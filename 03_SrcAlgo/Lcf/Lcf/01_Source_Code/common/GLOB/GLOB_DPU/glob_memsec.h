/*-------------------------------------------------------------------------
 |
 |  File Name   :  $Source: glob_memsec.h $
 |
 | ------------------------------------------------------------------------
 |
 |  COPYRIGHT (C) Continental Automotive AG 2014
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
 |                SET_STRUCT_A(v)        Force the alignement of a structure v to 128byte.
 |                                       Usage example: struct S { short f[16]; } SET_STRUCT_A(S);
 |                                       for GCC expands to:
 |                                       struct S { short f[16]; } __attribute__ ((aligned (128))) S;
 |                                       for TI expands to:
 |                                       struct S { short f[16]; } S;
 |                                       _Pragma("STRUCT_ALIGN( S , 128 )")
 |                                       for PC expands to:
 |                                       struct S { short f[16]; } S;
 |
 |                MEMSEC_REF             Adds the "far" attribute to a DSP variable
 |                                       which has been declared in specific memory section.
 |                                       The far attribute is needed because far access must
 |                                       be used in order to guarantee that the correct assembly
 |                                       code is produced to access a variable placed in a
 |                                       generic position in memory (and because the near
 |                                       memory model is by now used by the DSP C compiler)
 |                                       Usage example:  extern MEMSEC_REF uint32 my_var;
 |
 |  Developer  :  Ulrich Wagner
 |
 |  Last Revision     $Revision: 1.3 $
 |  Last Author       $Author: Mueller, Ulrich02 (uidw1725) $
 |  Check in Date     $Modtime:   01.07.2011  $
 |              
 +-------------------------------------------------------------------------*/

#ifndef GLOB_MEMSEC_H
#define GLOB_MEMSEC_H

#define MEMSEC_VAR ".data_secure_section_var"
#define MEMSEC_CONST ".const_secure_section_const"
#define ALIGN_BYTES 128


#if defined (PRQA_SIZE_T) /* <= QAC needs empty macros in order to work => */
/* Empty macros for QAC: */
#define SET_MEMSEC_VAR_A(v)
#define SET_MEMSEC_VAR(v)
#define SET_MEMSEC_CONST_A(v)
#define SET_MEMSEC_CONST(v)
#define SET_STRUCT_A(v) v
#define MEMSEC_REF
/* End: Definition of macros, used to align variables, constants, array in memory */

/* Begin: Definition of macros, used to define the memory sections of variables */
#elif defined(TARGET_GOLDDUST) /* <= TARGET_ARM_GOLDDUST, GNU => */
#define PRAGMA(x)         _Pragma (#x)

#define DATA_SECTION(v, x)  PRAGMA(section data_type x x) \
                          __attribute__((section(x))) v

#define CONST_SECTION(v, x) PRAGMA(section const_type x x) \
                          __attribute__((section(x))) v

#define DATA_ALIGN(x)     __attribute__((aligned(x)))


#ifdef __cplusplus
#define SET_MEMSEC_VAR_A(v) PRAGMA(DATA_ALIGN(ALIGN_BYTES)) \
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
#define SET_MEMSEC_CONST_A(v) PRAGMA(DATA_ALIGN(ALIGN_BYTES)) \
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
/* End: Definition of macros, used to align variables, constants, array in memory */

/* Begin: Definition of macros, used to align variables, constants, array in memory */
#elif defined(__TI_COMPILER_VERSION__) /* <= TI, PC => */
/* Begin: Definition of macros, used to align variables, constants, array in memory */
#define PRAGMA(x) _Pragma(#x)
#ifdef __cplusplus
#define ALIGN2CACHE(v) PRAGMA(DATA_ALIGN(ALIGN_BYTES))
#else
#define ALIGN2CACHE(v) PRAGMA(DATA_ALIGN(v, ALIGN_BYTES))
#endif
#define ALIGNSTRUCT2CACHE(v) PRAGMA(STRUCT_ALIGN(v, ALIGN_BYTES))
/* End: Definition of macros, used to align variables, constants, array in memory */


/* Begin: Definition of macros, used to define the memory sections and the cache alignement of variables */
#ifdef __cplusplus
#define SET_MEMSEC_VAR_A(v) ALIGN2CACHE(v) \
                            PRAGMA(DATA_SECTION(MEMSEC_VAR))
#else
#define SET_MEMSEC_VAR_A(v) ALIGN2CACHE(v) \
                            PRAGMA(DATA_SECTION(v, MEMSEC_VAR))
#endif

#ifdef __cplusplus
#define SET_MEMSEC_VAR(v) PRAGMA(DATA_SECTION(MEMSEC_VAR))
#else
#define SET_MEMSEC_VAR(v) PRAGMA(DATA_SECTION(v, MEMSEC_VAR))
#endif

#ifdef __cplusplus
#define SET_MEMSEC_CONST_A(v) ALIGN2CACHE(v) \
                              PRAGMA(DATA_SECTION(MEMSEC_CONST))
#else
#define SET_MEMSEC_CONST_A(v) ALIGN2CACHE(v) \
                              PRAGMA(DATA_SECTION(v, MEMSEC_CONST))
#endif

#ifdef __cplusplus
#define SET_MEMSEC_CONST(v) PRAGMA(DATA_SECTION(MEMSEC_CONST))
#else
#define SET_MEMSEC_CONST(v) PRAGMA(DATA_SECTION(v, MEMSEC_CONST))
#endif

#define SET_STRUCT_A(v) v; \
	                    ALIGNSTRUCT2CACHE(v)

// Use far on DSPs to refer to an external variable declared in a memory section
#if defined(_TMS320C6X) /* <TI => > */
#define MEMSEC_REF far
#else
#define MEMSEC_REF
#endif
/* End: Definition of macros, used to define the memory sections of variables */

/* Begin: Definition of macros, used to align variables, constants, array in memory */
#elif defined(__GNUG__) || defined(__GNUC__) /* <= GNU, TI => */
#define SET_MEMSEC_VAR_A(v) __attribute__ ((aligned(ALIGN_BYTES))) __attribute__ ((section (MEMSEC_VAR))) 
#define SET_MEMSEC_VAR(v) __attribute__ ((section (MEMSEC_VAR))) 

#define SET_MEMSEC_CONST_A(v) __attribute__ ((aligned(ALIGN_BYTES))) __attribute__ ((section (MEMSEC_CONST))) 
#define SET_MEMSEC_CONST(v) __attribute__ ((section (MEMSEC_CONST))) 
#define SET_STRUCT_A(v) __attribute__ ((aligned(ALIGN_BYTES))) v
/* End: Definition of macros, used to align variables, constants, array in memory */

#elif defined _MSC_VER /* <= PC, OTHER => */
#define SET_MEMSEC_VAR_A(v)   __declspec(align(ALIGN_BYTES))
#define SET_MEMSEC_VAR(v)
#define SET_MEMSEC_CONST_A(v) __declspec(align(ALIGN_BYTES))
#define SET_MEMSEC_CONST(v)
#define SET_STRUCT_A(v) __declspec(align(ALIGN_BYTES)) v
#define MEMSEC_REF


#else /* Empty macros for anything else: */
#define SET_MEMSEC_VAR_A(v) 
#define SET_MEMSEC_VAR(v) 
#define SET_MEMSEC_CONST_A(v) 
#define SET_MEMSEC_CONST(v)
#define SET_STRUCT_A(v) v
#define MEMSEC_REF

#endif /* #ifdef PC */

#endif //--  GLOB_MEMSEC_H
