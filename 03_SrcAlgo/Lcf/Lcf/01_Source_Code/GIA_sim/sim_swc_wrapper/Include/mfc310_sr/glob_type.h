/*! \file **********************************************************************

  COMPONENT:              -

  MODULENAME:             glob_type.he

  @brief                  This file contains all global types, needed in most components

  ---*/ /*---

  CHANGES
  ---------------

  VERSIONNUMBER:          $Revision: 1.1 $

  EDITOR NAME:            $Author: Wang, David (Wangd3) $
  
  CHANGES:                $Log: glob_type.h  $
  CHANGES:                Revision 1.1 2021/12/13 17:26:17CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310_sr/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:37:22CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310_sr/project.pj
  CHANGES:                Revision 1.1 2014/03/13 15:12:53CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310_sr/project.pj
  CHANGES:                Revision 1.2 2010/04/13 09:06:37CEST uerpen 
  CHANGES:                Change long int types to int, so that there effective size is 4 bytes. e.g. ui32_t
  CHANGES:                --- Added comments ---  uerpen [2010/04/13 07:09:10Z]
  CHANGES:                Change Package : 36045:14 http://LISS014:6001/im/viewissue?selection=36045
  CHANGES:                Revision 1.1 2009/10/14 18:57:25CEST Hubert Will   (hwill) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/BaseDevelopment_Camera_SW/02_Engineering/TMS320DM643x/11_MFC300/01_Design/vuc/headers/project.pj
  CHANGES:                Revision 1.29 2008/05/15 09:57:18CEST Thomas Diepolder (tdiepolder) 
  CHANGES:                Source code comments corrected to remove pdo issues
  CHANGES:                
  CHANGES:                --- Added comments ---  tdiepolder [2008/05/15 07:57:19Z]
  CHANGES:                Change Package : 12863:1 http://liss014:6001/im/viewissue?selection=12863
  CHANGES:                Revision 1.28 2008/03/28 08:44:19CET tdiepolder 
  CHANGES:                Extension of speed corrrection interface
  CHANGES:                --- Added comments ---  tdiepolder [2008/03/28 07:44:19Z]
  CHANGES:                Change Package : 11029:1 http://liss014:6001/im/viewissue?selection=11029
  CHANGES:                Revision 1.27 2007/11/05 11:01:14CET tstalder 
  CHANGES:                removed some project specific datatypes
  CHANGES:                (moved to glob_type_project.h)
  CHANGES:                --- Added comments ---  tstalder [2007/11/05 10:01:14Z]
  CHANGES:                Change Package : 6362:1 http://liss014:6001/im/viewissue?selection=6362
  CHANGES:                Revision 1.26 2007/10/04 09:09:24CEST kreinbott 
  CHANGES:                Moved types to module glob_type_project.h.
  CHANGES:                
  CHANGES:                --- Added comments ---  kreinbott [2007/10/04 07:09:25Z]
  CHANGES:                Change Package : 6033:1 http://liss014:6001/im/viewissue?selection=6033
  CHANGES:                Revision 1.25 2007/09/26 10:33:44CEST gungvary 
  CHANGES:                Removed BOOL type
  CHANGES:                --- Added comments ---  gungvary [2007/09/26 08:33:44Z]
  CHANGES:                Change Package : 5921:1 http://liss014:6001/im/viewissue?selection=5921
  CHANGES:                Revision 1.24 2007/06/22 14:14:34CEST mhinn 
  CHANGES:                added typedef f32_t fUncertainty_t;
  CHANGES:                --- Added comments ---  mhinn [2007/06/22 12:14:34Z]
  CHANGES:                Change Package : 3188:1 http://liss014:6001/im/viewissue?selection=3188
  CHANGES:                Revision 1.23 2007/06/11 15:23:18CEST gungvary 
  CHANGES:                Remove T_U64 type, as it is currently unused anyway (and generates pre-proc warnings with M32R)
  CHANGES:                --- Added comments ---  gungvary [2007/06/11 13:23:18Z]
  CHANGES:                Change Package : 2459:3 http://liss014:6001/im/viewissue?selection=2459
  CHANGES:                Revision 1.22 2007/06/05 18:23:22CEST gungvary 
  CHANGES:                Fix M32R define
  CHANGES:                --- Added comments ---  gungvary [2007/06/05 16:23:22Z]
  CHANGES:                Change Package : 2459:1 http://liss014:6001/im/viewissue?selection=2459
  CHANGES:                Revision 1.21 2007/06/05 18:09:03CEST gungvary 
  CHANGES:                Add TEMIC-Hybrid types needed by modules from Continental Temic Hybrid Berlin
  CHANGES:                --- Added comments ---  gungvary [2007/06/05 16:09:03Z]
  CHANGES:                Change Package : 2459:1 http://liss014:6001/im/viewissue?selection=2459
  CHANGES:                Revision 1.20 2007/05/02 09:34:36CEST mkammerl 
  CHANGES:                place the following typedefs in glob_type.he 
  CHANGES:                - DynamicProperty_t
  CHANGES:                - ObjectClassification_t
  CHANGES:                - MeasStatus_t
  CHANGES:                - AssignedLane_t
  CHANGES:                Former all these types were defined in vdata.
  CHANGES:                --- Added comments ---  mkammerl [2007/05/02 07:34:36Z]
  CHANGES:                Change Package : 1999:2 http://liss014:6001/im/viewissue?selection=1999
  CHANGES:                Revision 1.19 2007/04/04 23:00:13CEST jfuehrman 
  CHANGES:                added fVoltage for cl.30 ECU's
  CHANGES:                --- Added comments ---  jfuehrman [2007/04/04 21:00:13Z]
  CHANGES:                Change Package : 1864:1 http://liss014:6001/im/viewissue?selection=1864
  CHANGES:                Revision 1.18 2007/03/13 11:25:08CET tdiepolder 
  CHANGES:                Additional global vdy data tpyes added
  CHANGES:                --- Added comments ---  tdiepolder [2007/03/13 10:25:08Z]
  CHANGES:                Change Package : 1231:1 http://liss014:6001/im/viewissue?selection=1231
  CHANGES:                Revision 1.17 2007/02/23 17:32:05CET wharsche 
  CHANGES:                Types for vehicle velocity correction added
  CHANGES:                --- Added comments ---  wharsche [2007/02/23 16:32:05Z]
  CHANGES:                Change Package : 1409:2 http://liss014:6001/im/viewissue?selection=1409
  CHANGES:                Revision 1.16 2007/01/23 21:05:56CET astohr 
  CHANGES:                make win32 verification build compile again
  CHANGES:                --- Added comments ---  astohr [2007/01/23 20:05:56Z]
  CHANGES:                Change Package : 577:7 http://liss014:6001/im/viewissue?selection=577
  CHANGES:                Revision 1.15 2007/01/23 19:54:58CET astohr 
  CHANGES:                added force code macro for helping in code debug and with micro delays
  CHANGES:                --- Added comments ---  astohr [2007/01/23 18:54:58Z]
  CHANGES:                Change Package : 577:7 http://liss014:6001/im/viewissue?selection=577
  CHANGES:                Revision 1.14 2006/12/21 16:09:56CET astohr 
  CHANGES:                SBD and IPC integration
  CHANGES:                --- Added comments ---  astohr [2006/12/21 15:09:56Z]
  CHANGES:                
  CHANGES:                Change Package : 577:18
  CHANGES:                http://liss014:6001/im/viewissue?selection=577
  CHANGES:                Revision 1.13 2006/12/13 19:15:06CET jfuehrman 
  CHANGES:                added changes keyword for logging
  CHANGES:                added PixelData_t as global type

*****************************************************************************/
#ifndef GLOB_TYPE_H
#define GLOB_TYPE_H



/** @defgroup DataDictionary Data Dictionary
  Here you will find all available data types
  @{
 */

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/

/*************************************************************/
/* basic types */

/*! we are using three different types for bit fields
sbit32_t for a signed bit field of size 32 ; 
ubit32_t for an unsigned bit field of size 32 ;
sbit16_t for a signed bit field of size 16 ;
ubit16_t for an unsigned bit field of size 16 ;
sbit8_t for a signed bit field of size 8 ;
ubit8_t for an unsigned bit field of size 8 ;
In ANSI C the type is always an int (MISRA Rule), but 
if the compiler has the functionality to optimize the allignment
and packing, you can do this by changing the types.
*/

/*lint -emacro(717,FORCE_CODE) | do ... while(0); */
#define  FORCE_CODE() asm(" nop")

#if (defined(__M32R__))
/* M32's CC32 compiler has support for all types of bit-fields, and
ints are always 32bits regardless of their bit-width */
typedef signed int      sbit32_t;
typedef signed short    sbit16_t;
typedef signed char     sbit8_t;
typedef unsigned int    ubit32_t;
typedef unsigned short  ubit16_t;
typedef unsigned char   ubit8_t;

#elif (defined(_MSC_VER))
/* MS-VC supports bit-fields of all types */
#pragma warning(disable:4214)

typedef signed int      sbit32_t;
typedef signed short    sbit16_t;
typedef signed char     sbit8_t;
typedef unsigned int    ubit32_t;
typedef unsigned short  ubit16_t;
typedef unsigned char   ubit8_t;

#else
typedef signed int sbit32_t;   
/*! @see bit32_t */
typedef signed int sbit16_t;
/*! @see bit32_t */
typedef signed int sbit8_t;

/* Unsigned bit-fields are useful, since it is implementation defined,
whether a 'int' bitfield is unsigned or signed. For this reason dedicated
unsigned bits are useful. See also ISO C99 6.7.2 */
typedef unsigned int ubit32_t;
typedef unsigned int ubit16_t;
typedef unsigned int ubit8_t;
#endif

/*! unsigned 8 Bit Value [0,255]*/
typedef unsigned char ui8_t;
 /*! signed 8 Bit Value [-128,+127]*/
typedef signed char i8_t;

/*! unsigned 16 Bit Value [0,65535]*/
typedef unsigned short int ui16_t;

/*! signed 16 Bit Value [32768,32767]*/
typedef signed short int i16_t;

/*! unsigned 32 Bit Value [0,4294967295]*/
typedef unsigned int ui32_t;

/*! signed 32 Bit Value [-2147483648,+2147483647]*/
typedef signed int i32_t;

/*! 32 Bit floating point number [see float.h] */
typedef float f32_t;

/*! 64 Bit floating point number [see float.h] */
typedef double f64_t;

/*! enumaration type */
/* Karl - Heinz Reinbott: Type is deklared as a TEVES type */
/* Do not use type in non TEVES components */
/* typedef ui8_t     enum_t; */

/*! boolean type where FALSE = 0  and TRUE = 1 @see FALSE */
typedef ui8_t     bool_t;

/*! signed 8 Bit Value [0,255]*/
typedef volatile ui8_t      vui8_t;

/*! signed 16 Bit Value [0,65535]*/
typedef volatile ui16_t     vui16_t;

/*! signed 16 Bit Value [0, 2^32]*/
typedef volatile ui32_t     vui32_t;


/*************************************************************/
/* application specific types */

/*! @description: Type for imager pixel data with 8 data lines connected */
typedef ui16_t PixelData_t;

/*! @description: Angular rate about the vertical vehicle axix, left turn = positive, right turn = negative
  @resolution: 7 digits  @unit: rad/s  @min: -3.4E+38  @max: +3.4E+38 */
typedef f32_t fYawRate_t;

/*! @description: Angular rate, left/forward = positive, right/reverse = negative
  @resolution: 7 digits  @unit: rad/s  @min: -3.4E+38  @max: +3.4E+38 */
typedef f32_t fAngleSpeed_t;

/*! @description: fDistance_t 
  @resolution: tbd    @accuracy: tbd  @unit: tbd  
  @min: tbd     @max: tbd       @refreshtime: tbd  */
typedef f32_t fDistance_t;

/*! @description: fVrel_t 
  @resolution: tbd    @accuracy: tbd  @unit: tbd  
  @min: tbd     @max: tbd       @refreshtime: tbd  */
typedef f32_t fVrel_t;

/*! @description: fSpeed_t  
  @resolution: tbd    @accuracy: tbd  @unit: tbd  
  @min: tbd     @max: tbd       @refreshtime: tbd  */
typedef f32_t fSpeed_t;

/*! @description: Period of time
  @resolution: 7 digits  @unit: s  @min: 0  @max: +3.4E+38 */
typedef f32_t fTime_t;

/*! @description: fTemperature_t        
  @resolution: 7 digits  @unit: °C  @min: tbd   @max: tbd  */
typedef f32_t fTemperature_t;

/*! @description: fQuality_t    
  @resolution: 7 digits  @unit: 1   @min: 0   @max: 1.0  */
typedef f32_t fQuality_t;

/*! @description: Confidence
  @resolution: 7 digits  @unit: 1   @min: 0   @max: 1.0  */
typedef f32_t fConfidence_t;

/*! @description: fSteeringAngle_t  
  @resolution: tbd    @accuracy: tbd  @unit: tbd  
  @min: tbd     @max: tbd       @refreshtime: tbd  */
typedef f32_t fSteeringAngle_t;

/*! @description: fWheelSpeed_t 
  @resolution: tbd    @accuracy: tbd  @unit: tbd  
  @min: tbd     @max: tbd       @refreshtime: tbd  */
typedef f32_t fWheelSpeed_t;

/*! @description: Curvature of trajectory (:=1/Radius), left = positive, right = negative
  @resolution: 7 digits  @unit: 1/m   @min: -3.4E+38  @max: +3.4E+38  */
typedef f32_t fCurve_t;

/*! @description: Radius of trajectory, left = positive, right = negative
  @resolution: 7 digits  @unit: m   @min: -3.4E+38  @max: +3.4E+38  */
typedef f32_t fRadius_t;

/*! @description: times_t       
  @resolution: 1  @unit: ms  @min: 0  @max: 65535  */
/* Karl - Heinz Reinbott: comented, due to type is already defined: typedef unsigned_int16_t times_t */  
/* typedef ui16_t times_t; */

/*! @description:  translatory velocity 
  @resolution: 7 digits  @unit: m/s  @min: -3.4E+38  @max: +3.4E+38  */
typedef f32_t fVelocity_t;

/*! @description: translatory acceleration   
  @resolution: 7 digits  @unit: m/s^2  @min: -3.4E+38   @max: +3.4E+38  */
typedef f32_t fAcceleration_t;

/*! @description: gravity load in unit of mass
  @resolution: 7 digits  @unit: kg  @min: 0  @max: +3.4E+38   */
typedef f32_t fWeight_t;

/*! @description: Measurement of geometric size (length, width, height)
  @resolution: 7 digits @unit: m   @min: 0   @max: +3.4E+38    */
typedef f32_t fDimension_t;

/*! @description: Angle in radians
  @resolution: 7 digits  @unit: rad  @min: -3.4E+38   @max: +3.4e+38  */
typedef f32_t fAngle_t;

/*! @description: Relationship of quantity
  @resolution: 7 digits   @unit: 1  @min: -3.4E+38  @max: +3.4E+38 */ 
typedef f32_t fRatio_t;

/*! @description: Change rate (d/dt) of signal. Unit is dependent on considered signal
@resolution: 7 digits  @unit: [?/s] @min: -3.4E+38  @max: +3.4E+38 */
typedef f32_t fGradient_t;

/*! @description: Averaged squared deviation from mean
@resolution: 7 digits  @unit: [?/s] @min: 0  @max: +3.4E+38 */
typedef f32_t fVariance_t;

/*! @description: Rate of change of lateral force with respect to change in slip angle
@resolution: 7 digits  @unit: [N/rad] @min: 0  @max: +3.4E+38 */
typedef f32_t fCornerStiff_t;

/*! @description: Type definition for voltage
@resolution: tbd digits  @unit: [V] @min: tbd  @max: tbd */
typedef f32_t fVoltage_t;

/*! @description: type definition for uncertainty
@resolution: tbd digits  @unit: tbd @min: 0  @max: 1.0E+6 */
typedef f32_t fUncertainty_t;



/*************************************************************/
/* Karl - Heinz Reinbott: Integrated for development purpose */
/* basic data types */
typedef unsigned char  uc_t;
typedef signed char    sc_t;

/* definition of NULL value */
#ifndef NULL
#ifdef  __cplusplus
#define NULL           (0)
#else
#define NULL           ((void *)0)
#endif
#endif


/*************************************************************/
/* bit field structured types */

/*! @todo for each new project/compiler we have to check the allignment 
and packaging of bit fields in combination with structs and unions 
like in the types FourByte_t, TwoByte_t and OnByte_t 
If the allignment is o.k. we can violate MISRA Rule 110 */


/*lint -e960 Note 960: Violates MISRA Required Rule 110, bitfields inside union: untagged */
/*! Four Byte Bitfield (union)
Union to access each Bit, Byte, Word or the complete 32 Bit value.
FourByte_t t;
@sample:
t.LONG = 0xA0FF00FF;
t.WORD.H = 0xA0FF;
t.BYTE.MH =0xA0;
t.BIT.B20 = 1; 
*/  

typedef union
{
    f32_t  FLOAT;     /*!< Access to 4 byte float */
    ui32_t LONG;      /*!< Access to Byte 1+2+3+4 */
    struct
    {
        ui16_t H;    /*!< Access to Byte 3+4 */
        ui16_t L;    /*!< Access to Byte 1+2 */
    }WORD;
    struct
    {
        ui8_t   H;  /*!< Access to Byte 4 */
        ui8_t   MH; /*!< Access to Byte 3 */
        ui8_t   ML; /*!< Access to Byte 2 */
        ui8_t   L;  /*!< Access to Byte 1 */
    }BYTE;
    struct
    {
        ubit32_t B31  :1; /*!< Access to Bit 31 */
        ubit32_t B30  :1; /*!< Access to Bit 30 */
        ubit32_t B29  :1; /*!< Access to Bit 29 */
        ubit32_t B28  :1; /*!< Access to Bit 28 */
        ubit32_t B27  :1; /*!< Access to Bit 27 */
        ubit32_t B26  :1;
        ubit32_t B25  :1;
        ubit32_t B24  :1;
        ubit32_t B23  :1;
        ubit32_t B22  :1;
        ubit32_t B21  :1;
        ubit32_t B20  :1;
        ubit32_t B19  :1;
        ubit32_t B18  :1;
        ubit32_t B17  :1;
        ubit32_t B16  :1;
        ubit32_t B15  :1;
        ubit32_t B14  :1;
        ubit32_t B13  :1;
        ubit32_t B12  :1;
        ubit32_t B11  :1;
        ubit32_t B10  :1;
        ubit32_t B9   :1;
        ubit32_t B8   :1;
        ubit32_t B7   :1;
        ubit32_t B6   :1;
        ubit32_t B5   :1;
        ubit32_t B4   :1;
        ubit32_t B3   :1;
        ubit32_t B2   :1;
        ubit32_t B1   :1; /*!< Access to Bit 1 */
        ubit32_t B0   :1; /*!< Access to Bit 0 */
    }BIT; /*!< Access to Bit 1-31 */
}FourByte_t; 

typedef union 
{
    ui16_t  WORD;  /*!< Access to Byte 1+2 */
    struct 
    {
        ui8_t   H;  /*!< Access to the high byte */
        ui8_t   L;  /*!< Access to the low byte */
    }BYTE;
    struct
    {
        ubit16_t B15  :1; /*!< Access to Bit 15 */
        ubit16_t B14  :1; /*!< Access to Bit 14 */
        ubit16_t B13  :1; /*!< Access to Bit 13 */
        ubit16_t B12  :1;
        ubit16_t B11  :1;
        ubit16_t B10  :1;
        ubit16_t B9   :1;
        ubit16_t B8   :1;
        ubit16_t B7   :1;
        ubit16_t B6   :1;
        ubit16_t B5   :1;
        ubit16_t B4   :1;
        ubit16_t B3   :1;
        ubit16_t B2   :1;
        ubit16_t B1   :1; /*!< Access to Bit 1 */
        ubit16_t B0   :1; /*!< Access to Bit 0 */
    }BIT;  /*!< Access to Bit 0-15 */
}TwoByte_t; 

typedef union 
{
    ui8_t  BYTE;  /*!< Access to 8-Bits */
    struct
    {
        
        ubit8_t B7   :1;  /*!< Access to Bit 7 */
        ubit8_t B6   :1;  /*!< Access to Bit 6 */
        ubit8_t B5   :1;
        ubit8_t B4   :1;
        ubit8_t B3   :1;
        ubit8_t B2   :1;
        ubit8_t B1   :1;
        ubit8_t B0   :1;  /*!< Access to Bit 0 */
    }BIT;
}OneByte_t;



/* *************************************************************************************************** */
/* *************************************************************************************************** */
/* TEVES TYPES                      */
/* The use of the following types are limited to    */
/* software components which have to run on A.D.C.      */
/* MCU's and TEVES MCU's                                */
/* DO NOT USE (MIX) BOTH STYLES IN ONE COMPONENT        */
/*! TEVES STYLE: Limited to components which have to run on A.D.C. MCU's and TEVES MCU's */
/* *************************************************************************************************** */


/* TYPEDEFS (GLOBAL) */
typedef signed char         signed_char_t;
typedef unsigned char       unsigned_char_t;
typedef signed char           signed_int8_t;
typedef unsigned char       unsigned_int8_t;
typedef signed short int     signed_int16_t;
#define Signed_int16_min    -32767
#define Signed_int16_max    32766
typedef unsigned short int  unsigned_int16_t;
typedef signed             signed_int32_t;
#define Signed_int32_max    2147483647L
typedef unsigned 	       unsigned_int32_t;
typedef unsigned_int8_t     enum_t;


/* DATA DICTIONARY */
#define Scale_1000000 (1000000)
#define Scale_100000  (100000)
#define Scale_10000   (10000)
#define Scale_1000    (1000)
#define Scale_100     (100)
#define Scale_10      (10)
#define Scale_1       (1)

/*! Acceleration: Range -32,767 .. +32,766
@description: Acceleration, speed increase / left positive
@resolution: 0.001    @unit: [m/s²]
@min: -32767          @max: 32766 */
typedef signed_int16_t acceleration_t; /*%scale:0.001 unit:m/s2*/
#define Acceleration_s Scale_1000
#define Accel_min (-32767)
#define Accel_max ( 32766)

/*! Gradient:
@description: Change rate (d/dt) of signal. Attention, gradient is scaled same as signal it is derived from
@resolution: 0.001  @unit: [?/s]
@min: -2147483648     @max: +2147483647 */
typedef signed_int32_t gradient_t;     /*%scale:0.001 unit:x/s*/

/*! velocity: Range -327,67 .. +327,66
@description: velocity, forward / left positive
@resolution: 0.01     @unit: [m/s]
@min: -32767          @max: 32766 */
typedef signed_int16_t velocity_t;   /*%scale:0.01 unit:m/s*/
#define Velocity_s Scale_100
#define Velocity_min (-32767)
#define Velocity_max ( 32766)

/*! speed: Range -327,67 .. +327,66
@description: number of revolutions per time unit, forward / left positive
@resolution: 0.01     @unit: [1/s]
@min: -32767          @max: 32766 */
typedef signed_int16_t speed_t; /*%scale:0.01 unit:1/s*/
#define Speed_s Scale_100
#define Speed_min (-32767)
#define Speed_max ( 32766)

/*! SpeedometerSpeed: Range -327,67 .. +327,66
@description:  Vehicle speed displayed by speedometer
@resolution: 0.01     @unit: [Km/h | Mph]
@min: -32767          @max: 32766 */
typedef signed_int16_t speedometer_speed_t; /*%scale:0.01 unit:km/h|mph*/
#define Speedo_speed_s Scale_100
#define Speedo_speed_min (-32767)
#define Speedo_speed_max (32766)

/*! Factor: Range -32,767 .. +32,766
@description:  Factor
@resolution: 0.001    @unit: [-]
@min: -32767          @max: 32766 */
typedef signed_int16_t factor_t;    /*%scale:0.001*/
#define Factor_s Scale_1000

/*! Time: Range 0 .. +65,534
@description:  Time
@resolution: 0.001    @unit: [s]
@min: 0               @max: 65534 */
typedef unsigned_int16_t times_t;    /*%scale:0.001 unit:s*/
#define Time_s Scale_1000
#define Time_min (0u)
#define Time_max (65535u)

/*! SetSpeed: Range 0 .. 255
@description:  Driver selected speed
@resolution: 1        @unit: [Km/h | Mph]
@min: 0               @max: 255 */
typedef unsigned_int8_t setspeed_t;  /*%unit:km/h|mph*/
#define Setspeed_s Scale_1

/*! WheelImpulseCounter: Range 0 .. 255
@description:  Number of impulses from wheel speed sensor since last overflow
@resolution: 1        @unit: [-]
@min: 0               @max: 255 */
typedef unsigned_int8_t wheel_impulse_counter_t;
#define Wheel_impulse_s Scale_1

/*! Length:  Phys. Range 0 .. +65,534
@description:  Time
@resolution: 0.001    @unit: [m]
@min: 0               @max: 65534 */
typedef unsigned_int16_t length_t;  /*%scale:0.001 unit:m*/
#define Length_s Scale_1000

/*! Radius:  Phys. Range -32767 .. +32766
@description:  radius
@resolution: 1    @unit: [m]
@min: -32767          @max: +32766 */
typedef signed_int16_t curve_radius_t;  /*%unit:m*/
#define Curve_radius_s Scale_1

/*! Distance: Range -327,67 .. +327,66
@description:  Distance, left / forward positive
@resolution: 0.01     @unit: [m]
@min: -32767          @max: 32766 */
typedef signed_int16_t distance_t;    /*%scale:0.01 unit:m*/
#define Distance_s Scale_100
#define Distance_min (-32767)
#define Distance_max (32766)

/*! Torque: Range -32767 .. +32766
@description:  Torque
@resolution: 1        @unit: [Nm]
@min: -32767          @max: +32766 */
typedef signed_int16_t torque_t;       /*%unit:Nm*/
#define Torque_s Scale_1

/*! Ratio: Range 0 .. 655,35
@description:  Ratio, relation between two values
@resolution: 0.01     @unit: [-]
@min: 0               @max: 65534 */
typedef unsigned_int16_t ratio_t;         /*%scale:0.01*/
#define Ratio_s Scale_100

/*! Weight: Range 0 .. 6553,5
@description:  Weight
@resolution: 0.1      @unit: [Kg]
@min: 0               @max: 65534 */
typedef unsigned_int16_t weight_t;         /*%scale:0.1 unit:kg*/
#define Weight_s Scale_10
#define Weight_min (0)
#define Weight_max (65535)

/*! Energy:  Range -32767 .. +32766
@description:  Energy
@resolution: 1        @unit: [Nms]
@min: -32767          @max: +32766 */
typedef signed_int16_t energy_t;           /*%unit:Nms*/
#define Energy_s Scale_1

/*! Confidence:  Range 0 .. 100
@description:  Confidence
@resolution: 0.39        @unit: [%]
@min: 0          @max: 255 */
typedef unsigned_int8_t confidence_t;      /*%scale:0.392156862745 unit:%*/
#define Confidence_s   (255)
#define Confidence_min (0)
#define Confidence_max (255)

/*! Angle:  Range -10pi .. +10pi
@description:  Angle, positive counter clockwise / left
@resolution: 0.0001   @unit: [rad]
@min: -314160         @max: +314160 */ 
typedef signed_int32_t angle_t;            /*%scale:0.0001 unit:rad*/
#define Angle_s Scale_10000 
#define Angle_min (-314160)
#define Angle_max (314160)

/*! Curvature:  Range -0.32767 .. +0.32766
@description:  Curvature, positive counter clockwise / left
@resolution: 0.00001    @unit: [1/m]
@min: -32767          @max: +32766 */
typedef signed_int16_t curvature_t;       /*%scale:0.00001 unit:1/m*/
#define Curvature_s Scale_100000
#define Curvature_min (-32767)
#define Curvature_max (+32766)

/*! Quality:  Range 0 .. 100
@description:  Quality
@resolution: 1        @unit: [%]
@min: 0          @max: 100 */
typedef unsigned_int8_t quality_t;        /*%unit:%*/
#define Qual_s Scale_1
#define Qual_min (0)
#define Qual_max (100)

/*! Percentage:  Range 0 .. 100
@description:  Percentage
@resolution: 1        @unit: [%]
@min: 0          @max: 100 */
typedef unsigned_int8_t percentage_t;     /*%unit:%*/
#define Percentage_s Scale_1
#define Percentage_min (0)
#define Percentage_max (100)

/*! Forward looking sensor speed reference interface sizes */
#define REF_SPEED_MIN_RATIO        0.6F         /*< Minimum ratio of target velocity to uncorrected ego velocity */
#define REF_SPEED_MAX_RATIO        1.4F         /*< Maximum ratio of target velocity to uncorrected ego velocity */
#define REF_SPEED_NO_BINS          81uL         /*< Number of bins containing occurrences of sampled ratios   */

/*! Velocity of assumed stationary targets of forward looking sensor */
typedef struct {
  ui8_t       binVelRatio[REF_SPEED_NO_BINS];   /*!< Occurrences of velocity ratios within bounds */
  ui8_t       binVelRatOutLo;                   /*!< Occurrences of velocity ratios below lower bound */
  ui8_t       binVelRatOutHi;                   /*!< Occurrences of velocity ratios above higher bound */
  ui8_t       cntSample;                        /*!< Sample counter to recognize updated data */
  fVelocity_t refEgoVelo;                       /*!< Referenced, uncorrected ego velocity     */
} RefSpeed_t; 
#define BinVelRatio_s Scale_1
#define BinVelRatio_min (0)
#define BinVelRatio_max (255)
#define CntSample_s Scale_1
#define CntSample_min (0)
#define CntSample_max (255)
#define RefEgoVelo_s Scale_1
#define RefEgoVelo_min (0)
#define RefEgoVelo_max (128)

/* ************************************************************************************** */
/*     END OF TEVES TYPES                                                                 */
/* ************************************************************************************** */

/* *************************************************************************************************** */
/* *************************************************************************************************** */
/* TEMIC-HYBRID TYPES                                                                                  */
/* The use of the following types are limited to                                                       */
/* software components which have to run on A.D.C.                                                     */
/* MCU's and TEMIC Electric Drive (Hybrid-Berlin) MCU's                                                */
/* DO NOT USE (MIX) BOTH STYLES IN ONE COMPONENT                                                       */
/*! TEMIC-HYBRID STYLE: Limited to components which have to run on A.D.C. MCU's and TEMIC-HYBRID MCU's */
/* *************************************************************************************************** */

typedef signed char T_S8 ;
typedef unsigned char T_U8 ;
typedef signed short T_S16 ;
typedef unsigned short  T_U16 ;
typedef signed int T_S32 ;
typedef unsigned int T_U32 ;

/* Removed BOOL type as conflicts with standard windows-types */

/* ************************************************************************************** */
/*     END OF TEMIC-HYBRID TYPES                                                                 */
/* ************************************************************************************** */


/*************************************************************/
/* pointer types */

/*! Pointer to byte */
typedef ui8_t * pui8_t;
/*! Pointer to unsigned 16 bit value */
typedef ui16_t * pui16_t;
/*! Pointer to unsigned 32 bit value */
typedef ui32_t * pui32_t;



/* ************************************************************************************** */
/* inlcude of project specific global type definitions */
#include "glob_type_project.h"


#endif

/** @} */
