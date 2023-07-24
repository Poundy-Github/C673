/*~A*/
/*~+:VM Header*/
/* UML source model state: Draft */
/* ## Module Header Start [72adbf33-d1f8-42a3-b1e0-7559fa94f92b] */
/****************************************************************************

COPYRIGHT (C) $Date: 2019/07/03 13:44:19CEST $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.                                                 

The reproduction, transmission or use of this document or its contents is  
not permitted without express written authority.                           
Offenders will be liable for damages. All rights, including rights created 
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------

$Log: f32_calm_main.c  $
Revision 1.1 2019/07/03 13:44:19CEST Nastasa, Elena (uidt4846) 
Initial revision
Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/Common/SDA/project.pj
Revision 1.1 2018/07/24 16:49:19CEST Ammermueller Martin (uidv5342) (uidv5342) 
Initial revision
Member added to project /ES/1T/0C/SDA/SDA_Source/SDA_Toolboxes/ACG/Libraries/calm_f32/Src/3_1_0/project.pj
Revision 1.3 2018/03/06 08:04:14CET Angadi Hampa (uidu8151) (uidu8151) 
RO : 8197570 : MISRA2012 ANSI VERSIONS
Revision 1.14 2018/01/29 02:58:13CET Angadi Hampa (uidu8151) (uidu8151) 
For TC39xb validation & New LINT correction (9029)
Revision 1.13 2017/08/16 12:16:18CEST Ugran Parimala (uid41586) (uid41586) 
Newly added functions to F32_Calm
Revision 1.12 2017/08/07 14:40:46CEST Ugran Parimala (uid41586) (uid41586) 
Adding new Functions to F32_CALM
Revision 1.10 2017/06/21 11:32:48CEST Ugran Parimala (uid41586) (uid41586) 
Rework MISRA2012
Revision 1.8 2017/05/08 12:19:56CEST Angadi Hampa (uidu8151) (uidu8151) 
MISRA 2012
Revision 1.7 2015/12/17 08:16:39CET Adinarayanagowda Pruthviraj (uidp1961) (uidp1961) 
RO: 2877060 , Review updates
Revision 1.5 2013/08/22 08:39:46CEST Angadi Hampa (uidu8151) (uidu8151) 
for release RO 429670 :FS_0G01_TC2XX_F32CALM_100
Revision 1.4 2013/08/08 16:11:31IST Mahajan Abhishek (uidm3525) (uidm3525) 
RO 429670 :FS_0G01_TC2XX_F32CALM_100  Description file name correction in MKS
Revision 1.3 2013/08/08 12:35:56CEST Mahajan Abhishek (uidm3525) (uidm3525) 
Member renamed from f32_calm.c_code to f32_calm_main.c in project /ES/FS/0A/bsw/stdlib/f32_calm/pd_tc2xx/i/project.pj.
Revision 1.2 2013/08/05 05:06:07CEST Angadi Hampa (uidu8151) (uidu8151) 
429670 :FS_0G01_TC2XX_F32CALM_100  Description Correction
Revision 1.1 2013/08/01 08:11:54IST Angadi Hampa (uidu8151) (uidu8151) 
Initial revision
Member added to project /ES/FS/0D/bsw/stdlib/tc2xx/f32_calm/src_pd/i/project.pj
Revision 1.1 2013/07/30 16:53:15IST Angadi Hampa (uidu8151) (uidu8151) 
Initial revision
Member added to project /ES/FS/0D/bsw/stdlib/tc2xx/f32_calm/src_pd/i/project.pj
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
/* ## Module Header End [72adbf33-d1f8-42a3-b1e0-7559fa94f92b] */

/*~E*/
/*~A*/
/*~+:Includes*/
#include "Std_Types.h"
#include "powersar_addon_types.h"
#include "iopt_memmap.h"
#include "f32_calm_main.h"
/*~E*/
/*~A*/
/*~+:Lint Supressions*/
/*lint --e{9016} */
/*lint --e{9033} */
/*lint --e{9078} */
/*lint --e{923} */
/*~E*/
/*~A*/
/*~+:Private Function Prototypes*/
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

static float32 function_f32_interpolate_f32(const float32 * ip_ptr, const FDPS_RESULT x, const FDPS_RESULT y);


#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

static float32 function_f32_interpolate_u16(const uint16 * ip_ptr, const FDPS_RESULT x, const FDPS_RESULT y);


#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

static float32 function_f32_interpolate_u8(const uint8 * ip_ptr, const FDPS_RESULT x, const FDPS_RESULT y);


#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

static float32 function_f32_interpolate_s8(const sint8 * ip_ptr, const FDPS_RESULT x, const FDPS_RESULT y);


#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

static float32 function_f32_interpolate_s16(const sint16 * ip_ptr, const FDPS_RESULT x, const FDPS_RESULT y);


/*~E*/
/*~A*/
/*~+:Private Functions*/
/*~T*/

/*~T*/
/** This operation shall performs the 3D interpolation operation.

@param ip_ptr Pointer to map
@param x Pointer to structure FDPS_RESULT for x axis
@param y Pointer to structure FDPS_RESULT for y axis
@return Returns float32 value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

static float32 function_f32_interpolate_f32(const float32 * ip_ptr, const FDPS_RESULT x, const FDPS_RESULT y)
{
	/* ## Operation body start [fc26b9c3-7394-4868-b4f1-633ed5e4ffc0] */
	uint8    num_col, x_idx, y_idx;
	const float32 *ptr;
	float32   ip1, ip2, ip, x_fac, y_fac;

	num_col = y.line_count;
	x_idx   = x.line_index;
	y_idx   = y.line_index;
	x_fac   = x.line_factor;
	y_fac   = y.line_factor;
	ptr = ip_ptr + ((x_idx * num_col) + y_idx); 
	if (x_fac > 0.0f)
	{
		if (y_fac > 0.0f)
		{
			/*both column and line interpolation*/
			ip1 = *(ptr + 1); 
			ip = (ip1 * y_fac) - (*ptr * y_fac);
			ip1 = (*ptr + ip);
			ptr += num_col; 
			ip2 = *(ptr + 1);
			ip = (ip2 * y_fac) - (*ptr * y_fac);
			ip2 = (*ptr + ip);
			ip = (ip2 * x_fac) - (ip1 * x_fac);
			ip = (ip1 + ip);
		}
		else
		{
			/*only line interpolation*/
			ip1 = *(ptr + num_col);
			ip1 = (ip1 * x_fac) - (*ptr * x_fac);
			ip = (*ptr + ip1);
		}
	}
	else
	{
		if (y_fac > 0.0f)
		{
			/*only col. interpolation*/
			ip1 = *(ptr + 1);
			ip1 = (ip1 * y_fac) - (*ptr * y_fac);
			ip = (*ptr + ip1);
		}
		else
		{
			/* no interpolation*/
			ip = *ptr;
		}
	}
	return ip;

	/* ## Operation body end [fc26b9c3-7394-4868-b4f1-633ed5e4ffc0] */
}

/** This operation shall performs the 3D interpolation operation.

@param ip_ptr Pointer to map
@param x Pointer to structure FDPS_RESULT for x axis
@param y Pointer to structure FDPS_RESULT for y axis
@return Returns float32 value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

static float32 function_f32_interpolate_u16(const uint16 * ip_ptr, const FDPS_RESULT x, const FDPS_RESULT y)
{
	/* ## Operation body start [8839862a-b22a-44f6-aace-bacb596055ab] */
	const uint16 *ptr;
	uint8    num_col, x_idx, y_idx;
	float32   ip1, ip2, ip, x_fac, y_fac;

	num_col = y.line_count;
	x_idx   = x.line_index;
	y_idx   = y.line_index;
	x_fac   = x.line_factor;
	y_fac   = y.line_factor;
	ptr = ip_ptr + ((x_idx * num_col) + y_idx);
	if (x_fac > 0.0f)
	{
		if (y_fac > 0.0f)
		{
			/*both column and line interpolation*/
			ip1 = (float32)(*(ptr + 1));
			ip = (ip1 * y_fac) - ((float32)(*ptr) * y_fac);
			ip1 = ((float32)(*ptr) + ip);
			ptr += num_col;
			ip2 = (float32)(*(ptr + 1));
			ip = (ip2 * y_fac) - ((float32)(*ptr) * y_fac);
			ip2 = ((float32)(*ptr) + ip);
			ip = (ip2 * x_fac) - (ip1 * x_fac);
			ip = (ip1 + ip);
		}
		else
		{
			/*only line interpolation*/
			ip1 = (float32)(*(ptr + num_col));
			ip1 = (ip1 * x_fac) - ((float32)(*ptr) * x_fac);
			ip = ((float32)(*ptr) + ip1);
		}
	}
	else
	{
		if (y_fac > 0.0f)
		{
			/*only col. interpolation*/
			ip1 = (float32)(*(ptr + 1));
			ip1 = (ip1 * y_fac) - ((float32)(*ptr) * y_fac);
			ip = ((float32)(*ptr) + ip1);
		}
		else
		{
			/* no interpolation */
			ip = (float32)*ptr;
		}
	}
	return ip;

	/* ## Operation body end [8839862a-b22a-44f6-aace-bacb596055ab] */
}

/** This operation shall performs the 3D interpolation operation.

@param ip_ptr Pointer to map
@param x Pointer to structure FDPS_RESULT for x axis
@param y Pointer to structure FDPS_RESULT for y axis
@return Returns float32 value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

static float32 function_f32_interpolate_u8(const uint8 * ip_ptr, const FDPS_RESULT x, const FDPS_RESULT y)
{
	/* ## Operation body start [713da97c-814f-4c6e-8c01-a957610874aa] */
	const uint8 *ptr;
	uint8    num_col, x_idx, y_idx;
	float32   ip1, ip2, ip, x_fac, y_fac;

	num_col = y.line_count;
	x_idx   = x.line_index;
	y_idx   = y.line_index;
	x_fac   = x.line_factor;
	y_fac   = y.line_factor;
	ptr = ip_ptr + ((x_idx * num_col) + y_idx);
	if (x_fac > 0.0f)
	{
		if (y_fac > 0.0f)
		{
			/*both line and column interpolation*/
			ip1 = (float32)(*(ptr + 1));
			ip = (ip1 * y_fac) -((float32)(*ptr) * y_fac);
			ip1 = ((float32)(*ptr) + ip);
			ptr += num_col;
			ip2 = (float32)(*(ptr + 1));
			ip = (ip2 * y_fac) -((float32)(*ptr) * y_fac);
			ip2 = ((float32)(*ptr) + ip);
			ip = (ip2 * x_fac) - (ip1 * x_fac);
			ip = (ip1 + ip);
		}
		else
		{
			/*only line interpolation*/
			ip1 = (float32)(*(ptr + num_col));
			ip1 = (ip1 * x_fac) - ((float32)(*ptr) * x_fac);
			ip = ((float32)(*ptr) + ip1);
		}
	}
	else
	{
		if (y_fac > 0.0f)
		{
			/*only col. interpolation*/
			ip1 = (float32)(*(ptr + 1));
			ip1 = (ip1 * y_fac) -((float32)(*ptr) * y_fac);
			ip = ((float32)(*ptr) + ip1);
		}
		else
		{
			/* no interpolation */
			ip = (float32)*ptr;
		}
	}
	return ip;

	/* ## Operation body end [713da97c-814f-4c6e-8c01-a957610874aa] */
}

/** This operation shall performs the 3D interpolation operation.

@param ip_ptr Pointer to map
@param x Pointer to structure FDPS_RESULT for x axis
@param y Pointer to structure FDPS_RESULT for y axis
@return Returns float32 value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

static float32 function_f32_interpolate_s8(const sint8 * ip_ptr, const FDPS_RESULT x, const FDPS_RESULT y)
{
	/* ## Operation body start [9a54a0c8-2b7c-4b45-9bb4-172db53e6408] */
	const sint8 *ptr;
	uint8    num_col, x_idx, y_idx;
	float32   ip1, ip2, ip, x_fac, y_fac;
	/*~T*/
	num_col = y.line_count;
	x_idx   = x.line_index;
	y_idx   = y.line_index;
	x_fac   = x.line_factor;
	y_fac   = y.line_factor;
	ptr = ip_ptr + ((x_idx * num_col) + y_idx);
	if (x_fac > 0.0f)
	{
		if (y_fac > 0.0f)
		{
			/*both line and column interpolation*/
			ip1 = (float32)(*(ptr + 1));
			ip = (ip1 * y_fac) -((float32)(*ptr) * y_fac);
			ip1 = ((float32)(*ptr) + ip);
			ptr += num_col;
			ip2 = (float32)(*(ptr + 1));
			ip = (ip2 * y_fac) -((float32)(*ptr) * y_fac);
			ip2 = ((float32)(*ptr) + ip);
			ip = (ip2 * x_fac) - (ip1 * x_fac);
			ip = (ip1 + ip);
		}
		else
		{
			/*only line interpolation*/
			ip1 = (float32)(*(ptr + num_col));
			ip1 = (ip1 * x_fac) - ((float32)(*ptr) * x_fac);
			ip = ((float32)(*ptr) + ip1);
		}
	}
	else
	{
		if (y_fac > 0.0f)
		{
			/*only col. interpolation*/
			ip1 = (float32)(*(ptr + 1));
			ip1 = (ip1 * y_fac) -((float32)(*ptr) * y_fac);
			ip = ((float32)(*ptr) + ip1);
		}
		else
		{
			/* no interpolation */
			ip = (float32)*ptr;
		}
	}
	/*~T*/
	return ip;
	/*~T*/
	/* ## Operation body end [9a54a0c8-2b7c-4b45-9bb4-172db53e6408] */
}

/** 

@param ip_ptr Pointer to map
@param x Pointer to structure FDPS_RESULT for x axis
@param y Pointer to structure FDPS_RESULT for y axis
@return Returns float32 value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

static float32 function_f32_interpolate_s16(const sint16 * ip_ptr, const FDPS_RESULT x, const FDPS_RESULT y)
{
	/* ## Operation body start [518dc86b-f428-4bb0-bb99-e2ce5238b65e] */
	const sint16 *ptr;
	uint8    num_col, x_idx, y_idx;
	float32   ip1, ip2, ip, x_fac, y_fac;
	/*~T*/
	num_col = y.line_count;
	x_idx   = x.line_index;
	y_idx   = y.line_index;
	x_fac   = x.line_factor;
	y_fac   = y.line_factor;
	ptr = ip_ptr + ((x_idx * num_col) + y_idx);//lint !e9016 MISRA 2012 Rule 18.4: allowed by the C Coding Rules

	if (x_fac > 0.0f)
	{
		if (y_fac > 0.0f)
		{
			/*both column and line interpolation*/
			ip1 = (float32)(*(ptr + 1));
			ip = (ip1 * y_fac) - ((float32)(*ptr) * y_fac);
			ip1 = ((float32)(*ptr) + ip);
			ptr += num_col;
			ip2 = (float32)(*(ptr + 1));
			ip = (ip2 * y_fac) - ((float32)(*ptr) * y_fac);
			ip2 = ((float32)(*ptr) + ip);
			ip = (ip2 * x_fac) - (ip1 * x_fac);
			ip = (ip1 + ip);
		}
		else
		{
			/*only line interpolation*/
			ip1 = (float32)(*(ptr + num_col));
			ip1 = (ip1 * x_fac) - ((float32)(*ptr) * x_fac);
			ip = ((float32)(*ptr) + ip1);
		}
	}
	else
	{
		if (y_fac > 0.0f)
		{
			/*only col. interpolation*/
			ip1 = (float32)(*(ptr + 1));
			ip1 = (ip1 * y_fac) - ((float32)(*ptr) * y_fac);
			ip = ((float32)(*ptr) + ip1);
		}
		else
		{
			/* no interpolation */
			ip = (float32)*ptr;
		}
	}
	/*~T*/
	return ip;
	/*~T*/
	/* ## Operation body end [518dc86b-f428-4bb0-bb99-e2ce5238b65e] */
}



/*~T*/

/*~E*/
/*~A*/
/*~+:Public Operations*/
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

void function_fdps_ptr_f32(const float32 * data_point_array, float32 parameter, FDPS_RESULT * dps)
{
	/* ## Operation body start [b6fc32b0-e03f-4840-81f5-45d2dcc7d147] */
	const float32 *dp_ptr;
	uint32  tmpF32,tmpF32_1;
	float32 diff;
	dps->line_count = (uint8)(*data_point_array);
	dp_ptr = data_point_array + dps->line_count;
	if (parameter >= *dp_ptr)
	{
		/* if input data point value >= highest data point value set factor to zero and index to maximum */
		dps->line_factor = 0.0f;
		dps->line_index = (uint8)((uint32)*data_point_array -1U);
	}
	else
	{
		if (parameter <= *(data_point_array + 1U))
		{
			/* if input point value <= lowest data point value set factor and index to zero */
			dps->line_factor = 0.0f;
			dps->line_index = 0U;
		}
		else
		{
			/* calculate index and factors */
			do
			{
				--dp_ptr;
			}
			while (parameter < (*dp_ptr));
			tmpF32 = (uint32)dp_ptr;
			tmpF32_1 = (uint32)data_point_array;
			tmpF32_1 = (tmpF32 - tmpF32_1)/4U;
			dps->line_index = (uint8)(tmpF32_1 - 1U);
			diff = parameter - *dp_ptr;
			if (diff != 0.0f)
			{
					                dps->line_factor = diff / (*(dp_ptr + 1U) - *dp_ptr);
			}
			else
			{
				dps->line_factor = 0.0f;
			}
		}
	}

	/* ## Operation body end [b6fc32b0-e03f-4840-81f5-45d2dcc7d147] */
}

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

void function_fdps_ptr_u16(const uint16 * data_point_array, uint16 parameter, FDPS_RESULT * dps)
{
	/* ## Operation body start [d3957e70-8b78-46eb-a962-3a29b4ec872e] */
	const uint16 *dp_ptr;
	uint32  tmpF32,tmpF32_1;
	float32 diff;
	dps->line_count = (uint8)*data_point_array;
	dp_ptr = data_point_array + dps->line_count;
	if (parameter >= *dp_ptr)
	{
		/* if input data point value >= highest data point value set factor to zero and index to maximum */

		dps->line_factor = 0.0f;
		dps->line_index = (uint8)(*data_point_array - 1U);
	}
	else
	{
		if (parameter <= *(data_point_array + 1U))
		{
			/* if input point value <= lowest data point value set factor and index to zero */
			dps->line_factor = 0.0f;
			dps->line_index = 0;
		}
		else
		{
			/* calculate index and factors */
			do
			{
				--dp_ptr;
			}
			while (parameter < (*dp_ptr));
			tmpF32 = (uint32)dp_ptr;
			tmpF32_1 = (uint32)data_point_array;
			tmpF32_1 = (tmpF32 - tmpF32_1)/2U;
			dps->line_index = (uint8)(tmpF32_1 - 1U);
			diff = (float32)(parameter - *dp_ptr);
			if (diff != 0.0f)
			{
					                dps->line_factor = diff / (float32)(*(dp_ptr +1U) - *dp_ptr);
			}
			else
			{
				dps->line_factor = 0.0f;
			}
		}
	}

	/* ## Operation body end [d3957e70-8b78-46eb-a962-3a29b4ec872e] */
}

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

void function_fdps_ptr_u8(const uint8 * data_point_array, uint8 parameter, FDPS_RESULT * dps)
{
	/* ## Operation body start [c0ab8b98-1b45-4eac-9754-ce35e98940a2] */
	const uint8 *dp_ptr;
	uint32  tmpF32,tmpF32_1;
	float32 diff;
	dps->line_count = *data_point_array;
	dp_ptr = data_point_array + dps->line_count;
	if (parameter >= *dp_ptr)
	{
		/* if input data point value >= highest data point value set factor to zero and index to maximum */
		dps->line_factor = 0.0f;
		dps->line_index = (*data_point_array - 1U);
	}
	else
	{
		if (parameter <= *(data_point_array + 1))
		{
			/* if input point value <= lowest data point value set factor and index to zero */
			dps->line_factor = 0.0f;
			dps->line_index = 0;
		}
		else
		{
			/* calculate index and factors */
			do
			{
				--dp_ptr;
			}
			while (parameter < (*dp_ptr));
			tmpF32 = (uint32)dp_ptr;
			tmpF32_1 = (uint32)data_point_array;
			dps->line_index = (uint8)((tmpF32 - tmpF32_1) - 1U);
			diff = (float32)(parameter - *dp_ptr);
			if (diff != 0.0f)
			{
					                dps->line_factor = diff / (float32)(*(dp_ptr + 1U) - *dp_ptr);
			}
			else
			{
				dps->line_factor = 0.0f;
			}
		}
	}

	/* ## Operation body end [c0ab8b98-1b45-4eac-9754-ce35e98940a2] */
}

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

void function_fdps_ptr_s8(const sint8 * data_point_array, sint8 parameter, FDPS_RESULT * dps)
{
	/* ## Operation body start [11a33d95-0432-4dd6-a875-f4aeda214886] */
	const sint8 *dp_ptr;
	uint32  tmpF32,tmpF32_1;
	float32 diff;
	dps->line_count = (uint8)*data_point_array;
	dp_ptr = data_point_array + dps->line_count;
	if (parameter >= *dp_ptr)
	{
		/* if input data point value >= highest data point value set factor to zero and index to maximum */
		dps->line_factor = 0.0f;
		dps->line_index = (uint8)(*data_point_array - (sint8)1);
	}
	else
	{
		if (parameter <= *(data_point_array + 1))
		{
			/* if input point value <= lowest data point value set factor and index to zero */
			dps->line_factor = 0.0f;
			dps->line_index = 0;
		}
		else
		{
			/* calculate index and factors */
			do
			{
				--dp_ptr;
			}
			while (parameter < (*dp_ptr));
			tmpF32 = (uint32)dp_ptr;
			tmpF32_1 = (uint32)data_point_array;
			dps->line_index = (uint8)((tmpF32 - tmpF32_1) - 1U);
			diff = (float32)(parameter - *dp_ptr);
			if (diff != 0.0f)
			{
					                dps->line_factor = diff / (float32)(*(dp_ptr + 1U) - *dp_ptr);
			}
			else
			{
				dps->line_factor = 0.0f;
			}
		}
	}
	/*~T*/
	/* ## Operation body end [11a33d95-0432-4dd6-a875-f4aeda214886] */
}

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

void function_fdps_ptr_s16(const sint16 * data_point_array, sint16 parameter, FDPS_RESULT * dps)
{
	/* ## Operation body start [d9cadb8b-e818-4784-8084-cf5e6138d046] */
	const sint16 *dp_ptr;
	uint32  tmpF32,tmpF32_1;
	float32 diff;
	dps->line_count = (uint8)*data_point_array;
	dp_ptr = data_point_array + dps->line_count;
	if (parameter >= *dp_ptr)
	{
		/* if input data point value >= highest data point value set factor to zero and index to maximum */

		dps->line_factor = 0.0f;
		dps->line_index = (uint8)(*data_point_array - (sint8)1);
	}
	else
	{
		if (parameter <= *(data_point_array + 1))
		{
			/* if input point value <= lowest data point value set factor and index to zero */
			dps->line_factor = 0.0f;
			dps->line_index = 0;
		}
		else
		{
			/* calculate index and factors */
			do
			{
				--dp_ptr;
			}
			while (parameter < (*dp_ptr));
			tmpF32 = (uint32)dp_ptr;
			tmpF32_1 = (uint32)data_point_array;
			tmpF32_1 = (tmpF32 - tmpF32_1)/2U;
			dps->line_index = (uint8)(tmpF32_1 - 1U);
			diff = (float32)(parameter - *dp_ptr);
			if (diff != 0.0f)
			{
					                dps->line_factor = diff / (float32)(*(dp_ptr +1U) - *dp_ptr);
			}
			else
			{
				dps->line_factor = 0.0f;
			}
		}
	}
	/* ## Operation body end [d9cadb8b-e818-4784-8084-cf5e6138d046] */
}

/** This operation shall determines the table index.
 The input parameters need to be provided are,
 	- Pointer data point array
 	- Data point value

@param data_point_array : constant float32 Pointer to the data point array
@param parameter : float32 Value of the data point array
@return Returns uint8 value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint8 function_u8_fidx_ptr_f32(const float32 * data_point_array, float32 parameter)
{
	/*~T*/
	/* ## Operation body start [9fb626aa-5249-4bbb-a032-cdd35908f137] */
	uint8    table_idx;
	uint32  tmpF32,tmpF32_1;
	const float32 *dp_ptr;       /* pointer to data point array */
	/*~T*/
	dp_ptr = data_point_array + (uint8)(*data_point_array);

	if  (parameter >= *dp_ptr)
	{
		/*if input parameter >= highest data point value set line index to index of last element in the data point array */

			        table_idx= (uint8)((uint32)*data_point_array - 1U);

	}
	else
	{
		if (parameter <= *(data_point_array + 1U))
		{
			/*if input parameter <= lowest data point value set line index to zero */

			table_idx = 0;
		}
		else
		{
			do
			{
				--dp_ptr;
			}
			while (parameter < *dp_ptr);
			/* line index calculation*/
			tmpF32 = (uint32)dp_ptr;
			tmpF32_1 = (uint32)data_point_array;
			tmpF32_1 = (tmpF32 - tmpF32_1)/4U;
			table_idx = (uint8)(tmpF32_1 - 1U);
		}
	}
	return table_idx;

	/* ## Operation body end [9fb626aa-5249-4bbb-a032-cdd35908f137] */
}

/** This operation shall performs the 1D interpolation operation.
 The input parameters need to be provided are,
 	- Pointer to map
 	- Pointer to structure FDPS_RESULT for x axis

@param map : constant float32 Pointer to 1D map
@param dpsx Pointer to structure FDPS_RESULT for x axis
@return Returns float32 value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

float32 function_f32_ptr_ip1d(const float32 * map, const FDPS_RESULT * dpsx)
{
	/* ## Operation body start [8c3c929c-1876-43cc-b1ef-4d85d4e2c01a] */
	uint8  idx;
	float32 ip_1, ip_2, fac;
	idx = dpsx->line_index;
	fac = dpsx->line_factor;
	if (fac > 0.0f)
	{
		/* return the interpolated value for non-zero factor */
		ip_1 = *(map + idx);
		ip_2 = *(map + (idx + 1U));
		ip_2 = (ip_2 * fac) - (ip_1 * fac);

		ip_2 = (ip_1 + ip_2);
	}
	else
	{
		/* return the value pointed by the line index */
		ip_2 = (*(map + idx));
	}
	return ip_2;

	/* ## Operation body end [8c3c929c-1876-43cc-b1ef-4d85d4e2c01a] */
}

/** This operation shall performs the 1D interpolation operation for uint8.
 The input parameters need to be provided are,
 	- Pointer to map
 	- Pointer to structure FDPS_RESULT for x axis

@param map :constant uint8 Pointer to 1D map
@param dpsx : Pointer to structure FDPS_RESULT for x axis
@return Returns float32 value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

float32 function_f32_u8ptr_ip1d(const uint8 * map, const FDPS_RESULT * dpsx)
{
	/* ## Operation body start [d7975b78-01fb-4f03-b482-46fa9ad130c0] */
	uint8  idx;
	float32 ip_1, ip_2, fac;
	idx = dpsx->line_index;
	fac = dpsx->line_factor;

	if (fac > 0.0f)
	{
		/* return the interpolated value for non-zero factor */
		ip_1 = (float32)(*(map + idx));
		ip_2 = (float32)(*(map + (idx + 1U)));
		ip_2= (ip_2 * fac) - (ip_1 * fac);

		ip_2 = (ip_1 + ip_2);
	}
	else
	{
		/* return the value pointed by the line index */
		ip_2 = (float32)(*(map + idx));
	}
	/*~T*/
	return ip_2;
	/*~T*/
	/* ## Operation body end [d7975b78-01fb-4f03-b482-46fa9ad130c0] */
}

/** This operation shall performs the 1D interpolation operation for uint16.
 The input parameters need to be provided are,
 	- Pointer to map
 	- Pointer to structure FDPS_RESULT for x axis

@param map :constant uint16 Pointer to 1D map
@param dpsx : Pointer to structure FDPS_RESULT for x axis
@return Returns float32 value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

float32 function_f32_u16ptr_ip1d(const uint16 * map, const FDPS_RESULT * dpsx)
{
	/* ## Operation body start [da735bc2-0a2b-4e53-87c3-e077462fe700] */
	uint8  idx;
	float32 ip_1, ip_2, fac;

	idx = dpsx->line_index;
	fac = dpsx->line_factor;
	if (fac > 0.0f)
	{
		/* return the interpolated value for non-zero factor */
		ip_1 = (float32)(*(map + idx));
		ip_2 = (float32)(*(map + (idx + 1U)));
		ip_2= (ip_2 * fac) - (ip_1 * fac);

		ip_2 = (ip_1 + ip_2);
	}
	else
	{
		/* return the value pointed by the line index */

		ip_2 = (float32)(*(map + idx));





	}
	return ip_2;

	/* ## Operation body end [da735bc2-0a2b-4e53-87c3-e077462fe700] */
}

/** This operation shall performs the 1D interpolation operation for sint8.
 The input parameters need to be provided are,
 	- Pointer to map
 	- Pointer to structure FDPS_RESULT for x axis

@param map :constant sint8 Pointer to 1D map
@param dpsx : Pointer to structure FDPS_RESULT for x axis
@return Returns float32 value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

float32 function_f32_s8ptr_ip1d(const sint8 * map, const FDPS_RESULT * dpsx)
{
	/* ## Operation body start [034ea4f6-e15a-4b83-a04a-9fd9e96bb381] */
	uint8  idx;
	float32 ip_1, ip_2, fac;
	idx = dpsx->line_index;
	fac = dpsx->line_factor;

	if (fac > 0.0f)
	{
		/* return the interpolated value for non-zero factor */
		ip_1 = (float32)(*(map + idx));
		ip_2 = (float32)(*(map + (idx + 1U)));
		ip_2= (ip_2 * fac) - (ip_1 * fac);


		/*~T*/
		ip_2 = (ip_1 + ip_2);
	}
	else
	{
		/* return the value pointed by the line index */
		ip_2 = (float32)(*(map + idx));
	}
	/*~T*/
	return ip_2;
	/*~T*/
	/* ## Operation body end [034ea4f6-e15a-4b83-a04a-9fd9e96bb381] */
}

/** This operation shall performs the 1D interpolation operation for sint16.
 The input parameters need to be provided are,
 	- Pointer to map
 	- Pointer to structure FDPS_RESULT for x axis

@param map :constant sint16 Pointer to 1D map
@param dpsx : Pointer to structure FDPS_RESULT for x axis
@return Returns float32 value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

float32 function_f32_s16ptr_ip1d(const sint16 * map, const FDPS_RESULT * dpsx)
{
	/* ## Operation body start [8ea762ff-1e8c-41f3-afb7-3a5c188dc67f] */
	uint8  idx;
	float32 ip_1, ip_2, fac;
	idx = dpsx->line_index;
	fac = dpsx->line_factor;

	if (fac > 0.0f)
	{
		/* return the interpolated value for non-zero factor */
		ip_1 = (float32)(*(map + idx));
		ip_2 = (float32)(*(map + (idx + 1U)));
		ip_2= (ip_2 * fac) - (ip_1 * fac);

		ip_2 = (ip_1 + ip_2);
	}
	else
	{
		/* return the value pointed by the line index */
		ip_2 = (float32)(*(map + idx));
	}
	/*~T*/
	return ip_2;
	/*~T*/
	/* ## Operation body end [8ea762ff-1e8c-41f3-afb7-3a5c188dc67f] */
}

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

float32 function_f32_ptr_ip2d(const float32 * map, const FDPS_RESULT * dpsx, const FDPS_RESULT * dpsy)
{
	/* ## Operation body start [61814cf3-3a62-4b38-a7b0-8cc01bf0c6b8] */

	float32 ip;

	ip= function_f32_interpolate_f32(map,*dpsx,*dpsy);


	return ip;

	/* ## Operation body end [61814cf3-3a62-4b38-a7b0-8cc01bf0c6b8] */
}

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

float32 function_f32_u8ptr_ip2d(const uint8 * map, const FDPS_RESULT * dpsx, const FDPS_RESULT * dpsy)
{
	/* ## Operation body start [7b8ff7f5-4a54-4b65-b95e-6078c003e9af] */

	float32 ip;



	ip= function_f32_interpolate_u8(map,*dpsx,*dpsy);

	return ip;

	/* ## Operation body end [7b8ff7f5-4a54-4b65-b95e-6078c003e9af] */
}

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

float32 function_f32_u16ptr_ip2d(const uint16 * map, const FDPS_RESULT * dpsx, const FDPS_RESULT * dpsy)
{
	/* ## Operation body start [1623c76e-4e03-4e2e-b4a0-9562c63f154f] */
	float32 ip;

	ip=function_f32_interpolate_u16(map,*dpsx,*dpsy);

	return ip;

	/* ## Operation body end [1623c76e-4e03-4e2e-b4a0-9562c63f154f] */
}

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

float32 function_f32_s8ptr_ip2d(const sint8 * map, const FDPS_RESULT * dpsx, const FDPS_RESULT * dpsy)
{
	/* ## Operation body start [c3c00fea-c35d-4213-aeaa-fc18b7b48b00] */
	float32   ip;

	/*~T*/

	ip = function_f32_interpolate_s8(map, *dpsx,*dpsy);
	/*~T*/
	return ip;
	/*~T*/
	/* ## Operation body end [c3c00fea-c35d-4213-aeaa-fc18b7b48b00] */
}

/** This operation shall performs the 2D interpolation operation for sint16.
 The input parameters need to be provided are,
 	- Pointer to map
 	- Pointer to structure FDPS_RESULT for x axis
	- Pointer to structure FDPS_RESULT for y axis

@param map : constant sint816 Pointer to 2D map
@param dpsx : Pointer to structure FDPS_RESULT for x axis
@param dpsy : Pointer to structure FDPS_RESULT for y axis
@return Returns float32 value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

float32 function_f32_s16ptr_ip2d(const sint16 * map, const FDPS_RESULT * dpsx, const FDPS_RESULT * dpsy)
{
	/* ## Operation body start [cdc07efa-c298-4309-b878-5add4c3b600c] */
	float32   ip;
	/*~T*/
	ip=function_f32_interpolate_s16(map,*dpsx,*dpsy);
	/*~T*/
	return ip;
	/*~T*/
	/* ## Operation body end [cdc07efa-c298-4309-b878-5add4c3b600c] */
}

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

float32 function_f32_ptr_ip3d(const float32 * map, const FDPS_RESULT * dpsx, const FDPS_RESULT * dpsy, const FDPS_RESULT * dpsz)
{
	/* ## Operation body start [b7eb5d6c-b504-4ece-8412-13bfa32d05da] */
	uint8  x_num_col, y_num_col, z_idx;
	uint32 num_col, index;
	float32 z_fac, ip1, ip2 = 0.0f;

	x_num_col = dpsx -> line_count;
	y_num_col = dpsy -> line_count;
	z_idx     = dpsz -> line_index;
	z_fac     = dpsz -> line_factor;

	num_col = (uint32)(x_num_col * y_num_col);
	index = z_idx * num_col;
	/* interpolation of first 2D map */
	ip1 = function_f32_interpolate_f32(&map[index], *dpsx, *dpsy);
	if (z_fac > 0.0f)
	{
		/* interpolation of second 2D map if z_fac is non-zero*/
		ip2 = function_f32_interpolate_f32(&map[index + num_col], *dpsx, *dpsy);
		ip2 = (ip2 * z_fac) - (ip1 * z_fac);
	}
	return (ip1 + ip2);

	/* ## Operation body end [b7eb5d6c-b504-4ece-8412-13bfa32d05da] */
}

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

float32 function_f32_u8ptr_ip3d(const uint8 * map, const FDPS_RESULT * dpsx, const FDPS_RESULT * dpsy, const FDPS_RESULT * dpsz)
{
	/* ## Operation body start [e9bc407a-d541-400b-80ad-d07a68e99b24] */
	uint8  x_num_col, y_num_col, z_idx;
	uint32 num_col, index;
	float32 ip1, ip2 = 0.0f, z_fac;

	x_num_col = dpsx->line_count;
	y_num_col = dpsy->line_count;
	z_idx     = dpsz->line_index;
	z_fac     = dpsz->line_factor;
	num_col = (uint32)(x_num_col * y_num_col);
	index = z_idx * num_col;
	/* interpolation of first 2D map */
	ip1 = function_f32_interpolate_u8(&map[index], *dpsx, *dpsy);
	if (z_fac > 0.0f)
	{
		/* interpolation of second 2D map if z_fac is non-zero */
		ip2 = function_f32_interpolate_u8(&map[index + num_col], *dpsx, *dpsy);
		ip2 = (ip2 * z_fac) - (ip1 * z_fac);
	}
	return (ip1 + ip2);

	/* ## Operation body end [e9bc407a-d541-400b-80ad-d07a68e99b24] */
}

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

float32 function_f32_u16ptr_ip3d(const uint16 * map, const FDPS_RESULT * dpsx, const FDPS_RESULT * dpsy, const FDPS_RESULT * dpsz)
{
	/* ## Operation body start [9b6cc324-de97-416d-bd48-bb53ae29d4c2] */
	uint8  x_num_col, y_num_col, z_idx;
	uint32 num_col, index;
	float32 z_fac, ip1, ip2 = 0.0f;

	x_num_col = dpsx -> line_count;
	y_num_col = dpsy -> line_count;
	z_idx     = dpsz -> line_index;
	z_fac     = dpsz -> line_factor;
	num_col = (uint32)(x_num_col * y_num_col);
	index = z_idx * num_col;
	/* interpolation of first 2D map */
	ip1 = function_f32_interpolate_u16(&map[index], *dpsx, *dpsy);
	if (z_fac > 0.0f)
	{
		/* interpolation of second 2D map if z_fac is non-zero */
		ip2 = function_f32_interpolate_u16(&map[index + num_col], *dpsx, *dpsy);
		ip2 = (ip2 * z_fac) - (ip1 * z_fac);
	}
	return (ip1 + ip2);

	/* ## Operation body end [9b6cc324-de97-416d-bd48-bb53ae29d4c2] */
}

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

float32 function_f32_s8ptr_ip3d(const sint8 * map, const FDPS_RESULT * dpsx, const FDPS_RESULT * dpsy, const FDPS_RESULT * dpsz)
{
	/* ## Operation body start [093916a5-97d5-4a4c-bb85-ebcb0fc15030] */
	uint8  x_num_col, y_num_col, z_idx;
	uint32 num_col, index;
	float32 ip1, ip2 = 0.0f, z_fac;

	/*~T*/

	x_num_col = dpsx->line_count;

	y_num_col = dpsy->line_count;

	z_idx     = dpsz->line_index;

	z_fac     = dpsz->line_factor;

	num_col = (uint32)(x_num_col * y_num_col);

	index = z_idx * num_col;

	/* interpolation of first 2D map */

	ip1 = function_f32_interpolate_s8(&map[index], *dpsx, *dpsy);

	if (z_fac > 0.0f)
	{
		/* interpolation of second 2D map if z_fac is non-zero */
		ip2 = function_f32_interpolate_s8(&map[index + num_col], *dpsx, *dpsy);
		ip2 = (ip2 * z_fac) - (ip1 * z_fac);
	}
	/*~T*/
	return (ip1 + ip2);
	/*~T*/
	/* ## Operation body end [093916a5-97d5-4a4c-bb85-ebcb0fc15030] */
}

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

float32 function_f32_s16ptr_ip3d(const sint16 * map, const FDPS_RESULT * dpsx, const FDPS_RESULT * dpsy, const FDPS_RESULT * dpsz)
{
	/* ## Operation body start [8d89746f-961a-4ed8-a01e-0f1fb1905ae4] */
	uint8  x_num_col, y_num_col, z_idx;
	uint32 num_col, index;
	float32 z_fac, ip1, ip2 = 0.0f;

	/*~T*/

	x_num_col = dpsx -> line_count;

	y_num_col = dpsy -> line_count;

	z_idx     = dpsz -> line_index;

	z_fac     = dpsz -> line_factor;

	num_col = (uint32)(x_num_col * y_num_col);

	index = z_idx * num_col;

	/* interpolation of first 2D map */

	ip1 = function_f32_interpolate_s16(&map[index], *dpsx, *dpsy);
	if (z_fac > 0.0f)
	{
		/* interpolation of second 2D map if z_fac is non-zero */
		ip2 = function_f32_interpolate_s16(&map[index + num_col], *dpsx, *dpsy);
		ip2 = (ip2 * z_fac) - (ip1 * z_fac);
	}
	/*~T*/
	return (ip1 + ip2);
	/*~T*/
	/* ## Operation body end [8d89746f-961a-4ed8-a01e-0f1fb1905ae4] */
}

/*~E*/

