/*-------------------------------------------------------------------------
 |
 |  File Name   :  $Source: rta_stat_coll.h $
 |
 | ------------------------------------------------------------------------
 |
 |  COPYRIGHT (C) Continental Automotive AG 2014
 |  ALLE RECHTE VORBEHALTEN. ALL RIGHTS RESERVED.
 |
 |   The  reproduction,  transmission or  use  of  this  document or  its
 |   contents  is  not   permitted  without  express  written  authority.
 |   Offenders will  be liable for damages. All  rights, including rights
 |   created  by patent  grant  or  registration of  a  utility model  or
 |   design, are reserved.
 |
 | ------------------------------------------------------------------------
 |
 |  Description : Header of VH28 statistics collector API.
 |
 |
 |  Developer  :  Roland Stark
 |
 |  Last Revision     $Revision: 1.1 $
 |  Last Author       $Author: Wang, David (Wangd3) $
 |
 +-------------------------------------------------------------------------*/

#ifndef __RTA_STAT_COLL_H__
#define __RTA_STAT_COLL_H__

#include "rta_perf_cnt.h"


/* register base addresses for statitic collectors */
#define SC_SDRAM_BASE         (0x45001000)
#define SC_LAT_0_BASE         (0x45002000)
#define SC_LAT_1_BASE         (0x45003000)
#define SC_LAT_2_BASE         (0x45004000)
#define SC_LAT_3_BASE         (0x45005000)
#define SC_LAT_4_BASE         (0x45006000)
#define SC_LAT_5_BASE         (0x45007000)
#define SC_LAT_6_BASE         (0x45008000)
#define SC_LAT_7_BASE         (0x45009000)
#define SC_LAT_8_BASE         (0x4500A000)


#define SC_SDRAM_BASE_ADDR    (0x80000000)

/* macro for getting a pointer from base addresses above */
#define SC_GET_REG_PTR(base) (StatCollRegs_t *) base

/* macro for getting a value from a counter */
#define SC_GET_VALUE(reg_ptr,i) reg_ptr->dump_cnt[i]

#define SC_ENABLE              (1) // this enables a function
#define SC_DISABLE             (0) // this disables a function

#define SC_COUNTER_NUM         (8) // this is the maximum number of counters (for LAT collectors there are less)
#define SC_FILTER_NUM          (1) // this is the number of supported filters

#define SC_ADDR_FILTER_SHIFT  (12) // number of bits address filter is shifted


#ifdef __cplusplus
extern "C"
{
#endif

/* list of return values */
typedef enum
{
  SC_STATUS_OK  = 0,          // status ok
  SC_STATUS_ERR_MODE,         // invalid access mode was parameterized
  SC_STATUS_ERR_PARAM,        // any parameter is invalid
  SC_STATUS_ERR_ADDR_RANGE,   // invalid address filter range
  SC_STATUS_ERR_UNSUPPORTED,  // any function is not supported
  SC_STATUS_MAX               // number of possible states
} StatCollStatus_t;

/* If op_sel set to MIN_MAX_HIT or EVT_INFO then evt_info_sel applies */
typedef enum
{
  SC_MEAS_MODE_ALL = 0x0, // Length of transfer in bytes
  SC_MEAS_MODE_RD  = 0x1, // Length of transfer in bytes
  SC_MEAS_MODE_WR  = 0x2  // Length of transfer in bytes
} StatCollMeasMode_t;

typedef enum
{
  SC_EVENT_SEL_NONE     = 0x0, // No event selected
  SC_EVENT_SEL_ANY      = 0x1, // Any clock cycles
  SC_EVENT_SEL_TRANSFER = 0x2, // Header, necker or data has been accepted by the receiver
  SC_EVENT_SEL_WAIT     = 0x3, // Transfer initiated but the transmitter has no data to send
  SC_EVENT_SEL_BUSY     = 0x4, // Receiver applies flow control
  SC_EVENT_SEL_PKT      = 0x5, // Transfer of a new packet header
  SC_EVENT_SEL_DATA     = 0x6, // Transfer of a payload word (Request link: Store data, Respose link: Load data)
  SC_EVENT_SEL_IDLE     = 0x7, // No communication over the link
  SC_EVENT_SEL_LATENCY  = 0x8  // Debug bit detection
} StatCollEvent_t;

/* If op_sel set to MIN_MAX_HIT or EVT_INFO then evt_info_sel applies */
typedef enum
{
  SC_EVTINFOSEL_BYTELEN  = 0x0, // Length of transfer in bytes
  SC_EVTINFOSEL_PRESSURE = 0x1, // Pressure
  SC_EVTINFOSEL_LATENCY  = 0x2  // Amount of wait time
} StatCollEvtInfoSel_t;

/* op_sel determines how the counter functions */
typedef enum
{
  SC_OPSEL_FILTER_HIT   = 0x0, // Counter increments on a filter hit
  SC_OPSEL_MINMAX_HIT   = 0x1, // Counter increments when the filter hits
  SC_OPSEL_EVT_INFO     = 0x2, // Selected Evt_Info added to the counter value when the filter hits
  SC_OPSEL_AND_FILTER   = 0x3, // Counter increments by one when all unit filters hit.
  SC_OPSEL_OR_FILTER    = 0x4, // Counter increments by one when at least one unit filters hits.
  SC_OPSEL_SUM_REQ_EVT  = 0x5, // Counter sums the events from any request port.
  SC_OPSEL_SUM_RSP_EVT  = 0x6, // Counter sums the events from any response port.
  SC_OPSEL_SUM_ALL_EVT  = 0x7, // Counter sums the events from any request and response ports.
  SC_OPSEL_EX_EVT       = 0x8  // Counter increments by one when the selected ExtEvt input signal is sampled high
} StatCollOpSel_t;


typedef enum
{
  SC_PID_EMIF1_REQ      = 0x0, // port number for EMIF_1 request port
  SC_PID_EMIF1_RSP      = 0x1, // port number for EMIF_1 response port
  SC_PID_EMIF2_REQ      = 0x2, // port number for EMIF_2 request port
  SC_PID_EMIF2_RSP      = 0x3, // port number for EMIF_2 response port
  SC_PID_MA_MPU_P1_REQ  = 0x4, // port number for MPU_P1 request port
  SC_PID_MA_MPU_P1_RSP  = 0x5, // port number for MPU_P1 response port
  SC_PID_MA_MPU_P2_REQ  = 0x6, // port number for MPU_P2 request port
  SC_PID_MA_MPU_P2_RSP  = 0x7  // port number for MPU_P2 response port
} StatCollProbeIdSdram_t;

/* sdram statistic collector filter definition. R: read only, RW: read/write access */
typedef struct
{
  uint32 en;                // RW - 1: enable the filter, 0: disable
  uint32 mask_rd;           // RW - 1: mask read events (set also match)
  uint32 mask_wr;           // RW - 1: mask write events (set also match)
  uint32 mask_mstaddr;      // RW - 0xFF: mask all masters => see also "rta_perf_cnt.h" for master ID list */
  uint32 mask_slvaddr;      // RW - not supported
  uint32 mask_err;          // RW - not supported
  uint32 mask_userinfo;     // RW - not supported
  uint32 mask_requserinfo;  // RW - not supported
  uint32 mask_rspuserinfo;  // RW - not supported
  uint32 match_rd;          // 1: check if read event (set also mask)
  uint32 match_wr;          // 1: check if write event (set also mask)
  uint32 match_mstaddr;     // RW - check for mask all masters => see also "rta_perf_cnt.h" for master ID list */
  uint32 match_slvaddr;     // RW - not supported
  uint32 match_err;         // RW - not supported
  uint32 match_userinfo;    // RW - not supported
  uint32 match_requserinfo; // RW - not supported
  uint32 match_rspuserinfo; // RW - not supported
} StatCollFilterSetup_t;

/* statistic collector filter setup (each is designated to a counter). R: read only, RW: read/write access */
typedef struct
{
  uint32 globalen;                                    // RW - 1: enable the counter, 0: disable
  uint32 addrmin;                                     // RW - start address of monitored region (offset to SDRAM, right shift by 12)
  uint32 addrmax;                                     // RW - end address of monitored region (offset to SDRAM, right shift by 12)
  uint32 addren;                                      // RW - 1: enable address filter
  StatCollFilterSetup_t filter_setup[SC_FILTER_NUM];  // RW - see description of StatCollFilterSetup_t (we support only one filter some collectors have 2)
  uint32 not_supported[60];                           // RW - rest of filter register space (not supported)
  uint32 op_threshold_minval;                         // RW - lower threshold
  uint32 op_threshold_maxval;                         // RW - upper threshold
  uint32 op_evt_info_sel;                             // RW - StatCollEvtInfoSel_t type => see description
  uint32 op_sel;                                      // RW - StatCollOpSel_t type => see description
  uint32 reserved;                                    // xx - unused free space in register set
} StatCollCounterSetup_t;

/* statistic collector registers. R: read only, RW: read/write access */
typedef struct
{
  uint32 stdhosthdr_core;                               // R  - core and vendor code */
  uint32 stdhosthdr_version;                            // R  - revision ID and checksum */
  uint32 en;                                            // RW - 1: global enable, 0: disable
  uint32 soften;                                        // RW - 1: software enable, 0: disable
  uint32 ignore_suspend;                                // RW - 1: Ignore suspend mechanism, otherwise 0
  uint32 trigen;                                        // RW - 1: enable the external trigger start and stop, otherwise 0
  uint32 reqevt;                                        // RW - StatCollEvent_t => see description
  uint32 rspevt;                                        // RW - StatCollEvent_t => see description
  uint32 evtmux_sel[SC_COUNTER_NUM];                    // RW - select port for each counter (specific for each collector)
  uint32 dump_identifier;                               // R  - Probe identifier (0..9 depend on stat collector)
  uint32 dump_collecttime;                              // RW - Number of cycle to wait between two statistics frame.
  uint32 dump_slvaddr;                                  // R  - Dump slave address.
  uint32 dump_mstaddr;                                  // R  - Dump master address.
  uint32 dump_slvofs;                                   // RW - Dump slave offset, default: 0x800.
  uint32 dump_manual;                                   // RW - bit0: enable manual control, bit1: enable conditional control (alarm trigger)
  uint32 dump_send;                                     // RW - used in manual mode to send the dump content and initialize the counters.
  uint32 dump_disable;                                  // RW - 1: the dump frame will be disabled, but counters still active.
  uint32 dump_alarm_trig;                               // RW - 1: reset alarm (in alarm mode)
  uint32 dump_alarm_minval;                             // RW - triggers an alert if any of counter value is less
  uint32 dump_alarm_maxval;                             // RW - triggers an alert if any of counter value is larger
  uint32 dump_alarm_mode[SC_COUNTER_NUM];               // RW - 0:off, 1:min, 3:max, 2:both
  uint32 dump_cnt[SC_COUNTER_NUM];                      // RW - 32 bit counter values
  StatCollCounterSetup_t counter_setup[SC_COUNTER_NUM]; // xx - see description of StatCollCounterSetup_t
} StatCollRegs_t;

void Rta_StatColl_Init(StatCollRegs_t *pRegs);
StatCollStatus_t Rta_StatColl_EnableCounter(StatCollRegs_t *pRegs, uint32 uIndexCnt, uint32 uIndexFilter,
                                            StatCollProbeIdSdram_t probe, StatCollMeasMode_t mode,
                                            SdRamCtrlMConnId_t mstid);
StatCollStatus_t Rta_StatColl_AddrRange(StatCollRegs_t *pRegs, uint32 uIndexCnt, uint32 uAddrMin, uint32 uAddrMax);
void Rta_StatColl_Enable(StatCollRegs_t *pRegs);
void Rta_StatColl_Disable(StatCollRegs_t *pRegs);
void Rta_StatColl_Reset(StatCollRegs_t *pRegs);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __RTA_STAT_COLL_H__ */
