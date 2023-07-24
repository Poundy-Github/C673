/*~A*/
/*~+:VM Header*/
/* UML source model state: Draft */
/* ## Module Header Start [17f621ff-637d-4de0-b704-57239c701b36] */
/****************************************************************************

COPYRIGHT (C) $Date: 2019/07/03 13:45:21CEST $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.                                                 

The reproduction, transmission or use of this document or its contents is  
not permitted without express written authority.                           
Offenders will be liable for damages. All rights, including rights created 
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------

$Log: f32_calm.h  $
Revision 1.3 2019/07/03 13:45:21CEST Nastasa, Elena (uidt4846) 
Update SDA Library files
Revision 1.2 2019/04/10 07:45:51CEST Karmann Andreas-Johannes (uidk6640) (uidk6640) 
RO-9740446:1:AnKa: preload libraries: solved issues in preloading libraries
Revision 1.1 2018/07/24 16:49:20CEST Ammermueller Martin (uidv5342) (uidv5342) 
Initial revision
Member added to project /ES/1T/0C/SDA/SDA_Source/SDA_Toolboxes/ACG/Libraries/calm_f32/Src/3_1_0/project.pj
Revision 1.2 2018/03/06 08:04:16CET Angadi Hampa (uidu8151) (uidu8151) 
RO : 8197570 : MISRA2012 ANSI VERSIONS
Revision 1.7 2017/11/22 12:15:48CET Angadi Hampa (uidu8151) (uidu8151) 
TC38X validation.
Revision 1.6 2017/08/16 12:16:19CEST Ugran Parimala (uid41586) (uid41586) 
Newly added functions to F32_Calm
Revision 1.5 2017/08/07 14:40:46CEST Ugran Parimala (uid41586) (uid41586) 
Adding new Functions to F32_CALM
Revision 1.3 2013/08/22 08:38:31CEST Angadi Hampa (uidu8151) (uidu8151) 
for release RO 429670 :FS_0G01_TC2XX_F32CALM_100
Revision 1.2 2013/08/05 09:46:35IST Angadi Hampa (uidu8151) (uidu8151) 
429670 :FS_0G01_TC2XX_F32CALM_100  Description Correction
Revision 1.1 2013/08/01 11:22:48IST Angadi Hampa (uidu8151) (uidu8151) 
Initial revision
Member added to project /ES/FS/0D/bsw/stdlib/tc2xx/f32_calm/f32_calm/if/i/project.pj
Revision 1.1 2013/04/04 10:46:52CEST Grabow Marcus (uid08755) (uid08755) 
Initial revision
Member added to project /ES/FS/1T/03/UML_Development/DevelopmentSpace/Appl_Uml_ToolBox/Exporters/Uml_Exporter_C/Data/project.pj
Revision 1.1 2013/03/20 08:07:52CET Grabow Marcus (uid08755) (uid08755) 
Initial revision
Member added to project /ES/FS/1T/03/UML_Development/DevelopmentSpace/Appl_Uml_ToolBox/Exporters/Uml_Exporter_C/Core/Data/project.pj
Revision 1.3 2012/01/17 10:50:32CET Grabow Marcus (uid08755) (uid08755) 
-
Revision 1.2 2011/03/10 12:17:55CET Grabow Marcus (uid08755) (uid08755) 

 ****************************************************************************/
/* ## Module Header End [17f621ff-637d-4de0-b704-57239c701b36] */

/*~E*/
#ifndef F32_CALM_H
#define F32_CALM_H
/*~+:Includes*/

#include <Std_Types.h>
#include <powersar_addon_types.h>
/*~+:Structure TypeDefs*/
/** FDPS_RESULT is a structure, where line_count, line_index and line_factor are the structure elements. Data point search functions shall set these elements which shall be later used by the interpolation functions. */
typedef struct FDPS_RESULT_tag FDPS_RESULT;
/*~E*/
/*~A*/
/*~+:Structure Definitions*/
struct FDPS_RESULT_tag
{
	uint8 line_count;                                /** line_count : Number of data points in Axis */
	uint8 line_index;                                /** line_index : Location of the smaller data point, where the parameter value is in between two data points */
	float32 line_factor;                             /** line_factor : The ratio of the difference between the parameter value and the next smaller data point  and the  difference  between the two data points (with the given parameter value in between them) */
};

/*~E*/
/*~A*/
/*~+:Macro Operations*/
/* Macro operation name: F32_PTR_IP1D */
/** This operation performs interpolation for the given 1D interpolation map of type F32 and pointer to structure variable for x-axis of type  FDPS_RESULT and returns the interpolated value of type F32.

@param map Pointer to 1D map of type float32.
@param dpsx Pointer to structure of type FDPS_RESULT. */
/* ## Macro operation start [b7ef76da-5cd6-4242-a11c-89096c3fb953] */
#define F32_PTR_IP1D(map, dpsx)  function_f32_ptr_ip1d(map, dpsx)
/* ## Macro operation end [b7ef76da-5cd6-4242-a11c-89096c3fb953] */

/* Macro operation name: F32_U8PTR_IP1D */
/** This operation performs interpolation for the given 1D interpolation map of type U8 and pointer to structure variable for x-axis of type FDPS_RESULT and returns the interpolated value of type F32.

This operation has the return type different from the map type.

@param map Pointer to 1D map of type Uint8.
@param dpsx Pointer to structure of type FDPS_RESULT. */
/* ## Macro operation start [fcca2e9d-c3b2-4454-98b4-fc2001872305] */
#define F32_U8PTR_IP1D(map, dpsx)  function_f32_u8ptr_ip1d(map, dpsx)
/* ## Macro operation end [fcca2e9d-c3b2-4454-98b4-fc2001872305] */

/* Macro operation name: F32_U16PTR_IP1D */
/** This operation performs interpolation for the given 1D interpolation map of type U16 and pointer to structure variable for x-axis of type FDPS_RESULT and returns the interpolated value of type F32.

This operation has the return type different from the map type.

@param map Pointer to 1D map of type Uint16.
@param dpsx Pointer to structure of type FDPS_RESULT. */
/* ## Macro operation start [5b8d4e1b-e95e-4ebe-9e6a-3620556c1871] */
#define F32_U16PTR_IP1D(map, dpsx)  function_f32_u16ptr_ip1d(map, dpsx)
/* ## Macro operation end [5b8d4e1b-e95e-4ebe-9e6a-3620556c1871] */

/* Macro operation name: F32_S8PTR_IP1D */
/** This operation performs interpolation for the given 1D interpolation map of types s8 and pointer to structure variable for x-axis of type FDPS_RESULT and returns the interpolated value of type F32.

This operation has the return type different from the map type.

@param map Pointer to 1D map of type Sint8.
@param dpsx Pointer to structure of type FDPS_RESULT. */
/* ## Macro operation start [18db7173-659a-4a4a-963f-095e08fcf3ca] */
#define F32_S8PTR_IP1D(map, dpsx)  function_f32_s8ptr_ip1d(map, dpsx)
/* ## Macro operation end [18db7173-659a-4a4a-963f-095e08fcf3ca] */

/* Macro operation name: F32_S16PTR_IP1D */
/** This operation performs interpolation for the given 1D interpolation map of type S16 and pointer to structure variable for x-axis of type FDPS_RESULT and returns the interpolated value of type F32.

This operation has the return type different from the map type.

@param map Pointer to 1D map of type Sint16
@param dpsx Pointer to structure of type FDPS_RESULT. */
/* ## Macro operation start [40effe4e-9c1a-42cd-87c8-6be04d8a8da3] */
#define F32_S16PTR_IP1D(map, dpsx)  function_f32_s16ptr_ip1d(map, dpsx)
/* ## Macro operation end [40effe4e-9c1a-42cd-87c8-6be04d8a8da3] */

/* Macro operation name: F32_PTR_IP2D */
/** This operation performs interpolation for the given 2D interpolation map of type F32 and pointers to structure variable for x and y axes of type FDPS_RESULT and returns the interpolated value of type F32.

@param map Pointer to 2D map of type float32.
@param dpsx Pointer to structure of type FDPS_RESULT for x axis.
@param dpsy Pointer to structure of type FDPS_RESULT for y axis. */
/* ## Macro operation start [df2738fb-dbe2-46cb-ae92-057964eeabfa] */
#define F32_PTR_IP2D(map, dpsx, dpsy)  function_f32_ptr_ip2d((const float32 *)(const void *)map, dpsx, dpsy)
/* ## Macro operation end [df2738fb-dbe2-46cb-ae92-057964eeabfa] */

/* Macro operation name: F32_U8PTR_IP2D */
/** This operation performs interpolation for the given 2D interpolation map of type Uint8 and pointers to structure variable for x and y axes of type FDPS_RESULT and returns the interpolated value of type Float32.

This operation has the return type different from the map type.

@param map Pointer to 2D map of type Uint8.
@param dpsx Pointer to structure of type FDPS_RESULT for x axis.
@param dpsy Pointer to structure of type FDPS_RESULT for y axis. */
/* ## Macro operation start [9f130122-78e6-4913-97d8-0ff43c4c9ffd] */
#define F32_U8PTR_IP2D(map, dpsx, dpsy)  function_f32_u8ptr_ip2d((const uint8 *)map, dpsx, dpsy)
/* ## Macro operation end [9f130122-78e6-4913-97d8-0ff43c4c9ffd] */

/* Macro operation name: F32_U16PTR_IP2D */
/** This operation performs interpolation for the given 2D interpolation map of type Uint16 and pointers to structure variable for x and y axes of type FDPS_RESULT and returns the interpolated value of type float32.

This operation has the return type different from the map type.

@param map Pointer to 2D map of type Uint16.
@param dpsx Pointer to structure of type FDPS_RESULT for x axis.
@param dpsy Pointer to structure of type FDPS_RESULT for y axis. */
/* ## Macro operation start [c51328b2-50af-4145-8664-d3de30194677] */
#define F32_U16PTR_IP2D(map, dpsx, dpsy)  function_f32_u16ptr_ip2d((const uint16 *)(const void *)map, dpsx, dpsy)
/* ## Macro operation end [c51328b2-50af-4145-8664-d3de30194677] */

/* Macro operation name: F32_S8PTR_IP2D */
/** This operation performs interpolation for the given 2D interpolation map of type Sint8 and pointers to structure variable for x and y axes of type FDPS_RESULT and returns the interpolated value of type Float32.

This operation has the return type different from the map type.

@param map Pointer to 2D map of type Sint8.
@param dpsx Pointer to structure of type FDPS_RESULT for x axis.
@param dpsy Pointer to structure of type FDPS_RESULT for y axis. */
/* ## Macro operation start [d822cb53-0ab8-46df-8552-3220e9aa689a] */
#define F32_S8PTR_IP2D(map, dpsx, dpsy)  function_f32_s8ptr_ip2d((const sint8 *)map, dpsx, dpsy)
/* ## Macro operation end [d822cb53-0ab8-46df-8552-3220e9aa689a] */

/* Macro operation name: F32_S16PTR_IP2D */
/** This operation performs interpolation for the given 2D interpolation map of type Sint16 and pointers to structure variable for x and y axes of type FDPS_RESULT and returns the interpolated value of type Float32.

This operation has the return type different from the map type.

@param map Pointer to 2D map of type Sint16.
@param dpsx Pointer to structure of type FDPS_RESULT for x axis.
@param dpsy Pointer to structure of type FDPS_RESULT for y axis. */
/* ## Macro operation start [edc062db-45e0-4e2d-85dc-cefba01fc75e] */
#define F32_S16PTR_IP2D(map, dpsx, dpsy)  function_f32_s16ptr_ip2d((const sint16 *)(const void *)map, dpsx, dpsy)
/* ## Macro operation end [edc062db-45e0-4e2d-85dc-cefba01fc75e] */

/* Macro operation name: F32_PTR_IP3D */
/** This operation performs interpolation for the given 3D interpolation map of type Float32 and pointers to structure variable for x, y and z axes of type FDPS_RESULT and returns the interpolated value of type Float32.

@param map Pointer to 3D map of type Float32.
@param dpsx Pointer to structure of type FDPS_RESULT for x axis.
@param dpsy Pointer to structure of type FDPS_RESULT for y axis.
@param dpsz Pointer to structure of type FDPS_RESULT for z axis. */
/* ## Macro operation start [f1a1198a-30c8-4a9f-97af-c1d414fcc229] */
#define F32_PTR_IP3D(map, dpsx, dpsy, dpsz)  function_f32_ptr_ip3d((const float32 *)(const void *)map, dpsx, dpsy, dpsz)
/* ## Macro operation end [f1a1198a-30c8-4a9f-97af-c1d414fcc229] */

/* Macro operation name: F32_U8PTR_IP3D */
/** This operation performs interpolation for the given 3D interpolation map of type Uint8 and pointers to structure variable for x, y and z axes of type FDPS_RESULT and returns the interpolated value of type float32.

This operation has the return type different from the map type.

@param map Pointer to 3D map of type Uint8.
@param dpsx Pointer to structure of type FDPS_RESULT for x axis.
@param dpsy Pointer to structure of type FDPS_RESULT for y axis.
@param dpsz Pointer to structure of type FDPS_RESULT for z axis. */
/* ## Macro operation start [baf3cab9-584f-40be-b514-c7b96354e71e] */
#define F32_U8PTR_IP3D(map, dpsx, dpsy, dpsz)  function_f32_u8ptr_ip3d((const uint8 *)map, dpsx, dpsy, dpsz)
/* ## Macro operation end [baf3cab9-584f-40be-b514-c7b96354e71e] */

/* Macro operation name: F32_U16PTR_IP3D */
/** This operation performs interpolation for the given 3D interpolation map of type U16 and pointers to structure variable for x, y and z axes of type FDPS_RESULT and returns the interpolated value of type F32.

This operation has the return type different from the map type.

@param map Pointer to 3D map of type Uint16.
@param dpsx Pointer to structure of type FDPS_RESULT for x axis.
@param dpsy Pointer to structure of type FDPS_RESULT for y axis.
@param dpsz Pointer to structure of type FDPS_RESULT for z axis. */
/* ## Macro operation start [f1c923e3-0a4b-4c1b-abe1-d151e1e269b4] */
#define F32_U16PTR_IP3D(map, dpsx, dpsy, dpsz)  function_f32_u16ptr_ip3d((const uint16 *)(const void *)map, dpsx, dpsy, dpsz)
/* ## Macro operation end [f1c923e3-0a4b-4c1b-abe1-d151e1e269b4] */

/* Macro operation name: F32_S8PTR_IP3D */
/** This operation performs interpolation for the given 3D interpolation map of type Sint8 and pointers to structure variable for x, y and z axes of type FDPS_RESULT and returns the interpolated value of type float32.

This operation has the return type different from the map type.

@param map Pointer to 3D map of type Sint8.
@param dpsx Pointer to structure of type FDPS_RESULT for x axis.
@param dpsy Pointer to structure of type FDPS_RESULT for y axis.
@param dpsz Pointer to structure of type FDPS_RESULT for z axis. */
/* ## Macro operation start [5ca9a19a-e380-4d47-ac25-69c3aad4ba3b] */
#define F32_S8PTR_IP3D(map, dpsx, dpsy, dpsz)  function_f32_s8ptr_ip3d((const sint8 *)(const void *)map, dpsx, dpsy, dpsz)
/* ## Macro operation end [5ca9a19a-e380-4d47-ac25-69c3aad4ba3b] */

/* Macro operation name: F32_S16PTR_IP3D */
/** This operation performs interpolation for the given 3D interpolation map of type Sint16 and pointers to structure variable for x, y and z axes of type FDPS_RESULT and returns the interpolated value of type float32.

This operation has the return type different from the map type.

@param map Pointer to 3D map of type Sint16.
@param dpsx Pointer to structure of type FDPS_RESULT for x axis.
@param dpsy Pointer to structure of type FDPS_RESULT for y axis.
@param dpsz Pointer to structure of type FDPS_RESULT for z axis. */
/* ## Macro operation start [e21d05fd-6a97-4cea-9bfa-673f4d2e05fd] */
#define F32_S16PTR_IP3D(map, dpsx, dpsy, dpsz)  function_f32_s16ptr_ip3d((const sint16 *)(const void *)map, dpsx, dpsy, dpsz)
/* ## Macro operation end [e21d05fd-6a97-4cea-9bfa-673f4d2e05fd] */

/* Macro operation name: U8_FIDX_PTR_F32 */
/** This operation performs table index determination for the given data point array of type F32 and data point value of type F32 and returns table index of type U8.

@param data_point_array Pointer to the data point array of type F32.
@param parameter Value of the data as F32. */
/* ## Macro operation start [c7b4fe69-2291-4b83-a9ef-3bb7d8ae6016] */
#define U8_FIDX_PTR_F32(data_point_array, parameter)  function_u8_fidx_ptr_f32(data_point_array, parameter)
/* ## Macro operation end [c7b4fe69-2291-4b83-a9ef-3bb7d8ae6016] */

/* Macro operation name: FDPS_PTR_F32 */
/** This operation performs the data point search for the given data point array and data point value of type F32 and stores the result in a pointer variable of type FDPS_RESULT.

@param data_point_array Pointer to the data point array of type F32.
@param parameter Value of the data point array as F32.
@param dps Pointer to structure of type FDPS_RESULT. */
/* ## Macro operation start [b114cd41-3168-4b72-b663-12d5d293f75a] */
#define FDPS_PTR_F32(data_point_array, parameter, dps)  function_fdps_ptr_f32(data_point_array, parameter, dps)
/* ## Macro operation end [b114cd41-3168-4b72-b663-12d5d293f75a] */

/* Macro operation name: FDPS_PTR_U16 */
/** This operation performs the data point search for the given data point array and data point value of type U16 and stores the result in a pointer variable of type FDPS_RESULT.

@param data_point_array Pointer to the data point array of type U16.
@param parameter Value of the data point array as U16.
@param dps Pointer to structure of type FDPS_RESULT. */
/* ## Macro operation start [8ab00287-0c00-4d7b-8f1a-929cd97be514] */
#define FDPS_PTR_U16(data_point_array, parameter, dps)  function_fdps_ptr_u16(data_point_array, parameter, dps)
/* ## Macro operation end [8ab00287-0c00-4d7b-8f1a-929cd97be514] */

/* Macro operation name: FDPS_PTR_U8 */
/** This operation performs the data point search for the given data point array and data point value of type U8 and stores the result in a pointer variable of type FDPS_RESULT.

@param data_point_array Pointer to the data point array of type U8.
@param parameter Value of the data point array as U8.
@param dps Pointer to structure of type FDPS_RESULT. */
/* ## Macro operation start [5be3bfb5-4489-473a-9464-a7ce31b570bc] */
#define FDPS_PTR_U8(data_point_array, parameter, dps)  function_fdps_ptr_u8(data_point_array, parameter, dps)
/* ## Macro operation end [5be3bfb5-4489-473a-9464-a7ce31b570bc] */

/* Macro operation name: FDPS_PTR_S8 */
/** This operation performs the data point search for the given data point array and data point value of type S8 and stores the result in a pointer variable of type FDPS_RESULT.

@param data_point_array Pointer to the data point array of type S8.
@param parameter Value of the data point array as S8.
@param dps Pointer to structure of type FDPS_RESULT. */
/* ## Macro operation start [a0a41073-cb83-4f09-9dcc-e22683f03957] */
#define FDPS_PTR_S8(data_point_array, parameter, dps)  function_fdps_ptr_s8(data_point_array, parameter, dps)
/* ## Macro operation end [a0a41073-cb83-4f09-9dcc-e22683f03957] */

/* Macro operation name: FDPS_PTR_S16 */
/** This operation performs the data point search for the given data point array and data point value of type S16 and stores the result in a pointer variable of type FDPS_RESULT.

@param data_point_array Pointer to the data point array of type S16.
@param parameter Value of the data point array as S16.
@param dps Pointer to structure of type FDPS_RESULT. */
/* ## Macro operation start [dac0b905-dd44-4563-bdc0-425338245899] */
#define FDPS_PTR_S16(data_point_array, parameter, dps)  function_fdps_ptr_s16(data_point_array, parameter, dps)
/* ## Macro operation end [dac0b905-dd44-4563-bdc0-425338245899] */

/*~E*/
/*~A*/
/*~+:Private and Public Operations*/
/** This operation shall performs the data point search operation.
 The input parameters need to be provided are,
 	- Pointer to data point array
 	- Data point value
 	- Pointer to structure FDPS_RESULT

@param data_point_array : constant float32 Pointer to the data point array
@param parameter : float32  Value of the data point array
@param dps : Pointer to structure FDPS_RESULT */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern void function_fdps_ptr_f32(const float32 * data_point_array, float32 parameter, FDPS_RESULT * dps);


/** This operation shall performs the data point search operation for uint16.
 The input parameters need to be provided are,
 	- Pointer to data point array
 	- Data point value
 	- Pointer to structure FDPS_RESULT

@param data_point_array : constant uint16 Pointer to the data point array
@param parameter : Value of the data point array: uint16
@param dps : Pointer to structure FDPS_RESULT. */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern void function_fdps_ptr_u16(const uint16 * data_point_array, uint16 parameter, FDPS_RESULT * dps);


/** This operation shall performs the data point search operation for uint8.
 The input parameters need to be provided are,
 	- Pointer to data point array
 	- Data point value
 	- Pointer to structure FDPS_RESULT

@param data_point_array : constant uint8 Pointer to the data point array
@param parameter : Value of the data point array : uint8
@param dps : Pointer to structure FDPS_RESULT. */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern void function_fdps_ptr_u8(const uint8 * data_point_array, uint8 parameter, FDPS_RESULT * dps);


/** This operation shall performs the data point search operation for sint8.
 The input parameters need to be provided are,
 	- Pointer to data point array
 	- Data point value
 	- Pointer to structure FDPS_RESULT

@param data_point_array : constant s8 Pointer to the data point array
@param parameter : sint8 Value of the data point array
@param dps : Pointer to structure FDPS_RESULT. */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern void function_fdps_ptr_s8(const sint8 * data_point_array, sint8 parameter, FDPS_RESULT * dps);


/** This operation shall performs the data point search operation for sint16.
 The input parameters need to be provided are,
 	- Pointer to data point array
 	- Data point value
 	- Pointer to structure FDPS_RESULT

@param data_point_array : constant sint16 Pointer to the data point array
@param parameter : sint16 Value of the data point array
@param dps : Pointer to structure FDPS_RESULT. */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern void function_fdps_ptr_s16(const sint16 * data_point_array, sint16 parameter, FDPS_RESULT * dps);


/** This operation shall determines the table index.
 The input parameters need to be provided are,
 	- Pointer data point array
 	- Data point value

@param data_point_array : constant float32 Pointer to the data point array
@param parameter : float32 Value of the data point array
@return Returns uint8 value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint8 function_u8_fidx_ptr_f32(const float32 * data_point_array, float32 parameter);


/** This operation shall performs the 1D interpolation operation.
 The input parameters need to be provided are,
 	- Pointer to map
 	- Pointer to structure FDPS_RESULT for x axis

@param map : constant float32 Pointer to 1D map
@param dpsx Pointer to structure FDPS_RESULT for x axis
@return Returns float32 value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern float32 function_f32_ptr_ip1d(const float32 * map, const FDPS_RESULT * dpsx);


/** This operation shall performs the 1D interpolation operation for uint8.
 The input parameters need to be provided are,
 	- Pointer to map
 	- Pointer to structure FDPS_RESULT for x axis

@param map :constant uint8 Pointer to 1D map
@param dpsx : Pointer to structure FDPS_RESULT for x axis
@return Returns float32 value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern float32 function_f32_u8ptr_ip1d(const uint8 * map, const FDPS_RESULT * dpsx);


/** This operation shall performs the 1D interpolation operation for uint16.
 The input parameters need to be provided are,
 	- Pointer to map
 	- Pointer to structure FDPS_RESULT for x axis

@param map :constant uint16 Pointer to 1D map
@param dpsx : Pointer to structure FDPS_RESULT for x axis
@return Returns float32 value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern float32 function_f32_u16ptr_ip1d(const uint16 * map, const FDPS_RESULT * dpsx);


/** This operation shall performs the 1D interpolation operation for sint8.
 The input parameters need to be provided are,
 	- Pointer to map
 	- Pointer to structure FDPS_RESULT for x axis

@param map :constant sint8 Pointer to 1D map
@param dpsx : Pointer to structure FDPS_RESULT for x axis
@return Returns float32 value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern float32 function_f32_s8ptr_ip1d(const sint8 * map, const FDPS_RESULT * dpsx);


/** This operation shall performs the 1D interpolation operation for sint16.
 The input parameters need to be provided are,
 	- Pointer to map
 	- Pointer to structure FDPS_RESULT for x axis

@param map :constant sint16 Pointer to 1D map
@param dpsx : Pointer to structure FDPS_RESULT for x axis
@return Returns float32 value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern float32 function_f32_s16ptr_ip1d(const sint16 * map, const FDPS_RESULT * dpsx);


/** This operation shall performs the 2D interpolation operation.
 The input parameters need to be provided are,
 	- Pointer to map
 	- Pointer to structure FDPS_RESULT for x axis
	- Pointer to structure FDPS_RESULT for y axis

@param map : constant float32 Pointer to 2D map
@param dpsx Pointer to structure FDPS_RESULT for x axis
@param dpsy Pointer to structure FDPS_RESULT for y axis
@return Returns float32 value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern float32 function_f32_ptr_ip2d(const float32 * map, const FDPS_RESULT * dpsx, const FDPS_RESULT * dpsy);


/** This operation shall performs the 2D interpolation operation for uint8.
 The input parameters need to be provided are,
 	- Pointer to map
 	- Pointer to structure FDPS_RESULT for x axis
	- Pointer to structure FDPS_RESULT for y axis

@param map constant uint8 Pointer to 2D map
@param dpsx : Pointer to structure FDPS_RESULT for x axis
@param dpsy : Pointer to structure FDPS_RESULT for y axis
@return Returns float32 value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern float32 function_f32_u8ptr_ip2d(const uint8 * map, const FDPS_RESULT * dpsx, const FDPS_RESULT * dpsy);


/** This operation shall performs the 2D interpolation operation for uint16.
 The input parameters need to be provided are,
 	- Pointer to map
 	- Pointer to structure FDPS_RESULT for x axis
	- Pointer to structure FDPS_RESULT for y axis

@param map : constant uint16 Pointer to 2D map
@param dpsx : Pointer to structure FDPS_RESULT for x axis
@param dpsy : Pointer to structure FDPS_RESULT for y axis
@return Returns float32 value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern float32 function_f32_u16ptr_ip2d(const uint16 * map, const FDPS_RESULT * dpsx, const FDPS_RESULT * dpsy);


/** This operation shall performs the 2D interpolation operation for sint8.
 The input parameters need to be provided are,
 	- Pointer to map
 	- Pointer to structure FDPS_RESULT for x axis
	- Pointer to structure FDPS_RESULT for y axis

@param map : constant sint8 Pointer to 2D map
@param dpsx : Pointer to structure FDPS_RESULT for x axis
@param dpsy : Pointer to structure FDPS_RESULT for y axis
@return Returns float32 value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern float32 function_f32_s8ptr_ip2d(const sint8 * map, const FDPS_RESULT * dpsx, const FDPS_RESULT * dpsy);


/** This operation shall performs the 2D interpolation operation for sint16.
 The input parameters need to be provided are,
    - Pointer to map
    - Pointer to structure FDPS_RESULT for x axis
    - Pointer to structure FDPS_RESULT for y axis

@param map : constant sint16 Pointer to 2D map
@param dpsx : Pointer to structure FDPS_RESULT for x axis
@param dpsy : Pointer to structure FDPS_RESULT for y axis
@return Returns float32 value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern float32 function_f32_s16ptr_ip2d(const sint16 * map, const FDPS_RESULT * dpsx, const FDPS_RESULT * dpsy);


/** This operation shall performs the 3D interpolation operation.
 The input parameters need to be provided are,
 	- Pointer to map
 	- Pointer to structure FDPS_RESULT for x axis
	- Pointer to structure FDPS_RESULT for y axis
	- Pointer to structure FDPS_RESULT for z axis

@param map : constant float32 Pointer to 3D map
@param dpsx : Pointer to structure FDPS_RESULT for x axis
@param dpsy : Pointer to structure FDPS_RESULT for y axis
@param dpsz : Pointer to structure FDPS_RESULT for z axis
@return Returns float32 value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern float32 function_f32_ptr_ip3d(const float32 * map, const FDPS_RESULT * dpsx, const FDPS_RESULT * dpsy, const FDPS_RESULT * dpsz);


/** This operation shall performs the 3D interpolation operation for uint8.
 The input parameters need to be provided are,
 	- Pointer to map
 	- Pointer to structure FDPS_RESULT for x axis
	- Pointer to structure FDPS_RESULT for y axis
	- Pointer to structure FDPS_RESULT for z axis

@param map : constant uint8 Pointer to 3D map
@param dpsx : Pointer to structure FDPS_RESULT for x axis
@param dpsy : Pointer to structure FDPS_RESULT for y axis
@param dpsz : Pointer to structure FDPS_RESULT for z axis
@return Returns float32 value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern float32 function_f32_u8ptr_ip3d(const uint8 * map, const FDPS_RESULT * dpsx, const FDPS_RESULT * dpsy, const FDPS_RESULT * dpsz);


/** This operation shall performs the 3D interpolation operation for uint16.
 The input parameters need to be provided are,
 	- Pointer to map
 	- Pointer to structure FDPS_RESULT for x axis
	- Pointer to structure FDPS_RESULT for y axis
	- Pointer to structure FDPS_RESULT for z axis

@param map : constant uint16 Pointer to 3D map
@param dpsx :Pointer to structure FDPS_RESULT for x axis
@param dpsy :Pointer to structure FDPS_RESULT for y axis
@param dpsz :Pointer to structure FDPS_RESULT for z axis
@return Returns float32 value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern float32 function_f32_u16ptr_ip3d(const uint16 * map, const FDPS_RESULT * dpsx, const FDPS_RESULT * dpsy, const FDPS_RESULT * dpsz);


/** This operation shall performs the 3D interpolation operation for sint8.
 The input parameters need to be provided are,
 	- Pointer to map
 	- Pointer to structure FDPS_RESULT for x axis
	- Pointer to structure FDPS_RESULT for y axis
	- Pointer to structure FDPS_RESULT for z axis

@param map : constant sint8 Pointer to 3D map
@param dpsx : Pointer to structure FDPS_RESULT for x axis
@param dpsy : Pointer to structure FDPS_RESULT for y axis
@param dpsz : Pointer to structure FDPS_RESULT for z axis
@return Returns float32 value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern float32 function_f32_s8ptr_ip3d(const sint8 * map, const FDPS_RESULT * dpsx, const FDPS_RESULT * dpsy, const FDPS_RESULT * dpsz);


/** This operation shall performs the 3D interpolation operation for sint16.
 The input parameters need to be provided are,
 	- Pointer to map
 	- Pointer to structure FDPS_RESULT for x axis
	- Pointer to structure FDPS_RESULT for y axis
	- Pointer to structure FDPS_RESULT for z axis

@param map : constant sint16 Pointer to 3D map
@param dpsx : Pointer to structure FDPS_RESULT for x axis
@param dpsy : Pointer to structure FDPS_RESULT for y axis
@param dpsz : Pointer to structure FDPS_RESULT for z axis
@return Returns float32 value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern float32 function_f32_s16ptr_ip3d(const sint16 * map, const FDPS_RESULT * dpsx, const FDPS_RESULT * dpsy, const FDPS_RESULT * dpsz);


/*~E*/
#include "iopt_memmap.h"
#endif
