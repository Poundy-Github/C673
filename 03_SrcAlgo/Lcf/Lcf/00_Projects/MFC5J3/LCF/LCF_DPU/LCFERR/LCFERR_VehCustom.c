/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 LCF (Lateral Control Functions)

  MODULNAME:                 LCFERR_VehCustom.c

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.1 $


  ---*/ /*---
  CHANGES:                   $Log: LCFERR_VehCustom.c  $
  CHANGES:                   Revision 1.1 2020/03/25 13:44:32CET Craciun, Mihaela (uidl9730) (uidl9730) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/00_Projects/MFC431BD10/LCF/LCF_DPU/LCFERR/project.pj
  CHANGES:                   Revision 1.5 2019/11/27 08:18:47CET Grosu, George (uidl9584) 
  CHANGES:                   Adapt for CarMaker tests
  CHANGES:                   Revision 1.4 2019/11/26 15:23:43CET Grosu, George (uidl9584) 
  CHANGES:                   bring TA19 changes to trunk
  CHANGES:                   Revision 1.3 2019/05/30 13:15:25CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Correct wrapers for ports checks and HLA
  CHANGES:                   Revision 1.2 2019/04/10 04:18:47CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update LCF files for auxcodegen v4.0
  CHANGES:                   Revision 1.3 2019/03/24 09:16:23CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   1st check-in of files from AuxCodeGen 4.0
  CHANGES:                   Revision 1.7 2019/03/22 15:18:52CET Grosu, George (uidl9584) 
  CHANGES:                   review update
  CHANGES:                   Revision 1.6 2019/03/13 12:58:37CET Grosu, George (uidl9584) 
  CHANGES:                   Silent LCFERR
  CHANGES:                   Revision 1.5 2019/02/28 16:02:12CET Grosu, George (uidl9584) 
  CHANGES:                   Secure IuC. Add DMC
  CHANGES:                   Revision 1.4 2019/02/19 13:10:11CET Grosu, George (uidl9584) 
  CHANGES:                   add Intertask errors. Use algo signal names
  CHANGES:                   Revision 1.3 2018/09/14 16:16:17CEST Grosu, George (uidl9584) 
  CHANGES:                   Split naming for Error Handler
  CHANGES:                   Revision 1.2 2018/09/11 16:19:18CEST Grosu, George (uidl9584) 
  CHANGES:                   Update error handler
  CHANGES:                   Revision 1.1 2018/05/25 08:07:49CEST Grosu, George (uidl9584) 
  CHANGES:                   update LCFERR

**************************************************************************** */

/* avoid double inclusion */
#ifndef C_LCFERR_VehCustom_
#define C_LCFERR_VehCustom_

#include "LCFVEH/LCFVEH_data.h"
#include "LCFERR_VehCustom.h"
#include "LCFERR/lcferr.h"
#include "LCFERR/lcferr_veh.h"

/* Data Types */

/* configuraiton table for DEM Events */
const uint8 S_ERRVEH_DemArray[C_ERRVEH_DemArraySize] = {
    0x01, /* LCF_VEH_FUSI_ERROR -> ERRVEH_enFUSI */
    0x02, /* LCF_VEH_SERVICE_ERROR -> ERRVEH_enSERVICE */
    0x04, /* LCF_VEH_INTERNAL_ERROR -> ERRVEH_enINTERNAL */
    0x08, /* LCF_VEH_BUS_DATA_ERROR -> ERRVEH_enBUS */
    0x00, /* No DEM event */
    0x00  /* No DEM event */
};

const uint16 S_ERRVEH_DemEvents[C_ERRVEH_NumberOfDemEvents] =
{
    LCF_VEH_FUSI_ERROR, /* ERRVEH_enFUSI */
    LCF_VEH_SERVICE_ERROR, /* ERRVEH_enSERVICE */
    LCF_VEH_INTERNAL_ERROR, /* ERRVEH_enINTERNAL */
    LCF_VEH_BUS_DATA_ERROR /* ERRVEH_enBUS */
};

const LCFERR_ActionTableType_t S_ERRVEH_ActionTable[C_ERRVEH_NumOfActions] = 
{
   {0x0000, ERRVEH_srNoAction},          /* ERRVEH_enNoAction   */
   {0x0001, ERRVEH_srActDegrDMC},        /* ERRVEH_enActDegrDMC */
   {0x0002, ERRVEH_srActTempErr},        /* ERRVEH_enActTempErr */
   {0x0004, ERRVEH_srActVehOutInvalid},  /* ERRVEH_enActVehOutInv */
   {0x0008, ERRVEH_srActVeh2SenInvalid}, /* ERRVEH_enActVeh2SenInv */
   {0x0010, ERRVEH_srActVeh2IuCInvalid}, /* ERRVEH_enActVeh2IuCInv */
   {0x0020, ERRVEH_srActPermErr},        /* ERRVEH_enActPermErr */
   {0x0040, ERRVEH_srActRedAvail},       /* ERRVEH_enActPermErr */
   {0x0080, ERRVEH_srActDegrDMCActRedAvail}/* ERRVEH_enActPermErr */
   
};

/* Errors */
const ERRVEH_ErrCfgType_t S_ERRVEH_ConfigTable[C_ERRVEH_NumOfErrors] = 
{
{(uint8)ERRVEH_enInputsDegradation,0x1001,1,1,1,0,(uint8)ERRVEH_enERRIOVeh,0x00000001,LCFERR_REST_IMMEDIATELY,ERRVEH_enNoAction,ERRVEH_enNoAction,ERRVEH_enActDegrDMC,ERRVEH_enNoAction,ERRVEH_enNoDemEvent},
{(uint8)ERRVEH_enArchPortStructure,0x1020,1,1,1,0,(uint8)ERRVEH_enVEHWrapper,0x00000007,LCFERR_REST_IMMEDIATELY,ERRVEH_enNoAction,ERRVEH_enNoAction,ERRVEH_enActTempErr,ERRVEH_enNoAction,ERRVEH_enFUSI},
{(uint8)ERRVEH_enArchPortStructure,0x1021,1,1,21,0,(uint8)ERRVEH_enVEHWrapper,0x00000008,LCFERR_REST_IMMEDIATELY,ERRVEH_enNoAction,ERRVEH_enNoAction,ERRVEH_enActTempErr,ERRVEH_enNoAction,ERRVEH_enFUSI},
{(uint8)ERRVEH_enArchPortStructure,0x1022,1,1,21,0,(uint8)ERRVEH_enVEHWrapper,0x00000010,LCFERR_REST_IMMEDIATELY,ERRVEH_enNoAction,ERRVEH_enNoAction,ERRVEH_enActTempErr,ERRVEH_enNoAction,ERRVEH_enFUSI},
{(uint8)ERRVEH_enArchPortStructure,0x1023,1,1,21,0,(uint8)ERRVEH_enVEHWrapper,0x00000020,LCFERR_REST_IMMEDIATELY,ERRVEH_enNoAction,ERRVEH_enNoAction,ERRVEH_enActTempErr,ERRVEH_enNoAction,ERRVEH_enFUSI},
{(uint8)ERRVEH_enArchPortStructure,0x1024,1,1,21,0,(uint8)ERRVEH_enVEHWrapper,0x00000040,LCFERR_REST_IMMEDIATELY,ERRVEH_enNoAction,ERRVEH_enNoAction,ERRVEH_enActTempErr,ERRVEH_enNoAction,ERRVEH_enFUSI},
{(uint8)ERRVEH_enArchPortStructure,0x1025,1,1,21,0,(uint8)ERRVEH_enVEHWrapper,0x00000080,LCFERR_REST_IMMEDIATELY,ERRVEH_enNoAction,ERRVEH_enNoAction,ERRVEH_enActTempErr,ERRVEH_enNoAction,ERRVEH_enFUSI},
{(uint8)ERRVEH_enArchPortStructure,0x1026,1,1,21,0,(uint8)ERRVEH_enVEHWrapper,0x00000100,LCFERR_REST_IMMEDIATELY,ERRVEH_enNoAction,ERRVEH_enNoAction,ERRVEH_enActTempErr,ERRVEH_enNoAction,ERRVEH_enFUSI},
{(uint8)ERRVEH_enArchPortStructure,0x1027,1,1,21,0,(uint8)ERRVEH_enVEHWrapper,0x00000200,LCFERR_REST_IMMEDIATELY,ERRVEH_enNoAction,ERRVEH_enNoAction,ERRVEH_enActTempErr,ERRVEH_enNoAction,ERRVEH_enFUSI},
{(uint8)ERRVEH_enArchPortStructure,0x1028,1,1,21,0,(uint8)ERRVEH_enVEHWrapper,0x00000400,LCFERR_REST_IMMEDIATELY,ERRVEH_enNoAction,ERRVEH_enNoAction,ERRVEH_enActTempErr,ERRVEH_enNoAction,ERRVEH_enFUSI},
{(uint8)ERRVEH_enArchPortStructure,0x1029,1,1,21,0,(uint8)ERRVEH_enVEHWrapper,0x00000800,LCFERR_REST_IMMEDIATELY,ERRVEH_enNoAction,ERRVEH_enNoAction,ERRVEH_enActTempErr,ERRVEH_enNoAction,ERRVEH_enFUSI},
{(uint8)ERRVEH_enArchPortStructure,0x102A,1,1,21,0,(uint8)ERRVEH_enVEHWrapper,0x00001000,LCFERR_REST_IMMEDIATELY,ERRVEH_enNoAction,ERRVEH_enNoAction,ERRVEH_enActTempErr,ERRVEH_enNoAction,ERRVEH_enFUSI},
{(uint8)ERRVEH_enArchPortStructure,0x102B,1,1,21,0,(uint8)ERRVEH_enVEHWrapper,0x00002000,LCFERR_REST_IMMEDIATELY,ERRVEH_enNoAction,ERRVEH_enNoAction,ERRVEH_enActTempErr,ERRVEH_enNoAction,ERRVEH_enFUSI},
{(uint8)ERRVEH_enArchPortStructure,0x102C,1,1,21,0,(uint8)ERRVEH_enVEHWrapper,0x00004000,LCFERR_REST_IMMEDIATELY,ERRVEH_enNoAction,ERRVEH_enNoAction,ERRVEH_enActTempErr,ERRVEH_enNoAction,ERRVEH_enFUSI},
{(uint8)ERRVEH_enArchPortStructure,0x102D,1,1,1,0,(uint8)ERRVEH_enVEHWrapper,0x1FFF0000,LCFERR_REST_IMMEDIATELY,ERRVEH_enNoAction,ERRVEH_enNoAction,ERRVEH_enActTempErr,ERRVEH_enNoAction,ERRVEH_enNoDemEvent},
{(uint8)ERRVEH_enArchPortStructure,0x102E,1,1,1,0,(uint8)ERRVEH_enVEHWrapper,0x20000000,LCFERR_REST_IMMEDIATELY,ERRVEH_enNoAction,ERRVEH_enNoAction,ERRVEH_enActRedAvail,ERRVEH_enNoAction,ERRVEH_enFUSI},
{(uint8)ERRVEH_enInputsDegradation,0x1030,1,1,1,0,(uint8)ERRVEH_enERRIOAllive,0x00000001,LCFERR_REST_IMMEDIATELY,ERRVEH_enNoAction,ERRVEH_enNoAction,ERRVEH_enActDegrDMCActRedAvail,ERRVEH_enNoAction,ERRVEH_enFUSI},
{(uint8)ERRVEH_enInputsDegradation,0x1031,1,1,1,0,(uint8)ERRVEH_enERRIOAllive,0x00000002,LCFERR_REST_IMMEDIATELY,ERRVEH_enNoAction,ERRVEH_enNoAction,ERRVEH_enActDegrDMCActRedAvail,ERRVEH_enNoAction,ERRVEH_enFUSI},
{(uint8)ERRVEH_enInputsDegradation,0x1032,1,1,1,0,(uint8)ERRVEH_enERRIOAllive,0x00000004,LCFERR_REST_IMMEDIATELY,ERRVEH_enNoAction,ERRVEH_enNoAction,ERRVEH_enActDegrDMCActRedAvail,ERRVEH_enNoAction,ERRVEH_enFUSI},
{(uint8)ERRVEH_enInternalErrors,0x1040,1,1,1,0,(uint8)ERRVEH_enTRJPLN,0x00000001,LCFERR_REST_IMMEDIATELY,ERRVEH_enNoAction,ERRVEH_enNoAction,ERRVEH_enActDegrDMC,ERRVEH_enNoAction,ERRVEH_enINTERNAL},
{(uint8)ERRVEH_enInternalErrors,0x1050,1,1,1,0,(uint8)ERRVEH_enTRJCTR,0x00000001,LCFERR_REST_IMMEDIATELY,ERRVEH_enNoAction,ERRVEH_enNoAction,ERRVEH_enActDegrDMC,ERRVEH_enNoAction,ERRVEH_enINTERNAL},
{(uint8)ERRVEH_enInternalErrors,0x1060,1,1,1,0,(uint8)ERRVEH_enLATDMC,0x00000001,LCFERR_REST_IMMEDIATELY,ERRVEH_enNoAction,ERRVEH_enNoAction,ERRVEH_enActDegrDMC,ERRVEH_enNoAction,ERRVEH_enINTERNAL},
{(uint8)ERRVEH_enInternalErrors,0x1070,1,1,1,0,(uint8)ERRVEH_enDRVMN,0x00000001,LCFERR_REST_IMMEDIATELY,ERRVEH_enNoAction,ERRVEH_enNoAction,ERRVEH_enActDegrDMC,ERRVEH_enNoAction,ERRVEH_enINTERNAL},
{(uint8)ERRVEH_enInputsDegradation,0x10D0,1,1,1,0,(uint8)ERRVEH_enSenTask,0x00000800,LCFERR_REST_IMMEDIATELY,ERRVEH_enNoAction,ERRVEH_enNoAction,ERRVEH_enActDegrDMC,ERRVEH_enNoAction,ERRVEH_enNoDemEvent}


};

/* Parameters */
#if ((defined PC_SIM) && (!defined CM_SIM))
volatile uint8 P_ERRIOVEH_EnableChecks_btf = 0x00u;
#else
volatile uint8 P_ERRIOVEH_EnableChecks_btf = 0xFFu;/* ERRIO_CHECK_ NORM = 0x01, VEHDYN = 0x02, VEHSIGADD = 0x04, VEHSIGMAIN = 0x08, SIGHEADER = 0x10 , ALLIVE = 0x20 */
#endif

/* Actions */
void ERRVEH_srNoAction(void)
{
    //Do nothing for this action
}

void ERRVEH_srActDegrDMC(void)
{
    SET_ERRIOVEH_ErrStateArray(LCF_ERRHNDL_LATDMC, LCF_IS_ERROR);
}

void ERRVEH_srActTempErr(void)
{
    /* Set state to Temp Error */
    if(pLcfVehProPorts != NULL)
    {
		SET_S_LCFSND_VehAlgoCompState(COMP_STATE_TEMPORARY_ERROR);
    }
}

void ERRVEH_srActPermErr(void)
{
    /* Set state to Temp Error */
    if(pLcfVehProPorts != NULL)
    {
		SET_S_LCFSND_VehAlgoCompState(COMP_STATE_PERMANENT_ERROR);
    }
}
 
void ERRVEH_srActRedAvail(void)
{
    /* Set state to Reduced Availability */
    if(pLcfVehProPorts != NULL)
    {
		SET_S_LCFSND_VehAlgoCompState(COMP_STATE_REDUCED_AVAILABILITY);
    }
}

void ERRVEH_srActDegrDMCActRedAvail(void)
{
    ERRVEH_srActDegrDMC();
	ERRVEH_srActRedAvail();
}
 

void ERRVEH_srActVehOutInvalid(void)
{
    /* Set state to Temp Error */
    if(pLcfVehProPorts != NULL)
    {
        if(pLcfVehProPorts->pLcfVehOutputData != NULL)
        {
			SET_S_LCFSND_VehOutSigStatus(AL_SIG_STATE_INVALID);
            /* L3D_ALGO_21733 : if an output is Invalid, then component state is TempError */
            ERRVEH_srActTempErr();
        }
    }
}

void ERRVEH_srActVeh2SenInvalid(void)
{
    /* Set state to Temp Error */
    if(pLcfVehProPorts != NULL)
    {
        if(pLcfVehProPorts->pLcfVehOutputToSenData != NULL)
        {
			SET_S_LCFSND_Veh2SenSigStatus(AL_SIG_STATE_INVALID);
            /* L3D_ALGO)21733 : if an output is Invalid, then component state is TempError */
            ERRVEH_srActTempErr();
        }
    }
}

void ERRVEH_srActVeh2IuCInvalid(void)
{
    /* Set state to Temp Error */
    if(pLcfVehProPorts != NULL)
    {
#if defined(LCF_IUC_USED) && (LCF_IUC_USED == 1)
/* Must not call this function if IUC is not used */
        if(pLcfVehProPorts->pLcfLaDmcSocToIuc != NULL)
        {
			SET_S_LCFSND_Soc2IucSigStatus(AL_SIG_STATE_INVALID);
            /* L3D_ALGO)21733 : if an output is Invalid, then component state is TempError */
            ERRVEH_srActTempErr();
        }
#endif
    }
}



void LCFERR_VehSetSilentEventStatus(uint16 event, uint8 status)
{
	/* QAF rule 3.9 : This initialization is redundant. The value of this object is never used before being modified */
    /* GeGr: Defensive programming */
    /* PRQA S 2981 1 */
	uint8 DemEvents = 0u;
	switch(event)
	{
		case LCF_VEH_FUSI_ERROR:
		{
			DemEvents = 1u;
			break;
		}
		case LCF_VEH_SERVICE_ERROR:
		{
			DemEvents = 2u;
			break;
		}
		case LCF_VEH_INTERNAL_ERROR:
		{
			DemEvents = 4u;
			break;
		}
		case LCF_VEH_BUS_DATA_ERROR:
		{
			DemEvents = 8u;
			break;
		}
		default:
		{
			DemEvents = 16u;
			break;
		}
	}
	if(status == (uint8)DEM_EVENT_STATUS_FAILED)
	{
		S_D_LCFERR_DemEvents_btf |= DemEvents;
	}
	else
	{
		S_D_LCFERR_DemEvents_btf &= ~DemEvents;
	}
}

void ERRVEH_CustomErrReaction(void)
{
#if LCFERR_VEH_SILENT == 1
	SET_S_LCFSND_VehAlgoCompState(0);
	SET_S_LCFSND_VehOutSigStatus(0);
	SET_S_LCFSND_Veh2SenSigStatus(0);
	SET_S_LCFSND_Soc2IucSigStatus(0);
#endif

}



#endif /* C_LCFERR_VehCustom_ */
