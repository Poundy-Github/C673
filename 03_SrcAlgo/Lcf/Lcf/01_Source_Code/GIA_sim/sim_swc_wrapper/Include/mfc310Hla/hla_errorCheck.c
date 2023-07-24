/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_errorCheck.c

  DESCRIPTION:            Error checking routines

  AUTHOR:                 Stefan Zechner

  CREATION DATE:          2011-06-29

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_errorCheck.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:26:32CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:37:43CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:07CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/project.pj
  CHANGE:                 Revision 1.54 2014/03/25 19:02:58CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replaced fABS by CML_f_abs
  CHANGE:                 Introduced CML_f_Round
  CHANGE:                 Removed QAC warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 25, 2014 7:02:59 PM CET]
  CHANGE:                 Change Package : 207432:46 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.53 2014/03/21 09:38:39CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed some QAC warnings (parenthesis)
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 21, 2014 9:38:39 AM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.52 2014/03/19 16:30:24CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGE:                 Fixed hlar input adapter for old recordings (headlamp type)
  CHANGE:                 Clean-up of no longer needed files in simulation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 19, 2014 4:30:25 PM CET]
  CHANGE:                 Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGE:                 Revision 1.51 2014/03/12 18:07:34CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Added LRF on EVE
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 12, 2014 6:07:34 PM CET]
  CHANGE:                 Change Package : 198642:8 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.50 2014/03/11 11:03:27CET Brunn, Marcus (brunnm) 
  CHANGE:                 changed error check for s_CroppedRoiX1 (values from 0..2000 are ok)
  CHANGE:                 --- Added comments ---  brunnm [Mar 11, 2014 11:03:27 AM CET]
  CHANGE:                 Change Package : 207431:1 http://mks-psad:7002/im/viewissue?selection=207431
  CHANGE:                 Revision 1.49 2014/03/10 13:21:03CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed some new critical QAC warnings
  CHANGE:                 Moved suppressions from .hoc file to comment in source code
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 10, 2014 1:21:04 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.48 2014/03/04 18:00:54CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed ppars and vehpar from RTE and internal interface
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 6:00:54 PM CET]
  CHANGE:                 Change Package : 207432:38 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.47 2014/02/28 15:04:54CET Brunn, Marcus (brunnm) 
  CHANGE:                 - improved light filtering
  CHANGE:                 - preparation of light list for new rte interface i390
  CHANGE:                 --- Added comments ---  brunnm [Feb 28, 2014 3:04:54 PM CET]
  CHANGE:                 Change Package : 217024:1 http://mks-psad:7002/im/viewissue?selection=217024
  CHANGE:                 Revision 1.46 2014/02/24 12:23:36CET Brunn, Marcus (brunnm) 
  CHANGE:                 fixed dFrame calculation 
  CHANGE:                 - consider wrap around of frame count after 8 or 16 bit
  CHANGE:                 --- Added comments ---  brunnm [Feb 24, 2014 12:23:36 PM CET]
  CHANGE:                 Change Package : 217024:1 http://mks-psad:7002/im/viewissue?selection=217024
  CHANGE:                 Revision 1.45 2014/02/07 16:33:01CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed dframe calculation
  CHANGE:                 Updated time meas inside segmentation
  CHANGE:                 Updated HIL according to latest changes
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 7, 2014 4:33:02 PM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.44 2014/02/06 16:02:43CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Refactoring of hla debug output (time meas, removed redundant stuff)
  CHANGE:                 Centralized Null pointer checks
  CHANGE:                 Refactored dframe calculation
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 6, 2014 4:02:44 PM CET]
  CHANGE:                 Change Package : 214576:1 http://mks-psad:7002/im/viewissue?selection=214576
  CHANGE:                 Revision 1.43 2014/01/24 09:35:00CET Glebov, Roman (uidg4759) 
  CHANGE:                 switched from F32_IS_.* from global_defs.h to HLA_F32_IS_.* from hla_defs.h. 
  CHANGE:                 These are custom versions, which use much smaller Epsilon delta for comparison with 0
  CHANGE:                 --- Added comments ---  uidg4759 [Jan 24, 2014 9:35:00 AM CET]
  CHANGE:                 Change Package : 193435:4 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGE:                 Revision 1.42 2014/01/21 13:57:07CET Glebov, Roman (uidg4759) 
  CHANGE:                 fixed unsafe comparison of float with 0
  CHANGE:                 --- Added comments ---  uidg4759 [Jan 21, 2014 1:57:08 PM CET]
  CHANGE:                 Change Package : 193435:4 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGE:                 Revision 1.41 2014/01/10 18:33:28CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 First part of LRF on EVE (disabled)
  CHANGE:                 Merged LRF inputs into one struct
  CHANGE:                 Fixed exception handling of internal cali 
  CHANGE:                 Removed all tabs in the code and further clean-up
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:29 PM CET]
  CHANGE:                 Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.40 2014/01/08 17:10:29CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Refactored HLA_Exec() function
  CHANGE:                 Replaced uint64 time stamps by uint32 ones
  CHANGE:                 Smaller bug fixes
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 8, 2014 5:10:30 PM CET]
  CHANGE:                 Change Package : 207432:27 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.39 2013/12/13 16:45:10CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Service functions are now passed in one struct
  CHANGE:                 SDLfile definitions moved to separate file
  CHANGE:                 --- Added comments ---  uidv7867 [Dec 13, 2013 4:45:10 PM CET]
  CHANGE:                 Change Package : 207432:20 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.38 2013/12/11 08:59:38CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Error checks:
  CHANGE:                 - Frame count comparison between image and IC
  CHANGE:                 - Lens center, focal length, etc. (merge from I320 branch)
  CHANGE:                 Enabled internal measfreezes again
  CHANGES:                Reviewed by AlexF
  CHANGE:                 --- Added comments ---  uidv7867 [Dec 11, 2013 8:59:38 AM CET]
  CHANGE:                 Change Package : 207432:2 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.37 2013/11/21 17:53:51CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Merge from NEW_SEG branch
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 5:53:52 PM CET]
  CHANGE:                 Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.36.1.7 2013/11/21 13:37:37CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Improved Icon normalize
  CHANGE:                 Bug fixes in segmentation
  CHANGE:                 Removed no longer compiler switches
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 1:37:37 PM CET]
  CHANGE:                 Change Package : 207432:1 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.36.1.6 2013/10/30 13:06:42CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed no longer needed error warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Oct 30, 2013 1:06:42 PM CET]
  CHANGE:                 Change Package : 201787:4 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGE:                 Revision 1.36.1.5 2013/10/29 18:21:27CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Time meas fixes
  CHANGE:                 New roi calculation (alignment to eve)
  CHANGE:                 Call EVE in segmentation now
  CHANGE:                 --- Added comments ---  uidv7867 [Oct 29, 2013 6:21:27 PM CET]
  CHANGE:                 Change Package : 201787:2 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGE:                 Revision 1.36.1.4 2013/10/24 16:07:47CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fix for previous check-in
  CHANGE:                 --- Added comments ---  uidv7867 [Oct 24, 2013 4:07:48 PM CEST]
  CHANGE:                 Change Package : 201787:2 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGE:                 Revision 1.36.1.2 2013/10/24 10:44:18CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed some not needed variables
  CHANGE:                 Made HLA working on evalboard
  CHANGE:                 --- Added comments ---  uidv7867 [Oct 24, 2013 10:44:18 AM CEST]
  CHANGE:                 Change Package : 201787:2 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGE:                 Revision 1.36.1.1 2013/10/18 13:27:54CEST Brunn, Marcus (brunnm) 
  CHANGE:                 intial version of new segmentation
  CHANGE:                 --- Added comments ---  brunnm [Oct 18, 2013 1:27:54 PM CEST]
  CHANGE:                 Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGE:                 Revision 1.36 2013/08/30 14:15:04CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fix: ROIX1 calc wrong for ECU
  CHANGE:                 --- Added comments ---  uidv7867 [Aug 30, 2013 2:15:04 PM CEST]
  CHANGE:                 Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.35 2013/08/30 13:29:50CEST Manz, Alexander (uidv8777) 
  CHANGE:                 Update: added an error to be raised when there is a high deviation in the imager response curve between ECU and DLL.
  CHANGE:                 Change was needed due to getting rid of SIM_Overlay in visualization
  CHANGE:                 --- Added comments ---  uidv8777 [Aug 30, 2013 1:29:51 PM CEST]
  CHANGE:                 Change Package : 189284:1 http://mks-psad:7002/im/viewissue?selection=189284
  CHANGE:                 Revision 1.34 2013/08/27 17:13:29CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed icon extraction
  CHANGE:                 --- Added comments ---  uidv7867 [Aug 27, 2013 5:13:29 PM CEST]
  CHANGE:                 Change Package : 195030:1 http://mks-psad:7002/im/viewissue?selection=195030
  CHANGE:                 Revision 1.33 2013/08/15 14:23:07CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Improved EDMA handling on EVE side
  CHANGE:                 --- Added comments ---  uidv7867 [Aug 15, 2013 2:23:07 PM CEST]
  CHANGE:                 Change Package : 192116:1 http://mks-psad:7002/im/viewissue?selection=192116
  CHANGE:                 Revision 1.32 2013/08/09 17:53:28CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Eve bug fixes:
  CHANGE:                 - # of seglines of function roi
  CHANGE:                 - eve return code
  CHANGE:                 --- Added comments ---  uidv7867 [Aug 9, 2013 5:53:28 PM CEST]
  CHANGE:                 Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.31 2013/05/23 09:44:59CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Added error check for DCG factor from PPAR
  CHANGE:                 --- Added comments ---  uidv7867 [May 23, 2013 9:44:59 AM CEST]
  CHANGE:                 Change Package : 167173:30 http://mks-psad:7002/im/viewissue?selection=167173
**************************************************************************** */


/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "hla_errorCheck.h"

/* J.Häfer: Redundant including of math.h is checked */
#include <math.h>

/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/
/* ~CodeReview ~ID:546c3d112af5ec181216f442467be7fd ~Reviewer:CW01\uidt9253 ~Date:4/2/2012 ~Priority:3 ~Comment:use the define HLA_ERROR and HLA_NO_ERROR */


/*****************************************************************************
  MACROS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/


/*****************************************************************************
  VARIABLES 
*****************************************************************************/
static AlgoDataTimeStamp_t old_TimeStamp_HLA_us;
static AlgoDataTimeStamp_t old_TimeStamp_VDY_us;
static AlgoDataTimeStamp_t old_TimeStamp_Image_us;


/*****************************************************************************
  FUNCTION 
*****************************************************************************/
void HLAErrorCheck_Init(void)
{
  old_TimeStamp_HLA_us = 0;
  old_TimeStamp_VDY_us = 0;
  old_TimeStamp_Image_us = 0;
}

boolean HLAErrorCheck_NullPointer( const HLAR_t_RequiredInputs*  pReqIn,
                                   const HLAR_t_ProvidedOutputs* pProvOut,
                                   const t_PixelData*            pImgData,
                                   const AS_t_ServiceFuncts*     Services,
                                         HLA_t_SystemInfo*       pSystemInfo
                                  )
{
  boolean nullPointer = b_TRUE;

  /* if pSystemInfo is NULL we cannot visualize an error */
  if (pSystemInfo != NULL)
  {
    nullPointer = b_FALSE;
    /* Check whether our input data is valid */
    nullPointer |= (boolean)(pReqIn   == NULL);
    nullPointer |= (boolean)(pProvOut == NULL);
    nullPointer |= (boolean)(pImgData == NULL);
    nullPointer |= (boolean)(Services == NULL);

    if (nullPointer == b_TRUE)
    {
      /* There are NULL pointers, let's set an error message */
      pSystemInfo->errors.error[HLA_ERRORID_INPUT].status = HLA_ERRORSTATUS_CHECK_DONE_AND_FAILED;
      pSystemInfo->errors.error[HLA_ERRORID_INPUT].optData = HLA_ERRORID_OPTDATA_INPUT_NULL_POINTER;
    }
  }

  return nullPointer;
}

uint8 HLAErrorCheck_Vehicle(      HLA_t_SystemInfo*      ps_SystemInfo,
                            const HLA_t_HeadlightState*  pHeadlightState
                           )
{
  uint8 ret = 1;

  ps_SystemInfo->errors.error[HLA_ERRORID_VEHICLE_DATA].status = HLA_ERRORSTATUS_CHECK_DONE_AND_PASSED;

  if (pHeadlightState->e_LightModuleState == RTE_HLA_LTM_FAULT)
  {
    ps_SystemInfo->errors.error[HLA_ERRORID_VEHICLE_DATA].status = HLA_ERRORSTATUS_CHECK_DONE_AND_FAILED;
    ps_SystemInfo->errors.error[HLA_ERRORID_VEHICLE_DATA].optData = HLA_ERRORID_OPTDATA_VEHICLE_LIGHT_MODULE_STATE_FAULT;
    ret = 0;
  }
  return ret;
}

uint8 HLAErrorCheck_ImageData(      HLA_t_SystemInfo*           ps_SystemInfo,
                              const HLA_t_ImagerCharacteristic* imagerCharacteristic,
                              const HLA_t_CameraParameter*      cameraParameter
                             )
{
  uint8 ret = 1;

  if (ps_SystemInfo->errors.error[HLA_ERRORID_IMAGE_DATA].status != HLA_ERRORSTATUS_SIM_CHECK_DONE_AND_FAILED)
  {
    ps_SystemInfo->errors.error[HLA_ERRORID_IMAGE_DATA].status = HLA_ERRORSTATUS_CHECK_DONE_AND_PASSED;

    /* check imager control response curve */
    if (    (imagerCharacteristic->ui32_R1 == 16) 
         && (imagerCharacteristic->ui32_R2 == 16)
       )
    {
      if (    (imagerCharacteristic->s_ResponseCurve.ui16_Blacklevel_R_Greyvalue < 157.0f) 
           || (imagerCharacteristic->s_ResponseCurve.ui16_Blacklevel_R_Greyvalue > 177.0f) 
           || (imagerCharacteristic->s_ResponseCurve.ui16_Blacklevel_G_Greyvalue < 157.0f) 
           || (imagerCharacteristic->s_ResponseCurve.ui16_Blacklevel_G_Greyvalue > 177.0f) 
           || (imagerCharacteristic->s_ResponseCurve.ui16_Blacklevel_B_Greyvalue < 157.0f) 
           || (imagerCharacteristic->s_ResponseCurve.ui16_Blacklevel_B_Greyvalue > 177.0f)
           || (imagerCharacteristic->s_ResponseCurve.ui16_Kneepoint1_Greyvalue < 2047.5f) 
           || (imagerCharacteristic->s_ResponseCurve.ui16_Kneepoint1_Greyvalue > 2048.5f) 
           || (imagerCharacteristic->s_ResponseCurve.ui16_Kneepoint2_Greyvalue < 3039.5f) 
           || (imagerCharacteristic->s_ResponseCurve.ui16_Kneepoint2_Greyvalue > 3040.5f) 
           || (imagerCharacteristic->s_ResponseCurve.ui16_Saturation_Greyvalue < 3999.5f) 
           || (imagerCharacteristic->s_ResponseCurve.ui16_Saturation_Greyvalue > 4000.5f)
         )
      {
        ps_SystemInfo->errors.error[HLA_ERRORID_IMAGE_DATA].status = HLA_ERRORSTATUS_CHECK_DONE_AND_FAILED;
        ps_SystemInfo->errors.error[HLA_ERRORID_IMAGE_DATA].optData = HLA_ERRORID_OPTDATA_IMAGE_DATA_IC_RESPCURVE_GREYVALUE;
        ret = 0;
      }

      if (    (imagerCharacteristic->s_ResponseCurve.f32_Kneepoint1_R_Lux < 37.8f) 
           || (imagerCharacteristic->s_ResponseCurve.f32_Kneepoint1_R_Lux > 63.0f) 
           || (imagerCharacteristic->s_ResponseCurve.f32_Kneepoint1_G_Lux < 47.4f) 
           || (imagerCharacteristic->s_ResponseCurve.f32_Kneepoint1_G_Lux > 79.0f) 
           || (imagerCharacteristic->s_ResponseCurve.f32_Kneepoint1_B_Lux < 113.7f) 
           || (imagerCharacteristic->s_ResponseCurve.f32_Kneepoint1_B_Lux > 190.0f) 
           || (imagerCharacteristic->s_ResponseCurve.f32_Kneepoint2_R_Lux < 1313.0f) 
           || (imagerCharacteristic->s_ResponseCurve.f32_Kneepoint2_R_Lux > 2188.0f) 
           || (imagerCharacteristic->s_ResponseCurve.f32_Kneepoint2_G_Lux < 1647.0f) 
           || (imagerCharacteristic->s_ResponseCurve.f32_Kneepoint2_G_Lux > 2745.0f) 
           || (imagerCharacteristic->s_ResponseCurve.f32_Kneepoint2_B_Lux < 3950.0f) 
           || (imagerCharacteristic->s_ResponseCurve.f32_Kneepoint2_B_Lux > 6584.0f)
         )
      {
        ps_SystemInfo->errors.error[HLA_ERRORID_IMAGE_DATA].status = HLA_ERRORSTATUS_CHECK_DONE_AND_FAILED;
        ps_SystemInfo->errors.error[HLA_ERRORID_IMAGE_DATA].optData = HLA_ERRORID_OPTDATA_IMAGE_DATA_IC_RESPCURVE_KNEELUX;
        ret = 0;
      }

      if (    (imagerCharacteristic->s_ResponseCurve.f32_Saturation_R_Lux < 21058.0f) 
           || (imagerCharacteristic->s_ResponseCurve.f32_Saturation_R_Lux > 35096.0f) 
           || (imagerCharacteristic->s_ResponseCurve.f32_Saturation_G_Lux < 26419.0f) 
           || (imagerCharacteristic->s_ResponseCurve.f32_Saturation_G_Lux > 44032.0f) 
           || (imagerCharacteristic->s_ResponseCurve.f32_Saturation_B_Lux < 63360.0f) 
           || (imagerCharacteristic->s_ResponseCurve.f32_Saturation_B_Lux > 105600.0f)
         )
      {
        ps_SystemInfo->errors.error[HLA_ERRORID_IMAGE_DATA].status = HLA_ERRORSTATUS_CHECK_DONE_AND_FAILED;
        ps_SystemInfo->errors.error[HLA_ERRORID_IMAGE_DATA].optData = HLA_ERRORID_OPTDATA_IMAGE_DATA_IC_RESPCURVE_SATLUX;
        ret = 0;
      }
    }

    /* check camera parameters */
    if (cameraParameter->s_ImageHeader.uiBitsPerChannel != 12)
    {
      ps_SystemInfo->errors.error[HLA_ERRORID_IMAGE_DATA].status = HLA_ERRORSTATUS_CHECK_DONE_AND_FAILED;
      ps_SystemInfo->errors.error[HLA_ERRORID_IMAGE_DATA].optData = HLA_ERRORID_OPTDATA_IMAGE_DATA_BITSPERPIXEL;
      ret = 0;
    }

    if (    (cameraParameter->f32_cycleTime < 0.059f) 
         || (cameraParameter->f32_cycleTime > 0.061f)
       )
    {
      ps_SystemInfo->errors.error[HLA_ERRORID_IMAGE_DATA].status = HLA_ERRORSTATUS_CHECK_DONE_AND_FAILED;
      ps_SystemInfo->errors.error[HLA_ERRORID_IMAGE_DATA].optData = HLA_ERRORID_OPTDATA_IMAGE_DATA_CYCLETIME;
      ret = 0;
    }

    {
      const uint32 bayerPattern = (uint32)cameraParameter->e_bayerPattern;
      const uint8 patternH = (uint8)((bayerPattern % 2) + cameraParameter->s_CroppedRoiX1.ui32_x) % 2;
      const uint8 patternV = (uint8)((bayerPattern / 2) + cameraParameter->s_CroppedRoiX1.ui32_y) % 2;

      if (    (bayerPattern != 1) 
           || (patternH != 1) 
           || (patternV != 0)
         )
      {
        ps_SystemInfo->errors.error[HLA_ERRORID_IMAGE_DATA].status = HLA_ERRORSTATUS_CHECK_DONE_AND_FAILED;
        ps_SystemInfo->errors.error[HLA_ERRORID_IMAGE_DATA].optData = HLA_ERRORID_OPTDATA_IMAGE_DATA_CROPPEDROIBAYERPATTERN;
        ret = 0;
      }
    }
    
    if (    (cameraParameter->s_FocalLength.f32_x < 100) 
         || (cameraParameter->s_FocalLength.f32_x > 2000) 
         || (cameraParameter->s_FocalLength.f32_y < 100) 
         || (cameraParameter->s_FocalLength.f32_y > 2000)
       )
    {
      ps_SystemInfo->errors.error[HLA_ERRORID_IMAGE_DATA].status = HLA_ERRORSTATUS_CHECK_DONE_AND_FAILED;
      ps_SystemInfo->errors.error[HLA_ERRORID_IMAGE_DATA].optData = HLA_ERRORID_OPTDATA_IMAGE_DATA_FOCAL_LENGTH;
      ret = 0;
    }

    if (    (cameraParameter->s_ImageSize.ui32_x > 2000) 
         || (cameraParameter->s_ImageSize.ui32_x < 200) 
         || (cameraParameter->s_ImageSize.ui32_y > 2000) 
         || (cameraParameter->s_ImageSize.ui32_y < 200)
       )
    {
      ps_SystemInfo->errors.error[HLA_ERRORID_IMAGE_DATA].status = HLA_ERRORSTATUS_CHECK_DONE_AND_FAILED;
      ps_SystemInfo->errors.error[HLA_ERRORID_IMAGE_DATA].optData = HLA_ERRORID_OPTDATA_IMAGE_DATA_IMAGE_SIZE;
      ret = 0;
    }

    if (    (cameraParameter->s_CroppedRoiSize.ui32_x > 2000) 
         || (cameraParameter->s_CroppedRoiSize.ui32_x < 200) 
         || (cameraParameter->s_CroppedRoiSize.ui32_y > 2000) 
         || (cameraParameter->s_CroppedRoiSize.ui32_y < 200)
       )
    {
      ps_SystemInfo->errors.error[HLA_ERRORID_IMAGE_DATA].status = HLA_ERRORSTATUS_CHECK_DONE_AND_FAILED;
      ps_SystemInfo->errors.error[HLA_ERRORID_IMAGE_DATA].optData = HLA_ERRORID_OPTDATA_IMAGE_DATA_CROPPEDROISIZE;
      ret = 0;
    }

    if (    (cameraParameter->s_CroppedRoiX1.ui32_x > 2000) 
         || (cameraParameter->s_CroppedRoiX1.ui32_x > 2000)
       )
    {
      ps_SystemInfo->errors.error[HLA_ERRORID_IMAGE_DATA].status = HLA_ERRORSTATUS_CHECK_DONE_AND_FAILED;
      ps_SystemInfo->errors.error[HLA_ERRORID_IMAGE_DATA].optData = HLA_ERRORID_OPTDATA_IMAGE_DATA_CROPPEDROIX1;
      ret = 0;
    }

    if (    (cameraParameter->s_LensCenter.f32_x > 2000) 
         || (cameraParameter->s_LensCenter.f32_x < 100)  
         || (cameraParameter->s_LensCenter.f32_y > 2000) 
         || (cameraParameter->s_LensCenter.f32_y < 100)
       )
    {
      ps_SystemInfo->errors.error[HLA_ERRORID_IMAGE_DATA].status = HLA_ERRORSTATUS_CHECK_DONE_AND_FAILED;
      ps_SystemInfo->errors.error[HLA_ERRORID_IMAGE_DATA].optData = HLA_ERRORID_OPTDATA_IMAGE_DATA_LENSCENTER;
      ret = 0;
    }
  }
  else
  {
    ret = 0;
  }
  return ret;
}

uint8 HLAErrorCheck_Calibration(      HLA_t_SystemInfo*      ps_SystemInfo,
                                const HLA_t_CameraParameter* pCamParam,
                                const HLACameraData_t*       pCamData,
                                const HLACamRot*             pCamRot
                               )
{
  uint8 ret = 1;

  ps_SystemInfo->errors.error[HLA_ERRORID_CALIBRATION].status = HLA_ERRORSTATUS_CHECK_DONE_AND_PASSED;

  if (    ((pCamData->RoiWidth % HLA_EVE_SEG_PROCESSED_ROI_WIDTH_ALIGNMENT) != 0)
       || ((pCamData->RoiHeight % HLA_EVE_SEG_PROCESSED_ROI_HEIGHT_ALIGNMENT) != 0)
     )
  {
    ps_SystemInfo->errors.error[HLA_ERRORID_CALIBRATION].status = HLA_ERRORSTATUS_CHECK_DONE_AND_FAILED;
    ps_SystemInfo->errors.error[HLA_ERRORID_CALIBRATION].optData = HLA_ERRORID_OPTDATA_CALIBRATION_ROI_ALIGNMENT;
    ret = 0;
  }

  {
    /* check the guaranteed specified minimum 16 deg (0.2793 rad) horizontal FOV to left and right boundary */
    const sint32 xMinFOE = (sint32)CML_s_Round2Int(pCamParam->s_FocalLength.f32_x * tanf(0.2793f));

    if (    ((pCamData->FOE_x - xMinFOE) <  (sint32)(pCamParam->s_CroppedRoiX1.ui32_x)) 
         || ((pCamData->FOE_x + xMinFOE) >= (sint32)(pCamParam->s_CroppedRoiX1.ui32_x + pCamParam->s_CroppedRoiSize.ui32_x))
       )
    {
      ps_SystemInfo->errors.error[HLA_ERRORID_CALIBRATION].status = HLA_ERRORSTATUS_CHECK_DONE_AND_FAILED;
      ps_SystemInfo->errors.error[HLA_ERRORID_CALIBRATION].optData = HLA_ERRORID_OPTDATA_CALIBRATION_ROI_LIMITED_X;
    }
  }

  if (   (pCamRot->A[0] < CML_Deg2Rad(-100.0f))
      || (pCamRot->A[0] > CML_Deg2Rad( -80.0f))
      || (pCamRot->A[1] < CML_Deg2Rad(  -3.0f))
      || (pCamRot->A[1] > CML_Deg2Rad(   3.0f))
      || (pCamRot->A[2] < CML_Deg2Rad( -95.0f))
      || (pCamRot->A[2] > CML_Deg2Rad( -85.0f))
     )
  {
    ps_SystemInfo->errors.error[HLA_ERRORID_CALIBRATION].status = HLA_ERRORSTATUS_CHECK_DONE_AND_FAILED;
    ps_SystemInfo->errors.error[HLA_ERRORID_CALIBRATION].optData = HLA_ERRORID_OPTDATA_CALIBRATION_CAM_ROT_OUT_OF_RANGE;
    ret = 0;
  }

  return ret;
}

uint8 HLAErrorCheck_Input( const HLAR_t_RequiredInputs*    pIn,
                           const HLA_t_MotionState*        pMotionState,
                           const HLA_t_Availability*       pAvailability,
                           const RTE_HLAR_BrightnessState  eBrightnessState,
                           const sint16                    dFrameCnt,
                                 HLA_t_SystemInfo*         ps_SystemInfo
                          )
{
  uint8 ret = 1;

  ps_SystemInfo->errors.error[HLA_ERRORID_INPUT].status = HLA_ERRORSTATUS_CHECK_DONE_AND_PASSED;

  /* HLA timestamp not changed or increased more than 500ms since last HLA cycle */
  if (old_TimeStamp_HLA_us != 0)
  {
    if (eBrightnessState == RTE_HLAR_BRT_NIGHT)
    {
      if (    (pIn->uiTimeStamp_HLA_us <= old_TimeStamp_HLA_us) 
           || ((pIn->uiTimeStamp_HLA_us - old_TimeStamp_HLA_us) > 500000)
         )
      {
        ps_SystemInfo->errors.error[HLA_ERRORID_INPUT].status = HLA_ERRORSTATUS_CHECK_DONE_AND_FAILED;
        ps_SystemInfo->errors.error[HLA_ERRORID_INPUT].optData = HLA_ERRORID_OPTDATA_INPUT_TIMESTAMP_HLA;
        ret = 0;
      }
    }
  }

  /* VDY timestamp not changed or increased more than 500ms since last HLA cycle */
  if (old_TimeStamp_VDY_us != 0)
  {
    if (eBrightnessState == RTE_HLAR_BRT_NIGHT)
    {
      if (    (pIn->uiTimeStamp_VDY_us <= old_TimeStamp_VDY_us) 
           || ((pIn->uiTimeStamp_VDY_us - old_TimeStamp_VDY_us) > 500000)
         )
      {
        ps_SystemInfo->errors.error[HLA_ERRORID_INPUT].status = HLA_ERRORSTATUS_CHECK_DONE_AND_FAILED;
        ps_SystemInfo->errors.error[HLA_ERRORID_INPUT].optData = HLA_ERRORID_OPTDATA_INPUT_TIMESTAMP_VDY;
        ret = 0;
      }
    }
  }

  /* Image timestamp not changed or increased more than 500ms since last HLA cycle */
  if (old_TimeStamp_Image_us != 0)
  {
    if (eBrightnessState == RTE_HLAR_BRT_NIGHT)
    {
      if (    (pIn->uiTimeStamp_Image_us <= old_TimeStamp_Image_us) 
           || ((pIn->uiTimeStamp_Image_us - old_TimeStamp_Image_us) > 500000)
         )
      {
        ps_SystemInfo->errors.error[HLA_ERRORID_INPUT].status = HLA_ERRORSTATUS_CHECK_DONE_AND_FAILED;
        ps_SystemInfo->errors.error[HLA_ERRORID_INPUT].optData = HLA_ERRORID_OPTDATA_INPUT_TIMESTAMP_IMAGE;
        ret = 0;
      }
    }
  }

  /* remember the timestamps for next HLA cycle */
  old_TimeStamp_HLA_us = pIn->uiTimeStamp_HLA_us;
  old_TimeStamp_VDY_us = pIn->uiTimeStamp_VDY_us;
  old_TimeStamp_Image_us = pIn->uiTimeStamp_Image_us;

  /* valid input speed */
  if ((pMotionState->f32_Speed < -100) ||
    (pMotionState->f32_Speed >  100))
  {
    ps_SystemInfo->errors.error[HLA_ERRORID_INPUT].status = HLA_ERRORSTATUS_CHECK_DONE_AND_FAILED;
    ps_SystemInfo->errors.error[HLA_ERRORID_INPUT].optData = HLA_ERRORID_OPTDATA_INPUT_SPEED;
    ret = 0;
  }

  /* valid input displayed speed */
  if (    (pMotionState->f32_SpeedDisplay < -100) 
       || (pMotionState->f32_SpeedDisplay >  100)
     )
  {
    ps_SystemInfo->errors.error[HLA_ERRORID_INPUT].status = HLA_ERRORSTATUS_CHECK_DONE_AND_FAILED;
    ps_SystemInfo->errors.error[HLA_ERRORID_INPUT].optData = HLA_ERRORID_OPTDATA_INPUT_SPEED_DISPLAY;
    ret = 0;
  }

  /* valid input acceleration */
  if (    (pMotionState->f32_Acceleration < -50) 
       || (pMotionState->f32_Acceleration >  50)
     )
  {
    ps_SystemInfo->errors.error[HLA_ERRORID_INPUT].status = HLA_ERRORSTATUS_CHECK_DONE_AND_FAILED;
    ps_SystemInfo->errors.error[HLA_ERRORID_INPUT].optData = HLA_ERRORID_OPTDATA_INPUT_ACCELERATION;
    ret = 0;
  }

  /* valid input yaw rate raw */
  if (    (pMotionState->f32_YawRateRaw < -6.28f) 
       || (pMotionState->f32_YawRateRaw >  6.28f)
      )
  {
    ps_SystemInfo->errors.error[HLA_ERRORID_INPUT].status = HLA_ERRORSTATUS_CHECK_DONE_AND_FAILED;
    ps_SystemInfo->errors.error[HLA_ERRORID_INPUT].optData = HLA_ERRORID_OPTDATA_INPUT_YAWRATERAW;
    ret = 0;
  }

  /* valid input yaw rate */
  if (    (pMotionState->f32_YawRate < -6.28f) 
       || (pMotionState->f32_YawRate >  6.28f)
     )
  {
    ps_SystemInfo->errors.error[HLA_ERRORID_INPUT].status = HLA_ERRORSTATUS_CHECK_DONE_AND_FAILED;
    ps_SystemInfo->errors.error[HLA_ERRORID_INPUT].optData = HLA_ERRORID_OPTDATA_INPUT_YAWRATE;
    ret = 0;
  }

  /* faulty availability state */
  if (pAvailability->e_State == RTE_HLA_STATE_FAULT)
  {
    ps_SystemInfo->errors.error[HLA_ERRORID_INPUT].status = HLA_ERRORSTATUS_CHECK_DONE_AND_FAILED;
    ps_SystemInfo->errors.error[HLA_ERRORID_INPUT].optData = HLA_ERRORID_OPTDATA_INPUT_AVAILABILITY_FAULT;
    ret = 0;
  }

  /* IC doesn't match to image */
  if ((pIn->uiFrameCnt & UI8_T_MAX) != (pIn->s_Sig.s_ImagerState.ui32_FrameNumber & UI8_T_MAX))
  {
    ps_SystemInfo->errors.error[HLA_ERRORID_INPUT].status = HLA_ERRORSTATUS_CHECK_DONE_AND_FAILED;
    ps_SystemInfo->errors.error[HLA_ERRORID_INPUT].optData = HLA_ERRORID_OPTDATA_INPUT_MISMATCH_IMAGE_IC;
    ret = 0;
  }

  /* Frame drops, dframes */
  if (dFrameCnt != HLA_NUM_EXPECTED_DFRAMES)
  {
    ps_SystemInfo->errors.error[HLA_ERRORID_INPUT].status = HLA_ERRORSTATUS_CHECK_DONE_AND_FAILED;
    ps_SystemInfo->errors.error[HLA_ERRORID_INPUT].optData = HLA_ERRORID_OPTDATA_INPUT_DFRAME;
    ret = 0;
  }

  return ret;
}

uint8 HLAErrorCheck_Fatal(      HLA_t_SystemInfo*      ps_SystemInfo,
                          const HLA_t_DefectPixelList* pDefectPixelList
                         )
{
  uint8 ret = 1;

  ps_SystemInfo->errors.error[HLA_ERRORID_FATAL].status = HLA_ERRORSTATUS_CHECK_DONE_AND_PASSED;

  if (pDefectPixelList->ui8_DefectsListLength >= RTE_HLAR_DEFECT_PIXEL_LIST_LENGTH)
  {
    ps_SystemInfo->errors.error[HLA_ERRORID_FATAL].status = HLA_ERRORSTATUS_CHECK_DONE_AND_FAILED;
    ps_SystemInfo->errors.error[HLA_ERRORID_FATAL].optData = HLA_ERRORID_OPTDATA_FATAL_HOTPIXELS_EXCEEDED;
    ret = 0;
  }

  return ret;
}

uint8 HLAErrorCheck_Segmentation( const HLASegData_t*     pSegData,
                                        HLA_t_SystemInfo* pSystemInfo
                                )
{
  uint8 ret = 1;

  pSystemInfo->errors.error[HLA_ERRORID_SEGMENTATION].status = HLA_ERRORSTATUS_CHECK_DONE_AND_PASSED;

  /* EVE returned with an error? */
  if (pSegData->EveErrorCode != 0)
  {
    pSystemInfo->errors.error[HLA_ERRORID_SEGMENTATION].status = HLA_ERRORSTATUS_CHECK_DONE_AND_FAILED;
    pSystemInfo->errors.error[HLA_ERRORID_SEGMENTATION].optData = pSegData->EveErrorCode;
    ret = 0;
  }

  return ret;
}

uint8 HLAErrorCheck_Analysis( const HLAAnalysisData_t* pAnalysisData,
                                    HLA_t_SystemInfo*  pSystemInfo
                             )
{
  uint8 ret = 1;

  pSystemInfo->errors.error[HLA_ERRORID_ANALYSIS].status = HLA_ERRORSTATUS_CHECK_DONE_AND_PASSED;

  /* EVE returned with an error? */
  if (pAnalysisData->EveErrorCode != 0)
  {
    pSystemInfo->errors.error[HLA_ERRORID_ANALYSIS].status = HLA_ERRORSTATUS_CHECK_DONE_AND_FAILED;
    pSystemInfo->errors.error[HLA_ERRORID_ANALYSIS].optData = pAnalysisData->EveErrorCode;
    ret = 0;
  }

  return ret;
}/* PRQA S 861 1 */
  
