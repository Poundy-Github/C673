/*~A*/
/*~+:VM Header*/
/* Used UML Profile version  */
/* ## Module Header Start [1d09789f-0cdd-4387-8fe8-a6aeaddd7201] */
/****************************************************************************

COPYRIGHT (C) $Date: 2019/07/03 13:44:18CEST $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.                                                 

The reproduction, transmission or use of this document or its contents is  
not permitted without express written authority.                           
Offenders will be liable for damages. All rights, including rights created 
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------

$Log: ecmath_main.c  $
Revision 1.1 2019/07/03 13:44:18CEST Nastasa, Elena (uidt4846) 
Initial revision
Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/Common/SDA/project.pj
Revision 1.1 2018/07/24 16:50:38CEST Ammermueller Martin (uidv5342) (uidv5342) 
Initial revision
Member added to project /ES/1T/0C/SDA/SDA_Source/SDA_Toolboxes/ACG/Libraries/Ecmath/Src/3_1_0/project.pj
Revision 1.7 2018/03/06 08:32:43CET Angadi Hampa (uidu8151) (uidu8151) 
RO : 8197610 : MISRA2012 ANSI VERSIONS
Revision 1.6 2017/05/02 14:39:04CEST Wagner Michael (uid13432) (uid13432) 
Function u16_div_u32_u16 corrected.
Revision 1.5 2015/12/31 11:11:38CET Ganesh Sumangala (uidu8725) (uidu8725) 
reveiw updates
Revision 1.4 2015/12/29 11:07:59CET Ganesh Sumangala (uidu8725) (uidu8725) 
ecmath create ansi version
reveiw updates
Revision 1.2 2015/12/14 07:56:46CET Ganesh Sumangala (uidu8725) (uidu8725) 
RO : 3550598:MATH: Create ANSI version
Initial archive
Revision 1.10 2015/11/05 12:12:19CET Angadi Hampa (uidu8151) (uidu8151) 
RO: 2875029 ; Merge EMS2 and EMS3 math ;After UML corrections
Revision 1.8 2015/11/03 09:54:05CET Angadi Hampa (uidu8151) (uidu8151) 
RO: 2875029 ; Merge EMS2 and EMS3 math ; inital checkin
Revision 1.8 2015/11/03 09:54:05CET Angadi Hampa (uidu8151) (uidu8151) 
RO: 2875029 ; Merge EMS2 and EMS3 math ; inital checkin
Revision 1.7 2015/07/20 13:16:32CEST Ganesh Sumangala (uidu8725) (uidu8725) 
RO : 2875029 : FS_0G01_TC2XX_MATH_2.1.0
Update missing functions from EMS2 to EMS3
Revision 1.6 2014/02/03 13:42:58CET uidu8151 
RO:1024108:FS_0G01_TC2XX_AR_MATH_200: Bug Correction & Lint removal
Revision 1.5 2014/01/30 10:47:03CET Angadi Hampa (uidu8151) (uidu8151) 
Bug Correction & Lint removal
Revision 1.4 2013/08/20 06:29:53CEST Angadi Hampa (uidu8151) (uidu8151) 
for release RO 429653 FS_0G01_TC2XX_MATH_100
Revision 1.3 2013/08/20 09:29:00IST Angadi Hampa (uidu8151) (uidu8151) 
Member renamed from ecmath.c_code to ecmath_main.c in project /ES/FS/0A/bsw/stdlib/math/pd_tc2xx/i/project.pj.
Revision 1.2 2013/08/08 07:06:35CEST Angadi Hampa (uidu8151) (uidu8151) 
for release RO 429653 FS_0G01_TC2XX_MATH_100
Revision 1.1 2013/08/05 17:34:00IST Angadi Hampa (uidu8151) (uidu8151) 
Initial revision
Member added to project /ES/FS/0D/bsw/stdlib/tc2xx/math/src_pd/i/project.pj
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
/* ## Module Header End [1d09789f-0cdd-4387-8fe8-a6aeaddd7201] */

/*~E*/
/*~A*/
/*~+:Includes*/
#include "Std_Types.h"
#include "powersar_addon_types.h"
#include "iopt_memmap.h"
#include "ecmath_main.h"
/*~E*/
/*~A*/
/*~+:Macro Definitions*/

#define MATH_MAXITER                                     (16U)          /**< Number of iterations = the resolution of the arctan table */
#define MATH_COSCALE                                     ((uint32)0x11616E8E)  /**< 291597966 = 0.2715717684432241 * 2^30 */
/*~E*/
/*~A*/
/*~+:Private and Public Operations*/
/** This operation shall return the sine of an input angle of type uint16

@param phi Input angle for which sine has to be determined

Range:		00(H)......FFFF(H)
  		      0..1.57077 (pi/2) radians
@return sine (phi)

Range:		00(H)......FFFF(H)
		     0...0.99998 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint16 u16_sin_u16(uint16 phi)
{
	/* ## Operation body start [736fd573-d1ee-42b7-a359-0aec253cb0a5] */
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u16_sin_u16                                                     

         Parameter     type      Hex Range       Physical Range           

Input:                                                                    
         phi           uint16       0 H..ffff H      0..1.57077 (pi/2)       

Output:                                                                   
         res           uint16       0 H..ffff H      0..0.99998              

Functionality:                                                            
        res = sin(phi) -based on CORDIC algorithm                       */

	/*~E*/
	/*~A*/
	/*~+:Description of Lint supression*/
	/* Info 704: Use library functions for shift right and shift left. This PC-Lint info is disabled since a library must never use other libraries */

	/*~E*/
	/*lint -efunc(704, u16_sin_u16)*/
	uint8 i;
	sint32 xtemp;
	sint32 theta;
	sint32 x = (sint32)MATH_COSCALE, y = (sint32)(MATH_COSCALE << 1);

	/* arctan(2^(-i)) table */
	static const uint16 arctantab[] = { 46192, 32768, 19344, 10221, 5188,
			2604,  1303,  652,   326,   163,
			81,    41,    20,    10,    5,
			3,1
	};

	if (phi == 0U)
	{
		/* when phi = 0, the result has to be zero */
		y = 0;
	}
	else
	{
		theta = (sint32)phi - (sint32)arctantab[0];

		/* Iterations(chosen 16) till theta ~= phi. No overflow of any of the used variable is possible. */
		for (i = 0; i < MATH_MAXITER; i++)
		{
			if (theta < (sint8)0)
			{
				xtemp  = x + (y >> i);
				y     -= (x >> i);
				x      = xtemp;
				theta += (sint32)arctantab[i+1U];

			}
			else
			{
				xtemp = x - (y >> i);
				y    += (x >> i);
				x     = xtemp;
				theta -= (sint32)arctantab[i+1U];

			}
		}
		/* Adject the resolution to the resolution of the result*/
		y = y >> 14;
	}
	return (uint16)y;

	/* ## Operation body end [736fd573-d1ee-42b7-a359-0aec253cb0a5] */
}

/** This operation shall return the sine of an input angle of type uint32

@param phi Input angle for which sine has to be determined

Range:		00(H)......FFFFFFFF(H)
		     0...102943.7 (32768pi) radians
@return sine (phi)

Range:		8000(H)......7FFF(H)
		      -1..0.99998 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint16 s16_sin_u32(uint32 phi)
{
	/* ## Operation body start [29e840cf-f608-47d8-8177-56aa77adaec4] */
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s16_sin_u32                                                     

         Parameter     type      Hex Range       Physical Range           

Input:                                                                    
         phi           uint32       0 H..ffffffff H  0..102943.7 (32768 pi)  

Output:                                                                   
         res           sint16       8000 H..7fff H  -1..0.99998              

Functionality:                                                            
        res = sin(phi) -based on CORDIC algorithm                       */

	/*~E*/
	/*~A*/
	/*~+:Description of Lint supression*/
	/* Info 704: Use library functions for shift right and shift left. This PC-Lint info is disabled since a library must never use other libraries */

	/*~E*/
	/*lint -efunc(704, s16_sin_u32)*/

	uint32 tmp_phi = phi;
	sint32 xtemp;
	sint32 theta;
	sint32 sign;
	sint32 x = (sint32)MATH_COSCALE, y = (sint32)(MATH_COSCALE << 1);
	uint8 i;

	/* arctan(2^(-i)) table */
	static const uint16 arctantab[] = { 46192, 32768, 19344, 10221, 5188,
			2604,  1303,  652,   326,   163,
			81,    41,    20,    10,    5,
			3,1
	};

	/* Sign of the result */
	sign = 1 - (((sint32)tmp_phi >> 16) & 2);

	tmp_phi &= 0x1ffffU;

	if (tmp_phi > 0xffffU)
	{
		/* phi within 0.. pi/2 radians */
		tmp_phi = (uint32)0x1ffff - tmp_phi;
	}
	if (tmp_phi == 0U)
	{
		/* when phi = 0, the result has to be zero */
		y = 0;
	}
	else
	{
		theta = (sint32)tmp_phi - (sint32)arctantab[0];

		/* Iterations(chosen 16) till theta ~= phi. No overflow of any of the used variable is possible. */
		for (i = 0; i < MATH_MAXITER; i++)
		{
			if (theta < (sint8)0)
			{
				xtemp  = x + (y >> i);
				y     -= (x >> i);
				x      = xtemp;
				theta += (sint32)arctantab[i+1U];

			}
			else
			{
				xtemp = x - (y >> i);
				y    += (x >> i);
				x     = xtemp;
				theta -= (sint32)arctantab[i+1U];

			}
		}
		/* Adject the resolution to the resolution of the result*/
		y = y >> 15;
		if (sign < (sint8)0)
		{
			y = -y;
		}
	}
	return (sint16)y;

	/* ## Operation body end [29e840cf-f608-47d8-8177-56aa77adaec4] */
}

/** This operation shall return the cosine of an input angle of type uint16

@param phi Input angle for which cosine has to be determined

Range:		00(H)......FFFF(H)
 		    0....1.57077 (pi/2) radians
@return cosine (phi)

Range:		00(H)......FFFF(H)
		    0...0.99998 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint16 u16_cos_u16(uint16 phi)
{
	/* ## Operation body start [eee448bc-f77a-430b-a9f0-fbae59a5760e] */
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u16_cos_u16                                                     

         Parameter     type      Hex Range       Physical Range           

Input:                                                                    
         phi           uint16       0 H..ffff H      0..1.57077 (pi/2)       

Output:                                                                   
         res           uint16       0 H..ffff H      0..0.99998              

Functionality:                                                            
        res = cos(phi) -based on CORDIC algorithm                       */

	/*~E*/
	/*~A*/
	/*~+:Description of Lint supression*/
	/* Info 704: Use library functions for shift right and shift left. This PC-Lint info is disabled since a library must never use other libraries */

	/*~E*/
	/*lint -efunc(704, u16_cos_u16)*/

	uint8 i;
	sint32 xtemp;
	sint32 theta;
	sint32 x = (sint32)MATH_COSCALE, y = (sint32)(MATH_COSCALE << 1);

	/* arctan(2^(-i)) table */
	static const uint16 arctantab[] = { 46192, 32768, 19344, 10221, 5188,
			2604,  1303,  652,   326,   163,
			81,    41,    20,    10,    5,
			3,1
	};

	theta = (sint32)phi - (sint32)arctantab[0];

	/* Iterations(chosen 16) till theta ~= phi. No overflow of any of the used variable is possible. */
	for (i = 0; i < MATH_MAXITER; i++)
	{
		if (theta < 0)
		{
			xtemp  = x + (y >> i);
			y     -= (x >> i);
			x      = xtemp;
			theta += (sint32)arctantab[i+1U];

		}
		else
		{
			xtemp = x - (y >> i);
			y    += (x >> i);
			x     = xtemp;
			theta = theta - (sint32)arctantab[i+1U];

		}
	}
	/* Adject the resolution to the resolution of the result*/
	return (uint16)(x >> 14);

	/* ## Operation body end [eee448bc-f77a-430b-a9f0-fbae59a5760e] */
}

/** This operation shall return the cosine of an input angle of type uint32

@param phi Input angle for which cosine has to be determined

Range:		00(H)......FFFFFFFF(H)
		     0...102943.7 (32768pi) radians
@return cosine (phi)

Range:		8000(H)......7FFF(H)
		      -1..0.99998 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint16 s16_cos_u32(uint32 phi)
{
	/* ## Operation body start [39afff9c-2977-46fe-9091-11c85653ed97] */
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s16_cos_u32                                                     

         Parameter     type      Hex Range       Physical Range           

Input:                                                                    
         phi           uint32       0 H..ffffffff H  0..102943.7 (32768 pi)  

Output:                                                                   
         res           sint16       8000 H..7fff H  -1..0.99998              

Functionality:                                                            
        res = cos(phi) -based on CORDIC algorithm                       */

	/*~E*/
	/*~A*/
	/*~+:Description of Lint supression*/
	/* Info 704: Use library functions for shift right and shift left. This PC-Lint info is disabled since a library must never use other libraries */

	/*~E*/
	/*lint -efunc(704, s16_cos_u32)*/

	uint32 tmp_phi = phi;
	sint32 xtemp;
	sint32 theta;
	sint32 x = (sint32)MATH_COSCALE, y = (sint32)(MATH_COSCALE << 1);
	uint8 i;

	/* arctan(2^(-i)) table */
	static const uint16 arctantab[] = { 46192, 32768, 19344, 10221, 5188,
			2604,  1303,  652,   326,   163,
			81,    41,    20,    10,    5,
			3,1
	};

	/* Sign of the result */
	sint32 sign = 1;

	/* cos(2*pi*n + phi) = cos(phi)*/
	tmp_phi &= 0x3ffffU;

	if (tmp_phi > 0x2ffffU)
	{
		tmp_phi = (uint32)0x3ffff-tmp_phi;
		/*sign is 1 (initialization)*/
	}
	else
	{
		if (tmp_phi > 0x1ffffU)
		{
			tmp_phi = tmp_phi - 0x20000U;
			sign = -1;

		}
		else
		{
			if (tmp_phi > 0xffffU)
			{
				tmp_phi = (uint32)0x1ffff - tmp_phi;
				sign = -1;

			}
			else
			{
				/*sign is 1 (initialization)*/

			}
		}
	}
	theta = (sint32)tmp_phi - (sint32)arctantab[0];

	/* Iterations(chosen 16) till theta ~= phi. No overflow of any of the used variable is possible. */
	for (i = 0; i < MATH_MAXITER; i++)
	{
		if (theta < (sint8)0)
		{
			xtemp  = x + (y >> i);
			y     -= (x >> i);
			x      = xtemp;
			theta += (sint32)arctantab[i+1U];

		}
		else
		{
			xtemp = x - (y >> i);
			y    += (x >> i);
			x     = xtemp;
			theta -= (sint32)arctantab[i+1U];

		}
	}
	/* Resolution adjustment of the result */
	x = x >> 15;
	if (sign < (sint8)0)
	{
		x = -x;
	}
	return (sint16)x;

	/* ## Operation body end [39afff9c-2977-46fe-9091-11c85653ed97] */
}

/** This operation shall return the tangent of an input angle of type uint16

@param phi Input angle for which tangent has to be determined

Range:		00(H)......FFFF(H)
 		   0..1.57077 (pi/2) radians
@return tangent (phi)

Range:		00(H)......FFFF(H)
		   0..15.999756 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint16 u16_tan_u16(uint16 phi)
{
	/* ## Operation body start [69dcc188-db5b-4c1b-9af6-6d0d1c9e7de5] */
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u16_tan_u16                                                     

         Parameter     type      Hex Range       Physical Range           

Input:                                                                    
         phi           uint16       0 H..ffff H      0..1.57077 (pi/2)       

Output:                                                                   
         res           uint16       0 H..ffff H      0..15.999756            

Functionality:                                                            
        res = tan(phi) -based on CORDIC algorithm                       */

	/*~E*/
	/*~A*/
	/*~+:Description of Lint supression*/
	/* Info 704: Use library functions for shift right and shift left. This PC-Lint info is disabled since a library must never use other libraries */

	/*~E*/
	/*lint -efunc(704, u16_tan_u16)*/

	uint8 i;
	sint32 xtemp;
	sint32 theta;
	sint32 x = (sint32)MATH_COSCALE, y = (sint32)(MATH_COSCALE << 1);

	/* arctan(2^(-i)) table */
	static const uint16 arctantab[] = { 46192, 32768, 19344, 10221, 5188,
			2604,  1303,  652,   326,   163,
			81,    41,    20,    10,    5,
			3,1
	};

	theta = (sint32)phi - (sint32)arctantab[0];

	/* Iterations(chosen 16) till theta ~= phi. No overflow of any of the used variable is possible. */
	for (i = 0; i < MATH_MAXITER; i++)
	{
		if (theta < 0)
		{
			xtemp  = x + (y >> i);
			y     -= (x >> i);
			x      = xtemp;
			theta += (sint32)arctantab[i+1U];

		}
		else
		{
			xtemp = x - (y >> i);
			y    += (x >> i);
			x     = xtemp;
			theta -= (sint32)arctantab[i+1U];

		}
	}
	/*Adjust to the resolution of the result*/
	x = x >> 12;

	y = y/x;

	if (y > (sint32)0xffff)
	{
		y = 0xffff;
	}
	return (uint16)y;

	/* ## Operation body end [69dcc188-db5b-4c1b-9af6-6d0d1c9e7de5] */
}

/** This operation shall return the tangent of an input angle of type uint32

@param phi Input angle for which tangent has to be determined

Range:		00(H)......FFFFFFFF(H)
 		   0...102943.7 (32768pi) radians
@return tangent (phi)

Range:		8000(H)......7FFF(H)
                           -16..15.999512
 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint16 s16_tan_u32(uint32 phi)
{
	/* ## Operation body start [33f46f49-ee21-4242-b429-6fc3b52b0e33] */
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s16_tan_u32                                                     

         Parameter     type      Hex Range       Physical Range           

Input:                                                                    
         phi           uint32       0 H..ffffffff H   0..102943.7 (32768 pi) 

Output:                                                                   
         res           sint16       8000 H..7fff H   -16..15.999756          

Functionality:                                                            
        res = tan(phi) -based on CORDIC algorithm                       */

	/*~E*/
	/*~A*/
	/*~+:Description of Lint supression*/
	/* Info 704: Use library functions for shift right and shift left. This PC-Lint info is disabled since a library must never use other libraries */

	/*~E*/
	/*lint -efunc(704, s16_tan_u32)*/

	uint32 tmp_phi = phi;
	sint32 xtemp;
	sint32 theta;
	sint32 x = (sint32)MATH_COSCALE, y = (sint32)(MATH_COSCALE << 1);
	uint8 i;

	/* arctan(2^(-i)) table */
	static const uint16 arctantab[] = { 46192, 32768, 19344, 10221, 5188,
			2604,  1303,  652,   326,   163,
			81,    41,    20,    10,    5,
			3,1
	};

	/* Sign of the result */
	sint32 sign = 1;

	/* tan(2*pi*n + phi) = tan(phi)*/
	tmp_phi &= 0x3ffffU;

	if (tmp_phi > 0x2ffffU)
	{
		tmp_phi = (uint32)0x3ffff-tmp_phi;
		sign = -1;
	}
	else
	{
		if (tmp_phi > 0x1ffffU)
		{
			tmp_phi = tmp_phi - 0x20000U;
			/*sign is 1 (initialization)*/

		}
		else
		{
			if (tmp_phi > 0xffffU)
			{
				tmp_phi = (uint32)0x1ffff - tmp_phi;
				sign = -1;

			}
			else
			{
				/*sign is 1 (initialization)*/

			}
		}
	}
	theta = (sint32)tmp_phi - (sint32)arctantab[0];

	/* Iterations(chosen 16) till theta ~= phi. No overflow of any of the used variable is possible. */
	for (i = 0; i < MATH_MAXITER; i++)
	{
		if (theta < 0)
		{
			xtemp  = x + (y >> i);
			y     -= (x >> i);
			x      = xtemp;
			theta += (sint32)arctantab[i+1U];

		}
		else
		{
			xtemp = x - (y >> i);
			y    += (x >> i);
			x     = xtemp;
			theta -= (sint32)arctantab[i+1U];

		}
	}
	/*Adjust to the resolution of the result*/
	x = x >> 11;
	y = y/x;

	if (y > (sint16)0x7fff)
	{
		y = 0x7fff;
	}
	if (sign < 0)
	{
		y = -y;
	}
	return (sint16)y;

	/* ## Operation body end [33f46f49-ee21-4242-b429-6fc3b52b0e33] */
}

/** This operation shall return the square root value (uint16) of the uint32 parameter passed as the input

@param input input parameter for which square root has to be determined

Range:		0x00....0xFFFFFFFF
		   0.....4294967295
@return Square root (input)

Range:		0x00....0xFFF
		   0.....65535 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint16 u16_sqrt_u32(uint32 input)
{
	/* ## Operation body start [46c6a6cf-a1ce-4e69-bdc0-f41e751daee1] */
	/*~A*/
	/*~+:Description*/
	/*Calculates the integer square root of an unsigned 32-bit Input Value
The routine is implemented using a nested-interval algorithm.

Parameters used:                                                   


         Parameter     type      Hex Range       Physical Range    

Input:                                                             
         input          uint32     0..FFFFFFFFH    0..4294967295      
Output:                                                            
         result         uint16     0..FFFFH        0..65535           

Functionality:                                                     
        result = squareroot(input)                                 
	 */

	/*~E*/
	sint16 count;
	uint16 temp_val1;
	uint16 temp_val2 = 0;

	for (count = 15; count >= 0; count--)
	{
		temp_val1 = temp_val2 | (uint16)( (uint32)1 << (uint16)count);

		/* Perfect Squares Found which is less than or equal to the Given Input*/
		if (((uint32)temp_val1 * temp_val1) <= input)
		{
			/* Perfect Square roots are made into a temporary Variable*/
			temp_val2 = temp_val1;

		}
	}
	return temp_val2;


	/* ## Operation body end [46c6a6cf-a1ce-4e69-bdc0-f41e751daee1] */
}

/** This operation shall calculate the new floating average of type sint16 with a sint16 value as old floating average, a sint16 value as actual measured value and a sint16 value (-1...0.99997) as average value

@param gmw Old floating average

Range:		8000(H).....7FFF(H)
		 -32768......32767
@param messwert Actual measured value

Range:		8000(H).....7FFF(H)
		 -32768......32767
@param mitko Constant value

Range:		8000(H).....7FFF(H)
		    -1......0.99997
@return result = gmw + ((( messwert - gmw) * mitko) >> 15), result rounded off

result is corrected for moving mean value saturation using the following logic
	if (result=gmw)
	{	
		if  ((( messwert - gmw) * mitko) > 0)
		{
			result++
		}
		else if  ((( messwert - gmw) * mitko) < 0)
		{
			result--
		}
	}

Limit overflow to: 7FFF H (32767)
Limit underflow to: 8000 H (-32768)

Range: 		8000(H).....7FFF(H)
	              -32768.....32767 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint16 s16_mmv_s16_s16_s16_fac1(sint16 gmw, sint16 messwert, sint16 mitko)
{
	/* ## Operation body start [3ad916e4-f773-419c-9d7f-55ccbab2a41d] */
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s16_mmv_s16_s16_s16_fac1                                        

         Parameter         type      Hex Range       Physical Range       

Input:                                                                    
         gmw                sint16    8000....7FFF      -32768....32767      
         messwert           sint16    8000....7FFF      -32768....32767      
         mitko              sint16    8000....7FFF          -1....0.9999     

Output:                                                                   
         rueckgabe          sint16    8000....7FFF      -32768....32767      

Functionality:                                                            
         rueckgabe= gmw + (((messwert-gmw) * mitko) >> 15) with round off 
         If  ( ((( messwert - gmw) * mitko) >> 15)==0)                    
              If  ((( messwert - gmw) * mitko) > 0)                       
                  result++                                                
              Elseif  ((( messwert - gmw) * mitko) < 0)                   
                  result--                                                
              Endif                                                       
         Endif                                                            
         Limit  overflow  to  :7FFFH(32767)                               
         Limit  underflow  to :8000H(-32768)                              
	 */

	/*~E*/
	sint32 temp, quotient;
	sint16 res_ret;
	sint32 tmp_gmw = gmw, tmp_messwert = messwert;
	temp = ( tmp_messwert - tmp_gmw ) * mitko;

	/* Check if there is any increase in mmv value */
	if ( temp > 0 )
	{
		/* Calculate value to be added (with round-off) */
		quotient =  ((temp / (sint32)32768 ) + (( 2 * ( temp % (sint32)32768 )) / (sint32)32768));
		/* Check for saturation */
		if (quotient == (sint8)0)
		{
			/* Do Saturation correction  */
			quotient += (sint8)1;

		}
	}
	else
	{
		/* Check if there is any decrease in mmv value */
		if ( temp < (sint8)0 )
		{
			/* Calculate value to be subtracted (with round-off) */
			temp = -temp;
			quotient =  ((temp / (sint32)32768 ) + (( 2 * ( temp % (sint32)32768 )) / (sint32)32768));
			if (quotient == (sint8)0)
			{
				/*  Do Saturation correction */
				quotient -= (sint8)1;

			}
			else
			{
				quotient = - quotient;
			}
		}
		else
		{
			/* Convergence reached. */
			quotient = 0;

		}
	}
	/* Calculate new mmv */
	temp = tmp_gmw + quotient;
	/* Check for overflow */
	if ( temp >= S16_MAX )
	{
		res_ret =  S16_MAX;
	}
	else
	{
		/* Check for underflow */
		if ( temp <= S16_MIN )
		{
			res_ret =  S16_MIN;
		}
		else
		{
			res_ret =  (sint16)temp;
		}
	}
	return res_ret;
	/* ## Operation body end [3ad916e4-f773-419c-9d7f-55ccbab2a41d] */
}

/** This operation shall calculate the new floating average of type uint16 with an uint16 value as old floating average, an uint16 value as actual measured value and a sint16 value (-1...0.99997) as average value

@param gmw Old floating average

Range:		00(H).....FFFF(H)
	 	   0......65535
@param messwert Actual measured value

Range:		00(H).....FFFF(H)
	 	   0......65535
@param mitko Constant value

Range:		8000(H).....7FFF(H)
		    -1......0.99997
@return result = gmw + ((( messwert - gmw) * mitko) >> 15), result rounded off

result is corrected for moving mean value saturation using the following logic
	if  (result=gmw)
	{
		if  ((( messwert - gmw) * mitko) > 0)
		{
			result++
		}
		else if  ((( messwert - gmw) * mitko) < 0)
		{
			result--
		}
	}

Limit overflow to: FFFF H (65535)
Limit underflow to: 0000 H (0)

Range: 		0000...FFFF H
		     0...65535 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint16 u16_mmv_u16_u16_s16_fac1(uint16 gmw, uint16 messwert, sint16 mitko)
{
	/* ## Operation body start [bc1928cf-a69b-40c4-8181-d125d3a65a45] */
	/*~A*/
	/*~+:Description*/
	/*
                                                                            FUNCTION: u16_mmv_u16_u16_s16_fac1                                             

                                                                            Parameter         type          Hex Range         Physical Range      

                                                                            Input:                                                                         
                                                                            gmw                uint16          0....FFFF           0....65535        
                                                                            messwert           uint16          0....FFFF           0....65535        
                                                                            mitko              sint16       8000....7FFF          -1....0.9999       

                                                                            Output:                                                                        
                                                                            rueckgabe          uint16          0....FFFF           0....65535        

                                                                            Functionality:                                                                 
                                                                            rueckgabe= gmw + (((messwert-gmw) * mitko) >> 15) with round off      
                                                                            If  ( ((( messwert - gmw) * mitko) >> 15)==0)                         
                                                                            If  ((( messwert - gmw) * mitko) > 0)                            
                                                                            result++                                                     
                                                                            Elseif  ((( messwert - gmw) * mitko) < 0)                        
                                                                            result--                                                     
                                                                            Endif                                                            
                                                                            Endif                                                                 
                                                                            Limit  overflow  to  :FFFFH(65535)                                    
                                                                            Limit  underflow  to :0000H(0)                                        
	 */

	/*~E*/
	sint32 temp, quotient;
	uint32 tmp_gmw = gmw, tmp_messwert = messwert;
	uint16 res_ret;
	temp = (((sint32)tmp_messwert - (sint32)tmp_gmw ) * (sint32)mitko);

	/* Check if there is any increase in mmv value */
	if ( temp > (sint8)0 )
	{
		quotient =  ((temp / (sint32)32768 ) + (( 2 * ( temp % (sint32)32768 )) / (sint32)32768));
		/* Check for saturation */
		if ( quotient == (sint8)0 )
		{
			/* Do Saturation correction */
			quotient += (sint8)1;

		}
	}
	else
	{
		/* Check if there is any decrease in mmv value */
		if ( temp < (sint8)0 )
		{
			temp = -temp;
			quotient =  ((temp / (sint32)32768 ) + (( 2 * ( temp % (sint32)32768 )) / (sint32)32768));
			/* Check for saturation */
			if ( quotient == (sint8)0)
			{
				/* Do Saturation correction */
				quotient -= (sint8)1;

			}
			else
			{
				quotient = - quotient;
			}
		}
		else
		{
			/* Convergence reached. */
			quotient = 0;

		}
	}
	/* Calculate new mmv */
	temp = ((sint32)tmp_gmw + quotient);
	/* Check for overflow */
	if ( temp >= (sint32)U16_MAX )
	{
		res_ret =  U16_MAX;
	}
	else
	{
		/* Check for underflow */
		if ( temp <= (sint32)U16_MIN )
		{
			res_ret =  U16_MIN;
		}
		else
		{
			res_ret =  (uint16)temp;
		}
	}

	return res_ret ;
	/* ## Operation body end [bc1928cf-a69b-40c4-8181-d125d3a65a45] */
}

/** This operation shall calculate the new floating average of type uint16 with an uint16 value as old floating average, an uint16 value as actual measured value and an uint16 value (0...1.99997) as average value

@param gmw Old floating average

Range:		00(H).....FFFF(H)
	 	   0......65535
@param messwert Actual measured value

Range:		00(H).....FFFF(H)
	 	   0......65535
@param mitko Constant value

Range:		00(H).....FFFF(H)
		    0...1.99997
@return result = gmw + ((( messwert - gmw) * mitko) >> 15), result rounded off

result is corrected for moving mean value saturation using the following logic
	if  (result=gmw)
	{
		if  ((( messwert - gmw) * mitko) > 0)
		{
			result++
		}
		else if  ((( messwert - gmw) * mitko) < 0)
		{
			result--
		}
	}

Limit overflow to: FFFF H (65535)
Limit underflow to: 0000 H (0)

Range: 		00(H)...FFFF(H)
		    0...65535 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint16 u16_mmv_u16_u16_u16_fac2(uint16 gmw, uint16 messwert, uint16 mitko)
{
	/* ## Operation body start [a4bb1fa7-5bff-4b03-afc9-2a601e4aeb29] */
	/*~A*/
	/*~+:Description*/
	/*
                                                                       FUNCTION: u16_mmv_u16_u16_u16_fac2                                        

                                                                       Parameter         type      Hex Range       Physical Range       

                                                                       Input:                                                                    
                                                                       gmw                uint16      0....FFFF         0....65535         
                                                                       messwert           uint16      0....FFFF         0....65535         
                                                                       mitko              uint16      0....FFFF         0....1.9999        

                                                                       Output:                                                                   
                                                                       rueckgabe          uint16      0....FFFF         0....65535         

                                                                       Functionality:                                                            
                                                                       rueckgabe= gmw + (((messwert-gmw) * mitko) >> 15) with round off 
                                                                       If  ( ((( messwert - gmw) * mitko) >> 15)==0)                    
                                                                       If  ((( messwert - gmw) * mitko) > 0)                       
                                                                       result++                                                
                                                                       Elseif  ((( messwert - gmw) * mitko) < 0)                   
                                                                       result--                                                
                                                                       Endif                                                       
                                                                       Endif                                                            
                                                                       Limit  overflow  to  :FFFFH(65535)                               
                                                                       Limit  underflow  to :0000H(0)                                   
	 */

	/*~E*/
	/*FUNCTION_ID:3*/
	uint32 temp;
	sint32 quotient;
	uint16 res_ret;
	uint32 tmp_gmw = gmw,tmp_messwert = messwert;

	if ( tmp_messwert >= tmp_gmw )
	{
		/* Calculate increase in mmv value*/
		temp = ( (tmp_messwert - tmp_gmw) * (uint32)mitko );

		/* Rounding-off the mmv increase */
		quotient  = (sint32)((temp / (uint32)32768) + (( 2U * (temp % (uint32)32768) ) / (uint32)32768));

		/* Check for saturation */
		if ( (quotient == 0) && (temp >= 1U) )
		{
			/* Do Saturation correction */
			quotient =  (sint32)(tmp_gmw + 1U);
		}
		else
		{
			/* Saturation not reached */
			quotient = ((sint32)tmp_gmw + quotient);
		}
	}
	else
	{
		/* Calculate decrease in mmv value */
		temp = ( (tmp_gmw - tmp_messwert) * (uint32)mitko );

		/* Rounding-off the mmv decrease */
		quotient = (sint32)((temp / (uint32)32768) + (( 2U * (temp % (uint32)32768) ) / (uint32)32768));

		/* Check for saturation */
		if ( (quotient == 0) && (temp >= 1U) )
		{
			/* Do Saturation correction */
			quotient = (sint32) (tmp_gmw - 1U);
		}
		else
		{
			/* Saturation not reached */
			quotient = ((sint32)tmp_gmw - quotient);
		}
	}
	/* Check for ovewrflow */
	if ( quotient >= (sint32)U16_MAX )
	{
		res_ret =  U16_MAX;
	}
	else
	{
		/* Check for underflow */
		if ( quotient <= (sint32)U16_MIN )
		{
			res_ret =  U16_MIN;
		}
		else
		{
			res_ret =  (uint16)quotient;
		}
	}
	return res_ret ;
	/* ## Operation body end [a4bb1fa7-5bff-4b03-afc9-2a601e4aeb29] */
}

/** This operation shall calculate the new floating average of type uint32 with an uint32 value as old floating average, an uint16 value as actual measured value and an uint16 value (0...0.999985) as average value

@param gmw Old floating average

Range:		00(H).....FFFFFFFF(H)
	 	   0......4294967295
@param messwert Actual measured value

Range:		00(H).....FFFF(H)
	 	   0......65535
@param mitko Constant value

Range:		00(H).....FFFF(H)
		   0...0.999985
@return gmw + ((messwert - gmw.HIGH) * mitko)
if ((messwert - gmw.HIGH) == 0)
{
	result.HIGH = gmw.HIGH
	result.LOW = 8000H 
}

Range: 		00(H)...FFFFFFFF(H)
		    0...4294967295

 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint32 u32_mmv_u32_u16_u16_fac1(uint32 gmw, uint16 messwert, uint16 mitko)
{
	/* ## Operation body start [f0b9883f-04fc-4700-a569-918431257a14] */
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION:  u32_mmv_u32_u16_u16_fac1                                         

         Parameter      type       Hex Range     Physical Range           

Input:                                                                    
         gmw            uint32     0....FFFFFFFF    0....4294967295          
         messwert       uint16     0....FFFF        0....65535               
         mitko          uint16     0....FFFF        0....0.999985            

Output:                                                                   
         rueckgabe      uint32     0....FFFFFFFF    0....4294967295          

Functionality:                                                            
         rueckgabe= gmw + ((messwert-gmw.HIGH) * mitko)                   
              if ((messwert - gmw.HIGH) == 0)                             
                 result.HIGH = gmw.HIGH                                   
                 result.LOW = 8000H                                       
	 */

	/*~E*/
	uint32  temp;
	temp = (uint32)gmw / (uint32)65536;

	if ((messwert - temp) == 0U)
	{
		temp = ((gmw & (uint32)0xFFFF0000) | (0x00008000U));
	}
	else
	{
		if (messwert >= temp)
		{
			temp  = ((uint32)messwert - (uint32)temp);
			temp  = temp *(uint32)mitko;
			temp = gmw + (uint32)temp ;
		}
		else
		{
			temp  = ((uint32)temp - (uint32)messwert);
			temp  = temp *(uint32)mitko;
			temp = gmw - (uint32)temp ;
		}
	}
	return temp;
	/* ## Operation body end [f0b9883f-04fc-4700-a569-918431257a14] */
}

/** This operation shall calculate the new floating average of type sint16 with a sint16 value as old floating average, a sint16 value as actual measured value and an uint16 value (0...0.999985) as average value

@param mmv Old floating average

Range:		8000(H).....7FFF(H)
		 -32768......32767
@param measure Actual measured value

Range:		8000(H).....7FFF(H)
		 -32768......32767
@param crlc Constant value

Range:		00(H).....FFFF(H)
		     0...0.999985
@return result = mmv + ((( measure - mmv) * crlc) >> 16), result rounded off

result is corrected for moving mean value saturation using the following logic
	if  (result=gmw)
	{
		if  ((( measure - mmv) * crlc) > 0)
		{
			result++
		}
		else if  ((( measure - mmv) * crlc) < 0)
		{
			result--
		}
	}

Limit overflow to: 7FFF H (32767)
Limit underflow to: 8000 H (-32768)

Range: 		8000(H).....7FFF(H)
	              -32768.....32767 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint16 s16_mmv_s16_s16_u16_fac1(sint16 mmv, sint16 measure, uint16 crlc)
{
	/* ## Operation body start [90e1444f-048d-41fa-88d2-0b8cd292f081] */
	/*~A*/
	/*~+:Description*/
	/*
                                                                       FUNCTION:  s16_mmv_s16_s16_u16_fac1                                      

                                                                       Parameter         type      Hex Range     Physical Range         

                                                                       Input:                                                                    
                                                                       mmv                sint16    8000....7FFF   -32768....32767         
                                                                       measure            sint16    8000....7FFF   -32768....32767         
                                                                       crlc               uint16       0....FFFF       0....0.9999         

                                                                       Output:                                                                   
                                                                       result             sint16    8000....7FFF   -32768....32767         

                                                                       Functionality:                                                            
                                                                       mmv+(((measure-mmv)*crlc)>>16)  with round off                   
                                                                       If  ( ((( messwert - gmw) * mitko) >> 16)==0)                    
                                                                       If  ((( messwert - gmw) * mitko) > 0)                       
                                                                       result++                                                
                                                                       Elseif  ((( messwert - gmw) * mitko) < 0)                   
                                                                       result--                                                
                                                                       Endif                                                       
                                                                       Endif                                                            
	 */

	/*~E*/
	uint32 temp,quotient;
	sint16 res_ret;
	sint32 tmp_mmv = mmv,tmp_measure = measure;

	if ( tmp_measure >= tmp_mmv )
	{
		/* Calculate increase in mmv value */
		temp = ( (uint32)(tmp_measure - tmp_mmv) * (uint32)crlc );

		/* Rounding-off the mmv increase */
		quotient  = (temp / (uint32)65536 ) + ( (2U * (temp % (uint32)65536)) / (uint32)65536);

		/* Check for saturation */
		if ( (quotient == 0U) && (temp >= 1U) )
		{
			/* Do Saturation correction*/
			res_ret =  (sint16)(tmp_mmv + 1);
		}
		else
		{
			/*Saturation not reached*/
			res_ret =  (sint16)(tmp_mmv + (sint32)quotient);
		}
	}
	else
	{
		/* Calculate decrease in mmv value */
		temp = ( (uint32)(tmp_mmv - tmp_measure) * (uint32)crlc );

		/* Rounding-off the mmv decrease */
		quotient = (temp / (uint32)65536) + (( 2U * (temp % (uint32)65536) ) / (uint32)65536);

		if ( (quotient == 0U) && (temp >= 1U) )
		{
			/* Do Saturation correction */
			res_ret =  (sint16)(tmp_mmv - 1);
		}
		else
		{
			/* Saturation not reached*/
			res_ret =  (sint16)(tmp_mmv - (sint32)quotient);
		}
	}
	return res_ret ;
	/* ## Operation body end [90e1444f-048d-41fa-88d2-0b8cd292f081] */
}

/** This operation shall calculate the new floating average of type sint32 with a sint32 value as old floating average, a sint16 value as actual measured value and an uint16 value (0...0.999985) as average value

@param mmv Old floating average

Range:		80000000(H) ......7FFFFFFF(H)
		 -2147483648......2147483647
@param measure Actual measured value

Range:		8000(H).....7FFF(H)
		 -32768......32767
@param crlc Constant value

Range:		00(H).....FFFF(H)
		     0...0.999985
@return mmv + ((measure - mmv.HIGH) * crlc)
if ((measure - mmv.HIGH) == 0)
{
	result.HIGH = mmv.HIGH
	result.LOW = 8000H
}

Range:		80000000(H) ......7FFFFFFF(H)
		 -2147483648......2147483647

 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint32 s32_mmv_s32_s16_u16_fac1(sint32 mmv, sint16 measure, uint16 crlc)
{
	/* ## Operation body start [d8e7ae13-49f9-4fad-845f-098c73ae6035] */
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION:  s32_mmv_s32_s16_u16_fac1                                                

         Parameter     type         Hex Range              Physical Range        

Input:                                                                           
         mmv           sint32    80000000....7FFFFFFF   -2147483648....+2147483647  
         measure       sint16        8000....7FFF            -32768....+32767       
         crlc          uint16           0....FFFF                 0....+0.99998     

Output:                                                                          
         res           sint32    80000000....7FFFFFFF   -2147483648....+2147483647  

Functionality:                                                                   
         res = mmv + ((messwert-mmv.HIGH) * crlc)                                
         if ((measure - mmv.HIGH) == 0)                                          
              result.HIGH = mmv.HIGH                                             
              result.LOW = 8000H                                                 
	 */

	/*~E*/
	/*~A*/
	/*~+:Description of Lint supression*/
	/* Info 704: Use library functions for shift right and shift left. This PC-Lint info is disabled since a library must never use other libraries */

	/*~E*/
	/*uint16 temp;*/
	sint32 tmp_mmv =  mmv;
	sint16 mmv_high;

	mmv_high = /*lint --e(704) */(sint16)(mmv>>16);

	if (measure == mmv_high)
	{
		tmp_mmv =(tmp_mmv & (sint32)0xffff0000)|(0x8000);

	}
	else
	{
		if (measure > mmv_high)
		{
			/*temp = measure - mmv_high;*/
			tmp_mmv = tmp_mmv + (((sint32)measure - mmv_high)*(sint32)crlc);
		}
		else
		{
			/* temp = mmv_high - measure;*/
			tmp_mmv = tmp_mmv - ((mmv_high - (sint32)measure)*(sint32)crlc);
		}
	}
	return(tmp_mmv);

	/* ## Operation body end [d8e7ae13-49f9-4fad-845f-098c73ae6035] */
}

/** This operation shall calculate the new floating average of type uint16 with an uint16 value as old floating average, an uint16 value as actual measured value and an uint16 value (0...0.999985) as average value

@param mmv Old floating average

Range:		00(H).....FFFF(H)
	 	   0......65535
@param measure Actual measured value
If the measurement has the type char, shift it 8 bits to the left. XX(H)  --> XX00(H)

Range:		00(H).....FFFF(H)
	 	   0......65535
@param crlc Constant value
If the average value has the type char, shift it 8 bits to the left. XX(H)  --> XX00(H)

Range:		00(H)...FFFF(H)
	               0...0.999985
@return result = mmv + ((( measure - mmv) * crlc) >> 16),	Result rounded off

result is corrected for moving mean value saturation using the following logic
	if  (result=gmw)
	{
		if  ((( measure - mmv) * crlc) > 0)
		{
			result++
		}
		else if  ((( measure - mmv) * crlc) < 0)
		{
			result--
		}
	}

Limit overflow to: 0xFFFF (65535)
Limit underflow to: 0x00 (0)

Range: 		00(H).....FFFF(H)
	                  0...65535 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint16 u16_mmv_u16_u16_u16_fac1(uint16 mmv, uint16 measure, uint16 crlc)
{
	/* ## Operation body start [9091c178-df59-4d34-9d9b-3b5842a63de1] */
	uint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
                                                                       FUNCTION:  u16_mmv_u16_u16_u16_fac1                                    

                                                                       Parameter     type       Hex Range     Physical Range            

                                                                       Input:                                                                    
                                                                       mmv           uint16       0....FFFF       0....65535               
                                                                       measure       uint16       0....FFFF       0....65535               
                                                                       crlc          uint16       0....FFFF       0....0.99998             

                                                                       Output:                                                                   
                                                                       result        uint16       0....FFFF       0....65535               

                                                                       Functionality:                                                            
                                                                       mmv+(((measure-mmv)*crlc)>>16)  with round off                   
                                                                       If  ( ((( messwert - gmw) * mitko) >> 16)==0)                    
                                                                       If  ((( messwert - gmw) * mitko) > 0)                       
                                                                       result++                                                
                                                                       Elseif  ((( messwert - gmw) * mitko) < 0)                   
                                                                       result--                                                
                                                                       Endif                                                       
                                                                       Endif                                                            

	 */

	/*~E*/
	uint32 temp,quotient;
	uint32 tmp_mmv = mmv,tmp_measure = measure;

	if ( tmp_measure >= tmp_mmv )
	{
		/* Calculate increase in mmv value */
		temp = ( (tmp_measure - tmp_mmv) * (uint32)crlc );

		/* Rounding-off the mmv increase */
		quotient = (temp / (uint32)65536) + (( 2U * (temp % (uint32)65536) ) / (uint32)65536);

		/* Check for saturation */
		if ( (quotient == 0U) && (temp >= 1U) )
		{
			/* Do Saturation correction */
			res_ret =  (uint16)(tmp_mmv + 1U);
		}
		else
		{
			/*Saturation not reached*/
			res_ret =  (uint16)(tmp_mmv + quotient);
		}
	}
	else
	{
		/* Calculate decrease in mmv value */
		temp = ( (tmp_mmv - tmp_measure) * (uint32)crlc );

		/* Rounding-off the mmv decrease */
		quotient = (temp / (uint32)65536) + (( 2U * (temp % (uint32)65536) ) / (uint32)65536);

		/* Check for saturation */
		if ( (quotient == 0U) && (temp >= 1U) )
		{
			/* Do Saturation correction */
			res_ret =  (uint16)(tmp_mmv - 1U);
		}
		else
		{
			/*Saturation not reached*/
			res_ret =  (uint16)(tmp_mmv - quotient);
		}
	}
	return res_ret ;
	/* ## Operation body end [9091c178-df59-4d34-9d9b-3b5842a63de1] */
}

/** This operation shall calculate the new floating average of type uint32 with an uint32 value as old floating average, an uint32 value as actual measured value and an uint32 value (0...0.999985) as average value

@param mmv Old floating average

Range:		00(H).....FFFFFFFF(H)
	 	   0......4294967295
@param measure Actual measured value

Range:		00(H).....FFFFFFFF(H)
	 	   0......4294967295
@param crlc Constant value

Range:		00(H).....FFFFFFFF(H)
	 	      0...0.999985
@return result = mmv + (((measure - mmv) * crlc) >> 32), result  rounded  off

result is corrected for moving mean value saturation using the following logic
	if  (result = mmv)
	{
		if  (((measure - mmv) * crlc) > 0)
		{
			result++
		}
		else if  (((measure - mmv) * crlc) < 0)
		{
			result--
		}
	}

Range:	 	00(H)......FFFFFFFF(H)
		     0...4294967295 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint32 u32_mmv_u32_u32_u32_fac1(uint32 mmv, uint32 measure, uint32 crlc)
{
	/* ## Operation body start [9d4a75a1-f69e-46a2-90a2-41a594801571] */
	/*~A*/
	/*~+:Description*/
	/*
                                                                         FUNCTION:  u32_mmv_u32_u32_u32_fac1                                            

                                                                         Parameter         type      Hex Range      Physical Range         

                                                                         Input:                                                                     
                                                                         mmv                uint32    0....FFFFFFFF   0....+4294967295        
                                                                         measure            uint32    0....FFFFFFFF   0....+4294967295        
                                                                         crlc               uint32    0....FFFFFFFF   0....+0.99999           

                                                                         Output:                                                                    
                                                                         result             uint32    0....FFFFFFFF   0....+4294967295        

                                                                         Functionality:                                                             
                                                                         result = mmv+(((measure-mmv)*crlc)>>32)  with round off           
                                                                         If  ( ((( measure - mmv) * crlc) >> 32)==0)                       
                                                                         If  ((( measure - mmv) * crlc) > 0)                          
                                                                         result++                                                 
                                                                         Elseif  ((( measure - mmv) * crlc) < 0)                      
                                                                         result--                                                 
                                                                         Endif                                                        
                                                                         Endif                                                             

	 */

	/*~E*/
	uint64 temp;
	uint32 quotient;
	uint32 res_ret;

	if ( measure >= mmv )
	{
		/* Calculate increase in mmv value */
		temp = ((uint64) measure - mmv ) * crlc;

		/* Rounding-off the mmv increase */
		quotient  = (uint32)( (temp + (uint32)2147483648LL) >> 32 );
		/* Check for saturation */
		if ( (quotient == 0U) && (temp >= 1U) )
		{
			/* Saturation reached */
			res_ret =  (mmv + 1U);
		}
		else
		{
			/* Saturation not reached.*/
			res_ret =  (mmv + quotient);
		}
	}
	else
	{
		/* Calculate decrease in mmv value */
		temp = ((uint64)mmv - measure ) * crlc;

		/* Rounding-off the mmv decrease */
		quotient  = (uint32)( (temp + (uint32)2147483648LL) >> 32 );
		/* Check for saturation */
		if ( (quotient == 0U) && (temp >= 1U) )
		{
			/* Saturation reached.*/
			res_ret =  (mmv - 1U);
		}
		else
		{
			/* Saturation not reached.*/
			res_ret =  (mmv - quotient);
		}
	}


	return res_ret ;
	/* ## Operation body end [9d4a75a1-f69e-46a2-90a2-41a594801571] */
}

/** This operation shall calculate the new floating average of type uint32 with an uint32 value as old floating average, an uint32 value as actual measured value and an uint16 value (0...0.999985) as average value

@param mmv Old floating average

Range:		00(H).....FFFFFFFF(H)
	 	   0......4294967295
@param measure Actual measured value

Range:		00(H).....FFFFFFFF(H)
	 	   0......4294967295
@param crlc Constant value

Range:		00(H)...FFFF(H)
	               0...0.999985
@return result = mmv + (((measure - mmv) * crlc) >> 16), result  rounded  off

result is corrected for moving mean value saturation using the following logic
	if  (result =mmv)
	{
		if  (((measure - mmv) * crlc) > 0)
		{
			result++
		}
		else if  (((measure - mmv) * crlc) < 0)
		{
			result--
		}
	}

Range: 		00(H)......FFFFFFFF(H)
		       0...4294967295 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint32 u32_mmv_u32_u32_u16_fac1(uint32 mmv, uint32 measure, uint16 crlc)
{
	/* ## Operation body start [05c49db6-0f48-4bb0-8863-51e6ac5d0dee] */
	/*~A*/
	/*~+:Description*/
	/*
                                                                        FUNCTION:  u32_mmv_u32_u32_u16_fac1                                         

                                                                        Parameter         type      Hex Range      Physical Range        

                                                                        Input:                                                                    
                                                                        mmv                uint32    0....FFFFFFFF   0....+4294967295       
                                                                        measure            uint32    0....FFFFFFFF   0....+4294967295       
                                                                        crlc               uint16    0....FFFF       0....+0.99998          

                                                                        Output:                                                                   
                                                                        result             uint32    0....FFFFFFFF   0....+4294967295       

                                                                        Functionality:                                                            
                                                                        mmv+(((measure-mmv)*crlc)>>16)  with round off                   
                                                                        If  ( ((( measure - mmv) * crlc) >> 16)==0)                      
                                                                        If  ((( measure - mmv) * crlc) > 0)                         
                                                                        result++                                                
                                                                        Elseif  ((( measure - mmv) * crlc) < 0)                     
                                                                        result--                                                
                                                                        Endif                                                       
                                                                        Endif                                                            

	 */

	/*~E*/
	uint64 temp;
	uint32 res_ret;
	uint32 quotient,tmp_crlc = crlc;

	if (measure >= mmv)
	{
		/* Calculate increase in mmv value */
		temp = ((uint64) measure - mmv ) * tmp_crlc;

		/* Rounding-off the mmv increase */
		quotient  = (uint32)((temp + (uint32)32768) >> 16);

		/* Check for saturation */
		if ( (quotient == 0U) && (temp >= 1U) )
		{
			/* Saturation reached */
			res_ret = (mmv + 1U);
		}
		else
		{
			/* Saturation not reached.*/
			res_ret = (mmv + quotient);
		}
	}
	else
	{
		/* Calculate decrease in mmv value */
		temp = ( (uint64)mmv - measure ) * tmp_crlc;

		/* Rounding-off the mmv decrease */
		quotient  = (uint32)((temp + (uint32)32768) >> 16);

		/* Check for saturation */
		if ( (quotient == 0U) && (temp >= 1U) )
		{
			/* Saturation reached */
			res_ret = (mmv - 1U);
		}
		else
		{
			/* Saturation not reached.*/
			res_ret = (mmv - quotient);
		}
	}
	return res_ret ;
	/* ## Operation body end [05c49db6-0f48-4bb0-8863-51e6ac5d0dee] */
}

/** This operation shall calculate the new floating average of type uint32 with an uint32 value as old floating average, an uint32 value as actual measured value and a sint32 value (-1....0.9999) as average value

@param mmv Old floating average

Range:		00(H).....FFFFFFFF(H)
	 	   0......4294967295
@param measure Actual measured value

Range:		00(H).....FFFFFFFF(H)
	 	   0......4294967295
@param crlc Constant value

Range:		80000000(H)...7FFFFFFF(H)
	                    -1...0...0.9999
@return result = mmv + ((( measure - mmv) * crlc) >> 31),	result  rounded  off

result is corrected for moving mean value saturation using the following logic
	if  (result = mmv)
	{
		if  ((( measure - mmv) * crlc) > 0)
		{
			result++
		}
		else if  ((( measure - mmv) * crlc) < 0)
		{
			result--
		}
	}

Limit overflow to:   0xFFFFFFFF (4294967295)
Limit underflow to: 0x00 (0)

Range: 		00(H)......FFFFFFFF(H)
	               0.......4294967295 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint32 u32_mmv_u32_u32_s32_fac1(uint32 mmv, uint32 measure, sint32 crlc)
{
	/* ## Operation body start [74fbb205-1532-462b-acb5-d13f8fdb1abe] */
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u32_mmv_u32_u32_s32_fac1                                                   

         Parameter     type           Hex Range                  Physical Range        

Input:                                                                                 
         mmv           uint32             0....FFFFFFFF            0....+4294967295       
         measure       uint32             0....FFFFFFFF            0....+4294967295       
         crlc          sint32      80000000....7FFFFFFF            0....+0.99999          

Output:                                                                                
         result        uint32             0....FFFFFFFF            0....+4294967295       

Functionality:                                                                         
         result= mmv + (((messwert-mmv) * crlc) >> 31) with round off                  
         If  ( ((( measure - mmv) * crlc) >> 31)==0)                                   
              If  ((( measure - mmv) * crlc) > 0)                                      
                  result++                                                             
              Elseif  ((( measure - mmv) * crlc) < 0)                                  
                  result--                                                             
              Endif                                                                    
         Endif                                                                         
         Limit  overflow  to  :FFFFFFFFH(4294967295)                                   
         Limit  underflow  to :00000000H(0)                                            
	 */

	/*~E*/
	sint64 temp;
	sint64 quotient;
	uint32 res_ret;
	temp = ( (sint64)measure - (sint64)mmv ) * crlc;

	/* Check if there is any increase in mmv value */
	if ( temp > 0 )
	{
		/* Calculate value to be added with round-off*/
		quotient = (sint64)((uint64)( temp + 1073741824 ) >> 31);
		/* Check for saturation */
		if ( quotient == 0 )
		{
			/* Do Saturation correction */
			quotient += 1;

		}
	}
	else
	{
		/* Check if there is any decrease in mmv value */
		if ( temp < 0 )
		{
			/* Calculate value to be subtracted with round-off */
			quotient = (sint64)( (uint64)( (-temp) +1073741824 ) >> 31);
			/* Check for saturation */
			if ( quotient == 0)
			{
				/* Do Saturation correction */
				quotient -= 1;

			}
			else
			{
				quotient = - quotient;
			}
		}
		else
		{
			/* Convergence reached. */ quotient = 0LL;

		}
	}
	/* Calculate new mmv */
	temp = (sint64)mmv + quotient;

	/* Check for Overflow */
	if ( temp >= (sint64)U32_MAX )
	{
		res_ret =  U32_MAX;
	}
	else
	{
		/* Check for Underflow */
		if ( temp <= (sint64)U32_MIN )
		{
			res_ret =  U32_MIN;
		}
		else
		{
			res_ret =  (uint32)temp;
		}
	}
	return res_ret ;
	/* ## Operation body end [74fbb205-1532-462b-acb5-d13f8fdb1abe] */
}

/** This operation shall calculate the new floating average of type uint32 with an uint32 value as old floating average, an uint32 value as actual measured value and a sint16 value (-1...0.99997) as average value

@param mmv Old floating average

Range:		00(H).....FFFFFFFF(H)
	 	   0......4294967295
@param measure Actual measured value

Range:		00(H).....FFFFFFFF(H)
	 	   0......4294967295
@param crlc Constant value

Range:		8000(H)...7FFF(H)
	               -1...0.99997
@return result = mmv + ((( measure - mmv) * crlc) >> 15), result rounded off

result is corrected for moving mean value saturation using the following logic
	if  (result = mmv)
	{
		if  ((( measure - mmv) * crlc) > 0)
		{
			result++
		}
		else if  ((( measure - mmv) * crlc) < 0)
		{
			result--
		}
	}

Limit overflow to:   0xFFFFFFFF (4294967295)
Limit underflow to: 0x00 (0)

Range: 		00(H)......FFFFFFFF(H)
	                  0...4294967295 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint32 u32_mmv_u32_u32_s16_fac1(uint32 mmv, uint32 measure, sint16 crlc)
{
	/* ## Operation body start [f4bd3d10-5191-4d1e-b142-4ae6bc913cdf] */
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u32_mmv_u32_u32_s16_fac1                                                      

         Parameter         type        Hex Range                  Physical Range       

Input:                                                                                 
         mmv                uint32      0....FFFFFFFF               0....+4294967295      
         measure            uint32      0....FFFFFFFF               0....+4294967295      
         crlc               sint16      8000....7FFF               -1....+0.99997         

Output:                                                                                
         result             uint32      0....FFFFFFFF               0....+4294967295      

Functionality:                                                                         
         result = mmv + (((measure - mmv) * crlc) >> 15) with round off                
         If  ( ((( measure - mmv) * crlc) >> 15)==0)                                   
              If  ((( measure - mmv) * crlc) > 0)                                      
                  result++                                                             
              Elseif  ((( measure - mmv) * crlc) < 0)                                  
                  result--                                                             
              Endif                                                                    
         Endif                                                                         
         Limit  overflow  to  :FFFFFFFFH(4294967296)                                   
         Limit  underflow  to :00000000H(0)                                            
	 */

	/*~E*/
	sint64 temp;
	sint64 quotient;
	uint32 res_ret;
	temp = ( (sint64)measure -  (sint64)mmv ) * crlc;

	/* Check if there is any increase in mmv value */
	if ( temp > 0 )
	{
		/*Calculate value to be added with round-off*/
		quotient = (sint64)( (uint64)( temp + 16384 ) >> 15);
		/* Check for saturation */
		if ( quotient == 0)
		{
			/* Do Saturation correction */
			quotient += 1;

		}
	}
	else
	{
		/* Check if there is any decrease in mmv value */
		if ( temp < 0 )
		{
			/* Calculate value to be subtracted (with round-off) */
			quotient = (sint64)( (uint64)( (-temp) + 16384 )  >> 15);

			/* Check for saturation */
			if ( quotient == 0)
			{
				/* Do Saturation correction */
				quotient -= 1;

			}
			else
			{
				quotient = - quotient;
			}
		}
		else
		{
			/* Convergence reached. */
			quotient = 0LL;

		}
	}
	/* Calculate new mmv */
	temp = (sint64)mmv + quotient;

	/* Check for Overflow */
	if ( temp >= (sint64)U32_MAX )
	{
		res_ret = U32_MAX;
	}
	else
	{
		/* Check for Underflow */
		if ( temp <= (sint64)U32_MIN )
		{
			res_ret =  U32_MIN;
		}
		else
		{
			res_ret = (uint32)temp;
		}
	}
	return res_ret;
	/* ## Operation body end [f4bd3d10-5191-4d1e-b142-4ae6bc913cdf] */
}

/** This operation shall calculate the new floating average of type uint32 with a sint32 value as old floating average, a sint32 value as actual measured value and an uint32 value (0...0.999985) as average value

@param mmv Old floating average

Range:		80000000(H).....7FFFFFFF(H)
	             -2147483648....2147483647
@param measure Actual measured value

Range:		80000000(H).....7FFFFFFF(H)
	             -2147483648....2147483647
@param crlc Constant value

Range:		00(H)...FFFFFFFF(H)
	                0...0.999985
@return result = mmv + (((measure - mmv) * crlc) >> 32), result  rounded  off

result is corrected for moving mean value saturation using the following logic
	if  (result = mmv)
	{		
		if  (((measure - mmv) * crlc) > 0)
		{
			result++
		}
		else if  (((measure - mmv) * crlc) < 0)
		{
			result--
		}
	}

Limit underflow to: 0x00

Range:		 00(H).......FFFFFFFF(H)
		       0...4294967295 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint32 u32_mmv_s32_s32_u32_fac1(sint32 mmv, sint32 measure, uint32 crlc)
{
	/* ## Operation body start [fb51ebd7-7005-4c97-9ac4-7eb6b5c48670] */
	/*~A*/
	/*~+:Description*/
	/*
                                                                                      FUNCTION:  u32_mmv_s32_s32_u32_fac1                                                     

                                                                                      Parameter         type           Hex Range          Physical Range              

                                                                                      Input:                                                                                   
                                                                                      mmv                sint32      80000000..7FFFFFFF       -2147483648....+2147483647 
                                                                                      measure            sint32      80000000..7FFFFFFF       -2147483648....+2147483647 
                                                                                      crlc               uint32             0..7FFFFFFF                 0....+0.99999    

                                                                                      Output:                                                                                  
                                                                                      result             uint32             0..7FFFFFFF                 0....+4294967295 

                                                                                      Functionality:                                                                           
                                                                                      mmv+(((measure-mmv)*crlc)>>32)  with round off                                  
                                                                                      If  ( ((( measure - mmv) * crlc) >> 32)==0)                                     
                                                                                      If  ((( measure - mmv) * crlc) >>32) > 0)                                  
                                                                                      result++                                                               
                                                                                      Elseif  ((( measure - mmv) * crlc) < 0)                                    
                                                                                      result--                                                               
                                                                                      Endif                                                                      
                                                                                      Endif                                                                           

	 */

	/*~E*/
	uint64 temp;
	uint32 temp1;/*lint -esym(438,temp1)*/
	uint32 quotient;
	sint32 tmp_res;
	uint32 result;

	if (measure >= mmv)
	{
		/* Calculate increase in mmv value */
		temp1 = ( (uint32)measure - (uint32)mmv );
		temp = (uint64)temp1 * crlc ;
		/*Rounding-off the mmv increase */
		quotient  = (uint32)( (temp + (uint32)2147483648U) >> 32 )/*lint --e(530)*/;
		/* Check for saturation */

		if ((quotient == 0U) && (temp > 0U))
		{
			/* Dosaturation correction */
			tmp_res = mmv + (sint8)1;
		}
		else
		{
			/* Saturation not reached.*/
			tmp_res = mmv + (sint32)quotient;
		}
	}
	else
	{
		/* Calculate decrease in mmv value */
		temp1 = ( (uint32)mmv - (uint32)measure );
		temp = (uint64)temp1 * crlc ;

		/* Rounding-off the mmv decrease */
		quotient = (uint32)( (temp + (uint32)2147483648U) >> 32 );
		/* Check for saturation */
		if ((quotient == 0U) && (temp > 0U))
		{
			/* Do saturation correction */
			tmp_res = mmv - (sint8)1;
		}
		else
		{
			/* Saturation not reached.*/
			tmp_res = mmv - (sint32)quotient;

		}
	}
	/* Check for Underflow */
	if ( tmp_res <= (sint32)(U32_MIN) )
	{
		result =  U32_MIN;
	}
	else
	{
		result =  (uint32)tmp_res;
	}
	return result;
	/* ## Operation body end [fb51ebd7-7005-4c97-9ac4-7eb6b5c48670] */
}

/** This operation shall calculate the new floating average of type uint32 with a sint32 value as old floating average, a sint32 value as actual measured value and an uint16 value (0...0.99997) as average value

@param mmv Old floating average

Range:		80000000(H).....7FFFFFFF(H)
	             -2147483648....2147483647
@param measure Actual measured value

Range:		80000000(H).....7FFFFFFF(H)
	             -2147483648....2147483647
@param crlc Constant value

Range:		00(H)...FFFF(H)
	                0...0.99997
@return result = mmv + (((measure - mmv) * crlc) >> 16), result  rounded  off

result is corrected for moving mean value saturation using the following logic
	if  (result = mmv)
	{
		if  (((measure - mmv) * crlc) > 0)
		{
			result++
		}
		else if  (((measure - mmv) * crlc) < 0)
		{
			result--
		}
	}

Limit underflow to:  0x00

Range: 		00(H)......FFFFFFFF(H)
 	                 0...4294967295 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint32 u32_mmv_s32_s32_u16_fac1(sint32 mmv, sint32 measure, uint16 crlc)
{
	/* ## Operation body start [44333307-d3ad-4914-99ab-8938974480f2] */
	/*~A*/
	/*~+:Description*/
	/*
                                                                                      FUNCTION:  u32_mmv_s32_s32_u16_fac1                                                      

                                                                                      Parameter         type         Hex Range                Physical Range         

                                                                                      Input:                                                                                  
                                                                                      mmv                sint32   80000000....7FFFFFFF     -2147483648....+2147483647   
                                                                                      measure            sint32   80000000....7FFFFFFF     -2147483648....+2147483647   
                                                                                      crlc               uint16          0....FFFF                   0....+0.99998      

                                                                                      Output:                                                                                 
                                                                                      result             uint32          0....FFFFFFFF               0....+4294967295   

                                                                                      Functionality:                                                                          
                                                                                      mmv+(((measure-mmv)*crlc)>>16)  with round off                                 
                                                                                      If  ( ((( measure - mmv) * crlc) >> 16)==0)                                    
                                                                                      If  ((( measure - mmv) * crlc) > 0)                                       
                                                                                      result++                                                              
                                                                                      Elseif  ((( measure - mmv) * crlc) < 0)                                   
                                                                                      result--                                                              
                                                                                      Endif                                                                     
                                                                                      Endif                                                                          

	 */

	/*~E*/
	uint64 temp;
	uint32 temp1/*lint -esym(438,temp1) : tmp_s64 used in asm instrution*/;
	uint32 quotient;
	sint32 tmp_res;
	uint32 res_ret;
	if ( measure >= mmv )
	{
		/* Calculate increase in mmv value */
		temp1 = ( (uint32)measure - (uint32)mmv );
		temp = (uint64)temp1 * crlc ;

		/*Rounding-off the mmv increase */
		quotient  = (uint32)( (temp + (uint32)32768) >> 16 );

		/* Check for saturation */
		if ((quotient == 0U) && (temp > 0U))
		{
			/* Do saturation correction */
			tmp_res =mmv + (sint8)1;

		}
		else
		{
			/* Saturation not reached.*/
			tmp_res = mmv + (sint32)quotient;

		}
	}
	else
	{
		/* Calculate decrease in mmv value */
		temp1 = ( (uint32)mmv - (uint32)measure );
		temp = (uint64)temp1 * crlc ;

		/* Rounding-off the mmv decrease */
		quotient  = (uint32)( (temp + (uint32)32768) >> 16 );

		/* Check for saturation */
		if ((quotient == 0U) && (temp > 0U))
		{
			/* Do saturation correction */
			tmp_res = mmv - (sint8)1;

		}
		else
		{
			/* Saturation not reached.*/
			tmp_res = mmv - (sint32)quotient;

		}
	}
	/* Check for Underflow */
	if ( tmp_res <= (sint32)(U32_MIN) )
	{
		res_ret = U32_MIN;
	}
	else
	{
		res_ret = (uint32)tmp_res;
	}
	return res_ret;
	/* ## Operation body end [44333307-d3ad-4914-99ab-8938974480f2] */
}

/** This operation shall calculate the new floating average of type uint32 with a sint32 value as old floating average, a sint32 value as actual measured value and a sint32 value (-1....0.9999) as average value

@param mmv Old floating average

Range:		80000000(H).....7FFFFFFF(H)
	             -2147483648....2147483647
@param measure Actual measured value

Range:		80000000(H).....7FFFFFFF(H)
	             -2147483648....2147483647
@param crlc Constant value

Range:		80000000(H).....7FFFFFFF(H)
	                       -1......0.9999
@return result = mmv + ((( measure - mmv) * crlc) >> 31),	result  rounded  off

result is corrected for moving mean value saturation using the following logic
	if  (result = mmv)
	{
		if  ((( measure - mmv) * crlc) > 0)
		{
			result++
		}
		else if  ((( measure - mmv) * crlc) < 0)
		{
			result--
		}
	}

Limit overflow to:   0xFFFFFFFF (4294967295)
Limit underflow to: 0x00 (0)

Range: 		00(H).....FFFFFFFF(H)
		      0...4294967295 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint32 u32_mmv_s32_s32_s32_fac1(sint32 mmv, sint32 measure, sint32 crlc)
{
	/* ## Operation body start [3df33ab9-2554-4564-9b18-eb40293d3ec7] */
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u32_mmv_s32_s32_s32_fac1                                                       

         Parameter         type        Hex Range                  Physical Range       

Input:                                                                                 
         mmv                sint32   80000000....FFFFFFFF     -2147483648....+2147483647  
         measure            sint32   80000000....FFFFFFFF     -2147483648....+2147483647  
         crlc               sint32   80000000....7FFFFFFF              -1....+0.99999     

Output:                                                                                
         result             uint32          0....FFFFFFFF               0....+4294967295  

Functionality:                                                                         
         result = mmv + (((measure-mmv) * crlc) >> 31) with round off                  
         If  ( ((( measure - mmv) * crlc) >> 31)==0)                                   
              If  ((( measure - mmv) * crlc) > 0)                                      
                  result++                                                             
              Elseif  ((( measure - mmv) * crlc) < 0)                                  
                  result--                                                             
              Endif                                                                    
         Endif                                                                         
         Limit  overflow  to  :FFFFFFFFH(4294967295)                                   
         Limit  underflow  to :00000000H(0)                                            
	 */

	/*~E*/
	sint64 temp;
	sint64 quotient;
	uint32 res_ret;
	temp = ((sint64)measure - mmv) * crlc;

	/* Check if there is any increase in mmv value */
	if ( temp > 0 )
	{
		/* Calculate value to be added with round-off*/
		quotient = (sint64)( (uint64)( temp + 1073741824 ) >> 31);
		/* Check for saturation */
		if (quotient == 0)
		{
			/* Do Saturation correction */
			quotient += 1;

		}
	}
	else
	{
		/* Check if there is any decrease in mmv value */
		if ( temp < 0 )
		{
			/* Calculate value to be subtracted (with round-off) */
			quotient = (sint64)( (uint64)( (-temp) + 1073741824 ) >> 31);

			/* Check for saturation */
			if (quotient == 0)
			{
				/* Do Saturation correction */
				quotient -= 1;

			}
			else
			{
				quotient = - quotient;
			}
		}
		else
		{
			/* Convergence reached. */
			quotient = 0LL;

		}
	}
	/* Calculate new mmv */
	temp = (sint64)mmv + quotient;

	/* Check for Overflow */
	if (temp >= (sint64)U32_MAX)
	{
		res_ret = U32_MAX;
	}
	else
	{
		/* Check for Underflow */
		if (temp <= (sint64)U32_MIN)
		{
			res_ret = U32_MIN;
		}
		else
		{
			res_ret = (uint32)temp;
		}
	}
	return res_ret ;
	/* ## Operation body end [3df33ab9-2554-4564-9b18-eb40293d3ec7] */
}

/** This operation shall calculate the new floating average of type uint32 with a sint32 value as old floating average, a sint32 value as actual measured value and a sint16 value (-1....0.9999) as average value

@param mmv Old floating average

Range:		80000000(H).....7FFFFFFF(H)
	             -2147483648....2147483647
@param measure Actual measured value

Range:		80000000(H).....7FFFFFFF(H)
	             -2147483648....2147483647
@param crlc Constant value

Range:		8000(H).....7FFF(H)
	                -1......0.9999
@return result = mmv + ((( measure - mmv) * crlc) >> 15),	result  rounded  off

result is corrected for moving mean value saturation using the following logic
	if  (result = mmv)
	{
		if  ((( measure - mmv) * crlc) > 0)
		{
			result++
		}
		else if  ((( measure - mmv) * crlc) < 0)
		{
			result--
		}
	}

Limit overflow to:   0xFFFFFFFF (4294967295)
Limit underflow to: 0x00 (0)

Range: 		00(H).........FFFFFFFF(H)
		        0...4294967295 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint32 u32_mmv_s32_s32_s16_fac1(sint32 mmv, sint32 measure, sint16 crlc)
{
	/* ## Operation body start [281a6757-e69f-484f-94c1-259549fb9c3d] */
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u32_mmv_s32_s32_s16_fac1                                                      

         Parameter         type        Hex Range                  Physical Range       

Input:                                                                                 
         mmv                sint32   80000000....7FFFFFFF     -2147483648....+2147483647  
         measure            sint32   80000000....7FFFFFFF     -2147483648....+2147483647  
         crlc               sint16   80000000....7FFFFFFF              -1....+0.99997     

Output:                                                                                
         result             uint32          0....FFFFFFFF               0....+4294967295  

Functionality:                                                                         
         result = mmv + (((measure - mmv) * crlc) >> 15) with round off                
         If  ( ((( measure - mmv) * crlc) >> 15)==0)                                   
              If  ((( measure - mmv) * crlc) > 0)                                      
                  result++                                                             
              Elseif  ((( measure - mmv) * crlc) < 0)                                  
                  result--                                                             
              Endif                                                                    
         Endif                                                                         
         Limit  overflow  to  :FFFFFFFFH(4294967295)                                   
         Limit  underflow  to :00000000H(0)                                            
	 */

	/*~E*/
	sint64 temp;
	sint64 quotient;
	uint32 res_ret;
	temp = ( ((sint64)measure - mmv) ) * crlc;

	/* Check if there is any increase in mmv value */
	if ( temp > 0 )
	{
		/* Calculate value to be added with round-off */
		quotient = (sint64)((uint64)( temp + 16384) >> 15);
		/* Check for saturation */
		if (quotient == 0)
		{
			/* Do Saturation correction */
			quotient += 1;

		}
	}
	else
	{
		/* Check if there is any decrease in mmv value */
		if ( temp < 0 )
		{
			/* Calculate value to be subtracted with round-off */
			quotient =(sint64)((uint64) ( (-temp) + 16384 ) >> 15);

			/* Check for saturation */
			if (quotient == 0)
			{
				/* Do Saturation correction */
				quotient -= 1;

			}
			else
			{
				quotient = - quotient;
			}
		}
		else
		{
			/* Convergence reached. */
			quotient = 0LL;

		}
	}
	/* Calculate new mmv */
	temp = (sint64)mmv + quotient;

	/* Check for Overflow */
	if (temp >= (sint64)U32_MAX)
	{
		res_ret = U32_MAX;
	}
	else
	{
		/* Check for Underflow */
		if (temp <= (sint64)U32_MIN)
		{
			res_ret = U32_MIN;
		}
		else
		{
			res_ret = (uint32)temp;
		}
	}
	return res_ret ;
	/* ## Operation body end [281a6757-e69f-484f-94c1-259549fb9c3d] */
}

/** This operation shall calculate the new floating average of type sint32 with a sint32 value as old floating average, a sint32 value as actual measured value and a uint16 value (0....0.99998) as average value

@param mmv Old floating average

Range:		80000000(H).....7FFFFFFF(H)
	             -2147483648....2147483647
@param measure Actual measured value

Range:		80000000(H).....7FFFFFFF(H)
	             -2147483648....2147483647
@param crlc Constant value

Range:		00(H).....FFFF(H)
	                0......0.99998
@return result = mmv + ((( measure - mmv) * crlc) >> 16),	result  rounded  off

result is corrected for moving mean value saturation using the following logic
	if  ( ((( measure - mmv) * crlc) >> 16)==0) 
     	{
		if  ((( measure - mmv) * crlc) > 0)    
		{
		         result++                           
		}
		else if  ((( measure - mmv) * crlc) < 0)
		{
		        result--                           
		}                                  
	}                                 

Range: 		80000000(H).........7FFFFFFF(H)
		    -2147483648...2147483647 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint32 s32_mmv_s32_s32_u16_fac1(sint32 mmv, sint32 measure, uint16 crlc)
{
	/* ## Operation body start [ab694a35-7d51-4a5f-9e74-b5db67f69f09] */
	/*~A*/
	/*~+:Description*/
	/*
                                                                                       FUNCTION:  s32_mmv_s32_s32_u16_fac1                                                      

                                                                                       Parameter      type         Hex Range                Physical Range             

                                                                                       Input:                                                                                   
                                                                                       mmv            sint32     80000000....7FFFFFFF     -2147483648....+2147483647      
                                                                                       measure        sint32     80000000....7FFFFFFF     -2147483648....+2147483647      
                                                                                       crlc           uint16          0....FFFF                 0....+0.99998             

                                                                                       Output:                                                                                  
                                                                                       result         sint32     80000000....7FFFFFFF     -2147483648....+2147483647      

                                                                                       Functionality:                                                                           
                                                                                       mmv+(((measure-mmv)*crlc)>>16)  with round off                                  
                                                                                       If  ( ((( measure - mmv) * crlc) >> 16)==0)                                     
                                                                                       If  ((( measure - mmv) * crlc) > 0)                                        
                                                                                       result++                                                               
                                                                                       Elseif  ((( measure - mmv) * crlc) < 0)                                    
                                                                                       result--                                                               
                                                                                       Endif                                                                      
                                                                                       Endif                                                                           

	 */

	/*~E*/
	uint64 temp;
	uint32 temp1;
	uint32 quotient;
	sint32 tmp_res;
	if ( measure >= mmv )
	{
		/* Calculate increase in mmv value */
		temp1 = (uint32)( measure - mmv );
		temp = (uint64)temp1 * crlc;
		/*Rounding-off the mmv increase */
		quotient  = (uint32)( (temp + (uint32)32768) >> 16 );
		/* Check for saturation */
		if ( (quotient == 0U ) && ( temp > 0U ) )
		{
			/* Do saturation correction */
			tmp_res =mmv + 1;

		}
		else
		{
			/* Saturation not reached*/
			tmp_res = mmv + (sint32)quotient;

		}
	}
	else
	{
		/* Calculate decrease in mmv value */
		temp1 = (uint32)( mmv - measure );
		temp = (uint64)temp1 * crlc;

		/* Rounding-off the mmv decrease */
		quotient  = (uint32)( (temp + (uint32)32768) >> 16 );
		/* Check for saturation */
		if ( (quotient == 0U ) && ( temp > 0U ) )
		{
			/* Do saturation correction */
			tmp_res = mmv - 1;

		}
		else
		{
			/* Saturation not reached*/
			tmp_res = mmv - (sint32)quotient;

		}
	}
	return tmp_res;


	/* ## Operation body end [ab694a35-7d51-4a5f-9e74-b5db67f69f09] */
}

/** This operation shall calculate the output (sint16) of a first order high-Pass filter with the input parameters as previous output (yold), present input (u), previous input (uold) and a constant multiplying factor (m) with overflow and underflow limitation

@param yold Previous output 

Range:		8000(H)..........7FFF(H)
		 -256......255.9921875
@param u Present input

Range:		00(H).....FF(H)
		    0.....255
@param uold Previous input

Range:		00(H).....FF(H)
		    0.....255
@param m Constant multiplying factor

Range:		00(H).....FFFF(H)
		    0..0.999985
@return (yold - (m*yold/65536) + (u -uold)*128), result rounded off

Saturation correction for  converging output to zero
if ((result equals yold) and (yold > 0))
{
		decrement result by one
}
if ((result equals yold) and (yold < 0))
{
		increment result by one
}

Range:		8000(H)..........7FFF(H)
		 -256......255.9921875 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint16 s16_hip1_s16_u8_u8_u16_fac1(sint16 yold, uint8 u, uint8 uold, uint16 m)
{
	/* ## Operation body start [32659f77-3ae9-40d9-913f-5291bb8d55f3] */
	/*~A*/
	/*~+:Description*/
	/*FUNCTION: s16_hip1_s16_u8_u8_u16_fac1

Functional Description:
The result is the output of a first order High-Pass filter with the specified input parameters and constant multiplying factor in the range of 0..0.999985 with results limited if it falls outside sint16 range.



Parameters used:                                                   


         Parameter     type      Hex Range       Physical Range    

Input:                                                             
         yold           sint16     8000..7FFFH    -256..0..255.9921875
         u              uint8        00..FFH           0..255         
         uold           uint8        00..FFH           0..255         
         m              uint16     0000..FFFFH         0..0.999985    

Output:                                                            
         result         sint16     8000..7FFFH    -256..0..255.9921875

Functionality:                                                     
        result=yold-(yold*m)/65536+(u-uold)*128                    
             result rounded-off                                    
        if ((result equals yold)and(yold greater than zero))       
             result is decremented by one                          
        if ((result equals yold)and(yold less than zero))          
             result is incremented by one                          
	 */

	/*~E*/
	sint32 result,temp_yold;
	sint32 temp_product,temp_value;
	sint16 res_ret;
	temp_yold=(sint32)yold;
	temp_product = (sint32) temp_yold * (sint32)m;

	/*Rounding-off Correction*/
	temp_value = (temp_product / (sint32)65536) + (( 2 * (temp_product % (sint32)65536)) /(sint32)(65536));

	/*Filter Value Calculation*/
	result = (temp_yold-temp_value)+(((sint32)u-(sint32)uold)*128);

	/*Saturation Correction*/
	if (result==temp_yold)
	{
		/*Check for the sign of previous result*/
		if (temp_yold>(sint8)0)
		{
			result--;
		}
		else
		{
			if (temp_yold != (sint8)0)
			{
				result++;
			}
		}
	}
	/*Check for Overflow*/
	if (result>S16_MAX)
	{
		res_ret =  (S16_MAX);
	}
	else
	{
		/*Check for underflow*/
		if (result<S16_MIN)
		{
			res_ret =  (S16_MIN);
		}
		else
		{
			res_ret =  ((sint16)result);
		}
	}
	return res_ret ;
	/* ## Operation body end [32659f77-3ae9-40d9-913f-5291bb8d55f3] */
}

/** This operation shall calculate the output (sint16) of a first order high-Pass filter with the input parameters as previous output (yold), present input (u), previous input (uold) and a constant multiplying factor (m) with overflow and underflow limitation

@param yold Previous output

Range:		8000(H)..........7FFF(H)
		 -256......255.9921875
@param u Present input

Range:		80(H).....7F(H)
		  -128.....127
@param uold Previous input

Range:		80(H).....7F(H)
		  -128.....127
@param m Constant multiplying factor

Range:		00(H).....FFFF(H)
		    0..0.999985
@return (yold - (m*yold/65536) + (u -uold)*128), result rounded off

Saturation correction for  converging output to zero
if ((result equals yold) and (yold > 0))
{
		decrement result by one
}
if ((result equals yold) and (yold < 0))
{
		increment result by one
}

Range:		8000(H)..........7FFF(H)
		 -256......255.9921875 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint16 s16_hip1_s16_s8_s8_u16_fac1(sint16 yold, sint8 u, sint8 uold, uint16 m)
{
	/* ## Operation body start [b441491f-1c12-4bed-816b-127fd8e2c085] */
	/*~A*/
	/*~+:Description*/
	/*FUNCTION: s16_hip1_s16_s8_s8_u16_fac1

Functional Description:
The result is the output of a first order High-Pass filter with the specified input parameters and constant multiplying factor in the range of 0..0.999985 with results limited if it falls outside sint16 range.



Parameters used:                                                   


         Parameter     type      Hex Range       Physical Range    

Input:                                                             
         yold           sint16     8000..7FFFH    -256..0..255.9921875
         u              sint8        00..FFH         -128..0..127     
         uold           sint8        00..FFH         -128..0..127     
         m              uint16     0000..FFFFH         0..0.999985    

Output:                                                            
         result         sint16     8000..7FFFH    -256..0..255.9921875

Functionality:                                                     
        result=yold-(yold*m)/65536+(u-uold)*128                    
             result rounded-off                                    
        if ((result equals yold)and(yold greater than zero))       
             result is decremented by one                          
        if ((result equals yold)and(yold less than zero))          
             result is incremented by one                          
	 */

	/*~E*/
	sint16 res_ret;
	sint32 result,temp_yold;
	sint32 temp_product,temp_value;

	temp_yold=(sint32)yold;
	temp_product = (sint32) temp_yold * (sint32)m;

	/*Rounding-off Correction*/
	temp_value = (temp_product / (sint32)65536) + ((2 * (temp_product % (sint32)65536)) / (sint32)65536);

	/*Filter Value Calculation*/
	result = (temp_yold - temp_value) + (((sint32)u - (sint32)uold) * 128);

	/*Saturation Correction*/
	if (result == temp_yold)
	{
		/*Check for the sign of previous result*/
		if (temp_yold > 0)
		{
			result--;
		}
		else
		{
			if (temp_yold != 0)
			{
				result++;
			}
		}
	}
	/*Check for Overflow*/
	if (result>S16_MAX)
	{
		res_ret =  (S16_MAX);
	}
	else
	{
		/*Check for underflow*/
		if (result<S16_MIN)
		{
			res_ret =  (S16_MIN);
		}
		else
		{
			res_ret =  ((sint16)result);
		}
	}
	return res_ret ;
	/* ## Operation body end [b441491f-1c12-4bed-816b-127fd8e2c085] */
}

/** This operation shall calculate the output (sint32) of a first order high-Pass filter with the input parameters as previous output (yold), present input (u), previous input (uold) and a constant multiplying factor (m) with overflow and underflow limitation

@param yold Previous output

Range:		80000000(H)..........7FFFFFFF(H)
		      -65536.......65535.99996
@param u Present input

Range:		00(H).....FFFF(H)
		    0.....65535
@param uold Previous input

Range:		00(H).....FFFF(H)
		    0.....65535
@param m Constant multiplying factor

Range:		00(H).....FFFF(H)
		    0..0.999985
@return (yold - (m*yold/65536) + (u -uold)* 32768), result rounded off

Saturation correction for  converging output to zero
if ((result equals yold) and (yold > 0))
{
		decrement result by one
}
if ((result equals yold) and (yold < 0))
{
		increment result by one
}

Range:		80000000(H)..........7FFFFFFF(H)
		      -65536.......65535.99996 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint32 s32_hip1_s32_u16_u16_u16_fac1(sint32 yold, uint16 u, uint16 uold, uint16 m)
{
	/* ## Operation body start [ee52b4b3-92b0-4655-86ca-0aa68242b385] */
	/*~A*/
	/*~+:Description*/
	/*FUNCTION: s32_hip1_s32_u16_u16_u16_fac1

Functional Description:
The result is the output of a first order High-Pass filter with the specified input parameters and constant multiplying factor in the range of 0..0.999985 with results limited if it falls outside sint32 range.



Parameters used:                                                                 


         Parameter     type      Hex Range             Physical Range            

Input:                                                                           
         yold           sint32     80000000..7FFFFFFFH  -65536..0..65535.99996      
         u              uint16         0000..FFFFH           0..65535               
         uold           uint16         0000..FFFFH           0..65535               
         m              uint16         0000..FFFFH          0..0.999985             

Output:                                                                          
         result         sint32     80000000..7FFFFFFFH  -65536..0..65535.99996      

Functionality:                                                                   
        result=yold-(yold*m)/65536+(u-uold)*32768                                
             result rounded-off                                                  
        if ((result equals yold)and(yold greater than zero))                     
             result is decremented by one                                        
        if ((result equals yold)and(yold less than zero))                        
             result is incremented by one                                        
	 */

	/*~E*/

	sint64 result,temp_product;
	sint32 temp_yold,temp_value;
	sint32 ret_res;

	temp_yold=yold;
	temp_product=(sint64)temp_yold*(sint32)m;

	/*Rounding-off Correction*/
	/*lint -e704 : 704: arithmetic shift right OK in library */
	if (temp_yold >= 0)
	{
		temp_value = (sint32)((uint64)(temp_product + (sint32)32768) >> 16)/*lint --e(530)*/;
	}
	else
	{
		temp_value = (sint32)((uint64)(temp_product + 32767) >> 16);
	}
	/*Filter Value Calculation*/
	result = (((sint64)temp_yold - (sint64)temp_value) + ((sint64)(((sint32)u - (sint32)uold) * (sint32)32768)));

	/*Saturation Correction*/
	if (result == temp_yold)
	{
		/*Check for the sign of previous result*/
		if (temp_yold > 0)
		{
			result--;
		}
		else
		{
			if (temp_yold != 0)
			{
				result++;
			}
		}
	}
	/*Check for Overflow*/
	if (result > S32_MAX)
	{
		ret_res = S32_MAX;

	}
	else
	{
		/*Check for underflow*/
		if (result < S32_MIN)
		{
			ret_res = S32_MIN;
		}
		else
		{
			ret_res =  ((sint32)result);
		}
	}
	return ret_res;
	/* ## Operation body end [ee52b4b3-92b0-4655-86ca-0aa68242b385] */
}

/** This operation shall calculate the output (sint32) of a first order high-Pass filter with the input parameters as previous output (yold), present input (u), previous input (uold) and a constant multiplying factor (m) with overflow and underflow limitation

@param yold Previous output

Range:		80000000(H)..........7FFFFFFF(H)
		      -65536.......65535.99996
@param u Present input

Range:		8000(H).....7FFF(H)
		  -32768..0..32767
@param uold Previous input

Range:		8000(H).....7FFF(H)
		  -32768..0..32767
@param m Constant multiplying factor

Range:		00(H).....FFFF(H)
		    0..0.999985
@return (yold - (m*yold/65536) + (u -uold)* 32768), result rounded off

Saturation correction for  converging output to zero
if ((result equals yold) and (yold > 0))
{
		decrement result by one
}
if ((result equals yold) and (yold < 0))
{
		increment result by one
}

Range:		80000000(H)..........7FFFFFFF(H)
		      -65536.......65535.99996 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint32 s32_hip1_s32_s16_s16_u16_fac1(sint32 yold, sint16 u, sint16 uold, uint16 m)
{
	/* ## Operation body start [428b470c-3a89-4073-9a51-ff6e4e7e767d] */
	/*~A*/
	/*~+:Description*/
	/*FUNCTION: s32_hip1_s32_s16_s16_u16_fac1

Functional Description:
The result is the output of a first order High-Pass filter with the specified input parameters and constant multiplying factor in the range of 0..0.999985 with results limited if it falls outside sint32 range.



Parameters used:                                                                 


         Parameter     type      Hex Range             Physical Range            

Input:                                                                           
         yold           sint32     80000000..7FFFFFFFH  -65536..0..65535.99996      
         u              sint16         8000..7FFFH        -32768..32767             
         uold           sint16         8000..7FFFH        -32768..32767             
         m              uint16         0000..FFFFH          0..0.999985             

Output:                                                                          
         result         sint32     80000000..7FFFFFFFH  -65536..0..65535.99996      

Functionality:                                                                   
        result=yold-(yold*m)/65536+(u-uold)*32768                                
             result rounded-off                                                  
        if ((result equals yold)and(yold greater than zero))                     
             result is decremented by one                                        
        if ((result equals yold)and(yold less than zero))                        
             result is incremented by one                                        
	 */

	/*~E*/
	sint64 result,temp_product;
	sint32 temp_yold,temp_value;
	sint32 ret_res;

	temp_yold=yold;
	temp_product=(sint64)temp_yold*(sint32)m;

	/*Rounding-off Correction*/
	if (temp_yold >= (sint8)0)
	{
		temp_value = (sint32)((uint64)(temp_product + (sint32)32768) >> 16)/*lint --e(530)*/;
	}
	else
	{
		temp_value = (sint32)((uint64)(temp_product + 32767) >> 16);
	}
	/*Filter Value Calculation*/
	result = ((sint64)temp_yold - (sint64)temp_value) + (sint64)(((sint32)u - (sint32)uold) * (sint32)32768);

	/*Saturation Correction*/
	if (result == temp_yold)
	{
		/*Check for the sign of previous result*/
		if (temp_yold > 0)
		{
			result--;
		}
		else
		{
			if (temp_yold != 0)
			{
				result++;
			}
		}
	}
	/*Check for Overflow*/
	if (result > S32_MAX)
	{
		ret_res =(S32_MAX);
	}
	else
	{
		/*Check for underflow*/
		if (result < S32_MIN)
		{
			ret_res = (S32_MIN);
		}
		else
		{
			ret_res = ((sint32)result);
		}
	}
	return ret_res;
	/* ## Operation body end [428b470c-3a89-4073-9a51-ff6e4e7e767d] */
}

/** This operation shall perform division of sint16 value by sint16 value with overflow and underflow limitation to produce a result of type sint16

@param numerator Numerator

Range:		8000(H).....7FFF(H)
		  -32768....32767
@param denominator Denominator

Range:		8000(H).....7FFF(H)
		  -32768....32767
@return (numerator << 16) / denominator, result rounded off
- Limit overflow to: 	0x7FFF (32767)
- Limit underflow to: 	0x8000 ( -32768)
- Value after division by 0 with  the numerator being >= 0:    0x7FFF(32767)
- Value after division by 0 with  the numerator being < 0:     0x8000(-32768)

Range:		8000(H).....7FFF(H)
		  -32768....32767
 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint16 s16_fac05_div_s16_s16(sint16 numerator, sint16 denominator)
{
	/* ## Operation body start [8a4a1cd2-768e-486a-b783-9ecdad9e1b11] */
	sint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
                                                                       FUNCTION: s16_fac05_div_s16_s16

                                                                       Parameter         type      Hex Range       Physical Range

                                                                       Input:                                                                    
                                                                       x_value            sint16      8000..7FFF      -32768..32767        
                                                                       y_value            sint16      8000..7FFF      -32768..32767        

                                                                       Output:                                                                   
                                                                       res                sint16      8000..7FFF      -32768..32767        

                                                                       Functionality:                                                            
                                                                       res = (x_value<<16)/y_value with round off                        
                                                                       overflow : limit to 7FFFH                                         
                                                                       underflow: limit to 8000H                                         

                                                                       After round off there is no possibility of overflow and underflow         
                                                                       limitation                                                                
                                                                       For e.g in case of overflow limitation after round off                    
                                                                       32767.5=65536*x_value /y_value                                            
                                                                       so x_value/y_value = 32767.5/65536 which is not a possible case.This holds
                                                                       good for underflow limitation after round off                             
	 */

	/*~E*/
	/*FUNCTION_ID:1*/
	sint32 temp;
	uint16 tmp_num = (uint16)numerator;
	/*~T*/
	temp = (sint32)((uint32)tmp_num << 16)/*lint --e{960}*/;
	if (denominator != 0)
	{
		/* Avoiding 0x80000000/-1 calculation on divw instruction*/
		if ((temp == S32_MIN) && (denominator == (-1)))
		{
			res_ret =  S16_MAX;

		}
		else
		{
			/*Rounding The Result */
			temp = (temp / denominator) + ((2 * (temp % denominator)) / (denominator));
			if (temp >= S16_MAX)
			{
				res_ret =  S16_MAX;
			}
			else
			{
				if (temp <= S16_MIN)
				{
					res_ret =  S16_MIN;
				}
				else
				{
					res_ret =  (sint16)temp;
				}
			}
		}
	}
	else
	{
		if (numerator >= 0)
		{
			res_ret =  S16_MAX;
		}
		else
		{
			res_ret =  S16_MIN;
		}
	}
	return res_ret ;
	/* ## Operation body end [8a4a1cd2-768e-486a-b783-9ecdad9e1b11] */
}

/** This operation shall perform division of sint32 value by sint16 value with overflow and underflow limitation to produce a result of type sint16

@param x_value Numerator

Range:		80000000(H).....7FFFFFFF(H)
		 -2147483648....2147483647
@param y_value Denominator

Range:		8000(H).....7FFF(H)
		  -32768....32767
@return x_value / y_value, result rounded off
- Limit overflow to: 	0x7FFF (32767)
- Limit underflow to: 	0x8000 ( -32768)
- Value after division by 0 with  the numerator being >= 0:    0x7FFF(32767)
- Value after division by 0 with  the numerator being < 0:     0x8000(-32768)

Range:		8000(H).....7FFF(H)
		  -32768....32767 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint16 s16_div_s32_s16(sint32 x_value, sint16 y_value)
{
	/* ## Operation body start [ab95fd5d-ac37-43c5-b0a8-e28bb28cb8f2] */
	sint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s16_div_s32_s16                                                       

      Parameter       type      Hex Range            Physical Range           

Input:                                                                        
       x_value        sint32       80000000..7FFFFFFF  -2147483648..2147483647   
       y_value        sint16       8000..7FFF          -32768..32767             

Output:                                                                       
       res            sint16       8000..7FFF          -32768..32767             

Functionality:                                                                
        res = (x_value)/y_value  with round off                               
        overflow : limit to 7FFFH                                             
        underflow: limit to 8000H                                             
	 */

	/*~E*/
	/*FUNCTION_ID:2*/
	sint32 temp;

	if (y_value  != 0 )
	{
		if (((sint32)x_value == S32_MIN) && (y_value == -1)) /*Maximum +ve value is:2147283647*/
		{
			res_ret =  S16_MAX;
		}
		else
		{
			/* Rounding The Result */
			temp = (x_value / y_value) + ((2 * (x_value % y_value)) / (y_value));

			if (temp >=S16_MAX)
			{
				res_ret =  S16_MAX;
			}
			else
			{
				if (temp <= S16_MIN)
				{
					res_ret =  S16_MIN;
				}
				else
				{
					res_ret =  (sint16)temp;
				}
			}
		}
	}
	else
	{
		if (x_value >= 0)
		{
			res_ret =  S16_MAX;
		}
		else
		{
			res_ret =  S16_MIN;
		}
	}
	return res_ret ;
	/* Check if y_value is zero */
	/* ## Operation body end [ab95fd5d-ac37-43c5-b0a8-e28bb28cb8f2] */
}

/** This operation shall perform division of sint16 value by uint16 value with overflow and underflow limitation to produce a result of type sint16

@param numerator Numerator

Range:		8000(H).....7FFF(H)
		  -32768....32767
@param denominator Denominator

Range:		00(H).....FFFF(H)
		     0....65535
@return (numerator << 16) / denominator, result rounded off
- Limit overflow to: 	0x7FFF (32767)
- Limit underflow to: 	0x8000 ( -32768)
- Value after division by 0 with  the numerator being >= 0:    0x7FFF(32767)
- Value after division by 0 with  the numerator being < 0:     0x8000(-32768)

Range:		8000(H).....7FFF(H)
		  -32768....32767 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint16 s16_fac05_div_s16_u16(sint16 numerator, uint16 denominator)
{
	/* ## Operation body start [86c1cd93-e5a5-4c51-b4ae-0584158ce4f9] */
	/*~A*/
	/*~+:Description*/
	/*
                                                                       FUNCTION: s16_fac05_div_s16_u16                                         

                                                                       Parameter        type      Hex Range       Physical Range        

                                                                       Input:                                                                    
                                                                       x_value          sint16      8000..7FFF      -32768..32767          
                                                                       y_value          uint16         0..FFFF           0..65535          

                                                                       Output:                                                                   
                                                                       res              sint16      8000..7FFF      -32768..32767          

                                                                       Functionality:                                                            
                                                                       res = (x_value<<16)/y_value  with round off                      
                                                                       After round off there is no possibility of overflow and underflow         
                                                                       limitation                                                                
                                                                       For e.g in case of overflow limitation after round off                    
                                                                       32767.5=65536*x_value /y_value                                            
                                                                       so x_value/y_value = 32767.5/65536 which is not a possible case.This holds
                                                                       good for underflow limitation after round off                             
	 */

	/*~E*/
	/*FUNCTION_ID:3*/
	sint32 temp;
	sint16 res_ret;
	uint16 tmp_num = (uint16)numerator;
		    temp = (sint32)((uint32)tmp_num << (uint8)16)/*lint --e{960}*/;
	if (denominator != 0U)
	{
		/* Rounding The Result */
		temp = (temp / (sint32)denominator) + ((2*(temp % (sint32)denominator)) / ((sint32)denominator));
		if (temp >= S16_MAX)
		{
			res_ret =  S16_MAX;
		}
		else
		{
			if (temp <= S16_MIN)
			{
				res_ret =  S16_MIN;
			}
			else
			{
				res_ret =  (sint16)temp;
			}
		}
	}
	else
	{
		if (numerator >= 0)
		{
			res_ret =  S16_MAX;
		}
		else
		{
			res_ret =  S16_MIN;
		}
	}
	return res_ret ;
	/* ## Operation body end [86c1cd93-e5a5-4c51-b4ae-0584158ce4f9] */
}

/** This operation shall perform division of sint16 value by uint16 value with overflow and underflow limitation to produce a result of type sint16

@param numerator Numerator

Range:		8000(H).....7FFF(H)
		  -32768....32767
@param denominator Denominator

Range:		00(H).....FFFF(H)
		     0....65535
@return numerator / denominator, result rounded off
- Limit overflow to: 	0x7FFF (32767)
- Limit underflow to: 	0x8000 ( -32768)
- Value after division by 0 with  the numerator being >= 0:    0x7FFF(32767)
- Value after division by 0 with  the numerator being < 0:     0x8000(-32768)

Range:		8000(H).....7FFF(H)
		  -32768....32767 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint16 s16_div_s16_u16_shl0(sint16 numerator, uint16 denominator)
{
	/* ## Operation body start [4eb9a53e-7418-47bb-bcfc-1600f016663e] */
	sint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
                                                                       FUNCTION: s16_div_s16_u16_shl0                                           

                                                                       Parameter         type      Hex Range       Physical Range       

                                                                       Input:                                                                    
                                                                       x_value            sint516      8000..7FFF      -32768..32767        
                                                                       y_value            uint16         0..FFFF           0..65535        

                                                                       Output:                                                                   
                                                                       res                sint16      8000..7FFF      -32768..32767        

                                                                       Functionality:                                                            
                                                                       res = (x_value)/y_value   with round off                          
                                                                       overflow : limit to 7FFFH                                         
                                                                       underflow: limit to 8000H                                         
                                                                       After round off there is no possibility of overflow and underflow         
                                                                       limitation                                                                
                                                                       For e.g in case of overflow limitation after round off                    
                                                                       32767.5=65536*x_value /y_value                                            
                                                                       so x_value/y_value = 32767.5/65536 which is not a possible case.This holds
                                                                       good for underflow limitation after round off                             
	 */

	/*~E*/
	if (denominator > 0U)
	{
		/* Rounding The Result */

		res_ret = (sint16)(( (sint32)numerator / (sint32)denominator ) + ((2 * (((sint32)numerator %(sint32)denominator))) / (sint32)denominator));

	}
	else
	{
		if (numerator >= 0)
		{
			res_ret = S16_MAX;
		}
		else
		{
			res_ret = S16_MIN;
		}
	}


	return res_ret ;
	/* ## Operation body end [4eb9a53e-7418-47bb-bcfc-1600f016663e] */
}

/** This operation shall perform division of uint16 value by uint16 value with overflow limitation to produce a result of type uint8

@param numerator Numerator

Range:		00(H).....FFFF(H)
		     0....65535
@param denominator Denominator

Range:		00(H).....FFFF(H)
		     0....65535
@return ((numerator << 16) / denominator) >> 8, result rounded off
- Limit overflow to: 	0xFF (255)
- Value after division by 0:    0xFF(255)

Range:		00(H)....FF(H)
		    0....255 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint8 u8_fac1_div_u16_u16(uint16 numerator, uint16 denominator)
{
	/* ## Operation body start [25ef8873-586e-4397-91f3-29e9e7f2ddb4] */
	uint8 res_ret;
	uint16 tmp_var;
	/*~A*/
	/*~+:Description*/
	/*
                                                                       FUNCTION: u8_fac1_div_u16_u16                                                    

                                                                       Parameter         type      Hex Range       Physical Range       

                                                                       Input:                                                                    
                                                                       x_value            uint16         0..FFFF           0..65535         
                                                                       y_value            uint16         0..FFFF           0..65535         

                                                                       Output:                                                                   
                                                                       res                uint8         0..FF             0..255            

                                                                       Functionality:                                                            
                                                                       res =( (x_value<<16)/y_value)>>8  with round off                  
                                                                       overflow : limit to FFH                                           
	 */

	/*~E*/
	/*FUNCTION_ID:5*/
	uint32 temp, tmp_denominator =  denominator;

	/* check if denominator is zero */
	if ( tmp_denominator > 0U )
	{
		/* Rounding The Result */
		temp = (uint32)numerator << 16;
		temp = temp / tmp_denominator;
		tmp_var = (uint16)256 >> 1;
		temp = (( temp + tmp_var ) / (uint16)256);

		/* comapre result with maximum limit */
		if ( temp >= U8_MAX )
		{
			res_ret =  U8_MAX;
		}
		else
		{
			res_ret =  (uint8)temp;
		}
	}
	else
	{
		res_ret =  U8_MAX;
	}
	return res_ret ;
	/* ## Operation body end [25ef8873-586e-4397-91f3-29e9e7f2ddb4] */
}

/** This operation shall perform division of sint32 value by uint16 value with overflow and underflow limitation to produce a result of type uint16

@param x_value Numerator

Range:		80000000(H).....7FFFFFFF(H)
		 -2147483648....2147483647
@param y_value Denominator

Range:		00(H).....FFFF(H)
		     0....65535
@return x_value / y_value, result rounded off
- Limit overflow to: 	0xFFFF (65535)
- Limit underflow to: 	0x0000 (0)
- Value after division by 0 with  the numerator being >= 0:   0xFFFF(65535)
- Value after division by 0 with  the numerator being < 0:     0x0000(0)

Range:		00(H).....FFFF(H)
		     0....65535 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint16 u16_div_s32_u16(sint32 x_value, uint16 y_value)
{
	/* ## Operation body start [49b8b5a8-5b05-4b40-a3da-d7a206819e6f] */
	uint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
                                                                       FUNCTION: u16_div_s32_u16                                                     

                                                                       Parameter        type     Hex Range           Physical Range           

                                                                       Input:                                                                        
                                                                       x_value        sint32      80000000..7FFFFFFF  -2147483648..2147483647  
                                                                       y_value        uint16      0..FFFF              0..65535                

                                                                       Output:                                                                       
                                                                       res            uint16      0..FFFF              0..65535                

                                                                       Functionality:                                                                
                                                                       res = (x_value)/y_value with round off                                
                                                                       overflow : limit to FFFFH                                             
                                                                       underflow: limit to 0H                                                
	 */

	/*~E*/
	/*FUNCTION_ID:6*/
	sint32 temp;
	if (y_value > 0U)
	{
		/* Rounding The Result */
		temp = ((sint32)x_value / (sint32)y_value) + ((2 * ((sint32)x_value % (sint32)y_value)) / (sint32)(y_value));

		if (temp >=(sint32)U16_MAX)
		{
			res_ret =  U16_MAX;
		}
		else
		{
			if (temp <= (sint32)U16_MIN)
			{
				res_ret =  U16_MIN;
			}
			else
			{
				res_ret =  (uint16)temp;
			}
		}
	}
	else
	{
		if (x_value >= 0)
		{
			res_ret =  U16_MAX;
		}
		else
		{
			res_ret =   U16_MIN;
		}
	}

	return res_ret ;
	/* ## Operation body end [49b8b5a8-5b05-4b40-a3da-d7a206819e6f] */
}

/** This operation shall perform division of uint16 value by uint16 value with overflow limitation to produce a result of type uint16

@param numerator Numerator

Range:		00(H).....FFFF(H)
		     0....65535
@param denominator Denominator

Range:		00(H).....FFFF(H)
		     0....65535
@return (numerator << 16) / denominator, result rounded off
- Limit overflow to: 	0xFFFF (65535)
- Value after division by 0:    0xFFFF(65535)

Range:		00(H)....FFFF(H)
		    0....65535 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint16 u16_fac1_div_u16_u16(uint16 numerator, uint16 denominator)
{
	/* ## Operation body start [8faa7811-29cc-4d8b-8bb3-c1e97f7bfd09] */
	uint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
                                                                       FUNCTION: u16_fac1_div_u16_u16                                                

                                                                       Parameter         type      Hex Range       Physical Range       

                                                                       Input:                                                                    
                                                                       x_value           uint16         0..FFFF           0..65535         
                                                                       y_value           uint16         0..FFFF           0..65535         

                                                                       Output:                                                                   
                                                                       res               uint16         0..FFFF           0..65535         

                                                                       Functionality:                                                            
                                                                       res =( (x_value<<16)/y_value) with round off                      

                                                                       After round off there is no possibility of overflow                       
                                                                       limitation                                                                
                                                                       For e.g in case of overflow limitation after round off                    
                                                                       32767.5=65536*x_value /y_value                                            
                                                                       so x_value/y_value = 32767.5/65536 which is not a possible case.          

	 */

	/*~E*/
	uint32 temp, tmp_denominator = denominator;

	/* compare if denomintaor is zero */
	if ( tmp_denominator > 0U)
	{
		temp = ( (uint32)numerator << 16 );
		/* Rounding The Result */
		temp = ( temp + (tmp_denominator >> 1) ) / tmp_denominator;

		/* compare if result is greater than maximum limit */
		if ( temp >= U16_MAX )
		{
			res_ret =  U16_MAX;
		}
		else
		{
			res_ret =  (uint16)temp;
		}
	}
	else
	{
		res_ret =  U16_MAX;
	}
	return res_ret ;
	/* ## Operation body end [8faa7811-29cc-4d8b-8bb3-c1e97f7bfd09] */
}

/** This operation shall perform division of uint32 value by uint16 value with overflow limitation to produce a result of type uint16

@param x_value Numerator

Range:		00(H).....FFFFFFFF(H)
		     0....4294967295
@param y_value Denominator

Range:		00(H).....FFFF(H)
		     0....65535
@return x_value / y_value, result rounded off
- Limit overflow to: 	0xFFFF (65535)
- Value after division by 0:    0xFFFF(65535)

Range:		00(H)....FFFF(H)
		    0....65535 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint16 u16_div_u32_u16(uint32 x_value, uint16 y_value)
{
	/* ## Operation body start [e8d24269-c64f-4c5e-983a-4c661e5c796d] */
	uint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
                                                                       FUNCTION: u16_div_u32_u16                                                

                                                                       Parameter        type        Hex Range    Physical Range           

                                                                       Input:                                                                    
                                                                       x_value        uint32         0..FFFFFFFF   0..4294967295           
                                                                       y_value        uint16         0..FFFF       0..65535                

                                                                       Output:                                                                   
                                                                       res            uint16         0..FFFF       0..65535                

                                                                       Functionality:                                                            
                                                                       res = (x_value)/y_value with round off                            
                                                                       overflow : limit to FFFFH                                         
	 */

	/*~E*/
	uint32 temp_result;

	if (y_value > 0U)
	{
		/* Rounding The Result */
		temp_result= ((x_value / y_value) + ((2U * (x_value % y_value)) / (y_value)));

		if (temp_result >=U16_MAX)
		{
			res_ret =  U16_MAX;
		}
		else
		{
			res_ret =  (uint16)(temp_result);
		}
	}
	else
	{
		res_ret =  U16_MAX;
	}

	return res_ret ;
	/* ## Operation body end [e8d24269-c64f-4c5e-983a-4c661e5c796d] */
}

/** This operation shall multiply sint16 value by an uint16 value and divide the result by sint16 value with overflow and underflow limitation to produce a result of type sint16

@param factor1 First factor

Range:		8000(H).....7FFF(H)
		  -32768....32767
@param factor2 Second factor

Range:		00(H).....FFFF(H)
		    0....65535
@param denominator Denominator

Range:		8000(H).....7FFF(H)
		  -32768....32767
@return (factor1 * factor2) / denominator, result rounded off
- Limit overflow to: 	0x7FFF (32767)
- Limit underflow to: 	0x8000 ( -32768)
- Value after division by 0 with  the numerator being >= 0:    0x7FFF(32767)
- Value after division by 0 with  the numerator being < 0:     0x8000(-32768)

Range:		8000(H).....7FFF(H)
		  -32768....32767 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint16 s16_mul_s16_u16_div_s16(sint16 factor1, uint16 factor2, sint16 denominator)
{
	/* ## Operation body start [c410a674-53c1-4e94-90ad-d39466b04e70] */
	sint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
                                                                       FUNCTION: s16_mul_s16_u16_div_s16                                             

                                                                       Parameter        type      Hex Range       Physical Range          

                                                                       Input:                                                                    
                                                                       fak1              sint16       8000..7FFF      -32768..32767           
                                                                       fak2              uint16          0..FFFF           0..65535           
                                                                       div               sint16       8000..7FFF      -32768..32767           

                                                                       Output:                                                                   
                                                                       res               sint16       8000..7FFF      -32768..32767           

                                                                       Functionality:                                                            
                                                                       res = (fak1   *fak2   )/ div with round off                       
                                                                       overflow : limit to 7FFFH                                         
                                                                       underflow: limit to 8000H                                         
	 */

	/*~E*/
	/*FUNCTION_ID:9*/
	sint32 temp;
	temp = (sint32)factor1 * (sint32)factor2;
	if (denominator != 0)
	{
		/* Rounding The Result */
		temp = (temp / denominator) + ((2 * (temp % denominator)) / (denominator));

		if (temp >=S16_MAX)
		{
			res_ret =  S16_MAX;
		}
		else
		{
			if (temp <=S16_MIN)
			{
				res_ret =  S16_MIN;
			}
			else
			{
				res_ret =  (sint16)temp;
			}
		}
	}
	else
	{
		if (temp >= 0)
		{
			res_ret =  S16_MAX;
		}
		else
		{
			res_ret =  S16_MIN;
		}
	}

	return res_ret ;
	/* ## Operation body end [c410a674-53c1-4e94-90ad-d39466b04e70] */
}

/** This operation shall multiply uint16 value by sint16 value and divide the result by uint16 value with overflow and underflow limitation to produce a result of type sint16

@param factor1 First factor

Range:		00(H).....FFFF(H)
		    0....65535
@param factor2 Second factor

Range:		8000(H).....7FFF(H)
		  -32768....32767
@param denominator Denominator

Range:		00(H).....FFFF(H)
		    0....65535
@return (factor1 * factor2) / denominator, result rounded off
- Limit overflow to: 	0x7FFF (32767)
- Limit underflow to: 	0x8000 ( -32768)
- Value after division by 0 with  the numerator being >= 0:    0x7FFF(32767)
- Value after division by 0 with  the numerator being < 0:     0x8000(-32768)

Range:		8000(H).....7FFF(H)
		  -32768....32767 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint16 s16_mul_u16_s16_div_u16(uint16 factor1, sint16 factor2, uint16 denominator)
{
	/* ## Operation body start [3801f708-6840-42f1-8a5d-f2f892764287] */
	sint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
                                                                       FUNCTION: s16_mul_u16_s16_div_u16                                         

                                                                       Parameter        type      Hex Range       Physical Range          

                                                                       Input:                                                                    
                                                                       fak1              uint16          0..FFFF           0..65535           
                                                                       fak2              sint16       8000..7FFF      -32768..32767           
                                                                       div               uint16          0..FFFF           0..65535           

                                                                       Output:                                                                   
                                                                       res                sint16       8000..7FFF      -32768..32767          

                                                                       Functionality:                                                            
                                                                       res = (fak1 *fak2)/ div with round off                            
                                                                       overflow : limit to 7FFFH                                         
                                                                       underflow: limit to 8000H                                         
	 */

	/*~E*/
	/*FUNCTION_ID:10*/
	sint32 temp;
	temp = (sint32)factor1 * (sint32)factor2;
	if (denominator != 0U)
	{
		/* Rounding The Result */
		temp = (temp / (sint32)denominator) + ((2 * (temp % (sint32)denominator)) / ((sint32)denominator));

		if (temp >=S16_MAX)
		{
			res_ret =  S16_MAX;
		}
		else
		{
			if (temp <=S16_MIN)
			{
				res_ret =  S16_MIN;
			}
			else
			{
				res_ret =  (sint16)temp;
			}
		}
	}
	else
	{
		if (temp >=0)
		{
			res_ret =  S16_MAX;
		}
		else
		{
			res_ret =  S16_MIN;
		}
	}

	return res_ret ;
	/* ## Operation body end [3801f708-6840-42f1-8a5d-f2f892764287] */
}

/** This operation shall multiply sint16 value by uint16 value and divide the result by sint16 value with overflow and underflow limitation to produce a result of type uint16

@param factor1 First factor

Range:		8000(H).....7FFF(H)
		  -32768....32767
@param factor2 Second factor

Range:		00(H).....FFFF(H)
		    0....65535
@param denominator Denominator

Range:		8000(H).....7FFF(H)
		  -32768....32767
@return (factor1 * factor2) / denominator, result rounded off
- Limit overflow to: 	0xFFFF (65535)
- Limit underflow to: 	0x0000 (0)
- Value after division by 0 with  the numerator being >= 0:   0xFFFF(65535)
- Value after division by 0 with  the numerator being < 0:     0x0000(0)

Range:		00(H).....FFFF(H)
		     0....65535 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint16 u16_mul_s16_u16_div_s16(sint16 factor1, uint16 factor2, sint16 denominator)
{
	/* ## Operation body start [5a71a0af-7a80-4a45-99e1-b318e76a9687] */
	/*~A*/
	/*~+:Description*/
	/*
                                                                       FUNCTION: u16_mul_s16_u16_div_s16                                             

                                                                       Parameter        type      Hex Range       Physical Range          

                                                                       Input:                                                                    
                                                                       fak1              sint16       8000..7FFF      -32768..32767           
                                                                       fak2              uint16          0..FFFF           0..65535           
                                                                       denominator       sint16       8000..7FFF      -32768..32767           

                                                                       Output:                                                                   
                                                                       res               uint16          0..FFFF           0..65535           

                                                                       Functionality:                                                            
                                                                       res = (fak1 *fak2)/ denominator with round off                    
                                                                       overflow : limit to FFFFH                                         
                                                                       underflow: limit to 0000H                                         
	 */

	/*~E*/
	/*FUNCTION_ID:11*/
	uint16 res_ret;
	sint32 temp;
	temp = (sint32)factor1 * (sint32)factor2;
	if (denominator != 0)
	{
		/* Rounding The Result */
		temp = (temp / denominator) + ((2 * (temp % denominator)) / (denominator));

		if (temp >=(sint32)U16_MAX)
		{
			res_ret =  U16_MAX;
		}
		else
		{
			if (temp <=(sint32)U16_MIN)
			{
				res_ret =  U16_MIN;
			}
			else
			{
				res_ret =  (uint16)temp;
			}
		}
	}
	else
	{
		if (temp >= 0)
		{
			res_ret =  U16_MAX;
		}
		else
		{
			res_ret =  U16_MIN;
		}
	}

	return res_ret ;
	/* ## Operation body end [5a71a0af-7a80-4a45-99e1-b318e76a9687] */
}

/** This operation shall multiply sint16 value by uint16 value and divide the result by uint16 value with overflow and underflow limitation to produce a result of type uint16

@param factor1 First factor

Range:		8000(H).....7FFF(H)
		  -32768....32767
@param factor2 Second factor

Range:		00(H).....FFFF(H)
		    0....65535
@param denominator Denominator

Range:		00(H).....FFFF(H)
		    0....65535
@return (factor1 * factor2) / denominator, result rounded off
- Limit overflow to: 	0xFFFF (65535)
- Limit underflow to: 	0x0000 (0)
- Value after division by 0 with  the numerator being >= 0:   0xFFFF(65535)
- Value after division by 0 with  the numerator being < 0:     0x0000(0)

Range:		00(H).....FFFF(H)
		     0....65535 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint16 u16_mul_s16_u16_div_u16(sint16 factor1, uint16 factor2, uint16 denominator)
{
	/* ## Operation body start [e7246972-7853-4cde-99b4-6de08f50e8e6] */
	uint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
                                                                       FUNCTION: u16_mul_s16_u16_div_u16                                       

                                                                       Parameter        type      Hex Range       Physical Range          

                                                                       Input:                                                                    
                                                                       fak1              sint16       8000..7FFF      -32768..32767           
                                                                       fak2              uint16       0..FFFF          0..65535               
                                                                       div               uint16       0..FFFF          0..65535               

                                                                       Output:                                                                   
                                                                       res               uint16       0..FFFF          0..65535               

                                                                       Functionality:                                                            
                                                                       res = (fak1*fak2)/ div with round off                             
                                                                       overflow : limit to FFFFH                                         
                                                                       underflow: limit to 0000H                                         
	 */

	/*~E*/
	/*FUNCTION_ID:12*/
	sint32 temp;
	temp = (sint32)factor1 * (sint32)factor2;
	if (denominator > 0U)
	{
		/* Rounding The Result */
		temp = (temp / (sint32)denominator) + ((2 * (temp % (sint32)denominator)) / ((sint32)denominator));

		if (temp >=(sint32)U16_MAX)
		{
			res_ret =  U16_MAX;
		}
		else
		{
			if (temp <=(sint32)U16_MIN)
			{
				res_ret =  U16_MIN;
			}
			else
			{
				res_ret =  (uint16)temp;
			}
		}
	}
	else
	{
		if (temp >= 0)
		{
			res_ret =  U16_MAX;
		}
		else
		{
			res_ret =  U16_MIN;
		}
	}
	return res_ret ;
	/* ## Operation body end [e7246972-7853-4cde-99b4-6de08f50e8e6] */
}

/** This operation shall multiply uint16 value by uint16 value and divide the result by uint16 value with overflow limitation to produce a result of type uint16

@param factor1 First factor

Range:		00(H).....FFFF(H)
		    0....65535
@param factor2 Second factor

Range:		00(H).....FFFF(H)
		    0....65535
@param denominator Denominator

Range:		00(H).....FFFF(H)
		    0....65535
@return (factor1 * factor2) / denominator, result rounded off
- Limit overflow to: 	0xFFFF (65535)
- Value after division by 0:    0xFFFF(65535)

Range:		00(H)....FFFF(H)
		    0....65535 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint16 u16_mul_u16_u16_div_u16(uint16 factor1, uint16 factor2, uint16 denominator)
{
	/* ## Operation body start [6b8f0978-48f4-47dd-9ed7-7ed3f593aafa] */
	uint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
                                                                       FUNCTION: u16_mul_u16_u16_div_u16                                             

                                                                       Parameter        type        Hex Range       Physical Range        

                                                                       Input:                                                                    
                                                                       fak1              uint16          0..FFFF           0..65535           
                                                                       fak2              uint16          0..FFFF           0..65535           
                                                                       div               uint16          0..FFFF           0..65535           

                                                                       Output:                                                                   
                                                                       res               uint16          0..FFFF           0..65535           

                                                                       Functionality:                                                            
                                                                       res = (fak1*fak2)/div with round off                              
                                                                       overflow : limit to FFFFH                                         
	 */

	/*~E*/
	/*FUNCTION_ID:13*/
	uint32 temp, tmp_denominator = denominator;

	/* check if denominator is zero */
	if ( tmp_denominator > 0U )
	{
		temp = (uint32)factor1 * (uint32)factor2;
		/* Rounding The Result */
		temp = (temp + (tmp_denominator >> 1)) / (tmp_denominator);

		/* compare  result with maximum limit */
		if ( temp >= U16_MAX )
		{
			res_ret =  U16_MAX;
		}
		else
		{
			res_ret =  (uint16)temp;
		}
	}
	else
	{
		res_ret =  U16_MAX;
	}

	return res_ret ;
	/* ## Operation body end [6b8f0978-48f4-47dd-9ed7-7ed3f593aafa] */
}

/** This operation shall multiply uint16 value by uint16 value and divide the result by uint32 with overflow limitation to produce a result of type uint16

@param factor1 First factor

Range:		00(H).....FFFF(H)
		    0....65535
@param factor2 Second factor

Range:		00(H).....FFFF(H)
		    0....65535
@param denominator Denominator

Range:		00(H).....FFFFFFFF(H)
		    0....4294967295
@return (factor1 * factor2) / denominator, result rounded off
- Limit overflow to: 	0xFFFF (65535)
- Value after division by 0:    0xFFFF(65535)

Range:		00(H)....FFFF(H)
		    0....65535 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint16 u16_mul_u16_u16_div_u32(uint16 factor1, uint16 factor2, uint32 denominator)
{
	/* ## Operation body start [87305638-36de-4ce3-a1eb-1f385110a971] */
	uint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
                                                                       FUNCTION: u16_mul_u16_u16_div_u32                                       

                                                                       Parameter      type         Hex Range         Physical Range       

                                                                       Input:                                                                    
                                                                       fak1             uint16          0..FFFF           0..65535            
                                                                       fak2             uint16          0..FFFF           0..65535            
                                                                       div              uint32          0..FFFFFFFF       0.. 4294967295      

                                                                       Output:                                                                   
                                                                       res              uint16          0..FFFF           0..65535            

                                                                       Functionality:                                                            
                                                                       res = (fak1*fak2)/div with round off                                             
                                                                       overflow : limit to FFFFH                                         

	 */

	/*~E*/
	/* Check if denominator is non-zero */
	uint32 temp;
	if (denominator > 0U)
	{
		temp =  ( (uint32)factor1 * factor2 );
		/*Round off the result*/
		temp = (uint32)( ( (uint64)temp + (uint64)(denominator >> 1) ) / (uint64)denominator );
		if ( temp >= (uint32)U16_MAX )
		{
			res_ret =  U16_MAX;

		}
		else
		{
			res_ret =  (uint16)(temp);
		}
	}
	else
	{
		res_ret =  U16_MAX;
	}

	return res_ret;
	/* ## Operation body end [87305638-36de-4ce3-a1eb-1f385110a971] */
}

/** This operation shall perform division of uint32 value by an uint16 value to produce a result of uint32 with overflow limitation

@param x_value Numerator

Range:		00(H).....FFFFFFFF(H)
		    0....4294967295
@param y_value Denominator

Range:		00(H).....FFFF(H)
		    0....65535
@return x_value / y_value, result rounded off
Value after division by zero:	0xFFFFFFFF(4294967295)		

Range:		00(H) ... FFFFFFFF(H)
 		    0 ... 4294967295 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint32 u32_div_u32_u16(uint32 x_value, uint16 y_value)
{
	/* ## Operation body start [9148bc7d-c617-4023-a05d-d938c4232a1a] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
                                                                       FUNCTION: u32_div_u32_u16                                               

                                                                       Parameter        type         Hex Range        Physical Range    

                                                                       Input:                                                                    
                                                                       x_value          uint32          0..FFFFFFFF       0.. 4294967295   
                                                                       y_value          uint16          0..FFFF           0..65535         

                                                                       Output:                                                                   
                                                                       res              uint32          0..FFFFFFFF       0.. 4294967295   

                                                                       Functionality:                                                            
                                                                       res = (x_value/y_value) with round off                            

	 */

	/*~E*/
	if (y_value > 0U)
	{
		res_ret =  (uint32)((x_value / y_value) + ((2U * (x_value % y_value)) / (y_value)));
	}
	else
	{
		res_ret =  U32_MAX;
	}

	return res_ret ;
	/* ## Operation body end [9148bc7d-c617-4023-a05d-d938c4232a1a] */
}

/** This operation shall multiply sint16 value by an sint16 value and divide the result by sint16 value with overflow and underflow limitation to produce a result of type sint16

@param factor1 First factor

Range:		8000(H).....7FFF(H)
		  -32768....32767
@param factor2 Second factor

Range:		8000(H).....7FFF(H)
		  -32768....32767
@param denominator Denominator

Range:		8000(H).....7FFF(H)
		  -32768....32767
@return (factor1 * factor2) / denominator, result rounded off
- Limit overflow to: 	0x7FFF (32767)
- Limit underflow to: 	0x8000 ( -32768)
- Value after division by 0 with  the numerator being >= 0:    0x7FFF(32767)
- Value after division by 0 with  the numerator being < 0:     0x8000(-32768)

Range:		8000(H).....7FFF(H)
		  -32768....32767 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint16 s16_mul_s16_s16_div_s16(sint16 factor1, sint16 factor2, sint16 denominator)
{
	/* ## Operation body start [604a3c26-83ba-4650-95b7-4abd437d6422] */
	sint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
                                                                       FUNCTION: s16_mul_s16_s16_div_s16                                       

                                                                       Parameter        type      Hex Range       Physical Range          

                                                                       Input:                                                                    
                                                                       fak1              sint16       8000..7FFF      -32768..32767           
                                                                       fak2              sint16       8000..7FFF      -32768..32767           
                                                                       div               sint16       8000..7FFF      -32768..32767           

                                                                       Output:                                                                   
                                                                       res               sint16       8000..7FFF      -32768..32767           

                                                                       Functionality:                                                            
                                                                       res = (fak1 *fak2)/ div with round off                            
                                                                       overflow : limit to 7FFFH                                         
                                                                       underflow: limit to 8000H                                         
	 */

	/*~E*/
	/*FUNCTION_ID:16*/
	sint32 temp;
	temp = (sint32)factor1 * (sint32)factor2;
	if (denominator != 0)
	{
		/* Rounding The Result */
		temp = (temp / denominator) + ((2 * (temp % denominator))/(denominator));
		if (temp >=S16_MAX)
		{
			res_ret =  S16_MAX;
		}
		else
		{
			if (temp <=S16_MIN)
			{
				res_ret =  S16_MIN;
			}
			else
			{
				res_ret =  (sint16)temp;
			}
		}
	}
	else
	{
		if (temp >= 0)
		{
			res_ret =  S16_MAX;
		}
		else
		{
			res_ret =  S16_MIN;
		}
	}
	return res_ret ;
	/* ## Operation body end [604a3c26-83ba-4650-95b7-4abd437d6422] */
}

/** This operation shall multiply sint16 value by an sint16 value and divide the result by uint16 value with overflow and underflow limitation to produce a result of type sint16

@param data1 First data

Range:		8000(H).....7FFF(H)
		  -32768....32767
@param data2 Second data

Range:		8000(H).....7FFF(H)
		  -32768....32767
@param denominator Denominator

Range:		00(H).....FFFF(H)
		    0....65535
@return (data1 * data2) / denominator, result rounded off
- Limit overflow to: 	0x7FFF (32767)
- Limit underflow to: 	0x8000 ( -32768)
- Value after division by 0 with  the numerator being >= 0:    0x7FFF(32767)
- Value after division by 0 with  the numerator being < 0:     0x8000(-32768)

Range:		8000(H).....7FFF(H)
		  -32768....32767 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint16 s16_mul_s16_s16_div_u16(sint16 data1, sint16 data2, uint16 denominator)
{
	/* ## Operation body start [5ec22499-0cc6-49fb-8279-462555d01954] */
	sint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
                                                                       FUNCTION: s16_mul_s16_s16_div_u16                                         

                                                                       Parameter    type      Hex Range       Physical Range              

                                                                       Input:                                                                    
                                                                       fak1          sint16       8000..7FFF      -32768..32767               
                                                                       fak2          sint16       8000..7FFF      -32768..32767               
                                                                       div           sint16          0..FFFF           0..65535               

                                                                       Output:                                                                   
                                                                       res           sint16       8000..7FFF      -32768..32767               

                                                                       Functionality:                                                            
                                                                       res = (fak1 *fak2)/ div with round off                            
                                                                       overflow : limit to 7FFFH                                         
                                                                       underflow: limit to 8000H                                         
	 */

	/*~E*/
	sint32 temp;
	temp=(sint32)data1*(sint32)data2;

	if (denominator > 0U)
	{
		temp = (temp / (sint32)denominator) + ((2 * (temp % (sint32)denominator)) / ((sint32)denominator));
		if (temp>=S16_MAX)
		{
			res_ret =  S16_MAX;
		}
		else
		{
			if (temp <= S16_MIN)
			{
				res_ret =  S16_MIN;
			}
			else
			{
				res_ret =  (sint16)temp;
			}
		}
	}
	else
	{
		if (temp>=0)
		{
			res_ret =  S16_MAX;
		}
		else
		{
			res_ret =  S16_MIN;
		}
	}

	return res_ret ;
	/* ## Operation body end [5ec22499-0cc6-49fb-8279-462555d01954] */
}

/** This operation shall perform division of an uint32 value by an sint32 to produce a result of uint32 with underflow limitation

@param numerator Numerator

Range:		00(H).....FFFFFFFF(H)
		    0....4294967295
@param denominator Denominator

Range:		80000000(H).....7FFFFFFF(H)
		 -2147483648....2147483647
@return numerator / denominator, result rounded off
- Limit underflow to: 0x00(0)
- Value after division by zero:	0xFFFFFFFF(4294967295)

Range:		00(H) ... FFFFFFFF(H)
 		    0 ... 4294967295 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint32 u32_div_u32_s32(uint32 numerator, sint32 denominator)
{
	/* ## Operation body start [edac47d9-a09f-498d-afb1-ed1aa2980822] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
                                                                       FUNCTION: u32_div_u32_s32                                                  

                                                                       Parameter        type     Hex Range            Physical Range            

                                                                       Input:                                                                          
                                                                       numerator      uint32      0..FFFFFFFFH          0..4294967295            
                                                                       denominator    sint32      80000000..7FFFFFFF    -2147483648..2147483647  

                                                                       Output:                                                                         
                                                                       res            uint32      0..FFFFFFFFH          0..4294967295            

                                                                       Functionality:                                                                  
                                                                       res = (numerator)/denominator with round off                            
                                                                       underflow: limit to 00000000H                                           
	 */

	/*~E*/
	uint32 res;
	/* Check if denominator is non-zero */
	if ( denominator != 0)
	{
		/* Check for underflow */
		if ( denominator  > 0 )
		{
			/* Calculate result with round-off */
			res = (uint32)(((sint64)numerator / (sint64)denominator) +( ((sint64)2 * ((sint64)numerator % (sint64)denominator)) / (sint64)denominator));

			res_ret =  (uint32)res;
		}
		else
		{
			res_ret =  U32_MIN;
		}
	}
	else
	{
		res_ret =  U32_MAX;
	}

	return res_ret ;
	/* ## Operation body end [edac47d9-a09f-498d-afb1-ed1aa2980822] */
}

/** This operation shall perform division of sint32 value by an uint32 value to produce a result of uint32 with underflow limitation

@param numerator Numerator

Range:		80000000(H).....7FFFFFFF(H)
		 -2147483648....2147483647
@param denominator Denominator

Range:		00(H).....FFFFFFFF(H)
		    0....4294967295
@return numerator / denominator, result rounded off
- Limit underflow to: 0x00(0)
- Value after division by 0 with  the numerator being >= 0:    0xFFFFFFFF(4294967295)
- Value after division by 0 with  the numerator being < 0:     0x00(0)		
Range:		00(H) ... FFFFFFFF(H)
 		    0 ... 4294967295 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint32 u32_div_s32_u32(sint32 numerator, uint32 denominator)
{
	/* ## Operation body start [e6f3720b-de83-4ab9-95bb-275409817a80] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
                                                                       FUNCTION: u32_div_s32_u32                                                    

                                                                       Parameter        type     Hex Range           Physical Range           

                                                                       Input:                                                                        
                                                                       numerator      sint32      80000000..7FFFFFFF  -2147483648..2147483647  
                                                                       denominator    uint32      0..FFFFFFFF          0..4294967295           

                                                                       Output:                                                                       
                                                                       res            uint32      0..FFFFFFFF          0..4294967295           

                                                                       Functionality:                                                                
                                                                       res = (numerator)/denominator with round off                          
                                                                       underflow: limit to 00000000H                                         
	 */

	/*~E*/
	uint32 res;
	/* Check if denominator is non-zero */
	if ( denominator != 0U )
	{
		/* Check if signed input is negative */
		if ( numerator < 0 )
		{
			/* Underflow case */
			res_ret =  U32_MIN;
		}
		else
		{
			/* Calculate result with round-off */
			res = ((uint32)numerator / denominator) + ((2U * ((uint32)numerator % denominator)) / (denominator));

			res_ret =  (uint32)res;
		}
	}
	else
	{
		/* Check if numerator is negative or positive */
		if ( numerator >= 0 )
		{
			res_ret =  U32_MAX;
		}
		else
		{
			res_ret =  U32_MIN;
		}

	}

	return res_ret ;
	/* ## Operation body end [e6f3720b-de83-4ab9-95bb-275409817a80] */
}

/** This operation shall perform division of sint32 value by an sint32 value to produce a result of uint32 with underflow limitation

@param numerator Numerator

Range:		80000000(H).....7FFFFFFF(H)
		 -2147483648....2147483647
@param denominator Denominator

Range:		80000000(H).....7FFFFFFF(H)
		 -2147483648....2147483647
@return numerator / denominator, result rounded off
- Limit underflow to: 0x00(0)
- Value after division by 0 with  the numerator being >= 0:    0xFFFFFFFF(4294967295)
- Value after division by 0 with  the numerator being < 0:     0x00(0)		
Range:		00(H) ... FFFFFFFF(H)
 		    0 ... 4294967295 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint32 u32_div_s32_s32(sint32 numerator, sint32 denominator)
{
	/* ## Operation body start [77e57e08-2b8d-42ec-a4e9-33f4e14a8a8b] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
                                                                       FUNCTION: u32_div_s32_s32                                                     

                                                                       Parameter        type     Hex Range           Physical Range           

                                                                       Input:                                                                        
                                                                       numerator      sint32      80000000..7FFFFFFF  -2147483648..2147483647  
                                                                       denominator    sint32      80000000..7FFFFFFF  -2147483648..2147483647  

                                                                       Output:                                                                       
                                                                       res            uint32      0..FFFFFFFF          0..4294967295           

                                                                       Functionality:                                                                
                                                                       res = (numerator)/denominator with round off                          
                                                                       underflow: limit to 00000000H                                         
	 */

	/*~E*/
	uint32 res;
	/* Check if denominator is non-zero */
	if ( denominator  != 0 )
	{
		/* Check if one of the input is not signed */
		if ( (numerator < 0) && (denominator < 0))
		{
			/* Calculate result with round-off */
			res = (((uint32)(-numerator)) /   ((uint32)(-denominator))) + ((2U * (((uint32)(-numerator)) % ((uint32)(-denominator)))) / ((uint32)(-denominator)));

			res_ret =  (uint32)res;
		}
		else
		{
			if ( (numerator > 0) && (denominator > 0) )
			{
				res = ((uint32)numerator / (uint32)denominator) + ((2U * ((uint32)numerator % (uint32)denominator)) / ((uint32)denominator));

				res_ret =  (uint32)res;
			}
			else
			{
				res_ret =  U32_MIN;
			}
		}
	}
	else
	{
		/* check if numerator is positive or negative */
		if ( numerator >= 0 )
		{
			res_ret =  U32_MAX;
		}
		else
		{
			res_ret = U32_MIN;
		}

	}

	return res_ret ;
	/* ## Operation body end [77e57e08-2b8d-42ec-a4e9-33f4e14a8a8b] */
}

/** This operation shall perform division of uint32 value by an uint32 value to produce a result of uint32

@param numerator Numerator

Range:		00(H).....FFFFFFFF(H)
		    0....4294967295
@param denominator Denominator

Range:		00(H).....FFFFFFFF(H)
		    0....4294967295
@return numerator / denominator, result rounded off
Value after division by zero:    0xFFFFFFFF(4294967295)

Range:		00(H) ... FFFFFFFF(H)
 		    0 ... 4294967295 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint32 u32_div_u32_u32(uint32 numerator, uint32 denominator)
{
	/* ## Operation body start [02cc95ce-a41f-44f6-8936-1a9a0313bb83] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
                                                                       FUNCTION: u32_div_u32_u32                                                   

                                                                       Parameter        type     Hex Range           Physical Range           

                                                                       Input:                                                                        
                                                                       numerator      uint32      0..FFFFFFFF         0..4294967295            
                                                                       denominator    uint32      0..FFFFFFFF         0..4294967295            

                                                                       Output:                                                                       
                                                                       res            uint32      0..FFFFFFFF         0..4294967295            

                                                                       Functionality:                                                                
                                                                       res = (numerator)/denominator with round off                          
	 */

	/*~E*/
	uint32 res, rem,tmp_denominator;
	/* Check if denominator is non-zero */
	if (denominator !=0U)
	{
		/* Calculate result with round-off */
		res = (numerator / denominator);
		rem = numerator % denominator ;

		/* Check if denominator is odd */
		if ( (denominator % 2U) != 0U )
		{
			tmp_denominator = (denominator / 2U) + 1U;
		}
		else
		{
			tmp_denominator = denominator / 2U;
		}
		if ( rem >= tmp_denominator )
		{
			res++ ;
		}
		res_ret =  (uint32)res;
	}
	else
	{
		res_ret =  U32_MAX;
	}

	return res_ret ;
	/* ## Operation body end [02cc95ce-a41f-44f6-8936-1a9a0313bb83] */
}

/** This operation shall perform division of uint32 value by an sint32 value to produce a result of sint32 with underflow and overflow limitation

@param numerator Numerator

Range:		00(H).....FFFFFFFF(H)
		    0....4294967295
@param denominator Denominator

Range:		80000000(H).....7FFFFFFF(H)
		 -2147483648....2147483647
@return numerator / denominator, result rounded off
- Limit overflow to: 0x7FFFFFFF(2147483647)
- Limit underflow to: 0x80000000(-2147483648)
- Value after division by zero:    0x7FFFFFFF(2147483647)

Range:		80000000(H) ... 7FFFFFFF(H)
 		 -2147483648 ... 2147483647 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint32 s32_div_u32_s32(uint32 numerator, sint32 denominator)
{
	/* ## Operation body start [6d2a31a2-1cb2-42a8-a873-18546101e70e] */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
                                                                       FUNCTION: s32_div_u32_s32                                                    

                                                                       Parameter        type     Hex Range           Physical Range           

                                                                       Input:                                                                        
                                                                       numerator      uint32      0..FFFFFFFF          0..4294967295           
                                                                       denominator    sint32      80000000..7FFFFFFF  -2147483648..2147483647  

                                                                       Output:                                                                       
                                                                       res            sint32      80000000..7FFFFFFF  -2147483648..2147483647  

                                                                       Functionality:                                                                
                                                                       res = (numerator)/denominator with round off                          
                                                                       overflow : limit to 7FFFFFFFH                                         
                                                                       underflow: limit to 80000000H                                         
	 */

	/*~E*/
	uint32 res;
	/* Check if signed input is positive */
	if ( denominator > 0 )
	{
		/*  Calculate result with round-off */
		res = (numerator / (uint32)denominator) + ((2U * (numerator % (uint32)denominator)) / ((uint32)denominator));

		/* Check for overflow */
		if ( res > (uint32)S32_MAX )
		{
			res_ret =  S32_MAX;
		}
		else
		{
			res_ret =  (sint32)res;
		}
	}
	else
	{
		if ( denominator < 0 )
		{
			/* Calculate result with round-off */
			res = (numerator / (uint32)(-denominator)) + ((2U * (numerator % (uint32)(-denominator))) / ((uint32)(-denominator)));

			/* Check for underflow */
			if ( res > (uint32)S32_MAX )
			{
				res_ret =  S32_MIN;
			}
			else
			{
				res_ret =  -((sint32)res);
			}
		}
		else
		{
			res_ret =  S32_MAX;
		}
	}
	return res_ret ;
	/* ## Operation body end [6d2a31a2-1cb2-42a8-a873-18546101e70e] */
}

/** This operation shall perform division of sint32 value by an uint32 value to produce a result of sint32

@param numerator Numerator

Range:		80000000(H).....7FFFFFFF(H)
		 -2147483648....2147483647
@param denominator Denominator

Range:		00(H).....FFFFFFFF(H)
		    0....4294967295
@return numerator / denominator, result rounded off
- Value after division by 0 with  the numerator being >= 0:    0x7FFFFFFF(2147483647)
- Value after division by 0 with  the numerator being < 0:     0x80000000(-2147483648)

Range:		80000000(H) ... 7FFFFFFF(H)
 		 -2147483648 ... 2147483647 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint32 s32_div_s32_u32(sint32 numerator, uint32 denominator)
{
	/* ## Operation body start [79609eb8-e610-439a-a735-f541fde90975] */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
                                                                       FUNCTION: s32_div_s32_u32                                                  

                                                                       Parameter        type     Hex Range           Physical Range           

                                                                       Input:                                                                        
                                                                       numerator      sint32      80000000..7FFFFFFF  -2147483648..2147483647  
                                                                       denominator    uint32      0..FFFFFFFF         0..4294967295            

                                                                       Output:                                                                       
                                                                       res            sint32      80000000..7FFFFFFF  -2147483648..2147483647  

                                                                       Functionality:                                                                
                                                                       res = (numerator)/denominator with round off                          
	 */

	/*~E*/
	uint32 res, rem,tmp_denominator;
	sint32 res1;
	/* Check if denominator is non-zero */
	if ( denominator != 0U )
	{
		/* Check if signed input is positive */
		if ( numerator > 0 )
		{
			/*  Calculate result with round-off */
			res1 = (sint32)( ( (uint32)numerator / denominator) + ((2U * ((uint32)numerator % denominator) ) / denominator));

			res_ret =  res1;
		}
		else
		{
			/* Calculate result with round-off */
			res = ((uint32)(-numerator))/ denominator;
			rem =((uint32)(-numerator)) % denominator;

			/* Check if denominator is odd */
			if ( (denominator % 2U) != 0U)
			{
				tmp_denominator = (denominator /2U) + 1U;
			}
			else
			{
				tmp_denominator = denominator / 2U;
			}
			if ( rem >= tmp_denominator )
			{
				res++;
			}
			res_ret =  -((sint32)res);
		}
	}
	else
	{
		/* Check if numerator is positive or negative */
		if ( numerator >= 0 )
		{
			res_ret =  S32_MAX;
		}
		else
		{
			res_ret =  S32_MIN;
		}

	}

	return res_ret ;
	/* ## Operation body end [79609eb8-e610-439a-a735-f541fde90975] */
}

/** This operation shall perform division of sint32 value by an sint32 value to produce a result of sint32 with overflow limitation

@param numerator Numerator

Range:		80000000(H).....7FFFFFFF(H)
		 -2147483648....2147483647
@param denominator Denominator

Range:		80000000(H).....7FFFFFFF(H)
		 -2147483648....2147483647
@return numerator / denominator, result rounded off
- Limit overflow to: 0x7FFFFFFF(2147483647)
- Value after division by 0 with  the numerator being >= 0:    0x7FFFFFFF(2147483647)
- Value after division by 0 with  the numerator being < 0:     0x80000000(-2147483648)

Range:		80000000(H) ... 7FFFFFFF(H)
 		 -2147483648 ... 2147483647 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint32 s32_div_s32_s32(sint32 numerator, sint32 denominator)
{
	/* ## Operation body start [f67471fb-d2ea-428c-af6b-0060051f100f] */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
                                                                       FUNCTION: s32_div_s32_s32                                                     

                                                                       Parameter        type     Hex Range           Physical Range           

                                                                       Input:                                                                        
                                                                       numerator      sint32      80000000..7FFFFFFF  -2147483648..2147483647  
                                                                       denominator    sint32      80000000..7FFFFFFF  -2147483648..2147483647  

                                                                       Output:                                                                       
                                                                       res            sint32      80000000..7FFFFFFF  -2147483648..2147483647  

                                                                       Functionality:                                                                
                                                                       res = (numerator)/denominator with round off                          
                                                                       with overflow limitation 7FFFFFFFH                                  */

	/*~E*/
	uint32 tmp1;
	uint32 tmp2;

	if (denominator == 0)
	{
		if (numerator >= 0)
		{
			res_ret =  S32_MAX;
		}
		else
		{
			res_ret =  S32_MIN;
		}
	}
	else
	{
		if (numerator >= 0)
		{
			tmp1 = (uint32)numerator;

		}
		else
		{
			tmp1 = (uint32)(-numerator);

		}
		if (denominator > 0)
		{
			tmp2 = (uint32)denominator;

		}
		else
		{
			tmp2 = (uint32)(-denominator);

		}
		tmp1 = (tmp1 + (tmp2 / 2U)) / tmp2;
		if (((numerator >= 0) && (denominator > 0)) || ((numerator < 0 ) && (denominator < 0)))
		{
			if (tmp1 > (uint32)S32_MAX)
			{
				res_ret =  S32_MAX;
			}
			else
			{
				res_ret =  (sint32)tmp1;
			}
		}
		else
		{
			res_ret =  -((sint32)tmp1);
		}
	}
	/*~T*/


	return res_ret ;
	/* ## Operation body end [f67471fb-d2ea-428c-af6b-0060051f100f] */
}

/** This operation shall perform division of sint32 value by an uint32 value to produce a result of sint16 with underflow and overflow limitation

@param numerator Numerator

Range:		80000000(H).....7FFFFFFF(H)
		 -2147483648....2147483647
@param denominator Denominator

Range:		00(H).....FFFFFFFF(H)
		    0....4294967295
@return numerator / denominator, result rounded off
- Limit overflow to: 0x7FFF(32767)
- Limit underflow to: 0x8000(-32768)
- Value after division by 0 with  the numerator being >= 0:    0x7FFF(32767)
- Value after division by 0 with  the numerator being < 0:     0x8000(-32768)

Range:		8000(H) ... 7FFF(H)
 		 -32768 ... 32767 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint16 s16_div_s32_u32(sint32 numerator, uint32 denominator)
{
	/* ## Operation body start [67a11960-1b55-475e-91ea-8c95f9b47137] */
	sint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
                                                                       FUNCTION: s16_div_s32_u32                                                    

                                                                       Parameter        type     Hex Range           Physical Range             

                                                                       Input:                                                                          
                                                                       numerator        sint32      80000000..7FFFFFFF  -2147483648..2147483647  
                                                                       denominator      uint32      0..FFFFFFFF         0..4294967295            

                                                                       Output:                                                                         
                                                                       res              sint16      8000..7FFF          -32768..32767            

                                                                       Functionality:                                                                  
                                                                       res = (numerator)/denominator with round off                            
                                                                       with overflow limit : 7FFFH                                             
                                                                       underflow limit :8000H                                             
	 */

	/*~E*/
	sint32 res;
	uint32 res1, rem,tmp_denominator;
	/* Check if denominator is non-zero */
	if ( denominator != 0U )
	{
		/* Check if signed input is positive */
		if ( numerator > 0 )
		{
			/* Calculate result with round-off */
			res1 = (uint32)(((sint64)numerator / (sint64)denominator) + (((sint64)2 * ((sint64)numerator % (sint64)denominator)) / (sint64)(denominator)));

			/* Check for overflow */
			if ( res1 > (uint32)S16_MAX )
			{
				res_ret =  S16_MAX;
			}
			else
			{
				res_ret =  (sint16)res1;
			}
		}
		else
		{
			/* Calculate result with round-off */
			res1 = (uint32)(-numerator) / denominator;
			rem =(uint32)(-numerator) % denominator;

			/* Check if denominator is odd */
			if ( (denominator % 2U) != 0U )
			{
				tmp_denominator = (denominator/ 2U) + 1U;
			}
			else
			{
				tmp_denominator = denominator / 2U;
			}
			if ( rem >= tmp_denominator )
			{
				res1++;
			}
			res = -((sint32)res1);
			/* Check for underflow */
			if ( res < (sint32)S16_MIN )
			{
				res_ret =  S16_MIN;
			}
			else
			{
				res_ret =  (sint16)res;
			}
		}
	}
	else
	{
		/* Check if numerator is positive or negative */
		if (numerator >= 0)
		{
			res_ret =  S16_MAX;
		}
		else
		{
			res_ret =  S16_MIN;
		}

	}

	return res_ret ;
	/* ## Operation body end [67a11960-1b55-475e-91ea-8c95f9b47137] */
}

/** This operation shall multiply an uint32 value by an uint32 value and divide the result by an uint32 value with overflow limitation to produce a result of type uint32

@param factor1 First factor

Range:		00(H).....FFFFFFFF(H)
		    0....4294967295
@param factor2 Second factor

Range:		00(H).....FFFFFFFF(H)
		    0....4294967295
@param denominator Denominator

Range:		00(H).....FFFFFFFF(H)
		    0....4294967295
@return (factor1 * factor2) / denominator, result rounded off
- Limit overflow to: 0xFFFFFFFF(4294967295)
- Value after division by zero:    0xFFFFFFFF(4294967295)

Range:		00(H) ... FFFFFFFF(H)
 		     0....4294967295 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint32 u32_mul_u32_u32_div_u32(uint32 factor1, uint32 factor2, uint32 denominator)
{
	/* ## Operation body start [e250bef4-5dda-4f80-b461-793a30db85f7] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u32_mul_u32_u32_div_u32                                            

       Parameter        type        Hex Range                   Physical Range  

Input:                                                                          
      factor1           uint32          00000000..FFFFFFFF         0..4294967295   
      factor2           uint32          00000000..FFFFFFFF         0..4294967295   
      denominator       uint32          00000000..FFFFFFFF         0..4294967295   

Output:                                                                         
      res               uint32          00000000..FFFFFFFF         0..4294967295   

Functionality:                                                                  
        res = (factor1*factor2)/div with round off                              
        overflow : limit to FFFFFFFF H                                           
	 */

	/*~E*/
	uint64 temp;
	/* Check if denominator is zero */
	if ( denominator != 0U )
	{
		temp = (uint64)((uint64)factor1 * (uint64)factor2);
		/* Rounding The Result */
		temp = (temp + (uint64)(denominator >> 1)) / (uint64)(denominator);

		/* Compare  result with maximum limit */
		if ( temp >= U32_MAX )
		{
			res_ret =  U32_MAX;
		}
		else
		{
			res_ret =  (uint32)temp;
		}
	}
	else
	{
		res_ret =  U32_MAX;
	}

	return res_ret ;
	/* ## Operation body end [e250bef4-5dda-4f80-b461-793a30db85f7] */
}

/** This operation shall multiply an uint32 value by an uint32 value and divide the result by an sint32 value with overflow and underflow limitation to produce a result of type uint32

@param factor1 First factor

Range:		00(H).....FFFFFFFF(H)
		    0....4294967295
@param factor2 Second factor

Range:		00(H).....FFFFFFFF(H)
		    0....4294967295
@param denominator Denominator

Range:		80000000(H).....7FFFFFFF(H)
		 -2147483648....2147483647
@return (factor1 * factor2) / denominator, result rounded off
- Limit overflow to: 0xFFFFFFFF(4294967295)
- Limit underflow to: 0x00(0)
- Value after division by zero:    0xFFFFFFFF(4294967295)

Range:		00(H) ... FFFFFFFF(H)
 		     0....4294967295 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint32 u32_mul_u32_u32_div_s32(uint32 factor1, uint32 factor2, sint32 denominator)
{
	/* ## Operation body start [90c5ce15-a9e9-40b1-81f5-db34e828427b] */
	uint32 res_ret,tmp_var;

	/*~A*/
	/*~+:Description*/
	/*
                                                                                     FUNCTION: u32_mul_u32_u32_div_s32                                                          

                                                                                     Parameter        type        Hex Range                   Physical Range          

                                                                                     Input:                                                                                  
                                                                                     factor1           uint32          00000000..FFFFFFFF                   0..4294967295 
                                                                                     factor2           uint32          00000000..FFFFFFFF                   0..4294967295 
                                                                                     denominator       sint32          80000000..7FFFFFFF         -2147483648..2147483647 

                                                                                     Output:                                                                                 
                                                                                     res               uint32          00000000..FFFFFFFF         0..4294967295           

                                                                                     Functionality:                                                                          
                                                                                     res = (factor1*factor2)/div with round off                                      
                                                                                     underflow : limit to 00000000 H                                                 
                                                                                     overflow  : limit to FFFFFFFF H                                                 
	 */

	/*~E*/
	uint64 temp;
	/* Check if denominator is zero */
	if ( denominator != 0 )
	{
		if ( denominator > 0 )
		{
			temp = (uint64)factor1 * factor2;
			/* Rounding The Result */
			tmp_var = (uint32)denominator >> 1;
			temp = ((temp + tmp_var) / (uint32)(denominator));

			/* Compare  result with maximum limit */
			if ( temp >= U32_MAX )
			{
				res_ret =  U32_MAX;
			}
			else
			{
				res_ret =  (uint32)temp;
			}
		}
		else
		{
			res_ret =  U32_MIN;
		}
	}
	else
	{
		res_ret =  U32_MAX;
	}

	return res_ret ;
	/* ## Operation body end [90c5ce15-a9e9-40b1-81f5-db34e828427b] */
}

/** This operation shall multiply an uint32 value by an sint32 value and divide the result by an uint32 value with overflow and underflow limitation to produce a result of type uint32

@param factor1 First factor

Range:		00(H).....FFFFFFFF(H)
		    0....4294967295
@param factor2 Second factor

Range:		80000000(H).....7FFFFFFF(H)
		 -2147483648....2147483647
@param denominator Denominator

Range:		00(H).....FFFFFFFF(H)
		    0....4294967295
@return (factor1 * factor2) / denominator, result rounded off
- Limit overflow to: 0xFFFFFFFF(4294967295)
- Limit underflow to: 0x00(0)
- Value after division by 0 with  the numerator being >= 0:    0xFFFFFFFF(4294967295)
- Value after division by 0 with  the numerator being < 0:     0x00(0)

Range:		00(H) ... FFFFFFFF(H)
 		     0 ... 4294967295 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint32 u32_mul_u32_s32_div_u32(uint32 factor1, sint32 factor2, uint32 denominator)
{
	/* ## Operation body start [5fb55011-7be7-4b38-b39b-876c32744933] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
                                                                                     FUNCTION: u32_mul_u32_s32_div_u32                                                       

                                                                                     Parameter        type        Hex Range                   Physical Range          

                                                                                     Input:                                                                                  
                                                                                     factor1           uint32          00000000..FFFFFFFF                   0..4294967295 
                                                                                     factor2           sint32          80000000..7FFFFFFF         -2147483648..2147483647 
                                                                                     denominator       uint32          00000000..FFFFFFFF                   0..4294967295 

                                                                                     Output:                                                                                 
                                                                                     res               uint32          00000000..FFFFFFFF         0..4294967295           

                                                                                     Functionality:                                                                          
                                                                                     res = (factor1*factor2)/div with round off                                      
                                                                                     underflow : limit to 00000000 H                                                 
                                                                                     overflow  : limit to FFFFFFFF H                                                 
	 */

	/*~E*/
	uint64 temp;
	/* Check if denominator is zero */
	if ( denominator > 0U )
	{
		if ( factor2 < 0 )
		{
			res_ret =  U32_MIN;
		}
		else
		{
			temp = (uint64)((uint64)factor1 * (uint32)factor2);
			/* Rounding The Result */
			temp = (temp + (uint64)(denominator >> 1)) / (uint64)(denominator);

			/* Compare  result with maximum limit */
			if ( temp >= U32_MAX )
			{
				res_ret =  U32_MAX;
			}
			else
			{
				res_ret =  (uint32)temp;
			}
		}
	}
	else
	{
		if (factor2>=0)
		{
			res_ret =  U32_MAX;

		}
		else
		{
			res_ret =  U32_MIN;
		}
	}

	return res_ret ;
	/* ## Operation body end [5fb55011-7be7-4b38-b39b-876c32744933] */
}

/** This operation shall multiply an uint32 value by an sint32 value and divide the result by an sint32 value with overflow and underflow limitation to produce a result of type uint32

@param factor1 First factor

Range:		00(H).....FFFFFFFF(H)
		    0....4294967295
@param factor2 Second factor

Range:		80000000(H).....7FFFFFFF(H)
		 -2147483648....2147483647
@param denominator Denominator

Range:		80000000(H).....7FFFFFFF(H)
		 -2147483648....2147483647
@return (factor1 * factor2) / denominator, result rounded off
- Limit overflow to: 0xFFFFFFFF(4294967295)
- Limit underflow to: 0x00(0)
- Value after division by 0 with  the numerator being >= 0:    0xFFFFFFFF(4294967295)
- Value after division by 0 with  the numerator being < 0:     0x00(0)

Range:		00(H) ... FFFFFFFF(H)
 		     0 ... 4294967295 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint32 u32_mul_u32_s32_div_s32(uint32 factor1, sint32 factor2, sint32 denominator)
{
	/* ## Operation body start [be4aa109-ccfd-4b96-b508-6241e3964225] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
                                                                                     FUNCTION: u32_mul_u32_s32_div_s32                                                    

                                                                                     Parameter        type        Hex Range                   Physical Range          

                                                                                     Input:                                                                                  
                                                                                     factor1           uint32          00000000..FFFFFFFF                   0..4294967295 
                                                                                     factor2           sint32          80000000..7FFFFFFF         -2147483648..2147483647 
                                                                                     denominator       sint32          80000000..7FFFFFFF         -2147483648..2147483647 

                                                                                     Output:                                                                                 
                                                                                     res               uint32          00000000..FFFFFFFF         0..4294967295           

                                                                                     Functionality:                                                                          
                                                                                     res = (factor1*factor2)/div with round off                                      
                                                                                     underflow : limit to 00000000 H                                                 
                                                                                     overflow  : limit to FFFFFFFF H                                                 
	 */

	/*~E*/
	uint64 product;
	sint64 deno_zero_product;
	uint32 abs_factor2,abs_denominator;
	uint32 upper_32bit,upper_back,lower_32bit,upper_32bit_quotient,lower_32bit_quotient,lower_32bit_rem;
	uint32 final_result,inter_result;
	sint32 sign_factor2,sign_denominator;
	sint32 power_value,leading_zeros_count,prev_power_value;
	if (denominator<0)
	{
		sign_denominator=-1;
		abs_denominator=(uint32)(-denominator);
	}
	else
	{
		sign_denominator=1;
		abs_denominator=(uint32)denominator;
	}
	if (abs_denominator != 0U)
	{
		if (factor2<0)
		{
			sign_factor2=-1;
			abs_factor2=(uint32)(-factor2);
		}
		else
		{
			sign_factor2=1;
			abs_factor2=(uint32)factor2;
		}
		/*Checking for the sign of Final result*/
		if ((sign_factor2*sign_denominator)==-1)
		{
			res_ret =  (uint32)U32_MIN;
		}
		else
		{
			product= (uint64)((uint64)factor1*(uint64)abs_factor2);
			/*Separation of product into upper and lower 32 bit words*/
			upper_32bit = (uint32)(product>>32);
			lower_32bit = (uint32)product;
			upper_back = upper_32bit;

			upper_32bit_quotient=upper_32bit/abs_denominator;
			/*Checking for Overflow*/
			if (upper_32bit_quotient != 0U)
			{
				res_ret =  (uint32)U32_MAX;
			}
			else
			{
				power_value=32;
				final_result=0;

				leading_zeros_count=(sint32)u8_cntlz_u32_math(upper_32bit);
				power_value-=leading_zeros_count;
				/*Loop iteration to calculate Quotient part from upper 32 bit of the product*/
				while (power_value>=0)
				{
					/* Dividend for the next iteration is the remainder from the current iteration*/
					upper_32bit=upper_32bit<<leading_zeros_count;
					inter_result=upper_32bit/abs_denominator;
					inter_result=inter_result<<power_value;
					final_result+=inter_result;
					/* Remainder Calculation*/
					upper_32bit=upper_32bit%abs_denominator;
					leading_zeros_count=(sint32)u8_cntlz_u32_math(upper_32bit);
					power_value-=leading_zeros_count;

				}
				prev_power_value=power_value+leading_zeros_count;
				/*Making the final remainder from upper_32bit of the same magnitude of lower 32 bit*/
				upper_32bit=upper_32bit<<prev_power_value;
				/*Quotient and Remainder Calculation from Lower 32 bit of product*/
				lower_32bit_quotient=lower_32bit/abs_denominator;
				lower_32bit_rem=lower_32bit%abs_denominator;
				/*Addition of remainders from upper and lower 32 bit of product*/
				lower_32bit=upper_32bit+lower_32bit_rem;
				/*Rounded result calculation*/
				inter_result=(lower_32bit/abs_denominator)+((2U*(lower_32bit%abs_denominator))/abs_denominator);
				final_result= final_result+inter_result+lower_32bit_quotient;
				/*Over flow checking*/
				if ((upper_back != 0U)&& (final_result == 0U))
				{
					res_ret =  U32_MAX;
				}
				else
				{
					res_ret =  final_result;
				}
			}
		}
	}
	else
	{
		deno_zero_product = (sint64)factor1 * (sint64)factor2;

		if (deno_zero_product >= 0)
		{
			res_ret =    (uint32)U32_MAX;
		}
		else
		{
			res_ret =  (uint32)U32_MIN;
		}
	}

	return res_ret ;
	/* ## Operation body end [be4aa109-ccfd-4b96-b508-6241e3964225] */
}

/** This operation shall multiply an sint32 value by an sint32 value and divide the result by an sint32 value with overflow and underflow limitation to produce a result of type sint32

@param factor1 First factor

Range:		80000000(H).....7FFFFFFF(H)
		 -2147483648....2147483647
@param factor2 Second factor

Range:		80000000(H).....7FFFFFFF(H)
		 -2147483648....2147483647
@param denominator Denominator

Range:		80000000(H).....7FFFFFFF(H)
		 -2147483648....2147483647
@return (factor1 * factor2) / denominator, result rounded off
- Limit overflow to: 0x7FFFFFFF(2147483647)
- Limit underflow to: 0x80000000(-2147483648)
- Value after division by 0 with  the numerator being >= 0:    0x7FFFFFFF(2147483647)
- Value after division by 0 with  the numerator being < 0:     0x80000000(-2147483648)

Range:		80000000(H) ... 7FFFFFFF(H)
 		 -2147483648 ... 2147483647 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint32 s32_mul_s32_s32_div_s32(sint32 factor1, sint32 factor2, sint32 denominator)
{
	/* ## Operation body start [cbfc6d49-cb6c-42a4-870f-1f852a0fa6e1] */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
                                                                                     FUNCTION: s32_mul_s32_s32_div_s32                                                      

                                                                                     Parameter        type        Hex Range                   Physical Range          

                                                                                     Input:                                                                                  
                                                                                     factor1           sint32          80000000..7FFFFFFF         -2147483648..2147483647 
                                                                                     factor2           sint32          80000000..7FFFFFFF         -2147483648..2147483647 
                                                                                     denominator       sint32          80000000..7FFFFFFF         -2147483648..2147483647 

                                                                                     Output:                                                                                 
                                                                                     res               sint32          80000000..7FFFFFFF         -2147483648..2147483647 

                                                                                     Functionality:                                                                          
                                                                                     res = (factor1*factor2)/div with round off                                      
                                                                                     underflow : limit to 80000000 H (-2147483648)                                   
                                                                                     overflow  : limit to 7FFFFFFF H (2147483647)                                    
	 */

	/*~E*/
	uint64 product;
	sint64 deno_zero_product;
	uint32 abs_factor1,abs_factor2,abs_denominator;
	uint32 upper_32bit,lower_32bit,upper_32bit_quotient,lower_32bit_quotient,lower_32bit_rem;
	uint32 final_result,inter_result;
	sint32 sign_factor1,sign_factor2,sign_denominator;
	sint32 power_value,leading_zeros_count,prev_power_value;
	if (denominator<0)
	{
		sign_denominator=-1;
		abs_denominator=(uint32)(-denominator);
	}
	else
	{
		sign_denominator=1;
		abs_denominator=(uint32)denominator;
	}
	if (abs_denominator != 0U)
	{
		if (factor1<0)
		{
			sign_factor1=-1;
			abs_factor1=(uint32)(-factor1);
		}
		else
		{
			sign_factor1=1;
			abs_factor1=(uint32)factor1;
		}
		if (factor2<0)
		{
			sign_factor2=-1;
			abs_factor2=(uint32)(-factor2);
		}
		else
		{
			sign_factor2=1;
			abs_factor2=(uint32)factor2;
		}
		product= (uint64)((uint64)abs_factor1*(uint64)abs_factor2);
		/*Separation of product into upper and lower 32 bit words*/
		upper_32bit = (uint32)(product>>32);
		lower_32bit=(uint32)product;

		upper_32bit_quotient=(upper_32bit/abs_denominator ) + ((2U*(upper_32bit%abs_denominator))/abs_denominator);
		/*Checking for Overflow/ Under flow*/
		if (upper_32bit_quotient != 0U)
		{
			if ((sign_factor1*sign_factor2*sign_denominator)==-1)
			{
				/*Under Flow*/
				res_ret =  (sint32)S32_MIN;
			}
			else
			{
				/*Over flow*/
				res_ret =  (sint32)S32_MAX;
			}
		}
		else
		{
			power_value=32;
			final_result=0;

			leading_zeros_count=(sint32)u8_cntlz_u32_math(upper_32bit);
			power_value-=leading_zeros_count;
			/*Loop iteration to calculate Quotient part from upper 32 bit of the product*/
			while (power_value>=0)
			{
				/* Dividend for the next iteration is the remainder from the current iteration*/
				upper_32bit=upper_32bit<<leading_zeros_count;
				inter_result=upper_32bit/abs_denominator;
				inter_result=inter_result<<power_value;
				final_result+=inter_result;
				/* Remainder Calculation*/
				upper_32bit=upper_32bit%abs_denominator;
				leading_zeros_count=(sint32)u8_cntlz_u32_math(upper_32bit);
				power_value-=leading_zeros_count;

			}
			prev_power_value=power_value+leading_zeros_count;
			/*Making the final remainder from upper_32bit of the same magnitude of lower 32 bit*/
			upper_32bit=upper_32bit<<prev_power_value;
			/*Quotient and Remainder Calculation from Lower 32 bit of product*/
			lower_32bit_quotient=lower_32bit/abs_denominator;
			lower_32bit_rem=lower_32bit%abs_denominator;
			/*Addition of remainders from upper and lower 32 bit of product*/
			lower_32bit=upper_32bit+lower_32bit_rem;
			/*Rounded result calculation*/
			inter_result=(lower_32bit/abs_denominator)+((2U*(lower_32bit%abs_denominator))/abs_denominator);
			final_result= final_result+inter_result+lower_32bit_quotient;
			/*Appending Sign to the calculated result*/
			if ((sign_factor1*sign_factor2*sign_denominator)==-1)
			{
				/*Under flow checking*/
				if (final_result>(uint32)S32_MAX)
				{
					res_ret =  (sint32)S32_MIN;
				}
				else
				{
					res_ret =-((sint32)final_result);
				}
			}
			else
			{
				/*Over flow checking*/
				if (final_result>(uint32)S32_MAX)
				{
					res_ret =  (sint32)S32_MAX;
				}
				else
				{
					res_ret =(sint32)final_result;
				}
			}
		}
	}
	else
	{
		deno_zero_product = (sint64)factor1 * (sint64)factor2;

		if (deno_zero_product >= 0)
		{
			res_ret =    (sint32)S32_MAX;
		}
		else
		{
			res_ret =  (sint32)S32_MIN;
		}
	}

	return res_ret ;
	/* ## Operation body end [cbfc6d49-cb6c-42a4-870f-1f852a0fa6e1] */
}

/** This operation shall multiply an sint32 value by an sint32 value and divide the result by an uint32 value with overflow and underflow limitation to produce a result of type sint32

@param factor1 First factor

Range:		80000000(H).....7FFFFFFF(H)
		 -2147483648....2147483647
@param factor2 Second factor

Range:		80000000(H).....7FFFFFFF(H)
		 -2147483648....2147483647
@param denominator Denominator

Range:		00(H).....FFFFFFFF(H)
		    0....4294967295
@return (factor1 * factor2) / denominator, result rounded off
- Limit overflow to: 0x7FFFFFFF(2147483647)
- Limit underflow to: 0x80000000(-2147483648)
- Value after division by 0 with  the numerator being >= 0:    0x7FFFFFFF(2147483647)
- Value after division by 0 with  the numerator being < 0:     0x80000000(-2147483648)

Range:		80000000(H) ... 7FFFFFFF(H)
 		 -2147483648 ... 2147483647 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint32 s32_mul_s32_s32_div_u32(sint32 factor1, sint32 factor2, uint32 denominator)
{
	/* ## Operation body start [63dc75ce-6d42-4f35-b7f3-053e1548bf76] */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
                                                                                     FUNCTION: s32_mul_s32_s32_div_u32                                                     

                                                                                     Parameter        type        Hex Range                   Physical Range          

                                                                                     Input:                                                                                  
                                                                                     factor1           sint32          80000000..7FFFFFFF         -2147483648..2147483647 
                                                                                     factor2           sint32          80000000..7FFFFFFF         -2147483648..2147483647 
                                                                                     denominator       uint32                 0..FFFFFFFF                   0..4294967295 

                                                                                     Output:                                                                                 
                                                                                     res               sint32          80000000..7FFFFFFF         -2147483648..2147483647 

                                                                                     Functionality:                                                                          
                                                                                     res = (factor1*factor2)/div with round off                                      
                                                                                     underflow : limit to 80000000 H (-2147483648)                                   
                                                                                     overflow  : limit to 7FFFFFFF H (2147483647)                                    
	 */

	/*~E*/
	sint64 temp;

	temp = (sint64)factor1 * (sint64)factor2;
	/* Check if denominator is zero */
	if ( denominator != 0U )
	{
		/* Rounding The Result */
		temp = (temp / (sint64)denominator) + ((2 * (temp % (sint64)denominator))/((sint64)denominator));
		/* Compare  result with maximum limit */
		if (temp >= S32_MAX)
		{
			res_ret =  S32_MAX;
		}
		else
		{
			/* Compare  result with minimum limit */
			if (temp <= S32_MIN)
			{
				res_ret =  S32_MIN;
			}
			else
			{
				res_ret =  (sint32)temp;
			}
		}
	}
	else
	{
		if (temp >= 0)
		{
			res_ret =    S32_MAX;
		}
		else
		{
			res_ret =  S32_MIN;
		}
	}

	return res_ret ;
	/* ## Operation body end [63dc75ce-6d42-4f35-b7f3-053e1548bf76] */
}

/** This operation shall multiply an uint32 value by an sint32 value and divide the result by an sint32 value with overflow and underflow limitation to produce a result of type sint32

@param factor1 First factor

Range:		00(H).....FFFFFFFF(H)
		    0....4294967295
@param factor2 Second factor

Range:		80000000(H).....7FFFFFFF(H)
		 -2147483648....2147483647
@param denominator Denominator

Range:		80000000(H).....7FFFFFFF(H)
		 -2147483648....2147483647
@return (factor1 * factor2) / denominator, result rounded off
- Limit overflow to: 0x7FFFFFFF(2147483647)
- Limit underflow to: 0x80000000(-2147483648)
- Value after division by 0 with  the numerator being >= 0:    0x7FFFFFFF(2147483647)
- Value after division by 0 with  the numerator being < 0:     0x80000000(-2147483648)

Range:		80000000(H) ... 7FFFFFFF(H)
 		 -2147483648 ... 2147483647 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint32 s32_mul_u32_s32_div_s32(uint32 factor1, sint32 factor2, sint32 denominator)
{
	/* ## Operation body start [331984e3-e0a3-4b93-aa52-1036984e5161] */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
                                                                                     FUNCTION: s32_mul_u32_s32_div_s32                                                  

                                                                                     Parameter        type        Hex Range                   Physical Range          

                                                                                     Input:                                                                                  
                                                                                     factor1           uint32                 0..FFFFFFFF                   0..4294967295 
                                                                                     factor2           sint32          80000000..7FFFFFFF         -2147483648..2147483647 
                                                                                     denominator       sint32          80000000..7FFFFFFF         -2147483648..2147483647 

                                                                                     Output:                                                                                 
                                                                                     res               sint32          80000000..7FFFFFFF         -2147483648..2147483647 

                                                                                     Functionality:                                                                          
                                                                                     res = (factor1*factor2)/div with round off                                      
                                                                                     underflow : limit to 80000000 H (-2147483648)                                   
                                                                                     overflow  : limit to 7FFFFFFF H (2147483647)                                    
	 */

	/*~E*/
	uint64 product;
	sint64 deno_zero_product;
	uint32 abs_factor2,abs_denominator;
	uint32 upper_32bit,lower_32bit,upper_32bit_quotient,lower_32bit_quotient,lower_32bit_rem;
	uint32 final_result,inter_result;
	sint32 sign_factor2,sign_denominator;
	sint32 power_value,leading_zeros_count,prev_power_value;
	if (denominator<0)
	{
		sign_denominator=-1;
		abs_denominator=(uint32)(-denominator);
	}
	else
	{
		sign_denominator=1;
		abs_denominator=(uint32)denominator;
	}
	if (abs_denominator != 0U)
	{
		if (factor2<0)
		{
			sign_factor2=-1;
			abs_factor2=(uint32)(-factor2);
		}
		else
		{
			sign_factor2=1;
			abs_factor2=(uint32)factor2;
		}
		product= (uint64)((uint64)factor1*(uint64)abs_factor2);
		/*Separation of product into upper and lower 32 bit words*/
		upper_32bit = (uint32)(product>>32);
		lower_32bit=(uint32)product;

		upper_32bit_quotient= (upper_32bit/abs_denominator) + ((2U*(upper_32bit%abs_denominator))/abs_denominator);
		/*Checking for Overflow / Under flow*/
		if (upper_32bit_quotient != 0U)
		{
			if ((sign_factor2*sign_denominator)==-1)
			{
				/* Under flow*/
				res_ret =  (sint32)S32_MIN;
			}
			else
			{
				/*Over flow*/
				res_ret =  (sint32)S32_MAX;
			}
		}
		else
		{
			power_value=32;
			final_result=0;

			leading_zeros_count=(sint32)u8_cntlz_u32_math(upper_32bit);
			power_value-=leading_zeros_count;
			/*Loop iteration to calculate Quotient part from upper 32 bit of the product*/
			while (power_value>=0)
			{
				/* Dividend for the next iteration is the remainder from the current iteration */
				upper_32bit=upper_32bit<<leading_zeros_count;
				inter_result=upper_32bit/abs_denominator;
				inter_result=inter_result<<power_value;
				final_result+=inter_result;
				/* Remainder Calculation */
				upper_32bit=upper_32bit%abs_denominator;
				leading_zeros_count=(sint32)u8_cntlz_u32_math(upper_32bit);
				power_value-=leading_zeros_count;

			}
			prev_power_value=power_value+leading_zeros_count;
			/*Making the final remainder from upper_32bit of the same magnitude of lower 32 bit*/
			upper_32bit=upper_32bit<<prev_power_value;
			/*Quotient and Remainder Calculation from Lower 32 bit of product*/
			lower_32bit_quotient=lower_32bit/abs_denominator;
			lower_32bit_rem=lower_32bit%abs_denominator;
			/*Addition of remainders from upper and lower 32 bit of product*/
			lower_32bit=upper_32bit+lower_32bit_rem;
			/*Rounded result calculation*/
			inter_result=(lower_32bit/abs_denominator)+((2U*(lower_32bit%abs_denominator))/abs_denominator);
			final_result= final_result+inter_result+lower_32bit_quotient;
			/*Appending sign to the calculated result*/
			if ((sign_factor2*sign_denominator)==-1)
			{
				/*Over flow checking*/
				if (final_result>(uint32)S32_MAX)
				{
					res_ret = (sint32)S32_MIN;
				}
				else
				{
					res_ret =-((sint32)final_result);
				}
			}
			else
			{
				/*Under flow checking*/
				if (final_result>(uint32)S32_MAX)
				{
					res_ret =  (sint32)S32_MAX;
				}
				else
				{
					res_ret =(sint32)final_result;
				}
			}

		}
	}
	else
	{
		deno_zero_product = (sint64)factor1 * (sint64)factor2;

		if (deno_zero_product >= 0)
		{
			res_ret =    (sint32)S32_MAX;
		}
		else
		{
			res_ret =  (sint32)S32_MIN;
		}
	}

	return res_ret ;
	/* ## Operation body end [331984e3-e0a3-4b93-aa52-1036984e5161] */
}

/** This operation shall multiply an uint32 value by an sint32 value and divide the result by an uint32 value with overflow and underflow limitation to produce a result of type sint32

@param factor1 First factor

Range:		00(H).....FFFFFFFF(H)
		    0....4294967295
@param factor2 Second factor

Range:		80000000(H).....7FFFFFFF(H)
		 -2147483648....2147483647
@param denominator Denominator of type uint32

Range:		00(H).....FFFFFFFF(H)
		    0....4294967295
@return (factor1 * factor2) / denominator, result rounded off
- Limit overflow to: 0x7FFFFFFF(2147483647)
- Limit underflow to: 0x80000000(-2147483648)
- Value after division by 0 with  the numerator being >= 0:    0x7FFFFFFF(2147483647)
- Value after division by 0 with  the numerator being < 0:     0x80000000(-2147483648)

Range:		80000000(H) ... 7FFFFFFF(H)
 		 -2147483648 ... 2147483647 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint32 s32_mul_u32_s32_div_u32(uint32 factor1, sint32 factor2, uint32 denominator)
{
	/* ## Operation body start [9a084c8d-c2c3-4854-b691-d6d2cfab51ac] */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
                                                                                     FUNCTION: s32_mul_u32_s32_div_u32                                                  

                                                                                     Parameter        type        Hex Range                   Physical Range          

                                                                                     Input:                                                                                  
                                                                                     factor1           uint32                 0..FFFFFFFF                   0..4294967295 
                                                                                     factor2           sint32          80000000..7FFFFFFF         -2147483648..2147483647 
                                                                                     denominator       uint32                 0..FFFFFFFF                   0..4294967295 

                                                                                     Output:                                                                                 
                                                                                     res               sint32          80000000..7FFFFFFF         -2147483648..2147483647 

                                                                                     Functionality:                                                                          
                                                                                     res = (factor1*factor2)/div with round off                                      
                                                                                     underflow : limit to 80000000 H (-2147483648)                                   
                                                                                     overflow  : limit to 7FFFFFFF H (2147483647)                                    
	 */

	/*~E*/
	sint64 temp;

	temp = (sint64)factor1 * (sint64)factor2;
	/* Check if denominator is zero */
	if (denominator > 0U)
	{
		/* Rounding The Result */
		temp = (temp / (sint64)denominator) + ((2 * (temp % (sint64)denominator))/((sint64)denominator));
		/* Compare  result with maximum limit */
		if (temp >= S32_MAX)
		{
			res_ret =  S32_MAX;
		}
		else
		{
			/* Compare  result with minimum limit */
			if (temp <= S32_MIN)
			{
				res_ret =  S32_MIN;
			}
			else
			{
				res_ret =  (sint32)temp;
			}
		}
	}
	else
	{
		if (temp >= 0)
		{
			res_ret =    S32_MAX;
		}
		else
		{
			res_ret =  S32_MIN;
		}
	}

	return res_ret ;
	/* ## Operation body end [9a084c8d-c2c3-4854-b691-d6d2cfab51ac] */
}

/** This operation shall perform division of sint32 value by an uint16 value to produce a result of sint32 with underflow and overflow limitation
 @param numerator  Numerator

 Range:     80000000(H).....7FFFFFFF(H)
         -2147483648....2147483647

@param denominator  Denominator

 Range:     00(H).....FFFF(H)
            0....65535

@param numerator Numerator

Range:      80000000(H).....7FFFFFFF(H)
         -2147483648....2147483647
@param denominator Denominator

Range:      0....FFFF(H)
         0.....65535
@return numerator / denominator, result rounded off
- Limit overflow to: 0x7FFFFFFF(2147483647)
- Value after division by 0 with  the numerator being >= 0:    0x7FFFFFFF(2147483647)
- Value after division by 0 with  the numerator being < 0:     0x80000000(-2147483648)

Range:      80000000(H) ... 7FFFFFFF(H)
         -2147483648 ... 2147483647 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint32 s32_div_s32_u16(sint32 numerator, uint16 denominator)
{
	/* ## Operation body start [f1feb5f6-4135-4abf-89a8-ad8037d30216] */
	/* Check if denominator is zero */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
                                                                        FUNCTION: s16_div_s32_s16                                                       

                                                                        Parameter       type      Hex Range            Physical Range           

                                                                        Input:                                                                        
                                                                        x_value        sint32       80000000..7FFFFFFF  -2147483648..2147483647   
                                                                        y_value        sint16       8000..7FFF          -32768..32767             

                                                                        Output:                                                                       
                                                                        res            sint16       8000..7FFF          -32768..32767             

                                                                        Functionality:                                                                
                                                                        res = (x_value)/y_value  with round off                               
                                                                        overflow : limit to 7FFFH                                             
                                                                        underflow: limit to 8000H                                             
	 */

	/*~E*/
	uint32 res, rem;
	uint16 tmp_denominator;
	sint32 res1;
	/* Check if denominator is non-zero */
	if ( denominator != (uint8)0)
	{
		/* Check if signed input is positive */
		if ( numerator > 0 )
		{
			/*  Calculate result with round-off */
			res1 = ( ( (sint32)numerator / (sint32)denominator) + ((2 * ((sint32)numerator % (sint32)denominator) ) / (sint32)denominator));

			res_ret =  res1;
		}
		else
		{
			/* Calculate result with round-off */
			res = ((uint32)(-numerator))/ denominator;
			rem =((uint32)(-numerator)) % denominator;

			/* Check if denominator is odd */
			if ( (denominator % 2U)!= 0U)
			{
				tmp_denominator = (denominator /(uint8)2) + (uint8)1;
			}
			else
			{
				tmp_denominator = denominator / (uint8)2;
			}
			if ( rem >= tmp_denominator )
			{
				res++;
			}
			res_ret =  -((sint32)res);
		}
	}
	else
	{
		/* Check if numerator is positive or negative */
		if ( numerator >= 0 )
		{
			res_ret =  S32_MAX;
		}
		else
		{
			res_ret =  S32_MIN;
		}

	}
	return res_ret ;
	/* ## Operation body end [f1feb5f6-4135-4abf-89a8-ad8037d30216] */
}

/** This operation shall perform division of S32 value by an sint32 value to produce a result of sint16 with underflow and overflow limitation
@param numerator  Numerator

 Range:     80000000(H).....7FFFFFFF(H)
         -2147483648....2147483647

@param denominator  Denominator

 Range:     80000000(H).....7FFFFFFF(H)
         -2147483648....2147483647

@param numerator Numerator

Range:      80000000(H).....7FFFFFFF(H)
         -2147483648....2147483647
@param denominator Denominator

Range:      00(H).....FFFFFFFF(H)
            0....4294967295
@return numerator / denominator, result rounded off
- Limit overflow to: 0x7FFF(32767)
- Limit underflow to: 0x8000(-32768)
- Value after division by 0 with  the numerator being >= 0:    0x7FFF(32767)
- Value after division by 0 with  the numerator being < 0:     0x8000(-32768)

Range:      8000(H) ... 7FFF(H)
         -32768 ... 32767 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint16 s16_div_s32_s32(sint32 numerator, sint32 denominator)
{
	/* ## Operation body start [884809ff-ad5b-41ba-8163-bdc4c54528d7] */
	/* Check if denominator is zero */
	/*~A*/
	/*~+:Description*/
	/*
                                                                        FUNCTION: s16_div_s32_s16                                                       

                                                                        Parameter       type      Hex Range            Physical Range           

                                                                        Input:                                                                        
                                                                        x_value        sint32       80000000..7FFFFFFF  -2147483648..2147483647   
                                                                        y_value        sint16       8000..7FFF          -32768..32767             

                                                                        Output:                                                                       
                                                                        res            sint16       8000..7FFF          -32768..32767             

                                                                        Functionality:                                                                
                                                                        res = (x_value)/y_value  with round off                               
                                                                        overflow : limit to 7FFFH                                             
                                                                        underflow: limit to 8000H                                             
	 */

	/*~E*/
	/* Check if denominator is zero */
	return s16_s32(s32_div_s32_s32(numerator,denominator));
	/* ## Operation body end [884809ff-ad5b-41ba-8163-bdc4c54528d7] */
}

/** This operation shall perform division of sint32 value by an uint16 value to produce a result of sint16 with underflow and overflow limitation
@param numerator  Numerator

 Range:     80000000(H).....7FFFFFFF(H)
         -2147483648....2147483647

@param denominator  Denominator

 Range:     00(H).....FFFF(H)
            0....65535

@param numerator Numerator

Range:      80000000(H).....7FFFFFFF(H)
         -2147483648....2147483647
@param denominator Denominator

Range:      00(H).....FFFF(H)
            0....65535
@return numerator / denominator, result rounded off
- Limit overflow to: 0x7FFF(32767)
- Limit underflow to: 0x8000(-32768)
- Value after division by 0 with  the numerator being >= 0:    0x7FFF(32767)
- Value after division by 0 with  the numerator being < 0:     0x8000(-32768)

Range:      8000(H) ... 7FFF(H)
         -32768 ... 32767 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint16 s16_div_s32_u16(sint32 numerator, uint16 denominator)
{
	/* ## Operation body start [dc428269-d91c-4b07-a428-497f4ec59e5b] */
	/* Check if denominator is zero */
	/*~A*/
	/*~+:Description*/
	/*
                                                                        FUNCTION: s16_div_s32_s16                                                       

                                                                        Parameter       type      Hex Range            Physical Range           

                                                                        Input:                                                                        
                                                                        x_value        sint32       80000000..7FFFFFFF  -2147483648..2147483647   
                                                                        y_value        sint16       8000..7FFF          -32768..32767             

                                                                        Output:                                                                       
                                                                        res            sint16       8000..7FFF          -32768..32767             

                                                                        Functionality:                                                                
                                                                        res = (x_value)/y_value  with round off                               
                                                                        overflow : limit to 7FFFH                                             
                                                                        underflow: limit to 8000H                                             
	 */

	/*~E*/
	/* Check if denominator is zero */
	return s16_s32(s32_div_s32_u16(numerator,denominator));
	/* ## Operation body end [dc428269-d91c-4b07-a428-497f4ec59e5b] */
}

/** This operation shall perform division of uint32 value by an uint32 value to produce a result of uint16 with underflow and overflow limitation
@param numerator  Numerator

 Range:     00(H).....FFFFFFFF(H)
            0....4294967295

@param denominator  Denominator

 Range:     00(H).....FFFFFFFF(H)
            0....4294967295

@param numerator Numerator

Range:      00(H).....FFFFFFFF(H)
             0....4294967295
@param denominator Denominator

Range:      00(H).....FFFFFFFF(H)
             0....4294967295
@return x_value / y_value, result rounded off
- Limit overflow to:    0xFFFF (65535)
- Value after division by 0:    0xFFFF(65535)

Range:      00(H)....FFFF(H)
            0....65535 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

uint16 u16_div_u32_u32(uint32 numerator, uint32 denominator)
{
	/* ## Operation body start [ddfffe80-e308-4dac-afe8-50fedc90982d] */
	/* Check if denominator is non-zero */
	/*~A*/
	/*~+:Description*/
	/*
                                                                       FUNCTION: u16_div_u32_u32                                                   

                                                                       Parameter        type     Hex Range           Physical Range           

                                                                       Input:                                                                        
                                                                       numerator      uint32      0..FFFFFFFF         0..4294967295            
                                                                       denominator    uint32      0..FFFFFFFF         0..4294967295            

                                                                       Output:                                                                       
                                                                       res            uint16      0..FFFF         0..65535            

                                                                       Functionality:                                                                
                                                                       res = (numerator)/denominator with round off                          
	 */

	/*~E*/
	/* Check if denominator is non-zero */
	return u16_u32(u32_div_u32_u32(numerator, denominator));
	/* ## Operation body end [ddfffe80-e308-4dac-afe8-50fedc90982d] */
}

/** This operation shall multiply sint32 value by an sint16 value and divide the result by sint16 value with overflow and underflow limitation to produce a result of type sint16

@param factor1 First factor

Range:      80000000(H).....7FFFFFFF(H)
         -2147483648....2147483647
@param factor2 Second factor

Range:      8000(H).....7FFF(H)
          -32768....32767

@param denominator  Denominator

 Range:		8000(H).....7FFF(H)
 		  -32768....32767

@param factor1 First factor

Range:		80000000(H).....7FFFFFFF(H)
 		 -2147483648....2147483647
@param factor2 Second factor

Range:		8000(H).....7FFF(H)
		  -32768....32767
@param denominator Denominator

Range:      8000(H).....7FFF(H)
          -32768....32767
@return (factor1 * factor2) / denominator, result rounded off
- Limit overflow to:    0x7FFF (32767)
- Limit underflow to:   0x8000 ( -32768)
- Value after division by 0 with  the numerator being >= 0:    0x7FFF(32767)
- Value after division by 0 with  the numerator being < 0:     0x8000(-32768)

Range:      8000(H).....7FFF(H)
          -32768....32767 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint16 s16_mul_s32_s16_div_s16(sint32 factor1, sint16 factor2, sint16 denominator)
{
	/* ## Operation body start [a3ed8942-6a6c-4f7e-b4a3-261996bb8e9a] */
	sint16 res_ret;
	/*~A*/
	/*~+:Description*/


	/*~E*/
	/*FUNCTION_ID:16*/
	sint64 temp;
	temp = ((sint64)factor1 * (sint64)factor2);
	if (denominator != 0)
	{
		/* Rounding The Result */
		temp = ((temp / denominator) + ((2 * (temp % denominator))/(denominator)));
		if (temp >=S16_MAX)
		{
			res_ret =  S16_MAX;
		}
		else
		{
			if (temp <=S16_MIN)
			{
				res_ret =  S16_MIN;
			}
			else
			{
				res_ret =  (sint16)temp;
			}
		}
	}
	else
	{
		if (temp >= 0)
		{
			res_ret =  S16_MAX;
		}
		else
		{
			res_ret =  S16_MIN;
		}
	}
	return res_ret ;
	/* ## Operation body end [a3ed8942-6a6c-4f7e-b4a3-261996bb8e9a] */
}

/** This operation shall perform addition of three sint32 variables with underflow and overflow limitation and return result of type sint32

@param x_value First parameter

Range:      80000000(H).....7FFFFFFF(H)
        -2147483648......2147483647
@param y_value Second parameter

Range:      80000000(H).....7FFFFFFF(H)
        -2147483648......2147483647
@param z_value Third parameter

Range:      80000000(H).....7FFFFFFF(H)
        -2147483648......2147483647
@return (x_value + y_value + z_value).
Limit overflow to 0x7FFFFFFF (2147483647)
Limit underflow to 0x80000000 (-2147483648)

Range:      80000000(H).....7FFFFFFF(H)
        -2147483648......2147483647 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

sint32 s32_add_s32_s32_s32(sint32 x_value, sint32 y_value, sint32 z_value)
{
	/* ## Operation body start [c739c9bc-931c-4468-8ce1-a1a35b95b71b] */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s32_add_s32_s32_s32                                                    

         Parameter      type       Hex Range            Physical Range       

Input:                                                                       
         x_value        sint32   80000000..7FFFFFFF   -2147483648..2147483647   
         y_value        sint32   80000000..7FFFFFFF   -2147483648..2147483647   
         z_value        sint32   80000000..7FFFFFFF   -2147483648..2147483647   
Output:                                                                      
         res            sint32   80000000..7FFFFFFF   -2147483648..2147483647   

Functionality:                                                               
        res = x_value + y_value + z_value                                    
        overflow : limit to 7FFFFFFFH                                        
        underflow: limit to 80000000H                                        
	 */

	/*~E*/
	/*FUNCTION_ID:18*/
	sint64 temp;
	temp = (sint64)x_value + y_value + z_value;
	if (temp >= S32_MAX)
	{
		res_ret =  S32_MAX;
	}
	else
	{
		if (temp <= S32_MIN)
		{
			res_ret =  S32_MIN;
		}
		else
		{
			res_ret =  (sint32)temp;
		}
	}
	return res_ret ;
	/* ## Operation body end [c739c9bc-931c-4468-8ce1-a1a35b95b71b] */
}


/*~E*/

