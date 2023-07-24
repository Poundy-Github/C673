/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 GA (Global Architecture)

PACKAGENAME:               lcf_sen_ext.h

DESCRIPTION:               Interface definitions for LCF_SEN

VERSION:                   $Revision: 1.14 $

**************************************************************************** */

#ifndef __LCF_SEN_EXT_H
#define __LCF_SEN_EXT_H

#include "algo_glob.h"

#ifdef __cplusplus
extern "C"
{
#endif

// Port macro defines. Can be used to establish compatibility with different interface versions.
#define LCF_SEN_RPORT_PBASECTRLDATA
#define LCF_SEN_RPORT_PABDOUTPUTDATA
#define LCF_SEN_RPORT_PCAMOBJECTLIST
#define LCF_SEN_RPORT_PCBOUTPUTS
#define LCF_SEN_RPORT_PCPARLDP
#define LCF_SEN_RPORT_PCPARLKA
#define LCF_SEN_RPORT_PGENOBJECTLIST
#define LCF_SEN_RPORT_PHLARADAROBJECTLIST
#define LCF_SEN_RPORT_PLCFINPUTDATA
#define LCF_SEN_RPORT_PLCFLADMCIUCTOSOC
#define LCF_SEN_RPORT_PLCFSENINPUTFROMVEHDATA
#define LCF_SEN_RPORT_PLCFVEHOUTPUTDATA
#define LCF_SEN_RPORT_PLSDENVIRONMENTDATA
#define LCF_SEN_RPORT_PVEHDYN
#define LCF_SEN_RPORT_PVEHPAR
#define LCF_SEN_RPORT_PVEHSIG
#define LCF_SEN_PPORT_PALGOCOMPSTATE
#define LCF_SEN_PPORT_PLCFSENOUTPUTDATA
#define LCF_SEN_PPORT_PLCFSENOUTPUTTOVEHDATA

//! Input sync structure providing info about received inputs on measfreeze channel.
typedef struct LcfSen_SyncRef_s
{
  AlgoInterfaceVersionNumber_t uiVersionNumber;
  SignalHeader_t               sSigHeader;
  BaseCtrlData_t               sBaseCtrl;
  SignalHeader_t               pAbdOutputData;
  SignalHeader_t               pCamObjectList;
  SignalHeader_t               pCbOutputs;
  SignalHeader_t               pCParLdp;
  SignalHeader_t               pCParLka;
  SignalHeader_t               pGenObjectList;
  SignalHeader_t               pHlaRadarObjectList;
  SignalHeader_t               pLcfInputData;
  SignalHeader_t               pLcfLaDmcIucToSoc;
  SignalHeader_t               pLcfSenInputFromVehData;
  SignalHeader_t               pLcfVehOutputData;
  SignalHeader_t               pLsdEnvironmentData;
  SignalHeader_t               pVehDyn;
  SignalHeader_t               pVehPar;
  SignalHeader_t               pVehSig;
} LcfSen_SyncRef_t;

//! List of input ports.
typedef struct reqLcfSenPrtList_s
{
  const BaseCtrlData_t*          pBaseCtrlData;              //!< Control data giving information about the current mode
  const AbdOutputData_t*         pAbdOutputData;             //!< 
  const EM_t_CamObjectList*      pCamObjectList;             //!< Object list properties 
  const CB_t_ProvidedOutputs_t*  pCbOutputs;                 //!< Mono Camera Blockage provided outputs 
  const CPAR_LCF_TunParamsLDP_t* pCParLdp;                   //!< 
  const CPAR_LCF_TunParamsLKA_t* pCParLka;                   //!< 
  const EM_t_GenObjectList*      pGenObjectList;             //!< Object list properties 
  const HLA_RadarObjectList_t*   pHlaRadarObjectList;        //!< 
  const LCF_GenericInputs_t*     pLcfInputData;              //!< 
  const LCF_LaDmcIucToSoc_t*     pLcfLaDmcIucToSoc;          //!< 
  const LCF_VehToSen_t*          pLcfSenInputFromVehData;    //!< 
  const LCF_VehGenericOutputs_t* pLcfVehOutputData;          //!< 
  const LSD_EnvironmentData_t*   pLsdEnvironmentData;        //!< Environment analysis results 
  const VehDyn_t*                pVehDyn;                    //!< Vehicle dynamic data (VDY output) 
  const VehPar_t*                pVehPar;                    //!< Static Vehicle parameters all values are vehicle dependent, therefore no default values are given 
  const VehSig_t*                pVehSig;                    //!< Main Vehicle dynacmis sensor signals 
} reqLcfSenPrtList_t;

//! List of output ports.
typedef struct proLcfSenPrtList_s
{
  AlgoCompState_t*         pAlgoCompState;             //!< State return values of the algo component
  LCF_SenGenericOutputs_t* pLcfSenOutputData;          //!< 
  LCF_SenToVeh_t*          pLcfSenOutputToVehData;     //!< 
} proLcfSenPrtList_t;



/**
 * Entry point for algo calculation.
 * @param reqPorts Input data for algo calculation.
 * @param proPorts Output data of algo calculation.
 * @param services Service functions available for usage.
 * @return Error code.
 */
BaseReturnCode_t LcfSenExec(const reqLcfSenPrtList_t* const reqPorts, proLcfSenPrtList_t* const proPorts, const AS_t_ServiceFuncts* const services);

#ifdef __cplusplus
}
#endif

#endif  // __LCF_SEN_EXT_H

