/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  COMPONENT:              HLA

  MODULNAME:              sim_hla_can.h

  DESCRIPTION:            HLA CAN Class

  AUTHOR:                 Alexander Fischer

  CREATION DATE:          2014-11-20

  VERSION:                $Revision: 1.1 $
 
**************************************************************************** */

#pragma once

#include "sim_swc_base.h"
#include "sim_swc_can.h"
#include "sim_versioninfo_impl.h"
#include "sim_swc_cycleinfo.h"
#include "sim_swc_synchronization.h"
#include "sim_swc_draw_base.h"
#include "sim_swc_dbg_exc.h"
#include "sim_hla_common.h"
#include "sim_hla_measdata.h"

typedef enum
{
  CANBMW_GMAB_STA_ADAPTIVE_LT_CTRL_OFF  = 0, /* adaptive light control off */
  CANBMW_GMAB_STA_ADAPTIVE_LT_CTRL_ON   = 1, /* adaptive light control on  */
  CANBMW_GMAB_STA_RESERVED              = 2,
  CANBMW_GMAB_STA_INVALID               = 3
}eSimHla_CanBMWStGmabAsstStatus_t;

typedef struct
{
  float32                           cutOffAng_lower;
  float32                           LightDist;
  float32                           cutOffAng_left;
  float32                           cutOffAng_right;
  eSimHla_CanBMWStGmabAsstStatus_t  cutOffAng_lower_Status;
  eSimHla_CanBMWStGmabAsstStatus_t  LightDist_Status;
  eSimHla_CanBMWStGmabAsstStatus_t  cutOffAng_left_Status;
  eSimHla_CanBMWStGmabAsstStatus_t  cutOffAng_right_Status;
}SimHla_CanBMWStGmabAsst_t;

typedef struct
{
  uint8                          LowBeamState;      /* (BMW: ST_DIPB) 0: off, 1: on low beams on */
  uint8                          FogLampFrontState; /* (BMW: ST_FFLI) 0: off, 1: on */
  uint8                          FogLampRearState;  /* (BMW: ST_RFLI) 0: off, 1: on */
  HLA_BusInputSignals_HlaRequest eHLAState;         /* (BMW: ST_MAB_ASST) HLA activated by the driver ? */
  uint8                          HBState;           /* (BMW: ST_MBHF) 0: off, 1: on -> full HB, partial HB, flash light or spot activated */
}SimHla_CanBMWLampenzustand_t;

typedef struct
{
  uint8                             StGmabAsst_Can[8];
  uint8                             StGmabAsst_nBytes; /* number bytes != 0 */
  SimHla_CanBMWStGmabAsst_t         StGmabAsst;
  boolean                           bStGmabAsst_Valid;

  uint8                             Lampenzustand_Can[3];
  uint8                             Lampenzustand_nBytes; /* number bytes != 0 */
  SimHla_CanBMWLampenzustand_t      Lampenzustand;
  boolean                           bLampenzustand_Valid;

  uint8                             Kafas2_CtrMabAsst_Can[2];
  uint8                             Kafas2_CtrMabAsst_nBytes; /* number bytes != 0 */
  boolean                           bKafas2_CtrMabAsst_Valid;
  uint8                             Kafas2_ObjMabAsst_Can[8];
  uint8                             Kafas2_ObjMabAsst_nBytes; /* number bytes != 0 */
  boolean                           bKafas2_ObjMabAsst_Valid;

}SimHlaCanBMW_Input_t;


class CSimHlaCan :
  public CSimSwcCan,
  virtual public CSimHlaMeasData
{
public:
  CSimHlaCan( CSimSwcBase* pSimPlgBase);
  ~CSimHlaCan();

  SimHlaMeasdata_t GetCanData(void)
  {
    return m_CAN_BMW;
  }

  void ResetCanReceivePorts();

private:
  SimHlaMeasdata_t                 m_CAN_BMW;
  SimHlaMeasdataBuffers_t          m_CAN_BMW_buffers;
  SimHlaCanBMW_Input_t             m_CAN_BMW_input;

  virtual void CanDataReceive( CTKCanData_t *pData
                              );

};
