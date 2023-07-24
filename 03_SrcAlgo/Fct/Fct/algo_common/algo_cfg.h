/*! \file **********************************************************************

  COMPANY:                Continental Temic, PC DAS, A.D.C. GmbH

  PROJECT:                All

  CPU:                    All

  COMPONENT:              RTE

  MODULNAME:              algo_cfg.h

  DESCRIPTION:            configuration file for algo components:
                          - parameters and switches which effect several components
                          - application switches for modules which are not applicated to customer projects
                            (only activation/deactivation of functionalities)


  CREATION DATE:          23.03.2010

  VERSION:                $Revision: 1.20 $

  ---*/ /*---
  CHANGES:                   $Log: algo_cfg.h  $
  CHANGES:                   Revision 1.20 2015/04/02 09:51:14CEST Eisenacher, Michael (eisenacherm) 
  CHANGES:                   added CORRECTED_EGO_SPEED_IS_ZERO_ON_ROLLER_BENCH with value 1
  CHANGES:                   - Added comments -  eisenacherm [Apr 2, 2015 9:51:14 AM CEST]
  CHANGES:                   Change Package : 320951:7 http://mks-psad:7002/im/viewissue?selection=320951
  CHANGES:                   Revision 1.19 2014/04/11 09:40:00CEST uidg3348 
  CHANGES:                   Doxygen: Update for Doxygen Version 1.82, add doxygen comments for settings
  CHANGES:                   --- Added comments ---  uidg3348 [Apr 11, 2014 9:40:00 AM CEST]
  CHANGES:                   Change Package : 227155:1 http://mks-psad:7002/im/viewissue?selection=227155
  CHANGES:                   Revision 1.18 2014/03/21 13:16:18CET Schluttig, Jakob (uidv7098) 
  CHANGES:                   fixed PC-Lint Misra issue
  CHANGES:                   --- Added comments ---  uidv7098 [Mar 21, 2014 1:16:19 PM CET]
  CHANGES:                   Change Package : 215875:1 http://mks-psad:7002/im/viewissue?selection=215875
  CHANGES:                   Revision 1.17 2014/01/27 10:56:04CET Fuentes, Juan-Carlos (uidu2446) 
  CHANGES:                   - remove outdated comment.
  CHANGES:                   --- Added comments ---  uidu2446 [Jan 27, 2014 10:56:04 AM CET]
  CHANGES:                   Change Package : 212874:2 http://mks-psad:7002/im/viewissue?selection=212874
  CHANGES:                   Revision 1.16 2013/07/31 11:29:53CEST Schluttig, Jakob (uidv7098) 
  CHANGES:                   fixed PC-Lint Misra issue
  CHANGES:                   --- Added comments ---  uidv7098 [Jul 31, 2013 11:29:54 AM CEST]
  CHANGES:                   Change Package : 183793:2 http://mks-psad:7002/im/viewissue?selection=183793
  CHANGES:                   Revision 1.15 2013/07/23 15:41:22CEST Schluttig, Jakob (uidv7098) 
  CHANGES:                   added (boolean) define indicating whether far scan is available
  CHANGES:                   --- Added comments ---  uidv7098 [Jul 23, 2013 3:41:23 PM CEST]
  CHANGES:                   Change Package : 189720:1 http://mks-psad:7002/im/viewissue?selection=189720
  CHANGES:                   Revision 1.14 2013/07/22 17:08:56CEST Eisenacher, Michael (eisenacherm) 
  CHANGES:                   added camera fusion for B1 sample
  CHANGES:                   --- Added comments ---  eisenacherm [Jul 22, 2013 5:08:56 PM CEST]
  CHANGES:                   Change Package : 180551:1 http://mks-psad:7002/im/viewissue?selection=180551
  CHANGES:                   Revision 1.13 2013/07/18 18:59:00CEST Ungvary, Gergely (ungvaryg) 
  CHANGES:                   Replace ADC specific types with standard Autosar types
  CHANGES:                   --- Added comments ---  ungvaryg [Jul 18, 2013 6:59:00 PM CEST]
  CHANGES:                   Change Package : 179559:11 http://mks-psad:7002/im/viewissue?selection=179559
  CHANGES:                   Revision 1.12 2013/07/09 17:09:42CEST Fuentes, Juan-Carlos (uidu2446) 
  CHANGES:                   - adapted for B1.
  CHANGES:                   - dsiabled camera fusion until the camera structs are available.
  CHANGES:                   --- Added comments ---  uidu2446 [Jul 9, 2013 5:09:42 PM CEST]
  CHANGES:                   Change Package : 187998:1 http://mks-psad:7002/im/viewissue?selection=187998
  CHANGES:                   Revision 1.11 2013/05/15 15:47:36CEST Eisenacher, Michael (eisenacherm) 
  CHANGES:                   - bugfix: unknown define removed
  CHANGES:                   --- Added comments ---  eisenacherm [May 15, 2013 3:47:37 PM CEST]
  CHANGES:                   Change Package : 165941:3 http://mks-psad:7002/im/viewissue?selection=165941
  CHANGES:                   Revision 1.10 2013/04/09 13:42:53CEST Eisenacher, Michael (eisenacherm) 
  CHANGES:                   added switch for ARS400 B0 sample
  CHANGES:                   --- Added comments ---  eisenacherm [Apr 9, 2013 1:42:53 PM CEST]
  CHANGES:                   Change Package : 165941:3 http://mks-psad:7002/im/viewissue?selection=165941
  CHANGES:                   Revision 1.9 2013/02/05 10:28:48CET Oprisan, Dan (oprisand) 
  CHANGES:                   - add/correct file header
  CHANGES:                   --- Added comments ---  oprisand [Feb 5, 2013 10:28:48 AM CET]
  CHANGES:                   Change Package : 139701:25 http://mks-psad:7002/im/viewissue?selection=139701

**************************************************************************** */
#ifndef ALGO_CFG_H_INCLUDED
#define ALGO_CFG_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "algo_sensor_params.h"

/*****************************************************************************
  MACROS 
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

/*! Switch ON conditions for PDO tool */
#define SWITCH_ON                   1
/*! Switch OFF conditions for PDO tool */
#define SWITCH_OFF                  0

/*! Global switch for enabling EM/FCT code for fusion of camera and radar
data. */
#define ALGO_CFG_CameraRadarFusion	(1)
/*! CFG_CAMERA_RADAR_FUSION setting */
#define CFG_CAMERA_RADAR_FUSION     ALGO_CFG_CameraRadarFusion	 

/*! true if sensor type is one of the ARS400 family */
#define ALGO_ARS400Sensor		( (ALGO_SensorType == ALGO_CFG_ARS400PPLUS) || (ALGO_SensorType == ALGO_CFG_ARS400P) || (ALGO_SensorType == ALGO_CFG_ARS400S) || (ALGO_SensorType == ALGO_CFG_ARS400Entry) )

/*! true if code is generated for ARS400 B0 sample */
#define ALGO_ARS400_B0_Sample       (0)

/*! true if separate far scan cluster lists are available */
#define ALGO_CFG_FarScanAvailable   (SYS_NUM_OF_SCANS > 1)

/*! Configuration switch enabling SRR code*/
#define SRR_SWITCH                                 (0)

/*! If TRUE, corrected ego speed is set to zero by VDY, if roller test bench is detected by EM.
    Independent from this switch the flag bRollerTestBench is set to TRUE, if roller test bench is detected by EM.
	To avoid unexpected behaviour on roller bench for each customer project, VDY does not compile if this flag does not exist
	This flag shell be set to TRUE for each customer project without contradictory customer requirements. */
#define CORRECTED_EGO_SPEED_IS_ZERO_ON_ROLLER_BENCH		(1)

/*! traces */
#define NEW_TRACES                  (0)      /* 1: Calculate new traces */

/*! number of supporting points for traces */
#define TRACE_NO_OF_PTS    					((sint8)   25  )//EO_MOT_NO_PTS

/*! for check, whether trace is occupied but without obj */
#define TRACE_VALID_NO_OBJ_ID       ((uint8)  249 )//EOMOT_VALID_NO_OBJ_ID
/*! for check, whether trace is occupied     with    obj */
#define TRACE_VALID_OBJ_ID          ((uint8)  250 )//EOMOT_VALID_OBJ_ID
/*! define to transfer the 16 bit scales trace vectors back to the not scaled f32 vectors */
#define TRACE_SCALE_CONST_INV       (1.0F/(float32)TRACE_SCALE_CONST)

/*! switch for the lowering of RCS thresholds for low and medium veigen for better
performance in pedestrian detection */
#define RCS_THR_PED                               (0)

/*! Configuration switch enabling low speed pedestrian selection support in
EM and FCT components. This switch was formerly in TP with the name
CFG_SI_LOW_SPEED_STAT_PEDESTRIAN */
#define CFG_LOW_SPEED_STAT_PEDESTRIAN              (0)

#else
/* do nothing */
#endif //ALGO_CFG_H_INCLUDED
