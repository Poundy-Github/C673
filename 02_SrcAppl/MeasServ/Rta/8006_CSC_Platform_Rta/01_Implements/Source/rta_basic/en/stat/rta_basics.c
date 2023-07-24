// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - RealTimeAnalysis
/// \file
/// \brief This file implements basic functions which are called in many other parts of the RTA.

#include <Std_Types.h>
#include <rta_datasets.h>
#include <rta_req_if.h>
#include <rta_basics.h>

#ifdef __cplusplus
extern "C"
{
#endif


#define CddSwc_RTA_START_SEC_CODE
#include <rta_memmap_cfg.h>

const RTA_t_DataSet* RTA_p_GetDataSet(void)
{
  // Get Core ID
  const uint32                      u_CORE_ID   = RTA_ReqIf_u_GetCoreId();
  const RTA_t_DataSet*              p_dataSet;

  if(rta_dataSetHandler.u_numberOfCores > u_CORE_ID)
  {
    // Select corresponding dataSet
    p_dataSet = rta_dataSetHandler.p_dataSets[u_CORE_ID];
  }
  else
  {
    // Set pointer to NULL
    p_dataSet = NULL;
  }

  return p_dataSet;
}

#define CddSwc_RTA_STOP_SEC_CODE
#include <rta_memmap_cfg.h>


#ifdef __cplusplus
}
#endif
