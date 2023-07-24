#pragma once

#include "sim_hla_common.h"

/*****************************************************************************
TYPEDEFS 
*****************************************************************************/

typedef struct
{
  /* intern measfreezes */
  SimHlaInternMeasdataList_t hlaInternMeasdata;
  /* input data */
  SimHlaReqPrtList_t  ReqPorts;
  /* output data */
  SimHlaProPrtList_t  ProPorts;
} SimHlaMeasdata_t;

typedef struct
{
  /* intern measfreezes */
  SimHlaInternMeasdataBuffers_t hlaInternMeasdataBuffers;
  /* input data */
  SimHlaReqPrtBuffers_t      ReqPortsBuffers;
  /* output data */
  SimHlaProPrtBuffers_t      ProPortsBuffers;
} SimHlaMeasdataBuffers_t;

class CSimHlaMeasData
{
public:
  CSimHlaMeasData(void);
  virtual ~CSimHlaMeasData(void);

  void LinkBuffers(SimHlaMeasdata_t& pointer, SimHlaMeasdataBuffers_t& buffer);
  void LinkBuffersInterMeasData(SimHlaInternMeasdataList_t& pointer, SimHlaInternMeasdataBuffers_t& buffer);
  void LinkBuffersReqPorts(SimHlaReqPrtList_t& pointer, SimHlaReqPrtBuffers_t& buffer);
  void LinkBuffersProPorts(SimHlaProPrtList_t& pointer, SimHlaProPrtBuffers_t& buffer);

protected:

private:

};
