     


#ifndef cml_type_H
#define cml_type_H
#define glob_type_H              ///< To prevent inclusion of glob_type to avoid multiple definition

/*## package Types_Pkg */

/*## class TopLevel::glob_type */
/*#[ ignore */
//Description:        Global type definitions for all C types
//Integration notes:  The types defined here are always to be used instead of standard ANSI C types
//Package prefix:     -
/*#]*/

#ifdef __cplusplus
extern "C"
{
#endif

//**************************************************************************
//Type: boolean
//Description: Predefined void
//Range:       (0...1)
//Resolution:  1
//Unit:        none
/*## type boolean */
typedef unsigned char boolean;

//**************************************************************************
//Type: sint8
//Description: signed byte
//Range:       (-128...127)
//Resolution:  1
//Unit:        none
/*#[ type sint8 */
typedef signed char sint8;
/*#]*/

//**************************************************************************
//Type: uint8
//Description: unsigned byte
//Range:       (0...255)
//Resolution:  1
//Unit:        none
/*## type uint8 */
typedef unsigned char uint8;

//**************************************************************************
//Type: sint16
//Description: signed short integer
//Range:       (-32768...32767)
//Resolution:  1
//Unit:        none
/*#[ type sint16 */
typedef signed short sint16;
/*#]*/

//**************************************************************************
//Type: uint16
//Description: unsigned short integer
//Range:       (0...65535)
//Resolution:  1
//Unit:        none
/*## type uint16 */
typedef unsigned short uint16;

//**************************************************************************
//Type: sint32
//Description: signed long integer
//Range:       (-2147483648...2147483647)
//Resolution:  1
//Unit:        none
/*#[ type sint32 */
typedef signed int sint32;
/*#]*/

//**************************************************************************
//Type: uint32
//Description: unsigned long integer
//Range:       (0...4294967295)
//Resolution:  1
//Unit:        none
/*## type uint32 */
typedef unsigned int uint32;

//**************************************************************************
//Type: float32
//Description: 32-bit IEEE 754 floating point number
//Range:       -
//Resolution:  -
//Unit:        none
/*## type float32 */
typedef float float32;

//**************************************************************************
//Type: float64
//Description: 64-bit IEEE 754 floating point number
//Range:       -
//Resolution:  -
//Unit:        none
/*#[ type float64 */
#if (defined(_TMS320C6X) || defined(__TMS470__) || defined(_MSC_VER))
typedef double float64;
#endif
/*#]*/

//**************************************************************************
//Type: ubit8
//typedef uint8 %s
/*## type ubit8 */
typedef uint8 ubit8;

//**************************************************************************
//Type: psint8
//Description: Pointer to a signed 8-bit integer
//Range:       -
//Resolution:  -
//Unit:        none
/*## type psint8 */
typedef sint8* psint8;

//**************************************************************************
//Type: puint8
//Description: Pointer to an unsigned 8-bit integer
//Range:       -
//Resolution:  -
//Unit:        none
/*## type puint8 */
typedef uint8* puint8;

//**************************************************************************
//Type: psint16
//Description: Pointer to a signed 16-bit integer
//Range:       -
//Resolution:  -
//Unit:        none
/*## type psint16 */
typedef sint16* psint16;

//**************************************************************************
//Type: puint16
//Description: Pointer to an unsigned 16-bit integer
//Range:       -
//Resolution:  -
//Unit:        none
/*## type puint16 */
typedef uint16* puint16;

//**************************************************************************
//Type: psint32
//Description: Pointer to a signed 32-bit integer
//Range:       -
//Resolution:  -
//Unit:        none
/*## type psint32 */
typedef sint32* psint32;

//**************************************************************************
//Type: puint32
//Description: Pointer to an unsigned 32-bit integer
//Range:       -
//Resolution:  -
//Unit:        none
/*## type puint32 */
typedef uint32* puint32;

//**************************************************************************
//Type: pvoid
//Description: A void pointer
//Range:       -
//Resolution:  -
//Unit:        none
/*## type pvoid */
typedef void* pvoid;

//**************************************************************************
//Type: sint64
//Description: signed long integer
//Range:       (-2147483648...2147483647)
//Resolution:  1
//Unit:        none
/*#[ type sint64 */
typedef signed long long sint64;
/*#]*/

// CML typedefs

//**************************************************************************
//Type: uint64
//Description: unsigned long integer
//Range:       (0...4294967295)
//Resolution:  1
//Unit:        none
/*#[ type uint64 */
typedef unsigned long long uint64;
/*#]*/
typedef unsigned char percentage_t              /* percentage @min:0 @max:100 @resolution:1.0 */	/* [Satisfies_rte sws 1188] */;
typedef float fVelocity_t               /* Translatory velocity, time-derivative of distance with sign, forward direction positive, reverse direction negative @min:-100 @max:100 */	/* [Satisfies_rte sws 1188] */;
typedef float fYawRate_t                /* Measure of yaw rate, counterclockwise direction: positive, clockwise direction: negative. Reference is x-axis if not stated otherwise */	/* [Satisfies_rte sws 1188] */;
typedef float fVariance_t               /* The variance of a value @min:-100000 @max:100000 */	/* [Satisfies_rte sws 1188] */;
typedef float fDistance_t               /* Straight stretch between points or objects @min:-500 @max:500 */	/* [Satisfies_rte sws 1188] */;
typedef float fAngle_t                  /* Measure of rotation, counterclockwise direction: positive, clockwise direction: negative. Reference is x-axis if not stated otherwise */	/* [Satisfies_rte sws 1188] */;
typedef float fTime_t                   /* Period of time @min:0 @max:3.4e+038 */	/* [Satisfies_rte sws 1188] */;
typedef float fAccel_t                  /* Translatory acceleration, time-derivative of translatory velocity with sign @min:-18 @max:18 */	/* [Satisfies_rte sws 1188] */;

///< \brief       The Complex number polar coordinates Structure
///< \description The structure contains the amplitude and phase of value , 
///<              represented in polar coordinate system
typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float f_Amplitude;      ///< Amplitude of the value
 	float f_Phase;          ///< Phase of the value
 } t_ComplexPolarf32;			/* complex float in polar coordinates */

///< \brief       The Complex number cartesian coordinates Structure
///< \description The structure contains the real and imaginary parts of value , 
///<              represented in cartesian coordinate system
typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float f_Real;          ///< Real part of the value
 	float f_Imag;          ///< Imaginary part of the value
 } t_Complexf32;			/* complex float in cartesian coordinates */
 

///< \brief       The 16-bit integer Vector Structure
///< \description The structure contains the x and y distances of a vector , 
///<              represented as 16bit integers
 typedef struct 			/* [Satisfies_rte sws 1191] */
{
	signed short nXDist;   ///< x distance of the vector
 	signed short nYDist;   ///< y distance of the vector
 } Vector2_i16_t;			/* Vector with x and y with i16 values */
 
///< \brief       The 32-bit float Vector Structure
///< \description The structure contains the x and y distances of a vector , 
///<              represented as 32bit float values
 typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float fXDist;   ///< x distance of the vector
 	float fYDist;   ///< y distance of the vector
 } Vector2_f32_t;			/* Vector with x and y with f32 values */
 
///< \brief       The 32-bit integer Vector Structure
///< \description The structure contains the x and y distances of a vector , 
///<              represented as 32bit integers
 typedef struct 			/* [Satisfies_rte sws 1191] */
{
	signed long nXDist;   ///< x distance of the vector
 	signed long nYDist;   ///< y distance of the vector
 } Vector2_i32_t;			/* Vector with x and y with i32 values */
 

//**************************************************************************
//Type: ubit32
//typedef uint32 %s
//
/*## type ubit32 */
typedef uint32 ubit32;

//**************************************************************************
//Type: NULL
//- Description:	short description, meaning, usage
//- Range:		range of variable (Min - Max) based on raw value
//- Resolution:	resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:		physical unit (e.g. m/s^2)
//
/*#[ type NULL */
#ifndef NULL
  #ifdef __cplusplus
    #define NULL (0)           ///< Representation of 'NULL' value
  #else
    #define NULL ((void *)0)            ///< Representation of 'NULL' value
  #endif
#endif
/*#]*/

//**************************************************************************
//b_FALSE: boolean
//Description: Boolean constant false (FALSE = boolean 0)
//Range:       constant (boolean)0
//Resolution:  1
//Unit:        none
/*## attribute b_FALSE */
#ifndef b_FALSE
#define b_FALSE ((boolean)0)     ///< Boolean value to represent FALSE.
#endif

//**************************************************************************
//FALSE: boolean
//Description: Legacy - use b_FALSE wherever possible.
//Range:       constant (boolean)0
//Resolution:  1
//Unit:        none
/*## attribute FALSE */
#ifndef FALSE
#define FALSE b_FALSE     ///< Boolean value to represent FALSE. use b_FALSE wherever possible.
#endif

//**************************************************************************
//b_TRUE: boolean
//Description: Boolean constant true (TRUE = boolean 1)
//Range:       constant (boolean)1
//Resolution:  1
//Unit:        none
/*## attribute b_TRUE */
#ifndef b_TRUE
#define b_TRUE ((boolean)1)     ///< Boolean value to represent TRUE.
#endif

//**************************************************************************
//TRUE: boolean
//Description: Legacy - use b_TRUE wherever possible
//Range:       constant (boolean)1
//Resolution:  1
//Unit:        none
/*## attribute TRUE */
#ifndef TRUE
#define TRUE b_TRUE     ///< Boolean value to represent TRUE. use b_TRUE wherever possible.
#endif


/***    User explicit entries    ***/


#ifdef __cplusplus
}
#endif

/*## package Types_Pkg */

/*## class TopLevel::glob_type */

#endif
/*********************************************************************
	File Path	: ..\..\..\04_Engineering\01_Source_Code\_gensrc\rhapsody\glob_type.h
*********************************************************************/
