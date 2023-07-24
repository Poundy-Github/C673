/*-------------------------------------------------------------------------
 |
 |  File Name   :  $Source: algo_memsec.h $
 |
 | ------------------------------------------------------------------------
 |
 |  COPYRIGHT (C) Continental Automotive AG 2008
 |  ALLE RECHTE VORBEHALTEN. ALL RIGHTS RESERVED.
 |
 |   The  reproduction,  transmission or  use  of  this  document or  its
 |   contents  is  not   permitted  without  express  written  authority.
 |   Offenders will  be liable for damages. All  rights, including rights
 |   created  by patent  grant  or  registration of  a  utility model  or
 |   design, are reserved.
 |
 | ------------------------------------------------------------------------
 |
 |  Description : Macro collection for placing variables and constants
 |                into a specific memory section.
 |
 |                First of all define the macro for the section names
 |                of this algorithm module:
 |                MEMSEC_VAR "your_section_name_for_vars"
 |                MEMSEC_CONST "your_section_name_for_consts"
 |
 |
 |                Now you can instrument your code !!!directly!!!
 |                in front of !!!each!!! global (or static) memory
 |                object instantiation (no semicolon):
 |
 |                SET_MEMSEC_VAR_A(v)   Place variable v 128byte
 |                                      aligned in variables section
 |                                      ("your_section_name_for_vars")
 |
 |                                   => Use this aligned version for
 |                                      large arrays of structs
 |                                      or classes (>>32kByte)
 |
 |
 |                SET_MEMSEC_VAR(v)     Place variable v in variables
 |                                      section ("your_section_name_for_vars")
 |                                      (non aligned)
 |
 |                SET_MEMSEC_CONST_A(v) Place constant v 128byte
 |                                      aligned in constants section
 |                                      ("your_section_name_for_consts")
 |
 |                                   => Use this aligned version for large
 |                                      arrays of structs or classes (>>32kByte)
 |
 |
 |                SET_MEMSEC_CONST(v)   Place constant v in
 |                                      constants section
 |                                      ("your_section_name_for_consts")
 |                                      (non aligned)
 |
 |
 |  Developer  :  Ulrich Wagner
 |
 |  Last Revision     $Revision: 1.1 $
 |  Last Author       $Author: Wang, David (Wangd3) $
 |  Check in Date     $Modtime:   01.07.2011  $
 |              
 +-------------------------------------------------------------------------*/





#ifndef _ALGO_MEMSEC_H_
#define _ALGO_MEMSEC_H_

#ifdef TARGET_GOLDDUST

/* Begin: Definition of macros, used to define the memory sections of variables */

#define PRAGMA(x)         _Pragma (#x)

#define DATA_SECTION(v, x)  PRAGMA(section data_type x x) \
                          __attribute__((section(x))) v

#define CONST_SECTION(v, x) PRAGMA(section const_type x x) \
                          __attribute__((section(x))) v

#define DATA_ALIGN(x)     __attribute__((aligned(x)))




#ifdef __cplusplus
#define SET_MEMSEC_VAR_A(v) PRAGMA(DATA_ALIGN(128)) \
                            PRAGMA(DATA_SECTION(MEMSEC_VAR))
#else
#define SET_MEMSEC_VAR_A(v) PRAGMA(push) \
                            DATA_SECTION(v, MEMSEC_VAR) \
                            DATA_ALIGN(32); \
                            PRAGMA(pop)
#endif

#ifdef __cplusplus
#define SET_MEMSEC_VAR(v)   PRAGMA(DATA_SECTION(MEMSEC_VAR))
#else
#define SET_MEMSEC_VAR(v)   PRAGMA(push) \
                            DATA_SECTION(v, MEMSEC_VAR); \
                            PRAGMA(pop)
#endif

#ifdef __cplusplus
#define SET_MEMSEC_CONST_A(v) PRAGMA(DATA_ALIGN(128)) \
                              PRAGMA(DATA_SECTION(MEMSEC_CONST))
#else
#define SET_MEMSEC_CONST_A(v) PRAGMA(push) \
                              CONST_SECTION(v, MEMSEC_CONST) \
                              DATA_ALIGN(32); \
                              PRAGMA(pop)
#endif

#ifdef __cplusplus
#define SET_MEMSEC_CONST(v)   PRAGMA(DATA_SECTION(MEMSEC_CONST))
#else
#define SET_MEMSEC_CONST(v)   PRAGMA(push) \
                              CONST_SECTION(v, MEMSEC_CONST); \
                              PRAGMA(pop)
#endif
/* End: Definition of macros, used to define the memory sections of variables */

#else /* <= TARGET_DSP, PC => */

/* Empty macros for PC: */
#define SET_MEMSEC_VAR_A(v) 
#define SET_MEMSEC_VAR(v) 
#define SET_MEMSEC_CONST_A(v) 
#define SET_MEMSEC_CONST(v) 

#endif /* #ifdef TARGET_DSP */


#endif //#ifndef _ALGO_MEMSEC_H_

