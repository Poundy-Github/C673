/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 Lcf

  MODULNAME:                 lcf_sen_service.h

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.6 $


  ---*/ /*---
  CHANGES:                   $Log: lcf_sen_service.h  $
  CHANGES:                   Revision 1.6 2020/07/16 18:53:32CEST Craciun, Mihaela (uidl9730) (uidl9730) 
  CHANGES:                   new updates
  CHANGES:                   Revision 1.5 2020/02/21 12:50:07CET Craciun, Mihaela (uidl9730) (uidl9730) 
  CHANGES:                   Updates after qaf report
  CHANGES:                   Revision 1.3 2019/07/30 10:04:13CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update wrappers after LCF workshop review
  CHANGES:                   Revision 1.2 2019/05/10 12:13:07CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Switch to ID's from RTA_t_GlobalIDs
  CHANGES:                   Revision 1.1 2019/03/24 17:36:10CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/01_Source_Code/LCF/LCF_MFC431x/DPU/FRAME_SEN/project.pj
  CHANGES:                   Revision 1.1 2019/03/24 08:39:26CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/01_Source_Code/LCF/LCF_MFC431x/DPU/FRAME_SEN/project.pj
  CHANGES:                   Revision 1.1 2019/01/31 18:56:06CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/LCF_MFC/DPU/FRAME_SEN/project.pj
  CHANGES:                   Revision 1.8 2018/06/25 14:01:42CEST Grosu, George (uidl9584) 
  CHANGES:                   Update enum definition for RTA Analysis
  CHANGES:                   Revision 1.7 2018/04/19 09:39:08CEST Grosu, George (uidl9584) 
  CHANGES:                   8.2 Initial Revision
  CHANGES:                   Revision 1.6 2018/03/27 12:38:41CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Check-in wrappers for Sprint08
  CHANGES:                   Revision 1.5 2018/03/05 19:11:50CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   implement interface headers

**************************************************************************** */

#ifndef lcf_sen_service_h__
#define lcf_sen_service_h__
/*---------------------------------------------------------*
   V E R I F Y   I N C L U D E S
**---------------------------------------------------------*/

#ifndef lcf_sen_iface_h__
#error "Please include lcf_sen_iface.h"
#endif /* lcf_sen_iface_h__ */

/*---------------------------------------------------------*
   S E R V I C E   D E F I N I T I O N S
**---------------------------------------------------------*/

#ifdef	HMCSCT_SENPROCESS_START
#undef	HMCSCT_SENPROCESS_START
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON) 
 	/* Start runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_HMCSCT, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	HMCSCT_SENPROCESS_START	*/

#ifdef	HMCSCT_SENPROCESS_STOP
#undef	HMCSCT_SENPROCESS_STOP
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON)  
	/* Stop runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_HMCSCT, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	HMCSCT_SENPROCESS_STOP	*/

#ifdef	ABPR_SENPROCESS_START
#undef	ABPR_SENPROCESS_START
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON)  
 	/* Start runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_ABPR, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	ABPR_SENPROCESS_START	*/

#ifdef	ABPR_SENPROCESS_STOP
#undef	ABPR_SENPROCESS_STOP
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON)   
	/* Stop runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_ABPR, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	ABPR_SENPROCESS_STOP	*/

#ifdef	V1ABPR_SENPROCESS_START
#undef	V1ABPR_SENPROCESS_START
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON)  
 	/* Start runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_v1ABPR, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	V1ABPR_SENPROCESS_START	*/

#ifdef	V1ABPR_SENPROCESS_STOP
#undef	V1ABPR_SENPROCESS_STOP
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON)   
	/* Stop runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_v1ABPR, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	V1ABPR_SENPROCESS_STOP	*/


#ifdef	V2ABPR_SENPROCESS_START
#undef	V2ABPR_SENPROCESS_START
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON)  
 	/* Start runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_v2ABPR, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	V2ABPR_SENPROCESS_START	*/

#ifdef	V2ABPR_SENPROCESS_STOP
#undef	V2ABPR_SENPROCESS_STOP
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON)   
	/* Stop runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_v2ABPR, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	V2ABPR_SENPROCESS_STOP	*/


#ifdef	ODPR_SENPROCESS_START
#undef	ODPR_SENPROCESS_START
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON) 
 	/* Start runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_ODPR, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	ODPR_SENPROCESS_START	*/

#ifdef	ODPR_SENPROCESS_STOP
#undef	ODPR_SENPROCESS_STOP
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON)  
	/* Stop runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_ODPR, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	ODPR_SENPROCESS_STOP	*/

#ifdef	V1ODPR_SENPROCESS_START
#undef	V1ODPR_SENPROCESS_START
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON) 
 	/* Start runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_v1ODPR, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	V1ODPR_SENPROCESS_START	*/

#ifdef	V1ODPR_SENPROCESS_STOP
#undef	V1ODPR_SENPROCESS_STOP
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON)  
	/* Stop runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_v1ODPR, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	V1ODPR_SENPROCESS_STOP	*/

#ifdef	V2ODPR_SENPROCESS_START
#undef	V2ODPR_SENPROCESS_START
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON) 
 	/* Start runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_v2ODPR, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	V2ODPR_SENPROCESS_START	*/

#ifdef	V2ODPR_SENPROCESS_STOP
#undef	V2ODPR_SENPROCESS_STOP
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON)  
	/* Stop runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_v2ODPR, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	V2ODPR_SENPROCESS_STOP	*/

#ifdef	VDPR_SENPROCESS_START
#undef	VDPR_SENPROCESS_START
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON) 
 	/* Start runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_VDPR, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	VDPR_SENPROCESS_START	*/

#ifdef	VDPR_SENPROCESS_STOP
#undef	VDPR_SENPROCESS_STOP
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON)  
	/* Stop runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_VDPR, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	VDPR_SENPROCESS_STOP	*/

#ifdef	LKASA_SENPROCESS_START
#undef	LKASA_SENPROCESS_START
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON) 
 	/* Start runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_LKASA, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	LKASA_SENPROCESS_START	*/

#ifdef	LKASA_SENPROCESS_STOP
#undef	LKASA_SENPROCESS_STOP
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON)  
	/* Stop runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_LKASA, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	LKASA_SENPROCESS_STOP	*/

#ifdef	LDWSA_SENPROCESS_START
#undef	LDWSA_SENPROCESS_START
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON) 
 	/* Start runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_LDWSA, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	LDWSA_SENPROCESS_START	*/

#ifdef	LDWSA_SENPROCESS_STOP
#undef	LDWSA_SENPROCESS_STOP
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON)  
	/* Stop runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_LDWSA, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	LDWSA_SENPROCESS_STOP	*/

#ifdef	LDPSA_SENPROCESS_START
#undef	LDPSA_SENPROCESS_START
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON) 
 	/* Start runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_LDPSA, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	LDPSA_SENPROCESS_START	*/

#ifdef	LDPSA_SENPROCESS_STOP
#undef	LDPSA_SENPROCESS_STOP
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON)  
	/* Stop runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_LDPSA, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	LDPSA_SENPROCESS_STOP	*/

#ifdef	ALCASA_SENPROCESS_START
#undef	ALCASA_SENPROCESS_START
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON) 
 	/* Start runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_ALCASA, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	ALCASA_SENPROCESS_START	*/

#ifdef	ALCASA_SENPROCESS_STOP
#undef	ALCASA_SENPROCESS_STOP
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON)  
	/* Stop runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_ALCASA, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	ALCASA_SENPROCESS_STOP	*/

#ifdef	LDPOCSA_SENPROCESS_START
#undef	LDPOCSA_SENPROCESS_START
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON) 
 	/* Start runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_LDPOCSA, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	LDPOCSA_SENPROCESS_START	*/

#ifdef	LDPOCSA_SENPROCESS_STOP
#undef	LDPOCSA_SENPROCESS_STOP
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON)  
	/* Stop runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_LDPOCSA, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	LDPOCSA_SENPROCESS_STOP	*/

#ifdef	V1LDPOCSA_SENPROCESS_START
#undef	V1LDPOCSA_SENPROCESS_START
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON) 
 	/* Start runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_v1LDPOCSA, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	V1LDPOCSA_SENPROCESS_START	*/

#ifdef	V1LDPOCSA_SENPROCESS_STOP
#undef	V1LDPOCSA_SENPROCESS_STOP
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON)  
	/* Stop runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_v1LDPOCSA, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	V1LDPOCSA_SENPROCESS_STOP	*/

#ifdef	RDPSA_SENPROCESS_START
#undef	RDPSA_SENPROCESS_START
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON) 
 	/* Start runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_RDPSA, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	RDPSA_SENPROCESS_START	*/

#ifdef	RDPSA_SENPROCESS_STOP
#undef	RDPSA_SENPROCESS_STOP
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON)  
	/* Stop runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_RDPSA, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	RDPSA_SENPROCESS_STOP	*/

#ifdef	V1RDPSA_SENPROCESS_START
#undef	V1RDPSA_SENPROCESS_START
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON) 
 	/* Start runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_v1RDPSA, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	V1RDPSA_SENPROCESS_START	*/

#ifdef	V1RDPSA_SENPROCESS_STOP
#undef	V1RDPSA_SENPROCESS_STOP
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON)  
	/* Stop runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_v1RDPSA, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	V1RDPSA_SENPROCESS_STOP	*/

#ifdef	TJASA_SENPROCESS_START
#undef	TJASA_SENPROCESS_START
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON) 
 	/* Start runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_TJASA, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	TJASA_SENPROCESS_START	*/

#ifdef	TJASA_SENPROCESS_STOP
#undef	TJASA_SENPROCESS_STOP
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON)  
	/* Stop runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_TJASA, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	TJASA_SENPROCESS_STOP	*/

#ifdef	V1TJASA_SENPROCESS_START
#undef	V1TJASA_SENPROCESS_START
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON) 
 	/* Start runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_v1TJASA, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	V1TJASA_SENPROCESS_START	*/

#ifdef	V1TJASA_SENPROCESS_STOP
#undef	V1TJASA_SENPROCESS_STOP
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON)  
	/* Stop runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_v1TJASA, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	V1TJASA_SENPROCESS_STOP	*/

#ifdef	V2TJASA_SENPROCESS_START
#undef	V2TJASA_SENPROCESS_START
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON) 
 	/* Start runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_v2TJASA, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	V2TJASA_SENPROCESS_START	*/

#ifdef	V2TJASA_SENPROCESS_STOP
#undef	V2TJASA_SENPROCESS_STOP
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON)  
	/* Stop runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_v2TJASA, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	V2TJASA_SENPROCESS_STOP	*/

#ifdef	MDCTR_SENPROCESS_START
#undef	MDCTR_SENPROCESS_START
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON) 
 	/* Start runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_MDCTR, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	MDCTR_SENPROCESS_START	*/

#ifdef	MDCTR_SENPROCESS_STOP
#undef	MDCTR_SENPROCESS_STOP
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON)  
	/* Stop runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_MDCTR, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	MDCTR_SENPROCESS_STOP	*/

#ifdef	CTRSC_SENPROCESS_START
#undef	CTRSC_SENPROCESS_START
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON) 
 	/* Start runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_CTRSC, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	CTRSC_SENPROCESS_START	*/

#ifdef	CTRSC_SENPROCESS_STOP
#undef	CTRSC_SENPROCESS_STOP
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON)  
	/* Stop runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_CTRSC, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	CTRSC_SENPROCESS_STOP	*/

#ifdef	HMIOC_SENPROCESS_START
#undef	HMIOC_SENPROCESS_START
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON) 
 	/* Start runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_HMIOC, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	HMIOC_SENPROCESS_START	*/

#ifdef	HMIOC_SENPROCESS_STOP
#undef	HMIOC_SENPROCESS_STOP
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON)  
	/* Stop runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_HMIOC, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	HMIOC_SENPROCESS_STOP	*/

#ifdef	LTASA_SENPROCESS_START
#undef	LTASA_SENPROCESS_START
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON) 
 	/* Start runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_LTASA, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	LTASA_SENPROCESS_START	*/

#ifdef	LTASA_SENPROCESS_STOP
#undef	LTASA_SENPROCESS_STOP
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON)  
	/* Stop runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_LTASA, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	LTASA_SENPROCESS_STOP	*/

#ifdef	TMCSCT_SENPROCESS_START
#undef	TMCSCT_SENPROCESS_START
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON) 
 	/* Start runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_TMCSCT, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	TMCSCT_SENPROCESS_START	*/

#ifdef	TMCSCT_SENPROCESS_STOP
#undef	TMCSCT_SENPROCESS_STOP
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON)  
	/* Stop runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_TMCSCT, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	TMCSCT_SENPROCESS_STOP	*/

#ifdef	LCOSCT_SENPROCESS_START
#undef	LCOSCT_SENPROCESS_START
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON) 
 	/* Start runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_LCOSCT, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	LCOSCT_SENPROCESS_START	*/

#ifdef	LCOSCT_SENPROCESS_STOP
#undef	LCOSCT_SENPROCESS_STOP
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON)  
	/* Stop runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_LCOSCT, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	LCOSCT_SENPROCESS_STOP	*/

#ifdef	SAICSCT_SENPROCESS_START
#undef	SAICSCT_SENPROCESS_START
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON) 
 	/* Start runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_SAICSCT, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	SAICSCT_SENPROCESS_START	*/

#ifdef	SAICSCT_SENPROCESS_STOP
#undef	SAICSCT_SENPROCESS_STOP
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON)  
	/* Stop runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_SAICSCT, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	SAICSCT_SENPROCESS_STOP	*/

#ifdef	SGMWSCT_SENPROCESS_START
#undef	SGMWSCT_SENPROCESS_START
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON) 
 	/* Start runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_SGMWSCT, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	SGMWSCT_SENPROCESS_START	*/

#ifdef	SGMWSCT_SENPROCESS_STOP
#undef	SGMWSCT_SENPROCESS_STOP
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON)  
	/* Stop runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_SGMWSCT, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	SGMWSCT_SENPROCESS_STOP	*/

#ifdef	BYDSCT_SENPROCESS_START
#undef	BYDSCT_SENPROCESS_START
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON) 
 	/* Start runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_BYDSCT, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	BYDSCT_SENPROCESS_START	*/

#ifdef	BYDSCT_SENPROCESS_STOP
#undef	BYDSCT_SENPROCESS_STOP
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON)  
	/* Stop runtime profiling */
	pLcfSenServices->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_BYDSCT, 0);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	BYDSCT_SENPROCESS_STOP	*/

#ifdef	SEN_WRP_SENPROCESS_START
#undef	SEN_WRP_SENPROCESS_START
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON)  
	/* Stop runtime profiling */
	services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, (uint8)RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_TOTAL, 0U);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /* SEN_WRP_SENPROCESS_START */

#ifdef	SEN_WRP_SENPROCESS_STOP
#undef	SEN_WRP_SENPROCESS_STOP
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON)  
	/* Stop runtime profiling */
	services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd,(uint8)RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_TOTAL, 0U);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	SEN_WRP_SENPROCESS_STOP	*/

#ifdef	LCF_SEN_MEASF_START
#undef	LCF_SEN_MEASF_START
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON)  
	/* Stop runtime profiling */
	services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart,(uint8)RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_MEASF, 0U);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /* LCF_SEN_MEASF_START */

#ifdef	LCF_SEN_MEASF_STOP
#undef	LCF_SEN_MEASF_STOP
  #if defined(LCF_SEN_WRP_RUNTIME_PROFILING) && (LCF_SEN_WRP_RUNTIME_PROFILING == SWITCH_ON)  
	/* Stop runtime profiling */
	services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, (uint8)RTA_GLOBALID_LCF_SEN, (uint8)LCF_SEN_MEASF, 0U);
  #endif /* LCF_SEN_WRP_RUNTIME_PROFILING */ 
#endif /*	LCF_SEN_MEASF_STOP	*/

#endif /* lcf_sen_service_h__ */

