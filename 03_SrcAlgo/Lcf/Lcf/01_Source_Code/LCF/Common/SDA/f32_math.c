/*
 * f32_math.c
 *
 *  Created on: Nov 16, 2021
 *      Author: uie54321
 */
#include "f32_math.h"

uint8 u8_f32(float32 value)
{
	/* ## Operation body start [cc65bc57-8e97-49d1-83e7-4a4ad287aa0b] */
	uint8 res;
	if (value >= 255.0f)
	{
		res = U8_MAX;
	}
	else
	{
		if (value <= 0.0f)
		{
			res = U8_MIN;
		}
		else
		{
			res = (uint8)value;
		}
	}
	return res;
	/* ## Operation body end [cc65bc57-8e97-49d1-83e7-4a4ad287aa0b] */
}

/** This operation converts a single precision float value to unsigned integer data type with overflow and underflow limitation.

Result: uint16 equivalent of float32 value.

@param value Input value as float32.
@return Value converted and limited to Uint16. */
#include "iopt_memmap.h"

 uint16 u16_f32(float32 value)
{
	/* ## Operation body start [1d78f73f-22b6-4f78-836f-78c67f43603c] */
	/*~T*/
	uint16 res;
	if (value >= 65535.0f)
	{
		res = U16_MAX;
	}
	else
	{
		if (value <= 0.0f)
		{
			res = U16_MIN;
		}
		else
		{
			res = (uint16)value;
		}
	}
	return res;
	/* ## Operation body end [1d78f73f-22b6-4f78-836f-78c67f43603c] */
}

/** This operation converts a single precision float value to unsigned long integer data type with overflow and underflow limitation.

Result: uint32 equivalent of float32 value.

@param value Input value as float32.
@return Value converted and limited to uint32. */
#include "iopt_memmap.h"

 uint32 u32_f32(float32 value)
{
	/* ## Operation body start [c1d8b9dc-9eec-44e7-8d8c-ca61f7d4ba57] */
	/*~T*/
	uint32 res;
	if (value >= 4294967295.0f)
	{
		res = U32_MAX;
	}
	else
	{
		if (value <= 0.0f)
		{
			res = U32_MIN;
		}
		else
		{
			res = (uint32)value;
		}
	}
	return res;
	/* ## Operation body end [c1d8b9dc-9eec-44e7-8d8c-ca61f7d4ba57] */
}

/** This operation converts a single precision float value to signed character data type with overflow and underflow limitation.

Result: sint8 equivalent of float32 value.

@param value Input value as float32.
@return Value converted and limited to Sint8. */
#include "iopt_memmap.h"

 sint8 s8_f32(float32 value)
{
	/* ## Operation body start [f246815b-f531-4b33-b1d3-640be76f3f72] */
	/*~T*/
	sint8 res;
	if (value >= 127.0f)
	{
		res = S8_MAX;
	}
	else
	{
		if (value <= -128.0f)
		{
			res = S8_MIN;
		}
		else
		{
			res = (sint8)value;
		}
	}
	return res;
	/* ## Operation body end [f246815b-f531-4b33-b1d3-640be76f3f72] */
}

/** This operation converts a single precision float value to signed integer data type with overflow and underflow limitation.

Result: sint16 equivalent of float32 value.

@param value Input value as float32.
@return Value converted and limited to Sint16. */
#include "iopt_memmap.h"

 sint16 s16_f32(float32 value)
{
	/* ## Operation body start [3cd66498-7ad2-457d-8caa-79f0d61da0b5] */
	/*~T*/
	sint16 res;
	if (value >= 32767.0f)
	{
		res = S16_MAX;
	}
	else
	{
		if (value <= -32768.0f)
		{
			res = S16_MIN;
		}
		else
		{
			res = (sint16)value;
		}
	}
	return res;
	/* ## Operation body end [3cd66498-7ad2-457d-8caa-79f0d61da0b5] */
}

/** This operation converts a single precision float value to signed long integer data type with overflow and underflow limitation.

Result: sint32 equivalent of float32 value.

@param value Input value as float32.
@return Value converted and limited to Sint32. */
#include "iopt_memmap.h"

 sint32 s32_f32(float32 value)
{
	/* ## Operation body start [182938d4-f6f6-4f58-9758-c42cae31e95e] */
	/*~T*/
	sint32 res;
	if (value >= 2147483647.0f)
	{
		res = S32_MAX;
	}
	else
	{
		if (value <= -2147483648.0f)
		{
			res = S32_MIN;
		}
		else
		{
			res = (sint32)value;
		}
	}
	return res;
	/* ## Operation body end [182938d4-f6f6-4f58-9758-c42cae31e95e] */
}

/** This operation converts a single precision float value to signed long integer data type with overflow and underflow limitation.
If the argument "value" >= 9223372036854775807.0, return value shall be S64_MAX.
If the argument "value" <= -9223372036854775808.0, return value shall be S64_MIN.
If the input argument "value" is in the range -9223372036854775807.0 < value < 9223372036854775808.0 return value is floor(value) for value >= 0.0, and -floor(-value) for value < 0.0.
Result: sint64 equivalent of float32 value.

@param value Input value as float32.
@return Value converted and limited to Sint64. */
#include "iopt_memmap.h"

 sint64 s64_f32(float32 value)
{
	/* ## Operation body start [bf9e0131-f2d9-4422-b242-e6204dea73ec] */
	/*~T*/
	const float32 F32_2POW32 = 4294967296.0f;
	sint64 res=(sint64)0;

	uint32 HIGH32_value;
	float32 f32_tmp,tmp2;
	uint8 sign=0;

	/*~T*/
	f32_tmp = value;
	if (f32_tmp <= (float32)S64_MIN)
	{
		res = S64_MIN;
	}
	else
	{
		if (f32_tmp >= (float32)S64_MAX)
		{
			res =S64_MAX;
		}
		else
		{
			if (f32_tmp < 0.0f )
			{
				f32_tmp = -f32_tmp;
				sign = 1;
			}
			/*~T*/

			/*~T*/
			tmp2  = (f32_tmp/F32_2POW32);  /*upper 32 bit*/
			HIGH32_value  = (uint32)tmp2;
			f32_tmp = f32_tmp - ((float32)HIGH32_value*F32_2POW32); /*lint !e9034 DAT.11, MISRA 10.3: false positive, bug in PC-Lint*/ /*Subtract already converted part*/
			res = (sint64)(((uint64)HIGH32_value<<32) | (uint32)f32_tmp); /*combine upper and lower 32 bits*/

			if (sign !=0U)
			{
						                res = ((sint64)0-res);
			}
			else
			{
						            /*Else not required*/
			}
			/*~T*/

		}
	}
	/*~T*/
	return res;
	/*~T*/
	/* ## Operation body end [bf9e0131-f2d9-4422-b242-e6204dea73ec] */
}

/** This operation converts a single precision float value to unsigned long integer data type with overflow and underflow limitation.
If the argument "value" >= 18446744073709551615.0
, return value shall be U64_MAX.
If the argument "value" <= 0.0, return value shall be U64_MIN.
If the input argument "value" is in the range 18446744073709551615.0
 < value < 0.0 return value is floor(value) for value >= 0.0, and -floor(-value) for value < 0.0.

Result: uint64 equivalent of float32 value.

@param value Input value as float32.
@return Value converted and limited to Uint64. */
#include "iopt_memmap.h"

 uint64 u64_f32(float32 value)
{
	/* ## Operation body start [bf9e0131-f2d9-4422-b242-e6204dea73ec] */
	/*~T*/
	const float32 F32_2POW32 = 4294967296.0f;
	uint64 res;
	uint32 HIGH32_value;
	float32 f32_tmp,tmp2;
	/*~T*/
	f32_tmp = value;
	if (f32_tmp <= (float32)U64_MIN)
	{
		res = U64_MIN;
	}
	else
	{
		if (f32_tmp >= (float32)U64_MAX)
		{
			res = U64_MAX;
		}
		else
		{
			tmp2  = (f32_tmp/F32_2POW32);  /*upper 32 bit*/
			HIGH32_value  = (uint32)tmp2;
			f32_tmp = f32_tmp - (((float32)HIGH32_value)*F32_2POW32); /*Subtract already converted part*/
			res = ((uint64)HIGH32_value<<32) | (uint32)f32_tmp; /*combine upper and lower 32 bits*/
		}
	}
	/*~T*/
	return res;
	/*~T*/
	/* ## Operation body end [bf9e0131-f2d9-4422-b242-e6204dea73ec] */
}

/** This operation calculates the signum of the given argument of type float32 and returns a result of type S8.

Result: result is -1 if value < 0,
	             0 if value = 0,
	             1 if value > 0.

@param value Input value as float32.
@return Signum of F32 input value as Sint8. */
#include "iopt_memmap.h"

 sint8 s8_sgn_f32(float32 value)
{
	/* ## Operation body start [7b4acc2b-e2f0-400f-8b26-361559887e50] */
	sint8 tmp_ret ;
	if (value < 0.0f)
	{
		tmp_ret = (sint8)-1;
	}
	else
	{
		if (value == 0.0f)
		{
			tmp_ret = 0;
		}
		else
		{
			tmp_ret = 1;
		}
	}
	return tmp_ret;
	/* ## Operation body end [7b4acc2b-e2f0-400f-8b26-361559887e50] */
}

/** This operation calculates a new floating average using old floating average, actual measured value and mmv coefficient. All the input and return parameters are of type float32.

Result: result = mmv + ((value - mmv) * mmv_coefficient).

@param mmv Old floating average value as float32.
@param value Actual measured value as float32.
@param mmv_coefficient Coefficient for calculation of new mmv as float32.
@return New floating average value as float32. */
#include "iopt_memmap.h"

 float32 f32_mmv_f32_f32_f32(float32 mmv, float32 value, float32 mmv_coefficient)
{
	/* ## Operation body start [31c33355-d86c-448b-a050-cce4a7a310de] */
	return (mmv + ((value - mmv) * mmv_coefficient));
	/* ## Operation body end [31c33355-d86c-448b-a050-cce4a7a310de] */
}

/** This operation limits the value between minimum and maximum arguments. All the input and return parameters are of type float32.

Result: value is limited to minimum, if value <= minimum,
	value is limited to maximum, if value >= maximum.

@param value Input value as float32.
@param minimum Minimum value as float32.
@param maximum Maximum value as float32.
@return Limited float32 value. */
#include "iopt_memmap.h"

 float32 f32_min_max_f32_f32_f32(float32 value, float32 minimum, float32 maximum)
{
	/* ## Operation body start [0e17af50-b46d-4820-be19-ac6f13c5b6b4] */
	/*~T*/
	float32 res;
	if (value >= maximum)
	{
		res = maximum;
	}
	else
	{
		if (value <= minimum)
		{
			res = minimum;
		}
		else
		{
			res = value;
		}
	}
	return res;
	/* ## Operation body end [0e17af50-b46d-4820-be19-ac6f13c5b6b4] */
}

/** This operation returns the maximum of the two input arguments. All the input and return parameters are of type float32.

Result: if (x_val > y_val)
 	    result = x_val
 	else
	    result = y_val

@param x_val First argument as float32.
@param y_val Second argument as float32.
@return Maximum of two input values as float32. */
#include "iopt_memmap.h"

 float32 f32_max_f32_f32(float32 x_val, float32 y_val)
{
	/* ## Operation body start [f3b95cb6-4382-4fa8-9a8b-d249f4422cb3] */
	return ( (x_val > y_val) ? x_val : y_val );
	/* ## Operation body end [f3b95cb6-4382-4fa8-9a8b-d249f4422cb3] */
}

/** This operation returns the minimum of the two input arguments. All the input and return parameters are of type float32.

Result: if (x_val < y_val)
	    result = x_val
	else
	    result = y_val

@param x_val First argument as float32.
@param y_val Second argument as float32.
@return Minimum of two input values as float32. */
#include "iopt_memmap.h"

 float32 f32_min_f32_f32(float32 x_val, float32 y_val)
{
	/* ## Operation body start [cedffda9-40b0-465e-a071-c26b6b457e4a] */
	return ( (x_val < y_val) ? x_val : y_val );
	/* ## Operation body end [cedffda9-40b0-465e-a071-c26b6b457e4a] */
}

/** This operation returns the result of a first order high-pass filter with the input parameters as previous output (y_old), present input (u), previous input (u_old) and a constant multiplying factor (m).
All the input and return parameters are of type float32.

Result: result = [(1 - m) * y_old] + (u -u_old)

@param y_old Previous output as float32.
@param u Present input as float32.
@param u_old Previous input as float32.
@param m Constant multiplying factor as float32.
@return Result value of high-pass filter as float32. */
#include "iopt_memmap.h"

 float32 f32_hip1_f32_f32_f32_f32(float32 y_old, float32 u, float32 u_old, float32 m)
{
	/* ## Operation body start [385857ed-11fa-42df-82c3-9a52900e03c3] */
	return (((1.0f - m) * y_old) + (u - u_old));
	/* ## Operation body end [385857ed-11fa-42df-82c3-9a52900e03c3] */
}

/** This operation shall return the natural number value determined by rounding the argument towards negative infinity with underflow overflow saturation. Also the input values shall be limited in case of overflow or underflow before the return value is calculated.

If 0.0< value <= FLT_MIN, then the return value shall be 0.0
If 0.0 > value >= -FLT_MIN, then the return value shall be -1.0

The operation shall be synchronous and reentrant.

@param value Input value as float32.
@return float32 rounded value */
#include "iopt_memmap.h"

 float32 f32_floor_f32(float32 value)
{
	/** This operation calculates absolute value for the argument of type float32 and returns a result of type float32.

Result: result = |value|.
	Range of the result :  0.. MAX_FLOAT.

@param value Input value as float32.
@return Absolute float32 value. */
#include "iopt_memmap.h"

	/* ## Operation body start [1b003077-4d28-47df-ab9f-bee2ab18a86e] */

	sint32  hex_value, i;
	sint16  exp;
	float32 tmp_value = value;
	hex_value = /*lint -e(9087) *//*lint -e(9079) */  *(sint32 *)(void *)&value;
	exp = (sint16)((((uint32)hex_value >> 23) & 0xFFU) - 127U);
	if (exp < 22)
	{
		if (exp < 0)
		{
			/*small numbers get rounded to 0 or 1, depending on their sign
 raise inexact if ValValue != 0 */
			if (tmp_value > 0.0f)
			{
				tmp_value = 0.0f;
			}
			else
			{
				if (tmp_value < 0.0f)
				{
					tmp_value = -1.0f;
				}
				else
				{
					tmp_value = 0.0f;
				}
			}
		}
		else
		{
			i = (sint32)(0x007fffff) >> exp;
			if ( ( hex_value & i )== 0 )
			{

			}
			else
			{
				if (tmp_value < 0.0f)
				{
					hex_value += (sint32)(0x00800000)>>exp;
				}
				hex_value =  (sint32)(hex_value & (sint32)(~(uint32)i));
				tmp_value = /*lint -e(9087) *//*lint -e(9079) */ *(float32 *)(void *)&hex_value;
			}
		}
	}
	else
	{
		if (exp == 0x80)
		{
			tmp_value = F32_MAX + F32_EPSILON;/*invoking overflow*/
		}
		else
		{
			/*nothing */
		}
	}
	return tmp_value;

	/* ## Operation body end [1b003077-4d28-47df-ab9f-bee2ab18a86e] */
}

/** This operation returns the integer value determined by rounding the argument towards positive infinity with underflow overflow saturation. Also the input values shall be limited in case of overflow or underflow before the return value is calculated.

If 0.0< value <= FLT_MIN, then the return value shall be 1.0
If 0.0 > value >= -FLT_MIN, then the return value shall be 0.0

The operation shall be synchronous and reentrant.

@param value Input value as float32.
@return float32 rounded value */
#include "iopt_memmap.h"

 float32 f32_ceil_f32(float32 value)
{
	/* ## Operation body start [188a232b-2a15-4f48-b5c9-f54ac08d2472] */

	sint32  hex_value, i;
	float32 tmp_f32;
	sint16  exp;
	hex_value = /*lint -e(9087) *//*lint -e(9079) */  *(sint32 *)(void *)&value;
	exp = (sint16)((((uint32)hex_value >> 23) & 0xFFU) - 127U);

	if (exp < 22)
	{
		if (exp < 0)
		{
			/*small numbers get rounded to 0 or 1, depending on their sign
			 */
			if (hex_value < 0)
			{
				hex_value =(sint32)0x80000000;
			}
			else
			{
				if (hex_value !=0)
				{
					hex_value = (sint32)0x3f800000;
				}
			}
		}
		else
		{
			i = (sint32)(0x007fffff) >> exp;
			if ( ( hex_value & i )== 0 )
			{
				hex_value = /*lint -e(9087) *//*lint -e(9079) */  *(sint32 *)(void *)&value;
			}
			else
			{
				if (hex_value > 0)
				{
					hex_value += (sint32)(0x00800000)>>exp;
				}
				hex_value = (sint32)(hex_value & (sint32)(~(uint32)i));
			}
		}
	}
	else
	{
		if (exp == 0x80)
		{
			tmp_f32 =  (F32_MAX + F32_EPSILON);
			hex_value = /*lint -e(9087) *//*lint -e(9079) */  *(sint32 *)(void *)&tmp_f32;
		}
		else
		{
			hex_value = /*lint -e(9087) *//*lint -e(9079) */  *(sint32 *)(void *)&value;
		}
		/* x is integral */
	}
	return ( /*lint -e(9087) *//*lint -e(9079) */ *(float32 *)(void *)&hex_value );

	/* ## Operation body end [188a232b-2a15-4f48-b5c9-f54ac08d2472] */
}

/** This operation calculates absolute value for the argument of type float32 and returns a result of type float32.

Result: result = |value|.
	Range of the result :  0.. MAX_FLOAT.

@param value Input value as float32.
@return Absolute float32 value. */
#include "iopt_memmap.h"

 float32 f32_abs_f32(float32 value)
{
	/* ## Operation body start [ab73ad45-e757-424e-8c3b-155526c6b4e7] */
	float32 tmp_ret;
	if (value < 0.0f)
	{
		tmp_ret = -value;
	}
	else
	{
		tmp_ret = value;
	}
	return tmp_ret;
	/* ## Operation body end [ab73ad45-e757-424e-8c3b-155526c6b4e7] */
}



