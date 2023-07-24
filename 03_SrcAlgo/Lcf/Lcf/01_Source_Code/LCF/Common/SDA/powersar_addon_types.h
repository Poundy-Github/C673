/*~A*/
/*~+:VM Header*/
/* UML source model state: Draft */
/* ## Module Header Start [8d39263e-8b7d-4ee3-b175-17449f668aba] */
/****************************************************************************

COPYRIGHT (C) $Date: 2019/07/03 13:44:20CEST $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.                                                 
                                                                           
The reproduction, transmission or use of this document or its contents is  
not permitted without express written authority.                           
Offenders will be liable for damages. All rights, including rights created 
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------

$Log: powersar_addon_types.h  $
Revision 1.1 2019/07/03 13:44:20CEST Nastasa, Elena (uidt4846) 
Initial revision
Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/Common/SDA/project.pj
Revision 1.3 2018/01/12 12:54:51CET Garrelfs Ralf-Ingo (uidg0598) (uidg0598) 
added content from original file
Revision 1.6 2016/12/18 09:35:23CET Subramanian Sankar (uidw5330) (uidw5330) 
Update

****************************************************************************/
/* ## Module Header End [8d39263e-8b7d-4ee3-b175-17449f668aba] */

/*~E*/
#ifndef POWERSAR_ADDON_TYPES_H
#define POWERSAR_ADDON_TYPES_H
/*~A*/
/*~+:Includes*/
// #include "mcsa_types.h"
/*~E*/
/*~A*/
/*~+:Macro Definitions*/
/*lint -esym(9071,NULL) Deviation GEN.4, MISRA Rule 21.1: Not dangerous as NULL is defined in stddef.h which we do not include. */
#ifndef NULL
#define NULL                                             ((void *) 0)  /**< Null pointer */
#endif
#define F32_EPSILON                                      ((float32) 1.19209290E-07F)  /**< The epsilon value of data type float32. */
#define F32_MAX                                          ((float32) 3.40282346E+38F)  /**< MAX value of data type float32. */ //ElNa, original value 3.40282347E+38F was too big for preprocessing
#define F32_MIN                                          ((float32) 1.17549435E-38F)  /**< MIN value of data type float32. */
#define S16_MAX                                          ((sint16) 0x7FFF)  /**< MAX value of data type sint16. */
#define S16_MIN                                          ((sint16) 0x8000)  /**< MIN value of data type sint16. */
#define S32_MAX                                          ((sint32) 0x7FFFFFFFL)  /**< MAX value of data type sint32. */
#define S32_MIN                                          ((sint32) 0x80000000L)  /**< MIN value of data type sint32. */
#define S64_MAX                                          ((sint64) 0x7FFFFFFFFFFFFFFFLL)  /**< MAX value of data type sint64. */
#define S64_MIN                                          ((sint64) 0x8000000000000000LL)  /**< MIN value of data type sint64. */
#define S8_MAX                                           ((sint8)  0x7F)  /**< MAX value of data type sint8. */
#define S8_MIN                                           ((sint8)  0x80)  /**< MIN value of data type sint8. */
#define U16_MAX                                          ((uint16) 0xFFFFU)  /**< MAX value of data type uint16. */
#define U16_MIN                                          ((uint16) 0x0U)  /**< MIN value of data type uint16. */
#define U32_MAX                                          ((uint32) 0xFFFFFFFFUL)  /**< MAX value of data type uint32. */
#define U32_MIN                                          ((uint32) 0x0UL)  /**< MIN value of data type uint32. */
#define U64_MAX                                          ((uint64) 0xFFFFFFFFFFFFFFFFULL)  /**< MAX value of data type uint64. */
#define U64_MIN                                          ((uint64) 0x0ULL)  /**< MIN value of data type uint64. */
#define U8_MAX                                           ((uint8)  0xFFU)  /**< MAX value of data type uint8. */
#define U8_MIN                                           ((uint8)  0x0U)  /**< MIN value of data type uint8. */
/*~E*/
/*~A*/
/*~+:Macro Operations*/
/* Macro operation name: MAKE_VOLATILE */
/** This macro operation shall perform a volatile access to the given variable with the given type.

Example:
#define MAKE_VOLATILE(type, var) (*(volatile type *) (&(var)))

@param type 
@param var  */
/* ## Macro operation start [24684dfc-7ed8-4dc7-8b40-5d60518df711] */
#define MAKE_VOLATILE(type, var)  (*(volatile type *) (&(var)))
/* ## Macro operation end [24684dfc-7ed8-4dc7-8b40-5d60518df711] */

/*~E*/

#endif
