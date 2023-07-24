/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  COMPONENT:              HLA

  MODULNAME:              sim_hla_can.c

  DESCRIPTION:            HLA CAN Class

  AUTHOR:                 Alexander Fischer

  CREATION DATE:          2014-11-20

  VERSION:                $Revision: 1.1 $
 
**************************************************************************** */
#include "stdafx.h"

#include "sim_hla_can.h"

#include <sstream>

CSimHlaCan::CSimHlaCan( CSimSwcBase* pSimPlgBase)
: CSimSwcCan(pSimPlgBase)
, CSimHlaMeasData()
{
  ResetCanReceivePorts();
}

CSimHlaCan::~CSimHlaCan()
{
}

void CSimHlaCan::ResetCanReceivePorts()
{
  memset(&m_CAN_BMW_buffers, 0, sizeof(m_CAN_BMW_buffers));
  memset(&m_CAN_BMW, 0, sizeof(m_CAN_BMW));
  memset(&m_CAN_BMW_input, 0,sizeof(m_CAN_BMW_input));

  /* Link pointer lists to buffers */
  LinkBuffers(m_CAN_BMW, m_CAN_BMW_buffers);
  /* Clear all links to internal measfreezes as there are no */
  memset(&m_CAN_BMW.hlaInternMeasdata, 0, sizeof(m_CAN_BMW.hlaInternMeasdata));
}

void CSimHlaCan::CanDataReceive( CTKCanData_t *pData
                                )
{
  /* Matrix light */
  m_CAN_BMW.ReqPorts.pHlaBusInputSignals->sSigHeader.eSigStatus = AL_SIG_STATE_INIT;
  m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus = AL_SIG_STATE_INIT;

  if(pData->ArbitrationId == 0x95)
  {
    float32 cutOffAng_left, cutOffAng_right, dist;
    uint8 status;


    memcpy(&m_CAN_BMW_input.Kafas2_ObjMabAsst_Can[0], &pData->CanData[0], CML_Min(pData->DataLength * sizeof(pData->CanData[0]), sizeof(m_CAN_BMW_input.Kafas2_ObjMabAsst_Can)));   

    cutOffAng_left  = CML_Deg2Rad((m_CAN_BMW_input.Kafas2_ObjMabAsst_Can[1] * 0.1f) - 10.4f);
    cutOffAng_right = CML_Deg2Rad((m_CAN_BMW_input.Kafas2_ObjMabAsst_Can[2] * 0.1f) - 15.0f);
    dist            = m_CAN_BMW_input.Kafas2_ObjMabAsst_Can[3];

    m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[0].BndryLower_Ang_Cam  = -CML_Deg2Rad((m_CAN_BMW_input.Kafas2_ObjMabAsst_Can[0] * 0.05f) - 5.0f);
    m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[0].BndryLeft_Ang       =  cutOffAng_left;
    m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[0].BndryLeft_Ang_Cam   =  cutOffAng_left;
    m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[0].BndryRight_Ang      =  cutOffAng_right;
    m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[0].BndryRight_Ang_Cam  =  cutOffAng_right;
    m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[0].ClosestObj_Dist     =  dist;
    m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[0].BndryLeft_Dist      =  dist;
    m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[0].BndryRight_Dist     =  dist;



    status = ((m_CAN_BMW_input.Kafas2_ObjMabAsst_Can[4] &  0x3) >> 0);
    switch(status)
    {
    case 0:
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[0].BndryLower_Status = RTE_HLAF_OBJSTA_NO_OBJ;
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
      break;
    case 1:
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[0].BndryLower_Status = RTE_HLAF_OBJSTA_PREC_OBJ;
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
      break;
    case 2:
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[0].BndryLower_Status = RTE_HLAF_OBJSTA_ONC_OBJ;
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
      break;
    default:
    case 3:
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[0].BndryLower_Status = RTE_HLAF_OBJSTA_INVALID;
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus |= 0;
      break;
    }

    status = ((m_CAN_BMW_input.Kafas2_ObjMabAsst_Can[4] &  0xC) >> 2);
    switch(status)
    {
    case 0:
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[0].BndryLeft_Status = RTE_HLAF_OBJSTA_NO_OBJ;
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
      break;
    case 1:
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[0].BndryLeft_Status = RTE_HLAF_OBJSTA_PREC_OBJ;
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
      break;
    case 2:
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[0].BndryLeft_Status = RTE_HLAF_OBJSTA_ONC_OBJ;
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
      break;
    default:
    case 3:
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[0].BndryLeft_Status = RTE_HLAF_OBJSTA_INVALID;
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus |= 0;
      break;
    }

    status = ((m_CAN_BMW_input.Kafas2_ObjMabAsst_Can[4] & 0x30) >> 4);
    switch(status)
    {
    case 0:
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[0].BndryRight_Status = RTE_HLAF_OBJSTA_NO_OBJ;
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
      break;
    case 1:
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[0].BndryRight_Status = RTE_HLAF_OBJSTA_PREC_OBJ;
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
      break;
    case 2:
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[0].BndryRight_Status = RTE_HLAF_OBJSTA_ONC_OBJ;
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
      break;
    default:
    case 3:
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[0].BndryRight_Status = RTE_HLAF_OBJSTA_INVALID;
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus |= 0;
      break;
    }

    status = ((m_CAN_BMW_input.Kafas2_ObjMabAsst_Can[4] & 0xC0) >> 6);
    switch(status)
    {
    case 0:
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[0].ClosestObj_Status = RTE_HLAF_OBJSTA_NO_OBJ;
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
      break;
    case 1:
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[0].ClosestObj_Status = RTE_HLAF_OBJSTA_PREC_OBJ;
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
      break;
    case 2:
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[0].ClosestObj_Status = RTE_HLAF_OBJSTA_ONC_OBJ;
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
      break;
    default:
    case 3:
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[0].ClosestObj_Status = RTE_HLAF_OBJSTA_INVALID;
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus |= 0;
      break;
    }

    if(    (m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[0].ClosestObj_Status == RTE_HLAF_OBJSTA_PREC_OBJ)
      || (m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[0].ClosestObj_Status == RTE_HLAF_OBJSTA_ONC_OBJ)
      )
    {
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.nGFA = 1;
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
    }
    else
    {
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.nGFA = 0;
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus |= 0;
    }
    m_CAN_BMW_input.bKafas2_ObjMabAsst_Valid = b_TRUE;
  }
  else if(pData->ArbitrationId == 0x292)
  {
    memcpy(&m_CAN_BMW_input.Kafas2_CtrMabAsst_Can[0], &pData->CanData[0], CML_Min(pData->DataLength * sizeof(pData->CanData[0]), sizeof(m_CAN_BMW_input.Kafas2_CtrMabAsst_Can)));


    m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.TurnOffReason = RTE_HLAF_TURNOFFREASON_UNKNOWN;
    if(m_CAN_BMW_input.Kafas2_CtrMabAsst_Can[1] & 1)
    {
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.TurnOffReason |= RTE_HLAF_TURNOFFREASON_ONC;
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
    }
    if(m_CAN_BMW_input.Kafas2_CtrMabAsst_Can[1] & 2)
    {
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.TurnOffReason |= RTE_HLAF_TURNOFFREASON_PREC;
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
    }
    if(m_CAN_BMW_input.Kafas2_CtrMabAsst_Can[1] & 4)
    {
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.TurnOffReason |= RTE_HLAF_TURNOFFREASON_SPEED;
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
    }
    if(m_CAN_BMW_input.Kafas2_CtrMabAsst_Can[1] & 8)
    {
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.TurnOffReason |= RTE_HLAF_TURNOFFREASON_BRIGHTNESS;
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
    }
    if(m_CAN_BMW_input.Kafas2_CtrMabAsst_Can[1] & 16)
    {
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.TurnOffReason |= RTE_HLAF_TURNOFFREASON_CITY;
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
    }
    if(m_CAN_BMW_input.Kafas2_CtrMabAsst_Can[1] & 32)
    {
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.TurnOffReason |= RTE_HLAF_TURNOFFREASON_FOG;
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
    }
    if(m_CAN_BMW_input.Kafas2_CtrMabAsst_Can[1] & 64)
    {
      //      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.TurnOffReason |= RTE_HLAF_TURNOFFREASON_HIGHWAY;
    }
    if(m_CAN_BMW_input.Kafas2_CtrMabAsst_Can[1] & 128)
    {
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.TurnOffReason |= RTE_HLAF_TURNOFFREASON_DELAY;
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
    }


    switch(m_CAN_BMW_input.Kafas2_CtrMabAsst_Can[0] & 0x3)
    {
    case 0:
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.HighBeamState = RTE_HLAF_HB_STATE_UNKNOWN;
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus |= 0;
      break;
    case 1:
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.HighBeamState = RTE_HLAF_HB_STATE_OFF;
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
      break;
    case 2:
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.HighBeamState = RTE_HLAF_HB_STATE_FULL_ON;
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
      break;
    default:
    case 3:
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.HighBeamState = RTE_HLAF_HB_STATE_INVALID;
      m_CAN_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus |= 0;
      break;
    }
    m_CAN_BMW_input.bKafas2_CtrMabAsst_Valid = b_TRUE;
  }
  else if(pData->ArbitrationId == 0x96)
  {
    memcpy(&m_CAN_BMW_input.StGmabAsst_Can[0], &pData->CanData[0], CML_Min(pData->DataLength * sizeof(pData->CanData[0]), sizeof(m_CAN_BMW_input.StGmabAsst_Can)));

    m_CAN_BMW_input.StGmabAsst.cutOffAng_lower = -CML_Deg2Rad(m_CAN_BMW_input.StGmabAsst_Can[0] * 0.05f - 5.0f);
    m_CAN_BMW_input.StGmabAsst.LightDist       = m_CAN_BMW_input.StGmabAsst_Can[1];
    m_CAN_BMW_input.StGmabAsst.cutOffAng_left  = CML_Deg2Rad(m_CAN_BMW_input.StGmabAsst_Can[2] * 0.1f - 10.4f);
    m_CAN_BMW_input.StGmabAsst.cutOffAng_right = CML_Deg2Rad(m_CAN_BMW_input.StGmabAsst_Can[3] * 0.1f - 15.0f);

    m_CAN_BMW_input.StGmabAsst.cutOffAng_lower_Status = (eSimHla_CanBMWStGmabAsstStatus_t)((m_CAN_BMW_input.StGmabAsst_Can[4] &  0x3) >> 0);
    m_CAN_BMW_input.StGmabAsst.LightDist_Status       = (eSimHla_CanBMWStGmabAsstStatus_t)((m_CAN_BMW_input.StGmabAsst_Can[4] &  0xC) >> 2);
    m_CAN_BMW_input.StGmabAsst.cutOffAng_left_Status  = (eSimHla_CanBMWStGmabAsstStatus_t)((m_CAN_BMW_input.StGmabAsst_Can[4] & 0x30) >> 4);
    m_CAN_BMW_input.StGmabAsst.cutOffAng_right_Status = (eSimHla_CanBMWStGmabAsstStatus_t)((m_CAN_BMW_input.StGmabAsst_Can[4] & 0xC0) >> 6);


    /* set cut off angle */
    m_CAN_BMW.ReqPorts.pHlaBusInputSignals->glareFreeAreas[0].cutOffAngleLeft = m_CAN_BMW_input.StGmabAsst.cutOffAng_left;
    m_CAN_BMW.ReqPorts.pHlaBusInputSignals->glareFreeAreas[0].cutOffAngleRight = m_CAN_BMW_input.StGmabAsst.cutOffAng_right;


    /* set light distance */
    if(    (m_CAN_BMW_input.StGmabAsst.cutOffAng_left_Status  == CANBMW_GMAB_STA_ADAPTIVE_LT_CTRL_OFF)
      && (m_CAN_BMW_input.StGmabAsst.cutOffAng_right_Status == CANBMW_GMAB_STA_ADAPTIVE_LT_CTRL_OFF)
      && (m_CAN_BMW_input.StGmabAsst.cutOffAng_lower_Status == CANBMW_GMAB_STA_ADAPTIVE_LT_CTRL_OFF)
      )
    {
      /* full HB on */
      m_CAN_BMW.ReqPorts.pHlaBusInputSignals->lightDistance = 600.0f;
      m_CAN_BMW.ReqPorts.pHlaBusInputSignals->numGlareFreeAreas = 0;
    }
    else
    {
      m_CAN_BMW.ReqPorts.pHlaBusInputSignals->lightDistance = m_CAN_BMW_input.StGmabAsst.LightDist;
      m_CAN_BMW.ReqPorts.pHlaBusInputSignals->numGlareFreeAreas = 1;
    }

    if(   (m_CAN_BMW_input.StGmabAsst.cutOffAng_left_Status  == CANBMW_GMAB_STA_ADAPTIVE_LT_CTRL_OFF)
       && (m_CAN_BMW_input.StGmabAsst.cutOffAng_right_Status == CANBMW_GMAB_STA_ADAPTIVE_LT_CTRL_OFF)
       && (m_CAN_BMW_input.StGmabAsst.cutOffAng_lower_Status == CANBMW_GMAB_STA_ADAPTIVE_LT_CTRL_OFF)
      )
    {
      m_CAN_BMW.ReqPorts.pHlaBusInputSignals->headLightState = RTE_HLAF_HB_STATE_FULL_ON;
    }
    else if (   (m_CAN_BMW_input.StGmabAsst.cutOffAng_lower_Status == CANBMW_GMAB_STA_ADAPTIVE_LT_CTRL_ON)
             && (    (m_CAN_BMW_input.StGmabAsst.cutOffAng_left_Status == CANBMW_GMAB_STA_ADAPTIVE_LT_CTRL_ON)
                  || (m_CAN_BMW_input.StGmabAsst.cutOffAng_right_Status == CANBMW_GMAB_STA_ADAPTIVE_LT_CTRL_ON)
                )
             )
    {
      m_CAN_BMW.ReqPorts.pHlaBusInputSignals->headLightState = RTE_HLAF_HB_STATE_PARTIAL;
    }
    else
    {
      m_CAN_BMW.ReqPorts.pHlaBusInputSignals->headLightState = RTE_HLAF_HB_STATE_OFF;
    }
  }
  else if(pData->ArbitrationId == 0x21A)
  {
    memcpy(&m_CAN_BMW_input.Lampenzustand_Can[0], &pData->CanData[0], CML_Min(pData->DataLength * sizeof(pData->CanData[0]), sizeof(m_CAN_BMW_input.Lampenzustand_Can)));


    m_CAN_BMW_input.Lampenzustand.LowBeamState      = (m_CAN_BMW_input.Lampenzustand_Can[0] & 0x1);
    m_CAN_BMW_input.Lampenzustand.FogLampFrontState = (m_CAN_BMW_input.Lampenzustand_Can[0] & 0x20) >> 5;
    m_CAN_BMW_input.Lampenzustand.FogLampRearState  = (m_CAN_BMW_input.Lampenzustand_Can[0] & 0x40) >> 6;
    m_CAN_BMW_input.Lampenzustand.HBState           = (m_CAN_BMW_input.Lampenzustand_Can[0] & 0x2) >> 1;

    if(((m_CAN_BMW_input.Lampenzustand_Can[2] & 0xC) >> 2) == 2)
    {
      m_CAN_BMW_input.Lampenzustand.eHLAState = HLA_BUS_INPUT_SIGNALS_HLA_REQUEST_ON;
      m_CAN_BMW.ReqPorts.pHlaBusInputSignals->hlaRequest = HLA_BUS_INPUT_SIGNALS_HLA_REQUEST_ON;
      m_CAN_BMW.ReqPorts.pHlaBusInputSignals->sSigHeader.eSigStatus = AL_SIG_STATE_OK;
    }
    else if(((m_CAN_BMW_input.Lampenzustand_Can[2] & 0xC) >> 2) == 1)
    {
      m_CAN_BMW_input.Lampenzustand.eHLAState = HLA_BUS_INPUT_SIGNALS_HLA_REQUEST_OFF;
      m_CAN_BMW.ReqPorts.pHlaBusInputSignals->hlaRequest = HLA_BUS_INPUT_SIGNALS_HLA_REQUEST_OFF;
      m_CAN_BMW.ReqPorts.pHlaBusInputSignals->sSigHeader.eSigStatus = AL_SIG_STATE_OK;
    }
    else
    {
      m_CAN_BMW_input.Lampenzustand.eHLAState = HLA_BUS_INPUT_SIGNALS_HLA_REQUEST_UNKNOWN;
      m_CAN_BMW.ReqPorts.pHlaBusInputSignals->hlaRequest = HLA_BUS_INPUT_SIGNALS_HLA_REQUEST_UNKNOWN;
      m_CAN_BMW.ReqPorts.pHlaBusInputSignals->sSigHeader.eSigStatus = AL_SIG_STATE_OK;
    }

    m_CAN_BMW_input.bLampenzustand_Valid = b_TRUE;
  }
}
