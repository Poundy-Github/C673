/*! \file **********************************************************************

  @defgroup SWA_LAOffsetEstimationUnit VDY Offset Estimation - SWA and AY Unit Design
	@ingroup VDYHandCode
  @{
	  
  $Company:			Continental AG $

  $Component:		VDY (Vehicle Dynamics Observer) $

  $Module:			vdy_swa.c $

  @brief			This module contains the steering wheel angle (SWA) and lateral acceleration offset estimation

  $Descripion:		$

  $Revision: 1.30 $

  CHANGES:
  ---*/ /*---
  CHANGE:           $Log: vdy_ay_swa.c  $
  CHANGE:           Revision 1.30 2020/06/06 18:44:42CEST Chinnaswamy, Ramachandra (uids4735) (uids4735) 
  CHANGE:           merging to mainline
  CHANGE:           Revision 1.26.1.2 2020/06/04 21:57:04CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Test Cases Links Update
  CHANGE:           Revision 1.26.1.1 2020/05/31 23:26:36CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Test Scripts Linking
  CHANGE:           Revision 1.26 2020/05/14 02:00:34CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Design Update
  CHANGE:           Revision 1.25 2020/05/13 01:00:48CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Design update - Traceability
  CHANGE:           Revision 1.24 2020/05/06 08:46:55CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           PRQA Template Update
  CHANGE:           Revision 1.23 2020/05/04 23:06:14CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Design Update
  CHANGE:           Revision 1.22 2020/04/25 22:23:08CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Design Update
  CHANGE:           Revision 1.21 2020/04/15 15:49:54CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           L4 Design Link
  CHANGE:           Revision 1.20 2019/12/31 12:24:36CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           QAC Fixes
  CHANGE:           Revision 1.19 2019/11/04 17:08:57CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Migration of legacy changes into Mainstream
  CHANGE:           Revision 1.18 2019/06/11 08:36:15CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           QAF Fixes
  CHANGE:           Revision 1.17 2019/03/13 12:22:43CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Meas opitimization and vdy memset definition
  CHANGE:           Revision 1.16 2019/01/31 07:25:25CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Design Update
  CHANGE:           Revision 1.15 2019/01/26 21:24:03CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Followed camel case convention for methods
  CHANGE:           Revision 1.14 2019/01/09 13:36:53CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Design - Doors Linking
  CHANGE:           Revision 1.13 2019/01/03 10:44:34CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Design Update - UML for functions
  CHANGE:           Revision 1.12 2018/12/05 10:53:14CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           QAC fixes
  CHANGE:           Revision 1.11 2018/11/28 12:07:30CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           QAC fixes
  CHANGE:           Revision 1.10 2018/11/15 10:41:21CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           PDO tool support
  CHANGE:           Revision 1.9 2018/10/26 15:49:12CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Accordance with AL_VDY_BASE_05.00.10_INT-0
  CHANGE:           Revision 1.8 2018/09/17 14:00:03CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Support for courage environment: Defined STATIC_VAR
  CHANGE:           Revision 1.7 2018/09/12 16:23:15CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Support for courage environment
  CHANGE:           Revision 1.6 2018/09/04 12:00:05CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Design Update
  CHANGE:           Revision 1.5 2018/08/28 13:29:33CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Unit Design Update
  CHANGE:           Revision 1.4 2018/08/24 15:31:12CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Unit Design Update
  CHANGE:           Revision 1.3.1.2 2018/08/09 10:41:24CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           Initial revision
  CHANGE:           Member added to project /ADAS/SW/Components/VDY_VehicleDynamics/04_Engineering/01_Source_Code/VDY/vdy/project.pj
  CHANGE:           Revision 1.39.2.1 2018/07/25 11:48:51CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           VDY mearged code for ARS and MFC : Mainstream
  CHANGE:           Revision 1.39 2017/02/27 08:53:25CET Berwal, Anuj (uidp1444) 
  CHANGE:           -Included changes from Rev. 1.34.1.2 & 1.34.1.1
  CHANGE:           -Removed changes from Rev. 1.38 since it is not configured with Switch and throwing compilation error
  CHANGE:           Revision 1.38 2016/12/09 09:14:18CET Jahagirdar-EXT, Jayashree (uidr4458) 
  CHANGE:           1. Adaptation to new external file in custom folder
  CHANGE:           2. Adaptation to new BaseCtrlData_t request port
  CHANGE:           Revision 1.37 2016/05/12 14:49:44CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           Small Fix-
  CHANGE:           NVM State of lateral accel should be valid only during new learning
  CHANGE:           Revision 1.36 2016/05/02 12:26:35CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           same fix of RO 450018 is done in MFC430TA27 010B project.
  CHANGE:           But by using #ifndef macro so that other projects will not affect.
  CHANGE:           Revision 1.35 2016/04/21 13:37:57CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           Long Accel threshold SWA_FAST_OFFS_LONG_ACC_MAX for fast offset learnig is kept under #ifndef macro.
  CHANGE:           As per requested by toyata.
  CHANGE:           Revision 1.34 2016/03/11 07:23:06CET Singh, Sanjiv (uidr1340) 
  CHANGE:           =>> set conditions for AY_SET_ERR_OFFS_RG was wrong.
  CHANGE:           Swapped and corrected in this changepackage.
  CHANGE:           Revision 1.33 2016/02/22 12:49:03CET Singh, Sanjiv (uidr1340) 
  CHANGE:           QAC fixes
  CHANGE:           Revision 1.32 2016/02/19 14:03:19CET Singh, Sanjiv (uidr1340) 
  CHANGE:           adding and enabling of new the DEM(VDY_NVM_LEARN_DATA_ERROR)events logic:with new switch CFG_VDY_NVM_LEARN_DATA_ERROR.
  CHANGE:           with a small bugfix
  CHANGE:           Revision 1.31 2016/02/19 07:35:15CET Singh, Sanjiv (uidr1340) 
  CHANGE:           adding and enabling of new the DEM(VDY_NVM_LEARN_DATA_ERROR)events logic:with new switch CFG_VDY_NVM_LEARN_DATA_ERROR.
  CHANGE:           Revision 1.30 2016/02/04 09:53:09CET Mani, Yugesh (uidj6870) 
  CHANGE:           - integrated the MFC NVM issue changes with Switch disabled
  CHANGE:           Revision 1.29 2016/02/03 13:43:52CET Singh, Sanjiv (uidr1340) 
  CHANGE:           small module test finding fix from
  CHANGE:           Code_Review_Report_VDY_AL_MFC4T0_560A_03.06.00_INT16.xlsx
  CHANGE:           Revision 1.28 2016/01/08 16:42:54CET Singh, Sanjiv (uidr1340) 
  CHANGE:           Handling NVM cleared or Reset for Camera projects (MDB)
  CHANGE:           Revision 1.27 2016/01/05 15:44:55CET Singh, Sanjiv (uidr1340) 
  CHANGE:           writes NVM data  in every vdy cycle to the provide port for  camera(MDB) projects for steering wheel angle  Ay  offset
  CHANGE:           Revision 1.26 2015/12/24 08:24:44CET Singh, Sanjiv (uidr1340) 
  CHANGE:           Fix for writing in NVM for swa offset at every 20ms(for camera projects MDB) in init mode. Issue 404315
  CHANGE:           Revision 1.25 2015/12/22 09:42:29CET Singh, Sanjiv (uidr1340) 
  CHANGE:           Fix for writing in NVM for swa offset at every 20ms(for camera projects MDB).
  CHANGE:           Issue 404315
  CHANGE:           Revision 1.24 2015/07/30 14:08:17CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           QAC fic included in main branch - 1.23
  CHANGE:           - Added comments -  uidr1340 [Jul 30, 2015 2:08:18 PM CEST]
  CHANGE:           Change Package : 335155:2 http://mks-psad:7002/im/viewissue?selection=335155
  CHANGE:           Revision 1.23 2015/06/26 12:19:23CEST Mani, Yugesh (uidj6870) 
  CHANGE:           1.Removed the VALID/INVALID check before reading the SWA NVM data by using the config switch
  CHANGE:           2.Setting the SWA offset to default values when the NVM state is 0xFFFFFFFF
  CHANGE:           --- Added comments ---  uidj6870 [Jun 26, 2015 12:19:23 PM CEST]
  CHANGE:           Change Package : 338984:1 http://mks-psad:7002/im/viewissue?selection=338984
  CHANGE:           Revision 1.22 2015/04/16 09:26:02CEST Mani, Yugesh (uidj6870) 
  CHANGE:           fix for division by zero in vdy_ay_swa.c file
  CHANGE:           --- Added comments ---  uidj6870 [Apr 16, 2015 9:26:03 AM CEST]
  CHANGE:           Change Package : 315664:1 http://mks-psad:7002/im/viewissue?selection=315664
  CHANGE:           Revision 1.21 2014/12/03 10:52:26CET Balachandra, Swathi (uidj2447) 
  CHANGE:           Fix for MISRA VIOLATIONS
  CHANGE:           --- Added comments ---  uidj2447 [Dec 3, 2014 10:52:27 AM CET]
  CHANGE:           Change Package : 278585:1 http://mks-psad:7002/im/viewissue?selection=278585
  CHANGE:           Revision 1.20 2014/09/17 16:27:06CEST Wolter, Frank (wolterf) 
  CHANGE:           - first steering wheel offset estimation sets state directly to state 1
  CHANGE:           - changed limits for fast steering angle offset estimation
  CHANGE:           - reduced assumed deviation values for steering angle and lateral acceleration offset states
  CHANGE:           - accepted difference for state increase between old and new offset reduced to 0.5deg
  CHANGE:           --- Added comments ---  wolterf [Sep 17, 2014 4:27:08 PM CEST]
  CHANGE:           Change Package : 264924:1 http://mks-psad:7002/im/viewissue?selection=264924
  CHANGE:           Revision 1.19 2014/07/24 08:41:42CEST Wolter, Frank (wolterf) 
  CHANGE:           - steering wheel offset distances can be set in custom config
  CHANGE:           - better integration of steering wheel offset estimation
  CHANGE:           --- Added comments ---  wolterf [Jul 24, 2014 8:41:43 AM CEST]
  CHANGE:           Change Package : 247013:1 http://mks-psad:7002/im/viewissue?selection=247013
  CHANGE:           Revision 1.18 2014/07/10 12:17:52CEST Wolter, Frank (wolterf) 
  CHANGE:           - fast steering angle offset only stored is no offset is in NVM
  CHANGE:           --- Added comments ---  wolterf [Jul 10, 2014 12:17:52 PM CEST]
  CHANGE:           Change Package : 247013:1 http://mks-psad:7002/im/viewissue?selection=247013
  CHANGE:           Revision 1.17 2014/07/08 12:45:14CEST Wolter, Frank (wolterf) 
  CHANGE:           - calculating steering wheel offset from yaw rate differences if no offset is available (as in new cars)
  CHANGE:           - removed MISRA violations
  CHANGE:           --- Added comments ---  wolterf [Jul 8, 2014 12:45:15 PM CEST]
  CHANGE:           Change Package : 247013:1 http://mks-psad:7002/im/viewissue?selection=247013
  CHANGE:           Revision 1.16 2014/06/18 16:07:40CEST Wolter, Frank (wolterf) 
  CHANGE:           - input signal states in VDYAySwaAcqEstData available if lateral acceleration is configured
  CHANGE:           - description updates
  CHANGE:           --- Added comments ---  wolterf [Jun 18, 2014 4:07:41 PM CEST]
  CHANGE:           Change Package : 243308:1 http://mks-psad:7002/im/viewissue?selection=243308
  CHANGE:           Revision 1.15 2014/04/08 14:45:02CEST Wolter, Frank (wolterf) 
  CHANGE:           - doxygen function header
  CHANGE:           - removed MISRA violations
  CHANGE:           --- Added comments ---  wolterf [Apr 8, 2014 2:45:02 PM CEST]
  CHANGE:           Change Package : 229561:1 http://mks-psad:7002/im/viewissue?selection=229561
  CHANGE:           Revision 1.14 2014/03/07 09:26:59CET Wolter, Frank (wolterf) 
  CHANGE:           - removed QAC warnings
  CHANGE:           - removed non-Autosar types
  CHANGE:           --- Added comments ---  wolterf [Mar 7, 2014 9:26:59 AM CET]
  CHANGE:           Change Package : 223834:1 http://mks-psad:7002/im/viewissue?selection=223834
  CHANGE:           Revision 1.13 2014/02/07 12:54:59CET Wolter, Frank (wolterf) 
  CHANGE:           - use of NVM state macros
  CHANGE:           - removed compiler warning
  CHANGE:           --- Added comments ---  wolterf [Feb 7, 2014 12:55:00 PM CET]
  CHANGE:           Change Package : 217717:1 http://mks-psad:7002/im/viewissue?selection=217717
  CHANGE:           Revision 1.12 2013/12/06 14:39:12CET Wolter, Frank (wolterf) 
  CHANGE:           - no use of wheelspeeds if wheel speeds are diabled
  CHANGE:           - first calculated offset value is taken directly
  CHANGE:           --- Added comments ---  wolterf [Dec 6, 2013 2:39:13 PM CET]
  CHANGE:           Change Package : 205645:1 http://mks-psad:7002/im/viewissue?selection=205645
  CHANGE:           Revision 1.11 2013/09/25 15:00:47CEST Wolter, Frank (wolterf) 
  CHANGE:           - update code review by ICT
  CHANGE:           - implemented QAC MISRA findings
  CHANGE:           - switched to Autosar types
  CHANGE:           - grammar/spelling corrections
  CHANGE:           --- Added comments ---  wolterf [Sep 25, 2013 3:00:48 PM CEST]
  CHANGE:           Change Package : 198819:1 http://mks-psad:7002/im/viewissue?selection=198819
  CHANGE:           Revision 1.10 2011/08/23 09:41:43CEST Spruck, Jochen (spruckj) 
  CHANGE:           Remove some small misra/lint issues
  CHANGE:           --- Added comments ---  spruckj [Aug 23, 2011 9:41:44 AM CEST]
  CHANGE:           Change Package : 46866:16 http://mks-psad:7002/im/viewissue?selection=46866
  CHANGE:           Revision 1.9 2011/08/03 09:59:08CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGE:           Add memory sections definition to the vdy code
  CHANGE:           --- Added comments ---  spruckj [Aug 3, 2011 9:59:09 AM CEST]
  CHANGE:           Change Package : 74444:1 http://mks-psad:7002/im/viewissue?selection=74444
  CHANGE:           Revision 1.8 2010/11/12 12:11:59CET Spruck Jochen (spruckj) (spruckj) 
  CHANGE:           Remove misra and lint issues
  CHANGE:           Add review tags
  CHANGE:           --- Added comments ---  spruckj [Nov 12, 2010 12:12:00 PM CET]
  CHANGE:           Change Package : 54840:1 http://mks-psad:7002/im/viewissue?selection=54840
  CHANGE:           Revision 1.7 2010/10/13 14:12:51CEST Jochen Spruck (spruckj) 
  CHANGE:           fix Misra/Lint Issues
  CHANGE:           --- Added comments ---  spruckj [Oct 13, 2010 2:12:51 PM CEST]
  CHANGE:           Change Package : 52020:1 http://mks-psad:7002/im/viewissue?selection=52020
  CHANGE:           Revision 1.6 2010/06/17 10:50:26CEST jspruck 
  CHANGE:           move external interfaces from vdy_ext.h to rte
  CHANGE:           move external interface freez from internal to the adapter
  CHANGE:           --- Added comments ---  jspruck [2010/06/17 08:50:27Z]
  CHANGE:           Change Package : 42829:1 http://LISS014:6001/im/viewissue?selection=42829
  CHANGE:           Revision 1.5 2010/05/19 12:56:48CEST Jochen Spruck (jspruck) 
  CHANGE:           Update VDY to version 03.00.03
  CHANGE:           - remove some memcpy's and use insead direct access to the reqPort
  CHANGE:           - Update to new interface of the ALNYawRate
  CHANGE:           --- Added comments ---  jspruck [2010/05/19 10:56:48Z]
  CHANGE:           Change Package : 43263:1 http://LISS014:6001/im/viewissue?selection=43263
  CHANGE:           Revision 1.4 2010/03/26 12:23:18CET Jochen Spruck (jspruck) 
  CHANGE:           Change Function doxygen comment fn to Functionname
  CHANGE:           --- Added comments ---  jspruck [2010/03/26 11:23:19Z]
  CHANGE:           Change Package : 31184:2 http://LISS014:6001/im/viewissue?selection=31184
  CHANGE:           Revision 1.3 2010/03/11 09:11:06CET Jochen Spruck (jspruck) 
  CHANGE:           Move vdy io state macros and bitmasks to the algo_glob.h
  CHANGE:           --- Added comments ---  jspruck [2010/03/11 08:11:06Z]
  CHANGE:           Change Package : 31184:2 http://LISS014:6001/im/viewissue?selection=31184
  CHANGE:           Revision 1.2 2009/12/17 14:43:47CET Jochen Spruck (jspruck) 
  CHANGE:           - Update vdy to use rte types
  CHANGE:           - add mon component
  CHANGE:           - restuct vdy_main.c
  CHANGE:           --- Added comments ---  jspruck [2009/12/17 13:43:47Z]
  CHANGE:           Change Package : 31184:2 http://LISS014:6001/im/viewissue?selection=31184
  CHANGE:           Revision 1.1 2009/09/17 17:00:54CEST Jochen Spruck (jspruck) 
  CHANGE:           Initial revision
  CHANGE:           Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/VDY_VehicleDynamics/04_Engineering/01_Source_Code/algo/vdy/project.pj
  CHANGE:           Revision 1.18 2009/09/17 11:10:26CEST Jochen Spruck (jspruck) 
  CHANGE:           Remove misra/lint warnings
  CHANGE:           --- Added comments ---  jspruck [2009/09/17 09:10:26Z]
  CHANGE:           Change Package : 31102:1 http://LISS014:6001/im/viewissue?selection=31102
  CHANGE:           Revision 1.17 2009/04/27 09:44:43CEST Jochen Spruck (jspruck) 
  CHANGE:           Fixing of lint/MISRA warnings
  CHANGE:           --- Added comments ---  jspruck [2009/04/27 07:44:43Z]
  CHANGE:           Change Package : 25965:1 http://LISS014:6001/im/viewissue?selection=25965
  CHANGE:           Revision 1.16 2009/03/24 12:04:52CET mhinn 
  CHANGE:           added cycleid: vdy_cycle_id
  CHANGE:           --- Added comments ---  mhinn [2009/03/24 11:04:52Z]
  CHANGE:           Change Package : 24435:1 http://LISS014:6001/im/viewissue?selection=24435
  CHANGE:           Revision 1.15 2009/03/10 11:55:55CET Jochen Spruck (jspruck) 
  CHANGE:           Change error type of ay offset from Learand to NVM
  CHANGE:           --- Added comments ---  jspruck [2009/03/10 10:55:55Z]
  CHANGE:           Change Package : 23593:1 http://LISS014:6001/im/viewissue?selection=23593
  CHANGE:           Revision 1.14 2009/02/16 14:26:27CET Jochen Spruck (jspruck) 
  CHANGE:           Bug fix use ay errorflag for ay and not swa
  CHANGE:           --- Added comments ---  jspruck [2009/02/16 13:26:27Z]
  CHANGE:           Change Package : 22592:1 http://LISS014:6001/im/viewissue?selection=22592
  CHANGE:           Revision 1.13 2009/02/11 14:40:48CET Jochen Spruck (jspruck) 
  CHANGE:           Change to Matlab 2008b
  CHANGE:           --- Added comments ---  jspruck [2009/02/11 13:40:48Z]
  CHANGE:           Change Package : 22263:1 http://LISS014:6001/im/viewissue?selection=22263
  CHANGE:           Revision 1.12 2008/08/01 14:47:46CEST Jochen Spruck (jspruck) 
  CHANGE:           Use define of parameter instead of direct access to variable
  CHANGE:           --- Added comments ---  jspruck [2008/08/01 12:47:47Z]
  CHANGE:           Change Package : 13351:3 http://LISS014:6001/im/viewissue?selection=13351
  CHANGE:           Revision 1.11 2008/05/15 09:08:50CEST tdiepolder 
  CHANGE:           PDO "allow" vdy_pub and vdy_priv inserted
  CHANGE:           --- Added comments ---  tdiepolder [2008/05/15 07:08:50Z]
  CHANGE:           Change Package : 12863:1 http://liss014:6001/im/viewissue?selection=12863
  CHANGE:           Revision 1.10 2008/04/18 15:33:57CEST tdiepolder 
  CHANGE:           * Extension of offset learning regarding steering pattern of vehicle with higher CoG 
  CHANGE:           * Sharpened oval circular driving pattern recognization to avoid wrong calibraiton 
  CHANGE:           --- Added comments ---  tdiepolder [2008/04/18 13:33:58Z]
  CHANGE:           Change Package : 11029:5 http://liss014:6001/im/viewissue?selection=11029
  CHANGE:           Revision 1.9 2008/04/10 13:38:55CEST tdiepolder 
  CHANGE:           Allow more take overs during one ignition cycle
  CHANGE:           --- Added comments ---  tdiepolder [2008/04/10 11:38:55Z]
  CHANGE:           Change Package : 11029:5 http://liss014:6001/im/viewissue?selection=11029
  CHANGE:           Revision 1.8 2008/03/27 15:01:59CET jspruck 
  CHANGE:           Remove a // comment
  CHANGE:           --- Added comments ---  jspruck [2008/03/27 14:01:59Z]
  CHANGE:           Change Package : 11020:1 http://liss014:6001/im/viewissue?selection=11020
  CHANGE:           Revision 1.7 2008/03/26 16:54:35CET jspruck 
  CHANGE:           Add DEM event if swa offset histo is out of range 3 times
  CHANGE:           --- Added comments ---  jspruck [2008/03/26 15:54:35Z]
  CHANGE:           Change Package : 11020:1 http://liss014:6001/im/viewissue?selection=11020
  CHANGE:           Revision 1.6 2008/03/25 09:49:47CET jspruck 
  CHANGE:           Use the calibration flag, to switch of learn values wld, ssg and dyn yaw offset
  CHANGE:           --- Added comments ---  jspruck [2008/03/25 08:49:47Z]
  CHANGE:           Change Package : 11024:1 http://liss014:6001/im/viewissue?selection=11024
  CHANGE:           Revision 1.5 2008/03/19 17:42:05CET jspruck 
  CHANGE:           Modification to use the operation modes startup, init and running
  CHANGE:           --- Added comments ---  jspruck [2008/03/19 16:42:05Z]
  CHANGE:           Change Package : 11026:1 http://liss014:6001/im/viewissue?selection=11026
  CHANGE:           Revision 1.4 2007/10/31 17:26:19CET tdiepolder 
  CHANGE:           Extension of vehicle velocity correction
  CHANGE:           --- Added comments ---  tdiepolder [2007/10/31 16:26:19Z]
  CHANGE:           Change Package : 3172:1 http://liss014:6001/im/viewissue?selection=3172
  CHANGE:           Revision 1.3 2007/08/30 15:17:32CEST tdiepolder 
  CHANGE:           export lateral acceleration and steering wheel angle offset
  CHANGE:           --- Added comments ---  tdiepolder [2007/08/30 13:17:33Z]
  CHANGE:           Change Package : 3167:1 http://liss014:6001/im/viewissue?selection=3167
  CHANGE:           Revision 1.2 2007/08/21 17:02:35CEST tdiepolder 
  CHANGE:           nvm steering wheel anlge and lateral sensor offset state test corrected
  CHANGE:           interims lateral offset during learned swa offset state improved
  CHANGE:           --- Added comments ---  tdiepolder [2007/08/21 15:02:35Z]
  CHANGE:           Change Package : 3167:1 http://liss014:6001/im/viewissue?selection=3167

*****************************************************************************/
/* PRQA S 489,491 EOF */ 
/* date: Unknown, reviewer: Suggested TCI Code Review, reason: It is legacy code of ARS301 , alreay reviewed and working fine without any critical issue
 also pointer aritmetic saves runtime " */

/* PRQA S 7013 EOF */
/* date: Unknown, reviewer: Suggested TCI Code Review, reason: Legacy code of ARS301, reducing lines of code changes component structure." */

/* PRQA S 3447 EOF */
/* date: Unknown, reviewer: Suggested TCI Code Review, reason: Legacy code of ARS301,It is already declared in header file but cant recognise since it is under MACRO condition  " */

/* PRQA S 3112 EOF */
/* date: Unknown, reviewer: Suggested TCI Code Review, reason: reqPorts and proPorts are added to remove compiler warning, they are not used in this configuration  " */


/* QAC Level 2 Warning Suppression */
/* PRQA S 1532, 1534, 3227, 2211, 3469, 4330, 3678, 3212, 2981 EOF */
/* date: 2019-06-10, reviewer: Yogesh Ghongade (uidj8380), reason: No Risk */

/* PRQA S 2755, 2991, 2995 EOF */
/* date: 2019-12-30, reviewer: Ramachandra Chinnaswamy (uids4735), reason: Fucntional Safe and intended */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
/* PRQA S 0380 EOF */
/* date: 2019-06-10, reviewer: Yogesh Ghongade (uidj8380), reason: No Risk */
#include "vdy.h"


/*****************************************************************************
  SYMBOLIC CONSTANTS
*****************************************************************************/

/* SWA offset range values */
/// Default value for uncalibrated swa offset
#define SWA_ANG_OFFS_DEFAULT          (0.0F)
/// Bin width for steering wheel angle histogram
#define SWA_OFFSET_HIST_WIDTH         (DEG2RAD(1.95F))
/// Maximum absolute deviation at run-up to come to next higher offset state
#define SWA_OFFS_STAT_DIFF_RUN_UP     (DEG2RAD(1.5F))
/// Hysteresis at learned offset for restoring
#define SWA_OFFS_CHANGE_HYST          (DEG2RAD(0.5F))
/// Scaling of steering wheel angle offset
#define SWA_OFFS_NORM_RES             (DEG2RAD(0.5F))
/// Standard deviation NVM value
#define SWA_OFFS_DEV_NORMAL           (0.0F)
/// Reduction factor histogram counts
#define SWA_INTERVAL_RDCT_FCTR        (0.5F)
/// Maximum accumulated distance in swa and ay histograms
#define SWA_OFFS_DRIVEN_DIST_MAX      (500.0F*1000.0F)

/*! Steering wheel angle offset states */

/// SWA offset state 0 non existent                   
#define SWA_STATE_DEFAULT             (0) 
/// SWA offset state 1 run-up
#define SWA_STATE_1                   (1) 
/// SWA offset state 2 run-up
#define SWA_STATE_2                   (2) 
/// SWA offset state 3 run-up
#define SWA_STATE_3                   (3) 
/// SWA offset state 4 learned but not confirmed yet
#define SWA_STATE_4                   (4) 
/// SWA offset state 5 learned and confirmed once
#define SWA_STATE_5                   (5) 
/// SWA offset state 6 learned and confirmed twice
#define SWA_STATE_6                   (6) 


/*! Distance thresholds for offset estimation in dependence of offset state */
#ifndef SWA_DIST_SAMP_STAT_DEFAULT
/// Sampled distance for estimation at state 0
#define SWA_DIST_SAMP_STAT_DEFAULT    (20000.F)
#endif
#ifndef SWA_DIST_SAMP_STAT_1
/// Sampled distance for estimation at state 1
#define SWA_DIST_SAMP_STAT_1          (25000.F)
#endif
#ifndef SWA_DIST_SAMP_STAT_2
/// Sampled distance for estimation at state 2
#define SWA_DIST_SAMP_STAT_2          (30000.F)
#endif
#ifndef SWA_DIST_SAMP_STAT_3
/// Sampled distance for estimation at state 3
#define SWA_DIST_SAMP_STAT_3          (35000.F)
#endif
#ifndef SWA_DIST_SAMP_STAT_4
/// Sampled distance for estimation at state 4
#define SWA_DIST_SAMP_STAT_4          (40000.F)
#endif
#ifndef SWA_DIST_SAMP_STAT_5
/// Sampled distance for estimation at state 5
#define SWA_DIST_SAMP_STAT_5          (40000.F)
#endif
#ifndef SWA_DIST_SAMP_STAT_6
/// Sampled distance for estimation at state 6
#define SWA_DIST_SAMP_STAT_6          (50000.F)
#endif

/*! Sample thresholds for offset estimation in dependence of offset state */

#ifndef SWA_FAST_OFFS_SAMP_1
/// Sample for 1st Fast Offset estimation at state 1
#define SWA_FAST_OFFS_SAMP_1          250U                      
#endif

#ifndef SWA_FAST_OFFS_SAMP_2
/// Sample for 2nd Fast Offset estimation at state 1
#define SWA_FAST_OFFS_SAMP_2          750U                      
#endif

#ifndef SWA_FAST_OFFS_SAMP_3
/// Sample for 3rd Fast Offset estimation at state 1
#define SWA_FAST_OFFS_SAMP_3          1750U                     
#endif

#ifndef SWA_FAST_OFFS_SAMP_4
/// Sample for 4th Fast Offset estimation at state 1
#define SWA_FAST_OFFS_SAMP_4          3250U                     
#endif

#ifndef SWA_FAST_OFFS_SAMP_5
/// Sample for 5th Fast Offset estimation at state 1
#define SWA_FAST_OFFS_SAMP_5          5250U                     
#endif

#ifndef SWA_FAST_OFFS_SAMP_6
/// Sample for 6th Fast Offset estimation at state 1
#define SWA_FAST_OFFS_SAMP_6          10250U                    
#endif

#ifndef SWA_FAST_OFFS_SAMP_7
/// Sample for 7th Fast Offset estimation at state 1
#define SWA_FAST_OFFS_SAMP_7          15250U                    
#endif

#ifndef SWA_FAST_OFFS_SAMP_8
/// Sample for 8th Fast Offset estimation at state 1
#define SWA_FAST_OFFS_SAMP_8          18250U                    
#endif

#ifndef SWA_FAST_OFFS_SAMP_9
/// Sample for 9th Fast Offset estimation at state 1
#define SWA_FAST_OFFS_SAMP_9          19750U                    
#endif



/*! Steering wheel angle offset standard deviations */
/// SWA offset standard deviation state 0   
#define SWA_STATE_0_DEV           (DEG2RAD(12.0F/3.0F))
/// SWA offset standard deviation state 1
#define SWA_STATE_1_DEV           (DEG2RAD(4.0F/3.0F))
/// SWA offset standard deviation state 2
#define SWA_STATE_2_DEV           (DEG2RAD(3.0F/3.0F))
/// SWA offset standard deviation state 3
#define SWA_STATE_3_DEV           (DEG2RAD(2.0F/3.0F))
/// SWA offset standard deviation state 4
#define SWA_STATE_4_DEV           (DEG2RAD(1.0F/3.0F))
/// SWA offset standard deviation state 5
#define SWA_STATE_5_DEV           (DEG2RAD(0.5F/3.0F))
/// SWA offset standard deviation state 6
#define SWA_STATE_6_DEV           (DEG2RAD(0.5F/3.0F))

/*! Standard deviations for steering wheel angle offset estimation */

/// Default standard deviation for offset estimation
#define SWA_DEV_HIST_STAT_DEFAULT     (DEG2RAD(1.0F))
/// Standard deviation for offset estimation during startup phase
#define SWA_DEV_HIST_STAT_STARTUP     (DEG2RAD(1.0F))
/// Standard deviation for offset estimation during confirmation phase
#define SWA_DEV_HIST_STAT_NORMAL      (DEG2RAD(0.5F))

/*! Confidence levels for estimated steering wheel angle offsets */

/// Maximum confidence level  
#define AY_SWA_OFFS_MAX_CONF          (1.0F)
/// Medium  confidence level  
#define AY_SWA_OFFS_MID_CONF          (0.5F)
/// Low confidence level      
#define AY_SWA_OFFS_LOW_CONF          (0.2F)
/// No confidence level       
#define AY_SWA_OFFS_NO_CONF           (0.0F)

/*! Thesholds for offset takeover */

/// Range gap between maximum and mean                                 
#define SWA_OFFS_DIFF_MAX_MEAN       (DEG2RAD(1.0F))
/// Range gap between central mean for median usage                    
#define SWA_OFFS_DIFF_MEAN_CT_MED    (DEG2RAD(1.5F))
/// Range gap between mean and median for median usage                 
#define SWA_OFFS_DIFF_MEAN_MED       (DEG2RAD(1.0F))
/// Range gap between maximum and median for median usage              
#define SWA_OFFS_DIFF_MAX_MED        (DEG2RAD(2.5F))
/// Counted distance gap between maximum and neighbour bins            
#define SWA_OFFS_FTHR_DIST_MAX_ADJ   (0.5F)
/// Counted distance gap between maximum and secondary bin             
#define SWA_OFFS_FTHR_DIST_MAX_OUT   (0.2F)
/// Maximum number of takeovers during one ignition cycle              
#define SWA_OFFS_TAKE_OVR_MAX        (10U)
/// Counted distance gap between maximum and mean for median  
#define SWA_OFFS_FTHR_DIST_MAX_MEAN  (0.1F)

/*! Limits for steering wheel angle offset estimation */

/// Minimum veloctiy for steering wheel angle offset calibration        
#define SWA_OFFS_VEL_MIN             (10.F)
/// Maximum allowed steering wheel angle for offset estimation          
#define SWA_OFFS_ANGLE_MAX           (DEG2RAD(30.F))

#ifndef SWA_OFFS_ANGLE_FAST_OFF_MAX
/// Maximum allowed steering wheel angle for fast offset learning estimation      
#define SWA_OFFS_ANGLE_FAST_OFF_MAX  (DEG2RAD(30.F))   
#endif

/// Maximum allowed averaged lateral accleration for offset estimation  
#define SWA_OFFS_LAT_ACC_MAX         (1.8F)
/// Lateral acceleration average filter time constant                   
#define SWA_OFFS_LAT_ACC_FT          (60.F)
/// Wheel velocity difference filter time constant                      
#define SWA_OFFS_WHS_DIFF_FT         (6.F)
/// Maximum allowed wheel velocity differences for offset estimation    
#define SWA_OFFS_WHS_DIFF_VEL        (0.3F)

/*! Limits for fast steering wheel angle offset estimation */
#ifndef SWA_FAST_OFFS_WHS_DIFF_VEL
/// Maximum allowed wheel velocity differences for fast offset estimation       
#define SWA_FAST_OFFS_WHS_DIFF_VEL        (0.6F)   
#endif
#ifndef SWA_FAST_OFFS_LONG_ACC_MAX
/// Maximum allowed longitudinal acceleration for fast offset estimation        
#define SWA_FAST_OFFS_LONG_ACC_MAX        (0.5F)   
#endif
/// Minimum veloctiy for fast steering wheel angle offset estimation
#define SWA_FAST_OFFS_VEL_MIN             (5.0F)
/// Number of samples used for mean calculation in fast offset estimation
#define SWA_FAST_OFFS_SAMPLE_LIMIT        (250U)
/// Number of samples used for long term calculation in fast offset estimation
#define SWA_FAST_OFFS_SAMPLE_LIMIT_LT     (500U)

/*! Lateral acceleration sensor offset values */

/// Default value for uncalibrated swa offset
#define AY_OFFS_DEFAULT              (0.0F)
/// Range(+/-) where offset correction is conducted
#define AY_OFFSET_LIMIT_MAX          (1.2F)
/// Range(+/-) where swa offset data is added to histogram
#define AY_SWA_LIMIT_HIST            (5.0F)


/*! Lateral acceleration sensor offset states */

/// Ay offset state 0 non existent
#define AY_STATE_DEFAULT             (0)
/// Ay offset state 1 run-up
#define AY_STATE_1                   (1)
/// Ay offset state 2 run-up
#define AY_STATE_2                   (2)
/// Ay offset state 3 learn and relearn
#define AY_STATE_3                   (3)


/*! Distance thresholds for lateral acceleration offset estimation in depedence of offset state */

/// Sampled distance for estimation at state 0
#define AY_DIST_SAMP_STAT_DEFAULT    (20000.F)
/// Sampled distance for estimation at state 1
#define AY_DIST_SAMP_STAT_1          (25000.F)
/// Sampled distance for estimation at state 2  
#define AY_DIST_SAMP_STAT_2          (30000.F)
/// Sampled distance for estimation at state 3
#define AY_DIST_SAMP_STAT_3          (30000.F)


/*! Lateral acceleration offset standard deviations */

/// Lateral accleration offset standard deviation state 0
#define AY_STATE_0_DEV               (1.0F/3.0F)
/// Lateral accleration offset standard deviation state 1
#define AY_STATE_1_DEV               (0.3F/3.0F)
/// Lateral accleration offset standard deviation state 2
#define AY_STATE_2_DEV               (0.1F/3.0F)
/// Lateral accleration offset standard deviation state 3
#define AY_STATE_3_DEV               (0.07F/3.0F)


/*! Standard deviations for lateral acceleration offset estimation */

/// Default standard deviation for offset estimation
#define AY_DEV_SAMP_STAT_DEFAULT     (0.5F)
/// Standard deviation for offset estimation during startup phase
#define AY_DEV_SAMP_STAT_STARTUP     (0.5F)
/// Standard deviation for offset estimation during confirmation phase
#define AY_DEV_SAMP_STAT_NORMAL      (0.2F)
/// Maximum allowed difference for increasing state during learning phase
#define AY_OFFS_STAT_DIFF_RUN_UP     (0.7F)
/// Maximum allowed difference for increasing state during confirmation phase
#define AY_OFFS_STAT_DIFF_LEARNED    (0.5F)
/// Maximum number of takeovers during one ignition cycle
#define AY_OFFS_TAKE_OVR_MAX         (3U)
/// Standard deviation NVM value  
#define AY_OFFS_DEV_NORMAL           (0.0F)
/// Range gap between maximum and mean
#define AY_OFFS_DIFF_MAX_MEAN        (0.2F)
/// Range gap between maximum and median for median usage
#define AY_OFFS_DIFF_MAX_MED         (0.3F)
/// Range gap between maximum and mean for median usage  
#define AY_OFFS_DIFF_MEAN_MED        (0.2F)
/// Counted distance gap between maximum and neighbour bins
#define AY_OFFS_FTHR_DIST_MAX_ADJ    (0.5F)
/// Counted distance gap between maximum and secondary bin
#define AY_OFFS_FTHR_DIST_MAX_OUT    (0.2F)
/// Reduzierungsfaktor Sampleinterval
#define AY_INTERVAL_RDCT_FCTR        (0.4F)
/// Bin width for lateral acceleration offset estimation
#define AY_OFFSET_HIST_WIDTH         (0.25F)
/// SWA NVM Cleared Indicator
#define SWA_NVM_CLEARED              (0xFFFFFFFFU)


#ifndef SWA_BANK_ROAD_THRESH
/// Bank Road Threshold for Fast SWA offset
#define SWA_BANK_ROAD_THRESH         0.1F                
#endif

#ifndef SWA_OFFS_YAW_RATE_MAX
/// Max allowed Yaw Rate to take samples in Fast Steer Offset Second Stage
#define SWA_OFFS_YAW_RATE_MAX        (DEG2RAD(0.1146F))  
#endif

/*****************************************************************************
  MACROS
*****************************************************************************/

/// Access to VDY SWA global data
#define SWA_GET_ME                      (&VDYSwaGlobData) 

/// Access to VDY SWA global data iput signals
#define SWA_GET_INP_SIGNALS             (&VDYSwaGlobData.Io.in->Signals) 

/// Access to VDY internal intra module SWA
#define SWA_GET_MIF_DATA                (VDYSwaGlobData.Io.mif) 

/// SWA offset error range
#define SWA_GET_ERR_OFFS_RG             (*VDYSwaGlobData.Io.errOffsRg) 

/// SWA NVM offset error range
#define SWA_GET_NVM_ERR_OFFS_RG         (*VDYSwaGlobData.Io.NVMerrOffsRg) 

/* check for valid values written into NVM */
#if ( (defined(CFG_VDY_NVM_LEARN_DATA_ERROR)) && (CFG_VDY_NVM_LEARN_DATA_ERROR) )

/// Pointer to NVM Offset Error Range
#define SWA_SET_NVM_ERR_OFFS_RG         (*VDYSwaGlobData.Io.SwaNVMErrOffsRg)
#endif

/// Access to SWA sensror data
#define SWA_GET_SEN_DATA              (&VDYSwaGlobData.Sensor) 

/// Access to SWA offset data
#define SWA_GET_OFF_DATA              (&VDYSwaGlobData.Offset) 

/// Access to SWA NVM data
#define SWA_GET_NV_DATA               (&VDYSwaGlobData.NVValue) 

/// Access to VDY Lateral Acceleration global data
#define AY_GET_ME                     (&VDYAyGlobData) 

/// Access to VDY Lateral Acceleration global data iput signals
#define AY_GET_INP_SIGNALS            (&VDYAyGlobData.Io.in->Signals) 

/// Access to VDY Lateral Acceleration global NVM read data
#define AY_GET_NV_READ_DATA           (VDYAyGlobData.Io.nv_read) 

/// Access to VDY Lateral Acceleration global NVM read data
#define AY_GET_NV_WRITE_DATA          (VDYAyGlobData.Io.nv_write) 

/// Access to Lateral Acceleration sensror data
#define AY_GET_SEN_DATA               (&VDYAyGlobData.Sensor)  

/// Access to Lateral Acceleration offset data
#define AY_GET_OFF_DATA               (&VDYAyGlobData.Offset) 

/// Lateral Acceleration offset error range
#define AY_GET_ERR_OFFS_RG            (*VDYAyGlobData.Io.errOffsRg) 
#if ( (defined(CFG_VDY_NVM_LEARN_DATA_ERROR)) && (CFG_VDY_NVM_LEARN_DATA_ERROR) )
  /* check for valid values written into NVM */
#define AY_SET_ERR_OFFS_RG            (*VDYAyGlobData.Io.AyNVMerrOffsRg)
#endif


/*****************************************************************************
  TYPEDEFS
*****************************************************************************/


/*****************************************************************************
  CONSTS
*****************************************************************************/


/*****************************************************************************
  VARIABLES
*****************************************************************************/
SET_MEMSEC_VAR(VDYSwaGlobData)
STATIC_VAR VDYSwaData_t VDYSwaGlobData;	


SET_MEMSEC_VAR(VDYAyGlobData)
STATIC_VAR VDYAyData_t VDYAyGlobData;	


#if( (defined(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))&&(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))
SET_MEMSEC_VAR(LastSwaNvmData)								
STATIC_VAR VDYLastNvStWhlAngCal_t LastSwaNvmData; /// New structure for storing previous cycle steering offset of NVM
SET_MEMSEC_VAR(LastAyNvmData)								
STATIC_VAR VDYLastNvAyCal_t LastAyNvmData; /// New structure for storing previous cycle Ay offset of NVM
#endif


/*****************************************************************************
  LOCAL FUNCTION PROTOTYPES
*****************************************************************************/

/* **********************************************************************
  @fn                     vdySwaNvmReadOffset */ /*!
  @brief           Reads steering wheel offset from NVM

  @description     Updates RAM data if EEPromReadOk is not set

  @return          static void

  @param[in,out]   *NVValue : Steering wheel angle offset NVM read / write
  @param[in]       *nvin : Steering wheel angle zero point offset estimation
  @param[in]       status : Status

  @glob_in         
				  - SWA_ANG_OFFS_DEFAULT : Default value for uncalibrated swa offset
				  - SWA_STATE_DEFAULT : SWA offset state 0 non existent
  @glob_out        None

  @c_switch_part   None
  @c_switch_full   None

  @pre             None
  @post            No changes
  @InOutCorrelation
					  when EEPromReadOk is FALSE
							- If NVM is crashed/Erased
									- Set the offset and state to Default Values 
							- If Not
									- Upload data from nvmemory
							- Store the Read NVM value as the initial value of Last NVM value
							- Set EEPromReadOk to TRUE
  
							@startuml
								start
									if (NVValue->EEPromReadOk == (boolean)FALSE) then (YES)
										if(status == SWA_NVM_CLEARED) then (YES)
												:Set the offset and state to Default Values since NVM is crashed/Erased;
										else (No)
												:Upload data from nvmemory;
										endif
								 		:store the Read NVM value as the initial value of Last NVM value;
										:Set EEPromReadOk to TRUE;								 
									endif
								stop
								@enduml
  @testmethod
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c -> TEST_vdySwaNvmReadOffset_001(), TEST_vdySwaNvmReadOffset_002(), TEST_vdySwaNvmReadOffset_003()
  @traceability
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1029-00026448
**************************************************************************** */
STATIC_MTD void vdySwaNvmReadOffset(VDYSwaOffsEEprom_t *NVValue, const VDYNvStWhlAngCal_t *nvin, uint32 status);


/* **********************************************************************
  @fn                     vdySwaNvmWriteOffset */ /*!
  @brief           Writes steering wheel offset in NVM

  @description     Updates NVM data if EEPromWriteRequest is set

  @return          static VDYIoState_t

  @param[in,out]   *NVValue : Steering wheel angle offset NVM read / write 
  @param[in,out]   *nvout : Steering wheel angle zero point offset estimation

  @glob_in         
				  - VDY_IO_STATE_INVALID : invalid vdy io states
				  - VDY_IO_STATE_VALID : valid vdy io states
  @glob_out        None

  @c_switch_part   None
  @c_switch_full   None

  @pre             None
  @post            No changes
  @InOutCorrelation 
					- Stores the New SWA Offset value in the NVM Variable to update for every VDY cycle
  
					@startuml
								start
									:State = VDY_IO_STATE_INVALID;
									if(NVValue->EEPromWriteRequ == (boolean)TRUE) then (YES)
										if(check for valid values written into NVM) then (YES)
												:Copy req port NVM offset and status to Swa NVM offset and status respectively ;
												:Storing the New Offset value in the Variable to update for every VDY cycle ;
												:State = VDY_IO_STATE_VALID;
												:NVValue->EEPromWriteRequ =(boolean)FALSE;
												:SWA_SET_NVM_ERR_OFFS_RG = (VDY_ERR_STATE_INACTIVE);
										else (NO)
												:SWA_SET_NVM_ERR_OFFS_RG = (VDY_ERR_STATE_ACTIVE);
										endif
									else (NO)
										:nvout->ZeroAngle = LastSwaNvmData.ZeroAngle;
										:nvout->CalStatus = LastSwaNvmData.CalStatus;
									endif
								stop
						@enduml

  @testmethod
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c -> \n
                            TEST_vdySwaNvmWriteOffset_001(),
                            TEST_vdySwaNvmWriteOffset_002(),
                            TEST_vdySwaNvmWriteOffset_003(),
                            TEST_vdySwaNvmWriteOffset_004()
  @traceability
  - L3
    - doors://RBGS854A:40000/?version=2&prodID=0&view=000000cd&urn=urn:telelogic::1-503e822e5ec3651e-O-1802-000221c8 
    - doors://RBGS854A:40000/?version=2&prodID=0&view=000000cd&urn=urn:telelogic::1-503e822e5ec3651e-O-288-000221c8 
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-791-00026448
**************************************************************************** */
STATIC_MTD VDYIoState_t vdySwaNvmWriteOffset(VDYSwaOffsEEprom_t  *NVValue, VDYNvStWhlAngCal_t *nvout);


/* **********************************************************************
  @fn                     vdySwaTakeoverOffset */ /*!
  @brief           Take estimated steering wheel offset as active offset

  @description     Calculates the new offset value based on value difference
                   and learning state
                   Increases or decreases leraning state according to difference
                   and reduces the measurement data

  @return          static void

  @param[in,out]   *StrgOffsData : Steering wheel angle offset data
  @param[in,out]   *OffsEst : Steering wheel angle offset calibration 

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None 
  @post            No changes 
  @InOutCorrelation
					  - Calculate difference between active and new estimated offset
					  - If No active offset available (the estimated offset is the first calculated offset) then Use estimated offset as first offset, no appoximation with active offset (no active offset available)
					  - Otherwise Calculate average between active and estimated offset for successive approximation of final offset
					  - Normalize offset value
					  - Acquisition strategy is dependent on current state
							- For L E A R N   P H A S E , SWA_STATE_DEFAULT (0), SWA_STATE_1 (1), SWA_STATE_2 (2) and SWA_STATE_3 (3)
									- When offset value is stable or it is the first offset, increment state
									- Take over offset and deviation
									- Save offset value and status in nonvolatile memory
									- Initialize estimation data
							- For R E L E A R N   P H A S E, SWA_STATE_4 (4)
									- Test offset against stability
											- If Estimated offset differs significantly from active offset: restore learned offset value
											- Remain in this offset calibration state
											- Take over offset and deviation
											- Initialize estimation data
									- Otherwise, If Estimated offset approves active and stored offset
											- Increment offset state
											- Take over offset
											- Indicate that offset value has been confirmed during this ignition cylce, i.e., one confirmation per ignition cylce i.e., hold offset state in next state for this ignition cycle
											- Scale back estimation data
											- Save offset value and status in nonvolatile memory
							- For C O N F I R M A T I O N   P H A S E, SWA_STATE_5 (5) and SWA_STATE_6 (6)
									- If Estimated offset differs significantly form active offset: lower offset state without changing the offset value
											- Decrement offset state
											- Save offset state in nonvolatile memory
									- Otherwise, If Estimated offset approves active and stored offset
											- Offset state 5 has been reached since last ignition cycle, move to state 6
											- Take over offset
											- Save offset value and status in nonvolatile memory
									- Scale back estimation data
							- For other values
									- Set default state SWA_STATE_DEFAULT (0)
									- Initialize estimation data
  
						@startuml
									start
										: Take the absolute differences between active and new estimated swa offset
											SWA Offset Difference    = Estiamted SWA offset - Active SWA Offset
											Swa Offset Abs Diff = Abs(SWA Offset Difference);
										if (OffsState == SWA_STATE_DEFAULT) then (YES)
											:Use estimated offset as first offset, no appoximation with active offset (no active offset available)
												SWA Offset New = Estimated Offset;
										else (NO)
											:Calculate average between active and estimated offset for successive approximation of final offset
												SWA Offset New = active offset + (0.5 * SWA Offset Diff);
										endif
										:Normalize offset value;
										if((Offset State == SWA_STATE_DEFAULT) || (Offset State == SWA_STATE_1) || (Offset State == SWA_STATE_2)|| (Offset State == SWA_STATE_3)) then (YES)
													: When offset value is stable or it is the first offset, increment state;
													if (((SWA Offset Difference <= (DEG2RAD(1.5F))) || (Active SWA offset state  == SWA_STATE_DEFAULT)) && (Fast_Offset_State == 0U)) then (YES)
														:Increment the takeover counter 
															OvrTakeCntr++;
														if (OvrTakeCntr < 10) then (YES)
															:StrgOffsData->OffsState += 1;
														endif
													endif
													:Take over offset and deviation
														StrgOffsData->StrgOffset     = Swa Offset New
														StrgOffsData->StrgOffsetNorm = Swa Offset Normalize
														StrgOffsData->Dev            = Deviation at OffsState;
													:Save offset value and status in nonvolatile memory;
													if(OffsState > SWA_STATE_1) then (YES)
														:Initialize estimation data
															 HistReInit;
													endif
										else if (Offset State == SWA_STATE_4) then (YES)
													:R E L E A R N   P H A S E;
													if(Swa Offset Abs Diff >= (DEG2RAD(0.5F)) ) then (YES)
														:Remain in this offset calibration state
															Offset State      = SWA_STATE_4;
														: Take over offset 
														StrgOffsData->StrgOffset     = Swa Offset New
														StrgOffsData->Dev            = Deviation at OffsState
														StrgOffsData->StrgOffsetNorm = Swa Offset Norm;
														:Initialize estimation data
															Hist ReInit;
													else (NO)
														:Increment offset state
															OffsState  = SWA_STATE_5;
														: Take over offset 
														StrgOffsData->StrgOffset     = Swa Offset New
														StrgOffsData->Dev            = Deviation at OffsState
														StrgOffsData->StrgOffsetNorm = Swa Offset Norm;
														:OvrTakeCntr++;
														:Scale back estimation data
															Reduce histogram by 50%;
													endif
													:Save offset value and status in nonvolatile memory;
										else if ((Offset State == SWA_STATE_5) || (Offset State == SWA_STATE_6)) then (YES)
													:C O N F I R M A T I O N   P H A S E;
													if(Swa Offset Abs Diff >= (DEG2RAD(0.5F)) ) then (YES)
														:Offset State -= 1;
														: Save offset state in nonvolatile memory;
													else (NO)
																if ( (OvrTakeCntr == 0u)  && (Offset State < SWA_STATE_6)) then (YES)
																	:Offset State = SWA_STATE_6; 
																	:Take over offset
																			StrgOffsData->StrgOffset     = Swa Offset New
																			StrgOffsData->Dev            = Deviation at OffsState
																			StrgOffsData->StrgOffsetNorm = Swa Offset Norm;
																	:Save offset value and status in nonvolatile memory;
															endif
													endif
													:Scale back estimation data
														Reduce Histogram by 50%;
										else (default)
											:Set default state
												Offset State = SWA_STATE_DEFAULT;
											:Initialize estimation data
												HistReInit;
										endif
									stop
								@enduml

  @testmethod
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c -> \n
                            TEST_vdySwaTakeoverOffset_001(),
                            TEST_vdySwaTakeoverOffset_002(),
                            TEST_vdySwaTakeoverOffset_003(),
                            TEST_vdySwaTakeoverOffset_004(),
                            TEST_vdySwaTakeoverOffset_005(),
                            TEST_vdySwaTakeoverOffset_006(),
                            TEST_vdySwaTakeoverOffset_007(),
                            TEST_vdySwaTakeoverOffset_008(),
                            TEST_vdySwaTakeoverOffset_009(),
                            TEST_vdySwaTakeoverOffset_010(),
                            TEST_vdySwaTakeoverOffset_011(),
                            TEST_vdySwaTakeoverOffset_012(),
                            TEST_vdySwaTakeoverOffset_013()
  @traceability
  - L3
    - doors://rbgs854a:40000/?version=2&prodID=0&view=0000012f&urn=urn:telelogic::1-503e822e5ec3651e-O-288-000221c8
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-832-00026448
**************************************************************************** */
STATIC_MTD void vdySwaTakeoverOffset(VDYSwaOffsData_t *StrgOffsData, VDYSwaOffsEst_t *OffsEst);


/* ***********************************************************************
  @fn                     vdySwaInitVolatile */ /*!
  @brief           Initialization of volatile steering wheel angle data

  @description     Initialization of steering wheel angle Input/Output interface error states

  @return          static void

  @param[in,out]   *pSwaData :Steering wheel angle processing data structure  

  @c_switch_part   None
  @c_switch_full   None

  @pre             None
  @post            No changes
  @InOutCorrelation
					  - Initializes Swa Sensor Data
					  - Initializes Error States
  
						@startuml
								start
									:vdySwaInitSenData(&pSwaData->Sensor);
									:(void)memset(&pSwaData->FastSwaOffset, 0x00, sizeof(s_VDYFastSwaOffset_t));
									:pSwaData->Io.errOffsRg  = NULL;
									:pSwaData->Io.NVMerrOffsRg  = NULL;
									:pSwaData->Io.SwaNVMErrOffsRg  = NULL;
								stop
						@enduml

  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c -> TEST_vdySwaInitVolatile_001
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdySwaInitVolatile(VDYSwaData_t *pSwaData);


/* **********************************************************************
  @fn                     vdySwaInitOffsEepromMirror */ /*!
  @brief           Init NVM steering wheel offset mirror

  @description     Initialization NVM steering wheel angle offset

  @return          static void

  @param[in,out]   *NVValue : Steering wheel angle offset NVM read / write

  @glob_in         
				  - SWA_STATE_0_DEV : SWA offset standard deviation state 0    
				  - SWA_STATE_DEFAULT : SWA offset state 0 non existent
  @glob_out        None

  @c_switch_part   None
  @c_switch_full   None

  @pre             None
  @post            No changes

  @InOutCorrelation 
					- Initializes NVM steering wheel offset mirror
  					
					@startuml
							start
								:NVValue->EEPromStrgOffs.Offset = 0.0f;
								:NVValue->EEPromStrgOffs.Dev    = (DEG2RAD(12.0F/3.0F));
								:NVValue->EEPromStrgOffs.State  = 0;
								:NVValue->EEPromWriteRequ       = (boolean)FALSE;
								:NVValue->EEPromReadOk          = (boolean)FALSE;
							stop
					@enduml

  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c -> TEST_vdySwaInitOffsEepromMirror_001()
  @traceability			  
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1030-00026448
**************************************************************************** */
STATIC_MTD void vdySwaInitOffsEepromMirror(VDYSwaOffsEEprom_t  *NVValue);


/* **********************************************************************
  @fn                     vdySwaInitSenData */ /*!
  @brief           Initialization of steering wheel angle signal data

  @description     Init of Steering wheel angle sensor

  @return          static void

  @param[in,out]   *pSwaSen : SWA Sensor Data

  @c_switch_part   None
  @c_switch_full   None

  @pre             None
  @post            No changes
  @InOutCorrelation 
					- Initializes SWA Sensor Data
  					
					@startuml
							start
								  :pSwaSen->StrgDeltaDist         = (0.0F);
									:pSwaSen->Gradient              = (0.0F);
									:pSwaSen->StrgGradAbsOld        = (0.0F);
									:pSwaSen->StrgAngle             = (0.0F);
									:pSwaSen->StrgAngleOld          = (0.0F);
									:pSwaSen->Valid                 = (boolean)FALSE;
							stop
					@enduml

  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c -> TEST_vdySwaInitSenData_001()
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdySwaInitSenData(VDYSwaSenData_t *pSwaSen);


/* ***********************************************************************
  @fn                     vdySwaInitOffsData */ /*!
  @brief           Init of complete offset data

  @description     Initialization of steering wheel angle offset data

  @return          static void

  @param[in,out]   *SwaOffs : SWA Offset Data

  @glob_in         
				  - SWA_ANG_OFFS_DEFAULT : Default value for uncalibrated swa offset   
				  - SWA_STATE_DEFAULT : SWA offset state 0 non existent      
				  - SWA_STATE_0_DEV : SWA offset standard deviation state 0
  @glob_out        None

  @c_switch_part   None 
  @c_switch_full   None

  @pre             None 
  @post            No changes
  @InOutCorrelation 
					- Initialzes Swa Offset Data to default values
  
					@startuml
							start
								  :SwaOffs->StrgOffsReadOk        = (boolean)FALSE;
									:SwaOffs->StrgOffset            = SWA_ANG_OFFS_DEFAULT;
									:SwaOffs->StrgOffsetNorm        = 0.0f;
									:SwaOffs->OffsState             = 0;
									:SwaOffs->Dev                   = (DEG2RAD(12.0F/3.0F));
									:SwaOffs->OvrTakeCntr           = 0U;
									:SwaOffs->WhlFrDiffFilt         = 0.0f;
									:SwaOffs->WhlReDiffFilt         = 0.0f;
									:SwaOffs->LatAccel              = 0.0f;

									:SwaOffs->OffsInterimOk         = (boolean)FALSE;
									:SwaOffs->ErrStrgOffsOutOfRange = (boolean)FALSE;
									:SwaOffs->ReInitCntr            = 0U;
  
									:vdySwaInitOffsEst(&SwaOffs->Est);
							stop
					@enduml

  @testmethod			  - NA
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdySwaInitOffsData(VDYSwaOffsData_t *SwaOffs);


/* **********************************************************************
  @fn                     vdySwaInitOffsEst*/ /*!
  @brief           Init data of estimated offset

  @description     Initialize estimation results
                   Setup histogram data base

  @return          static void

  @param[in,out]   *OffsEst : Offset Estimation Data

  @glob_in         
			  - SWA_DEV_HIST_STAT_DEFAULT : Default standard deviation for offset estimation
			  - SWA_DIST_SAMP_STAT_DEFAULT : Sampled distance for estimation at state 0
  @glob_out        None 

  @c_switch_part   None
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation
				  - Initializes SWA Offset estimation results
				  - maxRg_c = (( (float32)((uint32)((float32)SWA_OFFS_HIST_NO_BINS / 2.0F))) + 0.5F) * SWA_OFFSET_HIST_WIDTH;
				  - Setup histogram database with maxRg_c
  
					@startuml
							start
								  :const float32 maxRg_c = (( (float32)((uint32)((float32)29 / 2.0F))) + 0.5F) * (DEG2RAD(1.95F));   
									:OffsEst->Offs = 0.0f;
									:OffsEst->ThrldDev          =  (DEG2RAD(1.0F));
									:OffsEst->ThrldDist         =  (20000.F);
									:OffsEst->Conf              =  0.0f;
									:vdyHistInit(&OffsEst->Hist, OffsEst->Bin.Range, OffsEst->Bin.Volume, SWA_OFFS_HIST_NO_BINS, -maxRg_c, maxRg_c);
						@enduml

  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c -> TEST_vdySwaInitOffsData_001()
  @traceability			  - 
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-828-00026448
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-833-00026448
**************************************************************************** */
STATIC_MTD void vdySwaInitOffsEst(VDYSwaOffsEst_t *OffsEst);


/* ***********************************************************************
  @fn                     vdySwaEvalThrdDist */ /*!
  @brief           Sets required distance for next learning state

  @description     Sets the distance which is needed to learn the next
                   steering wheel offset based on the current state

  @return          static fDistance_t

  @param[in]       Status : Offset Status

  @glob_in         
			  - SWA_DIST_SAMP_STAT_1 : Sampled distance for estimation at state 1    
			  - SWA_DIST_SAMP_STAT_2 : Sampled distance for estimation at state 2   
			  - SWA_DIST_SAMP_STAT_3 : Sampled distance for estimation at state 3       
			  - SWA_DIST_SAMP_STAT_4 : Sampled distance for estimation at state 4  
			  - SWA_DIST_SAMP_STAT_5 : Sampled distance for estimation at state 5      
			  - SWA_DIST_SAMP_STAT_6 : Sampled distance for estimation at state 6
			  - SWA_DIST_SAMP_STAT_DEFAULT : Sampled distance for estimation at state 0
  @glob_out        None 

  @c_switch_part   None
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation	
					- Sets the distance which is needed to learn the next steering wheel offset based on the current state
					- Default state 0 returns Sampled distance SWA_DIST_SAMP_STAT_DEFAULT    (fDistance_t) 20000.F
					- If state is 1 then returns Sampled distance SWA_DIST_SAMP_STAT_1          (fDistance_t) 25000.F
					- If state is 2 then returns Sampled distance SWA_DIST_SAMP_STAT_2          (fDistance_t) 30000.F
					- If state is 3 then returns Sampled distance SWA_DIST_SAMP_STAT_3          (fDistance_t) 35000.F
					- If state is 4 then returns Sampled distance SWA_DIST_SAMP_STAT_4          (fDistance_t) 40000.F
					- If state is 5 then returns Sampled distance SWA_DIST_SAMP_STAT_5          (fDistance_t) 40000.F
					- If state is 6 then returns Sampled distance SWA_DIST_SAMP_STAT_6          (fDistance_t) 50000.F
  
					@startuml
								start
									if (case SWA_STATE_1) then (yes)
											:Run-up phase \n required distance = 25000.F;
									elseif (case SWA_STATE_2) then (yes)
											:Run-up phase \n required distance = 30000.F;
									elseif (case SWA_STATE_3) then (yes)
											:Run-up phase \n required distance = 35000.F;
									elseif (case SWA_STATE_4) then (yes)
											:Relearn phase \n required distance = 40000.F;
								  elseif (case SWA_STATE_5) then (yes)
											:Confirmation phase \n required distance = 40000.F;
									elseif (case SWA_STATE_6) then (yes)
											:Confirmation phase \n required distance = 50000.F;
									else (default)
											:required distance = 20000.0F;;
									endif
								stop
						@enduml

  @testmethod
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c -> \n
                            TEST_vdySwaEvalThrdDist_001(),
                            TEST_vdySwaEvalThrdDist_002(),
                            TEST_vdySwaEvalThrdDist_003(),
                            TEST_vdySwaEvalThrdDist_004(),
                            TEST_vdySwaEvalThrdDist_005(),
                            TEST_vdySwaEvalThrdDist_006(),
                            TEST_vdySwaEvalThrdDist_007()
  @traceability
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-831-00026448
**************************************************************************** */
STATIC_MTD fDistance_t vdySwaEvalThrdDist(sint32 Status);


/* ***********************************************************************
  @fn                     vdySwaEvalThrdDeviation */ /*!
  @brief           Sets required offset difference

  @description     The maximum deviation of the steering wheel offset angle
                   for new offset estimation is set based on current state

  @return          static fAngle_t

  @param[in]       Status : Offset Status

  @glob_in         
				  - SWA_DEV_HIST_STAT_STARTUP : Standard deviation for offset estimation during startup phase  
				  - SWA_DEV_HIST_STAT_NORMAL : Standard deviation for offset estimation during confirmation phase
  @glob_out        None 

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None 
  @post            No changes
  @InOutCorrelation
					- Default status 0 SWA_DEV_HIST_STAT_DEFAULT     (fAngle_t) DEG2RAD(1.0F)   (Default standard deviation for offset estimation)
					- If status is 1, 2 or 3 then returns SWA_DEV_HIST_STAT_STARTUP     (fAngle_t) DEG2RAD(1.0F)    (Standard deviation for offset estimation during startup phase)       
					- If status is 4, 5 or 6 then returns SWA_DEV_HIST_STAT_NORMAL      (fAngle_t) DEG2RAD(0.5F)    (Standard deviation for offset estimation during confirmation phase)
  
					@startuml
							start
								if (case SWA_STATE_1:\n	case SWA_STATE_2:\n case SWA_STATE_3:\n) then (yes)
										:Run-up phase \n Standard deviation for offset estimation during startup phase = 1 Degree;
								elseif (case SWA_STATE_4:\n	case SWA_STATE_5:\n case SWA_STATE_6:\n) then (yes)
										:Confirmation phase \n Standard deviation for offset estimation during confirmation phase = 0.5 Degree;
								else (default)
										:Default standard deviation for offset estimation = 1 Degree;
								endif
							stop
					@enduml

  @testmethod
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c -> \n
                            TEST_vdySwaEvalThrdDeviation_001(),
                            TEST_vdySwaEvalThrdDeviation_002(),
                            TEST_vdySwaEvalThrdDeviation_003(),
                            TEST_vdySwaEvalThrdDeviation_004(),
                            TEST_vdySwaEvalThrdDeviation_005(),
                            TEST_vdySwaEvalThrdDeviation_006(),
                            TEST_vdySwaEvalThrdDeviation_007()
  @traceability
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-831-00026448
**************************************************************************** */
STATIC_MTD fAngle_t vdySwaEvalThrdDeviation(sint32 Status);


/* **********************************************************************
  @fn                     vdySwaPutEepromOffsetData */ /*!
  @brief           Stores offset in NVM mirror and set write
                   request for writing data into NVM

  @description     Copy LW offset in EEProm Mirror and set read request, save the Eeprom mirrors

  @return          static void

  @param[in]       Offset : offset value
  @param[in]       Status : learning state
  @param[in]       Dev : standard deviation

  @glob_in         SWA_GET_NV_DATA : Nonvolatile memory data of Steering wheel angle processing data
  @glob_out        None

  @c_switch_part   None 
  @c_switch_full   None

  @pre             None 
  @post            No changes 
  @InOutCorrelation
					  - Write Steering wheel angle offset NVM 
					  - Set read request, save the Eeprom mirror
  
						@startuml
								start
										:VDYSwaOffsEEprom_t *StrgOffsEEprom = SWA_GET_NV_DATA;
										:StrgOffsEEprom->EEPromStrgOffs.Offset = Offset;
										:StrgOffsEEprom->EEPromStrgOffs.State  = Status;
										:StrgOffsEEprom->EEPromStrgOffs.Dev    = Dev;
										:StrgOffsEEprom->EEPromWriteRequ       = (boolean)TRUE; 
								stop
						@enduml

  @testmethod
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c -> TEST_vdySwaPutEepromOffsetData_001()
  @traceability
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-844-00026448
**************************************************************************** */
STATIC_MTD void vdySwaPutEepromOffsetData(fAngle_t Offset, sint32 Status ,float32 Dev);


/* ***********************************************************************
  @fn                     vdySwaInitOffset */ /*!
  @brief           Init of steering wheel offset data

  @description     Init NVM steering wheel offset mirror
                   Initialization of steering wheel angle offset data

  @return          static void

  @param[in,out]   *Offset : Steering wheel angle offset data
  @param[in,out]   *NVValue : Steering wheel angle offset NVM read / write

  @c_switch_part   None
  @c_switch_full   None

  @pre             None
  @post            No changes
  @InOutCorrelation
					  - Calls Init Swa Eeprom Offset Mirror
					  - Calls Init Swa Offse Data
  
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c -> TEST_vdySwaInitOffset_001()
  @traceability			  - 
  - L4
    - NA
**************************************************************************** */
STATIC_MTD void vdySwaInitOffset(VDYSwaOffsData_t  *Offset, VDYSwaOffsEEprom_t  *NVValue);


/* **********************************************************************
  @fn                     vdySwaGetOffsetStart */ /*!
  @brief           Get non volatile start values of steering wheel offset

  @description     Reads and normalises data from NVM and determines
                   required distance and difference

  @return          static void

  @param[in,out]   *SwaOffsData : SWA offset Data

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None 
  @post            No changes 
  @InOutCorrelation
					  - If read Swa offset start values if not OK
							- Read non-volatile offset calibration data and verify ranges
							- Normalize steering wheel angle offset
							- Determine minimum required driven distance for offset estimation in depedence of state
							- Determine maximum offset deviation for estimation in dependence of state
  
							@startuml
								start
									if (Read offset start values if not OK\n if (SwaOffsData->StrgOffsReadOk == (boolean)FALSE)) then (yes)
											:Read non-volatile offset calibration data and verify ranges;
											:Normalize steering wheel angle offset;
											:Determine minimum required driven distance for offset estimation in depedence of state;
										  :Determine maximum offset deviation for estimation in dependence of state;
									endif
								stop
						@enduml
  @testmethod
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c ->
  @traceability
	- NA
**************************************************************************** */
STATIC_MTD void vdySwaGetOffsetStart(VDYSwaOffsData_t *SwaOffsData);


/* **********************************************************************
  @fn                     vdySwaCheckConfidence */ /*!
  @brief           Returns the confidence of the steering wheel offset

  @description     Confidence is based on learning state and range

  @return          static boolean

  @param[in]       *OffsData : SWA Offset Data

  @glob_in         
				  AY_SWA_OFFS_MID_CONF : Medium  confidence level       
				  AY_SWA_OFFS_LOW_CONF : Low confidence level
  @glob_out        None 

  @c_switch_part   None 
  @c_switch_full   None

  @pre             None 
  @post            No changes
  @InOutCorrelation
					  - For LEARN PHASE, AY_SWA_OFFS_LOW_CONF (0.2, Low confidence level)
					  - For RELEARN and CONFIRMATION PHASE, AY_SWA_OFFS_MID_CONF (0.5, Medium  confidence level)
					  - Check for Estimated Swa Offset is in range and Estimated Swa Offset level is greater or equal to the required confidence level
							- If Ok return True otherwise return False
  
						@startuml
								start
									:ret = (boolean)FALSE;
									if (SWA offset state > 3 (SWA_STATE_3)) then (YES)
											:Required confidence level should be Medium  confidence level (0.5);
								  else (NO)
											:Required confidence level should be Low confidence level (0.2);
								  endif
									if ((Estimated steering angle offset range is within range) && (estimated steering angle offset confidence > required confidence)) then (YES)
											:ret (boolean)TRUE;
									endif
								stop
						@enduml

  @testmethod
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c -> TEST_vdySwaCheckConfidence_001(), TEST_vdySwaCheckConfidence_002(), TEST_vdySwaCheckConfidence_003()
  @traceability
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-790-00026448
**************************************************************************** */
STATIC_MTD boolean vdySwaCheckConfidence(const VDYSwaOffsData_t *OffsData);


/* **********************************************************************
  @fn                     vdySwaOffsCheckandTakeOver */ /*!
  @brief           Take new steering wheel offset value if all conditions are met

  @description     New offset value is used if confidence is ok
                   Threshold and difference for new state are updated
                   Set fault flag if range and confidence were not good
                   enough for several attempts

  @return          static void

  @param[in,out]   *swaOffs : SWA Offset Data

  @glob_in         
				  - VDY_ERR_STATE_ACTIVE : set the error flag to active    
				  - VDY_PAR_ERR_SWA_REINIT : Steering wheel angle repeat reinit histo counter max to releas a dem event
				  - VDY_ERR_STATE_INACTIVE : set the error flag inactive
  @glob_out        None

  @c_switch_part   None
  @c_switch_full   None 

  @pre             None 
  @post            No changes 
  @InOutCorrelation
				  - Check confidence and range of estimation value
				  - If Ok
						- Validate offset value and use if applicable
						- Update distance threshold for offset calibration
						- Update deviation threshold for offset calibration
						- Reset ReInit counter
				  - Otherwise, if Estimated value is not usable as offset
						- Increment ReInit counter
				  - If ReInit counter is above parameter value (3) set the error flag and Limit ReInit counter
				  - Otherwise, reset error flag
  
					@startuml
								start
									if ((Estimated steering angle offset range is within range) && (estimated steering angle offset confidence > required confidence)) then (YES)
											:Validate offset value and use if applicable;
											:Update distance threshold for offset calibration;
											:Update deviation threshold for offset calibration;
											:Reset ReInit counter;
								  else (NO)
											if(swaOffs->OffsState > SWA_STATE_1) then (YES)
												:Reinitialize histogram;
										  endif
											if ((Estimated steering angle offset range is not within range) && (estimated steering angle offset confidence > required confidence)) then (YES)
												:Inc ReInit counter \n swaOffs->ReInitCntr++;
										  endif
								  endif
									if (ReInit counter is above parameter value (3)) the (YES)
											:set the error flag\n errOffsRg = VDY_ERR_STATE_ACTIVE;
											:Limit ReInit counter \n swaOffs->ReInitCntr = VDY_PAR_ERR_SWA_REINIT;
									else (NO)
											:reset error flag \n errOffsRg = VDY_ERR_STATE_INACTIVE;
									endif
								stop
						@enduml

  @testmethod
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c -> TEST_vdySwaOffsCheckandTakeOver_001(), TEST_vdySwaOffsCheckandTakeOver_002(), TEST_vdySwaOffsCheckandTakeOver_003(), TEST_vdySwaOffsCheckandTakeOver_004(), TEST_vdySwaOffsCheckandTakeOver_005()
  @traceability
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-790-00026448
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-831-00026448
**************************************************************************** */
STATIC_MTD void vdySwaOffsCheckandTakeOver(VDYSwaOffsData_t *swaOffs);


/* **********************************************************************
  @fn                     vdySwaGetOffset */ /*!
  @brief           Get steering wheel offset from NVM and check for plausibility

  @description      Complete the NVM read operation successfully if NVM swa offset access state is TRUE
                    Check Stored offset value is out of range
                    Copy LW offset from EEProm in application

  @return          static boolean

  @param[in,out]   *Offset : SWA Offset Data
  @param[in,out]   *Status : SWA Offset Status
  @param[in,out]   *Dev : Deviation

  @glob_in         
				  - SWA_GET_NV_DATA : Access to EEProm Mirror      
				  - SWA_ANG_OFFS_DEFAULT : Default value for uncalibrated swa offset      
				  - SWA_STATE_DEFAULT : SWA offset state 0 non existent       
				  - SWA_STATE_0_DEV : SWA offset standard deviation state 0    
				  - VDY_ERR_STATE_ACTIVE : Indicate error state active    
				  - VDY_ERR_STATE_INACTIVE : Indicate error state inactive
  @glob_out        SWA_GET_NVM_ERR_OFFS_RG : Input/Output interface

  @c_switch_part   None 
  @c_switch_full   None

  @pre             None 
  @post            No changes
  @InOutCorrelation
					  - Access EEProm mirror
					  - If NVM access fails, Set StrgOffs, StrgStatus, StrgDev to init values and return False
					  - If Read operation successful, 
							- If stored offset value is out of range or false value then Indicate active error state, Try to correct invalid values in nv memory by overwriting with defaults and return False
							- Stored swa nvmem values are OK, then Set StrgOffs, StrgStatus, StrgDev to read values and return True 
  
							@startuml
								start
									:Set StrgOffs, StrgStatus, StrgDev to init values;
									if (StrgOffsEEprom->EEPromReadOk == (boolean)TRUE) then (YES)
											if(NVM steering angle offset is not within range) then (YES)
												:Stored offset value is out of range 
														Indicate error state active "false" value stored in nvmemory 
														NVMerrOffsRg = VDY_ERR_STATE_ACTIVE;
												:correct invalid values in nv memory by overwriting with defaults
														StrgOffsEEprom->EEPromStrgOffs.Offset = SWA_ANG_OFFS_DEFAULT 
														StrgOffsEEprom->EEPromStrgOffs.State  = SWA_STATE_DEFAULT 
														StrgOffsEEprom->EEPromStrgOffs.Dev    = SWA_STATE_0_DEV;
											else if((StrgOffsEEprom->EEPromStrgOffs.State < SWA_STATE_DEFAULT) || (StrgOffsEEprom->EEPromStrgOffs.State > SWA_STATE_6)) then (YES)
												:Stored offset state is out of range
														Indicate error state active "false state stored in nvmemory
														NVMerrOffsRg = VDY_ERR_STATE_ACTIVE;
												:correct invalid values in nv memory by overwriting with defaults
														StrgOffsEEprom->EEPromStrgOffs.Offset = SWA_ANG_OFFS_DEFAULT
														StrgOffsEEprom->EEPromStrgOffs.State  = SWA_STATE_DEFAULT 
														StrgOffsEEprom->EEPromStrgOffs.Dev    = SWA_STATE_0_DEV;
											else (NO)
												:Stored swa nvm values are OK
														Set StrgOffs, StrgStatus, StrgDev to NVM values 
														*Offset    = StrgOffsEEprom->EEPromStrgOffs.Offset 
														*Status    = StrgOffsEEprom->EEPromStrgOffs.State 
														*Dev       = StrgOffsEEprom->EEPromStrgOffs.Dev;
												:NVMerrOffsRg = VDY_ERR_STATE_INACTIVE;
										 endif
									:StrgOffsOk = (boolean)TRUE;
								endif
								stop
						@enduml

  @testmethod
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c -> TEST_vdySwaGetOffset_001(), TEST_vdySwaGetOffset_002(), TEST_vdySwaGetOffset_003(), TEST_vdySwaGetOffset_004(), TEST_vdySwaGetOffset_005()
  @traceability
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1031-00026448
**************************************************************************** */
STATIC_MTD boolean vdySwaGetOffset(fAngle_t *Offset, sint32 *Status, float32 *Dev );


/* **********************************************************************
  @fn                     vdySwaCalcConfidence */ /*!
  @brief           Calculate confidence of steering wheel offset data

  @description     Calculates mean and deviation of histogram
                   Checks distribution and peaks
                   Sets confidence level based on the histogram quality

  @return          static void

  @param[in,out]   *StrgOffsData : Steering wheel angle offset data

  @glob_in         
				  - AY_SWA_OFFS_NO_CONF : No confidence level     
				  - AY_SWA_OFFS_MAX_CONF : Maximum confidence level       
				  - AY_SWA_OFFS_MID_CONF : Medium confidence level    
				  - AY_SWA_OFFS_LOW_CONF : Low confidence level
  @glob_out        None 

  @c_switch_part   None
  @c_switch_full   None

  @pre             None 
  @post            No changes 
  @InOutCorrelation
					  - Calculate mean and standard deviation of histogram data
					  - Create an sorted index of histogram bin volumes
					  - Calculate median of histogram data
					  - Store last value of sorted index coresponds to bin with maximum count
					  - Initialize confidence level and Compare mean with maximum count bin
							- If Range with maximum count is close to mean
									- Check if adjacent bins of maximum have enough counts, detect the case with nearly constant angle then normal route characteristics, best confidence, AY_SWA_OFFS_MAX_CONF
									- Otherwise, driving long section with same steering wheel angle (straight or constant radius), AY_SWA_OFFS_MID_CONF
									- bin counts are normally distributed, use mean as offset value
							- Otherwise, if Range with maximum count is far away from mean, counts are not normally distributed that means that a secondary peak exists. This can be caused by driving oval circuits on proving grounds
									- Get Distance difference between maximum and secondary peak
									- Get distance difference between maximum and range around mean
											- If the count difference between secondary peak and maximum peak is big enough, blind out secondary peak by use only center around the maximum peak
													- Calculate mean around maximum peak
													- Limit confidence to avoid high status offset calibration, AY_SWA_OFFS_LOW_CONF
											- Else If Maximum distance count is not not much above the mean distance count, but median and mode are close to together, this can occur in case of large offset values, where histogram data is unsymmetric because one-sided truncation
													- Calculate mean around maximum peak
													- Use median as estimated offset
													- If Maximum value looks like a outlier, use AY_SWA_OFFS_LOW_CONF
											- Else If Distribution looks symmetric, but maximum peak is outside the centre
													- Use median as estimated offset
													- If Maximum value looks like a outlier, use AY_SWA_OFFS_MID_CONF
													- Otherwise use AY_SWA_OFFS_LOW_CONF
											- Otherwise, If two peaks with rougly the same distance and ambiguous route characteristics
													- Estimation has no confidence, AY_SWA_OFFS_NO_CONF
  
						
						@startuml
									start
										:Calculate mean and standard deviation of histogram data;
										:Create an sorted index of histogram bin volumes;
										:Calculate median of histogram data;
										if (CML_f_Abs(hist->Mean - hist->Range[maxIdx]) < (DEG2RAD(1.0F)) ) then (YES)
											if((CML_f_Abs(hist->Volume[maxIdx] - (hist->Volume[maxIdx-1u] + hist->Volume[maxIdx+1u])) < (0.5 * StrgOffsData->Est.ThrldDist)) && ((maxIdx > 1u) && (maxIdx < (hist->Size - 1u)))) then (YES)
												:StrgOffsData->Est.Conf = 1.0f;
											else (NO)
												:StrgOffsData->Est.Conf = 0.5f;
											endif
											:StrgOffsData->Est.Offs = hist->Mean;
										else (NO)
											:Distance difference between maximum and secondary peak
												distMax_c = hist->Volume[rgSort[SWA_OFFS_HIST_MAX_IDX]];
											:Get distance difference between maximum and range around mean
												diffDistMaxMean = distMax_c - vdyHistGetVolume(hist, hist->Mean);
											if (diffDistMaxMean > (0.2 * swa ThresholdDist) ) then (YES)
												:Calculate mean around maximum peak;
												:StrgOffsData->Est.Conf = AY_SWA_OFFS_LOW_CONF;
											else if (CML_f_Abs(median - hist->Range[maxIdx]) < (DEG2RAD(2.5F)) ) then (YES)
												if (CML_f_Abs(diffMeanMedian) < (DEG2RAD(1.5F))) then (YES)
													:Use median as estimated offset
														StrgOffsData->Est.Offs = median;
													:Maximum value looks like a outlier, use median value instead
														StrgOffsData->Est.Conf = 0.2f;
												endif
											else if (CML_f_Abs(median - hist->Mean) < (DEG2RAD(1.0F)) ) then (YES)
												:StrgOffsData->Est.Offs = median;
												if (diffDistMaxMean < (0.1f * StrgOffsData->Est.ThrldDist) ) then (YES)
													:Maximum value looks like a outlier, use median value instead
														StrgOffsData->Est.Conf = 0.5f;
												else (NO)
													:Maximum value looks like a outlier, use median value instead
													:StrgOffsData->Est.Conf = 0.2f;
												endif
											else (NO)
												:StrgOffsData->Est.Conf = 0.0f;
											endif
										endif
									stop
							@enduml

  @testmethod
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c -> \n
                            TEST_vdySwaCalcConfidence_001(),
                            TEST_vdySwaCalcConfidence_002(),
                            TEST_vdySwaCalcConfidence_003(),
                            TEST_vdySwaCalcConfidence_004(),
                            TEST_vdySwaCalcConfidence_005(),
                            TEST_vdySwaCalcConfidence_006(),
                            TEST_vdySwaCalcConfidence_007(),
                            TEST_vdySwaCalcConfidence_008(),
                            TEST_vdySwaCalcConfidence_009()
  @traceability
  - L3
    - doors://RBGS854A:40000/?version=2&prodID=0&view=000000cd&urn=urn:telelogic::1-503e822e5ec3651e-O-288-000221c8 
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-830-00026448
**************************************************************************** */
STATIC_MTD void vdySwaCalcConfidence(VDYSwaOffsData_t *StrgOffsData);


/* ***********************************************************************
  @fn                     vdySwaOffsetRangeOk */ /*!
  @brief           Checks steering angle offset range

  @description     Return steering angle offset range TRUE if offset within range

  @return          static boolean

  @param[in]       Offset :SWA Offset Data

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None 
  @post            No changes 
  @InOutCorrelation
					  - Return True if steering angle offset range is within range i.e., CML_f_Abs(StrgAngOffsNorm) <= VDY_PAR_SWA_OFFSET_LIMIT_MAX(12 degrees) 
					  - Return False otherwise
  
						@startuml
								start
									:StrgOffsOk      = (boolean)FALSE; 
									if (offset within range) then (YES)
										:StrgOffsOk = (boolean)TRUE;
									else (NO)
										:StrgOffsOk = (boolean)FALSE;
									endif
								stop
						@enduml

  @testmethod
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c -> TEST_vdySwaOffsetRangeOk_001(), TEST_vdySwaOffsetRangeOk_002()
  @traceability
	- NA
**************************************************************************** */
STATIC_MTD boolean vdySwaOffsetRangeOk(fAngle_t Offset);


/* **********************************************************************
  @fn               vdySwaGetOffsetDeviation */ /*!

  @brief           Assign offset standard deviation for offset state

  @description     Assign offset standard deviation for offset state

  @return          static float32

  @param[in]       OffsState : SWA Offset Status

  @glob_in         
  SWA_STATE_1_DEV : SWA offset standard deviation state 1 \n
  SWA_STATE_2_DEV : SWA offset standard deviation state 2 \n
  SWA_STATE_3_DEV : SWA offset standard deviation state 3 \n
  SWA_STATE_4_DEV : SWA offset standard deviation state 4 \n
  SWA_STATE_5_DEV : SWA offset standard deviation state 5 \n
  SWA_STATE_6_DEV : SWA offset standard deviation state 6 \n
  SWA_STATE_0_DEV : SWA offset standard deviation state 0
  @glob_out        None

  @c_switch_part   None
  @c_switch_full   None

  @pre             None
  @post            No changes
  @InOutCorrelation	
					- (fAngle_t) DEG2RAD(12.0F/3.0F) for SWA_STATE_0_DEV (SWA offset standard deviation state 0)
					- (fAngle_t) DEG2RAD(4.0F/3.0F)  for SWA_STATE_1_DEV (SWA offset standard deviation state 1)
					- (fAngle_t) DEG2RAD(3.0F/3.0F)  for SWA_STATE_2_DEV (SWA offset standard deviation state 2)
					- (fAngle_t) DEG2RAD(2.0F/3.0F)  for SWA_STATE_3_DEV (SWA offset standard deviation state 3) 
					- (fAngle_t) DEG2RAD(1.0F/3.0F)  for SWA_STATE_4_DEV (SWA offset standard deviation state 4)  
					- (fAngle_t) DEG2RAD(0.5F/3.0F)  for SWA_STATE_5_DEV (SWA offset standard deviation state 5)  
					- (fAngle_t) DEG2RAD(0.5F/3.0F)  for SWA_STATE_6_DEV (SWA offset standard deviation state 6)
  
					@startuml
								start
									:ret;
									if (case SWA_STATE_1: OffsState == SWA_STATE_1) then (yes)
											:ret = DEG2RAD(4.0F/3.0F);
									else if (case SWA_STATE_2: OffsState == SWA_STATE_2) then (yes)
											:ret = DEG2RAD(3.0F/3.0F);
								  else if (case SWA_STATE_3: OffsState == SWA_STATE_3) then (yes)
											:ret = DEG2RAD(2.0F/3.0F);
								  else if (case SWA_STATE_4: OffsState == SWA_STATE_4) then (yes)
											:ret = DEG2RAD(1.0F/3.0F);
								  else if (case SWA_STATE_5: OffsState == SWA_STATE_5) then (yes)
											:ret = DEG2RAD(0.5F/3.0F);
								  else if (case SWA_STATE_6: OffsState == SWA_STATE_6) then (yes)
											:ret = DEG2RAD(0.5F/3.0F);
									else (default)
											:ret = DEG2RAD(12.0F/3.0F);
									endif
								stop
						@enduml
  @testmethod
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c -> \n
                            TEST_vdySwaGetOffsetDeviation_001(),
                            TEST_vdySwaGetOffsetDeviation_002(),
                            TEST_vdySwaGetOffsetDeviation_003(),
                            TEST_vdySwaGetOffsetDeviation_004(),
                            TEST_vdySwaGetOffsetDeviation_005(),
                            TEST_vdySwaGetOffsetDeviation_006(),
                            TEST_vdySwaGetOffsetDeviation_007(),
                            TEST_vdySwaGetOffsetDeviation_008()
  @traceability
	- NA
**************************************************************************** */
STATIC_MTD float32 vdySwaGetOffsetDeviation(sint32 OffsState);


/* **********************************************************************
  @fn                     vdyAyGetOffsetStart */ /*!
  @brief           Get non volatile start values of lat accel offset

  @description     Reads and normalises data from NVM and determines
                   required distance and difference

  @return          static void

  @param[in,out]   *pAyOffsData : Ay Offset Data

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None 
  @post            No changes
  @InOutCorrelation
				  - If read Ay offset start values if not OK
						- Read non-volatile offset calibration data and verify ranges
						- Determine minimum required driven distance for offset estimation in depedence of state
						- Determine maximum offset deviation for estimation in dependence of state
  
						@startuml
								start
									if (Read offset start values not OK) then (yes)
											:Read non-volatile offset calibration data and verify ranges;
											:Determine minimum required driven distance for offset estimation in depedence of state;
											:Determine maximum offset deviation for estimation in dependence of state;
									endif
								stop
						@enduml
  @testmethod
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c -> TEST_vdyAyGetOffsetStart_001(), TEST_vdyAyGetOffsetStart_002()
  @traceability
	- NA
**************************************************************************** */
STATIC_MTD void vdyAyGetOffsetStart(VDYAyOffsData_t *pAyOffsData);


/* ***********************************************************************
  @fn                     vdyAyInitVolatile */ /*!
  @brief           Initialization of volatile lateral acceleration data

  @description     Initialization of lateral acceleration data
                   Set lateral acceleration Input/Output interface error states

  @return          static void

  @param[in,out]   *pAyData : Lateral Acceleration Data 

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None
  @post            No changes 
  @InOutCorrelation
				  - Initializes lateral acceleration Sensor Data
				  - Initializes Error States
  
					@startuml
							start
								:vdyAyInitSenData(&pAyData->Sensor);
								:pAyData->Io.errOffsRg = NULL;
								:pAyData->Io.NVMerrOffsRg = NULL;
								:pAyData->Io.AyNVMerrOffsRg = NULL;
							stop
					@enduml

  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c -> TEST_vdyAyInitVolatile_001()
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdyAyInitVolatile(VDYAyData_t *pAyData);


/* ***********************************************************************
  @fn                     vdyAyInitOffset */ /*!
  @brief           Init of lateral offset data

  @description     Init of lateral acceleration offset data

  @return          static void

  @param[in,out]   *pAyOffset : Ay Offset Data

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None 
  @post            No changes 
  @InOutCorrelation
					- Calls vdyAyInitOffsData function
  
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c -> TEST_vdyAyInitOffset_001()
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdyAyInitOffset(VDYAyOffsData_t  *pAyOffset);


/* **********************************************************************
  @fn                     vdyAyOffsCheckandTakeOver */ /*!
  @brief           Take new lat accel offset value if all conditions are met

  @description     New offset value is used if confidence is ok
                   Threshold and difference for new state are updated
                   if requested by flag

  @return          static void

  @param[in,out]   *payOffs : Ay Offset Data
  @param[in]       *pswaOffs : Swa Pffset Data
  @param[in]       clrData : Data Clear Flag

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation
				  - Validate offset value and use if applicable
					- If no need of reset previous data
						- Update distance threshold for offset calibration
						- Update deviation threshold for offset calibration
				  - Otherwise
					- If no need of reset previous data
						- Estimated value is not usable as offset, call vdyHistReInit
  
						@startuml
								start
									if ((Ay offset is within range and confidence is greater than required confidence ) && (confidence > VDY_ZERO_F) ) then (YES)
											:Validate offset value and use if applicable;
											if (clrData !=(boolean)FALSE) then (YES)
												:Update distance threshold for offset calibration;
												:Update deviation threshold for offset calibration;
											endif
									else (NO)
											if (clrData !=(boolean)FALSE) then (YES)
												:Estimated value is not usable as offset \n
														ReInit Histogram;
										  endif
								  endif
								stop
						@enduml

  @testmethod
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c -> TEST_vdyAyOffsCheckandTakeOver_00(), TEST_vdyAyOffsCheckandTakeOver_002(), TEST_vdyAyOffsCheckandTakeOver_003(), TEST_vdyAyOffsCheckandTakeOver_004()
  @traceability
	- NA
**************************************************************************** */
STATIC_MTD void vdyAyOffsCheckandTakeOver(VDYAyOffsData_t *payOffs, const VDYSwaOffsData_t *pswaOffs, boolean clrData);


/* **********************************************************************
  @fn                     vdyAyTakeoverOffset */ /*!
  @brief           Take lateral acceleration offset as active offset

  @description     Calculates the new offset value based on value difference
                   and learning state
                   Increases or decreases leraning state according to difference
                   and reduces the measurement data

  @return          static void

  @param[in,out]   *offsAy : Ay Offset Data
  @param[in,out]   *estOffsAy : Estimated Ay Offset Data

  @glob_in         AY_STATE_DEFAULT : Ay offset state 0 non existent
  @glob_out        None 

  @c_switch_part   None 
  @c_switch_full   None

  @pre             None
  @post            No changes
  @InOutCorrelation
					  - Get gifferences between active and new estimated offset
					  - If No active offset available (the estimated offset is the first calculated offset)
						- Use estimated offset as first offset. no appoximation with active offset (there is no active offset available)
					  - Otherwise, Calculate average between active and estimated offset for successive approximation of final offset
					  - Acquisition strategy is dependent on current state
						- For L E A R N   P H A S E, AY_STATE_DEFAULT (0), AY_STATE_1 (1) and AY_STATE_2 (2)
							- When offset value is stable, increment state
							- Save offset value and status in nonvolatile memory
							- Initialize estimation data
							- Take over offset and deviation
						- For R E L E A R N   P H A S E, AY_STATE_3 (3)
							- Test offset against stability
							- If estimated offset differs significantly from active offset: restore learned offset value
								- Remain in this offset calibration state
								- Take over offset
								- Initialize estimation data
							- Otherwise, if estimated offset approves active and stored offset
								- Increment offset state
								- Take over offset
								- Indicate that offset value has been confirmed during this ignition cylce, i.e., one confirmation per ignition cylce
								- Scale back estimation data
							- if estimated offset approves active and stored offset, Save offset value and status in nonvolatile memory
						- For other values
							- Set default state, AY_STATE_DEFAULT (0)
							- Initialize estimation data
  
						@startuml
							start
								:Take the absolute differences between active and new estimated offset
									AyOffsDiff    = Estimated AyOffset - Active AyOffset
									AyOffsAbsDiff = CML_f_Abs(AyOffsDiff);
									if(AyOffsState == AY_STATE_DEFAULT) then (YES)
										:AyOffsNew = estimated AyOffset;
									else (NO)
										:AyOffsNew = Active AyOffset + (0.7 * AyOffsDiff);
									endif
									if((AyOffset State == AY_STATE_DEFAULT) || (AyOffset State == AY_STATE_1) || (AyOffset State == AY_STATE_2)) then (YES)
												:L E A R N   P H A S E;
												if (offsAy->Interims == (boolean)FALSE) then (YES)
													if(AyOffsAbsDiff <= 0.7f) then (YES)
														:AyOvrTakeCntr++;
														if(AyOvrTakeCntr < 3) then (YES)
															:AyOffsetState += 1;
														endif
													endif
													:Save offset value and status in non volatile memory;
													:Initialize estimation data
														HistReInit;
												endif
												:Take over offset and deviation 
													AyOffset     = AyOffsetNew
													AyDev        = Deviation at OffsState;
									else if (AyOffset State == AY_STATE_3) then (YES)
												:R E L E A R N   P H A S E;
												if(AyOffsAbsDiff >= 0.5f ) then (YES)
													:AyOffset State   = AY_STATE_2;
													:Take over offset
														AyOffset   = AyOffsNew
														AyDev      = Deviation at OffsState;
													if (offsAy->Interims == (boolean)FALSE) then (YES)
														:Initialize estimation data
															HistReInit;
													endif
												else (No)
													if (offsAy->Interims==(boolean)FALSE) then (YES)
														:AyOffsState  = AY_STATE_3;
														:Take over offset
															AyOffset   = AyOffsNew
															AyDev      = Deviation at OffsState;
														:AyOvrTakeCntr++;
														:Reduce histogram to 40%;
													endif
												endif
												if (offsAy->Interims == (boolean)FALSE) then (YES)
													:Save offset value and status in nonvolatile memory;
												endif
									else (default)
												:Set default state
														AyOffsetState = AY_STATE_DEFAULT
														offsAy->Dev       = Deviation at OffsState;
												:Initialize estimation data
														HistReInit;
								 endif
							stop
						@enduml

  @testmethod
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c -> \n
                            TEST_vdyAyTakeoverOffset_001(),
                            TEST_vdyAyTakeoverOffset_002(),
                            TEST_vdyAyTakeoverOffset_003(),
                            TEST_vdyAyTakeoverOffset_004(),
                            TEST_vdyAyTakeoverOffset_005(),
                            TEST_vdyAyTakeoverOffset_006(),
                            TEST_vdyAyTakeoverOffset_007(),
                            TEST_vdyAyTakeoverOffset_008(),
                            TEST_vdyAyTakeoverOffset_009(),
                            TEST_vdyAyTakeoverOffset_010()

  @traceability
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1020-00026448
**************************************************************************** */
STATIC_MTD void vdyAyTakeoverOffset(VDYAyOffsData_t *offsAy, VDYAyOffsEst_t *estOffsAy);


/* ***********************************************************************
  @fn                     vdyAyInitSenData */ /*!
  @brief           Initialization of lateral acceleration data

  @description     Initialization of lateral acceleration sensor data

  @return          static void

  @param[in,out]   *pAySen :Ay Sensor Data

  @c_switch_part   None 
  @c_switch_full   None

  @pre             None
  @post            No changes 
  @InOutCorrelation
					- Initializes lateral acceleration sensor data variable
  
					@startuml
							start
								:pAySen->Ay             = (0.0F);
								:pAySen->AyOld          = (0.0F);

								:pAySen->AyGradAbsOld   = (0.0F);
								:pAySen->Gradient       = (0.0F);

								:pAySen->Valid          = (boolean)FALSE;
							stop
					@enduml

  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c -> TEST_vdyAyInitSenData_001()
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdyAyInitSenData(VDYAySenData_t *pAySen);


/* ***********************************************************************
  @fn                     vdyAyInitOffsData */ /*!
  @brief           Init of estimated lateral acceleration offset data

  @description     Initialization of lateral acceleration offset calibration data

  @return          static void

  @param[in,out]   *pAyOffs : Ay Offset Data

  @glob_in         
				  - AY_STATE_0_DEV : Lateral accleration offset standard deviation state 0
				  - AY_STATE_DEFAULT : Ay offset state 0 non existent
  @glob_out        None 

  @c_switch_part   None 
  @c_switch_full   None
  
  @pre             None
  @post            No changes
  @InOutCorrelation
					- Initialzes lateral acceleration Offset Data to default values
  
					@startuml
								start
									:pAyOffs->AyOffset     = (0.0F);
									:pAyOffs->Dev          = (1.0F/3.0F);
									:pAyOffs->OffsState    = 0;
									:pAyOffs->OvrTakeCntr  = 0;
									:pAyOffs->Interims     = (boolean)FALSE;
									:pAyOffs->AyOffsReadOk = (boolean)FALSE;

									:vdyAyInitOffsEst(&pAyOffs->Est);
								stop
					@enduml

  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c -> TEST_vdyAyInitOffsData_001()
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdyAyInitOffsData(VDYAyOffsData_t *pAyOffs);


/* ***********************************************************************
  @fn                     vdyAyInitOffsEst */ /*!
  @brief           Init of lateral acceleration offset data

  @description     Initialization of lateral acceleration offset estimation

  @return          static void

  @param[in,out]   *pAyOffsEst : Ay Offset Data

  @glob_in         
				  - AY_DEV_SAMP_STAT_DEFAULT : Default standard deviation for offset estimation
				  - AY_DIST_SAMP_STAT_DEFAULT :  distance for estimation at state 0
  @glob_out        None

  @c_switch_part   None
  @c_switch_full   None

  @pre             None
  @post            No changes
  @InOutCorrelation
					  - Initializes SWA Offset estimation results
					  - maxRg_c = (( (float32)((uint32)((float32)AY_OFFS_HIST_NO_BINS / 2.0F))) + 0.5F) * AY_OFFSET_HIST_WIDTH;
					  - Setup histogram database with maxRg_c
  
						@startuml
							start
								:const float32 maxRg_c = (( (float32)((uint32)((float32)41/ 2.0F))) + 0.5F) * (0.25F); 
								:pAyOffsEst->Offs = 0.0f;
								:pAyOffsEst->ThrldDev          =  0.5f;
								:pAyOffsEst->ThrldDist         =  (20000.F);
								:pAyOffsEst->Conf              =  0.0f;
								:vdyHistInit(&pAyOffsEst->Hist, pAyOffsEst->Bin.Range, pAyOffsEst->Bin.Volume, AY_OFFS_HIST_NO_BINS, -maxRg_c, maxRg_c);
							stop
						@enduml

  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c -> TEST_vdyAyInitOffsEst_001()
  @traceability			  - 
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1017-00026448
**************************************************************************** */
STATIC_MTD void vdyAyInitOffsEst(VDYAyOffsEst_t *pAyOffsEst);


/* ************************************************************************
  @fn                     vdyAyEvalThrdDist */ /*!
  @brief           Sets required distance for next learning state

  @description     Sets the distance which is needed to learn the next
                   lateral acceleration offset based on the current state

  @return          static fDistance_t

  @param[in]       Status : Ay Offset Status

  @glob_in         
				  - AY_DIST_SAMP_STAT_1 : Sampled distance for estimation at state 1  
				  - AY_DIST_SAMP_STAT_2 : Sampled distance for estimation at state 2     
				  - AY_DIST_SAMP_STAT_3 : Sampled distance for estimation at state 3   
				  - AY_DIST_SAMP_STAT_DEFAULT : Sampled distance for estimation at state 0
  @glob_out        None 

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None 
  @post            No changes
  @InOutCorrelation
					  - If status is 0 then returns Sampled distance AY_DIST_SAMP_STAT_DEFAULT    ((fDistance_t) 20000.F)
					  - If status is 1 then returns Sampled distance AY_DIST_SAMP_STAT_1          ((fDistance_t) 25000.F)
					  - If status is 2 then returns Sampled distance AY_DIST_SAMP_STAT_2          ((fDistance_t) 30000.F)
					  - If status is 3 then returns Sampled distance AY_DIST_SAMP_STAT_3          ((fDistance_t) 30000.F)
  
						@startuml
								start
									: reqDist;
									if (Status == AY_STATE_1 ) then (YES)
											:Run-up phase \n reqDist = 25000.F;
									else if (Status == AY_STATE_2 ) then (YES)
											:Run-up phase \n reqDist = 30000.F;
								 else if (Status == AY_STATE_3 ) then (YES)
											:Learn and relearn state \n	reqDist = 30000.F;
									else (default)
											:reqDist = 20000.F;
								  endif
								stop
						@enduml

  @testmethod
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c -> TEST_vdyAyEvalThrdDist_001(), TEST_vdyAyEvalThrdDist_002(), TEST_vdyAyEvalThrdDist_003(), TEST_vdyAyEvalThrdDist_004()
  @traceability
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-786-00026448
**************************************************************************** */
STATIC_MTD fDistance_t vdyAyEvalThrdDist(sint32 Status);


/* ***********************************************************************
  @fn                     vdyAyEvalThrdDeviation */ /*!
  @brief           Sets required offset difference

  @description     The maximum deviation of the lateral acceleration offset angle
                   for new offset estimation is set based on current state

  @return          static fAccel_t

  @param[in]       Status : Ay Offset Status

  @glob_in         
				  - AY_DEV_SAMP_STAT_STARTUP : Standard deviation for offset estimation during startup phase
				  - AY_DEV_SAMP_STAT_NORMAL : Standard deviation for offset estimation during confirmation phase
  @glob_out        None 

  @c_switch_part   None
  @c_switch_full   None

  @pre             None 
  @post            No changes
  @InOutCorrelation
					  - If state is 0 then returns Default Standard deviation for offset estimation AY_DEV_SAMP_STAT_DEFAULT     (fAccel_t) (0.5F)
					  - If state is 1 or 2 then returns Standard deviation for offset estimation, AY_DEV_SAMP_STAT_STARTUP     (fAccel_t) (0.5F)   (during startup/runup phase)       
					  - If state is 3 then returns Standard deviation for offset estimation,AY_DEV_SAMP_STAT_NORMAL      (fAccel_t) (0.2F)    (during confirmation/learn relearn phase)
  
						@startuml
								start
									: Accel;
									if ((Status == AY_STATE_1) || (Status == AY_STATE_2)) then (YES)
											:Run-up phase \n Accel = 0.5F;
									else if (Status == AY_STATE_3 ) then (YES)
											:Learn and relearn phase \n Accel = 0.2F;
									else (default)
											:Accel = 0.5F;
								  endif
								stop
						@enduml

  @testmethod
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c -> TEST_vdyAyEvalThrdDeviation_001(), TEST_vdyAyEvalThrdDeviation_002(), TEST_vdyAyEvalThrdDeviation_003(), TEST_vdyAyEvalThrdDeviation_004()
  @traceability
	- NA
**************************************************************************** */
STATIC_MTD fAccel_t vdyAyEvalThrdDeviation(sint32 Status);


/* ***********************************************************************
  @fn                     vdyAyOffsetRangeOk */ /*!
  @brief           Checks lateral acceleration range

  @description     Verfiy that lateral acceleration offset value is inside plausible range and return TRUE if Offset value is ok

  @return          static boolean

  @param[in]       Offset : Offset Data

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None 
  @post            No changes 
  @InOutCorrelation
					  - Return True if laeral acceleration offset is within range i.e., CML_f_Abs(Offset) <= AY_OFFSET_LIMIT_MAX (1.2 degrees)
					  - Return False otherwise
  
						@startuml
								start
									:AyOffsOk = (boolean)FALSE;
									if (offset value is inside plausible range) then (YES)
											: Offset value is ok 
												AyOffsOk = (boolean)TRUE;
								  endif
								stop
						@enduml

  @testmethod
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c -> TEST_vdyAyOffsetRangeOk_001(), TEST_vdyAyOffsetRangeOk_002()
  @traceability
	- NA
**************************************************************************** */
STATIC_MTD boolean vdyAyOffsetRangeOk(fAccel_t Offset);


/* **********************************************************************
  @fn               vdyAyGetNvmOffsetData */ /*!
  @brief           Store values in nonvolatile memory

  @description     Complete the NVM read operation successfully if NVM state is valid

  @return          static boolean

  @param[in,out]   *Offset : Ay Offset Data
  @param[in,out]   *Status : Ay Offset Status
  @param[in,out]   *Dev : Deviation

  @glob_in         AY_GET_NV_READ_DATA : Input/Output interface
  @glob_out        None

  @c_switch_part   None 
  @c_switch_full   None

  @pre             None 
  @post            No changes 
  @InOutCorrelation
					  - Read NVM if NVM state is valid
					  - Else set offset and status to default values (0)
  
						@startuml
								start
									if(nvm->State == SWA_NVM_CLEARED) then (YES)
											:*Offset = AY_OFFS_DEFAULT;
											:*Status = AY_STATE_DEFAULT;
								  else (NO)
											:*Offset = nvm->LatAcc.ZeroAccel;
											:*Status = (sint32) nvm->LatAcc.CalStatus;
								  endif
									:*Dev    = vdyAyGetOffsetDeviation(*Status);
									:writing Ay offset into NVM in every excution cycle
										LastAyNvmData.ZeroAngle = *Offset
										LastAyNvmData.CalStatus = (uint32)*Status;
								stop
						@enduml

  @testmethod
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c -> TEST_vdyAyGetNvmOffsetData_001(), TEST_vdyAyGetNvmOffsetData_002()
  @traceability
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1015-00026448
**************************************************************************** */
STATIC_MTD boolean vdyAyGetNvmOffsetData(fAccel_t *Offset, sint32 *Status, float32 *Dev);


/* **********************************************************************
  @fn                     vdyAyCheckConfidence */ /*!
  @brief           Returns the confidence of the lat accel offset

  @description     Confidence is based on learning state and range

  @return          static boolean

  @param[in]       *ayOffs : Ay Offset Data

  @glob_in         
				  AY_SWA_OFFS_MID_CONF : Medium  confidence level   
				  AY_SWA_OFFS_LOW_CONF : Low confidence level
  @glob_out        None 

  @c_switch_part   None
  @c_switch_full   None 

  @pre             None
  @post            No changes 
  @InOutCorrelation
					  - For run-up PHASE, AY_SWA_OFFS_LOW_CONF (0.2, Low confidence level)
					  - For learn and relearn PHASE, AY_SWA_OFFS_MID_CONF (0.5, Medium  confidence level)
					  - Check for Estimated Ay Offset is in range and Estimated Ay Offset level is greater or equal to the required confidence level
							- If Ok return True otherwise return False
  
							@startuml
								start
									:ret = (boolean)FALSE;
									if (Ay offset state > 3 (AY_STATE_2)) then (YES)
											:Required confidence level should be Medium confidence level (0.5);
								  else (NO)
											:Required confidence level should be Low confidence level (0.2);
								  endif
									if ((Estimated Ay offset range is within range) && (estimated Ay offset confidence > required confidence)) then (YES)
											:ret (boolean)TRUE;
									endif
								stop
						@enduml

  @testmethod
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c -> TEST_vdyAyCheckConfidence_001(), TEST_vdyAyCheckConfidence_002(), TEST_vdyAyCheckConfidence_003()
  @traceability
	- NA
**************************************************************************** */
STATIC_MTD boolean vdyAyCheckConfidence(const VDYAyOffsData_t *ayOffs);


/* **********************************************************************
  @fn                     vdyAyCalcConfidence */ /*!
  @brief           Calculate confidence of lateral acceleration offset data

  @description     Calculates mean and deviation of histogram
                   Checks distribution and peaks
                   Sets confidence level based on the histogram quality

  @return          static void

  @param[in,out]   *pOffsAy : Ay offset data

  @glob_in         
				  - AY_SWA_OFFS_NO_CONF : No confidence level    
				  - AY_SWA_OFFS_MAX_CONF : Maximum confidence level    
				  - AY_SWA_OFFS_MID_CONF : Medium confidence level       
				  - AY_SWA_OFFS_LOW_CONF : Low confidence level
  @glob_out        None

  @c_switch_part   None
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation
				  - Calculate mean and standard deviation of histogram data
				  - Create an sorted index of histogram bin volumes
				  - Calculate median of histogram data
				  - Store last value of sorted index coresponds to bin with maximum count
				  - Initialize confidence level and Compare mean with maximum count bin
						- If Range with maximum count is close to mean
								- Check if adjacent bins of maximum have enough counts, detect the case with nearly constant angle then set best confidence AY_SWA_OFFS_MAX_CONF
								- Otherwise, driving long section with same steering wheel angle (straight or constant radius), AY_SWA_OFFS_MID_CONF
								- bin counts are normally distributed, use mean as offset value
						- Otherwise, if Range with maximum count is far away from mean, counts are not normally distributed that means that a secondary peak exists. This can be caused by driving oval circuits on proving grounds
								- Get Distance difference between maximum and secondary peak
								- Get distance difference between maximum and range around mean
										- If the count difference between secondary peak and maximum peak is big enough, blind out secondary peak by use only center around the maximum peak
												- Calculate mean around maximum peak
												- Limit confidence to avoid high status offset calibration, AY_SWA_OFFS_LOW_CONF
										- Else If Maximum distance count is not not much above the mean distance count, but median and mode are close to together, this can occur in case of large offset values, where histogram data is unsymmetric because one-sided truncation
												- Calculate mean around maximum peak
												- Use median as estimated offset
												- If Maximum value looks like a outlier, use AY_SWA_OFFS_LOW_CONF
										- Otherwise, If two peaks with rougly the same distance and ambiguous route characteristics
												- Estimation has no confidence, AY_SWA_OFFS_NO_CONF
  								
								@startuml
										start
											:Enough data for offset estimation acquired \n uint32 maxIdx \n uint32 rgSort[AY_OFFS_HIST_NO_BINS] \n VDYHistogram_t *hist = &pOffsAy->Est.Hist \n fAccel_t median;
											:Calculate mean and standard deviation of histogram data \n vdyHistCalcMeanDev(hist);
											:Create an sorted index of histgram bin volumes \n vdyHpSortInd(AY_OFFS_HIST_NO_BINS, hist->Volume, rgSort);
											:Calculate median of histogram data \n median = vdyHistCalcMedian(hist);
											:Last value of sorted index coresponds to bin with maximum count \n maxIdx = rgSort[AY_OFFS_HIST_MAX_IDX];
											:Init confidence level \n pOffsAy->Est.Conf = AY_SWA_OFFS_NO_CONF;
											if ( Compare mean with maximum count bin \n CML_f_Abs(hist->Mean - hist->Range[maxIdx]) < AY_OFFS_DIFF_MAX_MEAN ) then (Range with maximum count is close to mean)
												if (Check if adjacent bins of maximum have enough counts, detection the case with nearly constant angle \n ( CML_f_Abs(hist->Volume[maxIdx] - (hist->Volume[maxIdx-1u] + hist->Volume[maxIdx+1u])) < (AY_OFFS_FTHR_DIST_MAX_ADJ * pOffsAy->Est.ThrldDist) && ( (maxIdx > 1u) && (maxIdx < (hist->Size - 1u)) )  ) then (YES)
													:Normal route characteristics, best confidence \n pOffsAy->Est.Conf = AY_SWA_OFFS_MAX_CONF;
												else
													:Driving long section with same steering wheel angle (straight or constant radius) \n pOffsAy->Est.Conf = AY_SWA_OFFS_MID_CONF;
												endif
												:bin counts are normally distributed, use mean as offset value \n pOffsAy->Est.Offs = hist->Mean;
											else (Range with maximum count is far away from mean, counts are not normally distributed that means that a secondary peak exists. This can be caused by driving oval circuits on proving grounds)
												:Distance difference between maximum and secondary peak \n const fDistance_t distMax_c = hist->Volume[rgSort[AY_OFFS_HIST_MAX_IDX]];
												:Get distance difference between maximum and range around mean \n diffDistMaxMean = distMax_c - vdyHistGetVolume(hist, hist->Mean);
												if (If the count difference between secondary peak and maximum peak is big enough, blind out seondary peak by use only center around the maximum peak \n diffDistMaxMean > (AY_OFFS_FTHR_DIST_MAX_OUT * pOffsAy->Est.ThrldDist)) then (YES)
													:Calculate mean around maximum peak \n pOffsAy->Est.Offs = vdyHistCalcMeanCenter(hist, rgSort[AY_OFFS_HIST_MAX_IDX], VDY_THREE_U, VDY_ONE_U);
													:Limit confidence to avoid high status offset calibration \n pOffsAy->Est.Conf = AY_SWA_OFFS_LOW_CONF;
												else if (Maximum distance count is not not much above the mean distance count, but median and mode are close to together, this can occur in case of large offset values, where histogram data is unsymmetric because one-sided truncation \n
															CML_f_Abs(median - hist->Range[maxIdx]) < AY_OFFS_DIFF_MAX_MED)
													:meanCenter = vdyHistCalcMeanCenter(hist, rgSort[AY_OFFS_HIST_MAX_IDX], VDY_TEN_U, VDY_ONE_U);
													if (CML_f_Abs( meanCenter- median) < AY_OFFS_DIFF_MEAN_MED) then (YES)
														:Use median as estimated offset \n pOffsAy->Est.Offs = median;
														:Maximum value looks like a outlier, use median value instead \n pOffsAy->Est.Conf = AY_SWA_OFFS_LOW_CONF;
													endif
												else (two peaks with rougly the same distance and ambiguous route characteristics)
													:Estimation has no confidence \n pOffsAy->Est.Conf = AY_SWA_OFFS_NO_CONF;
												endif
											endif
											:return (void);
										stop
								@enduml

		- AY_OFFS_HIST_NO_BINS = 41U
		- AY_OFFS_HIST_MAX_IDX = (AY_OFFS_HIST_NO_BINS - 1U)
		- AY_SWA_OFFS_NO_CONF = 0.0F
		- AY_SWA_OFFS_MAX_CONF = 1.0F
		- AY_SWA_OFFS_MID_CONF = 0.5F
		- VDY_ONE_U = 1U
		- VDY_THREE_U = 3U
		- AY_OFFS_DIFF_MAX_MED = 0.3F
		- AY_SWA_OFFS_LOW_CONF = 0.2F
		- AY_SWA_OFFS_NO_CONF = 0.0F

  @testmethod
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c -> \n
                            TEST_vdyAyCalcConfidence_001(),
                            TEST_vdyAyCalcConfidence_002(),
                            TEST_vdyAyCalcConfidence_003(),
                            TEST_vdyAyCalcConfidence_004(),
                            TEST_vdyAyCalcConfidence_005(),
                            TEST_vdyAyCalcConfidence_006(),
                            TEST_vdyAyCalcConfidence_007()

  @traceability
  - L3
    - doors://RBGS854A:40000/?version=2&prodID=0&view=000000cd&urn=urn:telelogic::1-503e822e5ec3651e-O-290-000221c8 
    - doors://RBGS854A:40000/?version=2&prodID=0&view=000000cd&urn=urn:telelogic::1-503e822e5ec3651e-O-1519-000221c8 
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1021-00026448
**************************************************************************** */
STATIC_MTD void vdyAyCalcConfidence(VDYAyOffsData_t *pOffsAy);


/* **********************************************************************
  @fn                     vdyAyGetOffset */ /*!
  @brief           Get lat accel offset from NVM and check for plausibility

  @description     Complete NVM read operation successfully for lateral acceleration 
                   Check Stored offset value is out of range
                   Check Stored swa nvmem values are OK

  @return          static boolean

  @param[in,out]   *Offset : Ay Offset Data
  @param[in,out]   *Status : Ay Offset Status
  @param[in,out]   *Dev : Deviation

  @glob_in         
				  - VDY_ERR_STATE_ACTIVE : Indicate error state active     
				  - AY_OFFS_DEFAULT : Default value for uncalibrated swa offset 
				  - AY_STATE_DEFAULT : Ay offset state 0 non existent  
				  - VDY_ERR_STATE_INACTIVE : Indicate error state inactive
  @glob_out        None

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None 
  @post            No changes
  @InOutCorrelation
					  - If NVM read operation successfully completed
						- If stored offset value is out of range
							- Indicate error state active "false value stored in nvmemory
							- Try to correct invalid values in nv memory by overwriting with defaults
						- Otherwise, if Stored swa nvmem values are OK!
							- Indicate error state inactive "false value stored in nvmemory"
						- Data was read from Eeprom Mirror, return True
					  - Otherwise return False
  
						@startuml
								start
								:AyOffsOk = (boolean)FALSE;
								if (NVM read operation successfully completed) then (YES)
										if((lateral acceleration offset value is not inside plausible range)||((Ay offset state < AY_STATE_DEFAULT)||(Ay offset state > AY_STATE_3)))
												:Stored offset value is out of range
												 Try to correct invalid values in nv memory by overwriting with defaults
														*Offset =  AY_OFFS_DEFAULT
														*Status =  AY_STATE_DEFAULT
														*Dev    =  Deviation at that perticular Ay offset state ;
												:Indicate error state active "false" value stored in nvmemory
														errOffsRg = VDY_ERR_STATE_ACTIVE;
										else (NO)
												:Stored Ay nvm values as are OK;
												:Indicate error state inactive
														errOffsRg = VDY_ERR_STATE_INACTIVE;
										endif
										:AyOffsOk = (boolean)TRUE;
								endif
								stop
						@enduml

  @testmethod
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c -> TEST_vdyAyGetOffset_001(), TEST_vdyAyGetOffset_002(), TEST_vdyAyGetOffset_003(), TEST_vdyAyGetOffset_004(), TEST_vdyAyGetOffset_005()
  @traceability
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1015-00026448
**************************************************************************** */
STATIC_MTD boolean vdyAyGetOffset(fAccel_t *Offset, sint32 *Status, float32 *Dev );


/* **********************************************************************
  @fn               vdyAyPutNvmOffsetData */ /*!
  @brief           Store values in nonvolatile memory

  @description     Storing lateral accleration zero point offset estimation

  @return          static void

  @param[in]       Offset : Ay Offset Data
  @param[in]       Status : Ay Offset Status

  @glob_in         AY_GET_NV_WRITE_DATA : Input/Output interface
  @glob_out        None

  @c_switch_part   None 
  @c_switch_full   None

  @pre             None 
  @post            No changes
  @InOutCorrelation
					- Write lateral acceleration offset into NVM in every excution cycle
  
					@startuml
						start		
								if (check whether new Ay offset and offset state are within range) then (YES)
										: Store the new Ay offset and offset state in NMV;
										: Update Last Ay Nvm Data;
										:AyNVMerrOffsRg = VDY_ERR_STATE_INACTIVE;
								else (NO)
										:AyNVMerrOffsRg = VDY_ERR_STATE_ACTIVE;
										:keep the old value into the NVM;
								endif
						stop
					@enduml
  @testmethod
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c -> TEST_vdyAyPutNvmOffsetData_001(), TEST_vdyAyPutNvmOffsetData_002(), TEST_vdyAyPutNvmOffsetData_003()
  @traceability
	- NA
**************************************************************************** */
STATIC_MTD void vdyAyPutNvmOffsetData(fAccel_t Offset, sint32 Status);


/* **********************************************************************
  @fn                     vdyAySwaCalcOffset */ /*!
  @brief           Calculate offset

  @description     Works for both steering angle and lateral acceleration offset
                   Updates histogram with new data
                   Deletes data in case of circular driving
                   If data is accumulated over necessary distance, the histograms
                   are checked and evaluated
                   If necessary distance is not driven yet, an interim offset of the
                   lateral acceleration is calculated, the data is not cleared
                   in that case

  @return          static void

  @param[in]       *swaSen : SWA Sensor Data
  @param[in]       *aySen : Ay Sensor Data
  @param[in,out]   *swaOffs : SWA Offset Data
  @param[in,out]   *ayOffs : Ay Offset Data

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None 
  @post            No changes 
  @InOutCorrelation
				  - Calculate distance driven in this cycle
				  - Acquire data and store in histogram for offset estimation
				  - if Detected constant circular driving
								- Reset learn values due to circular driving
								- Reset integrated lateral acceleration
				  - If estimation requires a driven route with minimum distance
								- Signal no interims lateral acceleration offset calibration
								- Estimate and check reliability of offset
								- In case of sufficient confidence take over offset
				  - Otherwise,
								- Signal interims lateral acceleration offset
								- Estimate and check reliability of offset
								- In case of sufficient confidence take over offset and don't reset previous data
								- Increase distance threhold by 10000
  
						@startuml
							start		
								:Calculate distance driven in this cycle;
								:Acquire data and store in histogram for offset estimation;
								if(Detected constant circular driving) then (YES)
									:Reset learn values due to circular driving
										SWAHistReInit
										AyHistReInit;
									:Reset integrated lateral acceleration
										LatAccel = 0.0f;
								endif
									if(SWA histogram sum >= SWA threshold distance) then (YES)
										:Signal no interims lateral acceleration offset calibration 
											ayOffs->Interims =(boolean)FALSE
											p_SwaData->FastSwaOffset.Fast_Offset_State = 0.0f;
										:Estimate and check reliability of offset;
										:In case of sufficient confidence take over offset;
								else (NO)
									if(Ay histogram sum >= Ay threshold distance) then (YES)
										:Signal interims lateral acceleration offset
										ayOffs->Interims = (boolean)TRUE;
										:Estimate and check reliability of offset;
										:In case of sufficient confidence take over offset and don't reset previous data;
										:Increase distance threhold
											ayOffs->Est.ThrldDist += 10000.F;
									endif
								endif
							stop
						@enduml

  @testmethod
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c -> TEST_vdyAySwaCalcOffset_001(), TEST_vdyAySwaCalcOffset_002(), TEST_vdyAySwaCalcOffset_003(), TEST_vdyAySwaCalcOffset_004()
  @traceability
  - L3
    - doors://RBGS854A:40000/?version=2&prodID=0&view=000000cd&urn=urn:telelogic::1-503e822e5ec3651e-O-1167-000221c8 
    - doors://rbgs854a:40000/?version=2&prodID=0&view=0000012f&urn=urn:telelogic::1-503e822e5ec3651e-O-1166-000221c8
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-49-00026448
**************************************************************************** */
STATIC_MTD void vdyAySwaCalcOffset(const VDYSwaSenData_t *swaSen, const VDYAySenData_t *aySen, VDYSwaOffsData_t *swaOffs, VDYAyOffsData_t *ayOffs);


 /* **********************************************************************
  @fn                     vdyAySwaAcqEstData */ /*!
  @brief           Estimation of steering wheel angle offset

  @description     Filter front wheel velocities differences
                   Filter rear wheel velocities differences
                   Check validity condition for long term compensation

  @return          static void

  @param[in]       *swaSen : steering wheel data
  @param[in]       *aySen : lat accel data
  @param[in,out]   *swaOffs : steering wheel offset data
  @param[in]      *ayOffs : lat accel offset data
  @param[in]       cycDist : driven distance

  @c_switch_part   None 
  @c_switch_full   None

  @pre             None 
  @post            No changes 
  @InOutCorrelation
					  - Filter front and rear wheel velocities differences
					  - If long term compensation is valid then Integrate lateral acceleration to detect circular routes
					  - Accumulate driven distance
					  - If lateral acceleration calibration mode is off add lateral acceleration samples to histogram
					  - If steering wheel angle calibration mode is off add steering angle samples to histogram
  
						@startuml
							start		
								:Filter front wheel velocities differences;
								:Filter rear wheel velocities differences;
								if (( SWA_Abs < 30)&& ( (VehVelocityCorr > 10) && (Motion State != Reverse direction)) && ((WhlFrDiffFiltAbs < 0.3) && (WhlReDiffFiltAbs < 0.3 )) && (u_BankRoad == 0)) then (YES)
									:Integrate lateral acceleration to detect circular routes;
									if(SWA histogram sum <= (500.0F*1000.0F)) then (YES)
										if(state of input lateral acceleration is valid) then (YES)
											:currAccel = aySen->Ay;
											if(Lateral acceleration calibration mode is off) then (YES)
												:Add lateral acceleration samples to histogram;
											endif
										else (NO)
											:currAccel = VDY_ZERO_F;
										endif
										if (CML_f_Abs(currAccel) < 5.0f ) then (YES)
											if(steering wheel angle calibration mode is off) then (YES)
												:Add steering angle samples to histogram;
											endif
										endif
									endif
								endif
							stop
						@enduml

  @testmethod
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c -> \n
                            TEST_vdyAySwaAcqEstData_001(),
                            TEST_vdyAySwaAcqEstData_002(),
                            TEST_vdyAySwaAcqEstData_003(),
                            TEST_vdyAySwaAcqEstData_004(),
                            TEST_vdyAySwaAcqEstData_005(),
                            TEST_vdyAySwaAcqEstData_006(),
                            TEST_vdyAySwaAcqEstData_007(),
                            TEST_vdyAySwaAcqEstData_008(),
                            TEST_vdyAySwaAcqEstData_009(),
                            TEST_vdyAySwaAcqEstData_010(),
                            TEST_vdyAySwaAcqEstData_011(),
                            TEST_vdyAySwaAcqEstData_012(),
                            TEST_vdyAySwaAcqEstData_013(),
                            TEST_vdyAySwaAcqEstData_014()

  @traceability
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-787-00026448
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-788-00026448
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-789-00026448
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1016-00026448
**************************************************************************** */
STATIC_MTD void vdyAySwaAcqEstData(const VDYSwaSenData_t *swaSen, const VDYAySenData_t *aySen, VDYSwaOffsData_t *swaOffs, VDYAyOffsData_t *ayOffs, fDistance_t cycDist);  


/* **********************************************************************
  @fn               vdyAyGetOffsetDeviation */ /*!

  @brief           Assign offset standard deviation for offset state

  @description     Assign lateral accleration offset standard deviation states to lateral accleration offset state

  @return          static float32

  @param[in]       OffsState : Offset Status

  @glob_in         
				  - AY_STATE_1_DEV : Lateral accleration offset standard deviation state 1
				  - AY_STATE_2_DEV : Lateral accleration offset standard deviation state 2
				  - AY_STATE_3_DEV : Lateral accleration offset standard deviation state 3
				  - AY_STATE_0_DEV : Lateral accleration offset standard deviation state 0
  @glob_out        None

  @c_switch_part   None
  @c_switch_full   None

  @pre             None
  @post            No changes
  @InOutCorrelation 
					  - (fAccel_t) (1.0F/3.0F) for AY_STATE_0_DEV : Lateral accleration offset standard deviation state 0
					  - (fAccel_t) (0.3F/3.0F) for AY_STATE_1_DEV : Lateral accleration offset standard deviation state 1
					  - (fAccel_t) (0.1F/3.0F) for AY_STATE_2_DEV : Lateral accleration offset standard deviation state 2
					  - (fAccel_t) (0.07F/3.0F) for AY_STATE_3_DEV : Lateral accleration offset standard deviation state 3
  
						@startuml
								start
									:ret;
									if (case AY_STATE_1: OffsState == AY_STATE_1) then (yes)
											:ret = (0.3F/3.0F);
									else if (case AY_STATE_2: OffsState == AY_STATE_2) then (yes)
											:ret = (0.1F/3.0F);
								  else if (case AY_STATE_3: OffsState == AY_STATE_3) then (yes)
											:ret = (0.07F/3.0F);
								  else if (case AY_STATE_DEFAULT: OffsState == AY_STATE_DEFAULT) then (yes)
											:ret = (1.0F/3.0F);
								  else (default)
											:ret = (1.0F/3.0F);
									endif
								stop
						@enduml

  @testmethod
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c -> \n
                            TEST_vdyAyGetOffsetDeviation_001(),
                            TEST_vdyAyGetOffsetDeviation_002(),
                            TEST_vdyAyGetOffsetDeviation_003(),
                            TEST_vdyAyGetOffsetDeviation_004(),
                            TEST_vdyAyGetOffsetDeviation_005()
  @traceability
	- NA
**************************************************************************** */
STATIC_MTD float32 vdyAyGetOffsetDeviation(sint32 OffsState);


/* **********************************************************************
  @fn                     vdySwaGetPrivateData */ /*!
  @brief           Access to internal data

  @description     Allows accessing the steering wheel data from outside
                   of this module

  @param[in]              - 
  @param[out]             -
  @return          VDYSwaData_t

  @c_switch_part   None
  @c_switch_full   None

  @pre             None
  @post            No changes
  @InOutCorrelation	
					- returns VDY SWA global data
  
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c -> TEST_vdySwaGetPrivateData_001()
  @traceability			  - NA
**************************************************************************** */
VDYSwaData_t *vdySwaGetPrivateData(void);


/* **********************************************************************
  @fn                     vdyAyGetPrivateData */ /*!
  @brief                  Access to internal data

  @description            Allows accessing the lateral acceleration data from outside
                          of this module

  @param[in]              - 
  @param[out]             -
  @return                 VDYAyData_t  

  @pre                    None
  @post                   No Changes
  @InOutCorrelation
					- returns VDY Ay global data
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c -> TEST_vdyAyGetPrivateData_001()
  @traceability			  - NA
**************************************************************************** */
VDYAyData_t *vdyAyGetPrivateData(void);







/* **********************************************************************
			Unit Design for vdyAySwaExec is found in vdy.h 
**************************************************************************** */
void vdyAySwaExec(const reqVdyPrtList_t *reqPorts,const VDYInputData_t *input, VDYModIf_t *mif, const proVdyPrtList_t *proPorts)
{
  VDYSwaSenData_t  *pSwaSen   = SWA_GET_SEN_DATA;
  VDYSwaOffsData_t *pSwaOffs  = SWA_GET_OFF_DATA;
  VDYSwaData_t     *pSwaData  = SWA_GET_ME;

  VDYAySenData_t  *pAySen   = AY_GET_SEN_DATA;
  VDYAyOffsData_t *pAyOffs  = AY_GET_OFF_DATA;
  VDYAyData_t     *pAyData  = AY_GET_ME;

  pSwaData->Io.in          = input;
  pSwaData->Io.mif         = mif;
  pSwaData->Io.NVMerrOffsRg   = &proPorts->pVDYErrors->OutPutErrors.NVMSwaOffsRg;
  proPorts->pVDYErrors->OutPutErrors.NVMSwaOffsRg  = VDY_ERR_STATE_UNKNOWN;
#if ( (defined(CFG_VDY_NVM_LEARN_DATA_ERROR)) && (CFG_VDY_NVM_LEARN_DATA_ERROR) )
  /* check for valid values written into NVM */
  pSwaData->Io.SwaNVMErrOffsRg   = &proPorts->pVDYErrors->OutPutErrors.SwaNVMOffsRg;
  proPorts->pVDYErrors->OutPutErrors.SwaNVMOffsRg  = VDY_ERR_STATE_UNKNOWN;
#endif

  pSwaData->Io.errOffsRg   = &proPorts->pVDYErrors->OutPutErrors.SwaOffsRg;
  proPorts->pVDYErrors->OutPutErrors.SwaOffsRg  = VDY_ERR_STATE_UNKNOWN;

  pAyData->Io.in           = input;
  pAyData->Io.mif          = mif;
  pAyData->Io.nv_read      = reqPorts->pNVMRead;
  pAyData->Io.nv_write     = proPorts->pNVMWrite;
  /* Note: if online out of range error should also detect for lateral acceleration
           rename the errOffsRg to NVMerrOffsRg similar to the swa errors */
  pAyData->Io.errOffsRg    = &proPorts->pVDYErrors->OutPutErrors.NVMAyOffsRg;
  proPorts->pVDYErrors->OutPutErrors.NVMAyOffsRg   = VDY_ERR_STATE_UNKNOWN;
#if ( (defined(CFG_VDY_NVM_LEARN_DATA_ERROR)) && (CFG_VDY_NVM_LEARN_DATA_ERROR) )
  /* check for valid values written into NVM */
  pAyData->Io.AyNVMerrOffsRg  = &proPorts->pVDYErrors->OutPutErrors.AyNVMOffsRg;
  proPorts->pVDYErrors->OutPutErrors.AyNVMOffsRg   = VDY_ERR_STATE_UNKNOWN;
#endif


  /* Distinction between different operating states */
#if (!CFG_VDY_MFC)
    if (VDY_CTRL_GET_STATE((VDYCtrlState_t)VDY_CTRL_STATE_RUNNING, input->Frame.CtrlMode))
#else
    if (VDY_CTRL_GET_STATE( (BaseOpMode_t)BASE_OM_RUN, input->Frame.OpMode) )
#endif
  {
    /*<--- Execution path for normal operating mode --->*/
  
    /* Upload offset form nv memory to internal nvm offset buffer */
    #if( (!defined(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))||(!CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK)) 
    if (VDY_GET_NVM_IO_STATE(VDY_NVM_POS_SWA, &reqPorts->pNVMRead->State) == VDY_IO_STATE_VALID)
    #endif
    {
      vdySwaNvmReadOffset(&pSwaData->NVValue, &reqPorts->pNVMRead->StWhlAng ,reqPorts->pNVMRead->State);
    }
    
    /* Read steering wheel angle signal */
    pSwaSen->StrgAngle = SWA_GET_INP_SIGNALS->StWheelAngle;
    pSwaSen->Valid     = (boolean) ((VDY_GET_IO_STATE(VDY_SIN_POS_SWA, SWA_GET_INP_SIGNALS->State)==(VDYIoStateTypes_t)VDY_IO_STATE_VALID) ? TRUE : FALSE);
   
    /* Read lateral acceleration sensor signal */
    pAySen->Ay        = AY_GET_INP_SIGNALS->LatAccel;
    pAySen->Valid     = (boolean) ((VDY_GET_IO_STATE(VDY_SIN_POS_LATA, AY_GET_INP_SIGNALS->State)==(VDYIoStateTypes_t)VDY_IO_STATE_VALID) ? TRUE : FALSE);
    
    /* Get non volatile start values */
    vdySwaGetOffsetStart(pSwaOffs);
    vdyAyGetOffsetStart(pAyOffs);

    /* Check validity of lateral acceleration sensor */
    if (pAySen->Valid != (boolean)FALSE)
    {
      /* Calculate gradient */
      pAySen->Gradient = vdyCalcGradient(pAySen->Ay, pAySen->AyOld);
      pAySen->AyOld    = pAySen->Ay;
    }
#if( (defined(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))&&(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))
	{
	  /* PRQA S 1840, 4542, 1841 EOF */
	  /* date: 2019-06-10, reviewer: Yogesh Ghongade (uidj8380), reason: Not in Scope of VDY */
	  VDY_SET_NVM_IO_STATE(VDY_NVM_POS_LATACC, VDY_IO_STATE_INVALID, &proPorts->pNVMWrite->State);
	}
#endif    
    /* Check validity of steering wheel angle sensor */
    if (pSwaSen->Valid != (boolean)FALSE )
    {
      /* Calculate gradient */
      pSwaSen->Gradient     = vdyCalcGradient(pSwaSen->StrgAngle,pSwaSen->StrgAngleOld);
      pSwaSen->StrgAngleOld = pSwaSen->StrgAngle;

      /* Start calculation of steering wheel angle and lateral acceleration sensor offset */
      vdyAySwaCalcOffset(pSwaSen, pAySen, pSwaOffs, pAyOffs);

      /* Export to module interface */
      mif->SwaOffset.offset   = pSwaOffs->StrgOffset;
      mif->SwaOffset.state    = (uint8)pSwaOffs->OffsState;
      mif->SwaOffset.var      = SQR(pSwaOffs->Dev);
    
      mif->AyOffset.offset   = pAyOffs->AyOffset;
      mif->AyOffset.state    = (uint8)pAyOffs->OffsState;
      mif->AyOffset.var      = SQR(pAyOffs->Dev);
    }

    { 
      /* If necessary, write new offset to non volatile memory */
      VDYIoState_t ioState;
      
      /* Test if write access is required and copy data */
      ioState = vdySwaNvmWriteOffset(&pSwaData->NVValue, &proPorts->pNVMWrite->StWhlAng);
      
      /* Set non-volatile */
      /* <ln_offset:+2 PCLINT Error 845: reviewer name: Jochen Spruck date: 11-11-2010 reason: proven in use, error because of first state mask is zero */
      /* <ln_offset:+1 PCLINT Error 835: reviewer name: Jochen Spruck date: 11-11-2010 reason: proven in use, error because of first state mask is zero */
	  /* PRQA S 2985 EOF */
	  /* date: 2019-06-10, reviewer: Yogesh Ghongade (uidj8380), reason: Not in Scope of VDY */
      VDY_SET_NVM_IO_STATE(VDY_NVM_POS_SWA, ioState, &proPorts->pNVMWrite->State);
    }
#if( (defined(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))&&(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))
	{
	  VDYNvIoData_t   *nvm      = AY_GET_NV_WRITE_DATA;
     /* writing Ay offset into NVM in every excution cycle */
      nvm->LatAcc.ZeroAccel = LastAyNvmData.ZeroAngle;
      nvm->LatAcc.CalStatus = LastAyNvmData.CalStatus;
	}
#endif

  }
  else
  {
    /*<--- Execution path for initialization mode  --->*/

    vdySwaInitVolatile(pSwaData);
    vdyAyInitVolatile(pAyData);
  }

  return;
}


/* **********************************************************************
			Unit Design for vdyAySwaInit is found in vdy.h 
**************************************************************************** */
void vdyAySwaInit(const reqVdyPrtList_t *reqPorts, const proVdyPrtList_t *proPorts)

{
  VDYSwaData_t *pSwaData = SWA_GET_ME;
  VDYAyData_t *pAyData   = AY_GET_ME;

  /* Initialzation of steering wheel angle data */
  vdySwaInitVolatile(pSwaData);
  vdySwaInitOffset(&pSwaData->Offset, &pSwaData->NVValue);

  /* Initialzation of lateral acceleration data */
  vdyAyInitVolatile(pAyData);
  vdyAyInitOffset(&pAyData->Offset);

  #if( (defined(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))&&(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))

  {
    VDYIoState_t ioStateSwa;
    VDYIoState_t ioStateAy;
    if(reqPorts->pNVMRead->State == SWA_NVM_CLEARED)
    {
      LastSwaNvmData.ZeroAngle       = SWA_ANG_OFFS_DEFAULT;
      LastSwaNvmData.CalStatus       = (uint32)SWA_STATE_DEFAULT;
      proPorts->pNVMWrite->StWhlAng.ZeroAngle = SWA_ANG_OFFS_DEFAULT;
      proPorts->pNVMWrite->StWhlAng.CalStatus = (uint32)SWA_STATE_DEFAULT;

      LastAyNvmData.ZeroAngle        = AY_OFFS_DEFAULT;
      LastAyNvmData.CalStatus       = (uint32)AY_STATE_DEFAULT;
      proPorts->pNVMWrite->LatAcc.ZeroAccel = AY_OFFS_DEFAULT;
      proPorts->pNVMWrite->LatAcc.CalStatus = (uint32)AY_STATE_DEFAULT;
    }
    else
    {
      /* SWA offset writing in init mode */
      LastSwaNvmData.ZeroAngle       = reqPorts->pNVMRead->StWhlAng.ZeroAngle;
      LastSwaNvmData.CalStatus       = reqPorts->pNVMRead->StWhlAng.CalStatus;
      proPorts->pNVMWrite->StWhlAng.ZeroAngle = reqPorts->pNVMRead->StWhlAng.ZeroAngle;
      proPorts->pNVMWrite->StWhlAng.CalStatus = reqPorts->pNVMRead->StWhlAng.CalStatus;
      ioStateSwa = VDY_GET_NVM_IO_STATE(VDY_NVM_POS_SWA, &reqPorts->pNVMRead->State);
	  /* PRQA S 2986 EOF */
	  /* date: 2019-06-10, reviewer: Yogesh Ghongade (uidj8380), reason: Not in Scope of VDY */
      VDY_SET_NVM_IO_STATE(VDY_NVM_POS_SWA, ioStateSwa, &proPorts->pNVMWrite->State);

      /* Ay offset writing in init mode */
      LastAyNvmData.ZeroAngle        = reqPorts->pNVMRead->LatAcc.ZeroAccel;
      LastAyNvmData.CalStatus       = reqPorts->pNVMRead->LatAcc.CalStatus;
      proPorts->pNVMWrite->LatAcc.ZeroAccel = reqPorts->pNVMRead->LatAcc.ZeroAccel;
      proPorts->pNVMWrite->LatAcc.CalStatus = reqPorts->pNVMRead->LatAcc.CalStatus;
      ioStateAy = VDY_GET_NVM_IO_STATE(VDY_NVM_POS_LATACC, &reqPorts->pNVMRead->State);
      VDY_SET_NVM_IO_STATE(VDY_NVM_POS_LATACC, ioStateAy, &proPorts->pNVMWrite->State);
    }
  }
  #else
    (void)proPorts; /* remove compiler warning, proPorts is not used in this configuration */
    (void)reqPorts;  /* remove compiler warning, reqPorts is not used in this configuration */

  #endif

  return;
}


/* **********************************************************************
	Unit Design for vdySwaGetOffsetDeviation is found in Declaration Section
**************************************************************************** */
STATIC_MTD float32 vdySwaGetOffsetDeviation(sint32 OffsState)
{
  float32 ret;
  
  switch(OffsState)
  {
    case SWA_STATE_1:
      ret = SWA_STATE_1_DEV;
      break;

    case SWA_STATE_2:
      ret = SWA_STATE_2_DEV;
      break;

    case SWA_STATE_3:
      ret = SWA_STATE_3_DEV;
      break;

    case SWA_STATE_4:
      ret = SWA_STATE_4_DEV;
      break;

    case SWA_STATE_5:
      ret = SWA_STATE_5_DEV;
      break;

    case SWA_STATE_6:
      ret = SWA_STATE_6_DEV;
      break;

    case SWA_STATE_DEFAULT:
    default:
      ret = SWA_STATE_0_DEV;
      break;
  }
  return ret;
}


/* **********************************************************************
	Unit Design for vdyAyGetOffsetDeviation is found in Declaration Section
**************************************************************************** */
STATIC_MTD float32 vdyAyGetOffsetDeviation(sint32 OffsState)
{
  float32 ret;
  
  switch(OffsState)
  {
    case AY_STATE_1:
      ret = AY_STATE_1_DEV;
      break;

    case AY_STATE_2:
      ret = AY_STATE_2_DEV;
      break;

    case AY_STATE_3:
      ret = AY_STATE_3_DEV;
      break;

    case AY_STATE_DEFAULT:
    default:
      ret = AY_STATE_0_DEV;
      break;

  }
  return ret;
}


/* **********************************************************************
	Unit Design for vdySwaGetPrivateData is found in Declaration Section
**************************************************************************** */
VDYSwaData_t *vdySwaGetPrivateData(void)
{
  return (SWA_GET_ME);
}


/* **********************************************************************
	Unit Design for vdyAyGetPrivateData is found in Declaration Section
**************************************************************************** */
VDYAyData_t *vdyAyGetPrivateData(void)
{
  return (AY_GET_ME);
}


#if (CFG_VDY_YW_DYN_AVG)
/* **********************************************************************
	Unit Design for vdySwaCheckOffsetGoodEnough is found in vdy.h
**************************************************************************** */
boolean vdySwaCheckOffsetGoodEnough(void)
{
  boolean ret;

  VDYSwaSenData_t *sen   = SWA_GET_SEN_DATA;
  VDYSwaOffsData_t *offs = SWA_GET_OFF_DATA;

  if (   (sen->Valid==(boolean)FALSE) 
      || (offs->OffsState > SWA_STATE_6) 
      || (offs->OffsState < SWA_STATE_2) )
  {
    ret = (boolean)FALSE;
  }
  else
  {
    ret = (boolean)TRUE;
  }
  return ret;
}
#endif /* CFG_VDY_YW_DYN_AVG */


/* **********************************************************************
	Unit Design for vdySwaIsValid is found in vdy.h
**************************************************************************** */
boolean vdySwaIsValid(void)
{
  VDYSwaSenData_t *StrgData = SWA_GET_SEN_DATA;

  return (StrgData->Valid);
}


/* **********************************************************************
	Unit Design for vdySwaGetOffsData is found in vdy.h
**************************************************************************** */
const VDYSwaOffsData_t *vdySwaGetOffsData (void)
{
  return (SWA_GET_OFF_DATA);
}


/* **********************************************************************
	Unit Design for vdySwaNvmWriteOffset is found in Declaration Section
**************************************************************************** */
STATIC_MTD VDYIoState_t vdySwaNvmWriteOffset(VDYSwaOffsEEprom_t  *NVValue, VDYNvStWhlAngCal_t *nvout)
{
  VDYIoState_t State = VDY_IO_STATE_INVALID;
  
  if(NVValue->EEPromWriteRequ == (boolean)TRUE)
  {
#if ( (defined(CFG_VDY_NVM_LEARN_DATA_ERROR)) && (CFG_VDY_NVM_LEARN_DATA_ERROR) )
  /* check for valid values written into NVM */
  if (((vdySwaOffsetRangeOk(NVValue->EEPromStrgOffs.Offset) == (boolean)TRUE)) && ((NVValue->EEPromStrgOffs.State >= SWA_STATE_DEFAULT) && (NVValue->EEPromStrgOffs.State <= SWA_STATE_6)))
   {
#endif
    nvout->ZeroAngle = NVValue->EEPromStrgOffs.Offset;
    nvout->CalStatus = (uint32)NVValue->EEPromStrgOffs.State;

#if( (defined(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))&&(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))
	/* Storing the New Offset value in the Variable to update for every VDY cycle */
	LastSwaNvmData.ZeroAngle = NVValue->EEPromStrgOffs.Offset;
	LastSwaNvmData.CalStatus = (uint32)NVValue->EEPromStrgOffs.State;
#endif

    State = VDY_IO_STATE_VALID;
    NVValue->EEPromWriteRequ =(boolean)FALSE;
#if ( (defined(CFG_VDY_NVM_LEARN_DATA_ERROR)) && (CFG_VDY_NVM_LEARN_DATA_ERROR) )
    /* check for valid values written into NVM */
    SWA_SET_NVM_ERR_OFFS_RG = (VDY_ERR_STATE_INACTIVE);
   }
  else
   {
    SWA_SET_NVM_ERR_OFFS_RG = (VDY_ERR_STATE_ACTIVE);
    /*keep the old value into the NVM */
   }
#endif
  }
#if( (defined(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))&&(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))
  else
  {
    nvout->ZeroAngle = LastSwaNvmData.ZeroAngle;
    nvout->CalStatus = LastSwaNvmData.CalStatus;
  }
#endif
  return State;
}


/* **********************************************************************
	Unit Design for vdySwaNvmReadOffset is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdySwaNvmReadOffset(VDYSwaOffsEEprom_t  *NVValue, const VDYNvStWhlAngCal_t *nvin , uint32 status)
{
  if (NVValue->EEPromReadOk == (boolean)FALSE)
  {
    if(status == SWA_NVM_CLEARED)
    {
      /* Set the offset and state to Default Values since NVM is crashed/Erased */
      NVValue->EEPromStrgOffs.Offset = SWA_ANG_OFFS_DEFAULT;
      NVValue->EEPromStrgOffs.State = SWA_STATE_DEFAULT;
    }
    else
	{
      /* Upload data from nvmemory */
      NVValue->EEPromStrgOffs.Offset = nvin->ZeroAngle;
      NVValue->EEPromStrgOffs.State = (sint32)nvin->CalStatus;
	}
#if( (defined(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))&&(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))
    /* store the Read NVM value as the initial value of Last NVM value*/
    LastSwaNvmData.ZeroAngle = NVValue->EEPromStrgOffs.Offset;
    LastSwaNvmData.CalStatus = (uint32)NVValue->EEPromStrgOffs.State;
#endif
    
	NVValue->EEPromStrgOffs.Dev = vdySwaGetOffsetDeviation(NVValue->EEPromStrgOffs.State);
    NVValue->EEPromReadOk = (boolean)TRUE;
  }
  return;
}


/* **********************************************************************
	Unit Design for vdySwaInitOffsEepromMirror is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdySwaInitOffsEepromMirror(VDYSwaOffsEEprom_t  *NVValue)
{
  NVValue->EEPromStrgOffs.Offset = VDY_ZERO_F;
  NVValue->EEPromStrgOffs.Dev    = SWA_STATE_0_DEV;
  NVValue->EEPromStrgOffs.State  = SWA_STATE_DEFAULT;
  NVValue->EEPromWriteRequ       = (boolean)FALSE;
  NVValue->EEPromReadOk          = (boolean)FALSE;

  return;
}


/* **********************************************************************
	Unit Design for vdySwaInitSenData is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdySwaInitSenData(VDYSwaSenData_t *pSwaSen)
{
  pSwaSen->StrgDeltaDist         = VDY_ZERO_F;
  pSwaSen->Gradient              = VDY_ZERO_F;
  pSwaSen->StrgGradAbsOld        = VDY_ZERO_F;
  pSwaSen->StrgAngle             = VDY_ZERO_F;
  pSwaSen->StrgAngleOld          = VDY_ZERO_F;
  pSwaSen->Valid                 = (boolean)FALSE;

  return;
}


/* **********************************************************************
	Unit Design for vdySwaInitOffsEst is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdySwaInitOffsEst(VDYSwaOffsEst_t *OffsEst)
{
  const float32 maxRg_c = (( (float32)((uint32)((float32)SWA_OFFS_HIST_NO_BINS / 2.0F))) + 0.5F) * SWA_OFFSET_HIST_WIDTH; 
  
  OffsEst->Offs = VDY_ZERO_F;
  
  /* Initialize estimation results */
  OffsEst->ThrldDev          =  SWA_DEV_HIST_STAT_DEFAULT;
  OffsEst->ThrldDist         =  SWA_DIST_SAMP_STAT_DEFAULT;
  OffsEst->Conf              =  VDY_ZERO_F;

  /* Setup histogram data base */
  vdyHistInit(&OffsEst->Hist, OffsEst->Bin.Range, OffsEst->Bin.Volume, SWA_OFFS_HIST_NO_BINS, -maxRg_c, maxRg_c);

  return;
}


/* **********************************************************************
	Unit Design for vdySwaInitOffsData is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdySwaInitOffsData(VDYSwaOffsData_t *SwaOffs)
{
  SwaOffs->StrgOffsReadOk        = (boolean)FALSE;
  SwaOffs->StrgOffset            = SWA_ANG_OFFS_DEFAULT;
  SwaOffs->StrgOffsetNorm        = VDY_ZERO_F;
  SwaOffs->OffsState             = SWA_STATE_DEFAULT;
  SwaOffs->Dev                   = SWA_STATE_0_DEV;
  SwaOffs->OvrTakeCntr           = VDY_ZERO_U;
  SwaOffs->WhlFrDiffFilt         = VDY_ZERO_F;
  SwaOffs->WhlReDiffFilt         = VDY_ZERO_F;
  SwaOffs->LatAccel              = VDY_ZERO_F;

  SwaOffs->OffsInterimOk         = (boolean)FALSE;
  SwaOffs->ErrStrgOffsOutOfRange = (boolean)FALSE;
  SwaOffs->ReInitCntr            = VDY_ZERO_U;
  
  vdySwaInitOffsEst(&SwaOffs->Est);

  return;
}


/* **********************************************************************
	Unit Design for vdySwaInitVolatile is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdySwaInitVolatile(VDYSwaData_t *pSwaData)
{
  vdySwaInitSenData(&pSwaData->Sensor);
  /* PRQA S 0315 EOF */
  /* date: 2019-06-10, reviewer: Yogesh Ghongade (uidj8380), reason: Functional Safe */
  (void)vdy_memset_s(&pSwaData->FastSwaOffset, 0x00, sizeof(s_VDYFastSwaOffset_t));

    /* Init error states */
  pSwaData->Io.errOffsRg  = NULL;
  pSwaData->Io.NVMerrOffsRg  = NULL;
#if ( (defined(CFG_VDY_NVM_LEARN_DATA_ERROR)) && (CFG_VDY_NVM_LEARN_DATA_ERROR) )
  /* check for valid values written into NVM */
  pSwaData->Io.SwaNVMErrOffsRg  = NULL;
#endif

  return;
}


/* **********************************************************************
	Unit Design for vdySwaInitOffset is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdySwaInitOffset(VDYSwaOffsData_t  *Offset, VDYSwaOffsEEprom_t  *NVValue)
{
  vdySwaInitOffsEepromMirror(NVValue);

  vdySwaInitOffsData(Offset);

  return;
}


/* **********************************************************************
	Unit Design for vdyAyInitSenData is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyAyInitSenData(VDYAySenData_t *pAySen)
{
  pAySen->Ay             = VDY_ZERO_F;
  pAySen->AyOld          = VDY_ZERO_F;

  pAySen->AyGradAbsOld   = VDY_ZERO_F;
  pAySen->Gradient       = VDY_ZERO_F;

  pAySen->Valid          = (boolean)FALSE;

  return;
}


/* **********************************************************************
	Unit Design for vdyAyInitOffsEst is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyAyInitOffsEst(VDYAyOffsEst_t *pAyOffsEst)
{
  const float32 maxRg_c = (( (float32)((uint32)((float32)AY_OFFS_HIST_NO_BINS/ 2.0F))) + 0.5F) * AY_OFFSET_HIST_WIDTH; 

  pAyOffsEst->Offs = VDY_ZERO_F;

  pAyOffsEst->ThrldDev          =  AY_DEV_SAMP_STAT_DEFAULT;
  pAyOffsEst->ThrldDist         =  AY_DIST_SAMP_STAT_DEFAULT;
  pAyOffsEst->Conf              =  VDY_ZERO_F;

  vdyHistInit(&pAyOffsEst->Hist, pAyOffsEst->Bin.Range, pAyOffsEst->Bin.Volume, AY_OFFS_HIST_NO_BINS, -maxRg_c, maxRg_c);

  return;
}


/* **********************************************************************
	Unit Design for vdyAyInitOffsData is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyAyInitOffsData(VDYAyOffsData_t *pAyOffs)
{
  pAyOffs->AyOffset     = VDY_ZERO_F;
  pAyOffs->Dev          = AY_STATE_0_DEV;
  pAyOffs->OffsState    = AY_STATE_DEFAULT;
  pAyOffs->OvrTakeCntr  = VDY_ZERO_U;
  pAyOffs->Interims     = (boolean)FALSE;
  pAyOffs->AyOffsReadOk = (boolean)FALSE;

  vdyAyInitOffsEst(&pAyOffs->Est);

  return;
}


/* **********************************************************************
	Unit Design for vdyAyInitVolatile is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyAyInitVolatile(VDYAyData_t *pAyData)
{
  vdyAyInitSenData(&pAyData->Sensor);

  /* Init error states */
  pAyData->Io.errOffsRg = NULL;
  pAyData->Io.NVMerrOffsRg = NULL;
#if ( (defined(CFG_VDY_NVM_LEARN_DATA_ERROR)) && (CFG_VDY_NVM_LEARN_DATA_ERROR) )
    /* check for valid values written into NVM */
  pAyData->Io.AyNVMerrOffsRg = NULL;
#endif


  return;
}


/* **********************************************************************
	Unit Design for vdyAyInitOffset is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyAyInitOffset(VDYAyOffsData_t  *pAyOffset)
{
  vdyAyInitOffsData(pAyOffset);

  return;
}


/* **********************************************************************
	Unit Design for vdySwaEvalThrdDist is found in Declaration Section
**************************************************************************** */
STATIC_MTD fDistance_t vdySwaEvalThrdDist(sint32 Status)
{
  fDistance_t reqDist;     /* required distance */

  switch (Status)
  {
    case (SWA_STATE_1):
      /* Run-up phase */ 
      reqDist = SWA_DIST_SAMP_STAT_1;
      break;

    case (SWA_STATE_2):
      /* Run-up phase */ 
      reqDist = SWA_DIST_SAMP_STAT_2;
      break;

    case (SWA_STATE_3):
      /* Run-up phase */ 
      reqDist = SWA_DIST_SAMP_STAT_3;
      break;

    case (SWA_STATE_4):
      /* Relearn phase */
      reqDist = SWA_DIST_SAMP_STAT_4;
      break;

    case (SWA_STATE_5):
      /* Confirmation phase */
      reqDist = SWA_DIST_SAMP_STAT_5;
      break;

    case (SWA_STATE_6):
      /* Confirmation phase */
      reqDist = SWA_DIST_SAMP_STAT_6;
      break;

    default:
      reqDist = SWA_DIST_SAMP_STAT_DEFAULT;
      break;
  }

  return (reqDist);
}


/* **********************************************************************
	Unit Design for vdySwaEvalThrdDeviation is found in Declaration Section
**************************************************************************** */
STATIC_MTD fAngle_t vdySwaEvalThrdDeviation(sint32 Status)
{
  fAngle_t Angle;

  switch (Status)
  {
    case (SWA_STATE_1):
    case (SWA_STATE_2):
    case (SWA_STATE_3):
      
      /* Run-up phase */ 
      Angle = SWA_DEV_HIST_STAT_STARTUP;
      break;

    case (SWA_STATE_4):
    case (SWA_STATE_5):
    case (SWA_STATE_6):
      
      /* Confirmation phase */
      Angle = SWA_DEV_HIST_STAT_NORMAL;
      break;

    default:
      Angle = SWA_DEV_HIST_STAT_STARTUP;
      break;
  }

  return (Angle);
}


/* **********************************************************************
	Unit Design for vdyAyEvalThrdDist is found in Declaration Section
**************************************************************************** */
STATIC_MTD fDistance_t vdyAyEvalThrdDist(sint32 Status)
{
  fDistance_t reqDist;     /* required distance */

  switch (Status)
  {
    case (AY_STATE_1):
      /* Run-up phase */ 
      reqDist = AY_DIST_SAMP_STAT_1;
      break;

    case (AY_STATE_2):
      /* Run-up phase */ 
      reqDist = AY_DIST_SAMP_STAT_2;
      break;

    case (AY_STATE_3):
      /* Learn and relearn state */ 
      reqDist = AY_DIST_SAMP_STAT_3;
      break;

    default:
      reqDist = AY_DIST_SAMP_STAT_DEFAULT;
      break;
  }

  return (reqDist);
}


/* **********************************************************************
	Unit Design for vdyAyEvalThrdDeviation is found in Declaration Section
**************************************************************************** */
STATIC_MTD fAccel_t vdyAyEvalThrdDeviation(sint32 Status)
{
  fAccel_t Accel;            

  switch (Status)
  {
    case (AY_STATE_1):
    case (AY_STATE_2):
      /* Run-up phase */ 
      Accel = AY_DEV_SAMP_STAT_STARTUP;
      break;
    
    case (AY_STATE_3):
      /* Learn and relearn phase  */
      Accel = AY_DEV_SAMP_STAT_NORMAL;
      break;
      
    default:
      Accel = AY_DEV_SAMP_STAT_DEFAULT;
      break;
  }

  return (Accel);
}


/* **********************************************************************
	Unit Design for vdySwaOffsetRangeOk is found in Declaration Section
**************************************************************************** */
STATIC_MTD boolean vdySwaOffsetRangeOk(fAngle_t Offset)
{
  fAngle_t StrgAngOffsNorm;
  boolean   StrgOffsOk      = (boolean)FALSE; 

  /* norm offset */
  StrgAngOffsNorm = vdyDiscretize(Offset, SWA_OFFS_NORM_RES);

  /* check the offset range */
  if (CML_f_Abs(StrgAngOffsNorm) <= VDY_PAR_SWA_OFFSET_LIMIT_MAX)
  {
    /* offset within range  */
    StrgOffsOk = (boolean)TRUE;
  } 
  else
  {
    /* offset outside of range */
    StrgOffsOk = (boolean)FALSE;
  }

  return (StrgOffsOk);
}


/* **********************************************************************
	Unit Design for vdyAyOffsetRangeOk is found in Declaration Section
**************************************************************************** */
STATIC_MTD boolean vdyAyOffsetRangeOk(fAccel_t Offset)
{
  boolean AyOffsOk = (boolean)FALSE; 

  /* Verfiy that offset value is inside plausible range */
  if (CML_f_Abs(Offset) <= AY_OFFSET_LIMIT_MAX)
  {
    /* Offset value is ok */
    AyOffsOk = (boolean)TRUE;
  } 

  return AyOffsOk;
}


/* **********************************************************************
	Unit Design for vdySwaPutEepromOffsetData is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdySwaPutEepromOffsetData(fAngle_t Offset, sint32 Status ,float32 Dev)
{
  VDYSwaOffsEEprom_t *StrgOffsEEprom = SWA_GET_NV_DATA; /* Zugriff auf EEProm-Mirror */

  /* LW-Offset in EEProm-Mirror kopieren */
  StrgOffsEEprom->EEPromStrgOffs.Offset = Offset;
  StrgOffsEEprom->EEPromStrgOffs.State  = Status;
  StrgOffsEEprom->EEPromStrgOffs.Dev    = Dev;
 
  /* Leseanforderung setzen, abspeichern des Eeprom-Mirrors */
  StrgOffsEEprom->EEPromWriteRequ       = (boolean)TRUE; 

  return;
}


/* **********************************************************************
	Unit Design for vdyAyPutNvmOffsetData is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyAyPutNvmOffsetData(fAccel_t Offset, sint32 Status)
{
  VDYNvIoData_t *nvm = AY_GET_NV_WRITE_DATA;
#if ( (defined(CFG_VDY_NVM_LEARN_DATA_ERROR)) && (CFG_VDY_NVM_LEARN_DATA_ERROR) )
  /* check for valid values written into NVM */
  if ((vdyAyOffsetRangeOk(Offset) == (boolean)TRUE) && ( (Status >= AY_STATE_DEFAULT) && (Status <= AY_STATE_3 )))
   {
#endif
  nvm->LatAcc.ZeroAccel = Offset;
  nvm->LatAcc.CalStatus = (uint32) Status;

  #if( (defined(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))&&(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))
/* writing Ay offset into NVM in every excution cycle */
  LastAyNvmData.ZeroAngle	= Offset;
  LastAyNvmData.CalStatus	= (uint32) Status;
  #endif

  /* <ln_offset:+2 PCLINT Error 845: reviewer name: Jochen Spruck date: 11-11-2010 reason: proven in use, error because state value is zero */
  /* <ln_offset:+1 PCLINT Error 835: reviewer name: Jochen Spruck date: 11-11-2010 reason: proven in use, error because state value is zero */
  VDY_SET_NVM_IO_STATE(VDY_NVM_POS_LATACC, VDY_IO_STATE_VALID, &nvm->State);
#if ( (defined(CFG_VDY_NVM_LEARN_DATA_ERROR)) && (CFG_VDY_NVM_LEARN_DATA_ERROR) )
    /* check for valid values written into NVM */
    AY_SET_ERR_OFFS_RG = (VDY_ERR_STATE_INACTIVE);
   }
   else
   {
    AY_SET_ERR_OFFS_RG = (VDY_ERR_STATE_ACTIVE);
    /*keep the old value into the NVM */ 
   }
#endif
  return;
}


/* **********************************************************************
	Unit Design for vdyAyGetNvmOffsetData is found in Declaration Section
**************************************************************************** */
STATIC_MTD boolean vdyAyGetNvmOffsetData(fAccel_t *Offset, sint32 *Status, float32 *Dev)
{
  const VDYNvIoData_t *nvm = AY_GET_NV_READ_DATA;
  boolean ret = (boolean)FALSE;

#if( !(defined(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))||(!CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))
  if (VDY_GET_NVM_IO_STATE(VDY_NVM_POS_LATACC, &nvm->State ) == VDY_IO_STATE_VALID)
#endif
  {
    /* NVM read operation successfully completed */
    if(nvm->State == SWA_NVM_CLEARED)
    {
      *Offset = AY_OFFS_DEFAULT;
      *Status = AY_STATE_DEFAULT;
    }
   else
   {
     *Offset = nvm->LatAcc.ZeroAccel;
     *Status = (sint32) nvm->LatAcc.CalStatus;
   }
  *Dev    = vdyAyGetOffsetDeviation(*Status);
#if( (defined(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))&&(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))
/* writing Ay offset into NVM in every excution cycle */
  LastAyNvmData.ZeroAngle = *Offset;
  LastAyNvmData.CalStatus = (uint32)*Status;
#endif
    ret = (boolean)TRUE;
  }
  return ret;
}


/* **********************************************************************
	Unit Design for vdySwaGetOffset is found in Declaration Section
**************************************************************************** */
STATIC_MTD boolean vdySwaGetOffset(fAngle_t *Offset, sint32 *Status, float32 *Dev )
{
  boolean StrgOffsOk = (boolean)FALSE;
  VDYSwaOffsEEprom_t *StrgOffsEEprom = SWA_GET_NV_DATA; /* Zugriff auf EEProm-Mirror */

  /* Set StrgOffs, StrgStatus, StrgDev to init values.  If NVM access fails, */
  /* these default values are used and not the NVM values */
  *Offset =  SWA_ANG_OFFS_DEFAULT;
  *Status =  SWA_STATE_DEFAULT;
  *Dev    =  SWA_STATE_0_DEV;

  if (StrgOffsEEprom->EEPromReadOk == (boolean)TRUE)
  {
    /* Read operation successfully completed */
    if ((vdySwaOffsetRangeOk(StrgOffsEEprom->EEPromStrgOffs.Offset) != (boolean)TRUE))
    {
      /* Stored offset value is out of range */

      /* Indicate error state active "false value stored in nvmemory "*/
      SWA_GET_NVM_ERR_OFFS_RG = (VDY_ERR_STATE_ACTIVE);

      /* Try to correct invalid values in nv memory by overwriting with defaults */
      vdySwaPutEepromOffsetData(*Offset, *Status , *Dev);
    }
    else if (   (StrgOffsEEprom->EEPromStrgOffs.State < SWA_STATE_DEFAULT)
             || (StrgOffsEEprom->EEPromStrgOffs.State > SWA_STATE_6) )
    {
      /* Stored offset state is out of range  */
      
      /* @todo Indicate error state active "false state stored in nvmemory */
      SWA_GET_NVM_ERR_OFFS_RG = (VDY_ERR_STATE_ACTIVE);
      /* (void) ERRCheckForErrorTaskingActive(TRUE, ERR_LP_STRG_OFFS_READ_EEPR_UNKNOWN_STATUS); */

      /* Try to correct invalid values in nv memory by overwriting with defaults */
      vdySwaPutEepromOffsetData(*Offset, *Status, *Dev);
    }
    else
    {
      /* Stored swa nvmem values are OK! */
      
      /* LW-Offset aus EEProm in Applikation kopieren */
      *Offset    = StrgOffsEEprom->EEPromStrgOffs.Offset;
      *Status    = StrgOffsEEprom->EEPromStrgOffs.State;
      *Dev       = StrgOffsEEprom->EEPromStrgOffs.Dev;

      SWA_GET_NVM_ERR_OFFS_RG = (VDY_ERR_STATE_INACTIVE);
    }

    /* Data read from NVM */
    StrgOffsOk = (boolean)TRUE;
  }
  return (StrgOffsOk);
}


/* **********************************************************************
	Unit Design for vdyAySwaAcqEstData is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyAySwaAcqEstData(const VDYSwaSenData_t *swaSen, const VDYAySenData_t *aySen,
                               VDYSwaOffsData_t *swaOffs, VDYAyOffsData_t *ayOffs,
                               fDistance_t cycDist)
{
  /* local storage for absolute values */
  float32 f_StrgAngleAbs;
  float32 f_WhlFrDiffFiltAbs;
  float32 f_WhlReDiffFiltAbs;
  uint8 u_BankRoad = vdy_internal_data.vdy_aye_out.BankRoad;

#if ( ( (!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING) ) || ( (!defined(CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING) ) )
  const VehSigMain_t *in = SWA_GET_INP_SIGNALS;
#endif
  VDYCaliState_t SWACaliState = SWA_GET_ME->Io.in->Frame.CaliMode;
#if ( (!defined(CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING) )
  VDYCaliState_t AYCaliState = AY_GET_ME->Io.in->Frame.CaliMode;
#endif

  /* Filter front wheel velocities differences */
#if ( (!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING) )
  if (    (VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_FL, in->State) == (VDYIoStateTypes_t)VDY_IO_STATE_VALID) 
       && (VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_FR, in->State) == (VDYIoStateTypes_t)VDY_IO_STATE_VALID) )
  {
    swaOffs->WhlFrDiffFilt = vdyFilterCycleTime( in->WhlVelFrLeft - in->WhlVelFrRight, swaOffs->WhlFrDiffFilt, SWA_OFFS_WHS_DIFF_FT);
  }
  else
#endif
  {
    swaOffs->WhlFrDiffFilt = VDY_ZERO_F;
  }

  /* Filter rear wheel velocities differences */
#if ( (!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING) )
  if (    (VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_RL, in->State) == (VDYIoStateTypes_t)VDY_IO_STATE_VALID) 
       && (VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_RR, in->State) == (VDYIoStateTypes_t)VDY_IO_STATE_VALID) )
  {
    swaOffs->WhlReDiffFilt = vdyFilterCycleTime( in->WhlVelReLeft - in->WhlVelReRight, swaOffs->WhlReDiffFilt, SWA_OFFS_WHS_DIFF_FT);
  }
  else
#endif
  {
    swaOffs->WhlReDiffFilt = VDY_ZERO_F;
  }

  f_StrgAngleAbs = CML_f_Abs(swaSen->StrgAngle);
  f_WhlFrDiffFiltAbs = CML_f_Abs(swaOffs->WhlFrDiffFilt);
  f_WhlReDiffFiltAbs = CML_f_Abs(swaOffs->WhlReDiffFilt);

  /* Validity condition for long term compensation */
  if (   ( f_StrgAngleAbs < SWA_OFFS_ANGLE_MAX)
      && ( (SWA_GET_MIF_DATA->LongMot.VehVelocityCorr > SWA_OFFS_VEL_MIN) && (SWA_GET_MIF_DATA->LongMot.MotState.MotState != (MotState_t)VDY_LONG_MOT_STATE_MOVE_RWD) )
      && ( (f_WhlFrDiffFiltAbs < SWA_OFFS_WHS_DIFF_VEL) && (f_WhlReDiffFiltAbs < SWA_OFFS_WHS_DIFF_VEL ))
      && (u_BankRoad == VDY_ZERO_U) )                                                                       /* If Bent > (2 degree) */
  {
#if ( (!defined(CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING) )
    /* Integrate lateral acceleration to detect circular routes */
    if (VDY_GET_IO_STATE(VDY_SIN_POS_LATA,in->State) == (VDYIoStateTypes_t)VDY_IO_STATE_VALID)
    {
      swaOffs->LatAccel = vdyFilterCycleTime( in->LatAccel, swaOffs->LatAccel, SWA_OFFS_LAT_ACC_FT );
    }
#endif
    /* Accumulate driven distance */
    if (swaOffs->Est.Hist.Sum <= SWA_OFFS_DRIVEN_DIST_MAX)
    {
      fAccel_t currAccel;

#if ( (!defined(CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING) )
      if (VDY_GET_IO_STATE(VDY_SIN_POS_LATA,in->State) == (VDYIoStateTypes_t)VDY_IO_STATE_VALID)
      {
        currAccel = aySen->Ay;
        /* Only if lateral acceleration calibration mode is off add samples to histgramm */
        if (!VDY_CTRL_GET_STATE((VDYCaliState_t)VDY_CAL_LTA_OFFS, AYCaliState))
        {
          /* Add lateral acceleration samples to histogram */
          vdyHistAdd(&ayOffs->Est.Hist, aySen->Ay, cycDist);
        }
      }
      else
#else
      (void)aySen;
      (void)ayOffs;
#endif
      {
        currAccel = VDY_ZERO_F;
      }

      if (CML_f_Abs(currAccel) < AY_SWA_LIMIT_HIST )
      {
        /* Only if steering wheel angle calibration mode is off add samples to histgramm */
        if (!VDY_CTRL_GET_STATE((VDYCaliState_t)VDY_CAL_SWA_OFFS, SWACaliState))
        {
          /* Add steering angle samples to histogram */
          vdyHistAdd(&swaOffs->Est.Hist, swaSen->StrgAngle, cycDist);
        }
      }
    }
  }
  return;
}
  

/* **********************************************************************
	Unit Design for vdySwaTakeoverOffset is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdySwaTakeoverOffset(VDYSwaOffsData_t *StrgOffsData, VDYSwaOffsEst_t *OffsEst)
{
  const float32 Weightn_c = 0.5F;  /* Weight for new offset estimation max. 1.0 */
  fAngle_t SwaOffsNorm;            /* Normalised steering wheel offset */
  fAngle_t SwaOffsDiff;            /* Difference between new and old offset */
  fAngle_t SwaOffsAbsDiff;         /* Absolute difference between new and old offset */
  fAngle_t SwaOffsNew;             /* New offset value */
  VDYSwaData_t *p_SwaData  = SWA_GET_ME;  /* get the steering angle offset data */
  /* Differences between active and new estimated offset */
  SwaOffsDiff    = OffsEst->Offs - StrgOffsData->StrgOffset;
  SwaOffsAbsDiff = CML_f_Abs(SwaOffsDiff);

  /* No active offset available (the estimated offset is the first calculated offset)? */
  if (StrgOffsData->OffsState == SWA_STATE_DEFAULT)
  {
    /* Use estimated offset as first offset, no appoximation with active offset (no active offset available) */
    SwaOffsNew = OffsEst->Offs;
  }
  else
  {
    /* Calculate average between active and estimated offset for successive approximation of final offset */
    SwaOffsNew = StrgOffsData->StrgOffset + (Weightn_c * SwaOffsDiff);
  }
  
  /* Normalize offset value @todo is normalized offset still necessary */
  SwaOffsNorm = vdyDiscretize(SwaOffsNew, SWA_OFFS_NORM_RES);
  
  /* Acquisition strategy is dependent on current state */
  switch(StrgOffsData->OffsState)
  {
    case SWA_STATE_DEFAULT:
    case SWA_STATE_1:
    case SWA_STATE_2:
    case SWA_STATE_3:
      
      /*<<<<<<<< L E A R N   P H A S E >>>>>>>>*/
    
      /* When offset value is stable or it is the first offset, increment state  */
      if (((SwaOffsAbsDiff <= SWA_OFFS_STAT_DIFF_RUN_UP) || (StrgOffsData->OffsState == SWA_STATE_DEFAULT)) && (p_SwaData->FastSwaOffset.Fast_Offset_State == 0U))
      {
        StrgOffsData->OvrTakeCntr++;
        if (StrgOffsData->OvrTakeCntr < SWA_OFFS_TAKE_OVR_MAX)
        {
          StrgOffsData->OffsState += 1;
        }
      }

      /* Take over offset and deviation */
      StrgOffsData->StrgOffset     = SwaOffsNew;
      StrgOffsData->StrgOffsetNorm = SwaOffsNorm;
      StrgOffsData->Dev            = vdySwaGetOffsetDeviation(StrgOffsData->OffsState);

      /* Save offset value and status in nonvolatile memory */
      vdySwaPutEepromOffsetData(SwaOffsNew, StrgOffsData->OffsState, SWA_OFFS_DEV_NORMAL);
      
	  if(StrgOffsData->OffsState > SWA_STATE_1)
      {
       /* Initialize estimation data */ 
       vdyHistReInit(&OffsEst->Hist);
      }

      break;

    case SWA_STATE_4:

      /*<<<<<<<< R E L E A R N   P H A S E >>>>>>>>*/
      
      /* Test offset against stability */
      if  (SwaOffsAbsDiff >= SWA_OFFS_CHANGE_HYST )
      {      
        /* Estimated offset differs significantly from active offset: restore learned offset value */

        /* Remain in this offset calibration state */
        StrgOffsData->OffsState      = SWA_STATE_4;
        
        /* Take over offset */
        StrgOffsData->StrgOffset     = SwaOffsNew;
        StrgOffsData->Dev            = vdySwaGetOffsetDeviation(StrgOffsData->OffsState);
        StrgOffsData->StrgOffsetNorm = SwaOffsNorm;
      
        /* Initialize estimation data */ 
        vdyHistReInit(&OffsEst->Hist);
      }
      else
      {
        /* Estimated offset approves active and stored offset */

        /* Imcrement offset state */
        StrgOffsData->OffsState  = SWA_STATE_5;
        
        /* Take over offset */
        StrgOffsData->StrgOffset     = SwaOffsNew;
        StrgOffsData->Dev            = vdySwaGetOffsetDeviation(StrgOffsData->OffsState);
        StrgOffsData->StrgOffsetNorm = SwaOffsNorm;

        /* Indicate that offset value has been confirmed during this ignition cylce, i.e .one
           confirmation per ignition cylce i. e. hold offset state in next state for this ignition cycle */
        StrgOffsData->OvrTakeCntr++;
      
        /* Scale back estimation data */ 
        vdyHistReduce(&OffsEst->Hist, SWA_INTERVAL_RDCT_FCTR);
      }
      
      /* Save offset value and status in nonvolatile memory */
      vdySwaPutEepromOffsetData(StrgOffsData->StrgOffset, StrgOffsData->OffsState, SWA_OFFS_DEV_NORMAL);

      break;

    case SWA_STATE_5:
    case SWA_STATE_6:

      /*<<<<<<<< C O N F I R M A T I O N   P H A S E >>>>>>>*/

      if ( SwaOffsAbsDiff >= SWA_OFFS_CHANGE_HYST )
      {
        /* Estimated offset differs significantly form active offset: lower offset state without
           changing the offset value */
        StrgOffsData->OffsState -= 1;

        /* Save offset state in nonvolatile memory  */
        vdySwaPutEepromOffsetData(StrgOffsData->StrgOffset, StrgOffsData->OffsState, SWA_OFFS_DEV_NORMAL);
      }
      else
      {
        /* Estimated offset approves active and stored offset */
        if ( (StrgOffsData->OvrTakeCntr == 0u)  && (StrgOffsData->OffsState < SWA_STATE_6))
        {
          /* Offset state 5 has been reached since last ignition cycle, move to state 6 */
          StrgOffsData->OffsState = SWA_STATE_6;         
          
          /* Take over offset */
          StrgOffsData->StrgOffset     = SwaOffsNew;
          StrgOffsData->Dev            = vdySwaGetOffsetDeviation(StrgOffsData->OffsState);
          StrgOffsData->StrgOffsetNorm = SwaOffsNorm;
        
          /* Save offset value and status in nonvolatile memory */
          vdySwaPutEepromOffsetData(StrgOffsData->StrgOffset, StrgOffsData->OffsState, SWA_OFFS_DEV_NORMAL);
        } 
      }

      /* Scale back estimation data */ 
      vdyHistReduce(&OffsEst->Hist, SWA_INTERVAL_RDCT_FCTR);

      break;
    
    default:
      
      /* This state is not regular */
      
      /* Set default state */
      StrgOffsData->OffsState = SWA_STATE_DEFAULT;

      /* Initialize estimation data */ 
      vdyHistReInit(&OffsEst->Hist);

      break;
  }
  return;
}


/* **********************************************************************
	Unit Design for vdySwaCheckConfidence is found in Declaration Section
**************************************************************************** */
STATIC_MTD boolean vdySwaCheckConfidence(const VDYSwaOffsData_t *OffsData)
{
  float32  reqConf;
  boolean  ret = (boolean)FALSE;
  
  if (OffsData->OffsState > SWA_STATE_3)
  {
    reqConf = AY_SWA_OFFS_MID_CONF;
  }
  else
  {
    reqConf = AY_SWA_OFFS_LOW_CONF;
  }

  if ((vdySwaOffsetRangeOk(OffsData->Est.Offs) != (boolean)FALSE) && (OffsData->Est.Conf >= reqConf) )
  {
    ret = (boolean)TRUE;
  }
  return ret;
}


/* **********************************************************************
	Unit Design for vdyAyCheckConfidence is found in Declaration Section
**************************************************************************** */
STATIC_MTD boolean vdyAyCheckConfidence(const VDYAyOffsData_t *ayOffs)
{
  float32   reqConf;
  boolean  ret = (boolean)FALSE;
  
  if (ayOffs->OffsState > AY_STATE_2)
  {
    reqConf = AY_SWA_OFFS_MID_CONF;
  }
  else
  {
    reqConf = AY_SWA_OFFS_LOW_CONF;
  }

  if (   (vdyAyOffsetRangeOk(ayOffs->Est.Offs) != (boolean)FALSE) 
      && (ayOffs->Est.Conf >= reqConf) )
  {
    ret = (boolean)TRUE;
  }
  
  return ret;
}


/* **********************************************************************
	Unit Design for vdySwaGetOffsetStart is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdySwaGetOffsetStart(VDYSwaOffsData_t *SwaOffsData)
{
  /* Read offset start values if not OK */
  if (SwaOffsData->StrgOffsReadOk == (boolean)FALSE)
  {
    /* Read non-volatile offset calibration data and verify ranges */
    SwaOffsData->StrgOffsReadOk = vdySwaGetOffset(&SwaOffsData->StrgOffset, &SwaOffsData->OffsState, &SwaOffsData->Dev );

    /* Normalize steering wheel angle offset */
    SwaOffsData->StrgOffsetNorm = vdyDiscretize(SwaOffsData->StrgOffset, SWA_OFFS_NORM_RES);

    /* Determine minimum required driven distance for offset estimation in depedence of state */
    SwaOffsData->Est.ThrldDist = vdySwaEvalThrdDist(SwaOffsData->OffsState);

    /* Determine maximum offset deviation for estimation in dependence of state */
    SwaOffsData->Est.ThrldDev = vdySwaEvalThrdDeviation(SwaOffsData->OffsState); 
  }
  return;
}


/* **********************************************************************
	Unit Design for vdyAyGetOffsetStart is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyAyGetOffsetStart(VDYAyOffsData_t *pAyOffsData)
{
  /* Read offset start values if not OK */
  if (pAyOffsData->AyOffsReadOk == (boolean)FALSE)
  {
    /* Read non-volatile offset calibration data and verify ranges */
    pAyOffsData->AyOffsReadOk = vdyAyGetOffset(&pAyOffsData->AyOffset, &pAyOffsData->OffsState, &pAyOffsData->Dev );

    /* Determine minimum required driven distance for offset estimation in depedence of state */
    pAyOffsData->Est.ThrldDist = vdyAyEvalThrdDist(pAyOffsData->OffsState);

    /* Determine maximum offset deviation for estimation in dependence of state */
    pAyOffsData->Est.ThrldDev = vdyAyEvalThrdDeviation(pAyOffsData->OffsState); 
  }
  return;
}


/* **********************************************************************
	Unit Design for vdySwaCalcConfidence is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdySwaCalcConfidence(VDYSwaOffsData_t *StrgOffsData)
{
  /* Enough data for offset estimation acquired */
  uint32 maxIdx;
  uint32 rgSort[SWA_OFFS_HIST_NO_BINS];
  VDYHistogram_t *hist = &StrgOffsData->Est.Hist;
  fAngle_t median;

  /* Calculate mean and standard deviation of histogram data */
  vdyHistCalcMeanDev(hist);

  /* Create an sorted index of histogram bin volumes */
  vdyHpSortInd(SWA_OFFS_HIST_NO_BINS, hist->Volume, rgSort);

  /* Calculate median of histogram data */
  median = vdyHistCalcMedian(hist);

  /* Last value of sorted index coresponds to bin with maximum count */
  maxIdx = rgSort[SWA_OFFS_HIST_MAX_IDX];

  /* Init confidence level */
  StrgOffsData->Est.Conf = AY_SWA_OFFS_NO_CONF;

  /* Compare mean with maximum count bin */
  if (CML_f_Abs(hist->Mean - hist->Range[maxIdx]) < SWA_OFFS_DIFF_MAX_MEAN )
  {
    /* Range with maximum count is close to mean */
      
    /* Check if adjacent bins of maximum have enough counts, detect the case with nearly constant angle */
    if (    ( CML_f_Abs(hist->Volume[maxIdx] - (hist->Volume[maxIdx-1u] + hist->Volume[maxIdx+1u])) < (SWA_OFFS_FTHR_DIST_MAX_ADJ * StrgOffsData->Est.ThrldDist) )
         && ( (maxIdx > 1u) && (maxIdx < (hist->Size - 1u)) )  )
    {
      /* Normal route characteristics, best confidence */
      StrgOffsData->Est.Conf = AY_SWA_OFFS_MAX_CONF;
    }
    else
    {
      /* Driving long section with same steering wheel angle (straight or constant radius) */
      StrgOffsData->Est.Conf = AY_SWA_OFFS_MID_CONF;
    }
    
    /* bin counts are normally distributed, use mean as offset value */
    StrgOffsData->Est.Offs = hist->Mean;
  }
  else
  {
    /* Range with maximum count is far away from mean, counts are not normally distributed  
       that means that a secondary peak exists. This can be caused by driving oval circuits 
       on proving grounds */
      
    /* Distance difference between maximum and secondary peak */
    const fDistance_t distMax_c = hist->Volume[rgSort[SWA_OFFS_HIST_MAX_IDX]];
    fDistance_t diffDistMaxMean;

    /* Get distance difference between maximum and range around mean */
    diffDistMaxMean = distMax_c - vdyHistGetVolume(hist, hist->Mean);
    
    /* If the count difference between secondary peak and maximum peak is big enough, blind out secondary peak 
       by use only center around the maximum peak */
    if (  diffDistMaxMean > (SWA_OFFS_FTHR_DIST_MAX_OUT * StrgOffsData->Est.ThrldDist) )
    {
      /* Calculate mean around maximum peak */
      StrgOffsData->Est.Offs = vdyHistCalcMeanCenter(hist, rgSort[SWA_OFFS_HIST_MAX_IDX], VDY_TWO_U, VDY_ONE_U);

      /* Limit confidence to avoid high status offset calibration */
      StrgOffsData->Est.Conf = AY_SWA_OFFS_LOW_CONF;
    }
    else if (CML_f_Abs(median - hist->Range[maxIdx]) < SWA_OFFS_DIFF_MAX_MED )
    {
      /* Maximum distance count is not not much above the mean distance count, but median and mode are close to together, 
        this can occur in case of large offset values, where histogram data is unsymmetric because one-sided truncation */
      float32 diffMeanMedian = vdyHistCalcMeanCenter(hist, rgSort[SWA_OFFS_HIST_MAX_IDX], VDY_TEN_U, VDY_ONE_U) - median;
    
      /* Calculate mean around maximum peak */
      if (CML_f_Abs(diffMeanMedian) < SWA_OFFS_DIFF_MEAN_CT_MED)
      {
        /*  Use median as estimated offset */
        StrgOffsData->Est.Offs = median;

        /* Maximum value looks like a outlier, use median value instead */
        StrgOffsData->Est.Conf = AY_SWA_OFFS_LOW_CONF;
      }
    }
    else if (CML_f_Abs(median - hist->Mean) < SWA_OFFS_DIFF_MEAN_MED )
    {
      /* Distribution looks symmetric, but maximum peak is outside the centre */
      
      /* Use median as estimated offset */
      StrgOffsData->Est.Offs = median;

      if (diffDistMaxMean < (SWA_OFFS_FTHR_DIST_MAX_MEAN * StrgOffsData->Est.ThrldDist) )
      {
        /* Maximum value looks like a outlier, use median value instead */
        StrgOffsData->Est.Conf = AY_SWA_OFFS_MID_CONF;
      }
      else
      {
        /* Maximum value looks like a outlier, use median value instead */
        StrgOffsData->Est.Conf = AY_SWA_OFFS_LOW_CONF;
      }
    }
    else
    {
      /* two peaks with rougly the same distance and ambiguous route characteristics */

      /* Estimation has no confidence */
      StrgOffsData->Est.Conf = AY_SWA_OFFS_NO_CONF;
    }
  }
  return;
}


/* **********************************************************************
	Unit Design for vdyAyCalcConfidence is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyAyCalcConfidence(VDYAyOffsData_t *pOffsAy)
{
  /* Enough data for offset estimation acquired */
  uint32 maxIdx;
  uint32 rgSort[AY_OFFS_HIST_NO_BINS];
  VDYHistogram_t *hist = &pOffsAy->Est.Hist;
  fAccel_t median;

  /* Calculate mean and standard deviation of histogram data */
  vdyHistCalcMeanDev(hist);

  /* Create an sorted index of histgram bin volumes */
  vdyHpSortInd(AY_OFFS_HIST_NO_BINS, hist->Volume, rgSort);

  /* Calculate median of histogram data */
  median = vdyHistCalcMedian(hist);

  /* Last value of sorted index coresponds to bin with maximum count */
  maxIdx = rgSort[AY_OFFS_HIST_MAX_IDX];

  /* Init confidence level */
  pOffsAy->Est.Conf = AY_SWA_OFFS_NO_CONF;

  /* Compare mean with maximum count bin */
  if (CML_f_Abs(hist->Mean - hist->Range[maxIdx]) < AY_OFFS_DIFF_MAX_MEAN )
  {
    /* Range with maximum count is close to mean */
      
    /* Check if adjacent bins of maximum have enough counts, detection the case with nearly constant angle */
    if (    ( CML_f_Abs(hist->Volume[maxIdx] - (hist->Volume[maxIdx-1u] + hist->Volume[maxIdx+1u])) < (AY_OFFS_FTHR_DIST_MAX_ADJ * pOffsAy->Est.ThrldDist) )
         && ( (maxIdx > 1u) && (maxIdx < (hist->Size - 1u)) )  )
    {
      /* Normal route characteristics, best confidence */
      pOffsAy->Est.Conf = AY_SWA_OFFS_MAX_CONF;
    }
    else
    {
      /* Driving long section with same steering wheel angle (straight or constant radius) */
      pOffsAy->Est.Conf = AY_SWA_OFFS_MID_CONF;
    }
    
    /* bin counts are normally distributed, use mean as offset value */
    pOffsAy->Est.Offs = hist->Mean;
  }
  else
  {
    /* Range with maximum count is far away from mean, counts are not normally distributed  
       that means that a secondary peak exists. This can be caused by driving oval circuits 
       on proving grounds */
      
    /* Distance difference between maximum and secondary peak */
    const fDistance_t distMax_c = hist->Volume[rgSort[AY_OFFS_HIST_MAX_IDX]];
    fDistance_t diffDistMaxMean;

    /* Get distance difference between maximum and range around mean */
    diffDistMaxMean = distMax_c - vdyHistGetVolume(hist, hist->Mean);
    
    /* If the count difference between secondary peak and maximum peak is big enough, blind out seondary peak 
       by use only center around the maximum peak */
    if (  diffDistMaxMean > (AY_OFFS_FTHR_DIST_MAX_OUT * pOffsAy->Est.ThrldDist) )
    {
      /* Calculate mean around maximum peak */
      pOffsAy->Est.Offs = vdyHistCalcMeanCenter(hist, rgSort[AY_OFFS_HIST_MAX_IDX], VDY_THREE_U, VDY_ONE_U);

      /* Limit confidence to avoid high status offset calibration */
      pOffsAy->Est.Conf = AY_SWA_OFFS_LOW_CONF;
    }
    else if (CML_f_Abs(median - hist->Range[maxIdx]) < AY_OFFS_DIFF_MAX_MED )
    {
      /* Maximum distance count is not not much above the mean distance count, but median and mode are close to together, 
         this can occur in case of large offset values, where histogram data is unsymmetric because one-sided truncation */
      fAccel_t meanCenter;

      meanCenter = vdyHistCalcMeanCenter(hist, rgSort[AY_OFFS_HIST_MAX_IDX], VDY_TEN_U, VDY_ONE_U);
    
      /* Calculate mean around maximum peak */
      if ( CML_f_Abs( meanCenter- median) < AY_OFFS_DIFF_MEAN_MED)
      {
        /*  Use median as estimated offset */
        pOffsAy->Est.Offs = median;

        /* Maximum value looks like a outlier, use median value instead */
        pOffsAy->Est.Conf = AY_SWA_OFFS_LOW_CONF;
      }
    }
    else
    {
      /* two peaks with rougly the same distance and ambiguous route characteristics */

      /* Estimation has no confidence */
      pOffsAy->Est.Conf = AY_SWA_OFFS_NO_CONF;
    }
  }
  return;
}


/* **********************************************************************
	Unit Design for vdySwaOffsCheckandTakeOver is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdySwaOffsCheckandTakeOver(VDYSwaOffsData_t *swaOffs)
{
  /* Check confidence and range of estimation value */
  if (vdySwaCheckConfidence(swaOffs) != (boolean)FALSE )
  {
    /* Validate offset value and use if applicable */
    vdySwaTakeoverOffset(swaOffs, &swaOffs->Est);
     
    /* Update distance threshold for offset calibration */
    swaOffs->Est.ThrldDist = vdySwaEvalThrdDist(swaOffs->OffsState);

    /* Update deviation threshold for offset calibration */
    swaOffs->Est.ThrldDev = vdySwaEvalThrdDeviation(swaOffs->OffsState);

    /* Reset ReInit counter */
    swaOffs->ReInitCntr = 0U;
  }
  else
  {
    if(swaOffs->OffsState > SWA_STATE_1)
    {
     /* Estimated value is not usable as offset */
     vdyHistReInit(&swaOffs->Est.Hist);
    }

    if (  (vdySwaOffsetRangeOk(swaOffs->Est.Offs) == (boolean)FALSE)  
        &&(swaOffs->Est.Conf > AY_SWA_OFFS_NO_CONF))
    {
      /* Inc ReInit counter */
      swaOffs->ReInitCntr++;
    }
  }

  /* if ReInit counter is above parameter value (3) set the error flag */
  if (swaOffs->ReInitCntr >= VDY_PAR_ERR_SWA_REINIT)
  {
    SWA_GET_ERR_OFFS_RG = (VDY_ERR_STATE_ACTIVE);
    /* Limit ReInit counter */
    swaOffs->ReInitCntr = VDY_PAR_ERR_SWA_REINIT;
  }
  else
  {
     SWA_GET_ERR_OFFS_RG = (VDY_ERR_STATE_INACTIVE);
  }
  return;
}


/* **********************************************************************
	Unit Design for vdyAyTakeoverOffset is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyAyTakeoverOffset(VDYAyOffsData_t *offsAy, VDYAyOffsEst_t *estOffsAy)
{
  const float32 Weightn_c = 0.7F;     /* Weight for new offset estimation max. 1.0 */
  fAccel_t AyOffsDiff;                /* Difference between new and old offset */
  fAccel_t AyOffsAbsDiff;             /* Absolute difference between new and old offset */
  fAccel_t AyOffsNew;                 /* New offset value */

  /* Differences between active and new estimated offset */
  AyOffsDiff    = estOffsAy->Offs - offsAy->AyOffset;
  AyOffsAbsDiff = CML_f_Abs(AyOffsDiff);

  /* No active offset available (the estimated offset is the first calculated offset)? */
  if (offsAy->OffsState == AY_STATE_DEFAULT)
  {
    /* Use estimated offset as first offset. no appoximation with active offset (there is no active offset available) */
    AyOffsNew = estOffsAy->Offs;
  }
  else
  {
    /* Calculate average between active and estimated offset for successive approximation of final offset */
    AyOffsNew = offsAy->AyOffset + (Weightn_c * AyOffsDiff);
  }

  /* Acquisition strategy is dependent on current state */
  switch (offsAy->OffsState)
  {
    case AY_STATE_DEFAULT:
    case AY_STATE_1:
    case AY_STATE_2:
      
      /*<<<<<<<< L E A R N   P H A S E >>>>>>>>*/
    
      if (offsAy->Interims == (boolean)FALSE)
      {
        /* When offset value is stable, increment state  */
        if  (AyOffsAbsDiff <= AY_OFFS_STAT_DIFF_RUN_UP)
        {
          offsAy->OvrTakeCntr++;
          if (offsAy->OvrTakeCntr < AY_OFFS_TAKE_OVR_MAX)
          {
            offsAy->OffsState += 1;
          }
        }

        /* Save offset value and status in nonvolatile memory */
        vdyAyPutNvmOffsetData(AyOffsNew, offsAy->OffsState);

        /* Initialize estimation data */ 
        vdyHistReInit(&estOffsAy->Hist);
      }

      /* Take over offset and deviation */
      offsAy->AyOffset     = AyOffsNew;
      offsAy->Dev          = vdyAyGetOffsetDeviation(offsAy->OffsState);

      break;

    case AY_STATE_3:

      /*<<<<<<<< R E L E A R N   P H A S E >>>>>>>>*/
      
      /* Test offset against stability */
      if  (AyOffsAbsDiff >= AY_OFFS_STAT_DIFF_LEARNED )
      {
        /* Estimated offset differs significantly from active offset: restore learned offset value */

        /* Remain in this offset calibration state */
        offsAy->OffsState      = AY_STATE_2;
        
        /* Take over offset */
        offsAy->AyOffset   = AyOffsNew;
        offsAy->Dev        = vdyAyGetOffsetDeviation(offsAy->OffsState);

        if (offsAy->Interims == (boolean)FALSE)
        {
          /* Initialize estimation data */ 
          vdyHistReInit(&estOffsAy->Hist);
        }
      }
      else
      {
        /* Estimated offset approves active and stored offset */

        if (offsAy->Interims==(boolean)FALSE)
        {
          /* Imcrement offset state */
          offsAy->OffsState  = AY_STATE_3;
        
          /* Take over offset */
          offsAy->AyOffset   = AyOffsNew;
          offsAy->Dev        = vdyAyGetOffsetDeviation(offsAy->OffsState);

          /* Indicate that offset value has been confirmed during this ignition cylce, i.e .one
             confirmation per ignition cylce */
          offsAy->OvrTakeCntr++;
      
          /* Scale back estimation data */ 
          vdyHistReduce(&estOffsAy->Hist, AY_INTERVAL_RDCT_FCTR);
        }
      }
      
      if (offsAy->Interims == (boolean)FALSE)
      {
        /* Save offset value and status in nonvolatile memory */
        vdyAyPutNvmOffsetData(offsAy->AyOffset, offsAy->OffsState);
      }

      break;

    default:
      
      /* This state is not regular */
      
      /* Set default state */
      offsAy->OffsState = AY_STATE_DEFAULT;
      offsAy->Dev       = vdyAyGetOffsetDeviation(offsAy->OffsState);

      /* Initialize estimation data */ 
      vdyHistReInit(&estOffsAy->Hist);

      break;
  }

  return;
}


/* **********************************************************************
	Unit Design for vdyAyOffsCheckandTakeOver is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyAyOffsCheckandTakeOver(VDYAyOffsData_t *payOffs, const VDYSwaOffsData_t *pswaOffs, boolean clrData)
{
  if (    (vdyAyCheckConfidence(payOffs) != (boolean)FALSE)
       && (pswaOffs->Est.Conf > VDY_ZERO_F)  )
  {
    /* Validate offset value and use if applicable */
    vdyAyTakeoverOffset(payOffs, &payOffs->Est);
     
    if (clrData !=(boolean)FALSE)
    {
      /* Update distance threshold for offset calibration */
      payOffs->Est.ThrldDist = vdyAyEvalThrdDist(payOffs->OffsState);

      /* Update deviation threshold for offset calibration */
      payOffs->Est.ThrldDev = vdySwaEvalThrdDeviation(payOffs->OffsState);
    }
  }
  else
  {
    if (clrData !=(boolean)FALSE)
    {
      /* Estimated value is not usable as offset */
      vdyHistReInit(&payOffs->Est.Hist);
    }
  }
  return;
}


/* **********************************************************************
	Unit Design for vdyAySwaCalcOffset is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyAySwaCalcOffset(const VDYSwaSenData_t *swaSen, const VDYAySenData_t *aySen, VDYSwaOffsData_t *swaOffs, VDYAyOffsData_t *ayOffs)
{
  fDistance_t distCycle;
  VDYSwaData_t *p_SwaData  = SWA_GET_ME;  /* get the steering angle offset data */  
  /* Calculate distance driven in this cycle */
  distCycle = vdyCalcCycleDistance(SWA_GET_MIF_DATA->LongMot.VehVelocityCorr);
  
  /* Acquire data and store in histogram for offset estimation */
  vdyAySwaAcqEstData(swaSen, aySen, swaOffs, ayOffs, distCycle);

  /* Detect constant circular driving */
  if (CML_f_Abs(swaOffs->LatAccel) > SWA_OFFS_LAT_ACC_MAX )
  {
    /* Reset learn values due to circular driving */
    vdyHistReInit(&swaOffs->Est.Hist);
    vdyHistReInit(&ayOffs->Est.Hist);
    
    /* Reset integrated lateral acceleration */
    swaOffs->LatAccel = VDY_ZERO_F;
  }

  /* Estimation requires a driven route with minimum distance */
  if ( swaOffs->Est.Hist.Sum >= swaOffs->Est.ThrldDist )
  {
    /* Signal no interims lateral acceleration offset calibration */
    ayOffs->Interims =(boolean)FALSE;
    p_SwaData->FastSwaOffset.Fast_Offset_State = VDY_ZERO_U;

    /* Estimate and check reliability of offset */
    vdySwaCalcConfidence(swaOffs);
    if ( ayOffs->Est.Hist.Sum >= ayOffs->Est.ThrldDist )
    {
      vdyAyCalcConfidence(ayOffs);
    }

    /* In case of sufficient confidence take over offset */
    vdyAyOffsCheckandTakeOver(ayOffs, swaOffs, (boolean)TRUE);
    vdySwaOffsCheckandTakeOver(swaOffs);
  }
  else
  {
    if ( ayOffs->Est.Hist.Sum >= ayOffs->Est.ThrldDist )
    {
      const fDistance_t incDist_c = 10000.F;   /* Additional distance after interims offset */

      /* Signal interims lateral acceleration offset */
      ayOffs->Interims = (boolean)TRUE;

      /* Estimate and check reliability, of offset */
      if ( swaOffs->Est.Hist.Sum >= swaOffs->Est.ThrldDist )
      {
        vdySwaCalcConfidence(swaOffs);
      }
      vdyAyCalcConfidence(ayOffs);
      
      /* In case of sufficient confidence take over offset and don't reset previous data */
      vdyAyOffsCheckandTakeOver(ayOffs, swaOffs, (boolean)FALSE);

      /* Increase distance threhold */
      ayOffs->Est.ThrldDist += incDist_c;
    }
  }
  return;
}


/* **********************************************************************
	Unit Design for vdyAyGetOffset is found in Declaration Section
**************************************************************************** */
STATIC_MTD boolean vdyAyGetOffset(fAccel_t *Offset, sint32 *Status, float32 *Dev )
{
  boolean AyOffsOk = (boolean)FALSE;
  
  if (vdyAyGetNvmOffsetData(Offset, Status, Dev) != (boolean)FALSE)
  {
    /* NVM read operation successfully completed */
    if (    (vdyAyOffsetRangeOk(*Offset) == (boolean)FALSE) 
         || ( (*Status < AY_STATE_DEFAULT) || (*Status > AY_STATE_3 ))  )
    { 
      /* Stored offset value is out of range */

      /* Indicate error state active "false value stored in nvmemory" */
      AY_GET_ERR_OFFS_RG = (VDY_ERR_STATE_ACTIVE);

      *Offset =  AY_OFFS_DEFAULT;
      *Status =  AY_STATE_DEFAULT;
      *Dev    =  vdyAyGetOffsetDeviation(*Status);

      /* Try to correct invalid values in nv memory by overwriting with defaults */
      vdyAyPutNvmOffsetData(*Offset, *Status);
    }
    else
    {
      /* Stored swa nvmem values are OK! */
      
      /* Indicate error state inactive "false value stored in nvmemory" */
      AY_GET_ERR_OFFS_RG = (VDY_ERR_STATE_INACTIVE);
    }

    /* Daten wurden aus Eeprom-Mirror gelesen */
    AyOffsOk = (boolean)TRUE;
  }
  return (AyOffsOk);
}


/* **********************************************************************
	Unit Design for vdyCalcFastSwaOffset is found in vdy.h
**************************************************************************** */
void vdyCalcFastSwaOffset(const VDYInputData_t * p_InputData)
{
  float32 f_LongAccel;
  float32 f_EgoVel;
  float32 f_SteeringAngle;

  float32 f_WhlVelFrDiff;
  float32 f_WhlVelReDiff;
  float32 f_WhlVelFrDiffFiltAbs;
  float32 f_WhlVelReDiffFiltAbs;

  float32 f_yaw_gye;
  float32 f_LatAccel;
  uint8   u_BankRoad;
  uint16  u_samples;

  VDYSwaData_t *p_SwaData  = SWA_GET_ME;  /* get the steering angle offset data */

  /* get signals */
  f_yaw_gye       = CML_f_Abs(vdy_internal_data.vdy_gye_out.gier_yaw_rate);
  f_EgoVel        = vdy_internal_data.vdy_ve_out.veh_velo;
  f_LongAccel     = CML_f_Abs(vdy_internal_data.vdy_ve_out.veh_accel);
  f_SteeringAngle = CML_f_Abs(p_InputData->Signals.StWheelAngle);
  f_LatAccel      = CML_f_Abs(vdy_internal_data.vdy_ye_out.veh_lat_accel);
  u_BankRoad      = vdy_internal_data.vdy_aye_out.BankRoad;

  /* get wheel information */
  f_WhlVelFrDiff = p_InputData->Signals.WhlVelFrRight - p_InputData->Signals.WhlVelFrLeft;
  f_WhlVelReDiff = p_InputData->Signals.WhlVelReRight - p_InputData->Signals.WhlVelReLeft;

  /* filter wheel speed differences */
  p_SwaData->FastSwaOffset.f_WhlVelFrDiffFilt = vdyFilterCycleTime(f_WhlVelFrDiff, p_SwaData->FastSwaOffset.f_WhlVelFrDiffFilt, SWA_OFFS_WHS_DIFF_FT);
  p_SwaData->FastSwaOffset.f_WhlVelReDiffFilt = vdyFilterCycleTime(f_WhlVelReDiff, p_SwaData->FastSwaOffset.f_WhlVelReDiffFilt, SWA_OFFS_WHS_DIFF_FT);

  /* get absolute values for test locally as the signed values are needed in the filter in the next cycle */
  f_WhlVelFrDiffFiltAbs = CML_f_Abs(p_SwaData->FastSwaOffset.f_WhlVelFrDiffFilt);
  f_WhlVelReDiffFiltAbs = CML_f_Abs(p_SwaData->FastSwaOffset.f_WhlVelReDiffFilt);

  /* First time required sample should be 250 and then 500 */
  if(p_SwaData->FastSwaOffset.Vol == 0U)
  {
   u_samples = SWA_FAST_OFFS_SAMPLE_LIMIT;
  }
  else
  {
   u_samples = SWA_FAST_OFFS_SAMPLE_LIMIT_LT;
  }

  if (p_SwaData->FastSwaOffset.u_Number == SWA_FAST_OFFS_SAMPLE_LIMIT_LT)
  {
    p_SwaData->FastSwaOffset.f_Sum    = VDY_ZERO_F;
    p_SwaData->FastSwaOffset.u_Number = VDY_ZERO_U;
  }
    /* only calculate offset if all conditions are met */
  if (   (f_LongAccel < SWA_FAST_OFFS_LONG_ACC_MAX)
      && (f_LatAccel < SWA_OFFS_LAT_ACC_MAX)                                                                            /* Ay < 1.8m/s2 */
      && (VDY_GET_IO_STATE(VDY_SIN_POS_SWA, p_InputData->Signals.State) == (VDYIoStateTypes_t)VDY_IO_STATE_VALID)                          /* steering wheel input signal is valid? */ 
      && (f_SteeringAngle < SWA_OFFS_ANGLE_FAST_OFF_MAX)
      && (f_EgoVel > SWA_FAST_OFFS_VEL_MIN)                                                                             /* input signals showing static situation? */
      && (f_WhlVelFrDiffFiltAbs < SWA_OFFS_WHS_DIFF_VEL)  && (f_WhlVelReDiffFiltAbs < SWA_OFFS_WHS_DIFF_VEL)            /* wheels show straight driving? */                           
      && (u_BankRoad == VDY_ZERO_U)                                                                                       /* If Bent > (2 degree) */
      && (VDY_GET_IO_STATE(VDY_SIN_POS_YWR, p_InputData->Signals.State) == (VDYIoStateTypes_t)VDY_IO_STATE_VALID)       /* Gye input signal is valid? */ 
      && (f_yaw_gye < SWA_OFFS_YAW_RATE_MAX ) 
	 )
  {
    /* collect offset data */
    p_SwaData->FastSwaOffset.f_Sum += p_InputData->Signals.StWheelAngle;
    p_SwaData->FastSwaOffset.u_Number += VDY_ONE_U;
   
    /* are necessary samples collected? */
    if (p_SwaData->FastSwaOffset.u_Number == u_samples)
    {
      /* calculate long term data */
      p_SwaData->FastSwaOffset.SumVol       = p_SwaData->FastSwaOffset.SumVol + p_SwaData->FastSwaOffset.f_Sum;
      p_SwaData->FastSwaOffset.Vol          = p_SwaData->FastSwaOffset.Vol + p_SwaData->FastSwaOffset.u_Number;
      p_SwaData->FastSwaOffset.f_Offset     = p_SwaData->FastSwaOffset.SumVol / (float32)p_SwaData->FastSwaOffset.Vol;
    }
  }

    /* save offset - if state signals no offset available yet */
    if ((p_SwaData->Offset.OffsState < SWA_STATE_2) && \
      (((p_SwaData->FastSwaOffset.Vol == SWA_FAST_OFFS_SAMP_1) ||  \
        (p_SwaData->FastSwaOffset.Vol == SWA_FAST_OFFS_SAMP_2) ||  \
        (p_SwaData->FastSwaOffset.Vol == SWA_FAST_OFFS_SAMP_3) ||  \
        (p_SwaData->FastSwaOffset.Vol == SWA_FAST_OFFS_SAMP_4) ||  \
        (p_SwaData->FastSwaOffset.Vol == SWA_FAST_OFFS_SAMP_5) ||  \
        (p_SwaData->FastSwaOffset.Vol == SWA_FAST_OFFS_SAMP_6) ||  \
        (p_SwaData->FastSwaOffset.Vol == SWA_FAST_OFFS_SAMP_7) ||  \
        (p_SwaData->FastSwaOffset.Vol == SWA_FAST_OFFS_SAMP_8) ||  \
        (p_SwaData->FastSwaOffset.Vol == SWA_FAST_OFFS_SAMP_9)) && \
        (p_SwaData->FastSwaOffset.u_Number == u_samples)) )
      {
       p_SwaData->Offset.Est.Offs = p_SwaData->FastSwaOffset.f_Offset;
       p_SwaData->Offset.Est.Conf = AY_SWA_OFFS_LOW_CONF;

       /* use offset state is greater than initial state then set this flag to 1 */
	   if(p_SwaData->Offset.OffsState > SWA_STATE_DEFAULT)
       {
        p_SwaData->FastSwaOffset.Fast_Offset_State = VDY_ONE_U;
       }		
       /* use offset and store data in nonvolatile memory */
       vdySwaOffsCheckandTakeOver(&p_SwaData->Offset);
      }
   else
      {
       p_SwaData->FastSwaOffset.Fast_Offset_State = VDY_ZERO_U;
      }

    /* Clean Vol and Sum by after 19750 samples */
  if(p_SwaData->FastSwaOffset.Vol > SWA_FAST_OFFS_SAMP_9)
  {
   p_SwaData->FastSwaOffset.SumVol = VDY_ZERO_F;
   p_SwaData->FastSwaOffset.Vol    = VDY_ZERO_U;
  }
}

/** @} */ 
/* EOF */
