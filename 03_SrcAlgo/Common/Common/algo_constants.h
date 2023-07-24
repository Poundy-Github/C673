/*! \file **********************************************************************

  COMPANY:                   Continental, ADAS, A.D.C. GmbH

  PROJECT:                   ARSXXX, SRRXXX

  CPU:                       CPU-Independent

  COMPONENT:                 ARCH Algorithm Architecture

  MODULNAME:                 algo_constants.h

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.13 $


  ---*/ /*---
  CHANGES:                   $Log: algo_constants.h  $
  CHANGES:                   Revision 1.13 2018/03/29 13:16:07CEST Eisenacher, Michael (eisenacherm) 
  CHANGES:                   updated module test handling
  CHANGES:                   Revision 1.11 2018/03/26 12:41:35CEST Eisenacher, Michael (eisenacherm) 
  CHANGES:                   conditional define for constants which are also defined in glob component
  CHANGES:                   Revision 1.10 2018/03/23 10:10:36CET Purusothaman, Thiyagarajan (uidd7879) 
  CHANGES:                   algo static inline added
  CHANGES:                   Revision 1.9 2018/03/21 13:48:26CET Purusothaman, Thiyagarajan (uidd7879) 
  CHANGES:                   unknown compiler no inline
  CHANGES:                   Revision 1.8 2018/03/19 14:58:49CET Purusothaman, Thiyagarajan (uidd7879) 
  CHANGES:                   corrected defines
  CHANGES:                   Revision 1.7 2018/03/13 16:26:20CET Purusothaman, Thiyagarajan (uidd7879) 
  CHANGES:                   static inline added for mingw
  CHANGES:                   Revision 1.6 2018/03/13 15:30:25CET Purusothaman, Thiyagarajan (uidd7879) 
  CHANGES:                   __GCC__ switch added for QAC related warning
  CHANGES:                   Revision 1.5 2018/02/22 11:09:32CET Eisenacher, Michael (eisenacherm) 
  CHANGES:                   removed C_KMH_MS and C_MS_KMH since it is defined in GLOB component
  CHANGES:                   Revision 1.4 2018/01/17 14:39:30CET Eisenacher, Michael (eisenacherm) 
  CHANGES:                   another merge from ARS4xx
  CHANGES:                   Revision 1.3 2018/01/17 13:08:22CET Eisenacher, Michael (eisenacherm) 
  CHANGES:                   merged with ARS4xx
  CHANGES:                   Revision 1.2 2018/01/17 12:27:13CET Eisenacher, Michael (eisenacherm) 
  CHANGES:                   added define for GCC
  CHANGES:                   Revision 1.1 2017/04/24 09:53:28CEST Eisenacher, Michael (eisenacherm) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Architecture/04_Engineering/00_Projects/ARS510/GA/algo_common/project.pj
  CHANGES:                   Revision 1.2 2016/12/22 14:08:42CET Eisenacher, Michael (eisenacherm) 
  CHANGES:                   fixed compiler warnings
  CHANGES:                   no changes for target compiler output
  CHANGES:                   Revision 1.1 2016/07/18 12:44:48CEST Eisenacher, Michael (eisenacherm) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ARCH_AlgorithmArchitecture/04_Engineering/01_Source_Code/algo/algo_common/project.pj

**************************************************************************** */
#ifndef ALGO_CONSTANTS_H_INCLUDED
#define ALGO_CONSTANTS_H_INCLUDED


/*! Constant gravity G */
#define ALGO_f_Gravity 									9.80665f

/*! Constant speed of light in vacuum c [m/s] */
#define ALGO_f_SpeedOfLight							299792458.f


/*! Constant conversion km/h <-> m/s */
#ifndef C_KMH_MS
#define C_KMH_MS                                (3.6F)
#endif

#ifndef C_MS_KMH
#define C_MS_KMH                                (0.277778F)
#endif

/*! Constant conversion millisecond <-> second */
#define C_MILLISEC_SEC    (1000.0F)

/*! Switch conditions */
#define ALGO_SwitchOn                                   1
#define ALGO_SwitchOff                                  0

/*-------------------------------------------------------------------------
| Constants for ACC object quality for function preselection              |
-------------------------------------------------------------------------*/

#define FUN_PRESEL_ACC_DROP_QUAL            (0u)  /*!< Object without ACC quality */
#define FUN_PRESEL_ACC_STAT_OBSTACLE        (30u) /*!< ACC quality of an "obstacle" which cannot be functionally assigned to a 
                                                       lane but cause a blocked path with another object */
#define FUN_PRESEL_ACC_MIN_KEEP_OBJ_QUAL    (40u)
#define FUN_PRESEL_ACC_MIN_OBJ_QUAL         (70u) /*!< Minimum ACC quality level. Moving object with this quality are assigned 
                                                       to the ego lane. Stationary objects are only assigned to a neighbouring lane. */

#define FUN_PRESEL_ACC_HIGHEST_CLUST_VAR_OBJ_QUAL (74u) /*!< Moving object with highest cluster variance this quality is assigned */
#define FUN_PRESEL_ACC_HIGH_CLUST_VAR_OBJ_QUAL    (75u) /*!< Moving object with high cluster variance this quality is assigned */
#define FUN_PRESEL_ACC_LOW_CLUST_VAR_OBJ_QUAL     (76u) /*!< Moving object with low  cluster variance this quality is assigned */

#define FUN_PRESEL_ACC_OCCLUSION_OBJ_QUAL       (80u) /*!< ACC quality for occluded objects */
#define FUN_PRESEL_ACC_MIN_INLANE_OBJ_QUAL      (85u) /*!< Inlane quality. All object with this quality level can be assigned to the ego lane. */

/* definition of NULL value */
#ifndef NULL
#ifdef  __cplusplus
#define NULL           (0)
#else
#define NULL           ((void *)0)
#endif
#endif

/* ALGO_INLINE_C and ALGO_STATIC_INLINE_C are internal defines which should not be used outside of this file, ALGO_INLINE and ALGO_STATIC_INLINE shall be used instead */

/* Defines for inlining functions*/ 
#if defined(_MSC_VER) /* Microsoft compiler -> code only for simulation */
#define ALGO_INLINE_C __inline
#define ALGO_STATIC_INLINE_C static __inline
#define ALGO_ALIGNED_4
#define ALGO_ALIGNED_8 
#define ALGO_ALIGNED_16
#elif (defined(__POWERPC__) && defined(__MWERKS__)) /* Freescale Metrowerks compiler for PowerPC-ECUs -> code only for ECU */
#define ALGO_INLINE_C inline
#define ALGO_STATIC_INLINE_C static inline
#define ALGO_ALIGNED_4
#define ALGO_ALIGNED_8 
#define ALGO_ALIGNED_16
#elif (defined(__ghs__)) /* Greenhills compiler */
#define ALGO_INLINE_C inline
#define ALGO_STATIC_INLINE_C static inline
#define ALGO_ALIGNED_4
#define ALGO_ALIGNED_8 
#define ALGO_ALIGNED_16
#elif (defined(__TI_COMPILER_VERSION__)) /* TI compiler */
#define ALGO_INLINE_C inline
#define ALGO_STATIC_INLINE_C static inline
#define ALGO_ALIGNED_4
#define ALGO_ALIGNED_8 
#define ALGO_ALIGNED_16
#elif (defined (_TASKING_C_TRICORE_))/* Tasking compiler,Added by Mingfen */
	#define ALGO_INLINE_C inline	
    #define ALGO_STATIC_INLINE_C static inline
    #define ALGO_ALIGNED_4
    #define ALGO_ALIGNED_8 
    #define ALGO_ALIGNED_16
#elif (defined(__STDC_VERSION__))
  #if (__STDC_VERSION__ >= 199901) /* C99 compatible compiler has to have inline keyword with proper non-extern linkage */
    #define ALGO_INLINE_C inline
    #define ALGO_STATIC_INLINE_C static inline
    #define ALGO_ALIGNED_4
    #define ALGO_ALIGNED_8 
    #define ALGO_ALIGNED_16
  #else
    #define ALGO_INLINE_C inline
    #define ALGO_STATIC_INLINE_C static inline
    #define ALGO_ALIGNED_4
    #define ALGO_ALIGNED_8 
    #define ALGO_ALIGNED_16
  #endif
#elif (defined(__DCC__)) /* Windriver compiler*/
#define ALGO_INLINE_C inline
#define ALGO_STATIC_INLINE_C static inline
#define ALGO_ALIGNED_4 __attribute__(( aligned(4) ))
#define ALGO_ALIGNED_8 __attribute__(( aligned(8) ))
#define ALGO_ALIGNED_16 __attribute__(( aligned(16) ))
#elif defined(__MINGW32__)
#define ALGO_INLINE_C inline
#define ALGO_STATIC_INLINE_C static inline
#define ALGO_ALIGNED_4
#define ALGO_ALIGNED_8 
#define ALGO_ALIGNED_16
#else  /* unknown compiler -> no INLINE */
#define ALGO_INLINE_C static
#define ALGO_STATIC_INLINE_C static
#define ALGO_ALIGNED_4
#define ALGO_ALIGNED_8 
#define ALGO_ALIGNED_16
#endif

/*courage environment */
#if defined(CFG_DISABLE_STATIC_MTD)
  /* Keyword for static methods/functions*/ 
  #define STATIC_MTD
  /* Keyword for inline functions*/
  #define ALGO_INLINE
  /* Keyword for inline functions in header files */
  #define ALGO_STATIC_INLINE
#else
  #define STATIC_MTD static
  #define ALGO_INLINE ALGO_INLINE_C
  #define ALGO_STATIC_INLINE ALGO_STATIC_INLINE_C
#endif

/*courage environment */
#if defined(CFG_DISABLE_STATIC_VAR)
  /* Keyword for static variables*/
  #define STATIC_VAR
#else
  #define STATIC_VAR static
#endif

#else
/* do nothing */
#endif //ALGO_CONSTANTS_H_INCLUDED
