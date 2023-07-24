/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_city.c

  DESCRIPTION:            Definition file for head light assist.

  AUTHOR:                 Boris Lugez

  CREATION DATE:          2011-03-24

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_city.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:26:56CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/environment/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:38:36CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/environment/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:28CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/environment/project.pj
  CHANGE:                 Revision 1.90 2014/03/26 11:27:42CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed some mandatory QAC warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 26, 2014 11:27:42 AM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.89 2014/03/25 19:11:54CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Separation of hla_segmentation.c
  CHANGE:                 Removed QAC warnings
  CHANGE:                 Replaces fABS by CML_f_abs
  CHANGE:                 Introduced CML_s_Round2Int
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 25, 2014 7:11:54 PM CET]
  CHANGE:                 Change Package : 207432:46 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.88 2014/03/25 18:36:42CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_city.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_city.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/environment/project.pj.
  CHANGE:                 Revision 1.87 2014/03/21 09:38:41CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed some QAC warnings (parenthesis)
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 21, 2014 9:38:41 AM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.86 2014/03/19 16:31:44CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGE:                 Fixed hlar input adapter for old recordings (headlamp type)
  CHANGE:                 Clean-up of no longer needed files in simulation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 19, 2014 4:31:45 PM CET]
  CHANGE:                 Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGE:                 Revision 1.85 2014/03/19 15:21:59CET Fischer, Alexander (uidv8778) 
  CHANGE:                 Japan specific city implementations (CountryCode Parameter must be set to RTE_HLA_COUNTRY_CODE_JP)
  CHANGE:                 - leave city when there is numSLInSceneLeaveCityJapan or less SL in scene
  CHANGE:                 - faster city exit with ambient information
  CHANGE:                 --- Added comments ---  uidv8778 [Mar 19, 2014 3:21:59 PM CET]
  CHANGE:                 Change Package : 226009:1 http://mks-psad:7002/im/viewissue?selection=226009
  CHANGE:                 Revision 1.84 2014/03/04 16:51:57CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed QAC warnings
  CHANGE:                 Coding style
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 4:51:58 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.83 2014/03/03 16:51:39CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Support for R2.1 interface
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 3, 2014 4:51:40 PM CET]
  CHANGE:                 Change Package : 207432:31 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.82 2014/02/20 11:10:57CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed previous check-in
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 20, 2014 11:10:57 AM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.81 2014/02/18 13:21:49CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed missing initialization of global variables
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 18, 2014 1:21:50 PM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.80 2014/01/24 09:34:59CET Glebov, Roman (uidg4759) 
  CHANGE:                 switched from F32_IS_.* from global_defs.h to HLA_F32_IS_.* from hla_defs.h. 
  CHANGE:                 These are custom versions, which use much smaller Epsilon delta for comparison with 0
  CHANGE:                 --- Added comments ---  uidg4759 [Jan 24, 2014 9:34:59 AM CET]
  CHANGE:                 Change Package : 193435:4 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGE:                 Revision 1.79 2014/01/23 08:51:07CET Fischer, Alexander (uidv8778) 
  CHANGE:                 Bugfix --> wrong replacement f_32 < 0
  CHANGE:                 --- Added comments ---  uidv8778 [Jan 23, 2014 8:51:07 AM CET]
  CHANGE:                 Change Package : 169296:1 http://mks-psad:7002/im/viewissue?selection=169296
  CHANGE:                 Revision 1.78 2014/01/21 13:56:48CET Glebov, Roman (uidg4759) 
  CHANGE:                 fixed unsafe comparison of float32 with 0
  CHANGE:                 --- Added comments ---  uidg4759 [Jan 21, 2014 1:56:48 PM CET]
  CHANGE:                 Change Package : 193435:4 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGE:                 Revision 1.77 2014/01/10 18:34:03CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 First part of LRF on EVE (disabled)
  CHANGE:                 Merged LRF inputs into one struct
  CHANGE:                 Fixed exception handling of internal cali 
  CHANGE:                 Removed all tabs in the code and further clean-up
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 10, 2014 6:34:04 PM CET]
  CHANGE:                 Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.76 2014/01/05 22:53:02CET Glebov, Roman (uidg4759) 
  CHANGE:                 QAC: implicite conversion from int to unsigned int and vise versa removed
  CHANGE:                 --- Added comments ---  uidg4759 [Jan 5, 2014 10:53:02 PM CET]
  CHANGE:                 Change Package : 193435:2 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGE:                 Revision 1.75 2013/12/05 17:47:59CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Update to RTE I330
  CHANGE:                 --- Added comments ---  uidv7867 [Dec 5, 2013 5:48:00 PM CET]
  CHANGE:                 Change Package : 207432:13 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.74 2013/11/21 17:53:23CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Merge from NEW_SEG branch
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 5:53:24 PM CET]
  CHANGE:                 Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.73.1.4 2013/11/21 13:37:27CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Improved Icon normalize
  CHANGE:                 Bug fixes in segmentation
  CHANGE:                 Removed no longer compiler switches
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 1:37:27 PM CET]
  CHANGE:                 Change Package : 207432:1 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.73.1.3 2013/11/12 13:43:31CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Small bug fix
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 12, 2013 1:43:31 PM CET]
  CHANGE:                 Change Package : 201787:8 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGE:                 Revision 1.73.1.2 2013/10/21 10:18:29CEST Brunn, Marcus (brunnm) 
  CHANGE:                 - merged HLASegLInePos_t and HLASegLineLevelRef_t to HLASegLine_t
  CHANGE:                 - removed bit field for line position
  CHANGE:                 - moved  level index from line to region
  CHANGE:                 --- Added comments ---  brunnm [Oct 21, 2013 10:18:29 AM CEST]
  CHANGE:                 Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGE:                 Revision 1.73.1.1 2013/10/18 13:27:53CEST Brunn, Marcus (brunnm) 
  CHANGE:                 intial version of new segmentation
  CHANGE:                 --- Added comments ---  brunnm [Oct 18, 2013 1:27:53 PM CEST]
  CHANGE:                 Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGE:                 Revision 1.73 2013/04/19 14:48:28CEST Fischer, Alexander (uidv8778) 
  CHANGE:                 Changed city parameter from cm to m
  CHANGE:                 --- Added comments ---  uidv8778 [Apr 19, 2013 2:48:28 PM CEST]
  CHANGE:                 Change Package : 169296:1 http://mks-psad:7002/im/viewissue?selection=169296
  CHANGE:                 Revision 1.72 2013/04/12 10:55:35CEST Fischer, Alexander (uidv8778) 
  CHANGE:                 Implemented BMW Codierparameter for city
  CHANGE:                 --- Added comments ---  uidv8778 [Apr 12, 2013 10:55:36 AM CEST]
  CHANGE:                 Change Package : 169296:1 http://mks-psad:7002/im/viewissue?selection=169296
  CHANGE:                 Revision 1.71 2013/04/05 14:35:15CEST Fischer, Alexander (uidv8778) 
  CHANGE:                 Bugfix for detection of tunnels at night
  CHANGE:                 --- Added comments ---  uidv8778 [Apr 5, 2013 2:35:19 PM CEST]
  CHANGE:                 Change Package : 169296:1 http://mks-psad:7002/im/viewissue?selection=169296
  CHANGE:                 Revision 1.70 2013/03/11 16:13:32CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replaced no longer needed types by RTE ones
  CHANGE:                 - HLA_t_eSignalState
  CHANGE:                 - HLA_t_eLightStyle
  CHANGE:                 - HLA_t_eTunnel
  CHANGE:                 - HLA_t_eCityState
  CHANGE:                 - HLA_t_eWeatherState
  CHANGE:                 - HLA_t_eMotorwayState
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 11, 2013 4:13:33 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.69 2013/03/11 14:32:52CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Placed no longer needed by RTE ones
  CHANGE:                 - HLA_t_eBrightnessState
  CHANGE:                 - HLA_t_eLightOutput
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 11, 2013 2:32:52 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.68 2013/03/08 15:38:45CET Fischer, Alexander (uidv8778) 
  CHANGE:                 First version of ambient city detection
  CHANGE:                 --- Added comments ---  uidv8778 [Mar 8, 2013 3:38:46 PM CET]
  CHANGE:                 Change Package : 169296:1 http://mks-psad:7002/im/viewissue?selection=169296
  CHANGE:                 Revision 1.67 2013/03/08 10:30:17CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Updated to latest RTE
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 8, 2013 10:30:20 AM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.66 2013/03/04 11:14:58CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Integrated cam_rot into HLA
  CHANGE:                 bug fix in jacobian calculation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2013 11:14:59 AM CET]
  CHANGE:                 Change Package : 167173:26 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.65 2013/02/28 11:04:05CET Fischer, Alexander (uidv8778) 
  CHANGE:                 - Fixed MISRA warnings
  CHANGE:                 - Removed tabs
  CHANGE:                 --- Added comments ---  uidv8778 [Feb 28, 2013 11:04:06 AM CET]
  CHANGE:                 Change Package : 169296:1 http://mks-psad:7002/im/viewissue?selection=169296
  CHANGE:                 Revision 1.64 2013/02/12 15:08:09CET Fischer, Alexander (uidv8778) 
  CHANGE:                 Restructuring of the city code
  CHANGE:                 Optimization to avoid truck lights to be detected as SL
  CHANGE:                 --- Added comments ---  uidv8778 [Feb 12, 2013 3:08:09 PM CET]
  CHANGE:                 Change Package : 169296:1 http://mks-psad:7002/im/viewissue?selection=169296
  CHANGE:                 Revision 1.63 2013/01/25 16:59:42CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Changed enums to rte like types for missing hlar input params/signals
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 25, 2013 4:59:42 PM CET]
  CHANGE:                 Change Package : 167173:22 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.62 2013/01/24 13:20:12CET Fischer, Alexander (uidv8778) 
  CHANGE:                 MISRA fix
  CHANGE:                 --- Added comments ---  uidv8778 [Jan 24, 2013 1:20:13 PM CET]
  CHANGE:                 Change Package : 169296:1 http://mks-psad:7002/im/viewissue?selection=169296
  CHANGE:                 Revision 1.61 2013/01/23 17:57:29CET Brunn, Marcus (brunnm) 
  CHANGE:                 Converted enum to rte like type for
  CHANGE:                 - HLA_t_eCityState
  CHANGE:                 - HLA_t_eWeatherState
  CHANGE:                 --- Added comments ---  brunnm [Jan 23, 2013 5:57:29 PM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.60 2013/01/22 12:06:48CET Fischer, Alexander (uidv8778) 
  CHANGE:                 HLA-R Internal Highway Decision
  CHANGE:                 --- Added comments ---  uidv8778 [Jan 22, 2013 12:06:48 PM CET]
  CHANGE:                 Change Package : 173113:1 http://mks-psad:7002/im/viewissue?selection=173113
  CHANGE:                 Revision 1.59 2012/11/29 11:02:18CET Lugez, Boris (uidt2765) 
  CHANGE:                 Otpimize city detection for tunnels
  CHANGE:                 --- Added comments ---  uidt2765 [Nov 29, 2012 11:02:18 AM CET]
  CHANGE:                 Change Package : 166971:2 http://mks-psad:7002/im/viewissue?selection=166971
  CHANGE:                 Revision 1.58 2012/11/19 16:15:13CET Lugez, Boris (uidt2765) 
  CHANGE:                 -> Update city visu (street lamps classes exclusion reasons)
  CHANGE:                 --- Added comments ---  uidt2765 [Nov 19, 2012 4:15:14 PM CET]
  CHANGE:                 Change Package : 166971:1 http://mks-psad:7002/im/viewissue?selection=166971
  CHANGE:                 Revision 1.57 2012/11/15 09:56:36CET Brunn, Marcus (brunnm) 
  CHANGE:                 interface update for MFC4B0, BMW I210 (without RTE)
  CHANGE:                 --- Added comments ---  brunnm [Nov 15, 2012 9:56:36 AM CET]
  CHANGE:                 Change Package : 143736:1 http://mks-psad:7002/im/viewissue?selection=143736
  CHANGE:                 Revision 1.56 2012/10/18 17:55:45CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - allocation of array memory by array macro in order to realize a dedicated array boundary check mode
  CHANGE:                 --- Added comments ---  uidt9253 [Oct 18, 2012 5:55:45 PM CEST]
  CHANGE:                 Change Package : 118527:1 http://mks-psad:7002/im/viewissue?selection=118527
  CHANGE:                 Revision 1.55 2012/10/10 13:02:54CEST Brunn, Marcus (brunnm) 
  CHANGE:                 RAM optimization (Part2)
  CHANGE:                 --- Added comments ---  brunnm [Oct 10, 2012 1:02:55 PM CEST]
  CHANGE:                 Change Package : 143736:1 http://mks-psad:7002/im/viewissue?selection=143736
  CHANGE:                 Revision 1.54 2012/10/05 12:44:52CEST Brunn, Marcus (brunnm) 
  CHANGE:                 RAM optimization (part1)
  CHANGE:                 --- Added comments ---  brunnm [Oct 5, 2012 12:44:52 PM CEST]
  CHANGE:                 Change Package : 143736:1 http://mks-psad:7002/im/viewissue?selection=143736
  CHANGE:                 Revision 1.53 2012/06/05 11:59:59CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - activated the hlaCityData measfreeze and corrected the problem with SDL generation tool
  CHANGE:                 --- Added comments ---  uidt9253 [Jun 5, 2012 12:00:00 PM CEST]
  CHANGE:                 Change Package : 125128:1 http://mks-psad:7002/im/viewissue?selection=125128
  CHANGE:                 Revision 1.52 2012/04/19 16:26:42CEST Lugez, Boris (uidt2765) 
  CHANGE:                 To solve late city exit:
  CHANGE:                 -> Leaving city if straight (Radius>500) driving distance with no scene street lamps is superior to 50m
  CHANGE:                 -> Leaving city if real driving distance with no scene street lamp is superior to 70m and filtered driving distance with no scene street lamps is superior to 50m
  CHANGE:                 --- Added comments ---  uidt2765 [Apr 19, 2012 4:26:44 PM CEST]
  CHANGE:                 Change Package : 103574:1 http://mks-psad:7002/im/viewissue?selection=103574
  CHANGE:                 Revision 1.51 2012/03/23 11:36:08CET Brunn, Marcus (brunnm) 
  CHANGE:                 introduced forward driving distance and time (dtimeFwd_s, ddistFwd_m),
  CHANGE:                 time and distance will only be set while driving forwards and 0 while driving backwards
  CHANGE:                 --- Added comments ---  brunnm [Mar 23, 2012 11:36:08 AM CET]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.50 2012/03/22 18:40:09CET Lugez, Boris (uidt2765) 
  CHANGE:                 -> Leaving city if straight (Radius>500) driving distance with no scene street lamps is superior to 50m or real driving distance with no scene street lamp is superior to 120m
  CHANGE:                 --- Added comments ---  uidt2765 [Mar 22, 2012 6:40:09 PM CET]
  CHANGE:                 Change Package : 103574:1 http://mks-psad:7002/im/viewissue?selection=103574
  CHANGE:                 Revision 1.49 2012/03/20 18:18:59CET Lugez, Boris (uidt2765) 
  CHANGE:                 -> Differenciate right and left maximal static lateral distance for street lamps in accordance to the traffic style (right hand traffic: 10m < yw100 < 13m, left hand traffic: 13m < yw100 < 10m)
  CHANGE:                 -> Permits extra lateral distance for inner curve street lamps
  CHANGE:                 -> Permits extra lateral distance for bright street lamps (usage of an intensity flux model)
  CHANGE:                 -> Add a new kind of leaving street lamp used for Maybe city (isLeavingStreetLamp_MaybeCity) which is not as strict as isLeavingStreetLamp
  CHANGE:                 --- Added comments ---  uidt2765 [Mar 20, 2012 6:18:59 PM CET]
  CHANGE:                 Change Package : 103574:1 http://mks-psad:7002/im/viewissue?selection=103574
  CHANGE:                 Revision 1.48 2012/03/12 13:50:26CET Godreau, Bertrand (uid28828) 
  CHANGE:                 -> Rework of dynamic object classification
  CHANGE:                 -> Separate static kalman part from SLAM and static tracker
  CHANGE:                 --- Added comments ---  uid28828 [Mar 12, 2012 1:50:26 PM CET]
  CHANGE:                 Change Package : 94859:1 http://mks-psad:7002/im/viewissue?selection=94859
  CHANGE:                 Revision 1.47 2012/02/27 16:20:36CET Lugez, Boris (uidt2765) 
  CHANGE:                 -> Switch USE_CITY_ICON on
  CHANGE:                 --- Added comments ---  uidt2765 [Feb 27, 2012 4:20:36 PM CET]
  CHANGE:                 Change Package : 49956:1 http://mks-psad:7002/im/viewissue?selection=49956
  CHANGE:                 Revision 1.46 2012/02/23 16:56:53CET Lugez, Boris (uidt2765) 
  CHANGE:                 -> Possibility to filter lights rejected by city icon classifier (isSceneStreetLampIcon)
  CHANGE:                 -> Filter leaving street lamps detected as far object by static estimation (isFarObject)
  CHANGE:                 -> Filter scene street lamps with high uncertainty on static estimation (isConverging)
  CHANGE:                 --- Added comments ---  uidt2765 [Feb 23, 2012 4:56:54 PM CET]
  CHANGE:                 Change Package : 49560:1 http://mks-psad:7002/im/viewissue?selection=49560
  CHANGE:                 Revision 1.45 2012/01/06 11:21:00CET Lugez, Boris (uidt2765) 
  CHANGE:                 -> BugFix : remove street lamp height dependancy to speed in cities
  CHANGE:                 -> Clean up city parameters
  CHANGE:                 --- Added comments ---  uidt2765 [Jan 6, 2012 11:21:00 AM CET]
  CHANGE:                 Change Package : 49560:1 http://mks-psad:7002/im/viewissue?selection=49560
  CHANGE:                 Revision 1.44 2011/11/29 10:07:33CET Lugez, Boris (uidt2765) 
  CHANGE:                 -> Avoid city detection when the distance between street lamps is inferior to 20m (traffic lights false detection)
  CHANGE:                 --- Added comments ---  uidt2765 [Nov 29, 2011 10:07:33 AM CET]
  CHANGE:                 Change Package : 49560:1 http://mks-psad:7002/im/viewissue?selection=49560
  CHANGE:                 Revision 1.43 2011/11/16 17:22:00CET Lugez, Boris (uidt2765) 
  CHANGE:                 -> adapt required distance to leave city to the brightness of street lamps still in the scene
  CHANGE:                 --- Added comments ---  uidt2765 [Nov 16, 2011 5:22:00 PM CET]
  CHANGE:                 Change Package : 49560:1 http://mks-psad:7002/im/viewissue?selection=49560
  CHANGE:                 Revision 1.42 2011/11/15 17:54:40CET Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> adapt street lamps height assumption to speed
  CHANGE:                 --- Added comments ---  uidt2765 [Nov 15, 2011 5:54:40 PM CET]
  CHANGE:                 Change Package : 49560:1 http://mks-psad:7002/im/viewissue?selection=49560
  CHANGE:                 Revision 1.41 2011/11/15 10:56:06CET Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> solve MaybeCity instability
  CHANGE:                 --- Added comments ---  uidt2765 [Nov 15, 2011 10:56:06 AM CET]
  CHANGE:                 Change Package : 49560:1 http://mks-psad:7002/im/viewissue?selection=49560
  CHANGE:                 Revision 1.40 2011/11/14 14:06:52CET Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> add a reset pLeavList
  CHANGE:                 --- Added comments ---  uidt2765 [Nov 14, 2011 2:06:52 PM CET]
  CHANGE:                 Change Package : 49560:1 http://mks-psad:7002/im/viewissue?selection=49560
  CHANGE:                 Revision 1.39 2011/11/12 19:06:22CET Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> BF unrelated pointer
  CHANGE:                 --- Added comments ---  uidt2765 [Nov 12, 2011 7:06:24 PM CET]
  CHANGE:                 Change Package : 49560:1 http://mks-psad:7002/im/viewissue?selection=49560
  CHANGE:                 Revision 1.38 2011/11/12 17:19:02CET Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> Tuning City parameters
  CHANGE:                 --- Added comments ---  uidt2765 [Nov 12, 2011 5:19:02 PM CET]
  CHANGE:                 Change Package : 49560:1 http://mks-psad:7002/im/viewissue?selection=49560
  CHANGE:                 Revision 1.37 2011/11/11 18:53:41CET Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> MISRA rules
  CHANGE:                 --- Added comments ---  uidt2765 [Nov 11, 2011 6:53:42 PM CET]
  CHANGE:                 Change Package : 49560:1 http://mks-psad:7002/im/viewissue?selection=49560
  CHANGE:                 Revision 1.36 2011/11/11 15:50:17CET Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> remove delta_x_lp_lt
  CHANGE:                 -> change leaving street lamp list to chained list
  CHANGE:                 -> set city signal when 1 leaving street lamp on each side of the road and one scene street lamp
  CHANGE:                 -> set city signal when 2 leaving street lamps are shortly crossed and one in the scene
  CHANGE:                 --- Added comments ---  uidt2765 [Nov 11, 2011 3:50:17 PM CET]
  CHANGE:                 Change Package : 49560:1 http://mks-psad:7002/im/viewissue?selection=49560
  CHANGE:                 Revision 1.35 2011/10/20 19:47:19CEST Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> Add distance filter when decelerating
  CHANGE:                 --- Added comments ---  uidt2765 [Oct 20, 2011 7:47:19 PM CEST]
  CHANGE:                 Change Package : 49560:1 http://mks-psad:7002/im/viewissue?selection=49560
  CHANGE:                 Revision 1.34 2011/10/17 14:43:40CEST Godreau Bertrand (uid28828) (uid28828) 
  CHANGE:                 Rework of pairing
  CHANGE:                 --- Added comments ---  uid28828 [Oct 17, 2011 2:43:40 PM CEST]
  CHANGE:                 Change Package : 54276:1 http://mks-psad:7002/im/viewissue?selection=54276
  CHANGE:                 Revision 1.33 2011/10/12 17:40:06CEST Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> Solve DWBT errors
  CHANGE:                 -> Remove special city detection when speed above 80 kph
  CHANGE:                 -> Solve some City lost/ City False
  CHANGE:                 --- Added comments ---  uidt2765 [Oct 12, 2011 5:40:06 PM CEST]
  CHANGE:                 Change Package : 49560:1 http://mks-psad:7002/im/viewissue?selection=49560
  CHANGE:                 Revision 1.32 2011/09/28 18:42:43CEST Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> Add an auto evaluation for highway
  CHANGE:                 -> Decrease number of false city detection
  CHANGE:                 --- Added comments ---  uidt2765 [Sep 28, 2011 6:42:43 PM CEST]
  CHANGE:                 Change Package : 49560:1 http://mks-psad:7002/im/viewissue?selection=49560
  CHANGE:                 Revision 1.31 2011/09/20 19:02:32CEST Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> stronger traffic sign filter to speed up leaving city
  CHANGE:                 -> remove of 3D position estimation use to keep city state to speed up leaving city
  CHANGE:                 -> Decrease lateral range for scene street lamps
  CHANGE:                 --- Added comments ---  uidt2765 [Sep 20, 2011 7:02:32 PM CEST]
  CHANGE:                 Change Package : 49560:1 http://mks-psad:7002/im/viewissue?selection=49560
  CHANGE:                 Revision 1.30 2011/09/19 19:03:54CEST Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> change city detection first state in function of vehicle speed
  CHANGE:                 --- Added comments ---  uidt2765 [Sep 19, 2011 7:03:54 PM CEST]
  CHANGE:                 Change Package : 49560:1 http://mks-psad:7002/im/viewissue?selection=49560
  CHANGE:                 Revision 1.29 2011/09/07 09:47:01CEST Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> BF some variables not reset each frame
  CHANGE:                 --- Added comments ---  uidt2765 [Sep 7, 2011 9:47:02 AM CEST]
  CHANGE:                 Change Package : 49560:1 http://mks-psad:7002/im/viewissue?selection=49560
  CHANGE:                 Revision 1.28 2011/09/06 17:06:34CEST Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> Clean up city detection
  CHANGE:                 --- Added comments ---  uidt2765 [Sep 6, 2011 5:06:34 PM CEST]
  CHANGE:                 Change Package : 49560:1 http://mks-psad:7002/im/viewissue?selection=49560
  CHANGE:                 Revision 1.27 2011/09/06 13:58:10CEST Zechner Stefan (uidt9253) (uidt9253) 
  CHANGE:                 - remove redundant structure motionData from blackboard and replaced by input interface motionState
  CHANGE:                 --- Added comments ---  uidt9253 [Sep 6, 2011 1:58:10 PM CEST]
  CHANGE:                 Change Package : 76260:1 http://mks-psad:7002/im/viewissue?selection=76260
  CHANGE:                 Revision 1.26 2011/09/02 10:54:38CEST Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> Update visualisation for City
  CHANGE:                 --- Added comments ---  uidt2765 [Sep 2, 2011 10:54:38 AM CEST]
  CHANGE:                 Change Package : 49560:1 http://mks-psad:7002/im/viewissue?selection=49560
  CHANGE:                 Revision 1.25 2011/09/01 20:11:26CEST Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> Update City entry detection
  CHANGE:                 --- Added comments ---  uidt2765 [Sep 1, 2011 8:11:26 PM CEST]
  CHANGE:                 Change Package : 49560:1 http://mks-psad:7002/im/viewissue?selection=49560
  CHANGE:                 Revision 1.24 2011/08/31 17:53:38CEST Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> make more sensitive scene street lamps detection
  CHANGE:                 --- Added comments ---  uidt2765 [Aug 31, 2011 5:53:38 PM CEST]
  CHANGE:                 Change Package : 49560:1 http://mks-psad:7002/im/viewissue?selection=49560
  CHANGE:                 Revision 1.23 2011/08/30 19:17:07CEST Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> Add a new scenario for city entry detection
  CHANGE:                 -> Wait longer before leaving city if street lamp with height assumption is detected
  CHANGE:                 --- Added comments ---  uidt2765 [Aug 30, 2011 7:17:07 PM CEST]
  CHANGE:                 Change Package : 49560:1 http://mks-psad:7002/im/viewissue?selection=49560
  CHANGE:                 Revision 1.22 2011/08/26 16:11:30CEST Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> BF fix a bug in City detection
  CHANGE:                 --- Added comments ---  uidt2765 [Aug 26, 2011 4:11:30 PM CEST]
  CHANGE:                 Change Package : 49560:1 http://mks-psad:7002/im/viewissue?selection=49560
  CHANGE:                 Revision 1.21 2011/08/25 17:03:40CEST Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> Reduce calculation time for City
  CHANGE:                 --- Added comments ---  uidt2765 [Aug 25, 2011 5:03:40 PM CEST]
  CHANGE:                 Change Package : 49560:1 http://mks-psad:7002/im/viewissue?selection=49560
  CHANGE:                 Revision 1.20 2011/08/22 15:19:28CEST Godreau Bertrand (uid28828) (uid28828) 
  CHANGE:                 -> Clean StatusWord_t
  CHANGE:                 -> Remove StatusWordExt_t
  CHANGE:                 -> add variable willBeRemoved in StatusWord_t to flag tracks that will be removed on next cycle
  CHANGE:                  (replaces the previous test: pT->lost_time > pParamDeath->maxCyclesTrackLost)
  CHANGE:                 --- Added comments ---  uid28828 [Aug 22, 2011 3:19:28 PM CEST]
  CHANGE:                 Change Package : 54276:1 http://mks-psad:7002/im/viewissue?selection=54276
  CHANGE:                 Revision 1.19 2011/08/10 11:32:21CEST Godreau Bertrand (uid28828) (uid28828) 
  CHANGE:                 -> Add time measurements
  CHANGE:                 -> Add HLA_TEST_CALCULATION_TIME_PC cfg that can disable some time consuming PC_SIM sections.
  CHANGE:                 --- Added comments ---  uid28828 [Aug 10, 2011 11:32:21 AM CEST]
  CHANGE:                 Change Package : 54276:1 http://mks-psad:7002/im/viewissue?selection=54276
  CHANGE:                 Revision 1.18 2011/08/05 16:54:44CEST Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> city parameters tuning
  CHANGE:                 --- Added comments ---  uidt2765 [Aug 5, 2011 4:54:44 PM CEST]
  CHANGE:                 Change Package : 49560:1 http://mks-psad:7002/im/viewissue?selection=49560
  CHANGE:                 Revision 1.17 2011/08/03 16:54:06CEST Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> Add "City" detection with height assumption for critical scenarios
  CHANGE:                 --- Added comments ---  uidt2765 [Aug 3, 2011 4:54:07 PM CEST]
  CHANGE:                 Change Package : 49560:1 http://mks-psad:7002/im/viewissue?selection=49560
  CHANGE:                 Revision 1.16 2011/07/18 19:04:23CEST Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> add HLA_MAYBE_CITY state
  CHANGE:                 --- Added comments ---  uidt2765 [Jul 18, 2011 7:04:24 PM CEST]
  CHANGE:                 Change Package : 49560:1 http://mks-psad:7002/im/viewissue?selection=49560
  CHANGE:                 Revision 1.15 2011/07/13 17:17:53CEST Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> Add idle state to street lamp analysis
  CHANGE:                 --- Added comments ---  uidt2765 [Jul 13, 2011 5:17:53 PM CEST]
  CHANGE:                 Change Package : 49560:1 http://mks-psad:7002/im/viewissue?selection=49560
  CHANGE:                 Revision 1.14 2011/07/05 17:07:13CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGE:                 updated interface
  CHANGE:                 - fill environment data
  CHANGE:                 - use object list in hlaf
  CHANGE:                 --- Added comments ---  brunnm [Jul 5, 2011 5:07:13 PM CEST]
  CHANGE:                 Change Package : 49575:2 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGE:                 Revision 1.13 2011/06/21 16:14:23CEST Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> first integration of city detection
  CHANGE:                 --- Added comments ---  uidt2765 [Jun 21, 2011 4:14:23 PM CEST]
  CHANGE:                 Change Package : 49560:1 http://mks-psad:7002/im/viewissue?selection=49560
  CHANGE:                 Revision 1.12 2011/05/26 17:44:23CEST Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> Integrate street lamps analysis module
  CHANGE:                 -> Add 2D street lamps signature analysis
  CHANGE:                 --- Added comments ---  uidt2765 [May 26, 2011 5:44:24 PM CEST]
  CHANGE:                 Change Package : 49956:1 http://mks-psad:7002/im/viewissue?selection=49956
  CHANGE:                 Revision 1.11 2011/05/23 21:57:46CEST Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> Optimize street lamp analysis
  CHANGE:                 --- Added comments ---  uidt2765 [May 23, 2011 9:57:46 PM CEST]
  CHANGE:                 Change Package : 49956:1 http://mks-psad:7002/im/viewissue?selection=49956
  CHANGE:                 Revision 1.10 2011/05/23 19:48:30CEST Almeida Carlos (almeidac) (almeidac) 
  CHANGE:                 Adapted new identification model on all classifiers
  CHANGE:                 --- Added comments ---  almeidac [May 23, 2011 7:48:30 PM CEST]
  CHANGE:                 Change Package : 53530:1 http://mks-psad:7002/im/viewissue?selection=53530
  CHANGE:                 Revision 1.9 2011/05/23 14:02:53CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGE:                 - renamed seg_TracklistNode into HLATrack_t
  CHANGE:                 - renamed seg_ListNode into HLASegLight_t
  CHANGE:                 --- Added comments ---  brunnm [May 23, 2011 2:02:53 PM CEST]
  CHANGE:                 Change Package : 49575:1 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGE:                 Revision 1.8 2011/05/23 13:05:47CEST Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> Solve DWBT errors
  CHANGE:                 --- Added comments ---  uidt2765 [May 23, 2011 1:05:48 PM CEST]
  CHANGE:                 Change Package : 54240:1 http://mks-psad:7002/im/viewissue?selection=54240
  CHANGE:                 Revision 1.7 2011/05/09 17:05:11CEST Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> Solve MISRA rules
  CHANGE:                 --- Added comments ---  uidt2765 [May 9, 2011 5:05:12 PM CEST]
  CHANGE:                 Change Package : 54240:1 http://mks-psad:7002/im/viewissue?selection=54240
  CHANGE:                 Revision 1.6 2011/04/29 11:59:35CEST Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> MISRA Rules
  CHANGE:                 --- Added comments ---  uidt2765 [Apr 29, 2011 11:59:35 AM CEST]
  CHANGE:                 Change Package : 54240:1 http://mks-psad:7002/im/viewissue?selection=54240
  CHANGE:                 Revision 1.5 2011/04/29 11:41:38CEST Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> Highway detection less sensitive to occlusion
  CHANGE:                 -> Street Lamp detection more reactive to bad 3D position
  CHANGE:                 --- Added comments ---  uidt2765 [Apr 29, 2011 11:41:38 AM CEST]
  CHANGE:                 Change Package : 54240:1 http://mks-psad:7002/im/viewissue?selection=54240
  CHANGE:                 Revision 1.4 2011/04/21 11:54:51CEST Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> Add the result of identState_StreetLamp to HLAIdentificationPotentialVehicleOncoming
  CHANGE:                 -> Check MISRA rules
  CHANGE:                 --- Added comments ---  uidt2765 [Apr 21, 2011 11:56:13 AM CEST]
  CHANGE:                 Change Package : 49956:1 http://mks-psad:7002/im/viewissue?selection=49956
  CHANGE:                 Revision 1.3 2011/04/14 22:39:56CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGE:                 Golddust compiler: removed errors
  CHANGE:                 --- Added comments ---  brunnm [Apr 14, 2011 10:39:56 PM CEST]
  CHANGE:                 Change Package : 53526:1 http://mks-psad:7002/im/viewissue?selection=53526
  CHANGE:                 Revision 1.2 2011/04/14 19:01:20CEST Godreau Bertrand (uid28828) (uid28828) 
  CHANGE:                 3D tracking clean-up.
  CHANGE:                 Remove use of global variables.
  CHANGE:                 Set-up of an input/output/data archi
  CHANGE:                 --- Added comments ---  uid28828 [Apr 14, 2011 7:01:20 PM CEST]
  CHANGE:                 Change Package : 50618:1 http://mks-psad:7002/im/viewissue?selection=50618
  CHANGE:                 Revision 1.1 2011/04/14 15:41:36CEST Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
**************************************************************************** */

#include "hla_city.h"
#include <math.h>
#include <string.h>

#define USE_CITY_ICON 1

#ifdef PC_SIM
#include "param.h"
#endif
/*! Leaving street lamp struct used when clustering street lamps in city detection */
typedef struct 
{
  sint16 xw100;
  sint16 xwUnfiltered100;
  uint8 hasSceneStreetLampInCorridor;
  uint8 isInFrontVehicle;

  uint8 isShortRangeCrossed;
  uint8 isMiddleRangeCrossed;
} LeavingStreetLampToCluster_t;


static const ARRAY(uint8, 8, sumInd_city) = {1,3,6,10,15,21,28,36};

#ifdef PC_SIM
HLA_GLOBAL_STATIC ARRAY(uint16, HLA_CITY_NUM_STREETLAMP, table16b_city) = {1,2,4,8,16,32,64,128,256,512};

static void HLACitySLExclusionReason(const HLACityData_t *pCityData, HLATrack_t* pTLB_Start,const HLA_t_CityDetectionParameters * pParams, const RTE_HLAR_ParameterCity_t *pCityParams);
#endif

static void  HLACityAddLeavSL(HLACityData_t *pCityData, HLATrack_t* pTLB_Start);

static void  HLACityRemoveLeavSL(HLACityData_t *pCityData,HLA_City_ListNode_t*  pLeavSLToRemove);

static void HLACityUpdateLeavingSLList(/* Inputs */
                                       const HLACityInput_t *pIn,
                                       HLACityData_t *pCityData, 
                                       const HLA_t_CityDetectionParameters * pParams,
                                       const RTE_HLAR_ParameterCity_t      *pCityParams,
                                       /* Outputs */
                                       uint8 *pNumStreetLampTooCloseToTurnOn,
                                       uint8 *pNumSLCloseForMaybeUrban,
                                       uint8 *pNumSLCloseForMaybeUrban_LowInt,
                                       uint8 *pLeavingStreetLampActive,
                                       float32 *pRadius
                                       );

static void HLACityStreetLampClassesAnalysis(/* Inputs */
                                             const HLACityInput_t *pIn,
                                             HLACityData_t *pCityData, 
                                             const HLA_t_CityDetectionParameters * pParams,
                                             const RTE_HLAR_ParameterCity_t      *pCityParams,
                                             uint8 *pNumStreetLampTooCloseToTurnOn,
                                             uint8 *pNumSLCloseForMaybeUrban,
                                             uint8 *pNumSLCloseForMaybeUrban_LowInt,
                                             const float32 Radius,
                                             /* output */  
                                             const RTE_HLAR_CityState *peCityOutput,
                                             uint8 *pSceneStreetLampCount,
                                             uint8 *pSceneStreetLampLowIntCount
                                             );

static void HLACityIntensityFluxAnalysis(/* Inputs */
                                         HLATrack_t* pTLB,
                                         const HLACityInput_t *pIn,
                                         const sint16 MinYwDist100,
                                         const HLA_t_CityDetectionParameters * pParams,
                                         //const RTE_HLAR_ParameterCity_t      *pCityParams,
                                         /* Output */
                                         boolean *pHasHighIntensityFlux
                                         );
static void HLACityFarObjectAnalysis(HLATrack_t* pTLB,
                                     const HLA_t_CityDetectionParameters * pParams
                                     //const RTE_HLAR_ParameterCity_t      *pCityParams
                                    );

static void HLACityCheckLeavingStreetLamp(/* Inputs */
                                          const HLACityInput_t *pIn,
                                          HLATrack_t* pTLB,
                                          const uint16 maxXwDist100_3dEstLeav,
                                          const float32 LeavingSLdistance,
                                          const sint16    xwSL100,
                                          const sint16    ywSL100,
                                          const sint16    maxStreetLampY_LHD100,
                                          const sint16    maxStreetLampY_RHD100,
                                          HLACityData_t *pCityData, 
                                          const HLA_t_eMovementState e_MoveState,
                                          const uint16    maxYwDist100_3dEstLeav_Left_Curve,
                                          const uint16    maxYwDist100_3dEstLeav_Right_Curve,
                                          const uint16    maxYwDist100_3dEstLeav_Left_Intensity,
                                          const uint16    maxYwDist100_3dEstLeav_Right_Intensity,
                                          const uint16    maxYwDist100_3dEstLeav_Left_MaybeCity,
                                          const uint16    maxYwDist100_3dEstLeav_Right_MaybeCity
                                          );

static void HLACityCheckIconStreetLampDistanceToLeavingStreetLamp(const HLACityInput_t *pIn,
                                                                  const HLACityData_t *pCityData,
                                                                  const HLA_t_CityDetectionParameters * pParams,
                                                                  //const RTE_HLAR_ParameterCity_t      *pCityParams,
                                                                  uint8 *pIsAnyStreetLamp,
                                                                  uint8 *pIsAnyStreetLampLowInt
                                                           );

static void HLACitySceneStreetLampSignalStateMachine(    HLACityData_t *pCityData,
                                              const uint8 isAnyStreetLamp,
                                              const HLA_t_CityDetectionParameters * pParams
                                              //const RTE_HLAR_ParameterCity_t      *pCityParams
                                              );

static void HLACitySceneStreetLampLowIntSignalStateMachine( HLACityData_t *pCityData,
                                                    const uint8 isAnyStreetLampLowInt,
                                                    const HLA_t_CityDetectionParameters * pParams
                                                    //const RTE_HLAR_ParameterCity_t      *pCityParams
                                                    );

static void HLACityDetectionDecision(/* input */
                                     const HLACityInput_t *pIn,
                                     HLACityData_t *pCityData,
                                     const HLA_t_CityDetectionParameters * pParams,
                                     const RTE_HLAR_ParameterCity_t      *pCityParams,
                                     const uint8 numStreetLampTooCloseToTurnOn,
                                     const uint8 numSLCloseForMaybeUrban,
                                     const uint8 numSLCloseForMaybeUrban_LowInt,
                                     const uint8 SceneStreetLampLowIntCount,
                                     const float32 Radius);

static void HLACitySetOutput(const HLACityInput_t *pIn,
                             HLACityData_t *pCityData,
                             const HLA_t_CityDetectionParameters * pParams,
                             //const RTE_HLAR_ParameterCity_t      *pCityParams,
                             const uint8 numSLCloseForMaybeUrban,
                             const uint8 numSLCloseForMaybeUrban_LowInt,
                             RTE_HLAR_CityState *peCityOutput,
                             const uint8 SceneStreetLampLowIntCount);

static void HLACityAmbientAnalysis(const HLACityInput_t *pIn, 
                                   HLACityData_t *pCityData);

static float32 HLACityAverageFilter(float32 oldval,
                                    float32 luxsum,
                                    float32 coeff);

static float32 HLACityInterpolate(float32 x0, float32 x1, float32 y0, float32 y1, float32 xin);

/* **************************************************************************** 
  Functionname:     HLACityInit                              */ /*!  
  Description:      


  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Boris LUGEZ
**************************************************************************** */
void HLACityInit( HLACityData_t*      pCityData, 
                  RTE_HLAR_CityState* pCityState
                 )
{
  uint8 i;

  /* HLACityData_t hlaCityData */
  (void)memset((void*)pCityData, 0, sizeof(HLACityData_t));

  pCityData->internalCityState = RTE_HLAR_CITY_DTCD;
  pCityData->status.StreetLampSignal = 1;
  pCityData->status.StreetLampSignal_LowInt = 1;
  pCityData->numFrames = 0;
  pCityData->numConsecutiveStreetLampState = 0;
  pCityData->numConsecutiveStreetLampState_LowInt = 0;
  pCityData->status.InhibAtFirst = 1;
  pCityData->status.MaybeCity = 0;
  pCityData->pLeavSLBufferFree = &pCityData->hlaFreeLeavSLBuffer[0];
  pCityData->pLeavSLBuffer = 0;
  pCityData->distLeavSL100_NoMaybeLeavSL = SI16_T_MIN;
  pCityData->subimagesum = 0.0f;
  pCityData->IsAmbientLight.result = HLA_RESULT_IDLE;
  pCityData->IsAmbientLight.confidence = 0;
  pCityData->IsLowAmbientLight = 0;
  /* TooBright init */
  pCityData->TooBright.confidence = -31;
  pCityData->TooBright.result = HLA_RESULT_IDLE;

  (void)memset((void*)&pCityData->hlaFreeLeavSLBuffer[0],0,sizeof(HLA_City_ListNode_t)*HLA_CITY_NUM_STREETLAMP);
  for(i=0;i<(HLA_CITY_NUM_STREETLAMP-1);i++)
  {
    pCityData->hlaFreeLeavSLBuffer[i].next = &pCityData->hlaFreeLeavSLBuffer[i + 1];
  }

  pCityData->status.bInit = TRUE;

  pCityData->CityLuxSum[0] = 0;
  pCityData->CityLuxSum[1] = 0;
  pCityData->CityLuxSum[2] = 0;
  pCityData->CityLuxSum[3] = 0;
  pCityData->CityLuxSum[4] = 0;

#ifdef PC_SIM
  pCityData->eDetecion = 0;
#endif

  *pCityState = RTE_HLAR_CITY_UNKNOWN;
}
/* **************************************************************************** 
  Functionname:     hlaCity                                   */ /*!  
  Description:      


  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Boris LUGEZ
**************************************************************************** */
void HLACity( /* input */
              const HLACityInput_t *pIn,
              const HLA_t_CityDetectionParameters *pParams,
              const RTE_HLAR_ParameterCity_t      *pCityParams,
              /* history */
              HLACityData_t *pCityData,
              /* output */  
              RTE_HLAR_CityState *peCityOutput
            )
{
#ifdef PC_SIM
          pCityData->bCityEntry = FALSE;
          pCityData->bCityExit = FALSE;
#endif

  /*--- VARIABLES ---*/
  float32 Radius;
  uint8 isAnyStreetLamp = 0;
  uint8 isAnyStreetLampLowInt = 0;
  uint8 SceneStreetLampCount = 0;
  uint8 SceneStreetLampLowIntCount = 0;
  uint8 numStreetLampTooCloseToTurnOn = 0;
  uint8 numSLCloseForMaybeUrban = 0;
  uint8 numSLCloseForMaybeUrban_LowInt = 0;  
  uint8 LeavingStreetLampActive = (uint8) pCityData->status.InhibAtFirst;
  pCityData->subimagesum = 0.0f;
  
  if(     (pCityData->status.bInit == TRUE)
    /* if speed > approx. 25km/h at first frame reinitialize City internal state */
      &&  (pIn->pMotionData->f32_Speed > 7.0f) 
      )
  {
    pCityData->internalCityState = RTE_HLAR_CITY_NOT_DTCD;
  }
  pCityData->status.bInit = FALSE;

  HLACityUpdateLeavingSLList( pIn,
                              pCityData,
                              pParams,
                              pCityParams,
                              &numStreetLampTooCloseToTurnOn,
                              &numSLCloseForMaybeUrban,
                              &numSLCloseForMaybeUrban_LowInt,
                              &LeavingStreetLampActive,
                              &Radius);

  

  HLACityStreetLampClassesAnalysis(pIn,
                                  pCityData,
                                  pParams,
                                  pCityParams,
                                  &numStreetLampTooCloseToTurnOn,
                                  &numSLCloseForMaybeUrban,
                                  &numSLCloseForMaybeUrban_LowInt,
                                  Radius,
                                  peCityOutput,
                                  &SceneStreetLampCount,
                                  &SceneStreetLampLowIntCount);

  HLACityAmbientAnalysis(   pIn,
                            pCityData
                         );

  HLACityCheckIconStreetLampDistanceToLeavingStreetLamp(pIn,
                                                        pCityData,
                                                        pParams,
                                                        //pCityParams,
                                                        &isAnyStreetLamp,
                                                        &isAnyStreetLampLowInt);

  HLACitySceneStreetLampSignalStateMachine(pCityData,
                                           isAnyStreetLamp,
                                           pParams
                                           //pCityParams
                                           );

  HLACitySceneStreetLampLowIntSignalStateMachine(pCityData,
                                                 isAnyStreetLampLowInt,
                                                 pParams
                                                 //pCityParams
                                                );

#ifdef PC_SIM
  HLACitySLExclusionReason(pCityData,pIn->pTLB,pParams, pCityParams);
#endif

  HLACityDetectionDecision(pIn,
                          pCityData,
                          pParams,
                          pCityParams,
                          numStreetLampTooCloseToTurnOn,
                          numSLCloseForMaybeUrban,
                          numSLCloseForMaybeUrban_LowInt,
                          SceneStreetLampLowIntCount,
                          Radius);
  
  HLACitySetOutput(pIn,
                  pCityData,
                  pParams,
                  //pCityParams,
                  numSLCloseForMaybeUrban,
                  numSLCloseForMaybeUrban_LowInt,
                  peCityOutput,
                  SceneStreetLampLowIntCount);
}
/* **************************************************************************** 
  Functionname:     HLACityAddLeavSL                              */ /*!  
  Description:      Add Lights to free_LeavSL_buffer


  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Boris LUGEZ
**************************************************************************** */
static void  HLACityAddLeavSL(HLACityData_t *pCityData, HLATrack_t* pTLB_Start)
{
  /* local variable */
  HLA_City_ListNode_t*  pLeavSL;
  HLA_City_ListNode_t*  pLeavSL_Farest = 0;
  sint16                maxDist100 = SI16_T_MAX;

  /*  return current tracked_lights if maximum count reached */
  if( pCityData->pLeavSLBufferFree != 0 )
  {
    /* manage ROLLING BUFFER */
    /*  get next free Street Lamp */
    pLeavSL = pCityData->pLeavSLBufferFree;
    pCityData->pLeavSLBufferFree = pCityData->pLeavSLBufferFree->next;

    /* add new element as first element of analyzed street lamp list */
    pLeavSL->next = pCityData->pLeavSLBuffer;

    /* return analyzed street lamps */
    pCityData->pLeavSLBuffer = pLeavSL;

    /* Set pTLB_Start->pAssociatedLeavSL */
    pTLB_Start->pAssociatedLeavSL = pLeavSL;

    /* Reset pLeavList */
    pLeavSL->status.isBehind = 0;
    pLeavSL->status.isDecisiveForTurnOff1 = 0;
    pLeavSL->status.isDecisiveForTurnOff2 = 0;
    pLeavSL->numSceneStreetLampInSameCorridor = 0;
    pLeavSL->numBorderingStreetLamp = 0;
    pLeavSL->sumSL_y = 0;
    pLeavSL->sumsquareSL_y = 0;
    pLeavSL->sumSL_x = 0;
    pLeavSL->odometer = 0;
    pLeavSL->MinDistSceneSL100 = SI16_T_MAX;
    pLeavSL->xwUnfiltered100 = 0;
    pLeavSL->xwStraightRd100 = 0;
  }
  else
  {
    pLeavSL = pCityData->pLeavSLBuffer;
    while(pLeavSL != 0)
    {
      if(pLeavSL->xw100 < maxDist100)
      {
        pLeavSL_Farest = pLeavSL;
        maxDist100 = pLeavSL->xw100;
      }

      pLeavSL = pLeavSL->next;
    }

    if(pLeavSL_Farest != 0)
    {
        /* Set pTLB_Start->pAssociatedLeavSL */
      pTLB_Start->pAssociatedLeavSL = pLeavSL_Farest;
      
      /* Reset pLeavList */
      pLeavSL_Farest->status.isBehind = 0;
      pLeavSL_Farest->status.isDecisiveForTurnOff1 = 0;
      pLeavSL_Farest->status.isDecisiveForTurnOff2 = 0;
      pLeavSL_Farest->numSceneStreetLampInSameCorridor = 0;
      pLeavSL_Farest->numBorderingStreetLamp = 0;
      pLeavSL_Farest->sumSL_y = 0;
      pLeavSL_Farest->sumsquareSL_y = 0;
      pLeavSL_Farest->sumSL_x = 0;
      pLeavSL_Farest->odometer = 0;
      pLeavSL_Farest->MinDistSceneSL100 = SI16_T_MAX;
      pLeavSL_Farest->xwUnfiltered100 = 0;
      pLeavSL_Farest->xwStraightRd100 = 0;
    }
    else
    {
      pTLB_Start->pAssociatedLeavSL = 0;      
      pTLB_Start->statusAnalysisMisc.isLeavingStreetLamp = 0;
    }
  }
}
/* **************************************************************************** 
  Functionname:     HLACityRemoveLeavSL                              */ /*!  
  Description:      Remove Lights from free_LeavSL_buffer


  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Boris LUGEZ
**************************************************************************** */
static void  HLACityRemoveLeavSL(HLACityData_t *pCityData,HLA_City_ListNode_t*  pLeavSLToRemove)
{
  /* local variable */
  HLA_City_ListNode_t  *pLeavSL,*pLeavSL_next,*pLeavSL_prev;
  pLeavSL = pCityData->pLeavSLBuffer;
  pLeavSL_prev = 0;

  /* save previous leaving SL pointer in leaving SL list. */
  while(pLeavSL != 0)
  {
    if(pLeavSL->next == pLeavSLToRemove)
    {
      pLeavSL_prev = pLeavSL;
    }
    pLeavSL = pLeavSL->next;
  }

  /* save next leaving SL pointer in leaving SL list. */
  pLeavSL_next = pLeavSLToRemove->next;

  /* save the next-in-list SL to the previous SL. */
  if(pLeavSL_prev != 0)
  {
      pLeavSL_prev->next = pLeavSL_next;
  }
  else
  {
      pCityData->pLeavSLBuffer = pLeavSL_next;
  }

  /* add removed SL to the beginning of free SL list. */
  pLeavSLToRemove->next = pCityData->pLeavSLBufferFree;
  pCityData->pLeavSLBufferFree = pLeavSLToRemove;
}

#ifdef PC_SIM
/* **************************************************************************** 
  Functionname:     HLACitySLExclusionReason                              */ /*!  
  Description:      Debug infos on the exclusion reason for status:
                    - isSceneSL
                    - isSceneSL_Icon
                    - isLeavingSL
  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Boris LUGEZ
**************************************************************************** */
static void HLACitySLExclusionReason(const HLACityData_t *pCityData, HLATrack_t* pTLB_Start,const HLA_t_CityDetectionParameters * pParams, const RTE_HLAR_ParameterCity_t *pCityParams)
{
  HLATrack_t *pT = pTLB_Start;

  while(pT)
  {
    /* ********************************************************************** */
    /* ********************************************************************** */
    /* ********************************************************************** */
    if(pT->statusAnalysisMisc.isSceneStreetLamp == 1)
    {
      pT->eHLASceneSL = SCENESL_GOOD;
    }
    else if(pT->statusAnalysisMisc.isNOTLeavingStreetLamp == 1)
    {
      pT->eHLASceneSL = SCENESL_NOT_LEAVING;
    }
    else if(pT->bCitySceneSL_POS2D == 1)
    {
      pT->eHLASceneSL = SCENESL_POSITION_2D;
    }
    else if(!(pT->stageTrackStatic.trackTimeToReinit < 25) && !( pT->idResStat.isStreetLamp.result == HLA_RESULT_POSITIVE ) )
    {
      pT->eHLASceneSL = SCENESL_NOT_SL_IDRES;
    }    
    else if( !(pT->track_time>3) )
    {
      pT->eHLASceneSL = SCENESL_SHORT_TRACK_TIME;
    }
    else if( !(pT->RedLightCnt4City == 0) 
      || (!(pT->anaResStat.isOtherColor.result == HLA_RESULT_POSITIVE) && (pT->anaResStat.isWhiteOrRed.result == HLA_RESULT_NEGATIVE))
          )
    {
      pT->eHLASceneSL = SCENESL_RED_LIGHT;
    }    
    else if(             (pT->light_ref != NULL)
                &&  (pT->light_ref->pRegion != NULL)
                &&  ( (pT->light_ref->pRegion->x2 - pT->light_ref->pRegion->x1) < pParams->minSLsize)
                &&  ( (pT->light_ref->pRegion->y2 - pT->light_ref->pRegion->y1) < pParams->minSLsize)
                &&  ( pT->light_ref->pRegion->pRegionBelow == NULL )
              )
    {
      pT->eHLASceneSL = SCENESL_SKY_LIGHT;
    }
    else if( (pT->statusAnalysisVehicle.isVehicleAhead == TRUE)
          || (pT->statusAnalysisVehicle.isVehicleOncoming == TRUE)
          )
    {
      pT->eHLASceneSL = SCENESL_VEHICLE;
    }
    else if(pT->statusAnalysisMisc.isFarObject == TRUE)
    {
      pT->eHLASceneSL = SCENESL_ISFAROBJECT;
    }
    else if(pT->bCityMoveState == TRUE)
    {
      pT->eHLASceneSL = SCENESL_MOVING_BKWARD;
    }
    else if(pT->bCitySceneSL_POS3D == TRUE)
    {
      pT->eHLASceneSL = SCENESL_POSITION_3D;
    }
    else if(pT->isCityMoving == FALSE)
    {
      pT->eHLASceneSL = SCENESL_MOVING_DOWN;
    }
    else if(pT->bCitySceneSL_gap == TRUE)
    {
      pT->eHLASceneSL = SCENESL_LEAV_GAP;
    }
    else if( (pT->statusAnalysisMisc.isSceneStreetLamp == FALSE) && (pT->statusAnalysisMisc.isSceneStreetLampLowInt == TRUE) )
    {
      pT->eHLASceneSL = SCENESL_LOWINTENSITYFLUX;
    }
    else if(pT->statusAnalysisMisc.isLeavingStreetLamp == 1)
    {
      pT->eHLASceneSL = SCENESL_LEAVINGSL;
    }
  
    /* ********************************************************************** */
    /* ********************************************************************** */
    /* ********************************************************************** */
    if(pT->statusAnalysisMisc.isSceneStreetLampTunnel == 1) 
    {
      pT->eHLASceneSL_Tunnel = SCENESL_TUNNEL_GOOD;
    }
    else if(pT->statusAnalysisMisc.isBrigthSLS_Tunnel == 0)
    {
      pT->eHLASceneSL_Tunnel = SCENESL_TUNNEL_LOWINT;
    }
    else if(pT->statusAnalysisMisc.isConverging == FALSE)
    {
      pT->eHLASceneSL_Tunnel = SCENESL_TUNNEL_NOT_CONVERGING;
    }
    else if(pT->statusAnalysisMisc.isSceneStreetLamp == 0)
    {
      pT->eHLASceneSL_Tunnel = SCENESL_TUNNEL_NOT_SCENESL;
    }
    else if(pT->bCitySceneSL_TUNNEL_POS3D == TRUE)
    {
      pT->eHLASceneSL_Tunnel = SCENESL_TUNNEL_POSITION_3D;
    }
    else if(pT->bCitySceneSL_TUNNEL_POS2D == TRUE)
    {
      pT->eHLASceneSL_Tunnel = SCENESL_TUNNEL_POSITION_2D;
    }
  
    /* ********************************************************************** */
    /* ********************************************************************** */
    /* ********************************************************************** */
    if(pT->statusAnalysisMisc.isSceneStreetLampIcon == 1) 
    {
      pT->eHLASceneSL_Icon = SCENESL_ICON_GOOD;
    }
    else if(pT->statusAnalysisMisc.isSceneStreetLamp == 0)
    {
      pT->eHLASceneSL_Icon = SCENESL_ICON_NOT_SCENESL;
    }
    else if(pT->iconStateCity.classResultSum < pParams->minIconConf)
    {
      pT->eHLASceneSL_Icon = SCENESL_ICON_LOW_SCORE;
    }
    else if(pT->statusAnalysisMisc.isConverging == FALSE)
    {
      pT->eHLASceneSL_Icon = SCENESL_ICON_NOT_CONVERGING;
    }
    else if(pT->bCitySceneSL_gap == TRUE)
    {
      pT->eHLASceneSL_Icon = SCENESL_ICON_LEAV_GAP;
    }
    
    /* ********************************************************************** */
    /* ********************************************************************** */
    /* ********************************************************************** */
    if(pT->statusAnalysisMisc.isLeavingStreetLamp == 1)
    {
      pT->eHLALeavingSL = LEAVSL_GOOD;
    }
    else if( pT->statusAnalysisMisc.isSceneStreetLamp == 0 )
    {
      pT->eHLALeavingSL = LEAVSL_NOT_SCENESL;
    }
    else if(pT->bCityLeavSL_NotLeaving == 1)
    {
      pT->eHLALeavingSL = LEAVSL_NOT_LEAVING;
    }
    else if(pT->bCityLeavSL_POS3D)
    {
      pT->eHLALeavingSL = LEAVSL_POSITION_3D;
    }
    else if(pT->iconStateCity.classResultSum < -pParams->minIconConf)
    {
      pT->eHLALeavingSL = LEAVSL_ICON_LOW_SCORE;
    }

    /* Get next track */
    pT = pT->next;
  }
}
#endif

/* **************************************************************************** 
  Functionname:     HLACityUpdateLeavingSLList                             */ /*!  
  Description:      -
  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Boris LUGEZ, Alexander Fischer
**************************************************************************** */
static void HLACityUpdateLeavingSLList(/* Inputs */
                                       const HLACityInput_t *pIn,
                                       HLACityData_t *pCityData, 
                                       const HLA_t_CityDetectionParameters * pParams,
                                       const RTE_HLAR_ParameterCity_t      *pCityParams,
                                       /* Outputs */
                                       uint8 *pNumStreetLampTooCloseToTurnOn,
                                       uint8 *pNumSLCloseForMaybeUrban,
                                       uint8 *pNumSLCloseForMaybeUrban_LowInt,
                                       uint8 *pLeavingStreetLampActive,
                                       float32 *pRadius
                                )
{
    const float32  maxDistLastLeavingStreetLampExtended100 = pCityParams->LeavingCityDelaySceneStreetlamp_HighInt*100;
    /* Old implementation */
    //const uint16  maxDistLastLeavingStreetLamp100 = pParams->maxDistTurnOnDelay100*100;
    const uint16  maxDistLastLeavingStreetLamp100 = (uint16) HLACityInterpolate(pCityParams->SpeedThresholdLow, pCityParams->SpeedThresholdHigh, (pCityParams->LeavingCityDelay_LowSpeed*100), (pCityParams->LeavingCityDelay_HighSpeed*100), (pIn->pMotionData->f32_Speed));
    const float32  maxDistLastLS100_LowInt = pCityParams->LeavingCityDelaySceneStreetlamp_LowInt*100;
    /* Old implementation */
    //const uint16  maxDistInterStreetLamp100 = pParams->maxDistInterStreetLamp100*100;
    const uint16  maxDistInterStreetLamp100 = (uint16) HLACityInterpolate(pCityParams->SpeedThresholdLow, pCityParams->SpeedThresholdHigh, (pCityParams->StreetLampMaxInterDist_LowSpeed*100), (pCityParams->StreetLampMaxInterDist_HighSpeed*100), (pIn->pMotionData->f32_Speed));
    const float32  maxDistActiveLeavingStreetLamp100 = CML_MinMax((uint16)( (pCityParams->NumLeavingStreetlamp_HighSpeed-1)*maxDistInterStreetLamp100 ),(uint16)(SI16_T_MAX),maxDistLastLeavingStreetLampExtended100 + maxDistInterStreetLamp100);

    HLA_City_ListNode_t* pLeavList;
    HLA_City_ListNode_t* pLeavList2;



    HLA_t_eMovementState e_MoveState = pIn->pMotionData->e_MoveState;

    float32 cosa = 1.0f;
    float32 sina = 0.0f;
    float32 factor;
    float32 factorCurve = 1.0f;
    float32 factorAccel = 1.0f;

    sint16 txw100 = (sint16)(100.0f*pIn->pCamData->ddistFwd_m);
    sint16 tyw100 = 0;

    sint16 xw_temp100;
    sint16 yw_temp100;

    float32 MaxRadius = pParams->MaxRadius;

    /***********************************************/
    /* algebraic radius estimation */
    /***********************************************/
    (*pRadius) = 100000.0f;
    if(e_MoveState != HLA_MOVE_STATE_FWD)
    {
        (*pRadius) = 100000.0f;
        cosa = 0;
        sina = 0;
        txw100 = 0;
        tyw100 = 0;
    }
    else if (    ( (fabsf(pIn->pMotionData->f32_YawRate)-0.001f) > 0) 
        &&  ( (pIn->pMotionData->f32_Speed - 0.1f) > 0)
        )
    {
        (*pRadius) = pIn->pMotionData->f32_Speed/pIn->pMotionData->f32_YawRate;
        (*pRadius) = CML_f_MinMax(-100000.0f,100000.0f,(*pRadius));

        /* estimate transformation parameters from old cs to new cs */
        cosa = cosf( pIn->pCamData->ddistFwd_m / (*pRadius) );
        sina = sinf( pIn->pCamData->ddistFwd_m / (*pRadius) );

        txw100 =  (sint16)(100.0f*((*pRadius)*sina));
        tyw100 =  (sint16)(100.0f*((*pRadius)*(1 - cosa)));
    }
    else
    {
      /* Do nothing */
    }

    /* factor applied to distance counters when the vehicle is in a turn */
    if(pParams->minRadiusCityOff > 0)
    {
        factorCurve = 0.3f + ( ((1.0f-0.3f) / ( 2.0f * pParams->minRadiusCityOff ))*(fabsf((*pRadius)) - pParams->minRadiusCityOff) );
        factorCurve = CML_f_MinMax(0.3f, 1.0f, factorCurve);
    }

    /* factor applied to distance counters when the vehicle decelerating */
    if(     (pParams->CityAccelFactorMax > pParams->CityAccelFactorMin)
        &&  (pIn->pMotionData->f32_Speed > 1.0f)
        )
    {
        factorAccel = 0.3f + ( ((1.0f-0.3f) / ( pParams->CityAccelFactorMax - pParams->CityAccelFactorMin))*(pIn->pMotionData->f32_Acceleration - pParams->CityAccelFactorMin) );
        factorAccel = CML_f_MinMax(0.3f, 1.0f, factorAccel);
    }

    factor = CML_f_Min(factorCurve,factorAccel); /* factor not physical used in curve and acceleration/deceleration phase to solve city lost events */

#ifdef PC_SIM
    pCityData->filter = factor;
#endif

    /***********************************************/
    /*update distance with no NoMaybeLeavSL in the ROI */
    /***********************************************/
    pCityData->distLeavSL100_NoMaybeLeavSL = (sint16)( CML_f_Max((float32)(SI16_T_MIN),(float32)(pCityData->distLeavSL100_NoMaybeLeavSL) - ( (factor*pIn->pCamData->ddistFwd_m)*100.0f) ));

    /***********************************************/
    /*loop on leaving street lamp list */
    /***********************************************/
    pLeavList = pCityData->pLeavSLBuffer;
    while(pLeavList != 0)
    {
#ifdef PC_SIM
        /* reset flags used for visualization */
        pLeavList->status.isDecisiveForTurnOff1 = 0;
        pLeavList->status.isDecisiveForTurnOff2 = 0;
#endif

        /* reset corridor byte */
        pLeavList->numSceneStreetLampInSameCorridor  = 0;
        pLeavList->numBorderingStreetLamp = 0;
        pLeavList->sumSL_x = 0;
        pLeavList->sumSL_y = 0;
        pLeavList->sumsquareSL_y = 0;

        pCityData->status.InhibAtFirst = 0;

        pLeavList->MinDistSceneSL100 = SI16_T_MAX;

        /* see LSL that lies under maxDistLastLeavingStreetLampExtended*/
        (*pLeavingStreetLampActive) = (pLeavList->xw100 >= - maxDistLastLeavingStreetLampExtended100) ? 1:(*pLeavingStreetLampActive);

        if(e_MoveState != HLA_MOVE_STATE_FWD)
        {
            /* No Update */
        }
        else if( pLeavList->xw100 < 0 )  /* SL is behind vehicle */
        {
            /* update distance counter*/
            pLeavList->xw100 = (sint16)(CML_f_MinMax((float32)(SI16_T_MIN),(float32)(SI16_T_MAX),(float32)(pLeavList->xw100) - ((factor*pIn->pCamData->ddistFwd_m)*100.0f) ) );
        }
        else  /* vehicle hasn't cross the SL yet*/
        {
            /* update X,Y position */
            xw_temp100 = (sint16)( CML_f_MinMax((float32)(SI16_T_MIN),(float32)(SI16_T_MAX),(float32)(pLeavList->xw100 - txw100) ) );
            yw_temp100 = (sint16)( CML_f_MinMax((float32)(SI16_T_MIN),(float32)(SI16_T_MAX),(float32)(pLeavList->yw100 - tyw100) ) );
            pLeavList->xw100 = (sint16)(CML_f_MinMax((float32)(SI16_T_MIN),(float32)(SI16_T_MAX),(cosa*(xw_temp100)) + (sina*(yw_temp100)) ) );
            pLeavList->yw100 = (sint16)(CML_f_MinMax((float32)(SI16_T_MIN),(float32)(SI16_T_MAX),(-sina*(xw_temp100)) + (cosa*(yw_temp100)) ) );
        }

        pLeavList->xwUnfiltered100 = (sint16)(CML_f_MinMax((float32)(SI16_T_MIN),(float32)(SI16_T_MAX),(float32)(pLeavList->xwUnfiltered100) - (pIn->pCamData->ddistFwd_m*100.0f) ) );

        if(fabsf((*pRadius))>MaxRadius)
        {
            pLeavList->xwStraightRd100 = (sint16)(CML_f_MinMax((float32)(SI16_T_MIN),(float32)(SI16_T_MAX),(float32)(pLeavList->xwStraightRd100) - (pIn->pCamData->ddistFwd_m*100.0f) ) );
        }
        else
        {
            /* Do Nothing */
        }

        /* count SL that lies under maxDistLastLeavingStreetLamp*/
        (*pNumStreetLampTooCloseToTurnOn) = (*pNumStreetLampTooCloseToTurnOn) + (uint8)((pLeavList->xwStraightRd100>(-maxDistLastLeavingStreetLamp100))&& ( (pLeavList->xwUnfiltered100 > (-pParams->MaxDistToLeavCityInCurve100*100) ) || ( pLeavList->xw100>(-maxDistLastLeavingStreetLamp100) ) ) );

        /* count SL that lies under maxDistInterStreetLamp*/
        (*pNumSLCloseForMaybeUrban) = (*pNumSLCloseForMaybeUrban) + (uint8)(pLeavList->xw100 > -maxDistLastLeavingStreetLampExtended100);

        /* count SL that lies under maxDistInterStreetLamp*/
        (*pNumSLCloseForMaybeUrban_LowInt) = (*pNumSLCloseForMaybeUrban_LowInt) + (uint8)(pLeavList->xw100 > -maxDistLastLS100_LowInt);

        /* reset item if too far */
        if(pLeavList->xw100 <= - maxDistActiveLeavingStreetLamp100)
        {
            pLeavList2 = pLeavList->next;
            HLACityRemoveLeavSL(pCityData,pLeavList);
            pLeavList = pLeavList2;
        }
        else
        {
            pLeavList = pLeavList->next;
        }
    }
}

/* **************************************************************************** 
  Functionname:     HLACityStreetLampClassesAnalysis                             */ /*!  
  Description:      -
  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Boris LUGEZ, Alexander Fischer
**************************************************************************** */
static void HLACityStreetLampClassesAnalysis(/* Inputs */
                                             const HLACityInput_t *pIn,
                                             HLACityData_t *pCityData, 
                                             const HLA_t_CityDetectionParameters * pParams,
                                             const RTE_HLAR_ParameterCity_t      *pCityParams,
                                             uint8 *pNumStreetLampTooCloseToTurnOn,
                                             uint8 *pNumSLCloseForMaybeUrban,
                                             uint8 *pNumSLCloseForMaybeUrban_LowInt,
                                             const float32 Radius,
                                             /* output */  
                                             const RTE_HLAR_CityState *peCityOutput,
                                             uint8 *pSceneStreetLampCount,
                                             uint8 *pSceneStreetLampLowIntCount
                                             )
{
    const sint16 MinYwDist100 = (sint16)(pParams->MinYwDist100*100);
    const uint8 SafetyGapTop = pParams->SafetyGapTop;
    const uint8 SafetyGapSide = pParams->SafetyGapSide;
    /* Old Implementation */
    //const uint16  maxDistLastLeavingStreetLamp100 = pParams->maxDistTurnOnDelay100*100;
    const uint16  maxDistLastLeavingStreetLamp100 = (uint16) HLACityInterpolate(pCityParams->SpeedThresholdLow, pCityParams->SpeedThresholdHigh, (pCityParams->LeavingCityDelay_LowSpeed*100), (pCityParams->LeavingCityDelay_HighSpeed*100), (pIn->pMotionData->f32_Speed));
    const uint16  minDistInterStreetLampLeav100 = (uint16)(pParams->minDistTurnOffDelayLeav100*100);

    const float32 minRadiusDelatYw = pParams->minRadiusDelatYw;
    const float32 maxRadiusDelatYw = pParams->maxRadiusDelatYw;
    const float32 minDeltaYwCurve100 = pParams->minDeltaYwCurve100*100;
    const float32 maxDeltaYwCurve100 = pParams->maxDeltaYwCurve100*100;

    HLATrack_t* pTLB = pIn->pTLB;

    uint8 isNewLeaving;
    uint8 isNewLeaving_MaybeCity;

    boolean hasHighIntensityFlux;
    float32 horizonSafetyLX, horizonSafetyLY, horizonSafetyRX, horizonSafetyRY;
    float32 A, B, C; /* line equation: Ax + By + C = 0 */
    float32 d;

    float32 yb_L_f32;
    float32 yb_R_f32;
    float32 xb_L_f32;
    float32 xb_R_f32;

    float32 LeavingSLdistance;
    float32 HeightAssumpSL;

    float32  maxDistStreetLamp100;

    sint16 maxStreetLampY_RHD100;
    sint16 maxStreetLampY_LHD100;

    float32 tempf32;

    float32 minBrightness_lx = pParams->MinIntensityStreetLampUpperRoi;
    float32 minHighBrightness_lx = pParams->MinIntensityStreetLamp;
    float32 minBrightness_Tunnel_lx = pParams->MinIntensityStreetLampUpperRoi_Tunnel;
    float32 minHighBrightness_Tunnel_lx = pParams->MinIntensityStreetLamp_Tunnel;

    uint16 maxXwDist100_3dEstLeav;
    uint16 maxYwDist100_3dEstLeav_Left;
    uint16 maxYwDist100_3dEstLeav_Right;

    uint8 isCityMoving;
    
    float32 xw_f32;
    float32 yw_f32;

    sint16 xwSL100 = 0;
    sint16 ywSL100 = 0;

    HLA_t_eMovementState e_MoveState = pIn->pMotionData->e_MoveState;

    uint16 maxYwDist100_3dEstLeav_Left_Curve;
    uint16 maxYwDist100_3dEstLeav_Right_Curve;
    uint16 maxYwDist100_3dEstLeav_Left_Intensity;
    uint16 maxYwDist100_3dEstLeav_Right_Intensity;
    uint16 maxYwDist100_3dEstLeav_Left_MaybeCity = (uint16)(pParams->maxYwDist100_3dEstLeav_InCities*100);
    uint16 maxYwDist100_3dEstLeav_Right_MaybeCity = (uint16)(pParams->maxYwDist100_3dEstLeav_InCities*100);

    sint16 xb_temp;
    sint16 yb_temp;

    uint8 isLeavingSide;
    uint8 isLeavingTop;

    uint16  RoiX1 = pIn->pCamData->RoiX1;
    uint16  RoiX2 = pIn->pCamData->RoiX2;

    HLA_City_ListNode_t* pLeavList;

    sint16 xw_temp100;
    sint16 yw_temp100;

    uint16 DeltaYwCurve100;


    /***********************************************/
    /* parameters setting */
    /***********************************************/
    /* Set allowed lateral distance for scene street lamps and leaving street lamps according to traffic style and city state */
    if(pCityData->internalCityState == RTE_HLAR_CITY_DTCD)/* In city we allow the maximal lateral distance in order to avoid city lost */
    {
        maxStreetLampY_LHD100 = (sint16)(pParams->maxStreetLampY_Wide100*100);
        maxStreetLampY_RHD100 = -(sint16)(pParams->maxStreetLampY_Wide100*100);
        maxYwDist100_3dEstLeav_Left = (uint16)(pParams->maxYwDist100_3dEstLeav_InCities*100);
        maxYwDist100_3dEstLeav_Right = (uint16)(pParams->maxYwDist100_3dEstLeav_InCities*100);
    }
    else if(*pIn->pTrafficStyle == RTE_HLA_TRAFFIC_STYLE_RHD)/* extra lateral distance allowed for the opposite side of current traffic hand */
    {
        maxStreetLampY_LHD100 = (sint16)(pParams->maxStreetLampY_Wide100*100);
        maxStreetLampY_RHD100 = -(sint16)(pParams->maxStreetLampY_Narrow100*100);
        maxYwDist100_3dEstLeav_Left = (uint16)(pParams->maxYwDist100_3dEstLeav_Wide*100);
        maxYwDist100_3dEstLeav_Right = (uint16)(pParams->maxYwDist100_3dEstLeav_Narrow*100);
    }
    else if(*pIn->pTrafficStyle == RTE_HLA_TRAFFIC_STYLE_LHD)/* extra lateral distance allowed for the opposite side of current traffic hand */
    {
        maxStreetLampY_LHD100 = (sint16)(pParams->maxStreetLampY_Narrow100*100);
        maxStreetLampY_RHD100 = -(sint16)(pParams->maxStreetLampY_Wide100*100);
        maxYwDist100_3dEstLeav_Left = (uint16)(pParams->maxYwDist100_3dEstLeav_Narrow*100);
        maxYwDist100_3dEstLeav_Right = (uint16)(pParams->maxYwDist100_3dEstLeav_Wide*100);
    }
    else
    {
        maxStreetLampY_LHD100 = (sint16)(pParams->maxStreetLampY_Wide100*100);
        maxStreetLampY_RHD100 = -(sint16)(pParams->maxStreetLampY_Wide100*100);
        maxYwDist100_3dEstLeav_Left = (uint16)(pParams->maxYwDist100_3dEstLeav_Wide*100);
        maxYwDist100_3dEstLeav_Right = (uint16)(pParams->maxYwDist100_3dEstLeav_Wide*100);
    }

    /* Set HeightAssumpSL_variable */
    if(     (pIn->pMotionData->f32_Speed < (pCityParams->SpeedThresholdLow) /*pParams->minSpeedHeightAssumpSL*/)
        ||  (*peCityOutput == RTE_HLAR_CITY_DTCD)
        )
    {
        HeightAssumpSL = pParams->minHeightAssumpSL;
        LeavingSLdistance = pParams->minLeavingSLdistance;
        //maxDistStreetLamp100 = pParams->mindistStreetLamp100*100;
        maxDistStreetLamp100 = (pCityParams->StreetLampMaxDist_LowSpeed*100);
    }
    else if(pIn->pMotionData->f32_Speed > (pCityParams->SpeedThresholdHigh) /*pParams->maxSpeedHeightAssumpSL*/)
    {
        HeightAssumpSL = pParams->maxHeightAssumpSL;
        LeavingSLdistance = pParams->maxLeavingSLdistance;
        //maxDistStreetLamp100 = pParams->maxdistStreetLamp100;
        maxDistStreetLamp100 = (pCityParams->StreetLampMaxDist_HighSpeed*100);
    }
    else
    {
        /* Old Implementation */
        //tempf32 = (pIn->pMotionData->f32_Speed - pParams->minSpeedHeightAssumpSL)/(pParams->maxSpeedHeightAssumpSL - pParams->minSpeedHeightAssumpSL) ;
        tempf32 = (pIn->pMotionData->f32_Speed - (pCityParams->SpeedThresholdLow))/((pCityParams->SpeedThresholdHigh) - (pCityParams->SpeedThresholdLow)) ;
        HeightAssumpSL = ( (pParams->maxHeightAssumpSL - pParams->minHeightAssumpSL) * tempf32 ) + pParams->minHeightAssumpSL;
        LeavingSLdistance = ( (pParams->maxLeavingSLdistance - pParams->minLeavingSLdistance) * tempf32 ) + pParams->minLeavingSLdistance;
        //maxDistStreetLamp100 = ( (pParams->maxdistStreetLamp100*100 - pParams->mindistStreetLamp100) * tempf32 ) + pParams->mindistStreetLamp100*100;
        maxDistStreetLamp100 = ( ((pCityParams->StreetLampMaxDist_HighSpeed*100) - (pCityParams->StreetLampMaxDist_LowSpeed*100)) * tempf32 ) + (pCityParams->StreetLampMaxDist_LowSpeed*100);
    }

#ifdef PC_SIM
    pCityData->HeightAssumpSL = HeightAssumpSL;
    pCityData->LeavingSLdistance = LeavingSLdistance;
    pCityData->maxDistStreetLamp100 = maxDistStreetLamp100;
#endif

    /***********************************************/
    /* Horizon line parameters */
    /***********************************************/
    /* get image position for a leaving street lamp */
    HLACamRotGetXb(pIn->pCamRot, &xb_L_f32, &yb_L_f32, LeavingSLdistance, 15.0f, HeightAssumpSL);
    HLACamRotGetXb(pIn->pCamRot, &xb_R_f32, &yb_R_f32, LeavingSLdistance, -15.0f, HeightAssumpSL);

    /* get safety line for horizon in image */
    HLACamRotGetXb(pIn->pCamRot, &horizonSafetyLX, &horizonSafetyLY, 5000.0f, 500.0f, 0.0f);
    HLACamRotGetXb(pIn->pCamRot, &horizonSafetyRX, &horizonSafetyRY, 5000.0f, -500.0f, 0.0f);
    horizonSafetyLY -= (float32)(5.0f); /* SafetyGap pix above horizon */
    horizonSafetyRY -= (float32)(5.0f); /* SafetyGap pix above horizon */

    /* set parameters of line equation */
    A = (horizonSafetyRY - horizonSafetyLY) / (horizonSafetyRX - horizonSafetyLX);
    B = -1;
    C = ((horizonSafetyLX * (horizonSafetyLY - horizonSafetyRY)) / (horizonSafetyRX - horizonSafetyLX)) + horizonSafetyLY;

    /* brightness threshold */  
    minHighBrightness_lx = (fabsf(Radius) < 300.0f) ? (minHighBrightness_lx - 100.0f) : minHighBrightness_lx;

    /* DeltaYwCurve100 calculation : extra lateral gap calculation for curvy roads */
    maxYwDist100_3dEstLeav_Left_Curve = maxYwDist100_3dEstLeav_Left;
    maxYwDist100_3dEstLeav_Right_Curve = maxYwDist100_3dEstLeav_Right;

    if(fabsf(Radius) > maxRadiusDelatYw)
    {
        DeltaYwCurve100 = (uint16)(minDeltaYwCurve100);
    }
    else if(fabsf(Radius) < minRadiusDelatYw)
    {
        DeltaYwCurve100 = (uint16)(maxDeltaYwCurve100);
    }
    else
    {
        DeltaYwCurve100 = (uint16)( maxDeltaYwCurve100 + ( ( (minDeltaYwCurve100 - maxDeltaYwCurve100) / (maxRadiusDelatYw - minRadiusDelatYw) ) * (fabsf(Radius) - minRadiusDelatYw) ) );
    }

    if(Radius > 0)
    {
        maxYwDist100_3dEstLeav_Left_Curve += DeltaYwCurve100;    
        maxYwDist100_3dEstLeav_Left_MaybeCity += DeltaYwCurve100;
    }
    else
    {
        maxYwDist100_3dEstLeav_Right_Curve += DeltaYwCurve100;  
        maxYwDist100_3dEstLeav_Right_MaybeCity += DeltaYwCurve100;
    }

    maxXwDist100_3dEstLeav = (uint16)(pParams->maxXwDist100_3dEstLeav*100);

    /* fixed extra gap for street lamp with high intensity flux */
    maxYwDist100_3dEstLeav_Left_Intensity = maxYwDist100_3dEstLeav_Left + (uint16)(pParams->HighIntensityExtraGap100*100);
    maxYwDist100_3dEstLeav_Right_Intensity = maxYwDist100_3dEstLeav_Right + (uint16)(pParams->HighIntensityExtraGap100*100);

#ifdef PC_SIM
    pCityData->maxYwDist_3dEstLeav_Left = 0.01f*maxYwDist100_3dEstLeav_Left_Curve;
    pCityData->maxYwDist_3dEstLeav_Right = 0.01f*maxYwDist100_3dEstLeav_Right_Curve;
    pCityData->Radius = Radius;
#endif

  /***********************************************/
  /***********************************************/
      /* First Loop: 
                      1. Set isSceneStreetLamp flag
                      2. Set isNewLeaving flag 
                      3. Create new entry in leaving list
                      */
  /***********************************************/
  /***********************************************/
  while (pTLB != NULL)
  {
    
#ifdef PC_SIM
    pTLB->bCitySceneSL_gap = FALSE;
    pTLB->bCityLeavSL_POS3D = FALSE;
    pTLB->bCityLeavSL_NotLeaving = FALSE;
    pTLB->bCitySceneSL_POS2D = FALSE;
    pTLB->bCitySceneSL_POS3D = FALSE;
    pTLB->bCityMoveState = FALSE;
    pTLB->bCityLeavSL_NotLeaving = FALSE;
    pTLB->bCitySceneSL_TUNNEL_POS2D = FALSE;
    pTLB->bCitySceneSL_TUNNEL_POS3D = FALSE;
#endif
    /*reset flags */
    isNewLeaving = 0;
    isNewLeaving_MaybeCity = 0;
    pTLB->statusAnalysisMisc.isSceneStreetLamp = 0;
    pTLB->statusAnalysisMisc.isSceneStreetLampLowInt = 0;
    pTLB->statusAnalysisMisc.isSceneStreetLampIcon = 0;
    pTLB->statusAnalysisMisc.isSceneStreetLampTunnel = 0;

    HLACityIntensityFluxAnalysis(pTLB,
                                pIn,
                                MinYwDist100,
                                pParams,
                                //pCityParams,
                                &hasHighIntensityFlux
                                );

    HLACityFarObjectAnalysis(pTLB,
                             pParams
                             //pCityParams
                            );

/************************************************************/
    /* check distance to horizon safety line */
    d = (A * pTLB->xcenter) + ((B * pTLB->ycenter) + C);

    /* IS the track bright enough to be a scene street lamp? no => Low intensity scene street lamp */
    if(pTLB->ycenter < (sint16)(pIn->pCamData->RoiYu) )
    {
      pTLB->statusAnalysisMisc.isBrigthSLS = (uint8) ( (pTLB->statusAnalysisMisc.isBrigthSLS == TRUE) || (pTLB->MaxInt >= minBrightness_lx) );
    }
    else
    {
      pTLB->statusAnalysisMisc.isBrigthSLS = (uint8) ( (pTLB->statusAnalysisMisc.isBrigthSLS == TRUE) || (pTLB->MaxInt >= minHighBrightness_lx) );
      pTLB->statusAnalysisMisc.isBrigthSLS = (uint8) ( (pTLB->statusAnalysisMisc.isBrigthSLS == TRUE) && (pTLB->MaxInt >= minBrightness_lx) );
    }
    /* appareance criteria */
    if(pTLB->ycenter < (sint16)(pIn->pCamData->RoiYu) )
    {
      pTLB->statusAnalysisMisc.isBrigthSLS_Tunnel = (uint8) ( (pTLB->statusAnalysisMisc.isBrigthSLS_Tunnel == TRUE) || (pTLB->MaxInt >= minBrightness_Tunnel_lx) );
    }
    else
    {
      pTLB->statusAnalysisMisc.isBrigthSLS_Tunnel = (uint8) ( (pTLB->statusAnalysisMisc.isBrigthSLS_Tunnel == TRUE) || (pTLB->MaxInt >= minHighBrightness_Tunnel_lx) );
      pTLB->statusAnalysisMisc.isBrigthSLS_Tunnel = (uint8) ( (pTLB->statusAnalysisMisc.isBrigthSLS_Tunnel == TRUE) && (pTLB->MaxInt >= minBrightness_Tunnel_lx) );
    }

    /* moving criterion: moving upward? */
    /* J.Häfer: No Possible Side Effect */
    /* PRQA S 3415 2 */
    isCityMoving = (uint8) (    (    (CML_f_IsNonZero(pTLB->delta_x_lp)) 
                                  || (CML_f_IsNonZero(pTLB->delta_y_lp))
                                ) 
                             && (pTLB->delta_y_lp_lt < 0)
                           );

#ifdef PC_SIM
    pTLB->isCityMoving = isCityMoving;
#endif

    /* get world coordinate of current light with tracking informations */
    HLACamRotGetXwZ(pIn->pCamRot,&xw_f32,&yw_f32,HeightAssumpSL,(float32)(pTLB->xcenter),(float32)(pTLB->ycenter));
    xwSL100 = (sint16)(CML_f_MinMax((float32)(SI16_T_MIN),(float32)(SI16_T_MAX),100.0f*xw_f32) );
    ywSL100 = (sint16)(CML_f_MinMax((float32)(SI16_T_MIN),(float32)(SI16_T_MAX),100.0f*yw_f32) );

    /* Check already leaving street lamp to remove them from the list if necessary */
    HLACityCheckLeavingStreetLamp(  pIn,
                                    pTLB,
                                    maxXwDist100_3dEstLeav,
                                    LeavingSLdistance,
                                    xwSL100,
                                    ywSL100,
                                    maxStreetLampY_LHD100,
                                    maxStreetLampY_RHD100,
                                    pCityData, 
                                    e_MoveState,
                                    maxYwDist100_3dEstLeav_Left_Curve,
                                    maxYwDist100_3dEstLeav_Right_Curve,
                                    maxYwDist100_3dEstLeav_Left_Intensity,
                                    maxYwDist100_3dEstLeav_Right_Intensity,
                                    maxYwDist100_3dEstLeav_Left_MaybeCity,
                                    maxYwDist100_3dEstLeav_Right_MaybeCity
                                    );


/************************************************************
    Set isSceneStreetLamp flag
************************************************************/
    if(/* Only if it is not a leaving SL */  
              (((pTLB->statusAnalysisMisc).isLeavingStreetLamp) == FALSE) 
          /* Check the 2d position to horizon */   
          &&  (d > 0)
          /* only if it is moving */
          &&  (isCityMoving == TRUE)
          /* is associated to a light */
          &&  (pTLB->light_ref != 0)
          /* 3d potentially uncorrect */
          &&  (    ((pTLB->stageTrackStatic.trackTimeToReinit) < 25) 
                || ((pTLB->idResStat.isStreetLamp.result) == HLA_RESULT_POSITIVE ) /* isStreetLamp.result from analysisstreetlamps */
              ) 
          /* Minimum track Time */
          && (pTLB->track_time > 3)

          /* Filter Red tracks */
          && (pTLB->RedLightCnt4City == 0) 
          && (!(   !(pTLB->anaResStat.isOtherColor.result == HLA_RESULT_POSITIVE) 
                &&  (pTLB->anaResStat.isWhiteOrRed.result == HLA_RESULT_NEGATIVE)
                )
             )

          /* Filter already deleted leaving street lamp */
          &&  (pTLB->statusAnalysisMisc.isNOTLeavingStreetLamp == 0)

          /* Filter particular light */
          && (!(
                     (pTLB->light_ref != NULL)
                 &&  (pTLB->light_ref->pRegion != NULL)
                 &&  ( (pTLB->light_ref->pRegion->x2 - pTLB->light_ref->pRegion->x1) < pParams->minSLsize)
                 &&  ( (pTLB->light_ref->pRegion->y2 - pTLB->light_ref->pRegion->y1) < pParams->minSLsize)
                 &&  ( pTLB->light_ref->pRegion->pRegionBelow == NULL )
             ) )

          /* Filter bad tracks 3d tracking */
          && (pTLB->xwmin100 <= (pParams->maxXwDist100_3dEst*100))
          && (pTLB->ywmin100 < (pParams->maxYwDist100_3dEst*100))
          && (pTLB->ywmax100 > (-(pParams->maxYwDist100_3dEst*100)))

          /* Filter vehicles */
          && (pTLB->statusAnalysisVehicle.isVehicleAhead == FALSE)
          && (pTLB->statusAnalysisVehicle.isVehicleOncoming == FALSE)
          
          /* Filter far object */
          && ((pTLB->statusAnalysisMisc.isFarObject) == FALSE)

          /* Ensure to go forward */
          && (e_MoveState == HLA_MOVE_STATE_FWD)

          /* Set Death Area */
          && (!(    (fabsf((float32)pTLB->xwmax100) < (pParams->DeathAreaX * 100))
                 && (fabsf((float32)pTLB->ywmax100) < (pParams->DeathAreaY * 100))
                 && (fabsf((float32)pTLB->zwmax100) < (pParams->DeathAreaZ * 100))
             ) )
      )
    {
      if(     (xwSL100 > 0) 
          &&  (xwSL100 < maxDistStreetLamp100) 
          &&  (ywSL100 > maxStreetLampY_RHD100) 
          &&  (ywSL100 < maxStreetLampY_LHD100) 
          &&  (pTLB->statusAnalysisMisc.isBrigthSLS==TRUE)
        )
      {
        pTLB->statusAnalysisMisc.isSceneStreetLamp = TRUE;
        (*pSceneStreetLampCount)++;
      }  

      if(     (xwSL100 > 0) 
          &&  (xwSL100 < maxDistStreetLamp100) 
          &&  (ywSL100 > maxStreetLampY_RHD100) 
          &&  (ywSL100 < maxStreetLampY_LHD100) 
          )
      {
        pTLB->statusAnalysisMisc.isSceneStreetLampLowInt = TRUE;
        (*pSceneStreetLampLowIntCount)++;
      }
    }

    HLACamRotGetXwZ(pIn->pCamRot,&xw_f32,&yw_f32,pParams->minHeightAssumpSL,(float32)(pTLB->xcenter),(float32)(pTLB->ycenter));
    xwSL100 = (sint16)(CML_f_MinMax((float32)(SI16_T_MIN),(float32)(SI16_T_MAX),100.0f*xw_f32) );
    ywSL100 = (sint16)(CML_f_MinMax((float32)(SI16_T_MIN),(float32)(SI16_T_MAX),100.0f*yw_f32) );

/************************************************************/
    if(       (pTLB->statusAnalysisMisc.isSceneStreetLampLowInt == TRUE)
          /* Filter bad tracks 3d tracking */
          &&  (pTLB->xwmin100 <= (pParams->maxXwDist100_3dEst_Tunnel*100))
          &&  (pTLB->ywmin100 < (pParams->maxYwDist100_3dEst_Tunnel*100))
          &&  (pTLB->ywmax100 > -(pParams->maxYwDist100_3dEst_Tunnel*100))
          /* Filter bad tracks 2d */
          &&  (xwSL100>0) 
          &&  (xwSL100<maxDistStreetLamp100) 
          &&  (ywSL100 > -(pParams->maxStreetLampY_Tunnel100*100)) 
          &&  (ywSL100 < (pParams->maxStreetLampY_Tunnel100*100)) 
          /* Filter too low intensity tracks */
          &&  (pTLB->statusAnalysisMisc.isBrigthSLS_Tunnel==TRUE)
          /* Filter not converging tracks */
          &&  (pTLB->statusAnalysisMisc.isConverging == TRUE)
        )
    {
      pTLB->statusAnalysisMisc.isSceneStreetLampTunnel = TRUE;
    }
    
#ifdef PC_SIM
    if(d <= 0)
    {
      pTLB->bCitySceneSL_POS2D = TRUE;
    }

    if(     !(pTLB->xwmin100 <= pParams->maxXwDist100_3dEst*100)
        ||  !(pTLB->ywmin100 < pParams->maxYwDist100_3dEst*100)
        ||  !(pTLB->ywmax100 > -pParams->maxYwDist100_3dEst*100)
      )
    {
      pTLB->bCitySceneSL_POS3D = TRUE;
    }

    if(e_MoveState != HLA_MOVE_STATE_FWD)
    {
      pTLB->bCityMoveState = TRUE;
    }
    if(       !(xwSL100>0) 
          ||  !(xwSL100<maxDistStreetLamp100) 
          ||  !(ywSL100 > -pParams->maxStreetLampY_Tunnel100*100) 
          ||  !(ywSL100 < pParams->maxStreetLampY_Tunnel100*100) 
          )
    {
      pTLB->bCitySceneSL_TUNNEL_POS2D = TRUE;
    }

    if(       !(pTLB->xwmin100 <= pParams->maxXwDist100_3dEst_Tunnel*100)
          ||  !(pTLB->ywmin100 < pParams->maxYwDist100_3dEst_Tunnel*100)
          ||  !(pTLB->ywmax100 > -pParams->maxYwDist100_3dEst_Tunnel*100)
      )
    {
      pTLB->bCitySceneSL_TUNNEL_POS3D = TRUE;
    }

    pTLB->xwSL = 0.01f*xwSL100;
    pTLB->ywSL = 0.01f*ywSL100;
#endif


/************************************************************
    Set isNewLeaving flag
************************************************************/
    if(pTLB->statusAnalysisMisc.isSceneStreetLamp == TRUE)
    {
      xb_temp = (sint16)( CML_MinMax(SI16_T_MIN, SI16_T_MAX, CML_s_Round2Int( (pTLB->ox_p * pIn->ps_HLAR_In->s_Par.s_CameraParameter.s_FocalLength.f32_x) +  (pIn->ps_HLAR_In->s_Par.s_CameraParameter.s_LensCenter.f32_x) ) ) );
      yb_temp = (sint16)( CML_MinMax(SI16_T_MIN, SI16_T_MAX, CML_s_Round2Int( (pTLB->oy_p * pIn->ps_HLAR_In->s_Par.s_CameraParameter.s_FocalLength.f32_y) +  (pIn->ps_HLAR_In->s_Par.s_CameraParameter.s_LensCenter.f32_y) ) ) );

      /* if prediction is outside image edges, we have a leaving street lamp*/
      isLeavingSide = (uint8) (   ( ( (xb_temp - ( RoiX1 + SafetyGapSide ) ) <= 0 ) && (pTLB->delta_x_lp <= 0)/* check that track goes outward of ROI */ )
                               || ( ( (xb_temp - ( RoiX2 - SafetyGapSide ) ) >= 0 ) && (pTLB->delta_x_lp >= 0)/* check that track goes outward of ROI */ )
                               );

      isLeavingTop = (uint8) (  (       ( ( ( (xb_temp - xb_L_f32) * (yb_R_f32 - yb_L_f32) ) - ( (yb_temp - yb_L_f32) * (xb_R_f32 - xb_L_f32) ) ) >= 0 )
                                    ||  ( yb_temp <= (sint16)(pIn->pCamData->RoiY1 + SafetyGapTop) )
                                )
                                && (pTLB->delta_y_lp_lt < -0.1f)
                                );

      if(pTLB->statusAnalysisMisc.isSceneStreetLamp == TRUE)
      {
#if( USE_CITY_ICON == 1 )
        isNewLeaving = (uint8) (    ( (isLeavingSide == TRUE) || (isLeavingTop == TRUE) ) 
                        &&  (pTLB->xwmin100 < maxXwDist100_3dEstLeav) 
                        &&  ( (pTLB->ywmin100 < maxYwDist100_3dEstLeav_Left_Curve) || ((pTLB->ywmin100 < maxYwDist100_3dEstLeav_Left_Intensity)&&(pTLB->idResStat.hasHighIntensityFlux.result == HLA_RESULT_POSITIVE)) )
                        &&  ( (pTLB->ywmax100 > -maxYwDist100_3dEstLeav_Right_Curve)  || ((pTLB->ywmax100 > -maxYwDist100_3dEstLeav_Right_Intensity )&&(pTLB->idResStat.hasHighIntensityFlux.result == HLA_RESULT_POSITIVE)) )
                        /* Must be at least the min height assumption of a SL */
                        &&    (pTLB->zwmax100 >= (pParams->minHeightAssumpSL*100))
                        /* Don't take into account track classified as NONE SL */
                        &&  (pTLB->iconStateCity.classResultSum >= -pParams->minIconConf)
                        );

        isNewLeaving_MaybeCity = (uint8) (    ( (isLeavingSide == TRUE) || (isLeavingTop == TRUE) ) 
                                &&  (pTLB->xwmin100 < maxXwDist100_3dEstLeav) 
                                &&  (pTLB->ywmin100 < maxYwDist100_3dEstLeav_Left_MaybeCity ) 
                                &&  (pTLB->ywmax100 > -maxYwDist100_3dEstLeav_Right_MaybeCity )
                                /* Don't take into account track classified as NONE SL */
                                &&  (pTLB->iconStateCity.classResultSum >= -pParams->minIconConf)
                                );
      }

      if(     (pTLB->statusAnalysisMisc.isConverging == TRUE)
          &&  (pTLB->iconStateCity.classResultSum >= pParams->minIconConf)
          )
      {
        pTLB->statusAnalysisMisc.isSceneStreetLampIcon = TRUE;
      }

#ifdef PC_SIM
      if(     !(pTLB->xwmin100 < maxXwDist100_3dEstLeav)
          ||  !( (pTLB->ywmin100 < maxYwDist100_3dEstLeav_Left_Curve) || ((pTLB->ywmin100 < maxYwDist100_3dEstLeav_Left_Intensity)&&(pTLB->idResStat.hasHighIntensityFlux.result == HLA_RESULT_POSITIVE)) )
          ||  !( (pTLB->ywmax100 > -maxYwDist100_3dEstLeav_Right_Curve)  || ((pTLB->ywmax100 > -maxYwDist100_3dEstLeav_Right_Intensity )&&(pTLB->idResStat.hasHighIntensityFlux.result == HLA_RESULT_POSITIVE)) )
         )
      {
        pTLB->bCityLeavSL_POS3D = TRUE;
      }

      if( (isLeavingSide == FALSE) && (isLeavingTop == FALSE) )
      {
        pTLB->bCityLeavSL_NotLeaving = TRUE;
      }
#endif
#else
        isNewLeaving = (    ( (isLeavingSide == TRUE) || (isLeavingTop == TRUE) ) 
                        &&  (pTLB->xwmin100 < maxXwDist100_3dEstLeav) 
                        &&  (pTLB->ywmin100 < maxYwDist100_3dEstLeav) 
                        &&  (pTLB->ywmax100 > -maxYwDist100_3dEstLeav) 
                        );
      }
      if(pTLB->statusAnalysisMisc.isConverging == TRUE)
      {
        pTLB->statusAnalysisMisc.isSceneStreetLampIcon = TRUE;
      }
#endif 

/************************************************************
   Check new leaving not too close to a already leaving SL
************************************************************/
      pLeavList = pCityData->pLeavSLBuffer;

      while(pLeavList != 0)
      {  
        if( pLeavList->xw100 > (-maxDistLastLeavingStreetLamp100) )
        {
          xw_temp100 = ( xwSL100 - pLeavList->xw100); 
          yw_temp100 = (sint16)(fabsf((float32)(pLeavList->yw100 - ywSL100)));
          
          /* check if detected leaving street lamp is not too close from any leaving street lamp in the list */
          if(       (yw_temp100 < (pParams->sizeCorridor100*100)) /* item must be in same corridor */
                &&  (xw_temp100 < minDistInterStreetLampLeav100) /* interdistance must be superior to  minDistInterStreetLamp*/
               )
          {
            isNewLeaving = 0;
            isNewLeaving_MaybeCity = 0;    
          } 
        }
        pLeavList = pLeavList->next;
      }
    }

/************************************************************
 Create new entry in list if there's new leaving street lamp
************************************************************/
    /* update data in the leaving street lamp table */
    if(pTLB->statusAnalysisMisc.isLeavingStreetLamp == 1)
    {
      pLeavList = pTLB->pAssociatedLeavSL;
      pLeavList->xw100 = xwSL100;
      pLeavList->yw100 = ywSL100;
      pLeavList->xwUnfiltered100 = xwSL100;
      pLeavList->xwStraightRd100 = 1000;
    }

    if(isNewLeaving == TRUE) 
    {
      pTLB->statusAnalysisMisc.isLeavingStreetLamp = 1;
      pTLB->statusAnalysisMisc.isSceneStreetLamp = 0;
      pTLB->statusAnalysisMisc.isSceneStreetLampIcon = 0;
      pTLB->statusAnalysisMisc.isSceneStreetLampLowInt = 0;
      pTLB->statusAnalysisMisc.isSceneStreetLampTunnel = 0;

      pCityData->status.MaybeCity = 1;
      (*pNumSLCloseForMaybeUrban)++; /* Nb of leaving street lamp in front of the car or less than (140m) behind the car*/
      (*pNumSLCloseForMaybeUrban_LowInt)++;/* Nb of leaving street lamp in front of the car or less than (60m) behind the car*/
      (*pNumStreetLampTooCloseToTurnOn)++;/* Nb of leaving street lamp in front of the car or less than (50m) behind the car*/
      HLACityAddLeavSL(pCityData,pTLB);
      if(pTLB->pAssociatedLeavSL != 0)
      {
        pLeavList = pTLB->pAssociatedLeavSL;
        pLeavList->xw100 = xwSL100;
        pLeavList->yw100 = ywSL100;
      }
    }

    /* MaybeCity signal is set to ON if there is a LeavingStreetLamp_MaybeCity */
    if((isNewLeaving_MaybeCity == TRUE)||(pTLB->statusAnalysisMisc.isLeavingStreetLamp_MaybeCity == 1))
    {
      pTLB->statusAnalysisMisc.isLeavingStreetLamp_MaybeCity = 1;
      pCityData->distLeavSL100_NoMaybeLeavSL = 1000;
    }

/************************************************************/
    /* next object track */
    pTLB = pTLB->next; 
  }
}
/* **************************************************************************** 
  Functionname:     HLACityIntensityFluxAnalysis                             */ /*!  
  Description:      -
  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Boris LUGEZ, Alexander Fischer
**************************************************************************** */
static void HLACityIntensityFluxAnalysis(/* Inputs */
                                         HLATrack_t* pTLB,
                                         const HLACityInput_t *pIn,
                                         const sint16 MinYwDist100,
                                         const HLA_t_CityDetectionParameters * pParams,
                                         //const RTE_HLAR_ParameterCity_t      *pCityParams,
                                         /* Output */
                                         boolean *pHasHighIntensityFlux
                                  )
{
    const float32 luminousFluxMin = pParams->luminousFluxMin;
    const float32 luminousFluxMax = pParams->luminousFluxMax;
    const sint16 MaxYwDist100 = (sint16)(pParams->MaxYwDist100*100);
    const sint8 MaxConfHighIntensityFlux = pParams->MaxConfHighIntensityFlux;
    const sint8 MinConfHighIntensityFlux = pParams->MinConfHighIntensityFlux;
    const sint8 HighIntensityFluxThreshPositif = pParams->HighIntensityFluxThreshPositif;
    const sint8 HighIntensityFluxThreshNegative = pParams->HighIntensityFluxThreshNegative;

    uint32 areaLast;
    float32 currentLuminousFlux;
    float32 luminousFlux;
    sint16 AbsCurrentYw100;

    /************************************************************
                    Intensity Flux Model
    ************************************************************/
    areaLast = 0;
    luminousFlux = 0.0f;
    (*pHasHighIntensityFlux) = 0;

    if (pTLB->light_ref != NULL)
    {
      const HLASegLineRegion_t* pRegion = pTLB->light_ref->pRegion;
      

      while ((pRegion != NULL) &&
             (pRegion->iLine < HLA_SEG_MAX_NUM_SEG_LINES))
      {
        const uint32 area = (pRegion->x2 - pRegion->x1) * (pRegion->y2 - pRegion->y1);
        /* uint8 is always >= 0 */
        uint8 iLevel = (uint8) CML_Min(RTE_HLA_SEG_MAX_NUM_LEVELS - 1u, pRegion->Level);

        if (iLevel == 0)
        {
          break;
        }
        else
        {
          luminousFlux += pIn->pSegOut->RegionLevel.f32_Level[iLevel] * (area - areaLast);
        }
        
        areaLast = area;
        pRegion = pRegion->pRegionBelow;
      }

      {
        const HLASegNgb_t* ngb = &pTLB->light_ref->Maxima.ngb[0];

        luminousFlux += ngb[NGB_0].lux +
                        ngb[NGB_1].lux +
                        ngb[NGB_2].lux +
                        ngb[NGB_3].lux +
                        ngb[NGB_4].lux +
                        ngb[NGB_5].lux +
                        ngb[NGB_6].lux +
                        ngb[NGB_7].lux +
                        ngb[NGB_8].lux +
                        ngb[NGB_9].lux +
                        ngb[NGB_10].lux +
                        ngb[NGB_11].lux +
                        ngb[NGB_12].lux;
      }
    }

#ifdef PC_SIM
    pTLB->LuminousFlux = luminousFlux;
#endif

    if(pTLB->ywmax100 < -MinYwDist100)
    {
      AbsCurrentYw100 = -pTLB->ywmax100;
    }
    else if(pTLB->ywmin100 > MinYwDist100)
    {
      AbsCurrentYw100 = pTLB->ywmin100;
    }
    else
    {
      AbsCurrentYw100 = MinYwDist100;
    }

    /* currentLuminousFlux */
    currentLuminousFlux = luminousFluxMin + (( (luminousFluxMax - luminousFluxMin)/(MaxYwDist100 - MinYwDist100) )*(AbsCurrentYw100 - MinYwDist100));

    if(luminousFlux > currentLuminousFlux)
    {
      (*pHasHighIntensityFlux) = 1;
    }
    else
    {
      (*pHasHighIntensityFlux) = 0;
    }

    /* Update hasHighIntensityFlux confidence */
    if( ((*pHasHighIntensityFlux) == 1) && (pTLB->idResStat.hasHighIntensityFlux.confidence < MaxConfHighIntensityFlux) )
    {
      pTLB->idResStat.hasHighIntensityFlux.confidence++;
    }
    else if( (pTLB->light_ref != NULL) && ((*pHasHighIntensityFlux) == 0) && (pTLB->idResStat.hasHighIntensityFlux.confidence > MinConfHighIntensityFlux) )
    {
      pTLB->idResStat.hasHighIntensityFlux.confidence--;
    }
    else
    {
      /* Do nothing */
    }

    /* Update hasHighIntensityFlux result */
    if(pTLB->idResStat.hasHighIntensityFlux.confidence >= HighIntensityFluxThreshPositif /* =5 */)
    {
      pTLB->idResStat.hasHighIntensityFlux.result = HLA_RESULT_POSITIVE;
    }
    else if(pTLB->idResStat.hasHighIntensityFlux.confidence <= HighIntensityFluxThreshNegative /* =0 */)
    {
      pTLB->idResStat.hasHighIntensityFlux.result = HLA_RESULT_NEGATIVE;
    }
    else
    {
      pTLB->idResStat.hasHighIntensityFlux.result = HLA_RESULT_IDLE;
    }
}
/* **************************************************************************** 
  Functionname:     HLACityFarObjectAnalysis                             */ /*!  
  Description:      -
  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Boris LUGEZ, Alexander Fischer
**************************************************************************** */
static void HLACityFarObjectAnalysis(/* Inputs */
                                  HLATrack_t* pTLB,
                                  const HLA_t_CityDetectionParameters * pParams
                                  //const RTE_HLAR_ParameterCity_t      *pCityParams
                                  )
{
    /************************************************************
                    Far object & is Converging Flags
    ************************************************************/
    if(     (pTLB->stageTrackStatic.trackTimeToReinit >= pParams->minTrackTimeToReinit)
            &&   ( (pTLB->xwmax100 - pTLB->xwmin100) > (pParams->VarToDiverge*100))
          )
    {
      pTLB->statusAnalysisMisc.isConverging = FALSE;
      pTLB->statusAnalysisMisc.isFarObject = TRUE;
    }
    else if( (pTLB->xwmax100 - pTLB->xwmin100) < (pParams->VarToConverge*100) )
    {
      pTLB->statusAnalysisMisc.isConverging = TRUE;
      pTLB->statusAnalysisMisc.isFarObject = FALSE;
    }
    else
    {
      pTLB->statusAnalysisMisc.isFarObject = FALSE;
      /* TODO check in batch run */
      pTLB->statusAnalysisMisc.isConverging = FALSE;
    }
}
/* **************************************************************************** 
  Functionname:     HLACityCheckLeavingStreetLamp                        */ /*!  
  Description:      -
  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Boris LUGEZ, Alexander Fischer
**************************************************************************** */
static void HLACityCheckLeavingStreetLamp(/* Inputs */
                                   const HLACityInput_t *pIn,
                                   HLATrack_t* pTLB,
                                   const uint16 maxXwDist100_3dEstLeav,
                                   const float32 LeavingSLdistance,
                                   const sint16    xwSL100,
                                   const sint16    ywSL100,
                                   const sint16    maxStreetLampY_LHD100,
                                   const sint16    maxStreetLampY_RHD100,
                                   HLACityData_t *pCityData, 
                                   const HLA_t_eMovementState e_MoveState,
                                   const uint16    maxYwDist100_3dEstLeav_Left_Curve,
                                   const uint16    maxYwDist100_3dEstLeav_Right_Curve,
                                   const uint16    maxYwDist100_3dEstLeav_Left_Intensity,
                                   const uint16    maxYwDist100_3dEstLeav_Right_Intensity,
                                   const uint16    maxYwDist100_3dEstLeav_Left_MaybeCity,
                                   const uint16    maxYwDist100_3dEstLeav_Right_MaybeCity
                                   )
{

    if(         (pTLB->statusAnalysisMisc.isLeavingStreetLamp == TRUE)
        &&  (pTLB->light_ref != 0)
        && (        
        /* Filter Red tracks */
        (pTLB->RedLightCnt4City > 1) 
        /* Filter bad tracks 3d tracking */
        || (pTLB->xwmin100 >= maxXwDist100_3dEstLeav)
        || (pTLB->ywmin100 > CML_Max(maxYwDist100_3dEstLeav_Left_Curve,maxYwDist100_3dEstLeav_Left_Intensity))
        || (pTLB->ywmax100 < -CML_Max(maxYwDist100_3dEstLeav_Right_Curve,maxYwDist100_3dEstLeav_Right_Intensity))
        /* Filter tracks not in scene */
        || (xwSL100 > (sint16)(100.0f*LeavingSLdistance))
        || (ywSL100 < maxStreetLampY_RHD100)
        || (ywSL100 > maxStreetLampY_LHD100)
        /* Filter far object */
        || (pTLB->statusAnalysisMisc.isFarObject == TRUE)
        )
        )
    {
        pTLB->statusAnalysisMisc.isLeavingStreetLamp = FALSE;
        HLACityRemoveLeavSL(pCityData,pTLB->pAssociatedLeavSL);
        pTLB->pAssociatedLeavSL = 0;
    }
    else if(     (pTLB->statusAnalysisMisc.isLeavingStreetLamp == TRUE)
        &&  (e_MoveState != HLA_MOVE_STATE_FWD)
        )
    {
        pTLB->statusAnalysisMisc.isLeavingStreetLamp = FALSE;
        HLACityRemoveLeavSL(pCityData,pTLB->pAssociatedLeavSL);
        pTLB->pAssociatedLeavSL = 0;
    }
    else if(         (pTLB->statusAnalysisMisc.isLeavingStreetLamp == TRUE)
        &&    (pTLB->light_ref != 0)
        &&  (      ( (pTLB->ywmin100 > maxYwDist100_3dEstLeav_Left_Curve) && (pTLB->idResStat.hasHighIntensityFlux.result == HLA_RESULT_NEGATIVE) )
        || ( (pTLB->ywmax100 < -maxYwDist100_3dEstLeav_Right_Curve) && (pTLB->idResStat.hasHighIntensityFlux.result == HLA_RESULT_NEGATIVE) )
        )
        )
    {
        pTLB->statusAnalysisMisc.isLeavingStreetLamp = FALSE;
        HLACityRemoveLeavSL(pCityData,pTLB->pAssociatedLeavSL);
        pTLB->pAssociatedLeavSL = 0;
    }
    else if( (pTLB->statusAnalysisMisc.isLeavingStreetLamp == TRUE) && (pTLB->pAssociatedLeavSL->odometer > 150.0f) )
    {
        pTLB->statusAnalysisMisc.isNOTLeavingStreetLamp = 1;
    }
    else if(pTLB->statusAnalysisMisc.isLeavingStreetLamp == TRUE)
    {
        pTLB->pAssociatedLeavSL->odometer += pIn->pCamData->ddistFwd_m;
    }
    else
    {
      /* Do nothing */
    }

    /* Update isLeavingStreetLamp_MaybeCity value */
    if(         (pTLB->statusAnalysisMisc.isLeavingStreetLamp_MaybeCity == TRUE)
        &&    (pTLB->light_ref != 0)
        && (        
        /* Filter Red tracks */
        (pTLB->RedLightCnt4City != 0) 
        /* Filter bad tracks 3d tracking */
        || (pTLB->xwmin100 >= maxXwDist100_3dEstLeav)
        || (pTLB->ywmin100 > maxYwDist100_3dEstLeav_Left_MaybeCity)
        || (pTLB->ywmax100 < -maxYwDist100_3dEstLeav_Right_MaybeCity)
        /* Filter tracks not in scene */
        || (xwSL100 > (sint16)(100.0f*LeavingSLdistance))
        || (ywSL100 < maxStreetLampY_RHD100)
        || (ywSL100 > maxStreetLampY_LHD100)
        /* Filter far object */
        || (pTLB->statusAnalysisMisc.isFarObject == TRUE)
        )
        )
    {
        pTLB->statusAnalysisMisc.isLeavingStreetLamp_MaybeCity = 0;
    }
    else if(     (pTLB->statusAnalysisMisc.isLeavingStreetLamp_MaybeCity == TRUE)
        &&  (e_MoveState != HLA_MOVE_STATE_FWD)
        )
    {
        pTLB->statusAnalysisMisc.isLeavingStreetLamp_MaybeCity = 0;
    }
    else
    {
      /* Do nothing */
    }
}
/* **************************************************************************** 
  Functionname:     HLACityCheckIconStreetLampDistanceToLeavingStreetLamp                             */ /*!  
  Description:      -
  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Boris LUGEZ, Alexander Fischer
**************************************************************************** */
static void HLACityCheckIconStreetLampDistanceToLeavingStreetLamp(const HLACityInput_t *pIn,
                                       const HLACityData_t *pCityData,
                                       const HLA_t_CityDetectionParameters * pParams,
                                       //const RTE_HLAR_ParameterCity_t      *pCityParams,
                                       uint8 *pIsAnyStreetLamp,
                                       uint8 *pIsAnyStreetLampLowInt
                                                           )
{
    const uint16  minDistInterStreetLamp100 = (uint16)(pParams->minDistTurnOffDelay100*100);
    float32 sizeCorridorLoose100 = pParams->sizeCorridorLoose100*100;

    HLATrack_t* pTLB;
    HLA_City_ListNode_t* pLeavList;

    float32 xw_f32;
    float32 yw_f32;

    sint16 xwSL100;
    sint16 ywSL100;

    sint16 xw_temp100;
    sint16 yw_temp100;


    /***********************************************/
    /***********************************************/
    /* Second Loop: remove scene street lamp too close to leaving */
    /***********************************************/
    /***********************************************/
    pTLB = pIn->pTLB;
    while (pTLB != NULL)
    {    
        /***********************************************/
        /* remove scene street lamp too close to leaving */
        /***********************************************/
        if( pTLB->statusAnalysisMisc.isSceneStreetLampIcon == TRUE )
        {
            /* check leaving SL list */
            pLeavList = pCityData->pLeavSLBuffer;

            /* get world coordinate of current light with tracking informations */
            HLACamRotGetXwZ(pIn->pCamRot,&xw_f32,&yw_f32,pParams->minHeightAssumpSL,(float32)(pTLB->xcenter),(float32)(pTLB->ycenter));
            xwSL100 = (sint16)(CML_f_MinMax((float32)(SI16_T_MIN),(float32)(SI16_T_MAX),100.0f*xw_f32) );
            ywSL100 = (sint16)(CML_f_MinMax((float32)(SI16_T_MIN),(float32)(SI16_T_MAX),100.0f*yw_f32) );

            while(pLeavList != 0)
            {
                xw_temp100 = (sint16)( CML_f_MinMax((float32)(SI16_T_MIN),(float32)(SI16_T_MAX),(float32)(xwSL100 - pLeavList->xw100) ) );
                yw_temp100 = (sint16)(fabsf((float32)(pLeavList->yw100 - ywSL100) ) );

                /* check if detected leaving street lamp is not too close from any leaving street lamp in the list */
                if(      (yw_temp100 < (pParams->sizeCorridor100*100)) /* item must be in same corridor */
                    &&  (xw_temp100 < minDistInterStreetLamp100) /* interdistance must be superior to  minDistInterStreetLamp*/
                    )
                {
                    pTLB->statusAnalysisMisc.isSceneStreetLampIcon = FALSE;
                    pTLB->statusAnalysisMisc.isSceneStreetLampLowInt = FALSE;
#ifdef PC_SIM
                    pTLB->bCitySceneSL_gap = TRUE;
#endif
                } 
                pLeavList = pLeavList->next;
            }
        }
/***********************************************/
  /* set numSceneStreetLampInSameCorridor */
/***********************************************/    
        if((pTLB->statusAnalysisMisc.isSceneStreetLampIcon == TRUE)||(pTLB->statusAnalysisMisc.isSceneStreetLampTunnel == TRUE))
        {
            /* check leaving SL list */
             pLeavList = pCityData->pLeavSLBuffer;

            /* get world coordinate of current light with tracking informations */
            HLACamRotGetXwZ(pIn->pCamRot,&xw_f32,&yw_f32,pParams->minHeightAssumpSL,(float32)(pTLB->xcenter),(float32)(pTLB->ycenter));
            xwSL100 = (sint16)(CML_f_MinMax((float32)(SI16_T_MIN),(float32)(SI16_T_MAX),100.0f*xw_f32) );
            ywSL100 = (sint16)(CML_f_MinMax((float32)(SI16_T_MIN),(float32)(SI16_T_MAX),100.0f*yw_f32) );

            while(pLeavList != 0)
            {
                xw_temp100 = (sint16)( CML_f_MinMax((float32)(SI16_T_MIN),(float32)(SI16_T_MAX),(float32)(xwSL100 - pLeavList->xw100) ) );
                yw_temp100 = (sint16)(fabsf((float32)(pLeavList->yw100 - ywSL100) ) );

                /* check current light is in a loose corridor regarded to current leaving street lamp. This is for city detection confirmation */
                if(   (yw_temp100 < sizeCorridorLoose100)
                    &&  (xw_temp100 > minDistInterStreetLamp100) 
                    &&  (pTLB->statusAnalysisMisc.isSceneStreetLampIcon == TRUE)
                  )
                {     
                    (pLeavList->numSceneStreetLampInSameCorridor)++;
          
                    if( (xw_temp100 < pLeavList->MinDistSceneSL100) && (yw_temp100 < (pParams->sizeCorridor100*100)) )
                    {
                        pLeavList->MinDistSceneSL100 = xw_temp100;
                    }
                }
        
                if( xw_temp100 > 0 )
                {
                    /* check current light is in a tight corridor regarded to current leaving street lamp. This is for straight SL line  detection */
                    if(     (pTLB->lost_time == 0)    /* no appareance criteria */
                        &&  (pLeavList->numBorderingStreetLamp<8)                         
                        &&  (yw_temp100 < (pParams->sizeCorridorTight100*100))                
                        &&  (pLeavList->xw100 > 0)
                        &&  (pTLB->statusAnalysisMisc.isSceneStreetLampTunnel == TRUE)
                      )
                    {
                        pLeavList->numBorderingStreetLamp++;
                        pLeavList->sumSL_y += 0.01f * ywSL100;/* used for mean measurement of distance to road*/
                        pLeavList->sumsquareSL_y += 0.0001f * (ywSL100*ywSL100);/* used for std measurement of distance to road*/
                        pLeavList->sumSL_x += 0.01f * xw_temp100;/* used for street lamp interdistance mean measurement */
                    }
                }
                else
                {
                    pTLB->statusAnalysisMisc.isSceneStreetLampTunnel = FALSE;
                }
                pLeavList = pLeavList->next;
            }
        }

        /***********************************************/
        /* we have at least one relevant street lamp in the scene/ needed for the scene street lamp signal */
        /***********************************************/   
        if(     (pTLB->statusAnalysisMisc.isLeavingStreetLamp == TRUE) 
            ||  (pTLB->statusAnalysisMisc.isSceneStreetLamp == TRUE ) 
           )
            {
                (*pIsAnyStreetLamp) = 1;
            }

        /***********************************************/
        /* we have at least one relevant street lamp in the scene/ needed for the low intensity scene street lamp signal */
        /***********************************************/   
        if(     (pTLB->statusAnalysisMisc.isLeavingStreetLamp == TRUE) 
            ||  (pTLB->statusAnalysisMisc.isSceneStreetLampLowInt == TRUE ) 
           )
            {
                (*pIsAnyStreetLampLowInt) = 1;
            }
        /***********************************************/   
        /* next object track */
        pTLB = pTLB->next; 
    }
}
/* **************************************************************************** 
  Functionname:     HLACitySceneStreetLampSignalStateMachine                             */ /*!  
  Description:      -
  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Boris LUGEZ, Alexander Fischer
**************************************************************************** */
static void HLACitySceneStreetLampSignalStateMachine(    HLACityData_t *pCityData,
                                              const uint8 isAnyStreetLamp,
                                              const HLA_t_CityDetectionParameters * pParams
                                              //const RTE_HLAR_ParameterCity_t      *pCityParams
                                              )
{
    const uint8 numFramesSLSignalOnToOff = pParams->numFramesSLSignalOnToOff;
    const uint8 numFramesSLSignalOffToOn = pParams->numFramesSLSignalOffToOn;
    /***********************************************/
    /***********************************************/
    /* state machine: street lamp signal */
    /***********************************************/
    /***********************************************/
    if(isAnyStreetLamp == TRUE)
    {
        if(pCityData->status.StreetLampSignal==FALSE)
        {
            pCityData->numConsecutiveStreetLampState = pCityData->numConsecutiveStreetLampState + 1;
        }
        else
        {
            pCityData->numConsecutiveStreetLampState = 0;
        }
    }
    else
    {
        if(pCityData->status.StreetLampSignal==TRUE)
        {
            pCityData->numConsecutiveStreetLampState = pCityData->numConsecutiveStreetLampState + 1;
        }
        else
        {
            pCityData->numConsecutiveStreetLampState = 0;
        }
    }

    if( pCityData->status.StreetLampSignal==TRUE )
    {
        if(pCityData->numConsecutiveStreetLampState>=numFramesSLSignalOnToOff)
        { 
            pCityData->status.StreetLampSignal = 0;
            pCityData->numConsecutiveStreetLampState = 0;
        }
    }
    else
    {
        if(pCityData->numConsecutiveStreetLampState>=numFramesSLSignalOffToOn)
        { 
            pCityData->status.StreetLampSignal = 1;
            pCityData->numConsecutiveStreetLampState = 0;
        }
    }
}
/* **************************************************************************** 
  Functionname:     HLACitySceneStreetLampLowIntSignalStateMachine                             */ /*!  
  Description:      -
  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Boris LUGEZ, Alexander Fischer
**************************************************************************** */
static void HLACitySceneStreetLampLowIntSignalStateMachine( HLACityData_t *pCityData,
                                               const uint8 isAnyStreetLampLowInt,
                                               const HLA_t_CityDetectionParameters * pParams
                                               //const RTE_HLAR_ParameterCity_t      *pCityParams
                                                  )
{
    const uint8 numFramesSLSignalOnToOff = pParams->numFramesSLSignalOnToOff;
    const uint8 numFramesSLSignalOffToOn = pParams->numFramesSLSignalOffToOn;
    /***********************************************/
    /***********************************************/
    /* state machine: low intensity street lamp signal */
    /***********************************************/
    /***********************************************/
    if(isAnyStreetLampLowInt == TRUE)
    {
        if(pCityData->status.StreetLampSignal_LowInt==FALSE)
        {
            pCityData->numConsecutiveStreetLampState_LowInt = pCityData->numConsecutiveStreetLampState_LowInt + 1;
        }
        else
        {
            pCityData->numConsecutiveStreetLampState_LowInt = 0;
        }
    }
    else
    {
        if(pCityData->status.StreetLampSignal_LowInt==TRUE)
        {
            pCityData->numConsecutiveStreetLampState_LowInt = pCityData->numConsecutiveStreetLampState_LowInt + 1;
        }
        else
        {
            pCityData->numConsecutiveStreetLampState_LowInt = 0;
        }
    }

    if( pCityData->status.StreetLampSignal_LowInt==TRUE )
    {
        if(pCityData->numConsecutiveStreetLampState_LowInt>=numFramesSLSignalOnToOff)
        { 
            pCityData->status.StreetLampSignal_LowInt = 0;
            pCityData->numConsecutiveStreetLampState_LowInt = 0;
        }
    }
    else
    {
        if(pCityData->numConsecutiveStreetLampState_LowInt>=numFramesSLSignalOffToOn)
        { 
            pCityData->status.StreetLampSignal_LowInt = 1;
            pCityData->numConsecutiveStreetLampState_LowInt = 0;
        }
    }
}
/* **************************************************************************** 
  Functionname:     HLACityDetectionDecision                             */ /*!  
  Description:      -
  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Boris LUGEZ, Alexander Fischer
**************************************************************************** */
static void HLACityDetectionDecision(/* input */
                                     const HLACityInput_t *pIn,
                                     HLACityData_t *pCityData,
                                     const HLA_t_CityDetectionParameters * pParams,
                                     const RTE_HLAR_ParameterCity_t      *pCityParams,
                                     const uint8 numStreetLampTooCloseToTurnOn,
                                     const uint8 numSLCloseForMaybeUrban,
                                     const uint8 numSLCloseForMaybeUrban_LowInt,
                                     const uint8 SceneStreetLampLowIntCount,
                                     const float32 Radius)
{

    const float32 maxDistInterStreetLampVariance = pParams->maxDistInterStreetLampVariance;
    const float32  maxDistLastLeavingStreetLampExtended100 = pCityParams->LeavingCityDelaySceneStreetlamp_HighInt*100;
    //const uint16  maxDistLastLeavingStreetLamp100 = pParams->maxDistTurnOnDelay100*100;
    const float32  maxDistLastLS100_LowInt = pCityParams->LeavingCityDelaySceneStreetlamp_LowInt*100;

    const uint16  sizeCorridor100 = (uint16)(pParams->sizeCorridor100*100);
    /* Old implementation */
    //const uint16  maxDistInterStreetLamp100 = pParams->maxDistInterStreetLamp100*100;
    const uint16  maxDistInterStreetLamp100 = (uint16) HLACityInterpolate(pCityParams->SpeedThresholdLow, pCityParams->SpeedThresholdHigh, (pCityParams->StreetLampMaxInterDist_LowSpeed*100), (pCityParams->StreetLampMaxInterDist_HighSpeed*100), (pIn->pMotionData->f32_Speed));
    //const uint16  minDistInterStreetLamp100 = pParams->minDistTurnOffDelay100*100;
    const uint16  minDistInterStreetLampLeav100 = (uint16)(pParams->minDistTurnOffDelayLeav100*100);
    const uint16  minDistInterStreetLampUnfiltered = pParams->minDistInterStreetLampUnfiltered;

    /* Old Implementation */
    //const uint16 AHBC_NASL = ( ((pIn->pMotionData->f32_Speed*3.6f) < pParams->speedLimitLOW_HIGH) ? pCityParams->NumLeavingStreetlamp_LowSpeed : pCityParams->NumLeavingStreetlamp_HighSpeed );
    //const uint16 AHBC_NSCENESL = ( ((pIn->pMotionData->f32_Speed*3.6f) < pParams->speedLimitLOW_HIGH) ? pCityParams->NumSceneStreetlamp_LowSpeed : pCityParams->NumSceneStreetlamp_HighSpeed );

    const uint16 AHBC_NASL = (uint16) HLACityInterpolate(pCityParams->SpeedThresholdLow, pCityParams->SpeedThresholdHigh, (float32) pCityParams->NumLeavingStreetlamp_LowSpeed, (float32)pCityParams->NumLeavingStreetlamp_HighSpeed, (pIn->pMotionData->f32_Speed));
    const uint16 AHBC_NSCENESL = (uint16) HLACityInterpolate(pCityParams->SpeedThresholdLow, pCityParams->SpeedThresholdHigh, (float32)pCityParams->NumSceneStreetlamp_LowSpeed, (float32)pCityParams->NumSceneStreetlamp_HighSpeed, (pIn->pMotionData->f32_Speed));

//    const float32 minRadiusDelatYw = pParams->minRadiusDelatYw;
//    const float32 maxRadiusDelatYw = pParams->maxRadiusDelatYw;
//    const float32 minDeltaYwCurve100 = pParams->minDeltaYwCurve100;
//    const float32 maxDeltaYwCurve100 = pParams->maxDeltaYwCurve100;

//    const float32 luminousFluxMin = pParams->luminousFluxMin;
//    const float32 luminousFluxMax = pParams->luminousFluxMax;


    //const sint16 MinYwDist100 = pParams->MinYwDist100;
    //const sint8 MaxConfHighIntensityFlux = pParams->MaxConfHighIntensityFlux;
    //const sint8 MinConfHighIntensityFlux = pParams->MinConfHighIntensityFlux;
    //const sint8 HighIntensityFluxThreshPositif = pParams->HighIntensityFluxThreshPositif;
    //const sint8 HighIntensityFluxThreshNegative = pParams->HighIntensityFluxThreshNegative;

    const uint8 numFramesSLSignalOffToOn = pParams->numFramesSLSignalOffToOn;

    HLA_t_eMovementState e_MoveState = pIn->pMotionData->e_MoveState;

    HLA_City_ListNode_t* pLeavList;
    HLA_City_ListNode_t* pLeavList2;

    float32 dy;
    float32 VarYw;
    float32 sumXw;
    float32 sumXw_unfiltered; 
    float32 sum2Xw;
    float32 meanXw;
    float32 meanXw_unfiltered;
    float32 varXw;

    sint16 xw_temp100;
    sint16 xw_unfiltered_temp100;
    sint16 yw_temp100;


    LeavingStreetLampToCluster_t LSL2Clust[HLA_CITY_NUM_STREETLAMP];
    LeavingStreetLampToCluster_t LSL2ClustTemp;

    sint16 minYw100;
    sint16 maxYw100;

    uint8 numLSL = 0;
    sint8 m,p;
    uint8 hasSceneSLInCorridor;
    uint8 hasClusterOneLSLInFrontVehicle = 0;
    uint8 hasOneLSL_Short_RangeCrossed;
    uint8 hasOneLSL_Middle_RangeCrossed;
    uint8 hasSceneSLInCorridor_Crossed;
    uint8 isTooClose;

    /**************************************************************/
    /**************************************************************/
    /* Conditions to move from RTE_HLAR_CITY_NOT_DTCD to RTE_HLAR_CITY_DTCD */
    /**************************************************************/
    /**************************************************************/
    if( e_MoveState == HLA_MOVE_STATE_REV )
    {
        pCityData->status.MaybeCity = pCityData->status.MaybeCity;
        pCityData->internalCityState = pCityData->internalCityState;
        pCityData->status.StreetLampSignal = TRUE;
        pCityData->numConsecutiveStreetLampState = 0;
    }
    else if( pCityData->internalCityState == RTE_HLAR_CITY_NOT_DTCD )
    {
        /* double loop on leaving street lamp list */
        pLeavList = pCityData->pLeavSLBuffer;
        while(pLeavList != 0)
        {      
            if( pLeavList->xw100 > -maxDistInterStreetLamp100 )
            {
                numLSL = 0;
                /* keep in LSL2Clust information relative to leaving street lamp */
                LSL2Clust[numLSL].hasSceneStreetLampInCorridor = (uint8) (pLeavList->numSceneStreetLampInSameCorridor >= AHBC_NSCENESL);
                LSL2Clust[numLSL].isInFrontVehicle = (uint8) (pLeavList->xw100 >0);

                LSL2Clust[numLSL].isShortRangeCrossed = (uint8) ((pLeavList->xw100 < 0) && (pLeavList->xw100 > -3000));
                LSL2Clust[numLSL].isMiddleRangeCrossed = (uint8) ((pLeavList->xw100 < -3000) && (pLeavList->xw100 > -9500));

                LSL2Clust[numLSL].xw100 = pLeavList->xw100;
                LSL2Clust[numLSL].xwUnfiltered100 = pLeavList->xwUnfiltered100;

                numLSL++;

                /* lateral position range allowed to be in the same corridor*/
                minYw100 = (sint16)(pLeavList->yw100 - sizeCorridor100);
                maxYw100 = (sint16)(pLeavList->yw100 + sizeCorridor100);

                pLeavList2 = pCityData->pLeavSLBuffer;

                while(pLeavList2 != 0)
                {
                    xw_temp100 = (sint16)(fabsf((float32)(pLeavList2->xw100 - pLeavList->xw100)));
                    xw_unfiltered_temp100 = (sint16)(fabsf((float32)(pLeavList2->xwUnfiltered100 - pLeavList->xwUnfiltered100)));
                    yw_temp100 = (sint16)(fabsf((float32)(pLeavList2->yw100 - pLeavList->yw100)));
                    varXw = (float32)(abs( xw_temp100 - pLeavList->MinDistSceneSL100 ) );

                    if(   (pLeavList2->yw100 > minYw100)
                        &&  (pLeavList2->yw100 < maxYw100)
                        )
                    {
                        isTooClose = 0;
                        /* Check if this leaving street lamp is not too close to a street lamp already in LSL2Clust */
                        for(m=0;m<numLSL;m++)
                        {
                            xw_temp100 = (sint16)(fabsf((float32)(pLeavList2->xw100 - LSL2Clust[m].xw100)));
                            xw_unfiltered_temp100 = (sint16)(fabsf((float32)(pLeavList2->xwUnfiltered100 - LSL2Clust[m].xwUnfiltered100)));

                            if  (     (xw_temp100 <= minDistInterStreetLampLeav100)/* check interdistance between both SL is correct */
                                ||  (xw_unfiltered_temp100 <= (100 * minDistInterStreetLampUnfiltered) )
                                )
                            {   
                                isTooClose = 1;
                            }                  
                        }

                        if(isTooClose==0)
                        {
                            maxYw100 = CML_Min(maxYw100, (sint16)(pLeavList2->yw100 + sizeCorridor100));
                            minYw100 = CML_Max(minYw100, (sint16)(pLeavList2->yw100 - sizeCorridor100));
                            LSL2Clust[numLSL].xw100 = pLeavList2->xw100;
                            LSL2Clust[numLSL].xwUnfiltered100 = pLeavList2->xwUnfiltered100;
                            LSL2Clust[numLSL].hasSceneStreetLampInCorridor = (uint8) (pLeavList2->numSceneStreetLampInSameCorridor >= AHBC_NSCENESL);
                            LSL2Clust[numLSL].isInFrontVehicle = (uint8) (pLeavList2->xw100 >0);

                            LSL2Clust[numLSL].isShortRangeCrossed = (uint8) ((pLeavList2->xw100 < 0) && (pLeavList2->xw100 > -3000));
                            LSL2Clust[numLSL].isMiddleRangeCrossed = (uint8) ((pLeavList2->xw100 < -3000) && (pLeavList2->xw100 > -9500));

                            numLSL++;
                        }

                    }

                    xw_temp100 = (sint16)(fabsf((float32)(pLeavList2->xw100 - pLeavList->xw100)));
                    xw_unfiltered_temp100 = (sint16)(fabsf((float32)(pLeavList2->xwUnfiltered100 - pLeavList->xwUnfiltered100)));

                    /* SCENARIO 1 */
                    /* Special detection for cities with different sides street lamp distribution */
                    /* J.Häfer: No Possible Side Effect */
                    /* PRQA S 3415 7 */
                    if(     ( fabsf(Radius)>pParams->minRadiusCityOn )
                        &&  ( pLeavList != pLeavList2 )  
                        &&  ( pLeavList->numSceneStreetLampInSameCorridor >= AHBC_NSCENESL)
                        &&  ( CML_Sign(pLeavList->yw100) != CML_Sign(pLeavList2->yw100) )/* Different side of the road */
                        &&  ( abs(pLeavList->yw100) > (pParams->minYwDistSide100*100))
                        &&  ( abs(pLeavList2->yw100) > (pParams->minYwDistSide100*100))
                        &&  ( pLeavList->xw100 < 0 )/* behind vehicle */
                        &&  ( pLeavList2->xw100 > 0 )/* above vehicle */
                        &&  ( xw_temp100 < maxDistInterStreetLamp100)
                        &&  ( xw_unfiltered_temp100 > (100 * minDistInterStreetLampUnfiltered) )
                        &&  ( yw_temp100 > (pParams->minRoadYw100*100) )
                        &&  ( varXw > (float32)(100 * minDistInterStreetLampUnfiltered ) )
                        &&  ( varXw < (float32)(maxDistInterStreetLamp100) )
                        /* Japan specific handling */
                        &&  (     (pIn->eCountyCode != RTE_HLA_COUNTRY_CODE_JP) /* ok, when normal CC is set */
                              ||  (     (pIn->eCountyCode == RTE_HLA_COUNTRY_CODE_JP) /* Japan specific handling */
                                    &&  ( numLSL >= AHBC_NASL) 
                                  )
                            )
                        )
                    {
                        pCityData->internalCityState = RTE_HLAR_CITY_DTCD;
#ifdef PC_SIM
                        pCityData->bCityEntry = TRUE;
                        pCityData->eDetecion = 1;
#endif
                    }

                    /* SCENARIO 6: Detection with ambient light information */
                    if(       /*(pLeavList->xw100 < 0) && (pLeavList->xw100 > -1500)
                        &&*/  (pCityData->IsAmbientLight.result == HLA_RESULT_POSITIVE)
                        &&  ( pLeavList != pLeavList2 )
                        &&  (       (((uint8)(pLeavList->xw100 < 0) - (uint8)(0 < pLeavList2->xw100)) == 0) /* One is in front and one behind the car */
                                //||  (((pLeavList->xw100 < 0) - (0 < pLeavList2->xw100)) == 1) /* Two SLs are behind the car */
                            )
                        &&  ( xw_temp100 < maxDistInterStreetLamp100)
                        &&  ( xw_unfiltered_temp100 > (100 * minDistInterStreetLampUnfiltered) )
                        &&  ( varXw > (float32)(100 * minDistInterStreetLampUnfiltered ) )
                        &&  ( xw_temp100 < 6000) /* Interdistance between SL */
                        &&  ((pIn->pMotionData->f32_Speed*3.6f) < 70) /* Speed not too high */
                        &&  (pCityData->TooBright.result == HLA_RESULT_NEGATIVE) /* Prevent influence from twilight brightness*/
                        /* Japan specific handling */
                        &&  (     (pIn->eCountyCode != RTE_HLA_COUNTRY_CODE_JP) /* ok, when normal CC is set */
                              ||  (     (pIn->eCountyCode == RTE_HLA_COUNTRY_CODE_JP) /* Japan specific handling */
                                    &&  (SceneStreetLampLowIntCount > 1)
                                    &&  (pCityData->IsLowAmbientLight == HLA_RESULT_NEGATIVE)
                                  )
                            )
                        //&&  ( varXw < (float32)(maxDistInterStreetLamp100) )
                        )
                    {
                        pCityData->internalCityState = RTE_HLAR_CITY_DTCD;
#ifdef PC_SIM
                        pCityData->bCityEntry = TRUE;
                        pCityData->eDetecion = 6;
#endif
                    }

          pLeavList2 = pLeavList2->next;
        }

                if(numLSL>=AHBC_NASL)
                {
                    /* LSL Ascending Sorting */
                    for (m=1;m<numLSL;m++) 
                    {
                        LSL2ClustTemp = LSL2Clust[m];
                        p=m-1;
                        while ( (p >= 0) && (LSL2Clust[p].xw100 > LSL2ClustTemp.xw100)  )
                        {
                            LSL2Clust[p+1]=LSL2Clust[p];
                            p--;
                        }
                        LSL2Clust[p+1]=LSL2ClustTemp;
                    }


                    sumXw = 0;
                    sumXw_unfiltered = 0;
                    sum2Xw = 0;
                    hasSceneSLInCorridor = 0;
                    hasClusterOneLSLInFrontVehicle = 0;

                    hasOneLSL_Short_RangeCrossed = 0;
                    hasOneLSL_Middle_RangeCrossed = 0;
                    hasSceneSLInCorridor_Crossed = 0;

                    /* going from farthest leaving street lamp to the nearest one */
                    for (m=(sint8)(numLSL-1);m>(sint8)(numLSL-AHBC_NASL);m--)
                    {
                        /* calculation of the interdistance between 2 leaving street lamps */
                        xw_temp100 = (sint16)(CML_f_MinMax((float32)(SI16_T_MIN),(float32)(SI16_T_MAX),(float32)( LSL2Clust[m].xw100 - LSL2Clust[m-1].xw100 ) ) );
                        xw_unfiltered_temp100 = (sint16)(CML_f_MinMax((float32)(SI16_T_MIN),(float32)(SI16_T_MAX),(float32)( LSL2Clust[m].xwUnfiltered100 - LSL2Clust[m-1].xwUnfiltered100 ) ) );

                        /* calculation of the sum of leaving street lamps interdistance => to be able to calculate the mean */
                        sumXw += 0.01f*xw_temp100;
                        sumXw_unfiltered += 0.01f*xw_unfiltered_temp100;
                        /* calculation of the square of the sum of leaving street lamps interdistance => to be able to calculate the variance  */
                        sum2Xw += 0.0001f*(xw_temp100*xw_temp100);

                        /* Check if one of the leaving street lamps has a Icon street lamp in the same corridor */
                        hasSceneSLInCorridor = (LSL2Clust[m].isInFrontVehicle == TRUE) ? ( hasSceneSLInCorridor+ LSL2Clust[m].hasSceneStreetLampInCorridor) : (hasSceneSLInCorridor);

                        /* Nb of leaving street lamp in front of the car */
                        hasClusterOneLSLInFrontVehicle += (LSL2Clust[m].isInFrontVehicle);

                        /* Nb of leaving street lamp in short range [0,30] */
                        hasOneLSL_Short_RangeCrossed += (LSL2Clust[m].isShortRangeCrossed);
                        /* Nb of leaving street lamp in middle range [0,90] */
                        hasOneLSL_Middle_RangeCrossed += (LSL2Clust[m].isMiddleRangeCrossed);

                        /* Check if one of the leaving street lamps has been crossed by ego vehicle (means its xw < 0) */
                        hasSceneSLInCorridor_Crossed = (LSL2Clust[m].isShortRangeCrossed == TRUE) ? ( hasSceneSLInCorridor_Crossed+ LSL2Clust[m].hasSceneStreetLampInCorridor) : (hasSceneSLInCorridor_Crossed);
                    }

                    /* do to pairing necessity, the last leaving street lamp was not analyzed */
                    hasSceneSLInCorridor = (LSL2Clust[m].xw100>0) ? ( hasSceneSLInCorridor+ LSL2Clust[m].hasSceneStreetLampInCorridor) : (hasSceneSLInCorridor);
                    hasClusterOneLSLInFrontVehicle += (LSL2Clust[m].isInFrontVehicle);
                    hasOneLSL_Short_RangeCrossed += (LSL2Clust[m].isShortRangeCrossed);
                    hasOneLSL_Middle_RangeCrossed += (LSL2Clust[m].isMiddleRangeCrossed);
                    hasSceneSLInCorridor_Crossed = (LSL2Clust[m].isShortRangeCrossed == TRUE) ? ( hasSceneSLInCorridor_Crossed+ LSL2Clust[m].hasSceneStreetLampInCorridor) : (hasSceneSLInCorridor_Crossed);
                    
                    /* Calculation of the mean and variance */
                    if(AHBC_NASL != 1)
                    {
                        /* mean */
                        meanXw = (sumXw/(AHBC_NASL-1));
                        meanXw_unfiltered = (sumXw_unfiltered/(AHBC_NASL-1));

                        /* variance  */
                        varXw = (sum2Xw/(AHBC_NASL-1)) - (meanXw*meanXw);
                    }
                    else
                    {
                        /* mean */
                        meanXw = sumXw;
                        meanXw_unfiltered = sumXw_unfiltered;

                        /* variance  */
                        varXw = sum2Xw - (meanXw*meanXw);
                    }

                    /* SCENARIO 2 :    Scene_Leav_Cross  */
                    if(     ( hasSceneSLInCorridor>0  )  /* check one of the leaving street lamp has a street lamp in the same loose corridor in the scene */
                        &&  ( hasClusterOneLSLInFrontVehicle == 1  )  /* check one is behind vehicle and the other in front of vehicle */
                        &&  ( meanXw > (0.01f*minDistInterStreetLampLeav100) )/* check interdistance between both SL is correct */
                        &&  ( meanXw < (0.01f*maxDistInterStreetLamp100) )
                        &&  (meanXw_unfiltered > minDistInterStreetLampUnfiltered)
                        &&  ( varXw < maxDistInterStreetLampVariance )
                        )
                    {
                        pCityData->internalCityState = RTE_HLAR_CITY_DTCD;
#ifdef PC_SIM
                        pCityData->bCityEntry = TRUE;
                        pCityData->eDetecion = 2;
#endif
                    }

                    /* SCENARIO 3 : Scene_Short_Middle */
                    if(     ( hasSceneSLInCorridor_Crossed>0  )  /* check one of the leaving street lamp has a street lamp in the same loose corridor in the scene */
                        &&  ( hasOneLSL_Short_RangeCrossed == 1 )
                        &&  ( hasOneLSL_Middle_RangeCrossed == 1 )
                        &&  ( meanXw > (0.01f*minDistInterStreetLampLeav100) )/* check interdistance between both SL is correct */
                        &&  ( meanXw < (0.01f*maxDistInterStreetLamp100) )
                        &&  ( meanXw_unfiltered > minDistInterStreetLampUnfiltered)
                        &&  ( varXw < maxDistInterStreetLampVariance )
                        )
                    {
                        pCityData->internalCityState = RTE_HLAR_CITY_DTCD;
#ifdef PC_SIM
                        pCityData->bCityEntry = TRUE;
                        pCityData->eDetecion = 3;
#endif
                    }
                }

                if(numLSL>AHBC_NASL)
                {
                    /* LSL Ascending Sorting */
                    for (m=1;m<numLSL;m++) 
                    {
                        LSL2ClustTemp = LSL2Clust[m];
                        p=m-1;
                        while ( (p >= 0) && (LSL2Clust[p].xw100 > LSL2ClustTemp.xw100)  )
                        {
                            LSL2Clust[p+1]=LSL2Clust[p];
                            p--;
                        }
                        LSL2Clust[p+1]=LSL2ClustTemp;
                    }


                    sumXw = 0;
                    sumXw_unfiltered = 0;
                    sum2Xw = 0;
                    hasSceneSLInCorridor = 0;
                    hasClusterOneLSLInFrontVehicle = 0;

                    for (m=(sint8)(numLSL-1);m>(sint8)(numLSL-(AHBC_NASL+1));m--)
                    {
                        xw_temp100 = (sint16)(CML_f_MinMax((float32)(SI16_T_MIN),(float32)(SI16_T_MAX),(float32)( LSL2Clust[m].xw100 - LSL2Clust[m-1].xw100 ) ) );
                        xw_unfiltered_temp100 = (sint16)(CML_f_MinMax((float32)(SI16_T_MIN),(float32)(SI16_T_MAX),(float32)( LSL2Clust[m].xwUnfiltered100 - LSL2Clust[m-1].xwUnfiltered100 ) ) );
                        sumXw += 0.01f*xw_temp100;
                        sumXw_unfiltered += 0.01f*xw_unfiltered_temp100;
                        sum2Xw += 0.0001f*(xw_temp100*xw_temp100);

                        hasSceneSLInCorridor = (LSL2Clust[m].isInFrontVehicle == TRUE) ? ( hasSceneSLInCorridor+ LSL2Clust[m].hasSceneStreetLampInCorridor) : (hasSceneSLInCorridor);
                        hasClusterOneLSLInFrontVehicle += (LSL2Clust[m].isInFrontVehicle);        
                    }

                    hasSceneSLInCorridor = (LSL2Clust[m].xw100>0) ? ( hasSceneSLInCorridor+ LSL2Clust[m].hasSceneStreetLampInCorridor) : (hasSceneSLInCorridor);
                    hasClusterOneLSLInFrontVehicle += (LSL2Clust[m].isInFrontVehicle);

                    if(AHBC_NASL > 1)
                    {
                        /* mean */
                        meanXw = (sumXw/(AHBC_NASL));
                        meanXw_unfiltered = (sumXw_unfiltered/(AHBC_NASL));

                        /* variance  */
                        varXw = (sum2Xw/AHBC_NASL) - (meanXw*meanXw);
                    }
                    else
                    {
                        /* mean */
                        meanXw = sumXw;

                        meanXw_unfiltered = sumXw_unfiltered;

                        /* variance  */
                        varXw = sum2Xw - (meanXw*meanXw);
                    }

                    /* SCENARIO 4 : 1Leav_2Cross */
                    if(     ( hasClusterOneLSLInFrontVehicle == 1  )  /* check one is in front of vehicle and the others behind vehicle */
                        &&  ( meanXw > (0.01f*minDistInterStreetLampLeav100) )/* check inter distance between both SL is correct */
                        &&  ( meanXw < (0.01f*maxDistInterStreetLamp100) ) 
                        &&  ( meanXw_unfiltered > minDistInterStreetLampUnfiltered)
                        &&  ( varXw < pParams->maxDistInterStreetLampVarianceShort)
                        &&  ( varXw < (pParams->maxVarRatio*meanXw*meanXw) )
                        )
                    {
                        pCityData->internalCityState = RTE_HLAR_CITY_DTCD;
#ifdef PC_SIM
                        pCityData->bCityEntry = TRUE;
                        pCityData->eDetecion = 4;
#endif
                    }
                }
            }

            /* check if SL belongs to a straight line of street lamps */
            if(     (pLeavList->numBorderingStreetLamp > pCityParams->NumTunnelStreetlamp)
                &&  (pLeavList->odometer > 0.0f)
              )
            {

                /* TODO Batch run test -> include SC5 in main loop */
                //hasClusterOneLSLInFrontVehicle = 0;

                ///* going from farthest leaving street lamp to the nearest one */
                //    for (m=(sint8)(numLSL-1);m>(sint8)(numLSL-(AHBC_NASL+1));m--)
                //    {
                //        hasClusterOneLSLInFrontVehicle += (LSL2Clust[m].isInFrontVehicle);        
                //    }

                //    hasClusterOneLSLInFrontVehicle += (LSL2Clust[m].isInFrontVehicle);

                /* mean of distance to road */
                dy = pLeavList->sumSL_y/pLeavList->numBorderingStreetLamp;

                /* var of distance to road */
                VarYw = (pLeavList->sumsquareSL_y/pLeavList->numBorderingStreetLamp) - (dy*dy);

                /* mean of inter distance */
                meanXw = (pLeavList->sumSL_x/sumInd_city[pLeavList->numBorderingStreetLamp - 1]); 

            /* SCENARIO 5: Tunnel detection */
            if(         ( fabs(dy) < (0.01f*pParams->maxStreetLampTunnelYw100*100) )
                    &&  ( VarYw < pParams->maxStreetLampTunnelYwVar)
                    &&  ( meanXw > (0.01f*pParams->minStreetLampTunnelXwInter100*100) )
                    &&  ( meanXw < (0.01f*pParams->maxStreetLampTunnelXwInter100*100) )
                    /*&&  ( hasClusterOneLSLInFrontVehicle == 1  ) */
                )
                {
                    pCityData->internalCityState = RTE_HLAR_CITY_DTCD;
#ifdef PC_SIM
                    pCityData->bCityEntry = TRUE;
                    pCityData->eDetecion = 5;
                    pLeavList->status.isDecisiveForTurnOff2 = 1;
#endif
                }
            }

            /* Next Leaving Street Lamp */
            pLeavList = pLeavList->next;
        }

        /* set maybe city signal */
        if(     (pCityData->distLeavSL100_NoMaybeLeavSL < -maxDistLastLeavingStreetLampExtended100)
            ||  (        ( pCityData->status.StreetLampSignal == 0 ) 
                    &&  (            (pCityData->status.StreetLampSignal_LowInt == 0) 
                                 || (pCityData->distLeavSL100_NoMaybeLeavSL < -maxDistLastLS100_LowInt) 
                        )
                )
            ||  (pCityData->internalCityState == RTE_HLAR_CITY_DTCD)
            )
        {
            pCityData->status.MaybeCity = 0;
        }
    }
    /**************************************************************/
    /* Conditions to move from RTE_HLAR_CITY_DTCD to RTE_HLAR_CITY_NOT_DTCD */
    /**************************************************************/
    else
    {
        pCityData->status.MaybeCity = 0;
        /* avoid city detected during first frames */
        if(pCityData->numFrames < numFramesSLSignalOffToOn)
        {
            /* Code never executed */
            if(pCityData->numConsecutiveStreetLampState==numFramesSLSignalOffToOn)
            { 
                pCityData->internalCityState = RTE_HLAR_CITY_NOT_DTCD;
#ifdef PC_SIM
                pCityData->eDetecion = 0;
#endif
            }
        }
        else
        {
            if(     (numStreetLampTooCloseToTurnOn > 0 )
                ||  (( pCityData->status.StreetLampSignal == 1)  && (numSLCloseForMaybeUrban > 0 ))
                ||  ((pCityData->status.StreetLampSignal_LowInt == 1) && (numSLCloseForMaybeUrban_LowInt > 0))
                )
            {
                /* Keep previous state */
            }
            else
            {
                pCityData->internalCityState = RTE_HLAR_CITY_NOT_DTCD;
#ifdef PC_SIM
                pCityData->eDetecion = 0;
                pCityData->bCityExit = TRUE;
#endif
            }

            /* Special Japan mode -> leave city when less than 2 SL are in the scene */
            if(     (pIn->eCountyCode == RTE_HLA_COUNTRY_CODE_JP)
                &&  (
                      (     ((SceneStreetLampLowIntCount) <= pParams->numSLInSceneLeaveCityJapan)  /* less than 2 SL in the scene*/
                        //&& (pCityData->status.StreetLampSignal_LowInt == 0)
                        && (numSLCloseForMaybeUrban_LowInt == 0)
                        && (pCityData->IsAmbientLight.result != HLA_RESULT_POSITIVE)  /* not in the ambient brightness state */
                      )

                      || (pCityData->IsLowAmbientLight == HLA_RESULT_POSITIVE) /* Leave city immediately when there is low ambient information */
                    )
              )
            {
              pCityData->internalCityState = RTE_HLAR_CITY_NOT_DTCD;
#ifdef PC_SIM
              pCityData->eDetecion = 0;
              pCityData->bCityExit = TRUE;
#endif

            }


        }
    }
}
/* **************************************************************************** 
  Functionname:     HLACitySetOutput                             */ /*!  
  Description:      -
  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Boris LUGEZ, Alexander Fischer
**************************************************************************** */
static void HLACitySetOutput(const HLACityInput_t *pIn,
                             HLACityData_t *pCityData,
                             const HLA_t_CityDetectionParameters * pParams,
                             //const RTE_HLAR_ParameterCity_t      *pCityParams,
                             const uint8 numSLCloseForMaybeUrban,
                             const uint8 numSLCloseForMaybeUrban_LowInt,
                             RTE_HLAR_CityState *peCityOutput,
                             const uint8 SceneStreetLampLowIntCount)
{
    const uint8 numFramesSLSignalOffToOn = pParams->numFramesSLSignalOffToOn;
    HLA_t_eMovementState e_MoveState = pIn->pMotionData->e_MoveState;

  /***********************************************/
  /***********************************************/
  /* set output data */
  /***********************************************/
  /***********************************************/
  if(pCityData->numFrames < numFramesSLSignalOffToOn) 
  {
    if(e_MoveState == HLA_MOVE_STATE_FWD)
    {
      /* avoid city detected during first frames */
      pCityData->numFrames++;
    }

        /* maybe city ? */
        if(       (pCityData->status.MaybeCity == TRUE)
            &&  (     (( pCityData->status.StreetLampSignal == 1)  && (numSLCloseForMaybeUrban > 0 ))
            ||  ((pCityData->status.StreetLampSignal_LowInt == 1) && (numSLCloseForMaybeUrban_LowInt > 0))
            )
            /* Japan specific handling */
            &&  (     (pIn->eCountyCode != RTE_HLA_COUNTRY_CODE_JP) /* ok, when normal CC is set */
                  ||  (     (pIn->eCountyCode == RTE_HLA_COUNTRY_CODE_JP) /* Japan specific handling */
                        &&  ((SceneStreetLampLowIntCount) > pParams->numSLInSceneLeaveCityJapan)  /* avoid toggling of maybe city state */
                      )
                )
          )
        {
            *peCityOutput = RTE_HLAR_CITY_MAYBE;
        }
        else
        {
            *peCityOutput = RTE_HLAR_CITY_NOT_DTCD;
        }
    }
    else
    {
        if(pCityData->internalCityState == RTE_HLAR_CITY_DTCD)
        {
            *peCityOutput = RTE_HLAR_CITY_DTCD;
        }
        else if(      (pCityData->status.MaybeCity == TRUE)
                  &&  (    (( pCityData->status.StreetLampSignal == 1)  && (numSLCloseForMaybeUrban > 0 ))
                        || ((pCityData->status.StreetLampSignal_LowInt == 1) && (numSLCloseForMaybeUrban_LowInt > 0))
                      )
                  /* Japan specific handling */
                  &&  (    (pIn->eCountyCode != RTE_HLA_COUNTRY_CODE_JP) /* ok, when normal CC is set */
                        || (     (pIn->eCountyCode == RTE_HLA_COUNTRY_CODE_JP) /* Japan specific handling */
                             &&  ((SceneStreetLampLowIntCount) > pParams->numSLInSceneLeaveCityJapan)  /* avoid toggling of maybe city state */
                           )
                      )
            )
        {
            *peCityOutput = RTE_HLAR_CITY_MAYBE;
        }
        else
        {
            *peCityOutput = RTE_HLAR_CITY_NOT_DTCD;
        }
    }
}

/* **************************************************************************** 
  Functionname:     HLACityAmbientAnalysis                               */ /*!  
  Description:      Does the ambient analysis
  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Boris LUGEZ, Alexander Fischer
**************************************************************************** */
static void HLACityAmbientAnalysis(const HLACityInput_t *pIn, HLACityData_t *pCityData)
{

    uint8 i;
    uint8 j;
    for(i=0; i<HLA_SEG_INTENSITY_SUB_IMG_HEIGHT; i++)
    {
        for(j=0; j<HLA_SEG_INTENSITY_SUB_IMG_WIDTH;j++)
        {
            pCityData->subimagesum += pIn->pHLASubImage->SubImage_lux[i][j];
        }
    }

    /* Check if too bright */

    if(     (pIn->eBrightnessState == RTE_HLAR_BRT_TWLGT_3)
        &&  (pCityData->pLeavSLBuffer == 0)
        &&  (pCityData->TooBright.result != HLA_RESULT_POSITIVE)
        &&  ((pIn->pMotionData->f32_Speed*3.6f) > 20)
        )
    {
        pCityData->TooBright.confidence = CML_MinMax(-31, 31,pCityData->TooBright.confidence + 1);
    }
    else if(        (pIn->eBrightnessState == RTE_HLAR_BRT_NIGHT)
                ||  (pCityData->internalCityState == RTE_HLAR_CITY_DTCD)
           )
    {
        /* Reset Confidence */
        pCityData->TooBright.confidence = -31;
    }
    else if(        (pCityData->TooBright.result == HLA_RESULT_NEGATIVE)
                &&  (pCityData->pLeavSLBuffer != 0)
           )
    {
        /* Reset Confidence */
        pCityData->TooBright.confidence = -31;
    }
    else
    {
        /* Do nothing */
    }


    if(pCityData->TooBright.confidence > 30)
    {
        pCityData->TooBright.result = HLA_RESULT_POSITIVE;
    }
    else
    {
        pCityData->TooBright.result = HLA_RESULT_NEGATIVE;
    }

    /**********************/
    /* Calculate Features */
    /**********************/

    /* Feature 0
        1 1 1 1 1
        0 0 0 0 0
        0 0 0 0 0
        0 0 0 0 0
        0 0 0 0 0

    */
    pCityData->CityLuxFeat[0] = HLACityAverageFilter(pCityData->CityLuxFeat[0],(   pIn->pHLASubImage->SubImage_lux[0][0] + pIn->pHLASubImage->SubImage_lux[0][1] 
                                                                                    +   pIn->pHLASubImage->SubImage_lux[0][2] + pIn->pHLASubImage->SubImage_lux[0][3]
                                                                                    +   pIn->pHLASubImage->SubImage_lux[0][4])*0.2f, 0.25f
                                                    );
    /* Feature 1
        0 0 0 0 0
        1 1 1 1 1
        0 0 0 0 0
        0 0 0 0 0
        0 0 0 0 0

    */
    pCityData->CityLuxFeat[1] = HLACityAverageFilter(pCityData->CityLuxFeat[1],(     pIn->pHLASubImage->SubImage_lux[1][0] + pIn->pHLASubImage->SubImage_lux[1][1] 
                                                                                    +   pIn->pHLASubImage->SubImage_lux[1][2] + pIn->pHLASubImage->SubImage_lux[1][3]
                                                                                    +   pIn->pHLASubImage->SubImage_lux[1][4])*0.2f, 0.25f
                                                    );

    /* Feature 2
        0 0 0 1 1
        0 0 0 1 1
        0 0 0 0 0
        0 0 0 0 0
        0 0 0 0 0

    */
    pCityData->CityLuxFeat[2] = HLACityAverageFilter(pCityData->CityLuxFeat[2],(     pIn->pHLASubImage->SubImage_lux[0][3] + pIn->pHLASubImage->SubImage_lux[0][4] 
                                                                                    +   pIn->pHLASubImage->SubImage_lux[1][3] + pIn->pHLASubImage->SubImage_lux[1][4])*0.25f, 0.25f
                                                    );

    /* Feature 3
        1 1 0 0 0
        1 1 0 0 0
        0 0 0 0 0
        0 0 0 0 0
        0 0 0 0 0

    */
    pCityData->CityLuxFeat[3] = HLACityAverageFilter(pCityData->CityLuxFeat[3],(     pIn->pHLASubImage->SubImage_lux[0][0] + pIn->pHLASubImage->SubImage_lux[0][1] 
                                                                                    +   pIn->pHLASubImage->SubImage_lux[1][0] + pIn->pHLASubImage->SubImage_lux[1][1])*0.25f, 0.25f
                                                    );

    /* Feature 4
        1 1 1 1 1
        1 1 1 1 1
        1 1 1 1 1
        0 0 0 0 0
        0 0 0 0 0

    */
    pCityData->CityLuxFeat[4] = HLACityAverageFilter(pCityData->CityLuxFeat[4],(     pIn->pHLASubImage->SubImage_lux[0][0] + pIn->pHLASubImage->SubImage_lux[0][1] 
                                                                                    +   pIn->pHLASubImage->SubImage_lux[0][2] + pIn->pHLASubImage->SubImage_lux[0][3] + pIn->pHLASubImage->SubImage_lux[0][4]
                                                                                    + pIn->pHLASubImage->SubImage_lux[1][0] + pIn->pHLASubImage->SubImage_lux[1][1] 
                                                                                    +   pIn->pHLASubImage->SubImage_lux[1][2] + pIn->pHLASubImage->SubImage_lux[1][3] + pIn->pHLASubImage->SubImage_lux[1][4]
                                                                                    + pIn->pHLASubImage->SubImage_lux[3][0] + pIn->pHLASubImage->SubImage_lux[3][1] 
                                                                                    +   pIn->pHLASubImage->SubImage_lux[3][2] + pIn->pHLASubImage->SubImage_lux[3][3] + pIn->pHLASubImage->SubImage_lux[3][4])/15.0f, 0.25f
                                                    );

    /* Feature 5
        1 1 0 0 0
        1 1 0 0 0
        1 1 0 0 0
        1 1 0 0 0
        1 1 0 0 0

    */
    pCityData->CityLuxFeat[5] = HLACityAverageFilter(pCityData->CityLuxFeat[5],(       pIn->pHLASubImage->SubImage_lux[0][0] + pIn->pHLASubImage->SubImage_lux[0][1] 
                                                                                        +   pIn->pHLASubImage->SubImage_lux[1][0] + pIn->pHLASubImage->SubImage_lux[1][1]
                                                                                        +   pIn->pHLASubImage->SubImage_lux[2][0] + pIn->pHLASubImage->SubImage_lux[2][1]
                                                                                        +   pIn->pHLASubImage->SubImage_lux[3][0] + pIn->pHLASubImage->SubImage_lux[3][1]
                                                                                        +   pIn->pHLASubImage->SubImage_lux[4][0] + pIn->pHLASubImage->SubImage_lux[4][1])*0.1f, 0.25f
                                                    );
    /* Feature 6
        0 0 0 1 1
        0 0 0 1 1
        0 0 0 1 1
        0 0 0 1 1
        0 0 0 1 1

    */
    pCityData->CityLuxFeat[6] = HLACityAverageFilter(pCityData->CityLuxFeat[6],(       pIn->pHLASubImage->SubImage_lux[0][3] + pIn->pHLASubImage->SubImage_lux[0][4] 
                                                                                        +   pIn->pHLASubImage->SubImage_lux[1][3] + pIn->pHLASubImage->SubImage_lux[1][4]
                                                                                        +   pIn->pHLASubImage->SubImage_lux[2][3] + pIn->pHLASubImage->SubImage_lux[2][4]
                                                                                        +   pIn->pHLASubImage->SubImage_lux[3][3] + pIn->pHLASubImage->SubImage_lux[3][4]
                                                                                        +   pIn->pHLASubImage->SubImage_lux[4][3] + pIn->pHLASubImage->SubImage_lux[4][4])*0.1f, 0.25f
                                                    );


    /* Decision Part */
    /* For City Entry */
    pCityData->CityLuxFeatThresh[0] = 0.9f;
    pCityData->CityLuxFeatThresh[1] = 0.9f;
    pCityData->CityLuxFeatThresh[2] = 1.2f;
    pCityData->CityLuxFeatThresh[3] = 1.2f;
    pCityData->CityLuxFeatThresh[4] = 0.9f;
    pCityData->CityLuxFeatThresh[5] = 2.0f;
    pCityData->CityLuxFeatThresh[6] = 2.0f;

    if( (           (pCityData->CityLuxFeat[1] > pCityData->CityLuxFeatThresh[1]/*0.9f*/)
                ||  (pCityData->CityLuxFeat[0] > pCityData->CityLuxFeatThresh[0]/*0.9f*/)
             )
        &&  (pCityData->CityLuxFeat[4] > pCityData->CityLuxFeatThresh[4]/*0.9f*/)
        //&&  (fabs(pCityData->CityLuxFeat[5] - pCityData->CityLuxFeat[6]) < pCityData->CityLuxFeatThresh[5]/*2.0f*/)
        //&&  (fabs(pCityData->CityLuxFeat[2] - pCityData->CityLuxFeat[3]) < pCityData->CityLuxFeatThresh[2]/*2.0f*/)
        &&  (pCityData->CityLuxFeat[2] > pCityData->CityLuxFeatThresh[2])
        &&  (pCityData->CityLuxFeat[3] > pCityData->CityLuxFeatThresh[3])
           )
    {
        pCityData->IsAmbientLight.confidence = CML_MinMax(-10, 31,pCityData->IsAmbientLight.confidence + 2);

    }
    else
    {
        pCityData->IsAmbientLight.confidence = CML_MinMax(-10, 31,pCityData->IsAmbientLight.confidence - 2);
    }

    /* Confidence Check */
    if(pCityData->IsAmbientLight.confidence > 10)
    {
        pCityData->IsAmbientLight.result = HLA_RESULT_POSITIVE;

    }
    else
    {
        pCityData->IsAmbientLight.result = HLA_RESULT_NEGATIVE;
    }

    /* For City Exit */

    if(         (pCityData->CityLuxFeat[0] < 0.3f)
                &&  (pCityData->CityLuxFeat[1] < 0.3f)
                &&  (pCityData->CityLuxFeat[2] < 0.3f)
                &&  (pCityData->CityLuxFeat[3] < 0.3f)
       )
    {
        pCityData->IsLowAmbientLight = HLA_RESULT_POSITIVE;

    }
    else
    {
        pCityData->IsLowAmbientLight = HLA_RESULT_NEGATIVE;
    }


    /* Debug Info */
    pCityData->CityLuxSum[0] = HLACityAverageFilter(pCityData->CityLuxSum[0],( pIn->pHLASubImage->SubImage_lux[0][0] + pIn->pHLASubImage->SubImage_lux[0][1] 
                                                        +   pIn->pHLASubImage->SubImage_lux[0][2] + pIn->pHLASubImage->SubImage_lux[0][3]
                                                        +   pIn->pHLASubImage->SubImage_lux[0][4])*0.2f, 0.25f
                                                    );
    pCityData->CityLuxSum[1] = HLACityAverageFilter(pCityData->CityLuxSum[1], (pIn->pHLASubImage->SubImage_lux[1][0] + pIn->pHLASubImage->SubImage_lux[1][1] 
                                                        +   pIn->pHLASubImage->SubImage_lux[1][2] + pIn->pHLASubImage->SubImage_lux[1][3]
                                                        +   pIn->pHLASubImage->SubImage_lux[1][4])*0.2f, 0.25f
                        );
    pCityData->CityLuxSum[2] = HLACityAverageFilter(pCityData->CityLuxSum[2], (pIn->pHLASubImage->SubImage_lux[2][0] + pIn->pHLASubImage->SubImage_lux[2][1] 
                                                        +   pIn->pHLASubImage->SubImage_lux[2][2] + pIn->pHLASubImage->SubImage_lux[2][3]
                                                        +   pIn->pHLASubImage->SubImage_lux[2][4])*0.2f, 0.25f
                        );
    pCityData->CityLuxSum[3] = HLACityAverageFilter(pCityData->CityLuxSum[3], (pIn->pHLASubImage->SubImage_lux[3][0] + pIn->pHLASubImage->SubImage_lux[3][1] 
                                                        +   pIn->pHLASubImage->SubImage_lux[3][2] + pIn->pHLASubImage->SubImage_lux[3][3]
                                                        +   pIn->pHLASubImage->SubImage_lux[3][4])*0.2f, 0.25f
                        );
    pCityData->CityLuxSum[4] = HLACityAverageFilter(pCityData->CityLuxSum[4], (pIn->pHLASubImage->SubImage_lux[4][0] + pIn->pHLASubImage->SubImage_lux[4][1] 
                                                        +   pIn->pHLASubImage->SubImage_lux[4][2] + pIn->pHLASubImage->SubImage_lux[4][3]
                                                        +   pIn->pHLASubImage->SubImage_lux[4][4])*0.2f, 0.25f
                        );

}

/* **************************************************************************** 
  Functionname:     HLACityAverageFilter                                 */ /*!  
  Description:      Average Filter - used in the ambient analysis
  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Alexander Fischer
**************************************************************************** */
static float32 HLACityAverageFilter(float32 oldval, float32 luxsum, float32 coeff)
{
    return ((1-coeff)*oldval) + (coeff*luxsum);
}

/* **************************************************************************** 
  Functionname:     HLACityInterpolate                                 */ /*!  
  Description:      Linear Interpolation Function
  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Alexander Fischer
**************************************************************************** */
static float32 HLACityInterpolate(float32 x0, float32 x1, float32 y0, float32 y1, float32 xin)
{
    float32 res = 0;

    if(xin > x1)
    {
        res = y1;
    }
    else if(xin < x0)
    {
        res = y0;
    }
    else
    {
        res = ((CML_f_IsZero(x0 - x1)) ? y1 : (y0 + (((y1-y0)/(x1-x0))*(xin - x0))));
    }

    return res;
}
