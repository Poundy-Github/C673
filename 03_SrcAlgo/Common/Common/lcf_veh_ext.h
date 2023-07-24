/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 GA (Global Architecture)

PACKAGENAME:               lcf_veh_ext.h

DESCRIPTION:               Interface definitions for LCF_VEH

VERSION:                   $Revision: 1.13 $

**************************************************************************** */

#ifndef __LCF_VEH_EXT_H
#define __LCF_VEH_EXT_H

#include "algo_glob.h"

#ifdef __cplusplus
extern "C"
{
#endif

// Port macro defines. Can be used to establish compatibility with different interface versions.
#define LCF_VEH_RPORT_PBASECTRLDATA
#define LCF_VEH_RPORT_PABDOUTPUTDATA
#define LCF_VEH_RPORT_PCPARDMC
#define LCF_VEH_RPORT_PCPARKMC
#define LCF_VEH_RPORT_PLCFINPUTDATA
#define LCF_VEH_RPORT_PLCFLADMCIUCTOSOC
#define LCF_VEH_RPORT_PLCFSENOUTPUTDATA
#define LCF_VEH_RPORT_PLCFVEHINPUTFROMSENDATA
#define LCF_VEH_RPORT_PNVMLCFDATA
#define LCF_VEH_RPORT_PVDYOFFSETS
#define LCF_VEH_RPORT_PVEHDYN
#define LCF_VEH_RPORT_PVEHPAR
#define LCF_VEH_RPORT_PVEHSIG
#define LCF_VEH_PPORT_PALGOCOMPSTATE
#define LCF_VEH_PPORT_PLCFLADMCSOCTOIUC
#define LCF_VEH_PPORT_PLCFVEHOUTPUTDATA
#define LCF_VEH_PPORT_PLCFVEHOUTPUTTOSENDATA
#define LCF_VEH_PPORT_PNVMLCFDATA

//! Input sync structure providing info about received inputs on measfreeze channel.
typedef struct LcfVeh_SyncRef_s
{
  AlgoInterfaceVersionNumber_t uiVersionNumber;
  SignalHeader_t               sSigHeader;
  BaseCtrlData_t               sBaseCtrl;
  SignalHeader_t               pAbdOutputData;
  SignalHeader_t               pCParDmc;
  SignalHeader_t               pCParKmc;
  SignalHeader_t               pLcfInputData;
  SignalHeader_t               pLcfLaDmcIucToSoc;
  SignalHeader_t               pLcfSenOutputData;
  SignalHeader_t               pLcfVehInputFromSenData;
  SignalHeader_t               pNvmLcfData;
  SignalHeader_t               pVdyOffsets;
  SignalHeader_t               pVehDyn;
  SignalHeader_t               pVehPar;
  SignalHeader_t               pVehSig;
} LcfVeh_SyncRef_t;

//! List of input ports.
typedef struct reqLcfVehPrtList_s
{
  const BaseCtrlData_t*          pBaseCtrlData;              //!< Control data giving information about the current mode
  const AbdOutputData_t*         pAbdOutputData;             //!< 
  const CPAR_LCF_TunParamsDMC_t* pCParDmc;                   //!< 
  const CPAR_LCF_TunParamsKMC_t* pCParKmc;                   //!< 
  const LCF_GenericInputs_t*     pLcfInputData;              //!< 
  const LCF_LaDmcIucToSoc_t*     pLcfLaDmcIucToSoc;          //!< 
  const LCF_SenGenericOutputs_t* pLcfSenOutputData;          //!< 
  const LCF_SenToVeh_t*          pLcfVehInputFromSenData;    //!< 
  const NVM_LcfLearningData_t*   pNvmLcfData;                //!< Learning data for LCF
  const VDYOffsets_t*            pVdyOffsets;                //!< The offsets of the vdy input signals like yaw rate 
  const VehDyn_t*                pVehDyn;                    //!< Vehicle dynamic data (VDY output) 
  const VehPar_t*                pVehPar;                    //!< Static Vehicle parameters all values are vehicle dependent, therefore no default values are given 
  const VehSig_t*                pVehSig;                    //!< Main Vehicle dynacmis sensor signals 
} reqLcfVehPrtList_t;

//! List of output ports.
typedef struct proLcfVehPrtList_s
{
  AlgoCompState_t*         pAlgoCompState;             //!< State return values of the algo component
  LCF_LaDmcSocToIuc_t*     pLcfLaDmcSocToIuc;          //!< 
  LCF_VehGenericOutputs_t* pLcfVehOutputData;          //!< 
  LCF_VehToSen_t*          pLcfVehOutputToSenData;     //!< 
  NVM_LcfLearningData_t*   pNvmLcfData;                //!< Learning data for LCF
} proLcfVehPrtList_t;



/**
 * Entry point for algo calculation.
 * @param reqPorts Input data for algo calculation.
 * @param proPorts Output data of algo calculation.
 * @param services Service functions available for usage.
 * @return Error code.
 */
BaseReturnCode_t LcfVehExec(const reqLcfVehPrtList_t* const reqPorts, proLcfVehPrtList_t* const proPorts, const AS_t_ServiceFuncts* const services);

#ifdef __cplusplus
}
#endif

#endif  // __LCF_VEH_EXT_H

