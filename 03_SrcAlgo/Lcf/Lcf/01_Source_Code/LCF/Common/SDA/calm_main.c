/*~A*/
/*~+:VM Header*/
/* Used UML Profile version  */
/* ## Module Header Start [5930e086-6b60-412b-a82c-0a8723e9646a] */
/****************************************************************************

COPYRIGHT (C) $Date: 2019/07/03 13:44:17CEST $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.                                                 

The reproduction, transmission or use of this document or its contents is  
not permitted without express written authority.                           
Offenders will be liable for damages. All rights, including rights created 
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------

$Log: calm_main.c  $
Revision 1.1 2019/07/03 13:44:17CEST Nastasa, Elena (uidt4846) 
Initial revision
Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/Common/SDA/project.pj
Revision 1.1 2018/07/24 16:49:47CEST Ammermueller Martin (uidv5342) (uidv5342) 
Initial revision
Member added to project /ES/1T/0C/SDA/SDA_Source/SDA_Toolboxes/ACG/Libraries/calm/Src/3_1_0/project.pj
Revision 1.4 2018/03/06 07:53:49CET Angadi Hampa (uidu8151) (uidu8151) 
RO : 8197494 : MISRA2012 ANSI VERSIONS
Revision 1.3 2017/10/04 07:47:37CEST Angadi Hampa (uidu8151) (uidu8151) 
Calm : LINT MISRA2012 for ANSI
Revision 1.2 2015/12/02 03:40:25CET Angadi Hampa (uidu8151) (uidu8151) 
RO: 3550535: CALM : Create ANSI Version; Before review
Revision 1.3 2015/11/04 11:58:16CET Ganesh Sumangala (uidu8725) (uidu8725) 
RO : 2806846 : CALM: Merge EMS2 and EMS3 Calm versions.
Revision 1.2 2014/07/24 12:51:20CEST Angadi Hampa (uidu8151) (uidu8151) 
Ro: 1081869 : FS_0G01_TC2XX_CALM_200: C & test file update.
Revision 1.1 2013/08/09 11:27:25CEST Angadi Hampa (uidu8151) (uidu8151) 
Initial revision
Member added to project /ES/FS/0D/bsw/stdlib/tc2xx/calm/src_pd/i/project.pj
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
/* ## Module Header End [5930e086-6b60-412b-a82c-0a8723e9646a] */

/*~E*/
/*~A*/
/*~+:SW module (UML class) description*/

/*~E*/
/*~A*/
/*~+:Includes*/
#include "Std_Types.h"
#include "powersar_addon_types.h"
#include "iopt_memmap.h"
#include "calm_main.h"
/*~E*/
/*~A*/
/*~+:LINT Supressions*/
/*lint --e{9016} */
/*lint --e{9033} */
/*lint --e{9034} */
/*lint --e{9078} */
/*lint --e{923} */
/*lint --e{9087} */
/*lint --e{9079} */
/*lint --e{9005} */
/*lint --e{9031} */
/*~E*/
/*~A*/
/*~+:Private and Public Operations  */
/** This operation performs data point search for uint8 data point array and sets the structure - DPS_RESULT - elements, line_count, line_index and line_factor

@param dp_ptr :pointer to data point array
@param val :data point value to be searched
@param dps :pointer variable containing the information of interpolation length, index and factor */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

void function_udps_u8(const uint8 * dp_ptr, uint8 val, DPS_RESULT * dps)
{
	/* ## Operation body start [03d32286-f3e7-49a3-b595-34e5a52646f8] */
	const uint8 *ptr;
	uint32   diff, fac = 0;
	uint32   num_col, idx = 0;

	/* extract number of elements */
	num_col = (uint32)*dp_ptr;
	/* pointer to point to last element of dp array */
	ptr = dp_ptr + num_col;
	if (val >= *ptr)
	{
		/* index will be set to higher index and factor will be zero when val exceeds higher limit */
		idx = num_col - 1U;
	}
	else
	{
		if (val <= *(dp_ptr + 1))
		{
			/* index and factor will be zero when val exceeds lower limit */
		}
		else
		{
			/* find index and factor when val is within the limit */
			/*~T*/

			do
			{
				--ptr;
				idx = (uint32)(*ptr);

			}
			while ((uint32)val < idx);
			diff = ((uint32)val - idx);
			if (diff != 0U)
			{
				fac = ((diff << 16) / ((uint32)*(ptr + 1) - idx));
			}
			else
			{
				/* factor will be zero if val is matching to data point array element */
			}
			idx = ((uint32)ptr - (uint32)dp_ptr) - 1U;
		}
	}
	/* store interpolation length, index and factor inside dps */
	dps->line_count  = (uint8)num_col;
	dps->line_index  = (uint8)idx;
	dps->line_factor = (uint16)fac;

	/* ## Operation body end [03d32286-f3e7-49a3-b595-34e5a52646f8] */
}

/** This operation performs data point search for uint16 data point array and sets the structure - DPS_RESULT - elements, line_count, line_index and line_factor

@param dp_ptr :pointer to data point array
@param val :data point value to be searched
@param dps :pointer variable containing the information of interpolation length, index and factor */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

void function_udps_u16(const uint16 * dp_ptr, uint16 val, DPS_RESULT * dps)
{
	/* ## Operation body start [30e142c8-def7-4387-8728-646f1dddf351] */
	const uint16 *ptr;
	uint32   diff, fac = 0;
	uint32   num_col, idx = 0;

	/* extract number of elements */
	num_col = (uint32)(*dp_ptr);
	/* pointer to point to last element of dp array */
	ptr = dp_ptr + num_col;
	if (val >= *ptr)
	{
		/* index will be set to higher index and factor will be zero when val exceeds higher limit */
		idx = num_col - 1U;
	}
	else
	{
		if (val <= *(dp_ptr + 1))
		{
			/* index and factor will be zero when val exceeds lower limit */
		}
		else
		{
			/* find index and factor when val is within the limit */
			/*~T*/

			do
			{
				--ptr;
				idx = (uint32)(*ptr);

			}
			while ((uint32)val < idx);
			diff = ((uint32)val - idx);
			if (diff != 0U)
			{
				fac = ((diff << 16) / ((uint32)*(ptr + 1) - idx));
			}
			else
			{
				/* factor will be zero if val is matching to data point array element */
			}
			idx = (uint32)(((uint32)ptr - (uint32)dp_ptr)/2U) - 1U;
		}
	}
	/* store interpolation length, index and factor inside dps */
	dps->line_count  = (uint8)num_col;
	dps->line_index  = (uint8)idx;
	dps->line_factor = (uint16)fac;

	/* ## Operation body end [30e142c8-def7-4387-8728-646f1dddf351] */
}

/** This operation performs data point search for uint32 data point array and sets the structure - DPS_RESULT - elements, line_count, line_index and line_factor

@param dp_ptr :pointer to data point array
@param val :data point value to be searched
@param dps :pointer variable containing the information of interpolation length, index and factor */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

void function_udps_u32(const uint32 * dp_ptr, uint32 val, DPS_RESULT * dps)
{
	/* ## Operation body start [51ee48c4-77ad-4bd2-a820-d5de76f1091f] */
	const uint32 *ptr;
	uint32   num_col, idx = 0,fac=0,tmp_ptr;
	uint64   diff;
	/* extract number of elements */
	num_col = (*dp_ptr);
	/* pointer to point to last element of dp array */
	ptr = dp_ptr + num_col;
	if (val >= *ptr)
	{
		/* index will be set to higher index and factor will be zero when val exceeds higher limit */
		idx = num_col - 1U;
	}
	else
	{
		if (val <= *(dp_ptr + 1))
		{
			/* index and factor will be zero when val exceeds lower limit */
		}
		else
		{
			/* find index and factor when val is within the limit */
			do
			{
				--ptr;
				idx = (*ptr);
			}
			while (val < idx);
			diff = ((uint64)val - idx);
			if (diff != 0U)
			{
				tmp_ptr = *(ptr + 1)- idx;
				fac = (uint32)((diff<<16U) / tmp_ptr );
			}
			else
			{
				/* factor will be zero if val is matching to data point array element */
			}
			idx = (uint32)(((uint32)ptr - (uint32)dp_ptr)/4U) - 1U;
		}
	}
	/* store interpolation length, index and factor inside dps */
	dps->line_count  = (uint8)num_col;
	dps->line_index  = (uint8)idx;
	dps->line_factor = (uint16)fac;


	/* ## Operation body end [51ee48c4-77ad-4bd2-a820-d5de76f1091f] */
}

/** This operation performs data point search for sint8 data point array and sets the structure - DPS_RESULT - elements, line_count, line_index and line_factor

@param dp_ptr :pointer to data point array
@param val :data point value to be searched
@param dps :pointer variable containing the information of interpolation length, index and factor */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

void function_sdps_s8(const sint8 * dp_ptr, sint8 val, DPS_RESULT * dps)
{
	/* ## Operation body start [11ca9e0e-5945-4206-a6c7-d3f2655635b3] */
	const sint8 *ptr;
	sint32   diff, tmp;
	uint32   num_col, idx = 0, fac = 0;
	/* extract number of elements */
	num_col = (uint32)((uint8)*dp_ptr);
	/* pointer to point to last element of dp array */
	ptr = dp_ptr + num_col;
	if (val >= *ptr)
	{
		/* index will be set to higher index and factor will be zero when val exceeds higher limit */
		idx = num_col - 1U;
	}
	else
	{
		if (val <= *(dp_ptr + 1))
		{
			/* index and factor will be zero when val exceeds lower limit */
		}
		else
		{
			/* find index and factor when val is within the limit */
			do
			{
				--ptr;
				tmp = (sint32)(*ptr);
			}
			while ((sint32)val < tmp);
			idx = ((uint32)ptr - (uint32)dp_ptr) - 1U;
			diff = ((sint32)val - tmp);
			if (diff != 0)
			{
				fac = (uint16)(((uint32)diff << 16) / (uint32)((sint32)*(ptr + 1) - tmp));
			}
			else
			{
				/* factor will be zero if val is matching to data point array element */
			}
		}
	}
	/* store interpolation length, index and factor inside dps */
	dps->line_count  = (uint8)num_col;
	dps->line_index  = (uint8)idx;
	dps->line_factor = (uint16)fac;

	/* ## Operation body end [11ca9e0e-5945-4206-a6c7-d3f2655635b3] */
}

/** This operation performs data point search for sint16 data point array and sets the structure - DPS_RESULT - elements, line_count, line_index and line_factor

@param dp_ptr :pointer to data point array
@param val :data point value to be searched
@param dps :pointer variable containing the information of interpolation length, index and factor */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

void function_sdps_s16(const sint16 * dp_ptr, sint16 val, DPS_RESULT * dps)
{
	/* ## Operation body start [cf9e670b-928e-4ca4-b09c-0303dab10756] */
	const sint16 *ptr;
	sint32   diff, tmp;
	uint32   num_col, idx = 0, fac = 0;

	/* extract number of elements */
	num_col = (uint32)((uint16)*dp_ptr);
	/* pointer to point to last element of dp array */
	ptr = dp_ptr + num_col;
	if (val >= *ptr)
	{
		/* index will be set to higher index and factor will be zero when val exceeds higher limit */
		idx = num_col - 1U;
	}
	else
	{
		if (val <= *(dp_ptr + 1))
		{
			/* index and factor will be zero when val exceeds lower limit */
		}
		else
		{
			/* find index and factor when val is within the limit */
			do
			{
				--ptr;
				tmp = (sint32)(*ptr);
			}
			while ((sint32)val < tmp);
			idx = (uint32)(((uint32)ptr - (uint32)dp_ptr)/2U) - 1U;
			diff = ((sint32)val - tmp);
			if (diff != 0)
			{
				fac = (uint16)(((uint32)diff << 16) / (uint32)((sint32)*(ptr + 1) - tmp));
			}
			else
			{
				/* factor will be zero if val is matching to data point array element */
			}
		}
	}
	/* store interpolation length, index and factor inside dps */
	dps->line_count  = (uint8)num_col;
	dps->line_index  = (uint8)idx;
	dps->line_factor = (uint16)fac;

	/* ## Operation body end [cf9e670b-928e-4ca4-b09c-0303dab10756] */
}

/** This operation shall perform data point search for sint32 data point array and sets the structure - DPS_RESULT - elements, line_count, line_index and line_factor

@param dp_ptr :pointer to data point array
@param val :data point value to be searched
@param dps :pointer variable containing the information of interpolation length, index and factor */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

void function_sdps_s32(const sint32 * dp_ptr, sint32 val, DPS_RESULT * dps)
{
	/* ## Operation body start [daec3748-0fa8-4858-a30c-f14ca26478fd] */
	const sint32 *ptr;
	sint64   diff;
	sint32   tmp,tmp_ptr;
	uint32   num_col, idx = 0, fac = 0;
	/* extract number of elements */
	num_col = (uint32)(*dp_ptr);
	/* pointer to point to last element of dp array */
	ptr = dp_ptr + num_col;
	if (val >= *ptr)
	{
		/* index will be set to higher index and factor will be zero when val exceeds higher limit */
		idx = (num_col - 1U);
	}
	else
	{
		if (val <= *(dp_ptr + 1))
		{
			/* index and factor will be zero when val exceeds lower limit */
		}
		else
		{
			/* find index and factor when val is within the limit */
			do
			{
				--ptr;
				tmp = (*ptr);
			}
			while (val < tmp);
			idx = (uint32) (((uint32)ptr - (uint32)dp_ptr)/4U) - 1U;
			diff = ((sint64)val - tmp);
			if (diff != 0)
			{
				tmp_ptr = *(ptr + 1)- tmp;
				fac = (uint16)(((uint64)diff << 16) / (uint32)tmp_ptr);
			}
			else
			{
				/* factor will be zero if val is matching to data point array element */
			}
		}
	}
	/* store interpolation length, index and factor inside dps */
	dps->line_count  = (uint8)num_col;
	dps->line_index  = (uint8)idx;
	dps->line_factor = (uint16)fac;
	/* ## Operation body end [daec3748-0fa8-4858-a30c-f14ca26478fd] */
}

/** This operation performs interpolation for 1D calibration curve of type uint8

@param map :pointer to 1D calibration curve
@param dpsx :pointer variable containing the information of interpolation length, index and factor
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint8 function_u8_ip1d_u8(const uint8 * map, const DPS_RESULT * dpsx)
{
	/* ## Operation body start [6ab94fd2-3841-4a6b-a19c-a1c68d0a7df7] */
	uint8  idx;
	uint16 fac;
	/* extract index and factor from dpsx */
	idx = dpsx->line_index;
	fac = dpsx->line_factor;
	/* static inline function call for interpolation */
	return function_ip1d_u8(map, idx, fac);

	/* ## Operation body end [6ab94fd2-3841-4a6b-a19c-a1c68d0a7df7] */
}

/** This operation performs interpolation for 1D calibration curve of type uint16

@param map :pointer to 1D calibration curve
@param dpsx :pointer variable containing the information of interpolation length, index and factor
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint16 function_u16_ip1d_u16(const uint16 * map, const DPS_RESULT * dpsx)
{
	/* ## Operation body start [9583049f-ec94-4a7f-b6ae-c94a14f34215] */
	uint8  idx;
	uint16 fac;
	uint32 ip1, ip2;
	/* extract index and factor from dpsx */
	idx = dpsx->line_index;
	fac = dpsx->line_factor;
	ip1 = (uint32)(*(map + idx));       /* first map value */
	if (fac > 0U)
	{
		ip2 = (uint32)(*(map + (idx + 1U))); /* second map value */
		/* static inline function call for interpolation */
		ip1 = function_u32_interpolate_u16(ip1, ip2, fac);
	}
	else
	{
		/* no interpolation is required if factor is zero */
	}
	return (uint16)ip1;

	/* ## Operation body end [9583049f-ec94-4a7f-b6ae-c94a14f34215] */
}

/** This operation performs interpolation for 1D calibration curve of type uint32

@param map :pointer to 1D calibration curve
@param dpsx :pointer variable containing the information of interpolation length, index and factor
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint32 function_u32_ip1d_u32(const uint32 * map, const DPS_RESULT * dpsx)
{
	/* ## Operation body start [2c07472b-a055-4e20-8506-ab8a4f03f977] */
	uint8  idx;
	uint16 fac;
	uint32 ip1, ip2;
	/* extract index and factor from dpsx */
	idx = dpsx->line_index;
	fac = dpsx->line_factor;
	ip1 = *(map + idx);     /* first map value */
	if (fac > 0U)
	{
		ip2 = *(map + (idx + 1U));   /* second map value */
		/* static inline function call for interpolation */
		ip1 = function_u32_interpolate_u32(ip1, ip2, fac);
	}
	else
	{
		/* no interpolation is required if factor is zero */
	}
	return ip1;

	/* ## Operation body end [2c07472b-a055-4e20-8506-ab8a4f03f977] */
}

/** This operation performs interpolation for 2D calibration map of type uint8

@param map :pointer to 2D calibration map
@param dpsx :pointer variable containing the information of interpolation length, index and factor for X axis
@param dpsy :pointer variable containing the information of interpolation length, index and factor for Y axis
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint8 function_u8_ip2d_u8(const uint8 * map, const DPS_RESULT * dpsx, const DPS_RESULT * dpsy)
{
	/* ## Operation body start [89553885-657b-4be1-9f81-17d4f915ea99] */
	uint8  idx_x, idx_y, num_col;
	uint16 fac_x, fac_y;
	/* extract indeces for x and y axes from dpsx and dpsy respectively */
	idx_x = dpsx->line_index;
	idx_y = dpsy->line_index;
	/* extract factors for x and y axes from dpsx and dpsy respectively*/
	fac_x = dpsx->line_factor;
	fac_y = dpsy->line_factor;
	/* extract number of columns in y axis from dpsy */
	num_col = dpsy->line_count;
	/* static inline function call for interpolation */
	return function_ip2d_u8(map, num_col, idx_x, idx_y, fac_x, fac_y);

	/* ## Operation body end [89553885-657b-4be1-9f81-17d4f915ea99] */
}

/** This operation shall perform interpolation for 2D calibration map of type uint16

@param map :pointer to 2D calibration map
@param dpsx :pointer variable containing the information of interpolation length, index and factor for X axis
@param dpsy :pointer variable containing the information of interpolation length, index and factor for Y axis
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint16 function_u16_ip2d_u16(const uint16 * map, const DPS_RESULT * dpsx, const DPS_RESULT * dpsy)
{
	/* ## Operation body start [743d46fa-e439-4e71-b296-bfd2d2dfe629] */
	uint8  idx_x, idx_y, num_col;
	uint16 fac_x, fac_y;

	/* extract indeces for x and y axes from dpsx and dpsy respectively */
	idx_x = dpsx->line_index;
	idx_y = dpsy->line_index;
	/* extract factors for x and y axes from dpsx and dpsy respectively*/
	fac_x = dpsx->line_factor;
	fac_y = dpsy->line_factor;
	/* extract number of columns in y axis from dpsy */
	num_col = dpsy->line_count;
	/* static inline function call for interpolation */
	return function_ip2d_u16(map, num_col, idx_x, idx_y, fac_x, fac_y);

	/* ## Operation body end [743d46fa-e439-4e71-b296-bfd2d2dfe629] */
}

/** This operation performs interpolation for 2D calibration map of type uint32

@param map :pointer to 2D calibration map
@param dpsx :pointer variable containing the information of interpolation length, index and factor for X axis
@param dpsy :pointer variable containing the information of interpolation length, index and factor for Y axis
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint32 function_u32_ip2d_u32(const uint32 * map, const DPS_RESULT * dpsx, const DPS_RESULT * dpsy)
{
	/* ## Operation body start [9600d973-7f9b-4659-808f-fbebeb22297f] */
	uint8    idx_x, idx_y, num_col;
	uint16   fac_x, fac_y;

	/* extract indeces for x and y axes from dpsx and dpsy respectively */
	idx_x = dpsx->line_index;
	idx_y = dpsy->line_index;
	/* extract factors for x and y axes from dpsx and dpsy respectively */
	fac_x = dpsx->line_factor;
	fac_y = dpsy->line_factor;
	/* extract number of columns in y axis from dpsy */
	num_col = dpsy->line_count;
	return function_ip2d_u32(map, num_col, idx_x, idx_y, fac_x, fac_y);

	/* ## Operation body end [9600d973-7f9b-4659-808f-fbebeb22297f] */
}

/** This operation performs interpolation for 3D calibration map of type uint8

@param map :pointer to 3D calibration map
@param dpsx :pointer variable containing the information of interpolation length, index and factor for X axis (dimension 1)
@param dpsy :pointer variable containing the information of interpolation length, index and factor for Y axis (dimension 2)
@param dpsz :pointer variable containing the information of interpolation length, index and factor for Z axis (dimension 3)
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint8 function_u8_ip3d_u8(const uint8 * map, const DPS_RESULT * dpsx, const DPS_RESULT * dpsy, const DPS_RESULT * dpsz)
{
	/* ## Operation body start [5f5dd173-665f-42f6-8f69-2c0c56c2d0dd] */
	uint8  idx_z, num_y;
	uint16 fac_z, num;
	uint32 tmp;
	sint32 res1, res2;
	/* extract index and factor of the third dimension */
	idx_z = dpsz->line_index;
	fac_z = dpsz->line_factor;
	/* extract number of elements of dim 2 */
	num_y = dpsy->line_count;
	num = ((uint16)(dpsx->line_count) * num_y);
	tmp = ((uint32)idx_z * num);
	/* function call for first interpolation (use fast assembler-function!) */
	res1 = (sint32)function_u8_ip2d_u8(&map[tmp], dpsx, dpsy);

	/* function call for interpolation only if factor on third dimension is available */
	if (fac_z > 0U)
	{
		res2 = (sint32)function_u8_ip2d_u8(&map[tmp + num], dpsx, dpsy);

		/* static inline function call for final interpolation */

		res1 = function_s32_interpolate_s16(res1, res2, fac_z);
	}
	else
	{
		/* no second interpolation if factor on 3rd dimesion is zero */
	}
	return (uint8)res1;

	/* ## Operation body end [5f5dd173-665f-42f6-8f69-2c0c56c2d0dd] */
}

/** This operation performs interpolation for 3D calibration map of type uint16

@param map :pointer to 3D calibration map
@param dpsx :pointer variable containing the information of interpolation length, index and factor for X axis (dimension 1)
@param dpsy :pointer variable containing the information of interpolation length, index and factor for X axis (dimension 2)
@param dpsz :pointer variable containing the information of interpolation length, index and factor for X axis (dimension 3)
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint16 function_u16_ip3d_u16(const uint16 * map, const DPS_RESULT * dpsx, const DPS_RESULT * dpsy, const DPS_RESULT * dpsz)
{
	/* ## Operation body start [7b94ac20-a731-425c-9149-e4b296f6b97c] */
	uint8  idx_z;
	uint16 num, fac_z;
	uint32 tmp, res1, res2;
	/* extract index and factor of the third dimension */
	idx_z = dpsz->line_index;
	fac_z = dpsz->line_factor;
	/* extract number of elements of dim 2 */
	res2 = (uint32)dpsy->line_count;
	num = (uint16)(res2 * dpsx->line_count);
	tmp = ((uint32)idx_z * num);
	/* static inline function call for first interpolation */
	res1 = (uint32)function_u16_ip2d_u16(&map[tmp], dpsx, dpsy);

	/* static inline function call for interpolation only if factor on third dimension is available */
	if (fac_z > 0U)
	{
		res2 = (uint32)function_u16_ip2d_u16(&map[tmp + num], dpsx, dpsy);

		/* static inline function call for final interpolation */
		res1 = function_u32_interpolate_u16(res1, res2, fac_z);
	}
	else
	{
		/* no second interpolation if factor for 3rd dimesion is zero */
	}
	return (uint16)res1;
	/* ## Operation body end [7b94ac20-a731-425c-9149-e4b296f6b97c] */
}

/** This operation performs interpolation for 4D calibration map of type uint8

@param map :pointer to 4D calibration map
@param dpsx_in :pointer variable containing the information of interpolation length, index and factor for inner X axis (dimension 1)
@param dpsy_in :pointer variable containing the information of interpolation length, index and factor for inner Y axis (dimension 2)
@param dpsx_out :pointer variable containing the information of interpolation length, index and factor for outer X axis (dimension 3)
@param dpsy_out :pointer variable containing the information of interpolation length, index and factor for outer Y axis (dimension 4)
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint8 function_u8_ip4d_u8(const uint8 * map, const DPS_RESULT * dpsx_in, const DPS_RESULT * dpsy_in, const DPS_RESULT * dpsx_out, const DPS_RESULT * dpsy_out)
{
	/* ## Operation body start [743e4029-f32b-4e1e-8ea1-b5c2a5912e02] */
	uint8  idx_x, idx_y, res1, res2;
	uint8  tmp_ip[2][2] = {{0,0}, {0,0}};
	uint16 num, fac_y, fac_x, fac1, fac2;
	uint32 tmp;
	/* extract index of the outer x and y axes */
	idx_x = dpsx_out->line_index;
	idx_y = dpsy_out->line_index;
	/* extract number of elements of inner x and y axes */
	res1 = dpsx_in->line_count;
	res2 = dpsy_in->line_count;
	num = ((uint16)res1 * res2);
	/* extract factors of outer x and y axes */
	fac_x = dpsx_out->line_factor;
	fac_y = dpsy_out->line_factor;
	/* extract number of elements of outer y axis */
	res1 = dpsy_out->line_count;
	tmp = (((uint32)idx_y + ((uint32)idx_x * res1)) * num);

	/* extract indeces for inner x and y axes */
	idx_x = dpsx_in->line_index;
	idx_y = dpsy_in->line_index;
	/* extract factors for inner x and y axes */
	fac1 = dpsx_in->line_factor;
	fac2 = dpsy_in->line_factor;
	/* static inline function call for first interpolation */
	tmp_ip[0][0] = function_ip2d_u8(&map[tmp], res2, idx_x, idx_y, fac1, fac2);
	if (fac_y > 0U)
	{
		/* static inline function call for second interpolation only if y factor is available */
		tmp_ip[0][1] = function_ip2d_u8(&map[tmp + num], res2, idx_x, idx_y, fac1, fac2);
	}
	if (fac_x > 0U)
	{
		/* static inline function call for third interpolation only if x factor is available */
		tmp_ip[1][0] = function_ip2d_u8(&map[tmp + ((uint32)res1 * num)], res2, idx_x, idx_y, fac1, fac2);
		if (fac_y > 0U)
		{
			/* static inline function call for fourth interpolation only if y factor is available */
			tmp_ip[1][1] = function_ip2d_u8(&map[tmp + ((uint32)(res1 + 1U) * num)], res2, idx_x, idx_y, fac1, fac2);
		}
	}
	/* static inline function call for final interpolation */
	return function_ip2d_u8(tmp_ip[0], 2, 0, 0, fac_x, fac_y);

	/* ## Operation body end [743e4029-f32b-4e1e-8ea1-b5c2a5912e02] */
}

/** This operation performs interpolation for 4D calibration map of type uint16

@param map :pointer to 4D calibration map
@param dpsx_in :pointer variable containing the information of interpolation length, index and factor for inner X axis (dimension 1)
@param dpsy_in :pointer variable containing the information of interpolation length, index and factor for inner Y axis (dimension 2)
@param dpsx_out :pointer variable containing the information of interpolation length, index and factor for outer X axis (dimension 3)
@param dpsy_out :pointer variable containing the information of interpolation length, index and factor for outer Y axis (dimension 4)
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint16 function_u16_ip4d_u16(const uint16 * map, const DPS_RESULT * dpsx_in, const DPS_RESULT * dpsy_in, const DPS_RESULT * dpsx_out, const DPS_RESULT * dpsy_out)
{
	/* ## Operation body start [6f67dffe-4392-436f-9115-d4ef9f7ca48f] */
	uint8  idx_x, idx_y, res1, res2;
	uint16 num, fac_y, fac_x, fac1, fac2;
	uint16 tmp_ip[2][2] = {{0,0}, {0,0}};
	uint32 tmp;
	/* extract indeces of the outer axes */
	idx_x = dpsx_out->line_index;
	idx_y = dpsy_out->line_index;
	/* extract number of elements of inner axes */
	res1 = dpsx_in->line_count;
	res2 = dpsy_in->line_count;
	num = ((uint16)res1 * res2);
	/* extract factor of outer y axis */
	fac_x = dpsx_out->line_factor;
	fac_y = dpsy_out->line_factor;
	/* extract number of elements of outer y axis */
	res1 = dpsy_out->line_count;
	tmp = (((uint32)idx_y + ((uint32)idx_x * res1)) * num);
	/* extract indeces for inner x and y axes */
	idx_x = dpsx_in->line_index;
	idx_y = dpsy_in->line_index;
	/* extract factors for inner x and y axes */
	fac1 = dpsx_in->line_factor;
	fac2 = dpsy_in->line_factor;
	/* static inline function call for first interpolation */
	tmp_ip[0][0] = function_ip2d_u16(&map[tmp], res2, idx_x, idx_y, fac1, fac2);
	if (fac_y > 0U)
	{
		/* static inline function call for second interpolation only if y factor is available */
		tmp_ip[0][1] = function_ip2d_u16(&map[tmp + num], res2, idx_x, idx_y, fac1, fac2);
	}
	if (fac_x > 0U)
	{
		/* static inline function call for third interpolation only if x factor is available */
		tmp_ip[1][0] = function_ip2d_u16(&map[tmp + ((uint32)num * res1)], res2, idx_x, idx_y, fac1, fac2);
		if (fac_y > 0U)
		{
			/* static inline function call for fourth interpolation only if y factor is available */
			tmp_ip[1][1] = function_ip2d_u16(&map[tmp + ((uint32)num * ((uint32)res1 + (uint32)1))], res2, idx_x, idx_y, fac1, fac2);
		}
	}
	/* static inline function call for final interpolation */
	return function_ip2d_u16(tmp_ip[0], 2, 0, 0, fac_x, fac_y);
	/* ## Operation body end [6f67dffe-4392-436f-9115-d4ef9f7ca48f] */
}

/** This operation performs interpolation for 1D calibration curve of type sint8

@param map :pointer to 1D calibration curve
@param dpsx :pointer variable containing the information of interpolation length, index and factor
@return :sint8 interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint8 function_s8_ip1d_s8(const sint8 * map, const DPS_RESULT * dpsx)
{
	/* ## Operation body start [4355646f-8921-4dab-ac56-c63ea48cadf2] */
	uint8  idx;
	uint16 fac;
	sint32 ip1, ip2;
	/* extract index and factor from dpsx */
	idx = dpsx->line_index;
	fac = dpsx->line_factor;
	ip1 = (sint32)*(map + idx);            /* first map value */
	if (fac > 0U)
	{
		ip2 = (sint32)*(map + (idx + 1U));      /* second map value */
		ip2 = ((ip2 - ip1) * (sint32)fac);
		/* static inline function call for interpolation */
		ip1 = function_s32_interpolate_u8(ip1, ip2);
	}
	else
	{
		/* no interpolation is required if factor is zero */
	}
	return (sint8)ip1;

	/* ## Operation body end [4355646f-8921-4dab-ac56-c63ea48cadf2] */
}

/** This operation performs interpolation for 1D calibration curve of type sint16

@param map :pointer to 1D calibration curve
@param dpsx :pointer variable containing the information of interpolation length, index and factor
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint16 function_s16_ip1d_s16(const sint16 * map, const DPS_RESULT * dpsx)
{
	/* ## Operation body start [f267da17-88c7-4cf2-9643-456c80f7fac7] */
	uint8  idx;
	uint16 fac;
	sint32 ip1, ip2;
	/* extract index and factor from dpsx */
	idx = dpsx->line_index;
	fac = dpsx->line_factor;
	ip1 = (sint32)*(map + idx);             /* first map value */
	if (fac > 0U)
	{
		ip2 = (sint32)*(map + (idx + 1U));       /* second map value */
		/* static inline function call for interpolation */
		ip1 = function_s32_interpolate_s16(ip1, ip2, fac);
	}
	else
	{
		/* no interpolation is required if factor is zero */
	}
	return (sint16)ip1;

	/* ## Operation body end [f267da17-88c7-4cf2-9643-456c80f7fac7] */
}

/** This operation performs interpolation for 1D calibration curve of type sint32

@param map :pointer to 1D calibration curve
@param dpsx :pointer variable containing the information of interpolation length, index and factor
@return :sint32 interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint32 function_s32_ip1d_s32(const sint32 * map, const DPS_RESULT * dpsx)
{
	/* ## Operation body start [77d933b5-ebd4-4f6a-82df-766e1847cf39] */
	uint8  idx;
	uint16 fac;
	sint32 ip1, ip2;
	/* extract index and factor from dpsx */
	idx = dpsx->line_index;
	fac = dpsx->line_factor;
	ip1 = *(map + idx);         /* first map value */
	if (fac > 0U)
	{
		ip2 = *(map + (idx + 1U));   /* second map value */
		/* static inline function call for interpolation */
		ip1 = function_s32_interpolate_s32(ip1, ip2, fac);
	}
	else
	{
		/* no interpolation is required if factor is zero */
	}
	return ip1;

	/* ## Operation body end [77d933b5-ebd4-4f6a-82df-766e1847cf39] */
}

/** This operation performs interpolation for 2D calibration map of type sint8

@param map :pointer to 2D calibration map
@param dpsx :pointer variable containing the information of interpolation length, index and factor for X axis
@param dpsy :pointer variable containing the information of interpolation length, index and factor for Y axis
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint8 function_s8_ip2d_s8(const sint8 * map, const DPS_RESULT * dpsx, const DPS_RESULT * dpsy)
{
	/* ## Operation body start [34e0172d-ec27-4397-95e1-54ea2b0d53a7] */
	uint8  idx_x, idx_y, num_col;
	uint16 fac_x, fac_y;
	/* extract indeces for x and y axes from dpsx and dpsy respectively */
	idx_x = dpsx->line_index;
	idx_y = dpsy->line_index;
	/* extract factors for x and y axes from dpsx and dpsy respectively*/
	fac_x = dpsx->line_factor;
	fac_y = dpsy->line_factor;
	/* extract number of columns in y axis from dpsy */
	num_col = dpsy->line_count;
	/* static inline function call for interpolation */
	return function_ip2d_s8(map, num_col, idx_x, idx_y, fac_x, fac_y);

	/* ## Operation body end [34e0172d-ec27-4397-95e1-54ea2b0d53a7] */
}

/** This operation performs interpolation for 2D calibration map of type sint16

@param map :pointer to 2D calibration map
@param dpsx :pointer variable containing the information of interpolation length, index and factor for X axis
@param dpsy :pointer variable containing the information of interpolation length, index and factor for Y axis
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint16 function_s16_ip2d_s16(const sint16 * map, const DPS_RESULT * dpsx, const DPS_RESULT * dpsy)
{
	/* ## Operation body start [ca430788-599d-44cf-a5ee-3e803145b940] */
	uint8  idx_x, idx_y, num_col;
	uint16 fac_x, fac_y;

	/* extract indeces for x and y axes from dpsx and dpsy respectively */
	idx_x = dpsx->line_index;
	idx_y = dpsy->line_index;
	/* extract factors for x and y axes from dpsx and dpsy respectively*/
	fac_x = dpsx->line_factor;
	fac_y = dpsy->line_factor;
	/* extract number of columns in y axis from dpsy */
	num_col = dpsy->line_count;
	/* static inline function call for interpolation */
	return function_ip2d_s16(map, num_col, idx_x, idx_y, fac_x, fac_y);

	/* ## Operation body end [ca430788-599d-44cf-a5ee-3e803145b940] */
}

/** This operation performs interpolation for 2D calibration map of type sint32

@param map :pointer to 2D calibration map
@param dpsx :pointer variable containing the information of interpolation length, index and factor for X axis
@param dpsy :pointer variable containing the information of interpolation length, index and factor for Y axis
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint32 function_s32_ip2d_s32(const sint32 * map, const DPS_RESULT * dpsx, const DPS_RESULT * dpsy)
{
	/* ## Operation body start [38d09c24-62e5-4651-95b8-3236e36efdf1] */
	uint8    idx_x, idx_y, num_col;
	uint16   fac_x, fac_y;

	/* extract indeces for x and y axes from dpsx and dpsy respectively */
	idx_x = dpsx->line_index;
	idx_y = dpsy->line_index;
	/* extract factors for x and y axes from dpsx and dpsy respectively */
	fac_x = dpsx->line_factor;
	fac_y = dpsy->line_factor;
	/* extract number of columns in y axis from dpsy */
	num_col = dpsy->line_count;
	return function_ip2d_s32(map, num_col, idx_x, idx_y, fac_x, fac_y);

	/* ## Operation body end [38d09c24-62e5-4651-95b8-3236e36efdf1] */
}

/** This operation performs interpolation for 3D calibration map of type sint8

@param map :pointer to 3D calibration map
@param dpsx :pointer variable containing the information of interpolation length, index and factor for X axis (dimension 1)
@param dpsy :pointer variable containing the information of interpolation length, index and factor for Y axis (dimension 2)
@param dpsz :pointer variable containing the information of interpolation length, index and factor for Z axis (dimension 3)
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint8 function_s8_ip3d_s8(const sint8 * map, const DPS_RESULT * dpsx, const DPS_RESULT * dpsy, const DPS_RESULT * dpsz)
{
	/* ## Operation body start [9c74a80a-51b3-4ee0-b0c4-3f05a5b9aedc] */
	uint8  idx_z, num_y;
	uint16 fac_z, num;
	uint32 tmp;
	sint32 res1, res2;
	/* extract index and factor of the third dimension */
	idx_z = dpsz->line_index;
	fac_z = dpsz->line_factor;
	/* extract number of elements of dim 2 */
	num_y = dpsy->line_count;
	num = ((uint16)dpsx->line_count * num_y);
	tmp = ((uint32)idx_z * num);
	/* function call for first interpolation (use fast assembler-function!) */
	res1 = (sint32)function_s8_ip2d_s8(&map[tmp], dpsx, dpsy);

	/* function call for interpolation only if factor on third dimension is available */
	if (fac_z > 0U)
	{
		res2 = (sint32)function_s8_ip2d_s8(&map[tmp + num], dpsx, dpsy);

		/* static inline function call for final interpolation */
		res1 = function_s32_interpolate_s16(res1, res2, fac_z);
	}
	else
	{
		/* no second interpolation if factor on 3rd dimesion is zero */
	}
	return (sint8)res1;

	/* ## Operation body end [9c74a80a-51b3-4ee0-b0c4-3f05a5b9aedc] */
}

/** This operation performs interpolation for 3D calibration map of type sint16

@param map :pointer to 3D calibration map
@param dpsx :pointer variable containing the information of interpolation length, index and factor for X axis (dimension 1)
@param dpsy :pointer variable containing the information of interpolation length, index and factor for Y axis (dimension 2)
@param dpsz :pointer variable containing the information of interpolation length, index and factor for Z axis (dimension 3)
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint16 function_s16_ip3d_s16(const sint16 * map, const DPS_RESULT * dpsx, const DPS_RESULT * dpsy, const DPS_RESULT * dpsz)
{
	/* ## Operation body start [b21d3f41-0171-4203-b775-81c641f34620] */
	uint8  idx_z, num_y;
	uint16 fac_z, num;
	uint32 tmp;
	sint32 ip1, ip2;
	/* extract index and factor of the third dimension */
	idx_z = dpsz->line_index;
	fac_z = dpsz->line_factor;
	/* extract number of elements of dim 2 */
	num_y = dpsy->line_count;
	num = (uint16)dpsx->line_count * num_y;
	tmp = ((uint32)idx_z * num);
	/* static inline function call for first interpolation */
	ip1 = (sint32)function_s16_ip2d_s16(&map[tmp], dpsx, dpsy);
	/* static inline function call for interpolation only if factor on third dimension is available */
	if (fac_z > 0U)
	{
		ip2 = (sint32)function_s16_ip2d_s16(&map[tmp + num], dpsx, dpsy);

		/* static inline function call for final interpolation */
		ip1 = function_s32_interpolate_s16(ip1, ip2, fac_z);
	}
	else
	{
		/* no second interpolation if factor for 3rd dimesion is zero */
	}
	return (sint16)ip1;

	/* ## Operation body end [b21d3f41-0171-4203-b775-81c641f34620] */
}

/** This operation performs interpolation for 4D calibration map of type sint8

@param map :pointer to 4D calibration map
@param dpsx_in :pointer variable containing the information of interpolation length, index and factor for inner X axis (dimension 1)
@param dpsy_in :pointer variable containing the information of interpolation length, index and factor for inner Y axis (dimension 2)
@param dpsx_out :pointer variable containing the information of interpolation length, index and factor for outer X axis (dimension 3)
@param dpsy_out :pointer variable containing the information of interpolation length, index and factor for outer Y axis (dimension 4)
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint8 function_s8_ip4d_s8(const sint8 * map, const DPS_RESULT * dpsx_in, const DPS_RESULT * dpsy_in, const DPS_RESULT * dpsx_out, const DPS_RESULT * dpsy_out)
{
	/* ## Operation body start [13c46bb8-bd44-4778-aa9c-687066827e3b] */
	uint8  idx_x, idx_y, res1, res2;
	sint8  tmp_ip[2][2] = {{0,0}, {0,0}};
	uint16 num, fac_y, fac_x, fac1, fac2;
	uint32 tmp;
	/* extract index of the outer x and y axes */
	idx_x = dpsx_out->line_index;
	idx_y = dpsy_out->line_index;
	/* extract number of elements of x and y axes */
	res1 = dpsx_in->line_count;
	res2 = dpsy_in->line_count;

	num= ((uint16)res1 * res2);
	/* extract factor of outer x and y axes */
	fac_x = dpsx_out->line_factor;
	fac_y = dpsy_out->line_factor;
	/* extract number of elements of outer y axis */
	res1 = dpsy_out->line_count;
	tmp = (((uint32)idx_y + ((uint32)idx_x * res1)) * num);
	/* extract indeces for inner x and y axes */
	idx_x = dpsx_in->line_index;
	idx_y = dpsy_in->line_index;
	/* extract factors for inner x and y axes */
	fac1 = dpsx_in->line_factor;
	fac2 = dpsy_in->line_factor;
	/* static inline function call for first interpolation */
	tmp_ip[0][0] = function_ip2d_s8(&map[tmp], res2, idx_x, idx_y, fac1, fac2);
	if (fac_y > 0U)
	{
		/* static inline function call for second interpolation only if y factor is available */
		tmp_ip[0][1] = function_ip2d_s8(&map[tmp + num], res2, idx_x, idx_y, fac1, fac2);
	}
	if (fac_x > 0U)
	{
		/* static inline function call for third interpolation only if x factor is available */
		tmp_ip[1][0] = function_ip2d_s8(&map[tmp + ((uint32)res1 * num)], res2, idx_x, idx_y, fac1, fac2);
		if (fac_y > 0U)
		{
			/* static inline function call for fourth interpolation only if y factor is available */
			tmp_ip[1][1] = function_ip2d_s8(&map[tmp + ((uint32)(res1 + 1U) * num)], res2, idx_x, idx_y, fac1, fac2);
		}
	}
	/* static inline function call for final interpolation */
	return function_ip2d_s8(tmp_ip[0], 2, 0, 0, fac_x, fac_y);

	/* ## Operation body end [13c46bb8-bd44-4778-aa9c-687066827e3b] */
}

/** This operation performs interpolation for 4D calibration map of type sint16

@param map :pointer to 4D calibration map
@param dpsx_in :pointer variable containing the information of interpolation length, index and factor for inner X axis (dimension 1)
@param dpsy_in :pointer variable containing the information of interpolation length, index and factor for inner Y axis (dimension 2)
@param dpsx_out :pointer variable containing the information of interpolation length, index and factor for outer X axis (dimension 3)
@param dpsy_out :pointer variable containing the information of interpolation length, index and factor for outer Y axis (dimension 4)
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint16 function_s16_ip4d_s16(const sint16 * map, const DPS_RESULT * dpsx_in, const DPS_RESULT * dpsy_in, const DPS_RESULT * dpsx_out, const DPS_RESULT * dpsy_out)
{
	/* ## Operation body start [c0f926e7-e170-4c76-a93d-7003f3b15919] */
	uint8  idx_x, idx_y, res1, res2;
	uint16 num, fac_y, fac_x, fac1, fac2;
	sint16 tmp_ip[2][2] = {{0,0}, {0,0}};
	uint32 tmp;
	/* extract indeces of the outer axes */
	idx_x = dpsx_out->line_index;
	idx_y = dpsy_out->line_index;
	/* extract number of elements of inner axes */
	res1 = dpsx_in->line_count;
	res2 = dpsy_in->line_count;
	num = ((uint16)res1 * res2);
	/* extract factor of outer y axis */
	fac_x = dpsx_out->line_factor;
	fac_y = dpsy_out->line_factor;
	/* extract number of elements of outer y axis */
	res1 = dpsy_out->line_count;
	tmp = (((uint32)idx_y + ((uint32)idx_x * res1)) * num);
	/* extract indeces for inner x and y axes */
	idx_x = dpsx_in->line_index;
	idx_y = dpsy_in->line_index;
	/* extract factors for inner x and y axes */
	fac1 = dpsx_in->line_factor;
	fac2 = dpsy_in->line_factor;
	/* static inline function call for first interpolation */
	tmp_ip[0][0] = function_ip2d_s16(&map[tmp], res2, idx_x, idx_y, fac1, fac2);
	if (fac_y > 0U)
	{
		/* static inline function call for second interpolation only if y factor is available */
		tmp_ip[0][1] = function_ip2d_s16(&map[tmp + num], res2, idx_x, idx_y, fac1, fac2);
	}
	if (fac_x > 0U)
	{
		/* static inline function call for third interpolation only if x factor is available */
		tmp_ip[1][0] = function_ip2d_s16(&map[tmp + ((uint32)res1 * num)], res2, idx_x, idx_y, fac1, fac2);
		if (fac_y > 0U)
		{
			/* static inline function call for fourth interpolation only if y factor is available */
			tmp_ip[1][1] = function_ip2d_s16(&map[tmp + ((uint32)(res1 + 1U) * num)], res2, idx_x, idx_y, fac1, fac2);
		}
	}
	return function_ip2d_s16(tmp_ip[0], 2, 0, 0, fac_x, fac_y);

	/* ## Operation body end [c0f926e7-e170-4c76-a93d-7003f3b15919] */
}

/** This operation performs interpolation for 1D high resolution calibration curve of type uint8 and returns the interpolated result as uint16 type

@param map :pointer to 1D calibration curve
@param dpsx :pointer variable containing the information of interpolation length, index and factor
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint16 function_u16_ip1d_u8(const uint8 * map, const DPS_RESULT * dpsx)
{
	/* ## Operation body start [e2a38471-0e31-440c-8aaa-50508bf4df12] */
	uint8  idx;
	uint16 fac;
	uint32 ip1, ip2;
	/* extract index and factor from dpsx */
	idx = dpsx->line_index;
	fac = dpsx->line_factor;
	ip1 = (uint32)(*(map + idx)) << 8;    /* first map value */
	if (fac > 0U)
	{
		ip2 = (uint32)(*(map + (idx + 1U))) << 8;      /* second map value */
		/* static inline function call for interpolation */
		ip1 = function_u32_interpolate_u16(ip1, ip2, fac);
	}
	else
	{
		/* no interpolation is required if factor is zero */
	}
	return (uint16)ip1;

	/* ## Operation body end [e2a38471-0e31-440c-8aaa-50508bf4df12] */
}

/** This operation performs interpolation for 2D high resolution calibration curve of type uint8 and returns the interpolated result as uint16 type

@param map :pointer to 2D calibration map
@param dpsx :pointer variable containing the information of interpolation length, index and factor for X axis
@param dpsy :pointer variable containing the information of interpolation length, index and factor for Y axis
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint16 function_u16_ip2d_u8(const uint8 * map, const DPS_RESULT * dpsx, const DPS_RESULT * dpsy)
{
	/* ## Operation body start [7548e9c5-c942-4d94-b6f3-ad4c6f6d7362] */
	uint8  num_col, idx_x, idx_y;
	uint16 fac_x, fac_y;

	/* extract indeces for x and y axes from dpsx and dpsy respectively */
	idx_x = dpsx->line_index;
	idx_y = dpsy->line_index;
	/* extract factors for x and y axes from dpsx and dpsy respectively*/
	fac_x = dpsx->line_factor;
	fac_y = dpsy->line_factor;
	/* extract number of columns in y axis from dpsy */
	num_col = dpsy->line_count;
	/* static inline function call for interpolation */
	return function_ip2d_u16_u8(map, num_col, idx_x, idx_y, fac_x, fac_y);

	/* ## Operation body end [7548e9c5-c942-4d94-b6f3-ad4c6f6d7362] */
}

/** This operation performs interpolation for 3D high resolution calibration curve of type uint8 and returns the interpolated result as uint16 type

@param map :pointer to 3D calibration map
@param dpsx :pointer variable containing the information of interpolation length, index and factor for X axis (dimension 1)
@param dpsy :pointer variable containing the information of interpolation length, index and factor for Y axis (dimension 2)
@param dpsz :pointer variable containing the information of interpolation length, index and factor for Z axis (dimension 3)
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint16 function_u16_ip3d_u8(const uint8 * map, const DPS_RESULT * dpsx, const DPS_RESULT * dpsy, const DPS_RESULT * dpsz)
{
	/* ## Operation body start [693d35aa-c8d8-4b27-9c05-a55c41703cf7] */
	uint8  idx_z;
	uint16 num, fac_z;
	uint32 tmp, res1, res2;

	/* extract index and factor of the third dimension */
	idx_z = dpsz->line_index;
	fac_z = dpsz->line_factor;
	/* extract number of elements of dim 2 */
	res2 = (uint32)dpsy->line_count;
	num = (uint16)(res2 * dpsx->line_count);
	tmp = ((uint32)idx_z * num);
	/* function call for first interpolation (use fast assembler-function!) */
	res1 = (uint32)function_u16_ip2d_u8(&map[tmp], dpsx, dpsy);

	/* function call for interpolation only if factor on third dimension is available */
	if (fac_z > 0U)
	{
		res2 = (uint32)function_u16_ip2d_u8(&map[tmp + num], dpsx, dpsy);
		/* static inline function call for final interpolation */

		res1 = function_u32_interpolate_u16(res1, res2, fac_z);
	}
	else
	{
		/* no second interpolation if factor on 3rd dimesion is zero */
	}
	return (uint16)res1;

	/*## Operation End*/

	/* ## Operation body end [693d35aa-c8d8-4b27-9c05-a55c41703cf7] */
}

/** This operation performs interpolation for 4D high resolution calibration curve of type uint8 and returns the interpolated result as uint16 type

@param map :pointer to 4D calibration map
@param dpsx_in :pointer variable containing the information of interpolation length, index and factor for inner X axis (dimension 1)
@param dpsy_in :pointer variable containing the information of interpolation length, index and factor for inner Y axis (dimension 2)
@param dpsx_out :pointer variable containing the information of interpolation length, index and factor for outer X axis (dimension 3)
@param dpsy_out :pointer variable containing the information of interpolation length, index and factor for outer Y axis (dimension 4)
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint16 function_u16_ip4d_u8(const uint8 * map, const DPS_RESULT * dpsx_in, const DPS_RESULT * dpsy_in, const DPS_RESULT * dpsx_out, const DPS_RESULT * dpsy_out)
{
	/* ## Operation body start [9ec06e4b-56e7-43b8-add1-fa3befa87e85] */
	uint8  idx_x, idx_y, res1, res2;
	uint16 num, fac_y, fac_x;
	uint16 tmp_ip[2][2] = {{0,0}, {0,0}};
	uint32 tmp;

	DPS_RESULT dpsx_out_final, dpsy_out_final;
	/* extract indeces of the outer axes */
	idx_x = dpsx_out->line_index;
	idx_y = dpsy_out->line_index;
	/* extract number of elements of inner axes */
	res1 = dpsx_in->line_count;
	res2 = dpsy_in->line_count;
	num = ((uint16)res1 * res2);
	/* extract factor of outer y axis */
	fac_x = dpsx_out->line_factor;
	fac_y = dpsy_out->line_factor;
	/* extract number of elements of outer y axis */
	res1 = dpsy_out->line_count;
	tmp = (((uint32)idx_y + ((uint32)idx_x * res1)) * num);
	/* function call for first interpolation */
	tmp_ip[0][0] = function_u16_ip2d_u8(&map[tmp], dpsx_in, dpsy_in);
	if (fac_y > 0U)
	{
		/* function call for second interpolation only if y factor is available */
		tmp_ip[0][1] = function_u16_ip2d_u8(&map[tmp + num], dpsx_in, dpsy_in);
	}
	if (fac_x > 0U)
	{
		/* function call for third interpolation only if x factor is available */
		tmp_ip[1][0] = function_u16_ip2d_u8(&map[tmp + ((uint32)res1 * num)], dpsx_in, dpsy_in);
		if (fac_y > 0U)
		{
			/* function call for fourth interpolation only if y factor is available */
			tmp_ip[1][1] = function_u16_ip2d_u8(&map[tmp + ((uint32)(res1 + 1U) * num)], dpsx_in, dpsy_in);

		}
	}
	/* final interpolation */

	dpsx_out_final.line_count = 2;
	dpsy_out_final.line_count = 2;

	dpsx_out_final.line_index = 0;
	dpsy_out_final.line_index  = 0;

	dpsx_out_final.line_factor = fac_x;
	dpsy_out_final.line_factor = fac_y;

	return function_u16_ip2d_u16(&tmp_ip[0][0], &dpsx_out_final, &dpsy_out_final);

	/* ## Operation body end [9ec06e4b-56e7-43b8-add1-fa3befa87e85] */
}

/** This operation performs interpolation for 1D high resolution calibration curve of type sint8 and returns the interpolated result as sint16 type

@param map :pointer to 1D calibration curve
@param dpsx :pointer variable containing the information of interpolation length, index and factor
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint16 function_s16_ip1d_s8(const sint8 * map, const DPS_RESULT * dpsx)
{
	/* ## Operation body start [4b2a3174-3983-4b96-89bd-4588eaa4116e] */
	uint8  idx;
	uint16 fac;
	sint32 ip1, ip2;
	/* extract index and factor from dpsx */
	idx = dpsx->line_index;
	fac = dpsx->line_factor;
	ip1 = (sint32)(*(map + idx)) * 256;        /* first map value */
	if (fac > 0U)
	{
		ip2 = (sint32)(*(map + (idx + 1U))) * 256;    /* second map value */

		/* static inline function call for interpolation */
		ip1 = function_s32_interpolate_s16(ip1, ip2, fac);
	}
	else
	{
		/* no interpolation is required if factor is zero */
	}
	return (sint16)ip1;

	/* ## Operation body end [4b2a3174-3983-4b96-89bd-4588eaa4116e] */
}

/** This operation performs interpolation for 2D high resolution calibration curve of type sint8 and returns the interpolated result as sint16 type

@param map :pointer to 2D calibration map
@param dpsx :pointer variable containing the information of interpolation length, index and factor for X axis
@param dpsy :pointer variable containing the information of interpolation length, index and factor for Y axis
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint16 function_s16_ip2d_s8(const sint8 * map, const DPS_RESULT * dpsx, const DPS_RESULT * dpsy)
{
	/* ## Operation body start [f501f0b1-324e-45bf-868d-085968802ad6] */
	uint8  idx_x, idx_y, num_col;
	uint16 fac_x, fac_y;
	/* extract indeces for x and y axes from dpsx and dpsy respectively */
	idx_x = dpsx->line_index;
	idx_y = dpsy->line_index;
	/* extract factors for x and y axes from dpsx and dpsy respectively*/
	fac_x = dpsx->line_factor;
	fac_y = dpsy->line_factor;
	/* extract number of columns in y axis from dpsy */
	num_col = dpsy->line_count;
	/* static inline function call for interpolation */
	return function_ip2d_s16_s8(map, num_col, idx_x, idx_y, fac_x, fac_y);

	/* ## Operation body end [f501f0b1-324e-45bf-868d-085968802ad6] */
}

/** This operation performs interpolation for 3D high resolution calibration curve of type sint8 and returns the interpolated result as sint16 type

@param map :pointer to 3D calibration map
@param dpsx :pointer variable containing the information of interpolation length, index and factor for X axis (dimension 1)
@param dpsy :pointer variable containing the information of interpolation length, index and factor for Y axis (dimension 2)
@param dpsz :pointer variable containing the information of interpolation length, index and factor for Z axis (dimension 3)
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint16 function_s16_ip3d_s8(const sint8 * map, const DPS_RESULT * dpsx, const DPS_RESULT * dpsy, const DPS_RESULT * dpsz)
{
	/* ## Operation body start [1d0e016a-a1d3-4089-b102-4b0daaf64095] */
	uint8  idx_z, num_y;
	uint16 fac_z, num;
	uint32 tmp;
	sint32 ip1, ip2;
	/* extract index and factor of the third dimension */
	idx_z = dpsz->line_index;
	fac_z = dpsz->line_factor;
	/* extract number of elements of dim 2 */
	num_y = dpsy->line_count;
	num = ((uint16)dpsx->line_count * num_y);
	tmp = ((uint32)idx_z * num);
	/* function call for first interpolation (use fast assembler-function!) */
	ip1 = (sint32)function_s16_ip2d_s8(&map[tmp], dpsx, dpsy);
	/* function call for interpolation only if factor on third dimension is available */
	if (fac_z > 0U)
	{
		ip2 = (sint32)function_s16_ip2d_s8(&map[tmp + num], dpsx, dpsy);

		/* static inline function call for final interpolation */
		ip1 = function_s32_interpolate_s16(ip1, ip2, fac_z);
	}
	else
	{
		/* no second interpolation if factor for 3rd dimesion is zero */
	}
	return (sint16)ip1;
	/* ## Operation body end [1d0e016a-a1d3-4089-b102-4b0daaf64095] */
}

/** This operation performs interpolation for 4D high resolution calibration curve of type sint8 and returns the interpolated result as sint16 type

@param map :pointer to 4D calibration map
@param dpsx_in :pointer variable containing the information of interpolation length, index and factor for inner X axis (dimension 1)
@param dpsy_in :pointer variable containing the information of interpolation length, index and factor for inner Y axis (dimension 2)
@param dpsx_out :pointer variable containing the information of interpolation length, index and factor for outer X axis (dimension 3)
@param dpsy_out :pointer variable containing the information of interpolation length, index and factor for outer Y axis (dimension 4)
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint16 function_s16_ip4d_s8(const sint8 * map, const DPS_RESULT * dpsx_in, const DPS_RESULT * dpsy_in, const DPS_RESULT * dpsx_out, const DPS_RESULT * dpsy_out)
{
	/* ## Operation body start [006ae993-320d-4efc-84e4-7176d94d9cbd] */
	uint8  idx_x, idx_y, res1, res2;
	uint16 num, fac_y, fac_x;
	sint16 tmp_ip[2][2] = {{0,0}, {0,0}};
	uint32 tmp;

	DPS_RESULT dpsx_out_final, dpsy_out_final;
	/* extract indeces of the outer axes */
	idx_x = dpsx_out->line_index;
	idx_y = dpsy_out->line_index;
	/* extract number of elements of inner axes */
	res1 = dpsx_in->line_count;
	res2 = dpsy_in->line_count;

	num = ((uint16)res1 * res2);
	/* extract factor of outer y axis */
	fac_x = dpsx_out->line_factor;
	fac_y = dpsy_out->line_factor;
	/* extract number of elements of outer y axis */
	res1 = dpsy_out->line_count;
	tmp = (((uint32)idx_y + ((uint32)idx_x * res1)) * num);
	/* function call for first interpolation */
	tmp_ip[0][0] = function_s16_ip2d_s8(&map[tmp], dpsx_in, dpsy_in);

	if (fac_y > 0U)
	{
		/* function call for second interpolation only if y factor is available */
		tmp_ip[0][1] = function_s16_ip2d_s8(&map[tmp + num], dpsx_in, dpsy_in);

	}
	if (fac_x > 0U)
	{
		/* function call for third interpolation only if x factor is available */
		tmp_ip[1][0] = function_s16_ip2d_s8(&map[tmp + ((uint32)res1 * num)], dpsx_in, dpsy_in);

		if (fac_y > 0U)
		{
			/* function call for fourth interpolation only if y factor is available */
			tmp_ip[1][1] = function_s16_ip2d_s8(&map[tmp + ((uint32)(res1 + 1U) * num)], dpsx_in, dpsy_in);

		}
	}
	/* final interpolation */

	dpsx_out_final.line_count = 2;
	dpsy_out_final.line_count = 2;

	dpsx_out_final.line_index = 0;
	dpsy_out_final.line_index  = 0;

	dpsx_out_final.line_factor = fac_x;
	dpsy_out_final.line_factor = fac_y;

	return function_s16_ip2d_s16(&tmp_ip[0][0], &dpsx_out_final, &dpsy_out_final);
	/* ## Operation body end [006ae993-320d-4efc-84e4-7176d94d9cbd] */
}

/** This operation performs interpolation for 1D high resolution calibration curve of type uint16 and returns the interpolated result as uint32 type

@param map :pointer to 1D calibration curve
@param dpsx :pointer variable containing the information of interpolation length, index and factor
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint32 function_u32_ip1d_u16(const uint16 * map, const DPS_RESULT * dpsx)
{
	/* ## Operation body start [467103dc-3c51-4d5c-805e-eb7cc7430339] */
	uint8  idx;
	uint16 fac;
	uint32 ip1, ip2;
	/* extract index and factor from dpsx */
	idx = dpsx->line_index;
	fac = dpsx->line_factor;
	ip1 = (uint32)(*(map + idx)) << 16;     /* first map value */
	if (fac > 0U)
	{
		ip2 = (uint32)(*(map + (idx + 1U))) << 16;   /* second map value */
		/* static inline function call for interpolation */
		ip1 = function_u32_interpolate_u32(ip1, ip2, fac);
	}
	else
	{
		/* no interpolation is required if factor is zero */
	}
	return ip1;

	/* ## Operation body end [467103dc-3c51-4d5c-805e-eb7cc7430339] */
}

/** This operation performs interpolation for 2D high resolution calibration curve of type uint16 and returns the interpolated result as uint32 type

@param map :pointer to 2D calibration map
@param dpsx :pointer variable containing the information of interpolation length, index and factor for X axis
@param dpsy :pointer variable containing the information of interpolation length, index and factor for Y axis
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint32 function_u32_ip2d_u16(const uint16 * map, const DPS_RESULT * dpsx, const DPS_RESULT * dpsy)
{
	/* ## Operation body start [eb3b0126-5c12-46ff-bca2-9e70b68d70c4] */
	uint8  idx_x, idx_y, num_col;
	uint16 fac_x, fac_y;

	/* extract indeces for x and y axes from dpsx and dpsy respectively */
	idx_x = dpsx->line_index;
	idx_y = dpsy->line_index;
	/* extract indeces for x and y axes from dpsx and dpsy respectively */
	fac_x = dpsx->line_factor;
	fac_y = dpsy->line_factor;
	/* extract number of columns in y axis from dpsy */
	num_col = dpsy->line_count;
	/* static inline function call for interpolation */
	return function_ip2d_u32_u16(map, num_col, idx_x, idx_y, fac_x, fac_y);
	/* ## Operation body end [eb3b0126-5c12-46ff-bca2-9e70b68d70c4] */
}

/** This operation performs interpolation for 3D high resolution calibration curve of type uint16 and returns the interpolated result as uint32 type

@param map :pointer to 3D calibration map
@param dpsx :pointer variable containing the information of interpolation length, index and factor for X axis (dimension 1)
@param dpsy :pointer variable containing the information of interpolation length, index and factor for Y axis (dimension 2)
@param dpsz :pointer variable containing the information of interpolation length, index and factor for Z axis (dimension 3)
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint32 function_u32_ip3d_u16(const uint16 * map, const DPS_RESULT * dpsx, const DPS_RESULT * dpsy, const DPS_RESULT * dpsz)
{
	/* ## Operation body start [8b4bdc9f-0591-4db2-9d1a-48129e251014] */
	uint8  idx_x, idx_y, idx_z;
	uint16 num, fac_z;
	uint16 fac_x, fac_y;
	uint32 tmp, res1, res2;

	/* extract index and factor of the third dimension */
	idx_z = dpsz->line_index;
	fac_z = dpsz->line_factor;
	/* extract number of elements of dim 2 */
	res2 = (uint32)dpsy->line_count;
	num = (uint16)(res2 * dpsx->line_count);
	tmp = ((uint32)idx_z * num);
	/* extract indeces for x and y axes from dpsx and dpsy respectively */
	idx_x = dpsx->line_index;
	idx_y = dpsy->line_index;
	/* extract indeces for x and y axes from dpsx and dpsy respectively */
	fac_x = dpsx->line_factor;
	fac_y = dpsy->line_factor;
	/* static inline function call for first interpolation */
	res1 = function_ip2d_u32_u16(&map[tmp], (uint8)res2, idx_x, idx_y, fac_x, fac_y);
	/* static inline function call for interpolation only if factor on third dimension is available */
	if (fac_z > 0U)
	{
		res2 = function_ip2d_u32_u16(&map[tmp + num], (uint8)res2, idx_x, idx_y, fac_x, fac_y);
		res1 = function_u32_interpolate_u32(res1, res2, fac_z);
	}
	else
	{
		/* no second interpolation if factor for 3rd dimesion is zero */
	}
	return res1;
	/* ## Operation body end [8b4bdc9f-0591-4db2-9d1a-48129e251014] */
}

/** This operation performs interpolation for 4D high resolution calibration curve of type uint16 and returns the interpolated result as uint32 type

@param map :pointer to 4D calibration map
@param dpsx_in :pointer variable containing the information of interpolation length, index and factor for inner X axis (dimension 1)
@param dpsy_in :pointer variable containing the information of interpolation length, index and factor for inner Y axis (dimension 2)
@param dpsx_out :pointer variable containing the information of interpolation length, index and factor for outer X axis (dimension 3)
@param dpsy_out :pointer variable containing the information of interpolation length, index and factor for outer Y axis (dimension 4)
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint32 function_u32_ip4d_u16(const uint16 * map, const DPS_RESULT * dpsx_in, const DPS_RESULT * dpsy_in, const DPS_RESULT * dpsx_out, const DPS_RESULT * dpsy_out)
{
	/* ## Operation body start [6c7f24bd-272d-4a4f-8bb7-c826c3cfadb3] */
	uint8  idx_x, idx_y, res1, res2;
	uint16 num, fac_y, fac_x, fac1, fac2;
	uint32 tmp_ip[2][2] = {{0,0}, {0,0}};
	uint32 tmp;

	/* extract indeces of the outer axes */
	idx_x = dpsx_out->line_index;
	idx_y = dpsy_out->line_index;
	/* extract number of elements of inner axes */
	res1 = dpsx_in->line_count;
	res2 = dpsy_in->line_count;
	num = ((uint16)res1 * res2);
	/* extract factor of outer y axis */
	fac_x = dpsx_out->line_factor;
	fac_y = dpsy_out->line_factor;
	/* extract number of elements of outer y axis */
	res1 = dpsy_out->line_count;
	tmp = (((uint32)idx_y + ((uint32)idx_x * res1)) * num);
	/* extract indeces for inner x and y axes */
	idx_x = dpsx_in->line_index;
	idx_y = dpsy_in->line_index;

	/* extract factors for inner x and y axes */
	fac1 = dpsx_in->line_factor;
	fac2 = dpsy_in->line_factor;

	/* static inline function call for first interpolation */
	tmp_ip[0][0] = function_ip2d_u32_u16(&map[tmp], res2, idx_x, idx_y, fac1, fac2);
	if (fac_y > 0U)
	{
		/* static inline function call for second interpolation only if y factor is available */
		tmp_ip[0][1] = function_ip2d_u32_u16(&map[tmp + num], res2, idx_x, idx_y, fac1, fac2);
	}
	if (fac_x > 0U)
	{
		/* static inline function call for third interpolation only if x factor is available */
		tmp_ip[1][0] = function_ip2d_u32_u16(&map[tmp + ((uint32)res1 * num)], res2, idx_x, idx_y, fac1, fac2);
		if (fac_y > 0U)
		{
			/* static inline function call for fourth interpolation only if y factor is available */
			tmp_ip[1][1] = function_ip2d_u32_u16(&map[tmp + ((uint32)(res1 + 1U) * num)], res2, idx_x, idx_y, fac1, fac2);
		}
	}
	return function_ip2d_u32(tmp_ip[0], 2, 0, 0, fac_x, fac_y);

	/* ## Operation body end [6c7f24bd-272d-4a4f-8bb7-c826c3cfadb3] */
}

/** This operation performs interpolation for 1D high resolution calibration curve of type sint16 and returns the interpolated result as sint32 type

@param map :pointer to 1D calibration curve
@param dpsx :pointer variable containing the information of interpolation length, index and factor
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint32 function_s32_ip1d_s16(const sint16 * map, const DPS_RESULT * dpsx)
{
	/* ## Operation body start [dd6c440a-1a8d-41cd-a973-83fbbe2f51d3] */
	uint8  idx;
	uint16 fac;
	sint32 ip1, ip2;

	/* extract index and factor from dpsx */
	idx = dpsx->line_index;
	fac = dpsx->line_factor;
	ip1 = (sint32)*(map + idx) * (sint32)65536;         /* first map value */
	if (fac > 0U)
	{
		ip2 = (sint32)*(map + (idx + 1U)) * (sint32)65536;   /* second map value */
		/* static inline function call for interpolation */
		ip1 = function_s32_interpolate_s32(ip1, ip2, fac);
	}
	return ip1;

	/* ## Operation body end [dd6c440a-1a8d-41cd-a973-83fbbe2f51d3] */
}

/** This operation performs interpolation for 2D high resolution calibration curve of type sint16 and returns the interpolated result as sint32 type

@param map :pointer to 2D calibration map
@param dpsx :pointer variable containing the information of interpolation length, index and factor for X axis
@param dpsy :pointer variable containing the information of interpolation length, index and factor for Y axis
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint32 function_s32_ip2d_s16(const sint16 * map, const DPS_RESULT * dpsx, const DPS_RESULT * dpsy)
{
	/* ## Operation body start [ab654b57-35f4-4ed1-a3b0-e9721d1a90ec] */
	uint8  idx_x, idx_y, num_col;
	uint16 fac_x, fac_y;

	/* extract indeces for x and y axes from dpsx and dpsy respectively */
	idx_x = dpsx->line_index;
	idx_y = dpsy->line_index;
	/* extract factors for x and y axes from dpsx and dpsy respectively */
	fac_x = dpsx->line_factor;
	fac_y = dpsy->line_factor;
	/* extract number of columns in y axis from dpsy */
	num_col = dpsy->line_count;
	return function_ip2d_s32_s16(map, num_col, idx_x, idx_y, fac_x, fac_y);
	/* ## Operation body end [ab654b57-35f4-4ed1-a3b0-e9721d1a90ec] */
}

/** This operation performs interpolation for 3D high resolution calibration curve of type sint16 and returns the interpolated result as sint32 type

@param map :pointer to 3D calibration map
@param dpsx :pointer variable containing the information of interpolation length, index and factor for X axis (dimension 1)
@param dpsy :pointer variable containing the information of interpolation length, index and factor for Y axis (dimension 2)
@param dpsz :pointer variable containing the information of interpolation length, index and factor for Z axis (dimension 3)
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint32 function_s32_ip3d_s16(const sint16 * map, const DPS_RESULT * dpsx, const DPS_RESULT * dpsy, const DPS_RESULT * dpsz)
{
	/* ## Operation body start [7d28f93c-4211-401a-b06b-175944cc24db] */
	uint8  idx_x, idx_y, idx_z, num_y;
	uint16 fac_x, fac_y, fac_z, num;
	uint32 tmp;
	sint32 ip1, ip2;
	/* extract index and factor of the third dimension */
	idx_z = dpsz->line_index;
	fac_z = dpsz->line_factor;
	/* extract number of elements of dim 2 */
	num_y = dpsy->line_count;
	num = ((uint16)dpsx->line_count * num_y);
	tmp = ((uint32)num * idx_z);
	/* extract indeces for x and y axes from dpsx and dpsy respectively */
	idx_x = dpsx->line_index;
	idx_y = dpsy->line_index;
	/* extract factor for x and y axes from dpsx and dpsy respectively */
	fac_x = dpsx->line_factor;
	fac_y = dpsy->line_factor;
	/* static inline function call for first interpolation */
	ip1 = function_ip2d_s32_s16(&map[tmp], num_y, idx_x, idx_y, fac_x, fac_y);
	/* static inline function call for interpolation only if factor on third dimension is available */
	if (fac_z > 0U)
	{
		ip2 = function_ip2d_s32_s16(&map[tmp + num], num_y, idx_x, idx_y, fac_x, fac_y);
		ip1 = function_s32_interpolate_s32(ip1, ip2, fac_z);
	}
	else
	{
		/* no second interpolation if factor for 3rd dimesion is zero */
	}
	return ip1;

	/* ## Operation body end [7d28f93c-4211-401a-b06b-175944cc24db] */
}

/** This operation performs interpolation for 4D high resolution calibration curve of type sint16 and returns the interpolated result as sint32 type

@param map :pointer to 4D calibration map
@param dpsx_in :pointer variable containing the information of interpolation length, index and factor for inner X axis (dimension 1)
@param dpsy_in :pointer variable containing the information of interpolation length, index and factor for inner Y axis (dimension 2)
@param dpsx_out :pointer variable containing the information of interpolation length, index and factor for outer X axis (dimension 3)
@param dpsy_out :pointer variable containing the information of interpolation length, index and factor for outer Y axis (dimension 4)
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint32 function_s32_ip4d_s16(const sint16 * map, const DPS_RESULT * dpsx_in, const DPS_RESULT * dpsy_in, const DPS_RESULT * dpsx_out, const DPS_RESULT * dpsy_out)
{
	/* ## Operation body start [fc7c83a9-ec08-4fc5-98db-7d7cd9e2a113] */
	uint8  idx_x, idx_y, res1, res2;
	uint16 num, fac_y, fac_x, fac1, fac2;
	sint32 tmp_ip[2][2] = {{0,0}, {0,0}};
	uint32 tmp;

	/* extract indeces of the outer axes */
	idx_x = dpsx_out->line_index;
	idx_y = dpsy_out->line_index;
	/* extract number of elements of inner axes */
	res1 = dpsx_in->line_count;
	res2 = dpsy_in->line_count;
	num = ((uint16)res1 * res2);
	fac_x = dpsx_out->line_factor;
	fac_y = dpsy_out->line_factor;
	/* extract number of elements of outer y axis */
	res1 = dpsy_out->line_count;
	tmp = (((uint32)idx_y + ((uint32)idx_x * res1)) * num);
	/* extract indeces for inner x and y axes */
	idx_x = dpsx_in->line_index;
	idx_y = dpsy_in->line_index;

	/* extract factors for inner x and y axes */
	fac1 = dpsx_in->line_factor;
	fac2 = dpsy_in->line_factor;

	/* static inline function call for first interpolation */
	tmp_ip[0][0] = function_ip2d_s32_s16(&map[tmp], res2, idx_x, idx_y, fac1, fac2);
	if (fac_y > 0U)
	{
		/* static inline function call for second interpolation only if y factor is available */
		tmp_ip[0][1] = function_ip2d_s32_s16(&map[tmp + num], res2, idx_x, idx_y, fac1, fac2);
	}
	if (fac_x > 0U)
	{
		/* static inline function call for third interpolation only if x factor is available */
		tmp_ip[1][0] = function_ip2d_s32_s16(&map[tmp + ((uint32)res1 * num)], res2, idx_x, idx_y, fac1, fac2);
		if (fac_y > 0U)
		{
			/* static inline function call for fourth interpolation only if y factor is available */
			tmp_ip[1][1] = function_ip2d_s32_s16(&map[tmp + ((uint32)(res1 + 1U) * num)], res2, idx_x, idx_y, fac1, fac2);
		}
	}
	return function_ip2d_s32(tmp_ip[0], 2, 0, 0, fac_x, fac_y);

	/* ## Operation body end [fc7c83a9-ec08-4fc5-98db-7d7cd9e2a113] */
}

/** This operation performs interpolation of calibration curve of type uint8 with equidistant data point steps.

@param map :pointer to 1D calibration curve
@param step_address :pointer to step address of Data point array
@param val :data point value to be searched
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint8 function_u8_ip1da_ptr_u8(const uint8 * map, const uint8 * step_address, uint8 val)
{
	/* ## Operation body start [999f0de3-9918-4ff4-8651-5bf07031a5fd] */
	uint8  step;
	uint16 fac;
	uint32 idx, reminder;
	/* obtain step value from the pointer*/
	step = *step_address;
	/* find index using data point value and step value */
	idx = (uint32)val / step;
	/* find factor using data point value and step value */
	reminder = (uint32)val % step;
	fac = (uint16)((reminder << 16) / step);
	/* static inline function call for interpolation */
	return function_ip1d_u8(map, (uint8)idx, fac);
	/* ## Operation body end [999f0de3-9918-4ff4-8651-5bf07031a5fd] */
}

/** This operation performs interpolation of calibration map of type uint8 with equidistant data point steps.

@param map :pointer to 2D calibration map
@param step_address :pointer to step address of data point arrays
@param val1 :X data point array value to be searched
@param val2 :Y data point array value to be searched
@return :interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint8 function_u8_ip2da_ptr_u8(const uint8 * map, const uint8 * step_address, uint8 val1, uint8 val2)
{
	/* ## Operation body start [2e501cf6-e54b-4cb0-b656-1a168be8b9e6] */
	uint8  step_x, step_y;
	uint16 fac_x, fac_y;
	uint32 rem_x, rem_y, idx_x, idx_y, num_col;
	step_x  = *step_address;               /* obtain line step size */
	step_y  = *(step_address+1);           /* obtain column step size */

	/* find indeces using data point value and step value */
	idx_x = (uint32)val1 / step_x;
	idx_y = (uint32)val2 / step_y;
	/* find reminder using data point value and step value */
	rem_x = (uint32)val1 % step_x;
	rem_y = (uint32)val2 % step_y;
	/* find number of columns */
	num_col = (uint32)(((uint32)256 / step_y) + 1U);
	/* find factors using for x and y axis */
	fac_x = (uint16)((rem_x << 16) / step_x);
	fac_y = (uint16)((rem_y << 16) / step_y);
	/* static inline function call for interpolation */
	return function_ip2d_u8(map, (uint8)num_col, (uint8)idx_x, (uint8)idx_y, fac_x, fac_y);
	/* ## Operation body end [2e501cf6-e54b-4cb0-b656-1a168be8b9e6] */
}

/** This operation determines table index for the given data point value in the given data point array of type uint8

@param dp_ptr :pointer to data point array
@param val :Data point value to be searched
@param dps :pointer variable which sets table index inside DPS_RESULT */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

void function_uids_u8(const uint8 * dp_ptr, uint8 val, DPS_RESULT * dps)
{
	/* ## Operation body start [61fe844b-318f-4af5-8a78-7a4aa40bea9c] */
	const uint8 *ptr;
	uint32   num_col, idx = 0;
	num_col = (uint32)*dp_ptr;
	/* pointer to point the last element in the data point array */
	ptr = dp_ptr + num_col;
	/* compare input value with highest data point array value*/
	if (val >= *ptr)
	{
		/* if input value >= highest data point value set index to index of last element in the data point array  */
		idx = (num_col -1U);
	}
	else
	{
		if (val <= *(dp_ptr + 1))
		{
			/* index will be zero when value is less than the lower limit */
		}
		else
		{
			/* search input point value in the data point array from top to bottom */
			/*~T*/

			do
			{
				--ptr;
			}
			while (val < (*ptr));
			idx = (((uint32)ptr - (uint32)dp_ptr) - 1U);
		}
	}
	dps->line_count = (uint8)num_col;
	dps->line_index = (uint8)idx;
	dps->line_factor= 0;

	/* ## Operation body end [61fe844b-318f-4af5-8a78-7a4aa40bea9c] */
}

/** This operation determines table index for the given data point value in the given data point array of type uint16

@param dp_ptr :pointer to data point array
@param val :Data point value to be searched
@param dps :pointer variable which sets table index inside DPS_RESULT */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

void function_uids_u16(const uint16 * dp_ptr, uint16 val, DPS_RESULT * dps)
{
	/* ## Operation body start [cb78db66-cc38-4ffa-9c47-f51d446c5f65] */
	const uint16 *ptr;
	uint32   num_col, idx = 0;
	num_col = (uint32)(*dp_ptr);
	/* pointer to point the last element in the data point array */
	ptr = dp_ptr + num_col;
	/* compare input value with highest data point array value*/
	if (val >= *ptr)
	{
		/* if input value >= highest data point value set index to index of last element in the data point array  */
		idx = (num_col -1U);
	}
	else
	{
		if (val <= *(dp_ptr + 1))
		{
			/* index will be zero when value is less than the lower limit */
		}
		else
		{
			/* search input point value in the data point array from top to bottom */
			do
			{
				--ptr;
			}
			while (val < (*ptr));
			idx = ((((uint32)ptr - (uint32)dp_ptr)/2U) - 1U);
		}
	}
	dps->line_count = (uint8)num_col;
	dps->line_index = (uint8)idx;
	dps->line_factor= 0;

	/* ## Operation body end [cb78db66-cc38-4ffa-9c47-f51d446c5f65] */
}

/** This operation determines table index for the given data point value in the given data point array of type sint8

@param dp_ptr :pointer to data point array
@param val :Data point value to be searched
@param dps :pointer variable which sets table index inside DPS_RESULT */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

void function_sids_s8(const sint8 * dp_ptr, sint8 val, DPS_RESULT * dps)
{
	/* ## Operation body start [8f515641-7886-4f5b-bb9a-fc30a2e36d1a] */
	const sint8 *ptr;
	uint32   num_col, idx = 0;
	num_col = (uint32)((uint8)*dp_ptr);
	/* pointer to point the last element in the data point array */
	ptr = dp_ptr + num_col;
	/* compare input value with highest data point array value*/
	if (val >= *ptr)
	{
		/* if input value >= highest data point value set index to index of last element in the data point array  */
		idx = (num_col -1U);
	}
	else
	{
		if (val <= *(dp_ptr + 1))
		{
			/* index will be zero when value is less than the lower limit */
		}
		else
		{
			/* search input point value in the data point array from top to bottom */
			do
			{
				--ptr;
			}
			while (val < (*ptr));
			idx = (((uint32)ptr - (uint32)dp_ptr) - 1U);
		}
	}
	dps->line_count = (uint8)num_col;
	dps->line_index = (uint8)idx;
	dps->line_factor= 0;
	/* ## Operation body end [8f515641-7886-4f5b-bb9a-fc30a2e36d1a] */
}

/** This operation determines table index for the given data point value in the given data point array of type sint16

@param dp_ptr :pointer to data point array
@param val :Data point value to be searched
@param dps :pointer variable which sets table index inside DPS_RESULT */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

void function_sids_s16(const sint16 * dp_ptr, sint16 val, DPS_RESULT * dps)
{
	/* ## Operation body start [8a00461c-e427-4cb5-be22-1c5994d21278] */
	const sint16 *ptr;
	uint32   num_col, idx = 0;
	num_col = (uint32)(uint16)(*dp_ptr);
	/* pointer to point the last element in the data point array */
	ptr = dp_ptr + num_col;
	/* compare input value with highest data point array value*/
	if (val >= *ptr)
	{
		/* if input value >= highest data point value set index to index of last element in the data point array  */
		idx = (num_col -1U);
	}
	else
	{
		if (val <= *(dp_ptr + 1))
		{
			/* index will be zero when value is less than the lower limit */
		}
		else
		{
			/* search input point value in the data point array from top to bottom */
			do
			{
				--ptr;
			}
			while (val < (*ptr));
			idx = ((((uint32)ptr - (uint32)dp_ptr)/2U) - 1U);
		}
	}
	dps->line_count = (uint8)num_col;
	dps->line_index = (uint8)idx;
	dps->line_factor= 0;

	/* ## Operation body end [8a00461c-e427-4cb5-be22-1c5994d21278] */
}

/** This operation determines table value for the given 2D table of type uint8 using the table indeces of the axis searched by the search routines

@param ptr :Pointer to 2D calibration table
@param dpsx :Pointer variable containing the information of table length and index for X aixs
@param dpsy :Pointer variable containing the information of table length and index for Y axis
@return :Table value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint8 function_u8_id2d_u8(const uint8 * ptr, const DPS_RESULT * dpsx, const DPS_RESULT * dpsy)
{
	/* ## Operation body start [08866720-43c0-4749-bd42-4656283796ce] */
	return *(ptr + (dpsx->line_index * dpsy->line_count) + dpsy->line_index);

	/* ## Operation body end [08866720-43c0-4749-bd42-4656283796ce] */
}

/** This operation determines table value for the given 2D table of type uint16 using the table indeces of the axis searched by the search routines

@param ptr :Pointer to 2D calibration table
@param dpsx :Pointer variable containing the information of table length and index for X axis
@param dpsy :Pointer variable containing the information of table length and index for Y axis
@return :Table value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint16 function_u16_id2d_u16(const uint16 * ptr, const DPS_RESULT * dpsx, const DPS_RESULT * dpsy)
{
	/* ## Operation body start [6cd9e282-50f4-44e5-84ef-955faeafee69] */
	return *(ptr + (dpsx->line_index * dpsy->line_count) + dpsy->line_index);

	/* ## Operation body end [6cd9e282-50f4-44e5-84ef-955faeafee69] */
}

/** This operation determines table value for the given 1D table of type uint8 with equidistant data point steps

@param ptr :pointer to 1D calibration table
@param step_address :pointer to step address of data point array
@param val :data point value to be searched
@return :Table value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint8 function_u8_id1da_ptr_u8(const uint8 * ptr, const uint8 * step_address, uint8 val)
{
	/* ## Operation body start [ba7cd055-34c9-4792-8e7a-b656a0e416c9] */
	return  *(ptr + (val / (*step_address)));

	/* ## Operation body end [ba7cd055-34c9-4792-8e7a-b656a0e416c9] */
}

/** This operation performs combined data point search and interpolation for 1D calibration curve of type uint8 and data point array of type uint8

@param ptr_map :Pointer to 1D calibration curve
@param dp_ptr :pointer to data point array
@param xval :Data point value to be searched
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint8 function_u8_ip_ptr_u8(const uint8 * ptr_map, const uint8 * dp_ptr, uint8 xval)
{
	/* ## Operation body start [05df9323-7b9b-4619-8bc1-3d3f860c5fa9] */
	DPS_RESULT x_dps;
	UDPS_U8(dp_ptr, xval, &x_dps);
	return U8_IP1D_U8(ptr_map, &x_dps);

	/* ## Operation body end [05df9323-7b9b-4619-8bc1-3d3f860c5fa9] */
}

/** This operation performs combined data point search and interpolation for 1D calibration curve of type uint8 and data point array of type uint16

@param ptr_map :Pointer to 1D calibration curve
@param dp_ptr :pointer to data point array
@param xval :Data point value to be searched
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint8 function_u8_ip_ptr_u16(const uint8 * ptr_map, const uint16 * dp_ptr, uint16 xval)
{
	/* ## Operation body start [766e258a-dcaf-4ebd-ae2b-34ce585032c6] */
	DPS_RESULT x_dps;
	UDPS_U16(dp_ptr, xval, &x_dps);
	return U8_IP1D_U8(ptr_map, &x_dps);
	/* ## Operation body end [766e258a-dcaf-4ebd-ae2b-34ce585032c6] */
}

/** This operation performs combined data point search and interpolation for 1D calibration curve of type uint16 and data point array of type uint8

@param ptr_map :Pointer to 1D calibration curve
@param dp_ptr :pointer to data point array
@param xval :Data point value to be searched
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint16 function_u16_ip_ptr_u8(const uint16 * ptr_map, const uint8 * dp_ptr, uint8 xval)
{
	/* ## Operation body start [91a57198-a43c-406d-a769-9154020acaf6] */
	DPS_RESULT x_dps;
	UDPS_U8(dp_ptr, xval, &x_dps);
	return U16_IP1D_U16(ptr_map, &x_dps);

	/* ## Operation body end [91a57198-a43c-406d-a769-9154020acaf6] */
}

/** This operation performs combined data point search and interpolation for 1D calibration curve of type uint16 and data point array of type uint16

@param ptr_map :Pointer to 1D calibration curve
@param dp_ptr :pointer to data point array
@param xval :Data point value to be searched
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint16 function_u16_ip_ptr_u16(const uint16 * ptr_map, const uint16 * dp_ptr, uint16 xval)
{
	/* ## Operation body start [e8ac36c5-ad0b-4f82-9c2c-16001f9e0198] */
	DPS_RESULT x_dps;
	UDPS_U16(dp_ptr, xval, &x_dps);
	return U16_IP1D_U16(ptr_map, &x_dps);
	/* ## Operation body end [e8ac36c5-ad0b-4f82-9c2c-16001f9e0198] */
}

/** This operation performs combined data point search and interpolation for 2D calibration map of type uint8 and X data point array of type uint8 and Y data point array of type uint8

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint8 function_u8_ip_ptr_u8_u8(const uint8 * ptr_map, const uint8 * xdp_ptr, const uint8 * ydp_ptr, uint8 xval, uint8 yval)
{
	/* ## Operation body start [18457760-50bd-4433-aefb-4fc30f33ceb4] */
	DPS_RESULT x_dps, y_dps;
	UDPS_U8(xdp_ptr, xval, &x_dps);
	UDPS_U8(ydp_ptr, yval, &y_dps);
	return U8_IP2D_U8(ptr_map, &x_dps, &y_dps);
	/* ## Operation body end [18457760-50bd-4433-aefb-4fc30f33ceb4] */
}

/** This operation performs combined data point search and interpolation for 2D calibration map of type uint8 and X data point array of type uint8 and Y data point array of type uint16

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint8 function_u8_ip_ptr_u8_u16(const uint8 * ptr_map, const uint8 * xdp_ptr, const uint16 * ydp_ptr, uint8 xval, uint16 yval)
{
	/* ## Operation body start [d4c18ff9-3c08-4816-b0b0-c295ec4ba985] */
	DPS_RESULT x_dps, y_dps;
	UDPS_U8(xdp_ptr, xval, &x_dps);
	UDPS_U16(ydp_ptr, yval, &y_dps);
	return U8_IP2D_U8(ptr_map, &x_dps, &y_dps);

	/* ## Operation body end [d4c18ff9-3c08-4816-b0b0-c295ec4ba985] */
}

/** This operation performs combined data point search and interpolation for 2D calibration map of type uint8 and X data point array of type uint16 and Y data point array of type uint8

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint8 function_u8_ip_ptr_u16_u8(const uint8 * ptr_map, const uint16 * xdp_ptr, const uint8 * ydp_ptr, uint16 xval, uint8 yval)
{
	/* ## Operation body start [e75372f9-a7a0-4e74-ac27-2aa92f85d981] */
	DPS_RESULT x_dps, y_dps;
	UDPS_U16(xdp_ptr, xval, &x_dps);
	UDPS_U8(ydp_ptr, yval, &y_dps);
	return U8_IP2D_U8(ptr_map, &x_dps, &y_dps);

	/* ## Operation body end [e75372f9-a7a0-4e74-ac27-2aa92f85d981] */
}

/** This operation performs combined data point search and interpolation for 2D calibration map of type uint8 and X data point array of type uint16 and Y data point array of type uint16

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint8 function_u8_ip_ptr_u16_u16(const uint8 * ptr_map, const uint16 * xdp_ptr, const uint16 * ydp_ptr, uint16 xval, uint16 yval)
{
	/* ## Operation body start [53e9427e-ff67-4fa0-934a-0053f82017f0] */
	DPS_RESULT x_dps, y_dps;
	UDPS_U16(xdp_ptr, xval, &x_dps);
	UDPS_U16(ydp_ptr, yval, &y_dps);
	return U8_IP2D_U8(ptr_map, &x_dps, &y_dps);

	/* ## Operation body end [53e9427e-ff67-4fa0-934a-0053f82017f0] */
}

/** This operation performs combined data point search and interpolation for 2D calibration map of type uint16 and X data point array of type uint8 and Y data point array of type uint8

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint16 function_u16_ip_ptr_u8_u8(const uint16 * ptr_map, const uint8 * xdp_ptr, const uint8 * ydp_ptr, uint8 xval, uint8 yval)
{
	/* ## Operation body start [fbf98b4d-0eea-4d40-ab53-a73c37f539f8] */
	DPS_RESULT x_dps, y_dps;
	UDPS_U8(xdp_ptr, xval, &x_dps);
	UDPS_U8(ydp_ptr, yval, &y_dps);
	return U16_IP2D_U16(ptr_map, &x_dps, &y_dps);

	/* ## Operation body end [fbf98b4d-0eea-4d40-ab53-a73c37f539f8] */
}

/** This operation performs combined data point search and interpolation for 2D calibration map of type uint16 and X data point array of type uint8 and Y data point array of type uint16

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint16 function_u16_ip_ptr_u8_u16(const uint16 * ptr_map, const uint8 * xdp_ptr, const uint16 * ydp_ptr, uint8 xval, uint16 yval)
{
	/* ## Operation body start [7e393d3a-61fc-48b7-a41c-622f6231c768] */
	DPS_RESULT x_dps, y_dps;
	UDPS_U8(xdp_ptr, xval, &x_dps);
	UDPS_U16(ydp_ptr, yval, &y_dps);
	return U16_IP2D_U16(ptr_map, &x_dps, &y_dps);

	/* ## Operation body end [7e393d3a-61fc-48b7-a41c-622f6231c768] */
}

/** This operation performs combined data point search and interpolation for 2D calibration map of type uint16 and X data point array of type uint16 and Y data point array of type uint8

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint16 function_u16_ip_ptr_u16_u8(const uint16 * ptr_map, const uint16 * xdp_ptr, const uint8 * ydp_ptr, uint16 xval, uint8 yval)
{
	/* ## Operation body start [7a6b5180-42f2-4130-9fa1-49dac468c853] */
	DPS_RESULT x_dps, y_dps;
	UDPS_U16(xdp_ptr, xval, &x_dps);
	UDPS_U8(ydp_ptr, yval, &y_dps);
	return U16_IP2D_U16(ptr_map, &x_dps, &y_dps);
	/* ## Operation body end [7a6b5180-42f2-4130-9fa1-49dac468c853] */
}

/** This operation performs combined data point search and interpolation for 2D calibration map of type uint16 and X data point array of type uint16 and Y data point array of type uint16

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint16 function_u16_ip_ptr_u16_u16(const uint16 * ptr_map, const uint16 * xdp_ptr, const uint16 * ydp_ptr, uint16 xval, uint16 yval)
{
	/* ## Operation body start [40aa5875-040d-4fcd-8950-3cc4a1ace47d] */
	DPS_RESULT x_dps, y_dps;
	UDPS_U16(xdp_ptr, xval, &x_dps);
	UDPS_U16(ydp_ptr, yval, &y_dps);
	return U16_IP2D_U16(ptr_map, &x_dps, &y_dps);
	/* ## Operation body end [40aa5875-040d-4fcd-8950-3cc4a1ace47d] */
}

/** This operation performs combined data point search and interpolation for 2D calibration map of type uint32 and X data point array of type uint8 and Y data point array of type uint16

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint32 function_u32_ip_ptr_u8_u16(const uint32 * ptr_map, const uint8 * xdp_ptr, const uint16 * ydp_ptr, uint8 xval, uint16 yval)
{
	/* ## Operation body start [3e6c369d-3806-46bc-b703-70dab465f7fc] */
	DPS_RESULT x_dps, y_dps;
	UDPS_U8(xdp_ptr, xval, &x_dps);
	UDPS_U16(ydp_ptr, yval, &y_dps);
	return U32_IP2D_U32(ptr_map, &x_dps, &y_dps);

	/* ## Operation body end [3e6c369d-3806-46bc-b703-70dab465f7fc] */
}

/** This operation performs combined data point search and interpolation for 2D calibration map of type uint32 and X data point array of type uint16 and Y data point array of type uint16

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint32 function_u32_ip_ptr_u16_u16(const uint32 * ptr_map, const uint16 * xdp_ptr, const uint16 * ydp_ptr, uint16 xval, uint16 yval)
{
	/* ## Operation body start [3cba9d50-6707-49da-bea1-1b8ce233bb56] */
	DPS_RESULT x_dps, y_dps;
	UDPS_U16(xdp_ptr, xval, &x_dps);
	UDPS_U16(ydp_ptr, yval, &y_dps);
	return U32_IP2D_U32(ptr_map, &x_dps, &y_dps);

	/* ## Operation body end [3cba9d50-6707-49da-bea1-1b8ce233bb56] */
}

/** This operation performs combined relative data point search and interpolation for 1D calibration curve of type uint8 and data point array of type uint8

@param ptr_map :Pointer to 1D calibration curve
@param dp_ptr :pointer to data point array
@param xval :Data point value to be searched
@param idxp :Pointer pointing to the location of array from which data point search has to be started
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint8 function_u8_ip_rel_ptr_u8_idxp(const uint8 * ptr_map, const uint8 * dp_ptr, uint8 xval, uint8 * idxp)
{
	/* ## Operation body start [718eedfc-24fa-4207-8d06-8e4ec75c9262] */
	uint32   tmp_xval, rel_idx, tmp_product;   /* temporary variable to store intermediate results */
	uint32   x_factor;                         /* stores the line factor and intermediate values */
	const uint8  *tmp_ptr;
	const uint8  *ip_ptr;                      /* pointer to map array */
	sint32   diff;                             /* variable to store intermediate results */
	uint8 temp1_u8;

	/* assign input value to temporary variable */
	tmp_xval = xval;
	/* assign relative pointer to temporary variable */
	rel_idx = *idxp;

	/* compare relative pointer contents with the actual data elements in data point array*/
	if (rel_idx >= *dp_ptr)
	{
		/* point relative pointer to last element in data point array */
		rel_idx  =  *dp_ptr ;
		rel_idx-- ;
	}
	/* pointer to point to the the data point value pointed by relative pointer */
	tmp_ptr = dp_ptr + (rel_idx + 1U);

	/* compare input point value with data point array value pointed by relative pointer */
	if(tmp_xval >= *tmp_ptr)
	{
		/*~A*/
		/*~+:Search data point value in upper portion of the data point array*/
		/* compare input point value with highest data point array value */
		temp1_u8 = *(dp_ptr + (*dp_ptr));
		if (tmp_xval >= (uint32)temp1_u8)
		{
			/* set relative pointer to last value in data point  array */

			temp1_u8 = (*dp_ptr -1U) ;
			*idxp = temp1_u8  ;
			/* return the last value from the calibration map */
			temp1_u8 = *(ptr_map +(*dp_ptr -1U));
		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to top*/
			do
			{
				++tmp_ptr;
				x_factor = (uint32)*tmp_ptr;
			}
			while ( x_factor <= tmp_xval );
			/* realtive pointer index calculation*/
			rel_idx = (uint32)(((uint32)tmp_ptr - (uint32)dp_ptr) - 2U);
			*idxp = (uint8)rel_idx;
			/* line factor calculation */
			temp1_u8 = *(tmp_ptr - 1U);
			x_factor = ((tmp_xval - temp1_u8 )<<16) / (uint32)(x_factor - temp1_u8 );

			if (x_factor == 0U )
			{
				/* if input value is equal to one of the data point value return the value pointed by the updated relative pointer */
				temp1_u8 = *( ptr_map + rel_idx);
			}
			else
			{
				/* temporary pointer to point to a value in calibration map */
				ip_ptr = ptr_map + rel_idx;

				/*interpolate the value */
				diff = (sint32)(ip_ptr[1] - ip_ptr[0]);/* ip_ptr is a pointer , here referred as a array */

				if (diff >= 0)
				{
					tmp_product = (uint32)diff * x_factor;
					temp1_u8 = (uint8)(*ip_ptr + (tmp_product/65536U) + (((tmp_product % 65536U) * 2U)/65536U));
				}
				else
				{
					tmp_product = (uint32)(-diff) * x_factor;
					temp1_u8 = (uint8)((*ip_ptr - (tmp_product/65536U)) -(((tmp_product % 65536U) * 2U) /65536U));
				}
			}
		}
		/*~E*/
	}
	else
	{
		/*~A*/
		/*~+:Search data point value in lower portion of the data point array*/
		/* compare input point value with lowest data point array value */
		temp1_u8 = *(dp_ptr + 1U);
		if ( tmp_xval <= temp1_u8 )
		{
			/* set relative pointer to first value in data point  array */
			*idxp = 0U;
			/* return the first value from the calibration map */
			temp1_u8 = *(ptr_map);
		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to bottom */
			do
			{
				--tmp_ptr;
				x_factor = *tmp_ptr;
				diff = (sint32)(tmp_xval - x_factor);
			}
			while (diff < (sint16)0);
			/* realtive pointer index calculation*/
			rel_idx= (uint32)(((uint32)tmp_ptr - (uint32)dp_ptr) - 1U);
			*idxp = (uint8)rel_idx;
			if (diff == (sint16)0)
			{
				/* if input value is equal to one of the data point value return the value pointed by the updated relative pointer */
				temp1_u8 = *(ptr_map + rel_idx);
			}
			else
			{
				/* if input value lies in between any 2 data point values in the array calculate line factor */
				temp1_u8 = *(tmp_ptr + 1U);
				x_factor = ((uint32)diff<<16U) / (uint32)(temp1_u8 -x_factor);

				/* temporary pointer to point to a value in calibration map */
				ip_ptr = ptr_map + rel_idx;

				/* interpolate the value */
				diff = (sint32)(ip_ptr[1] - ip_ptr[0]);/* ip_ptr is a pointer , here referred as a array */
				if (diff >= (sint16)0)
				{
					tmp_product = (uint32)diff * x_factor;
					temp1_u8 = (uint8)(*ip_ptr + (tmp_product/65536U) + (((tmp_product % 65536U) * 2U)/65536U));
				}
				else
				{
					tmp_product = (uint32)(-diff) * x_factor;
					temp1_u8 = (uint8)((*ip_ptr - (tmp_product/65536U)) -(((tmp_product % 65536U) * 2U) /65536U));
				}
			}
		}
		/*~E*/
	}
	return temp1_u8;


	/* ## Operation body end [718eedfc-24fa-4207-8d06-8e4ec75c9262] */
}

/** This operation performs combined relative data point search and interpolation for 1D calibration curve of type uint8 and data point array of type uint16

@param ptr_map :Pointer to 1D calibration curve
@param dp_ptr :pointer to data pointer array
@param xval :Data point value to be searched
@param idxp :Pointer pointing to the location of array from which data point search has to be started
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint8 function_u8_ip_rel_ptr_u16_idxp(const uint8 * ptr_map, const uint16 * dp_ptr, uint16 xval, uint8 * idxp)
{
	/* ## Operation body start [85c1d456-f854-46b0-9ab8-c7190a3d3f98] */
	uint32   tmp_xval, rel_idx,tmp_product;  /* temporary variable to store intermediate results */
	uint32   x_factor;                       /* stores the line factor */
	const uint16 *tmp_ptr;
	const uint8  *ip_ptr;                    /* pointer to map array */
	sint32   diff;                           /* variable to store intermediate results */
	uint8 temp1_u8;
	uint16 temp1_u16;

	/* assign input value to temporary variable */
	tmp_xval = xval;
	/* assign relative pointer to temporary variable */
	rel_idx = *idxp;

	/* compare relative pointer contents with the actual data elements in data point array*/
	if (rel_idx >= *dp_ptr)
	{
		/* point relative pointer to last element in data point array */
		rel_idx  =  *dp_ptr ;
		rel_idx-- ;
	}
	/* pointer to point to the the data point value pointed by relative pointer */
	tmp_ptr = dp_ptr + (rel_idx + 1U);

	/* compare input point value with data point array value pointed by relative pointer */
	if(tmp_xval >= *tmp_ptr)
	{
		/*~A*/
		/*~+:Search data point value in upper portion of the data point array*/
		/* compare input point value with highest data point array value */
		if (tmp_xval >= dp_ptr[*dp_ptr] )
		{
			/* set relative pointer to last value in data point  array */
			*idxp = (uint8)(*dp_ptr - 1U);
			/* return the last value from the calibration map */
			temp1_u8 = *(ptr_map +(*dp_ptr -1U));
		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to top*/
			do
			{
				++tmp_ptr;
				x_factor = *tmp_ptr;
			}
			while (x_factor <= tmp_xval );
			/* realtive pointer index calculation*/
			rel_idx = (uint32)((((uint32)tmp_ptr - (uint32)dp_ptr)/2U) - 2U);
			*idxp = (uint8)rel_idx;
			/* line factor calculation */
			temp1_u16 = *(tmp_ptr - 1U);
			x_factor = ((tmp_xval - temp1_u16)<<16U) / (uint32)(x_factor - temp1_u16);

			if (x_factor == 0U)
			{
				/* if input value is equal to one of the data point value return the value pointed by the updated relative pointer */
				temp1_u8 =  *( ptr_map + rel_idx);
			}
			else
			{

				/* temporary pointer to point to a value in calibration map */
				ip_ptr = ptr_map + rel_idx;

				/*interpolate the value */
				diff = (sint32)(ip_ptr[1] - ip_ptr[0]);/* ip_ptr is a pointer , here referred as a array */
				if (diff >= (sint16)0)
				{
					tmp_product = (uint32)diff * x_factor;
					temp1_u8 =  (uint8)(((*ip_ptr) + (tmp_product/65536U)) + (((tmp_product % 65536U) * 2U)/65536U));
				}
				else
				{
					tmp_product = (uint32)(-diff) * x_factor;
					temp1_u8 =  (uint8)(((*ip_ptr) - (tmp_product/65536U)) -(((tmp_product % 65536U) * 2U) /65536U));
				}
			}
		}
		/*~E*/
	}
	else
	{
		/*~A*/
		/*~+:Search data point value in lower portion of the data point array*/
		/* compare input point value with lowest data point array value */
		if (tmp_xval <= dp_ptr[1] )
		{
			/* set relative pointer to first value in data point  array */
			*idxp = 0;
			/* return the first value from the calibration map */
			temp1_u8 =  *(ptr_map);
		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to bottom */
			do
			{
				--tmp_ptr;
				x_factor = *tmp_ptr;
				diff = (sint32)(tmp_xval - x_factor);
			}
			while (diff < (sint16)0);
			/* realtive pointer index calculation*/
			rel_idx= (uint32)((((uint32)tmp_ptr - (uint32)dp_ptr)/2U) - 1U);
			*idxp = (uint8)rel_idx;
			if (diff == (sint16)0)
			{
				/* if input value is equal to one of the data point value return the value pointed by the updated relative pointer */
				temp1_u8 =  *(ptr_map + rel_idx);
			}
			else
			{
				/* if input value lies in between any 2 data point values in the array calculate line factor */

				temp1_u16 = *(tmp_ptr + 1U);
				x_factor = ((uint32)diff<<16U) / (uint32)( temp1_u16 - x_factor  );

				/* temporary pointer to point to a value in calibration map */
				ip_ptr = ptr_map + rel_idx;

				/* interpolate the value */
				diff = (sint32)(ip_ptr[1] - ip_ptr[0]);/* ip_ptr is a pointer , here referred as a array */
				if (diff >= (sint16)0)
				{
					tmp_product = (uint32)diff * x_factor;
					temp1_u8 =  (uint8)(((*ip_ptr) + (tmp_product / 65536U) )+ (((tmp_product % 65536U) * 2U)/65536U));
				}
				else
				{
					tmp_product = (uint32)(-diff) * x_factor;
					temp1_u8 =  (uint8)(((*ip_ptr) - (tmp_product/65536U)) -(((tmp_product % 65536U) * 2U) /65536U));
				}
			}
		}
		/*~E*/
	}
	return temp1_u8;


	/* ## Operation body end [85c1d456-f854-46b0-9ab8-c7190a3d3f98] */
}

/** This operation performs combined relative data point search and interpolation for 1D calibration curve of type uint16 and data point array of type uint8

@param ptr_map :Pointer to 1D calibration curve
@param dp_ptr :pointer to data point array
@param xval :Data point value to be searched
@param idxp :Pointer pointing to the location of array from which data point search has to be started
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint16 function_u16_ip_rel_ptr_u8_idxp(const uint16 * ptr_map, const uint8 * dp_ptr, uint8 xval, uint8 * idxp)
{
	/* ## Operation body start [2316be31-832d-471f-b75c-67a3d89dfd80] */
	uint32   tmp_xval, rel_idx, tmp_product;   /* temporary variable to store intermediate results */
	uint32   x_factor;                         /* stores the line factor */
	const uint8 *tmp_ptr;
	const uint16 *ip_ptr;                      /* pointer to map array */
	sint32   diff;                             /* variable to store intermediate results */
	uint16 temp1_u16;
	uint8 temp1_u8;

	/* assign input value to temporary variable */
	tmp_xval = xval;
	/* assign relative pointer to temporary variable */
	rel_idx = *idxp;

	/* compare relative pointer contents with the actual data elements in data point array*/
	if (rel_idx >= *dp_ptr)
	{
		/* point relative pointer to last element in data point array */
		rel_idx  =  *dp_ptr ;
		rel_idx-- ;
	}
	/* pointer to point to the the data point value pointed by relative pointer */
	tmp_ptr = dp_ptr + (rel_idx + 1U);

	/* compare input point value with data point array value pointed by relative pointer */
	if(tmp_xval >= *tmp_ptr)
	{
		/*~A*/
		/*~+:Search data point value in upper portion of the data point array*/
		/* compare input point value with highest data point array value */
		temp1_u8 = *(dp_ptr + (*dp_ptr));
		if (tmp_xval >= temp1_u8)
		{
			/* set relative pointer to last value in data point  array */

			*idxp = *dp_ptr - 1U;
			/* return the last value from the calibration map */
			temp1_u8 = (*dp_ptr -1U);
			temp1_u16 = *(ptr_map + temp1_u8);
		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to top*/
			do
			{
				++tmp_ptr;
				x_factor = *tmp_ptr;
			}
			while (x_factor <= tmp_xval );
			/* realtive pointer index calculation*/
			rel_idx = (uint32)(((uint32)tmp_ptr - (uint32)dp_ptr) - 2U);
			*idxp = (uint8)rel_idx;
			/* line factor calculation */
			temp1_u8 = *(tmp_ptr - 1U);
			x_factor = ((tmp_xval - temp1_u8 )<<16U) / (uint32)(x_factor - temp1_u8 );

			if (x_factor == 0U)
			{
				/* if input value is equal to one of the data point value return the value pointed by the updated relative pointer */
				temp1_u16 =  *( ptr_map + rel_idx);
			}
			else
			{

				/* temporary pointer to point to a value in calibration map */
				ip_ptr = ptr_map + rel_idx;

				/*interpolate the value */
				diff = (sint32)(ip_ptr[1] - ip_ptr[0]);/* ip_ptr is a pointer , here referred as a array */
				if (diff >= (sint16)0)
				{
					tmp_product = (uint32)diff * x_factor;
					temp1_u16 =  (uint16)(((*ip_ptr) + (tmp_product/65536U) )+ (((tmp_product % 65536U) * 2U)/65536U));
				}
				else
				{
					tmp_product = (uint32)(-diff) * x_factor;
					temp1_u16 =  (uint16)(((*ip_ptr) - (tmp_product/65536U)) -(((tmp_product % 65536U) * 2U) /65536U));
				}
			}
		}
		/*~E*/
	}
	else
	{
		/*~A*/
		/*~+:Search data point value in lower portion of the data point array*/
		/* compare input point value with lowest data point array value */
		temp1_u8 = *(dp_ptr + 1U);
		if (tmp_xval <= temp1_u8 )
		{
			/* set relative pointer to first value in data point  array */
			*idxp = 0U;
			/* return the first value from the calibration map */
			temp1_u16 =  *(ptr_map);
		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to bottom */
			do
			{
				--tmp_ptr;
				x_factor = *tmp_ptr;
				diff = (sint32)(tmp_xval - x_factor);
			}
			while (diff < (sint16)0);
			/* realtive pointer index calculation*/
			rel_idx = (uint32)(((uint32)tmp_ptr - (uint32)dp_ptr) - 1U);
			*idxp = (uint8)rel_idx;
			if (diff == (sint16)0)
			{
				/* if input value is equal to one of the data point value return the value pointed by the updated relative pointer */
				temp1_u16 =  *(ptr_map + rel_idx);
			}
			else
			{
				/* if input value lies in between any 2 data point values in the array calculate line factor */
				temp1_u8 = *(tmp_ptr + 1U);
				x_factor = ((uint32)diff<<16U) / (uint32)(temp1_u8 -x_factor  );

				/* temporary pointer to point to a value in calibration map */
				ip_ptr = ptr_map + rel_idx;

				/* interpolate the value */
				diff = (sint32)(ip_ptr[1] - ip_ptr[0]);
				if (diff >= (sint16)0)
				{
					tmp_product = (uint32)diff * x_factor;
					temp1_u16 =  (uint16)(((*ip_ptr) + (tmp_product / 65536U) )+ (((tmp_product % 65536U) * 2U)/65536U));
				}
				else
				{
					tmp_product = (uint32)(-diff) * x_factor;
					temp1_u16 =  (uint16)(((*ip_ptr) - (tmp_product/65536U)) -(((tmp_product % 65536U) * 2U) /65536U));
				}
			}
		}
		/*~E*/
	}
	return temp1_u16;


	/* ## Operation body end [2316be31-832d-471f-b75c-67a3d89dfd80] */
}

/** This operation performs combined relative data point search and interpolation for 1D calibration curve of type uint16 and data point array of type uint16

@param ptr_map :Pointer to 1D calibration curve
@param dp_ptr :pointer to data point array
@param xval :Data point value to be searched
@param idxp :Pointer pointing to the location of array from which data point search has to be started
@return :Interpolated value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint16 function_u16_ip_rel_ptr_u16_idxp(const uint16 * ptr_map, const uint16 * dp_ptr, uint16 xval, uint8 * idxp)
{
	/* ## Operation body start [fd6e91bd-e166-4755-bdc6-ee8e82aeb1d3] */
	uint32   tmp_xval, rel_idx, tmp_product;   /* temporary variable to store intermediate results */
	uint32   x_factor;                         /* stores the line factor */
	const uint16 *tmp_ptr;
	const uint16 *ip_ptr;                      /* pointer to map array */
	sint32   diff;                             /* variable to store intermediate results */
	uint16 temp1_u16;

	/* assign input value to temporary variable */
	tmp_xval = xval;
	/* assign relative pointer to temporary variable */
	rel_idx = *idxp;

	/* compare relative pointer contents with the actual data elements in data point array*/
	if (rel_idx >= *dp_ptr)
	{
		/* point relative pointer to last element in data point array */
		rel_idx  =  *dp_ptr ;
		rel_idx-- ;
	}
	/* pointer to point to the the data point value pointed by relative pointer */
	tmp_ptr = dp_ptr + (rel_idx + 1U);

	/* compare input point value with data point array value pointed by relative pointer */
	if(tmp_xval >= *tmp_ptr)
	{
		/*~A*/
		/*~+:Search data point value in upper portion of the data point array*/
		/* compare input point value with highest data point array value */
		temp1_u16 = *(dp_ptr + (*dp_ptr));
		if (tmp_xval >= temp1_u16 )
		{
			/* set relative pointer to last value in data point  array */
			temp1_u16 = (*dp_ptr - 1U) ;
			*idxp = (uint8)temp1_u16;
			/* return the last value from the calibration map */
			temp1_u16 =  *(ptr_map +(*dp_ptr -1U));
		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to top*/

			do
			{
				++tmp_ptr;
				x_factor = *tmp_ptr;
			}
			while (x_factor <= tmp_xval);
			/* realtive pointer index calculation*/
			rel_idx = (uint32)((((uint32)tmp_ptr - (uint32)dp_ptr)/2U) - 2U);
			*idxp = (uint8)rel_idx;
			/* line factor calculation */
			temp1_u16 = *(tmp_ptr - 1U);
			x_factor = ((tmp_xval - temp1_u16)<<16U) / (uint32)(x_factor - temp1_u16);

			if (x_factor == 0U)
			{
				/* if input value is equal to one of the data point value return the value pointed by the updated relative pointer */
				temp1_u16 =  *( ptr_map + rel_idx);
			}
			else
			{

				/* temporary pointer to point to a value in calibration map */
				ip_ptr = ptr_map + rel_idx;

				/*interpolate the value */
				diff = (sint32)(ip_ptr[1] - ip_ptr[0]);
				if (diff >= (sint16)0)
				{
					tmp_product = (uint32)diff * x_factor;
					temp1_u16 =  (uint16)(((*ip_ptr) +( tmp_product/65536U ))+ (((tmp_product % 65536U) * 2U)/65536U));
				}
				else
				{
					tmp_product = (uint32)(-diff) * x_factor;
					temp1_u16 =  (uint16)(((*ip_ptr) - (tmp_product/65536U)) -(((tmp_product % 65536U) * 2U) /65536U));
				}
			}
		}
		/*~E*/
	}
	else
	{
		/*~A*/
		/*~+:Search data point value in lower portion of the data point array*/
		/* compare input point value with lowest data point array value */
		temp1_u16 = *(dp_ptr + 1U);
		if (tmp_xval <= temp1_u16 )
		{
			/* set relative pointer to first value in data point  array */
			*idxp = 0U;
			/* return the first value from the calibration map */
			temp1_u16 =  *(ptr_map);
		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to bottom */
			do
			{
				--tmp_ptr;
				x_factor = * tmp_ptr;
				diff = (sint32)(tmp_xval - x_factor);
			}
			while (diff < (sint16)0);
			/* realtive pointer index calculation*/
			rel_idx= (uint32)((((uint32)tmp_ptr - (uint32)dp_ptr)/2U) - 1U);
			*idxp = (uint8)rel_idx;
			if (diff == (sint16)0)
			{
				/* if input value is equal to one of the data point value return the value pointed by the updated relative pointer */
				temp1_u16 =  *(ptr_map + rel_idx);
			}
			else
			{
				/* if input value lies in between any 2 data point values in the array calculate line factor */
				temp1_u16 = *(tmp_ptr + 1U);
				x_factor = ((uint32)diff<<16U) / (uint32)(temp1_u16 - x_factor  );

				/* temporary pointer to point to a value in calibration map */
				ip_ptr = ptr_map + rel_idx;

				/* interpolate the value */
				diff = (sint32)(ip_ptr[1] - ip_ptr[0]);
				if (diff >= (sint16)0)
				{
					tmp_product = (uint32)diff * x_factor;
					temp1_u16 =  (uint16)(((*ip_ptr) +( tmp_product / 65536U ))+ (((tmp_product % 65536U) * 2U)/65536U));
				}
				else
				{
					tmp_product = (uint32)(-diff) * x_factor;
					temp1_u16 =  (uint16)(((*ip_ptr )- (tmp_product/65536U ))-(((tmp_product % 65536U) * 2U) /65536U));
				}
			}
		}
		/*~E*/
	}
	return temp1_u16;


	/* ## Operation body end [fd6e91bd-e166-4755-bdc6-ee8e82aeb1d3] */
}

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

uint8 func_u8_ip_rel_ptr_u8_idxp_u8(const uint8 * ptr_map, const uint8 * xdp_ptr, const uint8 * ydp_ptr, uint8 xval, uint8 yval, uint8 * idxp)
{
	/* ## Operation body start [07156c01-6275-4c89-96be-ce33eb501c04] */
	const uint8 *tmp_ptr;             /* temporary pointer to data point arrays and map */
	uint32   x_factor, y_factor;      /* variables to store line and column factors */
	uint32   index, num_col;          /* variable to store index and number of columns */
	sint32   tmp_product;             /* temporary variable to store intermediate results */
	sint32   tmp1, tmp2, diff;        /* variables to store intermediate results */
	uint8 temp1_u8;
	/* store x-relative index value in temporary variable */
	index  = *idxp;
	/* compare if relative index value exceeds no. of data values in data point array*/
	if (index >= *xdp_ptr)
	{
		/* set relative index value to index of last element of x-data point array */
		index = *xdp_ptr ;
		index--;
	}
	/* pointer to point to the the data point value pointed by relative pointer */
	tmp_ptr = xdp_ptr + (index + 1U);
	/* compare input point value with data point array value pointed by relative pointer */
	if (xval >= *tmp_ptr)
	{
		/*~A*/
		/*~+:Search data point value in upper portion of the data point array*/
		/* compare input point value with highest data point array value */
		temp1_u8 = *(xdp_ptr + (*xdp_ptr));
		if (xval >= temp1_u8 )
		{
			/* set index to last value in data point  array */
			temp1_u8 = (*xdp_ptr - 1U);
			index = (uint32)temp1_u8;
			/* set line factor to zero */
			x_factor = 0;
		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to top*/
			do
			{
				++tmp_ptr;
				x_factor = *tmp_ptr;
			}
			while ( x_factor <= (uint32)xval);
			/* line index value calculation*/
			index = (uint32)(((uint32)tmp_ptr - (uint32)xdp_ptr) - 2U);
			/* line factor calculation */
			temp1_u8 = *(tmp_ptr - 1U);
			x_factor = (uint32)(((uint32)xval - temp1_u8 ) * (uint32)65536) / (uint32)(x_factor - temp1_u8);
		}
		/*~E*/
	}
	else
	{
		/*~A*/
		/*~+:Search data point value in lower portion of the data point array*/
		/* compare input point value with lowest data point array value */
		if (xval <= *(xdp_ptr + 1))
		{
			/* set index to first value in data point  array */
			index = 0;
			/* set line factor to zero */
			x_factor = 0;
		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to bottom */
			do
			{
				--tmp_ptr;
				x_factor = *tmp_ptr;
			}
			while ( x_factor > xval);
			/* line index value calculation*/
			index = (uint32)(((uint32)tmp_ptr - (uint32)xdp_ptr) - 1U);
			/* line factor calculation */
			temp1_u8 = *(tmp_ptr + 1);
			x_factor = (uint32)(((uint32)xval - x_factor) * (uint32)65536) / (uint32)(temp1_u8 - x_factor);
		}

		/*~E*/
	}
	/*set relative pointer */
	*idxp = (uint8)index;
	/* pointer to point to last element of y-data point array */
	num_col = *ydp_ptr;
	tmp_ptr = ydp_ptr + num_col;
	index = (index * num_col);
	/*~A*/
	/*~+:Calculate the index value and column factor*/
	/* compare input point value with highest y-data point array */
	if (yval >= *tmp_ptr)
	{
		/*set column factor to zero */
		index = index + num_col - 1U;
		y_factor = 0;

	}
	else
	{
		/*compare input point value with lowest data point array
        value */
		if (yval <= *(ydp_ptr + 1))
		{
			/*set column factor to zero */
			y_factor = 0;

		}
		else
		{
			/* search input point value in the y-data point array from top to bottom */
			do
			{
				--tmp_ptr;
				y_factor = *tmp_ptr;
			}
			while (y_factor > (uint32)yval );
			/* index calculation*/
			index = index + (uint32)((uint32)tmp_ptr - (uint32)ydp_ptr) - 1U;
			/* column factor calculation */
			temp1_u8 = *(tmp_ptr + 1U);
			y_factor = (uint32)(((uint32)yval - y_factor) * (uint32)65536) / (uint32)(temp1_u8 - y_factor);
		}
	}

	/*~E*/
	/*temporary pointer to point to an element in interpolation data array */
	tmp_ptr = ptr_map + index;
	if (x_factor != 0U )
	{
		if (y_factor != 0U)
		{
			/*~A*/
			/*~+:If both line and column factors are non-zero then interpolate between both column and line*/
			/* if line factor and column factor both are non-zero, then calculate first column interpolation value */
			diff = (sint32)(tmp_ptr[1] - tmp_ptr[0] );
			tmp_product = (sint32)(diff * (sint32)y_factor);
			tmp1 = (((sint32)*tmp_ptr + (tmp_product/65536)) + (((tmp_product % 65536) * 2)/65536));
			/* point the pointer to the element in next row and same column */
			tmp_ptr += num_col;
			/* calculate second column interpolation value */
			diff = (sint32)(tmp_ptr[1] - tmp_ptr[0] );
			tmp_product = (sint32)(diff * (sint32)y_factor);
			tmp2 = (((sint32)*tmp_ptr + (tmp_product /65536)) + (((tmp_product% 65536) * 2)/65536));
			/* calculate line interpolation between the fisrt and second column interpolated values */
			diff = (tmp2 - tmp1);
			tmp_product = (sint32)(diff * (sint32)x_factor);
			tmp1 =  ((tmp1 + (tmp_product / 65536)) + (((tmp_product% 65536) * 2)/65536));

			/*~E*/
		}
		else
		{
			/*~A*/
			/*~+:If line factor is non-zero but col_factor is zero, then interpolate between lines*/
			/* if line factor is non-zero but col_factor is zero, then calculate only line interpolation */
			diff = (sint32)(tmp_ptr[num_col] - tmp_ptr[0] );
			tmp_product = (sint32)(diff * (sint32)x_factor);
			tmp1 =  (((sint32)*tmp_ptr + (tmp_product /65536)) +( ((tmp_product%65536) * 2)/65536));

			/*~E*/
		}
	}
	else
	{
		if (y_factor != 0U)
		{
			/*~A*/
			/*~+:If line factor is zero but column factor is non-zero then interpolate between columns*/
			/* if line factor is zero but column factor is non-zero, then calculate only column  interpolation */

			diff = (sint32)(tmp_ptr[1] - tmp_ptr[0] );
			tmp_product = (sint32)(diff * (sint32)y_factor);
			tmp1 = (((sint32)*tmp_ptr + (tmp_product /65536)) +( ((tmp_product%65536) * 2)/65536));

			/*~E*/
		}
		else
		{
			/*~A*/
			/*~+:If line factor and column factor are zero return the value pointed by the line index and column index*/
			/* if line factor and column factor are zero return the value pointed by the line index and column index */
			tmp1 =  (sint32)(*tmp_ptr);
			/*~E*/
		}
	}
	return (uint8)tmp1;

	/* ## Operation body end [07156c01-6275-4c89-96be-ce33eb501c04] */
}

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

uint8 func_u8_ip_rel_ptr_u8_u8_idyp(const uint8 * ptr_map, const uint8 * xdp_ptr, const uint8 * ydp_ptr, uint8 xval, uint8 yval, uint8 * idyp)
{
	/* ## Operation body start [f2c486b0-c98b-4568-90cb-12e75cc6dccd] */
	const uint8 *tmp_ptr;                    /* pointer to data point arrays and map */
	uint32      x_factor, y_factor;          /* variables to store line and column factors */
	uint32      x_index, index, num_col;     /* variable to store index and number of columns */
	sint32      tmp_product;                 /* temporary variable to store intermediate results */
	sint32      tmp1, tmp2, diff;            /* variables to store intermediate results */
	uint8 temp1_u8;
	/* pointer to point to last element of x-data point array */
	tmp_ptr = xdp_ptr + *xdp_ptr;

	/*~A*/
	/*~+:Calculate the index value and line factor*/
	/* compare input point value with highest x-data point array */
	if (xval >= *tmp_ptr)
	{
		x_index = *xdp_ptr ;
		x_index--;

		/* set line factor to zero */
		x_factor = 0U;

	}
	else
	{
		/*compare input point value with lowest data point array
        value */
		if (xval <= *(xdp_ptr + 1))
		{
			/*set line index and factor to zero */
			x_factor = 0U;
			x_index = 0U;

		}
		else
		{
			/* search input point value in the x-data point array from top to bottom */

			do
			{
				--tmp_ptr;
				x_factor = *tmp_ptr;
			}
			while (x_factor > (uint32)xval);
			/* line index calculation*/
			x_index = ((uint32)tmp_ptr - (uint32)xdp_ptr) - 1U;
			/* line factor calculation */
			temp1_u8 = *(tmp_ptr + 1U);
			x_factor = (uint32)(((uint32)xval - x_factor) * (uint32)65536) / (uint32)(temp1_u8 - x_factor);
		}
	}

	/*~E*/
	index = *idyp;

	/* compare if relative index value exceeds no. of data values in data point array*/
	num_col = *ydp_ptr;
	if (index >= num_col )
	{
		/* set relative index value to index of last element of y-data point array */
		index = num_col - 1U;
	}
	/* pointer to point to the the data point value pointed by relative pointer */
	tmp_ptr = ydp_ptr + (index + 1U);
	/* compare input point value with data point array value pointed by relative pointer */
	if (yval >= *tmp_ptr)
	{
		/*~A*/
		/*~+:Search data point value in upper portion of the data point array*/
		/* compare input point value with highest data point array value */
		if (yval >= *(ydp_ptr + num_col))
		{
			/* set index to last value in data point  array */
			index = (uint32)(num_col - 1U);
			/* set line factor to zero */
			y_factor = 0;
		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to top*/
			do
			{
				++tmp_ptr;
				y_factor = *tmp_ptr;
			}
			while ( y_factor  <= (uint32)yval );
			/* column index value calculation*/
			index = ((uint32)tmp_ptr - (uint32)ydp_ptr) - 2U;
			/* column factor calculation */
			temp1_u8 = *(tmp_ptr - 1U);
			y_factor = (((uint32)yval - temp1_u8 ) * (uint32)65536) / (uint32)(y_factor - temp1_u8);
		}
		/*~E*/
	}
	else
	{
		/*~A*/
		/*~+:Search data point value in lower portion of the data point array*/
		/* compare input point value with lowest data point array value */
		if (yval <= *(ydp_ptr + 1))
		{
			/* set index zero */
			index = 0;
			/* set line factor to zero */
			y_factor = 0;
		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to bottom */
			do
			{
				--tmp_ptr;
				y_factor = *tmp_ptr;
			}
			while (y_factor > (uint32)yval );
			/* column index value calculation*/
			index = (((uint32)tmp_ptr - (uint32)ydp_ptr) - 1U);
			/* column factor calculation */
			temp1_u8 = *(tmp_ptr + 1);
			y_factor = (((uint32)yval - y_factor) * (uint32)65536) / (uint32)(temp1_u8 - y_factor);
		}

		/*~E*/
	}
	/*set relative pointer */
	*idyp = (uint8)index;
	/* index calculation */
	x_index = x_index * num_col;
	index += x_index;
	/*temporary pointer to point to an element in interpolation data array */
	tmp_ptr = ptr_map + index;
	if (x_factor != 0U)
	{
		if (y_factor != 0U)
		{
			/*~A*/
			/*~+:If both line and column factors are non-zero then interpolate between both column and line*/
			/* if line factor and column factor both are non-zero, then calculate first column interpolation value */
			diff = (sint32)(tmp_ptr[1] - tmp_ptr[0] );
			tmp_product = (sint32)(diff * (sint32)y_factor);
			tmp1 = (((sint32)*tmp_ptr + (tmp_product/65536)) +( ((tmp_product % 65536) * 2)/65536));
			/* point the pointer to the element in next row and same column */
			tmp_ptr += num_col;
			/* calculate second column interpolation value */
			diff = (sint32)(tmp_ptr[1] - tmp_ptr[0] );
			tmp_product = (sint32)(diff * (sint32)y_factor);
			tmp2 = (((sint32)*tmp_ptr + (tmp_product /65536)) + (((tmp_product% 65536) * 2)/65536));
			/* calculate line interpolation between the fisrt and second column interpolated values */
			diff = (tmp2 - tmp1);
			tmp_product = (sint32)(diff * (sint32)x_factor);
			tmp1 = ( (tmp1 + (tmp_product / 65536)) + (((tmp_product% 65536) * 2)/65536));

			/*~E*/
		}
		else
		{
			/*~A*/
			/*~+:If line factor is non-zero but col_factor is zero, then interpolate between lines*/
			/* if line factor is non-zero but col_factor is zero, then calculate only line interpolation */
			diff = (sint32)(tmp_ptr[num_col] - tmp_ptr[0] );
			tmp_product = (sint32)(diff * (sint32)x_factor);
			tmp1 =  (((sint32)*tmp_ptr + (tmp_product /65536)) + (((tmp_product%65536) * 2)/65536));

			/*~E*/
		}
	}
	else
	{
		if (y_factor != 0U )
		{
			/*~A*/
			/*~+:If line factor is zero but column factor is non-zero then interpolate between columns*/
			/* if line factor is zero but column factor is non-zero, then calculate only column  interpolation */
			diff = (sint32)(tmp_ptr[1] - tmp_ptr[0] );
			tmp_product = (sint32)(diff * (sint32)y_factor);
			tmp1 = (((sint32)*tmp_ptr + (tmp_product /65536)) + (((tmp_product%65536) * 2)/65536));

			/*~E*/
		}
		else
		{
			/*~A*/
			/*~+:If line factor and column factor are zero return the value pointed by the line index and column index*/
			/* if line factor and column factor are zero return the value pointed by the line index and column index */
			tmp1 =  (sint32)(*tmp_ptr);
			/*~E*/
		}
	}
	return (uint8)tmp1;

	/* ## Operation body end [f2c486b0-c98b-4568-90cb-12e75cc6dccd] */
}

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

uint8 func_u8_ip_rel_ptr_u16_idxp_u8(const uint8 * ptr_map, const uint16 * xdp_ptr, const uint8 * ydp_ptr, uint16 xval, uint8 yval, uint8 * idxp)
{
	/* ## Operation body start [afbf4d27-23c1-4e74-a4fb-0b7d389043fc] */
	const uint16 *xtmp_ptr;              /* pointer to x-data point array */
	const uint8  *tmp_ptr;               /* pointer to y-data point array and map*/
	uint32       x_factor, y_factor;     /* variables to store line and column factors and intermediate values */
	uint32       index, num_col;         /* variable to store index and number of columns */
	sint32       tmp_product;            /* temporary variable to store intermediate results */
	sint32       tmp1, tmp2, diff;       /* variables to store intermediate results */
	uint8 temp1_u8;
	uint16 temp1_u16;
	/* assign x-relative index value to temporary variable */
	index  = *idxp;

	/* compare if relative index value exceeds no. of data values in data point array*/
	if (index >= *xdp_ptr)
	{
		/* set relative index value to index of last element of x-data point array */
		index = *xdp_ptr ;
		index--;

	}
	/* pointer to point to the the data point value pointed by relative pointer */
	xtmp_ptr = xdp_ptr + (index + 1U);

	/* compare input point value with data point array value pointed by relative pointer */
	if (xval >= *xtmp_ptr)
	{
		/*~A*/
		/*~+:Search data point value in upper portion of the data point array*/
		/* compare input point value with highest data point array value */
		if (xval >= *(xdp_ptr + (*xdp_ptr)))
		{
			/* set index to last value in data point  array */
			temp1_u16 = (*xdp_ptr - 1U);
			index = (uint32)temp1_u16;

			/* set line factor to zero */
			x_factor = 0;
		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to top*/
			do
			{
				++xtmp_ptr;
				x_factor = *xtmp_ptr;
			}
			while ( x_factor <= (uint32)xval );
			/* line index value calculation*/
			index = (((uint32)xtmp_ptr - (uint32)xdp_ptr)/2U) - 2U;

			/* line factor calculation */
			temp1_u16 = *(xtmp_ptr - 1);
			x_factor = (((uint32)xval - temp1_u16) * (uint32)65536) / (uint32)(x_factor - temp1_u16);

		}
		/*~E*/
	}
	else
	{
		/*~A*/
		/*~+:Search data point value in lower portion of the data point array*/
		/* compare input point value with lowest data point array value */
		if (xval <= *(xdp_ptr + 1))
		{
			/* set index to first value in data point  array */
			index = 0;

			/* set line factor to zero */
			x_factor = 0;

		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to bottom */
			do
			{
				--xtmp_ptr;
				x_factor = *xtmp_ptr;
			}
			while ( x_factor > (uint32)xval);
			/* line index value calculation*/
			index = (((uint32)xtmp_ptr - (uint32)xdp_ptr)/2U) - 1U;

			/* line factor calculation */
			temp1_u16 = *(xtmp_ptr + 1) ;
			x_factor = (((uint32)xval - x_factor) * (uint32)65536) / (uint32)(temp1_u16 - x_factor);

		}
		/*~E*/
	}
	/*set relative pointer */
	*idxp = (uint8)index;
	/* pointer to point to last element of y-data point array */
	num_col = *ydp_ptr;
	tmp_ptr = ydp_ptr + num_col;
	index = (index * num_col);
	/*~A*/
	/*~+:Calculate the index value and column factor*/
	/* compare input point value with highest y-data point array */
	if (yval >= *tmp_ptr)
	{
		/*set column factor to zero */
		index = index + num_col - 1U;
		y_factor = 0;

	}
	else
	{
		/*compare input point value with lowest data point array
        value */
		if (yval <= *(ydp_ptr + 1))
		{
			/*set column factor to zero */
			y_factor = 0;

		}
		else
		{
			/* search input point value in the y-data point array from top to bottom */
			do
			{
				--tmp_ptr;
				y_factor = *tmp_ptr;
			}
			while (y_factor > (uint32)yval);
			/* index calculation*/
			index = index + (uint32)((uint32)tmp_ptr - (uint32)ydp_ptr) - 1U;
			/* column factor calculation */
			temp1_u8 = *(tmp_ptr + 1U);
			y_factor = (((uint32)yval - y_factor) * (uint32)65536) / (uint32)(temp1_u8 - y_factor);
		}
	}
	/*~E*/
	/*temporary pointer to point to an element in interpolation data array */
	tmp_ptr = ptr_map + index;
	if (x_factor != 0U )
	{
		if (y_factor != 0U )
		{
			/*~A*/
			/*~+:If both line and column factors are non-zero then interpolate between both column and line*/
			/* if line factor and column factor both are non-zero, then calculate first column interpolation value */
			diff = (sint32)(tmp_ptr[1] - tmp_ptr[0] );
			tmp_product = (sint32)(diff * (sint32)y_factor);
			tmp1 = (((sint32)*tmp_ptr + (tmp_product/65536)) +( ((tmp_product %65536) * 2)/65536));
			/* point the pointer to the element in next row and same column */
			tmp_ptr += num_col;
			/* calculate second column interpolation value */
			diff = (sint32)(tmp_ptr[1] - tmp_ptr[0] );
			tmp_product = (sint32)(diff * (sint32)y_factor);
			tmp2 = (((sint32)*tmp_ptr + (tmp_product /65536)) +( ((tmp_product% 65536) * 2)/65536));
			/* calculate line interpolation between the fisrt and second column interpolated values */
			diff = (tmp2 - tmp1);
			tmp_product = (sint32)(diff * (sint32)x_factor);
			tmp1 =  ((tmp1 + (tmp_product / 65536)) + (((tmp_product% 65536) * 2)/65536));

			/*~E*/
		}
		else
		{
			/*~A*/
			/*~+:If line factor is non-zero but col_factor is zero, then interpolate between lines*/
			/* if line factor is non-zero but col_factor is zero, then calculate only line interpolation */
			diff = (sint32)(tmp_ptr[num_col] - tmp_ptr[0] );

			tmp_product = (sint32)(diff * (sint32)x_factor);
			tmp1 =  (((sint32)*tmp_ptr + (tmp_product /65536)) + (((tmp_product%65536) * 2)/65536));


			/*~E*/
		}
	}
	else
	{
		if (y_factor != 0U )
		{
			/*~A*/
			/*~+:If line factor is zero but column factor is non-zero then interpolate between columns*/
			/* if line factor is zero but column factor is non-zero, then calculate only column  interpolation */
			diff = (sint32)(tmp_ptr[1] - tmp_ptr[0] );

			tmp_product = (sint32)(diff * (sint32)y_factor);
			tmp1 = (((sint32)*tmp_ptr + ( tmp_product /65536 )) + (((tmp_product%65536) * 2)/65536));


			/*~E*/
		}
		else
		{
			/*~A*/
			/*~+:If line factor and column factor are zero return the value pointed by the line index and column index*/
			/* if line factor and column factor are zero return the value pointed by the line index and column index */
			tmp1 =  (sint32)(*tmp_ptr);

			/*~E*/
		}
	}
	return (uint8)tmp1;

	/* ## Operation body end [afbf4d27-23c1-4e74-a4fb-0b7d389043fc] */
}

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

uint8 func_u8_ip_rel_ptr_u16_u8_idyp(const uint8 * ptr_map, const uint16 * xdp_ptr, const uint8 * ydp_ptr, uint16 xval, uint8 yval, uint8 * idyp)
{
	/* ## Operation body start [441155e6-aa73-4bc8-a2aa-022efeb43f6c] */
	const uint16 *xtmp_ptr;                  /* pointer to x-data point array */
	const uint8  *tmp_ptr;                   /* pointer to y-data point array and map */
	uint32       x_factor, y_factor;         /* variables to store line and column factors and intermediate values */
	uint32       x_index, index, num_col;    /* variable to store index and number of columns */
	sint32       tmp_product;                /* temporary variable to store intermediate results */
	sint32       tmp1, tmp2, diff;           /* variables to store intermediate results */
	uint8 temp1_u8;
	uint16 temp1_u16;

	/* pointer to point to last element of x-data point array */
	xtmp_ptr = xdp_ptr + *xdp_ptr;

	/*~A*/
	/*~+:Calculate the index value and line factor*/
	/* compare input point value with highest x-data point array */
	if (xval >= *xtmp_ptr)
	{
		x_index = *xdp_ptr ;
		x_index--;

		/*set line factor to zero */
		x_factor = 0;

	}
	else
	{
		/*compare input point value with lowest data point array
        value */
		if (xval <= *(xdp_ptr + 1U))
		{
			/*set line factor to zero */
			x_factor = 0;
			x_index = 0;

		}
		else
		{
			/* search input point value in the x-data point array from top to bottom */
			do
			{
				--xtmp_ptr;
				x_factor = (uint32)*xtmp_ptr;
			}
			while (x_factor > (uint32)xval);
			/* line index calculation*/
			x_index = (((uint32)xtmp_ptr - (uint32)xdp_ptr)/2U) - 1U;
			/* line factor calculation */
			temp1_u16 = *(xtmp_ptr + 1U);
			x_factor = (((uint32)xval - x_factor) * (uint32)65536) / (uint32)(temp1_u16 - x_factor);
		}
	}

	/*~E*/
	index = *idyp;

	/* compare if relative index value exceeds no. of data values in data point array*/
	num_col = *ydp_ptr;
	if (index >= num_col)
	{
		/* set relative index value to index of last element of y-data point array */
		index = num_col - 1U;
	}
	/* pointer to point to the the data point value pointed by relative pointer */
	tmp_ptr = ydp_ptr + (index + 1U);
	/* compare input point value with data point array value pointed by relative pointer */
	if (yval >= *tmp_ptr)
	{
		/*~A*/
		/*~+:Search data point value in upper portion of the data point array*/
		/* compare input point value with highest data point array value */
		if (yval >= *(ydp_ptr + num_col))
		{
			/* set index to last value in data point  array */
			index = (uint32)(num_col - 1U);
			/* set line factor to zero */
			y_factor = 0;
		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to top*/
			do
			{
				++tmp_ptr;
				y_factor = *tmp_ptr;
			}
			while (y_factor <= (uint32)yval );
			/* column index value calculation*/
			index = ((uint32)tmp_ptr - (uint32)ydp_ptr) - 2U;
			/* column factor calculation */
			temp1_u8 = *(tmp_ptr - 1U);
			y_factor = (((uint32)yval - temp1_u8 ) * (uint32)65536) / (uint32)(y_factor - temp1_u8);
		}
		/*~E*/
	}
	else
	{
		/*~A*/
		/*~+:Search data point value in lower portion of the data point array*/
		/* compare input point value with lowest data point array value */
		if (yval <= *(ydp_ptr + 1U))
		{
			/* set index to first value in data point  array */
			index = 0;
			/* set line factor to zero */
			y_factor = 0;
		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to bottom */
			do
			{
				--tmp_ptr;
				y_factor = *tmp_ptr;
			}
			while (y_factor > (uint32)yval);
			/* column index value calculation*/
			index = ((uint32)tmp_ptr - (uint32)ydp_ptr) - 1U;
			/* column factor calculation */
			temp1_u8 = *(tmp_ptr + 1U);
			y_factor = (((uint32)yval - y_factor) * (uint32)65536) / (uint32)(temp1_u8 - y_factor);
		}

		/*~E*/
	}
	/*set relative pointer */
	*idyp = (uint8)index;
	x_index = x_index * num_col;
	index += x_index;
	/*temporary pointer to point to an element in interpolation data array */
	tmp_ptr = ptr_map + index;
	if (x_factor != 0U)
	{
		if (y_factor != 0U)
		{
			/*~A*/
			/*~+:If both line and column factors are non-zero then interpolate between both column and line*/
			/* if line factor and column factor both are non-zero, then calculate first column interpolation value */
			diff = (sint32)(tmp_ptr[1] - tmp_ptr[0] );
			tmp_product = (sint32)(diff * (sint32)y_factor);
			tmp1 = (((sint32)*tmp_ptr + ( tmp_product/(sint32)65536 ) ) + (((tmp_product % (sint32)65536) * 2)/(sint32)65536));
			/* point the pointer to the element in next row and same column */
			tmp_ptr += num_col;
			/* calculate second column interpolation value */
			diff = (sint32)(tmp_ptr[1] - tmp_ptr[0] );
			tmp_product = (sint32)(diff * (sint32)y_factor);
			tmp2 = (((sint32)*tmp_ptr + (tmp_product /(sint32)65536)) + (((tmp_product% (sint32)65536) * 2)/(sint32)65536));
			/* calculate line interpolation between the fisrt and second column interpolated values */
			diff = (tmp2 - tmp1);
			tmp_product = (sint32)(diff * (sint32)x_factor);
			tmp1 =  ((tmp1 + (tmp_product / (sint32)65536)) + (((tmp_product% (sint32)65536) * 2)/(sint32)65536));

			/*~E*/
		}
		else
		{
			/*~A*/
			/*~+:If line factor is non-zero but col_factor is zero, then interpolate between lines*/
			/* if line factor is non-zero but col_factor is zero, then calculate only line interpolation */
			diff = (sint32)(tmp_ptr[num_col] - tmp_ptr[0] );

			tmp_product = (sint32)(diff * (sint32)x_factor);
			tmp1 =  (((sint32)*tmp_ptr + (tmp_product /(sint32)65536)) + (((tmp_product%(sint32)65536) * 2)/(sint32)65536));


			/*~E*/
		}
	}
	else
	{
		if (y_factor != 0U)
		{
			/*~A*/
			/*~+:If line factor is zero but column factor is non-zero then interpolate between columns*/
			/* if line factor is zero but column factor is non-zero, then calculate only column  interpolation */
			diff = (sint32)(tmp_ptr[1] - tmp_ptr[0] );

			tmp_product = (sint32)(diff * (sint32)y_factor);
			tmp1 = (((sint32)*tmp_ptr + ( tmp_product /(sint32)65536)) + (((tmp_product%(sint32)65536) * 2)/(sint32)65536));


			/*~E*/
		}
		else
		{
			/*~A*/
			/*~+:If line factor and column factor are zero return the value pointed by the line index and column index*/
			/* if line factor and column factor are zero return the value pointed by the line index and column index */
			tmp1 =  (sint32)(*tmp_ptr);

			/*~E*/
		}
	}
	return (uint8)tmp1;

	/* ## Operation body end [441155e6-aa73-4bc8-a2aa-022efeb43f6c] */
}

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

uint8 func_u8_ip_rel_ptr_u8_idxp_u16(const uint8 * ptr_map, const uint8 * xdp_ptr, const uint16 * ydp_ptr, uint8 xval, uint16 yval, uint8 * idxp)
{
	/* ## Operation body start [29371c49-7750-4f38-8a9c-465951f5e00e] */
	const uint8  *tmp_ptr;              /* pointer to x-data point array and map */
	const uint16 *ytmp_ptr;             /* pointer to y-data point array */
	uint32       x_factor, y_factor;    /* variables to store line and column factors */
	uint32       index, num_col;        /* variable to store index and number of columns */
	sint32       tmp_product;           /* temporary variable to store intermediate results */
	sint32       tmp1, tmp2, diff;      /* variables to store intermediate results */
	uint8 temp1_u8;
	uint16 temp1_u16;
	/* assign x-relative index value to temporary variable */
	index  = *idxp;
	/* compare if relative index value exceeds no. of data values in data point array*/
	if (index >= *xdp_ptr)
	{
		/* set relative index value to index of last element of x-data point array */
		index = *xdp_ptr ;
		index--;
	}
	/* pointer to point to the the data point value pointed by relative pointer */
	tmp_ptr = xdp_ptr + (index + 1U);
	/* compare input point value with data point array value pointed by relative pointer */
	if (xval >= *tmp_ptr)
	{
		/*~A*/
		/*~+:Search data point value in upper portion of the data point array*/
		/* compare input point value with highest data point array value */
		if (xval >= *(xdp_ptr + (*xdp_ptr)))
		{
			/* set index to last value in data point  array */
			temp1_u8 = (*xdp_ptr - 1U);
			index = (uint32)temp1_u8;
			/* set line factor to zero */
			x_factor = 0;
		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to top*/
			do
			{
				++tmp_ptr;
				x_factor = *tmp_ptr;
			}
			while (x_factor <= (uint32)xval);
			/* line index value calculation*/
			index = ((uint32)tmp_ptr - (uint32)xdp_ptr) - 2U;
			/* line factor calculation */
			temp1_u8 = *(tmp_ptr - 1U);
			x_factor = (((uint32)xval -temp1_u8 ) * (uint32)65536) / (uint32)(x_factor - temp1_u8);
		}
		/*~E*/
	}
	else
	{
		/*~A*/
		/*~+:Search data point value in lower portion of the data point array*/
		/* compare input point value with lowest data point array value */
		if (xval <= *(xdp_ptr + 1U))
		{
			/* set index to first value in data point  array */
			index = 0;

			/* set line factor to zero */
			x_factor = 0;

		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to bottom */
			do
			{
				--tmp_ptr;
				x_factor = *tmp_ptr;
			}
			while ( x_factor > (uint32)xval);
			/* line index value calculation*/
			index = ((uint32)tmp_ptr - (uint32)xdp_ptr) - 1U;

			/* line factor calculation */
			temp1_u8 = *(tmp_ptr + 1U);
			x_factor = (((uint32)xval - x_factor) * (uint32)65536) / (uint32)(temp1_u8 - x_factor);

		}
		/*~E*/
	}
	/*set relative pointer */
	*idxp = (uint8)index;
	/* pointer to point to last element of y-data point array */
	num_col = *ydp_ptr;
	ytmp_ptr = ydp_ptr + num_col;
	index = (index * num_col);
	/*~A*/
	/*~+:Calculate the index value and column factor*/
	/* compare input point value with highest y-data point array */
	if (yval >= *ytmp_ptr)
	{
		/*set column factor to zero */
		index = index + num_col - 1U;
		y_factor = 0;

	}
	else
	{
		/*compare input point value with lowest data point array
        value */
		if (yval <= *(ydp_ptr + 1U))
		{
			/*set column factor to zero */
			y_factor = 0;

		}
		else
		{
			/* search input point value in the y-data point array from top to bottom */
			do
			{
				--ytmp_ptr;
				y_factor = *ytmp_ptr;
			}
			while (y_factor > (uint32)yval );
			/* index calculation*/
			index = index + (uint32)((((uint32)ytmp_ptr - (uint32)ydp_ptr)/2U) - 1U);
			/* column factor calculation */
			temp1_u16 = *(ytmp_ptr + 1U);
			y_factor = (((uint32)yval - y_factor) * (uint32)65536) / (uint32)( temp1_u16 - y_factor);
		}
	}
	/*~E*/
	/*temporary pointer to point to an element in interpolation data array */
	tmp_ptr = ptr_map + index;
	if (x_factor != 0U)
	{
		if (y_factor != 0U)
		{
			/*~A*/
			/*~+:If both line and column factors are non-zero then interpolate between both column and line*/
			/* if line factor and column factor both are non-zero, then calculate first column interpolation value */
			diff = (sint32)(tmp_ptr[1] - tmp_ptr[0] );
			tmp_product = (sint32)(diff * (sint32)y_factor);
			tmp1 = (((sint32)*tmp_ptr + (tmp_product/(sint32)65536)) + (((tmp_product % (sint32)65536) * 2)/(sint32)65536));
			/* point the pointer to the element in next row and same column */
			tmp_ptr += num_col;
			/* calculate second column interpolation value */
			diff = (sint32)(tmp_ptr[1] - tmp_ptr[0] );
			tmp_product = (sint32)(diff * (sint32)y_factor);
			tmp2 = (sint32)(((sint32)*tmp_ptr + (tmp_product /(sint32)65536)) + (((tmp_product% (sint32)65536) * 2)/(sint32)65536));
			/* calculate line interpolation between the fisrt and second column interpolated values */
			diff = (tmp2 - tmp1);
			tmp_product = (sint32)(diff * (sint32)x_factor);
			tmp1 =  ((tmp1 + (tmp_product / (sint32)65536)) + (((tmp_product% (sint32)65536) * 2)/(sint32)65536));

			/*~E*/
		}
		else
		{
			/*~A*/
			/*~+:If line factor is non-zero but col_factor is zero, then interpolate between lines*/
			/* if line factor is non-zero but col_factor is zero, then calculate only line interpolation */
			diff = (sint32)(tmp_ptr[num_col] - tmp_ptr[0] );
			tmp_product = (sint32)(diff * (sint32)x_factor);
			tmp1 =  (((sint32)*tmp_ptr + ( tmp_product /(sint32)65536 )) + (((tmp_product%(sint32)65536) * 2)/(sint32)65536));

			/*~E*/
		}
	}
	else
	{
		if (y_factor != 0U)
		{
			/*~A*/
			/*~+:If line factor is zero but column factor is non-zero then interpolate between columns*/
			/* if line factor is zero but column factor is non-zero, then calculate only column  interpolation */
			diff = (sint32)(tmp_ptr[1] - tmp_ptr[0] );
			tmp_product = (sint32)(diff * (sint32)y_factor);
			tmp1 = (((sint32)*tmp_ptr + (tmp_product /(sint32)65536)) + (((tmp_product%(sint32)65536) * 2)/(sint32)65536));

			/*~E*/
		}
		else
		{
			/*~A*/
			/*~+:If line factor and column factor are zero return the value pointed by the line index and column index*/
			/* if line factor and column factor are zero return the value pointed by the line index and column index */
			tmp1 =  (sint32)(*tmp_ptr);
			/*~E*/
		}
	}
	return (uint8)tmp1;

	/* ## Operation body end [29371c49-7750-4f38-8a9c-465951f5e00e] */
}

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

uint8 func_u8_ip_rel_ptr_u8_u16_idyp(const uint8 * ptr_map, const uint8 * xdp_ptr, const uint16 * ydp_ptr, uint8 xval, uint16 yval, uint8 * idyp)
{
	/* ## Operation body start [80b0241f-bc08-4af4-9dd2-4d6b78e86c86] */
	const uint8 *tmp_ptr;                /* pointer to x-data point array and map */
	const uint16 *ytmp_ptr;              /* pointer to y-data point array */
	uint32   x_factor, y_factor;         /* variables to store line and column factors */
	uint32   x_index, index, num_col;    /* variable to store index and number of columns */
	sint32   tmp_product;                /* temporary variable to store intermediate results */
	sint32   tmp1, tmp2, diff;           /* variables to store intermediate results */
	uint8 temp1_u8;
	uint16 temp1_u16;
	/* pointer to point to last element of x-data point array */
	tmp_ptr = xdp_ptr + *xdp_ptr;

	/*~A*/
	/*~+:Calculate the index value and line factor*/
	/* compare input point value with highest x-data point array */
	if (xval >= *tmp_ptr)
	{
		x_index = *xdp_ptr ;
		x_index--;

		/*set line factor to zero */
		x_factor = 0;

	}
	else
	{
		/*compare input point value with lowest data point array
        value */
		if (xval <= *(xdp_ptr + 1U))
		{
			/*set line factor to zero */
			x_factor = 0;
			x_index = 0;

		}
		else
		{
			/* search input point value in the x-data point array from top to bottom */
			do
			{
				--tmp_ptr;
				x_factor = *tmp_ptr;
			}
			while (x_factor > (uint32)xval);
			/* line index calculation*/
			x_index = ((uint32)tmp_ptr - (uint32)xdp_ptr) - 1U;
			/* line factor calculation */
			temp1_u8 = *(tmp_ptr + 1U);
			x_factor = (((uint32)xval - x_factor) * (uint32)65536) / (uint32)( temp1_u8 - x_factor);
		}
	}

	/*~E*/
	index = *idyp;

	/* compare if relative index value exceeds no. of data values in data point array*/
	num_col = *ydp_ptr;
	if (index >= num_col)
	{
		/* set relative index value to index of last element of y-data point array */
		index = num_col - 1U;
	}
	/* pointer to point to the the data point value pointed by relative pointer */
	ytmp_ptr = ydp_ptr + (index + 1U);
	/* compare input point value with data point array value pointed by relative pointer */
	if (yval >= *ytmp_ptr)
	{
		/*~A*/
		/*~+:Search data point value in upper portion of the data point array*/
		/* compare input point value with highest data point array value */
		if (yval >= *(ydp_ptr + num_col))
		{
			/* set index to last value in data point  array */
			index = (uint32)(num_col - 1U);
			/* set line factor to zero */
			y_factor = 0;
		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to top*/
			do
			{
				++ytmp_ptr;
				y_factor = *ytmp_ptr;
			}
			while (y_factor<= (uint32)yval);
			/* column index value calculation*/
			index = (((uint32)ytmp_ptr - (uint32)ydp_ptr)/2U) - 2U;
			/* column factor calculation */
			temp1_u16 = *(ytmp_ptr - 1U);
			y_factor = (((uint32)yval - temp1_u16) * (uint32)65536) / (uint32)(y_factor - temp1_u16);
		}
		/*~E*/
	}
	else
	{
		/*~A*/
		/*~+:Search data point value in lower portion of the data point array*/
		/* compare input point value with lowest data point array value */
		if (yval <= *(ydp_ptr + 1U))
		{
			/* set index to first value in data point  array */
			index = 0;
			/* set line factor to zero */
			y_factor = 0;
		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to bottom */
			do
			{
				--ytmp_ptr;
				y_factor = *ytmp_ptr;
			}
			while ( y_factor > (uint32)yval );
			/* column index value calculation*/
			index = (((uint32)ytmp_ptr - (uint32)ydp_ptr)/2U) - 1U;
			/* column factor calculation */
			temp1_u16 = *(ytmp_ptr + 1U);
			y_factor = (((uint32)yval - y_factor) * (uint32)65536) / (uint32)( temp1_u16 - y_factor);
		}

		/*~E*/
	}
	/*set relative pointer */
	*idyp = (uint8)index;
	x_index = x_index * num_col;
	index += x_index;
	/*temporary pointer to point to an element in interpolation data array */
	tmp_ptr = ptr_map + index;
	if (x_factor != 0U)
	{
		if (y_factor != 0U)
		{
			/*~A*/
			/*~+:If both line and column factors are non-zero then interpolate between both column and line*/
			/* if line factor and column factor both are non-zero, then calculate first column interpolation value */
			diff = (sint32)(tmp_ptr[1] - tmp_ptr[0] );
			tmp_product = (sint32)(diff * (sint32)y_factor);
			tmp1 = (sint32)(((sint32)*tmp_ptr + (tmp_product/(sint32)65536 ))+ (((tmp_product % (sint32)65536) * 2)/(sint32)65536));
			/* point the pointer to the element in next row and same column */
			tmp_ptr += num_col;
			/* calculate second column interpolation value */
			diff = (sint32)(tmp_ptr[1] - tmp_ptr[0] );
			tmp_product = (sint32)(diff * (sint32)y_factor);
			tmp2 = (sint32)(((sint32)*tmp_ptr + (tmp_product /(sint32)65536)) +( ((tmp_product% (sint32)65536) * 2)/(sint32)65536));
			/* calculate line interpolation between the fisrt and second column interpolated values */
			diff = (tmp2 - tmp1);
			tmp_product = (sint32)(diff * (sint32)x_factor);
			tmp1 =  ((tmp1 + (tmp_product / (sint32)65536)) + (((tmp_product% (sint32)65536) * 2)/(sint32)65536));

			/*~E*/
		}
		else
		{
			/*~A*/
			/*~+:If line factor is non-zero but col_factor is zero, then interpolate between lines*/
			/* if line factor is non-zero but col_factor is zero, then calculate only line interpolation */
			diff = (sint32)(tmp_ptr[num_col] - tmp_ptr[0] );
			tmp_product = (sint32)(diff * (sint32)x_factor);
			tmp1 =  (((sint32)*tmp_ptr + (tmp_product /(sint32)65536)) + (((tmp_product%(sint32)65536) * 2)/(sint32)65536));

			/*~E*/
		}
	}
	else
	{
		if (y_factor != 0U)
		{
			/*~A*/
			/*~+:If line factor is zero but column factor is non-zero then interpolate between columns*/
			/* if line factor is zero but column factor is non-zero, then calculate only column  interpolation */
			diff = (sint32)(tmp_ptr[1] - tmp_ptr[0] );
			tmp_product = (sint32)(diff * (sint32)y_factor);
			tmp1 = (((sint32)*tmp_ptr + (tmp_product /(sint32)65536)) + (((tmp_product%(sint32)65536) * 2)/(sint32)65536));

			/*~E*/
		}
		else
		{
			/*~A*/
			/*~+:If line factor and column factor are zero return the value pointed by the line index and column index*/
			/* if line factor and column factor are zero return the value pointed by the line index and column index */
			tmp1 =  (sint32)(*tmp_ptr);
			/*~E*/
		}
	}
	return (uint8)tmp1;


	/* ## Operation body end [80b0241f-bc08-4af4-9dd2-4d6b78e86c86] */
}

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

uint8 func_u8_ip_rel_ptr_u16_idxp_u16(const uint8 * ptr_map, const uint16 * xdp_ptr, const uint16 * ydp_ptr, uint16 xval, uint16 yval, uint8 * idxp)
{
	/* ## Operation body start [375a26ec-412f-467a-9fbe-8f27b9db46b9] */
	const uint16 *tmp_ptr;              /* pointer to data point arrays */
	const uint8  *ip_ptr;               /* pointer to map array */
	uint32       x_factor, y_factor;    /* variables to store line and column factors */
	uint32       index, num_col;        /* variable to store index and number of columns */
	sint32       tmp_product;           /* temporary variable to store intermediate results */
	sint32       tmp1, tmp2, diff;      /* variables to store intermediate results */
	uint16 temp1_u16;

	/* assign x-relative index value to temporary variable */
	index  = *idxp;
	/* compare if relative index value exceeds no. of data values in data point array*/
	if (index >= *xdp_ptr)
	{
		/* set relative index value to index of last element of x-data point array */
		index = *xdp_ptr ;
		index--;
	}
	/* pointer to point to the the data point value pointed by relative pointer */
	tmp_ptr = xdp_ptr + (index + 1U);
	/* compare input point value with data point array value pointed by relative pointer */
	if (xval >= *tmp_ptr)
	{
		/*~A*/
		/*~+:Search data point value in upper portion of the data point array*/
		/* compare input point value with highest data point array value */
		if (xval >= *(xdp_ptr + (*xdp_ptr)))
		{
			/* set index to last value in data point  array */
			temp1_u16 = (*xdp_ptr - 1U);
			index = (uint32)temp1_u16;
			/* set line factor to zero */
			x_factor = 0;
		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to top*/
			do
			{
				++tmp_ptr;
				x_factor = *tmp_ptr;
			}
			while (x_factor <= (uint32)xval);
			/* line index value calculation*/
			index = (((uint32)tmp_ptr - (uint32)xdp_ptr)/2U) - 2U;
			/* line factor calculation */
			temp1_u16 = *(tmp_ptr - 1U);
			x_factor = (((uint32)xval -temp1_u16) * (uint32)65536) / (uint32)(x_factor - temp1_u16);
		}

		/*~E*/
	}
	else
	{
		/*~A*/
		/*~+:Search data point value in lower portion of the data point array*/
		/* compare input point value with lowest data point array value */
		if (xval <= *(xdp_ptr + 1U))
		{
			/* set index to first value in data point  array */
			index = 0;
			/* set line factor to zero */
			x_factor = 0;
		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to bottom */
			do
			{
				--tmp_ptr;
				x_factor = *tmp_ptr;
			}
			while ( x_factor > (uint32)xval );
			/* line index value calculation*/
			index = (((uint32)tmp_ptr - (uint32)xdp_ptr)/2U) - 1U;
			/* line factor calculation */
			temp1_u16 = *(tmp_ptr + 1U);
			x_factor = (((uint32)xval - x_factor) * (uint32)65536) / (uint32)(temp1_u16 - x_factor);
		}

		/*~E*/
	}
	/*set relative pointer */
	*idxp = (uint8)index;
	/* pointer to point to last element of y-data point array */
	num_col = *ydp_ptr;
	tmp_ptr = ydp_ptr + num_col;
	index = (index * num_col);
	/*~A*/
	/*~+:Calculate the index value and column factor*/
	/* compare input point value with highest y-data point array */
	if (yval >= *tmp_ptr)
	{
		/*set column factor to zero */
		index = index + num_col - 1U;
		y_factor = 0;

	}
	else
	{
		/*compare input point value with lowest data point array
        value */
		if (yval <= *(ydp_ptr + 1U))
		{
			/*set column factor to zero */
			y_factor = 0;

		}
		else
		{
			/* search input point value in the y-data point array from top to bottom */
			do
			{
				--tmp_ptr;
				y_factor = *tmp_ptr;
			}
			while ( y_factor > (uint32)yval );
			/* index calculation*/
			index = (index + (uint32)(((uint32)tmp_ptr - (uint32)ydp_ptr)/2U)) - 1U;
			/* column factor calculation */
			temp1_u16 = *(tmp_ptr + 1U);
			y_factor = (uint32)(((uint32)yval - y_factor) * (uint32)65536) / (uint32)(temp1_u16 - y_factor);
		}
	}

	/*~E*/
	/*temporary pointer to point to an element in interpolation data array */
	ip_ptr = ptr_map + index;
	if (x_factor != 0U)
	{
		if (y_factor != 0U)
		{
			/*~A*/
			/*~+:If both line and column factors are non-zero then interpolate between both column and line*/
			/* if line factor and column factor both are non-zero, then calculate first column interpolation value */
			diff = (sint32)(ip_ptr[1] - ip_ptr[0] );
			tmp_product = (sint32)(diff * (sint32)y_factor);
			tmp1 = (sint32)(((sint32)*ip_ptr + (tmp_product/(sint32)65536)) + (((tmp_product % (sint32)65536) * 2)/(sint32)65536));
			/* point the pointer to the element in next row and same column */
			ip_ptr += num_col;
			/* calculate second column interpolation value */
			diff = (sint32)(ip_ptr[1] - ip_ptr[0] );
			tmp_product = (sint32)(diff * (sint32)y_factor);
			tmp2 = (sint32)(((sint32)*ip_ptr + (tmp_product /(sint32)65536)) + (((tmp_product% (sint32)65536) * 2)/(sint32)65536));
			/* calculate line interpolation between the fisrt and second column interpolated values */
			diff = (tmp2 - tmp1);
			tmp_product = (sint32)(diff * (sint32)x_factor);
			tmp1 =  ((tmp1 + (tmp_product / (sint32)65536)) + (((tmp_product% (sint32)65536) * 2)/(sint32)65536));

			/*~E*/
		}
		else
		{
			/*~A*/
			/*~+:If line factor is non-zero but col_factor is zero, then interpolate between lines*/
			/* if line factor is non-zero but col_factor is zero, then calculate only line interpolation */
			diff = (sint32)(ip_ptr[num_col] - ip_ptr[0] );
			tmp_product = (sint32)(diff * (sint32)x_factor);
			tmp1 =  (((sint32)*ip_ptr + (tmp_product /(sint32)65536)) + (((tmp_product%(sint32)65536) * 2)/(sint32)65536));

			/*~E*/
		}
	}
	else
	{
		if (y_factor != 0U)
		{
			/*~A*/
			/*~+:If line factor is zero but column factor is non-zero then interpolate between columns*/
			/* if line factor is zero but column factor is non-zero, then calculate only column  interpolation */
			diff = (sint32)(ip_ptr[1] - ip_ptr[0] );
			tmp_product = (sint32)(diff * (sint32)y_factor);
			tmp1 = (((sint32)*ip_ptr + (tmp_product /(sint32)65536)) + (((tmp_product%(sint32)65536) * 2)/(sint32)65536));

			/*~E*/
		}
		else
		{
			/*~A*/
			/*~+:If line factor and column factor are zero return the value pointed by the line index and column index*/
			/* if line factor and column factor are zero return the value pointed by the line index and column index */
			tmp1 = (sint32) *ip_ptr;
			/*~E*/
		}
	}
	return (uint8)tmp1;

	/* ## Operation body end [375a26ec-412f-467a-9fbe-8f27b9db46b9] */
}

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

uint8 func_u8_ip_rel_ptr_u16_u16_idyp(const uint8 * ptr_map, const uint16 * xdp_ptr, const uint16 * ydp_ptr, uint16 xval, uint16 yval, uint8 * idyp)
{
	/* ## Operation body start [67cd5dfb-5310-4379-8bd3-d71bad67a02e] */
	const uint16 *tmp_ptr;                  /* pointer to data point arrays */
	const uint8  *ip_ptr;                   /* pointer to map array */
	uint32       x_factor, y_factor;        /* variables to store line and column factors */
	uint32       x_index, index, num_col;   /* variable to store index and number of columns */
	sint32       tmp_product;               /* temporary variable to store intermediate results */
	sint32       tmp1, tmp2, diff;          /* variables to store intermediate results */

	uint16 temp1_u16;
	/* pointer to point to last element of x-data point array */
	tmp_ptr = xdp_ptr + *xdp_ptr;

	/*~A*/
	/*~+:Calculate the index value and line factor*/
	/* compare input point value with highest x-data point array */
	if (xval >= *tmp_ptr)
	{
		/*set line factor to zero */
		temp1_u16 = (*xdp_ptr - 1U);
		x_index = (uint32)temp1_u16;
		x_factor = 0;

	}
	else
	{
		/*compare input point value with lowest data point array
        value */
		if (xval <= *(xdp_ptr + 1U))
		{
			/*set line factor to zero */
			x_factor = 0;
			x_index = 0;

		}
		else
		{
			/* search input point value in the x-data point array from top to bottom */
			do
			{
				--tmp_ptr;
				x_factor = *tmp_ptr;
			}
			while (x_factor > (uint32)xval);
			/* line index calculation*/
			x_index = (((uint32)tmp_ptr - (uint32)xdp_ptr)/2U) - 1U;
			/* line factor calculation */
			temp1_u16 = *(tmp_ptr + 1);
			x_factor = (((uint32)xval - x_factor) * (uint32)65536) / (uint32)(temp1_u16 - x_factor);
		}
	}

	/*~E*/
	index = *idyp;

	/* compare if relative index value exceeds no. of data values in data point array*/
	num_col = *ydp_ptr;
	if (index >= num_col)
	{
		/* set relative index value to index of last element of y-data point array */
		index = num_col - 1U;
	}
	/* pointer to point to the the data point value pointed by relative pointer */
	tmp_ptr = ydp_ptr + (index + 1U);
	/* compare input point value with data point array value pointed by relative pointer */
	if (yval >= *tmp_ptr)
	{
		/*~A*/
		/*~+:Search data point value in upper portion of the data point array*/
		/* compare input point value with highest data point array value */
		if (yval >= *(ydp_ptr + num_col))
		{
			/* set index to last value in data point  array */
			index = (uint32)(num_col - 1U);
			/* set line factor to zero */
			y_factor = 0;
		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to top*/
			do
			{
				++tmp_ptr;
				y_factor = *tmp_ptr;
			}
			while (y_factor <= (uint32)yval );
			/* column index value calculation*/
			index = (((uint32)tmp_ptr - (uint32) ydp_ptr)/2U) - 2U;
			/* column factor calculation */
			temp1_u16 = *(tmp_ptr - 1);
			y_factor = (((uint32)yval - temp1_u16) * (uint32)65536) / (uint32)(y_factor - temp1_u16);
		}
		/*~E*/
	}
	else
	{
		/*~A*/
		/*~+:Search data point value in lower portion of the data point array*/
		/* compare input point value with lowest data point array value */
		if (yval <= *(ydp_ptr + 1))
		{
			/* set index to first value in data point  array */
			index = 0;
			/* set line factor to zero */
			y_factor = 0;
		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to bottom */
			do
			{
				--tmp_ptr;
				y_factor = *tmp_ptr;
			}
			while (y_factor > (uint32)yval);
			/* column index value calculation*/
			index = (((uint32)tmp_ptr - (uint32) ydp_ptr)/2U) - 1U;
			/* column factor calculation */
			temp1_u16 = *(tmp_ptr + 1);
			y_factor = (((uint32)yval - y_factor) * (uint32)65536) / (uint32)(temp1_u16 - y_factor);
		}

		/*~E*/
	}
	/* set relative pointer */
	*idyp = (uint8)index;
	x_index = x_index * num_col;
	index += x_index;
	/* temporary pointer to point to an element in interpolation data array */
	ip_ptr = ptr_map + index;
	if (x_factor != 0U)
	{
		if (y_factor != 0U)
		{
			/*~A*/
			/*~+:If both line and column factors are non-zero then interpolate between both column and line*/
			/* if line factor and column factor both are non-zero, then calculate first column interpolation value */
			diff = (sint32)(ip_ptr[1] - ip_ptr[0] );
			tmp_product = (sint32)(diff * (sint32)y_factor);
			tmp1 = (sint32)(((sint32)*ip_ptr + (tmp_product/(sint32)65536)) + (((tmp_product % (sint32)65536) * 2)/(sint32)65536));
			/* point the pointer to the element in next row and same column */
			ip_ptr += num_col;
			/* calculate second column interpolation value */
			diff = (sint32)(ip_ptr[1] - ip_ptr[0] );
			tmp_product = (sint32)(diff * (sint32)y_factor);
			tmp2 = (sint32)(((sint32)*ip_ptr + (tmp_product /(sint32)65536)) + (((tmp_product% (sint32)65536) * 2)/(sint32)65536));
			/* calculate line interpolation between the fisrt and second column interpolated values */
			diff = (tmp2 - tmp1);
			tmp_product = (sint32)(diff * (sint32)x_factor);
			tmp1 =  ((tmp1 + (tmp_product / (sint32)65536) )+ (((tmp_product% (sint32)65536) * 2)/(sint32)65536));

			/*~E*/
		}
		else
		{
			/*~A*/
			/*~+:If line factor is non-zero but col_factor is zero, then interpolate between lines*/
			/* if line factor is non-zero but col_factor is zero, then calculate only line interpolation */
			diff = (sint32)(ip_ptr[num_col] - ip_ptr[0] );
			tmp_product = (sint32)(diff * (sint32)x_factor);
			tmp1 = ( ((sint32)*ip_ptr + (tmp_product /(sint32)65536 ))+ (((tmp_product%(sint32)65536) * 2)/(sint32)65536));

			/*~E*/
		}
	}
	else
	{
		if (y_factor != 0U)
		{
			/*~A*/
			/*~+:If line factor is zero but column factor is non-zero then interpolate between columns*/
			/* if line factor is zero but column factor is non-zero, then calculate only column  interpolation */
			diff = (sint32)(ip_ptr[1] - ip_ptr[0] );
			tmp_product = (sint32)(diff * (sint32)y_factor);
			tmp1 = (((sint32)*ip_ptr + (tmp_product /(sint32)65536 )) + (((tmp_product%(sint32)65536) * 2)/(sint32)65536));

			/*~E*/
		}
		else
		{
			/*~A*/
			/*~+:If line factor and column factor are zero return the value pointed by the line index and column index*/
			/* if line factor and column factor are zero return the value pointed by the line index and column index */
			tmp1 = (sint32) (*ip_ptr);
			/*~E*/
		}
	}
	return (uint8)tmp1;

	/* ## Operation body end [67cd5dfb-5310-4379-8bd3-d71bad67a02e] */
}

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

uint16 func_u16_ip_rel_ptr_u8_idxp_u8(const uint16 * ptr_map, const uint8 * xdp_ptr, const uint8 * ydp_ptr, uint8 xval, uint8 yval, uint8 * idxp)
{
	/* ## Operation body start [8af10cdb-949a-4c40-8adf-1eba2cb4341a] */
	const uint8 *tmp_ptr;               /* pointer to data point arrays */
	const uint16 *ip_ptr;               /* pointer to map array */
	uint32   x_factor, y_factor;        /* variables to store line and column factors */
	uint32   index, num_col;            /* variable to store index and number of columns */
	uint32   tmp_product;               /* temporary variable to store intermediate results */
	sint32   tmp1, tmp2, diff;          /* variables to store intermediate results */
	uint8 temp1_u8;
	/* assign x-relative index value to temporary variable */
	index  = *idxp;
	/* compare if relative index value exceeds no. of data values in data point array*/
	if (index >= *xdp_ptr)
	{
		/* set relative index value to index of last element of x-data point array */
		index = *xdp_ptr ;
		index--;
	}
	/* pointer to point to the the data point value pointed by relative pointer */
	tmp_ptr = xdp_ptr + (index + 1U);
	/* compare input point value with data point array value pointed by relative pointer */
	if (xval >= *tmp_ptr)
	{
		/*~A*/
		/*~+:Search data point value in upper portion of the data point array*/
		/* compare input point value with highest data point array value */
		temp1_u8 = *(xdp_ptr + (*xdp_ptr));
		if (xval >= temp1_u8 )
		{
			/* set index to last value in data point  array */
			temp1_u8 = (*xdp_ptr - 1U);
			index = (uint32)temp1_u8;
			/* set line factor to zero */
			x_factor = 0;
		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to top*/
			do
			{
				++tmp_ptr;
				x_factor = *tmp_ptr;
			}
			while ( x_factor <= (uint32)xval );
			/* line index value calculation*/
			index = ((uint32)tmp_ptr - (uint32) xdp_ptr) - 2U;
			/* line factor calculation */
			temp1_u8 = *(tmp_ptr - 1);
			x_factor = (((uint32)xval - temp1_u8) * (uint32)65536) / (uint32)(x_factor - temp1_u8);
		}

		/*~E*/
	}
	else
	{
		/*~A*/
		/*~+:Search data point value in lower portion of the data point array*/
		/* compare input point value with lowest data point array value */
		if (xval <= *(xdp_ptr + 1))
		{
			/* set index to first value in data point  array */
			index = 0;
			/* set line factor to zero */
			x_factor = 0;
		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to bottom */
			do
			{
				--tmp_ptr;
				x_factor = *tmp_ptr;
			}
			while ( x_factor > (uint32)xval );
			/* line index value calculation*/
			index = ((uint32)tmp_ptr - (uint32) xdp_ptr) - 1U;
			/* line factor calculation */
			temp1_u8 = *(tmp_ptr + 1);
			x_factor = (((uint32)xval - x_factor) * (uint32)65536) / (uint32)(temp1_u8 - x_factor);
		}

		/*~E*/
	}
	/* set relative pointer */
	*idxp = (uint8)index;
	/* pointer to point to last element of y-data point array */
	num_col = *ydp_ptr;
	tmp_ptr = ydp_ptr + num_col ;
	index = (index * num_col);
	/*~A*/
	/*~+:Calculate the index value and column factor*/
	/* compare input point value with highest y-data point array */
	if (yval >= *tmp_ptr)
	{
		/*set column factor to zero */
		index = index + num_col - 1U;
		y_factor = 0;

	}
	else
	{
		/*compare input point value with lowest data point array
        value */
		if (yval <= *(ydp_ptr + 1))
		{
			/*set column factor to zero */
			y_factor = 0;

		}
		else
		{
			/* search input point value in the y-data point array from top to bottom */
			do
			{
				--tmp_ptr;
				y_factor = *tmp_ptr;
			}
			while (y_factor > (uint32)yval);
			/* index calculation*/
			index = index + (uint32)((uint32)tmp_ptr - (uint32) ydp_ptr) - 1U;
			/* column factor calculation */
			temp1_u8 = *(tmp_ptr + 1);
			y_factor = (((uint32)yval - y_factor) * (uint32)65536) / (uint32)(temp1_u8 - y_factor);
		}
	}

	/*~E*/
	/* temporary pointer to point to an element in interpolation data array */
	ip_ptr = ptr_map + index;
	if (x_factor != 0U)
	{
		if  (y_factor != 0U)
		{
			/*~A*/
			/*~+:If both line and column factors are non-zero theninterpolate between both column and line*/
			/* if line factor and column factor both are non-zero, then calculate first column interpolation value */
			diff = (sint32)ip_ptr[1] - (sint32)ip_ptr[0] ;
			if (diff >= 0)
			{
				tmp_product = (uint32)diff * y_factor;
				tmp1 = (sint32)(((uint32)*ip_ptr +  (tmp_product/(uint32)65536 ))+ (((tmp_product % (uint32)65536) * 2U)/(uint32)65536));
			}
			else
			{
				tmp_product = (uint32)(-diff) * y_factor;
				tmp1 = (sint32)(((uint32)*ip_ptr - (tmp_product /(uint32)65536) )- (((tmp_product %(uint32)65536)* 2U) /(uint32)65536));
			}
			/* point the pointer to the element in next row and same column */
			ip_ptr += num_col;
			/* calculate second column interpolation value */
			diff = (sint32)ip_ptr[1] - (sint32)ip_ptr[0] ;
			if (diff >= 0)
			{
				tmp_product = (uint32)diff * y_factor;
				tmp2 = (sint32)(((uint32)*ip_ptr +  (tmp_product / (uint32)65536)) + (((tmp_product % (uint32)65536) * 2U)/(uint32)65536));
			}
			else
			{
				tmp_product = (uint32)(-diff) * y_factor;
				tmp2 = (sint32)(((uint32)*ip_ptr - (tmp_product / (uint32)65536 ))- (((tmp_product % (uint32)65536) * 2U)/(uint32)65536));
			}
			/* calculate line interpolation between the fisrt and second column interpolated values */
			diff = (tmp2 - tmp1);
			if (diff >= 0)
			{
				tmp_product = (uint32)diff * x_factor;
				tmp1 = (sint32)(((uint32)tmp1 +  (tmp_product / (uint32)65536)) +( ((tmp_product % (uint32)65536) * 2U) /(uint32)65536));
			}
			else
			{
				tmp_product = (uint32)(-diff) * x_factor;
				tmp1 = (sint32)(((uint32)tmp1 - (tmp_product / (uint32)65536)) - (((tmp_product % (uint32)65536) * 2U)/(uint32)65536));
			}
			/*~E*/
		}
		else
		{
			/*~A*/
			/*~+:If line factor is non-zerobut col_factor is zero, then interpolate between lines*/
			/* if line factor is non-zero but col_factor is zero, then calculate only line interpolation */
			diff = (sint32)ip_ptr[num_col] - (sint32)ip_ptr[0];
			if (diff >= 0)
			{
				tmp_product = (uint32)diff * x_factor;
				tmp1 = (sint32)((*ip_ptr +  ( tmp_product /(uint32)65536)) + ((( tmp_product % (uint32)65536) * 2U) /(uint32)65536));
			}
			else
			{
				tmp_product = (uint32)(-diff)* x_factor;
				tmp1 = (sint32)(((uint32)*ip_ptr - (tmp_product / (uint32)65536)) - ((( tmp_product % (uint32)65536) * 2U) / (uint32)65536));
			}
			/*~E*/
		}
	}
	else
	{
		if  (y_factor != 0U)
		{
			/*~A*/
			/*~+:If line factor is zerobut column factor is non-zero then interpolate between columns*/
			/* if line factor is zero but column factor is non-zero, then calculate only column  interpolation */
			diff = (sint32)ip_ptr[1] - (sint32)ip_ptr[0];
			if (diff >= 0)
			{
				tmp_product = (uint32)diff * y_factor;
				tmp1 = (sint32)(((uint32)*ip_ptr +   (tmp_product / (uint32)65536)) + ((( tmp_product % (uint32)65536) * 2U) / (uint32)65536));
			}
			else
			{
				tmp_product = (uint32)     (-diff) * y_factor;
				tmp1 = (sint32)(((uint32)*ip_ptr - (tmp_product / (uint32)65536)) - ((( tmp_product % (uint32)65536) * 2U) / (uint32)65536));
			}
			/*~E*/
		}
		else
		{
			/*~A*/
			/*~+:If line factor and column factor are zero return the value pointed by the line index and column index*/
			/* if line factor and column factor are zero return the value pointed by the line index and column index */
			tmp1 = (sint32)(*ip_ptr);
			/*~E*/
		}
	}
	return (uint16)tmp1;


	/* ## Operation body end [8af10cdb-949a-4c40-8adf-1eba2cb4341a] */
}

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

uint16 func_u16_ip_rel_ptr_u8_u8_idyp(const uint16 * ptr_map, const uint8 * xdp_ptr, const uint8 * ydp_ptr, uint8 xval, uint8 yval, uint8 * idyp)
{
	/* ## Operation body start [d3c5efdb-e478-416a-9a81-cabfaabd402c] */
	const uint8  *tmp_ptr;                    /* pointer to data point arrays */
	const uint16 *ip_ptr;                     /* pointer to map array */
	uint32       x_factor, y_factor;          /* variables to store line and column factors */
	uint32       x_index, index, num_col;     /* variable to store index and number of columns */
	uint32       tmp_product;                 /* temporary variable to store intermediate results */
	sint32       tmp1, tmp2, diff;            /* variables to store intermediate results */
	uint8 temp1_u8;
	/* pointer to point to last element of x-data point array */
	tmp_ptr = xdp_ptr + *xdp_ptr;

	/*~A*/
	/*~+:Calculate the index value and line factor*/
	/* compare input point value with highest x-data point array */
	if (xval >= *tmp_ptr)
	{
		/*set line factor to zero */
		x_index = *xdp_ptr;
		x_index--;
		x_factor = 0;

	}
	else
	{
		/*compare input point value with lowest data point array
        value */
		if (xval <= *(xdp_ptr + 1U))
		{
			/*set line factor to zero */
			x_factor = 0;
			x_index = 0;

		}
		else
		{
			/* search input point value in the x-data point array from top to bottom */
			do
			{
				--tmp_ptr;
				x_factor = *tmp_ptr;
			}
			while ( x_factor > (uint32)xval );
			/* line index calculation*/
			x_index = ((uint32)tmp_ptr - (uint32) xdp_ptr) - 1U;
			/* line factor calculation */
			temp1_u8 = *(tmp_ptr + 1U);
			x_factor = (((uint32)xval - x_factor) * (uint32)65536) / (uint32)(temp1_u8 - x_factor);
		}
	}

	/*~E*/
	index = *idyp;

	/* compare if relative index value exceeds no. of data values in data point array*/
	num_col = *ydp_ptr;
	if (index >= num_col)
	{
		/* set relative index value to index of last element of y-data point array */
		index = num_col - 1U;
	}
	/* pointer to point to the the data point value pointed by relative pointer */
	tmp_ptr = ydp_ptr + (index + 1U);
	/* compare input point value with data point array value pointed by relative pointer */
	if (yval >= *tmp_ptr)
	{
		/*~A*/
		/*~+:Search data point value in upper portion of the data point array*/
		/* compare input point value with highest data point array value */
		if (yval >= ydp_ptr[num_col])
		{
			/* set index to last value in data point  array */
			index = (uint32)(num_col - 1U);
			/* set line factor to zero */
			y_factor = 0;
		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to top*/
			do
			{
				++tmp_ptr;
				y_factor = *tmp_ptr;
			}
			while ( y_factor <= (uint32)yval );
			/* column index value calculation*/
			index = ((uint32)tmp_ptr - (uint32) ydp_ptr) - 2U;
			/* column factor calculation */
			temp1_u8 = *(tmp_ptr - 1);
			y_factor = (((uint32)yval - temp1_u8 ) * (uint32)65536) / (uint32)(y_factor - temp1_u8 );
		}
		/*~E*/
	}
	else
	{
		/*~A*/
		/*~+:Search data point value in lower portion of the data point array*/
		/* compare input point value with lowest data point array value */
		if (yval <= *(ydp_ptr + 1))
		{
			/* set index to first value in data point  array */
			index = 0;
			/* set line factor to zero */
			y_factor = 0;
		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to bottom */
			do
			{
				--tmp_ptr;
				y_factor = *tmp_ptr;
			}
			while (y_factor > (uint32)yval);
			/* column index value calculation*/
			index = ((uint32)tmp_ptr - (uint32) ydp_ptr) - 1U;
			/* column factor calculation */
			temp1_u8 = *(tmp_ptr + 1);
			y_factor = (((uint32)yval - y_factor) * (uint32)65536) / (uint32)(temp1_u8 - y_factor);
		}

		/*~E*/
	}
	/*set relative pointer */
	*idyp = (uint8)index;
	x_index = x_index * num_col;
	index += x_index;
	/*temporary pointer to point to an element in interpolation data array */
	ip_ptr = ptr_map + index;
	if (x_factor != 0U)
	{
		if  (y_factor != 0U)
		{
			/*~A*/
			/*~+:If both line and column factors are non-zero theninterpolate between both column and line*/
			/* if line factor and column factor both are non-zero, then calculate first column interpolation value */
			diff = (sint32)ip_ptr[1] - (sint32)ip_ptr[0];
			if (diff >= 0)
			{
				tmp_product = (uint32)diff * y_factor;
				tmp1 = (sint32)(((uint32)*ip_ptr +  (tmp_product/(uint32)65536)) + (((tmp_product % (uint32)65536) * 2U)/(uint32)65536));
			}
			else
			{
				tmp_product = (uint32)(-diff) * y_factor;
				tmp1 = (sint32)(((uint32)*ip_ptr - (tmp_product /(uint32)65536)) - (((tmp_product %(uint32)65536)* 2U) /(uint32)65536));
			}
			/* point the pointer to the element in next row and same column */
			ip_ptr += num_col;
			/* calculate second column interpolation value */
			diff = (sint32)ip_ptr[1] - (sint32)ip_ptr[0];
			if (diff >= 0)
			{
				tmp_product = (uint32)diff * y_factor;
				tmp2 = (sint32)(((uint32)*ip_ptr +  (tmp_product / (uint32)65536)) + (((tmp_product % (uint32)65536) * 2U)/(uint32)65536));
			}
			else
			{
				tmp_product = (uint32)(-diff) * y_factor;
				tmp2 = (sint32)(((uint32)*ip_ptr - (tmp_product / (uint32)65536)) - (((tmp_product % (uint32)65536) * 2U)/(uint32)65536));
			}
			/* calculate line interpolation between the fisrt and second column interpolated values */
			diff = (tmp2 - tmp1);
			if (diff >= 0)
			{
				tmp_product = (uint32)diff * x_factor;
				tmp1 = (sint32)(((uint32)tmp1 +  ( tmp_product / (uint32)65536)) + (((tmp_product % (uint32)65536) * 2U) /(uint32)65536));
			}
			else
			{
				tmp_product = (uint32)(-diff) * x_factor;
				tmp1 = (sint32)(((uint32)tmp1 - (tmp_product / (uint32)65536)) - (((tmp_product % (uint32)65536) * 2U)/(uint32)65536));
			}
			/*~E*/
		}
		else
		{
			/*~A*/
			/*~+:If line factor is non-zerobut col_factor is zero, then interpolate between lines*/
			/* if line factor is non-zero but col_factor is zero, then calculate only line interpolation */
			diff = (sint32)(ip_ptr[num_col] - ip_ptr[0]);
			if (diff >= 0)
			{
				tmp_product = (uint32)diff * x_factor;
				tmp1 = (sint32)(((uint32)*ip_ptr +   (tmp_product /(uint32)65536)) + ((( tmp_product % (uint32)65536) * 2U) /(uint32)65536));
			}
			else
			{
				tmp_product = (uint32)(-diff)* x_factor;
				tmp1 = (sint32)(((uint32)*ip_ptr - (tmp_product / (uint32)65536)) - ((( tmp_product % (uint32)65536) * 2U) / (uint32)65536));
			}
			/*~E*/
		}
	}
	else
	{
		if  (y_factor != 0U)
		{
			/*~A*/
			/*~+:If line factor is zerobut column factor is non-zero then interpolate between columns*/
			/* if line factor is zero but column factor is non-zero, then calculate only column  interpolation */
			diff = (sint32)ip_ptr[1] - (sint32)ip_ptr[0] ;
			if (diff >= 0)
			{
				tmp_product = (uint32)diff * y_factor;
				tmp1 = (sint32)(((uint32)*ip_ptr +   (tmp_product / (uint32)65536)) + ((( tmp_product % (uint32)65536) * 2U) / (uint32)65536));
			}
			else
			{
				tmp_product = (uint32)     (-diff) * y_factor;
				tmp1 = (sint32)(((uint32)*ip_ptr - (tmp_product / (uint32)65536)) - ((( tmp_product % (uint32)65536) * 2U) / (uint32)65536));
			}
			/*~E*/
		}
		else
		{
			/*~A*/
			/*~+:If line factor and column factor are zero return the value pointed by the line index and column index*/
			/* if line factor and column factor are zero return the value pointed by the line index and column index */
			tmp1 = (sint32)(*ip_ptr);
			/*~E*/
		}
	}
	return (uint16)tmp1;


	/* ## Operation body end [d3c5efdb-e478-416a-9a81-cabfaabd402c] */
}

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

uint16 func_u16_ip_rel_ptr_u16_idxp_u8(const uint16 * ptr_map, const uint16 * xdp_ptr, const uint8 * ydp_ptr, uint16 xval, uint8 yval, uint8 * idxp)
{
	/* ## Operation body start [e3c19e11-729c-4888-b9e1-3dd84f330062] */
	const uint8  *ytmp_ptr;             /* pointer to y-data point array */
	const uint16 *tmp_ptr;              /* pointer to x-data point array and map */
	uint32       x_factor, y_factor;    /* variables to store line and column factors */
	uint32       index, num_col;        /* variable to store index and number of columns */
	uint32       tmp_product;           /* temporary variable to store intermediate results */
	sint32       tmp1, tmp2, diff;      /* variables to store intermediate results */
	uint16 temp1_u16;
	uint8 temp1_u8;
	/* assign x-relative index value to temporary variable */
	index  = *idxp;

	/* compare if relative index value exceeds no. of data values in data point array*/
	if (index >= *xdp_ptr)
	{
		/* set relative index value to index of last element of x-data point array */
		index = *xdp_ptr ;
		index--;
	}
	/* pointer to point to the the data point value pointed by relative pointer */
	tmp_ptr = xdp_ptr + (index + 1U);
	/* compare input point value with data point array value pointed by relative pointer */
	if (xval >= *tmp_ptr)
	{
		/*~A*/
		/*~+:Search data point value in upper portion of the data point array*/
		/* compare input point value with highest data point array value */
		if (xval >= xdp_ptr[*xdp_ptr])
		{
			/* set index to last value in data point  array */
			temp1_u16 = (*xdp_ptr - 1U);
			index = (uint32)temp1_u16;
			/* set line factor to zero */
			x_factor = 0;
		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to top*/
			do
			{
				++tmp_ptr;
				x_factor = *tmp_ptr;
			}
			while ( x_factor <= (uint32)xval );
			/* line index value calculation*/
			index = (((uint32)tmp_ptr - (uint32) xdp_ptr)/2U) - 2U;
			/* line factor calculation */
			temp1_u16 = *(tmp_ptr - 1U);
			x_factor = (((uint32)xval - temp1_u16 ) * (uint32)65536) / (uint32)(x_factor - temp1_u16 );
		}
		/*~E*/
	}
	else
	{
		/*~A*/
		/*~+:Search data point value in lower portion of the data point array*/
		/* compare input point value with lowest data point array value */
		if (xval <= *(xdp_ptr + 1))
		{
			/* set index to first value in data point  array */
			index = 0;
			/* set line factor to zero */
			x_factor = 0;
		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to bottom */
			do
			{
				--tmp_ptr;
				x_factor = *tmp_ptr;
			}
			while (x_factor > (uint32)xval);
			/* line index value calculation*/
			index = (((uint32)tmp_ptr - (uint32) xdp_ptr)/2U) - 1U;
			/* line factor calculation */
			temp1_u16 = *(tmp_ptr + 1U);
			x_factor = (((uint32)xval - x_factor) * (uint32)65536) / (uint32)(temp1_u16 - x_factor);
		}
		/*~E*/
	}
	/*set relative pointer */
	*idxp = (uint8)index;
	/* pointer to point to last element of y-data point array */
	num_col = *ydp_ptr;
	ytmp_ptr = ydp_ptr + num_col ;
	index = (index * num_col);
	/*~A*/
	/*~+:Calculate the index value and column factor*/
	/* compare input point value with highest y-data point array */
	if (yval >= *ytmp_ptr)
	{
		/*set column factor to zero */
		index = (index + num_col ) - 1U;
		y_factor = 0;


	}
	else
	{
		/*compare input point value with lowest data point array
        value */
		if (yval <= *(ydp_ptr + 1U))
		{
			/*set column factor to zero */
			y_factor = 0;

		}
		else
		{
			/* search input point value in the y-data point array from top to bottom */
			do
			{
				--ytmp_ptr;
				y_factor = *ytmp_ptr;
			}
			while (y_factor > (uint32)yval);
			/* index calculation*/
			index = (index + (uint32)((uint32)ytmp_ptr - (uint32) ydp_ptr)) - 1U;
			/* column factor calculation */
			temp1_u8 = *(ytmp_ptr + 1U) ;
			y_factor = (((uint32)yval - y_factor) * (uint32)65536) / (uint32)(temp1_u8 - y_factor);
		}
	}

	/*~E*/
	/*temporary pointer to point to an element in interpolation data array */
	tmp_ptr = ptr_map + index;
	if (x_factor != 0U)
	{
		if  (y_factor != 0U)
		{
			/*~A*/
			/*~+:If both line and column factors are non-zero theninterpolate between both column and line*/
			/* if line factor and column factor both are non-zero, then calculate first column interpolation value */
			diff = (sint32)(tmp_ptr[1] - tmp_ptr[0] );
			if (diff >= 0)
			{
				tmp_product = (uint32)diff * y_factor;
				tmp1 = (sint32)(((uint32)*tmp_ptr +  (tmp_product/(uint32)65536)) + (((tmp_product % (uint32)65536) * 2U)/(uint32)65536));
			}
			else
			{
				tmp_product = (uint32)(-diff) * y_factor;
				tmp1 = (sint32)(((uint32)*tmp_ptr - ( tmp_product /(uint32)65536) ) - (((tmp_product %(uint32)65536)* 2U) /(uint32)65536));
			}
			/* point the pointer to the element in next row and same column */
			tmp_ptr += num_col;
			/* calculate second column interpolation value */
			diff = (sint32)(tmp_ptr[1] - tmp_ptr[0] );
			if (diff >= 0)
			{
				tmp_product = (uint32)diff * y_factor;
				tmp2 = (sint32)(((uint32)*tmp_ptr +  (tmp_product / (uint32)65536)) + (((tmp_product % (uint32)65536) * 2U)/(uint32)65536));
			}
			else
			{
				tmp_product = (uint32)(-diff) * y_factor;
				tmp2 = (sint32)(((uint32)*tmp_ptr - (tmp_product / (uint32)65536)) - (((tmp_product % (uint32)65536) * 2U)/(uint32)65536));
			}
			/* calculate line interpolation between the fisrt and second column interpolated values */
			diff = (tmp2 - tmp1);
			if (diff >= 0)
			{
				tmp_product = (uint32)diff * x_factor;
				tmp1 =  (sint32)(((uint32)tmp1 +  ( tmp_product / (uint32)65536)) + (((tmp_product % (uint32)65536) * 2U) /(uint32)65536));
			}
			else
			{
				tmp_product = (uint32)(-diff) * x_factor;
				tmp1 =  (sint32)(((uint32)tmp1 - (tmp_product / (uint32)65536)) - (((tmp_product % (uint32)65536) * 2U)/(uint32)65536));
			}
			/*~E*/
		}
		else
		{
			/*~A*/
			/*~+:If line factor is non-zerobut col_factor is zero, then interpolate between lines*/
			/* if line factor is non-zero but col_factor is zero, then calculate only line interpolation */
			diff = (sint32)(tmp_ptr[num_col] - tmp_ptr[0] );
			if (diff >= 0)
			{
				tmp_product = (uint32)diff * x_factor;
				tmp1 =  (sint32)(((uint32)*tmp_ptr +  ( tmp_product /(uint32)65536)) + ((( tmp_product % (uint32)65536) * 2U) /(uint32)65536));
			}
			else
			{
				tmp_product = (uint32)(-diff)* x_factor;
				tmp1 =  (sint32)(((uint32)*tmp_ptr - (tmp_product / (uint32)65536)) - ((( tmp_product % (uint32)65536) * 2U) / (uint32)65536));
			}
			/*~E*/
		}
	}
	else
	{
		if  (y_factor != 0U)
		{
			/*~A*/
			/*~+:If line factor is zerobut column factor is non-zero then interpolate between columns*/
			/* if line factor is zero but column factor is non-zero, then calculate only column  interpolation */
			diff = (sint32)(tmp_ptr[1] - tmp_ptr[0] );
			if (diff >= 0)
			{
				tmp_product = (uint32)diff * y_factor;
				tmp1 = (sint32)(((uint32)*tmp_ptr +  ( tmp_product / (uint32)65536)) + ((( tmp_product % (uint32)65536) * 2U) / (uint32)65536));
			}
			else
			{
				tmp_product = (uint32)     (-diff) * y_factor;
				tmp1 =  (sint32)(((uint32)*tmp_ptr - (tmp_product / (uint32)65536)) - ((( tmp_product % (uint32)65536) * 2U) / (uint32)65536));
			}
			/*~E*/
		}
		else
		{
			/*~A*/
			/*~+:If line factor and column factor are zero return the value pointed by the line index and column index*/
			/* if line factor and column factor are zero return the value pointed by the line index and column index */
			tmp1 = (sint32)(*tmp_ptr);
			/*~E*/
		}
	}
	return (uint16)tmp1;


	/* ## Operation body end [e3c19e11-729c-4888-b9e1-3dd84f330062] */
}

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

uint16 func_u16_ip_rel_ptr_u16_u8_idyp(const uint16 * ptr_map, const uint16 * xdp_ptr, const uint8 * ydp_ptr, uint16 xval, uint8 yval, uint8 * idyp)
{
	/* ## Operation body start [3f197eb5-e1c3-4914-b9ae-7ab53c1579c3] */
	const uint8  *ytmp_ptr;                  /* pointer to y-data point array */
	const uint16 *tmp_ptr;                  /* pointer to x-data point array */
	uint32   x_factor, y_factor;                /* variables to store line and column factors and intermediate values */
	uint32   x_index, index, num_col;                    /* variable to store index and number of columns */
	uint32   tmp_product;                       /* temporary variable to store intermediate results */
	sint32   tmp1, tmp2, diff;                  /* variables to store intermediate results */
	uint16 temp1_u16;
	uint8 temp1_u8;
	/* pointer to point to last element of x-data point array */
	tmp_ptr = xdp_ptr + *xdp_ptr;

	/*~A*/
	/*~+:Calculate the index value and line factor*/
	/* compare input point value with highest x-data point array */
	if (xval >= *tmp_ptr)
	{
		/*set line factor to zero */
		temp1_u16 = (*xdp_ptr - 1U );
		x_index = (uint32)temp1_u16 ;
		x_factor = 0;

	}
	else
	{
		/*compare input point value with lowest data point array
        value */
		if (xval <= xdp_ptr[1])
		{
			/*set line factor to zero */
			x_factor = 0;
			x_index = 0;

		}
		else
		{
			/* search input point value in the x-data point array from top to bottom */
			do
			{
				--tmp_ptr;
				x_factor = *tmp_ptr;
			}
			while (x_factor > (uint32)xval);
			/* line index calculation*/
			x_index = (((uint32)tmp_ptr - (uint32) xdp_ptr)/2U) - 1U;
			/* line factor calculation */
			temp1_u16 = *(tmp_ptr + 1U);
			x_factor = (((uint32)xval - x_factor) * (uint32)65536) / (uint32)(temp1_u16 - x_factor);
		}
	}

	/*~E*/
	index = *idyp;

	/* compare if relative index value exceeds no. of data values in data point array*/
	num_col = *ydp_ptr;
	if (index >= num_col )
	{
		/* set relative index value to index of last element of y-data point array */
		index = num_col - 1U;
	}
	/* pointer to point to the the data point value pointed by relative pointer */
	ytmp_ptr = ydp_ptr + (index + 1U);
	/* compare input point value with data point array value pointed by relative pointer */
	if (yval >= *ytmp_ptr)
	{
		/*~A*/
		/*~+:Search data point value in upper portion of the data point array*/
		/* compare input point value with highest data point array value */
		if (yval >= ydp_ptr[num_col])
		{
			/* set index to last value in data point  array */
			index = (uint32)(num_col - 1U);
			/* set line factor to zero */
			y_factor = 0;
		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to top*/
			do
			{
				++ytmp_ptr;
				y_factor = *ytmp_ptr;
			}
			while (y_factor <= (uint32)yval);
			/* column index value calculation*/
			index = ((uint32)ytmp_ptr - (uint32) ydp_ptr) - 2U;
			/* column factor calculation */
			temp1_u8 = *(ytmp_ptr - 1U);
			y_factor = (((uint32)yval - temp1_u8) * (uint32)65536) / (uint32)(y_factor - temp1_u8 );
		}
		/*~E*/
	}
	else
	{
		/*~A*/
		/*~+:Search data point value in lower portion of the data point array*/
		/* compare input point value with lowest data point array value */
		if (yval <= *(ydp_ptr + 1U))
		{
			/* set index to first value in data point  array */
			index = 0;
			/* set line factor to zero */
			y_factor = 0;
		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to bottom */
			do
			{
				--ytmp_ptr;
				y_factor = *ytmp_ptr;
			}
			while ( y_factor > (uint32)yval);
			/* column index value calculation*/
			index = ((uint32)ytmp_ptr - (uint32) ydp_ptr) - 1U;
			/* column factor calculation */
			temp1_u8 = *(ytmp_ptr + 1U);
			y_factor = (((uint32)yval - y_factor) * (uint32)65536) / (uint32)(temp1_u8 - y_factor);
		}

		/*~E*/
	}
	/*set relative pointer */
	*idyp = (uint8)index;
	/* index calculation */
	x_index = x_index * num_col;
	index += x_index;
	/* temporary pointer to point to an element in interpolation data array */
	tmp_ptr = ptr_map + index;
	if (x_factor != 0U)
	{
		if  (y_factor != 0U)
		{
			/*~A*/
			/*~+:If both line and column factors are non-zero theninterpolate between both column and line*/
			/* if line factor and column factor both are non-zero, then calculate first column interpolation value */
			diff = (sint32)(tmp_ptr[1] - tmp_ptr[0] );
			if (diff >= 0)
			{
				tmp_product = (uint32)diff * y_factor;
				tmp1 = (sint32)(((uint32)*tmp_ptr +  (tmp_product/(uint32)65536)) + (((tmp_product % (uint32)65536) * 2U)/(uint32)65536));
			}
			else
			{
				tmp_product = (uint32)(-diff) * y_factor;
				tmp1 = (sint32)(((uint32)*tmp_ptr - (tmp_product /(uint32)65536)) - (((tmp_product %(uint32)65536)* 2U) /(uint32)65536));
			}
			/* point the pointer to the element in next row and same column */
			tmp_ptr += num_col;
			/* calculate second column interpolation value */
			diff = (sint32)(tmp_ptr[1] - tmp_ptr[0] );
			if (diff >= 0)
			{
				tmp_product = (uint32)diff * y_factor;
				tmp2 = (sint32)(((uint32)*tmp_ptr +  (tmp_product / (uint32)65536)) + (((tmp_product % (uint32)65536) * 2U)/(uint32)65536));
			}
			else
			{
				tmp_product = (uint32)(-diff) * y_factor;
				tmp2 = (sint32)(((uint32)*tmp_ptr - (tmp_product / (uint32)65536)) - (((tmp_product % (uint32)65536) * 2U)/(uint32)65536));
			}
			/* calculate line interpolation between the fisrt and second column interpolated values */
			diff = (tmp2 - tmp1);
			if (diff >= 0)
			{
				tmp_product = (uint32)diff * x_factor;
				tmp1 =  (sint32)(((uint32)tmp1 +  ( tmp_product / (uint32)65536)) + (((tmp_product % (uint32)65536) * 2U) /(uint32)65536));
			}
			else
			{
				tmp_product = (uint32)(-diff) * x_factor;
				tmp1 =  (sint32)(((uint32)tmp1 - (tmp_product / (uint32)65536) ) - (((tmp_product % (uint32)65536) * 2U)/(uint32)65536));
			}
			/*~E*/
		}
		else
		{
			/*~A*/
			/*~+:If line factor is non-zerobut col_factor is zero, then interpolate between lines*/
			/* if line factor is non-zero but col_factor is zero, then calculate only line interpolation */
			diff = (sint32)(tmp_ptr[num_col] - tmp_ptr[0] );
			if (diff >= 0)
			{
				tmp_product = (uint32)diff * x_factor;
				tmp1 =  (sint32)(((uint32)*tmp_ptr +  ( tmp_product /(uint32)65536))+ ((( tmp_product % (uint32)65536) * 2U) /(uint32)65536));
			}
			else
			{
				tmp_product = (uint32)(-diff)* x_factor;
				tmp1 =  (sint32)(((uint32)*tmp_ptr - (tmp_product / (uint32)65536)) - ((( tmp_product % (uint32)65536) * 2U) / (uint32)65536));
			}
			/*~E*/
		}
	}
	else
	{
		if  (y_factor != 0U)
		{
			/*~A*/
			/*~+:If line factor is zerobut column factor is non-zero then interpolate between columns*/
			/* if line factor is zero but column factor is non-zero, then calculate only column  interpolation */
			diff = (sint32)(tmp_ptr[1] - tmp_ptr[0] );
			if (diff >= 0)
			{
				tmp_product = (uint32)diff * y_factor;
				tmp1 = (sint32)(((uint32)*tmp_ptr +  ( tmp_product / (uint32)65536)) + ((( tmp_product % (uint32)65536) * 2U) / (uint32)65536));
			}
			else
			{
				tmp_product = (uint32)     (-diff) * y_factor;
				tmp1 =  (sint32)(((uint32)*tmp_ptr - (tmp_product / (uint32)65536)) - ((( tmp_product % (uint32)65536) * 2U) / (uint32)65536));
			}
			/*~E*/
		}
		else
		{
			/*~A*/
			/*~+:If line factor and column factor are zero return the value pointed by the line index and column index*/
			/* if line factor and column factor are zero return the value pointed by the line index and column index */
			tmp1 = (sint32)(*tmp_ptr);
			/*~E*/
		}
	}
	return (uint16)tmp1;

	/* ## Operation body end [3f197eb5-e1c3-4914-b9ae-7ab53c1579c3] */
}


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

uint16 func_u16_ip_rel_ptr_u8_idxp_u16(const uint16 * ptr_map, const uint8 * xdp_ptr, const uint16 * ydp_ptr, uint8 xval, uint16 yval, uint8 * idxp)
{
	/* ## Operation body start [e6dc574d-eca9-492a-b1a3-78ec53a29d8e] */
	const uint8 *xtmp_ptr;              /* pointer to x-data point array */
	const uint16 *tmp_ptr;              /* pointer to map array */
	uint32   x_factor, y_factor;        /* variables to store line and column factors */
	uint32   index, num_col;            /* variable to store index and number of columns */
	uint32   tmp_product;               /* temporary variable to store intermediate results */
	sint32   tmp1, tmp2, diff;          /* variables to store intermediate results */
	uint16 temp1_u16;
	uint8 temp1_u8;
	/* assign x-relative index value to temporary variable */
	index  = *idxp;
	/* compare if relative index value exceeds no. of data values in data point array*/
	if (index >= *xdp_ptr)
	{
		/* set relative index value to index of last element of x-data point array */
		index = *xdp_ptr;
		index--;
	}
	/* pointer to point to the the data point value pointed by relative pointer */
	xtmp_ptr = xdp_ptr + (index + 1U);
	/* compare input point value with data point array value pointed by relative pointer */
	if (xval >= *xtmp_ptr)
	{
		/*~A*/
		/*~+:Search data point value in upper portion of the data point array*/
		/* compare input point value with highest data point array value */
		if (xval >= xdp_ptr[*xdp_ptr] )
		{
			/* set index to last value in data point  array */
			temp1_u8= (*xdp_ptr - 1U);
			index = (uint32)temp1_u8;
			/* set line factor to zero */
			x_factor = 0;
		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to top*/
			do
			{
				++xtmp_ptr;
				x_factor = *xtmp_ptr;
			}
			while ( x_factor <= (uint32)xval );
			/* line index value calculation*/
			index = ((uint32)xtmp_ptr - (uint32) xdp_ptr) - 2U;
			/* line factor calculation */
			temp1_u8 = *(xtmp_ptr - 1U);
			x_factor = (((uint32)xval - temp1_u8 ) * (uint32)65536) / (uint32)(x_factor - temp1_u8 );
		}
		/*~E*/
	}
	else
	{
		/*~A*/
		/*~+:Search data point value in lower portion of the data point array*/
		/* compare input point value with lowest data point array value */
		if (xval <= xdp_ptr[1])
		{
			/* set relative pointer to first value in data point  array */
			index = 0;

			/* set line factor to zero */
			x_factor = 0;

		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to bottom */
			do
			{
				--xtmp_ptr;
				x_factor = *xtmp_ptr;
			}
			while (x_factor > (uint32)xval);
			/* line index value calculation*/
			index = ((uint32)xtmp_ptr - (uint32) xdp_ptr) - 1U;
			/* line factor calculation */
			temp1_u8 = *(xtmp_ptr + 1U);
			x_factor = (((uint32)xval - x_factor) * (uint32)65536) / (uint32)(temp1_u8 - x_factor);

		}
		/*~E*/
	}
	/*set relative pointer */
	*idxp = (uint8)index;
	/* pointer to point to last element of y-data point array */
	num_col = *ydp_ptr;
	tmp_ptr = ydp_ptr + num_col;
	index = (index * num_col);
	/*~A*/
	/*~+:Calculate the index value and column factor*/
	/* compare input point value with highest y-data point array */
	if (yval >= *tmp_ptr)
	{
		/*set column factor to zero */
		index = (index + num_col) - 1U;
		y_factor = 0;

	}
	else
	{
		/*compare input point value with lowest data point array
        value */
		if (yval <= ydp_ptr[1])
		{
			/*set column factor to zero */
			y_factor = 0;

		}
		else
		{
			/* search input point value in the y-data point array from top to bottom */
			do
			{
				--tmp_ptr;
				y_factor = *tmp_ptr;
			}
			while (y_factor> (uint32)yval);
			/* index calculation*/
			index = index + (uint32)((((uint32)tmp_ptr - (uint32) ydp_ptr)/2U) - 1U);
			/* column factor calculation */
			temp1_u16 = *(tmp_ptr + 1U);
			y_factor = (((uint32)yval - y_factor) * (uint32)65536) / (uint32)(temp1_u16 - y_factor);
		}
	}
	/*~E*/
	/*temporary pointer to point to an element in interpolation data array */
	tmp_ptr = ptr_map + index;
	if (x_factor != 0U)
	{
		if  (y_factor != 0U)
		{
			/*~A*/
			/*~+:If both line and column factors are non-zero theninterpolate between both column and line*/
			/* if line factor and column factor both are non-zero, then calculate first column interpolation value */
			diff = (sint32)(tmp_ptr[1] - tmp_ptr[0] );
			if (diff >= 0)
			{
				tmp_product = (uint32)diff * y_factor;
				tmp1 = (sint32)(((uint32)*tmp_ptr +  (tmp_product/(uint32)65536)) + (((tmp_product % (uint32)65536) * 2U)/(uint32)65536));
			}
			else
			{
				tmp_product = (uint32)(-diff) * y_factor;
				tmp1 = (sint32)(((uint32)*tmp_ptr - (tmp_product /(uint32)65536)) - (((tmp_product %(uint32)65536)* 2U) /(uint32)65536));
			}
			/* point the pointer to the element in next row and same column */
			tmp_ptr += num_col;
			/* calculate second column interpolation value */
			diff = (sint32)(tmp_ptr[1] - tmp_ptr[0] );
			if (diff >= 0)
			{
				tmp_product = (uint32)diff * y_factor;
				tmp2 = (sint32)(((uint32)*tmp_ptr +  (tmp_product / (uint32)65536)) + (((tmp_product % (uint32)65536) * 2U)/(uint32)65536));
			}
			else
			{
				tmp_product = (uint32)(-diff) * y_factor;
				tmp2 = (sint32)(((uint32)*tmp_ptr - (tmp_product / (uint32)65536)) - (((tmp_product % (uint32)65536) * 2U)/(uint32)65536));
			}
			/* calculate line interpolation between the fisrt and second column interpolated values */
			diff = (tmp2 - tmp1);
			if (diff >= 0)
			{
				tmp_product = (uint32)diff * x_factor;
				tmp1 =  (sint32)(((uint32)tmp1 + (tmp_product / (uint32)65536)) + (((tmp_product % (uint32)65536) * 2U) /(uint32)65536));
			}
			else
			{
				tmp_product = (uint32)(-diff) * x_factor;
				tmp1 =  (sint32)(((uint32)tmp1 - (tmp_product / (uint32)65536)) - (((tmp_product % (uint32)65536) * 2U)/(uint32)65536));
			}
			/*~E*/
		}
		else
		{
			/*~A*/
			/*~+:If line factor is non-zerobut col_factor is zero, then interpolate between lines*/
			/* if line factor is non-zero but col_factor is zero, then calculate only line interpolation */
			diff = (sint32)(tmp_ptr[num_col] - tmp_ptr[0] );
			if (diff >= 0)
			{
				tmp_product = (uint32)diff * x_factor;
				tmp1 =  (sint32)(((uint32)*tmp_ptr + (tmp_product /(uint32)65536)) + ((( tmp_product % (uint32)65536) * 2U) /(uint32)65536));
			}
			else
			{
				tmp_product = (uint32)(-diff)* x_factor;
				tmp1 =  (sint32)(((uint32)*tmp_ptr - (tmp_product / (uint32)65536)) - ((( tmp_product % (uint32)65536) * 2U) / (uint32)65536));
			}
			/*~E*/
		}
	}
	else
	{
		if  (y_factor != 0U)
		{
			/*~A*/
			/*~+:If line factor is zerobut column factor is non-zero then interpolate between columns*/
			/* if line factor is zero but column factor is non-zero, then calculate only column  interpolation */
			diff = (sint32)(tmp_ptr[1] - tmp_ptr[0] );
			if (diff >= 0)
			{
				tmp_product = (uint32)diff * y_factor;
				tmp1 = (sint32)(((uint32)*tmp_ptr + (tmp_product / (uint32)65536)) +( (( tmp_product % (uint32)65536) * 2U) / (uint32)65536));
			}
			else
			{
				tmp_product = (uint32)     (-diff) * y_factor;
				tmp1 =  (sint32)(((uint32)*tmp_ptr - (tmp_product / (uint32)65536)) - ((( tmp_product % (uint32)65536) * 2U) / (uint32)65536));
			}
			/*~E*/
		}
		else
		{
			/*~A*/
			/*~+:If line factor and column factor are zero return the value pointed by the line index and column index*/
			/* if line factor and column factor are zero return the value pointed by the line index and column index */
			tmp1 = (sint32)*tmp_ptr;
			/*~E*/
		}
	}
	return (uint16)tmp1;

	/* ## Operation body end [e6dc574d-eca9-492a-b1a3-78ec53a29d8e] */
}

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

uint16 func_u16_ip_rel_ptr_u8_u16_idyp(const uint16 * ptr_map, const uint8 * xdp_ptr, const uint16 * ydp_ptr, uint8 xval, uint16 yval, uint8 * idyp)
{
	/* ## Operation body start [9c6858e7-2859-4588-bf1b-536847e2b087] */
	const uint8 *xtmp_ptr;                   /* pointer to x-data point array */
	const uint16 *tmp_ptr;                   /* pointer to y-data point array */
	uint32   x_factor, y_factor;             /* variables to store line and column factors */
	uint32   x_index, index, num_col;        /* variable to store index and number of columns */
	uint32   tmp_product;                    /* temporary variable to store intermediate results */
	sint32   tmp1, tmp2, diff;               /* variables to store intermediate results */
	uint16 temp1_u16;
	uint8 temp1_u8;
	/* pointer to point to last element of x-data point array */
	xtmp_ptr = xdp_ptr + *xdp_ptr;

	/*~A*/
	/*~+:Calculate the index value and line factor*/
	/* compare input point value with highest x-data point array */
	if (xval >= *xtmp_ptr)
	{
		/*set line factor to zero */
		temp1_u8 = (*xdp_ptr - 1U);
		x_index = temp1_u8;
		x_factor = 0;

	}
	else
	{
		/*compare input point value with lowest data point array
        value */
		if (xval <= *(xdp_ptr + 1U))
		{
			/*set line factor to zero */
			x_factor = 0;
			x_index = 0;

		}
		else
		{
			/* search input point value in the x-data point array from top to bottom */
			do
			{
				--xtmp_ptr;
				x_factor = *xtmp_ptr;
			}
			while ( x_factor > (uint32)xval);
			/* line index calculation*/
			x_index = ((uint32)xtmp_ptr - (uint32) xdp_ptr) - 1U;
			/* line factor calculation */
			temp1_u8 = *(xtmp_ptr + 1U);
			x_factor = (((uint32)xval - x_factor) * (uint32)65536) / (uint32)(temp1_u8 - x_factor);
		}
	}

	/*~E*/
	index = *idyp;

	/* compare if relative index value exceeds no. of data values in data point array*/
	num_col = *ydp_ptr;
	if (index >= num_col )
	{
		/* set relative index value to index of last element of y-data point array */
		index = num_col - 1U;
	}
	/* pointer to point to the the data point value pointed by relative pointer */
	tmp_ptr = ydp_ptr + (index + 1U);
	/* compare input point value with data point array value pointed by relative pointer */
	if (yval >= *tmp_ptr)
	{
		/*~A*/
		/*~+:Search data point value in upper portion of the data point array*/
		/* compare input point value with highest data point array value */
		if (yval >= ydp_ptr[num_col])
		{
			/* set index to last value in data point  array */
			index = (uint32)(num_col - 1U);
			/* set line factor to zero */
			y_factor = 0;
		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to top*/
			do
			{
				++tmp_ptr;
				y_factor = *tmp_ptr;
			}
			while (y_factor<= (uint32)yval);
			/* column index value calculation*/
			index = (((uint32)tmp_ptr - (uint32) ydp_ptr)/2U) - 2U;
			/* column factor calculation */
			temp1_u16 = *(tmp_ptr - 1U);
			y_factor = (((uint32)yval - temp1_u16) * (uint32)65536) / (uint32)(y_factor - temp1_u16);
		}
		/*~E*/
	}
	else
	{
		/*~A*/
		/*~+:Search data point value in lower portion of the data point array*/
		/* compare input point value with lowest data point array value */
		if (yval <= ydp_ptr[1])
		{
			/* set index to first value in data point  array */
			index = 0;
			/* set line factor to zero */
			y_factor = 0;
		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to bottom */
			do
			{
				--tmp_ptr;
				y_factor = *tmp_ptr;
			}
			while ( y_factor > (uint32)yval);
			/* column index value calculation*/
			index = (((uint32)tmp_ptr - (uint32) ydp_ptr)/2U) - 1U;
			/* column factor calculation */
			temp1_u16 = *(tmp_ptr + 1U);
			y_factor = (((uint32)yval - y_factor) * (uint32)65536) / (uint32)(temp1_u16 - y_factor);
		}

		/*~E*/
	}
	/*set relative pointer */
	*idyp = (uint8)index;
	/* index calculation */
	x_index = x_index * num_col;
	index += x_index;
	/*temporary pointer to point to an element in interpolation data array */
	tmp_ptr = ptr_map + index;
	if (x_factor != 0U)
	{
		if  (y_factor != 0U)
		{
			/*~A*/
			/*~+:If both line and column factors are non-zero theninterpolate between both column and line*/
			/* if line factor and column factor both are non-zero, then calculate first column interpolation value */
			diff = (sint32)(tmp_ptr[1] - tmp_ptr[0] );
			if (diff >= 0)
			{
				tmp_product = (uint32)diff * y_factor;
				tmp1 = (sint32)(((uint32)*tmp_ptr + (tmp_product/(uint32)65536)) + (((tmp_product % (uint32)65536) * 2U)/(uint32)65536));
			}
			else
			{
				tmp_product = (uint32)(-diff) * y_factor;
				tmp1 = (sint32)(((uint32)*tmp_ptr - (tmp_product /(uint32)65536)) - (((tmp_product %(uint32)65536)* 2U) /(uint32)65536));
			}
			/* point the pointer to the element in next row and same column */
			tmp_ptr += num_col;
			/* calculate second column interpolation value */
			diff = (sint32)(tmp_ptr[1] - tmp_ptr[0] );
			if (diff >= 0)
			{
				tmp_product = (uint32)diff * y_factor;
				tmp2 = (sint32)(((uint32)*tmp_ptr + (tmp_product / (uint32)65536 )) + (((tmp_product % (uint32)65536) * 2U)/(uint32)65536));
			}
			else
			{
				tmp_product = (uint32)(-diff) * y_factor;
				tmp2 = (sint32)(((uint32)*tmp_ptr - (tmp_product / (uint32)65536)) - (((tmp_product % (uint32)65536) * 2U)/(uint32)65536));
			}
			/* calculate line interpolation between the fisrt and second column interpolated values */
			diff = (tmp2 - tmp1);
			if (diff >= 0)
			{
				tmp_product = (uint32)diff * x_factor;
				tmp1 =  (sint32)(((uint32)tmp1 + (tmp_product / (uint32)65536) ) + (((tmp_product % (uint32)65536) * 2U) /(uint32)65536));
			}
			else
			{
				tmp_product = (uint32)(-diff) * x_factor;
				tmp1 =  (sint32)(((uint32)tmp1 - (tmp_product / (uint32)65536)) - (((tmp_product % (uint32)65536) * 2U)/(uint32)65536));
			}
			/*~E*/
		}
		else
		{
			/*~A*/
			/*~+:If line factor is non-zerobut col_factor is zero, then interpolate between lines*/
			/* if line factor is non-zero but col_factor is zero, then calculate only line interpolation */
			diff = (sint32)(tmp_ptr[num_col] - tmp_ptr[0] );
			if (diff >= 0)
			{
				tmp_product = (uint32)diff * x_factor;
				tmp1 =  (sint32)(((uint32)*tmp_ptr + (tmp_product /(uint32)65536)) + ((( tmp_product % (uint32)65536) * 2U) /(uint32)65536));
			}
			else
			{
				tmp_product = (uint32)(-diff)* x_factor;
				tmp1 =  (sint32)(((uint32)*tmp_ptr - (tmp_product / (uint32)65536)) - ((( tmp_product % (uint32)65536) * 2U) / (uint32)65536));
			}
			/*~E*/
		}
	}
	else
	{
		if  (y_factor != 0U)
		{
			/*~A*/
			/*~+:If line factor is zerobut column factor is non-zero then interpolate between columns*/
			/* if line factor is zero but column factor is non-zero, then calculate only column  interpolation */
			diff = (sint32)(tmp_ptr[1] - tmp_ptr[0] );
			if (diff >= 0)
			{
				tmp_product = (uint32)diff * y_factor;
				tmp1 = (sint32)(((uint32)*tmp_ptr + (tmp_product / (uint32)65536)) + ((( tmp_product % (uint32)65536) * 2U) / (uint32)65536));
			}
			else
			{
				tmp_product = (uint32)     (-diff) * y_factor;
				tmp1 =  (sint32)(((uint32)*tmp_ptr -( tmp_product / (uint32)65536)) - ((( tmp_product % (uint32)65536) * 2U) / (uint32)65536));
			}
			/*~E*/
		}
		else
		{
			/*~A*/
			/*~+:If line factor and column factor are zero return the value pointed by the line index and column index*/
			/* if line factor and column factor are zero return the value pointed by the line index and column index */
			tmp1 = (sint32)(*tmp_ptr);
			/*~E*/
		}
	}
	return (uint16)tmp1;

	/* ## Operation body end [9c6858e7-2859-4588-bf1b-536847e2b087] */
}


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

uint16 func_u16_ip_rel_ptr_u16_idxp_u16(const uint16 * ptr_map, const uint16 * xdp_ptr, const uint16 * ydp_ptr, uint16 xval, uint16 yval, uint8 * idxp)
{
	/* ## Operation body start [f7a6578d-6eb3-4e8b-8b65-a3b0123a1115] */
	const uint16 *tmp_ptr;               /* pointer to data point arrays */
	uint32       x_factor, y_factor;     /* variables to store line and column factors and intermediate values */
	uint32       index, num_col;         /* variable to store index and number of columns */
	uint32       tmp_product;            /* temporary variable to store intermediate results */
	sint32       tmp1, tmp2, diff;       /* variables to store intermediate results */
	uint16 temp1_u16;
	/* assign x-relative index value to temporary variable */
	index  = *idxp;
	/* compare if relative index value exceeds no. of data values in data point array*/
	if (index >= *xdp_ptr)
	{
		/* set relative index value to index of last element of x-data point array */
		index = *xdp_ptr ;
		index--;
	}
	/* pointer to point to the the data point value pointed by relative pointer */
	tmp_ptr = xdp_ptr + (index + 1U);
	/* compare input point value with data point array value pointed by relative pointer */
	if (xval >= *tmp_ptr)
	{
		/*~A*/
		/*~+:Search data point value in upper portion of the data point array*/
		/* compare input point value with highest data point array value */
		if (xval >= xdp_ptr[*xdp_ptr])
		{
			/* set index to last value in data point  array */
			temp1_u16 = (*xdp_ptr - 1U);
			index = (uint32)temp1_u16;
			/* set line factor to zero */
			x_factor = 0;
		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to top*/
			do
			{
				++tmp_ptr;
				x_factor = *tmp_ptr;
			}
			while (x_factor <= (uint32)xval);
			/* line index value calculation*/
			index = (((uint32)tmp_ptr - (uint32) xdp_ptr)/2U) - 2U;
			/* line factor calculation */
			temp1_u16 = *(tmp_ptr - 1U);
			x_factor = (((uint32)xval - temp1_u16 ) * (uint32)65536) / (uint32)(x_factor - temp1_u16 );
		}

		/*~E*/
	}
	else
	{
		/*~A*/
		/*~+:Search data point value in lower portion of the data point array*/
		/* compare input point value with lowest data point array value */
		if (xval <= xdp_ptr[1])
		{
			/* set index to first value in data point  array */
			index = 0;
			/* set line factor to zero */
			x_factor = 0;
		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to bottom */
			do
			{
				--tmp_ptr;
				x_factor = *tmp_ptr;
			}
			while ( x_factor> (uint32)xval);
			/* line index value calculation*/
			index = (((uint32)tmp_ptr - (uint32) xdp_ptr)/2U) - 1U;
			/* line factor calculation */
			temp1_u16 = *(tmp_ptr + 1U);
			x_factor = (((uint32)xval - x_factor) * (uint32)65536) / (uint32)(temp1_u16 - x_factor);
		}

		/*~E*/
	}
	/*set relative pointer */
	*idxp = (uint8)index;
	/* pointer to point to last element of y-data point array */
	num_col = *ydp_ptr;
	tmp_ptr = ydp_ptr + num_col;
	index = (index * num_col);
	/*~A*/
	/*~+:Calculate the index value and column factor*/
	/* compare input point value with highest y-data point array */
	if (yval >= *tmp_ptr)
	{
		/*set column factor to zero */
		index = index + num_col - 1U;
		y_factor = 0;

	}
	else
	{
		/*compare input point value with lowest data point array
        value */
		if (yval <= ydp_ptr[1])
		{
			/*set column factor to zero */
			y_factor = 0;

		}
		else
		{
			/* search input point value in the y-data point array from top to bottom */
			do
			{
				--tmp_ptr;
				y_factor = *tmp_ptr;
			}
			while ( y_factor > (uint32)yval);
			/* index calculation*/
			index = index + (uint32)((((uint32)tmp_ptr - (uint32) ydp_ptr)/2U) - 1U);
			/* column factor calculation */
			temp1_u16 = *(tmp_ptr + 1U);
			y_factor = (((uint32)yval - y_factor) * (uint32)65536) / (uint32)(temp1_u16 - y_factor);
		}
	}

	/*~E*/
	/*temporary pointer to point to an element in interpolation data array */
	tmp_ptr = ptr_map + index;
	if (x_factor != 0U)
	{
		if  (y_factor != 0U)
		{
			/*~A*/
			/*~+:If both line and column factors are non-zero theninterpolate between both column and line*/
			/* if line factor and column factor both are non-zero, then calculate first column interpolation value */
			diff = (sint32)(tmp_ptr[1] - tmp_ptr[0] );
			if (diff >= 0)
			{
				tmp_product = (uint32)diff * y_factor;
				tmp1 = (sint32)(((uint32)*tmp_ptr + (tmp_product/(uint32)65536)) + (((tmp_product % (uint32)65536) * 2U)/(uint32)65536));
			}
			else
			{
				tmp_product = (uint32)(-diff) * y_factor;
				tmp1 = (sint32)(((uint32)*tmp_ptr - (tmp_product /(uint32)65536)) - (((tmp_product %(uint32)65536)* 2U) /(uint32)65536));
			}
			/* point the pointer to the element in next row and same column */
			tmp_ptr += num_col;
			/* calculate second column interpolation value */
			diff = (sint32)(tmp_ptr[1] - tmp_ptr[0] );
			if (diff >= 0)
			{
				tmp_product = (uint32)diff * y_factor;
				tmp2 = (sint32)(((uint32)*tmp_ptr + ( tmp_product / (uint32)65536)) + (((tmp_product % (uint32)65536) * 2U)/(uint32)65536));
			}
			else
			{
				tmp_product = (uint32)(-diff) * y_factor;
				tmp2 = (sint32)(((uint32)*tmp_ptr - (tmp_product / (uint32)65536)) - (((tmp_product % (uint32)65536) * 2U)/(uint32)65536));
			}
			/* calculate line interpolation between the fisrt and second column interpolated values */
			diff = (tmp2 - tmp1);
			if (diff >= 0)
			{
				tmp_product = (uint32)diff * x_factor;
				tmp1 = (sint32)(((uint32)tmp1 + (tmp_product / (uint32)65536)) + (((tmp_product % (uint32)65536) * 2U) /(uint32)65536));
			}
			else
			{
				tmp_product = (uint32)(-diff) * x_factor;
				tmp1 = (sint32)(((uint32)tmp1 -( tmp_product / (uint32)65536)) - (((tmp_product % (uint32)65536) * 2U)/(uint32)65536));
			}
			/*~E*/
		}
		else
		{
			/*~A*/
			/*~+:If line factor is non-zerobut col_factor is zero, then interpolate between lines*/
			/* if line factor is non-zero but col_factor is zero, then calculate only line interpolation */
			diff = (sint32)(tmp_ptr[num_col] - tmp_ptr[0] );
			if (diff >= 0)
			{
				tmp_product = (uint32)diff * x_factor;
				tmp1 = (sint32)(((uint32)*tmp_ptr +  ( tmp_product /(uint32)65536 ))+( (( tmp_product % (uint32)65536) * 2U) /(uint32)65536));
			}
			else
			{
				tmp_product = (uint32)(-diff)* x_factor;
				tmp1 = (sint32)(((uint32)*tmp_ptr - (tmp_product / (uint32)65536)) - ((( tmp_product % (uint32)65536) * 2U) / (uint32)65536));
			}
			/*~E*/
		}
	}
	else
	{
		if  (y_factor != 0U)
		{
			/*~A*/
			/*~+:If line factor is zerobut column factor is non-zero then interpolate between columns*/
			/* if line factor is zero but column factor is non-zero, then calculate only column  interpolation */
			diff = (sint32)(tmp_ptr[1] - tmp_ptr[0] );
			if (diff >= 0)
			{
				tmp_product = (uint32)diff * y_factor;
				tmp1 = (sint32)(((uint32)*tmp_ptr + (tmp_product / (uint32)65536)) + ((( tmp_product % (uint32)65536) * 2U) / (uint32)65536));
			}
			else
			{
				tmp_product = (uint32)     (-diff) * y_factor;
				tmp1 = (sint32)(((uint32)*tmp_ptr - (tmp_product / (uint32)65536)) - ((( tmp_product % (uint32)65536) * 2U) / (uint32)65536));
			}
			/*~E*/
		}
		else
		{
			/*~A*/
			/*~+:If line factor and column factor are zero return the value pointed by the line index and column index*/
			/* if line factor and column factor are zero return the value pointed by the line index and column index */
			tmp1 = (sint32)(*tmp_ptr);
			/*~E*/
		}
	}
	return (uint16)tmp1;


	/* ## Operation body end [f7a6578d-6eb3-4e8b-8b65-a3b0123a1115] */
}

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

uint16 func_u16_ip_rel_ptr_u16_u16_idyp(const uint16 * ptr_map, const uint16 * xdp_ptr, const uint16 * ydp_ptr, uint16 xval, uint16 yval, uint8 * idyp)
{
	/* ## Operation body start [40ffc2d6-b3bd-4125-9975-4107b673941d] */
	const uint16 *tmp_ptr;                   /* pointer to data point arrays */
	uint32       x_factor, y_factor;         /* variables to store line and column factors */
	uint32       x_index, index, num_col;    /* variable to store index and number of columns */
	uint32       tmp_product;                /* temporary variable to store intermediate results */
	sint32       tmp1, tmp2, diff;           /* variables to store intermediate results */
	uint16 temp1_u16;
	/* pointer to point to last element of x-data point array */
	tmp_ptr = xdp_ptr + *xdp_ptr;

	/*~A*/
	/*~+:Calculate the index value and line factor*/
	/* compare input point value with highest x-data point array */
	if (xval >= *tmp_ptr)
	{
		/*set line factor to zero */
		temp1_u16 = (*xdp_ptr - 1U) ;
		x_index = (uint32)temp1_u16;
		x_factor = 0;

	}
	else
	{
		/*compare input point value with lowest data point array
        value */
		if (xval <= *(xdp_ptr + 1U))
		{
			/*set line factor to zero */
			x_factor = 0;
			x_index = 0;

		}
		else
		{
			/* search input point value in the x-data point array from top to bottom */
			do
			{
				--tmp_ptr;
				x_factor = *tmp_ptr;
			}
			while (x_factor > (uint32)xval);
			/* line index calculation*/
			x_index = (((uint32)tmp_ptr - (uint32) xdp_ptr)/2U) - 1U;
			/* line factor calculation */
			temp1_u16 = *(tmp_ptr + 1U);
			x_factor = (((uint32)xval - x_factor) * (uint32)65536) / (uint32)(temp1_u16 - x_factor);
		}
	}

	/*~E*/
	index = *idyp;

	/* compare if relative index value exceeds no. of data values in data point array*/
	num_col = *ydp_ptr;
	if (index >= num_col)
	{
		/* set relative index value to index of last element of y-data point array */
		index = num_col - 1U;
	}
	/* pointer to point to the the data point value pointed by relative pointer */
	tmp_ptr = ydp_ptr + (index + 1U);
	/* compare input point value with data point array value pointed by relative pointer */
	if (yval >= *tmp_ptr)
	{
		/*~A*/
		/*~+:Search data point value in upper portion of the data point array*/
		/* compare input point value with highest data point array value */
		if (yval >= ydp_ptr[num_col])
		{
			/* set index to last value in data point  array */
			index = (uint32)(num_col - 1U);
			/* set line factor to zero */
			y_factor = 0;
		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to top*/
			do
			{
				++tmp_ptr;
				y_factor = *tmp_ptr;
			}
			while (y_factor <= (uint32)yval);
			/* column index value calculation*/
			index = (((uint32)tmp_ptr - (uint32) ydp_ptr)/2U) - 2U;
			/* column factor calculation */
			temp1_u16 = *(tmp_ptr - 1U);
			y_factor = (((uint32)yval - temp1_u16) * (uint32)65536) / (uint32)(y_factor - temp1_u16);
		}
		/*~E*/
	}
	else
	{
		/*~A*/
		/*~+:Search data point value in lower portion of the data point array*/
		/* compare input point value with lowest data point array value */
		if (yval <= ydp_ptr[1])
		{
			/* set index to first value in data point  array */
			index = 0;
			/* set line factor to zero */
			y_factor = 0;
		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to bottom */
			do
			{
				--tmp_ptr;
				y_factor = *tmp_ptr;
			}
			while (y_factor> (uint32)yval);
			/* column index value calculation*/
			index = (((uint32)tmp_ptr - (uint32) ydp_ptr)/2U) - 1U;
			/* column factor calculation */
			temp1_u16 = *(tmp_ptr + 1U);
			y_factor = (((uint32)yval - y_factor) * (uint32)65536) / (uint32)(temp1_u16 - y_factor);
		}

		/*~E*/
	}
	/* set relative pointer */
	*idyp = (uint8)index;
	/* index calculation */
	x_index = x_index * num_col;
	index += x_index;
	/* temporary pointer to point to an element in interpolation data array */
	tmp_ptr = ptr_map + index;
	if (x_factor != 0U)
	{
		if  (y_factor != 0U )
		{
			/*~A*/
			/*~+:If both line and column factors are non-zero theninterpolate between both column and line*/
			/* if line factor and column factor both are non-zero, then calculate first column interpolation value */
			diff = (sint32)(tmp_ptr[1] - tmp_ptr[0] );
			if (diff >= 0)
			{
				tmp_product = (uint32)diff * y_factor;
				tmp1 = (sint32)(((uint32)*tmp_ptr + ( tmp_product/(uint32)65536)) + (((tmp_product % (uint32)65536) * 2U)/(uint32)65536));
			}
			else
			{
				tmp_product = (uint32)(-diff) * y_factor;
				tmp1 = (sint32)(((uint32)*tmp_ptr - (tmp_product /(uint32)65536)) - (((tmp_product %(uint32)65536)* 2U) /(uint32)65536));
			}
			/* point the pointer to the element in next row and same column */
			tmp_ptr += num_col;
			/* calculate second column interpolation value */
			diff = (sint32)(tmp_ptr[1] - tmp_ptr[0] );
			if (diff >= 0)
			{
				tmp_product = (uint32)diff * y_factor;
				tmp2 = (sint32)(((uint32)*tmp_ptr + ( tmp_product / (uint32)65536)) + (((tmp_product % (uint32)65536) * 2U)/(uint32)65536));
			}
			else
			{
				tmp_product = (uint32)(-diff) * y_factor;
				tmp2 = (sint32)(((uint32)*tmp_ptr -( tmp_product / (uint32)65536)) - (((tmp_product % (uint32)65536) * 2U)/(uint32)65536));
			}
			/* calculate line interpolation between the fisrt and second column interpolated values */
			diff = (tmp2 - tmp1);
			if (diff >= 0)
			{
				tmp_product = (uint32)diff * x_factor;
				tmp1 = (sint32)(((uint32)tmp1 + (tmp_product / (uint32)65536)) + (((tmp_product % (uint32)65536) * 2U) /(uint32)65536));
			}
			else
			{
				tmp_product = (uint32)(-diff) * x_factor;
				tmp1 = (sint32)(((uint32)tmp1 -( tmp_product / (uint32)65536 )) - (((tmp_product % (uint32)65536) * 2U)/(uint32)65536));
			}
			/*~E*/
		}
		else
		{
			/*~A*/
			/*~+:If line factor is non-zerobut col_factor is zero, then interpolate between lines*/
			/* if line factor is non-zero but col_factor is zero, then calculate only line interpolation */
			diff = (sint32)(tmp_ptr[num_col] - tmp_ptr[0] );
			if (diff >= 0)
			{
				tmp_product = (uint32)diff * x_factor;
				tmp1 = (sint32)(((uint32)*tmp_ptr + (tmp_product /(uint32)65536)) + ((( tmp_product % (uint32)65536) * 2U) /(uint32)65536));
			}
			else
			{
				tmp_product = (uint32)(-diff)* x_factor;
				tmp1 = (sint32)(((uint32)*tmp_ptr - (tmp_product / (uint32)65536)) - ((( tmp_product % (uint32)65536) * 2U) / (uint32)65536));
			}
			/*~E*/
		}
	}
	else
	{
		if  (y_factor != 0U )
		{
			/*~A*/
			/*~+:If line factor is zerobut column factor is non-zero then interpolate between columns*/
			/* if line factor is zero but column factor is non-zero, then calculate only column  interpolation */
			diff = (sint32)(tmp_ptr[1] - tmp_ptr[0] );
			if (diff >= 0)
			{
				tmp_product = (uint32)diff * y_factor;
				tmp1 = (sint32)(((uint32)*tmp_ptr +  ( tmp_product / (uint32)65536)) + ((( tmp_product % (uint32)65536) * 2U) / (uint32)65536));
			}
			else
			{
				tmp_product = (uint32)     (-diff) * y_factor;
				tmp1 = (sint32)(((uint32)*tmp_ptr -( tmp_product / (uint32)65536 )) - ((( tmp_product % (uint32)65536) * 2U) / (uint32)65536));
			}
			/*~E*/
		}
		else
		{
			/*~A*/
			/*~+:If line factor and column factor are zero return the value pointed by the line index and column index*/
			/* if line factor and column factor are zero return the value pointed by the line index and column index */
			tmp1 = (sint32)(*tmp_ptr);
			/*~E*/
		}
	}
	return (uint16)tmp1;

	/* ## Operation body end [40ffc2d6-b3bd-4125-9975-4107b673941d] */
}

/** This operation performs combined data point search and table value determination for 1D calibration curve of type uint8 and data point array of type uint8

@param ptr_map :Pointer to 1D calibration curve
@param dp_ptr :pointer to data point array
@param xval :Data point value to be searched
@return :Table value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint8 function_u8_id_ptr_u8(const uint8 * ptr_map, const uint8 * dp_ptr, uint8 xval)
{
	/* ## Operation body start [74362c2e-d6aa-495b-84b6-6b7d180f81ec] */
	DPS_RESULT x_dps;
	UIDS_U8(dp_ptr, xval, &x_dps);
	return U8_ID1D_U8(ptr_map, &x_dps);

	/* ## Operation body end [74362c2e-d6aa-495b-84b6-6b7d180f81ec] */
}

/** This operation performs combined data point search and table value determination for 1D calibration curve of type uint8 and data point array of type uint16

@param ptr_map :Pointer to 1D calibration curve
@param dp_ptr :pointer to data point array
@param xval :Data point value to be searched
@return :Table value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint8 function_u8_id_ptr_u16(const uint8 * ptr_map, const uint16 * dp_ptr, uint16 xval)
{
	/* ## Operation body start [7da31528-00a6-482b-a9ca-e799eb0a1ddb] */
	DPS_RESULT x_dps;
	UIDS_U16(dp_ptr, xval, &x_dps);
	return U8_ID1D_U8(ptr_map, &x_dps);

	/* ## Operation body end [7da31528-00a6-482b-a9ca-e799eb0a1ddb] */
}

/** This operation performs combined data point search and table value determination for 1D calibration curve of type uint16 and data point array of type uint8

@param ptr_map :Pointer to 1D calibration curve
@param dp_ptr :pointer to data point array
@param xval :Data point value to be searched
@return :Table value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint16 function_u16_id_ptr_u8(const uint16 * ptr_map, const uint8 * dp_ptr, uint8 xval)
{
	/* ## Operation body start [5437500c-ce0e-4824-aaac-af7dfa61b445] */
	DPS_RESULT x_dps;
	UIDS_U8(dp_ptr, xval, &x_dps);
	return U16_ID1D_U16(ptr_map, &x_dps);

	/* ## Operation body end [5437500c-ce0e-4824-aaac-af7dfa61b445] */
}

/** This operation performs combined data point search and table value determination for 1D calibration curve of type uint16 and data point array of type uint16

@param ptr_map :Pointer to 1D calibration curve
@param dp_ptr :pointer to data point array
@param xval :Data point value to be searched
@return :Table value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint16 function_u16_id_ptr_u16(const uint16 * ptr_map, const uint16 * dp_ptr, uint16 xval)
{
	/* ## Operation body start [10f72d7d-fb6d-42c4-af0f-5bfd6682d415] */
	DPS_RESULT x_dps;
	UIDS_U16(dp_ptr, xval, &x_dps);
	return U16_ID1D_U16(ptr_map, &x_dps);

	/* ## Operation body end [10f72d7d-fb6d-42c4-af0f-5bfd6682d415] */
}

/** This operation performs combined data point search and table value determination for 2D calibration map of type uint8 with X data point array of type uint8 and Y data point array of type uint8

@param ptr_map :Pointer to 2D Calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@return :Table value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint8 function_u8_id_ptr_u8_u8(const uint8 * ptr_map, const uint8 * xdp_ptr, const uint8 * ydp_ptr, uint8 xval, uint8 yval)
{
	/* ## Operation body start [718aa1ea-106a-4178-8ad5-179afb872b6a] */
	DPS_RESULT x_dps, y_dps;
	UIDS_U8(xdp_ptr, xval, &x_dps);
	UIDS_U8(ydp_ptr, yval, &y_dps);
	return U8_ID2D_U8(ptr_map, &x_dps, &y_dps);

	/* ## Operation body end [718aa1ea-106a-4178-8ad5-179afb872b6a] */
}

/** This operation performs combined data point search and table value determination for 2D calibration map of type uint8 with X data point array of type uint8 and Y data point array of type uint16

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@return :Table value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint8 function_u8_id_ptr_u8_u16(const uint8 * ptr_map, const uint8 * xdp_ptr, const uint16 * ydp_ptr, uint8 xval, uint16 yval)
{
	/* ## Operation body start [9955d10c-7bdd-4be9-a420-e4e2a6cd9a4c] */
	DPS_RESULT x_dps, y_dps;
	UIDS_U8(xdp_ptr, xval, &x_dps);
	UIDS_U16(ydp_ptr, yval, &y_dps);
	return U8_ID2D_U8(ptr_map, &x_dps, &y_dps);

	/* ## Operation body end [9955d10c-7bdd-4be9-a420-e4e2a6cd9a4c] */
}

/** This operation performs combined data point search and table value determination for 2D calibration map of type uint8 with X data point array of type uint16 and Y data point array of type uint8

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@return :Table value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint8 function_u8_id_ptr_u16_u8(const uint8 * ptr_map, const uint16 * xdp_ptr, const uint8 * ydp_ptr, uint16 xval, uint8 yval)
{
	/* ## Operation body start [2f6a749d-b3aa-435f-a07f-ba138c488436] */
	DPS_RESULT x_dps, y_dps;
	UIDS_U16(xdp_ptr, xval, &x_dps);
	UIDS_U8(ydp_ptr, yval, &y_dps);
	return U8_ID2D_U8(ptr_map, &x_dps, &y_dps);

	/* ## Operation body end [2f6a749d-b3aa-435f-a07f-ba138c488436] */
}

/** This operation performs combined data point search and table value determination for 2D calibration map of type uint8 with X data point array of type uint16 and Y data point array of type uint16

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@return :Table value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint8 function_u8_id_ptr_u16_u16(const uint8 * ptr_map, const uint16 * xdp_ptr, const uint16 * ydp_ptr, uint16 xval, uint16 yval)
{
	/* ## Operation body start [710edcfc-0021-4399-8f0c-6766c85e0500] */
	DPS_RESULT x_dps, y_dps;
	UIDS_U16(xdp_ptr, xval, &x_dps);
	UIDS_U16(ydp_ptr, yval, &y_dps);
	return U8_ID2D_U8(ptr_map, &x_dps, &y_dps);

	/* ## Operation body end [710edcfc-0021-4399-8f0c-6766c85e0500] */
}

/** This operation performs combined data point search and table value determination for 2D calibration map of type uint16 with X data point array of type uint8 and Y data point array of type uint8

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@return :Table value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint16 function_u16_id_ptr_u8_u8(const uint16 * ptr_map, const uint8 * xdp_ptr, const uint8 * ydp_ptr, uint8 xval, uint8 yval)
{
	/* ## Operation body start [17173dcd-9902-4ff5-983a-772126975753] */
	DPS_RESULT x_dps, y_dps;
	UIDS_U8(xdp_ptr, xval, &x_dps);
	UIDS_U8(ydp_ptr, yval, &y_dps);
	return U16_ID2D_U16(ptr_map, &x_dps, &y_dps);

	/* ## Operation body end [17173dcd-9902-4ff5-983a-772126975753] */
}

/** This operation performs combined data point search and table value determination for 2D calibration map of type uint16 with X data point array of type uint8 and Y data point array of type uint16

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@return :Table value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint16 function_u16_id_ptr_u8_u16(const uint16 * ptr_map, const uint8 * xdp_ptr, const uint16 * ydp_ptr, uint8 xval, uint16 yval)
{
	/* ## Operation body start [91697f4f-8d51-4d82-9c7d-81c037b76b82] */
	DPS_RESULT x_dps, y_dps;
	UIDS_U8(xdp_ptr, xval, &x_dps);
	UIDS_U16(ydp_ptr, yval, &y_dps);
	return U16_ID2D_U16(ptr_map, &x_dps, &y_dps);

	/* ## Operation body end [91697f4f-8d51-4d82-9c7d-81c037b76b82] */
}

/** This operation performs combined data point search and table value determination for 2D calibration map of type uint16 with X data point array of type uint16 and Y data point array of type uint8

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@return :Table value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint16 function_u16_id_ptr_u16_u8(const uint16 * ptr_map, const uint16 * xdp_ptr, const uint8 * ydp_ptr, uint16 xval, uint8 yval)
{
	/* ## Operation body start [8e8f7140-f9da-48e9-be0c-9a17ad41e3ca] */
	DPS_RESULT x_dps, y_dps;
	UIDS_U16(xdp_ptr, xval, &x_dps);
	UIDS_U8(ydp_ptr, yval, &y_dps);
	return U16_ID2D_U16(ptr_map, &x_dps, &y_dps);

	/* ## Operation body end [8e8f7140-f9da-48e9-be0c-9a17ad41e3ca] */
}

/** This operation performs combined data point search and table value determination for 2D calibration map of type uint16 with X data point array of type uint16 and Y data point array of type uint16

@param ptr_map :Pointer to 2D calibration map
@param xdp_ptr :pointer to X data point array
@param ydp_ptr :pointer to Y data point array
@param xval :X Data point value to be searched
@param yval :Y Data point value to be searched
@return :Table value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint16 function_u16_id_ptr_u16_u16(const uint16 * ptr_map, const uint16 * xdp_ptr, const uint16 * ydp_ptr, uint16 xval, uint16 yval)
{
	/* ## Operation body start [d884398e-db0a-45af-a718-de338f248ab4] */
	DPS_RESULT x_dps, y_dps;
	UIDS_U16(xdp_ptr, xval, &x_dps);
	UIDS_U16(ydp_ptr, yval, &y_dps);
	return U16_ID2D_U16(ptr_map, &x_dps, &y_dps);

	/* ## Operation body end [d884398e-db0a-45af-a718-de338f248ab4] */
}

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

uint8 function_u8_y_inv_ip_ptr_u8_u8(const uint8 * x_ptr, const uint8 * y_ptr, const uint8 * z_ptr, uint8 x_val, uint8 z_val, uint8 * x1, uint8 * y1)
{
	/* ## Operation body start [5498a189-db56-41c7-a342-c345cdf45ef1] */
	uint8 y2, max, z_n_y1, z_n_y2;      /* Temporary variables to store intermediate result */
	uint8 y_actual, z2 = 0;                     /* Variable to store the return value */
	uint8 xrel_idx, yrel_idx,increase;           /* Variables to store the relative indices */
	const uint8 *xtmp_ptr, *x1_ptr;     /* Pointer variables to point to x data point array */
	const uint8 *z1_ptr, *z2_ptr;       /* Pointer variables to point to interpolation map values */
	uint32 fac, fac1, fac2;             /* Temporary variables to store intermediate results */
	sint32 temp,denominator;
	uint8 temp1_u8,temp1_u8_1,tmp_xval,tmp_Zval;
	const uint8 *tmp_U32,*tmp_U32_1;
	tmp_Zval = z_val;
	tmp_xval = x_val;
	/* Assign input x & y relative indices to temporary variables */
	xrel_idx = *x1;
	yrel_idx = *y1;

	/* Pointer to point to last element of x data point array */
	xtmp_ptr = x_ptr + *x_ptr;

	/* pointer to point to the the data point value pointed by relative pointer */
	x1_ptr = x_ptr + (xrel_idx + 1U);
	/* Check whether the x input value is greater than the element pointed by relative index */
	if (tmp_xval >= *(x1_ptr))
	{
		/*~A*/
		/*~+:Find the x relative index in the upper part from the relative point of the data point array*/
		/*~+:*/
		/* Check whether the x input value is greater than the last element of the x data point array */
		if (tmp_xval >= *xtmp_ptr)
		{
			/* set x actual value to last value in data point array */
			tmp_xval=*xtmp_ptr;

			/* set relative pointer to last but one index in data point  array */
			xrel_idx = *x_ptr;
			xrel_idx = xrel_idx - 2U ;
			/* Relative pointer pointing to element next to relative index */
			x1_ptr = xtmp_ptr;
			z2 = 1;

		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to top*/
			++x1_ptr;
			while (tmp_xval>= (*x1_ptr))
			{
				++x1_ptr;
			}
			/* realtive pointer index calculation*/
			xrel_idx=(uint8)(((uint32)x1_ptr-(uint32)x_ptr)-2U);

		}
		/*~E*/
	}
	else
	{
		/*~A*/
		/*~+:Find the x relative index in the lower part from the relative point of the data point array*/
		/*~+:*/
		/* Check whether the x input value is less than the first element of the x data point array */
		if (tmp_xval <= *(x_ptr+1U))
		{
			/* set x actual value to first value in data point array */
			tmp_xval= *(x_ptr+1U);

			/* set relative index to first index in data point array */
			xrel_idx = 0;

			/* Relative pointer pointing to second element of x data point array */
			x1_ptr = x_ptr + 2U;

		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to bottom */
			--x1_ptr;
			while (tmp_xval < (*x1_ptr))
			{
				--x1_ptr;
			}
			/* realtive index calculation*/
			xrel_idx=(uint8)(((uint32)x1_ptr-(uint32)x_ptr)-1U);

			/* Point the relative index pointer to the element next to relative index element */
			++x1_ptr;

		}
		/*~E*/
	}
	/* Store the relative index value */
	*x1 = xrel_idx;
	temp1_u8 = *(x1_ptr-1U);
	fac1 = (uint32)tmp_xval - (uint32)temp1_u8;
	temp1_u8 = *(x1_ptr);
	fac2 = (uint32)temp1_u8 - (uint32)tmp_xval;

	/* Find the interpolation factors */
	if (*(x1_ptr) > *(x1_ptr - 1U))
	{
		temp1_u8 = (*x1_ptr - *(x1_ptr - 1U));
		fac1 = ((uint32)fac1<<16U) / (uint32)temp1_u8;
		fac2 = ((uint32)fac2<<16U) / (uint32)temp1_u8;

	}
	else
	{
		fac1 = 65536;
		fac2 = 0;

	}
	/* Pointer to point to the element in the interpolation map */
	z1_ptr = z_ptr + (xrel_idx * (*y_ptr));
	z2_ptr = z1_ptr + *y_ptr;

	if (z2 != 0U) /*z2=1 when it is in last row i.e. when passed x_val value is greater or equal to the last element of the input x_array */
	{
		if (*z2_ptr < *(z2_ptr +(*y_ptr)- 1U))
			/* comparing the last row first element with last row last element */
		{
			increase=1U;
		}
		else
		{
			increase=0U;
		}
	}
	else
	{
		/* Check whether the interpolation map is increasing globally */
		if (*z1_ptr < (*(z2_ptr - 1U)))
		{
			increase=1U;
		}
		else
		{
			increase=0;
		}
	}
	if (increase == 1U)
	{
		/*~A*/
		/*~+:Interpolate the z_val value for a globally increasing interpolation map*/
		/*~+:*/
		/* If the map is increasing globally interpolate the map values */
		temp1_u8 = *(z2_ptr+yrel_idx);
		temp1_u8_1 = *(z1_ptr+yrel_idx);
		fac = (fac1 * (uint32)temp1_u8) + (fac2* (uint32)temp1_u8_1);
		z_n_y1 =(uint8)(( (fac / (uint32)65536)) +(((uint32)2*(fac % (uint32)65536)) / (uint32)65536));
		y2 = yrel_idx;
		z_n_y2 = z_n_y1;

		/*Interpolate the z value between 2 rows of the ipmap*/
		while ((tmp_Zval < z_n_y1) && (yrel_idx >= 1U))
		{
			y2 = yrel_idx;
			z_n_y2 = z_n_y1;
			yrel_idx = yrel_idx - 1U;
			temp1_u8 = *(z2_ptr+yrel_idx);
			temp1_u8_1 = *(z1_ptr+yrel_idx);
			fac = (fac1*(uint32)temp1_u8) + (fac2 * (uint32)temp1_u8_1);
			z_n_y1 =(uint8)((fac / (uint32)65536) +(((uint32)2*(fac % (uint32)65536)) / (uint32)65536));

		}
		/*Interpolate the z value between 2 rows of the ipmap*/
		while ((tmp_Zval >= z_n_y2) && (y2 < (*y_ptr - 1U)))
		{
			yrel_idx = y2;
			z_n_y1 = z_n_y2;
			y2 = y2 + 1U;
			temp1_u8 = *(z2_ptr+y2);
			temp1_u8_1 = *(z1_ptr+y2);
			fac = (fac1 * (uint32) temp1_u8) + (fac2 * (uint32)temp1_u8_1);
			z_n_y2 =(uint8)((fac / (uint32)65536) +(((uint32)2*(fac % (uint32)65536)) / (uint32)65536));

		}
		/* Check whether z_val lies between z_n_y1 & z_n_y2 otherwise fix it in between z_n_y1 & z_n_y2 */
		if (tmp_Zval > z_n_y1)
		{
			max = tmp_Zval;
		}
		else
		{
			max = z_n_y1;
		}
		if (max < z_n_y2)
		{
			tmp_Zval = max;
		}
		else
		{
			tmp_Zval = z_n_y2;
		}
		/*~E*/
	}
	else
	{
		/*~A*/
		/*~+:Interpolate the z_val value for a globally decresing interpolation map*/
		/*~+:*/
		/* If the map is globally decreasing interpolate map values */
		temp1_u8 = (*(z2_ptr+yrel_idx));
		temp1_u8_1 = (*(z1_ptr+yrel_idx));
		fac = (fac1 * (uint32)temp1_u8) + (fac2* (uint32)temp1_u8_1);
		z_n_y1 =(uint8)((fac / (uint32)65536) +(((uint32)2*(fac % (uint32)65536)) / (uint32)65536));
		y2 = yrel_idx;
		z_n_y2 = z_n_y1;

		/*Interpolate the z value between 2 rows of the ipmap*/
		while ((tmp_Zval <z_n_y2 ) && (y2 < (*y_ptr - 1U)))
		{
			yrel_idx = y2;
			z_n_y1 = z_n_y2;
			y2 = y2 + 1U;
			temp1_u8 = (*(z2_ptr+y2));
			temp1_u8_1 = (*(z1_ptr+y2));
			fac = (fac1 * (uint32)temp1_u8) + (fac2 * (uint32)temp1_u8_1);
			z_n_y2 =(uint8)( (fac /(uint32)65536) + (((uint32)2*(fac % (uint32)65536)) / (uint32)65536));

		}
		/*Interpolate the z value between 2 rows of the ipmap*/
		while ((tmp_Zval >= z_n_y1) && (yrel_idx >= 1U))
		{
			y2 = yrel_idx;
			z_n_y2 = z_n_y1;
			yrel_idx = yrel_idx - 1U;
			temp1_u8 = (*(z2_ptr+yrel_idx));
			temp1_u8_1 = (*(z1_ptr+yrel_idx));
			fac = (fac1 * (uint32)temp1_u8) + (fac2 * (uint32)temp1_u8_1);
			z_n_y1 =(uint8)((fac / (uint32)65536)+ (((uint32)2 * (fac % (uint32)65536)) / (uint32)65536));

		}
		/* Check whether tmp_Zval lies between z_n_y2 & z_n_y1 otherwise fix it in between z_n_y2 & z_n_y1 */
		if (tmp_Zval > z_n_y2)
		{
			max = tmp_Zval;
		}
		else
		{
			max = z_n_y2;
		}
		if (max < z_n_y1)
		{
			tmp_Zval = max;
		}
		else
		{
			tmp_Zval = z_n_y1;
		}
		/*~E*/
	}
	/* Store the y relative index in pointer */
	*y1 = yrel_idx;

	/* Find the y actual value from y data point array */
	if ((z_n_y1 < z_n_y2) || (z_n_y1 > z_n_y2))
	{
		/*interpolate between z_n_y1 and z_n_y2 */
		tmp_U32 = (y_ptr+y2)+1U;
		tmp_U32_1 = (y_ptr+yrel_idx)+1U;
		temp = (sint32)((tmp_Zval - z_n_y1) * (*tmp_U32)) + (sint32)((z_n_y2 - tmp_Zval) * (*tmp_U32_1));
		denominator = (sint32)(z_n_y2 - z_n_y1);
		y_actual = (uint8)(( (temp / denominator) )+ ((2 * (temp % denominator)) / denominator ));

	}
	else
	{
		y_actual = (uint8)(*(y_ptr+yrel_idx+1));
	}
	/* Return the value of y data point array */
	return y_actual;


	/* ## Operation body end [5498a189-db56-41c7-a342-c345cdf45ef1] */
}

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

uint8 function_u8_x_inv_ip_ptr_u8_u8(const uint8 * x_ptr, const uint8 * y_ptr, const uint8 * z_ptr, uint8 y_val, uint8 z_val, uint8 * x1, uint8 * y1)
{
	/* ## Operation body start [95481a0f-8f17-489c-8d7a-47e152d1262c] */
	const uint8    *ytmp_ptr, *y1_ptr;     /* pointer variables to point to y data point array */
	const uint8    *z1_ptr, *z2_ptr;       /* pointer variables to point to interpolation map */
	uint8          tmp_x, max,increase;             /* temporary variables to store intermediate results */
	uint8          xrel_idx, yrel_idx, z2=0;      /* variables to store relative indices */
	uint8          z_n_x1, z_n_x2;         /* temporary variables to store intermediate results */
	uint32         fac, fac1, fac2;        /* temporary variables to store intermediate results */
	sint32         temp;                   /* temporary variables to store intermediate results */
	uint8 tmp_y_val,temp1_u8,temp1_u8_1;
	uint8 tmp_z_val;
	const uint8 *tmp_U32,*tmp_U32_1;
	tmp_z_val = z_val;
	tmp_y_val = y_val;
	/* store x & y relative indices to temporary variables */
	xrel_idx = *x1;
	yrel_idx = *y1;
	/* pointer to point to last element of y data point array */
	ytmp_ptr = y_ptr + *y_ptr;

	/* pointer to point to the data point value pointed by relative pointer */
	y1_ptr = y_ptr + (yrel_idx + 1U);

	/* if y_val is greater than the value pointed by relative index */
	if (tmp_y_val >= *(y1_ptr))
	{
		/*~A*/
		/*~+:find y relative index in upper part from the point where relative pointer is pointing*/
		/* check if y_val is greater than the last element of the Y data point array */
		if (tmp_y_val >= *ytmp_ptr)
		{
			/* set tmp_y_val to last element in Y data point array*/
			tmp_y_val = *ytmp_ptr;
			/* set relative pointer to last but one index in Y data point array */
			yrel_idx = *y_ptr - 2U;
			/* relative pointer pointing to element next to relative index */
			y1_ptr = ytmp_ptr;
			z2 = 1;

		}
		else
		{
			/* search for tmp_y_val in the data point array from the point where relative pointer is pointing to top */
			do
			{
				++y1_ptr;
			}
			while (tmp_y_val >= (*y1_ptr));
			/* relative pointer calculation */
			yrel_idx = (uint8)(((uint32)y1_ptr - (uint32)y_ptr) - ((uint8)2));
		}
		/*~E*/
	}
	else
	{
		/*~A*/
		/*~+:find y relative index in lower part from the point where relative pointer is pointing*/
		/* check if tmp_y_val is less than the first element of the Y data point array */
		if (tmp_y_val <= *(y_ptr + 1))
		{
			/* set tmp_y_val to first element in Y data point array*/
			tmp_y_val = *(y_ptr + 1);
			/* set y relative index to 0 */
			yrel_idx = 0;
			/* relative pointer pointing to element next to relative index */
			y1_ptr = y_ptr + 2;
		}
		else
		{
			/* search for tmp_y_val in the data point array from the point where relative pointer is pointing to bottom */
			--y1_ptr;
			while (tmp_y_val < (*y1_ptr))
			{
				--y1_ptr;
			}
			/* relative pointer calculation */
			yrel_idx = (uint8)(((uint32)y1_ptr - (uint32)y_ptr) - 1U);

			/* relative pointer pointing to element next to relative
            index */
			++y1_ptr;
		}
		/*~E*/
	}
	/* store y relative index value */
	*y1 = yrel_idx;
	/* find the interpolation factors */
	if (*(y1_ptr) > *(y1_ptr - 1U))
	{
		temp1_u8 = *(y1_ptr - 1U);
		fac1 = ((uint32)(tmp_y_val -temp1_u8 ) << 16U) / (uint32)(*y1_ptr - temp1_u8);
		fac2 = ((uint32)(*(y1_ptr) - tmp_y_val) << 16U) / (uint32)(*y1_ptr - temp1_u8);

	}
	else
	{
		fac1 = 65536;
		fac2 = 0;
	}
	/* pointers to point to the elements in the interpolation map */
	z1_ptr = z_ptr + yrel_idx;
	z2_ptr = z1_ptr + 1U;

	if (z2 != 0U)  /*z2=1 when it is in last column i.e. when passed tmp_y_val value is greater or equal to the last element of the input y_array */
	{
		if (*z2_ptr < *(z2_ptr + (*y_ptr * (*x_ptr - 1U))) )/* comparing the last column first element with last coulmn  last element */
		{
			increase=1U;

		}
		else
		{
			increase=0U;

		}
	}
	else
	{
		/* if the map is incresing globally */
		if (*z1_ptr < (*(z1_ptr + (*y_ptr * (*x_ptr - 1U)))))

		{
			increase=1;

		}
		else
		{
			increase=0;

		}
	}
	if (increase == 1U)
	{
		/*~A*/
		/*~+:interpolate z_val for a globally increasing map */
		temp1_u8 = *(z2_ptr + (*y_ptr * xrel_idx));
		temp1_u8_1 = *(z1_ptr + (*y_ptr * xrel_idx));
		fac = (fac1 * (uint32)temp1_u8) + (fac2 * (uint32)temp1_u8_1);
		z_n_x1 = (uint8)((fac + 32768U)/ 65536U);
		tmp_x = xrel_idx;
		z_n_x2 = z_n_x1;
		/* interpolate z value between 2 columns of ip map */
		while ((tmp_z_val < z_n_x1) && (xrel_idx >= 1U))
		{
			tmp_x = xrel_idx;
			z_n_x2 = z_n_x1;
			xrel_idx = xrel_idx - 1U;
			temp1_u8 = *(z2_ptr + (*y_ptr * xrel_idx));
			temp1_u8_1 = *(z1_ptr + (*y_ptr * xrel_idx));
			fac = (fac1 * (uint32)temp1_u8) + ((fac2 * (uint32)temp1_u8_1));
			z_n_x1 = (uint8)((fac + 32768U)/ 65536U);

		}
		/* interpolate z value between 2 columns of ip map */
		while ((tmp_z_val >= z_n_x2) && (tmp_x < (*x_ptr - 1U)))
		{
			xrel_idx = tmp_x;
			z_n_x1 = z_n_x2;
			tmp_x = tmp_x + 1U;

			temp1_u8 = *(z2_ptr + (*y_ptr * tmp_x));
			temp1_u8_1 = *(z1_ptr + (*y_ptr * tmp_x));
			fac = (fac1 * (uint32)temp1_u8) + (fac2 * (uint32)temp1_u8_1);
			z_n_x2 = (uint8)((fac + 32768U)/ 65536U);

		}
		/* check whether z_val lies between z_n_x1 and z_n_x2 otherwise fix it in between z_n_x1 and z_n_x2 */
		if (tmp_z_val > z_n_x1)
		{
			max = tmp_z_val;
		}
		else
		{
			max = z_n_x1;
		}
		if (max < z_n_x2)
		{
			tmp_z_val = max;
		}
		else
		{
			tmp_z_val = z_n_x2;
		}

		/*~E*/
	}
	else
	{
		/*~A*/
		/*~+:interpolate z_val for a globally decreasing map*/
		fac = (fac1 * (uint32)(*(z2_ptr + (*y_ptr * xrel_idx)))) + (fac2 * (uint32)(*(z1_ptr + (*y_ptr * xrel_idx))));
		z_n_x1 = (uint8)((fac + 32768U)/ 65536U);
		tmp_x = xrel_idx;
		z_n_x2 = z_n_x1;

		/* interpolate z value between 2 columns of ip map */
		while ((tmp_z_val < z_n_x2) && (tmp_x < (*x_ptr - 1U)))
		{
			xrel_idx = tmp_x;
			z_n_x1 = z_n_x2;
			tmp_x = tmp_x + 1U;
			fac = (fac1 * (uint32)(*(z2_ptr + (*y_ptr * tmp_x)))) + (fac2 * (uint32)(*(z1_ptr + (*y_ptr * tmp_x))));
			z_n_x2 = (uint8)((fac + 32768U)/ 65536U);

		}
		/* interpolate z value between 2 columns of ip map */
		while ((tmp_z_val >= z_n_x1) && (xrel_idx >= 1U))
		{
			tmp_x = xrel_idx;
			z_n_x2 = z_n_x1;
			xrel_idx = xrel_idx - 1U;
			fac = (fac1 * (uint32)(*(z2_ptr + (*y_ptr * xrel_idx)))) + (fac2 * (uint32)(*(z1_ptr + (*y_ptr * xrel_idx))));
			z_n_x1 = (uint8)((fac + 32768U)/ 65536U);

		}
		/* check whether tmp_z_val lies between z_n_x1 and z_n_x2 otherwise fix it in between z_n_x1 and z_n_x2 */
		if (tmp_z_val > z_n_x2)
		{
			max = tmp_z_val;

		}
		else
		{
			max = z_n_x2;

		}
		if (max < z_n_x1)
		{
			tmp_z_val = max;
		}
		else
		{
			tmp_z_val = z_n_x1;
		}

		/*~E*/
	}
	/* store x relative index in pointer */
	*x1 = xrel_idx;

	/* find x actual value from X data point array */
	if ((z_n_x1 < z_n_x2) || (z_n_x1 > z_n_x2))
	{
		/* interpolate between z_n_x1 and z_n_x2 */
		tmp_U32 = (x_ptr + tmp_x) + 1U;
		tmp_U32_1 = (x_ptr + xrel_idx) + 1U;
		temp = (sint32)((tmp_z_val - z_n_x1) * (*(tmp_U32))) + (sint32)((z_n_x2 - tmp_z_val) * (*(tmp_U32_1)));

		tmp_x = (uint8)(((temp / (sint32)(z_n_x2 - z_n_x1))) + ((2*(temp % (sint32)(z_n_x2 - z_n_x1))) / (sint32)(z_n_x2 - z_n_x1)));
	}
	else
	{
		tmp_x = (uint8)(*(x_ptr + xrel_idx + 1));
	}
	/* return x actual value */
	return tmp_x;

	/* ## Operation body end [95481a0f-8f17-489c-8d7a-47e152d1262c] */
}

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

uint16 function_u16_y_inv_ip_ptr_u16_u16(const uint16 * x_ptr, const uint16 * y_ptr, const uint16 * z_ptr, uint16 x_val, uint16 z_val, uint8 * x1, uint8 * y1)
{
	/* ## Operation body start [ad610ec6-43dd-413b-b39d-4817b477bf33] */
	uint16 max, z_n_y1, z_n_y2;      /* Temporary variables to store intermediate result */
	uint16 y_actual;                     /* Variable to store the return value */
	uint8 xrel_idx, yrel_idx,y2,increase;           /* Variables to stores relative indices */
	uint8 z2=0;
	const uint16 *xtmp_ptr, *x1_ptr;     /* Pointer variables to point to x data point array */
	const uint16 *z1_ptr, *z2_ptr;       /* Pointer variables to point to interpolation map values */
	uint32 fac, fac1, fac2;              /* Temporary variables to store intermediate results */
	sint32 temp,denominator;
	uint16 tmp_z_val,tmp_x_val;
	const uint16 *tmp_U32,*tmp_U32_1;
	tmp_x_val = x_val;
	tmp_z_val = z_val;
	/* Assign input x & y relative indices to temporary variables */
	xrel_idx = *x1;
	yrel_idx = *y1;

	/* Pointer to point to last element of x data point array */
	xtmp_ptr = x_ptr + *x_ptr;

	/* pointer to point to the the data point value pointed by relative pointer */
	x1_ptr = x_ptr + (xrel_idx + 1U);
	/* Check whether the x input value is greater than the element pointed by relative index */
	if (tmp_x_val >= *(x1_ptr))
	{
		/*~A*/
		/*~+:Find the x relative index in the upper part from the relative point of the data point array*/
		/*~+:*/
		/* Check whether the x input value is greater than the last element of the x data point array */
		if (tmp_x_val >= *xtmp_ptr)
		{
			/* set x actual value to last value in data point array */
			tmp_x_val=*xtmp_ptr;

			/* set relative pointer to last but one index in data point  array */
			xrel_idx = (uint8)(*x_ptr-2U);

			/* Relative pointer pointing to element next to relative index */
			x1_ptr = xtmp_ptr;
			z2 = 1;

		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to top*/
			do
			{
				++x1_ptr;
			}
			while (tmp_x_val>= (*x1_ptr));
			/* realtive pointer index calculation*/
			xrel_idx=(uint8)((((uint32)x1_ptr-(uint32)x_ptr)/2U)-2U);

		}
		/*~E*/
	}
	else
	{
		/*~A*/
		/*~+:Find the x relative index in the lower part from the relative point of the data point array*/
		/*~+:*/
		/* Check whether the x input value is less than the first element of the x data point array */
		if (tmp_x_val <= *(x_ptr+1))
		{
			/* set x actual value to first value in data point array */
			tmp_x_val= *(x_ptr+1);

			/* set relative index to first index in data point array */
			xrel_idx = 0;

			/* Relative pointer pointing to second element of x data point array */
			x1_ptr = x_ptr + 2;

		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to bottom */
			do
			{
				--x1_ptr;
			}
			while (tmp_x_val < (*x1_ptr));
			/* realtive index calculation*/
			xrel_idx=(uint8)((((uint32)x1_ptr-(uint32)x_ptr)/2U)-1U);

			/* Point the relative index pointer to the element next to relative index element */
			++x1_ptr;

		}
		/*~E*/
	}
	/* Store the relative index value */
	*x1 = xrel_idx;

	fac1 = (uint32)(tmp_x_val - *(x1_ptr-1U));
	fac2 = (uint32)(*(x1_ptr) - tmp_x_val);

	/* Find the interpolation factors */
	if (*(x1_ptr) > *(x1_ptr - 1U))
	{
		fac1 = ((uint32)fac1<<16U) / (uint32)(*x1_ptr - *(x1_ptr - 1U));
		fac2 = ((uint32)fac2<<16U) / (uint32)(*x1_ptr - *(x1_ptr - 1U));

	}
	else
	{
		fac1 = 65536;
		fac2 = 0;

	}
	/* Pointer to point to the element in the interpolation map */
	z1_ptr = z_ptr + (xrel_idx * (*y_ptr));
	z2_ptr = z1_ptr + *y_ptr;

	if (z2 != 0U) /*z2=1 when it is in last row i.e. when passed tmp_x_val value is greater or equal to the last element of the input x_array */
	{
		if (*z2_ptr < *(z2_ptr +(*y_ptr)- 1U))
			/* comparing the last row first element with last row last element */
		{
			increase=1U;
		}
		else
		{
			increase=0U;
		}
	}
	else
	{
		/* Check whether the interpolation map is increasing globally */
		if (*z1_ptr < (*(z2_ptr - 1U)))
		{
			increase=1U;
		}
		else
		{
			increase=0;
		}
	}
	if (increase == 1U)
	{
		/*~A*/
		/*~+:Interpolate the z_val value for a globally increasing interpolation map*/
		/*~+:*/
		/* If the map is increasing globally interpolate the map values */
		fac = (fac1 * (uint32)(*(z2_ptr+yrel_idx))) + (fac2* (uint32)(*(z1_ptr+yrel_idx)));
		z_n_y1 =(uint16)(( (fac / 65536U)) +((2U*(fac % 65536U)) / 65536U));
		y2 = yrel_idx;
		z_n_y2 = z_n_y1;

		/*Interpolate the z value between 2 rows of the ip map*/
		while ((tmp_z_val < z_n_y1) && (yrel_idx >= 1U))
		{
			y2 = yrel_idx;
			z_n_y2 = z_n_y1;
			yrel_idx = yrel_idx - 1U;
			fac = (fac1*(uint32)(*(z2_ptr+yrel_idx))) + (fac2 * (uint32)(*(z1_ptr+yrel_idx)));
			z_n_y1 =(uint16)(( (fac / 65536U)) +((2U*(fac % 65536U)) / 65536U));

		}
		/*Interpolate the z value between 2 rows of the ip map*/
		while ((tmp_z_val >= z_n_y2) && (y2 < (*y_ptr - 1U)))
		{
			yrel_idx = y2;
			z_n_y1 = z_n_y2;
			y2 = y2 + 1U;
			fac = (fac1 * (uint32) (*(z2_ptr+y2))) + (fac2 * (uint32)(*(z1_ptr+y2)));
			z_n_y2 =(uint16)(( (fac / 65536U)) +((2U*(fac % 65536U)) / 65536U));

		}
		/* Check whether z_val lies between z_n_y1 & z_n_y2 otherwise fix it in between z_n_y1 & z_n_y2 */
		if (tmp_z_val > z_n_y1)
		{
			max = tmp_z_val;
		}
		else
		{
			max = z_n_y1;
		}
		if (max < z_n_y2)
		{
			tmp_z_val = max;
		}
		else
		{
			tmp_z_val = z_n_y2;
		}
		/*~E*/
	}
	else
	{
		/*~A*/
		/*~+:Interpolate the z_val value for a globally decresing interpolation map*/
		/*~+:*/
		/* If the map is globally decreasing interpolate map values */
		fac = (fac1 * (uint32)(*(z2_ptr+yrel_idx))) + (fac2* (uint32)(*(z1_ptr+yrel_idx)));
		z_n_y1 =(uint16)(((fac / 65536U)) +((2U*(fac % 65536U)) / 65536U));
		y2 = yrel_idx;
		z_n_y2 = z_n_y1;

		/*Interpolate the z value between 2 rows of  ipmap*/
		while ((tmp_z_val < z_n_y2) && (y2 < (*y_ptr - 1U)))
		{
			yrel_idx = y2;
			z_n_y1 = z_n_y2;
			y2 = y2 + 1U;
			fac = (fac1 * (uint32)(*(z2_ptr+y2))) + (fac2 * (uint32)(*(z1_ptr+y2)));
			z_n_y2 =(uint16)(( (fac /65536U)) + ((2U*(fac % 65536U)) / 65536U));

		}
		/*Interpolate the z value between 2 rows of ip map*/
		while ((tmp_z_val >= z_n_y1) && (yrel_idx >= 1U))
		{
			y2 = yrel_idx;
			z_n_y2 = z_n_y1;
			yrel_idx = yrel_idx - 1U;
			fac = (fac1 * (uint32)(*(z2_ptr+yrel_idx))) + (fac2 * (uint32)(*(z1_ptr+yrel_idx)));
			z_n_y1 =(uint16)( ((fac / 65536U)) + ((2U * (fac % 65536U)) / 65536U));

		}
		/* Check whether z_val lies between z_n_y2 & z_n_y1 otherwise fix it in between z_n_y2 & z_n_y1 */
		if (tmp_z_val > z_n_y2)
		{
			max = tmp_z_val;
		}
		else
		{
			max = z_n_y2;
		}
		if (max < z_n_y1)
		{
			tmp_z_val = max;
		}
		else
		{
			tmp_z_val = z_n_y1;
		}
		/*~E*/
	}
	/* Store the y relative index in pointer */
	*y1 = yrel_idx;

	/* Find the y actual value from y data point array */
	if ((z_n_y1 < z_n_y2) || (z_n_y1 > z_n_y2))
	{
		/* interpolate between z_n_y1 and z_n_y2 */
		tmp_U32 = (y_ptr+y2)+1U;
		tmp_U32_1 = (y_ptr+yrel_idx)+1U;
		temp = (sint32)((tmp_z_val - z_n_y1) * (*(tmp_U32))) +(sint32) ((z_n_y2 - tmp_z_val) * (*(tmp_U32_1)));
		denominator = (sint32)(z_n_y2 - z_n_y1);
		y_actual = (uint16)(( (temp / denominator)) + ((2 * (temp % denominator)) / denominator ));

	}
	else
	{
		y_actual = (uint16)(*(y_ptr+yrel_idx+1));
	}
	/* Return the value of y data point array */
	return y_actual;

	/* ## Operation body end [ad610ec6-43dd-413b-b39d-4817b477bf33] */
}

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

uint16 function_u16_x_inv_ip_ptr_u16_u16(const uint16 * x_ptr, const uint16 * y_ptr, const uint16 * z_ptr, uint16 y_val, uint16 z_val, uint8 * x1, uint8 * y1)
{
	/* ## Operation body start [43d0c717-afd9-4311-ae89-b7e9949a641d] */
	const uint16   *ytmp_ptr, *y1_ptr;     /* pointer variables to point to y data point array */
	const uint16   *z1_ptr, *z2_ptr;       /* pointer variables to point to interpolation map */
	uint16         tmp_x = 0;              /* temporary variables to store intermediate results */
	uint16         max;                    /* temporary variables to store intermediate results */
	uint8          xrel_idx, yrel_idx, increase;     /* variables to store relative indices */
	uint8          z2=0;
	uint16         z_n_x1, z_n_x2;         /* temporary variables to store intermediate results */
	uint32         fac, fac1, fac2;        /* temporary variables to store intermediate results */
	sint32         temp;                   /* temporary variables to store intermediate results */
	uint16 tmp_y_val,tmp_z_val;
	const uint16 *tmp_U32,*tmp_U32_1;
	tmp_y_val = y_val;
	tmp_z_val = z_val;
	/* store x & y relative indices to temporary variables */
	xrel_idx = *x1;
	yrel_idx = *y1;

	/* pointer to point to last element of y data point array */
	ytmp_ptr = y_ptr + *y_ptr;

	/* pointer to point to the data point value pointed by relative pointer */
	y1_ptr = y_ptr + (yrel_idx + 1U);
	/* if y_val is greater than the value pointed by relative index */
	if (tmp_y_val >= *(y1_ptr))
	{
		/*~A*/
		/*~+:find y relative index in upper part from the point where relative pointer is pointing*/
		/*~+:*/
		/* check if y_val value is greater than the last element of the Y data point array */
		if (tmp_y_val >= *ytmp_ptr)
		{
			/* set y actual value to last value in data point array*/
			tmp_y_val = *ytmp_ptr;

			/* set relative pointer to last but one index in Y data point array */
			yrel_idx = (uint8)(*y_ptr-2U);

			/* relative pointer pointing to element next to relative index */
			y1_ptr = ytmp_ptr;
			z2 = 1;

		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to top*/
			++y1_ptr;
			while (tmp_y_val>= (*y1_ptr))
			{
				++y1_ptr;
			}
			/* realtive pointer index calculation*/
			yrel_idx = (uint8)((((uint32)y1_ptr - (uint32)y_ptr)/2U) - 2U);

		}
		/*~E*/
	}
	else
	{
		/*~A*/
		/*~+:find y relative index in lower part from the point where*/
		/*~+:relative pointer is pointing*/
		/*~+:*/
		/* check if y_val is less than the first element of the Y data point array */
		if (tmp_y_val <= *(y_ptr + 1U))
		{
			/* set y_val to first element in Y data point
            array*/
			tmp_y_val = *(y_ptr+1U);

			/* set y relative index to 0 */
			yrel_idx = 0;

			/* relative pointer pointing to second element of x data point array */
			y1_ptr = y_ptr + 2;

		}
		else
		{
			/* search input point value in the data point array from the point where relative pointer is pointing to bottom */
			--y1_ptr;
			while (tmp_y_val < (*y1_ptr))
			{
				--y1_ptr;
			}
			/* realtive index calculation*/
			yrel_idx = (uint8)((((uint32)y1_ptr - (uint32)y_ptr)/2U) - 1U);

			/* relative pointer pointing to element next to relative
            index */
			++y1_ptr;

		}
		/*~E*/
	}
	/* store y relative index value */
	*y1 = yrel_idx;

	/* find the interpolation factors */
	if (*(y1_ptr) > *(y1_ptr - 1U))
	{
		fac1 = ((uint32)(tmp_y_val - *(y1_ptr - 1U)) << 16U) / (uint32)(*y1_ptr - *(y1_ptr - 1U));
		fac2 = ((uint32)(*(y1_ptr) - tmp_y_val) << 16U) / (uint32)(*y1_ptr - *(y1_ptr - 1U));

	}
	else
	{
		fac1 = 65536;
		fac2 = 0;

	}
	/* pointers to point to the elements in the interpolation map */
	z1_ptr = z_ptr + yrel_idx;
	z2_ptr = z1_ptr + 1U;

	if (z2 != 0U) /*z2=1 when it is in last column i.e. when passed y_val value is greater or equal to the last element of the input y_array */
	{
		if (*z2_ptr < *(z2_ptr + (*y_ptr * (*x_ptr - 1U))))/* comparing the last column first element with last column last element */
		{
			increase=1U;

		}
		else
		{
			increase=0U;

		}
	}
	else
	{
		/* if the map is incresing globally */
		if (*z1_ptr < (*(z1_ptr + (*y_ptr * (*x_ptr - 1U)))))

		{
			increase=1;

		}
		else
		{
			increase=0;

		}
	}
	if (increase == 1U)
	{
		/*~A*/
		/*~+:interpolate z_val for a globally increasing map*/
		fac = (fac1 * (uint32)(*(z2_ptr + (*y_ptr * xrel_idx)))) + (fac2 * (uint32)(*(z1_ptr + (*y_ptr * xrel_idx))));
		z_n_x1 = (uint16)((fac + 32768U) / 65536U);
		tmp_x = xrel_idx;
		z_n_x2 = z_n_x1;

		/* interpolate z value between 2 columns of the ip map*/
		while ((tmp_z_val < z_n_x1) && (xrel_idx >= 1U))
		{
			tmp_x = xrel_idx;
			z_n_x2 = z_n_x1;
			xrel_idx = xrel_idx - 1U;
			fac = (fac1 * (uint32)(*(z2_ptr + (*y_ptr * xrel_idx)))) + (fac2 * (uint32)(*(z1_ptr + (*y_ptr * xrel_idx))));
			z_n_x1 =(uint16)((fac + 32768U) / 65536U);

		}
		/* interpolate z value between 2 columns of the ip map*/
		while ((tmp_z_val >= z_n_x2) && (tmp_x < (*x_ptr - 1U)))
		{
			xrel_idx = (uint8)tmp_x;
			z_n_x1 = z_n_x2;
			tmp_x = tmp_x + 1U;
			fac = (fac1 * (uint32) (*(z2_ptr + (*y_ptr * tmp_x)))) + (fac2 * (uint32)(*(z1_ptr + (*y_ptr * tmp_x))));
			z_n_x2 =(uint16)( (fac + 32768U) / 65536U);

		}
		/* check whether tmp_z_val lies between z_n_x1 & z_n_x2 otherwise fix it in between z_n_x1 & z_n_x2 */
		if (tmp_z_val > z_n_x1)
		{
			max = tmp_z_val;
		}
		else
		{
			max = z_n_x1;
		}
		if (max < z_n_x2)
		{
			tmp_z_val = max;
		}
		else
		{
			tmp_z_val = z_n_x2;
		}
		/*~E*/
	}
	else
	{
		/*~A*/
		/*~+:interpolate tmp_z_val value for a globally decreasing map*/
		fac = (fac1 * (uint32)(*(z2_ptr + (*y_ptr * xrel_idx)))) + (fac2* (uint32)(*(z1_ptr + (*y_ptr * xrel_idx))));
		z_n_x1 =(uint16)((fac + 32768U) / 65536U);
		tmp_x = xrel_idx;
		z_n_x2 = z_n_x1;

		/* interpolate z value between 2 columns of  ip map*/
		while ((tmp_z_val < z_n_x2) && (tmp_x < (*x_ptr - 1U)))
		{
			xrel_idx = (uint8)tmp_x;
			z_n_x1 = z_n_x2;
			tmp_x = tmp_x + 1U;
			fac = (fac1 * (uint32)(*(z2_ptr + (*y_ptr * tmp_x)))) + (fac2 * (uint32)(*(z1_ptr + (*y_ptr * tmp_x))));
			z_n_x2 = (uint16)( (fac + 32768U) /65536U);

		}
		/* interpolate z value between 2 columns of ip map*/
		while ((tmp_z_val >= z_n_x1) && (xrel_idx >= 1U))
		{
			tmp_x = xrel_idx;
			z_n_x2 = z_n_x1;
			xrel_idx = xrel_idx - 1U;
			fac = (fac1 * (uint32)(*(z2_ptr + (*y_ptr * xrel_idx)))) + (fac2 * (uint32)(*(z1_ptr + (*y_ptr * xrel_idx))));
			z_n_x1 =(uint16)( (fac + 32768U) / 65536U);

		}
		/* check whether tmp_z_val lies between z_n_x2 & z_n_x1 otherwise fix it in between z_n_x2 & z_n_x1 */
		if (tmp_z_val > z_n_x2)
		{
			max = tmp_z_val;
		}
		else
		{
			max = z_n_x2;
		}
		if (max < z_n_x1)
		{
			tmp_z_val = max;
		}
		else
		{
			tmp_z_val = z_n_x1;
		}
		/*~E*/
	}
	/* store the x relative index in pointer */
	*x1 = xrel_idx;

	/* find the x actual value from X data point array */
	if ((z_n_x1 < z_n_x2) || (z_n_x1 > z_n_x2))
	{
		/* interpolate between z_n_x1 and z_n_x2 */

		tmp_U32 = (x_ptr + tmp_x) + 1U;
		tmp_U32_1 = (x_ptr + xrel_idx) + 1U;
		temp = (sint32)((tmp_z_val -z_n_x1) * (*(tmp_U32))) + (sint32)( (z_n_x2 - tmp_z_val) * (*(tmp_U32_1)));

		tmp_x = (uint16)(((temp / (sint32)(z_n_x2 - z_n_x1))) + ((2 * (temp % (sint32)(z_n_x2 - z_n_x1))) / (sint32)(z_n_x2 - z_n_x1)));

	}
	else
	{
		tmp_x = (uint16)(*(x_ptr + xrel_idx + 1));
	}
	/* return x actual value */
	return tmp_x;

	/* ## Operation body end [43d0c717-afd9-4311-ae89-b7e9949a641d] */
}

/*~E*/
