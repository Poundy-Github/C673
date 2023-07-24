#include "stdafx.h"

#include "sim_hla_measdata.h"

CSimHlaMeasData::CSimHlaMeasData()
{

}

CSimHlaMeasData::~CSimHlaMeasData()
{

}

void CSimHlaMeasData::LinkBuffers(SimHlaMeasdata_t &pointer, SimHlaMeasdataBuffers_t &buffer)
{
  LinkBuffersInterMeasData(pointer.hlaInternMeasdata, buffer.hlaInternMeasdataBuffers);
  LinkBuffersReqPorts(pointer.ReqPorts, buffer.ReqPortsBuffers);
  LinkBuffersProPorts(pointer.ProPorts, buffer.ProPortsBuffers);
}

void CSimHlaMeasData::LinkBuffersInterMeasData(SimHlaInternMeasdataList_t &pointer, SimHlaInternMeasdataBuffers_t &buffer)
{
  /* inter measdata */
  pointer.pHlaErrorStack                 = &buffer.HlaErrorStack;
  pointer.pHlafData                      = &buffer.HlafData;

  /* Set evm specialties to NULL by default */
  pointer.pRtaBuffer      = NULL;
  pointer.pRtaBufferEve   = NULL;
}

void CSimHlaMeasData::LinkBuffersReqPorts(SimHlaReqPrtList_t &pointer, SimHlaReqPrtBuffers_t &buffer)
{
  pointer.pBaseCtrlData           = &buffer.BaseCtrlData;
  pointer.pCPar_HlafPar           = &buffer.CPar_HlafPar;
  pointer.pMonoCalibration        = &buffer.Sig_MonoCalibration;
  pointer.pHlaBusInputSignals     = &buffer.HlaBusInputSignals;
  pointer.pHlaRadarObjectList     = &buffer.HlaRadarObjectList;
  pointer.pVehSig                 = &buffer.SigVeh_VehSig;
  pointer.pVehDyn                 = &buffer.SigVeh_VDYData;
  pointer.pCbOutputs              = &buffer.Sig_Blockage;
  pointer.pGenObjectList          = &buffer.Sig_EMObjectsList;
  pointer.pLsdEnvironmentData     = &buffer.LsdEnvironmentData;
  pointer.pLsdLightObjectList     = &buffer.LsdLightObjectList;
  pointer.pLsdLightList           = &buffer.LsdLightList;
}

void CSimHlaMeasData::LinkBuffersProPorts(SimHlaProPrtList_t &pointer, SimHlaProPrtBuffers_t &buffer)
{
  pointer.pAlgoCompState          = &buffer.AlgoCompState;
  pointer.pHlaf_HeadlightControl  = &buffer.Hlaf_HeadlightControl;
}
