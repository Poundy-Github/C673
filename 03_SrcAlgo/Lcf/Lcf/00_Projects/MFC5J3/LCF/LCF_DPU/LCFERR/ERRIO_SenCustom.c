/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 LCF (Lateral Control Functions)

  MODULNAME:                 LCFERR_SenCustom.c

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.8 $


  ---*/ /*---
  CHANGES:                   $Log: ERRIO_SenCustom.c  $
  CHANGES:                   Revision 1.8 2021/03/03 08:25:09CET Bi, Zhongyan (uib56412) (uib56412) 
  CHANGES:                   error handling update
  CHANGES:                   Revision 1.7 2021/02/25 09:21:32CET Bi, Zhongyan (uib56412) (uib56412) 
  CHANGES:                   error configure update
  CHANGES:                   Revision 1.6 2020/12/21 09:54:50CET Hu, Xiaohui02 (uib56746) (uib56746) 
  CHANGES:                   Update lcf error handling wrapper
  CHANGES:                   Revision 1.5 2020/12/16 05:45:01CET Hu, Xiaohui02 (uib56746) (uib56746) 
  CHANGES:                   Range check update
  CHANGES:                   Revision 1.4 2020/11/12 14:02:21CET Bi, Zhongyan (uib56412) (uib56412) 
  CHANGES:                   range check update
  CHANGES:                   Revision 1.3 2020/09/23 13:59:31CEST Tonofa, Vladimir (uic47530) (uic47530) 
  CHANGES:                   Update Overflow thresholds
  CHANGES:                   Revision 1.2 2020/08/26 08:22:01CEST Hu, Xiaohui02 (uib56746) (uib56746) 
  CHANGES:                   Update degradation functions to 0x0 for NORM check
  CHANGES:                   Revision 1.5 2020/08/25 05:43:45CEST Hu, Xiaohui02 (uib56746) (uib56746) 
  CHANGES:                   Update some degradation function to 0x0
  CHANGES:                   Revision 1.4 2019/11/26 15:23:42CET Grosu, George (uidl9584) 
  CHANGES:                   bring TA19 changes to trunk
  CHANGES:                   Revision 1.3 2019/05/16 13:40:33CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Remove LD port from wrappers
  CHANGES:                   Revision 1.2 2019/04/10 04:18:45CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update LCF files for auxcodegen v4.0
  CHANGES:                   Revision 1.3 2019/03/24 09:16:21CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   1st check-in of files from AuxCodeGen 4.0
  CHANGES:                   Revision 1.17 2019/03/22 15:18:50CET Grosu, George (uidl9584) 
  CHANGES:                   review update
  CHANGES:                   Revision 1.16 2019/03/13 12:58:46CET Grosu, George (uidl9584) 
  CHANGES:                   Silent LCFERR
  CHANGES:                   Revision 1.15 2019/03/07 14:52:09CET Grosu, George (uidl9584) 
  CHANGES:                   Update trunk for LCFERR
  CHANGES:                   Revision 1.14 2019/02/28 15:57:36CET Grosu, George (uidl9584) 
  CHANGES:                   Add DMC
  CHANGES:                   Revision 1.13 2019/02/27 15:36:50CET Grosu, George (uidl9584) 
  CHANGES:                   Add safety critical signals
  CHANGES:                   Revision 1.12 2019/02/24 18:01:31CET Grosu, George (uidl9584) 
  CHANGES:                   Update Quality tables
  CHANGES:                   Revision 1.11 2019/02/23 12:53:12CET Grosu, George (uidl9584) 
  CHANGES:                   Connect SEN and VEH error handlers
  CHANGES:                   Revision 1.10 2019/02/23 09:46:00CET Grosu, George (uidl9584) 
  CHANGES:                   Fix after module test
  CHANGES:                   Revision 1.9 2019/02/19 13:10:15CET Grosu, George (uidl9584) 
  CHANGES:                   add Intertask errors. Use algo signal names
  CHANGES:                   Revision 1.8 2019/01/31 09:17:07CET Grosu, George (uidl9584) 
  CHANGES:                   Add range checks
  CHANGES:                   Revision 1.7 2018/11/15 08:40:21CET Grosu, George (uidl9584) 
  CHANGES:                   ERR: Add Local Freze Frames for Allive checks
  CHANGES:                   ERR: Temporary: No Dem Event for aalive checks
  CHANGES:                   Revision 1.6 2018/10/31 15:40:57CET Grosu, George (uidl9584) 
  CHANGES:                   Remove cycle counter check for VehPar
  CHANGES:                   Revision 1.5 2018/09/14 16:16:14CEST Grosu, George (uidl9584) 
  CHANGES:                   Split naming for Error Handler
  CHANGES:                   Revision 1.4 2018/09/12 13:18:43CEST Grosu, George (uidl9584) 
  CHANGES:                   supress inputs with wrong state
  CHANGES:                   Revision 1.3 2018/08/05 18:08:19CEST Grosu, George (uidl9584) 
  CHANGES:                   Add debug signals
  CHANGES:                   Revision 1.2 2018/05/24 13:06:15CEST Grosu, George (uidl9584) 
  CHANGES:                   Update LCFERR
  CHANGES:                   Revision 1.1 2018/05/22 16:35:02CEST Grosu, George (uidl9584) 
  CHANGES:                   Reorder files

**************************************************************************** */
#ifndef ERRIO_SenCustom_H
#define ERRIO_SenCustom_H

#include "LCFSEN/LCFSEN_data.h"
#include "ERRIO_SenCustom.h"
#include "LCFERR/errio_sen.h"

//#ifndef C_ERRIO_SenCustom_
//#define C_ERRIO_SenCustom_


#define LCF_GET_SIGHEADER(p)   (((p) != NULL)?(&(p)->sSigHeader):(NULL))

/* Configuration arrays for each signal source */
ERRIO_ErrConfigData ERRIOSEN_ErrConfigNormData[] = {
/*  Signal,Rlvnt_fct,ErrCtr,Confirmed    */
{ LCF_IO_POS_HWAR,0x0,0,0},
{ LCF_IO_POS_DFSA,0x0,0,0},
{ LCF_IO_POS_DFSAR,0x0,0,0},
{ LCF_IO_POS_DSWT,0x0,0,0},
{ LCF_IO_POS_MTQ,0x0,0,0},
{ LCF_IO_POS_ESCS,0x0,0,0},
{ LCF_IO_POS_ESCA,0x0,0,0},
{ LCF_IO_POS_ABSS,0x0,0,0},
{ LCF_IO_POS_ABSA,0x0,0,0},
{ LCF_IO_POS_ACCS,0x0,0,0},
{ LCF_IO_POS_ACCA,0x0,0,0},
{ LCF_IO_POS_EBAS,0x0,0,0},
{ LCF_IO_POS_EBAA,0x0,0,0},
{ LCF_IO_POS_TBD,0x0,0,0},
{ LCF_IO_POS_DO,0x0,0,0},
{ LCF_IO_POS_TSL,0x0,0,0},
{ LCF_IO_POS_OSD,0x0,0,0},
{ LCF_IO_POS_USD,0x0,0,0},
{ LCF_IO_POS_BA,0x0,0,0},
{ LCF_IO_POS_TRL,0x0,0,0},
{ LCF_IO_POS_ETU,0x0,0,0},
{ LCF_IO_POS_ETA,0x0,0,0},
{ LCF_IO_POS_ETF,0x0,0,0},
{ LCF_IO_POS_EFS,0x0,0,0},
{ LCF_IO_POS_LKASW,0x0,0,0},
{ LCF_IO_POS_LKAM,0x0,0,0},
{ LCF_IO_POS_TJASW,0x0,0,0},
{ LCF_IO_POS_VAS,0x0,0,0},
{ LCF_IO_POS_LDWSW,0x0,0,0},
{ LCF_IO_POS_LDPSW,0x0,0,0},
{ LCF_IO_POS_RDWSW,0x0,0,0},
{ LCF_IO_POS_RDPSW,0x0,0,0},
{ LCF_IO_POS_LDWS,0x0,0,0},
{ LCF_IO_POS_LDPS,0x0,0,0},
{ LCF_IO_POS_RDPS,0x0,0,0},
{ LCF_IO_POS_OBSRL,0x0,0,0},
{ LCF_IO_POS_OFOVRL,0x0,0,0},
{ LCF_IO_POS_QFRL,0x0,0,0},
{ LCF_IO_POS_MSFRL,0x0,0,0},
{ LCF_IO_POS_OBSRR,0x0,0,0},
{ LCF_IO_POS_OFOVRR,0x0,0,0},
{ LCF_IO_POS_QFRR,0x0,0,0},
{ LCF_IO_POS_MSFRR,0x0,0,0},
{ LCF_IO_POS_ALCASW,0x0,0,0},
{ LCF_IO_POS_ALCAS,0x0,0,0},
{ LCF_IO_POS_ALCAM,0x0,0,0},
{ LCF_IO_POS_LCAAL,0x0,0,0},
{ LCF_IO_POS_BSDAL,0x0,0,0},
{ LCF_IO_POS_LCAWL,0x0,0,0},
{ LCF_IO_POS_BSDWL,0x0,0,0},
{ LCF_IO_POS_LCAAR,0x0,0,0},
{ LCF_IO_POS_BSDAR,0x0,0,0},
{ LCF_IO_POS_LCAWR,0x0,0,0},
{ LCF_IO_POS_BSDWR,0x0,0,0},
{ LCF_IO_POS_LDPOCS,0x0,0,0},
{ LCF_IO_POS_AOLCS,0x0,0,0},
{ LCF_IO_POS_STOD,0x0,0,0},
{ LCF_IO_POS_MRAX,0x0,0,0},
{ LCF_IO_POS_MRVX,0x0,0,0},
{ LCF_IO_POS_MRAY,0x0,0,0},
{ LCF_IO_POS_MRVY,0x0,0,0},
{ LCF_IO_POS_PPX,0x0,0,0},
{ LCF_IO_POS_PPY,0x0,0,0},
{ LCF_IO_POS_PPXSD,0x0,0,0},
{ LCF_IO_POS_PPYSD,0x0,0,0},
{ LCF_IO_POS_OBJQ,0x0,0,0},
{ LCF_IO_POS_OBJRCT,0x0,0,0},
{ LCF_IO_POS_OBJRMS,0x0,0,0},
{ LCF_IO_POS_DIMW,0x0,0,0},
{ LCF_IO_POS_SSRC,0x0,0,0},
{ LCF_IO_POS_TMST,0x0,0,0},
{ LCF_IO_POS_OBJREQ,0x0,0,0},
{ LCF_IO_POS_LPX,0x0,0,0},
{ LCF_IO_POS_LPY,0x0,0,0},
{ LCF_IO_POS_LRVX,0x0,0,0},
{ LCF_IO_POS_LRVY,0x0,0,0},
{ LCF_IO_POS_LRAX,0x0,0,0},
{ LCF_IO_POS_LRAY,0x0,0,0},
{ LCF_IO_POS_LQU,0x0,0,0},
{ LCF_IO_POS_LMS,0x0,0,0},
{ LCF_IO_POS_LOBJRCT,0x0,0,0},
{ LCF_IO_POS_LOBJTS,0x0,0,0}

};

ERRIO_ErrConfigData ERRIOSEN_ErrConfigVehDynData[]= {
/*  Signal,Rlvnt_fct,ErrCtr,Confirmed    */
{ VDY_SOUT_POS_VELOCITY,0xFFF,0,0},
{ VDY_SOUT_POS_ACCEL,0xFFF,0,0},
{ VDY_SOUT_POS_YAWRATE,0xFFF,0,0},
{ VDY_SOUT_POS_CURVE,0xFFF,0,0},
{ VDY_SOUT_POS_LATERALACCEL,0xFFF,0,0},
{ VDY_SOUT_POS_MOTIONSTATE,0x11,0,0}

};



ERRIO_ErrConfigData ERRIOSEN_ErrConfigVehSigAddData[] = {
/*  Signal,Rlvnt_fct,ErrCtr,Confirmed    */
{ VEH_SIG_ADD_TURN_SIGNAL,0x0,0,0},
{ VEH_SIG_ADD_ROAD_WHL_ANG_FR,0x0,0,0},
{ VEH_SIG_ADD_GAS_PEDAL_POS,0x0,0,0},
{ VEH_SIG_ADD_BRAKE_PEDAL_PRESSED,0x0,0,0},
{ VEH_SIG_ADD_SPEEDO_SPEED,0x0,0,0},
{ VEH_SIG_ADD_TRAILER_CON,0x0,0,0}

};

ERRIO_ErrConfigData ERRIOSEN_ErrConfigVehSigMainData[] = {
/*  Signal,Rlvnt_fct,ErrCtr,Confirmed    */
{  VDY_SIN_POS_GEAR,0x0,0,0}
};

ERRIO_ErrConfigData ERRIOSEN_ErrConfigVehSigBrakeData[] = {
/*  Signal,Rlvnt_fct,ErrCtr,Confirmed    */
{ VEH_SIG_BRAKE_TSC,0x0,0,0},
{ VEH_SIG_BRAKE_ABS,0x0,0,0}

};


uint8 ERRIOSEN_size_ErrConfigNormData       = sizeof(ERRIOSEN_ErrConfigNormData)/sizeof(ERRIOSEN_ErrConfigNormData[0]);
uint8 ERRIOSEN_size_ErrConfigVehDynData     = sizeof(ERRIOSEN_ErrConfigVehDynData)/sizeof(ERRIOSEN_ErrConfigVehDynData[0]);
uint8 ERRIOSEN_size_ErrConfigVehSigAddData  = sizeof(ERRIOSEN_ErrConfigVehSigAddData)/sizeof(ERRIOSEN_ErrConfigVehSigAddData[0]);
uint8 ERRIOSEN_size_ErrConfigVehSigMainData = sizeof(ERRIOSEN_ErrConfigVehSigMainData)/sizeof(ERRIOSEN_ErrConfigVehSigMainData[0]);
uint8 ERRIOSEN_size_ErrConfigVehSigBrakeData = sizeof(ERRIOSEN_ErrConfigVehSigBrakeData)/sizeof(ERRIOSEN_ErrConfigVehSigBrakeData[0]);

uint32 ERRIOSEN_RngChkFailed_btf = 0;


void ERRIOSEN_ChekSignalRanges(void);


/* ***********************************************************************
  @fn               ERRIOSEN_InputsCheck */ /*!

  @brief            check status of relevant inputs

  @description      

  @param[in]        pReqPorts required ports
  @param[out]       
  @return           void

  @pre              -
  @post             -
  **************************************************************************** */  
void ERRIOSEN_InputsCheck(const reqLcfSenPrtList_t *pReqPorts)
{
    /* QAF rule 3.9 : This initialization is redundant. The value of this object is never used before being modified */
    /* GeGr: Defensive programming */
    /* PRQA S 2981 1 */
    uint8 i=0u;
	static uint8 ui8CycleCntLD = 0u;
	static uint8 ui8CycleCntOD = 0u;
    
    /* Assume no error for all checked LCF functions */
    S_ERRSEN_ErrMatrix_btf[ERRSEN_enERRIOSen] = 0u;
	ERRIOSEN_RngChkFailed_btf = 0u;
	for(i=0u;i<8;i++)
	{
		ERRIOSEN_RngChkDbg_btf[i] = 0u;
	}
    
    if( (P_ERRIOSEN_EnableChecks_btf & ERRIOSEN_CHECK_ALLIVE) != 0u)
    {
        ERRIOSEN_CheckAllive();
    }
    
    /* Check state of signals coming from NORM */
    if( (P_ERRIOSEN_EnableChecks_btf & ERRIOSEN_CHECK_NORM) != 0u)
    {
        ERRIOSEN_CheckSignalSource(pReqPorts->pLcfInputData->State_nu, ERRIOSEN_ErrConfigNormData, sizeof(ERRIOSEN_ErrConfigNormData)/sizeof(ERRIOSEN_ErrConfigNormData[0]));
    }
    
    /* Check state of signals coming from VDY (VehDyn) */
    if( (P_ERRIOSEN_EnableChecks_btf & ERRIOSEN_CHECK_VEHDYN) != 0u)
    {
        ERRIOSEN_CheckSignalSource(pReqPorts->pVehDyn->State, ERRIOSEN_ErrConfigVehDynData, sizeof(ERRIOSEN_ErrConfigVehDynData)/sizeof(ERRIOSEN_ErrConfigVehDynData[0]));
    }
    
    /* Check state of signals coming from VDY (VehSigAdd) */
    if( (P_ERRIOSEN_EnableChecks_btf & ERRIOSEN_CHECK_VEHSIGADD) != 0u)
    {
        ERRIOSEN_CheckSignalSource(pReqPorts->pVehSig->VehSigAdd.State, ERRIOSEN_ErrConfigVehSigAddData, sizeof(ERRIOSEN_ErrConfigVehSigAddData)/sizeof(ERRIOSEN_ErrConfigVehSigAddData[0]));
    }
    
    /* Check state of signals coming from VDY (VehSigMain) */
    if( (P_ERRIOSEN_EnableChecks_btf & ERRIOSEN_CHECK_VEHSIGMAIN) != 0u)
    {
        ERRIOSEN_CheckSignalSource(pReqPorts->pVehSig->VehSigMain.State, ERRIOSEN_ErrConfigVehSigMainData, sizeof(ERRIOSEN_ErrConfigVehSigMainData)/sizeof(ERRIOSEN_ErrConfigVehSigMainData[0]));
    }
	
	/* Check state of signals coming from VDY (Brake) */
    if( (P_ERRIOSEN_EnableChecks_btf & ERRIOSEN_CHECK_VEHSIGBRAKE) != 0u)
    {
        ERRIOSEN_CheckSignalSource(pReqPorts->pVehSig->Brake.State, ERRIOSEN_ErrConfigVehSigBrakeData, sizeof(ERRIOSEN_ErrConfigVehSigBrakeData)/sizeof(ERRIOSEN_ErrConfigVehSigBrakeData[0]));
    }
	
        
    /* Check state of signals coming from LD/ABD (LD does not have an state array for its signals, but only one signal status) */
    if( (P_ERRIOSEN_EnableChecks_btf & ERRIOSEN_CHECK_SIGHEADER) != 0u)
    {
        if (pReqPorts->pAbdOutputData->sSigHeader.eSigStatus != (uint8)AL_SIG_STATE_OK)
        {
			ui8CycleCntLD++;
			if(ui8CycleCntLD >= 4u)
			{
				/* all functions use LD/ABD data */
				S_ERRSEN_ErrMatrix_btf[ERRSEN_enERRIOSen] |= LCF_RELEVANT_FOR_ALL;
				ui8CycleCntLD = 4u;
			}
        }
		else
		{
			ui8CycleCntLD = 0u;
		}
#if defined(LCF_CAMOBJ_USED) && (LCF_CAMOBJ_USED == 1)
		if ( (pReqPorts->pCamObjectList->sSigHeader.eSigStatus != (uint8)AL_SIG_STATE_OK) || (pReqPorts->pGenObjectList->sSigHeader.eSigStatus != (uint8)AL_SIG_STATE_OK) )
        {
			ui8CycleCntOD++;
			if(ui8CycleCntOD >= 4u)
			{
				/* Functions that needs object detection */
				S_ERRSEN_ErrMatrix_btf[ERRSEN_enERRIOSen] |= 0xD0u;
				ui8CycleCntOD = 4u;
			}
		}
		else
		{
			ui8CycleCntOD = 0u;
		}
#endif
    }
	
	/* Check signal ranges */
    if( (P_ERRIOSEN_EnableChecks_btf & ERRIOSEN_CHECK_SIGRANGE) != 0u)
    {
        ERRIOSEN_ChekSignalRanges();
       S_ERRSEN_ErrMatrix_btf[ERRSEN_enRangeCheck] = ERRIOSEN_RngChkFailed_btf;
    }
	
	
}

void ERRIOSEN_SenSetHeader(const reqLcfSenPrtList_t *pReqPorts)
{
    if (pReqPorts != NULL)
    {
        S_ERRIOSEN_sigHeader[ERRIOSEN_enSigHeadBCD].sigHead      = LCF_GET_SIGHEADER(pReqPorts->pBaseCtrlData);
        S_ERRIOSEN_sigHeader[ERRIOSEN_enSigHeadABD].sigHead     = LCF_GET_SIGHEADER(pReqPorts->pAbdOutputData);
#if defined(LCF_CAMOBJ_USED) && (LCF_CAMOBJ_USED == 1)
        S_ERRIOSEN_sigHeader[ERRIOSEN_enSigHeadCAMObj].sigHead  = LCF_GET_SIGHEADER(pReqPorts->pCamObjectList);
        S_ERRIOSEN_sigHeader[ERRIOSEN_enSigHeadGENObj].sigHead  = LCF_GET_SIGHEADER(pReqPorts->pGenObjectList);
#endif
        S_ERRIOSEN_sigHeader[ERRIOSEN_enSigHeadLcfIn].sigHead   = LCF_GET_SIGHEADER(pReqPorts->pLcfInputData);
#if defined(LCF_IUC_USED) && (LCF_IUC_USED == 1)
        S_ERRIOSEN_sigHeader[ERRIOSEN_enSigHeadI2S].sigHead     = LCF_GET_SIGHEADER(pReqPorts->pLcfLaDmcIucToSoc);
#endif
        S_ERRIOSEN_sigHeader[ERRIOSEN_enSigHeadV2S].sigHead     = LCF_GET_SIGHEADER(pReqPorts->pLcfSenInputFromVehData);
        S_ERRIOSEN_sigHeader[ERRIOSEN_enSigHeadVehOut].sigHead  = LCF_GET_SIGHEADER(pReqPorts->pLcfVehOutputData);
        S_ERRIOSEN_sigHeader[ERRIOSEN_enSigHeadVDY].sigHead     = LCF_GET_SIGHEADER(pReqPorts->pVehDyn);
        /* S_ERRIOSEN_sigHeader[ERRIOSEN_enSigHeadVPar].sigHead    = LCF_GET_SIGHEADER(pReqPorts->pVehPar); */
        S_ERRIOSEN_sigHeader[ERRIOSEN_enSigHeadVSig].sigHead    = LCF_GET_SIGHEADER(pReqPorts->pVehSig);
    }
    
}

void ERRIOSEN_ResetSigHdrConstCycles(void)
{
	/* ToDo: Review these values */
	/* Constant cycles */
    S_ERRIOSEN_sigHeader[ERRIOSEN_enSigHeadBCD].MaxConstantCycles = 4;
    S_ERRIOSEN_sigHeader[ERRIOSEN_enSigHeadABD].MaxConstantCycles = 4;
#if defined(LCF_CAMOBJ_USED) && (LCF_CAMOBJ_USED == 1)
    S_ERRIOSEN_sigHeader[ERRIOSEN_enSigHeadCAMObj].MaxConstantCycles = 7;
    S_ERRIOSEN_sigHeader[ERRIOSEN_enSigHeadGENObj].MaxConstantCycles = 7;
#endif
    S_ERRIOSEN_sigHeader[ERRIOSEN_enSigHeadLcfIn].MaxConstantCycles = 7;
#if defined(LCF_IUC_USED) && (LCF_IUC_USED == 1)
    S_ERRIOSEN_sigHeader[ERRIOSEN_enSigHeadI2S].MaxConstantCycles = 4;
#endif
    S_ERRIOSEN_sigHeader[ERRIOSEN_enSigHeadV2S].MaxConstantCycles = 4;
    S_ERRIOSEN_sigHeader[ERRIOSEN_enSigHeadVehOut].MaxConstantCycles = 4;
    S_ERRIOSEN_sigHeader[ERRIOSEN_enSigHeadVDY].MaxConstantCycles = 4;
    S_ERRIOSEN_sigHeader[ERRIOSEN_enSigHeadVSig].MaxConstantCycles = 4;
	
	/* Overflow threshold */
	S_ERRIOSEN_sigHeader[ERRIOSEN_enSigHeadBCD].MaxOvrflCycles = 100;
    S_ERRIOSEN_sigHeader[ERRIOSEN_enSigHeadABD].MaxOvrflCycles = 35;/*VlTo 23.09.20*/
#if defined(LCF_CAMOBJ_USED) && (LCF_CAMOBJ_USED == 1)
    S_ERRIOSEN_sigHeader[ERRIOSEN_enSigHeadCAMObj].MaxOvrflCycles = 35;/*VlTo 23.09.20*/
    S_ERRIOSEN_sigHeader[ERRIOSEN_enSigHeadGENObj].MaxOvrflCycles = 35;/*VlTo 23.09.20*/
#endif
    S_ERRIOSEN_sigHeader[ERRIOSEN_enSigHeadLcfIn].MaxOvrflCycles = 60;/*VlTo 23.09.20*/
#if defined(LCF_IUC_USED) && (LCF_IUC_USED == 1)
    S_ERRIOSEN_sigHeader[ERRIOSEN_enSigHeadI2S].MaxOvrflCycles = 60;/*VlTo 23.09.20*/
#endif
    S_ERRIOSEN_sigHeader[ERRIOSEN_enSigHeadV2S].MaxOvrflCycles = 60;/*VlTo 23.09.20*/
    S_ERRIOSEN_sigHeader[ERRIOSEN_enSigHeadVehOut].MaxOvrflCycles = 60;/*VlTo 23.09.20*/
    S_ERRIOSEN_sigHeader[ERRIOSEN_enSigHeadVDY].MaxOvrflCycles = 60;/*VlTo 23.09.20*/
    S_ERRIOSEN_sigHeader[ERRIOSEN_enSigHeadVSig].MaxOvrflCycles = 60;/*VlTo 23.09.20*/
    
}


void ERRIOSEN_ChekSignalRanges(void)
{
	/* Generated code from excel table */
	/* GeGr: The construction is designed to work with any datatype (generic), therefore explicit cast cannot be used */
	/* GeGr: code is generated for a large number of signals. Some have the maxmum range specified, therefore is ok to have unreachable code */
	/* PRQA S 1281, 1802, 1852, 1863, 2992, 3415, 3763, 3794, 4115, 4461, 4505, 4558 72 */
	ERRIOSEN_RANGE_CHECK(GET_S_DRMDAE_AbuseWarning_bool(), 0, 1, 0x46u, 3u, 134217728u)
	ERRIOSEN_RANGE_CHECK(GET_S_DRMDAE_SysWarning_nu(), 0, 9, 0x711u, 3u, 33554432u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_AccelPedalPos_nu(), 0, 100, 0x11u, 3u, 16u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_AccFRObjClassType_nu(), 0, 16, 0x10u, 2u, 32768u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_AccFRObjDetected_bool(), 0, 3, 0x10u, 2u, 32u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_AccFRObjID_nu(), 0, 255, 0x10u, 2u, 1048576u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_AccFRObjMeasState_nu(), 0, 8, 0x10u, 2u, 65536u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_AccFRObjPosX_met(), 0, 300, 0x10u, 2u, 1024u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_AccFRObjPosXStdDev_met(), -100, 100, 0x10u, 2u, 4096u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_AccFRObjPosY_met(), -25, 25, 0x10u, 2u, 2048u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_AccFRObjPosYStdDev_met(), -15, 15, 0x10u, 2u, 8192u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_AccFRObjQuality_perc(), 0, 128, 0x10u, 2u, 16384u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_AccFRObjRelAclX_mps2(), -84, 84, 0x10u, 2u, 64u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_AccFRObjRelAclY_mps2(), -84, 84, 0x10u, 2u, 256u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_AccFRObjRelVelX_mps(), -128, 150, 0x10u, 2u, 128u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_AccFRObjRelVelY_mps(), -128, 150, 0x10u, 2u, 512u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_AccFRObjSensorSource_btf(), 0, 65535, 0x10u, 2u, 262144u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_AccFRObjTStamp_usec(), 0, 4294967295, 0x10u, 2u, 524288u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_AccFRObjWidth_met(), 0, 41, 0x10u, 2u, 131072u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_ActiveStateABS_enum(), 0, 3, 0xF57u, 0u, 512u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_ActiveStateACC_enum(), 0, 3, 0xD0u, 0u, 8192u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_ActiveStateEBA_enum(), 0, 3, 0x10u, 0u, 2097152u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_ActiveStateESC_enum(), 0, 3, 0xF57u, 0u, 128u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_BrkPedlPressed_bool(), 0, 1, 0x6u, 3u, 32u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_BSD_ActiveLeft_nu(), 0, 1, 0x0u, 1u, 134217728u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_BSD_ActiveRight_nu(), 0, 1, 0x0u, 1u, 2147483648u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_CurrentGear_enum(), 0, 3, 0xF57u, 3u, 256u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_DangOcObjLeLn_nu(), 0, 4, 0x0u, 2u, 2097152u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_DangOcObjRiLn_nu(), 0, 4, 0x0u, 2u, 4194304u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_DoorOpen_bool(), 0, 1, 0xF57u, 0u, 8388608u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_DriverNotBuckledUp_bool(), 0, 1, 0xF57u, 0u, 134217728u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_EPS_ManualTrqActualVal_Nm(), -20, 20, 0xF57u, 0u, 16u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_LaDMC_Status_nu(), 0, 8, 0xF57u, 3u, 512u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_LatDmcStrAngReq_deg(), -720, 720, 0xF57u, 3u, 65536u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_LCA_ActiveLeft_nu(), 0, 1, 0x0u, 1u, 67108864u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_LCA_ActiveRight_nu(), 0, 1, 0x0u, 1u, 1073741824u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_LDPMode_nu(), 0, 255, 0x42u, 1u, 8192u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_LDPOCMode_nu(), 0, 255, 0x0u, 2u, 4u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_LDPOCSwitch_bool(), 0, 1, 0x0u, 1u, 2048u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_LDPSwitch_bool(), 0, 1, 0x42u, 1u, 256u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_LDWMode_nu(), 0, 255, 0x8u, 1u, 4096u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_LDWSwitch_bool(), 0, 1, 0x8u, 1u, 128u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_LKASwitch_nu(), 0, 1, 0x1u, 1u, 16u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_OversteeringDetected_bool(), 0, 1, 0x0u, 0u, 268435456u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_QuDangOcObjDtct_nu(), 0, 5, 0x0u, 2u, 8388608u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_RDPMode_nu(), 0, 255, 0x24u, 1u, 16384u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_RDPSwitch_bool(), 0, 1, 0x4u, 1u, 1024u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_RDWSwitch_bool(), 0, 1, 0x0u, 1u, 512u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_RollerBenchDetected_bool(), 0, 1, 0x0u, 0u, 4194304u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_SteerAngleEPS_deg(), -1000, 1000, 0xF57u, 0u, 4u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_SteerWAngle_deg(), -1000, 1000, 0xFFFu, 0u, 1u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_SteerWAngleRate_degps(), -1016, 1016, 0xFFFu, 0u, 2u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_SystemStateABS_enum(), 0, 3, 0xFFFu, 0u, 256u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_SystemStateACC_enum(), 0, 3, 0xD0u, 0u, 4096u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_SystemStateEBA_enum(), 0, 3, 0x10u, 0u, 1048576u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_SystemStateESC_enum(), 0, 3, 0xFFFu, 0u, 64u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_TJASwitch_nu(), 0, 1, 0x10u, 1u, 32u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_TrailerPresent_bool(), 0, 1, 0x0u, 3u, 128u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_TurnSignalLeverHold_bool(), 0, 1, 0x611u, 0u, 33554432u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_TurnSignalState_enum(), 0, 4, 0xFFFu, 3u, 4u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_UndersteeringDetected_bool(), 0, 1, 0x0u, 0u, 536870912u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_VDy_VehVelocity_kph(), -20, 300, 0xFFFu, 3u, 64u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_VehAclX_mps2(), -20, 20, 0xFFFu, 2u, 536870912u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_VehAclY_mps2(), -20, 20, 0xFFFu, 3u, 1u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_VehCrv_1pm(), -0.5, 0.5, 0xFFFu, 2u, 2147483648u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_VehMotionState_enum(), 0, 3, 0x11u, 3u, 2u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_VehReadyToStart_bool(), 0, 1, 0x0u, 0u, 67108864u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_VehVelX_mps(), -20, 210, 0xFFFu, 2u, 268435456u)
	ERRIOSEN_RANGE_CHECK(GET_S_LCFRCV_VehYawRate_rps(), -3, 3, 0x0u, 2u, 1073741824u)
	ERRIOSEN_RANGE_CHECK(GET_S_TCTCLM_Limiter_TgtCrv_1pm(), -0.15, 0.15, 0xF57u, 3u, 4096u)
	ERRIOSEN_RANGE_CHECK(GET_S_TCTCLM_QuServTrajCtr_nu(), 0, 255, 0xF57u, 4u, 262144u)


}



#endif /* C_ERRIO_SenCustom_ */
