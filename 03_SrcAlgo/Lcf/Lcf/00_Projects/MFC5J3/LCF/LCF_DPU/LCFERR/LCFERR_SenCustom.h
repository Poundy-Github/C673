/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 LCF

  MODULNAME:                 LCFERR_SenCustom.h

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.2 $


  ---*/ /*---
  CHANGES:                   $Log: LCFERR_SenCustom.h  $
  CHANGES:                   Revision 1.2 2020/08/26 08:24:06CEST Hu, Xiaohui02 (uib56746) (uib56746) 
  CHANGES:                   Update LCFERR_SEN_SILENT=0
  CHANGES:                   Revision 1.1 2020/03/25 13:44:31CET Craciun, Mihaela (uidl9730) (uidl9730) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/00_Projects/MFC431BD10/LCF/LCF_DPU/LCFERR/project.pj
  CHANGES:                   Revision 1.6 2020/01/14 11:36:34CET Grosu, George (uidl9584) 
  CHANGES:                   adapt ALGO_FUSI_DEBOUNCE_TIME
  CHANGES:                   fix some qaf findings
  CHANGES:                   Revision 1.5 2019/11/26 13:47:49CET Grosu, George (uidl9584) 
  CHANGES:                   Bring changes from TA19 to trunk
  CHANGES:                   Revision 1.4 2019/04/10 04:08:49CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update LCF files for auxcodegen v4.0
  CHANGES:                   Revision 1.3 2019/03/24 09:16:23CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   1st check-in of files from AuxCodeGen 4.0
  CHANGES:                   Revision 1.13 2019/03/22 15:18:50CET Grosu, George (uidl9584) 
  CHANGES:                   review update
  CHANGES:                   Revision 1.12 2019/03/15 11:17:44CET Grosu, George (uidl9584) 
  CHANGES:                   drop _names.h
  CHANGES:                   Revision 1.11 2019/03/13 12:58:45CET Grosu, George (uidl9584) 
  CHANGES:                   Silent LCFERR
  CHANGES:                   Revision 1.10 2019/02/19 13:10:15CET Grosu, George (uidl9584) 
  CHANGES:                   add Intertask errors. Use algo signal names
  CHANGES:                   Revision 1.9 2019/02/04 16:40:40CET Grosu, George (uidl9584) 
  CHANGES:                   Update LCF_ERR tables
  CHANGES:                   Revision 1.8 2019/01/31 09:17:07CET Grosu, George (uidl9584) 
  CHANGES:                   Add range checks
  CHANGES:                   Revision 1.7 2018/11/15 08:40:20CET Grosu, George (uidl9584) 
  CHANGES:                   ERR: Add Local Freze Frames for Allive checks
  CHANGES:                   ERR: Temporary: No Dem Event for aalive checks
  CHANGES:                   Revision 1.6 2018/09/14 16:16:15CEST Grosu, George (uidl9584) 
  CHANGES:                   Split naming for Error Handler
  CHANGES:                   Revision 1.5 2018/09/11 16:19:19CEST Grosu, George (uidl9584) 
  CHANGES:                   Update error handler
  CHANGES:                   Revision 1.4 2018/08/05 18:08:21CEST Grosu, George (uidl9584) 
  CHANGES:                   Add debug signals
  CHANGES:                   Revision 1.3 2018/05/25 08:07:50CEST Grosu, George (uidl9584) 
  CHANGES:                   update LCFERR
  CHANGES:                   Revision 1.2 2018/05/24 13:06:16CEST Grosu, George (uidl9584) 
  CHANGES:                   Update LCFERR
  CHANGES:                   Revision 1.1 2018/05/22 16:35:03CEST Grosu, George (uidl9584) 
  CHANGES:                   Reorder files
**************************************************************************** */

/* avoid double inclusion */
#ifndef __LCFERR_SenCustom_H__
#define __LCFERR_SenCustom_H__

#include "lcf_cfg_custom.h"
#include "algo_glob.h"

#define LCFERR_SEN_SILENT (0u)

#define C_ERRSEN_NumberOfDemEvents (ERRSEN_enDemEventsNumber)
#define C_ERRSEN_DemArraySize (ERRSEN_enDemArraySize)
#define C_ERRSEN_NumOfErrors (ERRSEN_enNumOfErrors)
#define C_ERRSEN_NumOfActions (ERRSEN_enActNumber)
/*  */
#define ERRSEN_MAX_CONSTANT_CYCLES  (7u)

/* ERRIO */
#define ERRIOSEN_CHECK_NORM        (0x01u)
#define ERRIOSEN_CHECK_VEHDYN      (0x02u)
#define ERRIOSEN_CHECK_VEHSIGADD   (0x04u)
#define ERRIOSEN_CHECK_VEHSIGMAIN  (0x08u)
#define ERRIOSEN_CHECK_SIGHEADER   (0x10u)
#define ERRIOSEN_CHECK_ALLIVE      (0x20u)
#define ERRIOSEN_CHECK_SIGRANGE    (0x40u)
#define ERRIOSEN_CHECK_VEHSIGBRAKE (0x80u)



#define ERRSEN_cui8NumberOfModules    (ERRSEN_enNoOfModules)
#define ERRSEN_cui8NoOfColumns           (32u)//32 bits for each signal



#if (LCFERR_SEN_SILENT == 1u)
#define SET_LCFSEN_DEM_EVENT_STATUS(event,status) LCFERR_SenSetSilentEventStatus((event), (status))
#else
#define SET_LCFSEN_DEM_EVENT_STATUS(event,status) pLcfSenServices->pfDem_SetEventStatus((event), (status))
#endif
#define ERRSEN_AFFtb pLCFERR_SenDbgData->D_LCFERR_FFtb 


#ifndef S_LCFSND_SenAlgoCompState
#if (LCFERR_SEN_SILENT == 1u)
#define S_LCFSND_SenAlgoCompState   pLCFERR_SenDbgData->D_LCFERR_AlgoCompState
#else
#define S_LCFSND_SenAlgoCompState   pLcfSenProPorts->pAlgoCompState->eCompState
#endif
#define GET_S_LCFSND_SenAlgoCompState() S_LCFSND_SenAlgoCompState
#define SET_S_LCFSND_SenAlgoCompState(val) S_LCFSND_SenAlgoCompState = (val)
#endif

#ifndef S_LCFSND_SenOutSigStatus
#if (LCFERR_SEN_SILENT == 1u)
#define S_LCFSND_SenOutSigStatus   pLCFERR_SenDbgData->D_LCFERR_SenOutSigStatus
#else
#define S_LCFSND_SenOutSigStatus   pLcfSenProPorts->pLcfSenOutputData->sSigHeader.eSigStatus
#endif
#define GET_S_LCFSND_SenOutSigStatus() S_LCFSND_SenOutSigStatus
#define SET_S_LCFSND_SenOutSigStatus(val) S_LCFSND_SenOutSigStatus = (val)
#endif

#ifndef S_LCFSND_Sen2VehSigStatus
#if (LCFERR_SEN_SILENT == 1u)
#define S_LCFSND_Sen2VehSigStatus   pLCFERR_SenDbgData->D_LCFERR_Sen2VehSigStatus
#else
#define S_LCFSND_Sen2VehSigStatus   pLcfSenProPorts->pLcfSenOutputToVehData->sSigHeader.eSigStatus
#endif
#define GET_S_LCFSND_Sen2VehSigStatus() S_LCFSND_Sen2VehSigStatus
#define SET_S_LCFSND_Sen2VehSigStatus(val) S_LCFSND_Sen2VehSigStatus = (val)
#endif


#ifndef S_D_LCFERR_DemEvents_btf
#define S_D_LCFERR_DemEvents_btf    pLCFERR_SenDbgData->D_LCFERR_DemEvents_btf
#define GET_S_D_LCFERR_DemEvents_btf() S_D_LCFERR_DemEvents_btf
#endif

#if (LCFERR_SEN_SILENT == 1u)

#ifndef SET_ERRIOSEN_ErrStateArray
#define SET_ERRIOSEN_ErrStateArray(i,status) pLCFERR_SenDbgData->D_ERRIOSEN_ErrStateArray[(i)] = (status)
#endif

#ifndef GET_ERRIOSEN_ErrStateArray
#define GET_ERRIOSEN_ErrStateArray(i) pLCFERR_SenDbgData->D_ERRIOSEN_ErrStateArray[(i)]
#endif

#endif//LCFERR_SEN_SILENT

/* Ring buffer */
#define S_ERRSEN_ErrBuff pLCFERR_SenDbgData->D_LCFERR_ErrBuff


/* Data Types */

/* Enum for Error Clusters */
typedef enum ERRSEN_enCluster
{

   ERRSEN_enInputsDegradation = (uint16)0,
   ERRSEN_enRangeCheckFailure,
   ERRSEN_enArchPortStructure,
   ERRSEN_enInternalErrors
} ERRSEN_enCluster_t;




/* Enum for action index used in ACT module */
typedef enum ERRSEN_enAction
{
    /* Order from this enum also gives the priority of the action. */
    /* The higher the position, the higher the priority. */
    /* e.g.: ERRSEN_enActDegrLKA = 1 has lower priority than ERRSEN_enActTempErr = 6 */
   ERRSEN_enNoAction = (uint16)0,
   ERRSEN_enActDegrTJA_LC,
   ERRSEN_enActDegrLDP,
   ERRSEN_enActDegrRDP,
   ERRSEN_enActDegrLDW,
   ERRSEN_enActDegrTJA_OF,
   ERRSEN_enActDegrRDW,
   ERRSEN_enActDegrLDPOC,
   ERRSEN_enActDegrLDWOC,
   ERRSEN_enActDegrALCA,
   ERRSEN_enActDegrSALC,
   ERRSEN_enActDegrAOLC,
   ERRSEN_enActDegrALL,
   ERRSEN_enActTempErr,
   ERRSEN_enActSenOutInv,
   ERRSEN_enActSen2VehInv,
   ERRSEN_enActPermErr,
   ERRSEN_enActRedAvail,
   ERRSEN_enActDegrALLActRedAvail,
   ERRSEN_enActNumber
   
} ERRSEN_enAction_t;

typedef enum ERRSEN_enDemEvent
{
    ERRSEN_enFUSI = 0u,
    ERRSEN_enSERVICE,
    ERRSEN_enINTERNAL,
    ERRSEN_enBUS,
    ERRSEN_enDemEventsNumber,
    ERRSEN_enNoDemEvent,
    ERRSEN_enDemArraySize
} ERRSEN_enDemEvent_t;

typedef enum ERRSEN_enErrModules
{
    ERRSEN_enERRIOSen = 0u,
	ERRSEN_enRangeCheck,
    ERRSEN_enSENWrapper,
    ERRSEN_enERRIOAllive,
    ERRSEN_enABPR,
    ERRSEN_enCTRSC,
    ERRSEN_enLDPOCSA,
    ERRSEN_enLDPSA,
    ERRSEN_enMDCTR,
    ERRSEN_enODPR,
    ERRSEN_enRDPSA,
    ERRSEN_enTJASA,
    ERRSEN_enVDPR,
	ERRSEN_enVehTask,
    ERRSEN_enNoOfModules
     
} ERRSEN_enErrModules_t;





typedef enum ERRSEN_enErrorList
{
    ERRSEN_enInputFailedTJA_LC = 0,
    ERRSEN_enInputFailedLDP,
    ERRSEN_enInputFailedRDP,
    ERRSEN_enInputFailedLDW,
    ERRSEN_enInputFailedTJA_OF,
	ERRSEN_enInputFailedRDW,
	ERRSEN_enInputFailedLDPOC,
	ERRSEN_enInputFailedLDWOC,
	ERRSEN_enInputFailedALCA,
	ERRSEN_enInputFailedSALC,
	ERRSEN_enInputFailedAOLC,
	ERRSEN_enRangeFailedTJA_LC,
	ERRSEN_enRangeFailedLDP,
	ERRSEN_enRangeFailedRDP,
	ERRSEN_enRangeFailedLDW,
	ERRSEN_enRangeFailedTJA_OF,
	ERRSEN_enRangeFailedRDW,
	ERRSEN_enRangeFailedLDPOC,
	ERRSEN_enRangeFailedLDWOC,
	ERRSEN_enRangeFailedALCA,
	ERRSEN_enRangeFailedSALC,
	ERRSEN_enRangeFailedAOLC,
    ERRSEN_enNullPort,
    ERRSEN_enInputInitBCD,
    ERRSEN_enInputInitABD,
    ERRSEN_enInputInitCAM,
    ERRSEN_enInputInitCparLDP,
    ERRSEN_enInputInitCparLKA,
    ERRSEN_enInputInitGENObj,
    ERRSEN_enInputInitGENInput,
    ERRSEN_enInputInitI2S,
    ERRSEN_enInputInitV2S,
    ERRSEN_enInputInitVehOut,
    ERRSEN_enInputInitVehDyn,
    ERRSEN_enInputInitVehPar,
    ERRSEN_enInputInitVehSig,
    ERRSEN_enPortInvalid,
    ERRSEN_enWrongVersionNumber,
    ERRSEN_enFailedAlliveMC,
    ERRSEN_enFailedAlliveTS,
    ERRSEN_enFailedAlliveCC,
	ERRSEN_enAPBRInternal,
	ERRSEN_enCTRSCInternal,
	ERRSEN_enLDPOCSAInternal,
	ERRSEN_enLDPSAInternal,
	ERRSEN_enMDCTRInternal,
	ERRSEN_enODPRInternal,
	ERRSEN_enRDPSAInternal,
	ERRSEN_enTJASAInternal,
	ERRSEN_enVDPRInternal,
	ERRSEN_enVehErrorTJA_LC,
	ERRSEN_enVehErrorLDP,
	ERRSEN_enVehErrorRDP,
	ERRSEN_enVehErrorLDW,
	ERRSEN_enVehErrorTJA_OF,
	ERRSEN_enVehErrorRDW,
	ERRSEN_enVehErrorLDPOC,
	ERRSEN_enVehErrorLDWOC,
	ERRSEN_enVehErrorALCA,
	ERRSEN_enVehErrorSALC,
	ERRSEN_enVehErrorAOLC,
    ERRSEN_enNumOfErrors    
} ERRSEN_enErrorList_t;

/* Enum for action index used in ACT module */
typedef enum ERRSEN_enFreezeFrame
{
   ERRSEN_enFFTsMon = (uint16)0,
   ERRSEN_enFFTsBcd,
   ERRSEN_enFFCnt,
   ERRSEN_enFFNumber
   
} ERRSEN_enFreezeFrame_t;


typedef uint8 uint1;//boolean


/* Actions */
void ERRSEN_srNoAction(void);
void ERRSEN_srActDegrTJA_LC(void);
void ERRSEN_srActDegrLDP(void);
void ERRSEN_srActDegrRDP(void);
void ERRSEN_srActDegrLDW(void);
void ERRSEN_srActDegrTJA_OF(void);
void ERRSEN_srActDegrRDW(void);
void ERRSEN_srActDegrLDPOC(void);
void ERRSEN_srActDegrLDWOC(void);
void ERRSEN_srActDegrALCA(void);
void ERRSEN_srActDegrSALC(void);
void ERRSEN_srActDegrAOLC(void);
void ERRSEN_srActDegrALL(void);
void ERRSEN_srActTempErr(void);
void ERRSEN_srActRedAvail(void);
void ERRSEN_srActDegrALLActRedAvail(void);
void ERRSEN_srActSenOutInvalid(void);
void ERRSEN_srActSen2VehInvalid(void);
void ERRSEN_srActPermErr(void);
void LCFERR_SenSetSilentEventStatus(uint16 event, uint8 status);
void ERRSEN_CustomErrReaction(void);

/* Parameters */
extern volatile uint8 P_ERRIOSEN_EnableChecks_btf; /* ERRIO_CHECK_ NORM = 0x01, VEHDYN = 2, VEHSIGADD = 4, VEHSIGMAIN = 8, SIGHEADER = 16 */


#endif /* __LCFERR_SenCustom_H__ */
