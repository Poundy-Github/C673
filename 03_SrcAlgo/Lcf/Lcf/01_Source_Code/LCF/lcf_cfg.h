/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 LCF

  MODULNAME:                 lcf_cfg.h

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.6.1.9 $


  ---*/ /*--- 
  CHANGES:                   $Log: lcf_cfg.h  $
  CHANGES:                   Revision 1.6.1.9 2021/02/22 13:26:00CET Craciun, Mihaela (uidl9730) (uidl9730) 
  CHANGES:                   updates for BD21 new project added to family structure
  CHANGES:                   Revision 1.6.1.8 2020/04/09 14:28:10CEST Craciun, Mihaela (uidl9730) (uidl9730) 
  CHANGES:                   integrate new updates
  CHANGES:                   Revision 1.6.1.7 2020/03/25 14:58:53CET Craciun, Mihaela (uidl9730) (uidl9730) 
  CHANGES:                   integrate new updates
  CHANGES:                   Revision 1.6.1.6 2020/03/04 16:29:25CET Tonofa, Vladimir (uic47530) (uic47530) 
  CHANGES:                   [MFC431LO20] LCF ALGO general integration - Update lcf_cfg.h for LO20
  CHANGES:                   Revision 1.6.1.4 2020/02/21 12:50:49CET Craciun, Mihaela (uidl9730) (uidl9730) 
  CHANGES:                   Updates after qaf report
  CHANGES:                   Revision 1.6.1.2 2019/07/03 13:53:01CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update for sprint 05.10.03
  CHANGES:                   Revision 1.6.1.1 2019/06/06 09:31:34CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update lcf_cfg
  CHANGES:                   Revision 1.6 2019/05/15 08:01:14CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Add VA10 to mainstream
  CHANGES:                   Revision 1.5 2019/05/10 12:13:09CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Switch to ID's from RTA_t_GlobalIDs
  CHANGES:                   Revision 1.4 2019/05/08 13:36:02CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update files for Sprint9
  CHANGES:                   Revision 1.3 2019/04/10 04:05:21CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update LCF files for auxcodegen v4.0
  CHANGES:                   Revision 1.2 2019/03/20 12:44:57CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   AuxCodeGen 4.0
  CHANGES:                   Revision 1.1 2019/01/31 18:55:40CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/project.pj

**************************************************************************** */

#ifndef LCF_CFG_H_
#define LCF_CFG_H_

/*---------------------------------------------------------*
   I N C L U D E S
**---------------------------------------------------------*/

#include "algo_glob.h"
#include "lcf_cfg_custom.h"

/*---------------------------------------------------------*
   D E F I N E S
**---------------------------------------------------------*/

#define	LCFPRJ_DEFAULT		(0)
#define LCFPRJ_MFC431		(1)
#define LCFPRJ_MFC430HI17	(2)
#define LCFPRJ_MFC431TA19	(3)
#define LCFPRJ_MFC431HI28	(4)
#define LCFPRJ_MFC431LO19	(5)
#define LCFPRJ_MFC431SC19	(6)
#define LCFPRJ_MFC510   	(7)
#define LCFPRJ_MFC520   	(8)
#define LCFPRJ_MFC431SW19	(9)
#define LCFPRJ_MFC431VA10	(10)
#define LCFPRJ_MFC431LO20	(11)
#define LCFPRJ_MFC431BD10	(12)
#define LCFPRJ_MFC431VA21	(13)
#define LCFPRJ_MFC431BD21	(14)
#define LCFPRJ_MFC5J3	(15)
#define LCFPRJ_MFC5J3CN15	(17)

#define	LCF_PRJ_NR	LCFPRJ_DEFAULT

/*<-- Start check of project definition */
#ifdef LCF_MFC431
#if		LCF_PRJ_NR == LCFPRJ_DEFAULT
#undef	LCF_PRJ_NR
#define	LCF_PRJ_NR LCFPRJ_MFC431
#else
#error "Multiple projects defined."
#endif /* LCF_PRJ_NR */
#endif /* LCF_MFC431 */

#ifdef LCF_MFC430HI17
#if		LCF_PRJ_NR == LCFPRJ_DEFAULT
#undef	LCF_PRJ_NR
#define	LCF_PRJ_NR LCFPRJ_MFC430HI17
#else
#error "Multiple projects defined."
#endif /* LCF_PRJ_NR */
#endif /* LCF_MFC430HI17 */

#ifdef LCF_MFC431TA19
#if		LCF_PRJ_NR == LCFPRJ_DEFAULT
#undef	LCF_PRJ_NR
#define	LCF_PRJ_NR LCFPRJ_MFC431TA19
#else
#error "Multiple projects defined."
#endif /* LCF_PRJ_NR */
#endif /* LCF_MFC431TA19 */

#ifdef LCF_MFC431HI28
#if		LCF_PRJ_NR == LCFPRJ_DEFAULT
#undef	LCF_PRJ_NR
#define	LCF_PRJ_NR LCFPRJ_MFC431HI28
#else
#error "Multiple projects defined."
#endif /* LCF_PRJ_NR */
#endif /* LCF_MFC431HI28 */

#ifdef LCF_MFC431LO19
#if		LCF_PRJ_NR == LCFPRJ_DEFAULT
#undef	LCF_PRJ_NR
#define	LCF_PRJ_NR LCFPRJ_MFC431LO19
#else
#error "Multiple projects defined."
#endif /* LCF_PRJ_NR */
#endif /* LCF_MFC431LO19 */

#ifdef LCF_MFC431BD10
#if		LCF_PRJ_NR == LCFPRJ_DEFAULT
#undef	LCF_PRJ_NR
#define	LCF_PRJ_NR LCFPRJ_MFC431BD10
#else
#error "Multiple projects defined."
#endif /* LCF_PRJ_NR */
#endif /* LCF_MFC431BD10 */

#ifdef LCF_MFC431BD21
#if		LCF_PRJ_NR == LCFPRJ_DEFAULT
#undef	LCF_PRJ_NR
#define	LCF_PRJ_NR LCFPRJ_MFC431BD21
#else
#error "Multiple projects defined."
#endif /* LCF_PRJ_NR */
#endif /* LCF_MFC431BD21 */

#ifdef LCF_MFC431LO20
#if		LCF_PRJ_NR == LCFPRJ_DEFAULT
#undef	LCF_PRJ_NR
#define	LCF_PRJ_NR LCFPRJ_MFC431LO20
#else
#error "Multiple projects defined."
#endif /* LCF_PRJ_NR */
#endif /* LCF_MFC431LO20 */

#ifdef LCF_MFC431SW19
#if		LCF_PRJ_NR == LCFPRJ_DEFAULT
#undef	LCF_PRJ_NR
#define	LCF_PRJ_NR LCFPRJ_MFC431SW19
#else
#error "Multiple projects defined."
#endif /* LCF_PRJ_NR */
#endif /* LCF_MFC431SW19 */

#ifdef LCF_MFC431VA10
#if		LCF_PRJ_NR == LCFPRJ_DEFAULT
#undef	LCF_PRJ_NR
#define	LCF_PRJ_NR LCFPRJ_MFC431VA10
#else
#error "Multiple projects defined."
#endif /* LCF_PRJ_NR */
#endif /* LCF_MFC431VA10 */

#ifdef LCF_MFC431VA21
#if		LCF_PRJ_NR == LCFPRJ_DEFAULT
#undef	LCF_PRJ_NR
#define	LCF_PRJ_NR LCFPRJ_MFC431VA21
#else
#error "Multiple projects defined."
#endif /* LCF_PRJ_NR */
#endif /* LCF_MFC431VA21 */

#ifdef LCF_MFC431SC19
#if		LCF_PRJ_NR == LCFPRJ_DEFAULT
#undef	LCF_PRJ_NR
#define	LCF_PRJ_NR LCFPRJ_MFC431SC19
#else
#error "Multiple projects defined."
#endif /* LCF_PRJ_NR */
#endif /* LCF_MFC431SC19 */

#ifdef LCF_MFC510
#if		LCF_PRJ_NR == LCFPRJ_DEFAULT
#undef	LCF_PRJ_NR
#define	LCF_PRJ_NR LCFPRJ_MFC510
#else
#error "Multiple projects defined."
#endif /* LCF_PRJ_NR */
#endif /* LCF_MFC510 */

#ifdef LCF_MFC520
#if		LCF_PRJ_NR == LCFPRJ_DEFAULT
#undef	LCF_PRJ_NR
#define	LCF_PRJ_NR LCFPRJ_MFC520
#else
#error "Multiple projects defined."
#endif /* LCF_PRJ_NR */
#endif /* LCF_MFC520 */

#ifdef LCF_MFC5J3
#if		LCF_PRJ_NR == LCFPRJ_DEFAULT
#undef	LCF_PRJ_NR
#define	LCF_PRJ_NR LCFPRJ_MFC5J3
#else
#error "Multiple projects defined."
#endif /* LCF_PRJ_NR */
#endif /* LCF_MFC5J3 */

#ifdef LCF_MFC5J3CN15
#if		LCF_PRJ_NR == LCFPRJ_DEFAULT
#undef	LCF_PRJ_NR
#define	LCF_PRJ_NR LCFPRJ_MFC5J3CN15
#else
#error "Multiple projects defined."
#endif /* LCF_PRJ_NR */
#endif /* LCF_MFC5J3CN15 */
/*--> End check of project definition */

/* Check that a project was defined */
#if		LCF_PRJ_NR == LCFPRJ_DEFAULT
#error "No project is defined."
#endif /* LCF_PRJ_NR */

#define GET_LCF_PRJ_NR()		LCF_PRJ_NR
#define GET_LCFPRJ_MFC431()		LCFPRJ_MFC431
#define GET_LCFPRJ_MFC430HI17()	LCFPRJ_MFC430HI17
#define GET_LCFPRJ_MFC431TA19()	LCFPRJ_MFC431TA19
#define GET_LCFPRJ_MFC431HI28()	LCFPRJ_MFC431HI28
#define GET_LCFPRJ_MFC431LO19()	LCFPRJ_MFC431LO19
#define GET_LCFPRJ_MFC431LO20()	LCFPRJ_MFC431LO20
#define GET_LCFPRJ_MFC431SC19()	LCFPRJ_MFC431SC19
#define GET_LCFPRJ_MFC431SW19()	LCFPRJ_MFC431SW19
#define GET_LCFPRJ_MFC431VA10()	LCFPRJ_MFC431VA10
#define GET_LCFPRJ_MFC431VA21()	LCFPRJ_MFC431VA21
#define GET_LCFPRJ_MFC431BD10()	LCFPRJ_MFC431BD10
#define GET_LCFPRJ_MFC431BD21()	LCFPRJ_MFC431BD21
#define GET_LCFPRJ_MFC510()	    LCFPRJ_MFC510
#define GET_LCFPRJ_MFC520()	    LCFPRJ_MFC520
#define GET_LCFPRJ_MFC5J3()		LCFPRJ_MFC5J3
#define GET_LCFPRJ_MFC5J3CN15()		LCFPRJ_MFC5J3CN15

/*Define that overwrites the value defined in *_data.h*/
#ifndef P_LCF_AlmostZero_nu
#define P_LCF_AlmostZero_nu (1e-15f)
#define GET_P_LCF_AlmostZero_nu() (P_LCF_AlmostZero_nu)
#endif /* P_LCF_AlmostZero_nu*/

/* exclude enumeration definitions */
#define	_E_LCF_FUNCTIONV2TYPE_T_
#define _E_ABPR_ABDLNMARKERSTYPE2_T_
#define _E_ABPR_LANECHANGETYPE_T_
#define _E_ABPR_LANEEVENTTYPE_T_
#define _E_ABPR_LANEMARKERSCOLORTYPE_T_
/* symbolic constants and macros common for all modules */
#define CONV_RAD2DEG	(57.2957f)	/* conversion factor from rad to deg */
#define CONV_MPS2KPH	(3.6f)		/* conversion factor from m/s to km/h */
#define CONV_MPH2KPH	(1.609344f)	/* conversion factor from miles per hour to km/h */
#define CONV_TO_PER     (100.f)        /* convert to percents */
#define CONV_DEG2RAD    (0.01745329f)  /* conversion factor from deg to rad */

/*Surpress QAC Messages - A function could probably be used instead of this function-like macro
										A function-like macro is being defined
										Parameter 'x' occurs more than once in the replacement list of this macro
										Parameter 'x' will be evaluated more than once when this macro is used
Macros can be used on different types of input arguments and reduce machine code instructions compared to normal function*/
/*PRQA S 3453,3429,3435,3456 1*/
#define MIN_NO_OF_ELEM(x,y)    (MIN((sizeof(x)/sizeof((x)[0])), (sizeof(y)/sizeof((y)[0])))) /* in case sizeof cpar input is not equal to sizeof actual parameters */

#endif /* _LCF_CFG_H_ */


