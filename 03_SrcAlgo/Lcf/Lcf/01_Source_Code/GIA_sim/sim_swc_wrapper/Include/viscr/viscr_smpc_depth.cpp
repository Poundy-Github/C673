/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      SAC - Stereo Auto Calibration

  MODULNAME:      viscr_smpc_depth.cpp  

  DESCRIPTION:    Delta camera yaw computation based on radar distance

  AUTHOR:         L. GARCIA

  CREATION DATE:  23.05.2011

  VERSION:        $Revision: 1.1 $

  CHANGES:        $Log: viscr_smpc_depth.cpp  $
  CHANGES:        Revision 1.1 2021/12/13 17:28:36CET Wang, David (Wangd3) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.0 2017/03/03 10:40:31CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.33 2013/11/27 11:25:29CET Mueller, Reik (muellerr5) 
  CHANGES:        - added blend_yaw_angle_with_tempmodel()
  CHANGES:        - Added comments -  muellerr5 [Nov 27, 2013 11:25:30 AM CET]
  CHANGES:        Change Package : 207519:1 http://mks-psad:7002/im/viewissue?selection=207519
  CHANGES:        Revision 1.32 2012/07/24 08:57:18CEST Behrens, Alexander (uidv2823) 
  CHANGES:        merged coverage tags and misra comments from branch to trunk
  CHANGES:        --- Added comments ---  uidv2823 [Jul 24, 2012 8:57:18 AM CEST]
  CHANGES:        Change Package : 134029:1 http://mks-psad:7002/im/viewissue?selection=134029
  CHANGES:        Revision 1.31 2012/07/13 16:44:45CEST Garcia, Lucien (uid26778) 
  CHANGES:        Check if RectError is equal to 0
  CHANGES:        --- Added comments ---  uid26778 [Jul 13, 2012 4:44:45 PM CEST]
  CHANGES:        Change Package : 138358:1 http://mks-psad:7002/im/viewissue?selection=138358
  CHANGES:        Revision 1.30 2012/07/13 10:15:08CEST Behrens, Alexander (uidv2823) 
  CHANGES:        add coverage tag
  CHANGES:        --- Added comments ---  uidv2823 [Jul 13, 2012 10:15:08 AM CEST]
  CHANGES:        Change Package : 134029:1 http://mks-psad:7002/im/viewissue?selection=134029
  CHANGES:        Revision 1.29 2012/07/05 13:45:50CEST Behrens Alexander (uidv2823) (uidv2823) 
  CHANGES:        add code coverage tags
  CHANGES:        --- Added comments ---  uidv2823 [Jul 5, 2012 1:45:51 PM CEST]
  CHANGES:        Change Package : 134029:1 http://mks-psad:7002/im/viewissue?selection=134029
  CHANGES:        Revision 1.28 2012/07/05 08:38:15CEST Behrens Alexander (uidv2823) (uidv2823) 
  CHANGES:        add code coverage tags (always false/true cases)
  CHANGES:        --- Added comments ---  uidv2823 [Jul 5, 2012 8:38:15 AM CEST]
  CHANGES:        Change Package : 134029:1 http://mks-psad:7002/im/viewissue?selection=134029
  CHANGES:        Revision 1.27 2012/07/04 11:00:09CEST Behrens Alexander (uidv2823) (uidv2823) 
  CHANGES:        update code coverage tags
  CHANGES:        --- Added comments ---  uidv2823 [Jul 4, 2012 11:00:09 AM CEST]
  CHANGES:        Change Package : 134029:1 http://mks-psad:7002/im/viewissue?selection=134029
  CHANGES:        Revision 1.26 2012/07/03 17:33:36CEST Behrens Alexander (uidv2823) (uidv2823) 
  CHANGES:        add code coverage tags
  CHANGES:        Revision 1.25 2012/07/02 13:45:58CEST Malot-EXT, Frederic (uidv0048) 
  CHANGES:        Modify priority of some findings from code review
  CHANGES:        --- Added comments ---  uidv0048 [Jul 2, 2012 1:45:59 PM CEST]
  CHANGES:        Change Package : 130129:1 http://mks-psad:7002/im/viewissue?selection=130129
  CHANGES:        Revision 1.24 2012/06/29 18:18:41CEST Malot-EXT, Frederic (uidv0048) 
  CHANGES:        Add findings from code review
  CHANGES:        --- Added comments ---  uidv0048 [Jun 29, 2012 6:18:41 PM CEST]
  CHANGES:        Change Package : 130129:1 http://mks-psad:7002/im/viewissue?selection=130129
  CHANGES:        Revision 1.23 2012/03/07 16:14:12CET Stache, Nicolaj (uidt6711) 
  CHANGES:        bug resolved
  CHANGES:        --- Added comments ---  uidt6711 [Mar 7, 2012 4:14:12 PM CET]
  CHANGES:        Change Package : 102359:1 http://mks-psad:7002/im/viewissue?selection=102359
  CHANGES:        Revision 1.22 2012/03/07 14:56:28CET Konarski-EXT, Witek (uidt8403) 
  CHANGES:        Removed PC-Lint/Misra errors.
  CHANGES:        --- Added comments ---  uidt8403 [Mar 7, 2012 2:56:29 PM CET]
  CHANGES:        Change Package : 101150:4 http://mks-psad:7002/im/viewissue?selection=101150
  CHANGES:        Revision 1.21 2012/03/02 11:10:45CET Garcia, Lucien (uid26778) 
  CHANGES:        Remove unused code
  CHANGES:        --- Added comments ---  uid26778 [Mar 2, 2012 11:10:45 AM CET]
  CHANGES:        Change Package : 80273:2 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.20 2011/12/15 09:20:50CET Spruck, Jochen (spruckj) 
  CHANGES:        Check not only the stereo dist range (20-60m), the radar distance should also be checked for dist range (20-60m)
  CHANGES:        --- Added comments ---  spruckj [Dec 15, 2011 9:20:50 AM CET]
  CHANGES:        Change Package : 91917:1 http://mks-psad:7002/im/viewissue?selection=91917
  CHANGES:        Revision 1.19 2011/11/16 12:41:14CET Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        Change distance fusi threshold from 4 m to 40 to disable this check
  CHANGES:        --- Added comments ---  spruckj [Nov 16, 2011 12:41:15 PM CET]
  CHANGES:        Change Package : 87958:1 http://mks-psad:7002/im/viewissue?selection=87958
  CHANGES:        Revision 1.18 2011/11/14 16:07:51CET Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        Init the not learnd buffer entries of yaw angle object median buffer with the yaw angle of the temp model
  CHANGES:        --- Added comments ---  spruckj [Nov 14, 2011 4:07:51 PM CET]
  CHANGES:        Change Package : 87958:1 http://mks-psad:7002/im/viewissue?selection=87958
  CHANGES:        Revision 1.17 2011/11/12 17:54:58CET Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        Yaw angle in Temp model should be updated if the object id changed
  CHANGES:        --- Added comments ---  spruckj [Nov 12, 2011 5:54:58 PM CET]
  CHANGES:        Change Package : 87855:1 http://mks-psad:7002/im/viewissue?selection=87855
  CHANGES:        Revision 1.16 2011/11/09 18:12:43CET Stache Nicolaj (uidt6711) (uidt6711) 
  CHANGES:        Bugfix-Papenburg
  CHANGES:        --- Added comments ---  uidt6711 [Nov 9, 2011 6:12:43 PM CET]
  CHANGES:        Change Package : 87467:1 http://mks-psad:7002/im/viewissue?selection=87467
  CHANGES:        Revision 1.15 2011/10/24 17:40:37CEST Stache Nicolaj (uidt6711) (uidt6711) 
  CHANGES:        Bugfix: Yaw angle delta now added to yaw angle
  CHANGES:        --- Added comments ---  uidt6711 [Oct 24, 2011 5:40:37 PM CEST]
  CHANGES:        Change Package : 67326:1 http://mks-psad:7002/im/viewissue?selection=67326
  CHANGES:        Revision 1.14 2011/10/20 19:57:53CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        Radar yaw angle does not converge bug fix
  CHANGES:        --- Added comments ---  spruckj [Oct 20, 2011 7:57:54 PM CEST]
  CHANGES:        Change Package : 64567:4 http://mks-psad:7002/im/viewissue?selection=64567
  CHANGES:        Revision 1.13 2011/10/17 15:37:52CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        Add additional ReInit buffer function
  CHANGES:        --- Added comments ---  spruckj [Oct 17, 2011 3:37:52 PM CEST]
  CHANGES:        Change Package : 84444:1 http://mks-psad:7002/im/viewissue?selection=84444
  CHANGES:        Revision 1.12 2011/10/13 17:34:05CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        Take the x mounting pos into account
  CHANGES:        --- Added comments ---  spruckj [Oct 13, 2011 5:34:05 PM CEST]
  CHANGES:        Change Package : 79036:2 http://mks-psad:7002/im/viewissue?selection=79036
  CHANGES:        Revision 1.11 2011/10/11 15:39:38CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        - Change enable radar yaw calib conition, if radar obj is valid for x cylces use the radar based calib
  CHANGES:        - Put all quality infos to internal data struct
  CHANGES:        - Add get quality interface
  CHANGES:        - Add the raw yaw angle to internal date struct
  CHANGES:        Revision 1.10 2011/10/10 16:41:29CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        Quality estimation update
  CHANGES:        --- Added comments ---  spruckj [Oct 10, 2011 4:41:29 PM CEST]
  CHANGES:        Change Package : 79036:2 http://mks-psad:7002/im/viewissue?selection=79036
  CHANGES:        Revision 1.9 2011/10/06 16:41:25CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        Add
  CHANGES:        - Error if distance between radar and stereo dist is to high
  CHANGES:        - Activate the radar bases yaw angle calibration only if the rectification error is low
  CHANGES:        - Use the radar based yaw anlge output only if a radar object was pressent for a time of 1 minute
  CHANGES:        Revision 1.8 2011/09/29 15:18:05CEST Stache Nicolaj (uidt6711) (uidt6711) 
  CHANGES:        Integrate Radar-based Yaw-Calibration
  CHANGES:        --- Added comments ---  uidt6711 [Sep 29, 2011 3:18:05 PM CEST]
  CHANGES:        Change Package : 67326:1 http://mks-psad:7002/im/viewissue?selection=67326
  CHANGES:        Revision 1.7 2011/09/29 12:07:01CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        Remove typing error
  CHANGES:        --- Added comments ---  spruckj [Sep 29, 2011 12:07:01 PM CEST]
  CHANGES:        Change Package : 79036:2 http://mks-psad:7002/im/viewissue?selection=79036
  CHANGES:        Revision 1.6 2011/09/29 10:42:49CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        Add median calculation to the yaw angle delta
  CHANGES:        --- Added comments ---  spruckj [Sep 29, 2011 10:42:49 AM CEST]
  CHANGES:        Change Package : 79035:1 http://mks-psad:7002/im/viewissue?selection=79035
  CHANGES:        Revision 1.5 2011/09/28 15:42:51CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        - add pod box criteria
  CHANGES:        - reduce quality in case of low object changes
  CHANGES:        Revision 1.4 2011/09/26 11:42:49CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        - Remove misra errors by adding namespace SAC
  CHANGES:        Revision 1.3 2011/09/23 16:55:38CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        - Add quality calculation for the radar yaw angle error
  CHANGES:        - Remove misra issues
  CHANGES:        Revision 1.2 2011/09/20 14:37:20CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        - Add additional limitation for yaw calibration with radar object
  CHANGES:        - Filter the yaw angle estimated via the radar object
  CHANGES:        --- Added comments ---  spruckj [Sep 20, 2011 2:37:20 PM CEST]
  CHANGES:        Change Package : 79036:1 http://mks-psad:7002/im/viewissue?selection=79036
  CHANGES:        Revision 1.1 2011/05/24 10:13:40CEST Stache Nicolaj (uidt6711) (uidt6711) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SAC_StereoAutoCalibration/04_Engineering/01_Source_Code/Kernel/project.pj

**************************************************************************** */




#include <cmath>
#include "sac_interface.h"
#include "sac_math.h"
#include "sac_errors.h"
#include "viscr_smpc_depth.hpp"

namespace SAC
{

/* **************************************************************************** 
  Functionname:    limitations                      */ /*!  
  @brief           This Function can be used to check algo input
  
  @return          -

  @pre             -
  @post            -

  @author          Jochen Spruck
**************************************************************************** */
i32_t Depth::limitations(const SACRadarDistInput_t * const pRadarObj, const SACStereoDistInput_t * const pStereoObj, const f32_t velocity, const f32_t yawrate, const f32_t RectError)
{
  i32_t depth_check    = 0;
  f32_t Radius         = 10000.0F;
  bool_t RadarInPodBox = FALSE;

  /* ~CodeReview ~ID:c81a922bd4f87e9191b256353c90ada1 ~Reviewer:CW01\uidv0048 ~Date:6/28/2012 ~Priority:3 ~Comment:Remove possible useless comments for readability */
  /* calculate Radius */
  //if (fABS(yawrate) <= VISCR_DEPTH_MIN_YAW_RATE)
  //{
  //  Radius = VISCR_DEPTH_MIN_RADIUS;
  //}
  /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 03.07.2012 reason: Check if parameter reaches the minimum value. */
  if (fABS(yawrate) > VISCR_DEPTH_MIN_YAW_RATE)
  {
    Radius = fABS(velocity / yawrate);
  }
  m_DepthYawAngleData.fRadius = Radius;

  /* check POD box */
  if ((pStereoObj->y_bl_m >= pRadarObj->yPosition ) && (pRadarObj->yPosition >= pStereoObj->y_br_m))
  {
    RadarInPodBox = TRUE;
  }
  else
  {
    RadarInPodBox = FALSE;
  }

  /* calculate delta distance */
  m_DepthYawAngleData.fDistDelta = pRadarObj->xPosition-pStereoObj->xPosition;

  /* check limitations */
  /* <ln_offset:+1to+10 COVERAGE reviewer name: Alexander Behrens date: 03.07.2012 reason: Check if parameters meets the limitations. */
  if (  (RectError                             <  VISCR_DEPTH_MAX_RECT_ERROR)
      &&(fabsf(RectError)                      > C_F32_DELTA)
      &&(pStereoObj->xPosition                 >= VISCR_DEPTH_MIN_STEREO_DIST) && (pStereoObj->xPosition <= VISCR_DEPTH_MAX_STEREO_DIST)
      &&(pRadarObj->xPosition                  >= VISCR_DEPTH_MIN_STEREO_DIST) && (pRadarObj->xPosition <= VISCR_DEPTH_MAX_STEREO_DIST)
      &&(Radius                                >  VISCR_DEPTH_MIN_RADIUS)
      &&(fABS(m_DepthYawAngleData.fDistDelta)  <= ((pRadarObj->xPosition + pStereoObj->xPosition)*VISCR_DEPTH_MAX_DELTA_REL))
      &&(fABS(pRadarObj->vxSpeed)              <= VISCR_DEPTH_MAX_VXREL)
      &&(RadarInPodBox                         == TRUE)
      &&(pStereoObj->quality                   >= VISCR_DEPTH_MIN_POD_QUALITY)
      &&(pStereoObj->valid                     == VISCR_DEPTH_STEREO_VALID) )
  {
    depth_check = 1;
  }
  else 
  {
    depth_check = 0;
  }
  return depth_check;
}

/* **************************************************************************** 
  Functionname:    check                      */ /*!  
  @brief           This Function can be used to check algo input
  
  @return          -

  @pre             -
  @post            -

  @author          GARCIA Lucien, Jochen Spruck
**************************************************************************** */

i32_t Depth::check(const SACRadarDistInput_t * const pRadarObj, const SACStereoDistInput_t * const pStereoObj,const f32_t baseline, const f32_t velocity, const f32_t yawrate, const f32_t RectError)
{
  i32_t depth_check;
  /* <ln_offset:+1to+7 COVERAGE reviewer name: Alexander Behrens date: 13.07.2012 reason: Check if parameters meet the limitations. */
  if (    ( (fABS(pRadarObj->xPosition - m_DepthYawAngleData.fRadarDistance_old) > 0.0F ) || ( fABS(pStereoObj->xPosition - m_DepthYawAngleData.fStereoDistance_old) > 0.0F ) )
      &&  (pRadarObj->xPosition > VISCR_DEPTH_MIN)
      &&  (pStereoObj->xPosition > VISCR_DEPTH_MIN)
      &&  (pRadarObj->xPosition < VISCR_DEPTH_MAX)
      &&  (pStereoObj->xPosition < VISCR_DEPTH_MAX)
      &&  (baseline > VISCR_DEPTH_BASELINE_MIN)
      &&  (baseline < VISCR_DEPTH_BASELINE_MAX) )
  {
    depth_check = limitations(pRadarObj, pStereoObj, velocity, yawrate, RectError);
  }
  else
  {
    depth_check = 0;
  }

  /* if the limitations are passed */
  /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 03.07.2012 reason: Parameter control check. */
  if (depth_check == 1)
  {
    /* inc the valid cycle counter for this ignition cycle */
    m_DepthYawAngleData.uiValidCycles++;
    /* set the limitation flag */
    m_DepthYawAngleData.bLinitationPassed = TRUE;
  }
  else
  {
    /* Init the yaw delta median ring buffer */
    m_RingBuffer.BufferReInit(&m_DepthYawAngleData.YawMedian.RingBufferData);
    /* Init the distance delta median ring buffer */
    m_RingBuffer.BufferReInit(&m_DepthYawAngleData.DistMedian.RingBufferData);
    /* set the limitation flag */
    m_DepthYawAngleData.bLinitationPassed = FALSE;
  }

  /* if the radar object is valid and the use yaw angel delta flag is not set inc the init counter */
  if ( (pRadarObj->dataQuality == 1L) && (m_DepthYawAngleData.bUseYawAngleDelta == FALSE) )
  {
    m_DepthYawAngleData.uiInitCycleCounter++;
  }
  else
  {
    /* Reset the init counter */
    m_DepthYawAngleData.uiInitCycleCounter = 0U;
  }

  /* check if the initial usage of the yaw angel delta is passed */
  if ( (m_DepthYawAngleData.bUseYawAngleDelta  == FALSE)
     &&(m_DepthYawAngleData.uiInitCycleCounter >  VISCR_DEPTH_INIT_CYCLES) )
  {
    m_DepthYawAngleData.bUseYawAngleDelta = TRUE;
  }

  m_DepthYawAngleData.fRadarDistance_old  = pRadarObj->xPosition;
  m_DepthYawAngleData.fStereoDistance_old = pStereoObj->xPosition;
  return depth_check;
}
/* **************************************************************************** 
  Functionname:    init                      */ /*!  
  @brief           This Function can be used to initialize algo
                   variables
  
  @return          -

  @pre             -
  @post            -

  @author          GARCIA Lucien
**************************************************************************** */

void Depth::init(void)
{
  m_DepthYawAngleData.fRadarDistance_old  = 0.0F;
  m_DepthYawAngleData.fStereoDistance_old = 0.0F;
  m_DepthYawAngleData.fDistDelta          = 0.0F;
  m_DepthYawAngleData.fRadius             = 0.0F;
  m_DepthYawAngleData.uiTotalCylces       = 0U;
  m_DepthYawAngleData.uiValidCycles       = 0U;
  m_DepthYawAngleData.fActDeltaYaw        = 0.0F;
  m_DepthYawAngleData.uiLastObjId         = 0UL;
  m_DepthYawAngleData.uiObjectChanges     = 0U;
  m_DepthYawAngleData.uiObjIdChanged      = TRUE;
  m_Intervall.SACStatIntervalInit(&m_DepthYawAngleData.YawAngleInterval_1);
  m_Intervall.SACStatIntervalInit(&m_DepthYawAngleData.YawAngleInterval);
  m_Intervall.SACStatIntervalInit(&m_DepthYawAngleData.DeltaDistInterval_1);
  m_Intervall.SACStatIntervalInit(&m_DepthYawAngleData.DeltaDistInterval);
  m_Intervall.SACStatIntervalInit(&m_DepthYawAngleData.ObjIdYawAngleInterval);
  m_DepthYawAngleData.YawMedian.RingBufferData.pBuffer = m_DepthYawAngleData.YawMedian.Buffer;
  m_DepthYawAngleData.DistMedian.RingBufferData.pBuffer = m_DepthYawAngleData.DistMedian.Buffer;
  m_DepthYawAngleData.AppliedYawAngleMedian.RingBufferData.pBuffer = m_DepthYawAngleData.AppliedYawAngleMedian.Buffer;
  m_RingBuffer.BufferInit(&m_DepthYawAngleData.YawMedian.RingBufferData, static_cast<ui32_t>VISCR_DEPTH_MEDIAN_BUFFER_LEN);
  m_RingBuffer.BufferInit(&m_DepthYawAngleData.DistMedian.RingBufferData, static_cast<ui32_t>VISCR_DEPTH_MEDIAN_BUFFER_LEN);
  m_RingBuffer.BufferInit(&m_DepthYawAngleData.AppliedYawAngleMedian.RingBufferData, static_cast<ui32_t>VISCR_DEPTH_MEDIAN_BUFFER_LEN);
  m_DepthYawAngleData.uiReinitAppliedMedianMask = 0UL;
  m_DepthYawAngleData.uiInitCycleCounter  = 0U;
  m_DepthYawAngleData.bUseYawAngleDelta   = FALSE;
  m_DepthYawAngleData.iErrorCode          = C_SACErrors::i32_SAC_NO_ERROR;
  m_DepthYawAngleData.uiMaxDistCounter    = 0U;
  m_DepthYawAngleData.fYawAngleQuality    = 0.0F;
  m_DepthYawAngleData.fYawAngleQualityStd = 0.0F;
  m_DepthYawAngleData.fYawAngleQualityDist= 0.0F;
  m_DepthYawAngleData.fYawAngleQualityObj = 0.0F;
  m_DepthYawAngleData.fCorrYawAngle       = 0.0F;
  m_DepthYawAngleData.fRawYawAngle        = 0.0F;
  m_CurrentObjYawAngleUpdated = FALSE;
}

/* **************************************************************************** 
  Functionname:    calc_distance_median                      */ /*!  
  @brief           This Function calculates the radar stereo distance median
  
  @return          -

  @pre             -
  @post            -

  @author          Jochen Spruck
**************************************************************************** */
/* <ln_offset:+1to+25 COVERAGE reviewer name: Alexander Behrens date: 03.07.2012 reason: Function is covered by "calc_quality". */
bool_t Depth::calc_distance_median(void)
{
  SACRingBuffer_t SortedBufferData;
  f32_t SortedBuffer[VISCR_DEPTH_MEDIAN_BUFFER_LEN];
  bool_t ret_value;

  SortedBufferData.pBuffer = SortedBuffer;
  /* push value to the buffer */
  m_RingBuffer.BufferPushValue(m_DepthYawAngleData.fDistDelta, &m_DepthYawAngleData.DistMedian.RingBufferData);
  /* Sort the Buffer */
  m_RingBuffer.BufferSort(&m_DepthYawAngleData.DistMedian.RingBufferData, &SortedBufferData);
  /* Get the median value */
  m_DepthYawAngleData.DistMedian.fActMedian = m_RingBuffer.GetBufferMedian(&SortedBufferData);
  
  /* check buffer load if buffer is not full set return value to false */
  if (m_DepthYawAngleData.DistMedian.RingBufferData.nBufferLoad < static_cast<i32_t>VISCR_DEPTH_MEDIAN_BUFFER_LEN)
  {
    ret_value = FALSE;
  }
  else
  {
    ret_value = TRUE;
  }
  return ret_value;
}

/* **************************************************************************** 
  Functionname:    calc_delta_median                      */ /*!  
  @brief           This Function calculates the radar yaw angle delta median
  
  @return          -

  @pre             -
  @post            -

  @author          Jochen Spruck
**************************************************************************** */
/* <ln_offset:+1to+25 COVERAGE reviewer name: Alexander Behrens date: 03.07.2012 reason: Function is covered by "calc_yaw_angle_delta". */
bool_t Depth::calc_delta_median(void)
{
  SACRingBuffer_t SortedBufferData;
  f32_t SortedBuffer[VISCR_DEPTH_MEDIAN_BUFFER_LEN];
  bool_t ret_value;

  SortedBufferData.pBuffer = SortedBuffer;
  /* push value to the buffer */
  m_RingBuffer.BufferPushValue(m_DepthYawAngleData.fActDeltaYaw, &m_DepthYawAngleData.YawMedian.RingBufferData);
  /* Sort the Buffer */
  m_RingBuffer.BufferSort(&m_DepthYawAngleData.YawMedian.RingBufferData, &SortedBufferData);
  /* Get the median value */
  m_DepthYawAngleData.YawMedian.fActMedian = m_RingBuffer.GetBufferMedian(&SortedBufferData);
  
  /* check buffer load if buffer is not full set return value to false */
  if (m_DepthYawAngleData.YawMedian.RingBufferData.nBufferLoad < static_cast<i32_t>VISCR_DEPTH_MEDIAN_BUFFER_LEN)
  {
    ret_value = FALSE;
  }
  else
  {
    ret_value = TRUE;
  }
  return ret_value;
}


/* **************************************************************************** 
  Functionname:    calc_yaw_angle_delta                      */ /*!  
  @brief           This Function calculates the radar yaw angle delta
  
  @return          -

  @pre             -
  @post            -

  @author          Jochen Spruck
**************************************************************************** */
/* <ln_offset:+1to+38 COVERAGE reviewer name: Alexander Behrens date: 03.07.2012 reason: Function is covered by condition in "run". */
void Depth::calc_yaw_angle_delta(const f32_t radarDistance, const f32_t stereoDistance, const f32_t baseline, const f32_t XPosMounting)
{
  /* calculate the yaw angle delta */
  // y = atan(x) could be replace by y = x for optimization
  /* ~CodeReview ~ID:db57e06e5b097bd0f0dc104adfaf8155 ~Reviewer:CW01\uidv0048 ~Date:6/28/2012 ~Priority:3 ~Comment:Split up complicated statement into multiple more comprehensible ones */
  /* ~CodeReview ~ID:2861d1974eab373c989de6b5101b1436 ~Reviewer:CW01\uidv0048 ~Date:6/28/2012 ~Priority:2 ~Comment:Possible divisions by zero */
  m_DepthYawAngleData.fActDeltaYaw = atanf(baseline*((1.0F/(stereoDistance-XPosMounting)) - (1.0F/(radarDistance-XPosMounting)) ));

  /* calculate the yaw angle delta median */
  /* only if the buffer is full add the median to the mean */
  if (calc_delta_median() == TRUE)
  {
    if (m_DepthYawAngleData.YawAngleInterval_1.Volume > VISCR_DEPTH_MIN_CALIB_CYCLES)
    {
      /* init the first sample interval */
      m_Intervall.SACStatIntervalInit(&m_DepthYawAngleData.YawAngleInterval_1);
    }

    /* add yaw angle median to the first sample interval */
    m_Intervall.SACStatIntervalAdd(&m_DepthYawAngleData.YawAngleInterval_1,m_DepthYawAngleData.YawMedian.fActMedian,1.0F);
    /* if max sample count reached add the first sample interval to the main and calculate mean standard dev */
    if (m_DepthYawAngleData.YawAngleInterval_1.Volume >= VISCR_DEPTH_MIN_CALIB_CYCLES)
    {
      /* calculate mean and std of the main sample interval */
      m_Intervall.SACStatIntervalMeanDev(&m_DepthYawAngleData.YawAngleInterval);

      /* reduce main sample interval */
      /* ~CodeReview ~ID:29b0eb456bd63f84f1c74d04a8aa0de9 ~Reviewer:CW01\uidv0048 ~Date:6/28/2012 ~Priority:3 ~Comment:Use meaningful defines instead of magic numbers */
      m_Intervall.SACStatIntervalReduce(&m_DepthYawAngleData.YawAngleInterval,0.9F);
      /* merge the first to the main sample interval */
      m_Intervall.SACStatIntervalMerge(&m_DepthYawAngleData.YawAngleInterval,&m_DepthYawAngleData.YawAngleInterval_1);
      /* calculate mean and std of the main sample interval */
      m_Intervall.SACStatIntervalMeanDev(&m_DepthYawAngleData.YawAngleInterval_1);
    }
  }


}

/* **************************************************************************** 
  Functionname:    calc_quality                      */ /*!  
  @brief           This Function calculates a quality value for the radar yaw angle
  
  @return          -

  @pre             -
  @post            -

  @author          Jochen Spruck
**************************************************************************** */
/* <ln_offset:+1to+114 COVERAGE reviewer name: Alexander Behrens date: 03.07.2012 reason: Function is covered by condition in "run". */
void Depth::calc_quality(const SACStereoDistInput_t * const pStereoObj)
{
  f32_t fQuality;
  f32_t fReduceQuality;

  /* calculate the distance delta median */
  /* only if the buffer is full add the median to the mean */
  if (calc_distance_median() == TRUE)
  {
    if (m_DepthYawAngleData.DeltaDistInterval_1.Volume > VISCR_DEPTH_MIN_CALIB_CYCLES)
    {
      /* init the first sample interval */
      m_Intervall.SACStatIntervalInit(&m_DepthYawAngleData.DeltaDistInterval_1);
    }

    /* add delta dist to the first sample interval */
    m_Intervall.SACStatIntervalAdd(&m_DepthYawAngleData.DeltaDistInterval_1,m_DepthYawAngleData.DistMedian.fActMedian,1.0F);
    /* if max sample count reached add the first sample interval to the main and calculate mean standard dev */
    if (m_DepthYawAngleData.DeltaDistInterval_1.Volume >= VISCR_DEPTH_MIN_CALIB_CYCLES)
    {
      /* calculate mean and std of the main sample interval */
      m_Intervall.SACStatIntervalMeanDev(&m_DepthYawAngleData.DeltaDistInterval_1);

      /* reduce main sample interval */
      /* ~CodeReview ~ID:3b073d209cac562141de1e13310b1602 ~Reviewer:CW01\uidv0048 ~Date:6/28/2012 ~Priority:3 ~Comment:Use meaningful defines instead of magic numbers */
      m_Intervall.SACStatIntervalReduce(&m_DepthYawAngleData.DeltaDistInterval,0.9F);
      /* merge the first to the main sample interval */
      m_Intervall.SACStatIntervalMerge(&m_DepthYawAngleData.DeltaDistInterval,&m_DepthYawAngleData.DeltaDistInterval_1);
      /* calculate mean and std of the main sample interval */
      m_Intervall.SACStatIntervalMeanDev(&m_DepthYawAngleData.DeltaDistInterval);
    }


    /* check if the distance median is above the max threshold */
    if  ( (fABS(m_DepthYawAngleData.DeltaDistInterval.Mean) >  VSICR_DEPTH_MAX_RA_ST_DIST      )
        &&(m_DepthYawAngleData.uiMaxDistCounter             <= (VSICR_DEPTH_MAX_DIST_CYCLES*2U)) )
    {
      m_DepthYawAngleData.uiMaxDistCounter++;
    }
    else
    {
      if (m_DepthYawAngleData.uiMaxDistCounter > 0U)
      {
        m_DepthYawAngleData.uiMaxDistCounter--;
      }
    }

    /* check for stereo object id changes */
    if ((m_DepthYawAngleData.uiLastObjId != pStereoObj->objID) && (m_DepthYawAngleData.uiObjectChanges < VISCR_DEPTH_LIMIT_OBJ_CHANGES))
    {
      m_DepthYawAngleData.uiLastObjId = pStereoObj->objID;
      m_DepthYawAngleData.uiObjectChanges++;
      m_DepthYawAngleData.uiObjIdChanged = TRUE;
    }

  }

  /* check if the counter max distance is above threshold */
  if (  (m_DepthYawAngleData.uiMaxDistCounter > VSICR_DEPTH_MAX_DIST_CYCLES)
    &&(m_DepthYawAngleData.iErrorCode == C_SACErrors::i32_SAC_NO_ERROR))
  {
    /* set the error code */
    m_DepthYawAngleData.iErrorCode = C_SACErrors::i32_SAC_INPUT_INVALID_RADAR_STEREO_DIST;
  }
  else
  {
    /* reset the error code if the error is active */
    if (m_DepthYawAngleData.iErrorCode == C_SACErrors::i32_SAC_INPUT_INVALID_RADAR_STEREO_DIST)
    {
      m_DepthYawAngleData.iErrorCode = C_SACErrors::i32_SAC_NO_ERROR;
    }
  }


  /* calculate the distance quality */
  if (fABS(m_DepthYawAngleData.DeltaDistInterval.Volume) <= 0.0001F)
  {
    m_DepthYawAngleData.fYawAngleQualityDist = VISCR_DEPTH_MIN_QUALITY;
  }
  else
  {
    m_DepthYawAngleData.fYawAngleQualityDist = SACLFunction(fABS(m_DepthYawAngleData.DeltaDistInterval.Mean),
      VISCR_DEPTH_MAX_DIST_MEAN, VISCR_DEPTH_MIN_DIST_MEAN,
      VISCR_DEPTH_MIN_QUALITY  , VISCR_DEPTH_MAX_QUALITY  );
    m_DepthYawAngleData.fYawAngleQualityDist = MINMAX_FLOAT(VISCR_DEPTH_MIN_QUALITY,VISCR_DEPTH_MAX_QUALITY,m_DepthYawAngleData.fYawAngleQualityDist);
  }

  /* calculate the yaw angle deviation quality */
  if (fABS(m_DepthYawAngleData.YawAngleInterval.Volume) <= 0.0001F)
  {
    m_DepthYawAngleData.fYawAngleQualityStd = VISCR_DEPTH_MIN_QUALITY;
  }
  else
  {
    m_DepthYawAngleData.fYawAngleQualityStd = SACLFunction(m_DepthYawAngleData.YawAngleInterval.Dev,
      VISCR_DEPTH_MAX_YAW_DEV, VISCR_DEPTH_MIN_YAW_DEV,
      VISCR_DEPTH_MIN_QUALITY, VISCR_DEPTH_MAX_QUALITY ) ;
    m_DepthYawAngleData.fYawAngleQualityStd = MINMAX_FLOAT(VISCR_DEPTH_MIN_QUALITY,VISCR_DEPTH_MAX_QUALITY,m_DepthYawAngleData.fYawAngleQualityStd);
  }

  /* calculate the total minimum of the above qualities */
  fQuality = MIN_FLOAT(m_DepthYawAngleData.fYawAngleQualityDist,m_DepthYawAngleData.fYawAngleQualityStd );

  /* calculate the number of object changes reduce quality */
  m_DepthYawAngleData.fYawAngleQualityObj = SACLFunction(static_cast<f32_t>(m_DepthYawAngleData.uiObjectChanges),
    VISCR_DEPTH_MIN_OBJ_CHANGES, VISCR_DEPTH_MAX_OBJ_CHANGES,
    VISCR_DEPTH_HALF_QUALITY, VISCR_DEPTH_MIN_QUALITY);
  m_DepthYawAngleData.fYawAngleQualityObj = MINMAX_FLOAT(VISCR_DEPTH_MIN_QUALITY,VISCR_DEPTH_MAX_QUALITY,m_DepthYawAngleData.fYawAngleQualityObj);

  fReduceQuality = m_DepthYawAngleData.fYawAngleQualityObj;

  /* get the min quality of the distance quality and the yaw angle deviation quality*/
  m_DepthYawAngleData.fYawAngleQuality = MINMAX_FLOAT(VISCR_DEPTH_MIN_QUALITY,VISCR_DEPTH_MAX_QUALITY,(fQuality-fReduceQuality));
}

/* **************************************************************************** 
  Functionname:    run                      */ /*!  
  @brief           This Function can be used to run the algo
                   variables
  
  @return          -

  @pre             -
  @post            -

  @author          GARCIA Lucien, Jochen Spruck
**************************************************************************** */

void Depth::run( const SACRadarDistInput_t * const pRadarObj, const SACStereoDistInput_t * const pStereoObj, f32_t const baseline, f32_t const XPosMounting, f32_t const velocity, f32_t const yawrate, f32_t const RectError)
{
  if (check(pRadarObj, pStereoObj, baseline, velocity, yawrate, RectError) == 1)
  {
    /* calculate the yaw angle delta from radar object */
    calc_yaw_angle_delta( pRadarObj->xPosition, pStereoObj->xPosition, baseline, XPosMounting);

    /* calculate the yaw angle quality */
    calc_quality(pStereoObj);
  }
  else
  {
    /* init the first sample interval */
    m_Intervall.SACStatIntervalInit(&m_DepthYawAngleData.YawAngleInterval_1);
    m_Intervall.SACStatIntervalInit(&m_DepthYawAngleData.DeltaDistInterval_1);
    m_DepthYawAngleData.fActDeltaYaw = 0.0F;
  }

  /* Inc total Counter */
  m_DepthYawAngleData.uiTotalCylces++;

  /* ~CodeReview ~ID:1aae7f4693e6bbcbba7fddcbd52a6440 ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:2 ~Comment:Possible division by zero */
  m_DepthYawAngleData.fAvailability = (static_cast<f32_t>(m_DepthYawAngleData.uiValidCycles)/static_cast<f32_t>(m_DepthYawAngleData.uiTotalCylces));
}


/* ~CodeReview ~ID:7699985294096d0533943e7562c3b03c ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Remove dead code for readability */
#if 0 // CODE NOT USED
/* **************************************************************************** 
  Functionname:    get_delta_yaw_last                      */ /*!  
  @brief           This Function can be used to get last delta yaw
                   variables
  
  @return          -

  @pre             -
  @post            -

  @author          GARCIA Lucien
**************************************************************************** */
f32_t Depth::get_delta_yaw_last() const
{
  fAngle_t ret_value = 0.0F;
  if (m_DepthYawAngleData.bUseYawAngleDelta == TRUE)
  {
    ret_value = m_DepthYawAngleData.fActDeltaYaw;
  }
  return (ret_value);
}

/* **************************************************************************** 
  Functionname:    get_delta_yaw_mean                      */ /*!  
  @brief           This Function can be used to get the yaw angle delta
                   mean
  
  @return          -

  @pre             -
  @post            -

  @author          GARCIA Lucien, Jochen Spruck
**************************************************************************** */
f32_t Depth::get_delta_yaw_mean() const
{
  fAngle_t ret_value = 0.0F;
  if (m_DepthYawAngleData.bUseYawAngleDelta == TRUE)
  {
    ret_value = m_DepthYawAngleData.YawAngleInterval.Mean;
  }
  return (ret_value);
}

/* **************************************************************************** 
  Functionname:    get_delta_yaw_dev                     */ /*!  
  @brief           This Function can be used to get the yaw angle delta
                   standard deviation
  
  @return          -

  @pre             -
  @post            -

  @author          Jochen Spruck
**************************************************************************** */
f32_t Depth::get_delta_yaw_dev() const
{
  fAngle_t ret_value = 0.0F;
  if (m_DepthYawAngleData.bUseYawAngleDelta == TRUE)
  {
    ret_value = m_DepthYawAngleData.YawAngleInterval.Dev;
  }
  return (ret_value);
}

/* **************************************************************************** 
  Functionname:    get_delta_yaw_quality                     */ /*!  
  @brief           This Function can be used to get the yaw angle delta
                   quality
  
  @return          -

  @pre             -
  @post            -

  @author          Jochen Spruck
**************************************************************************** */
f32_t Depth::get_delta_yaw_quality() const
{
  return m_DepthYawAngleData.fYawAngleQuality;
}
#endif
/* **************************************************************************** 
  Functionname:    get_tempmodel_yaw_angle                     */ /*!  
  @brief           This Function can be used to get the yaw angle for the temp model
  
  @return          -

  @pre             -
  @post            -

  @author          Jochen Spruck
**************************************************************************** */
bool_t Depth::get_tempmodel_yaw_angle(SACDepthYawAngleOutput_t * const pAngleOutput)
{
  bool_t DoYawUpdate = FALSE;
  /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 05.07.2012 reason: Parameter update control check. */
  if (m_CurrentObjYawAngleUpdated == TRUE)
  {
    pAngleOutput->fYawAngle = m_DepthYawAngleData.LastObjYawAngle.fYawAngle;
    pAngleOutput->fQuality  = m_DepthYawAngleData.LastObjYawAngle.fQuality;
    pAngleOutput->fDev      = m_DepthYawAngleData.LastObjYawAngle.fDev;
    /* Set Do Yaw Angle Update */
    DoYawUpdate = TRUE;
    m_CurrentObjYawAngleUpdated = FALSE;
  }
  else
  {
    DoYawUpdate = FALSE;
    pAngleOutput->fYawAngle = m_DepthYawAngleData.LastObjYawAngle.fYawAngle;
    pAngleOutput->fQuality  = VISCR_DEPTH_MIN_QUALITY;
    pAngleOutput->fDev      = VISCR_DEPTH_MAX_YAW_DEV;
  }
  return DoYawUpdate;
}

/* **************************************************************************** 
  Functionname:    get_yaw_angle                     */ /*!  
  @brief           This Function can be used to get the yaw angle
  
  @return          -

  @pre             -
  @post            -

  @author          Jochen Spruck
**************************************************************************** */
bool_t Depth::get_yaw_angle(const fAngle_t fAngle, const fAngle_t fTempModelYawAngle, SACDepthYawAngleOutput_t  * const pAngleOutput)
{
  bool_t DoYawUpdate = FALSE;
  SACRingBuffer_t SortedBufferData;
  f32_t SortedBuffer[VISCR_DEPTH_MEDIAN_BUFFER_LEN];

  SortedBufferData.pBuffer = SortedBuffer;

  /* setup the raw not corrected yaw angle */
  m_DepthYawAngleData.fRawYawAngle = fAngle;

  /* Calculate the corrected yaw angle */
  m_DepthYawAngleData.fCorrYawAngle = m_DepthYawAngleData.fRawYawAngle + m_DepthYawAngleData.YawAngleInterval.Mean;

  /* if the use flag is set use the radar based yaw angle */
  /* <ln_offset:+1to+68 COVERAGE reviewer name: Alexander Behrens date: 04.07.2012 reason: Condition is covered in the case of using radar based yaw angle. */
  if ( (m_DepthYawAngleData.bUseYawAngleDelta == TRUE) && (m_DepthYawAngleData.YawAngleInterval.Volume > (VISCR_DEPTH_MIN_CALIB_CYCLES * VISCR_DEPTH_VOLUME_THRESH)))
  {
    /* init yaw angle buffer if the buffer load is zero or the Reinit Mask is zero with the not corrected last yaw angle*/
    if ( (m_DepthYawAngleData.AppliedYawAngleMedian.RingBufferData.nBufferLoad == 0L) && (m_DepthYawAngleData.uiReinitAppliedMedianMask == 0U))
    {
      for (ui32_t i = 0UL; i < m_DepthYawAngleData.AppliedYawAngleMedian.RingBufferData.nBufferSize; i++ )
      {
        m_RingBuffer.BufferPushValue(m_DepthYawAngleData.fRawYawAngle, &m_DepthYawAngleData.AppliedYawAngleMedian.RingBufferData);
        /* set reinit mask to the reinit flag 1 */
        m_DepthYawAngleData.uiReinitAppliedMedianMask |= static_cast<ui32_t>(0x1UL<<i);
      }
    }
    else
    {
      /* reinit the not used AppliedYawAngleMedian buffer values with the temp model*/
      for (ui32_t i = 0UL; i < m_DepthYawAngleData.AppliedYawAngleMedian.RingBufferData.nBufferSize; i++)
      {
        ui32_t Mask = static_cast<ui32_t>(0x1UL<<i);
        /* if reinit flag is set for the index use the actuall temp model yaw rate */
        if ((m_DepthYawAngleData.uiReinitAppliedMedianMask & Mask) == Mask)
        {
          m_DepthYawAngleData.AppliedYawAngleMedian.Buffer[i] = fTempModelYawAngle;
        }
      }
    }
    
    /* Add corrected yaw angle to the ObjId Yaw angle Intervall */
    m_Intervall.SACStatIntervalAdd(&m_DepthYawAngleData.ObjIdYawAngleInterval, m_DepthYawAngleData.fCorrYawAngle, 1.0F);
    
    /* If the ObjId has been changed add the mean to the median buffer */
    if (m_DepthYawAngleData.uiObjIdChanged == TRUE)
    {
      /* calc mean of ObjIdYawAngleInterval */
      m_Intervall.SACStatIntervalMeanDev(&m_DepthYawAngleData.ObjIdYawAngleInterval);

      /* store the actual obj yaw angle */
      m_DepthYawAngleData.LastObjYawAngle.fYawAngle = m_DepthYawAngleData.ObjIdYawAngleInterval.Mean;
      m_DepthYawAngleData.LastObjYawAngle.fQuality  = m_DepthYawAngleData.fYawAngleQuality;
      m_DepthYawAngleData.LastObjYawAngle.fDev      = m_DepthYawAngleData.ObjIdYawAngleInterval.Dev;

      /* push value to the buffer */
      m_RingBuffer.BufferPushValue(m_DepthYawAngleData.ObjIdYawAngleInterval.Mean, &m_DepthYawAngleData.AppliedYawAngleMedian.RingBufferData);
      /* reset the reinit flag */
      m_DepthYawAngleData.uiReinitAppliedMedianMask &= static_cast<ui32_t>(~(0x1UL<<m_DepthYawAngleData.AppliedYawAngleMedian.RingBufferData.nBufferIndex));

      /* init intervall */
      m_Intervall.SACStatIntervalInit(&m_DepthYawAngleData.ObjIdYawAngleInterval);
      /* Reset Object changed flag */
      m_DepthYawAngleData.uiObjIdChanged = FALSE;
      /* Set Do Yaw Angle Update */
      DoYawUpdate       = TRUE;
      m_CurrentObjYawAngleUpdated = TRUE;
    }

    /* Sort the Buffer */
    m_RingBuffer.BufferSort(&m_DepthYawAngleData.AppliedYawAngleMedian.RingBufferData, &SortedBufferData);
    /* Get mean of yaw angle quantile */
    m_DepthYawAngleData.AppliedYawAngleMedian.fActMedian = m_RingBuffer.GetQuantileMedian(&SortedBufferData,
                                                                                          VSICR_DEPTH_YAW_QUANTILE_LOW,
                                                                                          VSICR_DEPTH_YAW_QUANTILE_UP);

    pAngleOutput->fYawAngle = m_DepthYawAngleData.AppliedYawAngleMedian.fActMedian;
    pAngleOutput->fQuality  = m_DepthYawAngleData.fYawAngleQuality;
    pAngleOutput->fDev      = m_DepthYawAngleData.YawAngleInterval.Dev;
    /* ~CodeReview ~ID:4723f69413b3006232eeeecdd7a3982c ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Use meaningful define instead of magic numbers */
    m_Intervall.SACStatIntervalReduce(&m_DepthYawAngleData.YawAngleInterval_1 , 0.05F);
    m_Intervall.SACStatIntervalReduce(&m_DepthYawAngleData.YawAngleInterval   , 0.05F);
  }
  else
  {
    DoYawUpdate = FALSE;
    pAngleOutput->fYawAngle = fAngle;
    pAngleOutput->fQuality  = VISCR_DEPTH_MIN_QUALITY;
    pAngleOutput->fDev      = VISCR_DEPTH_MAX_YAW_DEV;
  }

  return DoYawUpdate;
}

/* **************************************************************************** 
  Functionname:    blend_yaw_angle_with_tempmodel                     */ /*!  
  @brief           Blending between temperature model and input yaw angle.
  
  @return          -

  @pre             -
  @post            -

  @author          Reik Müller
**************************************************************************** */
void Depth::blend_yaw_angle_with_tempmodel(const fAngle_t fAngleInput, const fAngle_t fTempModelYawAngle, SACDepthYawAngleOutput_t  * const pAngleOutput)
{
  SACRingBuffer_t SortedBufferData;
  f32_t SortedBuffer[VISCR_DEPTH_MEDIAN_BUFFER_LEN];

  SortedBufferData.pBuffer = SortedBuffer;

  /* if the median buffer is empty, fill it with zeros and set the re-init flag on all entries */
  if ( (m_DepthYawAngleData.AppliedYawAngleMedian.RingBufferData.nBufferLoad == 0L) && (m_DepthYawAngleData.uiReinitAppliedMedianMask == 0U))
  {
    for (ui32_t i = 0UL; i < m_DepthYawAngleData.AppliedYawAngleMedian.RingBufferData.nBufferSize; i++ )
    {
      m_RingBuffer.BufferPushValue(0, &m_DepthYawAngleData.AppliedYawAngleMedian.RingBufferData);
      /* set reinit mask to the reinit flag 1 */
      m_DepthYawAngleData.uiReinitAppliedMedianMask |= static_cast<ui32_t>(0x1UL<<i);
    }
  }

  /* reinit the not used AppliedYawAngleMedian buffer values with the temp model */
  for (ui32_t i = 0UL; i < m_DepthYawAngleData.AppliedYawAngleMedian.RingBufferData.nBufferSize; i++)
  {
    ui32_t Mask = static_cast<ui32_t>(0x1UL<<i);
    /* if reinit flag is set for the index, use the current temp model yaw angle */
    if ((m_DepthYawAngleData.uiReinitAppliedMedianMask & Mask) == Mask)
    {
      m_DepthYawAngleData.AppliedYawAngleMedian.Buffer[i] = fTempModelYawAngle;
    }
  }

  /* push new angle to the ring buffer */
  m_RingBuffer.BufferPushValue(fAngleInput, &m_DepthYawAngleData.AppliedYawAngleMedian.RingBufferData);
  /* reset the reinit flag */
  m_DepthYawAngleData.uiReinitAppliedMedianMask &= static_cast<ui32_t>(~(0x1UL<<m_DepthYawAngleData.AppliedYawAngleMedian.RingBufferData.nBufferIndex));

  /* Sort the Buffer */
  m_RingBuffer.BufferSort(&m_DepthYawAngleData.AppliedYawAngleMedian.RingBufferData, &SortedBufferData);
  /* Get mean of yaw angle quantile */
  m_DepthYawAngleData.AppliedYawAngleMedian.fActMedian = m_RingBuffer.GetQuantileMedian(&SortedBufferData,
                                                                                        VSICR_DEPTH_YAW_QUANTILE_LOW,
                                                                                        VSICR_DEPTH_YAW_QUANTILE_UP);

  /* set output */
  pAngleOutput->fYawAngle = m_DepthYawAngleData.AppliedYawAngleMedian.fActMedian;
  pAngleOutput->fQuality  = 0.99f; // TODO: calc actual value
  pAngleOutput->fDev      = VISCR_DEPTH_MAX_YAW_DEV; // TODO: calc actual value

  /* store the actual obj yaw angle */
  m_DepthYawAngleData.LastObjYawAngle.fYawAngle = m_DepthYawAngleData.AppliedYawAngleMedian.fActMedian;
  m_DepthYawAngleData.LastObjYawAngle.fQuality  = 0.99f; // TODO: calc actual value
  m_DepthYawAngleData.LastObjYawAngle.fDev      = VISCR_DEPTH_MAX_YAW_DEV; // TODO: calc actual value
  m_CurrentObjYawAngleUpdated = TRUE;
}

/* **************************************************************************** 
  Functionname:    get_error_code                     */ /*!  
  @brief           This Function can be used to get the yaw angle error code
  
  @return          -

  @pre             -
  @post            -

  @author          Jochen Spruck
**************************************************************************** */
i32_t Depth::get_error_code(void) const
{
  return m_DepthYawAngleData.iErrorCode;
}

/* **************************************************************************** 
  Functionname:    exit                      */ /*!  
  @brief           This Function can be used to exit the algo
                   variables
  
  @return          -

  @pre             -
  @post            -

  @author          GARCIA Lucien
**************************************************************************** */
/* ~CodeReview ~ID:6a56e4028b7cd705baf3fef5fc325494 ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Empty function. Remove it or modify so as to make it useful */
void Depth::exit(void) const /* <ln_offset:+1to+3 COVERAGE reviewer name: Alexander Behrens date: 17.07.2012 reason: Empty function. */
{
}

/* **************************************************************************** 
  Functionname:    get_private_data                      */ /*!  
  @brief           This Function can be used get the private depth data
  
  @return          -

  @pre             -
  @post            -

  @author          Jochen Spruck
**************************************************************************** */
const SACDepthYawAngleData_t * Depth::get_private_data(void) const
{
  return &m_DepthYawAngleData;
}

}
