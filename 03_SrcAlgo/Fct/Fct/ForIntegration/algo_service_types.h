// **********************************************************************
// 
//COMPANY:     Continental Automotive , 
// 
//PROJECT:     ARS400
//    
//CPU:         MPC5677N
// 
//Component:   -/-
// 
//MODULNAME:   FullModelElementName
// 
//- Description:	short description of the file
//- CPU:		optional for HW dependent SW: processor name (e.g. MPC5674F)
//
//- Verwendung:

// 
// **********************************************************************         


#ifndef algo_service_types_H
#define algo_service_types_H

#include "glob_type.h"
#include "MTS_Adaption.h"
#include "MTS_Application.h"

#if (!defined(_MSC_VER)) /* Microsoft compiler -> code not for simulation */
//#include "RTA.h"
#endif

#define AS_SERVICEFUNC_VERSION 1u

/* ================================================================================================================= */


//**************************************************************************
//Type: MTS_Hdlr
//Definition of Algo Sevice: Mts Freeze
//- Mts Info Ptr [In]
//- Data Ptr [In]
//- Meas Callback - notification [In]
//
/*#[ type MTS_Hdlr */
typedef MEASReturn_t (*MTS_Hdlr)(const MEASInfo_t *, void *, MEAS_Callback_t);
/*#]*/

//**************************************************************************
//Type: MTS_u_GetHighResTimestamp
//Definition of Algo Sevice: Returns high resolution time stamp [1 �s]
//
/*#[ type MTS_u_GetHighResTimestamp */
typedef uint32 (*MTS_GetHighResTimestamp)(void);
/*#]*/

//**************************************************************************
//Type: MTS_v_SetTaskCounter
//Definition of Algo Sevice: Returns high resolution time stamp [1 �s]
//
/*#[ type MTS_v_SetTaskCounter */
typedef uint32 (*MTS_SetTaskCounter)(const uint16 u_TaskId);
/*#]*/

typedef MEASReturn_t (*AS_t_MeasHdlr)(const MEASInfo_t *, void *, MEAS_Callback_t);
typedef MEASReturn_t (*MeasHdlr_t)(const MEASInfo_t *, void *, MEAS_Callback_t );

//**************************************************************************
//Type: AS_t_GetTimestampuS32
//- Description:	short description, meaning, usage
//- Range:		range of variable (Min - Max) based on raw value
//- Resolution:	resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:		physical unit (e.g. m/s^2)
//
/*#[ type AS_t_GetTimestampuS32 */
typedef uint32 (*AS_t_GetTimestampuS32) (void);
/*#]*/

//**************************************************************************

//#if (!defined(_MSC_VER)) /* Microsoft compiler -> code not for simulation */
/* empty for frame software */
//#define AS_t_RtaEventType RTA_t_EventList
//#define e_RTA_EVT_AlgoStart RTA_EVT_ALGOSTART
//#define e_RTA_EVT_AlgoEnd RTA_EVT_ALGOEND
//#else
//Type: AS_t_RtaEventType
//- Description:	short description, meaning, usage
//- Range:		range of variable (Min - Max) based on raw value
//- Resolution:	resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:		physical unit (e.g. m/s^2)
//
/*#[ type AS_t_RtaEventType */
typedef enum {
    e_RTA_EVT_Marker      = 0,
    e_RTA_EVT_AlgoStart   = 1,
    e_RTA_EVT_AlgoEnd     = 2,
    e_RTA_EVT_TSK_Switch  = 3,
    e_RTA_EVT_TSK_Rdy     = 4,
    e_RTA_EVT_MAX_TYPES   = 5,
    /* RTA_EVT_MAX_TYPES must be smaller than 256 */
    /* compiler workaround */
    e_RTA_EVT_LAST_ENTRY  = 65536
} AS_t_RtaEventType;
/*#]*/
//#endif

typedef MEASInfo_t AS_t_MeasInfo;
typedef MEAS_Callback_t AS_t_MeasCallback;

//**************************************************************************
//Type: AS_t_RTAAlgoServiceAddEvent
//- Description:	short description, meaning, usage
//- Range:		range of variable (Min - Max) based on raw value
//- Resolution:	resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:		physical unit (e.g. m/s^2)
//
/*#[ type AS_t_RTAAlgoServiceAddEvent */
//#if (!defined(_MSC_VER)) /* Microsoft compiler -> code not for simulation */
//typedef void (*AS_t_RTAAlgoServiceAddEvent)(const RTA_t_EventList RTA_t_Event, const uint8 u_GlobalId, const uint8 u_LocalId, const uint8 u_OptData);
//#else
typedef sint32 (*AS_t_RTAAlgoServiceAddEvent)(AS_t_RtaEventType RtaEvtType, uint8 u_IdGlobal, uint8 u_IdLocal, uint8 u_OptData);
//#endif
/*#]*/

typedef struct
{
	uint32             					u_Version;
    AS_t_MeasHdlr						pfMeasFreeze;
    AS_t_GetTimestampuS32				pfGetTimestampuS32;
	AS_t_RTAAlgoServiceAddEvent 		pfRTAAlgoServiceAddEvent;  // Dummy
} AS_t_ServiceFuncts;


#endif
/*********************************************************************
	File Path	: ..\..\..\04_Engineering\01_Source_Code\common\algo_service_types.h
*********************************************************************/
