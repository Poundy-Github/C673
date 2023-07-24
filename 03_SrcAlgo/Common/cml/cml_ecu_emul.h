/*! \file **********************************************************************

  COMPANY:                   Continental AG, A.D.C. GmbH

  CPU:                       CPU-Independent

  COMPONENT:                 CML (Common Math Library)

  MODULNAME:                 cml_ecu_emul.h

  DESCRIPTION:               Provides emulation of ECU math routines for PC simulation

  AUTHOR:                    Michael Eisenacher

  CREATION DATE:             24.05.2012

  VERSION:                   $Revision: 1.34 $

  ---*/ /*---
  CHANGES:                   $Log: cml_ecu_emul.h  $
  CHANGES:                   Revision 1.34 2017/10/13 11:02:33CEST A, Nandu (uidr5428) (uidr5428) 
  CHANGES:                   Corrected the function header format
  CHANGES:                   Revision 1.33 2017/09/27 05:58:44CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Merged from branch with Detailed Design
  CHANGES:                   Revision 1.32 2017/05/29 12:43:43CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   merged CML_f_Neg macro definition from 1.26.1.3
  CHANGES:                   Revision 1.31 2017/05/26 09:45:06CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   corrected typo
  CHANGES:                   Revision 1.30 2017/05/25 14:42:05CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Included macro to add c66x optimization simulation for MSVC.
  CHANGES:                   Revision 1.29 2016/12/07 11:57:57CET Jagannath-EXT, Anu (uid42056) 
  CHANGES:                   Code cleanup
  CHANGES:                   Revision 1.28 2016/11/18 06:44:17CET Jagannath-EXT, Anu (uid42056) 
  CHANGES:                   Intrinsic optimization
  CHANGES:                   Revision 1.27 2016/11/02 04:36:48CET Jagannath-EXT, Anu (uid42056) 
  CHANGES:                   Added code for bitmatching MSVC and C66x
  CHANGES:                   Revision 1.26 2016/05/09 16:25:13CEST Ulveland, Lars (uidt7777) 
  CHANGES:                   Added the Ti C6000 compiler to the list of those understanding the inline keyword to improve the inlining of small functions.
  CHANGES:                   Revision 1.25 2014/09/24 14:38:52CEST Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - fixed handling of __STDC_VERSION__ for versions older than 199901
  CHANGES:                   --- Added comments ---  uidg6516 [Sep 24, 2014 2:38:52 PM CEST]
  CHANGES:                   Change Package : 266613:1 http://mks-psad:7002/im/viewissue?selection=266613
  CHANGES:                   Revision 1.24 2014/09/24 08:47:53CEST Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - reordered handling of compiler switch __STDC_VERSION__ to avoid compiler warnings
  CHANGES:                   --- Added comments ---  uidg6516 [Sep 24, 2014 8:47:53 AM CEST]
  CHANGES:                   Change Package : 243179:8 http://mks-psad:7002/im/viewissue?selection=243179
  CHANGES:                   Revision 1.23 2014/07/30 09:06:55CEST Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - reduced QA-C-warnings
  CHANGES:                   --- Added comments ---  uidg6516 [Jul 30, 2014 9:06:55 AM CEST]
  CHANGES:                   Change Package : 243179:6 http://mks-psad:7002/im/viewissue?selection=243179
  CHANGES:                   Revision 1.22 2014/07/30 08:02:56CEST Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - added suppression of QA-C-Warning 3415 (possible side effect on operand of logical operation) for functions that sure don't have any side effects
  CHANGES:                   --- Added comments ---  uidg6516 [Jul 30, 2014 8:02:57 AM CEST]
  CHANGES:                   Change Package : 243179:6 http://mks-psad:7002/im/viewissue?selection=243179
  CHANGES:                   Revision 1.21 2014/07/22 13:02:35CEST Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - merged runtime optimisations for CML_Round(), CML_f_Floor() and CML_f_Ceil() to trunk
  CHANGES:                   --- Added comments ---  uidg6516 [Jul 22, 2014 1:02:36 PM CEST]
  CHANGES:                   Change Package : 245057:1 http://mks-psad:7002/im/viewissue?selection=245057
  CHANGES:                   Revision 1.20.1.2 2014/07/22 12:49:33CEST Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - use emulation functions for CML_Round(), CML_f_Floor() and CML_f_Ceil() in Race Runner SIL
  CHANGES:                   --- Added comments ---  uidg6516 [Jul 22, 2014 12:49:33 PM CEST]
  CHANGES:                   Change Package : 245057:1 http://mks-psad:7002/im/viewissue?selection=245057
  CHANGES:                   Revision 1.20.1.1 2014/06/03 10:58:03CEST Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - use HW accelerated functions for CML_Round(), CML_f_Floor() and CML_f_Ceil()
  CHANGES:                   --- Added comments ---  uidg6516 [Jun 3, 2014 10:58:04 AM CEST]
  CHANGES:                   Change Package : 230040:5 http://mks-psad:7002/im/viewissue?selection=230040
  CHANGES:                   Revision 1.20 2014/05/10 11:20:34CEST Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - fixed some QA-C issues
  CHANGES:                   --- Added comments ---  uidg6516 [May 10, 2014 11:20:34 AM CEST]
  CHANGES:                   Change Package : 230040:1 http://mks-psad:7002/im/viewissue?selection=230040
  CHANGES:                   Revision 1.19 2014/05/09 08:44:26CEST Spruck, Jochen (spruckj) 
  CHANGES:                   change from inline to static inline for gcc
  CHANGES:                   --- Added comments ---  spruckj [May 9, 2014 8:44:26 AM CEST]
  CHANGES:                   Change Package : 232002:1 http://mks-psad:7002/im/viewissue?selection=232002
  CHANGES:                   Revision 1.18 2014/05/05 14:45:06CEST Fischer-EXT, Andre (uidg5297) 
  CHANGES:                   update compiler switch for gcc
  CHANGES:                   --- Added comments ---  uidg5297 [May 5, 2014 2:45:07 PM CEST]
  CHANGES:                   Change Package : 234287:2 http://mks-psad:7002/im/viewissue?selection=234287
  CHANGES:                   Revision 1.17 2014/04/07 16:45:34CEST Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - removed needless check in CML_u_Round2UintGen()
  CHANGES:                   --- Added comments ---  uidg6516 [Apr 7, 2014 4:45:34 PM CEST]
  CHANGES:                   Change Package : 227281:4 http://mks-psad:7002/im/viewissue?selection=227281
  CHANGES:                   Revision 1.16 2014/04/07 10:29:55CEST Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - fixed erroneous include protection
  CHANGES:                   --- Added comments ---  uidg6516 [Apr 7, 2014 10:29:56 AM CEST]
  CHANGES:                   Change Package : 227281:3 http://mks-psad:7002/im/viewissue?selection=227281
  CHANGES:                   Revision 1.15 2014/03/27 11:17:57CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - fixed some QA-C- and Styleguide-issues
  CHANGES:                   --- Added comments ---  uidg6516 [Mar 27, 2014 11:17:57 AM CET]
  CHANGES:                   Change Package : 227281:2 http://mks-psad:7002/im/viewissue?selection=227281
  CHANGES:                   Revision 1.14 2014/02/05 13:33:33CET Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - add include for target build
  CHANGES:                   --- Added comments ---  uidu0849 [Feb 5, 2014 1:33:34 PM CET]
  CHANGES:                   Change Package : 159154:34 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.13 2014/02/05 13:21:31CET Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - restructure compiler switches and use HW accelerated functions provided by SW
  CHANGES:                   --- Added comments ---  uidu0849 [Feb 5, 2014 1:21:31 PM CET]
  CHANGES:                   Change Package : 159154:34 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.12 2014/01/20 14:22:09CET Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - add switch for WindRiver Diab compiler
  CHANGES:                   Revision 1.11 2013/09/12 11:30:43CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - temporarily disable Visual Studio warning 4214 (unions)
  CHANGES:                   --- Added comments ---  uidu0849 [Sep 12, 2013 11:30:43 AM CEST]
  CHANGES:                   Change Package : 159154:32 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.10 2013/05/14 11:50:19CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - add switch for Greenhills compiler
  CHANGES:                   --- Added comments ---  uidu0849 [May 14, 2013 11:50:20 AM CEST]
  CHANGES:                   Change Package : 159154:30 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.9 2013/05/13 17:38:11CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - clean up float and int macros
  CHANGES:                   - use CML_INLINE
  CHANGES:                   --- Added comments ---  uidu0849 [May 13, 2013 5:38:12 PM CEST]
  CHANGES:                   Change Package : 159154:30 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.8 2013/05/08 15:28:52CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - make inline functions static
  CHANGES:                   --- Added comments ---  uidu0849 [May 8, 2013 3:28:52 PM CEST]
  CHANGES:                   Change Package : 159154:27 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.7 2013/05/07 15:43:20CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - add inline functions CML_f_Round2IntGen and CML_f_Round2UintGen
  CHANGES:                   - replace standard types
  CHANGES:                   --- Added comments ---  uidu0849 [May 7, 2013 3:43:21 PM CEST]
  CHANGES:                   Change Package : 159154:28 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.6 2013/05/03 09:55:43CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - drop algo_common from CML
  CHANGES:                   - use new standard type names, e.g. float32 instead of f32_t
  CHANGES:                   --- Added comments ---  uidu0849 [May 3, 2013 9:55:44 AM CEST]
  CHANGES:                   Change Package : 159154:27 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.5 2013/04/23 10:42:38CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - use assertions in the sqrt functions
  CHANGES:                   --- Added comments ---  uidu0849 [Apr 23, 2013 10:42:39 AM CEST]
  CHANGES:                   Change Package : 159154:26 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.4 2013/04/12 10:41:46CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - Fix inclusion of math.h
  CHANGES:                   --- Added comments ---  uidu0849 [Apr 12, 2013 10:41:47 AM CEST]
  CHANGES:                   Change Package : 159154:21 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.3 2013/04/09 12:55:21CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - Refactor cml_ecu_emul.h
  CHANGES:                   --- Added comments ---  uidu0849 [Apr 9, 2013 12:55:21 PM CEST]
  CHANGES:                   Change Package : 159154:21 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.2 2013/02/27 10:59:26CET Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - correct min/max for ECU
  CHANGES:                   --- Added comments ---  uidu0849 [Feb 27, 2013 10:59:27 AM CET]
  CHANGES:                   Change Package : 159154:17 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.1 2012/09/14 14:31:04CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CML_CommonMathLibrary/04_Engineering/01_Source_Code/algo/cml/project.pj

**************************************************************************** */

/**
@defgroup ecu_emul ECU_EMUL (Emulation of ECU Math Routines)
  @ingroup cml
@{ */

/*****************************************************************************
  QA-C
*****************************************************************************/
/* date: 2014-05-10, reviewer: S. Schwarzkopf, reason:  
   This file maps function identifiers to platform dependent code for 
   comparability between ECU and simulation. So function like macros are 
   accepted in this file.
*/
// PRQA S 3429 EOF
// PRQA S 3453 EOF

/* Check if we are in QA-C: PRQA_SIZE_T is defined in QA-C environment. */
#ifdef PRQA_SIZE_T
  /* Switch off QA-C warnings on side effects for functions, which don't have 
     any side effects and will sure never have some. */
  #pragma PRQA_NO_SIDE_EFFECTS CML_s_Round2Int_MPC5675K_Emu
  #pragma PRQA_NO_SIDE_EFFECTS CML_u_Round2Uint_MPC5675K_Emu
  #pragma PRQA_NO_SIDE_EFFECTS CML_f_MultAdd_MPC5675K_Emu
  #pragma PRQA_NO_SIDE_EFFECTS CML_f_Sqrt_MPC5675K_Emu
  #pragma PRQA_NO_SIDE_EFFECTS CML_f_AbsGen
  #pragma PRQA_NO_SIDE_EFFECTS CML_f_MinGen
  #pragma PRQA_NO_SIDE_EFFECTS CML_f_MaxGen
  #pragma PRQA_NO_SIDE_EFFECTS CML_f_Round2FloatGen
  #pragma PRQA_NO_SIDE_EFFECTS CML_s_Round2IntGen
  #pragma PRQA_NO_SIDE_EFFECTS CML_u_Round2UintGen
  #pragma PRQA_NO_SIDE_EFFECTS CML_f_Floor2FloatGen
  #pragma PRQA_NO_SIDE_EFFECTS CML_f_Ceil2FloatGen
  #pragma PRQA_NO_SIDE_EFFECTS CML_f_MultAddGen
#endif /* #ifdef PRQA_SIZE_T */

/*****************************************************************************
  INCLUDE PROTECTION
*****************************************************************************/

/* allow inclusion of cml sub-headers only if external cml header is included */
#ifndef _CML_EXT_INCLUDED
  #pragma message(__FILE__": Inclusion of cml_ecu_emul.h is discouraged. It exists only for compatibility with ARS3xx and might be deleted without prior notice. Include cml_ext.h instead.")
#endif /* #ifdef _CML_EXT_INCLUDED */

#ifndef _CML_ECU_EMUL_INCLUDED
#define _CML_ECU_EMUL_INCLUDED

/* include glob_type.h which contains HW accelerated functions only in the target build */
#if (defined(__DCC__))
#include "glob_type.h"
#endif

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#if defined(_MSC_VER) /* Microsoft compiler -> code only for simulation */
  #if (defined(CPU_MPC5675K_EMU) || defined(CPU_MPC5775N_EMU)) /* emulation of Freescale Golddust or Racerunner ECU specific functions */
    #include <math.h> /* use the standard sqrt to emulate the ECU specific sqrt in the simulation */
  #endif /* ECU switch for Microsoft compiler */
  #if defined(CML_OPT_c66x)
   #include "C6xSimulator.h"
  #endif
#endif /* compiler switch */

/*****************************************************************************
  CONSTANTS
*****************************************************************************/

/* Defines for inlining functions*/ 
#if defined(_MSC_VER) /* Microsoft compiler -> code only for simulation */
#define CML_INLINE  __inline 

#elif defined(__GNUC__) /* GNU C compiler -> code for CortexA8 per gcc */
#define CML_INLINE static inline 

#elif (defined(__POWERPC__) && defined(__MWERKS__)) /* Freescale Metrowerks compiler for PowerPC-ECUs -> code only for ECU (e.g. ARS301) */
#define CML_INLINE  inline

#elif (defined(__DCC__)) /* Wind River Diab compiler -> code only for ECU (e.g. ARS400) */
#define CML_INLINE inline

#elif defined(_TMS320C6X)
#define CML_INLINE inline

#elif (defined(__STDC_VERSION__)) /* C99 compatible compiler has to have inline keyword with proper non-extern linkage */
#if (__STDC_VERSION__ >= 199901)
#define CML_INLINE inline 
#else /* #if (__STDC_VERSION__ >= 199901) */
#define CML_INLINE static inline 
#endif /* #if/else (__STDC_VERSION__ >= 199901) */

#else  /* unknown compiler -> no INLINE */
#define CML_INLINE static ///< \brief Macro to inline the functions based on the compiler \description This will be defined as static OR inline OR static inline based on the compiler \n
///< \n
/// | Switch                        | Definition of CML_INLINE  |
/// | :---------------------------- | :------------------------ |
/// |_MSC_VER                       |__inline                   |
/// |__POWERPC__&&__MWERKS__        |   inline                  |
/// |__DCC__                        |   inline                  |
/// |_TMS320C6X                     |   inline                  |
/// |__STDC_VERSION__ >= 199901     |   inline                  |
/// |__STDC_VERSION__ < 199901      |   static inline           |
/// |__GNUC__                       |   static inline           |
/// |All Other Compilers            |   static                  |
#endif

/*****************************************************************************
  MACROS
*****************************************************************************/

#if defined(_MSC_VER) /* Microsoft compiler -> code only for simulation */

  #define CML_f_Abs(x)             CML_f_AbsGen(x) ///< absolute value for floating point 

  #define CML_f_Min(x,y)           CML_f_MinGen(x, y) ///< minimum of two values 

  #define CML_f_Max(x,y)           CML_f_MaxGen(x, y) ///< maximum of two values 

  #define CML_f_Neg(x)             (-(x)) ///< Negative number 

  #if (defined(CPU_MPC5675K_EMU) || defined(CPU_MPC5775N_EMU)) /* emulation of Freescale Golddust or Racerunner ECU specific functions */

    #define CML_s_Round2Int(x)     CML_s_Round2Int_MPC5675K_Emu(x) ///< rounds floating point and converts to signed integer 

    #define CML_u_Round2Uint(x)    CML_u_Round2Uint_MPC5675K_Emu(x) ///< rounds floating point and converts to unsigned integer 

    #define CML_f_MultAdd(a,b,d)   CML_f_MultAdd_MPC5675K_Emu(a,b,d) ///< floating point multiply and add: (a * b) + d 

    #define CML_f_Sqrt(x)          CML_f_Sqrt_MPC5675K_Emu(x) ///< square root 

    #define CML_Round(x)           (float32)CML_s_Round2Int_MPC5675K_Emu(x) ///< Rounds of positive and negative numbers 

    #define CML_f_Floor(x)         (float32)CML_s_Round2Int_MPC5675K_Emu(x - 0.5f) ///< Computes floor of positive and negative numbers. Works only for x in the range [-2147483647 ... 2147483647] 

    #define CML_f_Ceil(x)          (float32)CML_s_Round2Int_MPC5675K_Emu(x + 0.5f) ///< Computes ceiling of positive and negative numbers. Works only for x in the range [-2147483647 ... 2147483647] 

  #else /* default simulation code (none of the above listed ECU emulations) */

    #define CML_s_Round2Int(x)     CML_s_Round2IntGen(x) ///< rounds floating point and converts to signed integer 

    #define CML_u_Round2Uint(x)    CML_u_Round2UintGen(x) ///< rounds floating point and converts to unsigned integer 

    #define CML_f_MultAdd(a,b,d)   CML_f_MultAddGen(a,b,d) ///< floating point multiply and add: (a * b) + d 

    #define CML_f_Sqrt(x)          CML_f_SqrtApprox(x) ///< square root 

    #define CML_Round(x)             CML_f_Round2FloatGen(x) ///< Rounds of positive and negative numbers 

    #define CML_f_Floor(x)           CML_f_Floor2FloatGen(x) ///< Computes floor of positive and negative numbers. Works only for x in the range [-2147483647 ... 2147483647] 

    #define CML_f_Ceil(x)            CML_f_Ceil2FloatGen(x) ///< Computes ceiling of positive and negative numbers. Works only for x in the range [-2147483647 ... 2147483647] 

  #endif /* ECU switch for Microsoft compiler */

#elif (defined(__DCC__)) /* Wind River Diab compiler -> code only for ECU (e.g. ARS400) */

  #define CML_f_Abs(x)           fABS_HW(x) ///< absolute value for floating point 

  #define CML_f_Min(x,y)         MIN_FLOAT_HW(x,y) ///< minimum of two values 

  #define CML_f_Max(x,y)         MAX_FLOAT_HW(x,y) ///< maximum of two values 

  #define CML_Round(x)           (float32)ROUND_TO_INT_HW(x) ///< Rounds of positive and negative numbers 

  #define CML_f_Floor(x)         (float32)ROUND_TO_INT_HW(x - 0.5f) ///< Computes floor of positive and negative numbers. Works only for x in the range [-2147483647 ... 2147483647] 

  #define CML_f_Ceil(x)          (float32)ROUND_TO_INT_HW(x + 0.5f) ///< Computes ceiling of positive and negative numbers. Works only for x in the range [-2147483647 ... 2147483647] 

  #define CML_s_Round2Int(x)     ROUND_TO_INT_HW(x) ///< rounds floating point and converts to signed integer 

  #define CML_u_Round2Uint(x)    ROUND_TO_UINT_HW(x) ///< rounds floating point and converts to unsigned integer 

  #define CML_f_MultAdd(a,b,d)   MUL_ADD_FLOAT_HW(a,b,d) ///< floating point multiply and add: (a * b) + d 

  #define CML_f_Sqrt(x)          SQRT_HW(x) ///< square root 

  #define CML_f_Neg(x)           (NEG_FLOAT_HW(x)) ///< Negative number 

#else /* other compilers */

  #define CML_f_Abs(x)             CML_f_AbsGen(x) ///< absolute value for floating point 

  #define CML_f_Min(x,y)           CML_f_MinGen(x, y) ///< minimum of two values 

  #define CML_f_Max(x,y)           CML_f_MaxGen(x, y) ///< maximum of two values 

  #define CML_Round(x)             CML_f_Round2FloatGen(x) ///< Rounds of positive and negative numbers 

  #define CML_f_Floor(x)           CML_f_Floor2FloatGen(x) ///< Computes floor of positive and negative numbers. Works only for x in the range [-2147483647 ... 2147483647] 

  #define CML_f_Ceil(x)            CML_f_Ceil2FloatGen(x) ///< Computes ceiling of positive and negative numbers. Works only for x in the range [-2147483647 ... 2147483647] 

  #define CML_s_Round2Int(x)       CML_s_Round2IntGen(x) ///< rounds floating point and converts to signed integer 

  #define CML_u_Round2Uint(x)      CML_u_Round2UintGen(x) ///< rounds floating point and converts to unsigned integer 

  #define CML_f_MultAdd(a,b,d)     CML_f_MultAddGen(a, b, d) ///< floating point multiply and add: (a * b) + d 

  #define CML_f_Sqrt(x)            CML_f_SqrtApprox(x) ///< square root 
  
  #define CML_f_Neg(x)             (-(x)) ///< Negative number 

#endif


/*****************************************************************************
  INLINE FUNCTIONS
*****************************************************************************/

#if defined(_MSC_VER) /* Microsoft compiler -> code only for simulation */

#if (defined(CPU_MPC5675K_EMU) || defined(CPU_MPC5775N_EMU)) /* emulation of Freescale Golddust or Racerunner ECU specific functions */

CML_INLINE sint32 CML_s_Round2Int_MPC5675K_Emu(float32 x)
{
  /* Purpose of this function : emulate the behaviour of efsctsi (http://cache.freescale.com/files/32bit/doc/ref_manual/e200z760RM.pdf)
  which in the current ARS301 settings is configured for round to nearest even integer. This btw is
  also the intel x87 default (http://download.intel.com/design/processor/manuals/253665.pdf, chapter 4.8.4)
  The MSVC compiler at default uses the CRT function _ftol, _ftol2 for converting floating point to integer,
  the implementation of which suffers from several flaws. Currently no simulator code modifies the default
  rounding behaviour of the x87 FPU control word : the default being round to nearest even (thus the
  same as for PowerPC). We can use this via direct assembly language, provided we catch the saturation
  behaviour of the PPC: it clamps values into the min/max range. */
  __int32 retval;

  if (x < (float32)(1u<<31))
  {
    if (x > -(float32)(1u<<31))
    {
      __asm fld x
      __asm fistp retval
    }
    else
    {
      /* Case RD 32: 63 = 0x80000000, overflow max negative */
      retval = (1<<31);
    }
  }
  else
  {
    /* 0x7FFFFFFF, overflow max positive */
    retval = 0x7FFFFFFF;
  }
  return retval;
}

CML_INLINE uint32 CML_u_Round2Uint_MPC5675K_Emu(float32 x)
{
  /* Purpose of this function : emulate the behaviour of efsctsi (http://cache.freescale.com/files/32bit/doc/ref_manual/e200z760RM.pdf) */
  uint32 retval = 0UL;

  if (x >= 0.f)
  {
    if (x < (float32)0xFFFFFFFFu)
    {
      if (x < (float32)0x80000000u)
      {
        __asm fld x
        __asm fistp retval
      }
      else
      {
         x-= (float32)0x80000000u;
        __asm fld x
        __asm fistp retval
        retval += 0x80000000u;
      }
    }
    else
    {
      retval = 0xFFFFFFFFu;
    }
  }
  else
  {
    /* PowerPC returns 0, but as this is implementation defined according to ISO-IEC C,
    this shouldn't be relied on. An assertion would be a good idea here */
    retval = 0u;
  }
  return retval;
}

CML_INLINE float32 CML_f_MultAdd_MPC5675K_Emu(float32 fA, float32 fB, float32 fD)
{
  /* Purpose of this function : emulate the behaviour of efsmadd (http://cache.freescale.com/files/32bit/doc/ref_manual/e200z760RM.pdf) */
  typedef union {
#pragma warning(push)
#pragma warning(disable: 4214)
    struct {
      uint32 mantissa : 23;
      uint32 exponent : 8;
      uint32 sign : 1;
    } _bits;
#pragma warning(pop)
    uint32 _ui32;
    float32 _float;
  } float_rep_t;
  float_rep_t fa, fb, fd;
  float32 fTemp;

  fa._float = fA;
  fb._float = fB;
  fd._float = fD;
  if ((fa._bits.exponent == 0) || (fb._bits.exponent == 0))
  {
    /* Denormalized number : intermediate product properly signed zero
    Final result : added to corresponding element of RD */
    if (fd._bits.exponent >= 255)
    {
      if (fd._bits.sign == 0)
      {
        fd._ui32 = 0x7F7FFFFFu;
      }
      else
      {
        fd._ui32 = 0xFF7FFFFFu;
      }
      fTemp = fd._float;
    }
    else if (fd._bits.exponent == 0)
    {
      /* The result would be a denormalized number */
      fTemp = 0.f;
    }
    else
    {
      /* The result is 'fD' */
      fTemp = fD;
    }
  }
  else if ((fa._bits.exponent >= 255) || (fb._bits.exponent >= 255))
  {
    /* Infinity / NaN */
    if (fa._bits.sign == fb._bits.sign)
    {
      /* Final result pmax (see 5.3.1.1 of http://cache.freescale.com/files/32bit/doc/ref_manual/e200z760RM.pdf) */
      fa._ui32 = 0x7F7FFFFFu;
      fTemp = fa._float;
    }
    else
    {
      /* Final result nmax (see 5.3.1.1 of http://cache.freescale.com/files/32bit/doc/ref_manual/e200z760RM.pdf) */
      fa._ui32 = 0xFF7FFFFFu;
      fTemp = fa._float;
    }
  }
  else
  {
    if (fd._bits.exponent >= 255u)
    {
      /* fD is NaN/infinity */
      if (fd._bits.sign == 0)
      {
        fd._ui32 = 0x7F7FFFFFu;
      }
      else
      {
        fd._ui32 = 0xFF7FFFFFu;
      }
      fTemp = fd._float;
    }
    else if ((fa._bits.exponent + fb._bits.exponent) >= (255u + 254u))
    {
      /* fA * fB would overflow */
      if (fa._bits.sign == fb._bits.sign)
      {
        fd._ui32 = 0x7F7FFFFFu;
      }
      else
      {
        fd._ui32 = 0xFF7FFFFFu;
      }
      fTemp = fd._float;
    }
    else
    {
      /* Normal fA, fB : intermediate result is the multiplication
      Use SSE2 instruction set to be independent of FPU precission */
      __asm movss xmm0, fA
      __asm movss xmm1, fB
      __asm cvtps2pd xmm0, xmm0
      __asm cvtps2pd xmm1, xmm1
      __asm mulsd xmm0, xmm1
      __asm movss xmm1, fD
      __asm cvtps2pd xmm1, xmm1
      __asm addsd xmm0, xmm1
      __asm cvtpd2ps xmm0, xmm0
      __asm movss fTemp, xmm0
      /* fTemp = (fA * fB) + fD; */
    }
  }
  return fTemp;
}


CML_INLINE float32 CML_f_Sqrt_MPC5675K_Emu(float32 x)
{
  /* Purpose of this function : emulate the behaviour of efssqrt (http://cache.freescale.com/files/32bit/doc/ref_manual/e200z760RM.pdf) */
  /* Call the standard sqrt from math.h but return 0 instead of IND for negative radicand */
  /*
  Mail von Uwe-Juergen Zunker/li/eu/au/cag am 23.5.2011
  >Hallo Joachim,
  >
  >ich habe 2 Bereiche getestet fuer x=sqrt(y) 
  >- y im Bereich 0.0 bis 9780.20310 mit insgesamt 10000000 Schritte zu je 0.001
  >- y im Bereich 0.5 bis 1.19209 mit insgesamt 10000000 Mantissen-Inkrementen (also lueckenlos)
  >
  >Fuer x und y habe ich jeweils eine CRC32C (Castagnoli) berechnet.
  >Diese CRC hat eine Hamming Distance (HD) von hd>=4 fuer 268435455 Byte.
  >Dies entspricht 67 Mio Werten, der Test verknuepft "nur" 10 Mio Werte pro CRC, also gilt  hd>=4.
  >
  >Die Berechnung unter Visual 2005 ergibt 
  >mit
  >
  >
  >Glob_crcx  = 0xD2662C7C
  >Glob_crcy  = 0xDC44AF80
  >Glob_crcx2 = 0x56A18FF4
  >Glob_crcy2 = 0xAB7BAA9B
  >
  >Der entsprechend angepasste C-Code-Block liefert unter MPC5674F ab Rev 2 die identischen Ergebnisse, 
  >damit sind die jeweils 10 Mio Werte untereinander ebenfalls identisch:

  If the hw sqrt function is not available the standard lib sqrt function is used (PPC hw sqrt is bit idendtical to the std lib function)
  */

  float32 fTemp;

  CML_ASSERT(x >= 0.f);

  if (x <= 0.f)
  {
    fTemp = 0.f;
  }
  else
  {
    fTemp = (float32) sqrt(x);
  }
  return fTemp;
}

#endif /* ECU switch for Microsoft compiler */

#endif /* compiler switch */



/* generic functions for various compilers / ECUs */
/* date: 2014-07-30, reviewer: S. Schwarzkopf, reason:  
   Macro CML_INLINE used to handle inline keyword, which is compiler dependent, to have no external linkage.
*/
// PRQA S 3406 17
/*****************************************************************************
       Functionname:    CML_f_AbsGen                                     *//*!

  \brief           This computes absolute value of a floating point number

  \description     The function calculates the absolute value of a floating
                   point number. will return the same number if it is greater 
                   than or equal to zero, otherwise returns negated value.

  \InOutCorrelation
                  If x is the input value, then
                   \f[ if\ x\ >=\ 0;\ then\ return\  (|x| = x)\\ \f]
                   \f[ if\ x\ <\ 0;\  then\ return\ (|x| = -x) \f]

  \param[in]       x :  The float number for which absolute value is needed

  \return          Absolute value of the given floating point number
  
  \author
  
  \testmethod    
  
  \traceability   
*****************************************************************************/
CML_INLINE float32 CML_f_AbsGen(float32 x);
CML_INLINE float32 CML_f_AbsGen(float32 x)
{
#ifdef CML_OPT_c66x
  return(_fabsf(x));
#else
  return (x < 0.f) ? -x : x;
#endif  
}

/* date: 2014-07-30, reviewer: S. Schwarzkopf, reason:  
   Macro CML_INLINE used to handle inline keyword, which is compiler dependent, to have no external linkage.
*/
// PRQA S 3406 17
/*****************************************************************************
       Functionname:    CML_f_MinGen                                     *//*!

  \brief           This computes minimum of two given float values

  \description         The function calculates the minimum of two floating
                   point numbers.

  \InOutCorrelation
                  If x is the input value, then
                   \f[ if\ x\ <\ y;\ then\ return\  (x)\\ \f]
                   \f[ if\ x\ >= \ y;\ then\ return\  (y) \f]

  \param[in]       x :  The first float number for comparison
  \param[in]       y :  The second float number for comparison

  \return          Minimum of the two floating point numbers
  \author
  
  \testmethod    
  
  \traceability   
*****************************************************************************/
CML_INLINE float32 CML_f_MinGen(float32 x, float32 y);
CML_INLINE float32 CML_f_MinGen(float32 x, float32 y)
{
  return (x < y) ? x : y;
}

/* date: 2014-07-30, reviewer: S. Schwarzkopf, reason:  
   Macro CML_INLINE used to handle inline keyword, which is compiler dependent, to have no external linkage.
*/
// PRQA S 3406 17
/*****************************************************************************
       Functionname:    CML_f_MaxGen                                     *//*!

  \brief           This computes maximum of two given float values

  \description         The function calculates the maximum of two floating
                   point numbers.

  \InOutCorrelation
                  If x and y are two input values, then
                   \f[ if\ x\ >\ y;\ then\ return\  (x)\\ \f]
                   \f[ if\ x\ <= \ y;\ then\ return\  (y) \f]

  \param[in]       x :  The first float number for comparison
  \param[in]       y :  The second float number for comparison

  \return          Maximum of the two floating point numbers
  \author
  
  \testmethod    
  
  \traceability   
*****************************************************************************/
CML_INLINE float32 CML_f_MaxGen(float32 x, float32 y);
CML_INLINE float32 CML_f_MaxGen(float32 x, float32 y)
{
  return (x > y) ? x : y;
}

/* date: 2014-07-30, reviewer: S. Schwarzkopf, reason:  
   Macro CML_INLINE used to handle inline keyword, which is compiler dependent, to have no external linkage.
*/
// PRQA S 3406 15
/*****************************************************************************
       Functionname:    CML_f_Round2FloatGen                             *//*!

  \brief           This is a rounding function for a given float value

  \description         The function rounds the given floating point number 

  \InOutCorrelation
                  If x is the input value, then
                   \f[ if\ x\ >=\ 0;\ then\ return\  (x = x + 0.5)\\ \f]
                   \f[ if\ x\ <\ 0;\ then\ return\  (x = x - 0.5) \f]

  \param[in]       x :  The float number on which rounding operation needs to be done

  \return          Rounded value of the given floating point number

  \author
  
  \testmethod    
  
  \traceability   
*****************************************************************************/
CML_INLINE float32 CML_f_Round2FloatGen(float32 x);
CML_INLINE float32 CML_f_Round2FloatGen(float32 x)
{
  return (x >= 0.f) ? (float32)(sint32)(x + 0.5f) : (float32)(sint32)(x - 0.5f);
}

/* date: 2014-07-30, reviewer: S. Schwarzkopf, reason:  
   Macro CML_INLINE used to handle inline keyword, which is compiler dependent, to have no external linkage.
*/
// PRQA S 3406 17
/*****************************************************************************
       Functionname:    CML_s_Round2IntGen                               *//*!

  \brief           This is a rounding function for a given float value 
                   to nearest integer

  \description         The function rounds the given floating point number 
                   to the nearest signed integer

  \InOutCorrelation
                  If x is the input value, then
                   \f[ if\ x\ >=\ 0;\ then\ return\ (sint32)(x = x + 0.5)\\ \f]
                   \f[ if\ x\ <\ 0;\ then\ return\  (sint32)(x = x - 0.5) \f]

  \param[in]       x :  The float number on which rounding operation needs to be done

  \return          Rounded integer for the given floating point number

  \author
  
  \testmethod    
  
  \traceability   
*****************************************************************************/
CML_INLINE sint32 CML_s_Round2IntGen(float32 x);
CML_INLINE sint32 CML_s_Round2IntGen(float32 x)
{
  return (x >= 0.f) ? (sint32)(x + 0.5f) : (sint32)(x - 0.5f);
}

/* date: 2014-07-30, reviewer: S. Schwarzkopf, reason:  
   Macro CML_INLINE used to handle inline keyword, which is compiler dependent, to have no external linkage.
*/
// PRQA S 3406 17
/*****************************************************************************
       Functionname:    CML_u_Round2UintGen                              *//*!

  \brief           This is a rounding function for a given positive float  
                   value to nearest integer

  \description         The function rounds the given positive floating point 
                   number to the nearest unsigned integer

  \InOutCorrelation
                  If x is the input value, then
                   \f[ if\ x\ >\ 0;\ then\ return\  (uint32)(x = x + 0.5)\\ \f]

  \attention       x value has to be greater than or equal to 0.

  \param[in]       x :  The float number on which rounding operation needs to be done

  \return          Rounded integer for the given floating point number

  \author
  
  \testmethod    
  
  \traceability   
*****************************************************************************/
CML_INLINE uint32 CML_u_Round2UintGen(float32 x);
CML_INLINE uint32 CML_u_Round2UintGen(float32 x)
{
  /* date: 2014-05-10, reviewer: S. Schwarzkopf, reason: proven in use, CML ASSERT macro */
  CML_ASSERT(x >= 0.f); /* PRQA S 3112 */
  return (uint32)(x + 0.5f);
}

/*! Generic function to compute floor of positive and negative numbers. Works only for x in the range [-2147483647 ... 2147483647] */
/* date: 2014-07-30, reviewer: S. Schwarzkopf, reason:  
   Macro CML_INLINE used to handle inline keyword, which is compiler dependent, to have no external linkage.
*/
// PRQA S 3406 16
/*****************************************************************************
       Functionname:    CML_f_Floor2FloatGen                             *//*!

  \brief           This is a flooring function for a given float value 

  \description         The function does the flooring operation on given floating point  
                   number

  \InOutCorrelation
                  If x is the input value, then
                   \f[ if\ x - (sint32)x\  >= 0; then\ return\ x\\ \f]
                   \f[ if\ x - (sint32)x\  < 0; then\ return\ (x = x - 1.0)\\ \f]

  \param[in]       f_x :  The float number on which flooring operation needs to be done

  \return          Floored value for the given floating point number

  \author
  
  \testmethod    
  
  \traceability   
*****************************************************************************/
CML_INLINE float32 CML_f_Floor2FloatGen(float32 f_x);
CML_INLINE float32 CML_f_Floor2FloatGen(float32 f_x)
{
  return (((f_x - (float32)((sint32)f_x)) >= 0.0f) ? ((float32)((sint32)f_x)) : ((float32)((sint32)f_x) - 1.0f));
}

/*! Generic function to compute ceil of positive and negative numbers. Works only for x in the range [-2147483647 ... 2147483647] */
/* date: 2014-07-30, reviewer: S. Schwarzkopf, reason:  
   Macro CML_INLINE used to handle inline keyword, which is compiler dependent, to have no external linkage.
*/
// PRQA S 3406 16
/*****************************************************************************
       Functionname:    CML_f_Ceil2FloatGen                              *//*!

  \brief           This is a ceiling function for a given float value 

  \description         The function does the ceiling operation on given floating point  
                   number

  \InOutCorrelation
                  If x is the input value, then
                   \f[ if\ x - (sint32)x\  >= 0; then\ return\  (x = x + 1.0)\\ \f]
                   \f[ if\ x - (sint32)x\  < 0; then\ return\ x\\ \f]

  \param[in]       f_x :  The float number on which ceiling operation needs to be done

  \return          Ceiled value for the given floating point number

  \author
  
  \testmethod    
  
  \traceability    
*****************************************************************************/
CML_INLINE float32 CML_f_Ceil2FloatGen(float32 f_x);
CML_INLINE float32 CML_f_Ceil2FloatGen(float32 f_x)
{
  return (((f_x - (float32)((sint32)f_x))> 0.0f) ? ((float32)((sint32)f_x) + 1.0f) : ((float32)((sint32)f_x)));
}

/* date: 2014-07-30, reviewer: S. Schwarzkopf, reason:  
   Macro CML_INLINE used to handle inline keyword, which is compiler dependent, to have no external linkage.
*/
// PRQA S 3406 19
/*****************************************************************************
       Functionname:    CML_f_MultAddGen                                 *//*!

  \brief           This function does the multiply and add operation

  \description         The function does the multiply and add operation 
                   on given floating point numbers

  \InOutCorrelation
                  If (a, b, d) are inputs, then return
                   \f[Result =  (a\times b + d)\f]
  \param[in]       a :  The multiplicand float number
  \param[in]       b :  The multiplier float number
  \param[in]       d :  The float number to be added to the product.

  \return          Sum of product of first two numbers and the third number 
                   ((a*b)+d) 

  \author
  
  \testmethod    
  
  \traceability   
*****************************************************************************/
CML_INLINE float32 CML_f_MultAddGen(float32 a, float32 b, float32 d);
CML_INLINE float32 CML_f_MultAddGen(float32 a, float32 b, float32 d)
{
#if defined(_MSC_VER)  
  float32 f_tmp1, f_tmp2;
  f_tmp1 = a * b;
  f_tmp2 = f_tmp1 + d;
  return f_tmp2;
#else
  return (a * b) + d;
#endif
}

#endif /* #ifndef _CML_ECU_EMUL_INCLUDED */


/** @} end defgroup */
