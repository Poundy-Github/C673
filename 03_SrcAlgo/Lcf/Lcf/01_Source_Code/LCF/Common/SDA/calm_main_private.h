/*~A*/
/*~+:VM Header*/
/* Used UML Profile version  */
/* ## Module Header Start [5fee9f24-2b00-42d4-a8cd-b70cba5ad15b] */
/****************************************************************************

COPYRIGHT (C) $Date: 2019/07/03 13:44:17CEST $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.                                                 

The reproduction, transmission or use of this document or its contents is  
not permitted without express written authority.                           
Offenders will be liable for damages. All rights, including rights created 
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------

$Log: calm_main_private.h  $
Revision 1.1 2019/07/03 13:44:17CEST Nastasa, Elena (uidt4846) 
Initial revision
Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/Common/SDA/project.pj
Revision 1.1 2018/07/24 16:49:46CEST Ammermueller Martin (uidv5342) (uidv5342) 
Initial revision
Member added to project /ES/1T/0C/SDA/SDA_Source/SDA_Toolboxes/ACG/Libraries/calm/Src/3_1_0/project.pj
Revision 1.4 2018/03/06 07:53:45CET Angadi Hampa (uidu8151) (uidu8151) 
RO : 8197494 : MISRA2012 ANSI VERSIONS
Revision 1.3 2017/10/04 07:47:36CEST Angadi Hampa (uidu8151) (uidu8151) 
Calm : LINT MISRA2012 for ANSI
Revision 1.2 2015/12/02 03:17:58CET Angadi Hampa (uidu8151) (uidu8151) 
RO: 3550535: CALM : Create ANSI Version; Before review
Revision 1.4 2015/11/04 11:58:13CET Ganesh Sumangala (uidu8725) (uidu8725) 
RO : 2806846 : CALM: Merge EMS2 and EMS3 Calm versions.
Revision 1.3 2014/09/19 05:37:11CEST Angadi Hampa (uidu8151) (uidu8151) 
Ro: 1081869 : FS_0G01_TC2XX_CALM_200: Review comments update
Revision 1.2 2013/08/21 06:25:33CEST Angadi Hampa (uidu8151) (uidu8151) 
for release RO_429651 :FS_0G01_TC2XX_CALM_100
Revision 1.1 2013/08/09 14:57:32IST Angadi Hampa (uidu8151) (uidu8151) 
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
/* ## Module Header End [5fee9f24-2b00-42d4-a8cd-b70cba5ad15b] */

/*~E*/
/*~A*/
/*~+:SW module (UML class) description*/
/* This component provides an option to select either the C version or assembly version of the implemented code for compilation. 
This file also contains private static inline operations for interpolation which will be used in the exported library operations

This file will be generated through UML and will be updated manually for private static inline operations. */
/*~E*/
#ifndef CALM_MAIN_PRIVATE_H
#define CALM_MAIN_PRIVATE_H
#include "iopt_memmap.h"
/*~A*/
/*~+:Preprocessor Commands*/
/* SV C Preproc Class HFile */

/*~E*/
/*~A*/
/*~+:LINT SUPPRESSIONS*/
/*lint --e{9016} */
/*lint --e{9033} */
/*~E*/
/*~A*/
/*~+:Attributes*/
/*~A*/
/*~+:Forward Declarations*/

/*~E*/
/*~A*/
/*~+:Defines*/


/*~E*/
/*~A*/
/*~+:Typedefs*/

/*~E*/
/*~A*/
/*~+:Structures*/

/*~E*/
/*~A*/
/*~+:Variable and Constant Declarations*/

/*~E*/
/*~E*/
/*~A*/
/*~+:Operations*/
#include "iopt_memmap.h"
/*~A*/
/*~+:Interpolation with rounding*/
static inline sint32 function_s32_interpolate_u8(sint32 ip1, sint32 ip2)   /*  DONT USE !!!!!!! */
{
	/*only dummy
!!! DONT USE because of slow /  2^N-DIVISION and other interface (without FACTOR) than fct. below  !!!!*/
	/*~T*/
	sint32 temp=0;
	if (ip2 >= 0)
	{
		temp = (ip1 + ((ip2 + (sint32)32768) / (sint32)65536));
	}
	else
	{
		temp= (ip1 + ((ip2 - (sint32)32768) / (sint32)65536));
	}
	return temp;
}
static inline uint32 function_u32_interpolate_u16(uint32 ip1, uint32 ip2, uint16 fac)
{
	/*~T*/
	uint32 temp1=0,temp2=0;
	if (ip2 >= ip1)
	{
		temp2 = (ip2 - ip1) * fac;
		temp1 = (ip1 + ((temp2 + 32768U) >> 16));
	}
	else
	{
		temp2 = (ip1 - ip2) * fac;
		temp1 = (ip1 - ((temp2 + 32768U) >> 16));
	}
	return temp1;
}
/*lint --e{529,715}*/
static inline sint32 function_s32_interpolate_s16(sint32 ip1, sint32 ip2, uint16 fac)
{
	uint32 tmp_product;
	sint32 temp=0;
	if (ip2 >= ip1)
	{
		tmp_product = (uint32)(ip2 - ip1) * fac;
		temp = (ip1 + (sint32)((tmp_product + 32768U) >> 16));
	}
	else
	{
		tmp_product = (uint32)(ip1 - ip2) * fac;
		temp = (ip1 - (sint32)((tmp_product + 32768U) >> 16));
	}
	return temp;
}
static inline uint32 function_u32_interpolate_u32(uint32 ip1, uint32 ip2, uint16 fac)
{
	uint64 tmp_product;
	uint32 temp=0;
	if (ip2 >= ip1)
	{
		tmp_product = (uint64)(ip2 - ip1) * fac;
		temp = (ip1 + (uint32)((tmp_product + 32768U) >> 16));
	}
	else
	{
		tmp_product = (uint64)(ip1 - ip2) * fac;
		temp = (ip1 - (uint32)((tmp_product + 32768U) >> 16));
	}
	return temp;
}
static inline sint32 function_s32_interpolate_s32(sint32 ip1, sint32 ip2, uint16 fac)
{
	uint64 tmp_product;
	sint32 temp=0;
	if (ip2 >= ip1)
	{
		tmp_product = (uint64)((uint32)(ip2 - ip1)) * fac;
		temp = (sint32)((sint64)ip1 + (sint64)((tmp_product + 32768U) >> 16));
	}
	else
	{
		tmp_product = (uint64)((uint32)(ip1 - ip2)) * fac;
		temp = (sint32)((sint64)ip1 - (sint64)((tmp_product + 32768U) >> 16));
	}
	return temp;
}
/*~E*/
/*~A*/
/*~+:function_ip1d_u8*/
static inline uint8 function_ip1d_u8(const uint8 *ip_ptr, uint8 idx, uint16 fac)
{
	sint32 ip1, ip2;

	ip1 = (sint32)*(ip_ptr + idx); /* first map value */
	if (fac > 0U)
	{
		ip2 = (sint32)*(ip_ptr + (idx + 1U)); /* second map value */
		ip2 = ((ip2 - ip1) * (sint32)fac);
		/* static inline function call for interpolation */
		ip1 = function_s32_interpolate_u8(ip1, ip2);
	}
	else
	{
		/* no interpolation is required if factor is zero */

	}
	return (uint8)ip1;
}

/*~E*/
/*~A*/
/*~+:function_ip2d_u8*/
static inline uint8 function_ip2d_u8(const uint8 *ip_ptr, uint8 num_col, uint8 idx_x, uint8 idx_y, uint16 fac_x, uint16 fac_y)
{
	const uint8 *ptr;
	sint32   ip1, ip2, ip3;
	/* pointer to point to the element pointed by line and column index */
	ptr = ip_ptr + ((uint16)idx_x * num_col) + idx_y;
	ip1 = (sint32)*ptr;     /* first map value */
	if (fac_x != 0U)
	{
		if (fac_y != 0U)
		{
			/*~A*/
			/*~+:both line and column interpolation when x and y factors are non-zero*/
			ip2 = ((sint32)*(ptr + 1U) - ip1) * (sint32)fac_y;
			/* static inline function call for first column interpolation */
			ip1 = function_s32_interpolate_u8(ip1, ip2);
			/* pointer to point to next line in map */
			ptr += num_col;
			ip2 = (sint32)*ptr;             /* first map value */
			ip3 = ((sint32)*(ptr + 1U) - ip2) * (sint32)fac_y;
			/* static inline function call for second column interpolation */
			ip2 = function_s32_interpolate_u8(ip2, ip3);
			ip2 = ((ip2 - ip1) * (sint32)fac_x);
			/* static inline function call for final interpolation */
			ip1 = function_s32_interpolate_u8(ip1, ip2);

			/*~E*/
		}
		else
		{
			/*~A*/
			/*~+:line interpolation when y factor is zero*/
			ip2 = ((sint32)*(ptr + num_col) - ip1) * (sint32)fac_x;
			/* static inline function call for interpolation */
			ip1 = function_s32_interpolate_u8(ip1, ip2);

			/*~E*/
		}
	}
	else
	{
		if (fac_y != 0U)
		{
			/*~A*/
			/*~+:column interpolation when x factor is zero*/
			ip2 = ((sint32)*(ptr + 1) - ip1) * (sint32)fac_y;
			/* static inline function call for interpolation */
			ip1 = function_s32_interpolate_u8(ip1, ip2);

			/*~E*/
		}
		else
		{
			/* no interpolation when both  x and y factors are zero */
		}
	}
	return (uint8)ip1;
}

/*~E*/
/*~A*/
/*~+:function_ip2d_s8*/
static inline sint8 function_ip2d_s8(const sint8 *ip_ptr, uint8 num_col, uint8 idx_x, uint8 idx_y, uint16 fac_x, uint16 fac_y)

{
	const sint8 *ptr;
	sint32   ip1, ip2, ip3;
	/* pointer to point to the element pointed by line and column index */
	ptr = ip_ptr + ((uint16)idx_x * num_col) + idx_y;
	ip1 = (sint32)*ptr;     /* first map value */
	if (fac_x > 0U)
	{
		if  (fac_y > 0U)
		{
			/*~A*/
			/*~+:both line and column interpolation when x and y factors are non-zero*/
			ip2 = ((sint32)*(ptr + 1) - ip1) * (sint32)fac_y;
			/* static inline function call for first column interpolation */
			ip1 = function_s32_interpolate_u8(ip1, ip2);
			/* pointer to point to next line in map */
			ptr += num_col;
			ip2 = (sint32)*ptr;             /* first map value */
			ip3 = ((sint32)*(ptr + 1) - ip2) * (sint32)fac_y;
			/* static inline function call for second column interpolation */
			ip2 = function_s32_interpolate_u8(ip2, ip3);
			ip2 = ((ip2 - ip1) * (sint32)fac_x);
			/* static inline function call for final interpolation */
			ip1 = function_s32_interpolate_u8(ip1, ip2);

			/*~E*/
		}
		else
		{
			/*~A*/
			/*~+:line interpolation when y factor is zero*/
			ip2 = ((sint32)*(ptr + num_col) - ip1) * (sint32)fac_x;
			/* static inline function call for interpolation */
			ip1 = function_s32_interpolate_u8(ip1, ip2);

			/*~E*/
		}
	}
	else
	{
		if  (fac_y > 0U)
		{
			/*~A*/
			/*~+:column interpolation when x factor is zero*/
			ip2 = ((sint32)*(ptr + 1) - ip1) * (sint32)fac_y;
			/* static inline function call for interpolation */
			ip1 = function_s32_interpolate_u8(ip1, ip2);

			/*~E*/
		}
		else
		{
			/* no interpolation when both x and y factors are zero */
		}
	}
	return (sint8)ip1;
}

/*~E*/
/*~A*/
/*~+:function_ip2d_u16*/
static inline uint16 function_ip2d_u16(const uint16 *ip_ptr, uint8 num_col, uint8 idx_x, uint8 idx_y, uint16 fac_x, uint16 fac_y)
{
	const uint16 *ptr;
	uint32   ip1, ip2, ip3;
	/* pointer to point to the element pointed by line and column index */
	ptr = ip_ptr + ((uint16)idx_x * num_col) + idx_y;
	ip1 = (uint32)*ptr;     /* first map value */
	if (fac_x > 0U)
	{
		if (fac_y > 0U)
		{
			/*~A*/
			/*~+:both line and column interpolation when x and y factors are non-zero*/
			ip2 = (uint32)*(ptr + 1);       /* second map value */
			/* static inline function call for first column interpolation */
			ip1 = function_u32_interpolate_u16(ip1, ip2, fac_y);
			/* pointer to point to next line in map */
			ptr += num_col;
			ip3 = (uint32)*ptr;             /* first map value */
			ip2 = (uint32)*(ptr + 1);       /* second map value */
			/* static inline function call for second column interpolation */
			ip2 = function_u32_interpolate_u16(ip3, ip2, fac_y);
			/* static inline function call for final interpolation */
			ip1 = function_u32_interpolate_u16(ip1, ip2, fac_x);

			/*~E*/
		}
		else
		{
			/*~A*/
			/*~+:line interpolation when y factor is zero*/
			ip2 = (uint32)*(ptr + num_col);             /* second map value */
			/* static inline function call for interpolation */
			ip1 = function_u32_interpolate_u16(ip1, ip2, fac_x);

			/*~E*/
		}
	}
	else
	{
		if  (fac_y > 0U)
		{
			/*~A*/
			/*~+:column interpolation when x factor is zero*/
			ip2 = (uint32)*(ptr + 1);            /* second map value */
			/* static inline function call for interpolation */
			ip1 = function_u32_interpolate_u16(ip1, ip2, fac_y);

			/*~E*/
		}
		else
		{
			/* no interpolation when both x and y factors are zero */
		}
	}
	return (uint16)ip1;
}

/*~E*/
/*~A*/
/*~+:function_ip2d_s16*/
static inline sint16 function_ip2d_s16(const sint16 *ip_ptr, uint8 num_col, uint8 idx_x, uint8 idx_y, uint16 fac_x, uint16 fac_y)
{
	const sint16 *ptr;
	sint32   ip1, ip2, ip3;

	/* pointer to map value pointed by x and y axes */
	ptr = ip_ptr + ((uint16)idx_x * num_col) + idx_y;
	ip1 = (sint32)*ptr;     /* first map value */
	if (fac_x > 0U)
	{
		if (fac_y > 0U)
		{
			/*~A*/
			/*~+:both line and column interpolation when x and y factors are non-zero*/
			ip2 = (sint32)*(ptr + 1);       /* second map value */
			/* static inline function call for first column interpolation */
			ip1 = function_s32_interpolate_s16(ip1, ip2, fac_y);
			/* pointer to point to next line in map */
			ptr += num_col;
			ip3 = (sint32)*ptr;             /* first map value */
			ip2 = (sint32)*(ptr + 1);       /* second map value */
			/* static inline function call for second column interpolation */
			ip2 = function_s32_interpolate_s16(ip3, ip2, fac_y);
			/* static inline function call for final interpolation */
			ip1 = function_s32_interpolate_s16(ip1, ip2, fac_x);

			/*~E*/
		}
		else
		{
			/*~A*/
			/*~+:line interpolation when y factor is zero*/
			ip2 = (sint32)*(ptr + num_col);             /* second map value */
			/* static inline function call for interpolation */
			ip1 = function_s32_interpolate_s16(ip1, ip2, fac_x);

			/*~E*/
		}
	}
	else
	{
		if  (fac_y > 0U)
		{
			/*~A*/
			/*~+:column interpolation when x factor is zero*/
			ip2 = (sint32)*(ptr + 1);           /* second map value */
			/* static inline function call for interpolation */
			ip1 = function_s32_interpolate_s16(ip1, ip2, fac_y);

			/*~E*/
		}
		else
		{
			/* no interpolation when both x and y factors are zero */
		}
	}
	return (sint16)ip1;
}

/*~E*/
/*~A*/
/*~+:function_ip2d_u32*/
static inline uint32 function_ip2d_u32(const uint32 *ip_ptr, uint8 num_col, uint8 idx_x, uint8 idx_y, uint16 fac_x, uint16 fac_y)
{
	const uint32 *ptr;
	uint32   ip1, ip2, ip3;
	/* pointer to map value pointed by x and y indeces */
	ptr = ip_ptr + ((uint16)idx_x * num_col) + idx_y;
	ip1 = *ptr;     /* first map value */
	if (fac_x > 0U)
	{
		if (fac_y > 0U)
		{
			/*~A*/
			/*~+:both line and column interpolation when x and y factors are non-zero*/
			ip2 = *(ptr + 1);       /* second map value */
			/* static inline function call for first column interpolation */
			ip1 = function_u32_interpolate_u32(ip1, ip2, fac_y);
			/* pointer to point to next line in map */
			ptr += num_col;
			ip2 = *ptr;             /* first map value */
			ip3 = *(ptr + 1);       /* second map value */
			/* static inline function call for second column interpolation */
			ip2 = function_u32_interpolate_u32(ip2, ip3, fac_y);
			/* static inline function call for final interpolation */
			ip1 = function_u32_interpolate_u32(ip1, ip2, fac_x);

			/*~E*/
		}
		else
		{
			/*~A*/
			/*~+:line interpolation when y factor is zero*/
			ip2 = *(ptr + num_col);             /* second map value */
			/* static inline function call for interpolation */
			ip1 = function_u32_interpolate_u32(ip1, ip2, fac_x);

			/*~E*/
		}
	}
	else
	{
		if  (fac_y > 0U)
		{
			/*~A*/
			/*~+:column interpolation when x factor is zero*/
			ip2 = *(ptr + 1);           /* second map value */
			/* static inline function call for interpolation */
			ip1 = function_u32_interpolate_u32(ip1, ip2, fac_y);

			/*~E*/
		}
		else
		{
			/* no interpolation when both x and y factors are zero */
		}
	}
	return ip1;
}

/*~E*/
/*~A*/
/*~+:function_ip2d_s32*/
static inline sint32 function_ip2d_s32(const sint32 *ip_ptr, uint8 num_col, uint8 idx_x, uint8 idx_y, uint16 fac_x, uint16 fac_y)
{
	const sint32 *ptr;
	sint32   ip1, ip2, ip3;
	/* pointer to map value pointed by x and y indeces */
	ptr = ip_ptr + ((uint16)idx_x * num_col) + idx_y;
	ip1 = *ptr;     /* first map value */
	if (fac_x > 0U)
	{
		if (fac_y > 0U)
		{
			/*~A*/
			/*~+:both line and column interpolation when x and y factors are non-zero*/
			ip2 = *(ptr + 1);       /* second map value */
			/* static inline function call for first column interpolation */
			ip1 = function_s32_interpolate_s32(ip1, ip2, fac_y);
			/* pointer to point to next line in map */
			ptr += num_col;
			ip2 = *ptr;             /* first map value */
			ip3 = *(ptr + 1);       /* second map value */
			/* static inline function call for second column interpolation */
			ip2 = function_s32_interpolate_s32(ip2, ip3, fac_y);
			/* static inline function call for final interpolation */
			ip1 = function_s32_interpolate_s32(ip1, ip2, fac_x);

			/*~E*/
		}
		else
		{
			/*~A*/
			/*~+:line interpolation when y factor is zero*/
			ip2 = *(ptr + num_col);             /* second map value */
			/* static inline function call for interpolation */
			ip1 = function_s32_interpolate_s32(ip1, ip2, fac_x);

			/*~E*/
		}
	}
	else
	{
		if  (fac_y > 0U)
		{
			/*~A*/
			/*~+:column interpolation when x factor is zero*/
			ip2 = *(ptr + 1);           /* second map value */
			/* static inline function call for interpolation */
			ip1 = function_s32_interpolate_s32(ip1, ip2, fac_y);

			/*~E*/
		}
		else
		{
			/* no interpolation when both x and y factors are zero */
		}
	}
	return ip1;
}

/*~E*/
/*~A*/
/*~+:function_ip2d_u16_u8*/
static inline uint16 function_ip2d_u16_u8(const uint8 *ip_ptr, uint8 num_col, uint8 idx_x, uint8 idx_y, uint16 fac_x, uint16 fac_y)
{
	const uint8 *ptr;
	uint32   ip1, ip2, ip3;
	/* pointer to point to the element pointed by line and column index */
	ptr = ip_ptr + ((uint16)idx_x * num_col) + idx_y;
	ip1 = (uint32)*ptr << 8;     /* first map value */
	if (fac_x > 0U)
	{
		if (fac_y > 0U)
		{
			/*~A*/
			/*~+:both line and column interpolation when x and y factors are non-zero*/
			ip2 = (uint32)*(ptr + 1) << 8;     /* second map value */
			/* static inline function call for first column interpolation */
			ip1 = function_u32_interpolate_u16(ip1, ip2, fac_y);
			/* pointer to point to next line in map */
			ptr += num_col;
			ip3 = (uint32)*ptr << 8;           /* first map value */
			ip2 = (uint32)*(ptr + 1) << 8;     /* second map value */
			/* static inline function call for second column interpolation */
			ip2 = function_u32_interpolate_u16(ip3, ip2, fac_y);
			/* static inline function call for final interpolation */
			ip1 = function_u32_interpolate_u16(ip1, ip2, fac_x);

			/*~E*/
		}
		else
		{
			/*~A*/
			/*~+:line interpolation when y factor is zero*/
			ip2 = (uint32)*(ptr + num_col) << 8;             /* second map value */
			/* static inline function call for interpolation */
			ip1 = function_u32_interpolate_u16(ip1, ip2, fac_x);

			/*~E*/
		}
	}
	else
	{
		if  (fac_y > 0U)
		{
			/*~A*/
			/*~+:column interpolation when x factor is zero*/
			ip2 = (uint32)*(ptr + 1) << 8;           /* second map value */
			/* static inline function call for interpolation */
			ip1 = function_u32_interpolate_u16(ip1, ip2, fac_y);

			/*~E*/
		}
		else
		{
			/* no interpolation when both x and y factors are zero */
		}
	}
	return (uint16)ip1;

}

/*~E*/
/*~A*/
/*~+:function_ip2d_s16_s8*/
static inline sint16 function_ip2d_s16_s8(const sint8 *ip_ptr, uint8 num_col, uint8 idx_x, uint8 idx_y, uint16 fac_x, uint16 fac_y)
{
	const sint8 *ptr;
	sint32   ip1, ip2, ip3;

	/* pointer to map value pointed by line and column index */
	ptr = ip_ptr + ((uint16)idx_x * num_col) + idx_y;
	ip1 = (sint32)*ptr * 256;     /* first map value */
	if (fac_x > 0U)
	{
		if (fac_y > 0U)
		{
			/*~A*/
			/*~+:both line and column interpolation when x and y factors are non-zero*/
			ip2 = ((sint32)*(ptr + 1) * 256);       /* second map value */
			/* static inline function call for first column interpolation */
			ip1 = function_s32_interpolate_s16(ip1, ip2, fac_y);
			/* pointer to point to next line in map */
			ptr += num_col;
			ip3 = (sint32)*ptr * 256;               /* first map value */
			ip2 = ((sint32)*(ptr + 1) * 256);       /* second map value */
			/* static inline function call for second column interpolation */
			ip2 = function_s32_interpolate_s16(ip3, ip2, fac_y);
			/* static inline function call for final interpolation */
			ip1 = function_s32_interpolate_s16(ip1, ip2, fac_x);

			/*~E*/
		}
		else
		{
			/*~A*/
			/*~+:line interpolation when y factor is zero*/
			ip2 = ((sint32)*(ptr + num_col) * 256);             /* second map value */
			/* static inline function call for interpolation */
			ip1 = function_s32_interpolate_s16(ip1, ip2, fac_x);

			/*~E*/
		}
	}
	else
	{
		if  (fac_y > 0U)
		{
			/*~A*/
			/*~+:column interpolation when x factor is zero*/
			ip2 = ((sint32)*(ptr + 1) * 256);            /* second map value */
			/* static inline function call for interpolation */
			ip1 = function_s32_interpolate_s16(ip1, ip2, fac_y);

			/*~E*/
		}
		else
		{
			/* no interpolation when both x and y factors are zero */
		}
	}
	return (sint16)ip1;
}

/*~E*/
/*~A*/
/*~+:function_ip2d_u32_u16*/
static inline uint32 function_ip2d_u32_u16(const uint16 *ip_ptr, uint8 num_col, uint8 idx_x, uint8 idx_y, uint16 fac_x, uint16 fac_y)
{
	const uint16 *ptr;
	uint32   ip1, ip2, ip3;

	/* pointer to point to the element pointed by line and column index */
	ptr = ip_ptr + ((uint16)idx_x * num_col) + idx_y;

	ip1 = (uint32)*ptr << 16;     /* first map value */
	if (fac_x > 0U)
	{
		if  (fac_y > 0U)
		{
			/*~A*/
			/*~+:Interpolate between both columns and lines*/
			ip2 = (uint32)*(ptr + 1) << 16;       /* second map value */
			/* static inline function call for first column interpolation */
			ip1 = function_u32_interpolate_u32(ip1, ip2, fac_y);
			/* pointer to point to next line in map */
			ptr += num_col;
			ip2 = (uint32)*ptr << 16;             /* first map value */
			ip3 = (uint32)*(ptr + 1) << 16;       /* second map value */
			/* static inline function call for second column interpolation */
			ip2 = function_u32_interpolate_u32(ip2, ip3, fac_y);
			/* static inline function call for final interpolation */
			ip1 = function_u32_interpolate_u32(ip1, ip2, fac_x);

			/*~E*/
		}
		else
		{
			/*~A*/
			/*~+:interpolate only between lines*/
			ip2 = (uint32)*(ptr + num_col) << 16;             /* second map value */
			/* static inline function call for interpolation */
			ip1 = function_u32_interpolate_u32(ip1, ip2, fac_x);

			/*~E*/
		}
	}
	else
	{
		if  (fac_y > 0U)
		{
			/*~A*/
			/*~+:interpolate between columns*/
			ip2 = (uint32)*(ptr + 1) << 16;            /* second map value */
			/* static inline function call for interpolation */
			ip1 = function_u32_interpolate_u32(ip1, ip2, fac_y);

			/*~E*/
		}
		else
		{
			/* no interpolation when both x and y factors are zero */
		}
	}
	return ip1;
}

/*~E*/
/*~A*/
/*~+:function_ip2d_s32_s16*/
static inline sint32 function_ip2d_s32_s16(const sint16 *ip_ptr, uint8 num_col, uint8 idx_x, uint8 idx_y, uint16 fac_x, uint16 fac_y)
{
	const sint16 *ptr;
	sint32   ip1,ip2,ip3;

	/* pointer to point to the element pointed by line and column index */
	ptr = ip_ptr + ((uint16)idx_x * num_col) + idx_y;
	ip1 = (sint32)*ptr * (sint32)65536;     /* first map value */
	if (fac_x > 0U)
	{
		if  (fac_y > 0U)
		{
			/*~A*/
			/*~+:both line and column interpolation when x and y factors are non-zero*/
			ip2 = (sint32)*(ptr + 1) * (sint32)65536;       /* second map value */
			/* static inline function call for first column interpolation */
			ip1 = function_s32_interpolate_s32(ip1, ip2, fac_y);
			/* pointer to point to next line in map */
			ptr += num_col;
			ip2 = (sint32)*ptr * (sint32)65536;     /* first map value */
			ip3 = (sint32)*(ptr+1) * (sint32)65536;       /* second map value */
			/* static inline function call for second column interpolation */
			ip2 = function_s32_interpolate_s32(ip2, ip3, fac_y);
			/* static inline function call for final interpolation */
			ip1 = function_s32_interpolate_s32(ip1, ip2, fac_x);

			/*~E*/
		}
		else
		{
			/*~A*/
			/*~+:line interpolation when y factor is zero*/
			ip2 = (sint32)*(ptr + num_col) * (sint32)65536;            /* second map value */
			/* static inline function call for interpolation */
			ip1 = function_s32_interpolate_s32(ip1, ip2, fac_x);

			/*~E*/
		}
	}
	else
	{
		if  (fac_y > 0U)
		{
			/*~A*/
			/*~+:column interpolation when x factor is zero*/
			ip2 = (sint32)*(ptr+1) * (sint32)65536;            /* second map value */
			/* static inline function call for interpolation */
			ip1 = function_s32_interpolate_s32(ip1, ip2, fac_y);

			/*~E*/
		}
		else
		{
			/* no interpolation when both x and y factors are zero */
		}
	}
	return ip1;
}

/*~E*/

/*~E*/
#include "iopt_memmap.h"

#endif
