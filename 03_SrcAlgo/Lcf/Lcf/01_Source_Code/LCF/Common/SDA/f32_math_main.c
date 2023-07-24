/*~A*/
/*~+:VM Header*/
/* UML source model state: Draft */
/* ## Module Header Start [c768d364-f3d9-4b56-88c0-e0ea8d55b73d] */
/****************************************************************************

COPYRIGHT (C) $Date: 2019/07/03 13:44:19CEST $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.                                                 

The reproduction, transmission or use of this document or its contents is  
not permitted without express written authority.                           
Offenders will be liable for damages. All rights, including rights created 
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------

$Log: f32_math_main.c  $
Revision 1.1 2019/07/03 13:44:19CEST Nastasa, Elena (uidt4846) 
Initial revision
Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/Common/SDA/project.pj
Revision 1.1 2018/07/24 16:50:23CEST Ammermueller Martin (uidv5342) (uidv5342) 
Initial revision
Member added to project /ES/1T/0C/SDA/SDA_Source/SDA_Toolboxes/ACG/Libraries/ecmath_f32/Src/5_2_0/project.pj
Revision 1.11 2018/04/12 12:31:17CEST Ugran Parimala (uid41586) (uid41586) 
Added new functions in F32_math and improvement in accuracy of few of existing functions
Revision 1.9 2018/03/06 08:22:10CET Angadi Hampa (uidu8151) (uidu8151) 
RO : 8197596 : MISRA2012 ANSI VERSIONS
Revision 1.23 2018/01/29 03:03:38CET Angadi Hampa (uidu8151) (uidu8151) 
For TC39xb validation & New LINT correction (9029)
Revision 1.22 2017/06/21 10:56:47CEST Ugran Parimala (uid41586) (uid41586) 
Rework squore check MISRA2012
Revision 1.20 2017/05/08 12:31:05CEST Angadi Hampa (uidu8151) (uidu8151) 
MISRA 2012
Revision 1.19 2017/04/14 07:11:05CEST Ganesh Sumangala (uidu8725) (uidu8725) 
FS_0G01_TC2XX_F32MATH_COMP-ABSTRACT
Compiler abstract & validation
Revision 1.18 2017/02/15 10:25:31CET Angadi Hampa (uidu8151) (uidu8151) 
Inline & macros removal from f32_mayh_main.h 
RO : 5728843 : FS_0G01_F32MATH_5.1.0: pow() function correction
Revision 1.17 2017/02/02 05:36:52CET Angadi Hampa (uidu8151) (uidu8151) 
RO : 5728843 : FS_0G01_F32MATH_5.1.0: pow() function correction
Revision 1.16 2016/11/09 06:23:52CET Angadi Hampa (uidu8151) (uidu8151) 
changed to inline : Ceil & floor  fns
Revision 1.15 2016/10/26 10:41:08CEST Angadi Hampa (uidu8151) (uidu8151) 
Correcting the function names of exp & pow
Revision 1.14 2016/09/07 12:52:49CEST Adinarayanagowda Pruthviraj (uidp1961) (uidp1961) 
RO:4786123: FS_0G01_TC2XX_F32_MATH_5.0.0, New req 2
Revision 1.13 2016/09/06 11:01:03CEST Adinarayanagowda Pruthviraj (uidp1961) (uidp1961) 
RO:4786123: FS_0G01_TC2XX_F32_MATH_5.0.0, New req 2

 ****************************************************************************/
/* ## Module Header End [c768d364-f3d9-4b56-88c0-e0ea8d55b73d] */

/*~E*/
/*~A*/
/*~+:Includes*/
#include "Std_Types.h"
#include "powersar_addon_types.h"
#include "iopt_memmap.h"
#include "f32_math_main.h"
/*~E*/
/*~A*/
/*~+:LINT Supressions*/
/*lint --e{9079} */
/*lint --e{9087} */
/*lint --e{818} */
/*~E*/
/*~A*/
/*~+:Macro Definitions*/
#define F32_PI                                           3.1415926535897932384626433832795f  /**< Macros for Sine operation */
#define F32_INV_PI                                       0.3183098861837906715377675267450f  /**< 1/PI */
#define F32_SMALL_ANGLE                                  9.536743164e-7f  /**< sin(f32_small_angle)=f32_small_angle */
#define F32_S7                                           (-0.737066277507114174e-12f)  /**< S7 */
#define F32_S6                                           0.160478446323816900e-9f  /**< S6 */
#define F32_S5                                           (-0.250518708834705760e-7f)  /**< S5 */
#define F32_S4                                           0.275573164212926457e-5f  /**< S4 */
#define F32_S3                                           (-0.198412698232225068e-3f)  /**< S3 */
#define F32_S2                                           0.833333333327592139e-2f  /**< S2 */
#define F32_S1                                           (-0.166666666666659653f)  /**< S1 */
#define F32_EXP1                                         1.0f         
#define F32_EXP2                                         0.5f         
#define F32_EXP3                                         0.16666666666666666666666666666667f 
#define F32_EXP4                                         0.041666666666666666666666666666667f 
#define F32_EXP5                                         0.0083333333333333333333333333333333f 
#define F32_EXP6                                         0.0013888888888888888888888888888889f 
#define F32_PI_DIV_2                                     1.5707963267948966192313216916398f  /**< C1 */
#define F32_LOG2                                         0.693147180559945309e0f 
#define F32_INV_SQRTO2                                   0.707106781186547524e0f 
#define F32_P0                                           (-0.331355617479e1f) 
#define F32_P1                                           0.89554061525e0f 
#define F32_Q0                                           (-0.165677797691e1f) 
#define F32_INF                                          (2.0f*F32_MAX) 
/*~E*/
/*~A*/
/*~+:Private and Public Operations*/
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

float32 f32_limitnew_up_f32_f32_f32(float32 newval, float32 oldval, float32 maxdif)
{
	/* ## Operation body start [4c19a62a-30bc-42e6-8730-f6ad56f61652] */
	float32 res;
	if (newval > oldval)
	{
		if ((newval - oldval ) > maxdif)
		{
			res = (oldval + maxdif);
		}
		else
		{
			res = newval;
		}
	}
	else
	{
		res = newval;
	}
	return res;
	/* ## Operation body end [4c19a62a-30bc-42e6-8730-f6ad56f61652] */
}

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

float32 f32_limitnew_down_f32_f32_f32(float32 newval, float32 oldval, float32 maxdif)
{
	/* ## Operation body start [fe0e0159-010f-422e-a657-9fd165296442] */
	float32 res;
	if (oldval > newval)
	{
		if ((oldval - newval) > maxdif)
		{
			res = (oldval - maxdif);
		}
		else
		{
			res = newval;
		}
	}
	else
	{
		res = newval;
	}
	return res;
	/* ## Operation body end [fe0e0159-010f-422e-a657-9fd165296442] */
}

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

float32 f32_sqrt_f32(float32 value)
{
	
	/*~E*/
	/* This is not portable, but the whole implementation depends on IEEE-754, so we know what we are doing here */
	union { float32 val; //ElNa, union moved before variable initialization
	uint32 i;
	}tmp;
	/*~T*/
	
	/* ## Operation body start [234392aa-aa00-483a-9af8-fc79029d9732] */
	float32 tmp_value,result=0.0f;
	tmp_value = value;

	/*~A*/
	/*~+:Description of PC-Lint message-704 suppression*/
	/* Info 704: Use library functions for shift right and shift left. This PC-Lint info is disabled since a library must never use other libraries */



	if (value < 0.0f)
	{
		tmp_value = -tmp_value; /*Square Root of negative values  -sqrt(-val)*/
	}
	/*~T*/

	if (tmp_value >= F32_MIN)/* treat denormalized numbers as 0 */
	{
		/* We use the well-known FastInvSqrt for IEEE-754 in order to avoid divisions. Despite the proposal by Lomont we will use the original Quake3's magic, as this is most widely proven in use. As we are using an additional Newto
n-Raphson step, it will anyway make no practical difference, it is more a matter of taste. */
		tmp.val = tmp_value;

		/*~T*/
		tmp.i = 0x5F3759DFU - (tmp.i >> 1); /* the famous magic */
		result = tmp.val * (1.5F - (0.5F * (tmp_value * tmp.val) * tmp.val));
		result = result * (1.5F - (0.5F * (tmp_value * result) * result));
		result = result * (1.5F - (0.5F * (tmp_value * result) * result)); /* 3 times Newton-Raphson is for sure enough */
		result = result * tmp_value; /* from the inverse sqrt to the sqrt we only have to multiply with value */
		/*~T*/

	}
	else
	{
		result = 0.0F;
	}
	if (value < 0.0f)
	{
		result = -result;
	}
	/*~T*/

	/*~T*/
	return(result);
	/* ## Operation body end [234392aa-aa00-483a-9af8-fc79029d9732] */
}

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

float32 f32_tan_f32(float32 x)
{
	/* ## Operation body start [74030428-047d-462f-a178-15eb3f31f0bf] */
	float32 x_in,sine,cosine,tangent;

	x_in = x;
	if (x !=0.0f)
	{
		/*~T*/
		sine = f32_sin_f32(x_in);
		cosine = f32_cos_f32(x_in);
		/*~T*/
		/* Tangent calculation */
		if (cosine != 0.0f)
		{
			tangent = (sine / cosine);
		}
		else
		{
			/* if cos(tmp_x) is zero */
			if (sine > 0.0f)
			{
				/* return +infinity */
				tangent = (float32)F32_INF;

			}
			else
			{
				/* return -infinity */
				tangent = (float32)(-F32_INF);

			}
		}
	}
	else
	{
		tangent = 0.0f;
	}
	return tangent;
	/* ## Operation body end [74030428-047d-462f-a178-15eb3f31f0bf] */
}

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

float32 f32_cos_f32(float32 x)
{
	/* ## Operation body start [8bed8098-e134-4275-82c2-f4fc6af57b1e] */
	uint32 k;
	uint8  odd;
	sint8  sign = 0;
	float32 tmp, y, cosine = 0.0f,tmp_x;
	if (x != 0.0f)
	{
		/*~T*/
		/* cos(x)= sin(PI/2 + x)
         = sin(PI/2)*cos(x) + cos(PI/2)*sin(x)
         = cos(x) */
		tmp_x = x + F32_PI_DIV_2;
		/*~A*/
		/*~+:Cosine calculation using Taylor series */
		/*~T*/

		if (tmp_x < 0.0f)
		{
			sign = 1;
			tmp_x = -tmp_x;
		}
		/*~T*/
		/* Range Reduction between -PI/2 to PI/2*/
		tmp = (tmp_x * F32_INV_PI);
		k = (uint32)tmp;
		y = ((float32)k * F32_PI);
		tmp_x = tmp_x - y;
		odd = (uint8)(k & (uint32)0x01);
		/*~T*/
		/* sine calculation using Taylor series */
		y = tmp_x * tmp_x;
		tmp_x = (tmp_x + (tmp_x * (y * (F32_S1 + (y * (F32_S2 + (y * (F32_S3 + (y * (F32_S4 + (y * (F32_S5 + (y * (F32_S6 + (y * (F32_S7*y))))))))))))))));
		if (((sint8)odd ^ sign) == 1)
		{
			cosine = -tmp_x;
		}
		else
		{
			cosine = tmp_x;
		}
		/*~T*/

		/*~E*/
	}
	else
	{
		cosine = 1.0f;
	}
	/*~T*/
	return cosine;
	/* ## Operation body end [8bed8098-e134-4275-82c2-f4fc6af57b1e] */
}

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

float32 f32_sin_f32(float32 x)
{
	/* ## Operation body start [e9bc9b7a-d41e-4643-94ad-4ec1875c4c07] */
	sint8  sign = 0;
	uint8  odd = 0;
	uint32 k = 0;
	float32 tmp, y, sine = 0.0f,tmp_x;

	if (x != 0.0f)
	{
		tmp_x = x;
		if (tmp_x < 0.0f)
		{
			sign = 1;
			tmp_x = -tmp_x;
		}
		if (tmp_x > F32_SMALL_ANGLE)
		{
			if (tmp_x > F32_PI)
			{
				/* Range Reduction between 0 to PI*/
				tmp = (tmp_x * F32_INV_PI);
				k = (uint32)tmp;
				y = ((float32)k * F32_PI);
				tmp_x = tmp_x - y;
				odd = (uint8)(k & (uint32)0x01);
			}
			/* sine calculation using Taylor series */
			y = tmp_x * tmp_x;
			tmp_x = (tmp_x + (tmp_x * (y * (F32_S1 + (y * (F32_S2 + (y * (F32_S3 + (y * (F32_S4 + (y * (F32_S5 + (y * (F32_S6 + (y * (F32_S7*y))))))))))))))));
		}
		else
		{
			/*for small angles sin(tmp_x) = tmp_x*/
			sine = tmp_x;
		}
		if (((sint8)odd ^ sign) == 1)
		{
			sine = -tmp_x;
		}
		else
		{
			sine = tmp_x;
		}
	}
	else
	{
		sine = 0.0f;
	}
	return sine;
	/* ## Operation body end [e9bc9b7a-d41e-4643-94ad-4ec1875c4c07] */
}

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

float32 f32_mod_f32_f32(float32 numerator, float32 denominator)
{
	/* ## Operation body start [4144f586-2165-401e-a216-676c2d91f3d3] */
	sint32 n,hex_num,hex_den,hex_temp,exp_num,exp_den,sign_num;
	float32 result,tmp_res = 0.0f;
	boolean isDone = FALSE;

	hex_num =  *(sint32 *)(void *)&numerator;           /* Get hex equivalent numerator */
	hex_den =  *(sint32 *)(void *)&denominator;         /* Get hex equivalent denominator */
	sign_num = hex_num & (sint32)0x80000000;            /* sign of numerator */
	hex_num ^= sign_num;                                /* |numerator| */
	hex_den &= (sint32)0x7fffffff;                      /* |denominator| */
	if ( hex_den != 0 )         /* rid off exception values */
	{
		/*~A*/
		/*~+:Remainder Calculation*/
		if ( hex_num < hex_den )        /* |numerator| < |denominator| return numerator */
		{
			result =  numerator;
		}
		else
		{
			if (hex_num == hex_den)          /* |numerator| = |denominator| return 0*/
			{
				result =  0.0f;
			}
			else
			{
				/* find the exponent of hex_num minus 127  */
				exp_num = ((sint32)((uint32)hex_num >> 23))- 127;
				/* find the exponent of hex_den minus 127  */
				exp_den = ((sint32)((uint32)hex_den >> 23))- 127;
				/* set up hex_num, hex_den and align denominator to numerator */
				hex_num = 0x00800000 | (0x007fffff & hex_num);
				hex_den = 0x00800000 | (0x007fffff & hex_den);
				/* fix point fmod */
				n = exp_num - exp_den;
				while ( n != 0 )
				{
					n--;
					hex_temp = hex_num - hex_den;
					if (hex_temp < 0)
					{
						hex_num = hex_num + hex_num;
					}
					else
					{
						if (hex_temp == 0)  /* return sign(x)*0 */
						{
							tmp_res =  0.0f;
							isDone = TRUE;
							break;
						}
						else
						{
							hex_num = hex_temp + hex_temp;
						}
					}
				}
				hex_temp = hex_num - hex_den;
				if (isDone == TRUE )
				{
					result = tmp_res;
				}
				else
				{
					if (hex_temp >= 0)
					{
						hex_num = hex_temp;
					}
					/* convert back to floating value and restore the sign */
					while ( hex_num < 0x00800000 )
					{
						/* normalize numerator */
						hex_num = hex_num + hex_num;
						exp_den -= 1;
					}
					/* normalize output */
					hex_num = ((hex_num - 0x00800000) | ((sint32)((uint32)(exp_den + 127) << 23)));
					hex_num = (hex_num | sign_num);
					result =  *(float32 *)(void *)&hex_num; ; /* exact output */

				}
			}
		}

		/*~E*/
	}
	else
	{
		/* Invalid operation i.e. when denominator is zero, would lead to NAN*/
		hex_num = 0x7F800001;
		result = *(float32 *)(void *)&hex_num;
		result =  (2.0f * result);
	}
	return result;

	/* ## Operation body end [4144f586-2165-401e-a216-676c2d91f3d3] */
}

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

float32 f32_div_f32_f32_f32(float32 dividend, float32 divisor, float32 default_value)
{
	/* ## Operation body start [b2953636-fd88-4de5-821e-a65a185ea226] */
	float32 result;
	if (divisor != 0.0F)
	{
		result =  dividend / divisor;
	}
	else
	{
		result =  default_value;
	}
	return result;
	/* ## Operation body end [b2953636-fd88-4de5-821e-a65a185ea226] */
}

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

float32 f32_div_f32_f32_min_max_f32_f32(float32 dividend, float32 divisor, float32 minimum, float32 maximum)
{
	/* ## Operation body start [d299b00e-7d09-4198-a31d-aa8e33f6a8a2] */
	float32 temp_result,result;
	if (divisor != 0.0F)
	{
		temp_result = dividend / divisor;
		/* %0: return(value), %1(value), %2(minimum), %3(maximum) */


		if (temp_result>maximum)
		{
			result=maximum;
		}
		else
		{
			if (temp_result<minimum)
			{
				result=minimum;
			}
			else
			{
				result=temp_result;
			}
		}
	}
	else
	{
		if (dividend < 0.0F)
		{
			result =  minimum;
		}
		else
		{
			result =   maximum;
		}
	}
	return result;
	/* ## Operation body end [d299b00e-7d09-4198-a31d-aa8e33f6a8a2] */
}

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

float32 f32_exp_f32(float32 value)
{
	/* ## Operation body start [9eed851f-ca05-4984-9bfa-fa7ca85efa20] */
	float32 b;
	float32 result;
	float32 ln_value;
	sint32  hex_val;
	/* Overflow and Underflow limit check through (Value/ln(2)) */
	ln_value = 1.4426950F * value;

	if (ln_value >= 128.0F)
	{
		result = (float32)F32_INF; /* provoke overflow */
	}
	else
	{
		if (ln_value <= -126.24F)
		{
			result = F32_MIN/(ln_value+1.0f); /* provoke underflow */
		}
		else
		{
			/*~A*/
			/*~+:2^x function*/
			/* For all floatiing point numbers x, 2^x can be calculated as 2^i*2^j with i=trunc(x) and j=x-trunc(x), -1<j<1

            2^i can be calculated efficiently by directly manipulating an IEEE number (it is a number where we have to fill only the exponent as i+127, the rest are 0 bits

            2^j can be approximated by Taylor (use Taylor for Exp(y), replace y by z*ln(2) to get the correct coefficients

            Taylor works better (converges much faster) on -0.5<z<0.5 than on -1<z<1, therefore we use the fact that 2^j = 2^(j/2) * 2^(j/2) so setting b=Taylor(j/2) we can calculate 2^j as b*b


            Taylor Series Expansion for e power x:

                           n=inf   x^n 
            e^x = summation       -----
                           n=0      n!

                          x2    x3  x4  x5  x6 
            ex = 1 + x + ---- +----  ----  ---- + ú ú ú for all x
                          2!    3!  4!  5!  6!  


            2^x = (e^{ln 2})^x = e^(xln2) */
			/* normally forbidden, but we know it will stay in the limits */
			/* Instead of using this conversion "(hex_val =  *(sint32 *)(void *)&ln_value)" float is directly assigned to int value to round off the decimal part*/
			hex_val =  (sint32)ln_value;

			ln_value = ( ln_value - (float32)hex_val)  * 0.5f;         /* now x is in -0.5..0.5 */
			ln_value *= 0.69314718F;               /* x = x * ln(2) */

			hex_val += 127;                     /* make a.f = 2^a.i: step 1: add IEEE offset for exponent */
			hex_val *= 8388608;                 /* make a.f = 2^a.i: step 2: shift 23 bits left */

			/* b = TAYLOR (e^x, up to x^6) */

			b =
					1.0f + (ln_value*(F32_EXP1 + (ln_value*(F32_EXP2 + (ln_value*(F32_EXP3 + (ln_value*(F32_EXP4 + (ln_value*(F32_EXP5 + (ln_value*F32_EXP6)))))))))));

			result = ( (*(float32 *)(void *)&hex_val) * b * b);

			/*~E*/
		}
	}
	return result;
	/* ## Operation body end [9eed851f-ca05-4984-9bfa-fa7ca85efa20] */
}

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

float32 f32_ln_f32(float32 value)
{
	/* ## Operation body start [c11f7990-6b53-43ef-bd9d-efbfa0ca2605] */
	sint32 x,exp;
	uint32 temp;
	float32 result,ysq;
	float32 y;
	x = *(sint32 *)(void *)&value;
	if (value > 0.0f) /*float is used for NAN check*/
	{
		if (x == 0x3F800000) /* Hex representation for 1.0f*/
		{

			result = 0.0f;
		}
		else
		{
			if (x <= 0x7F7FFFFF)
			{
				exp = (sint32)((((uint32)x >>  23U) & (uint32)0xFF) - 127U);
				x &= (sint32)(~((uint32)0xFF << 23U));
				x += (sint32)((uint32)127 << 23);
				y = *(float32 *)(void *)&x;
				if (y < F32_INV_SQRTO2)
				{
					y = 2.0f*y;
					exp = exp - 1;
				}
				y = (y - 1.0f)/(y + 1.0f);
				ysq = y*y;
				result = (((((F32_P1*ysq) + F32_P0)/(ysq + F32_Q0))*y) + ((float32)exp*F32_LOG2));
			}
			else
			{
				result = (float32)(F32_INF);

				/* provoke overflow
				                when value
				                 is INFINITY */
			}
		}
	}
	else
	{
		if (value == 0.0f)
		{
			result = (float32)(-F32_INF); 

			/*Provoking negative overflow*/
		}
		else
		{
			temp = 0x7F800001;
			result =  (*(float32 *)(void *)&temp);


			/*return NAN*/
		}
	}
	return result;
	/* ## Operation body end [c11f7990-6b53-43ef-bd9d-efbfa0ca2605] */
}

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

float32 f32_pow_f32_f32(float32 valbase, float32 valexp)
{
	/* ## Operation body start [65e14b6d-a977-4c2e-ae88-369a1c4c3d68] */
	sint32 val1;
	float32 value;
	if (valbase < 0.0f)
	{
		val1= 0x7F800001;
		value =  (*(float32 *)(void *)&val1);
		/* retrun NAN */
	}
	else
	{
		if (valbase == 0.0f)
		{
			if (valexp == 0.0f)
			{
				value = 1.0f;
			}
			else
			{
				value = 0.0f;
			}
		}
		else
		{
			value = valexp * f32_ln_f32(valbase);
			value = f32_exp_f32(value);
		}
	}
	return(value);
	/* ## Operation body end [65e14b6d-a977-4c2e-ae88-369a1c4c3d68] */
}

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

float32 f32_arctan_f32_f32(float32 X1_f32, float32 X2_f32)
{
	/* ## Operation body start [b8a1a7d7-85ad-41b8-a9bc-46d18465bfae] */
	float32 Result;
	float32 atan2;
	if (X2_f32 != 0.0f)
	{
		atan2 = X1_f32/X2_f32;
		if (f32_abs_f32(atan2) < 1.0f)
		{
			atan2 = atan2/(1.0f + (0.28f*atan2*atan2));
			if (X2_f32 < 0.0f)
			{
				if (X1_f32 < 0.0f)
				{
					Result = atan2 - F32_PI;
				}
				else
				{
					Result = atan2 + F32_PI;
				}
			}
			else
			{
				Result = atan2;
			}
		}
		else
		{
			atan2 = F32_PI_DIV_2 - (atan2/((atan2*atan2) + 0.28f));
			if (X1_f32 < 0.0f)
			{
				Result = atan2 - F32_PI;
			}
			else
			{
				Result = atan2;
			}
		}
	}
	else
	{
		/*X2_f32 = 0*/
		if (X1_f32 > 0.0f)
		{
			Result = F32_PI_DIV_2;
		}
		else
		{
			if (X1_f32 < 0.0f)
			{
				Result = -F32_PI_DIV_2;
			}
			else
			{
				Result = 0.0f;
			}
		}

	}
	return Result;
	/* ## Operation body end [b8a1a7d7-85ad-41b8-a9bc-46d18465bfae] */
}

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

float32 f32_arcsin_f32(float32 x)
{
	/* ## Operation body start [de42c5ca-3aa5-4b83-b87c-e7402f04dae8] */

	/*~T*/
	float32 temp,res,arg;
	sint32 hex_num;
	sint8 sign = 0;
	uint8 odd = 0;
	/*~T*/
	arg = x;
	if (arg < 0.0f)
	{
		arg=-arg;
		sign = 1;
	}
	/*~T*/

	if (arg > 1.0f)
	{
		/* Invalid Input to inverse sine function*/
		hex_num = 0x7F800001;
		temp = *(float32 *)(void *)&hex_num;
	}
	else
	{
		/*~T*/
		temp = f32_sqrt_f32( 1.0f - (arg * arg) );
		if (arg>0.7f)
		{
			temp =  F32_PI_DIV_2 - f32_arctan_f32_f32( temp, arg );
		}
		else
		{
			temp = f32_arctan_f32_f32( arg, temp );
		}
		/*~T*/

	}
	/*~T*/

	if (((sint8)odd ^ sign) == 1)
	{
		res = -temp;
	}
	else
	{
		res = temp;
	}
	/*~T*/
	return res;
	/*~T*/
	/* ## Operation body end [de42c5ca-3aa5-4b83-b87c-e7402f04dae8] */
}

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

float32 f32_arccos_f32(float32 x)
{
	/* ## Operation body start [ac4510e8-d629-4546-81e8-52385d37c19b] */

	/*~T*/

	float32 temp,arg;

	sint32 hex_num;
	/*~T*/
	arg = x;
	/*~T*/

	if (arg > 1.0f)
	{
		/* Invalid Input to inverse sine function*/
		hex_num = 0x7F800001;
		temp = *(float32 *)(void *)&hex_num;
	}
	else
	{
		/*~T*/
		temp = f32_sqrt_f32( 1.0f - (arg * arg) );
		if (arg>0.7f)
		{
			temp =  F32_PI_DIV_2 - f32_arctan_f32_f32(arg,temp );
		}
		else
		{
			temp = f32_arctan_f32_f32(temp,arg );
		}
		/*~T*/

	}
	/*~T*/

	/*~T*/
	return temp;
	/*~T*/
	/* ## Operation body end [ac4510e8-d629-4546-81e8-52385d37c19b] */
}

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
Std_ReturnType invert_matrix_2_2(float32 A[2][2], float32 B[2][2])
{
	/* ## Operation body start [489a9b23-d58b-452a-a6f4-b0634218e887] */

	/*~T*/

	float32 determinant;

	float32 ADJ[2][2],Inp[2][2];

	uint8 i,j,temp;
	for (i=(uint8)0;i<(uint8)2;i++)
	{
		for (j=(uint8)0;j<(uint8)2;j++)
		{
			Inp[i][j] = A[i][j];
		}
	}
	/*~T*/
	determinant = (Inp[0][0]*Inp[1][1])- (Inp[0][1]*Inp[1][0]);
	if (determinant!=0.0f)
	{
		/*~T*/
		/*adjoint of matrix B*/
		ADJ[0][0]= Inp[1][1];
		ADJ[0][1]= - Inp[0][1];
		ADJ[1][0]= -Inp[1][0];
		ADJ[1][1]= Inp[0][0];
		for (i=(uint8)0;i<(uint8)2;i++)
		{
			for (j=(uint8)0;j<(uint8)2;j++)
			{
				B[i][j]= (float32)ADJ[i][j]/determinant;
			}
		}
		temp = E_OK;
	}
	else
	{
		/*~T*/

		for (i=(uint8)0;i<(uint8)2;i++)
		{
			for (j=(uint8)0;j<(uint8)2;j++)
			{
				B[i][j]=0.0f;
			}
		}
		/*~T*/
		temp = E_NOT_OK;
	}
	/*~T*/
	return temp;
	/*~T*/
	/* ## Operation body end [489a9b23-d58b-452a-a6f4-b0634218e887] */
}

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
Std_ReturnType invert_matrix_3_3(float32 A[3][3], float32 B[3][3])
{
	/* ## Operation body start [85eb17d3-3723-4944-ae9f-795e6785cd36] */

	/*~T*/

	float32 determinant=0.0f;

	float32 ADJ[3][3],Inp[3][3];

	uint8 i,j,temp;
	/*~T*/
	/*Determinant Calculation*/
	/*~T*/
	for (i=(uint8)0;i<(uint8)3;i++)
	{
		for (j=(uint8)0;j<(uint8)3;j++)
		{
			Inp[i][j] = A[i][j];
		}
	}
	for (i=(uint8)0;i<(uint8)3;i++)
	{
		determinant = determinant + ((Inp[0][i]*((Inp[1][(i+1U)%3U]*Inp[2][(i+2U)%3U]) - (Inp[1][(i+2U)%3U]*Inp[2][(i+1U)%3U]))));
	}

	if (determinant!=0.0f)
	{
		/*~T*/
		/*Co-factor and ad-joint calculation*/
		for (i=(uint8)0;i<(uint8)3;i++)
		{
			for (j=(uint8)0;j<(uint8)3;j++)
			{
				ADJ[i][j] = ((Inp[(i+1U)%3U][(j+1U)%3U] * Inp[(i+2U)%3U][(j+2U)%3U]) - (Inp[(i+1U)%3U][(j+2U)%3U]*Inp[(i+2U)%3U][(j+1U)%3U]));

			}
		}
		/*~T*/

		for (i=(uint8)0;i<(uint8)3;i++)
		{
			for (j=(uint8)0;j<(uint8)3;j++)
			{
				B[i][j] = ADJ[j][i]/determinant;
			}
		}
		/*~T*/

		/*~T*/
		temp = E_OK;
	}
	else
	{
		/*~T*/
		/*Set matrix B to a Zero matrix*/
		/*~T*/

		for (i=(uint8)0;i<(uint8)3;i++)
		{
			for (j=(uint8)0;j<(uint8)3;j++)
			{
				B[i][j]=0.0f;
			}
		}
		/*~T*/
		temp = E_NOT_OK;
	}
	/*~T*/
	return temp;
	/*~T*/
	/* ## Operation body end [85eb17d3-3723-4944-ae9f-795e6785cd36] */
}

/*~E*/

