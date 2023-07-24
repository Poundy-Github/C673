#ifndef RTA_SERVICE_H__
#define RTA_SERVICE_H__

#include "glob_type.h"
#include "glob_comp_id.h"
#include "rtatype.h"
#include "rta_perf_cnt.h"


#ifdef __cplusplus
extern "C"
{
#endif


/*****************************************************************************
  TYPEDEFS
*****************************************************************************/

/* Services for getting timing information: */
typedef uint32 (*GetDSPTicks_t)     (void);    /* cf. CSF COD */

typedef uint32 (*GetTimeMicroSec_t) (void);    /* cf. MFC300 (Stereo, PV) */

typedef struct
{
  AS_t_RtaBuffer* pRtaBuffer;
  uint32 u_CoreID;
  uint64 uFakeCycleTime_us;           /* When different from 0, this is used to emulate ECU-like cycle-times (cycle-time on EVM is really long, due to Ethernet, MTS...) */
  SdRamCtrlPerfCntCfg_t PerfCounter1; /* Performance Counter 1 configuration */
  SdRamCtrlPerfCntCfg_t PerfCounter2; /* Performance Counter 1 configuration */
  uint32 uBandwidthSamplingRate_us;   /* Cycle time of bandwith sampling in micro seconds  */
} Rta_EvmServiceParams_t;


/*****************************************************************************
  PROTOTYPES
*****************************************************************************/

/* inits the parameters passed to function InitEvmServiceCustom_Rta */
void InitEvmServiceParams_Rta(Rta_EvmServiceParams_t *pParams);

/* DEPRECATED: use InitEvmServiceCustom_Rta instead */
void InitEvmService_Rta(AS_t_RtaBuffer* pRtaBuffer, uint32 u_CoreID, uint64 uFakeCycleTime_us);

/* see parameter struct for further description */
void InitEvmServiceCustom_Rta(Rta_EvmServiceParams_t *pParams);

/* DEPRECATED: replaced by static function and integrated in InitEvmServiceCustom_Rta(). KEEP IT FOR COMPATIBILITY REASONS! */
void InitEvmService_RtaPerfCount(uint32 uCycleTimeBandwidthSampling_us);

void   Rta_NewCycle();
void   Rta_AlgoServiceAddEvent(AS_t_RtaEventType RtaEvtType, uint8 IdGlobal, uint8 IdLocal, uint8 OptData);
uint32 Rta_ExtractRuntime(uint8 ID);
void   Rta_GetCopyOfBuffer(AS_t_RtaBuffer* TargetBuffer);


void Rta_StartBandwidthMeasurement();
void Rta_StopBandwidthMeasurement();

#ifdef __cplusplus
}
#endif

#endif //RTA_SERVICE_H__
