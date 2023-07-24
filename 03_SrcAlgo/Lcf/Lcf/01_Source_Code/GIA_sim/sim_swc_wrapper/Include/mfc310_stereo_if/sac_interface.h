/*! \file **********************************************************************

COMPANY:        Continental AG

PROJECT:        MFC300

CPU:            

COMPONENT:      SAC - Stereo Auto Calibration

MODULNAME:      sac_interface.h  

DESCRIPTION:    input/output structure handling for SAC data

AUTHOR:         J. Schmidt

CREATION DATE:  20.07.2009

VERSION:        $Revision: 1.1 $

CHANGES:        $Log: sac_interface.h  $
CHANGES:        Revision 1.1 2021/12/13 17:26:25CET Wang, David (Wangd3) 
CHANGES:        Initial revision
CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310_stereo_if/project.pj
CHANGES:        Revision 1.0 2017/03/03 10:37:31CET Sorge, Sven (uidg3181) 
CHANGES:        Initial revision
CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310_stereo_if/project.pj
CHANGES:        Revision 1.1 2014/03/13 15:12:58CET Sorge, Sven (uidg3181) 
CHANGES:        Initial revision
CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310_stereo_if/project.pj
CHANGES:        Revision 1.44 2012/07/12 18:32:10CEST Stache, Nicolaj (uidt6711) 
CHANGES:        windshield distortion added to the interface
CHANGES:        --- Added comments ---  uidt6711 [Jul 12, 2012 6:32:11 PM CEST]
CHANGES:        Change Package : 67326:3 http://mks-psad:7002/im/viewissue?selection=67326
CHANGES:        Revision 1.43 2012/05/31 17:28:15CEST Garcia, Lucien (uid26778) 
CHANGES:        Remove lint warnings
CHANGES:        --- Added comments ---  uid26778 [May 31, 2012 5:28:18 PM CEST]
CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
CHANGES:        Revision 1.42 2012/05/04 11:58:31CEST Stache, Nicolaj (uidt6711) 
CHANGES:        Interface change 4.6 release
CHANGES:        --- Added comments ---  uidt6711 [May 4, 2012 11:58:33 AM CEST]
CHANGES:        Change Package : 67326:3 http://mks-psad:7002/im/viewissue?selection=67326
CHANGES:        Revision 1.41 2012/05/04 09:14:31CEST Garcia, Lucien (uid26778) 
CHANGES:        Add debug datas for distance test
CHANGES:        --- Added comments ---  uid26778 [May 4, 2012 9:14:32 AM CEST]
CHANGES:        Change Package : 106059:1 http://mks-psad:7002/im/viewissue?selection=106059
CHANGES:        Revision 1.40 2012/03/27 19:29:31CEST Stache, Nicolaj (uidt6711) 
CHANGES:        interface freeze update
CHANGES:        --- Added comments ---  uidt6711 [Mar 27, 2012 7:29:31 PM CEST]
CHANGES:        Change Package : 67326:3 http://mks-psad:7002/im/viewissue?selection=67326
CHANGES:        Revision 1.39 2012/03/27 16:05:58CEST Garcia, Lucien (uid26778) 
CHANGES:        Update comment
CHANGES:        --- Added comments ---  uid26778 [Mar 27, 2012 4:05:59 PM CEST]
CHANGES:        Change Package : 104771:1 http://mks-psad:7002/im/viewissue?selection=104771
CHANGES:        Revision 1.38 2012/03/27 16:01:07CEST Garcia, Lucien (uid26778) 
CHANGES:        Add road vanishing point position on rectified images for camera blockage
CHANGES:        --- Added comments ---  uid26778 [Mar 27, 2012 4:01:09 PM CEST]
CHANGES:        Change Package : 104771:1 http://mks-psad:7002/im/viewissue?selection=104771
CHANGES:        Revision 1.37 2012/03/27 15:35:49CEST Garcia, Lucien (uid26778) 
CHANGES:        Add horizon position on rectified images for camera blocage (in pixel)
CHANGES:        --- Added comments ---  uid26778 [Mar 27, 2012 3:35:49 PM CEST]
CHANGES:        Change Package : 104771:1 http://mks-psad:7002/im/viewissue?selection=104771
CHANGES:        Revision 1.36 2012/03/27 13:13:27CEST Garcia, Lucien (uid26778) 
CHANGES:        Distance Test interface update
CHANGES:        --- Added comments ---  uid26778 [Mar 27, 2012 1:13:27 PM CEST]
CHANGES:        Change Package : 94275:2 http://mks-psad:7002/im/viewissue?selection=94275
CHANGES:        Revision 1.35 2012/03/26 16:13:43CEST Garcia, Lucien (uid26778) 
CHANGES:        Change interfaces for distance check
CHANGES:        --- Added comments ---  uid26778 [Mar 26, 2012 4:13:43 PM CEST]
CHANGES:        Change Package : 94275:2 http://mks-psad:7002/im/viewissue?selection=94275
CHANGES:        Revision 1.34 2012/03/26 10:23:47CEST Garcia, Lucien (uid26778) 
CHANGES:        Wrong interface names on distance test
CHANGES:        --- Added comments ---  uid26778 [Mar 26, 2012 10:23:47 AM CEST]
CHANGES:        Change Package : 94275:2 http://mks-psad:7002/im/viewissue?selection=94275
CHANGES:        Revision 1.33 2012/03/14 17:28:47CET Exner, Christian (uidt8578) 
CHANGES:        - fixed trailing comma in last enum meber
CHANGES:        --- Added comments ---  uidt8578 [Mar 14, 2012 5:28:47 PM CET]
CHANGES:        Change Package : 90232:1 http://mks-psad:7002/im/viewissue?selection=90232
CHANGES:        Revision 1.32 2012/02/15 09:54:28CET Spruck, Jochen (spruckj) 
CHANGES:        Rename cct spod object list
CHANGES:        --- Added comments ---  spruckj [Feb 15, 2012 9:54:30 AM CET]
CHANGES:        Change Package : 98074:2 http://mks-psad:7002/im/viewissue?selection=98074
CHANGES:        Revision 1.31 2012/01/24 20:48:19CET Stache, Nicolaj (uidt6711) 
CHANGES:        4.4.0 interface freeze update
CHANGES:        --- Added comments ---  uidt6711 [Jan 24, 2012 8:48:20 PM CET]
CHANGES:        Change Package : 67326:3 http://mks-psad:7002/im/viewissue?selection=67326
CHANGES:        Revision 1.30 2011/12/16 11:12:39CET Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        bugfix: warnings corrected
CHANGES:        --- Added comments ---  uidt6711 [Dec 16, 2011 11:12:41 AM CET]
CHANGES:        Change Package : 67326:3 http://mks-psad:7002/im/viewissue?selection=67326
CHANGES:        Revision 1.29 2011/12/02 17:10:31CET Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        update of comment
CHANGES:        --- Added comments ---  uidt6711 [Dec 2, 2011 5:10:34 PM CET]
CHANGES:        Change Package : 67326:3 http://mks-psad:7002/im/viewissue?selection=67326
CHANGES:        Revision 1.28 2011/11/25 19:06:48CET Stache, Nicolaj (uidt6711) 
CHANGES:        update
CHANGES:        --- Added comments ---  uidt6711 [Nov 25, 2011 7:06:50 PM CET]
CHANGES:        Change Package : 67326:3 http://mks-psad:7002/im/viewissue?selection=67326
CHANGES:        Revision 1.27 2011/11/25 15:01:30CET Garcia, Lucien (uid26778) 
CHANGES:        Split LUT generation in 2 frames (runtime improvement)
CHANGES:        --- Added comments ---  uid26778 [Nov 25, 2011 3:01:32 PM CET]
CHANGES:        Change Package : 87584:1 http://mks-psad:7002/im/viewissue?selection=87584
CHANGES:        Revision 1.26 2011/11/25 08:33:16CET Garcia Lucien (uid26778) (uid26778) 
CHANGES:        LUT generation is splitted in 2 frames to avoid runtime peaks (see configuration VISCR_SMPC_INITLUT_SPLITTED)
CHANGES:        --- Added comments ---  uid26778 [Nov 25, 2011 8:33:17 AM CET]
CHANGES:        Change Package : 87584:1 http://mks-psad:7002/im/viewissue?selection=87584
CHANGES:        Revision 1.25 2011/11/12 20:27:57CET Stache Nicolaj (uidt6711) (uidt6711) CHANGES:        Revision 1.26 2011/11/25 08:33:16CET Garcia Lucien (uid26778) (uid26778) 
CHANGES:        LUT generation is splitted in 2 frames to avoid runtime peaks (see configuration VISCR_SMPC_INITLUT_SPLITTED)
CHANGES:        --- Added comments ---  uid26778 [Nov 25, 2011 8:33:17 AM CET]
CHANGES:        Change Package : 87584:1 http://mks-psad:7002/im/viewissue?selection=87584
CHANGES:        Revision 1.25 2011/11/12 20:27:57CET Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        3.3.0 Interface freeze 2
CHANGES:        --- Added comments ---  uidt6711 [Nov 12, 2011 8:27:57 PM CET]
CHANGES:        Change Package : 67326:3 http://mks-psad:7002/im/viewissue?selection=67326
CHANGES:        Revision 1.24 2011/11/10 13:12:00CET Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        Interface change for 3.3.0 release
CHANGES:        --- Added comments ---  uidt6711 [Nov 10, 2011 1:12:01 PM CET]
CHANGES:        Change Package : 87454:1 http://mks-psad:7002/im/viewissue?selection=87454
CHANGES:        Revision 1.23 2011/11/04 12:23:06CET Spruck Jochen (spruckj) (spruckj) 
CHANGES:        Introduce provide/request port interface for SAC component,
CHANGES:        Add additional port to this interface
CHANGES:        request port
CHANGES:        - SPODObjectList
CHANGES:        provide port
CHANGES:        - SAC CalibrationDate
CHANGES:        --- Added comments ---  spruckj [Nov 4, 2011 12:23:08 PM CET]
CHANGES:        Change Package : 86836:1 http://mks-psad:7002/im/viewissue?selection=86836
CHANGES:        Revision 1.22 2011/09/28 15:37:41CEST Spruck Jochen (spruckj) (spruckj) 
CHANGES:        Remove the write counter from the temp table interface
CHANGES:        --- Added comments ---  spruckj [Sep 28, 2011 3:37:43 PM CEST]
CHANGES:        Change Package : 79035:1 http://mks-psad:7002/im/viewissue?selection=79035
CHANGES:        Revision 1.21 2011/09/28 13:11:32CEST Spruck Jochen (spruckj) (spruckj) 
CHANGES:        - Remove misra issues
CHANGES:        - Extend stereo obj interface
CHANGES:        --- Added comments ---  spruckj [Sep 28, 2011 1:11:32 PM CEST]
CHANGES:        Change Package : 79035:1 http://mks-psad:7002/im/viewissue?selection=79035
CHANGES:        Revision 1.20 2011/09/20 20:40:03CEST Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        3.2.0 Subrelease2
CHANGES:        --- Added comments ---  uidt6711 [Sep 20, 2011 8:40:03 PM CEST]
CHANGES:        Change Package : 67326:1 http://mks-psad:7002/im/viewissue?selection=67326
CHANGES:        Revision 1.19 2011/09/20 18:57:17CEST Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        3.2.0 Lib 2 Interface change
CHANGES:        Revision 1.18 2011/09/20 14:47:29CEST Spruck Jochen (spruckj) (spruckj) 
CHANGES:        - Add nvm interface for temp model
CHANGES:        - Call temp model
CHANGES:        - Call yaw calib with radar object
CHANGES:        --- Added comments ---  spruckj [Sep 20, 2011 2:47:30 PM CEST]
CHANGES:        Change Package : 79035:1 http://mks-psad:7002/im/viewissue?selection=79035
CHANGES:        Revision 1.17 2011/09/13 17:06:16CEST Garcia Lucien (uid26778) (uid26778) 
CHANGES:        Change interfaces
CHANGES:        --- Added comments ---  uid26778 [Sep 13, 2011 5:06:16 PM CEST]
CHANGES:        Change Package : 77279:2 http://mks-psad:7002/im/viewissue?selection=77279
CHANGES:        Revision 1.16 2011/09/02 17:02:31CEST Garcia Lucien (uid26778) (uid26778) 
CHANGES:        Add new SAC error interface
CHANGES:        --- Added comments ---  uid26778 [Sep 2, 2011 5:02:31 PM CEST]
CHANGES:        Change Package : 77279:1 http://mks-psad:7002/im/viewissue?selection=77279
CHANGES:        Revision 1.15 2011/09/01 16:22:36CEST Garcia Lucien (uid26778) (uid26778) 
CHANGES:        Add SAC_ErrorState SW module
CHANGES:        --- Added comments ---  uid26778 [Sep 1, 2011 4:22:36 PM CEST]
CHANGES:        Change Package : 77279:1 http://mks-psad:7002/im/viewissue?selection=77279
CHANGES:        Revision 1.14 2011/08/26 19:48:00CEST Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        3.2.0 Interface change
CHANGES:        --- Added comments ---  uidt6711 [Aug 26, 2011 7:48:01 PM CEST]
CHANGES:        Change Package : 67326:1 http://mks-psad:7002/im/viewissue?selection=67326
CHANGES:        Revision 1.13 2011/07/07 16:03:24CEST Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        Interface freeze
CHANGES:        Revision 1.12 2011/07/06 16:08:33CEST Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        comment changed
CHANGES:        --- Added comments ---  uidt6711 [Jul 6, 2011 4:08:34 PM CEST]
CHANGES:        Change Package : 67326:1 http://mks-psad:7002/im/viewissue?selection=67326
CHANGES:        Revision 1.11 2011/07/05 19:54:12CEST Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        SAC interface change
CHANGES:        --- Added comments ---  uidt6711 [Jul 5, 2011 7:54:12 PM CEST]
CHANGES:        Change Package : 67326:1 http://mks-psad:7002/im/viewissue?selection=67326
CHANGES:        Revision 1.10 2011/05/12 20:30:22CEST Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        Interface freezes 2.5.1 revision
CHANGES:        --- Added comments ---  uidt6711 [May 12, 2011 8:30:22 PM CEST]
CHANGES:        Change Package : 58788:2 http://mks-psad:7002/im/viewissue?selection=58788
CHANGES:        Revision 1.9 2011/05/04 17:50:16CEST Mueller Reik (muellerr5) (muellerr5) 
CHANGES:        - updated SAC debug output struct: added indicator of new epi points
CHANGES:        --- Added comments ---  muellerr5 [May 4, 2011 5:50:17 PM CEST]
CHANGES:        Change Package : 64689:1 http://mks-psad:7002/im/viewissue?selection=64689
CHANGES:        Revision 1.8 2011/04/17 21:16:27CEST Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        Interface change, coarse calibration
CHANGES:        --- Added comments ---  uidt6711 [Apr 17, 2011 9:16:27 PM CEST]
CHANGES:        Change Package : 58788:2 http://mks-psad:7002/im/viewissue?selection=58788
CHANGES:        Revision 1.7 2011/04/15 17:50:39CEST Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        Simulation changes
CHANGES:        Revision 1.6 2011/03/25 16:37:13CET Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        interface adaptation
CHANGES:        Revision 1.5 2011/03/18 11:36:20CET Wagner Ulrich (uid04769) (uid04769) 
CHANGES:        Updated interface for future DSP-optimizations (use of fast L2 memory is now possible)
CHANGES:        --- Added comments ---  uid04769 [Mar 18, 2011 11:36:21 AM CET]
CHANGES:        Change Package : 37886:2 http://mks-psad:7002/im/viewissue?selection=37886
CHANGES:        Revision 1.4 2011/03/16 15:37:32CET Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        version number of ROIshiftStruct increased
CHANGES:        --- Added comments ---  uidt6711 [Mar 16, 2011 3:37:32 PM CET]
CHANGES:        Change Package : 58788:1 http://mks-psad:7002/im/viewissue?selection=58788
CHANGES:        Revision 1.3 2011/02/28 14:03:27CET Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        sac auto-mode added in enum of sac modes
CHANGES:        --- Added comments ---  uidt6711 [Feb 28, 2011 2:03:28 PM CET]
CHANGES:        Change Package : 58788:1 http://mks-psad:7002/im/viewissue?selection=58788
CHANGES:        Revision 1.2 2011/02/17 14:34:05CET Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        Widths, heights, start, stop for rectified and powerflow images provided
CHANGES:        struct version number for powerflow removed, roi-offset added to the interface
CHANGES:        --- Added comments ---  uidt6711 [Feb 17, 2011 2:34:05 PM CET]
CHANGES:        Change Package : 58788:1 http://mks-psad:7002/im/viewissue?selection=58788
CHANGES:        Revision 1.1 2011/02/14 18:23:31CET Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        Initial revision
CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SAC_StereoAutoCalibration/04_Engineering/99_Source_Code_CCT/algo/kernel_interface/project.pj
CHANGES:        Revision 1.28 2011/02/14 13:05:10CET Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        parameter ID added to the LUT interface
CHANGES:        Revision 1.27 2011/02/11 19:32:11CET Wagner Ulrich (uid04769) (uid04769) 
CHANGES:        ui64_t Timestamp is us and not ms (renamed struct member)
CHANGES:        --- Added comments ---  uid04769 [Feb 11, 2011 7:32:12 PM CET]
CHANGES:        Change Package : 37886:1 http://mks-psad:7002/im/viewissue?selection=37886
CHANGES:        Revision 1.26 2011/02/11 19:03:50CET Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        Bugfix interface (from Uli)
CHANGES:        --- Added comments ---  uidt6711 [Feb 11, 2011 7:03:50 PM CET]
CHANGES:        Change Package : 58788:1 http://mks-psad:7002/im/viewissue?selection=58788
CHANGES:        Revision 1.25 2011/02/11 16:43:47CET Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        Rename getter function for version and state
CHANGES:        Revision 1.24 2011/02/11 16:29:31CET Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        Interface adaptation finished (no crash in MTS)
CHANGES:        Revision 1.23 2011/02/10 20:19:52CET Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        SAC interface fully integrated, however MTS crashes
CHANGES:        Revision 1.22 2011/02/10 13:46:51CET Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        Provide preliminary interface
CHANGES:        Revision 1.21 2011/02/08 19:45:17CET Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        Provide Interface for Odometry, SGM, Powerflow, timestamp, Temperature, shiftedROI, ImagerSyncOffset
CHANGES:        Revision 1.20 2011/02/07 16:39:49CET Garcia Lucien (uid26778) (uid26778) 
CHANGES:        First integration of autocalibration code into SAC module
CHANGES:        --- Added comments ---  uid26778 [Feb 7, 2011 4:39:49 PM CET]
CHANGES:        Change Package : 58789:1 http://mks-psad:7002/im/viewissue?selection=58789
CHANGES:        Revision 1.19 2011/02/04 10:40:05CET Garcia Lucien (uid26778) (uid26778) 
CHANGES:        First integration of autocalibration code into SAC module
CHANGES:        --- Added comments ---  uid26778 [Feb 4, 2011 10:40:05 AM CET]
CHANGES:        Change Package : 58789:1 http://mks-psad:7002/im/viewissue?selection=58789
CHANGES:        Revision 1.18 2010/12/15 14:22:39CET Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        Provide Output of CROI-Offset
CHANGES:        --- Added comments ---  uidt6711 [Dec 15, 2010 2:22:39 PM CET]
CHANGES:        Change Package : 56502:2 http://mks-psad:7002/im/viewissue?selection=56502
CHANGES:        Revision 1.17 2010/12/13 13:48:55CET Wagner Ulrich (uid04769) (uid04769) 
CHANGES:        Bugfix for B1 2.3.1 release
CHANGES:        --- Added comments ---  uid04769 [Dec 13, 2010 1:48:55 PM CET]
CHANGES:        Change Package : 37886:1 http://mks-psad:7002/im/viewissue?selection=37886
CHANGES:        Revision 1.16 2010/09/08 11:18:26CEST Jochen Schmidt (schmidtj10) 
CHANGES:        passing of rectified images changed to struct with timestamp
CHANGES:        --- Added comments ---  schmidtj10 [Sep 8, 2010 11:18:27 AM CEST]
CHANGES:        Change Package : 37155:1 http://mks-psad:7002/im/viewissue?selection=37155
CHANGES:        Revision 1.15 2010/09/06 13:04:00CEST Jochen Schmidt (schmidtj10) 
CHANGES:        added output time stamp
CHANGES:        Revision 1.14 2010/08/13 11:07:13CEST Jochen Schmidt (schmidtj10) 
CHANGES:        interface update
CHANGES:        Revision 1.13 2010/08/11 16:46:28CEST Jochen Schmidt (schmidtj10) 
CHANGES:        - interface update (run mode switches, extended output,...)
CHANGES:        - generate test data set
CHANGES:        - run in MeaseFreeze Mode only
CHANGES:        Revision 1.12 2010/02/09 15:34:02CET jschmidt 
CHANGES:        added getBaseLine function
CHANGES:        --- Added comments ---  jschmidt [2010/02/09 14:34:02Z]
CHANGES:        Change Package : 26824:1 http://LISS014:6001/im/viewissue?selection=26824
CHANGES:        Revision 1.11 2009/11/09 16:37:56CET jschmidt 
CHANGES:        added support for MeasFreeze output
CHANGES:        --- Added comments ---  jschmidt [2009/11/09 15:37:56Z]
CHANGES:        Change Package : 26824:1 http://LISS014:6001/im/viewissue?selection=26824
CHANGES:        Revision 1.10 2009/09/08 14:03:06CEST jschmidt 
CHANGES:        replaced glob_type.he by cct_type.h
CHANGES:        --- Added comments ---  jschmidt [2009/09/08 12:03:06Z]
CHANGES:        Change Package : 26824:1 http://LISS014:6001/im/viewissue?selection=26824
CHANGES:        --- Added comments ---  jschmidt [2009/09/08 12:03:06Z]
CHANGES:        Change Package : 26824:1 http://LISS014:6001/im/viewissue?selection=26824
CHANGES:        Revision 1.9 2009/08/24 14:50:17CEST Ulrich Wagner (uwagner) 
CHANGES:        fixed point LUT datatype is now defined within this header => It is avoided to include sac_defs.h here
CHANGES:        --- Added comments ---  uwagner [2009/08/24 12:50:18Z]
CHANGES:        Change Package : 26829:1 http://LISS014:6001/im/viewissue?selection=26829
CHANGES:        --- Added comments ---  uwagner [2009/08/24 12:50:18Z]
CHANGES:        Change Package : 26829:1 http://LISS014:6001/im/viewissue?selection=26829
CHANGES:        Revision 1.8 2009/08/24 14:22:53CEST Ulrich Wagner (uwagner) 
CHANGES:        - All SAC algo workflow moved from sac_interface.cpp/.h to sac_algo.cpp/.h
CHANGES:        - Results are now handed to SW FW via buffers, that are provided by SW-FW (cf. telephone call with Bojan Banduka, 21.08.2009)
CHANGES:        --- Added comments ---  uwagner [2009/08/24 12:22:54Z]
CHANGES:        Change Package : 26829:1 http://LISS014:6001/im/viewissue?selection=26829
CHANGES:        --- Added comments ---  uwagner [2009/08/24 12:22:54Z]
CHANGES:        Change Package : 26829:1 http://LISS014:6001/im/viewissue?selection=26829
CHANGES:        Revision 1.7 2009/08/12 15:29:56CEST jschmidt 
CHANGES:        changed ui32_t to ui16_t
CHANGES:        --- Added comments ---  jschmidt [2009/08/12 13:29:57Z]
CHANGES:        Change Package : 26824:1 http://LISS014:6001/im/viewissue?selection=26824
CHANGES:        --- Added comments ---  jschmidt [2009/08/12 13:29:57Z]
CHANGES:        Change Package : 26824:1 http://LISS014:6001/im/viewissue?selection=26824
CHANGES:        Revision 1.6 2009/07/27 17:26:58CEST jschmidt 
CHANGES:        code update
CHANGES:        --- Added comments ---  jschmidt [2009/07/27 15:26:58Z]
CHANGES:        Change Package : 26824:1 http://LISS014:6001/im/viewissue?selection=26824
CHANGES:        --- Added comments ---  jschmidt [2009/07/27 15:26:58Z]
CHANGES:        Change Package : 26824:1 http://LISS014:6001/im/viewissue?selection=26824
CHANGES:        Revision 1.5 2009/07/27 13:41:32CEST jschmidt 
CHANGES:        changed interface
CHANGES:        --- Added comments ---  jschmidt [2009/07/27 11:41:32Z]
CHANGES:        Change Package : 26824:1 http://LISS014:6001/im/viewissue?selection=26824
CHANGES:        --- Added comments ---  jschmidt [2009/07/27 11:41:32Z]
CHANGES:        Change Package : 26824:1 http://LISS014:6001/im/viewissue?selection=26824
CHANGES:        Revision 1.4 2009/07/23 15:17:46CEST jschmidt 
CHANGES:        updates
CHANGES:        --- Added comments ---  jschmidt [2009/07/23 13:17:46Z]
CHANGES:        Change Package : 26824:1 http://LISS014:6001/im/viewissue?selection=26824
CHANGES:        --- Added comments ---  jschmidt [2009/07/23 13:17:46Z]
CHANGES:        Change Package : 26824:1 http://LISS014:6001/im/viewissue?selection=26824
CHANGES:        Revision 1.3 2009/07/22 17:23:27CEST jschmidt 
CHANGES:        changed comment
CHANGES:        --- Added comments ---  jschmidt [2009/07/22 15:23:27Z]
CHANGES:        Change Package : 26824:1 http://LISS014:6001/im/viewissue?selection=26824
CHANGES:        --- Added comments ---  jschmidt [2009/07/22 15:23:27Z]
CHANGES:        Change Package : 26824:1 http://LISS014:6001/im/viewissue?selection=26824
CHANGES:        Revision 1.2 2009/07/21 17:31:54CEST jschmidt 
CHANGES:        defined calibration parameters
CHANGES:        --- Added comments ---  jschmidt [2009/07/21 15:31:54Z]
CHANGES:        Change Package : 26824:1 http://LISS014:6001/im/viewissue?selection=26824
CHANGES:        --- Added comments ---  jschmidt [2009/07/21 15:31:54Z]
CHANGES:        Change Package : 26824:1 http://LISS014:6001/im/viewissue?selection=26824
CHANGES:        Revision 1.1 2009/07/20 17:18:44CEST jschmidt 
CHANGES:        Initial revision
CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SAC_StereoAutoCalibration/04_Engineering/01_Source_Code/Kernel/project.pj

**************************************************************************** */

#ifndef SAC_INTERFACE_H
#define SAC_INTERFACE_H


#include "common_stereointerface_types.h"
#include "SAC_ErrorState.h"


#ifdef __cplusplus
extern "C" 
{
#endif

  static const ui32_t SACSignalState_VersionNumber = 2; /*!< Version number of enumeration SACSignalState_t */
  /*! \brief  signal/variable state */
  typedef enum 
  {
    SAC_SIG_NOT_OK = 0u,  /*!< signal not available */ 
    SAC_SIG_OK     = 1u   /*!< signal available */ 
  } SACSignalState_t;

 
  static const ui32_t TimeFrameStamp_VersionNumber = 2; /*!< version number of struct TimeFrameStamp_t */
  /*! \brief contains timestamp and framecounter information */
  typedef struct 
  {
    DEFINE_VERSION_MEMBER(TimeFrameStamp);

    ui64_t Timestamp;
    ui32_t FrameCount;
  }TimeFrameStamp_t;

  static const ui32_t SACModes_VersionNumber = 5; /*!< Version Number of enumeration SACModes_t */

  typedef enum 
  {
    SAC_Mode_Deflt          = 0u,            /*!< default: do nothing  / value not set */
    SAC_Mode_MeasOnly       = 1u,            /*!< send Measfreeze data only, no computation (-> outout MeasFreeze invalid) */
    SAC_Mode_InitLUT        = 2u,            /*!< generate LUT only, no autocalibration, no rectified images or disparity map required */
    SAC_Mode_AutoCalCoarse  = 3u,            /*!< coarse autocalibration, update camera paramters and LUT, run until finished */
    SAC_Mode_AutoCalFine    = 4u,            /*!< fine autocalibration, update camera paramters and LUT when ready, defined runtime per cycle */
    SAC_Mode_AutoChoice     = 5u,            /*!< automatically chooses the correct mode */ 
    SAC_Mode_EOLupdate      = 6u,            /*!< mode which updates the EOL calibration parameters by doing coarse calibration on one frame (has to be called manually) */ 
    SAC_Mode_SelfEval       = 7u,            /*!< performs a self evaluation of the existing calibration by computing the rectification error */
    SAC_Mode_Test           = 8u,            /*!< test mode, send defined set of output data */
    SAC_Mode_DistanceTest   = 9u             /*!< SAC performs distance test at Conti-EOL and does a recalibration */
  } SACModes_t;
  


  static const ui32_t SACImageData_VersionNumber = 2; /*!< version number of struct SACImageData_t */
  /*! \brief start and size of ROI, size of complete image */
  typedef struct
  {
    DEFINE_VERSION_MEMBER(SACImageData);
    
    ui16_t ROIStartX;	         	/*!< x-coordinate of top/left pixel of image ROI */
    ui16_t ROIStartY;	         	/*!< y-coordinate of top/left pixel of image ROI */
    ui16_t ROIStartRelCroiX;	 	/*!< x-coordinate of top/left pixel of image ROI */
    ui16_t ROIStartRelCroiY;	 	/*!< y-coordinate of top/left pixel of image ROI */
    ui16_t ROIWidth;            /*!< width of image ROI */
    ui16_t ROIHeight;           /*!< height of image ROI */
    ui16_t ImgHeight;           /*!< height of complete imager */
    ui16_t ImgWidth;            /*!< width of complete imager */
    SACSignalState_t SignalStateTimeStamp;                /*!< signal state of TimeStamp */
    TimeFrameStamp_t  TFStamp;                            /*!< time stamp when SACImage was received in usec */
  }SACImageData_t;

#define SAC_TEMPMOD_ANGLE_NO_NODES                (16U)

/*! Bit mask for dword table node flags 0..31 */
#define SAC_TEMPMOD_NODES_MAKS_ALL                (0xFFFFU)

/*! Flag bit position number of total write counts */
#define SAC_TEMPMOD_BIT_POS_CNTR                  (SAC_TEMPMOD_ANGLE_NO_NODES)

  /*! Test if all table node flags are set */
#define SAC_TEMPMOD_NODES_ALL_VALID(stat_)        ( (((stat_) & SAC_TEMPMOD_NODES_MAKS_ALL) == SAC_TEMPMOD_NODES_MAKS_ALL) )

  /*! Test if specific node flag is set */
#define SAC_TEMPMOD_NODE_IS_VALID(idx_,stat_)     (((1UL<<((idx_)& 0x10U)) & (stat_))!= 0U)
  /*! Set specific node flag */
#define SAC_TEMPMOD_NODE_SET_VALID(idx_,stat_)    ((stat_) |=  ((static_cast<ui16_t>(1U))<<((static_cast<ui16_t>(idx_))& 0x10U)))
  /*! Clear specific node flag */
#define SAC_TEMPMOD_NODE_SET_INVALID(idx_,stat_)  ((stat_) &= ~(1U<<(static_cast<ui16_t>(idx_)& 0xFU)))

  typedef struct {
    i16_t Angle;            /*!< Learned angle            */
    ui8_t Conf;             /*!< Learned angle confidence */
  } SACNvAngleLearnNode_t;


  static const ui32_t SACNvAngleLearnTable_VersionNumber = 1; /*!< version number of struct SACNvAngleLearnTable_t */
  /*! \brief nvm temp tables SACNvAngleLearnTable_t */
  typedef struct {
    DEFINE_VERSION_MEMBER(SACNvAngleLearnTable);
    SACNvAngleLearnNode_t Node[SAC_TEMPMOD_ANGLE_NO_NODES];
    ui16_t  statRd;            /*!< Read states of each node  */
    ui16_t  statWr;            /*!< Write states of each node */
    ui16_t  statWrpd;          /*!< Write pending states of each node, used to minimize write access to nvm */
    i16_t   prodAngle;         /*!< Sensor angle determined during production */
  } SACNvAngleLearnTable_t; 

  static const ui32_t SACNvAngleData_VersionNumber = 1; /*!< version number of struct SACNvAngleData_t */
  /*! \brief nvm temp tables */
  typedef struct {
    DEFINE_VERSION_MEMBER(SACNvAngleData);
    SACNvAngleLearnTable_t YawAngleNvData;     /*!< Yaw angle nvm temp table data   */
    SACNvAngleLearnTable_t PitchAngleNvData;   /*!< Pitch angle nvm temp table data */
    SACNvAngleLearnTable_t RollAngleNvData;    /*!< Roll angle nvm temp table data  */
  } SACNvAngleData_t;

  static const ui32_t SACBBox_VersionNumber = 1; /*!< version number of struct SACBBox_t */
  /*! \brief start and size of bounding box */
  typedef struct
  {
    DEFINE_VERSION_MEMBER(SACBBox);
    
    ui16_t BBoxStartX;	         	/*!< x-coordinate of top/left pixel of image bounding box with respect to stereo roi */
    ui16_t BBoxStartY;	         	/*!< y-coordinate of top/left pixel of image bounding box with respect to stereo roi*/
    ui16_t BBoxWidth;             /*!< width of image bounding box */
    ui16_t BBoxHeight;            /*!< height of image bounding box */
  }SACBBox_t;

static const ui32_t SACshiftedROIData_VersionNumber = 5;  /*!< version number of struct SACshiftedROIData */
  typedef struct
  {
    DEFINE_VERSION_MEMBER ( SACshiftedROIData );

    SACImageData_t ImageDataLeft;
    SACImageData_t ImageDataRight;
    i32_t ImgSyncOffset;
    i32_t GlobROIShiftVert;         /*!< vertical global shift of the stereo ROI in pixels */
    i32_t GlobROIShiftHoriz;        /*!< horizontal global shift of the stereo ROI in pixels */
    f32_t RectScalefactor;
    ui16_t VanishingPoint_U;        /*!< U-position of the road vanishing point on rectified images [pixel] */
    ui16_t VanishingPoint_V;        /*!< V-position of the road vanishing point on rectified images [pixel] */
  }SACshiftedROIData_t;

  static const ui32_t SACIntrinsicCalibrationData_VersionNumber = 2; /*!< version number of struct SACIntrinsicCalibrationData_t */
  /*! \brief camera calibration data (intrinsic) */
  typedef struct
  {
    DEFINE_VERSION_MEMBER(SACIntrinsicCalibrationData);

    f32_t FocalX;	            	/*!< camera X-coordinate focal length [pixel] */
    f32_t FocalY;		            /*!< camera Y-coordinate focal length [pixel] */
    f32_t CenterX;	           	/*!< X-coordinate of camera center point in image [pixel] */
    f32_t CenterY;           		/*!< Y-coordinate of camera center point in image [pixel] */
    f32_t *RadialDistortion;  	/*!< array containing radial distortion coefficient k0 ... k9 */
    ui16_t  NumRadDistCoeff;      /*!< number of elements in array RadialDistortion[] */
  }SACIntrinsicCalibrationData_t;

  static const ui32_t SACExtrinsicCalibrationData_VersionNumber = 2; /*!< version number of struct SACExtrinsicCalibrationData_t */
  /*! \brief camera calibration data (extrinsic ) x_left = R * x_right + t for input */
  typedef struct
  {
    DEFINE_VERSION_MEMBER(SACExtrinsicCalibrationData);
    
    f32_t Baseline;     /*!< camera stereo baseline [m] */

    /* translation vector right to left [m]*/
    f32_t tx;           /*!< x-translation [m] */
    f32_t ty;           /*!< y-translation [m] */
    f32_t tz;           /*!< z-translation [m] */

    /* rotation matrix 3x3, stored rowwise*/
    f32_t *RotMat;		      	/*!< rotation matrix stored colum-major (i.e., col1, col2, col3), 9 elements */
  }SACExtrinsicCalibrationData_t;

  static const ui32_t SACTimeout_VersionNumber = 1; /*!< version number of struct SACTimeout_t */
  /*! \brief used for timeout checks*/
  typedef struct 
  {
    DEFINE_VERSION_MEMBER(SACTimeout);
    ui64_t timelimit;  /*!< Time limit for "time-out" */
    f32_t  distlimit;  /*!< Distance limit for "distance-out" */
    ui8_t  enable;     /*!< 0: disabled, 1: enabled*/
  }SACTimeout_t;

  static const ui32_t SACComponentTimeout_VersionNumber = 1; /*!< version number of struct SACComponentTimeout_t */
  /*! \brief used for timeout checks*/
  typedef struct 
  {
    DEFINE_VERSION_MEMBER(SACComponentTimeout);
    SACTimeout_t QCheckLR;  
    SACTimeout_t QCheckSGM;  
    SACTimeout_t CoarseCalib;     
    SACTimeout_t FineCalib;
  }SACComponentTimeout_t;



  static const ui32_t SACExtrinsicCalibrationDataOut_VersionNumber = 2; /*!< version number of struct SACExtrinsicCalibrationDataOut_t */
  /*! \brief camera calibration data (extrinsic ) x_left = R * x_right + t for output of online calibration*/
  typedef struct
  {
    DEFINE_VERSION_MEMBER(SACExtrinsicCalibrationDataOut);
    
    f32_t Baseline;     /*!< camera stereo baseline [m] */

    /* translation vector right to left [m]*/
    f32_t tx;           /*!< x-translation [m] */
    f32_t ty;           /*!< y-translation [m] */
    f32_t tz;           /*!< z-translation [m] */

    /* rotation matrix 3x3, stored rowwise*/
    f32_t RotMat[9];		 /*!< rotation matrix stored colum-major (i.e., col1, col2, col3) */

	f32_t current_angles[3]; // Lucien=>Nico output

  }SACExtrinsicCalibrationDataOut_t;


  static const ui32_t SACMountingCalibrationData_VersionNumber = 3; /*!< version number of struct SACCalibrationData_t */

  typedef struct
  {
    DEFINE_VERSION_MEMBER(SACMountingCalibrationData);

    /* cameraposition in AUTOSAR - coordinates  */
    f32_t PositionX;		       	/*!< X-position of camera in meters */
    f32_t PositionY;		       	/*!< Y-position of camera in meters */
    f32_t PositionZ;       			/*!< Z-position of camera in meters */

    /* rotation from vehicle to camera coordinates
    right handed, image rows coincide with x-axis, columns with y-axis, z to optical axis */
    f32_t Pitch;	      	/*!< x-rotation (pitch) [rad] */
    f32_t Roll;	       		/*!< y-rotation (roll)  [rad] */
    f32_t Yaw;			      /*!< z-rotation (yaw)   [rad] */

    /* rotation from vehicle to camera coordinates
    right handed, image rows coincide with x-axis, columns with y-axis, z to optical axis
    delta values determined by calibration of lane detection*/
    f32_t DeltaPitch;	      	/*!< x-rotation (pitch) [rad] */
    f32_t DeltaRoll;	     		/*!< y-rotation (roll)  [rad] */
    f32_t DeltaYaw;			      /*!< z-rotation (yaw)   [rad] */
    f32_t Quality;            /*!< Quality measure determined by lane detection */
  }SACMountingCalibrationData_t;


  static const ui32_t SACCalibrationData_VersionNumber = 3; /*!< version number of struct SACCalibrationData_t */

  typedef struct
  {
    DEFINE_VERSION_MEMBER(SACCalibrationData);

    SACImageData_t                ImageDataLeft;        /*!< ROI position and size, left image */
    SACImageData_t                ImageDataRight;       /*!< ROI position and size, right image */
    SACIntrinsicCalibrationData_t IntrinsicLeft;        /*!< intrinsic parameters left camera */
    SACIntrinsicCalibrationData_t IntrinsicRight;       /*!< intrinsic parameters right camera */
    SACExtrinsicCalibrationData_t ExtrinsicRightToLeft; /*!< stereo transformation right to left camera */
    SACMountingCalibrationData_t  MountRight;           /*!< transformation vehicle to right camera coordinate system */
    f32_t                         WshieldModelCoeff[5]; /*!< Model coefficients of windshield distortion model 0..4 i.e.: M[4]*u*v^2 + M[3]*v^2 + M[2]*u*v + M[1]*v + M[0] = dv  */

  } SACCalibrationData_t;


  static const ui32_t SACImage_VersionNumber = 3;      /*!< version number of struct SSACImage_t */
  typedef struct 
  {
    DEFINE_VERSION_MEMBER(SACImage);

    ui16_t *image_p;
    SACSignalState_t SignalStateTimeStamp;             /*!< signal state of TimeStamp */
    i32_t   StartX_px;                                 /*!< Start of rectified image ROI wrt image, x */
    i32_t   StartY_px;                                 /*!< Start of rectified image ROI wrt image, y */
    i32_t   Width_px; 
    i32_t   Height_px;
    TimeFrameStamp_t TFStamp;                          /*!< time stamp in msec and framecounter */
    ui16_t parameterIdLUT;                             /*!< identifier of the LUT which has been used to generate rectified image */
  } SACImage_t; 

  
  static const ui32_t SACDisparity_VersionNumber = 2;  /*!< version number of struct SACDisparity_t */
  typedef struct 
  {
    DEFINE_VERSION_MEMBER(SACDisparity);

    ui16_t *data_p;
    i32_t   StartX_px;                                  /*!< Start of disparity ROI wrt image, x */
    i32_t   StartY_px;                                  /*!< Start of disparity ROI wrt image, y */
    i32_t   Width_px; 
    i32_t   Height_px;
    SACSignalState_t SignalStateTimeStamp;              /*!< signal state of TimeStamp */
    TimeFrameStamp_t TFStamp;                           /*!< timestamp and frame counter information */
  } SACDisparity_t;


  static const ui32_t SACStaticInputData_VersionNumber = 2;  /*!< version number of struct SACStaticInputData_t */
  // presently unused
  typedef struct 
  {
    DEFINE_VERSION_MEMBER(SACStaticInputData);

    i32_t test;
  } SACStaticInputData_t;


  //static const ui32_t T_PFCIF_S_DUDV_VersionNumber = 1;  /*!< version number of struct T_PFCIF_S_DUDV_t */
  typedef struct  
  {
  //  DEFINE_VERSION_MEMBER(T_PFCIF_S_DUDV);

    char i8_DU;
    char i8_DV;
  } T_PFCIF_S_DUDV;


  static const ui32_t SAC_Powerflow_VersionNumber = 3;  /*!< version number of struct SAC_Powerflow */
  typedef struct  
  {
    DEFINE_VERSION_MEMBER(SAC_Powerflow);

    T_PFCIF_S_DUDV *Powerflow_p;                       /*!< Powerflow image */
    bool_t valid;                                      /*!< true, when powerflow data are valid */
    i32_t   StartX_px;                                 /*!< Start of powerflow image ROI wrt image, x */
    i32_t   StartY_px;                                 /*!< Start of powerflow image ROI wrt image, y */
    i32_t   Width_px; 
    i32_t   Height_px;
	  TimeFrameStamp_t TFStamp;                          /*!< Timestamp in msec, frame */
    SACSignalState_t SignalStateTimeStamp;             /*!< signal state of TimeStamp */
  }SAC_Powerflow_t;

  
  static const ui32_t SACSource_VersionNumber = 3; /*!< Version number of enumeration SACSource_t */

  /* helps to define the source of output data */
  typedef enum 
  {
    SAC_SRC_Invalid                    = 00u,    /*!< default, source and data are invalid */
    SAC_SRC_NVM                        = 20u,    /*!< source is existing data in non volatile memory */
    SAC_SRC_EOL                        = 30u,    /*!< source is end of line calibration data */
    SAC_SRC_AutoCalCoarse              = 40u,    /*!< source is coarse calibration data */
    SAC_SRC_AutoCalFine                = 50u,    /*!< source is fine calibration data */
    SAC_SRC_EOLUpdate                  = 60u,    /*!< source is data from end of line update mode */
    SAC_SRC_SelfEval                   = 70u,    /*!< source is data form self evaluation mode */
    SAC_SRC_TempModel                  = 80u,    /*!< source is data form the temperature model */
    SAC_SRC_DistanceTest               = 90u     /*!< source is data form the Conti-EOL distance test */

  } SACSource_t;

  static const ui32_t FromToNVM_VersionNumber = 3;  /*!< version number of struct FromToNVM */
  /* for communication with non volatile memory (NVM) */
  typedef struct
  {
    DEFINE_VERSION_MEMBER(FromToNVM);

    f32_t RotMatRL[9];    /*!< rotation matrix in column major from right to left camera coordinate system */
    f32_t tx;             /*!< translation vector from right to left camera coordinate system which has to be updated with the new rotation matrix*/
    f32_t ty;
    f32_t tz;
    f32_t temperature;
    SACSource_t source;   /*!< source information and valid flag */                    
  }FromToNVM_t;


  static const ui32_t SacUpdEolFromToNVM_VersionNumber = 4;  /*!< version number of struct SacUpdEolFromToNVM */
  /* for data transfer of the updated EOL (see SACMode EOLupdate) to or from non volatile memory (NVM) */
  typedef struct
  {
    DEFINE_VERSION_MEMBER(SacUpdEolFromToNVM);

    f32_t pitch;                   /*!< pitch angle right to left imager in rad (from eol update calibration)*/
    f32_t roll;                    /*!< roll angle right to left imager in rad (from eol update calibration)*/
    f32_t yaw;                     /*!< yaw angle right to left imager in rad (from eol update calibration)*/
    f32_t qltyPitch;               /*!< quality of pitch angle */
    f32_t qltyRoll;                /*!< quality of roll angle */
    f32_t qltyYaw;                 /*!< quality of yaw angle */
    f32_t odometer;                /*!< kilometers when the calibration was carried out */
    f32_t temperature;             /*!< current temperature of the calibration */
    ui8_t targetNo;                /*!< id of the calibration pattern which has been used */
    ui8_t errorCode;               /*!< 0: everything is fine, else: calibration was aborted with error */
    AlgoSignalState_t state;       /*!< 0: initialized, 1: array valid, can be used; 2: invalid */
  }SacUpdEolFromToNVM_t;


  static const ui32_t SacUpdEolInput_VersionNumber = 2;  /*!< version number of struct SacUpdEolInput */
  /* Data required to do the update of the EOL-calibration */
  typedef struct
  {
    DEFINE_VERSION_MEMBER(SacUpdEolInput);

    f32_t  targetPosX;              /*!< Position of the center of the calibration target in world coordinate system */
    f32_t  targetPosY;              /*!< Position of the center of the calibration target in world coordinate system */
    f32_t  targetPosZ;              /*!< Position of the center of the calibration target in world coordinate system */
    ui8_t  targetNo;                /*!< id of the calibration pattern which has been used */
    f32_t  xCircleLeft;             /*!< X coordinate of the left circle on the target determined by mono EOL calibration (image coordinates, ref. imager) */
    f32_t  xCircleRight;            /*!< X coordinate of the right circle on the target determined by mono EOL calibration (image coordinates, ref. imager) */
    f32_t  yCircleLeft;             /*!< Y coordinate of the left circle on the target determined by mono EOL calibration (image coordinates, ref. imager) */
    f32_t  yCircleRight;            /*!< Y coordinate of the right circle on the target determined by mono EOL calibration (image coordinates, ref. imager) */
    f32_t  initTmpModelPitch[16];   /*!< values from the PPAR which are used to initialize the temperature model entry 0: value for -40°C, entry 1: -30°C ... */
    f32_t  initTmpModelRoll[16];    /*!< values from the PPAR which are used to initialize the temperature model entry 0: value for -40°C, entry 1: -30°C ... */
    f32_t  initTmpModelYaw[16];     /*!< slope of the yaw angle which is used to initialize the temperature model entry 0: value for -40°C, entry 1: -30°C ... */

  }SacUpdEolInput_t;


  static const ui32_t SACDistTestMode_VersionNumber = 1; /*!< Version number of enumeration SACDistTestMode_t */

  /* defines a mode for the distance test */
  typedef enum 
  {
    SAC_DSTM_Evaluate                  = 0u,    /*!< default mode, distance test only determines the angles but does not apply them */
    SAC_DSTM_Calibrate                 = 1u     /*!< distance mode determines angles and uses them to initialize the calibration (i.e. temperature model, last calib result)*/
  } SACDistTestMode_t;

  
  static const ui32_t SACDistTestCoordinate_VersionNumber = 1; /*!< Version number of enumeration SACDistTestCoordinate_t */
  /* defines a coordinate system position for the distance test area selection which is specified by P_TopLeft and P_BottomRight */
  typedef enum 
  {
    SAC_DSTM_CoordinateSystem_None = 0u,                      /*!< No coordinate system           */
    SAC_DSTM_CoordinateSystem_Vehicle  = 2u,                  /*!< Direction : Camera Coordinate system, Position : Ground below front axles, Unit : Meter  */
    SAC_DSTM_CoordinateSystem_Camera_rectified_image = 50u,   /*!< Direction : Image Coordinate system, Position : Rectified right Image, Unit : Pixel      */
    SAC_DSTM_CoordinateSystem_Camera_disparity_image = 70u    /*!< Direction : Image Coordinate system, Position : Disparity Image, Unit : Pixel            */
  } SACDistTestCoordinate_t;


  static const ui32_t SacDistTestInput_VersionNumber = 2;  /*!< version number of struct SacDistTestInput */
  /* Data required to do distance test */
  typedef struct
  {
    DEFINE_VERSION_MEMBER(SacDistTestInput);
    // TARGET DEFINITION /////////////////////////////////////////////////////////////////////////////////////////////////////////
    SACDistTestCoordinate_t  CoordinateSystem; /*!< Defines the distance coordinate system for the distance test area selection */
    // If CoordinateSystem = SAC_DSTM_CoordinateSystem_Vehicle
    //      Autosar coordinate on front vehicle axis
    //      P_TopLeft[0] = Y position 
    //      P_TopLeft[1] = Z position
    //      P_BottomRight[0] = Y position
    //      P_BottomRight[1] = Z position    
    // If CoordinateSystem = SAC_DSTM_CoordinateSystem_Camera_rectified_image or SAC_DSTM_CoordinateSystem_Camera_disparity_image
    //      P_TopLeft[0] = U position 
    //      P_TopLeft[1] = V position
    //      P_BottomRight[0] = U position
    //      P_BottomRight[1] = V position    
    f32_t P_TopLeft[2];                        /*!< X,Y-Position of top left corner of the area to be evaluated (meter or px)   */
    f32_t P_BottomRight[2];                    /*!< X,Y-Position of top right corner of the area to be evaluated (meter or px)  */
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    f32_t TargetDistanceNorm;             /*!< Distance norm between reference camera and target center (meter)                 */
    SACDistTestMode_t  mode;              /*!< defines a mode for the distance test */
    f32_t reqRectError;                   /*!< desired rectification error at which the distance test shall be carried out. Coarse calibration will run until this error is reached */
    f32_t  initTmpModelPitch[16];         /*!< values from the PPAR which are used to initialize the temperature model entry 0: value for -40°C, entry 1: -30°C ... */
    f32_t  initTmpModelRoll[16];          /*!< values from the PPAR which are used to initialize the temperature model entry 0: value for -40°C, entry 1: -30°C ... */
    f32_t  initTmpModelYaw[16];           /*!< slope of the yaw angle which is used to initialize the temperature model entry 0: value for -40°C, entry 1: -30°C ... */
  }SacDistTestInput_t;


  static const ui32_t SACDistTestSigState_VersionNumber = 1; /*!< Version number of enumeration SACDistTestSigState_t */

  /* defines the state of the output struct of the distance test */
  typedef enum 
  {
    SAC_DSTMO_Default                  = 0u,    /*!< default mode, values not initalized*/
    SAC_DSTMO_ValidDstTest             = 1u,    /*!< outputs are valid and were determined in the distance test, w/o calibration*/
    SAC_DSTMO_ValidCalibration         = 2u     /*!< outputs are valid and have been used for calibration*/
  } SACDistTestSigState_t;

  static const ui32_t SacDistTestFromToNVM_VersionNumber = 1;  /*!< version number of struct SacDistTestFromToNVM */
  /* Data results of the distance test */
  typedef struct
  {
    DEFINE_VERSION_MEMBER(SacDistTestFromToNVM);

    f32_t meanDisparity;            /*!< mean of the disparity map in the specified areay (but w/o pixels marked as invalid)*/
    f32_t densityDisparity;         /*!< density of the disparity map (i.e. ratio of valid pixels / area to be evaluated) */
    f32_t xTargetDistMeasured;      /*!< Measured distance from rectified camera to the target in m (rectified optical axis) */
    f32_t xTargetDistMeasured_std;  /*!< debug data : standard deviation of xTargetDistMeasured */
    f32_t xTargetDistMeasured_min;  /*!< debug data : min of xTargetDistMeasured */
    f32_t xTargetDistMeasured_max;  /*!< debug data : max of xTargetDistMeasured */
    f32_t TargetDistanceNorm;       /*!< Distance norm between reference camera and target center (meter)                 */
    f32_t pitch;                    /*!< relative pitch angle determined via distance test (camera coordinate system orientation) */
    f32_t roll;                     /*!< relative roll angle determined via distance test (camera coordinate system orientation) */
    f32_t yaw;                      /*!< relative yaw angle determined via distance test (camera coordinate system orientation) */
    f32_t rectError;                /*!< actual rectification error when the results were generated */
    f32_t temperature;              /*!< temperature which was used to initialize the temperature model (if chosen by mode) */
    ui16_t errorCode;               /*!< Error code, 0 means everything OK, >0 means Error occurred */
    SACDistTestSigState_t  state;   /*!< defines a mode for the distance test */
  }SacDistTestFromToNVM_t;



 static const ui32_t TempArray_VersionNumber = 1;  /*!< version number of struct FromToNVM */
  /* for communication with non volatile memory (NVM) */
  typedef struct
  {
    DEFINE_VERSION_MEMBER(TempArray);

    f32_t temperat[10];    /*!< array filled with temperatures: [0]: right imager temperature, 
                                                                [1]: left imager temperature,
                                                                [2]: MCU tempertaure
                                                                [3]: Stereo DSP temperature,
                                                                [4]: Mono DSP temperature
                                                                [5]: FPGA temperature
                                                                [6]: interior temperature
                                                                [7]: exterior temperature
                                                             [8..9]: reserved*/
    ui16_t noOfEntries;  /*!< number of valid entries in temperatures array */
    TimeFrameStamp_t TFStamp;                          /*!< Timestamp in usec, frame */

  }TempArray_t;


 
  static const ui32_t SACRadarDistInput_VersionNumber = 1;  /*!< version number of struct SACRadarDistInput_t */
  /* Radar data which can be used for yaw angle computation */
  typedef struct
  {
    DEFINE_VERSION_MEMBER(SACRadarDistInput);

    i32_t crcChecksum;                                 /*!< CRC-checksum of signal group according to SAE J1850 */
    i32_t seqCntr;                                     /*!< Sequence counter */
    i32_t rduDTQTimestamp;                             /*!< RDU DTQ time stamp */
    i32_t rduGlobTimestamp;                            /*!< RDU Global time stamp */
    i32_t fft;                                         /*!< Object find for this special identification */
    f32_t xPosition;                                   /*!< Object x-position, relative, cartesian, autosar */
    f32_t vxSpeed;                                     /*!< Object vx-speed, relative, cartesian, autosar */
    f32_t yPosition;                                   /*!< Object y-position, relative, cartesian, autosar */
    TimeFrameStamp_t TFStamp;                          /*!< Timestamp in usec, frame */
    i32_t dataQuality;                                 /*!< if == 0: input not used, if == 1: input used */
  }SACRadarDistInput_t;

  static const ui32_t SACStereoDistInput_VersionNumber = 1;  /*!< version number of struct SACStereoDistInput_t */
  /* stereo data which can be used for yaw angle computation */
  typedef struct
  {
    DEFINE_VERSION_MEMBER(SACStereoDistInput);

    f32_t  xPosition;                                   /*!< distance in m to a vehicle which drives ahead, measured by camea (longitudinal distance, computed by SPOD) */
    f32_t  quality;                                     /*!< quality measure of POD object */
    i32_t  valid;                                       /*!< valid bit of POD object */
    ui32_t objID;                                       /*!< object ID */
    f32_t  y_bl_m;                                      /*!< y back left corner of object */
    f32_t  y_br_m;                                      /*!< y back right corner of object */
    TimeFrameStamp_t TFStamp;                           /*!< Timestamp in usec, frame */
    
  }SACStereoDistInput_t;


  
  //static const ui32_t SACEvalInput_VersionNumber = 1;  /*!< version number of struct SACEvalInput_t */
  ///* Debug input for better performance evaluation of SAC */
  //typedef struct
  //{
  //  DEFINE_VERSION_MEMBER(SACEvalInput);

  //  SACRadarInput_t radar;                             /*!< radar input data */
  //  f32_t stereoDistance;                              /*!< distance in m to a vehicle which drives ahead, measured by camea (longitudinal distance, computed by SPOD) */
  //  TimeFrameStamp_t TFStamp;                          /*!< Timestamp in usec, frame */

  //}SACEvalInput_t;

  static const ui32_t SACSFModeOut_VersionNumber = 1; /*!< Version number of enumeration SACSFModeOut_t */

  /* Defines the mode of the framework software the SAC wants to be executed in (output of SAC)*/
  typedef enum 
  {
    SAC_SFModeOut_Default                 = 00u,    /*!< undefined, do not react to it */
    SAC_SFModeOut_StandAlone_Requested    = 10u,    /*!< SAC wants to be executed in StandAlone mode */
    SAC_SFModeOut_StandAlone_Running      = 11u,    /*!< SAC is currently running in StandAlone mode */
    SAC_SFModeOut_StandAlone_Finished     = 12u,    /*!< SAC is finished with its computations in StandAlone Mode (usually in this case RunParallel is requested)  */
    SAC_SFModeOut_RunParallel_Requested   = 20u,    /*!< SAC wants to be executed in parallel to other driver assistance functions */
    SAC_SFModeOut_RunParallel_Running     = 21u,    /*!< SAC is currently running in parallel to other driver assistance functions */
    SAC_SFModeOut_RunParallel_Finished    = 22u     /*!< SAC is finished with computations which were done in parallel to other functions */
  } SACSFModeOut_t;


static const ui32_t SACSFModeIn_VersionNumber = 1; /*!< Version number of enumeration SACSFModeIn_t */

  /* Defines the current mode of the framework software */
  typedef enum 
  {
    SAC_SFModeIn_Default                  = 00u,    /*!< undefined, do not react to it */
    SAC_SFModeIn_StandAlone               = 10u,    /*!< Software framework is running SAC in StandAlone Mode */
    SAC_SFModeIn_RunParallel              = 20u     /*!< Software framework is running SAC in parallel to other functions */
  } SACSFModeIn_t;



  /*! Type definition for Blockage status. */
  typedef enum
  {
    SAC_GB_UNKNOWN_STATUS	                 = 0u,		/*!< Unknown status (init error, communication error,...) */
    SAC_GB_NO_BLOCKAGE		                  = 1u,		/*!< No Blockage */
    SAC_GB_TOLERATED_BLOCKAGE	              = 2u,		/*!< Tolerated Blockage */
    SAC_GB_CONDENSATION		                  = 3u,		/*!< Condensation */
    SAC_GB_PART_BLOCKAGE		                = 4u,		/*!< Partial Blockage */
    SAC_GB_LOW_VISIBILITY		                = 5u,		/*!< Low Visibility */
    SAC_GB_BLOCKAGE			                    = 6u		/*!< Blockage */
  } SAC_GB_t_eBlockageStatus;

/*! Type definition for the blockage of a MPC function */
typedef struct
{	
	SAC_GB_t_eBlockageStatus		e_BlockageStatus;		/*!< Blockage Status */
	ui8_t				ui8_StatusConf;			/*!< confidence (0..100) */
} SAC_GB_t_FctBlockage;



static const ui32_t SACQthres_VersionNumber = 1;  /*!< version number of struct SACQthres_t */
/* Used for quality threshold array */
typedef struct
{
  DEFINE_VERSION_MEMBER(SACQthres);
  f32_t qThres;                                 /*!< value of the quality threshold */
  ui8_t mode;                                   /*!< 0: qThres is ignored, default thresholds are applied, 1: qThres is used*/
}SACQthres_t;


  static const ui32_t SACDynamicInputData_VersionNumber = 9;  /*!< version number of struct SACDynamicInputData */

  typedef struct 
  {
    DEFINE_VERSION_MEMBER(SACDynamicInputData);

    SACSFModeIn_t SFrameworkMode;                       /*!< current mode of software framework */
    SACCalibrationData_t CalibrationData;               /*!< calibration information, image size, etc... */
    SACImage_t imageDataRectLeftCurrent;                /*!< left rectified image in current frame */
    SACImage_t imageDataRectRightCurrent;               /*!< right rectified image in current frame */
    SACImage_t imageDataRectLeftPrev;                   /*!< left rectified image in previous frame */
    SACImage_t imageDataRectRightPrev;                  /*!< right rectified image in previous frame */
    SAC_Powerflow_t imageDataTimePowerflow;             /*!< Time Powerflow image (Right) */	// Lucien=>Nico input
	  SAC_Powerflow_t imageDataRightLeftPowerflow;        /*!< Right Left Powerflow  image */		// Lucien=>Nico input
    f32_t VehicleSpeed;								                	/*!< Vehicle Speed in m/s */			
	  f32_t YawRate;										                  /*!< Yaw Rate in rad/s */	
    f32_t VehicleAcceleration;                          /*!< Acceleration in m/(s^2) */
    f32_t VehicleKilometers;                            /*!< Vehicle kilometers in km */
    i32_t isRain;                                       /*!< if >0: rain, if ==0: no rain */
    i32_t isDay;                                        /*!< if >0; night, if==0: day */
    f32_t exposureTime;                                 /*!< exposure time of imagers in us */
    SACModes_t diagnosisTriggerSACMode;                 /*!< set SAC into specific mode via diagnosis (only supported: SAC_Mode_Deflt (i.e. do nothing) SAC_Mode_AutoCalCoarse (i.e. do coarse calibration) */
    //f32_t ImgCurrTemperature;                         /*!< Imager temperature in degree centigrade */
    TempArray_t temperatures;                           /*!< Array of temperatures e.g. of imagers, MCU, DSP, FPGA,... */
    f32_t DistFrontToRearAxis;                          /*!< Distance between front and rear axis in meters */
    SACDisparity_t disparityMapCurrent;                 /*!< disparity (overview) map for current frame */
    SACDisparity_t disparityMapPrev;                    /*!< disparity (overview) map for previous frame */
    FromToNVM_t InputFromNVM;                           /*!< access to calibration data which is stored in NVM */
    SacUpdEolFromToNVM_t EOLupdateFromNVM;              /*!< previously determined update values of rotation by SAC */
    SacUpdEolInput_t EOLupdateInput;                    /*!< input from Diagnosis and PPARs for executing the EOL-Update mode */
    SacDistTestFromToNVM_t DistTestFromNVM;             /*!< data which have been saved by a previously conducted dist test in NVM */
    SacDistTestInput_t DistTestInput;                   /*!< input from Diagnosis and PPARs for executing the DistTest mode */
    //SACEvalInput_t EvaluationInp;                     /*!< contains distance measurements of other modules which help to assess the performance of SAC */
    ui32_t ui_DiagnoseDebugFlags;                       /*!< Diagnosis debug input bitfield (currently unused)*/
    SACRadarDistInput_t radarDist;                      /*!< radar distance data for yaw angle computation */
    SACStereoDistInput_t stereoDist;                    /*!< stereo distance data for yaw angle computation */
    SAC_GB_t_FctBlockage SAC_GB_FctBlockage;            /*!< camera blockage information */
    SACComponentTimeout_t timeout;                      /*!< define SAC-Timeouts */
    SACQthres_t qThresholds[20];                        /*!< Array of Quality thresholds tbd. */
  } SACDynamicInputData_t;


 
  typedef struct
  {
    ui32_t VersionNumber;
    char VersionInfo[51];
  }SACAlgoVersion_t;






  typedef i16_t sac_lut_fixedpoint_t;


   /* Rotation from rectified (virtual) camera to vehicle coordinate system in Autosar coordinate system. 
  Order of rotation: roll (x-axis), pitch (y-axis), yaw (z-axis)   */
  /*typedef struct 
  {
    f32_t Pitch;
    f32_t Roll;
    f32_t Yaw;
  } SACRectToVcl_t;*/

  static const ui32_t SACRectCamPars_VersionNumber = 2; /*!< Version Number of struct SACRectCamPars */
  /* camera parameters of rectified stereo system */
  typedef struct
  {
    DEFINE_VERSION_MEMBER(SACRectCamPars);

    f32_t                         FocalX;	            	/*!< camera X-coordinate focal length [pixel] */
    f32_t                         FocalY;		            /*!< camera Y-coordinate focal length [pixel] */
    f32_t                         CenterX;	           	/*!< X-coordinate of camera center point in image [pixel] */
    f32_t                         CenterY;           		/*!< Y-coordinate of camera center point in image [pixel] */
    f32_t                         Baseline;             /*!< camera stereo baseline [m] */
    // SACRectToVcl_t             RectToVcl;            /*!< rotation from original to rectified camera */
    SACMountingCalibrationData_t  MountRightRect;       /*!< pitch, roll, yaw angle to rotate rectified to orig camera in Autosar Coordinates. 1st rotation axis: x, 2nd: y, 3rd z., x,y,z coordinates are identical to MountRight*/
    SACBBox_t                     BBoxLeft;             /*!< bounding box of left rectified image */
    SACBBox_t                     BBoxRight;            /*!< bounding box of right rectified image */
  }SACRectCamPars_t;


  static const ui32_t SACReturnState_VersionNumber = 4; /*!< Version number of enumeration SACReturnState_t */

  /* return state of ongoing computation
  "_Ready" states indicate that the calibration result can be used */
  typedef enum 
  {
    SAC_Mode_Default                   = 00u,    /*!< undefined */
    SAC_Mode_Test_Running              = 11u,    /*!< test mode, send defined set of output data */
    SAC_Mode_Test_Finished             = 12u,    /*!< test mode, send defined set of output data */
    SAC_Mode_Test_Failed               = 13u,    /*!< test mode, send defined set of output data */
    SAC_Mode_MeasOnly_Running          = 21u,    /*!< MeasFreeze mode running, send MeasFreeze data only, output data invalid */
    SAC_Mode_MeasOnly_Finished         = 22u,    /*!< MeasFreeze mode finished, send MeasFreeze data only, output data invalid */
    SAC_Mode_MeasOnly_Failed           = 23u,    /*!< MeasFreeze mode failed, currently not used */
    SAC_Mode_InitLUT_Running           = 31u,    /*!< LUT init running */
    SAC_Mode_InitLUT_Finished          = 32u,    /*!< LUT init finished, resulting LUT can be used */
    SAC_Mode_InitLUT_Failed            = 33u,    /*!< LUT init failed, resulting LUT cannot be used */
    SAC_Mode_AutoCalCoarse_Running     = 41u,    /*!< coarse autocalibration still running, do not use resulting parameters/LUT */
    SAC_Mode_AutoCalCoarse_Finished    = 42u,    /*!< coarse autocalibration finished, resulting camera paramters and LUT can be used */
    SAC_Mode_AutoCalCoarse_Failed      = 43u,    /*!< coarse autocalibration failed, do not use resulting parameters/LUT */
    SAC_Mode_AutoCalFine_Running       = 51u,    /*!< fine autocalibration still running, do not use resulting parameters/LUT */
    SAC_Mode_AutoCalFine_Finished      = 52u,    /*!< fine autocalibrationfinished, resulting camera paramters and LUT can be used */
    SAC_Mode_AutoCalFine_Failed        = 53u,    /*!< fine calibration cannot compensate decalibration any longer -> e.g. coarse mode is required*/
    SAC_Mode_EOLUpdate_Running         = 61u,    /*!< End of line update mode is running */
    SAC_Mode_EOLUpdate_Finished        = 62u,    /*!< End of line update mode is finished, data can be used and stored in nvm */
    SAC_Mode_EOLUpdate_Failed          = 63u,    /*!< End of line update mode failed, data are marked as invalid (can also be stored) */
    SAC_Mode_SelfEval_Running          = 71u,    /*!< SelfEvaluation mode is running */
    SAC_Mode_SelfEval_Finished         = 72u,    /*!< SelfEvaluation mode is finished, output is valid */
    SAC_Mode_SelfEval_Failed           = 73u,    /*!< SelfEvaluation mode has failed, output is marked as invalid */
    SAC_Mode_DistTest_Running          = 81u,    /*!< Distance test is running */
    SAC_Mode_DistTest_Finished         = 82u,    /*!< Distance test is finished */
    SAC_Mode_DistTest_Failed           = 83u     /*!< Distance test failed */
  } SACReturnState_t;


  static const ui32_t SACCalibQuality_VersionNumber = 1; /*!< Version number of enumeration SACCalibQuality_t */

  /* summary of the calibration quality */
  typedef enum 
  {
    SAC_CalibQuality_undefined         = 0u,    /*!< undefined, ignore result */
    SAC_CalibQuality_good              = 1u,    /*!< good quality */
    SAC_CalibQuality_sufficient        = 3u,    /*!< sufficient quality (fine calibration should be able to compensate) */
    SAC_CalibQuality_insufficient      = 6u     /*!< insufficient quality (coarse calibration required) */
  } SACCalibQuality_t;



static const ui32_t SACEvalOutput_VersionNumber = 1; /*!< Version Number of struct SACEvalOutput */
  /* Output of the SelfEvaluation mode and other quality measures from different sources */
  typedef struct
  {
    DEFINE_VERSION_MEMBER(SACEvalOutput);
    SACCalibQuality_t             overall;                       /*!< Result of overall assesment of calibration quality result */
    SACCalibQuality_t             pitch;                         /*!< Result of pitch calibration quality result */
    SACCalibQuality_t             roll;                          /*!< Result of roll calibration quality result */
    SACCalibQuality_t             yaw;                           /*!< Result of yaw calibration quality result */
    SACCalibQuality_t             diparity;                      /*!< Result of disparity map density result */

    f32_t                         ErrorOutput[10];	             	/*!< [0]: Rectification error result of SelfEval mode
                                                                       [1]: Rectification error result of coarse calibration
                                                                       [2]: Rectification error result of fine calibration
                                                                       [3]: Deviation of SPOD distance and radar distance
                                                                       [4]: Disparity map density from 0 to 100 
                                                                       [5]...[9]: Reserve */
    TimeFrameStamp_t              ErrorTFstamp[10];               /*!< [0]...[9]: Corresponding timestamp and framecounter information to ErrorOutput array */
    
  }SACEvalOutput_t;

  //static const ui32_t SACEpipolarCorresp_VersionNumber = 1; /*!< Version number of struct SACEpipolarCorresp_t */
  /* contains one epipolar point correspondence, sub-pixel accurate */
  typedef struct 
  {   
    f32_t            u0; //Horizontal position, image 0
    f32_t            v0; //Vertical position, image 0
    f32_t            u1; //Horizontal position, image 1
    f32_t            v1; //Vertical position, image 1
  }SACEpipolarCorresp_t;


  //static const ui32_t SACYawPoint_VersionNumber = 1; /*!< Version number of struct SACYawPoint_t */
  /* A single stereo result for yaw angle estimation */
  typedef struct 
  { 
    f32_t            u; //Horizontal position, image 0
    f32_t            v; //Vertical position, image 0
    f32_t            d; //Disparity in pixels
  }SACYawPoint_t;

  static const ui32_t SACDebug_VersionNumber = 8; /*!< Version number of struct SACDebug_t */
  /* output for debug purposes */
  typedef struct 
  {
    DEFINE_VERSION_MEMBER(SACDebug);

    ui32_t                numberOfUsedFrames;                  // -> Lucien, please fill struct
    f32_t                 temperatureOld;
    f32_t                 temperatureNew;
    f32_t                 RotMatOld[9];
    f32_t                 RotMatNew[9];
    f32_t                 RotMatSACYawRadar[9];
    f32_t                 RotMatSACYawStereo[9];
    f32_t                 txtytzOld[3];
    f32_t                 txtytzNew[3];
    ui32_t                bin_cnt_epipolar[4]; // BINS_U*BINS_V
    ui32_t                bin_cnt_yaw[5];      // BINS_D
    SACEpipolarCorresp_t  epicorresp[120];
    ui8_t                 epicorresp_new[120]; // indicate new epi points
    SACYawPoint_t         yaw[400];
    ui32_t                median_buffer_entries;
    f32_t                 median_buffer[3][11];
    f32_t                 median_buffer_rmse_epipolar[11];
    f32_t                 median_buffer_rmse_improvement[11];
    SACEvalOutput_t       eval; 
  }SACDebug_t;

#ifdef __PDO__
 typedef struct FlexrayBits{
    ui64_t FrameCnt  : 2;
    ui64_t NoUsedFr  :16;
    ui64_t Blockage  : 2;
    ui64_t RadarCal  : 3;
    ui64_t BinFill   : 4;
    ui64_t RectError : 8;
    ui64_t SFMode    : 2;
    ui64_t SACState  : 3;
    ui64_t Error     : 8;
    ui64_t VersBugfx : 4;
    ui64_t VersMinor : 4;
    ui64_t VersMajor : 4;
    ui64_t AlgoID    : 4;
  } FlexrayBitfield_t;
#else
  typedef ui64_t FlexrayBitfield_t;
#endif


  static const ui32_t SACStatistics_VersionNumber = 4U; /*!< Version number of struct SACStatistics_t */
  /* output of sac statistics data */
  typedef struct 
  {
    DEFINE_VERSION_MEMBER(SACStatistics);
    FlexrayBitfield_t FlexrayBitfield;       /*!< Bitfield for Flexray output */
    ui32_t RectErrHistBin[12];      // Bin 0: Recterror == 0 (i.e. undefined)
                                    // Bin 1: 0   < Recterror <= 0.1
                                    // Bin 2: 0.1 < Recterror <= 0.2
                                    // Bin 3: 0.2 < recterror <= 0.3
                                    // Bin 4: 0.3 < Recterror <= 0.4
                                    // Bin 5: 0.4 < Recterror <= 0.5
                                    // Bin 6: 0.5 < Recterror <= 0.6
                                    // Bin 7: 0.6 < Recterror <= 0.7
                                    // Bin 8: 0.7 < Recterror <= 0.8
                                    // Bin 9: 0.8 < Recterror <= 0.9
                                    // Bin10: 0.9 < Recterror <= 1.0
                                    // Bin11:       Recterror >  1.0 

    ui32_t NoUsedFramesHistBin[6];  // Bin 0:     0 < NoUsedFrames <=    10
                                    // Bin 1:    10 < NoUsedFrames <=   100
                                    // Bin 2:   100 < NoUsedFrames <=  1000
                                    // Bin 3:  1000 < NoUsedFrames <= 10000
                                    // Bin 4: 10000 < NoUsedFrames <= 20000
                                    // Bin 5:        NoUsedFrames >  20000
    
    f32_t  KmetersLastCoarseCalib;  // kilometers (odometer) of last coarse calibration
    f32_t  KmetersLastFineCalib;    // kilometers (odometer) of last fine calibration
    f32_t  KmetersLastYawCalib;     // kilometers (odometer) of last yaw angle calibration
    f32_t  KmetersLastError;        // kilometers (odometer) of last error
    f32_t  KmetersStartOfStatistic; // kilometers (odometer) of start of statistics

    i32_t  LastError;               // number of last SAC error, corresponding to KmetersLastError

    f32_t  CurrRecterror;           // current rectification error
    ui32_t CurrNoUsedFrames;        // current no of used frames (for last calibration)

    f32_t  MaxDistCalib;            // Maximal distance between two calibrations in km
    ui32_t MaxNoUsedFramesFine;     // Maximal number of used frames in fine calibration
    ui32_t MaxNoUsedFramesCoarse;   // Maximal number of used frames in coarse calibration

    f32_t  MinPitch;                // minimum pitch angle on this vehicle
    f32_t  CurrPitch;               // current (last applied) pitch angle
    f32_t  MaxPitch;                // maximum pitch angle on this vehicle

    f32_t  MinYaw;                  // minimum yaw angle on this vehicle
    f32_t  CurrYaw;                 // current (last applied) yaw angle
    f32_t  MaxYaw;                  // maximum yaw angle on this vehicle

    f32_t  MinRoll;                 // minimum roll angle on this vehicle
    f32_t  CurrRoll;                // current (last applied) roll angle
    f32_t  MaxRoll;                 // maximum roll angle on this vehicle

    SACSource_t source;             // source of the current angles

    AlgoSignalState_t state;        // 0: initialized, 1: array valid, can be used; else: invalid

  }SACStatistics_t;


  static const ui32_t SACResult_VersionNumber = 1; /*!< Version number of enumeration SACResult_t */

  /* summary of the SAC result states */
  typedef enum 
  {
    SAC_Result_Default         = 0u,    /*!< undefined, ignore result */
    SAC_Result_Usable          = 1u,    /*!< SAC output can be used by other algorithms*/
    SAC_Result_NotUsable       = 2u     /*!< SAC output shall not be used by other algorithms */
  } SACResult_t;

  static const ui32_t SACOutputData_VersionNumber = 8; /*!< Version number of struct SACOutputData_t */

  typedef struct 
  {
    DEFINE_VERSION_MEMBER(SACOutputData);

    SACReturnState_t                  SACState;                          /*!< Internal State of SAC (in which mode SAC currently executes internally) */
    SACSFModeOut_t                    SACSFMode;                         /*!< Defines standalone / run in parallel computation for the software framework */
    TimeFrameStamp_t                  TFStamp;                           /*!< time stamp when output data was generated in msec */
    ui64_t                            SACWarnings;                       /*!< bitwise coding of warnings. Value 0 means everything is OK, 
                                                                         LSB= Bit 1: ROIshift out of range
                                                                              Bit 2: SAC resulting angles pitch, roll, yaw go beyond security boarders
                                                                              Bit 3-64: To be defined */
    i32_t                             pi32_usePowerflowLRMode;           /*!< if 0, uses powerflow time, otherwise use lr-mode of powerflow */
    FromToNVM_t                       OutputToNVM;
    SACResult_t                       SACResult;                         /*!< Defines whether SAC-result is valid or not */
    i32_t                             SACError;                          /*!< Number of SAC-Error */
    
    /* LUTs for FPGA rectification */
    sac_lut_fixedpoint_t             *ps_LUTCompLeft;
    sac_lut_fixedpoint_t             *ps_LUTCompRight;
    i32_t                            *pi32_ByteCountPerLUT;
   // ui16_t                            parameterIdLUTs;
    ui16_t                            parameterIdLutLeft;
    ui16_t                            parameterIdLutRight;
    ui16_t                            parameterIdRectPars;

    /* rectified camera parameters for other algos */
    SACRectCamPars_t                  rectCamPars;
    /* SAC-Rectification Rotation */

    /*!< updated stereo transformation right to left camera from online calibration
    has to be stored for next ignition cycle */
    SACExtrinsicCalibrationDataOut_t  ExtrinsicRightToLeftUpdate;
    SACSignalState_t                  ExtrinsicRightToLeftUpdateValid;
    SACDebug_t                        DebugDataOutput;
    SACshiftedROIData_t               shiftedROIData;                          
    SacUpdEolFromToNVM_t              EOLupdateToNVM;                  /*!< determined update values of rotation by SAC to be stored in NVM */
    SacDistTestFromToNVM_t            DistTestToNVM;                   /*!< result of the disttest which shall be stored in NVM */
    FlexrayBitfield_t                 FlexrayBitfield;                 /*!< Bitfield for Flexray output */
  } SACOutputData_t;

  /* PFC interface typedefs of used services */

  /* service for cache invalidation */
  typedef void (*Fct_v_CacheInvalidateAll)(void);

  /* service for starting a DMA transfer 
  (pv_Src -> pv_Dest)[sl_Size] */
  typedef i32_t (*Fct_sl_DMACopy)(void *pv_Dest, void *pv_Src, i32_t sl_Size, i32_t *psl_Handle);

  /* service for starting a 2D-DMA transfer */
  typedef i32_t (*Fct_sl_DMACopy_2D)(void *pv_Dst, void *pv_Src,
    i32_t sl_DstPitch, i32_t sl_SrcPitch,
    i32_t sl_Width, i32_t sl_Height,
    i32_t *psl_Handle);

  /* service for starting a chained DMA transfer 
  (pv_PreSrc -> pv_PreDest)[sl_PreSize] followed by 
  (pv_PostSrc-> pv_PostDest)[sl_PostSize] */
  typedef i32_t (*Fct_sl_DMACopyChained)(void *pv_PreDest, void *pv_PreSrc, i32_t sl_PreSize,
    void *pv_PostDest, void *pv_PostSrc, i32_t sl_PostSize,
    i32_t *psl_PostHandle);

  /* service for waiting for the DMA transfer specified by sl_Handle */
  typedef i32_t (*Fct_sl_DMAWait)(i32_t sl_Handle);

  /* MeasFreeze service */
  typedef i32_t (*Fct_sl_MEASFreeze) (void *pData, i32_t size, i32_t VirtAddr);

  typedef struct {
    Fct_v_CacheInvalidateAll  pfct_v_CacheInvalidateAll;
    Fct_sl_DMACopy            pfct_sl_DMACopy;
    Fct_sl_DMACopy_2D         pfct_sl_DMACopy_2D;
    Fct_sl_DMACopyChained     pfct_sl_DMACopyChained;
    Fct_sl_DMAWait            pfct_sl_DMAWait;
    Fct_sl_MEASFreeze         pfct_sl_MEASFreeze;
  }SACCallBackHdlr_t;

  /* Required input ports: Receiver (data) and Client (functions) */
  typedef struct {
    SACModes_t                    SACMode;
    const void                  * pvd_L2Ram;
    i32_t                         i32_SizeOfL2Bytes;
    const SACDynamicInputData_t * pDynamicInputData;
    const CCT_SPODObjectList_t  * pSPODObjectList;
    const SACCallBackHdlr_t     * pSACCallBackHdlr;        /* SAC call back handlers */
  } reqSACPrtList_t;

  /* Provided ouput ports: Sender (data) and Server (functions) */
  typedef struct {
    SACOutputData_t         *pOutputData;
    CalibrationData_t       *pCalibrationData;
    SAC_SystemInfo_t        *sysInfo;
    SACNvAngleData_t        *pSACNvAngleData;
    SACStatistics_t         *pSACStatistics;
  } proSACPrtList_t;

  /* *****************************************************************************
  Functionname : SACInit                                                    */ /*!
  Description  : initialize SAC algorithm with FW services

  @param[in]     CODFctPtrs_t:     function pointers
  @return        i32_COD_NO_ERROR or error code
  @pre           -
  @post          -
  @author        Jochen Schmidt
  **************************************************************************** */
  i32_t SACInit(const reqSACPrtList_t *reqPorts, proSACPrtList_t *proPorts);

  /* *****************************************************************************
  Functionname : SACOpen                                                    */ /*!
  Description  : open SAC algorithm

  @param[in]     pStaticInputData: static algo data
  @return        i32_SAC_NO_ERROR or error code
  @pre           -
  @post          -
  @author        Jochen Schmidt
  **************************************************************************** */
  i32_t SACOpen(const reqSACPrtList_t *reqPorts, proSACPrtList_t *proPorts);

  /* **************************************************************************** 
  Functionname : SACRun                                                    */ /*!  
  Description  : run SAC algorithm

  @param[in]     pDynamicInputData: dynamic input data
  @param[out]    pOutputData: output data to fill

  @return        i32_SAC_NO_ERROR or error code
  @pre           -
  @post          -
  @author        Jochen Schmidt
  **************************************************************************** */
  i32_t SACRun(const reqSACPrtList_t *reqPorts, proSACPrtList_t *proPorts);

  /* **************************************************************************** 
  Functionname : SACClose                                                  */ /*!  
  Description  : close SAC algorithm

  @return        i32_SAC_NO_ERROR or error code
  @pre           -
  @post          -
  @author        Jochen Schmidt
  **************************************************************************** */
  i32_t SACClose(void);

  
  i32_t SACGetInternalState(void* PV_AlgoState, ui32_t* length);

  i32_t SACGetAlgoVersion(SACAlgoVersion_t *pAlgoVersion);  

#ifdef __cplusplus
}
#endif

#endif /* SAC_INTERFACE_H */

