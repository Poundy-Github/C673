/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 Lcf

  MODULNAME:                 lcf_veh_service.h

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.5 $


  ---*/ /*---

  CHANGES:                   Initial revision

**************************************************************************** */

#ifndef lcf_veh_service_h__
#define lcf_veh_service_h__
/*---------------------------------------------------------*
   V E R I F Y   I N C L U D E S
**---------------------------------------------------------*/

#ifndef lcf_veh_iface_h__
#error "Please include lcf_veh_iface.h"
#endif /* lcf_veh_iface_h__ */

/*---------------------------------------------------------*
   S E R V I C E   D E F I N I T I O N S
**---------------------------------------------------------*/
 
#ifdef	DRVMN_VEHPROCESS_START
#undef	DRVMN_VEHPROCESS_START
	#if defined(LCF_VEH_WRP_RUNTIME_PROFILING) && (LCF_VEH_WRP_RUNTIME_PROFILING == SWITCH_ON)
		/* Start runtime profiling */
		pLcfVehServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, RTA_GLOBALID_LCF_VEH, LCF_VEH_DRVMN, 0);
	#endif	/* LCF_VEH_WRP_RUNTIME_PROFILING */
#endif /*	DRVMN_VEHPROCESS_START	*/

#ifdef	DRVMN_VEHPROCESS_STOP
#undef	DRVMN_VEHPROCESS_STOP
	#if defined(LCF_VEH_WRP_RUNTIME_PROFILING) && (LCF_VEH_WRP_RUNTIME_PROFILING == SWITCH_ON)
		/* Stop runtime profiling */
		pLcfVehServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, RTA_GLOBALID_LCF_VEH, LCF_VEH_DRVMN, 0);
	#endif	/* LCF_VEH_WRP_RUNTIME_PROFILING */
#endif /*	DRVMN_VEHPROCESS_STOP	*/

#ifdef	TRJPLN_VEHPROCESS_START
#undef	TRJPLN_VEHPROCESS_START
	#if defined(LCF_VEH_WRP_RUNTIME_PROFILING) && (LCF_VEH_WRP_RUNTIME_PROFILING == SWITCH_ON)
		/* Start runtime profiling */
		pLcfVehServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, RTA_GLOBALID_LCF_VEH, LCF_VEH_TRJPLN, 0);
	#endif	/* LCF_VEH_WRP_RUNTIME_PROFILING */	
#endif /*	TRJPLN_VEHPROCESS_START	*/

#ifdef	TRJPLN_VEHPROCESS_STOP
#undef	TRJPLN_VEHPROCESS_STOP
	#if defined(LCF_VEH_WRP_RUNTIME_PROFILING) && (LCF_VEH_WRP_RUNTIME_PROFILING == SWITCH_ON)	
		/* Stop runtime profiling */
		pLcfVehServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, RTA_GLOBALID_LCF_VEH, LCF_VEH_TRJPLN, 0);
	#endif	/* LCF_VEH_WRP_RUNTIME_PROFILING */
#endif /*	TRJPLN_VEHPROCESS_STOP	*/

#ifdef	TRJCTR_VEHPROCESS_START
#undef	TRJCTR_VEHPROCESS_START
#if defined(LCF_VEH_WRP_RUNTIME_PROFILING) && (LCF_VEH_WRP_RUNTIME_PROFILING == SWITCH_ON)
	/* Start runtime profiling */
	pLcfVehServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, RTA_GLOBALID_LCF_VEH, LCF_VEH_TRJCTR, 0);
#endif	/* LCF_VEH_WRP_RUNTIME_PROFILING */
#endif /*	TRJCTR_VEHPROCESS_START	*/

#ifdef	TRJCTR_VEHPROCESS_STOP
#undef	TRJCTR_VEHPROCESS_STOP
#if defined(LCF_VEH_WRP_RUNTIME_PROFILING) && (LCF_VEH_WRP_RUNTIME_PROFILING == SWITCH_ON)	
	/* Stop runtime profiling */
	pLcfVehServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, RTA_GLOBALID_LCF_VEH, LCF_VEH_TRJCTR, 0);
#endif	/* LCF_VEH_WRP_RUNTIME_PROFILING */
#endif /*	TRJCTR_VEHPROCESS_STOP	*/

#ifdef	V1TRJCTR_VEHPROCESS_START
#undef	V1TRJCTR_VEHPROCESS_START
	  #if defined(LCF_VEH_WRP_RUNTIME_PROFILING) && (LCF_VEH_WRP_RUNTIME_PROFILING == SWITCH_ON)
		/* Start runtime profiling */
		pLcfVehServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, RTA_GLOBALID_LCF_VEH, LCF_VEH_v1TRJCTR, 0);
	  #endif	/* LCF_VEH_WRP_RUNTIME_PROFILING */
#endif /*	V1TRJCTR_VEHPROCESS_START	*/

#ifdef	V1TRJCTR_VEHPROCESS_STOP
#undef	V1TRJCTR_VEHPROCESS_STOP
	  #if defined(LCF_VEH_WRP_RUNTIME_PROFILING) && (LCF_VEH_WRP_RUNTIME_PROFILING == SWITCH_ON)	
		/* Stop runtime profiling */
		pLcfVehServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, RTA_GLOBALID_LCF_VEH, LCF_VEH_v1TRJCTR, 0);
	  #endif	/* LCF_VEH_WRP_RUNTIME_PROFILING */
#endif /*	V1TRJCTR_VEHPROCESS_STOP	*/

#ifdef	LATDMC_VEHPROCESS_START
#undef	LATDMC_VEHPROCESS_START
	#if defined(LCF_VEH_WRP_RUNTIME_PROFILING) && (LCF_VEH_WRP_RUNTIME_PROFILING == SWITCH_ON)
		/* Start runtime profiling */
		pLcfVehServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, RTA_GLOBALID_LCF_VEH, LCF_VEH_LATDMC, 0);
	#endif	/* LCF_VEH_WRP_RUNTIME_PROFILING */
#endif /*	LATDMC_VEHPROCESS_START	*/

#ifdef	LATDMC_VEHPROCESS_STOP
#undef	LATDMC_VEHPROCESS_STOP
	#if defined(LCF_VEH_WRP_RUNTIME_PROFILING) && (LCF_VEH_WRP_RUNTIME_PROFILING == SWITCH_ON)
		/* Stop runtime profiling */
		pLcfVehServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, RTA_GLOBALID_LCF_VEH, LCF_VEH_LATDMC, 0);
	#endif	/* LCF_VEH_WRP_RUNTIME_PROFILING */
#endif /*	LATDMC_VEHPROCESS_STOP	*/

#ifdef	DDROC_VEHPROCESS_START
#undef	DDROC_VEHPROCESS_START
	#if defined(LCF_VEH_WRP_RUNTIME_PROFILING) && (LCF_VEH_WRP_RUNTIME_PROFILING == SWITCH_ON)
		/* Start runtime profiling */
		pLcfVehServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, RTA_GLOBALID_LCF_VEH, LCF_VEH_DDROC, 0);
	#endif	/* LCF_VEH_WRP_RUNTIME_PROFILING */
#endif /*	DDROC_VEHPROCESS_START	*/

#ifdef	DDROC_VEHPROCESS_STOP
#undef	DDROC_VEHPROCESS_STOP
	#if defined(LCF_VEH_WRP_RUNTIME_PROFILING) && (LCF_VEH_WRP_RUNTIME_PROFILING == SWITCH_ON)
		/* Stop runtime profiling */
		pLcfVehServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, RTA_GLOBALID_LCF_VEH, LCF_VEH_DDROC, 0);
	#endif	/* LCF_VEH_WRP_RUNTIME_PROFILING */
#endif /*	DDROC_VEHPROCESS_STOP	*/

#ifdef	VEH_WRP_VEHPROCESS_START
#undef	VEH_WRP_VEHPROCESS_START
  #if defined(LCF_VEH_WRP_RUNTIME_PROFILING) && (LCF_VEH_WRP_RUNTIME_PROFILING == SWITCH_ON)
    /* Start runtime profiling */
    services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, (uint8)RTA_GLOBALID_LCF_VEH, (uint8)LCF_VEH_TOTAL, 0U);
  #endif	/* LCF_VEH_WRP_RUNTIME_PROFILING */
#endif /* VEH_WRP_VEHPROCESS_START */

#ifdef	VEH_WRP_VEHPROCESS_STOP
#undef	VEH_WRP_VEHPROCESS_STOP
  #if defined(LCF_VEH_WRP_RUNTIME_PROFILING) && (LCF_VEH_WRP_RUNTIME_PROFILING == SWITCH_ON)
    /* Stop runtime profiling */
    services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, (uint8)RTA_GLOBALID_LCF_VEH, (uint8)LCF_VEH_TOTAL, 0U);
  #endif	/* LCF_VEH_WRP_RUNTIME_PROFILING */
#endif /* VEH_WRP_VEHPROCESS_STOP */

#ifdef	LCF_VEH_MEASF_START
#undef	LCF_VEH_MEASF_START
  #if defined(LCF_VEH_WRP_RUNTIME_PROFILING) && (LCF_VEH_WRP_RUNTIME_PROFILING == SWITCH_ON)
	/* Stop runtime profiling */
	services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart,(uint8)RTA_GLOBALID_LCF_VEH, (uint8)LCF_VEH_MEASF, 0U);
  #endif	/* LCF_VEH_WRP_RUNTIME_PROFILING */
#endif /* LCF_VEH_MEASF_START */

#ifdef	LCF_VEH_MEASF_STOP
#undef	LCF_VEH_MEASF_STOP
  #if defined(LCF_VEH_WRP_RUNTIME_PROFILING) && (LCF_VEH_WRP_RUNTIME_PROFILING == SWITCH_ON)
	/* Stop runtime profiling */
	services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, (uint8)RTA_GLOBALID_LCF_VEH, (uint8)LCF_VEH_MEASF, 0U);
  #endif	/* LCF_VEH_WRP_RUNTIME_PROFILING */
#endif /*	LCF_VEH_MEASF_STOP	*/


#endif /* lcf_veh_service_h__ */
