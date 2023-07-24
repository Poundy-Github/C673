/*~A*/
/*~+:VM Header*/
/* UML source model state: Draft */
/* ## Module Header Start [c768d364-f3d9-4b56-88c0-e0ea8d55b73d] */
/****************************************************************************

COPYRIGHT (C) $Date: 2019/11/29 08:45:56CET $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.                                                 

The reproduction, transmission or use of this document or its contents is  
not permitted without express written authority.                           
Offenders will be liable for damages. All rights, including rights created 
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------

$Log: f32_math.h  $
Revision 1.4 2019/11/29 08:45:56CET Nastasa, Elena (uidt4846) 
Update LCF code for new auxCodeGen 4.1
Revision 1.3 2019/07/03 13:45:21CEST Nastasa, Elena (uidt4846) 
Update SDA Library files
Revision 1.1 2018/07/24 16:50:23CEST Ammermueller Martin (uidv5342) (uidv5342) 
Initial revision
Member added to project /ES/1T/0C/SDA/SDA_Source/SDA_Toolboxes/ACG/Libraries/ecmath_f32/Src/5_2_0/project.pj
Revision 1.12 2018/04/11 08:14:27CEST Ugran Parimala (uid41586) (uid41586) 
added s64_f32,u64_f32
Revision 1.11 2018/03/06 08:22:13CET Angadi Hampa (uidu8151) (uidu8151) 
RO : 8197596 : MISRA2012 ANSI VERSIONS
Revision 1.10 2017/02/20 11:14:51CET Angadi Hampa (uidu8151) (uidu8151) 
Inline removal from f32_main.h file. RO : 5728850 : FS_0G01_ANSI_F32MATH_5.1.0 : pow() function correction
Revision 1.9 2017/02/03 07:14:06CET Angadi Hampa (uidu8151) (uidu8151) 
RO : 5728850 : FS_0G01_ANSI_F32MATH_5.1.0 : pow() function correction
Revision 1.8 2016/12/20 06:29:04CET Angadi Hampa (uidu8151) (uidu8151) 
After review correction
Revision 1.7 2016/11/28 04:51:19CET Angadi Hampa (uidu8151) (uidu8151) 
RO : 5358975 ; FS_0G01_ANSI_F32_MATH_5.0.0 ; New Functions added
Revision 1.6 2016/08/09 07:31:10CEST Adinarayanagowda Pruthviraj (uidp1961) (uidp1961) 
RO:4680707 : FS_0G01_ANSI_F32MATH_4.0.0, New requirements updated
Revision 1.4 2015/12/10 11:43:28CET Adinarayanagowda Pruthviraj (uidp1961) (uidp1961) 
reveiw updates
Revision 1.2 2015/12/03 09:56:59CET Adinarayanagowda Pruthviraj (uidp1961) (uidp1961) 
RO : 3550645 ; F32_math - ANSI version
Revision 1.1 2015/12/01 04:55:58CET Ganesh Sumangala (uidu8725) (uidu8725) 
Initial revision
Member added to project /ES/FS/0A/bsw/stdlib-ansi/f32_math/pd_ansi/i/project.pj
Revision 1.6 2015/11/19 04:57:19CET Angadi Hampa (uidu8151) (uidu8151) 
RO: 2877034 : F32_MATH:Merge EMS2 to EMS3 f32_math versions; initial checkin
Revision 1.5 2015/07/20 12:52:23CEST Angadi Hampa (uidu8151) (uidu8151) 
RO:2877034: FS_0G01_TC2XX_F32MATH_2.2.0; iNITIAL Archive
Revision 1.4 2015/04/09 08:24:27CEST uidu8151 
RO: 2593535 : FS_0G01_TC2XX_F32MATH_210
Revision 1.3 2013/08/19 10:36:37CEST Angadi Hampa (uidu8151) (uidu8151) 
for release RO:429659 FS_0G01_TC2XX_F32MATH_100
Revision 1.2 2013/08/19 11:28:27IST Angadi Hampa (uidu8151) (uidu8151) 
Member renamed from f32_math.h_code to f32_math_main.h in project /ES/FS/0A/bsw/stdlib/f32_math/pd_tc2xx/i/project.pj.
Revision 1.1 2013/08/06 10:46:13CEST Angadi Hampa (uidu8151) (uidu8151) 
Initial revision
Member added to project /ES/FS/0D/bsw/stdlib/tc2xx/f32_math/src_pd/i/project.pj
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
/* ## Module Header End [b0364878-da86-4c8d-b23d-db97066ca76f] */

/*~E*/
#ifndef F32_MATH_H
#define F32_MATH_H

#include "Platform_Types.h"
#include "gtypes.h" //ElNa
#include "powersar_addon_types.h"  //ElNa
#include "Std_types.h" //ElNa
// #include "gmem.h" //ElNa, Add gmem to use the correct sintax for inline

// #define static    //ElNa, Remove word static to be able to use the correct sintax for inline
/*~A*/
/*~+:Inline Operations*/
/*~T*/
/*Inline function Declarations*/
 uint8 u8_f32(float32 value);
 uint16 u16_f32(float32 value);
 uint32 u32_f32(float32 value);
 sint8 s8_f32(float32 value);
 sint16 s16_f32(float32 value);
 sint32 s32_f32(float32 value);
 sint64 s64_f32(float32 value);
 uint64 u64_f32(float32 value);
 sint8 s8_sgn_f32(float32 value);
 float32 f32_mmv_f32_f32_f32(float32 mmv, float32 value, float32 mmv_coefficient);
 float32 f32_min_max_f32_f32_f32(float32 value, float32 minimum, float32 maximum);
 float32 f32_max_f32_f32(float32 x_val, float32 y_val);
 float32 f32_min_f32_f32(float32 x_val, float32 y_val);
 float32 f32_hip1_f32_f32_f32_f32(float32 y_old, float32 u, float32 u_old, float32 m);
 float32 f32_floor_f32(float32 value);
 float32 f32_ceil_f32(float32 value);
 float32 f32_abs_f32(float32 value);

/*~T*/
/** This operation converts a single precision float value to unsigned character data type with overflow and underflow limitation.

Result: uint8 equivalent of float32 value.

@param value Input value as float32.
@return Value converted and limited to Uint8. */
//#include "iopt_memmap.h"
//
// uint8 u8_f32(float32 value)
//{
//	/* ## Operation body start [cc65bc57-8e97-49d1-83e7-4a4ad287aa0b] */
//	uint8 res;
//	if (value >= 255.0f)
//	{
//		res = U8_MAX;
//	}
//	else
//	{
//		if (value <= 0.0f)
//		{
//			res = U8_MIN;
//		}
//		else
//		{
//			res = (uint8)value;
//		}
//	}
//	return res;
//	/* ## Operation body end [cc65bc57-8e97-49d1-83e7-4a4ad287aa0b] */
//}
//
///** This operation converts a single precision float value to unsigned integer data type with overflow and underflow limitation.
//
//Result: uint16 equivalent of float32 value.
//
//@param value Input value as float32.
//@return Value converted and limited to Uint16. */
//#include "iopt_memmap.h"
//
// uint16 u16_f32(float32 value)
//{
//	/* ## Operation body start [1d78f73f-22b6-4f78-836f-78c67f43603c] */
//	/*~T*/
//	uint16 res;
//	if (value >= 65535.0f)
//	{
//		res = U16_MAX;
//	}
//	else
//	{
//		if (value <= 0.0f)
//		{
//			res = U16_MIN;
//		}
//		else
//		{
//			res = (uint16)value;
//		}
//	}
//	return res;
//	/* ## Operation body end [1d78f73f-22b6-4f78-836f-78c67f43603c] */
//}
//
///** This operation converts a single precision float value to unsigned long integer data type with overflow and underflow limitation.
//
//Result: uint32 equivalent of float32 value.
//
//@param value Input value as float32.
//@return Value converted and limited to uint32. */
//#include "iopt_memmap.h"
//
// uint32 u32_f32(float32 value)
//{
//	/* ## Operation body start [c1d8b9dc-9eec-44e7-8d8c-ca61f7d4ba57] */
//	/*~T*/
//	uint32 res;
//	if (value >= 4294967295.0f)
//	{
//		res = U32_MAX;
//	}
//	else
//	{
//		if (value <= 0.0f)
//		{
//			res = U32_MIN;
//		}
//		else
//		{
//			res = (uint32)value;
//		}
//	}
//	return res;
//	/* ## Operation body end [c1d8b9dc-9eec-44e7-8d8c-ca61f7d4ba57] */
//}
//
///** This operation converts a single precision float value to signed character data type with overflow and underflow limitation.
//
//Result: sint8 equivalent of float32 value.
//
//@param value Input value as float32.
//@return Value converted and limited to Sint8. */
//#include "iopt_memmap.h"
//
// sint8 s8_f32(float32 value)
//{
//	/* ## Operation body start [f246815b-f531-4b33-b1d3-640be76f3f72] */
//	/*~T*/
//	sint8 res;
//	if (value >= 127.0f)
//	{
//		res = S8_MAX;
//	}
//	else
//	{
//		if (value <= -128.0f)
//		{
//			res = S8_MIN;
//		}
//		else
//		{
//			res = (sint8)value;
//		}
//	}
//	return res;
//	/* ## Operation body end [f246815b-f531-4b33-b1d3-640be76f3f72] */
//}
//
///** This operation converts a single precision float value to signed integer data type with overflow and underflow limitation.
//
//Result: sint16 equivalent of float32 value.
//
//@param value Input value as float32.
//@return Value converted and limited to Sint16. */
//#include "iopt_memmap.h"
//
// sint16 s16_f32(float32 value)
//{
//	/* ## Operation body start [3cd66498-7ad2-457d-8caa-79f0d61da0b5] */
//	/*~T*/
//	sint16 res;
//	if (value >= 32767.0f)
//	{
//		res = S16_MAX;
//	}
//	else
//	{
//		if (value <= -32768.0f)
//		{
//			res = S16_MIN;
//		}
//		else
//		{
//			res = (sint16)value;
//		}
//	}
//	return res;
//	/* ## Operation body end [3cd66498-7ad2-457d-8caa-79f0d61da0b5] */
//}
//
///** This operation converts a single precision float value to signed long integer data type with overflow and underflow limitation.
//
//Result: sint32 equivalent of float32 value.
//
//@param value Input value as float32.
//@return Value converted and limited to Sint32. */
//#include "iopt_memmap.h"
//
// sint32 s32_f32(float32 value)
//{
//	/* ## Operation body start [182938d4-f6f6-4f58-9758-c42cae31e95e] */
//	/*~T*/
//	sint32 res;
//	if (value >= 2147483647.0f)
//	{
//		res = S32_MAX;
//	}
//	else
//	{
//		if (value <= -2147483648.0f)
//		{
//			res = S32_MIN;
//		}
//		else
//		{
//			res = (sint32)value;
//		}
//	}
//	return res;
//	/* ## Operation body end [182938d4-f6f6-4f58-9758-c42cae31e95e] */
//}
//
///** This operation converts a single precision float value to signed long integer data type with overflow and underflow limitation.
//If the argument "value" >= 9223372036854775807.0, return value shall be S64_MAX.
//If the argument "value" <= -9223372036854775808.0, return value shall be S64_MIN.
//If the input argument "value" is in the range -9223372036854775807.0 < value < 9223372036854775808.0 return value is floor(value) for value >= 0.0, and -floor(-value) for value < 0.0.
//Result: sint64 equivalent of float32 value.
//
//@param value Input value as float32.
//@return Value converted and limited to Sint64. */
//#include "iopt_memmap.h"
//
// sint64 s64_f32(float32 value)
//{
//	/* ## Operation body start [bf9e0131-f2d9-4422-b242-e6204dea73ec] */
//	/*~T*/
//	const float32 F32_2POW32 = 4294967296.0f;
//	sint64 res=(sint64)0;
//
//	uint32 HIGH32_value;
//	float32 f32_tmp,tmp2;
//	uint8 sign=0;
//
//	/*~T*/
//	f32_tmp = value;
//	if (f32_tmp <= (float32)S64_MIN)
//	{
//		res = S64_MIN;
//	}
//	else
//	{
//		if (f32_tmp >= (float32)S64_MAX)
//		{
//			res =S64_MAX;
//		}
//		else
//		{
//			if (f32_tmp < 0.0f )
//			{
//				f32_tmp = -f32_tmp;
//				sign = 1;
//			}
//			/*~T*/
//
//			/*~T*/
//			tmp2  = (f32_tmp/F32_2POW32);  /*upper 32 bit*/
//			HIGH32_value  = (uint32)tmp2;
//			f32_tmp = f32_tmp - ((float32)HIGH32_value*F32_2POW32); /*lint !e9034 DAT.11, MISRA 10.3: false positive, bug in PC-Lint*/ /*Subtract already converted part*/
//			res = (sint64)(((uint64)HIGH32_value<<32) | (uint32)f32_tmp); /*combine upper and lower 32 bits*/
//
//			if (sign !=0U)
//			{
//						                res = ((sint64)0-res);
//			}
//			else
//			{
//						            /*Else not required*/
//			}
//			/*~T*/
//
//		}
//	}
//	/*~T*/
//	return res;
//	/*~T*/
//	/* ## Operation body end [bf9e0131-f2d9-4422-b242-e6204dea73ec] */
//}
//
///** This operation converts a single precision float value to unsigned long integer data type with overflow and underflow limitation.
//If the argument "value" >= 18446744073709551615.0
//, return value shall be U64_MAX.
//If the argument "value" <= 0.0, return value shall be U64_MIN.
//If the input argument "value" is in the range 18446744073709551615.0
// < value < 0.0 return value is floor(value) for value >= 0.0, and -floor(-value) for value < 0.0.
//
//Result: uint64 equivalent of float32 value.
//
//@param value Input value as float32.
//@return Value converted and limited to Uint64. */
//#include "iopt_memmap.h"
//
// uint64 u64_f32(float32 value)
//{
//	/* ## Operation body start [bf9e0131-f2d9-4422-b242-e6204dea73ec] */
//	/*~T*/
//	const float32 F32_2POW32 = 4294967296.0f;
//	uint64 res;
//	uint32 HIGH32_value;
//	float32 f32_tmp,tmp2;
//	/*~T*/
//	f32_tmp = value;
//	if (f32_tmp <= (float32)U64_MIN)
//	{
//		res = U64_MIN;
//	}
//	else
//	{
//		if (f32_tmp >= (float32)U64_MAX)
//		{
//			res = U64_MAX;
//		}
//		else
//		{
//			tmp2  = (f32_tmp/F32_2POW32);  /*upper 32 bit*/
//			HIGH32_value  = (uint32)tmp2;
//			f32_tmp = f32_tmp - (((float32)HIGH32_value)*F32_2POW32); /*Subtract already converted part*/
//			res = ((uint64)HIGH32_value<<32) | (uint32)f32_tmp; /*combine upper and lower 32 bits*/
//		}
//	}
//	/*~T*/
//	return res;
//	/*~T*/
//	/* ## Operation body end [bf9e0131-f2d9-4422-b242-e6204dea73ec] */
//}
//
///** This operation calculates the signum of the given argument of type float32 and returns a result of type S8.
//
//Result: result is -1 if value < 0,
//	             0 if value = 0,
//	             1 if value > 0.
//
//@param value Input value as float32.
//@return Signum of F32 input value as Sint8. */
//#include "iopt_memmap.h"
//
// sint8 s8_sgn_f32(float32 value)
//{
//	/* ## Operation body start [7b4acc2b-e2f0-400f-8b26-361559887e50] */
//	sint8 tmp_ret ;
//	if (value < 0.0f)
//	{
//		tmp_ret = (sint8)-1;
//	}
//	else
//	{
//		if (value == 0.0f)
//		{
//			tmp_ret = 0;
//		}
//		else
//		{
//			tmp_ret = 1;
//		}
//	}
//	return tmp_ret;
//	/* ## Operation body end [7b4acc2b-e2f0-400f-8b26-361559887e50] */
//}
//
///** This operation calculates a new floating average using old floating average, actual measured value and mmv coefficient. All the input and return parameters are of type float32.
//
//Result: result = mmv + ((value - mmv) * mmv_coefficient).
//
//@param mmv Old floating average value as float32.
//@param value Actual measured value as float32.
//@param mmv_coefficient Coefficient for calculation of new mmv as float32.
//@return New floating average value as float32. */
//#include "iopt_memmap.h"
//
// float32 f32_mmv_f32_f32_f32(float32 mmv, float32 value, float32 mmv_coefficient)
//{
//	/* ## Operation body start [31c33355-d86c-448b-a050-cce4a7a310de] */
//	return (mmv + ((value - mmv) * mmv_coefficient));
//	/* ## Operation body end [31c33355-d86c-448b-a050-cce4a7a310de] */
//}
//
///** This operation limits the value between minimum and maximum arguments. All the input and return parameters are of type float32.
//
//Result: value is limited to minimum, if value <= minimum,
//	value is limited to maximum, if value >= maximum.
//
//@param value Input value as float32.
//@param minimum Minimum value as float32.
//@param maximum Maximum value as float32.
//@return Limited float32 value. */
//#include "iopt_memmap.h"
//
// float32 f32_min_max_f32_f32_f32(float32 value, float32 minimum, float32 maximum)
//{
//	/* ## Operation body start [0e17af50-b46d-4820-be19-ac6f13c5b6b4] */
//	/*~T*/
//	float32 res;
//	if (value >= maximum)
//	{
//		res = maximum;
//	}
//	else
//	{
//		if (value <= minimum)
//		{
//			res = minimum;
//		}
//		else
//		{
//			res = value;
//		}
//	}
//	return res;
//	/* ## Operation body end [0e17af50-b46d-4820-be19-ac6f13c5b6b4] */
//}
//
///** This operation returns the maximum of the two input arguments. All the input and return parameters are of type float32.
//
//Result: if (x_val > y_val)
// 	    result = x_val
// 	else
//	    result = y_val
//
//@param x_val First argument as float32.
//@param y_val Second argument as float32.
//@return Maximum of two input values as float32. */
//#include "iopt_memmap.h"
//
// float32 f32_max_f32_f32(float32 x_val, float32 y_val)
//{
//	/* ## Operation body start [f3b95cb6-4382-4fa8-9a8b-d249f4422cb3] */
//	return ( (x_val > y_val) ? x_val : y_val );
//	/* ## Operation body end [f3b95cb6-4382-4fa8-9a8b-d249f4422cb3] */
//}
//
///** This operation returns the minimum of the two input arguments. All the input and return parameters are of type float32.
//
//Result: if (x_val < y_val)
//	    result = x_val
//	else
//	    result = y_val
//
//@param x_val First argument as float32.
//@param y_val Second argument as float32.
//@return Minimum of two input values as float32. */
//#include "iopt_memmap.h"
//
// float32 f32_min_f32_f32(float32 x_val, float32 y_val)
//{
//	/* ## Operation body start [cedffda9-40b0-465e-a071-c26b6b457e4a] */
//	return ( (x_val < y_val) ? x_val : y_val );
//	/* ## Operation body end [cedffda9-40b0-465e-a071-c26b6b457e4a] */
//}
//
///** This operation returns the result of a first order high-pass filter with the input parameters as previous output (y_old), present input (u), previous input (u_old) and a constant multiplying factor (m).
//All the input and return parameters are of type float32.
//
//Result: result = [(1 - m) * y_old] + (u -u_old)
//
//@param y_old Previous output as float32.
//@param u Present input as float32.
//@param u_old Previous input as float32.
//@param m Constant multiplying factor as float32.
//@return Result value of high-pass filter as float32. */
//#include "iopt_memmap.h"
//
// float32 f32_hip1_f32_f32_f32_f32(float32 y_old, float32 u, float32 u_old, float32 m)
//{
//	/* ## Operation body start [385857ed-11fa-42df-82c3-9a52900e03c3] */
//	return (((1.0f - m) * y_old) + (u - u_old));
//	/* ## Operation body end [385857ed-11fa-42df-82c3-9a52900e03c3] */
//}
//
///** This operation shall return the natural number value determined by rounding the argument towards negative infinity with underflow overflow saturation. Also the input values shall be limited in case of overflow or underflow before the return value is calculated.
//
//If 0.0< value <= FLT_MIN, then the return value shall be 0.0
//If 0.0 > value >= -FLT_MIN, then the return value shall be -1.0
//
//The operation shall be synchronous and reentrant.
//
//@param value Input value as float32.
//@return float32 rounded value */
//#include "iopt_memmap.h"
//
// float32 f32_floor_f32(float32 value)
//{
//	/** This operation calculates absolute value for the argument of type float32 and returns a result of type float32.
//
//Result: result = |value|.
//	Range of the result :  0.. MAX_FLOAT.
//
//@param value Input value as float32.
//@return Absolute float32 value. */
//#include "iopt_memmap.h"
//
//	/* ## Operation body start [1b003077-4d28-47df-ab9f-bee2ab18a86e] */
//
//	sint32  hex_value, i;
//	sint16  exp;
//	float32 tmp_value = value;
//	hex_value = /*lint -e(9087) *//*lint -e(9079) */  *(sint32 *)(void *)&value;
//	exp = (sint16)((((uint32)hex_value >> 23) & 0xFFU) - 127U);
//	if (exp < 22)
//	{
//		if (exp < 0)
//		{
//			/*small numbers get rounded to 0 or 1, depending on their sign
// raise inexact if ValValue != 0 */
//			if (tmp_value > 0.0f)
//			{
//				tmp_value = 0.0f;
//			}
//			else
//			{
//				if (tmp_value < 0.0f)
//				{
//					tmp_value = -1.0f;
//				}
//				else
//				{
//					tmp_value = 0.0f;
//				}
//			}
//		}
//		else
//		{
//			i = (sint32)(0x007fffff) >> exp;
//			if ( ( hex_value & i )== 0 )
//			{
//
//			}
//			else
//			{
//				if (tmp_value < 0.0f)
//				{
//					hex_value += (sint32)(0x00800000)>>exp;
//				}
//				hex_value =  (sint32)(hex_value & (sint32)(~(uint32)i));
//				tmp_value = /*lint -e(9087) *//*lint -e(9079) */ *(float32 *)(void *)&hex_value;
//			}
//		}
//	}
//	else
//	{
//		if (exp == 0x80)
//		{
//			tmp_value = F32_MAX + F32_EPSILON;/*invoking overflow*/
//		}
//		else
//		{
//			/*nothing */
//		}
//	}
//	return tmp_value;
//
//	/* ## Operation body end [1b003077-4d28-47df-ab9f-bee2ab18a86e] */
//}
//
///** This operation returns the integer value determined by rounding the argument towards positive infinity with underflow overflow saturation. Also the input values shall be limited in case of overflow or underflow before the return value is calculated.
//
//If 0.0< value <= FLT_MIN, then the return value shall be 1.0
//If 0.0 > value >= -FLT_MIN, then the return value shall be 0.0
//
//The operation shall be synchronous and reentrant.
//
//@param value Input value as float32.
//@return float32 rounded value */
//#include "iopt_memmap.h"
//
// float32 f32_ceil_f32(float32 value)
//{
//	/* ## Operation body start [188a232b-2a15-4f48-b5c9-f54ac08d2472] */
//
//	sint32  hex_value, i;
//	float32 tmp_f32;
//	sint16  exp;
//	hex_value = /*lint -e(9087) *//*lint -e(9079) */  *(sint32 *)(void *)&value;
//	exp = (sint16)((((uint32)hex_value >> 23) & 0xFFU) - 127U);
//
//	if (exp < 22)
//	{
//		if (exp < 0)
//		{
//			/*small numbers get rounded to 0 or 1, depending on their sign
//			 */
//			if (hex_value < 0)
//			{
//				hex_value =(sint32)0x80000000;
//			}
//			else
//			{
//				if (hex_value !=0)
//				{
//					hex_value = (sint32)0x3f800000;
//				}
//			}
//		}
//		else
//		{
//			i = (sint32)(0x007fffff) >> exp;
//			if ( ( hex_value & i )== 0 )
//			{
//				hex_value = /*lint -e(9087) *//*lint -e(9079) */  *(sint32 *)(void *)&value;
//			}
//			else
//			{
//				if (hex_value > 0)
//				{
//					hex_value += (sint32)(0x00800000)>>exp;
//				}
//				hex_value = (sint32)(hex_value & (sint32)(~(uint32)i));
//			}
//		}
//	}
//	else
//	{
//		if (exp == 0x80)
//		{
//			tmp_f32 =  (F32_MAX + F32_EPSILON);
//			hex_value = /*lint -e(9087) *//*lint -e(9079) */  *(sint32 *)(void *)&tmp_f32;
//		}
//		else
//		{
//			hex_value = /*lint -e(9087) *//*lint -e(9079) */  *(sint32 *)(void *)&value;
//		}
//		/* x is integral */
//	}
//	return ( /*lint -e(9087) *//*lint -e(9079) */ *(float32 *)(void *)&hex_value );
//
//	/* ## Operation body end [188a232b-2a15-4f48-b5c9-f54ac08d2472] */
//}
//
///** This operation calculates absolute value for the argument of type float32 and returns a result of type float32.
//
//Result: result = |value|.
//	Range of the result :  0.. MAX_FLOAT.
//
//@param value Input value as float32.
//@return Absolute float32 value. */
//#include "iopt_memmap.h"
//
// float32 f32_abs_f32(float32 value)
//{
//	/* ## Operation body start [ab73ad45-e757-424e-8c3b-155526c6b4e7] */
//	float32 tmp_ret;
//	if (value < 0.0f)
//	{
//		tmp_ret = -value;
//	}
//	else
//	{
//		tmp_ret = value;
//	}
//	return tmp_ret;
//	/* ## Operation body end [ab73ad45-e757-424e-8c3b-155526c6b4e7] */
//}

/*~E*/
/*~A*/
/*~+:Private and Public Operations*/
/** This operation calculates the tangent of the argument of type float32 and returns the result of type F32.

Result: result = tangent( value ).
	Range of the result: [-MAX_FLOAT, MAX_FLOAT]

If FLT_MIN <= val < RAD_MIN, return value shall be "val" (Reason : for small "val" -> sin(val) / cos(val) = val/1.0 = val ) 
If FLT_MIN <= val < -RAD_MIN, return value shall be "val" (Reason : for small "val" -> sin(val) / cos(val) = val/1.0 = val ) 
The absolute deviation from the correct result is smaller than 1.0f for input values (k*pi -1.55) <= ValValue <= (k*pi + 1.55), with k between -1310 and 1310. There are no accuracy requirements outside this input range.
IMS Requirement Number : 8190266

@param x Input angle value as float32.
@return float32 tan value. */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern float32 f32_tan_f32(float32 x);


/** This operation calculates the square root of the argument of type float32 and returns the result of type F32.

Result:  result = square root ( value ).
	 Range of the result: -MAX_FLOAT - MAX_FLOAT (result is assumed to be within the range and no limitation required).

In case of negative number, operation shall return " -square root(abs(value))" 
In case of zero, operation shall return zero.

@param value Input value as float32.
Range of input is: 0 ... MAX_FLOAT
@return float32 value. */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern float32 f32_sqrt_f32(float32 value);


/** This operation calculates the sine of the argument of type float32 and returns the result of type F32.

Result: result = sine ( value ). 
	Range of the result: [-1,1]

If FLT_MIN <= val <= RAD_MIN, return value shall be "val" (Reason : for small val -> sin(val) = val ) 
If -FLT_MIN <= val <= -RAD_MIN, return value shall be val (Reason : for small val -> sin(val) = val ) 
The absolute deviation from the correct result is smaller than 0.001f for input values -8347.0f <= ValValue <= 8347.0f. There are no accuracy requirements outside this input range.
IMS Requirement Number : 3744193

@param x Input angle value as float32.
@return float32 sine value. */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern float32 f32_sin_f32(float32 x);


/** The operation shall return the power calculation of "Base"^"Exponent" with underflow overflow saturation. Also the input values shall be limited in case of overflow or underflow before the return value is calculated.
the input parameters.
- ValBase = Base 
- ValExp = Exponent
If Return value > FLT_MAX or < -FLT_MAX
	then Return value = (pos/neg)FLT_MAX
If Return value < (pos/neg) FLT_MIN
	then Return value = 0.0

If Input value > FLT_MAX or Input value < -FLT_MAX, the input value shall be limited to (pos/neg) FLT_MAX. 
If Input value < (pos/neg) FLT_MIN, the Input value shall be limited to 0.0, before the return value is calculated.
if Base < 0.0 
	Return value = NAN
If Base or Exponent = NaN, 	return value does not matter as the controller shall be configured to throw an exception before 
If Base = 0.0 and Exponent = 0.0
	Return value = 1.0
If Base = 0.0 and Exponent equal NaN
	Return = 0.0
If Base = 1.0 and Exponent equal NaN
	Return = 1.0
If 0.0< Base pow Exponent <= -FLT_MIN
	Return = 0.0
If 0.0< Base pow Exponent <= FLT_MIN
	Return = 0.0
If Base pow Exponent > FLT_MAX, return value shall be FLT_MAX + FLT_EPSILON -> provoke overflow, then the result depends on the configuration of the controller (e.g.  FLT_MAX or +INF)

@param valbase Input valbase as float32.
@param valexp Input valexp as float32.
@return result of float32 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern float32 f32_pow_f32_f32(float32 valbase, float32 valexp);


/** Result
       Result = numerator - (n * denominator)
Where n is the quotient of numerator divided by denominator
Magnitude of the result shall be 0 <= result < |denominator|
The sign of result shall be same as the numerator.

@param numerator Dividend : Input Parameter 1
@param denominator Divisor: Input Parameter 2
@return Returns the remainder of divison operation. */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern float32 f32_mod_f32_f32(float32 numerator, float32 denominator);


/** This function shall calculate the inverse of matrix A and store the inverse matrix in B if it exists. The return value would be E_OK if an inverse matrix exists and E_NOT_OK otherwise. If an inverse matrix does not exist, B will be the zero matrix. 
B = [A]^(-1)

Determinant
|A| = A11*A22 - A12*A21

If |A| = 0

B will be zero matrix.
Return E_NOT_OK

If |A| not equal to 0 
Return inverse of B.
Return E_OK.

@param A[2][2] Input Parameter which is to be inversed.
@param B[2][2] Inverse matrix of Matrix A, if it exists.
@return Standard return type to indicate inverse of matrix exists or not */
extern Std_ReturnType invert_matrix_2_2(float32 A[2][2], float32 B[2][2]);


/** This function shall calculate the inverse of matrix A and store the inverse matrix in B if it exists. The return value would be E_OK if an inverse matrix exists and E_NOT_OK otherwise. If an inverse matrix does not exist, B will be the zero matrix. 
B = [A]^(-1)
Determinant
|A| = A11 (A33*A22-A23*A32) - A12 (A21*A33- A31*A23) + A13 (A21*A32-A31*A22)
If |A| = 0

B will be zero matrix.
Return E_NOT_OK

If |A| not equal to 0 
Return inverse of B.
Return E_OK.

@param A[3][3] Input Matrix to be inversed
@param B[3][3] Inverse of matrix A, if it exists.
@return Standard return type to indicate inverse of matrix exists or not */
extern Std_ReturnType invert_matrix_3_3(float32 A[3][3], float32 B[3][3]);


/** The operation shall return the natural logarithm of the argument "val" with underflow overflow saturation. Also the input values shall be limited in case of overflow or underflow before the return value is calculated.

result = Ln to the base e (val), val is float32 and range is 1.0 < val <= FLT_MAX

If Return value > FLT_MAX or < -FLT_MAX
	then Return value = (pos/neg)FLT_MAX
If Return value < (pos/neg) FLT_MIN
	then Return value = 0.0

If Input value > FLT_MAX or Input value < -FLT_MAX, the input value shall be limited to (pos/neg) FLT_MAX. 
If Input value < (pos/neg) FLT_MIN, the Input value shall be limited to 0.0
if val < 0.0 
	Return value = NaN, the value shall provoke an exception before the function returns value
If val = 1.0 
	Return value = +0.0
If val = +INF
	Return Value = INF, provoke overflow.
If 0.0<= val <= FLT_MIN , return value shall be -INF -> provoke negative overflow
Maximum deviation from true value will be 0.2% .

@param value Input value as float32.
@return Natural logarithmic float32 value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern float32 f32_ln_f32(float32 value);


/** This operation returns result such that if the difference between the new value and the old value in the upward direction is greater than the maximum possible difference, the result is limited to (old value + maximum difference). Otherwise, the result is as the new value.
All the input and return parameters are of type float32.

Result: if (newval > oldval )
	    if (newval - oldval ) > maxdif
		result = oldval + maxdif
                else
		result = newval
	else
	    result = newval

@param newval New value as float32.
@param oldval Old value as float32.
@param maxdif Maximum allowed difference as float32.
@return Result of calculation as float32. */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern float32 f32_limitnew_up_f32_f32_f32(float32 newval, float32 oldval, float32 maxdif);


/** This operation returns result such that if the difference between the new value and the old value in the downward direction is greater than the maximum possible difference, the result is limited to (old value - maximum difference). Otherwise, the result is same as the new value.
All the input and return parameters are of type float32.

Result:  if (oldval > newval)
       	      if (oldval - newval ) > maxdif
		result = oldval - maxdif
	      else
		result = newval
	 else
	      result = newval

@param newval New value as float32.
@param oldval Old value as float32.
@param maxdif Maximum allowed difference as float32.
@return Result of calculation as float32. */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern float32 f32_limitnew_down_f32_f32_f32(float32 newval, float32 oldval, float32 maxdif);


/** This operation calculates the inverse sine value of the argument of type float32 and returns a result of type float32 with underflow overflow saturation. Also the input values shall be limited in case of overflow or underflow before the return value is calculated.
Range for input value will be [-1,1].
IF |x| > 1, return NAN, input to arcsin function beyond range  [-1,1] is invalid.

The range of the return value shall be -PI/2....PI/2.
If the argument is zero, then the result is a zero with the same sign as the argument. 
The operation shall be synchronous and reentrant.
Maximum deviation from true value will be 1.0%

@param x value Input parameter as Float32.
@return Absolute float32 value. */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern float32 f32_arcsin_f32(float32 x);


/** This operation calculates the inverse cosine value of the argument of type float32 and returns a result of type float32 with underflow overflow saturation. Also the input values shall be limited in case of overflow or underflow before the return value is calculated.
Range for input value will be [-1,1].
IF |x| > 1, return NAN, input to arccos function beyond range  [-1,1] is invalid.
The range of the return value shall be 0....PI.
If the argument is zero, then the result is a one. 
The operation shall be synchronous and reentrant.
Maximum deviation from true value will be 1.0%

@param x value Input parameter as Float32.
@return Absolute float32 value. */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern float32 f32_arccos_f32(float32 x);


/** The operation shall return the exponent of the argument "val with underflow overflow saturation. Also the input values shall be limited in case of overflow or underflow before the return value is calculated.
result = e^val, val is float32 value.

If Return value > FLT_MAX or < -FLT_MAX
	then Return value = (pos/neg)FLT_MAX
If Return value < (pos/neg) FLT_MIN
	then Return value = 0.0	
If Return value = NaN (sNaN or qNaN), the value shall be provoke an exception before the function returns value	
If Input value > FLT_MAX or Input value < -FLT_MAX, the input value shall be limited to (pos/neg) FLT_MAX. 
If Input value < (pos/neg) FLT_MIN, the Input value shall be limited to 0.0
If Input value = NaN the input value shall be provoke an exception before the return value is calculated. 
If Input value "val" = -INF, return value shall be +0.0
If Input value -INF <= val <= -126 * ln(2), return value shall be -FLT_MIN/2 -> provoke underflow
If Input value +INF >= val >= 128*ln(2) return value shall be FLT_MAX + F32_EPSILON -> provoke overflow
If Input value 0.0<= val <= -FLT_MIN, return value shall be 1.0 
If Input value 0.0<= val <= FLT_MIN, return value shall be 1.0 
Maximum deviation from true value will be 0.1% .

@param value Input value as float32.
@return Exponential float32 value */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern float32 f32_exp_f32(float32 value);


/** This operation shall divide float32 values with zero-div-limitation
    if (divisor != 0)
    then result = dividend / divisor;
    else result = default_value

@param dividend Dividend : Input parameter as Float32.
@param divisor Divisor : Input parameter as Float32.
@param default_value Default_value  Input parameter as Float32.
@return Returns Float32 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern float32 f32_div_f32_f32_f32(float32 dividend, float32 divisor, float32 default_value);


/** This operation shall divide float32 values with zero-div-limitation
    if  (divisor != 0)
    then    tmpresult = dividend / divisor
        result  = value, limited between [ minimum .. maximum ]
    else    if dividend < 0 then  result = minimum
                else  result = maximum

@param dividend Dividend : Input parameter as Float32.
@param divisor Divisor : Input parameter as Float32.
@param minimum Minimum  Input parameter as Float32.
@param maximum Maximum Input parameter as Float32.
@return Returns Float32 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern float32 f32_div_f32_f32_min_max_f32_f32(float32 dividend, float32 divisor, float32 minimum, float32 maximum);


/** This operation calculates cosine of the argument of type float32 and returns the result of type float32.

Result: result = cosine ( value ).
	Range of the result: [-1,1]

If FLT_MIN <= val < RAD_MIN, return value shall be 1.0 (Reason : for small "val" -> cos(val<<) = 1.0 ) 
If -FLT_MIN <= val < -RAD_MIN, return value shall be 1.0 (Reason : for small "val" -> cos(val<<) = 1.0 ) 

The absolute deviation from the correct result is smaller than 0.001f for input values -8307.0f <= ValValue <= 8307.0f. There are no accuracy requirements outside this input range.
IMS Requirement Number : 3744414

@param x Input angle as float32:
@return float32 cosine value. */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern float32 f32_cos_f32(float32 x);


/** This operation calculates the inverse tangent value of the arguments of type float32 and returns a result of type float32.
 If atan = (X1_f32/X2_f32) then, 
 If atan < 0, then "atan" shall be set to "-atan".
 If atan < FLT_MIN then return value shall be 0.0
 If X2_f32 = 0.0 and X1_f32 <0.0, then return value is -PI/2
 If X2_f32 = 0.0 and X1_f32 >0.0, then return value is PI/2
 If X2_f32 = 0.0 and X1_f32 =0.0, then return value is 0.0
The range of the return value shall be -PI/2....PI/2.
If the argument is zero, then the result is a zero with the same sign as the argument. 

The operation shall be synchronous and reentrant.

@param X1_f32 value 1: Input parameter as Float32.
@param X2_f32 value 2: Input parameter as Float32.
@return Absolute float32 value. */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern float32 f32_arctan_f32_f32(float32 X1_f32, float32 X2_f32);


/*~E*/
#include "iopt_memmap.h"
#endif
