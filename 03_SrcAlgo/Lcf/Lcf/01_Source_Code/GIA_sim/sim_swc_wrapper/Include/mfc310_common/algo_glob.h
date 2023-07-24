/*! \file **********************************************************************

  COMPANY:                Continental Temic, PC DAS, A.D.C. GmbH

  PROJECT:                All

  CPU:                    All

  COMPONENT:              RTE

  MODULNAME:              algo_glob.h

  DESCRIPTION:            


  CREATION DATE:          11.09.2007

  VERSION:                $Revision: 1.1 $

                  
  ---*/ /*---
  CHANGES:                $Log: algo_glob.h  $
  CHANGES:                Revision 1.1 2021/12/13 17:24:42CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310_common/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:35:37CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310_common/project.pj
  CHANGES:                Revision 1.1 2014/03/13 15:11:12CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310_common/project.pj
  CHANGES:                Revision 1.81.1.1 2011/08/05 17:10:43CEST Muench-EXT, Marc (uidt4601) 
  CHANGES:                Adaptions for MFC3xx
  CHANGES:                --- Added comments ---  uidt4601 [Aug 5, 2011 5:10:43 PM CEST]
  CHANGES:                Change Package : 72927:1 http://mks-psad:7002/im/viewissue?selection=72927
  CHANGES:                Revision 1.81 2011/08/02 18:59:03CEST Dintzer Philippe (dintzerp) (dintzerp) 
  CHANGES:                - fix Misra/Lint
  CHANGES:                --- Added comments ---  dintzerp [Aug 2, 2011 6:59:03 PM CEST]
  CHANGES:                Change Package : 73677:1 http://mks-psad:7002/im/viewissue?selection=73677
  CHANGES:                Revision 1.80 2011/07/26 15:24:27CEST Apel Norman (apeln) (apeln) 
  CHANGES:                - makro restructuring for new traces
  CHANGES:                --- Added comments ---  apeln [Jul 26, 2011 3:24:32 PM CEST]
  CHANGES:                Change Package : 73620:1 http://mks-psad:7002/im/viewissue?selection=73620
  CHANGES:                Revision 1.79 2011/07/25 13:58:04CEST Meschenmoser Daniel (uidu0849) (uidu0849) 
  CHANGES:                Fix double definition of object number in RTE and algo_glob.h
  CHANGES:                --- Added comments ---  uidu0849 [Jul 25, 2011 1:58:07 PM CEST]
  CHANGES:                Change Package : 73680:1 http://mks-psad:7002/im/viewissue?selection=73680
  CHANGES:                Revision 1.78 2011/06/30 18:24:19CEST Apel Norman (apeln) (apeln) 
  CHANGES:                - add old trace makros for temporary compiler satisfaction
  CHANGES:                --- Added comments ---  apeln [Jun 30, 2011 6:24:20 PM CEST]
  CHANGES:                Change Package : 59751:1 http://mks-psad:7002/im/viewissue?selection=59751
  CHANGES:                Revision 1.77 2011/06/27 09:56:37CEST Apel Norman (apeln) (apeln) 
  CHANGES:                - add ObjectTaceList (newTraces) as additional Port to EM
  CHANGES:                Revision 1.76 2011/06/14 13:21:51CEST Dintzer Philippe (dintzerp) (dintzerp) 
  CHANGES:                - Add EGO_ACCEL_X_STATE which was deleted by accident
  CHANGES:                --- Added comments ---  dintzerp [Jun 14, 2011 1:21:52 PM CEST]
  CHANGES:                Change Package : 69942:1 http://mks-psad:7002/im/viewissue?selection=69942
  CHANGES:                Revision 1.75 2011/06/10 13:23:48CEST Foelster Florian (foelsterf) (foelsterf) 
  CHANGES:                Delete old macro for standstill (EGO_STAND_STILL_RAW) to avoid reference of no longer valid VDY signal.
  CHANGES:                --- Added comments ---  foelsterf [Jun 10, 2011 1:23:48 PM CEST]
  CHANGES:                Change Package : 69562:2 http://mks-psad:7002/im/viewissue?selection=69562
  CHANGES:                Revision 1.74 2011/05/17 10:37:37CEST Dintzer Philippe (dintzerp) (dintzerp) 
  CHANGES:                - add further macros for object substructures
  CHANGES:                --- Added comments ---  dintzerp [May 17, 2011 10:37:38 AM CEST]
  CHANGES:                Change Package : 65764:3 http://mks-psad:7002/im/viewissue?selection=65764
  CHANGES:                Revision 1.72 2011/05/04 12:51:09CEST Sachs Martin (sachsm) (sachsm) 
  CHANGES:                remove misra lint message for:
  CHANGES:                RSP_F_PW_SAMPLE
  CHANGES:                RSP_F_PER_LINE
  CHANGES:                --- Added comments ---  sachsm [May 4, 2011 12:51:10 PM CEST]
  CHANGES:                Change Package : 65507:1 http://mks-psad:7002/im/viewissue?selection=65507
  CHANGES:                Revision 1.71 2011/04/27 11:45:01CEST Oprisan Dan (oprisand) (oprisand) 
  CHANGES:                - correct definition of MIN/MAX_FLOAT, SQRT depending on hardware platform (SIM, MCU Rev1, MCU Rev2)
  CHANGES:                --- Added comments ---  oprisand [Apr 27, 2011 11:45:01 AM CEST]
  CHANGES:                Change Package : 64321:1 http://mks-psad:7002/im/viewissue?selection=64321
  CHANGES:                Revision 1.70 2011/04/20 15:30:08CEST Oprisan Dan (oprisand) (oprisand) 
  CHANGES:                - add macro for object specific preselecton flags
  CHANGES:                Revision 1.69 2011/04/13 21:09:45CEST Zunker Uwe-Juergen (zunkeru) (zunkeru) 
  CHANGES:                new macros: MIN_FLOAT, MAX_FLOAT, MINMAX_FLOAT, SQRT
  CHANGES:                --- Added comments ---  zunkeru [Apr 13, 2011 9:09:45 PM CEST]
  CHANGES:                Change Package : 63689:1 http://mks-psad:7002/im/viewissue?selection=63689
  CHANGES:                Revision 1.68 2011/04/13 15:40:57CEST Sachs Martin (sachsm) (sachsm) 
  CHANGES:                adapt rcs thresholds to new if-transfer-function, as required in algo meeting on 13.04.2011
  CHANGES:                --- Added comments ---  sachsm [Apr 13, 2011 3:40:57 PM CEST]
  CHANGES:                Change Package : 58134:1 http://mks-psad:7002/im/viewissue?selection=58134
  CHANGES:                Revision 1.67 2011/03/18 11:52:08CET Spruck Jochen (spruckj) (spruckj) 
  CHANGES:                first version of new traces, could be switche on in the ars301_glob_cfg.h file. 
  CHANGES:                Features of new traces: 
  CHANGES:                - ring buffer memory
  CHANGES:                - relative traces vectors 
  CHANGES:                - i16 trace vectors (saves memory) 
  CHANGES:                - trace algo oncoming objects 
  CHANGES:                - introduce traces priority to delete/find free traces
  CHANGES:                --- Added comments ---  spruckj [Mar 18, 2011 11:52:08 AM CET]
  CHANGES:                Change Package : 53627:1 http://mks-psad:7002/im/viewissue?selection=53627
  CHANGES:                Revision 1.66 2011/03/18 10:49:47CET Konarski Witek (uidt8403) (uidt8403) 
  CHANGES:                FROUND(x) macro uses ROUND_TO_INT(x) when the software is build for the target
  CHANGES:                --- Added comments ---  uidt8403 [Mar 18, 2011 10:49:47 AM CET]
  CHANGES:                Change Package : 61848:1 http://mks-psad:7002/im/viewissue?selection=61848
  CHANGES:                Revision 1.65 2011/03/08 09:57:48CET Dintzer Philippe (dintzerp) (dintzerp) 
  CHANGES:                - Split macro for road border
  CHANGES:                --- Added comments ---  dintzerp [Mar 8, 2011 9:57:48 AM CET]
  CHANGES:                Change Package : 59704:1 http://mks-psad:7002/im/viewissue?selection=59704
  CHANGES:                Revision 1.64 2011/03/02 18:01:54CET Philippe Dintzer (dintzerp) 
  CHANGES:                - fill Flags InBridgeZone, InOtsZone
  CHANGES:                - regroup qualifiers
  CHANGES:                --- Added comments ---  dintzerp [Mar 2, 2011 6:01:54 PM CET]
  CHANGES:                Change Package : 59740:3 http://mks-psad:7002/im/viewissue?selection=59740
  CHANGES:                Revision 1.63 2011/02/28 11:28:36CET Philippe Dintzer (dintzerp) 
  CHANGES:                - Add Macro for the sub-Structure Object Attributes
  CHANGES:                - wide use of the kinematic macro
  CHANGES:                --- Added comments ---  dintzerp [Feb 28, 2011 11:28:37 AM CET]
  CHANGES:                Change Package : 59704:1 http://mks-psad:7002/im/viewissue?selection=59704
  CHANGES:                Revision 1.62 2011/02/23 16:45:35CET Jochen Spruck (spruckj) 
  CHANGES:                TRACE_NO_OF_TRACES and TRACE_INVALID_ID is now defined in the rte
  CHANGES:                --- Added comments ---  spruckj [Feb 23, 2011 4:45:35 PM CET]
  CHANGES:                Change Package : 53627:1 http://mks-psad:7002/im/viewissue?selection=53627
  CHANGES:                Revision 1.61 2011/02/17 09:10:04CET Philippe Dintzer (dintzerp) 
  CHANGES:                - add macro for the sensor mounting structure
  CHANGES:                --- Added comments ---  dintzerp [Feb 17, 2011 9:10:04 AM CET]
  CHANGES:                Change Package : 59704:1 http://mks-psad:7002/im/viewissue?selection=59704
  CHANGES:                Revision 1.60 2011/01/14 15:33:45CET Jochen Spruck (spruckj) 
  CHANGES:                Remove some target compiler warings, comma at enums and Rte_type.h include instead of rte_type.h
  CHANGES:                --- Added comments ---  spruckj [Jan 14, 2011 3:33:45 PM CET]
  CHANGES:                Change Package : 57456:1 http://mks-psad:7002/im/viewissue?selection=57456
  CHANGES:                Revision 1.59 2010/11/17 10:28:28CET Michael Eisenacher (eisenacherm) 
  CHANGES:                added DIST_CONST_OFFSET
  CHANGES:                --- Added comments ---  eisenacherm [Nov 17, 2010 10:28:28 AM CET]
  CHANGES:                Change Package : 52810:1 http://mks-psad:7002/im/viewissue?selection=52810
  CHANGES:                Revision 1.58 2010/11/16 14:45:51CET Gergely Ungvary (ungvaryg) 
  CHANGES:                Use new LongPosToCoG field of VehPar.SensorMounting struct for SENSOR_X_POSITION_CoG macro
  CHANGES:                --- Added comments ---  ungvaryg [Nov 16, 2010 2:45:52 PM CET]
  CHANGES:                Change Package : 54685:1 http://mks-psad:7002/im/viewissue?selection=54685
  CHANGES:                Revision 1.57 2010/11/16 13:21:19CET Gergely Ungvary (ungvaryg) 
  CHANGES:                Modify macro EGO_SPEED_X_STATE & EGO_YAW_RATE_STATE to refer to 'State' bit-field of VehDyn
  CHANGES:                (it seems the States sub-structure containing booleans has been removed from VehDyn)
  CHANGES:                Add new macro EGO_SPEED_X_CORRECTED_STATE for getting corrected X velocity state
  CHANGES:                --- Added comments ---  ungvaryg [Nov 16, 2010 1:21:19 PM CET]
  CHANGES:                Change Package : 54725:1 http://mks-psad:7002/im/viewissue?selection=54725
  CHANGES:                Revision 1.56 2010/10/18 11:16:02CEST Kloiber Armin (uidk7587) (uidk7587) 
  CHANGES:                moved missing MTS comp IDs to glob_comp_id.h
  CHANGES:                added include to glob_comp_id.h
  CHANGES:                --- Added comments ---  uidk7587 [Oct 18, 2010 11:16:03 AM CEST]
  CHANGES:                Change Package : 53278:1 http://mks-psad:7002/im/viewissue?selection=53278
  CHANGES:                Revision 1.55 2010/10/15 08:46:50CEST Jochen Spruck (spruckj) 
  CHANGES:                Remove not used OBJ_GET_CD_OBJECT_PROBABILITY marcro
  CHANGES:                --- Added comments ---  spruckj [Oct 15, 2010 8:46:50 AM CEST]
  CHANGES:                Change Package : 51889:1 http://mks-psad:7002/im/viewissue?selection=51889
  CHANGES:                Revision 1.54 2010/10/14 10:25:11CEST Jochen Spruck (spruckj) 
  CHANGES:                Misra/lint bug fix, redifined errors with target compiler
  CHANGES:                --- Added comments ---  spruckj [Oct 14, 2010 10:25:11 AM CEST]
  CHANGES:                Change Package : 52020:1 http://mks-psad:7002/im/viewissue?selection=52020
  CHANGES:                Revision 1.53 2010/10/14 09:02:21CEST Jochen Spruck (spruckj) 
  CHANGES:                Misra/lint bug fix, redifined errors with target compiler
  CHANGES:                --- Added comments ---  spruckj [Oct 14, 2010 9:02:22 AM CEST]
  CHANGES:                Change Package : 52020:1 http://mks-psad:7002/im/viewissue?selection=52020
  CHANGES:                Revision 1.52 2010/10/13 14:12:51CEST Jochen Spruck (spruckj) 
  CHANGES:                fix Misra/Lint Issues
  CHANGES:                --- Added comments ---  spruckj [Oct 13, 2010 2:12:52 PM CEST]
  CHANGES:                Change Package : 52020:1 http://mks-psad:7002/im/viewissue?selection=52020
  CHANGES:                Revision 1.51 2010/10/12 13:29:04CEST Norman Apel (apeln) 
  CHANGES:                - replace missleading sensor_x_pos with the distance from sensor to center of gravity sensor_x_ops_cog
  CHANGES:                --- Added comments ---  apeln [Oct 12, 2010 1:29:04 PM CEST]
  CHANGES:                Change Package : 18207:2 http://mks-psad:7002/im/viewissue?selection=18207
  CHANGES:                Revision 1.50 2010/10/04 10:53:20CEST Nele Hanel (haneln) 
  CHANGES:                cleanup: removed some old macros
  CHANGES:                --- Added comments ---  haneln [Oct 4, 2010 10:53:20 AM CEST]
  CHANGES:                Change Package : 51377:3 http://mks-psad:7002/im/viewissue?selection=51377
  CHANGES:                Revision 1.49 2010/09/29 14:59:32CEST Philippe Dintzer (dintzerp) 
  CHANGES:                - move grid gate confirmation defines from algo_glob to fps_par and fps_eba_quality_par
  CHANGES:                --- Added comments ---  dintzerp [Sep 29, 2010 2:59:32 PM CEST]
  CHANGES:                Change Package : 50954:1 http://mks-psad:7002/im/viewissue?selection=50954
  CHANGES:                Revision 1.48 2010/09/28 13:04:39CEST Philippe Dintzer (dintzerp) 
  CHANGES:                - Restructure Grid Gate Confirmation
  CHANGES:                --- Added comments ---  dintzerp [Sep 28, 2010 1:04:39 PM CEST]
  CHANGES:                Change Package : 50954:2 http://mks-psad:7002/im/viewissue?selection=50954
  CHANGES:                Revision 1.47 2010/09/27 16:46:54CEST Philippe Dintzer (dintzerp) 
  CHANGES:                - Adapt Grid gate confirmation
  CHANGES:                --- Added comments ---  dintzerp [Sep 27, 2010 4:46:54 PM CEST]
  CHANGES:                Change Package : 50954:1 http://mks-psad:7002/im/viewissue?selection=50954
  CHANGES:                Revision 1.46 2010/09/21 16:46:31CEST Jochen Spruck (spruckj) 
  CHANGES:                - Move traces to od and split up the trace quality calculation
  CHANGES:                - Remove all misra lint issues from the rd_movingobjtraces and od_movingobjtraces
  CHANGES:                --- Added comments ---  spruckj [Sep 21, 2010 4:46:32 PM CEST]
  CHANGES:                Change Package : 51352:1 http://mks-psad:7002/im/viewissue?selection=51352
  CHANGES:                Revision 1.45 2010/09/15 11:49:11CEST Dan Oprisan (oprisand) 
  CHANGES:                - ucMeasured is now a bitfield to handle multiple sources (radar, grid, cam).
  CHANGES:                - use macros to acces bits OBJ_SET_MEASURED, OBJ_IS_MEASURED, OBJ_CLEAR_MEASURED
  CHANGES:                --- Added comments ---  oprisand [Sep 15, 2010 11:49:12 AM CEST]
  CHANGES:                Change Package : 51282:1 http://mks-psad:7002/im/viewissue?selection=51282
  CHANGES:                Revision 1.44 2010/09/09 13:50:19CEST Gergely Ungvary (ungvaryg) 
  CHANGES:                Change OBJ_MEASURED macro: the field previously referenced (eMeasuredScans) has been superseeded
  CHANGES:                by a field ucMeasuredSources which is an ored bit-field of possible sensors / scans / sources for a given
  CHANGES:                object. Note: code which uses the macro needs to be checked and prepared for changed data representation
  CHANGES:                --- Added comments ---  ungvaryg [Sep 9, 2010 1:50:19 PM CEST]
  CHANGES:                Change Package : 48450:1 http://mks-psad:7002/im/viewissue?selection=48450
  CHANGES:                Revision 1.43 2010/09/06 17:52:11CEST Gergely Ungvary (ungvaryg) 
  CHANGES:                Fix mapping of trace hit pos macro (TRACE_HIT_POS)
  CHANGES:                Update comments for macros LOBE_ANGLE, COVERAGE_ANGLE
  CHANGES:                --- Added comments ---  ungvaryg [Sep 6, 2010 5:52:11 PM CEST]
  CHANGES:                Change Package : 50972:1 http://mks-psad:7002/im/viewissue?selection=50972
  CHANGES:                Revision 1.42 2010/08/27 12:51:55CEST Nele Hanel (haneln) 
  CHANGES:                added new macros for access of fused road border. 
  CHANGES:                todo: remove old macros with inconsistent naming/referencing asap
  CHANGES:                --- Added comments ---  haneln [Aug 27, 2010 12:51:55 PM CEST]
  CHANGES:                Change Package : 50381:1 http://mks-psad:7002/im/viewissue?selection=50381
  CHANGES:                Revision 1.41 2010/08/02 14:35:48CEST Gergely Ungvary (ungvaryg) 
  CHANGES:                Add roadbeam data access macros (needed by SPM)
  CHANGES:                --- Added comments ---  ungvaryg [Aug 2, 2010 2:35:48 PM CEST]
  CHANGES:                Change Package : 43282:3 http://mks-psad:7002/im/viewissue?selection=43282
  CHANGES:                Revision 1.40 2010/07/28 11:50:43CEST Martin Sachs (sachsm) 
  CHANGES:                + add defines for cluster and target list
  CHANGES:                --- Added comments ---  sachsm [Jul 28, 2010 11:50:43 AM CEST]
  CHANGES:                Change Package : 48376:1 http://mks-psad:7002/im/viewissue?selection=48376
  CHANGES:                Revision 1.39 2010/07/27 09:57:53CEST Gergely Ungvary (ungvaryg) 
  CHANGES:                Use defined for MWerks Codewarrrior for PowerPC detection instead of checking for value (merge in
  CHANGES:                Jochen's changes from 1.34.1.2/1.34.1.3 to avoid warnings about undefined identifiers in simulator compile)
  CHANGES:                --- Added comments ---  ungvaryg [Jul 27, 2010 9:57:53 AM CEST]
  CHANGES:                Change Package : 46738:1 http://mks-psad:7002/im/viewissue?selection=46738
  CHANGES:                Revision 1.38 2010/07/26 10:17:06CEST Jochen Spruck (spruckj) 
  CHANGES:                Buf fix in case of CPU_MPC5674F and not ((__POWERPC__) && (__MWERKS__)) don't use the special asm macros for CPU_MPC5674
  CHANGES:                --- Added comments ---  spruckj [Jul 26, 2010 10:17:06 AM CEST]
  CHANGES:                Change Package : 47577:1 http://mks-psad:7002/im/viewissue?selection=47577
  CHANGES:                Revision 1.37 2010/07/24 21:04:10CEST Uwe-Juergen Zunker (zunkeru) 
  CHANGES:                Rename MACRO names
  CHANGES:                --- Added comments ---  zunkeru [Jul 24, 2010 9:04:11 PM CEST]
  CHANGES:                Change Package : 47430:1 http://mks-psad:7002/im/viewissue?selection=47430
  CHANGES:                Revision 1.36 2010/07/23 22:07:26CEST Uwe-Juergen Zunker (zunkeru) 
  CHANGES:                MACROs for special MPC functions
  CHANGES:                --- Added comments ---  zunkeru [Jul 23, 2010 10:07:26 PM CEST]
  CHANGES:                Change Package : 47430:1 http://mks-psad:7002/im/viewissue?selection=47430
  CHANGES:                Revision 1.35 2010/07/20 11:19:43CEST Florian Foelster (foelsterf) 
  CHANGES:                Make floating point comparison macro MISRA conform (handling of types)
  CHANGES:                --- Added comments ---  foelsterf [Jul 20, 2010 11:19:43 AM CEST]
  CHANGES:                Change Package : 46740:9 http://mks-psad:7002/im/viewissue?selection=46740
  CHANGES:                Revision 1.34 2010/06/17 10:50:27CEST jspruck 
  CHANGES:                move external interfaces from vdy_ext.h to rte
  CHANGES:                move external interface freez from internal to the adapter
  CHANGES:                --- Added comments ---  jspruck [2010/06/17 08:50:27Z]
  CHANGES:                Change Package : 42829:1 http://LISS014:6001/im/viewissue?selection=42829
  CHANGES:                Revision 1.33 2010/06/01 13:59:57CEST gungvary 
  CHANGES:                Add different macros for fused/raw moving/stationary ranges and their confidences
  CHANGES:                --- Added comments ---  gungvary [2010/06/01 11:59:58Z]
  CHANGES:                Change Package : 39685:3 http://LISS014:6001/im/viewissue?selection=39685
  CHANGES:                Revision 1.32 2010/05/21 11:01:42CEST rthiel 
  CHANGES:                changed interface for cd object quality from lagacy to EM function preselection output
  CHANGES:                --- Added comments ---  rthiel [2010/05/21 09:01:43Z]
  CHANGES:                Change Package : 39716:2 http://LISS014:6001/im/viewissue?selection=39716
  CHANGES:                Revision 1.31 2010/05/12 17:04:01CEST gungvary 
  CHANGES:                Add dummy interface version define
  CHANGES:                Modify FCT Assessed Object List version number access define to reflect changed structure as of algo XLS
  CHANGES:                version 1.176 (and newer)
  CHANGES:                --- Added comments ---  gungvary [2010/05/12 15:04:02Z]
  CHANGES:                Change Package : 39685:3 http://LISS014:6001/im/viewissue?selection=39685
  CHANGES:                Revision 1.30 2010/04/28 15:59:04CEST Thomas Kleintje (tkleintj) 
  CHANGES:                remove REF_SPEED_NO_BINS as now definded in rte_type.h
  CHANGES:                --- Added comments ---  tkleintj [2010/04/28 13:59:04Z]
  CHANGES:                Change Package : 40787:1 http://LISS014:6001/im/viewissue?selection=40787
  CHANGES:                Revision 1.29 2010/04/22 15:40:30CEST Thomas Kleintje (tkleintj) 
  CHANGES:                add define for raw motion state
  CHANGES:                --- Added comments ---  tkleintj [2010/04/22 13:40:30Z]
  CHANGES:                Change Package : 41038:1 http://LISS014:6001/im/viewissue?selection=41038
  CHANGES:                Revision 1.28 2010/04/13 18:07:00CEST gungvary 
  CHANGES:                Fix external object ID access macro
  CHANGES:                --- Added comments ---  gungvary [2010/04/13 16:07:00Z]
  CHANGES:                Change Package : 39685:2 http://LISS014:6001/im/viewissue?selection=39685
  CHANGES:                Revision 1.27 2010/04/13 18:03:58CEST gungvary 
  CHANGES:                Add macro for accessing external object ID
  CHANGES:                --- Added comments ---  gungvary [2010/04/13 16:03:59Z]
  CHANGES:                Change Package : 39685:2 http://LISS014:6001/im/viewissue?selection=39685
  CHANGES:                Revision 1.26 2010/03/26 19:00:09CET gungvary 
  CHANGES:                Add defines FCT_PUB_OBJ_LIST_VERSION & FCT_PUB_OBJ_LIST_NUM_OBJS for accessing FCT Assessed object list's version and object number
  CHANGES:                --- Added comments ---  gungvary [2010/03/26 18:00:09Z]
  CHANGES:                Change Package : 39685:1 http://LISS014:6001/im/viewissue?selection=39685
  CHANGES:                Revision 1.25 2010/03/26 14:59:02CET doprisan 
  CHANGES:                - add OBJ_TIMESTAMP information to object list
  CHANGES:                --- Added comments ---  doprisan [2010/03/26 13:59:02Z]
  CHANGES:                Change Package : 39682:3 http://LISS014:6001/im/viewissue?selection=39682
  CHANGES:                Revision 1.24 2010/03/26 11:58:34CET doprisan 
  CHANGES:                - filling Em global kinematic structure with data
  CHANGES:                --- Added comments ---  doprisan [2010/03/26 10:58:34Z]
  CHANGES:                Change Package : 39682:2 http://LISS014:6001/im/viewissue?selection=39682
  CHANGES:                Revision 1.23 2010/03/26 08:37:31CET doprisan 
  CHANGES:                - compute compass card orientation and variance
  CHANGES:                - bugfix: correct initialization of eLastDynamicProperty for new objects
  CHANGES:                --- Added comments ---  doprisan [2010/03/26 07:37:31Z]
  CHANGES:                Change Package : 39682:1 http://LISS014:6001/im/viewissue?selection=39682
  CHANGES:                Revision 1.22 2010/03/24 17:39:17CET Jochen Spruck (jspruck) 
  CHANGES:                - seperate sim reset and int functions for em and fct
  CHANGES:                - move GED_CYCLE_TIME to EmFctCycleMode
  CHANGES:                --- Added comments ---  jspruck [2010/03/24 16:39:17Z]
  CHANGES:                Change Package : 33263:4 http://LISS014:6001/im/viewissue?selection=33263
  CHANGES:                Revision 1.21 2010/03/24 11:16:40CET gungvary 
  CHANGES:                Move CFG_USE_COMPACT_ENUMS switch to algo_cfg.h
  CHANGES:                Include algo_cfg.h in algo_glob.h and algo_type.h
  CHANGES:                Move SWITCH_ON and SWITCH_OFF definitions to algo_cfg.h, to assure that the corresponding defines
  CHANGES:                are always set, prior to any other definitions.
  CHANGES:                --- Added comments ---  gungvary [2010/03/24 10:16:40Z]
  CHANGES:                Change Package : 39685:1 http://LISS014:6001/im/viewissue?selection=39685
  CHANGES:                Revision 1.20 2010/03/23 08:45:07CET Jochen Spruck (jspruck) 
  CHANGES:                VDY sil-sil valitation update
  CHANGES:                - now all runs are equal
  CHANGES:                --- Added comments ---  jspruck [2010/03/23 07:45:07Z]
  CHANGES:                Change Package : 31184:2 http://LISS014:6001/im/viewissue?selection=31184
  CHANGES:                Revision 1.19 2010/03/11 09:11:06CET Jochen Spruck (jspruck) 
  CHANGES:                Move vdy io state macros and bitmasks to the algo_glob.h
  CHANGES:                --- Added comments ---  jspruck [2010/03/11 08:11:06Z]
  CHANGES:                Change Package : 31184:2 http://LISS014:6001/im/viewissue?selection=31184
  CHANGES:                Revision 1.18 2010/03/10 13:25:33CET gungvary 
  CHANGES:                Move CFG_USE_COMPACT_ENUMS from algo_glob.h to algo_type.h (since already referenced there)
  CHANGES:                --- Added comments ---  gungvary [2010/03/10 12:25:34Z]
  CHANGES:                Change Package : 33458:1 http://LISS014:6001/im/viewissue?selection=33458
  CHANGES:                Revision 1.17 2010/03/03 18:00:14CET gungvary 
  CHANGES:                Merge-in changes from 1.14.1.1 (removal of MTS data-type declarations & include of meas_ext.h)
  CHANGES:                --- Added comments ---  gungvary [2010/03/03 17:00:15Z]
  CHANGES:                Change Package : 38635:1 http://LISS014:6001/im/viewissue?selection=38635
  CHANGES:                Revision 1.16 2010/02/12 15:13:17CET gungvary 
  CHANGES:                Remove virtual address defines now directly in rte_type.h
  CHANGES:                --- Added comments ---  gungvary [2010/02/12 14:13:17Z]
  CHANGES:                Change Package : 33458:1 http://LISS014:6001/im/viewissue?selection=33458
  CHANGES:                Revision 1.15 2010/02/12 09:01:20CET gungvary 
  CHANGES:                Fix comment: GDBPerfDegrIn_t type no longer exists, superseeded by PerfDegrExtInput_t
  CHANGES:                --- Added comments ---  gungvary [2010/02/12 08:01:20Z]
  CHANGES:                Change Package : 33458:1 http://LISS014:6001/im/viewissue?selection=33458
  CHANGES:                Revision 1.14 2010/01/26 18:29:55CET Jochen Spruck (jspruck) 
  CHANGES:                update vdy to new algo interface Version 1.37
  CHANGES:                --- Added comments ---  jspruck [2010/01/26 17:29:55Z]
  CHANGES:                Change Package : 33263:2 http://LISS014:6001/im/viewissue?selection=33263
  CHANGES:                Revision 1.13 2010/01/15 16:04:56CET msachs 
  CHANGES:                moved common used rsp defines to algo_glob
  CHANGES:                --- Added comments ---  msachs [2010/01/15 15:04:56Z]
  CHANGES:                Change Package : 33459:1 http://LISS014:6001/im/viewissue?selection=33459
  CHANGES:                Revision 1.12 2010/01/15 11:41:02CET msachs 
  CHANGES:                moved define RSP_FQ_LINE_SCAL  from rsp_ext.h
  CHANGES:                --- Added comments ---  msachs [2010/01/15 10:41:02Z]
  CHANGES:                Change Package : 33459:1 http://LISS014:6001/im/viewissue?selection=33459
  CHANGES:                Revision 1.11 2010/01/15 09:46:42CET msachs 
  CHANGES:                added temporary defines for task logic monitoring
  CHANGES:                --- Added comments ---  msachs [2010/01/15 08:46:42Z]
  CHANGES:                Change Package : 33459:1 http://LISS014:6001/im/viewissue?selection=33459
  CHANGES:                Revision 1.10 2010/01/14 14:27:38CET gungvary 
  CHANGES:                Temporarily add MEAS types declarations. Note: this file shall later include the meas file declaraing these types, these declarations
  CHANGES:                shall only be an intermediate solution until a proper file is available. Algo sources shall not be modified later with an additional include,
  CHANGES:                as they only need to include this file to get the proper MEAS declarations.
  CHANGES:                --- Added comments ---  gungvary [2010/01/14 13:27:38Z]
  CHANGES:                Change Package : 33458:1 http://LISS014:6001/im/viewissue?selection=33458
  CHANGES:                Revision 1.9 2010/01/14 09:02:56CET msachs 
  CHANGES:                added makros  needed  rsp
  CHANGES:                --- Added comments ---  msachs [2010/01/14 08:02:57Z]
  CHANGES:                Change Package : 33459:1 http://LISS014:6001/im/viewissue?selection=33459
  CHANGES:                Revision 1.8 2010/01/07 16:30:39CET gungvary 
  CHANGES:                Adapt ROAD_GET_EST_VARIANCE macro to new names (RoadInt data moved to Legacy)
  CHANGES:                --- Added comments ---  gungvary [2010/01/07 15:30:39Z]
  CHANGES:                Change Package : 33458:1 http://LISS014:6001/im/viewissue?selection=33458
  CHANGES:                Revision 1.7 2010/01/07 15:01:35CET doprisan 
  CHANGES:                - introduce MERGE_NEW and MERGE_DELETED object states
  CHANGES:                --- Added comments ---  doprisan [2010/01/07 14:01:35Z]
  CHANGES:                Change Package : 33264:6 http://LISS014:6001/im/viewissue?selection=33264
  CHANGES:                Revision 1.6 2009/12/17 15:20:19CET Jochen Spruck (jspruck) 
  CHANGES:                Update algo_glob.h and algo_type.h to new rte interface
  CHANGES:                --- Added comments ---  jspruck [2009/12/17 14:20:20Z]
  CHANGES:                Change Package : 33263:2 http://LISS014:6001/im/viewissue?selection=33263
  CHANGES:                Revision 1.4 2009/12/15 09:41:20CET Jochen Spruck (jspruck) 
  CHANGES:                remove meas.he
  CHANGES:                add rsp input em macro block
  CHANGES:                change Yawrate to YawRate
  CHANGES:                --- Added comments ---  jspruck [2009/12/15 08:41:21Z]
  CHANGES:                Change Package : 33263:2 http://LISS014:6001/im/viewissue?selection=33263
  CHANGES:                Revision 1.3 2009/12/11 18:35:54CET gungvary 
  CHANGES:                Adapt header to new version of generated Cessar RTE
  CHANGES:                Add utility macro COMPILEMSG(x) to be able to display todo messages during compilation under MS-VC
  CHANGES:                Add utility define setting length of OOI list (OBJ_NUMBER_LENGTH_OF_OOI_LIST)
  CHANGES:                --- Added comments ---  gungvary [2009/12/11 17:35:54Z]
  CHANGES:                Change Package : 33458:1 http://LISS014:6001/im/viewissue?selection=33458
  CHANGES:                Revision 1.2 2009/12/11 17:36:32CET gungvary 
  CHANGES:                Add access macros to EBA object quality
  CHANGES:                --- Added comments ---  gungvary [2009/12/11 16:36:33Z]
  CHANGES:                Change Package : 33458:1 http://LISS014:6001/im/viewissue?selection=33458
  CHANGES:                Revision 1.1 2009/12/09 15:36:31CET Jochen Spruck (jspruck) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/PROJECTS/ARS301/05_Software/04_Engineering/01_Source_Code/rte/project.pj


**************************************************************************** */
#ifndef ALGO_GLOB_HE_INCLUDED
#define ALGO_GLOB_HE_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "glob_defs.h"
#include "Rte_type.h"
#include "algo_cfg.h"
#include "algo_type.h"
#include "algo_memsec.h"
#include "glob_comp_id.h"
#include "meas_ext.h"

/*****************************************************************************
  MACROS 
*****************************************************************************/

/* definition of NULL value */
#ifndef NULL
#ifdef  __cplusplus
#define NULL           (0)
#else
#define NULL           ((void *)0)
#endif
#endif

/* Definition of utility message macro for MS-VS */
#define COMPILEMSG(x) message(__FILE__"("STRING_QUOTE(__LINE__)"): TODO: " x)

/*! Absolute value */
//#define ABS(x)        (((x)<(0))?(-(x)):(x))

/*! Absolute value for type long */
//#define iABS(x)        (((x)<(0L))?(-(x)):(x))

/*! Determines the smaller of two values   */
//#define MIN(x,y)      (((x)<(y))?(x):(y))

/*! Determines  the larger  of two values */
//#define MAX(x,y)      (((x)>(y))?(x):(y))

/*! Limit the number to a minimum and a maximum value
          Parameterfolge: Minwert , Maxwert , Zahl */
//#define MINMAX(min,max,value)  (((value) < (min))? (min) : (((value) > (max))? (max) : (value)))

/*! Calculating the square (x*x) of a number */
#define SQR(x)        ((x)*(x))

/*! Determine the sign of a number 
0: Value equal 0 ||  1: Positiv Value || -1: Negativ Value */
#define SIGN(x)       (((x)==(0))?(0):(((x)>(0))?(1):(-1)))

#ifndef fSIGN
#define fSIGN(x)      ((F32_IS_ZERO(x))?(0.0F):((x > 0.F)?(1.0F):(-1.0f)))
#endif

/*! Rounds of positive and negative numbers with 0.5*/
#define ROUND(x)      (((x)>=0.F)?((x)+0.5F):((x)-0.5F))

/*! Conversion of angle from degree to radian unit */
#define DEG2RAD(deg_)  ((deg_)*(C_PI/180.F))

/*! Conversion of angle from radian to degree unit */
#define RAD2DEG(rad_)  ((rad_)*(180.F/C_PI))

/*! Internally used macro, never use outside of this file. */
#define STRING_INTERNAL_QUOTE(x)  #x

/*! Macro to convert a token/define to string. Useful for names etc. Note how
the internally used macro is needed by this function. Otherwise define
replacement wouldn't take place */
#define STRING_QUOTE(x) STRING_INTERNAL_QUOTE(x)

/*! Conversion macro to convert cycles to lifetime */
#define CONV_CYCLES_TO_LIFETIME(c)    (c)
/*! Conversion macro to convert time to lifetime */
#define CONV_TIME_TO_LIFETIME(t)      ((t) * (1.f/0.066f))
/*! Conversion macro to convert lifetime to time */
#define CONV_LIFETIME_TO_TIME(lt)     ((lt) * 0.066f)
/*! Conversion macro to convert lifetime to cycles */
#define CONV_LIFETIME_TO_CYCLES(lt)   (lt)

/*! Get the corresponding Bit on the basis of the BITMASK */
//#define GET_BIT(source, bitmask)   ( ((source) & (bitmask)) == (bitmask) )

/*! Set the corresponding Bit on the basis of the BITMASK */
//#define SET_BIT(source, bitmask)   ((source) |=  (bitmask))

/*! Reset the corresponding Bit on the basis of the BITMASK */
//#define CLEAR_BIT(source, bitmask) ((source) &= ~( bitmask) )

/*! Comparision of floating point value to equal zero */
//#define F32_IS_ZERO(value) (fABS(value) < C_F32_DELTA)

/*! Test whether the floating point value is approx. not zero (TRUE) or zero (FALSE)*/
//#define F32_IS_NZERO(value) (fABS(value) >= C_F32_DELTA)

#if !(defined(__POWERPC__) && defined(__MWERKS__))

/* rounding */
#define FROUND(x)     (((x) >= 0.0f) ? ((x) + 0.5f) : ((x) - 0.5f))

/*! Rounds floating point and converts to Signed Integer */
#define ROUND_TO_INT(x)   ((sint32)ROUND(x))

/*! Rounds floating point and converts to Unsigned Integer */
#define ROUND_TO_UINT(x)  ((uint32)ROUND(x))

/*! Absolute value for floating point*/
#define fABS(x)        (((x)<(0.f))?(-(x)):(x))

/*! Negate floating point */
#define NEG_FLOAT(x)   (-(x))

/* Floating point multiply and add: y = a * b + d */
#define MUL_ADD_FLOAT(a,b,d)  (((a) * (b)) + (d))

/*! Determines the smaller of two values - (simulation)  */
#define MIN_FLOAT(x,y)      (((x)<(y))?(x):(y))

/*! Determines  the larger  of two values - (simulation) */
#define MAX_FLOAT(x,y)      (((x)>(y))?(x):(y))

/*! Limit the floating point number to a minimum and a maximum value - (simulation) */
#define MINMAX_FLOAT(min,max,value)  (((value) < (min))? (min) : (((value) > (max))? (max) : (value)))

/*! Floating point Square Root - (simulation) */
#define SQRT(x)              SQRT_(x)

#else  /* #if !(defined(__POWERPC__) && defined(__MWERKS__)) */

/*! Absolute value for floating point */
//#define fABS(x)               GlobAbsFloat(x)

static inline float32 GlobAbsFloat(register float32 FpIn);
static inline float32 GlobAbsFloat(register float32 FpIn)
{                                 
	register float32 FpOut;    	    
                                  
	asm volatile {efsabs FpOut,FpIn}; 
  return (FpOut);                  
}

/*! Negate floating point */
#define NEG_FLOAT(x)          GlobNegFloat(x)

static inline float32 GlobNegFloat(register float32 FpIn);
static inline float32 GlobNegFloat(register float32 FpIn)
{                                 
	register float32 FpOut;    	    
                                  
	asm volatile {efsneg FpOut,FpIn}; 
  return (FpOut);                  
}

/*! Rounds floating point and converts to Signed Integer */
#define ROUND_TO_INT(x)       GlobRoundToSint(x)

static inline sint32 GlobRoundToSint(register float32 FpIn);
static inline sint32 GlobRoundToSint(register float32 FpIn)
{                                 
	register sint32 SiOut;    	    
                                  
	asm volatile {efsctsi SiOut,FpIn}; 
  return (SiOut);                  
}

/*! Rounds floating point and converts to Unsigned Integer */
#define ROUND_TO_UINT(x)      GlobRoundToUint(x)

static inline uint32 GlobRoundToUint(register float32 FpIn);
static inline uint32 GlobRoundToUint(register float32 FpIn)
{                                 
	register uint32 UiOut;    	    
                                  
	asm volatile {efsctui UiOut,FpIn}; 
  return (UiOut);                  
}

/* Floating point multiply and add: y = a * b + d */
#define MUL_ADD_FLOAT(a,b,d)  GlobMulAddFloat(a,b,d)

static inline float32 GlobMulAddFloat(register float32 FpA, register float32 FpB, register float32 FpD);
static inline float32 GlobMulAddFloat(register float32 FpA, register float32 FpB, register float32 FpD)
{                                 
	asm volatile {efsmadd FpD, FpA, FpB}; 
  return (FpD);                  
}

#if CPU_MPC5674F_2
/*! Floating point minimum - MCU Rev2 */
#define MIN_FLOAT(x,y)        GlobMinFloat(x,y)

static inline float32 GlobMinFloat(register float32 FpX, register float32 FpY);
static inline float32 GlobMinFloat(register float32 FpX, register float32 FpY)
{                                 
	register float32 FpOut;    	    
                                  
	asm volatile {efsmin FpOut, FpX, FpY}; 
  return (FpOut);                  
}

/*! Floating point maximum - MCU Rev2 */
#define MAX_FLOAT(x,y)        GlobMaxFloat(x,y)

static inline float32 GlobMaxFloat(register float32 FpX, register float32 FpY);
static inline float32 GlobMaxFloat(register float32 FpX, register float32 FpY)
{                                 
	register float32 FpOut;    	    
                                  
	asm volatile {efsmax FpOut, FpX, FpY}; 
  return (FpOut);                  
}

/*! Limit the floating point number to a minimum and a maximum value - MCU Rev2 */
#define MINMAX_FLOAT(min,max,value) MIN_FLOAT(MAX_FLOAT(min,value),max)

/*! Floating point Square Root - MCU Rev2 */
#define SQRT(x)               GlobSqrtFloat(x)

static inline float32 GlobSqrtFloat(register float32 FpIn);
static inline float32 GlobSqrtFloat(register float32 FpIn)
{                                 
	register float32 FpOut;    	    
                                  
	asm volatile {efssqrt FpOut, FpIn}; 
  return (FpOut);                  
}

#else  /* #if CPU_MPC5674F_2 */

/*! Determines the smaller of two values - MCU Rev1   */
#define MIN_FLOAT(x,y)      (((x)<(y))?(x):(y))

/*! Determines  the larger  of two values - MCU Rev1 */
#define MAX_FLOAT(x,y)      (((x)>(y))?(x):(y))

/*! Limit the floating point number to a minimum and a maximum value - MCU Rev1 */
#define MINMAX_FLOAT(min,max,value)  (((value) < (min))? (min) : (((value) > (max))? (max) : (value)))

/*! Floating point Square Root - MCU Rev1 */
#define SQRT(x)              SQRT_(x)

#endif  /* #if CPU_MPC5674F_2 */

/*! Round the float but use the above inline macro */
//#define FROUND(x)      ROUND_TO_INT(x)

#endif  /* #if (defined(__POWERPC__) && defined(__MWERKS__)) */
/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

/*! Dummy interface version number. This define is used to set the version number
of interfaces not used in the code */
#define DUMMY_INTERFACE_VERSION   0xFFFFFFFFu

/******************************************************************************************************************/
/******************************************************************************************************************/
/*                                                                                                                */
/*                                              generic base math lib                                             */
/*                                                                                                                */
/******************************************************************************************************************/
/******************************************************************************************************************/
/* MATH ***************+*/
/*! if working with trigonometric series, user have to choose different types of algorithms */
/*! Trigonometric series calculated with optimized µ-controller code (with 5.2 decimals of accuracy) */
#define GDB_TRIG_OPTIMIZED                        1

/*! Trigonometric series calculated with optimized µ-controller code (with 3.2 decimals of accuracy) */
#define GDB_TRIG_SMALL_SERIES                     1

/*! Additional calculation of e(x) */
#define GDB_TRIG_WITH_EXP                         1


/* defines for cluster and target list */

/* cluster and target PDH0 Reason */
#define RSP_PDH0_NO_REASON            0
#define RSP_PDH0_NEAR_RANGE_ARTIFACT  1
#define RSP_PDH0_SIDELOBE             2
#define RSP_PDH0_RANGE_ARTIFACT       3

/* cluster redundancy */
#define RSP_REDUNDANCY                0
#define RSP_NO_REDUNDANCY             1

/*! number of target far range */
//#define RSP_FAR_NUM_TARGETS   64

/*! number of target near range */
//#define RSP_NEAR_NUM_TARGETS   32

/*! number of stat cluster */
#define RSP_NUM_OF_STAT_CLUST  400

/*! number of reg of interest samples */
#define RSP_NUM_OF_REG_OF_INT_SAMP 20

/*! Number of scans (near/far) */
//#define RSP_NOF_SCANS                2

/*! maximum measuring distance far range scan */
#define RSP_DIST_MAX_FAR 200

/*! maximum measuring distance near range scan */
#define RSP_DIST_MAX_NEAR 60

/*! number of rg for near range scan */
#define RSP_NUM_OF_RG_NR  100

/*! number of rg for far range scan */
#define RSP_NUM_OF_RG_FR  200

/* *********** Common defines RSP *********** */
/*! number of antenna near range */
#define RSP_NUM_OF_ANT_NR 17
/*!  Number of peaks per Cell            */
#define RSP_MAX_NUM_OF_PEAK_PER_CELL (iRSPPeakNum_t) 3
/*! number of antenna far range */
#define RSP_NUM_OF_ANT_FR 17

/*! maximum number of anntenna */
#if RSP_NUM_OF_ANT_FR > RSP_NUM_OF_ANT_NR
#define RSP_MAX_NUM_OF_ANT  RSP_NUM_OF_ANT_FR
#else
//#define RSP_MAX_NUM_OF_ANT  RSP_NUM_OF_ANT_NR
#endif

/*! Number of lines around fft zero position. 1 Zeroline + 3 left and right adjacent lines */
//#define RSP_NOF_OFFSET_LINES         7
/*! Number of range gates with substantial offset */
#define RSP_NOF_OFFSET_RG           10

/*! Number of scans (near/far) */
//#define RSP_NOF_SCANS                2


/*! used for RSPValidFlag */
#define RSP_VALID      (RSPValidFlag_t) 1
#define RSP_INVALID    (RSPValidFlag_t) 0

/*! used for RSPFlag */
#define RSP_TRUE       (iRSPFlag_t) 1
#define RSP_FALSE      (iRSPFlag_t) 0

/*! traces */

#if ((defined(NEW_TRACES)) && (NEW_TRACES == 1))
#else
/*! number of supporting points for traces */
#define TRACE_NO_OF_PTS                           ((i8_t)   25  )//EO_MOT_NO_PTS
#endif

/*! for check, whether trace is occupied but without obj */
#define TRACE_VALID_NO_OBJ_ID                     ((ui8_t)  249 )//EOMOT_VALID_NO_OBJ_ID
/*! for check, whether trace is occupied     with    obj */
#define TRACE_VALID_OBJ_ID                        ((ui8_t)  250 )//EOMOT_VALID_OBJ_ID
/*! define to transfer the 16 bit scales trace vectors back to the not scaled f32 vectors */
#define TRACE_SCALE_CONST_INV               (1.0F/(f32_t)TRACE_SCALE_CONST)

/* //////////////////////////////////// Constant Values /////////////////////////// */
/*! Constant PI */
#define C_PI  (3.14159265359F)

/*! Constant gravity G */
#define C_GRAVITY  (9.80665F)

/*! Delta threshold value for 32 bit floating point equality tests  @see EQ_ZERO */
#define C_F32_DELTA  (0.0001F)

/*! Constant conversion km/h <-> m/s */
#define C_KMH_MS      (3.6F)

/*! Constant speed of light in vacuum c [m/s] */
#define C_V_LIGTH    (299792458.0F)


/*! global cycle time in [ms]: affects ACTL, CAN, TP, VDY */
#define GLOB_CYCLE_TIME   (66.667F)

/* ******** Definition for sensor configuration ****** */
/* Constant offset [m] depending on distances inside the sensor */
#define DIST_CONST_OFFSET (0.20f)
/* Scals factor for line postion  */
#define RSP_FQ_LINE_SCAL        512
/* Length of second FFT */
#define RSP_FFT_SIZE            128
/* segmentation of FFT to vrel range */
#define RSP_FFT_SPLIT_NORM           (0.75f)
/* segmentation of FFT to vrel range for power reduction */
#define RSP_FFT_SPLIT_POWRED         (0.5f)
/* scale FFT Size */
#define RSP_FFT_SIZE_SCAL       ((i32_t) RSP_FFT_SIZE * (i32_t) RSP_FQ_LINE_SCAL) 
/* line pos for maximum Vrel */ 
#define RSP_LINEPOS_MAX_VREL    ((f32_t)RSP_FFT_SIZE_SCAL * RSP_FFT_SPLIT_NORM )
/* transmit frequency [Hz] */
#define RSP_F_TRANSMIT 76.5e9f
/* puls repetition time (time between two ramps)*/
#define RSP_T_PW 20.0e-6f                         /* 01.06.2005 */
/* puls repetition rate [Hz] */
#define RSP_F_PW_SAMPLE (1.f/RSP_T_PW)
/* doppler frequency per FFT-Linie [Hz] */
#define RSP_F_PER_LINE (RSP_F_PW_SAMPLE / (f32_t)RSP_FFT_SIZE)
/* doppler frequency per FFT-Linie [Hz] scaled for linepos resolution */
#define RSP_F_PER_LINE_SCAL (RSP_F_PER_LINE / RSP_FQ_LINE_SCAL)
/* m/s per FFT-Linie (2.755 km/h per line)*/
#define RSP_MPS_PER_LINE ( ( ( RSP_F_PER_LINE * C_V_LIGTH ) / 2.0f) / RSP_F_TRANSMIT)
/* sample frequency at A/D conversion 40 MHz */
#define RSP_F_SAMPLE                 (40000000)  
/* length of first (range) FFT */
#define RSP_RANGE_FFT_SIZE           (512)
/* frequency shift per range bin (range gate) [Hz] */
#define RSP_RANGE_FEQU_PER_BIN       ( ((f32_t)RSP_F_SAMPLE) / ((f32_t) RSP_RANGE_FFT_SIZE)) 

/* scal factor for log peak power */
#define RSP_PEAK_POW_SCAL       (128.f)
#define RSP_PEAK_POW_SCAL_INV   (1.f/RSP_PEAK_POW_SCAL)
/* default log peak power */
#define RSP_PEAK_POW_DB_DEFAULT    (RSP_PEAK_POW_SCAL * (-999.f))


/* **** vrel ambiguity range **** */
/* vrel abmiguity normal condition           88.1 ... -264.5 km/h */
#define RSP_VREL_AMBIGUITY_NORMAL_REMOVING   ((f32_t)RSP_FFT_SIZE * (1.f-RSP_FFT_SPLIT_NORM) * RSP_MPS_PER_LINE)
#define RSP_VREL_AMBIGUITY_NORMAL_ONCOMMING  ((f32_t)RSP_FFT_SIZE * (   -RSP_FFT_SPLIT_NORM) * RSP_MPS_PER_LINE)
/* vrel abmiguity power reduction condition  44.1 ... - 44.1 km/h */
#define RSP_VREL_AMBIGUITY_POWRED_REMOVING   ((f32_t)RSP_FFT_SIZE  * (1.f-RSP_FFT_SPLIT_POWRED) * RSP_MPS_PER_LINE * 0.25f)
#define RSP_VREL_AMBIGUITY_POWRED_ONCOMMING  ((f32_t)RSP_FFT_SIZE  * (   -RSP_FFT_SPLIT_POWRED) * RSP_MPS_PER_LINE * 0.25f)

/* **** Modes for changing center frequency and range gate length ****** */
/*! no change required. */
#define NO_CHANGE         ((RSPChange_t) 0)
/*! change to any value to avoid interference. */
#define CHANGE_TO_ANY     ((RSPChange_t) 1)
/*! change to the default value with best hardware properties. */
#define CHANGE_TO_DEFAULT ((RSPChange_t) 2)

/* ***** defines regarding HW-Sample ***** */
/*! Prototype versions */
#define RSP_PROTOTYPE_VERSION_B2_AND_UPPER   0
/* new IF-path, new ADC, new CoarseDac */
#define RSP_PROTOTYPE_VERSION_B4_AND_UPPER   1
/* new mechanical elevation limit */
#define RSP_PROTOTYPE_VERSION_C0_AND_UPPER   2

/*! Assembly versions */
#define RSP_ASSEMBLY_VERSION_0_AND_UPPER   0

/* ********************************************* */
/* defines for blockage detection */
/*! roadbeam angle for blockage [°] (difference to current valid aligment) */
#define RSP_BLOCK_RB_REQU_ELEV_ANGLE   (9.f)
/*! roadbeam required rg length */
#define RSP_BLOCK_RB_REQU_RG_LENGTH    (0.25f)



/* **** RCS Thresholds **** */
/* number of table entries for rcs threshold (0...40m)*/ 
#define RSP_NUM_OF_RCS_TABLE_VAL    41

/* RCS-Threshold for traced targets in far scan in 1 m steps in dB square meters */ 
#define RCS_THR_TARGET_TRACED_00  -17.6f  
#define RCS_THR_TARGET_TRACED_01  -17.6f  
#define RCS_THR_TARGET_TRACED_02  -17.6f  
#define RCS_THR_TARGET_TRACED_03  -17.6f  
#define RCS_THR_TARGET_TRACED_04  -17.6f  
#define RCS_THR_TARGET_TRACED_05  -17.6f  
#define RCS_THR_TARGET_TRACED_06  -17.6f
#define RCS_THR_TARGET_TRACED_07  -17.2f
#define RCS_THR_TARGET_TRACED_08  -16.8f
#define RCS_THR_TARGET_TRACED_09  -16.4f
#define RCS_THR_TARGET_TRACED_10  -16.0f
#define RCS_THR_TARGET_TRACED_11  -15.8f
#define RCS_THR_TARGET_TRACED_12  -15.6f
#define RCS_THR_TARGET_TRACED_13  -15.4f
#define RCS_THR_TARGET_TRACED_14  -15.2f
#define RCS_THR_TARGET_TRACED_15  -15.0f
#define RCS_THR_TARGET_TRACED_16  -14.8f
#define RCS_THR_TARGET_TRACED_17  -14.6f
#define RCS_THR_TARGET_TRACED_18  -14.4f
#define RCS_THR_TARGET_TRACED_19  -14.2f
#define RCS_THR_TARGET_TRACED_20  -14.0f
#define RCS_THR_TARGET_TRACED_21  -13.8f
#define RCS_THR_TARGET_TRACED_22  -13.6f
#define RCS_THR_TARGET_TRACED_23  -13.4f
#define RCS_THR_TARGET_TRACED_24  -13.2f
#define RCS_THR_TARGET_TRACED_25  -13.0f
#define RCS_THR_TARGET_TRACED_26  -12.8f
#define RCS_THR_TARGET_TRACED_27  -12.6f
#define RCS_THR_TARGET_TRACED_28  -12.4f
#define RCS_THR_TARGET_TRACED_29  -12.2f
#define RCS_THR_TARGET_TRACED_30  -12.0f
#define RCS_THR_TARGET_TRACED_31  -11.8f
#define RCS_THR_TARGET_TRACED_32  -11.6f
#define RCS_THR_TARGET_TRACED_33  -11.4f
#define RCS_THR_TARGET_TRACED_34  -11.2f
#define RCS_THR_TARGET_TRACED_35  -11.0f
#define RCS_THR_TARGET_TRACED_36  -10.8f
#define RCS_THR_TARGET_TRACED_37  -10.6f
#define RCS_THR_TARGET_TRACED_38  -10.4f
#define RCS_THR_TARGET_TRACED_39  -10.2f
#define RCS_THR_TARGET_TRACED_40  -10.0f


/* RCS-Threshold for stationary targets in far scan in 1 m steps in dB square meters */ 
#define RCS_THR_TARGET_STAT_00  -17.6f  
#define RCS_THR_TARGET_STAT_01  -17.6f  
#define RCS_THR_TARGET_STAT_02  -17.6f  
#define RCS_THR_TARGET_STAT_03  -17.6f  
#define RCS_THR_TARGET_STAT_04  -17.6f  
#define RCS_THR_TARGET_STAT_05  -17.6f  
#define RCS_THR_TARGET_STAT_06  -17.6f
#define RCS_THR_TARGET_STAT_07  -17.2f
#define RCS_THR_TARGET_STAT_08  -16.8f
#define RCS_THR_TARGET_STAT_09  -16.4f
#define RCS_THR_TARGET_STAT_10  -15.0f
#define RCS_THR_TARGET_STAT_11  -14.8f
#define RCS_THR_TARGET_STAT_12  -13.6f
#define RCS_THR_TARGET_STAT_13  -12.4f
#define RCS_THR_TARGET_STAT_14  -11.2f
#define RCS_THR_TARGET_STAT_15  -10.0f
#define RCS_THR_TARGET_STAT_16  -9.8f
#define RCS_THR_TARGET_STAT_17  -9.6f
#define RCS_THR_TARGET_STAT_18  -9.4f
#define RCS_THR_TARGET_STAT_19  -9.2f
#define RCS_THR_TARGET_STAT_20  -9.0f
#define RCS_THR_TARGET_STAT_21  -8.8f
#define RCS_THR_TARGET_STAT_22  -8.6f
#define RCS_THR_TARGET_STAT_23  -8.4f
#define RCS_THR_TARGET_STAT_24  -8.2f
#define RCS_THR_TARGET_STAT_25  -8.0f
#define RCS_THR_TARGET_STAT_26  -7.8f
#define RCS_THR_TARGET_STAT_27  -7.6f
#define RCS_THR_TARGET_STAT_28  -7.4f
#define RCS_THR_TARGET_STAT_29  -7.2f
#define RCS_THR_TARGET_STAT_30  -7.0f
#define RCS_THR_TARGET_STAT_31  -6.8f
#define RCS_THR_TARGET_STAT_32  -6.6f
#define RCS_THR_TARGET_STAT_33  -6.4f
#define RCS_THR_TARGET_STAT_34  -6.2f
#define RCS_THR_TARGET_STAT_35  -6.0f
#define RCS_THR_TARGET_STAT_36  -5.8f
#define RCS_THR_TARGET_STAT_37  -5.6f
#define RCS_THR_TARGET_STAT_38  -5.4f
#define RCS_THR_TARGET_STAT_39  -5.2f
#define RCS_THR_TARGET_STAT_40  -5.0f

/* RCS-Threshold for stationary targets in far scan in 1 m steps in dB square meters */ 
/* at low veigen */
#define RCS_THR_TARGET_STAT_LOW_VEL_00  -24.6f 
#define RCS_THR_TARGET_STAT_LOW_VEL_01  -24.6f 
#define RCS_THR_TARGET_STAT_LOW_VEL_02  -24.6f 
#define RCS_THR_TARGET_STAT_LOW_VEL_03  -20.6f 
#define RCS_THR_TARGET_STAT_LOW_VEL_04  -17.6f 
#define RCS_THR_TARGET_STAT_LOW_VEL_05  -17.6f 
#define RCS_THR_TARGET_STAT_LOW_VEL_06  -17.6f
#define RCS_THR_TARGET_STAT_LOW_VEL_07  -17.2f
#define RCS_THR_TARGET_STAT_LOW_VEL_08  -16.8f
#define RCS_THR_TARGET_STAT_LOW_VEL_09  -16.4f
#define RCS_THR_TARGET_STAT_LOW_VEL_10  -15.0f
#define RCS_THR_TARGET_STAT_LOW_VEL_11  -14.8f
#define RCS_THR_TARGET_STAT_LOW_VEL_12  -13.6f
#define RCS_THR_TARGET_STAT_LOW_VEL_13  -12.4f
#define RCS_THR_TARGET_STAT_LOW_VEL_14  -11.2f
#define RCS_THR_TARGET_STAT_LOW_VEL_15  -10.0f
#define RCS_THR_TARGET_STAT_LOW_VEL_16  -9.8f
#define RCS_THR_TARGET_STAT_LOW_VEL_17  -9.6f
#define RCS_THR_TARGET_STAT_LOW_VEL_18  -9.4f
#define RCS_THR_TARGET_STAT_LOW_VEL_19  -9.2f
#define RCS_THR_TARGET_STAT_LOW_VEL_20  -9.0f
#define RCS_THR_TARGET_STAT_LOW_VEL_21  -8.8f
#define RCS_THR_TARGET_STAT_LOW_VEL_22  -8.6f
#define RCS_THR_TARGET_STAT_LOW_VEL_23  -8.4f
#define RCS_THR_TARGET_STAT_LOW_VEL_24  -8.2f
#define RCS_THR_TARGET_STAT_LOW_VEL_25  -8.0f
#define RCS_THR_TARGET_STAT_LOW_VEL_26  -7.8f
#define RCS_THR_TARGET_STAT_LOW_VEL_27  -7.6f
#define RCS_THR_TARGET_STAT_LOW_VEL_28  -7.4f
#define RCS_THR_TARGET_STAT_LOW_VEL_29  -7.2f
#define RCS_THR_TARGET_STAT_LOW_VEL_30  -7.0f
#define RCS_THR_TARGET_STAT_LOW_VEL_31  -6.8f
#define RCS_THR_TARGET_STAT_LOW_VEL_32  -6.6f
#define RCS_THR_TARGET_STAT_LOW_VEL_33  -6.4f
#define RCS_THR_TARGET_STAT_LOW_VEL_34  -6.2f
#define RCS_THR_TARGET_STAT_LOW_VEL_35  -6.0f
#define RCS_THR_TARGET_STAT_LOW_VEL_36  -5.8f
#define RCS_THR_TARGET_STAT_LOW_VEL_37  -5.6f
#define RCS_THR_TARGET_STAT_LOW_VEL_38  -5.4f
#define RCS_THR_TARGET_STAT_LOW_VEL_39  -5.2f
#define RCS_THR_TARGET_STAT_LOW_VEL_40  -5.0f


/* RCS-Threshold for traced targets in near scan in 1 m steps in dB square meters */ 
#define RCS_THR_TARGET_TRACED_NEAR_00  -17.0f 
#define RCS_THR_TARGET_TRACED_NEAR_01  -17.0f 
#define RCS_THR_TARGET_TRACED_NEAR_02  -17.0f 
#define RCS_THR_TARGET_TRACED_NEAR_03  -17.0f
#define RCS_THR_TARGET_TRACED_NEAR_04  -17.0f 
#define RCS_THR_TARGET_TRACED_NEAR_05  -17.0f
#define RCS_THR_TARGET_TRACED_NEAR_06  -17.0f
#define RCS_THR_TARGET_TRACED_NEAR_07  -17.0f
#define RCS_THR_TARGET_TRACED_NEAR_08  -16.8f
#define RCS_THR_TARGET_TRACED_NEAR_09  -16.4f
#define RCS_THR_TARGET_TRACED_NEAR_10  -16.0f
#define RCS_THR_TARGET_TRACED_NEAR_11  -15.8f
#define RCS_THR_TARGET_TRACED_NEAR_12  -15.6f
#define RCS_THR_TARGET_TRACED_NEAR_13  -15.4f
#define RCS_THR_TARGET_TRACED_NEAR_14  -15.2f
#define RCS_THR_TARGET_TRACED_NEAR_15  -15.0f
#define RCS_THR_TARGET_TRACED_NEAR_16  -14.8f
#define RCS_THR_TARGET_TRACED_NEAR_17  -14.6f
#define RCS_THR_TARGET_TRACED_NEAR_18  -14.4f
#define RCS_THR_TARGET_TRACED_NEAR_19  -14.2f
#define RCS_THR_TARGET_TRACED_NEAR_20  -14.0f
#define RCS_THR_TARGET_TRACED_NEAR_21  -13.8f
#define RCS_THR_TARGET_TRACED_NEAR_22  -13.6f
#define RCS_THR_TARGET_TRACED_NEAR_23  -13.4f
#define RCS_THR_TARGET_TRACED_NEAR_24  -13.2f
#define RCS_THR_TARGET_TRACED_NEAR_25  -13.0f
#define RCS_THR_TARGET_TRACED_NEAR_26  -12.8f
#define RCS_THR_TARGET_TRACED_NEAR_27  -12.6f
#define RCS_THR_TARGET_TRACED_NEAR_28  -12.4f
#define RCS_THR_TARGET_TRACED_NEAR_29  -12.2f
#define RCS_THR_TARGET_TRACED_NEAR_30  -12.0f
#define RCS_THR_TARGET_TRACED_NEAR_31  -11.8f
#define RCS_THR_TARGET_TRACED_NEAR_32  -11.6f
#define RCS_THR_TARGET_TRACED_NEAR_33  -11.4f
#define RCS_THR_TARGET_TRACED_NEAR_34  -11.2f
#define RCS_THR_TARGET_TRACED_NEAR_35  -11.0f
#define RCS_THR_TARGET_TRACED_NEAR_36  -10.8f
#define RCS_THR_TARGET_TRACED_NEAR_37  -10.6f
#define RCS_THR_TARGET_TRACED_NEAR_38  -10.4f
#define RCS_THR_TARGET_TRACED_NEAR_39  -10.2f
#define RCS_THR_TARGET_TRACED_NEAR_40  -10.0f


/* RCS-Threshold for stationary targets in near scan in 1 m steps in dB square meters */ 
#define RCS_THR_TARGET_STAT_NEAR_00  -17.0f
#define RCS_THR_TARGET_STAT_NEAR_01  -17.0f
#define RCS_THR_TARGET_STAT_NEAR_02  -17.0f
#define RCS_THR_TARGET_STAT_NEAR_03  -17.0f
#define RCS_THR_TARGET_STAT_NEAR_04  -17.0f
#define RCS_THR_TARGET_STAT_NEAR_05  -17.0f
#define RCS_THR_TARGET_STAT_NEAR_06  -17.0f
#define RCS_THR_TARGET_STAT_NEAR_07  -17.0f
#define RCS_THR_TARGET_STAT_NEAR_08  -11.8f
#define RCS_THR_TARGET_STAT_NEAR_09  -11.4f
#define RCS_THR_TARGET_STAT_NEAR_10  -11.0f
#define RCS_THR_TARGET_STAT_NEAR_11  -10.8f
#define RCS_THR_TARGET_STAT_NEAR_12  -10.6f
#define RCS_THR_TARGET_STAT_NEAR_13  -10.4f
#define RCS_THR_TARGET_STAT_NEAR_14  -10.2f
#define RCS_THR_TARGET_STAT_NEAR_15  -10.0f
#define RCS_THR_TARGET_STAT_NEAR_16  -9.8f
#define RCS_THR_TARGET_STAT_NEAR_17  -9.6f
#define RCS_THR_TARGET_STAT_NEAR_18  -9.4f
#define RCS_THR_TARGET_STAT_NEAR_19  -9.2f
#define RCS_THR_TARGET_STAT_NEAR_20  -9.0f
#define RCS_THR_TARGET_STAT_NEAR_21  -8.8f
#define RCS_THR_TARGET_STAT_NEAR_22  -8.6f
#define RCS_THR_TARGET_STAT_NEAR_23  -8.4f
#define RCS_THR_TARGET_STAT_NEAR_24  -8.2f
#define RCS_THR_TARGET_STAT_NEAR_25  -8.0f
#define RCS_THR_TARGET_STAT_NEAR_26  -7.8f
#define RCS_THR_TARGET_STAT_NEAR_27  -7.6f
#define RCS_THR_TARGET_STAT_NEAR_28  -7.4f
#define RCS_THR_TARGET_STAT_NEAR_29  -7.2f
#define RCS_THR_TARGET_STAT_NEAR_30  -7.0f
#define RCS_THR_TARGET_STAT_NEAR_31  -6.8f
#define RCS_THR_TARGET_STAT_NEAR_32  -6.6f
#define RCS_THR_TARGET_STAT_NEAR_33  -6.4f
#define RCS_THR_TARGET_STAT_NEAR_34  -6.2f
#define RCS_THR_TARGET_STAT_NEAR_35  -6.0f
#define RCS_THR_TARGET_STAT_NEAR_36  -5.8f
#define RCS_THR_TARGET_STAT_NEAR_37  -5.6f
#define RCS_THR_TARGET_STAT_NEAR_38  -5.4f
#define RCS_THR_TARGET_STAT_NEAR_39  -5.2f
#define RCS_THR_TARGET_STAT_NEAR_40  -5.0f

/* for low velocities RCS thresholds are lowered in the first 3 meters
   in near scan */
#define RCS_THR_LOW_VELOCITY        (10.f) /* meters per second */

#define RCS_THR_TARGET_TRACED_NEAR_LOW_VEL_00  -20.6f                 /* dB square meters */
#define RCS_THR_TARGET_TRACED_NEAR_LOW_VEL_01  -20.6f  
#define RCS_THR_TARGET_TRACED_NEAR_LOW_VEL_02  -20.6f  
#define RCS_THR_TARGET_TRACED_NEAR_LOW_VEL_03  -17.4f  
#define RCS_THR_TARGET_TRACED_NEAR_LOW_VEL_04  RCS_THR_TARGET_TRACED_NEAR_04 
#define RCS_THR_TARGET_TRACED_NEAR_LOW_VEL_05  RCS_THR_TARGET_TRACED_NEAR_05 
#define RCS_THR_TARGET_TRACED_NEAR_LOW_VEL_06  RCS_THR_TARGET_TRACED_NEAR_06 
#define RCS_THR_TARGET_TRACED_NEAR_LOW_VEL_07  RCS_THR_TARGET_TRACED_NEAR_07 
#define RCS_THR_TARGET_TRACED_NEAR_LOW_VEL_08  RCS_THR_TARGET_TRACED_NEAR_08 
#define RCS_THR_TARGET_TRACED_NEAR_LOW_VEL_09  RCS_THR_TARGET_TRACED_NEAR_09 
#define RCS_THR_TARGET_TRACED_NEAR_LOW_VEL_10  RCS_THR_TARGET_TRACED_NEAR_10 
#define RCS_THR_TARGET_TRACED_NEAR_LOW_VEL_11  RCS_THR_TARGET_TRACED_NEAR_11 
#define RCS_THR_TARGET_TRACED_NEAR_LOW_VEL_12  RCS_THR_TARGET_TRACED_NEAR_12 
#define RCS_THR_TARGET_TRACED_NEAR_LOW_VEL_13  RCS_THR_TARGET_TRACED_NEAR_13 
#define RCS_THR_TARGET_TRACED_NEAR_LOW_VEL_14  RCS_THR_TARGET_TRACED_NEAR_14 
#define RCS_THR_TARGET_TRACED_NEAR_LOW_VEL_15  RCS_THR_TARGET_TRACED_NEAR_15 
#define RCS_THR_TARGET_TRACED_NEAR_LOW_VEL_16  RCS_THR_TARGET_TRACED_NEAR_16 
#define RCS_THR_TARGET_TRACED_NEAR_LOW_VEL_17  RCS_THR_TARGET_TRACED_NEAR_17 
#define RCS_THR_TARGET_TRACED_NEAR_LOW_VEL_18  RCS_THR_TARGET_TRACED_NEAR_18 
#define RCS_THR_TARGET_TRACED_NEAR_LOW_VEL_19  RCS_THR_TARGET_TRACED_NEAR_19 
#define RCS_THR_TARGET_TRACED_NEAR_LOW_VEL_20  RCS_THR_TARGET_TRACED_NEAR_20 
#define RCS_THR_TARGET_TRACED_NEAR_LOW_VEL_21  RCS_THR_TARGET_TRACED_NEAR_21 
#define RCS_THR_TARGET_TRACED_NEAR_LOW_VEL_22  RCS_THR_TARGET_TRACED_NEAR_22 
#define RCS_THR_TARGET_TRACED_NEAR_LOW_VEL_23  RCS_THR_TARGET_TRACED_NEAR_23 
#define RCS_THR_TARGET_TRACED_NEAR_LOW_VEL_24  RCS_THR_TARGET_TRACED_NEAR_24 
#define RCS_THR_TARGET_TRACED_NEAR_LOW_VEL_25  RCS_THR_TARGET_TRACED_NEAR_25 
#define RCS_THR_TARGET_TRACED_NEAR_LOW_VEL_26  RCS_THR_TARGET_TRACED_NEAR_26 
#define RCS_THR_TARGET_TRACED_NEAR_LOW_VEL_27  RCS_THR_TARGET_TRACED_NEAR_27 
#define RCS_THR_TARGET_TRACED_NEAR_LOW_VEL_28  RCS_THR_TARGET_TRACED_NEAR_28 
#define RCS_THR_TARGET_TRACED_NEAR_LOW_VEL_29  RCS_THR_TARGET_TRACED_NEAR_29 
#define RCS_THR_TARGET_TRACED_NEAR_LOW_VEL_30  RCS_THR_TARGET_TRACED_NEAR_30 
#define RCS_THR_TARGET_TRACED_NEAR_LOW_VEL_31  RCS_THR_TARGET_TRACED_NEAR_31 
#define RCS_THR_TARGET_TRACED_NEAR_LOW_VEL_32  RCS_THR_TARGET_TRACED_NEAR_32 
#define RCS_THR_TARGET_TRACED_NEAR_LOW_VEL_33  RCS_THR_TARGET_TRACED_NEAR_33 
#define RCS_THR_TARGET_TRACED_NEAR_LOW_VEL_34  RCS_THR_TARGET_TRACED_NEAR_34 
#define RCS_THR_TARGET_TRACED_NEAR_LOW_VEL_35  RCS_THR_TARGET_TRACED_NEAR_35 
#define RCS_THR_TARGET_TRACED_NEAR_LOW_VEL_36  RCS_THR_TARGET_TRACED_NEAR_36 
#define RCS_THR_TARGET_TRACED_NEAR_LOW_VEL_37  RCS_THR_TARGET_TRACED_NEAR_37 
#define RCS_THR_TARGET_TRACED_NEAR_LOW_VEL_38  RCS_THR_TARGET_TRACED_NEAR_38 
#define RCS_THR_TARGET_TRACED_NEAR_LOW_VEL_39  RCS_THR_TARGET_TRACED_NEAR_39 
#define RCS_THR_TARGET_TRACED_NEAR_LOW_VEL_40  RCS_THR_TARGET_TRACED_NEAR_40 
  
#define RCS_THR_TARGET_STAT_NEAR_LOW_VEL_00  -22.6f 
#define RCS_THR_TARGET_STAT_NEAR_LOW_VEL_01  -22.6f 
#define RCS_THR_TARGET_STAT_NEAR_LOW_VEL_02  -22.6f 
#define RCS_THR_TARGET_STAT_NEAR_LOW_VEL_03  -17.4f 
#define RCS_THR_TARGET_STAT_NEAR_LOW_VEL_04  RCS_THR_TARGET_STAT_NEAR_04
#define RCS_THR_TARGET_STAT_NEAR_LOW_VEL_05  RCS_THR_TARGET_STAT_NEAR_05
#define RCS_THR_TARGET_STAT_NEAR_LOW_VEL_06  RCS_THR_TARGET_STAT_NEAR_06
#define RCS_THR_TARGET_STAT_NEAR_LOW_VEL_07  RCS_THR_TARGET_STAT_NEAR_07
#define RCS_THR_TARGET_STAT_NEAR_LOW_VEL_08  RCS_THR_TARGET_STAT_NEAR_08
#define RCS_THR_TARGET_STAT_NEAR_LOW_VEL_09  RCS_THR_TARGET_STAT_NEAR_09
#define RCS_THR_TARGET_STAT_NEAR_LOW_VEL_10  RCS_THR_TARGET_STAT_NEAR_10
#define RCS_THR_TARGET_STAT_NEAR_LOW_VEL_11  RCS_THR_TARGET_STAT_NEAR_11
#define RCS_THR_TARGET_STAT_NEAR_LOW_VEL_12  RCS_THR_TARGET_STAT_NEAR_12
#define RCS_THR_TARGET_STAT_NEAR_LOW_VEL_13  RCS_THR_TARGET_STAT_NEAR_13
#define RCS_THR_TARGET_STAT_NEAR_LOW_VEL_14  RCS_THR_TARGET_STAT_NEAR_14
#define RCS_THR_TARGET_STAT_NEAR_LOW_VEL_15  RCS_THR_TARGET_STAT_NEAR_15
#define RCS_THR_TARGET_STAT_NEAR_LOW_VEL_16  RCS_THR_TARGET_STAT_NEAR_16
#define RCS_THR_TARGET_STAT_NEAR_LOW_VEL_17  RCS_THR_TARGET_STAT_NEAR_17
#define RCS_THR_TARGET_STAT_NEAR_LOW_VEL_18  RCS_THR_TARGET_STAT_NEAR_18
#define RCS_THR_TARGET_STAT_NEAR_LOW_VEL_19  RCS_THR_TARGET_STAT_NEAR_19
#define RCS_THR_TARGET_STAT_NEAR_LOW_VEL_20  RCS_THR_TARGET_STAT_NEAR_20
#define RCS_THR_TARGET_STAT_NEAR_LOW_VEL_21  RCS_THR_TARGET_STAT_NEAR_21
#define RCS_THR_TARGET_STAT_NEAR_LOW_VEL_22  RCS_THR_TARGET_STAT_NEAR_22
#define RCS_THR_TARGET_STAT_NEAR_LOW_VEL_23  RCS_THR_TARGET_STAT_NEAR_23
#define RCS_THR_TARGET_STAT_NEAR_LOW_VEL_24  RCS_THR_TARGET_STAT_NEAR_24
#define RCS_THR_TARGET_STAT_NEAR_LOW_VEL_25  RCS_THR_TARGET_STAT_NEAR_25
#define RCS_THR_TARGET_STAT_NEAR_LOW_VEL_26  RCS_THR_TARGET_STAT_NEAR_26
#define RCS_THR_TARGET_STAT_NEAR_LOW_VEL_27  RCS_THR_TARGET_STAT_NEAR_27
#define RCS_THR_TARGET_STAT_NEAR_LOW_VEL_28  RCS_THR_TARGET_STAT_NEAR_28
#define RCS_THR_TARGET_STAT_NEAR_LOW_VEL_29  RCS_THR_TARGET_STAT_NEAR_29
#define RCS_THR_TARGET_STAT_NEAR_LOW_VEL_30  RCS_THR_TARGET_STAT_NEAR_30
#define RCS_THR_TARGET_STAT_NEAR_LOW_VEL_31  RCS_THR_TARGET_STAT_NEAR_31
#define RCS_THR_TARGET_STAT_NEAR_LOW_VEL_32  RCS_THR_TARGET_STAT_NEAR_32
#define RCS_THR_TARGET_STAT_NEAR_LOW_VEL_33  RCS_THR_TARGET_STAT_NEAR_33
#define RCS_THR_TARGET_STAT_NEAR_LOW_VEL_34  RCS_THR_TARGET_STAT_NEAR_34
#define RCS_THR_TARGET_STAT_NEAR_LOW_VEL_35  RCS_THR_TARGET_STAT_NEAR_35
#define RCS_THR_TARGET_STAT_NEAR_LOW_VEL_36  RCS_THR_TARGET_STAT_NEAR_36
#define RCS_THR_TARGET_STAT_NEAR_LOW_VEL_37  RCS_THR_TARGET_STAT_NEAR_37
#define RCS_THR_TARGET_STAT_NEAR_LOW_VEL_38  RCS_THR_TARGET_STAT_NEAR_38
#define RCS_THR_TARGET_STAT_NEAR_LOW_VEL_39  RCS_THR_TARGET_STAT_NEAR_39
#define RCS_THR_TARGET_STAT_NEAR_LOW_VEL_40  RCS_THR_TARGET_STAT_NEAR_40

#define OBJ_NUMBER_LENGTH_OF_OOI_LIST   (OBJ_NEXT_LAT_RIGHT_OOI + 1)


/*****************************************************************************
  Acces Macros to rte data buffers
*****************************************************************************/

#define MAX_NUM_OF_SCANS                (2)

#define LANE_SIDES          (2L)    /* Left and Right */
#define SIDE_LEFT           (0L)
#define SIDE_RIGHT          (1L)

#define OBJ_INDEX_NO_OBJECT     ((ObjNumber_t)-1)

#define NUMBER_OF_OBJECTS_      NUMBER_OF_OBJECTS


/*-------------------------------------------------------------------------
| Konstanten für Strassenbreiten und Fahrzeugbreiten                      |
-------------------------------------------------------------------------*/
#define STRASSENBREITE       (3.75F)
#define HALBESTRASSENBREITE  (STRASSENBREITE/2.0F)

#define FAHRZEUGBREITE       (2.2F)
#define HALBEFAHRZEUGBREITE  (FAHRZEUGBREITE/2.F)

/*-------------------------------------------------------------------------
| Constants for ACC object quality for function preselection              |
-------------------------------------------------------------------------*/

#define FUN_PRESEL_ACC_MIN_OBJ_QUAL         70
#define FUN_PRESEL_ACC_MIN_INLANE_OBJ_QUAL  85

/*****************************************************************************
  MACROS 
*****************************************************************************/

/*! ------------------ gdb object data macros -------------------------*/


/*****************************************************************************

  EM Object List (refered to as Object List)

  In order to access any information from the object list your component has
  to define the following access macro(s) to access the apropriate buffer:
    GET_EM_PUB_OBJ_DATA_PTR - It shall return the pointer to the EM object
                              list (optionally constant, if no fields are
                              modified)
                              type: ObjectList *

*****************************************************************************/

/* utility macro to access per-object data */
#define GET_EM_OBJ_PUB(iObj)                      GET_EM_PUB_OBJ_DATA_PTR->Objects[iObj]

/* Object kinematic */
#define OBJ_KINEMATIC(iObj)                       GET_EM_OBJ_PUB(iObj).Kinematic
/* Object general */
#define OBJ_GENERAL(iObj)                         GET_EM_OBJ_PUB(iObj).General
/* Object legacy */
#define OBJ_LEGACY(iObj)                          GET_EM_OBJ_PUB(iObj).Legacy
/* Object history */
#define OBJ_HISTORY(iObj)                         GET_EM_OBJ_PUB(iObj).History
/* Object Attributes */
#define OBJ_ATTRIBUTES(iObj)                      GET_EM_OBJ_PUB(iObj).Attributes
/* Object Qualifiers */
#define OBJ_QUALIFIERS(iObj)                      GET_EM_OBJ_PUB(iObj).Qualifiers
/* Object Geometry */
#define OBJ_GEOMETRY(iObj)                        GET_EM_OBJ_PUB(iObj).Geometry


/*
  Macros to query object kinematic data (based on GET_EM_OBJ_PUB(iObj))
*/
#define OBJ_LONG_DISPLACEMENT(iObj)               OBJ_KINEMATIC(iObj).fDistX
#define OBJ_LONG_VREL(iObj)                       OBJ_KINEMATIC(iObj).fVrelX
#define OBJ_LONG_AREL(iObj)                       OBJ_KINEMATIC(iObj).fArelX

#define OBJ_LAT_DISPLACEMENT(iObj)                OBJ_KINEMATIC(iObj).fDistY
#define OBJ_LAT_VREL(iObj)                        OBJ_KINEMATIC(iObj).fVrelY
#define OBJ_LAT_AREL(iObj)                        OBJ_KINEMATIC(iObj).fArelY

/*
  Macros to access object kinematic variance (based on GET_EM_OBJ_PUB(iObj))
*/
#define OBJ_LONG_DISPLACEMENT_VAR(iObj)           SQR(OBJ_KINEMATIC(iObj).fDistXStd)   //TPObject[iObj].OT.Kalman.PMatrixX.f00
#define OBJ_LONG_DISPLACEMENT_STD(iObj)           OBJ_KINEMATIC(iObj).fDistXStd        //TPObject[iObj].OT.Kalman.PMatrixX.f00
#define OBJ_LONG_VREL_VAR(iObj)                   SQR(OBJ_KINEMATIC(iObj).fVrelXStd)   //TPObject[iObj].OT.Kalman.PMatrixX.f11
#define OBJ_LONG_VREL_STD(iObj)                   OBJ_KINEMATIC(iObj).fVrelXStd        //TPObject[iObj].OT.Kalman.PMatrixX.f11
#define OBJ_LONG_AREL_VAR(iObj)                   SQR(OBJ_KINEMATIC(iObj).fArelXStd)   //TPObject[iObj].OT.Kalman.PMatrixX.f22
#define OBJ_LONG_AREL_STD(iObj)                   OBJ_KINEMATIC(iObj).fArelXStd        //TPObject[iObj].OT.Kalman.PMatrixX.f22

#define OBJ_LAT_DISPLACEMENT_VAR(iObj)            SQR(OBJ_KINEMATIC(iObj).fDistYStd)   //TPObject[iObj].OT.Kalman.PMatrixY.f00
#define OBJ_LAT_DISPLACEMENT_STD(iObj)            OBJ_KINEMATIC(iObj).fDistYStd        //TPObject[iObj].OT.Kalman.PMatrixY.f00
#define OBJ_LAT_VREL_VAR(iObj)                    SQR(OBJ_KINEMATIC(iObj).fVrelYStd)   //TPObject[iObj].OT.Kalman.PMatrixY.f11
#define OBJ_LAT_VREL_STD(iObj)                    OBJ_KINEMATIC(iObj).fVrelYStd        //TPObject[iObj].OT.Kalman.PMatrixY.f11
#define OBJ_LAT_AREL_VAR(iObj)                    SQR(OBJ_KINEMATIC(iObj).fArelYStd)  
#define OBJ_LAT_AREL_STD(iObj)                    OBJ_KINEMATIC(iObj).fArelYStd       

/*
  Macros to access X distance sorted object indices (based on GET_EM_PUB_OBJ_DATA_PTR)
*/
#define EM_OBJ_INDEX_DISTX_SORTED                 GET_EM_PUB_OBJ_DATA_PTR->HeaderObjList.iSortedObjectList

/*
  Macros to access object ID (identity transform, no dependency)
*/
#define OBJ_GET_ID_I(iObj)                        iObj

/*
  Macro to access number of objects (based on GET_EM_PUB_OBJ_DATA_PTR)
*/
#define OBJ_NUMBER_OF_OBJ_USED                    GET_EM_PUB_OBJ_DATA_PTR->HeaderObjList.iNumOfUsedObjects

/*
  Macro to access object lifetime (based on GET_EM_OBJ_PUB(iObj))
*/
#define OBJ_LIFETIME(iObj)                        OBJ_LEGACY(iObj).uiLifeTime

#define OBJ_TIMESTAMP(iObj)                       OBJ_GENERAL(iObj).fTimeStamp

/*
  Macros for object maintenance state (based on GET_EM_OBJ_PUB(iObj))
*/
#define OBJ_MERGE_DELETE_FLAG(iObj)               OBJ_GENERAL(iObj).cObjMergingID
#define OBJ_MERGE(iObj,iDest)                     OBJ_GENERAL(iObj).cObjMergingID = iDest
#if 0
#define OBJ_DELETE_VALUE                          -1
#define OBJ_DELETE(iObj)                          OBJ_GENERAL(iObj).cObjMergingID = OBJ_DELETE_VALUE
#endif

#define OBJ_MAINTENANCE_STATE(iObj)               (OBJ_GENERAL(iObj).eObjMaintenanceState)
#define OBJ_DELETE(iObj)                          OBJ_GENERAL(iObj).eObjMaintenanceState = MT_STATE_DELETED
#define OBJ_IS_DELETED(iObj)                      ((OBJ_GENERAL(iObj).eObjMaintenanceState == MT_STATE_DELETED) || (OBJ_GENERAL(iObj).eObjMaintenanceState == MT_STATE_MERGE_DELETED))

#define OT_GET_KALMAN_MAX_ACCEL_Y(iObj)           OBJ_LEGACY(iObj).fMaxAccelY       //TPObject[iObj].OT.Kalman.fMaxAccelY

/* target pos */
#define OBJ_TGT_LAST_DISTANCE(iObj)               OBJ_LEGACY(iObj).fLastTargetDistX               //TPObject[iObj].OT.LastTarget.Entfernung
#define OBJ_TGT_LONG_DISPLACEMENT(iObj)           GET_EM_OBJ_PUB(iObj).SensorSpecific.fCurrentTargetDistX    //TPObject[iObj].OT.CurrentTarget.fDistX
#define OBJ_TGT_LAT_DISPLACEMENT(iObj)            GET_EM_OBJ_PUB(iObj).SensorSpecific.fCurrentTargetDistY       //TPObject[iObj].OT.CurrentTarget.fDistY
#define OBJ_TGT_VREL_RAD(iObj)                    GET_EM_OBJ_PUB(iObj).SensorSpecific.fCurrentTargetVrelRad    //TPObject[iObj].OT.CurrentTarget.fRelSpeedPolar
#define OBJ_TGT_PDH0(iObj)                        GET_EM_OBJ_PUB(iObj).SensorSpecific.fCurrentTargetPDH0    //TPObject[iObj].OT.CurrentTarget.fRelSpeedPolar
#define OBJ_TGT_LAST_HORZ_DISPLACEMENT(iObj)      OBJ_LEGACY(iObj).fLastTargetDistY               //TPObject[iObj].OT.LastTarget.HorizontaleAblage 

#define OBJ_ANGLE(iObj)                           OBJ_LEGACY(iObj).fAngle

/****************************** Object history *********************************/
#define OBJ_LONG_DISPLACMEMT_FIRST_DETECT(iObj)   OBJ_HISTORY(iObj).fFirstDetectX
#define OBJ_LAT_DISPLACMEMT_FIRST_DETECT(iObj)    OBJ_HISTORY(iObj).fFirstDetectY
#define OBJ_TRACE_ID(iObj)                        OBJ_HISTORY(iObj).uiReferenceToTrace

/* object attributes */
#define OBJ_DYNAMIC_PROPERTY(iObj)                OBJ_ATTRIBUTES(iObj).eDynamicProperty
#define OBJ_DYNAMIC_SUB_PROPERTY(iObj)            OBJ_LEGACY(iObj).eDynamicSubProperty
#define OBJ_CLASSIFICATION(iObj)                  OBJ_ATTRIBUTES(iObj).eClassification
#define OBJ_MOVING_TO_STATIONARY(iObj)            OBJ_ATTRIBUTES(iObj).uiStoppedConfidence
// The below define is equivalent, but used in code which only evaluates for bool-ness
#define OBJ_IS_MOVING_TO_STATIONARY(iObj)         (OBJ_ATTRIBUTES(iObj).uiStoppedConfidence > 80U)

/* object Geometry */
#define OBJ_ORIENTATION(iObj)                     OBJ_GEOMETRY(iObj).fOrientation     
#define OBJ_ORIENTATION_STD(iObj)                 OBJ_GEOMETRY(iObj).fOrientationStd  
#define OT_GET_OBJ_WIDTH(iObj)                    OBJ_GEOMETRY(iObj).fWidth          // OTGetObjectWidth(iObj)
#define OT_GET_OBJ_WIDTH_STD(iObj)                OBJ_GEOMETRY(iObj).fWidthStd       // OTGetObjectWidthVar((ui32_t)iObj))
#define OT_GET_OBJ_LENGTH(iObj)                   OBJ_GEOMETRY(iObj).fLength         // OTGetObjectLength(iObj)
#define OT_GET_OBJ_LENGTH_STD(iObj)               OBJ_GEOMETRY(iObj).fLengthStd      
#define OBJ_CLASS_CONFIDENCE(iObj)                OBJ_LEGACY(iObj).fClassConfidence             // Attributes.uiClassConfidence

/* additional object atttributs */
#define OBJ_RCS_TGT_TRESHOLD(iObj)                OBJ_RCS_TGT_TRESHOLD_UNCOMP(iObj) - RSP_INPUT_REQ_SMALL_TGT_THRESHOLD //TPGetRCSThrTarget(OBJ_LONG_DISPLACEMENT(ObjNr), OBJ_DYNAMIC_PROPERTY(ObjNr))
#define OBJ_RCS_TGT_TRESHOLD_UNCOMP(iObj)         OBJ_LEGACY(iObj).fRCSTargetThresholdUncomp // TPGetRCSThrTargetUncomp (OBJ_LONG_DISPLACEMENT(ObjNr), OBJ_DYNAMIC_SUB_PROPERTY(ObjNr))

#define OBJ_RCS(iObj)                             GET_EM_OBJ_PUB(iObj).SensorSpecific.fRCS

#define OBJ_LONG_VEHICLE_TYPE(iObj)               OBJ_LEGACY(iObj).eObjRelationsClass

#define OBJ_IS_SHADOW(iObj)                       ((OBJ_LONG_VEHICLE_TYPE(iObj) == LONGVEHICLE_TYPE_MIRROR) ? TRUE : FALSE)
#define OBJ_IS_REAR(iObj)                         ((OBJ_LONG_VEHICLE_TYPE(iObj) == LONGVEHICLE_TYPE_REAR) ? TRUE : FALSE)

#define OBJ_CLEAR_MEASURED(iObj)                  OBJ_LEGACY(iObj).ucMeasuredSources = MEAS_SEN_NONE
#define OBJ_SET_MEASURED(iObj, ucMask)            OBJ_LEGACY(iObj).ucMeasuredSources = (OBJ_LEGACY(iObj).ucMeasuredSources | (ucMask))
#define OBJ_IS_MEASURED(iObj, ucMask)             ((OBJ_LEGACY(iObj).ucMeasuredSources & (ucMask)) ? TRUE : FALSE)

#define OBJ_GET_FOV_OVERLAP_FAR(iObj)             OBJ_LEGACY(iObj).eFOVOverlapFar                //bool_t OTGetObjFOVOverlapFar(ui32_t uiObject)

/****************************** Object qualifiers *********************************/
/* object Quality */
#define OBJ_PROBABILITY_OF_EXIST(iObj)            OBJ_QUALIFIERS(iObj).fProbabilityOfExistence

/* road, roadtype, border, lane, grid*/ 
#define OBJ_OBSTACLE_PROBABILITY(iObj)            OBJ_QUALIFIERS(iObj).ucObstacleProbability
#define OBJ_OBSTACLE_TYPE(iObj)                   OBJ_QUALIFIERS(iObj).eObstacleClass //TPObject[ObjID].EO.uiObstacleType
#define OBJ_IN_BRIDGE_ZONE(iObj)                  OBJ_QUALIFIERS(iObj).bInBridgeZone
#define OBJ_IN_OTS_ZONE(iObj)                     OBJ_QUALIFIERS(iObj).bInOtsZone

/* additional object atttributs */
#define OT_GET_TGT_CONFIRM_DENSITY(iObj)          OBJ_QUALIFIERS(iObj).uMeasuredTargetFrequency            //TPObject[ObjNr].OT.uZielBestaetDichte


/*
  Macros for accessing trace-related object qualities (based on GET_EM_OBJ_PUB(iObj))
*/
#define TRACE_HIT_POS_QUALITY(iObj)               OBJ_LEGACY(iObj).fTraceHitPosQuality //TPObject[iObj].EO.Approx.dQuality
#define TRACE_HIT_POS(iObj)                       OBJ_LEGACY(iObj).fTraceHitPos        //TPObject[iObj].EO.Approx.dHitPos

/*
  Macros for accessing EM-based function pre-selection information (based on GET_EM_OBJ_PUB(iObj))
*/
#define OBJ_GET_ACC_FUN_PRESEL_QUALITY(iObj)      GET_EM_OBJ_PUB(iObj).ACCPresel.ucAccObjQuality
#define OBJ_GET_EBA_MOV_PRESEL_QUALITY(iObj)      GET_EM_OBJ_PUB(iObj).EBAPresel.ucEbaMovingObjQuality
#define OBJ_GET_EBA_STAT_PRESEL_QUALITY(iObj)     GET_EM_OBJ_PUB(iObj).EBAPresel.ucEbaStationaryObjQuality
#define OBJ_GET_OBJ_SPEC_PRESEL_FLAGS(iObj)       GET_EM_OBJ_PUB(iObj).ObjSpecPresel.ucObjSpecSelBits

/*
  Macros for accessing per-object blockage data (based on GET_EM_OBJ_PUB(iObj))
*/
#define OBJ_PD_NEAR_OBJ_IN_BEAM(iObj)             OBJ_LEGACY(iObj).bNearObjInBeam


/*****************************************************************************

  FCT Object list - Assessed object list

  In order to access any information from the assessed object list
  your component has to define the access macro(s):
    GET_FCT_PUB_OBJ_DATA_PTR- It shall return the pointer to the assessed
                              object list buffer
                              type: AssessedObjList_t *

*****************************************************************************/

/* Internally used utility macro to access object at index */
#define GET_FCT_OBJ_PUB(iObj)                     GET_FCT_PUB_OBJ_DATA_PTR->ObjList[iObj]

/*
  Macros for accessing ACC assessed object list header
*/
#define FCT_PUB_OBJ_LIST_VERSION                  GET_FCT_PUB_OBJ_DATA_PTR->uiVersionNumber   // GET_FCT_PUB_OBJ_DATA_PTR->HeaderAssessedObjList.uiVersionNumber
#define FCT_PUB_OBJ_LIST_NUM_OBJS                 GET_FCT_PUB_OBJ_DATA_PTR->HeaderAssessedObjList.iNumOfUsedObjects

/*
  Macros for accessing ACC Assessed Object List per object (based on GET_FCT_OBJ_PUB(iObj))
*/
#define OBJ_GET_ASSOCIATED_LANE(iObj)             GET_FCT_OBJ_PUB(iObj).LaneInformation.eAssociatedLane    // SIGetAssociateLane
#define OBJ_GET_OOI_POS(iObj)                     GET_FCT_OBJ_PUB(iObj).ObjOfInterest.eObjOOI
#define OBJ_GET_RELEVANT(iObj)                    (OBJ_GET_OOI_POS(iObj) == OBJ_NEXT_OOI) //((iObj >= 0) && (iObj == EMRelObjPrevCycle))
#define OBJ_GET_OBJ_TO_REF_DISTANCE(iObj)         GET_FCT_OBJ_PUB(iObj).Legacy.fDistToRef         // SITrajGetObjToRefDistance((ui32_t)i_Obj, &fDistLat, &fDistLatVar); 
#define OBJ_GET_CUT_IN_POTENTIAL(iObj)            GET_FCT_OBJ_PUB(iObj).LaneInformation.uiCutInProbability
#define OBJ_GET_CUT_OUT_POTENTIAL(iObj)           GET_FCT_OBJ_PUB(iObj).LaneInformation.uiCutOutProbability
#define OBJ_GET_EXTERNAL_OBJ_ID(iObj)             GET_FCT_OBJ_PUB(iObj).ObjOfInterest.cExternalID

/*
  Macros for accessing ACC Assessed Object List object of interest array (based on GET_FCT_PUB_OBJ_DATA_PTR)
*/
#define OBJ_GET_OOI_LIST_OBJ_IDX(iOoiPos)         GET_FCT_PUB_OBJ_DATA_PTR->HeaderAssessedObjList.aiOOIList[iOoiPos]
#define OBJ_GET_RELEVANT_OBJ_NR                   OBJ_GET_OOI_LIST_OBJ_IDX(OBJ_NEXT_OOI)       //iRelObjNr

/*
  Macros for accessing EBA CD object data (based on GET_FCT_OBJ_PUB(iObj))
*/
#define OBJ_GET_EM_CD_OBJECT_PROBABILITY(iObj)    (( ((ObjNumber_t)OBJ_MERGE_DELETE_FLAG(iObj)) == (iObj))?(GET_FCT_OBJ_PUB(iObj).Legacy.CDObjectQuality):(0.0f)) // pScanObjectList[uiScanObj]->SA_CD.ObjectProbability


/*****************************************************************************

  Radar signal processing data

  In order to access any information from the assessed object list
  your component has to define the access macro(s):
    RSP_GET_KONTEXT_DATA_PTR  - It shall return the pointer to the RSP data
                                buffer
                                type: RSPKontextData_t *

*****************************************************************************/

/* RSP data */
#define RSP_GET_DATA_RANGE                        RSP_GET_KONTEXT_DATA_PTR->Range      //TPGetRSPKontextDataRange()
#define RSP_GET_RANGE_GATE_LENGTH                 RSP_GET_KONTEXT_DATA_PTR->RgLength   //TPSetRspRgLength()

#define RSP_IS_TGT_LIST_NEAR_VALID                RSP_GET_TGT_LIST_NEAR_PTR->TargetListValid //TPGetTargetListNear()
#define RSP_IS_TGT_LIST_FAR_VALID                 RSP_GET_TGT_LIST_FAR_PTR->TargetListValid  //TPGetTargetListNear()

#if 0

#define RSP_AZIM_MISALIGNMENT_PTR                 GET_RSP_PUB_DATA_PTR->AzimuthMisalignment           //

#define RSP_USED_AZIM_MISALIGN_ANGLE              GET_RSP_PUB_DATA_PTR->AzimuthMisalignment->fUsedAzimuthMisalignmentAngle         //TPGetUsedAzimuthMisalignmentAngle()
#define RSP_RECENT_AZIM_MISALIGN_ANGLE            GET_RSP_PUB_DATA_PTR->AzimuthMisalignment->fRecentAzimuthMisalignmentAngle       //TPGetRecentAzimuthMisalignmentAngle()
#define RSP_RECENT_AZIM_MISALIGN_ANGLE_DEV        GET_RSP_PUB_DATA_PTR->AzimuthMisalignment->fRecentAzimuthMisalignmentAngle_Dev   //TPGetRecentAzimuthMisalignmentAngleDev()
#define RSP_RECENT_AZIM_MISALIGN_ANGLE_VALID      GET_RSP_PUB_DATA_PTR->AzimuthMisalignment->bRecentAzimuthMisalignmentAngleValid  //TPGetRecentAzimuthMisalignmentAngleValid()
#endif

#define GET_AZ_FOF_LEFT(iBand)                    RSP_GET_KONTEXT_DATA_PTR->AzFieldOfView[iBand].Left      //TPGetRspAzFOVLeft(iBand)
#define GET_AZ_FOF_RIGHT(iBand)                   RSP_GET_KONTEXT_DATA_PTR->AzFieldOfView[iBand].Right     //TPGetRspAzFOVRight(iBand)

#define GET_TAN_AZ_FOF_LEFT(iBand)                RSP_GET_KONTEXT_DATA_PTR->AzFieldOfView[iBand].TanLeft      //TPGetRspTanAzFOVLeft(iBand)
#define GET_TAN_AZ_FOF_RIGHT(iBand)               RSP_GET_KONTEXT_DATA_PTR->AzFieldOfView[iBand].TanRight     //TPGetRspTanAzFOVRight(iBand)

#define SET_AZ_FOF(fFarLeft, fFarRight, fNearLeft, fNearRight)       \
  RSP_GET_KONTEXT_DATA_PTR->AzFieldOfView[0].RSPAngle_T_Left   = fFarLeft;  \
  RSP_GET_KONTEXT_DATA_PTR->AzFieldOfView[0].RSPAngle_T_Right  = fFarRight; \
  RSP_GET_KONTEXT_DATA_PTR->AzFieldOfView[1].RSPAngle_T_Left   = fNearLeft; \
  RSP_GET_KONTEXT_DATA_PTR->AzFieldOfView[1].RSPAngle_T_Right  = fNearRight;

/*****************************************************************************

  Radar signal processing output data

  In order to access any information from the assessed object list
  your component has to define the access macro(s):
    RSP_GET_RSP_INPUT_EM_PTR    - It shall return the pointer to the RSP data
                                  buffer
                                  type: RSPInputEM_t *

*****************************************************************************/

/* the required region of interest */
#define RSP_INPUT_REQ_REGION_OF_INTEREST          RSP_GET_RSP_INPUT_EM_PTR->RegionOfInterst

/* the required smapp tgt threshold */
#define RSP_INPUT_REQ_SMALL_TGT_THRESHOLD         RSP_GET_RSP_INPUT_EM_PTR->ReqSmallTarThres           //TPWGetSmallTarThres



/*****************************************************************************

  Performance degradation input data

  In order to access any information from the performance degradation input data
  your component has to define the access macro(s):
    GET_PERF_DEG_DATA_INPUT_PTR   - It shall return the pointer to the performance
                                    degradation input data buffer
                                    type: PerfDegrExtInput_t *

*****************************************************************************/

/*
  Macros for accessing global blockage information (based on GET_PERF_DEG_DATA_INPUT_PTR)
*/
#define PD_GET_SRD_SYS_DAMP                       GET_PERF_DEG_DATA_INPUT_PTR->eSRDSysDamp             //TPGetSRDSysDamp()

/*****************************************************************************

  Performance degradation RPS input data

  In order to access any information from the performance degradation input data
  your component has to define the access macro(s):
    GET_RSP_PD_OUTPUT_DATA_PTR   - It shall return the pointer to the performance
                            degradation RSP input data buffer
                            type: RSPOutputPD_t *

*****************************************************************************/

#define RSP_OUT_PD_GET_ROADBEAM_VISIBILITY        GET_RSP_PD_OUTPUT_DATA_PTR->RSPBlockageData.RoadVisibility
#define RSP_OUT_PD_GET_ROADBEAM_VISIBILITY_QUAL   GET_RSP_PD_OUTPUT_DATA_PTR->RSPBlockageData.iQuality
#define RSP_OUT_PD_GET_ROADBEAM_SENSOR_TILTED     GET_RSP_PD_OUTPUT_DATA_PTR->RSPBlockageData.SensorTilted

/*****************************************************************************

  Performance degradation data

  In order to access any information from the performance degradation data
  your component has to define the access macro(s):
    GET_PERF_DEG_DATA_PTR   - It shall return the pointer to the performance
                              degradation data buffer
                              type: GDBPerfDegr_t *

*****************************************************************************/

/*
  Macros for accessing global blockage information (based on GET_PERF_DEG_DATA_PTR)
*/
#define PD_GET_FUSED_RANGE_VALUE                  GET_PERF_DEG_DATA_PTR->RangeFused.fFusedRange        //PDGetRange(RangeData) RangeData.Val[PD_RANGE_MEAN]
#define PD_GET_FUSED_RANGE_CONF                   GET_PERF_DEG_DATA_PTR->RangeFused.fFusedConf         //PDGetRange(RangeData) RangeData.Conf[PD_RANGE_MEAN]
#define PD_GET_RAW_MOV_RANGE_VALUE                GET_PERF_DEG_DATA_PTR->RangeRaw.fMovingMeanRaw
#define PD_GET_RAW_MOV_RANGE_CONF                 GET_PERF_DEG_DATA_PTR->RangeRaw.fMovingConfRaw
#define PD_GET_RAW_STAT_RANGE_VALUE               GET_PERF_DEG_DATA_PTR->RangeRaw.fStationaryMeanRaw
#define PD_GET_RAW_STAT_MAX_RANGE_VALUE           GET_PERF_DEG_DATA_PTR->RangeRaw.fStationaryMaxRaw
#define PD_GET_RAW_STAT_RANGE_CONF                GET_PERF_DEG_DATA_PTR->RangeRaw.fStationaryConfRaw
#define PD_GET_TIMEOUT_TIME_TEMP                  GET_PERF_DEG_DATA_PTR->Timeout.fTimeCounter          //PDGetTimeoutData(TimeoutData) TimeoutData.TimeTemp
#define PD_GET_TIMEOUT_WAY_TEMP                   GET_PERF_DEG_DATA_PTR->Timeout.fWayCounter           //PDGetTimeoutData(TimeoutData) TimeoutData.WayTemp
#define PD_GET_ROADBEAM                           GET_PERF_DEG_DATA_PTR->RoadbeamInput                 //TPGetRoadbeamData

/* Tunnel Probability */
#define TUNNEL_PROBABILITY                        GET_PERF_DEG_DATA_PTR->fTunnelProbability   //


/*****************************************************************************

  System Performance Monitoring data

  In order to access any information from the system performance monitoring
  your component has to define the access macro(s):
    GET_SPM_DATA_PTR        - It shall return the pointer to the system
                              performance monitoring data buffer
                              type: GDBSysPerfMon_t *

*****************************************************************************/

#define SPM_RESET_BLOCKAGE_CRITERIA_FLAG          GET_SPM_DATA_PTR->bResetBlockageCriteria

#ifdef HINWEIS
#pragma message(__FILE__"("STRING_QUOTE(__LINE__)"): Move this section to the private block of fct")
#endif
#if 0
//PDState.Selftest.Prev = PDState.Selftest.Cur
// 2009.11.16: currently previous/current self test state is write only, this code is
// obsolete based on feedback from A. Schlensag
#define SPM_SAVE_SELFTEST_STATE                   GET_SPM_DATA_PTR->AlgoStates.Selftest.Prev = GET_SPM_DATA_PTR->AlgoStates.Selftest.Cur
//PDState.Selftest.Cur  = SPMData.SPMSelftestState;
#define SPM_SET_SELFTEST_STATE(uNewState)         GET_SPM_DATA_PTR->AlgoStates.Selftest.Cur = uNewState

//PDState.SRDSysDamp.Prev = PDState.SRDSysDamp.Cur
#define SPM_SAVE_SYS_DAMP_STATE                   GET_SPM_DATA_PTR->AlgoStates.SRDSysDamp.Prev = GET_SPM_DATA_PTR->AlgoStates.SRDSysDamp.Cur
#define SPM_GET_SYS_DAMP_STATE                    GET_SPM_DATA_PTR->AlgoStates.SRDSysDamp.Cur  //PDState.SRDSysDamp.Cur

#define SPM_GET_OBJECT_LOSS_STATE                 GET_SPM_DATA_PTR->AlgoStates.ObjectLoss.Cur  //PDState.ObjectLoss.Cur

#define SPM_GET_TIME_OUT_STATE                    GET_SPM_DATA_PTR->AlgoStates.Timeout.Cur     //PDState.Timeout.Cur
#endif

/*****************************************************************************

  Ego Dynamic Data Raw (VDYN-Raw)

  In order to access any information from the ego dynamic data your component
  has to define the access macro(s):
    GET_EGO_RAW_DATA_PTR    - It shall return the pointer to the raw ego
                              dynamic data buffer
                              type: VehDyn_t *

*****************************************************************************/

//#define GET_EGO_RAW_DATA_PTR                      GET_EGO_DYN_DATA_PTR->raw

/* Raw access macros */
#define EGO_SPEED_X_STATE                         VDY_GET_IO_STATE(VDY_SOUT_POS_VEL, GET_EGO_RAW_DATA_PTR->State) //GET_EGO_RAW_DATA_PTR->States.bVelocityX            //EMGetEgoSpeedXUncorrectedRawState()

#define EGO_SPEED_X_RAW                           GET_EGO_RAW_DATA_PTR->Longitudinal.MotVar.Velocity              //TPGetEgoSpeedXRaw() TPGetEgoSpeedXUncorrectedRaw()
#define EGO_SPEED_X_VAR_RAW                       GET_EGO_RAW_DATA_PTR->Longitudinal.MotVar.varVelocity           //TPGetEgoSpeedXVarRaw()

#define EGO_SPEED_X_CORRECTED_STATE               VDY_GET_IO_STATE(VDY_SOUT_POS_VCORR, GET_EGO_RAW_DATA_PTR->State)

#define EGO_SPEED_X_CORRECTED                     GET_EGO_RAW_DATA_PTR->Longitudinal.VeloCorr.corrVelo            //TPGetVehicleSpeedCorrected()
#define EGO_SPEED_X_CORRECTED_VAR                 GET_EGO_RAW_DATA_PTR->Longitudinal.VeloCorr.corrVeloVar         //TPGetVehicleSpeedCorrectedVar()

#define EGO_ACCEL_X_STATE                         VDY_GET_IO_STATE(VDY_SOUT_POS_ACCEL, GET_EGO_RAW_DATA_PTR->State) 
#define EGO_ACCEL_X_RAW                           GET_EGO_RAW_DATA_PTR->Longitudinal.MotVar.Accel                 //TPGetEgoAccelXTgtRaw();
#define EGO_ACCEL_X_VAR_RAW                       GET_EGO_RAW_DATA_PTR->Longitudinal.MotVar.varAccel              //TPGetEgoAccelXVarRawVAR();

#define EGO_YAW_RATE_STATE                        VDY_GET_IO_STATE(VDY_SOUT_POS_YWR, GET_EGO_RAW_DATA_PTR->State) //GET_EGO_RAW_DATA_PTR->States.bYawRate              //
#define EGO_YAW_RATE_RAW                          GET_EGO_RAW_DATA_PTR->Lateral.YawRate.YawRate                    //TPGetEgoYawRateRaw()
#define EGO_YAW_RATE_VAR_RAW                      GET_EGO_RAW_DATA_PTR->Lateral.YawRate.Variance                   //
#define EGO_YAW_RATE_QUALITY_RAW                  GET_EGO_RAW_DATA_PTR->Lateral.YawRate.Quality

#define EGO_CURVE_RAW                             GET_EGO_RAW_DATA_PTR->Lateral.Curve.Curve         //TPGetEgoCurveRaw() TPGetCurveStandard()
#define EGO_CURVE_GRAD_RAW                        GET_EGO_RAW_DATA_PTR->Lateral.Curve.Gradient      //TPGetEgoCurveGradRaw()TPGetGradientStandard()
#define EGO_CURVE_VAR_RAW                         GET_EGO_RAW_DATA_PTR->Lateral.Curve.varC0         //TPGetCurveStandardVariance TPGetEgoCurveVarRaw
#define EGO_CURVE_QUALITY_RAW                     GET_EGO_RAW_DATA_PTR->Lateral.Curve.Quality       //TPSetCurveStandardQuality

#define EGO_DRV_INT_CURVE_RAW                     GET_EGO_RAW_DATA_PTR->Lateral.DrvIntCurve.Curve          //
#define EGO_DRV_INT_CURVE_GRAD_RAW                GET_EGO_RAW_DATA_PTR->Lateral.DrvIntCurve.Gradient       //
#define EGO_DRV_INT_CURVE_VAR_RAW                 GET_EGO_RAW_DATA_PTR->Lateral.DrvIntCurve.Variance       //

#define EGO_SIDE_SLIP_RAW                         GET_EGO_RAW_DATA_PTR->Lateral.SlipAngle.SideSlipAngle    //
#define EGO_SIDE_SLIP_VAR_RAW                     GET_EGO_RAW_DATA_PTR->Lateral.SlipAngle.Variance         //


#define EGO_MOTION_STATE_RAW                      GET_EGO_RAW_DATA_PTR->MotionState.MotState

/*****************************************************************************

  Ego Dynamic Data Object Sync (VDYN-Obj)

  In order to access any information from the ego dynamic data your component
  has to define the access macro(s):
    GET_EGO_OBJ_SYNC_DATA_PTR - It shall return the pointer to the ego
                                dynamic data buffer
                                type: VehDyn_t *

*****************************************************************************/

//#define GET_EGO_OBJ_SYNC_DATA_PTR                 GET_EGO_DYN_DATA_PTR->sync_obj

#define EGO_SPEED_X_OBJ_SYNC                      GET_EGO_OBJ_SYNC_DATA_PTR->Longitudinal.MotVar.Velocity         //TPGetEgoSpeedXObjSync()
#define EGO_SPEED_X_VAR_OBJ_SYNC                  GET_EGO_OBJ_SYNC_DATA_PTR->Longitudinal.MotVar.varVelocity      //TPGetEgoSpeedXVarObjSync()

#define EGO_ACCEL_X_OBJ_SYNC                      GET_EGO_OBJ_SYNC_DATA_PTR->Longitudinal.MotVar.Accel            //TPGetEgoAccelXTgtSync();
#define EGO_ACCEL_X_VAR_OBJ_SYNC                  GET_EGO_OBJ_SYNC_DATA_PTR->Longitudinal.MotVar.varAccel         //TPGetEgoAccelXVarObjSync();

#define EGO_MERGED_EGO_ACCEL_X_VAR_OBJ_SYNC       GET_EGO_OBJ_SYNC_DATA_PTR->Longitudinal.AccelCorr.corrAccelVar  //
#define EGO_MERGED_EGO_ACCEL_X_STD_OBJ_SYNC       SQRT_(EGO_MERGED_EGO_ACCEL_X_VAR_OBJ_SYNC)                      //TPGetMergedEgoAccelStdDevObjSync
#define EGO_MERGED_EGO_ACCEL_X_OBJ_SYNC           GET_EGO_OBJ_SYNC_DATA_PTR->Longitudinal.AccelCorr.corrAccel     //TPGetMergedEgoAccelObjSync()

#define EGO_YAW_RATE_OBJ_SYNC                     GET_EGO_OBJ_SYNC_DATA_PTR->Lateral.YawRate.YawRate              //TPGetEgoYawRateSync() TPGetEgoYawRateObjSync
#define EGO_YAW_RATE_VAR_OBJ_SYNC                 GET_EGO_OBJ_SYNC_DATA_PTR->Lateral.YawRate.Variance             //
#define EGO_YAW_RATE_MAX_JITTER_OBJ_SYNC          GET_EGO_OBJ_SYNC_DATA_PTR->Legacy.YawRateMaxJitter              //

#define EGO_CURVE_OBJ_SYNC                        GET_EGO_OBJ_SYNC_DATA_PTR->Lateral.Curve.Curve                  //TPGetEgoCurveObjSync()
#define EGO_CURVE_GRAD_OBJ_SYNC                   GET_EGO_OBJ_SYNC_DATA_PTR->Lateral.Curve.Gradient               //TPGetEgoCurveGradObjSync()
#define EGO_CURVE_VAR_OBJ_SYNC                    GET_EGO_OBJ_SYNC_DATA_PTR->Lateral.Curve.varC0                  //TPGetEgoCurveVarObjSync()

#define EGO_DRV_INT_CURVE_OBJ_SYNC                GET_EGO_OBJ_SYNC_DATA_PTR->Lateral.DrvIntCurve.Curve            //
#define EGO_DRV_INT_CURVE_GRAD_OBJ_SYNC           GET_EGO_OBJ_SYNC_DATA_PTR->Lateral.DrvIntCurve.Gradient         //
#define EGO_DRV_INT_CURVE_VAR_OBJ_SYNC            GET_EGO_OBJ_SYNC_DATA_PTR->Lateral.DrvIntCurve.Variance         //

#define EGO_SIDE_SLIP_OBJ_SYNC                    GET_EGO_OBJ_SYNC_DATA_PTR->Lateral.SlipAngle.SideSlipAngle      //TPGetEgoSlipAngleObjSync()
#define EGO_SIDE_SLIP_VAR_OBJ_SYNC                GET_EGO_OBJ_SYNC_DATA_PTR->Lateral.SlipAngle.Variance           //TPGetEgoSlipAngleVarObjSync()


/*****************************************************************************

  Ego Dynamic Data Target Sync (VDYN-Tgt)

  In order to access any information from the ego dynamic data your component
  has to define the access macro(s):
    GET_EGO_TGT_SYNC_DATA_PTR - It shall return the pointer to the ego
                                dynamic data buffer
                                type: VehDyn_t *

*****************************************************************************/

//#define GET_EGO_TGT_SYNC_DATA_PTR                 GET_EGO_DYN_DATA_PTR->sync_tgt

#define EGO_SPEED_X_TGT_SYNC                      GET_EGO_TGT_SYNC_DATA_PTR->Longitudinal.MotVar.Velocity        //TPGetEgoSpeedXTgtSync()
#define EGO_SPEED_X_VAR_TGT_SYNC                  GET_EGO_TGT_SYNC_DATA_PTR->Longitudinal.MotVar.varVelocity     //TPGetEgoSpeedXVarTgtSync()

#define EGO_ACCEL_X_TGT_SYNC                      GET_EGO_TGT_SYNC_DATA_PTR->Longitudinal.MotVar.Accel           //TPGetEgoAccelXTgtSync();
#define EGO_ACCEL_X_VAR_TGT_SYNC                  GET_EGO_TGT_SYNC_DATA_PTR->Longitudinal.MotVar.varAccel        //

#define EGO_YAW_RATE_TGT_SYNC                     GET_EGO_TGT_SYNC_DATA_PTR->Lateral.YawRate.YawRate             //TPGetEgoYawRateLastTgtSync
#define EGO_YAW_RATE_VAR_TGT_SYNC                 GET_EGO_TGT_SYNC_DATA_PTR->Lateral.YawRate.Variance            //TPGetEgoYawRateLastTgtVarSync
#define EGO_YAW_RATE_MAX_JITTER_TGT_SYNC          GET_EGO_TGT_SYNC_DATA_PTR->Legacy.YawRateMaxJitter             //TPGetEgoYawRateMaxJitterTgtSync

#define EGO_CURVE_TGT_SYNC                        GET_EGO_TGT_SYNC_DATA_PTR->Lateral.Curve.Curve                 //TPGetEgoCurveTgtSync()
#define EGO_CURVE_GRAD_TGT_SYNC                   GET_EGO_TGT_SYNC_DATA_PTR->Lateral.Curve.Gradient              //TPGetEgoCurveGradTgtSync()
#define EGO_CURVE_VAR_TGT_SYNC                    GET_EGO_TGT_SYNC_DATA_PTR->Lateral.Curve.varC0                 //TPGetEgoCurveVarTgtSync()

#define EGO_DRV_INT_CURVE_TGT_SYNC                GET_EGO_TGT_SYNC_DATA_PTR->Lateral.DrvIntCurve.Curve           //TPGetEgoDrvIntCurveObjSync()
#define EGO_DRV_INT_CURVE_GRAD_TGT_SYNC           GET_EGO_TGT_SYNC_DATA_PTR->Lateral.DrvIntCurve.Gradient        //
#define EGO_DRV_INT_CURVE_VAR_TGT_SYNC            GET_EGO_TGT_SYNC_DATA_PTR->Lateral.DrvIntCurve.Variance        //

#define EGO_SIDE_SLIP_TGT_SYNC                    GET_EGO_TGT_SYNC_DATA_PTR->Lateral.SlipAngle.SideSlipAngle     //TPGetEgoSlipAngleTgtSync()
#define EGO_SIDE_SLIP_VAR_TGT_SYNC                GET_EGO_TGT_SYNC_DATA_PTR->Lateral.SlipAngle.Variance          //TPGetEgoSlipAngleVarTgtSync()

//#define EGO_CAN_VEH_SPEED_DIFF                    0.0F //TPVehSpdGetCANVehicleSpeedDiff (&TPVehicleSpeedDiff );


/*****************************************************************************

  Ego Static Data (VPAR)

  In order to access any information from the ego static data your component
  has to define the access macro(s):
    GET_EGO_STATIC_DATA_PTR - It shall return the pointer to the ego
                              dynamic data buffer
                              type: GDBEgoStatic_t *

  @todo: Potentially split up into parts, as some are filled by EM, some
  directly by VDY!

*****************************************************************************/

#define EGO_VEHICLE_WIDTH                         GET_EGO_STATIC_DATA_PTR->VehParAdd.VehicleWidth                //TPGetEgoWidth()
#define EGO_VEHICLE_TRACK_WIDTH_FRONT             GET_EGO_STATIC_DATA_PTR->VehParMain.TrackWidthFront             //
#define EGO_VEHICLE_WHEEL_BASE                    GET_EGO_STATIC_DATA_PTR->VehParMain.WheelBase               //
#define EGO_VEHICLE_AXLE_LOAD_DISTR               GET_EGO_STATIC_DATA_PTR->VehParMain.AxisLoadDistr        //


/*****************************************************************************

  Road data

  In order to access any information from the road data your component
  has to define the access macro(s):
    GET_ROAD_DATA_PTR       - It shall return the pointer to the ego
                              dynamic data buffer
                              type: GDBRoadGlob_t *

*****************************************************************************/

/*! roadtype*/
#define ROAD_GET_TYPE1( iTypeLevel1, fTypeLevel1Conf)  \
  *iTypeLevel1     = GET_ROAD_DATA_PTR->Legacy.RoadTypeClass.eRoadTypeLevel1; \
  *fTypeLevel1Conf = GET_ROAD_DATA_PTR->Legacy.RoadTypeClass.fRoadConfLevel1;

#define ROAD_SET_TYPE1( iTypeLevel1, fTypeLevel1Conf) \
  GET_ROAD_DATA_PTR->Legacy.RoadTypeClass.eRoadTypeLevel1 = iTypeLevel1; \
  GET_ROAD_DATA_PTR->Legacy.RoadTypeClass.fRoadConfLevel1 = fTypeLevel1Conf;

#define ROAD_TYPE1      GET_ROAD_DATA_PTR->Legacy.RoadTypeClass.eRoadTypeLevel1
#define ROAD_TYPE1_CONF GET_ROAD_DATA_PTR->Legacy.RoadTypeClass.fRoadConfLevel1
#define ROAD_TYPE2      GET_ROAD_DATA_PTR->Legacy.RoadTypeClass.eRoadTypeLevel2
#define ROAD_TYPE2_CONF GET_ROAD_DATA_PTR->Legacy.RoadTypeClass.fRoadConfLevel2

#define ROAD_GET_TYPE2( iTypeLevel2, fTypeLevel2Conf)  \
  *iTypeLevel2     = GET_ROAD_DATA_PTR->Legacy.RoadTypeClass.eRoadTypeLevel2; \
  *fTypeLevel2Conf = GET_ROAD_DATA_PTR->Legacy.RoadTypeClass.fRoadConfLevel2; 

#define ROAD_SET_TYPE2( iTypeLevel2, fTypeLevel2Conf) \
  GET_ROAD_DATA_PTR->Legacy.RoadTypeClass.eRoadTypeLevel2 = iTypeLevel2; \
  GET_ROAD_DATA_PTR->Legacy.RoadTypeClass.fRoadConfLevel2 = fTypeLevel2Conf;

#define ROAD_GET_TYPE( iTypeLevel1, fTypeLevel1Conf, iTypeLevel2, fTypeLevel2Conf)  \
  *iTypeLevel1     = GET_ROAD_DATA_PTR->Legacy.RoadTypeClass.eRoadTypeLevel1; \
  *fTypeLevel1Conf = GET_ROAD_DATA_PTR->Legacy.RoadTypeClass.fRoadConfLevel1; \
  *iTypeLevel2     = GET_ROAD_DATA_PTR->Legacy.RoadTypeClass.eRoadTypeLevel2; \
  *fTypeLevel2Conf = GET_ROAD_DATA_PTR->Legacy.RoadTypeClass.fRoadConfLevel2; 

/*! road */
#define ROAD_GET_RANGE_LEFT                       GET_ROAD_DATA_PTR->Legacy.RoadIntData.fmaxXLeftCompensated  // EORoadGetRangeLeft ();
#define ROAD_GET_RANGE_RIGHT                      GET_ROAD_DATA_PTR->Legacy.RoadIntData.fmaxXRightCompensated // EORoadGetRangeRight();
#define ROAD_SET_RANGE_LEFT_RIGHT(left,right)  \
  GET_ROAD_DATA_PTR->Legacy.RoadIntData.fmaxXLeftCompensated  = left; \
  GET_ROAD_DATA_PTR->Legacy.RoadIntData.fmaxXRightCompensated = right;


#define ROAD_GET_CONFIDENCE_LEFT                  GET_ROAD_DATA_PTR->Legacy.RoadIntData.fConfidenceLeft       //EORoadGetConfidenceLeft ();
#define ROAD_GET_CONFIDENCE_RIGHT                 GET_ROAD_DATA_PTR->Legacy.RoadIntData.fConfidenceRight      //EORoadGetConfidenceRight();
#define ROAD_SET_CONFIDENCE_LEFT_RIGHT(left,right)  \
  GET_ROAD_DATA_PTR->Legacy.RoadIntData.fConfidenceLeft  = left; \
  GET_ROAD_DATA_PTR->Legacy.RoadIntData.fConfidenceRight = right;

/* todo  create distance dependent variance */
#define ROAD_GET_EST_VARIANCE(long_displacement)        SQR(GET_ROAD_DATA_PTR->Legacy.RoadIntData.fLatStdDevFiltered)    //EORoadGetEstVariance(RE_Samples.S[i].f0);
#define ROAD_SET_EST_STDEV                              GET_ROAD_DATA_PTR->Legacy.RoadIntData.fLatStdDevFiltered         //
#define ROAD_GET_EST_STDEV                              GET_ROAD_DATA_PTR->Legacy.RoadIntData.fLatStdDevFiltered         //

#define ROAD_GET_MIN_MAX_TGT_DIST(fMinRight, fMaxRight, fMinLeft, fMaxLeft) \
  *fMinRight = GET_ROAD_DATA_PTR->Legacy.RoadIntData.fminXRight; \
  *fMaxRight = GET_ROAD_DATA_PTR->Legacy.RoadIntData.fmaxXRightCompensated; \
  *fMinLeft  = GET_ROAD_DATA_PTR->Legacy.RoadIntData.fminXLeft;  \
  *fMaxLeft  = GET_ROAD_DATA_PTR->Legacy.RoadIntData.fmaxXLeftCompensated; // EORoadGetMinMaxTgtDist(&fMinRight, &fMaxRight, &fMinLeft, &fMaxLeft);
#define ROAD_GET_MIN_X_LEFT                             GET_ROAD_DATA_PTR->Legacy.RoadIntData.fminXLeft
#define ROAD_GET_MIN_X_RIGHT                            GET_ROAD_DATA_PTR->Legacy.RoadIntData.fminXRight
#define ROAD_GET_MAX_X_LEFT_COMPENSTATED                GET_ROAD_DATA_PTR->Legacy.RoadIntData.fmaxXLeftCompensated
#define ROAD_GET_MAX_X_RIGHT_COMPENSTATED               GET_ROAD_DATA_PTR->Legacy.RoadIntData.fmaxXRightCompensated

#define ROAD_SET_MIN_LEFT_RIGHT(fMinLeft,fMinRight)  \
  GET_ROAD_DATA_PTR->Legacy.RoadIntData.fminXLeft  = fMinLeft;  \
  GET_ROAD_DATA_PTR->Legacy.RoadIntData.fminXRight = fMinRight;

#define ROAD_ESTMATION_TYPE                       RoadEstimation_t
#define GET_ROAD_ESTIMATION                       &GET_ROAD_DATA_PTR->RoadEstimation           //EORoadGetEstimation()
#define SET_ROAD_ESTIMATION                       GET_ROAD_DATA_PTR->RoadEstimation            //EORoadGetEstimation()

/*! lane matix */
#define ROAD_GET_LANE_NO_LEFT                     GET_ROAD_DATA_PTR->LaneMatrix.iNumOfLaneLeft
#define ROAD_GET_LANE_NO_RIGHT                    GET_ROAD_DATA_PTR->LaneMatrix.iNumOfLaneRight

#define ROAD_GET_NO_LANE_MATRIX_PROB_LEFT         GET_ROAD_DATA_PTR->LaneMatrix.Legacy.NoLaneProbLeft // EOGetNoLaneMatrixProbLeft
#define ROAD_GET_NO_LANE_MATRIX_PROB_RIGHT        GET_ROAD_DATA_PTR->LaneMatrix.Legacy.NoLaneProbRight// EOGetNoLaneMatrixProbRight

//#define EO_EGO_LANE_CHANGE_LEFT                   GET_ROAD_DATA_PTR->LaneChange.Left.iCorrection  // EOGetLaneChangeLeft
//#define EO_EGO_LANE_CHANGE_RIGHT                  GET_ROAD_DATA_PTR->LaneChange.Right.iCorrection // EOGetLaneChangeRight

#define ROAD_GET_LANE_CLASS                       GET_ROAD_DATA_PTR->LaneWidth.eLaneWidthClass  // EOGetLaneClass()

/*! road border */
#define ROAD_GET_BORDER                           GET_ROAD_DATA_PTR->FusedRoadBorder
#define ROAD_GET_BORDER_LEFT                      ROAD_GET_BORDER.fDistLeft   //(EOBorderGetEstimation())
#define ROAD_GET_BORDER_RIGHT                     ROAD_GET_BORDER.fDistRight  //(EOBorderGetEstimation())

#define ROAD_GET_BORDER_STAT_LEFT                 ROAD_GET_BORDER.bStatusLeft
#define ROAD_GET_BORDER_STAT_RIGHT                ROAD_GET_BORDER.bStatusRight

/* currently only filled with default values */
#define ROAD_GET_BORDER_STDDEV_LEFT               ROAD_GET_BORDER.fDistLeftStd
#define ROAD_GET_BORDER_STDDEV_RIGHT              ROAD_GET_BORDER.fDistRightStd

/* Traffic Orientation */
#define TRAFFIC_ORIENTATION_NEXT_WRITE_ALLOWED    GET_ROAD_DATA_PTR->Traffic.Legacy.fTimeToNextWriteAllowed //TPGetInitTrafficOrientation() TPUpdateTrafficOrientation
#define TRAFFIC_ORIENTATION                       GET_ROAD_DATA_PTR->Traffic.eTrafficOrientation     //TPGetInitTrafficOrientation() TPUpdateTrafficOrientation
#define TRAFFIC_ORIENTATION_NVM_STATE             GET_ROAD_DATA_PTR->Traffic.Legacy.bWriteToNVM             //TPGetInitTrafficOrientation() TPUpdateTrafficOrientation



/*****************************************************************************

  Object traces

  In order to access any information from the object traces your component
  has to define the access macro(s):
    GET_MOV_OBJ_TRACE_DATA_PTR  - It shall return the pointer to the moving
                                  object traces buffer to use
                                  type: GDBObjectTraces_t *

*****************************************************************************/

#define OBJECT_TRACES_TYPE                            ObjectTraces_t
#define GET_TRACE(iTrace)                             GET_OBJ_TRACE_LIST_DATA_PTR->ObjectTraces[iTrace]                                              
#define TRACE_GET_HEAD_VECTOR(iTrace)                 GET_TRACE(iTrace).ObjectTraceBasic.Head
#define TRACE_GET_TAIL_VECTOR(iTrace)                 GET_TRACE(iTrace).ObjectTraceBasic.Tail
#define TRACE_GET_STATE(iTrace)                       GET_TRACE(iTrace).ObjectTraceAttributes.eTraceUpdateState
#define TRACE_GET_TYPE(iTrace)                        GET_TRACE(iTrace).ObjectTraceAttributes.eTraceType

#define MOVING_OBJ_TRACES_TYPE                        ObjectTrace_t
#define GET_MOVING_OBJ_TRACE_PTR(iTrace)              (&GET_MOV_OBJ_TRACE_DATA_PTR->ObjectTrace[iTrace])
#define TRACE_GET_X(iTrace)                           GET_MOVING_OBJ_TRACE_PTR(iTrace)->fTracePointX
#define TRACE_GET_Y(iTrace)                           GET_MOVING_OBJ_TRACE_PTR(iTrace)->fTracePointY
#define TRACE_GET_Y_INTERSEC_GRAD_FILT(iTrace)        GET_MOVING_OBJ_TRACE_PTR(iTrace)->fYIntersectionGradFilt
#define TRACE_GET_YAXIS_PRED_INTERSECTION(iTrace)     GET_MOVING_OBJ_TRACE_PTR(iTrace)->Legacy.YPredictedIntersec
#define TRACE_GET_YAXIS_PRED_INTERSECTION_VAR(iTrace) GET_MOVING_OBJ_TRACE_PTR(iTrace)->Legacy.YPredictedIntersecVar


/* switch the ref to object interface */
#if ((defined(NEW_TRACES)) && (NEW_TRACES == 1))

/* new traces macros */
#define TRACE_GET_ID(iTrace)                    GET_TRACE(iTrace).ObjectTraceBasic.uiReferenceToObject
#define TRACE_GET_NO_OF_POINTS(iTrace)          GET_TRACE(iTrace).ObjectTraceBasic.uiNumberOfPoints
#define TRACE_GET_Y_INTERSEC(iTrace)            GET_TRACE(iTrace).ObjectTraceAttributes.fYIntersection
#define TRACE_GET_PRIO(iTrace)                  GET_TRACE(iTrace).ObjectTraceAttributes.uiPriority
#define TRACE_GET_QUALITY(iTrace)               GET_TRACE(iTrace).ObjectTraceAttributes.Quality
#define TRACE_GET_Y_STD_DEV(iTrace)             GET_TRACE(iTrace).ObjectTraceAttributes.uiTracePointYStdDev
#define TRACE_IS_OUALITY_FLAG_SET(iTrace,flag)  ((TRACE_GET_QUALITY(iTrace) & flag) == (flag))
#define TRACE_SET_OUALITY_FLAG(iTrace,flag)     (TRACE_GET_QUALITY(iTrace) = (TRACE_GET_QUALITY(iTrace) |  (flag)) )
#define TRACE_CLEAR_OUALITY_FLAG(iTrace,flag)   (TRACE_GET_QUALITY(iTrace) = (TRACE_GET_QUALITY(iTrace) & ~(flag)) )
#define TRACE_RESET_OUALITY_FLAGS(iTrace)       (TRACE_GET_QUALITY(iTrace) = 0UL)

#else

/* old traces macros */

#define GET_OBJ_TRACE_LIST_PTR(iTR)               (&GET_OBJ_TRACE_LIST_DATA_PTR->ObjectTraces[iTr])

#define TRACE_GET_ID(iTr)                         GET_MOVING_OBJ_TRACE_PTR(iTr)->uiReferenceToObject
#define TRACE_GET_Y_STD_DEV(iTr)                  GET_MOVING_OBJ_TRACE_PTR(iTr)->fTracePointYStdDev
#define TRACE_GET_Y_INTERSEC(iTr)                 GET_MOVING_OBJ_TRACE_PTR(iTr)->fYIntersection
#define TRACE_GET_NO_OF_POINTS(iTr)               GET_MOVING_OBJ_TRACE_PTR(iTr)->iNumberOfPoints
#define TRACE_REACHED_EGO_VEH(iTr)                GET_MOVING_OBJ_TRACE_PTR(iTr)->Legacy.TraceReachEgoVeh
#define TRACE_VALID_LANEMATRIX(iTr)               GET_MOVING_OBJ_TRACE_PTR(iTr)->Legacy.ValidForLaneMatrix

#endif

/*****************************************************************************

  Sensor Position data

  In order to access any information from the sensor data your component
  has to define the access macro(s):
    GET_SENSOR_EXT_DATA_PTR     - It shall return the pointer to the moving
                                  object traces buffer to use
                                  type: GDBSensorProperties_t *

*****************************************************************************/

/* sensor parameters */
#define SENSOR_MOUNTING                           GET_EGO_STATIC_DATA_PTR->SensorMounting
#define SENSOR_X_POSITION                         SENSOR_MOUNTING.LongPos //Sensor Position in CoFrA	Center of front wheel axle
#define SENSOR_Y_POSITION                         SENSOR_MOUNTING.LatPos  //TPGetSensorYPosition()
#define SENSOR_Z_POSITION                         SENSOR_MOUNTING.VertPos //

#define SENSOR_X_POSITION_CoG                     SENSOR_MOUNTING.LongPosToCoG  // (GET_EGO_STATIC_DATA_PTR->SensorMounting.LongPos + (GET_EGO_STATIC_DATA_PTR->VehParMain.WheelBase * GET_EGO_STATIC_DATA_PTR->VehParMain.AxisLoadDistr)) //Sensor Position in CoG	Basic (static) center of gravity

/*! Oeffnungswinkel einer Keule:  ARS2xx: (f32_t)(3.4F), ARS300: KEULENWINKEL = 8.0f */
#define LOBE_ANGLE                                GET_EGO_STATIC_DATA_PTR->Sensor.fLobeAngle       // (8.0f)

/*! Gesamter Erfassungsbereich der Antenne ueber 3 Keulen (ARS2xx: (KEULENWINKEL*3.0F)) ARS300: ERFASSUNGSWINKEL = 20.0f */
#define COVERAGE_ANGLE                            GET_EGO_STATIC_DATA_PTR->Sensor.fCoverageAngle   // (20.F)

/*! Wahrscheinlichster Winkel bei Messwerten ueber laengerer Zeit aus nur einer Keule, ARS300: ((KEULENWINKEL + (ERFASSUNGSWINKEL*0.5)*0.5) */
#define MAX_ANGLE                                 ((LOBE_ANGLE+(COVERAGE_ANGLE*0.5F))*0.5F)

/*! Number of scans (near/far) Mirrored from rsp.he */
#define NOF_SCANS                                 GET_EGO_STATIC_DATA_PTR->Sensor.uNoOfScans       //(2)

/*****************************************************************************

  Global sytem wide data

  In order to access any information from the global system data your
  component has to define the access macro(s):
    GET_EM_FCT_CYCLE_MODE_PTR   - It shall return the pointer to the moving
                                  object traces buffer to use
                                  type: GDBGlob_t *

  @todo: Currently only requirement is that the pointer returned shall
  be de-referencable with a field 'eCycleMode'! An explicit type is needed!

*****************************************************************************/

/* The global cycle mode */
#define GDB_CYCLE_MODE                            GET_EM_FCT_CYCLE_MODE_PTR->eCycleMode        //TPGetCycleMode();

/* The radar task cycle time */
#define TASK_CYCLE_TIME                          GET_EM_FCT_CYCLE_MODE_PTR->fEmFctCycleTime

/*****************************************************************************

  VDY io state macros

  In order to access any vdy signal/parameter io state,
  use this bit masks and the set/get macros

*****************************************************************************/

/*! @description: VDYIoState_t  
  @resolution: tbd   @unit: tbd   @min: 0     @max: tbd  */
typedef ui32_t VDYIoState_t;


/*! External interface states */
#define VDY_IO_STATE_NO_BIT            2UL
#define VDY_IO_STATE_VALID             ((VDYIoState_t) 0U)
#define VDY_IO_STATE_INVALID           ((VDYIoState_t) 1U)
#define VDY_IO_STATE_NOTAVAIL          ((VDYIoState_t) 2U)

/*! init vdy io states */
#define VDY_IO_STATE_INIT                      ((VDYIoState_t) 0xFFFFFFFFUL)
#define VDY_IO_STATE_BITMASK                   ((VDYIoState_t) (0x3U))

/*! Bit positions of input signal states */
#define VDY_SIN_POS_YWR             (0UL)                          /*!< Yaw rate signal                                        */
#define VDY_SIN_POS_YWR_TEMP        (1UL * VDY_IO_STATE_NO_BIT)    /*!< Temperature (yaw rate sensor) signal                   */
#define VDY_SIN_POS_SWA             (2UL * VDY_IO_STATE_NO_BIT)    /*!< Steering wheel angle signal                            */
#define VDY_SIN_POS_LATA            (3UL * VDY_IO_STATE_NO_BIT)    /*!< Lateral acceleration signal                            */
#define VDY_SIN_POS_WVEL_FL         (4UL * VDY_IO_STATE_NO_BIT)    /*!< Wheel velocity signal front left                       */
#define VDY_SIN_POS_WVEL_FR         (5UL * VDY_IO_STATE_NO_BIT)    /*!< Wheel velocity signal front right                      */
#define VDY_SIN_POS_WVEL_RL         (6UL * VDY_IO_STATE_NO_BIT)    /*!< Wheel velocity signal rear left                        */
#define VDY_SIN_POS_WVEL_RR         (7UL * VDY_IO_STATE_NO_BIT)    /*!< Wheel velocity signal rear right                       */
#define VDY_SIN_POS_YWRINT          (8UL * VDY_IO_STATE_NO_BIT)    /*!< Internal yaw rate signal                               */
#define VDY_SIN_POS_YWRINT_TEMP     (9UL * VDY_IO_STATE_NO_BIT)    /*!< Temperature (internal yaw rate sensor) signal          */
#define VDY_SIN_POS_LONGA          (10UL * VDY_IO_STATE_NO_BIT)    /*!< Longitudinal acceleration sensor signal                */
#define VDY_SIN_POS_RSTA           (11UL * VDY_IO_STATE_NO_BIT)    /*!< Longitudinal acceleration sensor signal                */
#define VDY_SIN_POS_VEHVEL_EXT     (12UL * VDY_IO_STATE_NO_BIT)    /*!< External provided vehicle velocity                     */
#define VDY_SIN_POS_VEHACL_EXT     (13UL * VDY_IO_STATE_NO_BIT)    /*!< External provided vehicle acceleraton                  */
#define VDY_SIN_POS_WDIR_FL        (14UL * VDY_IO_STATE_NO_BIT)    /*!< Wheel rolling direction front left                     */
#define VDY_SIN_POS_WDIR_FR        (15UL * VDY_IO_STATE_NO_BIT)    /*!< Wheel rolling direction front right                    */
#define VDY_SIN_POS_WDIR_RL        (16UL * VDY_IO_STATE_NO_BIT)    /*!< Wheel rolling direction rear left                      */
#define VDY_SIN_POS_WDIR_RR        (17UL * VDY_IO_STATE_NO_BIT)    /*!< Wheel rolling direction rear right                     */
#define VDY_SIN_POS_WTCKS_FL       (18UL * VDY_IO_STATE_NO_BIT)    /*!< Wheel ticks deviation front left to last cycle         */
#define VDY_SIN_POS_WTCKS_FR       (19UL * VDY_IO_STATE_NO_BIT)    /*!< Wheel ticks deviation front right to last cycle        */
#define VDY_SIN_POS_WTCKS_RL       (20UL * VDY_IO_STATE_NO_BIT)    /*!< Wheel ticks deviation rear left to last cycle          */
#define VDY_SIN_POS_WTCKS_RR       (21UL * VDY_IO_STATE_NO_BIT)    /*!< Wheel ticks deviation rear right to last cycle         */
#define VDY_SIN_POS_GEAR           (22UL * VDY_IO_STATE_NO_BIT)    /*!< Actual gear position                                   */
#define VDY_SIN_POS_BRAKE          (23UL * VDY_IO_STATE_NO_BIT)    /*!< Brake activity level (torque or pressure)              */
#define VDY_SIN_POS_PBRK           (24UL * VDY_IO_STATE_NO_BIT)    /*!< Status of park brake (false->released, true -> locked) */
#define VDY_SIN_POS_VDIR           (25UL * VDY_IO_STATE_NO_BIT)    /*!< External longitudinal direction state                  */
#define VDY_SIN_POS_VMOT           (26UL * VDY_IO_STATE_NO_BIT)    /*!< External longitudinal motion state                     */
#define VDY_SIN_POS_CRV            (28UL * VDY_IO_STATE_NO_BIT)    /*!< External estimated curve                               */
#define VDY_SIN_POS_SSA            (29UL * VDY_IO_STATE_NO_BIT)    /*!< External estimated body side slip angle                */
#define VDY_SIN_SIZE_DW            (2UL)                           /*!< Number of dwords necessary to store flags              */

/*! Bit postitions of input parameter states */
#define VDY_PAR_POS_SSG             (0UL)                          /*!< Understeer/oversteer gradient                          */
#define VDY_PAR_POS_SWARAT          (1UL * VDY_IO_STATE_NO_BIT)    /*!< Overall steering ratio                                 */
#define VDY_PAR_POS_WBASE           (2UL * VDY_IO_STATE_NO_BIT)    /*!< Distance between front and rear axle                   */
#define VDY_PAR_POS_TWDFR           (3UL * VDY_IO_STATE_NO_BIT)    /*!< Track width front axle                                 */
#define VDY_PAR_POS_TWDRE           (4UL * VDY_IO_STATE_NO_BIT)    /*!< Track width rear axle                                  */
#define VDY_PAR_POS_VEHWGT          (5UL * VDY_IO_STATE_NO_BIT)    /*!< Vehicle weight                                         */
#define VDY_PAR_POS_COGH            (6UL * VDY_IO_STATE_NO_BIT)    /*!< Center of gravity height                               */
#define VDY_PAR_POS_AXLD            (7UL * VDY_IO_STATE_NO_BIT)    /*!< Ratio between rear axle load and total load            */
#define VDY_PAR_POS_WHLDFR          (8UL * VDY_IO_STATE_NO_BIT)    /*!< Wheel load dependency front axle                       */
#define VDY_PAR_POS_WHLDRE          (9UL * VDY_IO_STATE_NO_BIT)    /*!< Wheel load dependency rear axle                        */
#define VDY_PAR_POS_WHLCIR         (10UL * VDY_IO_STATE_NO_BIT)    /*!< Effective dynamic rolling circumference                */
#define VDY_PAR_POS_DRVAXL         (11UL * VDY_IO_STATE_NO_BIT)    /*!< Powered axle                                           */
#define VDY_PAR_POS_WTCKSREV       (12UL * VDY_IO_STATE_NO_BIT)    /*!< Impulse counter ticks per wheel revolution             */
#define VDY_PAR_POS_CSFR           (13UL * VDY_IO_STATE_NO_BIT)    /*!< Front axke cornering stiffness                         */
#define VDY_PAR_POS_CSRE           (14UL * VDY_IO_STATE_NO_BIT)    /*!< Front axke cornering stiffness                         */
#define VDY_PAR_POS_TOTAL          (15UL * VDY_IO_STATE_NO_BIT)    /*!< Total state of parameter set                           */
#define VDY_PAR_SIZE_DW            (2UL)                           /*!< Number of dwords necessary to store flags              */

/*! Bit position of output signal states */
#define VDY_SOUT_POS_CURVE         (0UL)                           /*!< Curvature of vehicle tracetory                         */
#define VDY_SOUT_POS_YWR           (1UL * VDY_IO_STATE_NO_BIT)     /*!< Estimated vehicle yaw velocity                         */
#define VDY_SOUT_POS_DRCRV         (2UL * VDY_IO_STATE_NO_BIT)     /*!< Driver intended curvature                              */
#define VDY_SOUT_POS_VEL           (3UL * VDY_IO_STATE_NO_BIT)     /*!< Vehicle long. velocity                                 */
#define VDY_SOUT_POS_ACCEL         (4UL * VDY_IO_STATE_NO_BIT)     /*!< Vehicle long. acceleration                             */
#define VDY_SOUT_POS_MSTAT         (5UL * VDY_IO_STATE_NO_BIT)     /*!< Vehicle long. motion state                             */
#define VDY_SOUT_POS_VCORR         (6UL * VDY_IO_STATE_NO_BIT)     /*!< Velocity Correction                                    */
#define VDY_SOUT_POS_SSA           (7UL * VDY_IO_STATE_NO_BIT)     /*!< Side slip angle                                        */
#define VDY_SOUT_POS_LATACC        (8UL * VDY_IO_STATE_NO_BIT)     /*!< Lateral acceleration                                   */
#define VDY_SOUT_SIZE_DW           (1UL)                           /*!< Number of dwords necessary to store flags              */

/*! Bit position of nvm signal states */
#define VDY_NVM_POS_SWA            (0UL)                           /*!< Steering wheel angle zero point offset */
#define VDY_NVM_POS_SSG            (1UL * VDY_IO_STATE_NO_BIT)     /*!< Selfsteer gradient */
#define VDY_NVM_POS_YWR            (2UL * VDY_IO_STATE_NO_BIT)     /*!< Yaw rate zero point offset */
#define VDY_NVM_POS_LATACC         (3UL * VDY_IO_STATE_NO_BIT)     /*!< Lateral acceleration zero point offset */
#define VDY_NVM_POS_VELCORR        (4UL * VDY_IO_STATE_NO_BIT)     /*!< Longitudinal velocity correction */
#define VDY_NVM_POS_WLD            (5UL * VDY_IO_STATE_NO_BIT)     /*!< Wheel load dependency */
#define VDY_NVM_SIZE_DW           (1UL)                            /*!< Number of dwords necessary to store flags */


/*! Set get macros for the vdy states */
#ifdef __PDO__
#define VDY_SET_IO_STATE(pos_, state_, val_)
#define VDY_GET_IO_STATE(pos_,val_)             0
#else
#define VDY_SET_IO_STATE(pos_, state_, val_)   ( (val_)[(pos_)/32UL] = (~((VDYIoState_t) (VDY_IO_STATE_BITMASK<<((pos_)%32UL))) & ((val_)[(pos_)/32UL])) | ((VDY_IO_STATE_BITMASK & (state_))<<((pos_)%32UL)))
#define VDY_GET_IO_STATE(pos_,val_)            ( ((val_)[(pos_)/32UL] >> ((pos_) % 32UL)) & VDY_IO_STATE_BITMASK)
#endif


/*****************************************************************************

  Public Data Virtual addresses

*****************************************************************************/

/*! Virtual addresses or related records IDs (in case of framework lookup table) for 
    data acquisition interface. The addresses or IDs values must correspond to addresses 
    specified in data description file (SDL, A2L etc.) */
#define MEAS_ID_EGO_STATIC_PUBLIC_GLOB_DATA   0x2000FC80uL          /* GLOB DATA */
#define MEAS_ID_SENSOR_PUBLIC_GLOB_DATA       0x2000FC90uL          /* GLOB DATA */

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/

/*! temporary for task logic monitoring */
typedef ui32_t MONCheckpointVal_t;    /* task monitoring checkpoints */

typedef enum
{ /* identifier of the particular task or component (0...31) */
  MON_CHECK_IPC,
  MON_CHECK_ACTL,
  MON_CHECK_DIAG,
  MON_CHECK_MON,
  MON_CHECK_RADR,
  MON_CHECK_RHC,
  MON_CHECK_RSP,
  /* and so on...           last CheckId <= 31 */
  MON_CHECK_MAX
} MONCheckId_t;

/* Task Logic Monitoring: checkpoint value x */
#define MON_CHECKPOINT_VAL(x)         ((MONCheckpointVal_t) x)



#endif
