/*! \file **********************************************************************

  COMPONENT:              VDY (Vehicle Dynamics Observer)

  MODULENAME:             vdy_velcor.c

  @brief                  This module contains ego velocity correction factor
                          estimation. Correction factor matches velocity of 
                          stationary obstacles with vehicle velocity measured 
                          by wheel speed sensors.

  VERSIONNUMBER:          $Revision: 1.10 $

  CHANGES:
  ---*/ /*---
  CHANGE:           $Log: vdy_velcor.c  $
  CHANGE:           Revision 1.10 2019/06/11 08:36:20CEST Chinnaswamy, Ramachandra (uids4735) (uids4735) 
  CHANGE:           QAF Fixes
  CHANGE:           Revision 1.9 2019/04/15 07:42:36CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Implementation of L3_ALGO_VDY_1731
  CHANGE:           Revision 1.8 2019/03/13 12:24:15CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Meas opitimization and vdy memset definition
  CHANGE:           Revision 1.7 2019/01/31 07:25:30CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Design Update
  CHANGE:           Revision 1.6 2019/01/26 21:24:11CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Followed camel case convention for methods
  CHANGE:           Revision 1.5 2019/01/21 09:05:50CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           VDY Velocity Qualifier set to DECREASED State in case of NA or Not Confirmed NVM 
  CHANGE:           No fallback once Velocity Correction Quality set to VERIFIED
  CHANGE:           Revision 1.4 2018/09/17 14:00:05CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Support for courage environment: Defined STATIC_VAR
  CHANGE:           Revision 1.3 2018/09/12 16:23:18CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Support for courage environment
  CHANGE:           Revision 1.2 2018/08/24 15:18:57CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           VelCorr Update
  CHANGE:           Revision 1.1 2018/08/09 10:40:57CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           Initial revision
  CHANGE:           Member added to project /ADAS/SW/Components/VDY_VehicleDynamics/04_Engineering/01_Source_Code/VDY/vdy/project.pj
  CHANGE:           Revision 1.60.1.3.1.1 2018/07/25 11:48:54CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           VDY mearged code for ARS and MFC : Mainstream
  CHANGE:           Revision 1.60.1.3 2018/03/21 10:49:02CET Singh, Sanjiv (uidr1340) 
  CHANGE:           VDY should react with PlantMode and RTB mode similarly
  CHANGE:           Revision 1.60.1.2 2017/06/15 13:33:19CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           Fix for  VDY ego velocity correction factor deviation from ALN output
  CHANGE:           Revision 1.60.1.1 2017/03/31 05:32:57CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           Adaptation of latest VDY Base changes to ARS510
  CHANGE:           Revision 1.60 2017/03/10 12:44:49CET Berwal, Anuj (uidp1444) 
  CHANGE:           -QAC fixes
  CHANGE:           -Correction factor Start value & Bin width Macros are updated
  CHANGE:           Revision 1.59 2016/06/14 07:54:22CEST Mani, Yugesh (uidj6870) 
  CHANGE:           -Fixing of Module Testing finding of unreachable code
  CHANGE:           Revision 1.58 2016/03/02 15:26:22CET Mani, Yugesh (uidj6870) 
  CHANGE:           - Fixed QAC issues
  CHANGE:           - ABS and traction control timer threshold is set to 0 , From Custom it has to be changed for needed projects
  CHANGE:           Revision 1.57 2016/02/26 10:34:30CET Mani, Yugesh (uidj6870) 
  CHANGE:           - Enabled the VDY_FS_VEH_CORR_MON DEM when the CFG_VDY_FS_VELO_CORR_MON flag is active
  CHANGE:           Revision 1.56 2016/02/19 07:37:27CET Singh, Sanjiv (uidr1340) 
  CHANGE:           Adaptation/Deactivation of new functions for velocity corr for the camera projects.
  CHANGE:           where velo corr is not happening .
  CHANGE:           Revision 1.55 2016/02/15 11:08:40CET Mani, Yugesh (uidj6870) 
  CHANGE:           - To avoid the VDY_FS_VEH_CORR_MON vdy error toggling issue , hysteresis has been introduced
  CHANGE:           Revision 1.54 2016/02/04 08:53:08CET Mani, Yugesh (uidj6870) 
  CHANGE:           - New Velocity monitoring based on new minimum and maximum velocity signals
  CHANGE:           for ARS4D1 and ARS4D2
  CHANGE:           Revision 1.53 2015/10/17 15:18:50CEST Mani, Yugesh (uidj6870) 
  CHANGE:           - incorporating a function to compute the b_init_CorrFlag
  CHANGE:           
  CHANGE:           - Normal distribution to find the velocity variance till the ALN and VDY velocity is confirmed for the first time after startup
  CHANGE:           - Added comments -  uidj6870 [Oct 17, 2015 3:18:50 PM CEST]
  CHANGE:           Change Package : 387424:1 http://mks-psad:7002/im/viewissue?selection=387424
  CHANGE:           Revision 1.52 2015/08/19 18:17:42CEST Mani, Yugesh (uidj6870) 
  CHANGE:           Merged the Changes from 1.47.1.4
  CHANGE:           --- Added comments ---  uidj6870 [Aug 19, 2015 6:17:43 PM CEST]
  CHANGE:           Change Package : 369242:1 http://mks-psad:7002/im/viewissue?selection=369242
  CHANGE:           Revision 1.51 2015/06/23 09:16:24CEST Balachandra, Swathi (uidj2447) 
  CHANGE:           Limit output correction factor variance to max. reasonable value 0.0225, until sufficient number of stationary targets are detected for the first time
  CHANGE:           --- Added comments ---  uidj2447 [Jun 23, 2015 9:16:25 AM CEST]
  CHANGE:           Change Package : 255307:2 http://mks-psad:7002/im/viewissue?selection=255307
  CHANGE:           Revision 1.50 2015/04/22 15:53:06CEST Pakeer, Sudhakarreddy (uidj6215) 
  CHANGE:           ---> changes made for all projects compatibility
  CHANGE:           --- Added comments ---  uidj6215 [Apr 22, 2015 3:53:06 PM CEST]
  CHANGE:           Change Package : 320951:12 http://mks-psad:7002/im/viewissue?selection=320951
  CHANGE:           Revision 1.49 2015/04/22 13:57:05CEST Pakeer, Sudhakarreddy (uidj6215) 
  CHANGE:           ---. merging the roller test bench changes with the base line from version  1.45.1.1
  CHANGE:           --- Added comments ---  uidj6215 [Apr 22, 2015 1:57:05 PM CEST]
  CHANGE:           Change Package : 320951:12 http://mks-psad:7002/im/viewissue?selection=320951
  CHANGE:           Revision 1.48 2015/04/22 13:34:34CEST Mani, Yugesh (uidj6870) 
  CHANGE:           Changed  the corrected velocity variance as Non-Zero when calculated corrected velocity variance is Zero
  CHANGE:           --- Added comments ---  uidj6870 [Apr 22, 2015 1:34:34 PM CEST]
  CHANGE:           Change Package : 331094:1 http://mks-psad:7002/im/viewissue?selection=331094
  CHANGE:           Revision 1.47 2015/03/06 09:15:22CET Balachandra, Swathi (uidj2447) 
  CHANGE:           Addition of staring parameter for variance of velocity correction factor as 0.0225.
  CHANGE:           --- Added comments ---  uidj2447 [Mar 6, 2015 9:15:23 AM CET]
  CHANGE:           Change Package : 314123:1 http://mks-psad:7002/im/viewissue?selection=314123
  CHANGE:           Revision 1.46 2015/02/05 06:20:16CET Mani, Yugesh (uidj6870) 
  CHANGE:           Changed the maximum correction factor threshold from 10% to 15% for trucks
  CHANGE:           --- Added comments ---  uidj6870 [Feb 5, 2015 6:20:16 AM CET]
  CHANGE:           Change Package : 300040:1 http://mks-psad:7002/im/viewissue?selection=300040
  CHANGE:           Revision 1.45 2015/01/27 12:02:04CET Mani, Yugesh (uidj6870) 
  CHANGE:           QAC fix of velocity correction file
  CHANGE:           --- Added comments ---  uidj6870 [Jan 27, 2015 12:02:04 PM CET]
  CHANGE:           Change Package : 300000:2 http://mks-psad:7002/im/viewissue?selection=300000
  CHANGE:           Revision 1.44 2015/01/16 10:25:17CET Balachandra, Swathi (uidj2447) 
  CHANGE:           Fix for Compiling issues in SRR project
  CHANGE:           --- Added comments ---  uidj2447 [Jan 16, 2015 10:25:17 AM CET]
  CHANGE:           Change Package : 296635:2 http://mks-psad:7002/im/viewissue?selection=296635
  CHANGE:           Revision 1.43 2014/12/12 08:15:04CET Balachandra, Swathi (uidj2447) 
  CHANGE:           Updation on New velocity monitoring function forwheel-speed based ego-velocity vs. ego-speed from static radar objects with high (> 99%) availability
  CHANGE:           --- Added comments ---  uidj2447 [Dec 12, 2014 8:15:04 AM CET]
  CHANGE:           Change Package : 283384:4 http://mks-psad:7002/im/viewissue?selection=283384
  CHANGE:           Revision 1.42 2014/12/03 11:13:12CET Balachandra, Swathi (uidj2447) 
  CHANGE:           Fix for MISRA Violations
  CHANGE:           --- Added comments ---  uidj2447 [Dec 3, 2014 11:13:12 AM CET]
  CHANGE:           Change Package : 278585:1 http://mks-psad:7002/im/viewissue?selection=278585
  CHANGE:           Revision 1.41 2014/10/01 10:57:35CEST Wolter, Frank (wolterf) 
  CHANGE:           - variance of corrected velocity increases with higher velocities
  CHANGE:           --- Added comments ---  wolterf [Oct 1, 2014 10:57:36 AM CEST]
  CHANGE:           Change Package : 268402:1 http://mks-psad:7002/im/viewissue?selection=268402
  CHANGE:           Revision 1.40 2014/09/17 16:34:40CEST Wolter, Frank (wolterf) 
  CHANGE:           - calculating wheel yaw rate error in curve error
  CHANGE:           - set curve error limits if offset calculation is disabled
  CHANGE:           --- Added comments ---  wolterf [Sep 17, 2014 4:34:44 PM CEST]
  CHANGE:           Change Package : 259705:1 http://mks-psad:7002/im/viewissue?selection=259705
  CHANGE:           Revision 1.39 2014/09/05 14:47:01CEST Wolter, Frank (wolterf) 
  CHANGE:           - corrected function declaration for VDYFSCheckVelCorrMonitoring()
  CHANGE:           --- Added comments ---  wolterf [Sep 5, 2014 2:47:01 PM CEST]
  CHANGE:           Change Package : 259705:1 http://mks-psad:7002/im/viewissue?selection=259705
  CHANGE:           Revision 1.38 2014/09/05 13:41:44CEST Wolter, Frank (wolterf) 
  CHANGE:           - changed corrQual implementation:
  CHANGE:             - corrQual starts with 1 if a correction factor is stored in NVM
  CHANGE:             - the velocity is check done even if conditions for precise velocity correction factor calculation are not fullfilled
  CHANGE:           --- Added comments ---  wolterf [Sep 5, 2014 1:41:45 PM CEST]
  CHANGE:           Change Package : 259705:1 http://mks-psad:7002/im/viewissue?selection=259705
  CHANGE:           Revision 1.37 2014/08/28 12:08:44CEST Wolter, Frank (wolterf) 
  CHANGE:           - changed corrQual implementation: use FS limits and only reduce if outside limits for 400ms
  CHANGE:           - FSVelCorr fault inactive after first sample within limits
  CHANGE:           --- Added comments ---  wolterf [Aug 28, 2014 12:08:44 PM CEST]
  CHANGE:           Change Package : 259705:1 http://mks-psad:7002/im/viewissue?selection=259705
  CHANGE:           Revision 1.36 2014/08/28 10:00:28CEST Wolter, Frank (wolterf) 
  CHANGE:           - velocity histograms are discarded if 30% of samples are outside of histogram limits
  CHANGE:           --- Added comments ---  wolterf [Aug 28, 2014 10:00:29 AM CEST]
  CHANGE:           Change Package : 259142:1 http://mks-psad:7002/im/viewissue?selection=259142
  CHANGE:           Revision 1.35 2014/07/24 08:53:29CEST Wolter, Frank (wolterf) 
  CHANGE:           - removed double correction of velocity
  CHANGE:           --- Added comments ---  wolterf [Jul 24, 2014 8:53:30 AM CEST]
  CHANGE:           Change Package : 250600:1 http://mks-psad:7002/im/viewissue?selection=250600
  CHANGE:           Revision 1.34 2014/07/10 12:24:39CEST Wolter, Frank (wolterf) 
  CHANGE:           - correction of corrQual reduction
  CHANGE:           - check for VDY_FS_VEH_CORR_MON only if enabled in config
  CHANGE:           --- Added comments ---  wolterf [Jul 10, 2014 12:24:40 PM CEST]
  CHANGE:           Change Package : 245598:1 http://mks-psad:7002/im/viewissue?selection=245598
  CHANGE:           Revision 1.33 2014/07/08 12:35:42CEST Wolter, Frank (wolterf) 
  CHANGE:           - fault VDY_FS_VEH_CORR_MON reduces correction quality corrQual
  CHANGE:           - removed MISRA violations
  CHANGE:           --- Added comments ---  wolterf [Jul 8, 2014 12:35:43 PM CEST]
  CHANGE:           Change Package : 247013:1 http://mks-psad:7002/im/viewissue?selection=247013
  CHANGE:           Revision 1.32 2014/06/25 16:23:22CEST Wolter, Frank (wolterf) 
  CHANGE:           - storing of corrQual value in every case so that value 1 does not get lost 
  CHANGE:           - storing the information if an input velocity was available at least once in that running cycle and allow state 2 (confirmed) in that case.
  CHANGE:           --- Added comments ---  wolterf [Jun 25, 2014 4:23:22 PM CEST]
  CHANGE:           Change Package : 239134:1 http://mks-psad:7002/im/viewissue?selection=239134
  CHANGE:           Revision 1.31 2014/05/27 15:42:13CEST Wolter, Frank (wolterf) 
  CHANGE:           - removed possible out-of-array access when adding data into histogram
  CHANGE:           - corrected reduction of velocity correction corrQual from verified to not verified
  CHANGE:           --- Added comments ---  wolterf [May 27, 2014 3:42:13 PM CEST]
  CHANGE:           Change Package : 239730:1 http://mks-psad:7002/im/viewissue?selection=239730
  CHANGE:           Revision 1.30 2014/04/08 15:21:37CEST Wolter, Frank (wolterf) 
  CHANGE:           - input variances used in fast velocity monitor
  CHANGE:           - removed MISRA violations
  CHANGE:           - removed non-Autosar types
  CHANGE:           --- Added comments ---  wolterf [Apr 8, 2014 3:21:37 PM CEST]
  CHANGE:           Change Package : 226472:1 http://mks-psad:7002/im/viewissue?selection=226472
  CHANGE:           Revision 1.29 2014/02/24 09:11:40CET Wolter, Frank (wolterf) 
  CHANGE:           - faster confirmation of NVM correction factor qualifier
  CHANGE:           - implemented fast velocity check for ALN input
  CHANGE:           --- Added comments ---  wolterf [Feb 24, 2014 9:11:40 AM CET]
  CHANGE:           Change Package : 220996:1 http://mks-psad:7002/im/viewissue?selection=220996
  CHANGE:           Revision 1.28 2014/02/07 13:00:33CET Wolter, Frank (wolterf) 
  CHANGE:           - use of NVM state macros
  CHANGE:           --- Added comments ---  wolterf [Feb 7, 2014 1:00:34 PM CET]
  CHANGE:           Change Package : 217717:1 http://mks-psad:7002/im/viewissue?selection=217717
  CHANGE:           Revision 1.27 2014/01/29 09:23:41CET Wolter, Frank (wolterf) 
  CHANGE:           Replaced check of >0 with CML macro
  CHANGE:           --- Added comments ---  wolterf [Jan 29, 2014 9:23:41 AM CET]
  CHANGE:           Change Package : 215885:1 http://mks-psad:7002/im/viewissue?selection=215885
  CHANGE:           Revision 1.26 2014/01/08 16:06:13CET Wolter, Frank (wolterf) 
  CHANGE:           Check for division by 0 in VDYVelCorrCalc() in case inputs are corrupt
  CHANGE:           --- Added comments ---  wolterf [Jan 8, 2014 4:06:14 PM CET]
  CHANGE:           Change Package : 212620:1 http://mks-psad:7002/im/viewissue?selection=212620
  CHANGE:           Revision 1.25 2013/10/10 08:34:18CEST Wolter, Frank (wolterf) 
  CHANGE:           Added check if velocity greater 0 and deviation is low enough before using new data
  CHANGE:           --- Added comments ---  wolterf [Oct 10, 2013 8:34:18 AM CEST]
  CHANGE:           Change Package : 200127:1 http://mks-psad:7002/im/viewissue?selection=200127
  CHANGE:           Revision 1.24 2013/09/24 13:43:51CEST Wolter, Frank (wolterf) 
  CHANGE:           - switched types to Autosar types
  CHANGE:           - misra updates
  CHANGE:           - layout/spelling corrections
  CHANGE:           --- Added comments ---  wolterf [Sep 24, 2013 1:43:52 PM CEST]
  CHANGE:           Change Package : 188036:1 http://mks-psad:7002/im/viewissue?selection=188036
  CHANGE:           

*****************************************************************************/
/* ###Suggested TCI Code Review###:It is legacy code of ARS301 , alreay reviewed and working fine without any critical issue " */
/* PRQA S 3453 EOF */
/* ###Suggested TCI Code Review###:Legacy code of ARS301, reducing lines of code changes component structure." */
/* PRQA S 7013 EOF */
/* ###Suggested TCI Code Review###:Reducing complexity adds risk and effort." */
/* PRQA S 7004 EOF */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#define VDY_DACQ_IF   1L        /* Activate interface to internal data */
/* PRQA S 0380 EOF */
/* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: No Risk */
#include "vdy.h"

#if ( (defined(CFG_VDY_DO_VELOCITY_CORR)) && (CFG_VDY_DO_VELOCITY_CORR) )

/*****************************************************************************
  SYMBOLIC CONSTANTS
*****************************************************************************/

/* Define velocity ranges and bounds  */
#define VDY_CORR_VEL_RANGE_0_MIN        (fVelocity_t) (10.F/C_KMH_MS)
#define VDY_CORR_VEL_RANGE_0_MAX        (fVelocity_t) (60.F/C_KMH_MS)
#define VDY_CORR_VEL_RANGE_0_MID        (fVelocity_t) ((VDY_CORR_VEL_RANGE_0_MIN + VDY_CORR_VEL_RANGE_0_MAX) * 0.5F)

#define VDY_CORR_VEL_RANGE_1_MIN        VDY_CORR_VEL_RANGE_0_MAX
#define VDY_CORR_VEL_RANGE_1_MAX        (fVelocity_t) (140.F/C_KMH_MS)
#define VDY_CORR_VEL_RANGE_1_MID        (fVelocity_t) ((VDY_CORR_VEL_RANGE_1_MIN + VDY_CORR_VEL_RANGE_1_MAX) * 0.5F)

#define VDY_CORR_VEL_RANGE_2_MIN        VDY_CORR_VEL_RANGE_1_MAX
#define VDY_CORR_VEL_RANGE_2_MAX        (fVelocity_t) (240.F/C_KMH_MS)
#define VDY_CORR_VEL_RANGE_2_MID        (fVelocity_t) ((VDY_CORR_VEL_RANGE_2_MIN + VDY_CORR_VEL_RANGE_2_MAX) * 0.5F)

/* Per mill scale factor, use used to scale velocity thresholds befor checking, (ECU-SIL) */
#define VDY_CORR_PER_MILL_SCALE         (1000.0F)

/* Histogram bin width for velocity ratios ... BINS_CORR_FACTOR_STEP Macro is used in VDY instead of VDY_CORR_VEL_BIN_WIDTH */
/* #define VDY_CORR_VEL_BIN_WIDTH          ((REF_SPEED_MAX_RATIO - REF_SPEED_MIN_RATIO)/((float32) REF_SPEED_NO_BINS-1.F))  */

/* Minium ego velocity range for velocity dependency observability */
#define VDY_CORR_OBS_MIN_VEL_RG         (fVelocity_t)(20.F/C_KMH_MS)
/* Standard deviation at non-observeable velocity dependence */
#define VDY_CORR_OBS_STD_DEV            (0.03F/3.F)

/* Required number of samples for correction estimation */
#if (VEL_CORR_HIST_STATIONARY_TARGETS)
#define VDY_CORR_SPL_INIT               (4000UL)     /* Number of samples at init state   */
#define VDY_CORR_SPL_NORMAL             (8000UL)     /* Number of samples at other states */
#elif (VEL_CORR_ALN)
#define VDY_CORR_SPL_INIT               (200UL)     /* Number of samples at init state   */
#define VDY_CORR_SPL_NORMAL             (400UL)     /* Number of samples at other states */
#endif
#define VDY_CORR_SPL_OUTSIDE_LIMITS      (0.3F)     /* Percentage of samples allowed outside of histogram borders to still evaluate histogram */

/* Maximum allowed absolute correction factor deviation  */
#define VDY_CORR_ABS_DEV                VDY_PAR_VCOR_ABS_DEV
#define VDY_CORR_ABS_DEV_START          (0.45F)

/* Maximum allowed standard deviation of correction factor */
#define VDY_CORR_STD_DEV                (0.02F)

/* Correction factor for velocity variance */
#define VDY_CORR_VAR_CORRECT_FACTOR     (0.1F)

/* Reduction factors for collected  */
#define VDY_CORR_RED_FAC_INIT           (0.2F)   /* Reudction value at init state */
#define VDY_CORR_RED_FAC_NORMAL         (0.4F)   /* Reduction value at other states */

/* Required deviation to store new value in nv-memory */
#define VDY_CORR_NVM_FAC_DEV            (0.01F)

/* Init values for correction nodes */
#define VDY_CORR_INIT_STD_DEV_START     (VDY_CORR_ABS_DEV_START/3.F)           /* node standard deviation */
#ifndef VDY_CORR_INIT_STD_DEV
#define VDY_CORR_INIT_STD_DEV           (VDY_CORR_ABS_DEV/3.F)           /* node standard deviation */
#endif
#define VDY_CORR_INIT_VEL_NODE          ((fVelocity_t) (60.F/C_KMH_MS))  /* node average velocity   */

/* Minimum and maximum allowed state values */
/* Zero velocity intercept limit values */
#define VDY_CORR_ABS_ICT_MIN_VAL        (1.0F - VDY_CORR_ABS_DEV)
#define VDY_CORR_ABS_ICT_MAX_VAL        (1.0F + VDY_CORR_ABS_DEV)

/* Velocity dependency constraints values */
#define VDY_CORR_ABS_SLP_MAX_VAL        VDY_PAR_VCOR_VEL_DEP_MAX
#define VDY_CORR_ABS_SLP_MIN_VAL        VDY_PAR_VCOR_VEL_DEP_MIN

/* Maximum allowed magnitude of long. acceleration  for observability */
#define VDY_CORR_OBS_ACCEL_MAX          ((fAccel_t )(1.0F))

/* Maximum allowed magnitude of long. acceleration  for observability */
#define VDY_CORR_OBS_CURVE_MAX          ((fCurve_t )((1.F/200.F)))

/* Delay time for re-enter observability of ego velocity */
#define VDY_CORR_OBS_DELAY_TIME         (1000UL)

/* Correction factor estimator parameters */
#define VCOR_EST_CYCLE_TIME    (0.02F)                     /*!< Expected estimator cycle time */
#define VCOR_EST_K0_STD        (0.1F/3.0F)                /*!< Correction factor noise */
#define VCOR_EST_K1_STD        (0.000001F/3.0F)              /*!< Correction factor velocity gradient noise */

#define VCOR_EST_Q_DYN         (VCOR_EST_CYCLE_TIME/1E6F)      /*!< Correction factor model dynamic */
#define VCOR_EST_P_INIT_QFACT  (4E9F * VDY_PAR_VCOR_ABS_DEV)   /*!< Estimation coveriance initial factor value P_INIT = Q * FACT */
#define R_STD_DEV_FACT         (0.1F/1.0F)                     /*!< Measurement noise reduction factor for accumlated histograms  */

#define VCOR_ECU_ELPSD_TIME_MAX    (fTime_t)(10.0 * 24.0 * 60.0 * 60.0)  /*!< Maximum ECU running time 10 days         */
#define VCOR_NVM_WRITE_TIME_SPAN   (fTime_t)(120.0)                      /*!< Minimum time span between two nvm writes */

#if (CFG_VDY_FS_VELO_CORR_MON)
/* fast velocity correction factor fault monitor options */
/* configuration options */
#if ( (defined(VEL_CORR_HIST_STATIONARY_TARGETS)) && (VEL_CORR_HIST_STATIONARY_TARGETS) )
#define VEL_CORR_FS_MON_MAX_DEV        (0.15F)  /* max. deviation of velocity factor (defined in functional safety specification) */
#define VEL_CORR_FS_MON_MAX_COUNTER    (5u)     /* number of EM histograms used before reduced again (e.g. 5) */
#define VEL_CORR_FS_MON_REDUCTION      (0.2F)   /* reduction factor, depends on VEL_CORR_FS_MON_MAX_COUNTER (e.g. 0.2) */
#define VEL_CORR_FS_MON_MIN_NUMBER     (5.0F)   /* minimum number of samples to allow evaluation */
#define VEL_CORR_FS_MON_MIN_SA         (0.1F)   /* maximum allowed standard deviation of summed up histograms to allow evaluation */
#define VEL_CORR_FS_HIST_MAX_WIDTH     (19)     /* maximum width of input histogram (difference between first and last bin with at least one sample) */
#define VEL_CORR_FS_HIST_MIN_NUMBER    (3u)     /* minimum number of samples in input histogram */
#elif ( (defined(VEL_CORR_ALN)) && (VEL_CORR_ALN) )
#define VEL_CORR_FS_MON_MAX_COUNTER    (5u)     /* number of ALN inputs used before reduced again (e.g. 5) */
#define VDY_FS_VEL_MON_SIGMA           (4.0F)   /* measurement sigma for variance of velocity*/
#define VDY_FS_VEL_MON_MAX_VEL_DIFF    (2.0F)   /* maximum difference of radar target velocity and external velocity in m/s */

#define VDY_FS_VEL_CONF_MAX_VEL_DIFF   (1.0F)   /* maximum difference of radar confirmation velocity and corrected velocity in m/s */
#endif
#endif

#define MAX_COUNTER                    (10u)    /* number of VDY cycles till which VDY output velocity state should be DECREASED if (NVM CF - newly computed CF) * velocity at that instance > 1m/s */

#if ( (defined(CFG_VDY_TRUCK_CORRFACT)) && (CFG_VDY_TRUCK_CORRFACT) )
#define VDY_FS_VEL_MON_RAT_THRHD       (0.15F)   /* Ratio to determine threshold by means of absolute velocity for TRUCKS*/

#elif ( (defined(CFG_VDY_CORRFACT_ARS4D2)) && (CFG_VDY_CORRFACT_ARS4D2) )
#define VDY_FS_VEL_MON_RAT_THRHD       (0.3F)   /* Ratio to determine threshold by means of absolute velocity for ARS4D2*/

#else
#define VDY_FS_VEL_MON_RAT_THRHD       (0.1F)   /* Ratio to determine threshold by means of absolute velocity */

#endif

/*maximum vdy cycles to deactivate the output Velocity monitor when abs is active */
#ifndef OUTPUT_VEL_VAR_LIMITATION
#define OUTPUT_VEL_VAR_LIMITATION		(0.0F)
#endif


#if ( (CFG_VDY_FS_VELO_CORR_MON) || (VEL_CORR_ALN) )
/* non-configurable definitions */
#define BINS_CORR_FACTOR_STEP          (0.01F)  /* resolution of input histograms */
#define BINS_CORR_FACTOR_START_VALUE   (float32)(1.0F - ((((float32)REF_SPEED_NO_BINS-1.0f)/2.0f) * BINS_CORR_FACTOR_STEP))
#endif

/* Dimension of noise covariance matrix for estimator */
#define VDY_VCOR_DIM_COVAR_MATRIX      (4U)

#if ( (defined(VEL_CORR_ALN)) && (VEL_CORR_ALN) )
#define VDY_VCOR_NO_ALN_DATA_STD_DEV   (1E30F)  /* set by ALN as standard deviation if no velocity could have been calculated */
#endif
#define VEL_CORR_ALN_MON_MAX_COUNTER   (5U)

#if ( (defined(CFG_VDY_VELO_MONITOR_MIN_MAX)) && (CFG_VDY_VELO_MONITOR_MIN_MAX) )
/*values used for Interpolation to deactivate the VEL_MON and VEL_MONLT DEM */
#define VDY_INTERPOL_VEL_RANGE_MIN          (fVelocity_t) (0.F)           /* minimum velocity  input for interpolation */
#define VDY_INTERPOL_VEL_RANGE_MAX          (fVelocity_t) (100.F/C_KMH_MS) /* Maximum velocity  input for interpolation */
#define VDY_INTERPOL_ACCEL_RANGE_MIN        ((fAccel_t )(4.2F))           /* minimum Acceleration  input for interpolation */
#define VDY_INTERPOL_ACCEL_RANGE_MAX        ((fAccel_t )(2.8F))           /* Maximum Acceleration  input for interpolation */
#define VDY_DECELERATION_RANGE_MAX          ((fAccel_t )(-5.0F))          /* Maximum Acceleration  input for interpolation */
#endif

/*****************************************************************************
  MACROS
*****************************************************************************/
#define COR_GET_ME()                  (&VDYVelCorr)                           /* MISRA Rule 19.7: reviewer name: Jochen Spruck date: 30-09-2010 reason: proven in use */
#define COR_GET_HISTS()               (&VDYVelCorr.Hist[0])                   /* MISRA Rule 19.7: reviewer name: Jochen Spruck date: 30-09-2010 reason: proven in use */
#define COR_GET_NODES()               (&VDYVelCorr.Node[0])                   /* MISRA Rule 19.7: reviewer name: Jochen Spruck date: 30-09-2010 reason: proven in use */
#define COR_GET_EST()                 (&VDYVelCorr.Est)                       /* MISRA Rule 19.7: reviewer name: Jochen Spruck date: 30-09-2010 reason: proven in use */
#define COR_SET_ERR_FACT_RG(state_)   (*VDYVelCorr.Io.errFactRg = (state_))   /* MISRA Rule 19.7: reviewer name: Jochen Spruck date: 30-09-2010 reason: proven in use */
#define COR_SET_ERR_WIN(state_)       (*VDYVelCorr.Io.errWin    = (state_))   /* MISRA Rule 19.7: reviewer name: Jochen Spruck date: 30-09-2010 reason: proven in use */



/*****************************************************************************
  TYPEDEFS
*****************************************************************************/
/*! Map to assign ego velocity ranges */
typedef struct
{
  fVelocity_t min;     /*!< Lower bound velocity of range */
  fVelocity_t mid;     /*!< Mean velocity of range */
  fVelocity_t max;     /*!< Upper bound velocity of range */
} VDYVelCorrRgMap_t;

/*****************************************************************************
  CONSTS
*****************************************************************************/

STATIC_VAR const VDYVelCorrRgMap_t VDYVelCorrRgMap_c[VDY_CORR_VEL_RANGES] =
{
  {VDY_CORR_VEL_RANGE_0_MIN, VDY_CORR_VEL_RANGE_0_MID, VDY_CORR_VEL_RANGE_0_MAX},
  {VDY_CORR_VEL_RANGE_1_MIN, VDY_CORR_VEL_RANGE_1_MID, VDY_CORR_VEL_RANGE_1_MAX},
  {VDY_CORR_VEL_RANGE_2_MIN, VDY_CORR_VEL_RANGE_2_MID, VDY_CORR_VEL_RANGE_2_MAX}
};

/* Estimator process noise covariance matrix */
STATIC_VAR const fVariance_t Q_c[VDY_VCOR_DIM_COVAR_MATRIX] =
{ 
  SQR(VCOR_EST_K0_STD) * VCOR_EST_Q_DYN,     /*!< K0 variance       */
  0.F,                                       /*!< K0,K1 covariance  */
  0.F,                                       /*!< K1,K0 covariance  */
  SQR(VCOR_EST_K1_STD) * VCOR_EST_Q_DYN      /*!< K1 variance       */
};


/*****************************************************************************
  VARIABLES
*****************************************************************************/
#if (CFG_VDY_DO_VELOCITY_CORR)
SET_MEMSEC_VAR(VDYVelCorr)
STATIC_VAR VDYVelCorr_t VDYVelCorr;        
#if (CFG_VDY_FS_VELO_CORR_MON)
SET_MEMSEC_VAR(VDYFSVelCorrMon)
STATIC_VAR VDYFSVelCorrMon_t VDYFSVelCorrMon;        
#endif
#endif
STATIC_VAR uint8 cntSampleOld;
STATIC_VAR boolean b_init_CorrFlag;
STATIC_VAR float32 NVMCorrFact;
STATIC_VAR boolean b_NVMAndNewCFRangeFailed;
STATIC_VAR boolean b_NVMAndNewCFCheckDone;
STATIC_VAR uint8 u_TakeoverCounter;
STATIC_VAR uint8 u_count;
STATIC_VAR boolean b_firstNewCFLearned;
STATIC_VAR VDYIoStateTypes_t u_lastVelocityIOstate;
STATIC_VAR boolean u_noFallbackVelState;

#if ( (defined(CFG_VDY_VELO_MONITOR_MIN_MAX)) && (CFG_VDY_VELO_MONITOR_MIN_MAX) )
STATIC_VAR uint32 u_debounceCounter_set;
STATIC_VAR uint32 u_debounceCounter_Reset;
#endif

#if (ALN_MONITORING_VERSION > 3U) && (CFG_VDY_FS_VELO_CORR_MON)
STATIC_VAR uint8 u_ConfCounterOld;
#endif

STATIC_VAR uint16 u_velVarianceCounter_ABS ;
STATIC_VAR uint16 u_velVarianceCounter_TSC ;
STATIC_VAR uint8  u_vel_corr_mon ;
STATIC_VAR uint8 u_noFallBack_CF_Quality;
/*****************************************************************************
  LOCAL FUNCTION PROTOTYPES
*****************************************************************************/
STATIC_MTD void VDYVelCorrExecEstimator(const VDYVelCorrNode_t *node, VDYVelCorrEst_t *est, boolean mupdt);
STATIC_MTD void VDYVelCorrCalcResult(const VDYVelCorrEst_t *est, VDYModIf_t *mif,const reqVdyPrtList_t *reqPorts );
STATIC_MTD void VDYVelCorrInitEstimator(VDYVelCorrEst_t *est);
STATIC_MTD void VDYVelCorrInitCovEstimator(VDYVelCorrEst_t *est);
STATIC_MTD boolean VDYVelCorrOverTake(VDYRefSpeed_t *ref, VDYVelCorrNode_t *node, VDYVelCorrAux_t *pAux) ;
STATIC_MTD void VDYVelCorrHistInit(VDYRefSpeed_t ref[]);
STATIC_MTD void VDYVelCorrNodeInit(VDYVelCorrNode_t node[]);
STATIC_MTD boolean VDYVelCorrCalc(VDYRefSpeed_t *ref, uint32 start, uint32 end);
STATIC_MTD boolean VDYVelCorrEvalHist(VDYRefSpeed_t *ref);

#if ( (defined(CFG_VDY_VELO_MONITOR_MIN_MAX)) && (CFG_VDY_VELO_MONITOR_MIN_MAX) )
STATIC_MTD void VDYCorrectedVeloMonitoring (const VDYInputData_t *input , const proVdyPrtList_t *proPorts, VDYModIf_t *mif);
#endif

STATIC_MTD uint32 VDYVelCorrGetVelocityIndex(fVelocity_t Velocity);
#if (VEL_CORR_HIST_STATIONARY_TARGETS)
STATIC_MTD void VDYVelCorrAdd(const RefSpeed_t *refin, VDYRefSpeed_t *ref);
#elif (VEL_CORR_ALN)
STATIC_MTD void VDYVelCorrAdd(const ALN_Monitoring_t *refin, VDYRefSpeed_t *ref);
#endif
STATIC_MTD void VDYVelCorrSaveNvm(VDYVelCorrNode_t node[], fTime_t EcuTime, const VDYNvIoData_t *nv_read, VDYNvIoData_t *nv_write);
STATIC_MTD void VDYVelCorrReduce(VDYRefSpeed_t *ref, float32 reduce);
STATIC_MTD boolean VDYVelCorrReadNvm(VDYVelCorrNode_t node[], const VDYNvIoData_t *nv_read);
STATIC_MTD void VDYVelCorrAuxInit(VDYVelCorrAux_t *aux);
STATIC_MTD boolean VDYVelCorrIsObservable(const VDYModIf_t *mif, VDYVelCorrAux_t *pAux);

STATIC_MTD boolean VDYVelCorrStateInsideLimits(const VDYVelCorrEst_t *est);
STATIC_MTD void VDYVelCorrGetNodesAside(uint32 idx, uint32 nidx[]);

#if (CFG_VDY_FS_VELO_CORR_MON)
#if (ALN_MONITORING_VERSION > 3U) &&(VEL_CORR_ALN)
STATIC_MTD void VDYFSCheckVelCorrMonitoring(float32 f_CorrectedVelocity, float32 f_CorrectedVelocityVar, float32 f_ALNVelocity, float32 f_ALNVelocityDev, boolean b_EMProbRTBRecog, const VDYInputData_t *input);
STATIC_MTD void VDYFSConfirmVelocity(float32 f_CorrectedVelocity, float32 f_CorrectedVelocityVar, float32 f_ALNVelocity, boolean b_EMProbRTBRecog, const VDYInputData_t *input);
#endif
#elif(!CFG_VDY_FS_VELO_CORR_MON)
STATIC_MTD void VDYUncorrVelMonitoring(float32 f_UncorrectedVelocity, float32 f_UncorrectedVelocityVar, float32 f_ALNVelocity, float32 f_ALNVelocityDev);
#endif


#if (CFG_VDY_FS_VELO_CORR_MON)
/* **********************************************************************
  @fn                     VDYFSVelCorrMonGetPrivateData */ /*!
  @brief                  Get access to internal velocity correction monitor data

  @description            Returns pointer to data to allow MTS output

  @param[in]              -
  @param[out]             -
  @return                 *VDYFSVelCorrMon_t

  @pre                    -
  @post                   -
**************************************************************************** */
VDYFSVelCorrMon_t *VDYFSVelCorrMonGetPrivateData(void)
{
  return (&VDYFSVelCorrMon);
}
#endif


/* **********************************************************************
  @fn                     VDYVelCorrGetPrivateData */ /*!
  @brief                  Get access to internal velocity correction data

  @description            Returns pointer to data to allow MTS output

  @return                 *VDYVelCorr_t
  @param[in]              -
  @param[out]             -

  @pre                    -
  @post                   -
**************************************************************************** */
VDYVelCorr_t *VDYVelCorrGetPrivateData(void)
{
  return (COR_GET_ME());
}


/* **********************************************************************
  @fn               VDYVelCorrGetSpeedIndex */ /*!
  @brief            Get array index for specified velocity

  @description      

  @param[in]        Velocity
  @param[out]       -
  @return           index

  @pre              -
  @post             -
**************************************************************************** */
STATIC_MTD uint32 VDYVelCorrGetVelocityIndex(fVelocity_t Velocity)
{
  uint32 idx;
  fVelocity_t fScaleVelo = Velocity*VDY_CORR_PER_MILL_SCALE;
  uint32 uiScaleVelocity = (uint32)(fScaleVelo);

  if (uiScaleVelocity < (uint32)(VDY_CORR_VEL_RANGE_0_MAX*VDY_CORR_PER_MILL_SCALE) )
  {
    idx = 0UL;
  }
  else if (uiScaleVelocity < (uint32)(VDY_CORR_VEL_RANGE_1_MAX*VDY_CORR_PER_MILL_SCALE) )
  {
    idx = 1UL;
  }
  else
  {
    idx = 2UL;
  }
  return idx;
}


/* **********************************************************************
  @fn               VDYVelCorrEvalHist */ /*!
  @brief            Evaluate velocity correction histogram

  @description      Sorts histogram
                    highest bin index contains max number, is always > 0
                    if histogram is not empty (must be ensured by caller)
                    If difference of highest to second highest and highest to third highest
                    bin values are within limits and the histogram can be evaluated

  @param[in]        Velocity
  @param[out]       -
  @return           void

  @pre              -
  @post             -
**************************************************************************** */
STATIC_MTD boolean VDYVelCorrEvalHist(VDYRefSpeed_t *ref)
{
  const uint32 minIdxRat_c = 10UL;                                /* Minimum histogram index location for maximum = 0.7 */
  const uint32 maxIdxRat_c = (uint32)(REF_SPEED_NO_BINS) - 10U;   /* Maximum histogram index loaction for maximum = 1.3 */
  const uint32 winWidth_c  = 10UL;                                /* Window width for distribution evaluation */

  /* Parameters to test against normal distribution */
  const fRatio_t rat2ndPeak_c = 0.7F;    /* Ratio between second highest and hightest bin occurrences */
  const fRatio_t rat3rdPeak_c = 0.5F;    /* Ratio between third highest and highest bin occurences */
  const sint32 span2ndPeak_c = 2L;        /* Distance between second highest and hightest value */
  const sint32 span3rdPeak_c = 4L;        /* Distance between third highest and hightest value */

  boolean ret = FALSE;
  uint8 sortIdx[REF_SPEED_NO_BINS];
  uint32 idxMax, idxMax_1, idxMax_2;
  boolean Condition1, Condition2;

#if (VEL_CORR_HIST_STATIONARY_TARGETS)
  vdyHpSortIndU16((uint32)(REF_SPEED_NO_BINS), ref->binVelRatio, sortIdx);
#elif (VEL_CORR_ALN)
  vdyHpSortIndF32((uint32)(REF_SPEED_NO_BINS), ref->binVelRatio, sortIdx);
#endif

  idxMax   = sortIdx[(uint32)(REF_SPEED_NO_BINS) - 1U];  
  idxMax_1 = sortIdx[(uint32)(REF_SPEED_NO_BINS) - 2U];
  idxMax_2 = sortIdx[(uint32)(REF_SPEED_NO_BINS) - 3U];

  /* check first max to max */
  if (CML_f_IsNonZero(ref->binVelRatio[idxMax]))
  {
    if (((float32)ref->binVelRatio[idxMax_1] / (float32)ref->binVelRatio[idxMax]) > rat2ndPeak_c)
    {
      if (iABS((sint32)idxMax - (sint32)idxMax_1) < span2ndPeak_c)
      {
        Condition1 = TRUE;
      }
      else
      {
        Condition1 = FALSE;
      }
    }
    else
    {
      Condition1 = TRUE;
    }

    /* check second max to max */
    if (((float32)ref->binVelRatio[idxMax_2] / (float32)ref->binVelRatio[idxMax]) > rat3rdPeak_c)
    {
      if (iABS((sint32)idxMax - (sint32)idxMax_2) < span3rdPeak_c)
      {
        Condition2 = TRUE;
      }
      else
      {
        Condition2 = FALSE;
      }
    }
    else
    {
      Condition2 = TRUE;
    }
  }
  else  /* if (CML_f_IsNonZero(ref->binVelRatio[idxMax])) */
  {
    Condition1 = FALSE;
    Condition2 = FALSE;
  }

  if ( (Condition1 == TRUE) && (Condition2 == TRUE) )
  {
    /* significant peaks are close together */
    if ( (idxMax >= minIdxRat_c) && (idxMax <= maxIdxRat_c))
    {
      ret = VDYVelCorrCalc(ref, idxMax - winWidth_c, idxMax + winWidth_c);
    }
  }

  return ret;
}


/* **********************************************************************
  @fn               VDYVelCorrCalc */ /*!
  @brief            Calculate correction value from accumulated histogram data

  @description      Finds the median of the quartiles (1 to 3) and calculates
                    the median of the quartiles
                    The bin value of the median bin can not be 0 unless the histogram
                    is empty (must be ensured by caller).
					Bin values can have very small values, but negative values are not possible.

  @param[in]        ref speed histogram
  @param[in]        start
  @param[in]        end
  @return           void

  @pre              -
  @post             -
**************************************************************************** */
STATIC_MTD boolean VDYVelCorrCalc(VDYRefSpeed_t *ref, uint32 start, uint32 end)
{
  const float32 bwdth_c = BINS_CORR_FACTOR_STEP;
  boolean bSuccess;

  float32  volSum = 0.F;
  float32 ivSum = 0.F;
  uint32  idx;
  float32 rank;

  float32 val_q1, val_q2, val_q3; /* quartile values */

  boolean checkagain;
  
  /* First bin exceeding accumulated sum is first quartile */
  for (idx=start; idx <= end; idx++)
  {
    ivSum += (float32) ref->binVelRatio[idx];
  }
  
  /* Calculate first quartile */
  rank = 0.25F * ivSum;
  
  /* First bin exceeding accumulated sum is first quartile */  
  // To avoid floating point comparison in for loop Misra issue using checkagain 
  checkagain = (boolean)(volSum < rank);
  for (idx=start; (idx <= end) && (checkagain == TRUE); idx++) 
  {
    volSum += (float32) ref->binVelRatio[idx];
	checkagain = (boolean)(volSum < rank);
  }

  /* Get first quartile range */
  idx--;
  val_q1 = ((float32)(idx) * bwdth_c) + BINS_CORR_FACTOR_START_VALUE;

  /* Improve value by linear interpolation */
  if (CML_f_IsNonZero(ref->binVelRatio[idx]))
  {
    val_q1 += (-0.5F * bwdth_c) + ((((rank - (volSum - (float32) ref->binVelRatio[idx])) - 0.5F) * bwdth_c) / (float32) ref->binVelRatio[idx]);

    /* Calculate second quartile -> median */
  
    /* First bin exceeding accumulated sum is median */  
    rank = 0.5F * ivSum;
	// To avoid floating point comparison in for loop Misra issue using checkagain
	checkagain = (boolean)(volSum < rank);
    for ( idx++; (idx <= end) && (checkagain == TRUE); idx++)  
    {
      volSum += (float32) ref->binVelRatio[idx];
	  checkagain = (boolean)(volSum < rank);
    }

    /* Get median range value */
    idx--;
    val_q2 = ((float32)(idx) * bwdth_c) + BINS_CORR_FACTOR_START_VALUE;

    /* Improve value by linear interpolation */
    if (CML_f_IsNonZero(ref->binVelRatio[idx]))
    {
      val_q2 += (-0.5F * bwdth_c) + ((((rank - (volSum - (float32)ref->binVelRatio[idx])) - 0.5F) * bwdth_c) / (float32)ref->binVelRatio[idx]);

      /* Calculate third quartile */
      rank = 0.75F * ivSum;
	  // To avoid floating point comparison in for loop Misra issue using checkagain
	  checkagain = (boolean)(volSum < rank);
      for ( idx++; (idx <= end) && (checkagain == TRUE); idx++)  
      {
        volSum += (float32) ref->binVelRatio[idx];
		checkagain = (boolean)(volSum < rank);
      }

      /* Get third quartile range value */
      idx--;
      val_q3 = ((float32)(idx) * bwdth_c) + BINS_CORR_FACTOR_START_VALUE;

      if (CML_f_IsNonZero(ref->binVelRatio[idx]))
      {
        /* Improve value by linear interpolation */
        val_q3 += (-0.5F * bwdth_c) + ((((rank - (volSum - (float32) ref->binVelRatio[idx])) - 0.5F) * bwdth_c) / (float32) ref->binVelRatio[idx]);

        /* Assign median value */
        ref->Median =  val_q2;
  
        /* Assign pseude standard deviation */  
        ref->Dev    =  0.7413F * (val_q3 - val_q1);

        /* Calculate average ego velocity */
        vdyStatIntervalMeanDev(&ref->EgoVel);
        bSuccess = TRUE;
      }
      else
      {
        bSuccess = FALSE;
      }
    }
    else
    {
      bSuccess = FALSE;
    }
  }
  else
  {
    bSuccess = FALSE;
  }
  
  return bSuccess;
}


#if (VEL_CORR_HIST_STATIONARY_TARGETS)
/* **********************************************************************
  @fn               VDYVelCorrHistAdd */ /*!
  @brief            Insert new histogram into long-term histogram

  @description       

  @param[in]        refin one shot histogram address
  @param[out]       ref   long term histogram address

  @return           void

  @pre              -
  @post             -
**************************************************************************** */
STATIC_MTD void VDYVelCorrAdd(const RefSpeed_t *refin, VDYRefSpeed_t *ref)
{
  uint32 idx;
  float32 locSum = 0.F;

  /* Step through all bins and add bin und total occurences */
  for (idx=0UL; idx < (uint32)(REF_SPEED_NO_BINS); idx++)
  {
    ref->binVelRatio[idx] = (ui16_t) (ref->binVelRatio[idx] + refin->binVelRatio[idx]);
    locSum               += (float32) refin->binVelRatio[idx];
  }

  /* Accumulate total target counts */
  ref->Sum += locSum;

  /* Accumulate target occurences outside observation interval */
  ref->binVelRatOutLo = (ui16_t) (refin->binVelRatOutLo + ref->binVelRatOutLo);
  ref->binVelRatOutHi = (ui16_t) (refin->binVelRatOutHi + ref->binVelRatOutHi);

  /* Add reference ego velocity to statistical observation */
  vdyStatIntervalAdd(&ref->EgoVel, refin->refEgoVelo, locSum);

  /* Store sample counter to identify used input histogram */
  ref->cntSample = refin->cntSample;

  return;
}


#elif (VEL_CORR_ALN)
/* **********************************************************************
  @fn               VDYVelCorrHistAdd */ /*!
  @brief            Insert new histogram into long-term histogram

  @description       

  @param[in]        refin  : estimated ego speed from stationary targets of current radar cycle
  @param[in]        ref    : estimated standard deviation of estimated ego speed
  @param[out]       -
  @return           void

  @pre              -
  @post             -
**************************************************************************** */
STATIC_MTD void VDYVelCorrAdd(const ALN_Monitoring_t  *refin, VDYRefSpeed_t *ref)
{

  sint32  idx;            /* histogram index (bin) of the correction factor */
  float32 locSum = 1.0F;  /* number of samples, currently just on sample is provided (number of targets could be used, but must be provided by ALN) */
  float32 f_VelCorr;      /* correction factor of this cycle */
  
  /* possible division by zero, a check is implemented even if velocity must be higher than a minimum threshold to get here */
  if ( CML_f_IsNonZero(ref->EgoVel.Mean) )
  {
    f_VelCorr = refin->EgoSpeed.f_EgoSpeed / ref->EgoVel.Mean;

    /* calculate index */
    idx = (sint32)(((f_VelCorr - BINS_CORR_FACTOR_START_VALUE) / BINS_CORR_FACTOR_STEP)+0.5f);

    /* inside histogram borders? */
    if (idx >= 0)
    {
      if (idx < REF_SPEED_NO_BINS)
      {
        /* Add value to bin */
        ref->binVelRatio[idx] += (float32)(1.0 );  /* possible to use refin->f_EgoSpeedStandardDeviation as weight */
      }
      else
      {
        /* Accumulate occurences outside observation interval */
        ref->binVelRatOutHi++;
      }
    }
    else
    {
      /* Accumulate occurences outside observation interval */
      ref->binVelRatOutLo++;
    }

    /* Accumulate total count */
    ref->Sum++;  /* possible to use refin->f_EgoSpeedStandardDeviation as weight */

    /* Add reference ego velocity to statistical observation */
    vdyStatIntervalAdd(&ref->EgoVel, refin->EgoSpeed.f_EgoSpeed, locSum);

    /* Store sample counter to identify used input histogram */
    ref->cntSample = refin->EgoSpeed.u_UpdateCounter;
  }
  return;
}
#else
#ifdef _WIN32
/* <ln_offset:+1 PCLINT Error 975: reviewer name: Frank Wolter date: 08-07-2013 reason: message only */
#pragma message(__FILE__"("STRING_QUOTE(__LINE__)"): no velocity correction method defined")
#endif
#endif


/* **********************************************************************
  @fn               VDYVelCorrReduce */ /*!
  @brief            Reduce the observation database to avoid overflow

  @description       
  @param[in]        reduce reduction factor (0..1)
  @param[out]       ref long term histogram address
  @return           void

  @pre              -
  @post             -
**************************************************************************** */
STATIC_MTD void VDYVelCorrReduce(VDYRefSpeed_t *ref, float32 reduce)
{
  uint32 binNo;
  uint32 RoundVelRatio;

  /* Step through all bins and reduce occurences */
  for (binNo=0UL; binNo < (uint32)(REF_SPEED_NO_BINS); binNo++)
  {
    RoundVelRatio = ROUND_TO_UINT(reduce * (float32) ref->binVelRatio[binNo]); /* MISRA Rule 10.4: reviewer name: Jochen Spruck date: 06-12-2011 reason: issue due to use of global rounding macro */
    ref->binVelRatio[binNo] = (ui16_t)RoundVelRatio;
  }

  /* Reduce total occurences */
  ref->Sum *= reduce;
  ref->binVelRatOutHi = (ui16_t) 0UL;
  ref->binVelRatOutLo = (ui16_t) 0UL;

  /* Reduce ego velocity observation */
  vdyStatIntervalReduce(&ref->EgoVel, reduce);

  return;
}


/* **********************************************************************
  @fn               VDYVelCorrSaveNvm */ /*!
  @brief            Save learned values to non-volatile memory if necessary

  @description       

  @param[in]        node
  @param[in]        EcuTime
  @param[in]        nv_read
  @param[in]        nv_write
  @return           void

  @pre              -
  @post             -
**************************************************************************** */
STATIC_MTD void VDYVelCorrSaveNvm(VDYVelCorrNode_t node[], fTime_t EcuTime, const VDYNvIoData_t *nv_read, VDYNvIoData_t *nv_write)
{
  uint32 ii;

  /* Invalidate non volatile correction data */
  VDY_SET_NVM_IO_STATE(VDY_NVM_POS_VELCORR, VDY_IO_STATE_INVALID, &nv_write->State);

  /* Step through all velocity ranges */
  for (ii=0U; ii < VDY_CORR_VEL_RANGES; ii++)
  {
    /* Only use internal node values, if it has been learned since ignition start */
    if (node[ii].CorrDev < VDY_CORR_INIT_STD_DEV)
    {
      nv_write->VelCorr[ii].CorrFact = node[ii].CorrFact;
      nv_write->VelCorr[ii].Dev      = node[ii].CorrDev;
      nv_write->VelCorr[ii].Velo     = node[ii].CorrVel;
    }
    else
    {
      /* Node has not been learned, keep stored values */
      nv_write->VelCorr[ii] = nv_read->VelCorr[ii];
    }
  
    /* Store new correction node value if 
          deviation of new value is significant compared to stored values 
       or standard deviation of new value is better than stored one
       or velocity range has not been learned before
       and minimum time gap has been elapsed since last write cycle */
    if (  (  (CML_f_Abs(node[ii].CorrFact - nv_read->VelCorr[ii].CorrFact) > VDY_CORR_NVM_FAC_DEV)
           ||(node[ii].CorrDev < nv_read->VelCorr[ii].Dev) 
           ||(   (node[ii].CorrDev < VDY_CORR_INIT_STD_DEV)
              && ((nv_read->VelCorr[ii].Velo < VDYVelCorrRgMap_c[ii].min) || (nv_read->VelCorr[ii].Velo > VDYVelCorrRgMap_c[ii].max)) 
              &&((node[ii].CorrVel > VDYVelCorrRgMap_c[ii].min) && (node[ii].CorrVel < VDYVelCorrRgMap_c[ii].max))) )
        && ( (EcuTime - node[ii].LastNvmWrt) > VCOR_NVM_WRITE_TIME_SPAN ) )
    {
      
      /* Validate output nvm signal */
      /* <ln_offset:+2 PCLINT Error 845: reviewer name: Jochen Spruck date: 11-11-2010 reason: proven in use, error because state value is zero */
      /* <ln_offset:+1 PCLINT Error 835: reviewer name: Jochen Spruck date: 11-11-2010 reason: proven in use, error because state value is zero */
      VDY_SET_NVM_IO_STATE(VDY_NVM_POS_VELCORR, VDY_IO_STATE_VALID, &nv_write->State);
      
      /* update time since last write access */
      node[ii].LastNvmWrt = EcuTime;
    }
  }

  return;
}


/* **********************************************************************
  @fn               VDYVelCorrReadNvm */ /*!
  @brief            Read correction factor from non-volatile memory

  @description       

  @param[in]        node Correction node address
  @param[out]       nv_read Non-volatile data address
  @return           void

  @pre              -
  @post             -
**************************************************************************** */
STATIC_MTD boolean VDYVelCorrReadNvm(VDYVelCorrNode_t node[], const VDYNvIoData_t *nv_read)
{
  uint32 ii;
  boolean ret;
  boolean taken = FALSE;    /* Correction value taken from nv memory */
  boolean learned = FALSE;  /* New learn value at this ignition cycle available */

  if (VDY_GET_NVM_IO_STATE(VDY_NVM_POS_VELCORR, &nv_read->State) == VDY_IO_STATE_VALID)
  {    
    for (ii=0UL; ii < VDY_CORR_VEL_RANGES; ii++)
    {
      if (   (node[ii].State == (VDYCorrState_t) VEL_CORR_INIT) 
          && (nv_read->VelCorr[ii].Dev < node[ii].CorrDev) 
          && (nv_read->VelCorr[ii].Velo > 0.0F)  )
      {
        /*  Correction nodes have init-state and stored deviation is smaller than 
            current used deviation and it is not on NVM defaults */

        /* Take over non volalatile correction values */
        node[ii].State = (VDYCorrState_t) VEL_CORR_BACKUP;
        node[ii].CorrDev  =  nv_read->VelCorr[ii].Dev;

        /* Test whether the stored ego velocity is in expected range. During init 
           all three nodes are filled with same values. This prevents using this 
           on than more time */
        if (  (nv_read->VelCorr[ii].Velo > VDYVelCorrRgMap_c[ii].min) 
            &&(nv_read->VelCorr[ii].Velo < VDYVelCorrRgMap_c[ii].max) )
        {
          node[ii].CorrVel  =  nv_read->VelCorr[ii].Velo;
        }
        else
        {
          /* Velocity lies not inside the range, invalidate correction node by 
             initalization of standard deviation */
          node[ii].CorrVel  =  VDYVelCorrRgMap_c[ii].mid;
          node[ii].CorrDev  =  VDY_CORR_INIT_STD_DEV;
        }
        
        /* Test whether to stored correction factor is in expected range */
        if (  (nv_read->VelCorr[ii].CorrFact >= (1.F - VDY_CORR_ABS_DEV)) 
            &&(nv_read->VelCorr[ii].CorrFact <= (1.F + VDY_CORR_ABS_DEV)) )
        {
          node[ii].CorrFact =  nv_read->VelCorr[ii].CorrFact;
        }
        else
        {
          /* Factor lies not inside the range, invalidate correction node by 
             initalization of standard deviation */
          node[ii].CorrFact =  1.0F;
          node[ii].CorrDev  =  VDY_CORR_INIT_STD_DEV;
        }
        /* Signal that offset is taken from nvm memory */
        taken = TRUE;
      }
      /* Check if at least one new learn value has already been learned */
      if ((node[ii].State == (VDYCorrState_t) VEL_CORR_READY) || (node[ii].State == (VDYCorrState_t) VEL_CORR_STARTUP))
      {
        learned = TRUE;
      }
    }
  }

  /* Only init estimator if one nvm node was taken and no new learn has been learned so far */
  if ( (taken != FALSE) && (learned == FALSE) )
  {
    ret = TRUE;
  }
  else
  {
    ret = FALSE;
  }

  return ret;
}


/* **********************************************************************
  @fn               VDYVelCorrOverTake */ /*!
  @brief            Take over new correction value

  @description       

  @param[in]        ref
  @param[in]        node
  @param[in]        pAux
  @param[out]       --
  @return           void

  @pre              -
  @post             -
**************************************************************************** */
STATIC_MTD boolean VDYVelCorrOverTake(VDYRefSpeed_t *ref, VDYVelCorrNode_t *node, VDYVelCorrAux_t *pAux) 
{
  float32 volReq;
  float32 redFac;
  boolean success = FALSE;
  
  /* Required samples are dependent on current node state */
  if (node->State == (VDYCorrState_t) VEL_CORR_INIT)
  {
    volReq = (float32)(VDY_CORR_SPL_INIT);
    redFac = VDY_CORR_RED_FAC_INIT;
  }
  else
  {
    volReq = (float32)(VDY_CORR_SPL_NORMAL);
    redFac = VDY_CORR_RED_FAC_NORMAL;
  }

  /* If the majority of targets are outside the window */
  if (   (((float32)ref->binVelRatOutHi + (float32)ref->binVelRatOutLo) > (VDY_CORR_SPL_OUTSIDE_LIMITS * volReq))
      && (ref->Sum < (0.5F * volReq) ) )
  {  
    /* Correction value is out of expected range */
    pAux->cntMeasAmb++;

    /* Reduce amount of collected data */
    VDYVelCorrReduce(ref, 0.F);
  }
  else
  {
    /* If enough data is acquired to start evaluation */
    if (ref->Sum > volReq)
    {
      /* Calculate potential correction value */
      if (  (VDYVelCorrEvalHist(ref) != FALSE)
          &&(ref->Dev < VDY_CORR_STD_DEV)  )
      {
        /* Histogram provides clear distribution */
        /* Reset ambiguous meas error counter and indicate error inactive */
        if (pAux->cntMeasAmb > 0U )
        {
          pAux->cntMeasAmb--;
        }
        COR_SET_ERR_WIN(VDY_ERR_STATE_INACTIVE);

        if ( CML_f_Abs(ref->Median - 1.F) < VDY_CORR_ABS_DEV )
        {
          if (u_TakeoverCounter < 2)
          {
            u_TakeoverCounter++;
          }

          /* Estimation is good, take over learned values */
          node->CorrFact =  ref->Median;
          node->CorrDev  =  ref->Dev;
          node->CorrVel  =  ref->EgoVel.Mean;

          /* Promote learning state */
          if (node->State == (VDYCorrState_t) VEL_CORR_INIT)
          {
            node->State = (VDYCorrState_t) VEL_CORR_STARTUP;
          }
          else
          {
            node->State = (VDYCorrState_t) VEL_CORR_READY;
          }

          /* signal accepted overtake */
          success = TRUE;

          /* Correction factor is inside expectation range */
          if (pAux->cntMeasRng > 0U )
          {
            pAux->cntMeasRng--;
          }
          COR_SET_ERR_FACT_RG(VDY_ERR_STATE_INACTIVE);
        }
        else
        {
          /* Measured correction factor ouf range */
          pAux->cntMeasRng++;
        }
      }
      else
      {
        /* Distribution inside windows was discarded */
        pAux->cntMeasAmb++;
      }
      
      /* If distribution provides no useable result, discard it */
      if (success == FALSE)
      {
        redFac = 0.F;
      }
      
      /* Reduce amount of collected data */
      VDYVelCorrReduce(ref, redFac);
    }
  }

  /* If number of discarded histograms above threshold indicate error */
  if (pAux->cntMeasAmb >= VDY_PAR_VCOR_THRHD_CNT_MEAS_ERR)
  {
    COR_SET_ERR_WIN(VDY_ERR_STATE_ACTIVE);
    pAux->cntMeasAmb = MIN(pAux->cntMeasAmb, VDY_PAR_VCOR_THRHD_CNT_MEAS_ERR + 2U);
  }

  /* If number of measured correction factors out of range indicate error */
  if (pAux->cntMeasRng >= VDY_PAR_VCOR_THRHD_CNT_RANGE_ERR)
  {
    COR_SET_ERR_FACT_RG(VDY_ERR_STATE_ACTIVE);
    pAux->cntMeasAmb = MIN(pAux->cntMeasAmb, (VDY_PAR_VCOR_THRHD_CNT_RANGE_ERR + 1U));
  }

  return success;
}


/* **********************************************************************
  @fn               VDYVelCorrHistInit */ /*!
  @brief            Initialize histogram data

  @description       

  @param[in]        ref histogram address
  @param[out]       -
  @return           void

  @pre              -
  @post             -
**************************************************************************** */
STATIC_MTD void VDYVelCorrHistInit(VDYRefSpeed_t ref[])
{
  uint32 rgVel;
  uint32 rgBin;

  /* Step through all velocity ranges */
  for (rgVel=0UL; rgVel < VDY_CORR_VEL_RANGES; rgVel++)
  {
    /* Init histogram statistics */
    ref[rgVel].Dev    = 0.F;
    ref[rgVel].Median = 0.F;
    ref[rgVel].Sum    = 0.F;

    /* Init ego velocity statistics */
    vdyStatIntervalInit(&ref[rgVel].EgoVel);

    /* Initialize histogram bins */
    for (rgBin=0UL; rgBin < (uint32)(REF_SPEED_NO_BINS); rgBin++)
    {
      ref[rgVel].binVelRatio[rgBin] = (ui16_t) 0;
    }

    /* Initialize outside bins */
    ref[rgVel].binVelRatOutLo = (ui16_t) 0;
    ref[rgVel].binVelRatOutHi = (ui16_t) 0;

    /* Initialize sample counter of input histogram */
    ref[rgVel].cntSample = (uint8) 0;
  }
  return;
}


/* **********************************************************************
  @fn               VDYVelCorrNodeInit */ /*!
  @brief            Initialize correction node values

  @description       

  @param[in]        node correction node address
  @param[out]       -
  @return           void

  @pre              -
  @post             -
**************************************************************************** */
STATIC_MTD void VDYVelCorrNodeInit(VDYVelCorrNode_t node[])
{
  uint32 rgVel;

  /* Step through all velocity ranges */
  for (rgVel=0UL; rgVel < VDY_CORR_VEL_RANGES; rgVel++)
  {
    node[rgVel].CorrFact   = 1.F;
    node[rgVel].CorrDev    = VDY_CORR_INIT_STD_DEV;
    node[rgVel].CorrVel    = VDY_CORR_INIT_VEL_NODE;
    node[rgVel].State      = (VDYCorrState_t) VEL_CORR_INIT;
    node[rgVel].LastNvmWrt = -VCOR_NVM_WRITE_TIME_SPAN;
  }

  return;
}


/* **********************************************************************
  @fn               VDYVelCorrNodeInit */ /*!
  @brief            Initialize correction node values

  @description       

  @param[in]        aux correction node address
  @param[out]       -
  @return           void

  @pre              -
  @post             -
**************************************************************************** */
STATIC_MTD void VDYVelCorrAuxInit(VDYVelCorrAux_t *aux)
{
  aux->Timer      = 0UL;
  aux->maxVelMeas = 0.F;
  aux->minVelMeas = 0.F;
  aux->lastEgoVel = 0.F;
  aux->EcuTime    = 0.F;
  aux->cntMeasAmb = 0UL;
  aux->cntMeasRng = 0UL;

  return;
}


/* **********************************************************************
  @fn               VDYVelCorrInit */ /*!
  @brief            Initialize velocity correction module

  @description       

  @param[in]        mif
  @param[in]        proPorts
  @param[out]       -
  @return           void

  @pre              -
  @post             -
**************************************************************************** */
void VDYVelCorrInit(const proVdyPrtList_t *proPorts)
{
  /* Initialize velocity ratio histograms */  
  VDYVelCorrHistInit(COR_GET_HISTS());

  /* Initialize nodes for each velocity range  */
  VDYVelCorrNodeInit(COR_GET_NODES());

  /* Initialize estimator */
  VDYVelCorrInitEstimator(COR_GET_EST());

  /* Initialize auxillary data */
  VDYVelCorrAuxInit(&(COR_GET_ME()->Aux));

  /* Init velo correction quality */
  proPorts->pVehicleDynamicSignals->Longitudinal.VelocityCorrectionQuality = VDY_VELO_CORR_QUAL_SNA;

#if (CFG_VDY_FS_VELO_CORR_MON)
  /* Init fast velocity FS monitor */
  {
    VDYFSVelCorrMon_t    *pCorrMonData = VDYFSVelCorrMonGetPrivateData();
    (void)vdy_memset_s((void *)pCorrMonData, 0U, sizeof(VDYFSVelCorrMon_t));
  }
#endif

  /* reset static variables */
  cntSampleOld = 0U;
  /* b_init_CorrFlag to detect whether sufficient number of stationary targets are detected (sets TRUE when first time correction factor kalman filter updation happens)*/
  b_init_CorrFlag = FALSE;

  NVMCorrFact = 0.0f;
  b_NVMAndNewCFRangeFailed = FALSE;
  b_NVMAndNewCFCheckDone = FALSE;
  u_TakeoverCounter = 0U;
  u_count = 0;
  b_firstNewCFLearned = FALSE;
  u_lastVelocityIOstate = 0U;
  u_noFallbackVelState = FALSE;

#if ( (defined(CFG_VDY_VELO_MONITOR_MIN_MAX)) && (CFG_VDY_VELO_MONITOR_MIN_MAX) )
  /* reset the corrected velocity monitor DEM setting counter  */
  u_debounceCounter_set = 0U;
  u_debounceCounter_Reset = 0U;
#endif

#if (ALN_MONITORING_VERSION > 3U) && (CFG_VDY_FS_VELO_CORR_MON) && (CFG_VDY_FS_VELO_CONF_MON_FAULT)
  u_ConfCounterOld = 0U;
#endif

  u_velVarianceCounter_ABS = 0U;
  u_velVarianceCounter_TSC = 0U;
  u_vel_corr_mon           = 0U;
  u_noFallBack_CF_Quality  = 0U;
  return;
}


/* **********************************************************************
  @fn               VDYVelCorrIsObservable */ /*!
  @brief            Determine if ego velocity is observable by stationary target
                    velocity
  @description       

  @param[in]        mif component input data, module interface data 
  @param[in]        pAux component input data, module interface data 
  @param[out]       -
  @return           void

  @pre              -
  @post             -
**************************************************************************** */
STATIC_MTD boolean VDYVelCorrIsObservable(const VDYModIf_t *mif, VDYVelCorrAux_t *pAux)
{
  fAccel_t maxAccelMs = 10.0F * 0.001F;
  boolean observable = TRUE;
  uint32 cyclTimeMS;
  fVelocity_t diffVelo;
  fVelocity_t maxDiffVelo;
  fTime_t scaledCycleTime;

  float32 f_vehLongAccelAbs;
  float32 f_diffVeloAbs;

  /* Retrieve cycle time in MS */
  scaledCycleTime = (vdyGetCycleTime() * 1000.F);
  cyclTimeMS = (uint32) scaledCycleTime;

  maxDiffVelo  = (fVelocity_t) ((float32)(cyclTimeMS) * maxAccelMs);
  diffVelo = mif->LongMot.VehVelo - pAux->lastEgoVel;
  
  /* Ego velocity outside of observable range */
  if (   (mif->LongMot.MotState.MotState == (MotState_t)VDY_LONG_MOT_STATE_MOVE_RWD) 
      || (mif->LongMot.VehVelo < VDY_CORR_VEL_RANGE_0_MIN) 
      || (mif->LongMot.VehVelo > VDY_CORR_VEL_RANGE_2_MAX) )
  {
    observable = FALSE;
  }

  /* calculate absolute values to compare against thresholds */
  f_vehLongAccelAbs = CML_f_Abs(mif->LongMot.VehAccel);
  f_diffVeloAbs = CML_f_Abs(diffVelo);

  /* Ego acceleration above observable range */
  if (   (f_vehLongAccelAbs > VDY_CORR_OBS_ACCEL_MAX) 
      || (f_diffVeloAbs > maxDiffVelo ) )
  {
    pAux->Timer = VDY_CORR_OBS_DELAY_TIME;
  }

  /* Ego curvature above observable range */
  if ( CML_f_Abs(mif->Curve.Curve) > VDY_CORR_OBS_CURVE_MAX )
  {
    pAux->Timer = VDY_CORR_OBS_DELAY_TIME;
  }
  
  /* Decrement timer if it is non-zero */
  if (pAux->Timer > cyclTimeMS)
  {
    pAux->Timer -= cyclTimeMS;
    observable = FALSE;
  }
  else
  {
    pAux->Timer = 0UL;
  }

  /* save velocity for next cycle */
  pAux->lastEgoVel = mif->LongMot.VehVelo;

  return observable;
}


/* **********************************************************************
  @fn               VDYVelCorrStateInsideLimits */ /*!
  @brief            Determine if state value are inside allowed deviations

  @description       

  @param[in]        est component input data, module interface data 
  @param[out]       -
  @return           void

  @pre              -
  @post             -
**************************************************************************** */
STATIC_MTD boolean VDYVelCorrStateInsideLimits(const VDYVelCorrEst_t *est)
{
  boolean ret = FALSE;
  fRatio_t corr_vmax;

  /* Calculate speed correction at maximum speed */
  corr_vmax = est->X[0] + (est->X[1] * SQR(VDY_CORR_VEL_RANGE_2_MAX));

  if (   ((est->X[0] >= VDY_CORR_ABS_ICT_MIN_VAL ) && (est->X[0] <= VDY_CORR_ABS_ICT_MAX_VAL ))
      && ((est->X[1] >= VDY_CORR_ABS_SLP_MIN_VAL)  && (est->X[1] <= VDY_CORR_ABS_SLP_MAX_VAL))
      && ((corr_vmax >= VDY_CORR_ABS_ICT_MIN_VAL ) && (corr_vmax <= VDY_CORR_ABS_ICT_MAX_VAL )) )
  {
    ret = TRUE;
  }

  return ret;
}


/* **********************************************************************
  @fn               VDYVelCorrGetNodesAside */ /*!
  @brief            Determine all node indices but one passed 

  @description      Fills the nidx array with histograms numbers of the
                    histograms which are not the one given number in idx
                    Three histograms are defined for velocity correction
                    Example: index 1 leaves index 0 and inde 2 remaining

  @param[in]        idx
  @param[in]        nidx
  @param[out]       -
  @return           void

  @pre              -
  @post             -
**************************************************************************** */
STATIC_MTD void VDYVelCorrGetNodesAside(uint32 idx, uint32 nidx[])
{
  switch(idx)
  {
    case 0:
      nidx[0] = 1UL;
      nidx[1] = 2UL;
      break;
    case 1: 
      nidx[0] = 0UL;
      nidx[1] = 2UL;
      break;
    case 2: 
      nidx[0] = 0UL;
      nidx[1] = 1UL;
      break;
    default:
      break;
  }
  return;
}


/* ***********************************************************************
  @fn               VDYVelCorrExec */ /*!
  @brief            Determine operating sequence for vehicle dynamics observer

  @description       

  @param[in]        reqPorts
  @param[in]        input
  @param[in]        mif
  @param[in]        proPorts
  @return           void

  @pre              -
  @post             -
**************************************************************************** */
void VDYVelCorrExec(const reqVdyPrtList_t *reqPorts, const VDYInputData_t *input, VDYModIf_t *mif, const proVdyPrtList_t *proPorts , boolean b_RTBDetection)
{
  VDYVelCorr_t *pVelCorr = COR_GET_ME();
  boolean nvmCorrTaken = FALSE;
  uint32 idxVel;
  boolean newNodeVal = FALSE;
  boolean bIsVelCorrObservable = FALSE;
  fTime_t CycleTime;
  #if ( (defined(CFG_VDY_VELO_MONITOR_MIN_MAX)) && (CFG_VDY_VELO_MONITOR_MIN_MAX) )
  float32 Out_Accel_Interpolation = 0.F;
  float32 Input_velo_Interpolation = 0.F;
  #endif
  pVelCorr->Io.mif         = mif;
  pVelCorr->Io.errFactRg   = &proPorts->pVDYErrors->OutPutErrors.VelCorrRg;
  pVelCorr->Io.errWin      = &proPorts->pVDYErrors->OutPutErrors.VelCorrWin;

  /* Determine cycle time */
  CycleTime = vdyGetCycleTime();

  /* Update ecu runtime */
  if( pVelCorr->Aux.EcuTime >= VCOR_ECU_ELPSD_TIME_MAX )
  {
    pVelCorr->Aux.EcuTime = VCOR_ECU_ELPSD_TIME_MAX;
  } 
  else
  {
    pVelCorr->Aux.EcuTime += CycleTime;
  }

  /* Initialize error velocity correction factor range as not observable */
  COR_SET_ERR_FACT_RG(VDY_ERR_STATE_UNKNOWN);
  
  /* Initialize error velocity correction measurement window distribution as not observable */
  COR_SET_ERR_WIN(VDY_ERR_STATE_UNKNOWN);

  if (VDY_CTRL_GET_STATE((VDYCtrlState_t)VDY_CTRL_STATE_INIT, input->Frame.CtrlMode))
  {
    proPorts->pVDYErrors->OutPutErrors.VDY_FS_VEH_CORR_MON = VDY_ERR_STATE_UNKNOWN;
  }

  if (VDY_CTRL_GET_STATE((VDYCtrlState_t)VDY_CTRL_STATE_RUNNING, input->Frame.CtrlMode))
  {
    /* Read non-volatile correction data */
    nvmCorrTaken = VDYVelCorrReadNvm(pVelCorr->Node, reqPorts->pNVMRead);

    if (nvmCorrTaken != FALSE )
    {
      uint32 rgVelo;

      /* Initialize estimator with usable nodes from non-volatile memory */
      for (rgVelo = 0UL; rgVelo < VDY_CORR_VEL_RANGES; rgVelo++)
      {
        if (pVelCorr->Node[rgVelo].CorrDev < VDY_CORR_INIT_STD_DEV )
        {
          VDYVelCorrExecEstimator(&pVelCorr->Node[rgVelo], &pVelCorr->Est, TRUE);
        }
      }

      /* Check if the stored measurements results in reasonable estimations */
      if (VDYVelCorrStateInsideLimits(&pVelCorr->Est) == FALSE)
      {
        /* Discard nvm init values */
        VDYVelCorrInitEstimator(&pVelCorr->Est);
      }
      else
      {
        /* The measurement values are from last ignition cylce, init estimation variances */
        VDYVelCorrInitCovEstimator(&pVelCorr->Est);
      }
    }

#if (VEL_CORR_HIST_STATIONARY_TARGETS)
    /* Find velocity range index */
    idxVel = VDYVelCorrGetVelocityIndex(reqPorts->pVelStatObj->RefSpeed.refEgoVelo);

    if (    (reqPorts->pVelStatObj->state  == (SigState_t)SIGNAL_VALID )
         && (reqPorts->pVelStatObj->RefSpeed.cntSample != cntSampleOld) )
    {

      uint32 idxAside[2];
      
      /* Update sync counter */
      cntSampleOld = reqPorts->pVelStatObj->RefSpeed.cntSample;
#elif (VEL_CORR_ALN)
    /* Find velocity range index */
    idxVel = VDYVelCorrGetVelocityIndex(reqPorts->pAln_Monitoring->EgoSpeed.f_EgoSpeed);

    /* Check if new ALN data is available and Roller test bench and PlantMode is not detected*/
    if (    (reqPorts->pAln_Monitoring->EgoSpeed.u_UpdateCounter != cntSampleOld)  \
         && (reqPorts->pAln_Monitoring->EgoSpeed.f_EgoSpeed > 0.0F)                \
         && (reqPorts->pAln_Monitoring->EgoSpeed.f_EgoSpeedStandardDeviation < VDY_VCOR_NO_ALN_DATA_STD_DEV) 
         && ( b_RTBDetection!= TRUE ) 
         && ( input->Frame.ProductionMode != TRUE ))
    {
      uint32 idxAside[2];

      /* Update sync counter */
      cntSampleOld = reqPorts->pAln_Monitoring->EgoSpeed.u_UpdateCounter;
#endif

      /* Observability of ego velocity for correction */
      bIsVelCorrObservable = VDYVelCorrIsObservable(mif, &pVelCorr->Aux);
      if (bIsVelCorrObservable == TRUE)
      {
        /* During init state fill all velocity ranges */
        if (VDYVelCorr.Node[0].State == (VDYCorrState_t) VEL_CORR_INIT )
        {
#if (VEL_CORR_HIST_STATIONARY_TARGETS)
          /* Add data of all three histograms to long-term histograms */
          VDYVelCorrAdd(&reqPorts->pVelStatObj->RefSpeed, &pVelCorr->Hist[0]);
          VDYVelCorrAdd(&reqPorts->pVelStatObj->RefSpeed, &pVelCorr->Hist[1]);
          VDYVelCorrAdd(&reqPorts->pVelStatObj->RefSpeed, &pVelCorr->Hist[2]);
#elif (VEL_CORR_ALN)
          /* Store current uncorrected speed in all three histograms */
          pVelCorr->Hist[0].EgoVel.Mean = mif->LongMot.VehVelo;
          pVelCorr->Hist[1].EgoVel.Mean = mif->LongMot.VehVelo;
          pVelCorr->Hist[2].EgoVel.Mean = mif->LongMot.VehVelo;

          /* Add data of all three histograms to long-term histograms */
          VDYVelCorrAdd(reqPorts->pAln_Monitoring, &pVelCorr->Hist[0]);
          VDYVelCorrAdd(reqPorts->pAln_Monitoring, &pVelCorr->Hist[1]);
          VDYVelCorrAdd(reqPorts->pAln_Monitoring, &pVelCorr->Hist[2]);
#endif
          /* Test for take over of new measurment nodes */
          newNodeVal =  VDYVelCorrOverTake(&pVelCorr->Hist[0], &pVelCorr->Node[0], &pVelCorr->Aux);
          newNodeVal |= VDYVelCorrOverTake(&pVelCorr->Hist[1], &pVelCorr->Node[1], &pVelCorr->Aux);
          newNodeVal |= VDYVelCorrOverTake(&pVelCorr->Hist[2], &pVelCorr->Node[2], &pVelCorr->Aux);

          if (newNodeVal != FALSE)
          {
            /* Determine velocity range learned right now */
            idxVel = VDYVelCorrGetVelocityIndex(pVelCorr->Hist[0].EgoVel.Mean);
            
            /* Clear sampled data at non-affected nodes */
            VDYVelCorrGetNodesAside(idxVel, idxAside);
            VDYVelCorrReduce(&pVelCorr->Hist[idxAside[0]], 0.F);
            VDYVelCorrReduce(&pVelCorr->Hist[idxAside[1]], 0.F);
          }
        }
        else
        {
          boolean waitForFirstMeas;

          /* Non-Init state, histograms are filled velocity selective */
          if (  (pVelCorr->Node[0].State == (VDYCorrState_t) VEL_CORR_BACKUP)
              &&(pVelCorr->Node[1].State == (VDYCorrState_t) VEL_CORR_BACKUP)
              &&(pVelCorr->Node[2].State == (VDYCorrState_t) VEL_CORR_BACKUP) )
          {
            waitForFirstMeas = TRUE;
          }
          else
          {
            waitForFirstMeas = FALSE;
          }

          /* Add data to specific velocity range */
#if (VEL_CORR_HIST_STATIONARY_TARGETS)
          VDYVelCorrAdd(&reqPorts->pVelStatObj->RefSpeed, &pVelCorr->Hist[idxVel]);
#elif (VEL_CORR_ALN)
          pVelCorr->Hist[idxVel].EgoVel.Mean = mif->LongMot.VehVelo;  /* Store uncorrected speed */
          VDYVelCorrAdd(reqPorts->pAln_Monitoring, &pVelCorr->Hist[idxVel]);
#endif
          /* Test for takeover */
          newNodeVal = VDYVelCorrOverTake(&VDYVelCorr.Hist[idxVel], &VDYVelCorr.Node[idxVel], &pVelCorr->Aux);

          if (newNodeVal != FALSE)
          {
            /* difference between factor in current node and factor in node 0 and 1  */
            float32 f_corrFactDiffNode0Abs;
            float32 f_corrFactDiffNode1Abs;

            /* Ascertain nodes which have not been updated */
            VDYVelCorrGetNodesAside(idxVel, idxAside);

            f_corrFactDiffNode0Abs = CML_f_Abs(pVelCorr->Node[idxVel].CorrFact - pVelCorr->Node[idxAside[0]].CorrFact);
            f_corrFactDiffNode1Abs = CML_f_Abs(pVelCorr->Node[idxVel].CorrFact - pVelCorr->Node[idxAside[1]].CorrFact);

            /* Compare first measurement at current ignition cycle with stored value from NV memory */
            if (  (waitForFirstMeas != FALSE) 
                &&(  (f_corrFactDiffNode0Abs > VDY_CORR_NVM_FAC_DEV)
                   ||(f_corrFactDiffNode1Abs > VDY_CORR_NVM_FAC_DEV)) )
            {
              /* Discard nvm init values due to large deviation to new value */
              VDYVelCorrInitEstimator(&pVelCorr->Est);
            }
          }
        }

        /* if new estimation has been taken over, update non-volatile memory */
        if (newNodeVal != FALSE)
        {
          VDYVelCorrSaveNvm(pVelCorr->Node, pVelCorr->Aux.EcuTime, reqPorts->pNVMRead, proPorts->pNVMWrite);
        }
      }
	  u_vel_corr_mon = 0U;
    }
	
    /* Update miniumum and maximum ego velocity where correction factor has been observed */
    if (newNodeVal != FALSE)
    {
      /* Update maximum ego velocity used for velocity correction */
      if (pVelCorr->Aux.maxVelMeas > 0.F)
      {
        pVelCorr->Aux.maxVelMeas = MAX_FLOAT(pVelCorr->Hist[idxVel].EgoVel.Mean, pVelCorr->Aux.maxVelMeas);            
      }
      else
      {
        pVelCorr->Aux.maxVelMeas = pVelCorr->Hist[idxVel].EgoVel.Mean;
      }
      /* Update minimum ego velocity used for velocity correction */
      if (pVelCorr->Aux.minVelMeas > 0.F)
      {
        pVelCorr->Aux.minVelMeas = MIN_FLOAT(pVelCorr->Hist[idxVel].EgoVel.Mean, pVelCorr->Aux.minVelMeas);
      }
      else
      {
        pVelCorr->Aux.minVelMeas = pVelCorr->Hist[idxVel].EgoVel.Mean;
      }
    }

    /* Run estimator */
    /* start filter after one node was updated */
    VDYVelCorrExecEstimator(&pVelCorr->Node[idxVel] , &VDYVelCorr.Est, newNodeVal);

    /* Calculate output data */
    VDYVelCorrCalcResult(&VDYVelCorr.Est, mif, reqPorts);

    #if ( (defined(CFG_VDY_VELO_MONITOR_MIN_MAX)) && (CFG_VDY_VELO_MONITOR_MIN_MAX) )
    /* Linear interpolation to deactiavte the vel_mon and vel_monLT DEM  */
    if (mif->LongMot.VehVelocityCorr > VDY_INTERPOL_VEL_RANGE_MAX)
    {
      Input_velo_Interpolation = VDY_INTERPOL_VEL_RANGE_MAX;
    }
    else
    {
      Input_velo_Interpolation = mif->LongMot.VehVelocityCorr;
    }

    Out_Accel_Interpolation = CML_f_LinearInterpolation( VDY_INTERPOL_VEL_RANGE_MIN,VDY_INTERPOL_ACCEL_RANGE_MIN, VDY_INTERPOL_VEL_RANGE_MAX, VDY_INTERPOL_ACCEL_RANGE_MAX ,Input_velo_Interpolation);

    if ( (mif->LongMot.VehAccel < VDY_DECELERATION_RANGE_MAX )||(mif->LongMot.VehAccel > Out_Accel_Interpolation) )
    {
      VDY_SET_IO_STATE(VDY_SOUT_POS_VEL, VDY_IO_STATE_VALID, proPorts->pVehicleDynamicSignals->State);
      proPorts->pVDYErrors->OutPutErrors.VelMon   = VDY_ERR_STATE_INACTIVE;
      proPorts->pVDYErrors->OutPutErrors.VelMonLt = VDY_ERR_STATE_INACTIVE;
      u_debounceCounter_set = 0U; 
      u_debounceCounter_Reset = VDY_PAR_VMON_CYCLE_IN;
    }
    else
    {
      /* Monitoring the VDY output velocity against the MIN and MAX velocity */
      VDYCorrectedVeloMonitoring (input , proPorts , mif);
    }
    #endif

#if (ALN_MONITORING_VERSION > 3U) && (CFG_VDY_FS_VELO_CORR_MON) && (VEL_CORR_ALN)

    /* Check if new ALN data is available */
	if (    (reqPorts->pAln_Monitoring->EgoSpeed.u_UpdateCounter != u_ConfCounterOld) 
				&& (reqPorts->pAln_Monitoring->EgoSpeed.f_EgoSpeed > 0.0F)                         )
    {

	  u_ConfCounterOld = reqPorts->pAln_Monitoring->EgoSpeed.u_UpdateCounter;  //  update the counter
	  /* check velocity */
	  VDYFSCheckVelCorrMonitoring(mif->LongMot.VehVelocityCorr, proPorts->pVehicleDynamicSignals->Longitudinal.varVelocity, reqPorts->pAln_Monitoring->EgoSpeed.f_EgoSpeed, reqPorts->pAln_Monitoring->EgoSpeed.f_EgoSpeedStandardDeviation, b_RTBDetection, input);
	  VDYFSConfirmVelocity(mif->LongMot.VehVelocityCorr, proPorts->pVehicleDynamicSignals->Longitudinal.varVelocity, reqPorts->pAln_Monitoring->EgoSpeed.f_EgoSpeed, b_RTBDetection, input);
	
	  #if ( (CFG_VDY_FS_VELO_CORR_MON)  && (!CFG_VDY_USE_VELO_MONITOR) && (CFG_VDY_FS_VELO_CORR_MON_ERROR))

	  /* check if FS velocity monitor detected a fault */
	  if (VDYFSVelCorrMon.fault == VDY_ERR_STATE_ACTIVE)
	  {
	    proPorts->pVDYErrors->OutPutErrors.VDY_FS_VEH_CORR_MON = VDY_ERR_STATE_ACTIVE;
	  }
	  else
	  {
	    proPorts->pVDYErrors->OutPutErrors.VDY_FS_VEH_CORR_MON = VDY_ERR_STATE_INACTIVE;
	  }

	  #endif
    }
#elif (!CFG_VDY_FS_VELO_CORR_MON) && (VEL_CORR_ALN)
       VDYUncorrVelMonitoring(mif->LongMot.VehVelo, mif->LongMot.VehVeloVar, reqPorts->pAln_Monitoring->f_EgoSpeed, reqPorts->pAln_Monitoring->f_EgoSpeedStandardDeviation);
#endif

    /* set velocity correction quality flag if the node was updated or NVM correction factor was confirmed by first new samples */
    /* if correction factor is available, either from NVM or even from new histogram */
#if (CFG_VDY_FS_VELO_CORR_MON)
      if ( VDYFSVelCorrMon.confFault == VDY_ERR_STATE_INACTIVE )
      {
        /* velocity check successful, confirm qualifier */
        proPorts->pVehicleDynamicSignals->Longitudinal.VelocityCorrectionQuality = VDY_VELO_CORR_QUAL_RANGE_VERIFIED;
        b_init_CorrFlag = TRUE;
        u_noFallBack_CF_Quality = 1U;
      }
      else
#endif
    {
      if (pVelCorr->Node[idxVel].State == (VDYCorrState_t) VEL_CORR_INIT)
      {
        /* NVM is either not available or no correction factor is stored */
        proPorts->pVehicleDynamicSignals->Longitudinal.VelocityCorrectionQuality = VDY_VELO_CORR_QUAL_EEPROM;
      }
      else
      {
        if(u_noFallBack_CF_Quality == 1)
        {
          proPorts->pVehicleDynamicSignals->Longitudinal.VelocityCorrectionQuality = VDY_VELO_CORR_QUAL_RANGE_VERIFIED;					
        }
        else
        {						
          /*velocity check either not completed yet or set a fault, no corfirmation of qualifier */
          proPorts->pVehicleDynamicSignals->Longitudinal.VelocityCorrectionQuality = VDY_VELO_CORR_QUAL_RANGE_NVERIFIED;
        }
      }
    }

#if (CFG_VDY_FS_VELO_CORR_MON)
    //If (NVM CF -Newly computed CF)*Velocity at that instance is greater than 1m/s, VDY shall set velocity state to VDY_IO_STATE_DECREASED for 10 VDY cycles only.
    //After 10 VDY cycles VDY shall set velocity state to VDY_IO_STATE_VALID.
    if ((!b_NVMAndNewCFCheckDone) && (b_firstNewCFLearned))
    {		
      if( b_NVMAndNewCFRangeFailed)
      {
        if(u_count <= MAX_COUNTER )
        {
          VDY_SET_IO_STATE(VDY_SOUT_POS_VELOCITY, VDY_IO_STATE_DECREASED, proPorts->pVehicleDynamicSignals->State);
          u_lastVelocityIOstate = VDY_IO_STATE_DECREASED;
          u_count++;
        }
        else 
        {
          VDY_SET_IO_STATE(VDY_SOUT_POS_VELOCITY, VDY_IO_STATE_VALID, proPorts->pVehicleDynamicSignals->State);
          u_lastVelocityIOstate = VDY_IO_STATE_VALID;
          b_NVMAndNewCFCheckDone = TRUE;
        }
      }

      if(u_count < 1)
      {
        b_NVMAndNewCFCheckDone = TRUE;
        u_lastVelocityIOstate = VDY_IO_STATE_VALID;
      }
    }
		
		
    //If the difference between VDY corrected velocity(With NVM correction factor) and ALN velocity is less than 1m/s for 5 radar cycle, VDY shall set velocity state to VDY_IO_STATE_VALID.
    if ((u_TakeoverCounter < 1) && (u_noFallbackVelState == FALSE))
    {
      if (VDYFSVelCorrMon.confFault == VDY_ERR_STATE_INACTIVE)
      {
        VDY_SET_IO_STATE(VDY_SOUT_POS_VELOCITY, VDY_IO_STATE_VALID, proPorts->pVehicleDynamicSignals->State);
        u_lastVelocityIOstate = VDY_IO_STATE_VALID;
        u_noFallbackVelState = TRUE;
      }
      else
      {
        VDY_SET_IO_STATE(VDY_SOUT_POS_VELOCITY, VDY_IO_STATE_CF_CALC, proPorts->pVehicleDynamicSignals->State);
        u_lastVelocityIOstate = VDY_IO_STATE_CF_CALC;
      }
    }
    else
    {
      VDY_SET_IO_STATE(VDY_SOUT_POS_VELOCITY, u_lastVelocityIOstate, proPorts->pVehicleDynamicSignals->State);
    }
						
#endif
  }  // if (VDY_CTRL_GET_STATE((VDYCtrlState_t)VDY_CTRL_STATE_RUNNING, input->Frame.CtrlMode))

  return;
}


/* ***********************************************************************
  @fn               VDYVelCorrExecEstimator */ /*!
  @brief            Execute correction factor estimator

  @description       

  @param[in]        node  :  measurement points
  @param[in]        mupdt :  if true perform measurement update
  @param[out]       est   :  new estimation
  @return           void
  
  @pre              -
  @post             -
**************************************************************************** */
STATIC_MTD void VDYVelCorrExecEstimator(const VDYVelCorrNode_t *node, VDYVelCorrEst_t *est, boolean mupdt)
{
  /* Prediction  xhat = F * xhat*/

  /* Predicted estimate covariance  P = F * P * F' + Q */
  if ( est->P[0] < (VCOR_EST_P_INIT_QFACT * Q_c[0]) )
  {
    est->P[0] += Q_c[0];
    est->P[1] += Q_c[1];
    est->P[2] += Q_c[2];
    est->P[3] += Q_c[3];
  }

  if (mupdt != FALSE)
  {
    /* New measurement is available, update estimator */
    float32 y;
    float32 R;
    float32 S;
    float32 K[2];

    /* Build observation matrix */
    est->H[1] = SQR(node->CorrVel);

    /*  Calculate measurement variance */
    R = node->CorrDev * R_STD_DEV_FACT;
    R *= R;

    /* Innovation residual y = z - H * xhat */
    y = node->CorrFact - ( (est->H[0] * est->X[0]) + (est->H[1] * est->X[1]));

    /* Innovation covariance  S = H * P * H' + R */
    S =    ( ((est->H[0] * est->P[0]) + (est->H[1] * est->P[2])) * est->H[0] ) \
         + ( ((est->H[0] * est->P[1]) + (est->H[1] * est->P[3])) * est->H[1] ) \
         + R;

    /* Optimal Kalman gain   K = P * H' * inv(S) */
    { 
      static const float32 minBnd_c = 1E-30F;
      float32 invS;
      
      /* Avoid division by zero */
      if ( CML_f_Abs(S) > minBnd_c )
      {
        invS = 1.0F / S;
      }
      else
      {
        if (S > 0.0F)
        {
          invS = (1.0F / minBnd_c);
        }
        else
        {
          invS = -(1.0F / minBnd_c);
        }
      }

      K[0] = ((est->P[0] * est->H[0]) + (est->P[1] * est->H[1])) * invS;
      K[1] = ((est->P[2] * est->H[0]) + (est->P[3] * est->H[1])) * invS;
    }

    /* Update state estimate xhat = xhat + K * y */
    est->X[0] += K[0] * y;
    est->X[1] += K[1] * y;

    /* Applying state constraints if necessary */
    { 
      float32 XC_1;
      
      XC_1 = MINMAX_FLOAT(VDY_CORR_ABS_SLP_MIN_VAL, VDY_CORR_ABS_SLP_MAX_VAL,est->X[1]);

      est->X[0] = est->X[0] + (est->H[1] * (est->X[1] - XC_1));
      est->X[1] = XC_1;
    }

    /* Compute the covariance of the estimation error  P = (eye(2) - K * H) * P */
    { 
      float32 Pn[4];
      
      /* Copy new values first to seperate buffer to keep P matrix consistent during update */
      Pn[0] =  ( ( 1.0F - (K[0] * est->H[0])) * est->P[0] ) - (K[0] * est->H[1] * est->P[2]);
      Pn[1] =  ( ( 1.0F - (K[0] * est->H[0])) * est->P[1] ) - (K[0] * est->H[1] * est->P[3]);
      Pn[2] =  (-K[1] * est->H[0] * est->P[0]) +  ( ( 1.0F - (K[1] * est->H[1])) * est->P[2]);
      Pn[3] =  (-K[1] * est->H[0] * est->P[1]) +  ( ( 1.0F - (K[1] * est->H[1])) * est->P[3]);

      /* Update covariance matrix */
      est->P[0] = Pn[0];
      est->P[1] = Pn[1];
      est->P[2] = Pn[2];
      est->P[3] = Pn[3];
    }
  }

  return;
}


/* ***********************************************************************
  @fn               VDYVelCorrInitCovEstimator */ /*!
  @brief            Init correction factor coveriance matrix

  @description      

  @param[in]        est
  @return           initialized coveriance matrix

  @pre              -
  @post             -
**************************************************************************** */
STATIC_MTD void VDYVelCorrInitCovEstimator(VDYVelCorrEst_t *est)
{
  est->P[0] = VCOR_EST_P_INIT_QFACT * Q_c[0];
  est->P[1] = VCOR_EST_P_INIT_QFACT * Q_c[1];
  est->P[2] = VCOR_EST_P_INIT_QFACT * Q_c[2];
  est->P[3] = VCOR_EST_P_INIT_QFACT * Q_c[3];

  return;
}


/* ***********************************************************************
  @fn               VDYVelCorrInitEstimator */ /*!
  @brief            Init internal correction factor estimation data

  @description       
    
  @param[in]        
  @return           est : initialized estimator data base

  @pre              -
  @post             -
**************************************************************************** */
STATIC_MTD void VDYVelCorrInitEstimator(VDYVelCorrEst_t *est)
{
  /* Init covariance matrix */
  VDYVelCorrInitCovEstimator(est);
    
  est->H[0] = 1.0F;
  est->H[1] = 0.F;

  est->X[0] = 1.0F;
  est->X[1] = 0.F;

  return;
}


/* **********************************************************************
  @fn               VDYVelCorrCalcResult */ /*!
  @brief            Calculate final result derived from estimated states

  @description       
   
  @param[in]        est
  @param[in]        mif
  @param[out]       correction factor, corrected speed with variances

  @pre              -
  @post             -
**************************************************************************** */
STATIC_MTD void VDYVelCorrCalcResult(const VDYVelCorrEst_t *est, VDYModIf_t *mif, const reqVdyPrtList_t *reqPorts)
{
  VDYVelCorrAux_t *pVCorrAux = &(COR_GET_ME()->Aux);
  fVelocity_t velo = mif->LongMot.VehVelo;
  float32 dev;
  float32 X1_constr = est->X[1];
  static float32 lastVeloVar = 0.0F;

  /* Calculate correction factor */
  {
    float32 vel2 = SQR(velo);
    mif->LongMot.VelCorrFact =  est->X[0] + ( vel2 * X1_constr );
    mif->LongMot.corrVar  =  est->P[0] + (SQR(vel2) * est->P[3]) + (vel2 * (est->P[1] + est->P[2]));
  }

  if(u_TakeoverCounter == 0)
  {
    NVMCorrFact = mif->LongMot.VelCorrFact;
  }

  if((!b_NVMAndNewCFCheckDone) && (!b_firstNewCFLearned) && (u_TakeoverCounter == 1))
  {
    b_firstNewCFLearned = TRUE;
    if((CML_f_Abs((NVMCorrFact - mif->LongMot.VelCorrFact) * velo)) > 1.0f)
    {
      b_NVMAndNewCFRangeFailed = TRUE;
    }
  }
#if ( (defined(CFG_VDY_USE_CORRECT_VELO_CORR_VAR)) && (CFG_VDY_USE_CORRECT_VELO_CORR_VAR) )
  /* The variance of the corr velo should be higher if the velo hist is not learned or not validated 
     This change has negative effects on the grid object if meas files without learned or validated histo are used 
     The variance is higher and so the grid object position might be different
     This patch was developed for the ARS32x Project for IL_1998 */
  if ((pVCorrAux->maxVelMeas + pVCorrAux->minVelMeas) > 0.F)
  {
    static const float32 dVarDelta_c = 1E-4F; /* Lower max. variance if one measurement update is available */

    /* Limit output correction factor variance to max. reasonable value, if at least one measurement 
       has been available */
    if (corrout->corrVar > (SQR(VDY_CORR_INIT_STD_DEV) - dVarDelta_c) )
    {
      corrout->corrVar = SQR(VDY_CORR_INIT_STD_DEV) - dVarDelta_c;
    }
    
    /* If velocity dependency is not observable keep variance above minimum value */
    if ( (pVCorrAux->maxVelMeas - pVCorrAux->minVelMeas) <  VDY_CORR_OBS_MIN_VEL_RG)
    {
      corrout->corrVar = MAX_FLOAT(corrout->corrVar, SQR(VDY_CORR_OBS_STD_DEV));
    }
  }
  else
  {
    /* Limit output correction factor variance to max. reasonable value, if no measurement is available */
    if (corrout->corrVar > SQR(VDY_CORR_INIT_STD_DEV) )
    {
      corrout->corrVar = SQR(VDY_CORR_INIT_STD_DEV);
    }
  }
#else
  /* Limit output correction factor variance to max. reasonable value */
  if (mif->LongMot.corrVar > SQR(VDY_CORR_INIT_STD_DEV) )
  {
    mif->LongMot.corrVar = SQR(VDY_CORR_INIT_STD_DEV);
  }
  else
  {
    /* If velocity dependency is not observable keep variance above minimum value */
    if ( (pVCorrAux->maxVelMeas - pVCorrAux->minVelMeas) <  VDY_CORR_OBS_MIN_VEL_RG)
    {
      mif->LongMot.corrVar = SQR(VDY_CORR_OBS_STD_DEV);
    }
  }
#endif

  /* Calculate corrected velocity for interface to handcode parts */
  /* Final corrected output velocity must be calculated later as velocity is calculated later in this cycle */
  mif->LongMot.VehVelocityCorr = mif->LongMot.VelCorrFact * mif->LongMot.VehVelo;
  
  /* Are sufficient number of stationary targets detected? (b_init_CorrFlag sets TRUE when first time correction factor test was passed) */
  if (b_init_CorrFlag == TRUE)
  {
    /* Calculate variance of corrected velocity (variance derived from product of two normal distributed RV) */ 
    mif->LongMot.corrVeloVar         =   (SQR(mif->LongMot.VehVelo) * mif->LongMot.corrVar)   \
                                   + (SQR(mif->LongMot.VelCorrFact)    * mif->LongMot.VehVeloVar );

    /* correction for velocity variance as correction factor is not constant over velocity */
    mif->LongMot.corrVeloVar        *=  (VDY_CORR_VAR_CORRECT_FACTOR * mif->LongMot.VehVelo);
  }
  else
  {
    /* Set output correction factor variance to default value */
    mif->LongMot.corrVar = CML_Sqr(VDY_CORR_INIT_STD_DEV_START);
 
    /* If no correction factor is available or not validated with a radar target, the variance values might become unrealistic
       as the mathetical model of a Gaussian distribution does not fit any more.
       The variance is assumed to be of a uniform distribution of the correction factor with a maximum deviation of 10%*/
    mif->LongMot.corrVeloVar = ( CML_Sqr(2.0F*(mif->LongMot.VehVelo * VDY_FS_VEL_MON_RAT_THRHD)) )/12.0F;
  }
    /*During high Deceleration condition when ABS /TSC  signal is active  , Variance of velocity is limited to the maximum */
  if((VDY_GET_IO_STATE(VEH_SIG_BRAKE_ABS, reqPorts->pVehicleInputSignals->Brake.State) == VDY_IO_STATE_VALID) && (reqPorts->pVehicleInputSignals->Brake.ABSCtrl == FALSE))
  {
    u_velVarianceCounter_ABS = 0U;
  }

  if((VDY_GET_IO_STATE(VEH_SIG_BRAKE_TSC, reqPorts->pVehicleInputSignals->Brake.State) == VDY_IO_STATE_VALID) && (reqPorts->pVehicleInputSignals->Brake.TCSCtrl == FALSE))
  {
    u_velVarianceCounter_TSC = 0U;
  }

  /*During high Deceleration condition when ABS /TSC  signal is active  and variance is greater than threshold, Variance of velocity is limited to the maximum */

  if (((VDY_GET_IO_STATE(VEH_SIG_BRAKE_ABS, reqPorts->pVehicleInputSignals->Brake.State) == VDY_IO_STATE_VALID) &&
      (reqPorts->pVehicleInputSignals->Brake.ABSCtrl == TRUE) &&
      (u_velVarianceCounter_ABS < OUTPUT_VEL_VAR_LIMITATION)) ||

      ((VDY_GET_IO_STATE(VEH_SIG_BRAKE_TSC, reqPorts->pVehicleInputSignals->Brake.State) == VDY_IO_STATE_VALID) &&
       (reqPorts->pVehicleInputSignals->Brake.TCSCtrl == TRUE) &&
       (u_velVarianceCounter_TSC < OUTPUT_VEL_VAR_LIMITATION)))
  {

    if(mif->LongMot.corrVeloVar > VDY_VELOCITY_MAX_VARIANCE)
    {
      mif->LongMot.corrVeloVar =  VDY_VELOCITY_MAX_VARIANCE;
    }

    if((VDY_GET_IO_STATE(VEH_SIG_BRAKE_ABS, reqPorts->pVehicleInputSignals->Brake.State) == VDY_IO_STATE_VALID) &&
       (reqPorts->pVehicleInputSignals->Brake.ABSCtrl == TRUE))
    {
      u_velVarianceCounter_ABS ++;
    }

    if((VDY_GET_IO_STATE(VEH_SIG_BRAKE_TSC, reqPorts->pVehicleInputSignals->Brake.State) == VDY_IO_STATE_VALID) &&
       (reqPorts->pVehicleInputSignals->Brake.TCSCtrl == TRUE))
    {
      u_velVarianceCounter_TSC ++;
    }
  }
  /*Making the corrected velocity variance as Non-Zero when calculated corrected velocity variance is Zero */
  mif->LongMot.corrVeloVar         = CML_f_Max(CML_f_AlmostZero, mif->LongMot.corrVeloVar);   

  /* Calculate min and max value derived from 3 sigma range and check for negative variance */
  if ((CML_f_IsNonZero(mif->LongMot.corrVeloVar)) && (mif->LongMot.corrVeloVar > 0.0F))
  {
    dev = 3.F * VDY_SQRT(mif->LongMot.corrVeloVar);
    lastVeloVar = mif->LongMot.corrVeloVar;
  }
  else
  {
    dev = 3.F * VDY_SQRT(lastVeloVar);
  }

  return;
}
#endif


#if ( (defined(CFG_VDY_VELO_MONITOR_MIN_MAX)) && (CFG_VDY_VELO_MONITOR_MIN_MAX) )
/* ***********************************************************************
  @fn               VDYCorrectedVeloMonitoring*/ /*!
  @brief            Monitor the corrected velocity 

  @description      Monitor the corrected velocity based on the Minimum and Maximum velocity range and set the DEM respectively
                    
   
  @param[in]        input minimum velocity range
  @param[in]        input maximum velocity range
  @param[out]       VDYError vel_mon , vel_monLT
  @return           void

  @pre              -
  @post             -
**************************************************************************** */
STATIC_MTD void VDYCorrectedVeloMonitoring (const VDYInputData_t *input , const proVdyPrtList_t *proPorts , VDYModIf_t *mif)
{

  const uint32 incErrCnt_c = 1UL;   /* Increment step size */
   
  // if both the min and max velocities are VALID use both for monitoring the corrected velocity 
  if ( (VDY_GET_IO_STATE(VDY_SIN_POS_VEHVEL_MIN, input->Signals.State) == VDY_IO_STATE_VALID) &&
       (VDY_GET_IO_STATE(VDY_SIN_POS_VEHVEL_MAX, input->Signals.State) == VDY_IO_STATE_VALID) )
  {
  
    if ( (mif->LongMot.VehVelocityCorr < input->Signals.VehVelocityExtMin) ||
           (mif->LongMot.VehVelocityCorr > input->Signals.VehVelocityExtMax) )
    {
      u_debounceCounter_set += incErrCnt_c;
      u_debounceCounter_Reset = 0U;
    }

    else
    {
      /* decrement error count */
      u_debounceCounter_set=  0U;
      u_debounceCounter_Reset += incErrCnt_c;

    }
  } 

  else if ((VDY_GET_IO_STATE(VDY_SIN_POS_VEHVEL_MIN, input->Signals.State) == VDY_IO_STATE_VALID) &&
       (VDY_GET_IO_STATE(VDY_SIN_POS_VEHVEL_MAX, input->Signals.State) != VDY_IO_STATE_VALID))          // if both the MAX velocity is Not VALID use only MIN velo for monitoring 
  {

    if (mif->LongMot.VehVelocityCorr < input->Signals.VehVelocityExtMin)
           
    {
      u_debounceCounter_set += incErrCnt_c;
      u_debounceCounter_Reset = 0U;
    }

    else
    {
      /* decrement error count */
      u_debounceCounter_set=  0U;
      u_debounceCounter_Reset += incErrCnt_c;
    }

  }

  else if ((VDY_GET_IO_STATE(VDY_SIN_POS_VEHVEL_MIN, input->Signals.State) != VDY_IO_STATE_VALID) &&
       (VDY_GET_IO_STATE(VDY_SIN_POS_VEHVEL_MAX, input->Signals.State) == VDY_IO_STATE_VALID))         // if both the MIN velocity is Not VALID use only MAX velo for monitoring 
  {

    if (mif->LongMot.VehVelocityCorr > input->Signals.VehVelocityExtMax)
    {
      u_debounceCounter_set += incErrCnt_c;
      u_debounceCounter_Reset = 0U;
    }

    else
    {
      /* decrement error count */
      u_debounceCounter_set= 0U;
      u_debounceCounter_Reset += incErrCnt_c;
    }

  }

  else
  {
    /* decrement error count */
    u_debounceCounter_set = 0U; 
    u_debounceCounter_Reset = VDY_PAR_VMON_CYCLE_IN;
  }

  /* test counter thresholds */
  if (u_debounceCounter_set >= VDY_PAR_VMON_CYCLE_OUT_LT)
  {
    /* Counter above long-term limit and Velocity value is out of range*/
    u_debounceCounter_set = MIN(u_debounceCounter_set, VDY_PAR_VMON_CYCLE_OUT_LT +2);

    VDY_SET_IO_STATE(VDY_SOUT_POS_VEL, VDY_IO_STATE_INVALID, proPorts->pVehicleDynamicSignals->State);
    proPorts->pVDYErrors->OutPutErrors.VelMon   = VDY_ERR_STATE_INACTIVE;
    proPorts->pVDYErrors->OutPutErrors.VelMonLt = VDY_ERR_STATE_ACTIVE;
  }

  else if (u_debounceCounter_set >= VDY_PAR_VMON_CYCLE_OUT)
  {
    /* Velocity value is out of range and Counter above short limit */
    VDY_SET_IO_STATE(VDY_SOUT_POS_VEL, VDY_IO_STATE_INVALID, proPorts->pVehicleDynamicSignals->State);
    proPorts->pVDYErrors->OutPutErrors.VelMon   = VDY_ERR_STATE_ACTIVE;
    proPorts->pVDYErrors->OutPutErrors.VelMonLt = VDY_ERR_STATE_INACTIVE;
  }

  else
  {
    // Do Nothing  
  }

  if (u_debounceCounter_Reset >= VDY_PAR_VMON_CYCLE_IN)
  {
    /* Velocity value is within the range */
    
    u_debounceCounter_Reset = MIN(u_debounceCounter_Reset, VDY_PAR_VMON_CYCLE_IN +2);

    VDY_SET_IO_STATE(VDY_SOUT_POS_VEL, VDY_IO_STATE_VALID, proPorts->pVehicleDynamicSignals->State);
    proPorts->pVDYErrors->OutPutErrors.VelMon   = VDY_ERR_STATE_INACTIVE;
    proPorts->pVDYErrors->OutPutErrors.VelMonLt = VDY_ERR_STATE_INACTIVE;
  }
}

#endif


#if (CFG_VDY_FS_VELO_CORR_MON)
#if (VEL_CORR_HIST_STATIONARY_TARGETS)
/* ***********************************************************************
  @fn               VDYFSCheckVelCorrMonitoring */ /*!
  @brief            Monitor velocity based on correction factor

  @description      FS monitor to check if velocity is outside of functional
                    safety accepted tolerance by calculation a correction 
                    factor based on the last 5 static object histograms

                    running standard deviation:
                      sqrt( ( ( sqsum - ((sum*sum)/n) ) / (n-1) )

                    square mean y:
                      y(k+1)=((n-1)*y(k)+x(k+1)*x(k+1))/n
   
  @param[in]        histogram of static objects of last radar cycle
  @return           fault status

  @pre              -
  @post             -
**************************************************************************** */
STATIC_MTD void VDYFSCheckVelCorrMonitoring(const RefSpeed_t *histogram)
{
  float32 fBinsCorrFactor;  /* correction factor of histogram column */
  float32 f32_Local;        /* local buffer for check if square root argument is positive */
  uint8 i,j;
  sint16 li = 0;            /* index of lowest bin with targets */
  sint16 hi = 0;            /* index of highest bin with targets */
  uint16 number = 0U;       /* amount of targets in bins */

  /* calculate scattering width (Streuungsbreite) and number of targets */
  for (i=0u; i<(uint8)REF_SPEED_NO_BINS; i++)
  {
    if ((histogram->binVelRatio[i] > 0U) && (li == 0))
    {
      li = (sint16)i;
    }
    if (histogram->binVelRatio[i] > 0U)
    {
      hi = (sint16)i;
    }
    number = number + histogram->binVelRatio[i];
  }

  /* only add histogramm if not too much scattered */
  if ( ((hi - li) <= VEL_CORR_FS_HIST_MAX_WIDTH) && (number >= VEL_CORR_FS_HIST_MIN_NUMBER))
  {
    /* add histogram data to fast fault detection */
    fBinsCorrFactor = BINS_CORR_FACTOR_START_VALUE;

    /* add histogram data to fast fault detection */
    for (i=0u; i<(uint8)REF_SPEED_NO_BINS; i++)
    {
      /* add all elements of objects of this velocity deviation */
      for (j=0u; j < histogram->binVelRatio[i]; j++)
      {
        VDYFSVelCorrMon.number += 1.0f;
        VDYFSVelCorrMon.sum    += fBinsCorrFactor;
        VDYFSVelCorrMon.sqsum  += fBinsCorrFactor*fBinsCorrFactor;
        VDYFSVelCorrMon.sqmean  = (((VDYFSVelCorrMon.number-1.0f) * VDYFSVelCorrMon.sqmean) + (fBinsCorrFactor*fBinsCorrFactor)) / VDYFSVelCorrMon.number;

        /* only calculate standard deviation if more than one sample is available */
        if (VDYFSVelCorrMon.number > 1.0f) 
        {
          f32_Local = ( VDYFSVelCorrMon.sqsum - ((VDYFSVelCorrMon.sum*VDYFSVelCorrMon.sum) / VDYFSVelCorrMon.number) ) / (VDYFSVelCorrMon.number-1.0f);

          /* calculate standard deviation if possible */
          if (CML_f_IsNonZero(f32_Local))
          {
            VDYFSVelCorrMon.sa = VDY_SQRT(f32_Local);
          }
          else
          {
            VDYFSVelCorrMon.sa = 100.0F;
          }
        }
      }
      fBinsCorrFactor += BINS_CORR_FACTOR_STEP;
    }

    /* only calculate mean if at least one sample is available */
    if (CML_f_Abs(VDYFSVelCorrMon.number) > C_F32_DELTA)
    {
      VDYFSVelCorrMon.mean = VDYFSVelCorrMon.sum / VDYFSVelCorrMon.number;
    }
    else 
    {
      /* Default value is 1.0 */
      VDYFSVelCorrMon.mean = 1.0f;
    }
  }

  /* check if enough samples are available to check for fault and standard deviation is acceptable */
  if ((VDYFSVelCorrMon.number > VEL_CORR_FS_MON_MIN_NUMBER) && (VDYFSVelCorrMon.sa <= VEL_CORR_FS_MON_MIN_SA))
  {
    /* check if short term correction factor is outside of limits and set fault status */
    if ((VDYFSVelCorrMon.mean - 1.0f) < VEL_CORR_FS_MON_MAX_DEV)
    {
      VDYFSVelCorrMon.fault = VDY_ERR_STATE_INACTIVE;
    }
    else
    {
      VDYFSVelCorrMon.fault = VDY_ERR_STATE_ACTIVE;
    }
  }

  VDYFSVelCorrMon.counter++;

  /* reduce amount of data used for fault detection */
  if (VDYFSVelCorrMon.counter > VEL_CORR_FS_MON_MAX_COUNTER)
  {
    VDYFSVelCorrMon.number  = (VDYFSVelCorrMon.number * (float32)VEL_CORR_FS_MON_REDUCTION);
    VDYFSVelCorrMon.sum     = (VDYFSVelCorrMon.sum    * (float32)VEL_CORR_FS_MON_REDUCTION);
    VDYFSVelCorrMon.sqsum   = (VDYFSVelCorrMon.sqsum  * (float32)VEL_CORR_FS_MON_REDUCTION);
    VDYFSVelCorrMon.counter = 1u;
  }
}


#elif (ALN_MONITORING_VERSION > 3U) && (CFG_VDY_FS_VELO_CORR_MON) && (VEL_CORR_ALN)
/* ***********************************************************************
  @fn               VDYFSCheckVelCorrMonitoring*/ /*!
  @brief            Monitor velocity based on correction factor

  @description      FS monitor to check if velocity is outside of functional
                    safety accepted tolerance for 5 cycles
   
  @param[in]        fUncorrectedVelocity input velocity
  @param[in]        fUncorrectedVelocityVar input velocity variance
  @param[in]        fALNVelocity velocity from ALN
  @param[in]        fALNVelocityDev velocity standard deviation from ALN
  @return           void

  @pre              -
  @post             -
**************************************************************************** */
STATIC_MTD void VDYFSCheckVelCorrMonitoring(float32 f_CorrectedVelocity, float32 f_CorrectedVelocityVar, float32 f_ALNVelocity, float32 f_ALNVelocityDev, boolean b_EMProbRTBRecog, const VDYInputData_t *input)
{
  /* ALN will only provide a velocity above 20kph, but check if we have a vehicle velocity at all */
  if (f_CorrectedVelocity > 0.0F)
  {
    /* Calculate difference and uncertainty of estimated velocities and check for negative variance */
    VDYFSVelCorrMon.f_velDiff = (f_ALNVelocity - f_CorrectedVelocity);
    VDYFSVelCorrMon.f_threshold = f_CorrectedVelocity * VDY_FS_VEL_MON_RAT_THRHD;
    VDYFSVelCorrMon.f_curVelCorr = f_ALNVelocity / f_CorrectedVelocity;

    if (f_CorrectedVelocityVar >= 0.0F)
    {
      float32 f_velRangeDiff;
      float32 f_velDiffAbs = CML_f_Abs(VDYFSVelCorrMon.f_velDiff);

      VDYFSVelCorrMon.f_varRange = VDY_FS_VEL_MON_SIGMA * (VDY_SQRT(f_CorrectedVelocityVar) + f_ALNVelocityDev);
      f_velRangeDiff = CML_f_Abs(VDYFSVelCorrMon.f_velDiff) - VDYFSVelCorrMon.f_varRange;

      #if ( (defined (CFG_VDY_FS_VEH_CORR_MON_TOGGLING)) && (CFG_VDY_FS_VEH_CORR_MON_TOGGLING) )
      /* if velocity difference is inside of allowed velocity range, decrement fault count, otherwise increment fault count */
      if (   (f_velRangeDiff  < VDYFSVelCorrMon.f_threshold)
          && (f_velDiffAbs < VDY_FS_VEL_MON_MAX_VEL_DIFF)    )
      #else
      /* if velocity difference is inside of allowed velocity range, decrement fault count, otherwise increment fault count */
      if (   (f_velRangeDiff  < VDYFSVelCorrMon.f_threshold)
          || (f_velDiffAbs < VDY_FS_VEL_MON_MAX_VEL_DIFF)    )
      #endif
      {
        if (VDYFSVelCorrMon.u_counter > 0)
        {
          VDYFSVelCorrMon.u_counter--;
        }

        VDYFSVelCorrMon.fault = VDY_ERR_STATE_INACTIVE;
      }
      #if ( (defined (CFG_VDY_FS_VEH_CORR_MON_TOGGLING)) && (CFG_VDY_FS_VEH_CORR_MON_TOGGLING) )
      else if (   (f_velRangeDiff  > VDYFSVelCorrMon.f_threshold)
            && (f_velDiffAbs > VDY_FS_VEL_MON_MAX_VEL_DIFF)    )
      #else
      else
      #endif
      {
        if (VDYFSVelCorrMon.u_counter < VEL_CORR_FS_MON_MAX_COUNTER)
        {
          VDYFSVelCorrMon.u_counter++;
        }

        if (VDYFSVelCorrMon.u_counter >= VEL_CORR_FS_MON_MAX_COUNTER)
        {
          VDYFSVelCorrMon.fault = VDY_ERR_STATE_ACTIVE;
        }
        else
        {
          VDYFSVelCorrMon.fault = VDY_ERR_STATE_INACTIVE;
        }
        /* Process all calibration learning on roll bench detection or PlantMode and driving*/
        #if((VDY_VEH_DYN_INTFVER >= 8U) || (BSW_VDY_CTRL_DATA_INTFVER >= 3U))
        if((( b_EMProbRTBRecog ) && (CORRECTED_EGO_SPEED_IS_ZERO_ON_ROLLER_BENCH != 1)) || (input->Frame.ProductionMode == TRUE))
        {
          VDYFSVelCorrMon.fault = VDY_ERR_STATE_INACTIVE;
        }
        #endif
      }
      #if ( (defined (CFG_VDY_FS_VEH_CORR_MON_TOGGLING)) && (CFG_VDY_FS_VEH_CORR_MON_TOGGLING) )
      else
      {
         /* Do Nothing */
      }
      #endif
      
    }
  }
}


/* ***********************************************************************
  @fn               VDYFSConfirmVelocity */ /*!
  @brief            Monitor velocity based on confirmation velocity from ALN

  @description      FS monitor to check if velocity is outside of functional
                    safety accepted tolerance for 5 cycles
   
  @param[in]        fCorrectedVelocity input velocity
  @param[in]        fCorrectedVelocityVar input velocity variance
  @param[in]        fALNVelocity confirmation velocity from ALN
  @return           void

  @pre              -
  @post             -
**************************************************************************** */
STATIC_MTD void VDYFSConfirmVelocity(float32 f_CorrectedVelocity, float32 f_CorrectedVelocityVar, float32 f_ALNVelocity, boolean b_EMProbRTBRecog, const VDYInputData_t *input)
{
  /* ALN will only provide a velocity above 20kph, but check if we have a vehicle velocity at all */
  if (f_CorrectedVelocity > 0.0F)
  {
    /* Calculate difference of estimated velocities if variance is not negative */
    if (f_CorrectedVelocityVar >= 0.0F)
    {
      /* calculate velocity difference but consider variance as velocity gets more inacurate during braking or acceleration */
      VDYFSVelCorrMon.f_VelConfDiff = CML_f_Abs(f_ALNVelocity - f_CorrectedVelocity);

      /* if velocity difference is inside of allowed velocity range, decrement fault count, otherwise increment fault count */
      if (VDYFSVelCorrMon.f_VelConfDiff < VDY_FS_VEL_CONF_MAX_VEL_DIFF)
      {
        VDYFSVelCorrMon.u_UpConfCounter = 0U;
        if (VDYFSVelCorrMon.u_DownConfCounter < VEL_CORR_ALN_MON_MAX_COUNTER )
        {
          VDYFSVelCorrMon.u_DownConfCounter ++;
        }

        if (VDYFSVelCorrMon.u_DownConfCounter >= VEL_CORR_ALN_MON_MAX_COUNTER)
        {
          VDYFSVelCorrMon.confFault = VDY_ERR_STATE_INACTIVE;
          u_noFallBack_CF_Quality = 1U;
        }
      }
      else
      {
        VDYFSVelCorrMon.u_DownConfCounter = 0U;
        if (VDYFSVelCorrMon.u_UpConfCounter < VEL_CORR_ALN_MON_MAX_COUNTER)
        {
          VDYFSVelCorrMon.u_UpConfCounter++;
        }

        if (VDYFSVelCorrMon.u_UpConfCounter >= VEL_CORR_ALN_MON_MAX_COUNTER)
        {
          VDYFSVelCorrMon.confFault = VDY_ERR_STATE_ACTIVE;
        }
        /* Process all calibration learning on roll bench detection or PlantMode and driving*/
        #if((VDY_VEH_DYN_INTFVER >= 8U) || (BSW_VDY_CTRL_DATA_INTFVER >= 3U))
        if((( b_EMProbRTBRecog ) && (CORRECTED_EGO_SPEED_IS_ZERO_ON_ROLLER_BENCH != 1)) || (input->Frame.ProductionMode == TRUE))
        {
          VDYFSVelCorrMon.fault = VDY_ERR_STATE_INACTIVE;
        }
        #endif
      }
    }
  }
}

#endif
#elif((!CFG_VDY_FS_VELO_CORR_MON) && (CFG_VDY_DO_VELOCITY_CORR))
/* ***********************************************************************
  @fn               VDYUncorrVelMonitoring*/ /*!
  @brief            Monitor velocity 

  @description      Flag to check if ALN velocity and VDY velocity are alligned for the first time after startup
                    based on which the correction factor variance will be switched from 0.0225 to the computed value
   
  @param[in]        fUncorrectedVelocity input velocity
  @param[in]        fUncorrectedVelocityVar input velocity variance
  @param[in]        fALNVelocity velocity from ALN
  @param[in]        fALNVelocityDev velocity standard deviation from ALN
  @return           void

  @pre              -
  @post             -
**************************************************************************** */
STATIC_MTD void VDYUncorrVelMonitoring(float32 f_UncorrectedVelocity, float32 f_UncorrectedVelocityVar, float32 f_ALNVelocity, float32 f_ALNVelocityDev)
{

   float32 f_velDiff;
   float32 f_threshold;
   float32 f_varRange;

  /* ALN will only provide a velocity above 20kph, but check if we have a vehicle velocity at all */
  if (f_UncorrectedVelocity > 0.0F)
  {
    /* Calculate difference and uncertainty of estimated velocities and check for negative variance */
    f_velDiff = (f_ALNVelocity - f_UncorrectedVelocity);
    f_threshold = f_UncorrectedVelocity * VDY_FS_VEL_MON_RAT_THRHD;
    
    if (f_UncorrectedVelocityVar >= 0.0F)
    {
      float32 f_velRangeDiff;
      float32 f_velDiffAbs = CML_f_Abs(f_velDiff);

      f_varRange = (float32)(4.0  * (float32)(VDY_SQRT(f_UncorrectedVelocityVar) + f_ALNVelocityDev));
      f_velRangeDiff = CML_f_Abs(f_velDiff) - f_varRange;
    
      /* if velocity difference is inside of allowed velocity range, decrement fault count, otherwise increment fault count */
      if (   (f_velRangeDiff  < f_threshold)
          || (f_velDiffAbs < 2.0 )    )
      {
        b_init_CorrFlag = TRUE ; 
      }
    }
  }
}
#endif

/** @} */ 
/* EOF */
