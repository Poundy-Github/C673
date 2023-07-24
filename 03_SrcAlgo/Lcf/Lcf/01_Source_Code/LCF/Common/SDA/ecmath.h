/*~A*/
/*~+:VM Header*/
/* Used UML Profile version  */
/* ## Module Header Start [1d09789f-0cdd-4387-8fe8-a6aeaddd7201] */
/****************************************************************************

COPYRIGHT (C) $Date: 2019/11/29 08:45:56CET $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.                                                 

The reproduction, transmission or use of this document or its contents is  
not permitted without express written authority.                           
Offenders will be liable for damages. All rights, including rights created 
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------

$Log: ecmath.h  $
Revision 1.2.1.2 2019/11/29 08:45:56CET Nastasa, Elena (uidt4846) 
Update LCF code for new auxCodeGen 4.1
Revision 1.2.1.1 2019/07/03 13:45:20CEST Nastasa, Elena (uidt4846) 
Update SDA Library files
Revision 1.3 2019/04/10 07:45:49CEST Karmann Andreas-Johannes (uidk6640) (uidk6640) 
RO-9740446:1:AnKa: preload libraries: solved issues in preloading libraries
Revision 1.2 2018/09/27 12:00:49CEST Ammermueller Martin (uidv5342) (uidv5342) 
Update SwLibs - block s-functions and dll
Revision 1.1 2018/07/24 16:50:39CEST Ammermueller Martin (uidv5342) (uidv5342) 
Initial revision
Member added to project /ES/1T/0C/SDA/SDA_Source/SDA_Toolboxes/ACG/Libraries/Ecmath/Src/3_1_0/project.pj
Revision 1.6 2018/03/06 08:32:46CET Angadi Hampa (uidu8151) (uidu8151) 
RO : 8197610 : MISRA2012 ANSI VERSIONS
Revision 1.5 2015/12/31 11:11:39CET Ganesh Sumangala (uidu8725) (uidu8725) 
reveiw updates
Revision 1.4 2015/12/29 11:08:00CET Ganesh Sumangala (uidu8725) (uidu8725) 
ecmath create ansi version
reveiw updates
Revision 1.2 2015/12/14 07:56:48CET Ganesh Sumangala (uidu8725) (uidu8725) 
RO : 3550598:MATH: Create ANSI version
Initial archive
Revision 1.12 2015/11/18 04:31:33CET Angadi Hampa (uidu8151) (uidu8151) 
RO: 2875029; FS_0G01_TC2XX_MATH_3.0.0; Merge EMS2 and EMS3 math ; After Review
Revision 1.11 2015/11/06 11:44:44CET Angadi Hampa (uidu8151) (uidu8151) 
RO: 2875029; FS_0G01_TC2XX_MATH_3.0.0; Merge EMS2 and EMS3 math ; Lint save & restore
Revision 1.10 2015/11/05 12:11:42CET Angadi Hampa (uidu8151) (uidu8151) 
RO: 2875029 ; Merge EMS2 and EMS3 math ;After UML corrections
Revision 1.9 2015/11/03 10:01:49CET Angadi Hampa (uidu8151) (uidu8151) 
RO: 2875029 ; Merge EMS2 and EMS3 math ; inital checkin
Revision 1.11 2015/11/03 09:54:31CET Angadi Hampa (uidu8151) (uidu8151) 
RO: 2875029 ; Merge EMS2 and EMS3 math ; inital checkin
Revision 1.10 2015/07/20 13:16:21CEST Ganesh Sumangala (uidu8725) (uidu8725) 
RO : 2875029 : FS_0G01_TC2XX_MATH_2.1.0
Update missing functions from EMS2 to EMS3
Revision 1.9 2014/07/24 12:15:18CEST uidu8151 
RO: 1081294 : FS_0G01_TC2XX_MATH_200 : design doc and lint solve
Revision 1.8 2014/02/03 13:43:30CET Angadi Hampa (uidu8151) (uidu8151) 
RO:1024108:FS_0G01_TC2XX_AR_MATH_200: Bug Correction & Lint removal
Revision 1.7 2014/01/30 10:47:33CET Angadi Hampa (uidu8151) (uidu8151) 
Bug Correction & Lint removal
Revision 1.6 2013/08/23 13:04:13CEST Angadi Hampa (uidu8151) (uidu8151) 
for release RO 429653 FS_0G01_TC2XX_MATH_100
Revision 1.5 2013/08/20 09:59:33IST Angadi Hampa (uidu8151) (uidu8151) 
for release RO 429653 FS_0G01_TC2XX_MATH_100
Revision 1.4 2013/08/20 09:29:24IST Angadi Hampa (uidu8151) (uidu8151) 
Member renamed from ecmath.h_code to ecmath_main.h in project /ES/FS/0A/bsw/stdlib/math/pd_tc2xx/i/project.pj.
Revision 1.3 2013/08/09 04:37:07CEST Angadi Hampa (uidu8151) (uidu8151) 
for release RO 429653 FS_0G01_TC2XX_MATH_100
Revision 1.2 2013/08/08 10:37:10IST Angadi Hampa (uidu8151) (uidu8151) 
for release RO 429653 FS_0G01_TC2XX_MATH_100
Revision 1.1 2013/08/05 17:33:54IST Angadi Hampa (uidu8151) (uidu8151) 
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
/* ## Module Header End [8729f0e7-4a03-4ed3-bd70-cf5cd6e82538] */

/*~E*/
#ifndef ECMATH_H
#define ECMATH_H
/*~A*/
/*~+:Import*/
/*~T*/
/* Import                                                                      */
/*~T*/
#include <Std_Types.h>
#include <gtypes.h>
#include <powersar_addon_types.h>//ElNa
/*~T*/
/*~E*/
/*~A*/
/*~+:Lint Save*/
/*lint -save -e715 -e704 -e530 -e529 -e550 -e718 -e746 */
/* 715: parameter value not referenced  (normal when inline-ASM used) */
/* 530: result value not initialized (normal when inline-ASM used) */
/* 704: arithmetic shift right OK in library */
/* 718 & 746 :  Since the __ror & __rol are intrinsic functions,doesn't have extern declarations . */
/*~E*/
/*~A*/
/*~+:Macro Definitions*/
#define SET_MIN(X_VALUE, Y_VALUE)                        if (X_VALUE> (Y_VALUE))    {X_VALUE = (Y_VALUE); }  /**< 291597966 = 0.2715717684432241 * 2^30 */
#define SET_MAX(X_VALUE, Y_VALUE)                        if (X_VALUE < (Y_VALUE))    { X_VALUE = (Y_VALUE); }  /**< ADD MACROS */
#define MIN(A,B)                                         (((A)<(B))?(A):(B)) 
#define MAX(A,B)                                         (((A)>(B))?(A):(B)) 
#define WRITE_MIN(X_VALUE, Y_VALUE)                      if (X_VALUE> (Y_VALUE))    {X_VALUE = (Y_VALUE); }  /**< 291597966 = 0.2715717684432241 * 2^30 */
#define WRITE_MAX(X_VALUE, Y_VALUE)                      if (X_VALUE < (Y_VALUE))    { X_VALUE = (Y_VALUE); }  /**< ADD MACROS */

/*~E*/
/*~A*/
/*~+:Macro Operations*/
/* Macro operation name: s8_s16_shr3 */
/** This operation shall convert an sint16 value to an sint8 value, adapting the range of values (shift 3 bits to the right) with overflow and underflow limitation

@param x Value to be shifted to right
Range:      8000(H)......7FFF(H)
          -32768.....32767 */
/* ## Macro operation start [8334c003-a38a-4f38-9f39-bec7116f5f4a] */
#define s8_s16_shr3(x)  s8_s16((x)>>3)
/* ## Macro operation end [8334c003-a38a-4f38-9f39-bec7116f5f4a] */

/* Macro operation name: s16_s16_shl2 */
/** This operation shall adapt the range of values of sint16 (shift 2 bits to the left) with overflow and underflow limitation

@param x Value to be shifted to left

Range:      8000(H)......7FFF(H)
          -32768.....32767 */
/* ## Macro operation start [1851a530-253f-48da-92a4-c4d7e2c080a5] */
#define s16_s16_shl2(x)  s16_exp2_s16_u8((x),2)
/* ## Macro operation end [1851a530-253f-48da-92a4-c4d7e2c080a5] */

/* Macro operation name: s16_s16_shl3 */
/** This operation shall adapt the range of values of sint16 (shift 3 bits to the left) with overflow and underflow limitation

@param x Value of to be shifted left

Range:      8000(H)......7FFF(H)
          -32768.....32767 */
/* ## Macro operation start [97c35a7b-daed-4d38-8526-fe72e4e407b7] */
#define s16_s16_shl3(x)  s16_exp2_s16_u8((x),3)
/* ## Macro operation end [97c35a7b-daed-4d38-8526-fe72e4e407b7] */

/* Macro operation name: s16_s16_shl4 */
/** This operation shall adapt the range of values of sint16 (shift 4 bits to the left) with overflow and underflow limitation

@param x Value to be shifted left

Range:      8000(H)......7FFF(H)
          -32768.....32767 */
/* ## Macro operation start [d0ffca6c-e217-431b-b2d2-8d8d225ea16b] */
#define s16_s16_shl4(x)  s16_exp2_s16_u8((x),4)
/* ## Macro operation end [d0ffca6c-e217-431b-b2d2-8d8d225ea16b] */

/* Macro operation name: u8_s16_shr2 */
/** This operation shall convert an sint16 value to an uint8 value, adapting the range of values (shift 2 bits to the right) with overflow and underflow limitation

@param x Value to be shifted right

Range:      8000(H)......7FFF(H)
          -32768.....32767 */
/* ## Macro operation start [11e3c54d-7957-42b1-851e-0e741b1cd674] */
#define u8_s16_shr2(x)  u8_s16((x)>>2)
/* ## Macro operation end [11e3c54d-7957-42b1-851e-0e741b1cd674] */

/* Macro operation name: u8_u16_shr4 */
/** This operation shall convert an uint16 value to an uint8 value, adapting the range of values (shift 4 bits to the right) with overflow limitation

@param x value to be right shifted

Range:      00(H)........FFFF(H)
            0.......65535 */
/* ## Macro operation start [a991283b-0e6e-4801-8d3a-5c9298056788] */
#define u8_u16_shr4(x)  u8_u16((x)>>4)
/* ## Macro operation end [a991283b-0e6e-4801-8d3a-5c9298056788] */

/* Macro operation name: u8_s16_shr4 */
/** This operation shall convert an sint16 value to an uint8 value, adapting the range of values (shift 2 bits to the right) with overflow and underflow limitation

@param x Value to be shifted right

Range:      8000(H)......7FFF(H)
          -32768.....32767 */
/* ## Macro operation start [9e842fca-60c2-4d3d-bb94-6d94f18fd1ac] */
#define u8_s16_shr4(x)  u8_s16((x)>>4)
/* ## Macro operation end [9e842fca-60c2-4d3d-bb94-6d94f18fd1ac] */

/* Macro operation name: u16_s16_shl2 */
/** This operation shall convert an sint16 value to an uint16 value, adapting the range of values (shift 2 bits to the left) with overflow and underflow limitation

@param x Value to be left shifted

Range:      8000(H)......7FFF(H)
          -32768.....32767 */
/* ## Macro operation start [27c8544d-4951-447b-8062-7c59495ce790] */
#define u16_s16_shl2(x)  u16_s32((sint32)(x)<<2)
/* ## Macro operation end [27c8544d-4951-447b-8062-7c59495ce790] */

/* Macro operation name: u16_s16_shl6 */
/** This operation shall convert an sint16 value to an uint16 value, adapting the range of values (shift 6 bits to the left) with overflow and underflow limitation

@param x Value to be left shifted

Range:      8000(H)......7FFF(H)
          -32768.....32767 */
/* ## Macro operation start [71164aa3-46cf-47c1-9859-a8fabb2375a4] */
#define u16_s16_shl6(x)  u16_s32((sint32)(x)<<6)
/* ## Macro operation end [71164aa3-46cf-47c1-9859-a8fabb2375a4] */

/* Macro operation name: s16_s16_shl6 */
/** This operation shall shift an sint16 value left by 6 bits with overflow and underflow limitation

@param x Value to be shifted

Range:      8000(H)......7FFF(H)
          -32768.....32767
@return value << 6 
Limit overflow to:   0x7FFF
Limit underflow to: 0x8000

Range:      8000(H)......7FFF(H)
          -32768.....32767 */
/* ## Macro operation start [d9d6c353-95a9-48b2-8a54-2abd47e30a56] */
#define s16_s16_shl6(x)  s16_exp2_s16_u8((x),6)
/* ## Macro operation end [d9d6c353-95a9-48b2-8a54-2abd47e30a56] */

/* Macro operation name: s8_mul_s8_u8_fac0125 */
/** This operation shall multiply a value of type sint8 by a factor of 0...0.1245 (shift 11 bits to the right)

@param value Value

Range:      80(H)...... 7F(H)
          -128......127
@param factor Factor to be multiplied

Range:      00(H)...... FF(H)
          0......0.1245 */
/* ## Macro operation start [38153b3b-1a30-4ef9-882d-e5b4f5f457ab] */
#define s8_mul_s8_u8_fac0125(value, factor)  root_s8_mul_s8_u8_fac_less1(value,(uint16)((uint16)(factor) <<5))
/* ## Macro operation end [38153b3b-1a30-4ef9-882d-e5b4f5f457ab] */

/* Macro operation name: s8_mul_s8_u8_fac025 */
/** This operation shall multiply a value of type sint8 by a factor of 0...0.249 (shift 10 bits to the right)

@param value Value

Range:      80(H)...... 7F(H)
          -128......127
@param factor Factor to be multiplied

Range:      00(H)...... FF(H)
           0......0.249 */
/* ## Macro operation start [e99bac27-9245-431f-8676-8e82ffbfa489] */
#define s8_mul_s8_u8_fac025(value, factor)  root_s8_mul_s8_u8_fac_less1(value,(uint16)((uint16)(factor) <<6))
/* ## Macro operation end [e99bac27-9245-431f-8676-8e82ffbfa489] */

/* Macro operation name: s8_mul_s8_u8_fac05 */
/** This operation shall multiply a value of type sint8 by a factor of 0...0.498 (shift 9 bits to the right)

@param value Value

Range:      80(H)...... 7F(H)
          -128......127
@param factor Factor to be multiplied

Range:      00(H)...... FF(H)
           0......0.498 */
/* ## Macro operation start [d9b1c383-0498-4d2d-ac67-240b9b8d2c55] */
#define s8_mul_s8_u8_fac05(value, factor)  root_s8_mul_s8_u8_fac_less1(value,(uint16)((uint16)(factor) <<7))
/* ## Macro operation end [d9b1c383-0498-4d2d-ac67-240b9b8d2c55] */

/* Macro operation name: s8_mul_s8_u8_fac4 */
/** This operation shall multiply a value of type sint8 by a factor of 0...3.984 (shift 6 bits to the right)

@param value Value

Range:      80(H)...... 7F(H)
          -128......127
@param factor Factor to be multiplied

Range:      00(H)...... FF(H)
           0......3.984 */
/* ## Macro operation start [c8e188cd-76a0-4090-a1f6-e668e356d311] */
#define s8_mul_s8_u8_fac4(value, factor)  root_s8_mul_s8_u8_fac_greater1(value,(uint16)((uint16)(factor) <<2))
/* ## Macro operation end [c8e188cd-76a0-4090-a1f6-e668e356d311] */

/* Macro operation name: s8_mul_s8_u8_fac8 */
/** This operation shall multiply a value of type sint8 by a factor of 0...7.969 (shift 5 bits to the right)

@param value Value

Range:      80(H)...... 7F(H)
          -128......127
@param factor Factor to be multiplied

Range:      00(H)...... FF(H)
           0......7.969 */
/* ## Macro operation start [253cd070-a172-4a24-825c-c36ab369cb2d] */
#define s8_mul_s8_u8_fac8(value, factor)  root_s8_mul_s8_u8_fac_greater1(value,(uint16)((uint16)(factor) <<3))
/* ## Macro operation end [253cd070-a172-4a24-825c-c36ab369cb2d] */

/* Macro operation name: s8_mul_s8_u8_fac16 */
/** This operation shall multiply a value of type sint8 by a factor of 0...15.9375 (shift 4 bits to the right)

@param value Value

Range:      80(H)...... 7F(H)
          -128......127
@param factor Factor to be multiplied

Range:      00(H)...... FF(H)
          0......15.9375 */
/* ## Macro operation start [21d71683-04ac-470f-8349-f4b3ee209182] */
#define s8_mul_s8_u8_fac16(value, factor)  root_s8_mul_s8_u8_fac_greater1(value,(uint16)((uint16)(factor) <<4))
/* ## Macro operation end [21d71683-04ac-470f-8349-f4b3ee209182] */

/* Macro operation name: s8_mul_s8_u8_fac32 */
/** This operation shall multiply a value of type sint8 by a factor of 0...31.875 (shift 3 bits to the right)

@param value Value

Range:      80(H)...... 7F(H)
          -128......127
@param factor Factor to be multiplied

Range:      00(H)...... FF(H)
          0......31.875 */
/* ## Macro operation start [7322eb66-4160-4faf-be87-f0ae966485a4] */
#define s8_mul_s8_u8_fac32(value, factor)  root_s8_mul_s8_u8_fac_greater1(value,(uint16)((uint16)(factor) <<5))
/* ## Macro operation end [7322eb66-4160-4faf-be87-f0ae966485a4] */

/* Macro operation name: s8_mul_s8_u8_fac64 */
/** This operation shall multiply a value of type sint8 by a factor of 0...63.750 (shift 2 bits to the right)

@param value Value

Range:      80(H)...... 7F(H)
          -128......127
@param factor Factor to be multiplied

Range:      00(H)...... FF(H)
          0......63.750 */
/* ## Macro operation start [4d95326d-57bf-43cb-bd3c-f62a7a2fd37d] */
#define s8_mul_s8_u8_fac64(value, factor)  root_s8_mul_s8_u8_fac_greater1(value,(uint16)((uint16)(factor) <<6))
/* ## Macro operation end [4d95326d-57bf-43cb-bd3c-f62a7a2fd37d] */

/* Macro operation name: s8_mul_s8_u8_fac128 */
/** This operation shall multiply a value of type sint8 by a factor of 0...127.50 (shift 1 bit to the right)

@param value Value

Range:      80(H)...... 7F(H)
          -128......127
@param factor Factor to be multiplied

Range:      00(H)...... FF(H)
          0......127.50 */
/* ## Macro operation start [cbf1ac32-b981-4106-b4ab-b73d2d488dc9] */
#define s8_mul_s8_u8_fac128(value, factor)  root_s8_mul_s8_u8_fac_greater1(value,(uint16)((uint16)(factor) <<7))
/* ## Macro operation end [cbf1ac32-b981-4106-b4ab-b73d2d488dc9] */

/* Macro operation name: s16_mul_s16_s16_fac0125 */
/** This operation shall multiply a value of type sint16 by a factor of -0.125...0.124996 (shift 18 bits to the right)

@param value Value

Range:      8000(H)......7FFF(H)
          -32768......32767
@param factor Factor to be multiplied

Range:      8000(H)......7FFF(H)
         -0.125.....0.124996 */
/* ## Macro operation start [983226ae-a4dd-4cf4-9df8-10d5c010c95e] */
#define s16_mul_s16_s16_fac0125(value, factor)  root_s16_mul_s16_s16_fac_less1(value,factor,262144)
/* ## Macro operation end [983226ae-a4dd-4cf4-9df8-10d5c010c95e] */

/* Macro operation name: s16_mul_s16_s16_fac025 */
/** This operation shall multiply a value of type sint16 by a factor of -0.25......0.24999 (shift 17 bits to the right)

@param value Value

Range:      8000(H)......7FFF(H)
          -32768......32767
@param factor Factor to be multiplied

Range:      8000(H)......7FFF(H)
           -0.25.....0.24999 */
/* ## Macro operation start [6e09192b-62b9-4a2a-a52f-6819c61577ac] */
#define s16_mul_s16_s16_fac025(value, factor)  root_s16_mul_s16_s16_fac_less1(value,factor,131072)
/* ## Macro operation end [6e09192b-62b9-4a2a-a52f-6819c61577ac] */

/* Macro operation name: s16_mul_s16_s16_fac05 */
/** This operation shall multiply a value of type sint16 by a factor of -0.5....0.4999923 (shift 16 bits to the right)

@param value Value

Range:      8000(H)......7FFF(H)
          -32768......32767
@param factor Factor to be multiplied

Range:      8000(H)......7FFF(H)
          -0.5.....0.4999923 */
/* ## Macro operation start [1e22d931-2f23-4c22-9cef-69633ae75c9f] */
#define s16_mul_s16_s16_fac05(value, factor)  root_s16_mul_s16_s16_fac_less1(value,factor,65536)
/* ## Macro operation end [1e22d931-2f23-4c22-9cef-69633ae75c9f] */

/* Macro operation name: s16_mul_s16_s16_fac4 */
/** This operation shall multiply a value of type sint16 by a factor of -4.....3.99997 (shift 13 bits to the right) with overflow and underflow limitation

@param value Value

Range:      8000(H)......7FFF(H)
          -32768......32767
@param factor Factor to be multiplied

Range:      8000(H)......7FFF(H)
            -4.......3.99997 */
/* ## Macro operation start [704aa504-3d62-406a-9d83-d2f2239d94b2] */
#define s16_mul_s16_s16_fac4(value, factor)  root_s16_mul_s16_s16_fac_greater1(value,factor,8192)
/* ## Macro operation end [704aa504-3d62-406a-9d83-d2f2239d94b2] */

/* Macro operation name: s16_mul_s16_s16_fac8 */
/** This operation shall multiply a value of type sint16 by a factor of -8......7.99988 (shift 12 bits to the right) with overflow and underflow limitation

@param value Value

Range:      8000(H)......7FFF(H)
          -32768......32767
@param factor Factor to be multiplied

Range:      8000(H)......7FFF(H)
            -8......7.99988 */
/* ## Macro operation start [2a1ca5f0-4579-4125-a250-606f64726dd9] */
#define s16_mul_s16_s16_fac8(value, factor)  root_s16_mul_s16_s16_fac_greater1(value,factor,4096)
/* ## Macro operation end [2a1ca5f0-4579-4125-a250-606f64726dd9] */

/* Macro operation name: s16_mul_s16_s16_fac16 */
/** This operation shall multiply a value of type sint16 by a factor of -16......15.9995 (shift 11 bits to the right) with overflow and underflow limitation

@param value Value

Range:      8000(H)......7FFF(H)
          -32768......32767
@param factor Factor to be multiplied

Range:      8000(H)......7FFF(H)
           -16......15.9995 */
/* ## Macro operation start [9d7c00b1-acd4-4f38-a34d-966934c42403] */
#define s16_mul_s16_s16_fac16(value, factor)  root_s16_mul_s16_s16_fac_greater1(value,factor,2048)
/* ## Macro operation end [9d7c00b1-acd4-4f38-a34d-966934c42403] */

/* Macro operation name: s16_mul_s16_s16_fac32 */
/** This operation shall multiply a value of type sint16 by a factor of -32.....31.999 (shift 10 bits to the right) with overflow and underflow limitation

@param value Value

Range:      8000(H)......7FFF(H)
          -32768......32767
@param factor Factor to be multiplied

Range:      8000(H)......7FFF(H)
            -32.....31.999 */
/* ## Macro operation start [4e5619f7-a6bc-442e-ab6f-604e0d819f6a] */
#define s16_mul_s16_s16_fac32(value, factor)  root_s16_mul_s16_s16_fac_greater1(value,factor,1024)
/* ## Macro operation end [4e5619f7-a6bc-442e-ab6f-604e0d819f6a] */

/* Macro operation name: s16_mul_s16_s16_fac64 */
/** This operation shall multiply a value of type sint16 by a factor of -64.....63.998 (shift 9 bits to the right) with overflow and underflow limitation

@param value Value

Range:      8000(H)......7FFF(H)
          -32768......32767
@param factor Factor to be multiplied

Range:      8000(H)......7FFF(H)
            -64.....63.998 */
/* ## Macro operation start [f1ceb91d-05a2-4e95-a15a-ff11dc672326] */
#define s16_mul_s16_s16_fac64(value, factor)  root_s16_mul_s16_s16_fac_greater1(value,factor,512)
/* ## Macro operation end [f1ceb91d-05a2-4e95-a15a-ff11dc672326] */

/* Macro operation name: s16_mul_s16_s16_fac128 */
/** This operation shall multiply a value of type sint16 by a factor of -128......127.998 (shift 8 bit to the right) with overflow and underflow limitation

@param value Value

Range:      8000(H)......7FFF(H)
          -32768......32767
@param factor Factor to be multiplied

Range:      8000(H)......7FFF(H)
          -128......127.998 */
/* ## Macro operation start [16f95753-d29a-4d87-988b-4a88830c360b] */
#define s16_mul_s16_s16_fac128(value, factor)  root_s16_mul_s16_s16_fac_greater1(value,factor,256)
/* ## Macro operation end [16f95753-d29a-4d87-988b-4a88830c360b] */

/* Macro operation name: s16_mul_s16_s16_fac256 */
/** This operation shall multiply a value of type sint16 by a factor -256......255.99216 (shift 7 bits to the right) with overflow and underflow limitation

@param value Value

Range:      8000(H)......7FFF(H)
          -32768......32767
@param factor Factor to be multiplied

Range:      8000(H)......7FFF(H)
         -256......255.99216 */
/* ## Macro operation start [e2048b42-b345-4751-a1d1-963d44cd74ec] */
#define s16_mul_s16_s16_fac256(value, factor)  root_s16_mul_s16_s16_fac_greater1(value,factor,128)
/* ## Macro operation end [e2048b42-b345-4751-a1d1-963d44cd74ec] */

/* Macro operation name: s16_mul_s16_s16_fac512 */
/** This operation shall multiply a value of type sint16 by a factor of -512......511.992 (shift 6 bits to the right) with overflow and underflow limitation

@param value Value

Range:      8000(H)......7FFF(H)
          -32768......32767
@param factor Factor to be multiplied

Range:      8000(H)......7FFF(H)
          -512......511.992 */
/* ## Macro operation start [399c618a-9044-4f0f-82ae-95d22c66027e] */
#define s16_mul_s16_s16_fac512(value, factor)  root_s16_mul_s16_s16_fac_greater1(value,factor,64)
/* ## Macro operation end [399c618a-9044-4f0f-82ae-95d22c66027e] */

/* Macro operation name: s16_mul_s16_s16_fac1024 */
/** This operation shall multiply a value of type sint16 by a factor of -1024....1023.9686 (shift 5 bits to the right) with overflow and underflow limitation

@param value Value

Range:      8000(H)......7FFF(H)
          -32768......32767
@param factor Factor to be multiplied

Range:      8000(H)......7FFF(H)
         -1024....1023.9686 */
/* ## Macro operation start [5e481659-6766-47fa-878f-fffed1c1344e] */
#define s16_mul_s16_s16_fac1024(value, factor)  root_s16_mul_s16_s16_fac_greater1(value,factor,32)
/* ## Macro operation end [5e481659-6766-47fa-878f-fffed1c1344e] */

/* Macro operation name: s16_mul_s16_s16_fac2048 */
/** This operation shall multiply a value of type sint16 by a factor of -2048.....2047.9373 (shift 4 bits to the right) with overflow and underflow limitation

@param value Value

Range:      8000(H)......7FFF(H)
          -32768......32767
@param factor Factor to be multiplied

Range:      8000(H)......7FFF(H)
        -2048.....2047.9373 */
/* ## Macro operation start [c79b734f-366d-44e5-b150-acac4cdb123e] */
#define s16_mul_s16_s16_fac2048(value, factor)  root_s16_mul_s16_s16_fac_greater1(value,factor,16)
/* ## Macro operation end [c79b734f-366d-44e5-b150-acac4cdb123e] */

/* Macro operation name: s16_mul_s16_s16_fac4096 */
/** This operation shall multiply a value of type sint16 by a factor of -4096 ... 4095.875 (shift 3 bits to the right) with overflow and underflow limitation

@param value Value

Range:      8000(H)......7FFF(H)
          -32768......32767
@param factor Factor to be multiplied

Range:      8000(H)......7FFF(H)
         -4096 ... 4095.875 */
/* ## Macro operation start [4207a458-a626-4c77-83d8-2ff1fd57ab68] */
#define s16_mul_s16_s16_fac4096(value, factor)  root_s16_mul_s16_s16_fac_greater1(value,factor,8)
/* ## Macro operation end [4207a458-a626-4c77-83d8-2ff1fd57ab68] */

/* Macro operation name: s16_mul_s16_u8_fac0125 */
/** This operation shall multiply a value of type sint16 by a factor of 0.....0.1245 (shift 11 bits to the right)

@param value Value

Range:      8000(H)...... 7FFF(H)
          -32768......32767
@param factor Factor to be multiplied

Range:      00(H)...... FF(H)
           0.....0.1245 */
/* ## Macro operation start [671ce789-0cfb-4d35-9244-9b20fa3b10ce] */
#define s16_mul_s16_u8_fac0125(value, factor)  root_s16_mul_s16_u8_fac_less1(value,(uint16)((uint16)(factor) << 5))
/* ## Macro operation end [671ce789-0cfb-4d35-9244-9b20fa3b10ce] */

/* Macro operation name: s16_mul_s16_u8_fac025 */
/** This operation shall multiply a value of type sint16 by a factor of 0.....0.249 (shift 10 bits to the right)

@param value Value

Range:      8000(H)...... 7FFF(H)
          -32768......32767
@param factor Factor to be multiplied

Range:      00(H)...... FF(H)
           0.....0.249 */
/* ## Macro operation start [135031a4-95b0-4a4e-b7f3-d7b6462856ad] */
#define s16_mul_s16_u8_fac025(value, factor)  root_s16_mul_s16_u8_fac_less1(value,(uint16)((uint16)(factor) << 6))
/* ## Macro operation end [135031a4-95b0-4a4e-b7f3-d7b6462856ad] */

/* Macro operation name: s16_mul_s16_u8_fac05 */
/** This operation shall multiply a value of type sint16 by a factor of 0.....0.498 (shift 9 bits to the right)

@param value Value

Range:      8000(H)...... 7FFF(H)
          -32768......32767
@param factor Factor to be multiplied

Range:      00(H)...... FF(H)
           0.....0.498 */
/* ## Macro operation start [a090a155-97ab-4489-806b-47d2aa1803d4] */
#define s16_mul_s16_u8_fac05(value, factor)  root_s16_mul_s16_u8_fac_less1(value,(uint16)((uint16)(factor) << 7))
/* ## Macro operation end [a090a155-97ab-4489-806b-47d2aa1803d4] */

/* Macro operation name: s16_mul_s16_u8_fac4 */
/** This operation shall multiply a value of type sint16 by a factor of 0.....3.984 (shift 6 bits to the right)

@param value Value

Range:      8000(H)...... 7FFF(H)
          -32768......32767
@param factor Factor to be multiplied

Range:      00(H)...... FF(H)
           0.....3.984 */
/* ## Macro operation start [a26f45c1-9238-4b84-abc9-10a22c118467] */
#define s16_mul_s16_u8_fac4(value, factor)  root_s16_mul_s16_u8_fac_greater1(value,(uint16)((uint16)(factor) <<2))
/* ## Macro operation end [a26f45c1-9238-4b84-abc9-10a22c118467] */

/* Macro operation name: s16_mul_s16_u8_fac8 */
/** This operation shall multiply a value of type sint16 by a factor of 0.....7.969 (shift 5 bits to the right)

@param value Value

Range:      8000(H)...... 7FFF(H)
          -32768......32767
@param factor Factor to be multiplied

Range:      00(H)...... FF(H)
           0.....7.969 */
/* ## Macro operation start [1ee17b5e-fb63-45d6-8df2-ee226fad4126] */
#define s16_mul_s16_u8_fac8(value, factor)  root_s16_mul_s16_u8_fac_greater1(value,(uint16)((uint16)(factor) <<3))
/* ## Macro operation end [1ee17b5e-fb63-45d6-8df2-ee226fad4126] */

/* Macro operation name: s16_mul_s16_u8_fac16 */
/** This operation shall multiply a value of type sint16 by a factor of 0.....15.9375 (shift 4 bits to the right)

@param value Value

Range:      8000(H)...... 7FFF(H)
          -32768......32767
@param factor Factor to be multiplied

Range:      00(H)...... FF(H)
          0.....15.9375 */
/* ## Macro operation start [b19d9e39-2cb6-41a0-ab98-7fe87fe8911b] */
#define s16_mul_s16_u8_fac16(value, factor)  root_s16_mul_s16_u8_fac_greater1(value,(uint16)((uint16)(factor) <<4))
/* ## Macro operation end [b19d9e39-2cb6-41a0-ab98-7fe87fe8911b] */

/* Macro operation name: s16_mul_s16_u8_fac32 */
/** This operation shall multiply a value of type sint16 by a factor of 0.....31.875 (shift 3 bits to the right)

@param value Value

Range:      8000(H)...... 7FFF(H)
          -32768......32767
@param factor Factor to be multiplied

Range:      00(H)...... FF(H)
           0.....31.875 */
/* ## Macro operation start [e3700b30-2b5c-42ad-9a6c-a13a1fad7da8] */
#define s16_mul_s16_u8_fac32(value, factor)  root_s16_mul_s16_u8_fac_greater1(value,(uint16)((uint16)(factor) <<5))
/* ## Macro operation end [e3700b30-2b5c-42ad-9a6c-a13a1fad7da8] */

/* Macro operation name: s16_mul_s16_u8_fac64 */
/** This operation shall multiply a value of type sint16 by a factor of 0.....63.750 (shift 2 bits to the right)

@param value Value

Range:      8000(H)...... 7FFF(H)
          -32768......32767
@param factor Factor to be multiplied

Range:      00(H)...... FF(H)
           0.....63.750 */
/* ## Macro operation start [08f7ea9f-70a5-47d2-b0b4-99ca0d361ae4] */
#define s16_mul_s16_u8_fac64(value, factor)  root_s16_mul_s16_u8_fac_greater1(value,(uint16)((uint16)(factor) <<6))
/* ## Macro operation end [08f7ea9f-70a5-47d2-b0b4-99ca0d361ae4] */

/* Macro operation name: s16_mul_s16_u8_fac128 */
/** This operation shall multiply a value of type sint16 by a factor of 0.....127.5 (shift 1 bit to the right)

@param value Value

Range:      8000(H)...... 7FFF(H)
          -32768......32767
@param factor Factor to be multiplied

Range:      00(H)...... FF(H)
           0.....127.5 */
/* ## Macro operation start [b1da828a-0f16-46eb-b05d-087102631e47] */
#define s16_mul_s16_u8_fac128(value, factor)  root_s16_mul_s16_u8_fac_greater1(value,(uint16)((uint16)(factor) <<7))
/* ## Macro operation end [b1da828a-0f16-46eb-b05d-087102631e47] */

/* Macro operation name: s16_mul_s16_u16_fac0125 */
/** This operation shall multiply a value of type sint16 by a factor of 0.....0.124998 (shift 19 bits to the right)

@param value Value

Range:      8000(H)......7FFF(H)
          -32768......32767
@param factor Factor to be multiplied

Range:      00(H)......FFFF(H)
           0.....0.124998 */
/* ## Macro operation start [534d5172-f887-4fb0-8541-81de2d68b853] */
#define s16_mul_s16_u16_fac0125(value, factor)  root_s16_mul_s16_u16_fac_less1(value,factor,524288)
/* ## Macro operation end [534d5172-f887-4fb0-8541-81de2d68b853] */

/* Macro operation name: s16_mul_s16_u16_fac025 */
/** This operation shall multiply a value of type sint16 by a factor of 0.....0.249996 (shift 18 bits to the right)

@param value Value

Range:      8000(H)......7FFF(H)
          -32768......32767
@param factor Factor to be multiplied

Range:      00(H)......FFFF(H)
           0.....0.249996 */
/* ## Macro operation start [4c9430c5-dba3-45ff-8d8f-c909df8d7cd9] */
#define s16_mul_s16_u16_fac025(value, factor)  root_s16_mul_s16_u16_fac_less1(value,factor,262144)
/* ## Macro operation end [4c9430c5-dba3-45ff-8d8f-c909df8d7cd9] */

/* Macro operation name: s16_mul_s16_u16_fac05 */
/** This operation shall multiply a value of type sint16 by a factor of 0.....0.49999 (shift 17 bits to the right)

@param value Value

Range:      8000(H)......7FFF(H)
          -32768......32767
@param factor Factor to be multiplied

Range:      00(H)......FFFF(H)
           0.....0.49999 */
/* ## Macro operation start [c13c44ea-6906-461f-8929-6a56d6352f70] */
#define s16_mul_s16_u16_fac05(value, factor)  root_s16_mul_s16_u16_fac_less1(value,factor,131072)
/* ## Macro operation end [c13c44ea-6906-461f-8929-6a56d6352f70] */

/* Macro operation name: s16_mul_s16_u16_fac4 */
/** This operation shall multiply a value of type sint16 by a factor of 0.....3.999939 (shift 14 bits to the right) with overflow and underflow limitation

@param value Value

Range:      8000(H)......7FFF(H)
          -32768......32767
@param factor Factor to be multiplied

Range:      00(H)......FFFF(H)
           0.....3.999939 */
/* ## Macro operation start [1fa9cb1f-a6bc-4268-baea-cdc541c0a4bf] */
#define s16_mul_s16_u16_fac4(value, factor)  root_s16_mul_s16_u16_fac_greater1(value,factor,16384)
/* ## Macro operation end [1fa9cb1f-a6bc-4268-baea-cdc541c0a4bf] */

/* Macro operation name: s16_mul_s16_u16_fac8 */
/** This operation shall multiply a value of type sint16 by a factor of 0.....7.99987 (shift 13 bits to the right) with overflow and underflow limitation

@param value Value

Range:      8000(H)......7FFF(H)
          -32768......32767
@param factor Factor to be multiplied

Range:      00(H)......FFFF(H)
           0.....7.99987 */
/* ## Macro operation start [2e78c150-b6b0-410a-babb-34e4b61286e5] */
#define s16_mul_s16_u16_fac8(value, factor)  root_s16_mul_s16_u16_fac_greater1(value,factor,8192)
/* ## Macro operation end [2e78c150-b6b0-410a-babb-34e4b61286e5] */

/* Macro operation name: s16_mul_s16_u16_fac16 */
/** This operation shall multiply a value of type sint16 by a factor of 0.....15.999756 (shift 12 bits to the right) with overflow and underflow limitation

@param value Value

Range:      8000(H)......7FFF(H)
          -32768......32767
@param factor Factor to be multiplied

Range:      00(H)......FFFF(H)
          0.....15.999756 */
/* ## Macro operation start [54c9ea18-de00-4513-9716-59ccb234c5cd] */
#define s16_mul_s16_u16_fac16(value, factor)  root_s16_mul_s16_u16_fac_greater1(value,factor,4096)
/* ## Macro operation end [54c9ea18-de00-4513-9716-59ccb234c5cd] */

/* Macro operation name: s16_mul_s16_u16_fac32 */
/** This operation shall multiply a value of type sint16 by a factor of 0.....31.99951 (shift 11 bits to the right) with overflow and underflow limitation

@param value Value

Range:      8000(H)......7FFF(H)
          -32768......32767
@param factor Factor to be multiplied

Range:      00(H)......FFFF(H)
           0.....31.99951 */
/* ## Macro operation start [a712f3ca-1eb7-401d-b932-bc6be5190ae2] */
#define s16_mul_s16_u16_fac32(value, factor)  root_s16_mul_s16_u16_fac_greater1(value,factor,2048)
/* ## Macro operation end [a712f3ca-1eb7-401d-b932-bc6be5190ae2] */

/* Macro operation name: s16_mul_s16_u16_fac64 */
/** This operation shall multiply a value of type sint16 by a factor of 0.....63.999023 (shift 10 bits to the right) with overflow and underflow limitation

@param value Value

Range:      8000(H)......7FFF(H)
          -32768......32767
@param factor Factor to be multiplied

Range:      00(H)......FFFF(H)
           0.....63.999023 */
/* ## Macro operation start [978b4bdc-ad58-4b73-bb97-a3635f3f97fd] */
#define s16_mul_s16_u16_fac64(value, factor)  root_s16_mul_s16_u16_fac_greater1(value,factor,1024)
/* ## Macro operation end [978b4bdc-ad58-4b73-bb97-a3635f3f97fd] */

/* Macro operation name: s16_mul_s16_u16_fac128 */
/** This operation shall multiply a value of type sint16 by a factor of 0.....127.99808 (shift 9 bits to the right) with overflow and underflow limitation

@param value Value

Range:      8000(H)......7FFF(H)
          -32768......32767
@param factor Factor to be multiplied

Range:      00(H)......FFFF(H)
          0.....127.99808 */
/* ## Macro operation start [39e69958-3fa5-41fa-bbe9-892cb3b5e0fa] */
#define s16_mul_s16_u16_fac128(value, factor)  root_s16_mul_s16_u16_fac_greater1(value,factor,512)
/* ## Macro operation end [39e69958-3fa5-41fa-bbe9-892cb3b5e0fa] */

/* Macro operation name: s16_mul_s16_u16_fac256 */
/** This operation shall multiply a value of type sint16 by a factor of 0.....255.99616 (shift 8 bits to the right) with overflow and underflow limitation

@param value Value

Range:      8000(H)......7FFF(H)
          -32768......32767
@param factor Factor to be multiplied

Range:      00(H)......FFFF(H)
          0.....255.99616 */
/* ## Macro operation start [1c5dfc3b-42ce-4480-9389-14a353c3cea7] */
#define s16_mul_s16_u16_fac256(value, factor)  root_s16_mul_s16_u16_fac_greater1(value,factor,256)
/* ## Macro operation end [1c5dfc3b-42ce-4480-9389-14a353c3cea7] */

/* Macro operation name: s16_mul_s16_u16_fac512 */
/** This operation shall multiply a value of type sint16 by a factor of 0.....511.99232 (shift 7 bits to the right) with overflow and underflow limitation

@param value Value

Range:      8000(H)......7FFF(H)
          -32768......32767
@param factor Factor to be multiplied

Range:      00(H)......FFFF(H)
          0.....511.99232 */
/* ## Macro operation start [68a3e760-9c43-472d-bf2a-edcc42468b93] */
#define s16_mul_s16_u16_fac512(value, factor)  root_s16_mul_s16_u16_fac_greater1(value,factor,128)
/* ## Macro operation end [68a3e760-9c43-472d-bf2a-edcc42468b93] */

/* Macro operation name: s16_mul_s16_u16_fac1024 */
/** This operation shall multiply a value of type sint16 by a factor of 0.....1023.9846 (shift 6 bits to the right) with overflow and underflow limitation

@param value Value

Range:      8000(H)......7FFF(H)
          -32768......32767
@param factor Factor to be multiplied

Range:      00(H)......FFFF(H)
          0.....1023.9846 */
/* ## Macro operation start [c1ca27fc-8e42-441e-aacd-3c6b599e66d5] */
#define s16_mul_s16_u16_fac1024(value, factor)  root_s16_mul_s16_u16_fac_greater1(value,factor,64)
/* ## Macro operation end [c1ca27fc-8e42-441e-aacd-3c6b599e66d5] */

/* Macro operation name: s16_mul_s16_u16_fac2048 */
/** This operation shall multiply a value of type sint16 by a factor of 0.....2047.9693 (shift 5 bits to the right) with overflow and underflow limitation

@param value Value

Range:      8000(H)......7FFF(H)
          -32768......32767
@param factor Factor to be multiplied

Range:      00(H)......FFFF(H)
          0.....2047.9693 */
/* ## Macro operation start [cda702f8-9b1c-45b8-914c-0946e89f1184] */
#define s16_mul_s16_u16_fac2048(value, factor)  root_s16_mul_s16_u16_fac_greater1(value,factor,32)
/* ## Macro operation end [cda702f8-9b1c-45b8-914c-0946e89f1184] */

/* Macro operation name: s16_mul_s16_u16_fac4096 */
/** This operation shall multiply a value of type sint16 by a factor of 0.....4095.9386 (shift 4 bits to the right) with overflow and underflow limitation

@param value Value

Range:      8000(H)......7FFF(H)
          -32768......32767
@param factor Factor to be multiplied

Range:      00(H)......FFFF(H)
          0.....4095.9386 */
/* ## Macro operation start [334f790d-480c-4de2-85ee-ff507fdcf3b6] */
#define s16_mul_s16_u16_fac4096(value, factor)  root_s16_mul_s16_u16_fac_greater1(value,factor,16)
/* ## Macro operation end [334f790d-480c-4de2-85ee-ff507fdcf3b6] */

/* Macro operation name: u8_mul_u8_u8_fac0125 */
/** This operation shall multiply a value of type uint8 by a factor of 0.....0.1245 (shift 11 bits to the right)

@param value Value

Range:      00(H)......FF(H)
            0......255
@param factor Factor to be multiplied

Range:      00(H)......FF(H)
          0......0.1245 */
/* ## Macro operation start [edc2ce3c-2e04-44e9-8247-7956b45074b7] */
#define u8_mul_u8_u8_fac0125(value, factor)  root_u8_mul_u8_u8_fac_less1(value,factor,11)
/* ## Macro operation end [edc2ce3c-2e04-44e9-8247-7956b45074b7] */

/* Macro operation name: u8_mul_u8_u8_fac025 */
/** This operation shall multiply a value of type uint8 by a factor of 0.....0.249 (shift 10 bits to the right)

@param value Value

Range:      00(H)......FF(H)
            0......255
@param factor Factor to be multiplied

Range:      00(H)......FF(H)
          0......0.249 */
/* ## Macro operation start [813d22d9-40bf-4a6a-89cd-338fb5942ef8] */
#define u8_mul_u8_u8_fac025(value, factor)  root_u8_mul_u8_u8_fac_less1(value,factor,10)
/* ## Macro operation end [813d22d9-40bf-4a6a-89cd-338fb5942ef8] */

/* Macro operation name: u8_mul_u8_u8_fac05 */
/** This operation shall multiply a value of type uint8 by a factor of 0.....0.498 (shift 9 bits to the right)

@param value Value

Range:      00(H)......FF(H)
            0......255
@param factor Factor to be multiplied

Range:      00(H)......FF(H)
          0......0.498 */
/* ## Macro operation start [b6ab951f-d5aa-4944-97a6-4facac4eaf20] */
#define u8_mul_u8_u8_fac05(value, factor)  root_u8_mul_u8_u8_fac_less1(value,factor,9)
/* ## Macro operation end [b6ab951f-d5aa-4944-97a6-4facac4eaf20] */

/* Macro operation name: u8_mul_u8_u8_fac4 */
/** This operation shall multiply a value of type uint8 by a factor of 0.....3.984 (shift 6 bits to the right) with overflow limitation

@param value Value

Range:      00(H)......FF(H)
            0......255
@param factor Factor to be multiplied

Range:      00(H)......FF(H)
          0......3.984 */
/* ## Macro operation start [183eb22c-d40e-4d1e-bae8-4da28e3bb22c] */
#define u8_mul_u8_u8_fac4(value, factor)  root_u8_mul_u8_u8_fac_greater1(value,factor,64)
/* ## Macro operation end [183eb22c-d40e-4d1e-bae8-4da28e3bb22c] */

/* Macro operation name: u8_mul_u8_u8_fac8 */
/** This operation shall multiply a value of type uint8 by a factor of 0.....7.986 (shift 5 bits to the right) with overflow limitation

@param value Value

Range:      00(H)......FF(H)
            0......255
@param factor Factor to be multiplied

Range:      00(H)......FF(H)
          0......7.986 */
/* ## Macro operation start [dfb02609-b261-4a4a-834e-1cd8e0decf5a] */
#define u8_mul_u8_u8_fac8(value, factor)  root_u8_mul_u8_u8_fac_greater1(value,factor,32)
/* ## Macro operation end [dfb02609-b261-4a4a-834e-1cd8e0decf5a] */

/* Macro operation name: u8_mul_u8_u8_fac16 */
/** This operation shall multiply a value of type uint8 by a factor of 0.....15.936 (shift 4 bits to the right) with overflow limitation

@param value Value

Range:      00(H)......FF(H)
            0......255
@param factor Factor to be multiplied

Range:      00(H)......FF(H)
          0......15.936 */
/* ## Macro operation start [bea51106-ce92-4969-9706-c29979605683] */
#define u8_mul_u8_u8_fac16(value, factor)  root_u8_mul_u8_u8_fac_greater1(value,factor,16)
/* ## Macro operation end [bea51106-ce92-4969-9706-c29979605683] */

/* Macro operation name: u8_mul_u8_u8_fac32 */
/** This operation shall multiply a value of type uint8 by a factor of 0.....31.875 (shift 3 bits to the right) with overflow limitation

@param value Value

Range:      00(H)......FF(H)
            0......255
@param factor Factor to be multiplied

Range:      00(H)......FF(H)
         0......31.872 */
/* ## Macro operation start [ac3a07d0-b40a-47ec-b19a-74849e2469f4] */
#define u8_mul_u8_u8_fac32(value, factor)  root_u8_mul_u8_u8_fac_greater1(value,factor,8)
/* ## Macro operation end [ac3a07d0-b40a-47ec-b19a-74849e2469f4] */

/* Macro operation name: u8_mul_u8_u8_fac64 */
/** This operation shall multiply a value of type uint8 by a factor of 0.....63.75 (shift 2 bits to the right) with overflow limitation

@param value Value

Range:      00(H)......FF(H)
            0......255
@param factor Factor to be multiplied

Range:      00(H)......FF(H)
          0......63.744 */
/* ## Macro operation start [b6974320-045f-4814-82c7-a00b5948c690] */
#define u8_mul_u8_u8_fac64(value, factor)  root_u8_mul_u8_u8_fac_greater1(value,factor,4)
/* ## Macro operation end [b6974320-045f-4814-82c7-a00b5948c690] */

/* Macro operation name: u8_mul_u8_u8_fac128 */
/** This operation shall multiply a value of type uint8 by a factor of 0.....127.5 (shift 1 bit to the right) with overflow limitation

@param value Value

Range:      00(H)......FF(H)
            0......255
@param factor Factor to be multiplied

Range:      00(H)......FF(H)
          0....127.488 */
/* ## Macro operation start [9a237dbe-6bbd-4357-b930-2b79acf3b963] */
#define u8_mul_u8_u8_fac128(value, factor)  root_u8_mul_u8_u8_fac_greater1(value,factor,2)
/* ## Macro operation end [9a237dbe-6bbd-4357-b930-2b79acf3b963] */

/* Macro operation name: u16_mul_u16_u8_fac0125 */
/** This operation shall multiply a value of type uint16 by a factor of 0.....0.1245 (shift 11 bits to the right)

@param value Value

Range:      00(H)......FFFF(H)
            0......65535
@param factor Factor to be multiplied

Range:      00(H)......FF(H)
           0.....0.1245 */
/* ## Macro operation start [0d507eb9-4dad-4c53-a463-b16f094d0a97] */
#define u16_mul_u16_u8_fac0125(value, factor)  root_u16_mul_u16_u8_fac_less1(value,(uint16)((uint16)(factor)<< 5))
/* ## Macro operation end [0d507eb9-4dad-4c53-a463-b16f094d0a97] */

/* Macro operation name: u16_mul_u16_u8_fac025 */
/** This operation shall multiply a value of type uint16 by a factor of 0.....0.249 (shift 10 bits to the right)

@param value Value

Range:      00(H)......FFFF(H)
            0......65535
@param factor Factor to be multiplied

Range:      00(H)......FF(H)
           0.....0.249 */
/* ## Macro operation start [88782a5d-cffe-4e45-b075-520da56a7371] */
#define u16_mul_u16_u8_fac025(value, factor)  root_u16_mul_u16_u8_fac_less1(value,(uint16)((uint16)(factor)<< 6))
/* ## Macro operation end [88782a5d-cffe-4e45-b075-520da56a7371] */

/* Macro operation name: u16_mul_u16_u8_fac05 */
/** This operation shall multiply a value of type uint16 by a factor of 0.....0.498 (shift 9 bits to the right)

@param value Value

Range:      00(H)......FFFF(H)
            0......65535
@param factor Factor to be multiplied

Range:      00(H)......FF(H)
           0.....0.498 */
/* ## Macro operation start [446f9e78-4987-4e38-bcd8-b5076b2870a9] */
#define u16_mul_u16_u8_fac05(value, factor)  root_u16_mul_u16_u8_fac_less1(value,(uint16)((uint16)(factor)<< 7))
/* ## Macro operation end [446f9e78-4987-4e38-bcd8-b5076b2870a9] */

/* Macro operation name: u16_mul_u16_u8_fac4 */
/** This operation shall multiply a value of type uint16 by a factor of 0.....3.998 (shift 6 bits to the right)

@param value Value

Range:      00(H)......FFFF(H)
            0......65535
@param factor Factor to be multiplied

Range:      00(H)......FF(H)
           0.....3.998 */
/* ## Macro operation start [f0c976cd-33e4-4200-8db5-397c2a7f5f43] */
#define u16_mul_u16_u8_fac4(value, factor)  root_u16_mul_u16_u8_fac_greater_1(value,(uint16)((uint16)(factor) << 2))
/* ## Macro operation end [f0c976cd-33e4-4200-8db5-397c2a7f5f43] */

/* Macro operation name: u16_mul_u16_u8_fac8 */
/** This operation shall multiply a value of type uint16 by a factor of 0.....7.968 (shift 5 bits to the right)

@param value Value

Range:      00(H)......FFFF(H)
            0......65535
@param factor Factor to be multiplied

Range:      00(H)......FF(H)
           0.....7.968 */
/* ## Macro operation start [0bd15275-f243-47a7-996d-ec542d00fb64] */
#define u16_mul_u16_u8_fac8(value, factor)  root_u16_mul_u16_u8_fac_greater_1(value,(uint16)((uint16)(factor) << 3))
/* ## Macro operation end [0bd15275-f243-47a7-996d-ec542d00fb64] */

/* Macro operation name: u16_mul_u16_u8_fac16 */
/** This operation shall multiply a value of type uint16 by a factor of 0.....15.9375 (shift 4 bits to the right)

@param value Value

Range:      00(H)......FFFF(H)
            0......65535
@param factor Factor to be multiplied

Range:      00(H)......FF(H)
          0.....15.9375 */
/* ## Macro operation start [f5657ad2-793d-4307-a9f7-0bdbd151e899] */
#define u16_mul_u16_u8_fac16(value, factor)  root_u16_mul_u16_u8_fac_greater_1(value,(uint16)((uint16)(factor) << 4))
/* ## Macro operation end [f5657ad2-793d-4307-a9f7-0bdbd151e899] */

/* Macro operation name: u16_mul_u16_u8_fac32 */
/** This operation shall multiply a value of type uint16 by a factor of 0.....31.872 (shift 3 bits to the right)

@param value Value

Range:      00(H)......FFFF(H)
            0......65535
@param factor Factor to be multiplied

Range:      00(H)......FF(H)
           0.....31.872 */
/* ## Macro operation start [f706f6db-9c41-402f-bde1-649e4fc42fb8] */
#define u16_mul_u16_u8_fac32(value, factor)  root_u16_mul_u16_u8_fac_greater_1(value,(uint16)((uint16)(factor) << 5))
/* ## Macro operation end [f706f6db-9c41-402f-bde1-649e4fc42fb8] */

/* Macro operation name: u16_mul_u16_u8_fac64 */
/** This operation shall multiply a value of type uint16 by a factor of 0.....63.744 (shift 2 bits to the right)

@param value Value

Range:      00(H)......FFFF(H)
            0......65535
@param factor Factor to be multiplied

Range:      00(H)......FF(H)
           0.....63.744 */
/* ## Macro operation start [3b33c287-bb1e-402d-83d1-4d46c1c2f7e3] */
#define u16_mul_u16_u8_fac64(value, factor)  root_u16_mul_u16_u8_fac_greater_1(value,(uint16)((uint16)(factor) << 6))
/* ## Macro operation end [3b33c287-bb1e-402d-83d1-4d46c1c2f7e3] */

/* Macro operation name: u16_mul_u16_u8_fac128 */
/** This operation shall multiply a value of type uint16 by a factor of 0.....127.488 (shift 1 bit to the right)

@param value Value

Range:      00(H)......FFFF(H)
            0......65535
@param factor Factor to be multiplied

Range:      00(H)......FF(H)
          0.....127.488 */
/* ## Macro operation start [c4e0d9fa-dc90-466b-9b13-310d3afaf512] */
#define u16_mul_u16_u8_fac128(value, factor)  root_u16_mul_u16_u8_fac_greater_1(value,(uint16)((uint16)(factor) << 7))
/* ## Macro operation end [c4e0d9fa-dc90-466b-9b13-310d3afaf512] */

/* Macro operation name: u16_mul_u16_u16_fac0125 */
/** This operation shall multiply a value of type uint16 by a factor of 0.....0.124998125 (shift 19 bits to the right)

@param value Value

Range:      00(H)......FFFF(H)
            0......65535
@param factor Factor to be multiplied

Range:      00(H)......FFFF(H)
          0...0.124998125 */
/* ## Macro operation start [5a2a3cff-f314-4c2a-a8fd-c6e1daae9431] */
#define u16_mul_u16_u16_fac0125(value, factor)  root_u16_mul_u16_u16_fac_less1(value,factor,19)
/* ## Macro operation end [5a2a3cff-f314-4c2a-a8fd-c6e1daae9431] */

/* Macro operation name: u16_mul_u16_u16_fac025 */
/** This operation shall multiply a value of type uint16 by a factor of 0.....0.24999625 (shift 18 bits to the right)

@param value Value

Range:      00(H)......FFFF(H)
            0......65535
@param factor Factor to be multiplied

Range:      00(H)......FFFF(H)
          0...0.24999625 */
/* ## Macro operation start [76991c87-37e2-41fa-ade0-27f87ad305de] */
#define u16_mul_u16_u16_fac025(value, factor)  root_u16_mul_u16_u16_fac_less1(value,factor,18)
/* ## Macro operation end [76991c87-37e2-41fa-ade0-27f87ad305de] */

/* Macro operation name: u16_mul_u16_u16_fac05 */
/** This operation shall multiply a value of type uint16 by a factor of 0.....0.4999925 (shift 17 bits to the right)

@param value Value

Range:      00(H)......FFFF(H)
            0......65535
@param factor Factor to be multiplied

Range:      00(H)......FFFF(H)
           0...0.4999925 */
/* ## Macro operation start [776d321c-6b6a-40fe-9d77-0361290737c6] */
#define u16_mul_u16_u16_fac05(value, factor)  root_u16_mul_u16_u16_fac_less1(value,factor,17)
/* ## Macro operation end [776d321c-6b6a-40fe-9d77-0361290737c6] */

/* Macro operation name: u16_mul_u16_u16_fac4 */
/** This operation shall multiply a value of type uint16 by a factor of 0.....3.999938965 (shift 14 bits to the right) with overflow limitation

@param value Value

Range:      00(H)......FFFF(H)
            0......65535
@param factor Factor to be multiplied

Range:      00(H)......FFFF(H)
          0...3.999938965 */
/* ## Macro operation start [80198b5c-0baf-4a1e-9dc2-f8b35f1a85be] */
#define u16_mul_u16_u16_fac4(value, factor)  root_u16_mul_u16_u16_fac_greater1(value,factor,16384)
/* ## Macro operation end [80198b5c-0baf-4a1e-9dc2-f8b35f1a85be] */

/* Macro operation name: u16_mul_u16_u16_fac8 */
/** This operation shall multiply a value of type uint16 by a factor of 0.....7.99987793 (shift 13 bits to the right) with overflow limitation

@param value Value

Range:      00(H)......FFFF(H)
            0......65535
@param factor Factor to be multiplied

Range:      00(H)......FFFF(H)
          0.....7.99987793 */
/* ## Macro operation start [25dddc5d-067c-4d45-9087-18c4c6d73137] */
#define u16_mul_u16_u16_fac8(value, factor)  root_u16_mul_u16_u16_fac_greater1(value,factor,8192 )
/* ## Macro operation end [25dddc5d-067c-4d45-9087-18c4c6d73137] */

/* Macro operation name: u16_mul_u16_u16_fac16 */
/** This operation shall multiply a value of type uint16 by a factor of 0.....15.99975586 (shift 12 bits to the right) with overflow limitation

@param value Value

Range:      00(H)......FFFF(H)
            0......65535
@param factor Factor to be multiplied

Range:      00(H)......FFFF(H)
          0...15.99975586 */
/* ## Macro operation start [913d2c78-dd6d-4926-89a4-48cf951f75a3] */
#define u16_mul_u16_u16_fac16(value, factor)  root_u16_mul_u16_u16_fac_greater1(value,factor,4096)
/* ## Macro operation end [913d2c78-dd6d-4926-89a4-48cf951f75a3] */

/* Macro operation name: u16_mul_u16_u16_fac32 */
/** This operation shall multiply a value of type uint16 by a factor of 0.....31.9995 (shift 11 bits to the right) with overflow limitation

@param value Value

Range:      00(H)......FFFF(H)
            0......65535
@param factor Factor to be multiplied

Range:      00(H)......FFFF(H)
           0.....31.9995 */
/* ## Macro operation start [c0b43185-f4ad-4a25-8142-829c75873b36] */
#define u16_mul_u16_u16_fac32(value, factor)  root_u16_mul_u16_u16_fac_greater1(value,factor,2048 )
/* ## Macro operation end [c0b43185-f4ad-4a25-8142-829c75873b36] */

/* Macro operation name: u16_mul_u16_u16_fac64 */
/** This operation shall multiply a value of type uint16 by a factor of 0.....63.999023 (shift 10 bits to the right) with overflow limitation

@param value Value

Range:      00(H)......FFFF(H)
            0......65535
@param factor Factor to be multiplied

Range:      00(H)......FFFF(H)
          0.....63.999023 */
/* ## Macro operation start [26048916-a81d-4017-a542-af98861cca4e] */
#define u16_mul_u16_u16_fac64(value, factor)  root_u16_mul_u16_u16_fac_greater1(value,factor,1024)
/* ## Macro operation end [26048916-a81d-4017-a542-af98861cca4e] */

/* Macro operation name: u16_mul_u16_u16_fac128 */
/** This operation shall multiply a value of type uint16 by a factor of 0.....127.99808 (shift 9 bits to the right) with overflow limitation

@param value Value

Range:      00(H)......FFFF(H)
            0......65535
@param factor Factor to be multiplied

Range:      00(H)......FFFF(H)
          0.....127.99808 */
/* ## Macro operation start [ac7e26ea-1170-4c5b-b47d-f05b397eece0] */
#define u16_mul_u16_u16_fac128(value, factor)  root_u16_mul_u16_u16_fac_greater1(value,factor,512)
/* ## Macro operation end [ac7e26ea-1170-4c5b-b47d-f05b397eece0] */

/* Macro operation name: u16_mul_u16_u16_fac256 */
/** This operation shall multiply a value of type uint16 by a factor of 0.....255.9960938 (shift 8 bits to the right) with overflow limitation

@param value Value

Range:      00(H)......FFFF(H)
            0......65535
@param factor Factor to be multiplied

Range:      00(H)......FFFF(H)
          0...255.9960938 */
/* ## Macro operation start [df7455df-61e8-4d9c-8f26-a1d4e671d911] */
#define u16_mul_u16_u16_fac256(value, factor)  root_u16_mul_u16_u16_fac_greater1(value,factor,256)
/* ## Macro operation end [df7455df-61e8-4d9c-8f26-a1d4e671d911] */

/* Macro operation name: u16_mul_u16_u16_fac512 */
/** This operation shall multiply a value of type uint16 by a factor of 0.....511.992 (shift 7 bits to the right) with overflow limitation

@param value Value

Range:      00(H)......FFFF(H)
            0......65535
@param factor Factor to be multiplied

Range:      00(H)......FFFF(H)
          0......511.992 */
/* ## Macro operation start [bce43773-cf4d-4973-9bbb-55bb386c01b4] */
#define u16_mul_u16_u16_fac512(value, factor)  root_u16_mul_u16_u16_fac_greater1(value,factor,128)
/* ## Macro operation end [bce43773-cf4d-4973-9bbb-55bb386c01b4] */

/* Macro operation name: u16_mul_u16_u16_fac1024 */
/** This operation shall multiply a value of type uint16 by a factor of 0.....1023.98464 (shift 6 bits to the right) with overflow limitation

@param value Value

Range:      00(H)......FFFF(H)
            0......65535
@param factor Factor to be multiplied

Range:      00(H)......FFFF(H)
          0...1023.98464 */
/* ## Macro operation start [ff30b4a3-6d20-4eb4-9854-977a27ad8477] */
#define u16_mul_u16_u16_fac1024(value, factor)  root_u16_mul_u16_u16_fac_greater1(value,factor,64)
/* ## Macro operation end [ff30b4a3-6d20-4eb4-9854-977a27ad8477] */

/* Macro operation name: u16_mul_u16_u16_fac2048 */
/** This operation shall multiply a value of type uint16 by a factor of 0.....2047.96928 (shift 5 bits to the right) with overflow limitation

@param value Value

Range:      00(H)......FFFF(H)
            0......65535
@param factor Factor to be multiplied

Range:      00(H)......FFFF(H)
          0...2047.96928 */
/* ## Macro operation start [9d7553ee-7c47-4092-9308-0bdf757d0b83] */
#define u16_mul_u16_u16_fac2048(value, factor)  root_u16_mul_u16_u16_fac_greater1(value,factor,32)
/* ## Macro operation end [9d7553ee-7c47-4092-9308-0bdf757d0b83] */

/* Macro operation name: u16_mul_u16_u16_fac4096 */
/** This operation shall multiply a value of type uint16 by a factor of 0.....4095.9375 (shift 4 bits to the right) with overflow limitation

@param value Value

Range:      00(H)......FFFF(H)
            0......65535
@param factor Factor to be multiplied

Range:      00(H)......FFFF(H)
          0.....4095.9375 */
/* ## Macro operation start [b65ca5be-5230-4211-bd7e-405f3a047d27] */
#define u16_mul_u16_u16_fac4096(value, factor)  root_u16_mul_u16_u16_fac_greater1(value,factor,16)
/* ## Macro operation end [b65ca5be-5230-4211-bd7e-405f3a047d27] */

/* Macro operation name: u32_mul_u32_u16_fac05 */
/** This operation shall multiply a value of type uint32 by a factor of 0.....0.4999925 (shift 17 bits to the right)

@param value Value

Range:      00(H)......FFFFFFFF(H)
            0......4294967295
@param factor Factor to be multiplied

Range:      00(H)......FFFF(H)
          0....0. 4999925 */
/* ## Macro operation start [c0bde7f6-4913-4886-9d53-c918ec490784] */
#define u32_mul_u32_u16_fac05(value, factor)  root_u32_mul_u32_u32_fac_less1(value,factor,17)
/* ## Macro operation end [c0bde7f6-4913-4886-9d53-c918ec490784] */

/* Macro operation name: u32_mul_u32_s16_fac05 */
/** This operation shall multiply a value of type uint32 by a factor of -0.5.....0.4999925 (shift 16 bits to the right) with underflow limitation

@param value Value

Range:      00(H)......FFFFFFFF(H)
            0......4294967295
@param factor Factor to be multiplied

Range:      8000(H)......7FFF(H)
          -0.5....0.4999925 */
/* ## Macro operation start [42fb398b-696f-4a8d-8caa-f51c5402a514] */
#define u32_mul_u32_s16_fac05(value, factor)  root_u32_mul_u32_s32_fac_less1(value,factor,16)
/* ## Macro operation end [42fb398b-696f-4a8d-8caa-f51c5402a514] */

/* Macro operation name: u32_mul_u32_u32_fac05 */
/** This operation shall multiply a value of type uint32 by a factor of 0.....0.4999925 (shift 33 bits to the right)

@param value Value

Range:      00(H)......FFFFFFFF(H)
            0......4294967295
@param factor Factor to be multiplied

Range:      00(H)......FFFFFFFF(H)
             0.....0.4999925 */
/* ## Macro operation start [83c23c02-404a-4023-8f7e-f4f64b4cb57e] */
#define u32_mul_u32_u32_fac05(value, factor)  root_u32_mul_u32_u32_fac_less1(value,factor,33) 
/* ## Macro operation end [83c23c02-404a-4023-8f7e-f4f64b4cb57e] */

/* Macro operation name: u32_mul_u32_s32_fac05 */
/** This operation shall multiply a value of type uint32 by a factor of -0.5.....0.4999925 (shift 32 bits to the right) with underflow limitation

@param value Value

Range:      00(H)......FFFFFFFF(H)
            0......4294967295
@param factor Factor to be multiplied

Range:      80000000(H)......7FFFFFFF(H)
                -0.5.....0.4999925 */
/* ## Macro operation start [fd323650-7fe0-4175-81e5-9b71c7e0819a] */
#define u32_mul_u32_s32_fac05(value, factor)  root_u32_mul_u32_s32_fac_less1(value,factor,32)
/* ## Macro operation end [fd323650-7fe0-4175-81e5-9b71c7e0819a] */

/* Macro operation name: s32_mul_s32_u16_fac05 */
/** This operation shall multiply a value of type sint32 by a factor of 0.....0.4999925 (shift 17 bits to the right)

@param value Value

Range:      80000000(H)......7FFFFFFF(H)
         -2147483648......2147483647
@param factor Factor to be multiplied

Range:      00(H)......FFFF(H)
          0...0.4999925 */
/* ## Macro operation start [d5dc38b4-d7bb-41f6-b773-9880b4bab245] */
#define s32_mul_s32_u16_fac05(value, factor)  root_s32_mul_s32_u16_fac_less1(value,factor,131072)
/* ## Macro operation end [d5dc38b4-d7bb-41f6-b773-9880b4bab245] */

/* Macro operation name: s32_mul_s32_s16_fac05 */
/** This operation shall multiply a value of type sint32 by a factor of -0.5.....0.4999925 (shift 16 bits to the right)

@param value Value

Range:      80000000(H)......7FFFFFFF(H)
         -2147483648......2147483647
@param factor Factor to be multiplied

Range:      8000(H)......7FFF(H)
           -0.5....0.4999925 */
/* ## Macro operation start [1c54403a-cdc1-4eb1-ae7d-82963efb2cfa] */
#define s32_mul_s32_s16_fac05(value, factor)  root_s32_mul_s32_s16_fac_less1(value,factor,65536)
/* ## Macro operation end [1c54403a-cdc1-4eb1-ae7d-82963efb2cfa] */

/* Macro operation name: u32_mul_u32_u8_fac05 */
/** This operation shall multiply a value of type uint32 by a factor of 0.....0.4980 (shift 9 bits to the right)

@param value Value

Range:      00(H)......FFFFFFFF(H)
            0......4294967295
@param factor Factor to be multiplied

Range:      00(H)......FF(H)
            0....0.4980 */
/* ## Macro operation start [7681fa33-55bb-49b0-bf3b-e00f18258146] */
#define u32_mul_u32_u8_fac05(value, factor)  root_u32_mul_u32_u32_fac_less1(value,factor,9)
/* ## Macro operation end [7681fa33-55bb-49b0-bf3b-e00f18258146] */

/* Macro operation name: u32_mul_u32_s8_fac05 */
/** This operation shall multiply a value of type uint32 by a factor of -0.5.....0.4960 (shift 8 bits to the right) with underflow limitation

@param value Value

Range:      00(H)......FFFFFFFF(H)
            0......4294967295
@param factor Factor to be multiplied

Range:      80(H)......7F(H)
          -0.5...0.4980 */
/* ## Macro operation start [60d95f25-318f-40e4-937b-6090e00bb9d6] */
#define u32_mul_u32_s8_fac05(value, factor)  root_u32_mul_u32_s32_fac_less1(value,factor,8)
/* ## Macro operation end [60d95f25-318f-40e4-937b-6090e00bb9d6] */

/* Macro operation name: s32_mul_s32_u8_fac05 */
/** This operation shall multiply a value of type sint32 by a factor of 0.....0.4980 (shift 9 bits to the right)

@param value Value

Range:      80000000(H)......7FFFFFFF(H)
         -2147483648......2147483647
@param factor Factor to be multiplied

Range:      00(H)......FF(H)
            0....0.4980 */
/* ## Macro operation start [1517efaf-eef3-479b-9376-1aa6812d6d71] */
#define s32_mul_s32_u8_fac05(value, factor)  root_s32_mul_s32_u16_fac_less1(value,factor,512)
/* ## Macro operation end [1517efaf-eef3-479b-9376-1aa6812d6d71] */

/* Macro operation name: s32_mul_s32_s8_fac05 */
/** This operation shall multiply a value of type sint32 by a factor of -0.5.....0.4960 (shift 8 bits to the right)

@param value Value

Range:      80000000(H)......7FFFFFFF(H)
         -2147483648......2147483647
@param factor Factor to be multiplied

Range:      80(H)......7F(H)
         -0.5...0.4960 */
/* ## Macro operation start [30ed5d7b-59c2-430d-a32b-255a09628ed8] */
#define s32_mul_s32_s8_fac05(value, factor)  root_s32_mul_s32_s8_fac_less1(value,factor,256)
/* ## Macro operation end [30ed5d7b-59c2-430d-a32b-255a09628ed8] */

/* Macro operation name: u32_mul_u32_u32_fac_twopow_u8 */
/** This operation shall multiply two uint32 values and then right shift the product by 32 power value with overflow limitation

@param value First parameter

Range:      00(H)    FFFFFFFF(H)
                     0    4294967295
@param factor Second parameter

Range:      00(H)  FFFFFFFF(H)
                     0   4294967295
@param power (32 - power) indicates the number of bits by which the product has to be shifted right

Range:      1(H)...1F(H)
            1...31 */
/* ## Macro operation start [6a0851b2-ec82-4f77-8164-49957dc92cb0] */
#define u32_mul_u32_u32_fac_twopow_u8(value, factor, power)  u32_mul_u32_u32_exp05_u8(value,factor,(uint8)s32_min_max_s32_s32_s32(32-(power),1,31))
/* ## Macro operation end [6a0851b2-ec82-4f77-8164-49957dc92cb0] */

/* Macro operation name: s32_mul_s32_s32_fac_twopow_u8 */
/** This operation shall multiply two sint32 values and then right shift the product by 32power value with overflow and underflow limitation

@param value First parameter

Range:      80000000(H)  7FFFFFFF(H)
         -2147483648  2147483647
@param factor Second parameter

Range:      80000000(H)  7FFFFFFF(H)
         -2147483648   2147483647
@param power (32 - power) indicates the number of bits by which the product has to be shifted right

Range:      1(H)  1F(H)
            1  31 */
/* ## Macro operation start [dbbdd52c-f631-4ce8-b716-ab6f80b10e66] */
#define s32_mul_s32_s32_fac_twopow_u8(value, factor, power)  s32_mul_s32_s32_exp05_u8(value,factor,(uint8)s32_min_max_s32_s32_s32(32-(power),1,31))
/* ## Macro operation end [dbbdd52c-f631-4ce8-b716-ab6f80b10e66] */

/* Macro operation name: u8_mmv_u8_u8_u8_fac1 */
/** This operation shall calculate the new floating average of type uint8 with an uint8 value as old floating average, an uint8 value as actual measured value and an uint8 value (0...0.998) as average value

@param gmw Old floating average

Range:      00(H).....FF(H)
           0......255
@param messwert Actual measured value

Range:      00(H).....FF(H)
           0......255
@param mitko Constant value

Range:      00(H).....FF(H)
            0...0.998 */
/* ## Macro operation start [6d25c948-e747-4889-b28c-24b54434795c] */
#define u8_mmv_u8_u8_u8_fac1(gmw, messwert, mitko)  (uint8)(u16_mmv_u16_u16_u16_fac1(gmw,messwert,(uint16)((uint16)mitko<<8)))
/* ## Macro operation end [6d25c948-e747-4889-b28c-24b54434795c] */

/*~E*/
/*~T*/
/*lint --e{9033} DAT.11, MISRA 10.8: allowed by the C Coding Rules */

/*~A*/
/*~+:Declaration*/
/*~T*/
#include "iopt_memmap.h"
/*~T*/
static inline   sint8 s8_sub_s8_u8(sint8 x_value, uint8 y_value);
static inline   uint16 u16_sub_u16_u16(uint16 x_value, uint16 y_value);
static inline   uint16 u16_abs_sub_u16_u16(uint16 x_value, uint16 y_value);
static inline   uint8 u8_sub_u8_u8(uint8 x_value, uint8 y_value);
static inline   uint8 u8_abs_sub_u8_u8(uint8 x_value, uint8 y_value);
static inline   sint16 s16_sub_u16_u16(uint16 x_value, uint16 y_value);
static inline   sint16 s16_sub_u16_s16(uint16 x_value, sint16 y_value);
static inline   sint16 s16_sub_s16_u16(sint16 x_value, uint16 y_value);
static inline   sint16 s16_sub_s16_s16(sint16 x_value, sint16 y_value);
static inline   sint8 s8_sub_u8_u8(uint8 x_value, uint8 y_value);

static inline   sint16 s16_sub_u16_u16(uint16 x_value, uint16 y_value);
static inline   sint16 s16_sub_u16_s16(uint16 x_value, sint16 y_value);
static inline   sint16 s16_sub_s16_u16(sint16 x_value, uint16 y_value);
static inline   sint16 s16_sub_s16_s16(sint16 x_value, sint16 y_value);

static inline   uint32 u32_exp05_u32_u8(uint32 value, uint8 count);
static inline   sint8 s8_s16(sint16 value);
static inline   sint16 s16_abs_s16(sint16 value);
static inline   uint16 u16_abs_s16(sint16 value);
static inline   uint32 u32_rotl_u32_u16(uint32 value, uint16 count);
static inline   uint32 u32_rotr_u32_u16(uint32 value, uint16 count);
static inline   uint16 u16_exp05_u32_u8(uint32 value, uint8 count);
static inline   sint32 s32_exp05_s32_u8(sint32 value, uint8 count);
static inline   uint16 u16_u32(uint32 value);
static inline   uint16 u16_s16(sint16 value);
static inline   uint8 u8_u16(uint16 value);
static inline   sint16 s16_u16(uint16 value);
static inline   sint16 s16_s32(sint32 value);
static inline   uint8 u8_sub_u8_s8(uint8 x_value, sint8 y_value);
static inline   sint8 s8_sub_s8_s8(sint8 x_value, sint8 y_value);
static inline   sint32 s32_abs_sub_s32_s32(sint32 x_value, sint32 y_value);
static inline   sint32 s32_sub_u32_u32(uint32 x_value, uint32 y_value);
static inline   sint32 s32_sub_s32_u32(sint32 x_value, uint32 y_value);
static inline   sint32 s32_sub_u32_s32(uint32 x_value, sint32 y_value);
static inline   uint32 u32_abs_sub_u32_u32(uint32 x_value, uint32 y_value);
static inline   uint32 u32_sub_s32_s32(sint32 x_value, sint32 y_value);
static inline   uint32 u32_sub_s32_u32(sint32 x_value, uint32 y_value);
static inline   uint32 u32_sub_u32_s32(uint32 x_value, sint32 y_value);
static inline   sint16 s16_sub_u32_u32(uint32 x_value, uint32 y_value);
static inline   sint32 s32_sub_s32_s32(sint32 x_value, sint32 y_value);
static inline   uint16 u16_sub_u16_s16(uint16 x_value, sint16 y_value);
static inline   uint32 u32_sub_u32_u32(uint32 x_value, uint32 y_value);
static inline   uint16 u16_abs_sub_s16_s16(sint16 x_value, sint16 y_value);
static inline   uint16 u16_sub_u32_u32(uint32 x_value, uint32 y_value);
static inline   uint16 u16_sub_u16_u16(uint16 x_value, uint16 y_value);
static inline   uint16 u16_abs_sub_u16_u16(uint16 x_value, uint16 y_value);
static inline   uint8 u8_sub_u8_u8(uint8 x_value, uint8 y_value);
static inline   uint8 u8_abs_sub_u8_u8(uint8 x_value, uint8 y_value);
static inline   sint16 s16_sub_u16_u16(uint16 x_value, uint16 y_value);
static inline   sint16 s16_sub_u16_s16(uint16 x_value, sint16 y_value);
static inline   sint16 s16_sub_s16_u16(sint16 x_value, uint16 y_value);

static inline   sint32 s32_mul_s32_u16_fac1(sint32 value, uint16 factor);
static inline   uint32 u32_mul_u32_s32_fac2(uint32 value, sint32 factor);
static inline   uint32 u32_mul_u32_s32_fac1(uint32 value, sint32 factor);
static inline   uint32 u32_mul_u32_u32_fac2(uint32 value, uint32 factor);
static inline   uint32 u32_mul_u32_u32_fac1(uint32 value, uint32 factor);
static inline   uint32 u32_mul_u32_s16_fac2(uint32 value, sint16 factor);
static inline   uint32 u32_mul_u32_s16_fac1(uint32 value, sint16 factor);
static inline   uint32 u32_mul_u32_u16_fac2(uint32 value, uint16 factor);
static inline   uint32 u32_mul_u32_u16_fac1(uint32 value, uint16 factor);
static inline   sint32 s32_mul_s32_u16_fac1(sint32 value, uint16 factor);
static inline   uint16 u16_mul_u16_u16_fac2(uint16 value, uint16 factor);
static inline   uint16 u16_mul_u16_u16_fac1(uint16 value, uint16 factor);
static inline   uint16 u16_mul_u16_u8_fac2(uint16 x_value, uint8 y_value);
static inline   uint16 u16_mul_u16_u8_fac1(uint16 x_value, uint8 y_value);
static inline   uint8 u8_mul_u8_u8_fac2(uint8 value, uint8 factor);
static inline   uint8 u8_mul_u8_u8_fac1(uint8 value, uint8 factor);
static inline   sint16 s16_mul_s16_u16_fac2(sint16 value, uint16 factor);
static inline   sint16 s16_mul_s16_u16_fac1(sint16 value, uint16 factor);
static inline   sint16 s16_mul_s16_u8_fac2(sint16 value, uint8 factor);
static inline   sint16 s16_mul_s16_u16_fac1(sint16 value, uint16 factor);
static inline   sint16 s16_mul_s16_u8_fac1(sint16 value, uint8 factor);
static inline   sint16 s16_mul_s16_s16_fac2(sint16 value, sint16 factor);
static inline   sint16 s16_mul_s16_s16_fac1(sint16 value, sint16 factor);
static inline   sint8 s8_mul_s8_u8_fac2(sint8 value, uint8 factor);
static inline   sint8 s8_mul_s8_u8_fac1(sint8 value, uint8 factor);
static inline   sint32 s32_s64(sint64 val);
static inline   uint32 u32_s64(sint64 val);
static inline   uint32 u32_u64(uint64 val);
static inline   sint8 s8_sgn_s32(sint32 val);
static inline   sint16 s16_exp05_s32_u8(sint32 value, uint8 shiftright);
static inline   sint32 s32_exp2_s32_u8(sint32 data, uint8 shiftleft);
static inline   uint32 u32_exp2_u32_u8(uint32 data, uint8 shiftleft);
static inline   uint32 u32_mul_u32_u32_exp05_u8(uint32 tmp_1, uint32 tmp_2, uint8 shiftright);
static inline   sint32 s32_mul_s32_u32_exp05_u8(sint32 tmp_1, uint32 tmp_2, uint8 shiftright);
static inline   sint32 s32_mul_s32_s32_exp05_u8(sint32 tmp_1, sint32 tmp_2, uint8 shiftright);
static inline   uint8 u8_u32(uint32 value);
static inline   sint8 s8_s32(sint32 value);
static inline   uint8 u8_exp05_u16_u8(uint16 value, uint8 count);
static inline   sint16 s16_mul_s16_u16_exp05_u8(sint16 val1, uint16 val2, uint8 count);
static inline   uint8 u8_exp05_s16_u8(sint16 value, uint8 count);
static inline   uint16 u16_exp2_s16_u8(sint16 value, uint8 count);
static inline   sint8 s8_exp05_s16_u8(sint16 value, uint8 count);
static inline   sint32 s32_abs_s32(sint32 value);
static inline   sint32 s32_u32(uint32 value);
static inline   uint32 u32_abs_s32(sint32 value);
static inline   uint32 u32_s32(sint32 value);
static inline   sint16 s16_u32(uint32 value);
static inline   sint8 s8_abs_s8(sint8 value);
static inline   sint8 s8_u16(uint16 value);
static inline   sint8 s8_u8(uint8 value);
static inline   uint8 u8_abs_s8(sint8 value);
static inline   uint8 u8_s16(sint16 value);
static inline   uint8 u8_s8(sint8 value);
static inline   sint16 s16_mul_s16_s16_exp05_u8(sint16 x, sint16 y, uint8 count);
static inline   uint16 u16_exp2_u16_u8(uint16 data, uint8 bits);
static inline   sint16 s16_exp2_s16_u8(sint16 data, uint8 bits);
static inline   uint16 u16_s32(sint32 value);
static inline   uint16 u16_mul_u16_u16_exp2_u8(uint16 val1, uint16 val2, uint8 count);
static inline   uint16 u16_mul_u16_u16_exp05_u8(uint16 val1, uint16 val2, uint8 count);
static inline   sint16 s16_mul_s16_u16_exp2_u8(sint16 val1, uint16 val2, uint8 count);


static inline   sint32 s32_mul_s32_s16_fac2(sint32 value, sint16 factor);
static inline   sint32 s32_mul_s32_s16_fac1(sint32 value, sint16 factor);
static inline   sint32 s32_mul_s32_u16_fac2(sint32 value, uint16 factor);

static inline   sint16 s16_limitnew_up_s16_s16_u16(sint16 newval, sint16 oldval, uint16 maxdif);
static inline   uint16 u16_limitnew_u16_u16_u16(uint16 newval, uint16 oldval, uint16 maxdif);
static inline   uint16 u16_limitnew_down_u16_u16_u16(uint16 newval, uint16 oldval, uint16 maxdif);
static inline   uint16 u16_limitnew_up_u16_u16_u16(uint16 newval, uint16 oldval, uint16 maxdif);
static inline   sint16 s16_lim_hys_s16_u16(sint16 input_val, uint16 hysteresis);
static inline   uint16 u16_norm_u16_u16_u16(uint16 bottom_lim, uint16 top_lim, uint16 value);
static inline   sint16 s16_grdlmt20_s16_u16(sint16 grdlmt, uint16 value);
static inline   uint16 u16_min_max_u16_u16_u16(uint16 value, uint16 minimum, uint16 maximum);
static inline   uint8 u8_min_max_u8_u8_u8(uint8 value, uint8 minimum, uint8 maximum);
static inline   sint16 s16_min_max_s16_s16_s16(sint16 value, sint16 minimum, sint16 maximum);
static inline   sint16 s16_min_max_s16_s16(sint16 value, sint16 minmaxwert);
static inline   sint8 s8_min_max_s8_s8_s8(sint8 value, sint8 minimum, sint8 maximum);
static inline   sint8 s8_min_max_s8_s8(sint8 value, sint8 minmaxwert);
static inline   uint8 u8_max_tab_u16p_u8(const uint16 * tab, uint8 tablen);
static inline   sint32 s32_mul_s32_s32(sint32 val1, sint32 val2);
static inline   sint32 s32_mul_u32_s32(uint32 val1, sint32 val2);
static inline   uint32 u32_mul_u32_u32(uint32 val1, uint32 val2);
static inline   uint32 u32_mul_s32_s32(sint32 val1, sint32 val2);
static inline   uint32 u32_mul_u32_s32(uint32 val1, sint32 val2);
static inline   sint32 s32_mul_s16_s16(sint16 val1, sint16 val2);
static inline   uint32 u32_mul_u16_u16(uint16 val1, uint16 val2);
static inline   uint16 u16_mul_u16_u16(uint16 value, uint16 factor);
static inline   uint16 u16_cal1_u16_u16_s8(uint16 x_value, uint16 y_value, sint8 factor);
static inline   uint8 u8_cal1_u8_u8_s8(uint8 x_value, uint8 y_value, sint8 factor);
static inline   uint32 u32_mul_u32_u16(uint32 x_value, uint16 y_value);
static inline   sint32 s32_mul_s32_u16(sint32 value, uint16 factor);
static inline   sint32 s32_mul_s16_u16(sint16 value, uint16 factor);
static inline   sint16 s16_mul_u16_u16_fac256(uint16 value, uint16 factor);
static inline   sint16 s16_mul_s16_u16(sint16 value, uint16 factor);
static inline   sint32 s32_mul_s32_s8_fac2(sint32 value, sint8 factor);
static inline   sint32 s32_mul_s32_s8_fac1(sint32 value, sint8 factor);
static inline   sint32 s32_mul_s32_u8_fac2(sint32 value, uint8 factor);
static inline   sint32 s32_mul_s32_u8_fac1(sint32 value, uint8 factor);
static inline   uint32 u32_mul_u32_s8_fac2(uint32 value, sint8 factor);
static inline   uint32 u32_mul_u32_s8_fac1(uint32 value, sint8 factor);
static inline   uint32 u32_mul_u32_u8_fac2(uint32 value, uint8 factor);
static inline   uint32 u32_mul_u32_u8_fac1(uint32 value, uint8 factor);
static inline   sint32 s32_mul_s32_s32_fac2(sint32 value, sint32 factor);
static inline   sint32 s32_mul_s32_s32_fac1(sint32 value, sint32 factor);
static inline   sint32 s32_mul_s32_s32_fac05(sint32 value, sint32 factor);
static inline   sint32 s32_mul_s32_u32_fac2(sint32 value, uint32 factor);
static inline   sint32 s32_mul_s32_u32_fac1(sint32 value, uint32 factor);
static inline   sint32 s32_mul_s32_u32_fac05(sint32 value, uint32 factor);

static inline   uint8 u8_cntlz_u32_math(uint32 val);
static inline   sint32 root_s32_mul_s32_s8_fac_less1(sint32 value, sint8 factor, uint32 count);
static inline   sint32 root_s32_mul_s32_s16_fac_less1(sint32 value, sint16 factor, uint32 count);
static inline   sint32 root_s32_mul_s32_u16_fac_less1(sint32 value, uint16 factor, uint32 count);
static inline   uint32 root_u32_mul_u32_s32_fac_less1(uint32 value, sint32 factor, uint32 count);
static inline   uint32 root_u32_mul_u32_u32_fac_less1(uint32 value, uint32 factor, uint32 count);
static inline   uint16 root_u16_mul_u16_u16_fac_greater1(uint16 value, uint16 factor, uint16 count);
static inline   uint16 root_u16_mul_u16_u16_fac_less1(uint16 value, uint16 factor, uint32 count);
static inline   uint16 root_u16_mul_u16_u8_fac_greater_1(uint16 value, uint16 factor);
static inline   uint16 root_u16_mul_u16_u8_fac_less1(uint16 value, uint16 factor);
static inline   uint8 root_u8_mul_u8_u8_fac_greater1(uint8 value, uint8 factor, uint8 count);
static inline   uint8 root_u8_mul_u8_u8_fac_less1(uint8 value, uint8 factor, uint16 count);
static inline   sint16 root_s16_mul_s16_u16_fac_greater1(sint16 value, uint16 factor, uint16 count);
static inline   sint16 root_s16_mul_s16_u16_fac_less1(sint16 value, uint16 factor, sint32 count);
static inline   sint16 root_s16_mul_s16_u8_fac_greater1(sint16 value, uint16 factor);
static inline   sint16 root_s16_mul_s16_u8_fac_less1(sint16 value, uint16 factor);
static inline   sint16 root_s16_mul_s16_s16_fac_greater1(sint16 value, sint16 factor, sint16 count);
static inline   sint16 root_s16_mul_s16_s16_fac_less1(sint16 value, sint16 factor, sint32 count);
static inline   sint8 root_s8_mul_s8_u8_fac_greater1(sint8 value, uint16 factor);
static inline   sint8 root_s8_mul_s8_u8_fac_less1(sint8 value, uint16 factor);
static inline   uint32 u32_add_u32_u32_u32(uint32 x_value, uint32 y_value, uint32 z_value);
static inline   sint32 s32_add_u32_s32(uint32 x_value, sint32 y_value);
static inline   uint32 u32_add_s32_s32(sint32 x_value, sint32 y_value);
static inline   uint32 u32_add_u32_s32(uint32 x_value, sint32 y_value);
static inline   sint16 s16_add_s16_s16_s16(sint16 x_value, sint16 y_value, sint16 z_value);
static inline   uint16 u16_add_u16_u16_u16_u16(uint16 w_value, uint16 x_value, uint16 y_value, uint16 z_value);
static inline   uint16 u16_add_u16_u16_u16(uint16 x_value, uint16 y_value, uint16 z_value);
static inline   uint32 u32_add_u32_u32(uint32 x_value, uint32 y_value);
static inline   uint16 u16_add_u16_s16(uint16 x_value, sint16 y_value);
static inline   uint16 u16_add_u16_u16(uint16 x_value, uint16 y_value);
static inline   uint8 u8_add_u8_u8(uint8 x_value, uint8 y_value);
static inline   uint8 u8_add_u8_s8(uint8 x_value, sint8 y_value);
static inline   sint32 s32_add_s32_s32(sint32 x_value, sint32 y_value);
static inline   sint16 s16_add_u16_s16(uint16 x_value, sint16 y_value);
static inline   sint16 s16_add_s16_s16(sint16 x_value, sint16 y_value);
static inline   sint8 s8_add_u8_s8(uint8 x_value, sint8 y_value);
static inline   sint8 s8_add_s8_s8(sint8 x_value, sint8 y_value);
static inline   uint16 u16_calc_av_u16_u16(uint16 x_val, uint16 y_val);
static inline   uint8 flag_cmp_hys_u32_u32_u32_flag(uint32 val, uint32 upr_thd, uint32 low_thd, uint8 lv_oldstate);
static inline   uint8 flag_cmp_hys_s32_s32_s32_flag(sint32 val, sint32 upr_thd, sint32 low_thd, uint8 lv_oldstate);
static inline   sint32 s32_max_s32_s32(sint32 value1, sint32 value2);
static inline   sint8 s8_max_s8_s8(sint8 value1, sint8 value2);
static inline   sint32 s32_min_s32_s32(sint32 value1, sint32 value2);
static inline   sint8 s8_min_s8_s8(sint8 value1, sint8 value2);
static inline   uint32 u32_max_u32_u32(uint32 value1, uint32 value2);
static inline   uint8 u8_max_u8_u8(uint8 value1, uint8 value2);
static inline   uint32 u32_min_u32_u32(uint32 value1, uint32 value2);
static inline   uint8 u8_min_u8_u8(uint8 value1, uint8 value2);
static inline   uint8 u8_limitnew_u8_u8_u8(uint8 newval, uint8 oldval, uint8 maxdif);
static inline   uint8 u8_limitnew_down_u8_u8_u8(uint8 newval, uint8 oldval, uint8 maxdif);
static inline   uint8 u8_limitnew_up_u8_u8_u8(uint8 newval, uint8 oldval, uint8 maxdif);
static inline   uint8 u8_limitnew_up_u8_u8_u8(uint8 newval, uint8 oldval, uint8 maxdif);
static inline   sint8 s8_limitnew_s8_s8_u8(sint8 newval, sint8 oldval, uint8 maxdif);
static inline   sint8 s8_limitnew_down_s8_s8_u8(sint8 newval, sint8 oldval, uint8 maxdif);
static inline   sint8 s8_limitnew_up_s8_s8_u8(sint8 newval, sint8 oldval, uint8 maxdif);
static inline   sint32 s32_min_max_s32_s32_s32(sint32 value, sint32 minimum, sint32 maximum);
static inline   sint32 s32_limitnew_s32_s32_u16(sint32 newval, sint32 oldval, uint16 maxdif);
static inline   sint32 s32_limitnew_down_s32_s32_u16(sint32 newval, sint32 oldval, uint16 maxdif);
static inline   sint32 s32_limitnew_up_s32_s32_u16(sint32 newval, sint32 oldval, uint16 maxdif);
static inline   sint32 s32_limitnew_s32_s32_u32(sint32 newval, sint32 oldval, uint32 maxdif);
static inline   sint32 s32_limitnew_down_s32_s32_u32(sint32 newval, sint32 oldval, uint32 maxdif);
static inline   sint32 s32_limitnew_up_s32_s32_u32(sint32 newval, sint32 oldval, uint32 maxdif);
static inline   uint32 u32_limitnew_u32_u32_u16(uint32 newval, uint32 oldval, uint16 maxdif);
static inline   uint32 u32_limitnew_down_u32_u32_u16(uint32 newval, uint32 oldval, uint16 maxdif);
static inline   uint32 u32_limitnew_up_u32_u32_u16(uint32 newval, uint32 oldval, uint16 maxdif);
static inline   uint32 u32_limitnew_u32_u32_u32(uint32 newval, uint32 oldval, uint32 maxdif);
static inline   uint32 u32_limitnew_down_u32_u32_u32(uint32 newval, uint32 oldval, uint32 maxdif);
static inline   uint32 u32_limitnew_up_u32_u32_u32(uint32 newval, uint32 oldval, uint32 maxdif);
static inline   sint32 s32_min_max_s32_s32(sint32 value, sint32 minmaxwert);
static inline   uint32 u32_min_max_u32_u32_u32(uint32 value, uint32 minimum, uint32 maximum);
static inline   sint16 s16_max_s16_s16(sint16 value1, sint16 value2);
static inline   uint16 u16_max_u16_u16(uint16 value1, uint16 value2);
static inline   sint16 s16_min_s16_s16(sint16 value1, sint16 value2);
static inline   uint16 u16_min_u16_u16(uint16 value1, uint16 value2);
static inline   sint16 s16_limitnew_s16_s16_u16(sint16 newval, sint16 oldval, uint16 maxdif);
static inline   sint16 s16_limitnew_down_s16_s16_u16(sint16 newval, sint16 oldval, uint16 maxdif);


/*~E*/
/*~A*/
/*~+:static inline  Operations*/
/** This operation shall subtract an uint8 value from an sint8 value with underflow limitation

@param x_value First parameter

Range:      80(H)......7F(H)
         -128......127
@param y_value Second parameter 

Range:      00(H)......FF(H)
            0......255
@return (x_value - y_value)
Limit underflow to: 0x80 (-128)

Range:      80(H)...... 7F(H)
           -128......127 */
#include "iopt_memmap.h"

static inline   sint8 s8_sub_s8_u8(sint8 x_value, uint8 y_value)
{
	/* ## Operation body start [470a91e4-d734-4eb2-ba88-020a82a30c40] */
	sint8 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s8_sub_s8_u8                                                    

         Parameter         type    Hex Range       Physical Range         

Input:                                                                    
         x_value            sint8      80..7F           -128..127            
         y_value            uint8      0..FF              0..255             

Output:                                                                   
         res                sint8      80..7F           -128..127            

Functionality:                                                            
        res = x_value - y_value                                           
        underflow: limit to 80H                                           
	 */

	/*~E*/
	if ( ((sint16)x_value - (sint16)y_value) <S8_MIN)
	{
		res_ret =  S8_MIN;
	}
	else
	{
		res_ret = (sint8)((sint16)x_value - (sint16)y_value);
	}
	return  res_ret;
	/*~T*/
	/* ## Operation body end [470a91e4-d734-4eb2-ba88-020a82a30c40] */
}

/** This operation shall subtract an uint8 value from an uint8 value with overflow and underflow limitation

@param x_value First parameter

Range:		00(H)......FF(H)
		    0......255
@param y_value Second parameter

Range:		00(H)......FF(H)
		    0......255
@return (x_value - y_value)
Limit overflow to:  0x7F (127)
Limit underflow to: 0x80 (-128)

Range:		80(H)...... 7F(H)
		   -128......127 */
#include "iopt_memmap.h"

static inline  sint8 s8_sub_u8_u8(uint8 x_value, uint8 y_value)
{
	/* ## Operation body start [73570cf0-a33d-4039-86f4-0cd68650dd01] */
	sint8 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s8_sub_u8_u8                                                    

         Parameter         type    Hex Range       Physical Range         

Input:                                                                    
         x_value            uint8      0..FF             0..255              
         y_value            uint8      0..FF             0..255              

Output:                                                                   
         res                sint8      80..7F          -128..127             

Functionality:                                                            
        res = x_value - y_value                                           
        overflow : limit to 7FH                                           
        underflow: limit to 80H                                           
	 */

	/*~E*/
	if ( ((sint16)x_value -(sint16)y_value) >  S8_MAX)
	{
		res_ret =   S8_MAX;
	}
	else
	{
		if ( ((sint16)x_value -(sint16) y_value) < S8_MIN)
		{
			res_ret =   S8_MIN;
		}
		else
		{
			res_ret =  (sint8)(x_value - y_value);
		}
	}
	/*~T*/
	return res_ret;
	/*~T*/
	/* ## Operation body end [73570cf0-a33d-4039-86f4-0cd68650dd01] */
}

/** This operation shall subtract an sint16 value from an sint16 value with overflow and underflow limitation

@param x_value First parameter

Range:		8000(H)...... 7FFF(H)
		   -32768......32767
@param y_value Second parameter

Range:		8000(H)...... 7FFF(H)
		   -32768......32767
@return (x_value - y_value)
Limit overflow to:  0x7FFF (32767)
Limit underflow to: 0x8000 (-32768)

Range:		8000(H)...... 7FFF(H)
		   -32768......32767 */
#include "iopt_memmap.h"

static inline  sint16 s16_sub_s16_s16(sint16 x_value, sint16 y_value)
{
	/* ## Operation body start [d62ea6d9-f4ea-433f-98fd-70aa568e072f] */
	sint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s16_sub_s16_s16                                                    

         Parameter         type      Hex Range       Physical Range       

Input:                                                                    
         x_value           sint16      8000..7FFF       -32768..32767        
         y_value           sint16      8000..7FFF       -32768..32767        

Output:                                                                   
         res               sint16      8000..7FFF       -32768..32767        

Functionality:                                                            
        res = x_value - y_value                                           
        overflow : limit to 7FFFH                                         
        underflow: limit to 8000H                                         
	 */

	/*~E*/
	/*FUNCTION_ID:3*/
	sint32 tmp_res = (sint32)x_value - (sint32)y_value;
	if ( tmp_res > (sint32)S16_MAX)
	{
		res_ret =   S16_MAX;
	}
	else
	{
		if (tmp_res < (sint32)S16_MIN)
		{
			res_ret =   S16_MIN;
		}
		else
		{
			res_ret =  (sint16)tmp_res;
		}
	}

	/*~T*/
	return res_ret ;
	/*~T*/
	/* ## Operation body end [d62ea6d9-f4ea-433f-98fd-70aa568e072f] */
}

/** This operation shall subtract an uint16 value from an sint16 value with underflow limitation

@param x_value First parameter

Range:		8000(H)...... 7FFF(H)
		   -32768......32767
@param y_value Second parameter

Range:		00(H)......FFFF(H)
		     0.....65535
@return (x_value - y_value)
Limit underflow to: 0x8000 (-32768)

Range:		8000(H)...... 7FFF(H)
		   -32768......32767 */
#include "iopt_memmap.h"

static inline  sint16 s16_sub_s16_u16(sint16 x_value, uint16 y_value)
{
	/* ## Operation body start [4a93c99a-4de0-42e6-bdf3-2858f8b39f1c] */
	sint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s16_sub_s16_u16                                                    

         Parameter         type      Hex Range       Physical Range       

Input:                                                                    
         x_value            sint16      8000..7FFF       -32768..32767       
         y_value            uint16         0..FFFF            0..65535       

Output:                                                                   
         res                sint16      8000..7FFF       -32768..32767       

Functionality:                                                            
        res = x_value - y_value                                           
        underflow: limit to 8000H                                         
	 */

	/*~E*/
	if ( ((sint32)x_value - (sint32)y_value) < S16_MIN)
	{
		res_ret =   S16_MIN;
	}
	else
	{
		res_ret =  (sint16)((sint32)x_value -(sint32)y_value);
	}
	return res_ret ;
	/* ## Operation body end [4a93c99a-4de0-42e6-bdf3-2858f8b39f1c] */
}

/** This operation shall subtract an sint16 value from an uint16 value with overflow limitation

@param x_value First parameter

Range:		00(H)......FFFF(H)
		     0.....65535
@param y_value Second parameter

Range:		8000(H)...... 7FFF(H)
		   -32768......32767
@return (x_value - y_value)
Limit overflow to: 0x7FFF (32767)

Range:		8000(H)...... 7FFF(H)
		   -32768......32767 */
#include "iopt_memmap.h"

static inline  sint16 s16_sub_u16_s16(uint16 x_value, sint16 y_value)
{
	/* ## Operation body start [9d0e76ee-dc44-4ae9-b1a6-4bc5e5b0109e] */
	sint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s16_sub_u16_s16                                                    

         Parameter         type      Hex Range       Physical Range       

Input:                                                                    
         x_value            uint16         0..FFFF            0..65535       
         y_value            sint16      8000..7FFF       -32768..32767       

Output:                                                                   
         res                sint16      8000..7FFF       -32768..32767       

Functionality:                                                            
        res = x_value - y_value                                           
        overflow: limit to 7FFFH                                          
	 */

	/*~E*/
	if ( ((sint32)x_value - (sint32)y_value) > S16_MAX)
	{
		res_ret =   S16_MAX;
	}
	else
	{
		res_ret =  (sint16)((sint32)x_value - (sint32)y_value);
	}
	return res_ret ;
	/* ## Operation body end [9d0e76ee-dc44-4ae9-b1a6-4bc5e5b0109e] */
}

/** This operation shall subtract an uint16 value from an uint16 value with overflow and underflow limitation

@param x_value First parameter

Range:		00(H)......FFFF(H)
		     0.....65535
@param y_value Second parameter

Range:		00(H)......FFFF(H)
		     0.....65535
@return (x_value - y_value)
Limit overflow to:  0x7FFF (32767)
Limit underflow to: 0x8000 (-32768)

Range:		8000(H)...... 7FFF(H)
		   -32768......32767 */
#include "iopt_memmap.h"

static inline  sint16 s16_sub_u16_u16(uint16 x_value, uint16 y_value)
{
	/* ## Operation body start [edb9b8b4-8943-4b76-a679-86a317476b28] */
	sint32 temp;
	sint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s16_sub_u16_u16                                                    

         Parameter         type      Hex Range       Physical Range       

Input:                                                                    
         x_value           uint16        0..FFFF          0..65535           
         y_value           uint16        0..FFFF          0..65535           

Output:                                                                   
         res               sint16       8000..7FFF      -32768..32767        

Functionality:                                                            
        res = x_value - y_value                                           
        overflow : limit to 7FFFH                                         
        underflow: limit to 8000H                                         

	 */

	/*~E*/
	temp = ((sint32)x_value - (sint32)y_value);
	if ( temp > S16_MAX)
	{
		res_ret =   S16_MAX;
	}
	else
	{
		if (temp < S16_MIN)
		{
			res_ret =   S16_MIN;
		}
		else
		{
			res_ret =  (sint16)temp;
		}
	}
	return res_ret ;
	/* ## Operation body end [edb9b8b4-8943-4b76-a679-86a317476b28] */
}

/** This operation shall subtract an uint8 value from an uint8 value and return the uint8 absolute value

@param x_value First parameter

Range:		00(H)......FF(H)
		    0......255
@param y_value Second parameter

Range:		00(H)......FF(H)
		    0......255
@return | x_value - y_value |

Range:		00(H).....FF(H)
		   0.....255 */
#include "iopt_memmap.h"

static inline  uint8 u8_abs_sub_u8_u8(uint8 x_value, uint8 y_value)
{
	/* ## Operation body start [413ac4b4-e94a-435a-bdc3-0dd57f542079] */
	uint8 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u8_abs_sub_u8_u8                                                

         Parameter      type      Hex Range       Physical Range          

Input:                                                                    
         x_value         uint8        0..FF              0..255              
         y_value         uint8        0..FF              0..255              

Output:                                                                   
         res             uint8        0..FF              0..255              

Functionality:                                                            
        res = |x_value - y_value|                                         

	 */

	/*~E*/
	if (x_value > y_value)
	{
		res_ret =  (x_value - y_value);
	}
	else
	{
		res_ret =   (y_value - x_value);
	}
	return res_ret ;
	/* ## Operation body end [413ac4b4-e94a-435a-bdc3-0dd57f542079] */
}

/** This operation shall subtract an uint8 value from an uint8 value with underflow limitation

@param x_value First parameter

Range:		00(H)......FF(H)
		    0......255
@param y_value Second parameter

Range:		00(H)......FF(H)
		    0......255
@return (x_value - y_value)
Limit underflow to: 0x00 (0)

Range:		00(H)......FF(H)
		    0......255 */
#include "iopt_memmap.h"

static inline  uint8 u8_sub_u8_u8(uint8 x_value, uint8 y_value)
{
	/* ## Operation body start [35574a21-ebb4-4ab3-9164-2ef28efc1af3] */
	uint8 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u8_sub_u8_u8                                                    

         Parameter         type      Hex Range       Physical Range       

Input:                                                                    
         x_value            uint8         0..FF            0..255            
         y_value            uint8         0..FF            0..255            

Output:                                                                   
         res                uint8         0..FF            0..255            

Functionality:                                                            
        res = x_value - y_value                                           
        underflow: limit to 0H                                            

	 */

	/*~E*/
	/*~A*/
	/*~+:Description of Lint supression*/
	/* W715: x_value,y_value not referenced */
	/* W530: result not initialised */
	/*~E*/
	if (x_value > y_value)
	{
		res_ret =  (x_value - y_value);
	}
	else
	{
		res_ret =   U8_MIN;
	}
	return res_ret ;
	/* ## Operation body end [35574a21-ebb4-4ab3-9164-2ef28efc1af3] */
}

/** This operation shall subtract an uint16 value from an uint16 value and return the uint16 absolute value

@param x_value First parameter

Range:		00(H)......FFFF(H)
		     0.....65535
@param y_value Second parameter

Range:		00(H)......FFFF(H)
		     0.....65535
@return | x_value - y_value |

Range:		00(H)......FFFF(H)
		     0.....65535 */
#include "iopt_memmap.h"

static inline  uint16 u16_abs_sub_u16_u16(uint16 x_value, uint16 y_value)
{
	/* ## Operation body start [90860b18-89d0-45a7-b6e9-2fa61febac1b] */
	uint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u16_abs_sub_u16_u16                                                

         Parameter         type        Hex Range       Physical Range     

Input:                                                                    
         x_value            uint16         0..FFFF           0..65535        
         y_value            uint16         0..FFFF           0..65535        

Output:                                                                   
         res                uint16         0..FFFF           0..65535        

Functionality:                                                            
        res = |x_value - y_value|                                         

	 */

	/*~E*/
	/*~A*/
	/*~+:Description of Lint supression*/
	/* W715: x_value,y_value not referenced */
	/* W530: result not initialised */
	/*~E*/
	if (x_value > y_value)
	{
		res_ret =  (x_value - y_value);
	}
	else
	{
		res_ret =   (y_value - x_value);
	}
	/*~A*/
	/*~+:Description of Macro ABSSUB_INSTR*/
	/*Instruction used:      absdif  d0,d1,d2*/
	/*Functionality:         d0 = | d1 - d2 |*/
	/*~E*/
	return res_ret ;
	/* ## Operation body end [90860b18-89d0-45a7-b6e9-2fa61febac1b] */
}

/** This operation shall subtract an uint16 value from an uint16 value with underflow limitation

@param x_value First parameter

Range:		00(H)......FFFF(H)
		     0.....65535
@param y_value Second parameter

Range:		00(H)......FFFF(H)
		     0.....65535
@return (x_value - y_value)
Limit underflow to: 0x0000 (0)

Range:		00(H)......FFFF(H)
		     0.....65535 */
#include "iopt_memmap.h"

static inline  uint16 u16_sub_u16_u16(uint16 x_value, uint16 y_value)
{
	/* ## Operation body start [1b022f3e-8abc-4325-8587-735d4c7df0c5] */
	uint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u16_sub_u16_u16                                                    

         Parameter         type         Hex Range       Physical Range    

Input:                                                                    
         x_value            uint16         0..FFFF            0..65535       
         y_value            uint16         0..FFFF            0..65535       

Output:                                                                   
         res                uint16         0..FFFF            0..65535       

Functionality:                                                            
        res = x_value - y_value                                           
        underflow: limit to 0                                             

	 */

	/*~E*/
	if (x_value > y_value)
	{
		res_ret =  (x_value - y_value);
	}
	else
	{
		res_ret =   U16_MIN;
	}
	return res_ret ;
	/* ## Operation body end [1b022f3e-8abc-4325-8587-735d4c7df0c5] */
}

/** This operation shall subtract an uint32 value from an uint32 value with overflow and underflow limitation

@param x_value First parameter

Range:		00(H)......FFFFFFFF(H)
		     0.....4294967295
@param y_value Second parameter

Range:		00(H)......FFFFFFFF(H)
		     0.....4294967295
@return (x_value - y_value)
Limit overflow to: 0xFFFF (65535)
Limit underflow to: 0x0000 (0)

Range:		00(H)......FFFF(H)
		     0.....65535 */
#include "iopt_memmap.h"

static inline  uint16 u16_sub_u32_u32(uint32 x_value, uint32 y_value)
{
	/* ## Operation body start [bb990550-ed9a-4a14-bcc1-15875956f9db] */
	uint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u16_sub_u32_u32                                                    

         Parameter   type    Hex Range       Physical Range               

Input:                                                                    
         x_value     uint32     0..FFFFFFFF     0..4294967295                
         y_value     uint32     0..FFFFFFFF     0..4294967295                

Output:                                                                   
         res         uint16     0..FFFF           0..65535                   

Functionality:                                                            
        res = x_value - y_value                                           
        overflow : limit to FFFFH                                         
        underflow: limit to 0                                             

	 */

	/*~E*/
	if (y_value >= x_value)
	{
		res_ret =   U16_MIN;
	}
	else
	{
		if ((x_value - y_value) <U16_MAX)
		{
			res_ret =  (uint16)(x_value - y_value);
		}
		else
		{
			res_ret =   U16_MAX;
		}
	}
	return res_ret ;
	/* ## Operation body end [bb990550-ed9a-4a14-bcc1-15875956f9db] */
}

/** This operation shall return the absolute value of the difference between two sint16 values

@param x_value First parameter

Range:		8000(H)...... 7FFF(H)
		   -32768......32767
@param y_value Second parameter

Range:		8000(H)...... 7FFF(H)
		   -32768......32767
@return | (x_value - y_value) |

Range:		00(H)......FFFF(H)
		     0.....65535 */
#include "iopt_memmap.h"

static inline  uint16 u16_abs_sub_s16_s16(sint16 x_value, sint16 y_value)
{
	/* ## Operation body start [3e88640d-f9e1-4c14-b9b6-5c2787af223f] */
	uint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u16_abs_sub_s16_s16                                                

         Parameter     type        Hex Range       Physical Range         

Input:                                                                    
         x_value       sint16         8000..7FFF     -32768..32767           
         y_value       sint16         8000..7FFF     -32768..32767           

Output:                                                                   
         res           uint16          0..FFFF          0..65535             

Functionality:                                                            
        res = |x_value - y_value|                                         

	 */

	/*~E*/
	/*FUNCTION_ID:12*/
	if (x_value > y_value)
	{
		res_ret =  (uint16)(x_value - y_value);
	}
	else
	{
		res_ret =   (uint16)(y_value - x_value);
	}
	return res_ret ;
	/* ## Operation body end [3e88640d-f9e1-4c14-b9b6-5c2787af223f] */
}

/** This operation shall subtract an uint32 value from an uint32 value with underflow limitation

@param x_value First parameter

Range:		00(H)......FFFFFFFF(H)
		     0.....4294967295
@param y_value Second parameter

Range:		00(H)......FFFFFFFF(H)
		     0.....4294967295
@return (x_value - y_value)
Limit underflow to: 0x0000 (0)

Range:		00(H)......FFFFFFFF(H)
		     0.....4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_sub_u32_u32(uint32 x_value, uint32 y_value)
{
	/* ## Operation body start [6671f884-42df-4cb0-90d1-530b95c09c6f] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION:u32_sub_u32_u32                                                     

         Parameter      type      Hex Range        Physical Range         

Input:                                                                    
         x_value        uint32      0..FFFFFFFF       0..4294967295          
         y_value        uint32      0..FFFFFFFF       0..4294967295          

Output:                                                                   
         res            uint32      0..FFFFFFFF       0..4294967295          


Functionality:                                                            
        res =  x_value - y_value                                          

	 */

	/*~E*/
	if (x_value <= y_value)
	{
		res_ret =  U16_MIN;
	}
	else
	{
		res_ret =  (x_value - y_value);
	}
	return res_ret ;
	/* ## Operation body end [6671f884-42df-4cb0-90d1-530b95c09c6f] */
}

/** This operation shall subtract an sint16 value from an uint16 value with overflow and underflow limitation

@param x_value First parameter

Range:		00(H)......FFFF(H)
		     0.....65535
@param y_value Second parameter

Range:		8000(H)...... 7FFF(H)
		   -32768......32767
@return (x_value - y_value)
Limit overflow to:  0xFFFF (65535)
Limit underflow to: 0x00 (0)

Range:		00(H)......FFFF(H)
		     0......65535 */
#include "iopt_memmap.h"

static inline  uint16 u16_sub_u16_s16(uint16 x_value, sint16 y_value)
{
	/* ## Operation body start [f0e44053-82d6-46e9-9799-5e6c7081503d] */
	uint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION:u16_sub_u16_s16                                                     

         Parameter         type      Hex Range       Physical Range       

Input:                                                                    
         x_value           uint16        0..FFFF           0..65535          
         y_value           sint16      8000..7FFF       -32768..32767        

Output:                                                                   
         res               uint16        0..FFFF           0..65535          


Functionality:                                                            
        res =  x_value - y_value with overflow limitation                 

	 */

	/*~E*/
	sint32 temp;

	temp = (sint32)x_value - (sint32)y_value;

	if (temp >= (sint32)U16_MAX)
	{
		res_ret =  U16_MAX;
	}
	else
	{
		if (temp <= (sint32)U16_MIN)
		{
			res_ret =   U16_MIN;
		}
		else
		{
			res_ret =  (uint16)temp;
		}

	}
	return res_ret ;
	/* ## Operation body end [f0e44053-82d6-46e9-9799-5e6c7081503d] */
}

/** This operation shall subtract an sint32 value from an sint32 value with overflow and underflow limitation

@param x_value First parameter

Range:		80000000(H)......7FFFFFFF(H)
		  -2147483648....2147483647
@param y_value Second parameter

Range:		80000000(H)......7FFFFFFF(H)
		  -2147483648....2147483647
@return (x_value - y_value)
Limit overflow to:   0x7FFFFFFF (2147483647)
Limit underflow to: 0x80000000 (-2147483648)

Range:		80000000(H)......7FFFFFFF(H)
		  -2147483648....2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_sub_s32_s32(sint32 x_value, sint32 y_value)
{
	/* ## Operation body start [6f123ddd-0c26-44a2-bc21-5abe83b96312] */
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION:s32_sub_s32_s32                                                             

         Parameter     type         Hex Range              Physical Range         

Input:                                                                            
         x_value       sint32     80000000..FFFFFFFF     -2147483648..2147483647     
         y_value       sint32     80000000..FFFFFFFF     -2147483648..2147483647     

Output:                                                                           
         res           sint32     80000000..FFFFFFFF     -2147483648..2147483647     


Functionality:                                                                    
        res =  x_value - y_value                                                  

	 */

	/*~E*/
	sint64 tmp_res;
	sint32 res_ret;
	/* Check if signed input is negative */
	tmp_res = (sint64)x_value - (sint64)y_value;
	if (tmp_res >= S32_MAX)
	{
		res_ret =  S32_MAX;
	}
	else
	{
		if (tmp_res <= S32_MIN)
		{
			res_ret =  S32_MIN;
		}
		else
		{
			res_ret =  (sint32)tmp_res;
		}
	}
	return res_ret ;
	/* ## Operation body end [6f123ddd-0c26-44a2-bc21-5abe83b96312] */
}

/** This operation shall subtract an uint32 value from an uint32 value with overflow and underflow limitation

@param x_value First parameter

Range:		00(H)......FFFFFFFF(H)
		     0.....4294967295
@param y_value Second parameter

Range:		00(H)......FFFFFFFF(H)
		     0.....4294967295
@return (x_value - y_value)
Limit overflow to:   0x7FFF (32767)
Limit underflow to: 0x8000(-32768)

Range:		8000(H)...... 7FFF(H)
		   -32768......32767 */
#include "iopt_memmap.h"

static inline  sint16 s16_sub_u32_u32(uint32 x_value, uint32 y_value)
{
	/* ## Operation body start [1752005c-e460-47e7-81d2-6fae72130493] */
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s16_sub_u32_u32                                                    

         Parameter   type    Hex Range       Physical Range               

Input:                                                                    
         x_value     uint32     0..FFFFFFFF     0..4294967295                
         y_value     uint32     0..FFFFFFFF     0..4294967295                

Output:                                                                   
         res         sint16     8000..7FFF      -32768..32767                

Functionality:                                                            
        res = x_value - y_value                                           
        overflow : limit to 7FFFH                                         
        underflow: limit to 8000                                          

	 */

	/*~E*/
	sint32 tmp_res;
	uint32 tmp_res1;
	sint16 res_ret;
	/* Comapre the input parameters */
	if ( x_value > y_value )
	{
		tmp_res1 = x_value - y_value;
		/* Check for overflow */
		if ( tmp_res1 > (uint32)S16_MAX )
		{
			res_ret =   S16_MAX;
		}
		else
		{
			res_ret =  (sint16)tmp_res1;
		}
	}
	else
	{
		tmp_res = (sint32)(x_value - y_value);
		/* Check for underflow */
		if ( (tmp_res > 0) || (tmp_res < (sint32)S16_MIN) )
		{
			res_ret =   S16_MIN;
		}
		else
		{
			res_ret =  (sint16)tmp_res;
		}
	}

	return res_ret ;
	/* ## Operation body end [1752005c-e460-47e7-81d2-6fae72130493] */
}

/** This operation shall subtract an sint32 value from an uint32 value with overflow and underflow limitation

@param x_value First parameter

Range:		00(H)......FFFFFFFF(H)
		     0.....4294967295
@param y_value Second parameter

Range:		80000000(H)......7FFFFFFF(H)
		  -2147483648....2147483647
@return (x_value - y_value)
Limit overflow to:   0xFFFFFFFF (4294967295)
Limit underflow to: 0x0000 (0)

Range:		00(H)......FFFFFFFF(H)
		     0.....4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_sub_u32_s32(uint32 x_value, sint32 y_value)
{
	/* ## Operation body start [07e03935-9876-4792-a0ee-66e4cc6e0319] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION:u32_sub_u32_s32                                                     

         Parameter    type       Hex Range           Physical Range       

Input:                                                                    
         x_value      uint32       0..FFFFFFFF          0..4294967295        
         y_value      sint32    80000000..7FFFFFFF  -2147483648..2147483647  

Output:                                                                   
         res          uint32       0..FFFFFFFF          0..4294967295        


Functionality:                                                            
        res =  x_value - y_value with                                     
        overflow limitation FFFFFFFFH                                     
        underflow limitation 00000000H                                    
	 */

	/*~E*/
	/*~A*/
	/*~+:Description of Lint supression*/
	/* W715: x_value,y_value not referenced */
	/* W530: tmp_res not initialised */
	/* W529: abs_value not subsequently refrenced */
	/*~E*/
	uint32 tmp_res;

	/* Compare if signed input parameter is negative */
	if ( y_value < 0 )
	{
		tmp_res = x_value  + (uint32)(-y_value);

		/* Check for overflow */
		if ( tmp_res < x_value )
		{
			res_ret =  U32_MAX;
		}
		else
		{
			res_ret =  tmp_res;
		}
	}
	else
	{
		/* Check for underflow */
		if ( (uint32)y_value >= x_value )
		{
			res_ret =  U32_MIN;
		}
		else
		{
			res_ret =  (uint32)(x_value - (uint32)y_value);
		}
	}
	return res_ret ;
	/* ## Operation body end [07e03935-9876-4792-a0ee-66e4cc6e0319] */
}

/** This operation shall subtract an uint32 value from an sint32 value with underflow limitation

@param x_value First parameter

Range:		80000000(H)......7FFFFFFF(H)
		  -2147483648....2147483647
@param y_value Second parameter

Range:		00(H)......FFFFFFFF(H)
		     0.....4294967295
@return (x_value - y_value)
Limit underflow to: 0x0000 (0)

Range:		00(H)......FFFFFFFF(H)
		     0.....4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_sub_s32_u32(sint32 x_value, uint32 y_value)
{
	/* ## Operation body start [c272c6f3-23ab-473c-ae7a-57337872bea6] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION:u32_sub_s32_u32                                                        

         Parameter    type       Hex Range             Physical Range        

Input:                                                                       
         x_value      sint32    80000000..7FFFFFFF   -2147483648..2147483647    
         y_value      uint32       0..FFFFFFFF            0..4294967295         

Output:                                                                      
         res          uint32       0..FFFFFFFF            0..4294967295         


Functionality:                                                               
        res =  x_value - y_value with                                        
        underflow limitation  00000000H                                      

	 */

	/*~E*/
	/* Check for underflow */
	if ( x_value < 0 )
	{
		res_ret =   U32_MIN;
	}
	else
	{
		if ( (uint32)x_value < y_value )
		{
			res_ret =   U32_MIN;
		}
		else
		{
			res_ret =  (uint32)((uint32)x_value - y_value);

		}
	}
	return res_ret ;
	/* ## Operation body end [c272c6f3-23ab-473c-ae7a-57337872bea6] */
}

/** This operation shall subtract an sint32 value from an sint32 value with underflow limitation

@param x_value First parameter

Range:		80000000(H)......7FFFFFFF(H)
		  -2147483648....2147483647
@param y_value Second parameter

Range:		80000000(H)......7FFFFFFF(H)
		  -2147483648....2147483647
@return (x_value - y_value)
Limit underflow to: 0x0000 (0)

Range:		00(H)......FFFFFFFF(H)
		     0.....4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_sub_s32_s32(sint32 x_value, sint32 y_value)
{
	/* ## Operation body start [de34cbf8-ff9a-4de7-8718-6404b5ae3274] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION:u32_sub_s32_s32                                                          

         Parameter    type         Hex Range              Physical Range       

Input:                                                                         
         x_value      sint32      80000000..7FFFFFFF   -2147483648..2147483647    
         y_value      sint32      80000000..7FFFFFFF   -2147483648..2147483647    

Output:                                                                        
         res          uint32         0..FFFFFFFF           0..4294967295          


Functionality:                                                                 
        res =  x_value - y_value with                                          
        underflow limitation  00000000H                                        

	 */

	/*~E*/
	/* Check for underflow */
	if ( x_value < y_value )
	{
		res_ret =   U32_MIN;
	}
	else
	{
		res_ret =  (uint32)(x_value - y_value);

	}

	return res_ret ;
	/* ## Operation body end [de34cbf8-ff9a-4de7-8718-6404b5ae3274] */
}

/** This operation shall return the absolute value of the difference between two uint32 values

@param x_value First parameter

Range:		00(H)......FFFFFFFF(H)
		     0.....4294967295
@param y_value Second parameter

Range:		00(H)......FFFFFFFF(H)
		     0.....4294967295
@return  (x_value - y_value) 

Range:		00(H)......FFFFFFFF(H)
		    0.....4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_abs_sub_u32_u32(uint32 x_value, uint32 y_value)
{
	/* ## Operation body start [416a3cde-2be1-4aa1-8a0c-756a17d3ca8a] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u32_abs_sub_u32_u32                                                

         Parameter         type       Hex Range        Physical Range     

Input:                                                                    
         x_value            uint32      0..FFFFFFFF       0..4294967295      
         y_value            uint32      0..FFFFFFFF       0..4294967295      

Output:                                                                   
         res                uint32      0..FFFFFFFF       0..4294967295      
Functionality:                                                            
        res = |x_value - y_value|                                         

	 */

	/*~E*/
	/* comapre the input parameters */
	if ( x_value > y_value )
	{
		res_ret =  (uint32)(x_value - y_value);
	}
	else
	{
		res_ret =   (uint32)(y_value - x_value);
	}
	return res_ret ;
	/* ## Operation body end [416a3cde-2be1-4aa1-8a0c-756a17d3ca8a] */
}

/** This operation shall subtract an sint32 value from an uint32 value with overflow limitation

@param x_value First parameter

Range:		00(H)......FFFFFFFF(H)
		     0.....4294967295
@param y_value Second parameter

Range:		80000000(H)......7FFFFFFF(H)
		  -2147483648....2147483647
@return (x_value - y_value)
Limit overflow to:   0x7FFFFFFF (2147483647)

Range:		80000000(H)......7FFFFFFF(H)
		  -2147483648....2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_sub_u32_s32(uint32 x_value, sint32 y_value)
{
	/* ## Operation body start [be96df4b-4be7-45d7-afe6-064f4b824241] */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION:s32_sub_u32_s32                                                          

         Parameter    type           Hex Range              Physical Range     

Input:                                                                         
         x_value      uint32           0..FFFFFFFF            0..4294967295       
         y_value      sint32        80000000..7FFFFFFF   -2147483648..2147483647  

Output:                                                                        
         res          sint32        80000000..7FFFFFFF   -2147483648..2147483647  


Functionality:                                                                 
        res =  x_value - y_value with                                          
        overflow limitation   7FFFFFFFH                                        
	 */

	/*~E*/
	uint32 tmp_res;
	/* Check if signed input is negative */
	/* Check if signed input is negative */
	if ( y_value < 0 )
	{
		/* Subtraction of two values */
		tmp_res = (x_value + (uint32)(-y_value));
		/* Check for overflow case */
		if ( (tmp_res < x_value) || (tmp_res > (uint32)S32_MAX) )
		{
			res_ret =  S32_MAX;
		}
		else
		{
			res_ret =  (sint32)tmp_res;
		}
	}
	else
	{
		/* Check if first input is greater than second */
		if ( x_value > (uint32)y_value )
		{
			/* Subtraction of two values */
			tmp_res = x_value - (uint32)y_value;
			/* Check for overflow case */
			if ( tmp_res > (uint32)S32_MAX )
			{
				res_ret =  S32_MAX;
			}
			else
			{
				res_ret = (sint32)tmp_res;
			}
		}
		else
		{
			/* Return the result */
			res_ret =  (sint32)(x_value - (uint32)y_value);
		}
	}

	return res_ret ;
	/* ## Operation body end [be96df4b-4be7-45d7-afe6-064f4b824241] */
}

/** This operation shall subtract an uint32 value from an sint32 value with underflow limitation

@param x_value First parameter

Range:		80000000(H)......7FFFFFFF(H)
		  -2147483648....2147483647
@param y_value Second parameter

Range:		00(H)......FFFFFFFF(H)
		     0.....4294967295
@return (x_value - y_value)
Limit underflow to:   0x80000000 (-2147483648)

Range:		80000000(H)......7FFFFFFF(H)
		  -2147483648....2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_sub_s32_u32(sint32 x_value, uint32 y_value)
{
	/* ## Operation body start [af0f81a5-6273-4619-9605-9bc33c97e19c] */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION:s32_sub_s32_u32                                                        

         Parameter    type        Hex Range              Physical Range      

Input:                                                                       
         x_value      sint32    80000000..7FFFFFFF    -2147483648..2147483647   
         y_value      uint32        0..FFFFFFFF             0..4294967295       

Output:                                                                      
         res          sint32    80000000..7FFFFFFF    -2147483648..2147483647   


Functionality:                                                               
        res =  x_value - y_value with                                        
        underflow limitation  80000000H                                      
        overflow limitation   7FFFFFFFH                                      

	 */

	/*~E*/
	/*~A*/
	/*~+:Description of Lint supression*/
	/* W530: temp_res not initialised */

	/*~E*/
	sint64 tmp_res;
	/* Check if signed input is negative */
	tmp_res = (sint64)x_value - (sint64)y_value;
	if (tmp_res >= S32_MAX)
	{
		res_ret =  S32_MAX;
	}
	else
	{
		if (tmp_res <= S32_MIN)
		{
			res_ret =  S32_MIN;
		}
		else
		{
			res_ret =  (sint32)tmp_res;
		}
	}

	return res_ret ;
	/* ## Operation body end [af0f81a5-6273-4619-9605-9bc33c97e19c] */
}

/** This operation shall subtract an uint32 value from an uint32 value with overflow and underflow limitation

@param x_value First parameter

Range:		00(H)......FFFFFFFF(H)
		     0.....4294967295
@param y_value Second parameter

Range:		00(H)......FFFFFFFF(H)
		     0.....4294967295
@return (x_value - y_value)
Limit overflow to:   0x7FFFFFFF (2147483647)
Limit underflow to: 0x80000000(-2147483648)

Range:		80000000(H)......7FFFFFFF(H)
		  -2147483648....2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_sub_u32_u32(uint32 x_value, uint32 y_value)
{
	/* ## Operation body start [3e098853-21bf-4f0a-b3a6-608077338364] */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s32_sub_u32_u32                                                                

         Parameter     type         Hex Range               Physical Range            

Input:                                                                                
         x_value       uint32         0..FFFFFFFF              0..4294967295             
         y_value       uint32         0..FFFFFFFF              0..4294967295             

Output:                                                                               
         res           sint32    80000000..0..7FFFFFFF   -2147483648..0..2147483647      

Functionality:                                                                        
        res = x_value - y_value                                                       
        overflow : limit to 7FFFFFFFH                                                 
        underflow: limit to 80000000H                                                 

	 */

	/*~E*/
	sint32 tmp_res;
	uint32 tmp_res1;
	/* Comapre the input parameters */
	if ( x_value >= y_value )
	{
		tmp_res1 = x_value - y_value;
		/* Check for overflow */
		if ( tmp_res1 > (uint32)S32_MAX )
		{
			res_ret =   S32_MAX;
		}
		else
		{
			res_ret =  (sint32)tmp_res1;
		}
	}
	else
	{
		tmp_res = (sint32)(x_value - y_value);
		/* Check for underflow */
		if ( tmp_res > 0 )
		{
			res_ret =   S32_MIN;
		}
		else
		{
			res_ret =  tmp_res;
		}
	}
	return res_ret ;
	/* ## Operation body end [3e098853-21bf-4f0a-b3a6-608077338364] */
}

/** This operation shall return the absolute value of the difference between two sint32 values with overflow limitation

@param x_value First parameter

Range:		80000000(H)......7FFFFFFF(H)
		  -2147483648....2147483647
@param y_value Second parameter

Range:		80000000(H)......7FFFFFFF(H)
		  -2147483648....2147483647
@return  (x_value - y_value) 
Limit overflow to: 0x7FFFFFFF (2147483647)	

Range:		00(H)......7FFFFFFF(H)
		    0.....2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_abs_sub_s32_s32(sint32 x_value, sint32 y_value)
{
	/* ## Operation body start [63c52f67-a7af-4db6-b8f1-a4a5977f906c] */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s32_abs_sub_s32_s32                                                   

         Parameter   type         Hex Range               Physical Range     

Input:                                                                       
         x_value     sint32      80000000..7FFFFFFF     -2147483648..2147483648 
         y_value     sint32      80000000..7FFFFFFF     -2147483648..2147483648 

Output:                                                                      
         res         sint32      80000000..7FFFFFFF          0..2147483648      

Functionality:                                                               
        res = |x_value - y_value|                                            
        overflow : limit to 7FFFFFFFH                                        
	 */

	/*~E*/
	uint32 tmp_res;

	/* Comapre the input parameters */
	if ( x_value > y_value )
	{
		tmp_res = (uint32)(x_value - y_value);
	}
	else
	{
		tmp_res = (uint32)(y_value - x_value);
	}
	/* Check for overflow */
	if ( tmp_res > (uint32)S32_MAX )
	{
		res_ret =  S32_MAX ;
	}
	else
	{
		res_ret =  (sint32)tmp_res;
	}
	return res_ret ;
	/* ## Operation body end [63c52f67-a7af-4db6-b8f1-a4a5977f906c] */
}

/** This operation shall subtract an sint8 value from an sint8 value with overflow and underflow limitation

@param x_value First parameter

Range:		80(H)......7F(H)
		 -128......127
@param y_value Second parameter

Range:		80(H)......7F(H)
		 -128......127
@return (x_value - y_value)
Limit overflow to: 0x7F (127)
Limit underflow to: 0x80 (-128)

Range:		80(H)....7F(H)
		  -128....127 */
#include "iopt_memmap.h"

static inline  sint8 s8_sub_s8_s8(sint8 x_value, sint8 y_value)
{
	/* ## Operation body start [fdb41317-9062-4062-b66b-db2df00db506] */
	sint8 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s8_sub_s8_s8                                                    

         Parameter         type    Hex Range       Physical Range         

Input:                                                                    
         x_value            sint8      80..7F           -128..127            
         y_value            sint8      80..7F           -128..127            

Output:                                                                   
         res                sint8      80..7F           -128..127            

Functionality:                                                            
        res = x_value - y_value                                           
        overflow: Limit to 7FH                                             
        underflow: Limit to 80H                                           
	 */

	/*~E*/
	sint32 tmp_res = (sint32)x_value - (sint32)y_value;
	if ( tmp_res > (sint32)S8_MAX)
	{
		res_ret =   S8_MAX;
	}
	else
	{
		if (tmp_res < (sint32)S8_MIN)
		{
			res_ret =   S8_MIN;
		}
		else
		{
			res_ret =  (sint8)tmp_res;
		}
	}
	return res_ret ;
	/* ## Operation body end [fdb41317-9062-4062-b66b-db2df00db506] */
}

/** This operation shall subtract an sint8 value from an uint8 value with overflow and underflow limitation

@param x_value First parameter

Range:		00(H)......FF(H)
		    0......255
@param y_value Second parameter

Range:		80(H)......7F(H)
		 -128......127
@return (x_value - y_value)
Limit overflow to: 0xFF (255)
Limit underflow to: 0x00 (0)

Range:		00(H)......FF(H)
		    0......255 */
#include "iopt_memmap.h"

static inline  uint8 u8_sub_u8_s8(uint8 x_value, sint8 y_value)
{
	/* ## Operation body start [d45b2ea0-aaf7-4991-84a8-b4a1765c2672] */
	uint8 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION:u8_sub_u8_s8                                                     

         Parameter         type      Hex Range       Physical Range       

Input:                                                                    
         x_value           uint8          0..FF           0..255             
         y_value           sint8         80..7F        -128..127             

Output:                                                                   
         res               uint8          0..FF           0..255             


Functionality:                                                            
        res =  x_value - y_value with overflow and undeflow limitation    

	 */

	/*~E*/
	sint32 temp;

	temp = (sint32)x_value - (sint32)y_value;

	if (temp >= (sint32)U8_MAX)
	{
		res_ret =  U8_MAX;
	}
	else
	{
		if (temp <= (sint32)U8_MIN)
		{
			res_ret =   U8_MIN;
		}
		else
		{
			res_ret =  (uint8)temp;
		}
	}
	return res_ret ;
	/* ## Operation body end [d45b2ea0-aaf7-4991-84a8-b4a1765c2672] */
}

/** This operation shall convert an sint32 value to an sint16 value with overflow and underflow limitation

@param value value to be converted to sint16

Range:		80000000(H)........7FFFFFFF(H)
		 -2147483648.......2147483647
@return type converted value
Limit overflow to: 0x7FFF (32767)
Limit underflow to: 0x8000 (-32768)

Range:		8000(H)......7FFF(H)
		 -32768......32767 */
#include "iopt_memmap.h"

static inline  sint16 s16_s32(sint32 value)
{
	/* ## Operation body start [312d1d81-ddd8-4e22-97f7-8b1f63581344] */
	sint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s16_s32                                                               

       Parameter   type          Hex Range            Physical Range          

Input:                                                                        
         value     sint32       80000000..7FFFFFFF   -2147483648..2147483647     

Output:                                                                       
         res       sint16           8000..7FFF           -32768..32767           

Functionality:                                                                
        res = value converted from signed long to signed int with             
        overflow and underflow limitation                                     

        overflow : limit to 7FFFH                                             
	 */

	/*~E*/
	if (value >= S16_MAX)
	{
		res_ret =  S16_MAX;
	}
	else
	{
		if (value <= S16_MIN)
		{
			res_ret =  S16_MIN;
		}
		else
		{
			res_ret =  (sint16)value;
		}
	}
	return res_ret ;
	/* ## Operation body end [312d1d81-ddd8-4e22-97f7-8b1f63581344] */
}

/** This operation shall convert an uint16 value to an sint16 value with overflow limitation

@param value value to be converted to sint16

Range:		00(H)........FFFF(H)
	 	    0.......65535
@return type converted value
Limit overflow to: 0x7FFF (32767)

Range:		8000(H)......7FFF(H)
		 -32768......32767 */
#include "iopt_memmap.h"

static inline  sint16 s16_u16(uint16 value)
{
	/* ## Operation body start [2105e854-8320-49c3-a94f-82226f654e3e] */
	sint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s16_u16                                                           

         Parameter     type      Hex Range       Physical Range           

Input:                                                                    
         value          uint16      0..FFFF            0..65535              

Output:                                                                   
         res            sint16      8000..7FFF      -32768..32767            

Functionality:                                                            
        convert unsigned int to signed int                                
        overflow : limit to 7FFFH                                         
	 */

	/*~E*/
	if ((sint32)value >= S16_MAX)
	{
		res_ret =  S16_MAX;
	}
	else
	{
		res_ret =  (sint16)value;
	}
	return res_ret ;
	/* ## Operation body end [2105e854-8320-49c3-a94f-82226f654e3e] */
}

/** This operation shall convert an uint16 value to an uint8 value with overflow limitation

@param value value to be converted to uint8

Range:		00(H)........FFFF(H)
	 	    0.......65535
@return type converted uint8 value
Limit overflow to: 0xFF (255)

Range:		00(H)....FF(H)
		     0...255 */
#include "iopt_memmap.h"

static inline  uint8 u8_u16(uint16 value)
{
	/* ## Operation body start [ab31b6db-4f23-495d-b470-183157208c07] */
	uint8 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u8_u16                                                           

         Parameter      type       Hex Range     Physical Range           

Input:                                                                    
         value          uint16         0..FFFF         0..65535              

Output:                                                                   
         res            uint8          0..FF           0..255                

Functionality:                                                            
        conversion of unsigned to unsigned char with overflow limitation  
        overflow : limit to FFH                                           
	 */

	/*~E*/
	if (value >= U8_MAX)
	{
		res_ret =  U8_MAX;
	}
	else
	{
		res_ret =  (uint8)value;
	}
	return res_ret ;
	/* ## Operation body end [ab31b6db-4f23-495d-b470-183157208c07] */
}

/** This operation shall convert an sint16 value to an uint16 value with underflow limitation

@param value Value to be converted to uint16

Range:		8000(H)......7FFF(H)
		  -32768.....32767
@return value
Limit underflow to: 0x00 (0)

Range:		00(H).......FFFF(H)
	                0......65535 */
#include "iopt_memmap.h"

static inline  uint16 u16_s16(sint16 value)
{
	/* ## Operation body start [7723f041-7d2a-4195-b04f-d84d966cb785] */
	uint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u16_s16                                                           

         Parameter        type       Hex Range       Physical Range       

Input:                                                                    
         value             sint16       8000..7FFF      -32768..32767        

Output:                                                                   
         res               uint16       0..FFFF            0..65535          

Functionality:                                                            
         change a signed int to an unsigned int with underflow limitation 
         underflow: limit to 0H                                           
	 */

	/*~E*/
	if (value <= (sint16)U16_MIN)
	{
		res_ret =  U16_MIN;
	}
	else
	{
		res_ret =  (uint16)value;
	}
	return res_ret ;
	/* ## Operation body end [7723f041-7d2a-4195-b04f-d84d966cb785] */
}

/** This operation shall convert an uint32 value to an uint16 value with overflow limitation

@param value Value to be converted to uint16

Range:		00(H).......FFFFFFFF(H)
		     0.......4294967295
@return value
Limit overflow to: 0xFFFF (65535)

Range:		00(H).....FFFF(H)
	 	     0.....65535 */
#include "iopt_memmap.h"

static inline  uint16 u16_u32(uint32 value)
{
	/* ## Operation body start [d652f5da-924a-4d2e-8263-efc38adb487e] */
	uint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u16_u32                                                           

       Parameter        type      Hex Range       Physical Range          

Input:                                                                    
         value          uint32       0..FFFFFFFF     0..4294967295           

Output:                                                                   
         res            uint16         0..FFFF          0..65535             

Functionality:                                                            
       change an unsigned long to an unsigned int with overflow limitation
       overflow : limit to FFFFH                                          
	 */

	/*~E*/
	if (value >= U16_MAX)
	{
		res_ret =  U16_MAX;
	}
	else
	{
		res_ret =  (uint16)value;
	}
	return res_ret ;
	/* ## Operation body end [d652f5da-924a-4d2e-8263-efc38adb487e] */
}

/** This operation shall shift an sint32 value a given number of bits (count) to the right (no check of number of bits)

@param value value to be shifted right

Range:		80000000(H)........7FFFFFFF(H)
		 -2147483648.......2147483647
@param count number of bits by which value has to be shifted 

Range:		00(H)........0F(H)
		     0.......15
@return value >> count

Range:		80000000(H).......7FFFFFFF(H)
		  -2147483648.....2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_exp05_s32_u8(sint32 value, uint8 count)
{
	/* ## Operation body start [fc857706-6f15-4926-b9db-966de061ce36] */

	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s32_exp05_s32_u8                                                    

      Parameter   type           Hex Range            Physical Range      

Input:                                                                    
       value      sint32       80000000..7FFFFFFF  -2147483648..2147483647   
       count      uint8               0..F                   0..15           

Output:                                                                   
       res        sint32       80000000..7FFFFFFF  -2147483648..2147483647   

Functionality:                                                            
        count=count%16                                                    
        res=value>>count                                                  
	 */

	/*~E*/
	/*~A*/
	/*~+:Description of Lint supression*/
	/* Info 704: Use library functions for shift right and shift left. This PC-Lint info is disabled since a library must never use other libraries */

	/*~E*/
	/* count (count %= 32) limited internal by HW to (0..31) */
	return /*lint --e(704) */(value >> count);


	/* ## Operation body end [fc857706-6f15-4926-b9db-966de061ce36] */
}

/** This operation shall shift an uint32 value a given number of bits (count) to the right with overflow limitation (no check of number of bits)

@param value value to be shifted right

Range:		00(H)........FFFFFFFF(H)
		     0.....4294967295
@param count number of bits by which value has to be shifted 

Range:		00(H)........0F(H)
		     0.......15
@return value >> count
Limit overflow to: 0xFFFF (65535)

Range:		00(H)......FFFF(H)
		    0 ... 65535 */
#include "iopt_memmap.h"

static inline  uint16 u16_exp05_u32_u8(uint32 value, uint8 count)
{
	/* ## Operation body start [8848f315-3449-4d72-8a70-bfdbb7d1e7a4] */
	uint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION:  u16_exp05_u32_u8                                                   

      Parameter   type         Hex Range          Physical Range          

Input:                                                                    
       value      uint32         0..FFFFFFFF         0..4294967295           
       count      uint8          0..F                0..15                   

Output:                                                                   
       res        uint16         0..FFFF             0..65535                

functionality:                                                            
        count=count%16                                                    
        res=value>>count                                                  

	 */

	/*~E*/
	uint32 temp,tmp_count;
	tmp_count=(uint32)count;
	tmp_count %= 16U;

	temp = value >> tmp_count;
	/*Check for overlow*/
	if (temp >= U16_MAX)
	{
		res_ret =  U16_MAX;
	}
	else
	{
		res_ret =  (uint16)temp;
	}
	return res_ret ;
	/* ## Operation body end [8848f315-3449-4d72-8a70-bfdbb7d1e7a4] */
}

/** This operation shall shift an uint32 value a given number of bits (count) to the right (no check of number of bits)

@param value value to be shifted right

Range:		00(H)........FFFFFFFF(H)
		     0.....4294967295
@param count number of bits by which value has to be shifted 

Range:		00(H)........0F(H)
		     0.......15
@return value >> count

Range:		00(H).....FFFFFFFF(H)
		    0....4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_exp05_u32_u8(uint32 value, uint8 count)
{
	/* ## Operation body start [f2553db0-ab27-45d3-b771-d6d40cdd2fa4] */

	/*~A*/
	/*~+:Description*/
	/*
FUNCTION:  u32_exp05_u32_u8                                                   

      Parameter   type       Hex Range       Physical Range               

Input:                                                                    
       value       uint32      0..FFFFFFFF      0..4294967295                
       count       uint8       0..F             0..15                        

Output:                                                                   
       res         uint32      0..FFFFFFFF      0..4294967295                

functionality:                                                            
        count=count%16                                                    
        res=value>>count                                                  
	 */

	/*~E*/
	/* count (count %= 32) limited internal by HW to (0..31) */
	return (value >> count);

	/* ## Operation body end [f2553db0-ab27-45d3-b771-d6d40cdd2fa4] */
}

/** This operation shall rotate an uint32 value a given number of bits (max. 31) to the right (no check of number of bits)

@param value value to be rotated right

Range:		00(H)........FFFFFFFF(H)
		     0.....4294967295
@param count number of bits by which value has to be rotated

Range:		00(H)........1F(H)
		     0.......31
@return Value rotated by count

Range:		00(H).......FFFFFFFF(H)
		     0 ... 4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_rotr_u32_u16(uint32 value, uint16 count)
{
	/* ## Operation body start [1bc13ec6-0f05-4014-a555-ac6ea6abde32] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION:  u32_rotr_u32_u16                                                  

      Parameter   type       Hex Range      Physical Range                

Input:                                                                    
       value      uint32       0..FFFFFFFF     0..4294967295                 
       count      uint16       0..1F           0..31                         

Output:                                                                   
       res        uint32       0..FFFFFFFF     0..4294967295                 

functionality:                                                            
        if(count >32), count=count%32                                     
        if(count==0)                                                      
           res=value;                                                     
        else                                                              
           res=value rotated right by count                               
	 */

	/*~E*/
	uint32 temp1,temp2;
	if (count > 32U)
	{
		count %= 32U;
	}
	if (count == 0U)
	{
		res_ret =  value;
	}
	else
	{
		temp1 = value >> count;
		temp2 = value << (32U - count);
		temp1 = (uint32)temp1 + (uint32)temp2;
		res_ret =  temp1;

	}
	return res_ret ;
	/* ## Operation body end [1bc13ec6-0f05-4014-a555-ac6ea6abde32] */
}

/** This operation shall rotate an uint32 value a given number of bits (max. 31) to the left (no check of number of bits)

@param value value to be rotated left

Range:		00(H)........FFFFFFFF(H)
		     0.....4294967295
@param count number of bits by which value has to be rotated

Range:		00(H)........1F(H)
		     0.......31
@return Value rotated by count

Range:		00(H).......FFFFFFFF(H)
		     0 ... 4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_rotl_u32_u16(uint32 value, uint16 count)
{
	/* ## Operation body start [dd22abbc-a3c2-4cbb-a8da-d6913983f6f8] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION:  u32_rotl_u32_u16                                                  

      Parameter   type       Hex Range      Physical Range                

Input:                                                                    
       value      uint32       0..FFFFFFFF     0..4294967295                 
       count      uint16       0..1F           0..31                         

Output:                                                                   
       res        uint32       0..FFFFFFFF     0..4294967295                 

functionality:                                                            
        if(count >32), count=count%32                                     
        if(count==0)                                                      
           res=value;                                                     
        else                                                              
           res=value rotated left  by count                               
	 */

	/*~E*/
	uint32 temp1,temp2;

	if (count > 32U)
	{
		count %= 32U;
	}
	if (count == 0U)
	{
		res_ret =  value;
	}
	else
	{
		temp1 = value << count;
		temp2 = value >> (32U - count);
		temp1 = (uint32)temp1 + (uint32)temp2;
		res_ret =  temp1;

	}
	return res_ret ;
	/* ## Operation body end [dd22abbc-a3c2-4cbb-a8da-d6913983f6f8] */
}

/** This operation shall return the absolute of an sint16 value

@param value Value whose absolute has to be returned

Range:		8000(H)......7FFF(H)
		  -32768.....32767
@return Absolute value

Range:		00(H)......FFFF(H)
		    0.....65535 */
#include "iopt_memmap.h"

static inline  uint16 u16_abs_s16(sint16 value)
{
	/* ## Operation body start [2ed69f45-2457-44f3-8faf-df87f05cb085] */
	uint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u16_abs_s16                                                       

         Parameter         type      Hex Range      Physical Range        

Input:                                                                    
         value             sint16       8000..7FFF     -32768..32767         

Output:                                                                   
         res               uint16        0..FFFF         0..65535            

Functionality:                                                            
        res = |value|                                                     
	 */

	/*~E*/
	if (value >= (sint16)U16_MIN)
	{
		res_ret =  (uint16)value;
	}
	else
	{
		res_ret =  (uint16)(-value);
	}
	return res_ret ;
	/* ## Operation body end [2ed69f45-2457-44f3-8faf-df87f05cb085] */
}

/** This operation shall return the absolute of an sint16 value with overflow limitation. (For the input value of -32768, the output value is limited to 32767)

@param value Value whose absolute has to be returned

Range:		8000(H)......7FFF(H)
		  -32768.....32767
@return Absolute value
Limit overflow to: 0x7FFF

Range:		00(H)......7FFF(H)
		   0.....32767 */
#include "iopt_memmap.h"

static inline  sint16 s16_abs_s16(sint16 value)
{
	/* ## Operation body start [c1b2f434-2ec4-48fb-b718-cc0908490263] */
	sint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s16_abs_s16                                                       

         Parameter        type      Hex Range       Physical Range        

Input:                                                                    
         value            sint16       8000..7FFF      -32768..32767         

Output:                                                                   
         res              sint16       8000..7FFF      -32768..32767         
         Actual result    sint16       0000..7FFF           0..32767         
Functionality:                                                            
        res = |value|                                                     
        overflow : limit to 7FFFH                                         
	 */

	/*~E*/
	if (value == S16_MIN)
	{
		res_ret =  S16_MAX;
	}
	else
	{
		if (value >= (sint16)U16_MIN)
		{
			res_ret =  (sint16)value;
		}
		else
		{
			res_ret =  (sint16)(-value);
		}
	}
	return res_ret ;
	/* ## Operation body end [c1b2f434-2ec4-48fb-b718-cc0908490263] */
}

/** This operation shall convert an sint16 value to an sint8 value with overflow and underflow limitations

@param value Value to be converted

Range:		8000(H)......7FFF(H)
		  -32768.....32767
@return result
Limit overflow to:   0x7F
Limit underflow to: 0x80

Range:		80(H).........7F(H)
		   -128......127 */
#include "iopt_memmap.h"

static inline  sint8 s8_s16(sint16 value)
{
	/* ## Operation body start [8978c2d8-e055-4f86-8df7-649a15adb544] */
	sint8 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s8_s16                                                           

         Parameter         type      Hex Range       Physical Range       

Input:                                                                    
         value             sint16       8000..7FFF      -32768..32767        

Output:                                                                   
         res               sint8          80..7F          -128..127          

Functionality:                                                            
        res = value                                                       
        overflow : limit to 7FH                                           
        underflow: limit to 80H                                           
	 */

	/*~E*/
	if (value >= S8_MAX)
	{
		res_ret =  S8_MAX;
	}
	else
	{
		if (value <= S8_MIN)
		{
			res_ret =  S8_MIN;
		}
		else
		{
			res_ret =  (sint8)value;
		}
	}
	return res_ret ;
	/* ## Operation body end [8978c2d8-e055-4f86-8df7-649a15adb544] */
}

/** This operation shall multiply an sint16 value by an uint16 value and shift the product right by a specified number of bits (count) with overflow and underflow limitations

@param val1 First value

Range:      8000(H)......7FFF(H)
          -32768.....32767
@param val2 Second value

Range:      00(H)......FFFF(H)
           0......65535
@param count number of bits by which product has to be shifted

Range:      00(H)........0F(H)
             0.......15
@return (val1 * val2) >> count 
Limit overflow to:   0x7FFF
Limit underflow to: 0x8000

Range:      8000(H)......7FFF(H)
          -32768.....32767 */
#include "iopt_memmap.h"

static inline  sint16 s16_mul_s16_u16_exp05_u8(sint16 val1, uint16 val2, uint8 count)
{
	/* ## Operation body start [8ae1de36-2dec-4656-a426-b020c95bb952] */
	sint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION:  s16_mul_s16_u16_exp05_u8                                            

         Parameter        type       Hex Range       Physical Range       

Input:                                                                    
         val1              sint16      8000..7FFF       -32768..32767        
         val2              uint16         0..FFFF          0..65535          
         count             uint8          0..FF            0..255            

Output:                                                                   
         res               sint16      8000..7FFF       -32768..32767        

Functionality:                                                            
        res = (val1 * val2)>> count                                       
        overflow :  limit to 7FFFH                                        
        underflow : limit to 8000H                                        
	 */

	/*~E*/
	sint32 temp, denominator = 1;
	uint32 tmp_count = count;

	tmp_count %= 16U;
	denominator = (sint32)((uint32)denominator << tmp_count);
	/* multiply the values and shift right by number of bits as per the count */
	temp = ( (sint32)val1 * (sint32)val2) / denominator;
	/* compare result with maximum limit */
	if ( temp >= S16_MAX )
	{
		res_ret =  S16_MAX;
	}
	else
	{
		/* compare result with minimum limit */
		if ( temp <= S16_MIN )
		{
			res_ret =  S16_MIN;
		}
		else
		{
			res_ret =  (sint16)temp;
		}
	}
	return res_ret ;
	/* ## Operation body end [8ae1de36-2dec-4656-a426-b020c95bb952] */
}

/** This operation shall multiply an sint16 value by an uint16 value and shift the product left by a specified number of bits (count) with overflow and underflow limitations

@param val1 First value

Range:		8000(H)......7FFF(H)
		  -32768.....32767
@param val2 Second value

Range:		00(H)......FFFF(H)
		   0......65535
@param count number of bits by which product has to be shifted

Range:		00(H)........0F(H)
		     0.......15
@return (val1 * val2) << count 
Limit overflow to:   0x7FFF
Limit underflow to: 0x8000

Range:		8000(H)......7FFF(H)
		  -32768.....32767 */
#include "iopt_memmap.h"

static inline  sint16 s16_mul_s16_u16_exp2_u8(sint16 val1, uint16 val2, uint8 count)
{
	/* ## Operation body start [dc5a0668-d737-4903-b560-1c4cda5749da] */
	sint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION:  s16_mul_s16_u16_exp2_u8                                            

         Parameter        type         Hex Range       Physical Range     

Input:                                                                    
         val1              sint16         8000..7FFF      -32768..32767      
         val2              uint16          0..FFFF           0..65535        
         count             uint8            0..FF             0..255         

Output:                                                                   
         res               sint16         8000..7FFF      -32768..32767      

Functionality:                                                            
        res = (val1 * val2)<< count                                       
        overflow :  limit to 7FFFH                                        
        underflow : limit to 8000H                                        
	 */

	/*~E*/
	/*FUNCTION_ID:24*/
	sint32 temp;
	uint32 tmp_count = count;
	tmp_count %=16U;
	temp = ( (sint32)val1 * (sint32)val2 );

	/* compare if multiplication is greater than maximum limit */
	if ( temp >= S16_MAX )
	{
		res_ret =  S16_MAX;
	}
	else
	{
		/* compare if multiplication is less than minimum limit */
		if ( temp <= S16_MIN )
		{
			res_ret =  S16_MIN;
		}
		else
		{
			/* shift left the multiplication by number of bits as per the count */
			temp = (sint32)((uint32)temp << tmp_count);
			/* compare result with maximum limit */
			if ( temp >= S16_MAX )
			{
				res_ret =  S16_MAX;
			}
			else
			{
				/* compare result with minimum limit */
				if ( temp <= S16_MIN )
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
	return res_ret ;
	/* ## Operation body end [dc5a0668-d737-4903-b560-1c4cda5749da] */
}

/** This operation shall multiply two uint16 values and shift the product right by a specified number of bits (count) with overflow limitations

@param val1 First value

Range:		00(H)......FFFF(H)
		   0......65535
@param val2 Second value

Range:		00(H)......FFFF(H)
		   0......65535
@param count number of bits by which product has to be shifted

Range:		00(H)........0F(H)
		     0.......15
@return (val1 * val2) >> count 
Limit overflow to:   0xFFFF

Range:		00(H)......FFFF(H)
		   0.....65535 */
#include "iopt_memmap.h"

static inline  uint16 u16_mul_u16_u16_exp05_u8(uint16 val1, uint16 val2, uint8 count)
{
	/* ## Operation body start [59652b0e-1da3-4b15-bd68-ae464ef05b08] */
	uint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION:  u16_mul_u16_u16_exp05_u8                                            

         Parameter        type        Hex Range       Physical Range      

Input:                                                                    
         val1              uint16         0..FFFF          0..65535          
         val2              uint16         0..FFFF          0..65535          
         count             uint8          0..FF            0..15             

Output:                                                                   
         res               uint16         0..FFFF          0..65535          

Functionality:                                                            
        res = (val1 * val2)>> count                                       
        overflow : limit to FFFFH                                         
	 */

	/*~E*/
	uint32 temp, tmp_count = count;

	tmp_count %= 16U;
	/* multiply the two values and shift right by the number of bits as per the count */
	temp = ( (uint32)val1 * (uint32)val2 ) >> tmp_count;

	/* compare result with maximum limit */
	if ( temp >= U16_MAX )
	{
		res_ret =  U16_MAX;
	}
	else
	{
		res_ret =  (uint16)temp;
	}
	return res_ret ;
	/* ## Operation body end [59652b0e-1da3-4b15-bd68-ae464ef05b08] */
}

/** This operation shall multiply two uint16 values and shift the product left by a specified number of bits (count) with overflow limitations

@param val1 First value

Range:		00(H)......FFFF(H)
		   0......65535
@param val2 Second value

Range:		00(H)......FFFF(H)
		   0......65535
@param count number of bits by which product has to be shifted

Range:		00(H)........0F(H)
		     0.......15
@return (val1 * val2) << count 
Limit overflow to:   0xFFFF

Range:		00(H)......FFFF(H)
		   0.....65535 */
#include "iopt_memmap.h"

static inline  uint16 u16_mul_u16_u16_exp2_u8(uint16 val1, uint16 val2, uint8 count)
{
	/* ## Operation body start [f9fe3ab2-473c-4774-8195-59c9896e6516] */
	uint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION:  u16_mul_u16_u16_exp2_u8                                            

         Parameter        type         Hex Range       Physical Range     

Input:                                                                    
         val1              uint16         0..FFFF          0..65535          
         val2              uint16         0..FFFF          0..65535          
         count             uint8          0..FF            0..15             

Output:                                                                   
         res               uint16         0..FFFF          0..65535          

Functionality:                                                            
        res = (val1 * val2)<< count                                       
        overflow : limit to FFFFH                                         
	 */

	/*~E*/
	uint32 temp, tmp_count = count;
	tmp_count %= 16U;
	temp = ((uint32)val1 * (uint32)val2);

	/* compare if multiplication is greater than maximum limit */
	if ( temp > U16_MAX )
	{
		res_ret =  U16_MAX;
	}
	else
	{
		/* left shift the multiplication by number of bits as per the count */
		temp = temp << tmp_count;

		/* comapare the result with maxium limit */
		if ( temp >= U16_MAX )
		{
			res_ret =  U16_MAX;
		}
		else
		{
			res_ret =  (uint16)temp;
		}
	}
	return res_ret ;
	/* ## Operation body end [f9fe3ab2-473c-4774-8195-59c9896e6516] */
}

/** This operation shall convert an sint32 value to an uint16 value with overflow and underflow limitation

@param value value to be type converted

Range:		80000000(H)........7FFFFFFF(H)
		 -2147483648.......2147483647
@return value
Limit overflow to: 0xFFFF (65535)
Limit underflow to: 0x00 (0)

Range:		00(H)......FFFF(H)
		    0 ... 65535 */
#include "iopt_memmap.h"

static inline  uint16 u16_s32(sint32 value)
{
	/* ## Operation body start [08e58ae7-853c-4319-b327-5d79c4b69d16] */
	uint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION:  u16_s32                                                            

         Parameter     type       Hex Range            Physical Range       

Input:                                                                      
         val           sint32      80000000..7FFFFFFF  -2147483648..2147483647 

Output:                                                                     
         res           uint16          0000..FFFF                0..65535      

Functionality:                                                              
         val                                                                
         limit overflow to:  FFFFH (65535)                                  
         limit underflow to: 0000H  (0)                                     
	 */

	/*~E*/
	if (value >= (sint32)U16_MAX)
	{
		res_ret =  U16_MAX;
	}
	else
	{
		if (value <= (sint32)U16_MIN)
		{
			res_ret =  U16_MIN;
		}
		else
		{
			res_ret =  (uint16)value;
		}
	}
	return res_ret ;
	/* ## Operation body end [08e58ae7-853c-4319-b327-5d79c4b69d16] */
}

/** This operation shall shift an sint16 value by a given number of bits to the left specified by uint8 with overflow and underflow limitation (no check of number of bits) and return a result of sint16 type

@param data Data to be shifted

Range:		8000(H)......7FFF(H)
		  -32768.....32767
@param bits number of bits by which data has to be shifted

Range:		00(H)........0F(H)
		     0.......15
@return value << bits
Limit overflow to:   0x7FFF(32767) 
Limit underflow to: 0x8000 (-32768)

Range:		8000(H)......7FFF(H)
		   -32768 ... 32767 */
#include "iopt_memmap.h"

static inline  sint16 s16_exp2_s16_u8(sint16 data, uint8 bits)
{
	/* ## Operation body start [0c4d945c-4d47-455a-b468-d70d1bbbdc6b] */
	sint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION:  s16_exp2_s16_u8                                                   

         Parameter      type      Hex Range         Physical Range        

Input:                                                                    
       value            sint16       8000..7FFF        -32768..32767         
       bits             uint8          0..0F               0..15             
Output:                                                                   
       res              sint16       8000..7FFF        -32768..32767         

Functionality:                                                            
         bits%=16                                                         
         value << bits                                                    
         limit overflow to : 7FFF   ( 32767)                              
         limit underflow to: 8000   (-32768)                              
         range of result   : 8000..7FFF                                 */

	/*~E*/
	sint32 temp;
	uint32 tmp_bits;
	temp = (sint32)data;
	tmp_bits=(uint32)bits;
	tmp_bits %=16U;
	temp = (sint32)(((uint32)temp) <<tmp_bits);
	/*Check for Overflow*/
	if (temp>S16_MAX)
	{
		res_ret =  S16_MAX;
	}
	else
	{
		/*Check for Underflow*/
		if (temp <S16_MIN)
		{
			res_ret =  S16_MIN;
		}
		else
		{
			res_ret =  (sint16)temp;
		}
	}
	return res_ret ;
	/* ## Operation body end [0c4d945c-4d47-455a-b468-d70d1bbbdc6b] */
}

/** This operation shall shift an uint16 value by a given number of bits to the left specified by uint8 with overflow limitation (no check of number of bits) and return a result of uint16 type

@param data Data to be shifted

Range:		00(H).....FFFF(H)
	 	     0.....65535
@param bits number of bits by which data has to be shifted

Range:		00(H)........0F(H)
		     0.......15
@return value << bits
Limit overflow to:   0xFFFF(65535) 

Range:		00(H)......FFFF(H)
		   0......65535 */
#include "iopt_memmap.h"

static inline  uint16 u16_exp2_u16_u8(uint16 data, uint8 bits)
{
	/* ## Operation body start [85d7121b-7e4b-4dc1-b82c-56bdec2cc92c] */
	uint16 res_ret;
	/*~A*/
	/*~+:Desription*/
	/*
FUNCTION:  u16_exp2_u16_u8                                                   

         Parameter     type      Hex Range         Physical Range         

Input:                                                                    
       value           uint16       0..FFFF             0..65535             
       bits            uint8        0..0F               0..15                
Output:                                                                   
       res             uint16       0..FFFF             0..65535             

Functionality:                                                            
         value << bits                                                    
         Limit overflow to : FFFF (65535)                                 
         Range of result   : 0..FFFF                                    */

	/*~E*/
	uint32 temp,tmp_bits;

	tmp_bits=(uint32)bits;
	temp =(uint32)data;

	if (tmp_bits > 15U)
	{
		if (temp >0U)
		{
			res_ret =  U16_MAX;
		}
		else
		{
			res_ret =  U16_MIN;
		}
	}
	else
	{
		temp = temp <<tmp_bits;

		/*Check for Overflow*/
		if (temp>U16_MAX)

		{
			res_ret = (U16_MAX);
		}
		else
		{
			res_ret =  (uint16)temp;
		}
	}
	return res_ret ;
	/* ## Operation body end [85d7121b-7e4b-4dc1-b82c-56bdec2cc92c] */
}

/** This operation shall multiply two sint16 values and shift the result right by count specified in the uint8 value and return an sint16 value with overflow and underflow limitation

@param x First value

Range:		8000(H)......7FFF(H)
		  -32768.....32767
@param y Second value

Range:		8000(H)......7FFF(H)
		  -32768.....32767
@param count number of bits by which product has to be shifted

Range:		00(H)........0F(H)
		     0.......15
@return (x * y) >> count
Limit overflow to:   0x7FFF(32767) 
Limit underflow to: 0x8000 (-32768)

Range:		8000(H)......7FFF(H)
		   -32768 ... 32767 */
#include "iopt_memmap.h"

static inline  sint16 s16_mul_s16_s16_exp05_u8(sint16 x, sint16 y, uint8 count)
{
	/* ## Operation body start [4e23c721-4993-49e5-866e-5eff35eec64e] */
	sint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION:  s16_mul_s16_s16_exp05_u8                                            

         Parameter   type      Hex Range    Physical Range                

Input:                                                                    
         val1        sint16      8000..7FFF    -32768..32767                 
         val2        sint16      8000..FFFF    -32768..32767                 
         count       uint8          0..0F           0..15                    

Output:                                                                   
         res         sint16      8000..7FFF    -32768..32767                 

Functionality:                                                            
        res = (val1 * val2)>> count                                       
        overflow :  limit to 7FFFH                                        
        underflow : limit to 8000H                                        
	 */

	/*~E*/
	/*FUNCTION ID:31 */
	sint32 temp_result;

	if (count > 15U)
	{
		count %= 16U;
	}
	temp_result=(sint32)x*(sint32)y;
	temp_result = /*lint --e(704) */(temp_result >>count);

	if (temp_result> S16_MAX)
	{
		res_ret =  (S16_MAX);
	}
	else
	{
		if (temp_result <S16_MIN)
		{
			res_ret =  (S16_MIN);
		}
		else
		{
			res_ret =  (sint16)temp_result;
		}
	}
	return res_ret ;
	/* ## Operation body end [4e23c721-4993-49e5-866e-5eff35eec64e] */
}

/** This operation shall convert an sint8 value to an uint8 value with underflow limitation

@param value Value to be type converted

Range:		80(H)......7F(H)
		  -128.....127
@return result
Limit underflow to: 0x00 (0)

Range:		00(H)....7F(H)
		     0...127 */
#include "iopt_memmap.h"

static inline  uint8 u8_s8(sint8 value)
{
	/* ## Operation body start [478d3fc2-4f56-4243-b4d2-4cd437318aee] */
	uint8 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u8_s8                                                           

         Parameter        type       Hex Range       Physical Range       

Input:                                                                    
         value             sint8         80..7F           -128..127          

Output:                                                                   
         res               uint8         00..7F             0..127           

Functionality:                                                            
       Change a signed char to an unsigned char with underflow limitation.
       Underflow: Limit to 00H                                            
	 */

	/*~E*/
	/* Check for Underflow*/
	if ( value <= (sint8)U8_MIN )
	{
		res_ret =  U8_MIN;
	}
	else
	{
		res_ret =  (uint8)value;
	}
	return res_ret ;
	/* ## Operation body end [478d3fc2-4f56-4243-b4d2-4cd437318aee] */
}

/** This operation shall convert an sint16 value to an uint8 value with overflow and underflow limitation

@param value Value to be type converted

Range:		8000(H)......7FFF(H)
		  -32768.....32767
@return result
Limit overflow to:   0xFF (255)
Limit underflow to: 0x00 (0)

Range:		00(H)....FF(H)
		     0...255 */
#include "iopt_memmap.h"

static inline  uint8 u8_s16(sint16 value)
{
	/* ## Operation body start [ef7e8348-def1-4886-a98b-c5df4c318693] */
	uint8 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u8_s16                                                           

       Parameter   type      Hex Range             Physical Range         

Input:                                                                    
         value     sint16       8000..7FFF            -32768..32767          

Output:                                                                   
         res       uint8          00..FF                  0..255             

Functionality:                                                            
        res = value converted from signed int to unsigned char with       
        overflow and underflow limitation                                 

        overflow : limit to FFH                                           
        underflow : limit to 00H                                        */

	/*~E*/
	/* Check for Overflow */
	if ( value >= (sint16)U8_MAX )
	{
		res_ret =  U8_MAX;
	}
	else
	{
		/* Check for Underflow */
		if ( value <= (sint8)U8_MIN )
		{
			res_ret =  U8_MIN;
		}
		else
		{
			res_ret =  (uint8)value;
		}
	}
	return res_ret ;
	/* ## Operation body end [ef7e8348-def1-4886-a98b-c5df4c318693] */
}

/** This operation shall return the absolute of an sint8 value

@param value Value whose absolute has to be returned

Range:		80(H)......7F(H)
		  -128.....127
@return  result 

Range:		00(H).....FF(H)
		     0.....255 */
#include "iopt_memmap.h"

static inline  uint8 u8_abs_s8(sint8 value)
{
	/* ## Operation body start [708a509a-4593-40b6-a2b9-9f984e642771] */
	uint8 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u8_abs_s8                                                       

         Parameter         type      Hex Range       Physical Range       

Input:                                                                    
         value              sint8        80..7F           -128..127          

Output:                                                                   
         res                uint8        0..FF              0..255           

Functionality:                                                            
        res = |value|                                                     
	 */

	/*~E*/
	/* Check for positive number */
	if ( value >= (sint8)U8_MIN )
	{
		/* Return the positive input as output after type conversion */
		res_ret =  (uint8)value;
	}
	else
	{
		/* Convert the negative input to absolute value(positive) and return output after type conversion */
		res_ret =  (uint8)(-value);
	}
	return res_ret ;
	/* ## Operation body end [708a509a-4593-40b6-a2b9-9f984e642771] */
}

/** This operation shall convert an uint8 value to an sint8 value with overflow limitation

@param value Value to be type converted

Range of results:	00(H)....FF(H)
			     0...255
@return result
Limit overflow to: 0x7F (127)

Range:		00(H)......7F(H)
		    0.....127 */
#include "iopt_memmap.h"

static inline  sint8 s8_u8(uint8 value)
{
	/* ## Operation body start [9c8d86ad-c893-4f5b-ab2d-4bc3505aada2] */
	sint8 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s8_u8                                                                

         Parameter        type          Hex Range         Physical Range       

Input:                                                                         
         value             uint8             0..FF               0..255           

Output:                                                                        
         res               sint8            00..7F               0..127           

Functionality:                                                                 
         Change a unsigned char to an signed char with overflow limitation.    
         Overflow: Limit to 7FH                                                
	 */

	/*~E*/
	/* Check for Overflow */
	if ( value >= (uint8)S8_MAX )
	{
		res_ret =  S8_MAX;
	}
	else
	{
		res_ret =  (sint8)value;
	}
	return res_ret ;
	/* ## Operation body end [9c8d86ad-c893-4f5b-ab2d-4bc3505aada2] */
}

/** This operation shall convert an uint16 value to an sint8 value with overflow limitation

@param value Value to be type converted

Range of results:	00(H)....FFFF(H)
			     0...65535
@return result
Limit overflow to: 0x7F (127)

Range:		00(H)......7F(H)
		    0.....127 */
#include "iopt_memmap.h"

static inline  sint8 s8_u16(uint16 value)
{
	/* ## Operation body start [939a825e-9a60-4c6d-b248-b2149eaadd89] */
	sint8 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s8_u16                                                                

         Parameter        type          Hex Range         Physical Range       

Input:                                                                         
         value             uint16          0000..FFFF           0..65535          

Output:                                                                        
         res               sint8            00..7F              0..127            

Functionality:                                                                 
         Change an unsigned int to a signed char with overflow limitation.     
         Overflow: Limit to 7FH                                                
	 */

	/*~E*/
	/* Check for Overflow */
	if ( value >= (uint8)S8_MAX )
	{
		res_ret =  S8_MAX;
	}
	else
	{
		res_ret =  (sint8)value;
	}
	return res_ret ;
	/* ## Operation body end [939a825e-9a60-4c6d-b248-b2149eaadd89] */
}

/** This operation shall return the absolute of an sint8 value with overflow limitation

@param value Value whose absolute has to be returned

Range:		80(H)......7F(H)
		  -128.....127
@return  result 
Limit overflow to: 0x7F (127)

Range:		00(H)......7F(H)
		    0.....127 */
#include "iopt_memmap.h"

static inline  sint8 s8_abs_s8(sint8 value)
{
	/* ## Operation body start [0e995da6-aaef-4a05-aa19-021f4f8ac94e] */
	sint8 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s8_abs_s8                                                           

         Parameter        type       Hex Range          Physical Range        

Input:                                                                        
         value            sint8          80..7F              -128..127           

Output:                                                                       
         res              sint8          80..7F              -128..127           

Functionality:                                                                
        res = |value|                                                         
        Overflow : Limit to 7FH                                               
	 */

	/*~E*/
	/*Check if input equal to 0x080*/
	if ( value == S8_MIN )
	{
		/*Input equals 0x080. Return 0x07F*/
		res_ret =  S8_MAX;
	}
	else
	{
		/* Check for positive number */
		if ( value >= (sint32)U8_MIN )
		{
			/* Return the positive input as output after type conversion */
			res_ret =  (sint8)value;
		}
		else
		{
			/* Convert the negative input to absolute value(positive) and return output after type conversion */
			res_ret =  (sint8)(-value);
		}
	}
	return res_ret ;
	/* ## Operation body end [0e995da6-aaef-4a05-aa19-021f4f8ac94e] */
}

/** This operation shall convert an uint32 value to an sint16 value with overflow limitation

@param value value to be type converted

Range:		00(H)........FFFFFFFF(H)
		     0.....4294967295
@return result
Limit overflow to: 0x7FFF (32767)

Range:		00(H)......7FFF(H)
		   0.....32767 */
#include "iopt_memmap.h"

static inline  sint16 s16_u32(uint32 value)
{
	/* ## Operation body start [3720e008-d9bb-4185-a183-acf316a3e0de] */
	sint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s16_u32                                                                   

         Parameter        type         Hex Range            Physical Range        

Input:                                                                            
         value            uint32      00000000..FFFFFFFF        0..4294967295        

Output:                                                                           
         res              sint16              0..7FFF           0..32767             

Functionality:                                                                    
         Change an unsigned long to a signed int with overflow limitation.        
         Overflow: Limit to 7FFFH                                                 
	 */

	/*~E*/
	/* Check for Overflow */
	if ( value >= (uint32)S16_MAX )
	{
		res_ret =  S16_MAX;
	}
	else
	{
		res_ret =  (sint16)value;
	}
	return res_ret ;
	/* ## Operation body end [3720e008-d9bb-4185-a183-acf316a3e0de] */
}

/** This operation shall convert an sint32 value to an uint32 value with underflow limitation

@param value value to be type converted

Range:		80000000(H)........7FFFFFFF(H)
		 -2147483648.......2147483647
@return result
Limit underflow to: 0x00 (0)

Range:		00(H)....7FFFFFFF(H)
		     0...2147483647 */
#include "iopt_memmap.h"

static inline  uint32 u32_s32(sint32 value)
{
	/* ## Operation body start [29dafea5-e9c2-4db3-bab5-5afb801a8a7f] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u32_s32                                                                    

         Parameter        type          Hex Range          Physical Range          

Input:                                                                             
         value            sint32     80000000..7FFFFFFF  -2147483648..2147483647      

Output:                                                                            
         res              uint32     00000000..7FFFFFFF     0..2147483647             

Functionality:                                                                     
         Change a signed long to an unsigned long with underflow limitation.       
         Underflow: Limit to 00000000H                                             
	 */

	/*~E*/
	/* Check for Underflow*/
	if ( value < (sint32)(U32_MIN) )
	{
		res_ret =  U32_MIN;
	}
	else
	{
		res_ret =  (uint32)value;
	}
	return res_ret ;
	/* ## Operation body end [29dafea5-e9c2-4db3-bab5-5afb801a8a7f] */
}

/** This operation shall return the absolute of an sint32 value

@param value Value whose absolute has to be returned

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648....2147483647
@return  result 

Range:		00(H).....FFFFFFFF(H)
		   0.....4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_abs_s32(sint32 value)
{
	/* ## Operation body start [2bda287c-23ab-4992-ab45-b1ec156e612e] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u32_abs_s32                                                          

         Parameter    type       Hex Range           Physical Range          

Input:                                                                       
         value        sint32   80000000..7FFFFFFF  -2147483648..2147483647      

Output:                                                                      
         res          uint32   00000000..FFFFFFFF       0..4294967295           

Functionality:                                                               
        res = |value|                                                        
	 */

	/*~E*/
	/* Check for positive number */
	if ( value >= (sint32)(U32_MIN) )
	{
		/* Return the positive input as output after type conversion */
		res_ret =  (uint32)value;
	}
	else
	{
		/* Convert the negative input to absolute value(positive) and return output after type conversion */
		res_ret =  (uint32)(-value);
	}
	return res_ret ;
	/* ## Operation body end [2bda287c-23ab-4992-ab45-b1ec156e612e] */
}

/** This operation shall convert an uint32 value to an sint32 value with overflow limitation

@param value value to be type converted

Range:		00(H)........FFFFFFFF(H)
		     0.....4294967295
@return result
Limit overflow to: 0x7FFFFFFF (2147483647)

Range:		00(H)......7FFFFFFF(H)
		    0.....2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_u32(uint32 value)
{
	/* ## Operation body start [d67c6419-2fe9-4ec3-b295-ccb3b4febe5f] */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s32_u32                                                                   

         Parameter        type         Hex Range            Physical Range        

Input:                                                                            
         value            uint32      00000000..FFFFFFFF       0..4294967295         

Output:                                                                           
         res              sint32      80000000..7FFFFFFF   -2147483648..2147483647   

Functionality:                                                                    
         Change an unsigned long to a signed long with overflow limitation.       
         Overflow: Limit to 7FFFFFFFH                                             
	 */

	/*~E*/
	/* Check for Overflow */
	if ( value >= (uint32)S32_MAX )
	{
		res_ret =  S32_MAX;
	}
	else
	{
		res_ret =  (sint32)value;
	}
	return res_ret ;
	/* ## Operation body end [d67c6419-2fe9-4ec3-b295-ccb3b4febe5f] */
}

/** This operation shall return the absolute of an sint32 value with overflow limitation

@param value Value whose absolute has to be returned

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648....2147483647
@return  result 
Limit overflow to: 0x7FFFFFF (2147483647)

Range:		00(H)......7FFFFFFF(H)
		     0.....2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_abs_s32(sint32 value)
{
	/* ## Operation body start [09ba094f-b38e-4889-b235-07658986b9bd] */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s32_abs_s32                                                               

         Parameter        type        Hex Range               Physical Range       

Input:                                                                             
         value            sint32    80000000..7FFFFFFF       -2147483648..2147483647  

Output:                                                                            
         res              sint32    80000000..7FFFFFFF       -2147483648..2147483647  

Functionality:                                                                     
        res = |value|                                                              
        Overflow : Limit to 7FFFFFFFH                                              
	 */

	/*~E*/
	/*Check if input equal to 0x080000000*/
	if ( value == S32_MIN )
	{
		/*Input equals 0x080000000. Return 0x07FFFFFFF*/
		res_ret =  S32_MAX;
	}
	else
	{
		/* Check for positive number */
		if ( value >= (sint32)(U32_MIN) )
		{
			/* Return the positive input as output after type conversion */
			res_ret =  (sint32)value;
		}
		else
		{
			/* Convert the negative input to absolute value(positive) and return output after type conversion */
			res_ret =  (sint32)(-value);
		}
	}
	return res_ret ;
	/* ## Operation body end [09ba094f-b38e-4889-b235-07658986b9bd] */
}

/** This operation shall shift an sint16 value a given number of bits (count) to the right (no check of number of bits) and return sint8 result with overflow and underflow limitation

@param value Value to be shifted right

Range:		8000(H)......7FFF(H)
		  -32768.....32767
@param count number of bits by which value has to be shifted

Range:		00(H)........0F(H)
		     0.......15
@return value >> count
Limit overflow to:   0x7F (127)
Limit underflow to: 0x80 (-128)

Range:		80(H).......7F(H)
		  -128.....127 */
#include "iopt_memmap.h"

static inline  sint8 s8_exp05_s16_u8(sint16 value, uint8 count)
{
	/* ## Operation body start [fb1fa4cd-9c6b-43ff-8aec-dfc8cb61c9cc] */
	sint8 res_ret;
	/*~A*/
	/*~+:Description*/
	/*FUNCTION: s8_exp05_s16_u8

         Parameter        type       Hex Range       Physical Range   

Input:                                                                
         value             sint16       8000..7FFF      -32768..32767    
         count             uint8           0..F              0..15       
Output:                                                               
         res               sint8         80..7F           -128..127      

Functionality:                                                        
        temp_factor = 1<< count                                       
        res=value/temp_factor                                         
        overflow : limit to 7FH                                       
        underflow: limit to 80H                                       
	 */

	/*~E*/
	/*FUNCTION_ID:43*/
	sint32 temp_value;
	uint32 temp_factor,temp_count;

	temp_count=(uint32)count;
	temp_value=(sint32)value;

	/* Modulo operation to limit the count value to a value below 16*/
	temp_count%=16U;

	temp_factor=((uint32)1<<temp_count);
	temp_value = temp_value / (sint32)temp_factor;

	/*Check for Overflow*/
	if (temp_value >= S8_MAX)
	{
		res_ret =  S8_MAX;
	}
	else
	{
		/*Check for underflow*/
		if (temp_value <= S8_MIN)
		{
			res_ret =  S8_MIN;
		}
		else
		{
			res_ret =  (sint8)temp_value;
		}
	}
	return res_ret ;
	/* ## Operation body end [fb1fa4cd-9c6b-43ff-8aec-dfc8cb61c9cc] */
}

/** This operation shall shift an sint16 value by a given number of bits to the left specified by uint8 with overflow and underflow limitation (no check of number of bits) and return a result of uint16 type

@param value Value to be shifted left

Range:		8000(H)......7FFF(H)
		  -32768.....32767
@param count number of bits by which value has to be shifted

Range:		00(H)........0F(H)
		     0.......15
@return value << bits
Limit overflow to:   0xFFFF (65535)
Limit underflow to: 0x00 (0) 

Range:		00(H)......FFFF(H)
		   0......65535 */
#include "iopt_memmap.h"

static inline  uint16 u16_exp2_s16_u8(sint16 value, uint8 count)
{
	/* ## Operation body start [3ede33a1-3ee5-43b7-b8ce-30b091de2f57] */
	uint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*FUNCTION:  u16_exp2_s16_u8

         Parameter         type      Hex Range       Physical Range   

Input:                                                                
         value             sint16       8000..7FFF       -32768..32767   
         count             uint8           0..F               0..15      
Output:                                                               
         res               uint16       0000..FFFF            0..65535   

Functionality:                                                        
        res = value<<count                                            
        overflow : limit to FFFFH                                     
        underflow: limit to 0000H                                     
	 */

	/*~E*/
	sint32 temp_value;
	uint32 temp_count;

	temp_value=(sint32)value;
	temp_count=(uint32)count;

	/*Check for underflow*/
	if (temp_value < 0)
	{
		res_ret =  U16_MIN;
	}
	else
	{
		/* Modulo operation to limit the count value to a value below 16*/
		temp_count%=16U;
		temp_value = (sint32)((uint32)temp_value << temp_count);

		/*Check for Overflow*/
		if (temp_value > (sint32)U16_MAX)
		{
			res_ret =  U16_MAX;
		}
		else
		{
			res_ret =  (uint16)temp_value;

		}
	}

	return res_ret ;
	/* ## Operation body end [3ede33a1-3ee5-43b7-b8ce-30b091de2f57] */
}

/** This operation shall shift an sint16 value a given number of bits (count) to the right (no check of number of bits) and return uint8 result with overflow and underflow limitation

@param value Value to be shifted right

Range:		8000(H)......7FFF(H)
		  -32768.....32767
@param count number of bits by which value has to be shifted

Range:		00(H)........0F(H)
		     0.......15
@return value >> count
Limit overflow to:   0xFF (255)
Limit underflow to: 0x00 (0)

Range:		00(H).......FF(H)
		    0.....255 */
#include "iopt_memmap.h"

static inline  uint8 u8_exp05_s16_u8(sint16 value, uint8 count)
{
	/* ## Operation body start [197d2821-bcf5-4860-b987-3212170765e3] */
	uint8 res_ret;
	/*~A*/
	/*~+:Description*/
	/*FUNCTION:  u8_exp05_s16_u8

         Parameter        type        Hex Range      Physical Range 

Input:                                                              
         value             sint16       8000..7FFF     -32768..32767   
         count             uint8           0..F             0..15      
Output:                                                             
         res               uint8           0..FF            0..255     

Functionality:                                                      
        res = value>>count                                          
        overflow : limit to FFH                                     
        underflow: limit to 00H                                     
	 */

	/*~E*/
	/*FUNCTION_ID:45*/
	sint32 temp_value;
	uint32 temp_count;

	temp_count=(uint32)count;
	temp_value=(sint32)value;

	/* Modulo operation to limit the count value to a value below 16*/
	temp_count%=16U;
	temp_value = /*lint --e(704) */(temp_value >> temp_count);

	/*Check for Overflow*/
	if (temp_value >= (sint32)U8_MAX)
	{
		res_ret =  U8_MAX;
	}
	else
	{
		/*Check for underflow*/
		if (temp_value <= (sint32)U8_MIN)
		{
			res_ret =  U8_MIN;
		}
		else
		{
			res_ret =  (uint8)temp_value;
		}
	}
	return res_ret ;
	/* ## Operation body end [197d2821-bcf5-4860-b987-3212170765e3] */
}

/** This operation shall shift an uint16 value a given number of bits (count) to the right (no check of number of bits) and return uint8 result with overflow limitation

@param value Value to be shifted right

Range:			00(H)....FFFF(H)
			     0...65535
@param count number of bits by which value has to be shifted

Range:		00(H)........0F(H)
		     0.......15
@return value >> count
Limit overflow to:   0xFF (255)

Range:		00(H).......FF(H)
		    0.....255 */
#include "iopt_memmap.h"

static inline  uint8 u8_exp05_u16_u8(uint16 value, uint8 count)
{
	/* ## Operation body start [13cce908-0a5b-43db-a677-9e0e6ae001cb] */
	uint8 res_ret;
	/*~A*/
	/*~+:Description*/
	/*FUNCTION:  u8_exp05_u16_u8

         Parameter        type         Hex Range       Physical Range    

Input:                                                                   
         value             uint16         0000..FFFF        0..65535        
         count             uint8             0..F           0..15           
Output:                                                                  
         res               uint8            00..FF          0..255          

Functionality:                                                           
        value>>count                                                     
        overflow : limit to FFH                                          
	 */

	/*~E*/
	/*FUNCTION_ID:46*/
	uint32 temp_value,temp_count;
	temp_count=(uint32)count;
	temp_value=(uint32)value;

	/* Modulo operation to limit the count value to a value below 16*/
	temp_count%=16U;
	temp_value = temp_value >> temp_count;

	/*Check for Overflow*/
	if (temp_value >=U8_MAX)
	{
		res_ret =  U8_MAX;
	}
	else
	{
		res_ret =  (uint8)temp_value;
	}
	return res_ret ;
	/* ## Operation body end [13cce908-0a5b-43db-a677-9e0e6ae001cb] */
}

/** This operation shall convert an sint32 value to an sint8 value with over flow and underflow limitation

@param value Value to be type converted

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648....2147483647
@return result
Limit over flow to : 0x7F (127)
Limit underflow to: 0x80 (-128)

Range:		80(H).......7F(H)
                           -128....127 */
#include "iopt_memmap.h"

static inline  sint8 s8_s32(sint32 value)
{
	/* ## Operation body start [d5222b32-2ebd-4a48-9836-fa6a73e091f0] */
	sint8 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s8_s32                                                                  

         Parameter      type        Hex Range           Physical Range            

Input:                                                                            
         value          sint32    80000000..7FFFFFFF    -2147483648..2147483647      

Output:                                                                           
         res            sint8          80..7F                -128..127               

Functionality:                                                                    
        res = value                                                               
        overflow : limit to 7FH                                                   
        underflow: limit to 80H                                                   
	 */

	/*~E*/
	if (value >= S8_MAX)
	{
		res_ret =  S8_MAX;
	}
	else
	{
		if (value <= S8_MIN)
		{
			res_ret =  S8_MIN;
		}
		else
		{
			res_ret =  (sint8)value;
		}
	}
	return res_ret ;
	/* ## Operation body end [d5222b32-2ebd-4a48-9836-fa6a73e091f0] */
}

/** This operation shall convert an uint32 value to an uint8 value with overflow limitation

@param value Value to be type converted

Range:		00(H)........FFFFFFFF(H)
		     0.....4294967295
@return result
Limit overflow to : 0xFF (255)

Range:		00(H).....FF(H)
                             0....255 */
#include "iopt_memmap.h"

static inline  uint8 u8_u32(uint32 value)
{
	/* ## Operation body start [7977f1f8-4a46-4a50-a1e5-6e6c6fa53536] */
	uint8 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u8_u32                                                          

         Parameter      type       Hex Range        Physical Range        

Input:                                                                    
         value          uint32    0000000..FFFFFFFF     0..4294967295        

Output:                                                                   
         res            uint8          0..FF              0..255             

Functionality:                                                            
        conversion of unsigned long to unsigned char with overflow limitation  
        overflow : limit to FFH                                           
	 */

	/*~E*/
	if (value >= U8_MAX)
	{
		res_ret =  U8_MAX;
	}
	else
	{
		res_ret =  (uint8)value;
	}
	return res_ret ;
	/* ## Operation body end [7977f1f8-4a46-4a50-a1e5-6e6c6fa53536] */
}

/** This operation shall multiply an sint32 value by an sint32 value and shift the product right by a specified number of bits (count) with overflow and underflow  limitations

@param tmp_1 @param tmp_1  First value

 Range:     80000000(H).....7FFFFFFF(H)
         -2147483648....2147483647
@param tmp_2 @param tmp_2  Second value

 Range:     80000000(H).....7FFFFFFF(H)
         -2147483648....2147483647
@param shiftright @param shiftright  number of bits by which product has to be shifted

 Range:     input-range [0..63] 
@return @return  (val1 * val2) >> count 
 Limit overflow to:   0x7FFF
 Limit underflow to: 0x8000

Range:     80000000(H).....7FFFFFFF(H)
         -2147483648....2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_mul_s32_s32_exp05_u8(sint32 tmp_1, sint32 tmp_2, uint8 shiftright)
{
	/* ## Operation body start [f20936a0-c38b-4bbb-b0ca-57e7878846d3] */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/* shift:  input-range [0..63] */
	/* return:  ((sint64)tmp_1 * tmp_2) >> shift;  result limited to sint32 */

	/* should be similar to sint32_mul_sint32_sint32_div_u32 (tmp_1, tmp_2, 1<< shift); this function with MUCH LESS runtime */

	/*~E*/
	/*~A*/
	/*~+:Description of Lint supression*/
	/* Info 704: Use library functions for shift right and shift left. This PC-Lint info is disabled since a library must never use other libraries */

	/*~E*/
	sint64 temp_res;
	temp_res = ((sint64)tmp_1 * (sint64)tmp_2);
	temp_res = (temp_res >> shiftright);
	if (temp_res >= S32_MAX)
	{
		res_ret =  S32_MAX;
	}
	else
	{
		if (temp_res <= S32_MIN)
		{
			res_ret =  S32_MIN;
		}
		else
		{
			res_ret =  (sint32)temp_res;
		}
	}
	return res_ret ;
	/* ## Operation body end [f20936a0-c38b-4bbb-b0ca-57e7878846d3] */
}

/** This operation shall multiply an sint32 value by an uint32 value and shift the product right by a specified number of bits (count) with overflow and underflow limitations

@param tmp_1 @param tmp_1  First value

 Range:     80000000(H).....7FFFFFFF(H)
         -2147483648....2147483647
@param tmp_2 @param tmp_2  Second value

 Range:     00(H).....FFFFFFFF(H)
            0....4294967295
@param shiftright @param shiftright  number of bits by which product has to be shifted

Range:     00(H)........0F(H)
             0.......15
@return @return  (val1 * val2) >> count 
 Limit overflow to:   0x7FFF
 Limit underflow to: 0x8000

 Range:     80000000(H).....7FFFFFFF(H)
         -2147483648....2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_mul_s32_u32_exp05_u8(sint32 tmp_1, uint32 tmp_2, uint8 shiftright)
{
	/* ## Operation body start [3ab4ac13-ab02-4f5c-84ff-14098597916c] */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/* shift:  input-range [0..63] */
	/* return:  ((uint64)tmp_1 * tmp_2) >> shift;  result limited to sint32 */

	/* should be similar to s32_mul_s32_u32_div_u32 (tmp_1, tmp_2, 1<< shift); this function with MUCH LESS runtime */

	/*~E*/
	/*~A*/
	/*~+:Description of Lint supression*/
	/* Info 704: Use library functions for shift right and shift left. This PC-Lint info is disabled since a library must never use other libraries */

	/*~E*/
	sint64 temp_res;
	temp_res = ((sint64)tmp_1 * (sint64)tmp_2);
	temp_res = (temp_res >> shiftright);
	if (temp_res >= S32_MAX)
	{
		res_ret =  S32_MAX;
	}
	else
	{
		if (temp_res <= S32_MIN)
		{
			res_ret =  S32_MIN;
		}
		else
		{
			res_ret =  (sint32)temp_res;
		}
	}
	return res_ret ;
	/* ## Operation body end [3ab4ac13-ab02-4f5c-84ff-14098597916c] */
}

/** This operation shall multiply an uint32 value by an uint32 value and shift the product right by a specified number of bits (count) with overflow and underflow limitations

@param tmp_1 @param tmp_1  First value

 Range:     00(H).....FFFFFFFF(H)
            0....4294967295
@param tmp_2 @param tmp_2  Second value

 Range:     00(H).....FFFFFFFF(H)
            0....4294967295
@param shiftright @param shiftright  number of bits by which product has to be shifted

Range:     00(H)........0F(H)
             0.......15
@return @return  (val1 * val2) >> count 
 Limit overflow to:   0x7FFF
 Limit underflow to: 0x8000

 Range:     00(H).....FFFFFFFF(H)
            0....4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_mul_u32_u32_exp05_u8(uint32 tmp_1, uint32 tmp_2, uint8 shiftright)
{
	/* ## Operation body start [56d53b85-4973-4760-9632-ec430bb1c293] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/* shift:  input-range [0..63] */
	/* return:  ((uint64)tmp_1 * tmp_2) >> shift;  result limited to uint32 */

	/* should be similar to u32_mul_u32_u32_div_u32 (tmp_1, tmp_2, 1<< shift); this function with MUCH LESS runtime */

	/*~E*/
	uint64 temp_res;
	temp_res = ((uint64)tmp_1 * (uint64)tmp_2);
	temp_res = (temp_res >> shiftright);
	if (temp_res >= U32_MAX)
	{
		res_ret =  U32_MAX;
	}
	else
	{
		res_ret =  (uint32)temp_res;
	}
	return res_ret ;
	/* ## Operation body end [56d53b85-4973-4760-9632-ec430bb1c293] */
}

/** This operation shall shift an uint32 value by a given number of bits to the left specified by uint8 with overflow limitation (no check of number of bits) and return a result of uint32 type
@param data  Data to be shifted

 Range:		00(H).....FFFFFFFF(H)
 		    0....4294967295

@param shiftleft  number of bits by which data has to be shifted
 Range:		00(H)........0F(H)
 		     0.......31


          value << shiftleft, with Limit overflow (saturation) to : U32_MAX
    valid range of shiftleft:  [0..31] !

@param data Data to be shifted

Range:      00(H).....FFFFFFFF(H)
            0....4294967295
@param bits number of bits by which data has to be shifted

Range:      00(H)........1F(H)
             0.......31
@return value << bits
Limit overflow to:   0xFFFFFFFF(4294967295) 

Range:      00(H).....FFFFFFFF(H)
            0....4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_exp2_u32_u8(uint32 data, uint8 shiftleft)
{
	/* ## Operation body start [a2ee6f4b-e24a-4e5b-a4bb-b76580916dea] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*value << shiftleft, with Limit overflow (saturation) to : U32_MAX
    valid range of shiftleft:  [0..31] !*/
	/*SHL64U_INSTR: tmp = ((uint64)data << shiftleft), limited to U32_MAX */
	/*~E*/
	uint64 temp;
	if (shiftleft > 31U)
	{
		if (data > 0U)
		{
			res_ret =  U32_MAX;
		}
		else
		{
			res_ret =  U32_MIN;
		}
	}
	else
	{
		temp = ((uint64)data << (uint64)shiftleft);
		/*Check for Overflow*/
		if (temp>U32_MAX)

		{
			res_ret = (U32_MAX);
		}
		else
		{
			res_ret =  (uint32)temp;
		}
	}
	return res_ret ;
	/* ## Operation body end [a2ee6f4b-e24a-4e5b-a4bb-b76580916dea] */
}

/** This operation shall shift an uint32 value by a given number of bits to the left specified by uint8 with overflow limitation (no check of number of bits) and return a result of uint32 type
@param data  Data to be shifted

 Range:		80000000(H).....7FFFFFFF(H)
 		 -2147483648....2147483647

@param shiftleft  number of bits by which data has to be shifted

 Range:		00(H)........0F(H)
 		     0.......31

@param data Data to be shifted

 Range:		80000000(H).....7FFFFFFF(H)
 		 -2147483648....2147483647
@param shiftleft number of bits by which data has to be shifted

Range:      00(H)........1F(H)
             0.......31
@return value << bits
Limit overflow to:   0x7FFFFFFF(2147483647) 

 Range:     80000000(H).....7FFFFFFF(H)
         -2147483648....2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_exp2_s32_u8(sint32 data, uint8 shiftleft)
{
	/* ## Operation body start [8ec296fc-7803-4c2e-9398-51ef16151703] */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*value << shiftleft, with Limit overflow (saturation) to : U32_MAX
    valid range of shiftleft:  [0..31] !*/
	/*~E*/
	sint64 temp_data;
	temp_data = (sint64)data;
	temp_data = (sint64)(((uint64)temp_data) << (uint64)shiftleft);
	/*Check for Overflow*/
	if (temp_data > S32_MAX)
	{
		res_ret =  S32_MAX;
	}
	else
	{
		/*Check for Underflow*/
		if (temp_data < S32_MIN)
		{
			res_ret =  S32_MIN;
		}
		else
		{
			res_ret =  (sint32)temp_data;
		}
	}
	return res_ret ;
	/* ## Operation body end [8ec296fc-7803-4c2e-9398-51ef16151703] */
}

/** This operation shall shift an sint32 value a given number of bits (count) to the right (no check of number of bits)
@param value  value to be shifted right

 Range:     80000000(H)........7FFFFFFF(H)
         -2147483648.......2147483647
@param shiftright  number of bits by which value has to be shifted 

 Range:     00(H)........0F(H)
             0.......15

@param value value to be shifted right

Range:      80000000(H)........7FFFFFFF(H)
         -2147483648.......2147483647
@param shiftright number of bits by which value has to be shifted 

Range:      00(H)........0F(H)
             0.......15
@return value >> count

Range        sint16       8000..7FFF */
#include "iopt_memmap.h"

static inline  sint16 s16_exp05_s32_u8(sint32 value, uint8 shiftright)
{
	/* ## Operation body start [48f68628-931a-49e9-95e3-565f8fcd1cb8] */
	sint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*value << shiftleft, with Limit overflow (saturation) to : U32_MAX
    valid range of shiftleft:  [0..31] !

Functionality:
        res=value>>count, saturated to sint16

	 */
	/*~E*/
	sint32 temp;
	temp = (sint32)(value >> shiftright);
	/*Check for Overflow*/
	if (temp > S16_MAX)
	{
		res_ret =  S16_MAX;
	}
	else
	{
		/*Check for Underflow*/
		if (temp < S16_MIN)
		{
			res_ret =  S16_MIN;
		}
		else
		{
			res_ret =  (sint16)temp;
		}
	}
	return res_ret ;
	/* ## Operation body end [48f68628-931a-49e9-95e3-565f8fcd1cb8] */
}

/** This operation shall give the SIGN of sint32 value.
 if val < 0, then return -1
 if val = 0, then return 0
 if val > 0, then return +1

@param val  value to be type converted

 Range:     80000000(H)........7FFFFFFF(H)
         -2147483648.......2147483647

@param val Value to be type converted

Range:      80000000(H)......7FFFFFFF(H)
         -2147483648....2147483647
@return @return  result
 Limit underflow to: 0x00 (0)

 Range:     80...7F (H).     */
#include "iopt_memmap.h"

static inline  sint8 s8_sgn_s32(sint32 val)
{
	/* ## Operation body start [d2ab5918-6ed8-4f79-8ec2-e54b36ea7b3d] */

	/*~A*/
	/*~+:Description*/
	/* return: +1 if val > 0
            0 if val = 0
           -1 if val < 0 */
	/*~E*/
	return (sint8) ( (boolean)(val > 0) - (boolean)(val < 0) );//lint !e9030 DAT.11 MSRA 10.5: false positive, cast to boolean allowed in this case 
	/* ## Operation body end [d2ab5918-6ed8-4f79-8ec2-e54b36ea7b3d] */
}

/** This operation shall convert an uint64 value to an uint32 value with overflow limitation
@param val  Value to be type converted

 Range:     00(H)........0xFFFFFFFFFFFFFFFF(H)

@param val value to be type converted

Range:   0000000..FFFFFFFF(H)   
      0..4294967295
@return @return  result
 Limit overflow to : FFFFFFFF

 Range:     00(H).....FFFFFFFF(H)
        0..........4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_u64(uint64 val)
{
	/* ## Operation body start [2acc8120-67a7-4e93-a69b-b0e744132815] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/

	/*~E*/
	if (val >= U32_MAX)
	{
		res_ret =  U32_MAX;
	}
	else
	{
		res_ret =  (uint32)val;
	}
	return res_ret ;
	/* ## Operation body end [2acc8120-67a7-4e93-a69b-b0e744132815] */
}

/** This operation shall convert an sint64 value to an uint32 value with overflow limitation
@param val  Value to be type converted

 Range:     8000000000000000(H)........0x7FFFFFFFFFFFFFFF(H)

@param val value to be type converted

Range:   0000000..FFFFFFFF(H)   
      0..4294967295
@return @return  result
 Limit overflow to : 0xFF (255)

 Range:     00(H).....FFFFFFFF(H)
        0..........4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_s64(sint64 val)
{
	/* ## Operation body start [620cb0bb-5019-4abd-9474-4ad8544e0346] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/

	/*~E*/
	if (val >= (sint64)U32_MAX)
	{
		res_ret =  U32_MAX;
	}
	else
	{
		if (val <= (sint32)0)
		{
			res_ret =  U32_MIN;
		}
		else
		{
			res_ret =  (uint32)val;
		}
	}

	return res_ret ;
	/* ## Operation body end [620cb0bb-5019-4abd-9474-4ad8544e0346] */
}

/** This operation shall convert an sint64 value to an sint32 value with overflow limitation
@param val  Value to be type converted

 Range:     8000000000000000(H)........0x7FFFFFFFFFFFFFFF(H)

@param val value to be type converted

Range:   0000000..FFFFFFFF(H)   
      0..4294967295
@return @return  result
 Limit overflow to : 0xFF (255)

 Range:     80000000(H).....7FFFFFFF(H)
        -2147483648......2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_s64(sint64 val)
{
	/* ## Operation body start [0e395279-7eba-4513-a1ac-e9fcb5cac50a] */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/

	/*~E*/
	if (val >= S32_MAX)
	{
		res_ret =  S32_MAX;
	}
	else
	{
		if (val <= S32_MIN)
		{
			res_ret =  S32_MIN;
		}
		else
		{
			res_ret =  (sint32)val;
		}
	}
	return res_ret ;
	/* ## Operation body end [0e395279-7eba-4513-a1ac-e9fcb5cac50a] */
}

/** This operation shall multiply a value of type sint8 by a factor of 0...0.996 (shift 8 bits to the right)

@param value Value

Range:		80(H)...... 7F(H)
		  -128......127
@param factor Factor to be multiplied

Range:		00(H)...... FF(H)
		   0......0.996
@return (value * factor) >> 8

Range:		80(H)...... 7F(H)
		  -128......127 */
#include "iopt_memmap.h"

static inline  sint8 s8_mul_s8_u8_fac1(sint8 value, uint8 factor)
{
	/* ## Operation body start [f2f1cf5c-c211-454a-996a-74e0671a3bc5] */

	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s8_mul_s8_u8_fac1                                               

         Parameter        type    Hex Range       Physical Range          

Input:                                                                    
         value             sint8     80..7F          -128..127               
         factor            uint8     0..FF            0..0.996               

Output:                                                                   
         res               sint8     80..7F          -128..127               

Functionality:                                                            
        res = (value*factor)/256                                          
	 */

	/*~E*/
	return (sint8)(((sint16)value * (sint16)factor) / 256);


	/* ## Operation body end [f2f1cf5c-c211-454a-996a-74e0671a3bc5] */
}

/** This operation shall multiply a value of type sint8 by a factor of 0...1.992 (shift 7 bits to the right)

@param value Value

Range:		80(H)...... 7F(H)
		  -128......127
@param factor Factor to be multiplied

Range:		00(H)...... FF(H)
		   0......1.992
@return (value * factor) >> 7
Limit overflow to:    0x7F (127)
Limit underflow to:  0x80 (-128)

Range:		80(H)...... 7F(H)
		  -128......127 */
#include "iopt_memmap.h"

static inline  sint8 s8_mul_s8_u8_fac2(sint8 value, uint8 factor)
{
	/* ## Operation body start [f552e5ea-4314-42f7-9bfd-df92b4ae4088] */
	sint16 temp;
	sint8 res_ret;
	temp = (((sint16)value * (sint16)factor)/128);

	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s8_mul_s8_u8_fac2                                               

         Parameter          type      Hex Range       Physical Range      

Input:                                                                    
           value             sint8       80..7F           -128..127          
           factor            uint8       0..FF             0..1.992          

Output:                                                                   
           res               sint8       80..7F           -128..127          

Functionality:                                                            
          value*factor>>7                                                 
	 */

	/*~E*/
	if (temp >= S8_MAX)
	{
		res_ret =  S8_MAX;
	}
	else
	{
		if (temp <= S8_MIN)
		{
			res_ret =  S8_MIN;
		}
		else
		{
			res_ret =  (sint8)temp;
		}
	}
	return res_ret ;
	/* ## Operation body end [f552e5ea-4314-42f7-9bfd-df92b4ae4088] */
}

/** This operation shall multiply a value of type sint16 by a factor of -1.....0.999985 (shift 15 bits to the right) with overflow and underflow limitation

@param value Value

Range:		8000(H)......7FFF(H)
		  -32768......32767
@param factor Factor to be multiplied

Range:		8000(H)......7FFF(H)
		   -1......0.999985
@return (value * factor) >> 15
Limit overflow to:    0x7FFF (32767)
Limit underflow to:  0x8000 (-32768)

Range:		8000(H).......7FFF(H)
		  -32768......32767 */
#include "iopt_memmap.h"

static inline  sint16 s16_mul_s16_s16_fac1(sint16 value, sint16 factor)
{
	/* ## Operation body start [003a5454-1a47-49be-8f2c-44f38df01a3b] */
	sint32 res;
	sint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s16_mul_s16_s16_fac1                                               

         Parameter         type      Hex Range       Physical Range       

Input:                                                                    
         value             sint16       8000..7FFF       -32768..32767       
         factor            sint16       8000..7FFF       -1..0.999985        

Output:                                                                   
         res               sint16       8000..7FFF       -32768..32767       

Functionality:                                                            
        res = (value*factor)/32768                                        
        overflow : limit to 7FFFH                                         
        underflow: limit to 8000H                                         
	 */

	/*~E*/
	res = (((sint32)value * (sint32)factor) / (sint32)32768);
	if (res >= S16_MAX)
	{
		res_ret =  S16_MAX;
	}
	else
	{
		res_ret =  (sint16)res;
	}

	return res_ret ;
	/* ## Operation body end [003a5454-1a47-49be-8f2c-44f38df01a3b] */
}

/** This operation shall multiply a value of type sint16 by a factor of -2.....1.99997 (shift 14 bits to the right) with overflow and underflow limitation

@param value Value

Range:		8000(H)......7FFF(H)
		  -32768......32767
@param factor Factor to be multiplied

Range:		8000(H)......7FFF(H)
		    -2......1.99997
@return (value * factor) >> 14
Limit overflow to:    0x7FFF (32767)
Limit underflow to:  0x8000 (-32768)

Range:		8000(H).......7FFF(H)
		  -32768......32767 */
#include "iopt_memmap.h"

static inline  sint16 s16_mul_s16_s16_fac2(sint16 value, sint16 factor)
{
	/* ## Operation body start [974e7ed0-e867-44a5-98db-d6f971b3fcb1] */
	sint32 temp;
	sint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s16_mul_s16_s16_fac2                                            

         Parameter        type      Hex Range       Physical Range        

Input:                                                                    
         value            sint16       8000..7FFF       -32768..32767        
         factor           sint16       8000..7FFF       -2..1.99997          

Output:                                                                   
         res              sint16       8000..7FFF       -32768..32767        

Functionality:                                                            
        res = (value*factor)/16384                                        
        overflow : limit to 7FFFH                                         
        underflow: limit to 8000H                                         
	 */

	/*~E*/
	temp = (((sint32)value * (sint32)factor) / 16384);
	if ( temp >= S16_MAX)
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
	return res_ret ;
	/* ## Operation body end [974e7ed0-e867-44a5-98db-d6f971b3fcb1] */
}

/** This operation shall multiply a value of type sint16 by a factor of 0.....0.996 (shift 8 bits to the right)

@param value Value

Range:		8000(H)...... 7FFF(H)
		  -32768......32767
@param factor Factor to be multiplied

Range:		00(H)...... FF(H)
		   0.....0.996
@return (value * factor) >> 8

Range:		8000(H).......7FFF(H)
		  -32768......32767 */
#include "iopt_memmap.h"

static inline  sint16 s16_mul_s16_u8_fac1(sint16 value, uint8 factor)
{
	/* ## Operation body start [ce151027-3542-4e4b-bacc-ae6ea62ff015] */
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s16_mul_s16_u8_fac1                                              

         Parameter         type      Hex Range         Physical Range     

Input:                                                                    
         value             sint16       8000..7FFF        -32768..32767      
         factor            uint8        0..FF              0..0.996          

Output:                                                                   
         res               sint16       8000..7FFF        -32768..32767      

Functionality:                                                            
        res =   value*factor>>8                                           
	 */

	/*~E*/
	return (sint16)(((sint32)value * (sint32)factor) /256);
	/* ## Operation body end [ce151027-3542-4e4b-bacc-ae6ea62ff015] */
}

/** This operation shall multiply a value of type sint16 by a factor of 0.....1.992 (shift 7 bits to the right)

@param value Value

Range:		8000(H)...... 7FFF(H)
		  -32768......32767
@param factor Factor to be multiplied

Range:		00(H)...... FF(H)
		   0.....1.992
@return (value * factor) >> 7
Limit overflow to:    0x7FFF (32767)
Limit underflow to:  0x8000 (-32768)

Range:		8000(H).......7FFF(H)
		  -32768......32767 */
#include "iopt_memmap.h"

static inline  sint16 s16_mul_s16_u8_fac2(sint16 value, uint8 factor)
{
	/* ## Operation body start [5c5631ac-2e16-448a-add2-a3a6d6ebc2e7] */
	sint32 res;
	sint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s16_mul_s16_u8_fac2                                             

         Parameter         type      Hex Range         Physical Range     

Input:                                                                    
         value             sint16       8000..7FFF        -32768..32767      
         factor            uint8        0..FF              0..1.992          

Output:                                                                   
         res               sint16       8000..7FFF        -32768..32767      

Functionality:                                                            
        res =   value*factor>>7                                           
	 */

	/*~E*/
	res = (((sint32)value * (sint32)factor)/128);
	if ( res >= S16_MAX)
	{
		res_ret =  S16_MAX;
	}
	else
	{
		if (res <=S16_MIN)
		{
			res_ret =  S16_MIN;
		}
		else
		{
			res_ret =  (sint16)res;
		}
	}
	return res_ret ;
	/* ## Operation body end [5c5631ac-2e16-448a-add2-a3a6d6ebc2e7] */
}

/** This operation shall multiply a value of type sint16 by a factor of 0.....0.999985 (shift 16 bits to the right)

@param value Value

Range:		8000(H)......7FFF(H)
		  -32768......32767
@param factor Factor to be multiplied

Range:		00(H)......FFFF(H)
		   0.....0.999985
@return (value * factor) >> 16

Range:		8000(H).......7FFF(H)
		  -32768......32767 */
#include "iopt_memmap.h"

static inline  sint16 s16_mul_s16_u16_fac1(sint16 value, uint16 factor)
{
	/* ## Operation body start [268725e4-6132-499d-b8b9-f6cd6bae47ff] */
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s16_mul_s16_u16_fac1                                           

         Parameter         type      Hex Range        Physical Range      

Input:                                                                    
           value           sint16       8000..7FFF       -32768..32767       
           factor          uint16          0..FFFF        0..0.999985        

Output:                                                                   
           res             sint16       8000..7FFF       -32768..32767       

Functionality:                                                            
        res = (value*factor)/65536                                        
        overflow : limit to 7FFFH                                         
        underflow: limit to 8000H                                         
	 */

	/*~E*/
	return (sint16)(((sint32)value *(sint32) factor)/(sint32)65536);


	/* ## Operation body end [268725e4-6132-499d-b8b9-f6cd6bae47ff] */
}

/** This operation shall multiply a value of type sint16 by a factor of 0.....1.9999 (shift 15 bits to the right) with overflow and underflow limitation

@param value Value

Range:		8000(H)......7FFF(H)
		  -32768......32767
@param factor Factor to be multiplied

Range:		00(H)......FFFF(H)
		   0.....1.9999
@return (value * factor) >> 15
Limit overflow to:   0x7FFF (32767)
Limit underflow to: 0x8000 (-32768)

Range:		8000(H).......7FFF(H)
		  -32768......32767 */
#include "iopt_memmap.h"

static inline  sint16 s16_mul_s16_u16_fac2(sint16 value, uint16 factor)
{
	/* ## Operation body start [8c732451-09aa-4a12-b4ab-0c52dca723f1] */
	sint32 temp;
	sint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s16_mul_s16_u16_fac2                                          

         Parameter         type      Hex Range        Physical Range      

Input:                                                                    
           value           sint16       8000..7FFF       -32768..32767       
           factor          uint16          0..FFFF        0..1.9999          

Output:                                                                   
           res             sint16       8000..7FFF       -32768..32767       

Functionality:                                                            
        res = (value*factor)/32768                                        
        overflow : limit to 7FFFH                                         
        underflow: limit to 8000H                                         
	 */

	/*~E*/
	temp = (((sint32)value *(sint32) factor)/(sint32)32768);
	if ( temp >= S16_MAX)
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
	return res_ret ;
	/* ## Operation body end [8c732451-09aa-4a12-b4ab-0c52dca723f1] */
}

/** This operation shall multiply a value of type uint8 by a factor of 0.....0.996 (shift 8 bits to the right)

@param value Value

Range:		00(H)......FF(H)
		    0......255
@param factor Factor to be multiplied

Range:		00(H)......FF(H)
		  0......0.996
@return (value * factor) >> 8

Range:		00(H)......FF(H)
		    0......255 */
#include "iopt_memmap.h"

static inline  uint8 u8_mul_u8_u8_fac1(uint8 value, uint8 factor)
{
	/* ## Operation body start [0e4fbca0-1f70-42e9-be35-1a5011639632] */
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u8_mul_u8_u8_fac1                                               

      Parameter     type     Hex Range    Physical Range                  

Input:                                                                    
       value         uint8   0..FF          0..255                           
       factor        uint8   0..FF          0..0.996                         


Output:                                                                   
       res           uint8       0..FF          0..255                       

Functionality:                                                            
        res = (value * factor)/256                                        
	 */

	/*~E*/
	return (uint8)(((uint32)value * (uint32)factor ) /256U);

	/* ## Operation body end [0e4fbca0-1f70-42e9-be35-1a5011639632] */
}

/** This operation shall multiply a value of type uint8 by a factor of 0.....1.992 (shift 7 bits to the right) with overflow limitation

@param value Value

Range:		00(H)......FF(H)
		    0......255
@param factor Factor to be multiplied

Range:		00(H)......FF(H)
		  0......1.992
@return (value * factor) >> 7
Limit overflow to: 0xFF (255)

Range:		00(H)......FF(H)
		    0......255 */
#include "iopt_memmap.h"

static inline  uint8 u8_mul_u8_u8_fac2(uint8 value, uint8 factor)
{
	/* ## Operation body start [4001c343-419a-4bc0-b4b8-f84b33e5502b] */
	uint16 res;
	uint8 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u8_mul_u8_u8_fac2                                             


      Parameter     type     Hex Range    Physical Range                  

Input:                                                                    
         value       uint8       0..FF          0..255                       
         factor      uint8       0..FF          0..1.992                     


Output:                                                                   
         res         uint8       0..FF          0..255                       

Functionality:                                                            
        res = (value*factor)/128                                          
        limit overflow : FFh                                              
	 */

	/*~E*/
	res = (((uint16)value * (uint16)factor ) /128U);
	if (res > U8_MAX)
	{
		res_ret =  U8_MAX;
	}
	else
	{
		res_ret =  (uint8)res;
	}
	return res_ret ;
	/* ## Operation body end [4001c343-419a-4bc0-b4b8-f84b33e5502b] */
}

/** This operation shall multiply a value of type uint16 by a factor of 0.....0.998 (shift 8 bits to the right)

@param x_value First parameter

Range:		00(H)......FFFF(H)
		    0......65535
@param y_value Second parameter

Range:		00(H)......FF(H)
		   0.....0.998
@return (value * factor) >> 8

Range:		00(H)......FFFF(H)
		    0......65535 */
#include "iopt_memmap.h"

static inline  uint16 u16_mul_u16_u8_fac1(uint16 x_value, uint8 y_value)
{
	/* ## Operation body start [08d2fbf3-9ac0-4cc1-b213-5990cf95e668] */
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u16_mul_u16_u8_fac1                                              

         Parameter         type      Hex Range       Physical Range       

Input:                                                                    
         value             uint16       0..FFFF         0..65535             
         factor            uint8        0..FF           0..0.998             

Output:                                                                   
         res               uint16       0..FFFF         0..65535             

Functionality:                                                            
        res =   value*factor>>8                                           
	 */

	/*~E*/
	return (uint16)(((uint32)x_value * (uint32)y_value) >> 8);
	/* ## Operation body end [08d2fbf3-9ac0-4cc1-b213-5990cf95e668] */
}

/** This operation shall multiply a value of type uint16 by a factor of 0.....1.992 (shift 7 bits to the right)

@param x_value First parameter

Range:		00(H)......FFFF(H)
		    0......65535
@param y_value Second parameter

Range:		00(H)......FF(H)
		   0.....1.992
@return (value * factor) >> 7
Limit overflow to: 0xFFFF (65535)

Range:		00(H)......FFFF(H)
		    0......65535 */
#include "iopt_memmap.h"

static inline  uint16 u16_mul_u16_u8_fac2(uint16 x_value, uint8 y_value)
{
	/* ## Operation body start [25395b1a-c1a7-495f-a20f-229617d436f5] */
	uint32 temp;
	uint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
                                                                       FUNCTION: u16_mul_u16_u8_fac2                                             

                                                                       Parameter         type      Hex Range       Physical Range       

                                                                       Input:                                                                    
                                                                       x_value             uint16       0..FFFF         0..65535             
                                                                       y_value            uint8        0..FF           0..1.992             

                                                                       Output:                                                                   
                                                                       res               uint16       0..FFFF         0..65535             

                                                                       Functionality:                                                            
                                                                       res =   x_value*y_value>>7                                           
	 */

	/*~E*/
	temp = (((uint32)x_value * (uint32)y_value)/128U);
	if ( temp >= U16_MAX)
	{
		res_ret =  U16_MAX;
	}
	else
	{
		res_ret =  (uint16)temp;
	}
	return res_ret ;
	/* ## Operation body end [25395b1a-c1a7-495f-a20f-229617d436f5] */
}

/** This operation shall multiply a value of type uint16 by a factor of 0.....0.999985 (shift 16 bits to the right)

@param value Value

Range:		00(H)......FFFF(H)
		    0......65535
@param factor Factor to be multiplied

Range:		00(H)......FFFF(H)
		  0.....0.999985
@return (value * factor) >> 16

Range:		00(H)......FFFF(H)
		    0......65535 */
#include "iopt_memmap.h"

static inline  uint16 u16_mul_u16_u16_fac1(uint16 value, uint16 factor)
{
	/* ## Operation body start [ffed49e1-f57e-483f-ae9b-638bc10cbf83] */
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u16_mul_u16_u16_fac1                                          


      Parameter      type      Hex Range     Physical Range               

Input:                                                                    
       value         uint16       0..FFFF        0..65535                    
       factor        uint16       0..FFFF        0..0.999985                 


Output:                                                                   
       res           uint16       0..FFFF        0..65535                    

Functionality:                                                            
        res = (value  * factor)/65536                                     
        limit overflow to FFFFh                                           
	 */

	/*~E*/
	return (uint16)(((uint32)value * (uint32)factor) /(uint32)65536);
	/* ## Operation body end [ffed49e1-f57e-483f-ae9b-638bc10cbf83] */
}

/** This operation shall multiply a value of type uint16 by a factor of 0.....1.99997 (shift 15 bits to the right) with overflow limitation

@param value Value

Range:		00(H)......FFFF(H)
		    0......65535
@param factor Factor to be multiplied

Range:		00(H)......FFFF(H)
		  0.....1.99997
@return (value * factor) >> 15
Limit overflow to:  0xFFFF (65535)

Range:		00(H)......FFFF(H)
		    0......65535 */
#include "iopt_memmap.h"

static inline  uint16 u16_mul_u16_u16_fac2(uint16 value, uint16 factor)
{
	/* ## Operation body start [f49ccc5b-9e29-4949-b689-94db2b8d7317] */
	uint32 res;
	uint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u16_mul_u16_u16_fac2                                            


      Parameter      type      Hex Range     Physical Range               

Input:                                                                    
       value         uint16       0..FFFF        0..65535                    
       factor        uint16       0..FFFF        0..0..1.9921                


Output:                                                                   
       res           uint16       0..FFFF        0..65535                    

Functionality:                                                            
        res = (value  * factor)/32768                                     
        limit overflow to FFFFh                                           
	 */

	/*~E*/
	res = (((uint32)value * (uint32)factor) /(uint32)32768);
	if (res > U16_MAX)
	{
		res_ret =  U16_MAX;
	}
	else
	{
		res_ret =  (uint16)res;
	}
	return res_ret ;
	/* ## Operation body end [f49ccc5b-9e29-4949-b689-94db2b8d7317] */
}

/** This operation shall multiply a value of type uint32 by a factor of 0.....0.999985 (shift 16 bits to the right)

@param value Value

Range:		00(H)......FFFFFFFF(H)
		    0......4294967295
@param factor Factor to be multiplied

Range:		00(H)......FFFF(H)
		  0....0. 999985
@return (value * factor) >> 16

Range:		00(H)......FFFFFFFF(H)
		    0......4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_mul_u32_u16_fac1(uint32 value, uint16 factor)
{
	/* ## Operation body start [8fb4c0c1-de70-42bc-aa95-a336ab8d6c12] */
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u32_mul_u32_u16_fac1                                               

      Parameter     type     Hex Range    Physical Range                  

Input:                                                                    
       value         uint32   0..FFFFFFFF   0 .. 4294967295                  
       factor        uint16   0..FFFF       0 .. 0.9999                      


Output:                                                                   
       res           uint32   0..FFFFFFFF   0 .. 4294967295                  

Functionality:                                                            
        res = (value * factor)/65536                                      
	 */

	/*~E*/
	/*~A*/
	/*~+:Description of Lint supression*/
	/* W715: value,factor not referenced */
	/* W530: temp_result not initialised */

	/*~E*/
	uint32 tmp_factor = factor;
	return (uint32)(((uint64)value * tmp_factor) >> 16 );
	/* ## Operation body end [8fb4c0c1-de70-42bc-aa95-a336ab8d6c12] */
}

/** This operation shall multiply a value of type uint32 by a factor of 0.....1.99997 (shift 15 bits to the right) with overflow limitation

@param value Value

Range:		00(H)......FFFFFFFF(H)
		    0......4294967295
@param factor Factor to be multiplied

Range:		00(H)......FFFF(H)
		  0....1.99997
@return (value * factor) >> 17
Limit overflow to: 0xFFFFFFFF (4294967295)

Range:		00(H)......FFFFFFFF(H)
		    0......4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_mul_u32_u16_fac2(uint32 value, uint16 factor)
{
	/* ## Operation body start [503e6add-5264-47be-a6da-8bc54854b39c] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u32_mul_u32_u16_fac2                                            


      Parameter      type      Hex Range     Physical Range               

Input:                                                                    
       value         uint32       0..FFFFFFFF   0 .. 4294967295              
       factor        uint16       0..FFFF       0 .. 1.9999                  


Output:                                                                   
       res           uint32       0..FFFFFFFF   0 .. 4294967295              

Functionality:                                                            
        res = (value  * factor)/32768                                     
        limit overflow to FFFFFFFFh                                      
	 */

	/*~E*/
	uint64 res;
	uint32 tmp_factor = factor;
	/* Factor multiplication */
	res = ( ( (uint64)value * tmp_factor ) >> 15 ) ;
	/* Check for overflow */
	if ( res >= (uint64)U32_MAX )
	{
		res_ret =  U32_MAX;
	}
	else
	{
		res_ret =  (uint32)res;
	}
	return res_ret ;
	/* ## Operation body end [503e6add-5264-47be-a6da-8bc54854b39c] */
}

/** This operation shall multiply a value of type uint32 by a factor of -1....0.999985 (shift 15 bits to the right) with underflow limitation

@param value Value

Range:		00(H)......FFFFFFFF(H)
		    0......4294967295
@param factor Factor to be multiplied

Range:		8000(H)......7FFF(H)
		    -1....0.999985
@return (value * factor) >> 15
Limit underflow to:  0x00 (0)

Range:		00(H)......FFFFFFFF(H)
		    0......4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_mul_u32_s16_fac1(uint32 value, sint16 factor)
{
	/* ## Operation body start [7900aae0-7679-4cf3-98e4-e64161255f44] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u32_mul_u32_s16_fac1                                          


      Parameter      type      Hex Range     Physical Range               

Input:                                                                    
       value         uint32       0..FFFFFFFF   0 .. 4294967295              
       factor        sint16       8000..7FFF     -1 ... 0.9999               


Output:                                                                   
       res           uint32       0..FFFFFFFF   0 .. 4294967295              

Functionality:                                                            
        res = (value  * factor)/32768                                     
        limit overflow to FFFFFFFFh                                       
	 */

	/*~E*/
	/*~A*/
	/*~+:Description of Lint supression*/
	/* W715: value,factor not referenced */
	/* W530: temp_result not initialised */

	/*~E*/
	/* Check for underflow */
	if ( factor <= 0 )
	{
		res_ret =  U32_MIN;

	}
	else
	{
		res_ret =  (uint32)( ( (uint64)value * (uint16)factor ) >> 15 );
	}
	return res_ret ;
	/* ## Operation body end [7900aae0-7679-4cf3-98e4-e64161255f44] */
}

/** This operation shall multiply a value of type uint32 by a factor of -2....1.99997 (shift 14 bits to the right) with overflow and underflow limitation

@param value Value

Range:		00(H)......FFFFFFFF(H)
		    0......4294967295
@param factor Factor to be multiplied

Range:		8000(H)......7FFF(H)
		     -2....1.99997
@return (value * factor) >> 14
Limit overflow to:    0xFFFFFFFF (4294967295)
Limit underflow to:  0x00 (0)

Range:		00(H)......FFFFFFFF(H)
		    0......4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_mul_u32_s16_fac2(uint32 value, sint16 factor)
{
	/* ## Operation body start [847f2463-47a6-48a2-8bd7-790d6d15335b] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u32_mul_u32_s16_fac2                                           


      Parameter      type      Hex Range     Physical Range               

Input:                                                                    
       value         uint32       0..FFFF FFFF   0 .. 4294967295             
       factor        sint16       8000..7FFF     -2 ... 1.9999               


Output:                                                                   
       res           uint32       0..FFFF FFFF   0 .. 4294967295             

Functionality:                                                            
        res = (value  * factor)/16384                                     
        limit overflow to FFFF FFFFh                                      
	 */

	/*~E*/
	/*FUNCTION_ID:143*/
	sint64 res;
	/* Check for underflow */
	if ( factor > 0 )
	{
		/* Factor multiplication */
		res = (sint64)( (uint64)( (sint64)value * factor ) >> 14);
		/* Check for overflow */
		if ( res >= (sint64)U32_MAX )
		{
			res_ret =  U32_MAX;
		}
		else
		{
			res_ret =  (uint32)res;
		}
	}
	else
	{
		res_ret =  U32_MIN;
	}
	return res_ret ;
	/* ## Operation body end [847f2463-47a6-48a2-8bd7-790d6d15335b] */
}

/** This operation shall multiply a value of type uint32 by a factor of 0.....0.999985 (shift 32 bits to the right)

@param value Value

Range:		00(H)......FFFFFFFF(H)
		    0......4294967295
@param factor Factor to be multiplied

Range:		00(H)......FFFFFFFF(H)
		     0.....0.999985
@return (value * factor) >> 32

Range:		00(H)......FFFFFFFF(H)
		    0......4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_mul_u32_u32_fac1(uint32 value, uint32 factor)
{
	/* ## Operation body start [3e61a6e0-7a77-4407-9b34-df80e22c1c44] */
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION:  u32_mul_u32_u32_fac1                                         


      Parameter     type     Hex Range          Physical Range            

Input:                                                                    
       value         uint32       0..FFFFFFFF        0 .. 4294967295         
       factor        uint32       0..FFFFFFFF        0 .. 0.9999             


Output:                                                                   
       res           uint32       0..FFFFFFFF        0 .. 4294967295         

Functionality:                                                            
        res = (value * factor) >> 32                                     

	 */

	/*~E*/
	/*~A*/
	/*~+:Description of Lint supression*/
	/* W715: value,factor not referenced */
	/* W530: result not initialised */

	/*~E*/
	return (uint32)( ( (uint64)value * factor ) >> 32 ) ;

	/* ## Operation body end [3e61a6e0-7a77-4407-9b34-df80e22c1c44] */
}

/** This operation shall multiply a value of type uint32 by a factor of 0.....1.99997 (shift 31 bits to the right) with overflow limitation

@param value Value

Range:		00(H)......FFFFFFFF(H)
		    0......4294967295
@param factor Factor to be multiplied

Range:		00(H)......FFFFFFFF(H)
		     0.....1.99997
@return (value * factor) >> 31
Limit overflow to: 0xFFFFFFFF (4294967295)

Range:		00(H)......FFFFFFFF(H)
		    0......4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_mul_u32_u32_fac2(uint32 value, uint32 factor)
{
	/* ## Operation body start [1dac0018-85cc-4452-94c5-efb1f41e72fb] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION:  u32_mul_u32_u32_fac2                                          


      Parameter     type       Hex Range           Physical Range         

Input:                                                                    
       value         uint32       0..FFFFFFFF        0..4294967295           
       factor        uint32       0..FFFFFFFF        0 .. 1.9999             


Output:                                                                   
       res           uint32       0..FFFFFFFF        0..4294967295           

Functionality:                                                            
        res = value * factor / 2147483648                                 
        limit overflow : FFFFFFFFH                                        

	 */

	/*~E*/
	uint64 res;
	/* Factor multiplication */
	res = ( ( (uint64)value * factor ) >> 31 ) ;
	/* Check for overflow */
	if ( res >= (uint64)U32_MAX )
	{
		res_ret =  U32_MAX;
	}
	else
	{
		res_ret =  (uint32)res;
	}
	return res_ret ;
	/* ## Operation body end [1dac0018-85cc-4452-94c5-efb1f41e72fb] */
}

/** This operation shall multiply a value of type uint32 by a factor of -1.....0.999985 (shift 31 bits to the right) with underflow limitation

@param value Value

Range:		00(H)......FFFFFFFF(H)
		    0......4294967295
@param factor Factor to be multiplied

Range:		80000000(H)......7FFFFFFF(H)
		         -1.....0.999985
@return (value * factor) >> 31
Limit underflow to: 0x00 (0)


Range:		00(H)......FFFFFFFF(H)
		    0......4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_mul_u32_s32_fac1(uint32 value, sint32 factor)
{
	/* ## Operation body start [e61b4015-7bde-420f-a32d-f5f7dec10cb5] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u32_mul_u32_s32_fac1                                           


      Parameter      type      Hex Range            Physical Range        

Input:                                                                    
       value         uint32       00000000..FFFFFFFF   0..4294967295         
       factor        sint32       80000000..7FFFFFFF   -1.. 0 ..0.9999       


Output:                                                                   
       res           uint32       00000000..FFFFFFFF   0..4294967295         

Functionality:                                                            
        res = (value  * factor)/2147483648                                
        limit underflow to 00000000h                                      
	 */

	/*~E*/
	/* Check for underflow */
	if ( factor <= 0 )
	{
		res_ret =  U32_MIN;

	}
	else
	{
		res_ret =  (uint32)( ( (uint64)value * (uint32)factor ) >> 31 );
	}
	return res_ret ;
	/* ## Operation body end [e61b4015-7bde-420f-a32d-f5f7dec10cb5] */
}

/** This operation shall multiply a value of type uint32 by a factor of -2.....1.99997 (shift 30 bits to the right) with overflow and underflow limitation

@param value Value

Range:		00(H)......FFFFFFFF(H)
		    0......4294967295
@param factor Factor to be multiplied

Range:		80000000(H)......7FFFFFFF(H)
		           -2.....1.99997
@return (value * factor) >> 30
Limit overflow to: 0xFFFFFFFF (4294967295)
Limit underflow to: 0x00 (0)

Range:		00(H)......FFFFFFFF(H)
		    0......4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_mul_u32_s32_fac2(uint32 value, sint32 factor)
{
	/* ## Operation body start [37d8be54-97fc-436b-bcfa-9365eddb8c6d] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u32_mul_u32_s32_fac2                                           


      Parameter      type      Hex Range            Physical Range        

Input:                                                                    
       value         uint32       00000000..FFFFFFFF   0....4294967295       
       factor        sint32       80000000..7FFFFFFF   -2....1.9999          


Output:                                                                   
       res           uint32       00000000..FFFFFFFF   0..4294967295         

Functionality:                                                            
        res = (value  * factor)/1073741824                                
        limit overflow to FFFF FFFFh                                      
	 */

	/*~E*/
	/*FUNCTION_ID:151*/
	uint64 temp ;
	/* Check for underflow */
	if ( factor > 0 )
	{
		temp = ( ( (uint64)value * (uint32)factor ) >> 30 ) ;
		/* Check for overflow */
		if ( temp >= (uint64)U32_MAX )
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
	return res_ret ;
	/* ## Operation body end [37d8be54-97fc-436b-bcfa-9365eddb8c6d] */
}

/** This operation shall multiply a value of type sint32 by a factor of 0.....0.999985 (shift 16 bits to the right)

@param value Value

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648......2147483647
@param factor Factor to be multiplied

Range:		00(H)......FFFF(H)
		  0.....0.999985
@return (value * factor) >> 16

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648......2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_mul_s32_u16_fac1(sint32 value, uint16 factor)
{
	/* ## Operation body start [1122267e-74f4-4654-a847-cf239e84be0a] */
	/*
FUNCTION: s32_mul_s32_u16_fac1                                           


      Parameter      type      Hex Range            Physical Range        

Input:                                                                    
       value         sint32      80000000..7FFFFFFF -214783648....2147483647 
       factor        uint16      0..FFFF                     0 .. 0.9999     


Output:                                                                   
       res           sint32      80000000..7FFFFFFF   -214783648..2147483647 

Functionality:                                                            
        res = (value  * factor)/65536                                     
	 */

	/* W530: temp not initialised */
	/* W550: abs_value not accessed */
	/* W715: factor,value not referenced */

	/*lint -efunc(715, s32_mul_s32_u16_fac1)*/
	/*lint -efunc(550, s32_mul_s32_u16_fac1)*/
	return (sint32)( ( (sint64)value * (sint32)factor ) / 65536 );

	/* ## Operation body end [1122267e-74f4-4654-a847-cf239e84be0a] */
}

/** This operation shall multiply a value of type sint32 by a factor of 0.....1.99997 (shift 15 bits to the right) with overflow and underflow limitation

@param value Value

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648......2147483647
@param factor Factor to be multiplied

Range:		00(H)......FFFF(H)
		   0.....1.99997
@return (value * factor) >> 15
Limit overflow to:    0x7FFFFFFF (2147483647)
Limit underflow to : 0x80000000 (-2147483648)

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648......2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_mul_s32_u16_fac2(sint32 value, uint16 factor)
{
	/* ## Operation body start [715b2956-d9ea-47cb-9138-9290051fa9c1] */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s32_mul_s32_u16_fac2                                             


      Parameter      type      Hex Range            Physical Range          

Input:                                                                      
       value         sint32      80000000..7FFFFFFF   -214783648....2147483647 
       factor        uint16      0..FFFF                       0 .. 1.9999     


Output:                                                                     
       res           sint32      80000000..7FFFFFFF   -214783648....2147483647 

Functionality:                                                              
        res = (value  * factor)/32768                                       
        limit overflow  to  7FFFFFFFh                                      
        limit underflow to  80000000h                                      

	 */

	/*~E*/
	/* Check for overflow */
	if ( ( ( (sint64)value * (sint32)factor ) / 32768 ) > S32_MAX )
	{
		res_ret =  S32_MAX;
	}
	else
	{
		/* Check for underflow */
		if( ( ( (sint64)value * (sint32)factor ) / 32768 ) < S32_MIN )
		{
			res_ret =  S32_MIN ;
		}
		else
		{
			res_ret =  (sint32)( ( (sint64)value * (sint32)factor ) / 32768 );
		}
	}

	return res_ret ;
	/* ## Operation body end [715b2956-d9ea-47cb-9138-9290051fa9c1] */
}

/** This operation shall multiply a value of type sint32 by a factor of -1.....0.999985 (shift 15 bits to the right) with overflow limitation

@param value Value

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648......2147483647
@param factor Factor to be multiplied

Range:		8000(H)......7FFF(H)
		    -1....0.999985
@return (value * factor) >> 15
Limit overflow to: 0x7FFFFFFF (2147483647)

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648......2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_mul_s32_s16_fac1(sint32 value, sint16 factor)
{
	/* ## Operation body start [3d65141b-42f3-466d-8b14-b324b81c9be4] */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s32_mul_s32_s16_fac1                                     


      Parameter      type      Hex Range            Physical Range        

Input:                                                                    
       value         sint32      80000000..7FFFFFFF    -214783648..2147483647
       factor        sint16      8000..7FFF            -1 .. 0.9999          


Output:                                                                   
       res           sint32      80000000..7FFFFFFF   -214783648..2147483647 

Functionality:                                                            
        res = (value  * factor)/32768                                     
	 */

	/*~E*/
	if ( (( (sint64)value * factor ) / 32768) >= S32_MAX)
	{
		res_ret =  S32_MAX;
	}
	else
	{
		res_ret =  (sint32)(( (sint64)value * factor ) / 32768);
	}

	return res_ret ;
	/* ## Operation body end [3d65141b-42f3-466d-8b14-b324b81c9be4] */
}

/** This operation shall multiply a value of type sint32 by a factor of -2.....1.99997 (shift 14 bits to the right) with overflow and underflow limitation

@param value Value

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648......2147483647
@param factor Factor to be multiplied

Range:		8000(H)......7FFF(H)
		   -2....1.99997
@return (value * factor) >> 14
Limit overflow to: 0x7FFFFFFF (2147483647)
Limit underflow to: 0x80000000 (-2147483648)

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648......2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_mul_s32_s16_fac2(sint32 value, sint16 factor)
{
	/* ## Operation body start [c0d5a846-3058-4ab8-b4ee-a29960b90a47] */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s32_mul_s32_s16_fac2                                         


      Parameter      type      Hex Range            Physical Range        

Input:                                                                    
       value         sint32      80000000..7FFFFFFF   -214783648..2147483647 
       factor        sint16      8000..7FFF            -1 ... 1.9999         


Output:                                                                   
       res           sint32      80000000..7FFFFFFF   -214783648..2147483647 

Functionality:                                                            
        res = (value  * factor)/16384                                     
        limit overflow  to  7FFFFFFFh                                     
        limit underflow to  80000000h                                     

	 */

	/*~E*/
	/* Factor multiplication */
	/* Check for overflow */
	if ( ( ( (sint64)value * factor ) / 16384 ) >= S32_MAX )
	{
		res_ret =  S32_MAX;
	}
	else
	{
		/* Check for underflow */
		if ( ( ( (sint64)value * factor ) / 16384 ) <= S32_MIN )
		{
			res_ret =  S32_MIN;
		}
		else
		{
			res_ret =  (sint32)( ( (sint64)value * factor ) / 16384 );
		}
	}
	return res_ret ;
	/* ## Operation body end [c0d5a846-3058-4ab8-b4ee-a29960b90a47] */
}

/** This operation shall multiply a value of type sint32 by a factor of 0.....0.4999925 (shift 33 bits to the right)

@param value Value

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648......2147483647
@param factor Factor to be multiplied

Range:		00(H)......FFFFFFFF(H)
		   0....0.4999925
@return (value * factor) >> 33

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648......2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_mul_s32_u32_fac05(sint32 value, uint32 factor)
{
	/* ## Operation body start [b7312679-4b76-47a4-b450-e08c7a424fc9] */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION   s32_mul_s32_u32_fac05                                                 

         Parameter        type      Hex Range          Physical Range               

Input:                                                                              
         value             sint32   80000000..7FFFFFFF     -2147483648..0..2147483647  
         factor            uint32   0..FFFFFFFF             0 .. 0.4999                

Output:                                                                             
         res               sint32   80000000..7FFFFFFF     -2147483648..0..2147483647  

Functionality:                                                                      
         res = (value*factor)/8589934592                                            
	 */

	/*~E*/
	uint64 tmp_product;
	sint32 tmp_value;
	uint32 abs_value;
	/*Converting negative values to positive values to get the expected result after shifting*/
	if (value >= 0)
	{
		abs_value=(uint32)(value);

	}
	else
	{
		abs_value=(uint32)(-value);
	}
	tmp_product=(uint64)abs_value*factor;
	/* Shifting Positive Number by 33 is equivalent to division by 8589934592*/
	tmp_value=(sint32)((uint64)tmp_product>> 33);
	/*Appending the sign value*/
	if (value < 0)
	{
		res_ret =  (sint32)(-tmp_value);
	}
	else
	{
		res_ret =  (sint32)tmp_value;
	}

	return res_ret ;
	/* ## Operation body end [b7312679-4b76-47a4-b450-e08c7a424fc9] */
}

/** This operation shall multiply a value of type sint32 by a factor of 0.....0.999985 (shift 32 bits to the right)

@param value Value

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648......2147483647
@param factor Factor to be multiplied

Range:		00(H)......FFFFFFFF(H)
		   0....0.999985
@return (value * factor) >> 32

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648......2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_mul_s32_u32_fac1(sint32 value, uint32 factor)
{
	/* ## Operation body start [bc267eba-f9cf-4ee3-896c-92001c6ef713] */
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s32_mul_s32_u32_fac1                                         

         Parameter     type  Hex Range            Physical Range          

Input:                                                                    
           value       sint32   80000000..7FFFFFFF   -2147483648..2147483647 
           factor      uint32   00000000..FFFFFFFF    0 .. 0.999985          

Output:                                                                   
           res         sint32   80000000..7FFFFFFF  -2147483648..2147483647  

Functionality:                                                            
        res = (value*factor)/4294967296                                   
	 */

	/*~E*/
	return (sint32) ( ( (sint64)value * (sint64)factor ) / (sint64)4294967296LL ) ;
	/* ## Operation body end [bc267eba-f9cf-4ee3-896c-92001c6ef713] */
}

/** This operation shall multiply a value of type sint32 by a factor of 0.....1.99997 (shift 31 bits to the right)

@param value Value

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648......2147483647
@param factor Factor to be multiplied

Range:		00(H)......FFFFFFFF(H)
		   0....1.99997
@return (value * factor) >> 31
Limit overflow to: 0x7FFFFFFF (2147483647)
Limit underflow to: 0x80000000 (-2147483648)

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648......2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_mul_s32_u32_fac2(sint32 value, uint32 factor)
{
	/* ## Operation body start [1d037b3e-cc32-4735-b1a4-e622af480cd3] */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s32_mul_s32_u32_fac2                                                

         Parameter      type    Hex Range             Physical Range            

Input:                                                                          
           value        sint32    80000000..7FFFFFFF    -2147483648..2147483647    
           factor       uint32    00000000..FFFFFFFF     0 .. 1.9999               

Output:                                                                         
           res          sint32    80000000..7FFFFFFF    -2147483648..2147483647    

Functionality:                                                                  
        res = (value*factor)/2147483648                                         
        overflow : limit to 7FFFFFFFH                                           
        underflow: limit to 80000000H                                           
	 */

	/*~E*/
	/* Factor multiplication */
	/* Check for overflow */
	if ( ( ( (sint64)value * (sint64)factor ) / 2147483648LL ) >= S32_MAX )
	{
		res_ret =  S32_MAX;
	}
	else
	{
		/* Check for underflow */
		if ( ( ( (sint64)value * (sint64)factor ) / 2147483648LL ) <= S32_MIN )
		{
			res_ret =  S32_MIN;
		}
		else
		{
			res_ret =  (sint32)( ( (sint64)value * (sint64)factor ) / 2147483648LL );
		}
	}

	return res_ret ;
	/* ## Operation body end [1d037b3e-cc32-4735-b1a4-e622af480cd3] */
}

/** This operation shall multiply a value of type sint32 by a factor of -0.5.....0.4999925 (shift 32 bits to the right)

@param value Value

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648......2147483647
@param factor Factor to be multiplied

Range:		80000000(H)......7FFFFFFF(H)
		        -0.5....0.4999925
@return (value * factor) >> 32

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648......2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_mul_s32_s32_fac05(sint32 value, sint32 factor)
{
	/* ## Operation body start [89ca4acb-0f7a-422d-9270-eb26bf0ce077] */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION   s32_mul_s32_s32_fac05                                                   

         Parameter        type      Hex Range          Physical Range               

Input:                                                                              
         value             sint32   8000000..7FFFFFFF     -2147483648..2147483647      
         factor            sint32   8000000..7FFFFFFF     -0.5.. 0.499                 

Output:                                                                             
         res               sint32   8000000..7FFFFFFF     -2147483648..2147483647      

Functionality:                                                                      
         res = (value*factor)/4294967296                                            
	 */

	/*~E*/
	uint64 tmp_product;
	sint32 tmp_value,sign_value,sign_factor;
	uint32 abs_value,abs_factor;

	/*Converting negative values to positive values to get the expected result after shifting*/
	if (value >= 0)
	{
		abs_value=(uint32)(value);
		sign_value=1;

	}
	else
	{
		abs_value=(uint32)(-value);
		sign_value=-1;

	}
	if (factor >= 0)
	{
		abs_factor=(uint32)(factor);
		sign_factor=1;

	}
	else
	{
		abs_factor=(uint32)(-factor);
		sign_factor=-1;

	}
	tmp_product=(uint64)abs_value*abs_factor;
	/* Shifting Positive Number by 32 is equivalent to division by 4294967296*/
	tmp_value=(sint32)((uint64)tmp_product>> 32);
	/*Appending the sign value*/
	if ((sign_value*sign_factor) == 1)
	{
		res_ret =  (sint32)tmp_value;
	}
	else
	{
		res_ret =  (sint32)(-tmp_value);
	}

	return res_ret ;
	/* ## Operation body end [89ca4acb-0f7a-422d-9270-eb26bf0ce077] */
}

/** This operation shall multiply a value of type sint32 by a factor of -1.....0.999985 (shift 31 bits to the right) with overflow limitation

@param value Value

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648......2147483647
@param factor Factor to be multiplied

Range:		80000000(H)......7FFFFFFF(H)
		         -1....0.999985
@return (value * factor) >> 31
Limit overflow to: 0x7FFFFFFF (2147483647)

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648......2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_mul_s32_s32_fac1(sint32 value, sint32 factor)
{
	/* ## Operation body start [8b1f44e1-56b4-4252-95fe-f4e550cda45d] */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s32_mul_s32_s32_fac1                                                

         Parameter      type   Hex Range             Physical Range             

Input:                                                                          
           value        sint32   80000000..7FFFFFFF     -2147483648..2147483647    
          factor        sint32   80000000..7FFFFFFF     -1 .. -0.9999              

Output:                                                                         
           res          sint32   80000000..7FFFFFFF     -2147483648..2147483647    

Functionality:                                                                  
        res = (value*factor)/2147483648                                         
        overflow : limit to 7FFFFFFFH                                           
	 */

	/*~E*/
	/* Factor multiplication */
	/* Check for overflow */
	if (  ( ( (sint64)value * factor ) / 2147483648LL ) >= S32_MAX )
	{
		res_ret =  S32_MAX;
	}
	else
	{
		res_ret =  (sint32) ( ( (sint64)value * factor ) / 2147483648LL );
	}

	return res_ret ;
	/* ## Operation body end [8b1f44e1-56b4-4252-95fe-f4e550cda45d] */
}

/** This operation shall multiply a value of type sint32 by a factor of -2.....1.99997 (shift 30 bits to the right) with overflow and underflow limitation

@param value Value

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648......2147483647
@param factor Factor to be multiplied

Range:		80000000(H)......7FFFFFFF(H)
		          -2....1.99997
@return (value * factor) >> 30
Limit overflow to: 0x7FFFFFFF (2147483647)
Limit underflow to: 0x80000000 (-2147483648)

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648......2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_mul_s32_s32_fac2(sint32 value, sint32 factor)
{
	/* ## Operation body start [1b566d1a-50a8-4482-9f3a-5ba143b71aa3] */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s32_mul_s32_s32_fac2                                            

         Parameter      type   Hex Range           Physical Range         

Input:                                                                    
           value        sint32    80000000..7FFFFFFF  -2147483648..2147483647
           factor       sint32    00000000..FFFFFFFF  -1 .. 0.999985         

Output:                                                                   
           res          sint32    80000000..7FFFFFFF  -2147483648..2147483647

Functionality:                                                            
        res = (value*factor)/1073741824                                   
        overflow : limit to 7FFFFFFFH                                     
        underflow: limit to 80000000H                                     
	 */

	/*~E*/
	/* Factor multiplication */
	/* Check for overflow */
	if ( ( ( (sint64)value * factor ) / (sint32)1073741824 ) >= (sint64)S32_MAX )
	{
		res_ret =  S32_MAX;
	}
	else
	{
		/* Check for underflow */
		if ( ( ( (sint64)value * factor ) / (sint32)1073741824 ) <= (sint64)S32_MIN )
		{
			res_ret =  S32_MIN;
		}
		else
		{
			res_ret =  (sint32)( ( (sint64)value * factor ) / (sint32)1073741824 );
		}
	}

	return res_ret ;
	/* ## Operation body end [1b566d1a-50a8-4482-9f3a-5ba143b71aa3] */
}

/** This operation shall multiply a value of type uint32 by a factor of 0.....0.996 (shift 8 bits to the right)

@param value Value

Range:		00(H)......FFFFFFFF(H)
		    0......4294967295
@param factor Factor to be multiplied

Range:		00(H)......FF(H)
		    0....0.996
@return (value * factor) >> 8

Range:		00(H)......FFFFFFFF(H)
		    0......4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_mul_u32_u8_fac1(uint32 value, uint8 factor)
{
	/* ## Operation body start [df98a16d-6488-4576-b65e-af0095a086c2] */
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u32_mul_u32_u8_fac1                                           

      Parameter     type     Hex Range          Physical Range            

Input:                                                                    
       value         uint32   00000000..FFFFFFFF    0..4294967295            
       factor        uint8          00..FF          0..0.996                 


Output:                                                                   
       res           uint32   00000000..FFFFFFFF    0..4294967295            

Functionality:                                                            
        res = (value * factor) >> 8                                       
	 */

	/*~E*/
	uint32 tmp_factor = factor;
	return (uint32)( ( (uint64)value * tmp_factor ) >> 8 );
	/* ## Operation body end [df98a16d-6488-4576-b65e-af0095a086c2] */
}

/** This operation shall multiply a value of type uint32 by a factor of 0.....1.9922 (shift 7 bits to the right) with overflow limitation

@param value Value

Range:		00(H)......FFFFFFFF(H)
		    0......4294967295
@param factor Factor to be multiplied

Range:		00(H)......FF(H)
		    0....1.9922
@return (value * factor) >> 7
Limit overflow to: 0xFFFFFFFF (4294967295)

Range:		00(H)......FFFFFFFF(H)
		    0......4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_mul_u32_u8_fac2(uint32 value, uint8 factor)
{
	/* ## Operation body start [e9461283-c2d6-4944-9703-64f4a0b6cc50] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u32_mul_u32_u8_fac2                                          


      Parameter      type      Hex Range             Physical Range       

Input:                                                                    
       value         uint32       00000000..FFFFFFFF    0..4294967295        
       factor        uint8              00..FF          0..1.9922            


Output:                                                                   
       res           uint32       00000000..FFFFFFFF    0..4294967295        

Functionality:                                                            
        res = (value  * factor) >> 7                                      
        limit overflow to FFFFFFFF h                                      
	 */

	/*~E*/
	/* FUNCTION_ID:171 */
	uint64 res;
	uint32 tmp_factor = factor;
	/* Factor multiplication */
	res = ( ( (uint64)value * tmp_factor ) >> 7 ) ;
	/* Check for overflow */
	if ( res >= (uint64)U32_MAX )
	{
		res_ret =  U32_MAX;
	}
	else
	{
		res_ret =  (uint32)res;
	}
	return res_ret ;
	/* ## Operation body end [e9461283-c2d6-4944-9703-64f4a0b6cc50] */
}

/** This operation shall multiply a value of type uint32 by a factor of -1.....0.9922 (shift 7 bits to the right) with underflow limitation

@param value Value

Range:		00(H)......FFFFFFFF(H)
		    0......4294967295
@param factor Factor to be multiplied

Range:		80(H)......7F(H)
		  -1.....0.9922
@return (value * factor) >> 7
Limit underflow to: 0x00 (0)

Range:		00(H)......FFFFFFFF(H)
		    0......4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_mul_u32_s8_fac1(uint32 value, sint8 factor)
{
	/* ## Operation body start [6a58f3a5-ff1d-4025-97e3-ca935272cd14] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u32_mul_u32_s8_fac1                                             

      Parameter     type     Hex Range          Physical Range            

Input:                                                                    
       value         uint32   00000000..FFFFFFFF    0..4294967295            
       factor        sint8          80..7F          -1 .. 0.9922             


Output:                                                                   
       res           uint32   00000000..FFFFFFFF    0..4294967295            

Functionality:                                                            
        res = (value * factor) >> 7                                       
        limit underflow to 00000000 h                                     
	 */

	/*~E*/
	sint32 tmp_factor = factor;
	/* Check for underflow */
	if ( tmp_factor <= 0 )
	{
		res_ret =  U32_MIN;
	}
	else
	{
		res_ret =  (uint32)(((uint64)value * (uint32)tmp_factor) >> 7);
	}
	return res_ret ;
	/* ## Operation body end [6a58f3a5-ff1d-4025-97e3-ca935272cd14] */
}

/** This operation shall multiply a value of type uint32 by a factor of -2.....1.9844 (shift 6 bits to the right) with underflow and overflow limitation

@param value Value

Range:		00(H)......FFFFFFFF(H)
		    0......4294967295
@param factor Factor to be multiplied

Range:		80(H)......7F(H)
		  -2....1.9844
@return (value * factor) >> 6
Limit overflow to: 0xFFFFFFFF (4294967295)
Limit underflow to : 0x00 H (0)

Range:		00(H)......FFFFFFFF(H)
		    0......4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_mul_u32_s8_fac2(uint32 value, sint8 factor)
{
	/* ## Operation body start [1c3c6f54-9695-4f20-822e-b07bb7e0617e] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u32_mul_u32_s8_fac2                                           


      Parameter      type      Hex Range             Physical Range       

Input:                                                                    
       value         uint32       00000000..FFFFFFFF    0..4294967295        
       factor        sint8              80..7F          -2 .. 1.9844         


Output:                                                                   
       res           uint32       00000000..FFFFFFFF    0..4294967295        

Functionality:                                                            
        res = (value  * factor) >> 6                                      
        limit overflow  to FFFFFFFF h                                     
        limit underflow to 00000000 h                                     
	 */

	/*~E*/
	uint64 res;
	sint32 tmp_factor = factor;
	/* Check for underflow */
	if ( tmp_factor <= 0 )
	{
		res_ret =  U32_MIN;
	}
	else
	{
		/* Factor multiplication */
		res = ( ( (uint64)value * (uint32)tmp_factor ) >> 6 ) ;
		/* Check for overflow */
		if ( res >= (uint64)U32_MAX )
		{
			res_ret =  U32_MAX;
		}
		else
		{
			res_ret =  (uint32)res;
		}
	}
	return res_ret ;
	/* ## Operation body end [1c3c6f54-9695-4f20-822e-b07bb7e0617e] */
}

/** This operation shall multiply a value of type sint32 by a factor of 0.....0.996 (shift 8 bits to the right)

@param value Value

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648......2147483647
@param factor Factor to be multiplied

Range:		00(H)......FF(H)
		    0....0.996
@return (value * factor) >> 8

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648......2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_mul_s32_u8_fac1(sint32 value, uint8 factor)
{
	/* ## Operation body start [fc31f760-4748-4d8e-a043-b96168a59e68] */
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s32_mul_s32_u8_fac1                                                        

      Parameter     type     Hex Range                 Physical Range                   

Input:                                                                                  
       value         sint32     80000000..FFFFFFFF       -2147483648..2147483647           
       factor        uint8            00..FF              0 .. 0.996                       


Output:                                                                                 
       res           sint32     80000000..FFFFFFFF       -2147483648..2147483647           

Functionality:                                                                          
        res = (value * factor) / 256                                                    
	 */

	/*~E*/
	sint32 tmp_factor = (sint32)factor;
	return (sint32)( ( (sint64)value * tmp_factor ) / 256 );

	/* ## Operation body end [fc31f760-4748-4d8e-a043-b96168a59e68] */
}

/** This operation shall multiply a value of type sint32 by a factor of 0.....1.9922 (shift 7 bits to the right) with overflow and underflow limitation

@param value Value

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648......2147483647
@param factor Factor to be multiplied

Range:		00(H)......FF(H)
		    0....1.9922
@return (value * factor) >> 7
Limit overflow to: 0x7FFFFFFF (2147483647)
Limit underflow to: 0x80000000 (-2147483648)

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648......2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_mul_s32_u8_fac2(sint32 value, uint8 factor)
{
	/* ## Operation body start [b2130d05-156f-4fe4-9bcd-b72fb537d20e] */
	sint32 res_ret;

	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s32_mul_s32_u8_fac2                                                         


      Parameter      type      Hex Range             Physical Range                     

Input:                                                                                  
       value         sint32       80000000..FFFFFFFF    -2147483648..2147483647            
       factor        uint8              00..FF          0 .. 1.9922                        


Output:                                                                                 
       res           sint32       80000000..FFFFFFFF    -2147483648..2147483647            

Functionality:                                                                          
        res = (value  * factor) / 128                                                   
        limit overflow  to 7FFFFFFF h                                                   
        limit underflow to 80000000 h                                                   
	 */

	/*~E*/
	sint32 tmp_factor = (sint32)factor;
	/* Factor multiplication */
	/* Check for overflow */
	if ( ( ( (sint64)value * tmp_factor ) / 128 ) >= (sint64)S32_MAX )
	{
		res_ret =  S32_MAX;
	}
	else
	{
		/* Check for underflow */
		if ( ( ( (sint64)value * tmp_factor ) / 128 ) <= (sint64)S32_MIN )
		{
			res_ret =  S32_MIN;
		}
		else
		{
			res_ret =  (sint32)( ( (sint64)value * tmp_factor ) / 128 );
		}
	}
	return res_ret ;
	/* ## Operation body end [b2130d05-156f-4fe4-9bcd-b72fb537d20e] */
}

/** This operation shall multiply a value of type sint32 by a factor of -1.....0.9922 (shift 7 bits to the right) with overflow limitation

@param value Value

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648......2147483647
@param factor Factor to be multiplied

Range:		80(H)......7F(H)
		  -1...0.9922
@return (value * factor) >> 7
Limit overflow to: 0x7FFFFFFF (2147483647)

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648......2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_mul_s32_s8_fac1(sint32 value, sint8 factor)
{
	/* ## Operation body start [0b667922-a654-4aa9-9a11-05b1fcff5fa3] */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s32_mul_s32_s8_fac1                                                             

      Parameter     type     Hex Range                 Physical Range                   

Input:                                                                                  
       value         sint32     80000000..FFFFFFFF       -2147483648.2147483647            
       factor        sint8            80..FF             -1 .. 0.9922                      


Output:                                                                                 
       res           sint32     80000000..FFFFFFFF       -2147483648..2147483647           

Functionality:                                                                          
        res = (value * factor) / 128                                                    
	 */

	/*~E*/
	sint32 tmp_factor = factor;
	/* Check for overlow */
	if ( ( ( (sint64)value * tmp_factor ) / 128 ) > (sint64)(S32_MAX) )
	{
		res_ret =  S32_MAX;
	}
	else
	{
		res_ret =  (sint32)( ( (sint64)value * tmp_factor ) / 128 );
	}

	return res_ret ;
	/* ## Operation body end [0b667922-a654-4aa9-9a11-05b1fcff5fa3] */
}

/** This operation shall multiply a value of type sint32 by a factor of -2.....1.9844 (shift 6 bits to the right) with overflow and underflow limitation

@param value Value

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648......2147483647
@param factor Factor to be multiplied

Range:		80(H)......7F(H)
		  -2...1.9844
@return (value * factor) >> 6
Limit overflow to: 0x7FFFFFFF (2147483647)
Limit underflow to: 0x80000000 (-2147483648)

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648......2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_mul_s32_s8_fac2(sint32 value, sint8 factor)
{
	/* ## Operation body start [988747b5-892e-452e-b52a-d3915103f901] */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s32_mul_s32_s8_fac2                                                        


      Parameter      type      Hex Range             Physical Range                     

Input:                                                                                  
       value         sint32       80000000..FFFFFFFF    -2147483648..2147483647            
       factor        sint8              80..FF          -2 .. 1.9844                       


Output:                                                                                 
       res           sint32       80000000..FFFFFFFF    -2147483648..2147483647            

Functionality:                                                                          
        res = (value  * factor) / 64                                                    
        limit overflow  to 7FFFFFFF h                                                   
        limit underflow to 80000000 h                                                   
	 */

	/*~E*/
	sint32 tmp_factor = factor;
	/* Factor multiplication */
	/* Check for overflow */
	if ( ( ( (sint64)value * tmp_factor ) / 64 ) >= (sint64)S32_MAX )
	{
		res_ret =  S32_MAX;
	}
	else
	{
		/* Check for underflow */
		if ( ( ( (sint64)value * tmp_factor ) / 64 ) <= (sint64)S32_MIN )
		{
			res_ret =  S32_MIN;
		}
		else
		{
			res_ret =  (sint32)( ( (sint64)value * tmp_factor ) / 64 );
		}
	}

	return res_ret ;
	/* ## Operation body end [988747b5-892e-452e-b52a-d3915103f901] */
}

/** This operation shall multiply an sint16 value by an uint16 value with underflow and overflow limitation

@param value First parameter

Range:		8000(H)......7FFF(H)
		  -32768......32767
@param factor Second parameter

Range:		00(H)......FFFF(H)
		    0.....65535
@return (value * factor)
Limit overflow to:    0x7FFF (32767)
Limit underflow to:  0x8000 (-32768)

Range:		8000(H)......7FFF(H)
		  -32768......32767 */
#include "iopt_memmap.h"

static inline  sint16 s16_mul_s16_u16(sint16 value, uint16 factor)
{
	/* ## Operation body start [ef4a9a82-8936-45e2-8cfc-66de7b1f5f98] */
	sint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s16_mul_s16_u16                                                

         Parameter         type      Hex Range         Physical Range     

Input:                                                                    
         value             sint16       8000..7FFF       -32768..32767       
         factor            uint16          0..FFFF        0..65535           

Output:                                                                   
         res               sint16       8000..7FFF       -32768..32767       

Functionality:                                                            
        res = value*factor                                                
        overflow : limit to 7FFFH                                         
        underflow: limit to 8000H                                         
	 */

	/*~E*/
	if (((sint32)value *(sint32) factor) >= S16_MAX)
	{
		res_ret =  S16_MAX;
	}
	else
	{
		if (((sint32)value *(sint32) factor) <= S16_MIN)
		{
			res_ret =  S16_MIN;
		}
		else
		{
			res_ret =  (sint16)((sint32)value *(sint32) factor);
		}
	}
	return res_ret ;
	/* ## Operation body end [ef4a9a82-8936-45e2-8cfc-66de7b1f5f98] */
}

/** This operation shall multiply an uint16 value by a factor of 0...255.9960938 (shift 8 bits to the right) with overflow limitation

@param value Value

Range:		00(H)......FFFF(H)
		    0.....65535
@param factor Factor to be multiplied

Range:		00(H)......FFFF(H)
		 0...255.9960938
@return (value * factor) >> 8
Limit overflow to: 0x7FFF (32767)

Range:		8000(H).....7FFF(H)
		   -32768....32767 */
#include "iopt_memmap.h"

static inline  sint16 s16_mul_u16_u16_fac256(uint16 value, uint16 factor)
{
	/* ## Operation body start [6ece1af0-ef50-47fb-aaea-e72793a6e07a] */
	sint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s16_mul_u16_u16_fac256                                         

         Parameter         type      Hex Range     Physical Range         

Input:                                                                    
         value             uint16       0..FFFF       0 ... 65535            
         factor            uint16       0..FFFF       0..255.9960938         

Output:                                                                   
         res               sint16       8000..7FFF    -32768..32767          

Functionality:                                                            
        res = (value*factor)/256                                          
        overflow : limit to 7FFFH                                         
	 */

	/*~E*/
	if ( (((uint32)value * (uint32)factor)/256U) >= (uint32)S16_MAX)
	{
		res_ret =  S16_MAX;
	}
	else
	{
		res_ret =  (sint16)(((uint32)value * (uint32)factor)/256U);
	}
	return res_ret ;
	/* ## Operation body end [6ece1af0-ef50-47fb-aaea-e72793a6e07a] */
}

/** This operation shall multiply an sint16 value by an uint16 value

@param value First parameter

Range:		8000(H)......7FFF(H)
		  -32768......32767
@param factor Second parameter

Range:		00(H)......FFFF(H)
		    0.....65535
@return (value * factor)

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648....2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_mul_s16_u16(sint16 value, uint16 factor)
{
	/* ## Operation body start [4f584370-0cd6-4720-8622-c713ef989c71] */
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s32_mul_s16_u16                                                      

      Parameter      type      Hex Range            Physical Range             

Input:                                                                         
       value         sint16       8000..7FFF           -32768..32767              
       factor        uint16       0..FFFF               0..65535                  

Output:                                                                        
       res           sint32       80000000..7FFFFFFF   -2147483648..2147483647    

Functionality:                                                                 
        res = value*factor                                                     
	 */

	/*~E*/
	/*FUNCTION_ID:65*/
	return ((sint32)value *(sint32) factor);
	/* ## Operation body end [4f584370-0cd6-4720-8622-c713ef989c71] */
}

/** This operation shall multiply an sint32 value by an uint16 value with overflow and underflow limitation

@param value First parameter

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648....2147483647
@param factor Second parameter

Range:		00(H)......FFFF(H)
		    0.....65535
@return (value * factor)
Limit overflow to:    0x7FFFFFFF (2147483647)
Limit underflow to:  0x80000000 (-2147483648)

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648....2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_mul_s32_u16(sint32 value, uint16 factor)
{
	/* ## Operation body start [476e8255-b4f4-44d8-9f9a-61920899b435] */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s32_mul_s32_u16                                               

      Parameter     type      Hex Range          Physical Range           

Input:                                                                    
       value         sint32   80000000..7FFFFFFF  -2147483648..2147483647    
       factor        uint16          0..FFFF                0..65535         

Output:                                                                   
       res           sint32   80000000..7FFFFFFF  -2147483648..2147483647    

Functionality:                                                            
        res = value*factor                                                
        overflow : limit to 7FFFFFFFH                                     
        underflow: limit to 80000000H                                     
	 */

	/*~E*/
	/*FUNCTION_ID:66*/
	uint32 tmp_factor = factor;
	/* compare if factor is negative */
	if ( tmp_factor == 0U )
	{
		res_ret = (sint32) U16_MIN;
	}
	else
	{
		/* compare if value is positive */
		if ( value >= 0 )
		{
			/* compare if the result is greater than maximum limit */
			if ( ((uint32)S32_MAX / tmp_factor) > (uint32)value )
			{
				res_ret =  (sint32)((uint32)value * tmp_factor);
			}
			else
			{
				res_ret =  S32_MAX;
			}
		}
		else
		{
			/* comapre if result is less than minimum limit */
			if ( (S32_MIN / (sint32)tmp_factor) < value )
			{
				res_ret =  (sint32)(value * (sint32)tmp_factor);
			}
			else
			{
				res_ret =  S32_MIN;
			}
		}
	}
	return res_ret ;
	/* ## Operation body end [476e8255-b4f4-44d8-9f9a-61920899b435] */
}

/** This operation shall multiply an uint32 value by an uint16 value with overflow limitation

@param x_value First parameter

Range:		00(H)......FFFFFFFF(H)
		    0.....4294967295
@param y_value Second parameter

Range:		00(H)......FFFF(H)
		    0.....65535
@return (x_value * y_value)
Limit overflow to:    0xFFFFFFFF (4294967295)

Range:		00(H)......FFFFFFFF(H)
		    0.....4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_mul_u32_u16(uint32 x_value, uint16 y_value)
{
	/* ## Operation body start [7da79970-ad9a-497f-9eb1-f68a4df1700a] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION:u32_mul_u32_u16                                                  


    Parameter       type       Hex Range     Physical Range               

Input:                                                                    
     value          uint32       0..FFFFFFFF    0..4294967295                
     factor         uint16       0..FFFF        0..65535                     


Output:                                                                   
     res            uint32       0..FFFFFFFF    0..4294967295                

Functionality:                                                            
        res = (value*factor)                                              
        limit overflow to FFFFFFFFH                                       
	 */

	/*~E*/
	/*FUNCTION_ID:111*/
	uint32 tmp_y_value = y_value;
	/* compare if y_value is zero*/
	if ( tmp_y_value == 0U)
	{
		res_ret =  U32_MIN;
	}
	else
	{
		/* compare if result is greater than maximum limit */
		if ( (U32_MAX / tmp_y_value) > x_value )
		{
			res_ret =  (uint32)((uint32)x_value * (uint32)tmp_y_value);

		}
		else
		{
			res_ret =  U32_MAX;
		}
	}
	return res_ret ;
	/* ## Operation body end [7da79970-ad9a-497f-9eb1-f68a4df1700a] */
}

/** This operation shall perform the calculation ((uint8(param1) - uint8(param2)) * sint8(param3)) + uint8(param2) with overflow and underflow limitation

@param x_value First parameter

Range:		00(H)....FF(H)
		    0.....255
@param y_value Second parameter

Range:		00(H)....FF(H)
		    0.....255
@param factor Factor to be multiplied

Range:		80(H)....7F(H)
		   -4....3.96
@return ((x_value - y_value) * factor )/32 + y_value
Limit overflow to:    0xFF (255)
Limit underflow to:  0x00 (0)

Range:		00(H).....FF(H)
		   0 ... 255 */
#include "iopt_memmap.h"

static inline  uint8 u8_cal1_u8_u8_s8(uint8 x_value, uint8 y_value, sint8 factor)
{
	/* ## Operation body start [2643de51-b336-4449-bfcf-2f02a54d68d2] */
	uint8 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION:  u8_cal1_u8_u8_s8                                               


      Parameter     type     Hex Range       Physical Range               

Input:                                                                    
       x_value       uint8       0..FF          0..255                       
       y_value       uint8       0..FF          0..255                       
       factor        sint8       80..7F         -4..3.96                     


Output:                                                                   
       res           uint8       0..FF          0..255                       

Functionality:                                                            
        res = (x_value-y_value)*factor/32 +y_value                        
        limit overflow : FFH                                              
        limit underflow: 0                                                
	 */

	/*~E*/
	/*FUNCTION_ID:112*/
	sint32  temp;
	temp = ((sint32)((sint32)x_value - (sint32)y_value) * (sint32)factor)/32;
	temp += (sint32)y_value;
	if (temp >=(sint32)U8_MAX)
	{
		res_ret =  U8_MAX;
	}
	else
	{
		if (temp <= (sint32)U8_MIN)
		{
			res_ret =  U8_MIN;
		}
		else
		{
			res_ret =  (uint8)temp;
		}
	}

	return res_ret ;
	/* ## Operation body end [2643de51-b336-4449-bfcf-2f02a54d68d2] */
}

/** This operation shall perform the calculation ((uint16(param1) - uint16(param2)) * sint8(param3)) + uint16(param2) with overflow and underflow limitation

@param x_value First parameter

Range:		00(H)....FFFF(H)
		    0.....65535
@param y_value Second parameter

Range:		00(H)....FFFF(H)
		    0.....65535
@param factor Factor to be multiplied

Range:		80(H)....7F(H)
		   -4....3.96
@return ((x_value - y_value) * factor )/32 + y_value
Limit overflow to:    0xFFFF (65535)
Limit underflow to:  0x00 (0)

Range:		00(H).....FFFF(H)
		   0 ... 65535 */
#include "iopt_memmap.h"

static inline  uint16 u16_cal1_u16_u16_s8(uint16 x_value, uint16 y_value, sint8 factor)
{
	/* ## Operation body start [cc806932-cd5f-4b0e-b88c-a6680e56c856] */
	uint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION:  u16_cal1_u16_u16_s8                                            


      Parameter     type       Hex Range      Physical Range              

Input:                                                                    
       x_value       uint16       0..FFFF        0..65535                    
       y_value       uint16       0..FFFF        0..65535                    
       factor        sint8        80..FF        -4..3.97                     


Output:                                                                   
       res           uint16       0..FFFF        0..65535                    

Functionality:                                                            
        res = (x_value-y_value)*factor+y_value                            
        limit overflow : FFFFH                                            
        limit underflow: 0                                                
	 */

	/*~E*/
	/*FUNCTION_ID:113*/
	sint32  temp;

	temp = ((sint32)x_value - (sint32)y_value);
	temp = ((sint32)temp * (sint32)factor) / 32;
	temp += (sint32)y_value;

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

	return res_ret ;
	/* ## Operation body end [cc806932-cd5f-4b0e-b88c-a6680e56c856] */
}

/** This operation shall multiply an uint16 value by an uint16 value with overflow limitation

@param value First parameter

Range:		00(H)......FFFF(H)
		    0......65535
@param factor Second parameter

Range:		00(H)......FFFF(H)
		    0......65535
@return (value * factor)
Limit overflow to:    0xFFFF (65535)

Range:		00(H)......FFFF(H)
		    0......65535 */
#include "iopt_memmap.h"

static inline  uint16 u16_mul_u16_u16(uint16 value, uint16 factor)
{
	/* ## Operation body start [076cf570-eb9d-4c5d-8d23-5ec31c250616] */
	uint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION:  u16_mul_u16_u16                                                


      Parameter     type     Hex Range    Physical Range                  

Input:                                                                    
       x_value       uint16       0..FFFF        0..65535                    
       y_value       uint16       0..FFFF        0..65535                    


Output:                                                                   
       res           uint16       0..FFFF        0..65535                    

Functionality:                                                            
        res = x_value*y_value                                             
        limit overflow : FFFFH                                            

	 */

	/*~E*/
	/*FUNCTION_ID:114*/

	if ( ((uint32)value * (uint32)factor) > U16_MAX)
	{
		res_ret =  U16_MAX;
	}
	else
	{
		res_ret =  (uint16)(value * factor);
	}
	return res_ret ;
	/* ## Operation body end [076cf570-eb9d-4c5d-8d23-5ec31c250616] */
}

/** This operation shall multiply two uint16 values and returns an uint32 result

@param val1 First parameter

Range:		00(H)......FFFF(H)
		    0......65535
@param val2 Second parameter

Range:		00(H)......FFFF(H)
		    0......65535
@return (val1 * val2)

Range:		00(H)......FFFFFFFF(H)
		    0.....4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_mul_u16_u16(uint16 val1, uint16 val2)
{
	/* ## Operation body start [0e79ef7f-8037-4edf-839a-85d87b8e290f] */
	/*FUNCTION_ID:115*/
	return ((uint32)val1 * (uint32)val2);
	/* ## Operation body end [0e79ef7f-8037-4edf-839a-85d87b8e290f] */
}

/** This operation shall multiply two sint16 values and returns an sint32 result

@param val1 First parameter

Range:		8000(H)......7FFF(H)
		   -32768....32767
@param val2 Second parameter

Range:		8000(H)......7FFF(H)
		   -32768....32767
@return (val1 * val2)

Range:		80000000(H)......7FFFFFFF(H)
		  -2147483648....2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_mul_s16_s16(sint16 val1, sint16 val2)
{
	/* ## Operation body start [843742f6-fad4-4ee1-beeb-dd544fff6a6f] */
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s32_mul_s16_s16                                                      

      Parameter       type     Hex Range            Physical Range             

Input:                                                                         
         val1         sint16      8000..7FFF           -32768..32767              
         val2         sint16      8000..7FFF           -32768..32767              

Output:                                                                        
         res          sint32      80000000..7FFFFFFF   -2147483648..2147483647    

Functionality:                                                                 
         res =   val1*val2                                                     
	 */

	/*~E*/
	/*FUNCTION_ID:116*/
	return ((sint32)val1 * (sint32)val2);
	/* ## Operation body end [843742f6-fad4-4ee1-beeb-dd544fff6a6f] */
}

/** This operation shall multiply an uint32 value by a sint32 value and returns an uint32 result with overflow and underflow limitation

@param val1 First parameter

Range of results:	0(H).....FFFFFFFF(H)
			   0 ... 4294967295
@param val2 Second parameter

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648....2147483647
@return (val1  * val2)
Limit overflow to:   0xFFFFFFFF(4294967295)
Limit underflow to: 0x00 (0)

Range of results:	0(H).....FFFFFFFF(H)
			   0 ... 4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_mul_u32_s32(uint32 val1, sint32 val2)
{
	/* ## Operation body start [b2230543-d754-4a8f-935c-f799c73d3858] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u32_mul_u32_s32                                                        

         Parameter         type      Hex Range           Physical Range          

Input:                                                                           
         val1              uint32       0..FFFFFFFF         0..4294967295           
         val2              sint32       80000000..7FFFFFFF  -2147483648..2147483647 

Output:                                                                          
         res               uint32       0..FFFFFFFF         0..4294967295           

Functionality:                                                                   
        res = val1 * val2                                                        
        overflow : limit to FFFFFFFFH                                            
        underflow: limit to 00000000H                                            
	 */

	/*~E*/
	/*FUNCTION_ID:133*/
	/* Check for underflow */
	if ( val2 <= (sint32)(U32_MIN) )
	{
		res_ret =  U32_MIN;
	}
	else
	{
		/* Check for overflow */
		if ( (U32_MAX / (uint32)val2) >= val1)
		{
			res_ret =  (uint32)( val1 * (uint32)val2 );
		}
		else
		{
			res_ret =  U32_MAX;
		}
	}
	return res_ret ;
	/* ## Operation body end [b2230543-d754-4a8f-935c-f799c73d3858] */
}

/** This operation shall multiply two sint32 values returns an uint32 result with overflow and underflow limitation

@param val1 First parameter

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648....2147483647
@param val2 Second parameter

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648....2147483647
@return (val1  * val2)
Limit overflow to:   0xFFFFFFFF(4294967295)
Limit underflow to: 0x00 (0)

Range of results:	0(H).....FFFFFFFF(H)
			   0 ... 4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_mul_s32_s32(sint32 val1, sint32 val2)
{
	/* ## Operation body start [f98ec3ae-99ae-4c73-9385-7671c1815102] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u32_mul_s32_s32                                                        

         Parameter         type      Hex Range           Physical Range          

Input:                                                                           
         val1              sint32       80000000..7FFFFFFF  -2147483648..2147483647 
         val2              sint32       80000000..7FFFFFFF  -2147483648..2147483647 

Output:                                                                          
         res               uint32       0..FFFFFFFF         0..4294967295           

Functionality:                                                                   
        res = val1 * val2                                                        
        overflow : limit to FFFFFFFFH                                            
        underflow: limit to 00000000H                                            
	 */

	/*~E*/
	sint64 tmp_res;
	tmp_res = (sint64)val1 * val2;
	/* Check for underflow */
	if ( tmp_res <= (sint64)U32_MIN )
	{
		res_ret =  U32_MIN;
	}
	else
	{
		/* check for overflow */
		if ( tmp_res >= (sint64)U32_MAX )
		{
			res_ret =  U32_MAX;

		}
		else
		{
			res_ret =  (uint32)tmp_res;
		}
	}

	return res_ret ;
	/* ## Operation body end [f98ec3ae-99ae-4c73-9385-7671c1815102] */
}

/** This operation shall multiply two uint32 values returns an uint32 result with overflow limitation

@param val1 First parameter

Range:			0(H).....FFFFFFFF(H)
			   0 ... 4294967295
@param val2 Second parameter

Range:			0(H).....FFFFFFFF(H)
			   0 ... 4294967295
@return (val1  * val2)
Limit overflow to:   0xFFFFFFFF(4294967295)

Range:			0(H).....FFFFFFFF(H)
			   0 ... 4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_mul_u32_u32(uint32 val1, uint32 val2)
{
	/* ## Operation body start [7ab24637-74ed-4f28-8424-b57c9b7de13a] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u32_mul_u32_u32                                                       

         Parameter         type      Hex Range           Physical Range          

Input:                                                                           
         val1              uint32       0..FFFFFFFF         0..4294967295           
         val2              uint32       0..FFFFFFFF         0..4294967295           

Output:                                                                          
         res               uint32       0..FFFFFFFF         0..4294967295           

Functionality:                                                                   
        res = val1 * val2                                                        
        overflow : limit to FFFFFFFFH                                            
        underflow: limit to 00000000H                                            
	 */

	/*~E*/
	/* Check if second input prameter is zero */
	if ( val2 == 0U )
	{
		res_ret =  U32_MIN;
	}
	else
	{
		/* Check for overflow */
		if ( (U32_MAX/val2) >= val1 )
		{
			res_ret =  (val1 * val2);
		}
		else
		{
			res_ret =  U32_MAX;
		}
	}
	return res_ret ;
	/* ## Operation body end [7ab24637-74ed-4f28-8424-b57c9b7de13a] */
}

/** This operation shall multiply an uint32 value by an sint32 value and returns an sint32 result with overflow and underflow limitation

@param val1 First parameter

Range of results:	0(H).....FFFFFFFF(H)
			   0 ... 4294967295
@param val2 Second parameter

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648....2147483647
@return (val1 * val2)
Limit overflow to:    0x7FFFFFFF (2147483647)
Limit underflow to:  0x80000000 (-2147483648)

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648....2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_mul_u32_s32(uint32 val1, sint32 val2)
{
	/* ## Operation body start [44cf9028-ca20-406b-9c64-f62cd84ee640] */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s32_mul_u32_s32                                                        

         Parameter         type      Hex Range           Physical Range          

Input:                                                                           
         value             uint32       00000000..FFFFFFFF  0..4294967295           
         factor            sint32       80000000..7FFFFFFF  -2147483648..2147483647 

Output:                                                                          
         res               sint32       80000000..7FFFFFFF  -2147483648..2147483647 
Functionality:                                                                   
        res = value*factor                                                       
        overflow : limit to 7FFFFFFFH                                            
        underflow: limit to 80000000H                                            
	 */

	/*~E*/
	uint32 abs_val2;
	/* Code enhanced to avoid 0x80000000/-1 calculation which is undefined for divw instruction */
	if (val2 < 0)
	{
		abs_val2 = (uint32)(-val2);
	}
	else
	{
		abs_val2 = (uint32)val2;
	}
	if ( abs_val2 == 0U )
	{
		res_ret =  (sint32)U32_MIN;
	}
	else
	{
		/* Compare if signed input is positive */
		if ( val2 > 0 )
		{
			/* Check for overflow */
			if (((uint32)S32_MAX/abs_val2) >= val1 )
			{
				res_ret =  (sint32)(val1 * abs_val2);
			}
			else
			{
				res_ret =  S32_MAX;
			}
		}
		else
		{
			/* Check for underflow */
			if (((uint32)S32_MIN / abs_val2) <= val1 )
			{
				res_ret =  S32_MIN;
			}
			else
			{
				res_ret =  (sint32)((sint64)val1 * val2);
			}
		}
	}
	return res_ret ;
	/* ## Operation body end [44cf9028-ca20-406b-9c64-f62cd84ee640] */
}

/** This operation shall multiply two sint32 values returns an sint32 result with overflow and underflow limitation

@param val1 First parameter

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648....2147483647
@param val2 Second parameter

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648....2147483647
@return (val1 * val2)
Limit overflow to:    0x7FFFFFFF (2147483647)
Limit underflow to:  0x80000000 (-2147483648)

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648....2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_mul_s32_s32(sint32 val1, sint32 val2)
{
	/* ## Operation body start [4b67dc3c-6397-49c5-98d1-e5e861d2bc82] */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s32_mul_s32_s32                                                         

         Parameter         type      Hex Range           Physical Range          

Input:                                                                           
         value             sint32       80000000..7FFFFFFF  -2147483648..2147483647 
         factor            sint32       80000000..7FFFFFFF  -2147483648..2147483647 

Output:                                                                          
         res               sint32       80000000..7FFFFFFF  -2147483648..2147483647 
Functionality:                                                                   
        res = value*factor                                                       
        overflow : limit to 7FFFFFFFH                                            
        underflow: limit to 80000000H                                            
	 */

	/*~E*/
	sint64 res;
	res = (sint64)val1 * val2;
	/* Check for underflow */
	if ( res <= (sint64)S32_MIN )
	{
		res_ret =  S32_MIN;
	}
	else
	{
		/* Check for overflow */
		if ( res >= (sint64)S32_MAX )
		{
			res_ret =  S32_MAX;
		}
		else
		{
			res_ret =  (sint32)res;
		}
	}
	return res_ret ;
	/* ## Operation body end [4b67dc3c-6397-49c5-98d1-e5e861d2bc82] */
}

/** This operation shall determine the maximum in a table of type uint16 and returns the location of the maximum

@param tab Pointer to table in which maximum value position has to be determined

Range:
	Range of table values: 00(H)....FFFF(H)
				0.....65535
@param tablen Length of table

Range:		00(H)....FF(H)
		    0.....255
@return Location of the maximum of the table of type uint8

Range:		00(H).....FF(H)
		   0.......255 */
#include "iopt_memmap.h"

static inline  uint8 u8_max_tab_u16p_u8(const uint16 * tab, uint8 tablen)
{
	/* ## Operation body start [4ebcc575-e2fa-46ff-a6bb-81a8a89d64ad] */

	/*~A*/
	/*~+:Description*/
	/*
FUNCTION:  u8_max_tab_u16p_u8                                              

         Parameter         type      Hex Range       Physical Range       

Input:                                                                    
         tab               uint16        0..FFFF         0..65535            
         tablen            uint8         0..FF           0..255              

Output:                                                                   
         stored index      uint8         0..FF           0..255              

Functionality:                                                            

Location of the maximum of the table                                      
	 */

	/*~E*/
	uint16 temp;
	uint8 i_max;
	sint16 signed_tablen;

	temp = 0;
	i_max=tablen -1U;
	for (signed_tablen=(sint16)tablen-1;signed_tablen >= 0;signed_tablen--)
	{
		if ((*(tab + (uint16)signed_tablen)) > temp)//lint !e9016 MISRA 2012 Rule 18.4: allowed by the C Coding Rules
		{
			temp = *(tab + (uint16)signed_tablen);//lint !e9016 MISRA 2012 Rule 18.4: allowed by the C Coding Rules
			i_max = (uint8)signed_tablen;

		}
	}
	return i_max;

	/* ## Operation body end [4ebcc575-e2fa-46ff-a6bb-81a8a89d64ad] */
}

/** This operation shall limit an sint8 value to a limit in dependence on the sign of the limit (minmaxwert). If the limit is +ve overflow shall be limited and if it is -ve underflow shall be limited

@param value Value to be limited

Range:		80(H)......7F(H)
		  -128....127
@param minmaxwert Limit value

Range:		80(H)......7F(H)
		  -128....127
@return result = minmaxwert limited (if value < minmaxwert) AND (minmaxwert < 0)
result = minmaxwert limited (if value > minmaxwert) AND (minmaxwert > 0)
result = value                      (if the above condition are not satisfied)

Range:		80(H)......7F(H)
		  -128.....127 */
#include "iopt_memmap.h"

static inline  sint8 s8_min_max_s8_s8(sint8 value, sint8 minmaxwert)
{
	/* ## Operation body start [a7e6a5d9-742d-4392-ae33-2965cb5deb83] */
	sint8 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s8_min_max_s8_s8                                                

         Parameter         type   Hex Range       Physical Range          

Input:                                                                    
         value              sint8     80..7F          -128..127              
         minmaxwert         sint8     80..7F          -128..127              

Output:                                                                   
         res                sint8     80..7F          -128..127              

Functionality:                                                            
        res = value                                                       
        res=minmaxwert       , if minmaxwert>0 and value>minmaxwert       
                           (OR)if minmaxwert<0 and value<minmaxwert       

	 */

	/*~E*/
	if (minmaxwert >=0)
	{
		if (value > minmaxwert)
		{
			res_ret =  minmaxwert;
		}
		else
		{
			res_ret =  value;
		}
	}
	else
	{
		if (value < minmaxwert)
		{
			res_ret =  minmaxwert;
		}
		else
		{
			res_ret = (value);
		}
	}

	return res_ret ;
	/* ## Operation body end [a7e6a5d9-742d-4392-ae33-2965cb5deb83] */
}

/** This operation shall limit a value of type sint8 between minimum or maximum values of type sint8

@param value value to be limited

Range:		80(H)......7F(H)
		  -128....127
@param minimum Minimum value

Range:		80(H)......7F(H)
		  -128....127
@param maximum Maximum value

Range:		80(H)......7F(H)
		  -128....127
@return result = value, if minimum <= value <=maximum
result = value limited to minimum, if value < minimum
result = value limited to maximum, if value > maximum

Range:		80(H)......7F(H)
		  -128.....127 */
#include "iopt_memmap.h"

static inline  sint8 s8_min_max_s8_s8_s8(sint8 value, sint8 minimum, sint8 maximum)
{
	/* ## Operation body start [8f79d396-b147-4a5c-b3d1-416fd396bd41] */
	sint8 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s8_min_max_s8_s8_s8                                             

         Parameter         type   Hex Range       Physical Range          

Input:                                                                    
         value              sint8    80..7F          -128..127               
         minimum            sint8    80..7F          -128..127               
         maximum            sint8    80..7F          -128..127               

Output:                                                                   
         res                sint8    80..7F          -128..127               

Functionality:                                                            
        res    = value                                                    
        If value> maximum ,    value = maximum                            
         else if value<minimum value = minimum                            

	 */

	/*~E*/
	if (value > maximum)
	{
		res_ret =  maximum;
	}
	else
	{
		if (value < minimum)
		{
			res_ret =  minimum;
		}
		else
		{
			res_ret =  value;
		}
	}

	return res_ret ;
	/* ## Operation body end [8f79d396-b147-4a5c-b3d1-416fd396bd41] */
}

/** This operation shall limit an sint16 value to a limit in dependence on the sign of the limit (minmaxwert). If the limit is +ve overflow shall be limited, if it is -ve underflow shall be limited

@param value Value to be limited

Range:		8000(H)......7FFF(H)
		  -32768....32767
@param minmaxwert Limit value

Range:		8000(H)......7FFF(H)
		  -32768....32767
@return result = minmaxwert limited (if value < minmaxwert) AND (minmaxwert < 0)
result = minmaxwert limited (if value > minmaxwert) AND (minmaxwert > 0)
result = value                      If the above condition are not satisfied.

Range:		8000(H)......7FFF(H)
		  -32768.....32767 */
#include "iopt_memmap.h"

static inline  sint16 s16_min_max_s16_s16(sint16 value, sint16 minmaxwert)
{
	/* ## Operation body start [76b31d41-33f4-426a-9387-506429eaad96] */
	sint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s16_min_max_s16_s16                                                

         Parameter         type      Hex Range       Physical Range       

Input:                                                                    
         value              sint16      8000..7FFF       -32768..32767       
         minmaxwert         sint16      8000..7FFF       -32768..32767       

Output:                                                                   
         res                sint16      8000..7FFF       -32768..32767       
Functionality:                                                            
        res = value                                                       
        res=minmaxwert       , if minmaxwert>0 and value>minmaxwert       
                           (OR)if minmaxwert<0 and value<minmaxwert       

	 */

	/*~E*/
	if (minmaxwert >=0)
	{
		if (value > minmaxwert)
		{
			res_ret =  minmaxwert;
		}
		else
		{
			res_ret =  value;
		}
	}
	else
	{
		if (value < minmaxwert)
		{
			res_ret =  minmaxwert;
		}
		else
		{
			res_ret =  value;
		}
	}

	return res_ret ;
	/* ## Operation body end [76b31d41-33f4-426a-9387-506429eaad96] */
}

/** This operation shall limit a value of type sint16 between minimum or maximum values of type sint16

@param value value to be limited

Range:		8000(H)......7FFF(H)
		  -32768....32767
@param minimum Minimum value

Range:		8000(H)......7FFF(H)
		  -32768....32767
@param maximum Maximum value

Range:		8000(H)......7FFF(H)
		  -32768....32767
@return result = value, if minimum <= value <=maximum
result = value limited to minimum, if value < minimum
result = value limited to maximum, if value > maximum

Range:		8000(H)......7FFF(H)
		  -32768.....32767 */
#include "iopt_memmap.h"

static inline  sint16 s16_min_max_s16_s16_s16(sint16 value, sint16 minimum, sint16 maximum)
{
	/* ## Operation body start [2ae6e5d5-9519-457c-b3ac-09e8b660e468] */
	sint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s16_min_max_s16_s16_s16                                             

         Parameter         type      Hex Range       Physical Range       

Input:                                                                    
         value              sint16      8000..7FFF       -32768..32767       
         minimum            sint16      8000..7FFF       -32768..32767       
         maximum            sint16      8000..7FFF       -32768..32767       


Output:                                                                   
         res                sint16      8000..7FFF       -32768..32767       


Functionality:                                                            
        res    = value                                                    
        If value> maximum ,    value = maximum                            
         else if value<minimum value = minimum                            

	 */

	/*~E*/
	if (value > maximum)
	{
		res_ret =  maximum;
	}
	else
	{
		if (value < minimum)
		{
			res_ret =  minimum;
		}
		else
		{
			res_ret =  value;
		}
	}

	return res_ret ;
	/* ## Operation body end [2ae6e5d5-9519-457c-b3ac-09e8b660e468] */
}

/** This operation shall limit a value of type uint8 between minimum or maximum values of type uint8

@param value value to be limited

Range:		00(H)......FF(H)
		     0....255
@param minimum Minimum value

Range:		00(H)......FF(H)
		     0....255
@param maximum Maximum value

Range:		00(H)......FF(H)
		     0....255
@return result = value, if minimum <= value <=maximum
result = value limited to minimum, if value < minimum
result = value limited to maximum, if value > maximum

Range:		00(H)......FF(H)
		     0.....255 */
#include "iopt_memmap.h"

static inline  uint8 u8_min_max_u8_u8_u8(uint8 value, uint8 minimum, uint8 maximum)
{
	/* ## Operation body start [e52dc3d6-0b9a-4489-8660-addbf9b1921a] */
	uint8 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u8_min_max_u8_u8_u8                                             

         Parameter     type      Hex Range       Physical Range           

Input:                                                                    
         value          uint8         0..FF             0..255               
         minimum        uint8         0..FF             0..255               
         maximum        uint8         0..FF             0..255               

Output:                                                                   
         res            uint8         0..FF             0..255               

Functionality:                                                            
        res    = value                                                    
        If value> maximum ,    value = maximum                            
         else if value<minimum value = minimum                            


	 */

	/*~E*/
	if (value > maximum)
	{
		res_ret =  maximum;
	}
	else
	{
		if (value < minimum)
		{
			res_ret =  minimum;
		}
		else
		{
			res_ret =  value;
		}
	}

	return res_ret ;
	/* ## Operation body end [e52dc3d6-0b9a-4489-8660-addbf9b1921a] */
}

/** This operation shall limit a value of type uint16 between minimum or maximum values of type uint16

@param value value to be limited

Range:		00(H)......FFFF(H)
		     0....65535
@param minimum Minimum value

Range:		00(H)......FFFF(H)
		     0....65535
@param maximum Maximum value

Range:		00(H)......FFFF(H)
		     0....65535
@return result = value, if minimum <= value <=maximum
result = value limited to minimum, if value < minimum
result = value limited to maximum, if value > maximum

Range:		00(H)......FFFF(H)
		     0.....65535 */
#include "iopt_memmap.h"

static inline  uint16 u16_min_max_u16_u16_u16(uint16 value, uint16 minimum, uint16 maximum)
{
	/* ## Operation body start [80d0ba0a-ee43-403a-9cdc-6b775e09ca72] */
	uint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u16_min_max_u16_u16_u16                                             

         Parameter         type      Hex Range       Physical Range       

Input:                                                                    
         value             uint16        0..FFFF        0..65535             
         minimum           uint16        0..FFFF        0..65535             
         maximum           uint16        0..FFFF        0..65535             

Output:                                                                   
         res               uint16        0..FFFF        0..65535             

Functionality:                                                            
        res    = value                                                    
        If value> maximum ,    value = maximum                            
         else if value<minimum value = minimum                            

	 */

	/*~E*/
	if (value > maximum)
	{
		res_ret =  maximum;
	}
	else
	{
		if (value < minimum)
		{
			res_ret =  minimum;
		}
		else
		{
			res_ret =  value;
		}
	}

	return res_ret ;
	/* ## Operation body end [80d0ba0a-ee43-403a-9cdc-6b775e09ca72] */
}

/** This operation shall limit gradient of type sint16 to 0 with an uint16 value

@param grdlmt Gradient value

Range:		8000(H).....7FFF(H)
		 -32768.....32767
@param value Limiting value

Range: 		00(H)......FF(H)
		   0.....65535
@return result = 0, 		 if value > |gradient|
result = (gradient + value), if gradient < 0: 	 
result = (gradient - value),  if gradient > 0: 	

Range:		8000(H)......7FFF(H)
		  -32768.....32767 */
#include "iopt_memmap.h"

static inline  sint16 s16_grdlmt20_s16_u16(sint16 grdlmt, uint16 value)
{
	/* ## Operation body start [fa8bd572-da39-46b7-a2c4-f8c11c6eaefe] */
	sint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s16_grdlmt20_s16_u16                                              

         Parameter         type       Hex Range       Physical Range      

Input:                                                                    
         gradient           sint16       8000..7FFF     -32768..32767        
         value              uint16          0..FFFF          0..65535        

Output:                                                                   
         result             sint16       8000..7FFF     -32768..32767        

Functionality:                                                            
         if value >|gradient|,   res    = 0                               
   else  if gradient<0       ,   res    = gradient+value                  
   else  if gradient>0       ,   res    = gradient-value                  

	 */

	/*~E*/
	/* compare input value with the absolute value of gradient value */
	if ( ((sint32)value >= (sint32)grdlmt) && ((sint32)value >= (sint32)(-grdlmt)) )
	{
		res_ret =  0;
	}
	else
	{
		if ( grdlmt > 0 )
		{
			res_ret =  (sint16)((sint32)grdlmt - (sint32)value);
		}
		else
		{
			res_ret =  (sint16)((sint32)grdlmt + (sint32)value);
		}
	}

	return res_ret ;
	/* ## Operation body end [fa8bd572-da39-46b7-a2c4-f8c11c6eaefe] */
}

/** This operation shall normalize a value of type uint16 between a bottom and a top limits of type uint16 to a percentage [0...100%] [0...FFFF].

@param bottom_lim Bottom limit

Range: 		00(H)......FFFF(H)
		    0......65535
@param top_lim Top limit

Range: 		00(H)......FFFF(H)
		    0......65535
@param value Value to be normalized

Range: 		00(H)......FFFF(H)
		    0......65535
@return Normalized value
((value - bottom_lim)/(top_lim - bottom_lim))*10000H.

Limit result to: 	 FFFF(H) if bottom_lim >= top_lim
                         FFFF(H) if value >= top_lim
                         0000(H) if value <= bottom_lim

Range:		00(H)......FFFF(H)
		     0.....65535 */
#include "iopt_memmap.h"

static inline  uint16 u16_norm_u16_u16_u16(uint16 bottom_lim, uint16 top_lim, uint16 value)
{
	/* ## Operation body start [a741323c-80a1-4c91-8a94-84c6bbc9e65c] */
	uint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u16_norm_u16_u16_u16                                                

         Parameter         type      Hex Range       Physical Range       

Input:                                                                    
         bottom_lim         uint16         0..FFFF        0..65535           
         top_lim            uint16         0..FFFF        0..65535           
         value              uint16         0..FFFF        0..65535           

Output:                                                                   
         result             uint16         0..FFFF        0..65535           

Functionality:                                                            
   Normalizing function of a value between a bottom and a top-limit       
   to a percentage [0..100%] [0..FFFF]  (fak1-resolution)                 
              (value-bottom_lim)                                          
fak1-result = --------------------*(total range)                          
              (top_lim-bottom_lim)                                        

limitation of result to                                                   
       FFFFH   if  value >= top_lim                                       
       0H      if  value <= bottom_lim                                    
       FFFFH   if  top_lim <= bottom_lim                                  


	 */

	/*~E*/
	uint32 tmp_value = value, tmp_bottom_lim = bottom_lim, tmp_top_lim = top_lim;
	/* compare if bottom limit is greater thatn top limit or value is greater than top limit */
	if ( (tmp_bottom_lim >= tmp_top_lim) || (tmp_value >= tmp_top_lim) )
	{
		res_ret =  U16_MAX;

	}
	else
	{
		/* compare if input value is less than bottom limit */
		if ( tmp_value > tmp_bottom_lim )
		{
			/* normalizing the value to top and bottom limit */
			res_ret =  (uint16)(((tmp_value - tmp_bottom_lim) * (uint32)65536) / (tmp_top_lim - tmp_bottom_lim));

		}
		else
		{
			res_ret =  U16_MIN;

		}
	}

	return res_ret ;
	/* ## Operation body end [a741323c-80a1-4c91-8a94-84c6bbc9e65c] */
}

/** This operation shall limit an sint16 value to an upper or lower value based on the hysteresis value of type uint16.
For input_value = -32768, the expected result (limited value) is -32767.

@param input_val Input value

Range:		8000(H)......7FFF(H)
		 -32768......32767
@param hysteresis Hysteresis value

Range:		00(H)......7FFF(H)
		   0.......32767
@return value of type sint16

if (input_val >= hysteresis) then output = hysteresis
if (input_val <= -hysteresis) then output = -hysteresis
In case of limitation: 	USR0 = 1
Normal case(unlimited):	USR0=0

Range:		8000(H)......7FFF(H)
		  -32768.....32767 */
#include "iopt_memmap.h"

static inline  sint16 s16_lim_hys_s16_u16(sint16 input_val, uint16 hysteresis)
{
	/* ## Operation body start [589660aa-7504-4cc6-ae18-ce04214b9eaf] */
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s16_lim_hys_s16_u16                                                

         Parameter         type      Hex Range       Physical Range       

Input:                                                                    
         val                sint16      8000..7FFF       -32768..32767       
         hysteresis         uint16         0..7FFF            0..32767       

Output:                                                                   
         result             sint16      8000..7FFF       -32768..32767       

Functionality:                                                            
         val                                                              
         If (val >= hys) then val = hys;                                  
         if (val <= -hys) then val = -hys;                                
         In case of limitation:  lv_lim_act = 1                           
         normalcase(unlimited):lv_lim_act=0                               


	 */

	/*~E*/
	sint32 tmp_inp = (sint32)input_val;
	sint32 tmp_hys = (sint32)hysteresis;
	if (tmp_hys < 0x8000)
	{
		if ( tmp_inp <= tmp_hys )
		{
			tmp_hys = -tmp_hys;
			if ( tmp_inp >= tmp_hys )
			{
				/* DEFAULT: no limit */
			}
			else
			{
				tmp_inp = tmp_hys;
				/* negative hys is the limit */
			}
		}
		else
		{
			tmp_inp = tmp_hys;
			/* positive hys is the limit */
		}
	}
	else
	{
		/* hys out of range (0..7FFF): no limitation */
	}
	return (sint16)tmp_inp;
	/* ## Operation body end [589660aa-7504-4cc6-ae18-ce04214b9eaf] */
}

/** This operation shall find the difference between the new value and the old value in the upward direction. If it is greater than the maximum possible difference, the result shall be limited to (old value + maximum difference). Otherwise, the result shall be the new value

@param newval New value

Range:		00(H).....FFFF(H)
		   0.......65535
@param oldval Old value

Range:		00(H).....FFFF(H)
		   0.......65535
@param maxdif Maximum possible difference

Range:		00(H).....FFFF(H)
		   0.......65535
@return if ( newval > oldval )
{
       if  ( newval - oldval ) > maxdif
       {
	result = oldval + maxdif
       }
       else
       {
	result = newval
       }
}
else
{
       result = newval
}

Range:		00(H).......FFFF(H)
	                0...65535 */
#include "iopt_memmap.h"

static inline  uint16 u16_limitnew_up_u16_u16_u16(uint16 newval, uint16 oldval, uint16 maxdif)
{
	/* ## Operation body start [745f2d35-ea90-447d-a84e-2653f7c28b1f] */
	uint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u16_limitnew_up_u16_u16_u16                                         

         Parameter    type      Hex Range     Physical Range              

Input:                                                                    
         newval       uint16        0..FFFF         0..65535                 
         oldval       uint16        0..FFFF         0..65535                 
         maxdif       uint16        0..FFFF         0..65535                 

Output:                                                                   
         value        uint16        0..FFFF         0..65535                 

Functionality:                                                            
        if (newval > oldval)                                              
             if (newval-oldval) > maxdif                                  
               value = oldval+maxdif                                         
             else                                                         
               value = newval                                             
        else                                                              
              value = newval                                              

	 */

	/*~E*/
	if (newval > oldval)
	{
		if ((newval - oldval) > maxdif)
		{
			res_ret =  (oldval + maxdif);
		}
		else
		{
			res_ret =  (newval);
		}
	}
	else
	{
		res_ret =  (newval);
	}

	return res_ret ;
	/* ## Operation body end [745f2d35-ea90-447d-a84e-2653f7c28b1f] */
}

/** This operation shall find the difference between the new value and the old value in the downward direction. If it is greater than the maximum possible difference, the result shall be limited to (old value - maximum difference). Otherwise, the result shall be the new value

@param newval New value

Range:		00(H).....FFFF(H)
		   0.......65535
@param oldval Old value

Range:		00(H).....FFFF(H)
		   0.......65535
@param maxdif Maximum possible difference

Range:		00(H).....FFFF(H)
		   0.......65535
@return if ( oldval > newval )
{
       if  ( oldval - newval ) > maxdif
       {
	result = oldval - maxdif
       }
       else
       {
	result = newval
       }
}
else
{
       result = newval
}

Range:		00(H).......FFFF(H)
	                0...65535 */
#include "iopt_memmap.h"

static inline  uint16 u16_limitnew_down_u16_u16_u16(uint16 newval, uint16 oldval, uint16 maxdif)
{
	/* ## Operation body start [eba6f47e-87a0-459b-9c34-6e0053f2e2e5] */
	uint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u16_limitnew_down_u16_u16_u16                                       

         Parameter    type       Hex Range    Physical Range              

Input:                                                                    
         newval       uint16         0..FFFF        0..65535                 
         oldval       uint16         0..FFFF        0..65535                 
         maxdif       uint16         0..FFFF        0..65535                 

Output:                                                                   
         value        uint16         0..FFFF        0..65535                 

Functionality:                                                            
        if (oldval > newval)                                              
             if (oldval-newval) > maxdif                                  
               value = oldval-maxdif                                         
             else                                                         
               value = newval                                             
        else                                                              
              value = newval                                              

	 */

	/*~E*/
	if (oldval > newval)
	{
		if ((oldval - newval) > maxdif)
		{
			res_ret =  (oldval - maxdif);
		}
		else
		{
			res_ret =  (newval);
		}
	}
	else
	{
		res_ret =  (newval);
	}

	return res_ret ;
	/* ## Operation body end [eba6f47e-87a0-459b-9c34-6e0053f2e2e5] */
}

/** This operation shall find the difference between the new value and the old value in the upward or downward direction. If it is greater than the maximum possible difference, the result shall be limited to (old value + maximum difference) or (old value - maximum difference) respectively. Otherwise, the result shall be the new value

@param newval New value

Range:		00(H).....FFFF(H)
		   0.......65535
@param oldval Old value

Range:		00(H).....FFFF(H)
		   0.......65535
@param maxdif Maximum possible difference

Range:		00(H).....FFFF(H)
		   0.......65535
@return if ( newval > oldval )
{
     if  ( newval - oldval ) > maxdif
     {
	result = oldval + maxdif
     }
     else
     {
	result = newval
     }
}
else
{    
     if  ( oldval - newval ) > maxdif
     {
	result = oldval - maxdif
     }
     else
     {
	result = newval
     }
}

Range:		00(H)...FFFF(H)
		    0...65535 */
#include "iopt_memmap.h"

static inline  uint16 u16_limitnew_u16_u16_u16(uint16 newval, uint16 oldval, uint16 maxdif)
{
	/* ## Operation body start [72e12618-96e0-4509-9b1e-3251f9ca5dc7] */
	uint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u16_limitnew_u16_u16_u16                                            

         Parameter   type       Hex Range    Physical Range               

Input:                                                                    
         newval      uint16         0..FFFF        0..65535                  
         oldval      uint16         0..FFFF        0..65535                  
         maxdif      uint16         0..FFFF        0..65535                  

Output:                                                                   
         value       uint16         0..FFFF        0..65535                  

Functionality:                                                            
        if (newval > oldval)                                              
             if (newval-oldval) > maxdif                                  
               value = oldval+maxdif                                         
             else                                                         
               value = newval                                             
        else                                                              
             if (oldval-newval) > maxdif                                  
               value = oldval-maxdif                                         
             else                                                         
               value = newval                                             

	 */

	/*~E*/
	if (newval > oldval)
	{
		if ((newval - oldval) > maxdif)
		{
			res_ret =  (oldval + maxdif);
		}
		else
		{
			res_ret =  (newval);
		}
	}
	else
	{
		if ((oldval - newval) > maxdif)
		{
			res_ret =  (oldval - maxdif);
		}
		else
		{
			res_ret =  (newval);
		}
	}

	return res_ret ;
	/* ## Operation body end [72e12618-96e0-4509-9b1e-3251f9ca5dc7] */
}

/** This operation shall find the difference between the new value and the old value in the upward direction. If it is greater than the maximum possible difference, the result shall be limited to (old value + maximum difference). Otherwise, the result shall be the new value

@param newval New value

Range:		8000(H).....7FFF(H)
		-32768.......32767
@param oldval Old value

Range:		8000(H).....7FFF(H)
		-32768.......32767
@param maxdif Maximum possible difference

Range:		00(H).....FFFF(H)
		   0.......65535
@return if ( newval > oldval )
{
       if  ( newval - oldval ) > maxdif
       {
	result = oldval + maxdif
       }
       else
       {
	result = newval
       }
}
else
{
       result = newval
}

Range:		8000(H).......7FFF(H)
	               -32768...32767 */
#include "iopt_memmap.h"

static inline  sint16 s16_limitnew_up_s16_s16_u16(sint16 newval, sint16 oldval, uint16 maxdif)
{
	/* ## Operation body start [2f1f97d6-bada-48f2-863e-0c3ee0f5fdc7] */
	sint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s16_limitnew_up_s16_s16_u16                                         

         Parameter   type       Hex Range      Physical Range             

Input:                                                                    
         newval      sint16       8000..7FFF      -32768..32767              
         oldval      sint16       8000..7FFF      -32768..32767              
         maxdif      uint16         0..FFFF         0..65535                 

Output:                                                                   
         value       sint16       8000..7FFF      -32768..32767              

Functionality:                                                            
        if (newval > oldval)                                              
             if (newval-oldval) > maxdif                                  
               value = oldval+maxdif                                         
             else                                                         
               value = newval                                             
        else                                                              
               value = newval                                             

	 */

	/*~E*/
	if (newval > oldval)
	{
		if ((sint32)(newval - oldval) > (sint32)maxdif)
		{
			res_ret =  (sint16)(oldval + (sint16)maxdif);
		}
		else
		{
			res_ret =  (newval);
		}
	}
	else
	{
		res_ret =  (newval);
	}

	return res_ret ;
	/* ## Operation body end [2f1f97d6-bada-48f2-863e-0c3ee0f5fdc7] */
}

/** This operation shall find the difference between the new value and the old value in the downward direction. If it is greater than the maximum possible difference, the result shall be limited to (old value - maximum difference). Otherwise, the result shall be the new value

@param newval New value

Range:		8000(H).....7FFF(H)
		-32768.......32767
@param oldval Old value

Range:		8000(H).....7FFF(H)
		-32768.......32767
@param maxdif Maximum possible difference

Range:		00(H).....FFFF(H)
		   0.......65535
@return if ( oldval > newval )
{
       if  ( oldval - newval ) > maxdif
       {
	result = oldval - maxdif
       }
       else
       {
	result = newval
       }
}
else
{
       result = newval
}

Range:		8000(H).......7FFF(H)
	               -32768...32767 */
#include "iopt_memmap.h"

static inline  sint16 s16_limitnew_down_s16_s16_u16(sint16 newval, sint16 oldval, uint16 maxdif)
{
	/* ## Operation body start [e3b3fcaa-71d6-419a-a32f-9ddb57639fef] */
	sint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s16_limitnew_down_s16_s16_u16                                       

         Parameter   type       Hex Range       Physical Range            

Input:                                                                    
         newval      sint16       8000..7FFF       -32768..32767             
         oldval      sint16       8000..7FFF       -32768..32767             
         maxdif      uint16         0..FFFF          0..65535                

Output:                                                                   
         value       sint16       8000..7FFF       -32768..32767             

Functionality:                                                            
        if (oldval > newval)                                              
            if (oldval-newval) > maxdif                                   
               value = oldval-maxdif                                         
             else                                                         
               value = newval                                             
        else                                                              
               value = newval                                             

	 */

	/*~E*/
	if (oldval > newval)
	{
		if ((sint32)(oldval - newval) > (sint32)maxdif)
		{
			res_ret =   (oldval - (sint16)maxdif);
		}
		else
		{
			res_ret =  (newval);
		}
	}
	else
	{
		res_ret =  (newval);
	}

	return res_ret ;
	/* ## Operation body end [e3b3fcaa-71d6-419a-a32f-9ddb57639fef] */
}

/** This operation shall find the difference between the new value and the old value in the upward or downward direction. If it is greater than the maximum possible difference, the result shall be limited to (old value + maximum difference) or (old value - maximum difference) respectively. Otherwise, the result shall be the new value

@param newval New value

Range:		8000(H).....7FFF(H)
		-32768.......32767
@param oldval Old value

Range:		8000(H).....7FFF(H)
		-32768.......32767
@param maxdif Maximum possible difference

Range:		00(H).....FFFF(H)
		   0.......65535
@return if ( newval > oldval )
{
     if  ( newval - oldval ) > maxdif
     {
	result = oldval + maxdif
     }
     else
     {
	result = newval
     }
}
else
{    
     if  ( oldval - newval ) > maxdif
     {
	result = oldval - maxdif
     }
     else
     {
	result = newval
     }
}

Range:		8000(H).....7FFF(H)
		   -32768...32767 */
#include "iopt_memmap.h"

static inline  sint16 s16_limitnew_s16_s16_u16(sint16 newval, sint16 oldval, uint16 maxdif)
{
	/* ## Operation body start [5b4fd126-105a-4993-9d17-ed7889115dd7] */
	sint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s16_limitnew_s16_s16_u16                                            

         Parameter   type      Hex Range       Physical Range             

Input:                                                                    
         newval      sint16       8000..7FFF     -32768..32767               
         oldval      sint16       8000..7FFF     -32768..32767               
         maxdif      uint16         0..FFFF        0..65535                  

Output:                                                                   
         value       sint16       8000..7FFF     -32768..32767               

Functionality:                                                            
        if (newval > oldval)                                              
             if (newval-oldval) > maxdif                                  
               value = oldval+maxdif                                         
             else                                                         
               value = newval                                             
        else                                                              
             if (oldval-newval) > maxdif                                  
               value = oldval-maxdif                                         
             else                                                         
               value = newval                                             

	 */

	/*~E*/
	if (newval > oldval)
	{
		if ((sint32)(newval - oldval) > (sint32)maxdif)
		{
			res_ret =  (sint16)(oldval + (sint16)maxdif);
		}
		else
		{
			res_ret =  (newval);
		}
	}
	else
	{
		if ((sint32)(oldval - newval) > (sint32)maxdif)
		{
			res_ret =  (oldval - (sint16)maxdif);
		}
		else
		{
			res_ret =  (newval);
		}
	}

	return res_ret ;
	/* ## Operation body end [5b4fd126-105a-4993-9d17-ed7889115dd7] */
}

/** This operation shall return an uint16 value, which is the minimum of the two input uint16 values

@param value1 First value

Range:		00(H).....FFFF(H)
		   0.......65535
@param value2 Second value

Range:		00(H).....FFFF(H)
		   0.......65535
@return if (x_value < y_value)
{
       result = x_value
}
else
{
      result = y_value
}

Range:		00(H)......FFFF(H)
		     0.....65535 */
#include "iopt_memmap.h"

static inline  uint16 u16_min_u16_u16(uint16 value1, uint16 value2)
{
	/* ## Operation body start [369d50d4-384a-4754-be83-baf7f3dfca95] */
	uint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u16_min_u16_u16                                                    

         Parameter   type       Hex Range        Physical Range           

Input:                                                                    
         x           uint16         0..FFFF            0..65535              
         y           uint16         0..FFFF            0..65535              

Output:                                                                   
         result      uint16         0..FFFF            0..65535              

Functionality:                                                            
         compare x with y and return minimum value                        
         if (x <= y) then result = x                                      
         else result = y                                                  

	 */

	/*~E*/
	if (value1<value2)
	{
		res_ret =  (value1);
	}
	else
	{
		res_ret =  (value2);
	}
	return res_ret ;
	/* ## Operation body end [369d50d4-384a-4754-be83-baf7f3dfca95] */
}

/** This operation shall return an sint16 value, which is the minimum of the two input sint16 values

@param value1 First value

Range:		8000(H).....7FFF(H)
		 -32768......32767
@param value2 Second value

Range:		8000(H).....7FFF(H)
		 -32768......32767
@return if (x_value < y_value)
{
       result = x_value
}
else
{
      result = y_value
}

Range:		8000(H)......7FFF(H)
		  -32768.....32767 */
#include "iopt_memmap.h"

static inline  sint16 s16_min_s16_s16(sint16 value1, sint16 value2)
{
	/* ## Operation body start [4d422c0e-1717-4697-9316-39277a91f00c] */
	sint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s16_min_s16_s16                                                    

         Parameter   type      Hex Range       Physical Range             

Input:                                                                    
         x           sint16      8000..7FFF       -32768..32767              
         y           sint16      8000..7FFF       -32768..32767              

Output:                                                                   
         result      sint16      8000..7FFF       -32768..32767              

Functionality:                                                            
         compare x with y and return minimum value                        
         if (x <= y) then result = x                                      
         else result = y                                                  

	 */

	/*~E*/
	if (value1<value2)
	{
		res_ret =  (value1);
	}
	else
	{
		res_ret =  (value2);
	}
	return res_ret ;
	/* ## Operation body end [4d422c0e-1717-4697-9316-39277a91f00c] */
}

/** This operation shall return an uint16 value, which is the maximum of the two input uint16 values

@param value1 First value

Range:		00(H).....FFFF(H)
		   0.......65535
@param value2 Second value

Range:		00(H).....FFFF(H)
		   0.......65535
@return if (x_value > y_value)
{
       result = x_value
}
else
{
      result = y_value
}

Range:		00(H)......FFFF(H)
		     0.....65535 */
#include "iopt_memmap.h"

static inline  uint16 u16_max_u16_u16(uint16 value1, uint16 value2)
{
	/* ## Operation body start [719be9b5-666b-4f1b-a235-fd0d79bc8988] */
	uint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u16_max_u16_u16                                                    

         Parameter    type       Hex Range       Physical Range           

Input:                                                                    
         x             uint16        0..FFFF          0..65535               
         y             uint16        0..FFFF          0..65535               

Output:                                                                   
         result        uint16        0..FFFF          0..65535               

Functionality:                                                            
         compare x with y and return minimum value                        
         if (x <= y) then result = y                                      
         else result = x                                                  

	 */

	/*~E*/
	if (value1>value2)
	{
		res_ret =  (value1);
	}
	else
	{
		res_ret =  (value2);
	}
	return res_ret ;
	/* ## Operation body end [719be9b5-666b-4f1b-a235-fd0d79bc8988] */
}

/** This operation shall return an sint16 value, which is the maximum of the two input sint16 values

@param value1 First value

Range:		8000(H).....7FFF(H)
		 -32768......32767
@param value2 Second value

Range:		8000(H).....7FFF(H)
		 -32768......32767
@return if (x_value > y_value)
{
       result = x_value
}
else
{
      result = y_value
}

Range:		8000(H)......7FFF(H)
		  -32768.....32767 */
#include "iopt_memmap.h"

static inline  sint16 s16_max_s16_s16(sint16 value1, sint16 value2)
{
	/* ## Operation body start [d2f682b1-c102-4174-9201-74ec2008dfc2] */
	sint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s16_max_s16_s16                                                   

         Parameter    type      Hex Range       Physical Range            

Input:                                                                    
         x            sint16      8000..7FFF       -32768..32767             
         y            sint16      8000..7FFF       -32768..32767             

Output:                                                                   
         result       sint16      8000..7FFF       -32768..32767             

Functionality:                                                            
         compare x with y and return minimum value                        
         if (x <= y) then result = y                                      
         else result = x                                                  

	 */

	/*~E*/
	if (value1>value2)
	{
		res_ret =  (value1);
	}
	else
	{
		res_ret =  (value2);
	}
	return res_ret ;
	/* ## Operation body end [d2f682b1-c102-4174-9201-74ec2008dfc2] */
}

/** This operation shall limit a value of type uint32 between minimum or maximum values of type uint32

@param value value to be limited

Range:		00(H)......FFFFFFFF(H)
		     0....4294967295
@param minimum Minimum value

Range:		00(H)......FFFFFFFF(H)
		     0....4294967295
@param maximum Maximum value

Range:		00(H)......FFFFFFFF(H)
		     0....4294967295
@return result = value, if minimum <= value <=maximum
result = value limited to minimum, if value < minimum
result = value limited to maximum, if value > maximum

Range:		00(H)......FFFFFFFF(H)
		     0.....4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_min_max_u32_u32_u32(uint32 value, uint32 minimum, uint32 maximum)
{
	/* ## Operation body start [16c859b8-7eb6-4aab-9171-d0dfd1b743fc] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u32_min_max_u32_u32_u32                                                 

         Parameter      type          Hex Range           Physical Range      

Input:                                                                        
         value          uint32      00000000..FFFFFFFF        0..4294967295      
         minimum        uint32      00000000..FFFFFFFF        0..4294967295      
         maximum        uint32      00000000..FFFFFFFF        0..4294967295      

Output:                                                                       
         res            uint32      00000000..FFFFFFFF        0..4294967295      

Functionality:                                                                
        If value> maximum ,    value = maximum                                
        else if value<minimum value = minimum                                 
             else  res    = value                                             

	 */

	/*~E*/
	/* Check if input is greater than max-limit */
	if ( value >= maximum )
	{
		res_ret =  maximum;
	}
	else
	{
		/* Check if input is lower than min-limit */
		if ( value <= minimum )
		{
			res_ret =  minimum;
		}
		else
		{
			res_ret =  value;
		}
	}

	return res_ret ;
	/* ## Operation body end [16c859b8-7eb6-4aab-9171-d0dfd1b743fc] */
}

/** This operation shall limit an sint32 value to a limit in dependence on the sign of the limit (minmaxwert). If the limit is +ve overflow shall be limited, if it is -ve underflow shall be limited

@param value Value to be limited

Range:		80000000(H)......7FFFFFFF(H)
		  -2147483648....2147483647
@param minmaxwert Limit value

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648....2147483647
@return result = minmaxwert limited (if value < minmaxwert) AND (minmaxwert < 0)
result = minmaxwert limited (if value > minmaxwert) AND (minmaxwert > 0)
result = value                      If the above condition are not satisfied.


Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648.....2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_min_max_s32_s32(sint32 value, sint32 minmaxwert)
{
	/* ## Operation body start [4c76d6d0-de78-4681-9512-c66828f32758] */
	sint32 res_ret;

	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s32_min_max_s32_s32                                                              

         Parameter         type          Hex Range                 Physical Range       

Input:                                                                                  
         value              sint32      80000000..7FFFFFFF      -2147483648....+2147483647 
         minmaxwert         sint32      80000000..7FFFFFFF      -2147483648....+2147483647 

Output:                                                                                 
         res                sint32      80000000..7FFFFFFF      -2147483648....+2147483647 
Functionality:                                                                          
        res=minmaxwert       , if minmaxwert>0 and value>minmaxwert                     
                               (OR)if minmaxwert<0 and value<minmaxwert                 
        res = value                                                                     

	 */

	/*~E*/
	if ( minmaxwert >= 0 )
	{
		/* check if input is greater than the limit */
		if ( value > minmaxwert )
		{
			res_ret =  minmaxwert;
		}
		else
		{
			res_ret =  value;
		}
	}
	else
	{
		/* check if input is less than the limit */
		if ( value < minmaxwert )
		{
			res_ret =  minmaxwert;
		}
		else
		{
			res_ret =  value;
		}
	}

	return res_ret ;
	/* ## Operation body end [4c76d6d0-de78-4681-9512-c66828f32758] */
}

/** This operation shall find the difference between the new value and the old value in the upward direction. If it is greater than the maximum possible difference, the result shall be limited to (old value + maximum difference). Otherwise, the result shall be the new value

@param newval New value

Range:		00(H).....FFFFFFFF(H)
		   0.......4294967295
@param oldval Old value

Range:		00(H).....FFFFFFFF(H)
		   0.......4294967295
@param maxdif Maximum possible difference

Range:		00(H).....FFFFFFFF(H)
		   0.......4294967295
@return if ( newval > oldval )
{
       if  ( newval - oldval ) > maxdif
       {
	result = oldval + maxdif
       }
       else
       {
	result = newval
       }
}
else
{
       result = newval
}

Range:		00(H).......FFFFFFFF(H)
	                 0...4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_limitnew_up_u32_u32_u32(uint32 newval, uint32 oldval, uint32 maxdif)
{
	/* ## Operation body start [588bfdcf-b17a-4073-b7da-a7dcb3cfac48] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u32_limitnew_up_u32_u32_u32                                         

         Parameter   type      Hex Range       Physical Range             

Input:                                                                    
         newval      uint32      0..FFFFFFFF      0..4294967295              
         oldval      uint32      0..FFFFFFFF      0..4294967295              
         maxdif      uint32      0..FFFFFFFF      0..4294967295              

Output:                                                                   
         value       uint32      0..FFFFFFFF      0..4294967295              

Functionality:                                                            
        if (newval > oldval)                                              
             if (newval-oldval) > maxdif                                  
               value = oldval+maxdif                                         
             else                                                         
               value = newval                                             
        else                                                              
              value = newval                                              

	 */

	/*~E*/
	if (newval > oldval)
	{
		if ((newval - oldval) > maxdif)
		{
			res_ret =  (oldval+maxdif);
		}
		else
		{
			res_ret =  (newval);
		}
	}
	else
	{
		res_ret =  (newval);
	}

	return res_ret ;
	/* ## Operation body end [588bfdcf-b17a-4073-b7da-a7dcb3cfac48] */
}

/** This operation shall find the difference between the new value and the old value in the downward direction. If it is greater than the maximum possible difference, the result shall be limited to (old value - maximum difference). Otherwise, the result shall be the new value

@param newval New value

Range:		00(H).....FFFFFFFF(H)
		   0.......4294967295
@param oldval Old value

Range:		00(H).....FFFFFFFF(H)
		   0.......4294967295
@param maxdif Maximum possible difference

Range:		00(H).....FFFFFFFF(H)
		   0.......4294967295
@return if ( oldval > newval )
{
       if  ( oldval - newval ) > maxdif
       {
	result = oldval - maxdif
       }
       else
       {
	result = newval
       }
}
else
{
       result = newval
}

Range:		00(H).......FFFFFFFF(H)
	                 0...4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_limitnew_down_u32_u32_u32(uint32 newval, uint32 oldval, uint32 maxdif)
{
	/* ## Operation body start [d569232b-cb22-408b-ac97-d02c20b57318] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u32_limitnew_down_u32_u32_u32                                       

         Parameter   type      Hex Range      Physical Range              

Input:                                                                    
         newval      uint32      0..FFFFFFFF     0..4294967295               
         oldval      uint32      0..FFFFFFFF     0..4294967295               
         maxdif      uint32      0..FFFFFFFF     0..4294967295               

Output:                                                                   
         value       uint32      0..FFFFFFFF     0..4294967295               

Functionality:                                                            
        if (oldval > newval)                                              
             if (oldval-newval) > maxdif                                  
               value = oldval-maxdif                                         
             else                                                         
               value = newval                                             
        else                                                              
              value = newval                                              

	 */

	/*~E*/
	if (oldval > newval)
	{
		if ((oldval - newval) > maxdif)
		{
			res_ret =  (oldval - maxdif);
		}
		else
		{
			res_ret =  (newval);
		}
	}
	else
	{
		res_ret =  (newval);
	}

	return res_ret ;
	/* ## Operation body end [d569232b-cb22-408b-ac97-d02c20b57318] */
}

/** This operation shall find the difference between the new value and the old value in the upward or downward direction. If it is greater than the maximum possible difference, the result shall be limited to (old value + maximum difference) or (old value - maximum difference) respectively. Otherwise, the result shall be the new value

@param newval New value

Range:		00(H).....FFFFFFFF(H)
		   0.......4294967295
@param oldval Old value

Range:		00(H).....FFFFFFFF(H)
		   0.......4294967295
@param maxdif Maximum possible difference

Range:		00(H).....FFFFFFFF(H)
		   0.......4294967295
@return if ( newval > oldval )
{
     if  ( newval - oldval ) > maxdif
     {
	result = oldval + maxdif
     }
     else
     {
	result = newval
     }
}
else
{    
     if  ( oldval - newval ) > maxdif
     {
	result = oldval - maxdif
     }
     else
     {
	result = newval
     }
}

Range:		00(H).......FFFFFFFF(H)
	                 0...4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_limitnew_u32_u32_u32(uint32 newval, uint32 oldval, uint32 maxdif)
{
	/* ## Operation body start [2f5fcfad-ff3a-4c12-a2be-cdff2a979c64] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u32_limitnew_u32_u32_u32                                            

         Parameter    type       Hex Range       Physical Range           

Input:                                                                    
         newval       uint32       0..FFFFFFFF      0..4294967295            
         oldval       uint32       0..FFFFFFFF      0..4294967295            
         maxdif       uint32       0..FFFFFFFF      0..4294967295            

Output:                                                                   
         value        uint32       0..FFFFFFFF      0..4294967295            

Functionality:                                                            
        if (newval > oldval)                                              
             if (newval-oldval) > maxdif                                  
               value = oldval+maxdif                                         
             else                                                         
               value = newval                                             
        else                                                              
             if (oldval-newval) > maxdif                                  
               value = oldval-maxdif                                         
             else                                                         
               value = newval                                             

	 */

	/*~E*/
	if (newval > oldval)
	{
		if ((newval - oldval) > maxdif)
		{
			res_ret =  (oldval + maxdif);

		}
		else
		{
			res_ret =  (newval);
		}
	}
	else
	{
		if ((oldval - newval) > maxdif)
		{
			res_ret =  (oldval - maxdif);
		}
		else
		{
			res_ret =  (newval);

		}
	}

	return res_ret ;
	/* ## Operation body end [2f5fcfad-ff3a-4c12-a2be-cdff2a979c64] */
}

/** This operation shall find the difference between the new value and the old value in the upward direction. If it is greater than the maximum possible difference, the result shall be limited to (old value + maximum difference). Otherwise, the result shall be the new value

@param newval New value

Range:		00(H).....FFFFFFFF(H)
		   0.......4294967295
@param oldval Old value

Range:		00(H).....FFFFFFFF(H)
		   0.......4294967295
@param maxdif Maximum possible difference

Range:		00(H).....FFFF(H)
		   0.......65535
@return if ( newval > oldval )
{
       if  ( newval - oldval ) > maxdif
       {
	result = oldval + maxdif
       }
       else
       {
	result = newval
       }
}
else
{
       result = newval
}

Range:		00(H).......FFFFFFFF(H)
	                 0...4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_limitnew_up_u32_u32_u16(uint32 newval, uint32 oldval, uint16 maxdif)
{
	/* ## Operation body start [4122f2f3-84c5-463a-8811-fc92f834b0c8] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u32_limitnew_up_u32_u32_u16                                         

         Parameter   type      Hex Range       Physical Range             

Input:                                                                    
         newval      uint32      0..FFFFFFFF      0..4294967295              
         oldval      uint32      0..FFFFFFFF      0..4294967295              
         maxdif      uint16      0..FFFF          0..65535                   

Output:                                                                   
         value       uint32      0..FFFFFFFF      0..4294967295              

Functionality:                                                            
        if (newval > oldval)                                              
             if (newval-oldval) > maxdif                                  
               value = oldval+maxdif                                         
             else                                                         
               value = newval                                             
        else                                                              
              value = newval                                              

	 */

	/*~E*/
	if (newval > oldval)
	{
		if ((newval - oldval) > (uint32)maxdif)
		{
			res_ret =  (oldval + maxdif);
		}
		else
		{
			res_ret =  (newval);
		}
	}
	else
	{
		res_ret =  (newval);
	}

	return res_ret ;
	/* ## Operation body end [4122f2f3-84c5-463a-8811-fc92f834b0c8] */
}

/** This operation shall find the difference between the new value and the old value in the downward direction. If it is greater than the maximum possible difference, the result shall be limited to (old value - maximum difference). Otherwise, the result shall be the new value

@param newval New value

Range:		00(H).....FFFFFFFF(H)
		   0.......4294967295
@param oldval Old value

Range:		00(H).....FFFFFFFF(H)
		   0.......4294967295
@param maxdif Maximum possible difference

Range:		00(H).....FFFF(H)
		   0.......65535
@return if ( oldval > newval )
{
       if  ( oldval - newval ) > maxdif
       {
	result = oldval - maxdif
       }
       else
       {
	result = newval
       }
}
else
{
       result = newval
}

Range:		00(H).......FFFFFFFF(H)
	                 0...4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_limitnew_down_u32_u32_u16(uint32 newval, uint32 oldval, uint16 maxdif)
{
	/* ## Operation body start [29eb2195-3764-49f8-91c3-976da98646fe] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u32_limitnew_down_u32_u32_u16                                     

         Parameter    type      Hex Range       Physical Range            

Input:                                                                    
         newval       uint32     0..FFFFFFFF      0..4294967295              
         oldval       uint32     0..FFFFFFFF      0..4294967295              
         maxdif       uint16     0..FFFF          0..65535                   

Output:                                                                   
         value        uint32     0..FFFFFFFF      0..4294967295              

Functionality:                                                            
        if (oldval > newval)                                              
             if (oldval-newval) > maxdif                                  
               value = oldval-maxdif                                         
             else                                                         
               value = newval                                             
        else                                                              
              value = newval                                              

	 */

	/*~E*/
	if (oldval > newval)
	{
		if ((oldval - newval) > (uint32)maxdif)
		{
			res_ret =  (oldval - maxdif);
		}
		else
		{
			res_ret =  (newval);
		}
	}
	else
	{
		res_ret =  (newval);
	}

	return res_ret ;
	/* ## Operation body end [29eb2195-3764-49f8-91c3-976da98646fe] */
}

/** This operation shall find the difference between the new value and the old value in the upward or downward direction. If it is greater than the maximum possible difference, the result shall be limited to (old value + maximum difference) or (old value - maximum difference) respectively. Otherwise, the result shall be the new value

@param newval New value

Range:		00(H).....FFFFFFFF(H)
		   0.......4294967295
@param oldval Old value

Range:		00(H).....FFFFFFFF(H)
		   0.......4294967295
@param maxdif Maximum possible difference

Range:		00(H).....FFFF(H)
		   0.......65535
@return if ( newval > oldval )
{
     if  ( newval - oldval ) > maxdif
     {
	result = oldval + maxdif
     }
     else
     {
	result = newval
     }
}
else
{    
     if  ( oldval - newval ) > maxdif
     {
	result = oldval - maxdif
     }
     else
     {
	result = newval
     }
}

Range:		00(H).......FFFFFFFF(H)
	                 0...4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_limitnew_u32_u32_u16(uint32 newval, uint32 oldval, uint16 maxdif)
{
	/* ## Operation body start [d9730319-61eb-4cf9-9165-693735a89b50] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u32_limitnew_u32_u32_u16                                            

         Parameter   type       Hex Range       Physical Range            

Input:                                                                    
         newval       uint32      0..FFFFFFFF      0..4294967295             
         oldval       uint32      0..FFFFFFFF      0..4294967295             
         maxdif       uint16      0..FFFF          0..65535                  

Output:                                                                   
         value        uint32      0..FFFFFFFF      0..4294967295             

Functionality:                                                            
        if (newval > oldval)                                              
             if (newval-oldval) > maxdif                                  
               value = oldval+maxdif                                         
             else                                                         
               value = newval                                             
        else                                                              
             if (oldval-newval) > maxdif                                  
               value = oldval-maxdif                                         
             else                                                         
               value = newval                                             

	 */

	/*~E*/
	if (newval > oldval)
	{
		if ((newval - oldval) > (uint32)maxdif)
		{
			res_ret =  (oldval + maxdif);

		}
		else
		{
			res_ret =  (newval);
		}
	}
	else
	{
		if ((oldval - newval) > (uint32)maxdif)
		{
			res_ret =  (oldval - maxdif);
		}
		else
		{
			res_ret =  (newval);

		}
	}

	return res_ret ;
	/* ## Operation body end [d9730319-61eb-4cf9-9165-693735a89b50] */
}

/** This operation shall find the difference between the new value and the old value in the upward direction. If it is greater than the maximum possible difference, the result shall be limited to (old value + maximum difference). Otherwise, the result shall be the new value

@param newval New value

Range:		80000000(H).....7FFFFFFF(H)
		-2147483648.......2147483647
@param oldval Old value

Range:		80000000(H).....7FFFFFFF(H)
		-2147483648.......2147483647
@param maxdif Maximum possible difference

Range:		00(H).....FFFFFFFF(H)
		   0.......4294967295
@return if ( newval > oldval )
{
       if  ( newval - oldval ) > maxdif
       {
	result = oldval + maxdif
       }
       else
       {
	result = newval
       }
}
else
{
       result = newval
}

Range:		80000000(H).....7FFFFFFF(H)
		-2147483648.......2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_limitnew_up_s32_s32_u32(sint32 newval, sint32 oldval, uint32 maxdif)
{
	/* ## Operation body start [c2acf658-ebaf-4f1b-9aaa-1cf434205ac2] */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s32_limitnew_up_s32_s32_u32                                                      

         Parameter     type         Hex Range            Physical Range                

Input:                                                                                 
         newval        sint32     80000000..7FFFFFFF    -2147483648..2147483647           
         oldval        sint32     80000000..7FFFFFFF    -2147483648..2147483647           
         maxdif        uint32            0..FFFFFFFF              0..4294967295           

Output:                                                                                
         value         sint32     80000000..7FFFFFFF    -2147483648..2147483647           

Functionality:                                                                         
        if (newval > oldval)                                                           
             if (newval-oldval) > maxdif                                               
               value = oldval+maxdif                                                      
             else                                                                      
               value = newval                                                          
        else                                                                           
               value = newval                                                          

	 */

	/*~E*/
	if (newval > oldval)
	{
		if ((uint32)(newval - oldval) > (uint32)maxdif)
		{
			res_ret =  (sint32)((sint64)oldval + (sint64)maxdif);
		}
		else
		{
			res_ret =  (newval);
		}
	}
	else
	{
		res_ret =  (newval);
	}

	return res_ret ;
	/* ## Operation body end [c2acf658-ebaf-4f1b-9aaa-1cf434205ac2] */
}

/** This operation shall find the difference between the new value and the old value in the downward direction. If it is greater than the maximum possible difference, the result shall be limited to (old value - maximum difference). Otherwise, the result shall be the new value

@param newval New value

Range:		80000000(H).....7FFFFFFF(H)
		-2147483648.......2147483647
@param oldval Old value

Range:		80000000(H).....7FFFFFFF(H)
		-2147483648.......2147483647
@param maxdif Maximum possible difference

Range:		00(H).....FFFFFFFF(H)
		   0.......4294967295
@return if ( oldval > newval )
{
       if  ( oldval - newval ) > maxdif
       {
	result = oldval - maxdif
       }
       else
       {
	result = newval
       }
}
else
{
       result = newval
}

Range:		80000000(H).....7FFFFFFF(H)
		-2147483648.......2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_limitnew_down_s32_s32_u32(sint32 newval, sint32 oldval, uint32 maxdif)
{
	/* ## Operation body start [f80be05c-65d1-493d-9674-077b060f957b] */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s32_limitnew_down_s32_s32_u32                                                    

         Parameter    type        Hex Range            Physical Range                  

Input:                                                                                 
         newval       sint32    80000000..7FFFFFFF    -2147483648..2147483647             
         oldval       sint32    80000000..7FFFFFFF    -2147483648..2147483647             
         maxdif       uint32           0..FFFFFFFF              0..4294967295             

Output:                                                                                
         value        sint32    80000000..7FFFFFFF    -2147483648..2147483647             

Functionality:                                                                         
        if (oldval > newval)                                                           
            if (oldval-newval) > maxdif                                                
               value = oldval-maxdif                                                      
             else                                                                      
               value = newval                                                          
        else                                                                           
               value = newval                                                          

	 */

	/*~E*/
	if (oldval > newval)
	{
		if ((uint32)(oldval - newval) > (uint32)maxdif)
		{
			res_ret =  (sint32)((sint64)oldval - (sint64)maxdif);
		}
		else
		{
			res_ret =  (newval);
		}
	}
	else
	{
		res_ret =  (newval);
	}

	return res_ret ;
	/* ## Operation body end [f80be05c-65d1-493d-9674-077b060f957b] */
}

/** This operation shall find the difference between the new value and the old value in the upward or downward direction. If it is greater than the maximum possible difference, the result shall be limited to (old value + maximum difference) or (old value - maximum difference) respectively. Otherwise, the result shall be the new value

@param newval New value

Range:		80000000(H).....7FFFFFFF(H)
		-2147483648.......2147483647
@param oldval Old value

Range:		80000000(H).....7FFFFFFF(H)
		-2147483648.......2147483647
@param maxdif Maximum possible difference

Range:		00(H).....FFFFFFFF(H)
		   0.......4294967295
@return if ( newval > oldval )
{
     if  ( newval - oldval ) > maxdif
     {
	result = oldval + maxdif
     }
     else
     {
	result = newval
     }
}
else
{    
     if  ( oldval - newval ) > maxdif
     {
	result = oldval - maxdif
     }
     else
     {
	result = newval
     }
}

Range:		80000000(H).....7FFFFFFF(H)
		-2147483648.......2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_limitnew_s32_s32_u32(sint32 newval, sint32 oldval, uint32 maxdif)
{
	/* ## Operation body start [eb820e24-cc67-418d-971d-7d897aed05f5] */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s32_limitnew_s32_s32_u32                                                          

         Parameter     type         Hex Range                Physical Range              

Input:                                                                                   
         newval        sint32     80000000..7FFFFFFF       -2147483648..2147483647          
         oldval        sint32     80000000..7FFFFFFF       -2147483648..2147483647          
         maxdif        uint32            0..FFFFFFFF                 0..4294967295          

Output:                                                                                  
         value         sint32     80000000..7FFFFFFF       -2147483648..2147483647          

Functionality:                                                                           
        if (newval > oldval)                                                             
             if (newval-oldval) > maxdif                                                 
               value = oldval+maxdif                                                        
             else                                                                        
               value = newval                                                            
        else                                                                             
             if (oldval-newval) > maxdif                                                 
               value = oldval-maxdif                                                        
             else                                                                        
               value = newval                                                            

	 */

	/*~E*/
	if (newval > oldval)
	{
		if ((uint32)(newval - oldval) > (uint32)maxdif)
		{
			res_ret =  (sint32)((sint64)oldval + (sint64)maxdif);
		}
		else
		{
			res_ret =  (newval);
		}
	}
	else
	{
		if ((uint32)(oldval - newval) > maxdif)
		{
			res_ret =  (sint32)((sint64)oldval - (sint64)maxdif);
		}
		else
		{
			res_ret =  (newval);

		}
	}

	return res_ret ;
	/* ## Operation body end [eb820e24-cc67-418d-971d-7d897aed05f5] */
}

/** This operation shall find the difference between the new value and the old value in the upward direction. If it is greater than the maximum possible difference, the result shall be limited to (old value + maximum difference). Otherwise, the result shall be the new value

@param newval New value

Range:		80000000(H).....7FFFFFFF(H)
		-2147483648.......2147483647
@param oldval Old value

Range:		80000000(H).....7FFFFFFF(H)
		-2147483648.......2147483647
@param maxdif Maximum possible difference

Range:		00(H).....FFFF(H)
		   0.......65535
@return if ( newval > oldval )
{
       if  ( newval - oldval ) > maxdif
       {
	result = oldval + maxdif
       }
       else
       {
	result = newval
       }
}
else
{
       result = newval
}

Range:		80000000(H).....7FFFFFFF(H)
		-2147483648.......2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_limitnew_up_s32_s32_u16(sint32 newval, sint32 oldval, uint16 maxdif)
{
	/* ## Operation body start [8e8737d7-4fe1-4461-9bd7-33182fe52d07] */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s32_limitnew_up_s32_s32_u16                                                      

         Parameter    type         Hex Range            Physical Range                 

Input:                                                                                 
         newval       sint32     80000000..7FFFFFFF    -2147483648..2147483647            
         oldval       sint32     80000000..7FFFFFFF    -2147483648..2147483647            
         maxdif       uint16            0..FFFF                  0..65535                 

Output:                                                                                
         value        sint32     80000000..7FFFFFFF    -2147483648..2147483647            

Functionality:                                                                         
        if (newval > oldval)                                                           
             if (newval-oldval) > maxdif                                               
               value = oldval+maxdif                                                      
             else                                                                      
               value = newval                                                          
        else                                                                           
               value = newval                                                          

	 */

	/*~E*/
	if (newval > oldval)
	{
		if ((uint32)(newval - oldval) > (uint32)maxdif)
		{
			res_ret =  (sint32)(oldval + (sint32)maxdif);
		}
		else
		{
			res_ret =  (newval);
		}
	}
	else
	{
		res_ret =  (newval);
	}

	return res_ret ;
	/* ## Operation body end [8e8737d7-4fe1-4461-9bd7-33182fe52d07] */
}

/** This operation shall find the difference between the new value and the old value in the downward direction. If it is greater than the maximum possible difference, the result shall be limited to (old value - maximum difference). Otherwise, the result shall be the new value

@param newval New value

Range:		80000000(H).....7FFFFFFF(H)
		-2147483648.......2147483647
@param oldval Old value

Range:		80000000(H).....7FFFFFFF(H)
		-2147483648.......2147483647
@param maxdif Maximum possible difference

Range:		00(H).....FFFF(H)
		   0.......65535
@return if ( oldval > newval )
{
       if  ( oldval - newval ) > maxdif
       {
	result = oldval - maxdif
       }
       else
       {
	result = newval
       }
}
else
{
       result = newval
}

Range:		80000000(H).....7FFFFFFF(H)
		-2147483648.......2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_limitnew_down_s32_s32_u16(sint32 newval, sint32 oldval, uint16 maxdif)
{
	/* ## Operation body start [f4f095dd-aaaf-4975-a579-ceafeccd9fa4] */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s32_limitnew_down_s32_s32_u16                                                   

         Parameter     type        Hex Range            Physical Range                 

Input:                                                                                 
         newval        sint32    80000000..7FFFFFFF    -2147483648..2147483647            
         oldval        sint32    80000000..7FFFFFFF    -2147483648..2147483647            
         maxdif        uint16           0..FFFF                  0..65535                 

Output:                                                                                
         value         sint32    80000000..7FFFFFFF    -2147483648..2147483647            

Functionality:                                                                         
        if (oldval > newval)                                                           
            if (oldval-newval) > maxdif                                                
               value = oldval-maxdif                                                      
             else                                                                      
               value = newval                                                          
        else                                                                           
               value = newval                                                          

	 */

	/*~E*/
	if (oldval > newval)
	{
		if ((uint32)(oldval - newval) > (uint32)maxdif)
		{
			res_ret =  (sint32)(oldval - (sint32)maxdif);
		}
		else
		{
			res_ret =  (newval);
		}
	}
	else
	{
		res_ret =  (newval);
	}

	return res_ret ;
	/* ## Operation body end [f4f095dd-aaaf-4975-a579-ceafeccd9fa4] */
}

/** This operation shall find the difference between the new value and the old value in the upward or downward direction. If it is greater than the maximum possible difference, the result shall be limited to (old value + maximum difference) or (old value - maximum difference) respectively. Otherwise, the result shall be the new value

@param newval New value

Range:		80000000(H).....7FFFFFFF(H)
		-2147483648.......2147483647
@param oldval Old value

Range:		80000000(H).....7FFFFFFF(H)
		-2147483648.......2147483647
@param maxdif Maximum possible difference

Range:		00(H).....FFFF(H)
		   0.......65535
@return if ( newval > oldval )
{
     if  ( newval - oldval ) > maxdif
     {
	result = oldval + maxdif
     }
     else
     {
	result = newval
     }
}
else
{    
     if  ( oldval - newval ) > maxdif
     {
	result = oldval - maxdif
     }
     else
     {
	result = newval
     }
}

Range:		80000000(H).....7FFFFFFF(H)
		-2147483648.......2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_limitnew_s32_s32_u16(sint32 newval, sint32 oldval, uint16 maxdif)
{
	/* ## Operation body start [c8b48dea-c910-4f4b-9fe4-a4c43ddc1c79] */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s32_limitnew_s32_s32_u16                                                   

         Parameter     type         Hex Range               Physical Range       

Input:                                                                           
         newval        sint32     80000000..7FFFFFFF       -2147483648..2147483647  
         oldval        sint32     80000000..7FFFFFFF       -2147483648..2147483647  
         maxdif        uint16            0..FFFF                     0..65535       

Output:                                                                          
         value         sint32     80000000..7FFFFFFF       -2147483648..2147483647  

Functionality:                                                                   
        if (newval > oldval)                                                     
             if (newval-oldval) > maxdif                                         
               value = oldval+maxdif                                                
             else                                                                
               value = newval                                                    
        else                                                                     
             if (oldval-newval) > maxdif                                         
               value = oldval-maxdif                                                
             else                                                                
               value = newval                                                    

	 */

	/*~E*/
	if (newval > oldval)
	{
		if (((uint32)(newval - oldval)) > (uint32)maxdif)
		{
			res_ret =  (sint32)(oldval + (sint32)maxdif);
		}
		else
		{
			res_ret =  (newval);
		}
	}
	else
	{
		if (((uint32)(oldval - newval)) > (uint32)maxdif)
		{
			res_ret =  (sint32)(oldval - (sint32)maxdif);
		}
		else
		{
			res_ret =  (newval);

		}
	}

	return res_ret ;
	/* ## Operation body end [c8b48dea-c910-4f4b-9fe4-a4c43ddc1c79] */
}

/** This operation shall limit a value of type sint32 between minimum or maximum values of type sint32

@param value value to be limited

Range:		80000000(H).....7FFFFFFF(H)
		-2147483648.......2147483647
@param minimum Minimum value

Range:		80000000(H).....7FFFFFFF(H)
		-2147483648.......2147483647
@param maximum Maximum value

Range:		80000000(H).....7FFFFFFF(H)
		-2147483648.......2147483647
@return result = value, if minimum <= value <=maximum
result = value limited to minimum, if value < minimum
result = value limited to maximum, if value > maximum

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648.....2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_min_max_s32_s32_s32(sint32 value, sint32 minimum, sint32 maximum)
{
	/* ## Operation body start [ff5535f4-b747-41c6-9ba5-37ff2c866316] */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s32_min_max_s32_s32_s32                                                       

         Parameter      type         Hex Range                Physical Range          

Input:                                                                                
         value          sint32     80000000..7FFFFFFF       -2147483648..2147483647      
         minimum        sint32     80000000..7FFFFFFF       -2147483648..2147483647      
         maximum        sint32     80000000..7FFFFFFF       -2147483648..2147483647      


Output:                                                                               
         res            sint32     80000000..7FFFFFFF       -2147483648..2147483647      


Functionality:                                                                        
        res    = value                                                                
        If value> maximum ,    value = maximum                                        
         else if value<minimum value = minimum                                        

	 */

	/*~E*/
	if (value > maximum)
	{
		res_ret =  maximum;
	}
	else
	{
		if (value < minimum)
		{
			res_ret =  minimum;
		}
		else
		{
			res_ret =  value;
		}
	}

	return res_ret ;
	/* ## Operation body end [ff5535f4-b747-41c6-9ba5-37ff2c866316] */
}

/** This operation shall find the difference between the new value and the old value in the upward direction. If it is greater than the maximum possible difference, the result shall be limited to (old value + maximum difference). Otherwise, the result shall be the new value

@param newval New value

Range:		80(H).....7F(H)
		 -128.......127
@param oldval Old value

Range:		80(H).....7F(H)
		 -128.......127
@param maxdif Maximum possible difference

Range:		00(H).....FF(H)
		   0.......255
@return if ( newval > oldval )
{
       if  ( newval - oldval ) > maxdif
       {
	result = oldval + maxdif
       }
       else
       {
	result = newval
       }
}
else
{
       result = newval
}

Range:		80(H).....7F(H)
		 -128.......127 */
#include "iopt_memmap.h"

static inline  sint8 s8_limitnew_up_s8_s8_u8(sint8 newval, sint8 oldval, uint8 maxdif)
{
	/* ## Operation body start [aed4dcc7-fa44-4e5a-b258-08a39df32439] */
	sint8 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s8_limitnew_up_s8_s8_u8                                         

         Parameter   type       Hex Range      Physical Range             

Input:                                                                    
         newval      sint8          80..7F          -128..127                
         oldval      sint8          80..7F          -128..127                
         maxdif      uint8           0..FF             0..255                

Output:                                                                   
         value       sint8          80..7F          -128..127                

Functionality:                                                            
        if (newval > oldval)                                              
             if (newval-oldval) > maxdif                                  
               value = oldval+maxdif                                      
             else                                                         
               value = newval                                             
        else                                                              
               value = newval                                             

	 */

	/*~E*/
	if (newval > oldval)
	{
		if ((sint16)(newval - oldval) > (sint16)maxdif)
		{
			res_ret =  (sint8)((sint16)oldval + (sint16)maxdif);
		}
		else
		{
			res_ret =  (newval);
		}
	}
	else
	{
		res_ret =  (newval);
	}
	return res_ret ;
	/* ## Operation body end [aed4dcc7-fa44-4e5a-b258-08a39df32439] */
}

/** This operation shall find the difference between the new value and the old value in the downward direction. If it is greater than the maximum possible difference, the result shall be limited to (old value - maximum difference). Otherwise, the result shall be the new value

@param newval New value

Range:		80(H).....7F(H)
		 -128.......127
@param oldval Old value

Range:		80(H).....7F(H)
		 -128.......127
@param maxdif Maximum possible difference

Range:		00(H).....FF(H)
		   0.......255
@return if ( oldval > newval )
{
       if  ( oldval - newval ) > maxdif
       {
	result = oldval - maxdif
       }
       else
       {
	result = newval
       }
}
else
{
       result = newval
}

Range:		80(H).....7F(H)
		 -128.......127 */
#include "iopt_memmap.h"

static inline  sint8 s8_limitnew_down_s8_s8_u8(sint8 newval, sint8 oldval, uint8 maxdif)
{
	/* ## Operation body start [b0a1b21e-b9c4-4638-8982-f93464c300ea] */
	sint8 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s8_limitnew_down_s8_s8_u8                                       

         Parameter   type       Hex Range       Physical Range            

Input:                                                                    
         newval      sint8          80..7F            -128..127              
         oldval      sint8          80..7F            -128..127              
         maxdif      uint8           0..FF               0..255              

Output:                                                                   
         value       sint8          80..7F            -128..127              

Functionality:                                                            
        if (oldval > newval)                                              
            if (oldval-newval) > maxdif                                   
               value = oldval-maxdif                                      
             else                                                         
               value = newval                                             
        else                                                              
               value = newval                                             

	 */

	/*~E*/
	sint32 temp_oldval=(sint32)oldval;
	sint32 temp_maxdif=(sint32)maxdif;
	if (temp_oldval > newval)
	{
		if ((temp_oldval - newval) > temp_maxdif)
		{
			res_ret =   (sint8)(temp_oldval -  temp_maxdif);
		}
		else
		{
			res_ret =  (newval);
		}
	}
	else
	{
		res_ret =  (newval);
	}

	return res_ret ;
	/* ## Operation body end [b0a1b21e-b9c4-4638-8982-f93464c300ea] */
}

/** This operation shall find the difference between the new value and the old value in the upward or downward direction. If it is greater than the maximum possible difference, the result shall be limited to (old value + maximum difference) or (old value - maximum difference) respectively. Otherwise, the result shall be the new value

@param newval New value

Range:		80(H).....7F(H)
		 -128.......127
@param oldval Old value

Range:		80(H).....7F(H)
		 -128.......127
@param maxdif Maximum possible difference

Range:		00(H).....FF(H)
		   0.......255
@return if ( newval > oldval )
{
     if  ( newval - oldval ) > maxdif
     {
	result = oldval + maxdif
     }
     else
     {
	result = newval
     }
}
else
{    
     if  ( oldval - newval ) > maxdif
     {
	result = oldval - maxdif
     }
     else
     {
	result = newval
     }
}

Range:		80(H).....7F(H)
		 -128.......127 */
#include "iopt_memmap.h"

static inline  sint8 s8_limitnew_s8_s8_u8(sint8 newval, sint8 oldval, uint8 maxdif)
{
	/* ## Operation body start [7ca7e891-1d3c-410b-920c-432312e2b991] */
	sint8 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s8_limitnew_s8_s8_u8                                            

         Parameter   type      Hex Range       Physical Range             

Input:                                                                    
         newval      sint8         80..7F           -128..127                
         oldval      sint8         80..7F           -128..127                
         maxdif      uint8          0..FF              0..255                

Output:                                                                   
         value       sint8         80..7F           -128..127                

Functionality:                                                            
        if (newval > oldval)                                              
             if (newval-oldval) > maxdif                                  
               value = oldval+maxdif                                      
             else                                                         
               value = newval                                             
        else                                                              
             if (oldval-newval) > maxdif                                  
               value = oldval-maxdif                                      
             else                                                         
               value = newval                                             

	 */

	/*~E*/
	sint32 temp_oldval=(sint32)oldval;
	sint32 temp_maxdif=(sint32)maxdif;

	if (newval > temp_oldval)
	{
		if ((newval - temp_oldval) > temp_maxdif)
		{
			res_ret =  (sint8)(temp_oldval + temp_maxdif);
		}
		else
		{
			res_ret =  (newval);
		}
	}
	else
	{
		if ((temp_oldval - newval) > temp_maxdif)
		{
			res_ret =  (sint8)(temp_oldval - temp_maxdif);
		}
		else
		{
			res_ret =  (newval);
		}
	}

	return res_ret ;
	/* ## Operation body end [7ca7e891-1d3c-410b-920c-432312e2b991] */
}

/** This operation shall find the difference between the new value and the old value in the upward direction. If it is greater than the maximum possible difference, the result shall be limited to (old value + maximum difference). Otherwise, the result shall be the new value

@param newval New value

Range:		00(H).....FF(H)
		   0.......255
@param oldval Old value

Range:		00(H).....FF(H)
		   0.......255
@param maxdif Maximum possible difference

Range:		00(H).....FF(H)
		   0.......255
@return if ( newval > oldval )
{
       if  ( newval - oldval ) > maxdif
       {
	result = oldval + maxdif
       }
       else
       {
	result = newval
       }
}
else
{
       result = newval
}

Range:		00(H).....FF(H)
		   0.......255 */
#include "iopt_memmap.h"

static inline  uint8 u8_limitnew_up_u8_u8_u8(uint8 newval, uint8 oldval, uint8 maxdif)
{
	/* ## Operation body start [1e180375-6497-4dd0-b06f-4d84a17fe3ff] */
	uint8 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u8_limitnew_up_u8_u8_u8                                        

         Parameter    type      Hex Range     Physical Range              

Input:                                                                    
         newval       uint8         0..FF           0..255                   
         oldval       uint8         0..FF           0..255                   
         maxdif       uint8         0..FF           0..255                   

Output:                                                                   
         value        uint8         0..FF           0..255                   

Functionality:                                                            
        if (newval > oldval)                                              
             if (newval-oldval) > maxdif                                  
               value = oldval+maxdif                                      
             else                                                         
               value = newval                                             
        else                                                              
              value = newval                                              

	 */

	/*~E*/
	if (newval > oldval)
	{
		if ((newval - oldval) > maxdif)
		{
			res_ret =  (oldval + maxdif);
		}
		else
		{
			res_ret =  (newval);
		}
	}
	else
	{
		res_ret =  (newval);
	}
	return res_ret ;
	/* ## Operation body end [1e180375-6497-4dd0-b06f-4d84a17fe3ff] */
}

/** This operation shall find the difference between the new value and the old value in the downward direction. If it is greater than the maximum possible difference, the result shall be limited to (old value - maximum difference). Otherwise, the result shall be the new value

@param newval New value

Range:		00(H).....FF(H)
		   0.......255
@param oldval Old value

Range:		00(H).....FF(H)
		   0.......255
@param maxdif Maximum possible difference

Range:		00(H).....FF(H)
		   0.......255
@return if ( oldval > newval )
{
       if  ( oldval - newval ) > maxdif
       {
	result = oldval - maxdif
       }
       else
       {
	result = newval
       }
}
else
{
       result = newval
}

Range:		00(H).....FF(H)
		   0.......255 */
#include "iopt_memmap.h"

static inline  uint8 u8_limitnew_down_u8_u8_u8(uint8 newval, uint8 oldval, uint8 maxdif)
{
	/* ## Operation body start [f541790a-62bb-46ab-8e31-554f4d689ddd] */
	uint8 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u8_limitnew_down_u8_u8_u8                                       

         Parameter    type       Hex Range    Physical Range              

Input:                                                                    
         newval       uint8          0..FF          0..255                   
         oldval       uint8          0..FF          0..255                   
         maxdif       uint8          0..FF          0..255                   

Output:                                                                   
         value        uint8          0..FF          0..255                   

Functionality:                                                            
        if (oldval > newval)                                              
             if (oldval-newval) > maxdif                                  
               value = oldval-maxdif                                      
             else                                                         
               value = newval                                             
        else                                                              
              value = newval                                              

	 */

	/*~E*/
	if (oldval > newval)
	{
		if ((oldval - newval) > maxdif)
		{
			res_ret =  (oldval - maxdif);
		}
		else
		{
			res_ret =  (newval);
		}
	}
	else
	{
		res_ret =  (newval);
	}

	return res_ret ;
	/* ## Operation body end [f541790a-62bb-46ab-8e31-554f4d689ddd] */
}

/** This operation shall find the difference between the new value and the old value in the upward or downward direction. If it is greater than the maximum possible difference, the result shall be limited to (old value + maximum difference) or (old value - maximum difference) respectively. Otherwise, the result shall be the new value

@param newval New value

Range:		00(H).....FF(H)
		   0.......255
@param oldval Old value

Range:		00(H).....FF(H)
		   0.......255
@param maxdif Maximum possible difference

Range:		00(H).....FF(H)
		   0.......255
@return if ( newval > oldval )
{
     if  ( newval - oldval ) > maxdif
     {
	result = oldval + maxdif
     }
     else
     {
	result = newval
     }
}
else
{    
     if  ( oldval - newval ) > maxdif
     {
	result = oldval - maxdif
     }
     else
     {
	result = newval
     }
}

Range:		00(H).....FF(H)
		   0.......255 */
#include "iopt_memmap.h"

static inline  uint8 u8_limitnew_u8_u8_u8(uint8 newval, uint8 oldval, uint8 maxdif)
{
	/* ## Operation body start [54b0c6f6-8b28-48b6-ae46-d859e4acdcea] */
	uint8 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u8_limitnew_u8_u8_u8                                           

         Parameter   type       Hex Range    Physical Range               

Input:                                                                    
         newval      uint8          0..FF          0..255                    
         oldval      uint8          0..FF          0..255                    
         maxdif      uint8          0..FF          0..255                    

Output:                                                                   
         value       uint8          0..FF          0..255                    

Functionality:                                                            
        if (newval > oldval)                                              
             if (newval-oldval) > maxdif                                  
               value = oldval+maxdif                                      
             else                                                         
               value = newval                                             
        else                                                              
             if (oldval-newval) > maxdif                                  
               value = oldval-maxdif                                      
             else                                                         
               value = newval                                             

	 */

	/*~E*/
	if (newval > oldval)
	{
		if ((newval - oldval) > maxdif)
		{
			res_ret =  (oldval + maxdif);
		}
		else
		{
			res_ret =  (newval);
		}
	}
	else
	{
		if ((oldval - newval) > maxdif)
		{
			res_ret =  (oldval - maxdif);
		}
		else
		{
			res_ret =  (newval);
		}
	}

	return res_ret ;
	/* ## Operation body end [54b0c6f6-8b28-48b6-ae46-d859e4acdcea] */
}

/** This operation shall return an uint8 value, which is the minimum of the two input uint8 values

@param value1 First value

Range		00(H) FF(H)
		     0  255
@param value2 Second value

Range		00(H)  FF(H)
		     0  255
@return if (x_value < y_value)
{
     result = x_value
}
else
{
     result = y_value      
}

Range:		00(H)  FF(H)
		     0  255 */
#include "iopt_memmap.h"

static inline  uint8 u8_min_u8_u8(uint8 value1, uint8 value2)
{
	/* ## Operation body start [658bee23-6b2c-4b3c-b18d-a578192bdf9d] */
	uint8 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u8_min_u8_u8                                                    

         Parameter   type       Hex Range        Physical Range           

Input:                                                                    
         x           uint8          0..FF              0..255                
         y           uint8          0..FF              0..255                

Output:                                                                   
         result      uint8          0..FF              0..255                

Functionality:                                                            
         compare x with y and return minimum value                        
         if (x <= y) then result = x                                      
         else result = y                                                  

	 */

	/*~E*/
	if (value1<value2)
	{
		res_ret =  (value1);
	}
	else
	{
		res_ret =  (value2);
	}
	return res_ret ;
	/* ## Operation body end [658bee23-6b2c-4b3c-b18d-a578192bdf9d] */
}

/** This operation shall return an uint32 value, which is the minimum of the two input uint32 values

@param value1 First value

Range:		00(H)  FFFFFFFF(H)
		     0  4294967295
@param value2 Second value

Range:		00(H) FFFFFFFF(H)
		     0 4294967295
@return if (x_value < y_value)
{
     result = x_value
}
else
{
     result = y_value      
}

Range:		00(H)  FFFFFFFF(H)
		     0  4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_min_u32_u32(uint32 value1, uint32 value2)
{
	/* ## Operation body start [74e87075-0de3-451c-a568-6318ecb068eb] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u32_min_u32_u32                                                    

         Parameter   type       Hex Range        Physical Range           

Input:                                                                    
         x           uint32         0..FFFFFFFF            0..4294967295     
         y           uint32         0..FFFFFFFF            0..4294967295     

Output:                                                                   
         result      uint32         0..FFFFFFFF            0..4294967295     

Functionality:                                                            
         compare x with y and return minimum value                        
         if (x <= y) then result = x                                      
         else result = y                                                  

	 */

	/*~E*/
	if (value1<value2)
	{
		res_ret =  (value1);
	}
	else
	{
		res_ret =  (value2);
	}
	return res_ret ;
	/* ## Operation body end [74e87075-0de3-451c-a568-6318ecb068eb] */
}

/** This operation shall return an uint8 value, which is the maximum of the two input uint8 values

@param value1 First value

Range:		00(H) FF(H)
		     0  255
@param value2 Second value

Range:		00(H) FF(H)
		     0  255
@return if (x_value > y_value)
{
     result = x_value
}
else
{
     result = y_value      
}

Range:		00(H)  FF(H)
		     0  255 */
#include "iopt_memmap.h"

static inline  uint8 u8_max_u8_u8(uint8 value1, uint8 value2)
{
	/* ## Operation body start [8bd14414-682e-4bff-a194-babf57a7af6a] */
	uint8 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u8_max_u8_u8                                                    

         Parameter    type       Hex Range       Physical Range           

Input:                                                                    
         x             uint8          0..FF            0..255                
         y             uint8          0..FF            0..255                

Output:                                                                   
         result        uint8          0..FF            0..255                

Functionality:                                                            
         compare x with y and return maximum value                        
         if (x <= y) then result = y                                      
         else result = x                                                  

	 */

	/*~E*/
	if (value1>value2)
	{
		res_ret =  (value1);
	}
	else
	{
		res_ret =  (value2);
	}
	return res_ret ;
	/* ## Operation body end [8bd14414-682e-4bff-a194-babf57a7af6a] */
}

/** This operation shall return an uint32 value, which is the maximum of the two input uint32 values

@param value1 First value

Range:		00(H)  FFFFFFFF(H)
		     0   294967295
@param value2 Second value

Range:		00(H)  FFFFFFFF(H)
		     0  4294967295
@return if (x_value > y_value)
{
     result = x_value
}
else
{
     result = y_value      
}

Range:		00(H)  FFFFFFFF(H)
		     0  4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_max_u32_u32(uint32 value1, uint32 value2)
{
	/* ## Operation body start [c7f8776b-b8a0-49dc-9993-6b49f6748f49] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u32_max_u32_u32                                                   

         Parameter    type         Hex Range         Physical Range       

Input:                                                                    
         x             uint32        0..FFFFFFFF         0..4294967295       
         y             uint32        0..FFFFFFFF         0..4294967295       

Output:                                                                   
         result        uint32        0..FFFFFFFF         0..4294967295       

Functionality:                                                            
         compare x with y and return maximum value                        
         if (x <= y) then result = y                                      
         else result = x                                                  

	 */

	/*~E*/
	if (value1>value2)
	{
		res_ret =  (value1);
	}
	else
	{
		res_ret =  (value2);
	}
	return res_ret ;
	/* ## Operation body end [c7f8776b-b8a0-49dc-9993-6b49f6748f49] */
}

/** This operation shall return an sint8 value, which is the minimum of the two input sint8 values

@param value1 First value

Range:		80(H) 7F(H)
		  -128  127
@param value2 Second value

Range:		80(H)  7F(H)
		  -128 127
@return if (x_value < y_value)
{
     result = x_value
}
else
{
     result = y_value      
}

Range:		80(H)  7F(H)
		  -128  127 */
#include "iopt_memmap.h"

static inline  sint8 s8_min_s8_s8(sint8 value1, sint8 value2)
{
	/* ## Operation body start [b9e7e0b2-14c1-4d5e-bf11-cd481b65f2de] */
	sint8 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s8_min_s8_s8                                                    

         Parameter   type      Hex Range       Physical Range             

Input:                                                                    
         x           sint8         80..7F       -128..127                    
         y           sint8         80..7F       -128..127                    

Output:                                                                   
         result      sint8         80..7F       -128..127                    

Functionality:                                                            
         compare x with y and return minimum value                        
         if (x <= y) then result = x                                      
         else result = y                                                  

	 */

	/*~E*/
	if (value1<value2)
	{
		res_ret =  (value1);
	}
	else
	{
		res_ret =  (value2);
	}
	return res_ret ;
	/* ## Operation body end [b9e7e0b2-14c1-4d5e-bf11-cd481b65f2de] */
}

/** This operation shall return an sint32 value, which is the minimum of the two input sint32 values

@param value1 First value

Range:		80000000(H)   7FFFFFFF(H)
		 -2147483648   2147483647
@param value2 Second value

Range:		80000000(H)  7FFFFFFF(H)
		 -2147483648  2147483647
@return if (x_value < y_value)
{
     result = x_value
}
else
{
     result = y_value      
}

Range:		80000000(H)  7FFFFFFF(H)
		 -2147483648  2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_min_s32_s32(sint32 value1, sint32 value2)
{
	/* ## Operation body start [57ee6c44-5a8d-49b8-810a-1c726b9e8100] */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s32_min_s32_s32                                                              

         Parameter   type      Hex Range                 Physical Range             

Input:                                                                              
         x           sint32      80000000..7FFFFFFF      -2147483648....+2147483647    
         y           sint32      80000000..7FFFFFFF      -2147483648....+2147483647    

Output:                                                                             
         result      sint32      80000000..7FFFFFFF      -2147483648....+2147483647    

Functionality:                                                                      
         compare x with y and return minimum value                                  
         if (x <= y) then result = x                                                
         else result = y                                                            

	 */

	/*~E*/
	if (value1<value2)
	{
		res_ret =  (value1);
	}
	else
	{
		res_ret =  (value2);
	}
	return res_ret ;
	/* ## Operation body end [57ee6c44-5a8d-49b8-810a-1c726b9e8100] */
}

/** This operation shall return an sint8 value, which is the maximum of the two input sint8 values

@param value1 First value

Range:		80(H)  7F(H)
		  -128  127
@param value2 Second value

Range:		80(H)  7F(H)
		  -128  127
@return if (x_value > y_value)
{
     result = x_value
}
else
{
     result = y_value      
}

Range:		80(H)  7F(H)
		  -128  127 */
#include "iopt_memmap.h"

static inline  sint8 s8_max_s8_s8(sint8 value1, sint8 value2)
{
	/* ## Operation body start [e1ee0244-b0bc-45b2-b832-42e1f93854cf] */
	sint8 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s8_max_s8_s8                                                   

         Parameter    type      Hex Range       Physical Range            

Input:                                                                    
         x            sint8      80..7F       -128..127                      
         y            sint8      80..7F       -128..127                      

Output:                                                                   
         result       sint8      80..7F       -128..127                      

Functionality:                                                            
         compare x with y and return maximum value                        
         if (x <= y) then result = y                                      
         else result = x                                                  

	 */

	/*~E*/
	if (value1>value2)
	{
		res_ret =  (value1);
	}
	else
	{
		res_ret =  (value2);
	}
	return res_ret ;
	/* ## Operation body end [e1ee0244-b0bc-45b2-b832-42e1f93854cf] */
}

/** This operation shall return an sint32 value, which is the maximum of the two input sint32 values

@param value1 First value

Range:		80000000(H)  7FFFFFFF(H)
		 -2147483648  2147483647
@param value2 Second value

Range:		80000000(H)  7FFFFFFF(H)
		 -2147483648  2147483647
@return if (x_value > y_value)
{
     result = x_value
}
else
{
     result = y_value      
}

Range:		80000000(H)  7FFFFFFF(H)
		 -2147483648   2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_max_s32_s32(sint32 value1, sint32 value2)
{
	/* ## Operation body start [dd2dad2e-91fd-4161-a8ff-3c6b5b789303] */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
                                                                                     FUNCTION: sint32_max_sint32_sint32                                                                

                                                                                     Parameter    type      Hex Range                    Physical Range            

                                                                                     Input:                                                                                 
                                                                                     x            sint32      80000000..7FFFFFFF       -2147483648....+2147483647     
                                                                                     y            sint32      80000000..7FFFFFFF       -2147483648....+2147483647     

                                                                                     Output:                                                                                
                                                                                     result       sint32      80000000..7FFFFFFF       -2147483648....+2147483647     

                                                                                     Functionality:                                                                         
                                                                                     compare x with y and return maximum value                                     
                                                                                     if (x <= y) then result = y                                                   
                                                                                     else result = x                                                               

	 */

	/*~E*/
	if (value1>value2)
	{
		res_ret =  (value1);
	}
	else
	{
		res_ret =  (value2);
	}
	return res_ret ;
	/* ## Operation body end [dd2dad2e-91fd-4161-a8ff-3c6b5b789303] */
}

/** This operation shall perform 'Schmitt-Trigger-Hysteresis' operation.

@param val Input value

Range:		80000000(H)......7FFFFFFF(H)
		 -2147483648.......2147483647
@param upr_thd @param upr_thd  Denominator

 Range:		80000000(H).....7FFFFFFF(H)
 		 -2147483648....2147483647
@param low_thd @param low_thd  Numerator

 Range:		80000000(H).....7FFFFFFF(H)
 		 -2147483648....2147483647
@param lv_oldstate @param lv_oldstate  Numerator

 Range:		0(H).....1(H)
 		 0....1
@return if val > RSP(upr_thd), then result = 1
 if val < LSP(low_thd), then result = 0
 else result = lv_oldstate

Range : 00------FF(H) */
#include "iopt_memmap.h"

static inline  uint8 flag_cmp_hys_s32_s32_s32_flag(sint32 val, sint32 upr_thd, sint32 low_thd, uint8 lv_oldstate)
{
	/* ## Operation body start [decf8fcd-fd4d-4d3d-8884-c1fe55f68408] */
	uint8 Result ;
	if ( val > upr_thd )
	{
		Result = 1 ;
	}
	else
	{
		if ( val < low_thd )
		{
			Result = 0 ;
		}
		else
		{
			Result = lv_oldstate ;
		}
	}
	return Result;
	/* ## Operation body end [decf8fcd-fd4d-4d3d-8884-c1fe55f68408] */
}

/** This operation shall perform 'Schmitt-Trigger-Hysteresis' operation.

@param val Input value

Range:		00(H)......FFFFFFFF(H)
		 0.......4294967295
@param upr_thd @param upr_thd  Denominator

Range:		00(H)......FFFFFFFF(H)
		 0.......4294967295
@param low_thd @param low_thd  Numerator

Range:		00(H)......FFFFFFFF(H)
		 0.......4294967295
@param lv_oldstate @param lv_oldstate  Numerator

 Range:		0(H).....1(H)
 		 0....1
@return if val > RSP(upr_thd), then result = 1
 if val < LSP(low_thd), then result = 0
 else result = lv_oldstate

Range : 00------FF(H) */
#include "iopt_memmap.h"

static inline  uint8 flag_cmp_hys_u32_u32_u32_flag(uint32 val, uint32 upr_thd, uint32 low_thd, uint8 lv_oldstate)
{
	/* ## Operation body start [d4a5e2ae-9068-41fc-81af-8af9b40bd9b3] */
	uint8 Result ;
	if ( val > upr_thd )
	{
		Result = 1 ;
	}
	else
	{
		if ( val < low_thd )
		{
			Result = 0 ;
		}
		else
		{
			Result = lv_oldstate ;
		}
	}
	return Result;
	/* ## Operation body end [d4a5e2ae-9068-41fc-81af-8af9b40bd9b3] */
}

/** This operation shall calculate the average of two uint16 values to produce a result of type uint16

@param x_val First parameter

Range:		00(H)...FFFF(H)
		    0...65535
@param y_val Second parameter

Range:		00(H)...FFFF(H)
		    0...65535
@return (x_val + y_val) / 2 with round off

Range:		00(H)...FFFF(H)
  		     0...65535 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

static inline  uint16 u16_calc_av_u16_u16(uint16 x_val, uint16 y_val)
{
	/* ## Operation body start [40d1d455-0376-4880-bde3-10cfb00c082d] */
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION:  u16_calc_av_u16_u16                                          

         Parameter         type      Hex Range     Physical Range         

Input:                                                                    
         x_val              uint16      0....FFFF       0....65535           
         y_val              uint16      0....FFFF       0....65535           

Output:                                                                   
         res                uint16      0....FFFF       0....65535           

Functionality:                                                            
                      (x_val+y_val)/2 with  round  off                    
	 */

	/*~E*/
	uint32 temp;
	temp=((uint32)x_val + (uint32)y_val + 1U);

	return (uint16)(temp / 2U);
	/* ## Operation body end [40d1d455-0376-4880-bde3-10cfb00c082d] */
}
/** This operation shall perform addition of two sint8 variables with underflow and overflow limitation and return result of type sint8

@param x_value First parameter

Range:		80(H).....7F(H)
		 -128......127
@param y_value Second parameter

Range:		80(H).....7F(H)
		 -128......127
@return (x_value + y_value).
Limit overflow to 0x7F (127)
Limit underflow to 0x80 (-128)

Range:		80(H).....7F(H)
		-128......127 */
#include "iopt_memmap.h"

static inline  sint8 s8_add_s8_s8(sint8 x_value, sint8 y_value)
{
	/* ## Operation body start [60cd409c-6c54-4eb3-a2ed-a1683d17091d] */
	sint8 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s8_add_s8_s8                                                    

         Parameter     type      Hex Range       Physical Range           

Input:                                                                    
         x_value        sint8        80H..7FH        -128..127               
         y_value        sint8        80H..7FH        -128..127               

Output:                                                                   
         res            sint8        80H..7FH        -128..127               

Functionality:                                                            
        res = x_value + y_value                                           
        overflow : limit to 7FH                                           
        underflow: limit to 80H                                           
	 */

	/*~E*/
	if ( ((sint16)x_value +(sint16) y_value) >= S8_MAX)
	{
		res_ret =  S8_MAX;
	}
	else
	{
		if (((sint16)x_value +(sint16) y_value) <= S8_MIN)
		{
			res_ret =  S8_MIN;
		}
		else
		{
			res_ret =  (sint8)((sint16)x_value +(sint16) y_value);
		}
	}
	return res_ret ;
	/* ## Operation body end [60cd409c-6c54-4eb3-a2ed-a1683d17091d] */
}

/** This operation shall perform addition of uint8 and sint8 variables with overflow limitation and return result of type sint8

@param x_value First parameter

Range:		00(H).....FF(H)
		   0........255
@param y_value Second parameter

Range:		80(H).....7F(H)
		 -128......127
@return (x_value + y_value).
Limit overflow to 0x7F (127)

Range:		80(H).....7F(H)
		 -128......127 */
#include "iopt_memmap.h"

static inline  sint8 s8_add_u8_s8(uint8 x_value, sint8 y_value)
{
	/* ## Operation body start [cec42db1-b94b-4a2b-95ac-7a3f7f32a1b7] */
	sint8 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s8_add_u8_s8                                                    

         Parameter     type      Hex Range       Physical Range           

Input:                                                                    
         x_value        uint8         0..FFH            0..255               
         y_value        sint8        80H..7FH        -128..127               

Output:                                                                   
         res            sint8        80H..7FH        -128..127               

Functionality:                                                            
        res = x_value + y_value                                           
        overflow : limit to 7FH                                           
	 */

	/*~E*/
	if ( ((sint16)x_value +(sint16) y_value) >= S8_MAX)
	{
		res_ret =  S8_MAX;
	}
	else
	{
		res_ret =  (sint8)((sint16)x_value +(sint16) y_value);
	}
	return res_ret ;
	/* ## Operation body end [cec42db1-b94b-4a2b-95ac-7a3f7f32a1b7] */
}

/** This operation shall perform addition of two sint16 variables with underflow and overflow limitation and return result of type sint16

@param x_value First parameter

Range:		8000(H).....7FFF(H)
		 -32768......32767
@param y_value Second parameter

Range:		8000(H).....7FFF(H)
		 -32768......32767
@return (x_value + y_value).
Limit overflow to 0x7FFF (32767)
Limit underflow to 0x8000 (-32768)

Range:		8000(H).....7FFF(H)
		 -32768......32767 */
#include "iopt_memmap.h"

static inline  sint16 s16_add_s16_s16(sint16 x_value, sint16 y_value)
{
	/* ## Operation body start [3c41103f-d2e4-4b64-9584-48fa5f7165c7] */
	sint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s16_add_s16_s16                                                    

         Parameter        type      Hex Range       Physical Range        

Input:                                                                    
         x_value          sint16        8000..7FFFH     -32768..32767        
         y_value          sint16        8000..7FFFH     -32768..32767        

Output:                                                                   
         res              sint16        8000..7FFFH     -32768..32767        

Functionality:                                                            
        res = x_value + y_value                                           
        overflow : limit to 7FFFH                                         
        underflow: limit to 8000H                                         
	 */

	/*~E*/
	if ( ((sint32)x_value +(sint32)y_value) >= S16_MAX)
	{
		res_ret =  S16_MAX;
	}
	else
	{
		if (((sint32)x_value +(sint32)y_value) <= S16_MIN)
		{
			res_ret =  S16_MIN;
		}
		else
		{
			res_ret =  (sint16)((sint32)x_value +(sint32)y_value);
		}
	}
	return res_ret ;
	/* ## Operation body end [3c41103f-d2e4-4b64-9584-48fa5f7165c7] */
}

/** This operation shall perform addition of uint16 and sint16 variables with overflow limitation and return result of type sint16

@param x_value First parameter

Range:		0(H).....FFFF(H)
		  0......65535
@param y_value Second parameter

Range:		8000(H).....7FFF(H)
		 -32768......32767
@return (x_value + y_value).
Limit overflow to 0x7FFF (32767)

Range:		8000(H).....7FFF(H)
		 -32768......32767 */
#include "iopt_memmap.h"

static inline  sint16 s16_add_u16_s16(uint16 x_value, sint16 y_value)
{
	/* ## Operation body start [dd97ca78-77d5-411e-a83c-e6bd685a2b4e] */
	sint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s16_add_u16_s16                                                    

         Parameter       type      Hex Range       Physical Range         

Input:                                                                    
         x_value         uint16           0..FFFFH        0..65535           
         y_value         sint16        8000..7FFFH   -32768..32767           

Output:                                                                   
         res             sint16        8000..7FFFH   -32768..32767           

Functionality:                                                            
        res = x_value + y_value                                           
        overflow : limit to 7FFFH                                         
	 */

	/*~E*/
	/* FUNCTION_ID:4 */
	if (((sint32)x_value + (sint32)y_value) >= S16_MAX)
	{
		res_ret =  S16_MAX;
	}
	else
	{
		res_ret =  (sint16)((sint32)x_value + (sint32)y_value);
	}
	return res_ret ;
	/* ## Operation body end [dd97ca78-77d5-411e-a83c-e6bd685a2b4e] */
}

/** This operation shall perform addition of two sint32 variables with underflow and overflow limitation and return result of type sint32

@param x_value First parameter

Range:		80000000(H).....7FFFFFFF(H)
		-2147483648......2147483647
@param y_value Second parameter

Range:		80000000(H).....7FFFFFFF(H)
		-2147483648......2147483647
@return (x_value + y_value).
Limit overflow to 0x7FFFFFFF (2147483647)
Limit underflow to 0x80000000 (-2147483648)

Range:		80000000(H).....7FFFFFFF(H)
		-2147483648......2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_add_s32_s32(sint32 x_value, sint32 y_value)
{
	/* ## Operation body start [174c2bac-98a2-449e-a3ee-33b3ea6cc341] */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s32_add_s32_s32                                                           

         Parameter    type          Hex Range                 Physical Range     

Input:                                                                           
         x_value      sint32     80000000H...7FFFFFFFH      -2147483648..2147483647 
         y_value      sint32     80000000H...7FFFFFFFH      -2147483648..2147483647 

Output:                                                                          
         res          sint32     80000000H...7FFFFFFFH      -2147483648..2147483647 

Functionality:                                                                   
        res = x_value + y_value                                                  
        overflow : limit to 7FFFFFFFH                                            
        underflow: limit to 80000000H                                            
	 */

	/*~E*/
	if (x_value > 0 )
	{
		if (y_value > 0)
		{
			if (((sint64)x_value + (sint64)y_value) >= S32_MAX)
			{
				res_ret =   S32_MAX;
			}
			else
			{
				res_ret =   (sint32)((sint64)x_value + (sint64)y_value);
			}
		}
		else
		{
			res_ret =   (sint32)((sint64)x_value + (sint64)y_value);
		}
	}
	else
	{
		if (y_value < 0)
		{
			if (((sint64)x_value + (sint64)y_value) <= S32_MIN)
			{
				res_ret =   S32_MIN;
			}
			else
			{
				res_ret =   (sint32)((sint64)x_value + (sint64)y_value);
			}
		}
		else
		{
			res_ret =   (sint32)((sint64)x_value + (sint64)y_value);
		}
	}
	return res_ret ;
	/* ## Operation body end [174c2bac-98a2-449e-a3ee-33b3ea6cc341] */
}

/** This operation shall perform addition of uint8 and sint8 variables with underflow and overflow limitation and return result of type uint8

@param x_value First parameter

Range:		00(H).....FF(H)
		   0......255
@param y_value Second parameter

Range:		80(H).....7F(H)
		 -128......127
@return (x_value + y_value).
Limit overflow to 0xFF (255)
Limit underflow to 0x00 (0)

Range:		0(H).....FF(H)
		  0......255 */
#include "iopt_memmap.h"

static inline  uint8 u8_add_u8_s8(uint8 x_value, sint8 y_value)
{
	/* ## Operation body start [d5251e9e-293a-4238-8c2a-425c3f7f92f9] */
	uint8 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u8_add_u8_s8                                                    

         Parameter      type      Hex Range       Physical Range          

Input:                                                                    
         x_value        uint8         0..FFH            0..255               
         y_value        sint8        80..7FH         -128..127               

Output:                                                                   
         res            uint8         0..FFH            0..255               

Functionality:                                                            
        res = x_value + y_value                                           
        overflow : limit to FFH                                           
        underflow: limit to 00H                                           
	 */

	/*~E*/
	if ( ((sint16)x_value +(sint16)y_value) >= (sint16)U8_MAX)
	{
		res_ret =  U8_MAX;
	}
	else
	{
		if (((sint16)x_value +(sint16)y_value) <= (sint16)U8_MIN)
		{
			res_ret =  U8_MIN;
		}
		else
		{
			res_ret =  (uint8)((sint16)x_value +(sint16)y_value);
		}
	}
	return res_ret;
	/* ## Operation body end [d5251e9e-293a-4238-8c2a-425c3f7f92f9] */
}

/** This operation shall perform addition of two uint8 variables with overflow limitation and return result of type uint8

@param x_value First parameter

Range:		00(H).....FF(H)
		   0......255
@param y_value Second parameter

Range:		00(H).....FF(H)
		   0......255
@return (x_value + y_value).
Limit overflow to 0xFF (255)

Range:		0(H).....FF(H)
		  0......255 */
#include "iopt_memmap.h"

static inline  uint8 u8_add_u8_u8(uint8 x_value, uint8 y_value)
{
	/* ## Operation body start [d3267645-e2d0-4446-a135-cf2f1b1eb462] */
	uint8 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u8_add_u8_u8                                                    

         Parameter     type       Hex Range       Physical Range          

Input:                                                                    
         x_value        uint8         0..FFH            0..255               
         y_value        uint8         0..FFH            0..255               

Output:                                                                   
         res            uint8         0..FFH            0..255               

Functionality:                                                            
        res = x_value + y_value                                           
        overflow : limit to FFH                                           
	 */

	/*~E*/
	if ( ((uint16)x_value +(uint16) y_value) >= U8_MAX)
	{
		res_ret =  U8_MAX;
	}
	else
	{
		res_ret =  (uint8)((uint16)x_value +(uint16) y_value);
	}
	return res_ret ;
	/* ## Operation body end [d3267645-e2d0-4446-a135-cf2f1b1eb462] */
}

/** This operation shall perform addition of two uint16 variables with overflow limitation and return result of type uint16

@param x_value First parameter

Range:		00(H).....FFFF(H)
		   0......65535
@param y_value Second parameter

Range:		00(H).....FFFF(H)
		   0......65535
@return (x_value + y_value).
Limit overflow to 0xFFFF (65535)

Range:		0(H).....FFFF(H)
		  0......65535 */
#include "iopt_memmap.h"

static inline  uint16 u16_add_u16_u16(uint16 x_value, uint16 y_value)
{
	/* ## Operation body start [807e0715-2cd3-4e36-a309-df16052cc7ff] */
	uint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u16_add_u16_u16                                                    

         Parameter         type       Hex Range       Physical Range      

Input:                                                                    
         x_value            uint16         0..FFFFH            0..65535      
         y_value            uint16         0..FFFFH            0..65535      

Output:                                                                   
         res                uint16         0..FFFFH            0..65535      

Functionality:                                                            
        res = x_value + y_value                                           
        overflow : limit to FFFFH                                         
	 */

	/*~E*/
	if ( ((uint32)x_value + (uint32)y_value) >= U16_MAX)
	{
		res_ret =  U16_MAX;
	}
	else
	{
		res_ret =  (uint16)((uint32)x_value + (uint32)y_value);
	}
	return res_ret ;
	/* ## Operation body end [807e0715-2cd3-4e36-a309-df16052cc7ff] */
}

/** This operation shall perform addition of uint16 and sint16 variables with overflow and underflow limitation and return result of type uint16

@param x_value First parameter

Range:		00(H).....FFFF(H)
		   0......65535
@param y_value Second parameter

Range:		8000(H).....7FFF(H)
		 -32768......32767
@return (x_value + y_value).
Limit overflow to 0xFFFF (65535)
Limit underflow to 0x00 (0)

Range:		0(H).....FFFF(H)
		  0......65535 */
#include "iopt_memmap.h"

static inline  uint16 u16_add_u16_s16(uint16 x_value, sint16 y_value)
{
	/* ## Operation body start [916fe10c-c265-42a5-b8b6-91ee2478458a] */
	uint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u16_add_u16_s16                                                    

         Parameter         type      Hex Range       Physical Range       

Input:                                                                    
         x_value            uint16         0..FFFFH          0..65535        
         y_value            sint16      8000..7FFFH     -32768..32767        

Output:                                                                   
         res                uint16         0..FFFFH           0..65535       

Functionality:                                                            
        res = x_value + y_value                                           
        overflow : limit to FFFFH                                         
        underflow: limit to 0000H                                         
	 */

	/*~E*/
	/* FUNCTION_ID:9 */
	if (((sint32)x_value + (sint32)y_value) >= (sint32)U16_MAX)
	{
		res_ret =  U16_MAX;
	}
	else
	{
		if (((sint32)x_value + (sint32)y_value) <= (sint32)U16_MIN)
		{
			res_ret =  U16_MIN;
		}
		else
		{
			res_ret =  (uint16)((sint32)x_value + (sint32)y_value);
		}
	}
	return res_ret ;
	/* ## Operation body end [916fe10c-c265-42a5-b8b6-91ee2478458a] */
}

/** This operation shall perform addition of two uint32 variables with overflow limitation and return result of type uint32

@param x_value First parameter

Range:		00(H).....FFFFFFFF(H)
		   0......4294967295
@param y_value Second parameter

Range:		00(H).....FFFFFFFF(H)
		   0......4294967295
@return (x_value + y_value).
Limit overflow to 0xFFFFFFFF (4294967295)

Range:		0(H).....FFFFFFFF(H)
		  0......4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_add_u32_u32(uint32 x_value, uint32 y_value)
{
	/* ## Operation body start [69f3bc16-e446-4564-a7fb-ea23eb72bf91] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u32_add_u32_u32                                                 

         Parameter    type         Hex Range       Physical Range         

Input:                                                                    
         x_value      uint32          0..FFFFFFFF     0..4294967295          
         y_value      uint32          0..FFFFFFFF     0..4294967295          

Output:                                                                   
         res          uint32          0..FFFFFFFF     0..4294967295          

Functionality:                                                            
        res = x_value + y_value                                           
        overflow : limit to FFFFFFFFH                                     

	 */

	/*~E*/
	/* FUNCTION_ID:10 */
	x_value += y_value;
	if ( x_value < y_value)
	{
		res_ret =  U32_MAX;
	}
	else
	{
		res_ret =  x_value;
	}
	return res_ret ;
	/* ## Operation body end [69f3bc16-e446-4564-a7fb-ea23eb72bf91] */
}

/** This operation shall perform addition of three uint16 variables with overflow limitation and return result of type uint16

@param x_value First parameter

Range:		00(H).....FFFF(H)
		   0......65535
@param y_value Second parameter

Range:		00(H).....FFFF(H)
		   0......65535
@param z_value Third parameter

Range:		00(H).....FFFF(H)
		   0......65535
@return (x_value + y_value + z_value).
Limit overflow to 0xFFFF (65535)

Range:		0(H).....FFFF(H)
		  0......65535 */
#include "iopt_memmap.h"

static inline  uint16 u16_add_u16_u16_u16(uint16 x_value, uint16 y_value, uint16 z_value)
{
	/* ## Operation body start [6919fcf9-20dc-4217-af38-78c00f4964d5] */
	uint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u16_add_u16_u16_u16                                                 

         Parameter         type         Hex Range         Physical Range  

Input:                                                                    
         x_value            uint16         0..FFFF             0..65535      
         y_value            uint16         0..FFFF             0..65535      
         z_value            uint16         0..FFFF             0..65535      

Output:                                                                   
         res                uint16         0..FFFF             0..65535      

Functionality:                                                            
        res = x_value + y_value + z_value                                 
        overflow : limit to FFFFH                                         
	 */

	/*~E*/
	/* FUNCTION_ID:11 */
	if (((uint32)x_value + (uint32)y_value + (uint32)z_value) >= U16_MAX)
	{
		res_ret =  U16_MAX;
	}
	else
	{
		res_ret =  (uint16)((uint32)x_value + (uint32)y_value + (uint32)z_value);
	}
	return res_ret ;
	/* ## Operation body end [6919fcf9-20dc-4217-af38-78c00f4964d5] */
}

/** This operation shall perform addition of four uint16 variables with overflow limitation and return result of type uint16

@param w_value First parameter

Range:		00(H).....FFFF(H)
		   0......65535
@param x_value Second parameter

Range:		00(H).....FFFF(H)
		   0......65535
@param y_value Third parameter

Range:		00(H).....FFFF(H)
		   0......65535
@param z_value Fourth parameter

Range:		00(H).....FFFF(H)
		   0......65535
@return (w_value + x_value + y_value + z_value).
Limit overflow to 0xFFFF (65535)

Range:		0(H).....FFFF(H)
		  0......65535 */
#include "iopt_memmap.h"

static inline  uint16 u16_add_u16_u16_u16_u16(uint16 w_value, uint16 x_value, uint16 y_value, uint16 z_value)
{
	/* ## Operation body start [6f0bdba4-2021-42bc-ae19-289511e91b6d] */
	uint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u16_add_u16_u16_u16_u16                                              

         Parameter         type        Hex Range         Physical Range   

Input:                                                                    
         w_value            uint16         0..FFFF             0..65535      
         x_value            uint16         0..FFFF             0..65535      
         y_value            uint16         0..FFFF             0..65535      
         z_value            uint16         0..FFFF             0..65535      

Output:                                                                   
         res                uint16         0..FFFF             0..65535      

Functionality:                                                            
        res = w_value + x_value + y_value + z_value                       
        overflow : limit to FFFFH                                         
	 */

	/*~E*/
	/* FUNCTION_ID:12 */
	if (((uint32)w_value + (uint32)x_value + (uint32)y_value + (uint32)z_value) >= U16_MAX)
	{
		res_ret =  U16_MAX;
	}
	else
	{
		res_ret =  (uint16)((uint32)w_value + (uint32)x_value + (uint32)y_value + (uint32)z_value);
	}
	return res_ret ;
	/* ## Operation body end [6f0bdba4-2021-42bc-ae19-289511e91b6d] */
}

/** This operation shall perform addition of three sint16 variables with underflow and overflow limitation and return result of type sint16

@param x_value First parameter

Range:		8000(H).....7FFF(H)
		 -32768......32767
@param y_value Second parameter

Range:		8000(H).....7FFF(H)
		 -32768......32767
@param z_value Third parameter

Range:		8000(H).....7FFF(H)
		 -32768......32767
@return (x_value + y_value + z_value).
Limit overflow to 0x7FFF (32767)
Limit underflow to 0x8000 (-32768)

Range:		8000(H).....7FFF(H)
		 -32768......32767 */
#include "iopt_memmap.h"

static inline  sint16 s16_add_s16_s16_s16(sint16 x_value, sint16 y_value, sint16 z_value)
{
	/* ## Operation body start [8f5a1b32-c956-41e9-b881-6f5d34b9057f] */
	sint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s16_add_s16_s16_s16                                                 

         Parameter      type      Hex Range       Physical Range          

Input:                                                                    
         x_value        sint16       8000..7FFF      -32768..32767           
         y_value        sint16       8000..7FFF      -32768..32767           
         z_value        sint16       8000..7FFF      -32768..32767           
Output:                                                                   
         res            sint16       8000..7FFF      -32768..32767           

Functionality:                                                            
        res = x_value + y_value+z_value                                   
        overflow : limit to 7FFFH                                         
        underflow: limit to 8000H                                         
	 */

	/*~E*/
	/*FUNCTION_ID:13*/
	if (((sint32)x_value + (sint32)y_value + (sint32)z_value) >= S16_MAX)
	{
		res_ret =  S16_MAX;
	}
	else
	{
		if (((sint32)x_value + (sint32)y_value + (sint32)z_value) <= S16_MIN)
		{
			res_ret =  S16_MIN;
		}
		else
		{
			res_ret =  (sint16)((sint32)x_value + (sint32)y_value + (sint32)z_value);
		}
	}
	return res_ret ;
	/* ## Operation body end [8f5a1b32-c956-41e9-b881-6f5d34b9057f] */
}

/** This operation shall perform addition of uint32 and sint32 variables with overflow and underflow limitation and return result of type uint32

@param x_value First parameter

Range:		00(H).....FFFFFFFF(H)
		   0......4294967295
@param y_value Second parameter

Range:		80000000(H).....7FFFFFFF(H)
		-2147483648......2147483648
@return (x_value + y_value).
Limit overflow to 0xFFFFFFFF (4294967295)
Limit underflow to 0x00 (0)

Range:		0(H).....FFFFFFFF(H)
		  0......4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_add_u32_s32(uint32 x_value, sint32 y_value)
{
	/* ## Operation body start [3071de4a-4538-4160-a9dd-44c2b419d772] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u32_add_u32_s32                                                        

         Parameter   type          Hex Range            Physical Range        

Input:                                                                        
         x_value      uint32           0..FFFFFFFFH             0..4294967295    
         y_value      sint32    80000000..7FFFFFFFH   -2147483648..2147483647    

Output:                                                                       
         res          uint32           0..FFFFFFFFH             0..4294967295    

Functionality:                                                                
        res = x_value + y_value                                               
        overflow : limit to FFFFFFFFH                                         
        underflow: limit to 00000000H                                         
	 */

	/*~E*/
	uint32 tmp_res ;
	/* Check if signed input is positive */
	if ( y_value >= 0 )
	{
		/* add the two values */
		tmp_res = x_value + (uint32)y_value;
		/* Check for overflow */
		if ( tmp_res < x_value )
		{
			res_ret =  U32_MAX;
		}
		else
		{
			res_ret =  tmp_res;
		}
	}
	else
	{
		/* Check for underflow */
		if ( x_value < (uint32)(-y_value) )
		{
			res_ret =  U32_MIN;
		}
		else
		{
			res_ret =  (uint32)(x_value + (uint32)y_value);
		}
	}

	return res_ret ;
	/* ## Operation body end [3071de4a-4538-4160-a9dd-44c2b419d772] */
}

/** This operation shall perform addition of two sint32 variables with underflow limitation and return result of type uint32

@param x_value First parameter

Range:		80000000(H).....FFFFFFFF(H)
		 -2147483648.....2147483647
@param y_value Second parameter

Range:		80000000(H).....FFFFFFFF(H)
		 -2147483648.....2147483647
@return (x_value + y_value).
Limit underflow to 0x00 (0)

Range:		0(H).....FFFFFFFF(H)
		  0......4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_add_s32_s32(sint32 x_value, sint32 y_value)
{
	/* ## Operation body start [1d8140b6-8976-4b78-b539-3e96b952f51a] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u32_add_s32_s32                                                    

         Parameter   type          Hex Range          Physical Range      

Input:                                                                    
         x_value      sint32    80000000..7FFFFFFFH  -2147483648..2147483647 
         y_value      sint32    80000000..7FFFFFFFH  -2147483648..2147483647 

Output:                                                                   
         res          uint32        0..FFFFFFFFH          0..4294967295      

Functionality:                                                            
        res = x_value + y_value                                           
        overflow : limit to FFFFFFFFH                                     
        underflow: limit to 00000000H                                     
	 */

	/*~E*/
	/* Check if both input values are positive */
	if ( (x_value >= 0) && (y_value >= 0) )
	{
		res_ret =  (uint32)(x_value + y_value);
	}
	else
	{
		/* Check for underflow */
		if ( ((x_value < 0) && (y_value < 0)) || ((x_value + y_value) < (sint32)(U32_MIN)) )
		{
			res_ret =  U32_MIN;

		}
		else
		{
			res_ret =   (uint32)(x_value + y_value);
		}
	}
	/* Check if both input values are positive */

	return res_ret ;
	/* ## Operation body end [1d8140b6-8976-4b78-b539-3e96b952f51a] */
}

/** This operation shall perform addition of uint32 and sint32 variables with overflow limitation and return result of type sint32

@param x_value First parameter

Range:		00(H).....FFFFFFFF(H)
		   0......4294967295
@param y_value Second parameter

Range:		80000000(H).....FFFFFFFF(H)
		 -2147483648.....2147483647
@return (x_value + y_value).
Limit overflow to 0x7FFFFFFF (2147483647)

Range:		80000000(H).....FFFFFFFF(H)
		 -2147483648......2147483647 */
#include "iopt_memmap.h"

static inline  sint32 s32_add_u32_s32(uint32 x_value, sint32 y_value)
{
	/* ## Operation body start [a69f4909-f206-40d7-87b2-8c1d890bee34] */
	sint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: s32_add_u32_s32                                                      

         Parameter   type         Hex Range            Physical Range       

Input:                                                                      
         x_value      uint32       0..FFFFFFFFH            0..4294967295       
         y_value      sint32    80000000..7FFFFFFFH   -2147483648..2147483647  

Output:                                                                     
         res          sint32    80000000..7FFFFFFFH   -2147483648..2147483647  

Functionality:                                                              
        res = x_value + y_value                                             
        overflow : limit to 7FFFFFFFH                                       
        underflow: limit to 80000000H                                       
	 */

	/*~E*/
	uint32 tmp_res ;
	/* Check if the signed input is positive */
	if ( y_value >= 0 )
	{
		tmp_res = x_value + (uint32)y_value;
		/* Check for overflow */
		if ( (tmp_res < (uint32)y_value) || (tmp_res > (uint32)S32_MAX) )
		{
			res_ret =  S32_MAX;
		}
		else
		{
			res_ret =  (sint32)tmp_res;
		}
	}
	else
	{
		/* check if unsigned input is less than mod of signed value */
		if ( x_value < (uint32)(-y_value) )
		{
			res_ret =  (sint32)((sint32)x_value + y_value);
		}
		else
		{
			tmp_res = (uint32)(x_value + (uint32)y_value);
			/* Check for overflow */
			if ( tmp_res > (uint32)S32_MAX )
			{
				res_ret =  S32_MAX;
			}
			else
			{
				res_ret =  (sint32)tmp_res;
			}
		}
	}

	return res_ret ;
	/* ## Operation body end [a69f4909-f206-40d7-87b2-8c1d890bee34] */
}

/** This operation shall perform addition of three uint32 variables with overflow limitation and return result of type uint32

@param x_value First parameter

Range:		00(H).....FFFFFFFF(H)
		   0......4294967295
@param y_value Second parameter

Range:		00(H).....FFFFFFFF(H)
		   0......4294967295
@param z_value Third parameter

Range:		00(H).....FFFFFFFF(H)
		   0......4294967295
@return (x_value + y_value + z_value).
Limit overflow to 0xFFFFFFFF (4294967295)

Range:		0(H).....FFFFFFFF(H)
		  0......4294967295 */
#include "iopt_memmap.h"

static inline  uint32 u32_add_u32_u32_u32(uint32 x_value, uint32 y_value, uint32 z_value)
{
	/* ## Operation body start [8bf4b5f2-1a3a-4908-a74a-254d85506148] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: u32_add_u32_u32_u32                                                 

         Parameter    type          Hex Range      Physical Range         

Input:                                                                    
         x_value      uint32          0..FFFFFFFF     0..4294967295          
         y_value      uint32          0..FFFFFFFF     0..4294967295          
         z_value      uint32          0..FFFFFFFF     0..4294967295          

Output:                                                                   
         res          uint32          0..FFFFFFFF     0..4294967295          

Functionality:                                                            
        res = x_value + y_value + z_value                                 
        overflow : limit to FFFFFFFFH                                     

	 */

	/*~E*/
	/* FUNCTION_ID:17 */
	x_value += ( y_value + z_value );
	if ( (( y_value + z_value ) < y_value ) || (x_value < ( y_value + z_value )) )
	{
		res_ret =  U32_MAX;
	}
	else
	{
		res_ret =  x_value;
	}
	return res_ret ;
	/* ## Operation body end [8bf4b5f2-1a3a-4908-a74a-254d85506148] */
}

/** This is a root operation for the series s8_mul_s8_u8_facn, where n < 1. This operation multiplies value by a factor which is less than one

@param value : First value
@param factor : Factor to be multiplied
@return returns sint8 */
#include "iopt_memmap.h"

static inline  sint8 root_s8_mul_s8_u8_fac_less1(sint8 value, uint16 factor)
{
	/* ## Operation body start [704a6363-18d9-4b57-baaa-9730499a2310] */
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: root_s8_mul_s8_u8_fac_less1                                    

         Parameter          type      Hex Range       Physical Range      

Input:                                                                    
           value             sint8       80..7F           -128..127          
           factor            uint16       0..FFFF          0..0.999985       

Output:                                                                   
           res               sint8       80..7F           -128..127          

Functionality:                                                            
          value*factor/65536                                              
Remark:          Root function for the functions s8_mul_s8_u8_facn        
          where n < 1                                                     
	 */

	/*~E*/
	return (sint8)(((sint32)value * (sint32)factor) / (sint32)65536);


	/* ## Operation body end [704a6363-18d9-4b57-baaa-9730499a2310] */
}

/** This is a root operation for the series s8_mul_s8_u8_facn, where n > 1. This operation multiplies value by a factor which is greater than one

@param value : First value
@param factor : Factor to be multiplied
@return returns sint8 */
#include "iopt_memmap.h"

static inline  sint8 root_s8_mul_s8_u8_fac_greater1(sint8 value, uint16 factor)
{
	/* ## Operation body start [288b8e2b-cf45-47a8-9ad2-d4a47f4ed634] */
	sint8 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: root_s8_mul_s8_u8_fac_greater1                                  

         Parameter          type      Hex Range       Physical Range      

Input:                                                                    
           value             sint8       80..7F           -128..127          
           factor            uint16      0..FFFF           0..0.999985       

Output:                                                                   
           res               sint8       80..7F           -128..127          

Functionality:                                                            
          value*factor/256                                                
Remark:Root function for the functions s8_mul_s8_u8_facn                  
          where n > 1                                                     
	 */

	/*~E*/
	/*FUNCTION_ID:2*/
	if ( (((sint32)value * (sint32)factor) / 256) >= S8_MAX)
	{
		res_ret =  S8_MAX;
	}
	else
	{
		if ((((sint32)value * (sint32)factor) / 256) <=S8_MIN)
		{
			res_ret =  S8_MIN;
		}
		else
		{
			res_ret =  (sint8)(((sint32)value * (sint32)factor) / 256);
		}
	}
	return res_ret ;
	/* ## Operation body end [288b8e2b-cf45-47a8-9ad2-d4a47f4ed634] */
}

/** This is a root operation for the series s16_mul_s16_s16_facn, where n < 1. This operation multiplies value by a factor which is less than one

@param value : First value
@param factor : Factor to be multiplied
@param count : Count by which (value * factor) has to be divided
@return returns sint16 */
#include "iopt_memmap.h"

static inline  sint16 root_s16_mul_s16_s16_fac_less1(sint16 value, sint16 factor, sint32 count)
{
	/* ## Operation body start [84ad3036-cad7-4628-8d60-a0b814f96475] */
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION   root_s16_mul_s16_s16_fac_less1                                 

         Parameter      type      Hex Range       Physical Range          

Input:                                                                    
         value          sint16        8000..7FFF     -32768..32767           
         factor         sint16        8000..7FFF     -0.5 .. 0.4999923       
         count          sint16                          8...8192             

Output:                                                                   
         res            sint16        8000..7FFF     -32768..32767           

Functionality:                                                            
         res = (value*factor)/count                                       
Remark:          Root function for the functions s16_mul_s16_s16_facn        
          where n < 2                                                     

	 */

	/*~E*/
	return (sint16)(((sint32)value * (sint32)factor)/count);


	/* ## Operation body end [84ad3036-cad7-4628-8d60-a0b814f96475] */
}

/** This is a root operation for the series s16_mul_s16_s16_facn, where n > 1. This operation multiplies value by a factor which is greater than one

@param value : First value
@param factor : Factor to be multiplied
@param count : Count by which (value * factor) has to be divided
@return returns sint16 */
#include "iopt_memmap.h"

static inline  sint16 root_s16_mul_s16_s16_fac_greater1(sint16 value, sint16 factor, sint16 count)
{
	/* ## Operation body start [d1d47201-9e49-4a60-9afb-3907688a7d39] */
	sint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION   root_s16_mul_s16_s16_fac_greater1                                 

         Parameter    type      Hex Range       Physical Range            

Input:                                                                    
         value        sint16        8000..7FFF     -32768..32767             
         factor       sint16        8000..7FFF     -0.5 .. 0.4999923         
         count        sint16                          8...8192               

Output:                                                                   
         res          sint16        8000..7FFF     -32768..32767             

Functionality:                                                            
         res = (value*factor)/count                                       
Remark:          Root function for the functions s16_mul_s16_s16_facn        
          where n > 2                                                     

	 */

	/*~E*/
	if ( (((sint32)value * (sint32)factor)/(sint32)count) >= S16_MAX)
	{
		res_ret =  S16_MAX;
	}
	else
	{
		if ((((sint32)value * (sint32)factor)/(sint32)count) <= S16_MIN)
		{
			res_ret =  S16_MIN;
		}
		else
		{
			res_ret =  (sint16)(((sint32)value * (sint32)factor)/(sint32)count);
		}
	}
	return res_ret ;
	/* ## Operation body end [d1d47201-9e49-4a60-9afb-3907688a7d39] */
}

/** This is a root operation for the series s16_mul_s16_u8_facn, where n < 1. This operation multiplies value by a factor which is less than one

@param value : First value
@param factor : Factor to be multiplied
@return returns sint16 */
#include "iopt_memmap.h"

static inline  sint16 root_s16_mul_s16_u8_fac_less1(sint16 value, uint16 factor)
{
	/* ## Operation body start [06f2ef60-8e00-4f7e-8a3b-605a04cbd0b9] */
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: root_s16_mul_s16_u8_fac_less1                                          

         Parameter   type      Hex Range       Physical Range             

Input:                                                                    
           value     sint16       8000..7FFF       -32768..32767             
           factor    uint16          0..FFFF       0..0.999985               

Output:                                                                   
           res       sint16       8000..7FFF       -32768..32767             

Functionality:                                                            
            res=(value*factor)/65536                                      
          Root function for the functions s16_mul_s16_u8_facn               
          where n < 1                                                     
	 */

	/*~E*/
	return (sint16)(((sint32)value * (sint32)factor) / (sint32)65536);


	/* ## Operation body end [06f2ef60-8e00-4f7e-8a3b-605a04cbd0b9] */
}

/** This is a root operation for the series s16_mul_s16_u8_facn, where n > 1. This operation multiplies value by a factor which is greater than one

@param value : First value
@param factor : Factor to be multiplied
@return returns sint16 */
#include "iopt_memmap.h"

static inline  sint16 root_s16_mul_s16_u8_fac_greater1(sint16 value, uint16 factor)
{
	/* ## Operation body start [e6a8fd57-a417-45e0-8ced-452deb62796f] */
	sint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: root_s16_mul_s16_u8_fac_greater1                                       

         Parameter         type      Hex Range         Physical Range     

Input:                                                                    
           value           sint16       8000..7FFF       -32768..32767       
           factor          uint16          0..FFFF        0..0.999985        

Output:                                                                   
           res             sint16       8000..7FFF       -32768..32767       

Functionality:                                                            
            x*y/256                                                       
          Root function for the functions s16_mul_s16_u8_facn               
          where n > 1                                                     
	 */

	/*~E*/
	if ((((sint32)value * (sint32)factor)/256) >= S16_MAX)
	{
		res_ret =  S16_MAX;
	}
	else
	{
		if ((((sint32)value * (sint32)factor)/256) <=S16_MIN)
		{
			res_ret =  S16_MIN;
		}
		else
		{
			res_ret =  (sint16)(((sint32)value * (sint32)factor)/256);
		}
	}
	return res_ret ;
	/* ## Operation body end [e6a8fd57-a417-45e0-8ced-452deb62796f] */
}

/** This is a root operation for the series s16_mul_s16_u16_facn, where n < 1. This operation multiplies value by a factor which is less than one

@param value : First value
@param factor : Factor to be multiplied
@param count : Count by which (value * factor) has to be divided
@return returns sint16 */
#include "iopt_memmap.h"

static inline  sint16 root_s16_mul_s16_u16_fac_less1(sint16 value, uint16 factor, sint32 count)
{
	/* ## Operation body start [115a6f0e-42aa-4c08-965a-03a8786b79fb] */
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: root_s16_mul_s16_u16_fac_less1                                     

         Parameter   type      Hex Range       Physical Range             

Input:                                                                    
         value       sint16       8000..7FFF       -32768..32767             
          factor     uint16       0..FFFF           0..0.999985              
         count       sint32                         131072....524288         

Output:                                                                   
         res         sint16       8000..7FFF       -32768..32767             

Functionality:                                                            
      res = (value*factor)/count                                          
Remark:          Root function for the functions s16_mul_s16_u16_facn        
          where n < 1                                                     
	 */

	/*~E*/
	return (sint16)(((sint32)value *(sint32) factor)/count);

	/* ## Operation body end [115a6f0e-42aa-4c08-965a-03a8786b79fb] */
}

/** This is a root operation for the series s16_mul_s16_u16_facn, where n > 1. This operation multiplies value by a factor which is greater than one

@param value : First value
@param factor : Factor to be multiplied
@param count : Count by which (value * factor) has to be divided
@return returns sint16 */
#include "iopt_memmap.h"

static inline  sint16 root_s16_mul_s16_u16_fac_greater1(sint16 value, uint16 factor, uint16 count)
{
	/* ## Operation body start [9df7273f-7a31-4659-b17f-fc32cd41ee9a] */
	sint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
 FUNCTION: root_s16_mul_s16_u16_fac_greater1                                 

         Parameter   type      Hex Range       Physical Range    

Input:                                                                    
         value       sint16       8000..7FFF       -32768..32767    
          factor     uint16       0..FFFF           0..0.999985     
         count       uint16                           16..16384     

Output:                                                                   
         res         sint16       8000..7FFF       -32768..32767    

Functionality:                                                            
      res = (value*factor)/count                                          
Remark:          Root function for the functions s16_mul_s16_u16_facn        
          where n > 2                                                   */

	/*~E*/
	if ((((sint32)value *(sint32) factor)/(sint32)count) >= S16_MAX)
	{
		res_ret =  S16_MAX;
	}
	else
	{
		if ((((sint32)value *(sint32) factor)/(sint32)count) <= S16_MIN)
		{
			res_ret =  S16_MIN;
		}
		else
		{
			res_ret =  (sint16)(((sint32)value *(sint32) factor)/(sint32)count);
		}
	}
	return res_ret ;
	/* ## Operation body end [9df7273f-7a31-4659-b17f-fc32cd41ee9a] */
}

/** This is a root operation for the series u8_mul_u8_u8_facn, where n < 1. This operation multiplies value by a factor which is less than one

@param value : First value
@param factor : Factor to be multiplied
@param count : Count by which (value * factor) has to be divided
@return returns uint8 */
#include "iopt_memmap.h"

static inline  uint8 root_u8_mul_u8_u8_fac_less1(uint8 value, uint8 factor, uint16 count)
{
	/* ## Operation body start [f0dd2dfe-7f51-4fd6-bd80-df47e06f1a18] */
	/*~A*/
	/*~+:Description*/
	/*
UNCTION: root_u8_mul_u8_u8_fac_less1                                      

         Parameter   type      Hex Range       Physical Range             

Input:                                                                    
         value       uint8       00..FF            0..255                    
         factor      uint8       0..FFFF           0..0.996                  
         count       uint8                           9..11                   

Output:                                                                   
         res         uint8        0..FF             0..255                   

Functionality:                                                            
      res = (value*factor)/count                                          
Remark:          Root function for the functions u8_mul_u8_u8_facn        
          where n < 1                                                   */

	/*~E*/
	return (uint8)(((uint16)value * (uint16)factor ) >> count);


	/* ## Operation body end [f0dd2dfe-7f51-4fd6-bd80-df47e06f1a18] */
}

/** This is a root operation for the series u8_mul_u8_u8_facn, where n > 1. This operation multiplies value by a factor which is greater than one

@param value : First value
@param factor : Factor to be multiplied
@param count : Count by which (value * factor) has to be divided
@return returns uint8 */
#include "iopt_memmap.h"

static inline  uint8 root_u8_mul_u8_u8_fac_greater1(uint8 value, uint8 factor, uint8 count)
{
	/* ## Operation body start [b1f498e1-5f50-4fcd-a68d-87fd258909b8] */
	uint8 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
UNCTION: root_u8_mul_u8_u8_fac_greater1                                   

         Parameter   type      Hex Range       Physical Range             

Input:                                                                    
         value       uint8       00..FF            0..255                    
         factor      uint8       0..FFFF           0..0.996                  
         count       uint8                           1..6                    

Output:                                                                   
         res         uint8       0..FF             0..255                    

Functionality:                                                            
      res = (value*factor)/count                                          
Remark:          Root function for the functions u8_mul_u8_u8_facn        
          where n > 2                                                     
	 */

	/*~E*/
	if ((((uint16)value * (uint16)factor ) /(uint16)count) > U8_MAX)
	{
		res_ret =  U8_MAX;
	}
	else
	{
		res_ret =  (uint8)(((uint16)value * (uint16)factor ) /(uint16)count);
	}
	return res_ret ;
	/* ## Operation body end [b1f498e1-5f50-4fcd-a68d-87fd258909b8] */
}

/** This is a root operation for the series u16_mul_u16_u8_facn, where n < 1. This operation multiplies value by a factor which is less than one

@param value : First value
@param factor : Factor to be multiplied
@return returns uint16 */
#include "iopt_memmap.h"

static inline  uint16 root_u16_mul_u16_u8_fac_less1(uint16 value, uint16 factor)
{
	/* ## Operation body start [f7da39fd-9d3a-4189-ade1-37ef953ea18b] */
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: root_u16_mul_u16_u8_fac_less1                                     


      Parameter  type     Hex Range    Physical Range                     

Input:                                                                    
       value     uint16       0..FFFF        0..65535                        
       factor    uint16       0..FFFF        0..65535                        


Output:                                                                   
       res       uint16       0..FFFF        0..65535                        

Functionality:                                                            
            res=(value*factor)/65536                                      
          Root function for the functions s16_mul_s16_u8_facn               
          where n < 1                                                     
	 */

	/*~E*/
	return (uint16)(((uint32)value * (uint32)factor) >> 16);


	/* ## Operation body end [f7da39fd-9d3a-4189-ade1-37ef953ea18b] */
}

/** This is a root operation for the series u16_mul_u16_u8_facn, where n > 1. This operation multiplies value by a factor which is greater than one

@param value : First value
@param factor : Factor to be multiplied
@return returns uint16 */
#include "iopt_memmap.h"

static inline  uint16 root_u16_mul_u16_u8_fac_greater_1(uint16 value, uint16 factor)
{
	/* ## Operation body start [011a01e7-8628-41c2-92d2-0d448cd45d30] */
	uint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: root_u16_mul_u16_u8_fac_greater_1                                  


      Parameter      type      Hex Range     Physical Range               

Input:                                                                    
       value         uint16       0..FFFF        0..65535                    
       factor        uint16       0..FFFF        0..65535                    


Output:                                                                   
       res           uint16       0..FFFF        0..65535                    

Functionality:                                                            
        res = ( value*factor)>>8                                          
	 */

	/*~E*/
	if ((((uint32)value * (uint32)factor) >> 8) >= U16_MAX)
	{
		res_ret =  U16_MAX;
	}
	else
	{
		res_ret =  (uint16)(((uint32)value * (uint32)factor) >> 8);
	}
	return res_ret ;
	/* ## Operation body end [011a01e7-8628-41c2-92d2-0d448cd45d30] */
}

/** This is a root operation for the series u16_mul_u16_u16_facn, where n < 1. This operation multiplies value by a factor which is less than one

@param value : First value
@param factor : Factor to be multiplied
@param count : Count by which (value * factor) has to be divided
@return returns sint16 */
#include "iopt_memmap.h"

static inline  uint16 root_u16_mul_u16_u16_fac_less1(uint16 value, uint16 factor, uint32 count)
{
	/* ## Operation body start [db6651b9-dbc1-448c-9af4-725471905815] */
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: root_u16_mul_u16_u16_fac_less1                                     


      Parameter  type     Hex Range    Physical Range                     

Input:                                                                    
       value     uint16       0..FFFF        0..65535                        
       factor    uint16       0..FFFF        0..0.996                        
       count     uint16                       1..3                           

Output:                                                                   
       res       uint16       0..FFFF        0..65535                        

Functionality:                                                            
        res = (value  * factor)/count                                     
         Root function for the functions u16_mul_u16_u16_facn                
                where n < 1                                              */

	/*~E*/
	return (uint16)(((uint32)value * (uint32)factor)  >> count);


	/* ## Operation body end [db6651b9-dbc1-448c-9af4-725471905815] */
}

/** This is a root operation for the series u16_mul_u16_u16_facn, where n > 1. This operation multiplies value by a factor which is greater than one

@param value : First value
@param factor : Factor to be multiplied
@param count : Count by which (value * factor) has to be divided
@return returns uint16 */
#include "iopt_memmap.h"

static inline  uint16 root_u16_mul_u16_u16_fac_greater1(uint16 value, uint16 factor, uint16 count)
{
	/* ## Operation body start [d41e2f09-7e82-4094-9fd0-d60fb500a4a3] */
	uint16 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: root_u16_mul_u16_u16_fac_greater1                                  


      Parameter  type     Hex Range    Physical Range                     

Input:                                                                    
       value     uint16       0..FFFF        0..65535                        
       factor    uint16       0..FFFF        0..0.996                        
       count     uint16                       16..16384                      

Output:                                                                   
       res       uint16       0..FFFF        0..65535                        

Functionality:                                                            
        res = (value  * factor)/count                                     
         Root function for the functions u16_mul_u16_u16_facn                
                where n > 2                                             */

	/*~E*/
	if ((((uint32)value * (uint32)factor) /(uint32)count) > U16_MAX)
	{
		res_ret =  U16_MAX;
	}
	else
	{
		res_ret =  (uint16)(((uint32)value * (uint32)factor) /(uint32)count);
	}
	return res_ret ;
	/* ## Operation body end [d41e2f09-7e82-4094-9fd0-d60fb500a4a3] */
}

/** This is a root operation for the series u32_mul_u32_u32_facn, where n < 1. This operation multiplies value by a factor which is less than one

@param value : First value
@param factor : Factor to be multiplied
@param count : Count by which (value * factor) has to be divided
@return returns uint32 */
#include "iopt_memmap.h"

static inline  uint32 root_u32_mul_u32_u32_fac_less1(uint32 value, uint32 factor, uint32 count)
{
	/* ## Operation body start [3792ce5f-c62d-4b18-931a-443536a80bd9] */
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION:  root_u32_mul_u32_u32_fac_less1                              


      Parameter     type     Hex Range    Physical Range                  

Input:                                                                    
       x_value       uint32       0..FFFFFFFF        0..4294967295           
       y_value       uint32       0..FFFFFFFF        0..4294967295           
       count         uint32                          33                      

Output:                                                                   
       res           uint32       0..FFFFFFFF        0..4294967295           

Functionality:                                                            
        res = x_value*y_value >> count                                    

	 */

	/*~E*/
	return (uint32)( ( (uint64)value * factor ) >> count );
	/* ## Operation body end [3792ce5f-c62d-4b18-931a-443536a80bd9] */
}

/** This is a root operation for the series u32_mul_u32_s32_facn, where n < 1. This operation multiplies value by a factor which is less than one

@param value : First value
@param factor : Factor to be multiplied
@param count : Count by which (value * factor) has to be divided
@return returns uint32 */
#include "iopt_memmap.h"

static inline  uint32 root_u32_mul_u32_s32_fac_less1(uint32 value, sint32 factor, uint32 count)
{
	/* ## Operation body start [fb776aa7-3c41-46d6-be48-ad056e1e99d6] */
	uint32 res_ret;
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: root_u32_mul_u32_s32_fac_less1                                              


      Parameter      type      Hex Range            Physical Range             

Input:                                                                         
       value         uint32       00000000..FFFFFFFF   0..4294967295              
       factor        sint32       80000000..7FFFFFFF   -2147483648..2147483647    
       count         uint32                            32                         

Output:                                                                        
       res           uint32       00000000..FFFFFFFF    0..4294967295             

Functionality:                                                                 
        res = (value  * factor) >> count                                       
        limit underflow to 00000000H                                           
	 */

	/*~E*/
	/* Check for underflow */
	if ( factor <= 0 )
	{
		res_ret =  U32_MIN;
	}
	else
	{
		res_ret =  (uint32)( ( (uint64)value * (uint32)factor ) >> count );
	}
	return res_ret ;
	/* ## Operation body end [fb776aa7-3c41-46d6-be48-ad056e1e99d6] */
}

/** This is a root operation for the series s32_mul_s32_u16_facn, where n < 1. This operation multiplies value by a factor which is less than one

@param value : First value
@param factor : Factor to be multiplied
@param count : Count by which (value * factor) has to be divided
@return returns sint32 */
#include "iopt_memmap.h"

static inline  sint32 root_s32_mul_s32_u16_fac_less1(sint32 value, uint16 factor, uint32 count)
{
	/* ## Operation body start [6ffabc7d-bb50-496c-b9e4-347d4edaa83e] */
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: root_s32_mul_s32_u16_fac_less1                                    


      Parameter      type     Hex Range            Physical Range         

Input:                                                                    
       value         sint32      80000000..7FFFFFFF   -214783648..2147483647 
       factor        uint16      0..FFFF               0..65535              
       count         uint32                            131072                

Output:                                                                   
       res           sint32      80000000..7FFFFFFF   -214783648..2147483647 

Functionality:                                                            
        res = (value  * factor)/count                                     
	 */

	/*~E*/
	return (sint32)( ( (sint64)value * (sint32)factor )  / (sint32)count );

	/* ## Operation body end [6ffabc7d-bb50-496c-b9e4-347d4edaa83e] */
}

/** This is a root operation for the series s32_mul_s32_s16_facn, where n < 1. This operation multiplies value by a factor which is less than one

@param value : First value
@param factor : Factor to be multiplied
@param count : Count by which (value * factor) has to be divided
@return returns sint32 */
#include "iopt_memmap.h"

static inline  sint32 root_s32_mul_s32_s16_fac_less1(sint32 value, sint16 factor, uint32 count)
{
	/* ## Operation body start [4719b8d6-c7ea-4a31-8fcf-f9653f83c6c8] */
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: root_s32_mul_s32_s16_fac_less1                                


      Parameter      type      Hex Range            Physical Range        

Input:                                                                    
       value         sint32      80000000..7FFFFFFF   -214783648..2147483647 
       factor        sint16      8000..7FFF            -32768..32767         
       count         uint32                             65536                
Output:                                                                   
       res           sint32      80000000..7FFFFFFF   -214783648..2147483647 

Functionality:                                                            
        res = (value  * factor)/count                                     
	 */

	/*~E*/
	return (sint32)( ( (sint64)value * (sint32)factor ) / (sint32)count );

	/* ## Operation body end [4719b8d6-c7ea-4a31-8fcf-f9653f83c6c8] */
}

/** This is a root operation for the series s32_mul_s32_s8_facn, where n < 1. This operation multiplies value by a factor which is less than one

@param value : First value
@param factor : Factor to be multiplied
@param count : Count by which (value * factor) has to be divided
@return returns sint32 */
#include "iopt_memmap.h"

static inline  sint32 root_s32_mul_s32_s8_fac_less1(sint32 value, sint8 factor, uint32 count)
{
	/* ## Operation body start [1bff7f88-7689-40fe-a60e-ad15d0f5dec7] */
	/*~A*/
	/*~+:Description*/
	/*
FUNCTION: root_s32_mul_s32_s8_fac_less1                                              

        Parameter     type     Hex Range                Physical Range                  

Input:                                                                                  
        value         sint32      80000000..FFFFFFFF       -2147483648..2147483647         
        factor        sint8             80..FF             -128..127                       
        count         uint32                                256  (for fak05 function)      

Output:                                                                                 
       res            sint32      80000000..FFFFFFFF       -2147483648..2147483647         

Functionality:                                                                          
        res = (value * factor) / count                                                  
        Root function for the functions s32_mul_s32_s8_facn                               
                where n < 1                                                           */

	/*~E*/
	sint32 tmp_factor = factor;
	return (sint32)(((sint64)value * tmp_factor) / (sint64)count);

	/* ## Operation body end [1bff7f88-7689-40fe-a60e-ad15d0f5dec7] */
}


/** Returns an uint8 value which is the number of leading zeros of the uint32 value given as the input.

@param val : First value
@return returns sint32 */
#include "iopt_memmap.h"

static inline  uint8 u8_cntlz_u32_math(uint32 val)
{
	/* ## Operation body start [ba714633-101c-417a-8b8f-14f9b2a143ce] */
	/*~A*/
	/*~+:Description*/
	/*FUNCTION: u8_cntlz_u32_math

         Parameter     type      Hex Range             Physical Range     

Input:                                                                    
         val            uint32       00000000..FFFFFFFFH  0..4294967295      

Output:                                                                   
         result         uint8        00H..20H             0..32              

Functionality:                                                            
          Returns an uint8 value which is the number of                      
          leading zeros of the uint32 value given as the input.             
	 */

	/*~E*/
	/*~A*/
	/*~+:Description of Lint supression*/
	/* W715: val not referenced */

	/*~E*/
	uint8  k, cnt;
	uint32 i, j;

	cnt = 0;
	i = val;
	for (k = 1; k <= 32U; k++)
	{
		j = i & 0x80000000U;
		if (j == 0U)
		{
			cnt++;
			i = i << 1;
		}
		else
		{
					/* no else needed */
		}
	}
	return cnt;
}





/*~E*/
/*~A*/
/*~+:Private and Public Operations*/
/** This operation shall return the sine of an input angle of type uint16

@param phi Input angle for which sine has to be determined

Range:      00(H)......FFFF(H)
              0..1.57077 (pi/2) radians
@return sine (phi)

Range:      00(H)......FFFF(H)
             0...0.99998 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 u16_sin_u16(uint16 phi);


/** This operation shall return the sine of an input angle of type uint32

@param phi Input angle for which sine has to be determined

Range:      00(H)......FFFFFFFF(H)
             0...102943.7 (32768pi) radians
@return sine (phi)

Range:      8000(H)......7FFF(H)
              -1..0.99998 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern sint16 s16_sin_u32(uint32 phi);


/** This operation shall return the cosine of an input angle of type uint16

@param phi Input angle for which cosine has to be determined

Range:      00(H)......FFFF(H)
            0....1.57077 (pi/2) radians
@return cosine (phi)

Range:      00(H)......FFFF(H)
            0...0.99998 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 u16_cos_u16(uint16 phi);


/** This operation shall return the cosine of an input angle of type uint32

@param phi Input angle for which cosine has to be determined

Range:      00(H)......FFFFFFFF(H)
             0...102943.7 (32768pi) radians
@return cosine (phi)

Range:      8000(H)......7FFF(H)
              -1..0.99998 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern sint16 s16_cos_u32(uint32 phi);


/** This operation shall return the tangent of an input angle of type uint16

@param phi Input angle for which tangent has to be determined

Range:      00(H)......FFFF(H)
           0..1.57077 (pi/2) radians
@return tangent (phi)

Range:      00(H)......FFFF(H)
           0..15.999756 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 u16_tan_u16(uint16 phi);


/** This operation shall return the tangent of an input angle of type uint32

@param phi Input angle for which tangent has to be determined

Range:      00(H)......FFFFFFFF(H)
           0...102943.7 (32768pi) radians
@return tangent (phi)

Range:      8000(H)......7FFF(H)
                           -16..15.999512
 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern sint16 s16_tan_u32(uint32 phi);


/** This operation shall return the square root value (uint16) of the uint32 parameter passed as the input

@param input input parameter for which square root has to be determined

Range:      0x00....0xFFFFFFFF
           0.....4294967295
@return Square root (input)

Range:      0x00....0xFFF
           0.....65535 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 u16_sqrt_u32(uint32 input);


/** This operation shall calculate the new floating average of type sint16 with a sint16 value as old floating average, a sint16 value as actual measured value and a sint16 value (-1...0.99997) as average value

@param gmw Old floating average

Range:      8000(H).....7FFF(H)
         -32768......32767
@param messwert Actual measured value

Range:      8000(H).....7FFF(H)
         -32768......32767
@param mitko Constant value

Range:      8000(H).....7FFF(H)
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

Range:      8000(H).....7FFF(H)
                  -32768.....32767 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern sint16 s16_mmv_s16_s16_s16_fac1(sint16 gmw, sint16 messwert, sint16 mitko);


/** This operation shall calculate the new floating average of type uint16 with an uint16 value as old floating average, an uint16 value as actual measured value and a sint16 value (-1...0.99997) as average value

@param gmw Old floating average

Range:      00(H).....FFFF(H)
           0......65535
@param messwert Actual measured value

Range:      00(H).....FFFF(H)
           0......65535
@param mitko Constant value

Range:      8000(H).....7FFF(H)
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

Range:      0000...FFFF H
             0...65535 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 u16_mmv_u16_u16_s16_fac1(uint16 gmw, uint16 messwert, sint16 mitko);


/** This operation shall calculate the new floating average of type uint16 with an uint16 value as old floating average, an uint16 value as actual measured value and an uint16 value (0...1.99997) as average value

@param gmw Old floating average

Range:      00(H).....FFFF(H)
           0......65535
@param messwert Actual measured value

Range:      00(H).....FFFF(H)
           0......65535
@param mitko Constant value

Range:      00(H).....FFFF(H)
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

Range:      00(H)...FFFF(H)
            0...65535 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 u16_mmv_u16_u16_u16_fac2(uint16 gmw, uint16 messwert, uint16 mitko);


/** This operation shall calculate the new floating average of type uint32 with an uint32 value as old floating average, an uint16 value as actual measured value and an uint16 value (0...0.999985) as average value

@param gmw Old floating average

Range:      00(H).....FFFFFFFF(H)
           0......4294967295
@param messwert Actual measured value

Range:      00(H).....FFFF(H)
           0......65535
@param mitko Constant value

Range:      00(H).....FFFF(H)
           0...0.999985
@return gmw + ((messwert - gmw.HIGH) * mitko)
if ((messwert - gmw.HIGH) == 0)
{
    result.HIGH = gmw.HIGH
    result.LOW = 8000H 
}

Range:      00(H)...FFFFFFFF(H)
            0...4294967295

 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint32 u32_mmv_u32_u16_u16_fac1(uint32 gmw, uint16 messwert, uint16 mitko);


/** This operation shall calculate the new floating average of type sint16 with a sint16 value as old floating average, a sint16 value as actual measured value and an uint16 value (0...0.999985) as average value

@param mmv Old floating average

Range:      8000(H).....7FFF(H)
         -32768......32767
@param measure Actual measured value

Range:      8000(H).....7FFF(H)
         -32768......32767
@param crlc Constant value

Range:      00(H).....FFFF(H)
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

Range:      8000(H).....7FFF(H)
                  -32768.....32767 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern sint16 s16_mmv_s16_s16_u16_fac1(sint16 mmv, sint16 measure, uint16 crlc);


/** This operation shall calculate the new floating average of type sint32 with a sint32 value as old floating average, a sint16 value as actual measured value and an uint16 value (0...0.999985) as average value

@param mmv Old floating average

Range:      80000000(H) ......7FFFFFFF(H)
         -2147483648......2147483647
@param measure Actual measured value

Range:      8000(H).....7FFF(H)
         -32768......32767
@param crlc Constant value

Range:      00(H).....FFFF(H)
             0...0.999985
@return mmv + ((measure - mmv.HIGH) * crlc)
if ((measure - mmv.HIGH) == 0)
{
    result.HIGH = mmv.HIGH
    result.LOW = 8000H
}

Range:      80000000(H) ......7FFFFFFF(H)
         -2147483648......2147483647

 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern sint32 s32_mmv_s32_s16_u16_fac1(sint32 mmv, sint16 measure, uint16 crlc);


/** This operation shall calculate the new floating average of type uint16 with an uint16 value as old floating average, an uint16 value as actual measured value and an uint16 value (0...0.999985) as average value

@param mmv Old floating average

Range:      00(H).....FFFF(H)
           0......65535
@param measure Actual measured value
If the measurement has the type char, shift it 8 bits to the left. XX(H)  --> XX00(H)

Range:      00(H).....FFFF(H)
           0......65535
@param crlc Constant value
If the average value has the type char, shift it 8 bits to the left. XX(H)  --> XX00(H)

Range:      00(H)...FFFF(H)
                   0...0.999985
@return result = mmv + ((( measure - mmv) * crlc) >> 16),   Result rounded off

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

Range:      00(H).....FFFF(H)
                      0...65535 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 u16_mmv_u16_u16_u16_fac1(uint16 mmv, uint16 measure, uint16 crlc);


/** This operation shall calculate the new floating average of type uint32 with an uint32 value as old floating average, an uint32 value as actual measured value and an uint32 value (0...0.999985) as average value

@param mmv Old floating average

Range:      00(H).....FFFFFFFF(H)
           0......4294967295
@param measure Actual measured value

Range:      00(H).....FFFFFFFF(H)
           0......4294967295
@param crlc Constant value

Range:      00(H).....FFFFFFFF(H)
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

Range:      00(H)......FFFFFFFF(H)
             0...4294967295 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint32 u32_mmv_u32_u32_u32_fac1(uint32 mmv, uint32 measure, uint32 crlc);


/** This operation shall calculate the new floating average of type uint32 with an uint32 value as old floating average, an uint32 value as actual measured value and an uint16 value (0...0.999985) as average value

@param mmv Old floating average

Range:      00(H).....FFFFFFFF(H)
           0......4294967295
@param measure Actual measured value

Range:      00(H).....FFFFFFFF(H)
           0......4294967295
@param crlc Constant value

Range:      00(H)...FFFF(H)
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

Range:      00(H)......FFFFFFFF(H)
               0...4294967295 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint32 u32_mmv_u32_u32_u16_fac1(uint32 mmv, uint32 measure, uint16 crlc);


/** This operation shall calculate the new floating average of type uint32 with an uint32 value as old floating average, an uint32 value as actual measured value and a sint32 value (-1....0.9999) as average value

@param mmv Old floating average

Range:      00(H).....FFFFFFFF(H)
           0......4294967295
@param measure Actual measured value

Range:      00(H).....FFFFFFFF(H)
           0......4294967295
@param crlc Constant value

Range:      80000000(H)...7FFFFFFF(H)
                        -1...0...0.9999
@return result = mmv + ((( measure - mmv) * crlc) >> 31),   result  rounded  off

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

Range:      00(H)......FFFFFFFF(H)
                   0.......4294967295 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint32 u32_mmv_u32_u32_s32_fac1(uint32 mmv, uint32 measure, sint32 crlc);


/** This operation shall calculate the new floating average of type uint32 with an uint32 value as old floating average, an uint32 value as actual measured value and a sint16 value (-1...0.99997) as average value

@param mmv Old floating average

Range:      00(H).....FFFFFFFF(H)
           0......4294967295
@param measure Actual measured value

Range:      00(H).....FFFFFFFF(H)
           0......4294967295
@param crlc Constant value

Range:      8000(H)...7FFF(H)
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

Range:      00(H)......FFFFFFFF(H)
                      0...4294967295 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint32 u32_mmv_u32_u32_s16_fac1(uint32 mmv, uint32 measure, sint16 crlc);


/** This operation shall calculate the new floating average of type uint32 with a sint32 value as old floating average, a sint32 value as actual measured value and an uint32 value (0...0.999985) as average value

@param mmv Old floating average

Range:      80000000(H).....7FFFFFFF(H)
                 -2147483648....2147483647
@param measure Actual measured value

Range:      80000000(H).....7FFFFFFF(H)
                 -2147483648....2147483647
@param crlc Constant value

Range:      00(H)...FFFFFFFF(H)
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

Range:       00(H).......FFFFFFFF(H)
               0...4294967295 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint32 u32_mmv_s32_s32_u32_fac1(sint32 mmv, sint32 measure, uint32 crlc);


/** This operation shall calculate the new floating average of type uint32 with a sint32 value as old floating average, a sint32 value as actual measured value and an uint16 value (0...0.99997) as average value

@param mmv Old floating average

Range:      80000000(H).....7FFFFFFF(H)
                 -2147483648....2147483647
@param measure Actual measured value

Range:      80000000(H).....7FFFFFFF(H)
                 -2147483648....2147483647
@param crlc Constant value

Range:      00(H)...FFFF(H)
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

Range:      00(H)......FFFFFFFF(H)
                     0...4294967295 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint32 u32_mmv_s32_s32_u16_fac1(sint32 mmv, sint32 measure, uint16 crlc);


/** This operation shall calculate the new floating average of type uint32 with a sint32 value as old floating average, a sint32 value as actual measured value and a sint32 value (-1....0.9999) as average value

@param mmv Old floating average

Range:      80000000(H).....7FFFFFFF(H)
                 -2147483648....2147483647
@param measure Actual measured value

Range:      80000000(H).....7FFFFFFF(H)
                 -2147483648....2147483647
@param crlc Constant value

Range:      80000000(H).....7FFFFFFF(H)
                           -1......0.9999
@return result = mmv + ((( measure - mmv) * crlc) >> 31),   result  rounded  off

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

Range:      00(H).....FFFFFFFF(H)
              0...4294967295 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint32 u32_mmv_s32_s32_s32_fac1(sint32 mmv, sint32 measure, sint32 crlc);


/** This operation shall calculate the new floating average of type uint32 with a sint32 value as old floating average, a sint32 value as actual measured value and a sint16 value (-1....0.9999) as average value

@param mmv Old floating average

Range:      80000000(H).....7FFFFFFF(H)
                 -2147483648....2147483647
@param measure Actual measured value

Range:      80000000(H).....7FFFFFFF(H)
                 -2147483648....2147483647
@param crlc Constant value

Range:      8000(H).....7FFF(H)
                    -1......0.9999
@return result = mmv + ((( measure - mmv) * crlc) >> 15),   result  rounded  off

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

Range:      00(H).........FFFFFFFF(H)
                0...4294967295 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint32 u32_mmv_s32_s32_s16_fac1(sint32 mmv, sint32 measure, sint16 crlc);


/** This operation shall calculate the new floating average of type sint32 with a sint32 value as old floating average, a sint32 value as actual measured value and a uint16 value (0....0.99998) as average value

@param mmv Old floating average

Range:      80000000(H).....7FFFFFFF(H)
                 -2147483648....2147483647
@param measure Actual measured value

Range:      80000000(H).....7FFFFFFF(H)
                 -2147483648....2147483647
@param crlc Constant value

Range:      00(H).....FFFF(H)
                    0......0.99998
@return result = mmv + ((( measure - mmv) * crlc) >> 16),   result  rounded  off

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

Range:      80000000(H).........7FFFFFFF(H)
            -2147483648...2147483647 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern sint32 s32_mmv_s32_s32_u16_fac1(sint32 mmv, sint32 measure, uint16 crlc);


/** This operation shall calculate the output (sint16) of a first order high-Pass filter with the input parameters as previous output (yold), present input (u), previous input (uold) and a constant multiplying factor (m) with overflow and underflow limitation

@param yold Previous output 

Range:      8000(H)..........7FFF(H)
         -256......255.9921875
@param u Present input

Range:      00(H).....FF(H)
            0.....255
@param uold Previous input

Range:      00(H).....FF(H)
            0.....255
@param m Constant multiplying factor

Range:      00(H).....FFFF(H)
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

Range:      8000(H)..........7FFF(H)
         -256......255.9921875 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern sint16 s16_hip1_s16_u8_u8_u16_fac1(sint16 yold, uint8 u, uint8 uold, uint16 m);


/** This operation shall calculate the output (sint16) of a first order high-Pass filter with the input parameters as previous output (yold), present input (u), previous input (uold) and a constant multiplying factor (m) with overflow and underflow limitation

@param yold Previous output

Range:      8000(H)..........7FFF(H)
         -256......255.9921875
@param u Present input

Range:      80(H).....7F(H)
          -128.....127
@param uold Previous input

Range:      80(H).....7F(H)
          -128.....127
@param m Constant multiplying factor

Range:      00(H).....FFFF(H)
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

Range:      8000(H)..........7FFF(H)
         -256......255.9921875 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern sint16 s16_hip1_s16_s8_s8_u16_fac1(sint16 yold, sint8 u, sint8 uold, uint16 m);


/** This operation shall calculate the output (sint32) of a first order high-Pass filter with the input parameters as previous output (yold), present input (u), previous input (uold) and a constant multiplying factor (m) with overflow and underflow limitation

@param yold Previous output

Range:      80000000(H)..........7FFFFFFF(H)
              -65536.......65535.99996
@param u Present input

Range:      00(H).....FFFF(H)
            0.....65535
@param uold Previous input

Range:      00(H).....FFFF(H)
            0.....65535
@param m Constant multiplying factor

Range:      00(H).....FFFF(H)
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

Range:      80000000(H)..........7FFFFFFF(H)
              -65536.......65535.99996 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern sint32 s32_hip1_s32_u16_u16_u16_fac1(sint32 yold, uint16 u, uint16 uold, uint16 m);


/** This operation shall calculate the output (sint32) of a first order high-Pass filter with the input parameters as previous output (yold), present input (u), previous input (uold) and a constant multiplying factor (m) with overflow and underflow limitation

@param yold Previous output

Range:      80000000(H)..........7FFFFFFF(H)
              -65536.......65535.99996
@param u Present input

Range:      8000(H).....7FFF(H)
          -32768..0..32767
@param uold Previous input

Range:      8000(H).....7FFF(H)
          -32768..0..32767
@param m Constant multiplying factor

Range:      00(H).....FFFF(H)
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

Range:      80000000(H)..........7FFFFFFF(H)
              -65536.......65535.99996 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern sint32 s32_hip1_s32_s16_s16_u16_fac1(sint32 yold, sint16 u, sint16 uold, uint16 m);


/** This operation shall perform division of sint16 value by sint16 value with overflow and underflow limitation to produce a result of type sint16

@param numerator Numerator

Range:      8000(H).....7FFF(H)
          -32768....32767
@param denominator Denominator

Range:      8000(H).....7FFF(H)
          -32768....32767
@return (numerator << 16) / denominator, result rounded off
- Limit overflow to:    0x7FFF (32767)
- Limit underflow to:   0x8000 ( -32768)
- Value after division by 0 with  the numerator being >= 0:    0x7FFF(32767)
- Value after division by 0 with  the numerator being < 0:     0x8000(-32768)

Range:      8000(H).....7FFF(H)
          -32768....32767
 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern sint16 s16_fac05_div_s16_s16(sint16 numerator, sint16 denominator);


/** This operation shall perform division of sint32 value by sint16 value with overflow and underflow limitation to produce a result of type sint16

@param x_value Numerator

Range:      80000000(H).....7FFFFFFF(H)
         -2147483648....2147483647
@param y_value Denominator

Range:      8000(H).....7FFF(H)
          -32768....32767
@return x_value / y_value, result rounded off
- Limit overflow to:    0x7FFF (32767)
- Limit underflow to:   0x8000 ( -32768)
- Value after division by 0 with  the numerator being >= 0:    0x7FFF(32767)
- Value after division by 0 with  the numerator being < 0:     0x8000(-32768)

Range:      8000(H).....7FFF(H)
          -32768....32767 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern sint16 s16_div_s32_s16(sint32 x_value, sint16 y_value);


/** This operation shall perform division of sint16 value by uint16 value with overflow and underflow limitation to produce a result of type sint16

@param numerator Numerator

Range:      8000(H).....7FFF(H)
          -32768....32767
@param denominator Denominator

Range:      00(H).....FFFF(H)
             0....65535
@return (numerator << 16) / denominator, result rounded off
- Limit overflow to:    0x7FFF (32767)
- Limit underflow to:   0x8000 ( -32768)
- Value after division by 0 with  the numerator being >= 0:    0x7FFF(32767)
- Value after division by 0 with  the numerator being < 0:     0x8000(-32768)

Range:      8000(H).....7FFF(H)
          -32768....32767 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern sint16 s16_fac05_div_s16_u16(sint16 numerator, uint16 denominator);


/** This operation shall perform division of sint16 value by uint16 value with overflow and underflow limitation to produce a result of type sint16

@param numerator Numerator

Range:      8000(H).....7FFF(H)
          -32768....32767
@param denominator Denominator

Range:      00(H).....FFFF(H)
             0....65535
@return numerator / denominator, result rounded off
- Limit overflow to:    0x7FFF (32767)
- Limit underflow to:   0x8000 ( -32768)
- Value after division by 0 with  the numerator being >= 0:    0x7FFF(32767)
- Value after division by 0 with  the numerator being < 0:     0x8000(-32768)

Range:      8000(H).....7FFF(H)
          -32768....32767 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern sint16 s16_div_s16_u16_shl0(sint16 numerator, uint16 denominator);


/** This operation shall perform division of uint16 value by uint16 value with overflow limitation to produce a result of type uint8

@param numerator Numerator

Range:      00(H).....FFFF(H)
             0....65535
@param denominator Denominator

Range:      00(H).....FFFF(H)
             0....65535
@return ((numerator << 16) / denominator) >> 8, result rounded off
- Limit overflow to:    0xFF (255)
- Value after division by 0:    0xFF(255)

Range:      00(H)....FF(H)
            0....255 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint8 u8_fac1_div_u16_u16(uint16 numerator, uint16 denominator);


/** This operation shall perform division of sint32 value by uint16 value with overflow and underflow limitation to produce a result of type uint16

@param x_value Numerator

Range:      80000000(H).....7FFFFFFF(H)
         -2147483648....2147483647
@param y_value Denominator

Range:      00(H).....FFFF(H)
             0....65535
@return x_value / y_value, result rounded off
- Limit overflow to:    0xFFFF (65535)
- Limit underflow to:   0x0000 (0)
- Value after division by 0 with  the numerator being >= 0:   0xFFFF(65535)
- Value after division by 0 with  the numerator being < 0:     0x0000(0)

Range:      00(H).....FFFF(H)
             0....65535 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 u16_div_s32_u16(sint32 x_value, uint16 y_value);


/** This operation shall perform division of uint16 value by uint16 value with overflow limitation to produce a result of type uint16

@param numerator Numerator

Range:      00(H).....FFFF(H)
             0....65535
@param denominator Denominator

Range:      00(H).....FFFF(H)
             0....65535
@return (numerator << 16) / denominator, result rounded off
- Limit overflow to:    0xFFFF (65535)
- Value after division by 0:    0xFFFF(65535)

Range:      00(H)....FFFF(H)
            0....65535 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 u16_fac1_div_u16_u16(uint16 numerator, uint16 denominator);


/** This operation shall perform division of uint32 value by uint16 value with overflow limitation to produce a result of type uint16

@param x_value Numerator

Range:      00(H).....FFFFFFFF(H)
             0....4294967295
@param y_value Denominator

Range:      00(H).....FFFF(H)
             0....65535
@return x_value / y_value, result rounded off
- Limit overflow to:    0xFFFF (65535)
- Value after division by 0:    0xFFFF(65535)

Range:      00(H)....FFFF(H)
            0....65535 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 u16_div_u32_u16(uint32 x_value, uint16 y_value);


/** This operation shall multiply sint16 value by an uint16 value and divide the result by sint16 value with overflow and underflow limitation to produce a result of type sint16

@param factor1 First factor

Range:      8000(H).....7FFF(H)
          -32768....32767
@param factor2 Second factor

Range:      00(H).....FFFF(H)
            0....65535
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

extern sint16 s16_mul_s16_u16_div_s16(sint16 factor1, uint16 factor2, sint16 denominator);


/** This operation shall multiply uint16 value by sint16 value and divide the result by uint16 value with overflow and underflow limitation to produce a result of type sint16

@param factor1 First factor

Range:      00(H).....FFFF(H)
            0....65535
@param factor2 Second factor

Range:      8000(H).....7FFF(H)
          -32768....32767
@param denominator Denominator

Range:      00(H).....FFFF(H)
            0....65535
@return (factor1 * factor2) / denominator, result rounded off
- Limit overflow to:    0x7FFF (32767)
- Limit underflow to:   0x8000 ( -32768)
- Value after division by 0 with  the numerator being >= 0:    0x7FFF(32767)
- Value after division by 0 with  the numerator being < 0:     0x8000(-32768)

Range:      8000(H).....7FFF(H)
          -32768....32767 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern sint16 s16_mul_u16_s16_div_u16(uint16 factor1, sint16 factor2, uint16 denominator);


/** This operation shall multiply sint16 value by uint16 value and divide the result by sint16 value with overflow and underflow limitation to produce a result of type uint16

@param factor1 First factor

Range:      8000(H).....7FFF(H)
          -32768....32767
@param factor2 Second factor

Range:      00(H).....FFFF(H)
            0....65535
@param denominator Denominator

Range:      8000(H).....7FFF(H)
          -32768....32767
@return (factor1 * factor2) / denominator, result rounded off
- Limit overflow to:    0xFFFF (65535)
- Limit underflow to:   0x0000 (0)
- Value after division by 0 with  the numerator being >= 0:   0xFFFF(65535)
- Value after division by 0 with  the numerator being < 0:     0x0000(0)

Range:      00(H).....FFFF(H)
             0....65535 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 u16_mul_s16_u16_div_s16(sint16 factor1, uint16 factor2, sint16 denominator);


/** This operation shall multiply sint16 value by uint16 value and divide the result by uint16 value with overflow and underflow limitation to produce a result of type uint16

@param factor1 First factor

Range:      8000(H).....7FFF(H)
          -32768....32767
@param factor2 Second factor

Range:      00(H).....FFFF(H)
            0....65535
@param denominator Denominator

Range:      00(H).....FFFF(H)
            0....65535
@return (factor1 * factor2) / denominator, result rounded off
- Limit overflow to:    0xFFFF (65535)
- Limit underflow to:   0x0000 (0)
- Value after division by 0 with  the numerator being >= 0:   0xFFFF(65535)
- Value after division by 0 with  the numerator being < 0:     0x0000(0)

Range:      00(H).....FFFF(H)
             0....65535 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 u16_mul_s16_u16_div_u16(sint16 factor1, uint16 factor2, uint16 denominator);


/** This operation shall multiply uint16 value by uint16 value and divide the result by uint16 value with overflow limitation to produce a result of type uint16

@param factor1 First factor

Range:      00(H).....FFFF(H)
            0....65535
@param factor2 Second factor

Range:      00(H).....FFFF(H)
            0....65535
@param denominator Denominator

Range:      00(H).....FFFF(H)
            0....65535
@return (factor1 * factor2) / denominator, result rounded off
- Limit overflow to:    0xFFFF (65535)
- Value after division by 0:    0xFFFF(65535)

Range:      00(H)....FFFF(H)
            0....65535 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 u16_mul_u16_u16_div_u16(uint16 factor1, uint16 factor2, uint16 denominator);


/** This operation shall multiply uint16 value by uint16 value and divide the result by uint32 with overflow limitation to produce a result of type uint16

@param factor1 First factor

Range:      00(H).....FFFF(H)
            0....65535
@param factor2 Second factor

Range:      00(H).....FFFF(H)
            0....65535
@param denominator Denominator

Range:      00(H).....FFFFFFFF(H)
            0....4294967295
@return (factor1 * factor2) / denominator, result rounded off
- Limit overflow to:    0xFFFF (65535)
- Value after division by 0:    0xFFFF(65535)

Range:      00(H)....FFFF(H)
            0....65535 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 u16_mul_u16_u16_div_u32(uint16 factor1, uint16 factor2, uint32 denominator);


/** This operation shall perform division of uint32 value by an uint16 value to produce a result of uint32 with overflow limitation

@param x_value Numerator

Range:      00(H).....FFFFFFFF(H)
            0....4294967295
@param y_value Denominator

Range:      00(H).....FFFF(H)
            0....65535
@return x_value / y_value, result rounded off
Value after division by zero:   0xFFFFFFFF(4294967295)      

Range:      00(H) ... FFFFFFFF(H)
            0 ... 4294967295 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint32 u32_div_u32_u16(uint32 x_value, uint16 y_value);


/** This operation shall multiply sint16 value by an sint16 value and divide the result by sint16 value with overflow and underflow limitation to produce a result of type sint16

@param factor1 First factor

Range:      8000(H).....7FFF(H)
          -32768....32767
@param factor2 Second factor

Range:      8000(H).....7FFF(H)
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

extern sint16 s16_mul_s16_s16_div_s16(sint16 factor1, sint16 factor2, sint16 denominator);


/** This operation shall multiply sint16 value by an sint16 value and divide the result by uint16 value with overflow and underflow limitation to produce a result of type sint16

@param data1 First data

Range:      8000(H).....7FFF(H)
          -32768....32767
@param data2 Second data

Range:      8000(H).....7FFF(H)
          -32768....32767
@param denominator Denominator

Range:      00(H).....FFFF(H)
            0....65535
@return (data1 * data2) / denominator, result rounded off
- Limit overflow to:    0x7FFF (32767)
- Limit underflow to:   0x8000 ( -32768)
- Value after division by 0 with  the numerator being >= 0:    0x7FFF(32767)
- Value after division by 0 with  the numerator being < 0:     0x8000(-32768)

Range:      8000(H).....7FFF(H)
          -32768....32767 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern sint16 s16_mul_s16_s16_div_u16(sint16 data1, sint16 data2, uint16 denominator);


/** This operation shall perform division of an uint32 value by an sint32 to produce a result of uint32 with underflow limitation

@param numerator Numerator

Range:      00(H).....FFFFFFFF(H)
            0....4294967295
@param denominator Denominator

Range:      80000000(H).....7FFFFFFF(H)
         -2147483648....2147483647
@return numerator / denominator, result rounded off
- Limit underflow to: 0x00(0)
- Value after division by zero: 0xFFFFFFFF(4294967295)

Range:      00(H) ... FFFFFFFF(H)
            0 ... 4294967295 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint32 u32_div_u32_s32(uint32 numerator, sint32 denominator);


/** This operation shall perform division of sint32 value by an uint32 value to produce a result of uint32 with underflow limitation

@param numerator Numerator

Range:      80000000(H).....7FFFFFFF(H)
         -2147483648....2147483647
@param denominator Denominator

Range:      00(H).....FFFFFFFF(H)
            0....4294967295
@return numerator / denominator, result rounded off
- Limit underflow to: 0x00(0)
- Value after division by 0 with  the numerator being >= 0:    0xFFFFFFFF(4294967295)
- Value after division by 0 with  the numerator being < 0:     0x00(0)      
Range:      00(H) ... FFFFFFFF(H)
            0 ... 4294967295 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint32 u32_div_s32_u32(sint32 numerator, uint32 denominator);


/** This operation shall perform division of sint32 value by an sint32 value to produce a result of uint32 with underflow limitation

@param numerator Numerator

Range:      80000000(H).....7FFFFFFF(H)
         -2147483648....2147483647
@param denominator Denominator

Range:      80000000(H).....7FFFFFFF(H)
         -2147483648....2147483647
@return numerator / denominator, result rounded off
- Limit underflow to: 0x00(0)
- Value after division by 0 with  the numerator being >= 0:    0xFFFFFFFF(4294967295)
- Value after division by 0 with  the numerator being < 0:     0x00(0)      
Range:      00(H) ... FFFFFFFF(H)
            0 ... 4294967295 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint32 u32_div_s32_s32(sint32 numerator, sint32 denominator);


/** This operation shall perform division of uint32 value by an uint32 value to produce a result of uint32

@param numerator Numerator

Range:      00(H).....FFFFFFFF(H)
            0....4294967295
@param denominator Denominator

Range:      00(H).....FFFFFFFF(H)
            0....4294967295
@return numerator / denominator, result rounded off
Value after division by zero:    0xFFFFFFFF(4294967295)

Range:      00(H) ... FFFFFFFF(H)
            0 ... 4294967295 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint32 u32_div_u32_u32(uint32 numerator, uint32 denominator);


/** This operation shall perform division of uint32 value by an sint32 value to produce a result of sint32 with underflow and overflow limitation

@param numerator Numerator

Range:      00(H).....FFFFFFFF(H)
            0....4294967295
@param denominator Denominator

Range:      80000000(H).....7FFFFFFF(H) 
         -2147483648....2147483647
@return numerator / denominator, result rounded off
- Limit overflow to: 0x7FFFFFFF(2147483647)
- Limit underflow to: 0x80000000(-2147483648)
- Value after division by zero:    0x7FFFFFFF(2147483647)

Range:      80000000(H) ... 7FFFFFFF(H)
         -2147483648 ... 2147483647 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern sint32 s32_div_u32_s32(uint32 numerator, sint32 denominator);


/** This operation shall perform division of sint32 value by an uint32 value to produce a result of sint32

@param numerator Numerator

Range:      80000000(H).....7FFFFFFF(H)
         -2147483648....2147483647
@param denominator Denominator

Range:      00(H).....FFFFFFFF(H)
            0....4294967295
@return numerator / denominator, result rounded off
- Value after division by 0 with  the numerator being >= 0:    0x7FFFFFFF(2147483647)
- Value after division by 0 with  the numerator being < 0:     0x80000000(-2147483648)

Range:      80000000(H) ... 7FFFFFFF(H)
         -2147483648 ... 2147483647 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern sint32 s32_div_s32_u32(sint32 numerator, uint32 denominator);


/** This operation shall perform division of sint32 value by an sint32 value to produce a result of sint32 with overflow limitation

@param numerator Numerator

Range:      80000000(H).....7FFFFFFF(H)
         -2147483648....2147483647
@param denominator Denominator

Range:      80000000(H).....7FFFFFFF(H)
         -2147483648....2147483647
@return numerator / denominator, result rounded off
- Limit overflow to: 0x7FFFFFFF(2147483647)
- Value after division by 0 with  the numerator being >= 0:    0x7FFFFFFF(2147483647)
- Value after division by 0 with  the numerator being < 0:     0x80000000(-2147483648)

Range:      80000000(H) ... 7FFFFFFF(H)
         -2147483648 ... 2147483647 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern sint32 s32_div_s32_s32(sint32 numerator, sint32 denominator);


/** This operation shall perform division of sint32 value by an uint32 value to produce a result of sint16 with underflow and overflow limitation

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

extern sint16 s16_div_s32_u32(sint32 numerator, uint32 denominator);


/** This operation shall multiply an uint32 value by an uint32 value and divide the result by an uint32 value with overflow limitation to produce a result of type uint32

@param factor1 First factor

Range:      00(H).....FFFFFFFF(H)
            0....4294967295
@param factor2 Second factor

Range:      00(H).....FFFFFFFF(H)
            0....4294967295
@param denominator Denominator

Range:      00(H).....FFFFFFFF(H)
            0....4294967295
@return (factor1 * factor2) / denominator, result rounded off
- Limit overflow to: 0xFFFFFFFF(4294967295)
- Value after division by zero:    0xFFFFFFFF(4294967295)

Range:      00(H) ... FFFFFFFF(H)
             0....4294967295 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint32 u32_mul_u32_u32_div_u32(uint32 factor1, uint32 factor2, uint32 denominator);


/** This operation shall multiply an uint32 value by an uint32 value and divide the result by an sint32 value with overflow and underflow limitation to produce a result of type uint32

@param factor1 First factor

Range:      00(H).....FFFFFFFF(H)
            0....4294967295
@param factor2 Second factor

Range:      00(H).....FFFFFFFF(H)
            0....4294967295
@param denominator Denominator

Range:      80000000(H).....7FFFFFFF(H)
         -2147483648....2147483647
@return (factor1 * factor2) / denominator, result rounded off
- Limit overflow to: 0xFFFFFFFF(4294967295)
- Limit underflow to: 0x00(0)
- Value after division by zero:    0xFFFFFFFF(4294967295)

Range:      00(H) ... FFFFFFFF(H)
             0....4294967295 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint32 u32_mul_u32_u32_div_s32(uint32 factor1, uint32 factor2, sint32 denominator);


/** This operation shall multiply an uint32 value by an sint32 value and divide the result by an uint32 value with overflow and underflow limitation to produce a result of type uint32

@param factor1 First factor

Range:      00(H).....FFFFFFFF(H)
            0....4294967295
@param factor2 Second factor

Range:      80000000(H).....7FFFFFFF(H)
         -2147483648....2147483647
@param denominator Denominator

Range:      00(H).....FFFFFFFF(H)
            0....4294967295
@return (factor1 * factor2) / denominator, result rounded off
- Limit overflow to: 0xFFFFFFFF(4294967295)
- Limit underflow to: 0x00(0)
- Value after division by 0 with  the numerator being >= 0:    0xFFFFFFFF(4294967295)
- Value after division by 0 with  the numerator being < 0:     0x00(0)

Range:      00(H) ... FFFFFFFF(H)
             0 ... 4294967295 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint32 u32_mul_u32_s32_div_u32(uint32 factor1, sint32 factor2, uint32 denominator);


/** This operation shall multiply an uint32 value by an sint32 value and divide the result by an sint32 value with overflow and underflow limitation to produce a result of type uint32

@param factor1 First factor

Range:      00(H).....FFFFFFFF(H)
            0....4294967295
@param factor2 Second factor

Range:      80000000(H).....7FFFFFFF(H)
         -2147483648....2147483647
@param denominator Denominator

Range:      80000000(H).....7FFFFFFF(H)
         -2147483648....2147483647
@return (factor1 * factor2) / denominator, result rounded off
- Limit overflow to: 0xFFFFFFFF(4294967295)
- Limit underflow to: 0x00(0)
- Value after division by 0 with  the numerator being >= 0:    0xFFFFFFFF(4294967295)
- Value after division by 0 with  the numerator being < 0:     0x00(0)

Range:      00(H) ... FFFFFFFF(H)
             0 ... 4294967295 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint32 u32_mul_u32_s32_div_s32(uint32 factor1, sint32 factor2, sint32 denominator);


/** This operation shall multiply an sint32 value by an sint32 value and divide the result by an sint32 value with overflow and underflow limitation to produce a result of type sint32

@param factor1 First factor

Range:      80000000(H).....7FFFFFFF(H)
         -2147483648....2147483647
@param factor2 Second factor

Range:      80000000(H).....7FFFFFFF(H)
         -2147483648....2147483647
@param denominator Denominator

Range:      80000000(H).....7FFFFFFF(H)
         -2147483648....2147483647
@return (factor1 * factor2) / denominator, result rounded off
- Limit overflow to: 0x7FFFFFFF(2147483647)
- Limit underflow to: 0x80000000(-2147483648)
- Value after division by 0 with  the numerator being >= 0:    0x7FFFFFFF(2147483647)
- Value after division by 0 with  the numerator being < 0:     0x80000000(-2147483648)

Range:      80000000(H) ... 7FFFFFFF(H)
         -2147483648 ... 2147483647 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern sint32 s32_mul_s32_s32_div_s32(sint32 factor1, sint32 factor2, sint32 denominator);


/** This operation shall multiply an sint32 value by an sint32 value and divide the result by an uint32 value with overflow and underflow limitation to produce a result of type sint32

@param factor1 First factor

Range:      80000000(H).....7FFFFFFF(H)
         -2147483648....2147483647
@param factor2 Second factor

Range:      80000000(H).....7FFFFFFF(H)
         -2147483648....2147483647
@param denominator Denominator

Range:      00(H).....FFFFFFFF(H)
            0....4294967295
@return (factor1 * factor2) / denominator, result rounded off
- Limit overflow to: 0x7FFFFFFF(2147483647)
- Limit underflow to: 0x80000000(-2147483648)
- Value after division by 0 with  the numerator being >= 0:    0x7FFFFFFF(2147483647)
- Value after division by 0 with  the numerator being < 0:     0x80000000(-2147483648)

Range:      80000000(H) ... 7FFFFFFF(H)
         -2147483648 ... 2147483647 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern sint32 s32_mul_s32_s32_div_u32(sint32 factor1, sint32 factor2, uint32 denominator);


/** This operation shall multiply an uint32 value by an sint32 value and divide the result by an sint32 value with overflow and underflow limitation to produce a result of type sint32

@param factor1 First factor

Range:      00(H).....FFFFFFFF(H)
            0....4294967295
@param factor2 Second factor

Range:      80000000(H).....7FFFFFFF(H)
         -2147483648....2147483647
@param denominator Denominator

Range:      80000000(H).....7FFFFFFF(H)
         -2147483648....2147483647
@return (factor1 * factor2) / denominator, result rounded off
- Limit overflow to: 0x7FFFFFFF(2147483647)
- Limit underflow to: 0x80000000(-2147483648)
- Value after division by 0 with  the numerator being >= 0:    0x7FFFFFFF(2147483647)
- Value after division by 0 with  the numerator being < 0:     0x80000000(-2147483648)

Range:      80000000(H) ... 7FFFFFFF(H)
         -2147483648 ... 2147483647 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern sint32 s32_mul_u32_s32_div_s32(uint32 factor1, sint32 factor2, sint32 denominator);


/** This operation shall multiply an uint32 value by an sint32 value and divide the result by an uint32 value with overflow and underflow limitation to produce a result of type sint32

@param factor1 First factor

Range:      00(H).....FFFFFFFF(H)
            0....4294967295
@param factor2 Second factor

Range:      80000000(H).....7FFFFFFF(H)
         -2147483648....2147483647
@param denominator Denominator of type uint32

Range:      00(H).....FFFFFFFF(H)
            0....4294967295
@return (factor1 * factor2) / denominator, result rounded off
- Limit overflow to: 0x7FFFFFFF(2147483647)
- Limit underflow to: 0x80000000(-2147483648)
- Value after division by 0 with  the numerator being >= 0:    0x7FFFFFFF(2147483647)
- Value after division by 0 with  the numerator being < 0:     0x80000000(-2147483648)

Range:      80000000(H) ... 7FFFFFFF(H)
         -2147483648 ... 2147483647 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern sint32 s32_mul_u32_s32_div_u32(uint32 factor1, sint32 factor2, uint32 denominator);


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

extern sint32 s32_div_s32_u16(sint32 numerator, uint16 denominator);


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

extern sint16 s16_div_s32_s32(sint32 numerator, sint32 denominator);


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

extern sint16 s16_div_s32_u16(sint32 numerator, uint16 denominator);


/** This operation shall perform division of uint32 value by an uint32 value to produce a result of uint16 with underflow and overflow limitation
@param numerator  Numerator

 Range:     00(H).....FFFFFFFF(H)
            0....4294967295

@param denominator  Denominator

 Range:     00(H).....FFFFFFFF(H)
            0....4294967295

@param x_value Numerator

Range:      00(H).....FFFFFFFF(H)
             0....4294967295
@param y_value Denominator

Range:      00(H).....FFFFFFFF(H)
             0....4294967295
@return x_value / y_value, result rounded off
- Limit overflow to:    0xFFFF (65535)
- Value after division by 0:    0xFFFF(65535)

Range:      00(H)....FFFF(H)
            0....65535 */
#define IOPT_MEMMAP_CODE MEMMAP_CODE(LIB_FCT, ASIL_D, GLOBAL, IOPT_STDLIB)
#include "iopt_memmap.h"

extern uint16 u16_div_u32_u32(uint32 numerator, uint32 denominator);


/** This operation shall multiply sint32 value by an sint16 value and divide the result by sint16 value with overflow and underflow limitation to produce a result of type sint16

@param factor1  First factor

 Range:     80000000(H).....7FFFFFFF(H)
         -2147483648....2147483647
@param factor2  Second factor

 Range:     8000(H).....7FFF(H)
          -32768....32767

@param denominator  Denominator

 Range:     8000(H).....7FFF(H)
          -32768....32767

@param factor1 First factor

Range:      80000000(H).....7FFFFFFF(H)
         -2147483648....2147483647
@param factor2 Second factor

Range:      8000(H).....7FFF(H)
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

extern sint16 s16_mul_s32_s16_div_s16(sint32 factor1, sint16 factor2, sint16 denominator);


/** This operation shall perform addition of three sINT32 variables with underflow and overflow limitation and return result of type sINT32

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

extern sint32 s32_add_s32_s32_s32(sint32 x_value, sint32 y_value, sint32 z_value);
/*~E*/
/*lint -restore : (of 715,704,530 before) */
#include "iopt_memmap.h"
#endif
