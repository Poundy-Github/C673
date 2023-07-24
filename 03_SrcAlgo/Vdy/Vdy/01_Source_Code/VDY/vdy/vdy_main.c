/*! \file **********************************************************************

  @defgroup VDYMainModuleUnit VDY Main Module Unit Design
	@ingroup VDYHandCode
  @{
	  
  $Company:			Continental AG $

  $Component:		VDY (Vehicle Dynamics Observer) $

  $Module:			vdy_main.c $

  @brief 			This module contains the sequencing for the Vehicle Dynamics Component
  
  $Descripion:		$
	  
  $Revision: 1.40.1.7 $

  CHANGES:
  ---*/ /*---
  CHANGE:           $Log: vdy_main.c  $
  CHANGE:           Revision 1.40.1.7 2020/07/29 08:53:52CEST Chinnaswamy, Ramachandra (uids4735) (uids4735) 
  CHANGE:           Detailed Design Update
  CHANGE:           Revision 1.40.1.6 2020/06/08 12:21:04CEST Patle, Mahesh (uidr0487) 
  CHANGE:           - Iif steering wheel angle calibration mode is ON, don't learn the fast SWA offset.
  CHANGE:           Revision 1.40.1.5 2020/05/26 15:43:19CEST Reddy N, Rakesh (uic31759) (uic31759) 
  CHANGE:           VelocityErr DEM set condition when Input velocity is substitute state
  CHANGE:           Revision 1.40.1.4 2019/08/31 07:26:10CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           VDY_E_VEH_VEL_NOT_AVAILABLE and VDY_E_VEH_YWR_NOT_AVAILABLE  is removed as per TMC request
  CHANGE:           Revision 1.40.1.3 2019/06/11 08:36:18CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           QAF Fixes
  CHANGE:           Revision 1.40.1.2 2019/05/30 11:47:14CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           QAF error fix
  CHANGE:           Revision 1.40.1.1 2019/05/25 14:33:07CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           [VDY] QAF Fixes
  CHANGE:           Revision 1.37 2019/04/15 07:42:38CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Implementation of L3_ALGO_VDY_1731
  CHANGE:           Revision 1.36 2019/03/29 10:17:22CET Singh, Sanjiv (uidr1340) 
  CHANGE:           Ctrl mode fix for MFC and ARS in SAE model
  CHANGE:           Revision 1.35 2019/03/29 09:38:45CET Singh, Sanjiv (uidr1340) 
  CHANGE:           SideSlip estimation enabled.
  CHANGE:           +
  CHANGE:           In sideSlip model there , Slip Angle is estimated w.r.t ALD Rear Axle.
  CHANGE:           In previous Model it was ALD Front Axle
  CHANGE:           Revision 1.34 2019/03/22 21:07:30CET Seifi, Sepehr (uidh2503) 
  CHANGE:           Set eSigStatus to AL_SIG_STATE_OK for pNVMWrite proPort signal header in HFL110 according to architecture design decision (under CFG_VDY_HFL switch)
  CHANGE:           Revision 1.33 2019/03/20 07:43:00CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           QAC fixes
  CHANGE:           Revision 1.32 2019/03/19 13:37:05CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           QAC Fixes
  CHANGE:           Revision 1.31 2019/03/15 08:25:13CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           QAC fixes
  CHANGE:           Revision 1.29 2019/03/13 13:15:24CET Singh, Sanjiv (uidr1340) 
  CHANGE:           VDY MAinstream sync w.r.t-
  CHANGE:           
  CHANGE:           VDY checkpoint: AL_VDY_BASE_05.00.19_INT-1
  CHANGE:           CustomCP for ARS510TA19 : AL_VDY_ARS510TA19_CUS_05.00.19.30
  CHANGE:           Revision 1.28 2019/01/31 07:25:27CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Design Update
  CHANGE:           Revision 1.27 2019/01/26 21:24:09CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Followed camel case convention for methods
  CHANGE:           Revision 1.26 2019/01/26 09:22:15CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           QAC fixes
  CHANGE:           Revision 1.25 2019/01/21 10:05:21CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           VDY Velocity Qualifier set to DECREASED State in case of NA or Not Confirmed NVM 
  CHANGE:           No fallback once Velocity Correction Quality set to VERIFIED
  CHANGE:           Revision 1.24 2019/01/09 13:36:56CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Design - Doors Linking
  CHANGE:           Revision 1.23 2019/01/07 14:04:24CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           SW requirmnet link to necessary C-Functions
  CHANGE:           Revision 1.22 2019/01/03 11:15:54CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           UML update
  CHANGE:           Revision 1.21 2019/01/03 10:44:36CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Design Update - UML for functions
  CHANGE:           Revision 1.20 2018/12/14 03:12:56CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Disable steer ratio check,EG and Rear Steer check for projects having no SWA Processing
  CHANGE:           Revision 1.19 2018/12/06 05:35:51CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           QAC Fixes
  CHANGE:           Revision 1.18 2018/12/05 10:53:16CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           QAC fixes
  CHANGE:           Revision 1.17 2018/11/30 05:52:05CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           QAC fixes
  CHANGE:           Revision 1.16 2018/11/29 07:06:55CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           QAC fixes
  CHANGE:           Revision 1.15 2018/11/29 05:18:23CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           QAC fixes
  CHANGE:           Revision 1.14 2018/11/29 03:22:22CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           QAC fixes
  CHANGE:           Revision 1.13 2018/11/15 10:41:22CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           PDO tool support
  CHANGE:           Revision 1.12 2018/11/03 09:33:32CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           BankRoadAngle logic
  CHANGE:           Revision 1.11 2018/10/29 03:20:23CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Non Const Brake_t parameter for vdy_ve_step
  CHANGE:           Revision 1.8 2018/10/26 16:53:21CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Accordance with AL_VDY_BASE_05.00.10_INT-0
  CHANGE:           Revision 1.6 2018/09/17 14:00:06CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Support for courage environment: Defined STATIC_VAR
  CHANGE:           Revision 1.5 2018/09/12 16:23:16CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Support for courage environment
  CHANGE:           Revision 1.4 2018/09/04 12:00:08CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Design Update
  CHANGE:           Revision 1.3 2018/08/28 13:29:38CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Unit Design Update
  CHANGE:           Revision 1.2 2018/08/16 12:37:32CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Removal of CFG_VDY_ALN_MOT_ENABLE
  CHANGE:           Revision 1.1 2018/08/09 10:40:55CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           Initial revision
  CHANGE:           Member added to project /ADAS/SW/Components/VDY_VehicleDynamics/04_Engineering/01_Source_Code/VDY/vdy/project.pj
  CHANGE:           Revision 1.128.3.9.1.2 2018/07/27 06:00:29CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           VDY mearged code for ARS and MFC : Mainstream
  CHANGE:           Revision 1.128.3.9.1.1 2018/07/25 11:48:53CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           VDY mearged code for ARS and MFC : Mainstream
  CHANGE:           Revision 1.128.3.9 2018/07/05 09:37:59CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           argument for -
  CHANGE:           1) Motion state model changed to e-Direction instead of entire AlnStructure bus
  CHANGE:           2) SYE model changed to CtrlMode instead of using frame bus
  CHANGE:           for accomodating MFC and ARS in single source code.
  CHANGE:           Revision 1.128.3.8 2018/06/05 15:00:23CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           warning removed for GM
  CHANGE:           Revision 1.128.3.7 2018/06/05 11:37:37CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           For external curvature ,curve error is hardcoded to 0.0002.
  CHANGE:           As per ACC "For a 100m Safety Distance, required curve error is 0.000175"
  CHANGE:           and
  CHANGE:           Config Switch measfreeze update
  CHANGE:           Revision 1.128.3.6 2018/05/13 10:54:56CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           Inclusion of Aln data in Motion State model call
  CHANGE:           Revision 1.128.3.5 2018/03/21 13:27:49CET Singh, Sanjiv (uidr1340) 
  CHANGE:           Plant Mode small Correction
  CHANGE:           Revision 1.128.3.4 2018/03/21 10:48:07CET Singh, Sanjiv (uidr1340) 
  CHANGE:           VDY should react with PlantMode and RTB mode similarly
  CHANGE:           Revision 1.128.3.3 2018/03/15 06:46:50CET Singh, Sanjiv (uidr1340) 
  CHANGE:           Logic Correction
  CHANGE:           Revision 1.128.3.2 2018/03/14 10:27:26CET Singh, Sanjiv (uidr1340) 
  CHANGE:           Yaw Rate and Curve state improvement-
  CHANGE:           Vdy Yaw Rate and Curve output based on Velocity and SWA&Gye status .
  CHANGE:           For detail -
  CHANGE:           Look into the attached excel sheet of RO.
  CHANGE:           Revision 1.128.3.1 2017/03/31 05:30:40CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           Measfreezed velcor internal varible in internal data cluster
  CHANGE:           +
  CHANGE:           Adaptation of latest VDY Base changes to ARS510
  CHANGE:           Revision 1.128 2017/03/10 12:41:50CET Berwal, Anuj (uidp1444) 
  CHANGE:           -Merged all other Project Branches
  CHANGE:           Revision 1.127 2016/06/28 10:22:49CEST Balachandra, Swathi (uidj2447) 
  CHANGE:           update member rev to 1.1.26
  CHANGE:           Revision 1.126 2016/05/24 10:23:36CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           Fix for freezing VDY NVM request port.
  CHANGE:           Change is kept under a new Switch.
  CHANGE:           Revision 1.125 2016/05/12 14:51:00CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           Two more Unused NVM states and outputs for camera are set to 0.
  CHANGE:           Revision 1.124 2016/04/21 13:39:09CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           Un used NVM states and outputs for camera are set to 0.
  CHANGE:           Revision 1.123 2016/03/02 15:28:12CET Mani, Yugesh (uidj6870) 
  CHANGE:           - Fixed QAC issues
  CHANGE:           Revision 1.122 2016/02/26 11:00:47CET Mani, Yugesh (uidj6870) 
  CHANGE:           - Setting the Output yaw rate to INVALID other than VALID or input signal peak
  CHANGE:           Revision 1.121 2016/02/22 12:49:06CET Singh, Sanjiv (uidr1340) 
  CHANGE:           QAC fixes
  CHANGE:           Revision 1.120 2016/02/19 14:02:06CET Singh, Sanjiv (uidr1340) 
  CHANGE:           adding and enabling of new the DEM(VDY_NVM_LEARN_DATA_ERROR)events logic:with new switch CFG_VDY_NVM_LEARN_DATA_ERROR.
  CHANGE:           +
  CHANGE:           range check done for SSG and WLD while reading from proport
  CHANGE:           Revision 1.119 2016/02/19 07:35:44CET Singh, Sanjiv (uidr1340) 
  CHANGE:           adding and enabling of new the DEM(VDY_NVM_LEARN_DATA_ERROR)events logic:with new switch CFG_VDY_NVM_LEARN_DATA_ERROR.
  CHANGE:           Revision 1.118 2016/02/15 15:43:01CET Mani, Yugesh (uidj6870) 
  CHANGE:           - INIT mode will behave as STARTUP mode with switch for ARS4L1
  CHANGE:           - Added Switch for additional signals of ARS4D1/ARS4D2
  CHANGE:           - Monitoring inputs on both INIT and running mode for other projects
  CHANGE:           Revision 1.117 2016/02/04 08:56:58CET Mani, Yugesh (uidj6870) 
  CHANGE:           - New Velocity monitoring based on new minimum and maximum velocity signals
  CHANGE:           for ARS4D1 and ARS4D2
  CHANGE:           - Added Roller test bench changes to main branch with switch
  CHANGE:           Revision 1.116 2015/09/30 16:28:45CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           for setting output yaw rate invalid input lateral acceleration state is considered instead of output velocity state
  CHANGE:           - Added comments -  uidr1340 [Sep 30, 2015 4:28:46 PM CEST]
  CHANGE:           Change Package : 381850:1 http://mks-psad:7002/im/viewissue?selection=381850
  CHANGE:           Revision 1.115 2015/09/01 12:00:15CEST Mani, Yugesh (uidj6870) 
  CHANGE:           Merging the changes of the yaw offset error from EEPROM to Dynamic when vehicle is moving to reduce curve error
  CHANGE:           --- Added comments ---  uidj6870 [Sep 1, 2015 12:00:15 PM CEST]
  CHANGE:           Change Package : 372340:1 http://mks-psad:7002/im/viewissue?selection=372340
  CHANGE:           Revision 1.114 2015/08/17 13:45:19CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           VDY writes the signal uiVersionNumber of the cluster VDYOffsets not periodically to the MDB. 
  CHANGE:           and
  CHANGE:            QAC+acelera
  CHANGE:           --- Added comments ---  uidr1340 [Aug 17, 2015 1:45:19 PM CEST]
  CHANGE:           Change Package : 368255:1 http://mks-psad:7002/im/viewissue?selection=368255
  CHANGE:           Revision 1.113 2015/08/07 10:31:43CEST Mani, Yugesh (uidj6870) 
  CHANGE:           The Roller test detection flag is reset to false when EM sends roller test bench detection is not active
  CHANGE:           --- Added comments ---  uidj6870 [Aug 7, 2015 10:31:44 AM CEST]
  CHANGE:           Change Package : 365284:1 http://mks-psad:7002/im/viewissue?selection=365284
  CHANGE:           Revision 1.112 2015/08/03 15:52:28CEST Mani, Yugesh (uidj6870) 
  CHANGE:           - Changed the velocity correction code accordingly so that it
  CHANGE:           will hold the previous calculated correction factor and correction quality when roller test bench is detected.
  CHANGE:           - Made the code compatible to all projects
  CHANGE:           --- Added comments ---  uidj6870 [Aug 3, 2015 3:52:28 PM CEST]
  CHANGE:           Change Package : 363759:1 http://mks-psad:7002/im/viewissue?selection=363759
  CHANGE:           Revision 1.111 2015/07/22 12:41:34CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           if yaw rate variance is negative then 
  CHANGE:           proPorts->pVehicleDynamicSignals->Lateral.YawRate.Variance is set to VDY_YAWRATE_MAX_VARIANCE instead of 100
  CHANGE:           --- Added comments ---  uidr1340 [Jul 22, 2015 12:41:34 PM CEST]
  CHANGE:           Change Package : 359360:1 http://mks-psad:7002/im/viewissue?selection=359360
  CHANGE:           Revision 1.110 2015/07/22 09:05:31CEST Pakeer, Sudhakarreddy (uidj6215) 
  CHANGE:           To avoid wrong initialization during driving, the old velocity used for the acceleration computation is initialized using the signal value
  CHANGE:           --- Added comments ---  uidj6215 [Jul 22, 2015 9:05:31 AM CEST]
  CHANGE:           Change Package : 359415:1 http://mks-psad:7002/im/viewissue?selection=359415
  CHANGE:           Revision 1.109 2015/07/16 08:28:38CEST Pakeer, Sudhakarreddy (uidj6215) 
  CHANGE:           - Bugfix for setting output yaw rate state.
  CHANGE:           --- Added comments ---  uidj6215 [Jul 16, 2015 8:28:38 AM CEST]
  CHANGE:           Change Package : 357840:1 http://mks-psad:7002/im/viewissue?selection=357840
  CHANGE:           Revision 1.108 2015/07/01 16:04:05CEST Pakeer, Sudhakarreddy (uidj6215) 
  CHANGE:           --> Not allowing the VDY learning's and VDY velocity correction when VDY ego velocity is not set to zero during the roller test bench detection .
  CHANGE:           --- Added comments ---  uidj6215 [Jul 1, 2015 4:04:06 PM CEST]
  CHANGE:           Change Package : 352803:1 http://mks-psad:7002/im/viewissue?selection=352803
  CHANGE:           Revision 1.107 2015/04/22 13:23:56CEST Mani, Yugesh (uidj6870) 
  CHANGE:           Merged the changes of Roller test bench from verion 1.104.1.2
  CHANGE:           --- Added comments ---  uidj6870 [Apr 22, 2015 1:23:56 PM CEST]
  CHANGE:           Change Package : 331063:1 http://mks-psad:7002/im/viewissue?selection=331063
  CHANGE:           Revision 1.106 2015/04/22 13:15:32CEST Mani, Yugesh (uidj6870) 
  CHANGE:           Reverted back to 1.104 version and added the changes in VDYCalculateLaneErrorConf() for invalid input signal state
  CHANGE:           --- Added comments ---  uidj6870 [Apr 22, 2015 1:15:32 PM CEST]
  CHANGE:           Change Package : 331063:1 http://mks-psad:7002/im/viewissue?selection=331063
  CHANGE:           Revision 1.105 2015/03/05 08:23:38CET Pakeer, Sudhakarreddy (uidj6215) 
  CHANGE:           ---> Added the ALN inputs to VDYProcMotionState function for processing of motion state estimation in autocode
  CHANGE:           --- Added comments ---  uidj6215 [Mar 5, 2015 8:23:38 AM CET]
  CHANGE:           Change Package : 275775:11 http://mks-psad:7002/im/viewissue?selection=275775
  CHANGE:           Revision 1.104 2015/02/04 10:51:51CET Wolter, Frank (wolterf) 
  CHANGE:           - allowed setting of debouncing counter for invalid input signals in the custom config
  CHANGE:           --- Added comments ---  wolterf [Feb 4, 2015 10:51:52 AM CET]
  CHANGE:           Change Package : 303042:1 http://mks-psad:7002/im/viewissue?selection=303042
  CHANGE:           Revision 1.103 2015/01/27 07:40:42CET Balachandra, Swathi (uidj2447) 
  CHANGE:           Use of the VehDyn version number to mask ethe code with use of Zero point offset compensated steering wheel angle signal in struct Vehdyn with an #ifdef to keep it compatible to older RTEsand other projects
  CHANGE:           --- Added comments ---  uidj2447 [Jan 27, 2015 7:40:42 AM CET]
  CHANGE:           Change Package : 299920:1 http://mks-psad:7002/im/viewissue?selection=299920
  CHANGE:           Revision 1.102 2015/01/16 10:26:56CET Balachandra, Swathi (uidj2447) 
  CHANGE:           providing the zero pint offset compensation steering wheel angle signal at the vehdyn ouput.
  CHANGE:           --- Added comments ---  uidj2447 [Jan 16, 2015 10:26:56 AM CET]
  CHANGE:           Change Package : 296635:2 http://mks-psad:7002/im/viewissue?selection=296635
  CHANGE:           Revision 1.101 2014/12/05 05:47:28CET Balachandra, Swathi (uidj2447) 
  CHANGE:           Updation on Steering wheel, lateral acceleration and wheel speed yaw rates to  have correct  sign when driving reverse direction.
  CHANGE:           --- Added comments ---  uidj2447 [Dec 5, 2014 5:47:29 AM CET]
  CHANGE:           Change Package : 278584:1 http://mks-psad:7002/im/viewissue?selection=278584
  CHANGE:           Revision 1.100 2014/12/03 11:26:44CET Balachandra, Swathi (uidj2447) 
  CHANGE:           Fix for QAC Misra violations and Bug fix for VDY DEM EVENTS function
  CHANGE:           --- Added comments ---  uidj2447 [Dec 3, 2014 11:26:44 AM CET]
  CHANGE:           Change Package : 278585:1 http://mks-psad:7002/im/viewissue?selection=278585
  CHANGE:           Revision 1.99 2014/12/03 07:33:14CET Pakeer, Sudhakarreddy (uidj6215) 
  CHANGE:           ---> added if defined condition in the VDYGetConfig for the Roll Test Bench
  CHANGE:           --- Added comments ---  uidj6215 [Dec 3, 2014 7:33:14 AM CET]
  CHANGE:           Change Package : 187594:23 http://mks-psad:7002/im/viewissue?selection=187594
  CHANGE:           Revision 1.98 2014/11/28 11:29:49CET Pakeer, Sudhakarreddy (uidj6215) 
  CHANGE:           Setting  ego velocity to 0 when Roller Test Bench was recognized
  CHANGE:           --- Added comments ---  uidj6215 [Nov 28, 2014 11:29:49 AM CET]
  CHANGE:           Change Package : 187594:3 http://mks-psad:7002/im/viewissue?selection=187594
  CHANGE:           Revision 1.97 2014/11/04 06:30:08CET Balachandra, Swathi (uidj2447) 
  CHANGE:           -Use of macro "CFG_VDY_SET_DEM_EVENTS" in main function for calling,declaring and defining the VDYSetDEMEvents function.
  CHANGE:           -Addition  of (void) pVDYOffsets in VDYCalculateCurveError() function to get rid of QAC warning.
  CHANGE:           --- Added comments ---  uidj2447 [Nov 4, 2014 6:30:09 AM CET]
  CHANGE:           Change Package : 273353:3 http://mks-psad:7002/im/viewissue?selection=273353
  CHANGE:           Revision 1.96 2014/10/01 10:15:40CEST Wolter, Frank (wolterf) 
  CHANGE:           - added axle load distribution in curve error calculation
  CHANGE:           - added check for undefined operation modes
  CHANGE:           --- Added comments ---  wolterf [Oct 1, 2014 10:15:40 AM CEST]
  CHANGE:           Change Package : 264939:1 http://mks-psad:7002/im/viewissue?selection=264939
  CHANGE:           Revision 1.95 2014/09/17 16:46:42CEST Wolter, Frank (wolterf) 
  CHANGE:           - calculating wheel yaw rate error in curve error
  CHANGE:           - set curve error limits if offset calculation is disabled
  CHANGE:           --- Added comments ---  wolterf [Sep 17, 2014 4:46:42 PM CEST]
  CHANGE:           Change Package : 264939:1 http://mks-psad:7002/im/viewissue?selection=264939
  CHANGE:           Revision 1.94 2014/08/14 12:44:35CEST Wolter, Frank (wolterf) 
  CHANGE:           Re-Init of sye model if driver intended curve cannot start
  CHANGE:           --- Added comments ---  wolterf [Aug 14, 2014 12:44:35 PM CEST]
  CHANGE:           Change Package : 256683:1 http://mks-psad:7002/im/viewissue?selection=256683
  CHANGE:           Revision 1.93 2014/08/12 15:20:39CEST Balachandra, Swathi (uidj2447) 
  CHANGE:           Organization of cutom configuarations and addition of Custom config version number
  CHANGE:           --- Added comments ---  uidj2447 [Aug 12, 2014 3:20:40 PM CEST]
  CHANGE:           Change Package : 256090:1 http://mks-psad:7002/im/viewissue?selection=256090
  CHANGE:           Revision 1.92 2014/07/28 16:22:04CEST Wolter, Frank (wolterf) 
  CHANGE:           - added delta timestamp meas freeze
  CHANGE:           - restart of models only after variance was negative 5 times
  CHANGE:           - added seperate switch for reporting DEM events with servive function
  CHANGE:           --- Added comments ---  wolterf [Jul 28, 2014 4:22:05 PM CEST]
  CHANGE:           Change Package : 252144:1 http://mks-psad:7002/im/viewissue?selection=252144
  CHANGE:           Revision 1.91 2014/07/24 08:52:43CEST Wolter, Frank (wolterf) 
  CHANGE:           - better integration of steering wheel offset estimation
  CHANGE:           - removed double correction of velocity
  CHANGE:           - removed overwriting of acceleration if variance is calculated from internal acceleration
  CHANGE:           --- Added comments ---  wolterf [Jul 24, 2014 8:52:44 AM CEST]
  CHANGE:           Change Package : 250600:1 http://mks-psad:7002/im/viewissue?selection=250600
  CHANGE:           Revision 1.90 2014/07/10 12:19:55CEST Wolter, Frank (wolterf) 
  CHANGE:           - copy input signals for signal peak detection in INIT phase
  CHANGE:           --- Added comments ---  wolterf [Jul 10, 2014 12:19:56 PM CEST]
  CHANGE:           Change Package : 245598:1 http://mks-psad:7002/im/viewissue?selection=245598
  CHANGE:           Revision 1.89 2014/07/08 12:50:20CEST Wolter, Frank (wolterf) 
  CHANGE:           - calling fast steering wheel angle offset estimation
  CHANGE:           - removed MISRA violations
  CHANGE:           --- Added comments ---  wolterf [Jul 8, 2014 12:50:20 PM CEST]
  CHANGE:           Change Package : 247013:1 http://mks-psad:7002/im/viewissue?selection=247013
  CHANGE:           Revision 1.88 2014/06/25 16:27:59CEST Wolter, Frank (wolterf) 
  CHANGE:           Removed const from VDYErrors in VDYAutocodeProcess() function parameter
  CHANGE:           --- Added comments ---  wolterf [Jun 25, 2014 4:28:00 PM CEST]
  CHANGE:           Change Package : 244175:1 http://mks-psad:7002/im/viewissue?selection=244175
  CHANGE:           Revision 1.87 2014/06/18 16:31:33CEST Wolter, Frank (wolterf) 
  CHANGE:           Implemented setting of DEM events via service function
  CHANGE:           --- Added comments ---  wolterf [Jun 18, 2014 4:31:34 PM CEST]
  CHANGE:           Change Package : 243308:1 http://mks-psad:7002/im/viewissue?selection=243308
  CHANGE:           Revision 1.86 2014/05/27 15:44:08CEST Wolter, Frank (wolterf) 
  CHANGE:           Made VDYIn static to avoid possible stack issues between cores
  CHANGE:           --- Added comments ---  wolterf [May 27, 2014 3:44:09 PM CEST]
  CHANGE:           Change Package : 239729:1 http://mks-psad:7002/im/viewissue?selection=239729
  CHANGE:           Revision 1.85 2014/05/08 14:17:06CEST Wolter, Frank (wolterf) 
  CHANGE:           - correction if slip angle estimation is enabled
  CHANGE:           --- Added comments ---  wolterf [May 8, 2014 2:17:06 PM CEST]
  CHANGE:           Change Package : 235009:1 http://mks-psad:7002/im/viewissue?selection=235009
  CHANGE:           Revision 1.84 2014/05/06 17:09:09CEST Wolter, Frank (wolterf) 
  CHANGE:           - changed output state handling in case of invalid input states
  CHANGE:           - set NVM state to invalid if SSG and WhlLoad parameters are on defaults
  CHANGE:           - correction of brake activation level value in debouncing check
  CHANGE:           - restart of ye model if Kalman filter cannot calculate gain
  CHANGE:           --- Added comments ---  wolterf [May 6, 2014 5:09:10 PM CEST]
  CHANGE:           Change Package : 234720:1 http://mks-psad:7002/im/viewissue?selection=234720
  CHANGE:           Revision 1.83 2014/04/08 16:12:56CEST Wolter, Frank (wolterf) 
  CHANGE:           - debouncing of signal inputs
  CHANGE:           - timestamp is generated if not provided
  CHANGE:           - removed task monitoring as functionality is not supported in the system
  CHANGE:           - doxygen function header
  CHANGE:           - removed MISRA violations
  CHANGE:           --- Added comments ---  wolterf [Apr 8, 2014 4:12:56 PM CEST]
  CHANGE:           Change Package : 229571:1 http://mks-psad:7002/im/viewissue?selection=229571
  CHANGE:           Revision 1.82 2014/03/15 16:33:48CET Wolter, Frank (wolterf) 
  CHANGE:           - moved VDYMonitorOutput and VDYAlignmentYawOffsMonitor to VDYPostProcess
  CHANGE:           - moved meas freeze of sync ref to VDYEnvMeasFreezeInternal
  CHANGE:           - only invalid and not degraded steering angle and velocity inputs lead to an invalid cuve output
  CHANGE:           - removed MISRA violations
  CHANGE:           Revision 1.81 2014/03/12 16:21:14CET Wolter, Frank (wolterf) 
  CHANGE:           - implemented curve error and confidence
  CHANGE:           - direct freeze of all meas freezes to avoid empty or corrupt frames
  CHANGE:           - meas freeze of YE Kalman gain
  CHANGE:           --- Added comments ---  wolterf [Mar 12, 2014 4:21:15 PM CET]
  CHANGE:           Change Package : 219038:1 http://mks-psad:7002/im/viewissue?selection=219038
  CHANGE:           Revision 1.80 2014/03/07 12:33:10CET Wolter, Frank (wolterf) 
  CHANGE:           - removed non-Autosar types
  CHANGE:           - removed warnings
  CHANGE:           --- Added comments ---  wolterf [Mar 7, 2014 12:33:10 PM CET]
  CHANGE:           Change Package : 223834:1 http://mks-psad:7002/im/viewissue?selection=223834
  CHANGE:           Revision 1.79 2014/02/07 12:59:53CET Wolter, Frank (wolterf) 
  CHANGE:           - use of NVM state macros
  CHANGE:           --- Added comments ---  wolterf [Feb 7, 2014 12:59:53 PM CET]
  CHANGE:           Change Package : 217717:1 http://mks-psad:7002/im/viewissue?selection=217717
  CHANGE:           Revision 1.78 2014/01/28 15:57:42CET Wolter, Frank (wolterf) 
  CHANGE:           - changed input and output signal status interface
  CHANGE:           - added Kalman gains and KF fault status to output of ye model
  CHANGE:           --- Added comments ---  wolterf [Jan 28, 2014 3:57:42 PM CET]
  CHANGE:           Change Package : 208447:1 http://mks-psad:7002/im/viewissue?selection=208447
  CHANGE:           Revision 1.77 2014/01/24 18:01:06CET Wolter, Frank (wolterf) 
  CHANGE:           changedservices parameter in init freeze function to const pointer
  CHANGE:           --- Added comments ---  wolterf [Jan 24, 2014 6:01:06 PM CET]
  CHANGE:           Change Package : 215290:1 http://mks-psad:7002/im/viewissue?selection=215290
  CHANGE:           Revision 1.76 2014/01/24 12:27:26CET Wolter, Frank (wolterf) 
  CHANGE:           - added check of ports for NULL pointer
  CHANGE:           - corrected MEASFuncChannelID
  CHANGE:           --- Added comments ---  wolterf [Jan 24, 2014 12:27:27 PM CET]
  CHANGE:           Change Package : 215290:1 http://mks-psad:7002/im/viewissue?selection=215290
  CHANGE:           Revision 1.75 2014/01/14 16:13:05CET Wolter, Frank (wolterf) 
  CHANGE:           Added initialisation of steering wheel curve in internal data if steering wheel usage is not configured
  CHANGE:           (needed to correctly merge yaw rate and steering wheel curves)
  CHANGE:           --- Added comments ---  wolterf [Jan 14, 2014 4:13:06 PM CET]
  CHANGE:           Change Package : 213360:1 http://mks-psad:7002/im/viewissue?selection=213360
  CHANGE:           Revision 1.74 2013/12/06 15:03:33CET Wolter, Frank (wolterf) 
  CHANGE:           Added Services to function call for functions which do profiling
  CHANGE:           --- Added comments ---  wolterf [Dec 6, 2013 3:03:33 PM CET]
  CHANGE:           Change Package : 209059:1 http://mks-psad:7002/im/viewissue?selection=209059
  CHANGE:           Revision 1.73 2013/11/29 11:21:42CET Wolter, Frank (wolterf) 
  CHANGE:           - meas freeze functional ID also put in FuncChannelID
  CHANGE:           - update of cycle counter and sig status in sync frame
  CHANGE:           - added call of MeasStartFuncCycle
  CHANGE:           - added check if cycle time is not too high
  CHANGE:           - VehDyn initialised in every cycle to avoid undefined values in unused bytes
  CHANGE:           - sig status added to all output ports
  CHANGE:           - inputs only monitored in running mode
  CHANGE:           - autocode modules only called if active in configuration
  CHANGE:           - vehicle speed from wheels used if external velocity is not available
  CHANGE:           --- Added comments ---  wolterf [Nov 29, 2013 11:21:42 AM CET]
  CHANGE:           Change Package : 209059:1 http://mks-psad:7002/im/viewissue?selection=209059
  CHANGE:           Revision 1.72 2013/10/08 15:27:16CEST Wolter, Frank (wolterf) 
  CHANGE:           - filled signal header for offsets, errors, curves and NVMWrite
  CHANGE:           - added SyncFrame freeze
  CHANGE:           - changed measfreeze FuncID to new cycle IDs
  CHANGE:           Revision 1.71 2013/09/27 16:28:57CEST Wolter, Frank (wolterf) 
  CHANGE:           - update code review by ICT
  CHANGE:           - Code Review #339136
  CHANGE:           - implemented QAC MISRA findings
  CHANGE:           - grammar/spelling corrections
  CHANGE:           - corrected freeze of VDYConfig (FR 139703)
  CHANGE:           Revision 1.70 2013/08/23 14:56:47CEST Wolter, Frank (wolterf) 
  CHANGE:           corrected freeze of provide ports
  CHANGE:           --- Added comments ---  wolterf [Aug 23, 2013 2:56:48 PM CEST]
  CHANGE:           Change Package : 190608:6 http://mks-psad:7002/im/viewissue?selection=190608
  CHANGE:           Revision 1.69 2013/08/07 17:02:16CEST Wolter, Frank (wolterf) 
  CHANGE:           freezing provided ports
  CHANGE:           --- Added comments ---  wolterf [Aug 7, 2013 5:02:17 PM CEST]
  CHANGE:           Change Package : 190608:6 http://mks-psad:7002/im/viewissue?selection=190608
  CHANGE:           Revision 1.68 2013/07/23 13:56:33CEST Wolter, Frank (wolterf) 
  CHANGE:           timestamp taken from sig header
  CHANGE:           --- Added comments ---  wolterf [Jul 23, 2013 1:56:33 PM CEST]
  CHANGE:           Change Package : 188036:1 http://mks-psad:7002/im/viewissue?selection=188036
  CHANGE:           Revision 1.67 2013/07/22 16:33:53CEST Wolter, Frank (wolterf) 
  CHANGE:           vdy_main.c
  CHANGE:           - switched types to Autosar types
  CHANGE:           - usage of service functions parameter only if used in project setup (checked by service function version number)
  CHANGE:           - merge in of rev. 1.66.1.1: adapted profiling and deactivated runtime checkpoints
  CHANGE:           - removed unused macros
  CHANGE:           - removed 64 bit timestamp
  CHANGE:           - layout/spelling corrections
  CHANGE:           --- Added comments ---  wolterf [Jul 22, 2013 4:33:53 PM CEST]
  CHANGE:           Change Package : 188036:1 http://mks-psad:7002/im/viewissue?selection=188036
  CHANGE:           Revision 1.66 2013/03/19 16:01:55CET Wolter, Frank (wolterf) 
  CHANGE:           Adaptation to common adapter: implemented service functions (third algo parameter)
  CHANGE:           --- Added comments ---  wolterf [Mar 19, 2013 4:02:16 PM CET]
  CHANGE:           Change Package : 177967:1 http://mks-psad:7002/im/viewissue?selection=177967
  CHANGE:           Revision 1.65 2013/02/05 17:15:35CET Wolter, Frank (wolterf) 
  CHANGE:           Added curve output peak monitoring to limit curve output if steering wheel input becomes invalid
  CHANGE:           --- Added comments ---  wolterf [Feb 5, 2013 5:15:35 PM CET]
  CHANGE:           Change Package : 172942:1 http://mks-psad:7002/im/viewissue?selection=172942
  CHANGE:           Revision 1.64 2012/10/22 13:49:31CEST Wolter, Frank (wolterf) 
  CHANGE:           added meas freeze for FS velocity monitor
  CHANGE:           removed misra violations
  CHANGE:           --- Added comments ---  wolterf [Oct 22, 2012 1:49:44 PM CEST]
  CHANGE:           Change Package : 158544:1 http://mks-psad:7002/im/viewissue?selection=158544
  CHANGE:           Revision 1.63 2012/09/17 12:45:10CEST Wolter, Frank (wolterf) 
  CHANGE:           Corrected MEAS address of YwrtTempTable
  CHANGE:           --- Added comments ---  wolterf [Sep 17, 2012 12:45:18 PM CEST]
  CHANGE:           Change Package : 159305:1 http://mks-psad:7002/im/viewissue?selection=159305
  CHANGE:           Revision 1.62 2012/02/06 10:28:24CET Spruck, Jochen (spruckj) 
  CHANGE:           Merge SRR changes to trunk
  CHANGE:           --- Added comments ---  spruckj [Feb 6, 2012 10:28:27 AM CET]
  CHANGE:           Change Package : 95623:2 http://mks-psad:7002/im/viewissue?selection=95623
  CHANGE:           Revision 1.57.1.3 2012/02/02 08:22:01CET Spruck, Jochen (spruckj) 
  CHANGE:           Correct preprocessor switch, use swa switch instead of yaw rate switch
  CHANGE:           --- Added comments ---  spruckj [Feb 2, 2012 8:22:03 AM CET]
  CHANGE:           Change Package : 95623:1 http://mks-psad:7002/im/viewissue?selection=95623
  CHANGE:           Revision 1.57.1.2 2012/01/13 10:40:08CET Spruck, Jochen (spruckj) 
  CHANGE:           switch of some code if the aln sensor yaw rate is disabled
  CHANGE:           --- Added comments ---  spruckj [Jan 13, 2012 10:43:57 AM CET]
  CHANGE:           Change Package : 93372:1 http://mks-psad:7002/im/viewissue?selection=93372
  CHANGE:           Revision 1.60 2011/12/13 16:44:39CET Spruck, Jochen (spruckj) 
  CHANGE:           set vel corr output state similar to the velocity.
  CHANGE:           --- Added comments ---  spruckj [Dec 13, 2011 4:44:44 PM CET]
  CHANGE:           Change Package : 90999:1 http://mks-psad:7002/im/viewissue?selection=90999
  CHANGE:           Revision 1.59 2011/12/09 14:16:19CET Spruck, Jochen (spruckj) 
  CHANGE:           Do Input and Output Monitoring only if VDY is in Running mode
  CHANGE:           --- Added comments ---  spruckj [Dec 9, 2011 2:16:21 PM CET]
  CHANGE:           Change Package : 91199:1 http://mks-psad:7002/im/viewissue?selection=91199
  CHANGE:           Revision 1.58 2011/12/06 11:24:20CET Spruck, Jochen (spruckj) 
  CHANGE:           - Replace all checkes with == 0.0F and != 0.0F, with <= or >= small value
  CHANGE:           - Use now ROUND_TO_INT and ROUND_TO_UINT instead of ROUND
  CHANGE:           --- Added comments ---  spruckj [Dec 6, 2011 11:24:22 AM CET]
  CHANGE:           Change Package : 90149:1 http://mks-psad:7002/im/viewissue?selection=90149
  CHANGE:           Revision 1.57 2011/10/25 10:52:23CEST Spruck, Jochen (spruckj) 
  CHANGE:           - Make external interface est curves switchable
  CHANGE:           - Add some additional switches to remove compier warings
  CHANGE:           --- Added comments ---  spruckj [Oct 25, 2011 10:52:23 AM CEST]
  CHANGE:           Change Package : 85246:1 http://mks-psad:7002/im/viewissue?selection=85246
  CHANGE:           Revision 1.56 2011/09/20 16:36:41CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGE:           If the wheel yaw rate estimation is deactivated the offset from 
  CHANGE:           the yaw rate stand still offset should be used for the sensor yaw rate estimation
  CHANGE:           --- Added comments ---  spruckj [Sep 20, 2011 4:36:43 PM CEST]
  CHANGE:           Change Package : 78945:1 http://mks-psad:7002/im/viewissue?selection=78945
  CHANGE:           Revision 1.55 2011/09/08 08:52:48CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGE:           Remove the locat VDYCurve memory
  CHANGE:           Revision 1.54 2011/09/07 18:11:16CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGE:           Switch to the rte VDYEstCurves type
  CHANGE:           --- Added comments ---  spruckj [Sep 7, 2011 6:11:16 PM CEST]
  CHANGE:           Change Package : 75670:1 http://mks-psad:7002/im/viewissue?selection=75670
  CHANGE:           Revision 1.53 2011/08/23 09:41:45CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGE:           Remove some small misra/lint issues
  CHANGE:           --- Added comments ---  spruckj [Aug 23, 2011 9:41:45 AM CEST]
  CHANGE:           Change Package : 46866:16 http://mks-psad:7002/im/viewissue?selection=46866
  CHANGE:           Revision 1.52 2011/08/03 10:02:57CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGE:           - Add memory section definition to vdy code
  CHANGE:           - Put vdy fusi errors to the output
  CHANGE:           - Move spm vdy yaw rate and velocity output monitoring to vdy
  CHANGE:           --- Added comments ---  spruckj [Aug 3, 2011 10:02:57 AM CEST]
  CHANGE:           Change Package : 74444:1 http://mks-psad:7002/im/viewissue?selection=74444
  CHANGE:           Revision 1.51 2011/06/28 09:19:51CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGE:           Merge some bug fixes from B5 and add some additional compiler switches to remove wrong detected runntime errors
  CHANGE:           --- Added comments ---  spruckj [Jun 28, 2011 9:19:51 AM CEST]
  CHANGE:           Change Package : 70946:1 http://mks-psad:7002/im/viewissue?selection=70946
  CHANGE:           Revision 1.50 2011/06/28 09:13:56CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGE:           Merge some bug fixes from B5 and add some additional compiler switches to remove wrong detected runntime errors
  CHANGE:           --- Added comments ---  spruckj [Jun 28, 2011 9:13:57 AM CEST]
  CHANGE:           Change Package : 70946:1 http://mks-psad:7002/im/viewissue?selection=70946
  CHANGE:           Revision 1.49 2011/06/08 16:13:40CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGE:           - Update config vdy file to wabco secific input signals 
  CHANGE:           - Disable velocity monitoring 
  CHANGE:           - change temp range to calc temp table index to -40 - 105°C
  CHANGE:           - remove NVM temp table write counter observer
  CHANGE:           --- Added comments ---  spruckj [Jun 8, 2011 4:13:40 PM CEST]
  CHANGE:           Change Package : 69568:1 http://mks-psad:7002/im/viewissue?selection=69568
  CHANGE:           Revision 1.48 2011/05/18 08:51:24CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGE:           remove compiler warning
  CHANGE:           --- Added comments ---  spruckj [May 18, 2011 8:51:25 AM CEST]
  CHANGE:           Change Package : 46866:8 http://mks-psad:7002/im/viewissue?selection=46866
  CHANGE:           Revision 1.47 2011/05/05 11:07:53CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGE:           use the quality and yaw rate offset type form the internal yaw rate module,
  CHANGE:           instead of the external yaw rate offset module.
  CHANGE:           --- Added comments ---  spruckj [May 5, 2011 11:07:53 AM CEST]
  CHANGE:           Change Package : 60263:1 http://mks-psad:7002/im/viewissue?selection=60263
  CHANGE:           Revision 1.46 2011/05/05 10:33:42CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGE:           Make vdy yaw rate offset configurable during run time.
  CHANGE:           If the internal yaw rate processing is enabled and an external yaw rate is also provided,
  CHANGE:           the external yaw rate is used
  CHANGE:           --- Added comments ---  spruckj [May 5, 2011 10:33:42 AM CEST]
  CHANGE:           Change Package : 60263:1 http://mks-psad:7002/im/viewissue?selection=60263
  CHANGE:           Revision 1.45 2011/04/27 09:18:57CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGE:           Remove some misra issues
  CHANGE:           --- Added comments ---  spruckj [Apr 27, 2011 9:18:57 AM CEST]
  CHANGE:           Change Package : 43275:2 http://mks-psad:7002/im/viewissue?selection=43275
  CHANGE:           Revision 1.44 2011/02/15 15:55:35CET Spruck Jochen (spruckj) (spruckj) 
  CHANGE:           - Integration of internal yaw rate processing
  CHANGE:           - Fix some lint/misra issues
  CHANGE:           --- Added comments ---  spruckj [Feb 15, 2011 3:55:36 PM CET]
  CHANGE:           Change Package : 59398:1 http://mks-psad:7002/im/viewissue?selection=59398
  CHANGE:           Revision 1.43 2011/02/14 09:07:32CET Jochen Spruck (spruckj) 
  CHANGE:           Fix vdy sil-sil problems,
  CHANGE:           acceleration is calcalated with the ext velocity, and filterd, the filter was not initalized
  CHANGE:           --- Added comments ---  spruckj [Feb 14, 2011 9:07:32 AM CET]
  CHANGE:           Change Package : 59368:1 http://mks-psad:7002/im/viewissue?selection=59368
  CHANGE:           Revision 1.42 2011/02/11 13:31:53CET Jochen Spruck (spruckj) 
  CHANGE:           Add the 64 time stamp interface to the vdy component and vdy simulation dll
  CHANGE:           --- Added comments ---  spruckj [Feb 11, 2011 1:31:53 PM CET]
  CHANGE:           Change Package : 59318:1 http://mks-psad:7002/im/viewissue?selection=59318
  CHANGE:           Revision 1.41 2011/01/17 15:02:03CET Jochen Spruck (spruckj) 
  CHANGE:           correct config switch if yaw rate offset estimation and correction is disabled
  CHANGE:           --- Added comments ---  spruckj [Jan 17, 2011 3:02:03 PM CET]
  CHANGE:           Change Package : 55693:4 http://mks-psad:7002/im/viewissue?selection=55693
  CHANGE:           Revision 1.40 2010/12/08 14:26:15CET Jochen Spruck (spruckj) 
  CHANGE:           sequence init bug fix,
  CHANGE:           for wpp the size of the freeze was calculated wrong
  CHANGE:           --- Added comments ---  spruckj [Dec 8, 2010 2:26:15 PM CET]
  CHANGE:           Change Package : 51886:1 http://mks-psad:7002/im/viewissue?selection=51886
  CHANGE:           Revision 1.39 2010/12/01 11:35:46CET Jochen Spruck (spruckj) 
  CHANGE:           Update yaw rate offset output type, add fast and short stand still as offset types
  CHANGE:           --- Added comments ---  spruckj [Dec 1, 2010 11:35:47 AM CET]
  CHANGE:           Change Package : 51891:1 http://mks-psad:7002/im/viewissue?selection=51891
  CHANGE:           Revision 1.38 2010/12/01 10:33:44CET Jochen Spruck (spruckj) 
  CHANGE:           Set aln yaw rate offset stat always to stand still, if yaw rate offset compenstation is switched off
  CHANGE:           --- Added comments ---  spruckj [Dec 1, 2010 10:33:45 AM CET]
  CHANGE:           Change Package : 55982:1 http://mks-psad:7002/im/viewissue?selection=55982
  CHANGE:           Revision 1.37 2010/11/26 11:58:50CET Jochen Spruck (spruckj) 
  CHANGE:           Add the offset states to the vdy output yaw rate offset state
  CHANGE:           Revision 1.36 2010/11/23 15:55:20CET Jochen Spruck (spruckj) 
  CHANGE:           Add algo sys time and cycle counter to vdy output
  CHANGE:           Revision 1.35 2010/11/12 12:12:01CET Jochen Spruck (spruckj) 
  CHANGE:           Remove misra and lint issues
  CHANGE:           Add review tags
  CHANGE:           Revision 1.34 2010/11/11 17:50:35CET Jochen Spruck (spruckj) 
  CHANGE:           Remove usage of external uncertaity
  CHANGE:           Use instead fixed parameters from the par file
  CHANGE:           --- Added comments ---  spruckj [Nov 11, 2010 5:50:35 PM CET]
  CHANGE:           Change Package : 54386:1 http://mks-psad:7002/im/viewissue?selection=54386
  CHANGE:           Revision 1.33 2010/11/11 17:34:40CET Jochen Spruck (spruckj) 
  CHANGE:           remove bool signal state of the VehDyn
  CHANGE:           Revision 1.32 2010/10/14 09:02:23CEST Jochen Spruck (spruckj) 
  CHANGE:           Misra/lint bug fix, redifined errors with target compiler
  CHANGE:           --- Added comments ---  spruckj [Oct 14, 2010 9:02:23 AM CEST]
  CHANGE:           Change Package : 52020:1 http://mks-psad:7002/im/viewissue?selection=52020
  CHANGE:           Revision 1.31 2010/10/13 16:44:08CEST Jochen Spruck (spruckj) 
  CHANGE:           The quality of the aln yaw rate should be only the reduce quality
  CHANGE:           Revision 1.30 2010/10/13 16:37:47CEST Jochen Spruck (spruckj) 
  CHANGE:           Misra lint bug fix
  CHANGE:           Revision 1.29 2010/10/13 14:12:57CEST Jochen Spruck (spruckj) 
  CHANGE:           fix Misra/Lint Issues
  CHANGE:           --- Added comments ---  spruckj [Oct 13, 2010 2:12:57 PM CEST]
  CHANGE:           Change Package : 52020:1 http://mks-psad:7002/im/viewissue?selection=52020
  CHANGE:           Revision 1.28 2010/10/07 13:26:22CEST Tandler Joachim (uidk7536) (uidk7536) 
  CHANGE:           SIGNAL_(IN)VALID is not defined in the RTE. Use TRUE/FALSE instead
  CHANGE:           --- Added comments ---  uidk7536 [Oct 7, 2010 1:26:23 PM CEST]
  CHANGE:           Change Package : 52797:1 http://mks-psad:7002/im/viewissue?selection=52797
  CHANGE:           Revision 1.27 2010/09/10 11:25:05CEST Jochen Spruck (spruckj) 
  CHANGE:           Add version nummbers for vdy output ports, nvm_write, offsets, errors
  CHANGE:           --- Added comments ---  spruckj [Sep 10, 2010 11:25:05 AM CEST]
  CHANGE:           Change Package : 43275:1 http://mks-psad:7002/im/viewissue?selection=43275
  CHANGE:           Revision 1.26 2010/08/12 10:45:56CEST Jochen Spruck (spruckj) 
  CHANGE:           Bug fix sequence init of vdy, wrong pointer aritmetic, calculation the meas frezze package size
  CHANGE:           --- Added comments ---  spruckj [Aug 12, 2010 10:45:56 AM CEST]
  CHANGE:           Change Package : 45196:2 http://mks-psad:7002/im/viewissue?selection=45196
  CHANGE:           Revision 1.25 2010/08/09 10:36:52CEST Jochen Spruck (spruckj) 
  CHANGE:           Use compact enums, and use buffered instead of direct freeze for sequence init freeze
  CHANGE:           --- Added comments ---  spruckj [Aug 9, 2010 10:36:52 AM CEST]
  CHANGE:           Change Package : 47577:2 http://mks-psad:7002/im/viewissue?selection=47577
  CHANGE:           Revision 1.24 2010/07/28 12:28:11CEST Jochen Spruck (spruckj) 
  CHANGE:           Bug Fix sequence init state, wrong var name
  CHANGE:           --- Added comments ---  spruckj [Jul 28, 2010 12:28:11 PM CEST]
  CHANGE:           Change Package : 43283:1 http://mks-psad:7002/im/viewissue?selection=43283
  CHANGE:           Revision 1.23 2010/07/27 12:18:35CEST Jochen Spruck (spruckj) 
  CHANGE:           First implementation of the vdy functional savety monitoring.
  CHANGE:           Monitoring of the estimated velocity,
  CHANGE:           Monitoring of the estimated yaw rates,
  CHANGE:           Monitorign of the estimated curve
  CHANGE:           --- Added comments ---  spruckj [Jul 27, 2010 12:18:36 PM CEST]
  CHANGE:           Change Package : 45203:1 http://mks-psad:7002/im/viewissue?selection=45203
  CHANGE:           Revision 1.22 2010/07/06 12:14:05CEST jspruck 
  CHANGE:           Add sequence init meas freeze function to the ecu code.
  CHANGE:           Add function for simulation to single activate the processing of the submodules after sequence init
  CHANGE:           --- Added comments ---  jspruck [2010/07/06 10:14:05Z]
  CHANGE:           Change Package : 42829:2 http://LISS014:6001/im/viewissue?selection=42829
  CHANGE:           Revision 1.21 2010/07/05 19:57:30CEST Joachim Tandler (jtandler) 
  CHANGE:           Made pdo line for VelStatObj_t depend on CFG_VDY_DO_VELOCITY_CORR, so that it does not need to be declared.
  CHANGE:           --- Added comments ---  jtandler [2010/07/05 17:57:31Z]
  CHANGE:           Change Package : 45433:1 http://LISS014:6001/im/viewissue?selection=45433
  CHANGE:           Revision 1.20 2010/06/29 14:52:11CEST Jochen Spruck (jspruck) 
  CHANGE:           Remove the pYawOffs
  CHANGE:           --- Added comments ---  jspruck [2010/06/29 12:52:11Z]
  CHANGE:           Change Package : 42829:1 http://LISS014:6001/im/viewissue?selection=42829
  CHANGE:           Revision 1.19 2010/06/24 16:55:21CEST Jochen Spruck (jspruck) 
  CHANGE:           Move pYawOffs some lines,
  CHANGE:           Add time switch to smr config
  CHANGE:           --- Added comments ---  jspruck [2010/06/24 14:55:22Z]
  CHANGE:           Change Package : 42829:1 http://LISS014:6001/im/viewissue?selection=42829
  CHANGE:           Revision 1.18 2010/06/17 10:50:29CEST Jochen Spruck (jspruck) 
  CHANGE:           move external interfaces from vdy_ext.h to rte
  CHANGE:           move external interface freez from internal to the adapter
  CHANGE:           --- Added comments ---  jspruck [2010/06/17 08:50:29Z]
  CHANGE:           Change Package : 42829:1 http://LISS014:6001/im/viewissue?selection=42829
  CHANGE:           Revision 1.17 2010/05/21 15:03:50CEST Jochen Spruck (jspruck) 
  CHANGE:           Update vdy to use external opmode and callib stuct
  CHANGE:           --- Added comments ---  jspruck [2010/05/21 13:03:50Z]
  CHANGE:           Change Package : 43547:1 http://LISS014:6001/im/viewissue?selection=43547
  CHANGE:           Revision 1.16 2010/05/19 15:37:52CEST Jochen Spruck (jspruck) 
  CHANGE:           Add additional config switch to switch off the sensor yaw rate output for aln
  CHANGE:           --- Added comments ---  jspruck [2010/05/19 13:37:52Z]
  CHANGE:           Change Package : 43263:1 http://LISS014:6001/im/viewissue?selection=43263
  CHANGE:           Revision 1.15 2010/05/19 12:56:48CEST Jochen Spruck (jspruck) 
  CHANGE:           Update VDY to version 03.00.03
  CHANGE:           - remove some vdy_memcpy_s's and use insead direct access to the reqPort
  CHANGE:           - Update to new interface of the ALNYawRate
  CHANGE:           --- Added comments ---  jspruck [2010/05/19 10:56:49Z]
  CHANGE:           Change Package : 43263:1 http://LISS014:6001/im/viewissue?selection=43263
  CHANGE:           Revision 1.14 2010/05/07 11:31:01CEST Jochen Spruck (jspruck) 
  CHANGE:           Remove lint vdy lint warnings
  CHANGE:           --- Added comments ---  jspruck [2010/05/07 09:31:01Z]
  CHANGE:           Change Package : 43240:1 http://LISS014:6001/im/viewissue?selection=43240
  CHANGE:           Revision 1.13 2010/04/16 13:44:50CEST Jochen Spruck (jspruck) 
  CHANGE:           Add some additional config switches needed by the SMR SRR project
  CHANGE:           --- Added comments ---  jspruck [2010/04/16 11:44:51Z]
  CHANGE:           Change Package : 41243:1 http://LISS014:6001/im/viewissue?selection=41243
  CHANGE:           Revision 1.12 2010/04/14 16:10:15CEST Jochen Spruck (jspruck) 
  CHANGE:           Add ALNYawRate_t to vdy proPort
  CHANGE:           Could be switched  Off with CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING
  CHANGE:           --- Added comments ---  jspruck [2010/04/14 14:10:15Z]
  CHANGE:           Change Package : 40051:1 http://LISS014:6001/im/viewissue?selection=40051
  CHANGE:           Revision 1.11 2010/04/13 12:47:50CEST Jochen Spruck (jspruck) 
  CHANGE:           Update vdy to MFC300 some rte types are not pressent in MFC projects
  CHANGE:           --- Added comments ---  jspruck [2010/04/13 10:47:50Z]
  CHANGE:           Change Package : 40051:1 http://LISS014:6001/im/viewissue?selection=40051
  CHANGE:           Revision 1.10 2010/03/26 12:23:16CET Jochen Spruck (jspruck) 
  CHANGE:           Change Function doxygen comment fn to Functionname
  CHANGE:           --- Added comments ---  jspruck [2010/03/26 11:23:16Z]
  CHANGE:           Change Package : 31184:2 http://LISS014:6001/im/viewissue?selection=31184
  CHANGE:           Revision 1.9 2010/03/23 08:45:08CET Jochen Spruck (jspruck) 
  CHANGE:           VDY sil-sil valitation update
  CHANGE:           - now all runs are equal
  CHANGE:           --- Added comments ---  jspruck [2010/03/23 07:45:08Z]
  CHANGE:           Change Package : 31184:2 http://LISS014:6001/im/viewissue?selection=31184
  CHANGE:           Revision 1.8 2010/03/11 12:24:50CET Jochen Spruck (jspruck) 
  CHANGE:           If no stand still at startup we send now quality 2 for 1 second and then 
  CHANGE:           use the qulaity value from the temp table. Bug fix of always quality 2 if we have no stand still at startup.
  CHANGE:           --- Added comments ---  jspruck [2010/03/11 11:24:50Z]
  CHANGE:           Change Package : 39143:1 http://LISS014:6001/im/viewissue?selection=39143
  CHANGE:           Revision 1.7 2010/03/08 12:10:23CET Jochen Spruck (jspruck) 
  CHANGE:           Add meas frezze of VDYOffsets,
  CHANGE:           Use now rte from base project and rte_sim
  CHANGE:           --- Added comments ---  jspruck [2010/03/08 11:10:23Z]
  CHANGE:           Change Package : 31184:2 http://LISS014:6001/im/viewissue?selection=31184
  CHANGE:           Revision 1.6 2010/01/29 11:41:59CET Jochen Spruck (jspruck) 
  CHANGE:           Add prepocessor switch to dectivate the code of internal yaw rate senensor processing
  CHANGE:           --- Added comments ---  jspruck [2010/01/29 10:41:59Z]
  CHANGE:           Change Package : 31184:2 http://LISS014:6001/im/viewissue?selection=31184
  CHANGE:           Revision 1.5 2010/01/29 10:31:23CET Jochen Spruck (jspruck) 
  CHANGE:           Add define #define VDY_DACQ_IF   1L         Activate interface to internal data 
  CHANGE:           --- Added comments ---  jspruck [2010/01/29 09:31:24Z]
  CHANGE:           Change Package : 31184:2 http://LISS014:6001/im/viewissue?selection=31184
  CHANGE:           Revision 1.4 2010/01/26 18:29:56CET Jochen Spruck (jspruck) 
  CHANGE:           update vdy to new algo interface Version 1.37
  CHANGE:           --- Added comments ---  jspruck [2010/01/26 17:29:56Z]
  CHANGE:           Change Package : 33263:2 http://LISS014:6001/im/viewissue?selection=33263
  CHANGE:           Revision 1.3 2010/01/15 13:16:27CET Jochen Spruck (jspruck) 
  CHANGE:           Merge some bug fixes from old vdy project to the new project
  CHANGE:           --- Added comments ---  jspruck [2010/01/15 12:16:28Z]
  CHANGE:           Change Package : 31184:2 http://LISS014:6001/im/viewissue?selection=31184
  CHANGE:           Revision 1.2 2009/12/17 14:43:49CET Jochen Spruck (jspruck) 
  CHANGE:           - Update vdy to use rte types
  CHANGE:           - add mon component
  CHANGE:           - restuct vdy_main.c
  CHANGE:           --- Added comments ---  jspruck [2009/12/17 13:43:50Z]
  CHANGE:           Change Package : 31184:2 http://LISS014:6001/im/viewissue?selection=31184
  CHANGE:           Revision 1.1 2009/09/17 17:01:09CEST Jochen Spruck (jspruck) 
  CHANGE:           Initial revision
  CHANGE:           Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/VDY_VehicleDynamics/04_Engineering/01_Source_Code/algo/vdy/project.pj
  CHANGE:           Revision 1.90 2009/09/17 11:10:28CEST Jochen Spruck (jspruck) 
  CHANGE:           Remove misra/lint warnings
  CHANGE:           --- Added comments ---  jspruck [2009/09/17 09:10:28Z]
  CHANGE:           Change Package : 31102:1 http://LISS014:6001/im/viewissue?selection=31102
  CHANGE:           Revision 1.89 2009/08/18 16:45:11CEST Jochen Spruck (jspruck) 
  CHANGE:           - Set velcorr output to invalid if input (vel history or velocity)
  CHANGE:           - do not set yaw output to valid (monitor) if it is invalid
  CHANGE:           --- Added comments ---  jspruck [2009/08/18 14:45:12Z]
  CHANGE:           Change Package : 30067:1 http://LISS014:6001/im/viewissue?selection=30067
  CHANGE:           Revision 1.88 2009/07/29 09:47:51CEST Jochen Spruck (jspruck) 
  CHANGE:           Set vdy output sensor yaw rate quality too 2,
  CHANGE:           if yaw rate offset elapsed time is below 1 for internal yaw rate sensor
  CHANGE:           --- Added comments ---  jspruck [2009/07/29 07:47:52Z]
  CHANGE:           Change Package : 29328:1 http://LISS014:6001/im/viewissue?selection=29328
  CHANGE:           Revision 1.87 2009/07/27 14:00:39CEST Thomas Diepolder (tdiepolder) 
  CHANGE:           Typing error for CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING corrected
  CHANGE:           --- Added comments ---  tdiepolder [2009/07/27 12:00:39Z]
  CHANGE:           Change Package : 29189:1 http://LISS014:6001/im/viewissue?selection=29189
  CHANGE:           Revision 1.86 2009/05/14 17:59:24CEST Jochen Spruck (jspruck) 
  CHANGE:           Set quality of sensor yaw rate to a const value if offest elapsed time is below 1.0 s
  CHANGE:           --- Added comments ---  jspruck [2009/05/14 15:59:24Z]
  CHANGE:           Change Package : 26862:1 http://LISS014:6001/im/viewissue?selection=26862
  CHANGE:           Revision 1.85 2009/05/11 17:15:40CEST Jochen Spruck (jspruck) 
  CHANGE:           Update CFG_VDY_ALIGNMENT_OFFSET_MONITOR compiler switches
  CHANGE:           --- Added comments ---  jspruck [2009/05/11 15:15:40Z]
  CHANGE:           Change Package : 26415:1 http://LISS014:6001/im/viewissue?selection=26415
  CHANGE:           Revision 1.84 2009/05/11 17:02:26CEST Jochen Spruck (jspruck) 
  CHANGE:           Use confidence instead of propabitlty (alignment yaw offset monitoring)
  CHANGE:           --- Added comments ---  jspruck [2009/05/11 15:02:26Z]
  CHANGE:           Change Package : 26415:1 http://LISS014:6001/im/viewissue?selection=26415
  CHANGE:           Revision 1.83 2009/05/11 15:51:50CEST Jochen Spruck (jspruck) 
  CHANGE:           Future optimization of yaw rate quality for rsp alignment monitoring
  CHANGE:           --- Added comments ---  jspruck [2009/05/11 13:51:50Z]
  CHANGE:           Change Package : 26603:1 http://LISS014:6001/im/viewissue?selection=26603
  CHANGE:           Revision 1.82 2009/05/11 11:48:36CEST Jochen Spruck (jspruck) 
  CHANGE:           Use hysteresis for gyro offset monitoring
  CHANGE:           --- Added comments ---  jspruck [2009/05/11 09:48:36Z]
  CHANGE:           Change Package : 26408:1 http://LISS014:6001/im/viewissue?selection=26408
  CHANGE:           Revision 1.81 2009/05/11 10:47:19CEST Jochen Spruck (jspruck) 
  CHANGE:           Use the confidence instead of propability from alignment monitoring yaw rate offset error
  CHANGE:           --- Added comments ---  jspruck [2009/05/11 08:47:20Z]
  CHANGE:           Change Package : 26415:1 http://LISS014:6001/im/viewissue?selection=26415
  CHANGE:           Revision 1.80 2009/05/06 22:11:17CEST Thomas Diepolder (tdiepolder) 
  CHANGE:           non-const parameter for function "VDYInteraceAuto2Hand" to avoid compiler error at activated strap CFG_VDY_GEN_VELOCITY_VARIANCE
  CHANGE:           --- Added comments ---  tdiepolder [2009/05/06 20:11:17Z]
  CHANGE:           Change Package : 26487:1 http://LISS014:6001/im/viewissue?selection=26487
  CHANGE:           Revision 1.79 2009/04/27 09:44:41CEST Jochen Spruck (jspruck) 
  CHANGE:           Fixing of lint/MISRA warnings
  CHANGE:           --- Added comments ---  jspruck [2009/04/27 07:44:41Z]
  CHANGE:           Change Package : 25965:1 http://LISS014:6001/im/viewissue?selection=25965
  CHANGE:           Revision 1.78 2009/04/03 12:47:08CEST Jochen Spruck (jspruck) 
  CHANGE:           Optimization of initalization of VDY simulator
  CHANGE:           - Add init for disc self steering gradient
  CHANGE:           - Add get functions for the internal data memory of the simulink models (for init in future)
  CHANGE:           --- Added comments ---  jspruck [2009/04/03 10:47:08Z]
  CHANGE:           Change Package : 25038:1 http://LISS014:6001/im/viewissue?selection=25038
  CHANGE:           Revision 1.77 2009/04/03 09:54:53CEST Jochen Spruck (jspruck) 
  CHANGE:           Optimization of yawrate quality for alignment
  CHANGE:           --- Added comments ---  jspruck [2009/04/03 07:54:53Z]
  CHANGE:           Change Package : 25036:1 http://LISS014:6001/im/viewissue?selection=25036
  CHANGE:           Revision 1.76 2009/04/03 09:36:44CEST Jochen Spruck (jspruck) 
  CHANGE:           Optimization of initalization of VDY simulation
  CHANGE:           --- Added comments ---  jspruck [2009/04/03 07:36:44Z]
  CHANGE:           Change Package : 25038:1 http://LISS014:6001/im/viewissue?selection=25038
  CHANGE:           Revision 1.75 2009/04/01 17:31:28CEST Jochen Spruck (jspruck) 
  CHANGE:           Implement check points for Task Logic Monitoring
  CHANGE:           --- Added comments ---  jspruck [2009/04/01 15:31:28Z]
  CHANGE:           Change Package : 24841:1 http://LISS014:6001/im/viewissue?selection=24841
  CHANGE:           Revision 1.74 2009/03/24 12:03:27CET mhinn 
  CHANGE:           added cycleid: vdy_cycle_id
  CHANGE:           --- Added comments ---  mhinn [2009/03/24 11:03:28Z]
  CHANGE:           Change Package : 24435:1 http://LISS014:6001/im/viewissue?selection=24435
  CHANGE:           Revision 1.73 2009/03/10 14:47:33CET Jochen Spruck (jspruck) 
  CHANGE:           Set output state of sensor yaw rate
  CHANGE:           --- Added comments ---  jspruck [2009/03/10 13:47:33Z]
  CHANGE:           Change Package : 23593:1 http://LISS014:6001/im/viewissue?selection=23593
  CHANGE:           Revision 1.72 2009/02/11 14:43:48CET Jochen Spruck (jspruck) 
  CHANGE:           Change to Matlab 2008b
  CHANGE:           --- Added comments ---  jspruck [2009/02/11 13:43:48Z]
  CHANGE:           Change Package : 22263:1 http://LISS014:6001/im/viewissue?selection=22263
  CHANGE:           Revision 1.71 2009/02/10 15:08:18CET Jochen Spruck (jspruck) 
  CHANGE:           Add config switches for pre processing vdy moduls
  CHANGE:            - Disabels the wheel speed pre processing, 
  CHANGE:                -> CFG_VDY_DIS_WHEEL_PRE_PROCESSING (0)
  CHANGE:            - Disabels the sensor yaw rate pre processing
  CHANGE:                -> CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING (0)
  CHANGE:            - Disabels the alignment yaw rate offset pre filtering, 
  CHANGE:                -> CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING (0)
  CHANGE:            - Disabels the lateral acceleration sensor pre processing, 
  CHANGE:                -> CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING (0)
  CHANGE:            - Disabels the steering wheel angle sensor pre processing, 
  CHANGE:                -> CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING (0)
  CHANGE:            - Disabels the side slip angle estimation
  CHANGE:                -> CFG_VDY_DIS_SIDE_SLIP_ANGLE_ESTIMATION (0)
  CHANGE:           --- Added comments ---  jspruck [2009/02/10 14:08:19Z]
  CHANGE:           Change Package : 22265:1 http://LISS014:6001/im/viewissue?selection=22265
  CHANGE:           Revision 1.68 2009/02/04 09:33:12CET Jochen Spruck (jspruck) 
  CHANGE:           Optimization of reportet yaw rate quality for rsp:
  CHANGE:           stand still yaw rate quality is reduced between 5min and 20 min after last stand still from 1.0 to 0.75 
  CHANGE:           -> standstill quality threshold is now 0.75
  CHANGE:           --- Added comments ---  jspruck [2009/02/04 08:33:12Z]
  CHANGE:           Change Package : 21881:2 http://LISS014:6001/im/viewissue?selection=21881
  CHANGE:           Revision 1.67 2009/02/03 10:06:48CET Jochen Spruck (jspruck) 
  CHANGE:           Optimization of sensor yaw rate quality used by the rsp alignment monitoring
  CHANGE:           --- Added comments ---  jspruck [2009/02/03 09:06:48Z]
  CHANGE:           Change Package : 21881:1 http://LISS014:6001/im/viewissue?selection=21881
  CHANGE:           Revision 1.66 2009/01/21 12:40:58CET Jochen Spruck (jspruck) 
  CHANGE:           Quality bug fix for ARS350
  CHANGE:           --- Added comments ---  jspruck [2009/01/21 11:40:58Z]
  CHANGE:           Change Package : 21380:2 http://LISS014:6001/im/viewissue?selection=21380
  CHANGE:           Revision 1.65 2009/01/21 12:01:21CET Jochen Spruck (jspruck) 
  CHANGE:           If yaw rate offset compensation is of the vehicle yaw rate and curve quality was not ok
  CHANGE:           --- Added comments ---  jspruck [2009/01/21 11:01:21Z]
  CHANGE:           Change Package : 21380:1 http://LISS014:6001/im/viewissue?selection=21380
  CHANGE:           Revision 1.64 2008/12/15 16:34:37CET Jochen Spruck (jspruck) 
  CHANGE:           Remove yaw rate offset peaks
  CHANGE:           --- Added comments ---  jspruck [2008/12/15 15:34:37Z]
  CHANGE:           Change Package : 20829:1 http://LISS014:6001/im/viewissue?selection=20829
  CHANGE:           Revision 1.63 2008/12/15 10:23:14CET Jochen Spruck (jspruck) 
  CHANGE:           Activation of VDY output signal monitoring
  CHANGE:           --- Added comments ---  jspruck [2008/12/15 09:23:15Z]
  CHANGE:           Change Package : 20830:1 http://LISS014:6001/im/viewissue?selection=20830
  CHANGE:           Revision 1.62 2008/12/11 16:24:34CET Jochen Spruck (jspruck) 
  CHANGE:           - add alignment offset error monitoring 
  CHANGE:           - adapt yaw rate tp filter to projects with internal yaw rate sensor
  CHANGE:           - if steering wheel angle is invalid -> driver intendet curve is invalid
  CHANGE:           - adapt time meas to new meas interface
  CHANGE:           --- Added comments ---  jspruck [2008/12/11 15:24:34Z]
  CHANGE:           Change Package : 19964:1 http://LISS014:6001/im/viewissue?selection=19964
  CHANGE:           Revision 1.61 2008/10/22 13:26:41CEST Jochen Spruck (jspruck) 
  CHANGE:           - Filter raw dyn wheel speed  yaw rate offset (FT = 2500s)
  CHANGE:           - Calculate with this filtered offset sensor yaw rate for alignment
  CHANGE:           --- Added comments ---  jspruck [2008/10/22 11:26:41Z]
  CHANGE:           Change Package : 18777:1 http://LISS014:6001/im/viewissue?selection=18777
  CHANGE:           Revision 1.60 2008/10/07 12:53:05CEST Jochen Spruck (jspruck) 
  CHANGE:           Bug Fix: Use Quality insted of Qualtiy
  CHANGE:           --- Added comments ---  jspruck [2008/10/07 10:53:06Z]
  CHANGE:           Change Package : 17221:1 http://LISS014:6001/im/viewissue?selection=17221
  CHANGE:           Revision 1.59 2008/09/24 13:29:33CEST Jochen Spruck (jspruck) 
  CHANGE:           Update: Implementation of new definition of quality for vdy estimated vehicle yaw rate, 
  CHANGE:           vehicle curve and yaw rate sensor yaw rate.
  CHANGE:           --- Added comments ---  jspruck [2008/09/24 11:29:33Z]
  CHANGE:           Change Package : 17221:1 http://LISS014:6001/im/viewissue?selection=17221
  CHANGE:           Revision 1.58 2008/09/24 13:23:55CEST Jochen Spruck (jspruck) 
  CHANGE:           Implementation of new definition of quality for vdy estimated vehicle yaw rate, 
  CHANGE:           vehicle curve and yaw rate sensor yaw rate.
  CHANGE:           --- Added comments ---  jspruck [2008/09/24 11:23:55Z]
  CHANGE:           Change Package : 17221:1 http://LISS014:6001/im/viewissue?selection=17221
  CHANGE:           Revision 1.57 2008/09/24 09:18:19CEST Thomas Diepolder (tdiepolder) 
  CHANGE:           Introduction of yaw rate monitoring during vehicle standstill to observe yaw rate sensor zero point offset
  CHANGE:           --- Added comments ---  tdiepolder [2008/09/24 07:18:19Z]
  CHANGE:           Change Package : 17564:1 http://LISS014:6001/im/viewissue?selection=17564
  CHANGE:           Revision 1.56 2008/09/18 11:29:43CEST Jochen Spruck (jspruck) 
  CHANGE:           Add monitoring function
  CHANGE:            -> Monitor the wheel velocity, if velocity is below 0 use fABS(),
  CHANGE:                 and set InputSignalError state to active.
  CHANGE:           --- Added comments ---  jspruck [2008/09/18 09:29:44Z]
  CHANGE:           Change Package : 17223:1 http://LISS014:6001/im/viewissue?selection=17223
  CHANGE:           Revision 1.55 2008/09/16 09:47:00CEST Jochen Spruck (jspruck) 
  CHANGE:           VDY V02.09.05 
  CHANGE:           -> Dynamic yaw rate offset reinit bug fix.
  CHANGE:           -> Put static offset switches to output config struct
  CHANGE:           --- Added comments ---  jspruck [2008/09/16 07:47:00Z]
  CHANGE:           Change Package : 17225:1 http://LISS014:6001/im/viewissue?selection=17225
  CHANGE:           Revision 1.54 2008/09/01 09:34:27CEST Jochen Spruck (jspruck) 
  CHANGE:           Use external error amplitude if uncertainty parameter is set to zero
  CHANGE:           --- Added comments ---  jspruck [2008/09/01 07:34:27Z]
  CHANGE:           Change Package : 11021:1 http://LISS014:6001/im/viewissue?selection=11021
  CHANGE:           Revision 1.53 2008/09/01 08:55:58CEST Jochen Spruck (jspruck) 
  CHANGE:           Plausibility check of output signals
  CHANGE:           --- Added comments ---  jspruck [2008/09/01 06:55:58Z]
  CHANGE:           Change Package : 16730:1 http://LISS014:6001/im/viewissue?selection=16730
  CHANGE:           Revision 1.51 2008/09/01 08:37:01CEST Jochen Spruck (jspruck) 
  CHANGE:           Emulation of vehicle speed variance
  CHANGE:           --- Added comments ---  jspruck [2008/09/01 06:37:01Z]
  CHANGE:           Change Package : 16728:1 http://LISS014:6001/im/viewissue?selection=16728
  CHANGE:           Revision 1.50 2008/07/11 15:50:08CEST Thomas Diepolder (tdiepolder) 
  CHANGE:           Do not increase variance output curve variance during unlearned state, if learning algo is disabled.
  CHANGE:           --- Added comments ---  tdiepolder [2008/07/11 13:50:08Z]
  CHANGE:           Change Package : 14979:1 http://LISS014:6001/im/viewissue?selection=14979
  CHANGE:           Revision 1.49 2008/07/09 14:56:46CEST jspruck 
  CHANGE:           ARS350 bug fix: 
  CHANGE:           - output yaw rate variance was to high
  CHANGE:           --- Added comments ---  jspruck [2008/07/09 12:56:46Z]
  CHANGE:           Change Package : 13131:2 http://LISS014:6001/im/viewissue?selection=13131
  CHANGE:           Revision 1.48 2008/07/04 16:43:49CEST tdiepolder 
  CHANGE:           Fixed incomplete initialization of internal states causing non duplicatable behaviour (especially at simulation environment)
  CHANGE:           --- Added comments ---  tdiepolder [2008/07/04 14:43:49Z]
  CHANGE:           Change Package : 14398:2 http://LISS014:6001/im/viewissue?selection=14398
  CHANGE:           Revision 1.47 2008/05/28 17:21:17CEST jspruck 
  CHANGE:           Init internal states Velocity and acceleration with values form the rec file if simulator is initialized
  CHANGE:           --- Added comments ---  jspruck [2008/05/28 15:21:18Z]
  CHANGE:           Change Package : 13011:1 http://liss014:6001/im/viewissue?selection=13011
  CHANGE:           Revision 1.46 2008/05/15 19:40:05CEST tdiepolder 
  CHANGE:           Initialization of output and internal interface during init mode
  CHANGE:           --- Added comments ---  tdiepolder [2008/05/15 17:40:05Z]
  CHANGE:           Change Package : 13160:1 http://liss014:6001/im/viewissue?selection=13160
  CHANGE:           Revision 1.45 2008/05/15 17:11:50CEST jspruck 
  CHANGE:           raise yaw rate variance if stand still yaw rate offset is not available or bad
  CHANGE:           --- Added comments ---  jspruck [2008/05/15 15:11:51Z]
  CHANGE:           Change Package : 13131:1 http://liss014:6001/im/viewissue?selection=13131
  CHANGE:           Revision 1.44 2008/05/15 09:08:52CEST tdiepolder 
  CHANGE:           PDO "allow" vdy_pub and vdy_priv inserted
  CHANGE:           --- Added comments ---  tdiepolder [2008/05/15 07:08:52Z]
  CHANGE:           Change Package : 12863:1 http://liss014:6001/im/viewissue?selection=12863
  CHANGE:           Revision 1.43 2008/04/18 16:05:24CEST tdiepolder 
  CHANGE:           Workaround: Signal steering wheel angle offset state through signal output curvature variance
  CHANGE:           --- Added comments ---  tdiepolder [2008/04/18 14:05:24Z]
  CHANGE:           Change Package : 11972:1 http://liss014:6001/im/viewissue?selection=11972
  CHANGE:           Revision 1.42 2008/04/10 15:08:01CEST jspruck 
  CHANGE:           Use eeprom yaw rate offset to init dyn yaw rate offset etimation, in case of reset without standstill
  CHANGE:           --- Added comments ---  jspruck [2008/04/10 13:08:01Z]
  CHANGE:           Change Package : 11713:2 http://liss014:6001/im/viewissue?selection=11713
  CHANGE:           Revision 1.41 2008/04/10 10:15:04CEST tdiepolder 
  CHANGE:           + Additional error event for velocity monitoring: Long-term deviation
  CHANGE:           + Compiler strap CFG_VDY_USE_VELO_MONITOR introduced
  CHANGE:           
  CHANGE:           --- Added comments ---  tdiepolder [2008/04/10 08:15:05Z]
  CHANGE:           Change Package : 10979:1 http://liss014:6001/im/viewissue?selection=10979
  CHANGE:           Revision 1.40 2008/03/28 11:34:13CET tdiepolder 
  CHANGE:           velocity monitor added
  CHANGE:           --- Added comments ---  tdiepolder [2008/03/28 10:34:14Z]
  CHANGE:           Change Package : 11029:3 http://liss014:6001/im/viewissue?selection=11029
  CHANGE:           Revision 1.39 2008/03/26 16:54:38CET jspruck 
  CHANGE:           Add DEM event if swa offset histo is out of range 3 times
  CHANGE:           --- Added comments ---  jspruck [2008/03/26 15:54:38Z]
  CHANGE:           Change Package : 11020:1 http://liss014:6001/im/viewissue?selection=11020
  CHANGE:           Revision 1.38 2008/03/19 17:42:06CET jspruck 
  CHANGE:           Modification to use the operation modes startup, init and running
  CHANGE:           --- Added comments ---  jspruck [2008/03/19 16:42:06Z]
  CHANGE:           Change Package : 11026:1 http://liss014:6001/im/viewissue?selection=11026
  CHANGE:           Revision 1.37 2008/03/14 08:48:15CET jspruck 
  CHANGE:           Put input signal offset to the vdy output stuct
  CHANGE:           --- Added comments ---  jspruck [2008/03/14 07:48:15Z]
  CHANGE:           Change Package : 10944:1 http://liss014:6001/im/viewissue?selection=10944
  CHANGE:           Revision 1.36 2008/02/21 09:57:12CET tdiepolder 
  CHANGE:           + Take into account that either internal yaw rate or external yaw rate state has to be considered 
  CHANGE:               to compose output state for yaw rate and curvature
  CHANGE:           *  Correct usage of velocity state at composition of output curvature state
  CHANGE:           
  CHANGE:           
  CHANGE:           --- Added comments ---  tdiepolder [2008/02/21 08:57:13Z]
  CHANGE:           Change Package : 4204:1 http://liss014:6001/im/viewissue?selection=4204
  CHANGE:           Revision 1.35 2008/02/07 14:54:39CET tdiepolder 
  CHANGE:           Autocode interface yaw rate standstill and temperature table offset extended
  CHANGE:           --- Added comments ---  tdiepolder [2008/02/07 13:54:39Z]
  CHANGE:           Change Package : 4204:1 http://liss014:6001/im/viewissue?selection=4204
  CHANGE:           Revision 1.34 2008/01/16 19:00:05CET jspruck 
  CHANGE:           Adapt strukt names
  CHANGE:           --- Added comments ---  jspruck [2008/01/16 18:00:05Z]
  CHANGE:           Change Package : 8833:1 http://liss014:6001/im/viewissue?selection=8833
  CHANGE:           Revision 1.33 2007/12/06 15:20:32CET tdiepolder 
  CHANGE:           Usage of corrected ego velocity for yaw rate and curvature models
  CHANGE:           --- Added comments ---  tdiepolder [2007/12/06 14:20:32Z]
  CHANGE:           Change Package : 7976:2 http://liss014:6001/im/viewissue?selection=7976
  CHANGE:           Revision 1.32 2007/12/06 06:30:28CET tdiepolder 
  CHANGE:           Correction of output states of yaw rate and curvature signal
  CHANGE:           --- Added comments ---  tdiepolder [2007/12/06 05:30:28Z]
  CHANGE:           Change Package : 7976:1 http://liss014:6001/im/viewissue?selection=7976
  CHANGE:           Revision 1.31 2007/11/06 10:07:58CET jspruck 
  CHANGE:           Init of autocode
  CHANGE:           --- Added comments ---  jspruck [2007/11/06 09:07:58Z]
  CHANGE:           Change Package : 6982:1 http://liss014:6001/im/viewissue?selection=6982
  CHANGE:           Revision 1.30 2007/10/31 17:26:20CET tdiepolder 
  CHANGE:           Extension of vehicle velocity correction
  CHANGE:           --- Added comments ---  tdiepolder [2007/10/31 16:26:20Z]
  CHANGE:           Change Package : 3172:1 http://liss014:6001/im/viewissue?selection=3172
  CHANGE:           Revision 1.29 2007/10/12 19:35:57CEST tdiepolder 
  CHANGE:           Use yaw rate interims offset to verify wheel speed yaw rate offset estimation
  CHANGE:           --- Added comments ---  tdiepolder [2007/10/12 17:35:57Z]
  CHANGE:           Change Package : 6336:1 http://liss014:6001/im/viewissue?selection=6336
  CHANGE:           Revision 1.28 2007/09/14 16:52:37CEST tdiepolder 
  CHANGE:           Integration of internal yaw rate sensor processing
  CHANGE:           --- Added comments ---  tdiepolder [2007/09/14 14:52:37Z]
  CHANGE:           Change Package : 4195:1 http://liss014:6001/im/viewissue?selection=4195
  CHANGE:           Revision 1.27 2007/09/06 13:34:59CEST jspruck 
  CHANGE:           Add version number and project to vdy simuator
  CHANGE:           --- Added comments ---  jspruck [2007/09/06 11:34:59Z]
  CHANGE:           Change Package : 5187:1 http://liss014:6001/im/viewissue?selection=5187
  CHANGE:           Revision 1.26 2007/08/28 16:13:05CEST jspruck 
  CHANGE:           External motion state routing modification
  CHANGE:           --- Added comments ---  jspruck [2007/08/28 14:13:05Z]
  CHANGE:           Change Package : 4896:2 http://liss014:6001/im/viewissue?selection=4896
  CHANGE:           Revision 1.25 2007/08/24 14:47:46CEST jspruck 
  CHANGE:           External motion state and direction bug fix
  CHANGE:           --- Added comments ---  jspruck [2007/08/24 12:47:46Z]
  CHANGE:           Change Package : 4896:1 http://liss014:6001/im/viewissue?selection=4896
  CHANGE:           Revision 1.24 2007/08/23 17:47:26CEST jspruck 
  CHANGE:           Add wheel load dep
  CHANGE:           --- Added comments ---  jspruck [2007/08/23 15:47:26Z]
  CHANGE:           Change Package : 4201:1 http://liss014:6001/im/viewissue?selection=4201
  CHANGE:           Revision 1.23 2007/08/21 12:24:11CEST tdiepolder 
  CHANGE:           Potential division by zero corrected
  CHANGE:           --- Added comments ---  tdiepolder [2007/08/21 10:24:11Z]
  CHANGE:           Change Package : 3167:1 http://liss014:6001/im/viewissue?selection=3167
  CHANGE:           Revision 1.22 2007/08/16 14:21:28CEST tdiepolder 
  CHANGE:           vdy offset estimation introduced
  CHANGE:           --- Added comments ---  tdiepolder [2007/08/16 12:21:28Z]
  CHANGE:           Change Package : 3167:1 http://liss014:6001/im/viewissue?selection=3167
  CHANGE:           Revision 1.21 2007/07/31 14:27:40CEST jspruck 
  CHANGE:           execute wpp module 
  CHANGE:           --- Added comments ---  jspruck [2007/07/31 12:27:40Z]
  CHANGE:           Change Package : 3175:1 http://liss014:6001/im/viewissue?selection=3175
  CHANGE:           Revision 1.20 2007/07/27 17:30:20CEST tdiepolder 
  CHANGE:           exchange of sensor offset data via module interfacce 
  CHANGE:           --- Added comments ---  tdiepolder [2007/07/27 15:30:20Z]
  CHANGE:           Change Package : 2928:1 http://liss014:6001/im/viewissue?selection=2928
  CHANGE:           Revision 1.19 2007/07/27 14:46:14CEST jspruck 
  CHANGE:           Add the lat accel to the vdy output struct
  CHANGE:           --- Added comments ---  jspruck [2007/07/27 12:46:14Z]
  CHANGE:           Change Package : 3175:1 http://liss014:6001/im/viewissue?selection=3175
  CHANGE:           Revision 1.18 2007/07/23 18:11:02CEST jspruck 
  CHANGE:           Driver intend curve grad 
  CHANGE:           --- Added comments ---  jspruck [2007/07/23 16:11:02Z]
  CHANGE:           Change Package : 3175:1 http://liss014:6001/im/viewissue?selection=3175
  CHANGE:           Revision 1.17 2007/07/06 11:40:11CEST tdiepolder 
  CHANGE:           + Deactivation of motion state and velocity processing if external signals are provided
  CHANGE:           --- Added comments ---  tdiepolder [2007/07/06 09:40:11Z]
  CHANGE:           Change Package : 2928:1 http://liss014:6001/im/viewissue?selection=2928
  CHANGE:           Revision 1.16 2007/07/04 12:12:38CEST tdiepolder 
  CHANGE:           + Prepared usage of offset compensated input signals
  CHANGE:           --- Added comments ---  tdiepolder [2007/07/04 10:12:38Z]
  CHANGE:           Change Package : 3174:1 http://liss014:6001/im/viewissue?selection=3174
  CHANGE:           Revision 1.15 2007/07/04 11:54:31CEST tdiepolder 
  CHANGE:           + PDO (meas data parser)  tags added
  CHANGE:           + Internal data for diagnostic
  CHANGE:           --- Added comments ---  tdiepolder [2007/07/04 09:54:32Z]
  CHANGE:           Change Package : 3174:1 http://liss014:6001/im/viewissue?selection=3174
  CHANGE:           Revision 1.14 2007/06/22 12:13:50CEST tdiepolder 
  CHANGE:           Extension of input and output interface addressing the ARS330 signal configuration
  CHANGE:           --- Added comments ---  tdiepolder [2007/06/22 10:13:51Z]
  CHANGE:           Change Package : 3193:1 http://liss014:6001/im/viewissue?selection=3193
  CHANGE:           Revision 1.13 2007/06/01 16:03:57CEST jspruck 
  CHANGE:            
  CHANGE:           --- Added comments ---  jspruck [2007/06/01 14:03:57Z]
  CHANGE:           Change Package : 2941:1 http://liss014:6001/im/viewissue?selection=2941
  CHANGE:           Revision 1.12 2007/04/03 15:04:29CEST jspruck 
  CHANGE:           Variance Q11 added to internal struct
  CHANGE:           --- Added comments ---  jspruck [2007/04/03 13:04:29Z]
  CHANGE:           Change Package : 1230:1 http://liss014:6001/im/viewissue?selection=1230
  CHANGE:           Revision 1.11 2007/03/23 15:19:01CET jspruck 
  CHANGE:           Include intenal states of the motion state
  CHANGE:           --- Added comments ---  jspruck [2007/03/23 14:19:01Z]
  CHANGE:           Change Package : 1230:1 http://liss014:6001/im/viewissue?selection=1230
  CHANGE:           Revision 1.10 2007/03/20 10:51:32CET jspruck 
  CHANGE:           Stand Still offset state and swa Velockity bug fix
  CHANGE:           --- Added comments ---  jspruck [2007/03/20 09:51:32Z]
  CHANGE:           Change Package : 1230:1 http://liss014:6001/im/viewissue?selection=1230
  CHANGE:           Revision 1.9 2007/03/16 11:42:47CET tdiepolder 
  CHANGE:           workaround-bug-fix: NaN at output curvature
  CHANGE:           --- Added comments ---  tdiepolder [2007/03/16 10:42:47Z]
  CHANGE:           Change Package : 1231:1 http://liss014:6001/im/viewissue?selection=1231
  CHANGE:           Revision 1.8 2007/03/15 13:24:26CET jspruck 
  CHANGE:           new curves parsed to old MTS output interface
  CHANGE:           --- Added comments ---  jspruck [2007/03/15 12:24:26Z]
  CHANGE:           Change Package : 1230:1 http://liss014:6001/im/viewissue?selection=1230
  CHANGE:           Revision 1.7 2007/03/15 11:26:01CET tdiepolder 
  CHANGE:           vehicle acceleratio output corrected
  CHANGE:           --- Added comments ---  tdiepolder [2007/03/15 10:26:01Z]
  CHANGE:           Change Package : 1231:1 http://liss014:6001/im/viewissue?selection=1231
  CHANGE:           Revision 1.6 2007/03/14 13:49:40CET tdiepolder 
  CHANGE:           Integration bug fixes for ARS310
  CHANGE:           --- Added comments ---  tdiepolder [2007/03/14 12:49:40Z]
  CHANGE:           Change Package : 1231:1 http://liss014:6001/im/viewissue?selection=1231
  CHANGE:           Revision 1.5 2007/03/13 09:11:56CET tdiepolder 
  CHANGE:           config straps correction
  CHANGE:           --- Added comments ---  tdiepolder [2007/03/13 08:11:56Z]
  CHANGE:           Change Package : 1231:1 http://liss014:6001/im/viewissue?selection=1231

**************************************************************************** */


/* PRQA S 310 EOF */ 
/* date: Unknown, reviewer: Suggested TCI Code Review, reason: BrakeActLevel is unsigned short which is not advisable to change it as unsigned Char" */

/* PRQA S 3355,3358 EOF */ 
/* date: Unknown, reviewer: Suggested TCI Code Review, reason: It works as a safeguard  against configuration faults" */

/* PRQA S 3201 EOF */ 
/* date: Unknown, reviewer: Suggested TCI Code Review, reason: It works as a safeguard  against configuration faults" */

/* PRQA S 3673 EOF */
/* date: Unknown, reviewer: Suggested TCI Code Review, reason: Since It modifies in a different config , it cant be pointer to const" */

/* PRQA S 3453 EOF */
/* date: Unknown, reviewer: Suggested TCI Code Review, reason: It is legacy code of ARS301 , alreay reviewed and working fine without any critical issue " */

/* PRQA S 7013 EOF */
/* date: Unknown, reviewer: Suggested TCI Code Review, reason: Legacy code of ARS301, reducing lines of code changes component structure." */

/* PRQA S 7004 EOF */
/* date: Unknown, reviewer: Suggested TCI Code Review, reason: Legacy code of ARS301, reducing complexity adds risk and effort." */

/* PRQA S 3408 EOF */
/* date: Unknown, reviewer: Suggested TCI Code Review, reason: Legacy code of ARS301,It is already declared in header file but cant recognise since it is under MACRO condition  " */

/* PRQA S 3112 EOF */
/* date: Unknown, reviewer: Suggested TCI Code Review, reason: Legacy code of ARS301, Unused statement for some configurations " */

/* PRQA S 3116 EOF */
/* date: Unknown, reviewer: Suggested TCI Code Review, reason: Legacy code of ARS301, alreay reviewed and working fine without any critical issue  " */

/* PRQA S 3425 EOF */
/* date: Unknown, reviewer: Suggested TCI Code Review, reason: Legacy code of MFC400, working fine without any critical issue also the 2nd operand is not a redundant expression because expression((void)(0L))
   is kept for saftey relavent if incase(fct_) == (void *)NULL)." */

/* PRQA S 3218 EOF */
/* date: Unknown, reviewer: Suggested TCI Code Review, reason: Legacy code of MFC400, u_count is used in Radar projects.Here disabled by a switch CFG_VDY_REDUCE_CURVE_ERROR" */

/* PRQA S 3229 EOF */
/* date: Unknown, reviewer: Suggested TCI Code Review, reason: Legacy code of MFC400, u_count is used in Radar projects.Here disabled by a switch CFG_VDY_REDUCE_CURVE_ERROR" */

/* PRQA S 503,5120,3768 EOF */
/* date: Unknown, reviewer: Suggested TCI Code Review, reason: Standard MACRO offsetof() is used.*/

/* PRQA S 0380 EOF */
/* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: No Risk */

/* PRQA S 2006 EOF*/
/* date: Unknown, reviewer: Suggested TCI Code Review, reason: multiple return statements are conditional dependent.*/


/* PRQA S 0311, 0314 EOF */
/* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: Functional Safe */
/* PRQA S 0315 EOF */
/* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: Functional Safe */
/* PRQA S 2996 EOF */
/* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: Functional Safe */
/* PRQA S 2995, 2997 EOF */
/* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: Functional Safe */		
/* PRQA S 1840 EOF */
/* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: Functional Safe */
/* PRQA S 2812 EOF */
/* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: Functional Safe */
/* PRQA S 0499 EOF */
/* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: No Risk */
/* PRQA S 2992 EOF */
/* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: Intended */

/* QAC Level 1 & 2 Warning Suppression */
/* PRQA S 0318, 2211, 2981, 3206, 3212, 3227, 3469, 3472, 3678, 4330, 1502, 1504, 1534, 1751, 1757 EOF */
/* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: This operation is intended */

/* PRQA S 2991 EOF */
/* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: No Risk */
	  
/* PRQA S 3219, 3447, 4397, 7623, 9704, 9710 EOF */
/* date: 2019-12-30, reviewer: Ramachandra Chinnaswamy (uids4735), reason: Fucntional Safe */

/* PRQA S 2743, 2755, 3120, 3334, 3447, 4397, 7623, 9704 EOF */
/* date: 2019-12-30, reviewer: Ramachandra Chinnaswamy (uids4735), reason: Fucntional Safe */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
/// Activate interface to internal data 
#define VDY_DACQ_IF   1L 
#include "vdy.h"

#if ( (!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING) )
#include "vdy_wpp.h"
#include "vdy_ve.h"
#include "vdy_wye.h"
#endif

#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING) )
#include "vdy_gye.h"
#endif

#if ( (!defined(CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING) )
#include "vdy_aye.h"
#endif

#if ( (!defined(CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING) )
#include "vdy_sye.h"
#endif

#if ( (!defined(CFG_VDY_USE_EXT_PROC_YAW_RATE)) || (!CFG_VDY_USE_EXT_PROC_YAW_RATE) )
#include "vdy_ye.h"
#endif

#if ( (!defined(CFG_VDY_DIS_SIDE_SLIP_ANGLE_ESTIMATION)) || (!CFG_VDY_DIS_SIDE_SLIP_ANGLE_ESTIMATION) )
#include "vdy_sae.h"
#endif

#if (CFG_VDY_MOT_STATE)
#include "vdy_mot_st.h"
#endif

#if ( defined(CFG_VDY_SET_DEM_EVENTS) && (CFG_VDY_SET_DEM_EVENTS) )
#include "Dem_IntErrIdSlv.h"
#endif

#ifndef VDY_SIMU
/// VDY Simulation
#define VDY_SIMU    0
#endif

/*****************************************************************************
  SYMBOLIC CONSTANTS
*****************************************************************************/
/// Cleared NVM
#define NVM_CLEARED                    (0xFFFFFFFFU)

/*****************************************************************************
  MACROS
*****************************************************************************/
/// Set VDY first cycle is done
#define VDY_SET_FIRST_CYCLE_DONE        (VDYModIf.FirstCycleDone = TRUE) 
/// Reset VDY first cycle is done
#define VDY_RESET_FIRST_CYCLE_DONE      (VDYModIf.FirstCycleDone = FALSE) 
/// If Vdy first cycle is done
#define VDY_IS_FIRST_CYCLE_DONE         (VDYModIf.FirstCycleDone) 
/// Set VDY Cycle Time
#define VDY_SET_CYCLE_TIME(time_)       (VDYModIf.CycleTime = ((fTime_t)(time_))*0.001F)
/// Get VDY Cycle Time
#define VDY_GET_CYCLE_TIME              (VDYModIf.CycleTime)

///  Understeer gradient scaling : ram to nvram 
#define VDY_NVM_USTG_INV_SCALE          (25000.F)

#if (!CFG_VDY_DIS_YWR_OFFSET_COMP)
/// Offset elapesed time threshold to set sensor yaw rate quality
#define VDY_OFFSET_ELAPSED_TIME_QUALI_THRESH   (1.0F)
#endif

/// Constant cycle time if cycle time is zero
#define VDY_CONST_CYCLE_TIME                   ((uiTime_t)20U)
/// Maximum cycle time if cycle time too high
#define VDY_MAX_CYCLE_TIME                     ((uiTime_t)110U)
/// No VDY Port fault
#define VDY_NO_PORT_FAULT                      ((uint8)0x00)
/// VDY Request Port fault
#define VDY_REQUEST_PORT_FAULT                 ((uint8)0x01)
/// VDY Provide Port fault
#define VDY_PROVIDE_PORT_FAULT                 ((uint8)0x02)
/// VDY Service Port fault
#define VDY_SERVICE_PORT_FAULT                 ((uint8)0x04)

/// curve error and confidence definitions

/// yaw rate offset error if learn state is YWR_OFFS_NON (no offset available) 
#define YWR_OFFSET_ERROR_OUT_YWR_OFFS_NON             (CML_Deg2Rad(10.0F))
/// yaw rate offset error if learn state is YWR_OFFS_STANDST_SHORT 
#define YWR_OFFSET_ERROR_OUT_YWR_OFFS_STANDST_SHORT   (CML_Deg2Rad(2.5F))
/// yaw rate offset error if learn state is YWR_OFFS_STANDST_FULL 
#define YWR_OFFSET_ERROR_OUT_YWR_OFFS_STANDST_FULL    (CML_Deg2Rad(1.0F))
/// yaw rate offset error if learn state is YWR_OFFS_STANDST_EEPROM 
#define YWR_OFFSET_ERROR_OUT_YWR_OFFS_STANDST_EEPROM  (CML_Deg2Rad(2.5F))
/// yaw rate offset error if learn state is YWR_OFFS_DYN 
#define YWR_OFFSET_ERROR_OUT_YWR_OFFS_DYN             (0.002F)

/// minimum velocity for yaw rate error calculation, below this value the error is set to 0 
#define MIN_VELO_YAW_RATE_ERROR                (1.0F)
/// threshold for yaw rate offset outside limit 
#define YWR_OFFS_LIMIT                         (CML_Deg2Rad(10.0F))

#ifndef MAX_SIGNAL_COUNTER
/// debounce time for input signals: 100ms / cycle time 
#define MAX_SIGNAL_COUNTER                     (100U/20U)
#endif

/// hold time before going down to lower confidence: 400ms / cycle time 
#define MAX_HOLD_TIME                          (400U/20U)
/// maximum allowed lateral error of curves at given distances 
#define MAX_LAT_ERROR                          (1.75F)
/// curvatures below this value are considered straight 
#define MIN_CURVE_FOR_APPROXIMATION            (0.00001F)
/// time distance for status 6 
#define TIME_DIST_CONF_6                       (4.0F)
/// time distance for status 6 
#define TIME_DIST_CONF_5                       (3.0F)
/// time distance for status 6 
#define TIME_DIST_CONF_4                       (2.0F)
/// time distance for status 6 
#define TIME_DIST_CONF_3                       (1.0F)
/// time eeprom to dynamic 
#define TIME_EEPROM_TO_DYNAMIC                 (50U)

#ifndef VDY_MAX_INPUT_DEBOUNCING
/// Maximum input debouncing
#define VDY_MAX_INPUT_DEBOUNCING               (3U)
#endif

/// four wheel steering based on steering wheel number parameter
#define FOUR_WHEEL_STEERING                    (2U)

/// fault counter threshold
#define VDY_VAR_FAULT_COUNTER_THRESHOLD        (5U)
/// calibration mode roller bench
#define VDY_CALIMODE_ROLLER_BENCH              (uint8)(0xFFU)

#if (CFG_VDY_MFC)
/// Measurement counter wrap-around limit(max value before wrapping back to 0) while increasing monotonically.	
#define VDY_MEASUREMENT_CNT_WRAPPER_LIMIT		65535
#endif


#if ( (!defined(VDY_SIMU)) || (!VDY_SIMU) )
/// VDY Freeze sequence size 
#define VDY_FREEZE_INIT_SEQUENCE                (1)
#endif

#ifdef __PDO__
#if ( defined(VDY_FREEZE_INIT_SEQUENCE) && (VDY_FREEZE_INIT_SEQUENCE) )
/// VDY init sequence size
#define VDY_INIT_SEQUENCE_SIZE                  (1024UL)
/// VDY init sequence data size
#define VDY_INIT_SEQUENCE_DATA_SIZE             (VDY_INIT_SEQUENCE_SIZE -4UL)
#endif
#endif

/// Group VDYInitSeqence \n Virtual addresses or related records IDs (in case of framework lookup table) for data acquisition interface. The addresses or IDs values must correspond to addresses specified in data description file (SDL, A2L etc.)
#define VDY_MEAS_ID_INIT_SEQ    0x20010000U

/// Group VDYNvAutoData  \n Virtual addresses or related records IDs (in case of framework lookup table) for data acquisition interface. The addresses or IDs values must correspond to addresses specified in data description file (SDL, A2L etc.)
#define VDY_MEAS_ID_NVMEM_AUTO  0x20012300U

#if (CFG_VDY_MFC)
/// Group VdyCompState    \n Virtual addresses or related records IDs (in case of framework lookup table) for data acquisition interface. The addresses or IDs values must correspond to addresses specified in data description file (SDL, A2L etc.)
#define VDY_MEAS_ID_ALGO_COMP_STATE 0x2001E900U
#endif

/*----- Data acquisition interface functions, only active if configured */
#if ( defined(CFG_VDY_MEASUREMENT) && (CFG_VDY_MEASUREMENT) )
  #ifdef AS_SERVICEFUNC_VERSION
#if ((CFG_VDY_MFC) && (!CFG_VDY_MFC_VX)) /* For MFC431 */
    /// Freeze job uses application buffer  -> referenced data has to be kept global or static
    #define MEAS_FREEZE_BUFFERED(VADDR_,ADDR_,SIZE_)  do \
    { \
      AS_t_MeasInfo desc; \
      desc.VirtualAddress = (VADDR_);        \
      desc.Length         = (SIZE_);         \
      desc.FuncID         = (MEASFuncID_t)VDY_MTS_FUNC_ID;   \
      desc.FuncChannelID  = (MEASFuncChannelID_t)VDY_MTS_FUNC_CHANNEL_ID;           \
      (void) (services)->pfMeasFreeze(&desc,(void *)(ADDR_),(AS_t_MeasCallback) &VDY_MTS_Callback); \
    } while(0) /* (no trailing ; ) */
    /* <ln_offset:-8 MISRA Rule 19.7: reviewer name: Jochen Spruck date: 27-09-2010 reason: proven in use, meas freeze macro  */
    /// Freeze copies data immediately to internal buffer -> buffer sized is limited
    #define MEAS_FREEZE_DIRECT(VADDR_,ADDR_,SIZE_)  do \
    { \
      AS_t_MeasInfo desc; \
      desc.VirtualAddress = (VADDR_);        \
      desc.Length         = (SIZE_);         \
      desc.FuncID         = (MEASFuncID_t)VDY_MTS_FUNC_ID;   \
      desc.FuncChannelID  = (MEASFuncChannelID_t)VDY_MTS_FUNC_CHANNEL_ID;           \
      (void) (services)->pfMeasFreeze(&desc,(void *)(ADDR_),(AS_t_MeasCallback) 0UL); \
    } while(0) /* (no trailing ; ) */
    /* <ln_offset:-8 MISRA Rule 19.7: reviewer name: Jochen Spruck date: 27-09-2010 reason: proven in use, meas freeze macro  */
#elif((CFG_VDY_MFC) && (CFG_VDY_MFC_VX)) /* For MFC5xx */
    /// Freeze job uses application buffer  -> referenced data has to be kept global or static
    #define MEAS_FREEZE_BUFFERED(VADDR_,ADDR_,SIZE_)  do \
    { \
      AS_t_MeasInfo desc; \
      desc.VirtualAddress = (VADDR_);        \
      desc.Length         = (SIZE_);         \
      desc.FuncID         = (MEASFuncID_t)VDY_MTS_FUNC_CHANNEL_ID;   \
      desc.FuncChannelID  = (MEASFuncChannelID_t)VDY_MTS_FUNC_CHANNEL_ID;           \
      (void) (services)->pfMeasFreeze(&desc,(void *)(ADDR_),(AS_t_MeasCallback) &VDY_MTS_Callback); \
    } while(0) /* (no trailing ; ) */
    /* <ln_offset:-8 MISRA Rule 19.7: reviewer name: Jochen Spruck date: 27-09-2010 reason: proven in use, meas freeze macro  */
    /// Freeze copies data immediately to internal buffer -> buffer sized is limited
    #define MEAS_FREEZE_DIRECT(VADDR_,ADDR_,SIZE_)  do \
    { \
      AS_t_MeasInfo desc; \
      desc.VirtualAddress = (VADDR_);        \
      desc.Length         = (SIZE_);         \
      desc.FuncID         = (MEASFuncID_t)VDY_MTS_FUNC_CHANNEL_ID;   \
      desc.FuncChannelID  = (MEASFuncChannelID_t)VDY_MTS_FUNC_CHANNEL_ID;           \
      (void) (services)->pfMeasFreeze(&desc,(void *)(ADDR_),(AS_t_MeasCallback) 0UL); \
    } while(0) /* (no trailing ; ) */
    /* <ln_offset:-8 MISRA Rule 19.7: reviewer name: Jochen Spruck date: 27-09-2010 reason: proven in use, meas freeze macro  */
#else
    /// Freeze job uses application buffer  -> referenced data has to be kept global or static
    #define MEAS_FREEZE_BUFFERED(VADDR_,ADDR_,SIZE_)  do \
    { \
      MEASInfo_t desc; \
      desc.VirtualAddress = (VADDR_);        \
      desc.Length         = (SIZE_);         \
      desc.FuncID         = (MEASFuncID_t)VDY_MTS_FUNC_ID;   \
      desc.FuncChannelID  = (MEASFuncChannelID_t)VDY_MTS_FUNC_CHANNEL_ID;           \
      (void) (services)->pfMeasFreeze(&desc,(void *)(ADDR_),(MEAS_Callback_t) &VDY_MTS_Callback); \
    } while(0) /* (no trailing ; ) */
    /* <ln_offset:-8 MISRA Rule 19.7: reviewer name: Jochen Spruck date: 27-09-2010 reason: proven in use, meas freeze macro  */
    /// Freeze copies data immediately to internal buffer -> buffer sized is limited
    #define MEAS_FREEZE_DIRECT(VADDR_,ADDR_,SIZE_)  do \
    { \
      MEASInfo_t desc; \
      desc.VirtualAddress = (VADDR_);        \
      desc.Length         = (SIZE_);         \
      desc.FuncID         = (MEASFuncID_t)VDY_MTS_FUNC_ID;   \
      desc.FuncChannelID  = (MEASFuncChannelID_t)VDY_MTS_FUNC_CHANNEL_ID;           \
      (void) (services)->pfMeasFreeze(&desc,(void *)(ADDR_),(MEAS_Callback_t) 0UL); \
    } while(0) /* (no trailing ; ) */
    /* <ln_offset:-8 MISRA Rule 19.7: reviewer name: Jochen Spruck date: 27-09-2010 reason: proven in use, meas freeze macro  */
#endif
  #else
    /// Freeze job uses application buffer  -> referenced data has to be kept global or static
    #define MEAS_FREEZE_BUFFERED(VADDR_,ADDR_,SIZE_)  do \
    { \
      MEASInfo_t desc; \
      desc.VirtualAddress = VADDR_;        \
      desc.Length         = SIZE_;         \
      desc.FuncID         = (uint8)COMP_ID_VDY;   \
      desc.FuncChannelID  = 20U;           \
      (void) (reqPorts->pVDYCallBackHdlr)->pfMeasFreeze(&desc,(void *)ADDR_,(MEAS_Callback_t) VDY_MTS_Callback); \
    } while(0) /* (no trailing ; ) */
    /* <ln_offset:-8 MISRA Rule 19.7: reviewer name: Jochen Spruck date: 27-09-2010 reason: proven in use, meas freeze macro  */
    /// Freeze copies data immediately to internal buffer -> buffer sized is limited
    #define MEAS_FREEZE_DIRECT(VADDR_,ADDR_,SIZE_)  do \
    { \
      MEASInfo_t desc; \
      desc.VirtualAddress = VADDR_;        \
      desc.Length         = SIZE_;         \
      desc.FuncID         = (uint8)COMP_ID_VDY;   \
      desc.FuncChannelID  = 20U;           \
      (void) (reqPorts->pVDYCallBackHdlr)->pfMeasFreeze(&desc,(void *)ADDR_,(MEAS_Callback_t) 0UL); \
    } while(0) /* (no trailing ; ) */
    /* <ln_offset:-8 MISRA Rule 19.7: reviewer name: Jochen Spruck date: 27-09-2010 reason: proven in use, meas freeze macro  */
  #endif
#else
  /// Freeze job uses application buffer  -> referenced data has to be kept global or static
  #define MEAS_FREEZE_BUFFERED(ADDR_,DATA_,SIZE_)
  /// Freeze copies data immediately to internal buffer -> buffer sized is limited
  #define MEAS_FREEZE_DIRECT(ADDR_,DATA_,SIZE_)
#endif

#ifdef __PDO__
typedef VDYConfig_t  PDOVDYConfig;
#if ( defined(VDY_FREEZE_INIT_SEQUENCE) && (VDY_FREEZE_INIT_SEQUENCE) )
typedef uint8        PDOVDYInitSeqence[VDY_INIT_SEQUENCE_SIZE];       /*!< @VADDR: VDY_MEAS_ID_INIT_SEQ  @VNAME:VDYInitSequence @ALLOW: vdy_priv @CYCLEID: vdy_cycle_id @VALUES: struct { uint32 InitPackageID; uint8 rawdata[VDY_INIT_SEQUENCE_DATA_SIZE]; } */
#endif
#endif


/*****************************************************************************
  TYPEDEFS
*****************************************************************************/

/// \brief Frame counter data 
typedef struct
{
  uint16 ExecCntr;         ///< Execution cycle counter 
} VDYEnvFrameCounter_t;


/*****************************************************************************
  VARIABLES
*****************************************************************************/

/* Internal interface of autocode modules */
SET_MEMSEC_VAR(vdy_internal_data)
///Internal interface of autocode modules
VDYInternalData_t      vdy_internal_data;	

SET_MEMSEC_VAR(vdy_bayes_mot_states)
///Internal interface of autocode modules
vdy_bayes_mot_states_t vdy_bayes_mot_states;	

SET_MEMSEC_VAR(vdy_ye_k)
///Internal interface of autocode modules
STATIC_VAR VDYYe_K_t vdy_ye_k;	

///Internal interface of autocode modules 
STATIC_VAR VDYDeltaTimeStamp_t VDYDeltaTimeStamp;   

#if (CFG_VDY_MFC)
///VDY component State
AlgoCompState_t VdyCompState;	/*!< @VADDR: VDY_MEAS_ID_ALGO_COMP_STATE @VNAME: vdyCompState @ALLOW: vdy_priv @cycleid: vdy_cycle_id*/

/// flag to check whether Request port holds Init or Invalid signal state for more than debounce cycle.
STATIC_VAR boolean		b_ReqPortStateCrossDebouncLimit = (boolean)FALSE;

/// counter for number of cycles a Request port was debounced when in INIT state.
STATIC_VAR uint8		u_ReqPortDebounceCycleCount;
/// Average four wheel velocity for non radar project.
STATIC_VAR float32		RawVelo;
#endif

SET_MEMSEC_VAR(VDYEnvFrmCnt)
/// Frame counter to maintance execution
STATIC_VAR VDYEnvFrameCounter_t VDYEnvFrmCnt;

SET_MEMSEC_VAR(sSequenceInitState)
/// The sequence init State
STATIC_VAR VDYSequenceInitStates_t sSequenceInitState;

#if ( (!defined(CFG_VDY_DIS_YWR_OFFSET_COMP)) || (!CFG_VDY_DIS_YWR_OFFSET_COMP) )
SET_MEMSEC_VAR(VDYOutYwrOffsType)
/// The yaw rate offset output state
STATIC_VAR VDYOutYwrOffsType_t     VDYOutYwrOffsType;
#endif

#ifdef AS_SERVICEFUNC_VERSION
///Simulation synchronisation counter of input data 
STATIC_VAR VDY_SM_t_SyncRef s_SyncRef;	
#endif

/// buffer to debounce the input signals in case of invalid inputs 
STATIC_VAR VehSigMain_t s_LastInputSignals;
/// counter for number of cycles a signal was debounced 
STATIC_VAR uint8 u_DebouceCounter[VDY_SIN_POS_MAX];
#if ( (defined(CFG_VDY_REDUCE_CURVE_ERROR)) && (CFG_VDY_REDUCE_CURVE_ERROR) )
/// counter for reducing the curve error at system reset situations 
STATIC_VAR uint32 u_count ;
#endif

#if(!CFG_VDY_MFC)
/// instance for Roller test bench recognition  
STATIC_VAR boolean b_RTBDetection;
#endif 
/// VDY Internal Data
VDYInternal_t VDYInternal;
/*****************************************************************************
 MODULE LOCAL CONSTANTS
*****************************************************************************/


/*****************************************************************************
  MODULE LOCAL VARIABLES
*****************************************************************************/

/* Buffer for module interface hand code auto code */
SET_MEMSEC_VAR(VDYModIf)
/// Buffer for module interface hand code auto code
STATIC_VAR VDYModIf_t VDYModIf; 

#if ( (!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING) )
/* vdy_wpp modul */
SET_MEMSEC_VAR(vdy_wpp_B)
/// VDY Wheel Speeds Pre Processing Module :Observable signals  
STATIC_VAR BlockIO_vdy_wpp vdy_wpp_B;

SET_MEMSEC_VAR(vdy_wpp_DWork)
/// VDY Wheel Speeds Pre Processing Module :Observable states  
STATIC_VAR D_Work_vdy_wpp vdy_wpp_DWork;


/* vdy_ve modul */
SET_MEMSEC_VAR(vdy_ve_B)
/// VDY Velocity Module : Observable signals  
STATIC_VAR BlockIO_vdy_ve vdy_ve_B;

SET_MEMSEC_VAR(vdy_ve_DWork)
/// VDY Velocity Module : Observable states  
STATIC_VAR D_Work_vdy_ve vdy_ve_DWork;


/* vdy_wye modul */
SET_MEMSEC_VAR(vdy_wye_B)
/// VDY Yaw Rate Estimation with Wheel Speeds Module : Observable signals  
STATIC_VAR BlockIO_vdy_wye vdy_wye_B;

SET_MEMSEC_VAR(vdy_wye_DWork)
/// VDY Yaw Rate Estimation with Wheel Speeds Module : Observable states  
STATIC_VAR D_Work_vdy_wye vdy_wye_DWork;
#endif

#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING) )
/* vdy_gye modul */
SET_MEMSEC_VAR(vdy_gye_B)
/// Gier Yaw Rate Estimation Module : Observable signals  
STATIC_VAR BlockIO_vdy_gye vdy_gye_B;

SET_MEMSEC_VAR(vdy_gye_DWork)
/// Gier Yaw Rate Estimation Module : Observable states  
STATIC_VAR D_Work_vdy_gye vdy_gye_DWork;

#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING)) || (!CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING) )
/* vdy_gye modul to filter and output raw yaw rate  */
SET_MEMSEC_VAR(vdy_gye_B_FILT)
/// vdy_gye modul to filter and output raw yaw rate : Observable signals  
STATIC_VAR BlockIO_vdy_gye vdy_gye_B_FILT;

SET_MEMSEC_VAR(vdy_gye_DWork_FILT)
/// vdy_gye modul to filter and output raw yaw rate : Observable states  
STATIC_VAR D_Work_vdy_gye vdy_gye_DWork_FILT;

SET_MEMSEC_VAR(LastFiltered)
/// vdy_gye modul to filter and output raw yaw rate : Last filtered dyn yaw rate offset  
STATIC_VAR fYawRate_t LastFiltered = VDY_ZERO_F;

SET_MEMSEC_VAR(OldFiltYawOffset)
/// vdy_gye modul to filter and output raw yaw rate : Filter delay for yaw rate offset  
STATIC_VAR fYawRate_t OldFiltYawOffset = VDY_ZERO_F;
#endif
#endif

#if ( (!defined(CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING) )
/* vdy_aye modul */
SET_MEMSEC_VAR(vdy_aye_B)
/// VDY Yaw Rate Estimation Module : Observable signals  
STATIC_VAR BlockIO_vdy_aye vdy_aye_B;

SET_MEMSEC_VAR(vdy_aye_DWork)
/// VDY Yaw Rate Estimation with Lateral Acceleration Module : Observable states  
STATIC_VAR D_Work_vdy_aye vdy_aye_DWork;
#endif

#if ( (!defined(CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING) )
/* vdy_sye modul */
SET_MEMSEC_VAR(vdy_sye_B)
/// VDY Yaw Rate Estimation with Steering Wheel Angle Module : Observable signals  
STATIC_VAR BlockIO_vdy_sye vdy_sye_B;

SET_MEMSEC_VAR(vdy_sye_DWork)
/// VDY Yaw Rate Estimation with Steering Wheel Angle Module : Observable states  
STATIC_VAR D_Work_vdy_sye vdy_sye_DWork;
#endif

#if ( (!defined(CFG_VDY_USE_EXT_PROC_YAW_RATE)) || (!CFG_VDY_USE_EXT_PROC_YAW_RATE) )
/* vdy_ve modul */
SET_MEMSEC_VAR(vdy_ye_B)
/// VDY Velocity Module : Observable signals  
STATIC_VAR BlockIO_vdy_ye vdy_ye_B;

SET_MEMSEC_VAR(vdy_ye_DWork)
/// VDY Velocity Module : Observable states  
STATIC_VAR D_Work_vdy_ye vdy_ye_DWork;     
#endif

#if ( (!defined(CFG_VDY_DIS_SIDE_SLIP_ANGLE_ESTIMATION)) || (!CFG_VDY_DIS_SIDE_SLIP_ANGLE_ESTIMATION) )
/* vdy_sae modul */
SET_MEMSEC_VAR(vdy_sae_B)
/// VDY Velocity Module : Observable signals  
STATIC_VAR BlockIO_vdy_sae vdy_sae_B;

SET_MEMSEC_VAR(vdy_sae_DWork)
/// VDY Side Slip Angle Estimation Module : Observable states  
STATIC_VAR D_Work_vdy_sae vdy_sae_DWork;   
#endif

#if (CFG_VDY_MOT_STATE)
/* vdy_mot_st modul motion state */
SET_MEMSEC_VAR(vdy_mot_st_B)
/// VDY Motion State Module : Observable signals  
STATIC_VAR BlockIO_vdy_mot_st vdy_mot_st_B;

SET_MEMSEC_VAR(vdy_mot_st_DWork)
/// VDY Motion State Module : Observable states  
STATIC_VAR D_Work_vdy_mot_st vdy_mot_st_DWork;  
#endif

#if ( defined(VDY_FREEZE_INIT_SEQUENCE) && (VDY_FREEZE_INIT_SEQUENCE) )
SET_MEMSEC_VAR(InitPackageID)
/// Init Package ID
STATIC_VAR uint32 InitPackageID; 
#endif

#if (!(CFG_VDY_USE_EX_LONG_ACCEL) && (CFG_VDY_USE_EX_LONG_VELO))
 
SET_MEMSEC_VAR(VDYModIf)
/// External velocity without related acceleration is provided 
STATIC_VAR fVelocity_t oldVelocityIn; 
#endif


/*<---------------------------------------------------------------------------
  Service functions (defined locally if not available in RTE)
----------------------------------------------------------------------------->*/
#ifndef AS_SERVICEFUNC_VERSION
/// Service functions (defined locally if not available in RTE)
AS_t_ServiceFuncts * services; 
#endif


/*****************************************************************************
  LOCAL FUNCTION PROTOTYPES
*****************************************************************************/

/* ***********************************************************************
  @fn               vdySetSequenceInitState */ /*!
  @brief           Set the sequence initalization state

  @description     Set the sequence initalization state

  @return          void

  @param[in]       _sSequenceInitState : Sequence Init State

  @c_switch_part   None  
  @c_switch_full   VDY_SIMU

  @pre             None
  @post            No changes
  @InOutCorrelation -  Set the sequence init state to the local variable 
  
	@startuml
	start
		:Set the sequence init state to the local variable \n sSequenceInitState = _sSequenceInitState;	
	stop
	@enduml
  @testmethod			  - NA
  @traceability			  - NA
**************************************************************************** */
void vdySetSequenceInitState( VDYSequenceInitStates_t _sSequenceInitState );


/* ***********************************************************************
  @fn               vdyGetModulIf */ /*!
  @brief           Get pointer to interface data of the internal modules

  @description     Get pointer to interface data of the internal modules

  @return          VDYModIf_t pointer to interface data

  @glob_in         None 
  @glob_out        VDYModIf : interface data of the internal modules

  @c_switch_part   None  
  @c_switch_full   VDY_SIMU

  @pre             None
  @post            No changes
  @InOutCorrelation		  - 
  
	@startuml
	start
		:return(&VDYModIf);
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> TEST_vdyGetModulIf_001()
  @traceability			  - NA
**************************************************************************** */
VDYModIf_t        *vdyGetModulIf(void);


/* ***********************************************************************
  @fn               vdyGetVDYIntData */ /*!
  @brief           Get pointer to internal data

  @description     Get pointer to internal data

  @return          VDYInternalData_t pointer to internal data

  @glob_in         None
  @glob_out        vdy_internal_data : internal data

  @c_switch_part   None  
  @c_switch_full   VDY_SIMU

  @pre             None
  @post            No changes
  @InOutCorrelation		  - 
  
	@startuml
	start
		:return (&vdy_internal_data);
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> TEST_vdyGetVDYIntData_001()
  @traceability			  - NA
**************************************************************************** */
VDYInternalData_t *vdyGetVDYIntData(void);

#if ( (!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING) )

/* ***********************************************************************
  @fn               vdyGet_D_Work_vdy_wpp */ /*!
  @brief           Get pointer to estimated vdy_wpp internal data

  @description     Get pointer to estimated vdy_wpp internal data

  @return          D_Work_vdy_wpp pointer to wheel speed data

  @glob_in         None
  @glob_out        vdy_wpp_DWork : estimated vdy_wpp internal data

  @c_switch_part   None  
  @c_switch_full   VDY_SIMU
  @c_switch_full   
  - CFG_VDY_DIS_WHEEL_PRE_PROCESSING : Disables the wheel speed pre processing, 
                                                    - wheel offset estimation
                                                    - wheel velocity <-> puls fusion
                                                    - vehicle speed estimation
                                                    - wheel load dependancy estimation
                                                    - dynamic (drift) sensor yaw rate offset estimation
                                                    - wheel velocity yaw rate estimation

  @pre             None
  @post            No changes 
  @InOutCorrelation		  - 
  
	@startuml
	start
		:return (&vdy_wpp_DWork);
	stop
	@enduml
  @testmethod			  - NA
  @traceability			  - NA
**************************************************************************** */
D_Work_vdy_wpp    *vdyGet_D_Work_vdy_wpp(void);

/* ***********************************************************************
  @fn               vdyGet_D_Work_vdy_ve */ /*!
  @brief           Get pointer to estimated vdy_ve internal data

  @description     Get pointer to estimated vdy_ve internal data

  @return          D_Work_vdy_ve pointer to yaw rate fusion data

  @glob_in         None 
  @glob_out        vdy_ve_DWork : estimated vdy_ve internal data

  @c_switch_part   None 
  @c_switch_full   VDY_SIMU
  @c_switch_full   
  - CFG_VDY_DIS_WHEEL_PRE_PROCESSING : Disables the wheel speed pre processing, 
                                                    - wheel offset estimation
                                                    - wheel velocity <-> puls fusion
                                                    - vehicle speed estimation
                                                    - wheel load dependancy estimation
                                                    - dynamic (drift) sensor yaw rate offset estimation
                                                    - wheel velocity yaw rate estimation


  @pre             None
  @post            No changes
  @InOutCorrelation		  - 
  
	@startuml
	start
		:return (&vdy_ve_DWork);
	stop
	@enduml

  @testmethod			  - NA
  @traceability			  - NA
**************************************************************************** */
D_Work_vdy_ve     *vdyGet_D_Work_vdy_ve(void);

/* ***********************************************************************
  @fn               vdyGet_D_Work_vdy_wye */ /*!
  @brief           Get pointer to estimated vdy_wye internal data

  @description     Get pointer to estimated vdy_wye internal data

  @return          D_Work_vdy_wye pointer to wheel speed yaw rate data

  @glob_in         None 
  @glob_out        vdy_wye_DWork : estimated vdy_wye internal data

  @c_switch_part   None  
  @c_switch_full   VDY_SIMU
  @c_switch_full   
  - CFG_VDY_DIS_WHEEL_PRE_PROCESSING : Disables the wheel speed pre processing, 
                                                    - wheel offset estimation
                                                    - wheel velocity <-> puls fusion
                                                    - vehicle speed estimation
                                                    - wheel load dependancy estimation
                                                    - dynamic (drift) sensor yaw rate offset estimation
                                                    - wheel velocity yaw rate estimation


  @pre             None
  @post            No changes
  @InOutCorrelation		  - 
  
	@startuml
	start
		:return (&vdy_wye_DWork);
	stop
	@enduml
  @testmethod			  - NA
  @traceability			  - NA
**************************************************************************** */
D_Work_vdy_wye    *vdyGet_D_Work_vdy_wye(void);
#endif

#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING) )

/* ***********************************************************************
  @fn               vdyGet_D_Work_vdy_gye */ /*!
  @brief           Get pointer to estimated vdy_gye internal data

  @description     Get pointer to estimated vdy_gye internal data

  @return          D_Work_vdy_gye pointer to gyro yaw rate data

  @glob_in         None 
  @glob_out        vdy_gye_DWork : estimated vdy_gye internal data

  @c_switch_part   None  
  @c_switch_full   VDY_SIMU
  @c_switch_full   
  - CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING : Disables the sensor yaw rate pre processing, 
                                                         - static (stand still)yaw rate offset
                                                         - yaw rate from yaw rate sensor estimation
  @pre             None
  @post            No changes
  @InOutCorrelation		  - 
  
	@startuml
	start
		:return (&vdy_gye_DWork);
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> TEST_vdyGet_D_Work_vdy_gye_001()
  @traceability			  - NA
**************************************************************************** */
D_Work_vdy_gye    *vdyGet_D_Work_vdy_gye(void);

/* ***********************************************************************
  @fn               vdyGet_D_Work_vdy_gye_filt */ /*!
  @brief           Get pointer to estimated vdy_gye_filt internal data

  @description     Get pointer to estimated vdy_gye_filt internal data

  @return          D_Work_vdy_gye : 

  @glob_in         None
  @glob_out        vdy_gye_DWork_FILT : estimated vdy_gye_filt internal data

  @c_switch_part   None  
  @c_switch_full   VDY_SIMU
  @c_switch_full   
  - CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING : Disables the alignment yaw rate offset pre filtering, 
                                                             - yaw rate from yaw rate sensor with filtered offset estimation
  @pre             None
  @post            No changes
  @InOutCorrelation		  - 
  
	@startuml
	start
		:return (&vdy_gye_DWork_FILT);
	stop
	@enduml
  @testmethod			  - NA
  @traceability			  - NA
**************************************************************************** */
D_Work_vdy_gye    *vdyGet_D_Work_vdy_gye_filt(void);
#endif

#if ( (!defined(CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING) )

/* ***********************************************************************
  @fn               vdyGet_D_Work_vdy_aye */ /*!
  @brief           Get pointer to estimated vdy_aye internal data

  @description     Get pointer to estimated vdy_aye internal data

  @return          D_Work_vdy_aye pointer to lat accel yaw rate data

  @glob_in         None  
  @c_switch_full   VDY_SIMU
  @glob_out        vdy_aye_DWork :estimated vdy_aye internal data

  @c_switch_part   None 
  @c_switch_full   
  - CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING : Disables the lateral acceleration sensor pre processing, 
                                                               - lateral sensor offset estimation
                                                               - yaw rate from lateral acceleration sensor estimation

  @pre             None
  @post            No changes
  @InOutCorrelation		  - 
  
	@startuml
	start
		:return (&vdy_aye_DWork);
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> TEST_vdyGet_D_Work_vdy_aye_001()
  @traceability			  - NA
**************************************************************************** */
D_Work_vdy_aye    *vdyGet_D_Work_vdy_aye(void);
#endif

#if ( (!defined(CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING) )
/* ***********************************************************************
  @fn               vdyGet_D_Work_vdy_sye */ /*!
  @brief           Get pointer to estimated vdy_sye internal data

  @description     Get pointer to estimated vdy_sye internal data

  @return          D_Work_vdy_sye pointer to steering wheel yaw rate data

  @glob_in         None 
  @glob_out        vdy_sye_DWork : estimated vdy_sye internal data

  @c_switch_part   None  
  @c_switch_full   VDY_SIMU
  @c_switch_full   
  - CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING : Disables the steering wheel angle sensor pre processing, 
                                                               - steering wheel angle sensor offset estimation
                                                               - estimation of self steering gradient
                                                               - driver intended curvature
                                                               - yaw rate from steering wheel sensor estimation
  @pre             None
  @post            No changes
  @InOutCorrelation		  - 
  
	@startuml
	start
		:return (&vdy_sye_DWork);
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> TEST_vdyGet_D_Work_vdy_sye_001()
  @traceability			  - NA
**************************************************************************** */
D_Work_vdy_sye    *vdyGet_D_Work_vdy_sye(void);
#endif

#if ( (!defined(CFG_VDY_USE_EXT_PROC_YAW_RATE)) || (!CFG_VDY_USE_EXT_PROC_YAW_RATE) )
/* ***********************************************************************
  @fn               vdyGet_D_Work_vdy_ye */ /*!
  @brief           Get pointer to estimated vdy_ye internal data

  @description     Get pointer to estimated vdy_ye internal data

  @return          D_Work_vdy_ye pointer to yaw rate and curve fusion data

  @glob_in         None 
  @glob_out        vdy_ye_DWork : estimated vdy_ye internal data

  @c_switch_part   None  
  @c_switch_full   VDY_SIMU
  @c_switch_full   
  - CFG_VDY_USE_EXT_PROC_YAW_RATE : Enables usage of external yaw rate as vdy output yaw rate

  @pre             None
  @post            No changes
  @InOutCorrelation		  - 
  
	@startuml
	start
		:return (&vdy_ye_DWork);
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> TEST_vdyGet_D_Work_vdy_ye_001()
  @traceability			  - NA
**************************************************************************** */
D_Work_vdy_ye     *vdyGet_D_Work_vdy_ye(void);
#endif

#if ( (!defined(CFG_VDY_DIS_SIDE_SLIP_ANGLE_ESTIMATION)) || (!CFG_VDY_DIS_SIDE_SLIP_ANGLE_ESTIMATION) )
/* ***********************************************************************
  @fn               vdyGet_D_Work_vdy_sae */ /*!
  @brief           Get pointer to estimated vdy_sae internal data

  @description     Get pointer to estimated vdy_sae internal data

  @return          D_Work_vdy_sae pointer to slip angle data

  @glob_in         None 
  @glob_out        vdy_sae_DWork : estimated vdy_sae internal data

  @c_switch_part   None 
  @c_switch_full   VDY_SIMU
  @c_switch_full   
  - CFG_VDY_DIS_SIDE_SLIP_ANGLE_ESTIMATION : Disables the side slip angle estimation
  @pre             None
  @post            No changes
  @InOutCorrelation		  - 
  
	@startuml
  start
	:return (&vdy_sae_DWork);
  stop
  @enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> TEST_vdyGet_D_Work_vdy_sae_001()
  @traceability			  - NA
**************************************************************************** */
D_Work_vdy_sae    *vdyGet_D_Work_vdy_sae(void);
#endif


/* ***********************************************************************
  @fn               vdyProcess */ /*!
  @brief           Process vdy component

  @description     Processing VDY in the order: \n
                   - monitor input \n
                   - preprocessing \n
                   - handcode modules \n
                   - autocode module \n
                   - postprocessing \n
                   Handles the interfaces and data conversion between these modules. \n
                   Freezes internal data

  @return          static void

  @param[in]       *reqPorts : Request Ports
  @param[in,out]   *VDYIn : VDY Input Signal
  @param[in,out]   *proPorts : Provide ports
  @param[in]       services : Service Calls

  @glob_in         
				  VDY_SW_VERSION_NUMBER : Component version number
				  ExecCntr : Execution cycle counter
  @glob_out        None 

  @c_switch_part   
				  - VDY_VEH_DYN_INTFVER : 
				  - CFG_VDY_INT_GYRO : Enable internal yaw rate sensor processing
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation 
				  - VDY_VEH_DYN_INTFVER : 
				  - CFG_VDY_INT_GYRO : Enable internal yaw rate sensor processing
				  - Setup the version
				  - Increment execution cyle counter
				  - Monitor input signals and parameter only if the vdy is in running mode and INIT mode
				  - Initalizing the bRollerTestBench variable \n Update the right operand(ver number) for which version the RollerTestBench gets activated in MFC431.
				  - Process velocity during roll bench detection
				  - Transfer component input interface data and some additional infos to data acquisition
				  - VDY Pre Processing setup output states in condition of input states
				  - Process VDY handcode modules
				  - Interface between handcode (hd) and autocde (ac)
				  - Process VDY autocode modules
				  - Interface between autocde (ac) and  handcode (hd)
				  - VDY Post Processing setup output states in condition of input states
				  - Transfer component internal data to sync-data and MeasFreeze - for simulation purpose
				  - Transfer component output interface data to data acquisition
    
	@startuml
	start
		:Local instance of some NVM data used to copy it from const input pointer and modify them \n VDYNvData_t VDYNvData;
		:Setup the version \n VDYIn->Frame.Version = (uint32)VDY_SW_VERSION_NUMBER;
		:Increment execution cyle counter \n VDYIn->Frame.CycleCnt = VDYEnvFrmCnt.ExecCntr \n VDYEnvFrmCnt.ExecCntr++;
		:Monitor input signals and parameter only if the vdy is in running mode and INIT mode \n vdyMonitorInput(VDYIn, proPorts->pVDYErrors);
		:Initalizing the bRollerTestBench variable \n proPorts->pVehicleDynamicSignals->MotionState.bRollerTestBench = false;
		:Transfer component input interface data and some additional infos to data acquisition \n MEAS_FREEZE_DIRECT(VDY_MEAS_ID_INPUT, VDYIn, sizeof(VDYInputData_t));
		:VDY Pre Processing setup output states in condition of input states \n vdyPreProcess( reqPorts, VDYIn, &VDYNvData, proPorts);
		:Process VDY handcode modules \n vdyHandcodeProcess( reqPorts, VDYIn, proPorts, services);
		:Interface between handcode (hd) and autocde (ac) \n vdyInterfaceHand2Auto( VDYIn, &vdy_internal_data, &VDYModIf);
		:Process VDY autocode modules \n vdyAutocodeProcess( reqPorts, VDYIn, &VDYNvData, proPorts->pVDYErrors, services, proPorts);
		:Interface between autocde (ac) and  handcode (hd) \n vdyInterfaceAuto2Hand( &vdy_internal_data, &VDYModIf);
		:VDY Post Processing setup output states in condition of input states \n vdyPostProcess( reqPorts, VDYIn, &VDYNvData, proPorts);
		:Transfer component internal data to data acquisition \n vdyEnvMeasFreezeInternal(services);
		:Transfer component output interface data to data acquisition \n MEAS_FREEZE_DIRECT(VDY_MEAS_ID_NVMEM_AUTO,&VDYNvData,sizeof(VDYNvData_t));		
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> TEST_vdyProcess_001()
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdyProcess(const reqVdyPrtList_t *reqPorts, VDYInputData_t *VDYIn, proVdyPrtList_t *proPorts, const AS_t_ServiceFuncts *services);


/* ***********************************************************************
  @fn               vdyInitProcess */ /*!
  @brief           Initialize module data

  @description     Sets handcode, autocode and provived output data to default values

  @return          static void

  @param[in]       *reqPorts : Request Ports
  @param[in]       *input : Current Input Signal 
  @param[in]       *proPorts : Provide Ports

  @glob_in         None :
  @glob_out        LastFiltered : Last filtered dyn yaw rate offset
  @glob_out        OldFiltYawOffset : Filter delay for yaw rate offset

  @c_switch_part   
				  - CFG_VDY_YWR_OFFSET_MONITOR : Enables monitoring of yaw rate at vehicle-stop, during vehicle-stop and vehicle drive-off. During this driving
																conditions zero point offset is roughly observeable. Exceedance of limits are indicated by error eventst   
				  - CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING : Disables the sensor yaw rate pre processing, 
																		 - static (stand still)yaw rate offset
																		 - yaw rate from yaw rate sensor estimation 
				  - CFG_VDY_INT_GYRO : Enable internal yaw rate sensor processing  
				  - CFG_VDY_DIS_WHEEL_PRE_PROCESSING : Disables the wheel speed pre processing, 
																	- wheel offset estimation
																	- wheel velocity <-> puls fusion
																	- vehicle speed estimation
																	- wheel load dependancy estimation
																	- dynamic (drift) sensor yaw rate offset estimation
																	- wheel velocity yaw rate estimation   
				  - CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING : Disables the steering wheel angle sensor pre processing, 
																			   - steering wheel angle sensor offset estimation
																			   - estimation of self steering gradient
																			   - driver intended curvature
																			   - yaw rate from steering wheel sensor estimation   
				  - CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING : Disables the lateral acceleration sensor pre processing, 
																			   - lateral sensor offset estimation
																			   - yaw rate from lateral acceleration sensor estimation 
				  - CFG_VDY_DO_VELOCITY_CORR : Enables the velocity correction  
				  - CFG_VDY_USE_VELO_MONITOR : Enables monitoring of external vehicle velocity. The velocity is compared with estimated 
															  velocity based on wheel speeds  
				  - CFG_VDY_DIS_FUNCTIONAL_SAFETY_MON : Disable functional safety monitoring  
				  vCFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING : Disables the alignment yaw rate offset pre filtering, 
																			 - yaw rate from yaw rate sensor with filtered offset estimation 
				  - CFG_VDY_USE_EXT_PROC_YAW_RATE : Enables usage of external yaw rate as vdy output yaw rate  
				  - CFG_VDY_DIS_SIDE_SLIP_ANGLE_ESTIMATION : Disables the side slip angle estimation
				  - CFG_VDY_MOT_STATE : Enable motion state processing
				  - CFG_VDY_DIS_YWR_OFFSET_COMP : Disables zero point offset compensation of input yaw rate signal
				  - CFG_VDY_DIS_YAW_SENSOR_OUTPUT : Disables the alignment yaw rate output,
																 - yaw rate from yaw rate sensor with filtered offset estimation
  @c_switch_full   None

  @pre             None
  @post            No changes
  @InOutCorrelation	
					- Clear first cycle execution completed flag
					- Initialize yaw rate sensor module
					- Initialize yaw rate sensor module
					- Initialize yaw rate sensor offset monitoring
					- Initialize steering wheel angle sensor module
					- Initialize velocity monitoring
					- Initialize Functional safety monitoring functions
					- Initialize Module Interface
					- Initialize auto code models
						- vdy_wpp
						- vdy_ve
						- vdy_wye
						- vdy_gye
						- vdy_ay
						- vdy_sye
						- vdy_ve
						- vdy_mot_st
					- Initialize external yaw rate offset state
					- Initialize provide port's pVDYOffsets
					- Initialize provide port's pVDYErrors
					- Initialize monitoring data

    
					
	@startuml
	start
		:Clear first cycle execution completed flag \n VDY_RESET_FIRST_CYCLE_DONE;
		if (CFG_VDY_INT_GYRO)  then (YES)
			:VDYYwrtInit( proPorts );
		endif
		if ( (!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING) ) then (YES)
			:Initialize yaw rate sensor module \n vdyWhsInit();
		endif
		if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING) ) then (YES)
			:Initialize yaw rate sensor module \n vdyYwrInit(reqPorts ,proPorts);
		endif
		if (CFG_VDY_YWR_OFFSET_MONITOR)
			:Initialize yaw rate sensor offset monitoring \n vdyYwrMonInit(input, &VDYModIf, proPorts->pVDYErrors);
		endif
		if ( ( (!defined(CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING) ) || ( (!defined(CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING) ) ) then (YES)
			:Initialize steering wheel angle sensor module \n vdyAySwaInit(reqPorts , proPorts);
		endif
		if ( (defined(CFG_VDY_DO_VELOCITY_CORR)) && (CFG_VDY_DO_VELOCITY_CORR) ) then (YES)
			:Initialize velocity correction \n VDYVelCorrInit(proPorts);
		endif
		if (CFG_VDY_USE_VELO_MONITOR) then (YES)
			:Initialize velocity monitoring \n vdyVelMonInit( proPorts->pVDYErrors);
		endif
		if (!(defined(CFG_VDY_DIS_FUNCTIONAL_SAFETY_MON) && (CFG_VDY_DIS_FUNCTIONAL_SAFETY_MON))) then (YES)
			: Functional savety monitoring functions  \n vdyFSInit();
		endif
		:Module Interface \n vdyInitModuleIf(&VDYModIf) \n vdyInitInternal(&vdy_internal_data);
		:Initialize Auto code;
		if ((!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) then (YES)
			:Initialize vdy_wpp model \n vdy_wpp_initialize((boolean_T) 1, &vdy_wpp_M, &vdy_wpp_B, &vdy_wpp_DWork);
			:Initialize vdy_ve model \n vdy_ve_initialize((boolean_T) 1, &vdy_ve_M, &vdy_ve_B, &vdy_ve_DWork);  
			:Initialize vdy_wye model \n vdy_wye_initialize((boolean_T) 1, &vdy_wye_M, &vdy_wye_B, &vdy_wye_DWork);
		endif
		if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING) ) then (YES)
			:Initialize vdy_gye model \n vdy_gye_initialize((boolean_T) 1, &vdy_gye_M, &vdy_gye_B, &vdy_gye_DWork);
			if (!CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING) then (YES)
				:Initialize vdy_gye_filt model \n vdy_gye_initialize((boolean_T) 1, &vdy_gye_M_FILT, &vdy_gye_B_FILT, &vdy_gye_DWork_FILT);
				:Last filtered dyn yaw rate offset \n  LastFiltered = VDY_ZERO_F;
				:Filter delay for yaw rate offset \n OldFiltYawOffset = VDY_ZERO_F;
			endif
		endif
		if ((!defined(CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING)) then (YES)
			:Initialize vdy_ay model \n vdy_aye_initialize((boolean_T) 1, &vdy_aye_M, &vdy_aye_DWork);
		endif
		if ((!defined(CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING)) then (YES)
			:Initialize vdy_sye model \n vdy_sye_initialize((boolean_T) 1, &vdy_sye_M, &vdy_sye_B, &vdy_sye_DWork);
		endif
		if ( (!defined(CFG_VDY_USE_EXT_PROC_YAW_RATE)) || (!CFG_VDY_USE_EXT_PROC_YAW_RATE) ) then (YES)
			:Initialize vdy_ve model \n vdy_ye_initialize((boolean_T) 1, &vdy_ye_M, &vdy_ye_B, &vdy_ye_DWork);
		endif
		if ((!defined(CFG_VDY_DIS_SIDE_SLIP_ANGLE_ESTIMATION)) || (!CFG_VDY_DIS_SIDE_SLIP_ANGLE_ESTIMATION)) then (YES)
			:Initialize vdy_sae model \n vdy_sae_initialize((boolean_T) 1, &vdy_sae_M, &vdy_sae_DWork);
		endif
		if (CFG_VDY_MOT_STATE) then (YES)
			:Initialize vdy_mot_st model \n vdy_mot_st_initialize((boolean_T) 1, &vdy_mot_st_M , &vdy_mot_st_B, &vdy_mot_st_DWork);
		endif
		:vdy_internal_data.vdy_offsets_in.vdy_swa_offset.offset = VDY_ZERO_F;
		:vdy_internal_data.vdy_offsets_in.vdy_swa_offset.state = 1U;
		:vdy_internal_data.vdy_offsets_in.vdy_swa_offset.var   = VDY_ONE_NE_FIVE;
		:vdy_internal_data.vdy_offsets_in.vdy_yaw_offset.offset = VDY_ZERO_F;
		:vdy_internal_data.vdy_offsets_in.vdy_yaw_offset.state = 1U;
		:vdy_internal_data.vdy_offsets_in.vdy_yaw_offset.var   = VDY_ONE_NE_NINE;
		if ( (!defined(CFG_VDY_DIS_YWR_OFFSET_COMP)) || (!CFG_VDY_DIS_YWR_OFFSET_COMP) ) then (YES)
			:init external yaw rate offset state \n VDYOutYwrOffsType = (VDYOutYwrOffsType_t)OUT_YWR_OFFS_NON;
		endif
		:vdy_internal_data.vdy_offsets_in.vdy_ay_offset.offset = VDY_ZERO_F;
		:vdy_internal_data.vdy_offsets_in.vdy_ay_offset.state = 1U;
		:vdy_internal_data.vdy_offsets_in.vdy_ay_offset.var   = VDY_TWENTY_CENT;
		:vdy_internal_data.vdy_offsets_in.vdy_whs_offset.offset_ratio_front     = VDY_ONE_F;
		:vdy_internal_data.vdy_offsets_in.vdy_whs_offset.offset_ratio_front_dev = VDY_ONE_F;
		:vdy_internal_data.vdy_offsets_in.vdy_whs_offset.offset_ratio_rear      = VDY_ONE_F;
		:vdy_internal_data.vdy_offsets_in.vdy_whs_offset.offset_ratio_rear_dev  = VDY_ONE_F;
		:vdy_internal_data.vdy_offsets_in.vdy_whs_offset.SpeedRange             = 0;
		if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_OUTPUT)) || (!CFG_VDY_DIS_YAW_SENSOR_OUTPUT) ) then (YES)
			:Initalize alignment yaw rate \n vdyInitALNYawRate(proPorts->pALNYawRate);
		endif
		:Initialize offsets \n vdyInitOffsets(proPorts->pVDYOffsets);
		:Initialize error states \n vdyInitErrors(proPorts->pVDYErrors);
		:Init monitoring \n vdyInitMon();
		:return;	
	stop
	@enduml
  @testmethod			  - NA
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdyInitProcess(const reqVdyPrtList_t *reqPorts, const VDYInputData_t *input, const proVdyPrtList_t *proPorts);


/* ***********************************************************************
  @fn               vdyInit */ /*!
  @brief           Initialize all component data

  @description     Handles initialisation of VDY

  @return          static void

  @param[in]       *reqPorts : requested ports
  @param[in,out]   *VDYIn : Input of the Vehicle Dynamics Module
  @param[in]       *proPorts : provided ports
  @param[in]       services : Service Calls

  @glob_in         None
  @glob_out        
			  ExecCntr : Execution cycle counter \n   
			  u_CurveFaultCounter : Kalman gain data from YE Kalman filter \n       
			  u_YawFaultCounter : Kalman gain data from YE Kalman filter \n       
			  u_DICurveFaultCounter : Kalman gain data from YE Kalman filter \n       
			  u_count : Counter for reducing the curve error at system reset siuations \n  
			  b_RTBDetection : Instance for Roller test bench recognition

  @c_switch_part   None
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation 
				  - Initialization of component
				  - Initialize cycle counters
				  - copy input signals and parameters
				  - copy input signals to debouncing buffer
				  - clear debouncing counter
				  - copy input signals for signal peak detection
				  - Transfer component's internal input data and some additional infos to simulation
				  - Transfer component internal data to sync-data and MeasFreeze - for simulation purpose
				  - Init sequence package counter
				  - Init acceleration velocity filter
				  
	@startuml
	start
		:Init cycle counters \n VDYEnvFrmCnt.ExecCntr = 0U \n VDYIn->Frame.CycleCnt = 0U;
		:copy input signals \n (void)vdy_memcpy_s(&VDYIn->Signals, &reqPorts->pVehicleInputSignals->VehSigMain, sizeof(VehSigMain_t));
		:copy input parameters \n (void)vdy_memcpy_s(&VDYIn->Parameter, &reqPorts->pVehicleParameter->VehParMain, sizeof(VehParMain_t));
		:copy input signals to debouncing buffer \n (void)vdy_memcpy_s(&s_LastInputSignals, &reqPorts->pVehicleInputSignals->VehSigMain, sizeof(VehSigMain_t));
		:clear debouncing counter \n (void)vdy_memset_s(u_DebouceCounter, 0x00, VDY_SIN_POS_MAX);
		if( (defined(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))&&(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK)) then (YES)
			:VDYIoState_t ioStateSSG \n VDYIoState_t ioStateWLD;
			if(SSG and WLD offset writing in init mode \n reqPorts->pNVMRead->State == NVM_CLEARED) then (YES)
				:(void)vdy_memset_s(&proPorts->pNVMWrite->SlfstGrad  , 0 , sizeof(VDYNvSlfStGradCal_t));
				:(void)vdy_memset_s(&proPorts->pNVMWrite->Wld  , 0 , sizeof(VDYNvWldCal_t));
			else (NO)
				:proPorts->pNVMWrite->SlfstGrad = reqPorts->pNVMRead->SlfstGrad;
				:proPorts->pNVMWrite->Wld = reqPorts->pNVMRead->Wld;
				if( (defined(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))&&(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK)) then (YES)
					:proPorts->pNVMWrite->SlfstGrad.Dummy = VDY_ZERO_U;
					:proPorts->pNVMWrite->Wld.Wld_rear = VDY_ZERO_F;
					:proPorts->pNVMWrite->Wld.Wld_rear_quality = 0;
				endif
				:ioStateSSG = VDY_GET_NVM_IO_STATE(VDY_NVM_POS_SSG, &reqPorts->pNVMRead->State);
				:VDY_SET_NVM_IO_STATE(VDY_NVM_POS_SSG, ioStateSSG, &proPorts->pNVMWrite->State);
				:ioStateWLD = VDY_GET_NVM_IO_STATE(VDY_NVM_POS_WLD, &reqPorts->pNVMRead->State);
				:VDY_SET_NVM_IO_STATE(VDY_NVM_POS_WLD, ioStateWLD, &proPorts->pNVMWrite->State);
			endif
		endif
		:copy input signals for signal peak detection \n vdyInitForCheckSignalPeakErrors(VDYIn);
		:Initialization of component \n vdyInitProcess(reqPorts, VDYIn, proPorts);
		:vdyEnvMeasFreezeInternal(services, VDYIn);
		:Init sequence package counter;
		if ( defined(VDY_FREEZE_INIT_SEQUENCE) && (VDY_FREEZE_INIT_SEQUENCE) ) then (YES)
			:VDY_SET_ALL_SEQUENCE_STATES_TO_INIT(sSequenceInitState);
			:InitPackageID = 0U;
		endif
		:Init acceleration velocity filter;
		if (!(CFG_VDY_USE_EX_LONG_ACCEL) && (CFG_VDY_USE_EX_LONG_VELO)) then (YES)
			:External velocity without related acceleration is provided \n oldVelocityIn = s_LastInputSignals.VehVelocityExt;
		endif
		:vdy_ye_k.u_CurveFaultCounter = 0U;
		:vdy_ye_k.u_YawFaultCounter = 0U;
		:vdy_ye_k.u_DICurveFaultCounter = 0U;
		if ( (defined(CFG_VDY_REDUCE_CURVE_ERROR)) && (CFG_VDY_REDUCE_CURVE_ERROR) ) then (YES)
			:u_count = 0U;
		endif
		:b_RTBDetection = false;
		:return;
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> TEST_vdyInit_001(), TEST_vdyInit_002()
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdyInit(const reqVdyPrtList_t *reqPorts, VDYInputData_t *VDYIn, const proVdyPrtList_t *proPorts, const AS_t_ServiceFuncts * services);


/* ***********************************************************************
  @fn               vdyGetConfig */ /*!
  @brief           Functional Summary

  @description     Collects the configuration of the custom part and
                   does the MTS output of the configuration
                   Output is done only every 50th cycle to reduce MTS load

  @return          static void

  @param[in]       - void

  @c_switch_part   
				  - AS_SERVICEFUNC_VERSION : Servicefunctions version   
				  - CFG_VDY_USE_CORRECT_VELO_CORR_VAR : Enable lower max. variance of velocity correction factor variance if one measurement update is available   
				  - CFG_VDY_ROLLBENCH_DETECTION : Enables reaction to roll bench detection  
				  - CFG_VDY_DIS_SWA_OFFSET_COMP : Disables zero point offset compensation of input steering wheel angle signal  
				  - CFG_VDY_DIS_YWR_OFFSET_COMP : Disables zero point offset compensation of input yaw rate signal 
				  - CFG_VDY_DIS_WHS_OFFSET_COMP : Disables offset compensation between left and right wheel on vehicle axle  
				  - CFG_VDY_DIS_LAT_OFFSET_COMP : Disables zero point offset compensation of input lateral acceleration signal
				  - CFG_VDY_USE_EXT_PROC_UNDERSTEER_GRAD : Enables usage external estimated understeer gradient (characteristic velocity) as input parameter   
				  - CFG_VDY_USE_VELO_MONITOR : Enables monitoring of external vehicle velocity. The velocity is compared with estimated velocity based on wheel speeds  
				  - CFG_VDY_YWR_OFFSET_MONITOR : Enables monitoring of yaw rate at vehicle-stop, during vehicle-stop and vehicle drive-off. During this driving conditions zero point offset is roughly observeable. Exceedance of limits are indicated by error events   
				  - CFG_VDY_DIS_WHEEL_PRE_PROCESSING : Disables the wheel speed pre processing, 
																	- wheel offset estimation
																	- wheel velocity <-> puls fusion
																	- vehicle speed estimation
																	- wheel load dependancy estimation
																	- dynamic (drift) sensor yaw rate offset estimation
																	- wheel velocity yaw rate estimation  
				  - CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING : Disables the sensor yaw rate pre processing, 
																		  - static (stand still)yaw rate offset
																		  - yaw rate from yaw rate sensor estimation  
				  - CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING : Disables the alignment yaw rate offset pre filtering, 
																			 - yaw rate from yaw rate sensor with filtered offset estimation    
				  - CFG_VDY_DIS_YAW_SENSOR_OUTPUT : Disables the alignment yaw rate output,
																 - yaw rate from yaw rate sensor with filtered offset estimation   
				  - CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING : Disables the lateral acceleration sensor pre processing, 
																				- lateral sensor offset estimation
																				- yaw rate from lateral acceleration sensor estimation  
				  - CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING : Disables the steering wheel angle sensor pre processing, 
																				- steering wheel angle sensor offset estimation
																				- estimation of self steering gradient
																				- driver intended curvature
																				- yaw rate from steering wheel sensor estimation 
				  - CFG_VDY_DIS_SIDE_SLIP_ANGLE_ESTIMATION : Disables the side slip angle estimation
				  - CFG_VDY_GEN_VELOCITY_VARIANCE : Generated a velocity variance by deviation of the acceleration 
				  - CFG_VDY_ALIGNMENT_OFFSET_MONITOR : Do yaw rate offset monitoring with alignment offset estimation input 
				  - CFG_VDY_CALC_VDY_TIMING : Do yaw rate offset monitoring with alignment offset estimation input
				  - CFG_VDY_SET_DEM_EVENTS : Enables setting DEM events by VDY, otherwise only the VDYError flags are set
  @c_switch_full   None

  @pre             None
  @post            No changes
  @InOutCorrelation 
					- Get VDY algo configurations
  
	@startuml
	start
		:static uint8 nCounter = 0U;
		:VDYConfig Configuration \n VDYConfig_t  VDYConfig;
		if (nCounter < (VDY_FIFTY_U)) then (YES)
			:nCounter++;
		else (NO)
			:Block A;
			:Block B;
			:Block C;				
		endif	
	stop
	@enduml

- Block A
	@startuml
	start
		:Store custom version number \n VDYConfig.Version	= VDY_CUSTOM_VERSION_NUMBER;
		:Enable dynamic gyro offst compensation \n DYConfig.cfg_vdy_yw_dyn_avg = CFG_VDY_YW_DYN_AVG;
		:Enable offset storage  in nonvolatile Memory \n VDYConfig.cfg_vdy_ex_ywr_nvm = CFG_VDY_EX_YWR_NVM;
		:Enable internal yaw rate sensor processing \n VDYConfig.cfg_vdy_int_gyro = CFG_VDY_INT_GYRO;
		:Enable optimized math functio approximation \n VDYConfig.cfg_vdy_fpm_754 = CFG_VDY_FPM_754;
		:Use external provided longitudinal acceleration signal \n VDYConfig.cfg_vdy_use_ex_long_accel = CFG_VDY_USE_EX_LONG_ACCEL;
		:Use external provided longitudinal velocity signal \n VDYConfig.cfg_vdy_use_ex_long_velo = CFG_VDY_USE_EX_LONG_VELO;
		:Enable motion state processing \n VDYConfig.cfg_vdy_mot_state = CFG_VDY_MOT_STATE;
		:Enables the velocity correction \n VDYConfig.cfg_vdy_do_velocity_corr = CFG_VDY_DO_VELOCITY_CORR;
		:Enables the velocity correction \n VDYConfig.vel_corr_aln = VEL_CORR_ALN;
		:Enables the velocity correction \n VDYConfig.vel_corr_hist_stationary_targets = VEL_CORR_HIST_STATIONARY_TARGETS;
	stop
	@enduml

- Block B
	@startuml
	start
		if ( (defined(CFG_VDY_USE_CORRECT_VELO_CORR_VAR)) && (CFG_VDY_USE_CORRECT_VELO_CORR_VAR) ) then (YES)
			:VDYConfig.cfg_vdy_use_correct_velo_corr_var = CFG_VDY_USE_CORRECT_VELO_CORR_VAR;
		else (NO)
			:VDYConfig.cfg_vdy_use_correct_velo_corr_var = 0;
		endif
		if (defined(CFG_VDY_ROLLBENCH_DETECTION)) then (YES)
			:Enables the roll bench detection \n VDYConfig.cfg_vdy_rollbench_detection = CFG_VDY_ROLLBENCH_DETECTION;
		else (NO) 
			:VDYConfig.cfg_vdy_rollbench_detection = 0U;
		endif
		:Enables usage of external curve as vdy output curve \n VDYConfig.cfg_vdy_use_ext_proc_curvature = CFG_VDY_USE_EXT_PROC_CURVATURE;
		:Enables usage of external yaw rate as vdy output yaw rate \n VDYConfig.cfg_vdy_use_ext_proc_yaw_rate = CFG_VDY_USE_EXT_PROC_YAW_RATE;
		:Enables usage of external side slip angle as vdy ouput side slip angle \n VDYConfig.cfg_vdy_use_ext_proc_side_slip_angle = CFG_VDY_USE_EXT_PROC_SIDE_SLIP_ANGLE;
		if (defined(CFG_VDY_DIS_SWA_OFFSET_COMP) ) then (YES)
			:VDYConfig.cfg_vdy_dis_swa_offset_comp = CFG_VDY_DIS_SWA_OFFSET_COMP;
		else (NO) 
			:VDYConfig.cfg_vdy_dis_swa_offset_comp = 0U;
		endif
		if (defined(CFG_VDY_DIS_YWR_OFFSET_COMP) ) then (YES)
			:VDYConfig.cfg_vdy_dis_ywr_offset_comp = CFG_VDY_DIS_YWR_OFFSET_COMP;
		else (NO) 
			:VDYConfig.cfg_vdy_dis_ywr_offset_comp = 0U;
		endif
		if (defined(CFG_VDY_DIS_WHS_OFFSET_COMP) ) then (YES)
			:VDYConfig.cfg_vdy_dis_whs_offset_comp = CFG_VDY_DIS_WHS_OFFSET_COMP;
		else (NO) 
			:VDYConfig.cfg_vdy_dis_whs_offset_comp = 0U;
		endif
		if (defined(CFG_VDY_DIS_LAT_OFFSET_COMP) ) then (YES)
			:VDYConfig.cfg_vdy_dis_lat_offset_comp = CFG_VDY_DIS_LAT_OFFSET_COMP;
		else (NO) 
			:VDYConfig.cfg_vdy_dis_lat_offset_comp = 0U;
		endif
		if (defined(CFG_VDY_USE_EXT_PROC_UNDERSTEER_GRAD) ) then (YES)
			:VDYConfig.cfg_vdy_use_ext_proc_understeer_grad = CFG_VDY_USE_EXT_PROC_UNDERSTEER_GRAD;
		else (NO) 
			:VDYConfig.cfg_vdy_use_ext_proc_understeer_grad = 0U;
		endif
		:If the learned understeer gradiend should be used \n VDYConfig.vdy_use_learned_understeer_grad = VDY_USE_LEARNED_UNDERSTEER_GRAD;
		:If the estimated wheel load dep should be used \n VDYConfig.vdy_use_est_wld_dep = VDY_USE_EST_WLD_DEP;
		if (defined(CFG_VDY_USE_VELO_MONITOR) ) then (YES)
			:VDYConfig.cfg_vdy_use_velo_monitor = CFG_VDY_USE_VELO_MONITOR;
		else (NO) 
			:VDYConfig.cfg_vdy_use_velo_monitor = 0U;
		endif
		if (defined(CFG_VDY_YWR_OFFSET_MONITOR) ) then (YES)
			:VDYConfig.cfg_vdy_ywr_offset_monitor = CFG_VDY_YWR_OFFSET_MONITOR;
		else (NO) 
			:VDYConfig.cfg_vdy_ywr_offset_monitor = 0U;
		endif
		if (defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING) ) then (YES)
			:VDYConfig.cfg_vdy_dis_wheel_pre_processing = CFG_VDY_DIS_WHEEL_PRE_PROCESSING;
		else (NO) 
			:VDYConfig.cfg_vdy_dis_wheel_pre_processing = 0U;
		endif
		if (defined(CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING) ) then (YES)
			:VDYConfig.cfg_vdy_dis_yaw_sensor_pre_processing = CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING;
		else (NO) 
			:VDYConfig.cfg_vdy_dis_yaw_sensor_pre_processing = 0U;
		endif
		if (defined(CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING) ) then (YES)
			:VDYConfig.cfg_vdy_dis_yaw_sensor_offs_pre_filtering = CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING;
		else (NO)
			:VDYConfig.cfg_vdy_dis_yaw_sensor_offs_pre_filtering = 0U;
		endif
		if (defined(CFG_VDY_DIS_YAW_SENSOR_OUTPUT) ) then (YES)
			:VDYConfig.cfg_vdy_dis_yaw_sensor_output = CFG_VDY_DIS_YAW_SENSOR_OUTPUT;
		else (NO) 
			:VDYConfig.cfg_vdy_dis_yaw_sensor_output = 0U;
		endif
		if (defined(CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING) ) then (YES)
			:VDYConfig.cfg_vdy_dis_lat_accel_sensor_pre_processing = CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING;
		else (NO) 
			:VDYConfig.cfg_vdy_dis_lat_accel_sensor_pre_processing = 0U;
		endif
		if (defined(CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING) ) then (YES)
			:VDYConfig.cfg_vdy_dis_stw_angle_sensor_pre_processing = CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING;
		else (NO) 
			:VDYConfig.cfg_vdy_dis_stw_angle_sensor_pre_processing = 0U;
		endif
		if (defined(CFG_VDY_DIS_SIDE_SLIP_ANGLE_ESTIMATION) ) then (YES)
			:VDYConfig.cfg_vdy_dis_side_slip_angle_estimation = CFG_VDY_DIS_SIDE_SLIP_ANGLE_ESTIMATION;
		else (NO) 
		    :VDYConfig.cfg_vdy_dis_side_slip_angle_estimation = 0U;
		endif
		if (defined(CFG_VDY_GEN_VELOCITY_VARIANCE) ) then (YES)
			:VDYConfig.cfg_vdy_gen_velocity_variance = CFG_VDY_GEN_VELOCITY_VARIANCE;
		else (NO) 
		    :VDYConfig.cfg_vdy_gen_velocity_variance = 0U;
		endif
		if (defined(CFG_VDY_ALIGNMENT_OFFSET_MONITOR) ) then (YES)
			:VDYConfig.cfg_vdy_alignment_offset_monitor = CFG_VDY_ALIGNMENT_OFFSET_MONITOR;
		else (NO) 
		    :VDYConfig.cfg_vdy_alignment_offset_monitor = 0U;
		endif
		:VDYConfig.cfg_vdy_dis_functional_safety_mon = CFG_VDY_DIS_FUNCTIONAL_SAFETY_MON;
		:VDYConfig.cfg_vdy_64bit_timestamp_interv = CFG_VDY_64BIT_TIMESTAMP_INTERV;
		:VDYConfig.cfg_vdy_dis_curve_output = CFG_VDY_DIS_CURVE_OUTPUT;
		if (defined(CFG_VDY_CALC_VDY_TIMING) ) then (YES)
			:If the timing should be calculated \n VDYConfig.cfg_vdy_calc_vdy_timing = CFG_VDY_CALC_VDY_TIMING;
		else (NO) 
		    :VDYConfig.cfg_vdy_calc_vdy_timing = 0U;
		endif
		:VDYConfig.cfg_vdy_fs_velo_corr_mon = CFG_VDY_FS_VELO_CORR_MON;
		:VDYConfig.cfg_vdy_mon_output_peaks = CFG_VDY_MON_OUTPUT_PEAKS;
		:VDYConfig.vdy_profiling_enabled = VDY_PROFILING_ENABLED;
		:VDYConfig.cfg_vdy_use_algocompstate = CFG_VDY_USE_ALGOCOMPSTATE;
		if (defined(CFG_VDY_SET_DEM_EVENTS) ) then (YES)
			:VDYConfig.cfg_vdy_set_dem_events = CFG_VDY_SET_DEM_EVENTS;
		else (NO) 
			:VDYConfig.cfg_vdy_set_dem_events = 0U;
		endif
	stop
	@enduml

- Block C
	@startuml
	start
		:Enables setting DEM event VelMon \n VDYConfig.cfg_vdy_fs_velo_conf_mon_fault =  CFG_VDY_FS_VELO_CONF_MON_FAULT;
			:Enables the increase of correction factor for trucks \n VDYConfig.cfg_vdy_truck_corrfact =  CFG_VDY_TRUCK_CORRFACT;
			:Enables the max debouncing ouput counter \n VDYConfig.cfg_vdy_debounce_outputs =  CFG_VDY_DEBOUNCE_OUTPUTS;
			:Enables the Turn Table detection and limit max. delta 4deg/sec yaw rate offset compensation at one learning cycle \n VDYConfig.cfg_vdy_turntable_detection =  CFG_VDY_TURNTABLE_DETECTION;
			:Enables the increase of correction factor to 30% for ARS4D2 \n VDYConfig.cfg_vdy_corrfact_ars4d2 =  CFG_VDY_CORRFACT_ARS4D2;
			:Disables Valid Or Invalid check before reading NVM and writes NVM data  in every vdy cycle to the provide port for camera(MDB) projects for steering wheel angle , \n Ay ,Yaw offset also SSD and WLD data \n VDYConfig.cfg_vdy_swa_ay_yaw_ssd_wld_dis_nvm_valid_check =  CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK;
			:Enables the velocity variance check for setting the velocity not available DEM \n VDYConfig.cfg_vdy_velo_variance_check =  CFG_VDY_VELO_VARIANCE_CHECK;
			:Enables the corrected velocity monitoring based on the new minimum and maximum velocity signals \n VDYConfig.cfg_vdy_velo_monitor_min_max =  CFG_VDY_VELO_MONITOR_MIN_MAX;
			:Enables the code for reducing the curve error after software reset \n VDYConfig.cfg_vdy_reduce_curve_error =  CFG_VDY_REDUCE_CURVE_ERROR;
			:Enable DEM relates NVM learning values to ensure no corrupted data is written to flash memory \n VDYConfig.cfg_vdy_nvm_learn_data_error =  CFG_VDY_NVM_LEARN_DATA_ERROR;
			:Disable unused function throwing red error in polyspace \n VDYConfig.cfg_vdy_polyspace_error_disable =  CFG_VDY_POLYSPACE_ERROR_DISABLE;
			:Enable measfreezing of VDY Structure VDYNvIoDataRD \n VDYConfig.cfg_vdy_vdynviodatard_measfreez_enable =  CFG_VDY_VDYNVIODATARD_MEASFREEZ_ENABLE;
			:Enables the switch to stop toggling the DEM for trucks \n VDYConfig.cfg_vdy_init_mode_as_startup_mode =  CFG_VDY_INIT_MODE_AS_STARTUP_MODE;
			:Enables the switch to Rear Wheel Steer \n VDYConfig.cfg_vdy_rear_wheel_steering =  CFG_VDY_REAR_WHEEL_STEERING;
			:Enables the FS_YR_VS_WSP DEM \n VDYConfig.cfg_vdy_fs_yr_vs_wsp_enable =  CFG_VDY_FS_YR_VS_WSP_ENABLE;
			:Enables the BMW acceleration Model \n VDYConfig.cfg_vdy_bmw_long_accel_model =  CFG_VDY_BMW_LONG_ACCEL_MODEL;
			:Enables the yaw rate variance check for yaw rate not available DEM \n VDYConfig.cfg_vdy_yawrate_variance_check =  CFG_VDY_YAWRATE_VARIANCE_CHECK;
			:Enables the monitor of corrected velocity and ALN velocity error \n VDYConfig.cfg_vdy_fs_velo_corr_mon_error =  CFG_VDY_FS_VELO_CORR_MON_ERROR;
			:Enables the code to stop toggling of FS_VEH_CORR_MON DEM \n VDYConfig.cfg_vdy_fs_veh_corr_mon_toggling =  CFG_VDY_FS_VEH_CORR_MON_TOGGLING;
			:Enables MFC specific logic \n VDYConfig.cfg_vdy_mfc =  CFG_VDY_MFC;
			:Enables usage of ABS/TCS info in velocity and accel estimation \n VDYConfig.cfg_vdy_int_tcs_abs =  CFG_VDY_INT_TCS_ABS;
			:MFC5xx specific switch \n VDYConfig.cfg_vdy_mfc_vx =  CFG_VDY_MFC_VX;
			:nCounter = 0U;
			:MEAS_FREEZE_DIRECT(VDY_MEAS_ID_CONFIG,  &VDYConfig, sizeof(VDYConfig));
	stop
	@enduml

  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> TEST_vdyGetConfig_001()
  @traceability			  - NA
  **************************************************************************** */
STATIC_MTD void vdyGetConfig(void);


/* ***********************************************************************
  @fn               vdyLearnInitWithParams */ /*!
  @brief           Init learn values ssg and wld with parameter values

  @description     Read the NVM learn values selfsteeringgradient and
                   wheelloaddependencies, and update the used parameter values
                   If no NVM learn values are available, the coding parameter values
                   are stored in NVM

  @return          static void

  @param[in]       *input : Current Input Data
  @param[in,out]   nvdata : NVM Data

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation 
					  - init learn self steering gradient with the vehicle parameter if the parameter is available and the nvm not yet initialized
					  - Set CalStatus to 1, Self steering gradient is initialized with vehicle parameter
					  - init learn wheel load dependency with the vehicle parameter if the parameter is available and the nvm not yet initialized
					  - Set quality to 1, wheel load dependency is initialized with vehicle parameter
 
	@startuml
	start
		if ( init learn self steering gradient with the vehicle parameter if the parameter is available and the nvm not yet initialized \n (nvdata->Read.SlfstGrad.CalStatus == (sint8)0) && (VDY_GET_IO_STATE(VDY_PAR_POS_SSG, input->Parameter.State) == (VDYIoStateTypes_t)VDY_IO_STATE_VALID)  ) then (YES)
			:nvdata->Read.SlfstGrad.SlfStGrad = input->Parameter.SelfSteerGrad;
			:nvdata->Read.SlfstGrad.SlfStGradMax = (uint8) (ROUND_TO_UINT(VDY_NVM_USTG_INV_SCALE*input->Parameter.SelfSteerGrad) & VDY_X_FF);
			:nvdata->Read.SlfstGrad.SlfStGradMin = (uint8) (ROUND_TO_UINT(VDY_NVM_USTG_INV_SCALE*input->Parameter.SelfSteerGrad) & VDY_X_FF);
			:Set CalStatus to 1, Self steering gradient is initialized with vehicle parameter \n nvdata->Write.SlfstGrad.CalStatus = (sint8)1;
		else (NO)
			:nvdata->Write.SlfstGrad.CalStatus = nvdata->Read.SlfstGrad.CalStatus;
			:VDY_SET_NVM_IO_STATE(VDY_NVM_POS_SSG, VDY_IO_STATE_INVALID, &nvdata->Read.State);
			:VDY_SET_NVM_IO_STATE(VDY_NVM_POS_SSG, VDY_IO_STATE_INVALID, &nvdata->Write.State);
		endif
		if ( init learn wheel load dependency with the vehicle parameter if the parameter is available and the nvm not yet initialized \n 
			(nvdata->Read.Wld.Wld_front_quality == (uint8)0U) && (input->Parameter.WhlLoadDepFrontAxle > VDY_ZERO_F) && (VDY_GET_IO_STATE(VDY_PAR_POS_WHLDFR, input->Parameter.State) == (VDYIoStateTypes_t)VDY_IO_STATE_VALID)  ) then (YES)
			:nvdata->Read.Wld.Wld_front = input->Parameter.WhlLoadDepFrontAxle;
			:nvdata->Write.Wld.Wld_front = nvdata->Read.Wld.Wld_front;
			:Set quality to 1, wheel load dependency is initialized with vehicle parameter \n nvdata->Write.Wld.Wld_front_quality = 1U;
		else (NO)
			:nvdata->Write.Wld.Wld_front_quality = nvdata->Read.Wld.Wld_front_quality;
			:VDY_SET_NVM_IO_STATE(VDY_NVM_POS_WLD, VDY_IO_STATE_INVALID, &nvdata->Read.State);
			:VDY_SET_NVM_IO_STATE(VDY_NVM_POS_WLD, VDY_IO_STATE_INVALID, &nvdata->Write.State);
		endif
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> \n
                            TEST_vdyLearnInitWithParams_001(), \n
                            TEST_vdyLearnInitWithParams_002(), \n
                            TEST_vdyLearnInitWithParams_003(), \n 
                            TEST_vdyLearnInitWithParams_004()
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdyLearnInitWithParams(const VDYInputData_t *input, VDYNvData_t * nvdata);


/* ***********************************************************************
  @fn               vdyPreProcess */ /*!
  @brief           VDY pre processing setup input and output states

  @description     Inits learn values ssg and wld
                   Sets the output states depending of input state and configuraton
                   and the yaw rate state depending on internal and external yaw rate
                   Sets output motion state if probability processing is disabled

  @return          static void

  @param[in]       *reqPorts : requested ports
  @param[in]       input : external input signals
  @param[in,out]   *VDYNvData : learn values from NVM
  @param[in]       *proPorts : provided ports

  @c_switch_part   
				  - CFG_VDY_USE_EX_LONG_VELO : Use external provided longitudinal velocity signal  
				  - CFG_VDY_USE_EX_LONG_ACCEL : Use external provided longitudinal acceleration signal  
				  - CFG_VDY_MOT_STATE : Enable motion state processing  
				  - CFG_VDY_INT_GYRO : Enable internal yaw rate sensor processing   
				  - CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING : Disables the sensor yaw rate pre processing, 
																		  - static (stand still)yaw rate offset
																		  - yaw rate from yaw rate sensor estimation  
				  - CFG_VDY_USE_EXT_PROC_YAW_RATE : Enables usage of external yaw rate as vdy output yaw rate 
				  - CFG_VDY_DIS_YAW_SENSOR_OUTPUT : Disables the alignment yaw rate output,
																  - yaw rate from yaw rate sensor with filtered offset estimation  
				  - CFG_VDY_DIS_SIDE_SLIP_ANGLE_ESTIMATION : Disables the side slip angle estimation
  @c_switch_full   None 

  @glob_in         VDY_PAR_ACCEL_EXT_UNC : Acceleration variance in case of external conditioned acceleration
  @glob_out        VDYModIf : Component internal intra module interface

  @pre             None
  @post            No changes
  @InOutCorrelation 
					  - Convert cycle time to float value with unit sec
					  - In case of Startup state reset first cycle done flag
					  - Clear flag to indicate that first cycle execution has not been completed
					  - copy the autocode nvm data from the request and provide port to a local buffer
					  - check for valid values read from NVM
					  - Init learn values ssg and wld with parameter values				
					  - set output state of lateral acceleration depending on yaw rate and lateral acceleration
					  - if input yawrate and lataccel are invalid, output Lataccel is also invalid
					  - Set output state of driver intended curvature depending on swa input state
  
	@startuml
	start
		:Convert cycle time to float value with unit sec;
		:In case of Startup state reset first cycle done flag;
		:Clear flag to indicate that first cycle execution has not been completed;
		:copy the autocode nvm data from the request and provide port to a local buffer;
		:check for valid values read from NVM;
		:Init learn values ssg and wld with parameter values;
		:set output state of lateral acceleration depending on yaw rate and lateral acceleration;
		:if input yawrate and lataccel are invalid, output Lataccel is also invalid;
		:Set output state of driver intended curvature depending on swa input state;		
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> TEST_vdyPreProcess_001(), TEST_vdyPreProcess_002()
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdyPreProcess(const reqVdyPrtList_t *reqPorts, const VDYInputData_t * input, VDYNvData_t *VDYNvData, const proVdyPrtList_t *proPorts);


/* ***********************************************************************
  @fn               vdyHandcodeProcess */ /*!
  @brief           VDY processing of handcode modules

  @description     Executing VDY handcode modules in the order:
                   - internal gyro processing
                   - velocity correction
                   - stand still yaw rate offset processing
                   - steering angle and lateral acceleration offset processing
                   - wheel velocity offset (left-right at one axle) processing

  @return          static void

  @param[in]       *reqPorts : Request Ports
  @param[in]       input : Current Input Signal
  @param[in]       *proPorts : Provide Ports
  @param[in]       services : Service Calls

  @glob_in         None 
  @glob_out        VDYModIf : Component internal intra module interface

  @c_switch_part   
				  - CFG_VDY_INT_GYRO : Enable internal yaw rate sensor processing
				  - CFG_VDY_DO_VELOCITY_CORR : Enables the velocity correction
				  - CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING : Disables the sensor yaw rate pre processing, 
																		  - static (stand still)yaw rate offset
																		  - yaw rate from yaw rate sensor estimation
				  - CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING : Disables the lateral acceleration sensor pre processing, 
																				- lateral sensor offset estimation
																				- yaw rate from lateral acceleration sensor estimation  
				  - CFG_VDY_DIS_WHEEL_PRE_PROCESSING : Disables the wheel speed pre processing, 
																	- wheel offset estimation
																	- wheel velocity <-> puls fusion
																	- vehicle speed estimation
																	- wheel load dependancy estimation
																	- dynamic (drift) sensor yaw rate offset estimation
																	- wheel velocity yaw rate estimation
				  - VDY_PROFILING_ENABLED : Enables runtime measurement and profiling 
				  - CFG_VDY_YWR_OFFSET_MONITOR : Enables monitoring of yaw rate at vehicle-stop, during vehicle-stop and vehicle drive-off. During this driving
																conditions zero point offset is roughly observeable. Exceedance of limits are indicated by error events
				  - CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING : Disables the steering wheel angle sensor pre processing, 
																				- steering wheel angle sensor offset estimation
																				- estimation of self steering gradient
																				- driver intended curvature
																				- yaw rate from steering wheel sensor estimation
  @c_switch_full   None 
  @pre             None
  @post            No changes
  @InOutCorrelation 
					- stand still yaw rate offset processing
					- Monitoring of stand still yaw rate offset
					- Execute steering wheel angle sensor signal processing
					- Execute wheel speed sensors signal processing
 
  
	@startuml
	start
		:stand still yaw rate offset processing;
		:Monitoring of stand still yaw rate offset;
		:Execute steering wheel angle sensor signal processing;
		:Execute wheel speed sensors signal processing;
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> TEST_vdyHandcodeProcess_001(), TEST_vdyHandcodeProcess_002()
  @traceability			  - 
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-656-00026448
**************************************************************************** */
STATIC_MTD void vdyHandcodeProcess(const reqVdyPrtList_t *reqPorts,const VDYInputData_t * input, proVdyPrtList_t *proPorts, const AS_t_ServiceFuncts * services);


/* ***********************************************************************
  @fn               vdyAutocodeProcess */ /*!
  @brief           VDY processing of autocode modules

  @description     Executing VDY autocode modules in the order:
                   - velocity calculation
                   - velocity monitoring
                   - switches between internal or external (corrected) velocity
                   - wheel speed yaw rate processing
                   - gyro yaw rate processing
                   - lateral acceleration yaw rate processing
                   - steering wheel yaw rate processing
                   - yaw rate fusion
                   - slip angle calculation
                   - motion state calculation

  @return          static void

  @param[in]       *reqPorts	: Request Port
  @param[in,out]   input		: Current Input Signal 
  @param[in,out]   nvdata		: NVM Data 
  @param[in,out]   *VDYErrors	: VDY Error structure 
  @param[in]       services		: Services Calls
  @param[in,out]   *proPorts	: Provide Ports

  @c_switch_part   
				  - VDY_PROFILING_ENABLED : Enables runtime measurement and profiling
				  - CFG_VDY_DIS_WHEEL_PRE_PROCESSING : Disables the wheel speed pre processing, 
																	- wheel offset estimation
																	- wheel velocity <-> puls fusion
																	- vehicle speed estimation
																	- wheel load dependancy estimation
																	- dynamic (drift) sensor yaw rate offset estimation
																	- wheel velocity yaw rate estimation
				  - CFG_VDY_USE_VELO_MONITOR : Enables monitoring of external vehicle velocity. The velocity is compared with estimated velocity based on wheel speeds 
				  - CFG_VDY_USE_EX_LONG_VELO : Use external provided longitudinal velocity signal 
				  - CFG_VDY_INT_GYRO : Enable internal yaw rate sensor processing
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation	
					- Process velocity estimation
					- Velocity monitoring (external <-> internal velocity)
					- overwrite internal velocity data if external velocity should be used and is valid
					- set the internal autocode velocity to the corrected velocity
					- Process velocity during roll bench detection
					- Process all auto code modules
						- vdy_gye
						- vdy_aye
						- vdy_sye
						- vdy_ye
						- vdy_mot_st

  
	@startuml
	start
		if (Autocode Profiling \n defined(VDY_PROFILING_ENABLED) && (VDY_PROFILING_ENABLED == 1) ) then (YES)
			:VDY_PROF_MARKER(services->pfRTAAlgoServiceAddEvent, VDY_PROF_MARKER_AUTOCODE);
		endif
		:Process velocity estimation;
		if ((!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) then (YES)
			:vdyProcAutoVelocity(input,reqPorts);
		endif
		if ((!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) then (YES)
			:vdyProcAutoVelocity(input,reqPorts);
		endif
		:Velocity monitoring (external <-> internal velocity);
		if (CFG_VDY_USE_VELO_MONITOR) then (YES)
			:vdyVelMonExec(input, &vdy_internal_data.vdy_ve_out, VDYErrors);
		endif
		:overwrite internal velocity data if external velocity should be used and is valid;
		if (CFG_VDY_USE_EX_LONG_VELO) then (YES)
            if (  (VDY_GET_IO_STATE(VDY_SIN_POS_VEHVEL_EXT, input->Signals.State) == VDY_IO_STATE_VALID) 
				||(VDY_GET_IO_STATE(VDY_SIN_POS_VEHVEL_EXT, input->Signals.State) == VDY_IO_STATE_SUBSTITUE) ) then (YES)

				:vdy_internal_data.vdy_ve_out.veh_velo =  VDYModIf.LongMot.VehVelo;
			endif
		else (NO)
			:keep the uncorrected velocity \n VDYModIf.LongMot.VehVelo = vdy_internal_data.vdy_ve_out.veh_velo;
		endif
		:set the internal autocode velocity to the corrected velocity \n vdy_internal_data.vdy_ve_out.veh_velo *= VDYModIf.LongMot.VelCorrFact;
		if ( velocity Profiling \n defined(VDY_PROFILING_ENABLED) && (VDY_PROFILING_ENABLED == 1) ) then (YES)
			:VDY_PROF_MARKER(services->pfRTAAlgoServiceAddEvent, VDY_PROF_MARKER_VELOCITY);
		endif
		:Process GYE \n vdyProcAutoSenYawRate(input);
		if ( GYE Profiling \n defined(VDY_PROFILING_ENABLED) && (VDY_PROFILING_ENABLED == 1) ) then (YES)
			:VDY_PROF_MARKER(services->pfRTAAlgoServiceAddEvent, VDY_PROF_MARKER_GYE);
		endif
		:vdy_aye modul \n vdyProcAutoLatAccelYawRate(input);
		if ( AYE Profiling  \n defined(VDY_PROFILING_ENABLED) && (VDY_PROFILING_ENABLED == 1) ) then (YES)
			:VDY_PROF_MARKER(services->pfRTAAlgoServiceAddEvent, VDY_PROF_MARKER_AYE);
		endif
		:vdy_sye modul \n VDYProcAutoSwaYawRate(input,nvdata);
		if (SYE Profiling  \n defined(VDY_PROFILING_ENABLED) && (VDY_PROFILING_ENABLED == 1) ) then (YES)
			:VDY_PROF_MARKER(services->pfRTAAlgoServiceAddEvent, VDY_PROF_MARKER_SYE);
		endif
		:vdy_ye modul \n vdyProcAutoVehicleYawRate(input);
		if (YE Profiling \n defined(VDY_PROFILING_ENABLED) && (VDY_PROFILING_ENABLED == 1) ) then (YES)
			:VDY_PROF_MARKER(services->pfRTAAlgoServiceAddEvent, VDY_PROF_MARKER_YE);
		endif
		:vdy_sae modul slip angle \n vdyProcAutoSideSlip(input);
		if (SAE Profiling \n defined(VDY_PROFILING_ENABLED) && (VDY_PROFILING_ENABLED == 1) )
			:VDY_PROF_MARKER(services->pfRTAAlgoServiceAddEvent, VDY_PROF_MARKER_SAE);
		endif
		if (vdy_mot_st modul motion state \n CFG_VDY_MOT_STATE) then (YES)
			:vdyProcMotionState(input);
		endif
		if (Motion State Profiling defined(VDY_PROFILING_ENABLED) && (VDY_PROFILING_ENABLED == 1) ) then (YES)
			:VDY_PROF_MARKER(services->pfRTAAlgoServiceAddEvent, VDY_PROF_MARKER_MOT_ST);
		endif	
	stop
	@enduml
	
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> TEST_vdyAutocodeProcess_001()
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdyAutocodeProcess(const reqVdyPrtList_t *reqPorts, VDYInputData_t * input, VDYNvData_t * nvdata, VDYErrors_t *VDYErrors, const AS_t_ServiceFuncts * services, const proVdyPrtList_t *proPorts);

#if ((!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING))
/* ***********************************************************************
  @fn               vdyProcAutoVelocity */ /*!
  @brief           VDY processing of velocity estimation autocode

  @description     Initialises wpp and ve module in INIT
                   Calls wheel speed preprocessing module wpp
                   Calls velocity and acceleration calculation module ve

  @return          static void

  @param[in,out]   input : Current Input Signal
  @param[in]       *reqPorts : Request Ports

  @c_switch_part   None 
  @c_switch_full   CFG_VDY_DIS_WHEEL_PRE_PROCESSING : Disables the wheel speed pre processing,  
                                                    - wheel offset estimation
                                                    - wheel velocity <-> puls fusion
                                                    - vehicle speed estimation
                                                    - wheel load dependancy estimation
                                                    - dynamic (drift) sensor yaw rate offset estimation
                                                    - wheel velocity yaw rate estimation
  @pre             None
  @post            No changes

  @InOutCorrelation 
					- if vdy control mode is init
						- Initialize vdy_wpp model
						- Initialize vdy_ve model
					- otherwise
						- if vdy_wpp_module is sequence initalized execute it
						- execute wheel pre processing module
						- if vdy_ve_module is sequence initalized execute it
						- execute vehicle velocity and acceleration estimation module
  
	@startuml
	start
		:Brake_t BrakeData_input;
		:BrakeData_input.ABSCtrl = reqPorts->pVehicleInputSignals->Brake.ABSCtrl;
		:BrakeData_input.TCSCtrl = reqPorts->pVehicleInputSignals->Brake.TCSCtrl;
		:BrakeData_input.State[0] = reqPorts->pVehicleInputSignals->Brake.State[0];
		:BrakeData_input.State[1] = reqPorts->pVehicleInputSignals->Brake.State[1];
		if (if vdy control mode is init \n VDY_CTRL_GET_STATE( (BaseOpMode_t)BASE_OM_RESET, input->Frame.OpMode) ) then (YES)
			:Initialize vdy_wpp model \n vdy_wpp_initialize((boolean_T) 1, &vdy_wpp_M, &vdy_wpp_B, &vdy_wpp_DWork);
			:Initialize vdy_ve model \n vdy_ve_initialize((boolean_T) 1, &vdy_ve_M, &vdy_ve_B, &vdy_ve_DWork);
		else (NO)
			if ( if vdy_wpp_module is sequence initalized execute it \n VDY_IS_MODULE_SEQU_INITALIZED((uint32)sSequenceInitState.initStates.vdy_wpp_sequ_init) == TRUE) then (YES)
				:execute wheel pre processing module \n vdy_wpp_step(&vdy_wpp_B, &vdy_wpp_DWork, input, &vdy_internal_data, &vdy_internal_data);
			endif
			if ( if vdy_ve_module is sequence initalized execute it VDY_IS_MODULE_SEQU_INITALIZED((uint32)sSequenceInitState.initStates.vdy_ve_sequ_init) == TRUE) then (YES)
				:execute vehicle velocity and acceleration estimation modul \n vdy_ve_step(&vdy_ve_B, &vdy_ve_DWork, (VDYInputData_t*)input, &vdy_internal_data, &BrakeData_input, &vdy_internal_data);
			endif
		endif		
	stop
	@enduml
	
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> TEST_vdyProcAutoVelocity_001(), TEST_vdyProcAutoVelocity_002()
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdyProcAutoVelocity(VDYInputData_t * input, const reqVdyPrtList_t *reqPorts);
#endif


/* ***********************************************************************
  @fn               vdyProcAutoWheelYawRate */ /*!
  @brief           VDY processing of wheel velocity yaw rate estimation autocode

  @description     Initialises wye module in INIT
                   Calls wheel yaw rate module wye

  @return          static void

  @param[in,out]   input : Current Input Data
  @param[in,out]   nvdata : NVM Data

  @c_switch_part   CFG_VDY_DIS_WHEEL_PRE_PROCESSING :  Disables the wheel speed pre processing, 
						- wheel offset estimation
						- wheel velocity <-> puls fusion
						- vehicle speed estimation
						- wheel load dependancy estimation
						- dynamic (drift) sensor yaw rate offset estimation
						- wheel velocity yaw rate estimation
  @c_switch_full   None 
  @pre             None
  @post            No changes
  @InOutCorrelation 
					- if wheel velocity yaw rate preprocessing is enabled
						- if vdy op mode is init do not delete learn values but init the rest
							- Store a local copy of last cycle data
							- Initialize vdy_wye model
							- copy all necessary data and old learn values to reinitialize the auto code module
						- Otherwise if vdy_wye_module is sequence initalized execute it
  
	@startuml
	start
		if ((!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) then (YES)
			if (VDY_CTRL_GET_STATE( (BaseOpMode_t)BASE_OM_RESET, input->Frame.OpMode) ) then (YES)
				:local copy of last cycle data;
				:uint8 init_nvm_wld_delay_DSTATE = vdy_wye_DWork.init_nvm_wld_delay_DSTATE;
				:float32 x_delay_wld_DSTATE = vdy_wye_DWork.x_delay_wld_DSTATE[VDY_TWO];
				:float32 last_est_wld_DSTATE = vdy_wye_DWork.last_est_wld_DSTATE;
				:float32 x_delay_dyn_off_DSTATE = vdy_wye_DWork.x_delay_dyn_off_DSTATE[VDY_TWO];
				:sint8 last_dyn_yaw_offset_sign_DSTATE = vdy_wye_DWork.last_dyn_yaw_offset_sign_DSTATE;
				:float32 dyn_yaw_off_overt_count_DSTATE = vdy_wye_DWork.dyn_yaw_off_overt_count_DSTATE;
				:float32 last_dyn_yaw_offset_DSTATE = vdy_wye_DWork.last_dyn_yaw_offset_DSTATE;   
				:Initialize vdy_wye model \n vdy_wye_initialize((boolean_T) 1, &vdy_wye_M, &vdy_wye_B, &vdy_wye_DWork);
				:copy all necessary data and old learn values to reinitialize the auto code module;
				:vdy_wye_DWork.init_nvm_wld_delay_DSTATE = init_nvm_wld_delay_DSTATE;
				:vdy_wye_DWork.x_delay_wld_DSTATE[VDY_TWO] = x_delay_wld_DSTATE;
				:vdy_wye_DWork.last_est_wld_DSTATE = last_est_wld_DSTATE;
				:vdy_wye_DWork.x_delay_dyn_off_DSTATE[VDY_TWO] = x_delay_dyn_off_DSTATE;
				:vdy_wye_DWork.last_dyn_yaw_offset_sign_DSTATE = last_dyn_yaw_offset_sign_DSTATE;
				:vdy_wye_DWork.dyn_yaw_off_overt_count_DSTATE = dyn_yaw_off_overt_count_DSTATE;
				:vdy_wye_DWork.last_dyn_yaw_offset_DSTATE = last_dyn_yaw_offset_DSTATE;
			else (NO)
				if ( if vdy_wye_module is sequence initalized execute it \n VDY_IS_MODULE_SEQU_INITALIZED((uint32)sSequenceInitState.initStates.vdy_wye_sequ_init) == TRUE) then (YES)
					:at running mode \n vdy_wye_step(&vdy_wye_B, &vdy_wye_DWork, input, &vdy_internal_data, (VDYNvData_t*)nvdata, &vdy_internal_data, (VDYNvData_t*)nvdata);
				endif
			endif				 
		else (NO)
			:set the wheel yaw rate modul to invalid variances;
			:vdy_internal_data.vdy_wye_out.whl_yaw_rate = 0.0F;
			:vdy_internal_data.vdy_wye_out.whl_yaw_rate_var = 100.0F;
			:vdy_internal_data.vdy_wye_out.gier_yaw_rate_offset = vdy_internal_data.vdy_offsets_in.vdy_yaw_offset.offset;
			:vdy_internal_data.vdy_wye_out.gier_yaw_rate_offset_var = vdy_internal_data.vdy_offsets_in.vdy_yaw_offset.var;
			:vdy_internal_data.vdy_wye_out.raw_est_yaw_offset = 0.0F;
		endif
		
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> TEST_vdyProcAutoWheelYawRate_001(), TEST_vdyProcAutoWheelYawRate_002()
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdyProcAutoWheelYawRate(VDYInputData_t * input, VDYNvData_t * nvdata);

#if (!CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING)
#if (CFG_VDY_INT_GYRO)
/* ***********************************************************************
  @fn               vdyProcAutoSenIntYawRateOffset */ /*!
  @brief           VDY processing of sensor internal yaw rate offset

  @description     Dynamic yaw rate handling if internal yaw rate sensor is used

  @return          static void

  @glob_in         None
  @glob_out        OldFiltYawOffset : Filter delay for yaw rate offset  

  @pre             None
  @post            No changes
  @InOutCorrelation	
  - CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING : Disables the alignment yaw rate offset pre filtering, 
		- yaw rate from yaw rate sensor with filtered offset estimation
  - CFG_VDY_INT_GYRO : Enable internal yaw rate sensor processing
  
  @testmethod			  - NA
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdyProcAutoSenIntYawRateOffset(void);
#endif


/* ***********************************************************************
  @fn               vdyProcAutoSenExtYawRateOffset */ /*!
  @brief           VDY processing of sensor internal yaw rate offset

  @description     Dynamic yaw rate handling if external yaw rate sensor is used

  @return          static void

  @glob_in         None
  @glob_out        OldFiltYawOffset : Filter delay for yaw rate offset

  @c_switch_part   None 
  @c_switch_full   None

  @pre             None
  @post            No changes
  @InOutCorrelation	
				  - reset dyn yaw rate offset filter if stand still
				  - applies low pass filter raw yaw offset
  
	@startuml
	start
		:const VDYYwrOffsData_t *pYwrOffs = vdyYwrGetOffsData();
		if ( reset dyn yaw rate offset filter if stand still \n ( (pYwrOffs->OffsElpsdTime < VDY_ONE_F) && 
			(pYwrOffs->OffsType == (VDYYwrOffsType_t) OFFS_STANDST) ) || (pYwrOffs->OffsType==(VDYYwrOffsType_t) OFFS_STANDST_EEPROM) ) then (YES)
			:OldFiltYawOffset = vdy_internal_data.vdy_wye_out.raw_est_yaw_offset;
		else (NO)
			:OldFiltYawOffset = vdy_internal_data.vdy_gye_out_filt.raw_est_yaw_offset_filt;
		endif
		:low pass filter raw yaw offset \n 
			vdy_internal_data.vdy_gye_out_filt.raw_est_yaw_offset_filt = vdyFilterCycleTime( vdy_internal_data.vdy_wye_out.raw_est_yaw_offset, OldFiltYawOffset, VDY_PAR_RAW_YAW_RATE_OFFSET_FT);
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> \n
                            TEST_vdyProcAutoSenExtYawRateOffset_001(), \n
                            TEST_vdyProcAutoSenExtYawRateOffset_002(), \n
                            TEST_vdyProcAutoSenExtYawRateOffset_003(), \n
                            TEST_vdyProcAutoSenExtYawRateOffset_004()
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdyProcAutoSenExtYawRateOffset(void);
#endif


/* ***********************************************************************
  @fn               vdyProcAutoSenYawRate */ /*!
  @brief           VDY processing of sensor yaw rate estimation autocode

  @description     Initialises gye module in INIT
                   Calls gyro yaw rate module gye

  @return          static void

  @param[in,out]   input : Current Input Signal

  @c_switch_part   
				  - CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING : Disables the sensor yaw rate pre processing, 
																		 - static (stand still)yaw rate offset
																		 - yaw rate from yaw rate sensor estimation
				  - CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING : Disables the alignment yaw rate offset pre filtering, 
																			 - yaw rate from yaw rate sensor with filtered offset estimation
				  - CFG_VDY_INT_GYRO : Enable internal yaw rate sensor processing 
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation 
					- if sensor yaw rate pre processing is enabled
						- if vdy control mode is init
							- Initialize vdy_gye model filt
							- Initialize vdy_gye model
						- Otherwise
							- if vdy_gye_module is sequence initalized execute it
							- if sensor yaw rate offset should be prefilterd for alignment
							- store not filterd yaw rate offset
						- reset and low pass filter external yaw rate dynamic offset
						- copy filterd yaw rate offset to gier_yaw_rate_offset as input for alignment gier sensor yaw rate
						- calculate gier yaw rate with filtered raw yaw rate offset
						- copy sensor yaw rate with filtered raw estimated gier yaw rate offset to seperate struct
						- restore original not filtered yaw rate offset
						- calculate gier yaw rate with discrete yaw rate offset
  
	@startuml
	start
		if (if sensor yaw rate pre processing is enabled \n  (!defined(CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING) ) then (YES)
			if (VDY_CTRL_GET_STATE( (BaseOpMode_t)BASE_OM_RESET, input->Frame.OpMode) ) then (YES)
				if (!CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING) then (YES)
					:Initialize vdy_gye model filt \n vdy_gye_initialize((boolean_T) 1, &vdy_gye_M_FILT, &vdy_gye_B_FILT, &vdy_gye_DWork_FILT);
				endif
				:Initialize vdy_gye model \n vdy_gye_initialize((boolean_T) 1, &vdy_gye_M, &vdy_gye_B, &vdy_gye_DWork);
			else (NO)
				if ( if vdy_gye_module is sequence initalized execute it \n VDY_IS_MODULE_SEQU_INITALIZED((uint32)sSequenceInitState.initStates.vdy_gye_sequ_init) == TRUE) then (YES)
					if (if sensor yaw rate offset should be prefilterd for alignment \n !CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING) then (YES) 
						:store not filterd yaw rate offset \n fYawRate_t NotFiltYawOffset = vdy_internal_data.vdy_wye_out.gier_yaw_rate_offset;
						if (CFG_VDY_INT_GYRO) then (YES)
							if (VDY_GET_IO_STATE(VDY_SIN_POS_YWR, input->Signals.State) == VDY_IO_STATE_VALID) then (YES)
								:reset and low pass filter external yaw rate dynamic offset \n vdyProcAutoSenExtYawRateOffset();
							else
								:reset and low pass filter internal yaw rate dynamic offset \n vdyProcAutoSenIntYawRateOffset();
							endif
						else (NO)
							:reset and low pass filter external yaw rate dynamic offset \n vdyProcAutoSenExtYawRateOffset();
						endif
						:copy filterd yaw rate offset to gier_yaw_rate_offset as input for alignment gier sensor yaw rate \n vdy_internal_data.vdy_wye_out.gier_yaw_rate_offset = vdy_internal_data.vdy_gye_out_filt.raw_est_yaw_offset_filt;
						:calculate gier yaw rate with filtered raw yaw rate offset \N vdy_gye_step(&vdy_gye_B_FILT,&vdy_gye_DWork_FILT, input, &vdy_internal_data, &vdy_internal_data);
						:copy sensor yaw rate with filtered raw estimated gier yaw rate offset to seperate struct \n vdy_internal_data.vdy_gye_out_filt.gier_yaw_rate = vdy_internal_data.vdy_gye_out.gier_yaw_rate \n vdy_internal_data.vdy_gye_out_filt.gier_yaw_rate_var = vdy_internal_data.vdy_gye_out.gier_yaw_rate_var;
						:restore original not filtered yaw rate offset \n vdy_internal_data.vdy_wye_out.gier_yaw_rate_offset = NotFiltYawOffset;
					else (NO)
						:set filtered offset to not filtered raw offset \n vdy_internal_data.vdy_gye_out_filt.raw_est_yaw_offset_filt = vdy_internal_data.vdy_wye_out.raw_est_yaw_offset;
					endif
					:calculate gier yaw rate with discrete yaw rate offset \n vdy_gye_step(&vdy_gye_B,&vdy_gye_DWork, (VDYInputData_t*)input, &vdy_internal_data, &vdy_internal_data);
				endif
				if (!CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING) then (YES)
				else (NO)
					:copy sensor yaw rate with NOT filtered raw estimated gier yaw rate offset to seperate struct;
					:vdy_internal_data.vdy_gye_out_filt.gier_yaw_rate = vdy_internal_data.vdy_gye_out.gier_yaw_rate;
					:vdy_internal_data.vdy_gye_out_filt.gier_yaw_rate_var = vdy_internal_data.vdy_gye_out.gier_yaw_rate_var;
				endif
			endif		
		else (NO)
			:set internal sensor yaw rate data to default values \n vdy_internal_data.vdy_gye_out.gier_yaw_rate     = 0.0F \n vdy_internal_data.vdy_gye_out.gier_yaw_rate_var = 100.0F;		
		endif
	
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> TEST_vdyProcAutoSenYawRate_001(), TEST_vdyProcAutoSenYawRate_002()
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdyProcAutoSenYawRate(VDYInputData_t * input);


/* ***********************************************************************
  @fn               vdyProcAutoLatAccelYawRate */ /*!
  @brief           VDY processing of lateral acceleration yaw rate estimation autocode

  @description     Initialises aye module in INIT
                   Calls lat accel yaw rate module aye

  @return          static void

  @param[in,out]   input : Current Input Signal

  @c_switch_part   CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING : Disables the lateral acceleration sensor pre processing, 
                                                                - lateral sensor offset estimation
                                                                - yaw rate from lateral acceleration sensor estimation 
  @c_switch_full   None

  @pre             None
  @post            No changes
  @InOutCorrelation	
					- If lateral acceleration sensor pre processing is enabled
						- if vdy control mode is init
							- Initialize vdy_ay model
						- if vdy_aye_module is sequence initalized execute it
  
	@startuml
	start
		if (lateral acceleration sensor pre processing is enabled \n (!defined(CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING)) then (YES)
			if (vdy control mode is init \n VDY_CTRL_GET_STATE( (BaseOpMode_t)BASE_OM_RESET, input->Frame.OpMode) ) then (YES)
				:Initialize vdy_ay model \n vdy_aye_initialize((boolean_T) 1, &vdy_aye_M, &vdy_aye_DWork);
			else (NO)
				if (vdy_aye_module is sequence initalized execute it \n VDY_IS_MODULE_SEQU_INITALIZED((uint32)sSequenceInitState.initStates.vdy_aye_sequ_init) == TRUE)
					:vdy_aye_step(&vdy_aye_DWork, input, &vdy_internal_data, &vdy_internal_data);
				endif
			endif		
		else (NO)
			:set internal lateral accel yaw rate data to default values \n vdy_internal_data.vdy_aye_out.ay_yaw_rate     = 0.0F \n vdy_internal_data.vdy_aye_out.ay_yaw_rate_var = 100.0F;
		endif	
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> TEST_vdyProcAutoLatAccelYawRate_001(), TEST_vdyProcAutoLatAccelYawRate_002()
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdyProcAutoLatAccelYawRate(VDYInputData_t * input);


/* ***********************************************************************
  @fn               vdyProcAutoSwaYawRate */ /*!
  @brief           VDY processing of steering wheel angle yaw rate estimation autocode

  @description     Initialises sye module in INIT
                   Calls steering wheel yaw rate module sye

  @return          static void

  @param[in,out]   input : Current Input Signal
  @param[in,out]   nvdata : NVM Data

  @glob_in         None ? : Global input used in this function
  @glob_out        None ? : Global output filled in this function

  @c_switch_part   CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING : Disables the steering wheel angle sensor pre processing, 
                                                                - steering wheel angle sensor offset estimation
                                                                - estimation of self steering gradient
                                                                - driver intended curvature
                                                                - yaw rate from steering wheel sensor estimation
  @c_switch_full   None

  @pre             None
  @post            No changes
  @InOutCorrelation	
					- If steering wheel angle sensor pre processing is enabled
						- if vdy control mode is init
							- store a local copy of last cycle data
							- Initialize vdy_sye model
							- copy all necessary data and old learn values to reinitialize the auto code module
						- if vdy_sye_module is sequence initalized execute it
  
	@startuml
	start
		if (If steering wheel angle sensor pre processing is enabled  \n (!defined(CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING)) then (YES)
			if (VDY_CTRL_GET_STATE( (BaseOpMode_t)BASE_OM_RESET, input->Frame.OpMode) ) then (YES)
				:local copy of last cycle data \n uint8 init_nvm_eg_delay_DSTATE = vdy_sye_DWork.init_nvm_eg_delay_DSTATE \n float32 x_delay_eg_DSTATE = vdy_sye_DWork.x_delay_eg_DSTATE[VDY_TWO];
				:Initialize vdy_sye model \n vdy_sye_initialize((boolean_T) 1, &vdy_sye_M, &vdy_sye_B, &vdy_sye_DWork);
				:copy all necessary data and old learn values to reinitialize the auto code module \n vdy_sye_DWork.init_nvm_eg_delay_DSTATE = init_nvm_eg_delay_DSTATE \n vdy_sye_DWork.x_delay_eg_DSTATE[VDY_TWO] = x_delay_eg_DSTATE;
			else (NO)
				if ( if vdy_sye_module is sequence initalized execute it \n VDY_IS_MODULE_SEQU_INITALIZED((uint32)sSequenceInitState.initStates.vdy_sye_sequ_init) == TRUE) then (YES)
					:vdy_sye_step(&vdy_sye_B, &vdy_sye_DWork, input, &vdy_internal_data ,(VDYNvData_t*)nvdata ,(uint8)input->Frame.OpMode, &vdy_internal_data, (VDYNvData_t*)nvdata);
				endif
			endif
		else (NO)
			:set internal steering wheel angle yaw rate data to default values;
			:vdy_internal_data.vdy_sye_out.stw_yaw_rate     = 0.0F;
			:vdy_internal_data.vdy_sye_out.stw_yaw_rate_var = 100.0F;
			:vdy_internal_data.vdy_sye_out.stw_curve        = 0.0F;
			:vdy_internal_data.vdy_sye_out.stw_curve_var    = 100.0F;
		endif	
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> TEST_vdyProcAutoSwaYawRate_001(), TEST_vdyProcAutoSwaYawRate_002()
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdyProcAutoSwaYawRate(VDYInputData_t * input, VDYNvData_t * nvdata);


/* ***********************************************************************
  @fn               vdyProcAutoVehicleYawRate */ /*!
  @brief           VDY processing of vehicle angle yaw rate fusion estimation autocode

  @description     Initialises ye module in INIT
                   Calls yaw rate fusion module ye

  @return          static void

  @param[in,out]   input : Current Input Data

  @c_switch_part   CFG_VDY_USE_EXT_PROC_YAW_RATE : Enables usage of external yaw rate as vdy output yaw rate
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation	
					- If external yaw rate sensor processing
						- if vdy control mode is init
							- Initialize vdy_ve model
						- if vdy_ye_module is sequence initalized execute it
  
	@startuml
	start
		if ( If external yaw rate sensor processing (!defined(CFG_VDY_USE_EXT_PROC_YAW_RATE)) || (!CFG_VDY_USE_EXT_PROC_YAW_RATE) ) then (YES)
			if (VDY_CTRL_GET_STATE( (BaseOpMode_t)BASE_OM_RESET, input->Frame.OpMode) ) then (YES)
				:Initialize vdy_ve model \n vdy_ye_initialize((boolean_T) 1, &vdy_ye_M, &vdy_ye_B, &vdy_ye_DWork);
			else (NO)
				if (if vdy_ye_module is sequence initalized execute it \n VDY_IS_MODULE_SEQU_INITALIZED((uint32)sSequenceInitState.initStates.vdy_ye_sequ_init) == TRUE) then (YES)
					:vdy_ye_step(&vdy_ye_B, &vdy_ye_DWork, input, &vdy_internal_data, &vdy_internal_data, vdy_ye_k.K_yaw, &vdy_ye_k.K_yaw_fault, vdy_ye_k.K_curve, &vdy_ye_k.K_curve_fault);
					if ((vdy_ye_k.K_yaw_fault == 1U) || (vdy_ye_k.K_curve_fault == 1U)) then (YES)
						:Initialize vdy_ye model \n vdy_ye_initialize((boolean_T) 1, &vdy_ye_M, &vdy_ye_B, &vdy_ye_DWork);
					endif
				endif
			endif				
		else (NO)
			if (calculate the curve manually, if not filtered \n CML_f_IsZero(vdy_internal_data.vdy_ve_out.veh_velo)) then (YES)
				:vdy_internal_data.vdy_ye_out.veh_merge_curve = 0.0F;
			else (NO)
				:vdy_internal_data.vdy_ye_out.veh_merge_curve = input->Signals.YawRate/vdy_internal_data.vdy_ve_out.veh_velo;
			endif
			:vdy_internal_data.vdy_ye_out.veh_merge_curve_grad = 0.0F;
			:vdy_internal_data.vdy_ye_out.veh_merge_curve_var  = 0.0F;			
		endif
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> TEST_vdyProcAutoVehicleYawRate_001()
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdyProcAutoVehicleYawRate(VDYInputData_t * input);


/* ***********************************************************************
  @fn               vdyProcAutoSideSlip */ /*!
  @brief           VDY processing of side slip angle estimation autocode

  @description     Initialises sae module in INIT
                   Calls side slip angle module sae

  @return          static void

  @param[in,out]   input : Current Input Signal

  @c_switch_part   CFG_VDY_DIS_SIDE_SLIP_ANGLE_ESTIMATION : Disables the side slip angle estimation
  @c_switch_full   None

  @pre             None
  @post            No changes
  @InOutCorrelation	
					- If side slip angle processing is enabled
						- if vdy control mode is init
							- Initialize vdy_sae model
						- if vdy_sae module is sequence initalized execute it
  			
	@startuml
	start
		if (If side slip angle processing is enabled \n (!defined(CFG_VDY_DIS_SIDE_SLIP_ANGLE_ESTIMATION)) || (!CFG_VDY_DIS_SIDE_SLIP_ANGLE_ESTIMATION)) then (YES)
			if (VDY_CTRL_GET_STATE((VDYCtrlState_t)VDY_CTRL_STATE_INIT, input->Frame.CtrlMode)) then (YES)
				:Initialize vdy_sae model \n vdy_sae_initialize((boolean_T) 1, &vdy_sae_M, &vdy_sae_DWork);
			else
				if (if vdy_sae_module is sequence initalized execute it \n VDY_IS_MODULE_SEQU_INITALIZED(sSequenceInitState.initStates.vdy_sae_sequ_init) == TRUE) then (YES)
					:vdy_sae_step(&vdy_sae_DWork, (VDYInputData_t*)input, &vdy_internal_data, &vdy_internal_data);
				endif
			endif
		else (NO)
			:set internal side slip angle data to default values \n vdy_internal_data.vdy_sae_out.est_slip_angle     = VDY_ZERO_F \n vdy_internal_data.vdy_sae_out.est_slip_angle_var = VDY_HUNDRED_F;
		endif
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> TEST_vdyProcAutoSideSlip_001()
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdyProcAutoSideSlip(VDYInputData_t * input);


#if (CFG_VDY_MOT_STATE)
#if (CFG_VDY_MFC)
/* ***********************************************************************
  @fn               vdyProcMotionState */ /*!
  @brief           VDY processing of motion state estimation autocode

  @description     Initialises mot_st module in INIT
                   Calls motion state determination module mot_st

  @return          static void

  @param[in,out]   input : 

  @c_switch_part   None 
  @c_switch_full   CFG_VDY_MOT_STATE : Enable motion state processing

  @pre             None
  @post            No changes
  @InOutCorrelation	
			- If motion state processing is enabled
				- if vdy control mode is init
					- Initialize vdy_mot_st model
				- if vdy_mot_state_module is sequence initalized execute it
  
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> TEST_vdyProcMotionState_001(), TEST_vdyProcMotionState_002()
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdyProcMotionState(VDYInputData_t * input);
#else
STATIC_MTD void vdyProcMotionState(VDYInputData_t * input, ALN_Monitoring_t * ALNMonitoring, const proVdyPrtList_t *proPorts);
#endif
#endif


/* ***********************************************************************
  @fn               vdyPostProcess */ /*!
  @brief           VDY post processing copy output to the rte output structs

  @description     Distributes internally calculated data to output ports
                   Maps yaw rate offset state to output state and quality
                   Calls yaw rate to curves conversion
                   Calls functional safety monitors

  @return          static void

  @param[in]       *reqPorts : requested ports
  @param[in]       input : signals
  @param[in]       *VDYNvData : learn values
  @param[in,out]   *proPorts : provided ports

  @glob_in         VDYModIf : Component internal intra module interface
  @glob_out        None 

  @c_switch_part   
					  - CFG_VDY_DIS_YWR_OFFSET_COMP : Disables zero point offset compensation of input yaw rate signal
					  - CFG_VDY_INT_GYRO : Enable internal yaw rate sensor processing 
					  - CFG_VDY_DIS_CURVE_OUTPUT : Disable the additional VDY curve output 
					  - CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING : Disables the steering wheel angle sensor pre processing, 
																					- steering wheel angle sensor offset estimation
																					- estimation of self steering gradient
																					- driver intended curvature
																					- yaw rate from steering wheel sensor estimation 
					  - CFG_VDY_DIS_YAW_SENSOR_OUTPUT : Disables the alignment yaw rate output,
																	  - yaw rate from yaw rate sensor with filtered offset estimation
					  - CFG_VDY_DO_VELOCITY_CORR : Enables the velocity correction
					  - CFG_VDY_ALIGNMENT_OFFSET_MONITOR : Do yaw rate offset monitoring with alignment offset estimation input
					  - CFG_VDY_DIS_FUNCTIONAL_SAFETY_MON : Disable functional safety monitoring
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation 
					- Get the stand still yaw rate offset 
					- Convert yaw rates for diag and mts purpose
					- output curvature, yaw rate, lateral acceleration, driver intended curve
					- output velocity and acceleration variables
					- output vehicle motion state
					- Generate qualitys for sensor yaw rate, vehicle yaw rate and vehicle curve
					- VDY should write this VersionNumber _EVERY_ time in "VDYExec()" when writing VDYOffsets to MDB
					- output yaw rate swa and ay offsets
					- In case of normal state set first cycle done flag; Set flag to indicate that first cycle execution is completed
					- Monitor the vdy output signals for physical range only if the vdy is in running mode
					- call Functional safety monitoring functions
					- BankRoadAngle Calculation
						-   RoadBankAngle = track_bent;
						-	SelfSteerGradEst = stw_understeer_grad;  
								- when YawRate & Ay States are Valid and gier_yaw_rate_var is less than VDY_YAWRATE_MAX_VARIANCE
									- and r_On_Off_control is 1(If Ay offset state > 1), Set QuRoadBankAngle  to 1;
									- and r_On_Off_control is 2(If Ay offset state <= 1) Set QuRoadBankAngle to 0.5;
									- otherwise set to 0;
								- Otherwise Set QuRoadBankAngle to 0.0;  
						- when YawRate & Ay States are Valid or decreased and when swa ration and wheel base parameter states are valid 
						- then set QuSelfSteerGradEst to 1.0 and set self steering output state to valid
						- otherwise set QuSelfSteerGradEst to 0.0 and set self steering output state to invalid
  
    @startuml
	start
		:Get the stand still yaw rate offset;
		:Convert yaw rates for diag and mts purpose;
		:output curvature, yaw rate, lateral acceleration, driver intended curve;
		:output velocity and acceleration variables;
		:output vehicle motion state;
		:Generate qualitys for sensor yaw rate, vehicle yaw rate and vehicle curve;
		:VDY should write this VersionNumber _EVERY_ time in "VDYExec()" when writing VDYOffsets to MDB;
		:output yaw rate swa and ay offsets;
		:In case of normal state set first cycle done flag; Set flag to indicate that first cycle execution is completed;
		:Monitor the vdy output signals for physical range only if the vdy is in running mode;
		:call Functional safety monitoring functions;
		:RoadBankAngle = track_bent;
		:SelfSteerGradEst = stw_understeer_grad;
		if (when YawRate & Ay States are Valid and gier_yaw_rate_var is less than VDY_YAWRATE_MAX_VARIANCE ) then (YES)
			if (r_On_Off_control is 1(If Ay offset state > 1)) then (YES)
				:Set QuRoadBankAngle  to 1;
				if (r_On_Off_control is 2(If Ay offset state <= 1)) then (YES)
					:Set QuRoadBankAngle to 0.5;
				else (NO)
					:otherwise set to 0;
				endif
			else (NO)
				:Set QuRoadBankAngle to 0.0;  
			endif 
			if (YawRate & Ay States are Valid or decreased and when swa ration and wheel base parameter states are valid ) then (YES)
				:set QuSelfSteerGradEst to 1.0 and set self steering output state to valid;
				:set QuSelfSteerGradEst to 0.0 and set self steering output state to invalid;
			endif			
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> \n
                            TEST_vdyPostProcess_001(), \n
                            TEST_vdyPostProcess_002(), \n
                            TEST_vdyPostProcess_003(), \n
                            TEST_vdyPostProcess_004(), \n
                            TEST_vdyPostProcess_005(), \n
                            TEST_vdyPostProcess_006(), \n
                            TEST_vdyPostProcess_007(), \n
                            TEST_vdyPostProcess_008(), \n
                            TEST_vdyPostProcess_009(), \n
                            TEST_vdyPostProcess_010(), \n
                            TEST_vdyPostProcess_011(), \n
                            TEST_vdyPostProcess_012(), \n
                            TEST_vdyPostProcess_013(), \n
                            TEST_vdyPostProcess_014(), \n
                            TEST_vdyPostProcess_015(), \n
                            TEST_vdyPostProcess_016(), \n
                            TEST_vdyPostProcess_017(), \n
                            TEST_vdyPostProcess_018(), \n
                            TEST_vdyPostProcess_019(), \n
                            TEST_vdyPostProcess_020(), \n
                            TEST_vdyPostProcess_021(), \n
                            TEST_vdyPostProcess_022(), \n
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdyPostProcess(const reqVdyPrtList_t *reqPorts, const VDYInputData_t * input, const VDYNvData_t *VDYNvData, proVdyPrtList_t *proPorts);


/* ***********************************************************************
  @fn               vdyEnvMeasFreezeInternal */ /*!
  @brief           Transfer internal component data to acquisition

  @description     Sends all internal meas freezes

  @return          static void

  @param[in]       services : Service Calls
  @param[in]       *VDYIn : VDY Input Data

  @c_switch_part   
					  - CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING : Disables the sensor yaw rate pre processing, 
																			  - static (stand still)yaw rate offset
																			  - yaw rate from yaw rate sensor estimation   
					  - CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING : Disables the steering wheel angle sensor pre processing, 
																					- steering wheel angle sensor offset estimation
																					- estimation of self steering gradient
																					- driver intended curvature
																					- yaw rate from steering wheel sensor estimation   
					  - CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING : Disables the lateral acceleration sensor pre processing, 
																					- lateral sensor offset estimation
																					- yaw rate from lateral acceleration sensor estimation 
					  - CFG_VDY_DIS_WHEEL_PRE_PROCESSING : Disables the wheel speed pre processing, 
																		- wheel offset estimation
																		- wheel velocity <-> puls fusion
																		- vehicle speed estimation
																		- wheel load dependancy estimation
																		- dynamic (drift) sensor yaw rate offset estimation
																		- wheel velocity yaw rate estimation
					  - CFG_VDY_INT_GYRO : Enable internal yaw rate sensor processing   
					  - CFG_VDY_USE_VELO_MONITOR : Enables monitoring of external vehicle velocity. The velocity is compared with estimated velocity based on wheel speeds    
					  - AS_SERVICEFUNC_VERSION : Servicefunctions version  
					  - CFG_VDY_YWR_OFFSET_MONITOR : Enables monitoring of yaw rate at vehicle-stop, during vehicle-stop and vehicle drive-off. During this driving
																	conditions zero point offset is roughly observeable. Exceedance of limits are indicated by error events
					  - CFG_VDY_DO_VELOCITY_CORR : Enables the velocity correction 
					  - CFG_VDY_FS_VELO_CORR_MON : Enables the fast velocity to stationary targets monitor  
					  - CFG_VDY_DIS_FUNCTIONAL_SAFETY_MON : Disable functional safety monitoring
					  - VDY_FREEZE_INIT_SEQUENCE : Init sequence meas freeze
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation	
  - Fetch the vdy configuration
  - Freeze component internal data groups
  - MeaseFreeze the synchronization data for MTS/simulation.
  
	@startuml
	start
		if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING) ) then (YES)
			:VDYYwrData_t    *pYwrData  = vdyYwrGetPrivateData();
		endif
		if ( (!defined(CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING) ) then (YES)
			:VDYSwaData_t    *pSwaData  = vdySwaGetPrivateData();
		endif
		if ( (!defined(CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING) ) then (YES)
			:VDYAyData_t     *pAyData   = vdyAyGetPrivateData();
		endif
		if ( (!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING) ) then (YES)
			:VDYWhsData_t    *pWhsData  = vdyWhsGetPrivateData();
		endif
		if (CFG_VDY_INT_GYRO)
			:VDYYwrtData_t   *pYwrtData = VDYYwrtGetPrivateData();
		endif
		:Fetch the vdy configuration \n vdyGetConfig();
		:Freeze component internal data groups;
		if ( (!defined(CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING) ) then (YES)
			:MEAS_FREEZE_DIRECT(VDY_MEAS_ID_SWA, pSwaData, sizeof(VDYSwaData_t)); 
		endif
		if ( (!defined(CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING) ) then (YES)
			:MEAS_FREEZE_DIRECT(VDY_MEAS_ID_AY,  pAyData,  sizeof(VDYAyData_t)); 
		endif
		if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING) )
			:MEAS_FREEZE_DIRECT(VDY_MEAS_ID_YWR, pYwrData, sizeof(VDYYwrData_t)); 
		endif
		if (CFG_VDY_INT_GYRO)
			:MEAS_FREEZE_DIRECT(VDY_MEAS_ID_YWRT, pYwrtData, sizeof(VDYYwrtData_t)); 
		endif
		if ( (!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING) ) then (YES)
			:MEAS_FREEZE_DIRECT(VDY_MEAS_ID_WHS, pWhsData, sizeof(VDYWhsData_t));
		endif
		:MEAS_FREEZE_DIRECT(VDY_MEAS_ID_INTDATA,   &vdy_internal_data, sizeof(vdy_internal_data));
		:MEAS_FREEZE_DIRECT(VDY_MEAS_ID_BAYESDATA, &vdy_bayes_mot_states, sizeof(vdy_bayes_mot_states));
		if (!(defined(CFG_VDY_DIS_FUNCTIONAL_SAFETY_MON) && (CFG_VDY_DIS_FUNCTIONAL_SAFETY_MON))) then (YES)
			:VDYFSData_t * VDYFsData = vdyFSMonGetPrivateData();
			:MEAS_FREEZE_DIRECT(VDY_MEAS_ID_FS_MON,   VDYFsData, sizeof(VDYFSData_t)); 
		endif
		:MEAS_FREEZE_DIRECT(VDY_MEAS_ID_YE_K, &vdy_ye_k, sizeof(VDYYe_K_t)); 
		:MEAS_FREEZE_DIRECT(VDY_MEAS_ID_TIMESTAMPS, &VDYDeltaTimeStamp, sizeof(VDYDeltaTimeStamp_t));
		if ( defined(VDY_FREEZE_INIT_SEQUENCE) && (VDY_FREEZE_INIT_SEQUENCE) )
			:vdyInitSequenceMeasFreeze(services);
		endif
			:MEAS_FREEZE_DIRECT(VDY_MEAS_ID_SYNC_REF, &(s_SyncRef), sizeof(VDY_SM_t_SyncRef));
		:return;	
	stop
	@enduml
  @testmethod			  - NA
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdyEnvMeasFreezeInternal(const AS_t_ServiceFuncts * services, VDYInputData_t *VDYIn);


#if ((!CFG_VDY_DIS_YWR_OFFSET_COMP) && ((!defined(CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING)))
#if (CFG_VDY_INT_GYRO)
STATIC_MTD fQuality_t vdyGenInternalYawRateQuality(const VDYInternalData_t *IntData, const proVdyPrtList_t *proPorts, const VDYInputData_t *input );
#endif


#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING)) || (!CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING) )
/* ***********************************************************************
  @fn               vdyGenExternalYawRateQuality */ /*!
  @brief           Generate qualitys for External yaw rate sensor

  @description     Takes interally calculated quality and reduces the quality
                   with difference between last filtered yaw rate and stand still offset
                   Sets the aln yaw rate offset compensation stat according
                   to the yaw rate offset state

  @return          static fQuality_t

 */
#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING)) || (!CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING) )
/*!
  @param[in]       *IntData : IntData yaw sensor data
*/
#endif
/*!

  @param[in]       *proPorts : proPorts output quality
  @param[in]       *input : input yaw rate signal state

  @glob_in         LastFiltered : Last filtered dyn yaw rate offset
  @glob_out        LastFiltered : Last filtered dyn yaw rate offset

  @c_switch_part   
				  - CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING : Disables the alignment yaw rate offset pre filtering, 
																			 - yaw rate from yaw rate sensor with filtered offset estimation 
				  - CFG_VDY_DIS_YAW_SENSOR_OUTPUT : Disables the alignment yaw rate output,
																 - yaw rate from yaw rate sensor with filtered offset estimation
  @c_switch_full   None

  @pre             None
  @post            No changes
  @InOutCorrelation 
		- Takes interally calculated quality and reduces the quality with difference between last filtered yaw rate and stand still offset 
  
	@startuml
	start
		:If external yaw sensor is used \n const VDYYwrOffsData_t *pYwrOffs = vdyYwrGetOffsData();
		:static fQuality_t TempVehSensorYawRateQuality = VDY_ZERO_F;
		if (!CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING) then (YES)
			:Reduce sensor yaw rate quality with difference between raw yaw rate offset and filtered yaw rate offset \n if the diff is 0.01rad the reduce Quality is 0.5 -> (Quality = 0.05*diff[mrad]) \n
			fYawRate_t ReduceQuality = CML_f_Abs(IntData->vdy_wye_out.raw_est_yaw_offset-IntData->vdy_gye_out_filt.raw_est_yaw_offset_filt) * VDY_FIFTY_F \n
			boolean b_ReduceQualityIsNonYero = (boolean)(CML_f_IsNonZero(ReduceQuality) ? TRUE : FALSE) \n 
			boolean b_LastFilteredIsZero = (boolean)(CML_f_IsZero(LastFiltered) ? TRUE : FALSE);
			if (Reduce sensor yaw rate with difference between last filtered yaw rate and stand still offset at stand still \n (b_ReduceQualityIsNonYero == (boolean)TRUE) || (b_LastFilteredIsZero == (boolean)TRUE)) then (YES)
				:LastFiltered = IntData->vdy_gye_out_filt.raw_est_yaw_offset_filt;
			else
				if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_OUTPUT)) || (!CFG_VDY_DIS_YAW_SENSOR_OUTPUT) ) then (YES)
					:The difference between the current filtered dyn offset and the last filtered last dyn offset \n ReduceQuality += CML_f_Abs(IntData->vdy_wye_out.raw_est_yaw_offset-LastFiltered)*50.0F;
				endif
			endif
			if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_OUTPUT)) || (!CFG_VDY_DIS_YAW_SENSOR_OUTPUT) ) then (YES)
				if (ReduceQuality > 0.2F) then (YES)
					:limit ReduceQuality \n ReduceQuality = 0.2F;
				endif
			endif
		else (NO)
			if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_OUTPUT)) || (!CFG_VDY_DIS_YAW_SENSOR_OUTPUT) ) then (YES)
				:fYawRate_t ReduceQuality = 0.0F;
			endif
		endif		
	stop
	@enduml
  @testmethod
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> TEST_vdyGenExternalYawRateQuality_001(),
  @traceability
  - L3
    - NA
  - L4
    - NA
**************************************************************************** */
STATIC_MTD fQuality_t vdyGenExternalYawRateQuality(const VDYInternalData_t *IntData, const proVdyPrtList_t *proPorts, const VDYInputData_t *input );
#else
STATIC_MTD fQuality_t vdyGenExternalYawRateQuality(const proVdyPrtList_t *proPorts, const VDYInputData_t *input );
#endif
#endif


/* ***********************************************************************
  @fn               vdyGenYawAndCurveQualitys */ /*!
  @brief           Generate qualitys for sensor yaw rate,
                   and for vehicle curve and vehicle yaw rate.

  @description     Sets curve quality based on yaw rate quality and signal state,
                   steering wheel quality and lateral acceleration offset quality

  @return          static void

  @param[in]       *IntData : VDY Internal Signal Structure
  @param[in,out]   *proPorts : Provide Port
  @param[in]       *input : Current input Signal Structure

  @c_switch_part   
				  - CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING : Disables the alignment yaw rate offset pre filtering, 
																			 - yaw rate from yaw rate sensor with filtered offset estimation 
				  - CFG_VDY_DIS_SWA_OFFSET_COMP : Disables zero point offset compensation of input steering wheel angle signal
				  - CFG_VDY_DIS_LAT_OFFSET_COMP : Disables zero point offset compensation of input lateral acceleration signal
				  - CFG_VDY_DIS_WHS_OFFSET_COMP : Disables offset compensation between left and right wheel on vehicle axle
				  - CFG_VDY_DIS_YWR_OFFSET_COMP : Disables zero point offset compensation of input yaw rate signal
				  - CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING : Disables the sensor yaw rate pre processing, 
																		 - static (stand still)yaw rate offset
																		 - yaw rate from yaw rate sensor estimation
				  - CFG_VDY_INT_GYRO : Enable internal yaw rate sensor processing  
				  - CFG_VDY_DIS_YAW_SENSOR_OUTPUT : Disables the alignment yaw rate output,
																 - yaw rate from yaw rate sensor with filtered offset estimation
				  - CFG_VDY_USE_EXT_PROC_YAW_RATE : Enables usage of external yaw rate as vdy output yaw rate
				  - CFG_VDY_USE_EXT_PROC_CURVATURE : Enables usage of external curve as vdy output curve
  @c_switch_full   None
  @pre             None
  @post            No changes
  @InOutCorrelation	
				  - If internal yaw sensor is used, the quality of the internal yaw rate estimation is used
				  - If external yaw sensor is used, Get quality from external yaw rate sensor processing
				  - Add vehicle sensor yaw rate quality
				  - Add steering wheel angle offset quality, if available
				  - Add lateral acceleration offset quality, if available
				  - Add wheel velocity offset quality, if available
  
	@startuml
	start
		:fQuality_t VehSensorYawQuality \n fQuality_t VehicleCurveYawQuality = VDY_ZERO_F;
		:Sensor yaw rate quality;
		if (If vdy does the sensor yaw rate offset is estimation \n (!CFG_VDY_DIS_YWR_OFFSET_COMP) && ((!defined(CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING))) then (YES)
			if (If internal yaw sensor is used, the quality of the internal yaw rate estimation is used \n CFG_VDY_INT_GYRO)
				if (if external yaw rate signal is valid use the external yaw rate signal otherwise the internal \n VDY_GET_IO_STATE(VDY_SIN_POS_YWR, input->Signals.State) == VDY_IO_STATE_VALID) then (YES)
					if (Get quality from external yaw rate sensor processing \n  (!defined(CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING)) || (!CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING) ) then (YES)
						:VehSensorYawQuality =vdyGenExternalYawRateQuality(IntData, proPorts, input);
					else (NO)
						:VehSensorYawQuality =vdyGenExternalYawRateQuality(proPorts, input);
					endif
				else (NO)
					:Get quality from internal yaw rate sensor processing \n VehSensorYawQuality = vdyGenInternalYawRateQuality(IntData, proPorts, input);
				endif
			else
				if (If external yaw sensor is used Get quality from external yaw rate sensor processing \n (!defined(CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING)) || (!CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING) )
					:VehSensorYawQuality = vdyGenExternalYawRateQuality(IntData, proPorts, input);
				else (NO)
					:VehSensorYawQuality = vdyGenExternalYawRateQuality(proPorts, input);
				endif
			endif
		else (NO)
			:If yaw rate offset compensation is disabeled \n VehSensorYawQuality =  0.45F;
			if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_OUTPUT)) || (!CFG_VDY_DIS_YAW_SENSOR_OUTPUT) )
				:proPorts->pALNYawRate->Quality = 1.0F;
				:set the offset compensation stat always to full stand still \n proPorts->pALNYawRate->OffsetCompState = ALN_YAW_RATE_FULL_STAND_STILL;
				if (Set output state to external input yaw rate state \n VDY_GET_IO_STATE(VDY_SIN_POS_YWR,input->Signals.State) == VDY_IO_STATE_VALID) then (YES)
					:proPorts->pALNYawRate->bSenYawRateState = TRUE;
				else (NO)
					:proPorts->pALNYawRate->bSenYawRateState = FALSE;
				endif
			endif
		endif
		:Add vehicle sensor yaw rate quality \n VehicleCurveYawQuality += VehSensorYawQuality;
		if (Add steering wheel angle offset quality, if available \n !CFG_VDY_DIS_SWA_OFFSET_COMP) then (YES)
			if (IntData->vdy_offsets_in.vdy_swa_offset.state > (uint8)VDY_TWO_U) then (YES)
				:VehicleCurveYawQuality += VDY_THIRTY_FIVE_CENT;
			endif
		else (NO)
			:VehicleCurveYawQuality += VDY_THIRTY_FIVE_CENT;			
		endif
		 
		if (Add lateral acceleration offset quality, if available \n !CFG_VDY_DIS_LAT_OFFSET_COMP) then (YES)
			if (IntData->vdy_offsets_in.vdy_ay_offset.state > (uint8)VDY_TWO_U) then (YES)
				:VehicleCurveYawQuality += VDY_FIFTEEN_CENT;
			endif
		else (NO)
			:VehicleCurveYawQuality += VDY_FIFTEEN_CENT;
		endif

		if (Add wheel velocity offset quality, if available \n !CFG_VDY_DIS_WHS_OFFSET_COMP) then (YES)
			if (   (IntData->vdy_offsets_in.vdy_whs_offset.offset_ratio_front_dev < VDY_ONE_F) && (IntData->vdy_offsets_in.vdy_whs_offset.offset_ratio_rear_dev < VDY_ONE_F)) then (YES)
				:VehicleCurveYawQuality += VDY_FIVE_CENT;
			endif
		else (NO)
			:VehicleCurveYawQuality += VDY_FIVE_CENT;
		endif
	
	stop
	@enduml
  @testmethod			  
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> TEST_vdyGenYawAndCurveQualitys_001()
  @traceability			  
  - L3
    - doors://RBGS854A:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1316-000221c8
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-651-00026448
**************************************************************************** */
STATIC_MTD void vdyGenYawAndCurveQualitys(const VDYInternalData_t *IntData, proVdyPrtList_t *proPorts, const VDYInputData_t *input );


#if (CFG_VDY_GEN_VELOCITY_VARIANCE)
/* ***********************************************************************
  @fn               vdyGenVeloVar */ /*!
  @brief           Generate the velocity variance with use of the acceleration

  @description     Generated velocity variance is calculate by this parabolic function v_var(a) = m*a^2 +b

  @return          static void

  @param[in,out]   *IntData : 

  @pre             None
  @post            No changes
  @InOutCorrelation	
  - CFG_VDY_GEN_VELOCITY_VARIANCE : Generated a velocity variance by deviation of the acceleration
  @testmethod			  
	- Review
  @traceability			  
  - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1570-000221c8
**************************************************************************** */
STATIC_MTD void vdyGenVeloVar(VDYInternalData_t *IntData);
#endif


/* ***********************************************************************
  @fn               vdyInitVehDyn */ /*!
  @brief           Initialize vdy output data

  @description     Sets all data in VehDyn to default values

  @return          static void

  @param[in,out]   *VehDyn : 
  @pre             None
  @post            No changes

  @InOutCorrelation	 
					- Clear and initialize VehDyn to default values
  
	@startuml
	start
		:clear everything including alignment bytes \n (void)vdy_memset_s(VehDyn, 0, sizeof(VehDyn_t));
		:Set interface version number and default states of vdy output \n VehDyn->uiVersionNumber = VDY_VEH_DYN_INTFVER;
		if (VDY_VEH_DYN_INTFVER <= 5) then (YES)
			:VehDyn->State[0] = VDY_VEH_DYN_IO_STATE_INIT;
			:VehDyn->State[1] = VDY_VEH_DYN_IO_STATE_INIT;
		else
			:(void)vdy_memset_s(VehDyn->State, VDY_IO_STATE_INIT, sizeof(VehDyn->State));
		endif
		:VehDyn->MotionState.MotState   = VDY_LONG_MOT_STATE_MOVE;
		if (CFG_VDY_MFC) then (YES)
			:Raw velocity is a provide port for ARS \n RawVelo = VDY_ZERO_F;
		endif
		:return;
	stop
	@enduml
  @testmethod			  - NA
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdyInitVehDyn(VehDyn_t *VehDyn);


#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_OUTPUT)) || (!CFG_VDY_DIS_YAW_SENSOR_OUTPUT) )
/* ***********************************************************************
  @fn               vdyInitALNYawRate */ /*!
  @brief           Initialize vdy alignment yaw rate

  @description     Sets all data in ALNYawRate to default values

  @return          static void

  @param[in,out]   *ALNYawRate : ALN Yaw Rate Signal




  @pre             None
  @post            No changes
  @InOutCorrelation	
  - CFG_VDY_DIS_YAW_SENSOR_OUTPUT : Disables the alignment yaw rate output,
							- yaw rate from yaw rate sensor with filtered offset estimation
  
	@startuml
	start
		:ALNYawRate->uiVersionNumber  = VDY_ALN_YAW_RATE_INTFVER;
		:ALNYawRate->YawRate          = 0.F;
		:ALNYawRate->Quality          = 0.F;
		:ALNYawRate->bSenYawRateState = FALSE;
		:ALNYawRate->OffsetCompState  = ALN_YAW_RATE_NO_EEPROM;
	stop
	@enduml
  @testmethod			  - NA
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdyInitALNYawRate(ALNYawRate_t *ALNYawRate);
#endif


/* ***********************************************************************
  @fn               vdyInitOffsets */ /*!
  @brief           Initialize vdy offset data

  @description     Sets all data in VDYOffsets to default values

  @return          static void

  @param[in,out]   *VDYOffsets : VDY Offset Data

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation	
					- Initialize all data in VDYOffsets to default values 0
  
	@startuml
	start
	  :VDYOffsets->uiVersionNumber = VDY_OFFSETS_INTFVER;
	  :VDYOffsets->Ay.Offset   = VDY_ZERO_F;
	  :VDYOffsets->Ay.State    = VDY_ZERO;
	  :VDYOffsets->Ay.Variance = VDY_ZERO_F;
	  :VDYOffsets->Swa.Offset   = VDY_ZERO_F;
	  :VDYOffsets->Swa.State    = VDY_ZERO;
	  :VDYOffsets->Swa.Variance = VDY_ZERO_F;
	  :VDYOffsets->Ywr.DynOffset        = VDY_ZERO_F;
	  :VDYOffsets->Ywr.DynVariance      = VDY_ZERO_F;
	  :VDYOffsets->Ywr.StandStillOffset = VDY_ZERO_F;
	  :VDYOffsets->Ywr.StandStillState  = VDY_ZERO;	
	stop
	@enduml
  @testmethod			  - NA
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdyInitOffsets(VDYOffsets_t *VDYOffsets);


/* ***********************************************************************
  @fn               vdyInitErrors */ /*!
  @brief           Initialize vdy fault output data

  @description     Sets all faults in VDYErrors to unknown state

  @return          static void

  @param[in,out]   *VDYErrors : VDY Error Signals

  @c_switch_part   None 
  @c_switch_full   None

  @pre             None
  @post            No changes
  @InOutCorrelation	
					  - set version number 
					  - Initialize input parameter error states
					  - Initialize output error states
  
	@startuml
	start
		:set version number \n VDYErrors->uiVersionNumber = VDY_ERRORS_INTFVER;
		:Initialize input signal error states \n VDYErrors->SignalInputErrors.InputSignalError     = VDY_ERR_STATE_UNKNOWN \n VDYErrors->SignalInputErrors.InputSignalPeakError = VDY_ERR_STATE_UNKNOWN;
		:Initialize input parameter error states \n VDYErrors->ParInputErrors.InputParameterError   = VDY_ERR_STATE_UNKNOWN;
		:Initialize output error states;
		:VDYErrors->OutPutErrors.YwrOffsRg        = VDY_ERR_STATE_UNKNOWN;
		:VDYErrors->OutPutErrors.SwaOffsRg        = VDY_ERR_STATE_UNKNOWN;
		:VDYErrors->OutPutErrors.AyOffsRg         = VDY_ERR_STATE_UNKNOWN;
		:VDYErrors->OutPutErrors.VelCorrRg        = VDY_ERR_STATE_UNKNOWN;
		:VDYErrors->OutPutErrors.NVMYwrOffsRg     = VDY_ERR_STATE_UNKNOWN;
		:VDYErrors->OutPutErrors.NVMSwaOffsRg     = VDY_ERR_STATE_UNKNOWN;
		:VDYErrors->OutPutErrors.NVMAyOffsRg      = VDY_ERR_STATE_UNKNOWN;
		:VDYErrors->OutPutErrors.NVMVelCorrRg     = VDY_ERR_STATE_UNKNOWN;
		if ( (defined(CFG_VDY_NVM_LEARN_DATA_ERROR)) && (CFG_VDY_NVM_LEARN_DATA_ERROR) ) then (YES)
			:VDYErrors->OutPutErrors.YwrNVMOffsRg     = VDY_ERR_STATE_UNKNOWN;
			:VDYErrors->OutPutErrors.SwaNVMOffsRg     = VDY_ERR_STATE_UNKNOWN;
			:VDYErrors->OutPutErrors.AyNVMOffsRg      = VDY_ERR_STATE_UNKNOWN;
			:VDYErrors->OutPutErrors.SSGNVMOffsRg     = VDY_ERR_STATE_UNKNOWN;
			:VDYErrors->OutPutErrors.WLDNVMOffsRg     = VDY_ERR_STATE_UNKNOWN;
		endif
		:VDYErrors->OutPutErrors.VelCorrWin       = VDY_ERR_STATE_UNKNOWN;
		:VDYErrors->OutPutErrors.VelMon           = VDY_ERR_STATE_UNKNOWN;
		:VDYErrors->OutPutErrors.VelMonLt         = VDY_ERR_STATE_UNKNOWN;
		:VDYErrors->OutPutErrors.VelocityErr      = VDY_ERR_STATE_UNKNOWN;
		:VDYErrors->OutPutErrors.YawRateErr       = VDY_ERR_STATE_UNKNOWN;
		:VDYErrors->OutPutErrors.YwrMonVehHalt    = VDY_ERR_STATE_UNKNOWN;
		:VDYErrors->OutPutErrors.YwrMonVehDOff    = VDY_ERR_STATE_UNKNOWN;
		:VDYErrors->OutPutErrors.YwrMonAdmWdrwl   = VDY_ERR_STATE_UNKNOWN;
		:VDYErrors->OutPutErrors.YwrACCMonAlignm  = VDY_ERR_STATE_UNKNOWN;
		:VDYErrors->OutPutErrors.YwrCGMonAlignm   = VDY_ERR_STATE_UNKNOWN;
		:VDYErrors->OutPutErrors.YwrMonVehHaltCal = VDY_ERR_STATE_UNKNOWN;
		:VDYErrors->OutPutErrors.VDY_FS_YR_VS_AY  = VDY_ERR_STATE_UNKNOWN;
		:VDYErrors->OutPutErrors.VDY_FS_YR_VS_SWA = VDY_ERR_STATE_UNKNOWN;
		:VDYErrors->OutPutErrors.VDY_FS_YR_VS_WSP = VDY_ERR_STATE_UNKNOWN;
		:VDYErrors->OutPutErrors.VDY_VEH_YWR_NOT_AVAILABLE= VDY_ERR_STATE_UNKNOWN;
		:VDYErrors->OutPutErrors.VDY_VEH_VEL_NOT_AVAILABLE= VDY_ERR_STATE_UNKNOWN;
		:VDYErrors->OutPutErrors.VDY_FS_VEH_CORR_MON = VDY_ERR_STATE_UNKNOWN;	
	stop
	@enduml
  @testmethod			  - NA
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdyInitErrors(VDYErrors_t *VDYErrors);


/* ***********************************************************************
  @fn               vdyInitModuleIf */ /*!
  @brief           Init the Module Interface

  @description     Sets all data in VDYModIf to default values

  @return          static void

  @param[in,out]   *mif : Module Interface Data

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation
  - Sets all data in VDYModIf to default values
  
	@startuml
	start
		:mif->LongMot.MotState.MotState = VDY_LONG_MOT_STATE_MOVE_FWD;
		:mif->LongMot.MotState.Confidence = VDY_ZERO_F;
		:mif->LongMot.VehVelocityCorr = VDY_ZERO_F;
		:mif->LongMot.VehVelo = VDY_ZERO_F;
		:mif->LongMot.VehAccel = VDY_ZERO_F;
 		:mif->LongMot.VehAccelVar = VDY_ZERO_F;
		:mif->LongMot.VehVeloVar = VDY_ZERO_F;
		:mif->SideSlipAngle.SideSlipAngle = VDY_ZERO_F;
		:mif->SideSlipAngle.Variance = VDY_ZERO_F;
		:mif->Curve.Curve = VDY_ZERO_F;
		:mif->Curve.VarCurve = VDY_ZERO_F;
		:mif->CurveInt.C1 = VDY_ZERO_F;
		:mif->CurveInt.varC1 = VDY_ZERO_F;
		:mif->CurveInt.Gradient = VDY_ZERO_F;
		:mif->CurveInt.Quality = VDY_ZERO_F;  
		:mif->YawRate.YawRate = VDY_ZERO_F;
		:mif->YawRate.Variance = VDY_ZERO_F;
		:mif->LongMot.FLWhlVelo = VDY_ONE_F;
		:mif->LongMot.FRWhlVelo = VDY_ONE_F;
		:mif->LongMot.RLWhlVelo = VDY_ONE_F;
		:mif->LongMot.RRWhlVelo = VDY_ONE_F;
		:mif->LongMot.VelCorrFact = VDY_ONE_F;
		:mif->LatAcc.LatAccel = VDY_ZERO_F;
		:mif->LatAcc.Variance = VDY_ZERO_F;
		:mif->YwrOffset.offset = VDY_ZERO_F;
		:mif->YwrOffset.var = VDY_ZERO_F;
		:mif->AyOffset.offset = VDY_ZERO_F;
		:mif->AyOffset.var = VDY_ZERO_F;
		:mif->AyOffset.state = 0U;
		:mif->SwaOffset.offset = VDY_ZERO_F;
		:mif->SwaOffset.state = 0U;
		:mif->SwaOffset.var = VDY_ZERO_F;
		:return;	
	stop
	@enduml
  @testmethod			  - NA
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdyInitModuleIf(VDYModIf_t *mif);


/* ***********************************************************************
  @fn               vdyInitInternal */ /*!
  @brief           Initialize vdy internal autocode data bus

  @description     Sets all data in VDYInternalData to 0

  @return          static void

  @param[in,out]   *intData : VDY Internal Data

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation
						- Set all data in VDYInternalData to 0
  
	@startuml
	start
		:(void)vdy_memset_s(intData, 0x00, sizeof(VDYInternalData_t));
	stop
	@enduml
	
  @testmethod			  - NA
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdyInitInternal(VDYInternalData_t *intData);


/* ***********************************************************************
  @fn               vdyReinitYawRate */ /*!
  @brief           ReInitializes the YE model

  @description     If the YE model calculates a negative variance for
                   several cycles, a re-init of the YE model will be done.

  @return          static void

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation
					- Renitialize YE module
  
					
	@startuml
	start
		:vdy_ye_initialize((boolean_T) 1, &vdy_ye_M, &vdy_ye_B, &vdy_ye_DWork);
		:vdy_ye_k.u_CurveFaultCounter = 0U;
		:vdy_ye_k.u_YawFaultCounter = 0U;
		:vdy_ye_k.u_DICurveFaultCounter = 0U;
	stop
	@enduml
  @testmethod			  - NA
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdyReinitYawRate(void);


/* ***********************************************************************
  @fn               vdyInterfaceHand2Auto */ /*!
  @brief           Interface from handcode to autocode

  @description     Sets all data in VDYInternalData which is an interface
                   between handcode and autocode  to default values

  @return          static void

  @param[in]       input : Current Input Data
  @param[in,out]   *IntData : VDY Internal Data
  @param[in]       *mif : Module Interface Signal

  @c_switch_part   
				  - CFG_VDY_DIS_SWA_OFFSET_COMP : Disables zero point offset compensation of input steering wheel angle signal
				  - CFG_VDY_DIS_LAT_OFFSET_COMP : Disables zero point offset compensation of input lateral acceleration signal
				  - CFG_VDY_DIS_YWR_OFFSET_COMP : Disables zero point offset compensation of input yaw rate signal
				  - CFG_VDY_INT_GYRO : Enable internal yaw rate sensor processing
				  - CFG_VDY_DIS_WHS_OFFSET_COMP : Disables offset compensation between left and right wheel on vehicle axle
  @c_switch_full   None

  @pre             None
  @post            No changes
  @InOutCorrelation	
					- Transfer steering wheel offset to auto code
					- Transfer yaw rate offset to auto code
					- Copy the ToAutocode struct from the external stand still yaw rate offset module
					- Monitor the Dynamic yaw rate offset signal
					- Get the wheel speed offset from the whs modul
					- Transfer lateral acceleration offset  to auto code
  
	@startuml
	start
		if (Steering wheel angle offset \n CFG_VDY_DIS_SWA_OFFSET_COMP) then (YES)
			:input signal is already compensated, there is no zero point offset;
			:IntData->vdy_offsets_in.vdy_swa_offset.state  = 3U;
			:IntData->vdy_offsets_in.vdy_swa_offset.offset = 0.F;
			:IntData->vdy_offsets_in.vdy_swa_offset.var    = 0.00001F;
		else (NO)
			:Pass steering wheel angle offset;
			:Transfer steering wheel offset to auto code;
			:IntData->vdy_offsets_in.vdy_swa_offset      = mif->SwaOffset;
			:IntData->vdy_offsets_in.vdy_swa_offset.var  = VDY_ONE_NE_FIVE;
		endif
		if (Yaw rate offset \n CFG_VDY_DIS_YWR_OFFSET_COMP) then (YES)
			:input signal is already compensated, there is no zero point offset;
			:IntData->vdy_offsets_in.vdy_yaw_offset.offset  = 0.F; 
			:IntData->vdy_offsets_in.vdy_yaw_offset.var     = 0.000000001F;
			:IntData->vdy_offsets_in.vdy_yaw_offset.state   = 1U;
			:IntData->vdy_offsets_in.vdy_yaw_offset.quality = 1.5F;
		else (NO)
			:Pass yaw rate offset;
			:const ToAutocode_t * ToAutocode;
			if (CFG_VDY_INT_GYRO) then (YES)
				:if external yaw rate signal is valid use the external yaw rate signal otherwise the internal;
				if (VDY_GET_IO_STATE(VDY_SIN_POS_YWR, input->Signals.State) == VDY_IO_STATE_VALID) then (YES)
					:const VDYYwrOffsData_t *pYwrOffs = vdyYwrGetOffsData();
					:ToAutocode = &pYwrOffs->ToAutocode;
				else
					:const VDYYwrtOffsData_t *pYwrOffs = VDYYwrtGetOffsData();
					:ToAutocode = &pYwrOffs->ToAutocode;
				endif
			else (NO)
				:const VDYYwrOffsData_t *pYwrOffs = vdyYwrGetOffsData();
				:(void)input;
				:Copy the ToAutocode struct from the external stand still yaw rate offset module \n ToAutocode = &pYwrOffs->ToAutocode;
			endif
			:Monitor the Dynamic yaw rate offset signal \n vdyMonitorDynYwrOffset(ToAutocode, IntData);
		endif
	stop
	@enduml
  @testmethod			  - NA
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdyInterfaceHand2Auto( const VDYInputData_t * input, VDYInternalData_t *IntData, const VDYModIf_t *mif);


#if (CFG_VDY_GEN_VELOCITY_VARIANCE)
STATIC_MTD void vdyInterfaceAuto2Hand(VDYInternalData_t *IntData, VDYModIf_t *mif);

#else
/* ***********************************************************************
  @fn               vdyInterfaceAuto2Hand */ /*!
  @brief           Interface from autocode to handcode

  @description     Sets all data in  VDYModIf which is an interface
                   between autocode and handcode  to default values

  @return          static void

  @param[in,out]   *IntData : VDY Internal Data
  @param[in,out]   *mif : Module Interface Data

  @c_switch_part   
				  - CFG_VDY_GEN_VELOCITY_VARIANCE : Generated a velocity variance by deviation of the acceleration
				  - CFG_VDY_USE_EX_LONG_ACCEL : Use external provided longitudinal acceleration signal
				  - CFG_VDY_USE_EX_LONG_VELO : Use external provided longitudinal velocity signal
				  - CFG_VDY_DO_VELOCITY_CORR : Enables the velocity correction
				  - CFG_VDY_MOT_STATE : Enable motion state processing
				  - CFG_VDY_USE_EXT_PROC_CURVATURE : Enables usage of external curve as vdy output curve
				  - CFG_VDY_USE_EXT_PROC_YAW_RATE : Enables usage of external yaw rate as vdy output yaw rate
				  - CFG_VDY_USE_EXT_PROC_SIDE_SLIP_ANGLE : Enables usage of external side slip angle as vdy ouput side slip angle
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation	
					- copy autocode module output data to module interface
  	  
	@startuml
	start
		:mif->LongMot.VehVeloVar  = IntData->vdy_ve_out.veh_velo_var;
		if (!CFG_VDY_USE_EX_LONG_ACCEL && !CFG_VDY_USE_EX_LONG_VELO) then (YES)
			:mif->LongMot.VehAccel    = IntData->vdy_ve_out.veh_accel;
		endif
		:mif->LongMot.VehAccelVar = IntData->vdy_ve_out.veh_accel_var;
		if (!CFG_VDY_DO_VELOCITY_CORR) then (YES)
			:mif->LongMot.VehVelocityCorr = IntData->vdy_ve_out.veh_velo;
		endif
		if (CFG_VDY_MOT_STATE) then (YES)
			:mif->LongMot.MotState.MotState    = IntData->vdy_mot_st_out.mot_state;
			:mif->LongMot.MotState.Confidence  = (float32) IntData->vdy_mot_st_out.mot_quality;
		endif
		if (!CFG_VDY_USE_EXT_PROC_CURVATURE) then (YES)
			:if internal curvature estimation is used, copy output data to module interface;
			:mif->Curve.Curve    = IntData->vdy_ye_out.veh_merge_curve;
			:mif->CurveInt.C1       = VDY_ZERO_F;
			:mif->CurveInt.Gradient = IntData->vdy_ye_out.veh_merge_curve_grad;
			:mif->Curve.VarCurve    = IntData->vdy_ye_out.veh_merge_curve_var;
			:mif->CurveInt.varC1    = VDY_ZERO_F;
			:mif->CurveInt.Quality  = VDY_ZERO_F;
		endif
		if (if internal yaw rate estimation is used, copy output data to module interface  \n !CFG_VDY_USE_EXT_PROC_YAW_RATE)  then (YES)
			:mif->YawRate.YawRate  = vdy_internal_data.vdy_ye_out.veh_yaw_rate;
			:mif->YawRate.Variance = vdy_internal_data.vdy_ye_out.veh_yaw_rate_var;
		endif
		if (!CFG_VDY_USE_EXT_PROC_SIDE_SLIP_ANGLE) then (YES)
			:mif->SideSlipAngle.SideSlipAngle   = vdy_internal_data.vdy_sae_out.est_slip_angle;
			:mif->SideSlipAngle.Variance        = vdy_internal_data.vdy_sae_out.est_slip_angle_var;
		endif
		:mif->LongMot.FLWhlVelo    = IntData->vdy_wpp_out.wheel_velo_front_left;
		:mif->LongMot.FRWhlVelo    = IntData->vdy_wpp_out.wheel_velo_front_right;
		:mif->LongMot.RLWhlVelo    = IntData->vdy_wpp_out.wheel_velo_rear_left;
		:mif->LongMot.RRWhlVelo    = IntData->vdy_wpp_out.wheel_velo_rear_right;
		:mif->LatAcc.LatAccel      = IntData->vdy_ye_out.veh_lat_accel;
		:mif->LatAcc.Variance      = IntData->vdy_ye_out.veh_merge_curve_var  + (VDY_TWO_F * IntData->vdy_ve_out.veh_velo_var);
		:write the the dynamic yaw rate offset to the module interface \n mif->YwrOffset.offset     = IntData->vdy_wye_out.gier_yaw_rate_offset \n mif->YwrOffset.var        = IntData->vdy_wye_out.gier_yaw_rate_offset_var;
		if ((CFG_VDY_MOT_STATE) || (!CFG_VDY_MOT_STATE)) then (YES)
			if((VDYModIf.LongMot.MotState.MotState ==  (MotState_t)VDY_LONG_MOT_STATE_MOVE_RWD) && (VDYModIf.LongMot.VehVelo > VDY_ZERO_F)) then (YES)
				:vdy_internal_data.vdy_wye_out.whl_yaw_rate	=	-vdy_internal_data.vdy_wye_out.whl_yaw_rate;
				:vdy_internal_data.vdy_sye_out.stw_yaw_rate	=	-vdy_internal_data.vdy_sye_out.stw_yaw_rate;
				:vdy_internal_data.vdy_aye_out.ay_yaw_rate	=	-vdy_internal_data.vdy_aye_out.ay_yaw_rate;
			endif
		endif
		:return;
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> TEST_vdyInterfaceAuto2Hand_001(), TEST_vdyInterfaceAuto2Hand_002()
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdyInterfaceAuto2Hand(const VDYInternalData_t *IntData, VDYModIf_t *mif);
#endif


#if ( (!defined(CFG_VDY_DIS_CURVE_OUTPUT)) || (!CFG_VDY_DIS_CURVE_OUTPUT) )
/* **********************************************************************
  @fn               vdyYawRate2Curve */ /*!
  @brief           Convert yaw rates to curve and copy the data to meas buffer

  @description     Calculates the curves for all the internal yaw rates
                   These curves are used by the birdeye MO

  @return          static void

  @param[in]       *intData : VDY Internal Data
  @param[in]       *proPorts : Provide Ports

  @c_switch_part   None 
  @c_switch_full   CFG_VDY_DIS_CURVE_OUTPUT : Disable the additional VDY curve output

  @pre             None
  @post            No changes
  @InOutCorrelation	
					- copy version number, wheel speeds curves, yaw rate curve, lateral acceleration curve, steering wheel angle curve, vehicle yaw rate curve and driver intended curve to proPorts->pVDYEstCurves
					
	@startuml
	start
		if (VDYModIf.LongMot.VehVelocityCorr > C_F32_DELTA) then (YES)
			:invVelo = VDY_ONE_F / VDYModIf.LongMot.VehVelocityCorr;
		else (NO)
			:invVelo = VDY_ZERO_F;
		endif
		:version number \n proPorts->pVDYEstCurves->uiVersionNumber = VDY_EST_CURVES_INTFVER;
		:whl speed curve \n proPorts->pVDYEstCurves->WhlFr.Curve     = intData->vdy_wye_out.front_whl_yaw_rate_filt_wld  * invVelo;
		:whl speed curve \n proPorts->pVDYEstCurves->WhlRe.Curve     = intData->vdy_wye_out.rear_whl_yaw_rate_filt  * invVelo;
		:whl speed curve \n proPorts->pVDYEstCurves->Whl.Curve       = intData->vdy_wye_out.whl_yaw_rate  * invVelo;
		:yaw rate curve \n proPorts->pVDYEstCurves->YwRate.Curve    = intData->vdy_gye_out.gier_yaw_rate * invVelo;
		:lateral acceleration curve \n proPorts->pVDYEstCurves->Ay.Curve        = intData->vdy_aye_out.ay_yaw_rate   * invVelo;
		:steering wheel angle curve \n proPorts->pVDYEstCurves->Swa.Curve       = intData->vdy_sye_out.stw_yaw_rate  * invVelo;
		:vehicle yaw rate curve  \n proPorts->pVDYEstCurves->VehYaw.Curve    = intData->vdy_ye_out.veh_yaw_rate   * invVelo;
		:driver intented curve \n proPorts->pVDYEstCurves->DrvInt.Curve    = intData->vdy_sye_out.stw_curve;
		:return;
	stop
	@enduml
  @testmethod			  - NA
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdyYawRate2Curve(const VDYInternalData_t *intData, const proVdyPrtList_t *proPorts);
#endif

#if ( defined(VDY_FREEZE_INIT_SEQUENCE) && (VDY_FREEZE_INIT_SEQUENCE) )
/* ***********************************************************************
  @fn               vdyInitSequenceMeasFreeze */ /*!
  @brief           Do Init sequence meas freeze

  @description     Freezes all internal data, one module every time
                   Cycles through the modules until all data is freezed
                   This function is only active in the ECU code and 
                   used to sync the simulation to the measurement

  @return          static void

  @param[in]       services : Service Calls

  @glob_in         None 
  @glob_out        InitPackageID : package ID

  @pre             None
  @post            No changes
  @c_switch_part   None 
  @c_switch_full
  - CFG_VDY_DIS_WHEEL_PRE_PROCESSING : Disables the wheel speed pre processing, 
							- wheel offset estimation
							- wheel velocity <-> puls fusion
							- vehicle speed estimation
							- wheel load dependancy estimation
							- dynamic (drift) sensor yaw rate offset estimation
							- wheel velocity yaw rate estimation 
  - CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING : Disables the sensor yaw rate pre processing, 
							- static (stand still)yaw rate offset
							- yaw rate from yaw rate sensor estimation
  - CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING : Disables the alignment yaw rate offset pre filtering, 
							- yaw rate from yaw rate sensor with filtered offset estimation
  - CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING : Disables the lateral acceleration sensor pre processing, 
							- lateral sensor offset estimation
							- yaw rate from lateral acceleration sensor estimation
  - CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING : Disables the steering wheel angle sensor pre processing, 
							- steering wheel angle sensor offset estimation
							- estimation of self steering gradient
							- driver intended curvature
							- yaw rate from steering wheel sensor estimation 
  - CFG_VDY_USE_EXT_PROC_YAW_RATE : Enables usage of external yaw rate as vdy output yaw rate
  - CFG_VDY_DIS_SIDE_SLIP_ANGLE_ESTIMATION : Disables the side slip angle estimation
  - CFG_VDY_MOT_STATE : Enable motion state processing
  - VDY_FREEZE_INIT_SEQUENCE : Init sequence meas freeze
  
  @InOutCorrelation 
  
  @startuml
  start
	:Measfreeze InitSequence;
	:return;
  stop
  @enduml
    
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> \n
                            TEST_vdyInitSequenceMeasFreeze_001(),
                            TEST_vdyInitSequenceMeasFreeze_002(),
                            TEST_vdyInitSequenceMeasFreeze_003(),
                            TEST_vdyInitSequenceMeasFreeze_004(),
                            TEST_vdyInitSequenceMeasFreeze_005(),
                            TEST_vdyInitSequenceMeasFreeze_006(),
                            TEST_vdyInitSequenceMeasFreeze_007(),
                            TEST_vdyInitSequenceMeasFreeze_008(),
                            TEST_vdyInitSequenceMeasFreeze_009(),
                            TEST_vdyInitSequenceMeasFreeze_010(),
                            TEST_vdyInitSequenceMeasFreeze_011(),
                            TEST_vdyInitSequenceMeasFreeze_012(),
                            TEST_vdyInitSequenceMeasFreeze_013(),
                            TEST_vdyInitSequenceMeasFreeze_014()
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdyInitSequenceMeasFreeze(const AS_t_ServiceFuncts * services);
#endif

#if ( defined(CFG_VDY_USE_ALGOCOMPSTATE) && (CFG_VDY_USE_ALGOCOMPSTATE) && (!CFG_VDY_MFC) )
/* *************************************************************************
  @fn               VDYSenSetCompState */ /*!
  @brief            set VDY compstate for scheduler

  @description      sets version, operation state and fault state

  @param[in]        VDYIn ControlMode
  @param[out]       proPorts comp state output
  @return           void

  @pre             None
  @post            No changes
  @InOutCorrelation	
  
	- 
  @testmethod			  -
  @traceability			  -
**************************************************************************** */
STATIC_MTD void vdySetCompState(const VDYInputData_t  VDYIn, const proVdyPrtList_t * proPorts);
#endif
#ifdef AS_SERVICEFUNC_VERSION
/* *************************************************************************
  @fn               vdySetSyncFrame */ /*!
  @brief           Fill VDY MTS sync frame

  @description     Copies the content of the signal headers of all inputs
                   (required ports) to the sync header data structure
                   and freezes the sync frame, then freeze the SIM frame

  @return          static void

  @param[in]       *reqPorts : 
  @param[in]       CycleCnt : 
  @param[in]       eVDYSigStatus : 

  @glob_in         None 
  @glob_out        s_SyncRef : Simulation synchronisation counter of input data

  @c_switch_part   
				  - CFG_VDY_DO_VELOCITY_CORR : Enables the velocity correction
				  - VEL_CORR_HIST_STATIONARY_TARGETS : Enables stationary targets as input for velocity correction
				  - VEL_CORR_ALN : Enables ALN calculated velocity as input for velocity correction
				  - CFG_VDY_ROLLBENCH_DETECTION : Enables reaction to roll bench detection 
				  - CFG_VDY_64BIT_TIMESTAMP_INTERV : Enables the 64 bit Timestamp interface
  @c_switch_full   AS_SERVICEFUNC_VERSION : Servicefunctions version

  @pre             None
  @post            No changes
  @InOutCorrelation	
  
	- 
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> TEST_vdySetSyncFrame_001()
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdySetSyncFrame(const reqVdyPrtList_t *reqPorts, uint16 CycleCnt, AlgoSignalState_t eVDYSigStatus);
#endif

/* *************************************************************************
  @fn             vdyCheckPorts */ /*!
  @brief          Check input and output ports for valid pointer

  @description    Check all requested, provided and servive ports for NULL pointer
                  and set a fault if any one contains a NULL pointer

  @param[in]      reqPorts : the inputs passed to VDY
  @param[in]      proPorts : the outputs of VDY
  @param[in]      services : service functions used by VDY
  @param[out]     -

  @return         Fault status

  @pre            -
  @post           -
  @InOutCorrelation	
					- Check all ports for NULL pointer 

	@startuml
	start
		:uint8 ui8Fault = VDY_NO_PORT_FAULT;
		:Check all ports for NULL pointer;
		:uint8 uiOpData[VDY_THREE] \n uint8 uiOpData1[VDY_THREE] \n uiOpData[0] = FUSI_ERROR_DIR_INPUT \n uiOpData[1] = FUSI_ERROR_TYPE_NULLPOINTER;
		:uiOpData[VDY_TWO] = (uint8)offsetof ( reqVdyPrtList_t, pBaseCtrlData);
		if(If Request Port in NULL \n (NULL == reqPorts) || (NULL == reqPorts->pBaseCtrlData)) then (YES)
			:uiOpData[VDY_TWO] = (uint8)offsetof(reqVdyPrtList_t, pBaseCtrlData);
			if( reqPorts->pBaseCtrlData->eOpMode != (BaseOpMode_t)BASE_OM_RESET ) then (YES) 
				:services->pfDem_SetEventStatus( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED );
				:services->pfDem_SetEventStatusPreExtData( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED, (const uint8*)&uiOpData, sizeof(uiOpData) );
			endif
			:ui8Fault = VDY_REQUEST_PORT_FAULT;
		else if(If NVM read port is NULL \n  NULL == reqPorts->pNVMRead	) then (YES)
			:uiOpData[VDY_TWO] = (uint8)offsetof ( reqVdyPrtList_t, pNVMRead);
			if( reqPorts->pBaseCtrlData->eOpMode != (BaseOpMode_t)BASE_OM_RESET ) then (YES)
				:services->pfDem_SetEventStatus( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED );
				:services->pfDem_SetEventStatusPreExtData( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED, (const uint8*)&uiOpData, sizeof(uiOpData) );
			endif
			:ui8Fault = VDY_REQUEST_PORT_FAULT;
		else if(If pVehicleInputSignals port is NULL \n NULL == reqPorts->pVehicleInputSignals	) then (YES)
			:uiOpData[VDY_TWO] = (uint8)offsetof ( reqVdyPrtList_t, pVehicleInputSignals );
			if( reqPorts->pBaseCtrlData->eOpMode != (BaseOpMode_t)BASE_OM_RESET ) then (YES)
				:services->pfDem_SetEventStatus( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED );
				:services->pfDem_SetEventStatusPreExtData( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED, (const uint8*)&uiOpData, sizeof(uiOpData) );
			endif
			:ui8Fault = VDY_REQUEST_PORT_FAULT;
		else if(If pVehicleParameter port is NULL \n NULL == reqPorts->pVehicleParameter) then (YES)
			:uiOpData[VDY_TWO] = (uint8)offsetof ( reqVdyPrtList_t, pVehicleParameter	   );
			if( reqPorts->pBaseCtrlData->eOpMode != (BaseOpMode_t)BASE_OM_RESET ) then (YES)
				:services->pfDem_SetEventStatus( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED );
				:services->pfDem_SetEventStatusPreExtData( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED, (const uint8*)&uiOpData, sizeof(uiOpData) );
			endif
			:ui8Fault = VDY_REQUEST_PORT_FAULT;
		else (NO)
			:If none of the request port's are null, then set the Dem_EventStatus PASS and return. \n 
			services->pfDem_SetEventStatus( VDY_FUSI_ERROR, DEM_EVENT_STATUS_PASSED ) \n
			services->pfDem_SetEventStatusPreExtData( (const AS_t_Dem_EventIDType)VDY_FUSI_ERROR, (const AS_t_Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, (const uint8*)&uiOpData, sizeof(uiOpData) );
		endif
		:Check Provide Ports for NULL
		:uiOpData1[0] = FUSI_ERROR_DIR_OUTPUT;
		:uiOpData1[1] = FUSI_ERROR_TYPE_NULLPOINTER;
		if (If provide port is Null, then set the Dem_EventStatus FAILED and return \n (NULL == proPorts) ||  (NULL == proPorts->pAlgoCompState))  then (YES)
			:uiOpData1[VDY_TWO] = (uint8)offsetof ( proVdyPrtList_t, pAlgoCompState);
			:services->pfDem_SetEventStatus( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED );
			:services->pfDem_SetEventStatusPreExtData( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED, (const uint8*)&uiOpData1, sizeof(uiOpData1) );
			:ui8Fault = VDY_PROVIDE_PORT_FAULT;
		else if(If NVM write port is Null \n NULL == proPorts->pNVMWrite) then (YES)
			:uiOpData1[VDY_TWO] = (uint8)offsetof ( proVdyPrtList_t, pNVMWrite);
			:services->pfDem_SetEventStatus( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED );
			:services->pfDem_SetEventStatusPreExtData( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED, (const uint8*)&uiOpData1, sizeof(uiOpData1) );
			:ui8Fault = VDY_PROVIDE_PORT_FAULT;
		else if(If pVDYErrors port is Null \n NULL == proPorts->pVDYErrors) then (YES)
			:uiOpData1[VDY_TWO] = (uint8)offsetof ( proVdyPrtList_t, pVDYErrors);
			:services->pfDem_SetEventStatus( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED );
			:services->pfDem_SetEventStatusPreExtData( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED, (const uint8*)&uiOpData1, sizeof(uiOpData1) );
			:ui8Fault = VDY_PROVIDE_PORT_FAULT;
		else if(If pVDYOffsets port is Null \n NULL == proPorts->pVDYOffsets) then (YES)
			:uiOpData1[VDY_TWO] = (uint8)offsetof ( proVdyPrtList_t, pVDYOffsets);
			:services->pfDem_SetEventStatus( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED );
			:services->pfDem_SetEventStatusPreExtData( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED, (const uint8*)&uiOpData1, sizeof(uiOpData1) );
			:ui8Fault = VDY_PROVIDE_PORT_FAULT;
		else if(If pVehicleDynamicSignals port is Null \n NULL == proPorts->pVehicleDynamicSignals	) then (YES)
			:uiOpData1[VDY_TWO] = (uint8)offsetof ( proVdyPrtList_t, pVehicleDynamicSignals );
			:services->pfDem_SetEventStatus( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED );
			:services->pfDem_SetEventStatusPreExtData( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED, (const uint8*)&uiOpData1, sizeof(uiOpData1) );
			:ui8Fault = VDY_PROVIDE_PORT_FAULT;
		else (NO)
			:If none of the provide port's are Null, then set the Dem_EventStatus PASS and return;
			:services->pfDem_SetEventStatus( VDY_FUSI_ERROR, DEM_EVENT_STATUS_PASSED );
			:services->pfDem_SetEventStatusPreExtData( VDY_FUSI_ERROR, DEM_EVENT_STATUS_PASSED, (const uint8*)&uiOpData1, sizeof(uiOpData1) );
		endif
		:Check Service Ports for NULL;
		if( (NULL == services->pfRTAAlgoServiceAddEvent) || (NULL == services->pfMeasStartFuncCycle) || 
			(NULL == services->pfDem_SetEventStatus	 ) || (NULL == services->pfDem_SetEventStatusPreExtData) ) then (YES)
			:ui8Fault = VDY_SERVICE_PORT_FAULT;
		else (NO)
			:If none of the service port's are Null, then set the Dem_EventStatus PASS and return;
		endif
		:return ui8Fault;
		
	stop
	@enduml
  @testmethod
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> TEST_vdyCheckPorts_001(), TEST_vdyCheckPorts_002(), TEST_vdyCheckPorts_003()
  @traceability
  - L3
    - doors://RBGS854A:40000/?version=2&prodID=0&view=000000cd&urn=urn:telelogic::1-503e822e5ec3651e-O-1612-000221c8
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1614-000221c8
  - L4 
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1142-00026448
  @author         Frank Wolter
**************************************************************************** */
#ifdef AS_SERVICEFUNC_VERSION
STATIC_MTD uint8 vdyCheckPorts(const reqVdyPrtList_t *reqPorts, const proVdyPrtList_t *proPorts, const AS_t_ServiceFuncts * services);
#else
STATIC_MTD uint8 vdyCheckPorts(const reqVdyPrtList_t *reqPorts, const proVdyPrtList_t *proPorts);
#endif


/* **********************************************************************
  @fn              vdyCalculateCurveLatDistance */ /*!
  @brief           Calculate lateral distance of 2 curves in given distance

  @description     On 2 circles with a given radius (or curvature), the
                   euklidian distance between the points on these 2 circles with
                   the same arc length is calculated

  @return          static float32: distance between the 2 points

  @param[in]       f_c1 : curve of first circle
  @param[in]       f_c2 : curve of second circle
  @param[in]       f_b : arc length, used for both cicles

  @pre             None
  @post            No changes
  @InOutCorrelation	
					  - if curvature is very small, the point is assumed on the straight line, otherwise calculate coordinates on circle then f_xc1 = 0; f_yc1 = f_b;
												- else     f_xc1 = ((COS_HD_(f_c1*f_b)) / f_c1) - (1/f_c1); f_yc1 = (SIN_HD_(f_c1*f_b)) / f_c1;
					  - if curvature is very small, the point is assumed on the straight line, otherwise calculate coordinates on circle then f_xc2 = 0; f_yc2 = f_b;
												- else f_xc2 = ((COS_HD_(f_c2*f_b)) / f_c2) - (1/f_c2); f_yc2 = (SIN_HD_(f_c2*f_b)) / f_c2;
					  - calculate distance between points 
												- f_d = VDY_SQRT( CML_Sqr(f_xc1 - f_xc2) + CML_Sqr(f_yc1 - f_yc2) );
  
	@startuml
	start
		if (CML_f_Abs(f_c1) < MIN_CURVE_FOR_APPROXIMATION) then (YES)
			:f_xc1 = VDY_ZERO_F;
			:f_yc1 = f_b;
		else (NO)
			:f_xc1 = ((COS_HD_(f_c1*f_b)) / f_c1) - (VDY_ONE_F/f_c1);
			:f_yc1 = (SIN_HD_(f_c1*f_b)) / f_c1;
		endif
		if ( if curvature is very small, the point is assumed on the straight line, otherwise calculate coordinates on circle \n CML_f_Abs(f_c2) < MIN_CURVE_FOR_APPROXIMATION) then (YES)
			:f_xc2 = VDY_ZERO_F;
			:f_yc2 = f_b;
		else (NO)
			:f_xc2 = ((COS_HD_(f_c2*f_b)) / f_c2) - (VDY_ONE_F/f_c2);
			:f_yc2 = (SIN_HD_(f_c2*f_b)) / f_c2;
		endif
		:calculate distance between points \n f_d = VDY_SQRT( CML_Sqr(f_xc1 - f_xc2) + CML_Sqr(f_yc1 - f_yc2) );
		:return f_d;
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> TEST_vdyCalculateCurveLatDistance_001()
  @traceability			  - NA
  @author         Frank Wolter
**************************************************************************** */
STATIC_MTD float32 vdyCalculateCurveLatDistance(float32 f_c1, float32 f_c2, float32 f_b);


/* *************************************************************************
  @fn              vdyCalculateCurveError */ /*!
  @brief           Calculate lateral error of the curve

  @description     The offset learning states of ay, swa, gye and wye are
                   transformed into a yaw rate offset error (the error gets
                   less with higher states).
                   Then these remaining yaw rate errors are calculated into a
                   seperate curvature error for each input.  These individually
                   curvature errors are then added into a single curvature
                   error using the Kalman gain of the ye model as weight.
                   The ye yaw rate error and the swa yae rate error is then
                   calculated into a curve error (again using the Kalman gain
                   of the cuve fusion as weight).

  @return          static float32: curve error

  @param[in]       input : current input signal
  @param[in]       pVDYOffsets : vdy offset structure

  @c_switch_part   
				  - CFG_VDY_DIS_WHS_OFFSET_COMP : Disables offset compensation between left and right wheel on vehicle axle
				  - CFG_VDY_DIS_WHEEL_PRE_PROCESSING : Disables the wheel speed pre processing, 
																	- wheel offset estimation
																	- wheel velocity <-> puls fusion
																	- vehicle speed estimation
																	- wheel load dependancy estimation
																	- dynamic (drift) sensor yaw rate offset estimation
																	- wheel velocity yaw rate estimation
				  - CFG_VDY_DIS_SWA_OFFSET_COMP : Disables zero point offset compensation of input steering wheel angle signal
				  CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING : Disables the steering wheel angle sensor pre processing, 
																			   - steering wheel angle sensor offset estimation
																			   - estimation of self steering gradient
																			   - driver intended curvature
																			   - yaw rate from steering wheel sensor estimation
				  - CFG_VDY_DIS_YWR_OFFSET_COMP : Disables zero point offset compensation of input yaw rate signal
				  - CFG_VDY_DIS_LAT_OFFSET_COMP : Disables zero point offset compensation of input lateral acceleration signal
				  - CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING : Disables the lateral acceleration sensor pre processing, 
																			   - lateral sensor offset estimation
																			   - yaw rate from lateral acceleration sensor estimation
				  - CFG_VDY_DIS_WHS_OFFSET_COMP : Disables offset compensation between left and right wheel on vehicle axle 
  @c_switch_full   None ? : Compiler switch used around this function/file

  @pre             None
  @post            No changes 
  @InOutCorrelation	
					  - get steering wheel error based on offset deviation
					  - get gyro error based on offset learn state
						- If no offset type present then yaw_offset_error = YWR_OFFSET_ERROR_OUT_YWR_OFFS_NON
						- Else if Offset short acquired from stand still then  yaw_offset_error = YWR_OFFSET_ERROR_OUT_YWR_OFFS_STANDST_SHORT
						- Else if already in the dynamic offset phase, use dynamic offset accuracy, yaw_offset_error = YWR_OFFSET_ERROR_OUT_YWR_OFFS_DYN
						- Else if Offset full acquired from stand still 
							- If the wheel offsets are calculated, we are also already in the dynamic yaw rate offset phase then yaw_offset_error = YWR_OFFSET_ERROR_OUT_YWR_OFFS_STANDST_FULL
							- else yaw_offset_error = YWR_OFFSET_ERROR_OUT_YWR_OFFS_DYN
						- Else if Offset acquired from non-volatile memory
							- If CFG_VDY_REDUCE_CURVE_ERROR is enabled
								- If Change the yaw offset error from EEPROM to Dynamic to reduce the curve error when the vehicle is moving and threshold time is elapsed then yaw_offset_error = YWR_OFFSET_ERROR_OUT_YWR_OFFS_DYN
								- Else yaw_offset_error = YWR_OFFSET_ERROR_OUT_YWR_OFFS_STANDST_EEPROM and increase the count
							- Else yaw_offset_error = YWR_OFFSET_ERROR_OUT_YWR_OFFS_STANDST_EEPROM
						- Else invalid state information, assume max. error, yaw_offset_error = YWR_OFFSET_ERROR_OUT_YWR_OFFS_NON
					  - get lateral acceleration error based on offset deviation
					  - calculate yaw errors based on variance and offset error
					  - gye error is already a yaw rate error, no further calculation needed
					  - calculate wheel errors based offset error
					  - calculate combined yaw rate (ye) error considering the Kalman gain
					  - calculate combined yaw rate (ye) curve error
					  - calculate steering angle (sye) curve error
					  - calculate combined curve error considering the Kalman gain
  
	@startuml
	start
		if (get steering wheel error based on offset deviation \n (CFG_VDY_DIS_SWA_OFFSET_COMP == 0) && (CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING == 0) ) then (YES)
			:VDYSwaData_t    *pSwaData  = vdySwaGetPrivateData();
			:swa_offset_error = pSwaData->Offset.Dev / VDY_THREE_F;
		else (NO)
			:swa_offset_error = 0.0F;
		endif
		if (get gyro error based on offset learn state \n CFG_VDY_DIS_YWR_OFFSET_COMP == 0) then (YES)
			if (No offset type present  \n pVDYOffsets->Ywr.StandStillState == (sint32)OUT_YWR_OFFS_NON) then (YES)
				:yaw_offset_error = YWR_OFFSET_ERROR_OUT_YWR_OFFS_NON;
			else if (Offset short acquired from stand still  \n pVDYOffsets->Ywr.StandStillState == (sint32)OUT_YWR_OFFS_STANDST_SHORT) then (YES)
				:yaw_offset_error = YWR_OFFSET_ERROR_OUT_YWR_OFFS_STANDST_SHORT;
			else if (if already in the dynamic offset phase, use dynamic offset accuracy \n pVDYOffsets->Ywr.StandStillState == (sint32)OUT_YWR_OFFS_DYN) then (YES)
				:yaw_offset_error = YWR_OFFSET_ERROR_OUT_YWR_OFFS_DYN;
			else if (Offset full acquired from stand still \n pVDYOffsets->Ywr.StandStillState == (sint32)OUT_YWR_OFFS_STANDST_FULL) then (YES)
				if ( the wheel offsets are calculated, we are also already in the dynamic yaw rate offset phase \n (vdy_internal_data.vdy_offsets_in.vdy_whs_offset.offset_ratio_front_dev >= VDY_ONE_F) || (vdy_internal_data.vdy_offsets_in.vdy_whs_offset.offset_ratio_rear_dev >= VDY_ONE_F)) then (YES)
					:yaw_offset_error = YWR_OFFSET_ERROR_OUT_YWR_OFFS_STANDST_FULL;
				else (NO)
					:yaw_offset_error = YWR_OFFSET_ERROR_OUT_YWR_OFFS_DYN;
				endif
			else if (Offset acquired from non-volatile memory \n pVDYOffsets->Ywr.StandStillState == (sint32)OUT_YWR_OFFS_STANDST_EEPROM) then (YES)
				if ( (defined(CFG_VDY_REDUCE_CURVE_ERROR)) && (CFG_VDY_REDUCE_CURVE_ERROR) ) then (YES)
					:Change the yaw offset error from EEPROM to Dynamic to reduce the curve error when the vehicle is moving and threshold time is elapsed;
					if((VDYModIf.LongMot.MotState.MotState != VDY_LONG_MOT_STATE_STDST) && (u_count > TIME_EEPROM_TO_DYNAMIC)) then (YES)
						:yaw_offset_error = YWR_OFFSET_ERROR_OUT_YWR_OFFS_DYN;
					else (NO)
						if(u_count > TIME_EEPROM_TO_DYNAMIC) then (YES)
							:u_count = 0;
						endif
						:yaw_offset_error = YWR_OFFSET_ERROR_OUT_YWR_OFFS_STANDST_EEPROM;
						:u_count++;
					endif
				else (NO)
					:yaw_offset_error = YWR_OFFSET_ERROR_OUT_YWR_OFFS_STANDST_EEPROM;
				endif
			else
				:invalid state information, assume max. error \n yaw_offset_error = YWR_OFFSET_ERROR_OUT_YWR_OFFS_NON;
			endif
		else (NO)
			:yaw rate input already compensated, assume low error \n yaw_offset_error = YWR_OFFSET_ERROR_OUT_YWR_OFFS_DYN;
		endif
		if (get lateral acceleration error based on offset deviation  \n (CFG_VDY_DIS_LAT_OFFSET_COMP == 0) && (CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING == 0) ) then (YES)
			:VDYAyData_t     *pAyData   = vdyAyGetPrivateData();
			:ay_offset_error = pAyData->Offset.Dev / VDY_THREE_F;
		else
			:ay_offset_error = 0.0F;
		endif
		:calculate yaw errors based on variance and offset error \n sye_error = (VDY_ONE_F/input->Parameter.SteeringRatio.swa.rat[1]) * ((swa_offset_error / (input->Parameter.WheelBase + (input->Parameter.SelfSteerGrad * CML_Sqr(vdy_internal_data.vdy_ve_out.veh_velo)))) * vdy_internal_data.vdy_ve_out.veh_velo);
		:gye error is already a yaw rate error, no further calculation needed  \n gye_error = yaw_offset_error;
		if ( vdy_internal_data.vdy_ve_out.veh_velo >MIN_VELO_YAW_RATE_ERROR) then (YES)
			:aye_error = ay_offset_error / vdy_internal_data.vdy_ve_out.veh_velo;
		else (NO)
			:aye_error = VDY_ZERO_F;
		endif
		if (calculate wheel errors based offset error \n (CFG_VDY_DIS_WHS_OFFSET_COMP == 0) && (CFG_VDY_DIS_WHEEL_PRE_PROCESSING == 0) )
			if (CML_f_IsNonZero(vdy_internal_data.vdy_ve_out.veh_velo))
				:float32 f_wye_temp;
				:f_wye_temp =(input->Parameter.TrackWidthFront * (VDY_ONE_F + ((input->Parameter.AxisLoadDistr) * ((input->Parameter.WhlLoadDepFrontAxle * (input->Parameter.CntrOfGravHeight * (input->Parameter.VehWeight * CML_Sqr(vdy_internal_data.vdy_ve_out.veh_velo)))) / ((VDY_THOUSAND_F*VDY_THOUSAND_F) * CML_Sqr(input->Parameter.TrackWidthFront))) ) ));
				if (f_wye_temp > VDY_ZERO_F) then (YES)
					:wye_error_front = (vdy_internal_data.vdy_offsets_in.vdy_whs_offset.offset_ratio_front_dev * vdy_internal_data.vdy_ve_out.veh_velo) / f_wye_temp;
				else
					:wye_error_front = VDY_ZERO_F;
				endif
				:f_wye_temp = (input->Parameter.TrackWidthRear  * (VDY_ONE_F + (((VDY_ONE_F - input->Parameter.AxisLoadDistr) * ((input->Parameter.WhlLoadDepRearAxle  * (input->Parameter.CntrOfGravHeight * (input->Parameter.VehWeight * CML_Sqr(vdy_internal_data.vdy_ve_out.veh_velo)))) / ((VDY_THOUSAND_F*VDY_THOUSAND_F) * CML_Sqr(input->Parameter.TrackWidthRear ))) ) ))  );
				if (f_wye_temp > VDY_ZERO_F) then (YES)
					:wye_error_rear = (vdy_internal_data.vdy_offsets_in.vdy_whs_offset.offset_ratio_rear_dev  * vdy_internal_data.vdy_ve_out.veh_velo) / f_wye_temp;
				else (NO)
					:wye_error_rear = VDY_ZERO_F;
				endif
			else (NO)
				:wye_error_front = VDY_ZERO_F;
				:wye_error_rear = VDY_ZERO_F;
			endif
			:wye_error = wye_error_front + wye_error_rear; 
		else (NO)
			:wheel speed processing deactivated, no error added (will not be used for yaw rate anyway) \n wye_error = 0;
		endif
		:calculate combined yaw rate (ye) error considering the Kalman gain \n k_yaw_sum = vdy_ye_k.K_yaw[VDY_ONE] + vdy_ye_k.K_yaw[VDY_THREE] + vdy_ye_k.K_yaw[VDY_FIVE] + vdy_ye_k.K_yaw[VDY_SEVEN];
		if ( CML_f_IsNonZero(k_yaw_sum) ) then (YES)
			:k_yaw_gye_part = vdy_ye_k.K_yaw[VDY_ONE] / k_yaw_sum;
			:k_yaw_wye_part = vdy_ye_k.K_yaw[VDY_THREE] / k_yaw_sum;
			:k_yaw_aye_part = vdy_ye_k.K_yaw[VDY_FIVE] / k_yaw_sum;
			:k_yaw_sye_part = vdy_ye_k.K_yaw[VDY_SEVEN] / k_yaw_sum;
			:ye_error = (sye_error * k_yaw_sye_part) + (gye_error * k_yaw_gye_part) + (aye_error * k_yaw_aye_part) + (wye_error * k_yaw_wye_part);
		else (NO)
			:ye_error = VDY_ZERO_F;
		endif
		if (calculate combined yaw rate (ye) curve error \n vdy_internal_data.vdy_ve_out.veh_velo > MIN_VELO_YAW_RATE_ERROR) then (YES)
			:ye_curve_error = ye_error/(vdy_internal_data.vdy_ve_out.veh_velo);
		else (NO)
			:ye_curve_error = VDY_ZERO_F;
		endif
		:calculate steering angle (sye) curve error \n sye_curve_error = (VDY_ONE_F/input->Parameter.SteeringRatio.swa.rat[1]) * (swa_offset_error / (input->Parameter.WheelBase + (input->Parameter.SelfSteerGrad * CML_Sqr(vdy_internal_data.vdy_ve_out.veh_velo))));
		:calculate combined curve error considering the Kalman gain \n k_curve_sum = vdy_ye_k.K_curve[VDY_TWO] + vdy_ye_k.K_curve[0];
		if ( CML_f_IsNonZero(k_curve_sum) ) then (YES)
			:k_curve_ye_part  = vdy_ye_k.K_curve[0] / k_curve_sum;
			:k_curve_sye_part = vdy_ye_k.K_curve[VDY_TWO] / k_curve_sum;
			:curve_error = (sye_curve_error * k_curve_sye_part) + (ye_curve_error * k_curve_ye_part);
		else (NO)
			:curve_error = VDY_ZERO_F;
		endif
		:return curve_error;
	stop
	@enduml
  @testmethod
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> \n
                            TEST_vdyCalculateCurveError_001(), \n
                            TEST_vdyCalculateCurveError_002(), \n
                            TEST_vdyCalculateCurveError_003(), \n
                            TEST_vdyCalculateCurveError_004(), \n
                            TEST_vdyCalculateCurveError_005(), \n
                            TEST_vdyCalculateCurveError_006()
  @traceability
  - L3
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1720-000221c8
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-704-00026448
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-705-00026448
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-706-00026448
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-707-00026448
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-708-00026448
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-710-00026448
  @author         Frank Wolter
**************************************************************************** */
STATIC_MTD float32 vdyCalculateCurveError(const VDYInputData_t * input, const VDYOffsets_t * pVDYOffsets);


/* *************************************************************************
  @fn              vdyCalculateLaneErrorConf */ /*!
  @brief           Calculate lateral error and confidence of curve

  @description     The lateral error of the curve output is calculated by
                   using the function vdyCalculateCurveError.
                   The confidence is set considering the states of the input
                   signals and the lateral curve error at certain distances
                   (predicted over 1, 2, 3 and 4 seconds).
                   The lateral error must be less than 1.75m at the given
                   distances (higher distance gives a higher confidence).
                   The input states are debounced for 100ms.  Reducing
                   the confidence due to lower distance is delayed by 400ms
                   to avoid a toggling confidence.

  @return          static void

  @param[in]       reqPorts : Request Ports
  @param[in]       input : Curren Input Signal
  @param[in]       pVDYOffsets : VDY Offset Structure
  @param[in,out]   pVehDyn : VehDyn - VDY Ouput Signal Structure

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation 
  - check if all the wheel speeds are not available for 5 cycles
  - check if just one wheel speed is not available for 5 cycles
  - check if yaw rate is not available for 5 cycles
  - check if yaw rate is decreased for 5 cycles
  - check if steering angle is not available for 5 cycles
  - check if steering angle is at low precision for 5 cycles
  - check if lateral acceleration is not available for 5 cycles
  - check if esp is not available for 5 cycles 
  - calculate the curve error and store in output
  - calculate the lateral curve error in x sec distance and set the conf signal
  - if (new conf lower then before and higher than 2?)
							- if(new (lower) conf already calculates for 400ms?) then count hold time of old higher conf else take new lower conf after hold time expired
							- else take new lower conf after hold time expired
  - else higher or equal conf or conf is 2 or lower, take conf value directly
  - Store values in output port
  
	@startuml
	start
		:counter and flags for input signals
		:static uint8 u_all_wheels_qual_not_avail_counter = 0;
		:static boolean b_all_wheels_qual_not_avail = FALSE;
		:static uint8 u_yaw_qual_not_avail_counter = 0;
		:static boolean b_yaw_qual_not_avail = FALSE;
		:static uint8 u_swa_qual_not_avail_counter = 0;
		:static boolean b_swa_qual_not_avail = FALSE;
		:static uint8 u_esp_qual_not_avail_counter = 0;
		:static boolean b_esp_qual_not_avail = FALSE;
		:static uint8 u_yaw_qual_not_def_counter = 0;
		:static boolean b_yaw_qual_not_def = FALSE;
		:static uint8 u_swa_qual_low_precision_counter = 0;
		:static boolean b_swa_qual_low_precision = FALSE;
		:static uint8 u_one_wheel_qual_reduced_counter = 0;
		:static boolean b_one_wheel_qual_reduced = FALSE;
		:static uint8 u_lat_acc_qual_not_avail_counter = 0;
		:static boolean b_lat_acc_qual_not_avail = FALSE;
		:error in curve \n float32 f_CurveError;
		:lateral error in curve \n float32 f_LatError;
		:counter for hold time (before going to lower confidence) \n static uint8 u_conf_counter = 0;
		:curve confidence calculated in this cycle \n static uint8 u_CurveConf = 0;
		:curve confidence output (calculated value might be delayed by hold time) \n static uint8 u_CurveConfOutput = 0;

  if ( check if all the wheel speeds are not available for 5 cycles \n (VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_FL, reqPorts->pVehicleInputSignals->VehSigMain.State) == (VDYIoStateTypes_t)VDY_IO_STATE_INVALID) && (VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_FR, reqPorts->pVehicleInputSignals->VehSigMain.State) == (VDYIoStateTypes_t)VDY_IO_STATE_INVALID) && (VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_RL, reqPorts->pVehicleInputSignals->VehSigMain.State) == (VDYIoStateTypes_t)VDY_IO_STATE_INVALID) && (VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_RR, reqPorts->pVehicleInputSignals->VehSigMain.State) == (VDYIoStateTypes_t)VDY_IO_STATE_INVALID)  ) then (YES)
    if (u_all_wheels_qual_not_avail_counter < MAX_SIGNAL_COUNTER) then (YES)
      :u_all_wheels_qual_not_avail_counter++;   
    else (NO)
      :b_all_wheels_qual_not_avail = TRUE;
    endif
  else (NO)
    :u_all_wheels_qual_not_avail_counter = 0;
    :b_all_wheels_qual_not_avail = FALSE;
  endif

  if (  check if just one wheel speed is not available for 5 cycles \n (VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_FL, reqPorts->pVehicleInputSignals->VehSigMain.State) != (VDYIoStateTypes_t)VDY_IO_STATE_VALID) || (VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_FR, reqPorts->pVehicleInputSignals->VehSigMain.State) != (VDYIoStateTypes_t)VDY_IO_STATE_VALID) || (VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_RL, reqPorts->pVehicleInputSignals->VehSigMain.State) != (VDYIoStateTypes_t)VDY_IO_STATE_VALID) || (VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_RR, reqPorts->pVehicleInputSignals->VehSigMain.State) != (VDYIoStateTypes_t)VDY_IO_STATE_VALID)  ) then (YES)
    if (u_one_wheel_qual_reduced_counter < MAX_SIGNAL_COUNTER) then (YES)
      :u_one_wheel_qual_reduced_counter++;    
    else (NO)
      :b_one_wheel_qual_reduced = TRUE;
    endif
  else (NO)
    :u_one_wheel_qual_reduced_counter = 0;
    :b_one_wheel_qual_reduced = FALSE;
  endif

  if (check if yaw rate is not available for 5 cycles \n VDY_GET_IO_STATE(VDY_SIN_POS_YWR, reqPorts->pVehicleInputSignals->VehSigMain.State) == (VDYIoStateTypes_t)VDY_IO_STATE_INVALID) then (YES)
    if (u_yaw_qual_not_avail_counter < MAX_SIGNAL_COUNTER) then (YES)
      :u_yaw_qual_not_avail_counter++;
    else (NO)
      :b_yaw_qual_not_avail = TRUE;
    endif
  else (NO)
    :u_yaw_qual_not_avail_counter = 0;
    :b_yaw_qual_not_avail = FALSE;
  endif
  if (check if yaw rate is decreased for 5 cycles \n VDY_GET_IO_STATE(VDY_SIN_POS_YWR, reqPorts->pVehicleInputSignals->VehSigMain.State) == (VDYIoStateTypes_t)VDY_IO_STATE_DECREASED) then (YES)
	  if (u_yaw_qual_not_def_counter < MAX_SIGNAL_COUNTER) then (YES)
		  :u_yaw_qual_not_def_counter++;
	  else
		  :b_yaw_qual_not_def = TRUE;
	  endif
  else (NO)
	:u_yaw_qual_not_def_counter = 0;
	:b_yaw_qual_not_def = FALSE;
  endif

  if (check if steering angle is not available for 5 cycles \n VDY_GET_IO_STATE(VDY_SIN_POS_SWA, reqPorts->pVehicleInputSignals->VehSigMain.State) == (VDYIoStateTypes_t)(VDYIoStateTypes_t)VDY_IO_STATE_INVALID) then (YES)
	  if (u_swa_qual_not_avail_counter < MAX_SIGNAL_COUNTER) then (YES)
		  :u_swa_qual_not_avail_counter++;
	  else (NO)
		  :b_swa_qual_not_avail = TRUE;
	  endif
  else (NO)
	:u_swa_qual_not_avail_counter = 0;
	:b_swa_qual_not_avail = FALSE;
  endif

  if (check if steering angle is at low precision for 5 cycles \n VDY_GET_IO_STATE(VDY_SIN_POS_SWA, reqPorts->pVehicleInputSignals->VehSigMain.State) == (VDYIoStateTypes_t)VDY_IO_STATE_DECREASED) then (YES)
	  if (u_swa_qual_low_precision_counter < MAX_SIGNAL_COUNTER) then (YES)
		  :u_swa_qual_low_precision_counter++;
	  else (NO)
		  :b_swa_qual_low_precision = TRUE;
	  endif
  else (NO)
	:u_swa_qual_low_precision_counter = 0;
    :b_swa_qual_low_precision = FALSE;
  endif

  if (check if lateral acceleration is not available for 5 cycles \n VDY_GET_IO_STATE(VDY_SIN_POS_LATA, reqPorts->pVehicleInputSignals->VehSigMain.State) != (VDYIoStateTypes_t)VDY_IO_STATE_VALID) then (YES)
	  if (u_lat_acc_qual_not_avail_counter < MAX_SIGNAL_COUNTER) then (YES)
		:u_lat_acc_qual_not_avail_counter++;
	else (NO)
		:b_lat_acc_qual_not_avail = TRUE;
	endif
  else (NO)
	:u_lat_acc_qual_not_avail_counter = 0;
    :b_lat_acc_qual_not_avail = FALSE;
  endif

  if (check if esp is not available for 5 cycles \n VDY_GET_IO_STATE(VEH_SIG_BRAKE_ABS, reqPorts->pVehicleInputSignals->Brake.State) != (VDYIoStateTypes_t)VDY_IO_STATE_VALID) then (YES)
		if (u_esp_qual_not_avail_counter < MAX_SIGNAL_COUNTER) then (YES)
			:u_esp_qual_not_avail_counter++;
		else (NO)
			:b_esp_qual_not_avail = TRUE;
		endif
	else (NO)
		:u_esp_qual_not_avail_counter = 0;
		:b_esp_qual_not_avail = FALSE;
	endif

	if (calculate the curve error and store in output \n CFG_VDY_USE_EXT_PROC_CURVATURE) then (YES)
		:For external curvature ,curve error is hardcoded to 0.0002. As per ACC "For a 100m Safety Distance, required curve error is 0.000175" \n f_CurveError = 0.0002f;
	else  (NO)
		:f_CurveError = vdyCalculateCurveError(input, pVDYOffsets);
	endif

  if (if curve output is not available \n (VDY_GET_IO_STATE(VDY_SOUT_POS_CURVE, pVehDyn->State) != (VDYIoStateTypes_t)VDY_IO_STATE_VALID) &&
      (VDY_GET_IO_STATE(VDY_SOUT_POS_CURVE, pVehDyn->State) != (VDYIoStateTypes_t)VDY_IO_STATE_DECREASED)) then (YES)
		:u_CurveConf = 0;
  else (NO)
    if ( if both yaw rate and steering angle offset are not available, or either yaw rate, steering angle or ESP are not available or all wheel inputs are not available \n   
			(((pVDYOffsets->Ywr.StandStillState == (sint32)OUT_YWR_OFFS_NON) || 
			(pVDYOffsets->Ywr.StandStillState == (sint32)OUT_YWR_OFFS_STANDST_EEPROM)) && (pVDYOffsets->Swa.State == 0))|| 
			(b_swa_qual_not_avail == (boolean)TRUE) || (b_yaw_qual_not_avail == (boolean)TRUE) || (b_esp_qual_not_avail == (boolean)TRUE) || (b_all_wheels_qual_not_avail == (boolean)TRUE)) then (YES)
		:u_CurveConf = 1;
    else if ( if only one offset is available, the yaw rate offset is too high, steering angle is at low precision, yaw rate is degraded, lat accel or one of the wheel inputs are not available \n   
			(CML_f_Abs(pVDYOffsets->Ywr.StandStillOffset) > YWR_OFFS_LIMIT) || 
			((pVDYOffsets->Ywr.StandStillState == (sint32)OUT_YWR_OFFS_NON) || (pVDYOffsets->Ywr.StandStillState == (sint32)OUT_YWR_OFFS_STANDST_EEPROM) || (pVDYOffsets->Swa.State == 0)) || 
			(b_swa_qual_low_precision == (boolean)TRUE) || (b_yaw_qual_not_def == (boolean)TRUE) || ((b_lat_acc_qual_not_avail == (boolean)TRUE) && (pVDYOffsets->Ywr.StandStillState == (sint32)OUT_YWR_OFFS_DYN)) || ((b_one_wheel_qual_reduced == (boolean)TRUE) && 
			(pVDYOffsets->Ywr.StandStillState == (sint32)OUT_YWR_OFFS_DYN))  ) then (YES)
      :u_CurveConf = VDY_TWO_U;
    else (NO)
      :calculate the lateral curve error in x sec distance and set the conf signal
      :distance in 4 seconds \n f_LatError = vdyCalculateCurveLatDistance(VDY_ZERO_F, f_CurveError, TIME_DIST_CONF_6 * vdy_internal_data.vdy_ve_out.veh_velo); 
      if (f_LatError <= MAX_LAT_ERROR) then (YES)
		  :u_CurveConf = VDY_SIX_U;
	  else (NO)
        :distance in 3 seconds \n f_LatError = vdyCalculateCurveLatDistance(VDY_ZERO_F, f_CurveError, TIME_DIST_CONF_5 * vdy_internal_data.vdy_ve_out.veh_velo);
        if (f_LatError <= MAX_LAT_ERROR) then (YES)
          :u_CurveConf = VDY_FIVE_U;
        else (NO)
          :distance in 2 seconds \n f_LatError = vdyCalculateCurveLatDistance(VDY_ZERO_F, f_CurveError, TIME_DIST_CONF_4 * vdy_internal_data.vdy_ve_out.veh_velo);
          if (f_LatError <= MAX_LAT_ERROR) then (YES)
            :u_CurveConf = VDY_FOUR_U;
          else
            : distance in 1 second \n f_LatError = vdyCalculateCurveLatDistance(VDY_ZERO_F, f_CurveError, TIME_DIST_CONF_3 * vdy_internal_data.vdy_ve_out.veh_velo);
            if (f_LatError <= MAX_LAT_ERROR) then (YES)
              :u_CurveConf = VDY_THREE_U;
            else (NO)
              :u_CurveConf = VDY_TWO_U;
			endif
          endif
		endif
	endif
  endif
endif

  if (new conf lower then before and higher than 2? \n (u_CurveConfOutput > u_CurveConf) && (u_CurveConf > VDY_TWO_U)) then (YES)
	  if (new (lower) conf already calculates for 400ms? \n u_conf_counter < MAX_HOLD_TIME) then (YES)
		  :count hold time of old higher conf \n u_conf_counter++;
	  else (NO)
		  :take new lower conf after hold time expired \n u_CurveConfOutput = u_CurveConf;
	  endif
  else (NO)
	  :higher or equal conf or conf is 2 or lower, take conf value directly \n u_conf_counter = 0 \n u_CurveConfOutput = u_CurveConf;
  endif
	  :Store values in output port \n pVehDyn->Lateral.Curve.CrvConf = u_CurveConfOutput \n pVehDyn->Lateral.Curve.CrvError = f_CurveError;
	stop
	@enduml
  @testmethod
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> \n
                            TEST_vdyCalculateLaneErrorConf_001(),
                            TEST_vdyCalculateLaneErrorConf_002(),
                            TEST_vdyCalculateLaneErrorConf_003(),
                            TEST_vdyCalculateLaneErrorConf_004(),
                            TEST_vdyCalculateLaneErrorConf_005(),
                            TEST_vdyCalculateLaneErrorConf_006(),
                            TEST_vdyCalculateLaneErrorConf_007(),
                            TEST_vdyCalculateLaneErrorConf_008(),
                            TEST_vdyCalculateLaneErrorConf_009(),
                            TEST_vdyCalculateLaneErrorConf_010(),
                            TEST_vdyCalculateLaneErrorConf_011(),
                            TEST_vdyCalculateLaneErrorConf_012(),
                            TEST_vdyCalculateLaneErrorConf_013(),
                            TEST_vdyCalculateLaneErrorConf_014(),
                            TEST_vdyCalculateLaneErrorConf_015(),
                            TEST_vdyCalculateLaneErrorConf_016(),
                            TEST_vdyCalculateLaneErrorConf_017(),
                            TEST_vdyCalculateLaneErrorConf_018(),
                            TEST_vdyCalculateLaneErrorConf_019(),
                            TEST_vdyCalculateLaneErrorConf_020(),
                            TEST_vdyCalculateLaneErrorConf_021(),
                            TEST_vdyCalculateLaneErrorConf_022(),
                            TEST_vdyCalculateLaneErrorConf_023(),
                            TEST_vdyCalculateLaneErrorConf_024(),
                            TEST_vdyCalculateLaneErrorConf_025(),
                            TEST_vdyCalculateLaneErrorConf_026(),
                            TEST_vdyCalculateLaneErrorConf_027(),
                            TEST_vdyCalculateLaneErrorConf_028(),
                            TEST_vdyCalculateLaneErrorConf_029(),
                            TEST_vdyCalculateLaneErrorConf_030(),
                            TEST_vdyCalculateLaneErrorConf_031(),
                            TEST_vdyCalculateLaneErrorConf_032(),
                            TEST_vdyCalculateLaneErrorConf_033(),
                            TEST_vdyCalculateLaneErrorConf_034(),
                            TEST_vdyCalculateLaneErrorConf_035(),
                            TEST_vdyCalculateLaneErrorConf_036(),
                            TEST_vdyCalculateLaneErrorConf_037(),
                            TEST_vdyCalculateLaneErrorConf_038(),
                            TEST_vdyCalculateLaneErrorConf_039(),
                            TEST_vdyCalculateLaneErrorConf_040(),
                            TEST_vdyCalculateLaneErrorConf_041(),
                            TEST_vdyCalculateLaneErrorConf_042(),
                            TEST_vdyCalculateLaneErrorConf_043(),
                            TEST_vdyCalculateLaneErrorConf_044()
  @traceability	
  - L3
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1462-000221c8 
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1463-000221c8 
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1464-000221c8 
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1465-000221c8 
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1466-000221c8 
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1467-000221c8
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1468-000221c8 
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1760-000221c8
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1469-000221c8
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1470-000221c8
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1471-000221c8
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1473-000221c8
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1474-000221c8
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1475-000221c8
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1476-000221c8
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1477-000221c8
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1478-000221c8
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1479-000221c8
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1480-000221c8
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1481-000221c8
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1482-000221c8
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1483-000221c8
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1484-000221c8
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1486-000221c8
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1487-000221c8
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-714-00026448
 
  @author         Frank Wolter
**************************************************************************** */
STATIC_MTD void vdyCalculateLaneErrorConf(const reqVdyPrtList_t * reqPorts, const VDYInputData_t * input, const VDYOffsets_t * pVDYOffsets, VehDyn_t * pVehDyn);


/* *************************************************************************
  @fn              vdyCopyInputSignals */ /*!
  @brief           Copies input signals from VehSig into VDYIn

  @description     All input signals in VehSigMain are copied into VDYIn
                   for internal use.
                   Some input signals are debounced to avoid a fault
                   reaction for invalid input signals if the signal
                   is only invalid for a very brief time
                   (e.g. short bus faults or sporadic timing issues)

  @return          static void

  @param[in,out]   p_Input : Internal input signal structure
  @param[in]       p_VehSigMain : VehSigMain signal structure

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation
					- Copy all input signals in VehSigMain into VDYIn
						- external yaw rate and temperature
						- steering angle 
						- lateral acceleration
						- wheel speeds
						- internal yaw rate and temperature
						- internal longitudinal acceleration
						- rear wheel steering angle
						- external longitudinal velocity and acceleration 
						- wheel rolling directions 
						- wheel pulses
						- gear position
						- brake activation level
						- parking brake state
						- external driving direction 
						- external motion state
						- external lateral curvature
						- external side slip angle

  
	@startuml
	start
		:External Yaw Rate\n 
			vdyFCheckInputSignals(&p_Input->YawRate, p_VehSigMain->YawRate, &s_LastInputSignals.YawRate, 
                          &p_Input->State[VDY_SIN_POS_YWR], p_VehSigMain->State[VDY_SIN_POS_YWR], &s_LastInputSignals.State[VDY_SIN_POS_YWR],
                          &u_DebouceCounter[VDY_SIN_POS_YWR]);
		:External Yaw Rate Temperature \n
			vdyFCheckInputSignals(&p_Input->YawRateTemp, p_VehSigMain->YawRateTemp, &s_LastInputSignals.YawRateTemp,
                          &p_Input->State[VDY_SIN_POS_YWR_TEMP], p_VehSigMain->State[VDY_SIN_POS_YWR_TEMP], &s_LastInputSignals.State[VDY_SIN_POS_YWR_TEMP],
                          &u_DebouceCounter[VDY_SIN_POS_YWR_TEMP]);
		:Steering Angle
			vdyFCheckInputSignals(&p_Input->StWheelAngle, p_VehSigMain->StWheelAngle, &s_LastInputSignals.StWheelAngle,
                          &p_Input->State[VDY_SIN_POS_SWA], p_VehSigMain->State[VDY_SIN_POS_SWA], &s_LastInputSignals.State[VDY_SIN_POS_SWA],
                          &u_DebouceCounter[VDY_SIN_POS_SWA]);
						  
		:Lateral Acceleration \n
			vdyFCheckInputSignals(&p_Input->LatAccel, p_VehSigMain->LatAccel, &s_LastInputSignals.LatAccel,
                          &p_Input->State[VDY_SIN_POS_LATA], p_VehSigMain->State[VDY_SIN_POS_LATA], &s_LastInputSignals.State[VDY_SIN_POS_LATA],
                          &u_DebouceCounter[VDY_SIN_POS_LATA]);

		:Wheel Speeds - Front Left \n
			vdyFCheckInputSignals(&p_Input->WhlVelFrLeft, p_VehSigMain->WhlVelFrLeft, &s_LastInputSignals.WhlVelFrLeft,
                          &p_Input->State[VDY_SIN_POS_WVEL_FL], p_VehSigMain->State[VDY_SIN_POS_WVEL_FL], &s_LastInputSignals.State[VDY_SIN_POS_WVEL_FL],
                          &u_DebouceCounter[VDY_SIN_POS_WVEL_FL]);
		:Wheel Speeds - Front Right \n
			vdyFCheckInputSignals(&p_Input->WhlVelFrRight, p_VehSigMain->WhlVelFrRight, &s_LastInputSignals.WhlVelFrRight,
                          &p_Input->State[VDY_SIN_POS_WVEL_FR], p_VehSigMain->State[VDY_SIN_POS_WVEL_FR], &s_LastInputSignals.State[VDY_SIN_POS_WVEL_FR],
                          &u_DebouceCounter[VDY_SIN_POS_WVEL_FR]);
						  
		:Wheel Speeds - Rear Left \n
			vdyFCheckInputSignals(&p_Input->WhlVelReLeft, p_VehSigMain->WhlVelReLeft, &s_LastInputSignals.WhlVelReLeft,
                          &p_Input->State[VDY_SIN_POS_WVEL_RL], p_VehSigMain->State[VDY_SIN_POS_WVEL_RL], &s_LastInputSignals.State[VDY_SIN_POS_WVEL_RL],
                          &u_DebouceCounter[VDY_SIN_POS_WVEL_RL]);
						
		:Wheel Speeds - Rear Right \n
			vdyFCheckInputSignals(&p_Input->WhlVelReRight, p_VehSigMain->WhlVelReRight, &s_LastInputSignals.WhlVelReRight,
                          &p_Input->State[VDY_SIN_POS_WVEL_RR], p_VehSigMain->State[VDY_SIN_POS_WVEL_RR], &s_LastInputSignals.State[VDY_SIN_POS_WVEL_RR],
                          &u_DebouceCounter[VDY_SIN_POS_WVEL_RR]);
						  
		:Internal Yaw Rate \n
			vdyFCheckInputSignals(&p_Input->YawRateInt, p_VehSigMain->YawRateInt, &s_LastInputSignals.YawRateInt,
                          &p_Input->State[VDY_SIN_POS_YWRINT], p_VehSigMain->State[VDY_SIN_POS_YWRINT], &s_LastInputSignals.State[VDY_SIN_POS_YWRINT],
                          &u_DebouceCounter[VDY_SIN_POS_YWRINT]);
			
		:Internal Yaw Rate Temperature 
			vdyFCheckInputSignals(&p_Input->YawRateIntTemp, p_VehSigMain->YawRateIntTemp, &s_LastInputSignals.YawRateIntTemp,
                          &p_Input->State[VDY_SIN_POS_YWRINT_TEMP], p_VehSigMain->State[VDY_SIN_POS_YWRINT_TEMP], &s_LastInputSignals.State[VDY_SIN_POS_YWRINT_TEMP],
                          &u_DebouceCounter[VDY_SIN_POS_YWRINT_TEMP]);
						  
		:Internal Longitudinal Acceleration \n
			vdyFCheckInputSignals(&p_Input->LongAccel, p_VehSigMain->LongAccel, &s_LastInputSignals.LongAccel,
                          &p_Input->State[VDY_SIN_POS_LONGA], p_VehSigMain->State[VDY_SIN_POS_LONGA], &s_LastInputSignals.State[VDY_SIN_POS_LONGA],
                          &u_DebouceCounter[VDY_SIN_POS_LONGA]);

		:Rear Wheel Steering Angle \n
			vdyFCheckInputSignals(&p_Input->RearWhlAngle, p_VehSigMain->RearWhlAngle, &s_LastInputSignals.RearWhlAngle,
                          &p_Input->State[VDY_SIN_POS_RSTA], p_VehSigMain->State[VDY_SIN_POS_RSTA], &s_LastInputSignals.State[VDY_SIN_POS_RSTA],
                          &u_DebouceCounter[VDY_SIN_POS_RSTA]);
						  
		:External longitudinal velocity \n
			vdyFCheckInputSignals(&p_Input->VehVelocityExt, p_VehSigMain->VehVelocityExt, &s_LastInputSignals.VehVelocityExt,
                          &p_Input->State[VDY_SIN_POS_VEHVEL_EXT], p_VehSigMain->State[VDY_SIN_POS_VEHVEL_EXT], &s_LastInputSignals.State[VDY_SIN_POS_VEHVEL_EXT],
                          &u_DebouceCounter[VDY_SIN_POS_VEHVEL_EXT]);
						  
		:External longitudinal acceleration \n
			vdyFCheckInputSignals(&p_Input->VehLongAccelExt, p_VehSigMain->VehLongAccelExt, &s_LastInputSignals.VehLongAccelExt,
                          &p_Input->State[VDY_SIN_POS_VEHACL_EXT], p_VehSigMain->State[VDY_SIN_POS_VEHACL_EXT], &s_LastInputSignals.State[VDY_SIN_POS_VEHACL_EXT],
                          &u_DebouceCounter[VDY_SIN_POS_VEHACL_EXT]);

		:Wheel Rolling Direction - Front Left \n
			vdyUCheckInputSignals(&p_Input->WhlDirFrLeft, p_VehSigMain->WhlDirFrLeft, &s_LastInputSignals.WhlDirFrLeft,
                          &p_Input->State[VDY_SIN_POS_WDIR_FL], p_VehSigMain->State[VDY_SIN_POS_WDIR_FL], &s_LastInputSignals.State[VDY_SIN_POS_WDIR_FL],
                          &u_DebouceCounter[VDY_SIN_POS_WDIR_FL]);

		:Wheel Rolling Direction - Front Right \n
			vdyUCheckInputSignals(&p_Input->WhlDirFrRight, p_VehSigMain->WhlDirFrRight, &s_LastInputSignals.WhlDirFrRight,
                          &p_Input->State[VDY_SIN_POS_WDIR_FR], p_VehSigMain->State[VDY_SIN_POS_WDIR_FR], &s_LastInputSignals.State[VDY_SIN_POS_WDIR_FR],
                          &u_DebouceCounter[VDY_SIN_POS_WDIR_FR]);
						  
		:Wheel Rolling Direction - Rear Left \n
			vdyUCheckInputSignals(&p_Input->WhlDirReLeft, p_VehSigMain->WhlDirReLeft, &s_LastInputSignals.WhlDirReLeft,
                          &p_Input->State[VDY_SIN_POS_WDIR_RL], p_VehSigMain->State[VDY_SIN_POS_WDIR_RL], &s_LastInputSignals.State[VDY_SIN_POS_WDIR_RL],
                          &u_DebouceCounter[VDY_SIN_POS_WDIR_RL]);

		:Wheel Rolling Direction - Rear Right \n
			vdyUCheckInputSignals(&p_Input->WhlDirReRight, p_VehSigMain->WhlDirReRight, &s_LastInputSignals.WhlDirReRight,
                          &p_Input->State[VDY_SIN_POS_WDIR_RR], p_VehSigMain->State[VDY_SIN_POS_WDIR_RR], &s_LastInputSignals.State[VDY_SIN_POS_WDIR_RR],
                          &u_DebouceCounter[VDY_SIN_POS_WDIR_RR]);
						  
		:Wheel Pulses - Front Left \n
			vdyUCheckInputSignals(&p_Input->WhlTicksDevFrLeft, p_VehSigMain->WhlTicksDevFrLeft, &s_LastInputSignals.WhlTicksDevFrLeft,
                          &p_Input->State[VDY_SIN_POS_WTCKS_FL], p_VehSigMain->State[VDY_SIN_POS_WTCKS_FL], &s_LastInputSignals.State[VDY_SIN_POS_WTCKS_FL],
                          &u_DebouceCounter[VDY_SIN_POS_WTCKS_FL]);
						  
		:Wheel Pulses - Front Right \n
			vdyUCheckInputSignals(&p_Input->WhlTicksDevFrRight, p_VehSigMain->WhlTicksDevFrRight, &s_LastInputSignals.WhlTicksDevFrRight,
                          &p_Input->State[VDY_SIN_POS_WTCKS_FR], p_VehSigMain->State[VDY_SIN_POS_WTCKS_FR], &s_LastInputSignals.State[VDY_SIN_POS_WTCKS_FR],
                          &u_DebouceCounter[VDY_SIN_POS_WTCKS_FR]);
						  
		:Wheel Pulses - Rear Left \n
			vdyUCheckInputSignals(&p_Input->WhlTicksDevReLeft, p_VehSigMain->WhlTicksDevReLeft, &s_LastInputSignals.WhlTicksDevReLeft,
                          &p_Input->State[VDY_SIN_POS_WTCKS_RL], p_VehSigMain->State[VDY_SIN_POS_WTCKS_RL], &s_LastInputSignals.State[VDY_SIN_POS_WTCKS_RL],
                          &u_DebouceCounter[VDY_SIN_POS_WTCKS_RL]);
						  
		:Wheel Pulses - Rear Right \n
			vdyUCheckInputSignals(&p_Input->WhlTicksDevReRight, p_VehSigMain->WhlTicksDevReRight, &s_LastInputSignals.WhlTicksDevReRight,
                          &p_Input->State[VDY_SIN_POS_WTCKS_RR], p_VehSigMain->State[VDY_SIN_POS_WTCKS_RR], &s_LastInputSignals.State[VDY_SIN_POS_WTCKS_RR],
                          &u_DebouceCounter[VDY_SIN_POS_WTCKS_RR]);
						  
		:Gear Position
			vdyUCheckInputSignals(&p_Input->ActGearPos, p_VehSigMain->ActGearPos, &s_LastInputSignals.ActGearPos,
                          &p_Input->State[VDY_SIN_POS_GEAR], p_VehSigMain->State[VDY_SIN_POS_GEAR], &s_LastInputSignals.State[VDY_SIN_POS_GEAR],
                          &u_DebouceCounter[VDY_SIN_POS_GEAR]);
						  
		:Brake Activation Level \n
			p_Input->BrakeActLevel = 0U \n 
			vdySCheckInputSignals(&p_Input->BrakeActLevel, p_VehSigMain->BrakeActLevel, &s_LastInputSignals.BrakeActLevel,
                          &p_Input->State[VDY_SIN_POS_BRAKE], p_VehSigMain->State[VDY_SIN_POS_BRAKE], &s_LastInputSignals.State[VDY_SIN_POS_BRAKE],
                          &u_DebouceCounter[VDY_SIN_POS_BRAKE]);
						  
		:Parking Brake State \n
			vdyUCheckInputSignals(&p_Input->ParkBrakeState, p_VehSigMain->ParkBrakeState, &s_LastInputSignals.ParkBrakeState,
                          &p_Input->State[VDY_SIN_POS_PBRK], p_VehSigMain->State[VDY_SIN_POS_PBRK], &s_LastInputSignals.State[VDY_SIN_POS_PBRK],
                          &u_DebouceCounter[VDY_SIN_POS_PBRK]);

		:External Driving Direction \n
			vdyUCheckInputSignals(&p_Input->VehLongDirExt, p_VehSigMain->VehLongDirExt, &s_LastInputSignals.VehLongDirExt,
                          &p_Input->State[VDY_SIN_POS_VDIR], p_VehSigMain->State[VDY_SIN_POS_VDIR], &s_LastInputSignals.State[VDY_SIN_POS_VDIR],
                          &u_DebouceCounter[VDY_SIN_POS_VDIR]);
						  
		:External Motion State \n
			vdyUCheckInputSignals(&p_Input->VehLongMotStateExt, p_VehSigMain->VehLongMotStateExt, &s_LastInputSignals.VehLongMotStateExt,
                          &p_Input->State[VDY_SIN_POS_VMOT], p_VehSigMain->State[VDY_SIN_POS_VMOT], &s_LastInputSignals.State[VDY_SIN_POS_VMOT],
                          &u_DebouceCounter[VDY_SIN_POS_VMOT]);
						 
		:External Lateral Curvature \n 
			vdyFCheckInputSignals(&p_Input->CurveC0Ext, p_VehSigMain->CurveC0Ext, &s_LastInputSignals.CurveC0Ext,
                          &p_Input->State[VDY_SIN_POS_CRV], p_VehSigMain->State[VDY_SIN_POS_CRV], &s_LastInputSignals.State[VDY_SIN_POS_CRV],
                          &u_DebouceCounter[VDY_SIN_POS_CRV]) \n 
			vdyFCheckInputSignals(&p_Input->CurveC1Ext, p_VehSigMain->CurveC1Ext, &s_LastInputSignals.CurveC1Ext,
                          &p_Input->State[VDY_SIN_POS_CRV], p_VehSigMain->State[VDY_SIN_POS_CRV], &s_LastInputSignals.State[VDY_SIN_POS_CRV],
                          &u_DebouceCounter[VDY_SIN_POS_CRV]);

		:External side slip angle \n 
			vdyFCheckInputSignals(&p_Input->SideSlipAngleExt, p_VehSigMain->SideSlipAngleExt, &s_LastInputSignals.SideSlipAngleExt,
                          &p_Input->State[VDY_SIN_POS_SSA], p_VehSigMain->State[VDY_SIN_POS_SSA], &s_LastInputSignals.State[VDY_SIN_POS_SSA],
                          &u_DebouceCounter[VDY_SIN_POS_SSA]);
	
	stop
	@enduml
  @testmethod
	- NA
  @traceability
    - NA
  @author         Frank Wolter
**************************************************************************** */
STATIC_MTD void vdyCopyInputSignals(VehSigMain_t * p_Input, const VehSigMain_t * p_VehSigMain);


/* *************************************************************************
  @fn              vdyFCheckInputSignals */ /*!
  @brief           Debounces invalid float type input signals

  @description     A signal which has the state 'invalid' or 'not available'
                   (= timeout) is kept at the last valid input signal and state
                   for VDY_MAX_INPUT_DEBOUNCING cycles.

  @return          static void

  @param[in,out]   p_InputSignal		: Current Input Signal
  @param[in]       f_VehSigMainSignal	: Current VehSigMain signals
  @param[in,out]   p_LastSignal			: Last Input Signal
  @param[in,out]   p_VDYInState			: Input Signal State
  @param[in]       e_VehSigState		: Signal Validity
  @param[in,out]   p_LastState			: Last Signal Validity
  @param[in,out]   p_DebouceCounter		: Debounce Counter

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation	
					  - if invalid and not available signals are debounced, all other states are valid inputs
												- if no debouncing any more, take input value else keep old value and increase counter
					  - else take new value and state, reset debounce counter and store current signal and state for next cycle
  

	@startuml
	start
		:invalid and not available signals are debounced, all other states are valid inputs;
		if ((e_VehSigState == (VDYIoStateTypes_t)VDY_IO_STATE_INVALID) || (e_VehSigState == (VDYIoStateTypes_t)VDY_IO_STATE_NOTAVAIL)) then (YES)
			if (*p_DebouceCounter >= VDY_MAX_INPUT_DEBOUNCING) then (YES)
				:no debouncing any more, take input value \n *p_InputSignal = f_VehSigMainSignal \n *p_VDYInState = e_VehSigState \n *p_LastSignal = f_VehSigMainSignal \n *p_LastState = e_VehSigState;
			else (NO)
				:keep old value and increase counter \n (*p_DebouceCounter)++ \n *p_InputSignal = *p_LastSignal \n *p_VDYInState = *p_LastState;
			endif
		else (NO)
			:take new value and state \n *p_InputSignal = f_VehSigMainSignal \n *p_VDYInState = e_VehSigState;
			:reset debounce counter \n *p_DebouceCounter = 0U;
			:store current signal and state for next cycle \n *p_LastSignal = f_VehSigMainSignal \n *p_LastState = e_VehSigState;
		endif
	stop
	@enduml
  @testmethod
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> TEST_vdyFCheckInputSignals_001()
  @traceability
  - L3
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1500-000221c8
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1501-000221c8
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1502-000221c8 
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1503-000221c8 
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1504-000221c8 
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1505-000221c8
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-701-00026448
  @author         Frank Wolter
**************************************************************************** */
STATIC_MTD void vdyFCheckInputSignals(float32 * p_InputSignal, float32 f_VehSigMainSignal, float32 * p_LastSignal, VDYIoStateTypes_t * p_VDYInState, VDYIoStateTypes_t e_VehSigState, VDYIoStateTypes_t * p_LastState, uint8 * p_DebouceCounter);


/* *************************************************************************
  @fn             vdyUCheckInputSignals */ /*!
  @brief           Debounces invalid unsigned byte type input signals

  @description     A signal which has the state 'invalid' or 'not available'
                   (= timeout) is kept at the last valid input signal and state
                   for VDY_MAX_INPUT_DEBOUNCING cycles.

  @return          static void

  @param[in,out]   p_InputSignal		: Current Input Signal
  @param[in]       u_VehSigMainSignal	: Current VehSigMain signals
  @param[in,out]   p_LastSignal			: Last Input Signal
  @param[in,out]   p_VDYInState			: Input Signal State
  @param[in]       e_VehSigState		: Signal Validity
  @param[in,out]   p_LastState			: Last Signal Validity
  @param[in,out]   p_DebouceCounter		: Debounce Counter

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation
				  - if invalid and not available signals are debounced, all other states are valid inputs
											- if no debouncing any more, take input value else keep old value and increase counter
				  - else take new value and state, reset debounce counter and store current signal and state for next cycle

  
	@startuml
	start
		if (invalid and not available signals are debounced, all other states are valid inputs \n (e_VehSigState == (VDYIoStateTypes_t)VDY_IO_STATE_INVALID) || (e_VehSigState == (VDYIoStateTypes_t)VDY_IO_STATE_NOTAVAIL)) then (YES)
			if (*p_DebouceCounter >= VDY_MAX_INPUT_DEBOUNCING) then (YES)
				:no debouncing any more, take input value \n *p_InputSignal = u_VehSigMainSignal \n *p_VDYInState = e_VehSigState \n *p_LastSignal = u_VehSigMainSignal \n *p_LastState = e_VehSigState;
			else (NO)
				:keep old value and increase counter \n (*p_DebouceCounter)++ \n *p_InputSignal = *p_LastSignal \n *p_VDYInState = *p_LastState;
			endif
		else (NO)
			:take new value and state \n *p_InputSignal = u_VehSigMainSignal \n *p_VDYInState = e_VehSigState;
			:reset debounce counter \n *p_DebouceCounter = 0U;
			:store current signal and state for next cycle \n *p_LastSignal = u_VehSigMainSignal \n *p_LastState = e_VehSigState;
		endif
	stop
	@enduml

  @testmethod
  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> TEST_vdyUCheckInputSignals_001(), TEST_vdyUCheckInputSignals_002(), TEST_vdyUCheckInputSignals_003(), TEST_vdyUCheckInputSignals_004()
	- Algo Req Test
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-2588-0002220d
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-2592-0002220d
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-2600-0002220d
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-2604-0002220d
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-2608-0002220d
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-2612-0002220d
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-2617-0002220d
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-2625-0002220d
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-2629-0002220d

  @traceability
  - L3
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1500-000221c8
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1501-000221c8
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1502-000221c8 
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1503-000221c8 
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1504-000221c8 
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1505-000221c8
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-701-00026448
  @author         Frank Wolter
**************************************************************************** */
STATIC_MTD void vdyUCheckInputSignals(uint8 * p_InputSignal, uint8 u_VehSigMainSignal, uint8 * p_LastSignal, VDYIoStateTypes_t * p_VDYInState, VDYIoStateTypes_t e_VehSigState, VDYIoStateTypes_t * p_LastState, uint8 * p_DebouceCounter);


/* *************************************************************************
  @fn             vdySCheckInputSignals */ /*!
  @brief          Debounces invalid unsigned short type input signals

  @description    A signal which has the state 'invalid' or 'not available'
                  (= timeout) is kept at the last valid input signal and state
                  for VDY_MAX_INPUT_DEBOUNCING cycles.

  @param[in,out]   p_InputSignal		: Current Input Signal
  @param[in]       u_VehSigMainSignal	: Current VehSigMain signals
  @param[in,out]   p_LastSignal			: Last Input Signal
  @param[in,out]   p_VDYInState			: Input Signal State
  @param[in]       e_VehSigState		: Signal Validity
  @param[in,out]   p_LastState			: Last Signal Validity
  @param[in,out]   p_DebouceCounter		: Debounce Counter

  @return         static void

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation
				  A signal which has the state 'invalid' or 'not available'
                  (= timeout) is kept at the last valid input signal and state
                  for VDY_MAX_INPUT_DEBOUNCING cycles.
  
	@startuml
	start
		if (invalid and not available signals are debounced, all other states are valid inputs \n (e_VehSigState == (VDYIoStateTypes_t)VDY_IO_STATE_INVALID) || (e_VehSigState == (VDYIoStateTypes_t)VDY_IO_STATE_NOTAVAIL)) then (YES)
			if (*p_DebouceCounter >= VDY_MAX_INPUT_DEBOUNCING) then (YES)
				:no debouncing any more, take input value \n *p_InputSignal = u_VehSigMainSignal \n *p_VDYInState = e_VehSigState \n *p_LastSignal = u_VehSigMainSignal \n *p_LastState = e_VehSigState;
			else (NO)
				:keep old value and increase counter \n (*p_DebouceCounter)++ \n *p_InputSignal = *p_LastSignal \n *p_VDYInState = *p_LastState;
			endif
		else (NO)
			:take new value and state \n *p_InputSignal = u_VehSigMainSignal \n *p_VDYInState = e_VehSigState;
			:reset debounce counter \n *p_DebouceCounter = 0U;
			:store current signal and state for next cycle \n *p_LastSignal = u_VehSigMainSignal \n *p_LastState = e_VehSigState;
		endif
	stop
	@enduml
  @testmethod
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> TEST_vdySCheckInputSignals_001(), TEST_vdySCheckInputSignals_002(), TEST_vdySCheckInputSignals_003()
  @traceability
  - L3
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1500-000221c8
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1501-000221c8
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1502-000221c8 
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1503-000221c8 
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1504-000221c8 
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1505-000221c8
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-701-00026448
  @author         Yugesh Raj Mani
**************************************************************************** */
STATIC_MTD void vdySCheckInputSignals(uint16 * p_InputSignal, uint16 u_VehSigMainSignal, uint16 * p_LastSignal, VDYIoStateTypes_t * p_VDYInState, VDYIoStateTypes_t e_VehSigState, VDYIoStateTypes_t * p_LastState, uint8 * p_DebouceCounter);

#if ( defined(CFG_VDY_SET_DEM_EVENTS) && (CFG_VDY_SET_DEM_EVENTS) )
/* *************************************************************************
  @fn             vdySetDEMEvents */ /*!
  @brief          Sets DEM events for BUS_DATA_ERROR, FUSI_ERROR, 
				  FS_YR_VS_WSP, FS_YR_VS_AY, FS_YR_VS_SWA, 
				  VEH_VEL_NOT_AVAILABLE, YWR_NOT_AVAILABLE, NVM_LEARN_DATA_ERROR.
  @description    Sets the DEM for Vdy's internal plausibility calculation/processing. \n
				  - VDY_ERR_STATE_UNKNOWN
                  - VDY_ERR_STATE_ACTIVE
                  - VDY_ERR_STATE_INACTIVE
  @param[in]      pVDYErrors : VDYErrors
  @param[in]      Services : Service functions
  @param[out]     -
  @return         static void

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation 
					- if signal error is active then set dem_failed else if signal is inactive then set dem_passed else keep old DEM status
  
  @testmethod
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> TEST_vdySetDEMEvents_001(), TEST_vdySetDEMEvents_002(), TEST_vdySetDEMEvents_003(), TEST_vdySetDEMEvents_004(), TEST_vdySetDEMEvents_005()
  @traceability
  - L3
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1623-000221c8 
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1622-000221c8 
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1621-000221c8 
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1618-000221c8 
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1133-00026448

  @author         Frank Wolter
**************************************************************************** */
STATIC_MTD void vdySetDEMEvents(const VDYErrors_t * pVDYErrors, const AS_t_ServiceFuncts * services);
#endif

/* ***********************************************************************
  @fn               vdyRawEstimatedVelocity */ /*!

  @brief            Average of four wheel speed with velocity correction

  @description      Average of four wheel speed with velocity correction

  @param[in]        input: input signals
  @param[out]       proPorts: provided ports
  @return           void

  @pre              -
  @post             -
  @InOutCorrelation 
					- Estimate verage of four wheel speed with velocity correction
  					
	@startuml
	start
		:u_Wcount = VDY_FOUR_U;
		:f_WhlVelFrLeft = input->Signals.WhlVelFrLeft;
		:f_WhlVelFrRight= input->Signals.WhlVelFrRight;
		:f_WhlVelReLeft= input->Signals.WhlVelReLeft;
		:f_WhlVelReRight= input->Signals.WhlVelReRight;
		:f_MinWhlVel = CML_Min(CML_Min(CML_Min(f_WhlVelFrLeft,f_WhlVelFrRight),f_WhlVelReLeft),f_WhlVelReRight);
		:f_MaxWhlVel = CML_Max(CML_Max(CML_Max(f_WhlVelFrLeft,f_WhlVelFrRight),f_WhlVelReLeft),f_WhlVelReRight);
		if ( VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_FL, input->Signals.State) == (VDYIoStateTypes_t)VDY_IO_STATE_INVALID ) then (YES)
			:f_WhlVelFrLeft = VDY_ZERO_F;
			:u_Wcount = u_Wcount - 1U;
		endif
		if ( VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_FR, input->Signals.State) == (VDYIoStateTypes_t)VDY_IO_STATE_INVALID ) then (YES)
			:f_WhlVelFrRight = VDY_ZERO_F;
			:u_Wcount = u_Wcount - 1U;
		endif
		if ( VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_RL, input->Signals.State) == (VDYIoStateTypes_t)VDY_IO_STATE_INVALID ) then (YES)
			:f_WhlVelReLeft = VDY_ZERO_F;
			:u_Wcount = u_Wcount - 1U;
		endif
		if ( VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_RR, input->Signals.State) == (VDYIoStateTypes_t)VDY_IO_STATE_INVALID ) then (YES)
			:f_WhlVelReRight = VDY_ZERO_F;
			:u_Wcount = u_Wcount - 1U;
		endif
		if (u_Wcount == 0U) then (YES)
			:u_Wcount = 1U;
		endif
		:RawVelo = ((f_WhlVelFrLeft + f_WhlVelFrRight + f_WhlVelReLeft + f_WhlVelReRight)/(float32)u_Wcount);	
	stop
	@enduml
  @testmethod
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> TEST_vdyRawEstimatedVelocity_001(), TEST_vdyRawEstimatedVelocity_002()
  @traceability
	- NA
  @author         Sanjiv Singh
**************************************************************************** */
STATIC_MTD void vdyRawEstimatedVelocity(const VDYInputData_t * input, proVdyPrtList_t *proPorts);

#if (CFG_VDY_MFC)
/* **********************************************************************
  @fn               vdyInputChecks */ /*!
  @brief            Input checks for reqports.
  @description      Checks reqPort's against NULL in order of NULL pointer, version number, signal status, and sets dem accordingly in sub-functions.
  @param[in]        reqPorts: request Ports 
  @param[in]        proPorts: provide Ports
  @param[in]        services: Services
  @param[in]        eVDYSigStatus: AlgoSignalState_t
  @param[in]        uiReqPortNullPtrCheck: Ports Null Pointer Check Flag
  @return           returns port fault / not fault.
  @c_switch_part   None
  @c_switch_full   None
  @InOutCorrelation
					- InputCheck with Priority(1) : Check request port's NULL Pointer.
					- InputCheck with Priority(2) : If request ports are not NULL, then check for their version numbers.
					- InputCheck with Priority(3) : Check request port's signal status.
					- InputCheck with Priority(4) : Timestamp and MeasureCounter check.
  
	@startuml
	start
		if( InputCheck with Priority(1) - Check request port's NULL Pointer \n uiReqPortNullPtrCheck != VDY_REQUEST_PORT_FAULT ) then (YES)
			:InputCheck with Priority(2) - If request ports are not NULL, then check for their version numbers \n vdyCheckRequestPortVersionNumber( reqPorts,services );
			:InputCheck with Priority(3) - Check request port's signal status \n vdyCheckReqPortSignalState( reqPorts, proPorts, eVDYSigStatus, services );
			:InputCheck with Priority(4) - Timestamp and MeasureCounter check \n vdyCheckTimestamp_MeasCounter( reqPorts, services );
		endif
	stop
	@enduml
  @testmethod
	- NA
  @traceability	
  - L3
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1614-000221c8
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1142-00026448
**************************************************************************** */
STATIC_MTD void vdyInputChecks( const reqVdyPrtList_t* const reqPorts, proVdyPrtList_t* const proPorts, const AS_t_ServiceFuncts* const services, AlgoSignalState_t* eVDYSigStatus, uint8 uiReqPortNullPtrCheck );


/* *************************************************************************
  @fn             vdyCheckRequestPortVersionNumber */ /*!
  @brief          Checks the Request port version number against RTE defined version number and sets DEM if not matching.
  @description    Check all requested, provided and service ports for error
                  and set the respective DEM
  @param[in]           reqPorts	  : Request port data
  @param[in, out]      services	  : Service functions for setting the Dem
  @return value	  - void
  @InOutCorrelation	
					 - Check Request port version. If it is not equal to RTE port version, then set Fusi dem 
  
	@startuml
	start
        :Initialize uiOpData;
        :Check if reqPorts->pBaseCtrlData->uiVersionNumber not equal to BASE_CTRL_DATA_INTFVER then set VDY_FUSI_ERROR to DEM_EVENT_STATUS_FAILED;
        :Check if reqPorts->pNVMRead->uiVersionNumber not equal to VDY_NVM_IO_DATA_INTFVER then set VDY_FUSI_ERROR to DEM_EVENT_STATUS_FAILED;
        :Check if reqPorts->pVehicleInputSignals->uiVersionNumber not equal to BSW_VEH_SIG_INTFVER then set VDY_FUSI_ERROR to DEM_EVENT_STATUS_FAILED;
        :Check if reqPorts->pVehicleParameter->uiVersionNumber not equal to BSW_VEH_PAR_INTFVER then set VDY_FUSI_ERROR to DEM_EVENT_STATUS_FAILED;
        :If all ports version are matching then set VDY_FUSI_ERROR to DEM_EVENT_STATUS_PASSED;
        stop
	@enduml
  @testmethod
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> \n
                            TEST_vdyCheckRequestPortVersionNumber_001(),
                            TEST_vdyCheckRequestPortVersionNumber_002(),
                            TEST_vdyCheckRequestPortVersionNumber_003(),
                            TEST_vdyCheckRequestPortVersionNumber_004(),
                            TEST_vdyCheckRequestPortVersionNumber_005(),
                            TEST_vdyCheckRequestPortVersionNumber_006(),
                            TEST_vdyCheckRequestPortVersionNumber_007(),
                            TEST_vdyCheckRequestPortVersionNumber_008()
  @traceability
  - L3
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1614-000221c8
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1144-00026448
***************************************************************************/
STATIC_MTD void vdyCheckRequestPortVersionNumber( const reqVdyPrtList_t* const reqPorts,const AS_t_ServiceFuncts* services );


/* *************************************************************************
  @fn             vdyCheckReqPortSignalState */ /*!
  @brief          Checks the Request port Signal state Invalid.
  @description    Check all requested port's signal state. If state is in INIT for continuously more than debounce cycle or InValid, then set the DEM.
  @param[in]      reqPorts : Request Port
  @param[in]      proPorts : Provide Port
  @param[in]      eVDYSigStatus : VDY signal Status
  @param[in, out]      services : Services 
  @return value	  - void
  @c_switch_part   None
  @c_switch_full   None 
  @InOutCorrelation	
					 - Set Fusi DEM for reqport holding signal state as INIT for more than 3 debounce cycle.
  
  @testmethod	
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> \n
                            TEST_vdyCheckReqPortSignalState_001(), \n
                            TEST_vdyCheckReqPortSignalState_002(), \n
                            TEST_vdyCheckReqPortSignalState_003(), \n
                            TEST_vdyCheckReqPortSignalState_004(), \n
                            TEST_vdyCheckReqPortSignalState_005(), \n
                            TEST_vdyCheckReqPortSignalState_006(), \n
                            TEST_vdyCheckReqPortSignalState_007(), \n
                            TEST_vdyCheckReqPortSignalState_008(), \n
                            TEST_vdyCheckReqPortSignalState_009(), \n
                            TEST_vdyCheckReqPortSignalState_010() \n
                       
  @traceability	
  - L3
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1614-000221c8
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1145-00026448
***************************************************************************/
STATIC_MTD void vdyCheckReqPortSignalState( const reqVdyPrtList_t* const reqPorts, proVdyPrtList_t* const proPorts, AlgoSignalState_t* eVDYSigStatus, const AS_t_ServiceFuncts* services );


/* **********************************************************************
  @fn               vdyCheckTimestamp_MeasCounter (only for camera) */ /*!
  @brief            Signal header Timestamp & MeasurementCounter check shall be conducted for non-static signals.
  @description      Sets Dem if any reqports (apart from basectrl) fails the Timestamp and MeasureCounter check.
					Timestamp check   : reqPort's timestamp should be less than 185000(Fusi Debounce Time limit).
					MeasCounter check : reqPort's meascount should be less than 65535 (i.e wrap-around limit).
  @param[in]        *reqPorts : request Ports
  @param[in]		*services : servicefunctions
  @return           void
  @InOutCorrelation
					- Sets Dem if any reqports (apart from basectrl) fails the Timestamp and MeasureCounter check.
  
  @testmethod	
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> TEST_vdyCheckTimestamp_MeasCounter_001(), TEST_vdyCheckTimestamp_MeasCounter_002()
  @traceability	
  - L3
    - NA
  - L3
    - NA
**************************************************************************** */
STATIC_MTD void vdyCheckTimestamp_MeasCounter( const reqVdyPrtList_t* const reqPorts, const AS_t_ServiceFuncts* services );


/* *************************************************************************
  @fn             vdySetProPortSigStateDetectionFlag */ /*!
  @brief          Detects the Request port's signal state for debounce cycle and sets the Provide port's signal status.
  @description    - Check all request port's signal state. If state is in INIT for continuously more than debounce cycle or is InValid, then set the provide port's signal state
				    to Invalid else set it to Init and also set the DEM.
				  - sets the flag for respective Dem Event depending on Signal State
  @param[in]      proPorts : Provide Port
  @return        void
  @c_switch_part   None
  @c_switch_full   None 
  @InOutCorrelation	
					- check ReqPort signal state has crossed debounce limit of 3
  
  @testmethod
	- NA
  @traceability	
  - L3
    - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1614-000221c8
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1145-00026448
***************************************************************************/
STATIC_MTD void vdySetProPortSigStateDetectionFlag( proVdyPrtList_t* const proPorts );
#endif

#ifdef CFG_VDY_MEASUREMENT
void VDY_MTS_Callback (void)
{
  return;
}
#endif

/* **********************************************************************
  @fn               VdyExec */ /*!
  @brief           Main loop for VDY, called from outside

  @description     Determine operating sequence for vehicle dynamics observer
                   Collect input signals
                   Freeze provided ports

  @return          BaseReturnCode_t (uint32)

  @param[in]       *reqPorts : provide ports
  @param[in]       services : servicefunctions
  @param[in,out]   *proPorts : request ports

  @glob_in         
					  - VDY_CALIMODE_ROLLER_BENCH : Calibration inhibition states
					  - VDY_CONST_CYCLE_TIME : Constant cycle time of component 
					  - VDY_NVM_YWRT_LEARN_TAB_INTFVER : Provided ports NvYawrate temp table Version number
					  - VDY_NVM_IO_DATA_INTFVER : Provided ports VDY NVM write data Version number
					  - AL_SIG_STATE_OK : Algo signal state enumeration     
					  - AL_SIG_STATE_INIT : Algo signal state enumeration  
					  - AL_SIG_STATE_INVALID : Algo signal state enumeration
  @glob_out        None 

  @pre             None 
  @post            No changes 

  @c_switch_part   
					  - AS_SERVICEFUNC_VERSION : Servicefunctions version
					  - VDY_PROFILING_ENABLED : Enables runtime measurement and profiling
					  - CFG_VDY_ROLLBENCH_DETECTION : Enables reaction to roll bench detection
					  - VDY_VEH_DYN_INTFVER : 
					  - CORRECTED_EGO_SPEED_IS_ZERO_ON_ROLLER_BENCH : Corrected ego speed is set to zero by VDY, if roller test bench is detected by EM
					  - CFG_VDY_INT_GYRO : Enable internal yaw rate sensor processing
					  - CFG_VDY_INIT_MODE_AS_STARTUP_MODE : Enables the switch to make Init mode as StarUp mode
					  - CFG_VDY_DIS_CURVE_OUTPUT : Disable the additional VDY curve output
  @c_switch_full   None 
           
  @InOutCorrelation 
                    This function is called by Global Scheduler every 20ms. VDY execution is based on Operational Modes.
                    - BASE_OM_RUN
                    - BASE_OM_IDLE
                    - BASE_OM_RESET
                    - BASE_OM_DEMO

  

	@startuml
	start
        : Create a static variable of Input to the Vehicle Dynamics Module;
        : Create a Variable to store i/o Port faults;
        : Create a variable of type AlgoSignalState_t to store eVDYSigStatus;
        if (not MFC) then (YES)
	        :Create Algo Time Stamp;
	        :Create System Time Stamp;
	        :Create Time Stamp of previous cycle;
        else
	        :Create a variable to store length of string;
	        :Initialize return value of the function of type BaseReturnCode_t to BASE_RETURN_OK;
	        :Initialize eVDYSigStatus to init;
        endif
        if(Profiling is enabled) then (YES)
            if (services->pfRTAAlgoServiceAddEvent not NULL) then (YES)
                if(reqPorts and reqPorts->pBaseCtrlData are not NULL ) then (YES)
                    :Start profiling by adding VDY to serviceFunction RTA_v_AddEvent along with right OpMode;
                else (NO)
                    :Start profiling by adding VDY to serviceFunction RTA_v_AddEvent along with OpMode 0 (IDLE);
                endif
            endif
        endif
        :Check for VDY i/o ports fault including Service Port when AS_SERVICEFUNC_VERSION is defined otherwise Check for VDY i/o ports fault excluding Service Port;
        :Start new MTS cycle when AS_SERVICEFUNC_VERSION is defined and CFG_VDY_USE_ALGOCOMPSTATE is enabled;
        :MeasFreeze NVM request port when defined and enabled CFG_VDY_VDYNVIODATARD_MEASFREEZ_ENABLE;
        :Set velcorr and unused NVM positions invalid and Set velcorr NVM data to zero for camera when CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK defined and enabled;
        if (No fault in ports) then (YES)
	        :copy cycle time, control state and calibration state to the frame data;
	        :check and set the RTB detection flag if RTB is detected to use the variable in the entire VDY algo when CFG_VDY_ROLLBENCH_DETECTION is enabled;
	        :Process all calibration learning on roll bench detection or PlantMode and driving for ARS;
	        :Disable all offset, WLD and Selfsteering Gradient learnings when Ego velocity is not set to zero on roller test bench or PlantMode;
	        :Avoid zero or too large cycle times, 20 ms is nominal cycle time;
	        :Initialize VDY output;
	        :Initialize the Provide port's AlgoCompState with default values, few of which will be overwritten in respective OpModes below;
	        :Initialize Provide port's pYwrtTempTable uiVersionNumber with VDY_NVM_YWRT_LEARN_TAB_INTFVER when CFG_VDY_INT_GYRO is defined and enabled;
	        :Initialize Provide port's pNVMWrite uiVersionNumber to VDY_NVM_IO_DATA_INTFVER;
	        :VDY Execution Begins;
	        if (OpMode is BASE_OM_RUN, Control Mode in ARS) then (YES)
		        :Do Input Checks (null ptr, version number, signal state for all ports);
		        :Set eSigStatus to AL_SIG_STATE_OK;
		        if(No Request Ports Fault) then (YES)
			        :Copy Input SIgnals;
			        :copy input parameters;
			        :Process VDY in case of init and running mode;
			        :Update proPort's compState for Camera \n eCompoState with COMP_STATE_RUNNING and eGenAlgoQualifier with ALGO_QUAL_OK;
			        :set eSigStatus to AL_SIG_STATE_OK for ARS when AS_SERVICEFUNC_VERSION is defined
		        else (NO)
			        :Update proPort's compState accordingly for Camera \n eCompoState with COMP_STATE_TEMPORARY_ERROR and eGenAlgoQualifier with ALGO_QUAL_CRITICAL_INPUT_ERROR;
			        :Initialize component in startup mode in ARS;
			        :Set eVDYSigStatus to AL_SIG_STATE_INIT in ARS;
		        endif
	        else if (OpMode is BASE_OM_IDLE) then (YES)
		        :Set eVDYSigStatus to AL_SIG_STATE_INVALID when AS_SERVICEFUNC_VERSION is defined;
		        :Initialize VDY;
		        :Set eSigStatus to AL_SIG_STATE_INVALID;
		        :Set eCompState to COMP_STATE_NOT_RUNNING
		        :Set eGenAlgoQualifier to ALGO_QUAL_OK;
	        else if (OpMode is BASE_OM_RESET) then (YES)
		        :Do Input Checks (null ptr, version number, signal state for all ports);
		        :Set eSigStatus to AL_SIG_STATE_INIT
		        :When reqports are normal, then initialize vdy in Reset mode, and set proport's eCompState to success else set to Not_Initialized;
		        :When reqports are normal set eGenAlgoQualifier to ALGO_QUAL_OK otherwise to ALGO_QUAL_CRITICAL_INPUT_ERROR;
	        else if (OpMode is BASE_OM_DEMO) then (YES)	
		        :Set eVDYSigStatus to AL_SIG_STATE_OK;
		        :Initialize VDY;
		        :Set eSigStatus to AL_SIG_STATE_OK;
		        :Set eCompState to COMP_STATE_SUCCESS;
		        :Set eGenAlgoQualifier to ALGO_QUAL_OK;
	        else (NO)
		        :Set eVDYSigStatus to AL_SIG_STATE_INVALID when AS_SERVICEFUNC_VERSION is defined;
		        :Set eCompState to COMP_STATE_TEMPORARY_ERROR;
		        :Set eErrorCode to COMP_ERROR_UNKNOWN;
		        :Set eShedulerSubModeRequest to BASE_OM_RUN;
		        :Set eGenAlgoQualifier to ALGO_QUAL_OK;
	        endif
	        :set  ret_Exec to BASE_RETURN_OK;
        else (NO)
	        :Critical error, no input data available \n Set eVDYSigStatus to AL_SIG_STATE_INVALID;
	        :Nullify all Proports when PreconditionCheck is Failed;
	        :When pAlgoCompState is not null then
		        \n Set eCompState to COMP_STATE_TEMPORARY_ERROR
		        \n Set eErrorCode to COMP_ERROR_UNKNOWN
		        \n Set eShedulerSubModeRequest to BASE_OM_RUN
		        \n Set eGenAlgoQualifier to ALGO_QUAL_OK;
	        :Set ret_Exec to BASE_RETURN_ERROR;
	        :Set cycle counter in the internal buffer to reset values;
        endif
        :Fill the signal headers of all output ports;
        :For any opMode, the measurecounter, Timestamp of all proPorts should be initialized with reqport's basectrl's measurecounter & Timestamp;
        :set compstate for scheduler for ARS;
        :Meas Freeze all provide ports;
        :Set DEM events if any;
        :End profiling ;
        :return ret_Exec;
	stop
	@enduml
  @testmethod
  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> TEST_vdyExec_001(), TEST_vdyExec_002(), TEST_vdyExec_003()

  @traceability	

  - OpMode handling:
    - L3
      - Idle : doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1645-000221c8 
      - Demo : doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1644-000221c8 
      - Reset: doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1643-000221c8 
      - Run  : doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1642-000221c8
      .
    - L4
      - Idle : doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1147-00026448 
      - Demo : doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1149-00026448 
      - Reset: doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1150-00026448 
      - Run  : doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1148-00026448
      .
  - Measfreeze:
    - L3
      - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1625-000221c8 
      - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1626-000221c8 
      - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1628-000221c8
      .
    - L4
      - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1152-00026448 
      - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1153-00026448 
      - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1154-00026448
      .
  - CompState: 
    - L3
      - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1640-000221c8 
      - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1639-000221c8 
      - doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1638-000221c8
      .
    - L4
      - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1158-00026448 
      - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1157-00026448 
      - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1156-00026448
      .
  - Roller Test Bench
    - L3
      - doors://rbgs854a:40000/?version=2&prodID=0&view=0000012f&urn=urn:telelogic::1-503e822e5ec3651e-O-1653-000221c8
      .
    - L4
      - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-729-00026448
      .
  - Input Checks
    - L3
      - doors://rbgs854a:40000/?version=2&prodID=0&view=0000012f&urn=urn:telelogic::1-503e822e5ec3651e-O-1614-000221c8
      .
    - L4
      - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1142-00026448
      .
  - General 
    - L4
      - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-360-00026448
      .
**************************************************************************** */
#ifdef AS_SERVICEFUNC_VERSION
#if (CFG_VDY_MFC)
BaseReturnCode_t VdyExec(const reqVdyPrtList_t* const reqPorts, proVdyPrtList_t* const proPorts, const AS_t_ServiceFuncts* const services)
#else
void VdyExec(const reqVdyPrtList_t *reqPorts, proVdyPrtList_t *proPorts, const AS_t_ServiceFuncts * services)
#endif
#else
void VdyExec(const reqVdyPrtList_t *reqPorts, proVdyPrtList_t *proPorts)
#endif
{
  /* Input to the Vehicle Dynamics Module */
  static VDYInputData_t  VDYIn;
  /* Variable to store i/o Port faults */
  uint8 ui8PortFault;
#ifdef AS_SERVICEFUNC_VERSION
  /// VDY Signal Status
  AlgoSignalState_t eVDYSigStatus;
#if (!CFG_VDY_MFC)
  /* Algo Time Stamp */
  AlgoDataTimeStamp_t uiTimeStamp;
  /* System Time Stamp */
  AlgoDataTimeStamp_t uiSystemTimeStamp;
  /* Time Stamp of previous cycle  */
  static AlgoDataTimeStamp_t uiTimeStampLastCycle = 0U;
#else
  /* variable to store length of string */
  size_t len		         = 0;
  /* return value of the function of type BaseReturnCode_t */
  BaseReturnCode_t	ret_Exec = BASE_RETURN_OK;
  /* Initialize eVDYSigStatus to init */
  eVDYSigStatus              = AL_SIG_STATE_INIT;
#endif
#endif

  /* Start profiling */
#if ( defined(VDY_PROFILING_ENABLED) && (VDY_PROFILING_ENABLED == 1) )
  if(services->pfRTAAlgoServiceAddEvent != (NULL))
  {
		  VDY_PROF_START(services->pfRTAAlgoServiceAddEvent, VDY_PROF_ID_ALL);
  }
#endif

#ifdef AS_SERVICEFUNC_VERSION
  /* Check for VDY i/o ports fault including Service Port */
  ui8PortFault = vdyCheckPorts(reqPorts, proPorts, services);
#else
  /* Check for VDY i/o ports fault excluding Service Port */
  ui8PortFault = vdyCheckPorts(reqPorts, proPorts);
#endif

#ifdef AS_SERVICEFUNC_VERSION
#if (CFG_VDY_USE_ALGOCOMPSTATE)
  /* Start new MTS cycle */
  if ((services->pfMeasStartFuncCycle) != (void *)NULL)
  {
#if( (defined(CFG_VDY_VDYNVIODATARD_MEASFREEZ_ENABLE))&&(CFG_VDY_VDYNVIODATARD_MEASFREEZ_ENABLE))
    services->pfMeasStartFuncCycle(TASK_ID_VDY);
#else
    services->pfMeasStartFuncCycle(COMP_ID_VDY);
#endif
  }
#endif
#endif

/* Freeze NVM request ports */
#if( (defined(CFG_VDY_VDYNVIODATARD_MEASFREEZ_ENABLE))&&(CFG_VDY_VDYNVIODATARD_MEASFREEZ_ENABLE))
	if(reqPorts->pNVMRead != NULL)
	{

		MEAS_FREEZE_DIRECT(VDY_MEAS_ID_NVM_READ, reqPorts->pNVMRead, sizeof(VDYNvIoData_t));
	}      
#endif

#if( (defined(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))&&(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))
	{
   /* Set velcorr and unused NVM positions invalid,only for camera  */
      VDY_SET_NVM_IO_STATE((uint32)VDY_NVM_POS_VELCORR, (uint32)VDY_IO_STATE_INVALID, &proPorts->pNVMWrite->State);
	  VDY_SET_NVM_IO_STATE((uint32)VDY_NVM_POS_TWELVE, (uint32)VDY_IO_STATE_INVALID, &proPorts->pNVMWrite->State);
	  VDY_SET_NVM_IO_STATE((uint32)VDY_NVM_POS_FOURTEEN, (uint32)VDY_IO_STATE_INVALID, &proPorts->pNVMWrite->State);
	  VDY_SET_NVM_IO_STATE((uint32)VDY_NVM_POS_SIXTEEN, (uint32)VDY_IO_STATE_INVALID, &proPorts->pNVMWrite->State);
	  VDY_SET_NVM_IO_STATE((uint32)VDY_NVM_POS_EIGHTEEN, (uint32)VDY_IO_STATE_INVALID, &proPorts->pNVMWrite->State);
	  VDY_SET_NVM_IO_STATE((uint32)VDY_NVM_POS_TWENTY, (uint32)VDY_IO_STATE_INVALID, &proPorts->pNVMWrite->State);
	  VDY_SET_NVM_IO_STATE((uint32)VDY_NVM_POS_TWENTYTWO, (uint32)VDY_IO_STATE_INVALID, &proPorts->pNVMWrite->State);
	  VDY_SET_NVM_IO_STATE((uint32)VDY_NVM_POS_TWENTYFOUR, (uint32)VDY_IO_STATE_INVALID, &proPorts->pNVMWrite->State);
	  VDY_SET_NVM_IO_STATE((uint32)VDY_NVM_POS_TWENTYSIX, (uint32)VDY_IO_STATE_INVALID, &proPorts->pNVMWrite->State);
	  VDY_SET_NVM_IO_STATE((uint32)VDY_NVM_POS_TWENTYEIGHT, (uint32)VDY_IO_STATE_INVALID, &proPorts->pNVMWrite->State);
	  VDY_SET_NVM_IO_STATE((uint32)VDY_NVM_POS_THIRTY, (uint32)VDY_IO_STATE_INVALID, &proPorts->pNVMWrite->State);

   /* Set velcorr NVM data to zero,only for camera  */

	  (void)vdy_memset_s(proPorts->pNVMWrite->VelCorr , 0 , sizeof(VelCorr_array_t));
	}
#endif
#if (CFG_VDY_MFC)

	/* [Requirement - L3D_ALGO_21600 : PreconditionChecks] - Check pBaseCtrlData, it's signal state, Service port, Provide ports - as the first step. */
	if ((ui8PortFault != VDY_PROVIDE_PORT_FAULT) && (ui8PortFault != VDY_SERVICE_PORT_FAULT) && ((reqPorts->pBaseCtrlData != NULL) || ((reqPorts->pBaseCtrlData != NULL) && (reqPorts->pBaseCtrlData->sSigHeader.eSigStatus == (AlgoSignalState_t)AL_SIG_STATE_OK))))
#else
	if (ui8PortFault == VDY_NO_PORT_FAULT)
#endif
  {
    /* copy cycle time, control state and calibration state to the frame data */
#if (CFG_VDY_MFC)
	  VDYIn.Frame.CycleTime = VDY_CONST_CYCLE_TIME;
	  VDYIn.Frame.OpMode    = reqPorts->pBaseCtrlData->eOpMode;
	  VDYIn.Frame.CaliMode  = VDY_CAL_INIT;
#else
	  VDYIn.Frame.CycleTime = reqPorts->pCtrl->CycleTime;
	  VDYIn.Frame.CtrlMode  = reqPorts->pCtrl->CtrlMode;
	  VDYIn.Frame.CaliMode  = reqPorts->pCtrl->CaliMode;
#endif
    #if(BSW_VDY_CTRL_DATA_INTFVER >= 3U) 
    VDYIn.Frame.ProductionMode  = reqPorts->pCtrl->ProductionMode;
    #endif
	
    /* check and set the RTB detection flag if RTB is detected to use the variable in the entire VDY algo*/
    #if ( (defined(CFG_VDY_ROLLBENCH_DETECTION)) && (CFG_VDY_ROLLBENCH_DETECTION) )
    if(reqPorts->pRTBRecognition->f_ProbRTBRecog > VDYRTBRecognitionThreshold_c)
    {
      b_RTBDetection = true;
    }
    else
    {
      b_RTBDetection = false;
    }
    #endif
#if (!CFG_VDY_MFC)
    /* Process all calibration learning on roll bench detection or PlantMode and driving*/
    #if((VDY_VEH_DYN_INTFVER >= 8U) || (BSW_VDY_CTRL_DATA_INTFVER >= 3U))
    if (((CORRECTED_EGO_SPEED_IS_ZERO_ON_ROLLER_BENCH!= 1) && ( b_RTBDetection == TRUE )) || (VDYIn.Frame.ProductionMode == TRUE))
    {
      /* Disable all offset, WLD and Selfsteering Gradient learnings when Ego velocity is not set to zero on roller test bench or PlantMode */
      VDYIn.Frame.CaliMode = VDY_CALIMODE_ROLLER_BENCH;
    }
    #endif
#endif

    /*! Avoid zero or too large cycle times, 20 ms is nominal cycle time */
    VDYIn.Frame.CycleTime = (( (VDYIn.Frame.CycleTime > (uiTime_t)0U) && (VDYIn.Frame.CycleTime < VDY_MAX_CYCLE_TIME) ) ? VDYIn.Frame.CycleTime : VDY_CONST_CYCLE_TIME);

    /* Initialize output */
    vdyInitVehDyn(proPorts->pVehicleDynamicSignals);
	
#if (CFG_VDY_MFC)
	/* Initialize the Provide port's AlgoCompState with default values, few of which will be overwritten in respective OpModes below. */
    (void)vdy_memset_s( proPorts->pAlgoCompState, 0, sizeof (proPorts->pAlgoCompState) );

	len = VDY_STRLEN( VDY_SW_ALGO_VERSION_INFO );
	(void)vdy_memcpy_s( proPorts->pAlgoCompState->AlgoVersionInfo, VDY_SW_ALGO_VERSION_INFO, len );
	proPorts->pAlgoCompState->eCompState					=	COMP_STATE_RUNNING;
	proPorts->pAlgoCompState->eErrorCode					=	COMP_ERROR_NO_ERROR;
	proPorts->pAlgoCompState->eGenAlgoQualifier				=	ALGO_QUAL_OK;
	proPorts->pAlgoCompState->eShedulerSubModeRequest		=	BASE_SSM_NONE;
	proPorts->pAlgoCompState->uiAlgoVersionNumber			=	VDY_SW_VERSION_NUMBER;
	proPorts->pAlgoCompState->uiApplicationNumber			=	0u;
	proPorts->pAlgoCompState->uiVersionNumber				=	COMP_STATE_INTFVER;
#endif
    /* Initialize Provide port's pYwrtTempTable uiVersionNumber to VDY_NVM_YWRT_LEARN_TAB_INTFVER */
  #if ( (defined(CFG_VDY_INT_GYRO)) && (CFG_VDY_INT_GYRO) )
    proPorts->pYwrtTempTable->uiVersionNumber = VDY_NVM_YWRT_LEARN_TAB_INTFVER;
  #endif
    /* Initialize Provide port's pNVMWrite uiVersionNumber to VDY_NVM_IO_DATA_INTFVER */
    proPorts->pNVMWrite->uiVersionNumber = VDY_NVM_IO_DATA_INTFVER;


    /* VDY execution */
#if (CFG_VDY_MFC)
    /* When Operation Mode is Running */
	if ( VDYIn.Frame.OpMode == (BaseOpMode_t)BASE_OM_RUN )
	{
#else
    /* When Control Mode is Running in ARS*/
    if ( VDYIn.Frame.CtrlMode <= (VDYCtrlState_t)VDY_CTRL_STATE_RUNNING )
    {
      #if ( (defined (CFG_VDY_INIT_MODE_AS_STARTUP_MODE)) && (CFG_VDY_INIT_MODE_AS_STARTUP_MODE) )
      if ( VDYIn.Frame.CtrlMode == (VDYCtrlState_t)VDY_CTRL_STATE_RUNNING )
      #else
      if ( VDYIn.Frame.CtrlMode != (VDYCtrlState_t)VDY_CTRL_STATE_STARTUP )
      #endif
#endif
      {
#if (CFG_VDY_MFC)
	    /* [Requirement - L3D_ALGO_10786 : InputChecks] - Only InputChecks (null ptr, version number, signalstate for all ports). */
        vdyInputChecks( reqPorts, proPorts, services, &eVDYSigStatus, ui8PortFault );
		proPorts->pAlgoCompState->sSigHeader.eSigStatus = AL_SIG_STATE_OK;
        if(ui8PortFault != VDY_REQUEST_PORT_FAULT)
		{
#endif
			/* copy input signals */
			vdyCopyInputSignals(&VDYIn.Signals, &reqPorts->pVehicleInputSignals->VehSigMain);
			/* copy input parameters */
			(void)vdy_memcpy_s(&VDYIn.Parameter, &reqPorts->pVehicleParameter->VehParMain, sizeof(VehParMain_t));

			/* Process VDY in case of init and running mode */
			vdyProcess(reqPorts, &VDYIn, proPorts, services);
#if (CFG_VDY_MFC)
			/* Update proPort's compState. */
	        proPorts->pAlgoCompState->eCompState		=	COMP_STATE_RUNNING;
	        proPorts->pAlgoCompState->eGenAlgoQualifier	=	ALGO_QUAL_OK;
		}
		else
		{
			proPorts->pAlgoCompState->eCompState		=	COMP_STATE_TEMPORARY_ERROR;
	        proPorts->pAlgoCompState->eGenAlgoQualifier	=	ALGO_QUAL_CRITICAL_INPUT_ERROR;		
		}			
#else
        #ifdef AS_SERVICEFUNC_VERSION
        eVDYSigStatus = AL_SIG_STATE_OK;
        #endif
#endif
      }
#if (!CFG_VDY_MFC)
      else
      {
        /* Initialize component in startup mode */
        vdyInit(reqPorts, &VDYIn, proPorts, services);
#ifdef AS_SERVICEFUNC_VERSION
        eVDYSigStatus = AL_SIG_STATE_INIT;
#endif
      }
#endif
	}
    else
	{
#if (!CFG_VDY_MFC)
      /* Undefined operation mode, re-init, no processing */
      vdyInit(reqPorts, &VDYIn, proPorts, services);
#ifdef AS_SERVICEFUNC_VERSION
      eVDYSigStatus = AL_SIG_STATE_INVALID;
#endif
#endif
#if (CFG_VDY_MFC)
      switch( VDYIn.Frame.OpMode )
	  {
		  case (BaseOpMode_t)BASE_OM_IDLE:
		  {
              #ifdef AS_SERVICEFUNC_VERSION
              eVDYSigStatus = AL_SIG_STATE_INVALID;
              #endif
			  /* In Idle mode also, VDY shall be initialized. */
              vdyInit(reqPorts, &VDYIn, proPorts, services);
              proPorts->pAlgoCompState->sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
              // "?" TODO: reset timestamp - check properly, right now not sure.
              proPorts->pAlgoCompState->eCompState			=	COMP_STATE_NOT_RUNNING;
              proPorts->pAlgoCompState->eGenAlgoQualifier	=	ALGO_QUAL_OK;
			  break;
		  }
		  case (BaseOpMode_t)BASE_OM_RESET:
		  {
			  /* [Requirement - L3D_ALGO_10786 : InputChecks] - Only InputChecks (null ptr, version number, signalstate for all ports). */
              vdyInputChecks( reqPorts, proPorts, services, &eVDYSigStatus, ui8PortFault );
			  proPorts->pAlgoCompState->sSigHeader.eSigStatus = AL_SIG_STATE_INIT;
			   /* If reqports are normal, then initialize vdy in Reset mode, and set proport's eCompState to success else set to Not_Initialized. */
              if(ui8PortFault != VDY_REQUEST_PORT_FAULT)
			  {
				  vdyInit(reqPorts, &VDYIn, proPorts, services);
                  proPorts->pAlgoCompState->eCompState		    =	COMP_STATE_SUCCESS;
                  proPorts->pAlgoCompState->eGenAlgoQualifier	=	ALGO_QUAL_OK;
			  }
			  else
			  {
				  proPorts->pAlgoCompState->eCompState		    =	COMP_STATE_NOT_INITIALIZED;
                  proPorts->pAlgoCompState->eGenAlgoQualifier	=	ALGO_QUAL_CRITICAL_INPUT_ERROR;
			  }
			  break;
		  }
		  case (BaseOpMode_t)BASE_OM_DEMO:
		  {
              #ifdef AS_SERVICEFUNC_VERSION
              eVDYSigStatus = AL_SIG_STATE_OK;
              #endif
              /* In Demo mode also, VDY shall be initialized. */
              vdyInit(reqPorts, &VDYIn, proPorts, services);
			  proPorts->pAlgoCompState->sSigHeader.eSigStatus   =   AL_SIG_STATE_OK;
              proPorts->pAlgoCompState->eCompState			    =	COMP_STATE_SUCCESS;
              proPorts->pAlgoCompState->eGenAlgoQualifier	    =	ALGO_QUAL_OK;
			  break;
		  }
		  default:
		  {
			  #ifdef AS_SERVICEFUNC_VERSION
              eVDYSigStatus = AL_SIG_STATE_INVALID;
              #endif
			  if( NULL != proPorts->pAlgoCompState )
			  {
				  proPorts->pAlgoCompState->eCompState				    =	COMP_STATE_TEMPORARY_ERROR;
                  proPorts->pAlgoCompState->eErrorCode				    =	COMP_ERROR_UNKNOWN;
                  proPorts->pAlgoCompState->eShedulerSubModeRequest	    =	BASE_OM_RUN;
                  proPorts->pAlgoCompState->eGenAlgoQualifier			=	ALGO_QUAL_OK;
			  }
			  break;
		  }
	  }
#endif
	}
#if (CFG_VDY_MFC)
	/* Return OK to software. */
  ret_Exec = BASE_RETURN_OK;
#endif
  }
  else
  {
    /* Critical error, no input data available */
#ifdef AS_SERVICEFUNC_VERSION
    eVDYSigStatus = AL_SIG_STATE_INVALID;
#endif
#if (CFG_VDY_MFC)
	if( NULL != services->pfDem_SetEventStatus )	{	services->pfDem_SetEventStatus( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED );	}
	/* Nullify all Proports if PreconditionCheck is Failed. */
	proPorts->pAlgoCompState         = NULL;
    proPorts->pNVMWrite              = NULL;
    proPorts->pVDYErrors             = NULL;
    proPorts->pVDYEstCurves          = NULL;
    proPorts->pVDYOffsets            = NULL;
    proPorts->pVehicleDynamicSignals = NULL;

	if( proPorts->pAlgoCompState != NULL )
	{
		proPorts->pAlgoCompState->eCompState				=	COMP_STATE_TEMPORARY_ERROR;
        proPorts->pAlgoCompState->eErrorCode				=	COMP_ERROR_UNKNOWN;
        proPorts->pAlgoCompState->eShedulerSubModeRequest	=	BASE_OM_RUN;
        proPorts->pAlgoCompState->eGenAlgoQualifier			=	ALGO_QUAL_OK;
	}
	/* Return ERROR to software. */
    ret_Exec = BASE_RETURN_ERROR;
#endif
    /* Set cycle counter in the internal buffer to reset values */
    VDYIn.Frame.CycleCnt  = 0;
  }
#if (!CFG_VDY_MFC)
  if ((ui8PortFault & VDY_PROVIDE_PORT_FAULT) != VDY_PROVIDE_PORT_FAULT)
#else
  if ((ui8PortFault != VDY_PROVIDE_PORT_FAULT) && (ui8PortFault != VDY_SERVICE_PORT_FAULT) && (reqPorts->pBaseCtrlData != NULL) && (reqPorts->pBaseCtrlData->sSigHeader.eSigStatus == (AlgoSignalState_t)AL_SIG_STATE_OK))
#endif
  {
#ifdef AS_SERVICEFUNC_VERSION
#if (!CFG_VDY_MFC)
    /* Add the input timestamp and the vdy cycle counter to the vdy output data */
    uiTimeStamp = reqPorts->pVehicleInputSignals->sSigHeader.uiTimeStamp;
    uiSystemTimeStamp = services->pfGetTimestampuS32();

    /* if no timestamp was delivered */
    if ((uiTimeStamp == 0U) && (uiTimeStampLastCycle == 0U))
    {
      /* take the current time as timestamp for output data */
      uiTimeStamp = uiSystemTimeStamp;
    }
    else
    {
      /* save current timestamp for next cycle */
      uiTimeStampLastCycle = uiTimeStamp;
    }

    /* calculate delta times between the last 2 calls and the VehSig timestamp and the current system time */
	if(uiTimeStamp > 0U)
	{
		VDYDeltaTimeStamp.ui_DeltaTimeBetweenCalls = uiTimeStamp - uiTimeStampLastCycle;
	}
    VDYDeltaTimeStamp.ui_DeltaTimeDataAndExecution = uiSystemTimeStamp - uiTimeStamp;
#else
	  VDYDeltaTimeStamp.ui_DeltaTimeBetweenCalls = 0U;
	  VDYDeltaTimeStamp.ui_DeltaTimeDataAndExecution = 0U;
#endif
    vdySetSyncFrame(reqPorts, VDYIn.Frame.CycleCnt, eVDYSigStatus);

    /* Fill the signal headers of all output ports */
#if (CFG_VDY_MFC)
	/* For any opMode, the measurecounter, Timestamp of all proPorts should be initialized with reqport's basectrl's measurecounter & Timestamp. */
	proPorts->pAlgoCompState->sSigHeader.uiCycleCounter 			  =	VDYIn.Frame.CycleCnt;    
    proPorts->pAlgoCompState->sSigHeader.uiMeasurementCounter		  =	reqPorts->pBaseCtrlData->sSigHeader.uiMeasurementCounter;
    proPorts->pAlgoCompState->sSigHeader.uiTimeStamp				  =	reqPorts->pBaseCtrlData->sSigHeader.uiTimeStamp;
#endif

    proPorts->pVehicleDynamicSignals->sSigHeader.eSigStatus = eVDYSigStatus;
#if (CFG_VDY_MFC)
    proPorts->pVehicleDynamicSignals->sSigHeader.uiTimeStamp          = reqPorts->pBaseCtrlData->sSigHeader.uiTimeStamp;
    proPorts->pVehicleDynamicSignals->sSigHeader.uiMeasurementCounter = reqPorts->pBaseCtrlData->sSigHeader.uiMeasurementCounter;
#else
    proPorts->pVehicleDynamicSignals->sSigHeader.uiTimeStamp = uiTimeStamp;
    proPorts->pVehicleDynamicSignals->sSigHeader.uiMeasurementCounter = reqPorts->pVehicleInputSignals->sSigHeader.uiCycleCounter;
#endif
    proPorts->pVehicleDynamicSignals->sSigHeader.uiCycleCounter = VDYIn.Frame.CycleCnt;

    proPorts->pVDYOffsets->sSigHeader.eSigStatus = eVDYSigStatus;
#if (CFG_VDY_MFC)
    proPorts->pVDYOffsets->sSigHeader.uiTimeStamp          = reqPorts->pBaseCtrlData->sSigHeader.uiTimeStamp;
    proPorts->pVDYOffsets->sSigHeader.uiMeasurementCounter = reqPorts->pBaseCtrlData->sSigHeader.uiMeasurementCounter;
#else
    proPorts->pVDYOffsets->sSigHeader.uiTimeStamp = uiTimeStamp;
    proPorts->pVDYOffsets->sSigHeader.uiMeasurementCounter = reqPorts->pVehicleInputSignals->sSigHeader.uiCycleCounter;
#endif
    proPorts->pVDYOffsets->sSigHeader.uiCycleCounter = VDYIn.Frame.CycleCnt;

  #if ( (!defined(CFG_VDY_DIS_CURVE_OUTPUT)) || (!CFG_VDY_DIS_CURVE_OUTPUT) )
    proPorts->pVDYEstCurves->sSigHeader.eSigStatus = eVDYSigStatus;
#if (CFG_VDY_MFC)
    proPorts->pVDYEstCurves->sSigHeader.uiTimeStamp          = reqPorts->pBaseCtrlData->sSigHeader.uiTimeStamp;
    proPorts->pVDYEstCurves->sSigHeader.uiMeasurementCounter = reqPorts->pBaseCtrlData->sSigHeader.uiMeasurementCounter;
#else
    proPorts->pVDYEstCurves->sSigHeader.uiTimeStamp = uiTimeStamp;
    proPorts->pVDYEstCurves->sSigHeader.uiMeasurementCounter = reqPorts->pVehicleInputSignals->sSigHeader.uiCycleCounter;
#endif
    proPorts->pVDYEstCurves->sSigHeader.uiCycleCounter = VDYIn.Frame.CycleCnt;
  #endif

    proPorts->pVDYErrors->sSigHeader.eSigStatus = eVDYSigStatus;
#if (CFG_VDY_MFC)
    proPorts->pVDYErrors->sSigHeader.uiTimeStamp          = reqPorts->pBaseCtrlData->sSigHeader.uiTimeStamp;
    proPorts->pVDYErrors->sSigHeader.uiMeasurementCounter = reqPorts->pBaseCtrlData->sSigHeader.uiMeasurementCounter;
#else
    proPorts->pVDYErrors->sSigHeader.uiTimeStamp = uiTimeStamp;
    proPorts->pVDYErrors->sSigHeader.uiMeasurementCounter = reqPorts->pVehicleInputSignals->sSigHeader.uiCycleCounter;
#endif
    proPorts->pVDYErrors->sSigHeader.uiCycleCounter = VDYIn.Frame.CycleCnt;

#if (CFG_VDY_HFL)
    proPorts->pNVMWrite->sSigHeader.eSigStatus = AL_SIG_STATE_OK;
#else
    proPorts->pNVMWrite->sSigHeader.eSigStatus = eVDYSigStatus;
#endif
#if (CFG_VDY_MFC)
    proPorts->pNVMWrite->sSigHeader.uiTimeStamp          = reqPorts->pBaseCtrlData->sSigHeader.uiTimeStamp;
    proPorts->pNVMWrite->sSigHeader.uiMeasurementCounter = reqPorts->pBaseCtrlData->sSigHeader.uiMeasurementCounter;
#else
    proPorts->pNVMWrite->sSigHeader.uiTimeStamp = uiTimeStamp;
    proPorts->pNVMWrite->sSigHeader.uiMeasurementCounter = reqPorts->pVehicleInputSignals->sSigHeader.uiCycleCounter;
#endif
    proPorts->pNVMWrite->sSigHeader.uiCycleCounter = VDYIn.Frame.CycleCnt;
#if (!CFG_VDY_MFC)
#if ( defined(CFG_VDY_USE_ALGOCOMPSTATE) && (CFG_VDY_USE_ALGOCOMPSTATE) )
    /* set compstate for scheduler */
    vdySetCompState(VDYIn, proPorts);
#endif
#endif

    if ((ui8PortFault & VDY_SERVICE_PORT_FAULT) != VDY_SERVICE_PORT_FAULT)
    {
      /* Freeze provided ports */
#if (CFG_VDY_MFC)
	    if(proPorts->pAlgoCompState != NULL)
		{
			MEAS_FREEZE_DIRECT( VDY_MEAS_ID_ALGO_COMP_STATE, proPorts->pAlgoCompState, sizeof(AlgoCompState_t));
		}
#endif
		if(proPorts->pVehicleDynamicSignals != NULL)
		{
			MEAS_FREEZE_DIRECT(VDY_MEAS_ID_VEH_DYN, proPorts->pVehicleDynamicSignals, sizeof(VehDyn_t));
		}

		if(proPorts->pVDYOffsets != NULL)
		{
			MEAS_FREEZE_DIRECT(VDY_MEAS_ID_OFFSETS, proPorts->pVDYOffsets, sizeof(VDYOffsets_t));
		}
#if ( (!defined(CFG_VDY_DIS_CURVE_OUTPUT)) || (!CFG_VDY_DIS_CURVE_OUTPUT) )
		if(proPorts->pVDYEstCurves != NULL)
		{
			MEAS_FREEZE_DIRECT(VDY_MEAS_ID_EST_CURVES, proPorts->pVDYEstCurves, sizeof(VDYEstCurves_t));
		}
#endif
		if(proPorts->pVDYErrors != NULL)
		{
			MEAS_FREEZE_DIRECT(VDY_MEAS_ID_ERRORS, proPorts->pVDYErrors, sizeof(VDYErrors_t));
		}

		if(proPorts->pNVMWrite != NULL)
		{
			MEAS_FREEZE_DIRECT(VDY_MEAS_ID_NVM_WRITE, proPorts->pNVMWrite, sizeof(VDYNvIoData_t));
		}

#if ( defined(CFG_VDY_SET_DEM_EVENTS) && (CFG_VDY_SET_DEM_EVENTS) )
      if ((services->pfDem_SetEventStatus) != (void *)NULL)
      {
          /* Set DEM events if any */
        vdySetDEMEvents(proPorts->pVDYErrors, services);
      }
#endif

    }
    else
    {
      /* no service functions available, skip meas output */
    }
#else
    proPorts->pVehicleDynamicSignals->uiTimeStamp = reqPorts->pCtrl->uiTimeStamp;
    proPorts->pVehicleDynamicSignals->uiCycleCounter = VDYIn.Frame.CycleCnt;
#endif
  }

  /* End profiling */
#if ( defined(VDY_PROFILING_ENABLED) && (VDY_PROFILING_ENABLED == 1) )
  if(services->pfRTAAlgoServiceAddEvent != NULL)
  {
	  VDY_PROF_STOP(services->pfRTAAlgoServiceAddEvent, VDY_PROF_ID_ALL);
  }  
#endif
#if (CFG_VDY_MFC)  
  return ret_Exec;
#endif
}


/* **********************************************************************
	Unit Design for vdyProcess is found in Declaration Section
**************************************************************************** */
/* <ln_offset:2 PCLINT Error 578: reviewer name: Frank Wolter date: 09-07-2013 reason: parameter only hidden if not used at all, implementation to keep same code with and without services */
STATIC_MTD void vdyProcess(const reqVdyPrtList_t *reqPorts, VDYInputData_t *VDYIn, proVdyPrtList_t *proPorts, const AS_t_ServiceFuncts * services)
{
  /* Local instance of some NVM data used to copy it from const input pointer and modify them */
  VDYNvData_t VDYNvData;

  /* Setup the version */
  VDYIn->Frame.Version = (uint32)VDY_SW_VERSION_NUMBER;
/* <ln_offset:-1 PCLINT Error 845: reviewer name: Jochen Spruck date: 27-09-2010 reason: sub versions could be zero */
/* <ln_offset:-2 PCLINT Error 835: reviewer name: Jochen Spruck date: 27-09-2010 reason: sub versions could be zero */
/* <ln_offset:-3 MISRA Rule 10.5: reviewer name: Jochen Spruck date: 27-09-2010 reason: sub versions could be zero */

  /* Increment execution cyle counter */
  VDYIn->Frame.CycleCnt = VDYEnvFrmCnt.ExecCntr;
  VDYEnvFrmCnt.ExecCntr++;

  #if ( (defined(CFG_VDY_REAR_WHEEL_STEERING)) && (CFG_VDY_REAR_WHEEL_STEERING) ) 
  #if (BSW_VEH_PAR_INTFVER >= 9U)
    /*manipulate the Steering wheel angle as effective steering wheel angle
    considering the rear wheel angle for 4 wheel steering ( based on steering wheel number parameter */
  if (reqPorts->pVehicleParameter->VehParAdd.SteeringWheelNumber == FOUR_WHEEL_STEERING)
  #endif
  {
    /* check the valididty of both signals and non zero condition for Steering ratio*/
    if ( (VDY_GET_IO_STATE(VDY_SIN_POS_SWA, VDYIn->Signals.State) != VDY_IO_STATE_INVALID) &&
              (VDY_GET_IO_STATE(VDY_SIN_POS_SWA, VDYIn->Signals.State) != VDY_IO_STATE_INIT)&&
              (VDY_GET_IO_STATE(VDY_SIN_POS_SWA, VDYIn->Signals.State) != VDY_IO_STATE_NOTAVAIL) ) 
    {

      if ( (VDY_GET_IO_STATE(VDY_SIN_POS_RSTA, VDYIn->Signals.State) != VDY_IO_STATE_INVALID)&&
             (VDY_GET_IO_STATE(VDY_SIN_POS_RSTA, VDYIn->Signals.State) != VDY_IO_STATE_INIT)&&
             (VDY_GET_IO_STATE(VDY_SIN_POS_RSTA, VDYIn->Signals.State) != VDY_IO_STATE_NOTAVAIL) )
      {

        if ( CML_f_IsNonZero(VDYIn->Parameter.SteeringRatio.swa.rat[1] ))
        {
		   VDYIn->Signals.StWheelAngle = ( (VDYIn->Signals.StWheelAngle/ VDYIn->Parameter.SteeringRatio.swa.rat[1] ) - VDYIn->Signals.RearWhlAngle )*
                                            (VDYIn->Parameter.SteeringRatio.swa.rat[1]) ;
        }
      }
    }
  } 

  #endif

  /* Monitor input signals and parameter only if the vdy is in running mode and INIT mode*/
  vdyMonitorInput(VDYIn, proPorts->pVDYErrors);


  /* Initalizing the bRollerTestBench variable*/
  #if(VDY_VEH_DYN_INTFVER >= 8U)
  proPorts->pVehicleDynamicSignals->MotionState.bRollerTestBench = (uint8)FALSE;
  #endif
#if (!CFG_VDY_MFC)
  /* Process velocity during roll bench detection or Plant Mode*/
  if(( b_RTBDetection == TRUE ) || (VDYIn->Frame.ProductionMode == TRUE)) 
  {
  #if((VDY_VEH_DYN_INTFVER < 8U) || (BSW_VDY_CTRL_DATA_INTFVER < 3U))
  {
    VDYIn->Signals.VehVelocityExt = 0;
    VDYIn->Signals.WhlVelFrLeft = 0;
    VDYIn->Signals.WhlVelFrRight = 0;
    VDYIn->Signals.WhlVelReLeft = 0;
    VDYIn->Signals.WhlVelReRight = 0;
  }
  #elif((VDY_VEH_DYN_INTFVER >= 8U) || (BSW_VDY_CTRL_DATA_INTFVER >= 3U))
  {
    /* not setting the corrected ego speed to zero. instead set the new flag.  */
    proPorts->pVehicleDynamicSignals->MotionState.bRollerTestBench = true;
    if ((CORRECTED_EGO_SPEED_IS_ZERO_ON_ROLLER_BENCH == 1) || (VDYIn->Frame.ProductionMode == TRUE))
    {
      VDYIn->Signals.VehVelocityExt = 0;
      VDYIn->Signals.WhlVelFrLeft = 0;
      VDYIn->Signals.WhlVelFrRight = 0;
      VDYIn->Signals.WhlVelReLeft = 0;
      VDYIn->Signals.WhlVelReRight = 0;
    }    
  }
  #endif
  }
  #endif

  /* VDY Pre Processing setup output states in condition of input states */
  vdyPreProcess( reqPorts, VDYIn, &VDYNvData, proPorts);

  /* Process VDY handcode modules */
  vdyHandcodeProcess( reqPorts, VDYIn, proPorts, services);

  /* Interface between handcode (hd) and autocde (ac) */
  vdyInterfaceHand2Auto( VDYIn, &vdy_internal_data, &VDYModIf);

  /* Process VDY autocode modules */
  vdyAutocodeProcess( reqPorts, VDYIn, &VDYNvData, proPorts->pVDYErrors, services, proPorts);

  /* Interface between autocde (ac) and  handcode (hd) */
  vdyInterfaceAuto2Hand( &vdy_internal_data, &VDYModIf);

  /* VDY Post Processing setup output states in condition of input states */
  vdyPostProcess( reqPorts, VDYIn, &VDYNvData, proPorts);

  /* Transfer component input and internal data to data acquisition */
  vdyEnvMeasFreezeInternal(services, VDYIn);

  /* Transfer component output interface data to data acquisition */
#if (CFG_VDY_INT_GYRO)
  MEAS_FREEZE_DIRECT(VDY_MEAS_ID_NV_YWRT, proPorts->pYwrtTempTable, sizeof(VDYNvYwrtLearnTable_t));
  /* <ln_offset:-1 PCLINT Error 717: reviewer name: Jochen Spruck date: 27-09-2010 reason: proven in use */
#endif
  MEAS_FREEZE_DIRECT(VDY_MEAS_ID_NVMEM_AUTO,&VDYNvData,sizeof(VDYNvData_t)); /* MISRA Rule 11.4: reviewer name: Jochen Spruck date: 27-09-2010 reason: proven in use, meas freeze macro  */
  /* <ln_offset:-1 PCLINT Error 717: reviewer name: Jochen Spruck date: 27-09-2010 reason: proven in use, meas freeze macro  */
}


/* **********************************************************************
	Unit Design for vdyInit is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyInit(const reqVdyPrtList_t *reqPorts, VDYInputData_t *VDYIn, const proVdyPrtList_t *proPorts, const AS_t_ServiceFuncts * services)
{
  /* Init cycle counters */
  VDYEnvFrmCnt.ExecCntr = 0U;
  VDYIn->Frame.CycleCnt = 0U;

  /* copy input signals */
  (void)vdy_memcpy_s(&VDYIn->Signals, &reqPorts->pVehicleInputSignals->VehSigMain, sizeof(VehSigMain_t));
  /* copy input parameters */
  (void)vdy_memcpy_s(&VDYIn->Parameter, &reqPorts->pVehicleParameter->VehParMain, sizeof(VehParMain_t));
  /* copy input signals to debouncing buffer */
  (void)vdy_memcpy_s(&s_LastInputSignals, &reqPorts->pVehicleInputSignals->VehSigMain, sizeof(VehSigMain_t));
  /* clear debouncing counter */
  (void)vdy_memset_s(u_DebouceCounter, 0x00, VDY_SIN_POS_MAX);

#if( (defined(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))&&(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))
 {
  VDYIoState_t ioStateSSG;
  VDYIoState_t ioStateWLD;
  /* SSG and WLD offset writing in init mode */
   if(reqPorts->pNVMRead->State == NVM_CLEARED)
   {
	   (void)vdy_memset_s(&proPorts->pNVMWrite->SlfstGrad  , 0 , sizeof(VDYNvSlfStGradCal_t));
	   (void)vdy_memset_s(&proPorts->pNVMWrite->Wld  , 0 , sizeof(VDYNvWldCal_t));
   }
   else
   {
     proPorts->pNVMWrite->SlfstGrad = reqPorts->pNVMRead->SlfstGrad;
     proPorts->pNVMWrite->Wld = reqPorts->pNVMRead->Wld;
#if( (defined(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))&&(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))
	 proPorts->pNVMWrite->SlfstGrad.Dummy = VDY_ZERO_U;
	 proPorts->pNVMWrite->Wld.Wld_rear = VDY_ZERO_F;
	 proPorts->pNVMWrite->Wld.Wld_rear_quality = 0;
#endif
  
    ioStateSSG = VDY_GET_NVM_IO_STATE(VDY_NVM_POS_SSG, &reqPorts->pNVMRead->State);
	/* PRQA S 2986 EOF */
	/* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: Out of Scope of VDY */
    VDY_SET_NVM_IO_STATE(VDY_NVM_POS_SSG, ioStateSSG, &proPorts->pNVMWrite->State);

    ioStateWLD = VDY_GET_NVM_IO_STATE(VDY_NVM_POS_WLD, &reqPorts->pNVMRead->State);
    VDY_SET_NVM_IO_STATE(VDY_NVM_POS_WLD, ioStateWLD, &proPorts->pNVMWrite->State);
   }
 }
#endif

  /* copy input signals for signal peak detection */
  vdyInitForCheckSignalPeakErrors(VDYIn);


  /* Initialization of component */
  vdyInitProcess(reqPorts, VDYIn, proPorts);

  vdyEnvMeasFreezeInternal(services,VDYIn);

  /* Init sequence package counter */
  #if ( defined(VDY_FREEZE_INIT_SEQUENCE) && (VDY_FREEZE_INIT_SEQUENCE) )
  VDY_SET_ALL_SEQUENCE_STATES_TO_INIT(sSequenceInitState);
  InitPackageID = 0U;
  #endif

  /* Init acceleration velocity filter */
  #if (!(CFG_VDY_USE_EX_LONG_ACCEL) && (CFG_VDY_USE_EX_LONG_VELO))
  /* External velocity without related acceleration is provided */
  oldVelocityIn = s_LastInputSignals.VehVelocityExt;
  #endif

  vdy_ye_k.u_CurveFaultCounter = 0U;
  vdy_ye_k.u_YawFaultCounter = 0U;
  vdy_ye_k.u_DICurveFaultCounter = 0U;
  #if ( (defined(CFG_VDY_REDUCE_CURVE_ERROR)) && (CFG_VDY_REDUCE_CURVE_ERROR) )
  u_count = 0U;
  #endif
#if(!CFG_VDY_MFC)
  b_RTBDetection = false;
#endif

  return;
}


/* **********************************************************************
	Unit Design for vdyGetConfig is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyGetConfig(void)
{
  static uint8 nCounter = 0U;
  VDYConfig_t  VDYConfig;

  if (nCounter < (VDY_FIFTY_U))
  {
    nCounter++;
  }
  else
  {
    VDYConfig.Version                                       = VDY_CUSTOM_VERSION_NUMBER;        /* Store custom version number  */
    VDYConfig.cfg_vdy_yw_dyn_avg                            = CFG_VDY_YW_DYN_AVG;    /* Enable dynamic gyro offst compensation */
    VDYConfig.cfg_vdy_ex_ywr_nvm                            = CFG_VDY_EX_YWR_NVM;    /* Enable offset storage  in nonvolatile Memory */
    VDYConfig.cfg_vdy_int_gyro                              = CFG_VDY_INT_GYRO;      /* Enable internal yaw rate sensor processing */
    VDYConfig.cfg_vdy_fpm_754                               = CFG_VDY_FPM_754;       /* Enable optimized math functio approximation  */
    VDYConfig.cfg_vdy_use_ex_long_accel                     = CFG_VDY_USE_EX_LONG_ACCEL; /* Use external provided longitudinal acceleration signal  */
    VDYConfig.cfg_vdy_use_ex_long_velo                      = CFG_VDY_USE_EX_LONG_VELO;  /* Use external provided longitudinal velocity signal  */
    VDYConfig.cfg_vdy_mot_state                             = CFG_VDY_MOT_STATE;         /*  Enable motion state processing */
    VDYConfig.cfg_vdy_do_velocity_corr                      = CFG_VDY_DO_VELOCITY_CORR;  /*  Enables the velocity correction   */
    VDYConfig.vel_corr_aln                                  = VEL_CORR_ALN;  /*  Enables the velocity correction   */
    VDYConfig.vel_corr_hist_stationary_targets              = VEL_CORR_HIST_STATIONARY_TARGETS;  /*  Enables the velocity correction   */

#if ( (defined(CFG_VDY_USE_CORRECT_VELO_CORR_VAR)) && (CFG_VDY_USE_CORRECT_VELO_CORR_VAR) )
    VDYConfig.cfg_vdy_use_correct_velo_corr_var        = CFG_VDY_USE_CORRECT_VELO_CORR_VAR;
#else
    VDYConfig.cfg_vdy_use_correct_velo_corr_var             = 0;
#endif

#if defined(CFG_VDY_ROLLBENCH_DETECTION)
    VDYConfig.cfg_vdy_rollbench_detection                   = CFG_VDY_ROLLBENCH_DETECTION;	/*  Enables the roll bench detection   */
#else
    VDYConfig.cfg_vdy_rollbench_detection                   = 0U;
#endif

    VDYConfig.cfg_vdy_use_ext_proc_curvature                = CFG_VDY_USE_EXT_PROC_CURVATURE;  /* Enables usage of external curve as vdy output curve  */
    VDYConfig.cfg_vdy_use_ext_proc_yaw_rate                 = CFG_VDY_USE_EXT_PROC_YAW_RATE;   /* Enables usage of external yaw rate as vdy output yaw rate  */
    VDYConfig.cfg_vdy_use_ext_proc_side_slip_angle          = CFG_VDY_USE_EXT_PROC_SIDE_SLIP_ANGLE;  /* Enables usage of external side slip angle as vdy ouput side slip angle  */

#if defined(CFG_VDY_DIS_SWA_OFFSET_COMP)
    VDYConfig.cfg_vdy_dis_swa_offset_comp                   = CFG_VDY_DIS_SWA_OFFSET_COMP;
#else
    VDYConfig.cfg_vdy_dis_swa_offset_comp                   = 0U;
#endif

#if defined(CFG_VDY_DIS_YWR_OFFSET_COMP)
    VDYConfig.cfg_vdy_dis_ywr_offset_comp                   = CFG_VDY_DIS_YWR_OFFSET_COMP;
#else
    VDYConfig.cfg_vdy_dis_ywr_offset_comp                   = 0U;
#endif

#if defined(CFG_VDY_DIS_WHS_OFFSET_COMP)
    VDYConfig.cfg_vdy_dis_whs_offset_comp                   = CFG_VDY_DIS_WHS_OFFSET_COMP;
#else
    VDYConfig.cfg_vdy_dis_whs_offset_comp                   = 0U;
#endif

#if defined(CFG_VDY_DIS_LAT_OFFSET_COMP)
    VDYConfig.cfg_vdy_dis_lat_offset_comp                   = CFG_VDY_DIS_LAT_OFFSET_COMP;
#else
    VDYConfig.cfg_vdy_dis_lat_offset_comp                   = 0U;
#endif

#if defined(CFG_VDY_USE_EXT_PROC_UNDERSTEER_GRAD)
    VDYConfig.cfg_vdy_use_ext_proc_understeer_grad          = CFG_VDY_USE_EXT_PROC_UNDERSTEER_GRAD;
#else
    VDYConfig.cfg_vdy_use_ext_proc_understeer_grad          = 0U;
#endif

    VDYConfig.vdy_use_learned_understeer_grad               = VDY_USE_LEARNED_UNDERSTEER_GRAD;  /* If the learned understeer gradiend should be used */
    VDYConfig.vdy_use_est_wld_dep                           = VDY_USE_EST_WLD_DEP;               /* If the estimated wheel load dep should be used */

#if defined(CFG_VDY_USE_VELO_MONITOR)
    VDYConfig.cfg_vdy_use_velo_monitor                      = CFG_VDY_USE_VELO_MONITOR;
#else
    VDYConfig.cfg_vdy_use_velo_monitor                      = 0U;
#endif

#if defined(CFG_VDY_YWR_OFFSET_MONITOR)
    VDYConfig.cfg_vdy_ywr_offset_monitor                    = CFG_VDY_YWR_OFFSET_MONITOR;
#else
    VDYConfig.cfg_vdy_ywr_offset_monitor                    = 0U;
#endif

#if defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)
    VDYConfig.cfg_vdy_dis_wheel_pre_processing              = CFG_VDY_DIS_WHEEL_PRE_PROCESSING;
#else
    VDYConfig.cfg_vdy_dis_wheel_pre_processing              = 0U;
#endif

#if defined(CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING)
    VDYConfig.cfg_vdy_dis_yaw_sensor_pre_processing         = CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING;
#else
    VDYConfig.cfg_vdy_dis_yaw_sensor_pre_processing         = 0U;
#endif

#if defined(CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING)
    VDYConfig.cfg_vdy_dis_yaw_sensor_offs_pre_filtering     = CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING;
#else
    VDYConfig.cfg_vdy_dis_yaw_sensor_offs_pre_filtering     = 0U;
#endif

#if defined(CFG_VDY_DIS_YAW_SENSOR_OUTPUT)
    VDYConfig.cfg_vdy_dis_yaw_sensor_output                 = CFG_VDY_DIS_YAW_SENSOR_OUTPUT;
#else
    VDYConfig.cfg_vdy_dis_yaw_sensor_output                 = 0U;
#endif

#if defined(CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING)
    VDYConfig.cfg_vdy_dis_lat_accel_sensor_pre_processing   = CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING;
#else
    VDYConfig.cfg_vdy_dis_lat_accel_sensor_pre_processing   = 0U;
#endif

#if defined(CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING)
    VDYConfig.cfg_vdy_dis_stw_angle_sensor_pre_processing   = CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING;
#else
    VDYConfig.cfg_vdy_dis_stw_angle_sensor_pre_processing   = 0U;
#endif

#if defined(CFG_VDY_DIS_SIDE_SLIP_ANGLE_ESTIMATION)
    VDYConfig.cfg_vdy_dis_side_slip_angle_estimation        = CFG_VDY_DIS_SIDE_SLIP_ANGLE_ESTIMATION;
#else
    VDYConfig.cfg_vdy_dis_side_slip_angle_estimation        = 0U;
#endif

#if defined(CFG_VDY_GEN_VELOCITY_VARIANCE)
    VDYConfig.cfg_vdy_gen_velocity_variance                 = CFG_VDY_GEN_VELOCITY_VARIANCE;
#else
    VDYConfig.cfg_vdy_gen_velocity_variance                 = 0U;
#endif

#if defined(CFG_VDY_ALIGNMENT_OFFSET_MONITOR)
    VDYConfig.cfg_vdy_alignment_offset_monitor              = CFG_VDY_ALIGNMENT_OFFSET_MONITOR;
#else
    VDYConfig.cfg_vdy_alignment_offset_monitor              = 0U;
#endif

    VDYConfig.cfg_vdy_dis_functional_safety_mon             = CFG_VDY_DIS_FUNCTIONAL_SAFETY_MON;
    VDYConfig.cfg_vdy_64bit_timestamp_interv                = CFG_VDY_64BIT_TIMESTAMP_INTERV;
    VDYConfig.cfg_vdy_dis_curve_output                      = CFG_VDY_DIS_CURVE_OUTPUT;

#if defined(CFG_VDY_CALC_VDY_TIMING)
    VDYConfig.cfg_vdy_calc_vdy_timing                       = CFG_VDY_CALC_VDY_TIMING;              /* If the timing should be calculated */
#else
    VDYConfig.cfg_vdy_calc_vdy_timing                       = 0U;
#endif

    VDYConfig.cfg_vdy_fs_velo_corr_mon                      = CFG_VDY_FS_VELO_CORR_MON;
    VDYConfig.cfg_vdy_mon_output_peaks                      = CFG_VDY_MON_OUTPUT_PEAKS;
    VDYConfig.vdy_profiling_enabled                         = VDY_PROFILING_ENABLED;
    VDYConfig.cfg_vdy_use_algocompstate                     = CFG_VDY_USE_ALGOCOMPSTATE;

#if defined(CFG_VDY_SET_DEM_EVENTS)
    VDYConfig.cfg_vdy_set_dem_events                        = CFG_VDY_SET_DEM_EVENTS;
#else
    VDYConfig.cfg_vdy_set_dem_events                        = 0U;
#endif
    VDYConfig.cfg_vdy_fs_velo_conf_mon_fault                =  CFG_VDY_FS_VELO_CONF_MON_FAULT; /* Enables setting DEM event VelMon*/                
    VDYConfig.cfg_vdy_truck_corrfact                        =  CFG_VDY_TRUCK_CORRFACT; /* Enables the increase of correction factor for trucks */                            
    VDYConfig.cfg_vdy_debounce_outputs                      =  CFG_VDY_DEBOUNCE_OUTPUTS; /* Enables the max debouncing ouput counter */                          
    VDYConfig.cfg_vdy_turntable_detection                   =  CFG_VDY_TURNTABLE_DETECTION; /* Enables the Turn Table detection and limit max. delta 4deg/sec yaw rate offset compensation at one learning cycle */                       
    VDYConfig.cfg_vdy_corrfact_ars4d2                       =  CFG_VDY_CORRFACT_ARS4D2; /* Enables the increase of correction factor to 30% for ARS4D2 */                           
    VDYConfig.cfg_vdy_swa_ay_yaw_ssd_wld_dis_nvm_valid_check=  CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK; /* Disables Valid Or Invalid check before reading NVM and writes NVM data  in every vdy cycle to the provide port for camera(MDB) projects for steering wheel angle , Ay ,Yaw offset also SSD and WLD data */    
    VDYConfig.cfg_vdy_velo_variance_check                   =  CFG_VDY_VELO_VARIANCE_CHECK; /* Enables the velocity variance check for setting the velocity not available DEM  */                       
    VDYConfig.cfg_vdy_velo_monitor_min_max                  =  CFG_VDY_VELO_MONITOR_MIN_MAX; /* Enables the corrected velocity monitoring based on the new minimum and maximum velocity signals   */                      
    VDYConfig.cfg_vdy_reduce_curve_error                    =  CFG_VDY_REDUCE_CURVE_ERROR; /* Enables the code for reducing the curve error after software reset*/                        
    VDYConfig.cfg_vdy_nvm_learn_data_error                  =  CFG_VDY_NVM_LEARN_DATA_ERROR; /* Enable DEM relates NVM learning values to ensure no corrupted data is written to flash memory */                      
    VDYConfig.cfg_vdy_polyspace_error_disable               =  CFG_VDY_POLYSPACE_ERROR_DISABLE; /* Disable unused function throwing red error in polyspace  */                  
    VDYConfig.cfg_vdy_vdynviodatard_measfreez_enable        =  CFG_VDY_VDYNVIODATARD_MEASFREEZ_ENABLE; /* Enable measfreezing of VDY Structure VDYNvIoDataRD  */            
    VDYConfig.cfg_vdy_init_mode_as_startup_mode             =  CFG_VDY_INIT_MODE_AS_STARTUP_MODE; /* Enables the switch to stop toggling the DEM for trucks */                 
    VDYConfig.cfg_vdy_rear_wheel_steering                   =  CFG_VDY_REAR_WHEEL_STEERING; /* Enables the switch to Rear Wheel Steer */                       
    VDYConfig.cfg_vdy_fs_yr_vs_wsp_enable                   =  CFG_VDY_FS_YR_VS_WSP_ENABLE; /* Enables the FS_YR_VS_WSP DEM  */                       
    VDYConfig.cfg_vdy_bmw_long_accel_model                  =  CFG_VDY_BMW_LONG_ACCEL_MODEL; /* Enables the BMW acceleration Model  */                      
    VDYConfig.cfg_vdy_yawrate_variance_check                =  CFG_VDY_YAWRATE_VARIANCE_CHECK; /* Enables the yaw rate variance check for yaw rate not available DEM */                   
    VDYConfig.cfg_vdy_fs_velo_corr_mon_error                =  CFG_VDY_FS_VELO_CORR_MON_ERROR; /* Enables the monitor of corrected velocity and ALN velocity error */                    
    VDYConfig.cfg_vdy_fs_veh_corr_mon_toggling              =  CFG_VDY_FS_VEH_CORR_MON_TOGGLING; /* Enables the code to stop toggling of FS_VEH_CORR_MON DEM*/                   
    VDYConfig.cfg_vdy_mfc                                   =  CFG_VDY_MFC; /* Enables MFC specific logic */ 
    VDYConfig.cfg_vdy_int_tcs_abs                           =  CFG_VDY_INT_TCS_ABS; /*Enables usage of ABS/TCS info in velocity and accel estimation */
    VDYConfig.cfg_vdy_mfc_vx                                =  CFG_VDY_MFC_VX; /* MFC5xx specific switch */

    nCounter = 0U;
    VDYInternal.VDYConfig = VDYConfig;
  }
}


/* **********************************************************************
	Unit Design for vdyLearnInitWithParams is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyLearnInitWithParams(const VDYInputData_t *input, VDYNvData_t * nvdata)
{
  /* init learn self steering gradient with the vehicle parameter if the parameter is available and the nvm not yet initialized */
  if (    (nvdata->Read.SlfstGrad.CalStatus == (sint8)0)
       && (VDY_GET_IO_STATE(VDY_PAR_POS_SSG, input->Parameter.State) == (VDYIoStateTypes_t)VDY_IO_STATE_VALID)  )
  {
    nvdata->Read.SlfstGrad.SlfStGrad = input->Parameter.SelfSteerGrad;
	/* PRQA S 4542 EOF */
	/* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: Out of Scope of VDY */
	/* PRQA S 1841 EOF */
	/* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: Functional Safe */
    nvdata->Read.SlfstGrad.SlfStGradMax = (uint8) (ROUND_TO_UINT(VDY_NVM_USTG_INV_SCALE*input->Parameter.SelfSteerGrad) & VDY_X_FF);
    nvdata->Read.SlfstGrad.SlfStGradMin = (uint8) (ROUND_TO_UINT(VDY_NVM_USTG_INV_SCALE*input->Parameter.SelfSteerGrad) & VDY_X_FF);

    /* Set CalStatus to 1, Self steering gradient is initialized with vehicle parameter */
    nvdata->Write.SlfstGrad.CalStatus = (sint8)1;
  }
  else
  {
    nvdata->Write.SlfstGrad.CalStatus = nvdata->Read.SlfstGrad.CalStatus;
    VDY_SET_NVM_IO_STATE(VDY_NVM_POS_SSG, VDY_IO_STATE_INVALID, &nvdata->Read.State);
    VDY_SET_NVM_IO_STATE(VDY_NVM_POS_SSG, VDY_IO_STATE_INVALID, &nvdata->Write.State);
  }


  /* init learn wheel load dependency with the vehicle parameter if the parameter is available and the nvm not yet initialized */
  if (    (nvdata->Read.Wld.Wld_front_quality == (uint8)0U)
       && (input->Parameter.WhlLoadDepFrontAxle > VDY_ZERO_F)
       && (VDY_GET_IO_STATE(VDY_PAR_POS_WHLDFR, input->Parameter.State) == (VDYIoStateTypes_t)VDY_IO_STATE_VALID)  )
  {
    nvdata->Read.Wld.Wld_front = input->Parameter.WhlLoadDepFrontAxle;
    nvdata->Write.Wld.Wld_front = nvdata->Read.Wld.Wld_front;

    /* Set quality to 1, wheel load dependency is initialized with vehicle parameter */
    nvdata->Write.Wld.Wld_front_quality = 1U;
  }
  else
  {
    nvdata->Write.Wld.Wld_front_quality = nvdata->Read.Wld.Wld_front_quality;
    VDY_SET_NVM_IO_STATE(VDY_NVM_POS_WLD, VDY_IO_STATE_INVALID, &nvdata->Read.State);
    VDY_SET_NVM_IO_STATE(VDY_NVM_POS_WLD, VDY_IO_STATE_INVALID, &nvdata->Write.State);
  }
}



/* **********************************************************************
	Unit Design for vdyPreProcess is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyPreProcess( const reqVdyPrtList_t *reqPorts, const VDYInputData_t * input, VDYNvData_t *VDYNvData, const proVdyPrtList_t *proPorts)
{
  VDYIoState_t iostatYwr;

  /* Convert cycle time to float value with unit sec */
  VDY_SET_CYCLE_TIME(input->Frame.CycleTime);

  /* In case of Startup state reset first cycle done flag */
#if (!CFG_VDY_MFC)
  if (    (!VDY_CTRL_GET_STATE((VDYCtrlState_t)VDY_CTRL_STATE_RUNNING, input->Frame.CtrlMode))
       && (!VDY_CTRL_GET_STATE((VDYCtrlState_t)VDY_CTRL_STATE_INIT, input->Frame.CtrlMode))  )
#else
  if( (VDY_CTRL_GET_STATE( (BaseOpMode_t)BASE_OM_RESET, input->Frame.OpMode)) )
#endif
  {
    /* Clear flag to indicate that first cycle execution has not been completed */
	/* PRQA S 1294 EOF */
	/* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: Intended */
    VDY_RESET_FIRST_CYCLE_DONE;
  }

  /* copy the autocode nvm data from the request and provide port to a local buffer */
  if(reqPorts->pNVMRead->State == NVM_CLEARED)
  {
    (void)vdy_memset_s(&VDYNvData->Read.Wld , 0 , sizeof(VDYNvWldCal_t));
    (void)vdy_memset_s(&VDYNvData->Read.SlfstGrad , 0 , sizeof(VDYNvSlfStGradCal_t));
    (void)vdy_memset_s(&VDYNvData->Write.Wld , 0 , sizeof(VDYNvWldCal_t));
    (void)vdy_memset_s(&VDYNvData->Write.SlfstGrad , 0 , sizeof(VDYNvSlfStGradCal_t));
  }
  else
  {
#if ( (defined(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK)) && (CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK) )
  /* check for valid values read from NVM */
  if ((reqPorts->pNVMRead->SlfstGrad.SlfStGrad <= MAXIMUM_SELF_STEERING_GRAD)
      && (reqPorts->pNVMRead->SlfstGrad.CalStatus >= 0)&&(reqPorts->pNVMRead->SlfstGrad.CalStatus <= 1))
    {
#endif
    VDYNvData->Read.SlfstGrad  = reqPorts->pNVMRead->SlfstGrad;
#if ( (defined(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK)) && (CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK) )
  /* check for valid values read from NVM */
    }
  else
    {
	 (void)vdy_memset_s(&VDYNvData->Read.SlfstGrad , 0 , sizeof(VDYNvSlfStGradCal_t));
    }
  /* check for valid values read from NVM */
  if ((reqPorts->pNVMRead->Wld.Wld_front >= MINIMUM_WHEEL_LOAD_DEP) && (reqPorts->pNVMRead->Wld.Wld_front <= MAXIMUM_WHEEL_LOAD_DEP)
	  && (reqPorts->pNVMRead->Wld.Wld_front_quality >= 0U) && (reqPorts->pNVMRead->Wld.Wld_front_quality <= 1U))
    {
#endif
    VDYNvData->Read.Wld        = reqPorts->pNVMRead->Wld;
#if ( (defined(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK)) && (CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK) )
  /* check for valid values read from NVM */
    }
  else
    {
	 (void)vdy_memset_s(&VDYNvData->Read.Wld , 0 , sizeof(VDYNvWldCal_t));
    }
#endif

    VDYNvData->Read.State      = reqPorts->pNVMRead->State;
    VDYNvData->Write.Wld       = proPorts->pNVMWrite->Wld;
    VDYNvData->Write.SlfstGrad = proPorts->pNVMWrite->SlfstGrad;
    VDYNvData->Write.State     = proPorts->pNVMWrite->State;
  }

  /* Init learn values ssg and wld with parameter values */
  vdyLearnInitWithParams(input, VDYNvData);

  /* Set output state of velocity (for internal / external velocity) */
#if (CFG_VDY_USE_EX_LONG_VELO)
  /* Feed in external velocity */
  VDYModIf.LongMot.VehVelo    = input->Signals.VehVelocityExt;

  if (VDY_GET_IO_STATE(VDY_SIN_POS_VEHVEL_EXT, input->Signals.State) == VDY_IO_STATE_VALID)
  {
    VDY_SET_IO_STATE(VDY_SOUT_POS_VELOCITY, VDY_IO_STATE_VALID, proPorts->pVehicleDynamicSignals->State);
  }
  else
  {
    VDY_SET_IO_STATE(VDY_SOUT_POS_VELOCITY, VDY_IO_STATE_INVALID, proPorts->pVehicleDynamicSignals->State);
  }
#else
  if (   (VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_FL, input->Signals.State) != (VDYIoStateTypes_t)VDY_IO_STATE_VALID)
      && (VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_FR, input->Signals.State) != (VDYIoStateTypes_t)VDY_IO_STATE_VALID)
      && (VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_RL, input->Signals.State) != (VDYIoStateTypes_t)VDY_IO_STATE_VALID)
      && (VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_RR, input->Signals.State) != (VDYIoStateTypes_t)VDY_IO_STATE_VALID) )
  {
    VDY_SET_IO_STATE(VDY_SOUT_POS_VELOCITY, VDY_IO_STATE_INVALID, proPorts->pVehicleDynamicSignals->State);
  }
  else
  {
    VDY_SET_IO_STATE(VDY_SOUT_POS_VELOCITY, VDY_IO_STATE_VALID, proPorts->pVehicleDynamicSignals->State);
  }
#endif

  /* Set output state of acceleration (for internal / external acceleration) */
#if (CFG_VDY_USE_EX_LONG_ACCEL)
  /* Feed in external acceleration */
  VDYModIf.LongMot.VehAccel     = input->Signals.VehLongAccelExt;
  VDYModIf.LongMot.VehAccelVar  = VDY_PAR_ACCEL_EXT_UNC;

  if (VDY_GET_IO_STATE(VDY_SIN_POS_VEHACL_EXT, input->Signals.State) == VDY_IO_STATE_VALID)
  {
    VDY_SET_IO_STATE(VDY_SOUT_POS_ACCEL, VDY_IO_STATE_VALID, proPorts->pVehicleDynamicSignals->State);
  }
  else
  {
    VDY_SET_IO_STATE(VDY_SOUT_POS_ACCEL, VDY_IO_STATE_INVALID, proPorts->pVehicleDynamicSignals->State);
  }
#else
#if (CFG_VDY_USE_EX_LONG_VELO)
  { 
    /* External velocity without related acceleration is provided */
    VDYModIf.LongMot.VehAccel = vdyDifferentiateCycleTime(VDYModIf.LongMot.VehVelo, oldVelocityIn, VDYModIf.LongMot.VehAccel, VDY_PAR_VEL_DIFF_FT);
    oldVelocityIn = VDYModIf.LongMot.VehVelo;
    VDYModIf.LongMot.VehAccelVar  = VDY_PAR_ACCEL_EXT_UNC;
  }
#endif
  if ( VDY_GET_IO_STATE(VDY_SOUT_POS_VELOCITY,proPorts->pVehicleDynamicSignals->State) == (VDYIoStateTypes_t)VDY_IO_STATE_VALID)
  {
    VDY_SET_IO_STATE(VDY_SOUT_POS_ACCEL, VDY_IO_STATE_VALID, proPorts->pVehicleDynamicSignals->State);
  }
  else
  {
    VDY_SET_IO_STATE(VDY_SOUT_POS_ACCEL, VDY_IO_STATE_INVALID, proPorts->pVehicleDynamicSignals->State);
  }
#endif

  /* Set output motion state and copy the external motion state to the Module interface if external motion state should be used */
#if (!CFG_VDY_MOT_STATE)
  /* if the external direction is valid */
  if (VDY_GET_IO_STATE(VDY_SIN_POS_VMOT, input->Signals.State) == VDY_IO_STATE_VALID)
  {  
    if(input->Signals.VehLongMotStateExt != (VehLongMotStateExt_t)VDY_VEH_MOT_STATE_ROLLING)
    {
      VDYModIf.LongMot.MotState.MotState = VDY_LONG_MOT_STATE_STDST;
      VDYModIf.LongMot.MotState.Confidence = (ucConfidence_t) 100.F;
      /* Set input state to output state */
      VDY_SET_IO_STATE(VDY_SOUT_POS_MOTIONSTATE, VDY_GET_IO_STATE(VDY_SIN_POS_VMOT, input->Signals.State), proPorts->pVehicleDynamicSignals->State);
    }
    else
    {
      /* if the external direction is valid */
      if (VDY_GET_IO_STATE(VDY_SIN_POS_VDIR, input->Signals.State) == VDY_IO_STATE_VALID)
      {  
        switch (input->Signals.VehLongDirExt)
        {
          case VDY_LONG_DIR_FWD: 
            VDYModIf.LongMot.MotState.MotState = VDY_LONG_MOT_STATE_MOVE_FWD;
            VDYModIf.LongMot.MotState.Confidence = (ucConfidence_t) 100.F;
            break;

          case VDY_LONG_DIR_RWD:
            VDYModIf.LongMot.MotState.MotState = VDY_LONG_MOT_STATE_MOVE_RWD;
            VDYModIf.LongMot.MotState.Confidence = (ucConfidence_t) 100.F;
            break;

          case VDY_LONG_DIR_VOID:  /* fallthrough to default */
          default:
            VDYModIf.LongMot.MotState.MotState = VDY_LONG_MOT_STATE_MOVE;
            VDYModIf.LongMot.MotState.Confidence = (ucConfidence_t) 50.F;
            break;
        }
        /* Set input state to output state */
        VDY_SET_IO_STATE(VDY_SOUT_POS_MOTIONSTATE, VDY_GET_IO_STATE(VDY_SIN_POS_VDIR, input->Signals.State), proPorts->pVehicleDynamicSignals->State);
      }
      else
      {
        VDYModIf.LongMot.MotState.MotState = VDY_LONG_MOT_STATE_MOVE;
        VDYModIf.LongMot.MotState.Confidence = (ucConfidence_t) 50.F;
        /* Set input state to output state */
        VDY_SET_IO_STATE(VDY_SOUT_POS_MOTIONSTATE, VDY_GET_IO_STATE(VDY_SIN_POS_VMOT, input->Signals.State), proPorts->pVehicleDynamicSignals->State);
      }
    }
  }
  else
  {
    VDYModIf.LongMot.MotState.MotState = VDY_LONG_MOT_STATE_MOVE;
    VDYModIf.LongMot.MotState.Confidence = (ucConfidence_t) 50.F;
    VDY_SET_IO_STATE(VDY_SOUT_POS_MOTIONSTATE, VDY_IO_STATE_INVALID, proPorts->pVehicleDynamicSignals->State);  
  }
#else
  VDY_SET_IO_STATE(VDY_SOUT_POS_MOTIONSTATE, VDY_IO_STATE_VALID, proPorts->pVehicleDynamicSignals->State);
#endif

  /* Set temp iostatYwr to internal or external yaw rate sensor state */
#if (CFG_VDY_INT_GYRO)
  /* if external yaw rate signal is valid use the external yaw rate signal otherwise the internal */
  if (VDY_GET_IO_STATE(VDY_SIN_POS_YWR, input->Signals.State) == VDY_IO_STATE_VALID)
  {
    iostatYwr = VDY_GET_IO_STATE(VDY_SIN_POS_YWR, input->Signals.State);
  }
  else
  {
    iostatYwr = VDY_GET_IO_STATE(VDY_SIN_POS_YWRINT, input->Signals.State);
  }
#else
#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING) )
  iostatYwr = VDY_GET_IO_STATE(VDY_SIN_POS_YWR, input->Signals.State);
#else
  iostatYwr = VDY_IO_STATE_VALID;
#endif
#endif

  /* Set output yaw rate to input yaw rate state or to state combination of swa, velocity and external input yaw rate state */
#if (CFG_VDY_USE_EXT_PROC_YAW_RATE)
  VDYModIf.YawRate.YawRate  = input->Signals.YawRate;
  VDYModIf.YawRate.Variance = VDY_PAR_YWR_EXT_UNC;

  if (VDY_GET_IO_STATE(VDY_SIN_POS_YWR, input->Signals.State) == VDY_IO_STATE_VALID)
  {
    VDY_SET_IO_STATE(VDY_SOUT_POS_YAWRATE, VDY_IO_STATE_VALID, proPorts->pVehicleDynamicSignals->State);
#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_OUTPUT)) || (!CFG_VDY_DIS_YAW_SENSOR_OUTPUT) )
    proPorts->pALNYawRate->bSenYawRateState = TRUE;
#endif
  }
  else
  {
    VDY_SET_IO_STATE(VDY_SOUT_POS_YAWRATE, VDY_IO_STATE_INVALID, proPorts->pVehicleDynamicSignals->State);
#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_OUTPUT)) || (!CFG_VDY_DIS_YAW_SENSOR_OUTPUT) )
    proPorts->pALNYawRate->bSenYawRateState = FALSE;
#endif
  }
#else
  /* if vdy velocity is less then 5m/s give weightage to SWA for vdy yaw and its quality */
#if (CFG_VDY_USE_EX_LONG_VELO)
  if(input->Signals.VehVelocityExt < 5.0f)
#else
  if (((CML_f_Abs(input->Signals.WhlVelFrLeft) + CML_f_Abs(input->Signals.WhlVelFrRight) + CML_f_Abs(input->Signals.WhlVelReLeft) + CML_f_Abs(input->Signals.WhlVelReRight))*(VDY_ONE_F/VDY_FOUR_F)) < VDY_FIVE_F)
#endif
  {
	  if(
	 /* If steering wheel angle sensor pre processing is enabled */
      #if ((!defined(CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING))
          (((VDY_GET_IO_STATE(VDY_SIN_POS_SWA, input->Signals.State) == (VDYIoStateTypes_t)VDY_IO_STATE_VALID) ||
            (VDY_GET_IO_STATE(VDY_SIN_POS_SWA, input->Signals.State) == (VDYIoStateTypes_t)VDY_IO_STATE_DECREASED)) &&
            (VDY_GET_IO_STATE(VDY_SOUT_POS_VELOCITY, proPorts->pVehicleDynamicSignals->State) == (VDYIoStateTypes_t)VDY_IO_STATE_VALID)) ||
      #endif
            ((iostatYwr == (VDYIoState_t)VDY_IO_STATE_VALID) || (iostatYwr == (VDYIoState_t)VDY_IO_STATE_DECREASED)))
	  {
          VDY_SET_IO_STATE(VDY_SOUT_POS_YAWRATE, VDY_IO_STATE_VALID, proPorts->pVehicleDynamicSignals->State);
          #if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_OUTPUT)) || (!CFG_VDY_DIS_YAW_SENSOR_OUTPUT) )
          proPorts->pALNYawRate->bSenYawRateState = TRUE;
          #endif
	  }
	  else
	  {
          VDY_SET_IO_STATE(VDY_SOUT_POS_YAWRATE, VDY_IO_STATE_INVALID, proPorts->pVehicleDynamicSignals->State);
          #if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_OUTPUT)) || (!CFG_VDY_DIS_YAW_SENSOR_OUTPUT) )
          proPorts->pALNYawRate->bSenYawRateState = FALSE;
          #endif
	  }
  }
  else
  /* if vdy velocity is greater then 5m/s give weightage to Gye model vdy yaw and its quality */
  {
	  if((iostatYwr == (VDYIoState_t)VDY_IO_STATE_VALID) || (iostatYwr == (VDYIoState_t)VDY_IO_STATE_DECREASED))
	  {
          VDY_SET_IO_STATE(VDY_SOUT_POS_YAWRATE, VDY_IO_STATE_VALID, proPorts->pVehicleDynamicSignals->State);
          #if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_OUTPUT)) || (!CFG_VDY_DIS_YAW_SENSOR_OUTPUT) )
          proPorts->pALNYawRate->bSenYawRateState = TRUE;
          #endif
	  }
	  else
     /* If steering wheel angle sensor pre processing is enabled */
	  {
      #if ((!defined(CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING))
      if(( (VDY_GET_IO_STATE(VDY_SIN_POS_SWA, input->Signals.State) == (VDYIoStateTypes_t)VDY_IO_STATE_VALID) ||
           (VDY_GET_IO_STATE(VDY_SIN_POS_SWA, input->Signals.State) == (VDYIoStateTypes_t)VDY_IO_STATE_DECREASED)) &&
           (VDY_GET_IO_STATE(VDY_SOUT_POS_VELOCITY, proPorts->pVehicleDynamicSignals->State) == (VDYIoStateTypes_t)VDY_IO_STATE_VALID))
	  {
           VDY_SET_IO_STATE(VDY_SOUT_POS_YAWRATE, VDY_IO_STATE_DECREASED, proPorts->pVehicleDynamicSignals->State);
           #if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_OUTPUT)) || (!CFG_VDY_DIS_YAW_SENSOR_OUTPUT) )
           proPorts->pALNYawRate->bSenYawRateState = FALSE;
           #endif
	  }
      else
      #endif
	  {
           VDY_SET_IO_STATE(VDY_SOUT_POS_YAWRATE, VDY_IO_STATE_INVALID, proPorts->pVehicleDynamicSignals->State);
           #if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_OUTPUT)) || (!CFG_VDY_DIS_YAW_SENSOR_OUTPUT) )
           proPorts->pALNYawRate->bSenYawRateState = FALSE;
           #endif
	  }
	  }
  }
#endif

  /* Set output curvature to input curvature state or to state combination of swa, velocity and external input yaw rate state */
#if (CFG_VDY_USE_EXT_PROC_CURVATURE)
  VDYModIf.Curve.Curve  = input->Signals.CurveC0Ext;
  VDYModIf.Curve.VarCurve = VDY_PAR_CRV_EXT_UNC;

  if (VDY_GET_IO_STATE(VDY_SIN_POS_CRV, input->Signals.State) == VDY_IO_STATE_VALID)
  {
    VDY_SET_IO_STATE(VDY_SOUT_POS_CURVE, VDY_IO_STATE_VALID, proPorts->pVehicleDynamicSignals->State);
  }
  else
  {
    VDY_SET_IO_STATE(VDY_SOUT_POS_CURVE, VDY_IO_STATE_INVALID, proPorts->pVehicleDynamicSignals->State);
  }
#else
  /* Set curve qualifier directly from VDY yaw */
  VDY_SET_IO_STATE(VDY_SOUT_POS_CURVE, VDY_GET_IO_STATE(VDY_SOUT_POS_YAWRATE, proPorts->pVehicleDynamicSignals->State), proPorts->pVehicleDynamicSignals->State);
#endif

  /* Set output state of side slip angle if side slip angle estimation is not disabled */
#if ((!defined(CFG_VDY_DIS_SIDE_SLIP_ANGLE_ESTIMATION)) || (!CFG_VDY_DIS_SIDE_SLIP_ANGLE_ESTIMATION))
#if (CFG_VDY_USE_EXT_PROC_SIDE_SLIP_ANGLE)

  VDYModIf.SideSlipAngle.SideSlipAngle = input->Signals.SideSlipAngleExt;
  VDYModIf.SideSlipAngle.Variance      = VDY_PAR_SSA_EXT_UNC;

  /* Set output state of slip angle depending on slip angle input state */
  VDY_SET_IO_STATE(VDY_SOUT_POS_SLIPANGLE, VDY_GET_IO_STATE(VDY_SIN_POS_SSA, input->Signals.State), proPorts->pVehicleDynamicSignals->State);

#else  /* CFG_VDY_USE_EXT_PROC_SIDE_SLIP_ANGLE */
  /* set output state of slip angle depending on inputs */
  if (    ( iostatYwr != VDY_IO_STATE_VALID)
       || ( VDY_GET_IO_STATE(VDY_SOUT_POS_VELOCITY, input->Signals.State) != VDY_IO_STATE_VALID)
       || ( VDY_GET_IO_STATE(VDY_SIN_POS_LATA, input->Signals.State) != VDY_IO_STATE_VALID)  )
  {
    /* if yawrate, velocity or lataccel are invalid, output SideSlipAngle is also invalid */
    VDY_SET_IO_STATE(VDY_SOUT_POS_SLIPANGLE, VDY_IO_STATE_INVALID, proPorts->pVehicleDynamicSignals->State);
  }
  else
  {
    /* if yawrate, velocity and lataccel are valid, output SideSlipAngle is also valid */
    VDY_SET_IO_STATE(VDY_SOUT_POS_SLIPANGLE, VDY_IO_STATE_VALID, proPorts->pVehicleDynamicSignals->State);
  }
#endif
#else  /* CFG_VDY_DIS_SIDE_SLIP_ANGLE_ESTIMATION */
  VDY_SET_IO_STATE(VDY_SOUT_POS_SLIPANGLE, VDY_IO_STATE_INVALID, proPorts->pVehicleDynamicSignals->State);
#endif

  /* set output state of lateral acceleration depending on vdy yaw rate and velocity */
  if (((VDY_GET_IO_STATE(VDY_SOUT_POS_YAWRATE, proPorts->pVehicleDynamicSignals->State) == (VDYIoStateTypes_t)VDY_IO_STATE_VALID) ||
       (VDY_GET_IO_STATE(VDY_SOUT_POS_YAWRATE, proPorts->pVehicleDynamicSignals->State) == (VDYIoStateTypes_t)VDY_IO_STATE_DECREASED)) &&
       (VDY_GET_IO_STATE(VDY_SOUT_POS_VELOCITY, proPorts->pVehicleDynamicSignals->State) == (VDYIoStateTypes_t)VDY_IO_STATE_VALID))
  {
    /* if input vdy yawrate and velocity are valid, output Lataccel is also valid */
    VDY_SET_IO_STATE(VDY_SOUT_POS_LATERALACCEL, VDY_IO_STATE_VALID, proPorts->pVehicleDynamicSignals->State);
  }
  else
  {
    VDY_SET_IO_STATE(VDY_SOUT_POS_LATERALACCEL, VDY_IO_STATE_INVALID, proPorts->pVehicleDynamicSignals->State);
  }

  /* Set output state of driver intended curvature depending on swa input state */
  VDY_SET_IO_STATE(VDY_SOUT_POS_DRVINTCURVE, VDY_GET_IO_STATE(VDY_SIN_POS_SWA, input->Signals.State), proPorts->pVehicleDynamicSignals->State);
}


/* **********************************************************************
	Unit Design for vdyHandcodeProcess is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyHandcodeProcess(const reqVdyPrtList_t *reqPorts, const VDYInputData_t * input, proVdyPrtList_t *proPorts, const AS_t_ServiceFuncts * services)
{
#if ((!CFG_VDY_INT_GYRO) && (!CFG_VDY_DO_VELOCITY_CORR) && (CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING) && (CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING) && (CFG_VDY_DIS_WHEEL_PRE_PROCESSING))
  (void)input;  /* remove compiler warning, input is not used in certain configurations */
#endif
#if (!(VDY_PROFILING_ENABLED == 1))
  (void)services;  /* to avoid compiler warning, service function not used in this setup */
#endif
#if ( defined(VDY_PROFILING_ENABLED) && (VDY_PROFILING_ENABLED == 1) )
  if(services->pfRTAAlgoServiceAddEvent != NULL)
  {
	  VDY_PROF_MARKER(services->pfRTAAlgoServiceAddEvent, VDY_PROF_MARKER_HANDCODE);  /* set marker for start of handcode process */
  }  
#endif
  /* Execute internal gyro processing */
#if (CFG_VDY_INT_GYRO)
  VDYYwrtExec(reqPorts, &VDYModIf, proPorts);
#endif
#if ( defined(VDY_PROFILING_ENABLED) && (VDY_PROFILING_ENABLED == 1) )
  if(services->pfRTAAlgoServiceAddEvent != NULL)
  {
	  VDY_PROF_MARKER(services->pfRTAAlgoServiceAddEvent, VDY_PROF_MARKER_YWRT);
  }  
#endif

  /* Velocity correction using velocity of stationary targets */
#if (CFG_VDY_DO_VELOCITY_CORR)

  /* Execute velocity correction  */
  VDYVelCorrExec(reqPorts, input, &VDYModIf, proPorts, b_RTBDetection);

#else
  /* If no correction is active set default value */
  VDYModIf.LongMot.VelCorrFact = VDY_ONE_F;
#endif

  /* Calculate raw velocity  */
  vdyRawEstimatedVelocity(input, proPorts);

#if ( defined(VDY_PROFILING_ENABLED) && (VDY_PROFILING_ENABLED == 1) )
  if(services->pfRTAAlgoServiceAddEvent != NULL)
  {
	  VDY_PROF_MARKER(services->pfRTAAlgoServiceAddEvent, VDY_PROF_MARKER_VELCORR);
  }  
#endif

  /* stand still yaw rate offset processing */
#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING) )
  /* Execute yaw rate sensor signal processing stand still offset e.g.*/
#if (CFG_VDY_MFC)
  vdyYwrExec(reqPorts, input, &VDYModIf, proPorts, RawVelo);
#else
  vdyYwrExec(reqPorts, input, &VDYModIf, proPorts);
#endif
#endif
#if ( defined(VDY_PROFILING_ENABLED) && (VDY_PROFILING_ENABLED == 1) )
  if(services->pfRTAAlgoServiceAddEvent != NULL)
  {
	  VDY_PROF_MARKER(services->pfRTAAlgoServiceAddEvent, VDY_PROF_MARKER_YWR);
  }  
#endif
  
  /* Monitoring of stand still yaw rate offset, like in the conti brake systems */
#if (CFG_VDY_YWR_OFFSET_MONITOR)
  /* Execute yaw rate sensor offset monitoring */
  vdyYwrMonExec(input, &VDYModIf, proPorts);
#endif

  /* Steering angle and lateral acceleration offset processing */
#if (   ((!defined(CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING)) \
     || ((!defined(CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING)) )
  /* Execute steering wheel angle sensor signal processing */
  vdyAySwaExec(reqPorts, input, &VDYModIf, proPorts);
#endif
#if ( defined(VDY_PROFILING_ENABLED) && (VDY_PROFILING_ENABLED == 1) )
  if(services->pfRTAAlgoServiceAddEvent != NULL)
  {
	  VDY_PROF_MARKER(services->pfRTAAlgoServiceAddEvent, VDY_PROF_MARKER_AY_SWA);
  }  
#endif

  /* Wheel velocity offset (left-right at one axle) processing */
#if ((!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING))
  /* Execute wheel speed sensors signal processing */
  vdyWhsExec(input, &VDYModIf);
#endif
#if ( defined(VDY_PROFILING_ENABLED) && (VDY_PROFILING_ENABLED == 1) )
  if(services->pfRTAAlgoServiceAddEvent != NULL)
  {
	  VDY_PROF_MARKER(services->pfRTAAlgoServiceAddEvent, VDY_PROF_MARKER_WHS);
  }  
#endif
}

/* ***********************************************************************
	Unit Design for vdyRawEstimatedVelocity is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyRawEstimatedVelocity(const VDYInputData_t * input, proVdyPrtList_t *proPorts)
{
  uint8 u_Wcount;
  float32 f_WhlVelFrLeft;
  float32 f_WhlVelFrRight;
  float32 f_WhlVelReLeft;
  float32 f_WhlVelReRight;
#if(!CFG_VDY_MFC)
  float32 f_MinWhlVel;
  float32 f_MaxWhlVel;
#endif
  /* Raw estimated OutPut velocity */
  u_Wcount = VDY_FOUR_U;
  f_WhlVelFrLeft = input->Signals.WhlVelFrLeft;
  f_WhlVelFrRight= input->Signals.WhlVelFrRight;
  f_WhlVelReLeft= input->Signals.WhlVelReLeft;
  f_WhlVelReRight= input->Signals.WhlVelReRight;
#if(!CFG_VDY_MFC)
  f_MinWhlVel = CML_Min(CML_Min(CML_Min(f_WhlVelFrLeft,f_WhlVelFrRight),f_WhlVelReLeft),f_WhlVelReRight);
  f_MaxWhlVel = CML_Max(CML_Max(CML_Max(f_WhlVelFrLeft,f_WhlVelFrRight),f_WhlVelReLeft),f_WhlVelReRight);
#endif

  if(VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_FL, input->Signals.State) == (VDYIoStateTypes_t)VDY_IO_STATE_INVALID)
  {
   f_WhlVelFrLeft = VDY_ZERO_F;
   u_Wcount = u_Wcount - 1U;
  }
  if(VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_FR, input->Signals.State) == (VDYIoStateTypes_t)VDY_IO_STATE_INVALID)
  {
   f_WhlVelFrRight = VDY_ZERO_F;
   u_Wcount = u_Wcount - 1U;
  }
  if(VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_RL, input->Signals.State) == (VDYIoStateTypes_t)VDY_IO_STATE_INVALID)
  {
   f_WhlVelReLeft = VDY_ZERO_F;
   u_Wcount = u_Wcount - 1U;
  }
  if(VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_RR, input->Signals.State) == (VDYIoStateTypes_t)VDY_IO_STATE_INVALID)
  {
   f_WhlVelReRight = VDY_ZERO_F;
   u_Wcount = u_Wcount - 1U;
  }
  if(u_Wcount == 0U)
  {
    u_Wcount = 1U;
  }
#if (CFG_VDY_MFC)

  RawVelo = ((f_WhlVelFrLeft + f_WhlVelFrRight + f_WhlVelReLeft + f_WhlVelReRight)/(float32)u_Wcount);
#else
  proPorts->pVehicleDynamicSignals->Longitudinal.VelocityRaw  = (((f_WhlVelFrLeft + f_WhlVelFrRight + f_WhlVelReLeft + f_WhlVelReRight)/u_Wcount) *
                                                                   (vdy_internal_data.vdy_velcor.VelCorrFact));

  /*Threshold to find more scattered wheel speeds is 1 m/s and that is diff between max and min wheel speeds */
  if(f_MaxWhlVel - f_MinWhlVel < 1.0F)
  {
    VDY_SET_IO_STATE(VDY_SOUT_POS_RAW_VEL, VDY_IO_STATE_VALID, proPorts->pVehicleDynamicSignals->State);
  }
  else
  {
	VDY_SET_IO_STATE(VDY_SOUT_POS_RAW_VEL, VDY_IO_STATE_INVALID, proPorts->pVehicleDynamicSignals->State);
  }
#endif

}

#if ((!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING))
/* **********************************************************************
	Unit Design for vdyProcAutoVelocity is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyProcAutoVelocity(VDYInputData_t * input, const reqVdyPrtList_t *reqPorts)
{
	Brake_t BrakeData_input;
	BrakeData_input.ABSCtrl = reqPorts->pVehicleInputSignals->Brake.ABSCtrl;
	BrakeData_input.TCSCtrl = reqPorts->pVehicleInputSignals->Brake.TCSCtrl;
	BrakeData_input.State[0] = reqPorts->pVehicleInputSignals->Brake.State[0];
	BrakeData_input.State[1] = reqPorts->pVehicleInputSignals->Brake.State[1];
  /* if vdy control mode is init  */
#if (!CFG_VDY_MFC)
	if (VDY_CTRL_GET_STATE((VDYCtrlState_t)VDY_CTRL_STATE_INIT, input->Frame.CtrlMode))
#else
    if (VDY_CTRL_GET_STATE( (BaseOpMode_t)BASE_OM_RESET, input->Frame.OpMode) )
#endif
  {
    /* Initialize vdy_wpp model */
    vdy_wpp_initialize((boolean_T) 1, &vdy_wpp_B, &vdy_wpp_DWork);
    /* Initialize vdy_ve model */
    vdy_ve_initialize((boolean_T) 1, &vdy_ve_B, &vdy_ve_DWork);
  }
  else
  {
    /* if vdy_wpp_module is sequence initalized execute it */
    if (VDY_IS_MODULE_SEQU_INITALIZED((uint32)sSequenceInitState.initStates.vdy_wpp_sequ_init) == TRUE)
    {
      /* execute wheel pre processing module */
      vdy_wpp_step(&vdy_wpp_B, &vdy_wpp_DWork, input, &vdy_internal_data, &vdy_internal_data); /* MISRA Rule 11.4: reviewer name: Jochen Spruck date: 27-09-2010 reason: vdy inpur ports are const, but the Matlab simulik autocode modules uses not const as input, autocode module does note modify this struct */
    }
    /* if vdy_ve_module is sequence initalized execute it */
    if (VDY_IS_MODULE_SEQU_INITALIZED((uint32)sSequenceInitState.initStates.vdy_ve_sequ_init) == TRUE)
	{
      /* execute vehicle velocity and acceleration estimation modul */
#if (CFG_VDY_MFC)
     vdy_ve_step(&vdy_ve_B, &vdy_ve_DWork, (VDYInputData_t*)input, &vdy_internal_data, &BrakeData_input, &vdy_internal_data); /* MISRA Rule 11.4: reviewer name: Jochen Spruck date: 27-09-2010 reason: vdy inpur ports are const, but the Matlab simulik autocode modules uses not const as input, autocode module does note modify this struct */
#else
     vdy_ve_step(&vdy_ve_B, &vdy_ve_DWork, (VDYInputData_t*)input, &vdy_internal_data, &reqPorts->pVehicleInputSignals->Brake, &vdy_internal_data); /* MISRA Rule 11.4: reviewer name: Jochen Spruck date: 27-09-2010 reason: vdy inpur ports are const, but the Matlab simulik autocode modules uses not const as input, autocode module does note modify this struct */
#endif
	}
  }
}
#endif


/* **********************************************************************
	Unit Design for vdyProcAutoWheelYawRate is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyProcAutoWheelYawRate(VDYInputData_t * input, VDYNvData_t * nvdata)
{
/* if wheel velocity yaw rate preprocessing is enabled */
#if ((!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING))
  /* if vdy ctrl mode is init do not delete learn values but init the rest*/
#if (!CFG_VDY_MFC)
    if (VDY_CTRL_GET_STATE((VDYCtrlState_t)VDY_CTRL_STATE_INIT, input->Frame.CtrlMode))
#else
    if (VDY_CTRL_GET_STATE( (BaseOpMode_t)BASE_OM_RESET, input->Frame.OpMode) )
#endif
  {
    /* local copy of last cycle data */
    uint8 init_nvm_wld_delay_DSTATE = vdy_wye_DWork.init_nvm_wld_delay_DSTATE;
    float32 x_delay_wld_DSTATE = vdy_wye_DWork.x_delay_wld_DSTATE[VDY_TWO];
    float32 last_est_wld_DSTATE = vdy_wye_DWork.last_est_wld_DSTATE;

    float32 x_delay_dyn_off_DSTATE = vdy_wye_DWork.x_delay_dyn_off_DSTATE[VDY_TWO];
    sint8 last_dyn_yaw_offset_sign_DSTATE = vdy_wye_DWork.last_dyn_yaw_offset_sign_DSTATE;
    float32 dyn_yaw_off_overt_count_DSTATE = vdy_wye_DWork.dyn_yaw_off_overt_count_DSTATE;
    float32 last_dyn_yaw_offset_DSTATE = vdy_wye_DWork.last_dyn_yaw_offset_DSTATE;   

    /* Initialize vdy_wye model */
    vdy_wye_initialize((boolean_T) 1, &vdy_wye_B, &vdy_wye_DWork);
    /* copy all necessary data and old learn values to reinitialize the auto code module */
    vdy_wye_DWork.init_nvm_wld_delay_DSTATE = init_nvm_wld_delay_DSTATE;
    vdy_wye_DWork.x_delay_wld_DSTATE[VDY_TWO] = x_delay_wld_DSTATE;
    vdy_wye_DWork.last_est_wld_DSTATE = last_est_wld_DSTATE;

    vdy_wye_DWork.x_delay_dyn_off_DSTATE[VDY_TWO] = x_delay_dyn_off_DSTATE;
    vdy_wye_DWork.last_dyn_yaw_offset_sign_DSTATE = last_dyn_yaw_offset_sign_DSTATE;
    vdy_wye_DWork.dyn_yaw_off_overt_count_DSTATE = dyn_yaw_off_overt_count_DSTATE;
    vdy_wye_DWork.last_dyn_yaw_offset_DSTATE = last_dyn_yaw_offset_DSTATE;
  }
  else
  {
    /* if vdy_wye_module is sequence initalized execute it */
    if (VDY_IS_MODULE_SEQU_INITALIZED((uint32)sSequenceInitState.initStates.vdy_wye_sequ_init) == TRUE)
    {
      /* at running mode */
      vdy_wye_step(&vdy_wye_B, &vdy_wye_DWork, input, &vdy_internal_data, (VDYNvData_t*)nvdata, &vdy_internal_data, (VDYNvData_t*)nvdata); /* MISRA Rule 11.4: reviewer name: Jochen Spruck date: 27-09-2010 reason: vdy inpur ports are const, but the Matlab simulik autocode modules uses not const as input, autocode module does note modify this struct */
    }
  }
#else
  /* if the wheel pre processing module is not used (wheel velocities are not available) */
  /* remove compiler warning, parameters are not used in this configuration */
  (void)input;
  (void)nvdata;

  /* set the wheel yaw rate modul to invalid variances */
  vdy_internal_data.vdy_wye_out.whl_yaw_rate = 0.0F;
  vdy_internal_data.vdy_wye_out.whl_yaw_rate_var = 100.0F;
  vdy_internal_data.vdy_wye_out.gier_yaw_rate_offset = vdy_internal_data.vdy_offsets_in.vdy_yaw_offset.offset;
  vdy_internal_data.vdy_wye_out.gier_yaw_rate_offset_var = vdy_internal_data.vdy_offsets_in.vdy_yaw_offset.var;
  vdy_internal_data.vdy_wye_out.raw_est_yaw_offset = 0.0F;
#endif
}


#if (!CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING)
#if (CFG_VDY_INT_GYRO)
/* **********************************************************************
	Unit Design for vdyProcAutoSenIntYawRateOffset is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyProcAutoSenIntYawRateOffset(void)
{
  const VDYYwrtOffsData_t *pYwrOffs = VDYYwrtGetOffsData();

  /* reset dyn yaw rate offset filter if stand still */
  if (   ( (pYwrOffs->OffsElpsdTime < (fTime_t) 1.0F) && (pYwrOffs->OffsType == (VDYYwrOffsType_t) OFFS_STANDST) )
      || (pYwrOffs->OffsType==(VDYYwrOffsType_t) OFFS_STANDST_EEPROM)
      || ( VDY_IS_FIRST_CYCLE_DONE == FALSE ) )
  {
    OldFiltYawOffset = vdy_internal_data.vdy_wye_out.gier_yaw_rate_offset;
  }
  else
  {
    OldFiltYawOffset = vdy_internal_data.vdy_gye_out_filt.raw_est_yaw_offset_filt;
  }
  /* low pass filter raw yaw offset */
  vdy_internal_data.vdy_gye_out_filt.raw_est_yaw_offset_filt = vdyFilterCycleTime( vdy_internal_data.vdy_wye_out.gier_yaw_rate_offset,
    OldFiltYawOffset,
    VDY_PAR_RAW_YAW_RATE_OFFSET_FT);
}
#endif


/* **********************************************************************
	Unit Design for vdyProcAutoSenExtYawRateOffset is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyProcAutoSenExtYawRateOffset(void)
{
  const VDYYwrOffsData_t *pYwrOffs = vdyYwrGetOffsData();

  /* reset dyn yaw rate offset filter if stand still */
  if ( ( (pYwrOffs->OffsElpsdTime < VDY_ONE_F) && (pYwrOffs->OffsType == (VDYYwrOffsType_t) OFFS_STANDST) )
      || (pYwrOffs->OffsType==(VDYYwrOffsType_t) OFFS_STANDST_EEPROM) )
  {
    OldFiltYawOffset = vdy_internal_data.vdy_wye_out.raw_est_yaw_offset;
  }
  else
  {
    OldFiltYawOffset = vdy_internal_data.vdy_gye_out_filt.raw_est_yaw_offset_filt;
  }
  /* low pass filter raw yaw offset */
  vdy_internal_data.vdy_gye_out_filt.raw_est_yaw_offset_filt = vdyFilterCycleTime( vdy_internal_data.vdy_wye_out.raw_est_yaw_offset,
    OldFiltYawOffset,
    VDY_PAR_RAW_YAW_RATE_OFFSET_FT);
}
#endif


/* **********************************************************************
	Unit Design for vdyProcAutoSenYawRate is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyProcAutoSenYawRate(VDYInputData_t * input)
{
/* if sensor yaw rate pre processing is enabled*/
#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING) )
  /* if vdy control mode is init */
#if (!CFG_VDY_MFC)
    if (VDY_CTRL_GET_STATE((VDYCtrlState_t)VDY_CTRL_STATE_INIT, input->Frame.CtrlMode))
#else
    if (VDY_CTRL_GET_STATE( (BaseOpMode_t)BASE_OM_RESET, input->Frame.OpMode) )
#endif
  {
#if (!CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING)
    /* Initialize vdy_gye model filt */
    vdy_gye_initialize((boolean_T) 1, &vdy_gye_B_FILT, &vdy_gye_DWork_FILT);
#endif
    /* do nothing */

    /* Initialize vdy_gye model */
    vdy_gye_initialize((boolean_T) 1, &vdy_gye_B, &vdy_gye_DWork);
  }
  else
  {
    /* if vdy_gye_module is sequence initalized execute it */
    if (VDY_IS_MODULE_SEQU_INITALIZED((uint32)sSequenceInitState.initStates.vdy_gye_sequ_init) == TRUE)
    {
#if (!CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING)
      /* if sensor yaw rate offset should be prefilterd for alignment */

      /* store not filterd yaw rate offset */
      fYawRate_t NotFiltYawOffset = vdy_internal_data.vdy_wye_out.gier_yaw_rate_offset;

      /*<----- Pass yaw rate offset  ----->*/
#if (CFG_VDY_INT_GYRO)
      /* if external yaw rate signal is valid use the external yaw rate signal otherwise the internal */
      /* <ln_offset:+2 PCLINT Error 845: reviewer name: Jochen Spruck date: 4-05-2011 reason: proven in use, error because mask value is zero */
      /* <ln_offset:+1 PCLINT Error 835: reviewer name: Jochen Spruck date: 4-05-2011 reason: proven in use, error because mask value is zero */
      if (VDY_GET_IO_STATE(VDY_SIN_POS_YWR, input->Signals.State) == VDY_IO_STATE_VALID)
      {
        /* reset and low pass filter external yaw rate dynamic offset */
        vdyProcAutoSenExtYawRateOffset();
      }
      else
      {
        /* reset and low pass filter internal yaw rate dynamic offset */
        vdyProcAutoSenIntYawRateOffset();
      }
#else
      /* reset and low pass filter external yaw rate dynamic offset */
      vdyProcAutoSenExtYawRateOffset();
#endif

      /* copy filterd yaw rate offset to gier_yaw_rate_offset as input for alignment gier sensor yaw rate*/
      vdy_internal_data.vdy_wye_out.gier_yaw_rate_offset = vdy_internal_data.vdy_gye_out_filt.raw_est_yaw_offset_filt;

      /* calculate gier yaw rate with filtered raw yaw rate offset */
      vdy_gye_step(&vdy_gye_B_FILT,&vdy_gye_DWork_FILT, input, &vdy_internal_data, &vdy_internal_data); /* MISRA Rule 11.4: reviewer name: Jochen Spruck date: 27-09-2010 reason: vdy inpur ports are const, but the Matlab simulik autocode modules uses not const as input, autocode module does note modify this struct */

      /* copy sensor yaw rate with filtered raw estimated gier yaw rate offset to seperate struct */
      vdy_internal_data.vdy_gye_out_filt.gier_yaw_rate = vdy_internal_data.vdy_gye_out.gier_yaw_rate;
      vdy_internal_data.vdy_gye_out_filt.gier_yaw_rate_var = vdy_internal_data.vdy_gye_out.gier_yaw_rate_var;

      /* restore original not filtered yaw rate offset*/
      vdy_internal_data.vdy_wye_out.gier_yaw_rate_offset = NotFiltYawOffset;
#else
      /* set filtered offset to not filtered raw offset */
      vdy_internal_data.vdy_gye_out_filt.raw_est_yaw_offset_filt = vdy_internal_data.vdy_wye_out.raw_est_yaw_offset;
#endif

      /* calculate gier yaw rate with discrete yaw rate offset */
      vdy_gye_step(&vdy_gye_B,&vdy_gye_DWork, (VDYInputData_t*)input, &vdy_internal_data, &vdy_internal_data); /* MISRA Rule 11.4: reviewer name: Jochen Spruck date: 27-09-2010 reason: vdy inpur ports are const, but the Matlab simulik autocode modules uses not const as input, autocode module does note modify this struct */
    }

#if (!CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING)
#else
    /* copy sensor yaw rate with NOT filtered raw estimated gier yaw rate offset to seperate struct */
    vdy_internal_data.vdy_gye_out_filt.gier_yaw_rate = vdy_internal_data.vdy_gye_out.gier_yaw_rate;
    vdy_internal_data.vdy_gye_out_filt.gier_yaw_rate_var = vdy_internal_data.vdy_gye_out.gier_yaw_rate_var;
#endif
  }
#else
  (void)input;  /* remove compiler warning, input is not used in this configuration */

  /* set internal sensor yaw rate data to default values */
  vdy_internal_data.vdy_gye_out.gier_yaw_rate     = 0.0F;
  vdy_internal_data.vdy_gye_out.gier_yaw_rate_var = 100.0F;
#endif
}


/* **********************************************************************
	Unit Design for vdyProcAutoLatAccelYawRate is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyProcAutoLatAccelYawRate(VDYInputData_t * input)
{
/* If lateral acceleration sensor pre processing is enabled */
#if ((!defined(CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING))
  /* if vdy control mode is init */
#if (!CFG_VDY_MFC)
    if (VDY_CTRL_GET_STATE((VDYCtrlState_t)VDY_CTRL_STATE_INIT, input->Frame.CtrlMode))
#else
    if (VDY_CTRL_GET_STATE( (BaseOpMode_t)BASE_OM_RESET, input->Frame.OpMode) )
#endif
  {
    /* Initialize vdy_ay model */
    vdy_aye_initialize((boolean_T) 1, &vdy_aye_B, &vdy_aye_DWork);   
  }
  else
  {
    /* if vdy_aye_module is sequence initalized execute it */
    if (VDY_IS_MODULE_SEQU_INITALIZED((uint32)sSequenceInitState.initStates.vdy_aye_sequ_init) == TRUE)
    {
      vdy_aye_step(&vdy_aye_B, &vdy_aye_DWork, input, &vdy_internal_data, &vdy_internal_data); /* MISRA Rule 11.4: reviewer name: Jochen Spruck date: 27-09-2010 reason: vdy inpur ports are const, but the Matlab simulik autocode modules uses not const as input, autocode module does note modify this struct */
    }
  }
#else
  (void)input;  /* remove compiler warning, input is not used in this configuration */

  /* set internal lateral accel yaw rate data to default values */
  vdy_internal_data.vdy_aye_out.ay_yaw_rate     = 0.0F;
  vdy_internal_data.vdy_aye_out.ay_yaw_rate_var = 100.0F;
#endif
}


/* **********************************************************************
	Unit Design for vdyProcAutoSwaYawRate is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyProcAutoSwaYawRate(VDYInputData_t * input, VDYNvData_t * nvdata)
{
/* If steering wheel angle sensor pre processing is enabled */
#if ((!defined(CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING))
  /* if vdy control mode is init */
#if (!CFG_VDY_MFC)
    if (VDY_CTRL_GET_STATE((VDYCtrlState_t)VDY_CTRL_STATE_INIT, input->Frame.CtrlMode))
#else
    if (VDY_CTRL_GET_STATE( (BaseOpMode_t)BASE_OM_RESET, input->Frame.OpMode) )
#endif
  {
    /* local copy of last cycle data */
    uint8 init_nvm_eg_delay_DSTATE = vdy_sye_DWork.init_nvm_eg_delay_DSTATE;
    float32 x_delay_eg_DSTATE = vdy_sye_DWork.x_delay_eg_DSTATE[VDY_TWO];
    /* Initialize vdy_sye model */
    vdy_sye_initialize((boolean_T) 1, &vdy_sye_B, &vdy_sye_DWork);
    /* copy all necessary data and old learn values to reinitialize the auto code module */
    vdy_sye_DWork.init_nvm_eg_delay_DSTATE = init_nvm_eg_delay_DSTATE;
    vdy_sye_DWork.x_delay_eg_DSTATE[VDY_TWO] = x_delay_eg_DSTATE;
  }
  else
  {
    /* if vdy_sye_module is sequence initalized execute it */
    if (VDY_IS_MODULE_SEQU_INITALIZED((uint32)sSequenceInitState.initStates.vdy_sye_sequ_init) == TRUE)
    {
	 #if (!CFG_VDY_MFC)
	    vdy_sye_step(&vdy_sye_B, &vdy_sye_DWork, input, &vdy_internal_data ,(VDYNvData_t*)nvdata ,input->Frame.CtrlMode, &vdy_internal_data, (VDYNvData_t*)nvdata); /* MISRA Rule 11.4: reviewer name: Jochen Spruck date: 27-09-2010 reason: vdy inpur ports are const, but the Matlab simulik autocode modules uses not const as input, autocode module does note modify this struct */
     #else
		vdy_sye_step(&vdy_sye_B, &vdy_sye_DWork, input, &vdy_internal_data ,(VDYNvData_t*)nvdata ,(uint8)input->Frame.OpMode, &vdy_internal_data, (VDYNvData_t*)nvdata); /* MISRA Rule 11.4: reviewer name: Jochen Spruck date: 27-09-2010 reason: vdy inpur ports are const, but the Matlab simulik autocode modules uses not const as input, autocode module does note modify this struct */
     #endif
    }
  }
#else
  /* remove compiler warning, parameters are not used in this configuration */
  (void)nvdata;
  (void)input;

  /* set internal steering wheel angle yaw rate data to default values */
  vdy_internal_data.vdy_sye_out.stw_yaw_rate     = 0.0F;
  vdy_internal_data.vdy_sye_out.stw_yaw_rate_var = 100.0F;

  vdy_internal_data.vdy_sye_out.stw_curve        = 0.0F;
  vdy_internal_data.vdy_sye_out.stw_curve_var    = 100.0F;
#endif
}


/* **********************************************************************
	Unit Design for vdyProcAutoVehicleYawRate is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyProcAutoVehicleYawRate(VDYInputData_t * input)
{
  /* If external yaw rate sensor processing  */
#if ( (!defined(CFG_VDY_USE_EXT_PROC_YAW_RATE)) || (!CFG_VDY_USE_EXT_PROC_YAW_RATE) )
#if (!CFG_VDY_MFC)
    if (VDY_CTRL_GET_STATE((VDYCtrlState_t)VDY_CTRL_STATE_INIT, input->Frame.CtrlMode))
#else
    if (VDY_CTRL_GET_STATE( (BaseOpMode_t)BASE_OM_RESET, input->Frame.OpMode) )
#endif
  {
    /* Initialize vdy_ve model */
    vdy_ye_initialize((boolean_T) 1, &vdy_ye_B, &vdy_ye_DWork);
  }
  else
  {
    /* if vdy_ye_module is sequence initalized execute it */
    if (VDY_IS_MODULE_SEQU_INITALIZED((uint32)sSequenceInitState.initStates.vdy_ye_sequ_init) == TRUE)
    {
      vdy_ye_step(&vdy_ye_B, &vdy_ye_DWork, input, &vdy_internal_data, &vdy_internal_data, \
                  vdy_ye_k.K_yaw, &vdy_ye_k.K_yaw_fault, vdy_ye_k.K_curve, &vdy_ye_k.K_curve_fault);

      if ((vdy_ye_k.K_yaw_fault == 1U) || (vdy_ye_k.K_curve_fault == 1U))
      {
        /* Initialize vdy_ye model */
        vdy_ye_initialize((boolean_T) 1, &vdy_ye_B, &vdy_ye_DWork);
      }
    }
  }
#else
  /* calculate the curve manually, is not filtered !!!*/
  if (CML_f_IsZero(vdy_internal_data.vdy_ve_out.veh_velo))
  {
    vdy_internal_data.vdy_ye_out.veh_merge_curve = 0.0F;
  }
  else
  {
    vdy_internal_data.vdy_ye_out.veh_merge_curve = input->Signals.YawRate/vdy_internal_data.vdy_ve_out.veh_velo; /* MISRA Rule 11.4: reviewer name: Jochen Spruck date: 27-09-2010 reason: vdy inpur ports are const, but the Matlab simulik autocode modules uses not const as input, autocode module does note modify this struct */
  }
  vdy_internal_data.vdy_ye_out.veh_merge_curve_grad = 0.0F;
  vdy_internal_data.vdy_ye_out.veh_merge_curve_var  = 0.0F;
#endif
}


/* **********************************************************************
	Unit Design for vdyProcAutoSideSlip is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyProcAutoSideSlip(VDYInputData_t * input)
{
/* If side slip angle processing is enabled */
#if ((!defined(CFG_VDY_DIS_SIDE_SLIP_ANGLE_ESTIMATION)) || (!CFG_VDY_DIS_SIDE_SLIP_ANGLE_ESTIMATION))
  #if (!CFG_VDY_MFC)
    if (VDY_CTRL_GET_STATE((VDYCtrlState_t)VDY_CTRL_STATE_INIT, input->Frame.CtrlMode))
  #else
    if (VDY_CTRL_GET_STATE( (BaseOpMode_t)BASE_OM_RESET, input->Frame.OpMode) )
  #endif
  {
    /* Initialize vdy_sae model */
    vdy_sae_initialize((boolean_T) 1, &vdy_sae_B, &vdy_sae_DWork);
  }
  else
  {
    /* if vdy_sae_module is sequence initalized execute it */
    if (VDY_IS_MODULE_SEQU_INITALIZED(sSequenceInitState.initStates.vdy_sae_sequ_init) == TRUE)
    {
      vdy_sae_step(&vdy_sae_B ,&vdy_sae_DWork, (VDYInputData_t*)input, &vdy_internal_data, &vdy_internal_data); /* MISRA Rule 11.4: reviewer name: Jochen Spruck date: 27-09-2010 reason: vdy input ports are const, but the Matlab simulik autocode modules uses not const as input, autocode module does note modify this struct */
    }
  }
#else
  /* PRQA S 3119 EOF */
  /* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: No Risk */
  (void)input;  /* remove compiler warning, input is not used in this configuration */

  /* set internal side slip angle data to default values */
  vdy_internal_data.vdy_sae_out.est_slip_angle     = VDY_ZERO_F;
  vdy_internal_data.vdy_sae_out.est_slip_angle_var = VDY_HUNDRED_F;
#endif
}


#if (CFG_VDY_MOT_STATE)
/* **********************************************************************
	Unit Design for vdyProcMotionState is found in Declaration Section
**************************************************************************** */
#if (CFG_VDY_MFC)
STATIC_MTD void vdyProcMotionState(VDYInputData_t * input)
#else
STATIC_MTD void vdyProcMotionState(VDYInputData_t * input, ALN_Monitoring_t * ALNMonitoring, const proVdyPrtList_t *proPorts)
#endif
{
/* If motion state processing is enabled */
#if (!CFG_VDY_MFC)
    if (VDY_CTRL_GET_STATE((VDYCtrlState_t)VDY_CTRL_STATE_INIT, input->Frame.CtrlMode))
#else
    if (VDY_CTRL_GET_STATE( (BaseOpMode_t)BASE_OM_RESET, input->Frame.OpMode) )
#endif
  {
    /* Initialize vdy_mot_st model */
    vdy_mot_st_initialize((boolean_T) 1, &vdy_mot_st_B, &vdy_mot_st_DWork);
  }
  else
  {
    /* if vdy_mot_state_module is sequence initalized execute it */
    if (VDY_IS_MODULE_SEQU_INITALIZED((uint32)sSequenceInitState.initStates.vdy_mot_state_sequ_init) == TRUE)
    {
#if (!CFG_VDY_MFC)
	  vdy_mot_st_step(&vdy_mot_st_B, &vdy_mot_st_DWork, input, &vdy_internal_data, (uint8)ALNMonitoring->EgoSpeed.DrivingDirection.e_Direction, proPorts->pVehicleDynamicSignals->Longitudinal.VelocityRaw, &vdy_bayes_mot_states); /* MISRA Rule 11.4: reviewer name: Jochen Spruck date: 27-09-2010 reason: vdy input ports are const, but the Matlab simulik autocode modules uses not const as input, autocode module does note modify this struct */
#else
	  vdy_mot_st_step(&vdy_mot_st_B, &vdy_mot_st_DWork, input, &vdy_internal_data, (uint8)0, RawVelo, &vdy_bayes_mot_states); /* MISRA Rule 11.4: reviewer name: Jochen Spruck date: 27-09-2010 reason: vdy input ports are const, but the Matlab simulik autocode modules uses not const as input, autocode module does note modify this struct */
#endif
	  vdy_internal_data.vdy_mot_st_out.fwd = vdy_bayes_mot_states.mot_st_out.fwd;
      vdy_internal_data.vdy_mot_st_out.ss = vdy_bayes_mot_states.mot_st_out.ss;
      vdy_internal_data.vdy_mot_st_out.rvs = vdy_bayes_mot_states.mot_st_out.rvs;
      vdy_internal_data.vdy_mot_st_out.mot_state  = vdy_bayes_mot_states.mot_st_out.mot_state;
      vdy_internal_data.vdy_mot_st_out.mot_quality = vdy_bayes_mot_states.mot_st_out.mot_quality;
    }
  }
}
#endif


/* **********************************************************************
	Unit Design for vdyAutocodeProcess is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyAutocodeProcess(const reqVdyPrtList_t *reqPorts, VDYInputData_t * input, VDYNvData_t * nvdata, VDYErrors_t *VDYErrors, const AS_t_ServiceFuncts * services, const proVdyPrtList_t *proPorts)
{
  (void)reqPorts;  /* remove compiler warning, reqPorts is not used in this configuration */
#if (!(VDY_PROFILING_ENABLED == 1))
  (void)services;  /* to avoid compiler warning, service function not used in this setup */
#endif
  /* Process velocity estimation */
#if ( defined(VDY_PROFILING_ENABLED) && (VDY_PROFILING_ENABLED == 1) )
  if(services->pfRTAAlgoServiceAddEvent != NULL)
  {
	  VDY_PROF_MARKER(services->pfRTAAlgoServiceAddEvent, VDY_PROF_MARKER_AUTOCODE);
  }
  
#endif
#if ((!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING))
  vdyProcAutoVelocity(input,reqPorts);
#endif

  /* Velocity monitoring (external <-> internal velocity)*/
#if (CFG_VDY_USE_VELO_MONITOR)
  vdyVelMonExec(input, &vdy_internal_data.vdy_ve_out, VDYErrors);
#else
  (void)VDYErrors;  /* remove compiler warning, VDYErrors is not used in this configuration */
#endif

  /* overwrite internal velocity data if external velocity should be used and is valid or Substitute */
#if (CFG_VDY_USE_EX_LONG_VELO)
  if (  (VDY_GET_IO_STATE(VDY_SIN_POS_VEHVEL_EXT, input->Signals.State) == VDY_IO_STATE_VALID)
      ||(VDY_GET_IO_STATE(VDY_SIN_POS_VEHVEL_EXT, input->Signals.State) == VDY_IO_STATE_SUBSTITUE) )
  {
    vdy_internal_data.vdy_ve_out.veh_velo =  VDYModIf.LongMot.VehVelo;
  }
#else
  /* keep the uncorrected velocity */
  VDYModIf.LongMot.VehVelo = vdy_internal_data.vdy_ve_out.veh_velo;
#endif
  /* set the internal autocode velocity to the corrected velocity */
  vdy_internal_data.vdy_ve_out.veh_velo *= VDYModIf.LongMot.VelCorrFact;
#if(!CFG_VDY_MFC)
  vdy_internal_data.vdy_velcor.corrVar = VDYModIf.LongMot.corrVar;
  vdy_internal_data.vdy_velcor.corrVeloVar = VDYModIf.LongMot.corrVeloVar;
  vdy_internal_data.vdy_velcor.VehVelo = VDYModIf.LongMot.VehVelo;
  vdy_internal_data.vdy_velcor.VehVelocityCorr = VDYModIf.LongMot.VehVelocityCorr;
  vdy_internal_data.vdy_velcor.VehVeloVar = VDYModIf.LongMot.VehVeloVar;
  vdy_internal_data.vdy_velcor.VelCorrFact = VDYModIf.LongMot.VelCorrFact;
#endif

#if ( defined(VDY_PROFILING_ENABLED) && (VDY_PROFILING_ENABLED == 1) )
  if(services->pfRTAAlgoServiceAddEvent != NULL)
  {
	  VDY_PROF_MARKER(services->pfRTAAlgoServiceAddEvent, VDY_PROF_MARKER_VELOCITY);
  }  
#endif

#if (!CFG_VDY_MFC)
  /* Process velocity during roll bench detection*/
  if(( b_RTBDetection == TRUE ) || (input->Frame.ProductionMode == TRUE))
  {
  #if ((VDY_VEH_DYN_INTFVER < 8U) || (BSW_VDY_CTRL_DATA_INTFVER < 3U))
  {
    vdy_internal_data.vdy_ve_out.veh_velo	=	0;		
    vdy_internal_data.vdy_wpp_out.wheel_velo_front_left = 0;
    vdy_internal_data.vdy_wpp_out.wheel_velo_front_right = 0;
    vdy_internal_data.vdy_wpp_out.wheel_velo_rear_left = 0;
    vdy_internal_data.vdy_wpp_out.wheel_velo_rear_right = 0;
  }
  #elif ((VDY_VEH_DYN_INTFVER >= 8U) || (BSW_VDY_CTRL_DATA_INTFVER >= 3U))
  {
  if ((CORRECTED_EGO_SPEED_IS_ZERO_ON_ROLLER_BENCH == 1) || (input->Frame.ProductionMode == TRUE))
  {
    vdy_internal_data.vdy_ve_out.veh_velo	=	0;
    vdy_internal_data.vdy_wpp_out.wheel_velo_front_left = 0;
    vdy_internal_data.vdy_wpp_out.wheel_velo_front_right = 0;
    vdy_internal_data.vdy_wpp_out.wheel_velo_rear_left = 0;
    vdy_internal_data.vdy_wpp_out.wheel_velo_rear_right = 0;
  }  
  }
  #endif
  }
#endif

  /* vdy_wye modul */
  vdyProcAutoWheelYawRate(input,nvdata);
#if ( defined(VDY_PROFILING_ENABLED) && (VDY_PROFILING_ENABLED == 1) )
  if(services->pfRTAAlgoServiceAddEvent != NULL)
  {
	  VDY_PROF_MARKER(services->pfRTAAlgoServiceAddEvent, VDY_PROF_MARKER_WYE);  /* Task Logic Monitoring Checkpoint Nr 7 */
  }
  
#endif

  /* If internal gyro is used copy/overwrite internal gyro offset in autocode yaw rate offset estimation data struct */
#if (CFG_VDY_INT_GYRO)
  /* if external yaw rate signal is not valid use the internal yaw rate signal */
  /* <ln_offset:+2 PCLINT Error 845: reviewer name: Jochen Spruck date: 4-05-2011 reason: proven in use, error because mask value is zero */
  /* <ln_offset:+1 PCLINT Error 835: reviewer name: Jochen Spruck date: 4-05-2011 reason: proven in use, error because mask value is zero */
  if (VDY_GET_IO_STATE(VDY_SIN_POS_YWR, input->Signals.State) != VDY_IO_STATE_VALID)
  {
    vdy_internal_data.vdy_wye_out.gier_yaw_rate_offset = vdy_internal_data.vdy_offsets_in.vdy_yaw_offset.offset;
    vdy_internal_data.vdy_wye_out.gier_yaw_rate_offset_var = vdy_internal_data.vdy_offsets_in.vdy_yaw_offset.var;
  }
#endif

  /* vdy_gye modul */
  vdyProcAutoSenYawRate(input);
#if ( defined(VDY_PROFILING_ENABLED) && (VDY_PROFILING_ENABLED == 1) )
  if(services->pfRTAAlgoServiceAddEvent != NULL)
  {
	  VDY_PROF_MARKER(services->pfRTAAlgoServiceAddEvent, VDY_PROF_MARKER_GYE);
  }  
#endif

  /* vdy_aye modul */
  vdyProcAutoLatAccelYawRate(input);
#if ( defined(VDY_PROFILING_ENABLED) && (VDY_PROFILING_ENABLED == 1) )
  if(services->pfRTAAlgoServiceAddEvent != NULL)
  {
	  VDY_PROF_MARKER(services->pfRTAAlgoServiceAddEvent, VDY_PROF_MARKER_AYE);
  }  
#endif

  /* vdy_sye modul */
  vdyProcAutoSwaYawRate(input,nvdata);
#if ( defined(VDY_PROFILING_ENABLED) && (VDY_PROFILING_ENABLED == 1) )
  if(services->pfRTAAlgoServiceAddEvent != NULL)
  {
	  VDY_PROF_MARKER(services->pfRTAAlgoServiceAddEvent, VDY_PROF_MARKER_SYE);
  }  
#endif

  /* vdy_ye modul */  
  vdyProcAutoVehicleYawRate(input);
#if ( defined(VDY_PROFILING_ENABLED) && (VDY_PROFILING_ENABLED == 1) )
  if(services->pfRTAAlgoServiceAddEvent != NULL)
  {
	  VDY_PROF_MARKER(services->pfRTAAlgoServiceAddEvent, VDY_PROF_MARKER_YE);
  }  
#endif
  
  /* vdy_sae modul slip angle */
  vdyProcAutoSideSlip(input);
#if ( defined(VDY_PROFILING_ENABLED) && (VDY_PROFILING_ENABLED == 1) )
  if(services->pfRTAAlgoServiceAddEvent != NULL)
  {
	  VDY_PROF_MARKER(services->pfRTAAlgoServiceAddEvent, VDY_PROF_MARKER_SAE);
  }  
#endif

  /* vdy_mot_st modul motion state*/
#if (CFG_VDY_MOT_STATE)
#if (CFG_VDY_MFC)
  vdyProcMotionState(input);
  (void)proPorts;  /* remove compiler warning, services is not used in this configuration */
#else
  vdyProcMotionState(input,reqPorts->pAln_Monitoring,proPorts);
#endif
#else
  (void)proPorts;  /* remove compiler warning, services is not used in this configuration */
#endif
#if ( defined(VDY_PROFILING_ENABLED) && (VDY_PROFILING_ENABLED == 1) )
  if(services->pfRTAAlgoServiceAddEvent != NULL)
  {
	  VDY_PROF_MARKER(services->pfRTAAlgoServiceAddEvent, VDY_PROF_MARKER_MOT_ST);
  }  
#endif
}


/* **********************************************************************
	Unit Design for vdyPostProcess is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyPostProcess( const reqVdyPrtList_t *reqPorts, const VDYInputData_t * input, const VDYNvData_t *VDYNvData, proVdyPrtList_t *proPorts)
{
  VDYCaliState_t SWACaliState = input->Frame.CaliMode;
  /* Get the stand still yaw rate offset */
#if ( (!defined(CFG_VDY_DIS_YWR_OFFSET_COMP)) || (!CFG_VDY_DIS_YWR_OFFSET_COMP) )
#if (CFG_VDY_INT_GYRO)
  const VDYYwrtOffsData_t *pYwrOffs = VDYYwrtGetOffsData();
  const VDYYwrOffsData_t *pYwrOffsStd = vdyYwrGetOffsData();
#else
  const VDYYwrOffsData_t *pYwrOffs = vdyYwrGetOffsData();
#endif
#endif

  /* copy the autocode nvm data from the provide port */
#if ( (defined(CFG_VDY_NVM_LEARN_DATA_ERROR)) && (CFG_VDY_NVM_LEARN_DATA_ERROR) )
  /* check for valid values written into NVM */
  if ((VDYNvData->Write.SlfstGrad.SlfStGrad >= MINIMUM_SELF_NVM_STEERING_GRAD) && (VDYNvData->Write.SlfstGrad.SlfStGrad <= MAXIMUM_SELF_STEERING_GRAD)
      && (VDYNvData->Write.SlfstGrad.CalStatus >= 0)&&(VDYNvData->Write.SlfstGrad.CalStatus <= 1))
    {
#endif
  proPorts->pNVMWrite->SlfstGrad = VDYNvData->Write.SlfstGrad;
#if( (defined(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))&&(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))
  proPorts->pNVMWrite->SlfstGrad.Dummy = 0;
#endif
  VDY_SET_NVM_IO_STATE(VDY_NVM_POS_SSG,
                       VDY_GET_NVM_IO_STATE(VDY_NVM_POS_SSG, &VDYNvData->Write.State),
                       &proPorts->pNVMWrite->State);
#if ( (defined(CFG_VDY_NVM_LEARN_DATA_ERROR)) && (CFG_VDY_NVM_LEARN_DATA_ERROR) )
     /* check for valid values written into NVM */
     proPorts->pVDYErrors->OutPutErrors.SSGNVMOffsRg = VDY_ERR_STATE_INACTIVE;
    }
	else
    {
     /*keep the old value into the NVM */
     proPorts->pVDYErrors->OutPutErrors.SSGNVMOffsRg = VDY_ERR_STATE_ACTIVE;
    }
if ((VDYNvData->Write.Wld.Wld_front >= MINIMUM_WHEEL_LOAD_DEP) && (VDYNvData->Write.Wld.Wld_front <= MAXIMUM_WHEEL_LOAD_DEP)
	  && (VDYNvData->Write.Wld.Wld_front_quality >= 0U) && (VDYNvData->Write.Wld.Wld_front_quality <= 1U))
    {
#endif
     proPorts->pNVMWrite->Wld = VDYNvData->Write.Wld;
#if( (defined(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))&&(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))
	 proPorts->pNVMWrite->Wld.Wld_rear = VDY_ZERO_F;
	 proPorts->pNVMWrite->Wld.Wld_rear_quality = VDY_ZERO_U;
#endif
     VDY_SET_NVM_IO_STATE(VDY_NVM_POS_WLD,
                          VDY_GET_NVM_IO_STATE(VDY_NVM_POS_WLD, &VDYNvData->Write.State),
                          &proPorts->pNVMWrite->State);
#if ( (defined(CFG_VDY_NVM_LEARN_DATA_ERROR)) && (CFG_VDY_NVM_LEARN_DATA_ERROR) )
     /* check for valid values written into NVM */
     proPorts->pVDYErrors->OutPutErrors.WLDNVMOffsRg = VDY_ERR_STATE_INACTIVE;
    }
    else
    {
     /*keep the old value into the NVM */
     proPorts->pVDYErrors->OutPutErrors.WLDNVMOffsRg = VDY_ERR_STATE_ACTIVE;
    }
#endif


#if ( (!defined(CFG_VDY_DIS_CURVE_OUTPUT)) || (!CFG_VDY_DIS_CURVE_OUTPUT) )
  /* Convert yaw rates for diag and mts purpose */
  vdyYawRate2Curve(&vdy_internal_data, proPorts );
#endif
  /* Only if steering wheel angle calibration mode is off learn fast SWA offset */
#if ((!defined(CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING))
#if ( (!defined(CFG_VDY_DIS_YWR_OFFSET_COMP)) || (!CFG_VDY_DIS_YWR_OFFSET_COMP) )
  if (proPorts->pVDYOffsets->Swa.State < VDY_TWO)
#endif
  {
   if (!VDY_CTRL_GET_STATE((VDYCaliState_t)VDY_CAL_SWA_OFFS, SWACaliState))
   {
    vdyCalcFastSwaOffset(input);
   }
  }
#endif

#if (!CFG_VDY_MFC)
    if (VDY_CTRL_GET_STATE((VDYCtrlState_t)VDY_CTRL_STATE_INIT, input->Frame.CtrlMode))
#else
    if (VDY_CTRL_GET_STATE( (BaseOpMode_t)BASE_OM_RESET, input->Frame.OpMode) )
#endif
  {
    vdyInitVehDyn(proPorts->pVehicleDynamicSignals);
#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_OUTPUT)) || (!CFG_VDY_DIS_YAW_SENSOR_OUTPUT) )
    vdyInitALNYawRate(proPorts->pALNYawRate);
#endif
    vdyInitOffsets(proPorts->pVDYOffsets);
    vdyInitErrors(proPorts->pVDYErrors);
    vdyInitInternal(&vdy_internal_data);
    vdyInitModuleIf(&VDYModIf);
  }

  /* output curvature */
  proPorts->pVehicleDynamicSignals->Lateral.Curve   = VDYModIf.Curve;
  if (proPorts->pVehicleDynamicSignals->Lateral.Curve.VarCurve< VDY_ZERO_F)
  {
    /* if variance is negative, the ye model encountered a problem, set output to invalid and restart ye model */
    proPorts->pVehicleDynamicSignals->Lateral.Curve.VarCurve = VDY_HUNDRED_F;
    if (vdy_ye_k.u_CurveFaultCounter < VDY_VAR_FAULT_COUNTER_THRESHOLD)
    {
      vdy_ye_k.u_CurveFaultCounter++;
    }
    if (vdy_ye_k.u_CurveFaultCounter >= VDY_VAR_FAULT_COUNTER_THRESHOLD)
    {
      VDY_SET_IO_STATE(VDY_SOUT_POS_CURVE, VDY_IO_STATE_INVALID, proPorts->pVehicleDynamicSignals->State);
      vdyReinitYawRate();
    }
  }
  else
  {
     vdy_ye_k.u_CurveFaultCounter = 0U;
  }
  vdyCalculateLaneErrorConf(reqPorts, input, proPorts->pVDYOffsets, proPorts->pVehicleDynamicSignals);

  /* output yaw rate */
  proPorts->pVehicleDynamicSignals->Lateral.YawRate = VDYModIf.YawRate;
  if (proPorts->pVehicleDynamicSignals->Lateral.YawRate.Variance < VDY_ZERO_F)
  {
    /* if variance is negative, the ye model encountered a problem, set output to invalid and restart ye model */
    proPorts->pVehicleDynamicSignals->Lateral.YawRate.Variance = VDY_YAWRATE_MAX_VARIANCE;
    if (vdy_ye_k.u_YawFaultCounter < VDY_VAR_FAULT_COUNTER_THRESHOLD)
    {
      vdy_ye_k.u_YawFaultCounter++;
    }
    if (vdy_ye_k.u_YawFaultCounter >= VDY_VAR_FAULT_COUNTER_THRESHOLD)
    {
      VDY_SET_IO_STATE(VDY_SOUT_POS_YAWRATE, VDY_IO_STATE_INVALID, proPorts->pVehicleDynamicSignals->State);
      vdyReinitYawRate();
    }
  }
  else
  {
    vdy_ye_k.u_YawFaultCounter = 0U;
  }

#if (!CFG_VDY_MFC)
  /* Raw estimated OutPut yaw rate */
  if(VDY_GET_IO_STATE(VDY_SIN_POS_YWR, input->Signals.State) != VDY_IO_STATE_INVALID)
  {
    proPorts->pVehicleDynamicSignals->Lateral.YawRate.YawRateRaw = input->Signals.YawRate - proPorts->pVDYOffsets->Ywr.StandStillOffset;
    VDY_SET_IO_STATE(VDY_SOUT_POS_RAW_YWR, VDY_IO_STATE_VALID, proPorts->pVehicleDynamicSignals->State);
  }
  else
  {
    proPorts->pVehicleDynamicSignals->Lateral.YawRate.YawRateRaw = 0.0F;
    VDY_SET_IO_STATE(VDY_SOUT_POS_RAW_YWR, VDY_IO_STATE_INVALID, proPorts->pVehicleDynamicSignals->State);
  }
#endif

  /* output lateral acceleration */
  proPorts->pVehicleDynamicSignals->Lateral.Accel   = VDYModIf.LatAcc;

  /* output driver intended curve */
  proPorts->pVehicleDynamicSignals->Lateral.DrvIntCurve.Curve    = vdy_internal_data.vdy_sye_out.stw_curve;
  proPorts->pVehicleDynamicSignals->Lateral.DrvIntCurve.Variance = vdy_internal_data.vdy_sye_out.stw_curve_var;
  if (proPorts->pVehicleDynamicSignals->Lateral.DrvIntCurve.Variance < VDY_ZERO_F)
  {
    /* if variance is negative, the ye model encountered a problem, set output to invalid and restart ye model */
    proPorts->pVehicleDynamicSignals->Lateral.DrvIntCurve.Variance = VDY_HUNDRED_F;
    if (vdy_ye_k.u_DICurveFaultCounter < VDY_VAR_FAULT_COUNTER_THRESHOLD)
    {
      vdy_ye_k.u_DICurveFaultCounter++;
    }
    if (vdy_ye_k.u_DICurveFaultCounter >= VDY_VAR_FAULT_COUNTER_THRESHOLD)
    {
      VDY_SET_IO_STATE(VDY_SOUT_POS_DRVINTCURVE, VDY_IO_STATE_INVALID, proPorts->pVehicleDynamicSignals->State);
#if (!CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING)
      vdy_sye_initialize((boolean_T) 1, &vdy_sye_B, &vdy_sye_DWork);  /* Re-Initialize vdy_sye model */
#endif
      vdyReinitYawRate();  /* Re-Initialize vdy_ye model */
    }
  }
  else
  {
    vdy_ye_k.u_DICurveFaultCounter = 0U;
  }
  proPorts->pVehicleDynamicSignals->Lateral.DrvIntCurve.Gradient = vdy_internal_data.vdy_sye_out.stw_curve_grad;

  /* output velocity and acceleration variables */
  proPorts->pVehicleDynamicSignals->Longitudinal.Velocity      =  vdy_internal_data.vdy_ve_out.veh_velo;
  #if (CFG_VDY_DO_VELOCITY_CORR)
  proPorts->pVehicleDynamicSignals->Longitudinal.varVelocity   =  VDYModIf.LongMot.corrVeloVar;
  #else/* Disabled - as no velocity correction in MFC. */
  proPorts->pVehicleDynamicSignals->Longitudinal.varVelocity   =  VDYModIf.LongMot.VehVeloVar;
  #endif
  proPorts->pVehicleDynamicSignals->Longitudinal.Accel         =  VDYModIf.LongMot.VehAccel;
  proPorts->pVehicleDynamicSignals->Longitudinal.varAccel      =  VDYModIf.LongMot.VehAccelVar;

  /* output vehicle motion state */
  proPorts->pVehicleDynamicSignals->MotionState.MotState   =  VDYModIf.LongMot.MotState.MotState;
  proPorts->pVehicleDynamicSignals->MotionState.Confidence =  VDYModIf.LongMot.MotState.Confidence;

  /* output slip angle */
  proPorts->pVehicleDynamicSignals->Lateral.SlipAngle = VDYModIf.SideSlipAngle;

#if(CFG_VDY_MFC)
  #if (VDY_VEH_DYN_INTFVER > 6U)
  /* offset compensated steering wheel angle  */
  proPorts->pVehicleDynamicSignals->Lateral.OffCompStWheelAngle= input->Signals.StWheelAngle - vdy_internal_data.vdy_offsets_in.vdy_swa_offset.offset;
  #endif
  
#if(VDY_VEH_DYN_INTFVER >= 33U)
  proPorts->pVehicleDynamicSignals->Lateral.SelfSteering.RoadBankAngle    = vdy_internal_data.vdy_aye_out.track_bent;
  proPorts->pVehicleDynamicSignals->Lateral.SelfSteering.SelfSteerGradEst = vdy_internal_data.vdy_sye_out.stw_understeer_grad;
  /* If Gyro YawRate and Lateral Accel is valid +
     Gye Variance < 0.025, 
	 then BankRoad Angle quality shall be considered as good*/
  if (((sint32)VDY_GET_IO_STATE(VDY_SIN_POS_YWR,input->Signals.State) == VDY_IO_STATE_VALID) &&
	 ((sint32)VDY_GET_IO_STATE(VDY_SIN_POS_LATA,input->Signals.State) == VDY_IO_STATE_VALID) &&
	 (vdy_internal_data.vdy_gye_out.gier_yaw_rate_var < VDY_YAWRATE_MAX_VARIANCE))
  {
	  /* If Ay offset state > 1 */
	  if(vdy_internal_data.vdy_aye_out.r_On_Off_control == 1U)
	  {
		  proPorts->pVehicleDynamicSignals->Lateral.SelfSteering.QuRoadBankAngle = VDY_ONE_F;
	  }
	  /* If Ay offset state <= 1 */
	  else if(vdy_internal_data.vdy_aye_out.r_On_Off_control == VDY_TWO_U)
	  {
		  proPorts->pVehicleDynamicSignals->Lateral.SelfSteering.QuRoadBankAngle = VDY_FIFTY_CENT;
	  }
	  else
	  {
		  proPorts->pVehicleDynamicSignals->Lateral.SelfSteering.QuRoadBankAngle = VDY_ZERO_F;
	  }
  }
  else
  {
	  proPorts->pVehicleDynamicSignals->Lateral.SelfSteering.QuRoadBankAngle = VDY_ZERO_F;
  }

  /* If input SWA is valid +
     VDY Yaw and Velocity is valid or decreased +
	 WheelBase,SteerRatio is valid, 
	 then SSG quality shall be considered as good and Valid*/
  if (((sint32)VDY_GET_IO_STATE(VDY_SIN_POS_SWA,input->Signals.State) == VDY_IO_STATE_VALID) &&
	 (((sint32)VDY_GET_IO_STATE(VDY_SOUT_POS_YAWRATE,proPorts->pVehicleDynamicSignals->State) == VDY_IO_STATE_VALID) || ((sint32)VDY_GET_IO_STATE(VDY_SOUT_POS_YAWRATE,proPorts->pVehicleDynamicSignals->State) == VDY_IO_STATE_DECREASED)) &&
	 (((sint32)VDY_GET_IO_STATE(VDY_SOUT_POS_VELOCITY,proPorts->pVehicleDynamicSignals->State) == VDY_IO_STATE_VALID) || ((sint32)VDY_GET_IO_STATE(VDY_SOUT_POS_YAWRATE,proPorts->pVehicleDynamicSignals->State) == VDY_IO_STATE_DECREASED)) &&
	 ((sint32)VDY_GET_IO_STATE(VDY_PAR_POS_SWARAT,input->Parameter.State) == VDY_IO_STATE_VALID) &&
	 ((sint32)VDY_GET_IO_STATE(VDY_PAR_POS_WBASE,input->Parameter.State) == VDY_IO_STATE_VALID)
	 )
  {
	  proPorts->pVehicleDynamicSignals->Lateral.SelfSteering.QuSelfSteerGradEst = VDY_ONE_F;
	  VDY_SET_IO_STATE(VDY_SOUT_POS_SELFSTEERING, VDY_IO_STATE_VALID, proPorts->pVehicleDynamicSignals->State);
  }
  else
  {
	  proPorts->pVehicleDynamicSignals->Lateral.SelfSteering.QuSelfSteerGradEst = VDY_ZERO_F;
	  VDY_SET_IO_STATE(VDY_SOUT_POS_SELFSTEERING, VDY_IO_STATE_INVALID, proPorts->pVehicleDynamicSignals->State);
  }
#endif
#endif

#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_OUTPUT)) || (!CFG_VDY_DIS_YAW_SENSOR_OUTPUT) )
  /* sensor yaw rate output */
  proPorts->pALNYawRate->YawRate          = vdy_internal_data.vdy_gye_out_filt.gier_yaw_rate;
  proPorts->pALNYawRate->Quality          = 0.0F;
#endif

  /* Generate qualitys for sensor yaw rate, vehicle yaw rate and vehicle curve */
  vdyGenYawAndCurveQualitys(&vdy_internal_data,proPorts,input);

  /* VDY should write this VersionNumber _EVERY_ time in "VDYExec()" when writing VDYOffsets to MDB.*/
  proPorts->pVDYOffsets->uiVersionNumber = VDY_OFFSETS_INTFVER;

#if ( (!defined(CFG_VDY_DIS_YWR_OFFSET_COMP)) || (!CFG_VDY_DIS_YWR_OFFSET_COMP) )
  /* Yaw rate Offset output */
  proPorts->pVDYOffsets->Ywr.StandStillOffset = pYwrOffs->ToAutocode.OffsData.offset;
  proPorts->pVDYOffsets->Ywr.DynOffset = vdy_internal_data.vdy_wye_out.gier_yaw_rate_offset;
  proPorts->pVDYOffsets->Ywr.DynVariance = vdy_internal_data.vdy_wye_out.gier_yaw_rate_offset_var;
  /* Wrap state to the output state */
  if (CML_f_IsNonZero(vdy_internal_data.vdy_wye_out.gier_yaw_rate_offset - pYwrOffs->ToAutocode.OffsData.offset))
  {
    VDYOutYwrOffsType = (VDYOutYwrOffsType_t)OUT_YWR_OFFS_DYN;
    proPorts->pVDYOffsets->Ywr.StandStillState = (sint32)VDYOutYwrOffsType;
  }
  else
  {
    switch (pYwrOffs->ToAutocode.OffsData.state)
    {
      case VDY_YAWRATE_STATE_STANDSTILL: /* stand still */
        /* if the standstill quality is above 0.75 then use full stand still as base output state
           or the Yaw Rate offset StandStillState was one time OUT_YWR_OFFS_STANDST_FULL */
#if (CFG_VDY_INT_GYRO)
        if ((pYwrOffsStd->QualNoRed >= VDY_SEVENTY_FIVE_CENT) || (proPorts->pVDYOffsets->Ywr.StandStillState == (sint32)OUT_YWR_OFFS_STANDST_FULL))
#else
        if ((pYwrOffs->QualNoRed >= VDY_SEVENTY_FIVE_CENT) || (proPorts->pVDYOffsets->Ywr.StandStillState == (sint32)OUT_YWR_OFFS_STANDST_FULL))
#endif
        {
          VDYOutYwrOffsType = (VDYOutYwrOffsType_t)OUT_YWR_OFFS_STANDST_FULL;
          proPorts->pVDYOffsets->Ywr.StandStillState = (sint32)VDYOutYwrOffsType;
        }
        else
        {
          /* if standstill quality is below 0.75 the stand still yaw rate offset sample time was to short */
          VDYOutYwrOffsType = (VDYOutYwrOffsType_t)OUT_YWR_OFFS_STANDST_SHORT;
          proPorts->pVDYOffsets->Ywr.StandStillState = (sint32)VDYOutYwrOffsType;
        }
        break;

      case VDY_YAWRATE_STATE_NVM: /* eeprom */
        VDYOutYwrOffsType = (VDYOutYwrOffsType_t)OUT_YWR_OFFS_STANDST_EEPROM;
        proPorts->pVDYOffsets->Ywr.StandStillState = (sint32)VDYOutYwrOffsType;
        break;

      case VDY_YAWRATE_STATE_NOT_ESTIMATED: /* no offset */
        VDYOutYwrOffsType = (VDYOutYwrOffsType_t)OUT_YWR_OFFS_NON;
        proPorts->pVDYOffsets->Ywr.StandStillState = (sint32)VDYOutYwrOffsType;
        break;

      case VDY_YAWRATE_STATE_KEEP_TYPE: /* fallthrough: do not take over use last type */
      default:
        proPorts->pVDYOffsets->Ywr.StandStillState = (sint32)VDYOutYwrOffsType;
        break;
    }
  }
#else
  /* Yaw rate Offset output */
  proPorts->pVDYOffsets->Ywr.StandStillOffset = 0.0F;
  proPorts->pVDYOffsets->Ywr.DynOffset        = 0.0F;
  proPorts->pVDYOffsets->Ywr.DynVariance      = 0.001F;
  proPorts->pVDYOffsets->Ywr.StandStillState  = (sint32)OUT_YWR_OFFS_NON;  
#endif

  /* Swa Offset output */
  proPorts->pVDYOffsets->Swa.Offset = vdy_internal_data.vdy_offsets_in.vdy_swa_offset.offset;
  proPorts->pVDYOffsets->Swa.State = (sint32)vdy_internal_data.vdy_offsets_in.vdy_swa_offset.state;
  proPorts->pVDYOffsets->Swa.Variance = vdy_internal_data.vdy_offsets_in.vdy_swa_offset.var;
  
  /* Ay Offset output */
  proPorts->pVDYOffsets->Ay.Offset = vdy_internal_data.vdy_offsets_in.vdy_ay_offset.offset;
  proPorts->pVDYOffsets->Ay.State = (sint32)vdy_internal_data.vdy_offsets_in.vdy_ay_offset.state;
  proPorts->pVDYOffsets->Ay.Variance = vdy_internal_data.vdy_offsets_in.vdy_ay_offset.var;


  /* In case of normal state set first cycle done flag */
#if (!CFG_VDY_MFC)
    if (VDY_CTRL_GET_STATE((VDYCtrlState_t)VDY_CTRL_STATE_INIT, input->Frame.CtrlMode))
#else
    if (VDY_CTRL_GET_STATE( (BaseOpMode_t)BASE_OM_RUN, input->Frame.OpMode) )
#endif
  {  
    /* Set flag to indicate that first cycle execution is completed */
    VDY_SET_FIRST_CYCLE_DONE;

    /* Monitor the vdy output signals for physical range only if the vdy is in running mode */
    vdyMonitorOutput( input, proPorts, reqPorts);

    /* if monitoring yaw rate with alignment offset is switched on */
#if ( (defined(CFG_VDY_ALIGNMENT_OFFSET_MONITOR)) && (CFG_VDY_ALIGNMENT_OFFSET_MONITOR) )
    /* Monitor the yaw rate offset */
    vdyAlignmentYawOffsMonitor(reqPorts, VDYIn, &vdy_internal_data, proPorts->pVDYErrors);
#endif

    /* Functional safety monitoring functions */
#if !(defined(CFG_VDY_DIS_FUNCTIONAL_SAFETY_MON) && (CFG_VDY_DIS_FUNCTIONAL_SAFETY_MON))
    vdyFSMonitor(&vdy_internal_data, &VDYModIf, proPorts);
#endif
  }
}
/* <ln_offset:-1 MISRA Rule 16.7: reviewer name: Jochen Spruck date: 27-09-2010 reason: VDYNvData could not be declared as const because of compiler switches  */



/* **********************************************************************
	Unit Design for vdyEnvMeasFreezeInternal is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyEnvMeasFreezeInternal(const AS_t_ServiceFuncts * services, VDYInputData_t *VDYIn)
{
  /* <ln_offset:-2 PCLINT Error 578: reviewer name: Frank Wolter date: 09-07-2013 reason: parameter only hidden if not used at all, implementation to keep same code with and without services */
#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING) )
  VDYYwrData_t    *pYwrData  = vdyYwrGetPrivateData();
#endif
#if ( (!defined(CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING) )
  VDYSwaData_t    *pSwaData  = vdySwaGetPrivateData();
#endif
#if ( (!defined(CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING) )
  VDYAyData_t     *pAyData   = vdyAyGetPrivateData();
#endif
#if ( (!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING) )
  VDYWhsData_t    *pWhsData  = vdyWhsGetPrivateData();
#endif
#if (CFG_VDY_INT_GYRO)
  VDYYwrtData_t   *pYwrtData = VDYYwrtGetPrivateData();
#endif
  
#if (CFG_VDY_USE_VELO_MONITOR)
#ifdef _WIN32
#pragma message(__FILE__"("STRING_QUOTE(__LINE__)"): Add meas freeze for velo monitoring if needed")
  /* <ln_offset:-1 PCLINT Error 975: reviewer name: Jochen Spruck date: 27-09-2010  reason: only todo message */
#endif
  /* VDYVelMon_t     *pVelMon   = VDYVelMonGetPrivateData(); */
  /* add some meas monitoring freeze data AuxMeasData.Reserved[0] = pVelMon->cntOutSide; */
#endif

#ifndef AS_SERVICEFUNC_VERSION
  (void)services;  /* remove compiler warning, services is not used in this configuration */
#endif

  /* Fetch the vdy configuration */
  vdyGetConfig();

  /* Freeze component internal data groups */
#if ( (!defined(CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING) )
  VDYInternal.VDYSwa = *pSwaData;
#endif
#if ( (!defined(CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING) )
  VDYInternal.VDYAy = *pAyData;
#endif
#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING) )
  VDYInternal.VDYYwr = *pYwrData;
#endif

#if (CFG_VDY_INT_GYRO)
  VDYInternal.VDYYwrt = *pYwrtData;
#endif

#if ( (!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING) )
  VDYInternal.VDYWhs = *pWhsData;
#endif

#if (CFG_VDY_YWR_OFFSET_MONITOR)
  { 
    VDYYwrMonData_t  *pYwrMonData = vdyYwrMonGetPrivateData();
    VDYInternal.VDYYwrMonData = *pYwrMonData;
  }
#endif
  
#if (CFG_VDY_DO_VELOCITY_CORR)
  { 
    VDYVelCorr_t    *pCorrData = VDYVelCorrGetPrivateData();
    VDYInternal.VDYVelCorr = *pCorrData;
  }
#if (CFG_VDY_FS_VELO_CORR_MON)
  {
    VDYFSVelCorrMon_t    *pCorrMonData = VDYFSVelCorrMonGetPrivateData();
    VDYInternal.VDYFSVelCorrMon = *pCorrMonData;
  }
#endif
#endif
  VDYInternal.VDYIntData = vdy_internal_data;
  VDYInternal.VDYBayesOut = vdy_bayes_mot_states;

#if !(defined(CFG_VDY_DIS_FUNCTIONAL_SAFETY_MON) && (CFG_VDY_DIS_FUNCTIONAL_SAFETY_MON))
  {
    VDYFSData_t * VDYFsData = vdyFSMonGetPrivateData();
    VDYInternal.VDYFSMon = *VDYFsData;
  }
#endif
  VDYInternal.VDYYeK = vdy_ye_k;
  VDYInternal.VDYDeltaTimeStamp = VDYDeltaTimeStamp;

#if ( defined(VDY_FREEZE_INIT_SEQUENCE) && (VDY_FREEZE_INIT_SEQUENCE) )
  vdyInitSequenceMeasFreeze(services);
#endif

  VDYInternal.VDY_SyncRef = s_SyncRef;
  VDYInternal.VDYIn = *VDYIn;

  // Measfreezing all the internal structures and VDY input 
  /* MISRA Rule 11.4: reviewer name: Jochen Spruck date: 27-09-2010 reason: proven in use, meas freeze macro  */
  MEAS_FREEZE_DIRECT(VDY_MEAS_ID_INTDATA, &(VDYInternal), sizeof(VDYInternal_t));


  return;
}

#if (CFG_VDY_MFC)
/* **********************************************************************
	Unit Design for vdyInputChecks is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyInputChecks( const reqVdyPrtList_t* const reqPorts, proVdyPrtList_t* const proPorts, const AS_t_ServiceFuncts* const services, AlgoSignalState_t* eVDYSigStatus, uint8 uiReqPortNullPtrCheck )
{
  /* InputCheck with Priority(1) : Check request port's NULL Pointer. */
  if( uiReqPortNullPtrCheck != VDY_REQUEST_PORT_FAULT )
  {
    /* InputCheck with Priority(2) : If request ports are not NULL, then check for their version numbers. */
    vdyCheckRequestPortVersionNumber( reqPorts,services );

	/* InputCheck with Priority(3) : Check request port's signal status. */
    vdyCheckReqPortSignalState( reqPorts, proPorts, eVDYSigStatus, services );

	/* InputCheck with Priority(4) : Timestamp and MeasureCounter check. */
	vdyCheckTimestamp_MeasCounter( reqPorts, services );
  }
  /* TODO : Timestamp and Measurement counter check. */
}


/* **********************************************************************
	Unit Design for vdyCheckRequestPortVersionNumber is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyCheckRequestPortVersionNumber( const reqVdyPrtList_t* const reqPorts,const AS_t_ServiceFuncts* services )
{
  uint8 uiOpData[VDY_THREE];

  uiOpData[VDY_ZERO] = FUSI_ERROR_DIR_INPUT;
  uiOpData[VDY_ONE] = FUSI_ERROR_TYPE_VERSIONNUMBER;

  if( (AlgoInterfaceVersionNumber_t)BASE_CTRL_DATA_INTFVER != reqPorts->pBaseCtrlData->uiVersionNumber )
  {
	  if(reqPorts->pBaseCtrlData->eOpMode != (BaseOpMode_t)BASE_OM_RESET)
	  {	  
		/* PRQA S 2810 EOF */
		/* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: Functional Safe */
		uiOpData[VDY_TWO] = (uint8)offsetof( reqVdyPrtList_t, pBaseCtrlData );
		services->pfDem_SetEventStatus( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED );
		services->pfDem_SetEventStatusPreExtData( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED, (const uint8*)uiOpData, sizeof(uiOpData) );
	  }
  }
  else if( (AlgoInterfaceVersionNumber_t)VDY_NVM_IO_DATA_INTFVER != reqPorts->pNVMRead->uiVersionNumber )
  {
	   if( reqPorts->pBaseCtrlData->eOpMode != (BaseOpMode_t)BASE_OM_RESET)
	   {
	    uiOpData[VDY_TWO] = (uint8)offsetof( reqVdyPrtList_t, pNVMRead );
		services->pfDem_SetEventStatus( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED );
		services->pfDem_SetEventStatusPreExtData( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED, (const uint8*)uiOpData, sizeof(uiOpData) );
	   }
  }
  else if( (AlgoInterfaceVersionNumber_t)BSW_VEH_SIG_INTFVER != reqPorts->pVehicleInputSignals->uiVersionNumber )
  {
	 if( reqPorts->pBaseCtrlData->eOpMode != (BaseOpMode_t)BASE_OM_RESET)
	 {
		uiOpData[VDY_TWO] = (uint8)offsetof( reqVdyPrtList_t, pVehicleInputSignals );
		services->pfDem_SetEventStatus( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED );
		services->pfDem_SetEventStatusPreExtData( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED, (const uint8*)uiOpData, sizeof(uiOpData) );
	 }
  }
  else if( (AlgoInterfaceVersionNumber_t)BSW_VEH_PAR_INTFVER != reqPorts->pVehicleParameter->uiVersionNumber )
  {
	 if( reqPorts->pBaseCtrlData->eOpMode != (BaseOpMode_t)BASE_OM_RESET)
	 {		
		uiOpData[VDY_TWO] = (uint8)offsetof( reqVdyPrtList_t, pVehicleParameter );
		services->pfDem_SetEventStatus( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED );
		services->pfDem_SetEventStatusPreExtData( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED, (const uint8*)uiOpData, sizeof(uiOpData) );
	 }
  }
  else
  {
	services->pfDem_SetEventStatus( VDY_FUSI_ERROR, DEM_EVENT_STATUS_PASSED );
	services->pfDem_SetEventStatusPreExtData( VDY_FUSI_ERROR, DEM_EVENT_STATUS_PASSED, (const uint8*)uiOpData, sizeof(uiOpData) );
  }
}

/* **********************************************************************
	Unit Design for vdyCheckReqPortSignalState is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyCheckReqPortSignalState( const reqVdyPrtList_t* const reqPorts, proVdyPrtList_t* const proPorts, AlgoSignalState_t* eVDYSigStatus, const AS_t_ServiceFuncts* services )
{
  uint8 uiOpData[VDY_THREE];

  uiOpData[VDY_ZERO] = FUSI_ERROR_DIR_INPUT;
  uiOpData[VDY_ONE] = FUSI_ERROR_TYPE_SIGNALSTATE;

  if( reqPorts->pBaseCtrlData->eOpMode == (BaseOpMode_t)BASE_OM_RESET )
  {
	*eVDYSigStatus = AL_SIG_STATE_INIT;	// pVehicleParameter output ports will be set to Init when eOpMode is Reset
  }
  else if( reqPorts->pBaseCtrlData->sSigHeader.eSigStatus == (BaseOpMode_t)AL_SIG_STATE_INIT )
  {
	uiOpData[VDY_TWO] = (uint8)offsetof( reqVdyPrtList_t, pBaseCtrlData );
	vdySetProPortSigStateDetectionFlag( proPorts );
  }
  else if( reqPorts->pBaseCtrlData->sSigHeader.eSigStatus == (BaseOpMode_t)AL_SIG_STATE_INVALID )
  {
	*eVDYSigStatus = AL_SIG_STATE_INVALID;	// pBaseCtrlData output ports will be set to invalid and no DEM is set.
  }
  else if( reqPorts->pNVMRead->sSigHeader.eSigStatus == (BaseOpMode_t)AL_SIG_STATE_INVALID )
  {
	*eVDYSigStatus = AL_SIG_STATE_INVALID;	// pNVMRead output port will be set to invalid and no DEM is set.
  }
  else if( reqPorts->pVehicleInputSignals->sSigHeader.eSigStatus == (BaseOpMode_t)AL_SIG_STATE_INIT )
  {
    uiOpData[VDY_TWO] = (uint8)offsetof( reqVdyPrtList_t, pVehicleInputSignals );
	vdySetProPortSigStateDetectionFlag( proPorts );
  }
  else if( reqPorts->pVehicleInputSignals->sSigHeader.eSigStatus == (BaseOpMode_t)AL_SIG_STATE_INVALID )
  {
	*eVDYSigStatus = AL_SIG_STATE_INVALID;	// pVehicleInputSignals output ports will be set to invalid and no DEM is set.
  }
  else if( reqPorts->pVehicleParameter->sSigHeader.eSigStatus == (BaseOpMode_t)AL_SIG_STATE_INIT )
  {
    uiOpData[VDY_TWO] = (uint8)offsetof( reqVdyPrtList_t, pVehicleParameter );
	vdySetProPortSigStateDetectionFlag( proPorts );
  }
  else if( reqPorts->pVehicleParameter->sSigHeader.eSigStatus == (BaseOpMode_t)AL_SIG_STATE_INVALID )
  {
	*eVDYSigStatus = AL_SIG_STATE_INVALID;	// pVehicleParameter output ports will be set to invalid and no DEM is set.
  }
  else
  {
	*eVDYSigStatus = AL_SIG_STATE_OK;
    services->pfDem_SetEventStatus( VDY_FUSI_ERROR, DEM_EVENT_STATUS_PASSED );
	services->pfDem_SetEventStatusPreExtData( VDY_FUSI_ERROR, DEM_EVENT_STATUS_PASSED, (const uint8*)uiOpData, sizeof(uiOpData) );
  }

  /* Set Fusi DEM for reqport holding signal state as INIT for more than 3 debounce cycle. */
  if(( (boolean)TRUE == b_ReqPortStateCrossDebouncLimit )&&(reqPorts->pBaseCtrlData->eOpMode != (BaseOpMode_t)BASE_OM_RESET))
  {
    services->pfDem_SetEventStatus( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED );
	services->pfDem_SetEventStatusPreExtData( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED, (const uint8*)uiOpData, sizeof(uiOpData) );
  }
}


/* **********************************************************************
	Unit Design for vdyCheckTimestamp_MeasCounter is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyCheckTimestamp_MeasCounter( const reqVdyPrtList_t* const reqPorts, const AS_t_ServiceFuncts* services )
{
  uint8 opData[VDY_THREE];
  opData[VDY_ZERO] = FUSI_ERROR_DIR_INPUT;
  opData[VDY_ONE] = FUSI_ERROR_TYPE_COUNTER;

  if( (reqPorts->pBaseCtrlData->sSigHeader.uiTimeStamp - reqPorts->pVehicleInputSignals->sSigHeader.uiTimeStamp) > (AlgoDataTimeStamp_t)ALGO_FUSI_DEBOUNCE_TIME )
  {
		if( reqPorts->pVehicleInputSignals->sSigHeader.uiMeasurementCounter > (AlgoCycleCounter_t)VDY_MEASUREMENT_CNT_WRAPPER_LIMIT )
		{
			/* PRQA S 2880 EOF */
			/* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: No Risk */
			if( reqPorts->pBaseCtrlData->eOpMode != (BaseOpMode_t)BASE_OM_RESET)
			{
			  opData[VDY_TWO] = (uint8)offsetof( reqVdyPrtList_t, pVehicleInputSignals );
			  services->pfDem_SetEventStatus( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED );
			  services->pfDem_SetEventStatusPreExtData( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED, (const uint8*)&opData, sizeof(opData) );
			}
			else
			{
				/*do nothing*/
			}
		}
  }
  if( (reqPorts->pBaseCtrlData->sSigHeader.uiTimeStamp - reqPorts->pNVMRead->sSigHeader.uiTimeStamp) > (AlgoDataTimeStamp_t)ALGO_FUSI_DEBOUNCE_TIME )
  {
    if( reqPorts->pNVMRead->sSigHeader.uiMeasurementCounter > (AlgoCycleCounter_t)VDY_MEASUREMENT_CNT_WRAPPER_LIMIT )
    {

		if( reqPorts->pBaseCtrlData->eOpMode != (BaseOpMode_t)BASE_OM_RESET)
		{
			  opData[VDY_TWO] = (uint8)offsetof( reqVdyPrtList_t, pNVMRead );
			  services->pfDem_SetEventStatus( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED );
			  services->pfDem_SetEventStatusPreExtData( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED, (const uint8*)&opData, sizeof(opData) );
		}
		else
		{
			/*do nothing*/
		}
    }
  }
  if( (reqPorts->pBaseCtrlData->sSigHeader.uiTimeStamp - reqPorts->pVehicleParameter->sSigHeader.uiTimeStamp) > (AlgoDataTimeStamp_t)ALGO_FUSI_DEBOUNCE_TIME )
  {
    
	 if( reqPorts->pVehicleParameter->sSigHeader.uiMeasurementCounter > (AlgoCycleCounter_t)VDY_MEASUREMENT_CNT_WRAPPER_LIMIT )
    {
		if( reqPorts->pBaseCtrlData->eOpMode != (BaseOpMode_t)BASE_OM_RESET)
		{
		  opData[VDY_TWO] = (uint8)offsetof( reqVdyPrtList_t, pVehicleParameter );
		  services->pfDem_SetEventStatus( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED );
		  services->pfDem_SetEventStatusPreExtData( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED, (const uint8*)&opData, sizeof(opData) );
		}
		else
		{
			/*do nothing*/
		}
    }
  }
}

/* **********************************************************************
	Unit Design for vdySetProPortSigStateDetectionFlag is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdySetProPortSigStateDetectionFlag( proVdyPrtList_t* const proPorts )
{
  if( u_ReqPortDebounceCycleCount > (uint8)ALGO_FUSI_DEBOUNCE_CYCLES )
  {
	proPorts->pVehicleDynamicSignals->sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
	proPorts->pVDYOffsets->sSigHeader.eSigStatus            = AL_SIG_STATE_INVALID;
	proPorts->pVDYErrors->sSigHeader.eSigStatus             = AL_SIG_STATE_INVALID;
#if (CFG_VDY_HFL)
  proPorts->pNVMWrite->sSigHeader.eSigStatus              = AL_SIG_STATE_OK;
#else
  proPorts->pNVMWrite->sSigHeader.eSigStatus              = AL_SIG_STATE_INVALID;
#endif
	proPorts->pVDYEstCurves->sSigHeader.eSigStatus          = AL_SIG_STATE_INVALID;

	b_ReqPortStateCrossDebouncLimit = TRUE;			/* ReqPort signal state has crossed debounce limit of 3. */
	u_ReqPortDebounceCycleCount = 0;
  }
  else
  {
    u_ReqPortDebounceCycleCount++;

	proPorts->pVehicleDynamicSignals->sSigHeader.eSigStatus = AL_SIG_STATE_INIT;
	proPorts->pVDYOffsets->sSigHeader.eSigStatus            = AL_SIG_STATE_INIT;
	proPorts->pVDYErrors->sSigHeader.eSigStatus             = AL_SIG_STATE_INIT;
#if (CFG_VDY_HFL)
  proPorts->pNVMWrite->sSigHeader.eSigStatus              = AL_SIG_STATE_OK;
#else
  proPorts->pNVMWrite->sSigHeader.eSigStatus              = AL_SIG_STATE_INIT;
#endif
	proPorts->pVDYEstCurves->sSigHeader.eSigStatus          = AL_SIG_STATE_INIT;

	b_ReqPortStateCrossDebouncLimit = FALSE;		/*  ReqPort signal state is still within debounce limit of 3. */
  }
}
#endif

#if (CFG_VDY_GEN_VELOCITY_VARIANCE)
/* **********************************************************************
	Unit Design for vdyGenVeloVar is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyGenVeloVar(VDYInternalData_t *IntData)
{
/* Generated velo variance is calculate by this parabolic function v_var(a) = m*a^2 +b */
  IntData->vdy_ve_out.veh_velo_var = ( IntData->vdy_ve_out.veh_accel*IntData->vdy_ve_out.veh_accel \
                                      * VDY_GEN_VELO_VAR_M )  + VDY_GEN_VELO_VAR_B;
}
#endif


#if ((!CFG_VDY_DIS_YWR_OFFSET_COMP) && ((!defined(CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING)))
#if (CFG_VDY_INT_GYRO)
/* **********************************************************************
	Unit Design for vdyGenInternalYawRateQuality is found in Declaration Section
**************************************************************************** */
STATIC_MTD fQuality_t vdyGenInternalYawRateQuality(const VDYInternalData_t *IntData, const proVdyPrtList_t *proPorts, const VDYInputData_t *input )
{
  /* If internal yaw sensor is used */
  const VDYYwrtOffsData_t *pYwrOffs = VDYYwrtGetOffsData();

#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_OUTPUT)) || (!CFG_VDY_DIS_YAW_SENSOR_OUTPUT) )
  proPorts->pALNYawRate->Quality = pYwrOffs->Quality;
#endif

  /* Reduce sensor yaw rate quality with difference between raw yaw rate offset and filtered yaw rate offset */
  {
#if (!CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING)
    fYawRate_t ReduceQuality = CML_f_Abs(vdy_internal_data.vdy_wye_out.gier_yaw_rate_offset-IntData->vdy_gye_out_filt.raw_est_yaw_offset_filt)*50.0F;
    boolean b_ReduceQualityisNotZero = CML_f_IsNonZero(ReduceQuality;
    boolean b_LastFilteredisZero = CML_f_IsZero(LastFiltered);

    /* Reduce sensor yaw rate with difference between last filtered yaw rate and stand still offset at stand still */
    if ((b_ReduceQualityisNotZero) || (b_LastFilteredisZero))
    {
      LastFiltered = IntData->vdy_gye_out_filt.raw_est_yaw_offset_filt;
    }
    else
    {
      ReduceQuality += CML_f_Abs(vdy_internal_data.vdy_wye_out.gier_yaw_rate_offset-LastFiltered)*50.0F;
    }

    if (ReduceQuality > 0.2F)
    {
      ReduceQuality = 0.2F;
    }
#else
#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_OUTPUT)) || (!CFG_VDY_DIS_YAW_SENSOR_OUTPUT) )
    fYawRate_t ReduceQuality = 0.0F;
#endif
#endif

#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_OUTPUT)) || (!CFG_VDY_DIS_YAW_SENSOR_OUTPUT) )
    proPorts->pALNYawRate->Quality -= ReduceQuality;

    /* Quality should not be negative */
    if (proPorts->pALNYawRate->Quality < 0.0F)
    {
      proPorts->pALNYawRate->Quality = 0.0F;
    }

    /* set the aln yaw rate offset compensation stat according to the yaw rate offset state */
    switch (pYwrOffs->OffsType)
    {
      case OFFS_NON:
        proPorts->pALNYawRate->OffsetCompState = ALN_YAW_RATE_NO_EEPROM;
        break;

      case OFFS_STANDST:  /* fallthrough: same handling */
      case OFFS_DYN_AVG:  /* fallthrough: same handling */
      case OFFS_DYN_INTER:
        /* if the standstill quality is above 0.75 then use full stand still as base output state
           or the Sensor Yaw Rate OffsetCompState was one time ALN_YAW_RATE_FULL_STAND_STILL */
        if ((pYwrOffs->Quality >= 0.75F) || (proPorts->pALNYawRate->OffsetCompState == ALN_YAW_RATE_FULL_STAND_STILL))
        {
          proPorts->pALNYawRate->OffsetCompState = ALN_YAW_RATE_FULL_STAND_STILL;
        }
        else
        {
          /* if standstill quality is below 0.75 the stand still yaw rate offset sample time was to short */
          proPorts->pALNYawRate->OffsetCompState = ALN_YAW_RATE_SHORT_STAND_STILL;
        }
        break;

      case OFFS_STANDST_EEPROM:
        proPorts->pALNYawRate->OffsetCompState = ALN_YAW_RATE_NO_STAND_STILL;
        break;
 
      case OFFS_DYN_APPRX:     /* fallthrough: same as default */
      case OFFS_TEMPER_TABLE:  /* fallthrough: same as default */
      default:
        /* do nothing */
        break;

    }

    /* if offset elapsed time is below the threshold set it to const quality */
    if (pYwrOffs->OffsElpsdTime <= VDY_OFFSET_ELAPSED_TIME_QUALI_THRESH)
    {
      proPorts->pALNYawRate->OffsetCompState = ALN_YAW_RATE_PROCESS_STAND_STILL;
    }
#endif
  }

#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_OUTPUT)) || (!CFG_VDY_DIS_YAW_SENSOR_OUTPUT) )
  /* Set output state to internal input yaw rate state */
  if (VDY_GET_IO_STATE(VDY_SIN_POS_YWRINT,input->Signals.State) == VDY_IO_STATE_VALID)
  {
    proPorts->pALNYawRate->bSenYawRateState = TRUE;
  }
  else
  {
    proPorts->pALNYawRate->bSenYawRateState = FALSE;
  }
#endif

  return (pYwrOffs->Quality * 0.45F);
}


#endif


/* **********************************************************************
	Unit Design for vdyGenExternalYawRateQuality is found in Declaration Section
**************************************************************************** */
#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING)) || (!CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING) )
STATIC_MTD fQuality_t vdyGenExternalYawRateQuality(const VDYInternalData_t *IntData, const proVdyPrtList_t *proPorts, const VDYInputData_t *input )
#else
STATIC_MTD fQuality_t vdyGenExternalYawRateQuality(const proVdyPrtList_t *proPorts, const VDYInputData_t *input )
#endif
{
  /* If external yaw sensor is used */
  const VDYYwrOffsData_t *pYwrOffs = vdyYwrGetOffsData();
#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_OUTPUT)) || (!CFG_VDY_DIS_YAW_SENSOR_OUTPUT) )
  static fQuality_t TempSensorYawRateQuality = VDY_ZERO_F;
#endif
  static fQuality_t TempVehSensorYawRateQuality = VDY_ZERO_F;

#if (!CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING)
  /* Reduce sensor yaw rate quality with difference between raw yaw rate offset and filtered yaw rate offset */
  /* if the diff is 0.01rad the reduce Quality is 0.5 -> (Quality = 0.05*diff[mrad])  */
  fYawRate_t ReduceQuality = CML_f_Abs(IntData->vdy_wye_out.raw_est_yaw_offset-IntData->vdy_gye_out_filt.raw_est_yaw_offset_filt) * VDY_FIFTY_F;
  boolean b_ReduceQualityIsNonYero = (boolean)(CML_f_IsNonZero(ReduceQuality) ? TRUE : FALSE);
  boolean b_LastFilteredIsZero = (boolean)(CML_f_IsZero(LastFiltered) ? TRUE : FALSE);

  /* Reduce sensor yaw rate with difference between last filtered yaw rate and stand still offset at stand still */
  if ((b_ReduceQualityIsNonYero == (boolean)TRUE) || (b_LastFilteredIsZero == (boolean)TRUE))
  {
    LastFiltered = IntData->vdy_gye_out_filt.raw_est_yaw_offset_filt;
  }
  else
  {
#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_OUTPUT)) || (!CFG_VDY_DIS_YAW_SENSOR_OUTPUT) )
    /* The difference between the current filtered dyn offset and the last filtered last dyn offset*/
    ReduceQuality += CML_f_Abs(IntData->vdy_wye_out.raw_est_yaw_offset-LastFiltered)*50.0F;
#endif
  }

#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_OUTPUT)) || (!CFG_VDY_DIS_YAW_SENSOR_OUTPUT) )
  /* limit ReduceQuality */
  if (ReduceQuality > 0.2F)
  {
    ReduceQuality = 0.2F;
  }
#endif
#else
#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_OUTPUT)) || (!CFG_VDY_DIS_YAW_SENSOR_OUTPUT) )
  fYawRate_t ReduceQuality = 0.0F;
#endif
#endif

  /* Case No yaw rate sensor offset -> quality = 0.25 - Reduce Quality
  Case stand still yaw rate sensor offset + its Quality is = 1.0 -> quality = 1.0 - Reduce Quality
  Case stand still yaw rate sensor offset + its Quality is < 1.0 -> quality = 0.75 - Reduce Quality
  Case EEPROM yaw rate sensor offset -> quality = 0.5 - Reduce Quality */
  switch (pYwrOffs->OffsType)
  {
    case OFFS_NON:
#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_OUTPUT)) || (!CFG_VDY_DIS_YAW_SENSOR_OUTPUT) )
      proPorts->pALNYawRate->OffsetCompState = ALN_YAW_RATE_NO_EEPROM;
#endif
      TempVehSensorYawRateQuality =  VDY_ZERO_F;
      break;

    case OFFS_STANDST:
    case OFFS_DYN_AVG:
    case OFFS_DYN_INTER:
      /* if the standstill quality is above 0.75 then use full stand still as base output state
      or the Sensor Yaw Rate OffsetCompState was one time ALN_YAW_RATE_FULL_STAND_STILL */
#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_OUTPUT)) || (!CFG_VDY_DIS_YAW_SENSOR_OUTPUT) )
      if ((pYwrOffs->QualNoRed >= VDY_SEVENTY_FIVE_CENT) || (proPorts->pALNYawRate->OffsetCompState == (OffsetCompState_t)ALN_YAW_RATE_FULL_STAND_STILL))
      {
        proPorts->pALNYawRate->OffsetCompState = ALN_YAW_RATE_FULL_STAND_STILL;
      }
      else
      {
        /* if standstill quality is below 0.75 the stand still yaw rate offset sample time was to short */
        proPorts->pALNYawRate->OffsetCompState = ALN_YAW_RATE_SHORT_STAND_STILL;
      }
#endif
      TempVehSensorYawRateQuality =  VDY_FORTY_FIVE_CENT;
      break;

    case OFFS_STANDST_EEPROM:
#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_OUTPUT)) || (!CFG_VDY_DIS_YAW_SENSOR_OUTPUT) )
      proPorts->pALNYawRate->OffsetCompState = ALN_YAW_RATE_NO_STAND_STILL;
#endif
      TempVehSensorYawRateQuality =  VDY_TWENTY_CENT;
      break;

    case OFFS_DYN_APPRX:
    case OFFS_TEMPER_TABLE:
	/* PRQA S 2016 EOF */
	/* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: No Risk */
    default: 
      break;
      /* take last values because static */
  }

#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_OUTPUT)) || (!CFG_VDY_DIS_YAW_SENSOR_OUTPUT) )
  /* Quality should only be the reduce Quality */
  TempSensorYawRateQuality = ReduceQuality;
#endif

#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_OUTPUT)) || (!CFG_VDY_DIS_YAW_SENSOR_OUTPUT) )
  /* if offset elapesed time is below the threshold set it to const quality */
  if (pYwrOffs->OffsElpsdTime <= VDY_OFFSET_ELAPSED_TIME_QUALI_THRESH)
  {
    proPorts->pALNYawRate->OffsetCompState = ALN_YAW_RATE_PROCESS_STAND_STILL;
  }

  /* copy to stuct */
  proPorts->pALNYawRate->Quality = TempSensorYawRateQuality;

  /* Set output state to external input yaw rate state */
  /* <ln_offset:+2 PCLINT Error 835: reviewer name: Jochen Spruck date: 27-09-2010 reason: first state element has pos 0 */
  /* <ln_offset:+1 PCLINT Error 845: reviewer name: Jochen Spruck date: 27-09-2010 reason: first state element has pos 0 */
  if (VDY_GET_IO_STATE(VDY_SIN_POS_YWR,input->Signals.State) == VDY_IO_STATE_VALID)
  {
    proPorts->pALNYawRate->bSenYawRateState = TRUE;
  }
  else
  {
    proPorts->pALNYawRate->bSenYawRateState = FALSE;
  }
#else
  (void)input;     /* remove compiler warning, input is not used in this configuration */
  (void)proPorts;  /* remove compiler warning, proPorts is not used in this configuration */
#endif

  return TempVehSensorYawRateQuality;
}
#endif


/* **********************************************************************
	Unit Design for vdyGenYawAndCurveQualitys is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyGenYawAndCurveQualitys(const VDYInternalData_t *IntData, proVdyPrtList_t *proPorts, const VDYInputData_t *input )
{
  fQuality_t VehSensorYawQuality;
  fQuality_t VehicleCurveYawQuality = VDY_ZERO_F;

#if ((CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING) && (CFG_VDY_DIS_SWA_OFFSET_COMP) && (CFG_VDY_DIS_LAT_OFFSET_COMP) && (CFG_VDY_DIS_WHS_OFFSET_COMP))
  (void)IntData;  /* remove compiler warning, IntData is not used in this configuration */
#endif

  /* Sensor yaw rate quality */
  /* If vdy does the sensor yaw rate offset is estimation */
#if ((!CFG_VDY_DIS_YWR_OFFSET_COMP) && ((!defined(CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING)))
  /* If internal yaw sensor is used, the quality of the internal yaw rate estimation is used */
#if (CFG_VDY_INT_GYRO)
  /* if external yaw rate signal is valid use the external yaw rate signal otherwise the internal */
  /* <ln_offset:+2 PCLINT Error 845: reviewer name: Jochen Spruck date: 4-05-2011 reason: proven in use, error because mask value is zero */
  /* <ln_offset:+1 PCLINT Error 835: reviewer name: Jochen Spruck date: 4-05-2011 reason: proven in use, error because mask value is zero */
  if (VDY_GET_IO_STATE(VDY_SIN_POS_YWR, input->Signals.State) == VDY_IO_STATE_VALID)
  {
    /* Get quality from external yaw rate sensor processing */
#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING)) || (!CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING) )
    VehSensorYawQuality =vdyGenExternalYawRateQuality(IntData, proPorts, input);
#else
    VehSensorYawQuality =vdyGenExternalYawRateQuality(proPorts, input);
#endif
  }
  else
  {
    /* Get quality from internal yaw rate sensor processing */
    VehSensorYawQuality = vdyGenInternalYawRateQuality(IntData, proPorts, input);
  }
#else
  /* If external yaw sensor is used */
  /* Get quality from external yaw rate sensor processing */
#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING)) || (!CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING) )
  VehSensorYawQuality = vdyGenExternalYawRateQuality(IntData, proPorts, input);
#else
  VehSensorYawQuality = vdyGenExternalYawRateQuality(proPorts, input);
#endif
#endif
#else
  /* If yaw rate offset compensation is disabeled */
  VehSensorYawQuality =  0.45F;

#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_OUTPUT)) || (!CFG_VDY_DIS_YAW_SENSOR_OUTPUT) )
  proPorts->pALNYawRate->Quality = 1.0F;

  /* set the offset compensation stat always to full stand still */
  proPorts->pALNYawRate->OffsetCompState = ALN_YAW_RATE_FULL_STAND_STILL;

  /* Set output state to external input yaw rate state */
  /* <ln_offset:+2 PCLINT Error 835: reviewer name: Jochen Spruck date: 27-09-2010 reason: first state element has pos 0 */
  /* <ln_offset:+1 PCLINT Error 845: reviewer name: Jochen Spruck date: 27-09-2010 reason: first state element has pos 0 */
  if (VDY_GET_IO_STATE(VDY_SIN_POS_YWR,input->Signals.State) == VDY_IO_STATE_VALID)
  {
    proPorts->pALNYawRate->bSenYawRateState = TRUE;
  }
  else
  {
    proPorts->pALNYawRate->bSenYawRateState = FALSE;
  }
#else
  (void)input; /* remove compiler warning, input is not used in certain configurations */
#endif

#endif

  /* Add vehicle sensor yaw rate quality */
  VehicleCurveYawQuality += VehSensorYawQuality;

  /* Add steering wheel angle offset quality, if available */
#if (!CFG_VDY_DIS_SWA_OFFSET_COMP)
  if (IntData->vdy_offsets_in.vdy_swa_offset.state > (uint8)VDY_TWO_U)
  {
    VehicleCurveYawQuality += VDY_THIRTY_FIVE_CENT;
  }
#else
  VehicleCurveYawQuality += VDY_THIRTY_FIVE_CENT;
#endif

  /* Add lateral acceleration offset quality, if available */
#if (!CFG_VDY_DIS_LAT_OFFSET_COMP)
  if (IntData->vdy_offsets_in.vdy_ay_offset.state > (uint8)VDY_TWO_U)
  {
    VehicleCurveYawQuality += VDY_FIFTEEN_CENT;
  }
#else
  VehicleCurveYawQuality += VDY_FIFTEEN_CENT;
#endif

  /* Add wheel velocity offset quality, if available */
#if (!CFG_VDY_DIS_WHS_OFFSET_COMP)
  if (   (IntData->vdy_offsets_in.vdy_whs_offset.offset_ratio_front_dev < VDY_ONE_F)
      && (IntData->vdy_offsets_in.vdy_whs_offset.offset_ratio_rear_dev < VDY_ONE_F))
  { 
	/* PRQA S 2983 EOF */
	  /* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: Future Use */
    VehicleCurveYawQuality += VDY_FIVE_CENT;
  }
#else
  VehicleCurveYawQuality += VDY_FIVE_CENT;
#endif

}
/* <ln_offset:-1 MISRA Rule 16.7: reviewer name: Jochen Spruck date: 27-09-2010 reason: proPorts could not be declared as const because of compiler switches  */


/* **********************************************************************
	Unit Design for vdyInitVehDyn is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyInitVehDyn(VehDyn_t *VehDyn)
{
  /* clear everything including alignment bytes */
  (void)vdy_memset_s(VehDyn, 0, sizeof(VehDyn_t));

  /* Set interface version number and default states of vdy output */
  VehDyn->uiVersionNumber = VDY_VEH_DYN_INTFVER;
#if (VDY_VEH_DYN_INTFVER <= 5)
  VehDyn->State[0] = VDY_VEH_DYN_IO_STATE_INIT;
  VehDyn->State[1] = VDY_VEH_DYN_IO_STATE_INIT;
#else
  (void)vdy_memset_s(VehDyn->State, VDY_IO_STATE_INIT, sizeof(VehDyn->State));
#endif

  VehDyn->MotionState.MotState   = VDY_LONG_MOT_STATE_MOVE;
#if (CFG_VDY_MFC)
  RawVelo = VDY_ZERO_F;  //Raw velocity is a provide port for ARS.
#endif
  return;
}


#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_OUTPUT)) || (!CFG_VDY_DIS_YAW_SENSOR_OUTPUT) )
/* **********************************************************************
	Unit Design for vdyInitALNYawRate is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyInitALNYawRate(ALNYawRate_t *ALNYawRate)
{
  ALNYawRate->uiVersionNumber  = VDY_ALN_YAW_RATE_INTFVER;
  ALNYawRate->YawRate          = 0.F;
  ALNYawRate->Quality          = 0.F;
  ALNYawRate->bSenYawRateState = FALSE;
  ALNYawRate->OffsetCompState  = ALN_YAW_RATE_NO_EEPROM;
}
#endif


/* **********************************************************************
	Unit Design for vdyInitOffsets is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyInitOffsets(VDYOffsets_t *VDYOffsets)
{
  VDYOffsets->uiVersionNumber = VDY_OFFSETS_INTFVER;

  VDYOffsets->Ay.Offset   = VDY_ZERO_F;
  VDYOffsets->Ay.State    = VDY_ZERO;
  VDYOffsets->Ay.Variance = VDY_ZERO_F;

  VDYOffsets->Swa.Offset   = VDY_ZERO_F;
  VDYOffsets->Swa.State    = VDY_ZERO;
  VDYOffsets->Swa.Variance = VDY_ZERO_F;

  VDYOffsets->Ywr.DynOffset        = VDY_ZERO_F;
  VDYOffsets->Ywr.DynVariance      = VDY_ZERO_F;
  VDYOffsets->Ywr.StandStillOffset = VDY_ZERO_F;
  VDYOffsets->Ywr.StandStillState  = VDY_ZERO;
}


/* **********************************************************************
	Unit Design for vdyInitErrors is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyInitErrors(VDYErrors_t *VDYErrors)
{
  /* set version number */
  VDYErrors->uiVersionNumber = VDY_ERRORS_INTFVER;

  /* Initialize input signal error states */
  VDYErrors->SignalInputErrors.InputSignalError     = VDY_ERR_STATE_UNKNOWN;
  VDYErrors->SignalInputErrors.InputSignalPeakError = VDY_ERR_STATE_UNKNOWN;

  /* Initialize input parameter error states */
  VDYErrors->ParInputErrors.InputParameterError   = VDY_ERR_STATE_UNKNOWN;

  /* Initialize output error states */
  VDYErrors->OutPutErrors.YwrOffsRg        = VDY_ERR_STATE_UNKNOWN;
  VDYErrors->OutPutErrors.SwaOffsRg        = VDY_ERR_STATE_UNKNOWN;
  VDYErrors->OutPutErrors.AyOffsRg         = VDY_ERR_STATE_UNKNOWN;
  VDYErrors->OutPutErrors.VelCorrRg        = VDY_ERR_STATE_UNKNOWN;
  VDYErrors->OutPutErrors.NVMYwrOffsRg     = VDY_ERR_STATE_UNKNOWN;
  VDYErrors->OutPutErrors.NVMSwaOffsRg     = VDY_ERR_STATE_UNKNOWN;
  VDYErrors->OutPutErrors.NVMAyOffsRg      = VDY_ERR_STATE_UNKNOWN;
  VDYErrors->OutPutErrors.NVMVelCorrRg     = VDY_ERR_STATE_UNKNOWN;
#if ( (defined(CFG_VDY_NVM_LEARN_DATA_ERROR)) && (CFG_VDY_NVM_LEARN_DATA_ERROR) )
  /* check for valid values written into NVM */
  VDYErrors->OutPutErrors.YwrNVMOffsRg     = VDY_ERR_STATE_UNKNOWN;
  VDYErrors->OutPutErrors.SwaNVMOffsRg     = VDY_ERR_STATE_UNKNOWN;
  VDYErrors->OutPutErrors.AyNVMOffsRg      = VDY_ERR_STATE_UNKNOWN;
  VDYErrors->OutPutErrors.SSGNVMOffsRg     = VDY_ERR_STATE_UNKNOWN;
  VDYErrors->OutPutErrors.WLDNVMOffsRg     = VDY_ERR_STATE_UNKNOWN;
#endif
  VDYErrors->OutPutErrors.VelCorrWin       = VDY_ERR_STATE_UNKNOWN;
  VDYErrors->OutPutErrors.VelMon           = VDY_ERR_STATE_UNKNOWN;
  VDYErrors->OutPutErrors.VelMonLt         = VDY_ERR_STATE_UNKNOWN;
  VDYErrors->OutPutErrors.VelocityErr      = VDY_ERR_STATE_UNKNOWN;
  VDYErrors->OutPutErrors.YawRateErr       = VDY_ERR_STATE_UNKNOWN;
  VDYErrors->OutPutErrors.YwrMonVehHalt    = VDY_ERR_STATE_UNKNOWN;
  VDYErrors->OutPutErrors.YwrMonVehDOff    = VDY_ERR_STATE_UNKNOWN;
  VDYErrors->OutPutErrors.YwrMonAdmWdrwl   = VDY_ERR_STATE_UNKNOWN;
  VDYErrors->OutPutErrors.YwrACCMonAlignm  = VDY_ERR_STATE_UNKNOWN;
  VDYErrors->OutPutErrors.YwrCGMonAlignm   = VDY_ERR_STATE_UNKNOWN;
  VDYErrors->OutPutErrors.YwrMonVehHaltCal = VDY_ERR_STATE_UNKNOWN;
  VDYErrors->OutPutErrors.VDY_FS_YR_VS_AY  = VDY_ERR_STATE_UNKNOWN;
  VDYErrors->OutPutErrors.VDY_FS_YR_VS_SWA = VDY_ERR_STATE_UNKNOWN;
  VDYErrors->OutPutErrors.VDY_FS_YR_VS_WSP = VDY_ERR_STATE_UNKNOWN;
  VDYErrors->OutPutErrors.VDY_VEH_YWR_NOT_AVAILABLE= VDY_ERR_STATE_UNKNOWN;
  VDYErrors->OutPutErrors.VDY_VEH_VEL_NOT_AVAILABLE= VDY_ERR_STATE_UNKNOWN;
  VDYErrors->OutPutErrors.VDY_FS_VEH_CORR_MON = VDY_ERR_STATE_UNKNOWN;
}


/* **********************************************************************
	Unit Design for vdyInitInternal is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyInitInternal(VDYInternalData_t *intData)
{
  (void)vdy_memset_s(intData, 0x00, sizeof(VDYInternalData_t));
  intData->vdy_velcor.VelCorrFact = VDY_ONE_F;

}


/* **********************************************************************
	Unit Design for vdyInitProcess is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyInitProcess( const reqVdyPrtList_t *reqPorts, const VDYInputData_t *input, const proVdyPrtList_t *proPorts)
{
#if (!(CFG_VDY_YWR_OFFSET_MONITOR))
  (void)input;  /* remove compiler warning, input is not used in this configuration */
#endif

#if ( (defined(CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING)) && (CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING) )
  (void)reqPorts;  /* remove compiler warning, reqPorts is not used in this configuration */
#endif

  /* Clear first cycle execution completed flag */
  VDY_RESET_FIRST_CYCLE_DONE;

#if (CFG_VDY_INT_GYRO)  
  VDYYwrtInit( proPorts );
#endif

#if ( (!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING) )
  /* Initialize yaw rate sensor module */
  vdyWhsInit();
#endif

#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING) )
  /* Initialize yaw rate sensor module */
  vdyYwrInit(reqPorts ,proPorts);
#endif

#if (CFG_VDY_YWR_OFFSET_MONITOR)
  /* Initialize yaw rate sensor offset monitoring */
  vdyYwrMonInit(input, &VDYModIf, proPorts->pVDYErrors);
#endif


#if ( ( (!defined(CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING) ) || ( (!defined(CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING) ) )
  /* Initialize steering wheel angle sensor module */
  vdyAySwaInit(reqPorts , proPorts);
#endif

#if ( (defined(CFG_VDY_DO_VELOCITY_CORR)) && (CFG_VDY_DO_VELOCITY_CORR) )
  /* Initialize velocity correction */
  VDYVelCorrInit(proPorts);
#endif

  /* Initialize velocity monitoring */
#if (CFG_VDY_USE_VELO_MONITOR)
  vdyVelMonInit( proPorts->pVDYErrors);
#endif

  /* Functional savety monitoring functions */
#if !(defined(CFG_VDY_DIS_FUNCTIONAL_SAFETY_MON) && (CFG_VDY_DIS_FUNCTIONAL_SAFETY_MON))
  vdyFSInit();
#endif

  /* Module Interface */
  vdyInitModuleIf(&VDYModIf);
  vdyInitInternal(&vdy_internal_data);

  /* Auto code */

#if ((!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING))
  /* Initialize vdy_wpp model */
  vdy_wpp_initialize((boolean_T) 1, &vdy_wpp_B, &vdy_wpp_DWork);

  /* Initialize vdy_ve model */
  vdy_ve_initialize((boolean_T) 1,&vdy_ve_B, &vdy_ve_DWork);  

 /* Initialize vdy_wye model */
  vdy_wye_initialize((boolean_T) 1, &vdy_wye_B, &vdy_wye_DWork);
#endif

#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING) )
  /* Initialize vdy_gye model */
  vdy_gye_initialize((boolean_T) 1, &vdy_gye_B, &vdy_gye_DWork);

#if (!CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING)
  /* Initialize vdy_gye_filt model */
  vdy_gye_initialize((boolean_T) 1, &vdy_gye_B_FILT, &vdy_gye_DWork_FILT);
  LastFiltered = VDY_ZERO_F;      /* Last filtered dyn yaw rate offset */
  OldFiltYawOffset = VDY_ZERO_F;  /* Filter delay for yaw rate offset */
#endif

#endif

#if ((!defined(CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING))
  /* Initialize vdy_ay model */
  vdy_aye_initialize((boolean_T) 1, &vdy_aye_B, &vdy_aye_DWork);  
#endif

#if ((!defined(CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING))
  /* Initialize vdy_sye model */
  vdy_sye_initialize((boolean_T) 1, &vdy_sye_B, &vdy_sye_DWork);
#endif

#if ( (!defined(CFG_VDY_USE_EXT_PROC_YAW_RATE)) || (!CFG_VDY_USE_EXT_PROC_YAW_RATE) )
  /* Initialize vdy_ve model */
  vdy_ye_initialize((boolean_T) 1, &vdy_ye_B, &vdy_ye_DWork);
#endif

#if ((!defined(CFG_VDY_DIS_SIDE_SLIP_ANGLE_ESTIMATION)) || (!CFG_VDY_DIS_SIDE_SLIP_ANGLE_ESTIMATION))
  /* Initialize vdy_sae model */
  vdy_sae_initialize((boolean_T) 1, &vdy_sae_B, &vdy_sae_DWork);
#endif

#if (CFG_VDY_MOT_STATE)
  /* Initialize vdy_mot_st model */
  vdy_mot_st_initialize((boolean_T) 1, &vdy_mot_st_B, &vdy_mot_st_DWork);
#endif

  vdy_internal_data.vdy_offsets_in.vdy_swa_offset.offset = VDY_ZERO_F;
  vdy_internal_data.vdy_offsets_in.vdy_swa_offset.state = 1U;
  vdy_internal_data.vdy_offsets_in.vdy_swa_offset.var   = VDY_ONE_NE_FIVE;


  vdy_internal_data.vdy_offsets_in.vdy_yaw_offset.offset = VDY_ZERO_F;
  vdy_internal_data.vdy_offsets_in.vdy_yaw_offset.state = 1U;
  vdy_internal_data.vdy_offsets_in.vdy_yaw_offset.var   = VDY_ONE_NE_NINE;
  
#if ( (!defined(CFG_VDY_DIS_YWR_OFFSET_COMP)) || (!CFG_VDY_DIS_YWR_OFFSET_COMP) )
  /* init external yaw rate offset state */
  VDYOutYwrOffsType = (VDYOutYwrOffsType_t)OUT_YWR_OFFS_NON;
#endif
  
  vdy_internal_data.vdy_offsets_in.vdy_ay_offset.offset = VDY_ZERO_F;
  vdy_internal_data.vdy_offsets_in.vdy_ay_offset.state = 1U;
  vdy_internal_data.vdy_offsets_in.vdy_ay_offset.var   = VDY_TWENTY_CENT;

  vdy_internal_data.vdy_offsets_in.vdy_whs_offset.offset_ratio_front     = VDY_ONE_F;
  vdy_internal_data.vdy_offsets_in.vdy_whs_offset.offset_ratio_front_dev = VDY_ONE_F;
  vdy_internal_data.vdy_offsets_in.vdy_whs_offset.offset_ratio_rear      = VDY_ONE_F;
  vdy_internal_data.vdy_offsets_in.vdy_whs_offset.offset_ratio_rear_dev  = VDY_ONE_F;
  vdy_internal_data.vdy_offsets_in.vdy_whs_offset.SpeedRange             = 0;

#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_OUTPUT)) || (!CFG_VDY_DIS_YAW_SENSOR_OUTPUT) )
  /* Initalize alignment yaw rate */
  vdyInitALNYawRate(proPorts->pALNYawRate);
#endif

  /* Initialize offsets */
  vdyInitOffsets(proPorts->pVDYOffsets);

  /* Initialize error states */
  vdyInitErrors(proPorts->pVDYErrors);

  /* Init monitoring */
  vdyInitMon();

  return;
}


/* **********************************************************************
	Unit Design for vdyReinitYawRate is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyReinitYawRate(void)
{
  vdy_ye_initialize((boolean_T) 1, &vdy_ye_B, &vdy_ye_DWork);
  vdy_ye_k.u_CurveFaultCounter = 0U;
  vdy_ye_k.u_YawFaultCounter = 0U;
  vdy_ye_k.u_DICurveFaultCounter = 0U;
}


/* **********************************************************************
	Unit Design for vdyIsFirstCycleDone is found in Declaration Section
**************************************************************************** */
boolean vdyIsFirstCycleDone(void)
{
  return(VDY_IS_FIRST_CYCLE_DONE);
}


/* **********************************************************************
	Unit Design for vdyGetCycleTime is found in Declaration Section
**************************************************************************** */
fTime_t vdyGetCycleTime(void)
{
  return(VDY_GET_CYCLE_TIME);
}


/* **********************************************************************
	Unit Design for vdyInitModuleIf is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyInitModuleIf(VDYModIf_t *mif)
{
  mif->LongMot.MotState.MotState    = VDY_LONG_MOT_STATE_MOVE_FWD;
#if(CFG_VDY_MFC)
  mif->LongMot.MotState.Confidence  = VDY_ZERO_F;
#else
  mif->LongMot.MotState.Confidence  = VDY_ZERO_U;
#endif

  mif->LongMot.VehVelocityCorr      = VDY_ZERO_F;
  mif->LongMot.VehVelo              = VDY_ZERO_F;
  mif->LongMot.VehAccel             = VDY_ZERO_F;
  mif->LongMot.VehAccelVar          = VDY_ZERO_F;
  mif->LongMot.VehVeloVar           = VDY_ZERO_F;

  mif->SideSlipAngle.SideSlipAngle  = VDY_ZERO_F;
  mif->SideSlipAngle.Variance       = VDY_ZERO_F;

  mif->Curve.Curve                  = VDY_ZERO_F;
  mif->Curve.VarCurve               = VDY_ZERO_F;
  mif->CurveInt.C1                  = VDY_ZERO_F;
  mif->CurveInt.varC1               = VDY_ZERO_F;
  mif->CurveInt.Gradient            = VDY_ZERO_F;
  mif->CurveInt.Quality             = VDY_ZERO_F;
  
  mif->YawRate.YawRate              = VDY_ZERO_F;
  mif->YawRate.Variance             = VDY_ZERO_F;

  mif->LongMot.FLWhlVelo            = VDY_ONE_F;
  mif->LongMot.FRWhlVelo            = VDY_ONE_F;
  mif->LongMot.RLWhlVelo            = VDY_ONE_F;
  mif->LongMot.RRWhlVelo            = VDY_ONE_F;
  mif->LongMot.VelCorrFact          = VDY_ONE_F;

  mif->LatAcc.LatAccel              = VDY_ZERO_F;
  mif->LatAcc.Variance              = VDY_ZERO_F;

  mif->YwrOffset.offset             = VDY_ZERO_F;
  mif->YwrOffset.var                = VDY_ZERO_F;

  mif->AyOffset.offset              = VDY_ZERO_F;
  mif->AyOffset.var                 = VDY_ZERO_F;
  mif->AyOffset.state               = 0U;

  mif->SwaOffset.offset             = VDY_ZERO_F;
  mif->SwaOffset.state              = 0U;
  mif->SwaOffset.var                = VDY_ZERO_F;

  return;
}


/* **********************************************************************
	Unit Design for vdyInterfaceHand2Auto is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyInterfaceHand2Auto(const VDYInputData_t * input, VDYInternalData_t *IntData, const VDYModIf_t *mif)
{
#if ((CFG_VDY_DIS_SWA_OFFSET_COMP) && (CFG_VDY_DIS_LAT_OFFSET_COMP))
  (void)mif;  /* remove compiler warning, mif is not used in this configuration */
#endif

  /*<----- Steering wheel angle offset  ----->*/
#if (CFG_VDY_DIS_SWA_OFFSET_COMP)
  /* input signal is already compensated, there is no zero point offset */
  IntData->vdy_offsets_in.vdy_swa_offset.state  = 3U;
  IntData->vdy_offsets_in.vdy_swa_offset.offset = 0.F;
  IntData->vdy_offsets_in.vdy_swa_offset.var    = 0.00001F;
#else
  { /*<----- Pass steering wheel angle offset  ----->*/
    /* Transfer steering wheel offset to auto code */
    IntData->vdy_offsets_in.vdy_swa_offset      = mif->SwaOffset;
    IntData->vdy_offsets_in.vdy_swa_offset.var  = VDY_ONE_NE_FIVE;
  }
#endif

  /*<----- Yaw rate offset  ----->*/
#if (CFG_VDY_DIS_YWR_OFFSET_COMP)
  /* input signal is already compensated, there is no zero point offset */
  IntData->vdy_offsets_in.vdy_yaw_offset.offset  = 0.F; 
  IntData->vdy_offsets_in.vdy_yaw_offset.var     = 0.000000001F;
  IntData->vdy_offsets_in.vdy_yaw_offset.state   = 1U;
  IntData->vdy_offsets_in.vdy_yaw_offset.quality = 1.5F;
  (void)input; /* remove compiler warning, input is not used in certain configurations */
#else
  /*<----- Pass yaw rate offset  ----->*/
  {
    const ToAutocode_t * ToAutocode;
#if (CFG_VDY_INT_GYRO)
    /* if external yaw rate signal is valid use the external yaw rate signal otherwise the internal */
    /* <ln_offset:+2 PCLINT Error 845: reviewer name: Jochen Spruck date: 4-05-2011 reason: proven in use, error because mask value is zero */
    /* <ln_offset:+1 PCLINT Error 835: reviewer name: Jochen Spruck date: 4-05-2011 reason: proven in use, error because mask value is zero */
    if (VDY_GET_IO_STATE(VDY_SIN_POS_YWR, input->Signals.State) == VDY_IO_STATE_VALID)
    {
      const VDYYwrOffsData_t *pYwrOffs = vdyYwrGetOffsData();
      ToAutocode = &pYwrOffs->ToAutocode;
    }
    else
    {
      const VDYYwrtOffsData_t *pYwrOffs = VDYYwrtGetOffsData();
      ToAutocode = &pYwrOffs->ToAutocode;
    }
#else
    const VDYYwrOffsData_t *pYwrOffs = vdyYwrGetOffsData();
    (void)input; /* remove compiler warning */
    /* Copy the ToAutocode struct from the external stand still yaw rate offset module */
    ToAutocode = &pYwrOffs->ToAutocode;
#endif
    /* Monitor the Dynamic yaw rate offset signal */
    vdyMonitorDynYwrOffset(ToAutocode, IntData);
  }
#endif

  /*<----- Wheel Speed offset  ----->*/
#if (CFG_VDY_DIS_WHS_OFFSET_COMP)
  /* input signal has been already compensated, there is no zero point offset */
  IntData->vdy_offsets_in.vdy_whs_offset.offset_ratio_front      = 1.0F;
  IntData->vdy_offsets_in.vdy_whs_offset.offset_ratio_front_dev  = 1E-6F;

  IntData->vdy_offsets_in.vdy_whs_offset.offset_ratio_rear       = 1.0F;
  IntData->vdy_offsets_in.vdy_whs_offset.offset_ratio_rear_dev   = 1E-6F;
  
  IntData->vdy_offsets_in.vdy_whs_offset.SpeedRange              = 0;

#else
  /*<----- Pass wheel speed offsets  ----->*/
  /* Get the wheel speed offset from the whs modul */
  IntData->vdy_offsets_in.vdy_whs_offset = vdyWhsOffset();
#endif

  /*<----- Lateral acceleration offset ----->*/
#if (CFG_VDY_DIS_LAT_OFFSET_COMP)
  /* input signal has been already compensated, there is no zero point offset */
  IntData->vdy_offsets_in.vdy_ay_offset.state  = 3U;
  IntData->vdy_offsets_in.vdy_ay_offset.offset = 0.F;
  IntData->vdy_offsets_in.vdy_ay_offset.var    = 0.00001F;
#else
  /*<----- Pass lateral acceleration offset  ----->*/
  /* Transfer steering wheel offset to auto code */
  IntData->vdy_offsets_in.vdy_ay_offset = mif->AyOffset;
#endif

  return;
}


/* **********************************************************************
	Unit Design for vdyInterfaceAuto2Hand is found in Declaration Section
**************************************************************************** */
#if (CFG_VDY_GEN_VELOCITY_VARIANCE)
STATIC_MTD void vdyInterfaceAuto2Hand(VDYInternalData_t *IntData, VDYModIf_t *mif)
#else
STATIC_MTD void vdyInterfaceAuto2Hand(const VDYInternalData_t *IntData, VDYModIf_t *mif)
#endif
{
  /* if velocity variance should be generated from acceleration */
#if (CFG_VDY_GEN_VELOCITY_VARIANCE)
#if (CFG_VDY_USE_EX_LONG_ACCEL)
  IntData->vdy_ve_out.veh_accel = mif->LongMot.VehAccel;
#endif
  vdyGenVeloVar(IntData);
#endif
  mif->LongMot.VehVeloVar  = IntData->vdy_ve_out.veh_velo_var;

#if (!CFG_VDY_USE_EX_LONG_ACCEL && !CFG_VDY_USE_EX_LONG_VELO)
  mif->LongMot.VehAccel    = IntData->vdy_ve_out.veh_accel;
#endif
  mif->LongMot.VehAccelVar = IntData->vdy_ve_out.veh_accel_var;

#if (!CFG_VDY_DO_VELOCITY_CORR)
  mif->LongMot.VehVelocityCorr = IntData->vdy_ve_out.veh_velo;
#endif

#if (CFG_VDY_MOT_STATE)
  mif->LongMot.MotState.MotState    = IntData->vdy_mot_st_out.mot_state;
#if(CFG_VDY_MFC)
  mif->LongMot.MotState.Confidence  = (float32)IntData->vdy_mot_st_out.mot_quality;
#else
  mif->LongMot.MotState.Confidence  = IntData->vdy_mot_st_out.mot_quality;
#endif
#endif

#if (!CFG_VDY_USE_EXT_PROC_CURVATURE)
  /* if internal curvature estimation is used, copy output data to module interface */
  mif->Curve.Curve    = IntData->vdy_ye_out.veh_merge_curve;
  mif->CurveInt.C1       = VDY_ZERO_F;
  mif->CurveInt.Gradient = IntData->vdy_ye_out.veh_merge_curve_grad;
  mif->Curve.VarCurve    = IntData->vdy_ye_out.veh_merge_curve_var;
  mif->CurveInt.varC1    = VDY_ZERO_F;
  mif->CurveInt.Quality  = VDY_ZERO_F;
#endif

#if (!CFG_VDY_USE_EXT_PROC_YAW_RATE)
  /* if internal yaw rate estimation is used, copy output data to module interface */
  mif->YawRate.YawRate  = vdy_internal_data.vdy_ye_out.veh_yaw_rate;
  mif->YawRate.Variance = vdy_internal_data.vdy_ye_out.veh_yaw_rate_var;
#if (!CFG_VDY_MFC)
  mif->YawRate.YawAngle = vdy_internal_data.vdy_ye_out.veh_yaw_angle;
#endif
#endif

#if (!CFG_VDY_USE_EXT_PROC_SIDE_SLIP_ANGLE)
  mif->SideSlipAngle.SideSlipAngle   = vdy_internal_data.vdy_sae_out.est_slip_angle;
  mif->SideSlipAngle.Variance        = vdy_internal_data.vdy_sae_out.est_slip_angle_var;
#endif

  mif->LongMot.FLWhlVelo    = IntData->vdy_wpp_out.wheel_velo_front_left;
  mif->LongMot.FRWhlVelo    = IntData->vdy_wpp_out.wheel_velo_front_right;
  mif->LongMot.RLWhlVelo    = IntData->vdy_wpp_out.wheel_velo_rear_left;
  mif->LongMot.RRWhlVelo    = IntData->vdy_wpp_out.wheel_velo_rear_right;

  mif->LatAcc.LatAccel      = IntData->vdy_ye_out.veh_lat_accel;
  mif->LatAcc.Variance      = IntData->vdy_ye_out.veh_merge_curve_var  + (VDY_TWO_F * IntData->vdy_ve_out.veh_velo_var);

  /* write the the dynamic yaw rate offset to the module interface */
  mif->YwrOffset.offset     = IntData->vdy_wye_out.gier_yaw_rate_offset;
  mif->YwrOffset.var        = IntData->vdy_wye_out.gier_yaw_rate_offset_var;

#if ((CFG_VDY_MOT_STATE) || (!CFG_VDY_MOT_STATE))
  if((VDYModIf.LongMot.MotState.MotState ==  (MotState_t)VDY_LONG_MOT_STATE_MOVE_RWD) && (VDYModIf.LongMot.VehVelo > VDY_ZERO_F))
  {
    vdy_internal_data.vdy_wye_out.whl_yaw_rate	=	-vdy_internal_data.vdy_wye_out.whl_yaw_rate;
    vdy_internal_data.vdy_sye_out.stw_yaw_rate	=	-vdy_internal_data.vdy_sye_out.stw_yaw_rate;
    vdy_internal_data.vdy_aye_out.ay_yaw_rate	=	-vdy_internal_data.vdy_aye_out.ay_yaw_rate;
  }
#endif

  return;
}


#if ( (!defined(CFG_VDY_DIS_CURVE_OUTPUT)) || (!CFG_VDY_DIS_CURVE_OUTPUT) )
/* **********************************************************************
	Unit Design for vdyYawRate2Curve is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyYawRate2Curve(const VDYInternalData_t *intData, const proVdyPrtList_t *proPorts)
{
  float32 invVelo;

  if (VDYModIf.LongMot.VehVelocityCorr > C_F32_DELTA)
  {
    invVelo = VDY_ONE_F / VDYModIf.LongMot.VehVelocityCorr;
  }
  else
  {
    invVelo = VDY_ZERO_F;
  }

  /* version number */
  proPorts->pVDYEstCurves->uiVersionNumber = VDY_EST_CURVES_INTFVER;

  /* whl speed curve */
  proPorts->pVDYEstCurves->WhlFr.Curve     = intData->vdy_wye_out.front_whl_yaw_rate_filt_wld  * invVelo;

  /* whl speed curve */
  proPorts->pVDYEstCurves->WhlRe.Curve     = intData->vdy_wye_out.rear_whl_yaw_rate_filt  * invVelo;

  /* whl speed curve */
  proPorts->pVDYEstCurves->Whl.Curve       = intData->vdy_wye_out.whl_yaw_rate  * invVelo;

  /* yaw rate curve */
  proPorts->pVDYEstCurves->YwRate.Curve    = intData->vdy_gye_out.gier_yaw_rate * invVelo;
    
  /* lateral acceleration curve */
  proPorts->pVDYEstCurves->Ay.Curve        = intData->vdy_aye_out.ay_yaw_rate   * invVelo;
    
  /* steering wheel angle curve */
  proPorts->pVDYEstCurves->Swa.Curve       = intData->vdy_sye_out.stw_yaw_rate  * invVelo;

  /* vehicle yaw rate curve  */
  proPorts->pVDYEstCurves->VehYaw.Curve    = intData->vdy_ye_out.veh_yaw_rate   * invVelo;

  /* driver intented curve */
  proPorts->pVDYEstCurves->DrvInt.Curve    = intData->vdy_sye_out.stw_curve;

  return;
}
#endif


#if defined(VDY_SIMU)
#if (CFG_VDY_MOT_STATE)
/* **********************************************************************
	Unit Design for vdyGetVDYBayesOut is found in Declaration Section
**************************************************************************** */
vdy_bayes_mot_states_t *vdyGetVDYBayesOut(void)
{
  return (&vdy_bayes_mot_states);
}
#endif


/* **********************************************************************
	Unit Design for vdyGetVDYIntData is found in Declaration Section
**************************************************************************** */
VDYInternalData_t *vdyGetVDYIntData(void)
{
  return (&vdy_internal_data);
}


#if ((!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING))
/* **********************************************************************
	Unit Design for vdyGet_D_Work_vdy_wpp is found in Declaration Section
**************************************************************************** */
D_Work_vdy_wpp *vdyGet_D_Work_vdy_wpp(void)
{
  return (&vdy_wpp_DWork);
}


/* **********************************************************************
	Unit Design for vdyGet_D_Work_vdy_ve is found in Declaration Section
**************************************************************************** */
D_Work_vdy_ve *vdyGet_D_Work_vdy_ve(void)
{
  return (&vdy_ve_DWork);
}


/* **********************************************************************
	Unit Design for vdyGet_D_Work_vdy_wye is found in Declaration Section
**************************************************************************** */
D_Work_vdy_wye *vdyGet_D_Work_vdy_wye(void)
{
  return (&vdy_wye_DWork);
}
#endif


#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING) )
/* **********************************************************************
	Unit Design for vdyGet_D_Work_vdy_gye is found in Declaration Section
**************************************************************************** */
D_Work_vdy_gye *vdyGet_D_Work_vdy_gye(void)
{
  return (&vdy_gye_DWork);
}
#endif


#if (!CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING)
/* **********************************************************************
	Unit Design for vdyGet_D_Work_vdy_gye_filt is found in Declaration Section
**************************************************************************** */
D_Work_vdy_gye *vdyGet_D_Work_vdy_gye_filt(void)
{
  return (&vdy_gye_DWork_FILT);
}
#endif


#if ((!defined(CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING))
/* **********************************************************************
	Unit Design for vdyGet_D_Work_vdy_aye is found in Declaration Section
**************************************************************************** */
D_Work_vdy_aye *vdyGet_D_Work_vdy_aye(void)
{
  return (&vdy_aye_DWork);
}
#endif


#if ((!defined(CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING))
/* **********************************************************************
	Unit Design for vdyGet_D_Work_vdy_sye is found in Declaration Section
**************************************************************************** */
D_Work_vdy_sye *vdyGet_D_Work_vdy_sye(void)
{
  return (&vdy_sye_DWork);
}
#endif


#if ( (!defined(CFG_VDY_USE_EXT_PROC_YAW_RATE)) || (!CFG_VDY_USE_EXT_PROC_YAW_RATE) )
/* **********************************************************************
	Unit Design for vdyGet_D_Work_vdy_ye is found in Declaration Section
**************************************************************************** */
D_Work_vdy_ye *vdyGet_D_Work_vdy_ye(void)
{
  return (&vdy_ye_DWork);
}
#endif


#if ((!defined(CFG_VDY_DIS_SIDE_SLIP_ANGLE_ESTIMATION)) || (!CFG_VDY_DIS_SIDE_SLIP_ANGLE_ESTIMATION))
/* **********************************************************************
	Unit Design for vdyGet_D_Work_vdy_sae is found in Declaration Section
**************************************************************************** */
D_Work_vdy_sae *vdyGet_D_Work_vdy_sae(void)
{
  return (&vdy_sae_DWork);
}
#endif


#if (CFG_VDY_MOT_STATE)
/* **********************************************************************
	Unit Design for vdyGet_D_Work_vdy_mot_st is found in Declaration Section
**************************************************************************** */
D_Work_vdy_mot_st *vdyGet_D_Work_vdy_mot_st(void)
{
  return (&vdy_mot_st_DWork);
}
#endif


/* **********************************************************************
	Unit Design for vdyGetModulIf is found in Declaration Section
**************************************************************************** */
VDYModIf_t *vdyGetModulIf(void)
{
  return(&VDYModIf);
}


/* **********************************************************************
	Unit Design for vdySetSequenceInitState is found in Declaration Section
**************************************************************************** */
void vdySetSequenceInitState( VDYSequenceInitStates_t _sSequenceInitState )
{
  /* Set the sequence init state to the local variable */
  sSequenceInitState = _sSequenceInitState;
}

#endif


#if ( defined(VDY_FREEZE_INIT_SEQUENCE) && (VDY_FREEZE_INIT_SEQUENCE) )
/// Temporary buffer size
#define TempBufferSize 600U

/// Header Size
#define HeaderSize     16U
/* **********************************************************************
	Unit Design for vdyInitSequenceMeasFreeze is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyInitSequenceMeasFreeze(const AS_t_ServiceFuncts * services)
{
  static uint8  VDYInitSeqence[TempBufferSize];
  uint32 nSize = 0U;
  uint32 nRawSize = 0U;
  uint32 nPos = 0U;

//  (void)services;  /* to remove compiler warning, service function is not used in all configurations */

  switch (InitPackageID)
  {
    case 0U:
#if ( (!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING) )
      /* the raw size of the data package without the header(id+size)*/
      nRawSize = sizeof(vdy_wpp_DWork);
	  /* PRQA S 2991 EOF */
	  /* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: No Risk */
      if (nRawSize < (uint32)(TempBufferSize-HeaderSize))
      {
        /* <ln_offset:-1 PCLINT Error 774: reviewer name: Jochen Spruck date: 27-09-2010 reason: size check at runtime */
        /* Copy data of sequence InitPackageID */
        (void)vdy_memcpy_s(VDYInitSeqence,&InitPackageID,sizeof(InitPackageID));
        nPos = nPos + (uint32)sizeof(InitPackageID);
        (void)vdy_memcpy_s(&VDYInitSeqence[nPos],&nRawSize,sizeof(nRawSize));
        nPos = nPos + (uint32)sizeof(nRawSize);
        (void)vdy_memcpy_s(&VDYInitSeqence[nPos], &vdy_wpp_DWork, sizeof(vdy_wpp_DWork));
        nPos = nPos + (uint32)sizeof(vdy_wpp_DWork);

        /* Set up the total size of init package */
        nSize = nPos;
        /* Freeze the sequence init package */
        MEAS_FREEZE_DIRECT(VDY_MEAS_ID_INIT_SEQ, VDYInitSeqence, nSize); /* MISRA Rule 11.4: reviewer name: Jochen Spruck date: 27-09-2010 reason: proven in use, meas freeze macro  */
        /* <ln_offset:-1 PCLINT Error 717: reviewer name: Jochen Spruck date: 27-09-2010 reason: proven in use, meas freeze macro  */
      }
      else
      {
        /* set error */
      }
#endif
      InitPackageID++;
      break;

    case 1U:
#if ( (!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING) )
      /* the raw size of the data package without the header(id+size)*/
      nRawSize = sizeof(vdy_ve_DWork);
      if (nRawSize < (uint32)(TempBufferSize-HeaderSize))
      {
        /* <ln_offset:-1 PCLINT Error 774: reviewer name: Jochen Spruck date: 27-09-2010 reason: size check at runtime */
        /* Copy data of sequence InitPackageID */
        (void)vdy_memcpy_s(VDYInitSeqence,&InitPackageID,sizeof(InitPackageID));
        nPos = nPos + (uint32)sizeof(InitPackageID);
        (void)vdy_memcpy_s(&VDYInitSeqence[nPos],&nRawSize,sizeof(nRawSize));
        nPos = nPos + (uint32)sizeof(nRawSize);
        (void)vdy_memcpy_s(&VDYInitSeqence[nPos], &vdy_ve_DWork, sizeof(vdy_ve_DWork));
        nPos = nPos + (uint32)sizeof(vdy_ve_DWork);

        /* Set up the total size of init package */
        nSize = nPos;
        /* Freeze the sequence init package */
        MEAS_FREEZE_DIRECT(VDY_MEAS_ID_INIT_SEQ, VDYInitSeqence, nSize); /* MISRA Rule 11.4: reviewer name: Jochen Spruck date: 27-09-2010 reason: proven in use, meas freeze macro  */
        /* <ln_offset:-1 PCLINT Error 717: reviewer name: Jochen Spruck date: 27-09-2010 reason: proven in use, meas freeze macro  */
      }
      else
      {
        /* set error */
      }
#endif
      InitPackageID++;
      break;

    case VDY_TWO_U:
#if ( (!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING) )
      /* the raw size of the data package without the header(id+size)*/
      nRawSize = sizeof(vdy_wye_DWork);
      if (nRawSize < (uint32)(TempBufferSize-HeaderSize))
      {
        /* <ln_offset:-1 PCLINT Error 774: reviewer name: Jochen Spruck date: 27-09-2010 reason: size check at runtime */
        /* Copy data of sequence InitPackageID */
        (void)vdy_memcpy_s(VDYInitSeqence,&InitPackageID,sizeof(InitPackageID));
        nPos = nPos + (uint32)sizeof(InitPackageID);
        (void)vdy_memcpy_s(&VDYInitSeqence[nPos],&nRawSize,sizeof(nRawSize));
        nPos = nPos + (uint32)sizeof(nRawSize);
        (void)vdy_memcpy_s(&VDYInitSeqence[nPos], &vdy_wye_DWork, sizeof(vdy_wye_DWork));
        nPos = nPos + (uint32)sizeof(vdy_wye_DWork);

        /* Set up the total size of init package */
        nSize = nPos;
        /* Freeze the sequence init package */
        MEAS_FREEZE_DIRECT(VDY_MEAS_ID_INIT_SEQ, VDYInitSeqence, nSize); /* MISRA Rule 11.4: reviewer name: Jochen Spruck date: 27.09.2010 reason: proven in use, meas freeze macro  */
        /* <ln_offset:-1 PCLINT Error 717: reviewer name: Jochen Spruck date: 27-09-2010 reason: proven in use, meas freeze macro  */
      }
      else
      {
        /* set error */
      }
#endif
      InitPackageID++;
      break;

    case VDY_THREE_U:
#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING) )
      /* the raw size of the data package without the header(id+size)*/
      nRawSize = (uint32)sizeof(vdy_gye_DWork);
#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING)) || (!CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING) )
      nRawSize = nRawSize + (uint32)sizeof(vdy_gye_DWork_FILT);
#endif
      if (nRawSize < (uint32)(TempBufferSize-HeaderSize))
      {
        /* <ln_offset:-1 PCLINT Error 774: reviewer name: Jochen Spruck date: 27-09-2010 reason: size check at runtime */
        /* Copy data of sequence InitPackageID */
        (void)vdy_memcpy_s(VDYInitSeqence,&InitPackageID,sizeof(InitPackageID));
        nPos = nPos + (uint32)sizeof(InitPackageID);
        (void)vdy_memcpy_s(&VDYInitSeqence[nPos],&nRawSize,sizeof(nRawSize));
        nPos = nPos + (uint32)sizeof(nRawSize);
        (void)vdy_memcpy_s(&VDYInitSeqence[nPos], &vdy_gye_DWork, sizeof(vdy_gye_DWork));
        nPos = nPos + (uint32)sizeof(vdy_gye_DWork);
#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING)) || (!CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING) )
        (void)vdy_memcpy_s(&VDYInitSeqence[nPos], &vdy_gye_DWork_FILT, sizeof(vdy_gye_DWork_FILT));
        nPos = nPos + (uint32)sizeof(vdy_gye_DWork_FILT);
#endif

        /* Set up the total size of init package */
        nSize = nPos;

        /* Freeze the sequence init package if package size is smaller than buffer*/
        MEAS_FREEZE_DIRECT(VDY_MEAS_ID_INIT_SEQ, VDYInitSeqence, nSize); /* MISRA Rule 11.4: reviewer name: Jochen Spruck date: 27-09-2010 reason: proven in use, meas freeze macro  */
        /* <ln_offset:-1 PCLINT Error 717: reviewer name: Jochen Spruck date: 27-09-2010 reason: proven in use, meas freeze macro  */
      }
      else
      {
        /* set error */
      }
#endif
      InitPackageID++;
      break;

    case VDY_FOUR_U:
#if ( (!defined(CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING) )
      /* the raw size of the data package without the header(id+size)*/
      nRawSize = sizeof(vdy_aye_DWork);
      if (nRawSize < (uint32)(TempBufferSize-HeaderSize))
      {
        /* <ln_offset:-1 PCLINT Error 774: reviewer name: Jochen Spruck date: 27-09-2010 reason: size check at runtime */
        /* Copy data of sequence InitPackageID */
        (void)vdy_memcpy_s(VDYInitSeqence,&InitPackageID,sizeof(InitPackageID));
        nPos = nPos + (uint32)sizeof(InitPackageID);
        (void)vdy_memcpy_s(&VDYInitSeqence[nPos],&nRawSize,sizeof(nRawSize));
        nPos = nPos + (uint32)sizeof(nRawSize);
        (void)vdy_memcpy_s(&VDYInitSeqence[nPos], &vdy_aye_DWork, sizeof(vdy_aye_DWork));
        nPos = nPos + (uint32)sizeof(vdy_aye_DWork);

        /* Set up the total size of init package */
        nSize = nPos;
        /* Freeze the sequence init package */
        MEAS_FREEZE_DIRECT(VDY_MEAS_ID_INIT_SEQ, VDYInitSeqence, nSize); /* MISRA Rule 11.4: reviewer name: Jochen Spruck date: 27-09-2010 reason: proven in use, meas freeze macro  */
        /* <ln_offset:-1 PCLINT Error 717: reviewer name: Jochen Spruck date: 27-09-2010 reason: proven in use, meas freeze macro  */
      }
      else
      {
        /* set error */
      }
#endif
      InitPackageID++;
      break;

    case VDY_FIVE_U:
#if ( (!defined(CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING) )
      /* the raw size of the data package without the header(id+size)*/
      nRawSize = sizeof(vdy_sye_DWork);
      if (nRawSize < (uint32)(TempBufferSize-HeaderSize))
      {
        /* <ln_offset:-1 PCLINT Error 774: reviewer name: Jochen Spruck date: 27-09-2010 reason: size check at runtime */
        /* Copy data of sequence InitPackageID */
        (void)vdy_memcpy_s(VDYInitSeqence,&InitPackageID,sizeof(InitPackageID));
        nPos = nPos + (uint32)sizeof(InitPackageID);
        (void)vdy_memcpy_s(&VDYInitSeqence[nPos],&nRawSize,sizeof(nRawSize));
        nPos = nPos + (uint32)sizeof(nRawSize);
        (void)vdy_memcpy_s(&VDYInitSeqence[nPos], &vdy_sye_DWork, sizeof(vdy_sye_DWork));
        nPos = nPos + (uint32)sizeof(vdy_sye_DWork);

        /* Set up the total size of init package */
        nSize = nPos;
        /* Freeze the sequence init package */
        MEAS_FREEZE_DIRECT(VDY_MEAS_ID_INIT_SEQ, VDYInitSeqence, nSize); /* MISRA Rule 11.4: reviewer name: Jochen Spruck date: 27-09-2010 reason: proven in use, meas freeze macro  */
        /* <ln_offset:-1 PCLINT Error 717: reviewer name: Jochen Spruck date: 27-09-2010 reason: proven in use, meas freeze macro  */
      }
      else
      {
        /* set error */
      }
#endif
      InitPackageID++;
      break;

    case VDY_SIX_U:
#if ( (!defined(CFG_VDY_USE_EXT_PROC_YAW_RATE)) || (!CFG_VDY_USE_EXT_PROC_YAW_RATE) )
      /* the raw size of the data package without the header(id+size)*/
      nRawSize = sizeof(vdy_ye_DWork);
      if (nRawSize < (uint32)(TempBufferSize-HeaderSize))
      {
        /* <ln_offset:-1 PCLINT Error 774: reviewer name: Jochen Spruck date: 27-09-2010 reason: size check at runtime */
        /* Copy data of sequence InitPackageID */
        (void)vdy_memcpy_s(VDYInitSeqence,&InitPackageID,sizeof(InitPackageID));
        nPos = nPos + (uint32)sizeof(InitPackageID);
        (void)vdy_memcpy_s(&VDYInitSeqence[nPos],&nRawSize,sizeof(nRawSize));
        nPos = nPos + (uint32)sizeof(nRawSize);
        (void)vdy_memcpy_s(&VDYInitSeqence[nPos], &vdy_ye_DWork, sizeof(vdy_ye_DWork));
        nPos = nPos + (uint32)sizeof(vdy_ye_DWork);

        /* Set up the total size of init package */
        nSize = nPos;
        /* Freeze the sequence init package */
        MEAS_FREEZE_DIRECT(VDY_MEAS_ID_INIT_SEQ, VDYInitSeqence, nSize); /* MISRA Rule 11.4: reviewer name: Jochen Spruck date: 27-09-2010 reason: proven in use, meas freeze macro  */
        /* <ln_offset:-1 PCLINT Error 717: reviewer name: Jochen Spruck date: 27-09-2010 reason: proven in use, meas freeze macro  */
      }
      else
      {
        /* set error */
      }
#endif
      InitPackageID++;
      break;

    case VDY_SEVEN_U:
#if ( (!defined(CFG_VDY_DIS_SIDE_SLIP_ANGLE_ESTIMATION)) || (!CFG_VDY_DIS_SIDE_SLIP_ANGLE_ESTIMATION) )
      /* the raw size of the data package without the header(id+size)*/
      nRawSize = sizeof(vdy_sae_DWork);
      if (nRawSize < (uint32)(TempBufferSize-HeaderSize))
      {
        /* <ln_offset:-1 PCLINT Error 774: reviewer name: Jochen Spruck date: 27-09-2010 reason: size check at runtime */
        /* Copy data of sequence InitPackageID */
        (void)vdy_memcpy_s(VDYInitSeqence,&InitPackageID,sizeof(InitPackageID));
        nPos = nPos + (uint32)sizeof(InitPackageID);
        (void)vdy_memcpy_s(&VDYInitSeqence[nPos],&nRawSize,sizeof(nRawSize));
        nPos = nPos + (uint32)sizeof(nRawSize);
        (void)vdy_memcpy_s(&VDYInitSeqence[nPos], &vdy_sae_DWork, sizeof(vdy_sae_DWork));
        nPos = nPos + (uint32)sizeof(vdy_sae_DWork);

        /* Set up the total size of init package */
        nSize =nPos;
        /* Freeze the sequence init package */
        MEAS_FREEZE_DIRECT(VDY_MEAS_ID_INIT_SEQ, VDYInitSeqence, nSize); /* MISRA Rule 11.4: reviewer name: Jochen Spruck date: 27-09-2010 reason: proven in use, meas freeze macro  */
        /* <ln_offset:-1 PCLINT Error 717: reviewer name: Jochen Spruck date: 27-09-2010 reason: proven in use, meas freeze macro  */
      }
      else
      {
        /* set error */
      }
#endif
      InitPackageID++;
      break;

    case VDY_EIGHT_U:
#if (CFG_VDY_MOT_STATE)
      /* the raw size of the data package without the header(id+size)*/
      nRawSize = (uint32)sizeof(vdy_mot_st_DWork);
      if (nRawSize < (uint32)(TempBufferSize-HeaderSize))
      {
        /* <ln_offset:-1 PCLINT Error 774: reviewer name: Jochen Spruck date: 27-09-2010 reason: size check at runtime */
        /* Copy data of sequence InitPackageID */
        (void)vdy_memcpy_s(VDYInitSeqence,&InitPackageID,sizeof(InitPackageID));
        nPos = nPos + (uint32)sizeof(InitPackageID);
        (void)vdy_memcpy_s(&VDYInitSeqence[nPos],&nRawSize,sizeof(nRawSize));
        nPos = nPos + (uint32)sizeof(nRawSize);
        (void)vdy_memcpy_s(&VDYInitSeqence[nPos], &vdy_mot_st_DWork, sizeof(vdy_mot_st_DWork));
        nPos = nPos + (uint32)sizeof(vdy_mot_st_DWork);

        /* Set up the total size of init package */
        nSize = nPos;
        /* Freeze the sequence init package */
        MEAS_FREEZE_DIRECT(VDY_MEAS_ID_INIT_SEQ, VDYInitSeqence, nSize); /* MISRA Rule 11.4: reviewer name: Jochen Spruck date: 27-09-2010 reason: proven in use, meas freeze macro  */
        /* <ln_offset:-1 PCLINT Error 717: reviewer name: Jochen Spruck date: 27-09-2010 reason: proven in use, meas freeze macro  */
      }
      else
      {
        /* set error */
      }
#endif
      InitPackageID++;
      break;

	case VDY_FOURTEEN_U:
		InitPackageID = 0U;
		break;

    case VDY_NINE_U:   /* fallthrough: same as default */
    case VDY_TEN_U:  /* fallthrough: same as default */
    case VDY_ELEVEN_U:  /* fallthrough: same as default */
    case VDY_TWELVE_U:  /* fallthrough: same as default */
    case VDY_THIRTEEN_U:  /* fallthrough: same as default */
    default:
      InitPackageID++;
      break;

  }
}
#endif


#if ( defined(CFG_VDY_USE_ALGOCOMPSTATE) && (CFG_VDY_USE_ALGOCOMPSTATE) && (!CFG_VDY_MFC) )
/* **********************************************************************
	Unit Design for vdySetCompState is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdySetCompState(const VDYInputData_t  VDYIn, const proVdyPrtList_t * proPorts)
{
  /* set state information for scheduler */
  proPorts->pVdyCompState->uiAlgoVersionNumber = COMP_STATE_INTFVER;
  proPorts->pVdyCompState->uiAlgoVersionNumber = VDY_SW_VERSION_NUMBER;
  proPorts->pVdyCompState->ApplicationNumber = 0u;
  proPorts->pVdyCompState->AlgoVersionInfo[0] = 0u; 
  proPorts->pVdyCompState->eShedulerModeRequest = COMP_MODE_REQ_NONE;

  switch (VDYIn.Frame.CtrlMode)
  {
    case VDY_CTRL_STATE_INIT:     /* fallthrough */
    case VDY_CTRL_STATE_STARTUP:  /* fallthrough */
    case VDY_CTRL_STATE_RUNNING:  /* fallthrough */
      /* Check if a fault condition is set */
      if (proPorts->pVehicleDynamicSignals->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
      {
        /* Set CompState to fault mode */
        proPorts->pVdyCompState->eCompState = COMP_STATE_TEMPORARY_ERROR;
        proPorts->pVdyCompState->eErrorCode = COMP_ERROR_UNKNOWN;
        proPorts->pVdyCompState->eGenAlgoQualifier = ALGO_QUAL_CRITICAL_INPUT_ERROR;
      }
      else
      {
        /* Set CompState to normal operation mode */
        proPorts->pVdyCompState->eCompState = COMP_STATE_RUNNING;
        proPorts->pVdyCompState->eErrorCode = COMP_ERROR_NO_ERROR;
        proPorts->pVdyCompState->eGenAlgoQualifier = ALGO_QUAL_OK;
      }
      break;

    default:  /* unspecified operation mode */
      /* Set CompState to undefined operation mode */
      proPorts->pVdyCompState->eCompState = COMP_STATE_TEMPORARY_ERROR;
      proPorts->pVdyCompState->eErrorCode = COMP_ERROR_UNKNOWN;
      proPorts->pVdyCompState->eGenAlgoQualifier = ALGO_QUAL_CRITICAL_INPUT_ERROR;
      break;
  }
}
#endif /* CFG_VDY_USE_ALGOCOMPSTATE */


#ifdef AS_SERVICEFUNC_VERSION
/* **********************************************************************
	Unit Design for vdySetSyncFrame is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdySetSyncFrame(const reqVdyPrtList_t *reqPorts, uint16 CycleCnt, AlgoSignalState_t eVDYSigStatus)
{
#if (CFG_VDY_MFC)
    if (reqPorts->pBaseCtrlData != NULL) 
	{
		s_SyncRef.vdy_SyncRef.sBaseCtrl.sSigHeader           = reqPorts->pBaseCtrlData->sSigHeader;
	}		
    if (reqPorts->pVehicleParameter != NULL) 
	{
		s_SyncRef.vdy_SyncRef.pVehicleParameter              = reqPorts->pVehicleParameter->sSigHeader;
	}		
    if (reqPorts->pVehicleInputSignals != NULL) 
	{
		s_SyncRef.vdy_SyncRef.pVehicleInputSignals           = reqPorts->pVehicleInputSignals->sSigHeader;
	}		
    if (reqPorts->pNVMRead != NULL) 
	{
		s_SyncRef.vdy_SyncRef.pNVMRead                       = reqPorts->pNVMRead->sSigHeader;
	}

		
#else
    s_SyncRef.BSW_s_VDYCtrlData   = reqPorts->pCtrl->sSigHeader;
    s_SyncRef.VehPar              = reqPorts->pVehicleParameter->sSigHeader;
    s_SyncRef.VehSig              = reqPorts->pVehicleInputSignals->sSigHeader;
    s_SyncRef.VDYNVMRead          = reqPorts->pNVMRead->sSigHeader;
#endif

#if ( (defined(CFG_VDY_DO_VELOCITY_CORR)) && (CFG_VDY_DO_VELOCITY_CORR) )
#if ( (defined(VEL_CORR_HIST_STATIONARY_TARGETS)) && (VEL_CORR_HIST_STATIONARY_TARGETS) )
  s_SyncRef.VelStatObj;         = reqPorts->pVelStatObj->sSigHeader;    /* Reference speed histogramm       */
#endif
#if ( (defined(VEL_CORR_ALN)) && (VEL_CORR_ALN) )
  s_SyncRef.ALN_Monitoring      = reqPorts->pAln_Monitoring->sSigHeader;     /* Velocity information from ALN    */
#endif
#endif
#if ( (defined(CFG_VDY_ROLLBENCH_DETECTION)) && (CFG_VDY_ROLLBENCH_DETECTION) )
  s_SyncRef.EM_RTBRecognition   = reqPorts->pRTBRecognition->sSigHeader;     /* Roll Bench detection information    */
#endif
#if ( (defined(CFG_VDY_64BIT_TIMESTAMP_INTERV)) && (CFG_VDY_64BIT_TIMESTAMP_INTERV) )
  s_SyncRef.VDYLongLongTimeStamp = reqPorts->pLongLongTimeStamp->sSigHeader;;
#endif
  
  /* ------------------ freeze --------------- */
  #if (CFG_VDY_MFC)
  s_SyncRef.vdy_SyncRef.sSigHeader.uiTimeStamp = reqPorts->pVehicleInputSignals->sSigHeader.uiTimeStamp;
  s_SyncRef.vdy_SyncRef.sSigHeader.uiMeasurementCounter = reqPorts->pVehicleInputSignals->sSigHeader.uiMeasurementCounter;
  s_SyncRef.vdy_SyncRef.sSigHeader.eSigStatus = eVDYSigStatus;
  s_SyncRef.vdy_SyncRef.sSigHeader.uiCycleCounter = CycleCnt;
  #else
  s_SyncRef.sSigHeader.uiTimeStamp = reqPorts->pVehicleInputSignals->sSigHeader.uiTimeStamp;
  s_SyncRef.sSigHeader.uiMeasurementCounter = reqPorts->pVehicleInputSignals->sSigHeader.uiMeasurementCounter;
  s_SyncRef.sSigHeader.eSigStatus = eVDYSigStatus;
  s_SyncRef.sSigHeader.uiCycleCounter = CycleCnt;
  #endif
}
#endif


/* **********************************************************************
	Unit Design for vdyCheckPorts is found in Declaration Section
**************************************************************************** */
#ifdef AS_SERVICEFUNC_VERSION
STATIC_MTD uint8 vdyCheckPorts(const reqVdyPrtList_t *reqPorts, const proVdyPrtList_t *proPorts, const AS_t_ServiceFuncts * services)
#else
STATIC_MTD uint8 vdyCheckPorts(const reqVdyPrtList_t *reqPorts, const proVdyPrtList_t *proPorts)
#endif
{
  uint8 ui8Fault = VDY_NO_PORT_FAULT;
    /* Check all ports for NULL pointer */
  /* all request ports */
#if (CFG_VDY_MFC)
  uint8 uiOpData[VDY_THREE];
  uint8 uiOpData1[VDY_THREE];
  {
  uiOpData[0] = FUSI_ERROR_DIR_INPUT;
  uiOpData[1] = FUSI_ERROR_TYPE_NULLPOINTER;
  /* PRQA S 2810 EOF */
  /* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: Functional Safe */
  uiOpData[VDY_TWO] = (uint8)offsetof ( reqVdyPrtList_t, pBaseCtrlData);
  
  if( (NULL == reqPorts) || 
	  (NULL == reqPorts->pBaseCtrlData)				)
  { 
	  uiOpData[VDY_TWO] = (uint8)offsetof(reqVdyPrtList_t, pBaseCtrlData);
	  /* [Requirement - L3D_ALGO_22428 : InputChecks] - set DEM if operation Mode is not Reset and return. */
	  if( reqPorts->pBaseCtrlData->eOpMode != (BaseOpMode_t)BASE_OM_RESET )
		  {
			services->pfDem_SetEventStatus( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED );
			services->pfDem_SetEventStatusPreExtData( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED, (const uint8*)&uiOpData, sizeof(uiOpData) );
		  }
	 ui8Fault = VDY_REQUEST_PORT_FAULT;
  }
  else if( NULL == reqPorts->pNVMRead				) 
  { 
	  uiOpData[VDY_TWO] = (uint8)offsetof ( reqVdyPrtList_t, pNVMRead			   );
	  /* [Requirement - L3D_ALGO_22428 : InputChecks] - set DEM if operation Mode is not Reset and return. */
      if( reqPorts->pBaseCtrlData->eOpMode != (BaseOpMode_t)BASE_OM_RESET )
		  {
			services->pfDem_SetEventStatus( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED );
			services->pfDem_SetEventStatusPreExtData( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED, (const uint8*)&uiOpData, sizeof(uiOpData) );
		  }
	 ui8Fault = VDY_REQUEST_PORT_FAULT;
  }
  else if( NULL == reqPorts->pVehicleInputSignals	) 
  { 
	  uiOpData[VDY_TWO] = (uint8)offsetof ( reqVdyPrtList_t, pVehicleInputSignals );
	  /* [Requirement - L3D_ALGO_22428 : InputChecks] - set DEM if operation Mode is not Reset and return. */
	  if( reqPorts->pBaseCtrlData->eOpMode != (BaseOpMode_t)BASE_OM_RESET )
		  {
			services->pfDem_SetEventStatus( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED );
			services->pfDem_SetEventStatusPreExtData( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED, (const uint8*)&uiOpData, sizeof(uiOpData) );
		  }
	 ui8Fault = VDY_REQUEST_PORT_FAULT;
  }
  else if( NULL == reqPorts->pVehicleParameter		) 
  { 
	  uiOpData[VDY_TWO] = (uint8)offsetof ( reqVdyPrtList_t, pVehicleParameter	   );
	  /* [Requirement - L3D_ALGO_22428 : InputChecks] - set DEM if operation Mode is not Reset and return. */
	  if( reqPorts->pBaseCtrlData->eOpMode != (BaseOpMode_t)BASE_OM_RESET )
		  {
			services->pfDem_SetEventStatus( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED );
			services->pfDem_SetEventStatusPreExtData( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED, (const uint8*)&uiOpData, sizeof(uiOpData) );
		  }
	 ui8Fault = VDY_REQUEST_PORT_FAULT;
  }
  else
  {
    /* If none of the request port's are null, then set the Dem_EventStatus PASS and return. */
  	services->pfDem_SetEventStatus( VDY_FUSI_ERROR, DEM_EVENT_STATUS_PASSED );
	services->pfDem_SetEventStatusPreExtData( (const AS_t_Dem_EventIDType)VDY_FUSI_ERROR, (const AS_t_Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, (const uint8*)&uiOpData, sizeof(uiOpData) );
  }
  }
#else
  if (    (reqPorts == NULL)
#if (CFG_VDY_MFC)
	   || (reqPorts->pBaseCtrlData == NULL)           /* operation mode, calibration mode and cyle time*/
#else
       || (reqPorts->pCtrl == NULL)           /* operation mode, calibration mode and cyle time*/
#endif
       || (reqPorts->pVehicleParameter == NULL)       /* VehicleParameter data            */
       || (reqPorts->pVehicleInputSignals == NULL)    /* Vehicle input signals            */
       || (reqPorts->pNVMRead == NULL)                /* VDY NVM read data                */
#if ( (defined(CFG_VDY_DO_VELOCITY_CORR)) && (CFG_VDY_DO_VELOCITY_CORR) )
#if ( (defined(VEL_CORR_HIST_STATIONARY_TARGETS)) && (VEL_CORR_HIST_STATIONARY_TARGETS) )
       || (reqPorts->pVelStatObj == NULL)             /* Reference speed histogramm       */
#endif
#if ( (defined(VEL_CORR_ALN)) && (VEL_CORR_ALN) )
       || (reqPorts->pAln_Monitoring == NULL)         /* Velocity information from ALN    */
#endif
#endif
#if ( (defined(CFG_VDY_ROLLBENCH_DETECTION)) && (CFG_VDY_ROLLBENCH_DETECTION) )
       || (reqPorts->pRTBRecognition == NULL)         /* RTB information    */
#endif
#if ( (defined(CFG_VDY_ALIGNMENT_OFFSET_MONITOR)) && (CFG_VDY_ALIGNMENT_OFFSET_MONITOR) )
       || (reqPorts->pAlignEstYawRateOffset == NULL)  /* Yaw rate offset estimated by the alignment */
#endif
#ifndef AS_SERVICEFUNC_VERSION
       || (reqPorts->pVDYCallBackHdlr == NULL)        /* VDY call back handler            */
#endif
#if ( (defined(CFG_VDY_64BIT_TIMESTAMP_INTERV)) && (CFG_VDY_64BIT_TIMESTAMP_INTERV) )
       || (reqPorts->pLongLongTimeStamp == NULL)
#endif
       )
    {
      ui8Fault |= VDY_REQUEST_PORT_FAULT;
    }
    else
    {
      /* all request ports available, no fault */
    }
#endif
  /* all provided ports */
#if (CFG_VDY_MFC)
  uiOpData1[0] = FUSI_ERROR_DIR_OUTPUT;
  uiOpData1[1] = FUSI_ERROR_TYPE_NULLPOINTER;

  if( (NULL == proPorts) || 
	  (NULL == proPorts->pAlgoCompState)			) 
  { 
	  uiOpData1[VDY_TWO] = (uint8)offsetof ( proVdyPrtList_t, pAlgoCompState		 );
	  /* If any of the provide port is Null, then set the Dem_EventStatus FAILED and return. */
      services->pfDem_SetEventStatus( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED );
      services->pfDem_SetEventStatusPreExtData( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED, (const uint8*)&uiOpData1, sizeof(uiOpData1) );
      ui8Fault = VDY_PROVIDE_PORT_FAULT;
  }
  else if( NULL == proPorts->pNVMWrite				) 
  { 
	  uiOpData1[VDY_TWO] = (uint8)offsetof ( proVdyPrtList_t, pNVMWrite				 );
	  /* If any of the provide port is Null, then set the Dem_EventStatus FAILED and return. */
      services->pfDem_SetEventStatus( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED );
      services->pfDem_SetEventStatusPreExtData( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED, (const uint8*)&uiOpData1, sizeof(uiOpData1) );
      ui8Fault = VDY_PROVIDE_PORT_FAULT;
  }
  else if( NULL == proPorts->pVDYErrors				) 
  { 
	  uiOpData1[VDY_TWO] = (uint8)offsetof ( proVdyPrtList_t, pVDYErrors			 );
	  /* If any of the provide port is Null, then set the Dem_EventStatus FAILED and return. */
      services->pfDem_SetEventStatus( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED );
      services->pfDem_SetEventStatusPreExtData( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED, (const uint8*)&uiOpData1, sizeof(uiOpData1) );
      ui8Fault = VDY_PROVIDE_PORT_FAULT;
  }
  else if( NULL == proPorts->pVDYEstCurves			) 
  { 
	  uiOpData1[VDY_TWO] = (uint8)offsetof ( proVdyPrtList_t, pVDYEstCurves			 );
	  /* If any of the provide port is Null, then set the Dem_EventStatus FAILED and return. */
      services->pfDem_SetEventStatus( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED );
      services->pfDem_SetEventStatusPreExtData( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED, (const uint8*)&uiOpData1, sizeof(uiOpData1) );
      ui8Fault = VDY_PROVIDE_PORT_FAULT;
  }
  else if( NULL == proPorts->pVDYOffsets			) 
  { 
	  uiOpData1[VDY_TWO] = (uint8)offsetof ( proVdyPrtList_t, pVDYOffsets			 );
	  /* If any of the provide port is Null, then set the Dem_EventStatus FAILED and return. */
      services->pfDem_SetEventStatus( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED );
      services->pfDem_SetEventStatusPreExtData( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED, (const uint8*)&uiOpData1, sizeof(uiOpData1) );
      ui8Fault = VDY_PROVIDE_PORT_FAULT;
  }
  else if( NULL == proPorts->pVehicleDynamicSignals	) 
  { 
	  uiOpData1[VDY_TWO] = (uint8)offsetof ( proVdyPrtList_t, pVehicleDynamicSignals );
	  /* If any of the provide port is Null, then set the Dem_EventStatus FAILED and return. */
      services->pfDem_SetEventStatus( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED );
      services->pfDem_SetEventStatusPreExtData( VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED, (const uint8*)&uiOpData1, sizeof(uiOpData1) );
      ui8Fault = VDY_PROVIDE_PORT_FAULT;
  }
  else 
  {
    /* If none of the provide port's are Null, then set the Dem_EventStatus PASS and return. */
    services->pfDem_SetEventStatus( VDY_FUSI_ERROR, DEM_EVENT_STATUS_PASSED );
    services->pfDem_SetEventStatusPreExtData( VDY_FUSI_ERROR, DEM_EVENT_STATUS_PASSED, (const uint8*)&uiOpData1, sizeof(uiOpData1) );
  }
#else
  if (    (proPorts == NULL)
       || (proPorts->pVehicleDynamicSignals == NULL)       /* Vehicle Dynamic signals     */
#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_OUTPUT)) || (!CFG_VDY_DIS_YAW_SENSOR_OUTPUT) )
       || (proPorts->pALNYawRate == NULL)                  /* The yaw rate for alignment only yaw rate from yaw rate sensro */
#endif
#if (CFG_VDY_INT_GYRO)
       || (proPorts->pYwrtTempTable == NULL)          /* NvYawrate temp table             */
#endif
       || (proPorts->pNVMWrite == NULL)                    /* VDY NVM write data          */
       || (proPorts->pVDYErrors == NULL)                   /* vdy errors, input signals/parameters and internal errors */
       || (proPorts->pVDYOffsets == NULL)                  /* vdy offsets, for yaw rate steering wheel angle and lateral acceleration sensor */
#if ( (defined(CFG_VDY_64BIT_TIMESTAMP_INTERV)) && (CFG_VDY_64BIT_TIMESTAMP_INTERV) )
       || (proPorts->pLongLongTimeStamp == NULL)
#endif
#if ( (!defined(CFG_VDY_DIS_CURVE_OUTPUT)) || (!CFG_VDY_DIS_CURVE_OUTPUT) )
       || (proPorts->pVDYEstCurves == NULL)                /* VDY estimated curves       */
#endif
#if ( defined(CFG_VDY_USE_ALGOCOMPSTATE) && (CFG_VDY_USE_ALGOCOMPSTATE) )
#if (CFG_VDY_MFC)
	   || (proPorts->pAlgoCompState == NULL)                /* VDY component state output */
#else
	   || (proPorts->pVdyCompState == NULL)                /* VDY component state output */
#endif
#endif
       )
    {
      ui8Fault |= VDY_PROVIDE_PORT_FAULT;
    }
    else
    {
      /* all provide ports available, no fault */
    }
#endif

/* PRQA S 0894 EOF */
/* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: No Risk */
#if (AS_SERVICEFUNC_VERSION)
#if (CFG_VDY_MFC)
  if( (NULL == services->pfRTAAlgoServiceAddEvent) || (NULL == services->pfMeasStartFuncCycle) ||
      (NULL == services->pfDem_SetEventStatus	 ) || (NULL == services->pfDem_SetEventStatusPreExtData) )
  {
    ui8Fault = VDY_SERVICE_PORT_FAULT;
  }
  else
  {
    /* If none of the service port's are Null, then set the Dem_EventStatus PASS and return. */
  }
#else
  /* servive functions */
  if (services == NULL)
  {
    ui8Fault |= VDY_SERVICE_PORT_FAULT;
  }
  else
  {
    /* service ports available, no fault */
  }
#endif
#endif

  return ui8Fault;
}


/* **********************************************************************
	Unit Design for vdyCalculateCurveError is found in Declaration Section
**************************************************************************** */
STATIC_MTD float32 vdyCalculateCurveError(const VDYInputData_t * input, const VDYOffsets_t * pVDYOffsets)
{
  /* steering angle */
  float32 swa_offset_error;    /* offset error */
  float32 sye_error;           /* yaw rate error */

  /* gyro */
  float32 yaw_offset_error;    /* offset error */
  float32 gye_error;           /* yaw rate error */

  /* lateral acceleration */
  float32 ay_offset_error;     /* offset error */
  float32 aye_error;           /* yaw rate error */

  /* wheels */
#if ( (CFG_VDY_DIS_WHS_OFFSET_COMP == 0) && (CFG_VDY_DIS_WHEEL_PRE_PROCESSING == 0) )
  float32 wye_error_front;     /* yaw rate error front axle*/
  float32 wye_error_rear;      /* yaw rate error rear axle*/
#endif
  float32 wye_error;           /* yaw rate error */

  /* combined yaw rate */
  float32 ye_error;            /* offset error */
  float32 k_yaw_sye_part, k_yaw_gye_part, k_yaw_aye_part, k_yaw_wye_part, k_yaw_sum;  /* percentage of input yaw rates in combined yaw rate */

  /* curve */
  float32 sye_curve_error;     /* error of steering angle curve  */
  float32 ye_curve_error;      /* error of yaw rate curve  */
  float32 curve_error;         /* resulting curve error */
  float32 k_curve_sye_part, k_curve_ye_part, k_curve_sum;  /* percentage of input curves in combined curve */

  /* get steering wheel error based on offset deviation */
#if ( (CFG_VDY_DIS_SWA_OFFSET_COMP == 0) && (CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING == 0) )
  {
    VDYSwaData_t    *pSwaData  = vdySwaGetPrivateData();
    swa_offset_error = pSwaData->Offset.Dev / VDY_THREE_F;
  }
#else
  swa_offset_error = 0.0F;
#endif

   (void)pVDYOffsets;

  /* get gyro error based on offset learn state */
#if (CFG_VDY_DIS_YWR_OFFSET_COMP == 0)
  /* No offset type present                   */
  if (pVDYOffsets->Ywr.StandStillState == (sint32)OUT_YWR_OFFS_NON)
  {
    yaw_offset_error = YWR_OFFSET_ERROR_OUT_YWR_OFFS_NON;
  }
  /*!< Offset short acquired from stand still   */
  else if (pVDYOffsets->Ywr.StandStillState == (sint32)OUT_YWR_OFFS_STANDST_SHORT)
  {
    yaw_offset_error = YWR_OFFSET_ERROR_OUT_YWR_OFFS_STANDST_SHORT;
  }
  /* if already in the dynamic offset phase, use dynamic offset accuracy */
  else if (pVDYOffsets->Ywr.StandStillState == (sint32)OUT_YWR_OFFS_DYN)
  {
    yaw_offset_error = YWR_OFFSET_ERROR_OUT_YWR_OFFS_DYN;
  }
  /* Offset full acquired from stand still    */
  else if (pVDYOffsets->Ywr.StandStillState == (sint32)OUT_YWR_OFFS_STANDST_FULL)
  {
    // if the wheel offsets are calculated, we are also already in the dynamic yaw rate offset phase
    if ((vdy_internal_data.vdy_offsets_in.vdy_whs_offset.offset_ratio_front_dev >= VDY_ONE_F) || (vdy_internal_data.vdy_offsets_in.vdy_whs_offset.offset_ratio_rear_dev >= VDY_ONE_F))
    {
      yaw_offset_error = YWR_OFFSET_ERROR_OUT_YWR_OFFS_STANDST_FULL;
    }
    else
    {
      yaw_offset_error = YWR_OFFSET_ERROR_OUT_YWR_OFFS_DYN;
    }
  }
   /* Offset acquired from non-volatile memory */
  else if (pVDYOffsets->Ywr.StandStillState == (sint32)OUT_YWR_OFFS_STANDST_EEPROM)
  {
    #if ( (defined(CFG_VDY_REDUCE_CURVE_ERROR)) && (CFG_VDY_REDUCE_CURVE_ERROR) )
     // Change the yaw offset error from EEPROM to Dynamic to reduce the curve error when the vehicle is moving and threshold time is elapsed
    if((VDYModIf.LongMot.MotState.MotState != VDY_LONG_MOT_STATE_STDST) && (u_count > TIME_EEPROM_TO_DYNAMIC))
    {
      yaw_offset_error = YWR_OFFSET_ERROR_OUT_YWR_OFFS_DYN;
    }
    else
    {
      if(u_count > TIME_EEPROM_TO_DYNAMIC)
      {
        u_count = 0;
      }
      yaw_offset_error = YWR_OFFSET_ERROR_OUT_YWR_OFFS_STANDST_EEPROM;
      u_count++;
    }
   #else
      yaw_offset_error = YWR_OFFSET_ERROR_OUT_YWR_OFFS_STANDST_EEPROM;

   #endif
  }
  /* invalid state information, assume max. error */
  else
  {
    yaw_offset_error = YWR_OFFSET_ERROR_OUT_YWR_OFFS_NON;
  }
#else
  /* yaw rate input already compensated, assume low error  */
  yaw_offset_error = YWR_OFFSET_ERROR_OUT_YWR_OFFS_DYN;
#endif

  /* get lateral acceleration error based on offset deviation */
#if ((CFG_VDY_DIS_LAT_OFFSET_COMP == 0) && (CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING == 0) )
  {
    VDYAyData_t     *pAyData   = vdyAyGetPrivateData();
    ay_offset_error = pAyData->Offset.Dev / VDY_THREE_F;
  }
#else
  ay_offset_error = 0.0F;
#endif

  /* calculate yaw errors based on variance and offset error */
#if ( ( CFG_VDY_DIS_SWA_OFFSET_COMP == 0) && ( CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING == 0) )
  sye_error = (VDY_ONE_F/input->Parameter.SteeringRatio.swa.rat[1]) * ((swa_offset_error / (input->Parameter.WheelBase + (input->Parameter.SelfSteerGrad * CML_Sqr(vdy_internal_data.vdy_ve_out.veh_velo)))) * vdy_internal_data.vdy_ve_out.veh_velo);
#else
  (void)input; /* remove compiler warning, input is not used in certain configurations */
  sye_error = 0.0F;
#endif  
  gye_error = yaw_offset_error;  /* gye error is already a yaw rate error, no further calculation needed */
  if ( vdy_internal_data.vdy_ve_out.veh_velo >MIN_VELO_YAW_RATE_ERROR)
  {
    aye_error = ay_offset_error / vdy_internal_data.vdy_ve_out.veh_velo;
  }
  else
  {
    aye_error = VDY_ZERO_F;
  }

#if ( (CFG_VDY_DIS_WHS_OFFSET_COMP == 0) && (CFG_VDY_DIS_WHEEL_PRE_PROCESSING == 0) )
  /* calculate wheel errors based offset error */
  if (CML_f_IsNonZero(vdy_internal_data.vdy_ve_out.veh_velo))
  {
    float32 f_wye_temp;

    
	f_wye_temp =(input->Parameter.TrackWidthFront * (VDY_ONE_F + ((input->Parameter.AxisLoadDistr) * ((input->Parameter.WhlLoadDepFrontAxle * (input->Parameter.CntrOfGravHeight * (input->Parameter.VehWeight * CML_Sqr(vdy_internal_data.vdy_ve_out.veh_velo)))) / ((VDY_THOUSAND_F*VDY_THOUSAND_F) * CML_Sqr(input->Parameter.TrackWidthFront))) ) ));

    if (f_wye_temp > VDY_ZERO_F)
    {
      wye_error_front = (vdy_internal_data.vdy_offsets_in.vdy_whs_offset.offset_ratio_front_dev * vdy_internal_data.vdy_ve_out.veh_velo) / f_wye_temp;
    }
    else
    {
      wye_error_front = VDY_ZERO_F;
    }

    
	f_wye_temp = (input->Parameter.TrackWidthRear  * (VDY_ONE_F + (((VDY_ONE_F - input->Parameter.AxisLoadDistr) * ((input->Parameter.WhlLoadDepRearAxle  * (input->Parameter.CntrOfGravHeight * (input->Parameter.VehWeight * CML_Sqr(vdy_internal_data.vdy_ve_out.veh_velo)))) / ((VDY_THOUSAND_F*VDY_THOUSAND_F) * CML_Sqr(input->Parameter.TrackWidthRear ))) ) ))  );

    if (f_wye_temp > VDY_ZERO_F)
    {
      wye_error_rear = (vdy_internal_data.vdy_offsets_in.vdy_whs_offset.offset_ratio_rear_dev  * vdy_internal_data.vdy_ve_out.veh_velo) / f_wye_temp;
    }
    else
    {
      wye_error_rear = VDY_ZERO_F;
    }
  }
  else
  {
    wye_error_front = VDY_ZERO_F;
    wye_error_rear = VDY_ZERO_F;
  }

  wye_error = wye_error_front + wye_error_rear; 
#else
  /* wheel speed processing deactivated, no error added (will not be used for yaw rate anyway) */
  wye_error = 0;
#endif

  /* calculate combined yaw rate (ye) error considering the Kalman gain */
  k_yaw_sum = vdy_ye_k.K_yaw[VDY_ONE] + vdy_ye_k.K_yaw[VDY_THREE] + vdy_ye_k.K_yaw[VDY_FIVE] + vdy_ye_k.K_yaw[VDY_SEVEN];
  if ( CML_f_IsNonZero(k_yaw_sum) )
  {
    k_yaw_gye_part = vdy_ye_k.K_yaw[VDY_ONE] / k_yaw_sum;
    k_yaw_wye_part = vdy_ye_k.K_yaw[VDY_THREE] / k_yaw_sum;
    k_yaw_aye_part = vdy_ye_k.K_yaw[VDY_FIVE] / k_yaw_sum;
    k_yaw_sye_part = vdy_ye_k.K_yaw[VDY_SEVEN] / k_yaw_sum;
    ye_error = (sye_error * k_yaw_sye_part) + (gye_error * k_yaw_gye_part) + (aye_error * k_yaw_aye_part) + (wye_error * k_yaw_wye_part);
  }
  else
  {
    ye_error = VDY_ZERO_F;
  }

  /* calculate combined yaw rate (ye) curve error */
  if (vdy_internal_data.vdy_ve_out.veh_velo > MIN_VELO_YAW_RATE_ERROR)
  {
    ye_curve_error = ye_error/(vdy_internal_data.vdy_ve_out.veh_velo);
  }
  else
  {
    ye_curve_error = VDY_ZERO_F;
  }

  /* calculate steering angle (sye) curve error */
#if ( ( CFG_VDY_DIS_SWA_OFFSET_COMP == 0) && (CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING == 0) )
  sye_curve_error = (VDY_ONE_F/input->Parameter.SteeringRatio.swa.rat[1]) * (swa_offset_error / (input->Parameter.WheelBase + (input->Parameter.SelfSteerGrad * CML_Sqr(vdy_internal_data.vdy_ve_out.veh_velo))));
#else
  sye_curve_error = 0.0F;
#endif

  /* calculate combined curve error considering the Kalman gain */
  k_curve_sum = vdy_ye_k.K_curve[VDY_TWO] + vdy_ye_k.K_curve[0];
  if ( CML_f_IsNonZero(k_curve_sum) )
  {
    k_curve_ye_part  = vdy_ye_k.K_curve[0] / k_curve_sum;
    k_curve_sye_part = vdy_ye_k.K_curve[VDY_TWO] / k_curve_sum;
    curve_error = (sye_curve_error * k_curve_sye_part) + (ye_curve_error * k_curve_ye_part);
  }
  else
  {
    curve_error = VDY_ZERO_F;
  }
  return curve_error;
}
 

 
/* **********************************************************************
	Unit Design for vdyCalculateLaneErrorConf is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyCalculateLaneErrorConf(const reqVdyPrtList_t * reqPorts, const VDYInputData_t * input, const VDYOffsets_t * pVDYOffsets, VehDyn_t * pVehDyn)
{
  /* counter and flags for input signals */
  static uint8 u_all_wheels_qual_not_avail_counter = 0;
  static boolean b_all_wheels_qual_not_avail = (boolean)FALSE;

  static uint8 u_yaw_qual_not_avail_counter = 0;
  static boolean b_yaw_qual_not_avail = (boolean)FALSE;

  static uint8 u_swa_qual_not_avail_counter = 0;
  static boolean b_swa_qual_not_avail = (boolean)FALSE;

  static uint8 u_esp_qual_not_avail_counter = 0;
  static boolean b_esp_qual_not_avail = (boolean)FALSE;

  static uint8 u_yaw_qual_not_def_counter = 0;
  static boolean b_yaw_qual_not_def = (boolean)FALSE;

  static uint8 u_swa_qual_low_precision_counter = 0;
  static boolean b_swa_qual_low_precision = (boolean)FALSE;

  static uint8 u_one_wheel_qual_reduced_counter = 0;
  static boolean b_one_wheel_qual_reduced = (boolean)FALSE;

  static uint8 u_lat_acc_qual_not_avail_counter = 0;
  static boolean b_lat_acc_qual_not_avail = (boolean)FALSE;

  float32 f_CurveError;  /* error in curve */
  float32 f_LatError;    /* lateral error in curve */

  static uint8 u_conf_counter = 0;     /* counter for hold time (before going to lower confidence) */
  static uint8 u_CurveConf = 0;        /* curve confidence calculated in this cycle */
  static uint8 u_CurveConfOutput = 0;  /* curve confidence output (calculated value might be delayed by hold time) */


  /* check if all the wheel speeds are not available for 5 cycles */
  if (    (VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_FL, reqPorts->pVehicleInputSignals->VehSigMain.State) == (VDYIoStateTypes_t)VDY_IO_STATE_INVALID)
       && (VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_FR, reqPorts->pVehicleInputSignals->VehSigMain.State) == (VDYIoStateTypes_t)VDY_IO_STATE_INVALID)
       && (VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_RL, reqPorts->pVehicleInputSignals->VehSigMain.State) == (VDYIoStateTypes_t)VDY_IO_STATE_INVALID)
       && (VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_RR, reqPorts->pVehicleInputSignals->VehSigMain.State) == (VDYIoStateTypes_t)VDY_IO_STATE_INVALID)  )
  {
    if (u_all_wheels_qual_not_avail_counter < MAX_SIGNAL_COUNTER)
    {
      u_all_wheels_qual_not_avail_counter++;
    }
    else
    {
      b_all_wheels_qual_not_avail = (boolean)TRUE;
    }
  }
  else
  {
    u_all_wheels_qual_not_avail_counter = 0;
    b_all_wheels_qual_not_avail = (boolean)FALSE;
  }

  /* check if just one wheel speed is not available for 5 cycles */
  if (    (VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_FL, reqPorts->pVehicleInputSignals->VehSigMain.State) != (VDYIoStateTypes_t)VDY_IO_STATE_VALID)
       || (VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_FR, reqPorts->pVehicleInputSignals->VehSigMain.State) != (VDYIoStateTypes_t)VDY_IO_STATE_VALID)
       || (VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_RL, reqPorts->pVehicleInputSignals->VehSigMain.State) != (VDYIoStateTypes_t)VDY_IO_STATE_VALID)
       || (VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_RR, reqPorts->pVehicleInputSignals->VehSigMain.State) != (VDYIoStateTypes_t)VDY_IO_STATE_VALID)  )
  {
    if (u_one_wheel_qual_reduced_counter < MAX_SIGNAL_COUNTER)
    {
      u_one_wheel_qual_reduced_counter++;
    }
    else
    {
      b_one_wheel_qual_reduced = (boolean)TRUE;
    }
  }
  else
  {
    u_one_wheel_qual_reduced_counter = 0;
    b_one_wheel_qual_reduced = (boolean)FALSE;
  }

  /* check if yaw rate is not available for 5 cycles */
  if (VDY_GET_IO_STATE(VDY_SIN_POS_YWR, reqPorts->pVehicleInputSignals->VehSigMain.State) == (VDYIoStateTypes_t)VDY_IO_STATE_INVALID)
  {
    if (u_yaw_qual_not_avail_counter < MAX_SIGNAL_COUNTER)
    {
      u_yaw_qual_not_avail_counter++;
    }
    else
    {
      b_yaw_qual_not_avail = (boolean)TRUE;
    }
  }
  else
  {
    u_yaw_qual_not_avail_counter = 0;
    b_yaw_qual_not_avail = (boolean)FALSE;
  }

  /* check if yaw rate is decreased for 5 cycles */
  if (VDY_GET_IO_STATE(VDY_SIN_POS_YWR, reqPorts->pVehicleInputSignals->VehSigMain.State) == (VDYIoStateTypes_t)VDY_IO_STATE_DECREASED)
  {
    if (u_yaw_qual_not_def_counter < MAX_SIGNAL_COUNTER)
    {
      u_yaw_qual_not_def_counter++;
    }
    else
    {
      b_yaw_qual_not_def = (boolean)TRUE;
    }
  }
  else
  {
    u_yaw_qual_not_def_counter = 0;
    b_yaw_qual_not_def = (boolean)FALSE;
  }

  /* check if steering angle is not available for 5 cycles */
  if (VDY_GET_IO_STATE(VDY_SIN_POS_SWA, reqPorts->pVehicleInputSignals->VehSigMain.State) == (VDYIoStateTypes_t)(VDYIoStateTypes_t)VDY_IO_STATE_INVALID)
  {
    if (u_swa_qual_not_avail_counter < MAX_SIGNAL_COUNTER)
    {
      u_swa_qual_not_avail_counter++;
    }
    else
    {
      b_swa_qual_not_avail = (boolean)TRUE;
    }
  }
  else
  {
    u_swa_qual_not_avail_counter = 0;
    b_swa_qual_not_avail = (boolean)FALSE;
  }

  /* check if steering angle is at low precision for 5 cycles */
  if (VDY_GET_IO_STATE(VDY_SIN_POS_SWA, reqPorts->pVehicleInputSignals->VehSigMain.State) == (VDYIoStateTypes_t)VDY_IO_STATE_DECREASED)
  {
    if (u_swa_qual_low_precision_counter < MAX_SIGNAL_COUNTER)
    {
      u_swa_qual_low_precision_counter++;
    }
    else
    {
      b_swa_qual_low_precision = (boolean)TRUE;
    }
  }
  else
  {
    u_swa_qual_low_precision_counter = 0;
    b_swa_qual_low_precision = (boolean)FALSE;
  }

  /* check if lateral acceleration is not available for 5 cycles */
  if (VDY_GET_IO_STATE(VDY_SIN_POS_LATA, reqPorts->pVehicleInputSignals->VehSigMain.State) != (VDYIoStateTypes_t)VDY_IO_STATE_VALID)
  {
    if (u_lat_acc_qual_not_avail_counter < MAX_SIGNAL_COUNTER)
    {
      u_lat_acc_qual_not_avail_counter++;
    }
    else
    {
      b_lat_acc_qual_not_avail = (boolean)TRUE;
    }
  }
  else
  {
    u_lat_acc_qual_not_avail_counter = 0;
    b_lat_acc_qual_not_avail = (boolean)FALSE;
  }

  /* check if esp is not available for 5 cycles */
  if (VDY_GET_IO_STATE(VEH_SIG_BRAKE_ABS, reqPorts->pVehicleInputSignals->Brake.State) != (VDYIoStateTypes_t)VDY_IO_STATE_VALID)
  {
    if (u_esp_qual_not_avail_counter < MAX_SIGNAL_COUNTER)
    {
      u_esp_qual_not_avail_counter++;
    }
    else
    {
      b_esp_qual_not_avail = (boolean)TRUE;
    }
  }
  else
  {
    u_esp_qual_not_avail_counter = 0;
    b_esp_qual_not_avail = (boolean)FALSE;
  }

  /* calculate the curve error and store in output */
#if (CFG_VDY_USE_EXT_PROC_CURVATURE)
  f_CurveError = 0.0002f; /* For external curvature ,curve error is hardcoded to 0.0002.
  						  As per ACC "For a 100m Safety Distance, required curve error is 0.000175"  */
  (void)input;
#else  
  f_CurveError = vdyCalculateCurveError(input, pVDYOffsets);
#endif

  /* if curve output is not available */
  if ((VDY_GET_IO_STATE(VDY_SOUT_POS_CURVE, pVehDyn->State) != (VDYIoStateTypes_t)VDY_IO_STATE_VALID) &&
      (VDY_GET_IO_STATE(VDY_SOUT_POS_CURVE, pVehDyn->State) != (VDYIoStateTypes_t)VDY_IO_STATE_DECREASED))
  {
    u_CurveConf = 0;
  }
  else
  {
    /* if both yaw rate and steering angle offset are not available, or either yaw rate, steering angle or ESP are not available or all wheel inputs are not available */
    if (    (((pVDYOffsets->Ywr.StandStillState == (sint32)OUT_YWR_OFFS_NON) || (pVDYOffsets->Ywr.StandStillState == (sint32)OUT_YWR_OFFS_STANDST_EEPROM)) && (pVDYOffsets->Swa.State == 0))
         || (b_swa_qual_not_avail == (boolean)TRUE)
         || (b_yaw_qual_not_avail == (boolean)TRUE)
         || (b_esp_qual_not_avail == (boolean)TRUE)
         || (b_all_wheels_qual_not_avail == (boolean)TRUE)
       )
    {
      u_CurveConf = 1;
    }
    /* if only one offset is available, the yaw rate offset is too high, steering angle is at low precision, yaw rate is degraded, lat accel or one of the wheel inputs are not available */
    else if (    (CML_f_Abs(pVDYOffsets->Ywr.StandStillOffset) > YWR_OFFS_LIMIT)
              || ((pVDYOffsets->Ywr.StandStillState == (sint32)OUT_YWR_OFFS_NON) || (pVDYOffsets->Ywr.StandStillState == (sint32)OUT_YWR_OFFS_STANDST_EEPROM) || (pVDYOffsets->Swa.State == 0))
              || (b_swa_qual_low_precision == (boolean)TRUE)
              || (b_yaw_qual_not_def == (boolean)TRUE)
              || ((b_lat_acc_qual_not_avail == (boolean)TRUE) && (pVDYOffsets->Ywr.StandStillState == (sint32)OUT_YWR_OFFS_DYN))
              || ((b_one_wheel_qual_reduced == (boolean)TRUE) && (pVDYOffsets->Ywr.StandStillState == (sint32)OUT_YWR_OFFS_DYN))  )
    {
      u_CurveConf = VDY_TWO_U;
    }
    else
    {
      /* calculate the lateral curve error in x sec distance and set the conf signal */
      f_LatError = vdyCalculateCurveLatDistance(VDY_ZERO_F, f_CurveError, TIME_DIST_CONF_6 * vdy_internal_data.vdy_ve_out.veh_velo);  /* distance in 4 seconds */
      if (f_LatError <= MAX_LAT_ERROR)
      {
        u_CurveConf = VDY_SIX_U;
      }
      else
      {
        f_LatError = vdyCalculateCurveLatDistance(VDY_ZERO_F, f_CurveError, TIME_DIST_CONF_5 * vdy_internal_data.vdy_ve_out.veh_velo);  /* distance in 3 seconds */
        if (f_LatError <= MAX_LAT_ERROR)
        {
          u_CurveConf = VDY_FIVE_U;
        }
        else
        {
          f_LatError = vdyCalculateCurveLatDistance(VDY_ZERO_F, f_CurveError, TIME_DIST_CONF_4 * vdy_internal_data.vdy_ve_out.veh_velo);  /* distance in 2 seconds */
          if (f_LatError <= MAX_LAT_ERROR)
          {
            u_CurveConf = VDY_FOUR_U;
          }
          else
          {
            f_LatError = vdyCalculateCurveLatDistance(VDY_ZERO_F, f_CurveError, TIME_DIST_CONF_3 * vdy_internal_data.vdy_ve_out.veh_velo);  /* distance in 1 second */
            if (f_LatError <= MAX_LAT_ERROR)
            {
              u_CurveConf = VDY_THREE_U;
            }
            else
            {
              u_CurveConf = VDY_TWO_U;
            }
          }
        }
      }
    }
  }

  /* new conf lower then before and higher than 2? */
  if ((u_CurveConfOutput > u_CurveConf) && (u_CurveConf > VDY_TWO_U))
  {
    /* new (lower) conf already calculates for 400ms? */
    if (u_conf_counter < MAX_HOLD_TIME)
    {
      /* count hold time of old higher conf */
      u_conf_counter++;
    }
    else
    {
      /* take new lower conf after hold time expired */
      u_CurveConfOutput = u_CurveConf;
    }
  }
  else
  {
    /* higher or equal conf or conf is 2 or lower, take conf value directly */
    u_conf_counter = 0;
    u_CurveConfOutput = u_CurveConf;
  }
 
  /* Store values in output port */
  pVehDyn->Lateral.Curve.CrvConf = u_CurveConfOutput;
  pVehDyn->Lateral.Curve.CrvError = f_CurveError;
}



/* **********************************************************************
	Unit Design for vdyCalculateCurveLatDistance is found in Declaration Section
**************************************************************************** */
STATIC_MTD float32 vdyCalculateCurveLatDistance(float32 f_c1, float32 f_c2, float32 f_b)
{
  float32 f_xc1, f_yc1, f_xc2, f_yc2;  /* coordinates of points on curves */
  float32 f_d;                         /* resulting distance */

  /* if curvature is very small, the point is assumed on the straight line, otherwise calculate coordinates on circle */ 
  if (CML_f_Abs(f_c1) < MIN_CURVE_FOR_APPROXIMATION)
  {
    f_xc1 = VDY_ZERO_F;
    f_yc1 = f_b;
  }
  else
  {
    f_xc1 = ((COS_HD_(f_c1*f_b)) / f_c1) - (VDY_ONE_F/f_c1);
    f_yc1 = (SIN_HD_(f_c1*f_b)) / f_c1;
  }
    
  /* if curvature is very small, the point is assumed on the straight line, otherwise calculate coordinates on circle */ 
  if (CML_f_Abs(f_c2) < MIN_CURVE_FOR_APPROXIMATION)
  {
    f_xc2 = VDY_ZERO_F;
    f_yc2 = f_b;
  }
  else
  {
    f_xc2 = ((COS_HD_(f_c2*f_b)) / f_c2) - (VDY_ONE_F/f_c2);
    f_yc2 = (SIN_HD_(f_c2*f_b)) / f_c2;
  }
    
  /* calculate distance between points */
  f_d = VDY_SQRT( CML_Sqr(f_xc1 - f_xc2) + CML_Sqr(f_yc1 - f_yc2) );

  return f_d;
}



/* **********************************************************************
	Unit Design for vdyCopyInputSignals is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyCopyInputSignals(VehSigMain_t * p_Input, const VehSigMain_t * p_VehSigMain)
{
  /* external yaw rate and temperature */
  vdyFCheckInputSignals(&p_Input->YawRate, p_VehSigMain->YawRate, &s_LastInputSignals.YawRate,
                          &p_Input->State[VDY_SIN_POS_YWR], p_VehSigMain->State[VDY_SIN_POS_YWR], &s_LastInputSignals.State[VDY_SIN_POS_YWR],
                          &u_DebouceCounter[VDY_SIN_POS_YWR]);

  vdyFCheckInputSignals(&p_Input->YawRateTemp, p_VehSigMain->YawRateTemp, &s_LastInputSignals.YawRateTemp,
                          &p_Input->State[VDY_SIN_POS_YWR_TEMP], p_VehSigMain->State[VDY_SIN_POS_YWR_TEMP], &s_LastInputSignals.State[VDY_SIN_POS_YWR_TEMP],
                          &u_DebouceCounter[VDY_SIN_POS_YWR_TEMP]);

  /* steering angle */
  vdyFCheckInputSignals(&p_Input->StWheelAngle, p_VehSigMain->StWheelAngle, &s_LastInputSignals.StWheelAngle,
                          &p_Input->State[VDY_SIN_POS_SWA], p_VehSigMain->State[VDY_SIN_POS_SWA], &s_LastInputSignals.State[VDY_SIN_POS_SWA],
                          &u_DebouceCounter[VDY_SIN_POS_SWA]);

  /* lateral acceleration */
  vdyFCheckInputSignals(&p_Input->LatAccel, p_VehSigMain->LatAccel, &s_LastInputSignals.LatAccel,
                          &p_Input->State[VDY_SIN_POS_LATA], p_VehSigMain->State[VDY_SIN_POS_LATA], &s_LastInputSignals.State[VDY_SIN_POS_LATA],
                          &u_DebouceCounter[VDY_SIN_POS_LATA]);

  /* wheel speeds */
  vdyFCheckInputSignals(&p_Input->WhlVelFrLeft, p_VehSigMain->WhlVelFrLeft, &s_LastInputSignals.WhlVelFrLeft,
                          &p_Input->State[VDY_SIN_POS_WVEL_FL], p_VehSigMain->State[VDY_SIN_POS_WVEL_FL], &s_LastInputSignals.State[VDY_SIN_POS_WVEL_FL],
                          &u_DebouceCounter[VDY_SIN_POS_WVEL_FL]);

  vdyFCheckInputSignals(&p_Input->WhlVelFrRight, p_VehSigMain->WhlVelFrRight, &s_LastInputSignals.WhlVelFrRight,
                          &p_Input->State[VDY_SIN_POS_WVEL_FR], p_VehSigMain->State[VDY_SIN_POS_WVEL_FR], &s_LastInputSignals.State[VDY_SIN_POS_WVEL_FR],
                          &u_DebouceCounter[VDY_SIN_POS_WVEL_FR]);

  vdyFCheckInputSignals(&p_Input->WhlVelReLeft, p_VehSigMain->WhlVelReLeft, &s_LastInputSignals.WhlVelReLeft,
                          &p_Input->State[VDY_SIN_POS_WVEL_RL], p_VehSigMain->State[VDY_SIN_POS_WVEL_RL], &s_LastInputSignals.State[VDY_SIN_POS_WVEL_RL],
                          &u_DebouceCounter[VDY_SIN_POS_WVEL_RL]);

  vdyFCheckInputSignals(&p_Input->WhlVelReRight, p_VehSigMain->WhlVelReRight, &s_LastInputSignals.WhlVelReRight,
                          &p_Input->State[VDY_SIN_POS_WVEL_RR], p_VehSigMain->State[VDY_SIN_POS_WVEL_RR], &s_LastInputSignals.State[VDY_SIN_POS_WVEL_RR],
                          &u_DebouceCounter[VDY_SIN_POS_WVEL_RR]);

  /* internal yaw rate and temperature */
  vdyFCheckInputSignals(&p_Input->YawRateInt, p_VehSigMain->YawRateInt, &s_LastInputSignals.YawRateInt,
                          &p_Input->State[VDY_SIN_POS_YWRINT], p_VehSigMain->State[VDY_SIN_POS_YWRINT], &s_LastInputSignals.State[VDY_SIN_POS_YWRINT],
                          &u_DebouceCounter[VDY_SIN_POS_YWRINT]);

  vdyFCheckInputSignals(&p_Input->YawRateIntTemp, p_VehSigMain->YawRateIntTemp, &s_LastInputSignals.YawRateIntTemp,
                          &p_Input->State[VDY_SIN_POS_YWRINT_TEMP], p_VehSigMain->State[VDY_SIN_POS_YWRINT_TEMP], &s_LastInputSignals.State[VDY_SIN_POS_YWRINT_TEMP],
                          &u_DebouceCounter[VDY_SIN_POS_YWRINT_TEMP]);

  /* internal longitudinal acceleration */
  vdyFCheckInputSignals(&p_Input->LongAccel, p_VehSigMain->LongAccel, &s_LastInputSignals.LongAccel,
                          &p_Input->State[VDY_SIN_POS_LONGA], p_VehSigMain->State[VDY_SIN_POS_LONGA], &s_LastInputSignals.State[VDY_SIN_POS_LONGA],
                          &u_DebouceCounter[VDY_SIN_POS_LONGA]);

  /* rear wheel steering angle */
  vdyFCheckInputSignals(&p_Input->RearWhlAngle, p_VehSigMain->RearWhlAngle, &s_LastInputSignals.RearWhlAngle,
                          &p_Input->State[VDY_SIN_POS_RSTA], p_VehSigMain->State[VDY_SIN_POS_RSTA], &s_LastInputSignals.State[VDY_SIN_POS_RSTA],
                          &u_DebouceCounter[VDY_SIN_POS_RSTA]);

  /* external longitudinal velocity */
  vdyFCheckInputSignals(&p_Input->VehVelocityExt, p_VehSigMain->VehVelocityExt, &s_LastInputSignals.VehVelocityExt,
                          &p_Input->State[VDY_SIN_POS_VEHVEL_EXT], p_VehSigMain->State[VDY_SIN_POS_VEHVEL_EXT], &s_LastInputSignals.State[VDY_SIN_POS_VEHVEL_EXT],
                          &u_DebouceCounter[VDY_SIN_POS_VEHVEL_EXT]);

  /* external longitudinal acceleration */
  vdyFCheckInputSignals(&p_Input->VehLongAccelExt, p_VehSigMain->VehLongAccelExt, &s_LastInputSignals.VehLongAccelExt,
                          &p_Input->State[VDY_SIN_POS_VEHACL_EXT], p_VehSigMain->State[VDY_SIN_POS_VEHACL_EXT], &s_LastInputSignals.State[VDY_SIN_POS_VEHACL_EXT],
                          &u_DebouceCounter[VDY_SIN_POS_VEHACL_EXT]);

  /* wheel rolling directions */
  vdyUCheckInputSignals(&p_Input->WhlDirFrLeft, p_VehSigMain->WhlDirFrLeft, &s_LastInputSignals.WhlDirFrLeft,
                          &p_Input->State[VDY_SIN_POS_WDIR_FL], p_VehSigMain->State[VDY_SIN_POS_WDIR_FL], &s_LastInputSignals.State[VDY_SIN_POS_WDIR_FL],
                          &u_DebouceCounter[VDY_SIN_POS_WDIR_FL]);

  vdyUCheckInputSignals(&p_Input->WhlDirFrRight, p_VehSigMain->WhlDirFrRight, &s_LastInputSignals.WhlDirFrRight,
                          &p_Input->State[VDY_SIN_POS_WDIR_FR], p_VehSigMain->State[VDY_SIN_POS_WDIR_FR], &s_LastInputSignals.State[VDY_SIN_POS_WDIR_FR],
                          &u_DebouceCounter[VDY_SIN_POS_WDIR_FR]);

  vdyUCheckInputSignals(&p_Input->WhlDirReLeft, p_VehSigMain->WhlDirReLeft, &s_LastInputSignals.WhlDirReLeft,
                          &p_Input->State[VDY_SIN_POS_WDIR_RL], p_VehSigMain->State[VDY_SIN_POS_WDIR_RL], &s_LastInputSignals.State[VDY_SIN_POS_WDIR_RL],
                          &u_DebouceCounter[VDY_SIN_POS_WDIR_RL]);

  vdyUCheckInputSignals(&p_Input->WhlDirReRight, p_VehSigMain->WhlDirReRight, &s_LastInputSignals.WhlDirReRight,
                          &p_Input->State[VDY_SIN_POS_WDIR_RR], p_VehSigMain->State[VDY_SIN_POS_WDIR_RR], &s_LastInputSignals.State[VDY_SIN_POS_WDIR_RR],
                          &u_DebouceCounter[VDY_SIN_POS_WDIR_RR]);

  /* wheel pulses */
  vdyUCheckInputSignals(&p_Input->WhlTicksDevFrLeft, p_VehSigMain->WhlTicksDevFrLeft, &s_LastInputSignals.WhlTicksDevFrLeft,
                          &p_Input->State[VDY_SIN_POS_WTCKS_FL], p_VehSigMain->State[VDY_SIN_POS_WTCKS_FL], &s_LastInputSignals.State[VDY_SIN_POS_WTCKS_FL],
                          &u_DebouceCounter[VDY_SIN_POS_WTCKS_FL]);
 
  vdyUCheckInputSignals(&p_Input->WhlTicksDevFrRight, p_VehSigMain->WhlTicksDevFrRight, &s_LastInputSignals.WhlTicksDevFrRight,
                          &p_Input->State[VDY_SIN_POS_WTCKS_FR], p_VehSigMain->State[VDY_SIN_POS_WTCKS_FR], &s_LastInputSignals.State[VDY_SIN_POS_WTCKS_FR],
                          &u_DebouceCounter[VDY_SIN_POS_WTCKS_FR]);

  vdyUCheckInputSignals(&p_Input->WhlTicksDevReLeft, p_VehSigMain->WhlTicksDevReLeft, &s_LastInputSignals.WhlTicksDevReLeft,
                          &p_Input->State[VDY_SIN_POS_WTCKS_RL], p_VehSigMain->State[VDY_SIN_POS_WTCKS_RL], &s_LastInputSignals.State[VDY_SIN_POS_WTCKS_RL],
                          &u_DebouceCounter[VDY_SIN_POS_WTCKS_RL]);

  vdyUCheckInputSignals(&p_Input->WhlTicksDevReRight, p_VehSigMain->WhlTicksDevReRight, &s_LastInputSignals.WhlTicksDevReRight,
                          &p_Input->State[VDY_SIN_POS_WTCKS_RR], p_VehSigMain->State[VDY_SIN_POS_WTCKS_RR], &s_LastInputSignals.State[VDY_SIN_POS_WTCKS_RR],
                          &u_DebouceCounter[VDY_SIN_POS_WTCKS_RR]);

  /* gear position */
  vdyUCheckInputSignals(&p_Input->ActGearPos, p_VehSigMain->ActGearPos, &s_LastInputSignals.ActGearPos,
                          &p_Input->State[VDY_SIN_POS_GEAR], p_VehSigMain->State[VDY_SIN_POS_GEAR], &s_LastInputSignals.State[VDY_SIN_POS_GEAR],
                          &u_DebouceCounter[VDY_SIN_POS_GEAR]);

  /* brake activation level */
  p_Input->BrakeActLevel = 0U;
  vdySCheckInputSignals(&p_Input->BrakeActLevel, p_VehSigMain->BrakeActLevel, &s_LastInputSignals.BrakeActLevel,
                          &p_Input->State[VDY_SIN_POS_BRAKE], p_VehSigMain->State[VDY_SIN_POS_BRAKE], &s_LastInputSignals.State[VDY_SIN_POS_BRAKE],
                          &u_DebouceCounter[VDY_SIN_POS_BRAKE]);

  /* parking brake state */
  vdyUCheckInputSignals(&p_Input->ParkBrakeState, p_VehSigMain->ParkBrakeState, &s_LastInputSignals.ParkBrakeState,
                          &p_Input->State[VDY_SIN_POS_PBRK], p_VehSigMain->State[VDY_SIN_POS_PBRK], &s_LastInputSignals.State[VDY_SIN_POS_PBRK],
                          &u_DebouceCounter[VDY_SIN_POS_PBRK]);

  /* external driving direction */
  vdyUCheckInputSignals(&p_Input->VehLongDirExt, p_VehSigMain->VehLongDirExt, &s_LastInputSignals.VehLongDirExt,
                          &p_Input->State[VDY_SIN_POS_VDIR], p_VehSigMain->State[VDY_SIN_POS_VDIR], &s_LastInputSignals.State[VDY_SIN_POS_VDIR],
                          &u_DebouceCounter[VDY_SIN_POS_VDIR]);

  /* external motion state */
  vdyUCheckInputSignals(&p_Input->VehLongMotStateExt, p_VehSigMain->VehLongMotStateExt, &s_LastInputSignals.VehLongMotStateExt,
                          &p_Input->State[VDY_SIN_POS_VMOT], p_VehSigMain->State[VDY_SIN_POS_VMOT], &s_LastInputSignals.State[VDY_SIN_POS_VMOT],
                          &u_DebouceCounter[VDY_SIN_POS_VMOT]);

  /* external lateral curvature */
  vdyFCheckInputSignals(&p_Input->CurveC0Ext, p_VehSigMain->CurveC0Ext, &s_LastInputSignals.CurveC0Ext,
                          &p_Input->State[VDY_SIN_POS_CRV], p_VehSigMain->State[VDY_SIN_POS_CRV], &s_LastInputSignals.State[VDY_SIN_POS_CRV],
                          &u_DebouceCounter[VDY_SIN_POS_CRV]);

  vdyFCheckInputSignals(&p_Input->CurveC1Ext, p_VehSigMain->CurveC1Ext, &s_LastInputSignals.CurveC1Ext,
                          &p_Input->State[VDY_SIN_POS_CRV], p_VehSigMain->State[VDY_SIN_POS_CRV], &s_LastInputSignals.State[VDY_SIN_POS_CRV],
                          &u_DebouceCounter[VDY_SIN_POS_CRV]);

  /* external side slip angle */
  vdyFCheckInputSignals(&p_Input->SideSlipAngleExt, p_VehSigMain->SideSlipAngleExt, &s_LastInputSignals.SideSlipAngleExt,
                          &p_Input->State[VDY_SIN_POS_SSA], p_VehSigMain->State[VDY_SIN_POS_SSA], &s_LastInputSignals.State[VDY_SIN_POS_SSA],
                          &u_DebouceCounter[VDY_SIN_POS_SSA]);

#if( defined(CFG_VDY_VELO_MONITOR_MIN_MAX) && (CFG_VDY_VELO_MONITOR_MIN_MAX))

    /* external MIN velocity  */
  vdyFCheckInputSignals(&p_Input->VehVelocityExtMin, p_VehSigMain->VehVelocityExtMin, &s_LastInputSignals.VehVelocityExtMin,
                          &p_Input->State[VDY_SIN_POS_VEHVEL_MIN], p_VehSigMain->State[VDY_SIN_POS_VEHVEL_MIN], &s_LastInputSignals.State[VDY_SIN_POS_VEHVEL_MIN],
                          &u_DebouceCounter[VDY_SIN_POS_VEHVEL_MIN]);

  /* external MAX velocity  */
  vdyFCheckInputSignals(&p_Input->VehVelocityExtMax, p_VehSigMain->VehVelocityExtMax, &s_LastInputSignals.VehVelocityExtMax,
                          &p_Input->State[VDY_SIN_POS_VEHVEL_MAX], p_VehSigMain->State[VDY_SIN_POS_VEHVEL_MAX], &s_LastInputSignals.State[VDY_SIN_POS_VEHVEL_MAX],
                          &u_DebouceCounter[VDY_SIN_POS_VEHVEL_MAX]);

#endif

}




/* **********************************************************************
	Unit Design for vdyFCheckInputSignals is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyFCheckInputSignals(float32 * p_InputSignal, float32 f_VehSigMainSignal, float32 * p_LastSignal, VDYIoStateTypes_t * p_VDYInState, VDYIoStateTypes_t e_VehSigState, VDYIoStateTypes_t * p_LastState, uint8 * p_DebouceCounter)
{

  /* invalid and not available signals are debounced, all other states are valid inputs */
  if ((e_VehSigState == (VDYIoStateTypes_t)VDY_IO_STATE_INVALID) || (e_VehSigState == (VDYIoStateTypes_t)VDY_IO_STATE_NOTAVAIL))
  {
    if (*p_DebouceCounter >= VDY_MAX_INPUT_DEBOUNCING)
    {
      /* no debouncing any more, take input value */
      *p_InputSignal = f_VehSigMainSignal;
      *p_VDYInState = e_VehSigState;
      *p_LastSignal = f_VehSigMainSignal;
      *p_LastState = e_VehSigState;
    }
    else
    {
      /* keep old value and increase counter */
      (*p_DebouceCounter)++;
      *p_InputSignal = *p_LastSignal;
      *p_VDYInState = *p_LastState;
    }
  }
  else
  {
    /* take new value and state */
    *p_InputSignal = f_VehSigMainSignal;
    *p_VDYInState = e_VehSigState;
    /* reset debounce counter */
    *p_DebouceCounter = 0U;
    /* store current signal and state for next cycle */
    *p_LastSignal = f_VehSigMainSignal;
    *p_LastState = e_VehSigState;
  }
}



/* **********************************************************************
	Unit Design for vdyUCheckInputSignals is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyUCheckInputSignals(uint8 * p_InputSignal, uint8 u_VehSigMainSignal, uint8 * p_LastSignal, VDYIoStateTypes_t * p_VDYInState, VDYIoStateTypes_t e_VehSigState, VDYIoStateTypes_t * p_LastState, uint8 * p_DebouceCounter)
{

  /* invalid and not available signals are debounced, all other states are valid inputs */
  if ((e_VehSigState == (VDYIoStateTypes_t)VDY_IO_STATE_INVALID) || (e_VehSigState == (VDYIoStateTypes_t)VDY_IO_STATE_NOTAVAIL))
  {
    if (*p_DebouceCounter >= VDY_MAX_INPUT_DEBOUNCING)
    {
      /* no debouncing any more, take input value */
      *p_InputSignal = u_VehSigMainSignal;
      *p_VDYInState = e_VehSigState;
      *p_LastSignal = u_VehSigMainSignal;
      *p_LastState = e_VehSigState;
    }
    else
    {
      /* keep old value and increase counter */
      (*p_DebouceCounter)++;
      *p_InputSignal = *p_LastSignal;
      *p_VDYInState = *p_LastState;
    }
  }
  else
  {
    /* take new value and state */
    *p_InputSignal = u_VehSigMainSignal;
    *p_VDYInState = e_VehSigState;
    /* reset debounce counter */
    *p_DebouceCounter = 0U;
    /* store current signal and state for next cycle */
    *p_LastSignal = u_VehSigMainSignal;
    *p_LastState = e_VehSigState;
  }
}



/* **********************************************************************
	Unit Design for vdySCheckInputSignals is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdySCheckInputSignals(uint16 * p_InputSignal, uint16 u_VehSigMainSignal, uint16 * p_LastSignal, VDYIoStateTypes_t * p_VDYInState, VDYIoStateTypes_t e_VehSigState, VDYIoStateTypes_t * p_LastState, uint8 * p_DebouceCounter)
{

  /* invalid and not available signals are debounced, all other states are valid inputs */
  if ((e_VehSigState == (VDYIoStateTypes_t)VDY_IO_STATE_INVALID) || (e_VehSigState == (VDYIoStateTypes_t)VDY_IO_STATE_NOTAVAIL))
  {
    if (*p_DebouceCounter >= VDY_MAX_INPUT_DEBOUNCING)
    {
      /* no debouncing any more, take input value */
      *p_InputSignal = u_VehSigMainSignal;
      *p_VDYInState = e_VehSigState;
      *p_LastSignal = u_VehSigMainSignal;
      *p_LastState = e_VehSigState;
    }
    else
    {
      /* keep old value and increase counter */
      (*p_DebouceCounter)++;
      *p_InputSignal = *p_LastSignal;
      *p_VDYInState = *p_LastState;
    }
  }
  else
  {
    /* take new value and state */
    *p_InputSignal = u_VehSigMainSignal;
    *p_VDYInState = e_VehSigState;
    /* reset debounce counter */
    *p_DebouceCounter = 0U;
    /* store current signal and state for next cycle */
    *p_LastSignal = u_VehSigMainSignal;
    *p_LastState = e_VehSigState;
  }
}


#if ( defined(CFG_VDY_SET_DEM_EVENTS) && (CFG_VDY_SET_DEM_EVENTS) )
/* **********************************************************************
	Unit Design for vdySetDEMEvents is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdySetDEMEvents(const VDYErrors_t * pVDYErrors, const AS_t_ServiceFuncts * services)
{
  /* signal fault */
  if (pVDYErrors->SignalInputErrors.InputSignalError == (VDYErrState_t)VDY_ERR_STATE_ACTIVE)
  {
    services->pfDem_SetEventStatus(VDY_BUS_DATA_ERROR, DEM_EVENT_STATUS_FAILED);
  }
  else if (pVDYErrors->SignalInputErrors.InputSignalError == (VDYErrState_t)VDY_ERR_STATE_INACTIVE)
  {
    services->pfDem_SetEventStatus(VDY_BUS_DATA_ERROR, DEM_EVENT_STATUS_PASSED);
  }
  else
  {
    /* keep old DEM status */
  }

  /* yaw rate monitor wheel speeds fault */
  if (pVDYErrors->OutPutErrors.VDY_FS_YR_VS_WSP == (VDYErrState_t)VDY_ERR_STATE_ACTIVE)
  {
    services->pfDem_SetEventStatus(VDY_E_FS_YR_VS_WSP, DEM_EVENT_STATUS_FAILED);
  }
  else if (pVDYErrors->OutPutErrors.VDY_FS_YR_VS_WSP == (VDYErrState_t)VDY_ERR_STATE_INACTIVE)
  {
    services->pfDem_SetEventStatus(VDY_E_FS_YR_VS_WSP, DEM_EVENT_STATUS_PASSED);
  }
  else
  {
    /* keep old DEM status */
  }

  /* yaw rate monitor lateral acceleration fault */
  if (pVDYErrors->OutPutErrors.VDY_FS_YR_VS_AY == (VDYErrState_t)VDY_ERR_STATE_ACTIVE)
  {
    services->pfDem_SetEventStatus(VDY_E_FS_YR_VS_AY, DEM_EVENT_STATUS_FAILED);
  }
  else if (pVDYErrors->OutPutErrors.VDY_FS_YR_VS_AY == (VDYErrState_t)VDY_ERR_STATE_INACTIVE)
  {
    services->pfDem_SetEventStatus(VDY_E_FS_YR_VS_AY, DEM_EVENT_STATUS_PASSED);
  }
  else
  {
    /* keep old DEM status */
  }

  /* yaw rate monitor steering wheel fault */
  if (pVDYErrors->OutPutErrors.VDY_FS_YR_VS_SWA == (VDYErrState_t)VDY_ERR_STATE_ACTIVE)
  {
    services->pfDem_SetEventStatus(VDY_E_FS_YR_VS_SWA, DEM_EVENT_STATUS_FAILED);
  }
  else if (pVDYErrors->OutPutErrors.VDY_FS_YR_VS_SWA == (VDYErrState_t)VDY_ERR_STATE_INACTIVE)
  {
    services->pfDem_SetEventStatus(VDY_E_FS_YR_VS_SWA, DEM_EVENT_STATUS_PASSED);
  }
  else
  {
    /* keep old DEM status */
  }

#if ( (!defined(CFG_VDY_MFC431TA19)) || (!CFG_VDY_MFC431TA19) )
  /* velocity output fault */
  if (pVDYErrors->OutPutErrors.VDY_VEH_VEL_NOT_AVAILABLE == (VDYErrState_t)VDY_ERR_STATE_ACTIVE)
  {
    services->pfDem_SetEventStatus(VDY_E_VEH_VEL_NOT_AVAILABLE, DEM_EVENT_STATUS_FAILED);
  }
  else if (pVDYErrors->OutPutErrors.VDY_VEH_VEL_NOT_AVAILABLE == (VDYErrState_t)VDY_ERR_STATE_INACTIVE)
  {
    services->pfDem_SetEventStatus(VDY_E_VEH_VEL_NOT_AVAILABLE, DEM_EVENT_STATUS_PASSED);
  }
  else
  {
    /* keep old DEM status */
  }

  /* yaw rate output fault */
  if (pVDYErrors->OutPutErrors.VDY_VEH_YWR_NOT_AVAILABLE == (VDYErrState_t)VDY_ERR_STATE_ACTIVE)
  {
    services->pfDem_SetEventStatus(VDY_E_VEH_YWR_NOT_AVAILABLE, DEM_EVENT_STATUS_FAILED);
  }
  else if (pVDYErrors->OutPutErrors.VDY_VEH_YWR_NOT_AVAILABLE == (VDYErrState_t)VDY_ERR_STATE_INACTIVE)
  {
    services->pfDem_SetEventStatus(VDY_E_VEH_YWR_NOT_AVAILABLE, DEM_EVENT_STATUS_PASSED);
  }
  else
  {
    /* keep old DEM status */
  }
#endif

  if ( (pVDYErrors->OutPutErrors.VelocityErr == (VDYErrState_t)VDY_ERR_STATE_ACTIVE) || (pVDYErrors->OutPutErrors.YawRateErr == (VDYErrState_t)VDY_ERR_STATE_ACTIVE) )
  {
	services->pfDem_SetEventStatus(VDY_FUSI_ERROR, DEM_EVENT_STATUS_FAILED);
  }
  else if ( (pVDYErrors->OutPutErrors.VelocityErr == (VDYErrState_t)VDY_ERR_STATE_INACTIVE) || (pVDYErrors->OutPutErrors.YawRateErr == (VDYErrState_t)VDY_ERR_STATE_INACTIVE) )
  {
	services->pfDem_SetEventStatus(VDY_FUSI_ERROR, DEM_EVENT_STATUS_PASSED);
  }
  else
  {
	  /* keep old DEM status */
  }

 #if ( (defined(CFG_VDY_NVM_LEARN_DATA_ERROR)) && (CFG_VDY_NVM_LEARN_DATA_ERROR) )
  /* check for valid values written into NVM */ 
  /* NVM Learn Data fault */
  if ((pVDYErrors->OutPutErrors.YwrNVMOffsRg == (VDYErrState_t)VDY_ERR_STATE_ACTIVE) || (pVDYErrors->OutPutErrors.SwaNVMOffsRg == (VDYErrState_t)VDY_ERR_STATE_ACTIVE) ||
	  (pVDYErrors->OutPutErrors.AyNVMOffsRg == (VDYErrState_t)VDY_ERR_STATE_ACTIVE) || (pVDYErrors->OutPutErrors.SSGNVMOffsRg == (VDYErrState_t)VDY_ERR_STATE_ACTIVE) ||
	  (pVDYErrors->OutPutErrors.WLDNVMOffsRg == (VDYErrState_t)VDY_ERR_STATE_ACTIVE))
  {
//    services->pfDem_SetEventStatus(VDY_NVM_LEARN_DATA_ERROR, DEM_EVENT_STATUS_FAILED);
  }
  else
  {
//    services->pfDem_SetEventStatus(VDY_NVM_LEARN_DATA_ERROR, DEM_EVENT_STATUS_PASSED);
  }
#endif

}
#endif

/** @} */ 
/* EOF */
