/*~-*/
/*~XSF_LANGUAGE: C/C++*/
/*~I*/
#ifndef GTYPES_H
/*~T*/
#define GTYPES_H 0x10000000
/*~A*/
/*~+:Module Header*/
/*~T*/
/****************************************************************************
 *   COPYRIGHT (C) SIEMENS  VDO AUTOMOTIVE AG 2006                           
 *   AUTOMOTIVE ELECTRONICS                                                  
 *   ALLE RECHTE VORBEHALTEN. ALL RIGHTS RESERVED.                           
 *                                                                           
 *   The reproduction, transmission or use of this document or its           
 *   contents is not permitted without express written authority.            
 *   Offenders will be liable for damages. All rights, including rights      
 *   created by patent grant or registration of a utility model or design,   
 *   are reserved.                                                           
 *---------------------------------------------------------------------------
 *   Purpose:   GTYPES header file for TC17XX                                
 *   Processor: TC17XX
 *   Project:   32 bit Generic IO
 *   Compiler:  CTC
 *   Filename:  $Workfile:   gtypes.h  $
 *   Revision:  $Revision: 1.7 $
 *   Author:    $Author: Nastasa, Elena (uidt4846) $
 *   Date:      $Date: 2019/07/03 13:45:22CEST $
 *   Changes:
 *      $Log: gtypes.h  $
 *      Revision 1.7 2019/07/03 13:45:22CEST Nastasa, Elena (uidt4846) 
 *      Update SDA Library files
 *      Revision 1.6 2017/02/01 12:47:11CET Ammermueller Martin (uidv5342) (uidv5342) 
 *      Adapted Nissan map handling - ACG SIL
 *      Revision 1.5 2013/07/11 11:07:26CEST Garrelfs Ralf-Ingo (uidg0598) (uidg0598) 
 *      RO-268201-24:Add floating point ranges from float.h
 *      Revision 1.2 2012/06/09 09:59:21CEST Nitzsche Tilo (uid03085) (uid03085) 
 *      Initial revision
 *      Member added to project /ES/1T/0C/SDA/SDA_Source/SDA_Toolboxes/ACG/Libraries/generic_includes/project.pj
 * 
 *    Rev 1.2   28 Apr 2011 15:56:40   uid15893
 * T44-1252 MaKr: Avoid compiler warnings for S-Function-Wrapper
 * 
 *    Rev 1.1   21 Oct 2010 13:50:56   uid15893
 * T44-RCN-180 MaKr: Add typedefs for EMS3
 * 
 *    Rev 1.0   Feb 01 2010 09:38:14   uid15893
 * Initial revision.
 * 
 *    Rev 1.0   May 05 2009 16:54:46   uidg0598
 * Initial revision.
 * 
 *    Rev 1.7   Jun 05 2006 07:01:42   uide5316
 * 1AR SIF 30 ,1AR SCN 38, 1AR SCN 39 (after spec change)
 * 
 *    Rev 1.6   Jun 02 2006 07:56:22   uide5316
 * 1AR SIF 30 ,1AR SCN 38, 1AR SCN 39 (after review)
 * 
 *    Rev 1.5   May 31 2006 09:29:22   uide5316
 *  1AR SIF 30 ,1AR SCN 38, 1AR SCN 39 (after test)
 * 
 *    Rev 1.4   May 31 2006 08:58:08   uide5316
 * 1AR SIF 30 :Gtypes_dds.grl with attribute'logical builtin'
 * 1AR SCN 38:MAKE_VOLATILE
 * 1AR SCN 39: Datatypes for reset-safe-data management
 * 
 *    Rev 1.3   Sep 17 2004 17:12:26   uid03156
 * 1L2 SAR 045: GTYPES: S8_MIN definition not correct
 * 
 *    Rev 1.2   May 14 2004 14:44:38   uid03156
 * 1L2 SIF 022: GTYPES: reworking (after review)
 * 
 *    Rev 1.1   May 14 2004 09:03:54   uid03156
 * 1L2 SIF 022: GTYPES: reworking
 * 
 *    Rev 1.0   Feb 04 2004 15:15:28   uid07812
 * Initial revision.
 * 
 *    Rev 1.3   Oct 17 2003 16:04:26   uid03156
 * change typedef for    flag    from    __bit    to    unsigned char
 * 
 *    Rev 1.2   Oct 02 2003 15:03:28   uid05759
 * (Included gprc.h)
 * 
 *    Rev 1.1   Aug 29 2003 16:07:14   uid05518
 * Integration of CTC-Compiler
 * 
 *    Rev 1.0   Aug 26 2003 16:21:56   uid05759
 * Initial revision.
 * 
 *****************************************************************************/
/*~E*/
/*~A*/
/*~+:Includes*/
/*~T*/

/*~E*/
/*~A*/
/*~+:Typedefinitions*/
/*~T*/
/* Definition of Data Types */
/*~T*/
/* Boolean Data Type */
typedef unsigned char      flag;
/*~T*/

/* Fix-point data types */
//EMS3
/***ElNa: Removed by hand. Already declared in ADAS headers***/
/*
typedef unsigned char      uint8;
typedef signed char        sint8;
typedef unsigned short     uint16;
typedef signed short       sint16;
typedef unsigned long      uint32;
typedef signed long        sint32;
typedef unsigned long long uint64;
typedef signed long long   sint64;
typedef float              float32;
typedef unsigned char      boolean;
*/


/* Fix-point data types */
//EMS2
typedef unsigned char      u8;
typedef signed char        s8;
typedef unsigned short     u16;
typedef signed short       s16;
typedef unsigned long      u32;
typedef signed long        s32;
typedef unsigned long long u64;
typedef signed long long   s64;
/*~T*/
/* Optimized fix-point data types */
typedef unsigned int       u8_least;
typedef signed int         s8_least;
typedef unsigned int       u16_least;
typedef signed int         s16_least;
typedef unsigned int       u32_least;
typedef signed int         s32_least;
/*~T*/
 /* Floating-point data types */
typedef float              f32;
/*~T*/
/* Reset-safe variables */
/*~T*/
/* Reset-safe variables - Flag */
typedef u8 RST_SAFE_FlagPatternU8;
typedef u16 RST_SAFE_FlagPatternU16;
typedef u32 RST_SAFE_FlagPatternU32;
/*~T*/
/* Reset-safe variables - Duplicated variables */
typedef struct {
                 u8 value;
                 u8 value_cpl;
               } RST_SAFE_CplU8;
typedef struct {
                 s8 value;
                 s8 value_cpl;
               } RST_SAFE_CplS8;
typedef struct {
                 u16 value;
                 u16 value_cpl;
               } RST_SAFE_CplU16;
typedef struct {
                 s16 value;
                 s16 value_cpl;
               } RST_SAFE_CplS16;
typedef struct {
                 u32 value;
                 u32 value_cpl;
               } RST_SAFE_CplU32;
typedef struct {
                 s32 value;
                 s32 value_cpl;
               } RST_SAFE_CplS32;
/*~T*/
/* Reset-safe variables - Triplicated variables */
typedef struct {
                 u8 value;
                 u8 value_tri2;
                 u8 value_tri3;
               } RST_SAFE_TriU8;
typedef struct {
                 s8 value;
                 s8 value_tri2;
                 s8 value_tri3;
               } RST_SAFE_TriS8;
typedef struct {
                 u16 value;
                 u16 value_tri2;
                 u16 value_tri3;
               } RST_SAFE_TriU16;
typedef struct {
                 s16 value;
                 s16 value_tri2;
                 s16 value_tri3;
               } RST_SAFE_TriS16;
typedef struct {
                 u32 value;
                 u32 value_tri2;
                 u32 value_tri3;
               } RST_SAFE_TriU32;
typedef struct {
                 s32 value;
                 s32 value_tri2;
                 s32 value_tri3;
               } RST_SAFE_TriS32;
/*~T*/
/* Definition of Macros */
/*~T*/
/* Macros for Boolean Data Type flag */
//#ifndef FALSE
//#define FALSE ((flag) 0)
//#endif

//#ifndef TRUE
//#define TRUE  ((flag) 1)
//#endif
/*~T*/
/* Fix-point data types */
//#define U8_MIN ((u8) 0U)
//#define U8_MAX ((u8) 0xFFU)                  /* 255                   */

//#define S8_MIN ((s8) 0x80)                   /* -128                  */
//#define S8_MAX ((s8) 0x7F)                   /* 127                   */

//#define U16_MIN ((u16) 0U)
//#define U16_MAX ((u16) 0xFFFFU)              /* 65535                 */

//#define S16_MIN ((s16)  0x8000)              /* -32768                */
//#define S16_MAX ((s16)  0x7FFF)              /*  32767                */

//#define U32_MIN ((u32) 0UL)
//#define U32_MAX ((u32) 0xFFFFFFFFUL)          /* 4294967295            */

//#define S32_MIN ((s32) 0x80000000L)           /* -2147483648           */
//#define S32_MAX ((s32) 0x7FFFFFFFL)           /*  2147483647           */

//#define U64_MIN ((u64) 0ULL)
//#define U64_MAX ((u64) 0xFFFFFFFFFFFFFFFFULL) /* 18446744073709551615  */

//#define S64_MIN ((s64) 0x8000000000000000LL)  /* -9223372036854775808  */
//#define S64_MAX ((s64) 0x7FFFFFFFFFFFFFFFLL)  /*  9223372036854775807  */
/*~T*/

/* from float.h */
//#define F32_EPSILON     1.192092896e-07F        /* smallest such that 1.0+FLT_EPSILON != 1.0 */
//#define F32_MIN         1.175494351e-38F        /* min positive value */
//#define F32_MAX         3.402823466e+38F        /* max value */
/* Floating-point data types */
//#define F32_EPSILON     ((f32) 1.19209290E-07F)
//#define F32_MIN         ((f32) 1.17549435E-38F)
//#define F32_MAX         ((f32) 3.40282347E+38F)
/*~T*/
/* NULL Pointer */
//undef to avoid warnings
//#ifdef NULL
//	#undef NULL
//#endif
//#define NULL ((void *) 0)
/*~T*/
/* Make Volatile */
//#define MAKE_VOLATILE(type, var) (*(volatile type *) (&(var)))
/*~T*/
/* Controller information */
/*~T*/
/* CPU_TYPE       */
//#define  CPU_TYPE_8       8  /* 8 bit controller  */
//#define  CPU_TYPE_16      16 /* 16 bit controller */
//#define  CPU_TYPE_32      32 /* 32 bit controller */
/* CPU_BIT_ORDER  */
//#define  MSB_FIRST        0  /* MSB Bit first     */
//#define  LSB_FIRST        1  /* LSB Bit first     */
/* CPU_BYTE_ORDER */
//#define  HIGH_BYTE_FIRST  0  /* HIGH Byte first   */
//#define  LOW_BYTE_FIRST   1  /* LOW  Byte first   */
/* CPU_WORD_ORDER */
//#define  HIGH_WORD_FIRST  0  /* HIGH word first   */
//#define  LOW_WORD_FIRST   1  /* LOW  word first   */
/*~T*/
//#define CPU_TYPE         CPU_TYPE_32
//#define CPU_BIT_ORDER    LSB_FIRST
//#define CPU_BYTE_ORDER   LOW_BYTE_FIRST
//#define CPU_WORD_ORDER   LOW_WORD_FIRST


/*~E*/
/*~-*/
#endif
/*~E*/
