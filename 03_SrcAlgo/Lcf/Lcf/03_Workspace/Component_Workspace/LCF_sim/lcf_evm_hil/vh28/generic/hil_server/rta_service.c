#include "rta_service.h"
#include "string.h"
#include "stdlib.h"

#include <xdc/runtime/Types.h>
#include <xdc/runtime/Timestamp.h>
#include <ti/sysbios/hal/Timer.h>
#include <ti/sysbios/hal/Hwi.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/SysStd.h>

static AS_t_RtaBuffer* m_pRtaBuffer        = 0;
static uint32          m_u_CoreID          = 0;
static uint64          m_uFakeCycleTime_us = 0; /* this is used to emulate ECU-like cycle-times (cycle-time on EVM is really long, due to Ethernet, MTS...) */
static uint64          m_uReferenceTS_us   = 0; /* reference timestamp of the cycle */

/* performance counter configuration */
static SdRamCtrlCntrCfg_t m_CntConfig1 = DDRCTRL_CNTRX_CFG_TOTAL_ACCESSES;
static SdRamCtrlMConnId_t m_MConnId1   = DDRCTRL_MCONNID__ALL__;
static SdRamCtrlCntrCfg_t m_CntConfig2 = DDRCTRL_CNTRX_CFG_TOTAL_ACCESSES;
static SdRamCtrlMConnId_t m_MConnId2   = DDRCTRL_MCONNID__ALL__;

/* prototype */
static void InitPerfCounter(uint32 uCycleTimeBandwidthSampling_us);

static uint64 GetSystemTs_us()
{
  Types_Timestamp64 ts;
  Types_FreqHz      freq;

  uint64 ui_ts;
  uint64 ui_freq;

  Timestamp_get64(&ts);
  Timestamp_getFreq(&freq);

  ui_ts   = (uint64)ts.hi   * (uint64)0x100000000 + (uint64)ts.lo;
  ui_freq = (uint64)freq.hi * (uint64)0x100000000 + (uint64)freq.lo;

  ui_freq = ui_freq / 1e6;  /* convert to MHz */

  return (ui_ts/ui_freq);
}

/* translates the performance counter access mode for RTA Analyse Tool (MTS) */
static uint8 TranslatePerfCounterMode(SdRamCtrlCntrCfg_t Config)
{
  uint8 uMode;

  switch (Config)
  {
    case DDRCTRL_CNTRX_CFG_TOTAL_ACCESSES:
      uMode = 2;
      break;
    case DDRCTRL_CNTRX_CFG_TOTAL_READS:
      uMode = 0;
      break;
    case DDRCTRL_CNTRX_CFG_TOTAL_WRITES:
      uMode = 1;
      break;
    case DDRCTRL_CNTRX_CFG_TOTAL_ACTIVATES:
      /* falls through */
    default:
      /* not yet supported */
      uMode = 0xFFu;

  }

  return uMode;
}

void InitEvmServiceParams_Rta(Rta_EvmServiceParams_t *pParams)
{
  pParams->pRtaBuffer                = NULL;
  pParams->u_CoreID                  = 12;
  pParams->uFakeCycleTime_us         = 60000;
#ifdef RTA_TARGET_VISION_HIGH
  pParams->PerfCounter1.MConnId      = DDRCTRL_MCONNID_DSP1_MDMA;        /* Default: C66xx */
#else
  pParams->PerfCounter1.MConnId      = DDRCTRL_MCONNID_MMU;              /* Default: C674x */
#endif
  pParams->PerfCounter1.Config       = DDRCTRL_CNTRX_CFG_TOTAL_ACCESSES;
#ifdef RTA_TARGET_VISION_HIGH
  pParams->PerfCounter2.MConnId      = DDRCTRL_MCONNID_EVE1_P1;          /* Default: EVE */
#else
  pParams->PerfCounter2.MConnId      = DDRCTRL_MCONNID_HDVICP;           /* Default: EVE */
#endif
  pParams->PerfCounter2.Config       = DDRCTRL_CNTRX_CFG_TOTAL_ACCESSES;
  pParams->uBandwidthSamplingRate_us = 500;
}

void InitEvmService_Rta(AS_t_RtaBuffer* pRtaBuffer, uint32 u_CoreID, uint64 uFakeCycleTime_us)
     /* uFakeCycleTime_us: When different from 0, this is used to emulate ECU-like cycle-times (cycle-time on EVM is really long, due to Ethernet, MTS...) */
{
  Rta_EvmServiceParams_t params;

  /* create setup */
  InitEvmServiceParams_Rta(&params);
  params.pRtaBuffer                = pRtaBuffer;
  params.u_CoreID                  = u_CoreID;
  params.uFakeCycleTime_us         = uFakeCycleTime_us;

  InitEvmServiceCustom_Rta(&params);
}

void InitEvmServiceCustom_Rta(Rta_EvmServiceParams_t *pParams)
     /* uFakeCycleTime_us: When different from 0, this is used to emulate ECU-like cycle-times (cycle-time on EVM is really long, due to Ethernet, MTS...) */
{
  m_pRtaBuffer        = pParams->pRtaBuffer;
  m_u_CoreID          = pParams->u_CoreID;
  m_uFakeCycleTime_us = pParams->uFakeCycleTime_us;
  m_CntConfig1        = pParams->PerfCounter1.Config;
  m_MConnId1          = pParams->PerfCounter1.MConnId;
  m_CntConfig2        = pParams->PerfCounter2.Config;
  m_MConnId2          = pParams->PerfCounter2.MConnId;

  InitPerfCounter(pParams->uBandwidthSamplingRate_us);
}

uint32 Rta_ExtractRuntime(uint8 ID)
{
  uint32 Stop  = 0;
  uint32 Start = 0;
  uint32 i;
  uint32 HwiKey = 0;

  if (m_pRtaBuffer != 0)
  {
    HwiKey = Hwi_disable();

    if (AS_RTA_MAX_EVENTS > m_pRtaBuffer->u_MaxEventIndex)
    {
      for (i=0; i<m_pRtaBuffer->u_MaxEventIndex; i++)
      {
        if (m_pRtaBuffer->EventContainer[i].u_IdLocal == ID)
        {
          if (e_RTA_EVT_AlgoStart == m_pRtaBuffer->EventContainer[i].u_EventType)
          {
            Start = m_pRtaBuffer->EventContainer[i].u_RelTs_us;
          }

          if (e_RTA_EVT_AlgoEnd == m_pRtaBuffer->EventContainer[i].u_EventType)
          {
            Stop  = m_pRtaBuffer->EventContainer[i].u_RelTs_us;
          }
        }
      }
    }
    Hwi_restore(HwiKey);
  }

  return Stop - Start;
}

void Rta_NewCycle()
{
  uint32 HwiKey = 0;

  if (m_pRtaBuffer != 0)
  {
    HwiKey = Hwi_disable();

    m_pRtaBuffer->u_ContainerSize   = AS_RTA_MAX_EVENTS;
    m_pRtaBuffer->u_MaxEventIndex   = 0;
    m_uReferenceTS_us = GetSystemTs_us();
    if (0 == m_uFakeCycleTime_us)
    {
      m_pRtaBuffer->u_RefTs_us      = m_uReferenceTS_us;
    }
    else
    {
      m_pRtaBuffer->u_RefTs_us     += m_uFakeCycleTime_us;
    }
    m_pRtaBuffer->u_CoreID          = m_u_CoreID;

    Hwi_restore(HwiKey);

    Rta_AlgoServiceAddEvent(e_RTA_EVT_Marker, 162, 1, 0);

    /* translate access mode for MTS RTA Analysis Tool */
    uint8 uAccessMode1 = TranslatePerfCounterMode(m_CntConfig1);
    uint8 uAccessMode2 = TranslatePerfCounterMode(m_CntConfig2);

    switch (m_MConnId1)
    {
#ifdef RTA_TARGET_VISION_HIGH
      case DDRCTRL_MCONNID_CORTEX_A15: /* CortexA15 */
        Rta_AlgoServiceAddEvent(e_RTA_EVT_SampleSelect, 0, 1, uAccessMode1);
        break;
      case DDRCTRL_MCONNID_DSP1_MDMA: /* C66xx */
        Rta_AlgoServiceAddEvent(e_RTA_EVT_SampleSelect, 0, 4, uAccessMode1);
        break;
      case DDRCTRL_MCONNID_EVE1_P1:   /* EVE */
        Rta_AlgoServiceAddEvent(e_RTA_EVT_SampleSelect, 0, 6, uAccessMode1);
        break;
#else
      case DDRCTRL_MCONNID_CORTEX_A8: /* CortexA8 */
        Rta_AlgoServiceAddEvent(e_RTA_EVT_SampleSelect, 0, 1, uAccessMode1);
        break;
      case DDRCTRL_MCONNID_MMU:       /* C674x */
        Rta_AlgoServiceAddEvent(e_RTA_EVT_SampleSelect, 0, 4, uAccessMode1);
        break;
      case DDRCTRL_MCONNID_HDVICP:    /* EVE */
        Rta_AlgoServiceAddEvent(e_RTA_EVT_SampleSelect, 0, 6, uAccessMode1);
        break;
#endif
      case DDRCTRL_MCONNID__ALL__:    /* no master filter */
        Rta_AlgoServiceAddEvent(e_RTA_EVT_SampleSelect, 0, 0xFF, uAccessMode1);
        break;
      default:
        /* not supported: do not add any sample select */
        break;
    }

    switch (m_MConnId2)
    {
#ifdef RTA_TARGET_VISION_HIGH
      case DDRCTRL_MCONNID_CORTEX_A15: /* CortexA15 */
        Rta_AlgoServiceAddEvent(e_RTA_EVT_SampleSelect, 1, 1, uAccessMode2);
        break;
      case DDRCTRL_MCONNID_DSP1_MDMA: /* C66xx */
        Rta_AlgoServiceAddEvent(e_RTA_EVT_SampleSelect, 1, 4, uAccessMode2);
        break;
      case DDRCTRL_MCONNID_EVE1_P1:   /* EVE */
        Rta_AlgoServiceAddEvent(e_RTA_EVT_SampleSelect, 1, 6, uAccessMode2);
        break;
#else
      case DDRCTRL_MCONNID_CORTEX_A8: /* CortexA8 */
        Rta_AlgoServiceAddEvent(e_RTA_EVT_SampleSelect, 1, 1, uAccessMode2);
        break;
      case DDRCTRL_MCONNID_MMU:       /* C674x */
        Rta_AlgoServiceAddEvent(e_RTA_EVT_SampleSelect, 1, 4, uAccessMode2);
        break;
      case DDRCTRL_MCONNID_HDVICP:    /* EVE */
        Rta_AlgoServiceAddEvent(e_RTA_EVT_SampleSelect, 1, 6, uAccessMode2);
        break;
#endif
      case DDRCTRL_MCONNID__ALL__:    /* no master filter */
        Rta_AlgoServiceAddEvent(e_RTA_EVT_SampleSelect, 1, 0xFF, uAccessMode2);
        break;
      default:
        /* not supported: do not add any sample select */
        break;
    }
  }

}


void Rta_AlgoServiceAddEvent(AS_t_RtaEventType RtaEvtType, uint8 IdGlobal, uint8 IdLocal, uint8 OptData)
{
  uint32 HwiKey = 0;

  if (m_pRtaBuffer != 0)
  {
    HwiKey = Hwi_disable();

    if ( m_pRtaBuffer->u_MaxEventIndex < AS_RTA_MAX_EVENTS )
    {
      m_pRtaBuffer->EventContainer[m_pRtaBuffer->u_MaxEventIndex].u_EventType = (uint8)RtaEvtType;
      m_pRtaBuffer->EventContainer[m_pRtaBuffer->u_MaxEventIndex].u_OptData   = OptData;
      m_pRtaBuffer->EventContainer[m_pRtaBuffer->u_MaxEventIndex].u_IdGlobal  = IdGlobal;
      m_pRtaBuffer->EventContainer[m_pRtaBuffer->u_MaxEventIndex].u_IdLocal   = IdLocal;
      m_pRtaBuffer->EventContainer[m_pRtaBuffer->u_MaxEventIndex].u_RelTs_us  = GetSystemTs_us() - m_uReferenceTS_us;
      m_pRtaBuffer->u_MaxEventIndex++;
    }

    Hwi_restore(HwiKey);
  }
}

void Rta_GetCopyOfBuffer(AS_t_RtaBuffer* pTargetBuffer)
{
  uint32 HwiKey = 0;

  if ((m_pRtaBuffer != 0) && (pTargetBuffer != 0))
  {
    HwiKey = Hwi_disable();
    memcpy(pTargetBuffer, m_pRtaBuffer, sizeof(AS_t_RtaBuffer));
    Hwi_restore(HwiKey);
  }
}


/**************************************************************/
/* RTA bandwidth measurement (based on performance counters): */
/**************************************************************/

static uint32 m_PerfCntPrev[PERF_COUNT_NUMBER_OF]  = { 0 };
static uint32 m_PerfCntDelta[PERF_COUNT_NUMBER_OF] = { 0 };
static SdRamCtrlRegs_t volatile * m_p_SdRamCtrlRegs = (SdRamCtrlRegs_t *)REG_BASE_DDR0;

Timer_Handle hRta_TimerSamplePerfCounter = 0;

void Rta_TimerSamplePerfCounter()
{
  sint32 i = 0;

  uint8 PerfCntDelta_high[PERF_COUNT_NUMBER_OF];
  uint8 PerfCntDelta_low[PERF_COUNT_NUMBER_OF];

  m_PerfCntDelta[PERF_COUNT1] = m_p_SdRamCtrlRegs->u_PerfCnt1 - m_PerfCntPrev[PERF_COUNT1];
  m_PerfCntPrev[PERF_COUNT1]  = m_p_SdRamCtrlRegs->u_PerfCnt1;

  m_PerfCntDelta[PERF_COUNT2] = m_p_SdRamCtrlRegs->u_PerfCnt2 - m_PerfCntPrev[PERF_COUNT2];
  m_PerfCntPrev[PERF_COUNT2]  = m_p_SdRamCtrlRegs->u_PerfCnt2;

  for (i=PERF_COUNT1; i<PERF_COUNT_NUMBER_OF; i++)
  {
    m_PerfCntDelta[i] /= PERF_CNT_SCALING_FACTOR;

    if (m_PerfCntDelta[i] <= 0xFFFF)
    {
      PerfCntDelta_high[i] = (uint8)(m_PerfCntDelta[i] >> 8);
      PerfCntDelta_low[i]  = (uint8)(m_PerfCntDelta[i]);
    }
    else
    {
      PerfCntDelta_high[i] = 0xFF;
      PerfCntDelta_low[i]  = 0xFF;
    }
    Rta_AlgoServiceAddEvent(e_RTA_EVT_SampleValue, (uint8)i, (uint8)PerfCntDelta_high[i], (uint8)PerfCntDelta_low[i]);
  }
}

void InitEvmService_RtaPerfCount(uint32 uCycleTimeBandwidthSampling_us)
{
  /*
   * DEPRECATED: replaced by static function InitPerfCounter!!!
   *
   * The initialization of the performance counter is now integrated in InitEvmServiceCustom_Rta().
   * This function body is kept for compatibility reasons. This may be cleaned up if no more referenced.
   */
}

void Rta_StartBandwidthMeasurement()
{
  sint32 i = 0;
  uint32 HwiKey = 0;

  HwiKey = Hwi_disable();

  m_PerfCntPrev[PERF_COUNT1]  = m_p_SdRamCtrlRegs->u_PerfCnt1;
  m_PerfCntDelta[PERF_COUNT1] = 0;

  m_PerfCntPrev[PERF_COUNT2]  = m_p_SdRamCtrlRegs->u_PerfCnt2;
  m_PerfCntDelta[PERF_COUNT2] = 0;
  Hwi_restore(HwiKey);

  for (i=PERF_COUNT1; i<PERF_COUNT_NUMBER_OF; i++)
  {
    Rta_AlgoServiceAddEvent(e_RTA_EVT_SampleValue, (uint8)i, (uint8)0, (uint8)0);
  }

  if (hRta_TimerSamplePerfCounter != 0)
  {
    Timer_start(hRta_TimerSamplePerfCounter);
  }
}

void Rta_StopBandwidthMeasurement()
{
  if (hRta_TimerSamplePerfCounter != 0)
  {
    Timer_stop(hRta_TimerSamplePerfCounter);
  }
  Rta_TimerSamplePerfCounter();
}

static void InitPerfCounter(uint32 uCycleTimeBandwidthSampling_us)
{
  uint32 HwiKey = 0;
  Timer_Params TimerParams;
  Error_Block eb;

  HwiKey = Hwi_disable();

  Timer_Params_init(&TimerParams);
  Error_init(&eb);
  TimerParams.arg        = NULL;
  TimerParams.period     = uCycleTimeBandwidthSampling_us;
  TimerParams.extFreq.hi = 0;
  TimerParams.extFreq.lo = 0x01312d00;  /* timer is clocked with 20MHz on our EVM */
  TimerParams.periodType = Timer_PeriodType_MICROSECS;
  TimerParams.runMode    = Timer_RunMode_CONTINUOUS;
  TimerParams.startMode  = Timer_StartMode_USER;

  hRta_TimerSamplePerfCounter = Timer_create(Timer_ANY, (Timer_FuncPtr) &Rta_TimerSamplePerfCounter, &TimerParams, &eb);
  if (hRta_TimerSamplePerfCounter == NULL)
  {
    // "RTA-bandwidth profiling timer creation failed"
    abort();
  }
  Hwi_restore(HwiKey);

  /* Configure performance counter 1 */
  m_p_SdRamCtrlRegs->perfCntCfg.fields.u_Cntr1Cfg       = m_CntConfig1;
  if (m_MConnId1 != DDRCTRL_MCONNID__ALL__)
  {
    m_p_SdRamCtrlRegs->perfCntCfg.fields.u_Cntr1MConnIdEn = PERF_COUNT_ENABLE;
    m_p_SdRamCtrlRegs->perfCntSel.fields.u_MConnId1       = m_MConnId1;
  }
  else
  {
    m_p_SdRamCtrlRegs->perfCntCfg.fields.u_Cntr1MConnIdEn = PERF_COUNT_DISABLE;
  }

  /* Configure performance counter 2 */
  m_p_SdRamCtrlRegs->perfCntCfg.fields.u_Cntr2Cfg       = m_CntConfig2;
  if (m_MConnId2 != DDRCTRL_MCONNID__ALL__)
  {
    m_p_SdRamCtrlRegs->perfCntCfg.fields.u_Cntr2MConnIdEn = PERF_COUNT_ENABLE;
    m_p_SdRamCtrlRegs->perfCntSel.fields.u_MConnId2       = m_MConnId2;
  }
  else
  {
    m_p_SdRamCtrlRegs->perfCntCfg.fields.u_Cntr2MConnIdEn = PERF_COUNT_DISABLE;
  }
}
