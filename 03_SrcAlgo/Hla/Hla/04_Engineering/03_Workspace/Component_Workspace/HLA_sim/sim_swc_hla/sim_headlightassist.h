
#pragma once

#include "sim_swc_meas.h"
#include "sim_swc_cdl.h"
#include "simReceivePort.h"
#include "sim_algo_service_types.h"

#include "sim_hla_measdata.h"
#include "sim_visu_type.h"
#include "sim_hla_visu.h"
#include "hla_evm_hil_ports.h"

#include "sim_hla_recfileindex.h"

typedef struct  
{
  uint16 ImageData_Odd[IMAGE_MAX_NUM_PIXEL];
  uint16 ImageData_OddY0[IMAGE_MAX_NUM_PIXEL];
  uint16 ImageData_OddY1[IMAGE_MAX_NUM_PIXEL_SUBSAMPLED];
  uint8  ImageData_OddU1[IMAGE_MAX_NUM_PIXEL_SUBSAMPLED];
  uint8  ImageData_OddV1[IMAGE_MAX_NUM_PIXEL_SUBSAMPLED];
  uint16 ImageData_Even[IMAGE_MAX_NUM_PIXEL];
  uint8  ImageData_EvenSat[IMAGE_MAX_NUM_PIXEL_SUBSAMPLED];
  uint16 ImageData_EvenY0[IMAGE_MAX_NUM_PIXEL];
  uint16 ImageData_EvenY1[IMAGE_MAX_NUM_PIXEL_SUBSAMPLED];
  uint8  ImageData_EvenU1[IMAGE_MAX_NUM_PIXEL_SUBSAMPLED];
  uint8  ImageData_EvenV1[IMAGE_MAX_NUM_PIXEL_SUBSAMPLED];
} InputImageBuffer_Visu_t;

class CSimHeadLightAssist :
  public CSimHlaVisu,
  public CSimSwcMeas,
  virtual public CSimHlaMeasData,
  public CSimSwcCDL
{
public:
  CSimHeadLightAssist(CSimSwcBase*              pSimPlgBase, 
                      const char*              recFileName, 
                      const unsigned __int64& m_uiInputTimestamp
                      );
  ~CSimHeadLightAssist(void);

  CSimSwcBase* m_pSimPlgBase;

  SimHlaMeasdata_t        m_hlaMeasdata[VISU_MAX +1];
  SimHlaMeasdataBuffers_t m_hlaMeasdataBuffersSIL;

  sint8* m_pOverwriteInputs;

  /* global intern data for visualization */
  SimHlaInternMeasdataList_t m_hlaInternMeasdata;

  virtual const char* GetRecFile() = 0;

  virtual const char* GetRecFileName() = 0;

  virtual const char* GetRecFilePath() = 0;

  virtual const char* GetDllFile() = 0;

  virtual const char* GetDllFilePath() = 0;

protected:

  unsigned __int64 m_uiPrevTimestamp;
  unsigned __int64 m_uiInputTimestamp;

  void SimuInit(void);
  long Reset(char* szDLLPath);
  void InitGlobalVars();

  void CopyRTEInputData( SimHlaReqPrtList_t& pDest,
                         const SimHlaReqPrtList_t& pSrc
                       );
  void CopyImageData( const void*              pSrc, 
                      const uint32             imageSize,
                            void*              pDest, 
                            AlgoSignalState_t& destSigStatus
                     );
  void PrepareInputOutputSignals(boolean bResetNeeded);
  long RunAlgo(boolean bResetNeeded);

private:
  AlgoDataTimeStamp_t old_uiTimeStamp_Image_us;

  CSimHlaRecFileIndex m_recFileIndex;

  /* algo service functions */
  sim::as::CServiceTypes                    m_algoServicesInstance;
  AS_t_ServiceFuncts&                       m_algoServices;

  /* HIL */
  Mts2Hil_t                                 m_Mts2Hil;
  Hil2Mts_t&                                m_Hil2Mts;
  SimReceivePort<Hil2MtsArray_t, simUI8_t>  m_Hil2MtsPort;
  SimReceivePort<char, simI8_t >            m_EnableHil;
  uint8                                     m_isHilInitNeeded;
  uint32                                    m_maxNumMeasfreezedBytes;
  bool                                      m_recIsOnInternalIndex;

  void CopyRTEData(void** pDest, const void* pSrc, const uint32 length);
  void TriggerHil();
  void GenerateHotPixels(ImageU16_t* pImageOdd);
  void SetSimuOutput_Udex(boolean rte_inputs);
  void SetAdapter_RTE_In_Out(void);
  void LinkBuffers2AlgoInterMeasData(SimHlaInternMeasdataList_t &hlaInternMeasdata);
  void LinkBuffers2EVMInterMeasData(SimHlaInternMeasdataList_t &hlaInternMeasdata);
  void LinkBuffers2ECUInterMeasData(SimHlaInternMeasdataList_t &hlaInternMeasdata);
  void AddSimProvidePorts(CSimSwcBase* pSimPlgBase);
  void OverwriteRTEInput( boolean bResetNeeded);
};
