/*! \file **********************************************************************

  COMPANY:                Continental, BC DAS, A.D.C. GmbH

  PROJECT:                MFC3xx

  CPU:                    freescale Golddust

  COMPONENT:              HLA

  MODULNAME:              hla_imager.c

  DESCRIPTION:            Functions for imager characteristic.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          20.09.2010

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_imager.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:26:52CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/camera/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:38:29CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/camera/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:25CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/camera/project.pj
  CHANGE:                 Revision 1.40 2014/03/25 19:11:52CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Separation of hla_segmentation.c
  CHANGE:                 Removed QAC warnings
  CHANGE:                 Replaces fABS by CML_f_abs
  CHANGE:                 Introduced CML_s_Round2Int
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 25, 2014 7:11:52 PM CET]
  CHANGE:                 Change Package : 207432:46 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.39 2014/03/25 18:35:12CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_imager.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_imager.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/camera/project.pj.
  CHANGE:                 Revision 1.38 2014/03/24 18:33:27CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed boost assert
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 24, 2014 6:33:27 PM CET]
  CHANGE:                 Change Package : 207432:44 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.37 2014/03/19 16:31:23CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGE:                 Fixed hlar input adapter for old recordings (headlamp type)
  CHANGE:                 Clean-up of no longer needed files in simulation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 19, 2014 4:31:24 PM CET]
  CHANGE:                 Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGE:                 Revision 1.36 2014/03/10 13:20:59CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed some new critical QAC warnings
  CHANGE:                 Moved suppressions from .hoc file to comment in source code
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 10, 2014 1:20:59 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.35 2014/01/21 09:12:53CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Added a few more checks for devision of zero
  CHANGE:                 Removed some PC_SIM code that is no longer needed
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 21, 2014 9:12:54 AM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.34 2014/01/05 22:54:22CET Glebov, Roman (uidg4759) 
  CHANGE:                 removed unnneeded conversion from float to uint32 because the original values were not float but uint16
  CHANGE:                 --- Added comments ---  uidg4759 [Jan 5, 2014 10:54:22 PM CET]
  CHANGE:                 Change Package : 193435:2 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGE:                 Revision 1.33 2013/12/13 16:44:57CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Service functions are now passed in one struct
  CHANGE:                 SDLfile definitions moved to separate file
  CHANGE:                 --- Added comments ---  uidv7867 [Dec 13, 2013 4:44:57 PM CET]
  CHANGE:                 Change Package : 207432:20 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.32 2013/11/21 17:53:32CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Merge from NEW_SEG branch
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 5:53:33 PM CET]
  CHANGE:                 Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.31.1.1 2013/11/21 13:38:11CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Improved Icon normalize
  CHANGE:                 Bug fixes in segmentation
  CHANGE:                 Removed no longer compiler switches
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 1:38:11 PM CET]
  CHANGE:                 Change Package : 207432:1 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.31 2013/08/29 12:39:44CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Disabled almost all internal measfreezes temporary due 15K budget
  CHANGE:                 --- Added comments ---  uidv7867 [Aug 29, 2013 12:39:45 PM CEST]
  CHANGE:                 Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.30 2012/10/19 15:00:57CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - remove the test assert
  CHANGE:                 --- Added comments ---  uidt9253 [Oct 19, 2012 3:01:03 PM CEST]
  CHANGE:                 Change Package : 118527:1 http://mks-psad:7002/im/viewissue?selection=118527
  CHANGE:                 Revision 1.29 2012/10/19 14:55:47CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - replace assert() by the boost::assert because it generates a better output to be run on HPC
  CHANGE:                 --- Added comments ---  uidt9253 [Oct 19, 2012 2:55:54 PM CEST]
  CHANGE:                 Change Package : 118527:1 http://mks-psad:7002/im/viewissue?selection=118527
  CHANGE:                 Revision 1.28 2012/10/11 16:39:41CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - hla imager parameter preCalculation only when necessary (imager state changed)
  CHANGE:                 --- Added comments ---  uidt9253 [Oct 11, 2012 4:39:45 PM CEST]
  CHANGE:                 Change Package : 118527:1 http://mks-psad:7002/im/viewissue?selection=118527
  CHANGE:                 Revision 1.27 2012/10/10 19:04:48CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 -  icon image normalization optimized by linear picewise interpolation: avoid overflow in imager day characteristics and some smaller improvements
  CHANGE:                 --- Added comments ---  uidt9253 [Oct 10, 2012 7:04:49 PM CEST]
  CHANGE:                 Change Package : 118527:1 http://mks-psad:7002/im/viewissue?selection=118527
  CHANGE:                 Revision 1.26 2012/10/10 15:51:32CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 -  icon image normalization optimized by linear picewise interpolation: fix some copypaste and overflow problems
  CHANGE:                 --- Added comments ---  uidt9253 [Oct 10, 2012 3:51:32 PM CEST]
  CHANGE:                 Change Package : 118527:1 http://mks-psad:7002/im/viewissue?selection=118527
  CHANGE:                 Revision 1.25 2012/10/10 11:39:16CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 -  icon image normalization optimized by linear picewise interpolation: cleanup and optimization
  CHANGE:                 --- Added comments ---  uidt9253 [Oct 10, 2012 11:39:16 AM CEST]
  CHANGE:                 Change Package : 118527:1 http://mks-psad:7002/im/viewissue?selection=118527
  CHANGE:                 Revision 1.24 2012/10/10 08:39:04CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - first version of icon image normalization optimized by linear picewise interpolation precalculated in lookup table
  CHANGE:                 --- Added comments ---  uidt9253 [Oct 10, 2012 8:39:05 AM CEST]
  CHANGE:                 Change Package : 118527:1 http://mks-psad:7002/im/viewissue?selection=118527
  CHANGE:                 Revision 1.23 2012/07/23 12:58:02CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - code review comments from Humic
  CHANGE:                 --- Added comments ---  uidt9253 [Jul 23, 2012 12:58:02 PM CEST]
  CHANGE:                 Change Package : 94931:1 http://mks-psad:7002/im/viewissue?selection=94931
  CHANGE:                 Revision 1.22 2012/07/17 15:24:28CEST Mueller, Reik (muellerr5) 
  CHANGE:                 - added code review tags
  CHANGE:                 --- Added comments ---  muellerr5 [Jul 17, 2012 3:24:28 PM CEST]
  CHANGE:                 Change Package : 94921:1 http://mks-psad:7002/im/viewissue?selection=94921
  CHANGE:                 Revision 1.21 2012/02/22 12:06:59CET Brunn, Marcus (brunnm) 
  CHANGE:                 bugfixed integer lux calculation for ECU
  CHANGE:                 --- Added comments ---  brunnm [Feb 22, 2012 12:07:00 PM CET]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.20 2012/02/07 10:45:49CET Brunn, Marcus (brunnm) 
  CHANGE:                 fixed misra errors
  CHANGE:                 Revision 1.19 2012/02/07 10:09:50CET Brunn, Marcus (brunnm) 
  CHANGE:                 HLAImager_GetIntLux_Red, Green, Blue:
  CHANGE:                 fixed saturation at 65535 lux
  CHANGE:                 --- Added comments ---  brunnm [Feb 7, 2012 10:09:51 AM CET]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.18 2012/02/06 15:57:07CET Brunn, Marcus (brunnm) 
  CHANGE:                 image characteristic now in uint16 lux
  CHANGE:                 Revision 1.17 2012/02/01 09:57:25CET Brunn, Marcus (brunnm) 
  CHANGE:                 - RAM opt. -> lux values now in 16 Bit integer
  CHANGE:                 --- Added comments ---  brunnm [Feb 1, 2012 9:57:25 AM CET]
  CHANGE:                 Change Package : 94876:1 http://mks-psad:7002/im/viewissue?selection=94876
  CHANGE:                 Revision 1.16 2012/01/19 17:30:00CET Zechner, Stefan (uidt9253) 
  CHANGE:                 - move functions HLAImager_GetLux_* from .c to .h in order to be inlined
  CHANGE:                 - remove old code which is not defined by HLA_USE_IC_RESPONSE_CURVE
  CHANGE:                 --- Added comments ---  uidt9253 [Jan 19, 2012 5:30:01 PM CET]
  CHANGE:                 Change Package : 90757:1 http://mks-psad:7002/im/viewissue?selection=90757
  CHANGE:                 Revision 1.15 2011/08/31 19:16:05CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - led lights: remove the swap icon functionality because it did not show great benefit. This enables the analysis of the raw grey value icon in combination with the segmented preProcessed icon
  CHANGE:                 - more thighter LED satuarion range
  CHANGE:                 --- Added comments ---  uidt9253 [Aug 31, 2011 7:16:05 PM CEST]
  CHANGE:                 Change Package : 76260:1 http://mks-psad:7002/im/viewissue?selection=76260
  CHANGE:                 Revision 1.14 2011/06/30 07:50:11CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGE:                 added functions to get imager saturation (3999) in grey values or lux
  CHANGE:                 --- Added comments ---  brunnm [Jun 30, 2011 7:50:11 AM CEST]
  CHANGE:                 Change Package : 49575:2 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGE:                 Revision 1.13 2011/06/10 14:10:42CEST Zechner Stefan (uidt9253) (uidt9253) 
  CHANGE:                 - pulsed light detection: 3 of 4 surrounding green pixel at saturation level are enough for LED indication
  CHANGE:                 --- Added comments ---  uidt9253 [Jun 10, 2011 2:10:43 PM CEST]
  CHANGE:                 Change Package : 63192:1 http://mks-psad:7002/im/viewissue?selection=63192
  CHANGE:                 Revision 1.12 2011/06/09 17:17:03CEST Zechner Stefan (uidt9253) (uidt9253) 
  CHANGE:                 - T1 saturation thresholds corrected due to observation of pulsed lights in latest imagers
  CHANGE:                 --- Added comments ---  uidt9253 [Jun 9, 2011 5:17:04 PM CEST]
  CHANGE:                 Change Package : 63192:1 http://mks-psad:7002/im/viewissue?selection=63192
  CHANGE:                 Revision 1.11 2011/05/10 08:11:29CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGE:                 removed MISRA Errors
  CHANGE:                 --- Added comments ---  brunnm [May 10, 2011 8:11:29 AM CEST]
  CHANGE:                 Change Package : 53526:2 http://mks-psad:7002/im/viewissue?selection=53526
  CHANGE:                 Revision 1.10 2011/04/14 10:17:07CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGE:                 runtime optimized segmentation
  CHANGE:                 --- Added comments ---  brunnm [Apr 14, 2011 10:17:08 AM CEST]
  CHANGE:                 Change Package : 53526:1 http://mks-psad:7002/im/viewissue?selection=53526
  CHANGE:                 Revision 1.9 2011/03/10 22:41:18CET Brunn Marcus (brunnm) (brunnm) 
  CHANGE:                 added some comments
  CHANGE:                 --- Added comments ---  brunnm [Mar 10, 2011 10:41:18 PM CET]
  CHANGE:                 Change Package : 49575:1 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGE:                 Revision 1.8 2011/02/17 13:51:15CET Reik Mueller (muellerr5) 
  CHANGE:                 - changed order of includes to avoid errors in PC-Lint checker
  CHANGE:                 --- Added comments ---  muellerr5 [Feb 17, 2011 1:51:15 PM CET]
  CHANGE:                 Change Package : 38439:2 http://mks-psad:7002/im/viewissue?selection=38439
  CHANGE:                 Revision 1.7 2011/02/09 07:31:00CET Marcus Brunn (brunnm) 
  CHANGE:                 - implemented subsampled image (5x5 in lux)
  CHANGE:                 - adapted segmentation behaviour in bright scenes (city, dusk and dawn)
  CHANGE:                 --- Added comments ---  brunnm [Feb 9, 2011 7:31:00 AM CET]
  CHANGE:                 Change Package : 53526:1 http://mks-psad:7002/im/viewissue?selection=53526
  CHANGE:                 Revision 1.6 2011/02/03 12:30:32CET Marcus Brunn (brunnm) 
  CHANGE:                 renamed ResponseCurve to s_ResponseCurve
  CHANGE:                 --- Added comments ---  brunnm [Feb 3, 2011 12:30:32 PM CET]
  CHANGE:                 Change Package : 53526:1 http://mks-psad:7002/im/viewissue?selection=53526
  CHANGE:                 Revision 1.5 2011/02/01 14:47:11CET Marcus Brunn (brunnm) 
  CHANGE:                 use current imager response curve (calculated and updated by IC on every frame)
  CHANGE:                 Revision 1.4 2011/01/27 07:38:21CET Marcus Brunn (brunnm) 
  CHANGE:                 bugfix: adapted T1 saturation thresholds for pulsed light detection to reduce false turn offs
  CHANGE:                 --- Added comments ---  brunnm [Jan 27, 2011 7:38:21 AM CET]
  CHANGE:                 Change Package : 53526:1 http://mks-psad:7002/im/viewissue?selection=53526
  CHANGE:                 Revision 1.3 2010/12/02 13:33:35CET Marcus Brunn (brunnm) 
  CHANGE:                 imager:
  CHANGE:                 - added function to read T1 saturation region
  CHANGE:                 segmentation:
  CHANGE:                 - clustering: increased number of regions from 64 to 128
  CHANGE:                 - binarize row: implemented special feature for T1 saturation (dInt always 0)
  CHANGE:                 --- Added comments ---  brunnm [Dec 2, 2010 1:33:35 PM CET]
  CHANGE:                 Change Package : 53526:1 http://mks-psad:7002/im/viewissue?selection=53526
  CHANGE:                 Revision 1.2 2010/11/02 15:59:17CET Marcus Brunn (brunnm) 
  CHANGE:                 removed 12Bit ngbs from maxima list to save RAM
  CHANGE:                 Revision 1.1 2010/10/14 14:28:29CEST Marcus Brunn (brunnm) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
  CHANGE:                 Revision 1.3 2010/10/01 10:38:19CEST Marcus Brunn (brunnm) 
  CHANGE:                 rework of hla segmentation
  CHANGE:                 --- Added comments ---  brunnm [Oct 1, 2010 10:38:19 AM CEST]
  CHANGE:                 Change Package : 38437:1 http://mks-psad:7002/im/viewissue?selection=38437
  CHANGE:                 Revision 1.2 2010/09/28 07:42:49CEST Marcus Brunn (brunnm) 
  CHANGE:                 added conversion function from lux to red/green/blue/ greyvalue
  CHANGE:                 Revision 1.1 2010/09/24 06:58:52CEST Marcus Brunn (brunnm) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
  CHANGE:                 
**************************************************************************** */
#ifdef PC_SIM
#include <assert.h>
#endif

/* J.Häfer: Redundant including of math.h is checked */
#include <math.h>
#include <string.h>
#include "hla_imager.h"

/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/
#define HLA_IMAGER_LOGLUX_LINLOG_TRANSITION_LUX         2.0f
#define HLA_IMAGER_LOGLUX_LINLOG_LIN_SLOPE              11.458994f
#define HLA_IMAGER_LOGLUX_LINLOG_LOG_OFFSET             7.0324492f
#define HLA_IMAGER_LOGLUX_LINLOG_LOG_SLOPE              15.885539f

/* the calculation of logLux characteristic parameters */
/*
static const float32 HLA_IMAGER_LOGLUX_LINLOG_TRANSITION_LUX = 2.0f;
static const float32 maxLux = 50000.0f;
static const float32 HLA_IMAGER_LOGLUX_LINLOG_LOG_SLOPE = 255.0f / (1/logf(2) - logf(HLA_IMAGER_LOGLUX_LINLOG_TRANSITION_LUX)/logf(2) + logf(maxLux)/logf(2));
static const float32 HLA_IMAGER_LOGLUX_LINLOG_LOG_OFFSET = HLA_IMAGER_LOGLUX_LINLOG_LOG_SLOPE/logf(2) - HLA_IMAGER_LOGLUX_LINLOG_LOG_SLOPE*logf(HLA_IMAGER_LOGLUX_LINLOG_TRANSITION_LUX)/logf(2);
static const float32 HLA_IMAGER_LOGLUX_LINLOG_LIN_SLOPE = HLA_IMAGER_LOGLUX_LINLOG_LOG_SLOPE / (HLA_IMAGER_LOGLUX_LINLOG_TRANSITION_LUX * logf(2));
*/


/*****************************************************************************
  VARIABLES
*****************************************************************************/
HLAImagerParameter_t          hlaImagerPar;

/******************************************************************************
* PROTOTYPES
******************************************************************************/
static void HLAImager_InitParCompression(HLAImagerParCompression_t *pDat, uint32 R1, uint32 R2);
static uint8 HLAImager_luxToLog8Bit(float32 lux);
static void HLAImager_FillLogLuxLookupTable(void);


/* ****************************************************************************
  Functionname:     HLAImager_GetLinearGreyvalue                         */ /*!
  Description:      Get linear grey value

  @param[in]        12Bit not linear grey value 
  @param[in,out]    
  @param[out]       

  @return           20Bit linear grey value
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
uint32 HLAImager_GetLinearGreyvalue(uint16 pix_in)
{
  uint32 pix_out;

  if(pix_in < hlaImagerPar.Comp.Pout_1)
  {
    pix_out = pix_in;
  }
  else if(pix_in < hlaImagerPar.Comp.Pout_2)
  {
    pix_out = (hlaImagerPar.Comp.Pin_1 + ((pix_in - hlaImagerPar.Comp.Pout_1) * hlaImagerPar.Comp.Factor1));
  }
  else
  {
    pix_out = (hlaImagerPar.Comp.Pin_2 + ((pix_in - hlaImagerPar.Comp.Pout_2) * hlaImagerPar.Comp.Factor2));
  }

  return(pix_out);
}

/* ****************************************************************************
  Functionname:     HLAImager_GetLinearGreyvalue                         */ /*!
  Description:      Get linear grey value

  @param[in]        12Bit not linear grey value 
  @param[in,out]    
  @param[out]       

  @return           20Bit linear grey value
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
float32 HLAImager_GetfLinearGreyvalue(float32 pix_in)
{
  float32 pix_out;  

  if(pix_in < hlaImagerPar.Comp.Pout_1)
  {
    pix_out = pix_in;
  }
  else if(pix_in < hlaImagerPar.Comp.Pout_2)
  {
    pix_out = (hlaImagerPar.Comp.Pin_1 + ((pix_in - hlaImagerPar.Comp.Pout_1) * hlaImagerPar.Comp.fFactor1));
  }
  else
  {
    pix_out = (hlaImagerPar.Comp.Pin_2 + ((pix_in - hlaImagerPar.Comp.Pout_2) * hlaImagerPar.Comp.fFactor2));
  }

  return(pix_out);
}


/* ****************************************************************************
  Functionname:     HLAImager_GetNotLinearGreyvalue                         */ /*!
  Description:      Get not linear grey value (12Bit)

  @param[in]        20Bit linear grey value 
  @param[in,out]    
  @param[out]       

  @return           12Bit not linear grey value
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
uint16 HLAImager_GetNotLinearGreyvalue(uint32 pix_in)
{
  uint16 pix_out;

  if(pix_in < hlaImagerPar.Comp.Pin_1)
  {
    pix_out = (uint16)pix_in;
  }
  else if(pix_in < hlaImagerPar.Comp.Pin_2)
  {
    pix_out = (uint16)CML_u_Round2Uint(hlaImagerPar.Comp.Pout_1 + ((pix_in - hlaImagerPar.Comp.Pin_1) * hlaImagerPar.Comp.fInvFactor1));
  }
  else
  {
    pix_out = (uint16)CML_u_Round2Uint(hlaImagerPar.Comp.Pout_2 + ((pix_in - hlaImagerPar.Comp.Pin_2) * hlaImagerPar.Comp.fInvFactor2));
  }

  return(pix_out);
}


/* ****************************************************************************
  Functionname:     HLAImager_GetfNotLinearGreyvalue                     */ /*!
  Description:      Get not linear grey value (12Bit)

  @param[in]        20Bit linear grey value 
  @param[in,out]    
  @param[out]       

  @return           12Bit not linear grey value
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
float32 HLAImager_GetfNotLinearGreyvalue(float32 pix_in)
{
  float32 pix_out;

  if(pix_in < hlaImagerPar.Comp.Pin_1)
  {
    pix_out = pix_in;
  }
  else if(pix_in < hlaImagerPar.Comp.Pin_2)
  {
    pix_out = (hlaImagerPar.Comp.Pout_1 + ((pix_in - hlaImagerPar.Comp.Pin_1) * hlaImagerPar.Comp.fInvFactor1));
  }
  else
  {
    pix_out = (hlaImagerPar.Comp.Pout_2 + ((pix_in - hlaImagerPar.Comp.Pin_2) * hlaImagerPar.Comp.fInvFactor2));
  }
  
  return(pix_out);
}

/* ****************************************************************************
  Functionname:     HLAImager_GetRed_Lux                         */ /*!
  Description:      Get 12 bit not linear red value of lux value
                    This function uses the response curve from IC.

  @param[in]        intensity in lux 
  @param[in,out]    
  @param[out]       

  @return           12Bit not linear red value 
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
float32 HLAImager_GetRed_Lux(float32 Int)
{
  float32 pix_out;

  if(Int < hlaImagerPar.ResponseCurve.f32_Kneepoint1_R_Lux)
  {
    pix_out = hlaImagerPar.ResponseCurve.ui16_Blacklevel_R_Greyvalue + (Int * hlaImagerPar.R2Lux_1);
  }
  else if(Int < hlaImagerPar.ResponseCurve.f32_Kneepoint2_R_Lux)
  {
    pix_out = hlaImagerPar.ResponseCurve.ui16_Kneepoint1_Greyvalue + ((Int - hlaImagerPar.ResponseCurve.f32_Kneepoint1_R_Lux) * hlaImagerPar.R2Lux_2);
  }
  else
  {
    pix_out = hlaImagerPar.ResponseCurve.ui16_Kneepoint2_Greyvalue + ((Int - hlaImagerPar.ResponseCurve.f32_Kneepoint2_R_Lux) * hlaImagerPar.R2Lux_3);
  }

  return(pix_out);
}

/* ****************************************************************************
  Functionname:     HLAImager_GetGreen_Lux                         */ /*!
  Description:      Get 12 bit not linear green value of lux value
                    This function uses the response curve from IC.

  @param[in]        intensity in lux 
  @param[in,out]    
  @param[out]       

  @return           12Bit not linear green value 
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
float32 HLAImager_GetGreen_Lux(float32 Int)
{
  float32 pix_out;

  if(Int < hlaImagerPar.ResponseCurve.f32_Kneepoint1_G_Lux)
  {
    pix_out = hlaImagerPar.ResponseCurve.ui16_Blacklevel_G_Greyvalue + (Int * hlaImagerPar.G2Lux_1);
  }
  else if(Int < hlaImagerPar.ResponseCurve.f32_Kneepoint2_G_Lux)
  {
    pix_out = hlaImagerPar.ResponseCurve.ui16_Kneepoint1_Greyvalue + ((Int - hlaImagerPar.ResponseCurve.f32_Kneepoint1_G_Lux) * hlaImagerPar.G2Lux_2);
  }
  else
  {
    pix_out = hlaImagerPar.ResponseCurve.ui16_Kneepoint2_Greyvalue + ((Int - hlaImagerPar.ResponseCurve.f32_Kneepoint2_G_Lux) * hlaImagerPar.G2Lux_3);
  }
  return(pix_out);
}

/* ****************************************************************************
  Functionname:     HLAImager_GetBlue_Lux                         */ /*!
  Description:      Get 12 bit not linear blue value of lux value
                    This function uses the response curve from IC.

  @param[in]        intensity in lux 
  @param[in,out]    
  @param[out]       

  @return           12Bit not linear blue value 
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
float32 HLAImager_GetBlue_Lux(float32 Int)
{
  float32 pix_out;

  if(Int < hlaImagerPar.ResponseCurve.f32_Kneepoint1_B_Lux)
  {
    pix_out = hlaImagerPar.ResponseCurve.ui16_Blacklevel_B_Greyvalue + (Int * hlaImagerPar.B2Lux_1);
  }
  else if(Int < hlaImagerPar.ResponseCurve.f32_Kneepoint2_B_Lux)
  {
    pix_out = hlaImagerPar.ResponseCurve.ui16_Kneepoint1_Greyvalue + ((Int - hlaImagerPar.ResponseCurve.f32_Kneepoint1_B_Lux) * hlaImagerPar.B2Lux_2);
  }
  else
  {
    pix_out = hlaImagerPar.ResponseCurve.ui16_Kneepoint2_Greyvalue + ((Int - hlaImagerPar.ResponseCurve.f32_Kneepoint2_B_Lux) * hlaImagerPar.B2Lux_3);
  }
  return(pix_out);
}

/* ****************************************************************************
  Functionname:     HLAImager_InitParCompression                         */ /*!
  Description:      Inits imager compression parameter

  @param[in]        HLAImagerParCompression_t  *pDat  
  @param[in,out]    requested R1 = T1/T2
                    requested R2 = T2/T3
  @param[out]       

  @return           void
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLAImager_InitParCompression(HLAImagerParCompression_t *pDat, uint32 R1, uint32 R2)
{
  switch(R1)
  {
    case 4:
      pDat->Pin_1 = 2048;      /* = 2^11;  1. kneepoint in 20Bit */
      pDat->Pin_2 = 16384;     /* = 2^14;  2. kneepoint in 20Bit */
      pDat->Pin_max = 65536;   /* = 2^16;  maximal output in 20Bit */
      break;
    case 8:
      pDat->Pin_1 = 2048;      /* = 2^11;  1. kneepoint in 20Bit */
      pDat->Pin_2 = 32768;     /* = 2^15;  2. kneepoint in 20Bit */
      pDat->Pin_max = 131072;  /* = 2^17;  maximal output in 20Bit */
      break;
    case 16:
      pDat->Pin_1 = 2048;      /* = 2^11;  1. kneepoint in 20Bit */
      pDat->Pin_2 = 65536;     /* = 2^16;  2. kneepoint in 20Bit */
      pDat->Pin_max = 262144;  /* = 2^18;  maximal output in 20Bit */
      break;
    default:
      /* invalid -> Error */
      /* use night characteristic */
      R1            = 16;
      pDat->Pin_1   = 2048;      /* = 2^11;  1. kneepoint in 20Bit */
      pDat->Pin_2   = 65536;     /* = 2^16;  2. kneepoint in 20Bit */
      pDat->Pin_max = 262144;  /* = 2^18;  maximal output in 20Bit */
      break;
  }

  switch(R2)
  {
    case 4:
      /* ~CodeReview ~ID:9aae3e0d62c0eb648c1c46afb276cbd9 ~Reviewer:CW01\muellerr5 ~Date:17.07.2012 ~Priority:3 ~Comment:code commented out -> add documentation or remove */
      /* pDat->Pin_max *= 1; */   /* maximal output in 20Bit */
      break;
    case 8:
      pDat->Pin_max *= 2;  /* maximal output in 20Bit */
      break;
    case 16:
      pDat->Pin_max *= 4;  /* maximal output in 20Bit */
      break;
    default:
      /* invalid -> Error */
      /* use night characteristic */
      R2             = 16;
      pDat->Pin_max *= 4;  /* maximal output in 20Bit */
      break;
  }

  pDat->Pout_1      = pDat->Pin_1;  /* = Pin_1 */
  pDat->Pout_2      = ((pDat->Pin_2 - pDat->Pin_1)/(4*R1)) + pDat->Pout_1;      /* = (Pin_2 - Pin_1)/(4*R1) + Pout_1 */
  pDat->Pout_max    = ((pDat->Pin_max - pDat->Pin_2)/(4*R1*R2)) + pDat->Pout_2; /* = (Pin_max - Pin_2)/(4*R1*R2) + Pout_2 */;
  pDat->Factor1     = 4*R1;     /* = 4 * T1/T2 = 4*R1 */
  pDat->Factor2     = 4*R1*R2;  /* = 4 * T1/T2 * T2/T3 = 4*R1*R2 */
  pDat->fFactor1    = (float32)4*R1;     /* = 4 * T1/T2 = 4*R1 */
  pDat->fFactor2    = (float32)4*R1*R2;  /* = 4 * T1/T2 * T2/T3 = 4*R1*R2 */
  pDat->fInvFactor1 = 1/pDat->fFactor1;
  pDat->fInvFactor2 = 1/pDat->fFactor2;
}

/* ****************************************************************************
  Functionname:     HLAImagerInitPar                                     */ /*!
  Description:      Inits imager parameter
                    parameter set uses imager response curve from image control
                    (updated on every frame, uses current gain, integration time, R1, R2...)

  @param[in]        
  @param[in,out]    
  @param[out]       

  @return           void
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLAImager_InitPar(const HLA_t_ImagerCharacteristic *pImgChar_Cur)
{
  /* init compression parameter */
  HLAImager_InitParCompression(&hlaImagerPar.Comp, pImgChar_Cur->ui32_R1, pImgChar_Cur->ui32_R2);

  /* copy current imager response curve into internal RAM */
  (void)memcpy(&hlaImagerPar.ResponseCurve, &pImgChar_Cur->s_ResponseCurve, sizeof(HLA_t_ImagerResponseCurve));

  /* 1. section ( (12Bit grey value) < 1. kneepoint) */
  /* Division by 0 not possible as these values are checked beginning of HLAR_v_Exec() and HLAR_v_Init() */
  hlaImagerPar.R2Lux_1 = (hlaImagerPar.ResponseCurve.ui16_Kneepoint1_Greyvalue - hlaImagerPar.ResponseCurve.ui16_Blacklevel_R_Greyvalue)/(hlaImagerPar.ResponseCurve.f32_Kneepoint1_R_Lux);
  hlaImagerPar.G2Lux_1 = (hlaImagerPar.ResponseCurve.ui16_Kneepoint1_Greyvalue - hlaImagerPar.ResponseCurve.ui16_Blacklevel_G_Greyvalue)/(hlaImagerPar.ResponseCurve.f32_Kneepoint1_G_Lux);
  hlaImagerPar.B2Lux_1 = (hlaImagerPar.ResponseCurve.ui16_Kneepoint1_Greyvalue - hlaImagerPar.ResponseCurve.ui16_Blacklevel_B_Greyvalue)/(hlaImagerPar.ResponseCurve.f32_Kneepoint1_B_Lux);
  if(hlaImagerPar.R2Lux_1 > 0.0f)
  {
    hlaImagerPar.Lux2R_1 = 1/ hlaImagerPar.R2Lux_1;
  }
  else
  {
    hlaImagerPar.Lux2R_1 = 0.0f;
  }
  if(hlaImagerPar.G2Lux_1 > 0.0f)
  {
    hlaImagerPar.Lux2G_1 = 1/ hlaImagerPar.G2Lux_1;
  }
  else
  {
    hlaImagerPar.Lux2G_1 = 0.0f;
  }
  if(hlaImagerPar.B2Lux_1 > 0.0f)
  {
    hlaImagerPar.Lux2B_1 = 1/ hlaImagerPar.B2Lux_1;
  }
  else
  {
    hlaImagerPar.Lux2B_1 = 0.0f;
  }
  
  /* 2. section (1. kneepoint < (12Bit grey value) < 2. kneepoint) */
  /* Division by 0 not possible as these values are checked beginning of HLAR_v_Exec() and HLAR_v_Init() */
  hlaImagerPar.R2Lux_2 = (hlaImagerPar.ResponseCurve.ui16_Kneepoint2_Greyvalue - hlaImagerPar.ResponseCurve.ui16_Kneepoint1_Greyvalue)/(hlaImagerPar.ResponseCurve.f32_Kneepoint2_R_Lux - hlaImagerPar.ResponseCurve.f32_Kneepoint1_R_Lux);
  hlaImagerPar.G2Lux_2 = (hlaImagerPar.ResponseCurve.ui16_Kneepoint2_Greyvalue - hlaImagerPar.ResponseCurve.ui16_Kneepoint1_Greyvalue)/(hlaImagerPar.ResponseCurve.f32_Kneepoint2_G_Lux - hlaImagerPar.ResponseCurve.f32_Kneepoint1_G_Lux);
  hlaImagerPar.B2Lux_2 = (hlaImagerPar.ResponseCurve.ui16_Kneepoint2_Greyvalue - hlaImagerPar.ResponseCurve.ui16_Kneepoint1_Greyvalue)/(hlaImagerPar.ResponseCurve.f32_Kneepoint2_B_Lux - hlaImagerPar.ResponseCurve.f32_Kneepoint1_B_Lux);
  if(hlaImagerPar.R2Lux_2 > 0.0f)
  {
    hlaImagerPar.Lux2R_2 = 1/ hlaImagerPar.R2Lux_2;
  }
  else
  {
    hlaImagerPar.Lux2R_2 = 0.0f;
  }
  if(hlaImagerPar.G2Lux_2 > 0.0f)
  {
    hlaImagerPar.Lux2G_2 = 1/ hlaImagerPar.G2Lux_2;
  }
  else
  {
    hlaImagerPar.Lux2G_2 = 0.0f;
  }
  if(hlaImagerPar.B2Lux_2 > 0.0f)
  {
    hlaImagerPar.Lux2B_2 = 1/ hlaImagerPar.B2Lux_2;
  }
  else
  {
    hlaImagerPar.Lux2B_2 = 0.0f;
  }
  
  /* 3. section (2. kneepoint < (12Bit grey value) < saturation) */
  /* Division by 0 not possible as these values are checked beginning of HLAR_v_Exec() and HLAR_v_Init() */
  hlaImagerPar.R2Lux_3 = (hlaImagerPar.ResponseCurve.ui16_Saturation_Greyvalue - hlaImagerPar.ResponseCurve.ui16_Kneepoint2_Greyvalue)/(hlaImagerPar.ResponseCurve.f32_Saturation_R_Lux - hlaImagerPar.ResponseCurve.f32_Kneepoint2_R_Lux);
  hlaImagerPar.G2Lux_3 = (hlaImagerPar.ResponseCurve.ui16_Saturation_Greyvalue - hlaImagerPar.ResponseCurve.ui16_Kneepoint2_Greyvalue)/(hlaImagerPar.ResponseCurve.f32_Saturation_G_Lux - hlaImagerPar.ResponseCurve.f32_Kneepoint2_G_Lux);
  hlaImagerPar.B2Lux_3 = (hlaImagerPar.ResponseCurve.ui16_Saturation_Greyvalue - hlaImagerPar.ResponseCurve.ui16_Kneepoint2_Greyvalue)/(hlaImagerPar.ResponseCurve.f32_Saturation_B_Lux - hlaImagerPar.ResponseCurve.f32_Kneepoint2_B_Lux);
  if(hlaImagerPar.R2Lux_3 > 0.0f)
  {
    hlaImagerPar.Lux2R_3 = 1/ hlaImagerPar.R2Lux_3;
  }
  else
  {
    hlaImagerPar.Lux2R_3 = 0.0f;
  }
  if(hlaImagerPar.G2Lux_3 > 0.0f)
  {
    hlaImagerPar.Lux2G_3 = 1/ hlaImagerPar.G2Lux_3;
  }
  else
  {
    hlaImagerPar.Lux2G_3 = 0.0f;
  }
  if(hlaImagerPar.B2Lux_3 > 0.0f)
  {
    hlaImagerPar.Lux2B_3 = 1/ hlaImagerPar.B2Lux_3;
  }
  else
  {
    hlaImagerPar.Lux2B_3 = 0.0f;
  }

  
  /* calculate some color ratios */
  if(hlaImagerPar.G2Lux_1 > 0.0f)
  {
    hlaImagerPar.R2G = hlaImagerPar.R2Lux_1 / hlaImagerPar.G2Lux_1;
  }
  else
  {
    hlaImagerPar.R2G = 0.0f;
  }
  if(hlaImagerPar.B2Lux_1 > 0.0f)
  {
    hlaImagerPar.R2B = hlaImagerPar.R2Lux_1 / hlaImagerPar.B2Lux_1;
  }
  else
  {
    hlaImagerPar.R2B = 0.0f;
  }
  if(hlaImagerPar.R2Lux_1 > 0.0f)
  {
    hlaImagerPar.G2R = hlaImagerPar.G2Lux_1 / hlaImagerPar.R2Lux_1;
  }
  else
  {
    hlaImagerPar.G2R = 0.0f;
  }


  /* set T1 saturation thresholds */
  /* ~CodeReview ~ID:981e48bac8f0b1d4df8220bd17e5305e ~Reviewer:CW01\muellerr5 ~Date:17.07.2012 ~Priority:3 ~Comment:magic number ? (or add documentation) */
  hlaImagerPar.T1Sat_L          = 2064u;
  hlaImagerPar.T1Sat_H          = 2068u;
  hlaImagerPar.T1Sat_L_RedLux   = HLAImager_GetLux_Red(hlaImagerPar.T1Sat_L);
  hlaImagerPar.T1Sat_H_RedLux   = HLAImager_GetLux_Red(hlaImagerPar.T1Sat_H);
  hlaImagerPar.T1Sat_L_GreenLux = HLAImager_GetLux_Green(hlaImagerPar.T1Sat_L);
  hlaImagerPar.T1Sat_H_GreenLux = HLAImager_GetLux_Green(hlaImagerPar.T1Sat_H);
  hlaImagerPar.T1Sat_L_BlueLux  = HLAImager_GetLux_Blue(hlaImagerPar.T1Sat_L);
  hlaImagerPar.T1Sat_H_BlueLux  = HLAImager_GetLux_Blue(hlaImagerPar.T1Sat_H);
  /* integer T1 saturation */
  hlaImagerPar.ui16_T1Sat_L_RedLux   = (uint16)CML_Min(UI16_T_MAX, CML_u_Round2UintGen(hlaImagerPar.T1Sat_L_RedLux));
  hlaImagerPar.ui16_T1Sat_H_RedLux   = (uint16)CML_Min(UI16_T_MAX, CML_u_Round2UintGen(hlaImagerPar.T1Sat_H_RedLux));
  hlaImagerPar.ui16_T1Sat_L_GreenLux = (uint16)CML_Min(UI16_T_MAX, CML_u_Round2UintGen(hlaImagerPar.T1Sat_L_GreenLux));
  hlaImagerPar.ui16_T1Sat_H_GreenLux = (uint16)CML_Min(UI16_T_MAX, CML_u_Round2UintGen(hlaImagerPar.T1Sat_H_GreenLux));
  hlaImagerPar.ui16_T1Sat_L_BlueLux  = (uint16)CML_Min(UI16_T_MAX, CML_u_Round2UintGen(hlaImagerPar.T1Sat_L_BlueLux));
  hlaImagerPar.ui16_T1Sat_H_BlueLux  = (uint16)CML_Min(UI16_T_MAX, CML_u_Round2UintGen(hlaImagerPar.T1Sat_H_BlueLux));


  hlaImagerPar.ui32Lux2R1 = CML_u_Round2Uint(hlaImagerPar.Lux2R_1 * 65536.0f);
  hlaImagerPar.ui32Lux2G1 = CML_u_Round2Uint(hlaImagerPar.Lux2G_1 * 65536.0f);
  hlaImagerPar.ui32Lux2B1 = CML_u_Round2Uint(hlaImagerPar.Lux2B_1 * 65536.0f);
  hlaImagerPar.ui32Lux2R2 = CML_u_Round2Uint(hlaImagerPar.Lux2R_2 * 65536.0f);
  hlaImagerPar.ui32Lux2G2 = CML_u_Round2Uint(hlaImagerPar.Lux2G_2 * 65536.0f);
  hlaImagerPar.ui32Lux2B2 = CML_u_Round2Uint(hlaImagerPar.Lux2B_2 * 65536.0f); 
  hlaImagerPar.ui32Lux2R3 = CML_u_Round2Uint(hlaImagerPar.Lux2R_3 * 65536.0f);
  hlaImagerPar.ui32Lux2G3 = CML_u_Round2Uint(hlaImagerPar.Lux2G_3 * 65536.0f);
  hlaImagerPar.ui32Lux2B3 = CML_u_Round2Uint(hlaImagerPar.Lux2B_3 * 65536.0f);

  hlaImagerPar.ui16Kneepoint1_Greyvalue = hlaImagerPar.ResponseCurve.ui16_Kneepoint1_Greyvalue;
  hlaImagerPar.ui16Kneepoint2_Greyvalue = hlaImagerPar.ResponseCurve.ui16_Kneepoint2_Greyvalue;
  hlaImagerPar.ui16Saturation_Greyvalue = hlaImagerPar.ResponseCurve.ui16_Saturation_Greyvalue;
  hlaImagerPar.ui16Blacklevel_R_Greyvalue = hlaImagerPar.ResponseCurve.ui16_Blacklevel_R_Greyvalue;
  hlaImagerPar.ui16Blacklevel_G_Greyvalue = hlaImagerPar.ResponseCurve.ui16_Blacklevel_G_Greyvalue;
  hlaImagerPar.ui16Blacklevel_B_Greyvalue = hlaImagerPar.ResponseCurve.ui16_Blacklevel_B_Greyvalue;

  /* variables converted from (float32) to (uint32 multiplied by 65536). At the algo this values are shifted down to uint16 (+ 32768.0f + 0.5f) reason: space and speed  */
  hlaImagerPar.ui32_Kneepoint1_R_Lux = CML_u_Round2Uint((hlaImagerPar.ResponseCurve.f32_Kneepoint1_R_Lux * 65536.0f) + 32768.0f);
  hlaImagerPar.ui32_Kneepoint1_G_Lux = CML_u_Round2Uint((hlaImagerPar.ResponseCurve.f32_Kneepoint1_G_Lux * 65536.0f) + 32768.0f);
  hlaImagerPar.ui32_Kneepoint1_B_Lux = CML_u_Round2Uint((hlaImagerPar.ResponseCurve.f32_Kneepoint1_B_Lux * 65536.0f) + 32768.0f);
  
  hlaImagerPar.ui32_Kneepoint2_R_Lux = CML_u_Round2Uint((hlaImagerPar.ResponseCurve.f32_Kneepoint2_R_Lux * 65536.0f) + 32768.0f);
  hlaImagerPar.ui32_Kneepoint2_G_Lux = CML_u_Round2Uint((hlaImagerPar.ResponseCurve.f32_Kneepoint2_G_Lux * 65536.0f) + 32768.0f);
  hlaImagerPar.ui32_Kneepoint2_B_Lux = CML_u_Round2Uint((hlaImagerPar.ResponseCurve.f32_Kneepoint2_B_Lux * 65536.0f) + 32768.0f);

  /* imager saturation, absolute maximum */
  hlaImagerPar.Sat              = (uint16)(hlaImagerPar.Comp.Pout_max - 1);
  hlaImagerPar.Sat_RedLux       = HLAImager_GetLux_Red(hlaImagerPar.Sat);
  hlaImagerPar.Sat_GreenLux     = HLAImager_GetLux_Green(hlaImagerPar.Sat);
  hlaImagerPar.Sat_BlueLux      = HLAImager_GetLux_Blue(hlaImagerPar.Sat);

  /* 16 Bit integer values */
  /* red */
  {
    float32 Sat_Lux;

    Sat_Lux                        = CML_f_Min(((UI16_T_MAX - hlaImagerPar.Lux2R_3) - 1.0f), hlaImagerPar.Sat_RedLux);
    hlaImagerPar.ui16_Sat_Red      = (uint16)HLAImager_GetRed_Lux(Sat_Lux);
    hlaImagerPar.ui16_Sat_RedLux   = HLAImager_GetIntLux_Red(hlaImagerPar.ui16_Sat_Red);
    /* green */
    Sat_Lux                        = CML_f_Min(((UI16_T_MAX - hlaImagerPar.Lux2G_3) - 1.0f), hlaImagerPar.Sat_GreenLux);
    hlaImagerPar.ui16_Sat_Green    = (uint16)HLAImager_GetGreen_Lux(Sat_Lux);
    hlaImagerPar.ui16_Sat_GreenLux = HLAImager_GetIntLux_Green(hlaImagerPar.ui16_Sat_Green);
    /* blue */
    Sat_Lux                        = CML_f_Min(((UI16_T_MAX - hlaImagerPar.Lux2B_3) - 1.0f), hlaImagerPar.Sat_BlueLux);
    hlaImagerPar.ui16_Sat_Blue     = (uint16)HLAImager_GetBlue_Lux(Sat_Lux);
    hlaImagerPar.ui16_Sat_BlueLux  = HLAImager_GetIntLux_Blue(hlaImagerPar.ui16_Sat_Blue);
  }

/* ~CodeReview ~ID:fb722fedee7e77770b9dc85f08fab18a ~Reviewer:CW01\muellerr5 ~Date:17.07.2012 ~Priority:3 ~Comment:dead code -> add documentation or remove */
#if 0
  /* check ui16_lux versus f32_lux calculation */
  {
    uint32 p_in;
    uint32 Err_Cnt_red = 0;
    uint32 Err_Cnt_green = 0;
    uint32 Err_Cnt_blue = 0;

    for(p_in = 0; p_in<4000; p_in++)
    {
      float32 f32_lux_red;
      float32 f32_lux_blue;
      float32 f32_lux_green;
      float32 ui32_lux_red;
      float32 ui32_lux_blue;
      float32 ui32_lux_green;
      /* red */
      f32_lux_red  = HLAImager_GetLux_Red(p_in);
      ui32_lux_red = HLAImager_GetIntLux_Red(p_in);
      if(    (f32_lux_red > 0.0f)
          && (fabs(f32_lux_red - (float32)ui32_lux_red) > 0.55f)
        ) 
      {
        Err_Cnt_red++;
      }

      /* green */
      f32_lux_green  = HLAImager_GetLux_Green(p_in);
      ui32_lux_green = HLAImager_GetIntLux_Green(p_in);
      if(    (f32_lux_green > 0.0f)
          && (fabs(f32_lux_green - (float32)ui32_lux_green) > 0.55f)
        )
      {
        Err_Cnt_green++;
      }

      /* blue */
      f32_lux_blue  = HLAImager_GetLux_Blue(p_in);
      ui32_lux_blue = HLAImager_GetIntLux_Blue(p_in);
      if(    (f32_lux_blue > 0.0f)
          && (fabs(f32_lux_blue - (float32)ui32_lux_blue) > 0.55f)
          && (p_in <= hlaImagerPar.ui16_Sat_Blue)
        )
      {
        Err_Cnt_blue++;
      }
    }
  }
#endif
}

/* ****************************************************************************
  Functionname:     HLAImager_InitPar_Exec                               */ /*!
  Description:      Inits imager parameter
                    (the part which can be delayed until HLAR_v_Exec main loop)

  @param[in]        
  @param[in,out]    
  @param[out]       

  @return           void
  @pre              -
  @post             -
  @author           Stefan Zechner
**************************************************************************** */
void HLAImager_InitPar_Exec(void)
{
  HLAImager_FillLogLuxLookupTable();
}

/* ****************************************************************************
  Functionname:     HLAImager_GetT1Sat_Lux                        */ /*!
  Description:      Get T1 saturation region in lux (lower and upper threshold)
                    T1 saturation (LEDs and high intensity lights/ reflectors which saturates during T1
                        and which are during T2,3 on a other pixel (high dx or dy movement in the image))
                        T1Sat_L <= Intensity <= T1Sat_H                                                  

  @param[in]        
  @param[in,out]    
  @param[out]       

  @return           void
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
float32 HLAImager_GetT1SatLow_RedLux()
{
  return(hlaImagerPar.T1Sat_L_RedLux);
}
float32 HLAImager_GetT1SatHigh_RedLux()
{
  return(hlaImagerPar.T1Sat_H_RedLux);
}
float32 HLAImager_GetT1SatLow_GreenLux()
{
  return(hlaImagerPar.T1Sat_L_GreenLux);
}
float32 HLAImager_GetT1SatHigh_GreenLux()
{
  return(hlaImagerPar.T1Sat_H_GreenLux);
}
float32 HLAImager_GetT1SatLow_BlueLux()
{
  return(hlaImagerPar.T1Sat_L_BlueLux);
}
float32 HLAImager_GetT1SatHigh_BlueLux()
{
  return(hlaImagerPar.T1Sat_H_BlueLux);
}
/* integer T1 saturation */
uint16 HLAImager_GetIntT1SatLow_RedLux()
{
  return(hlaImagerPar.ui16_T1Sat_L_RedLux);
}
uint16 HLAImager_GetIntT1SatHigh_RedLux()
{
  return(hlaImagerPar.ui16_T1Sat_H_RedLux);
}
uint16 HLAImager_GetIntT1SatLow_GreenLux()
{
  return(hlaImagerPar.ui16_T1Sat_L_GreenLux);
}
uint16 HLAImager_GetIntT1SatHigh_GreenLux()
{
  return(hlaImagerPar.ui16_T1Sat_H_GreenLux);
}
uint16 HLAImager_GetIntT1SatLow_BlueLux()
{
  return(hlaImagerPar.ui16_T1Sat_L_BlueLux);
}
uint16 HLAImager_GetIntT1SatHigh_BlueLux()
{
  return(hlaImagerPar.ui16_T1Sat_H_BlueLux);
}


/* ****************************************************************************
  Functionname:     HLAImager_GetT1Sat                           */ /*!
  Description:      Get T1 saturation region in not linear 12 bits (lower and upper threshold)
                    T1 saturation (LEDs and high intensity lights/ reflectors which saturates during T1
                        and which are during T2,3 on a other pixel (high dx or dy movement in the image))
                        T1Sat_L <= Intensity <= T1Sat_H                                                  

  @param[in]        
  @param[in,out]    
  @param[out]       

  @return           void
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
uint16 HLAImager_GetT1SatLow()
{
  return(hlaImagerPar.T1Sat_L);
}
uint16 HLAImager_GetT1SatHigh()
{
  return(hlaImagerPar.T1Sat_H);
}


/* ****************************************************************************
  Functionname:     HLAImager_GetSaturation_Lux                          */ /*!
  Description:      Get imager saturation in lux
                    

  @param[in]        
  @param[in,out]    
  @param[out]       

  @return           void
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
float32 HLAImager_GetSaturation_RedLux()
{
  return(hlaImagerPar.Sat_RedLux);
}
float32 HLAImager_GetSaturation_GreenLux()
{
  return(hlaImagerPar.Sat_GreenLux);
}
float32 HLAImager_GetSaturation_BlueLux()
{
  return(hlaImagerPar.Sat_BlueLux);
}
uint16 HLAImager_GetIntSaturation_RedLux()
{
  return(hlaImagerPar.ui16_Sat_RedLux);
}
uint16 HLAImager_GetIntSaturation_GreenLux()
{
  return(hlaImagerPar.ui16_Sat_GreenLux);
}
uint16 HLAImager_GetIntSaturation_BlueLux()
{
  return(hlaImagerPar.ui16_Sat_BlueLux);
}
/* ****************************************************************************
  Functionname:     HLAImager_GetSaturation                            */ /*!
  Description:      Get imager saturation in not linear 12 bits
                    
  @param[in]        
  @param[in,out]    
  @param[out]       

  @return           void
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
uint16 HLAImager_GetSaturation()
{
  return(hlaImagerPar.Sat);
}

/* ****************************************************************************
  Functionname:     HLAImager_GetR2G                            */ /*!
  Description:      Get red/ green ratio (linear section)
                                        
  @param[in]        
  @param[in,out]    
  @param[out]       

  @return           void
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
float32 HLAImager_GetR2G()
{
  return(hlaImagerPar.R2G);
}

/* ****************************************************************************
  Functionname:     HLAImager_GetR2B                            */ /*!
  Description:      Get red/ blue ratio (linear section)
                                        
  @param[in]        
  @param[in,out]    
  @param[out]       

  @return           void
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
float32 HLAImager_GetR2B()
{
  return(hlaImagerPar.R2B);
}

/* ****************************************************************************
  Functionname:     HLAImager_GetG2R                            */ /*!
  Description:      Get green/ red ratio (linear section)
                                        
  @param[in]        
  @param[in,out]    
  @param[out]       

  @return           void
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
float32 HLAImager_GetG2R()
{
  return(hlaImagerPar.G2R);
}


/* ****************************************************************************
  Functionname:     HLAImager_Measfreeze                                 */ /*!
  Description:      send imager internal data per measfreeze
                                        
  @param[in]        
  @param[in,out]    
  @param[out]       

  @return           void
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLAImager_Measfreeze(AS_t_MeasHdlr pfMeasFreeze)
{
#ifdef HLA_ENABLE_INTERNAL_MEASFREEZES
  AS_t_MeasInfo ImagerParMeasInfo = {HLA_MEAS_VADDR_IMAGER_PARAMETERS, sizeof(hlaImagerPar), 0 /*COMP_ID_HLA*/, TASK_ID_HLA};
  (void)pfMeasFreeze(&ImagerParMeasInfo, (void*)&hlaImagerPar, NULL);
#endif
}


/* **************************************************************************** 
  Functionname:     HLAImager_luxToLog8Bit                               */ /*!  
  @description:     convert lux value to logarithmic 8-bit value

  @param[in]        float32 lux                 lux value

  @return           uint8                       normalized 8-bit value
  @pre              -
  @post             -
  @author           Stefan Zechner
**************************************************************************** */
static uint8 HLAImager_luxToLog8Bit(float32 lux)
{
  sint32 lux8Bit;

  if (lux <= HLA_IMAGER_LOGLUX_LINLOG_TRANSITION_LUX)
  {
    lux8Bit = (sint32)(HLA_IMAGER_LOGLUX_LINLOG_LIN_SLOPE * lux);
  }
  else
  {
    /* <ln_offset+1 MISRA Rule 1.2, 11.4: reviewer name: Stefan Zechner date: 21.04.2011 reason: floating point value has to be considered as int (not typecasted) in order to split mantissa and exponent  */
    const sint32 luxCast_sint32 = (*(sint32 *)&lux);

    /* ~CodeReview ~ID:329a1de552a8a4708b08fce59ff0e8f6 ~Reviewer:CW01\uidv0772 ~Date:17.07.2012 ~Priority:3 ~Comment:120930, values not defined in symbolic way (15,  23, 0x7F, ) */
    /* ~CodeReview ~ID:7c407cb78eac91b83fa80a60eefa4bc3 ~Reviewer:CW01\uidt9253 ~Date:3/23/2012 ~Priority:3 ~Comment:explain calculation of fast log2 function and describe limitation regarding IEEE floating point type */
    const float32 log2_lux_approx = (((luxCast_sint32 & 0x7f800000) >> 23) - 0x7f) + ((luxCast_sint32 & 0x007fffff) * (1/(float32)0x800000));
    lux8Bit = (sint32)(HLA_IMAGER_LOGLUX_LINLOG_LOG_OFFSET + (HLA_IMAGER_LOGLUX_LINLOG_LOG_SLOPE * log2_lux_approx));
  }

  lux8Bit = CML_MinMax(0, 255, lux8Bit);
  return (uint8)(lux8Bit);
}


/* **************************************************************************** 
  Functionname:     HLAImager_FillLogLuxLookupTable                      */ /*!  
  @description:     Prepare the pice-wise interpolation LUTs for fast pixel
                    to 8-bit LogLux conversion

  @param[in]        -

  @return           -
  @pre              -
  @post             -
  @author           Stefan Zechner
**************************************************************************** */
static void HLAImager_FillLogLuxLookupTable(void)
{
  uint8 i;

  {
    /* Red Knee 1 */
    uint16 x1 = (uint16)hlaImagerPar.ui16Blacklevel_R_Greyvalue;
    uint16 p1 = 0;

#ifdef PC_SIM
    assert(hlaImagerPar.ui16Blacklevel_R_Greyvalue + HLA_IMAGER_LOGLUX_KNEE1_TABLE_SIZE * HLA_IMAGER_LOGLUX_KNEE1_TABLE_BINSIZE >= hlaImagerPar.ui16Kneepoint1_Greyvalue);
#endif

    for (i=0; i<HLA_IMAGER_LOGLUX_KNEE1_TABLE_SIZE; i++)
    {
      uint16 x2 = (uint16)(hlaImagerPar.ui16Blacklevel_R_Greyvalue + ((i+1) * HLA_IMAGER_LOGLUX_KNEE1_TABLE_BINSIZE));

      if (x2 > hlaImagerPar.ui16Kneepoint1_Greyvalue)
      {
        x2 = (uint16)(hlaImagerPar.ui16Kneepoint1_Greyvalue);
      }

      if ((x2 > x1) &&
          (x2 > hlaImagerPar.ui16Blacklevel_R_Greyvalue))
      {
        uint16 p2 = HLAImager_luxToLog8Bit(HLAImager_GetLux_Red(x2));

        const uint16 scale = (uint16)(((uint32)(p2-p1) << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) / (uint32)(x2-x1));
        hlaImagerPar.logLuxLookupTableRedKnee1[i].scale = scale;
        hlaImagerPar.logLuxLookupTableRedKnee1[i].offset = (uint16)((p1 << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) - (scale * (x1 - hlaImagerPar.ui16Blacklevel_R_Greyvalue)));

#ifdef PC_SIM
        assert(((sint64)(p2-p1) << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) / (sint64)(x2-x1) <= UI16_T_MAX);
        assert(((sint64)p1 << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) - scale * (sint64)(x1 - hlaImagerPar.ui16Blacklevel_R_Greyvalue) <= UI16_T_MAX);
        assert(((sint64)p1 << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) - scale * (sint64)(x1 - hlaImagerPar.ui16Blacklevel_R_Greyvalue) >= 0);
#endif

        x1 = x2;
        p1 = p2;
      }
      else
      {
        hlaImagerPar.logLuxLookupTableRedKnee1[i].scale = 0;
        hlaImagerPar.logLuxLookupTableRedKnee1[i].offset = 0;
      }
    }
  }

  {
    /* Red Knee 2 */
    uint16 x1 = (uint16)hlaImagerPar.ui16Kneepoint1_Greyvalue;
    uint16 p1 = HLAImager_luxToLog8Bit(HLAImager_GetLux_Red(x1));

#ifdef PC_SIM
    assert(hlaImagerPar.ui16Kneepoint1_Greyvalue + HLA_IMAGER_LOGLUX_KNEE2_TABLE_SIZE * HLA_IMAGER_LOGLUX_KNEE2_TABLE_BINSIZE >= hlaImagerPar.ui16Kneepoint2_Greyvalue);
#endif

    for (i=0; i<HLA_IMAGER_LOGLUX_KNEE2_TABLE_SIZE; i++)
    {
      uint16 x2 = (uint16)(hlaImagerPar.ui16Kneepoint1_Greyvalue + ((i+1) * HLA_IMAGER_LOGLUX_KNEE2_TABLE_BINSIZE));

      if (x2 > hlaImagerPar.ui16Kneepoint2_Greyvalue)
      {
        x2 = (uint16)(hlaImagerPar.ui16Kneepoint2_Greyvalue);
      }

      if (x2 > x1)
      {
        uint16 p2 = HLAImager_luxToLog8Bit(HLAImager_GetLux_Red(x2));

        const uint16 scale = (uint16)(((uint32)(p2-p1) << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) / (uint32)(x2-x1));
        hlaImagerPar.logLuxLookupTableRedKnee2[i].scale = scale;
        hlaImagerPar.logLuxLookupTableRedKnee2[i].offset = (uint16)((p1 << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) - (scale * (x1 - hlaImagerPar.ui16Kneepoint1_Greyvalue)));

#ifdef PC_SIM
        assert(((sint64)(p2-p1) << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) / (sint64)(x2-x1) <= UI16_T_MAX);
        assert(((sint64)p1 << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) - scale * (sint64)(x1 - hlaImagerPar.ui16Kneepoint1_Greyvalue) <= UI16_T_MAX);
        assert(((sint64)p1 << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) - scale * (sint64)(x1 - hlaImagerPar.ui16Kneepoint1_Greyvalue) >= 0);
#endif

        x1 = x2;
        p1 = p2;
      }
      else
      {
        hlaImagerPar.logLuxLookupTableRedKnee2[i].scale = 0;
        hlaImagerPar.logLuxLookupTableRedKnee2[i].offset = 0;
      }
    }
  }

  {
    /* Red Knee 3 */
    uint16 x1 = (uint16)hlaImagerPar.ui16Kneepoint2_Greyvalue;
    uint16 p1 = HLAImager_luxToLog8Bit(HLAImager_GetLux_Red(x1));
    const float32 xSat = HLAImager_GetRed_Lux(powf(2.0f, (255.0f - HLA_IMAGER_LOGLUX_LINLOG_LOG_OFFSET) / HLA_IMAGER_LOGLUX_LINLOG_LOG_SLOPE));

#ifdef PC_SIM
    assert(hlaImagerPar.ui16Kneepoint2_Greyvalue + HLA_IMAGER_LOGLUX_KNEE3_TABLE_SIZE * HLA_IMAGER_LOGLUX_KNEE3_TABLE_BINSIZE >= hlaImagerPar.ui16Saturation_Greyvalue);
#endif

    for (i=0; i<HLA_IMAGER_LOGLUX_KNEE3_TABLE_SIZE; i++)
    {
      uint16 x2 = (uint16)(hlaImagerPar.ui16Kneepoint2_Greyvalue + ((i+1) * HLA_IMAGER_LOGLUX_KNEE3_TABLE_BINSIZE));

      if (x2 > xSat)
      {
        x2 = (uint16)xSat;
      }

      if (x2 > x1)
      {
        uint16 p2 = HLAImager_luxToLog8Bit(HLAImager_GetLux_Red(x2));

        const uint16 scale = (uint16)(((uint32)(p2-p1) << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) / (uint32)(x2-x1));
        hlaImagerPar.logLuxLookupTableRedKnee3[i].scale = scale;
        hlaImagerPar.logLuxLookupTableRedKnee3[i].offset = (uint16)((p1 << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) - (scale * (x1 - hlaImagerPar.ui16Kneepoint2_Greyvalue)));

#ifdef PC_SIM
        assert(((sint64)(p2-p1) << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) / (sint64)(x2-x1) <= UI16_T_MAX);
        assert(((sint64)p1 << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) - scale * (sint64)(x1 - hlaImagerPar.ui16Kneepoint2_Greyvalue) <= UI16_T_MAX);
        assert(((sint64)p1 << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) - scale * (sint64)(x1 - hlaImagerPar.ui16Kneepoint2_Greyvalue) >= 0);
#endif

        x1 = x2;
        p1 = p2;
      }
      else
      {
        hlaImagerPar.logLuxLookupTableRedKnee3[i].scale = 0;
        hlaImagerPar.logLuxLookupTableRedKnee3[i].offset = HLAImager_luxToLog8Bit(HLAImager_GetLux_Red(x2)) << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2;
      }
    }
  }

  {
    /* Green Knee 1 */
    uint16 x1 = (uint16)hlaImagerPar.ui16Blacklevel_G_Greyvalue;
    uint16 p1 = 0;

#ifdef PC_SIM
    assert(hlaImagerPar.ui16Blacklevel_G_Greyvalue + HLA_IMAGER_LOGLUX_KNEE1_TABLE_SIZE * HLA_IMAGER_LOGLUX_KNEE1_TABLE_BINSIZE >= hlaImagerPar.ui16Kneepoint1_Greyvalue);
#endif

    for (i=0; i<HLA_IMAGER_LOGLUX_KNEE1_TABLE_SIZE; i++)
    {
      uint16 x2 = (uint16)(hlaImagerPar.ui16Blacklevel_G_Greyvalue + ((i+1) * HLA_IMAGER_LOGLUX_KNEE1_TABLE_BINSIZE));

      if (x2 > hlaImagerPar.ui16Kneepoint1_Greyvalue)
      {
        x2 = (uint16)(hlaImagerPar.ui16Kneepoint1_Greyvalue);
      }

      if ((x2 > x1) &&
          (x2 > hlaImagerPar.ui16Blacklevel_G_Greyvalue))
      {
        uint16 p2 = HLAImager_luxToLog8Bit(HLAImager_GetLux_Green(x2));

        const uint16 scale = (uint16)(((uint32)(p2-p1) << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) / (uint32)(x2-x1));
        hlaImagerPar.logLuxLookupTableGreenKnee1[i].scale = scale;
        hlaImagerPar.logLuxLookupTableGreenKnee1[i].offset = (uint16)((p1 << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) - (scale * (x1 - hlaImagerPar.ui16Blacklevel_G_Greyvalue)));

#ifdef PC_SIM
        assert(((sint64)(p2-p1) << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) / (sint64)(x2-x1) <= UI16_T_MAX);
        assert(((sint64)p1 << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) - scale * (sint64)(x1 - hlaImagerPar.ui16Blacklevel_G_Greyvalue) <= UI16_T_MAX);
        assert(((sint64)p1 << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) - scale * (sint64)(x1 - hlaImagerPar.ui16Blacklevel_G_Greyvalue) >= 0);
#endif

        x1 = x2;
        p1 = p2;
      }
      else
      {
        hlaImagerPar.logLuxLookupTableGreenKnee1[i].scale = 0;
        hlaImagerPar.logLuxLookupTableGreenKnee1[i].offset = 0;
      }
    }
  }

  {
    /* Green Knee 2 */
    uint16 x1 = (uint16)hlaImagerPar.ui16Kneepoint1_Greyvalue;
    uint16 p1 = HLAImager_luxToLog8Bit(HLAImager_GetLux_Green(x1));

#ifdef PC_SIM
    assert(hlaImagerPar.ui16Kneepoint1_Greyvalue + HLA_IMAGER_LOGLUX_KNEE2_TABLE_SIZE * HLA_IMAGER_LOGLUX_KNEE2_TABLE_BINSIZE >= hlaImagerPar.ui16Kneepoint2_Greyvalue);
#endif

    for (i=0; i<HLA_IMAGER_LOGLUX_KNEE2_TABLE_SIZE; i++)
    {
      uint16 x2 = (uint16)(hlaImagerPar.ui16Kneepoint1_Greyvalue + ((i+1) * HLA_IMAGER_LOGLUX_KNEE2_TABLE_BINSIZE));

      if (x2 > hlaImagerPar.ui16Kneepoint2_Greyvalue)
      {
        x2 = (uint16)(hlaImagerPar.ui16Kneepoint2_Greyvalue);
      }

      if (x2 > x1)
      {
        uint16 p2 = HLAImager_luxToLog8Bit(HLAImager_GetLux_Green(x2));

        const uint16 scale = (uint16)(((uint32)(p2-p1) << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) / (uint32)(x2-x1));
        hlaImagerPar.logLuxLookupTableGreenKnee2[i].scale = scale;
        hlaImagerPar.logLuxLookupTableGreenKnee2[i].offset = (uint16)((p1 << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) - (scale * (x1 - hlaImagerPar.ui16Kneepoint1_Greyvalue)));

#ifdef PC_SIM
        assert(((sint64)(p2-p1) << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) / (sint64)(x2-x1) <= UI16_T_MAX);
        assert(((sint64)p1 << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) - scale * (sint64)(x1 - hlaImagerPar.ui16Kneepoint1_Greyvalue) <= UI16_T_MAX);
        assert(((sint64)p1 << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) - scale * (sint64)(x1 - hlaImagerPar.ui16Kneepoint1_Greyvalue) >= 0);
#endif

        x1 = x2;
        p1 = p2;
      }
      else
      {
        hlaImagerPar.logLuxLookupTableGreenKnee2[i].scale = 0;
        hlaImagerPar.logLuxLookupTableGreenKnee2[i].offset = 0;
      }
    }
  }

  {
    /* Green Knee 3 */
    uint16 x1 = (uint16)hlaImagerPar.ui16Kneepoint2_Greyvalue;
    uint16 p1 = HLAImager_luxToLog8Bit(HLAImager_GetLux_Green(x1));
    const float32 xSat = HLAImager_GetGreen_Lux(powf(2.0f, (255.0f - HLA_IMAGER_LOGLUX_LINLOG_LOG_OFFSET) / HLA_IMAGER_LOGLUX_LINLOG_LOG_SLOPE));

#ifdef PC_SIM
    assert(hlaImagerPar.ui16Kneepoint2_Greyvalue + HLA_IMAGER_LOGLUX_KNEE3_TABLE_SIZE * HLA_IMAGER_LOGLUX_KNEE3_TABLE_BINSIZE >= hlaImagerPar.ui16Saturation_Greyvalue);
#endif

    for (i=0; i<HLA_IMAGER_LOGLUX_KNEE3_TABLE_SIZE; i++)
    {
      uint16 x2 = (uint16)(hlaImagerPar.ui16Kneepoint2_Greyvalue + ((i+1) * HLA_IMAGER_LOGLUX_KNEE3_TABLE_BINSIZE));

      if (x2 > xSat)
      {
        x2 = (uint16)xSat;
      }

      if (x2 > x1)
      {
        uint16 p2 = HLAImager_luxToLog8Bit(HLAImager_GetLux_Green(x2));

        const uint16 scale = (uint16)(((uint32)(p2-p1) << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) / (uint32)(x2-x1));
        hlaImagerPar.logLuxLookupTableGreenKnee3[i].scale = scale;
        hlaImagerPar.logLuxLookupTableGreenKnee3[i].offset = (uint16)((p1 << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) - (scale * (x1 - hlaImagerPar.ui16Kneepoint2_Greyvalue)));

#ifdef PC_SIM
        assert(((sint64)(p2-p1) << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) / (sint64)(x2-x1) <= UI16_T_MAX);
        assert(((sint64)p1 << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) - scale * (sint64)(x1 - hlaImagerPar.ui16Kneepoint2_Greyvalue) <= UI16_T_MAX);
        assert(((sint64)p1 << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) - scale * (sint64)(x1 - hlaImagerPar.ui16Kneepoint2_Greyvalue) >= 0);
#endif

        x1 = x2;
        p1 = p2;
      }
      else
      {
        hlaImagerPar.logLuxLookupTableGreenKnee3[i].scale = 0;
        hlaImagerPar.logLuxLookupTableGreenKnee3[i].offset = HLAImager_luxToLog8Bit(HLAImager_GetLux_Green(x2)) << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2;
      }
    }
  }

  {
    /* Blue Knee 1 */
    uint16 x1 = (uint16)hlaImagerPar.ui16Blacklevel_B_Greyvalue;
    uint16 p1 = 0;

#ifdef PC_SIM
    assert(hlaImagerPar.ui16Blacklevel_B_Greyvalue + HLA_IMAGER_LOGLUX_KNEE1_TABLE_SIZE * HLA_IMAGER_LOGLUX_KNEE1_TABLE_BINSIZE >= hlaImagerPar.ui16Kneepoint1_Greyvalue);
#endif

    for (i=0; i<HLA_IMAGER_LOGLUX_KNEE1_TABLE_SIZE; i++)
    {
      uint16 x2 = (uint16)(hlaImagerPar.ui16Blacklevel_B_Greyvalue + ((i+1) * HLA_IMAGER_LOGLUX_KNEE1_TABLE_BINSIZE));

      if (x2 > hlaImagerPar.ui16Kneepoint1_Greyvalue)
      {
        x2 = (uint16)(hlaImagerPar.ui16Kneepoint1_Greyvalue);
      }

      if ((x2 > x1) &&
          (x2 > hlaImagerPar.ui16Blacklevel_B_Greyvalue))
      {
        uint16 p2 = HLAImager_luxToLog8Bit(HLAImager_GetLux_Blue(x2));

        const uint16 scale = (uint16)(((uint32)(p2-p1) << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) / (uint32)(x2-x1));
        hlaImagerPar.logLuxLookupTableBlueKnee1[i].scale = scale;
        hlaImagerPar.logLuxLookupTableBlueKnee1[i].offset = (uint16)((p1 << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) - (scale * (x1 - hlaImagerPar.ui16Blacklevel_B_Greyvalue)));

#ifdef PC_SIM
        assert(((sint64)(p2-p1) << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) / (sint64)(x2-x1) <= UI16_T_MAX);
        assert(((sint64)p1 << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) - scale * (sint64)(x1 - hlaImagerPar.ui16Blacklevel_B_Greyvalue) <= UI16_T_MAX);
        assert(((sint64)p1 << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) - scale * (sint64)(x1 - hlaImagerPar.ui16Blacklevel_B_Greyvalue) >= 0);
#endif

        x1 = x2;
        p1 = p2;
      }
      else
      {
        hlaImagerPar.logLuxLookupTableBlueKnee1[i].scale = 0;
        hlaImagerPar.logLuxLookupTableBlueKnee1[i].offset = 0;
      }
    }
  }

  {
    /* Blue Knee 2 */
    uint16 x1 = (uint16)hlaImagerPar.ui16Kneepoint1_Greyvalue;
    uint16 p1 = HLAImager_luxToLog8Bit(HLAImager_GetLux_Blue(x1));

#ifdef PC_SIM
    assert(hlaImagerPar.ui16Kneepoint1_Greyvalue + HLA_IMAGER_LOGLUX_KNEE2_TABLE_SIZE * HLA_IMAGER_LOGLUX_KNEE2_TABLE_BINSIZE >= hlaImagerPar.ui16Kneepoint2_Greyvalue);
#endif

    for (i=0; i<HLA_IMAGER_LOGLUX_KNEE2_TABLE_SIZE; i++)
    {
      uint16 x2 = (uint16)(hlaImagerPar.ui16Kneepoint1_Greyvalue + ((i+1) * HLA_IMAGER_LOGLUX_KNEE2_TABLE_BINSIZE));

      if (x2 > hlaImagerPar.ui16Kneepoint2_Greyvalue)
      {
        x2 = (uint16)(hlaImagerPar.ui16Kneepoint2_Greyvalue);
      }

      if (x2 > x1)
      {
        uint16 p2 = HLAImager_luxToLog8Bit(HLAImager_GetLux_Blue(x2));

        const uint16 scale = (uint16)(((uint32)(p2-p1) << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) / (uint32)(x2-x1));
        hlaImagerPar.logLuxLookupTableBlueKnee2[i].scale = scale;
        hlaImagerPar.logLuxLookupTableBlueKnee2[i].offset = (uint16)((p1 << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) - (scale * (x1 - hlaImagerPar.ui16Kneepoint1_Greyvalue)));

#ifdef PC_SIM
        assert(((sint64)(p2-p1) << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) / (sint64)(x2-x1) <= UI16_T_MAX);
        assert(((sint64)p1 << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) - scale * (sint64)(x1 - hlaImagerPar.ui16Kneepoint1_Greyvalue) <= UI16_T_MAX);
        assert(((sint64)p1 << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) - scale * (sint64)(x1 - hlaImagerPar.ui16Kneepoint1_Greyvalue) >= 0);
#endif

        x1 = x2;
        p1 = p2;
      }
      else
      {
        hlaImagerPar.logLuxLookupTableBlueKnee2[i].scale = 0;
        hlaImagerPar.logLuxLookupTableBlueKnee2[i].offset = 0;
      }
    }
  }

  {
    /* Blue Knee 3 */
    uint16 x1 = (uint16)hlaImagerPar.ui16Kneepoint2_Greyvalue;
    uint16 p1 = HLAImager_luxToLog8Bit(HLAImager_GetLux_Blue(x1));
    const float32 xSat = HLAImager_GetBlue_Lux(powf(2.0f, (255.0f - HLA_IMAGER_LOGLUX_LINLOG_LOG_OFFSET) / HLA_IMAGER_LOGLUX_LINLOG_LOG_SLOPE));

#ifdef PC_SIM
    assert(hlaImagerPar.ui16Kneepoint2_Greyvalue + HLA_IMAGER_LOGLUX_KNEE3_TABLE_SIZE * HLA_IMAGER_LOGLUX_KNEE3_TABLE_BINSIZE >= hlaImagerPar.ui16Saturation_Greyvalue);
#endif

    for (i=0; i<HLA_IMAGER_LOGLUX_KNEE3_TABLE_SIZE; i++)
    {
      uint16 x2 = (uint16)(hlaImagerPar.ui16Kneepoint2_Greyvalue + ((i+1) * HLA_IMAGER_LOGLUX_KNEE3_TABLE_BINSIZE));

      if (x2 > xSat)
      {
        x2 = (uint16)xSat;
      }

      if (x2 > x1)
      {
        uint16 p2 = HLAImager_luxToLog8Bit(HLAImager_GetLux_Blue(x2));

        const uint16 scale = (uint16)(((uint32)(p2-p1) << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) / (uint32)(x2-x1));
        hlaImagerPar.logLuxLookupTableBlueKnee3[i].scale = scale;
        hlaImagerPar.logLuxLookupTableBlueKnee3[i].offset = (uint16)((p1 << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) - (scale * (x1 - hlaImagerPar.ui16Kneepoint2_Greyvalue)));

#ifdef PC_SIM
        assert(((sint64)(p2-p1) << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) / (sint64)(x2-x1) <= UI16_T_MAX);
        assert(((sint64)p1 << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) - scale * (sint64)(x1 - hlaImagerPar.ui16Kneepoint2_Greyvalue) <= UI16_T_MAX);
        assert(((sint64)p1 << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2) - scale * (sint64)(x1 - hlaImagerPar.ui16Kneepoint2_Greyvalue) >= 0);
#endif

        x1 = x2;
        p1 = p2;
      }
      else
      {
        hlaImagerPar.logLuxLookupTableBlueKnee3[i].scale = 0;
        hlaImagerPar.logLuxLookupTableBlueKnee3[i].offset = HLAImager_luxToLog8Bit(HLAImager_GetLux_Blue(x2)) << HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2;
      }
    }
  }
}/* PRQA S 861 1 */
