/***************************************************************************************************

  COMPANY:      Continental Automotive

  COMPONENT:    RTA - real time analysis

  MODULE NAME:  RTA

  VERSION:      $Revision: 1.8 $

***************************************************************************************************/

/** ************************************************************************************************
  \file     RTA_Types.h

  \brief    This header is intended for interface exchange with sensorics. \n
            It defines all RTA types needed by sensorics.
            \b Note: In order to ensure usability for sensorics it must not include other headers.

***************************************************************************************************/

/***************************************************************************************************

  File Name:      $Source: RTA_Types.h $
  Developer:      Matthias Kammerl

  Last Author:    $Author: Rajana, Sanyasinaidu (uib10172) (uib10172) $
  Last Change:    $Date: 2019/06/05 14:49:44CEST $

***************************************************************************************************/

/***************************************************************************************************

  File History:

  Changes:        $Log: RTA_Types.h  $
  Changes:        Revision 1.8 2019/06/05 14:49:44CEST Rajana, Sanyasinaidu (uib10172) (uib10172) 
  Changes:        glob_defs.h included to fix  compiler errors.
  Changes:        Revision 1.7 2017/01/31 11:52:57CET Kammerl, Matthias (uidr3468) 
  Changes:        Prepare for usage in dpu
  Changes:        Revision 1.6 2016/10/26 08:56:50CEST Kammerl, Matthias (uidr3468) 
  Changes:        Design adaptations according new template.
  Changes:        Revision 1.5 2016/09/13 15:20:39CEST Kammerl, Matthias (uidr3468) 
  Changes:        Correct RtaAlgoInterface
  Changes:        Revision 1.4 2016/09/13 12:34:36CEST Kammerl, Matthias (uidr3468) 
  Changes:        Introduce versioning of RTA_Interface
  Changes:        Revision 1.3 2016/09/07 11:30:20CEST Kammerl, Matthias (uidr3468) 
  Changes:        Move RTA_t_Events to RTA_Types.h in order to ensure usability by Sensorics.

***************************************************************************************************/

#ifndef RTA_Types_H
#define RTA_Types_H

#include "glob_defs.h"

#ifdef __cplusplus
extern "C"
{
#endif


/** Description: This define is used by sensorics to ensure compatibility.\n
 *               \b Note: It has to be incremented whenever the enum RTA_t_Events or the typedef RTA_t_ServiceAddEvent is changed\n
 * */
#define RTA_INTERFACE_VERSION 4

/** Description:  This enum defines all eventTypes provided by RTA.\n
 *               \b Note: As it is a direct interface to the MO running on the MTS this enum has to be \n
 *                        compatible to the MO.  \n
 * */
typedef enum
{
  RTA_EVT_MARKER,           ///< 0; Visualize an event
  RTA_EVT_ALGOSTART,        ///< 1; Mark the start of a time period
  RTA_EVT_ALGOEND,          ///< 2; Mark the end of a time period
  RTA_EVT_TASKSWITCH,       ///< 3; Mark a task switch
  RTA_EVT_TASKRDY,          ///< 4; Mark the task as ready
  RTA_EVT_SAMPLEVALUE,      ///< 5;
  RTA_EVT_SAMPLESELECT,     ///< 6;
  RTA_EVT_MAX_TYPES         ///Has to be smaller than 256
} RTA_t_Events;

/** Description:  This is a typeDefinition for functionPointer to the serviceFunction RTA_v_AddEvent.\n
 *                 \b Note: It is used by sensorics, do not change it if not really needed! \n
 * */
typedef void (*RTA_t_ServiceAddEvent)(const RTA_t_Events EVENT, const uint8 u_GLOBALID, const uint8 u_LOCALID, const uint8 u_OPTDATA);

/** Description: This defines are necessary for compatibility reason.
 */
#define e_RTA_EVT_Marker        RTA_EVT_MARKER
#define e_RTA_EVT_AlgoStart     RTA_EVT_ALGOSTART
#define e_RTA_EVT_AlgoEnd       RTA_EVT_ALGOEND
#define e_RTA_EVT_TSK_Switch    RTA_EVT_TASKSWITCH
#define e_RTA_EVT_TSK_Rdy       RTA_EVT_TASKRDY
#define e_RTA_EVT_SampleValue   RTA_EVT_SAMPLEVALUE
#define e_RTA_EVT_SampleSelect  RTA_EVT_SAMPLESELECT
#define e_RTA_EVT_MAX_TYPES     RTA_EVT_MAX_TYPES



#ifdef __cplusplus
}
#endif


#endif //#ifndef RTA_Types_H

