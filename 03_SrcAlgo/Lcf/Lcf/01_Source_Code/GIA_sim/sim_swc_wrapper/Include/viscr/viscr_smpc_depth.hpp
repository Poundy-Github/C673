/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      SAC - Stereo Auto Calibration

  MODULNAME:      viscr_smpc_depth.hpp

  DESCRIPTION:    Delta camera yaw computation based on radar distance

  AUTHOR:         L. GARCIA

  CREATION DATE:  23.05.2011

  VERSION:        $Revision: 1.1 $

  CHANGES:        $Log: viscr_smpc_depth.hpp  $
  CHANGES:        Revision 1.1 2021/12/13 17:28:37CET Wang, David (Wangd3) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.0 2017/03/03 10:40:32CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.22 2013/11/27 11:10:26CET Mueller, Reik (muellerr5) 
  CHANGES:        - added blend_yaw_angle_with_tempmodel()
  CHANGES:        - Added comments -  muellerr5 [Nov 27, 2013 11:10:27 AM CET]
  CHANGES:        Change Package : 207519:1 http://mks-psad:7002/im/viewissue?selection=207519
  CHANGES:        Revision 1.21 2012/06/29 18:18:41CEST Malot-EXT, Frederic (uidv0048) 
  CHANGES:        Add findings from code review
  CHANGES:        --- Added comments ---  uidv0048 [Jun 29, 2012 6:18:41 PM CEST]
  CHANGES:        Change Package : 130129:1 http://mks-psad:7002/im/viewissue?selection=130129
  CHANGES:        Revision 1.20 2012/03/07 14:56:37CET Konarski-EXT, Witek (uidt8403) 
  CHANGES:        Removed PC-Lint/Misra errors.
  CHANGES:        --- Added comments ---  uidt8403 [Mar 7, 2012 2:56:37 PM CET]
  CHANGES:        Change Package : 101150:4 http://mks-psad:7002/im/viewissue?selection=101150
  CHANGES:        Revision 1.19 2012/03/02 11:10:46CET Garcia, Lucien (uid26778) 
  CHANGES:        Remove unused code
  CHANGES:        --- Added comments ---  uid26778 [Mar 2, 2012 11:10:46 AM CET]
  CHANGES:        Change Package : 80273:2 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.18 2012/01/23 18:45:56CET Stache, Nicolaj (uidt6711) 
  CHANGES:        Update of baselinelength check
  CHANGES:        --- Added comments ---  uidt6711 [Jan 23, 2012 6:45:56 PM CET]
  CHANGES:        Change Package : 67326:3 http://mks-psad:7002/im/viewissue?selection=67326
  CHANGES:        Revision 1.17 2011/12/14 17:35:57CET Stache Nicolaj (uidt6711) (uidt6711) 
  CHANGES:        update
  CHANGES:        --- Added comments ---  uidt6711 [Dec 14, 2011 5:35:57 PM CET]
  CHANGES:        Change Package : 67326:3 http://mks-psad:7002/im/viewissue?selection=67326
  CHANGES:        Revision 1.16 2011/12/12 12:11:36CET Stache Nicolaj (uidt6711) (uidt6711) 
  CHANGES:        [bugfix:] baselinecheck corrected
  CHANGES:        Revision 1.15 2011/11/16 12:41:15CET Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        Change distance fusi threshold from 4 m to 40 to disable this check
  CHANGES:        --- Added comments ---  spruckj [Nov 16, 2011 12:41:15 PM CET]
  CHANGES:        Change Package : 87958:1 http://mks-psad:7002/im/viewissue?selection=87958
  CHANGES:        Revision 1.14 2011/11/14 16:07:46CET Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        Init the not learnd buffer entries of yaw angle object median buffer with the yaw angle of the temp model
  CHANGES:        --- Added comments ---  spruckj [Nov 14, 2011 4:07:46 PM CET]
  CHANGES:        Change Package : 87958:1 http://mks-psad:7002/im/viewissue?selection=87958
  CHANGES:        Revision 1.13 2011/11/12 17:54:54CET Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        Yaw angle in Temp model should be updated if the object id changed
  CHANGES:        --- Added comments ---  spruckj [Nov 12, 2011 5:54:54 PM CET]
  CHANGES:        Change Package : 87855:1 http://mks-psad:7002/im/viewissue?selection=87855
  CHANGES:        Revision 1.12 2011/11/09 18:16:02CET Stache Nicolaj (uidt6711) (uidt6711) 
  CHANGES:        Bugfix-Papenburg
  CHANGES:        --- Added comments ---  uidt6711 [Nov 9, 2011 6:16:02 PM CET]
  CHANGES:        Change Package : 87467:1 http://mks-psad:7002/im/viewissue?selection=87467
  CHANGES:        Revision 1.11 2011/10/20 19:57:52CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        Radar yaw angle does not converge bug fix
  CHANGES:        --- Added comments ---  spruckj [Oct 20, 2011 7:57:52 PM CEST]
  CHANGES:        Change Package : 64567:4 http://mks-psad:7002/im/viewissue?selection=64567
  CHANGES:        Revision 1.10 2011/10/13 17:34:02CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        Take the x mounting pos into account
  CHANGES:        --- Added comments ---  spruckj [Oct 13, 2011 5:34:02 PM CEST]
  CHANGES:        Change Package : 79036:2 http://mks-psad:7002/im/viewissue?selection=79036
  CHANGES:        Revision 1.9 2011/10/11 15:39:38CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        - Change enable radar yaw calib conition, if radar obj is valid for x cylces use the radar based calib
  CHANGES:        - Put all quality infos to internal data struct
  CHANGES:        - Add get quality interface
  CHANGES:        - Add the raw yaw angle to internal date struct
  CHANGES:        Revision 1.8 2011/10/10 16:41:29CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        Quality estimation update
  CHANGES:        Revision 1.7 2011/10/06 16:41:19CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        Add
  CHANGES:        - Error if distance between radar and stereo dist is to high
  CHANGES:        - Activate the radar bases yaw angle calibration only if the rectification error is low
  CHANGES:        - Use the radar based yaw anlge output only if a radar object was pressent for a time of 1 minute
  CHANGES:        --- Added comments ---  spruckj [Oct 6, 2011 4:41:20 PM CEST]
  CHANGES:        Change Package : 79035:1 http://mks-psad:7002/im/viewissue?selection=79035
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
  CHANGES:        --- Added comments ---  spruckj [Sep 20, 2011 2:37:21 PM CEST]
  CHANGES:        Change Package : 79036:1 http://mks-psad:7002/im/viewissue?selection=79036
  CHANGES:        Revision 1.1 2011/05/24 10:13:43CEST Stache Nicolaj (uidt6711) (uidt6711) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SAC_StereoAutoCalibration/04_Engineering/01_Source_Code/Kernel/project.pj

**************************************************************************** */


#ifndef _viscr_smpc_depth_hpp_
#define _viscr_smpc_depth_hpp_

#include <viscr_types.hpp>
#include "viscr_smpc_depth_types.h"

#define VISCR_DEPTH_MIN               (10.0F)         /*!< Min distance of objects */
#define VISCR_DEPTH_MAX               (200.0F)        /*!< Max distance of objects */
#define VISCR_DEPTH_BASELINE_MIN      (0.11F)         /*!< Min baseline */
#define VISCR_DEPTH_BASELINE_MAX      (0.24F)         /*!< Max baseline */

#define VISCR_DEPTH_MIN_CALIB_CYCLES  (15.0F)         /*!< Mean filter length */
#define VISCR_DEPTH_VOLUME_THRESH     (7.5F)          /*!< Volume threshold 15*(10*0.75) = 112.5 */

#define VISCR_DEPTH_MIN_YAW_RATE      (0.0001F)       /*!< Min yaw rate to prevent div by zero */
#define VISCR_DEPTH_MAX_DELTA_REL     (0.4F)          /*!< Max proc delta between the radar and the stereo x distance, related to the sum of the distances delta < (x_radar+x_stero)*VISCR_DEPTH_MAX_DELTA_REL */
#define VISCR_DEPTH_MIN_STEREO_DIST   (20.0F)         /*!< Min dist of stereo object to enable radar based calibration */
#define VISCR_DEPTH_MAX_STEREO_DIST   (60.0F)         /*!< Max dist of stereo object to enable radar based calibration */
#define VISCR_DEPTH_MIN_RADIUS        (2000.0F)       /*!< Min radius to enable radar based calibration */
#define VISCR_DEPTH_MAX_VXREL         (1.0F)          /*!< Max x rel velocity of radar obj */
#define VISCR_DEPTH_MIN_POD_QUALITY   (0.65F)         /*!< Min POD obj quality to use it*/
#define VISCR_DEPTH_STEREO_VALID      (1L)            /*!< Valid flag for stereo obj  */
#define VISCR_DEPTH_MAX_RECT_ERROR    (0.7F)          /*!< Max rectification error to use POD obj */

#define VISCR_DEPTH_INIT_CYCLES       (250U)          /*!< Min init cycle to enable usage of radar bases yaw angle delta */

#define VISCR_DEPTH_LIMIT_OBJ_CHANGES (100U)          /*!< Limit obj change counter */
#define VISCR_DEPTH_MAX_OBJ_CHANGES   (15.0F)         /*!< Max Object changes, if reached the quality is no more reduced */
#define VISCR_DEPTH_MIN_OBJ_CHANGES   (0.0F)          /*!< Min ob changes */

#define VISCR_DEPTH_REINIT_REDUCE_FAC (0.05)          /*!< */

#define VISCR_DEPTH_MIN_QUALITY       (0.0F)          /*!< Min qualiy */
#define VISCR_DEPTH_HALF_QUALITY      (VISCR_DEPTH_MAX_QUALITY/2.0F)  /*!< Half quality */
#define VISCR_DEPTH_MAX_QUALITY       (1.0F)          /*!< Max quality */

#define VISCR_DEPTH_MIN_DIST_MEAN     (2.0F)          /*!< Min mean distance between radar and stereo, -> max quality */
#define VISCR_DEPTH_MAX_DIST_MEAN     (6.0F)          /*!< Max mean distance between radar and stereo, -> min quality */

#define VISCR_DEPTH_MIN_YAW_DEV       DEG2RAD(0.01F)  /*!< Min standard deviation of yaw angle delta, -> max quality */
#define VISCR_DEPTH_MAX_YAW_DEV       DEG2RAD(0.05F)  /*!< Max standard deviation of yaw angle delta, -> min quality */

#define VSICR_DEPTH_MAX_RA_ST_DIST    (40.0F)          /*!> Max distance between the radar and the stereo object systematic error*/
#define VSICR_DEPTH_MAX_DIST_CYCLES   (1000U)         /*!> Max cycle for distance between the radar and the stereo object over the above threshold systematic error*/

#define VSICR_DEPTH_YAW_QUANTILE_LOW  (0.3F)          /*!> Lower limit of quantile for corrected yaw angle */
#define VSICR_DEPTH_YAW_QUANTILE_UP   (0.701F)        /*!> Upper limit of quantile for corrected yaw angle */

namespace SAC
{
  class Depth
  {
  public:
    /* Default constructor to silence the compiler. */
    Depth() {}
    ~Depth() {}
    void init(void);

    void run( const SACRadarDistInput_t * const pRadarObj, const SACStereoDistInput_t * const pStereoObj, f32_t const baseline, f32_t const XPosMounting, f32_t const velocity, f32_t const yawrate, f32_t const RectError);
/* ~CodeReview ~ID:ca71d3a04f13b60bb373b214783bb638 ~Reviewer:CW01\uidv0048 ~Date:6/28/2012 ~Priority:3 ~Comment:Remove dead code for readability */
#if 0 // CODE NOT USED
    f32_t get_delta_yaw_last(void) const;
    f32_t get_delta_yaw_mean(void) const;
    f32_t get_delta_yaw_dev(void) const;
    f32_t get_delta_yaw_quality() const;
#endif    
    bool_t get_tempmodel_yaw_angle(SACDepthYawAngleOutput_t * const pAngleOutput);
    bool_t get_yaw_angle(const fAngle_t fAngle, const fAngle_t fTempModelYawAngle, SACDepthYawAngleOutput_t * const pAngleOutput);
    void blend_yaw_angle_with_tempmodel(const fAngle_t fAngleInput, const fAngle_t fTempModelYawAngle, SACDepthYawAngleOutput_t  * const pAngleOutput);

    i32_t get_error_code(void) const;

    void exit(void) const;
    const SACDepthYawAngleData_t * get_private_data(void) const;

  private:
    i32_t limitations(const SACRadarDistInput_t * const pRadarObj, const SACStereoDistInput_t * const pStereoObj, const f32_t velocity, const f32_t yawrate, const f32_t RectError);
    i32_t check(const SACRadarDistInput_t * const pRadarObj, const SACStereoDistInput_t * const pStereoObj,const f32_t baseline, const f32_t velocity, const f32_t yawrate, const f32_t RectError);
    bool_t calc_delta_median(void);
    bool_t calc_distance_median(void);
    void calc_yaw_angle_delta(const f32_t radarDistance, const f32_t stereoDistance, const f32_t baseline, const f32_t XPosMounting);
    void calc_quality(const SACStereoDistInput_t * const pStereoObj);
    SAC::Intervall m_Intervall;
    SACDepthYawAngleData_t    m_DepthYawAngleData;
    RingBuffer                m_RingBuffer;
    bool_t                    m_CurrentObjYawAngleUpdated;
  };
}

#endif

