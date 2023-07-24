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

  VERSION:                   $Revision: 1.3 $


  ---*/ /*---
  CHANGES:                   $Log: ERRIO_VehCustom.c  $
  CHANGES:                   Revision 1.3 2020/11/12 14:07:11CET Bi, Zhongyan (uib56412) (uib56412) 
  CHANGES:                   range check update
  CHANGES:                   Revision 1.2 2020/06/11 12:37:38CEST Grosu, George (uidl9584) 
  CHANGES:                   Remove checks for VehPar because parameters must not be checked for allive.
  CHANGES:                   Revision 1.1 2020/03/25 13:44:31CET Craciun, Mihaela (uidl9730) (uidl9730) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/00_Projects/MFC431BD10/LCF/LCF_DPU/LCFERR/project.pj
  CHANGES:                   Revision 1.4 2019/11/26 15:23:42CET Grosu, George (uidl9584) 
  CHANGES:                   bring TA19 changes to trunk
  CHANGES:                   Revision 1.3 2019/05/16 13:40:34CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Remove LD port from wrappers
  CHANGES:                   Revision 1.2 2019/04/10 04:18:46CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update LCF files for auxcodegen v4.0
  CHANGES:                   Revision 1.3 2019/03/24 09:16:22CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   1st check-in of files from AuxCodeGen 4.0
  CHANGES:                   Revision 1.13 2019/03/22 15:18:51CET Grosu, George (uidl9584) 
  CHANGES:                   review update
  CHANGES:                   Revision 1.12 2019/03/13 12:58:36CET Grosu, George (uidl9584) 
  CHANGES:                   Silent LCFERR
  CHANGES:                   Revision 1.11 2019/03/07 14:52:10CET Grosu, George (uidl9584) 
  CHANGES:                   Update trunk for LCFERR
  CHANGES:                   Revision 1.10 2019/02/27 15:25:52CET Grosu, George (uidl9584) 
  CHANGES:                   Add safety critical signals
  CHANGES:                   Revision 1.9 2019/02/25 15:29:30CET Grosu, George (uidl9584) 
  CHANGES:                   Update used signals for range check
  CHANGES:                   Revision 1.8 2019/02/24 17:21:57CET Grosu, George (uidl9584) 
  CHANGES:                   Update quality checks for all functions in veh
  CHANGES:                   Revision 1.7 2019/02/23 12:53:12CET Grosu, George (uidl9584) 
  CHANGES:                   Connect SEN and VEH error handlers
  CHANGES:                   Revision 1.6 2019/02/23 09:54:16CET Grosu, George (uidl9584) 
  CHANGES:                   Fix after module test
  CHANGES:                   Revision 1.5 2019/02/19 13:10:10CET Grosu, George (uidl9584) 
  CHANGES:                   add Intertask errors. Use algo signal names
  CHANGES:                   Revision 1.4 2018/09/14 16:16:16CEST Grosu, George (uidl9584) 
  CHANGES:                   Split naming for Error Handler
  CHANGES:                   Revision 1.3 2018/09/12 13:17:49CEST Grosu, George (uidl9584) 
  CHANGES:                   supress inputs with wrong state
  CHANGES:                   Revision 1.2 2018/05/25 11:57:30CEST Grosu, George (uidl9584) 
  CHANGES:                   Resolve compiler errors
  CHANGES:                   Revision 1.1 2018/05/25 08:07:49CEST Grosu, George (uidl9584) 
  CHANGES:                   update LCFERR


**************************************************************************** */

#ifndef ERRIO_VehCustom_H
#define ERRIO_VehCustom_H

#include "LCFVEH/LCFVEH_data.h"
#include "ERRIO_VehCustom.h"

#define LCF_GET_SIGHEADER(p)   (((p) != NULL)?(&(p)->sSigHeader):(NULL))

/* Configuration arrays for each signal source */
ERRIO_ErrConfigData ERRIOVEH_ErrConfigNormData[] = {
/*  Signal,Rlvnt_fct,ErrCtr,Confirmed    */
{ LCF_IO_POS_HWAR,0xFFF,0,0},
{ LCF_IO_POS_DFSA,0xF57,0,0},
{ LCF_IO_POS_DFSAR,0xF57,0,0},
{ LCF_IO_POS_DSWT,0xF57,0,0},
{ LCF_IO_POS_MTQ,0xF57,0,0},
{ LCF_IO_POS_ESCS,0xFFF,0,0},
{ LCF_IO_POS_ESCA,0xF57,0,0},
{ LCF_IO_POS_ABSS,0xFFF,0,0},
{ LCF_IO_POS_ABSA,0xF57,0,0},
{ LCF_IO_POS_ACCS,0x10,0,0},
{ LCF_IO_POS_ACCA,0x10,0,0},
{ LCF_IO_POS_EBAS,0x10,0,0},
{ LCF_IO_POS_EBAA,0x10,0,0},
{ LCF_IO_POS_TBD,0xFF,0,0},
{ LCF_IO_POS_DO,0xF57,0,0},
{ LCF_IO_POS_TSL,0x611,0,0},
{ LCF_IO_POS_OSD,0xF57,0,0},
{ LCF_IO_POS_USD,0xF57,0,0},
{ LCF_IO_POS_BA,0xF57,0,0},
{ LCF_IO_POS_TRL,0xF57,0,0},
{ LCF_IO_POS_ETU,0xF57,0,0},
{ LCF_IO_POS_ETA,0xF57,0,0},
{ LCF_IO_POS_ETF,0xF57,0,0},
{ LCF_IO_POS_EFS,0xF57,0,0},
{ LCF_IO_POS_ED,0xF57,0,0},
{ LCF_IO_POS_LKASW,0x1,0,0},
{ LCF_IO_POS_LKAM,0x1,0,0},
{ LCF_IO_POS_TJASW,0x10,0,0},
{ LCF_IO_POS_VAS,0xA8,0,0},
{ LCF_IO_POS_LDWSW,0x8,0,0},
{ LCF_IO_POS_LDPSW,0x42,0,0},
{ LCF_IO_POS_RDWSW,0x20,0,0},
{ LCF_IO_POS_RDPSW,0x4,0,0},
{ LCF_IO_POS_LDWS,0x8,0,0},
{ LCF_IO_POS_LDPS,0x42,0,0},
{ LCF_IO_POS_RDPS,0x24,0,0},
{ LCF_IO_POS_OBSRL,0x3C0,0,0},
{ LCF_IO_POS_OFOVRL,0x3C0,0,0},
{ LCF_IO_POS_QFRL,0x3C0,0,0},
{ LCF_IO_POS_MSFRL,0x3C0,0,0},
{ LCF_IO_POS_OBSRR,0x3C0,0,0},
{ LCF_IO_POS_OFOVRR,0x3C0,0,0},
{ LCF_IO_POS_QFRR,0x3C0,0,0},
{ LCF_IO_POS_MSFRR,0x3C0,0,0},
{ LCF_IO_POS_ALCASW,0x100,0,0},
{ LCF_IO_POS_ALCAS,0x100,0,0},
{ LCF_IO_POS_ALCAM,0x100,0,0},
{ LCF_IO_POS_LCAAL,0x3D0,0,0},
{ LCF_IO_POS_BSDAL,0x3D0,0,0},
{ LCF_IO_POS_LCAWL,0x3C0,0,0},
{ LCF_IO_POS_BSDWL,0x3C0,0,0},
{ LCF_IO_POS_LCAAR,0x3C0,0,0},
{ LCF_IO_POS_BSDAR,0x3C0,0,0},
{ LCF_IO_POS_LCAWR,0x3C0,0,0},
{ LCF_IO_POS_BSDWR,0x3C0,0,0},
{ LCF_IO_POS_LDPOCS,0x40,0,0},
{ LCF_IO_POS_AOLCS,0x400,0,0},
{ LCF_IO_POS_STOD,0x10,0,0},
{ LCF_IO_POS_MRAX,0x10,0,0},
{ LCF_IO_POS_MRVX,0x10,0,0},
{ LCF_IO_POS_MRAY,0x10,0,0},
{ LCF_IO_POS_MRVY,0x10,0,0},
{ LCF_IO_POS_PPX,0x10,0,0},
{ LCF_IO_POS_PPY,0x10,0,0},
{ LCF_IO_POS_PPXSD,0x10,0,0},
{ LCF_IO_POS_PPYSD,0x10,0,0},
{ LCF_IO_POS_OBJQ,0x10,0,0},
{ LCF_IO_POS_OBJRCT,0x10,0,0},
{ LCF_IO_POS_OBJRMS,0x10,0,0},
{ LCF_IO_POS_DIMW,0x10,0,0},
{ LCF_IO_POS_SSRC,0x10,0,0},
{ LCF_IO_POS_TMST,0x10,0,0},
{ LCF_IO_POS_OBJREQ,0x10,0,0},
{ LCF_IO_POS_LPX,0x10,0,0},
{ LCF_IO_POS_LPY,0x10,0,0},
{ LCF_IO_POS_LRVX,0x10,0,0},
{ LCF_IO_POS_LRVY,0x10,0,0},
{ LCF_IO_POS_LRAX,0x10,0,0},
{ LCF_IO_POS_LRAY,0x10,0,0},
{ LCF_IO_POS_LQU,0x10,0,0},
{ LCF_IO_POS_LMS,0x10,0,0},
{ LCF_IO_POS_LOBJRCT,0x10,0,0},
{ LCF_IO_POS_LOBJTS,0x10,0,0}

};

ERRIO_ErrConfigData ERRIOVEH_ErrConfigVehDynData[]= {
/*  Signal,Rlvnt_fct,ErrCtr,Confirmed    */
{ VDY_SOUT_POS_VELOCITY,0xFFF,0,0},
{ VDY_SOUT_POS_ACCEL,0xFFF,0,0},
{ VDY_SOUT_POS_YAWRATE,0xFFF,0,0},
{ VDY_SOUT_POS_CURVE,0xFFF,0,0},
{ VDY_SOUT_POS_LATERALACCEL,0xFFF,0,0},
{ VDY_SOUT_POS_MOTIONSTATE,0x11,0,0}
};

ERRIO_ErrConfigData ERRIOVEH_ErrConfigVehSigAddData[] = {
/*  Signal,Rlvnt_fct,ErrCtr,Confirmed    */
{ VEH_SIG_ADD_TURN_SIGNAL,0xFFF,0,0},
{ VEH_SIG_ADD_ROAD_WHL_ANG_FR,0x17,0,0},
{ VEH_SIG_ADD_GAS_PEDAL_POS,0x11,0,0},
{ VEH_SIG_ADD_BRAKE_PEDAL_PRESSED,0x6,0,0},
{ VEH_SIG_ADD_SPEEDO_SPEED,0xFFF,0,0},
{ VEH_SIG_ADD_TRAILER_CON,0xF57,0,0}
};

ERRIO_ErrConfigData ERRIOVEH_ErrConfigVehSigMainData[] = {
/*  Signal,Rlvnt_fct,ErrCtr,Confirmed    */
{  VDY_SIN_POS_GEAR,0xF57,0,0}
};

ERRIO_ErrConfigData ERRIOVEH_ErrConfigVehSigBrakeData[] = {
/*  Signal,Rlvnt_fct,ErrCtr,Confirmed    */
{ VEH_SIG_BRAKE_TSC,0xF57,0,0},
{ VEH_SIG_BRAKE_ABS,0xF57,0,0}

};

uint8 ERRIOVEH_size_ErrConfigNormData       = sizeof(ERRIOVEH_ErrConfigNormData)/sizeof(ERRIOVEH_ErrConfigNormData[0]);
uint8 ERRIOVEH_size_ErrConfigVehDynData     = sizeof(ERRIOVEH_ErrConfigVehDynData)/sizeof(ERRIOVEH_ErrConfigVehDynData[0]);
uint8 ERRIOVEH_size_ErrConfigVehSigAddData  = sizeof(ERRIOVEH_ErrConfigVehSigAddData)/sizeof(ERRIOVEH_ErrConfigVehSigAddData[0]);
uint8 ERRIOVEH_size_ErrConfigVehSigMainData = sizeof(ERRIOVEH_ErrConfigVehSigMainData)/sizeof(ERRIOVEH_ErrConfigVehSigMainData[0]);
uint8 ERRIOVEH_size_ErrConfigVehSigBrakeData = sizeof(ERRIOVEH_ErrConfigVehSigBrakeData)/sizeof(ERRIOVEH_ErrConfigVehSigBrakeData[0]);
uint32 ERRIOVEH_RngChkFailed_btf = 0;

void ERRIOVEH_ChekSignalRanges(void);


/* ***********************************************************************
  @fn               ERRIOVEH_InputsCheck */ /*!

  @brief            check status of relevant inputs

  @description      

  @param[in]        pReqPorts required ports
  @param[out]       
  @return           void

  @pre              -
  @post             -
  **************************************************************************** */  
void ERRIOVEH_InputsCheck(const reqLcfVehPrtList_t *pReqPorts)
{
    /* GeGr: Defensive programming */
    /* PRQA S 2981 1 */
    uint8 i=0u;
    static uint8 ui8CycleCntLD = 0u;
    
    /* Assume no error for all checked LCF functions */
    S_ERRVEH_ErrMatrix_btf[ERRVEH_enERRIOVeh] = 0u;
	ERRIOVEH_RngChkFailed_btf = 0u;
    for(i=0u;i<8u;i++)
	{
		ERRIOVEH_RngChkDbg_btf[i] = 0u;
	}
	
    if( (P_ERRIOVEH_EnableChecks_btf & ERRIOVEH_CHECK_ALLIVE) != 0u)
    {
        ERRIOVEH_CheckAllive();
    }
    
    /* Check state of signals coming from NORM */
    if( (P_ERRIOVEH_EnableChecks_btf & ERRIOVEH_CHECK_NORM) != 0u)
    {
        ERRIOVEH_CheckSignalSource(pReqPorts->pLcfInputData->State_nu, ERRIOVEH_ErrConfigNormData, sizeof(ERRIOVEH_ErrConfigNormData)/sizeof(ERRIOVEH_ErrConfigNormData[0]));
    }
    
    /* Check state of signals coming from VDY (VehDyn) */
    if( (P_ERRIOVEH_EnableChecks_btf & ERRIOVEH_CHECK_VEHDYN) != 0u)
    {
        ERRIOVEH_CheckSignalSource(pReqPorts->pVehDyn->State, ERRIOVEH_ErrConfigVehDynData, sizeof(ERRIOVEH_ErrConfigVehDynData)/sizeof(ERRIOVEH_ErrConfigVehDynData[0]));
    }
    
    /* Check state of signals coming from VDY (VehSigAdd) */
    if( (P_ERRIOVEH_EnableChecks_btf & ERRIOVEH_CHECK_VEHSIGADD) != 0u)
    {
        ERRIOVEH_CheckSignalSource(pReqPorts->pVehSig->VehSigAdd.State, ERRIOVEH_ErrConfigVehSigAddData, sizeof(ERRIOVEH_ErrConfigVehSigAddData)/sizeof(ERRIOVEH_ErrConfigVehSigAddData[0]));
    }
    
    /* Check state of signals coming from VDY (VehSigMain) */
    if( (P_ERRIOVEH_EnableChecks_btf & ERRIOVEH_CHECK_VEHSIGMAIN) != 0u)
    {
        ERRIOVEH_CheckSignalSource(pReqPorts->pVehSig->VehSigMain.State, ERRIOVEH_ErrConfigVehSigMainData, sizeof(ERRIOVEH_ErrConfigVehSigMainData)/sizeof(ERRIOVEH_ErrConfigVehSigMainData[0]));
    }
	
	/* Check state of signals coming from VDY (Brake) */
    if( (P_ERRIOVEH_EnableChecks_btf & ERRIOVEH_CHECK_VEHSIGBRAKE) != 0u)
    {
        ERRIOVEH_CheckSignalSource(pReqPorts->pVehSig->Brake.State, ERRIOVEH_ErrConfigVehSigMainData, sizeof(ERRIOVEH_ErrConfigVehSigMainData)/sizeof(ERRIOVEH_ErrConfigVehSigMainData[0]));
    }
        
    /* Check state of signals coming from LD/ABD (LD does not have an state array for its signals, but only one signal status) */
    if( (P_ERRIOVEH_EnableChecks_btf & ERRIOVEH_CHECK_SIGHEADER) != 0u)
    {
        if (pReqPorts->pAbdOutputData->sSigHeader.eSigStatus != (uint8)AL_SIG_STATE_OK)
        {
			ui8CycleCntLD++;
			if(ui8CycleCntLD >= 10u)/* 9 increments => 180ms */
			{
	            			/* all functions use LD/ABD data */
				S_ERRVEH_ErrMatrix_btf[ERRVEH_enERRIOVeh] |= LCF_RELEVANT_FOR_ALL;
				ui8CycleCntLD = 10u;
			}
        }
		else
		{
			ui8CycleCntLD = 0u;
		}
    }
	
	/* Check signal ranges */
    if( (P_ERRIOVEH_EnableChecks_btf & ERRIOVEH_CHECK_SIGRANGE) != 0)
    {
        ERRIOVEH_ChekSignalRanges();
        S_ERRVEH_ErrMatrix_btf[ERRVEH_enERRIOVeh] |= ERRIOVEH_RngChkFailed_btf;
    }
}

void ERRIOVEH_VehSetHeader(const reqLcfVehPrtList_t *pReqPorts)
{
    if (pReqPorts != NULL)
    {
        S_ERRIOVEH_sigHeader[ERRIOVEH_enSigHeadBCD].sigHead      = LCF_GET_SIGHEADER(pReqPorts->pBaseCtrlData);
        S_ERRIOVEH_sigHeader[ERRIOVEH_enSigHeadABD].sigHead     = LCF_GET_SIGHEADER(pReqPorts->pAbdOutputData);
        S_ERRIOVEH_sigHeader[ERRIOVEH_enSigHeadLcfIn].sigHead   = LCF_GET_SIGHEADER(pReqPorts->pLcfInputData);
#if defined(LCF_IUC_USED) && (LCF_IUC_USED == 1)
        S_ERRIOVEH_sigHeader[ERRIOVEH_enSigHeadI2S].sigHead     = LCF_GET_SIGHEADER(pReqPorts->pLcfLaDmcIucToSoc);
#endif
        S_ERRIOVEH_sigHeader[ERRIOVEH_enSigHeadS2V].sigHead     = LCF_GET_SIGHEADER(pReqPorts->pLcfVehInputFromSenData);
        S_ERRIOVEH_sigHeader[ERRIOVEH_enSigHeadSenOut].sigHead  = LCF_GET_SIGHEADER(pReqPorts->pLcfSenOutputData);
        S_ERRIOVEH_sigHeader[ERRIOVEH_enSigHeadVDY].sigHead     = LCF_GET_SIGHEADER(pReqPorts->pVehDyn);
        /*S_ERRIOVEH_sigHeader[ERRIOVEH_enSigHeadVPar].sigHead    = LCF_GET_SIGHEADER(pReqPorts->pVehPar);*/
        S_ERRIOVEH_sigHeader[ERRIOVEH_enSigHeadVSig].sigHead    = LCF_GET_SIGHEADER(pReqPorts->pVehSig);
		S_ERRIOVEH_sigHeader[ERRIOVEH_enSigHeadVOffset].sigHead  = LCF_GET_SIGHEADER(pReqPorts->pVdyOffsets);
    }
    
}

void ERRIOVEH_ResetSigHdrConstCycles(void)
{
	/* ToDo: Review these values */
	/* Constant cycles */
    S_ERRIOVEH_sigHeader[ERRIOVEH_enSigHeadBCD].MaxConstantCycles = 7u;
    S_ERRIOVEH_sigHeader[ERRIOVEH_enSigHeadABD].MaxConstantCycles = 15u;
    S_ERRIOVEH_sigHeader[ERRIOVEH_enSigHeadLcfIn].MaxConstantCycles = 7u;
#if defined(LCF_IUC_USED) && (LCF_IUC_USED == 1u)
    S_ERRIOVEH_sigHeader[ERRIOVEH_enSigHeadI2S].MaxConstantCycles = 7u;
#endif
    S_ERRIOVEH_sigHeader[ERRIOVEH_enSigHeadS2V].MaxConstantCycles = 15u;
    S_ERRIOVEH_sigHeader[ERRIOVEH_enSigHeadSenOut].MaxConstantCycles = 15u;
    S_ERRIOVEH_sigHeader[ERRIOVEH_enSigHeadVDY].MaxConstantCycles = 15u;
    /*S_ERRIOVEH_sigHeader[ERRIOVEH_enSigHeadVPar].MaxConstantCycles = 15u;*/
    S_ERRIOVEH_sigHeader[ERRIOVEH_enSigHeadVSig].MaxConstantCycles = 15u;
	S_ERRIOVEH_sigHeader[ERRIOVEH_enSigHeadVOffset].MaxConstantCycles = 15u;
	
	/* Overflow threshold */	
	S_ERRIOVEH_sigHeader[ERRIOVEH_enSigHeadBCD].MaxOvrflCycles = 100u;
    S_ERRIOVEH_sigHeader[ERRIOVEH_enSigHeadABD].MaxOvrflCycles = 18u;
    S_ERRIOVEH_sigHeader[ERRIOVEH_enSigHeadLcfIn].MaxOvrflCycles = 6u;
#if defined(LCF_IUC_USED) && (LCF_IUC_USED == 1u)
    S_ERRIOVEH_sigHeader[ERRIOVEH_enSigHeadI2S].MaxOvrflCycles = 6u;
#endif
    S_ERRIOVEH_sigHeader[ERRIOVEH_enSigHeadS2V].MaxOvrflCycles = 18u;
    S_ERRIOVEH_sigHeader[ERRIOVEH_enSigHeadSenOut].MaxOvrflCycles = 18u;
    S_ERRIOVEH_sigHeader[ERRIOVEH_enSigHeadVDY].MaxOvrflCycles = 18u;
    /*S_ERRIOVEH_sigHeader[ERRIOVEH_enSigHeadVPar].MaxOvrflCycles = 18u;*/
    S_ERRIOVEH_sigHeader[ERRIOVEH_enSigHeadVSig].MaxOvrflCycles = 18u;
	S_ERRIOVEH_sigHeader[ERRIOVEH_enSigHeadVOffset].MaxOvrflCycles = 18u;
    
}


void ERRIOVEH_ChekSignalRanges(void)
{	
	/* GeGr: The construction is designed to work with any datatype (generic), therefore explicit cast cannot be used */
	/* GeGr: code is generated for a large number of signals. Some have the maxmum range specified, therefore is ok to have unreachable code */
	/* PRQA S 1281, 1802, 1852, 1863, 2880, 2992, 3763, 3794, 4505, 4115, 4461, 4558 75 */
	ERRIOVEH_RANGE_CHECK(GET_S_ABPLBP_CntrLnClthCrv_1pm(), -0.1, 0.1, 0x800u, 7u, 4u)
	ERRIOVEH_RANGE_CHECK(GET_S_ABPLBP_CntrLnClthHeading_rad(), -0.7854, 0.7854, 0x800u, 7u, 16u)
	ERRIOVEH_RANGE_CHECK(GET_S_ABPLBP_CntrLnClthPosY0_met(), -15, 15, 0x800u, 7u, 8u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_DeratingLevel_nu(), 0, 100, 0x800u, 6u, 2048u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_DistYTolLeTgtArea_met(), 0, 10, 0x800u, 5u, 524288u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_DistYTolRiTgtArea_met(), 0, 10, 0x800u, 5u, 1048576u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_FTireAclMax_mps2(), -20, 20, 0x800u, 5u, 2097152u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_FTireAclMin_mps2(), -20, 20, 0x800u, 5u, 4194304u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_HighStatAccu_bool(), 0, 1, 0x800u, 6u, 1024u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_LatencyCompActivated_nu(), 0, 1, 0x800u, 6u, 2u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_LeCridrBndCrv_1pm(), -0.1, 0.1, 0x800u, 5u, 2u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_LeCridrBndCrvChng_1pm2(), -0.001, 0.001, 0x800u, 5u, 4u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_LeCridrBndHeadAng_rad(), -0.7854, 0.7854, 0x800u, 5u, 1u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_LeCridrBndLength_met(), 0, 150, 0x800u, 5u, 8u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_LeCridrBndPosX0_met(), -150, 150, 0x800u, 4u, 1073741824u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_LeCridrBndPosY0_met(), -15, 15, 0x800u, 4u, 2147483648u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_LimiterActivated_nu(), 0, 1, 0x800u, 6u, 8192u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_LimiterTimeDuration_sec(), 0, 60, 0x800u, 6u, 32768u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_MaxCrvGrdBuildup_1pms(), -2, 2, 0x800u, 6u, 16u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_MaxCrvGrdRed_1pms(), -2, 2, 0x800u, 6u, 32u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_MaxCrvTrajGuiCtrl_1pm(), -0.1, 0.1, 0x800u, 6u, 8u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_MaxJerkAllowed_mps3(), 0, 50, 0x800u, 4u, 67108864u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_ObstacleAclX_mps2(), -20, 20, 0x800u, 5u, 536870912u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_ObstacleDistX_met(), -1000, 1000, 0x800u, 5u, 2147483648u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_ObstacleDistY_met(), -1000, 1000, 0x800u, 6u, 1u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_ObstacleVelX_mps(), -20, 150, 0x800u, 5u, 268435456u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_ObstacleWidth_met(), 0, 150, 0x800u, 5u, 1073741824u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_PlanningHorizon_sec(), 0, 60, 0x800u, 5u, 134217728u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_PredictionTimeCrv_sec(), 0, 60, 0x800u, 5u, 67108864u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_PredTimeHeadAng_sec(), 0, 60, 0x800u, 5u, 33554432u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_RiCridrBndCrv_1pm(), -0.1, 0.1, 0x800u, 5u, 128u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_RiCridrBndCrvChng_1pm2(), -0.001, 0.001, 0x800u, 5u, 256u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_RiCridrBndHeadAng_rad(), -0.7854, 0.7854, 0x800u, 5u, 64u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_RiCridrBndLength_met(), 0, 150, 0x800u, 5u, 512u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_RiCridrBndPosX0_met(), -150, 150, 0x800u, 5u, 16u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_RiCridrBndPosY0_met(), -15, 15, 0x800u, 5u, 32u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_SensorTStamp_sec(), 0, 4295, 0x800u, 6u, 4u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_StrWhStifGrad_1ps(), 0, 10000, 0x800u, 6u, 128u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_StrWhStifLimit_nu(), 0, 100, 0xF57u, 4u, 2097152u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_SysStateLCF_enum(), 0, 6, 0x800u, 6u, 2097152u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_TgtTrajCrv_1pm(), -0.1, 0.1, 0x800u, 5u, 8192u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_TgtTrajCrvChng_1pm2(), -0.001, 0.001, 0x800u, 5u, 16384u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_TgtTrajHeadAng_rad(), -0.7854, 0.7854, 0x800u, 5u, 4096u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_TgtTrajLength_met(), 0, 150, 0x800u, 5u, 32768u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_TgtTrajPosX0_met(), -150, 150, 0x800u, 5u, 1024u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_TgtTrajPosY0_met(), -15, 15, 0x800u, 5u, 2048u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_TrajGuiQualifier_nu(), 0, 5, 0x800u, 5u, 8388608u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_TrajPlanServQu_nu(), 0, 255, 0x800u, 5u, 65536u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_TriggerReplan_nu(), 0, 1, 0x800u, 5u, 16777216u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_WeightEndTime_nu(), 0, 1, 0x800u, 5u, 262144u)
	ERRIOVEH_RANGE_CHECK(GET_S_CSCLTA_WeightTgtDistY_nu(), 0, 1, 0x800u, 5u, 131072u)
	ERRIOVEH_RANGE_CHECK(GET_S_DPLSTM_SysStateLDP_nu(), 0, 6, 0x2u, 6u, 65536u)
	ERRIOVEH_RANGE_CHECK(GET_S_DPRSTM_SysStateRDP_nu(), 0, 6, 0x4u, 6u, 131072u)
	ERRIOVEH_RANGE_CHECK(GET_S_HMORQG_AvailableFunction_btf(), 0, 65535, 0xF57u, 4u, 16777216u)
	ERRIOVEH_RANGE_CHECK(GET_S_LCFRCV_ActFctLevel_nu(), 0, 9, 0xF57u, 4u, 33554432u)
	ERRIOVEH_RANGE_CHECK(GET_S_LCFRCV_ActualStWheelAngle_deg(), -1000, 1000, 0xFFFu, 2u, 16u)
	ERRIOVEH_RANGE_CHECK(GET_S_LCFRCV_AngReqMaxLimitScale_per(), 0, 100, 0x800u, 4u, 268435456u)
	ERRIOVEH_RANGE_CHECK(GET_S_LCFRCV_AngReqRateMaxLimitScale_per(), 0, 100, 0x800u, 4u, 536870912u)
	ERRIOVEH_RANGE_CHECK(GET_S_LCFRCV_BankAngle_rad(), -1, 1, 0xF57u, 0u, 1073741824u)
	ERRIOVEH_RANGE_CHECK(GET_S_LCFRCV_EPS_ManualTrqActualVal_Nm(), -20, 20, 0xF57u, 0u, 16u)
	ERRIOVEH_RANGE_CHECK(GET_S_LCFRCV_LatCtrlModeTJA_nu(), 0, 8, 0x11u, 6u, 33554432u)
	ERRIOVEH_RANGE_CHECK(GET_S_LCFRCV_MotorTorqueEPS_Nm(), -30, 30, 0xF57u, 0u, 32u)
	ERRIOVEH_RANGE_CHECK(GET_S_LCFRCV_SteerAngleEPS_deg(), -1000, 1000, 0xF57u, 0u, 4u)
	ERRIOVEH_RANGE_CHECK(GET_S_LCFRCV_SteerWAngleRate_degps(), -1016, 1016, 0xFFFu, 0u, 2u)
	ERRIOVEH_RANGE_CHECK(GET_S_LCFRCV_TorqueActiveEPS_nu(), 0, 1, 0xF57u, 1u, 2u)
	ERRIOVEH_RANGE_CHECK(GET_S_LCFRCV_TorqueFaultEPS_nu(), 0, 1, 0xF57u, 1u, 4u)
	ERRIOVEH_RANGE_CHECK(GET_S_LCFRCV_TorqueUnavailableEPS_nu(), 0, 1, 0xF57u, 1u, 1u)
	ERRIOVEH_RANGE_CHECK(GET_S_LCFRCV_VehAclX_mps2(), -20, 20, 0xFFFu, 2u, 536870912u)
	ERRIOVEH_RANGE_CHECK(GET_S_LCFRCV_VehAclY_mps2(), -20, 20, 0xFFFu, 3u, 1u)
	ERRIOVEH_RANGE_CHECK(GET_S_LCFRCV_VehCrv_1pm(), -0.5, 0.5, 0xFFFu, 2u, 2147483648u)
	ERRIOVEH_RANGE_CHECK(GET_S_LCFRCV_VehMotionState_enum(), 0, 3, 0x11u, 3u, 2u)
	ERRIOVEH_RANGE_CHECK(GET_S_LCFRCV_VehVelX_mps(), -20, 150, 0xFFFu, 2u, 268435456u)
	ERRIOVEH_RANGE_CHECK(GET_S_LCFRCV_VehYawRate_rps(), -1, 1, 0xFFFu, 2u, 1073741824u)
	ERRIOVEH_RANGE_CHECK(GET_S_MCTLFC_ControllingFunction_nu(), 0, 7, 0x800u, 4u, 8388608u)
	ERRIOVEH_RANGE_CHECK(GET_S_TJASTM_SysStateTJA_nu(), 0, 6, 0x11u, 6u, 16777216u)



}



#endif /* C_ERRIO_VehCustom_ */
