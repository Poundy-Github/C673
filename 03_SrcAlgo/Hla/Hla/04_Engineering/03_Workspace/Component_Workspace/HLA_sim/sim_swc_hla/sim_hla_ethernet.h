/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  COMPONENT:              HLA

  MODULNAME:              sim_hla_ethernet.h

  DESCRIPTION:            HLA Ethernet Class

  AUTHOR:                 Alexander Fischer

  CREATION DATE:          2014-11-20

  VERSION:                $Revision: 1.1 $
 
**************************************************************************** */

#pragma once

#include "sim_swc_base.h"
#include "sim_versioninfo_impl.h"
#include "sim_swc_cycleinfo.h"
#include "sim_swc_synchronization.h"
#include "sim_swc_draw_base.h"
#include "sim_swc_dbg_exc.h"
#include "sim_hla_common.h"
#include "sim_hla_measdata.h"

typedef struct
{
  uint8                 ControlMainBeam;
  boolean eControlMainBeam_Valid;
  uint8                 QuantityDomainNonGlare;
  boolean eQuantityDomainNonGlare_Valid;
  uint8                 ReasonSwitchOffMainBeam;
  boolean eReasonSwitchOffMainBeam_Valid;
  uint8                 ValidityObjectData;
  boolean eValidityObjectData_Valid;
}SimHlaEnetBMW_ControlMainBeamAssistant_Enet_t;

typedef struct
{
  RTE_HLAF_MatrixTurnOffReason  Reason;
  RTE_HLAF_HighBeamState        HBState;
  uint8                         nGFA;

}SimHlaEnetBMW_ControlMainBeamAssistant_t;

typedef struct
{
  uint8                 BoundaryDomainBottomNonGlareFLA;
  boolean eBoundaryDomainBottomNonGlareFLA_Valid;

  uint8                 StatusBoundaryDomainBottomNonGlareFLA;
  boolean eStatusBoundaryDomainBottomNonGlareFLA_Valid;

  uint8                 BoundaryDomainNonGlareLeftHandFLA;
  boolean eBoundaryDomainNonGlareLeftHandFLA_Valid;

  uint8                 StatusBoundaryDomainNonGlareLeftHandFLA;
  boolean eStatusBoundaryDomainNonGlareLeftHandFLA_Valid;

  uint8                 BoundaryDomainNonGlareRightHandFLA;
  boolean eBoundaryDomainNonGlareRightHandFLA_Valid;

  uint8                 StatusBoundaryDomainNonGlareRightHandFLA;
  boolean eStatusBoundaryDomainNonGlareRightHandFLA_Valid;

  uint8                 ObjectDistanceFLA;
  boolean eObjectDistanceFLA_Valid;

  uint8                 StatusObjectDistanceFLA;
  boolean eStatusObjectDistanceFLA_Valid;

  uint8                 ProbabilitySubsistenceFLA;
  boolean eProbabilitySubsistenceFLA_Valid;
}SimHlaEnetBMW_ObjectDataGlareFreeMainBeamAssistant_Enet_t;


typedef struct
{
  uint8                 PositionCutOffLineDippedBeamFLA;
  boolean ePositionCutOffLineDippedBeamFLA_Valid;

  uint8                 PositionCutOffLineLeftFLA;
  boolean ePositionCutOffLineLeftFLA_Valid;

  uint8                 PositionCutOffLineRightFLA;
  boolean ePositionCutOffLineRightFLA_Valid;

  uint8                 StatusPositionCutOffLineMainBeamFLA;
  boolean eStatusPositionCutOffLineMainBeamFLA_Valid;

  uint8                 StatusPositionCutOffLineLeftFLA;
  boolean eStatusPositionCutOffLineLeftFLA_Valid;

  uint8                 StatusPositionCutOffLineRightFLA;
  boolean eStatusPositionCutOffLineRightFLA_Valid;
} SimHlaEnetBMW_StatusGlareFreeMainBeamAssistant_Enet_t;


typedef struct
{
  RTE_HLAF_MatrixGFA_t GFA[3];
  uint8                nGFA;
  
}SimHlaEnetBMW_ObjectDataGlareFreeMainBeamAssistant_t;

typedef struct
{
  SimHlaEnetBMW_ControlMainBeamAssistant_Enet_t             ControlMainBeamAssistant_Enet; /* Ethernet raw data */
  SimHlaEnetBMW_ObjectDataGlareFreeMainBeamAssistant_Enet_t ObjectDataGlareFreeMainBeamAssistant_Enet[3]; /* Ethernet raw data */
  SimHlaEnetBMW_StatusGlareFreeMainBeamAssistant_Enet_t     StatusGlareFreeMainBeamAssistant_Enet[3]; /* Ethernet raw data */
}SimHlaEnetBMW_Input_t;

class CSimHlaEthernet : virtual public CSimHlaMeasData
{
public:
  CSimHlaEthernet(CSimSwcBase* pSimPlgBase);
  ~CSimHlaEthernet();

  void CollectKAFASInputs();

  boolean CheckKAFASInputs(void);

  void ResetEthReceivePorts(void);

  SimHlaMeasdata_t GetEthernetData(void)
  {
    return m_ENET_BMW;
  }


private:
  /* Eth Ports */
  SimReceivePort<uint8, simUI8_t> m_rpKAFAS_CtrlMainBeam_ControlMainBeam;
  SimReceivePort<uint8, simUI8_t> m_rpKAFAS_CtrlMainBeam_QuantityDomainNonGlare;
  SimReceivePort<uint8, simUI8_t> m_rpKAFAS_CtrlMainBeam_ReasonSwitchOffMainBeam;
  SimReceivePort<uint8, simUI8_t> m_rpKAFAS_CtrlMainBeam_ValidityObjectData;
  SimReceivePort<uint8, simUI8_t> m_rpKAFAS_ObjDataGlareFree0_BoundaryDomainBottomNonGlareFLA;
  SimReceivePort<uint8, simUI8_t> m_rpKAFAS_ObjDataGlareFree0_StatusBoundaryDomainBottomNonGlareFLA;
  SimReceivePort<uint8, simUI8_t> m_rpKAFAS_ObjDataGlareFree0_BoundaryDomainNonGlareLeftHandFLA;
  SimReceivePort<uint8, simUI8_t> m_rpKAFAS_ObjDataGlareFree0_StatusBoundaryDomainNonGlareLeftHandFLA;
  SimReceivePort<uint8, simUI8_t> m_rpKAFAS_ObjDataGlareFree0_BoundaryDomainNonGlareRightHandFLA;
  SimReceivePort<uint8, simUI8_t> m_rpKAFAS_ObjDataGlareFree0_StatusBoundaryDomainNonGlareRightHandFLA;
  SimReceivePort<uint8, simUI8_t> m_rpKAFAS_ObjDataGlareFree0_ObjectDistanceFLA;
  SimReceivePort<uint8, simUI8_t> m_rpKAFAS_ObjDataGlareFree0_StatusObjectDistanceFLA;
  SimReceivePort<uint8, simUI8_t> m_rpKAFAS_ObjDataGlareFree0_ProbabilitySubsistenceFLA;
  SimReceivePort<uint8, simUI8_t> m_rpZGW_StatusGlareFree0_PositionCutOffLineDippedBeamFLA;
  SimReceivePort<uint8, simUI8_t> m_rpZGW_StatusGlareFree0_PositionCutOffLineLeftFLA;
  SimReceivePort<uint8, simUI8_t> m_rpZGW_StatusGlareFree0_PositionCutOffLineRightFLA;
  SimReceivePort<uint8, simUI8_t> m_rpZGW_StatusGlareFree0_StatusPositionCutOffLineMainBeamFLA;
  SimReceivePort<uint8, simUI8_t> m_rpZGW_StatusGlareFree0_StatusPositionCutOffLineLeftFLA;
  SimReceivePort<uint8, simUI8_t> m_rpZGW_StatusGlareFree0_StatusPositionCutOffLineRightFLA;

  SimReceivePort<uint8, simUI8_t> m_rpKAFAS_ObjDataGlareFree1_BoundaryDomainBottomNonGlareFLA;
  SimReceivePort<uint8, simUI8_t> m_rpKAFAS_ObjDataGlareFree1_StatusBoundaryDomainBottomNonGlareFLA;
  SimReceivePort<uint8, simUI8_t> m_rpKAFAS_ObjDataGlareFree1_BoundaryDomainNonGlareLeftHandFLA;
  SimReceivePort<uint8, simUI8_t> m_rpKAFAS_ObjDataGlareFree1_StatusBoundaryDomainNonGlareLeftHandFLA;
  SimReceivePort<uint8, simUI8_t> m_rpKAFAS_ObjDataGlareFree1_BoundaryDomainNonGlareRightHandFLA;
  SimReceivePort<uint8, simUI8_t> m_rpKAFAS_ObjDataGlareFree1_StatusBoundaryDomainNonGlareRightHandFLA;
  SimReceivePort<uint8, simUI8_t> m_rpKAFAS_ObjDataGlareFree1_ObjectDistanceFLA;
  SimReceivePort<uint8, simUI8_t> m_rpKAFAS_ObjDataGlareFree1_StatusObjectDistanceFLA;
  SimReceivePort<uint8, simUI8_t> m_rpKAFAS_ObjDataGlareFree1_ProbabilitySubsistenceFLA;
  SimReceivePort<uint8, simUI8_t> m_rpZGW_StatusGlareFree1_PositionCutOffLineDippedBeamFLA;
  SimReceivePort<uint8, simUI8_t> m_rpZGW_StatusGlareFree1_PositionCutOffLineLeftFLA;
  SimReceivePort<uint8, simUI8_t> m_rpZGW_StatusGlareFree1_PositionCutOffLineRightFLA;
  SimReceivePort<uint8, simUI8_t> m_rpZGW_StatusGlareFree1_StatusPositionCutOffLineMainBeamFLA;
  SimReceivePort<uint8, simUI8_t> m_rpZGW_StatusGlareFree1_StatusPositionCutOffLineLeftFLA;
  SimReceivePort<uint8, simUI8_t> m_rpZGW_StatusGlareFree1_StatusPositionCutOffLineRightFLA;

  SimReceivePort<uint8, simUI8_t> m_rpKAFAS_ObjDataGlareFree2_BoundaryDomainBottomNonGlareFLA;
  SimReceivePort<uint8, simUI8_t> m_rpKAFAS_ObjDataGlareFree2_StatusBoundaryDomainBottomNonGlareFLA;
  SimReceivePort<uint8, simUI8_t> m_rpKAFAS_ObjDataGlareFree2_BoundaryDomainNonGlareLeftHandFLA;
  SimReceivePort<uint8, simUI8_t> m_rpKAFAS_ObjDataGlareFree2_StatusBoundaryDomainNonGlareLeftHandFLA;
  SimReceivePort<uint8, simUI8_t> m_rpKAFAS_ObjDataGlareFree2_BoundaryDomainNonGlareRightHandFLA;
  SimReceivePort<uint8, simUI8_t> m_rpKAFAS_ObjDataGlareFree2_StatusBoundaryDomainNonGlareRightHandFLA;
  SimReceivePort<uint8, simUI8_t> m_rpKAFAS_ObjDataGlareFree2_ObjectDistanceFLA;
  SimReceivePort<uint8, simUI8_t> m_rpKAFAS_ObjDataGlareFree2_StatusObjectDistanceFLA;
  SimReceivePort<uint8, simUI8_t> m_rpKAFAS_ObjDataGlareFree2_ProbabilitySubsistenceFLA;
  SimReceivePort<uint8, simUI8_t> m_rpZGW_StatusGlareFree2_PositionCutOffLineDippedBeamFLA;
  SimReceivePort<uint8, simUI8_t> m_rpZGW_StatusGlareFree2_PositionCutOffLineLeftFLA;
  SimReceivePort<uint8, simUI8_t> m_rpZGW_StatusGlareFree2_PositionCutOffLineRightFLA;
  SimReceivePort<uint8, simUI8_t> m_rpZGW_StatusGlareFree2_StatusPositionCutOffLineMainBeamFLA;
  SimReceivePort<uint8, simUI8_t> m_rpZGW_StatusGlareFree2_StatusPositionCutOffLineLeftFLA;
  SimReceivePort<uint8, simUI8_t> m_rpZGW_StatusGlareFree2_StatusPositionCutOffLineRightFLA;

  typedef std::vector<SimReceivePortBase*> SimReceivePortMap_t;

  SimReceivePortMap_t m_receivePortMapBMW;

  /* Ethernet: Can data */
  SimHlaMeasdata_t            m_ENET_BMW;
  SimHlaMeasdataBuffers_t     m_ENET_BMW_buffers;
  SimHlaEnetBMW_Input_t       m_ENET_BMW_input;

  void SetupEthPorts();

  void CheckPortsDirty(void);

  void CollectKAFAS_CtrlMainBeam_ControlMainBeam( const uint8 CtrlMainBeam_ControlMainBeam
                                                 );

  void CollectKAFAS_CtrlMainBeam_QuantityDomainNonGlare( const uint8 CtrlMainBeam_QuantityDomainNonGlare
                                                        );

  void CollectKAFAS_CtrlMainBeam_ReasonSwitchOffMainBeam( const uint8 CtrlMainBeam_ReasonSwitchOffMainBeam
                                                         );

  void CollectKAFAS_CtrlMainBeam_ValidityObjectData( const uint8 CtrlMainBeam_ValidityObjectData
                                                    );

  void CollectKAFAS_ObjDataGlareFree0_BoundaryDomainBottomNonGlareFLA( const uint8 idx,
                                                                       const uint8 BoundaryDomainBottomNonGlareFLA
                                                                      );

  void CollectKAFAS_ObjDataGlareFree0_StatusBoundaryDomainBottomNonGlareFLA( const uint8 idx,
                                                                             const uint8 StatusBoundaryDomainBottomNonGlareFLA
                                                                            );

  void CollectKAFAS_ObjDataGlareFree0_BoundaryDomainNonGlareLeftHandFLA( const uint8 idx,
                                                                         const uint8 BoundaryDomainNonGlareLeftHandFLA
                                                                        );

  void CollectKAFAS_ObjDataGlareFree0_StatusBoundaryDomainNonGlareLeftHandFLA( const uint8 idx,
                                                                               const uint8 StatusBoundaryDomainNonGlareLeftHandFLA
                                                                              );

  void CollectKAFAS_ObjDataGlareFree0_BoundaryDomainNonGlareRightHandFLA( const uint8 idx,
                                                                          const uint8 BoundaryDomainNonGlareRightHandFLA
                                                                         );

  void CollectKAFAS_ObjDataGlareFree0_StatusBoundaryDomainNonGlareRightHandFLA( const uint8 idx,
                                                                                const uint8 StatusBoundaryDomainNonGlareRightHandFLA
                                                                               );

  void CollectKAFAS_ObjDataGlareFree0_ObjectDistanceFLA( const uint8 idx,
                                                         const uint8 ObjectDistanceFLA
                                                        );

  void CollectKAFAS_ObjDataGlareFree0_StatusObjectDistanceFLA( const uint8 idx,
                                                               const uint8 StatusObjectDistanceFLA
                                                              );

  void CollectKAFAS_ObjDataGlareFree0_ProbabilitySubsistenceFLA( const uint8 idx,
                                                                 const uint8 ProbabilitySubsistenceFLA
                                                                );

  void CollectZGW_StatusGlareFree0_PositionCutOffLineDippedBeamFLA( const uint8 idx,
                                                                    const uint8 PositionCutOffLineDippedBeamFLA
                                                                   );

  void CollectZGW_StatusGlareFree0_PositionCutOffLineLeftFLA( const uint8 idx,
                                                              const uint8 PositionCutOffLineLeftFLA
                                                             );

  void CollectZGW_StatusGlareFree0_PositionCutOffLineRightFLA( const uint8 idx,
                                                               const uint8 PositionCutOffLineRightFLA
                                                              );

  void CollectZGW_StatusGlareFree0_StatusPositionCutOffLineMainBeamFLA( const uint8 StatusPositionCutOffLineMainBeamFLA,
                                                                        const uint8 PositionCutOffLineLeftFLA,
                                                                        const uint8 PositionCutOffLineRightFLA
                                                                       );
};
