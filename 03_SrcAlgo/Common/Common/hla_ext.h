/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 GA (Global Architecture)

PACKAGENAME:               hla_ext.h

DESCRIPTION:               Interface definitions for HLA

VERSION:                   $Revision: 1.13 $

**************************************************************************** */

#ifndef __HLA_EXT_H
#define __HLA_EXT_H

#include "algo_glob.h"

#ifdef __cplusplus
extern "C"
{
#endif

// Port macro defines. Can be used to establish compatibility with different interface versions.
#define HLA_RPORT_PBASECTRLDATA
#define HLA_RPORT_PCBOUTPUTS
#define HLA_RPORT_PCPAR_HLAFPAR
#define HLA_RPORT_PGENOBJECTLIST
#define HLA_RPORT_PHLABUSINPUTSIGNALS
#define HLA_RPORT_PHLARADAROBJECTLIST
#define HLA_RPORT_PLSDENVIRONMENTDATA
#define HLA_RPORT_PLSDLIGHTLIST
#define HLA_RPORT_PLSDLIGHTOBJECTLIST
#define HLA_RPORT_PMONOCALIBRATION
#define HLA_RPORT_PVEHDYN
#define HLA_RPORT_PVEHSIG
#define HLA_PPORT_PALGOCOMPSTATE
#define HLA_PPORT_PHLAF_HEADLIGHTCONTROL

//! Input sync structure providing info about received inputs on measfreeze channel.
typedef struct Hla_SyncRef_s
{
  AlgoInterfaceVersionNumber_t uiVersionNumber;
  SignalHeader_t               sSigHeader;
  BaseCtrlData_t               sBaseCtrl;
  SignalHeader_t               pCbOutputs;
  SignalHeader_t               pCPar_HlafPar;
  SignalHeader_t               pGenObjectList;
  SignalHeader_t               pHlaBusInputSignals;
  SignalHeader_t               pHlaRadarObjectList;
  SignalHeader_t               pLsdEnvironmentData;
  SignalHeader_t               pLsdLightList;
  SignalHeader_t               pLsdLightObjectList;
  SignalHeader_t               pMonoCalibration;
  SignalHeader_t               pVehDyn;
  SignalHeader_t               pVehSig;
} Hla_SyncRef_t;

//! List of input ports.
typedef struct reqHlaPrtList_s
{
  const BaseCtrlData_t*              pBaseCtrlData;             //!< Control data giving information about the current mode
  const CB_t_ProvidedOutputs_t*      pCbOutputs;                //!< Mono Camera Blockage provided outputs 
  const CPAR_HLAF_Parameter_t*       pCPar_HlafPar;             //!< HLAF parameter 
  const EM_t_GenObjectList*          pGenObjectList;            //!< [OptionalInput]; Object list properties 
  const HLA_BusInputSignals_t*       pHlaBusInputSignals;       //!< All kind of bus signals relevant for HLA, e.g. headlight state (feedback from headlight control unit), driver requests like US sensitivity mode or HLA on/off 
  const HLA_RadarObjectList_t*       pHlaRadarObjectList;       //!< 
  const LSD_EnvironmentData_t*       pLsdEnvironmentData;       //!< Environment analysis results 
  const LSD_LightList_t*             pLsdLightList;             //!< Raw light list 
  const LSD_LightObjectList_t*       pLsdLightObjectList;       //!< Light object list 
  const MonoCalibration_t*           pMonoCalibration;          //!< Output data of monocular calibration
  const VehDyn_t*                    pVehDyn;                   //!< Vehicle dynamic data (VDY output) 
  const VehSig_t*                    pVehSig;                   //!< Main Vehicle dynacmis sensor signals 
} reqHlaPrtList_t;

//! List of output ports.
typedef struct proHlaPrtList_s
{
  AlgoCompState_t*             pAlgoCompState;            //!< State return values of the algo component
  RTE_HLAF_HeadlightControl_t* pHlaf_HeadlightControl;    //!< Headlight Control data 
} proHlaPrtList_t;



/**
 * Entry point for algo calculation.
 * @param reqPorts Input data for algo calculation.
 * @param proPorts Output data of algo calculation.
 * @param services Service functions available for usage.
 * @return Error code.
 */
BaseReturnCode_t HlaExec(const reqHlaPrtList_t* const reqPorts, proHlaPrtList_t* const proPorts, const AS_t_ServiceFuncts* const services);

#ifdef __cplusplus
}
#endif

#endif  // __HLA_EXT_H

