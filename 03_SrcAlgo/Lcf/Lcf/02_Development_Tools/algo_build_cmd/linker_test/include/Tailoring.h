/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC4xx, SRLCamxxx

  CPU:                    

  COMPONENT:              Linker test

  MODULNAME:              Tailoring

  DESCRIPTION:            Tailoring the standered names expected from the components.

  AUTHOR:                 Medhat HUSSAIN

  CREATION DATE:          2014-05-12

  VERSION:                $Revision: 1.1 $
********************************************************************************/
#include "ecm_service_types.h"
/********************************************************************************/
/* COMPONENT: Sac																*/
/********************************************************************************/
#define reqSacPrtList reqSacPrtListWrp_t 
#define proSacPrtList proSacPrtListWrp_t
#define proSacPrtList_t proSacPrtListWrp_t 
#define reqSacPrtList_t reqSacPrtListWrp_t

/********************************************************************************/
/* COMPONENT: HLA																*/
/********************************************************************************/ 
#define HlaExec HLA_Exec

/********************************************************************************/
/* COMPONENT: SR																*/
/********************************************************************************/ 
#define reqSrWrpPartAPrtList_t	reqSrAPrtList_t
#define proSrWrpPartAPrtList_t  proSrAPrtList_t
#define reqSrWrpPartBPrtList_t	reqSrBPrtList_t
#define proSrWrpPartBPrtList_t  proSrBPrtList_t
