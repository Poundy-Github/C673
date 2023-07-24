/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 FCT

MODULNAME:                 fct_sen_wrapper.c

DESCRIPTION:               FCT wrapper function to be active during the ECU mode, if memory isn't provided by GA

AUTHOR:                    Madhusudan Mudhol

CREATION DATE:             03/06/2018

VERSION:                   $Revision: 1.4 $

LEGACY VERSION:            -

**************************************************************************** */

/*#include "fct_sen_ext.h"
#include "fct_sen.h"


#if (FCT_CFG_USE_INTERNAL_MEMORY)

static FCT_Mem_DataIntraCycle       FCT_MemDataIntraCycle;
static FCT_Mem_DataInterCycle       FCT_MemDataInterCycle;
static FCT_Mem_DataIntraCycleFreeze FCT_MemDataIntraCycleFreeze;
static FCT_Mem_DataInterCycleFreeze FCT_MemDataInterCycleFreeze; */

/* Memory object for FCT */
/*const FCT_ProcMem FCT_MemObj = {
	&FCT_MemDataIntraCycle,
	&FCT_MemDataInterCycle,
	&FCT_MemDataIntraCycleFreeze,
	&FCT_MemDataInterCycleFreeze
};

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)*/
/*THIS IS THE ENTRY POINT TO FCT SEN EXECUTION*/
/*void FCT_v_Wrapper(const reqFCTSenPrtList_t * pRequirePorts, const proFCTSenPrtList_t * pProvidePorts, const AS_t_ServiceFuncts *pServiceFuncts)
{
	FCTSen_Exec(pRequirePorts, pProvidePorts, pServiceFuncts, &FCT_MemObj);

}
#else
void FCT_v_Wrapper(const reqFCTSenPrtList_t * pRequirePorts, const proFCTSenPrtList_t * pProvidePorts)
{
	FCTSen_Exec(pRequirePorts, pProvidePorts, &FCT_SlateMemObj);

}
#endif 

#endif */ /*FCT_CFG_USE_INTERNAL_MEMORY*/ 
