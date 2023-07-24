/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 LCF

  MODULNAME:                 sim_lcf_sen_types.h

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.1 $


  ---*/ /*---
  CHANGES:                   Initial revision

**************************************************************************** */

#ifndef sim_lcf_sen_types_h__
#define sim_lcf_sen_types_h__

#include "rtatype.h"
#include "algo_glob.h"

typedef struct
{
  /* LCF_SEN input ports */
  BaseCtrlData_t			        SenIn_LcfSenCtrlData;
  EM_t_CamObjectList                SenIn_CamObjectList;
  EM_t_GenObjectList                SenIn_GenObjectList;
  LCF_GenericInputs_t               SenIn_LcfInputData;
#if defined(LCF_SEN_RPORT_PLCFLADMCIUCTOSOC)
  LCF_LaDmcIucToSoc_t               SenIn_LcfLaDmcIucToSoc;
#endif
  LCF_VehToSen_t                    SenIn_LcfSenInputFromVehData;
  LCF_VehGenericOutputs_t           SenIn_LcfVehOutputData;
  VehPar_t                          SenIn_VehPar;       
  VehSig_t                          SenIn_VehSig;       
  VehDyn_t                          SenIn_VehDyn;  
#if defined(LCF_SEN_RPORT_PHLARADAROBJECTLIST) 
  HLA_RadarObjectList_t             SenIn_HlaRadarObjectList;
#endif
#if defined(LCF_SEN_RPORT_PCBOUTPUTS)
  CB_t_ProvidedOutputs_t			SenIn_CbOutputs;
#endif
#if defined(LCF_SEN_RPORT_PLSDENVIRONMENTDATA)
  LSD_EnvironmentData_t				SenIn_LsdEnvironmentData;
#endif
  AbdOutputData_t                   SenIn_ABDOutputData;
  CPAR_LCF_TunParamsLDP_t           SenIn_CParLdp; 
  CPAR_LCF_TunParamsLKA_t           SenIn_CParLka; 
  
} hil_PortBuffer_mts2hil_t;

typedef struct
{
  AS_t_RtaBuffer                    RtaBuffer;
  
  /* LCF_SEN output ports */
  AlgoCompState_t                   SenOut_LcfAlgoCompState;
  LCF_SenGenericOutputs_t           SenOut_LcfSenOutputData;
  LCF_SenToVeh_t                    SenOut_LcfSenOutputToVehData;
  
} hil_PortBuffer_hil2mts_t;

#endif
