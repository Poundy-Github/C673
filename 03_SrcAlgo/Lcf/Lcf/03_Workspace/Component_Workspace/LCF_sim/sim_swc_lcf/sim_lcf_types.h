/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 LCF

  MODULNAME:                 sim_swc_lcf_types.h

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.1 $


  ---*/ /*---
  CHANGES:                   Initial revision

**************************************************************************** */

#ifndef sim_swc_lcf_types_h__
#define sim_swc_lcf_types_h__

#include "rtatype.h"
#include "Rte_Type.h"

typedef struct
{
  /* LCF_SEN input ports */
  BaseCtrlData_t			        SenIn_LcfSenCtrlData;
  LCF_GenericInputs_t               SenIn_LcfInputData;
  LCF_VehToSen_t                    SenIn_LcfSenInputFromVehData;
  LCF_VehGenericOutputs_t           SenIn_LcfVehOutputData;
  LCF_CPAR_Parameters_t             SenIn_LcfCpar;		
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
  EMT0_t_ObjectList_MCAM            SenIn_EMT0OutputData;
  
  /* LCF_VEH input ports */
  BaseCtrlData_t			        VehIn_LcfVehCtrlData;
  LCF_GenericInputs_t               VehIn_LcfInputData;	
  LCF_SenToVeh_t                    VehIn_LcfVehInputFromSenData;
  LCF_SenGenericOutputs_t           VehIn_LcfSenOutputData;     
  LCF_CPAR_Parameters_t             VehIn_LcfCpar;				
  VehPar_t                          VehIn_VehPar;               
  VehSig_t                          VehIn_VehSig;               
  VehDyn_t                          VehIn_VehDyn;  
  EMT0_t_ObjectList_MCAM            VehIn_EMT0OutputData;       
  
} hil_PortBuffer_mts2hil_t;

typedef struct
{
  AS_t_RtaBuffer                    RtaBuffer;
  
  /* LCF_SEN output ports */
  AlgoCompState_t                   SenOut_LcfAlgoCompState;
  BusDebugData_t                    SenOut_LcfBusDebugData;
  LCF_SenGenericOutputs_t           SenOut_LcfSenOutputData;
  LCF_SenToVeh_t                    SenOut_LcfSenOutputToVehData;
  
  /* LCF_VEH output ports */
  AlgoCompState_t                   VehOut_LcfAlgoCompState;
  BusDebugData_t                    VehOut_LcfBusDebugData;
  LCF_VehGenericOutputs_t           VehOut_LcfVehOutputData;
  LCF_VehToSen_t                    VehOut_LcfVehOutputToSenData;
  
} hil_PortBuffer_hil2mts_t;

#endif
