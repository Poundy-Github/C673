/*! \file **********************************************************************

  COMPANY:                Continental, BC DAS, A.D.C. GmbH

  PROJECT:                CSF200

  CPU:                    M32R

  COMPONENT:              HLA

  MODULNAME:              hla_camera.c

  DESCRIPTION:            camera functions  

  AUTHOR:                 Stefan Heinrich

  CREATION DATE:          11.09.2007

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_camera.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:26:51CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/camera/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:38:27CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/camera/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:23CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/camera/project.pj
  CHANGE:                 Revision 1.17 2014/03/25 19:11:48CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Separation of hla_segmentation.c
  CHANGE:                 Removed QAC warnings
  CHANGE:                 Replaces fABS by CML_f_abs
  CHANGE:                 Introduced CML_s_Round2Int
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 25, 2014 7:11:49 PM CET]
  CHANGE:                 Change Package : 207432:46 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.16 2014/03/25 18:35:12CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_camera.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_camera.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/camera/project.pj.
  CHANGE:                 Revision 1.15 2014/03/21 09:39:26CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Added more Cantata tests
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 21, 2014 9:39:26 AM CET]
  CHANGE:                 Change Package : 207432:34 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.14 2014/03/19 16:30:29CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGE:                 Fixed hlar input adapter for old recordings (headlamp type)
  CHANGE:                 Clean-up of no longer needed files in simulation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 19, 2014 4:30:29 PM CET]
  CHANGE:                 Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGE:                 Revision 1.13 2014/03/04 16:51:55CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed QAC warnings
  CHANGE:                 Coding style
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 4:51:56 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.12 2014/02/07 16:33:04CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed dframe calculation
  CHANGE:                 Updated time meas inside segmentation
  CHANGE:                 Updated HIL according to latest changes
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 7, 2014 4:33:04 PM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.11 2014/02/06 16:02:51CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Refactoring of hla debug output (time meas, removed redundant stuff)
  CHANGE:                 Centralized Null pointer checks
  CHANGE:                 Refactored dframe calculation
  CHANGE:                 Revision 1.10 2014/01/10 18:33:30CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 First part of LRF on EVE (disabled)
  CHANGE:                 Merged LRF inputs into one struct
  CHANGE:                 Fixed exception handling of internal cali 
  CHANGE:                 Removed all tabs in the code and further clean-up
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:31 PM CET]
  CHANGE:                 Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.9 2014/01/05 22:52:25CET Glebov, Roman (uidg4759) 
  CHANGE:                 QAC: implicite conversion from int to unsigned int and float32 to double and vise versa removed
  CHANGE:                          added constant for minimal allowed float value of dFrameHLA
  CHANGE:                 --- Added comments ---  uidg4759 [Jan 5, 2014 10:52:25 PM CET]
  CHANGE:                 Change Package : 193435:2 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGE:                 Revision 1.8 2013/11/21 17:54:02CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Merge from NEW_SEG branch
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 5:54:03 PM CET]
  CHANGE:                 Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.7.1.3 2013/10/29 18:21:21CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Time meas fixes
  CHANGE:                 New roi calculation (alignment to eve)
  CHANGE:                 Call EVE in segmentation now
  CHANGE:                 --- Added comments ---  uidv7867 [Oct 29, 2013 6:21:21 PM CET]
  CHANGE:                 Change Package : 201787:2 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGE:                 Revision 1.7.1.2 2013/10/24 10:44:16CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed some not needed variables
  CHANGE:                 Made HLA working on evalboard
  CHANGE:                 --- Added comments ---  uidv7867 [Oct 24, 2013 10:44:16 AM CEST]
  CHANGE:                 Change Package : 201787:2 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGE:                 Revision 1.7.1.1 2013/10/18 13:27:34CEST Brunn, Marcus (brunnm) 
  CHANGE:                 intial version of new segmentation
  CHANGE:                 --- Added comments ---  brunnm [Oct 18, 2013 1:27:34 PM CEST]
  CHANGE:                 Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGE:                 Revision 1.7 2013/08/30 14:15:04CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fix: ROIX1 calc wrong for ECU
  CHANGE:                 --- Added comments ---  uidv7867 [Aug 30, 2013 2:15:04 PM CEST]
  CHANGE:                 Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.6 2013/08/27 17:13:32CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed icon extraction
  CHANGE:                 --- Added comments ---  uidv7867 [Aug 27, 2013 5:13:32 PM CEST]
  CHANGE:                 Change Package : 195030:1 http://mks-psad:7002/im/viewissue?selection=195030
  CHANGE:                 Revision 1.5 2013/08/27 11:03:14CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed ROI calculation in simulation
  CHANGE:                 --- Added comments ---  uidv7867 [Aug 27, 2013 11:03:15 AM CEST]
  CHANGE:                 Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.4 2013/08/24 15:01:06CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Further eve optimiztations:
  CHANGE:                 - Run interpreter in parallel to edma/vcop
  CHANGE:                 - Get rid of interpreter prologue
  CHANGE:                 - Return vcop init errors
  CHANGE:                 - ROI size at most cROI size + 2 pixels
  CHANGE:                 --- Added comments ---  uidv7867 [Aug 24, 2013 3:01:06 PM CEST]
  CHANGE:                 Change Package : 192116:3 http://mks-psad:7002/im/viewissue?selection=192116
  CHANGE:                 Revision 1.3 2013/08/21 18:21:01CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Improved sorting on EVE quite a lot
  CHANGE:                 --- Added comments ---  uidv7867 [Aug 21, 2013 6:21:02 PM CEST]
  CHANGE:                 Change Package : 192116:3 http://mks-psad:7002/im/viewissue?selection=192116
  CHANGE:                 Revision 1.2 2013/08/15 14:23:05CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Improved EDMA handling on EVE side
  CHANGE:                 --- Added comments ---  uidv7867 [Aug 15, 2013 2:23:05 PM CEST]
  CHANGE:                 Change Package : 192116:1 http://mks-psad:7002/im/viewissue?selection=192116
  CHANGE:                 Revision 1.1 2013/08/05 17:01:54CEST Manz, Alexander (uidv8777) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
  CHANGE:                 Revision 1.68.1.65 2013/07/26 17:04:09CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Added first part of EVE implementation
  CHANGE:                 --- Added comments ---  uidv7867 [Jul 26, 2013 5:04:10 PM CEST]
  CHANGE:                 Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.68.1.64 2013/03/13 17:09:13CET Brunn, Marcus (brunnm) 
  CHANGE:                 added HLA parameter to HLAR/F input interface
  CHANGE:                 --- Added comments ---  brunnm [Mar 13, 2013 5:09:14 PM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.68.1.63 2013/03/04 11:14:48CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Integrated cam_rot into HLA
  CHANGE:                 bug fix in jacobian calculation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2013 11:14:49 AM CET]
  CHANGE:                 Change Package : 167173:26 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.68.1.62 2013/02/22 16:21:54CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Added system info errors for roi calculation in x direction
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 22, 2013 4:21:54 PM CET]
  CHANGE:                 Change Package : 167173:25 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.68.1.61 2013/02/22 09:09:25CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Exchanged modulo count magic number by macro
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 22, 2013 9:09:25 AM CET]
  CHANGE:                 Change Package : 167173:25 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.68.1.60 2013/02/15 16:54:40CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Bug fix: minHeight was missing
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 15, 2013 4:54:40 PM CET]
  CHANGE:                 Change Package : 167173:22 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.68.1.59 2013/02/11 08:55:40CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Updated visulalization for new ROI error categorie
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 11, 2013 8:55:41 AM CET]
  CHANGE:                 Change Package : 167173:24 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.68.1.58 2013/02/05 11:41:01CET Zechner, Stefan (uidt9253) 
  CHANGE:                 - fix misra warnings
  CHANGE:                 --- Added comments ---  uidt9253 [Feb 5, 2013 11:41:01 AM CET]
  CHANGE:                 Change Package : 166950:1 http://mks-psad:7002/im/viewissue?selection=166950
  CHANGE:                 Revision 1.68.1.57 2013/02/04 17:55:21CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Introduced error categorie for ROI
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 4, 2013 5:55:21 PM CET]
  CHANGE:                 Change Package : 167173:24 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.68.1.56 2013/02/04 13:02:19CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Added function pointer casting
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 4, 2013 1:02:19 PM CET]
  CHANGE:                 Change Package : 167173:24 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.68.1.55 2013/01/23 16:39:54CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Converted enum to rte like type for
  CHANGE:                 - HLA_t_eHeadLightMode
  CHANGE:                 - HLA_t_eSpotLight
  CHANGE:                 - HLA_t_eWindshieldType
  CHANGE:                 - HLA_t_eDefectPixelType
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 23, 2013 4:39:54 PM CET]
  CHANGE:                 Change Package : 167173:22 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.68.1.54 2013/01/23 14:31:53CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Updated header file dependency to algo_service_types.h
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 23, 2013 2:31:54 PM CET]
  CHANGE:                 Change Package : 167173:22 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.68.1.53 2013/01/22 12:15:23CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace 0.0001f by #define from glob_def.sh
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 22, 2013 12:15:23 PM CET]
  CHANGE:                 Change Package : 167173:23 http://mks-psad:7002/im/viewissue?selection=167173
**************************************************************************** */

/* includes */
#include "hla_type.h"
#include "hla_cam_rot.h"
#include "hla_camera.h"
#include "hla_analysis.h"
#include "hla_eve_ext.h"
#include <math.h>
#include <string.h>

/*****************************************************************************
  CONSTANTS
*****************************************************************************/
/* Constant for minimum allowed dFrameHLACycle abs value so that the division of 1 with it does not overflow max float which is approx. 3.4e38 */
static const float32 f_MinAllowedDFrameHLACycle = 3.4e-38f;


/* macros */
#if((HLA_EVE_SEG_PROCESSED_MAX_ROI_WIDTH % HLA_EVE_SEG_PROCESSED_ROI_WIDTH_ALIGNMENT) != 0u)
  #error HLA_EVE_SEG_PROCESSED_MAX_ROI_WIDTH % HLA_EVE_SEG_PROCESSED_ROI_WIDTH_ALIGNMENT isn't null. Please update corresponding data in hla_eve_ext.h acccordingly and update this check.
#endif
#if((HLA_EVE_SEG_PROCESSED_MAX_ROI_HEIGHT % HLA_EVE_SEG_PROCESSED_ROI_HEIGHT_ALIGNMENT) != 0u)
  #error HLA_EVE_SEG_PROCESSED_MAX_ROI_HEIGHT % HLA_EVE_SEG_PROCESSED_ROI_HEIGHT_ALIGNMENT isn't null. Please update corresponding data in hla_eve_ext.h acccordingly and update this check.
#endif

/* local functions */



/* **************************************************************************** 
  Functionname:     HLAInitCameraGlobals()                           */ /*!  
  Description:      Initializes all global variables of the HLA Camera. 
                    This enables the simulation framework to re-init the HLA 
                    algo without reloading the DLL.
                    
  @param[in]        -

  @return           - 
  @pre              -
  @post             -
  @author           Reik Müller
**************************************************************************** */ 
void HLAInitCamera(                      
                   HLACameraData_t               *pCamData,
                   HLACamRot                     *pCamRot
                   )
{  
  (void)memset((void*)pCamRot, 0, sizeof(HLACamRot));
  (void)memset((void*)pCamData, 0, sizeof(HLACameraData_t));
}


/* **************************************************************************** 
  Functionname:     void HLAUpdateCamera(const HLAR_t_RequiredInputs *ps_In)                           */ /*!  
  Description:      

  @param[in,out]    void

  @return           0 if error, else success 
  @pre              -
  @post             Stefan Heinrich
**************************************************************************** */
void HLAUpdateCamera( const HLAR_t_RequiredInputs*   pReqIn,
                      const HLATracking3DDataCali_t* pDataCali,
                      const boolean                  forceCameraUpdate,
                      const sint16                   dFrameCnt,
                            HLACameraData_t*         pCamData,
                            HLACamRot*               pCamRot
                    )
{
  boolean cameraUpdateNeeded = FALSE;
  
  if(forceCameraUpdate == TRUE)
  {
    cameraUpdateNeeded = TRUE;
  }
  else
  {
    /*******************************/
    /* check if camera has changed */

    /* camera update only if angles, position, focal length or lens center have changed */
    /* testing for equality is exactly what we want                                     */                                  
    cameraUpdateNeeded |= ((pReqIn->s_Par.s_CameraParameter.s_FocalLength.f32_x > pCamRot->FX) ? 1: 0);
    cameraUpdateNeeded |= ((pReqIn->s_Par.s_CameraParameter.s_FocalLength.f32_x < pCamRot->FX) ? 1: 0);

    cameraUpdateNeeded |= ((pReqIn->s_Par.s_CameraParameter.s_FocalLength.f32_y > pCamRot->FY)? 1: 0);
    cameraUpdateNeeded |= ((pReqIn->s_Par.s_CameraParameter.s_FocalLength.f32_y < pCamRot->FY)? 1: 0);

    cameraUpdateNeeded |= ((pReqIn->s_Par.s_CameraParameter.s_LensCenter.f32_x  > pCamRot->XO)? 1: 0);
    cameraUpdateNeeded |= ((pReqIn->s_Par.s_CameraParameter.s_LensCenter.f32_x  < pCamRot->XO)? 1: 0);

    cameraUpdateNeeded |= ((pReqIn->s_Par.s_CameraParameter.s_LensCenter.f32_y  > pCamRot->YO)? 1: 0);
    cameraUpdateNeeded |= ((pReqIn->s_Par.s_CameraParameter.s_LensCenter.f32_y  < pCamRot->YO)? 1: 0);
    
    cameraUpdateNeeded |= ((pReqIn->s_Par.s_SensorSocket.f32_X > pCamRot->T[0])? 1: 0);
    cameraUpdateNeeded |= ((pReqIn->s_Par.s_SensorSocket.f32_X < pCamRot->T[0])? 1: 0);

    cameraUpdateNeeded |= ((pReqIn->s_Par.s_SensorSocket.f32_Y > pCamRot->T[1])? 1: 0);
    cameraUpdateNeeded |= ((pReqIn->s_Par.s_SensorSocket.f32_Y < pCamRot->T[1])? 1: 0);

    cameraUpdateNeeded |= ((pReqIn->s_Par.s_SensorSocket.f32_Z > pCamRot->T[2])? 1: 0);
    cameraUpdateNeeded |= ((pReqIn->s_Par.s_SensorSocket.f32_Z < pCamRot->T[2])? 1: 0);
    
    cameraUpdateNeeded |= ((pDataCali->cal_pitch > pCamRot->A[0])? 1: 0);
    cameraUpdateNeeded |= ((pDataCali->cal_pitch < pCamRot->A[0])? 1: 0);
    
    cameraUpdateNeeded |= ((pDataCali->cal_roll > pCamRot->A[1])? 1: 0);
    cameraUpdateNeeded |= ((pDataCali->cal_roll < pCamRot->A[1])? 1: 0);

    cameraUpdateNeeded |= ((pDataCali->cal_yaw > pCamRot->A[2])? 1: 0);
    cameraUpdateNeeded |= ((pDataCali->cal_yaw < pCamRot->A[2])? 1: 0);
  }    

  /****************************/
  /* proceed if update needed */

  if(cameraUpdateNeeded == TRUE)
  {
    /*******************************/
    /* initialize camera parameter */
  
    HLACamRotSetFxFyXoYo ( pCamRot, 
                           pReqIn->s_Par.s_CameraParameter.s_FocalLength.f32_x,
                           pReqIn->s_Par.s_CameraParameter.s_FocalLength.f32_y, 
                           pReqIn->s_Par.s_CameraParameter.s_LensCenter.f32_x,
                           pReqIn->s_Par.s_CameraParameter.s_LensCenter.f32_y 
                          );
    /* camera position in respect of world coordinate system */
    HLACamRotSetT ( pCamRot, 
                    pReqIn->s_Par.s_SensorSocket.f32_X,
                    pReqIn->s_Par.s_SensorSocket.f32_Y,
                    pReqIn->s_Par.s_SensorSocket.f32_Z
                   );
    /* camera rotational angles */
    HLACamRotSetRot( pCamRot, 
                     pDataCali->cal_pitch,
                     pDataCali->cal_roll,
                     pDataCali->cal_yaw
                    );

    /* set FOE */
    /* ~CodeReview ~ID:c76c0c53ecb99f48ceed962bea6f25a7 ~Reviewer:CW01\muellerr5 ~Date:17.07.2012 ~Priority:3 ~Comment:magic numbers */
    pCamData->FOE_x = (uint16) HLACamRotGetxb(pCamRot, 9999.9f, 0.0f, 0.0f); /* roi center x-position. */
    pCamData->FOE_y = (uint16) HLACamRotGetyb(pCamRot, 9999.9f, 0.0f, 0.0f); /* roi center y-position. */
    /* set upper Roi border (function Roi): no vehicle above this line */
    pCamData->RoiYu  = pCamData->FOE_y;
    pCamData->RoiYu -= (uint16)CML_u_Round2Uint(pReqIn->s_Par.s_CameraParameter.s_FocalLength.f32_y * tanf(pReqIn->s_Par.s_HlarPar.Roi.FOV_FunctionRoiAboveHorizon));

    /* update new cam data flag */
    pCamData->newCamData = 1;
  }

  /* update delta time and distance since last processed image */
  pCamData->dtime_s    = 0.5f * abs(dFrameCnt) * pReqIn->s_Par.s_CameraParameter.f32_cycleTime;
  pCamData->ddist_m    = pCamData->dtime_s * pReqIn->s_Sig.s_MotionState.f32_Speed;
  if(pReqIn->s_Sig.s_MotionState.e_MoveState == HLA_MOVE_STATE_FWD)
  {
    pCamData->dtimeFwd_s = pCamData->dtime_s;
    pCamData->ddistFwd_m = pCamData->ddist_m;
  }
  else
  {
    pCamData->dtimeFwd_s = 0.0f;
    pCamData->ddistFwd_m = 0.0f;
  }
   
  /* update delta frame */
  pCamData->dFrameHLACycle = 0.5f * abs(dFrameCnt);
  /* even if the pCamData->dFrameHLACycle is very small but still not 0, the division of 1 with it could overflow float */
  if ( fabsf(pCamData->dFrameHLACycle ) >= f_MinAllowedDFrameHLACycle )
  {
    pCamData->dFrameHLACycle_inv = 1.0f/pCamData->dFrameHLACycle;
  }
  else
  {
    pCamData->dFrameHLACycle_inv = 0.0f;
  }

  /* compute radius of curve */
  if(fabs(pReqIn->s_Sig.s_MotionState.f32_YawRate) > CML_f_Delta)
  {
    pCamData->radius_m = pReqIn->s_Sig.s_MotionState.f32_Speed/ pReqIn->s_Sig.s_MotionState.f32_YawRate;
  }
  else
  {
    /* ~CodeReview ~ID:c0dac8af6b22b0befa2a817f28a235ad ~Reviewer:CW01\muellerr5 ~Date:17.07.2012 ~Priority:3 ~Comment:magic number */
    pCamData->radius_m = 100000.0f;
  }
  pCamData->radiusAbs_m = CML_f_Abs(pCamData->radius_m);
}


/* **************************************************************************** 
  Functionname:     HLARUpdateRoi                                        */ /*!  
  Description:      Updates the ROI

  @param[in]        HLAR_t_RequiredInputs  *pHlarReqIn   required input for HLAR
  @param[in,out]    HLARHistory_t         *pHlarHist    history data for HLAR
  @param[out]       HLARProvidedOutputs_t *pHlarProOut  provided output from HLAR

  @return           -
  @pre              -
  @post             -
  @author           Carlos Almeida
**************************************************************************** */
void HLARUpdateRoi( const HLAR_t_RequiredInputs *ps_In,
                    HLACameraData_t             *pCamData,
                    const HLACamRot             *pCamRot,
                    HLA_t_SystemInfo            *ps_SystemInfo
                  )
{
  float32 yb;                      /* bottom of HLA ROI */
  float32 yt;                      /* top of HLA ROI */
  sint32  X1, X2, Y1, Y2;          /* ROI coordinates */
  sint32  xRoiWidth;              /* Roi width */
  float32 yRoiMinAboveHorizon;    /* y position above horizon at most */
  float32 yRoiMinBelowHorizon;    /* y position below horizon at most */
  uint8   alignmentOffset;        /* number of pixels above alignment */
  sint32  Y2MaxCRoi, Y2MaxRoi;    /* Maximum for Y2 from cRoi and max Roi pointer of view, respectively */
  sint32  X2MaxCRoi, X2MaxRoi;    /* Maximum for X2 from cRoi and max Roi pointer of view, respectively */
  sint32  cRoiX1, cRoiY1;         /* local variables containing start of ROI */
  sint32  cRoiWidth, cRoiHeight;  /* local variables containing size of ROI */
  
  /****************************/
  /* proceed if update needed */
  if(pCamData->newCamData == 1)
  {
    cRoiX1 = (sint32) ps_In->s_Par.s_CameraParameter.s_CroppedRoiX1.ui32_x;
    cRoiY1 = (sint32) ps_In->s_Par.s_CameraParameter.s_CroppedRoiX1.ui32_y;
    cRoiWidth = (sint32) ps_In->s_Par.s_CameraParameter.s_CroppedRoiSize.ui32_x;
    cRoiHeight = (sint32) ps_In->s_Par.s_CameraParameter.s_CroppedRoiSize.ui32_y;

    /**************************************/
    /* compute ROI coordinates            */
    /* all in absolute imager coordinates */
    /**************************************/

    /* ROI HEIGHT */
    /* compute minimum field of view above/ below the horizon */
    yRoiMinAboveHorizon = (pCamData->FOE_y - (ps_In->s_Par.s_CameraParameter.s_FocalLength.f32_y * tanf(ps_In->s_Par.s_HlarPar.Roi.FOV_MinAboveHorizon)));
    yRoiMinBelowHorizon = (pCamData->FOE_y + (ps_In->s_Par.s_CameraParameter.s_FocalLength.f32_y * tanf(ps_In->s_Par.s_HlarPar.Roi.FOV_MinBelowHorizon)));

    /* TOP OF ROI */
    yt = HLACamRotGetyb(pCamRot, ps_In->s_Par.s_HlarPar.Roi.StreetLamp_Distance, 0.0f, ps_In->s_Par.s_HlarPar.Roi.StreetLamp_Height); /* roi bottom in front of camera */
    /* check against requested minimum */
    yt = CML_f_Min(yt, yRoiMinAboveHorizon);
    /* error check on top boundary */
    if (yt < (cRoiY1 - HLA_SEG_ERR_THRESHOLD_ROI_OUTSIDE_CROI_Y))
    {
      ps_SystemInfo->errors.error[HLA_ERRORID_CALIBRATION].status = HLA_ERRORSTATUS_CHECK_DONE_AND_FAILED;
      ps_SystemInfo->errors.error[HLA_ERRORID_CALIBRATION].optData = HLA_ERRORID_OPTDATA_CALIBRATION_ROI_LIMITED_Y;
    }
    Y1 = CML_s_Round2Int(yt);
    Y1 = CML_Max(Y1, cRoiY1);
    /* set first row to red pixel row */
    Y1 = ((Y1 - (Y1%2)) + (sint32) ((uint32)ps_In->s_Par.s_CameraParameter.e_bayerPattern / 2u));

    /* BOTTOM OF ROI */
    yb = HLACamRotGetyb(pCamRot, ps_In->s_Par.s_HlarPar.Roi.PrecVehLight_minDistance, 0.0f, ps_In->s_Par.s_HlarPar.Roi.PrecVehLight_minHeight); /* roi bottom in front of camera */
    /* check against requested minimum */
    yb = CML_f_Max(yb, yRoiMinBelowHorizon);
    /* error check on bottom boundary */
    if (yb >= (cRoiY1 + cRoiHeight + HLA_SEG_ERR_THRESHOLD_ROI_OUTSIDE_CROI_Y))
    {
      ps_SystemInfo->errors.error[HLA_ERRORID_CALIBRATION].status = HLA_ERRORSTATUS_CHECK_DONE_AND_FAILED;
      ps_SystemInfo->errors.error[HLA_ERRORID_CALIBRATION].optData = HLA_ERRORID_OPTDATA_CALIBRATION_ROI_LIMITED_Y;
    }
    Y2 = CML_s_Round2Int(yb);
    /* Check bottom boundary against cROI and maximum supported roi height */
    Y2MaxCRoi = (cRoiY1 + cRoiHeight) - 1;
    Y2MaxRoi = (Y1 + (sint32) HLA_EVE_SEG_PROCESSED_MAX_ROI_HEIGHT) - 1;
    Y2 = CML_Min(Y2, CML_Min(Y2MaxCRoi, Y2MaxRoi));
    
    /* Do alignment of Y2 */
    alignmentOffset = (uint8) ( ( ( Y2 - Y1 ) + 1 ) % (sint32) HLA_EVE_SEG_PROCESSED_ROI_HEIGHT_ALIGNMENT);
    if( alignmentOffset != 0u )
    {
      Y2 += (sint32) ( HLA_EVE_SEG_PROCESSED_ROI_HEIGHT_ALIGNMENT - alignmentOffset);
    }
    /* Check bottom boundary again against cROI */
    /* Check for maximum supported roi height (Y2 > Y2MaxRoi) isn't needed. */
    /* If Y2 > Y2MaxRoi Y2 will automatic be aligned to Y1, else Compilerwarning */
    if ( Y2 > Y2MaxCRoi )
    {
      /* In this case we are above our limits and need reduce Y2 */
      Y2 -= (sint32) HLA_EVE_SEG_PROCESSED_ROI_HEIGHT_ALIGNMENT;
    }

    /* ROI WIDTH */
    /* compute requested roi width in pixel */
    xRoiWidth = CML_s_Round2Int((2.0f * ps_In->s_Par.s_CameraParameter.s_FocalLength.f32_x) * tanf(ps_In->s_Par.s_HlarPar.Roi.FOV_Horizontal / 2.0f));
    /* xRoiWidth = multiple of 16 pixels as 8 pixels can be processed in parallel on eve + binning */
    
    alignmentOffset = (uint8) ( xRoiWidth % (sint32) HLA_EVE_SEG_PROCESSED_ROI_WIDTH_ALIGNMENT );
    if( alignmentOffset != 0u)
    {
      /* Cannot be bigger than HLA_EVE_SEG_PROCESSED_MAX_IMG_WIDTH */
      xRoiWidth += (sint32) (HLA_EVE_SEG_PROCESSED_ROI_WIDTH_ALIGNMENT - alignmentOffset);
    }

    /* LEFT BORDER OF ROI */
    X1 = (sint32)(pCamData->FOE_x - (xRoiWidth / 2));
    if (X1 < (cRoiX1 - HLA_SEG_ERR_THRESHOLD_ROI_OUTSIDE_CROI_X))
    {
      ps_SystemInfo->errors.error[HLA_ERRORID_CALIBRATION].status = HLA_ERRORSTATUS_CHECK_DONE_AND_FAILED;
      ps_SystemInfo->errors.error[HLA_ERRORID_CALIBRATION].optData = HLA_ERRORID_OPTDATA_CALIBRATION_ROI_LIMITED_X;
    }
    /* Check against right border of cRoi */
    X1 = CML_Min(X1, ((cRoiX1 + cRoiWidth) - 1) - xRoiWidth);
    /* Check against left border of cRoi */
    X1 = CML_Max(X1, cRoiX1);

    /* RIGHT BORDER OF ROI */
    X2 = (X1 + xRoiWidth) - 1;
    if (X2 > (cRoiX1 + cRoiWidth + HLA_SEG_ERR_THRESHOLD_ROI_OUTSIDE_CROI_X))
    {
      ps_SystemInfo->errors.error[HLA_ERRORID_CALIBRATION].status = HLA_ERRORSTATUS_CHECK_DONE_AND_FAILED;
      ps_SystemInfo->errors.error[HLA_ERRORID_CALIBRATION].optData = HLA_ERRORID_OPTDATA_CALIBRATION_ROI_LIMITED_X;
    }
    /* Check right boundary against cROI and maximum supported roi width */
    X2MaxCRoi = (cRoiX1 + cRoiWidth) - 1;
    X2MaxRoi = (X1 + (sint32) HLA_EVE_SEG_PROCESSED_MAX_ROI_WIDTH) - 1;
    X2 = CML_Min(X2, CML_Min(X2MaxCRoi, X2MaxRoi));
    /* Do alignment of X2 */
    alignmentOffset = (uint8) ( ( ( X2 - X1 ) + 1) % (sint32) HLA_EVE_SEG_PROCESSED_ROI_WIDTH_ALIGNMENT );
    if( alignmentOffset != 0u )
    {
      X2 += (sint32) (HLA_EVE_SEG_PROCESSED_ROI_WIDTH_ALIGNMENT - alignmentOffset);
    }
    /* Check right boundary again against cROI */
    /* Check for maximum supported roi width (X2 > X2MaxRoi) isn't needed. */
    /* If X2 > X2MaxRoi X2 will automatic be aligned to X1, else Compilerwarning */
    if ( X2 > X2MaxCRoi )
    {
      /* In this case we are above our limits and need to reduce X2 */
      X2 -= (sint32) HLA_EVE_SEG_PROCESSED_ROI_WIDTH_ALIGNMENT;
    }

    /* Update global structure with ROI data */
    pCamData->RoiX1    = (uint16)X1;
    pCamData->RoiX2    = (uint16)X2;
    pCamData->RoiY1    = (uint16)Y1;
    pCamData->RoiY2    = (uint16)Y2;
    pCamData->RoiWidth = ((uint16)X2 - (uint16)X1) + 1u;
    pCamData->RoiHeight= ((uint16)Y2 - (uint16)Y1) + 1u;
  }
}
