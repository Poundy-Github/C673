/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter_fct

  MODULNAME:            sim_conv_DW_input_custom.cpp

  DESCRIPTION:          Converter class for DWInputCustom

  AUTHOR:               Teodora Cretu

  CREATION DATE:        21.03.2017

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: sim_conv_dw_input_custom.cpp  $
  CHANGES:              Revision 1.1 2017/08/10 13:15:14CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/fct/project.pj
  CHANGES:              Revision 1.2 2017/03/27 13:40:02CEST Cretu, Teodora (CretuT) 
  CHANGES:              Add new version V0_1 (structure size 144)
  CHANGES:              Revision 1.1 2017/03/23 12:05:15CET Cretu, Teodora (CretuT) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CRT_CommonRadarToolbox/04_Engineering/03_Workspace/algo/sim_adapter/fct/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */
#include "stdafx.h"
#include "sim_conv_DW_input_custom.h"
#include "sim_versioninfo_impl.h"

namespace DWInputCustomV0
{
  typedef unsigned long AlgoInterfaceVersionNumber_t /* Algo interface version nummbers @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned short AlgoCycleCounter_t        /* Algo cycle counter @min:0 @max:65535 */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned long AlgoDataTimeStamp_t       /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char AlgoSignalState_t         /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned long ACC_Status_t              /* @min: None @max:None */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned long DynamicObject00_t         /* @min: None @max:None */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned long StatusObject00_t          /* Status of the ACC Object 0 @min: None @max:None */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned long TypeObject00_t            /* Type of the ACC Object 0 @min: None @max:None */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned long AEB_FCWactivationState_t  /* @min: None @max:None */	/* [Satisfies_rte sws 1188] */;

  typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoDataTimeStamp_t uiTimeStamp;
 	AlgoCycleCounter_t uiMeasurementCounter;
 	AlgoCycleCounter_t uiCycleCounter;
 	AlgoSignalState_t eSigStatus;
 } SignalHeader_t;			/* Common header for all structured data types */

  typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float DistanceObject00;
 	ACC_Status_t ACC_Status;
 	StatusObject00_t StatusObject00;
 	TypeObject00_t TypeObject00;
 	DynamicObject00_t DynamicObject00;
 	float ExistenceProbabilityObject0;
 } DWACCData_t;			

  typedef struct 			/* [Satisfies_rte sws 1191] */
{
	boolean DW_ActivationRequest;
 	boolean UserSetPref_A2_NOTreceived;
 	boolean GenericApplicativeDiagEnabl;
 	boolean VehicleSpeedChecksum_OK;
 	boolean VehicleSpeedClock_Frozen;
 	boolean VDC_A9_NOTreceived;
 	boolean BCM_A7_NOTreceived;
 	float WheelSpeed_F_R;
 	float WheelSpeed_F_L;
 	float WheelSpeed_R_R;
 	float WheelSpeed_R_L;
 	boolean UnderVoltage;
 	boolean OverVoltage;
 	boolean CANFailure;
 	boolean Blindness;
 	boolean Misalignment;
 	boolean InternalElectronicFailure;
 	boolean IncompleteConfiguration;
 	boolean AirbagCrashOrder;
 	float VehicleSpeed;
 	boolean VDC_A3_NOTreceived;
 	boolean EraseFailure;
 	boolean AEB_DWInhibitionRequest;
 	AEB_FCWactivationState_t AEB_FCWactivationState;
 	boolean ADAS_A2_NOTReceived;
 } DWExternalInputs_t;	

  typedef struct 			/* [Satisfies_rte sws 1191] */
{
  AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSigHeader;
 	boolean DWActivationValue;
 	boolean EEPROMwrite_Trig_ZCE;
 	boolean GADDisabledSampletime1;
 	boolean Target_Display;
 	boolean AirbagCrashOrder_flag;
 	boolean Preprocessing_VehicleSpeed;
 	boolean Preprocessing_Target;
 	boolean DWDegradedMode;
 	boolean E_Failure5ToMD2;
 	boolean D_Failure1ToMD2;
 	boolean GenApplDiagEnable_Avail;
 	boolean DW_ActivationRequest_Avail;
 	DWExternalInputs_t DWExternalInputs;
 	DWACCData_t DWACCData;
 } FCTDWInputCustom_t;			/* @vaddr:0x202E0300 @vaddr_defs: FCT_MEAS_ID_DW_INPUT_CUSTOM @cycleid:FCT_VEH_IN @vname:FCTDWInputCustom */

};  // End of namespace DWInputCustomV0

namespace DWInputCustomV0_1
{
  typedef struct 			/* [Satisfies_rte sws 1191] */
{
	DWInputCustomV0::AlgoInterfaceVersionNumber_t uiVersionNumber;
 	DWInputCustomV0::SignalHeader_t sSigHeader;
 	boolean DW_ActivationRequestData;
 	unsigned char DW_ActivationRequestStatus;
 	boolean GenericApplicativeDiagEnablData;
 	unsigned char GenericApplicativeDiagEnablStatus;
 	float WheelSpeed_F_R_Data;
 	unsigned char WheelSpeed_F_R_Status;
 	float WheelSpeed_F_L_Data;
 	unsigned char WheelSpeed_F_L_Status;
 	float WheelSpeed_R_R_Data;
 	unsigned char WheelSpeed_R_R_Status;
 	float WheelSpeed_R_L_Data;
 	unsigned char WheelSpeed_R_L_Status;
 	boolean UnderVoltage;
 	boolean OverVoltage;
 	boolean CANFailure;
 	boolean Blindness;
 	boolean Misalignment;
 	boolean InternalElectronicFailure;
 	boolean IncompleteConfiguration;
 	boolean AirbagCrashOrderData;
 	unsigned char AirbagCrashOrderStatus;
 	float VehicleSpeedData;
 	unsigned char VehicleSpeedStatus;
 	boolean EraseFailure;
 	boolean AEB_DWInhibitionRequestData;
 	unsigned char AEB_DWInhibitionRequestStatus;
 	boolean AEB_FCWactivationState;
 	boolean DWActivationState_IN;
 	boolean RearGearEngagedData;
 	unsigned char RearGearEngagedStatus;
 	float GearLeverPositionData;
 	boolean GearLeverPositionStatus;
 	float NeutralContactData;
 	unsigned char NeutralContactStatus;
 	float SWACorrectedData;
 	unsigned char SWACorrectedStatus;
 	float YawRateRawData;
 	unsigned char YawRateRawStatus;
 	float RearWheelAnglePosData;
 	unsigned char RearWheelAnglePosStatus;
 	float YawRateCorrectedData;
 	unsigned char YawRateCorrectedStatus;
 	DWInputCustomV0::DWACCData_t DWACCData;
 } FCTDWInputCustom_t;			/* @vaddr:0x202E0300 @vaddr_defs: FCT_MEAS_ID_DW_INPUT_CUSTOM @cycleid:FCT_VEH_IN @vname:FCTDWInputCustom */

};  // End of namespace DWInputCustomV0_1

namespace DWInputCustomV3
{

  typedef struct 			/* [Satisfies_rte sws 1191] */
{
	unsigned char ACC_StatusData;
 	unsigned char ACC_StatusStatus;
 	unsigned char StatusObject00;
 	float DistanceObject00;
 	unsigned char TypeObject00;
 	unsigned char DynamicObject00;
 	unsigned char ExistenceProbabilityObject0;
 } DWACCData_t;			

  typedef struct 			/* [Satisfies_rte sws 1191] */
{
	DWInputCustomV0::AlgoInterfaceVersionNumber_t uiVersionNumber;
 	DWInputCustomV0::SignalHeader_t sSigHeader;
 	unsigned char DW_ActivationRequestData;
 	unsigned char DW_ActivationRequestStatus;
 	boolean GenericApplicativeDiagEnablData;
 	unsigned char GenericApplicativeDiagEnablStatus;
 	float WheelSpeed_F_R_Data;
 	unsigned char WheelSpeed_F_R_Status;
 	float WheelSpeed_F_L_Data;
 	unsigned char WheelSpeed_F_L_Status;
 	float WheelSpeed_R_R_Data;
 	unsigned char WheelSpeed_R_R_Status;
 	float WheelSpeed_R_L_Data;
 	unsigned char WheelSpeed_R_L_Status;
 	boolean UnderVoltage;
 	boolean OverVoltage;
 	boolean CANFailure;
 	boolean Blindness;
 	boolean Misalignment;
 	boolean InternalElectronicFailure;
 	boolean IncompleteConfiguration;
 	boolean AirbagCrashOrderData;
 	unsigned char AirbagCrashOrderStatus;
 	float VehicleSpeedData;
 	unsigned char VehicleSpeedStatus;
 	boolean EraseFailure;
 	boolean DWActivationState_IN;
 	float SWACorrectedData;
 	unsigned char SWACorrectedStatus;
 	float YawRateRawData;
 	unsigned char YawRateRawStatus;
 	float RearWheelAnglePosData;
 	unsigned char RearWheelAnglePosStatus;
 	float YawRateCorrectedData;
 	unsigned char YawRateCorrectedStatus;
 	DWACCData_t DWACCData;
 } FCTDWInputCustom_t;			/* @vaddr:0x202E0300 @vaddr_defs: FCT_MEAS_ID_DW_INPUT_CUSTOM @cycleid:FCT_VEH_IN @vname:FCTDWInputCustom */

};  // End of namespace DWInputCustomV3

namespace DWInputCustom_Gen
{
  typedef unsigned long ACC_Status_t              /* @min: None @max:None */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned long DynamicObject00_t         /* @min: None @max:None */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned long StatusObject00_t          /* Status of the ACC Object 0 @min: None @max:None */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned long TypeObject00_t            /* Type of the ACC Object 0 @min: None @max:None */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned long AEB_FCWactivationState_t  /* @min: None @max:None */	/* [Satisfies_rte sws 1188] */;

  typedef struct
{
	float DistanceObject00;
 	ACC_Status_t ACC_Status;
  unsigned char ACC_StatusData;
 	unsigned char ACC_StatusStatus;
 	StatusObject00_t StatusObject00;
 	TypeObject00_t TypeObject00;
 	DynamicObject00_t DynamicObject00;
 	float ExistenceProbabilityObject0;
 } DWACCData;			

  typedef struct
{
	boolean DW_ActivationRequest;
 	boolean UserSetPref_A2_NOTreceived;
 	boolean GenericApplicativeDiagEnabl;
 	boolean VehicleSpeedChecksum_OK;
 	boolean VehicleSpeedClock_Frozen;
 	boolean VDC_A9_NOTreceived;
 	boolean BCM_A7_NOTreceived;
 	float WheelSpeed_F_R;
 	float WheelSpeed_F_L;
 	float WheelSpeed_R_R;
 	float WheelSpeed_R_L;
 	boolean UnderVoltage;
 	boolean OverVoltage;
 	boolean CANFailure;
 	boolean Blindness;
 	boolean Misalignment;
 	boolean InternalElectronicFailure;
 	boolean IncompleteConfiguration;
 	boolean AirbagCrashOrder;
 	float VehicleSpeed;
 	boolean VDC_A3_NOTreceived;
 	boolean EraseFailure;
 	boolean AEB_DWInhibitionRequest;
 	AEB_FCWactivationState_t AEB_FCWactivationState;
 	boolean ADAS_A2_NOTReceived;
 } DWExternalInputs_t;	

  typedef struct
{
  DWInputCustomV0::AlgoInterfaceVersionNumber_t uiVersionNumber;
 	DWInputCustomV0::SignalHeader_t sSigHeader;
 	boolean DWActivationValue;
 	boolean EEPROMwrite_Trig_ZCE;
 	boolean GADDisabledSampletime1;
 	boolean Target_Display;
 	boolean AirbagCrashOrder_flag;
 	boolean Preprocessing_VehicleSpeed;
 	boolean Preprocessing_Target;
 	boolean DWDegradedMode;
 	boolean E_Failure5ToMD2;
 	boolean D_Failure1ToMD2;
 	boolean GenApplDiagEnable_Avail;
 	boolean DW_ActivationRequest_Avail;
 	DWExternalInputs_t DWExternalInputs;
	unsigned char DW_ActivationRequestData;
 	unsigned char DW_ActivationRequestStatus;
 	boolean GenericApplicativeDiagEnablData;
 	unsigned char GenericApplicativeDiagEnablStatus;
 	float WheelSpeed_F_R_Data;
 	unsigned char WheelSpeed_F_R_Status;
 	float WheelSpeed_F_L_Data;
 	unsigned char WheelSpeed_F_L_Status;
 	float WheelSpeed_R_R_Data;
 	unsigned char WheelSpeed_R_R_Status;
 	float WheelSpeed_R_L_Data;
 	unsigned char WheelSpeed_R_L_Status;
 	boolean UnderVoltage;
 	boolean OverVoltage;
 	boolean CANFailure;
 	boolean Blindness;
 	boolean Misalignment;
 	boolean InternalElectronicFailure;
 	boolean IncompleteConfiguration;
 	boolean AirbagCrashOrderData;
 	unsigned char AirbagCrashOrderStatus;
 	float VehicleSpeedData;
 	unsigned char VehicleSpeedStatus;
 	boolean EraseFailure;
  boolean AEB_DWInhibitionRequestData;
 	unsigned char AEB_DWInhibitionRequestStatus;
 	boolean AEB_FCWactivationState;
 	boolean DWActivationState_IN;
  boolean RearGearEngagedData;
 	unsigned char RearGearEngagedStatus;
 	float GearLeverPositionData;
 	boolean GearLeverPositionStatus;
 	float NeutralContactData;
 	unsigned char NeutralContactStatus;
 	float SWACorrectedData;
 	unsigned char SWACorrectedStatus;
 	float YawRateRawData;
 	unsigned char YawRateRawStatus;
 	float RearWheelAnglePosData;
 	unsigned char RearWheelAnglePosStatus;
 	float YawRateCorrectedData;
 	unsigned char YawRateCorrectedStatus;
 	DWACCData DWACCData;
 } FCTDWInputCustom_t;

};  // End of namespace DWInputCustom_Gen

//
// Main DWInputCustom conversion class
//

class CConvDWInputCustom : public CSimConverterBase
{
  
  // the list of dependency names used inside by the converter
  /*
  static const char* DEP_NAMES[];
  */

  // here we define the index of each dependency for quick acces
  // the order here should match with the order from DEP_NAMES array
  enum eDepIdx
  {
    // add new dependencies here 
    DEP_COUNT
  };

  DWInputCustom_Gen::FCTDWInputCustom_t m_BufGen;
  DWInputCustomV0::FCTDWInputCustom_t m_DWInputCustomV0;
  DWInputCustomV0_1::FCTDWInputCustom_t m_DWInputCustomV0_1;
  DWInputCustomV3::FCTDWInputCustom_t m_DWInputCustomV3;

  void InitGen(DWInputCustom_Gen::FCTDWInputCustom_t & Params);
  void InitV0(DWInputCustomV0::FCTDWInputCustom_t & Dest);
  void InitV0_1(DWInputCustomV0_1::FCTDWInputCustom_t & Dest);
  void InitV3(DWInputCustomV3::FCTDWInputCustom_t & Dest);

  static void Convert_V0_to_Gen(DWInputCustom_Gen::FCTDWInputCustom_t & Dest, const DWInputCustomV0::FCTDWInputCustom_t & Src);
  static void Convert_V0_1_to_Gen(DWInputCustom_Gen::FCTDWInputCustom_t & Dest, const DWInputCustomV0_1::FCTDWInputCustom_t & Src);
  static void Convert_V3_to_Gen(DWInputCustom_Gen::FCTDWInputCustom_t & Dest, const DWInputCustomV3::FCTDWInputCustom_t & Src);
  
  static void Convert_Gen_to_V0(DWInputCustomV0::FCTDWInputCustom_t & Dest, const DWInputCustom_Gen::FCTDWInputCustom_t & Src);
  static void Convert_Gen_to_V0_1(DWInputCustomV0_1::FCTDWInputCustom_t & Dest, const DWInputCustom_Gen::FCTDWInputCustom_t & Src);
  static void Convert_Gen_to_V3(DWInputCustomV3::FCTDWInputCustom_t & Dest, const DWInputCustom_Gen::FCTDWInputCustom_t & Src);
  
public:

  static const char* GetConverterTypeName()
  {
    return "DWInputCustom";
  }

  CConvDWInputCustom(void);
  virtual ~CConvDWInputCustom(void);

  const char* GetTypeName()
  {
    return GetConverterTypeName();
  }

  void Destroy()
  {
    delete this;
  }

  /** returns: 
   *   SIM_ERR_OK - when this value can be used
   *   SIM_ERR_USE_VALUE_FROM_PPORT - when the conversion is not implemented here
   *                                  and the value from Provide Port must be used
   */
  long ConvertData(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo, 
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo* pProvidePortVersionInfo, 
    void* pPPortData,
    void** pOutData, unsigned long& ulOutSize);
  
  /** returns: 
   *   SIM_ERR_OK - when this value can be used
   *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implemented here
   *                                            and the default value from Request Port must be used
   */
  long GetDefaultValue(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo, 
    void** pDefaultData, unsigned long& ulDefaultSize);

protected:

  // used to check if an unversioned PPort is compatible with a certain version of RPort
  bool IsVersionCompatibleWithType(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo, 
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize);

  // used to check if ports are compatible between different versions
  bool AreVersionsCompatible(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo& providePortVersionInfo);
private:

  static CVersionInfoImpl BASE_VERSION;
  static CVersionInfoImpl DW_INPUT_CUSTOM_V0_VERSION;
  static CVersionInfoImpl DW_INPUT_CUSTOM_V0_1_VERSION;
  static CVersionInfoImpl DW_INPUT_CUSTOM_V3_VERSION;
  static CVersionInfoImpl DW_INPUT_CUSTOM_V3_1_VERSION;

  enum eDWInputCustomVersions
  {
    DW_INPUT_CUSTOM_DUMMY_INPUT,
    DW_INPUT_CUSTOM_V0,
    DW_INPUT_CUSTOM_V0_1,
    DW_INPUT_CUSTOM_V3,
    DW_INPUT_CUSTOM_V3_1,
    DW_INPUT_CUSTOM_VERSION_COUNT
  };
  static unsigned long SUPPORTED_SIZE[DW_INPUT_CUSTOM_VERSION_COUNT];
  static const CVersionInfoImpl * const DW_INPUT_CUSTOM_VERSIONS[DW_INPUT_CUSTOM_VERSION_COUNT];

  bool IsPortSupported(unsigned long ulPortSize, const IVersionInfo * pPortVersion) const;
};

CVersionInfoImpl  CConvDWInputCustom::BASE_VERSION(0, 0, 0);
CVersionInfoImpl  CConvDWInputCustom::DW_INPUT_CUSTOM_V0_VERSION(0, 0, 0);
CVersionInfoImpl  CConvDWInputCustom::DW_INPUT_CUSTOM_V0_1_VERSION(0, 0, 0);
CVersionInfoImpl  CConvDWInputCustom::DW_INPUT_CUSTOM_V3_VERSION(0, 0, 3);
CVersionInfoImpl  CConvDWInputCustom::DW_INPUT_CUSTOM_V3_1_VERSION(0, 0, 3);

static uint32 DummyVersion = 0xFFFFFFFFu;

unsigned long CConvDWInputCustom::SUPPORTED_SIZE[CConvDWInputCustom::DW_INPUT_CUSTOM_VERSION_COUNT]=
{
  sizeof(DummyVersion),     //!< Special dummy for 4 byte version number only (i.e.: no ACC interface of FCT component)
  sizeof(DWInputCustomV0::FCTDWInputCustom_t),
  sizeof(DWInputCustomV0_1::FCTDWInputCustom_t),
  sizeof(DWInputCustomV3::FCTDWInputCustom_t),
  sizeof(DWInputCustomV0::FCTDWInputCustom_t)
};

const CVersionInfoImpl * const CConvDWInputCustom::DW_INPUT_CUSTOM_VERSIONS[CConvDWInputCustom::DW_INPUT_CUSTOM_VERSION_COUNT] =
{
  &BASE_VERSION,
  &DW_INPUT_CUSTOM_V0_VERSION,
  &DW_INPUT_CUSTOM_V0_1_VERSION,
  &DW_INPUT_CUSTOM_V3_VERSION,
  &DW_INPUT_CUSTOM_V3_1_VERSION
};

CConvDWInputCustom::CConvDWInputCustom(void)
: CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT), m_DWInputCustomV0(), m_DWInputCustomV3()
{
  InitV0(m_DWInputCustomV0);
  InitV0_1(m_DWInputCustomV0_1);
  InitV3(m_DWInputCustomV3);
}

CConvDWInputCustom::~CConvDWInputCustom(void)
{
}

bool CConvDWInputCustom::IsPortSupported(unsigned long ulPortSize, const IVersionInfo * pPortVersion) const
{
  for (int nI=0; nI<DW_INPUT_CUSTOM_VERSION_COUNT; nI++)
  {
    if ((pPortVersion == NULL) ||
      (pPortVersion->Equals(&BASE_VERSION)) ||
      (pPortVersion->Equals(DW_INPUT_CUSTOM_VERSIONS[nI])))
    {
      if (ulPortSize == SUPPORTED_SIZE[nI])
      {
        return true;
      }
    }
  }
  return false;
};

void CConvDWInputCustom::InitGen(DWInputCustom_Gen::FCTDWInputCustom_t & Dest)
{
  memset(&Dest, 0, sizeof(Dest));
}

void CConvDWInputCustom::InitV0(DWInputCustomV0::FCTDWInputCustom_t & Dest)
{
  memset(&Dest, 0, sizeof(Dest));
  Dest.uiVersionNumber  = 0;
}

void CConvDWInputCustom::InitV0_1(DWInputCustomV0_1::FCTDWInputCustom_t & Dest)
{
  memset(&Dest, 0, sizeof(Dest));
  Dest.uiVersionNumber  = 0;
}

void CConvDWInputCustom::InitV3(DWInputCustomV3::FCTDWInputCustom_t & Dest)
{
  memset(&Dest, 0, sizeof(Dest));
  Dest.uiVersionNumber  = 3;
}

void CConvDWInputCustom::Convert_V0_to_Gen(DWInputCustom_Gen::FCTDWInputCustom_t & Dest, const DWInputCustomV0::FCTDWInputCustom_t & Src)
{
  Dest.DWActivationValue            = Src.DWActivationValue;
  Dest.DWActivationState_IN         = Src.DWActivationValue;
  Dest.EEPROMwrite_Trig_ZCE         = Src.EEPROMwrite_Trig_ZCE;
  Dest.GADDisabledSampletime1       = Src.GADDisabledSampletime1;
  Dest.Target_Display               = Src.Target_Display;
  Dest.AirbagCrashOrder_flag        = Src.AirbagCrashOrder_flag;
  Dest.AirbagCrashOrderData         = Src.AirbagCrashOrder_flag;
  Dest.Preprocessing_VehicleSpeed   = Src.Preprocessing_VehicleSpeed;
  Dest.Preprocessing_Target         = Src.Preprocessing_Target;
  Dest.DWDegradedMode               = Src.DWDegradedMode;
  Dest.E_Failure5ToMD2              = Src.E_Failure5ToMD2;
  Dest.D_Failure1ToMD2              = Src.D_Failure1ToMD2;
  Dest.GenApplDiagEnable_Avail      = Src.GenApplDiagEnable_Avail;
  Dest.DW_ActivationRequest_Avail   = Src.DW_ActivationRequest_Avail;

  Dest.DWExternalInputs.DW_ActivationRequest               = Src.DWExternalInputs.DW_ActivationRequest;
  Dest.DWExternalInputs.UserSetPref_A2_NOTreceived         = Src.DWExternalInputs.UserSetPref_A2_NOTreceived;
  Dest.DWExternalInputs.GenericApplicativeDiagEnabl        = Src.DWExternalInputs.GenericApplicativeDiagEnabl;
  Dest.DWExternalInputs.VehicleSpeedChecksum_OK            = Src.DWExternalInputs.VehicleSpeedChecksum_OK;
  Dest.DWExternalInputs.VehicleSpeedClock_Frozen           = Src.DWExternalInputs.VehicleSpeedClock_Frozen;
  Dest.DWExternalInputs.VDC_A9_NOTreceived                 = Src.DWExternalInputs.VDC_A9_NOTreceived;
  Dest.DWExternalInputs.BCM_A7_NOTreceived                 = Src.DWExternalInputs.BCM_A7_NOTreceived;
  Dest.DWExternalInputs.WheelSpeed_F_R                     = Src.DWExternalInputs.WheelSpeed_F_R;
  Dest.WheelSpeed_F_R_Data                                 = Src.DWExternalInputs.WheelSpeed_F_R;
  Dest.DWExternalInputs.WheelSpeed_F_L                     = Src.DWExternalInputs.WheelSpeed_F_L;
  Dest.WheelSpeed_F_L_Data                                 = Src.DWExternalInputs.WheelSpeed_F_L;
  Dest.DWExternalInputs.WheelSpeed_R_R                     = Src.DWExternalInputs.WheelSpeed_R_R;
  Dest.WheelSpeed_R_R_Data                                 = Src.DWExternalInputs.WheelSpeed_R_R;
  Dest.DWExternalInputs.WheelSpeed_R_L                     = Src.DWExternalInputs.WheelSpeed_R_L;
  Dest.WheelSpeed_R_L_Data                                 = Src.DWExternalInputs.WheelSpeed_R_L;
  Dest.DWExternalInputs.UnderVoltage                       = Src.DWExternalInputs.UnderVoltage;
  Dest.DWExternalInputs.OverVoltage                        = Src.DWExternalInputs.OverVoltage;
  Dest.DWExternalInputs.CANFailure                         = Src.DWExternalInputs.CANFailure;
  Dest.DWExternalInputs.Blindness                          = Src.DWExternalInputs.Blindness;
  Dest.DWExternalInputs.Misalignment                       = Src.DWExternalInputs.Misalignment;
  Dest.DWExternalInputs.InternalElectronicFailure          = Src.DWExternalInputs.InternalElectronicFailure;
  Dest.DWExternalInputs.IncompleteConfiguration            = Src.DWExternalInputs.IncompleteConfiguration;
  Dest.DWExternalInputs.AirbagCrashOrder                   = Src.DWExternalInputs.AirbagCrashOrder;
  Dest.DWExternalInputs.VehicleSpeed                       = Src.DWExternalInputs.VehicleSpeed;
  Dest.VehicleSpeedData                                    = Src.DWExternalInputs.VehicleSpeed;
  Dest.DWExternalInputs.VDC_A3_NOTreceived                 = Src.DWExternalInputs.VDC_A3_NOTreceived;
  Dest.DWExternalInputs.EraseFailure                       = Src.DWExternalInputs.EraseFailure;
  Dest.DWExternalInputs.AEB_DWInhibitionRequest            = Src.DWExternalInputs.AEB_DWInhibitionRequest;
  Dest.DWExternalInputs.AEB_FCWactivationState             = Src.DWExternalInputs.AEB_FCWactivationState;
  Dest.DWExternalInputs.ADAS_A2_NOTReceived                = Src.DWExternalInputs.ADAS_A2_NOTReceived;

  Dest.DWACCData.DistanceObject00                 = Src.DWACCData.DistanceObject00;
  Dest.DWACCData.ExistenceProbabilityObject0      = Src.DWACCData.ExistenceProbabilityObject0;
  Dest.DWACCData.ACC_Status                       = Src.DWACCData.ACC_Status;
  Dest.DWACCData.StatusObject00                   = Src.DWACCData.StatusObject00;
  Dest.DWACCData.TypeObject00                     = Src.DWACCData.TypeObject00;
  Dest.DWACCData.DynamicObject00                  = Src.DWACCData.DynamicObject00;
}

void CConvDWInputCustom::Convert_V0_1_to_Gen(DWInputCustom_Gen::FCTDWInputCustom_t & Dest, const DWInputCustomV0_1::FCTDWInputCustom_t & Src)
{
  Dest.DWExternalInputs.DW_ActivationRequest = Src.DW_ActivationRequestData;
  Dest.DW_ActivationRequestData              = Src.DW_ActivationRequestData;
  Dest.DW_ActivationRequestStatus            = Src.DW_ActivationRequestStatus;
  Dest.GenericApplicativeDiagEnablData       = Src.GenericApplicativeDiagEnablData;
  Dest.GenericApplicativeDiagEnablStatus     = Src.GenericApplicativeDiagEnablStatus;
  Dest.WheelSpeed_F_R_Data                   = Src.WheelSpeed_F_R_Data;
  Dest.DWExternalInputs.WheelSpeed_F_R       = Src.WheelSpeed_F_R_Data;
  Dest.WheelSpeed_F_R_Status                 = Src.WheelSpeed_F_R_Status;
  Dest.WheelSpeed_F_L_Data                   = Src.WheelSpeed_F_L_Data;
  Dest.DWExternalInputs.WheelSpeed_F_L       = Src.WheelSpeed_F_L_Data;
  Dest.WheelSpeed_F_L_Status                 = Src.WheelSpeed_F_L_Status;
  Dest.WheelSpeed_R_R_Data                   = Src.WheelSpeed_R_R_Data;
  Dest.DWExternalInputs.WheelSpeed_R_R       = Src.WheelSpeed_R_R_Data;
  Dest.WheelSpeed_R_R_Status                 = Src.WheelSpeed_R_R_Status;
  Dest.WheelSpeed_R_L_Data                   = Src.WheelSpeed_R_L_Data;
  Dest.DWExternalInputs.WheelSpeed_R_L       = Src.WheelSpeed_R_L_Data;
  Dest.WheelSpeed_R_L_Status                 = Src.WheelSpeed_R_L_Status;
  Dest.UnderVoltage                          = Src.UnderVoltage;
  Dest.OverVoltage                           = Src.OverVoltage;
  Dest.CANFailure                            = Src.CANFailure;
  Dest.Blindness                             = Src.Blindness;
  Dest.Misalignment                          = Src.Misalignment;
  Dest.InternalElectronicFailure             = Src.InternalElectronicFailure;
  Dest.IncompleteConfiguration               = Src.IncompleteConfiguration;
  Dest.AirbagCrashOrderData                  = Src.AirbagCrashOrderData;
  Dest.AirbagCrashOrder_flag                 = Src.AirbagCrashOrderData;
  Dest.AirbagCrashOrderStatus                = Src.AirbagCrashOrderStatus;
  Dest.VehicleSpeedData                      = Src.VehicleSpeedData;
  Dest.DWExternalInputs.VehicleSpeed         = Src.VehicleSpeedData;
  Dest.VehicleSpeedStatus                    = Src.VehicleSpeedStatus;
  Dest.EraseFailure                          = Src.EraseFailure;
  Dest.AEB_DWInhibitionRequestData           = Src.AEB_DWInhibitionRequestData;
  Dest.AEB_DWInhibitionRequestStatus         = Src.AEB_DWInhibitionRequestStatus;
  Dest.AEB_FCWactivationState                = Src.AEB_FCWactivationState;
  Dest.DWActivationState_IN                  = Src.DWActivationState_IN;
  Dest.DWActivationValue                     = Src.DWActivationState_IN;
  Dest.RearGearEngagedData                   = Src.RearGearEngagedData;
  Dest.RearGearEngagedStatus                 = Src.RearGearEngagedStatus;
  Dest.GearLeverPositionData                 = Src.GearLeverPositionData;
  Dest.GearLeverPositionStatus               = Src.GearLeverPositionStatus;
  Dest.NeutralContactData                    = Src.NeutralContactData;
  Dest.NeutralContactStatus                  = Src.NeutralContactStatus;
  Dest.SWACorrectedData                      = Src.SWACorrectedData;
  Dest.SWACorrectedStatus                    = Src.SWACorrectedStatus;
  Dest.YawRateRawData                        = Src.YawRateRawData;
  Dest.YawRateRawStatus                      = Src.YawRateRawStatus;
  Dest.RearWheelAnglePosData                 = Src.RearWheelAnglePosData;
  Dest.RearWheelAnglePosStatus               = Src.RearWheelAnglePosStatus;
  Dest.YawRateCorrectedData                  = Src.YawRateCorrectedData;
  Dest.YawRateCorrectedStatus                = Src.YawRateCorrectedStatus;

  Dest.DWACCData.ACC_StatusData                = Src.DWACCData.ACC_Status;
  Dest.DWACCData.StatusObject00                = Src.DWACCData.StatusObject00;
  Dest.DWACCData.DistanceObject00              = Src.DWACCData.DistanceObject00;
  Dest.DWACCData.TypeObject00                  = Src.DWACCData.TypeObject00;
  Dest.DWACCData.DynamicObject00               = Src.DWACCData.DynamicObject00;
  Dest.DWACCData.ExistenceProbabilityObject0   = Src.DWACCData.ExistenceProbabilityObject0;
}

void CConvDWInputCustom::Convert_V3_to_Gen(DWInputCustom_Gen::FCTDWInputCustom_t & Dest, const DWInputCustomV3::FCTDWInputCustom_t & Src)
{
  Dest.DWExternalInputs.DW_ActivationRequest = Src.DW_ActivationRequestData;
  Dest.DW_ActivationRequestData              = Src.DW_ActivationRequestData;
  Dest.DW_ActivationRequestStatus            = Src.DW_ActivationRequestStatus;
  Dest.GenericApplicativeDiagEnablData       = Src.GenericApplicativeDiagEnablData;
  Dest.GenericApplicativeDiagEnablStatus     = Src.GenericApplicativeDiagEnablStatus;
  Dest.WheelSpeed_F_R_Data                   = Src.WheelSpeed_F_R_Data;
  Dest.DWExternalInputs.WheelSpeed_F_R       = Src.WheelSpeed_F_R_Data;
  Dest.WheelSpeed_F_R_Status                 = Src.WheelSpeed_F_R_Status;
  Dest.WheelSpeed_F_L_Data                   = Src.WheelSpeed_F_L_Data;
  Dest.DWExternalInputs.WheelSpeed_F_L       = Src.WheelSpeed_F_L_Data;
  Dest.WheelSpeed_F_L_Status                 = Src.WheelSpeed_F_L_Status;
  Dest.WheelSpeed_R_R_Data                   = Src.WheelSpeed_R_R_Data;
  Dest.DWExternalInputs.WheelSpeed_R_R       = Src.WheelSpeed_R_R_Data;
  Dest.WheelSpeed_R_R_Status                 = Src.WheelSpeed_R_R_Status;
  Dest.WheelSpeed_R_L_Data                   = Src.WheelSpeed_R_L_Data;
  Dest.DWExternalInputs.WheelSpeed_R_L       = Src.WheelSpeed_R_L_Data;
  Dest.WheelSpeed_R_L_Status                 = Src.WheelSpeed_R_L_Status;
  Dest.UnderVoltage                          = Src.UnderVoltage;
  Dest.OverVoltage                           = Src.OverVoltage;
  Dest.CANFailure                            = Src.CANFailure;
  Dest.Blindness                             = Src.Blindness;
  Dest.Misalignment                          = Src.Misalignment;
  Dest.InternalElectronicFailure             = Src.InternalElectronicFailure;
  Dest.IncompleteConfiguration               = Src.IncompleteConfiguration;
  Dest.AirbagCrashOrderData                  = Src.AirbagCrashOrderData;
  Dest.AirbagCrashOrder_flag                 = Src.AirbagCrashOrderData;
  Dest.AirbagCrashOrderStatus                = Src.AirbagCrashOrderStatus;
  Dest.VehicleSpeedData                      = Src.VehicleSpeedData;
  Dest.DWExternalInputs.VehicleSpeed         = Src.VehicleSpeedData;
  Dest.VehicleSpeedStatus                    = Src.VehicleSpeedStatus;
  Dest.EraseFailure                          = Src.EraseFailure;
  Dest.DWActivationState_IN                  = Src.DWActivationState_IN;
  Dest.DWActivationValue                     = Src.DWActivationState_IN;
  Dest.SWACorrectedData                      = Src.SWACorrectedData;
  Dest.SWACorrectedStatus                    = Src.SWACorrectedStatus;
  Dest.YawRateRawData                        = Src.YawRateRawData;
  Dest.YawRateRawStatus                      = Src.YawRateRawStatus;
  Dest.RearWheelAnglePosData                 = Src.RearWheelAnglePosData;
  Dest.RearWheelAnglePosStatus               = Src.RearWheelAnglePosStatus;
  Dest.YawRateCorrectedData                  = Src.YawRateCorrectedData;
  Dest.YawRateCorrectedStatus                = Src.YawRateCorrectedStatus;

  Dest.DWACCData.ACC_StatusData                = Src.DWACCData.ACC_StatusData;
  Dest.DWACCData.ACC_StatusStatus              = Src.DWACCData.ACC_StatusStatus;
  Dest.DWACCData.StatusObject00                = Src.DWACCData.StatusObject00;
  Dest.DWACCData.DistanceObject00              = Src.DWACCData.DistanceObject00;
  Dest.DWACCData.TypeObject00                  = Src.DWACCData.TypeObject00;
  Dest.DWACCData.DynamicObject00               = Src.DWACCData.DynamicObject00;
  Dest.DWACCData.ExistenceProbabilityObject0   = Src.DWACCData.ExistenceProbabilityObject0;
}

void CConvDWInputCustom::Convert_Gen_to_V0(DWInputCustomV0::FCTDWInputCustom_t & Dest, const DWInputCustom_Gen::FCTDWInputCustom_t & Src)
{
  Dest.uiVersionNumber                  = 0u;
  Dest.DWActivationValue                = Src.DWActivationValue;
  Dest.EEPROMwrite_Trig_ZCE             = Src.EEPROMwrite_Trig_ZCE;
  Dest.GADDisabledSampletime1           = Src.GADDisabledSampletime1;
  Dest.Target_Display                   = Src.Target_Display;
  Dest.AirbagCrashOrder_flag            = Src.AirbagCrashOrder_flag;
  Dest.Preprocessing_VehicleSpeed       = Src.Preprocessing_VehicleSpeed;
  Dest.Preprocessing_Target             = Src.Preprocessing_Target;
  Dest.DWDegradedMode                   = Src.DWDegradedMode;
  Dest.E_Failure5ToMD2                  = Src.E_Failure5ToMD2;
  Dest.D_Failure1ToMD2                  = Src.D_Failure1ToMD2;
  Dest.GenApplDiagEnable_Avail          = Src.GenApplDiagEnable_Avail;
  Dest.DW_ActivationRequest_Avail       = Src.DW_ActivationRequest_Avail;
  
  memcpy(&(Dest.DWExternalInputs), &(Src.DWExternalInputs), sizeof(Dest.DWExternalInputs));
  memcpy(&(Dest.DWACCData), &(Src.DWACCData), sizeof(Dest.DWACCData));
}

void CConvDWInputCustom::Convert_Gen_to_V0_1(DWInputCustomV0_1::FCTDWInputCustom_t & Dest, const DWInputCustom_Gen::FCTDWInputCustom_t & Src)
{
  Dest.uiVersionNumber                       = 0u;
  Dest.DW_ActivationRequestData              = Src.DW_ActivationRequestData;
  Dest.DW_ActivationRequestStatus            = Src.DW_ActivationRequestStatus;
  Dest.GenericApplicativeDiagEnablData       = Src.GenericApplicativeDiagEnablData;
  Dest.GenericApplicativeDiagEnablStatus     = Src.GenericApplicativeDiagEnablStatus;
  Dest.WheelSpeed_F_R_Data                   = Src.WheelSpeed_F_R_Data;
  Dest.WheelSpeed_F_R_Status                 = Src.WheelSpeed_F_R_Status;
  Dest.WheelSpeed_F_L_Data                   = Src.WheelSpeed_F_L_Data;
  Dest.WheelSpeed_F_L_Status                 = Src.WheelSpeed_F_L_Status;
  Dest.WheelSpeed_R_R_Data                   = Src.WheelSpeed_R_R_Data;
  Dest.WheelSpeed_R_R_Status                 = Src.WheelSpeed_R_R_Status;
  Dest.WheelSpeed_R_L_Data                   = Src.WheelSpeed_R_L_Data;
  Dest.WheelSpeed_R_L_Status                 = Src.WheelSpeed_R_L_Status;
  Dest.UnderVoltage                          = Src.UnderVoltage;
  Dest.OverVoltage                           = Src.OverVoltage;
  Dest.CANFailure                            = Src.CANFailure;
  Dest.Blindness                             = Src.Blindness;
  Dest.Misalignment                          = Src.Misalignment;
  Dest.InternalElectronicFailure             = Src.InternalElectronicFailure;
  Dest.IncompleteConfiguration               = Src.IncompleteConfiguration;
  Dest.AirbagCrashOrderData                  = Src.AirbagCrashOrderData;
  Dest.AirbagCrashOrderStatus                = Src.AirbagCrashOrderStatus;
  Dest.VehicleSpeedData                      = Src.VehicleSpeedData;
  Dest.VehicleSpeedStatus                    = Src.VehicleSpeedStatus;
  Dest.EraseFailure                          = Src.EraseFailure;
  Dest.AEB_DWInhibitionRequestData           = Src.AEB_DWInhibitionRequestData;
  Dest.AEB_DWInhibitionRequestStatus         = Src.AEB_DWInhibitionRequestStatus;
  Dest.AEB_FCWactivationState                = Src.AEB_FCWactivationState;
  Dest.DWActivationState_IN                  = Src.DWActivationState_IN;
  Dest.RearGearEngagedData                   = Src.RearGearEngagedData;
  Dest.RearGearEngagedStatus                   = Src.RearGearEngagedStatus;
  Dest.RearGearEngagedData                   = Src.RearGearEngagedData;
  Dest.RearGearEngagedData                   = Src.RearGearEngagedData;
  Dest.RearGearEngagedData                   = Src.RearGearEngagedData;
  Dest.SWACorrectedData                      = Src.SWACorrectedData;
  Dest.SWACorrectedStatus                    = Src.SWACorrectedStatus;
  Dest.GearLeverPositionData                 = Src.GearLeverPositionData;
  Dest.GearLeverPositionStatus               = Src.GearLeverPositionStatus;
  Dest.NeutralContactData                    = Src.NeutralContactData;
  Dest.NeutralContactStatus                  = Src.NeutralContactStatus;

  Dest.DWACCData.ACC_Status                    = Src.DWACCData.ACC_Status;
  Dest.DWACCData.StatusObject00                = Src.DWACCData.StatusObject00;
  Dest.DWACCData.DistanceObject00              = Src.DWACCData.DistanceObject00;
  Dest.DWACCData.TypeObject00                  = Src.DWACCData.TypeObject00;
  Dest.DWACCData.DynamicObject00               = Src.DWACCData.DynamicObject00;
  Dest.DWACCData.ExistenceProbabilityObject0   = Src.DWACCData.ExistenceProbabilityObject0;
}

void CConvDWInputCustom::Convert_Gen_to_V3(DWInputCustomV3::FCTDWInputCustom_t & Dest, const DWInputCustom_Gen::FCTDWInputCustom_t & Src)
{
  Dest.uiVersionNumber                  = 3u;
  Dest.DW_ActivationRequestData              = Src.DW_ActivationRequestData;
  Dest.DW_ActivationRequestStatus            = Src.DW_ActivationRequestStatus;
  Dest.GenericApplicativeDiagEnablData       = Src.GenericApplicativeDiagEnablData;
  Dest.GenericApplicativeDiagEnablStatus     = Src.GenericApplicativeDiagEnablStatus;
  Dest.WheelSpeed_F_R_Data                   = Src.WheelSpeed_F_R_Data;
  Dest.WheelSpeed_F_R_Status                 = Src.WheelSpeed_F_R_Status;
  Dest.WheelSpeed_F_L_Data                   = Src.WheelSpeed_F_L_Data;
  Dest.WheelSpeed_F_L_Status                 = Src.WheelSpeed_F_L_Status;
  Dest.WheelSpeed_R_R_Data                   = Src.WheelSpeed_R_R_Data;
  Dest.WheelSpeed_R_R_Status                 = Src.WheelSpeed_R_R_Status;
  Dest.WheelSpeed_R_L_Data                   = Src.WheelSpeed_R_L_Data;
  Dest.WheelSpeed_R_L_Status                 = Src.WheelSpeed_R_L_Status;
  Dest.UnderVoltage                          = Src.UnderVoltage;
  Dest.OverVoltage                           = Src.OverVoltage;
  Dest.CANFailure                            = Src.CANFailure;
  Dest.Blindness                             = Src.Blindness;
  Dest.Misalignment                          = Src.Misalignment;
  Dest.InternalElectronicFailure             = Src.InternalElectronicFailure;
  Dest.IncompleteConfiguration               = Src.IncompleteConfiguration;
  Dest.AirbagCrashOrderData                  = Src.AirbagCrashOrderData;
  Dest.AirbagCrashOrderStatus                = Src.AirbagCrashOrderStatus;
  Dest.VehicleSpeedData                      = Src.VehicleSpeedData;
  Dest.VehicleSpeedStatus                    = Src.VehicleSpeedStatus;
  Dest.EraseFailure                          = Src.EraseFailure;
  Dest.DWActivationState_IN                  = Src.DWActivationState_IN;
  Dest.SWACorrectedData                      = Src.SWACorrectedData;
  Dest.SWACorrectedStatus                    = Src.SWACorrectedStatus;
  Dest.YawRateRawData                        = Src.YawRateRawData;
  Dest.YawRateRawStatus                      = Src.YawRateRawStatus;
  Dest.RearWheelAnglePosData                 = Src.RearWheelAnglePosData;
  Dest.RearWheelAnglePosStatus               = Src.RearWheelAnglePosStatus;
  Dest.YawRateCorrectedData                  = Src.YawRateCorrectedData;
  Dest.YawRateCorrectedStatus                = Src.YawRateCorrectedStatus;

  Dest.DWACCData.ACC_StatusData                = Src.DWACCData.ACC_StatusData;
  Dest.DWACCData.ACC_StatusStatus              = Src.DWACCData.ACC_StatusStatus;
  Dest.DWACCData.StatusObject00                = Src.DWACCData.StatusObject00;
  Dest.DWACCData.DistanceObject00              = Src.DWACCData.DistanceObject00;
  Dest.DWACCData.TypeObject00                  = Src.DWACCData.TypeObject00;
  Dest.DWACCData.DynamicObject00               = Src.DWACCData.DynamicObject00;
  Dest.DWACCData.ExistenceProbabilityObject0   = Src.DWACCData.ExistenceProbabilityObject0;
}

long CConvDWInputCustom::ConvertData(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo, 
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo* pProvidePortVersionInfo, 
    void* pPPortData,
    void** pOutData, unsigned long& ulOutSize)
{
  long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  bool bGenBufferFilled = false;
  const uint32 uDataVer = ((pPPortData != NULL) && (ulPPortSize >= 4) && (ePPortType == simOPAQUE_t))?(*reinterpret_cast<uint32*>(pPPortData)):(0);

  // First decide which version we are converting to
  if ((eRPortType == simOPAQUE_t) && (ePPortType == simOPAQUE_t))
  {
    // If ports equal, then always compatible
    if (ulRPortSize == ulPPortSize)
    {
      lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
    }
    // First decide from which version we are converting and fill the generic buffer accordingly
    else if ((ulPPortSize == SUPPORTED_SIZE[DW_INPUT_CUSTOM_V3])
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(DW_INPUT_CUSTOM_VERSIONS[DW_INPUT_CUSTOM_V3])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION))))
    {
      // Source Port V3
      CConvDWInputCustom::InitGen(m_BufGen);
      const DWInputCustomV3::FCTDWInputCustom_t & Src = *reinterpret_cast<DWInputCustomV3::FCTDWInputCustom_t*>(pPPortData);
      Convert_V3_to_Gen(m_BufGen, Src);
      bGenBufferFilled = true;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[DW_INPUT_CUSTOM_V0])
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(DW_INPUT_CUSTOM_VERSIONS[DW_INPUT_CUSTOM_V0])) || (pProvidePortVersionInfo->Equals(DW_INPUT_CUSTOM_VERSIONS[DW_INPUT_CUSTOM_V3_1])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION))))
    {
      // Source Port V0 || V3_1
      CConvDWInputCustom::InitGen(m_BufGen);
      const DWInputCustomV0::FCTDWInputCustom_t & Src = *reinterpret_cast<DWInputCustomV0::FCTDWInputCustom_t*>(pPPortData);
      Convert_V0_to_Gen(m_BufGen, Src);
      bGenBufferFilled = true;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[DW_INPUT_CUSTOM_V0_1])
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(DW_INPUT_CUSTOM_VERSIONS[DW_INPUT_CUSTOM_V0_1])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION))))
    {
      // Source Port V0_1
      CConvDWInputCustom::InitGen(m_BufGen);
      const DWInputCustomV0_1::FCTDWInputCustom_t & Src = *reinterpret_cast<DWInputCustomV0_1::FCTDWInputCustom_t*>(pPPortData);
      Convert_V0_1_to_Gen(m_BufGen, Src);
      bGenBufferFilled = true;
    }

    if (bGenBufferFilled == true)
    {
      // Second decide to which version we are converting
      // and take the generic buffer to fill the destination buffer
      if ((ulRPortSize == SUPPORTED_SIZE[DW_INPUT_CUSTOM_V3]) && (requestPortVersionInfo.Equals(DW_INPUT_CUSTOM_VERSIONS[DW_INPUT_CUSTOM_V3])))
      {
        // Destination port of V3
        Convert_Gen_to_V3(m_DWInputCustomV3, m_BufGen);
        *pOutData = &m_DWInputCustomV3;
        ulOutSize = sizeof(m_DWInputCustomV3);
        lRet = SIM_ERR_OK;
      }
      else if ((ulRPortSize == SUPPORTED_SIZE[DW_INPUT_CUSTOM_V0]) && (requestPortVersionInfo.Equals(DW_INPUT_CUSTOM_VERSIONS[DW_INPUT_CUSTOM_V0])))
      {
        // Destination port of V0
        Convert_Gen_to_V0(m_DWInputCustomV0, m_BufGen);
        *pOutData = &m_DWInputCustomV0;
        ulOutSize = sizeof(m_DWInputCustomV0);
        lRet = SIM_ERR_OK;
      }
      else if ((ulRPortSize == SUPPORTED_SIZE[DW_INPUT_CUSTOM_V0]) && (requestPortVersionInfo.Equals(DW_INPUT_CUSTOM_VERSIONS[DW_INPUT_CUSTOM_V0])))
      {
        // Destination port of V0_1
        Convert_Gen_to_V0_1(m_DWInputCustomV0_1, m_BufGen);
        *pOutData = &m_DWInputCustomV0_1;
        ulOutSize = sizeof(m_DWInputCustomV0_1);
        lRet = SIM_ERR_OK;
      }
    }
  }
  return lRet;
}

/** returns: 
 *   SIM_ERR_OK - when this value can be used
 *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implememnted here
 *                                            and the default value from Request Port must be used
 */
long CConvDWInputCustom::GetDefaultValue(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo, 
    void** pDefaultData, unsigned long& ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == SUPPORTED_SIZE[DW_INPUT_CUSTOM_V3]) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (requestPortVersionInfo.Equals(DW_INPUT_CUSTOM_VERSIONS[DW_INPUT_CUSTOM_V3]))))
    {
      InitV3(m_DWInputCustomV3);
      *pDefaultData = &m_DWInputCustomV3;
      ulDefaultSize = sizeof(m_DWInputCustomV3);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[DW_INPUT_CUSTOM_V0]) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (requestPortVersionInfo.Equals(DW_INPUT_CUSTOM_VERSIONS[DW_INPUT_CUSTOM_V0]))))
    {
      InitV0(m_DWInputCustomV0);
      *pDefaultData = &m_DWInputCustomV0;
      ulDefaultSize = sizeof(m_DWInputCustomV0);
      lRet = SIM_ERR_OK;
    }
    else
    {
      // No conversion available
    }
  }
  return lRet;
}

// used to check if an unversioned PPort is compatible with a certain version of RPort
bool CConvDWInputCustom::IsVersionCompatibleWithType(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo, 
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize)
{
  bool bResult = false;
  // Equal ports are always compatible (at least assumed to be)
  if ((ulRPortSize == ulPPortSize) && (eRPortType == ePPortType))
  {
    bResult = true;
  }
  else
  {
    if ((eRPortType == simOPAQUE_t) && (ePPortType == simOPAQUE_t))
    {
      if ((IsPortSupported(ulRPortSize, &requestPortVersionInfo)) && (IsPortSupported(ulPPortSize, NULL)))
      {
        bResult = true;
      }
    }
  }
  return bResult;
}

// used to check if ports are compatible between different versions
bool CConvDWInputCustom::AreVersionsCompatible(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo& providePortVersionInfo)
{
  bool bResult = false;
  // If ports equal, then always compatible
  if ((eRPortType == ePPortType) && (ulRPortSize == ulPPortSize) && (requestPortVersionInfo.Equals(&providePortVersionInfo)))
  {
    bResult = true;
  }
  else
  {
    if ((eRPortType == simOPAQUE_t) && (ePPortType == simOPAQUE_t))
    {
      if ((IsPortSupported(ulRPortSize, &requestPortVersionInfo)) && (IsPortSupported(ulPPortSize, &providePortVersionInfo)))
      {
        bResult = true;
      }
    }
  }
  return bResult;
}

//
// CreateAccLeverConvClass : single externally visible function of module
//

IConverter * CreateDWInputCustomConvClass(void)
{
  return new CConvDWInputCustom();
}
