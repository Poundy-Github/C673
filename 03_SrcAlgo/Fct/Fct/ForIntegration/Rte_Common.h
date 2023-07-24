// **********************************************************************
// 
//COMPANY:     Continental Automotive , 
// 
//PROJECT:     ARS400
//    
//CPU:         MPC5674x
// 
//Component:   Rte_Adaption_Cmp
// 
//MODULNAME:   FullModelElementName
// 
//- Description:	short description of the file
//- CPU:		optional for HW dependent SW: processor name (e.g. MPC5674F)
//
// 
// **********************************************************************         


#ifndef Rte_Common_H
#define Rte_Common_H

#include "Rte_Algo_Type.h"
//#include "Rte_CDDFlsp_Type.h"
//#include "Rte_EcuM_Type.h"
//#include "Rte_NvM_Type.h"
//#include "Rte_SWCAlnAdapt_Type.h"
//#include "Rte_SWCBsw_Type.h"
//#include "Rte_SWCDem_Type.h"
//#include "Rte_SWCDiag_Type.h"
//#include "Rte_SWCDiaSrv_Type.h"
//#include "Rte_SWCEmAdapt_Type.h"
//#include "Rte_SWCEth_Type.h"
//#include "Rte_SWCFctSenAdapt_Type.h"
//#include "Rte_SWCFctVehAdapt_Type.h"
//#include "Rte_SWCFr_Type.h"
//#include "Rte_SWCFSMon_SysMISC_Type.h"
//#include "Rte_SWCFSMon_TaskMonitoring_Type.h"
//#include "Rte_SWCFSMon_Type.h"
//#include "Rte_SWCMts_Type.h"
//#include "Rte_SWCNorm_Type.h"
//#include "Rte_SWCNvm_Type.h"
//#include "Rte_SWCRcc_Type.h"
//#include "Rte_SWCRhcAdapt_Type.h"
//#include "Rte_SWCRsp1Adapt_Type.h"
//#include "Rte_SWCRsp2Adapt_Type.h"
//#include "Rte_SWCSctl_Type.h"
//#include "Rte_SWCSysTime_Type.h"
//#include "Rte_SWCVdyAdapt_Type.h"
//#include "Rte_SWCXcp_Type.h"

/*## package ARS400_SW_Algo_Pkg::Radar_Pkg::Rte_Adaption_Pkg */

/*## class TopLevel::Rte_Common */
/*#[ ignore */
//- Description:	short description of the file
//- CPU:		optional for HW dependent SW: processor name (e.g. MPC5674F)
/*#]*/

#ifdef __cplusplus
extern "C"
{
#endif

/* CM: float limits are not generated properly from AUTOSAR_BaseTypes.ecuextract. Therefore removed from ecuextract */
/* typedef float32Limit_t */
#ifndef   float32_LowerLimit
  #define float32_LowerLimit	-1.175494351E38f
#endif
#ifndef   float32_UpperLimit
  #define float32_UpperLimit	3.402823466E38f
#endif

#ifdef __cplusplus
}
#endif

#endif
/*********************************************************************
	File Path	: ..\..\..\04_Engineering\_gensrc\rhapsody\Rte_Common.h
*********************************************************************/

