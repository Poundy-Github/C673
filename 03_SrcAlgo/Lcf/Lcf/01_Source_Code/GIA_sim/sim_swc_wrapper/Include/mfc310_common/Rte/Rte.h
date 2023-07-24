/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2010 by Vector Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte.h
 *     Workspace:  D:/Sandboxes/MFC300/MFC300_Base/05_Software/MCU/03_Design/05_DaVinci/mfc310_SMPC.dev
 *   ECU-Project:  MPC
 *  Generated at:  Thu Jul  7 11:15:52 2011
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.3
 *       License:  License CBD1000091 valid for CBD1000091 A.D.C. GmbH Continental  Package: Daimler Car SLP10  Micro: MPC567xK / MPC5675K  Compiler: Metrowerks V4.0.0
 *
 *   Description:  Header file containing RTE types
 *********************************************************************************************************************/

/* double include prevention */

#ifndef _RTE_H
# define _RTE_H

# define RTE_SW_MAJOR_VERSION (0x02u)
# define RTE_SW_MINOR_VERSION (0x11u)
# define RTE_SW_PATCH_VERSION (0x03u)

# define RTE_VENDOR_ID (0x001Eu)

# define RTE_AR_MAJOR_VERSION (0x02u)
# define RTE_AR_MINOR_VERSION (0x02u)
# define RTE_AR_PATCH_VERSION (0x00u)

# include "Std_Types.h"

# ifdef RTE_ENABLE_USER_DATATYPES
#  include "Rte_UserTypes.h"
# endif

/* AUTOSAR 2.1 compatibility */
# if !defined (STATIC) && defined (_STATIC_)
#  define STATIC _STATIC_
# endif

# if !defined (TYPEDEF) && defined (AUTOMATIC)
#  define TYPEDEF AUTOMATIC
# endif

/* Note: application errors are in the range between 1-63
         overlayed error (ORed with application errors) is 64
         structural errors are in the range between 128-256 */

/* common errors */
# define RTE_E_OK               ((Std_ReturnType)  0)
# define RTE_E_INVALID          ((Std_ReturnType)  1)

/* overlayed errors */
# define RTE_E_LOST_DATA        ((Std_ReturnType) 64)
# define RTE_E_MAX_AGE_EXCEEDED ((Std_ReturnType) 64)

/* immediate infrastructure errors */
# define RTE_E_COM_STOPPED      ((Std_ReturnType)128)
# define RTE_E_COMMS_ERROR      ((Std_ReturnType)128)  /* AUTOSAR 2.1 compatibility */
# define RTE_E_TIMEOUT          ((Std_ReturnType)129)
# define RTE_E_LIMIT            ((Std_ReturnType)130)
# define RTE_E_NO_DATA          ((Std_ReturnType)131)
# define RTE_E_TRANSMIT_ACK     ((Std_ReturnType)132)

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1310030428
#    error "The magic number of the generated file <D:/Sandboxes/MFC300/MFC300_Base/05_Software/MCU/03_Design/05_DaVinci/MPC/Rte/Rte.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1310030428
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_H */

/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* %name:              RTE.h %
* %instance:          TAUTOSAR_1 %
* %version:           10 %
* %created_by:        TFCESB %
* %date_created:      Wed May 27 09:37:36 2009 %
*=============================================================================*/
/* DESCRIPTION :      Header file for RTE module                              */
/*============================================================================*/
/* FUNCTION COMMENT : This RTE header File [Satisfies_rte sws 1157]           */
/*                    contains overall definitions for the RTE                */
/*                                                                            */
/*============================================================================*/
/* COPYRIGHT (C) CONTINENTAL AG 2008                                          */
/* AUTOMOTIVE ELECTRONICS                                                     */
/* ALL RIGHTS RESERVED                                                        */
/*                                                                            */
/* The reproduction, transmission, or use of this document or its content is  */
/* not permitted without express written authority. Offenders will be liable  */
/* for damages.                                                               */
/* All rights, including rights created by patent grant or registration of a  */
/* utility model or design, are reserved.                                     */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*   1.0     | 20/12 /2005 |New                            | Karl Kell        */
/*============================================================================*/

#ifndef RTE_H
#define RTE_H


//#include "Std_Types.h"    /* [Satisfies_rte sws 1164] */
#include "Os.h"           /* [Satisfies_rte sws 1257] */
#include "Com.h"          /* [Satisfies_rte sws 3794] */
/* #include "MemMap.h"       [Satisfies_rte sws done in Rte.c */
// #include "Rte_SymbolLimiter.h"  
/* if Rte_SymbolLimiter.h is included, all public linker lables of the RTE will be trunctated <32char */



 /* fixed mappping of RTE timout event to ((EventMaskType)(0x80))  */
#define RTE_EvMask_timeout         (0x8000)
#define RTE_WaitAllEventsMask      (0xFFFFFFFF)
#define RTE_NoEventsMask            0

// KK workaround #defins for CS events 
#define RTE_EvMask_SrvCallReturns  (0x4000)  


// KK workaround 
#define RTE_MdDclGrpEcuM_QLENGTH    3
#define RTE_MdDclGrpComM_QLENGTH    3
#define RTE_MdDclGrpApplMM_QLENGTH  3

extern Std_ReturnType  Rte_Invalidate_Dummy(void);


extern FUNC(void, COM_CODE) Rte__MemCopy(
                                         P2VAR(uint8, AUTOMATIC, AUTOMATIC) pDest,
                                         P2VAR(uint8, AUTOMATIC, AUTOMATIC) pSrc,
                                         VAR(uint8, AUTOMATIC) NrOfBytes
                                       );


// #define RTE__MEMCPY(PtrDst, PtrSrc, BytesNb) Rte__MemCopy(PtrDst, PtrSrc, BytesNb)
#define RTE__MEMCPY(PtrDst, PtrSrc, BytesNb) memcpy(PtrDst, PtrSrc, BytesNb)

/*
 *  The RTE uses its RTE_EN/DISABLE_IRQ macro within coma expressions.
 *  This conflicts with some Os implementations.  
 *  
 *   #define RTE_DISABLE_IRQ()		SuspendAllInterrupts()
 *   #define RTE_ENABLE_IRQ()		  ResumeAllInterrupts()
 */  
extern FUNC(void, COM_CODE) Rte__SuspendAllInterrupts(void);
extern FUNC(void, COM_CODE) Rte__ResumeAllInterrupts(void);

#define RTE_DISABLE_IRQ()		Rte__SuspendAllInterrupts()
#define RTE_ENABLE_IRQ()		Rte__ResumeAllInterrupts()



// only for DC projects 
typedef enum Rte_tResetReason 
{ 
   RTE_CYCLIC_ACTIVATION = 0, 
   RTE_EVENT_ACTIVATION	 = 1, 
   RTE_AFTER_RESET_ACTIVATION = 2,
   RTE_AFTER_FLASH_ACTIVATION = 3 
}Rte_tResetReason;

extern Rte_tResetReason Rte__get_startup_reason(void);

#endif /* RTE_H */

