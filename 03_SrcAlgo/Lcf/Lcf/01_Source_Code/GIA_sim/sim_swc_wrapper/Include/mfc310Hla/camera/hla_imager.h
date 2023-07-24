/*! \file **********************************************************************

  COMPANY:                Continental, BC DAS, A.D.C. GmbH

  PROJECT:                MFC3xx

  CPU:                    freescale Golddust

  COMPONENT:              HLA

  MODULNAME:              hla_imager.h

  DESCRIPTION:            Functions for imager characteristic.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          20.09.2010

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_imager.h  $
  CHANGE:                 Revision 1.1 2021/12/13 17:26:52CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/camera/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:38:30CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/camera/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:25CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/camera/project.pj
  CHANGE:                 Revision 1.26 2014/03/25 18:35:12CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_imager.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_imager.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/camera/project.pj.
  CHANGE:                 Revision 1.25 2014/03/19 16:31:20CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGE:                 Fixed hlar input adapter for old recordings (headlamp type)
  CHANGE:                 Clean-up of no longer needed files in simulation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 19, 2014 4:31:21 PM CET]
  CHANGE:                 Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGE:                 Revision 1.24 2014/03/04 16:52:03CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed QAC warnings
  CHANGE:                 Coding style
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 4:52:03 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.23 2013/12/13 16:44:52CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Service functions are now passed in one struct
  CHANGE:                 SDLfile definitions moved to separate file
  CHANGE:                 --- Added comments ---  uidv7867 [Dec 13, 2013 4:44:53 PM CET]
  CHANGE:                 Change Package : 207432:20 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.22 2013/11/21 17:53:21CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Merge from NEW_SEG branch
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 5:53:22 PM CET]
  CHANGE:                 Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.21.1.1 2013/11/21 13:38:10CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Improved Icon normalize
  CHANGE:                 Bug fixes in segmentation
  CHANGE:                 Removed no longer compiler switches
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 1:38:10 PM CET]
  CHANGE:                 Change Package : 207432:1 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.21 2012/10/19 14:20:53CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - allocation of array memory by array macro in order to realize a dedicated array boundary check mode
  CHANGE:                 --- Added comments ---  uidt9253 [Oct 19, 2012 2:21:01 PM CEST]
  CHANGE:                 Change Package : 118527:1 http://mks-psad:7002/im/viewissue?selection=118527
  CHANGE:                 Revision 1.20 2012/10/12 07:58:23CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - HLAImager_GetLogLux*(): small optimization, avoid a comparison
  CHANGE:                 --- Added comments ---  uidt9253 [Oct 12, 2012 7:58:24 AM CEST]
  CHANGE:                 Change Package : 118527:1 http://mks-psad:7002/im/viewissue?selection=118527
  CHANGE:                 Revision 1.19 2012/10/11 16:39:48CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - hla imager parameter preCalculation only when necessary (imager state changed)
  CHANGE:                 --- Added comments ---  uidt9253 [Oct 11, 2012 4:39:48 PM CEST]
  CHANGE:                 Change Package : 118527:1 http://mks-psad:7002/im/viewissue?selection=118527
  CHANGE:                 Revision 1.18 2012/10/11 13:03:33CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - align variable naming
  CHANGE:                 --- Added comments ---  uidt9253 [Oct 11, 2012 1:03:33 PM CEST]
  CHANGE:                 Change Package : 118527:1 http://mks-psad:7002/im/viewissue?selection=118527
  CHANGE:                 Revision 1.17 2012/10/10 19:05:16CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 -  icon image normalization optimized by linear picewise interpolation: avoid overflow in imager day characteristics and some smaller improvements
  CHANGE:                 --- Added comments ---  uidt9253 [Oct 10, 2012 7:05:17 PM CEST]
  CHANGE:                 Change Package : 118527:1 http://mks-psad:7002/im/viewissue?selection=118527
  CHANGE:                 Revision 1.16 2012/10/10 15:51:33CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 -  icon image normalization optimized by linear picewise interpolation: fix some copypaste and overflow problems
  CHANGE:                 --- Added comments ---  uidt9253 [Oct 10, 2012 3:51:33 PM CEST]
  CHANGE:                 Change Package : 118527:1 http://mks-psad:7002/im/viewissue?selection=118527
  CHANGE:                 Revision 1.15 2012/10/10 11:39:17CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 -  icon image normalization optimized by linear picewise interpolation: cleanup and optimization
  CHANGE:                 --- Added comments ---  uidt9253 [Oct 10, 2012 11:39:21 AM CEST]
  CHANGE:                 Change Package : 118527:1 http://mks-psad:7002/im/viewissue?selection=118527
  CHANGE:                 Revision 1.14 2012/10/10 08:39:06CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - first version of icon image normalization optimized by linear picewise interpolation precalculated in lookup table
  CHANGE:                 --- Added comments ---  uidt9253 [Oct 10, 2012 8:39:06 AM CEST]
  CHANGE:                 Change Package : 118527:1 http://mks-psad:7002/im/viewissue?selection=118527
  CHANGE:                 Revision 1.13 2012/07/23 12:57:59CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - code review comments from Humic
  CHANGE:                 --- Added comments ---  uidt9253 [Jul 23, 2012 12:57:59 PM CEST]
  CHANGE:                 Change Package : 94931:1 http://mks-psad:7002/im/viewissue?selection=94931
  CHANGE:                 Revision 1.12 2012/03/23 16:47:08CET Zechner, Stefan (uidt9253) 
  CHANGE:                 - comments after review with Reik
  CHANGE:                 --- Added comments ---  uidt9253 [Mar 23, 2012 4:47:08 PM CET]
  CHANGE:                 Change Package : 94867:1 http://mks-psad:7002/im/viewissue?selection=94867
  CHANGE:                 Revision 1.11 2012/02/22 12:07:00CET Brunn, Marcus (brunnm) 
  CHANGE:                 bugfixed integer lux calculation for ECU
  CHANGE:                 --- Added comments ---  brunnm [Feb 22, 2012 12:07:00 PM CET]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.10 2012/02/07 10:09:51CET Brunn, Marcus (brunnm) 
  CHANGE:                 HLAImager_GetIntLux_Red, Green, Blue:
  CHANGE:                 fixed saturation at 65535 lux
  CHANGE:                 --- Added comments ---  brunnm [Feb 7, 2012 10:09:51 AM CET]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.9 2012/02/06 15:57:08CET Brunn, Marcus (brunnm) 
  CHANGE:                 image characteristic now in uint16 lux
  CHANGE:                 Revision 1.8 2012/02/01 19:04:19CET Brunn, Marcus (brunnm) 
  CHANGE:                 fixed typecast
  CHANGE:                 --- Added comments ---  brunnm [Feb 1, 2012 7:04:20 PM CET]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.7 2012/02/01 09:57:25CET Brunn, Marcus (brunnm) 
  CHANGE:                 - RAM opt. -> lux values now in 16 Bit integer
  CHANGE:                 Revision 1.6 2012/01/19 17:30:01CET Zechner, Stefan (uidt9253) 
  CHANGE:                 - move functions HLAImager_GetLux_* from .c to .h in order to be inlined
  CHANGE:                 - remove old code which is not defined by HLA_USE_IC_RESPONSE_CURVE
  CHANGE:                 --- Added comments ---  uidt9253 [Jan 19, 2012 5:30:01 PM CET]
  CHANGE:                 Change Package : 90757:1 http://mks-psad:7002/im/viewissue?selection=90757
  CHANGE:                 Revision 1.5 2011/06/30 07:50:11CEST Brunn, Marcus (brunnm) 
  CHANGE:                 added functions to get imager saturation (3999) in grey values or lux
  CHANGE:                 --- Added comments ---  brunnm [Jun 30, 2011 7:50:12 AM CEST]
  CHANGE:                 Change Package : 49575:2 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGE:                 Revision 1.4 2011/02/01 14:47:12CET Brunn Marcus (brunnm) (brunnm) 
  CHANGE:                 use current imager response curve (calculated and updated by IC on every frame)
  CHANGE:                 --- Added comments ---  brunnm [Feb 1, 2011 2:47:12 PM CET]
  CHANGE:                 Change Package : 53526:1 http://mks-psad:7002/im/viewissue?selection=53526
  CHANGE:                 Revision 1.3 2010/12/02 13:33:35CET Marcus Brunn (brunnm) 
  CHANGE:                 imager:
  CHANGE:                 - added function to read T1 saturation region
  CHANGE:                 segmentation:
  CHANGE:                 - clustering: increased number of regions from 64 to 128
  CHANGE:                 - binarize row: implemented special feature for T1 saturation (dInt always 0)
  CHANGE:                 Revision 1.2 2010/11/02 15:59:18CET Marcus Brunn (brunnm) 
  CHANGE:                 removed 12Bit ngbs from maxima list to save RAM
  CHANGE:                 Revision 1.1 2010/10/14 14:28:31CEST Marcus Brunn (brunnm) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
  CHANGE:                 Revision 1.2 2010/09/28 07:42:49CEST Marcus Brunn (brunnm) 
  CHANGE:                 added conversion function from lux to red/green/blue/ greyvalue
  CHANGE:                 --- Added comments ---  brunnm [Sep 28, 2010 7:42:49 AM CEST]
  CHANGE:                 Change Package : 38437:1 http://mks-psad:7002/im/viewissue?selection=38437
  CHANGE:                 Revision 1.1 2010/09/24 06:58:52CEST Marcus Brunn (brunnm) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
  CHANGE:                 
**************************************************************************** */

/* avoid cyclic binding ---------------------------------------------------*/
#ifndef HLA_IMAGER_INCLUDED
#define HLA_IMAGER_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hla_base.h"
#include "hla_type.h"
#include "hlar_ext.h"
#include "hla_cfg.h"


/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/
#define HLA_IMAGER_LOGLUX_KNEE1_TABLE_SIZE              16
#define HLA_IMAGER_LOGLUX_KNEE2_TABLE_SIZE              8
#define HLA_IMAGER_LOGLUX_KNEE3_TABLE_SIZE              9
#define HLA_IMAGER_LOGLUX_KNEE1_TABLE_BINSIZE           128
#define HLA_IMAGER_LOGLUX_KNEE2_TABLE_BINSIZE           128
#define HLA_IMAGER_LOGLUX_KNEE3_TABLE_BINSIZE           128
#define HLA_IMAGER_LOGLUX_KNEE1_TABLE_BINSIZE_LOG2      7
#define HLA_IMAGER_LOGLUX_KNEE2_TABLE_BINSIZE_LOG2      7
#define HLA_IMAGER_LOGLUX_KNEE3_TABLE_BINSIZE_LOG2      7

#define HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2           8

#define HLA_IMAGER_ROUNDING_FACTOR          32768u  /* rounding -> 65536u/2u */
#define HLA_IMAGER_UINT16_BITSIZE             16


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/
typedef struct
{
  /* 20Bit to 12Bit compression parameter */
  uint32  Pin_1;      /* internal 20Bit knee point 1  */ 
  uint32  Pin_2;      /* internal 20Bit knee point 2  */
  uint32  Pin_max;    /* maximal internal 20Bit value */
  uint32  Pout_1;     /* external 12Bit knee point 1  */
  uint32  Pout_2;     /* external 12Bit knee point 1  */
  uint32  Pout_max;   /* maximal external 12Bit value */
  uint32  Factor1;    /* = 4* T1/T2 */
  uint32  Factor2;    /* = 4* T1/T2 * T2/T3 */
  float32 fFactor1;   /* = 4* T1/T2 */
  float32 fFactor2;   /* = 4* T1/T2 * T2/T3 */
  float32 fInvFactor1;/* = 1/ fFactor1 */
  float32 fInvFactor2;/* = 1/ fFactor2 */
}HLAImagerParCompression_t;

typedef struct 
{
  uint16 offset;
  uint16 scale;
} HLAImagerLogLuxLookupTable;


typedef struct
{
  /* imager response curve, calculated by IC */
  HLA_t_ImagerResponseCurve ResponseCurve;

  /* definition of the three sections */
  /* _1: first section,  12 bit greyvalue < 1. kneepoint                     */
  /* _2: second section, 12 bit greyvalue between first and second kneepoint */
  /* _3: third section,  12 bit greyvalue > 2. kneepoint                     */

  float32   Lux2R_1;      /* mean (lux/ red) value   */
  float32   Lux2R_2;      /* mean (lux/ red) value   */
  float32   Lux2R_3;      /* mean (lux/ red) value   */

  float32   Lux2G_1;      /* mean (lux/ green) value */
  float32   Lux2G_2;      /* mean (lux/ green) value */
  float32   Lux2G_3;      /* mean (lux/ green) value */

  float32   Lux2B_1;      /* mean (lux/ blue) value  */
  float32   Lux2B_2;      /* mean (lux/ blue) value  */
  float32   Lux2B_3;      /* mean (lux/ blue) value  */

  float32   R2Lux_1;      /* mean (red/ lux) value   */
  float32   R2Lux_2;      /* mean (red/ lux) value   */
  float32   R2Lux_3;      /* mean (red/ lux) value   */

  float32   G2Lux_1;      /* mean (green/ lux) value */
  float32   G2Lux_2;      /* mean (green/ lux) value */
  float32   G2Lux_3;      /* mean (green/ lux) value */

  float32   B2Lux_1;      /* mean (blue/ lux) value  */
  float32   B2Lux_2;      /* mean (blue/ lux) value  */
  float32   B2Lux_3;      /* mean (blue/ lux) value  */

  float32   R2G;          /* mean (red/green) value  */
  float32   R2B;          /* mean (red/blue)  value  */
  float32   G2R;          /* mean (green/red) value  */

  /* 20Bit to 12Bit compression parameter */
  HLAImagerParCompression_t Comp;

  /* T1 saturation (LEDs and high intensity lights/ reflectors which saturates during T1  */
  /*    and which are during T2,3 on a other pixel (high dx or dy movement in the image)) */
  /*  T1Sat_L <= Intensity <= T1Sat_H */
  uint16  T1Sat_L;                /* [12 Bit raw value] for r,g,b */
  uint16  T1Sat_H;                /* [12 Bit raw value] for r,g,b */
  float32 T1Sat_L_RedLux;         /* [lux] for red   */
  float32 T1Sat_H_RedLux;         /* [lux] for red   */
  float32 T1Sat_L_GreenLux;       /* [lux] for green */
  float32 T1Sat_H_GreenLux;       /* [lux] for green */
  float32 T1Sat_L_BlueLux;        /* [lux] for blue  */
  float32 T1Sat_H_BlueLux;        /* [lux] for blue  */
  /* integer T1 saturation */
  uint16 ui16_T1Sat_L_RedLux;     /* [lux] for red   */
  uint16 ui16_T1Sat_H_RedLux;     /* [lux] for red   */
  uint16 ui16_T1Sat_L_GreenLux;   /* [lux] for green */
  uint16 ui16_T1Sat_H_GreenLux;   /* [lux] for green */
  uint16 ui16_T1Sat_L_BlueLux;    /* [lux] for blue  */
  uint16 ui16_T1Sat_H_BlueLux;    /* [lux] for blue  */

  /* imager saturation, absolute maximum */
  uint16  Sat;            /* [12 Bit raw value] for r,g,b */
  float32 Sat_RedLux;     /* [lux] for red   */
  float32 Sat_GreenLux;   /* [lux] for green */
  float32 Sat_BlueLux;    /* [lux] for blue  */
  
  /* uint16 saturation (integer lux values) */
  uint16 ui16_Sat_Red;        /* [12 Bit raw value] for red   */
  uint16 ui16_Sat_Green;      /* [12 Bit raw value] for green */
  uint16 ui16_Sat_Blue;       /* [12 Bit raw value] for blue  */
  uint16 ui16_Sat_RedLux;     /* [lux] for red   */
  uint16 ui16_Sat_GreenLux;   /* [lux] for green */
  uint16 ui16_Sat_BlueLux;    /* [lux] for blue  */

  uint32 ui32LuxValueR;
  uint32 ui32LuxValueG;
  uint32 ui32LuxValueB;

  uint32 ui32Lux2R1;
  uint32 ui32Lux2G1;
  uint32 ui32Lux2B1;
  uint32 ui32Lux2R2;
  uint32 ui32Lux2G2;
  uint32 ui32Lux2B2;
  uint32 ui32Lux2R3;
  uint32 ui32Lux2G3;
  uint32 ui32Lux2B3;

  uint16 ui16Kneepoint1_Greyvalue;
  uint16 ui16Kneepoint2_Greyvalue;
  uint16 ui16Saturation_Greyvalue;
  uint16 ui16Blacklevel_R_Greyvalue;
  uint16 ui16Blacklevel_G_Greyvalue;
  uint16 ui16Blacklevel_B_Greyvalue;

  uint32 ui32_Kneepoint1_R_Lux;
  uint32 ui32_Kneepoint1_G_Lux;
  uint32 ui32_Kneepoint1_B_Lux;
  uint32 ui32_Kneepoint2_R_Lux;
  uint32 ui32_Kneepoint2_G_Lux;
  uint32 ui32_Kneepoint2_B_Lux;

  ARRAY(HLAImagerLogLuxLookupTable, HLA_IMAGER_LOGLUX_KNEE1_TABLE_SIZE, logLuxLookupTableRedKnee1);
  ARRAY(HLAImagerLogLuxLookupTable, HLA_IMAGER_LOGLUX_KNEE2_TABLE_SIZE, logLuxLookupTableRedKnee2);
  ARRAY(HLAImagerLogLuxLookupTable, HLA_IMAGER_LOGLUX_KNEE3_TABLE_SIZE, logLuxLookupTableRedKnee3);

  ARRAY(HLAImagerLogLuxLookupTable, HLA_IMAGER_LOGLUX_KNEE1_TABLE_SIZE, logLuxLookupTableGreenKnee1);
  ARRAY(HLAImagerLogLuxLookupTable, HLA_IMAGER_LOGLUX_KNEE2_TABLE_SIZE, logLuxLookupTableGreenKnee2);
  ARRAY(HLAImagerLogLuxLookupTable, HLA_IMAGER_LOGLUX_KNEE3_TABLE_SIZE, logLuxLookupTableGreenKnee3);

  ARRAY(HLAImagerLogLuxLookupTable, HLA_IMAGER_LOGLUX_KNEE1_TABLE_SIZE, logLuxLookupTableBlueKnee1);
  ARRAY(HLAImagerLogLuxLookupTable, HLA_IMAGER_LOGLUX_KNEE2_TABLE_SIZE, logLuxLookupTableBlueKnee2);
  ARRAY(HLAImagerLogLuxLookupTable, HLA_IMAGER_LOGLUX_KNEE3_TABLE_SIZE, logLuxLookupTableBlueKnee3);

} HLAImagerParameter_t;


/*****************************************************************************
  Variables 
*****************************************************************************/
extern HLAImagerParameter_t hlaImagerPar;


/*****************************************************************************
  FUNCTIONS
*****************************************************************************/
void HLAImager_InitPar(const HLA_t_ImagerCharacteristic *pImgChar_Cur);
void HLAImager_InitPar_Exec(void);


uint32  HLAImager_GetLinearGreyvalue(uint16 pix_in);
float32 HLAImager_GetfLinearGreyvalue(float32 pix_in);
uint16  HLAImager_GetNotLinearGreyvalue(uint32 pix_in);
float32 HLAImager_GetfNotLinearGreyvalue(float32 pix_in);
float32 HLAImager_GetRed_Lux(float32 Int);
float32 HLAImager_GetGreen_Lux(float32 Int);
float32 HLAImager_GetBlue_Lux(float32 Int);

uint16  HLAImager_GetT1SatLow(void);
uint16  HLAImager_GetT1SatHigh(void);
float32 HLAImager_GetT1SatLow_RedLux(void);
float32 HLAImager_GetT1SatHigh_RedLux(void);
float32 HLAImager_GetT1SatLow_GreenLux(void);
float32 HLAImager_GetT1SatHigh_GreenLux(void);
float32 HLAImager_GetT1SatLow_BlueLux(void);
float32 HLAImager_GetT1SatHigh_BlueLux(void);
/* integer T1 saturation */  
uint16 HLAImager_GetIntT1SatLow_RedLux(void);
uint16 HLAImager_GetIntT1SatHigh_RedLux(void);
uint16 HLAImager_GetIntT1SatLow_GreenLux(void);
uint16 HLAImager_GetIntT1SatHigh_GreenLux(void);
uint16 HLAImager_GetIntT1SatLow_BlueLux(void);
uint16 HLAImager_GetIntT1SatHigh_BlueLux(void);

uint16  HLAImager_GetSaturation(void);
float32 HLAImager_GetSaturation_RedLux(void);
float32 HLAImager_GetSaturation_GreenLux(void);
float32 HLAImager_GetSaturation_BlueLux(void);
/* integer saturation */
uint16  HLAImager_GetIntSaturation_RedLux(void);
uint16  HLAImager_GetIntSaturation_GreenLux(void);
uint16  HLAImager_GetIntSaturation_BlueLux(void);


float32 HLAImager_GetR2G(void);
float32 HLAImager_GetR2B(void);
float32 HLAImager_GetG2R(void);

void HLAImager_Measfreeze(AS_t_MeasHdlr pfMeasFreeze);

/* ****************************************************************************
  Functionname:     HLAImager_GetLux_Red                         */ /*!
  Description:      Get lux intensity of not linear 12 Bit red value
                    This function uses the imager response curve from ic.

  @param[in]        12Bit not linear red value 
  @param[in,out]    
  @param[out]       

  @return           intensity in lux
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static INLINE float32 HLAImager_GetLux_Red(uint16 pix_in)
{
  float32 pix_out;

  if(pix_in < hlaImagerPar.ResponseCurve.ui16_Kneepoint1_Greyvalue)
  {
    pix_out = (pix_in - hlaImagerPar.ResponseCurve.ui16_Blacklevel_R_Greyvalue) * hlaImagerPar.Lux2R_1;
  }
  else if(pix_in < hlaImagerPar.ResponseCurve.ui16_Kneepoint2_Greyvalue)
  {
    pix_out = hlaImagerPar.ResponseCurve.f32_Kneepoint1_R_Lux +  ((pix_in - hlaImagerPar.ResponseCurve.ui16_Kneepoint1_Greyvalue) * hlaImagerPar.Lux2R_2);
  }
  else
  {
    pix_out = hlaImagerPar.ResponseCurve.f32_Kneepoint2_R_Lux +  ((pix_in - hlaImagerPar.ResponseCurve.ui16_Kneepoint2_Greyvalue) * hlaImagerPar.Lux2R_3);
  }

  return(pix_out);
}
static INLINE uint16 HLAImager_GetIntLux_Red(uint16 pix_in)
{
  uint16 ui16_pix_out;

  if(pix_in < hlaImagerPar.ui16Kneepoint1_Greyvalue)
  {
    if(pix_in < hlaImagerPar.ui16Blacklevel_R_Greyvalue)
    {
      ui16_pix_out = 0;
    }
    else
    {
      ui16_pix_out = (uint16)((((pix_in - hlaImagerPar.ui16Blacklevel_R_Greyvalue) * hlaImagerPar.ui32Lux2R1) + HLA_IMAGER_ROUNDING_FACTOR) >> HLA_IMAGER_UINT16_BITSIZE);
    }
  }
  else if(pix_in < hlaImagerPar.ui16Kneepoint2_Greyvalue)
  {
    ui16_pix_out = (uint16)((((pix_in - hlaImagerPar.ui16Kneepoint1_Greyvalue) * hlaImagerPar.ui32Lux2R2) + hlaImagerPar.ui32_Kneepoint1_R_Lux)>>HLA_IMAGER_UINT16_BITSIZE);
  }
  else
  {
    if(pix_in > hlaImagerPar.ui16_Sat_Red)
    {
      ui16_pix_out = hlaImagerPar.ui16_Sat_RedLux;
    }
    else
    {
      ui16_pix_out = (uint16)((((pix_in - hlaImagerPar.ui16Kneepoint2_Greyvalue) * hlaImagerPar.ui32Lux2R3) + hlaImagerPar.ui32_Kneepoint2_R_Lux)>>HLA_IMAGER_UINT16_BITSIZE);
    }
  }
  return(ui16_pix_out);
}

/* ****************************************************************************
  Functionname:     HLAImager_GetLux_Green                         */ /*!
  Description:      Get lux intensity of not linear 12 Bit green value
                    This function uses the imager response curve from ic.

  @param[in]        12Bit not linear green value 
  @param[in,out]    
  @param[out]       

  @return           intensity in lux
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static INLINE float32 HLAImager_GetLux_Green(uint16 pix_in)
{
  float32 pix_out;

  if(pix_in < hlaImagerPar.ResponseCurve.ui16_Kneepoint1_Greyvalue)
  {
    pix_out = (pix_in - hlaImagerPar.ResponseCurve.ui16_Blacklevel_G_Greyvalue) * hlaImagerPar.Lux2G_1;
  }
  else if(pix_in < hlaImagerPar.ResponseCurve.ui16_Kneepoint2_Greyvalue)
  {
    pix_out = hlaImagerPar.ResponseCurve.f32_Kneepoint1_G_Lux +  ((pix_in - hlaImagerPar.ResponseCurve.ui16_Kneepoint1_Greyvalue) * hlaImagerPar.Lux2G_2);
  }
  else
  {
    pix_out = hlaImagerPar.ResponseCurve.f32_Kneepoint2_G_Lux +  ((pix_in - hlaImagerPar.ResponseCurve.ui16_Kneepoint2_Greyvalue) * hlaImagerPar.Lux2G_3);
  }

  return(pix_out);
}
static INLINE uint16 HLAImager_GetIntLux_Green(uint16 pix_in)
{
  uint16  ui16_pix_out;

  if(pix_in < hlaImagerPar.ui16Kneepoint1_Greyvalue)
  {
    if(pix_in < hlaImagerPar.ui16Blacklevel_G_Greyvalue)
    {
      ui16_pix_out = 0;
    }
    else
    {
      ui16_pix_out = (uint16)((((pix_in - hlaImagerPar.ui16Blacklevel_G_Greyvalue) * hlaImagerPar.ui32Lux2G1) + HLA_IMAGER_ROUNDING_FACTOR) >> HLA_IMAGER_UINT16_BITSIZE);
    }
  }
  else if(pix_in < hlaImagerPar.ui16Kneepoint2_Greyvalue)
  {
    ui16_pix_out = (uint16)((((pix_in - hlaImagerPar.ui16Kneepoint1_Greyvalue) * hlaImagerPar.ui32Lux2G2) + hlaImagerPar.ui32_Kneepoint1_G_Lux)>>HLA_IMAGER_UINT16_BITSIZE);
  }
  else
  {
    if(pix_in > hlaImagerPar.ui16_Sat_Green)
    {
      ui16_pix_out = hlaImagerPar.ui16_Sat_GreenLux;
    }
    else
    {
      ui16_pix_out = (uint16)((((pix_in - hlaImagerPar.ui16Kneepoint2_Greyvalue) * hlaImagerPar.ui32Lux2G3) + hlaImagerPar.ui32_Kneepoint2_G_Lux)>>HLA_IMAGER_UINT16_BITSIZE);
    }
  }
  return(ui16_pix_out);
}

/* ****************************************************************************
  Functionname:     HLAImager_GetLux_Blue                         */ /*!
  Description:      Get lux intensity of not linear 12 Bit blue value
                    This function uses the imager response curve from ic.

  @param[in]        12Bit not linear blue value 
  @param[in,out]    
  @param[out]       

  @return           intensity in lux
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static INLINE float32 HLAImager_GetLux_Blue(uint16 pix_in)
{
  float32 pix_out;

  if(pix_in < hlaImagerPar.ResponseCurve.ui16_Kneepoint1_Greyvalue)
  {
    pix_out = (pix_in - hlaImagerPar.ResponseCurve.ui16_Blacklevel_B_Greyvalue) * hlaImagerPar.Lux2B_1;
  }
  else if(pix_in < hlaImagerPar.ResponseCurve.ui16_Kneepoint2_Greyvalue)
  {
    pix_out = hlaImagerPar.ResponseCurve.f32_Kneepoint1_B_Lux +  ((pix_in - hlaImagerPar.ResponseCurve.ui16_Kneepoint1_Greyvalue) * hlaImagerPar.Lux2B_2);
  }
  else
  {
    pix_out = hlaImagerPar.ResponseCurve.f32_Kneepoint2_B_Lux +  ((pix_in - hlaImagerPar.ResponseCurve.ui16_Kneepoint2_Greyvalue) * hlaImagerPar.Lux2B_3);
  }

  return(pix_out);
}

static INLINE uint16 HLAImager_GetIntLux_Blue(uint16 pix_in)
{
  uint16  ui16_pix_out;

  if(pix_in < hlaImagerPar.ui16Kneepoint1_Greyvalue)
  {
    if(pix_in < hlaImagerPar.ui16Blacklevel_B_Greyvalue)
    {
      ui16_pix_out = 0;
    }
    else
    {
      ui16_pix_out = (uint16)((((pix_in - hlaImagerPar.ui16Blacklevel_B_Greyvalue) * hlaImagerPar.ui32Lux2B1) + HLA_IMAGER_ROUNDING_FACTOR) >> HLA_IMAGER_UINT16_BITSIZE);
    }
  }
  else if(pix_in < hlaImagerPar.ui16Kneepoint2_Greyvalue)
  {
    ui16_pix_out = (uint16)((((pix_in - hlaImagerPar.ui16Kneepoint1_Greyvalue) * hlaImagerPar.ui32Lux2B2) + hlaImagerPar.ui32_Kneepoint1_B_Lux)>>HLA_IMAGER_UINT16_BITSIZE);
  }
  else
  {
    if(pix_in > hlaImagerPar.ui16_Sat_Blue)
    {
      ui16_pix_out = hlaImagerPar.ui16_Sat_BlueLux;
    }
    else
    {
      ui16_pix_out = (uint16)((((pix_in - hlaImagerPar.ui16Kneepoint2_Greyvalue) * hlaImagerPar.ui32Lux2B3) + hlaImagerPar.ui32_Kneepoint2_B_Lux)>>HLA_IMAGER_UINT16_BITSIZE);
    }  
  }
  return(ui16_pix_out);
}


/* **************************************************************************** 
  Functionname:     HLAImager_GetLogLux_*                                */ /*!  
  @description:     transform input pixel pixel by 8-bit logarithmic Lux 
                    characteristic. (Function for red, green and blue)

  @param[in]        12-Bit image gray value

  @return           8-bit transformation
  @pre              -
  @post             -
  @author           Stefan Zechner
**************************************************************************** */
static INLINE uint8 HLAImager_GetLogLux_Red(uint16 pix_in)
{
  uint8 result;

  if (pix_in < hlaImagerPar.ui16Kneepoint1_Greyvalue)
  {
    if (pix_in <= hlaImagerPar.ui16Blacklevel_R_Greyvalue)
    {
      result = 0;
    }
    else
    {
      const uint16 dPix = (pix_in - hlaImagerPar.ui16Blacklevel_R_Greyvalue);
      sint32 lookupBin = dPix >> HLA_IMAGER_LOGLUX_KNEE1_TABLE_BINSIZE_LOG2;
      const HLAImagerLogLuxLookupTable* pLUT = &hlaImagerPar.logLuxLookupTableRedKnee1[lookupBin];
      result = (uint8)((uint32)(pLUT->offset + (dPix * pLUT->scale)) >> HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2);
    }
  }
  else if (pix_in < hlaImagerPar.ui16Kneepoint2_Greyvalue)
  {
    const uint16 dPix = (pix_in - hlaImagerPar.ui16Kneepoint1_Greyvalue);
    sint32 lookupBin = dPix >> HLA_IMAGER_LOGLUX_KNEE2_TABLE_BINSIZE_LOG2;
    const HLAImagerLogLuxLookupTable* pLUT = &hlaImagerPar.logLuxLookupTableRedKnee2[lookupBin];
    result = (uint8)((uint32)(pLUT->offset + (dPix * pLUT->scale)) >> HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2);
  }
  else
  {
    const uint16 dPix = (pix_in - hlaImagerPar.ui16Kneepoint2_Greyvalue);
    sint32 lookupBin = dPix >> HLA_IMAGER_LOGLUX_KNEE3_TABLE_BINSIZE_LOG2;
    const HLAImagerLogLuxLookupTable* pLUT = &hlaImagerPar.logLuxLookupTableRedKnee3[lookupBin];
    const uint32 result32 = (uint32)(pLUT->offset + (dPix * pLUT->scale)) >> HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2;
    result = (uint8)CML_Min(UI8_T_MAX, result32);
  }

  return result;
}

static INLINE uint8 HLAImager_GetLogLux_Green(uint16 pix_in)
{
  uint8 result;

  if (pix_in < hlaImagerPar.ui16Kneepoint1_Greyvalue)
  {
    if (pix_in <= hlaImagerPar.ui16Blacklevel_G_Greyvalue)
    {
      result = 0;
    }
    else
    {
      const uint16 dPix = (pix_in - hlaImagerPar.ui16Blacklevel_G_Greyvalue);
      sint32 lookupBin = dPix >> HLA_IMAGER_LOGLUX_KNEE1_TABLE_BINSIZE_LOG2;
      const HLAImagerLogLuxLookupTable* pLUT = &hlaImagerPar.logLuxLookupTableGreenKnee1[lookupBin];
      result = (uint8)((uint32)(pLUT->offset + (dPix * pLUT->scale)) >> HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2);
    }
  }
  else if (pix_in < hlaImagerPar.ui16Kneepoint2_Greyvalue)
  {
    const uint16 dPix = (pix_in - hlaImagerPar.ui16Kneepoint1_Greyvalue);
    sint32 lookupBin = dPix >> HLA_IMAGER_LOGLUX_KNEE2_TABLE_BINSIZE_LOG2;
    const HLAImagerLogLuxLookupTable* pLUT = &hlaImagerPar.logLuxLookupTableGreenKnee2[lookupBin];
    result = (uint8)((uint32)(pLUT->offset + (dPix * pLUT->scale)) >> HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2);
  }
  else
  {
    const uint16 dPix = (pix_in - hlaImagerPar.ui16Kneepoint2_Greyvalue);
    sint32 lookupBin = dPix >> HLA_IMAGER_LOGLUX_KNEE3_TABLE_BINSIZE_LOG2;
    const HLAImagerLogLuxLookupTable* pLUT = &hlaImagerPar.logLuxLookupTableGreenKnee3[lookupBin];
    const uint32 result32 = (uint32)(pLUT->offset + (dPix * pLUT->scale)) >> HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2;
    result = (uint8)CML_Min(UI8_T_MAX, result32);
  }

  return result;
}

static INLINE uint8 HLAImager_GetLogLux_Blue(uint16 pix_in)
{
  uint8 result;

  if (pix_in < hlaImagerPar.ui16Kneepoint1_Greyvalue)
  {
    if (pix_in <= hlaImagerPar.ui16Blacklevel_B_Greyvalue)
    {
      result = 0;
    }
    else
    {
      const uint16 dPix = (pix_in - hlaImagerPar.ui16Blacklevel_B_Greyvalue);
      sint32 lookupBin = dPix >> HLA_IMAGER_LOGLUX_KNEE1_TABLE_BINSIZE_LOG2;
      const HLAImagerLogLuxLookupTable* pLUT = &hlaImagerPar.logLuxLookupTableBlueKnee1[lookupBin];
      result = (uint8)((uint32)(pLUT->offset + (dPix * pLUT->scale)) >> HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2);
    }
  }
  else if (pix_in < hlaImagerPar.ui16Kneepoint2_Greyvalue)
  {
    const uint16 dPix = (pix_in - hlaImagerPar.ui16Kneepoint1_Greyvalue);
    sint32 lookupBin = dPix >> HLA_IMAGER_LOGLUX_KNEE2_TABLE_BINSIZE_LOG2;
    const HLAImagerLogLuxLookupTable* pLUT = &hlaImagerPar.logLuxLookupTableBlueKnee2[lookupBin];
    result = (uint8)((uint32)(pLUT->offset + (dPix * pLUT->scale)) >> HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2);
  }
  else
  {
    const uint16 dPix = (pix_in - hlaImagerPar.ui16Kneepoint2_Greyvalue);
    sint32 lookupBin = dPix >> HLA_IMAGER_LOGLUX_KNEE3_TABLE_BINSIZE_LOG2;
    const HLAImagerLogLuxLookupTable* pLUT = &hlaImagerPar.logLuxLookupTableBlueKnee3[lookupBin];
    const uint32 result32 = (uint32)(pLUT->offset + (dPix * pLUT->scale)) >> HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2;
    result = (uint8)CML_Min(UI8_T_MAX, result32);
  }

  return result;
}

#endif
