/*~A*/
/*~+:VM Header*/
/* UML source model state: Draft */
/* ## Module Header Start [085487c7-037e-4d54-bcb5-1a6e6c1f7f5a] */
/****************************************************************************

COPYRIGHT (C) $Date: 2019/07/03 13:45:18CEST $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.                                                 
                                                                           
The reproduction, transmission or use of this document or its contents is  
not permitted without express written authority.                           
Offenders will be liable for damages. All rights, including rights created 
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------

$Log: Calm.h  $
Revision 1.4 2019/07/03 13:45:18CEST Nastasa, Elena (uidt4846) 
Update SDA Library files
Revision 1.2 2019/04/10 07:45:51CEST Karmann Andreas-Johannes (uidk6640) (uidk6640) 
RO-9740446:1:AnKa: preload libraries: solved issues in preloading libraries
Revision 1.1 2018/07/24 16:49:48CEST Ammermueller Martin (uidv5342) (uidv5342) 
Initial revision
Member added to project /ES/1T/0C/SDA/SDA_Source/SDA_Toolboxes/ACG/Libraries/calm/Src/3_1_0/project.pj
Revision 1.2 2018/03/06 07:53:47CET Angadi Hampa (uidu8151) (uidu8151) 
RO : 8197494 : MISRA2012 ANSI VERSIONS
Revision 1.10 2018/01/29 02:55:00CET Angadi Hampa (uidu8151) (uidu8151) 
For TC39xb validation & New LINT correction (9029)
Revision 1.9 2017/11/22 11:40:16CET Angadi Hampa (uidu8151) (uidu8151) 
TC38X validation for all libraries.
Revision 1.8 2015/11/20 03:30:13CET Ganesh Sumangala (uidu8725) (uidu8725) 
RO : 2806846 : Merging - reveiw updates
Revision 1.7 2015/11/19 05:43:24CET Ganesh Sumangala (uidu8725) (uidu8725) 
RO:2806846: EMS2-EMS3 Merging
reveiw updates
Revision 1.4 2015/06/01 04:56:08CEST Angadi Hampa (uidu8151) (uidu8151) 
RO:2806846;FS_0G01_TC2XX_CALM-3.0.0; Lint correction
Revision 1.3 2014/09/19 05:37:12CEST uidu8151 
Ro: 1081869 : FS_0G01_TC2XX_CALM_200: Review comments update
Revision 1.2 2013/08/22 05:09:30CEST Angadi Hampa (uidu8151) (uidu8151) 
for release RO_429651 :FS_0G01_TC2XX_CALM_100
Revision 1.1 2013/08/09 14:57:30IST Angadi Hampa (uidu8151) (uidu8151) 
Initial revision
Member added to project /ES/FS/0D/bsw/stdlib/tc2xx/calm/calm/if/i/project.pj
Revision 1.1 2013/04/04 10:46:52CEST Grabow Marcus (uid08755) (uid08755) 
Initial revision
Member added to project /ES/FS/1T/03/UML_Development/DevelopmentSpace/Appl_Uml_ToolBox/Exporters/Uml_Exporter_C/Data/project.pj
Revision 1.1 2013/03/20 08:07:52CET Grabow Marcus (uid08755) (uid08755) 
Initial revision
Member added to project /ES/FS/1T/03/UML_Development/DevelopmentSpace/Appl_Uml_ToolBox/Exporters/Uml_Exporter_C/Core/Data/project.pj
Revision 1.3 2012/01/17 10:50:32CET Grabow Marcus (uid08755) (uid08755) 
-
Revision 1.2 2011/03/10 12:17:55CET Grabow Marcus (uid08755) (uid08755) 
-

****************************************************************************/
/* ## Module Header End [085487c7-037e-4d54-bcb5-1a6e6c1f7f5a] */

/*~E*/
/*~A*/
/*~+:SW module (UML class) description*/
/* The CALM component supports a generic interface for fixed point interpolations and table access including data point search in a microcontroller independent way. */
/*~E*/
#ifndef CALM_H
#define CALM_H
/*~A*/
/*~+:Includes*/
#include <Std_Types.h>
#include <powersar_addon_types.h>
#include <calm_shared.h>
#include <calm_private.h>
/*~E*/
/*~A*/
/*~+:TypeDefs*/

/*~E*/
/*~A*/
/*~+:Macro Operations*/
/* Macro operation name: UDPS_U8 */
/** This operation shall perform data point search for uint8 data point array and sets the interpolation length, index and factor inside DPS_RESULT

@param dp_ptr pointer to data point array
@param val data point value to be searched.

Range:	         00(H) ... FF(H)
	           0 ....... 255
@param dps pointer to a variable of type DPS_RESULT */
/* ## Macro operation start [5d6e39e5-13e1-4c7d-924c-5357fb11f4d7] */
#define UDPS_U8(dp_ptr, val, dps)  function_udps_u8(dp_ptr, val, dps)
/* ## Macro operation end [5d6e39e5-13e1-4c7d-924c-5357fb11f4d7] */

/* Macro operation name: UDPS_U16 */
/** This operation shall perform data point search for uint16 data point array and sets the interpolation length, index and factor inside DPS_RESULT

@param dp_ptr pointer to data point array
@param val data point value to be searched.

Range:	       0000(H) ... FFFF(H)
	           0 ....... 65535
@param dps pointer to a variable of type DPS_RESULT */
/* ## Macro operation start [fd92573f-253f-4ae4-932d-75aa4925496b] */
#define UDPS_U16(dp_ptr, val, dps)  function_udps_u16(dp_ptr, val, dps)
/* ## Macro operation end [fd92573f-253f-4ae4-932d-75aa4925496b] */

/* Macro operation name: UDPS_U32 */
/** This operation shall perform data point search for uint32 data point array and sets the interpolation length, index and factor inside DPS_RESULT

@param dp_ptr pointer to data point array
@param val data point value to be searched.

Range:	      00000000(H) ... FFFFFFFF(H)
  	                     0 ....... 4294967295
@param dps pointer to a variable of type DPS_RESULT */
/* ## Macro operation start [5d37babd-41ce-4ff7-ad93-b4a834cd31d8] */
#define UDPS_U32(dp_ptr, val, dps)  function_udps_u32(dp_ptr, val, dps)
/* ## Macro operation end [5d37babd-41ce-4ff7-ad93-b4a834cd31d8] */

/* Macro operation name: SDPS_S8 */
/** This operation shall perform data point search for sint8 data point array and sets the interpolation length, index and factor inside DPS_RESULT

@param dp_ptr pointer to data point array
@param val data point value to be searched.

Range:	         80(H) ... 7F(H)
	         -128 ..... 127
@param dps pointer to a variable of type DPS_RESULT */
/* ## Macro operation start [d93a8cf5-612b-4953-b3e4-5f5ff7e0a5b0] */
#define SDPS_S8(dp_ptr, val, dps)  function_sdps_s8(dp_ptr, val, dps)
/* ## Macro operation end [d93a8cf5-612b-4953-b3e4-5f5ff7e0a5b0] */

/* Macro operation name: SDPS_S16 */
/** This operation shall perform data point search for sint16 data point array and sets the interpolation length, index and factor inside DPS_RESULT

@param dp_ptr pointer to data point array
@param val data point value to be searched.

Range:	      8000(H) ... 7FFF(H)
                   -32768 ..... 32767
@param dps pointer to a variable of type DPS_RESULT */
/* ## Macro operation start [78e4179b-fd0a-4235-9d6e-e07300213435] */
#define SDPS_S16(dp_ptr, val, dps)  function_sdps_s16(dp_ptr, val, dps)
/* ## Macro operation end [78e4179b-fd0a-4235-9d6e-e07300213435] */

/* Macro operation name: SDPS_S32 */
/** This operation shall perform data point search for sint32 data point array and sets the interpolation length, index and factor inside DPS_RESULT

@param dp_ptr pointer to data point array
@param val data point value to be searched.

Range:	         80000000(H) ... 7FFFFFFF(H)
	        -2147483648 ..... 2147483647
@param dps pointer to a variable of type DPS_RESULT */
/* ## Macro operation start [e6bdb6e6-8bb0-44ad-b4ea-1e5d9839b7f7] */
#define SDPS_S32(dp_ptr, val, dps)  function_sdps_s32(dp_ptr, val, dps)
/* ## Macro operation end [e6bdb6e6-8bb0-44ad-b4ea-1e5d9839b7f7] */

/* Macro operation name: U8_CALM_GET_LENGTH */
/** This operation shall return the interpolation length of the axis from DPS_RESULT.

@param dps Pointer to variable of type DPS_RESULT from which length has to be returned. */
/* ## Macro operation start [9b711620-eb5e-4bf4-a77b-91f61770694f] */
#define U8_CALM_GET_LENGTH(dps)  ((dps)->line_count)
/* ## Macro operation end [9b711620-eb5e-4bf4-a77b-91f61770694f] */

/* Macro operation name: U8_CALM_GET_INDEX */
/** This operation shall return the interpolation Index of the axis from DPS_RESULT.

@param dps Pointer to variable of type DPS_RESULT from which Index has to be returned. */
/* ## Macro operation start [0f6e4c96-1fdf-4cee-9629-65ab098cbb34] */
#define U8_CALM_GET_INDEX(dps)  ((dps)->line_index)
/* ## Macro operation end [0f6e4c96-1fdf-4cee-9629-65ab098cbb34] */

/* Macro operation name: U16_CALM_GET_FACTOR */
/** This operation shall return the interpolation factor of the axis from DPS_RESULT.

@param dps Pointer to variable of type DPS_RESULT from which factor has to be returned. */
/* ## Macro operation start [dd0f53cb-abd5-4579-a773-dfe942d0cf50] */
#define U16_CALM_GET_FACTOR(dps)  ((dps)->line_factor)
/* ## Macro operation end [dd0f53cb-abd5-4579-a773-dfe942d0cf50] */

/* Macro operation name: CALM_SET_LENGTH_U8 */
/** This operation shall set the interpolation length of the axis inside DPS_RESULT.

@param dps Pointer to variable of type DPS_RESULT in which length has to be set.
@param length Interpolation length that needs to be set in side DPS_RESULT
Range:      00(H)....FF(H)
          0........255 */
/* ## Macro operation start [c701efc6-2cd6-4454-a9b2-6456c972180a] */
#define CALM_SET_LENGTH_U8(dps, length)  ((dps)->line_count = (uint8)(length) )
/* ## Macro operation end [c701efc6-2cd6-4454-a9b2-6456c972180a] */

/* Macro operation name: CALM_SET_INDEX_U8 */
/** This operation shall set the interpolation Index of the axis inside DPS_RESULT.

@param dps Pointer to variable of type DPS_RESULT in which index has to be set.
@param idx Interpolation index that needs to be set in side DPS_RESULT

Range:      00(H)....FF(H)
          0.......255 */
/* ## Macro operation start [0ac317ab-09a9-454c-98a9-6d1a1f0e9f97] */
#define CALM_SET_INDEX_U8(dps, idx)  ((dps)->line_index = (uint8)(idx) )
/* ## Macro operation end [0ac317ab-09a9-454c-98a9-6d1a1f0e9f97] */

/* Macro operation name: CALM_SET_FACTOR_U16 */
/** This operation shall set the interpolation factor of the axis inside DPS_RESULT.

@param dps Pointer to variable of type DPS_RESULT in which factor has to be set.
@param fac Interpolation factor that needs to be set in side DPS_RESULT
Range:      00(H)....FFFF(H)
          0........65535 */
/* ## Macro operation start [b647cd1c-10a7-497c-b55a-7f387540b100] */
#define CALM_SET_FACTOR_U16(dps, fac)  ((dps)->line_factor = (uint16)(fac) )
/* ## Macro operation end [b647cd1c-10a7-497c-b55a-7f387540b100] */

/* Macro operation name: DPSX_PTR_U8_U8 */
/** This operation shall perform data point search for uint8 dpsx data point array and sets the interpolation length, index and factor inside X DPS_RESULT

@param map pointer to dpsx data point array
@param val data point value to be searched.

Range:	         00(H) ... FF(H)
	           0 ....... 255 */
/* ## Macro operation start [126cc5ad-5fc7-439d-af9a-c3c833056ff8] */
#define DPSX_PTR_U8_U8(map, val)  UDPS_U8(X_##map, val, &calm_x_dps_result)
/* ## Macro operation end [126cc5ad-5fc7-439d-af9a-c3c833056ff8] */

/* Macro operation name: DPSY_PTR_U8_U8 */
/** This operation shall perform data point search for uint8 dpsy data point array and sets the interpolation length, index and factor inside Y DPS_RESULT

@param map pointer to dpsy data point array
@param val data point value to be searched.

Range:	         00(H) ... FF(H)
	           0 ....... 255 */
/* ## Macro operation start [83fba672-e495-421c-a232-fcea9d494395] */
#define DPSY_PTR_U8_U8(map, val)  UDPS_U8(Y_##map, val, &calm_y_dps_result)
/* ## Macro operation end [83fba672-e495-421c-a232-fcea9d494395] */

/* Macro operation name: DPSX_PTR_U16_U16 */
/** This operation shall perform data point search for uint16 dpsx data point array and sets the interpolation length, index and factor inside X DPS_RESULT

@param map pointer to dpsx data point array
@param val data point value to be searched.

Range:	      0000(H) ... FFFF(H)
               0 ....... 65535 */
/* ## Macro operation start [3bc012d0-dee5-4fda-8818-c902c7a9c913] */
#define DPSX_PTR_U16_U16(map, val)  UDPS_U16(X_##map, val, &calm_x_dps_result)
/* ## Macro operation end [3bc012d0-dee5-4fda-8818-c902c7a9c913] */

/* Macro operation name: DPSY_PTR_U16_U16 */
/** This operation shall perform data point search for uint16 dpsy data point array and sets the interpolation length, index and factor inside Y DPS_RESULT

@param map pointer to dpsx data point array
@param val data point value to be searched.

Range:	      0000(H) ... FFFF(H)
               0 ....... 65535 */
/* ## Macro operation start [89899bf7-b098-486c-a9d6-978010cc02ff] */
#define DPSY_PTR_U16_U16(map, val)  UDPS_U16(Y_##map, val, &calm_y_dps_result)
/* ## Macro operation end [89899bf7-b098-486c-a9d6-978010cc02ff] */

/* Macro operation name: DPSX_PTR_U32_U32 */
/** This operation shall perform data point search for uint32 dpsx data point array and sets the interpolation length, index and factor inside X DPS_RESULT

@param map pointer to dpsx data point array
@param val data point value to be searched.

Range:	      00000000(H) ... FFFFFFFF(H)
                         0 ....... 4294967295 */
/* ## Macro operation start [ace1d4f5-5b13-49b4-9beb-ed557d1a5c51] */
#define DPSX_PTR_U32_U32(map, val)  UDPS_U32(X_##map, val, &calm_x_dps_result)
/* ## Macro operation end [ace1d4f5-5b13-49b4-9beb-ed557d1a5c51] */

/* Macro operation name: DPSY_PTR_U32_U32 */
/** This operation shall perform data point search for uint32 dpsy data point array and sets the interpolation length, index and factor inside Y DPS_RESULT

@param map pointer to dpsx data point array
@param val data point value to be searched.

Range:	      00000000(H) ... FFFFFFFF(H)
                         0 ....... 4294967295 */
/* ## Macro operation start [59eb8888-c299-4b06-adf2-784761605bed] */
#define DPSY_PTR_U32_U32(map, val)  UDPS_U32(Y_##map, val, &calm_y_dps_result)
/* ## Macro operation end [59eb8888-c299-4b06-adf2-784761605bed] */

/* Macro operation name: U8_Y_INV_IP_PTR_U8_U8 */
/** This operation shall perform inverse interpolation of calibration map of type uint8 where x data point array value of type uint8 is given and y data point array value has to be determined.

@param map Pointer to 2D calibration map for which inverse interpolation has to be done
@param x_val X data point array value

Range:		00(H).... FF(H)
		  0........  255
@param z_val map value

Range:		00(H).... FF(H)
		  0........  255
@param idxp pointer pointing to x relative index
@param idyp pointer pointing to y relative index */
/* ## Macro operation start [aedb05ee-7988-4d76-bf7d-b20495444cb7] */
#define U8_Y_INV_IP_PTR_U8_U8(map, x_val, z_val, idxp, idyp)  function_u8_y_inv_ip_ptr_u8_u8(X_##map, Y_##map, (const uint8 *)map, x_val, z_val, idxp, idyp)
/* ## Macro operation end [aedb05ee-7988-4d76-bf7d-b20495444cb7] */

/* Macro operation name: U8_X_INV_IP_PTR_U8_U8 */
/** This operation shall perform inverse interpolation of calibration map of type uint8 where y data point array value is given and x data point array value has to be determined.

@param map Pointer to 2D calibration map for which inverse interpolation has to be done
@param y_val Y data point array value

Range:		00(H).... FF(H)
		  0........  255
@param z_val map value

Range:		00(H).... FF(H)
		  0........  255
@param idxp pointer pointing to x relative index
@param idyp pointer pointing to y relative index */
/* ## Macro operation start [36fdbd3e-7489-43e8-85ee-f1a67e719a34] */
#define U8_X_INV_IP_PTR_U8_U8(map, y_val, z_val, idxp, idyp)  function_u8_x_inv_ip_ptr_u8_u8(X_##map, Y_##map, (const uint8 *)map, y_val, z_val,idxp,idyp)
/* ## Macro operation end [36fdbd3e-7489-43e8-85ee-f1a67e719a34] */

/* Macro operation name: U16_Y_INV_IP_PTR_U16_U16 */
/** This operation shall perform inverse interpolation of calibration map of type uint16 where x data point array value is given and y data point array value has to be determined.

@param map Pointer to 2D calibration map for which inverse interpolation has to be done
@param x_val X data point array value

Range:		0000(H).... FFFF(H)
		    0........  65535
@param z_val map value

Range:		0000(H).... FFFF(H)
		    0........  65535
@param idxp pointer pointing to x relative index
@param idyp pointer pointing to y relative index */
/* ## Macro operation start [36730ae6-1a63-400d-9a3c-2c5a9d8d100d] */
#define U16_Y_INV_IP_PTR_U16_U16(map, x_val, z_val, idxp, idyp)  function_u16_y_inv_ip_ptr_u16_u16(X_##map, Y_##map, (const uint16 *)map, x_val, z_val, idxp, idyp)
/* ## Macro operation end [36730ae6-1a63-400d-9a3c-2c5a9d8d100d] */

/* Macro operation name: U16_X_INV_IP_PTR_U16_U16 */
/** This operation shall perform inverse interpolation of calibration map of type uint16 where y data point array value is given and x data point array value has to be determined.

@param map Pointer to 2D calibration map for which inverse interpolation has to be done
@param y_val Y data point array value

Range:		0000(H).... FFFF(H)
		    0........  65535
@param z_val map value

Range:		0000(H).... FFFF(H)
		    0.........  65535
@param idxp pointer pointing to x relative index
@param idyp pointer pointing to y relative index */
/* ## Macro operation start [47e01685-cbc2-4ec4-9dcd-92a0c05e27d6] */
#define U16_X_INV_IP_PTR_U16_U16(map, y_val, z_val, idxp, idyp)  function_u16_x_inv_ip_ptr_u16_u16(X_##map, Y_##map, (const uint16 *)map, y_val, z_val, idxp,idyp)
/* ## Macro operation end [47e01685-cbc2-4ec4-9dcd-92a0c05e27d6] */

/* Macro operation name: U8_ID1DA_PTR_U8 */
/** This operation shall determine table value for the given 1D table of type uint8 with equidistant data point steps.

@param ptr pointer to 1D calibration table
@param val data point value to be searched

Range:	         00(H)... FF(H)
	           0....... 255 */
/* ## Macro operation start [bfae0baa-7756-4816-9473-a7706675377a] */
#define U8_ID1DA_PTR_U8(ptr, val)  function_u8_id1da_ptr_u8(ptr, step_##ptr, val)
/* ## Macro operation end [bfae0baa-7756-4816-9473-a7706675377a] */

/* Macro operation name: S8_ID1DA_PTR_S8 */
/** This operation shall determine table value for the given 1D table of type sint8 with equidistant data point steps.

@param ptr pointer to 1D calibration table
@param val data point value to be searched

Range:	         00(H)... FF(H)
	           0....... 255 */
/* ## Macro operation start [d5768961-6554-4990-be18-972ecc53d31d] */
#define S8_ID1DA_PTR_S8(ptr, val)  (sint8)function_u8_id1da_ptr_u8((const uint8 *)ptr, step_##ptr, val)
/* ## Macro operation end [d5768961-6554-4990-be18-972ecc53d31d] */

/* Macro operation name: U8_IP1DA_PTR_U8 */
/** This operation shall perform interpolation of calibration curve of type uint8 with equidistant data point steps.

@param map pointer to 1D calibration curve
@param val data point value to be searched 

Range:	         00(H)... FF(H)
	           0....... 255 */
/* ## Macro operation start [339da99f-d98d-4fb2-94b8-62fdbfa05114] */
#define U8_IP1DA_PTR_U8(map, val)  function_u8_ip1da_ptr_u8(map, step_##map, val)
/* ## Macro operation end [339da99f-d98d-4fb2-94b8-62fdbfa05114] */

/* Macro operation name: U8_IP2DA_PTR_U8 */
/** This operation shall perform interpolation of calibration map of type uint8 with equidistant data point steps.

@param map pointer to 2D calibration map
@param val1 data point value to be searched for X data point array

Range:	         00(H)... FF(H)
	           0....... 255
@param val2 data point value to be searched for Y data point array

Range:	         00(H)... FF(H)
	           0....... 255 */
/* ## Macro operation start [50bbf8cc-778e-472f-96b1-8759392e9db4] */
#define U8_IP2DA_PTR_U8(map, val1, val2)  function_u8_ip2da_ptr_u8((const uint8 *)map, step_##map, val1, val2)
/* ## Macro operation end [50bbf8cc-778e-472f-96b1-8759392e9db4] */

/* Macro operation name: U8_ID1D_U8 */
/** This operation shall determine table value for the given 1D table of type uint8 using the index of the axis searched by the search routine

@param ptr Pointer to 1D calibration table
@param dpsx Pointer to a variable of type DPS_RESULT which gives the table index */
/* ## Macro operation start [3a8e573f-d1da-4463-b398-df446940b525] */
#define U8_ID1D_U8(ptr, dpsx)  (uint8)(((const uint8 *)ptr)[(dpsx)->line_index])
/* ## Macro operation end [3a8e573f-d1da-4463-b398-df446940b525] */

/* Macro operation name: U8_ID1D_PTR_U8 */
/** This operation shall determine table value for the given 1D table of type uint8 using the index of the axis searched by the search routine

@param map Pointer to 1D calibration table */
/* ## Macro operation start [1a332d54-79c7-4511-8950-077923b39d5f] */
#define U8_ID1D_PTR_U8(map)  U8_ID1D_U8(map, &calm_x_dps_result)
/* ## Macro operation end [1a332d54-79c7-4511-8950-077923b39d5f] */

/* Macro operation name: U16_ID1D_U16 */
/** This operation shall determine table value for the given 1D table of type uint16 using the index of the axis searched by the search routine

@param ptr Pointer to 1D calibration table
@param dpsx Pointer to a variable of type DPS_RESULT  which gives the table index */
/* ## Macro operation start [b40ef651-aa37-4061-b71c-1e5d31074278] */
#define U16_ID1D_U16(ptr, dpsx)  (uint16)(((const uint16 *)ptr) [(dpsx)->line_index])
/* ## Macro operation end [b40ef651-aa37-4061-b71c-1e5d31074278] */

/* Macro operation name: U16_ID1D_PTR_U16 */
/** This operation shall determine table value for the given 1D table of type uint16 using the index of the axis searched by the search routine

@param map Pointer to 1D calibration table */
/* ## Macro operation start [1681059c-3494-4959-8c6a-35ece6286e09] */
#define U16_ID1D_PTR_U16(map)  U16_ID1D_U16(map, &calm_x_dps_result)
/* ## Macro operation end [1681059c-3494-4959-8c6a-35ece6286e09] */

/* Macro operation name: U8_ID2D_U8 */
/** This operation shall determine the table value for the given 2D table of type uint8 using the length and indices of the axis searched by the search routines

@param ptr Pointer to 2D calibration table
@param dpsx Pointer to a variable of type DPS_RESULT which gives the table index for X axis
@param dpsy Pointer to a variable of type DPS_RESULT which gives the table index for Y axis */
/* ## Macro operation start [5b9b1c0b-1915-4417-8465-61d0658fddfe] */
#define U8_ID2D_U8(ptr, dpsx, dpsy)  function_u8_id2d_u8((const uint8 *)ptr,dpsx,dpsy)
/* ## Macro operation end [5b9b1c0b-1915-4417-8465-61d0658fddfe] */

/* Macro operation name: U16_ID2D_U16 */
/** This operation shall determine table value for the given 2D table of type uint16 using the length and indices of the axis searched by the search routines

@param ptr Pointer to 2D calibration table
@param dpsx Pointer to a variable of type DPS_RESULT which gives the table index for X axis
@param dpsy Pointer to a variable of type DPS_RESULT which gives the table index for Y axis */
/* ## Macro operation start [9e60e574-772d-44d6-83dd-d4bcd185a633] */
#define U16_ID2D_U16(ptr, dpsx, dpsy)  function_u16_id2d_u16((const uint16 *)(const void *)ptr,dpsx,dpsy)
/* ## Macro operation end [9e60e574-772d-44d6-83dd-d4bcd185a633] */

/* Macro operation name: S8_ID1D_S8 */
/** This operation shall determine table value for the given 1D table of type sint8 using the index of the axis searched by the search routine

@param ptr Pointer to 1D calibration table
@param dpsx Pointer to a variable of type DPS_RESULT which gives the table index */
/* ## Macro operation start [58615397-7af1-42cd-90db-790e81a15bbb] */
#define S8_ID1D_S8(ptr, dpsx)  (sint8)(((const sint8 *)ptr)[(dpsx)->line_index])
/* ## Macro operation end [58615397-7af1-42cd-90db-790e81a15bbb] */

/* Macro operation name: S8_ID1D_PTR_S8 */
/** This operation shall determine table value for the given 1D table of type sint8 using the index of the axis searched by the search routine

@param map Pointer to 1D calibration table */
/* ## Macro operation start [7c74961a-231a-4357-a85a-a6e5f8d826af] */
#define S8_ID1D_PTR_S8(map)  S8_ID1D_S8(map, &calm_x_dps_result)
/* ## Macro operation end [7c74961a-231a-4357-a85a-a6e5f8d826af] */

/* Macro operation name: S16_ID1D_S16 */
/** This operation shall determine table value for the given 1D table of type sint16 using the index of the axis searched by the search routine

@param ptr Pointer to 1D calibration table
@param dpsx Pointer to a variable of type DPS_RESULT which gives the table index */
/* ## Macro operation start [f718e758-ca92-4aed-8d7c-6759f85592b0] */
#define S16_ID1D_S16(ptr, dpsx)  (sint16)(((const sint16 *)ptr)[(dpsx)->line_index])
/* ## Macro operation end [f718e758-ca92-4aed-8d7c-6759f85592b0] */
/* Macro operation name: S16_ID1D_PTR_S16 */
/** This operation shall determine table value for the given 1D table of type sint16 using the index of the axis searched by the search routine

@param map Pointer to 1D calibration table */
/* ## Macro operation start [61389e89-969e-44c1-93b1-4cf63cf92091] */
#define S16_ID1D_PTR_S16(map)  S16_ID1D_S16(map, &calm_x_dps_result)
/* ## Macro operation end [61389e89-969e-44c1-93b1-4cf63cf92091] */

/* Macro operation name: S8_ID2D_S8 */
/** This operation shall determine table value for the given 2D table of type sint8 using the length and indices of the axis searched by the search routines

@param ptr Pointer to 2D calibration table
@param dpsx Pointer to a variable of type DPS_RESULT which gives the table index for x axis
@param dpsy Pointer to a variable of type DPS_RESULT which gives the table index for Y axis */
/* ## Macro operation start [b01da460-71cb-4f7d-8fae-105653272b5e] */
#define S8_ID2D_S8(ptr, dpsx, dpsy)  (sint8)function_u8_id2d_u8((const uint8 *)ptr,dpsx, dpsy)
/* ## Macro operation end [b01da460-71cb-4f7d-8fae-105653272b5e] */

/* Macro operation name: S16_ID2D_S16 */
/** This operation shall determine table value for the given 2D table of type sint16 using the length and indices of the axis searched by the search routines

@param ptr Pointer to 2D calibration table
@param dpsx Pointer to a variable of type DPS_RESULT which gives the table index for X axis
@param dpsy Pointer to a variable of type DPS_RESULT which gives the table index for Y axis */
/* ## Macro operation start [70f07fb5-a321-4448-a64c-84fa3ddda230] */
#define S16_ID2D_S16(ptr, dpsx, dpsy)  (sint16)function_u16_id2d_u16((const uint16 *)(const void *)ptr,dpsx, dpsy)
/* ## Macro operation end [70f07fb5-a321-4448-a64c-84fa3ddda230] */

/* Macro operation name: U8_ID2D_PTR_U8 */
/** This operation shall determine table value for the given 2D table of type uint8 using the index of the axis searched by the search routine

@param map Pointer to 2D calibration table */
/* ## Macro operation start [95f97908-e24e-4124-b0f4-2395a3e483be] */
#define U8_ID2D_PTR_U8(map)  U8_ID2D_U8(map, &calm_x_dps_result, &calm_y_dps_result)
/* ## Macro operation end [95f97908-e24e-4124-b0f4-2395a3e483be] */

/* Macro operation name: U16_ID2D_PTR_U16 */
/** This operation shall determine table value for the given 2D table of type uint16 using the index of the axis searched by the search routine

@param map Pointer to 2D calibration table */
/* ## Macro operation start [f4551e1b-de46-4814-8c7b-08cdc3ded5e1] */
#define U16_ID2D_PTR_U16(map)  U16_ID2D_U16(map, &calm_x_dps_result, &calm_y_dps_result)
/* ## Macro operation end [f4551e1b-de46-4814-8c7b-08cdc3ded5e1] */

/* Macro operation name: S8_ID2D_PTR_S8 */
/** This operation shall determine table value for the given 2D table of type sint8 using the index of the axis searched by the search routine

@param map Pointer to 2D calibration table */
/* ## Macro operation start [5fab52a5-7f04-4305-b895-552d127f6bf7] */
#define S8_ID2D_PTR_S8(map)  S8_ID2D_S8(map, &calm_x_dps_result, &calm_y_dps_result)
/* ## Macro operation end [5fab52a5-7f04-4305-b895-552d127f6bf7] */

/* Macro operation name: S16_ID2D_PTR_S16 */
/** This operation shall determine table value for the given 2D table of type sint16 using the index of the axis searched by the search routine

@param map Pointer to 2D calibration table */
/* ## Macro operation start [b0616e92-c331-4edd-8f10-e1d66da90b5f] */
#define S16_ID2D_PTR_S16(map)  S16_ID2D_S16(map, &calm_x_dps_result, &calm_y_dps_result)
/* ## Macro operation end [b0616e92-c331-4edd-8f10-e1d66da90b5f] */

/* Macro operation name: U8_ID_PTR_U8 */
/** This operation shall perform combined data point search and table value determination for 1D calibration curve of type uint8 and data point array of type uint8.

@param ptr Pointer to 1D calibration curve
@param xval Data point value to be searched

Range:	     00(H)... FF(H)
	       0....... 255 */
/* ## Macro operation start [2213ea7a-9fed-4506-8c9e-ff10fd090a62] */
#define U8_ID_PTR_U8(ptr, xval)  function_u8_id_ptr_u8(ptr, X_##ptr, xval) 
/* ## Macro operation end [2213ea7a-9fed-4506-8c9e-ff10fd090a62] */

/* Macro operation name: U8_ID_PTR_U16 */
/** This operation shall perform combined data point search and table value determination for 1D calibration curve of type uint8 and data point array of type uint16

@param ptr Pointer to 1D calibration curve
@param xval Data point value to be searched

Range:	     0000(H)... FFFF(H)
	          0........ 65535 */
/* ## Macro operation start [bf2e895c-6cf9-49b3-8369-8cf36317b876] */
#define U8_ID_PTR_U16(ptr, xval)  function_u8_id_ptr_u16(ptr, X_##ptr, xval) 
/* ## Macro operation end [bf2e895c-6cf9-49b3-8369-8cf36317b876] */

/* Macro operation name: U16_ID_PTR_U8 */
/** This operation shall perform combined data point search and table value determination for 1D calibration curve of type uint16 and data point array of type uint8

@param ptr Pointer to 1D calibration curve
@param xval Data point value to be searched

Range:	     00(H)... FF(H)
	       0....... 255 */
/* ## Macro operation start [1c717725-5925-48ec-ae87-97c5dbb9bcf5] */
#define U16_ID_PTR_U8(ptr, xval)  function_u16_id_ptr_u8(ptr, X_##ptr, xval) 
/* ## Macro operation end [1c717725-5925-48ec-ae87-97c5dbb9bcf5] */

/* Macro operation name: U16_ID_PTR_U16 */
/** This operation shall perform combined data point search and table value determination for 1D calibration curve of type uint16 and data point array of type uint16.

@param ptr Pointer to 1D calibration curve
@param xval Data point value to be searched

Range:	     0000(H)... FFFF(H)
	           0....... 65535 */
/* ## Macro operation start [1e4749d1-3c0d-4461-9edd-46c8a9ac853c] */
#define U16_ID_PTR_U16(ptr, xval)  function_u16_id_ptr_u16(ptr, X_##ptr, xval) 
/* ## Macro operation end [1e4749d1-3c0d-4461-9edd-46c8a9ac853c] */

/* Macro operation name: U8_ID_PTR_U8_U8 */
/** This operation shall perform combined data point search and table value determination for 2D calibration map of type uint8 with X data point array of type uint8 and Y data point array of type uint8

@param ptr Pointer to 2D Calibration map
@param xval X Data point value to be searched

Range:	     00(H)... FF(H)
	       0....... 255
@param yval Y Data point value to be searched

Range:	     00(H)... FF(H)
	       0....... 255 */
/* ## Macro operation start [667c5079-a720-437a-851e-febe7fc2f48c] */
#define U8_ID_PTR_U8_U8(ptr, xval, yval)  function_u8_id_ptr_u8_u8((const uint8 *)ptr,X_##ptr,Y_##ptr, xval, yval) 
/* ## Macro operation end [667c5079-a720-437a-851e-febe7fc2f48c] */

/* Macro operation name: U8_ID_PTR_U8_U16 */
/** This operation shall perform combined data point search and table value determination for 2D calibration map of type uint8 with X data point array of type uint8 and Y data point array of type uint16

@param ptr Pointer to 2D calibration map
@param xval X Data point value to be searched

Range:	     00(H)... FF(H)
	       0....... 255
@param yval Y Data point value to be searched

Range:	        0000(H)... FFFF(H)
	              0....... 65535 */
/* ## Macro operation start [757840a0-18d1-436b-a0e7-2a6532e525ed] */
#define U8_ID_PTR_U8_U16(ptr, xval, yval)  function_u8_id_ptr_u8_u16((const uint8 *)ptr, X_##ptr, Y_##ptr, xval, yval) 
/* ## Macro operation end [757840a0-18d1-436b-a0e7-2a6532e525ed] */

/* Macro operation name: U8_ID_PTR_U16_U8 */
/** This operation shall perform combined data point search and table value determination for 2D calibration map of type uint8 with X data point array of type uint16 and Y data point array of type uint8

@param ptr Pointer to 2D calibration map
@param xval X Data point value to be searched

Range:	        0000(H)... FFFF(H)
	              0....... 65535
@param yval Y Data point value to be searched

Range:	        00(H)... FF(H)
	          0....... 255 */
/* ## Macro operation start [ce3f9306-1d4a-4369-b808-3e42f58c5843] */
#define U8_ID_PTR_U16_U8(ptr, xval, yval)  function_u8_id_ptr_u16_u8((const uint8 *)ptr, X_##ptr, Y_##ptr, xval, yval) 
/* ## Macro operation end [ce3f9306-1d4a-4369-b808-3e42f58c5843] */

/* Macro operation name: U8_ID_PTR_U16_U16 */
/** This operation shall perform combined data point search and table value determination for 2D calibration map of type uint8 with X data point array of type uint16 and Y data point array of type uint16

@param ptr Pointer to 2D calibration map
@param xval X Data point value to be searched

Range:	        0000(H)... FFFF(H)
	              0....... 65535
@param yval Y Data point value to be searched

Range:	        0000(H)... FFFF(H)
	              0....... 65535 */
/* ## Macro operation start [b2a3ff50-efa2-45df-b7fe-3af8d03d4c9d] */
#define U8_ID_PTR_U16_U16(ptr, xval, yval)  function_u8_id_ptr_u16_u16((const uint8 *)ptr, X_##ptr, Y_##ptr, xval, yval) 
/* ## Macro operation end [b2a3ff50-efa2-45df-b7fe-3af8d03d4c9d] */

/* Macro operation name: U16_ID_PTR_U8_U8 */
/** This operation shall perform combined data point search and table value determination for 2D calibration map of type uint16 with X data point array of type uint8 and Y data point array of type uint8

@param ptr Pointer to 2D calibration map
@param xval X Data point value to be searched

Range:          00(H)... FF(H)
              0....... 255
@param yval Y Data point value to be searched

Range:          00(H)... FF(H)
              0....... 255 */
/* ## Macro operation start [cc1a25fa-9b9e-4b67-8b33-b26fe2940391] */
#define U16_ID_PTR_U8_U8(ptr, xval, yval)  function_u16_id_ptr_u8_u8((const uint16 *)(const void *)ptr, X_##ptr, Y_##ptr, xval, yval) 
/* ## Macro operation end [cc1a25fa-9b9e-4b67-8b33-b26fe2940391] */

/* Macro operation name: U16_ID_PTR_U8_U16 */
/** This operation shall perform combined data point search and table value determination for 2D calibration map of type uint16 with X data point array of type uint8 and Y data point array of type uint16

@param ptr Pointer to 2D calibration map
@param xval X Data point value to be searched

Range:          00(H)... FF(H)
              0....... 255
@param yval Y Data point value to be searched

Range:         0000(H)... FFFF(H)
                  0....... 65535 */
/* ## Macro operation start [664a4b04-ae91-43ba-8d43-2f89da069af8] */
#define U16_ID_PTR_U8_U16(ptr, xval, yval)  function_u16_id_ptr_u8_u16((const uint16 *)(const void *)ptr, X_##ptr, Y_##ptr, xval, yval) 
/* ## Macro operation end [664a4b04-ae91-43ba-8d43-2f89da069af8] */

/* Macro operation name: U16_ID_PTR_U16_U8 */
/** This operation shall perform combined data point search and table value determination for 2D calibration map of type uint16 with X data point array of type uint16 and Y data point array of type uint8

@param ptr Pointer to 2D calibration map
@param xval X Data point value to be searched

Range:          0000(H)... FFFF(H)
                  0....... 65535
@param yval Y Data point value to be searched

Range:          00(H)... FF(H)
              0....... 255 */
/* ## Macro operation start [36e43d1e-080e-402b-8881-a3903de91cf1] */
#define U16_ID_PTR_U16_U8(ptr, xval, yval)  function_u16_id_ptr_u16_u8((const uint16 *)(const void *)ptr, X_##ptr, Y_##ptr, xval, yval) 
/* ## Macro operation end [36e43d1e-080e-402b-8881-a3903de91cf1] */

/* Macro operation name: U16_ID_PTR_U16_U16 */
/** This operation shall perform combined data point search and table value determination for 2D calibration map of type uint16 with X data point array of type uint16 and Y data point array of type uint16

@param ptr Pointer to 2D calibration map
@param xval X Data point value to be searched

Range:          0000(H)... FFFF(H)
                  0....... 65535
@param yval Y Data point value to be searched

Range:          0000(H)... FFFF(H)
                  0....... 65535 */
/* ## Macro operation start [e5839223-b242-408e-b143-774700d4163b] */
#define U16_ID_PTR_U16_U16(ptr, xval, yval)  function_u16_id_ptr_u16_u16((const uint16 *)(const void *)ptr, X_##ptr, Y_##ptr, xval, yval)
/* ## Macro operation end [e5839223-b242-408e-b143-774700d4163b] */

/* Macro operation name: S8_IDS_PTR_U8 */
/** This operation shall perform combined data point search and table value determination for 1D calibration curve of type sint8 and data point array of type uint8

@param ptr Pointer to 1D calibration curve
@param xval Data point value to be searched

Range:	     00(H)... FF(H)
	       0....... 255 */
/* ## Macro operation start [e60296c7-8e74-4caf-ba3f-a95e84b526eb] */
#define S8_IDS_PTR_U8(ptr, xval)  (sint8)function_u8_id_ptr_u8((const uint8 *)ptr, X_##ptr, xval)
/* ## Macro operation end [e60296c7-8e74-4caf-ba3f-a95e84b526eb] */

/* Macro operation name: S8_IDS_PTR_U16 */
/** This operation shall perform combined data point search and table value determination for 1D calibration curve of type sint8 and data point array of type uint16

@param ptr Pointer to 1D calibration curve
@param xval Data point value to be searched

Range:	     0000(H)... FFFF(H)
	          0........ 65535 */
/* ## Macro operation start [9a8bb0b9-7124-4986-a675-60753b6d87d8] */
#define S8_IDS_PTR_U16(ptr, xval)  (sint8)function_u8_id_ptr_u16((const uint8 *)ptr, X_##ptr, xval) 
/* ## Macro operation end [9a8bb0b9-7124-4986-a675-60753b6d87d8] */

/* Macro operation name: S16_IDS_PTR_U8 */
/** This operation shall perform combined data point search and table value determination for 1D calibration curve of type sint16 and data point array of type uint8

@param ptr Pointer to 1D calibration curve
@param xval Data point value to be searched

Range:	     00(H)... FF(H)
	       0....... 255 */
/* ## Macro operation start [a27b962e-fa49-4d45-a77a-924739122708] */
#define S16_IDS_PTR_U8(ptr, xval)  (sint16)function_u16_id_ptr_u8((const uint16 *)ptr, X_##ptr, xval)
/* ## Macro operation end [a27b962e-fa49-4d45-a77a-924739122708] */

/* Macro operation name: S16_IDS_PTR_U16 */
/** This operation shall perform combined data point search and table value determination for 1D calibration map of type sint16 and data point array of type uint16

@param ptr Pointer to 1D calibration curve
@param xval Data point value to be searched

Range:	     0000(H) ... FFFF(H)
	           0 ....... 65535 */
/* ## Macro operation start [652f0fe2-8e7a-4079-96c9-4fa95bb0d80b] */
#define S16_IDS_PTR_U16(ptr, xval)  (sint16)function_u16_id_ptr_u16((const uint16 *)ptr, X_##ptr, xval)
/* ## Macro operation end [652f0fe2-8e7a-4079-96c9-4fa95bb0d80b] */

/* Macro operation name: S8_IDS_PTR_U8_U8 */
/** This operation shall perform combined data point search and table value determination for 2D calibration map of type sint8 with X data point array of type uint8 and Y data point array of type uint8

@param ptr Pointer to 2D calibration map
@param xval X Data point value to be searched

Range:	     00(H) ... FF(H)
	       0 ....... 255
@param yval Y Data point value to be searched

Range:	     00(H) ... FF(H)
	       0 ....... 255 */
/* ## Macro operation start [ae0461c5-7165-41f0-bb4c-13f888f43aa3] */
#define S8_IDS_PTR_U8_U8(ptr, xval, yval)  (sint8)function_u8_id_ptr_u8_u8((const uint8 *)ptr, X_##ptr, Y_##ptr, xval,yval)
/* ## Macro operation end [ae0461c5-7165-41f0-bb4c-13f888f43aa3] */

/* Macro operation name: S8_IDS_PTR_U8_U16 */
/** This operation shall perform combined data point search and table value determination for 2D calibration map of type sint8 with X data point array of type uint8 and Y data point array of type uint16

@param ptr Pointer to 2D calibration map
@param xval X Data point value to be searched

Range:	     00(H) ... FF(H)
	       0 ....... 255
@param yval Y Data point value to be searched

Range:	     0000(H) ... FFFF(H)
	            0 ....... 65535 */
/* ## Macro operation start [c4ec710c-5371-440f-a40f-751bec0c9f25] */
#define S8_IDS_PTR_U8_U16(ptr, xval, yval)  (sint8)function_u8_id_ptr_u8_u16((const uint8 *)ptr, X_##ptr, Y_##ptr, xval, yval)
/* ## Macro operation end [c4ec710c-5371-440f-a40f-751bec0c9f25] */

/* Macro operation name: S8_IDS_PTR_U16_U8 */
/** This operation shall perform combined data point search and table value determination for 2D calibration map of type sint8 with X data point array of type uint16 and Y data point array of type uint8

@param ptr Pointer to 2D calibration map
@param xval X Data point value to be searched

Range:	     0000(H) ... FFFF(H)
	          0 ........ 65535
@param yval Y Data point value to be searched

Range:	     00(H) ... FF(H)
	       0 ....... 255 */
/* ## Macro operation start [5637e898-f687-4fc4-ac75-ac42a10baceb] */
#define S8_IDS_PTR_U16_U8(ptr, xval, yval)  (sint8)function_u8_id_ptr_u16_u8((const uint8 *)ptr, X_##ptr, Y_##ptr, xval, yval)
/* ## Macro operation end [5637e898-f687-4fc4-ac75-ac42a10baceb] */

/* Macro operation name: S8_IDS_PTR_U16_U16 */
/** This operation shall perform combined data point search and table value determination for 2D calibration map of type sint8 with X data point array of type uint16 and Y data point array of type uint16

@param ptr Pointer to 2D calibration map
@param xval X Data point value to be searched

Range:	     0000(H) ... FFFF(H)
	          0 ........ 65535
@param yval Y Data point value to be searched

Range:	     0000(H) ... FFFF(H)
	          0 ........ 65535 */
/* ## Macro operation start [7ae67820-74c9-4211-ae48-ab1aec7706ac] */
#define S8_IDS_PTR_U16_U16(ptr, xval, yval)  (sint8)function_u8_id_ptr_u16_u16((const uint8 *)ptr, X_##ptr, Y_##ptr, xval, yval)
/* ## Macro operation end [7ae67820-74c9-4211-ae48-ab1aec7706ac] */

/* Macro operation name: S16_IDS_PTR_U8_U8 */
/** This operation shall perform combined data point search and table value determination for 2D calibration map of type sint16 with X data point array of type uint8 and Y data point array of type uint8

@param ptr Pointer to 2D calibration map
@param xval X Data point value to be searched

Range:       00(H) ... FF(H)
           0 ....... 255
@param yval Y Data point value to be searched

Range:       00(H) ... FF(H)
           0 ....... 255 */
/* ## Macro operation start [edb0f6ee-00cc-4897-9710-6d5d8bcaaf72] */
#define S16_IDS_PTR_U8_U8(ptr, xval, yval)  (sint16)function_u16_id_ptr_u8_u8((const uint16 *)(const void *)ptr, X_##ptr, Y_##ptr, xval, yval) 
/* ## Macro operation end [edb0f6ee-00cc-4897-9710-6d5d8bcaaf72] */

/* Macro operation name: S16_IDS_PTR_U8_U16 */
/** This operation shall perform combined data point search and table value determination for 2D calibration map of type sint16 with X data point array of type uint8 and Y data point array of type uint16

@param ptr Pointer to 2D calibration map
@param xval X Data point value to be searched

Range:       00(H) ... FF(H)
           0 ....... 255
@param yval Y Data point value to be searched

Range:       0000(H) ... FFFF(H)
              0 ........ 65535 */
/* ## Macro operation start [34108a71-ec23-4e93-be11-2a8efc947bf0] */
#define S16_IDS_PTR_U8_U16(ptr, xval, yval)  (sint16)function_u16_id_ptr_u8_u16((const uint16 *)(const void *)ptr, X_##ptr, Y_##ptr, xval, yval) 
/* ## Macro operation end [34108a71-ec23-4e93-be11-2a8efc947bf0] */

/* Macro operation name: S16_IDS_PTR_U16_U8 */
/** This operation shall perform combined data point search and table value determination for 2D calibration map of type sint16 with X data point array of type uint16 and Y data point array of type uint8

@param ptr Pointer to 2D calibration map
@param xval X Data point value to be searched

Range:       0000(H) ... FFFF(H)
              0 ........ 65535
@param yval Y Data point value to be searched

Range:       00(H) ... FF(H)
           0 ....... 255 */
/* ## Macro operation start [562c6ab6-8b1a-4b82-ac27-69c9106e1020] */
#define S16_IDS_PTR_U16_U8(ptr, xval, yval)  (sint16)function_u16_id_ptr_u16_u8((const uint16 *)(const void *)ptr, X_##ptr, Y_##ptr, xval, yval) 
/* ## Macro operation end [562c6ab6-8b1a-4b82-ac27-69c9106e1020] */

/* Macro operation name: S16_IDS_PTR_U16_U16 */
/** This operation shall perform combined data point search and table value determination for 2D calibration map of type sint16 with X data point array of type uint16 and Y data point array of type uint16

@param ptr Pointer to 2D calibration map
@param xval X Data point value to be searched

Range:       0000(H) ... FFFF(H)
              0 ........ 65535
@param yval Y Data point value to be searched

Range:       0000(H) ... FFFF(H)
              0 ........ 65535 */
/* ## Macro operation start [b8e64ef6-d259-4930-a76c-7633aed6386c] */
#define S16_IDS_PTR_U16_U16(ptr, xval, yval)  (sint16)function_u16_id_ptr_u16_u16((const uint16 *)(const void *)ptr, X_##ptr, Y_##ptr, xval, yval)
/* ## Macro operation end [b8e64ef6-d259-4930-a76c-7633aed6386c] */

/* Macro operation name: UIDS_U8 */
/** This operation shall determine table index for the given data point value in the given data point array of type uint8

@param dp_ptr Pointer to data point array
@param val Data point value to be searched.

Range: 	         00(H) ... FF(H)
	           0 ....... 255
@param dps pointer to a variable of type DPS_RESULT in which index shall be set */
/* ## Macro operation start [df277452-6294-44b5-be9e-25dc1eb0150a] */
#define UIDS_U8(dp_ptr, val, dps)  function_uids_u8(dp_ptr, val, dps) 
/* ## Macro operation end [df277452-6294-44b5-be9e-25dc1eb0150a] */

/* Macro operation name: UIDS_U16 */
/** This operation shall determine table index for the given data point value in the given data point array of type uint16

@param dp_ptr Pointer to data point array
@param val Data point value to be searched.

Range: 	         0000(H) ... FFFF(H)
	              0 ....... 65535
@param dps pointer to a variable of type DPS_RESULT in which index shall be set */
/* ## Macro operation start [12460701-aa0d-446e-8730-e99c4ffd90a1] */
#define UIDS_U16(dp_ptr, val, dps)  function_uids_u16(dp_ptr, val, dps) 
/* ## Macro operation end [12460701-aa0d-446e-8730-e99c4ffd90a1] */

/* Macro operation name: SIDS_S8 */
/** This operation shall determine table index for the given data point value in the given data point array of type sint8

@param dp_ptr Pointer to data point array
@param val Data point value to be searched.

Range: 	         80(H) ... 7F(H)
	         -128 ..... 127
@param dps pointer to a variable of type DPS_RESULT in which index shall be set */
/* ## Macro operation start [f16b0d7b-98db-473d-8b58-7f63c9001ef1] */
#define SIDS_S8(dp_ptr, val, dps)  function_sids_s8(dp_ptr, val, dps) 
/* ## Macro operation end [f16b0d7b-98db-473d-8b58-7f63c9001ef1] */

/* Macro operation name: SIDS_S16 */
/** This operation shall determine table index for the given data point value in the given data point array of type sint16

@param dp_ptr Pointer to data point array
@param val Data point value to be searched.

Range: 	         8000(H) ... 7FFF(H)
	         -32768 ...... 32767
@param dps pointer to a variable of type DPS_RESULT in which index shall be set */
/* ## Macro operation start [d9ac016d-f9e9-41fe-bcfa-c8b5cc5384bb] */
#define SIDS_S16(dp_ptr, val, dps)  function_sids_s16(dp_ptr, val, dps) 
/* ## Macro operation end [d9ac016d-f9e9-41fe-bcfa-c8b5cc5384bb] */

/* Macro operation name: IDINDX_PTR_U8_U8 */
/** This operation shall determine table index for the given data point value in the given dpsx data point array of type uint8

@param map Pointer to data point array
@param val Data point value to be searched.

Range: 	         00(H) ... FF(H)
	           0 ....... 255 */
/* ## Macro operation start [a06ee21a-cb82-427f-9e14-8ee21bd8fae6] */
#define IDINDX_PTR_U8_U8(map, val)  UIDS_U8(X_##map, val, &calm_x_dps_result)
/* ## Macro operation end [a06ee21a-cb82-427f-9e14-8ee21bd8fae6] */

/* Macro operation name: IDINDY_PTR_U8_U8 */
/** This operation shall determine table index for the given data point value in the given dpsy data point array of type uint8

@param map Pointer to data point array
@param val Data point value to be searched.

Range: 	         00(H) ... FF(H)
	           0 ....... 255 */
/* ## Macro operation start [a8f6038a-0ec7-48a8-b0f0-f6ec88cc2fb3] */
#define IDINDY_PTR_U8_U8(map, val)  UIDS_U8(Y_##map, val, &calm_y_dps_result)
/* ## Macro operation end [a8f6038a-0ec7-48a8-b0f0-f6ec88cc2fb3] */

/* Macro operation name: IDINDX_PTR_U16_U16 */
/** This operation shall determine table index for the given data point value in the given dpsx data point array of type uint16

@param map Pointer to data point array
@param val Data point value to be searched.

Range: 	         0000(H) ... FFFF(H)
	              0 ....... 65535 */
/* ## Macro operation start [13c5ac4a-cc74-48e5-b4ce-633a8ba338de] */
#define IDINDX_PTR_U16_U16(map, val)  UIDS_U16(X_##map, val, &calm_x_dps_result) 
/* ## Macro operation end [13c5ac4a-cc74-48e5-b4ce-633a8ba338de] */

/* Macro operation name: IDINDY_PTR_U16_U16 */
/** This operation shall determine table index for the given data point value in the given dpsy data point array of type uint16

@param map Pointer to data point array
@param val Data point value to be searched.

Range: 	         0000(H) ... FFFF(H)
	              0 ....... 65535 */
/* ## Macro operation start [a2fb2719-cec4-4fac-a37d-761988d436da] */
#define IDINDY_PTR_U16_U16(map, val)  UIDS_U16(Y_##map, val, &calm_y_dps_result)
/* ## Macro operation end [a2fb2719-cec4-4fac-a37d-761988d436da] */

/* Macro operation name: U8_IP_PTR_U8 */
/** This operation shall perform combined data point search and interpolation for 1D calibration curve of type uint8 and data point array of type uint8

@param map Pointer to 1D calibration curve
@param xval Data point value to be searched

Range:          00(H) ... FF(H)
	            0 ...... 255 */
/* ## Macro operation start [caff4dfb-9e57-4b2b-ad60-a39b1a3ce640] */
#define U8_IP_PTR_U8(map, xval)  function_u8_ip_ptr_u8(map, X_##map, xval)
/* ## Macro operation end [caff4dfb-9e57-4b2b-ad60-a39b1a3ce640] */

/* Macro operation name: U8_IP_PTR_U16 */
/** This operation shall perform combined data point search and interpolation for 1D calibration curve of type uint8 and data point array of type uint16

@param map Pointer to 1D calibration curve
@param xval Data point value to be searched

Range:	         0000(H) ... FFFF(H)
	               0 ....... 65535 */
/* ## Macro operation start [e3384d21-f185-4a15-a9f5-5b98e024023e] */
#define U8_IP_PTR_U16(map, xval)  function_u8_ip_ptr_u16(map, X_##map, xval)
/* ## Macro operation end [e3384d21-f185-4a15-a9f5-5b98e024023e] */

/* Macro operation name: U16_IP_PTR_U8 */
/** This operation shall perform combined data point search and interpolation for 1D calibration curve of type uint16 and data point array of type uint8

@param map Pointer to 1D calibration curve
@param xval Data point value to be searched

Range:	         00(H) ... FF(H)
	           0 ....... 255 */
/* ## Macro operation start [8cdbde46-7810-4fd3-922b-6308e9bfcb0a] */
#define U16_IP_PTR_U8(map, xval)  function_u16_ip_ptr_u8(map, X_##map, xval)
/* ## Macro operation end [8cdbde46-7810-4fd3-922b-6308e9bfcb0a] */

/* Macro operation name: U16_IP_PTR_U16 */
/** This operation shall perform combined data point search and interpolation for 1D calibration curve of type uint16 and data point array of type uint16

@param map Pointer to 1D calibration curve
@param xval Data point value to be searched

Range:	         0000(H) ... FFFF(H)
	               0 ....... 65535 */
/* ## Macro operation start [7b524708-921b-433b-b2d1-4c1fc115a041] */
#define U16_IP_PTR_U16(map, xval)  function_u16_ip_ptr_u16(map, X_##map, xval)
/* ## Macro operation end [7b524708-921b-433b-b2d1-4c1fc115a041] */

/* Macro operation name: U8_IP_PTR_U8_U8 */
/** This operation shall perform combined data point search and interpolation for 2D calibration map of type uint8 with X data point array of type uint8 and Y data point array of type uint8

@param map Pointer to 2D calibration map
@param xval X Data point value to be searched

Range:	         00(H) ... FF(H)
	           0 ....... 255
@param yval Y Data point value to be searched

Range:	         00(H) ... FF(H)
	           0 ....... 255 */
/* ## Macro operation start [7cd96052-bbea-424a-ab68-aa1fb47c336b] */
#define U8_IP_PTR_U8_U8(map, xval, yval)  function_u8_ip_ptr_u8_u8((const uint8 *)map, X_##map, Y_##map, xval, yval)
/* ## Macro operation end [7cd96052-bbea-424a-ab68-aa1fb47c336b] */

/* Macro operation name: U8_IP_PTR_U8_U16 */
/** This operation shall perform combined data point search and interpolation for 2D calibration map of type uint8 with X data point array of type uint8 and Y data point array of type uint16

@param map Pointer to 2D calibration map
@param xval X Data point value to be searched

Range:	         00(H) ... FF(H)
	           0 ....... 255
@param yval Y Data point value to be searched

Range:	         0000(H) ... FFFF(H)
	               0 ....... 65535 */
/* ## Macro operation start [61204fb5-5139-42d8-bd06-7d690577dc7c] */
#define U8_IP_PTR_U8_U16(map, xval, yval)  function_u8_ip_ptr_u8_u16((const uint8 *)map, X_##map, Y_##map, xval, yval)
/* ## Macro operation end [61204fb5-5139-42d8-bd06-7d690577dc7c] */

/* Macro operation name: U8_IP_PTR_U16_U8 */
/** This operation shall perform combined data point search and interpolation for 2D calibration map of type uint8 with X data point array of type uint16 and Y data point array of type uint8

@param map Pointer to 2D calibration map
@param xval X Data point value to be searched

Range:	         0000(H) ... FFFF(H)
	               0 ....... 65535
@param yval Y Data point value to be searched

Range:	         00(H) ... FF(H)
	            0 ....... 255 */
/* ## Macro operation start [bb7f1076-cfe9-4bf3-95f2-cdcbe292cf6a] */
#define U8_IP_PTR_U16_U8(map, xval, yval)  function_u8_ip_ptr_u16_u8((const uint8 *)map, X_##map, Y_##map, xval, yval) 
/* ## Macro operation end [bb7f1076-cfe9-4bf3-95f2-cdcbe292cf6a] */

/* Macro operation name: U8_IP_PTR_U16_U16 */
/** This operation shall perform combined data point search and interpolation for 2D calibration map of type uint8 with X data point array of type uint16 and Y data point array of type uint16

@param map Pointer to 2D calibration map
@param xval X Data point value to be searched

Range:	         0000(H) ... FFFF(H)
	               0 ....... 65535
@param yval Y Data point value to be searched

Range:	         0000(H) ... FFFF(H)
	               0 ....... 65535 */
/* ## Macro operation start [e8a374cf-7c84-4d55-94e7-f2ebef91af5c] */
#define U8_IP_PTR_U16_U16(map, xval, yval)  function_u8_ip_ptr_u16_u16((const uint8 *)map, X_##map, Y_##map, xval, yval) 
/* ## Macro operation end [e8a374cf-7c84-4d55-94e7-f2ebef91af5c] */

/* Macro operation name: U16_IP_PTR_U8_U8 */
/** This operation shall perform combined data point search and interpolation for 2D calibration map of type uint16 with X data point array of type uint8 and Y data point array of type uint8

@param map Pointer to 2D calibration map
@param xval X Data point value to be searched

Range:           00(H) ... FF(H)
               0 ....... 255
@param yval Y Data point value to be searched

Range:           00(H) ... FF(H)
               0 ....... 255 */
/* ## Macro operation start [97ffb6c1-8047-401b-b762-bbda1597e449] */
#define U16_IP_PTR_U8_U8(map, xval, yval)  function_u16_ip_ptr_u8_u8((const uint16 *)(const void *)map, X_##map, Y_##map, xval, yval) 
/* ## Macro operation end [97ffb6c1-8047-401b-b762-bbda1597e449] */

/* Macro operation name: U16_IP_PTR_U8_U16 */
/** This operation shall perform combined data point search and interpolation for 2D calibration map of type uint16 with X data point array of type uint8 and Y data point array of type uint16

@param map Pointer to 2D calibration map
@param xval X Data point value to be searched

Range:           00(H) ... FF(H)
               0 ....... 255
@param yval Y Data point value to be searched

Range:           0000(H) ... FFFF(H)
                   0 ....... 65535 */
/* ## Macro operation start [bf04191b-f2e9-410a-942c-540555dc5d10] */
#define U16_IP_PTR_U8_U16(map, xval, yval)  function_u16_ip_ptr_u8_u16((const uint16 *)(const void *)map, X_##map, Y_##map, xval, yval)
/* ## Macro operation end [bf04191b-f2e9-410a-942c-540555dc5d10] */

/* Macro operation name: U16_IP_PTR_U16_U8 */
/** This operation shall perform combined data point search and interpolation for 2D calibration map of type uint16 with X data point array of type uint16 and Y data point array of type uint8

@param map Pointer to 2D calibration map
@param xval X Data point value to be searched

Range:           0000(H) ... FFFF(H)
                   0 ....... 65535
@param yval Y Data point value to be searched

Range:           00(H) ... FF(H)
                0 ...... 255 */
/* ## Macro operation start [370adb32-cddf-4a83-a6b7-d0728e74bc22] */
#define U16_IP_PTR_U16_U8(map, xval, yval)  function_u16_ip_ptr_u16_u8((const uint16 *)(const void *)map, X_##map, Y_##map, xval, yval)
/* ## Macro operation end [370adb32-cddf-4a83-a6b7-d0728e74bc22] */

/* Macro operation name: U16_IP_PTR_U16_U16 */
/** This operation shall perform combined data point search and interpolation for 2D calibration map of type uint16 with X data point array of type uint16 and Y data point array of type uint16

@param map Pointer to 2D calibration map
@param xval X Data point value to be searched

Range:           0000(H) ... FFFF(H)
                   0 ....... 65535
@param yval Y Data point value to be searched

Range:           0000(H) ... FFFF(H)
                   0 ....... 65535 */
/* ## Macro operation start [91d7af40-39f2-45d9-be99-31c28f7adb75] */
#define U16_IP_PTR_U16_U16(map, xval, yval)  function_u16_ip_ptr_u16_u16((const uint16 *)(const void *)map, X_##map, Y_##map, xval, yval)
/* ## Macro operation end [91d7af40-39f2-45d9-be99-31c28f7adb75] */

/* Macro operation name: U32_IP_PTR_U8_U16 */
/** This operation shall perform combined data point search and interpolation for 2D calibration map of type uint32 with X data point array of type uint8 and Y data point array of type uint16

@param map Pointer to 2D calibration map
@param xval X Data point value to be searched

Range:           00(H) ... FF(H)
               0 ....... 255
@param yval Y Data point value to be searched

Range:           0000(H) ... FFFF(H)
                   0 ....... 65535 */
/* ## Macro operation start [7d456529-0fe7-4bf3-b890-112224b4dd9a] */
#define U32_IP_PTR_U8_U16(map, xval, yval)  function_u32_ip_ptr_u8_u16((const uint32 *)(const void *)map, X_##map, Y_##map, xval, yval)
/* ## Macro operation end [7d456529-0fe7-4bf3-b890-112224b4dd9a] */

/* Macro operation name: U32_IP_PTR_U16_U16 */
/** This operation shall perform combined data point search and interpolation for 2D calibration map of type uint32 with X data point array of type uint16 and Y data point array of type uint16

@param map Pointer to 2D calibration map
@param xval X Data point value to be searched

Range:           0000(H) ... FFFF(H)
                   0 ....... 65535
@param yval Y Data point value to be searched

Range:           0000(H) ... FFFF(H)
                   0 ....... 65535 */
/* ## Macro operation start [4cdb12b3-91b7-42b0-9972-ae78d4632358] */
#define U32_IP_PTR_U16_U16(map, xval, yval)  function_u32_ip_ptr_u16_u16((const uint32 *)(const void *)map, X_##map, Y_##map, xval, yval)
/* ## Macro operation end [4cdb12b3-91b7-42b0-9972-ae78d4632358] */

/* Macro operation name: U16_IP1D_U8 */
/** This operation shall perform interpolation for 1D high resolution calibration curve of type uint8 and shall return the interpolated result as uint16 type

@param map pointer to 1D calibration curve
@param dpsx pointer to a variable of type DPS_RESULT which provides length, index and factor of the axis searched by search routine */
/* ## Macro operation start [39df2aad-2d90-46fc-9c00-00ffafefffb6] */
#define U16_IP1D_U8(map, dpsx)  function_u16_ip1d_u8(map, dpsx)
/* ## Macro operation end [39df2aad-2d90-46fc-9c00-00ffafefffb6] */

/* Macro operation name: U16_IP2D_U8 */
/** This operation shall perform interpolation for 2D high resolution calibration map of type uint8 and shall return the interpolated result as uint16 type

@param map pointer to 2D calibration map
@param dpsx pointer to a variable of type DPS_RESULT for X data point array which provides length, index and factor of the axis searched by search routine
@param dpsy pointer to a variable of type DPS_RESULT for Y data point array which provides length, index and factor of the axis searched by search routine */
/* ## Macro operation start [9b108383-114d-4b04-8e5d-db68edc488f7] */
#define U16_IP2D_U8(map, dpsx, dpsy)  function_u16_ip2d_u8((const uint8 *)map, dpsx, dpsy)
/* ## Macro operation end [9b108383-114d-4b04-8e5d-db68edc488f7] */

/* Macro operation name: U16_IP3D_U8 */
/** This operation shall perform interpolation for 3D high resolution calibration map of type uint8 and shall return the interpolated result as uint16 type

@param map pointer to 3D calibration map
@param dpsx pointer to a variable of type DPS_RESULT for X data point array or dimension 1 which provides length, index and factor of the axis searched by search routine
@param dpsy pointer to a variable of type DPS_RESULT for Y data point array or dimension 2 which provides length, index and factor of the axis searched by search routine
@param dpsz pointer to a variable of type DPS_RESULT for Z data point array or dimension 3 which provides length, index and factor of the axis searched by search routine */
/* ## Macro operation start [479707b2-10b9-418b-8915-d20eef4c0de9] */
#define U16_IP3D_U8(map, dpsx, dpsy, dpsz)  function_u16_ip3d_u8((const uint8 *)map, dpsx, dpsy, dpsz)
/* ## Macro operation end [479707b2-10b9-418b-8915-d20eef4c0de9] */

/* Macro operation name: U16_IP4D_U8 */
/** This operation shall perform interpolation for 4D high resolution calibration map of type uint8 and shall return the interpolated result as uint16 type

@param map pointer to 4D calibration map
@param dpsx_in pointer to a variable of type DPS_RESULT for inner X data point array or dimension 1 which provides length, index and factor of the axis searched by search routine
@param dpsy_in pointer to a variable of type DPS_RESULT for inner Y data point array or dimension 2 which provides length, index and factor of the axis searched by search routine
@param dpsx_out pointer to a variable of type DPS_RESULT for outer X data point array or dimension 3 which provides length, index and factor of the axis searched by search routine
@param dpsy_out pointer to a variable of type DPS_RESULT for outer Y data point array or dimension 4 which provides length, index and factor of the axis searched by search routine */
/* ## Macro operation start [cbb2933e-c788-416e-ac87-984e0c55771f] */
#define U16_IP4D_U8(map, dpsx_in, dpsy_in, dpsx_out, dpsy_out)  function_u16_ip4d_u8((const uint8 *)map, dpsx_in, dpsy_in, dpsx_out, dpsy_out)
/* ## Macro operation end [cbb2933e-c788-416e-ac87-984e0c55771f] */

/* Macro operation name: U32_IP1D_U16 */
/** This operation shall perform interpolation for 1D high resolution calibration curve of type uint16 and shall return the interpolated result as uint32 type

@param map pointer to 1D calibration curve
@param dpsx pointer to a variable of type DPS_RESULT which provides length, index and factor of the axis searched by search routine */
/* ## Macro operation start [60cedf32-8d8e-4d04-9d8e-2bac91983eb8] */
#define U32_IP1D_U16(map, dpsx)  function_u32_ip1d_u16(map, dpsx)
/* ## Macro operation end [60cedf32-8d8e-4d04-9d8e-2bac91983eb8] */

/* Macro operation name: U32_IP2D_U16 */
/** This operation shall perform interpolation for 2D high resolution calibration map of type uint16 and shall return the interpolated result as uint32 type

@param map pointer to 2D calibration map
@param dpsx pointer to a variable of type DPS_RESULT for X data point array which provides length, index and factor of the axis searched by search routine
@param dpsy pointer to a variable of type DPS_RESULT for Y data point array which provides length, index and factor of the axis searched by search routine */
/* ## Macro operation start [8c691b6a-fc69-49ad-9a8e-e5c76255e3ca] */
#define U32_IP2D_U16(map, dpsx, dpsy)  function_u32_ip2d_u16((const uint16 *)(const void *)map, dpsx, dpsy) 
/* ## Macro operation end [8c691b6a-fc69-49ad-9a8e-e5c76255e3ca] */

/* Macro operation name: U32_IP3D_U16 */
/** This operation shall perform interpolation for 3D high resolution calibration map of type uint16 and shall return the interpolated result as uint32 type

@param map pointer to 3D calibration map
@param dpsx pointer to a variable of type DPS_RESULT for X data point array or dimension 1 which provides length, index and factor of the axis searched by search routine
@param dpsy pointer to a variable of type DPS_RESULT for Y data point array or dimension 2 which provides length, index and factor of the axis searched by search routine
@param dpsz pointer to a variable of type DPS_RESULT for Z data point array or dimension 3 which provides length, index and factor of the axis searched by search routine */
/* ## Macro operation start [2d2dbac0-4868-4e2e-b28b-df23162bdb6e] */
#define U32_IP3D_U16(map, dpsx, dpsy, dpsz)  function_u32_ip3d_u16((const uint16 *)(const void *)map, dpsx, dpsy, dpsz) 
/* ## Macro operation end [2d2dbac0-4868-4e2e-b28b-df23162bdb6e] */

/* Macro operation name: U32_IP4D_U16 */
/** This operation shall perform interpolation for 4D high resolution calibration map of type uint16 and shall return the interpolated result as uint32 type

@param map pointer to 4D calibration map
@param dpsx_in pointer to a variable of type DPS_RESULT for inner X data point array or dimension 1 which provides length, index and factor of the axis searched by search routine
@param dpsy_in pointer to a variable of type DPS_RESULT for inner Y data point array or dimension 2 which provides length, index and factor of the axis searched by search routine
@param dpsx_out pointer to a variable of type DPS_RESULT for outer X data point array or dimension 3 which provides length, index and factor of the axis searched by search routine
@param dpsy_out pointer to a variable of type DPS_RESULT for outer Y data point array or dimension 4 which provides length, index and factor of the axis searched by search routine */
/* ## Macro operation start [ee0c533f-8d50-4451-8236-28a2405f9f9b] */
#define U32_IP4D_U16(map, dpsx_in, dpsy_in, dpsx_out, dpsy_out)  function_u32_ip4d_u16((const uint16 *)(const void *)map, dpsx_in, dpsy_in, dpsx_out, dpsy_out)
/* ## Macro operation end [ee0c533f-8d50-4451-8236-28a2405f9f9b] */

/* Macro operation name: S16_IP1D_S8 */
/** This operation shall perform interpolation for 1D high resolution calibration curve of type sint8 and shall return the interpolated result as sint16 type

@param map pointer to 1D calibration curve
@param dpsx pointer to a variable of type DPS_RESULT which provides length, index and factor of the axis searched by search routine */
/* ## Macro operation start [fbcde92c-a16e-4600-bc13-09cb859ee384] */
#define S16_IP1D_S8(map, dpsx)  function_s16_ip1d_s8(map, dpsx)
/* ## Macro operation end [fbcde92c-a16e-4600-bc13-09cb859ee384] */

/* Macro operation name: S16_IP2D_S8 */
/** This operation shall perform interpolation for 2D high resolution calibration map of type sint8 and shall return the interpolated result as sint16 type

@param map pointer to 2D calibration map
@param dpsx pointer to a variable of type DPS_RESULT for X data point array which provides length, index and factor of the axis searched by search routine
@param dpsy pointer to a variable of type DPS_RESULT for Y data point array which provides length, index and factor of the axis searched by search routine */
/* ## Macro operation start [63496ad9-781f-403d-96c1-87194ff5f14b] */
#define S16_IP2D_S8(map, dpsx, dpsy)  function_s16_ip2d_s8((const sint8 *)map, dpsx, dpsy)
/* ## Macro operation end [63496ad9-781f-403d-96c1-87194ff5f14b] */

/* Macro operation name: S16_IP3D_S8 */
/** This operation shall perform interpolation for 3D high resolution calibration map of type sint8 and shall return the interpolated result as sint16 type

@param map pointer to 3D calibration map
@param dpsx pointer to a variable of type DPS_RESULT for X data point array or dimension 1 which provides length, index and factor of the axis searched by search routine
@param dpsy pointer to a variable of type DPS_RESULT for Y data point array or dimension 2 which provides length, index and factor of the axis searched by search routine
@param dpsz pointer to a variable of type DPS_RESULT for Z data point array or dimension 3 which provides length, index and factor of the axis searched by search routine */
/* ## Macro operation start [2f754deb-8155-4230-a8da-f5169b6e70d1] */
#define S16_IP3D_S8(map, dpsx, dpsy, dpsz)  function_s16_ip3d_s8((const sint8 *)map, dpsx, dpsy, dpsz)
/* ## Macro operation end [2f754deb-8155-4230-a8da-f5169b6e70d1] */

/* Macro operation name: S16_IP4D_S8 */
/** This operation shall perform interpolation for 4D high resolution calibration map of type sint8 and shall return the interpolated result as sint16 type

@param map pointer to 4D calibration map
@param dpsx_in pointer to a variable of type DPS_RESULT for inner X data point array or dimension 1 which provides length, index and factor of the axis searched by search routine
@param dpsy_in pointer to a variable of type DPS_RESULT for inner Y data point array or dimension 2 which provides length, index and factor of the axis searched by search routine
@param dpsx_out pointer to a variable of type DPS_RESULT for outer X data point array or dimension 3 which provides length, index and factor of the axis searched by search routine
@param dpsy_out pointer to a variable of type DPS_RESULT for outer Y data point array or dimension 4 which provides length, index and factor of the axis searched by search routine */
/* ## Macro operation start [1b65e0d4-0aa0-45d4-9d00-236418cd62db] */
#define S16_IP4D_S8(map, dpsx_in, dpsy_in, dpsx_out, dpsy_out)  function_s16_ip4d_s8((const sint8 *)map, dpsx_in, dpsy_in, dpsx_out, dpsy_out)
/* ## Macro operation end [1b65e0d4-0aa0-45d4-9d00-236418cd62db] */

/* Macro operation name: S32_IP1D_S16 */
/** This operation shall perform interpolation for 1D high resolution calibration curve of type sint16 and shall return the interpolated result as sint32 type

@param map pointer to 1D calibration curve
@param dpsx pointer to a variable of type DPS_RESULT which provides length, index and factor of the axis searched by search routine */
/* ## Macro operation start [40aa0f60-37e9-4a6b-ba42-4e441613e2ff] */
#define S32_IP1D_S16(map, dpsx)  function_s32_ip1d_s16(map, dpsx)
/* ## Macro operation end [40aa0f60-37e9-4a6b-ba42-4e441613e2ff] */

/* Macro operation name: S32_IP2D_S16 */
/** This operation shall perform interpolation for 2D high resolution calibration map of type sint16 and shall return the interpolated result as sint32 type

@param map pointer to 2D calibration map
@param dpsx pointer to a variable of type DPS_RESULT for X data point array which provides length, index and factor of the axis searched by search routine
@param dpsy pointer to a variable of type DPS_RESULT for Y data point array which provides length, index and factor of the axis searched by search routine */
/* ## Macro operation start [aec81426-bc8c-446e-8079-2c85308cbe63] */
#define S32_IP2D_S16(map, dpsx, dpsy)  function_s32_ip2d_s16((const sint16 *)(const void *)map, dpsx, dpsy)
/* ## Macro operation end [aec81426-bc8c-446e-8079-2c85308cbe63] */

/* Macro operation name: S32_IP3D_S16 */
/** This operation shall perform interpolation for 3D high resolution calibration map of type sint16 and shall return the interpolated result as sint32 type

@param map pointer to 3D calibration map
@param dpsx pointer to a variable of type DPS_RESULT for X data point array or dimension 1 which provides length, index and factor of the axis searched by search routine
@param dpsy pointer to a variable of type DPS_RESULT for Y data point array or dimension 2 which provides length, index and factor of the axis searched by search routine
@param dpsz pointer to a variable of type DPS_RESULT for Z data point array or dimension 3 which provides length, index and factor of the axis searched by search routine */
/* ## Macro operation start [a8a5a89a-3f2e-4b3f-8d5e-456542a2226b] */
#define S32_IP3D_S16(map, dpsx, dpsy, dpsz)  function_s32_ip3d_s16((const sint16 *)(const void *)map, dpsx, dpsy, dpsz)
/* ## Macro operation end [a8a5a89a-3f2e-4b3f-8d5e-456542a2226b] */

/* Macro operation name: S32_IP4D_S16 */
/** This operation shall perform interpolation for 4D high resolution calibration map of type sint16 and shall return the interpolated result as sint32 type

@param map pointer to 4D calibration map
@param dpsx_in pointer to a variable of type DPS_RESULT for inner X data point array or dimension 1 which provides length, index and factor of the axis searched by search routine
@param dpsy_in pointer to a variable of type DPS_RESULT for inner Y data point array or dimension 2 which provides length, index and factor of the axis searched by search routine
@param dpsx_out pointer to a variable of type DPS_RESULT for outer X data point array or dimension 3 which provides length, index and factor of the axis searched by search routine
@param dpsy_out pointer to a variable of type DPS_RESULT for outer Y data point array or dimension 4 which provides length, index and factor of the axis searched by search routine */
/* ## Macro operation start [cb630e9f-6e58-4640-a46e-426ce6372e0a] */
#define S32_IP4D_S16(map, dpsx_in, dpsy_in, dpsx_out, dpsy_out)  function_s32_ip4d_s16((const sint16 *)(const void *)map, dpsx_in, dpsy_in, dpsx_out, dpsy_out)
/* ## Macro operation end [cb630e9f-6e58-4640-a46e-426ce6372e0a] */

/* Macro operation name: U8_IP1D_U8 */
/** This operation shall perform interpolation for 1D calibration curve of type uint8

@param map pointer to 1D calibration curve
@param dpsx pointer to a variable of type DPS_RESULT which provides length, index and factor of the axis searched by search routine */
/* ## Macro operation start [a21b4fdc-a561-4f4b-8878-12d8a748879a] */
#define U8_IP1D_U8(map, dpsx)  function_u8_ip1d_u8(map, dpsx)
/* ## Macro operation end [a21b4fdc-a561-4f4b-8878-12d8a748879a] */

/* Macro operation name: U16_IP1D_U16 */
/** This operation shall perform interpolation for 1D calibration curve of type uint16

@param map pointer to 1D calibration curve
@param dpsx pointer to a variable of type DPS_RESULT which provides length, index and factor of the axis searched by search routine */
/* ## Macro operation start [d3df0f7b-daae-4092-821e-18c040a81636] */
#define U16_IP1D_U16(map, dpsx)  function_u16_ip1d_u16(map, dpsx)
/* ## Macro operation end [d3df0f7b-daae-4092-821e-18c040a81636] */

/* Macro operation name: U32_IP1D_U32 */
/** This operation shall perform interpolation for 1D calibration curve of type uint32

@param map pointer to 1D calibration curve
@param dpsx pointer to a variable of type DPS_RESULT which provides length, index and factor of the axis searched by search routine */
/* ## Macro operation start [70ce41e8-7391-40a6-835f-78d073ccd4d3] */
#define U32_IP1D_U32(map, dpsx)  function_u32_ip1d_u32(map, dpsx)
/* ## Macro operation end [70ce41e8-7391-40a6-835f-78d073ccd4d3] */

/* Macro operation name: U8_IP2D_U8 */
/** This operation shall perform interpolation for 2D calibration map of type uint8

@param map pointer to 2D calibration map
@param dpsx pointer to a variable of type DPS_RESULT for X data point array which provides length, index and factor of the axis searched by search routine
@param dpsy pointer to a variable of type DPS_RESULT for Y data point array which provides length, index and factor of the axis searched by search routine */
/* ## Macro operation start [8f61c8e1-0d97-41b6-848e-0828bc7ae00e] */
#define U8_IP2D_U8(map, dpsx, dpsy)  function_u8_ip2d_u8((const uint8 *)map, dpsx, dpsy)
/* ## Macro operation end [8f61c8e1-0d97-41b6-848e-0828bc7ae00e] */

/* Macro operation name: U16_IP2D_U16 */
/** This operation shall perform interpolation for 2D calibration map of type uint16

@param map pointer to 2D calibration map
@param dpsx pointer to a variable of type DPS_RESULT for X data point array which provides length, index and factor of the axis searched by search routine
@param dpsy pointer to a variable of type DPS_RESULT for Y data point array which provides length, index and factor of the axis searched by search routine */
/* ## Macro operation start [291e0e5e-540e-4afa-a12c-a81e24d9bbd4] */
#define U16_IP2D_U16(map, dpsx, dpsy)  function_u16_ip2d_u16((const uint16 *)(const void *)map, dpsx, dpsy)
/* ## Macro operation end [291e0e5e-540e-4afa-a12c-a81e24d9bbd4] */

/* Macro operation name: U32_IP2D_U32 */
/** This operation shall perform interpolation for 2D calibration map of type uint32

@param map pointer to 2D calibration map
@param dpsx pointer to a variable of type DPS_RESULT for X data point array which provides length, index and factor of the axis searched by search routine
@param dpsy pointer to a variable of type DPS_RESULT for Y data point array which provides length, index and factor of the axis searched by search routine */
/* ## Macro operation start [b2e9caaa-8b57-4bd4-8ddf-458f9ca4833b] */
#define U32_IP2D_U32(map, dpsx, dpsy)  function_u32_ip2d_u32((const uint32 *)(const void *)map, dpsx, dpsy)
/* ## Macro operation end [b2e9caaa-8b57-4bd4-8ddf-458f9ca4833b] */

/* Macro operation name: U8_IP3D_U8 */
/** This operation shall perform interpolation for 3D calibration map of type uint8

@param map pointer to 3D calibration map
@param dpsx pointer to a variable of type DPS_RESULT for X data point array or dimension 1 which provides length, index and factor of the axis searched by search routine
@param dpsy pointer to a variable of type DPS_RESULT for Y data point array or dimension 2 which provides length, index and factor of the axis searched by search routine
@param dpsz pointer to a variable of type DPS_RESULT for Z data point array or dimension 3 which provides length, index and factor of the axis searched by search routine */
/* ## Macro operation start [369745a2-3b22-47a3-91b2-0060cdf7f494] */
#define U8_IP3D_U8(map, dpsx, dpsy, dpsz)  function_u8_ip3d_u8((const uint8 *)map, dpsx, dpsy, dpsz)
/* ## Macro operation end [369745a2-3b22-47a3-91b2-0060cdf7f494] */

/* Macro operation name: U16_IP3D_U16 */
/** This operation shall perform interpolation for 3D calibration map of type uint16

@param map pointer to 3D calibration map
@param dpsx pointer to a variable of type DPS_RESULT for X data point array or dimension 1 which provides length, index and factor of the axis searched by search routine
@param dpsy pointer to a variable of type DPS_RESULT for Y data point array or dimension 2 which provides length, index and factor of the axis searched by search routine
@param dpsz pointer to a variable of type DPS_RESULT for Z data point array or dimension 3 which provides length, index and factor of the axis searched by search routine */
/* ## Macro operation start [db2c28c1-69fe-4a82-8026-59c303d1b837] */
#define U16_IP3D_U16(map, dpsx, dpsy, dpsz)  function_u16_ip3d_u16((const uint16 *)(const void *)map, dpsx, dpsy, dpsz)
/* ## Macro operation end [db2c28c1-69fe-4a82-8026-59c303d1b837] */

/* Macro operation name: U8_IP4D_U8 */
/** This operation shall perform interpolation for 4D calibration map of type uint8

@param map pointer to 4D calibration map
@param dpsx_in pointer to a variable of type DPS_RESULT for inner X data point array or dimension 1 which provides length, index and factor of the axis searched by search routine
@param dpsy_in pointer to a variable of type DPS_RESULT for inner Y data point array or dimension 2 which provides length, index and factor of the axis searched by search routine
@param dpsx_out pointer to a variable of type DPS_RESULT for outer X data point array or dimension 3 which provides length, index and factor of the axis searched by search routine
@param dpsy_out pointer to a variable of type DPS_RESULT for outer Y data point array or dimension 4 which provides length, index and factor of the axis searched by search routine */
/* ## Macro operation start [7085e578-c8c4-420d-b5be-e5b79c1dac74] */
#define U8_IP4D_U8(map, dpsx_in, dpsy_in, dpsx_out, dpsy_out)  function_u8_ip4d_u8((const uint8 *)map, dpsx_in, dpsy_in, dpsx_out, dpsy_out)
/* ## Macro operation end [7085e578-c8c4-420d-b5be-e5b79c1dac74] */

/* Macro operation name: U16_IP4D_U16 */
/** This operation shall perform interpolation for 4D calibration map of type uint16

@param map pointer to 4D calibration map
@param dpsx_in pointer to a variable of type DPS_RESULT for inner X data point array or dimension 1 which provides length, index and factor of the axis searched by search routine
@param dpsy_in pointer to a variable of type DPS_RESULT for inner Y data point array or dimension 2 which provides length, index and factor of the axis searched by search routine
@param dpsx_out pointer to a variable of type DPS_RESULT for outer X data point array or dimension 3 which provides length, index and factor of the axis searched by search routine
@param dpsy_out pointer to a variable of type DPS_RESULT for outer Y data point array or dimension 4 which provides length, index and factor of the axis searched by search routine */
/* ## Macro operation start [572c7696-888f-4999-8ed5-a02ced7eea8b] */
#define U16_IP4D_U16(map, dpsx_in, dpsy_in, dpsx_out, dpsy_out)  function_u16_ip4d_u16((const uint16 *)(const void *)map, dpsx_in, dpsy_in, dpsx_out, dpsy_out)
/* ## Macro operation end [572c7696-888f-4999-8ed5-a02ced7eea8b] */

/* Macro operation name: S8_IP1D_S8 */
/** This operation shall perform interpolation for 1D calibration curve of type sint8

@param map pointer to 1D calibration curve
@param dpsx pointer to a variable of type DPS_RESULT which provides length, index and factor of the axis searched by search routine */
/* ## Macro operation start [53ab487d-8148-4648-874d-1e40a7d18ab4] */
#define S8_IP1D_S8(map, dpsx)  function_s8_ip1d_s8(map, dpsx)
/* ## Macro operation end [53ab487d-8148-4648-874d-1e40a7d18ab4] */

/* Macro operation name: S16_IP1D_S16 */
/** This operation shall perform interpolation for 1D calibration curve of type sint16

@param map pointer to 1D calibration curve
@param dpsx pointer to a variable of type DPS_RESULT which provides length, index and factor of the axis searched by search routine */
/* ## Macro operation start [0d77a39e-31fa-4e45-8d29-d167f1ce315e] */
#define S16_IP1D_S16(map, dpsx)  function_s16_ip1d_s16(map, dpsx)
/* ## Macro operation end [0d77a39e-31fa-4e45-8d29-d167f1ce315e] */

/* Macro operation name: S32_IP1D_S32 */
/** This operation shall perform interpolation for 1D calibration curve of type sint32

@param map pointer to 1D calibration curve
@param dpsx pointer to a variable of type DPS_RESULT which provides length, index and factor of the axis searched by search routine */
/* ## Macro operation start [10b8b7d0-8e47-4036-8025-2513449bcaef] */
#define S32_IP1D_S32(map, dpsx)  function_s32_ip1d_s32(map, dpsx)
/* ## Macro operation end [10b8b7d0-8e47-4036-8025-2513449bcaef] */

/* Macro operation name: S8_IP2D_S8 */
/** This operation shall perform interpolation for 2D calibration map of type sint8

@param map pointer to 2D calibration map
@param dpsx pointer to a variable of type DPS_RESULT for X data point array which provides length, index and factor of the axis searched by search routine
@param dpsy pointer to a variable of type DPS_RESULT for Y data point array which provides length, index and factor of the axis searched by search routine */
/* ## Macro operation start [426c0307-49b1-4e4c-872b-80a3a2cad237] */
#define S8_IP2D_S8(map, dpsx, dpsy)  function_s8_ip2d_s8((const sint8 *)map, dpsx, dpsy) 
/* ## Macro operation end [426c0307-49b1-4e4c-872b-80a3a2cad237] */

/* Macro operation name: S16_IP2D_S16 */
/** This operation shall perform interpolation for 2D calibration map of type sint16

@param map pointer to 2D calibration map
@param dpsx pointer to a variable of type DPS_RESULT for X data point array which provides length, index and factor of the axis searched by search routine
@param dpsy pointer to a variable of type DPS_RESULT for Y data point array which provides length, index and factor of the axis searched by search routine */
/* ## Macro operation start [13f57455-9d9e-4a4f-b7e5-a3590849cb42] */
#define S16_IP2D_S16(map, dpsx, dpsy)  function_s16_ip2d_s16((const sint16 *)(const void *)map, dpsx, dpsy)
/* ## Macro operation end [13f57455-9d9e-4a4f-b7e5-a3590849cb42] */

/* Macro operation name: S32_IP2D_S32 */
/** This operation shall perform interpolation for 2D calibration map of type sint32

@param map pointer to 2D calibration map
@param dpsx pointer to a variable of type DPS_RESULT for X data point array which provides length, index and factor of the axis searched by search routine
@param dpsy pointer to a variable of type DPS_RESULT for Y data point array which provides length, index and factor of the axis searched by search routine */
/* ## Macro operation start [8ea05159-ec22-454c-9815-b05151f7299d] */
#define S32_IP2D_S32(map, dpsx, dpsy)  function_s32_ip2d_s32((const sint32 *)(const void *)map, dpsx, dpsy)
/* ## Macro operation end [8ea05159-ec22-454c-9815-b05151f7299d] */

/* Macro operation name: S8_IP3D_S8 */
/** This operation shall perform interpolation for 3D calibration map of type sint8

@param map pointer to 3D calibration map
@param dpsx pointer to a variable of type DPS_RESULT for X data point array or dimension 1 which provides length, index and factor of the axis searched by search routine
@param dpsy pointer to a variable of type DPS_RESULT for Y data point array or dimension 2 which provides length, index and factor of the axis searched by search routine
@param dpsz pointer to a variable of type DPS_RESULT for Z data point array or dimension 3 which provides length, index and factor of the axis searched by search routine */
/* ## Macro operation start [90077dc6-3de9-40ca-bf56-dc27e4f15d58] */
#define S8_IP3D_S8(map, dpsx, dpsy, dpsz)  function_s8_ip3d_s8((const sint8 *)map, dpsx, dpsy, dpsz) 
/* ## Macro operation end [90077dc6-3de9-40ca-bf56-dc27e4f15d58] */

/* Macro operation name: S16_IP3D_S16 */
/** This operation shall perform interpolation for 3D calibration map of type sint16

@param map pointer to 3D calibration map
@param dpsx pointer to a variable of type DPS_RESULT for X data point array or dimension 1 which provides length, index and factor of the axis searched by search routine
@param dpsy pointer to a variable of type DPS_RESULT for Y data point array or dimension 2 which provides length, index and factor of the axis searched by search routine
@param dpsz pointer to a variable of type DPS_RESULT for Z data point array or dimension 3 which provides length, index and factor of the axis searched by search routine */
/* ## Macro operation start [814f8eaf-24ef-4b94-bbd9-985af855edbd] */
#define S16_IP3D_S16(map, dpsx, dpsy, dpsz)  function_s16_ip3d_s16((const sint16 *)(const void *)map, dpsx, dpsy, dpsz)
/* ## Macro operation end [814f8eaf-24ef-4b94-bbd9-985af855edbd] */

/* Macro operation name: S8_IP4D_S8 */
/** This operation shall perform interpolation for 4D calibration map of type sint8

@param map pointer to 4D calibration map
@param dpsx_in pointer to a variable of type DPS_RESULT for inner X data point array or dimension 1 which provides length, index and factor of the axis searched by search routine
@param dpsy_in pointer to a variable of type DPS_RESULT for inner Y data point array or dimension 2 which provides length, index and factor of the axis searched by search routine
@param dpsx_out pointer to a variable of type DPS_RESULT for outer X data point array or dimension 3 which provides length, index and factor of the axis searched by search routine
@param dpsy_out pointer to a variable of type DPS_RESULT for outer Y data point array or dimension 4 which provides length, index and factor of the axis searched by search routine */
/* ## Macro operation start [08cc992d-b35e-461e-a4e9-baa4817b8df7] */
#define S8_IP4D_S8(map, dpsx_in, dpsy_in, dpsx_out, dpsy_out)  function_s8_ip4d_s8((const sint8 *)map, dpsx_in, dpsy_in, dpsx_out, dpsy_out)
/* ## Macro operation end [08cc992d-b35e-461e-a4e9-baa4817b8df7] */

/* Macro operation name: S16_IP4D_S16 */
/** This operation shall perform interpolation for 4D calibration map of type sint16

@param map pointer to 4D calibration map
@param dpsx_in pointer to a variable of type DPS_RESULT for inner X data point array or dimension 1 which provides length, index and factor of the axis searched by search routine
@param dpsy_in pointer to a variable of type DPS_RESULT for inner Y data point array or dimension 2 which provides length, index and factor of the axis searched by search routine
@param dpsx_out pointer to a variable of type DPS_RESULT for outer X data point array or dimension 3 which provides length, index and factor of the axis searched by search routine
@param dpsy_out pointer to a variable of type DPS_RESULT for outer Y data point array or dimension 4 which provides length, index and factor of the axis searched by search routine */
/* ## Macro operation start [350a7869-bbb4-4dc9-a226-898784ea7184] */
#define S16_IP4D_S16(map, dpsx_in, dpsy_in, dpsx_out, dpsy_out)  function_s16_ip4d_s16((const sint16 *)(const void *)map, dpsx_in, dpsy_in, dpsx_out, dpsy_out)
/* ## Macro operation end [350a7869-bbb4-4dc9-a226-898784ea7184] */

/* Macro operation name: U8_IP1D_PTR_U8 */
/** This operation shall perform interpolation for 1D calibration curve of type uint8

@param map pointer to 1D calibration curve */
/* ## Macro operation start [8e5668ff-d2b0-4563-b63a-b51480c42e7e] */
#define U8_IP1D_PTR_U8(map)  U8_IP1D_U8(map, &calm_x_dps_result)
/* ## Macro operation end [8e5668ff-d2b0-4563-b63a-b51480c42e7e] */

/* Macro operation name: U16_IP1D_PTR_U16 */
/** This operation shall perform interpolation for 1D calibration curve of type uint16

@param map pointer to 1D calibration curve */
/* ## Macro operation start [ae5f9e6e-ec8b-4561-b982-0500e81b2861] */
#define U16_IP1D_PTR_U16(map)  U16_IP1D_U16(map, &calm_x_dps_result)
/* ## Macro operation end [ae5f9e6e-ec8b-4561-b982-0500e81b2861] */

/* Macro operation name: U32_IP1D_PTR_U32 */
/** This operation shall perform interpolation for 1D calibration curve of type uint32

@param map pointer to 1D calibration curve */
/* ## Macro operation start [17bd1652-2a51-4bda-86bb-4755e8621fec] */
#define U32_IP1D_PTR_U32(map)  U32_IP1D_U32(map, &calm_x_dps_result)
/* ## Macro operation end [17bd1652-2a51-4bda-86bb-4755e8621fec] */

/* Macro operation name: U8_IP2D_PTR_U8 */
/** This operation shall perform interpolation for 2D calibration map of type uint8

@param map pointer to 2D calibration map */
/* ## Macro operation start [07291427-d4c8-4cab-9228-f31ccfdc7475] */
#define U8_IP2D_PTR_U8(map)  U8_IP2D_U8(map, &calm_x_dps_result, &calm_y_dps_result)
/* ## Macro operation end [07291427-d4c8-4cab-9228-f31ccfdc7475] */

/* Macro operation name: U16_IP2D_PTR_U16 */
/** This operation shall perform interpolation for 2D calibration map of type uint16

@param map pointer to 2D calibration map */
/* ## Macro operation start [eec18f56-4b79-490e-988e-13679b9502ec] */
#define U16_IP2D_PTR_U16(map)  U16_IP2D_U16(map, &calm_x_dps_result, &calm_y_dps_result)
/* ## Macro operation end [eec18f56-4b79-490e-988e-13679b9502ec] */

/* Macro operation name: U32_IP2D_PTR_U32 */
/** This operation shall perform interpolation for 2D calibration map of type uint32

@param map pointer to 2D calibration map */
/* ## Macro operation start [b6399c44-fb7f-4e03-9db5-25666e42205f] */
#define U32_IP2D_PTR_U32(map)  U32_IP2D_U32(map, &calm_x_dps_result, &calm_y_dps_result)
/* ## Macro operation end [b6399c44-fb7f-4e03-9db5-25666e42205f] */

/* Macro operation name: U8_IP_REL_PTR_U8_IDXP */
/** This operation shall perform combined relative data point search and interpolation for 1D calibration curve of type uint8 and data point array of type uint8

@param map Pointer to 1D calibration curve
@param xval Data point value to be searched

Range:       00(H) ... FF(H)
	         0 ....... 255
@param idxp Pointer pointing to the location of array from which data point search has to be started */
/* ## Macro operation start [57ad166e-f9d9-4528-878b-5a70fe9e8f70] */
#define U8_IP_REL_PTR_U8_IDXP(map, xval, idxp)  function_u8_ip_rel_ptr_u8_idxp(map, X_##map, xval, idxp)
/* ## Macro operation end [57ad166e-f9d9-4528-878b-5a70fe9e8f70] */

/* Macro operation name: U8_IP_REL_PTR_U16_IDXP */
/** This operation shall perform combined relative data point search and interpolation for 1D calibration curve of type uint8 and data point array of type uint16

@param map Pointer to 1D calibration curve
@param xval Data point value to be searched

Range:	        0000(H) ... FFFF(H)
	              0 ....... 65535
@param idxp Pointer pointing to the location of array from which data point search has to be started */
/* ## Macro operation start [8aa33388-89f8-4ee3-a48e-5f4b98f5732a] */
#define U8_IP_REL_PTR_U16_IDXP(map, xval, idxp)  function_u8_ip_rel_ptr_u16_idxp(map, X_##map, xval, idxp)
/* ## Macro operation end [8aa33388-89f8-4ee3-a48e-5f4b98f5732a] */

/* Macro operation name: U16_IP_REL_PTR_U8_IDXP */
/** This operation shall perform combined relative data point search and interpolation for 1D calibration curve of type uint16 and data point array of type uint8

@param map Pointer to 1D calibration curve
@param xval Data point value to be searched

Range:	        00(H) ... FF(H)
	          0 ....... 255
@param idxp Pointer pointing to the location of array from which data point search has to be started */
/* ## Macro operation start [14a6a5a6-20c8-4a0f-b075-2b2c9da074ca] */
#define U16_IP_REL_PTR_U8_IDXP(map, xval, idxp)  function_u16_ip_rel_ptr_u8_idxp(map, X_##map, xval, idxp)
/* ## Macro operation end [14a6a5a6-20c8-4a0f-b075-2b2c9da074ca] */

/* Macro operation name: U16_IP_REL_PTR_U16_IDXP */
/** This operation shall perform combined relative data point search and interpolation for 1D calibration curve of type uint16 and data point array of type uint16

@param map Pointer to 1D calibration curve
@param xval Data point value to be searched

Range:	        0000(H) ... FFFF(H)
	              0 ....... 65535
@param idxp Pointer pointing to the location of array from which data point search has to be started */
/* ## Macro operation start [d5a792bf-e3e6-480b-8f3e-be9bc4098258] */
#define U16_IP_REL_PTR_U16_IDXP(map, xval, idxp)  function_u16_ip_rel_ptr_u16_idxp(map, X_##map, xval, idxp)
/* ## Macro operation end [d5a792bf-e3e6-480b-8f3e-be9bc4098258] */

/* Macro operation name: U8_IP_REL_PTR_U8_IDXP_U8 */
/** This operation shall perform combined relative data point search and interpolation for 2D calibration map of type uint8 with X data point array of type uint8 and Y data point array of type uint8

X axis shall be searched relatively

@param map Pointer to 2D calibration map
@param xval X Data point value to be searched

Range:	        00(H) ... FF(H)
	          0 ....... 255
@param yval Y Data point value to be searched

Range:	        00(H) ... FF(H)
	          0 ....... 255
@param idxp Pointer pointing to the location of X data point array from which data point search has to be started */
/* ## Macro operation start [20df8d43-2a81-4d74-a8dd-c0f51d7cf821] */
#define U8_IP_REL_PTR_U8_IDXP_U8(map, xval, yval, idxp)  func_u8_ip_rel_ptr_u8_idxp_u8((const uint8 *)map, X_##map, Y_##map, xval, yval, idxp)
/* ## Macro operation end [20df8d43-2a81-4d74-a8dd-c0f51d7cf821] */

/* Macro operation name: U8_IP_REL_PTR_U8_U8_IDYP */
/** This operation shall perform combined relative data point search and interpolation for 2D calibration map of type uint8 with X data point array of type uint8 and Y data point array of type uint8

Y axis shall be searched relatively

@param map Pointer to 2D calibration map
@param xval X Data point value to be searched

Range:	        00(H) ... FF(H)
	          0 ....... 255
@param yval Y Data point value to be searched

Range:	        00(H) ... FF(H)
	          0 ....... 255
@param idyp Pointer pointing to the location of array from which data point search has to be started */
/* ## Macro operation start [1e9795e4-57d0-4c82-9ba1-f276cc440bc0] */
#define U8_IP_REL_PTR_U8_U8_IDYP(map, xval, yval, idyp)  func_u8_ip_rel_ptr_u8_u8_idyp((const uint8 *)map, X_##map, Y_##map, xval, yval, idyp)
/* ## Macro operation end [1e9795e4-57d0-4c82-9ba1-f276cc440bc0] */

/* Macro operation name: U8_IP_REL_PTR_U16_IDXP_U8 */
/** This operation shall perform combined relative data point search and interpolation for 2D calibration map of type uint8 with X data point array of type uint16 and Y data point array of type uint8

X axis shall be searched relatively

@param map Pointer to 2D calibration map
@param xval X Data point value to be searched

Range:	        0000(H) ... FFFF(H)
	              0 ....... 65535
@param yval Y Data point value to be searched

Range:	        00(H) ... FF(H)
	          0 ....... 255
@param idxp Pointer pointing to the location of array from which data point search has to be started */
/* ## Macro operation start [30228ee0-b134-435b-a275-244f0a9cad89] */
#define U8_IP_REL_PTR_U16_IDXP_U8(map, xval, yval, idxp)  func_u8_ip_rel_ptr_u16_idxp_u8((const uint8 *)map, X_##map, Y_##map, xval, yval, idxp)
/* ## Macro operation end [30228ee0-b134-435b-a275-244f0a9cad89] */

/* Macro operation name: U8_IP_REL_PTR_U16_U8_IDYP */
/** This operation shall perform combined relative data point search and interpolation for 2D calibration map of type uint8 with X data point array of type uint16 and Y data point array of type uint8

Y axis shall be searched relatively

@param map Pointer to 2D calibration map
@param xval X Data point value to be searched

Range:	        0000(H) ... FFFF(H)
	              0 ....... 65535
@param yval Y Data point value to be searched

Range:	        00(H) ... FF(H)
	          0 ....... 255
@param idyp Pointer pointing to the location of array from which data point search is to be started */
/* ## Macro operation start [231b9748-a9e5-4cae-9991-9dc516a07f7c] */
#define U8_IP_REL_PTR_U16_U8_IDYP(map, xval, yval, idyp)  func_u8_ip_rel_ptr_u16_u8_idyp((const uint8 *)map, X_##map, Y_##map, xval, yval, idyp)
/* ## Macro operation end [231b9748-a9e5-4cae-9991-9dc516a07f7c] */

/* Macro operation name: U8_IP_REL_PTR_U8_IDXP_U16 */
/** This operation shall perform combined relative data point search and interpolation for 2D calibration map of type uint8 with X data point array of type uint8 and Y data point array of type uint16.

X axis shall be searched relatively

@param map Pointer to 2D calibration map
@param xval X Data point value to be searched

Range:	        00(H) ... FF(H)
	          0 ....... 255
@param yval Y Data point value to be searched

Range:	        0000(H) ... FFFF(H)
	              0 ....... 65535
@param idxp Pointer pointing to the location of array from which data point search is to be started */
/* ## Macro operation start [1cb37c97-feea-4c5f-855e-89e5dc7911b9] */
#define U8_IP_REL_PTR_U8_IDXP_U16(map, xval, yval, idxp)  func_u8_ip_rel_ptr_u8_idxp_u16((const uint8 *)map, X_##map, Y_##map, xval, yval, idxp)
/* ## Macro operation end [1cb37c97-feea-4c5f-855e-89e5dc7911b9] */

/* Macro operation name: U8_IP_REL_PTR_U8_U16_IDYP */
/** This operation shall perform combined relative data point search and interpolation for 2D calibration map of type uint8 with X data point array of type uint8 and Y data point array of type uint16

Y axis shall be searched relatively

@param map Pointer to 2D calibration map
@param xval X Data point value to be searched

Range:	        00(H) ... FF(H)
	          0 ....... 255
@param yval Y Data point value to be searched

Range:	        0000(H) ... FFFF(H)
	              0 ....... 65535
@param idyp Pointer pointing to the location of array from which data point search is to be started */
/* ## Macro operation start [c07c2db9-b029-40b7-9b28-89c94200be44] */
#define U8_IP_REL_PTR_U8_U16_IDYP(map, xval, yval, idyp)  func_u8_ip_rel_ptr_u8_u16_idyp((const uint8 *)map, X_##map, Y_##map, xval, yval, idyp)
/* ## Macro operation end [c07c2db9-b029-40b7-9b28-89c94200be44] */

/* Macro operation name: U8_IP_REL_PTR_U16_IDXP_U16 */
/** This operation shall perform combined relative data point search and interpolation for 2D calibration map of type uint8 with X data point array of type uint16 and Y data point array of type uint16

X axis shall be searched relatively

@param map Pointer to 2D calibration map
@param xval X Data point value to be searched

Range:	        0000(H) ... FFFF(H)
	              0 ....... 65535
@param yval Y Data point value to be searched

Range:	        0000(H) ... FFFF(H)
	              0 ....... 65535
@param idxp Pointer pointing to the location of array from which data point search is to be started */
/* ## Macro operation start [fd058e55-247e-410e-ae9b-1e6a861e3e03] */
#define U8_IP_REL_PTR_U16_IDXP_U16(map, xval, yval, idxp)  func_u8_ip_rel_ptr_u16_idxp_u16((const uint8 *)map, X_##map, Y_##map, xval, yval, idxp)
/* ## Macro operation end [fd058e55-247e-410e-ae9b-1e6a861e3e03] */

/* Macro operation name: U8_IP_REL_PTR_U16_U16_IDYP */
/** This operation shall perform combined relative data point search and interpolation for 2D calibration map of type uint8 with X data point array of type uint16 and Y data point array of type uint16

Y axis shall be searched relatively

@param map Pointer to 2D calibration map
@param xval X Data point value to be searched

Range:	        0000(H) ... FFFF(H)
	              0 ....... 65535
@param yval Y Data point value to be searched

Range:	        0000(H) ... FFFF(H)
	              0 ....... 65535
@param idyp Pointer pointing to the location of array from which data point search is to be started */
/* ## Macro operation start [f3eeab12-086e-4c5c-ad7b-0c2cab61aa5b] */
#define U8_IP_REL_PTR_U16_U16_IDYP(map, xval, yval, idyp)  func_u8_ip_rel_ptr_u16_u16_idyp((const uint8 *)map, X_##map, Y_##map, xval, yval, idyp)
/* ## Macro operation end [f3eeab12-086e-4c5c-ad7b-0c2cab61aa5b] */

/* Macro operation name: U16_IP_REL_PTR_U8_IDXP_U8 */
/** This operation shall perform combined relative data point search and interpolation for 2D calibration map of type uint16 with X data point array of type uint8 and Y data point array of type uint8

X axis shall be searched relatively

@param map Pointer to 2D calibration map
@param xval X Data point value to be searched

Range:          00(H) ... FF(H)
              0 ....... 255
@param yval Y Data point value to be searched

Range:          00(H) ... FF(H)
              0 ....... 255
@param idxp Pointer pointing to the location of array from which data point search is to be started */
/* ## Macro operation start [98465758-595a-4c86-b503-1ec142ef6ccc] */
#define U16_IP_REL_PTR_U8_IDXP_U8(map, xval, yval, idxp)  func_u16_ip_rel_ptr_u8_idxp_u8((const uint16 *)(const void *)map, X_##map, Y_##map, xval,  yval, idxp)
/* ## Macro operation end [98465758-595a-4c86-b503-1ec142ef6ccc] */

/* Macro operation name: U16_IP_REL_PTR_U8_U8_IDYP */
/** This operation shall perform combined relative data point search and interpolation for 2D calibration map of type uint16 with X data point array of type uint8 and Y data point array of type uint8

Y axis shall be searched relatively

@param map Pointer to 2D calibration map
@param xval X Data point value to be searched

Range:          00(H) ... FF(H)
              0 ....... 255
@param yval Y Data point value to be searched

Range:          00(H) ... FF(H)
              0 ....... 255
@param idyp Pointer pointing to the location of array from which data point search is to be started */
/* ## Macro operation start [87ccd2ab-1ed6-4e57-b875-6c2423c3ffc6] */
#define U16_IP_REL_PTR_U8_U8_IDYP(map, xval, yval, idyp)  func_u16_ip_rel_ptr_u8_u8_idyp((const uint16 *)(const void *)map, X_##map, Y_##map, xval, yval, idyp)
/* ## Macro operation end [87ccd2ab-1ed6-4e57-b875-6c2423c3ffc6] */

/* Macro operation name: U16_IP_REL_PTR_U16_IDXP_U8 */
/** This operation shall perform combined relative data point search and interpolation for 2D calibration map of type uint16 with X data point array of type uint16 and Y data point array of type uint8

X axis shall be searched relatively

@param map Pointer to 2D calibration map
@param xval X Data point value to be searched

Range:          0000(H) ... FFFF(H)
                  0 ....... 65535
@param yval Y Data point value to be searched

Range:          00(H) ... FF(H)
              0 ....... 255
@param idxp Pointer pointing to the location of array from which data point search is to be started */
/* ## Macro operation start [515b690e-70f3-4a9d-be93-870789cb5764] */
#define U16_IP_REL_PTR_U16_IDXP_U8(map, xval, yval, idxp)  func_u16_ip_rel_ptr_u16_idxp_u8((const uint16 *)(const void *)map, X_##map, Y_##map, xval, yval, idxp)
/* ## Macro operation end [515b690e-70f3-4a9d-be93-870789cb5764] */

/* Macro operation name: U16_IP_REL_PTR_U16_U8_IDYP */
/** This operation shall perform combined relative data point search and interpolation for 2D calibration map of type uint16 with X data point array of type uint16 and Y data point array of type uint8

Y axis shall be searched relatively

@param map Pointer to 2D calibration map
@param xval X Data point value to be searched

Range:          0000(H) ... FFFF(H)
                  0 ....... 65535
@param yval Y Data point value to be searched

Range:          00(H) ... FF(H)
              0 ....... 255
@param idyp Pointer pointing to the location of array from which data point search is to be started */
/* ## Macro operation start [9d12f43b-5987-4c0a-b112-f07766ba01b8] */
#define U16_IP_REL_PTR_U16_U8_IDYP(map, xval, yval, idyp)  func_u16_ip_rel_ptr_u16_u8_idyp((const uint16 *)(const void *)map, X_##map, Y_##map, xval, yval, idyp)
/* ## Macro operation end [9d12f43b-5987-4c0a-b112-f07766ba01b8] */

/* Macro operation name: U16_IP_REL_PTR_U8_IDXP_U16 */
/** This operation shall perform combined relative data point search and interpolation for 2D calibration map of type uint16 with X data point array of type uint8 and Y data point array of type uint16

X axis shall be searched relatively

@param map Pointer to 2D calibration map
@param xval X Data point value to be searched

Range:          00(H) ... FF(H)
              0 ....... 255
@param yval Y Data point value to be searched

Range:          0000(H) ... FFFF(H)
                  0 ....... 65535
@param idxp Pointer pointing to the location of array from which data point search is to be started */
/* ## Macro operation start [05055469-a1e1-4a21-826c-4bb5db36596c] */
#define U16_IP_REL_PTR_U8_IDXP_U16(map, xval, yval, idxp)  func_u16_ip_rel_ptr_u8_idxp_u16((const uint16 *)(const void *)map, X_##map, Y_##map, xval, yval, idxp)
/* ## Macro operation end [05055469-a1e1-4a21-826c-4bb5db36596c] */

/* Macro operation name: U16_IP_REL_PTR_U8_U16_IDYP */
/** This operation shall perform combined relative data point search and interpolation for 2D calibration map of type uint16 with X data point array of type uint8 and Y data point array of type uint16

Y axis shall be searched relatively

@param map Pointer to 2D calibration map
@param xval X Data point value to be searched

Range:          00(H) ... FF(H)
              0 ....... 255
@param yval Y Data point value to be searched

Range:          0000(H) ... FFFF(H)
                  0 ....... 65535
@param idyp Pointer pointing to the location of array from which data point search is to be started */
/* ## Macro operation start [6d2d2e28-250d-4bad-bec5-14c8d22034a1] */
#define U16_IP_REL_PTR_U8_U16_IDYP(map, xval, yval, idyp)  func_u16_ip_rel_ptr_u8_u16_idyp((const uint16 *)(const void *)map, X_##map, Y_##map, xval, yval, idyp)
/* ## Macro operation end [6d2d2e28-250d-4bad-bec5-14c8d22034a1] */

/* Macro operation name: U16_IP_REL_PTR_U16_IDXP_U16 */
/** This operation shall perform combined relative data point search and interpolation for 2D calibration map of type uint16 with X data point array of type uint16 and Y data point array of type uint16

X axis shall be searched relatively

@param map Pointer to 2D calibration map
@param xval X Data point value to be searched

Range:          0000(H) ... FFFF(H)
                  0 ....... 65535
@param yval Y Data point value to be searched

Range:          0000(H) ... FFFF(H)
                  0 ....... 65535
@param idxp Pointer pointing to the location of array from which data point search is to be started */
/* ## Macro operation start [61d53553-a8d9-48b8-9ae4-14d2d811dd42] */
#define U16_IP_REL_PTR_U16_IDXP_U16(map, xval, yval, idxp)  func_u16_ip_rel_ptr_u16_idxp_u16((const uint16 *)(const void *)map, X_##map, Y_##map, xval, yval, idxp)
/* ## Macro operation end [61d53553-a8d9-48b8-9ae4-14d2d811dd42] */

/* Macro operation name: U16_IP_REL_PTR_U16_U16_IDYP */
/** This operation shall perform combined relative data point search and interpolation for 2D calibration map of type uint16 with X data point array of type uint16 and Y data point array of type uint16

Y axis shall be searched relatively

@param map Pointer to 2D calibration map
@param xval X Data point value to be searched

Range:          0000(H) ... FFFF(H)
                  0 ....... 65535
@param yval Y Data point value to be searched

Range:          0000(H) ... FFFF(H)
                  0 ....... 65535
@param idyp Pointer pointing to the location of array from which data point search is to be started */
/* ## Macro operation start [a226f9f7-cd4a-4598-8985-df0ffa98a49d] */
#define U16_IP_REL_PTR_U16_U16_IDYP(map, xval, yval, idyp)  func_u16_ip_rel_ptr_u16_u16_idyp((const uint16 *)(const void *)map, X_##map, Y_##map, xval, yval, idyp)
/* ## Macro operation end [a226f9f7-cd4a-4598-8985-df0ffa98a49d] */

/*~E*/
/*~A*/
/*~+:Private and Public Operations*/
/** This operation performs data point search for uint32 data point array and sets the structure - DPS_RESULT - elements, line_count, line_index and line_factor

@param dp_ptr :pointer to data point array
@param val :data point value to be searched
@param dps :pointer variable containing the information of interpolation length, index and factor */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern void function_udps_u32(const uint32 * dp_ptr, uint32 val, DPS_RESULT * dps);


/** This operation shall perform data point search for sint32 data point array and sets the structure - DPS_RESULT - elements, line_count, line_index and line_factor

@param dp_ptr :pointer to data point array
@param val :data point value to be searched
@param dps :pointer variable containing the information of interpolation length, index and factor */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern void function_sdps_s32(const sint32 * dp_ptr, sint32 val, DPS_RESULT * dps);


/** This operation performs interpolation for 1D calibration curve of type uint32

@param map :pointer to 1D calibration curve
@param dpsx :pointer variable containing the information of interpolation length, index and factor
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint32 function_u32_ip1d_u32(const uint32 * map, const DPS_RESULT * dpsx);


/** This operation performs interpolation for 2D calibration map of type uint32

@param map :pointer to 2D calibration map
@param dpsx :pointer variable containing the information of interpolation length, index and factor for X axis
@param dpsy :pointer variable containing the information of interpolation length, index and factor for Y axis
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint32 function_u32_ip2d_u32(const uint32 * map, const DPS_RESULT * dpsx, const DPS_RESULT * dpsy);


/** This operation performs interpolation for 3D calibration map of type uint8

@param map :pointer to 3D calibration map
@param dpsx :pointer variable containing the information of interpolation length, index and factor for X axis (dimension 1)
@param dpsy :pointer variable containing the information of interpolation length, index and factor for Y axis (dimension 2)
@param dpsz :pointer variable containing the information of interpolation length, index and factor for Z axis (dimension 3)
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint8 function_u8_ip3d_u8(const uint8 * map, const DPS_RESULT * dpsx, const DPS_RESULT * dpsy, const DPS_RESULT * dpsz);


/** This operation performs interpolation for 3D calibration map of type uint16

@param map :pointer to 3D calibration map
@param dpsx :pointer variable containing the information of interpolation length, index and factor for X axis (dimension 1)
@param dpsy :pointer variable containing the information of interpolation length, index and factor for X axis (dimension 2)
@param dpsz :pointer variable containing the information of interpolation length, index and factor for X axis (dimension 3)
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 function_u16_ip3d_u16(const uint16 * map, const DPS_RESULT * dpsx, const DPS_RESULT * dpsy, const DPS_RESULT * dpsz);


/** This operation performs interpolation for 4D calibration map of type uint8

@param map :pointer to 4D calibration map
@param dpsx_in :pointer variable containing the information of interpolation length, index and factor for inner X axis (dimension 1)
@param dpsy_in :pointer variable containing the information of interpolation length, index and factor for inner Y axis (dimension 2)
@param dpsx_out :pointer variable containing the information of interpolation length, index and factor for outer X axis (dimension 3)
@param dpsy_out :pointer variable containing the information of interpolation length, index and factor for outer Y axis (dimension 4)
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint8 function_u8_ip4d_u8(const uint8 * map, const DPS_RESULT * dpsx_in, const DPS_RESULT * dpsy_in, const DPS_RESULT * dpsx_out, const DPS_RESULT * dpsy_out);


/** This operation performs interpolation for 4D calibration map of type uint16

@param map :pointer to 4D calibration map
@param dpsx_in :pointer variable containing the information of interpolation length, index and factor for inner X axis (dimension 1)
@param dpsy_in :pointer variable containing the information of interpolation length, index and factor for inner Y axis (dimension 2)
@param dpsx_out :pointer variable containing the information of interpolation length, index and factor for outer X axis (dimension 3)
@param dpsy_out :pointer variable containing the information of interpolation length, index and factor for outer Y axis (dimension 4)
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 function_u16_ip4d_u16(const uint16 * map, const DPS_RESULT * dpsx_in, const DPS_RESULT * dpsy_in, const DPS_RESULT * dpsx_out, const DPS_RESULT * dpsy_out);


/** This operation performs interpolation for 1D calibration curve of type sint32

@param map :pointer to 1D calibration curve
@param dpsx :pointer variable containing the information of interpolation length, index and factor
@return :sint32 interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern sint32 function_s32_ip1d_s32(const sint32 * map, const DPS_RESULT * dpsx);


/** This operation performs interpolation for 2D calibration map of type sint32

@param map :pointer to 2D calibration map
@param dpsx :pointer variable containing the information of interpolation length, index and factor for X axis
@param dpsy :pointer variable containing the information of interpolation length, index and factor for Y axis
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern sint32 function_s32_ip2d_s32(const sint32 * map, const DPS_RESULT * dpsx, const DPS_RESULT * dpsy);


/** This operation performs interpolation for 3D calibration map of type sint8

@param map :pointer to 3D calibration map
@param dpsx :pointer variable containing the information of interpolation length, index and factor for X axis (dimension 1)
@param dpsy :pointer variable containing the information of interpolation length, index and factor for Y axis (dimension 2)
@param dpsz :pointer variable containing the information of interpolation length, index and factor for Z axis (dimension 3)
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern sint8 function_s8_ip3d_s8(const sint8 * map, const DPS_RESULT * dpsx, const DPS_RESULT * dpsy, const DPS_RESULT * dpsz);


/** This operation performs interpolation for 3D calibration map of type sint16

@param map :pointer to 3D calibration map
@param dpsx :pointer variable containing the information of interpolation length, index and factor for X axis (dimension 1)
@param dpsy :pointer variable containing the information of interpolation length, index and factor for Y axis (dimension 2)
@param dpsz :pointer variable containing the information of interpolation length, index and factor for Z axis (dimension 3)
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern sint16 function_s16_ip3d_s16(const sint16 * map, const DPS_RESULT * dpsx, const DPS_RESULT * dpsy, const DPS_RESULT * dpsz);


/** This operation performs interpolation for 4D calibration map of type sint8

@param map :pointer to 4D calibration map
@param dpsx_in :pointer variable containing the information of interpolation length, index and factor for inner X axis (dimension 1)
@param dpsy_in :pointer variable containing the information of interpolation length, index and factor for inner Y axis (dimension 2)
@param dpsx_out :pointer variable containing the information of interpolation length, index and factor for outer X axis (dimension 3)
@param dpsy_out :pointer variable containing the information of interpolation length, index and factor for outer Y axis (dimension 4)
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern sint8 function_s8_ip4d_s8(const sint8 * map, const DPS_RESULT * dpsx_in, const DPS_RESULT * dpsy_in, const DPS_RESULT * dpsx_out, const DPS_RESULT * dpsy_out);


/** This operation performs interpolation for 4D calibration map of type sint16

@param map :pointer to 4D calibration map
@param dpsx_in :pointer variable containing the information of interpolation length, index and factor for inner X axis (dimension 1)
@param dpsy_in :pointer variable containing the information of interpolation length, index and factor for inner Y axis (dimension 2)
@param dpsx_out :pointer variable containing the information of interpolation length, index and factor for outer X axis (dimension 3)
@param dpsy_out :pointer variable containing the information of interpolation length, index and factor for outer Y axis (dimension 4)
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern sint16 function_s16_ip4d_s16(const sint16 * map, const DPS_RESULT * dpsx_in, const DPS_RESULT * dpsy_in, const DPS_RESULT * dpsx_out, const DPS_RESULT * dpsy_out);


/** This operation performs interpolation for 1D high resolution calibration curve of type uint8 and returns the interpolated result as uint16 type

@param map :pointer to 1D calibration curve
@param dpsx :pointer variable containing the information of interpolation length, index and factor
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 function_u16_ip1d_u8(const uint8 * map, const DPS_RESULT * dpsx);


/** This operation performs interpolation for 2D high resolution calibration curve of type uint8 and returns the interpolated result as uint16 type

@param map :pointer to 2D calibration map
@param dpsx :pointer variable containing the information of interpolation length, index and factor for X axis
@param dpsy :pointer variable containing the information of interpolation length, index and factor for Y axis
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 function_u16_ip2d_u8(const uint8 * map, const DPS_RESULT * dpsx, const DPS_RESULT * dpsy);


/** This operation performs interpolation for 3D high resolution calibration curve of type uint8 and returns the interpolated result as uint16 type

@param map :pointer to 3D calibration map
@param dpsx :pointer variable containing the information of interpolation length, index and factor for X axis (dimension 1)
@param dpsy :pointer variable containing the information of interpolation length, index and factor for Y axis (dimension 2)
@param dpsz :pointer variable containing the information of interpolation length, index and factor for Z axis (dimension 3)
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 function_u16_ip3d_u8(const uint8 * map, const DPS_RESULT * dpsx, const DPS_RESULT * dpsy, const DPS_RESULT * dpsz);


/** This operation performs interpolation for 4D high resolution calibration curve of type uint8 and returns the interpolated result as uint16 type

@param map :pointer to 4D calibration map
@param dpsx_in :pointer variable containing the information of interpolation length, index and factor for inner X axis (dimension 1)
@param dpsy_in :pointer variable containing the information of interpolation length, index and factor for inner Y axis (dimension 2)
@param dpsx_out :pointer variable containing the information of interpolation length, index and factor for outer X axis (dimension 3)
@param dpsy_out :pointer variable containing the information of interpolation length, index and factor for outer Y axis (dimension 4)
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 function_u16_ip4d_u8(const uint8 * map, const DPS_RESULT * dpsx_in, const DPS_RESULT * dpsy_in, const DPS_RESULT * dpsx_out, const DPS_RESULT * dpsy_out);


/** This operation performs interpolation for 1D high resolution calibration curve of type sint8 and returns the interpolated result as sint16 type

@param map :pointer to 1D calibration curve
@param dpsx :pointer variable containing the information of interpolation length, index and factor
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern sint16 function_s16_ip1d_s8(const sint8 * map, const DPS_RESULT * dpsx);


/** This operation performs interpolation for 2D high resolution calibration curve of type sint8 and returns the interpolated result as sint16 type

@param map :pointer to 2D calibration map
@param dpsx :pointer variable containing the information of interpolation length, index and factor for X axis
@param dpsy :pointer variable containing the information of interpolation length, index and factor for Y axis
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern sint16 function_s16_ip2d_s8(const sint8 * map, const DPS_RESULT * dpsx, const DPS_RESULT * dpsy);


/** This operation performs interpolation for 3D high resolution calibration curve of type sint8 and returns the interpolated result as sint16 type

@param map :pointer to 3D calibration map
@param dpsx :pointer variable containing the information of interpolation length, index and factor for X axis (dimension 1)
@param dpsy :pointer variable containing the information of interpolation length, index and factor for Y axis (dimension 2)
@param dpsz :pointer variable containing the information of interpolation length, index and factor for Z axis (dimension 3)
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern sint16 function_s16_ip3d_s8(const sint8 * map, const DPS_RESULT * dpsx, const DPS_RESULT * dpsy, const DPS_RESULT * dpsz);


/** This operation performs interpolation for 4D high resolution calibration curve of type sint8 and returns the interpolated result as sint16 type

@param map :pointer to 4D calibration map
@param dpsx_in :pointer variable containing the information of interpolation length, index and factor for inner X axis (dimension 1)
@param dpsy_in :pointer variable containing the information of interpolation length, index and factor for inner Y axis (dimension 2)
@param dpsx_out :pointer variable containing the information of interpolation length, index and factor for outer X axis (dimension 3)
@param dpsy_out :pointer variable containing the information of interpolation length, index and factor for outer Y axis (dimension 4)
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern sint16 function_s16_ip4d_s8(const sint8 * map, const DPS_RESULT * dpsx_in, const DPS_RESULT * dpsy_in, const DPS_RESULT * dpsx_out, const DPS_RESULT * dpsy_out);


/** This operation performs interpolation for 1D high resolution calibration curve of type uint16 and returns the interpolated result as uint32 type

@param map :pointer to 1D calibration curve
@param dpsx :pointer variable containing the information of interpolation length, index and factor
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint32 function_u32_ip1d_u16(const uint16 * map, const DPS_RESULT * dpsx);


/** This operation performs interpolation for 2D high resolution calibration curve of type uint16 and returns the interpolated result as uint32 type

@param map :pointer to 2D calibration map
@param dpsx :pointer variable containing the information of interpolation length, index and factor for X axis
@param dpsy :pointer variable containing the information of interpolation length, index and factor for Y axis
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint32 function_u32_ip2d_u16(const uint16 * map, const DPS_RESULT * dpsx, const DPS_RESULT * dpsy);


/** This operation performs interpolation for 3D high resolution calibration curve of type uint16 and returns the interpolated result as uint32 type

@param map :pointer to 3D calibration map
@param dpsx :pointer variable containing the information of interpolation length, index and factor for X axis (dimension 1)
@param dpsy :pointer variable containing the information of interpolation length, index and factor for Y axis (dimension 2)
@param dpsz :pointer variable containing the information of interpolation length, index and factor for Z axis (dimension 3)
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint32 function_u32_ip3d_u16(const uint16 * map, const DPS_RESULT * dpsx, const DPS_RESULT * dpsy, const DPS_RESULT * dpsz);


/** This operation performs interpolation for 4D high resolution calibration curve of type uint16 and returns the interpolated result as uint32 type

@param map :pointer to 4D calibration map
@param dpsx_in :pointer variable containing the information of interpolation length, index and factor for inner X axis (dimension 1)
@param dpsy_in :pointer variable containing the information of interpolation length, index and factor for inner Y axis (dimension 2)
@param dpsx_out :pointer variable containing the information of interpolation length, index and factor for outer X axis (dimension 3)
@param dpsy_out :pointer variable containing the information of interpolation length, index and factor for outer Y axis (dimension 4)
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint32 function_u32_ip4d_u16(const uint16 * map, const DPS_RESULT * dpsx_in, const DPS_RESULT * dpsy_in, const DPS_RESULT * dpsx_out, const DPS_RESULT * dpsy_out);


/** This operation performs interpolation for 1D high resolution calibration curve of type sint16 and returns the interpolated result as sint32 type

@param map :pointer to 1D calibration curve
@param dpsx :pointer variable containing the information of interpolation length, index and factor
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern sint32 function_s32_ip1d_s16(const sint16 * map, const DPS_RESULT * dpsx);


/** This operation performs interpolation for 2D high resolution calibration curve of type sint16 and returns the interpolated result as sint32 type

@param map :pointer to 2D calibration map
@param dpsx :pointer variable containing the information of interpolation length, index and factor for X axis
@param dpsy :pointer variable containing the information of interpolation length, index and factor for Y axis
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern sint32 function_s32_ip2d_s16(const sint16 * map, const DPS_RESULT * dpsx, const DPS_RESULT * dpsy);


/** This operation performs interpolation for 3D high resolution calibration curve of type sint16 and returns the interpolated result as sint32 type

@param map :pointer to 3D calibration map
@param dpsx :pointer variable containing the information of interpolation length, index and factor for X axis (dimension 1)
@param dpsy :pointer variable containing the information of interpolation length, index and factor for Y axis (dimension 2)
@param dpsz :pointer variable containing the information of interpolation length, index and factor for Z axis (dimension 3)
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern sint32 function_s32_ip3d_s16(const sint16 * map, const DPS_RESULT * dpsx, const DPS_RESULT * dpsy, const DPS_RESULT * dpsz);


/** This operation performs interpolation for 4D high resolution calibration curve of type sint16 and returns the interpolated result as sint32 type

@param map :pointer to 4D calibration map
@param dpsx_in :pointer variable containing the information of interpolation length, index and factor for inner X axis (dimension 1)
@param dpsy_in :pointer variable containing the information of interpolation length, index and factor for inner Y axis (dimension 2)
@param dpsx_out :pointer variable containing the information of interpolation length, index and factor for outer X axis (dimension 3)
@param dpsy_out :pointer variable containing the information of interpolation length, index and factor for outer Y axis (dimension 4)
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern sint32 function_s32_ip4d_s16(const sint16 * map, const DPS_RESULT * dpsx_in, const DPS_RESULT * dpsy_in, const DPS_RESULT * dpsx_out, const DPS_RESULT * dpsy_out);


/** This operation performs interpolation of calibration curve of type uint8 with equidistant data point steps.

@param map :pointer to 1D calibration curve
@param step_address :pointer to step address of Data point array
@param val :data point value to be searched
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint8 function_u8_ip1da_ptr_u8(const uint8 * map, const uint8 * step_address, uint8 val);


/** This operation performs interpolation of calibration map of type uint8 with equidistant data point steps.

@param map :pointer to 2D calibration map
@param step_address :pointer to step address of data point arrays
@param val1 :X data point array value to be searched
@param val2 :Y data point array value to be searched
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint8 function_u8_ip2da_ptr_u8(const uint8 * map, const uint8 * step_address, uint8 val1, uint8 val2);


/** This operation determines table index for the given data point value in the given data point array of type uint8

@param dp_ptr :pointer to data point array
@param val :Data point value to be searched
@param dps :pointer variable which sets table index inside DPS_RESULT */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern void function_uids_u8(const uint8 * dp_ptr, uint8 val, DPS_RESULT * dps);


/** This operation determines table index for the given data point value in the given data point array of type uint16

@param dp_ptr :pointer to data point array
@param val :Data point value to be searched
@param dps :pointer variable which sets table index inside DPS_RESULT */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern void function_uids_u16(const uint16 * dp_ptr, uint16 val, DPS_RESULT * dps);


/** This operation determines table index for the given data point value in the given data point array of type sint8

@param dp_ptr :pointer to data point array
@param val :Data point value to be searched
@param dps :pointer variable which sets table index inside DPS_RESULT */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern void function_sids_s8(const sint8 * dp_ptr, sint8 val, DPS_RESULT * dps);


/** This operation determines table index for the given data point value in the given data point array of type sint16

@param dp_ptr :pointer to data point array
@param val :Data point value to be searched
@param dps :pointer variable which sets table index inside DPS_RESULT */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern void function_sids_s16(const sint16 * dp_ptr, sint16 val, DPS_RESULT * dps);


/** This operation determines table value for the given 2D table of type uint8 using the table indeces of the axis searched by the search routines

@param ptr :Pointer to 2D calibration table
@param dpsx :Pointer variable containing the information of table length and index for X aixs
@param dpsy :Pointer variable containing the information of table length and index for Y axis
@return :Table value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint8 function_u8_id2d_u8(const uint8 * ptr, const DPS_RESULT * dpsx, const DPS_RESULT * dpsy);


/** This operation determines table value for the given 2D table of type uint16 using the table indeces of the axis searched by the search routines

@param ptr :Pointer to 2D calibration table
@param dpsx :Pointer variable containing the information of table length and index for X axis
@param dpsy :Pointer variable containing the information of table length and index for Y axis
@return :Table value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 function_u16_id2d_u16(const uint16 * ptr, const DPS_RESULT * dpsx, const DPS_RESULT * dpsy);


/** This operation determines table value for the given 1D table of type uint8 with equidistant data point steps

@param ptr :pointer to 1D calibration table
@param step_address :pointer to step address of data point array
@param val :data point value to be searched
@return :Table value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint8 function_u8_id1da_ptr_u8(const uint8 * ptr, const uint8 * step_address, uint8 val);


/** This operation performs combined data point search and interpolation for 1D calibration curve of type uint8 and data point array of type uint8

@param ptr_map :Pointer to 1D calibration curve
@param dp_ptr :pointer to data point array
@param xval :Data point value to be searched
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint8 function_u8_ip_ptr_u8(const uint8 * ptr_map, const uint8 * dp_ptr, uint8 xval);


/** This operation performs combined data point search and interpolation for 1D calibration curve of type uint8 and data point array of type uint16

@param ptr_map :Pointer to 1D calibration curve
@param dp_ptr :pointer to data point array
@param xval :Data point value to be searched
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint8 function_u8_ip_ptr_u16(const uint8 * ptr_map, const uint16 * dp_ptr, uint16 xval);


/** This operation performs combined data point search and interpolation for 1D calibration curve of type uint16 and data point array of type uint8

@param ptr_map :Pointer to 1D calibration curve
@param dp_ptr :pointer to data point array
@param xval :Data point value to be searched
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 function_u16_ip_ptr_u8(const uint16 * ptr_map, const uint8 * dp_ptr, uint8 xval);


/** This operation performs combined data point search and interpolation for 1D calibration curve of type uint16 and data point array of type uint16

@param ptr_map :Pointer to 1D calibration curve
@param dp_ptr :pointer to data point array
@param xval :Data point value to be searched
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 function_u16_ip_ptr_u16(const uint16 * ptr_map, const uint16 * dp_ptr, uint16 xval);


/** This operation performs combined data point search and interpolation for 2D calibration map of type uint8 and X data point array of type uint8 and Y data point array of type uint8

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint8 function_u8_ip_ptr_u8_u8(const uint8 * ptr_map, const uint8 * xdp_ptr, const uint8 * ydp_ptr, uint8 xval, uint8 yval);


/** This operation performs combined data point search and interpolation for 2D calibration map of type uint8 and X data point array of type uint8 and Y data point array of type uint16

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint8 function_u8_ip_ptr_u8_u16(const uint8 * ptr_map, const uint8 * xdp_ptr, const uint16 * ydp_ptr, uint8 xval, uint16 yval);


/** This operation performs combined data point search and interpolation for 2D calibration map of type uint8 and X data point array of type uint16 and Y data point array of type uint8

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint8 function_u8_ip_ptr_u16_u8(const uint8 * ptr_map, const uint16 * xdp_ptr, const uint8 * ydp_ptr, uint16 xval, uint8 yval);


/** This operation performs combined data point search and interpolation for 2D calibration map of type uint8 and X data point array of type uint16 and Y data point array of type uint16

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint8 function_u8_ip_ptr_u16_u16(const uint8 * ptr_map, const uint16 * xdp_ptr, const uint16 * ydp_ptr, uint16 xval, uint16 yval);


/** This operation performs combined data point search and interpolation for 2D calibration map of type uint16 and X data point array of type uint8 and Y data point array of type uint8

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 function_u16_ip_ptr_u8_u8(const uint16 * ptr_map, const uint8 * xdp_ptr, const uint8 * ydp_ptr, uint8 xval, uint8 yval);


/** This operation performs combined data point search and interpolation for 2D calibration map of type uint16 and X data point array of type uint8 and Y data point array of type uint16

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 function_u16_ip_ptr_u8_u16(const uint16 * ptr_map, const uint8 * xdp_ptr, const uint16 * ydp_ptr, uint8 xval, uint16 yval);


/** This operation performs combined data point search and interpolation for 2D calibration map of type uint16 and X data point array of type uint16 and Y data point array of type uint8

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 function_u16_ip_ptr_u16_u8(const uint16 * ptr_map, const uint16 * xdp_ptr, const uint8 * ydp_ptr, uint16 xval, uint8 yval);


/** This operation performs combined data point search and interpolation for 2D calibration map of type uint16 and X data point array of type uint16 and Y data point array of type uint16

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 function_u16_ip_ptr_u16_u16(const uint16 * ptr_map, const uint16 * xdp_ptr, const uint16 * ydp_ptr, uint16 xval, uint16 yval);


/** This operation performs combined data point search and interpolation for 2D calibration map of type uint32 and X data point array of type uint8 and Y data point array of type uint16

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint32 function_u32_ip_ptr_u8_u16(const uint32 * ptr_map, const uint8 * xdp_ptr, const uint16 * ydp_ptr, uint8 xval, uint16 yval);


/** This operation performs combined data point search and interpolation for 2D calibration map of type uint32 and X data point array of type uint16 and Y data point array of type uint16

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint32 function_u32_ip_ptr_u16_u16(const uint32 * ptr_map, const uint16 * xdp_ptr, const uint16 * ydp_ptr, uint16 xval, uint16 yval);


/** This operation performs combined relative data point search and interpolation for 1D calibration curve of type uint8 and data point array of type uint8

@param ptr_map :Pointer to 1D calibration curve
@param dp_ptr :pointer to data point array
@param xval :Data point value to be searched
@param idxp :Pointer pointing to the location of array from which data point search has to be started
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint8 function_u8_ip_rel_ptr_u8_idxp(const uint8 * ptr_map, const uint8 * dp_ptr, uint8 xval, uint8 * idxp);


/** This operation performs combined relative data point search and interpolation for 1D calibration curve of type uint8 and data point array of type uint16

@param ptr_map :Pointer to 1D calibration curve
@param dp_ptr :pointer to data pointer array
@param xval :Data point value to be searched
@param idxp :Pointer pointing to the location of array from which data point search has to be started
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint8 function_u8_ip_rel_ptr_u16_idxp(const uint8 * ptr_map, const uint16 * dp_ptr, uint16 xval, uint8 * idxp);


/** This operation performs combined relative data point search and interpolation for 1D calibration curve of type uint16 and data point array of type uint8

@param ptr_map :Pointer to 1D calibration curve
@param dp_ptr :pointer to data point array
@param xval :Data point value to be searched
@param idxp :Pointer pointing to the location of array from which data point search has to be started
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 function_u16_ip_rel_ptr_u8_idxp(const uint16 * ptr_map, const uint8 * dp_ptr, uint8 xval, uint8 * idxp);


/** This operation performs combined relative data point search and interpolation for 1D calibration curve of type uint16 and data point array of type uint16

@param ptr_map :Pointer to 1D calibration curve
@param dp_ptr :pointer to data point array
@param xval :Data point value to be searched
@param idxp :Pointer pointing to the location of array from which data point search has to be started
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 function_u16_ip_rel_ptr_u16_idxp(const uint16 * ptr_map, const uint16 * dp_ptr, uint16 xval, uint8 * idxp);


/** This operation performs combined relative data point search and interpolation for 2D calibration map of type uint8 with X data point array of type uint8 and Y data point array of type uint8
X axis shall be searched relatively

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@param idxp :Pointer pointing to the location of X data point array from which data point search has to be started
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint8 func_u8_ip_rel_ptr_u8_idxp_u8(const uint8 * ptr_map, const uint8 * xdp_ptr, const uint8 * ydp_ptr, uint8 xval, uint8 yval, uint8 * idxp);


/** This operation performs combined relative data point search and interpolation for 2D calibration map of type uint8 with X data point array of type uint8 and Y data point array of type uint8
Y axis shall be searched relatively

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@param idyp :Pointer pointing to the location of array from which data point search has to be started
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint8 func_u8_ip_rel_ptr_u8_u8_idyp(const uint8 * ptr_map, const uint8 * xdp_ptr, const uint8 * ydp_ptr, uint8 xval, uint8 yval, uint8 * idyp);


/** This operation performs combined relative data point search and interpolation for 2D calibration map of type uint8 with X data point array of type uint16 and Y data point array of type uint8
X axis shall be searched relatively

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@param idxp :Pointer pointing to the location of array from which data point search has to be started
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint8 func_u8_ip_rel_ptr_u16_idxp_u8(const uint8 * ptr_map, const uint16 * xdp_ptr, const uint8 * ydp_ptr, uint16 xval, uint8 yval, uint8 * idxp);


/** This operation performs combined relative data point search and interpolation for 2D calibration map of type uint8 with X data point array of type uint16 and Y data point array of type uint8
Y axis shall be searched relatively

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@param idyp :Pointer pointing to the location of array from which data point search has to be started
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint8 func_u8_ip_rel_ptr_u16_u8_idyp(const uint8 * ptr_map, const uint16 * xdp_ptr, const uint8 * ydp_ptr, uint16 xval, uint8 yval, uint8 * idyp);


/** This operation performs combined relative data point search and interpolation for 2D calibration map of type uint8 with X data point array of type uint8 and Y data point array of type uint16
X axis shall be searched relatively

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@param idxp :Pointer pointing to the location of array from which data point search has to be started
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint8 func_u8_ip_rel_ptr_u8_idxp_u16(const uint8 * ptr_map, const uint8 * xdp_ptr, const uint16 * ydp_ptr, uint8 xval, uint16 yval, uint8 * idxp);


/** This operation performs combined relative data point search and interpolation for 2D calibration map of type uint8 with X data point array of type uint8 and Y data point array of type uint16
Y axis shall be searched relatively

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@param idyp :Pointer pointing to the location of array from which data point search has to be started
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint8 func_u8_ip_rel_ptr_u8_u16_idyp(const uint8 * ptr_map, const uint8 * xdp_ptr, const uint16 * ydp_ptr, uint8 xval, uint16 yval, uint8 * idyp);


/** This operation performs combined relative data point search and interpolation for 2D calibration map of type uint8 with X data point array of type uint16 and Y data point array of type uint16
X axis shall be searched relatively

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@param idxp :Pointer pointing to the location of array from which data point search has to be started
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint8 func_u8_ip_rel_ptr_u16_idxp_u16(const uint8 * ptr_map, const uint16 * xdp_ptr, const uint16 * ydp_ptr, uint16 xval, uint16 yval, uint8 * idxp);


/** This operation performs combined relative data point search and interpolation for 2D calibration map of type uint8 with X data point array of type uint16 and Y data point array of type uint16
Y axis shall be searched relatively

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@param idyp :Pointer pointing to the location of array from which data point search has to be started
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint8 func_u8_ip_rel_ptr_u16_u16_idyp(const uint8 * ptr_map, const uint16 * xdp_ptr, const uint16 * ydp_ptr, uint16 xval, uint16 yval, uint8 * idyp);


/** This operation performs combined relative data point search and interpolation for 2D calibration map of type uint16 with X data point array of type uint8 and Y data point array of type uint8
X axis shall be searched relatively

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@param idxp :Pointer pointing to the location of array from which data point search has to be started
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 func_u16_ip_rel_ptr_u8_idxp_u8(const uint16 * ptr_map, const uint8 * xdp_ptr, const uint8 * ydp_ptr, uint8 xval, uint8 yval, uint8 * idxp);


/** This operation performs combined relative data point search and interpolation for 2D calibration map of type uint16 with X data point array of type uint8 and Y data point array of type uint8
Y axis shall be searched relatively

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@param idyp :Pointer pointing to the location of array from which data point search is to be started
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 func_u16_ip_rel_ptr_u8_u8_idyp(const uint16 * ptr_map, const uint8 * xdp_ptr, const uint8 * ydp_ptr, uint8 xval, uint8 yval, uint8 * idyp);


/** This operation performs combined relative data point search and interpolation for 2D calibration map of type uint16 with X data point array of type uint16 and Y data point array of type uint8
X axis shall be searched relatively

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@param idxp :Pointer pointing to the location of array from which data point search is to be started
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 func_u16_ip_rel_ptr_u16_idxp_u8(const uint16 * ptr_map, const uint16 * xdp_ptr, const uint8 * ydp_ptr, uint16 xval, uint8 yval, uint8 * idxp);


/** This operation performs combined relative data point search and interpolation for 2D calibration map of type uint16 with X data point array of type uint16 and Y data point array of type uint8
Y axis shall be searched relatively

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@param idyp :Pointer pointing to the location of array from which data point search is to be started
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 func_u16_ip_rel_ptr_u16_u8_idyp(const uint16 * ptr_map, const uint16 * xdp_ptr, const uint8 * ydp_ptr, uint16 xval, uint8 yval, uint8 * idyp);


/** This operation performs combined relative data point search and interpolation for 2D calibration map of type uint16 with X data point array of type uint8 and Y data point array of type uint16
X axis shall be searched relatively

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@param idxp :Pointer pointing to the location of array from which data point search is to be started
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 func_u16_ip_rel_ptr_u8_idxp_u16(const uint16 * ptr_map, const uint8 * xdp_ptr, const uint16 * ydp_ptr, uint8 xval, uint16 yval, uint8 * idxp);


/** This operation performs combined relative data point search and interpolation for 2D calibration map of type uint16 with X data point array of type uint8 and Y data point array of type uint16
Y axis shall be searched relatively

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@param idyp :Pointer pointing to the location of array from which data point search is to be started
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 func_u16_ip_rel_ptr_u8_u16_idyp(const uint16 * ptr_map, const uint8 * xdp_ptr, const uint16 * ydp_ptr, uint8 xval, uint16 yval, uint8 * idyp);


/** This operation performs combined relative data point search and interpolation for 2D calibration map of type uint16 with X data point array of type uint16 and Y data point array of type uint16
X axis shall be searched relatively

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@param idxp :Pointer pointing to the location of array from which data point search is to be started
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 func_u16_ip_rel_ptr_u16_idxp_u16(const uint16 * ptr_map, const uint16 * xdp_ptr, const uint16 * ydp_ptr, uint16 xval, uint16 yval, uint8 * idxp);


/** This operation performs combined relative data point search and interpolation for 2D calibration map of type uint16 with X data point array of type uint16 and Y data point array of type uint16
Y axis shall be searched relatively

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@param idyp :Pointer pointing to the location of array from which data point search is to be started
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 func_u16_ip_rel_ptr_u16_u16_idyp(const uint16 * ptr_map, const uint16 * xdp_ptr, const uint16 * ydp_ptr, uint16 xval, uint16 yval, uint8 * idyp);


/** This operation performs combined data point search and table value determination for 1D calibration curve of type uint8 and data point array of type uint8

@param ptr_map :Pointer to 1D calibration curve
@param dp_ptr :pointer to data point array
@param xval :Data point value to be searched
@return :Table value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint8 function_u8_id_ptr_u8(const uint8 * ptr_map, const uint8 * dp_ptr, uint8 xval);


/** This operation performs combined data point search and table value determination for 1D calibration curve of type uint8 and data point array of type uint16

@param ptr_map :Pointer to 1D calibration curve
@param dp_ptr :pointer to data point array
@param xval :Data point value to be searched
@return :Table value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint8 function_u8_id_ptr_u16(const uint8 * ptr_map, const uint16 * dp_ptr, uint16 xval);


/** This operation performs combined data point search and table value determination for 1D calibration curve of type uint16 and data point array of type uint8

@param ptr_map :Pointer to 1D calibration curve
@param dp_ptr :pointer to data point array
@param xval :Data point value to be searched
@return :Table value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 function_u16_id_ptr_u8(const uint16 * ptr_map, const uint8 * dp_ptr, uint8 xval);


/** This operation performs combined data point search and table value determination for 1D calibration curve of type uint16 and data point array of type uint16

@param ptr_map :Pointer to 1D calibration curve
@param dp_ptr :pointer to data point array
@param xval :Data point value to be searched
@return :Table value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 function_u16_id_ptr_u16(const uint16 * ptr_map, const uint16 * dp_ptr, uint16 xval);


/** This operation performs combined data point search and table value determination for 2D calibration map of type uint8 with X data point array of type uint8 and Y data point array of type uint8

@param ptr_map :Pointer to 2D Calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@return :Table value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint8 function_u8_id_ptr_u8_u8(const uint8 * ptr_map, const uint8 * xdp_ptr, const uint8 * ydp_ptr, uint8 xval, uint8 yval);


/** This operation performs combined data point search and table value determination for 2D calibration map of type uint8 with X data point array of type uint8 and Y data point array of type uint16

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@return :Table value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint8 function_u8_id_ptr_u8_u16(const uint8 * ptr_map, const uint8 * xdp_ptr, const uint16 * ydp_ptr, uint8 xval, uint16 yval);


/** This operation performs combined data point search and table value determination for 2D calibration map of type uint8 with X data point array of type uint16 and Y data point array of type uint8

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@return :Table value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint8 function_u8_id_ptr_u16_u8(const uint8 * ptr_map, const uint16 * xdp_ptr, const uint8 * ydp_ptr, uint16 xval, uint8 yval);


/** This operation performs combined data point search and table value determination for 2D calibration map of type uint8 with X data point array of type uint16 and Y data point array of type uint16

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@return :Table value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint8 function_u8_id_ptr_u16_u16(const uint8 * ptr_map, const uint16 * xdp_ptr, const uint16 * ydp_ptr, uint16 xval, uint16 yval);


/** This operation performs combined data point search and table value determination for 2D calibration map of type uint16 with X data point array of type uint8 and Y data point array of type uint8

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@return :Table value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 function_u16_id_ptr_u8_u8(const uint16 * ptr_map, const uint8 * xdp_ptr, const uint8 * ydp_ptr, uint8 xval, uint8 yval);


/** This operation performs combined data point search and table value determination for 2D calibration map of type uint16 with X data point array of type uint8 and Y data point array of type uint16

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@return :Table value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 function_u16_id_ptr_u8_u16(const uint16 * ptr_map, const uint8 * xdp_ptr, const uint16 * ydp_ptr, uint8 xval, uint16 yval);


/** This operation performs combined data point search and table value determination for 2D calibration map of type uint16 with X data point array of type uint16 and Y data point array of type uint8

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@return :Table value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 function_u16_id_ptr_u16_u8(const uint16 * ptr_map, const uint16 * xdp_ptr, const uint8 * ydp_ptr, uint16 xval, uint8 yval);


/** This operation performs combined data point search and table value determination for 2D calibration map of type uint16 with X data point array of type uint16 and Y data point array of type uint16

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@return :Table value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 function_u16_id_ptr_u16_u16(const uint16 * ptr_map, const uint16 * xdp_ptr, const uint16 * ydp_ptr, uint16 xval, uint16 yval);


/** This operation performs inverse interpolation of calibration map of type uint8 where x data point array value of type uint8 is given and y data point array value has to be determined

@param x_ptr :pointer to X data point array
@param y_ptr :pointer to Y data point array
@param z_ptr Pointer to 2D calibration map for which inverse interpolation has to be done
@param x_val :X data point array value
@param z_val :map value
@param x1 :pointer to x relative index
@param y1 :pointer to y relative index
@return :Result of inverse interpolation i.e. y value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint8 function_u8_y_inv_ip_ptr_u8_u8(const uint8 * x_ptr, const uint8 * y_ptr, const uint8 * z_ptr, uint8 x_val, uint8 z_val, uint8 * x1, uint8 * y1);


/** This operation performs inverse interpolation of calibration map of type uint8 where y data point array value of type uint8 is given and x data point array value has to be determined

@param x_ptr :pointer to X data point array
@param y_ptr :pointer to Y data point array
@param z_ptr :Pointer to 2D calibration map for which inverse interpolation has to be done
@param y_val :Y data point array value
@param z_val :map value
@param x1 :pointer to x relative index
@param y1 pointer to y relative index
@return :Result of inverse interpolation i.e. x value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint8 function_u8_x_inv_ip_ptr_u8_u8(const uint8 * x_ptr, const uint8 * y_ptr, const uint8 * z_ptr, uint8 y_val, uint8 z_val, uint8 * x1, uint8 * y1);


/** This operation performs inverse interpolation of calibration map of type uint16 where x data point array value is given and y data point array value has to be determined

@param x_ptr :pointer to X data point array
@param y_ptr :pointer to Y data point array
@param z_ptr :Pointer to 2D calibration map for which inverse interpolation has to be done
@param x_val :X data point array value
@param z_val :map value
@param x1 :pointer to x relative index
@param y1 pointer to y relative index
@return :Result of inverse interpolation i.e. y value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 function_u16_y_inv_ip_ptr_u16_u16(const uint16 * x_ptr, const uint16 * y_ptr, const uint16 * z_ptr, uint16 x_val, uint16 z_val, uint8 * x1, uint8 * y1);


/** This operation performs inverse interpolation of calibration map of type uint16 where y data point array value is given and x data point array value has to be determined

@param x_ptr :pointer to X data point array
@param y_ptr :pointer to Y data point array
@param z_ptr :Pointer to 2D calibration map for which inverse interpolation has to be done
@param y_val :Y data point array value
@param z_val :map value
@param x1 :pointer to x relative index
@param y1 pointer to y relative index
@return :Result of inverse interpolation i.e. x value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 function_u16_x_inv_ip_ptr_u16_u16(const uint16 * x_ptr, const uint16 * y_ptr, const uint16 * z_ptr, uint16 y_val, uint16 z_val, uint8 * x1, uint8 * y1);


/** This operation performs data point search for uint8 data point array and sets the structure - DPS_RESULT - elements, line_count, line_index and line_factor

@param dp_ptr :pointer to data point array
@param val :data point value to be searched
@param dps :pointer variable containing the information of interpolation length, index and factor */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern void function_udps_u8(const uint8 * dp_ptr, uint8 val, DPS_RESULT * dps);


/** This operation performs data point search for uint16 data point array and sets the structure - DPS_RESULT - elements, line_count, line_index and line_factor

@param dp_ptr :pointer to data point array
@param val :data point value to be searched
@param dps :pointer variable containing the information of interpolation length, index and factor */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern void function_udps_u16(const uint16 * dp_ptr, uint16 val, DPS_RESULT * dps);


/** This operation shall perform data point search for sint8 data point array and sets the structure - DPS_RESULT - elements, line_count, line_index and line_factor

@param dp_ptr :pointer to data point array
@param val :data point value to be searched
@param dps :pointer variable containing the information of interpolation length, index and factor */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern void function_sdps_s8(const sint8 * dp_ptr, sint8 val, DPS_RESULT * dps);


/** This operation shall perform data point search for sint16 data point array and sets the structure - DPS_RESULT - elements, line_count, line_index and line_factor

@param dp_ptr :pointer to data point array
@param val :data point value to be searched
@param dps :pointer variable containing the information of interpolation length, index and factor */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern void function_sdps_s16(const sint16 * dp_ptr, sint16 val, DPS_RESULT * dps);


/** This operation performs interpolation for 1D calibration curve of type uint8

@param map :pointer to 1D calibration curve
@param dpsx :pointer variable containing the information of interpolation length, index and factor
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint8 function_u8_ip1d_u8(const uint8 * map, const DPS_RESULT * dpsx);


/** This operation performs interpolation for 1D calibration curve of type uint16

@param map :pointer to 1D calibration curve
@param dpsx :pointer variable containing the information of interpolation length, index and factor
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 function_u16_ip1d_u16(const uint16 * map, const DPS_RESULT * dpsx);


/** This operation performs interpolation for 2D calibration map of type uint8

@param map :pointer to 2D calibration map
@param dpsx :pointer variable containing the information of interpolation length, index and factor for X axis
@param dpsy :pointer variable containing the information of interpolation length, index and factor for Y axis
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint8 function_u8_ip2d_u8(const uint8 * map, const DPS_RESULT * dpsx, const DPS_RESULT * dpsy);


/** This operation performs interpolation for 2D calibration map of type uint16

@param map :pointer to 2D calibration map
@param dpsx :pointer variable containing the information of interpolation length, index and factor for X axis
@param dpsy :pointer variable containing the information of interpolation length, index and factor for Y axis
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 function_u16_ip2d_u16(const uint16 * map, const DPS_RESULT * dpsx, const DPS_RESULT * dpsy);


/** This operation performs interpolation for 1D calibration curve of type sint8

@param map :pointer to 1D calibration curve
@param dpsx :pointer variable containing the information of interpolation length, index and factor
@return :sint32 interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern sint8 function_s8_ip1d_s8(const sint8 * map, const DPS_RESULT * dpsx);


/** This operation performs interpolation for 2D calibration map of type sint8

@param map :pointer to 2D calibration map
@param dpsx :pointer variable containing the information of interpolation length, index and factor for X axis
@param dpsy :pointer variable containing the information of interpolation length, index and factor for Y axis
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern sint8 function_s8_ip2d_s8(const sint8 * map, const DPS_RESULT * dpsx, const DPS_RESULT * dpsy);


/** This operation performs interpolation for 1D calibration curve of type sint16

@param map :pointer to 1D calibration curve
@param dpsx :pointer variable containing the information of interpolation length, index and factor
@return :sint32 interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern sint16 function_s16_ip1d_s16(const sint16 * map, const DPS_RESULT * dpsx);


/** This operation performs interpolation for 2D calibration map of type sint16

@param map :pointer to 2D calibration map
@param dpsx :pointer variable containing the information of interpolation length, index and factor for X axis
@param dpsy :pointer variable containing the information of interpolation length, index and factor for Y axis
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern sint16 function_s16_ip2d_s16(const sint16 * map, const DPS_RESULT * dpsx, const DPS_RESULT * dpsy);


/*~E*/
#include "iopt_memmap.h"
#endif
