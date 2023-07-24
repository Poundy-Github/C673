/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 LCF

  MODULNAME:                 LCFERR_VehCustom.h

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.1 $


  ---*/ /*---
  CHANGES:                   $Log: LCFERR_VehCustom.h  $
  CHANGES:                   Revision 1.1 2020/03/25 13:44:32CET Craciun, Mihaela (uidl9730) (uidl9730) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/00_Projects/MFC431BD10/LCF/LCF_DPU/LCFERR/project.pj
  CHANGES:                   Revision 1.5 2019/11/26 13:47:50CET Grosu, George (uidl9584) 
  CHANGES:                   Bring changes from TA19 to trunk
  CHANGES:                   Revision 1.4 2019/04/10 04:08:50CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update LCF files for auxcodegen v4.0
  CHANGES:                   Revision 1.3 2019/03/24 09:16:23CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   1st check-in of files from AuxCodeGen 4.0
  CHANGES:                   Revision 1.8 2019/03/22 15:18:52CET Grosu, George (uidl9584) 
  CHANGES:                   review update
  CHANGES:                   Revision 1.7 2019/03/13 12:58:36CET Grosu, George (uidl9584) 
  CHANGES:                   Silent LCFERR
  CHANGES:                   Revision 1.6 2019/03/07 14:52:11CET Grosu, George (uidl9584) 
  CHANGES:                   Update trunk for LCFERR
  CHANGES:                   Revision 1.5 2019/02/24 17:21:59CET Grosu, George (uidl9584) 
  CHANGES:                   Update quality checks for all functions in veh
  CHANGES:                   Revision 1.4 2019/02/19 13:10:10CET Grosu, George (uidl9584) 
  CHANGES:                   add Intertask errors. Use algo signal names
  CHANGES:                   Revision 1.3 2018/09/14 16:16:17CEST Grosu, George (uidl9584) 
  CHANGES:                   Split naming for Error Handler
  CHANGES:                   Revision 1.2 2018/09/11 16:19:18CEST Grosu, George (uidl9584) 
  CHANGES:                   Update error handler
  CHANGES:                   Revision 1.1 2018/05/25 08:07:49CEST Grosu, George (uidl9584) 
  CHANGES:                   update LCFERR
**************************************************************************** */

/* avoid double inclusion */
#ifndef __LCFERR_VehCustom_H__
#define __LCFERR_VehCustom_H__


#include "lcf_cfg_custom.h"
#include "algo_glob.h"

#define LCFERR_VEH_SILENT (1)

#define C_ERRVEH_NumberOfDemEvents (ERRVEH_enDemEventsNumber)
#define C_ERRVEH_DemArraySize (ERRVEH_enDemArraySize)
#define C_ERRVEH_NumOfErrors (ERRVEH_enNumOfErrors)
#define C_ERRVEH_NumOfActions (ERRVEH_enActNumber)
/*  */
#define ERRVEH_MAX_CONSTANT_CYCLES  (2u)

/* ERRIO */
#define ERRIOVEH_CHECK_NORM        (0x01u)
#define ERRIOVEH_CHECK_VEHDYN      (0x02u)
#define ERRIOVEH_CHECK_VEHSIGADD   (0x04u)
#define ERRIOVEH_CHECK_VEHSIGMAIN  (0x08u)
#define ERRIOVEH_CHECK_SIGHEADER   (0x10u)
#define ERRIOVEH_CHECK_ALLIVE      (0x20u)
#define ERRIOVEH_CHECK_SIGRANGE    (0x40u)
#define ERRIOVEH_CHECK_VEHSIGBRAKE (0x80u)


#define ERRVEH_cui8NumberOfModules    (ERRVEH_enNoOfModules)
#define ERRVEH_cui8NoOfColumns           (32u)//32 bits for each signal


#if (LCFERR_VEH_SILENT == 1u)
#define SET_LCFVEH_DEM_EVENT_STATUS(event,status) LCFERR_VehSetSilentEventStatus((event), (status))
#else
#define SET_LCFVEH_DEM_EVENT_STATUS(event,status) pLcfVehServices->pfDem_SetEventStatus((event), (status))
#endif


#define ERRVEH_AFFtb pLCFERR_VehDbgData->D_LCFERR_FFtb 

/* Ring buffer */
#define S_ERRVEH_ErrBuff pLCFERR_VehDbgData->D_LCFERR_ErrBuff


#ifndef S_LCFSND_VehAlgoCompState
#if (LCFERR_VEH_SILENT == 1u)
#define S_LCFSND_VehAlgoCompState   pLCFERR_VehDbgData->D_LCFERR_AlgoCompState
#else
#define S_LCFSND_VehAlgoCompState   pLcfVehProPorts->pAlgoCompState->eCompState
#endif
#define GET_S_LCFSND_VehAlgoCompState() S_LCFSND_VehAlgoCompState
#define SET_S_LCFSND_VehAlgoCompState(val) S_LCFSND_VehAlgoCompState = (val)
#endif


#ifndef S_LCFSND_VehOutSigStatus
#if (LCFERR_VEH_SILENT == 1u)
#define S_LCFSND_VehOutSigStatus   pLCFERR_VehDbgData->D_LCFERR_VehOutSigStatus
#else
#define S_LCFSND_VehOutSigStatus   pLcfVehProPorts->pLcfVehOutputData->sSigHeader.eSigStatus
#endif
#define GET_S_LCFSND_VehOutSigStatus() S_LCFSND_VehOutSigStatus
#define SET_S_LCFSND_VehOutSigStatus(val) S_LCFSND_VehOutSigStatus = (val)
#endif

#ifndef S_LCFSND_Veh2SenSigStatus
#if (LCFERR_VEH_SILENT == 1u)
#define S_LCFSND_Veh2SenSigStatus   pLCFERR_VehDbgData->D_LCFERR_Veh2SenSigStatus
#else
#define S_LCFSND_Veh2SenSigStatus   pLcfVehProPorts->pLcfVehOutputToSenData->sSigHeader.eSigStatus
#endif
#define GET_S_LCFSND_Veh2SenSigStatus() S_LCFSND_Veh2SenSigStatus
#define SET_S_LCFSND_Veh2SenSigStatus(val) S_LCFSND_Veh2SenSigStatus = (val)
#endif

#ifndef S_LCFSND_Soc2IucSigStatus
#if (LCFERR_VEH_SILENT == 1u)
#define S_LCFSND_Soc2IucSigStatus   pLCFERR_VehDbgData->D_LCFERR_Soc2IucSigStatus
#else
#define S_LCFSND_Soc2IucSigStatus   pLcfVehProPorts->pLcfLaDmcSocToIuc->sSigHeader.eSigStatus
#endif
#define GET_S_LCFSND_Soc2IucSigStatus() S_LCFSND_Soc2IucSigStatus
#define SET_S_LCFSND_Soc2IucSigStatus(val) S_LCFSND_Soc2IucSigStatus = (val)
#endif

#ifndef S_D_LCFERR_DemEvents_btf
#define S_D_LCFERR_DemEvents_btf    pLCFERR_VehDbgData->D_LCFERR_DemEvents_btf
#define GET_S_D_LCFERR_DemEvents_btf() S_D_LCFERR_DemEvents_btf
#endif

#if (LCFERR_VEH_SILENT == 1u)

#ifndef SET_ERRIOVEH_ErrStateArray
#define SET_ERRIOVEH_ErrStateArray(i,status) pLCFERR_VehDbgData->D_ERRIOVEH_ErrStateArray[(i)] = (status)
#endif

#ifndef GET_ERRIOVEH_ErrStateArray
#define GET_ERRIOVEH_ErrStateArray(i) pLCFERR_VehDbgData->D_ERRIOVEH_ErrStateArray[(i)]
#endif

#endif//LCFERR_VEH_SILENT

/* Data Types */

/* Enum for Error Clusters */
typedef enum ERRVEH_enCluster
{

   ERRVEH_enInputsDegradation = (uint16)0,
   ERRVEH_enArchPortStructure,
   ERRVEH_enInternalErrors
} ERRVEH_enCluster_t;



/* Enum for action index used in ACT module */
typedef enum ERRVEH_enAction
{
    /* Order from this enum also gives the priority of the action. */
    /* The higher the position, the higher the priority. */
    /* e.g.: ERRVEH_enActDegrLKA = 1 has lower priority than ERRVEH_enActTempErr = 6 */
   ERRVEH_enNoAction = (uint8)0,
   ERRVEH_enActDegrDMC,
   ERRVEH_enActTempErr,
   ERRVEH_enActVehOutInv,
   ERRVEH_enActVeh2SenInv,
   ERRVEH_enActVeh2IuCInv,
   ERRVEH_enActPermErr,
   ERRVEH_enActRedAvail,
   ERRVEH_enActDegrDMCActRedAvail,
   ERRVEH_enActNumber
   
} ERRVEH_enAction_t;

typedef enum ERRVEH_enDemEvent
{
    ERRVEH_enFUSI = 0u,
    ERRVEH_enSERVICE,
    ERRVEH_enINTERNAL,
    ERRVEH_enBUS,
    ERRVEH_enDemEventsNumber,
    ERRVEH_enNoDemEvent,
    ERRVEH_enDemArraySize
} ERRVEH_enDemEvent_t;

typedef enum ERRVEH_enErrModules
{
    ERRVEH_enERRIOVeh = 0u,
    ERRVEH_enVEHWrapper,
    ERRVEH_enERRIOAllive,
    ERRVEH_enDRVMN,
    ERRVEH_enLATDMC,
    ERRVEH_enTRJCTR,
    ERRVEH_enTRJPLN,
	ERRVEH_enSenTask,
    ERRVEH_enNoOfModules
     
} ERRVEH_enErrModules_t;





typedef enum ERRVEH_enErrorList
{
    ERRVEH_enInputFailedDMC = 0u,
    ERRVEH_enNullPort,
    ERRVEH_enInputInitBCD,
    ERRVEH_enInputInitABD,
    ERRVEH_enInputInitCparDMC,
    ERRVEH_enInputInitCparKMC,
    ERRVEH_enInputInitGENInput,
    ERRVEH_enInputInitI2S,
    ERRVEH_enInputInitS2V,
    ERRVEH_enInputInitSenOut,
    ERRVEH_enInputInitVehDyn,
    ERRVEH_enInputInitVehPar,
    ERRVEH_enInputInitVehSig,
    ERRVEH_enInputInitVDyOffset,
    ERRVEH_enPortInvalid,
    ERRVEH_enWrongVersionNumber,
    ERRVEH_enFailedAlliveMC,
    ERRVEH_enFailedAlliveTS,
    ERRVEH_enFailedAlliveCC,
	ERRVEH_enTRJPLNInternal,
	ERRVEH_enTRJCTRInternal,
	ERRVEH_enDMCInternal,
	ERRVEH_enDRVMNInternal,
	ERRVEH_enSenErrorDMC,
    ERRVEH_enNumOfErrors    
} ERRVEH_enErrorList_t;

/* Enum for action index used in ACT module */
typedef enum ERRVEH_enFreezeFrame
{
   ERRVEH_enFFTsMon = (uint16)0,
   ERRVEH_enFFTsBcd,
   ERRVEH_enFFCnt,
   ERRVEH_enFFNumber
   
} ERRVEH_enFreezeFrame_t;

typedef uint8 uint1;//boolean



/* Actions */
void ERRVEH_srNoAction(void);
void ERRVEH_srActDegrDMC(void);
void ERRVEH_srActTempErr(void);
void ERRVEH_srActVehOutInvalid(void);
void ERRVEH_srActVeh2SenInvalid(void);
void ERRVEH_srActVeh2IuCInvalid(void);
void ERRVEH_srActPermErr(void);
void ERRVEH_srActRedAvail(void);
void ERRVEH_srActDegrDMCActRedAvail(void);
void LCFERR_VehSetSilentEventStatus(uint16 event, uint8 status);
void ERRVEH_CustomErrReaction(void);

/* Parameters */
extern volatile uint8 P_ERRIOVEH_EnableChecks_btf; /* ERRIO_CHECK_ NORM = 0x01, VEHDYN = 2, VEHSIGADD = 4, VEHSIGMAIN = 8, SIGHEADER = 16 */


#endif /* __LCFERR_SenCustom_H__ */
