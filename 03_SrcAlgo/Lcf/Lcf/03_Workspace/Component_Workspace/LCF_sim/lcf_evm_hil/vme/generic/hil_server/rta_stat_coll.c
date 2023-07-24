/*-------------------------------------------------------------------------
 |
 |  File Name   :  $Source: rta_stat_coll.c $
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
 |  Description : The VH28 statistics collector API.
 |
 |
 |  Developer  :  Roland Stark
 |
 |  Last Revision     $Revision: 1.1 $
 |  Last Author       $Author: Wang, David (Wangd3) $
 |
 +-------------------------------------------------------------------------*/

#include <string.h>
#include "glob_type.h"
#include "rta_stat_coll.h"

void Rta_StatColl_Init(StatCollRegs_t *pRegs)
{
  sint32 i, j;

  /* init basic register set */
  pRegs->en                = SC_DISABLE;
  pRegs->soften            = SC_DISABLE;
  pRegs->ignore_suspend    = SC_DISABLE;
  pRegs->trigen            = SC_DISABLE;
  pRegs->reqevt            = SC_EVENT_SEL_PKT; // we support only bandwidth measurement
  pRegs->rspevt            = SC_EVENT_SEL_PKT;
  pRegs->dump_collecttime  = 0;
  pRegs->dump_slvofs       = 0;
  pRegs->dump_manual       = SC_ENABLE; // we support only manual dump mode
  pRegs->dump_disable      = SC_DISABLE;
  pRegs->dump_alarm_minval = 0;
  pRegs->dump_alarm_maxval = 0;

  /* init counter setups */
  for (i = 0; i < SC_COUNTER_NUM; ++i)
  {
    pRegs->evtmux_sel[i] = 0;
    pRegs->dump_alarm_mode[i] = 0;

    pRegs->counter_setup[i].globalen = SC_DISABLE;
    pRegs->counter_setup[i].addrmin = 0;
    pRegs->counter_setup[i].addrmax = 0;
    pRegs->counter_setup[i].addren = SC_DISABLE;
    pRegs->counter_setup[i].op_threshold_minval = 0;
    pRegs->counter_setup[i].op_threshold_maxval = 0;
    pRegs->counter_setup[i].op_evt_info_sel = SC_EVTINFOSEL_BYTELEN;
    pRegs->counter_setup[i].op_sel = SC_OPSEL_FILTER_HIT;

    /* zero filter setups */
    for (j = 0; j < SC_FILTER_NUM; ++j)
    {
      pRegs->counter_setup[i].filter_setup[j].en = SC_DISABLE;
      pRegs->counter_setup[i].filter_setup[j].mask_rd = 0;
      pRegs->counter_setup[i].filter_setup[j].mask_wr = 0;
      pRegs->counter_setup[i].filter_setup[j].mask_mstaddr = 0;
      pRegs->counter_setup[i].filter_setup[j].mask_slvaddr = 0;
      pRegs->counter_setup[i].filter_setup[j].mask_err = 0;
      pRegs->counter_setup[i].filter_setup[j].mask_userinfo = 0;
      pRegs->counter_setup[i].filter_setup[j].mask_requserinfo = 0;
      pRegs->counter_setup[i].filter_setup[j].mask_rspuserinfo = 0;
      pRegs->counter_setup[i].filter_setup[j].match_rd = 0;
      pRegs->counter_setup[i].filter_setup[j].match_wr = 0;
      pRegs->counter_setup[i].filter_setup[j].match_mstaddr = 0;
      pRegs->counter_setup[i].filter_setup[j].match_slvaddr = 0;
      pRegs->counter_setup[i].filter_setup[j].match_err = 0;
      pRegs->counter_setup[i].filter_setup[j].match_userinfo = 0;
      pRegs->counter_setup[i].filter_setup[j].match_requserinfo = 0;
      pRegs->counter_setup[i].filter_setup[j].match_rspuserinfo = 0;
    }

    /* zero unsupported filter setups */
    for (j = 0; j < (sizeof(pRegs->counter_setup[i].not_supported) >> 2); ++j)
    {
      pRegs->counter_setup[i].not_supported[j] = 0;
    }
  }
}

StatCollStatus_t Rta_StatColl_EnableCounter(StatCollRegs_t *pRegs, uint32 uIndexCnt, uint32 uIndexFilter,
                                            StatCollProbeIdSdram_t probe, StatCollMeasMode_t mode,
                                            SdRamCtrlMConnId_t mstid)
{
  StatCollStatus_t ret = SC_STATUS_OK;

  if ((pRegs != 0) && (uIndexCnt < SC_COUNTER_NUM) && (uIndexFilter < SC_FILTER_NUM))
  {
    pRegs->evtmux_sel[uIndexCnt] = probe;

    pRegs->counter_setup[uIndexCnt].globalen = SC_ENABLE;
    pRegs->counter_setup[uIndexCnt].op_evt_info_sel = SC_EVTINFOSEL_BYTELEN;
    pRegs->counter_setup[uIndexCnt].op_sel = SC_OPSEL_EVT_INFO; // we support only bandwidth measurement

    switch (mode)
    {
      case SC_MEAS_MODE_ALL:
        /* disable RD + WR filter to dump complete traffic */
        pRegs->counter_setup[uIndexCnt].filter_setup[uIndexFilter].mask_rd  = SC_DISABLE;
        pRegs->counter_setup[uIndexCnt].filter_setup[uIndexFilter].mask_wr  = SC_DISABLE;
        pRegs->counter_setup[uIndexCnt].filter_setup[uIndexFilter].match_rd = SC_DISABLE;
        pRegs->counter_setup[uIndexCnt].filter_setup[uIndexFilter].match_wr = SC_DISABLE;
        break;
      case SC_MEAS_MODE_RD:
        pRegs->counter_setup[uIndexCnt].filter_setup[uIndexFilter].mask_rd  = SC_ENABLE;
        pRegs->counter_setup[uIndexCnt].filter_setup[uIndexFilter].mask_wr  = SC_DISABLE;
        pRegs->counter_setup[uIndexCnt].filter_setup[uIndexFilter].match_rd = SC_ENABLE;
        pRegs->counter_setup[uIndexCnt].filter_setup[uIndexFilter].match_wr = SC_DISABLE;
        break;
      case SC_MEAS_MODE_WR:
        pRegs->counter_setup[uIndexCnt].filter_setup[uIndexFilter].mask_rd  = SC_DISABLE;
        pRegs->counter_setup[uIndexCnt].filter_setup[uIndexFilter].mask_wr  = SC_ENABLE;
        pRegs->counter_setup[uIndexCnt].filter_setup[uIndexFilter].match_rd = SC_DISABLE;
        pRegs->counter_setup[uIndexCnt].filter_setup[uIndexFilter].match_wr = SC_ENABLE;
        break;
      default:
        /* invalid mode */
        ret = SC_STATUS_ERR_MODE;
    }

    if (DDRCTRL_MCONNID__ALL__ == mstid)
    {
      /* disable master filter to dump complete traffic */
      pRegs->counter_setup[uIndexCnt].filter_setup[uIndexFilter].mask_mstaddr = 0;
      pRegs->counter_setup[uIndexCnt].filter_setup[uIndexFilter].match_mstaddr = 0;
    }
    else
    {
      /* mask all bits for all masters -> then set match-filter to specific master */
      pRegs->counter_setup[uIndexCnt].filter_setup[uIndexFilter].mask_mstaddr = 0xFF;
      pRegs->counter_setup[uIndexCnt].filter_setup[uIndexFilter].match_mstaddr = mstid;
    }

    /* enable the filter */
    pRegs->counter_setup[uIndexCnt].filter_setup[uIndexFilter].en = SC_ENABLE;
  }
  else
  {
    /* invalid indices */
    ret = SC_STATUS_ERR_PARAM;
  }

  return ret;
}

StatCollStatus_t Rta_StatColl_AddrRange(StatCollRegs_t *pRegs, uint32 uIndexCnt, uint32 uAddrMin, uint32 uAddrMax)
{
  StatCollStatus_t ret = SC_STATUS_OK;

  /* only supported for SDRAM collector */
  if (pRegs == SC_GET_REG_PTR(SC_SDRAM_BASE))
  {
    if (uIndexCnt < SC_COUNTER_NUM)
    {
      if ((uAddrMin >= uAddrMax) || ((uAddrMax - uAddrMin) < (1 << SC_ADDR_FILTER_SHIFT)))
      {
        /* invalid address filter range */
        ret = SC_STATUS_ERR_ADDR_RANGE;
      }
      else if (uAddrMin >= SC_SDRAM_BASE_ADDR)
      {
        pRegs->counter_setup[uIndexCnt].addrmin = (uAddrMin - SC_SDRAM_BASE_ADDR) >> SC_ADDR_FILTER_SHIFT;
        pRegs->counter_setup[uIndexCnt].addrmax = (uAddrMax - SC_SDRAM_BASE_ADDR) >> SC_ADDR_FILTER_SHIFT;
        pRegs->counter_setup[uIndexCnt].addren = SC_ENABLE;
      }
      else
      {
        pRegs->counter_setup[uIndexCnt].addrmin = uAddrMin >> SC_ADDR_FILTER_SHIFT;
        pRegs->counter_setup[uIndexCnt].addrmax = uAddrMax >> SC_ADDR_FILTER_SHIFT;
        pRegs->counter_setup[uIndexCnt].addren = SC_ENABLE;
      }
    }
    else
    {
      /* invalid indices */
      ret = SC_STATUS_ERR_PARAM;
    }
  }
  else
  {
    /* invalid indices */
    ret = SC_STATUS_ERR_PARAM;
  }

  return ret;
}

void Rta_StatColl_Enable(StatCollRegs_t *pRegs)
{
  if (pRegs != 0)
  {
    pRegs->en = SC_ENABLE;
    pRegs->soften = SC_ENABLE;
  }
}

void Rta_StatColl_Disable(StatCollRegs_t *pRegs)
{
  if (pRegs != 0)
  {
    pRegs->en = SC_DISABLE;
    pRegs->soften = SC_DISABLE;
  }
}

void Rta_StatColl_Reset(StatCollRegs_t *pRegs)
{
  if (pRegs != 0)
  {
    pRegs->dump_send = SC_ENABLE;
  }
}

