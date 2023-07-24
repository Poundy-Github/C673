#ifndef	P_TRAJ_PLAN_MATH_DEFS_H
#define	P_TRAJ_PLAN_MATH_DEFS_H

typedef float float32;
typedef unsigned char uint8;     

#ifdef MATH_LOCAL_SFUNCTION
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif

#ifndef true
# define true    TRUE
#endif
#ifndef false
# define false   FALSE
#endif

#include <math.h> //fix to make it work without the BMW math headers
#include "cml_ext.h"
#ifndef Boolean
#define 	Boolean     boolean_T
#endif
#ifndef 	sinf
#define 	sinf(x)   ((float)sin(x))
#endif
#ifndef cosf
#define 	cosf(x)   ((float)cos(x))
#endif

#ifndef cosftest
#define   cosftest(x)  ((float)cosf(x))
#endif

#ifndef tanf
#define 	tanf(x)   ((float)tan(x))
#endif
#ifndef powf
#define 	powf(x, y)   ((float)pow(x, y))
#endif
#ifndef fabsf
#define 	fabsf(x)   ((float)fabs(x))
#endif
#ifndef sqrtf
#define 	sqrtf(x)   ((float)sqrt(x))
#endif
#ifndef fmodf
#define     fmodf(x,y)  ((float)fmod(x,y))
#endif
#ifndef atanf
#define     atanf(x)   ((float)atan(x))
#endif
#ifndef ceilf
#define     ceilf(x)    ((uint8)ceil(x)) 
#endif

// !!!!!!!!!!!! IN MFC5J3 project, comment it !!!!!!!!!!!!
// #ifndef floorf
// #define     floorf(x)    ((uint8)floor(x))
// #endif
#ifndef FD_ASIN
#define 	FD_ASIN( x) 	ASIN_(x)           /*asin(    x) */
#endif
#ifndef FD_ATAN
#define 	FD_ATAN( x)     ATAN_(x)           /*atan(    x)*/
#endif
#ifndef FD_ATAN2
#define 	FD_ATAN2(x,y)  	ATAN2_(   x,y)     /*atan2(   x,y)*/
#endif
#ifndef FD_COS
#define 	FD_COS(  x)    	CML_cos66(x)            /*cos(     x)*/
#endif
#ifndef FD_FABS
#define 	FD_FABS( x)    	fABS(    x)  
#endif
#ifndef FD_FLOOR
#define 	FD_FLOOR(x)    	CML_f_Floor(x)             /*floor(   x)*/ 
#endif
#ifndef FD_POW
#define 	FD_POW(  x,y)  	CML_f_XPowY(     x,y)              /*pow(     x,y)*/
#endif
#ifndef FD_SIN
#define 	FD_SIN(  x)    	CML_f_sin66(x)            /*sin(     x)*/
#endif
#ifndef FD_SQRT 
#define 	FD_SQRT( x)    	CML_f_Sqrt(    x)         /* sqrt(    x) */
#endif
#ifndef FD_TAN
#define 	FD_TAN(  x)    	CML_f_tan52(x)          /*	tan(     x)*/
#endif
#ifndef FD_EXP
#define 	FD_EXP(  x)    	CML_f_exp(     x)
#endif
#ifndef FD_CEIL
#define 	FD_CEIL( x)    	CML_f_Ceil(    x)       /* ceil(    x) */
#endif


#endif
