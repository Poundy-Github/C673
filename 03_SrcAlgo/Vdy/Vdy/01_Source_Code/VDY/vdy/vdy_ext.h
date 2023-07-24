/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 GA (Global Architecture)

PACKAGENAME:               vdy_ext.h

DESCRIPTION:               Interface definitions for VDY

VERSION:                   $Revision: 1.6 $

**************************************************************************** */

#ifndef __VDY_EXT_H
#define __VDY_EXT_H

#include "algo_glob.h"

#ifdef __cplusplus
extern "C"
{
#endif

// Port macro defines. Can be used to establish compatibility with different interface versions.
#define VDY_RPORT_PBASECTRLDATA
#define VDY_RPORT_PNVMREAD
#define VDY_RPORT_PVEHICLEINPUTSIGNALS
#define VDY_RPORT_PVEHICLEPARAMETER
#define VDY_PPORT_PALGOCOMPSTATE
#define VDY_PPORT_PNVMWRITE
#define VDY_PPORT_PVDYERRORS
#define VDY_PPORT_PVDYESTCURVES
#define VDY_PPORT_PVDYOFFSETS
#define VDY_PPORT_PVEHICLEDYNAMICSIGNALS

//! Input sync structure providing info about received inputs on measfreeze channel.
typedef struct Vdy_SyncRef_s
{
  AlgoInterfaceVersionNumber_t uiVersionNumber;
  SignalHeader_t               sSigHeader;
  BaseCtrlData_t               sBaseCtrl;
  SignalHeader_t               pNVMRead;
  SignalHeader_t               pVehicleInputSignals;
  SignalHeader_t               pVehicleParameter;
} Vdy_SyncRef_t;

//! List of input ports.
typedef struct reqVdyPrtList_s
{
  const BaseCtrlData_t*  pBaseCtrlData;             //!< Control data giving information about the current mode
  const VDYNvIoData_t*   pNVMRead;                  //!< The vdy nvm input and output data stuct 
  const VehSig_t*        pVehicleInputSignals;      //!< Main Vehicle dynacmis sensor signals 
  const VehPar_t*        pVehicleParameter;         //!< Static Vehicle parameters all values are vehicle dependent, therefore no default values are given 
} reqVdyPrtList_t;

//! List of output ports.
typedef struct proVdyPrtList_s
{
  AlgoCompState_t* pAlgoCompState;            //!< State return values of the algo component
  VDYNvIoData_t*   pNVMWrite;                 //!< The vdy nvm input and output data stuct 
  VDYErrors_t*     pVDYErrors;                //!< The vdy errors input signals/parameters Output errors, internal errors, 
  VDYEstCurves_t*  pVDYEstCurves;             //!< The vdy estimated curves 
  VDYOffsets_t*    pVDYOffsets;               //!< The offsets of the vdy input signals like yaw rate 
  VehDyn_t*        pVehicleDynamicSignals;    //!< Vehicle dynamic data (VDY output) 
} proVdyPrtList_t;



/**
 * Entry point for algo calculation.
 * @param reqPorts Input data for algo calculation.
 * @param proPorts Output data of algo calculation.
 * @param services Service functions available for usage.
 * @return Error code.
 */
BaseReturnCode_t VdyExec(const reqVdyPrtList_t* const reqPorts, proVdyPrtList_t* const proPorts, const AS_t_ServiceFuncts* const services);

#ifdef __cplusplus
}
#endif

#endif  // __VDY_EXT_H

