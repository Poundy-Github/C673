/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      SAC - Stereo Auto Calibration

  MODULNAME:      viscr_defs.h  

  DESCRIPTION:    defines for SAC

  AUTHOR:         L. GARCIA

  CREATION DATE:  23.03.2011

  VERSION:        $Revision: 1.1 $

  CHANGES:        $Log: viscr_defs.h  $
  CHANGES:        Revision 1.1 2021/12/13 17:28:25CET Wang, David (Wangd3) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.0 2017/03/03 10:40:06CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.106 2014/04/01 15:15:09CEST Ruland, Thomas (uidw0251) 
  CHANGES:        Merged in activation of FIYAC from I330_FIYAC branch
  CHANGES:        - Added comments -  uidw0251 [Apr 1, 2014 3:15:10 PM CEST]
  CHANGES:        Change Package : 210743:1 http://mks-psad:7002/im/viewissue?selection=210743
  CHANGES:        Revision 1.105 2014/03/21 18:40:00CET Mueller, Reik (muellerr5) 
  CHANGES:        - restored 1.103
  CHANGES:        --- Added comments ---  muellerr5 [Mar 21, 2014 6:40:00 PM CET]
  CHANGES:        Change Package : 199840:1 http://mks-psad:7002/im/viewissue?selection=199840
  CHANGES:        Revision 1.104 2014/03/21 18:37:59CET Mueller, Reik (muellerr5) 
  CHANGES:        - disabled VISCR_SMPC_STEREO_YAW_CALIBRATION_ODOMETER
  CHANGES:        - enabled VISCR_SMPC_STEREO_YAW_CALIBRATION_IMAGE
  CHANGES:        --- Added comments ---  muellerr5 [Mar 21, 2014 6:37:59 PM CET]
  CHANGES:        Change Package : 199840:1 http://mks-psad:7002/im/viewissue?selection=199840
  CHANGES:        Revision 1.103 2014/03/20 13:13:43CET Mueller, Reik (muellerr5) 
  CHANGES:        - added configuration define to disable any stereo yaw calibration
  CHANGES:        --- Added comments ---  muellerr5 [Mar 20, 2014 1:13:44 PM CET]
  CHANGES:        Change Package : 199840:1 http://mks-psad:7002/im/viewissue?selection=199840
  CHANGES:        Revision 1.102 2014/02/27 12:13:30CET Caron, Thibault (uidw3103) 
  CHANGES:        StereoYaw Calibration connection with SAC
  CHANGES:        --- Added comments ---  uidw3103 [Feb 27, 2014 12:13:31 PM CET]
  CHANGES:        Change Package : 207661:2 http://mks-psad:7002/im/viewissue?selection=207661
  CHANGES:        Revision 1.101 2014/02/17 11:07:39CET Caron, Thibault (uidw3103) 
  CHANGES:        Update of the STD computation
  CHANGES:        --- Added comments ---  uidw3103 [Feb 17, 2014 11:07:39 AM CET]
  CHANGES:        Change Package : 207661:1 http://mks-psad:7002/im/viewissue?selection=207661
  CHANGES:        Revision 1.100 2014/02/06 13:45:00CET Ruland, Thomas (uidw0251) 
  CHANGES:        Adaption to changed stereo image map sizes
  CHANGES:        --- Added comments ---  uidw0251 [Feb 6, 2014 1:45:01 PM CET]
  CHANGES:        Change Package : 216853:1 http://mks-psad:7002/im/viewissue?selection=216853
  CHANGES:        Revision 1.99 2013/12/06 11:48:07CET Caron, Thibault (uidw3103) 
  CHANGES:        Disable stereo yaw debug mode
  CHANGES:        --- Added comments ---  uidw3103 [Dec 6, 2013 11:48:08 AM CET]
  CHANGES:        Change Package : 207661:1 http://mks-psad:7002/im/viewissue?selection=207661
  CHANGES:        Revision 1.98 2013/12/05 16:24:23CET Caron, Thibault (uidw3103) 
  CHANGES:        Addition of a condition to enable or not stereoyaw calibration code
  CHANGES:        --- Added comments ---  uidw3103 [Dec 5, 2013 4:24:23 PM CET]
  CHANGES:        Change Package : 207661:1 http://mks-psad:7002/im/viewissue?selection=207661
  CHANGES:        Revision 1.97 2013/11/27 16:45:17CET Ruland, Thomas (uidw0251) 
  CHANGES:        - Adapting viscr_defs.h parameters if compiled in SDE environment to allow faster convergence
  CHANGES:        - Improved verbosity of parseSDLFile in case of signal search errors
  CHANGES:        - Redesigned SDE MF handling in algo_execute
  CHANGES:        - Displaying rectifying and internal state rotation matrix
  CHANGES:        - improved visualization of epi-corrs from SAC MF
  CHANGES:        - added parameter degradation method
  CHANGES:        --- Added comments ---  uidw0251 [Nov 27, 2013 4:45:17 PM CET]
  CHANGES:        Change Package : 196075:1 http://mks-psad:7002/im/viewissue?selection=196075
  CHANGES:        Revision 1.96 2013/10/19 16:20:52CEST Mueller, Reik (muellerr5) 
  CHANGES:        - added MAX_YAW_SAMPLES_PER_FRAME
  CHANGES:        --- Added comments ---  muellerr5 [Oct 19, 2013 4:20:52 PM CEST]
  CHANGES:        Change Package : 202434:1 http://mks-psad:7002/im/viewissue?selection=202434
  CHANGES:        Revision 1.95 2013/05/03 18:49:05CEST Mueller, Reik (muellerr5) 
  CHANGES:        - activated camera based yaw calibration
  CHANGES:        --- Added comments ---  muellerr5 [May 3, 2013 6:49:05 PM CEST]
  CHANGES:        Change Package : 173648:2 http://mks-psad:7002/im/viewissue?selection=173648
  CHANGES:        Revision 1.94 2013/05/03 18:29:10CEST Stache, Nicolaj (uidt6711) 
  CHANGES:        merge from devpath
  CHANGES:        --- Added comments ---  uidt6711 [May 3, 2013 6:29:10 PM CEST]
  CHANGES:        Change Package : 67326:3 http://mks-psad:7002/im/viewissue?selection=67326
  CHANGES:        Revision 1.93.1.1 2013/04/23 19:18:18CEST Garcia, Lucien (uid26778) 
  CHANGES:        Restart all distance timers in case of odometer jumps
  CHANGES:        --- Added comments ---  uid26778 [Apr 23, 2013 7:18:19 PM CEST]
  CHANGES:        Change Package : 180696:1 http://mks-psad:7002/im/viewissue?selection=180696
  CHANGES:        Revision 1.93 2012/09/14 14:10:13CEST Lugez, Boris (uidt2765) 
  CHANGES:        -> update stereo-yawangle-code (reviewed by Lucien)
  CHANGES:        --- Added comments ---  uidt2765 [Sep 14, 2012 2:10:17 PM CEST]
  CHANGES:        Change Package : 158543:1 http://mks-psad:7002/im/viewissue?selection=158543
  CHANGES:        Revision 1.92 2012/07/27 12:18:12CEST Garcia, Lucien (uid26778) 
  CHANGES:        Distance Test : Remove the loop in order to have the same behaviour than the 4.6.
  CHANGES:        --- Added comments ---  uid26778 [Jul 27, 2012 12:18:14 PM CEST]
  CHANGES:        Change Package : 142649:1 http://mks-psad:7002/im/viewissue?selection=142649
  CHANGES:        Revision 1.91 2012/07/23 18:59:41CEST Stache, Nicolaj (uidt6711) 
  CHANGES:        weighting function for wss distortion model implemented
  CHANGES:        --- Added comments ---  uidt6711 [Jul 23, 2012 6:59:41 PM CEST]
  CHANGES:        Change Package : 67326:3 http://mks-psad:7002/im/viewissue?selection=67326
  CHANGES:        Revision 1.90 2012/07/20 11:04:18CEST Garcia, Lucien (uid26778) 
  CHANGES:        Improve distance test accuracy at 10m (new requirement) by making several calibrations instead of one.
  CHANGES:        --- Added comments ---  uid26778 [Jul 20, 2012 11:04:19 AM CEST]
  CHANGES:        Change Package : 142649:1 http://mks-psad:7002/im/viewissue?selection=142649
  CHANGES:        Revision 1.89 2012/06/26 11:00:44CEST Visscher-EXT, Eric (uidk7517) 
  CHANGES:        Code review comments added
  CHANGES:        --- Added comments ---  uidk7517 [Jun 26, 2012 11:00:45 AM CEST]
  CHANGES:        Change Package : 127722:1 http://mks-psad:7002/im/viewissue?selection=127722
  CHANGES:        Revision 1.88 2012/06/15 16:49:52CEST Garcia, Lucien (uid26778) 
  CHANGES:        Reduce eol stereo calib runtime due to Daimler plant time constraint (3 try in 5s)
  CHANGES:        --- Added comments ---  uid26778 [Jun 15, 2012 4:49:52 PM CEST]
  CHANGES:        Change Package : 128857:1 http://mks-psad:7002/im/viewissue?selection=128857
  CHANGES:        Revision 1.87 2012/05/21 20:04:06CEST Garcia, Lucien (uid26778) 
  CHANGES:        Add error code for eol calibration function
  CHANGES:        --- Added comments ---  uid26778 [May 21, 2012 8:04:09 PM CEST]
  CHANGES:        Change Package : 94275:1 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.86 2012/04/26 10:48:34CEST Garcia, Lucien (uid26778) 
  CHANGES:        Stereo end of line update
  CHANGES:        --- Added comments ---  uid26778 [Apr 26, 2012 10:48:34 AM CEST]
  CHANGES:        Change Package : 94275:1 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.85 2012/04/17 17:16:16CEST Garcia, Lucien (uid26778) 
  CHANGES:        Improve RL powerflow direction check
  CHANGES:        --- Added comments ---  uid26778 [Apr 17, 2012 5:16:19 PM CEST]
  CHANGES:        Change Package : 111349:1 http://mks-psad:7002/im/viewissue?selection=111349
  CHANGES:        Revision 1.84 2012/04/16 11:04:20CEST Garcia, Lucien (uid26778) 
  CHANGES:        Reduce eol timeout value
  CHANGES:        --- Added comments ---  uid26778 [Apr 16, 2012 11:04:20 AM CEST]
  CHANGES:        Change Package : 106060:2 http://mks-psad:7002/im/viewissue?selection=106060
  CHANGES:        Revision 1.83 2012/04/03 17:31:08CEST Garcia, Lucien (uid26778) 
  CHANGES:        Add global coarse timeout
  CHANGES:        --- Added comments ---  uid26778 [Apr 3, 2012 5:31:08 PM CEST]
  CHANGES:        Change Package : 94275:2 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.82 2012/03/30 14:06:10CEST Garcia, Lucien (uid26778) 
  CHANGES:        Lint warning corrections : Bitexactness test and MTS simulation OK
  CHANGES:        --- Added comments ---  uid26778 [Mar 30, 2012 2:06:10 PM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.81 2012/03/29 11:29:09CEST Garcia, Lucien (uid26778) 
  CHANGES:        Implement distance test and merge eol calibration function
  CHANGES:        --- Added comments ---  uid26778 [Mar 29, 2012 11:29:09 AM CEST]
  CHANGES:        Change Package : 94275:2 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.80 2012/03/13 18:21:27CET Garcia, Lucien (uid26778) 
  CHANGES:        Add robustness to eol calibration function and parameter tuning
  CHANGES:        --- Added comments ---  uid26778 [Mar 13, 2012 6:21:27 PM CET]
  CHANGES:        Change Package : 94275:1 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.79 2012/03/13 18:17:12CET Garcia, Lucien (uid26778) 
  CHANGES:        Remove Lint warning (bitexactness test done)
  CHANGES:        --- Added comments ---  uid26778 [Mar 13, 2012 6:17:12 PM CET]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.78 2012/03/08 12:53:29CET Konarski-EXT, Witek (uidt8403) 
  CHANGES:        Removed PC-Lint/Misra error.
  CHANGES:        --- Added comments ---  uidt8403 [Mar 8, 2012 12:53:30 PM CET]
  CHANGES:        Change Package : 101150:11 http://mks-psad:7002/im/viewissue?selection=101150
  CHANGES:        Revision 1.77 2012/02/23 18:10:21CET Garcia, Lucien (uid26778) 
  CHANGES:        Update EOL calibration mode
  CHANGES:        --- Added comments ---  uid26778 [Feb 23, 2012 6:10:21 PM CET]
  CHANGES:        Change Package : 94275:1 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.76 2012/01/19 14:22:25CET Garcia, Lucien (uid26778) 
  CHANGES:        First integration of stereo EOL calibration
  CHANGES:        --- Added comments ---  uid26778 [Jan 19, 2012 2:22:26 PM CET]
  CHANGES:        Change Package : 94275:1 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.75 2011/12/16 10:29:33CET Garcia, Lucien (uid26778) 
  CHANGES:        Because some heater wires are in front of the camera, we should increased the quality threshold
  CHANGES:        --- Added comments ---  uid26778 [Dec 16, 2011 10:29:34 AM CET]
  CHANGES:        Change Package : 91934:1 http://mks-psad:7002/im/viewissue?selection=91934
  CHANGES:        Revision 1.74 2011/12/01 11:03:16CET Garcia, Lucien (uid26778) 
  CHANGES:        Add input filter because wrong imager temperatures could occur.
  CHANGES:        --- Added comments ---  uid26778 [Dec 1, 2011 11:03:16 AM CET]
  CHANGES:        Change Package : 90060:1 http://mks-psad:7002/im/viewissue?selection=90060
  CHANGES:        Revision 1.73 2011/11/29 16:55:05CET Garcia, Lucien (uid26778) 
  CHANGES:        Improve Fine calibration runtime : less features selected per frame
  CHANGES:        --- Added comments ---  uid26778 [Nov 29, 2011 4:55:06 PM CET]
  CHANGES:        Change Package : 87584:1 http://mks-psad:7002/im/viewissue?selection=87584
  CHANGES:        Revision 1.72 2011/11/25 15:01:27CET Garcia, Lucien (uid26778) 
  CHANGES:        Split LUT generation in 2 frames (runtime improvement)
  CHANGES:        --- Added comments ---  uid26778 [Nov 25, 2011 3:01:27 PM CET]
  CHANGES:        Change Package : 87584:1 http://mks-psad:7002/im/viewissue?selection=87584
  CHANGES:        Revision 1.71 2011/11/25 08:33:15CET Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        LUT generation is splitted in 2 frames to avoid runtime peaks (see configuration VISCR_SMPC_INITLUT_SPLITTED)
  CHANGES:        --- Added comments ---  uid26778 [Nov 25, 2011 8:33:15 AM CET]
  CHANGES:        Change Package : 87584:1 http://mks-psad:7002/im/viewissue?selection=87584
  CHANGES:        Revision 1.70 2011/11/16 19:35:01CET Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        In fine calibration, the number of points per bins could changed
  CHANGES:        --- Added comments ---  uid26778 [Nov 16, 2011 7:35:01 PM CET]
  CHANGES:        Change Package : 87607:1 http://mks-psad:7002/im/viewissue?selection=87607
  CHANGES:        Revision 1.69 2011/11/14 11:48:44CET Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Improve runtime consumption
  CHANGES:        --- Added comments ---  uid26778 [Nov 14, 2011 11:48:44 AM CET]
  CHANGES:        Change Package : 87584:1 http://mks-psad:7002/im/viewissue?selection=87584
  CHANGES:        Revision 1.68 2011/11/11 18:00:27CET Stache Nicolaj (uidt6711) (uidt6711) 
  CHANGES:        3.2.0 Bugfix
  CHANGES:        --- Added comments ---  uidt6711 [Nov 11, 2011 6:00:27 PM CET]
  CHANGES:        Change Package : 87835:1 http://mks-psad:7002/im/viewissue?selection=87835
  CHANGES:        Revision 1.67 2011/10/25 15:17:20CEST Stache Nicolaj (uidt6711) (uidt6711) 
  CHANGES:        3.2.0 Int16
  CHANGES:        --- Added comments ---  uidt6711 [Oct 25, 2011 3:17:21 PM CEST]
  CHANGES:        Change Package : 67326:1 http://mks-psad:7002/im/viewissue?selection=67326
  CHANGES:        Revision 1.65.1.1 2011/10/21 17:08:41CEST Wagner Ulrich (uid04769) (uid04769) 
  CHANGES:        Turned on yaw-calibration, again
  CHANGES:        --- Added comments ---  uid04769 [Oct 21, 2011 5:08:41 PM CEST]
  CHANGES:        Change Package : 37886:2 http://mks-psad:7002/im/viewissue?selection=37886
  CHANGES:        Revision 1.66 2011/10/21 17:04:40CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Use only 2 vertical bins for coarse calibration (epipolar constraint)
  CHANGES:        --- Added comments ---  uid26778 [Oct 21, 2011 5:04:40 PM CEST]
  CHANGES:        Change Package : 80275:3 http://mks-psad:7002/im/viewissue?selection=80275
  CHANGES:        Revision 1.65 2011/10/21 14:11:10CEST Wagner Ulrich (uid04769) (uid04769) 
  CHANGES:        Yaw angle calibration turned off
  CHANGES:        --- Added comments ---  uid04769 [Oct 21, 2011 2:11:10 PM CEST]
  CHANGES:        Change Package : 37886:2 http://mks-psad:7002/im/viewissue?selection=37886
  CHANGES:        Revision 1.64 2011/10/14 12:25:04CEST Stache Nicolaj (uidt6711) (uidt6711) 
  CHANGES:        3.2.0 Bugfix -> Input check after initialisation of depth filed
  CHANGES:        --- Added comments ---  uidt6711 [Oct 14, 2011 12:25:04 PM CEST]
  CHANGES:        Change Package : 67326:1 http://mks-psad:7002/im/viewissue?selection=67326
  CHANGES:        Revision 1.63 2011/10/10 17:34:35CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        switch off open loop radar yaw calib simulation
  CHANGES:        --- Added comments ---  spruckj [Oct 10, 2011 5:34:35 PM CEST]
  CHANGES:        Change Package : 79035:1 http://mks-psad:7002/im/viewissue?selection=79035
  CHANGES:        Revision 1.62 2011/10/10 17:33:43CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        move open loop simulation switch for radar bases yaw callib to viscr_defs.h
  CHANGES:        --- Added comments ---  spruckj [Oct 10, 2011 5:33:43 PM CEST]
  CHANGES:        Change Package : 79035:1 http://mks-psad:7002/im/viewissue?selection=79035
  CHANGES:        Revision 1.61 2011/10/10 17:09:44CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        Add compiler switches for radar based open loop simulation
  CHANGES:        --- Added comments ---  spruckj [Oct 10, 2011 5:09:44 PM CEST]
  CHANGES:        Change Package : 79036:2 http://mks-psad:7002/im/viewissue?selection=79036
  CHANGES:        Revision 1.60 2011/10/05 08:26:44CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        Remove misra issues
  CHANGES:        Revision 1.59 2011/10/04 18:24:34CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Remove lint warnings
  CHANGES:        --- Added comments ---  uid26778 [Oct 4, 2011 6:24:34 PM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.58 2011/10/01 15:50:37CEST Stache Nicolaj (uidt6711) (uidt6711) 
  CHANGES:        3.2.0 Subrelease 3 Bugfix 1
  CHANGES:        --- Added comments ---  uidt6711 [Oct 1, 2011 3:50:37 PM CEST]
  CHANGES:        Change Package : 67326:1 http://mks-psad:7002/im/viewissue?selection=67326
  CHANGES:        Revision 1.57 2011/09/29 16:31:30CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Remove warnings on timeout mng
  CHANGES:        --- Added comments ---  uid26778 [Sep 29, 2011 4:31:30 PM CEST]
  CHANGES:        Change Package : 79047:3 http://mks-psad:7002/im/viewissue?selection=79047
  CHANGES:        Revision 1.56 2011/09/29 15:18:05CEST Stache Nicolaj (uidt6711) (uidt6711) 
  CHANGES:        Integrate Radar-based Yaw-Calibration
  CHANGES:        --- Added comments ---  uidt6711 [Sep 29, 2011 3:18:05 PM CEST]
  CHANGES:        Change Package : 67326:1 http://mks-psad:7002/im/viewissue?selection=67326
  CHANGES:        Revision 1.55 2011/09/29 09:26:38CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Coarse and Fine Timeout management
  CHANGES:        Default configuration management for quality thresholds and timeouts
  CHANGES:        --- Added comments ---  uid26778 [Sep 29, 2011 9:26:38 AM CEST]
  CHANGES:        Change Package : 79047:3 http://mks-psad:7002/im/viewissue?selection=79047
  CHANGES:        Revision 1.54 2011/09/28 15:08:10CEST Stache Nicolaj (uidt6711) (uidt6711) 
  CHANGES:        Roi-Shift error is passed through
  CHANGES:        --- Added comments ---  uidt6711 [Sep 28, 2011 3:08:10 PM CEST]
  CHANGES:        Change Package : 67327:1 http://mks-psad:7002/im/viewissue?selection=67327
  CHANGES:        Revision 1.53 2011/09/27 14:08:35CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Use anti-bounce counter for SAC_ERROR_SAC_FINE_OUT_OF_RANGE error
  CHANGES:        --- Added comments ---  uid26778 [Sep 27, 2011 2:08:36 PM CEST]
  CHANGES:        Change Package : 79047:2 http://mks-psad:7002/im/viewissue?selection=79047
  CHANGES:        Revision 1.52 2011/09/26 16:48:52CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Use the same quality check for fine and coarse calibration
  CHANGES:        --- Added comments ---  uid26778 [Sep 26, 2011 4:48:52 PM CEST]
  CHANGES:        Change Package : 79047:1 http://mks-psad:7002/im/viewissue?selection=79047
  CHANGES:        Revision 1.51 2011/09/20 19:24:19CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Enable input and output error checks
  CHANGES:        --- Added comments ---  uid26778 [Sep 20, 2011 7:24:19 PM CEST]
  CHANGES:        Change Package : 77279:1 http://mks-psad:7002/im/viewissue?selection=77279
  CHANGES:        Revision 1.50 2011/09/20 15:24:47CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        ADD DEM error when SAC rectification is not good in fine mode
  CHANGES:        --- Added comments ---  uid26778 [Sep 20, 2011 3:24:47 PM CEST]
  CHANGES:        Change Package : 77279:1 http://mks-psad:7002/im/viewissue?selection=77279
  CHANGES:        Revision 1.49 2011/09/20 13:36:04CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Add errors in case of bad rectification quality for FOD, POD, SLNE and PV functions
  CHANGES:        --- Added comments ---  uid26778 [Sep 20, 2011 1:36:04 PM CEST]
  CHANGES:        Change Package : 77279:1 http://mks-psad:7002/im/viewissue?selection=77279
  CHANGES:        Revision 1.48 2011/09/19 19:12:13CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Add MAX_RL_POWERFLOW_V configuration
  CHANGES:        --- Added comments ---  uid26778 [Sep 19, 2011 7:12:14 PM CEST]
  CHANGES:        Change Package : 77279:4 http://mks-psad:7002/im/viewissue?selection=77279
  CHANGES:        Revision 1.47 2011/09/17 18:56:44CEST Stache Nicolaj (uidt6711) (uidt6711) 
  CHANGES:        Implementation of ROIshift and Scaling
  CHANGES:        --- Added comments ---  uidt6711 [Sep 17, 2011 6:56:44 PM CEST]
  CHANGES:        Change Package : 67327:1 http://mks-psad:7002/im/viewissue?selection=67327
  CHANGES:        Revision 1.44 2011/09/14 10:46:49CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Add extented fine mode
  CHANGES:        --- Added comments ---  uid26778 [Sep 14, 2011 10:46:49 AM CEST]
  CHANGES:        Change Package : 77279:2 http://mks-psad:7002/im/viewissue?selection=77279
  CHANGES:        Revision 1.43 2011/09/12 17:05:25CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Add extended fine mode
  CHANGES:        --- Added comments ---  uid26778 [Sep 12, 2011 5:05:25 PM CEST]
  CHANGES:        Change Package : 77279:2 http://mks-psad:7002/im/viewissue?selection=77279
  CHANGES:        Revision 1.41 2011/09/09 15:43:18CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Add extented fine calibration mode
  CHANGES:        --- Added comments ---  uid26778 [Sep 9, 2011 3:43:18 PM CEST]
  CHANGES:        Change Package : 77279:2 http://mks-psad:7002/im/viewissue?selection=77279
  CHANGES:        Revision 1.40 2011/09/05 17:17:33CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Improve disparity accuracy
  CHANGES:        --- Added comments ---  uid26778 [Sep 5, 2011 5:17:33 PM CEST]
  CHANGES:        Change Package : 76623:1 http://mks-psad:7002/im/viewissue?selection=76623
  CHANGES:        Revision 1.39 2011/08/26 13:30:00CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Configuration update
  CHANGES:        --- Added comments ---  uid26778 [Aug 26, 2011 1:30:00 PM CEST]
  CHANGES:        Change Package : 76623:1 http://mks-psad:7002/im/viewissue?selection=76623
  CHANGES:        Revision 1.38 2011/08/26 10:25:24CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Integration of new yaw angle calibration algoritm (Daimler update)
  CHANGES:        --- Added comments ---  uid26778 [Aug 26, 2011 10:25:24 AM CEST]
  CHANGES:        Change Package : 76623:1 http://mks-psad:7002/im/viewissue?selection=76623
  CHANGES:        Revision 1.37 2011/08/22 13:08:21CEST Stache Nicolaj (uidt6711) (uidt6711) 
  CHANGES:        started to implement the corrected yaw angle correction via stereo
  CHANGES:        --- Added comments ---  uidt6711 [Aug 22, 2011 1:08:21 PM CEST]
  CHANGES:        Change Package : 67326:1 http://mks-psad:7002/im/viewissue?selection=67326
  CHANGES:        Revision 1.36 2011/08/18 15:56:41CEST Kozek Werner (uidt8688) (uidt8688) 
  CHANGES:        preprocessor flags for disabling FUSI checks
  CHANGES:        --- Added comments ---  uidt8688 [Aug 18, 2011 3:56:41 PM CEST]
  CHANGES:        Change Package : 63914:4 http://mks-psad:7002/im/viewissue?selection=63914
  CHANGES:        Revision 1.35 2011/08/16 09:44:13CEST Kozek Werner (uidt8688) (uidt8688) 
  CHANGES:        preprocessor flag for disabling input checks added
  CHANGES:        --- Added comments ---  uidt8688 [Aug 16, 2011 9:44:14 AM CEST]
  CHANGES:        Change Package : 63914:4 http://mks-psad:7002/im/viewissue?selection=63914
  CHANGES:        Revision 1.34 2011/08/03 17:00:44CEST Stache Nicolaj (uidt6711) (uidt6711) 
  CHANGES:        started to work on ROI shift
  CHANGES:        --- Added comments ---  uidt6711 [Aug 3, 2011 5:00:44 PM CEST]
  CHANGES:        Change Package : 67326:1 http://mks-psad:7002/im/viewissue?selection=67326
  CHANGES:        Revision 1.33 2011/07/29 10:49:41CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Rejection function could be call just before to save the points in order to save run-time
  CHANGES:        Reduce the distance between correspondences
  CHANGES:        --- Added comments ---  uid26778 [Jul 29, 2011 10:49:41 AM CEST]
  CHANGES:        Change Package : 67298:1 http://mks-psad:7002/im/viewissue?selection=67298
  CHANGES:        Revision 1.32 2011/07/28 18:39:34CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Add VISCR_SMPC_FILTERING_GOOD_RMSE
  CHANGES:        --- Added comments ---  uid26778 [Jul 28, 2011 6:39:34 PM CEST]
  CHANGES:        Change Package : 67298:1 http://mks-psad:7002/im/viewissue?selection=67298
  CHANGES:        Revision 1.31 2011/07/28 13:10:45CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Add new filtering mode VISCR_SMPC_FILTERING_MODE = 1
  CHANGES:        Improve quality measurements
  CHANGES:        --- Added comments ---  uid26778 [Jul 28, 2011 1:10:45 PM CEST]
  CHANGES:        Change Package : 67298:1 http://mks-psad:7002/im/viewissue?selection=67298
  CHANGES:        Revision 1.30 2011/07/26 19:46:54CEST Stache Nicolaj (uidt6711) (uidt6711) 
  CHANGES:        3.1.0 Lib2 Update
  CHANGES:        --- Added comments ---  uidt6711 [Jul 26, 2011 7:46:54 PM CEST]
  CHANGES:        Change Package : 67326:1 http://mks-psad:7002/im/viewissue?selection=67326
  CHANGES:        Revision 1.29 2011/07/26 15:55:44CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        mark safety relevant datas
  CHANGES:        --- Added comments ---  uid26778 [Jul 26, 2011 3:55:44 PM CEST]
  CHANGES:        Change Package : 67298:1 http://mks-psad:7002/im/viewissue?selection=67298
  CHANGES:        Revision 1.28 2011/07/07 20:00:17CEST Stache Nicolaj (uidt6711) (uidt6711) 
  CHANGES:        3.1 Release Int1
  CHANGES:        --- Added comments ---  uidt6711 [Jul 7, 2011 8:00:17 PM CEST]
  CHANGES:        Change Package : 67326:1 http://mks-psad:7002/im/viewissue?selection=67326
  CHANGES:        Revision 1.27 2011/07/07 16:03:25CEST Stache Nicolaj (uidt6711) (uidt6711) 
  CHANGES:        Interface freeze
  CHANGES:        --- Added comments ---  uidt6711 [Jul 7, 2011 4:03:26 PM CEST]
  CHANGES:        Change Package : 67326:1 http://mks-psad:7002/im/viewissue?selection=67326
  CHANGES:        Revision 1.26 2011/07/07 13:07:19CEST Kozek Werner (uidt8688) (uidt8688) 
  CHANGES:        added parameter MIN_DIST_BIN_FEATURE for parametrization of feature rejection logic
  CHANGES:        --- Added comments ---  uidt8688 [Jul 7, 2011 1:07:19 PM CEST]
  CHANGES:        Change Package : 63914:2 http://mks-psad:7002/im/viewissue?selection=63914
  CHANGES:        Revision 1.25 2011/07/06 19:01:47CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Autocalibration quality measurementand improvement
  CHANGES:        --- Added comments ---  uid26778 [Jul 6, 2011 7:01:47 PM CEST]
  CHANGES:        Change Package : 67298:1 http://mks-psad:7002/im/viewissue?selection=67298
  CHANGES:        Revision 1.24 2011/06/17 13:31:24CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Add new configuration swithes
  CHANGES:        --- Added comments ---  uid26778 [Jun 17, 2011 1:31:24 PM CEST]
  CHANGES:        Change Package : 67298:1 http://mks-psad:7002/im/viewissue?selection=67298
  CHANGES:        Revision 1.23 2011/06/15 12:53:52CEST Stache Nicolaj (uidt6711) (uidt6711) 
  CHANGES:        Mod: Uses 30 Features in fine calibration.
  CHANGES:        Mod: Modified feature distribution.
  CHANGES:        Bugfix: initialisation of internal rot NVM array
  CHANGES:        --- Added comments ---  uidt6711 [Jun 15, 2011 12:53:53 PM CEST]
  CHANGES:        Change Package : 67326:1 http://mks-psad:7002/im/viewissue?selection=67326
  CHANGES:        Revision 1.22 2011/06/07 17:53:40CEST Stache Nicolaj (uidt6711) (uidt6711) 
  CHANGES:        Fixedpointed cost function, new random number generator for feature selection (modifications by Werner Kozek)
  CHANGES:        --- Added comments ---  uidt6711 [Jun 7, 2011 5:53:40 PM CEST]
  CHANGES:        Change Package : 67326:2 http://mks-psad:7002/im/viewissue?selection=67326
  CHANGES:        Revision 1.21 2011/05/30 16:54:29CEST Stache Nicolaj (uidt6711) (uidt6711) 
  CHANGES:        Mod: Heap sort for quality check criterion
  CHANGES:        --- Added comments ---  uidt6711 [May 30, 2011 4:54:30 PM CEST]
  CHANGES:        Change Package : 67326:2 http://mks-psad:7002/im/viewissue?selection=67326
  CHANGES:        Revision 1.20 2011/05/24 22:21:13CEST Stache Nicolaj (uidt6711) (uidt6711) 
  CHANGES:        2.5.1 lib1
  CHANGES:        --- Added comments ---  uidt6711 [May 24, 2011 10:21:13 PM CEST]
  CHANGES:        Change Package : 67326:2 http://mks-psad:7002/im/viewissue?selection=67326
  CHANGES:        Revision 1.17.1.1 2011/05/24 21:27:55CEST Stache Nicolaj (uidt6711) (uidt6711) 
  CHANGES:        2.5.1 Lib1 release
  CHANGES:        --- Added comments ---  uidt6711 [May 24, 2011 9:27:56 PM CEST]
  CHANGES:        Change Package : 67326:2 http://mks-psad:7002/im/viewissue?selection=67326
  CHANGES:        Revision 1.17 2011/05/23 13:46:26CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Add verfical filter for right left powerflow
  CHANGES:        --- Added comments ---  uid26778 [May 23, 2011 1:46:26 PM CEST]
  CHANGES:        Change Package : 67298:1 http://mks-psad:7002/im/viewissue?selection=67298
  CHANGES:        Revision 1.16 2011/05/12 13:47:05CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        First integration of autocalibration code into SAC module
  CHANGES:        --- Added comments ---  uid26778 [May 12, 2011 1:47:05 PM CEST]
  CHANGES:        Change Package : 58789:1 http://mks-psad:7002/im/viewissue?selection=58789
  CHANGES:        Revision 1.15 2011/05/10 17:47:57CEST Stache Nicolaj (uidt6711) (uidt6711) 
  CHANGES:        Modification: number of features in bins in coarse calibration is not influenced by fine calibration settings
  CHANGES:        --- Added comments ---  uidt6711 [May 10, 2011 5:47:58 PM CEST]
  CHANGES:        Change Package : 58788:2 http://mks-psad:7002/im/viewissue?selection=58788
  CHANGES:        Revision 1.14 2011/05/09 17:03:58CEST Stache Nicolaj (uidt6711) (uidt6711) 
  CHANGES:        Modification: SAC can be executed in parallel-mode unless coarse calibration has not been finished (in this case measfreezes are made)
  CHANGES:        --- Added comments ---  uidt6711 [May 9, 2011 5:03:58 PM CEST]
  CHANGES:        Change Package : 58788:2 http://mks-psad:7002/im/viewissue?selection=58788
  CHANGES:        Revision 1.13 2011/05/04 14:21:04CEST Mueller Reik (muellerr5) (muellerr5) 
  CHANGES:        Update from W.Kozek:
  CHANGES:        - set fine cali in parallel mode
  CHANGES:        --- Added comments ---  muellerr5 [May 4, 2011 2:21:04 PM CEST]
  CHANGES:        Change Package : 64689:1 http://mks-psad:7002/im/viewissue?selection=64689
  CHANGES:        --- Added comments ---  muellerr5 [May 4, 2011 2:22:33 PM CEST]
  CHANGES:        Update from W.Kozek:
  CHANGES:        - change number of features per frame
  CHANGES:        Revision 1.12 2011/05/02 18:15:14CEST Mueller Reik (muellerr5) (muellerr5) 
  CHANGES:        Update from W.Kozek:
  CHANGES:        - changed parameters for runtime optimization
  CHANGES:        --- Added comments ---  muellerr5 [May 2, 2011 6:15:14 PM CEST]
  CHANGES:        Change Package : 64689:1 http://mks-psad:7002/im/viewissue?selection=64689
  CHANGES:        Revision 1.11 2011/04/26 18:10:57CEST Stache Nicolaj (uidt6711) (uidt6711) 
  CHANGES:        Improved corner check, output of epi-correspondences and quality measure
  CHANGES:        --- Added comments ---  uidt6711 [Apr 26, 2011 6:10:57 PM CEST]
  CHANGES:        Change Package : 58788:2 http://mks-psad:7002/im/viewissue?selection=58788
  CHANGES:        Revision 1.10 2011/04/20 16:16:41CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        First integration of autocalibration code into SAC module / Yaw calculation activated
  CHANGES:        --- Added comments ---  uid26778 [Apr 20, 2011 4:16:45 PM CEST]
  CHANGES:        Change Package : 58789:1 http://mks-psad:7002/im/viewissue?selection=58789
  CHANGES:        Revision 1.9 2011/04/18 18:03:34CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        First integration of autocalibration code into SAC module
  CHANGES:        --- Added comments ---  uid26778 [Apr 18, 2011 6:03:34 PM CEST]
  CHANGES:        Change Package : 58789:1 http://mks-psad:7002/im/viewissue?selection=58789
  CHANGES:        Revision 1.8 2011/04/17 21:18:57CEST Stache Nicolaj (uidt6711) (uidt6711) 
  CHANGES:        remove yaw activated
  CHANGES:        --- Added comments ---  uidt6711 [Apr 17, 2011 9:18:58 PM CEST]
  CHANGES:        Change Package : 58788:2 http://mks-psad:7002/im/viewissue?selection=58788
  CHANGES:        Revision 1.7 2011/04/15 17:50:43CEST Stache Nicolaj (uidt6711) (uidt6711) 
  CHANGES:        Simulation changes
  CHANGES:        Revision 1.6 2011/04/14 17:29:39CEST Stache Nicolaj (uidt6711) (uidt6711) 
  CHANGES:        LUT height increased to 460 lines. Rectifier input 476 lines, rectifier output 460 lines (used for ROIshift check). SGM and Powerflow 220 lines.
  CHANGES:        Revision 1.5 2011/04/14 16:02:55CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        First integration of autocalibration code into SAC module
  CHANGES:        --- Added comments ---  uid26778 [Apr 14, 2011 4:02:55 PM CEST]
  CHANGES:        Change Package : 58789:1 http://mks-psad:7002/im/viewissue?selection=58789
  CHANGES:        Revision 1.4 2011/04/13 16:26:21CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        First integration of autocalibration code into SAC module
  CHANGES:        --- Added comments ---  uid26778 [Apr 13, 2011 4:26:21 PM CEST]
  CHANGES:        Change Package : 58789:1 http://mks-psad:7002/im/viewissue?selection=58789
  CHANGES:        Revision 1.3 2011/04/07 17:09:54CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        First integration of autocalibration code into SAC module
  CHANGES:        --- Added comments ---  uid26778 [Apr 7, 2011 5:09:54 PM CEST]
  CHANGES:        Change Package : 58789:1 http://mks-psad:7002/im/viewissue?selection=58789
  CHANGES:        Revision 1.2 2011/04/05 16:53:11CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        First integration of autocalibration code into SAC module
  CHANGES:        --- Added comments ---  uid26778 [Apr 5, 2011 4:53:12 PM CEST]
  CHANGES:        Change Package : 58789:1 http://mks-psad:7002/im/viewissue?selection=58789
  CHANGES:        Revision 1.1 2011/03/23 19:23:32CET Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SAC_StereoAutoCalibration/04_Engineering/01_Source_Code/Kernel/project.pj

**************************************************************************** */

#ifndef VISCR_DEFS_H
#define VISCR_DEFS_H

/////// COMPILER SWITCHES  ///////

#define SAC_ALGO_EOL_ENABLE 0
#define SAC_ALGO_EOL_MEDIAN_LEN 20
#define SAC_ALGO_EOL_MEDIAN_LEN_SHORT 16
#define SAC_TIMEOUT_EOL_TIME                       (static_cast<ui64_t>(1400000))  // in microseconds, the goal is we could try 3 calibrations in 5s
// ~CodeReview ~ID:20a499bfa550cab9f5942057628d82f0 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or comment dead code
//#define SAC_TIMEOUT_EOL_TIME                       (static_cast<ui64_t>((30000*SAC_ALGO_EOL_MEDIAN_LEN*10)))  // in microseconds
#define SAC_TIMEOUT_EOL_TIME_ENA                   1U  

#define SAC_TIMEOUT_DISTTEST_TIME                       (static_cast<ui64_t>(15000000))  // in microseconds
#define SAC_TIMEOUT_DISTTEST_TIME_ENA                   1U  
#define SAC_LOOPMAX_DISTTEST                            0U


#define SAC_TIMEOUT_GLOBAL_COARSE_DISTANCE_ENA          1U                                // 0 disable, 1 enable
#define SAC_TIMEOUT_GLOBAL_COARSE_DISTANCE              (static_cast<ui64_t>(50*1000))    // in meters
#define SAC_TIMEOUT_GLOBAL_COARSE_TIME_ENA              0U                                // 0 disable, 1 enable
#define SAC_TIMEOUT_GLOBAL_COARSE_TIME                  1UL                               // in microseconds


// This define should be used for debug purpose
#define SAC_ALGO_DEBUG 0
#define WKO_DEBUG 0
#define DISABLE_INPUT_CHECKS  0
#define DISABLE_OUTPUT_CHECKS 0

#define VISCR_SMPC_DEEPTRACE 0
#define VISCR_SMPC_DEEPTRACE_RECT 0
#define VISCR_SMPC_DEEPTRACE_DISP 0
#define VISCR_SMPC_DEEPTRACE_LASTRECT 0
#define VISCR_SMPC_DEEPTRACE_POWERFLOW 0
#define VISCR_SMPC_DEEPTRACE_SIMILARFLOW 0

#define VISCR_SMPC_DEEPTRACE_YAW 0 // Remove all previous flag

// CONFIGURATION FOR STEREO YAW CALIBRATION
// 0 with odometer 
// 1 with radar VISCR_SMPC_REMOVE_YAW_IN_FINE = 1
// 2 with image processing only
// 4 with ground fitting

// Please configure only one yac algorithm.
// In case of VISCR_SMPC_STEREO_YAW_CALIBRATION_ODOMETER and VISCR_SMPC_STEREO_YAW_CALIBRATION_IMAGE are activated, 
// only VISCR_SMPC_STEREO_YAW_CALIBRATION_ODOMETER will be used and VISCR_SMPC_STEREO_YAW_CALIBRATION_IMAGE will be in passive mode
//

#define VISCR_SMPC_STEREO_YAW_CALIBRATION_NONE          0 // 0 DISABLE, 1 ENABLE 
#define VISCR_SMPC_STEREO_YAW_CALIBRATION_ODOMETER      0 // 0 DISABLE, 1 ENABLE 
#define VISCR_SMPC_STEREO_YAW_CALIBRATION_RADAR         0 // 0 DISABLE, 1 ENABLE 
#define VISCR_SMPC_STEREO_YAW_CALIBRATION_IMAGE         1 // 0 DISABLE, 1 ENABLE 
#define VISCR_SMPC_STEREO_YAW_CALIBRATION_GROUNDFITTING 0 // 0 DISABLE, 1 ENABLE 


// VISCR_SMPC_REMOVE_YAW_IN_FINE==0 => VISCR_SMPC_STEREO_YAW_CALIBRATION_ODOMETER == 1
// (VISCR_SMPC_APPLYRADAR_YAW == 0) => VISCR_SMPC_STEREO_YAW_CALIBRATION_ODOMETER == 1
// (VISCR_SMPC_APPLYRADAR_YAW != 0) => VISCR_SMPC_STEREO_YAW_CALIBRATION_RADAR == 1
// #if defined(VISCR_YAW_CAMERACALIBRATION) => (VISCR_SMPC_STEREO_YAW_CALIBRATION_ODOMETER == 1)


//#define VISCR_YAW_CAMERACALIBRATION
//#if defined(VISCR_YAW_CAMERACALIBRATION)
//#define VISCR_SMPC_REMOVE_YAW_IN_FINE 0
//#define VISCR_SMPC_APPLYRADAR_YAW 0 // Shall yaw computed by radar be used or not
//#else
//#define VISCR_SMPC_REMOVE_YAW_IN_FINE 1
//#define VISCR_SMPC_APPLYRADAR_YAW 1 // Shall yaw computed by radar be used or not
//#endif

#define VISCR_SMPC_DO_RADAR_CALIB_ONLY (0U)
#define VISCR_SMPC_RADAR_HIGH_RES_HACK (0U)

#define VISCR_SMPC_RIGHT_REFERENCE 1

#define VISCR_CORNER_CHECK 1 // 0: MIN, 1: FAST
#define VISCR_KLT_SHIFT_MEAN 0 //0: CENTER PIXEL ONLY, 1: WHOLE WINDOW 
#define VISCR_EPIPOLAR_CALIBRATION_MODE 1 // 0: on raw image, 1: on rectified image
#define VISCR_SMPC_QUALITY_MEASUREMENT 1 // 0 not active, 1 active ( VISCR_EPIPOLAR_CALIBRATION_MODE should be 1)

#define VISCR_SMPC_SAD_ENABLE  0 // 0 not active, 1 active
#define VISCR_SMPC_SAD_ENABLE_NUM_CALIB 4 

#define VISCR_SMPC_FILTERING_MODE 1 // 0 original mode with median + low pass filter, 
                                    // 1 use quality measurement and please configure VISCR_SMPC_FILTERING_LOW_PASS_FACTOR_DYN, VISCR_SMPC_FILTERING_LOW_PASS_MAX_STEP and VISCR_SMPC_FILTERING_GOOD_RMSE
#define VISCR_SMPC_FILTERING_LOW_PASS_FACTOR_DYN 2.0F
#define VISCR_SMPC_FILTERING_LOW_PASS_MAX_STEP ((0.01F * M_PI) / 180.0F)
#define VISCR_SMPC_FILTERING_GOOD_RMSE 0.5F

#define VISCR_SMPC_RANDOM_SHUFFLE 2  // 0: deterministic choice 
                                     // 1: shift register based random generator
                                     // 2: deterministic choice from border (design with 4 bins only)
                                     // 3: improved deterministic choice from border, better for static scenes (design with 4 bins only)

#ifndef M_PI
  #define M_PI 3.141592653589793F
#endif

#define LM_MU_FINE_ONLY 0.0001  //LM damping factor for tracking mode
#define MIN_DIST_BIN_FEATURE 4
#define MIN_DIST_BIN_FEATURE_DET 2
#define FEATURE_ROI_SPLIT 4  //split of UV map according to suggestion of Lucien
#define FEATURE_ROI_U_MARGIN 40 // disabled part of UV map
#define POINTS_PER_EPIPOLAR_BIN_FINE 30U // default 4
#define POINTS_PER_EPIPOLAR_BIN_COARSE 60U // default 30 please take care of COARSE_BINS_V
#define COARSE_BINS_U 2
#define COARSE_BINS_V 1
#define FINE_BINS_U 2
#define FINE_BINS_V 2

#ifndef SDE_ENVIRONMENT
#define MAX_POINTS_PER_FRAME_FINE 5U
#else
//inside SDE, fast calibration is desired currently
#define MAX_POINTS_PER_FRAME_FINE 1000U
#endif

#define MAX_POINTS_PER_FRAME_FINE_SAD 10

#define RANDOM_SEED_INIT 1234567

#if (POINTS_PER_EPIPOLAR_BIN_COARSE < POINTS_PER_EPIPOLAR_BIN_FINE)
 #error  viscr_defs.h: Fatal Parameter-Error POINTS_PER_EPIPOLAR_BIN_COARSE < POINTS_PER_EPIPOLAR_BIN_FINE
#endif


#define BINS_U 2
#define BINS_V 2
#define SUB_SAMP_UV 1 // subsampling of UV map for power flow feature selection, currently only 1 due to bug

#define BINS_D 1 // 5 
#define POINTS_PER_YAW_BIN 400
#define MAX_YAW_SAMPLES_PER_FRAME 15

#define MAX_NPOINTS_FLOW_PER_FRAME_COARSE 2000
#ifndef SDE_ENVIRONMENT
#define MAX_NPOINTS_FLOW_PER_FRAME_FINE 400 // maximum number of flow vectors per frame default MAX_INPUT_COARSE only relevant for fine calibration
#else
//inside SDE, fast calibration is desired currently
#define MAX_NPOINTS_FLOW_PER_FRAME_FINE 2000 // maximum number of flow vectors per frame default MAX_INPUT_COARSE only relevant for fine calibration
#endif
#define MAX_NPOINTS_FLOW_PER_FRAME 2000 // max value between MAX_NPOINTS_FLOW_PER_FRAME_COARSE and MAX_NPOINTS_FLOW_PER_FRAME_FINE
// ~CodeReview ~ID:87c4e02d3cf7039ed9e9628317c38223 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or comment dead code
//#define MAX_NPOINTS_FLOW_PER_FRAME ((MAX_NPOINTS_FLOW_PER_FRAME_COARSE>=MAX_NPOINTS_FLOW_PER_FRAME_FINE)? MAX_NPOINTS_FLOW_PER_FRAME_COARSE :MAX_NPOINTS_FLOW_PER_FRAME_FINE)

#if ((VISCR_SMPC_STEREO_YAW_CALIBRATION_ODOMETER == 1) || (VISCR_SMPC_STEREO_YAW_CALIBRATION_IMAGE == 1)) //defined(VISCR_YAW_CAMERACALIBRATION)
#ifdef _DEBUG
#undef _DEBUG
#endif
#define KLT_SHIFT 
#define MIN_FLOW_LEN 3U //minimal length of flow vector
#define MEDIAN_LEN 3U // Length of the median buffer. the elements in the buffer are used to calculate the median for the calibration.
#define MIN_DISP 6U // 6 [pix] = (f*b)[pix*m]/60[m]
#define MAX_DISP 10U //maximum disparity size for the role pitch angle calibration
#define MAX_DISP_YAW 55U // 55 [pix] = (f*b)[pix*m]/5[m]
#define SAC_ALGO_MIN_SPEED_FOR_YAW 30.F/3.6F //Speed for calibration time [m/s] ([km/h]/3.6 = [m/s])
#define MAX_FLOW_ERROR_VERTICAL 2.5F*0.45F // 0.45 aspect ratio of stereo roi
#define MAX_FLOW_ERROR_HORIZONTAL 2.5F*1.F //1.F 
#define POWERFLOW_BORDER_LEFT_LENGTH 0U // No powerflow will be available on right and left image borders
    // The right border is removed because it could appears some noise 0.22*1240/(60*2) = 2.2 m
#define POWERFLOW_BORDER_RIGHT_LENGTH 0U // No powerflow will be available on right and left image borders
#else
#undef  KLT_SHIFT
#define MIN_FLOW_LEN 1 //4
#define MEDIAN_LEN 3 // 11
#define MIN_DISP 4 //8
#define MAX_DISP 9 //18
#define POWERFLOW_BORDER_LEFT_LENGTH 25 // No powerflow will be available on right and left image borders
    // The right border is removed because it could appears some noise 0.22*1240/(60*2) = 2.2 m
#define POWERFLOW_BORDER_RIGHT_LENGTH 60 // No powerflow will be available on right and left image borders
#endif

#define MAX_INPUT_COARSE 2000
#define MAX_LM_ITER_FINE 1 // maximum LM iterations during fine calibration
#define KLT_SHIFT_RAD 3

#define MAX_RL_POWERFLOW_V 20 // high resolution : pitch=1024*tan(0.5°)=10.8px , roll=1024/2*tan(0.5°)=4.5px 
#define MAX_TIME_POWERFLOW_V 20 // to avoid rolling shutter distortion like motion blur (pixel, high resolution)
                                // max_dv_error is the maximun vertical error which is allowed for a good calibration
                                // rolling_shutter_offset_line will depend on the 3D points and the cameras poses, could be calculated for each powerflow if needed
                                // => (time_between_2_images * max_dv_error) / (rolling_shutter_offset_line * rolling_shutter_time_per_line)
                                // MAX_TIME_POWERFLOW_V => (60ms * 0.1 px) / (10 px *36.7µs) = 16.3 px  
#define MAX_TIME_POWERFLOW_U 40 // to avoid motion blur due to exposure time 

#define  MIN_RL_POWERFLOW_U (-4) // 0.2° => -4 pixel

#define MAX_YAW_RATE 0.05 // rad/s

#define MAX_DELTA_ODOMETER 5.0F // 5 km between 2 frames
//min_flow_len

 // param.min_disp = 4;
 // param.max_disp = 9;
  //param.bins_d = 5;
//  param.bins_d = 1;


#if (VISCR_SMPC_DO_RADAR_CALIB_ONLY == 0)
#define USE_GLOBAL_ROI_SHIFT 1 // Defines whether to use a global ROI-shift and scaling in the rectification procedure.
#else
#define USE_GLOBAL_ROI_SHIFT 0
#endif

#define SAC_ERROR_SAC_MIN_RECT_QUALITY_THRESHOLD        0.7F 
#define SAC_ERROR_SAC_MAX_DISPARITY_DENSITY_THRESHOLD   0.9F // if density < threshold then an error could be set 
                                                             // 1.0f means deactivation, proposed value 0.9f
#define SAC_ERROR_SAC_FINE_OUT_OF_RANGE_BOUNCE_MAX      1000U

#define SAC_ERROR_FOD_MIN_RECT_QUALITY_THRESHOLD        0.5F 
#define SAC_ERROR_FOD_MAX_DISPARITY_DENSITY_THRESHOLD   1.0F // if density < threshold then an error could be set 
                                                             // 1.0f means deactivation, proposed value 0.9f
#define SAC_ERROR_POD_MIN_RECT_QUALITY_THRESHOLD        0.5F
#define SAC_ERROR_POD_MAX_DISPARITY_DENSITY_THRESHOLD   1.0F // if density < threshold then an error could be set
                                                             // 1.0f means deactivation, proposed value 0.9f
#define SAC_ERROR_SLNE_MIN_RECT_QUALITY_THRESHOLD       0.5F
#define SAC_ERROR_SLNE_MAX_DISPARITY_DENSITY_THRESHOLD  1.0F // if density < threshold then an error could be set
                                                             // 1.0f means deactivation, proposed value 0.9f
#define SAC_ERROR_PV_MIN_RECT_QUALITY_THRESHOLD         0.5F
#define SAC_ERROR_PV_MAX_DISPARITY_DENSITY_THRESHOLD    1.0F // if density < threshold then an error could be set
                                                             // 1.0f means deactivation, proposed value 0.9f

#define SAC_CALIBQUALITY_SUFFICIENT_RECT_TH             0.59F
#define SAC_CALIBQUALITY_GOOD_RECT_TH                   0.3F
#define SAC_CALIBQUALITY_RECT_LOWPASS                   0.5F

#define SAC_CALIBQUALITY_SUFFICIENT_DISP_TH             0.6F
#define SAC_CALIBQUALITY_GOOD_DISP_TH                   0.8F
#define SAC_CALIBQUALITY_DISP_LOWPASS                   0.3F



#define SAC_FAST_QUALITY_CHECK_ENA                      0  // 1 : in one frame, it will decide if we should go on coarse or fine calibration
                                                           // 0 : use normal quality check from the bins


#define SAC_TIMEOUT_COARSE_DISTANCE_ENA                 1U                        // 0 disable, 1 enable
#define SAC_TIMEOUT_COARSE_DISTANCE                     (static_cast<ui64_t>(50*1000))       // in meters
#define SAC_TIMEOUT_COARSE_TIME_ENA                     0U                         // 0 disable, 1 enable
#define SAC_TIMEOUT_COARSE_TIME                         1UL//((ui64_t)(2*60*60*10e6))  // in microseconds
#define SAC_TIMEOUT_FINE_DISTANCE_ENA                   1U                        // 0 disable, 1 enable
#define SAC_TIMEOUT_FINE_DISTANCE                       (static_cast<ui64_t>(500*1000))      // in meters
#define SAC_TIMEOUT_FINE_TIME_ENA                       0U                        // 0 disable, 1 enable
#define SAC_TIMEOUT_FINE_TIME                           1//((ui64_t)(5*60*60*10e6))  // in microseconds

#define VISCR_SMPC_INITLUT_SPLITTED                     1 // 0 InitLut is computed left and right LUT at on the same frame, 1: InitLut is splitted in 2 frames


// defines for windshield distortion weighing-function
#define WS_V_TOP                                     190.0F   // Vertical position of the top edge, 0.5 weight
#define WS_V_BOT                                     460.0F   // Vertical position of the bottom edge, 0.5 weight
#define WS_U_TOPLEFT                                 389.0F   // Horizontal position of the top left corner, 0.5 weight
#define WS_U_TOPRIGHT                                635.0F   // Horizontal position of the top right corner, 0.5 weight
#define WS_U_BOTLEFT                                  75.0F   // Horizontal position of the bottom left corner, 0.5 weight
#define WS_U_BOTRIGHT                                949.0F   // Horizontal position of the bottom right corner, 0.5 weight
#define WS_U_EDGEWIDTH                                30.0F   // Half-width of the weighting strip


#define SAC_STEREO_YAW_ENA                          1U   // 0 DISABLE, 1 ENABLE, 2 ENABLE + DEBUG (do not check in this value)
#define SAC_STD_MODE                                1U   // 0 frame by frame, 1 std buffer 

#endif /* VISCR_DEFS_H */
