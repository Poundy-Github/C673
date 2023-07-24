/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  COMPONENT:              HLA

  MODULNAME:              sim_hla_ethernet.c

  DESCRIPTION:            HLA Ethernet Class

  AUTHOR:                 Alexander Fischer

  CREATION DATE:          2014-11-20

  VERSION:                $Revision: 1.1 $
 
**************************************************************************** */
#include "stdafx.h"

#include "sim_hla_ethernet.h"

#include <sstream>

CSimHlaEthernet::CSimHlaEthernet(CSimSwcBase* pSimPlgBase)
: CSimHlaMeasData()
/* BMW Ports */
, m_rpKAFAS_CtrlMainBeam_ControlMainBeam                              (pSimPlgBase, "KAFAS_CtrlMainBeam_ControlMainBeam",                               uint8())
, m_rpKAFAS_CtrlMainBeam_QuantityDomainNonGlare                       (pSimPlgBase, "KAFAS_CtrlMainBeam_QuantityDomainNonGlare",                        uint8())
, m_rpKAFAS_CtrlMainBeam_ReasonSwitchOffMainBeam                      (pSimPlgBase, "KAFAS_CtrlMainBeam_ReasonSwitchOffMainBeam",                       uint8())
, m_rpKAFAS_CtrlMainBeam_ValidityObjectData                           (pSimPlgBase, "KAFAS_CtrlMainBeam_ValidityObjectData",                            uint8())
, m_rpKAFAS_ObjDataGlareFree0_BoundaryDomainBottomNonGlareFLA         (pSimPlgBase, "KAFAS_ObjDataGlareFree0_BoundaryDomainBottomNonGlareFLA",          uint8())
, m_rpKAFAS_ObjDataGlareFree0_StatusBoundaryDomainBottomNonGlareFLA   (pSimPlgBase, "KAFAS_ObjDataGlareFree0_StatusBoundaryDomainBottomNonGlareFLA",    uint8())
, m_rpKAFAS_ObjDataGlareFree0_BoundaryDomainNonGlareLeftHandFLA       (pSimPlgBase, "KAFAS_ObjDataGlareFree0_BoundaryDomainNonGlareLeftHandFLA",        uint8())
, m_rpKAFAS_ObjDataGlareFree0_StatusBoundaryDomainNonGlareLeftHandFLA (pSimPlgBase, "KAFAS_ObjDataGlareFree0_StatusBoundaryDomainNonGlareLeftHandFLA",  uint8())
, m_rpKAFAS_ObjDataGlareFree0_BoundaryDomainNonGlareRightHandFLA      (pSimPlgBase, "KAFAS_ObjDataGlareFree0_BoundaryDomainNonGlareRightHandFLA",       uint8())
, m_rpKAFAS_ObjDataGlareFree0_StatusBoundaryDomainNonGlareRightHandFLA(pSimPlgBase, "KAFAS_ObjDataGlareFree0_StatusBoundaryDomainNonGlareRightHandFLA", uint8())
, m_rpKAFAS_ObjDataGlareFree0_ObjectDistanceFLA                       (pSimPlgBase, "KAFAS_ObjDataGlareFree0_ObjectDistanceFLA",                        uint8())
, m_rpKAFAS_ObjDataGlareFree0_StatusObjectDistanceFLA                 (pSimPlgBase, "KAFAS_ObjDataGlareFree0_StatusObjectDistanceFLA",                  uint8())
, m_rpKAFAS_ObjDataGlareFree0_ProbabilitySubsistenceFLA               (pSimPlgBase, "KAFAS_ObjDataGlareFree0_ProbabilitySubsistenceFLA",                uint8())
, m_rpZGW_StatusGlareFree0_PositionCutOffLineDippedBeamFLA            (pSimPlgBase, "ZGW_StatusGlareFree0_PositionCutOffLineDippedBeamFLA",             uint8())
, m_rpZGW_StatusGlareFree0_PositionCutOffLineLeftFLA                  (pSimPlgBase, "ZGW_StatusGlareFree0_PositionCutOffLineLeftFLA",                   uint8())
, m_rpZGW_StatusGlareFree0_PositionCutOffLineRightFLA                 (pSimPlgBase, "ZGW_StatusGlareFree0_PositionCutOffLineRightFLA",                  uint8())
, m_rpZGW_StatusGlareFree0_StatusPositionCutOffLineMainBeamFLA        (pSimPlgBase, "ZGW_StatusGlareFree0_StatusPositionCutOffLineMainBeamFLA",         uint8())
, m_rpZGW_StatusGlareFree0_StatusPositionCutOffLineLeftFLA            (pSimPlgBase, "ZGW_StatusGlareFree0_StatusPositionCutOffLineLeftFLA",             uint8())
, m_rpZGW_StatusGlareFree0_StatusPositionCutOffLineRightFLA           (pSimPlgBase, "ZGW_StatusGlareFree0_StatusPositionCutOffLineRightFLA",            uint8())

, m_rpKAFAS_ObjDataGlareFree1_BoundaryDomainBottomNonGlareFLA         (pSimPlgBase, "KAFAS_ObjDataGlareFree1_BoundaryDomainBottomNonGlareFLA",          uint8())
, m_rpKAFAS_ObjDataGlareFree1_StatusBoundaryDomainBottomNonGlareFLA   (pSimPlgBase, "KAFAS_ObjDataGlareFree1_StatusBoundaryDomainBottomNonGlareFLA",    uint8())
, m_rpKAFAS_ObjDataGlareFree1_BoundaryDomainNonGlareLeftHandFLA       (pSimPlgBase, "KAFAS_ObjDataGlareFree1_BoundaryDomainNonGlareLeftHandFLA",        uint8())
, m_rpKAFAS_ObjDataGlareFree1_StatusBoundaryDomainNonGlareLeftHandFLA (pSimPlgBase, "KAFAS_ObjDataGlareFree1_StatusBoundaryDomainNonGlareLeftHandFLA",  uint8())
, m_rpKAFAS_ObjDataGlareFree1_BoundaryDomainNonGlareRightHandFLA      (pSimPlgBase, "KAFAS_ObjDataGlareFree1_BoundaryDomainNonGlareRightHandFLA",       uint8())
, m_rpKAFAS_ObjDataGlareFree1_StatusBoundaryDomainNonGlareRightHandFLA(pSimPlgBase, "KAFAS_ObjDataGlareFree1_StatusBoundaryDomainNonGlareRightHandFLA", uint8())
, m_rpKAFAS_ObjDataGlareFree1_ObjectDistanceFLA                       (pSimPlgBase, "KAFAS_ObjDataGlareFree1_ObjectDistanceFLA",                        uint8())
, m_rpKAFAS_ObjDataGlareFree1_StatusObjectDistanceFLA                 (pSimPlgBase, "KAFAS_ObjDataGlareFree1_StatusObjectDistanceFLA",                  uint8())
, m_rpKAFAS_ObjDataGlareFree1_ProbabilitySubsistenceFLA               (pSimPlgBase, "KAFAS_ObjDataGlareFree1_ProbabilitySubsistenceFLA",                uint8())
, m_rpZGW_StatusGlareFree1_PositionCutOffLineDippedBeamFLA            (pSimPlgBase, "ZGW_StatusGlareFree1_PositionCutOffLineDippedBeamFLA",             uint8())
, m_rpZGW_StatusGlareFree1_PositionCutOffLineLeftFLA                  (pSimPlgBase, "ZGW_StatusGlareFree1_PositionCutOffLineLeftFLA",                   uint8())
, m_rpZGW_StatusGlareFree1_PositionCutOffLineRightFLA                 (pSimPlgBase, "ZGW_StatusGlareFree1_PositionCutOffLineRightFLA",                  uint8())
, m_rpZGW_StatusGlareFree1_StatusPositionCutOffLineMainBeamFLA        (pSimPlgBase, "ZGW_StatusGlareFree1_StatusPositionCutOffLineMainBeamFLA",         uint8())
, m_rpZGW_StatusGlareFree1_StatusPositionCutOffLineLeftFLA            (pSimPlgBase, "ZGW_StatusGlareFree1_StatusPositionCutOffLineLeftFLA",             uint8())
, m_rpZGW_StatusGlareFree1_StatusPositionCutOffLineRightFLA           (pSimPlgBase, "ZGW_StatusGlareFree1_StatusPositionCutOffLineRightFLA",            uint8())

, m_rpKAFAS_ObjDataGlareFree2_BoundaryDomainBottomNonGlareFLA         (pSimPlgBase, "KAFAS_ObjDataGlareFree2_BoundaryDomainBottomNonGlareFLA",          uint8())
, m_rpKAFAS_ObjDataGlareFree2_StatusBoundaryDomainBottomNonGlareFLA   (pSimPlgBase, "KAFAS_ObjDataGlareFree2_StatusBoundaryDomainBottomNonGlareFLA",    uint8())
, m_rpKAFAS_ObjDataGlareFree2_BoundaryDomainNonGlareLeftHandFLA       (pSimPlgBase, "KAFAS_ObjDataGlareFree2_BoundaryDomainNonGlareLeftHandFLA",        uint8())
, m_rpKAFAS_ObjDataGlareFree2_StatusBoundaryDomainNonGlareLeftHandFLA (pSimPlgBase, "KAFAS_ObjDataGlareFree2_StatusBoundaryDomainNonGlareLeftHandFLA",  uint8())
, m_rpKAFAS_ObjDataGlareFree2_BoundaryDomainNonGlareRightHandFLA      (pSimPlgBase, "KAFAS_ObjDataGlareFree2_BoundaryDomainNonGlareRightHandFLA",       uint8())
, m_rpKAFAS_ObjDataGlareFree2_StatusBoundaryDomainNonGlareRightHandFLA(pSimPlgBase, "KAFAS_ObjDataGlareFree2_StatusBoundaryDomainNonGlareRightHandFLA", uint8())
, m_rpKAFAS_ObjDataGlareFree2_ObjectDistanceFLA                       (pSimPlgBase, "KAFAS_ObjDataGlareFree2_ObjectDistanceFLA",                        uint8())
, m_rpKAFAS_ObjDataGlareFree2_StatusObjectDistanceFLA                 (pSimPlgBase, "KAFAS_ObjDataGlareFree2_StatusObjectDistanceFLA",                  uint8())
, m_rpKAFAS_ObjDataGlareFree2_ProbabilitySubsistenceFLA               (pSimPlgBase, "KAFAS_ObjDataGlareFree2_ProbabilitySubsistenceFLA",                uint8())
, m_rpZGW_StatusGlareFree2_PositionCutOffLineDippedBeamFLA            (pSimPlgBase, "ZGW_StatusGlareFree2_PositionCutOffLineDippedBeamFLA",             uint8())
, m_rpZGW_StatusGlareFree2_PositionCutOffLineLeftFLA                  (pSimPlgBase, "ZGW_StatusGlareFree2_PositionCutOffLineLeftFLA",                   uint8())
, m_rpZGW_StatusGlareFree2_PositionCutOffLineRightFLA                 (pSimPlgBase, "ZGW_StatusGlareFree2_PositionCutOffLineRightFLA",                  uint8())
, m_rpZGW_StatusGlareFree2_StatusPositionCutOffLineMainBeamFLA        (pSimPlgBase, "ZGW_StatusGlareFree2_StatusPositionCutOffLineMainBeamFLA",         uint8())
, m_rpZGW_StatusGlareFree2_StatusPositionCutOffLineLeftFLA            (pSimPlgBase, "ZGW_StatusGlareFree2_StatusPositionCutOffLineLeftFLA",             uint8())
, m_rpZGW_StatusGlareFree2_StatusPositionCutOffLineRightFLA           (pSimPlgBase, "ZGW_StatusGlareFree2_StatusPositionCutOffLineRightFLA",            uint8())
{

  /* Setup Eth Ports */
  SetupEthPorts();

  /* Init/Set up ENET_BMW struct */
  memset(&m_ENET_BMW_buffers, 0, sizeof(m_ENET_BMW_buffers));
  memset(&m_ENET_BMW, 0, sizeof(m_ENET_BMW));
  memset(&m_ENET_BMW_input, 0,sizeof(m_ENET_BMW_input));

  /* Link pointer lists to buffers */
  LinkBuffers(m_ENET_BMW, m_ENET_BMW_buffers);
  /* Clear all links to internal measfreezes as there are no */
  memset(&m_ENET_BMW.hlaInternMeasdata, 0, sizeof(m_ENET_BMW.hlaInternMeasdata));
}

CSimHlaEthernet::~CSimHlaEthernet()
{
}

void CSimHlaEthernet::SetupEthPorts()
{
  /* initialize input port map */
  m_receivePortMapBMW.clear();

  /* add every port to the port map */
  m_receivePortMapBMW.push_back(&m_rpKAFAS_CtrlMainBeam_ControlMainBeam);
  m_receivePortMapBMW.push_back(&m_rpKAFAS_CtrlMainBeam_QuantityDomainNonGlare);
  m_receivePortMapBMW.push_back(&m_rpKAFAS_CtrlMainBeam_ReasonSwitchOffMainBeam);
  m_receivePortMapBMW.push_back(&m_rpKAFAS_CtrlMainBeam_ValidityObjectData);
  m_receivePortMapBMW.push_back(&m_rpKAFAS_ObjDataGlareFree0_BoundaryDomainBottomNonGlareFLA);
  m_receivePortMapBMW.push_back(&m_rpKAFAS_ObjDataGlareFree0_StatusBoundaryDomainBottomNonGlareFLA);
  m_receivePortMapBMW.push_back(&m_rpKAFAS_ObjDataGlareFree0_BoundaryDomainNonGlareLeftHandFLA);
  m_receivePortMapBMW.push_back(&m_rpKAFAS_ObjDataGlareFree0_StatusBoundaryDomainNonGlareLeftHandFLA);
  m_receivePortMapBMW.push_back(&m_rpKAFAS_ObjDataGlareFree0_BoundaryDomainNonGlareRightHandFLA);
  m_receivePortMapBMW.push_back(&m_rpKAFAS_ObjDataGlareFree0_StatusBoundaryDomainNonGlareRightHandFLA);
  m_receivePortMapBMW.push_back(&m_rpKAFAS_ObjDataGlareFree0_ObjectDistanceFLA);
  m_receivePortMapBMW.push_back(&m_rpKAFAS_ObjDataGlareFree0_StatusObjectDistanceFLA);
  m_receivePortMapBMW.push_back(&m_rpKAFAS_ObjDataGlareFree0_ProbabilitySubsistenceFLA);
  m_receivePortMapBMW.push_back(&m_rpZGW_StatusGlareFree0_PositionCutOffLineDippedBeamFLA);
  m_receivePortMapBMW.push_back(&m_rpZGW_StatusGlareFree0_PositionCutOffLineLeftFLA);
  m_receivePortMapBMW.push_back(&m_rpZGW_StatusGlareFree0_PositionCutOffLineRightFLA);
  m_receivePortMapBMW.push_back(&m_rpZGW_StatusGlareFree0_StatusPositionCutOffLineMainBeamFLA);
  m_receivePortMapBMW.push_back(&m_rpZGW_StatusGlareFree0_StatusPositionCutOffLineLeftFLA);
  m_receivePortMapBMW.push_back(&m_rpZGW_StatusGlareFree0_StatusPositionCutOffLineRightFLA);
  m_receivePortMapBMW.push_back(&m_rpKAFAS_ObjDataGlareFree1_BoundaryDomainBottomNonGlareFLA);
  m_receivePortMapBMW.push_back(&m_rpKAFAS_ObjDataGlareFree1_StatusBoundaryDomainBottomNonGlareFLA);
  m_receivePortMapBMW.push_back(&m_rpKAFAS_ObjDataGlareFree1_BoundaryDomainNonGlareLeftHandFLA);
  m_receivePortMapBMW.push_back(&m_rpKAFAS_ObjDataGlareFree1_StatusBoundaryDomainNonGlareLeftHandFLA);
  m_receivePortMapBMW.push_back(&m_rpKAFAS_ObjDataGlareFree1_BoundaryDomainNonGlareRightHandFLA);
  m_receivePortMapBMW.push_back(&m_rpKAFAS_ObjDataGlareFree1_StatusBoundaryDomainNonGlareRightHandFLA);
  m_receivePortMapBMW.push_back(&m_rpKAFAS_ObjDataGlareFree1_ObjectDistanceFLA);
  m_receivePortMapBMW.push_back(&m_rpKAFAS_ObjDataGlareFree1_StatusObjectDistanceFLA);
  m_receivePortMapBMW.push_back(&m_rpKAFAS_ObjDataGlareFree1_ProbabilitySubsistenceFLA);
  m_receivePortMapBMW.push_back(&m_rpZGW_StatusGlareFree1_PositionCutOffLineDippedBeamFLA);
  m_receivePortMapBMW.push_back(&m_rpZGW_StatusGlareFree1_PositionCutOffLineLeftFLA);
  m_receivePortMapBMW.push_back(&m_rpZGW_StatusGlareFree1_PositionCutOffLineRightFLA);
  m_receivePortMapBMW.push_back(&m_rpZGW_StatusGlareFree1_StatusPositionCutOffLineMainBeamFLA);
  m_receivePortMapBMW.push_back(&m_rpZGW_StatusGlareFree1_StatusPositionCutOffLineLeftFLA);
  m_receivePortMapBMW.push_back(&m_rpZGW_StatusGlareFree1_StatusPositionCutOffLineRightFLA);
  m_receivePortMapBMW.push_back(&m_rpKAFAS_ObjDataGlareFree2_BoundaryDomainBottomNonGlareFLA);
  m_receivePortMapBMW.push_back(&m_rpKAFAS_ObjDataGlareFree2_StatusBoundaryDomainBottomNonGlareFLA);
  m_receivePortMapBMW.push_back(&m_rpKAFAS_ObjDataGlareFree2_BoundaryDomainNonGlareLeftHandFLA);
  m_receivePortMapBMW.push_back(&m_rpKAFAS_ObjDataGlareFree2_StatusBoundaryDomainNonGlareLeftHandFLA);
  m_receivePortMapBMW.push_back(&m_rpKAFAS_ObjDataGlareFree2_BoundaryDomainNonGlareRightHandFLA);
  m_receivePortMapBMW.push_back(&m_rpKAFAS_ObjDataGlareFree2_StatusBoundaryDomainNonGlareRightHandFLA);
  m_receivePortMapBMW.push_back(&m_rpKAFAS_ObjDataGlareFree2_ObjectDistanceFLA);
  m_receivePortMapBMW.push_back(&m_rpKAFAS_ObjDataGlareFree2_StatusObjectDistanceFLA);
  m_receivePortMapBMW.push_back(&m_rpKAFAS_ObjDataGlareFree2_ProbabilitySubsistenceFLA);
  m_receivePortMapBMW.push_back(&m_rpZGW_StatusGlareFree2_PositionCutOffLineDippedBeamFLA);
  m_receivePortMapBMW.push_back(&m_rpZGW_StatusGlareFree2_PositionCutOffLineLeftFLA);
  m_receivePortMapBMW.push_back(&m_rpZGW_StatusGlareFree2_PositionCutOffLineRightFLA);
  m_receivePortMapBMW.push_back(&m_rpZGW_StatusGlareFree2_StatusPositionCutOffLineMainBeamFLA);
  m_receivePortMapBMW.push_back(&m_rpZGW_StatusGlareFree2_StatusPositionCutOffLineLeftFLA);
  m_receivePortMapBMW.push_back(&m_rpZGW_StatusGlareFree2_StatusPositionCutOffLineRightFLA);

}

void CSimHlaEthernet::ResetEthReceivePorts()
{
  /* Reset Eth Ports */
  for (SimReceivePortMap_t::iterator i = m_receivePortMapBMW.begin(); i != m_receivePortMapBMW.end(); ++i)
  {
    SimReceivePortBase& port = **i;

    /* reset the ports received flag */
    port.setNotDirty();
  }
}

void CSimHlaEthernet::CollectKAFASInputs()
{

  /* Check for new data at input ports */
  CheckPortsDirty();

  m_ENET_BMW.ReqPorts.pHlaBusInputSignals->sSigHeader.eSigStatus = AL_SIG_STATE_INIT;
  m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus = AL_SIG_STATE_INIT;

  if(!CheckKAFASInputs())
  {
    CollectZGW_StatusGlareFree0_StatusPositionCutOffLineMainBeamFLA(m_rpZGW_StatusGlareFree0_StatusPositionCutOffLineMainBeamFLA.val(), m_rpZGW_StatusGlareFree0_PositionCutOffLineLeftFLA.val(), m_rpZGW_StatusGlareFree0_PositionCutOffLineRightFLA.val());

    CollectKAFAS_CtrlMainBeam_ControlMainBeam(m_rpKAFAS_CtrlMainBeam_ControlMainBeam.val());
    CollectKAFAS_CtrlMainBeam_QuantityDomainNonGlare(m_rpKAFAS_CtrlMainBeam_QuantityDomainNonGlare.val());
    CollectKAFAS_CtrlMainBeam_ReasonSwitchOffMainBeam(m_rpKAFAS_CtrlMainBeam_ReasonSwitchOffMainBeam.val());
    CollectKAFAS_CtrlMainBeam_ValidityObjectData(m_rpKAFAS_CtrlMainBeam_ValidityObjectData.val());
    CollectKAFAS_ObjDataGlareFree0_BoundaryDomainBottomNonGlareFLA(0, m_rpKAFAS_ObjDataGlareFree0_BoundaryDomainBottomNonGlareFLA.val());
    CollectKAFAS_ObjDataGlareFree0_StatusBoundaryDomainBottomNonGlareFLA(0, m_rpKAFAS_ObjDataGlareFree0_StatusBoundaryDomainBottomNonGlareFLA.val());
    CollectKAFAS_ObjDataGlareFree0_BoundaryDomainNonGlareLeftHandFLA(0, m_rpKAFAS_ObjDataGlareFree0_BoundaryDomainNonGlareLeftHandFLA.val());
    CollectKAFAS_ObjDataGlareFree0_StatusBoundaryDomainNonGlareLeftHandFLA(0, m_rpKAFAS_ObjDataGlareFree0_StatusBoundaryDomainNonGlareLeftHandFLA.val());
    CollectKAFAS_ObjDataGlareFree0_BoundaryDomainNonGlareRightHandFLA(0, m_rpKAFAS_ObjDataGlareFree0_BoundaryDomainNonGlareRightHandFLA.val());
    CollectKAFAS_ObjDataGlareFree0_StatusBoundaryDomainNonGlareRightHandFLA(0,m_rpKAFAS_ObjDataGlareFree0_StatusBoundaryDomainNonGlareRightHandFLA.val());
    CollectKAFAS_ObjDataGlareFree0_ObjectDistanceFLA(0, m_rpKAFAS_ObjDataGlareFree0_ObjectDistanceFLA.val());
    CollectKAFAS_ObjDataGlareFree0_StatusObjectDistanceFLA(0, m_rpKAFAS_ObjDataGlareFree0_StatusObjectDistanceFLA.val());
    CollectKAFAS_ObjDataGlareFree0_ProbabilitySubsistenceFLA(0, m_rpKAFAS_ObjDataGlareFree0_ProbabilitySubsistenceFLA.val());
    CollectZGW_StatusGlareFree0_PositionCutOffLineDippedBeamFLA(0, m_rpZGW_StatusGlareFree0_PositionCutOffLineDippedBeamFLA.val());
    CollectZGW_StatusGlareFree0_PositionCutOffLineLeftFLA(0, m_rpZGW_StatusGlareFree0_PositionCutOffLineLeftFLA.val());
    CollectZGW_StatusGlareFree0_PositionCutOffLineRightFLA(0, m_rpZGW_StatusGlareFree0_PositionCutOffLineRightFLA.val());

    CollectKAFAS_ObjDataGlareFree0_BoundaryDomainBottomNonGlareFLA(1, m_rpKAFAS_ObjDataGlareFree1_BoundaryDomainBottomNonGlareFLA.val());
    CollectKAFAS_ObjDataGlareFree0_StatusBoundaryDomainBottomNonGlareFLA(1, m_rpKAFAS_ObjDataGlareFree1_StatusBoundaryDomainBottomNonGlareFLA.val());
    CollectKAFAS_ObjDataGlareFree0_BoundaryDomainNonGlareLeftHandFLA(1, m_rpKAFAS_ObjDataGlareFree1_BoundaryDomainNonGlareLeftHandFLA.val());
    CollectKAFAS_ObjDataGlareFree0_StatusBoundaryDomainNonGlareLeftHandFLA(1, m_rpKAFAS_ObjDataGlareFree1_StatusBoundaryDomainNonGlareLeftHandFLA.val());
    CollectKAFAS_ObjDataGlareFree0_BoundaryDomainNonGlareRightHandFLA(1, m_rpKAFAS_ObjDataGlareFree1_BoundaryDomainNonGlareRightHandFLA.val());
    CollectKAFAS_ObjDataGlareFree0_StatusBoundaryDomainNonGlareRightHandFLA(1, m_rpKAFAS_ObjDataGlareFree1_StatusBoundaryDomainNonGlareRightHandFLA.val());
    CollectKAFAS_ObjDataGlareFree0_ObjectDistanceFLA(1, m_rpKAFAS_ObjDataGlareFree1_ObjectDistanceFLA.val());
    CollectKAFAS_ObjDataGlareFree0_StatusObjectDistanceFLA(1, m_rpKAFAS_ObjDataGlareFree1_StatusObjectDistanceFLA.val());
    CollectKAFAS_ObjDataGlareFree0_ProbabilitySubsistenceFLA(1, m_rpKAFAS_ObjDataGlareFree1_ProbabilitySubsistenceFLA.val());
    CollectZGW_StatusGlareFree0_PositionCutOffLineDippedBeamFLA(1, m_rpZGW_StatusGlareFree1_PositionCutOffLineDippedBeamFLA.val());
    CollectZGW_StatusGlareFree0_PositionCutOffLineLeftFLA(1, m_rpZGW_StatusGlareFree1_PositionCutOffLineLeftFLA.val());
    CollectZGW_StatusGlareFree0_PositionCutOffLineRightFLA(1, m_rpZGW_StatusGlareFree1_PositionCutOffLineRightFLA.val());

    CollectKAFAS_ObjDataGlareFree0_BoundaryDomainBottomNonGlareFLA(2, m_rpKAFAS_ObjDataGlareFree2_BoundaryDomainBottomNonGlareFLA.val());
    CollectKAFAS_ObjDataGlareFree0_StatusBoundaryDomainBottomNonGlareFLA(2, m_rpKAFAS_ObjDataGlareFree2_StatusBoundaryDomainBottomNonGlareFLA.val());
    CollectKAFAS_ObjDataGlareFree0_BoundaryDomainNonGlareLeftHandFLA(2, m_rpKAFAS_ObjDataGlareFree2_BoundaryDomainNonGlareLeftHandFLA.val());
    CollectKAFAS_ObjDataGlareFree0_StatusBoundaryDomainNonGlareLeftHandFLA(2, m_rpKAFAS_ObjDataGlareFree2_StatusBoundaryDomainNonGlareLeftHandFLA.val());
    CollectKAFAS_ObjDataGlareFree0_BoundaryDomainNonGlareRightHandFLA(2, m_rpKAFAS_ObjDataGlareFree2_BoundaryDomainNonGlareRightHandFLA.val());
    CollectKAFAS_ObjDataGlareFree0_StatusBoundaryDomainNonGlareRightHandFLA(2, m_rpKAFAS_ObjDataGlareFree2_StatusBoundaryDomainNonGlareRightHandFLA.val());
    CollectKAFAS_ObjDataGlareFree0_ObjectDistanceFLA(2, m_rpKAFAS_ObjDataGlareFree2_ObjectDistanceFLA.val());
    CollectKAFAS_ObjDataGlareFree0_StatusObjectDistanceFLA(2, m_rpKAFAS_ObjDataGlareFree2_StatusObjectDistanceFLA.val());
    CollectKAFAS_ObjDataGlareFree0_ProbabilitySubsistenceFLA(2, m_rpKAFAS_ObjDataGlareFree2_ProbabilitySubsistenceFLA.val());
    CollectZGW_StatusGlareFree0_PositionCutOffLineDippedBeamFLA(2, m_rpZGW_StatusGlareFree2_PositionCutOffLineDippedBeamFLA.val());
    CollectZGW_StatusGlareFree0_PositionCutOffLineLeftFLA(2, m_rpZGW_StatusGlareFree2_PositionCutOffLineLeftFLA.val());
    CollectZGW_StatusGlareFree0_PositionCutOffLineRightFLA(2, m_rpZGW_StatusGlareFree2_PositionCutOffLineRightFLA.val());
  }
}

boolean CSimHlaEthernet::CheckKAFASInputs(void)
{

  boolean portsnotdirty = FALSE;

  portsnotdirty |= !m_rpKAFAS_CtrlMainBeam_ControlMainBeam.isDirty();
  portsnotdirty |= !m_rpKAFAS_CtrlMainBeam_QuantityDomainNonGlare.isDirty();
  portsnotdirty |= !m_rpKAFAS_CtrlMainBeam_ReasonSwitchOffMainBeam.isDirty();
  portsnotdirty |= !m_rpKAFAS_CtrlMainBeam_ValidityObjectData.isDirty();
  portsnotdirty |= !m_rpKAFAS_ObjDataGlareFree0_BoundaryDomainBottomNonGlareFLA.isDirty();
  portsnotdirty |= !m_rpKAFAS_ObjDataGlareFree0_StatusBoundaryDomainBottomNonGlareFLA.isDirty();
  portsnotdirty |= !m_rpKAFAS_ObjDataGlareFree0_BoundaryDomainNonGlareLeftHandFLA.isDirty();
  portsnotdirty |= !m_rpKAFAS_ObjDataGlareFree0_StatusBoundaryDomainNonGlareLeftHandFLA.isDirty();
  portsnotdirty |= !m_rpKAFAS_ObjDataGlareFree0_BoundaryDomainNonGlareRightHandFLA.isDirty();
  portsnotdirty |= !m_rpKAFAS_ObjDataGlareFree0_StatusBoundaryDomainNonGlareRightHandFLA.isDirty();
  portsnotdirty |= !m_rpKAFAS_ObjDataGlareFree0_ObjectDistanceFLA.isDirty();
  portsnotdirty |= !m_rpKAFAS_ObjDataGlareFree0_StatusObjectDistanceFLA.isDirty();
  portsnotdirty |= !m_rpKAFAS_ObjDataGlareFree0_ProbabilitySubsistenceFLA.isDirty();
  portsnotdirty |= !m_rpZGW_StatusGlareFree0_PositionCutOffLineDippedBeamFLA.isDirty();
  portsnotdirty |= !m_rpZGW_StatusGlareFree0_PositionCutOffLineLeftFLA.isDirty();
  portsnotdirty |= !m_rpZGW_StatusGlareFree0_PositionCutOffLineRightFLA.isDirty();
  portsnotdirty |= !m_rpZGW_StatusGlareFree0_StatusPositionCutOffLineMainBeamFLA.isDirty();
  portsnotdirty |= !m_rpZGW_StatusGlareFree0_StatusPositionCutOffLineLeftFLA.isDirty();
  portsnotdirty |= !m_rpZGW_StatusGlareFree0_StatusPositionCutOffLineRightFLA.isDirty();

  return portsnotdirty;

}

void CSimHlaEthernet::CheckPortsDirty(void)
{
  m_ENET_BMW_input.ControlMainBeamAssistant_Enet.eControlMainBeam_Valid                                         = m_rpKAFAS_CtrlMainBeam_ControlMainBeam.isDirty();
  m_ENET_BMW_input.ControlMainBeamAssistant_Enet.eQuantityDomainNonGlare_Valid                                  = m_rpKAFAS_CtrlMainBeam_QuantityDomainNonGlare.isDirty();
  m_ENET_BMW_input.ControlMainBeamAssistant_Enet.eReasonSwitchOffMainBeam_Valid                                 = m_rpKAFAS_CtrlMainBeam_ReasonSwitchOffMainBeam.isDirty();
  m_ENET_BMW_input.ControlMainBeamAssistant_Enet.eValidityObjectData_Valid                                      = m_rpKAFAS_CtrlMainBeam_ValidityObjectData.isDirty();
  m_ENET_BMW_input.ObjectDataGlareFreeMainBeamAssistant_Enet[0].eBoundaryDomainBottomNonGlareFLA_Valid          = m_rpKAFAS_ObjDataGlareFree0_BoundaryDomainBottomNonGlareFLA.isDirty();
  m_ENET_BMW_input.ObjectDataGlareFreeMainBeamAssistant_Enet[0].eStatusBoundaryDomainBottomNonGlareFLA_Valid    = m_rpKAFAS_ObjDataGlareFree0_StatusBoundaryDomainBottomNonGlareFLA.isDirty();
  m_ENET_BMW_input.ObjectDataGlareFreeMainBeamAssistant_Enet[0].eBoundaryDomainNonGlareLeftHandFLA_Valid        = m_rpKAFAS_ObjDataGlareFree0_BoundaryDomainNonGlareLeftHandFLA.isDirty();
  m_ENET_BMW_input.ObjectDataGlareFreeMainBeamAssistant_Enet[0].eStatusBoundaryDomainNonGlareLeftHandFLA_Valid  = m_rpKAFAS_ObjDataGlareFree0_StatusBoundaryDomainNonGlareLeftHandFLA.isDirty();
  m_ENET_BMW_input.ObjectDataGlareFreeMainBeamAssistant_Enet[0].eBoundaryDomainNonGlareRightHandFLA_Valid       = m_rpKAFAS_ObjDataGlareFree0_BoundaryDomainNonGlareRightHandFLA.isDirty();
  m_ENET_BMW_input.ObjectDataGlareFreeMainBeamAssistant_Enet[0].eStatusBoundaryDomainNonGlareRightHandFLA_Valid = m_rpKAFAS_ObjDataGlareFree0_StatusBoundaryDomainNonGlareRightHandFLA.isDirty();
  m_ENET_BMW_input.ObjectDataGlareFreeMainBeamAssistant_Enet[0].eObjectDistanceFLA_Valid                        = m_rpKAFAS_ObjDataGlareFree0_ObjectDistanceFLA.isDirty();
  m_ENET_BMW_input.ObjectDataGlareFreeMainBeamAssistant_Enet[0].eStatusObjectDistanceFLA_Valid                  = m_rpKAFAS_ObjDataGlareFree0_StatusObjectDistanceFLA.isDirty();
  m_ENET_BMW_input.ObjectDataGlareFreeMainBeamAssistant_Enet[0].eProbabilitySubsistenceFLA_Valid                = m_rpKAFAS_ObjDataGlareFree0_ProbabilitySubsistenceFLA.isDirty();
  m_ENET_BMW_input.StatusGlareFreeMainBeamAssistant_Enet[0].ePositionCutOffLineDippedBeamFLA_Valid              = m_rpZGW_StatusGlareFree0_PositionCutOffLineDippedBeamFLA.isDirty();
  m_ENET_BMW_input.StatusGlareFreeMainBeamAssistant_Enet[0].ePositionCutOffLineLeftFLA_Valid                    = m_rpZGW_StatusGlareFree0_PositionCutOffLineLeftFLA.isDirty();
  m_ENET_BMW_input.StatusGlareFreeMainBeamAssistant_Enet[0].ePositionCutOffLineRightFLA_Valid                   = m_rpZGW_StatusGlareFree0_PositionCutOffLineRightFLA.isDirty();
  m_ENET_BMW_input.StatusGlareFreeMainBeamAssistant_Enet[0].eStatusPositionCutOffLineMainBeamFLA_Valid          = m_rpZGW_StatusGlareFree0_StatusPositionCutOffLineMainBeamFLA.isDirty();
  m_ENET_BMW_input.StatusGlareFreeMainBeamAssistant_Enet[0].eStatusPositionCutOffLineLeftFLA_Valid              = m_rpZGW_StatusGlareFree0_StatusPositionCutOffLineLeftFLA.isDirty();
  m_ENET_BMW_input.StatusGlareFreeMainBeamAssistant_Enet[0].eStatusPositionCutOffLineRightFLA_Valid             = m_rpZGW_StatusGlareFree0_StatusPositionCutOffLineRightFLA.isDirty();
  m_ENET_BMW_input.ObjectDataGlareFreeMainBeamAssistant_Enet[1].eBoundaryDomainBottomNonGlareFLA_Valid          = m_rpKAFAS_ObjDataGlareFree1_BoundaryDomainBottomNonGlareFLA.isDirty();
  m_ENET_BMW_input.ObjectDataGlareFreeMainBeamAssistant_Enet[1].eStatusBoundaryDomainBottomNonGlareFLA_Valid    = m_rpKAFAS_ObjDataGlareFree1_StatusBoundaryDomainBottomNonGlareFLA.isDirty();
  m_ENET_BMW_input.ObjectDataGlareFreeMainBeamAssistant_Enet[1].eBoundaryDomainNonGlareLeftHandFLA_Valid        = m_rpKAFAS_ObjDataGlareFree1_BoundaryDomainNonGlareLeftHandFLA.isDirty();
  m_ENET_BMW_input.ObjectDataGlareFreeMainBeamAssistant_Enet[1].eStatusBoundaryDomainNonGlareLeftHandFLA_Valid  = m_rpKAFAS_ObjDataGlareFree1_StatusBoundaryDomainNonGlareLeftHandFLA.isDirty();
  m_ENET_BMW_input.ObjectDataGlareFreeMainBeamAssistant_Enet[1].eBoundaryDomainNonGlareRightHandFLA_Valid       = m_rpKAFAS_ObjDataGlareFree1_BoundaryDomainNonGlareRightHandFLA.isDirty();
  m_ENET_BMW_input.ObjectDataGlareFreeMainBeamAssistant_Enet[1].eStatusBoundaryDomainNonGlareRightHandFLA_Valid = m_rpKAFAS_ObjDataGlareFree1_StatusBoundaryDomainNonGlareRightHandFLA.isDirty();
  m_ENET_BMW_input.ObjectDataGlareFreeMainBeamAssistant_Enet[1].eObjectDistanceFLA_Valid                        = m_rpKAFAS_ObjDataGlareFree1_ObjectDistanceFLA.isDirty();
  m_ENET_BMW_input.ObjectDataGlareFreeMainBeamAssistant_Enet[1].eStatusObjectDistanceFLA_Valid                  = m_rpKAFAS_ObjDataGlareFree1_StatusObjectDistanceFLA.isDirty();
  m_ENET_BMW_input.ObjectDataGlareFreeMainBeamAssistant_Enet[1].eProbabilitySubsistenceFLA_Valid                = m_rpKAFAS_ObjDataGlareFree1_ProbabilitySubsistenceFLA.isDirty();
  m_ENET_BMW_input.StatusGlareFreeMainBeamAssistant_Enet[1].ePositionCutOffLineDippedBeamFLA_Valid              = m_rpZGW_StatusGlareFree1_PositionCutOffLineDippedBeamFLA.isDirty();
  m_ENET_BMW_input.StatusGlareFreeMainBeamAssistant_Enet[1].ePositionCutOffLineLeftFLA_Valid                    = m_rpZGW_StatusGlareFree1_PositionCutOffLineLeftFLA.isDirty();
  m_ENET_BMW_input.StatusGlareFreeMainBeamAssistant_Enet[1].ePositionCutOffLineRightFLA_Valid                   = m_rpZGW_StatusGlareFree1_PositionCutOffLineRightFLA.isDirty();
  m_ENET_BMW_input.StatusGlareFreeMainBeamAssistant_Enet[1].eStatusPositionCutOffLineMainBeamFLA_Valid          = m_rpZGW_StatusGlareFree1_StatusPositionCutOffLineMainBeamFLA.isDirty();
  m_ENET_BMW_input.StatusGlareFreeMainBeamAssistant_Enet[1].eStatusPositionCutOffLineLeftFLA_Valid              = m_rpZGW_StatusGlareFree1_StatusPositionCutOffLineLeftFLA.isDirty();
  m_ENET_BMW_input.StatusGlareFreeMainBeamAssistant_Enet[1].eStatusPositionCutOffLineRightFLA_Valid             = m_rpZGW_StatusGlareFree1_StatusPositionCutOffLineRightFLA.isDirty();
  m_ENET_BMW_input.ObjectDataGlareFreeMainBeamAssistant_Enet[2].eBoundaryDomainBottomNonGlareFLA_Valid          = m_rpKAFAS_ObjDataGlareFree2_BoundaryDomainBottomNonGlareFLA.isDirty();
  m_ENET_BMW_input.ObjectDataGlareFreeMainBeamAssistant_Enet[2].eStatusBoundaryDomainBottomNonGlareFLA_Valid    = m_rpKAFAS_ObjDataGlareFree2_StatusBoundaryDomainBottomNonGlareFLA.isDirty();
  m_ENET_BMW_input.ObjectDataGlareFreeMainBeamAssistant_Enet[2].eBoundaryDomainNonGlareLeftHandFLA_Valid        = m_rpKAFAS_ObjDataGlareFree2_BoundaryDomainNonGlareLeftHandFLA.isDirty();
  m_ENET_BMW_input.ObjectDataGlareFreeMainBeamAssistant_Enet[2].eStatusBoundaryDomainNonGlareLeftHandFLA_Valid  = m_rpKAFAS_ObjDataGlareFree2_StatusBoundaryDomainNonGlareLeftHandFLA.isDirty();
  m_ENET_BMW_input.ObjectDataGlareFreeMainBeamAssistant_Enet[2].eBoundaryDomainNonGlareRightHandFLA_Valid       = m_rpKAFAS_ObjDataGlareFree2_BoundaryDomainNonGlareRightHandFLA.isDirty();
  m_ENET_BMW_input.ObjectDataGlareFreeMainBeamAssistant_Enet[2].eStatusBoundaryDomainNonGlareRightHandFLA_Valid = m_rpKAFAS_ObjDataGlareFree2_StatusBoundaryDomainNonGlareRightHandFLA.isDirty();
  m_ENET_BMW_input.ObjectDataGlareFreeMainBeamAssistant_Enet[2].eObjectDistanceFLA_Valid                        = m_rpKAFAS_ObjDataGlareFree2_ObjectDistanceFLA.isDirty();
  m_ENET_BMW_input.ObjectDataGlareFreeMainBeamAssistant_Enet[2].eStatusObjectDistanceFLA_Valid                  = m_rpKAFAS_ObjDataGlareFree2_StatusObjectDistanceFLA.isDirty();
  m_ENET_BMW_input.ObjectDataGlareFreeMainBeamAssistant_Enet[2].eProbabilitySubsistenceFLA_Valid                = m_rpKAFAS_ObjDataGlareFree2_ProbabilitySubsistenceFLA.isDirty();
  m_ENET_BMW_input.StatusGlareFreeMainBeamAssistant_Enet[2].ePositionCutOffLineDippedBeamFLA_Valid              = m_rpZGW_StatusGlareFree2_PositionCutOffLineDippedBeamFLA.isDirty();
  m_ENET_BMW_input.StatusGlareFreeMainBeamAssistant_Enet[2].ePositionCutOffLineLeftFLA_Valid                    = m_rpZGW_StatusGlareFree2_PositionCutOffLineLeftFLA.isDirty();
  m_ENET_BMW_input.StatusGlareFreeMainBeamAssistant_Enet[2].ePositionCutOffLineRightFLA_Valid                   = m_rpZGW_StatusGlareFree2_PositionCutOffLineRightFLA.isDirty();
  m_ENET_BMW_input.StatusGlareFreeMainBeamAssistant_Enet[2].eStatusPositionCutOffLineMainBeamFLA_Valid          = m_rpZGW_StatusGlareFree2_StatusPositionCutOffLineMainBeamFLA.isDirty();
  m_ENET_BMW_input.StatusGlareFreeMainBeamAssistant_Enet[2].eStatusPositionCutOffLineLeftFLA_Valid              = m_rpZGW_StatusGlareFree2_StatusPositionCutOffLineLeftFLA.isDirty();
  m_ENET_BMW_input.StatusGlareFreeMainBeamAssistant_Enet[2].eStatusPositionCutOffLineRightFLA_Valid             = m_rpZGW_StatusGlareFree2_StatusPositionCutOffLineRightFLA.isDirty();

}

void CSimHlaEthernet::CollectKAFAS_CtrlMainBeam_ControlMainBeam( const uint8 CtrlMainBeam_ControlMainBeam
                                                                )
{
  switch(CtrlMainBeam_ControlMainBeam)
  {
  case 0:
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.HighBeamState = RTE_HLAF_HB_STATE_UNKNOWN;
    break;
  case 1:
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.HighBeamState = RTE_HLAF_HB_STATE_OFF;
    break;
  case 2:
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.HighBeamState = RTE_HLAF_HB_STATE_FULL_ON;
    break;
  default:
  case 3:
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.HighBeamState = RTE_HLAF_HB_STATE_INVALID;
    break;
  }
}

void CSimHlaEthernet::CollectKAFAS_CtrlMainBeam_QuantityDomainNonGlare( const uint8 CtrlMainBeam_QuantityDomainNonGlare
                                                                       )
{

  if(CtrlMainBeam_QuantityDomainNonGlare <= RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS)
  {
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.nGFA = CtrlMainBeam_QuantityDomainNonGlare;
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  }
  else
  {
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.nGFA = 0;
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus |= 0;
  }

}

void CSimHlaEthernet::CollectKAFAS_CtrlMainBeam_ReasonSwitchOffMainBeam( const uint8 CtrlMainBeam_ReasonSwitchOffMainBeam
                                                                        )
{

  m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.TurnOffReason = RTE_HLAF_TURNOFFREASON_UNKNOWN;
  if(CtrlMainBeam_ReasonSwitchOffMainBeam & 1)
  {
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.TurnOffReason |= RTE_HLAF_TURNOFFREASON_ONC;
  }
  if(CtrlMainBeam_ReasonSwitchOffMainBeam & 2)
  {
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.TurnOffReason |= RTE_HLAF_TURNOFFREASON_PREC;
  }
  if(CtrlMainBeam_ReasonSwitchOffMainBeam & 4)
  {
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.TurnOffReason |= RTE_HLAF_TURNOFFREASON_SPEED;
  }
  if(CtrlMainBeam_ReasonSwitchOffMainBeam & 8)
  {
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.TurnOffReason |= RTE_HLAF_TURNOFFREASON_BRIGHTNESS;
  }
  if(CtrlMainBeam_ReasonSwitchOffMainBeam & 16)
  {
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.TurnOffReason |= RTE_HLAF_TURNOFFREASON_CITY;
  }
  if(CtrlMainBeam_ReasonSwitchOffMainBeam & 32)
  {
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.TurnOffReason |= RTE_HLAF_TURNOFFREASON_FOG;
  }
  if(CtrlMainBeam_ReasonSwitchOffMainBeam & 64)
  {
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Common.MotorwayState |= RTE_HLAF_MTWY_MOTORWAY;
  }
  if(CtrlMainBeam_ReasonSwitchOffMainBeam & 128)
  {
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.TurnOffReason |= RTE_HLAF_TURNOFFREASON_DELAY;
  }
}

void CSimHlaEthernet::CollectKAFAS_CtrlMainBeam_ValidityObjectData( const uint8 CtrlMainBeam_ValidityObjectData
                                                                   )
{

  switch(CtrlMainBeam_ValidityObjectData)
  {
  case 0:
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFAStatus = RTE_HLAF_SIGSTAT_UNKNOWN;
    break;
  case 1:
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFAStatus = RTE_HLAF_SIGSTAT_DATA_VALID;
    break;
  case 2:
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFAStatus = RTE_HLAF_SIGSTAT_DATA_INVALID;
    break;
  default:
  case 3:
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFAStatus = RTE_HLAF_SIGSTAT_INVALID;
    break;

  }
}

void CSimHlaEthernet::CollectKAFAS_ObjDataGlareFree0_BoundaryDomainBottomNonGlareFLA( const uint8 idx, 
                                                                                      const uint8 BoundaryDomainBottomNonGlareFLA
                                                                                     )
{

  if(BoundaryDomainBottomNonGlareFLA < 255)
  {
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[idx].BndryLower_Ang_Cam = -CML_Deg2Rad((0.05f*BoundaryDomainBottomNonGlareFLA)-5.0f);
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  }
  else
  {
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[idx].BndryLower_Ang_Cam = 0;
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus |= 0;
  }
}

void CSimHlaEthernet::CollectKAFAS_ObjDataGlareFree0_StatusBoundaryDomainBottomNonGlareFLA( const uint8 idx, 
                                                                                            const uint8 StatusBoundaryDomainBottomNonGlareFLA
                                                                                           )
{

  switch(StatusBoundaryDomainBottomNonGlareFLA)
  {
  case 0:
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[idx].BndryLower_Status = RTE_HLAF_OBJSTA_NO_OBJ;
    break;
  case 1:
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[idx].BndryLower_Status = RTE_HLAF_OBJSTA_PREC_OBJ;
    break;
  case 2:
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[idx].BndryLower_Status = RTE_HLAF_OBJSTA_ONC_OBJ;
    break;
  default:
  case 3:
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[idx].BndryLower_Status = RTE_HLAF_OBJSTA_INVALID;
    break;
  }
}

void CSimHlaEthernet::CollectKAFAS_ObjDataGlareFree0_BoundaryDomainNonGlareLeftHandFLA( const uint8 idx,
                                                                                        const uint8 BoundaryDomainNonGlareLeftHandFLA
                                                                                       )
{

  if(BoundaryDomainNonGlareLeftHandFLA < 255)
  {
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[idx].BndryLeft_Ang_Cam = CML_Deg2Rad((0.1f*BoundaryDomainNonGlareLeftHandFLA)-10.4f);
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  }
  else
  {
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[idx].BndryLeft_Ang_Cam = 0;
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus = 0;
  }
  m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[idx].BndryLeft_Ang = m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[idx].BndryLeft_Ang_Cam;
}

void CSimHlaEthernet::CollectKAFAS_ObjDataGlareFree0_StatusBoundaryDomainNonGlareLeftHandFLA( const uint8 idx,
                                                                                              const uint8 StatusBoundaryDomainNonGlareLeftHandFLA
                                                                                             )
{

  switch(StatusBoundaryDomainNonGlareLeftHandFLA)
  {
  case 0:
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[idx].BndryLeft_Status = RTE_HLAF_OBJSTA_NO_OBJ;
    break;
  case 1:
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[idx].BndryLeft_Status = RTE_HLAF_OBJSTA_PREC_OBJ;
    break;
  case 2:
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[idx].BndryLeft_Status = RTE_HLAF_OBJSTA_ONC_OBJ;
    break;
  default:
  case 3:
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[idx].BndryLeft_Status = RTE_HLAF_OBJSTA_INVALID;
    break;
  }
}

void CSimHlaEthernet::CollectKAFAS_ObjDataGlareFree0_BoundaryDomainNonGlareRightHandFLA( const uint8 idx,
                                                                                         const uint8 BoundaryDomainNonGlareRightHandFLA
                                                                                        )
{

  if(BoundaryDomainNonGlareRightHandFLA < 255)
  {
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[idx].BndryRight_Ang_Cam = CML_Deg2Rad((0.1f*BoundaryDomainNonGlareRightHandFLA)-15.0f);
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  }
  else
  {
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[idx].BndryRight_Ang_Cam = 0;
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus |= 0;
  }
  m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[idx].BndryRight_Ang = m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[idx].BndryRight_Ang_Cam;
}

void CSimHlaEthernet::CollectKAFAS_ObjDataGlareFree0_StatusBoundaryDomainNonGlareRightHandFLA( const uint8 idx,
                                                                                               const uint8 StatusBoundaryDomainNonGlareRightHandFLA
                                                                                              )
{

  switch(StatusBoundaryDomainNonGlareRightHandFLA)
  {
  case 0:
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[idx].BndryRight_Status = RTE_HLAF_OBJSTA_NO_OBJ;
    break;
  case 1:
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[idx].BndryRight_Status = RTE_HLAF_OBJSTA_PREC_OBJ;
    break;
  case 2:
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[idx].BndryRight_Status = RTE_HLAF_OBJSTA_ONC_OBJ;
    break;
  default:
  case 3:
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[idx].BndryRight_Status = RTE_HLAF_OBJSTA_INVALID;
    break;
  }
}

void CSimHlaEthernet::CollectKAFAS_ObjDataGlareFree0_ObjectDistanceFLA( const uint8 idx,
                                                                        const uint8 ObjectDistanceFLA
                                                                       )
{

  if(ObjectDistanceFLA <= 150)
  {
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[idx].ClosestObj_Dist = ObjectDistanceFLA;
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  }
  else
  {
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[idx].ClosestObj_Dist = 0.0f;
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus |= 0;
  }
  m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[idx].BndryLeft_Dist = m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[idx].ClosestObj_Dist;
  m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[idx].BndryRight_Dist = m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[idx].ClosestObj_Dist;
}

void CSimHlaEthernet::CollectKAFAS_ObjDataGlareFree0_StatusObjectDistanceFLA( const uint8 idx, 
                                                                              const uint8 StatusObjectDistanceFLA
                                                                             )
{

  switch(StatusObjectDistanceFLA)
  {
  case 0:
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[idx].ClosestObj_Status = RTE_HLAF_OBJSTA_NO_OBJ;
    break;
  case 1:
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[idx].ClosestObj_Status = RTE_HLAF_OBJSTA_PREC_OBJ;
    break;
  case 2:
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[idx].ClosestObj_Status = RTE_HLAF_OBJSTA_ONC_OBJ;
    break;
  default:
  case 3:
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[idx].ClosestObj_Status = RTE_HLAF_OBJSTA_INVALID;
    break;
  }
}

void CSimHlaEthernet::CollectKAFAS_ObjDataGlareFree0_ProbabilitySubsistenceFLA( const uint8 idx,
                                                                                const uint8 ProbabilitySubsistenceFLA
                                                                               )
{

  if(ProbabilitySubsistenceFLA < 15)
  {
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[idx].ExistenceProb = 10*ProbabilitySubsistenceFLA;
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  }
  else
  {
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.Matrix.GFA[idx].ExistenceProb = 0;
    m_ENET_BMW_buffers.ProPortsBuffers.Hlaf_HeadlightControl.sSigHeader.eSigStatus |= 0;
  }
}

void CSimHlaEthernet::CollectZGW_StatusGlareFree0_PositionCutOffLineDippedBeamFLA( const uint8 idx,
                                                                                   const uint8 PositionCutOffLineDippedBeamFLA
                                                                                  )
{

  /* Matrix light */
  /* m_ENET_BMW.ReqPorts.pSig_HeadlightState->nGFA = 1; */
  m_ENET_BMW.ReqPorts.pHlaBusInputSignals->hlaRequest = HLA_BUS_INPUT_SIGNALS_HLA_REQUEST_ON;
  m_ENET_BMW.ReqPorts.pHlaBusInputSignals->sSigHeader.eSigStatus = AL_SIG_STATE_OK;


  if(PositionCutOffLineDippedBeamFLA < 255)
  {
    m_ENET_BMW.ReqPorts.pHlaBusInputSignals->glareFreeAreas[idx].cutOffAngleLower = -CML_Deg2Rad((0.05f*PositionCutOffLineDippedBeamFLA)-5.0f);
    m_ENET_BMW.ReqPorts.pHlaBusInputSignals->sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  }
  else
  {
    m_ENET_BMW.ReqPorts.pHlaBusInputSignals->glareFreeAreas[idx].cutOffAngleLower = 0.0f;
    m_ENET_BMW.ReqPorts.pHlaBusInputSignals->sSigHeader.eSigStatus |= 0;
  }
}

void CSimHlaEthernet::CollectZGW_StatusGlareFree0_PositionCutOffLineLeftFLA( const uint8 idx,
                                                                             const uint8 PositionCutOffLineLeftFLA
                                                                            )
{

  if(PositionCutOffLineLeftFLA < 255)
  {
    m_ENET_BMW.ReqPorts.pHlaBusInputSignals->glareFreeAreas[idx].cutOffAngleLeft = CML_Deg2Rad((0.1f*PositionCutOffLineLeftFLA)-10.4f);
    m_ENET_BMW.ReqPorts.pHlaBusInputSignals->sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  }
  else
  {
    m_ENET_BMW.ReqPorts.pHlaBusInputSignals->glareFreeAreas[idx].cutOffAngleLeft = 0.0f;
    m_ENET_BMW.ReqPorts.pHlaBusInputSignals->sSigHeader.eSigStatus |= 0;
  }
}

void CSimHlaEthernet::CollectZGW_StatusGlareFree0_PositionCutOffLineRightFLA( const uint8 idx,
                                                                              const uint8 PositionCutOffLineRightFLA
                                                                             )
{

  if(PositionCutOffLineRightFLA < 255)
  {
    m_ENET_BMW.ReqPorts.pHlaBusInputSignals->glareFreeAreas[idx].cutOffAngleRight = CML_Deg2Rad((0.1f*PositionCutOffLineRightFLA)-15.0f);
    m_ENET_BMW.ReqPorts.pHlaBusInputSignals->sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  }
  else
  {
    m_ENET_BMW.ReqPorts.pHlaBusInputSignals->glareFreeAreas[idx].cutOffAngleRight = 0.0f;
    m_ENET_BMW.ReqPorts.pHlaBusInputSignals->sSigHeader.eSigStatus |= 0;
  }
}

void CSimHlaEthernet::CollectZGW_StatusGlareFree0_StatusPositionCutOffLineMainBeamFLA( const uint8 StatusPositionCutOffLineMainBeamFLA,
                                                                                       const uint8 PositionCutOffLineLeftFLA,
                                                                                       const uint8 PositionCutOffLineRightFLA
                                                                                      )
{

  if(StatusPositionCutOffLineMainBeamFLA < 2)
  {
    if(   (PositionCutOffLineLeftFLA  == 0)
       && (PositionCutOffLineRightFLA == 0)
       && (StatusPositionCutOffLineMainBeamFLA == 0)
      )
    {
      m_ENET_BMW.ReqPorts.pHlaBusInputSignals->headLightState = RTE_HLAF_HB_STATE_FULL_ON;
    }

    else if(   (StatusPositionCutOffLineMainBeamFLA == 1)
            && (   (PositionCutOffLineLeftFLA == 1)
                || (PositionCutOffLineRightFLA == 1)
                )
           )
    {
      m_ENET_BMW.ReqPorts.pHlaBusInputSignals->headLightState = RTE_HLAF_HB_STATE_PARTIAL;
    }
    else
    {
      m_ENET_BMW.ReqPorts.pHlaBusInputSignals->headLightState = RTE_HLAF_HB_STATE_OFF;
    }
  }
}

