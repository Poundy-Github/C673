/*! \file **********************************************************************

  COMPANY:         Continental

  PROJECT:         Simulation

  COMPONENT:       sim_adapter em

  MODULNAME:       sim_conv_em_bswemctrldata

  DESCRIPTION:

  AUTHOR:          Thomas Berndt

  CREATION DATE:   27.08.2013

  VERSION:         $Revision: 1.1 $

  ---*/ /*---
  CHANGES:         $Log: sim_conv_em_bswemctrldata.cpp  $
  CHANGES:         Revision 1.1 2017/08/10 13:15:02CEST uid34177 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/em/project.pj
  CHANGES:         Revision 1.8 2016/09/29 14:55:50CEST Cretu, Teodora (CretuT) 
  CHANGES:         Add Version V4, the same as V3
  CHANGES:         Revision 1.7 2016/08/10 14:35:27CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         + Version V4 for ARS510
  CHANGES:         Revision 1.6 2016/08/09 13:24:03CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         Intermediate V100
  CHANGES:         Revision 1.5 2016/05/09 14:26:20CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         * Corrected version number
  CHANGES:         Revision 1.4 2016/05/03 14:56:04CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         * switch HWSample to unsigned short
  CHANGES:         # Get HWSample through dependency
  CHANGES:         Revision 1.3 2016/04/27 07:20:40CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         * added V3 (HWSample)
  CHANGES:         * using generic structure
  CHANGES:         Revision 1.2 2013/12/11 12:11:23CET Berndt, Thomas01 (berndtt1) 
  CHANGES:         New version with -> unsigned long u_VersionNumber;
  CHANGES:         - Added comments -  berndtt1 [Dec 12, 2013 10:04:03 AM CET]
  CHANGES:         Change Package : 208935:2 http://mks-psad:7002/im/viewissue?selection=208935
  CHANGES:         Revision 1.1 2013/09/02 12:43:42CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CRT_CommonRadarToolbox/04_Engineering/03_Workspace/algo/sim_adapter/em/project.pj

**************************************************************************** */

/* includes ---------------------------------------------------------------- */
#include <atlbase.h>                             // ATL includes
#include "sim_conv_em_bswemctrldata.h"
#include "sim_versioninfo_impl.h"

typedef float float32;
typedef unsigned __int8 boolean, uint8;
typedef unsigned __int32 uint32;

/* typedef EMOpMode_t */
#ifndef EM_MOD_STARTUP
  #define EM_MOD_STARTUP (0U)
#endif
#ifndef EM_MOD_INIT
  #define EM_MOD_INIT (4U)
#endif

/* typedef AlgoSignalState_t */
#ifndef AL_SIG_STATE_INIT
  #define AL_SIG_STATE_INIT (0U)
#endif
#ifndef AL_SIG_STATE_OK
  #define AL_SIG_STATE_OK (1U)
#endif
#ifndef AL_SIG_STATE_INVALID
  #define AL_SIG_STATE_INVALID (2U)
#endif


// ARS4xx EM_BSW_EMCtrlData_V1 version 0         Length = 3
namespace EM_BSW_EMCtrlData_V0
{
  typedef unsigned char EMOpMode_t               /* @min: 0 @max:18 @values: enum { EM_MOD_HIDDEN_NEXT_VEH=8,EM_MOD_BRIDGEDETECT=9,EM_MOD_LIMITED_RANGE=11,EM_MOD_STARTUP=0,EM_MOD_INTERFERENCE=15,EM_MOD_FUNCTION_TEST=18,EM_MOD_MONITORING_INPUT_ACC=13,EM_MOD_END_OF_LINE=6,EM_MOD_REENGAGE=10,EM_MOD_SELFTEST=12,EM_MOD_SERVICEALIGNMENT=3,EM_MOD_INIT=4,EM_MOD_INVALID_INPUT_SIGNALS=14,EM_MOD_RUNNING=1,EM_MOD_WORKSHOP=5,EM_MOD_BLOCKAGE_TEST=16,EM_MOD_BLOCKAGE_TEST_RB=17,EM_MOD_BLOCKAGE_EVAL=7,EM_MOD_SOFTWARECYCLE=2,} */  /* [Satisfies_rte sws 1188] */;

  typedef struct BSW_s_EMCtrlData_t              /* [Satisfies_rte sws 1191] */
  {
    EMOpMode_t EMOpMode;
    boolean RSPCycleViolation;
    boolean EMCycleViolation;
  } BSW_s_EMCtrlData_t;                          /* @vaddr:0x20100200 @vaddr_defs: EM_MEAS_ID_CTRLDATA @cycleid:EM_ENV @vname:BSW_EMCtrlData */
}

// ARS4xx EM_BSW_EMCtrlData_V1 version 1         Length = 16
namespace EM_BSW_EMCtrlData_V1
{
  typedef unsigned long AlgoDataTimeStamp_t      /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */  /* [Satisfies_rte sws 1188] */;
  typedef unsigned short AlgoCycleCounter_t      /* Algo cycle counter @min:0 @max:65535 */  /* [Satisfies_rte sws 1188] */;
  typedef unsigned char AlgoSignalState_t        /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */  /* [Satisfies_rte sws 1188] */;

  typedef struct SignalHeader_t                  /* [Satisfies_rte sws 1191] */
  {
    AlgoDataTimeStamp_t uiTimeStamp;
    AlgoCycleCounter_t uiMeasurementCounter;
    AlgoCycleCounter_t uiCycleCounter;
    AlgoSignalState_t eSigStatus;
  } SignalHeader_t;                              /* Common header for all structured data types */

  typedef struct BSW_s_EMCtrlData_t              /* [Satisfies_rte sws 1191] */
  {
    SignalHeader_t sSigHeader;
    EM_BSW_EMCtrlData_V0::EMOpMode_t EMOpMode;
    boolean RSPCycleViolation;
    boolean EMCycleViolation;
  } BSW_s_EMCtrlData_t;                          /* @vaddr:0x20100200 @vaddr_defs: EM_MEAS_ID_CTRLDATA @cycleid:EM_ENV @vname:BSW_EMCtrlData */
}

// ARS4xx EM_BSW_EMCtrlData_V2 version 2         Length = 20
namespace EM_BSW_EMCtrlData_V2
{

  typedef struct BSW_s_EMCtrlData_t              /* [Satisfies_rte sws 1191] */
  {
    unsigned long u_VersionNumber;
    EM_BSW_EMCtrlData_V1::SignalHeader_t sSigHeader;
    EM_BSW_EMCtrlData_V0::EMOpMode_t EMOpMode;
    boolean RSPCycleViolation;
    boolean EMCycleViolation;
  } BSW_s_EMCtrlData_t;                          /* @vaddr:0x20100200 @vaddr_defs: EM_MEAS_ID_CTRLDATA @cycleid:EM_ENV @vname:BSW_EMCtrlData */
}

// ARS5xx EM_BSW_EMCtrlData_V3 version 3         Length = 32
namespace EM_BSW_EMCtrlData_V3
{
  typedef unsigned short SYS_t_HWSample;         /* @min: 257 @max:272 @values: enum { SYS_C1=260,SYS_C0=258,SYS_C2=261,SYS_C2_TX30=262,SYS_C2_TX31=263,SYS_C2_1=272,SYS_B1_2=257,} */ /* [Satisfies_rte sws 1188] */

  typedef struct BSW_s_EMCtrlData_t              /* [Satisfies_rte sws 1191] */
  {
    unsigned long u_VersionNumber;
    EM_BSW_EMCtrlData_V1::SignalHeader_t sSigHeader;
    SYS_t_HWSample HWSample;
    EM_BSW_EMCtrlData_V0::EMOpMode_t EMOpMode;
    boolean RSPCycleViolation;
    boolean EMCycleViolation;
    unsigned char u_Dummy81;
    unsigned char u_Dummy82;
    unsigned char u_Dummy83;
  } BSW_s_EMCtrlData_t;                          /* @vaddr:0x20100200 @vaddr_defs: EM_MEAS_ID_CTRLDATA @cycleid:EM_ENV @vname:BSW_EMCtrlData */
}

namespace EM_BSW_EMCtrlData_V4
{
  typedef struct SYS_t_HWSample
  {
    unsigned __int32 u_LowFreqBoardVersion;
    unsigned __int32 u_HighFreqBoardVersion;
    unsigned __int32 u_RaceRunnerVersion;
  } SYS_t_HWSample;

  typedef struct BSW_s_EMCtrlData_t              /* [Satisfies_rte sws 1191] */
  {
    unsigned long u_VersionNumber;
    EM_BSW_EMCtrlData_V1::SignalHeader_t sSigHeader;
    SYS_t_HWSample HWSample;
    EM_BSW_EMCtrlData_V0::EMOpMode_t EMOpMode;
    boolean RSPCycleViolation;
    boolean EMCycleViolation;
  } BSW_s_EMCtrlData_t;                          /* @vaddr:0x20100200 @vaddr_defs: EM_MEAS_ID_CTRLDATA @cycleid:EM_ENV @vname:BSW_EMCtrlData */
}

// Generic namespace and structure, which includes all variances of the versioned namespaces

namespace EM_BSW_EMCtrlData_GenAll
{
  typedef struct BSW_s_EMCtrlData_t              /* [Satisfies_rte sws 1191] */
  {
    unsigned long u_VersionNumber;
    EM_BSW_EMCtrlData_V1::SignalHeader_t sSigHeader;
    EM_BSW_EMCtrlData_V3::SYS_t_HWSample HWSample;
    EM_BSW_EMCtrlData_V4::SYS_t_HWSample HWSampleV4;
    EM_BSW_EMCtrlData_V0::EMOpMode_t EMOpMode;
    boolean RSPCycleViolation;
    boolean EMCycleViolation;
  } BSW_s_EMCtrlData_t;
}


class CConvBswEmCtrlData : public CSimConverterBase
{
  // the list of dependency names used inside by the converter
  static const char *DEP_NAMES[];

  // here we define the index of each dependency for quick acces
  // the order here should match with the order from DEP_NAMES array
  enum eDepIdx
  {
    // add new dependencies here
    HWSAMPLE_VALUE,
    DEP_COUNT
  };
  // Dependency value of HWSAMPLE_VALUE
  static unsigned __int16 uiHWSampleValue;

  EM_BSW_EMCtrlData_V0::BSW_s_EMCtrlData_t m_BufV0;
  EM_BSW_EMCtrlData_V1::BSW_s_EMCtrlData_t m_BufV1;
  EM_BSW_EMCtrlData_V2::BSW_s_EMCtrlData_t m_BufV2;
  EM_BSW_EMCtrlData_V3::BSW_s_EMCtrlData_t m_BufV3;
  EM_BSW_EMCtrlData_V4::BSW_s_EMCtrlData_t m_BufV4;
  EM_BSW_EMCtrlData_GenAll::BSW_s_EMCtrlData_t m_BufGen;

  static void InitV0(EM_BSW_EMCtrlData_V0::BSW_s_EMCtrlData_t & Params);
  static void InitV1(EM_BSW_EMCtrlData_V1::BSW_s_EMCtrlData_t & Params);
  static void InitV2(EM_BSW_EMCtrlData_V2::BSW_s_EMCtrlData_t & Params);
  static void InitV3(EM_BSW_EMCtrlData_V3::BSW_s_EMCtrlData_t & Params);
  static void InitV4(EM_BSW_EMCtrlData_V4::BSW_s_EMCtrlData_t & Params);
  static void InitGen(EM_BSW_EMCtrlData_GenAll::BSW_s_EMCtrlData_t & Params, unsigned long VersionNumber);

public:

  static const char *GetConverterTypeName()
  {
    return "BSW_EMCtrlData";
  }

  CConvBswEmCtrlData(void);
  virtual ~CConvBswEmCtrlData(void);

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

  /* **************************************************************************** 
    @fn            IsPortSupported */ /*!
    @brief         Check Port for support
    @description   Used to check if a given port is in the list(s) of supported versions.
                   The version info is in the arrays VERSION_NUMBERS and SUPPORTED_SIZE
    @return        bool
    @param[in]     unsigned long ulPortSize
    @param[in]     const IVersionInfo *pPortVersion
    @pre           
    @post          (no changes)
    @date          14.01.2016
    @todo          
    @author        Thomas Berndt
  **************************************************************************** */
  bool IsPortSupported(unsigned long ulPortSize, const IVersionInfo *pPortVersion) const
  {
    for (int nI = 0; nI < EM_BSW_EMCTRLDATA_COUNT; nI++)
    {
      if ((pPortVersion == NULL) || pPortVersion->Equals(VERSION_NUMBERS[nI]))
      {
        if (ulPortSize == SUPPORTED_SIZE[nI])
        {
          return true;
        }
      }
    };
    return false;
  };

private:
  static void Convert_V0_to_Gen(EM_BSW_EMCtrlData_GenAll::BSW_s_EMCtrlData_t & Dest, const EM_BSW_EMCtrlData_V0::BSW_s_EMCtrlData_t & Src);
  static void Convert_V1_to_Gen(EM_BSW_EMCtrlData_GenAll::BSW_s_EMCtrlData_t & Dest, const EM_BSW_EMCtrlData_V1::BSW_s_EMCtrlData_t & Src);
  static void Convert_V2_to_Gen(EM_BSW_EMCtrlData_GenAll::BSW_s_EMCtrlData_t & Dest, const EM_BSW_EMCtrlData_V2::BSW_s_EMCtrlData_t & Src);
  static void Convert_V3_to_Gen(EM_BSW_EMCtrlData_GenAll::BSW_s_EMCtrlData_t & Dest, const EM_BSW_EMCtrlData_V3::BSW_s_EMCtrlData_t & Src);
  static void Convert_V4_to_Gen(EM_BSW_EMCtrlData_GenAll::BSW_s_EMCtrlData_t & Dest, const EM_BSW_EMCtrlData_V4::BSW_s_EMCtrlData_t & Src);
  static void Convert_Gen_to_V0(EM_BSW_EMCtrlData_V0::BSW_s_EMCtrlData_t & Dest, const EM_BSW_EMCtrlData_GenAll::BSW_s_EMCtrlData_t & Src);
  static void Convert_Gen_to_V1(EM_BSW_EMCtrlData_V1::BSW_s_EMCtrlData_t & Dest, const EM_BSW_EMCtrlData_GenAll::BSW_s_EMCtrlData_t & Src);
  static void Convert_Gen_to_V2(EM_BSW_EMCtrlData_V2::BSW_s_EMCtrlData_t & Dest, const EM_BSW_EMCtrlData_GenAll::BSW_s_EMCtrlData_t & Src);
  static void Convert_Gen_to_V3(EM_BSW_EMCtrlData_V3::BSW_s_EMCtrlData_t & Dest, const EM_BSW_EMCtrlData_GenAll::BSW_s_EMCtrlData_t & Src);
  static void Convert_Gen_to_V4(EM_BSW_EMCtrlData_V4::BSW_s_EMCtrlData_t & Dest, const EM_BSW_EMCtrlData_GenAll::BSW_s_EMCtrlData_t & Src);

  static void ConvertHWSample(EM_BSW_EMCtrlData_V4::SYS_t_HWSample &Dest, EM_BSW_EMCtrlData_V3::SYS_t_HWSample Src_HWSample);

private:

  static CVersionInfoImpl BASE_VERSION;
  static CVersionInfoImpl VERSION1;
  static CVersionInfoImpl VERSION2;
  static CVersionInfoImpl VERSION3;
  static CVersionInfoImpl VERSION4;

  enum BSW_EMCtrlData
  {
    EM_BSW_EMCtrlData_V0,
    EM_BSW_EMCtrlData_V1,
    EM_BSW_EMCtrlData_V2_1,
    EM_BSW_EMCtrlData_V2,
    EM_BSW_EMCtrlData_V3,
    EM_BSW_EMCtrlData_V4,
    EM_BSW_EMCtrlData_V3_1,
    EM_BSW_EMCTRLDATA_COUNT
  };

  static const unsigned long SUPPORTED_SIZE[EM_BSW_EMCTRLDATA_COUNT];

  static const CVersionInfoImpl * const VERSION_NUMBERS[EM_BSW_EMCTRLDATA_COUNT];

  /* **************************************************************************** 
    @fn              GetDepValue */ /*!
    @brief           
    @description     
    @return          bool
    @param[in]       unsigned __int16 &uiHWSampleValue
    @pre             
    @post            (no changes)
    @date            03.05.2016
    @todo            
    @author          Thomas Berndt
  **************************************************************************** */
  bool GetDepValue (unsigned __int16 &uiHWSampleValue)
  {
    bool bRet = false;
    uiHWSampleValue = 0u;
    DepInfo *pValUi = GetDependencyInfo(HWSAMPLE_VALUE);
    // retrieve dependency for being used
    if ((pValUi != NULL) && (pValUi->m_pDepData != NULL) && (pValUi->m_ulDepSize == sizeof(uiHWSampleValue)))
    {
      uiHWSampleValue = * (unsigned __int16 *) pValUi->m_pDepData;
      bRet = true;
    }
    return bRet;
  }
}; // End of class CConvBswEmCtrlData

const TCHAR *CConvBswEmCtrlData::DEP_NAMES[CConvBswEmCtrlData::DEP_COUNT] = {_T("HWSample_Value")};
unsigned __int16 CConvBswEmCtrlData::uiHWSampleValue = 0;

CVersionInfoImpl CConvBswEmCtrlData::BASE_VERSION(0, 0, 0);
CVersionInfoImpl CConvBswEmCtrlData::VERSION1(0, 0, 1);
CVersionInfoImpl CConvBswEmCtrlData::VERSION2(0, 0, 2);
CVersionInfoImpl CConvBswEmCtrlData::VERSION3(0, 0, 3);
CVersionInfoImpl CConvBswEmCtrlData::VERSION4(0, 0, 4);

const unsigned long CConvBswEmCtrlData::SUPPORTED_SIZE[CConvBswEmCtrlData::EM_BSW_EMCTRLDATA_COUNT] =
{
  sizeof(EM_BSW_EMCtrlData_V0::BSW_s_EMCtrlData_t),
  sizeof(EM_BSW_EMCtrlData_V1::BSW_s_EMCtrlData_t),
  sizeof(EM_BSW_EMCtrlData_V2::BSW_s_EMCtrlData_t),
  sizeof(EM_BSW_EMCtrlData_V2::BSW_s_EMCtrlData_t),
  sizeof(EM_BSW_EMCtrlData_V3::BSW_s_EMCtrlData_t),
  sizeof(EM_BSW_EMCtrlData_V4::BSW_s_EMCtrlData_t),
  sizeof(EM_BSW_EMCtrlData_V3::BSW_s_EMCtrlData_t)
};

const CVersionInfoImpl * const CConvBswEmCtrlData::VERSION_NUMBERS[CConvBswEmCtrlData::EM_BSW_EMCTRLDATA_COUNT] =
{
  &BASE_VERSION,
  &VERSION1,
  &VERSION1,
  &VERSION2,
  &VERSION3,
  &VERSION3,
  &VERSION4,
};

CConvBswEmCtrlData::CConvBswEmCtrlData(void) : CSimConverterBase(DEP_NAMES, DEP_COUNT), m_BufV0(), m_BufV1(), m_BufV2(), m_BufV3(), m_BufGen()
{
  uiHWSampleValue = 0u;
}

CConvBswEmCtrlData::~CConvBswEmCtrlData(void)
{
}

void CConvBswEmCtrlData::InitV0(EM_BSW_EMCtrlData_V0::BSW_s_EMCtrlData_t & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  // Data
  Params.EMOpMode                                = EM_MOD_STARTUP;
  Params.RSPCycleViolation                       = 0;
  Params.EMCycleViolation                        = 0;
}

void CConvBswEmCtrlData::InitV1(EM_BSW_EMCtrlData_V1::BSW_s_EMCtrlData_t & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  // Signal Header
  Params.sSigHeader.uiTimeStamp                  = 0;
  Params.sSigHeader.uiMeasurementCounter         = 0;
  Params.sSigHeader.uiCycleCounter               = 0;
  Params.sSigHeader.eSigStatus                   = AL_SIG_STATE_INIT;
  // Data
  Params.EMOpMode                                = EM_MOD_STARTUP;
  Params.RSPCycleViolation                       = 0;
  Params.EMCycleViolation                        = 0;
}

void CConvBswEmCtrlData::InitV2(EM_BSW_EMCtrlData_V2::BSW_s_EMCtrlData_t & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.u_VersionNumber                         = 2;
  // Signal Header
  Params.sSigHeader.uiTimeStamp                  = 0;
  Params.sSigHeader.uiMeasurementCounter         = 0;
  Params.sSigHeader.uiCycleCounter               = 0;
  Params.sSigHeader.eSigStatus                   = AL_SIG_STATE_INIT;
  // Data
  Params.EMOpMode                                = EM_MOD_STARTUP;
  Params.RSPCycleViolation                       = 0;
  Params.EMCycleViolation                        = 0;
}

void CConvBswEmCtrlData::InitV3(EM_BSW_EMCtrlData_V3::BSW_s_EMCtrlData_t & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.u_VersionNumber                         = 3;
  // Signal Header
  Params.sSigHeader.uiTimeStamp                  = 0;
  Params.sSigHeader.uiMeasurementCounter         = 0;
  Params.sSigHeader.uiCycleCounter               = 0;
  Params.sSigHeader.eSigStatus                   = AL_SIG_STATE_INIT;
  // Data
  memset(&(Params.HWSample), 0, sizeof(Params.HWSample));
  Params.EMOpMode                                = EM_MOD_STARTUP;
  Params.RSPCycleViolation                       = 0;
  Params.EMCycleViolation                        = 0;
  Params.u_Dummy81                               = 0;
  Params.u_Dummy82                               = 0;
  Params.u_Dummy83                               = 0;
}

void CConvBswEmCtrlData::InitV4(EM_BSW_EMCtrlData_V4::BSW_s_EMCtrlData_t & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.u_VersionNumber                         = 4;
  // Signal Header
  Params.sSigHeader.uiTimeStamp                  = 0;
  Params.sSigHeader.uiMeasurementCounter         = 0;
  Params.sSigHeader.uiCycleCounter               = 0;
  Params.sSigHeader.eSigStatus                   = AL_SIG_STATE_INIT;
  // Data
  Params.HWSample.u_HighFreqBoardVersion         = 1;
  Params.HWSample.u_LowFreqBoardVersion          = 1;
  Params.HWSample.u_RaceRunnerVersion            = 1;
  Params.EMOpMode                                = EM_MOD_STARTUP;
  Params.RSPCycleViolation                       = 0;
  Params.EMCycleViolation                        = 0;
}

void CConvBswEmCtrlData::InitGen(EM_BSW_EMCtrlData_GenAll::BSW_s_EMCtrlData_t & Params, unsigned long VersionNumber)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.u_VersionNumber                         = VersionNumber;
  // Signal Header
  Params.sSigHeader.uiTimeStamp                  = 0;
  Params.sSigHeader.uiMeasurementCounter         = 0;
  Params.sSigHeader.uiCycleCounter               = 0;
  Params.sSigHeader.eSigStatus                   = AL_SIG_STATE_INIT;
  // Data
  memset(&(Params.HWSample), 0, sizeof(Params.HWSample));
  Params.HWSampleV4.u_HighFreqBoardVersion       = 1;
  Params.HWSampleV4.u_LowFreqBoardVersion        = 1;
  Params.HWSampleV4.u_RaceRunnerVersion          = 1;
  Params.EMOpMode                                = EM_MOD_STARTUP;
  Params.RSPCycleViolation                       = 0;
  Params.EMCycleViolation                        = 0;
}

void CConvBswEmCtrlData::Convert_V0_to_Gen(EM_BSW_EMCtrlData_GenAll::BSW_s_EMCtrlData_t & Dest, const EM_BSW_EMCtrlData_V0::BSW_s_EMCtrlData_t & Src)
{
  //Dest.u_VersionNumber = Src.u_VersionNumber;
  //Dest.sSigHeader = Src.sSigHeader;
  Dest.EMOpMode = Src.EMOpMode;
  Dest.HWSample = uiHWSampleValue;
  ConvertHWSample(Dest.HWSampleV4, uiHWSampleValue);
  Dest.RSPCycleViolation = Src.EMCycleViolation;
  Dest.RSPCycleViolation = Src.RSPCycleViolation;
}

void CConvBswEmCtrlData::Convert_V1_to_Gen(EM_BSW_EMCtrlData_GenAll::BSW_s_EMCtrlData_t & Dest, const EM_BSW_EMCtrlData_V1::BSW_s_EMCtrlData_t & Src)
{
  //Dest.u_VersionNumber = Src.u_VersionNumber;
  Dest.sSigHeader = Src.sSigHeader;
  Dest.HWSample = uiHWSampleValue;
  ConvertHWSample(Dest.HWSampleV4, uiHWSampleValue);
  Dest.EMOpMode = Src.EMOpMode;
  Dest.RSPCycleViolation = Src.EMCycleViolation;
  Dest.RSPCycleViolation = Src.RSPCycleViolation;
}

void CConvBswEmCtrlData::Convert_V2_to_Gen(EM_BSW_EMCtrlData_GenAll::BSW_s_EMCtrlData_t & Dest, const EM_BSW_EMCtrlData_V2::BSW_s_EMCtrlData_t & Src)
{
  Dest.u_VersionNumber = Src.u_VersionNumber;
  Dest.sSigHeader = Src.sSigHeader;
  Dest.HWSample = uiHWSampleValue;
  ConvertHWSample(Dest.HWSampleV4, uiHWSampleValue);
  Dest.EMOpMode = Src.EMOpMode;
  Dest.RSPCycleViolation = Src.EMCycleViolation;
  Dest.RSPCycleViolation = Src.RSPCycleViolation;
}

void CConvBswEmCtrlData::Convert_V3_to_Gen(EM_BSW_EMCtrlData_GenAll::BSW_s_EMCtrlData_t & Dest, const EM_BSW_EMCtrlData_V3::BSW_s_EMCtrlData_t & Src)
{
  Dest.u_VersionNumber = Src.u_VersionNumber;
  Dest.sSigHeader = Src.sSigHeader;
  Dest.HWSample = Src.HWSample;
  ConvertHWSample(Dest.HWSampleV4, Src.HWSample);
  Dest.EMOpMode = Src.EMOpMode;
  Dest.RSPCycleViolation = Src.EMCycleViolation;
  Dest.RSPCycleViolation = Src.RSPCycleViolation;
}

void CConvBswEmCtrlData::Convert_V4_to_Gen(EM_BSW_EMCtrlData_GenAll::BSW_s_EMCtrlData_t & Dest, const EM_BSW_EMCtrlData_V4::BSW_s_EMCtrlData_t & Src)
{
  Dest.u_VersionNumber = Src.u_VersionNumber;
  Dest.sSigHeader = Src.sSigHeader;
  Dest.HWSampleV4 = Src.HWSample;
  Dest.EMOpMode = Src.EMOpMode;
  Dest.RSPCycleViolation = Src.EMCycleViolation;
  Dest.RSPCycleViolation = Src.RSPCycleViolation;
}

void CConvBswEmCtrlData::Convert_Gen_to_V0(EM_BSW_EMCtrlData_V0::BSW_s_EMCtrlData_t & Dest, const EM_BSW_EMCtrlData_GenAll::BSW_s_EMCtrlData_t & Src)
{
  Dest.EMOpMode = Src.EMOpMode;
  Dest.RSPCycleViolation = Src.EMCycleViolation;
  Dest.RSPCycleViolation = Src.RSPCycleViolation;
}

void CConvBswEmCtrlData::Convert_Gen_to_V1(EM_BSW_EMCtrlData_V1::BSW_s_EMCtrlData_t & Dest, const EM_BSW_EMCtrlData_GenAll::BSW_s_EMCtrlData_t & Src)
{
  Dest.sSigHeader = Src.sSigHeader;
  Dest.EMOpMode = Src.EMOpMode;
  Dest.RSPCycleViolation = Src.EMCycleViolation;
  Dest.RSPCycleViolation = Src.RSPCycleViolation;
}

void CConvBswEmCtrlData::Convert_Gen_to_V2(EM_BSW_EMCtrlData_V2::BSW_s_EMCtrlData_t & Dest, const EM_BSW_EMCtrlData_GenAll::BSW_s_EMCtrlData_t & Src)
{
  Dest.u_VersionNumber = 2;
  Dest.sSigHeader = Src.sSigHeader;
  Dest.EMOpMode = Src.EMOpMode;
  Dest.RSPCycleViolation = Src.EMCycleViolation;
  Dest.RSPCycleViolation = Src.RSPCycleViolation;
}

void CConvBswEmCtrlData::Convert_Gen_to_V3(EM_BSW_EMCtrlData_V3::BSW_s_EMCtrlData_t & Dest, const EM_BSW_EMCtrlData_GenAll::BSW_s_EMCtrlData_t & Src)
{
  Dest.u_VersionNumber = 3;
  Dest.sSigHeader = Src.sSigHeader;
  Dest.HWSample = Src.HWSample;
  Dest.EMOpMode = Src.EMOpMode;
  Dest.RSPCycleViolation = Src.EMCycleViolation;
  Dest.RSPCycleViolation = Src.RSPCycleViolation;
}

void CConvBswEmCtrlData::Convert_Gen_to_V4(EM_BSW_EMCtrlData_V4::BSW_s_EMCtrlData_t & Dest, const EM_BSW_EMCtrlData_GenAll::BSW_s_EMCtrlData_t & Src)
{
  Dest.u_VersionNumber = 3;
  Dest.sSigHeader = Src.sSigHeader;
  Dest.HWSample = Src.HWSampleV4;
  Dest.EMOpMode = Src.EMOpMode;
  Dest.RSPCycleViolation = Src.EMCycleViolation;
  Dest.RSPCycleViolation = Src.RSPCycleViolation;
}

void CConvBswEmCtrlData::ConvertHWSample(EM_BSW_EMCtrlData_V4::SYS_t_HWSample &Dest, EM_BSW_EMCtrlData_V3::SYS_t_HWSample Src_HWSample)
{
  if (Src_HWSample == 259u)
  {
    Dest.u_HighFreqBoardVersion = 1;
  }
  else if (Src_HWSample == 4096u)
  {
    Dest.u_HighFreqBoardVersion = 2;
  }
}

long CConvBswEmCtrlData::ConvertData(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo *pProvidePortVersionInfo,
  void *pPPortData,
  void **pOutData, unsigned long &ulOutSize)
{
  long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  bool bGenBufferFilled = false;
  const uint32 uDataVer = ((pPPortData != NULL) && (ulPPortSize >= 4) && (ePPortType == simOPAQUE_t))?(*reinterpret_cast<uint32*>(pPPortData)):(0);
  GetDepValue (uiHWSampleValue);
  if (eRPortType == ePPortType)
  {
    // If ports equal, then always compatible
    if (ulPPortSize == ulRPortSize)
    {
      lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
    }
    // First decide from which version we are converting and fill the generic buffer accordingly
    else if ((ulPPortSize == SUPPORTED_SIZE[EM_BSW_EMCtrlData_V4])
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(VERSION_NUMBERS[EM_BSW_EMCtrlData_V4])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && (uDataVer == 3u))
    {
      // Source Port V4 of ARS5xx
      InitGen(m_BufGen, 4);
      const EM_BSW_EMCtrlData_V4::BSW_s_EMCtrlData_t & Src = *reinterpret_cast<EM_BSW_EMCtrlData_V4::BSW_s_EMCtrlData_t*>(pPPortData);
      Convert_V4_to_Gen(m_BufGen, Src);
      bGenBufferFilled = true;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[EM_BSW_EMCtrlData_V3])
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(VERSION_NUMBERS[EM_BSW_EMCtrlData_V3])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && (uDataVer == 3u))
    {
      // Source Port V3 of ARS4xx
      InitGen(m_BufGen, 3);
      const EM_BSW_EMCtrlData_V3::BSW_s_EMCtrlData_t & Src = *reinterpret_cast<EM_BSW_EMCtrlData_V3::BSW_s_EMCtrlData_t*>(pPPortData);
      Convert_V3_to_Gen(m_BufGen, Src);
      bGenBufferFilled = true;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[EM_BSW_EMCtrlData_V2])
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(VERSION_NUMBERS[EM_BSW_EMCtrlData_V2])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && ((uDataVer == 1u) || (uDataVer == 2u)))
    {
      // Source Port V2 of ARS4xx
      InitGen(m_BufGen, 2);
      const EM_BSW_EMCtrlData_V2::BSW_s_EMCtrlData_t & Src = *reinterpret_cast<EM_BSW_EMCtrlData_V2::BSW_s_EMCtrlData_t*>(pPPortData);
      Convert_V2_to_Gen(m_BufGen, Src);
      bGenBufferFilled = true;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[EM_BSW_EMCtrlData_V1])
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(VERSION_NUMBERS[EM_BSW_EMCtrlData_V1])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION))))
    {
      // Source Port V1 of ARS4xx
      InitGen(m_BufGen, 1);
      const EM_BSW_EMCtrlData_V1::BSW_s_EMCtrlData_t & Src = *reinterpret_cast<EM_BSW_EMCtrlData_V1::BSW_s_EMCtrlData_t*>(pPPortData);
      Convert_V1_to_Gen(m_BufGen, Src);
      bGenBufferFilled = true;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[EM_BSW_EMCtrlData_V0])
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(VERSION_NUMBERS[EM_BSW_EMCtrlData_V0])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION))))
    {
      // Source Port V0 of ARS4xx
      InitGen(m_BufGen, 0);
      const EM_BSW_EMCtrlData_V0::BSW_s_EMCtrlData_t & Src = *reinterpret_cast<EM_BSW_EMCtrlData_V0::BSW_s_EMCtrlData_t*>(pPPortData);
      Convert_V0_to_Gen(m_BufGen, Src);
      m_BufGen.sSigHeader.eSigStatus = AL_SIG_STATE_OK;                        // No sSigHeader -> Set State = OK
      bGenBufferFilled = true;
    }

    if (bGenBufferFilled == true)
    {
      // Second decide to which version we are converting
      // and take the generic buffer to fill the destination buffer
      if ((ulRPortSize == SUPPORTED_SIZE[EM_BSW_EMCtrlData_V4]) && (requestPortVersionInfo.Equals(VERSION_NUMBERS[EM_BSW_EMCtrlData_V4])))
      {
        // Destination port of V4 of ARS5xx
        InitV4(m_BufV4);
        Convert_Gen_to_V4(m_BufV4, m_BufGen);
        *pOutData = &m_BufV4;
        ulOutSize = sizeof(m_BufV4);
        lRet = SIM_ERR_OK;
      }
      else if (((ulRPortSize == SUPPORTED_SIZE[EM_BSW_EMCtrlData_V3]) && ((requestPortVersionInfo.Equals(VERSION_NUMBERS[EM_BSW_EMCtrlData_V3])) || (requestPortVersionInfo.Equals(VERSION_NUMBERS[EM_BSW_EMCtrlData_V3_1])))))
      {
        // Destination port of V3 and V4 (same as V3) of ARS4xx
        InitV3(m_BufV3);
        Convert_Gen_to_V3(m_BufV3, m_BufGen);
        if ((requestPortVersionInfo.Equals(VERSION_NUMBERS[EM_BSW_EMCtrlData_V3_1])))
        {
          m_BufV3.u_VersionNumber = 4;
        }
        *pOutData = &m_BufV3;
        ulOutSize = sizeof(m_BufV3);
        lRet = SIM_ERR_OK;
      }
      else if ((ulRPortSize == SUPPORTED_SIZE[EM_BSW_EMCtrlData_V2]) && ((requestPortVersionInfo.Equals(VERSION_NUMBERS[EM_BSW_EMCtrlData_V2])) || (requestPortVersionInfo.Equals(VERSION_NUMBERS[EM_BSW_EMCtrlData_V2_1]))))
      {
        // Destination port of V2 of ARS4xx
        InitV2(m_BufV2);
        Convert_Gen_to_V2(m_BufV2, m_BufGen);
        *pOutData = &m_BufV2;
        ulOutSize = sizeof(m_BufV2);
        lRet = SIM_ERR_OK;
      }
      else if ((ulRPortSize == SUPPORTED_SIZE[EM_BSW_EMCtrlData_V1]) && (requestPortVersionInfo.Equals(VERSION_NUMBERS[EM_BSW_EMCtrlData_V1])))
      {
        // Destination port of V1 of ARS4xx
        InitV1(m_BufV1);
        Convert_Gen_to_V1(m_BufV1, m_BufGen);
        *pOutData = &m_BufV1;
        ulOutSize = sizeof(m_BufV1);
        lRet = SIM_ERR_OK;
      }
      else if ((ulRPortSize == SUPPORTED_SIZE[EM_BSW_EMCtrlData_V0]) && (requestPortVersionInfo.Equals(VERSION_NUMBERS[EM_BSW_EMCtrlData_V0])))
      {
        // Destination port of V0 of ARS4xx
        InitV0(m_BufV0);
        Convert_Gen_to_V0(m_BufV0, m_BufGen);
        *pOutData = &m_BufV0;
        ulOutSize = sizeof(m_BufV0);
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
long CConvBswEmCtrlData::GetDefaultValue(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  void **pDefaultData, unsigned long &ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == sizeof(m_BufV4)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION3.Equals(&requestPortVersionInfo))))
    {
      InitV4(m_BufV4);
      *pDefaultData = &m_BufV4;
      ulDefaultSize = sizeof(m_BufV4);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_BufV3)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION3.Equals(&requestPortVersionInfo))))
    {
      InitV3(m_BufV3);
      *pDefaultData = &m_BufV3;
      ulDefaultSize = sizeof(m_BufV3);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_BufV2)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION1.Equals(&requestPortVersionInfo))))
    {
      InitV2(m_BufV2);
      *pDefaultData = &m_BufV2;
      ulDefaultSize = sizeof(m_BufV2);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_BufV1)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION1.Equals(&requestPortVersionInfo))))
    {
      InitV1(m_BufV1);
      *pDefaultData = &m_BufV1;
      ulDefaultSize = sizeof(m_BufV1);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_BufV0)) && BASE_VERSION.Equals(&requestPortVersionInfo))
    {
      InitV0(m_BufV0);
      *pDefaultData = &m_BufV0;
      ulDefaultSize = sizeof(m_BufV0);
      lRet = SIM_ERR_OK;
    }
    else
    {
      // No default value(s) available
    }
  }
  return lRet;
}

// used to check if an unversioned PPort is compatible with a certain version of RPort
bool CConvBswEmCtrlData::IsVersionCompatibleWithType(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
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
    if ((IsPortSupported(ulRPortSize, &requestPortVersionInfo)) && (IsPortSupported(ulPPortSize, NULL)))
    {
      bResult = true;
    }
  }
  return bResult;
}

// used to check if ports are compatible between different versions
bool CConvBswEmCtrlData::AreVersionsCompatible(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo &providePortVersionInfo)
{
  bool bResult = false;
  // If ports equal, then always compatible
  if ((eRPortType == ePPortType) && (ulRPortSize == ulPPortSize) && (requestPortVersionInfo.Equals(&providePortVersionInfo)))
  {
    bResult = true;
  }
  else
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
IConverter * CreateBswEmCtrlDataConvClass(void)
{
  return new CConvBswEmCtrlData();
}
