/*! \file **********************************************************************

  
  MODULENAME:             glob_type_project.h

  DESCRIPTION:            This file contains project specific global types, 
                          which are used in more than one component and not
                          exported by a component he-file.


  CHANGES
  ---*/ /*---

  VERSIONNUMBER:          $Revision: 1.1 $

  EDITOR NAME:            $Author: Wang, David (Wangd3) $

  CHANGE:                 $Log: glob_type_project.h  $
  CHANGE:                 Revision 1.1 2021/12/13 17:26:17CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310_sr/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:37:22CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310_sr/project.pj
  CHANGE:                 Revision 1.1 2014/03/13 15:12:53CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310_sr/project.pj
  CHANGE:                 Revision 1.1 2009/10/14 18:57:25CEST hwill 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/BaseDevelopment_Camera_SW/02_Engineering/TMS320DM643x/11_MFC300/01_Design/vuc/headers/project.pj
 * 
 *    Rev 1.1   Dec 09 2008 17:32:52   uidl6172
 * added enums for IC component
 * 
 *    Rev 1.0   Nov 18 2008 16:32:58   uid07728
 * Initial revision.
  CHANGE:                 Revision 1.1.2.1 2008/03/27 15:34:44CET jfuehrman 
  CHANGE:                 changes for CSF200/201
  CHANGE:                 --- Added comments ---  jfuehrman [2008/03/27 14:34:44Z]
  CHANGE:                 Change Package : 10691:2 http://liss014:6001/im/viewissue?selection=10691
  CHANGE:                 Revision 1.1 2007/10/04 09:02:53CEST kreinbott 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/customer/Base_ARS3xx_ISF1xx/3_development/4_sw/dev/appl/mcu_master/src/glob/project.pj


*****************************************************************************/
#ifndef GLOB_TYPE_PROJECT_H
#define GLOB_TYPE_PROJECT_H

#if 0
/*************************************************************/
/* types for vendor specific APIs */
/* *** do not use this types for any regular coding *** */

/* *1 = this type allows direct inclusion of TI headers, e.g. for the MSGQ module */
/* *2 = this type allows direct inclusion of MSGQ sysemulation.h */

/*! "Void" alias define for the void type, *1 */
#define Void void

/*! "Char" alias define for the char type, *1 */
#define Char char
#ifdef WIN32
#define _WINCON_ /* above define conflicts with struct from the _WINCON_ header */
#endif

/*! "Uns" alias define for the ui32_t, *1 */
#define Uns ui32_t

/*! "Int" alias define for the i32_t type, *1 */
#define Int i32_t


/*! generic function pointer type, *1 */
typedef Int (*Fxn)();

/*! void pointer type, *1 */
typedef void *Ptr;

/*! char pointer type, points to a null-terminated character sequence, *1 */
typedef char *String;

/*! boolean type, matches Windows boolean def, *1 */
typedef long Bool;


#define TI_FALSE  ((Bool)(1==0)) /* *1 */
#define TI_TRUE   ((Bool)(1==1)) /* *1 */

typedef i8_t                Int8;     /*<  8 bit signed, *1 */
typedef i16_t               Int16;    /*< 16 bit signed, *1 */
typedef i32_t               Int32;    /*< 32 bit signed, *1 */

typedef ui8_t               Uint8;    /*<  8 bit unsigned, *1 */
typedef ui16_t              Uint16;   /*< 16 bit unsigned, *1 */
typedef ui32_t              Uint32;   /*< 32 bit unsigned, *1 */

typedef float               Real32;   /*< 32 bit float, *1 */
typedef double              Real64;   /*< 64 bit float, *1 */

typedef char                Char8;    /*<  8 bit signed, *1 */
typedef short               Char16;   /*< 16 bit signed, *1 */

typedef unsigned char       Uchar8;   /*<  8 bit unsigned, *1 */
typedef unsigned short      Uchar16;  /*< 16 bit unsigned, *1 */


typedef ui32_t              U32;      /*< 32 bit unsigned *2 */



/*************************************************************/

/*! Type definition for DynamicProperty */
typedef enum
{
  NO_OBJECT   = 0u,
  STANDING    = 1u,
  STOPPED     = 2u,
  MOVING      = 3u,
  ONCOMING    = 4u,
  CROSSING    = 5u,
  CUT_IN      = 6u,
  CUT_OUT     = 7u,
  OVERTAKING  = 8u,
  BREAKING    = 9u,
  BACKSLIDING = 10u,
  UNCLASSIFIED = 11u
} DynamicProperty_t;

/*! Type definition for Object Class*/
typedef enum
{
  CLASS_UNKONWN = 0u,		/* old: NO_CLASS    = 0u, */
  CAR			= 1u,
  TRUCK			= 2u,
  BIKE			= 3u,
  PEDESTRIAN	= 4u,
  WIDE_OBJECT	= 5u,
  POINT_OBJECT	= 6u,
  BRIDGE		= 7u,
  GUARDRAIL		= 8u,
  MOTORCYCLE = 9u,
  OBSTACLE = 10u,
  OVERHEAD_OBJECT = 11u,
  GARBAGE = 12u
} ObjectClassification_t;

/*!Type definition for Object Status*/
typedef enum
{
  OBJ_NONE         = 0u,
  OBJ_NEW          = 1u,
  OBJ_NOT_MEASURED = 2u,
  OBJ_MEASURED     = 3u
} MeasStatus_t;

/* Type definition for AssignedLane */
typedef enum
{
  LANE_UNKNOWN = 0u,
  HOST_LANE = 1u,
  RIGHT_LANE = 2u,
  LEFT_LANE = 3u,
  FAR_RIGHT = 4u,
  FAR_LEFT = 5u
} AssignedLane_t;

/*! Type definition for EMVSwitch bits. The bits have to be evaluated inverted (EEPROM default is 0xFFFFFFFF) */
typedef enum
{
  BIT_NO_BIT                = 0u,     /*!< (Inverted) Nothing set */
  BIT_NO_SLEEP              = 1u,     /*!< (Inverted) Device will not sleep - even if no CAN message was received */
  BIT_ENABLE_DSP_DEBUGGING  = 2u      /*!< (Inverted) DSP debugging is enabled (some monitoring is switched off) */
} EMVSwitch_t;

#endif

#endif



