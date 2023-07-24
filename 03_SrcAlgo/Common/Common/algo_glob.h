/*! \file **********************************************************************

  COMPANY:                Continental Temic, PC DAS, A.D.C. GmbH

  PROJECT:                All

  CPU:                    All

  COMPONENT:              RTE

  MODULNAME:              algo_glob.h

  DESCRIPTION:            


  CREATION DATE:          11.09.2007

  VERSION:                $Revision: 1.62 $

  ---*/ /*---
  CHANGES:                $Log: algo_glob.h  $
  CHANGES:                Revision 1.62 2016/08/22 10:13:57CEST Ibrouchene, Nassim (uidt5589) (uidt5589) 
  CHANGES:                Fixed typo in road confidence access macro
  CHANGES:                Revision 1.61 2016/05/30 16:42:39CEST Ibrouchene, Nassim (uidt5589) 
  CHANGES:                Fixed typo in macro definition
  CHANGES:                Revision 1.60 2016/05/25 15:27:52CEST Ibrouchene, Nassim (uidt5589) 
  CHANGES:                Update for new road output signals
  CHANGES:                Revision 1.59 2016/05/02 15:45:28CEST Ibrouchene, Nassim (uidt5589) 
  CHANGES:                Merge branch.
  CHANGES:                Revision 1.58.1.2 2016/05/02 14:16:28CEST Ibrouchene, Nassim (uidt5589) 
  CHANGES:                New signal name. Changes in the comments.
  CHANGES:                Revision 1.58.1.1 2016/05/02 10:53:13CEST Ibrouchene, Nassim (uidt5589) 
  CHANGES:                Update of RD access macros as a preparation of an RTE update.
  CHANGES:                Revision 1.58 2016/03/23 11:15:45CET Eisenacher, Michael (eisenacherm) 
  CHANGES:                changed EGO_SPEED_X_RAW to corrected ego speed
  CHANGES:                added comments for EGO_SPEED_X_OBJ_SYNC and EGO_SPEED_X_TGT_SYNC
  CHANGES:                Revision 1.57 2015/08/21 11:00:00CEST Oprisan, Dan (oprisand) 
  CHANGES:                - remove GET_ALIGNMENT_SIGNAL -> error prone because it assumes u_ScanMode is defined. Replaced with EM_f_GetAlignmentAzAng() in EM
  CHANGES:                - Added comments -  oprisand [Aug 21, 2015 11:00:00 AM CEST]
  CHANGES:                Change Package : 369826:1 http://mks-psad:7002/im/viewissue?selection=369826
  CHANGES:                Revision 1.56 2015/07/29 17:45:15CEST Dora, Bala Ganesh (uidj4934) 
  CHANGES:                - merge branch
  CHANGES:                --- Added comments ---  uidj4934 [Jul 29, 2015 5:45:15 PM CEST]
  CHANGES:                Change Package : 354751:1 http://mks-psad:7002/im/viewissue?selection=354751
  CHANGES:                Revision 1.55.1.1 2015/07/28 16:43:52CEST Dora, Bala Ganesh (uidj4934) 
  CHANGES:                - Backward compatible to macro's,  which are been used by fct
  CHANGES:                --- Added comments ---  uidj4934 [Jul 28, 2015 4:43:52 PM CEST]
  CHANGES:                Change Package : 354751:1 http://mks-psad:7002/im/viewissue?selection=354751
  CHANGES:                Revision 1.55 2015/07/21 11:58:21CEST Dora, Bala Ganesh (uidj4934) 
  CHANGES:                - merge branch
  CHANGES:                --- Added comments ---  uidj4934 [Jul 21, 2015 11:58:22 AM CEST]
  CHANGES:                Change Package : 354751:1 http://mks-psad:7002/im/viewissue?selection=354751
  CHANGES:                Revision 1.54.3.1 2015/07/08 13:10:29CEST Dora-EXT, Bala Ganesh (uidj4934) 
  CHANGES:                - Replacement of Road related macros with inline functions
  CHANGES:                --- Added comments ---  uidj4934 [Jul 8, 2015 1:10:29 PM CEST]
  CHANGES:                Change Package : 354751:1 http://mks-psad:7002/im/viewissue?selection=354751
  CHANGES:                Revision 1.54 2015/02/16 14:02:17CET Dohri, Karim (TFCES9) 
  CHANGES:                backward compatibilty with old RTE based on EM_PERF_DEGR_INTFVER
  CHANGES:                --- Added comments ---  TFCES9 [Feb 16, 2015 2:02:17 PM CET]
  CHANGES:                Change Package : 306322:1 http://mks-psad:7002/im/viewissue?selection=306322
  CHANGES:                Revision 1.53 2015/01/22 13:52:40CET Dohri, Karim (TFCES9) 
  CHANGES:                Use near Scan for Blockage Detection (Done by Marian Olaru)
  CHANGES:                --- Added comments ---  TFCES9 [Jan 22, 2015 1:52:41 PM CET]
  CHANGES:                Change Package : 296118:5 http://mks-psad:7002/im/viewissue?selection=296118
  CHANGES:                Revision 1.52 2014/12/08 11:52:15CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                - suppressed QA-C warnings on macro _PARAM_UNUSED as suspected behaviour is intended
  CHANGES:                --- Added comments ---  uidg6516 [Dec 8, 2014 11:52:15 AM CET]
  CHANGES:                Change Package : 287770:2 http://mks-psad:7002/im/viewissue?selection=287770
  CHANGES:                Revision 1.51 2014/10/21 08:30:19CEST Hackel, Bjoern (uidj2938) 
  CHANGES:                added new signal: EGO_CURVE_ERROR_RAW
  CHANGES:                --- Added comments ---  uidj2938 [Oct 21, 2014 8:30:20 AM CEST]
  CHANGES:                Change Package : 222749:1 http://mks-psad:7002/im/viewissue?selection=222749
  CHANGES:                Revision 1.50 2014/09/19 16:19:58CEST Diewald, Fabian (uidt8878) 
  CHANGES:                added target distance for which the elevation peak ratio is minimized, for EM StatObst Ground Obj and ALN MON
  CHANGES:                --- Added comments ---  uidt8878 [Sep 19, 2014 4:19:59 PM CEST]
  CHANGES:                Change Package : 229461:19 http://mks-psad:7002/im/viewissue?selection=229461
  CHANGES:                Revision 1.49 2014/08/29 12:43:02CEST Pfrang-EXT, Christoph (uidw8162) 
  CHANGES:                removed obsolete EM_GEN_OBJECT_INTFVER >= 8 query
  CHANGES:                --- Added comments ---  uidw8162 [Aug 29, 2014 12:43:02 PM CEST]
  CHANGES:                Change Package : 259464:1 http://mks-psad:7002/im/viewissue?selection=259464
  CHANGES:                Revision 1.48 2014/06/17 19:05:48CEST Tandler, Joachim (uidk7536) 
  CHANGES:                Removed obsolete macro NUMBER_OF_OBJECTS_. Use EM_N_OBJECTS instead!
  CHANGES:                --- Added comments ---  uidk7536 [Jun 17, 2014 7:05:48 PM CEST]
  CHANGES:                Change Package : 242918:1 http://mks-psad:7002/im/viewissue?selection=242918
  CHANGES:                Revision 1.47 2014/05/19 17:27:11CEST Pfrang-EXT, Christoph (uidw8162) 
  CHANGES:                redefined GEN_OBJECT_LIST macros according to new interface version >= 8
  CHANGES:                --- Added comments ---  uidw8162 [May 19, 2014 5:27:11 PM CEST]
  CHANGES:                Change Package : 237759:1 http://mks-psad:7002/im/viewissue?selection=237759
  CHANGES:                Revision 1.46 2014/03/11 10:55:51CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                Changes on cycle time macro undone
  CHANGES:                --- Added comments ---  uidg6516 [Mar 11, 2014 10:55:51 AM CET]
  CHANGES:                Change Package : 224133:2 http://mks-psad:7002/im/viewissue?selection=224133
  CHANGES:                Revision 1.45 2014/03/10 13:39:45CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                - replaced reading access to EMData.pEmFctCycleMode->fEmFctCycleTime via macro TASK_CYCLE_TIME or direct with get-fct.
  CHANGES:                - replaced writing access via macro TASK_CYCLE_TIME with direct access
  CHANGES:                --- Added comments ---  uidg6516 [Mar 10, 2014 1:39:45 PM CET]
  CHANGES:                Change Package : 224133:1 http://mks-psad:7002/im/viewissue?selection=224133
  CHANGES:                Revision 1.44 2014/02/07 12:51:28CET Wolter, Frank (wolterf) 
  CHANGES:                Added VDY state macros for NVM access
  CHANGES:                --- Added comments ---  wolterf [Feb 7, 2014 12:51:29 PM CET]
  CHANGES:                Change Package : 217717:1 http://mks-psad:7002/im/viewissue?selection=217717
  CHANGES:                Revision 1.43 2014/02/06 16:43:35CET Heidemann-EXT, Siegfried (uidg3348) 
  CHANGES:                add macro _PARAM_UNUSED for warning reduction
  CHANGES:                --- Added comments ---  uidg3348 [Feb 6, 2014 4:43:35 PM CET]
  CHANGES:                Change Package : 217551:1 http://mks-psad:7002/im/viewissue?selection=217551
  CHANGES:                Revision 1.42 2014/02/05 11:27:39CET Oprisan, Dan (oprisand) 
  CHANGES:                - bugfix comment
  CHANGES:                --- Added comments ---  oprisand [Feb 5, 2014 11:27:39 AM CET]
  CHANGES:                Change Package : 216059:2 http://mks-psad:7002/im/viewissue?selection=216059
  CHANGES:                Revision 1.41 2014/01/28 15:12:57CET Wolter, Frank (wolterf) 
  CHANGES:                Adapted VDY IO state macros to new interface (old interface still supported)
  CHANGES:                --- Added comments ---  wolterf [Jan 28, 2014 3:12:59 PM CET]
  CHANGES:                Change Package : 208447:1 http://mks-psad:7002/im/viewissue?selection=208447
  CHANGES:                Revision 1.40 2013/12/18 09:56:09CET Hanel, Nele (haneln) 
  CHANGES:                adapt code to new GenObjList-Qualifier structure
  CHANGES:                --- Added comments ---  haneln [Dec 18, 2013 9:56:09 AM CET]
  CHANGES:                Change Package : 207943:1 http://mks-psad:7002/im/viewissue?selection=207943
  CHANGES:                Revision 1.39 2013/11/21 14:38:02CET Boll, Marie-Theres (uidu1091) 
  CHANGES:                Adapt source code to new merge/split interface
  CHANGES:                --- Added comments ---  uidu1091 [Nov 21, 2013 2:38:02 PM CET]
  CHANGES:                Change Package : 206241:1 http://mks-psad:7002/im/viewissue?selection=206241
  CHANGES:                Revision 1.38 2013/10/31 16:59:19CET Eisenacher, Michael (eisenacherm) 
  CHANGES:                shifted inline define to algo_constants.h
  CHANGES:                --- Added comments ---  eisenacherm [Oct 31, 2013 4:59:20 PM CET]
  CHANGES:                Change Package : 180551:1 http://mks-psad:7002/im/viewissue?selection=180551
  CHANGES:                Revision 1.37 2013/10/18 13:10:57CEST Schluttig, Jakob (uidv7098) 
  CHANGES:                remove redundant defines of resolution of azimuth angle deviation tables (now computed by generic defines)
  CHANGES:                --- Added comments ---  uidv7098 [Oct 18, 2013 1:10:57 PM CEST]
  CHANGES:                Change Package : 183851:1 http://mks-psad:7002/im/viewissue?selection=183851
  CHANGES:                Revision 1.36 2013/10/17 11:09:20CEST Ungvary, Gergely (ungvaryg) 
  CHANGES:                Remove FUN_PRESEL_ACC_MIN_OBJ_QUAL/FUN_PRESEL_ACC_MIN_INLANE_OBJ_QUAL as declarations obviously
  CHANGES:                duplicated in algo_constants.h
  CHANGES:                --- Added comments ---  ungvaryg [Oct 17, 2013 11:09:20 AM CEST]
  CHANGES:                Change Package : 198450:1 http://mks-psad:7002/im/viewissue?selection=198450
  CHANGES:                Revision 1.35 2013/10/16 18:10:26CEST Foelster, Florian (foelsterf) 
  CHANGES:                distinguish between object IDs due to object priorisation
  CHANGES:                --- Added comments ---  foelsterf [Oct 16, 2013 6:10:26 PM CEST]
  CHANGES:                Change Package : 198608:1 http://mks-psad:7002/im/viewissue?selection=198608
  CHANGES:                Revision 1.34 2013/10/14 13:26:44CEST Boll, Marie-Theres (uidu1091) 
  CHANGES:                Move macros from algo_glob.h to EM/FCT if the macro is only used in the component
  CHANGES:                --- Added comments ---  uidu1091 [Oct 14, 2013 1:26:45 PM CEST]
  CHANGES:                Change Package : 179586:1 http://mks-psad:7002/im/viewissue?selection=179586
  CHANGES:                Revision 1.33 2013/10/10 17:19:52CEST Kaelberer, Stephan (uidu2442) 
  CHANGES:                removed all FCT_SIMU switches, macros are also used in ECU code
  CHANGES:                --- Added comments ---  uidu2442 [Oct 10, 2013 5:19:53 PM CEST]
  CHANGES:                Change Package : 200509:3 http://mks-psad:7002/im/viewissue?selection=200509
  CHANGES:                Revision 1.32 2013/10/10 10:18:45CEST Hanel, Nele (haneln) 
  CHANGES:                temporary workaround to enable compiling in target compiler again: uncomment FCT_SIMU compiler switch
  CHANGES:                --- Added comments ---  haneln [Oct 10, 2013 10:18:45 AM CEST]
  CHANGES:                Change Package : 197797:2 http://mks-psad:7002/im/viewissue?selection=197797
  CHANGES:                Revision 1.31 2013/10/02 18:14:48CEST Oprisan, Dan (oprisand) 
  CHANGES:                - temporary fix: replace uiReferenceToFCTObject with uiReferenceToObject until new common CP is available
  CHANGES:                --- Added comments ---  oprisand [Oct 2, 2013 6:14:49 PM CEST]
  CHANGES:                Change Package : 178940:5 http://mks-psad:7002/im/viewissue?selection=178940
  CHANGES:                Revision 1.30 2013/10/01 15:23:22CEST Boll, Marie-Theres (uidu1091) 
  CHANGES:                Merge initial version of object priorisation to trunk
  CHANGES:                --- Added comments ---  uidu1091 [Oct 1, 2013 3:23:22 PM CEST]
  CHANGES:                Change Package : 179586:1 http://mks-psad:7002/im/viewissue?selection=179586
  CHANGES:                Revision 1.29.1.3 2013/10/01 15:21:48CEST Boll, Marie-Theres (uidu1091) 
  CHANGES:                Merge initial version of object priorisation to trunk
  CHANGES:                --- Added comments ---  uidu1091 [Oct 1, 2013 3:21:48 PM CEST]
  CHANGES:                Change Package : 179586:1 http://mks-psad:7002/im/viewissue?selection=179586
  CHANGES:                Revision 1.29.1.2 2013/09/23 11:59:47CEST Boll, Marie-Theres (uidu1091) 
  CHANGES:                Add Object ID conversation from EM to FCT for ObjectTraceBasic-Type
  CHANGES:                --- Added comments ---  uidu1091 [Sep 23, 2013 11:59:47 AM CEST]
  CHANGES:                Change Package : 179586:1 http://mks-psad:7002/im/viewissue?selection=179586
  CHANGES:                Revision 1.29.1.1 2013/09/17 14:56:24CEST Boll, Marie-Theres (uidu1091) 
  CHANGES:                First code changes for object priorisation in EM/FPS and increasing the number of objects in EM
  CHANGES:                --- Added comments ---  uidu1091 [Sep 17, 2013 2:56:24 PM CEST]
  CHANGES:                Change Package : 179586:1 http://mks-psad:7002/im/viewissue?selection=179586
  CHANGES:                Revision 1.29 2013/08/23 10:52:06CEST Fuentes, Juan-Carlos (uidu2446) 
  CHANGES:                - removed the macro to get the RangeGateLength, the variables from the RTE should be used now.
  CHANGES:                --- Added comments ---  uidu2446 [Aug 23, 2013 10:52:06 AM CEST]
  CHANGES:                Change Package : 178131:39 http://mks-psad:7002/im/viewissue?selection=178131
  CHANGES:                Revision 1.28 2013/08/14 17:04:18CEST Schluttig, Jakob (uidv7098) 
  CHANGES:                fixed ALN_f_AngleDeviationFar_AngleMin according to new PPar definition
  CHANGES:                --- Added comments ---  uidv7098 [Aug 14, 2013 5:04:19 PM CEST]
  CHANGES:                Change Package : 183793:2 http://mks-psad:7002/im/viewissue?selection=183793
  CHANGES:                Revision 1.27 2013/07/19 13:41:01CEST Ungvary, Gergely (ungvaryg) 
  CHANGES:                Add glob_comp_id.h include so that algo components have access to MEAS component defines
  CHANGES:                --- Added comments ---  ungvaryg [Jul 19, 2013 1:41:01 PM CEST]
  CHANGES:                Change Package : 190129:4 http://mks-psad:7002/im/viewissue?selection=190129
  CHANGES:                Revision 1.26 2013/07/17 14:45:41CEST Eisenacher, Michael (eisenacherm) 
  CHANGES:                added VDY_IO_STATE_BITMASK which was accidently removed
  CHANGES:                --- Added comments ---  eisenacherm [Jul 17, 2013 2:45:41 PM CEST]
  CHANGES:                Change Package : 180551:1 http://mks-psad:7002/im/viewissue?selection=180551
  CHANGES:                Revision 1.25 2013/07/17 13:09:45CEST Gharib-EXT, Ahmad (uidv7292) 
  CHANGES:                delete redundant define which is already defined in RTE file
  CHANGES:                --- Added comments ---  uidv7292 [Jul 17, 2013 1:09:46 PM CEST]
  CHANGES:                Change Package : 183858:2 http://mks-psad:7002/im/viewissue?selection=183858
  CHANGES:                Revision 1.24 2013/07/16 13:49:38CEST Gharib-EXT, Ahmad (uidv7292) 
  CHANGES:                Disable MeshFreez
  CHANGES:                --- Added comments ---  uidv7292 [Jul 16, 2013 1:49:39 PM CEST]
  CHANGES:                Change Package : 183858:2 http://mks-psad:7002/im/viewissue?selection=183858
  CHANGES:                Revision 1.23 2013/05/14 11:47:37CEST Oprisan, Dan (oprisand) 
  CHANGES:                - Adapt ALGO_INLINE macro for Greenhill compiler
  CHANGES:                --- Added comments ---  oprisand [May 14, 2013 11:47:37 AM CEST]
  CHANGES:                Change Package : 178131:9 http://mks-psad:7002/im/viewissue?selection=178131
  CHANGES:                Revision 1.22 2013/04/29 11:34:32CEST Fuentes, Juan-Carlos (uidu2446) 
  CHANGES:                - added inline macros for EM.
  CHANGES:                - todo: add the proper macro for the racerunner.
  CHANGES:                --- Added comments ---  uidu2446 [Apr 29, 2013 11:34:33 AM CEST]
  CHANGES:                Change Package : 174150:2 http://mks-psad:7002/im/viewissue?selection=174150
  CHANGES:                Revision 1.21 2013/04/26 10:48:31CEST Ungvary, Gergely (ungvaryg) 
  CHANGES:                Add maintenance states split deleted to OBJ_IS_DELETED() macro, and split new to OBJ_IS_NEW() macro
  CHANGES:                Modify class confidence macro to OBJ_CLASS_CONFIDENCE_PERCENT, since new interface includes integer confidence
  CHANGES:                while old interface used float value. (Provides compile-time error for wrong use)
  CHANGES:                --- Added comments ---  ungvaryg [Apr 26, 2013 10:48:32 AM CEST]
  CHANGES:                Change Package : 179559:3 http://mks-psad:7002/im/viewissue?selection=179559
  CHANGES:                Revision 1.20 2013/04/23 10:53:55CEST Hanel, Nele (haneln) 
  CHANGES:                adapt macros to new EM generic and technology specific object lists
  CHANGES:                remove some unused macros
  CHANGES:                --- Added comments ---  haneln [Apr 23, 2013 10:53:55 AM CEST]
  CHANGES:                Change Package : 179439:4 http://mks-psad:7002/im/viewissue?selection=179439
  CHANGES:                Revision 1.19 2013/03/26 15:08:06CET Meschenmoser, Daniel (uidu0849) 
  CHANGES:                - move the __ASSERT macro to em.h and rename it to __EM_ASSERT
  CHANGES:                --- Added comments ---  uidu0849 [Mar 26, 2013 3:08:06 PM CET]
  CHANGES:                Change Package : 170691:52 http://mks-psad:7002/im/viewissue?selection=170691
  CHANGES:                Revision 1.18 2012/11/19 16:56:40CET Fuentes, Juan-Carlos (uidu2446) 
  CHANGES:                - implemented the alignment compensation using a #define.
  CHANGES:                - all possible uses have been taken into account.
  CHANGES:                --- Added comments ---  uidu2446 [Nov 19, 2012 4:56:44 PM CET]
  CHANGES:                Change Package : 165708:2 http://mks-psad:7002/im/viewissue?selection=165708
  CHANGES:                Revision 1.17 2012/09/24 17:57:14CEST Oprisan, Dan (oprisand) 
  CHANGES:                - remove unused defines and macros
  CHANGES:                --- Added comments ---  oprisand [Sep 24, 2012 5:57:17 PM CEST]
  CHANGES:                Change Package : 139701:10 http://mks-psad:7002/im/viewissue?selection=139701
  CHANGES:                Revision 1.16 2012/09/24 17:54:24CEST Oprisan, Dan (oprisand) 
  CHANGES:                - switch back to new cml structure

  *****************************************************************************/


/*****************************************************************************
  MACROS 
*****************************************************************************/

#ifndef ALGO_GLOB_H_INCLUDED
#define ALGO_GLOB_H_INCLUDED

#include "algo_type.h"
#include "algo_cfg.h"
#include "meas_ext.h"
#include "cml_ext.h"
#include "glob_comp_id.h"


/* Check if we are in QA-C: PRQA_SIZE_T is defined in QA-C environment. */
#ifdef PRQA_SIZE_T
  /* Deactivate QAC warnings 3112, Reviewer: S. Schwarzkopf; Date: 08.12.2014; 
     Reason: _PARAM_UNUSED is intended to have no side effects. */
  #pragma PRQA_MACRO_MESSAGES_OFF "_PARAM_UNUSED" 3112
#endif /* #ifdef PRQA_SIZE_T */


/* defines for the angle deviations in the interface ALN_AzimuthCorrection_t (from ALN to RSP2) */

/* minimum angle for far scan (i.e. angle of first point in array) [radians] */
#define ALN_f_AngleDeviationFar_AngleMin (CML_Deg2Rad(-22.f))

/* minimum angle for near scan (i.e. angle of first point in array) [radians] */
#define ALN_f_AngleDeviationNear_AngleMin (CML_Deg2Rad(-90.f))

/* angle increment for far scan [radians]


   NB: in both Ppar and ALN_AzimuthCorrection, the sampling points are at the *edges* of the bins 
       -> number of bins = (number of sampling points - 1)
   bin width [radians] = total angle range (2 * maxangle) / (number of sampling points - 1) */
#define ALN_f_AngleDeviationFar_AngleInc  ( - (2.f * ALN_f_AngleDeviationFar_AngleMin ) / (float32)(ALN_ANGLE_DEV_FAR_NOF_ANGLES-1) )

/* angle increment for near scan [radians] */
#define ALN_f_AngleDeviationNear_AngleInc ( - (2.f * ALN_f_AngleDeviationNear_AngleMin) / (float32)(ALN_ANGLE_DEV_NEAR_NOF_ANGLES-1) )

/* constants share between EM <-> FCT */
//TODO: rename according to coding conventions 
/* standard road width */
#define STRASSENBREITE       (3.75F)
/* half of standard road width */
#define HALBESTRASSENBREITE  (STRASSENBREITE/2.0F)
/* standard vehicle width */
#define FAHRZEUGBREITE       (2.2F)
/* half of standard vehicle width */
#define HALBEFAHRZEUGBREITE  (FAHRZEUGBREITE/2.F)

/*****************************************************************************
  MACROS 
*****************************************************************************/

/*! Internally used macro, never use outside of this file. */
#define ALGO_StringInternalQuote(x)			#x

/*! Macro to convert a token/define to string. Useful for names etc. Note how
the internally used macro is needed by this function. Otherwise define
replacement wouldn't take place */
#define ALGO_StringQuote(x) 						ALGO_StringInternalQuote(x)

/*! Conversion macro to convert cycles to lifetime */
#define ALGO_f_ConvCyclesToLifetime(c)	(c)
/*! Conversion macro to convert time to lifetime */
#define ALGO_f_ConvTimeToLifeTime(t)		((t) * (1.f/ALGO_f_RadarCycleTime))
/*! Conversion macro to convert lifetime to time */
#define ALGO_f_ConvLifetimeToTime(lt)   ((lt) * ALGO_f_RadarCycleTime)
/*! Conversion macro to convert lifetime to cycles */
#define ALGO_f_ConvLifetimeToCycles(lt) (lt)

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
#define GET_EM_GEN_OBJ(iObj)                      GET_EM_PUB_OBJ_DATA_PTR->aObject[iObj]

/* Object kinematic */
#define OBJ_KINEMATIC(iObj)                       GET_EM_GEN_OBJ(iObj).Kinematic
/* Object general */
#define OBJ_GENERAL(iObj)                         GET_EM_GEN_OBJ(iObj).General
/* Object Attributes */
#define OBJ_ATTRIBUTES(iObj)                      GET_EM_GEN_OBJ(iObj).Attributes
/* Object Qualifiers */
#define OBJ_QUALIFIERS(iObj)                      GET_EM_GEN_OBJ(iObj).Qualifiers
/* Object Geometry */
#define OBJ_GEOMETRY(iObj)                        GET_EM_GEN_OBJ(iObj).Geometry


#define GET_EM_ARS_OBJ_PUB(iObj)                  GET_EM_ARS_OBJ_LIST_PTR->aObject[iObj]

#define OBJ_ARS_KINEMATICS(iObj)                  GET_EM_ARS_OBJ_PUB(iObj).Kinematic
#define OBJ_ARS_GEOMETRY(iObj)                    GET_EM_ARS_OBJ_PUB(iObj).Geometry
#define OBJ_ARS_MOTIONATTRIBUTES(iObj)            GET_EM_ARS_OBJ_PUB(iObj).MotionAttributes
#define OBJ_ARS_ATTRIBUTES(iObj)                  GET_EM_ARS_OBJ_PUB(iObj).Attributes
#define OBJ_ARS_SENSORSPECIFIC(iObj)              GET_EM_ARS_OBJ_PUB(iObj).SensorSpecific
#define OBJ_ARS_LEGACY(iObj)                      GET_EM_ARS_OBJ_PUB(iObj).Legacy


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
#define OBJ_LONG_DISPLACEMENT_VAR(iObj)           SQR(OBJ_KINEMATIC(iObj).fDistXStd)
#define OBJ_LONG_DISPLACEMENT_STD(iObj)           OBJ_KINEMATIC(iObj).fDistXStd
#define OBJ_LONG_VREL_VAR(iObj)                   SQR(OBJ_KINEMATIC(iObj).fVrelXStd)
#define OBJ_LONG_VREL_STD(iObj)                   OBJ_KINEMATIC(iObj).fVrelXStd
#define OBJ_LONG_AREL_VAR(iObj)                   SQR(OBJ_KINEMATIC(iObj).fArelXStd)
#define OBJ_LONG_AREL_STD(iObj)                   OBJ_KINEMATIC(iObj).fArelXStd

#define OBJ_LAT_DISPLACEMENT_VAR(iObj)            SQR(OBJ_KINEMATIC(iObj).fDistYStd)
#define OBJ_LAT_DISPLACEMENT_STD(iObj)            OBJ_KINEMATIC(iObj).fDistYStd
#define OBJ_LAT_VREL_VAR(iObj)                    SQR(OBJ_KINEMATIC(iObj).fVrelYStd)
#define OBJ_LAT_VREL_STD(iObj)                    OBJ_KINEMATIC(iObj).fVrelYStd
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
#define OBJ_LIFETIME_SEC(iObj)                    OBJ_GENERAL(iObj).fLifeTime
#define OBJ_LIFECYCLES(iObj)                      OBJ_GENERAL(iObj).uiLifeCycles

/*
  Macros for object maintenance state (based on GET_EM_OBJ_PUB(iObj))
*/

#define OBJ_MAINTENANCE_STATE(iObj)               (OBJ_GENERAL(iObj).eMaintenanceState)
#define OBJ_IS_DELETED(iObj)                      (OBJ_GENERAL(iObj).eMaintenanceState == EM_GEN_OBJECT_MT_STATE_DELETED)
#define OBJ_IS_NEW(iObj)                          (OBJ_GENERAL(iObj).eMaintenanceState == EM_GEN_OBJECT_MT_STATE_NEW)


#define OBJ_KALMAN_MAX_ACCEL_Y(iObj)              OBJ_ARS_KINEMATICS(iObj).fMaxAccelY


/* target pos */
#define OBJ_TGT_LAST_DISTANCE(iObj)               OBJ_ARS_LEGACY(iObj).fLastTargetDistX
#define OBJ_TGT_LAST_HORZ_DISPLACEMENT(iObj)      OBJ_ARS_LEGACY(iObj).fLastTargetDistY

#define OBJ_ANGLE(iObj)                           OBJ_ARS_LEGACY(iObj).fAngle

/****************************** Object history *********************************/
#define OBJ_TRACE_ID(iObj)                        OBJ_ARS_ATTRIBUTES(iObj).uiReferenceToTrace

/* object attributes */
#define OBJ_DYNAMIC_PROPERTY(iObj)                OBJ_ARS_MOTIONATTRIBUTES(iObj).eDynamicProperty
#define OBJ_DYNAMIC_SUB_PROPERTY(iObj)            OBJ_ARS_MOTIONATTRIBUTES(iObj).eDynamicSubProperty
#define OBJ_CLASSIFICATION(iObj)                  OBJ_ARS_ATTRIBUTES(iObj).eClassification
#define OBJ_MOVING_TO_STATIONARY(iObj)            OBJ_ARS_MOTIONATTRIBUTES(iObj).uiStoppedConfidence
// The below define is equivalent, but used in code which only evaluates for bool-ness
#define OBJ_IS_MOVING_TO_STATIONARY(iObj)         (OBJ_ARS_MOTIONATTRIBUTES(iObj).uiStoppedConfidence > 80U)

/* object Geometry */
#define OBJ_ORIENTATION(iObj)                     OBJ_ARS_GEOMETRY(iObj).fOrientation
#define OBJ_ORIENTATION_STD(iObj)                 OBJ_ARS_GEOMETRY(iObj).fOrientationStd
#define OT_GET_OBJ_WIDTH(iObj)                    OBJ_ARS_GEOMETRY(iObj).fWidth
#define OT_GET_OBJ_LENGTH(iObj)                   OBJ_ARS_GEOMETRY(iObj).fLength
#define OBJ_CLASS_CONFIDENCE_PERCENT(iObj)        OBJ_ARS_ATTRIBUTES(iObj).uiClassConfidence

#define OBJ_RCS(iObj)                             OBJ_ARS_SENSORSPECIFIC(iObj).fRCS

#define OBJ_LONG_VEHICLE_TYPE(iObj)               OBJ_ARS_SENSORSPECIFIC(iObj).eObjRelationsClass
#define OBJ_IS_NORMAL(iObj)                       ((OBJ_LONG_VEHICLE_TYPE(iObj) == ARS_LONGVEHICLE_TYPE_NORMAL) ? TRUE : FALSE)
#define OBJ_IS_SHADOW(iObj)                       (((OBJ_LONG_VEHICLE_TYPE(iObj) == ARS_LONGVEHICLE_TYPE_SHADOW) || (OBJ_LONG_VEHICLE_TYPE(iObj) == ARS_LONGVEHICLE_TYPE_MIDDLE)) ? TRUE : FALSE)
#define OBJ_IS_MIDDLE(iObj)                       ((OBJ_LONG_VEHICLE_TYPE(iObj) == ARS_LONGVEHICLE_TYPE_MIDDLE) ? TRUE : FALSE)
#define OBJ_IS_REAL(iObj)                         ((OBJ_LONG_VEHICLE_TYPE(iObj) == ARS_LONGVEHICLE_TYPE_REAL) ? TRUE : FALSE)


#define OBJ_IS_MEASURED(iObj, ucMask)             ((OBJ_ARS_SENSORSPECIFIC(iObj).ucMeasuredSources & (ucMask)) ? TRUE : FALSE)

#define OBJ_GET_FOV_OVERLAP_FAR(iObj)             OBJ_ARS_SENSORSPECIFIC(iObj).eFOVOverlapFar

/****************************** Object qualifiers *********************************/
/* object Quality */
#define OBJ_PROBABILITY_OF_EXIST(iObj)            OBJ_QUALIFIERS(iObj).uiProbabilityOfExistence /* attention changed from float [0.0, 1.0] to uint [0, 100] */


/*
  Macros for accessing EM-based function pre-selection information (based on GET_EM_OBJ_PUB(iObj))
*/
#define OBJ_GET_ACC_FUN_PRESEL_QUALITY(iObj)      OBJ_QUALIFIERS(iObj).uiAccObjQuality
#define OBJ_GET_EBA_MOV_PRESEL_QUALITY(iObj)      OBJ_QUALIFIERS(iObj).uiEbaObjQuality    /* macro name kept for backwards compatibility */
#define OBJ_GET_EBA_HYPOTHESIS_CATEGORY(iObj)     OBJ_QUALIFIERS(iObj).eEbaHypCat
#define OBJ_GET_EBA_INHIBITION_MASK(iObj)         OBJ_QUALIFIERS(iObj).eEbaInhibitionMask


/*
  Macros for accessing per-object blockage data (based on GET_EM_OBJ_PUB(iObj))
*/
#define OBJ_PD_NEAR_OBJ_IN_BEAM(iObj)             OBJ_ARS_SENSORSPECIFIC(iObj).bNearObjInBeam


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
#define RSP_GET_RANGE_GATE_LENGTH                 EMData.p_RHCAdjHwConfigFar->RampPar.f_RangeGateLength   //TPSetRspRgLength()

/*****************************************************************************

  Radar signal processing output data

  In order to access any information from the assessed object list
  your component has to define the access macro(s):
    RSP_GET_RSP_INPUT_EM_PTR    - It shall return the pointer to the RSP data
                                  buffer
                                  type: RSPInputEM_t *

*****************************************************************************/

/* the required smapp tgt threshold */
#define RSP_INPUT_REQ_SMALL_TGT_THRESHOLD         0.0f //RSP_GET_RSP_INPUT_EM_PTR->ReqSmallTarThres           //TPWGetSmallTarThres


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
#if (EM_PERF_DEGR_INTFVER  >= 6u) 
  #if (ALGO_SensorType == ALGO_CFG_ARS400Entry)
    #define PD_GET_FUSED_RANGE_NEAR_VALUE                 GET_PERF_DEG_DATA_PTR->RangeFused[SYS_SCAN_NEAR].fFusedRange        //PDGetRange(RangeData) RangeData.Val[PD_RANGE_MEAN]
  #else
    #define PD_GET_FUSED_RANGE_NEAR_VALUE                 GET_PERF_DEG_DATA_PTR->RangeFused[SYS_SCAN_NEAR].fFusedRange        //PDGetRange(RangeData) RangeData.Val[PD_RANGE_MEAN]
    #define PD_GET_FUSED_RANGE_FAR_VALUE                  GET_PERF_DEG_DATA_PTR->RangeFused[SYS_SCAN_FAR].fFusedRange        //PDGetRange(RangeData) RangeData.Val[PD_RANGE_MEAN]
  #endif
#else
   #define PD_GET_FUSED_RANGE_VALUE                  GET_PERF_DEG_DATA_PTR->RangeFused.fFusedRange        //PDGetRange(RangeData) RangeData.Val[PD_RANGE_MEAN]
#endif

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

/* actual radar corrected speed from VDY */
#define EGO_SPEED_X_RAW                           GET_EGO_RAW_DATA_PTR->Longitudinal.VeloCorr.corrVelo
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
#define EGO_CURVE_ERROR_RAW                       GET_EGO_RAW_DATA_PTR->Lateral.Curve.CrvError      

#define EGO_DRV_INT_CURVE_RAW                     GET_EGO_RAW_DATA_PTR->Lateral.DrvIntCurve.Curve          //
#define EGO_DRV_INT_CURVE_GRAD_RAW                GET_EGO_RAW_DATA_PTR->Lateral.DrvIntCurve.Gradient       //
#define EGO_DRV_INT_CURVE_VAR_RAW                 GET_EGO_RAW_DATA_PTR->Lateral.DrvIntCurve.Variance       //

#define EGO_SIDE_SLIP_RAW                         GET_EGO_RAW_DATA_PTR->Lateral.SlipAngle.SideSlipAngle    //
#define EGO_SIDE_SLIP_VAR_RAW                     GET_EGO_RAW_DATA_PTR->Lateral.SlipAngle.Variance         //


#define EGO_MOTION_STATE_RAW                      GET_EGO_RAW_DATA_PTR->MotionState.MotState
#define EGO_MOTION_STATE_STATE                    VDY_GET_IO_STATE(VDY_SOUT_POS_MSTAT, GET_EGO_RAW_DATA_PTR->State)

/*****************************************************************************

  Ego Dynamic Data Object Sync (VDYN-Obj)

  In order to access any information from the ego dynamic data your component
  has to define the access macro(s):
    GET_EGO_OBJ_SYNC_DATA_PTR - It shall return the pointer to the ego
                                dynamic data buffer
                                type: VehDyn_t *

*****************************************************************************/

//#define GET_EGO_OBJ_SYNC_DATA_PTR                 GET_EGO_DYN_DATA_PTR->sync_obj

/* radar corrected speed from VDY synchronized to objects (EM takes corrected speed to fill MotVar.Velocity) */
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

/* radar corrected speed from VDY synchronized to clusters (EM takes corrected speed to fill MotVar.Velocity) */
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

#define ROAD_ESTMATION_TYPE                     RoadEstimation_t
#define GET_ROAD_ESTIMATION                     &GET_ROAD_DATA_PTR->RoadEstimation

/* TRAFFIC ORIENTATION */
#define ROAD_GET_TRAFFIC_ORIENTATION              GET_ROAD_DATA_PTR->Traffic.eTrafficOrientation

/* LANE WIDTH */
#define ROAD_GET_LANEWIDTH                        GET_ROAD_DATA_PTR->LaneWidth.fLaneWidth
#define ROAD_GET_LANEWIDTH_SOURCE                 GET_ROAD_DATA_PTR->LaneWidth.eLaneWidthSource
#define ROAD_GET_LANE_CLASS                       GET_ROAD_DATA_PTR->LaneWidth.eLaneWidthClass

#define ROAD_GET_LANE_MATRIX                      GET_ROAD_DATA_PTR->LaneMatrix

#define ROAD_GET_BORDER                           GET_ROAD_DATA_PTR->FusedRoadBorder
#define ROAD_GET_BORDER_RIGHT                     ROAD_GET_BORDER.fDistRight
#define ROAD_GET_BORDER_RIGHT_STD                 GET_ROAD_DATA_PTR->FusedRoadBorder.fDistRightStd
#define ROAD_GET_BORDER_LEFT                      ROAD_GET_BORDER.fDistLeft
#define ROAD_GET_BORDER_LEFT_STD                  GET_ROAD_DATA_PTR->FusedRoadBorder.fDistLeftStd
#define ROAD_GET_BORDER_STAT_RIGHT                ROAD_GET_BORDER.bStatusRight
#define ROAD_GET_BORDER_STAT_LEFT                 ROAD_GET_BORDER.bStatusLeft


#if (EM_ROAD_INTFVER == 1u)
/**************************** 
ROAD ESTIMATION access macros 
 **************************** */
/* New naming for the access macros */
#define ROAD_GET_CR_YAWANGLE                    GET_ROAD_DATA_PTR->RoadEstimation.fYawAngle
#define ROAD_GET_CR_CURVATURE                   GET_ROAD_DATA_PTR->RoadEstimation.fC0
#define ROAD_GET_CR_CLOTHOID_PARAM              GET_ROAD_DATA_PTR->RoadEstimation.fC1
#define ROAD_GET_CR_CONFIDENCE_LEFT             GET_ROAD_DATA_PTR->Legacy.RoadIntData.fConfidenceLeft
#define ROAD_GET_CR_MIN_X_LEFT                  GET_ROAD_DATA_PTR->Legacy.RoadIntData.fminXLeft
#define ROAD_GET_CR_MAX_X_LEFT                  GET_ROAD_DATA_PTR->RoadEstimation.fRangeMaxLeft
#define ROAD_GET_CR_MAX_X_LEFT_COMPENSTATED     GET_ROAD_DATA_PTR->Legacy.RoadIntData.fmaxXLeftCompensated
#define ROAD_GET_CR_TRACKSTAT_LEFT              GET_ROAD_DATA_PTR->RoadEstimation.Legacy.uiTrackingStatusLeft
#define ROAD_GET_CR_CONFIDENCE_RIGHT            GET_ROAD_DATA_PTR->Legacy.RoadIntData.fConfidenceRight
#define ROAD_GET_CR_MIN_X_RIGHT                 GET_ROAD_DATA_PTR->Legacy.RoadIntData.fminXRight
#define ROAD_GET_CR_MAX_X_RIGHT                 GET_ROAD_DATA_PTR->RoadEstimation.fRangeMaxRight
#define ROAD_GET_CR_MAX_X_RIGHT_COMPENSTATED    GET_ROAD_DATA_PTR->Legacy.RoadIntData.fmaxXRightCompensated
#define ROAD_GET_CR_TRACKSTAT_RIGHT             GET_ROAD_DATA_PTR->RoadEstimation.Legacy.uiTrackingStatusRight
#define ROAD_GET_CR_OFFSET_LEFT                 GET_ROAD_DATA_PTR->RoadEstimation.Legacy.fYLeft
#define ROAD_GET_CR_OFFSET_RIGHT                GET_ROAD_DATA_PTR->RoadEstimation.Legacy.fYRight
#define ROAD_GET_CR_CONFIDENCE                  GET_ROAD_DATA_PTR->RoadEstimation.Legacy.uiConfidence
#define ROAD_GET_CR_TRACKSTAT                   GET_ROAD_DATA_PTR->RoadEstimation.Legacy.uiTrackingStatus
#define ROAD_GET_CR_EST_STDEV                   GET_ROAD_DATA_PTR->Legacy.RoadIntData.fLatStdDevFiltered
/* The next 4 defines are deprecated please use the new defines */
#define ROAD_GET_RANGE_LEFT                     ROAD_GET_CR_MAX_X_LEFT_COMPENSTATED
#define ROAD_GET_RANGE_RIGHT                    ROAD_GET_CR_MAX_X_RIGHT_COMPENSTATED
#define ROAD_GET_CONFIDENCE_LEFT                ROAD_GET_CR_CONFIDENCE_LEFT
#define ROAD_GET_CONFIDENCE_RIGHT               ROAD_GET_CR_CONFIDENCE_RIGHT
#define ROAD_SET_CONFIDENCE_LEFT_RIGHT(left,right)  \
  GET_ROAD_DATA_PTR->Legacy.RoadIntData.fConfidenceLeft  = left; \
  GET_ROAD_DATA_PTR->Legacy.RoadIntData.fConfidenceRight = right;
#define ROAD_GET_MIN_MAX_TGT_DIST(fMinRight, fMaxRight, fMinLeft, fMaxLeft) \
  *fMinRight = GET_ROAD_DATA_PTR->Legacy.RoadIntData.fminXRight; \
  *fMaxRight = GET_ROAD_DATA_PTR->Legacy.RoadIntData.fmaxXRightCompensated; \
  *fMinLeft  = GET_ROAD_DATA_PTR->Legacy.RoadIntData.fminXLeft;  \
  *fMaxLeft  = GET_ROAD_DATA_PTR->Legacy.RoadIntData.fmaxXLeftCompensated;
/* The next 6 defines are deprecated please use the new defines */
#define ROAD_GET_MIN_X_LEFT                             ROAD_GET_CR_MIN_X_LEFT
#define ROAD_GET_MIN_X_RIGHT                            ROAD_GET_CR_MIN_X_RIGHT
#define ROAD_GET_MAX_X_LEFT_COMPENSTATED                ROAD_GET_CR_MAX_X_LEFT_COMPENSTATED
#define ROAD_GET_MAX_X_RIGHT_COMPENSTATED               ROAD_GET_CR_MAX_X_RIGHT_COMPENSTATED
#define ROAD_GET_EST_VARIANCE(long_displacement)        SQR(ROAD_GET_CR_EST_STDEV)
#define ROAD_GET_EST_STDEV                              ROAD_GET_CR_EST_STDEV

/* ROAD TYPE */
#define ROAD_GET_ROADTYPE               GET_ROAD_DATA_PTR->Legacy.RoadTypeClass.eRoadTypeLevel1
#define ROAD_GET_ROADWORKS              GET_ROAD_DATA_PTR->Legacy.RoadTypeClass.eRoadTypeLevel2
#define ROAD_GET_ROADTYPE_CONF          GET_ROAD_DATA_PTR->Legacy.RoadTypeClass.fRoadConfLevel1
#define ROAD_GET_ROADWORKS_CONF         GET_ROAD_DATA_PTR->Legacy.RoadTypeClass.fRoadConfLevel2
/* The next 2 defines are deprecated please use the new defines */
#define ROAD_TYPE1                      ROAD_GET_ROADTYPE
#define ROAD_TYPE2                      ROAD_GET_ROADWORKS

#define ROAD_GET_TYPE1( iTypeLevel1, fTypeLevel1Conf)  \
  *iTypeLevel1     = GET_ROAD_DATA_PTR->Legacy.RoadTypeClass.eRoadTypeLevel1; \
  *fTypeLevel1Conf = GET_ROAD_DATA_PTR->Legacy.RoadTypeClass.fRoadConfLevel1;

#define ROAD_GET_TYPE2( iTypeLevel2, fTypeLevel2Conf)  \
  *iTypeLevel2     = GET_ROAD_DATA_PTR->Legacy.RoadTypeClass.eRoadTypeLevel2; \
  *fTypeLevel2Conf = GET_ROAD_DATA_PTR->Legacy.RoadTypeClass.fRoadConfLevel2

#define ROAD_GET_TYPE( iTypeLevel1, iTypeLevel2)  \
  *iTypeLevel1     = GET_ROAD_DATA_PTR->Legacy.RoadTypeClass.eRoadTypeLevel1; \
  *iTypeLevel2     = GET_ROAD_DATA_PTR->Legacy.RoadTypeClass.eRoadTypeLevel2

/* This define is deprecated please use the new define */
#define TRAFFIC_ORIENTATION                       ROAD_GET_TRAFFIC_ORIENTATION

/* LANE MATRIX */
#define ROAD_GET_LANE_NO_LEFT                     GET_ROAD_DATA_PTR->LaneMatrix.iNumOfLaneLeft
#define ROAD_GET_LANE_NO_RIGHT                    GET_ROAD_DATA_PTR->LaneMatrix.iNumOfLaneRight
#define ROAD_GET_NO_LANE_MATRIX_PROB_LEFT         GET_ROAD_DATA_PTR->LaneMatrix.Legacy.NoLaneProbLeft
#define ROAD_GET_NO_LANE_MATRIX_PROB_RIGHT        GET_ROAD_DATA_PTR->LaneMatrix.Legacy.NoLaneProbRight

#else

#define ROAD_GET_CR_YAWANGLE                    GET_ROAD_DATA_PTR->RoadEstimation.CoupledRoad.ClothoidParams.f_YawAngle
#define ROAD_GET_CR_CURVATURE                   GET_ROAD_DATA_PTR->RoadEstimation.CoupledRoad.ClothoidParams.f_Curvature
#define ROAD_GET_CR_CLOTHOID_PARAM              GET_ROAD_DATA_PTR->RoadEstimation.CoupledRoad.ClothoidParams.f_ClothoidParam1
#define ROAD_GET_CR_TRANSITION_POINT            GET_ROAD_DATA_PTR->RoadEstimation.CoupledRoad.ClothoidParams.f_TransitionPoint
#define ROAD_GET_CR_CLOTHOID_PARAM_2            GET_ROAD_DATA_PTR->RoadEstimation.CoupledRoad.ClothoidParams.f_ClothoidParam2
#define ROAD_GET_CR_CONFIDENCE_LEFT             GET_ROAD_DATA_PTR->RoadEstimation.CoupledRoad.QualityMeasLeft.f_Confidence
#define ROAD_GET_CR_MIN_X_LEFT                  GET_ROAD_DATA_PTR->RoadEstimation.CoupledRoad.QualityMeasLeft.f_MinX
#define ROAD_GET_CR_MAX_X_LEFT                  GET_ROAD_DATA_PTR->RoadEstimation.CoupledRoad.QualityMeasLeft.f_MaxX
#define ROAD_GET_CR_MAX_X_LEFT_COMPENSTATED     GET_ROAD_DATA_PTR->RoadEstimation.CoupledRoad.QualityMeasLeft.f_MaxXCompensated
#define ROAD_GET_CR_TRACKSTAT_LEFT              GET_ROAD_DATA_PTR->RoadEstimation.CoupledRoad.QualityMeasLeft.u_TrackingStatus
#define ROAD_GET_CR_CONFIDENCE_RIGHT            GET_ROAD_DATA_PTR->RoadEstimation.CoupledRoad.QualityMeasRight.f_Confidence
#define ROAD_GET_CR_MIN_X_RIGHT                 GET_ROAD_DATA_PTR->RoadEstimation.CoupledRoad.QualityMeasRight.f_MinX
#define ROAD_GET_CR_MAX_X_RIGHT                 GET_ROAD_DATA_PTR->RoadEstimation.CoupledRoad.QualityMeasRight.f_MaxX
#define ROAD_GET_CR_MAX_X_RIGHT_COMPENSTATED    GET_ROAD_DATA_PTR->RoadEstimation.CoupledRoad.QualityMeasRight.f_MaxXCompensated
#define ROAD_GET_CR_TRACKSTAT_RIGHT             GET_ROAD_DATA_PTR->RoadEstimation.CoupledRoad.QualityMeasRight.u_TrackingStatus
#define ROAD_GET_CR_OFFSET_LEFT                 GET_ROAD_DATA_PTR->RoadEstimation.CoupledRoad.f_LateralOffsetLeft
#define ROAD_GET_CR_OFFSET_RIGHT                GET_ROAD_DATA_PTR->RoadEstimation.CoupledRoad.f_LateralOffsetRight
#define ROAD_GET_CR_CONFIDENCE                  GET_ROAD_DATA_PTR->RoadEstimation.CoupledRoad.u_GlobalConfidence
#define ROAD_GET_CR_TRACKSTAT                   GET_ROAD_DATA_PTR->RoadEstimation.CoupledRoad.u_GlobalTrackingStatus
#define ROAD_GET_CR_EST_STDEV                   GET_ROAD_DATA_PTR->RoadEstimation.CoupledRoad.f_LatStdDevFiltered

#define ROAD_GET_BL_YAWANGLE                    GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderLeft.ClothoidParams.f_YawAngle
#define ROAD_GET_BL_CURVATURE                   GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderLeft.ClothoidParams.f_Curvature
#define ROAD_GET_BL_CLOTHOID_PARAM              GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderLeft.ClothoidParams.f_ClothoidParam1
#define ROAD_GET_BL_TRANSITION_POINT            GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderLeft.ClothoidParams.f_TransitionPoint
#define ROAD_GET_BL_CLOTHOID_PARAM_2            GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderLeft.ClothoidParams.f_ClothoidParam2
#define ROAD_GET_BL_CONFIDENCE_LEFT             GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderLeft.QualityMeasLeft.f_Confidence
#define ROAD_GET_BL_MIN_X_LEFT                  GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderLeft.QualityMeasLeft.f_MinX
#define ROAD_GET_BL_MAX_X_LEFT                  GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderLeft.QualityMeasLeft.f_MaxX
#define ROAD_GET_BL_MAX_X_LEFT_COMPENSTATED     GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderLeft.QualityMeasLeft.f_MaxXCompensated
#define ROAD_GET_BL_TRACKSTAT_LEFT              GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderLeft.QualityMeasLeft.u_TrackingStatus
#define ROAD_GET_BL_CONFIDENCE_RIGHT            GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderLeft.QualityMeasLeft.f_Confidence
#define ROAD_GET_BL_MIN_X_RIGHT                 GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderLeft.QualityMeasRight.f_MinX
#define ROAD_GET_BL_MAX_X_RIGHT                 GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderLeft.QualityMeasRight.f_MaxX
#define ROAD_GET_BL_MAX_X_RIGHT_COMPENSTATED    GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderLeft.QualityMeasRight.f_MaxXCompensated
#define ROAD_GET_BL_TRACKSTAT_RIGHT             GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderLeft.QualityMeasRight.u_TrackingStatus
#define ROAD_GET_BL_OFFSET_LEFT                 GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderLeft.f_LateralOffsetLeft
#define ROAD_GET_BL_OFFSET_RIGHT                GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderLeft.f_LateralOffsetRight
#define ROAD_GET_BL_CONFIDENCE                  GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderLeft.u_GlobalConfidence
#define ROAD_GET_BL_TRACKSTAT                   GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderLeft.u_GlobalTrackingStatus
#define ROAD_GET_BL_EST_STDEV                   GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderLeft.f_LatStdDevFiltered

#define ROAD_GET_BR_YAWANGLE                    GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderRight.ClothoidParams.f_YawAngle
#define ROAD_GET_BR_CURVATURE                   GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderRight.ClothoidParams.f_Curvature
#define ROAD_GET_BR_CLOTHOID_PARAM              GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderRight.ClothoidParams.f_ClothoidParam1
#define ROAD_GET_BR_TRANSITION_POINT            GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderRight.ClothoidParams.f_TransitionPoint
#define ROAD_GET_BR_CLOTHOID_PARAM_2            GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderRight.ClothoidParams.f_ClothoidParam2
#define ROAD_GET_BR_CONFIDENCE_LEFT             GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderRight.QualityMeasLeft.f_Confidence
#define ROAD_GET_BR_MIN_X_LEFT                  GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderRight.QualityMeasLeft.f_MinX
#define ROAD_GET_BR_MAX_X_LEFT                  GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderRight.QualityMeasLeft.f_MaxX
#define ROAD_GET_BR_MAX_X_LEFT_COMPENSTATED     GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderRight.QualityMeasLeft.f_MaxXCompensated
#define ROAD_GET_BR_TRACKSTAT_LEFT              GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderRight.QualityMeasLeft.u_TrackingStatus
#define ROAD_GET_BR_CONFIDENCE_RIGHT            GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderRight.QualityMeasLeft.f_Confidence
#define ROAD_GET_BR_MIN_X_RIGHT                 GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderRight.QualityMeasRight.f_MinX
#define ROAD_GET_BR_MAX_X_RIGHT                 GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderRight.QualityMeasRight.f_MaxX
#define ROAD_GET_BR_MAX_X_RIGHT_COMPENSTATED    GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderRight.QualityMeasRight.f_MaxXCompensated
#define ROAD_GET_BR_TRACKSTAT_RIGHT             GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderRight.QualityMeasRight.u_TrackingStatus
#define ROAD_GET_BR_OFFSET_LEFT                 GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderRight.f_LateralOffsetLeft
#define ROAD_GET_BR_OFFSET_RIGHT                GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderRight.f_LateralOffsetRight
#define ROAD_GET_BR_CONFIDENCE                  GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderRight.u_GlobalConfidence
#define ROAD_GET_BR_TRACKSTAT                   GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderRight.u_GlobalTrackingStatus
#define ROAD_GET_BR_EST_STDEV                   GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderRight.f_LatStdDevFiltered

/* Access groups */
#define ROAD_GET_CR_DATA                        GET_ROAD_DATA_PTR->RoadEstimation.CoupledRoad
#define ROAD_GET_CR_PARAMETERS                  GET_ROAD_DATA_PTR->RoadEstimation.CoupledRoad.ClothoidParams
#define ROAD_GET_CR_LEFT_QUALITY                GET_ROAD_DATA_PTR->RoadEstimation.CoupledRoad.QualityMeasLeft
#define ROAD_GET_CR_RIGHT_QUALITY               GET_ROAD_DATA_PTR->RoadEstimation.CoupledRoad.QualityMeasRight
#define ROAD_GET_BL_DATA                        GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderLeft
#define ROAD_GET_BL_PARAMETERS                  GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderLeft.ClothoidParams
#define ROAD_GET_BL_QUALITY                     GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderLeft.QualityMeas
#define ROAD_GET_BR_DATA                        GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderRight
#define ROAD_GET_BR_PARAMETERS                  GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderRight.ClothoidParams
#define ROAD_GET_BR_QUALITY                     GET_ROAD_DATA_PTR->RoadEstimation.RoadBorderRight.QualityMeas

#define ROAD_SET_CONFIDENCE_LEFT_RIGHT(left,right)  \
  GET_ROAD_DATA_PTR->RoadEstimation.CoupledRoad.QualityMeasLeft.f_Confidence = left; \
  GET_ROAD_DATA_PTR->RoadEstimation.CoupledRoad.QualityMeasRight.f_Confidence = right;

#define ROAD_GET_MIN_MAX_TGT_DIST(fMinRight, fMaxRight, fMinLeft, fMaxLeft) \
  *fMinRight = GET_ROAD_DATA_PTR->RoadEstimation.CoupledRoad.QualityMeasRight.f_MinX; \
  *fMaxRight = GET_ROAD_DATA_PTR->RoadEstimation.CoupledRoad.QualityMeasRight.f_MaxXCompensated; \
  *fMinLeft  = GET_ROAD_DATA_PTR->RoadEstimation.CoupledRoad.QualityMeasLeft.f_MinX;  \
  *fMaxLeft  = GET_ROAD_DATA_PTR->RoadEstimation.CoupledRoad.QualityMeasLeft.f_MaxXCompensated;

/* ROAD TYPE */
#define ROAD_GET_ROADTYPE               GET_ROAD_DATA_PTR->RoadType.eRoadTypeClass
#define ROAD_GET_ROADWORKS              GET_ROAD_DATA_PTR->RoadType.eRoadWorksClass
#define ROAD_GET_ROADTYPE_CONF          GET_ROAD_DATA_PTR->RoadType.fRoadTypeClassConf
#define ROAD_GET_ROADWORKS_CONF         GET_ROAD_DATA_PTR->RoadType.fRoadWorksClassConf

#define ROAD_GET_TYPE1( iTypeLevel1, fTypeLevel1Conf)  \
  *iTypeLevel1     = GET_ROAD_DATA_PTR->RoadType.eRoadTypeClass; \
  *fTypeLevel1Conf = GET_ROAD_DATA_PTR->RoadType.fRoadTypeClassConf;

#define ROAD_GET_TYPE2( iTypeLevel2, fTypeLevel2Conf)  \
  *iTypeLevel2     = GET_ROAD_DATA_PTR->RoadType.eRoadWorksClass; \
  *fTypeLevel2Conf = GET_ROAD_DATA_PTR->RoadType.fRoadWorksClassConf

#define ROAD_GET_TYPE( iTypeLevel1, iTypeLevel2)  \
  *iTypeLevel1     = GET_ROAD_DATA_PTR->RoadType.eRoadTypeClass; \
  *iTypeLevel2     = GET_ROAD_DATA_PTR->RoadType.eRoadWorksClass

/* LANE MATRIX */
#define ROAD_GET_LANE_NO_LEFT                     GET_ROAD_DATA_PTR->LaneMatrix.iNumOfLaneLeft
#define ROAD_GET_LANE_NO_RIGHT                    GET_ROAD_DATA_PTR->LaneMatrix.iNumOfLaneRight
#define ROAD_GET_NO_LANE_MATRIX_PROB_LEFT         GET_ROAD_DATA_PTR->LaneMatrix.NoLaneProbLeft
#define ROAD_GET_NO_LANE_MATRIX_PROB_RIGHT        GET_ROAD_DATA_PTR->LaneMatrix.NoLaneProbRight

#endif

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
  #define TRACE_GET_FCT_ID(iTr)                   GET_TRACE(iTrace).ObjectTraceBasic.uiReferenceToFCTObject
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
#define TRACE_GET_FCT_ID(iTr)                     GET_MOVING_OBJ_TRACE_PTR(iTr)->uiReferenceToFCTObject
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
#define SENSOR_X_POSITION                         SENSOR_MOUNTING.LongPos //Sensor Position in CoFrA  Center of front wheel axle
#define SENSOR_Y_POSITION                         SENSOR_MOUNTING.LatPos  //TPGetSensorYPosition()
#define SENSOR_Z_POSITION                         SENSOR_MOUNTING.VertPos //

#define SENSOR_X_POSITION_CoG                     SENSOR_MOUNTING.LongPosToCoG  // (GET_EGO_STATIC_DATA_PTR->SensorMounting.LongPos + (GET_EGO_STATIC_DATA_PTR->VehParMain.WheelBase * GET_EGO_STATIC_DATA_PTR->VehParMain.AxisLoadDistr)) //Sensor Position in CoG Basic (static) center of gravity

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


/*! Set get macros for the vdy states */
#ifdef __PDO__
#define VDY_IO_STATE_BITMASK                   ((VDYIoState_t) (0x3U))
#define VDY_SET_IO_STATE(pos_, state_, val_)
#define VDY_GET_IO_STATE(pos_,val_)             0
#else
#if (VDY_VEH_DYN_INTFVER <= 5)
#define VDY_IO_STATE_BITMASK                   ((VDYIoState_t) (0x3U))
#define VDY_SET_IO_STATE(pos_, state_, val_)   ( (val_)[(pos_)/32UL] = (~((VDYIoState_t) (VDY_IO_STATE_BITMASK<<((pos_)%32UL))) & ((val_)[(pos_)/32UL])) | ((VDY_IO_STATE_BITMASK & (state_))<<((pos_)%32UL)))
#define VDY_GET_IO_STATE(pos_,val_)            ( ((val_)[(pos_)/32UL] >> ((pos_) % 32UL)) & VDY_IO_STATE_BITMASK)
#else
#define VDY_SET_IO_STATE(pos_, state_, val_)   ((val_)[(pos_)] = (state_))
#define VDY_GET_IO_STATE(pos_,val_)            ((val_)[(pos_)])

#define VDY_IO_STATE_BITMASK                       ((VDYIoState_t) (0x3U))
#define VDY_SET_NVM_IO_STATE(pos_, state_, val_)   ( (val_)[(pos_)/32UL] = (~((VDYIoState_t) (VDY_IO_STATE_BITMASK<<((pos_)%32UL))) & ((val_)[(pos_)/32UL])) | ((VDY_IO_STATE_BITMASK & (state_))<<((pos_)%32UL)))
#define VDY_GET_NVM_IO_STATE(pos_,val_)            ( ((val_)[(pos_)/32UL] >> ((pos_) % 32UL)) & VDY_IO_STATE_BITMASK)
#endif
#endif

/* Compatibility macros for old naming conventions. @TODO Cleanup with old traces*/
#define OBJ_INDEX_NO_OBJECT     ((ObjNumber_t)-1)

/* Compatibility macros for old naming conventions */
//#define STRING_QUOTE         ALGO_StringQuote


/*! used for RSPValidFlag */
#define RSP_VALID      (RSPValidFlag_t) 1    //TODO  -> RteType.h
#define RSP_INVALID    (RSPValidFlag_t) 0    //TODO  -> RteType.h

/*! maximum measuring distance far range scan */
#define RSP_DIST_MAX_FAR 200    //TODO  -> RteType.h

/*! number of reg of interest samples */
#define RSP_NUM_OF_REG_OF_INT_SAMP 20 //TODO -> move to RteType.h or remove completely from ARS400

/*! Virtual addresses or related records IDs (in case of framework lookup table) for 
    data acquisition interface. The addresses or IDs values must correspond to addresses 
    specified in data description file (SDL, A2L etc.) */
#define MEAS_ID_EGO_STATIC_PUBLIC_GLOB_DATA   0x2000FC80uL          /* GLOB DATA */     //TODO  -> RteType.h


/* target distance for which the elevation peak ratio is minimized */
#define ALGO_OPTIMIZED_TARGET_DIST_FOR_ELEVATION  70.f

/* returns the systematic offset applied for the elevation angle */
ALGO_INLINE float32 ALGO_GetElevationOffset(const float32 f_MountingHeight)
{
  return f_MountingHeight * ((-1.f)/ALGO_OPTIMIZED_TARGET_DIST_FOR_ELEVATION);
}

#ifndef _PARAM_UNUSED
#define _PARAM_UNUSED(x) (void)(x)
#endif

/* @todo: Once name change done, remove old ALN output name alias! */
typedef ALN_Monitoring_t ALN_S_Monitoring_t;

#endif
