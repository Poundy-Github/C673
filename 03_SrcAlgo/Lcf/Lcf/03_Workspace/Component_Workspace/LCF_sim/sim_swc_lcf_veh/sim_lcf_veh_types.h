/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 LCF

  MODULNAME:                 sim_lcf_veh_types.h

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.1 $


  ---*/ /*---
  CHANGES:                   Initial revision

**************************************************************************** */

#ifndef sim_lcf_veh_types_h__
#define sim_lcf_veh_types_h__

#include "rtatype.h"
#include "algo_glob.h"

typedef struct
{
  /* LCF_VEH input ports */
  BaseCtrlData_t                    VehIn_LcfVehCtrlData;
  LCF_GenericInputs_t               VehIn_LcfInputData;
#if defined(LCF_VEH_RPORT_PLCFLADMCIUCTOSOC)
  LCF_LaDmcIucToSoc_t               VehIn_LcfLaDmcIucToSoc; 
#endif  
  LCF_SenToVeh_t                    VehIn_LcfVehInputFromSenData;
  LCF_SenGenericOutputs_t           VehIn_LcfSenOutputData;     
  VehPar_t                          VehIn_VehPar;               
  VehSig_t                          VehIn_VehSig;               
  VehDyn_t                          VehIn_VehDyn;  
  VDYOffsets_t                      VehIn_VdyOffsets; 
#ifdef ABD_OUTPUT_DATA_INTFVER
  AbdOutputData_t                   VehIn_ABDOutputData;
#endif  
  CPAR_LCF_TunParamsKMC_t           VehIn_CParKmc;
  CPAR_LCF_TunParamsDMC_t           VehIn_CParDmc;
#ifdef LCF_VEH_PPORT_PNVMLCFDATA    //TODO: delete this line in next release
  NVM_LcfLearningData_t             VehIn_NvmLcfData;
#endif 
  
} hil_PortBuffer_mts2hil_t;

typedef struct
{
  AS_t_RtaBuffer                    RtaBuffer;
  
  /* LCF_VEH output ports */
  AlgoCompState_t                   VehOut_LcfAlgoCompState;
  LCF_VehGenericOutputs_t           VehOut_LcfVehOutputData;
  LCF_LaDmcSocToIuc_t               VehOut_LcfLaDmcSocToIuc;
  LCF_VehToSen_t                    VehOut_LcfVehOutputToSenData;
#ifdef LCF_VEH_PPORT_PNVMLCFDATA  //TODO: delete this line in next release
  NVM_LcfLearningData_t             VehOut_NvmLcfData;
#endif
  
} hil_PortBuffer_hil2mts_t;

#endif
