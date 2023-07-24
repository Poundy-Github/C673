/*-------------------------------------------------------------------------
 |
 |  File Name   :  $Source: CortexM4_EvmHilWrapper.h $
 |
 | ------------------------------------------------------------------------
 |
 |  COPYRIGHT (C) Continental Automotive AG 2008
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
 |  Description : VME Evalboard-HIL simulation wrapper
 |
 |
 |
 |  Developer  :  Ulrich Wagner
 |
 |  Last Revision     $Revision: 1.1 $
 |  Last Author       $Author: Fischer, Stephan02 (uidg9447) $
 |              
 +-------------------------------------------------------------------------*/

#ifndef CORTEXM4_EVMHILWRAPPER_H__
#define CORTEXM4_EVMHILWRAPPER_H__


#include "algo_scheduler.h"
#include "glob_type.h"


class C_HilSimulation : public C_AlgoBase
{
public:
    C_HilSimulation();
    ~C_HilSimulation();

  void Init(int i32_Param);
  void Run (int);
  void Exit(int) {};
};

#endif

