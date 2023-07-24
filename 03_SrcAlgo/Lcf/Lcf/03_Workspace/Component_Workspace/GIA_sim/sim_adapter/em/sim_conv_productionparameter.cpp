/*! \file **********************************************************************

  COMPANY:         Continental

  PROJECT:         Simulation

  COMPONENT:       sim_adapter em

  MODULNAME:       sim_conv_productionparameter.cpp

  DESCRIPTION:

  AUTHOR:          Thomas Berndt

  CREATION DATE:   27.1.2015

  VERSION:         $Revision: 1.1 $

  ---*/ /*---
  CHANGES:         $Log: sim_conv_productionparameter.cpp  $
  CHANGES:         Revision 1.1 2017/08/10 13:15:08CEST uid34177 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/em/project.pj
  CHANGES:         Revision 1.3 2015/08/28 11:30:27CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         New Version of PPars with size 13404
  CHANGES:         - Added comments -  berndtt1 [Aug 28, 2015 11:38:15 AM CEST]
  CHANGES:         Change Package : 221167:52 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:         Revision 1.2 2015/03/26 08:22:51CET Diewald, Fabian (uidt8878) 
  CHANGES:         added possibility to convert measurement with PPAR_t_ElevationAngleDeviationFar to simulator without PPAR_t_ElevationAngleDeviationFar
  CHANGES:         --- Added comments ---  uidt8878 [Mar 26, 2015 8:22:51 AM CET]
  CHANGES:         Change Package : 321658:2 http://mks-psad:7002/im/viewissue?selection=321658
  CHANGES:         Revision 1.1 2015/01/27 10:30:00CET Berndt, Thomas01 (berndtt1) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CRT_CommonRadarToolbox/04_Engineering/03_Workspace/algo/sim_adapter/em/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */

#include "sim_adapter_cfg.h"
#include "sim_conv_productionparameter.h"
#include "sim_versioninfo_impl.h"


namespace ProductionParameter_t_V2
{

  typedef signed __int16   PPAR_t_PathCompensationFarArray[24];                                    /* [Satisfies_rte sws 1189] */
  typedef unsigned __int16 PPAR_t_RxCalibrationArray[6];                                           /* [Satisfies_rte sws 1189] */
  typedef unsigned __int16 PPAR_t_RxGainsFarArray[6];                                              /* [Satisfies_rte sws 1189] */
  typedef signed __int16   PPAR_t_AngleDeviationFarArray[441];                                     /* [Satisfies_rte sws 1189] */
  typedef unsigned __int8  PPAR_t_DecayTargetNormSFarAzimuthArray[441];                            /* [Satisfies_rte sws 1189] */
  typedef unsigned __int16 PPAR_t_StcFrequency6dBDecayFarArray[6];                                 /* [Satisfies_rte sws 1189] */
  typedef unsigned __int8  PPAR_t_DecayTargetNormSFarElevationArray[161];                          /* [Satisfies_rte sws 1189] */
  typedef signed __int16   PPAR_t_RxControllableGainArray[5];                                      /* [Satisfies_rte sws 1189] */
  typedef unsigned __int8  PPAR_t_AntennaFarReservedArray[10];                                     /* [Satisfies_rte sws 1189] */

  typedef struct                                                                                   /* [Satisfies_rte sws 1191] */
  {
    PPAR_t_PathCompensationFarArray a_PathCompensationFar;
    PPAR_t_RxCalibrationArray a_RxCalibrationFar;
    unsigned __int8 u_VgaTx1Far;
    unsigned __int8 u_VgaTx2Far;
    unsigned __int16 u_Alignment;
    unsigned __int16 u_PowerSenseTx1Far;
    unsigned __int16 u_PowerSenseTx2Far;
    unsigned __int16 u_PowerSenseLO1Far;
    unsigned __int16 u_PowerSenseLO2Far;
    PPAR_t_RxGainsFarArray a_RxGainsFar;
    signed __int16 s_BoresightFarAzimuth;
    signed __int16 s_BoresightFarElevation;
    PPAR_t_AngleDeviationFarArray a_AngleDeviationFar;
    signed __int16 s_MaxTargetNormSFar;
    PPAR_t_DecayTargetNormSFarAzimuthArray a_DecayTargetNormSFarAzimuth;
    PPAR_t_DecayTargetNormSFarElevationArray a_DecayTargetNormSFarElevation;
    unsigned __int16 u_MaxTargetNormSNFar;
    PPAR_t_StcFrequency6dBDecayFarArray a_StcFrequency6dBDecayFar;
    unsigned __int16 u_StcAttenuationForBptFar;
    unsigned __int16 u_FrequencyForBeamPatternFar;
    PPAR_t_RxControllableGainArray a_RxControllableGainFar;
    PPAR_t_AntennaFarReservedArray a_Alignment1;
  } PPAR_t_AntennaParamsFar;

  typedef signed __int16   PPAR_t_AngleDeviationNearArray[721];                                    /* [Satisfies_rte sws 1189] */
  typedef unsigned __int16 PPAR_t_RxGainsNearArray[6];                                             /* [Satisfies_rte sws 1189] */
  typedef signed __int16   PPAR_t_PathCompensationNearArray[24];                                   /* [Satisfies_rte sws 1189] */
  typedef unsigned __int8  PPAR_t_DecayTargetNormSNearAzimuthArray[721];                           /* [Satisfies_rte sws 1189] */
  typedef unsigned __int8  PPAR_t_DecayTargetNormSNearElevationArray[161];                         /* [Satisfies_rte sws 1189] */
  typedef unsigned __int16 PPAR_t_StcFrequency6dBDecayNearArray[6];                                /* [Satisfies_rte sws 1189] */

  typedef struct                                                                                   /* [Satisfies_rte sws 1191] */
  {
    PPAR_t_PathCompensationNearArray a_PathCompensationNear;
    PPAR_t_RxCalibrationArray a_RxCalibrationNear;
    unsigned __int8 u_VgaTx1Near;
    unsigned __int8 u_VgaTx2Near;
    unsigned __int16 u_Alignment;
    unsigned __int16 u_PowerSenseTx1Near;
    unsigned __int16 u_PowerSenseTx2Near;
    unsigned __int16 u_PowerSenseLO1Near;
    unsigned __int16 u_PowerSenseLO2Near;
    PPAR_t_RxGainsNearArray a_RxGainsNear;
    signed __int16 s_BoresightNearAzimuth;
    signed __int16 s_BoresightNearElevation;
    PPAR_t_AngleDeviationNearArray a_AngleDeviationNear;
    signed __int16 s_MaxTargetNormSNear;
    PPAR_t_DecayTargetNormSNearAzimuthArray a_DecayTargetNormSNearAzimuth;
    PPAR_t_DecayTargetNormSNearElevationArray a_DecayTargetNormSNearElevation;
    unsigned __int16 u_MaxTargetNormSNNear;
    PPAR_t_StcFrequency6dBDecayNearArray a_StcFrequency6dBDecayNear;
    unsigned __int16 u_StcAttenuationForBptNear;
    unsigned __int16 u_FrequencyForBeamPatternNear;
    PPAR_t_RxControllableGainArray a_RxControllableGainNear;
    unsigned __int16 u_Alignment1;
  } PPAR_t_AntennaParamsNear;

  typedef struct                                                                                   /* [Satisfies_rte sws 1191] */
  {
    PPAR_t_AntennaParamsFar AntennaParamsFar;
    PPAR_t_AntennaParamsNear AntennaParamsNear;
  } AntennaPar_BaseType_t;

  typedef unsigned __int16 PPAR_t_TempSensorValuesArray[11];                                       /* [Satisfies_rte sws 1189] */

  typedef struct                                                                                   /* [Satisfies_rte sws 1191] */
  {
    unsigned __int8 u_VcoDacCoarse;
    unsigned __int8 u_VcoVTuneGain;
    unsigned __int16 u_VcoDacFineUpper;
    unsigned __int16 u_VcoDacFineLower;
    PPAR_t_TempSensorValuesArray a_TempSensorValues;
    signed __int16 s_GyroOffset;
    signed __int16 s_GyroTempDiff;
  } PPAR_t_VCOandGyroParams;

  typedef unsigned __int8 PPAR_t_Reserved1Array[492];                                              /* [Satisfies_rte sws 1189] */

  typedef unsigned __int8 PPAR_t_CustomerHardwareNumberArray[32];                                  /* [Satisfies_rte sws 1189] */

  typedef unsigned __int8 PPAR_t_SerialNumberArray[26];                                            /* [Satisfies_rte sws 1189] */

  typedef unsigned __int8 PPAR_t_HwSampAdaptInfReserved1Array[2];                                  /* [Satisfies_rte sws 1189] */
  typedef unsigned __int8 PPAR_t_HwSampAdaptInfReserved2array[15];                                 /* [Satisfies_rte sws 1189] */

  typedef struct                                                                                   /* [Satisfies_rte sws 1191] */
  {
    unsigned __int32 u_HwAddiCompaDatInitTag;
    unsigned __int8 u_HwAdaptCompatIndex;
    unsigned __int8 u_HwVersionChangeIndex;
    PPAR_t_HwSampAdaptInfReserved1Array a_HwSampAdaptInfReserved1;
    unsigned __int8 u_InterfaceVers;
    PPAR_t_HwSampAdaptInfReserved2array a_HwSampAdaptInfReserved2;
  } PPAR_t_HwSampAdaptInf;

  typedef unsigned __int8 PPAR_t_HilReservedArray[16];                                                                                                 /* [Satisfies_rte sws 1189] */

  typedef struct                                                                                               /* [Satisfies_rte sws 1191] */
  {
    unsigned __int32 u_HilHardware;
    PPAR_t_HilReservedArray a_HilReserved;
  } PPAR_t_HilData;

  typedef unsigned __int8 PPAR_t_MACAddressArray[6];                                                                                                 /* [Satisfies_rte sws 1189] */
  typedef unsigned __int8 PPAR_t_EthernetReservedArray1[10];                                                                                              /* [Satisfies_rte sws 1189] */
  typedef unsigned __int8 PPAR_t_EthernetReserved2Array[12];                                                                                              /* [Satisfies_rte sws 1189] */

  typedef struct                                                                                               /* [Satisfies_rte sws 1191] */
  {
    PPAR_t_MACAddressArray a_MACAddress;
    PPAR_t_EthernetReservedArray1 a_EthernetReserved1;
    unsigned __int32 u_StaticIpAddress;
    PPAR_t_EthernetReserved2Array a_EthernetReserved2;
  } PPAR_t_EthernetParameters;

  typedef unsigned __int8 PPAR_t_ManufactureProductionLineCode[3];                                                                                              /* [Satisfies_rte sws 1189] */
  typedef unsigned __int8 PPAR_t_ManufactureCode[3];                                                                                                 /* [Satisfies_rte sws 1189] */
  typedef unsigned __int8 PPAR_t_ManufacturingDate[8];                                                                                               /* [Satisfies_rte sws 1189] */
  typedef unsigned __int8 PPAR_t_ManufactureTestBedNo[4];                                                                                              /* [Satisfies_rte sws 1189] */
  typedef unsigned __int8 PPAR_t_ConsecutiveManufactureNo[4];                                                                                              /* [Satisfies_rte sws 1189] */

  typedef struct                                                                                               /* [Satisfies_rte sws 1191] */
  {
    PPAR_t_ManufactureProductionLineCode u_ManufactureProductionLineCode;
    unsigned __int8 u_Hyphen;
    PPAR_t_ManufactureCode u_ManufactureCode;
    PPAR_t_ManufacturingDate u_ManufacturingDate;
    PPAR_t_ManufactureTestBedNo u_ManufactureTestBedNo;
    PPAR_t_ConsecutiveManufactureNo u_ConsecutiveManufactureNo;
  } PPAR_t_FazitIdentString;

  typedef unsigned __int8 PPAR_t_VWECUHardwareNumber[11];                                                                                              /* [Satisfies_rte sws 1189] */
  typedef unsigned __int8 PPAR_t_VWECUHardwareVersionNumber[3];                                                                                              /* [Satisfies_rte sws 1189] */
  typedef unsigned __int8 Ks_AesBufferType[16];                                                                                                        /* [Satisfies_rte sws 1189] */
  typedef Ks_AesBufferType PPAR_t_KsStartKey[1];                                                                                                      /* [Satisfies_rte sws 1189] */
  typedef Ks_AesBufferType PPAR_t_KsECEncMISC[1];                                                                                                     /* [Satisfies_rte sws 1189] */
  typedef Ks_AesBufferType PPAR_t_KsGfaKey[1];                                                                                                        /* [Satisfies_rte sws 1189] */
  typedef Ks_AesBufferType PPAR_t_KsMasterKey[1];                                                                                                     /* [Satisfies_rte sws 1189] */
  typedef unsigned __int8                     	PPAR_t_OemSwReservedBlockArray[923];                                                                                              /* [Satisfies_rte sws 1189] */

  typedef struct                                                                                               /* [Satisfies_rte sws 1191] */
  {
    PPAR_t_KsMasterKey a_MasterKey;
    PPAR_t_KsStartKey a_StartKey;
    PPAR_t_KsECEncMISC a_ECEncMISC;
    PPAR_t_KsGfaKey a_GfaKey;
  } PPAR_t_KsKeys;

  typedef struct                                                                                               /* [Satisfies_rte sws 1191] */
  {
    PPAR_t_FazitIdentString FazitIdentString;
    PPAR_t_VWECUHardwareNumber a_VWECUHardwareNumber;
    PPAR_t_VWECUHardwareVersionNumber a_VWECUHardwareVersionNumber;
    PPAR_t_KsKeys Ks;
    PPAR_t_OemSwReservedBlockArray a_OemSwReservedBlock;
  } PPAR_t_OemSwBlock;

  typedef signed __int16 PPAR_t_MeasAngleNearMPArray[721];                                                                                              /* [Satisfies_rte sws 1189] */

  typedef signed __int8 PPAR_t_ComplexIQValuesNearArray[2088];                                                                                              /* [Satisfies_rte sws 1189] */

  typedef signed __int8 PPAR_t_ComplexIQValuesFarArray[1080];                                                                                              /* [Satisfies_rte sws 1189] */

  typedef struct                                                                                               /* [Satisfies_rte sws 1191] */
  {
    AntennaPar_BaseType_t AntennaPar_Base;
    PPAR_t_VCOandGyroParams VCOandGyroParams;
    PPAR_t_Reserved1Array a_ProdParamsReservedArray;
    PPAR_t_CustomerHardwareNumberArray a_CustomerHardwareNumber;
    PPAR_t_SerialNumberArray a_TemicSerialNumber;
    unsigned __int16 u_Alignment;
    PPAR_t_HwSampAdaptInf HwSampAdaptInf;
    PPAR_t_HilData HilData;
    PPAR_t_EthernetParameters EthernetParameters;
    PPAR_t_OemSwBlock OemSwBlock;
    PPAR_t_AngleDeviationNearArray a_MeasAngleNearBF;
    PPAR_t_MeasAngleNearMPArray a_MeasAngleNearMP;
    PPAR_t_ComplexIQValuesNearArray a_ComplexIQValuesNear;
    PPAR_t_AngleDeviationFarArray a_MeasAngleFarBF;
    PPAR_t_ComplexIQValuesFarArray a_ComplexIQValuesFar;
    PPAR_t_DecayTargetNormSNearAzimuthArray a_DecayTargetNormSFarAzimuth;
    unsigned __int8 Psw_VgaTx1Far;
    unsigned __int8 Psw_VgaTx2Far;
    unsigned __int8 Psw_VgaTx1Near;
    unsigned __int8 Psw_VgaTx2Near;
    unsigned __int8 RxGainSettings;
  } ProductionParameter_t;
} // end of ProductionParameter_t_V2


namespace ProductionParameter_t_V2_2
{
  typedef struct                                                                                               /* [Satisfies_rte sws 1191] */
  {
    ProductionParameter_t_V2::AntennaPar_BaseType_t AntennaPar_Base;
    ProductionParameter_t_V2::PPAR_t_VCOandGyroParams VCOandGyroParams;
    ProductionParameter_t_V2::PPAR_t_Reserved1Array a_ProdParamsReservedArray;
    ProductionParameter_t_V2::PPAR_t_CustomerHardwareNumberArray a_CustomerHardwareNumber;
    ProductionParameter_t_V2::PPAR_t_SerialNumberArray a_TemicSerialNumber;
    unsigned __int16 u_Alignment;
    ProductionParameter_t_V2::PPAR_t_HwSampAdaptInf HwSampAdaptInf;
    ProductionParameter_t_V2::PPAR_t_HilData HilData;
    ProductionParameter_t_V2::PPAR_t_EthernetParameters EthernetParameters;
    ProductionParameter_t_V2::PPAR_t_OemSwBlock OemSwBlock;
    ProductionParameter_t_V2::PPAR_t_AngleDeviationNearArray a_MeasAngleNearBF;
    ProductionParameter_t_V2::PPAR_t_MeasAngleNearMPArray a_MeasAngleNearMP;
    ProductionParameter_t_V2::PPAR_t_ComplexIQValuesNearArray a_ComplexIQValuesNear;
    ProductionParameter_t_V2::PPAR_t_AngleDeviationFarArray a_MeasAngleFarBF;
    ProductionParameter_t_V2::PPAR_t_ComplexIQValuesFarArray a_ComplexIQValuesFar;
    ProductionParameter_t_V2::PPAR_t_DecayTargetNormSNearAzimuthArray a_DecayTargetNormSFarAzimuth;
    unsigned __int8 Psw_VgaTx1Far;
    unsigned __int8 Psw_VgaTx2Far;
    unsigned __int8 Psw_VgaTx1Near;
    unsigned __int8 Psw_VgaTx2Near;
    unsigned __int8 RxGainSettings;
    signed __int16 s_MsbTransDipAreaInLSBns;
  } ProductionParameter_t;
} // end of ProductionParameter_t_V2_2



namespace ProductionParameter_t_V3
{
  typedef signed __int16 PPAR_t_ElevationAngleDeviationFar[41];                                                                                              /* [Satisfies_rte sws 1189] */

  typedef struct                                                                                               /* [Satisfies_rte sws 1191] */
  {
    ProductionParameter_t_V2::AntennaPar_BaseType_t AntennaPar_Base;
    ProductionParameter_t_V2::PPAR_t_VCOandGyroParams VCOandGyroParams;
    ProductionParameter_t_V2::PPAR_t_Reserved1Array a_ProdParamsReservedArray;
    ProductionParameter_t_V2::PPAR_t_CustomerHardwareNumberArray a_CustomerHardwareNumber;
    ProductionParameter_t_V2::PPAR_t_SerialNumberArray a_TemicSerialNumber;
    unsigned __int16 u_Alignment;
    ProductionParameter_t_V2::PPAR_t_HwSampAdaptInf HwSampAdaptInf;
    ProductionParameter_t_V2::PPAR_t_HilData HilData;
    ProductionParameter_t_V2::PPAR_t_EthernetParameters EthernetParameters;
    ProductionParameter_t_V2::PPAR_t_OemSwBlock OemSwBlock;
    ProductionParameter_t_V2::PPAR_t_AngleDeviationNearArray a_MeasAngleNearBF;
    ProductionParameter_t_V2::PPAR_t_MeasAngleNearMPArray a_MeasAngleNearMP;
    ProductionParameter_t_V2::PPAR_t_ComplexIQValuesNearArray a_ComplexIQValuesNear;
    ProductionParameter_t_V2::PPAR_t_AngleDeviationFarArray a_MeasAngleFarBF;
    ProductionParameter_t_V2::PPAR_t_ComplexIQValuesFarArray a_ComplexIQValuesFar;
    ProductionParameter_t_V2::PPAR_t_DecayTargetNormSNearAzimuthArray a_DecayTargetNormSFarAzimuth;
    unsigned __int8 Psw_VgaTx1Far;
    unsigned __int8 Psw_VgaTx2Far;
    unsigned __int8 Psw_VgaTx1Near;
    unsigned __int8 Psw_VgaTx2Near;
    unsigned __int8 RxGainSettings;
    PPAR_t_ElevationAngleDeviationFar a_ElevationAngleDeviationFar;
    signed __int16 s_MsbTransDipAreaInLSBns;
  } ProductionParameter_t;
} // end of ProductionParameter_t_V3


class CConvProductionparameter : public CSimConverterBase
{
  // the list of dependency names used inside by the converter
  /*
  static const char *DEP_NAMES[];
  */

  // here we define the index of each dependency for quick acces
  // the order here should match with the order from DEP_NAMES array
  enum eDepIdx
  {
    // add new dependencies here
    DEP_COUNT
  };

  ProductionParameter_t_V2::ProductionParameter_t m_BufV2;
  ProductionParameter_t_V2_2::ProductionParameter_t m_BufV2_2;
  ProductionParameter_t_V3::ProductionParameter_t m_BufV3;

  // Initialization
  template <typename T> static void InitVx (T & Dest)
  {
    ::memset(&Dest, 0, sizeof(Dest));
  }

public:

  static const char *GetConverterTypeName()
  {
    return "Production_Par";
  }

  CConvProductionparameter(void);
  virtual ~CConvProductionparameter(void);

  const char *GetTypeName()
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
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo *pProvidePortVersionInfo,
    void *pPPortData,
    void **pOutData, unsigned long &ulOutSize);

  /** returns:
   *   SIM_ERR_OK - when this value can be used
   *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implemented here
   *                                            and the default value from Request Port must be used
   */
  long GetDefaultValue(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
    void **pDefaultData, unsigned long &ulDefaultSize);

protected:

  // used to check if an unversioned PPort is compatible with a certain version of RPort
  bool IsVersionCompatibleWithType(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize);

  // used to check if ports are compatible between different versions
  bool AreVersionsCompatible(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo &providePortVersionInfo);

private:
  enum EM_ObjectList_Cam
  {
    PRODUCTIONPARAMETER_T_V2,
    PRODUCTIONPARAMETER_T_V2_2,
    PRODUCTIONPARAMETER_T_V3,
    PRODUCTIONPARAMETER_VERSION_COUNT
  };

  static CVersionInfoImpl BASE_VERSION;
  static CVersionInfoImpl VERSION1;
  static const CVersionInfoImpl * const EM_OBJECTLIST_CAM_INPUT_VERSIONS[PRODUCTIONPARAMETER_VERSION_COUNT];

  static const unsigned long SUPPORTED_SIZE[PRODUCTIONPARAMETER_VERSION_COUNT];

  bool IsPortSupported(unsigned long ulPortSize, const IVersionInfo *pPortVersion) const
  {
    for (int nI = 0; nI < PRODUCTIONPARAMETER_VERSION_COUNT; nI++)
    {
      if ((pPortVersion == NULL) || pPortVersion->Equals(EM_OBJECTLIST_CAM_INPUT_VERSIONS[nI]))
      {
        if (ulPortSize == SUPPORTED_SIZE[nI])
        {
          return true;
        }
      }
    };
    return false;
  };
};

CVersionInfoImpl CConvProductionparameter::BASE_VERSION(0, 0, 0);
CVersionInfoImpl CConvProductionparameter::VERSION1    (0, 0, 1);

const CVersionInfoImpl * const CConvProductionparameter::EM_OBJECTLIST_CAM_INPUT_VERSIONS[CConvProductionparameter::PRODUCTIONPARAMETER_VERSION_COUNT] =
{
  &BASE_VERSION,
  &BASE_VERSION,
  &BASE_VERSION
};

const unsigned long CConvProductionparameter::SUPPORTED_SIZE[CConvProductionparameter::PRODUCTIONPARAMETER_VERSION_COUNT] =
{
  sizeof(ProductionParameter_t_V2::ProductionParameter_t),
  sizeof(ProductionParameter_t_V2_2::ProductionParameter_t),
  sizeof(ProductionParameter_t_V3::ProductionParameter_t),
};

__inline void v_Convert_v2_to_v3 (ProductionParameter_t_V3::ProductionParameter_t * const pDest,
  const ProductionParameter_t_V2::ProductionParameter_t * const pSrc)
{
  memcpy(pDest, pSrc, sizeof (*pSrc));
  ::memset(pDest->a_ElevationAngleDeviationFar, 0, sizeof(pDest->a_ElevationAngleDeviationFar));
  pDest->s_MsbTransDipAreaInLSBns = 0;
}

__inline void v_Convert_v3_to_v2 (ProductionParameter_t_V2::ProductionParameter_t * const pDest,
  const ProductionParameter_t_V3::ProductionParameter_t * const pSrc)
{
  memcpy(pDest, pSrc, sizeof (*pDest));
}

__inline void v_Convert_v2_to_v2_2 (ProductionParameter_t_V2_2::ProductionParameter_t * const pDest,
  const ProductionParameter_t_V2::ProductionParameter_t * const pSrc)
{
  memcpy(pDest, pSrc, sizeof (*pSrc));
  pDest->s_MsbTransDipAreaInLSBns = 0;
}

__inline void v_Convert_v2_2_to_v2 (ProductionParameter_t_V2::ProductionParameter_t * const pDest,
  const ProductionParameter_t_V2_2::ProductionParameter_t * const pSrc)
{
  memcpy(pDest, pSrc, sizeof (*pDest));
}

__inline void v_Convert_v2_2_to_v3 (ProductionParameter_t_V3::ProductionParameter_t * const pDest,
  const ProductionParameter_t_V2_2::ProductionParameter_t * const pSrc)
{
  ::memset(pDest->a_ElevationAngleDeviationFar, 0, sizeof(pDest->a_ElevationAngleDeviationFar));
  memcpy(pDest, pSrc, sizeof (*pSrc));
}

__inline void v_Convert_v3_to_v2_2 (ProductionParameter_t_V2_2::ProductionParameter_t * const pDest,
  const ProductionParameter_t_V3::ProductionParameter_t * const pSrc)
{
  memcpy(pDest, pSrc, sizeof (*pDest));
}

CConvProductionparameter::CConvProductionparameter(void) : CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT), m_BufV2(), m_BufV2_2(), m_BufV3()
{
  InitVx(m_BufV2);
  InitVx(m_BufV2_2);
  InitVx(m_BufV3);
}

CConvProductionparameter::~CConvProductionparameter(void)
{
}

long CConvProductionparameter::ConvertData(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo *pProvidePortVersionInfo,
  void *pPPortData,
  void **pOutData, unsigned long &ulOutSize)
{
  long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  //const unsigned int uDataVer = ((pPPortData != NULL) && (ulPPortSize >= 4) && (ePPortType == simOPAQUE_t))?(*reinterpret_cast<unsigned int*>(pPPortData)):(0);

  if (eRPortType == ePPortType)
  {
    if ((ulRPortSize == ulPPortSize) && ((pProvidePortVersionInfo == NULL) || requestPortVersionInfo.Equals(pProvidePortVersionInfo)))
    {
      // Use data directly from provide port
      lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
    }
    else
    {
      // First decide which version we are converting from
      if ((ulPPortSize == SUPPORTED_SIZE[PRODUCTIONPARAMETER_T_V2]) &&
        ((pProvidePortVersionInfo == NULL) || pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      {
        const ProductionParameter_t_V2::ProductionParameter_t *pSrc = reinterpret_cast<ProductionParameter_t_V2::ProductionParameter_t *>(pPPortData);
        // The decide which version we are converting to
        if ((ulRPortSize == SUPPORTED_SIZE[PRODUCTIONPARAMETER_T_V3]) &&
          (requestPortVersionInfo.Equals(&VERSION1) ||
          requestPortVersionInfo.Equals(&BASE_VERSION)))
        {
          // Destination port of V3 is m_BufV3
          v_Convert_v2_to_v3(&m_BufV3, pSrc);
          *pOutData = &m_BufV3;
          ulOutSize = sizeof(m_BufV3);
          lRet = SIM_ERR_OK;
        }
        else if ((ulRPortSize == SUPPORTED_SIZE[PRODUCTIONPARAMETER_T_V2_2]) &&
          (requestPortVersionInfo.Equals(&VERSION1) ||
          requestPortVersionInfo.Equals(&BASE_VERSION)))
        {
          // Destination port of V2_2 is m_BufV2_2
          v_Convert_v2_to_v2_2(&m_BufV2_2, pSrc);
          *pOutData = &m_BufV2_2;
          ulOutSize = sizeof(m_BufV2_2);
          lRet = SIM_ERR_OK;
        }
      }
      else if ((ulPPortSize == SUPPORTED_SIZE[PRODUCTIONPARAMETER_T_V2_2]) &&
        ((pProvidePortVersionInfo == NULL) || pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      {
        const ProductionParameter_t_V2_2::ProductionParameter_t *pSrc = reinterpret_cast<ProductionParameter_t_V2_2::ProductionParameter_t *>(pPPortData);
        // The decide which version we are converting to
        if ((ulRPortSize == SUPPORTED_SIZE[PRODUCTIONPARAMETER_T_V3]) &&
          (requestPortVersionInfo.Equals(&VERSION1) ||
          requestPortVersionInfo.Equals(&BASE_VERSION)))
        {
          // Destination port of V3 is m_BufV3
          v_Convert_v2_2_to_v3(&m_BufV3, pSrc);
          *pOutData = &m_BufV3;
          ulOutSize = sizeof(m_BufV3);
          lRet = SIM_ERR_OK;
        }
        else if ((ulRPortSize == SUPPORTED_SIZE[PRODUCTIONPARAMETER_T_V2]) &&
          (requestPortVersionInfo.Equals(&VERSION1) ||
          requestPortVersionInfo.Equals(&BASE_VERSION)))
        {
          // Destination port of V2 is m_BufV2
          v_Convert_v2_2_to_v2(&m_BufV2, pSrc);
          *pOutData = &m_BufV2;
          ulOutSize = sizeof(m_BufV2);
          lRet = SIM_ERR_OK;
        }
      }
      else if ((ulPPortSize == SUPPORTED_SIZE[PRODUCTIONPARAMETER_T_V3]) &&
        ((pProvidePortVersionInfo == NULL) || pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      {
        const ProductionParameter_t_V3::ProductionParameter_t *pSrc = reinterpret_cast<ProductionParameter_t_V3::ProductionParameter_t *>(pPPortData);
        // The decide which version we are converting to
        if ((ulRPortSize == SUPPORTED_SIZE[PRODUCTIONPARAMETER_T_V2_2]) &&
          (requestPortVersionInfo.Equals(&VERSION1) ||
          requestPortVersionInfo.Equals(&BASE_VERSION)))
        {
          // Destination port of V2_2 is m_BufV2_2
          v_Convert_v3_to_v2_2(&m_BufV2_2, pSrc);
          *pOutData = &m_BufV2_2;
          ulOutSize = sizeof(m_BufV2_2);
          lRet = SIM_ERR_OK;
        }
        else if ((ulRPortSize == SUPPORTED_SIZE[PRODUCTIONPARAMETER_T_V2]) &&
          (requestPortVersionInfo.Equals(&VERSION1) ||
          requestPortVersionInfo.Equals(&BASE_VERSION)))
        {
          // Destination port of V2 is m_BufV2
          v_Convert_v3_to_v2(&m_BufV2, pSrc);
          *pOutData = &m_BufV2;
          ulOutSize = sizeof(m_BufV2);
          lRet = SIM_ERR_OK;
        }
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
long CConvProductionparameter::GetDefaultValue(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  void **pDefaultData, unsigned long &ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == SUPPORTED_SIZE[PRODUCTIONPARAMETER_T_V3]) && (BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION1.Equals(&requestPortVersionInfo)))
    {
      InitVx(m_BufV3);
      *pDefaultData = &m_BufV3;
      ulDefaultSize = sizeof(ProductionParameter_t_V3::ProductionParameter_t);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[PRODUCTIONPARAMETER_T_V2_2]) && BASE_VERSION.Equals(&requestPortVersionInfo))
    {
      InitVx(m_BufV2_2);
      *pDefaultData = &m_BufV2_2;
      ulDefaultSize = sizeof(ProductionParameter_t_V2_2::ProductionParameter_t);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[PRODUCTIONPARAMETER_T_V2]) && BASE_VERSION.Equals(&requestPortVersionInfo))
    {
      InitVx(m_BufV2);
      *pDefaultData = &m_BufV2;
      ulDefaultSize = sizeof(ProductionParameter_t_V2::ProductionParameter_t);
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
bool CConvProductionparameter::IsVersionCompatibleWithType(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize)
{
  bool bResult = false;
  // Equal ports are always compatible (at least assumed to be)
  if ((ulRPortSize == ulPPortSize) && (eRPortType == ePPortType))
  {
    bResult = true;
  }
  else if ((eRPortType == simOPAQUE_t) && (ePPortType == simOPAQUE_t))
  {
    if ((IsPortSupported(ulRPortSize, &requestPortVersionInfo)) && (IsPortSupported(ulPPortSize, NULL)))
    {
      bResult = true;
    }
  }
  return bResult;
}

// used to check if ports are compatible between different versions
bool CConvProductionparameter::AreVersionsCompatible(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo &providePortVersionInfo)
{
  bool bResult = false;
  // Equal ports are always compatible (at least assumed to be)
  if ((ulRPortSize == ulPPortSize) && (eRPortType == ePPortType))
  {
    bResult = true;
  }
  else if ((eRPortType == simOPAQUE_t) && (ePPortType == simOPAQUE_t))
  {
    if ((IsPortSupported(ulRPortSize, &requestPortVersionInfo)) && (IsPortSupported(ulPPortSize, &providePortVersionInfo)))
    {
      bResult = true;
    }
  }
  return bResult;
}

//
// Main factory class returning conversion class
//
IConverter * CreateProductionparameterConvClass(void)
{
  return new CConvProductionparameter();
}
