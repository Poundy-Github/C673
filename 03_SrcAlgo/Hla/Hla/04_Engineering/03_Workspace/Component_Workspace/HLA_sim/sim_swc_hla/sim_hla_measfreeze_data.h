/*! @file ******************************************************************
  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH
 
  PROJECT:                MFC4xx

  COMPONENT:              HLA

  MODULNAME:              sim_hla_measfreeze_data.h

  DESCRIPTION:            Everything related to measfreezes during simulation,
                          e.g. virtual addresses.

  CREATION DATE:          2016-09-22
  
  CPU:                    Independent

  VERSION:                $Revision: 1.6.1.1 $
**************************************************************************** */
#ifndef SIM_HLA_MEASFREEZE_DATA_H
#define SIM_HLA_MEASFREEZE_DATA_H

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hla_measfreeze_data.h"
#ifndef AS_RTA_MAX_EVENTS
#include "rtatype.h"
#endif

/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/
/* Virtual addresses for SIL measfreezes, i.e. triggered from SIL wrapper */
#define SIL_HLA_MEAS_VADDR_REQ_PORT_CPAR_HLAF_PAR          HLA_MEAS_VADDR_LAST_ITEM_ALIGNED
#define SIL_HLA_MEAS_VADDR_REQ_PORT_MONO_CALI              (SIL_HLA_MEAS_VADDR_REQ_PORT_CPAR_HLAF_PAR          + HLA_MEAS_VADDR_PADDING_BYTES + sizeof(CPAR_HLAF_Parameter_t))
#define SIL_HLA_MEAS_VADDR_REQ_PORT_HLA_BUS_INPUT_SIGNALS  (SIL_HLA_MEAS_VADDR_REQ_PORT_MONO_CALI              + HLA_MEAS_VADDR_PADDING_BYTES + sizeof(MonoCalibration_t))
#define SIL_HLA_MEAS_VADDR_REQ_PORT_HLA_RADAR_OBJECT_LIST  (SIL_HLA_MEAS_VADDR_REQ_PORT_HLA_BUS_INPUT_SIGNALS  + HLA_MEAS_VADDR_PADDING_BYTES + sizeof(HLA_BusInputSignals_t))
#define SIL_HLA_MEAS_VADDR_REQ_PORT_VEH_SIG                (SIL_HLA_MEAS_VADDR_REQ_PORT_HLA_RADAR_OBJECT_LIST  + HLA_MEAS_VADDR_PADDING_BYTES + sizeof(HLA_RadarObjectList_t))
#define SIL_HLA_MEAS_VADDR_REQ_PORT_VDY_DATA               (SIL_HLA_MEAS_VADDR_REQ_PORT_VEH_SIG                + HLA_MEAS_VADDR_PADDING_BYTES + sizeof(VehSig_t))
#define SIL_HLA_MEAS_VADDR_REQ_PORT_BLOCKAGE_OUTPUTS       (SIL_HLA_MEAS_VADDR_REQ_PORT_VDY_DATA               + HLA_MEAS_VADDR_PADDING_BYTES + sizeof(VehDyn_t))
#define SIL_HLA_MEAS_VADDR_REQ_PORT_EM_OBJECT_LIST         (SIL_HLA_MEAS_VADDR_REQ_PORT_BLOCKAGE_OUTPUTS       + HLA_MEAS_VADDR_PADDING_BYTES + sizeof(CB_t_ProvidedOutputs_t))
#define SIL_HLA_MEAS_VADDR_REQ_PORT_LD_OUT                 (SIL_HLA_MEAS_VADDR_REQ_PORT_EM_OBJECT_LIST         + HLA_MEAS_VADDR_PADDING_BYTES + sizeof(EM_t_GenObjectList))
#define SIL_HLA_MEAS_VADDR_REQ_PORT_LSD_ENVIRONMENT_DATA   (SIL_HLA_MEAS_VADDR_REQ_PORT_LD_OUT                 + HLA_MEAS_VADDR_PADDING_BYTES + sizeof(LdOutputData_t))
#define SIL_HLA_MEAS_VADDR_REQ_PORT_LSD_LIGHT_OBJECT_LIST  (SIL_HLA_MEAS_VADDR_REQ_PORT_LSD_ENVIRONMENT_DATA   + HLA_MEAS_VADDR_PADDING_BYTES + sizeof(LSD_EnvironmentData_t))
#define SIL_HLA_MEAS_VADDR_REQ_PORT_LSD_LIGHT_LIST         (SIL_HLA_MEAS_VADDR_REQ_PORT_LSD_LIGHT_OBJECT_LIST  + HLA_MEAS_VADDR_PADDING_BYTES + sizeof(LSD_LightObjectList_t))

/* Virtual addresses for HIL measfreezes, i.e. triggered from SIL wrapper */
#define HIL_HLA_MEAS_VADDR_ALGO_COMP_STATE   (SIL_HLA_MEAS_VADDR_REQ_PORT_LSD_LIGHT_OBJECT_LIST + HLA_MEAS_VADDR_PADDING_BYTES + sizeof(LSD_LightObjectList_t))
                                                                                                
#define HIL_HLA_MEAS_VADDR_RTA_BUFFER        (HIL_HLA_MEAS_VADDR_ALGO_COMP_STATE                + HLA_MEAS_VADDR_PADDING_BYTES + sizeof(AlgoCompState_t))
#define HIL_HLA_MEAS_VADDR_RTA_BUFFER_EVE    (HIL_HLA_MEAS_VADDR_RTA_BUFFER                     + HLA_MEAS_VADDR_PADDING_BYTES + sizeof(AS_t_RtaBuffer))


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
  FUNCTIONS 
*****************************************************************************/

#endif /* #ifndef SIM_HLA_MEASFREEZE_DATA_H */
