/*! \file **********************************************************************
 
  COMPANY:              Continental
 
  PROJECT:              Simulation
 
  COMPONENT:            sim_adapter
 
  MODULNAME:            sim_conv_frs_frsbswctrldata.cpp
 
  DESCRIPTION:          Convert
 
  AUTHOR:               Gökhan Dagli
 
  CREATION DATE:        24.01.2017
 
  VERSION:              $Revision: 1.1 $
 
  ---*/ /*---
  CHANGES:              $Log: sim_conv_frs_frsbswctrldata.cpp  $
  CHANGES:              Revision 1.1 2021/12/13 17:21:14CET Wang, David (Wangd3) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_adapter/frs/project.pj
  CHANGES:              Revision 1.1 2017/08/10 13:15:22CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/frs/project.pj
  CHANGES:              Revision 1.1 2017/01/24 15:03:10CET Dagli, Goekhan (uidj7850) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CRT_CommonRadarToolbox/04_Engineering/03_Workspace/algo/sim_adapter/frs/project.pj
 
**************************************************************************** */
/* includes ---------------------------------------------------------------- */
#include "stdafx.h"
#include "sim_conv_frs_frsbswctrldata.h"
#include "sim_versioninfo_impl.h"

namespace FRS_frsBSWCtrlData_t_V1
{
  typedef uint32 AlgoInterfaceVersionNumber_t /* Algo interface version nummbers @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */;
  typedef uint32 AlgoDataTimeStamp_t       /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */;
  typedef uint16 AlgoCycleCounter_t        /* Algo cycle counter @min:0 @max:65535 */	/* [Satisfies_rte sws 1188] */;
  typedef uint16 AlgoCycleCounter_t        /* Algo cycle counter @min:0 @max:65535 */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 AlgoSignalState_t          /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8  FRSOpMode_t               				/* [Satisfies_rte_sws_7109] , [Satisfies_rte_sws_7168] */;

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    AlgoDataTimeStamp_t uiTimeStamp;
    AlgoCycleCounter_t uiMeasurementCounter;
    AlgoCycleCounter_t uiCycleCounter;
    AlgoSignalState_t eSigStatus;
  } SignalHeader_t;			/* Common header for all structured data types */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    AlgoInterfaceVersionNumber_t uVersionNumber;
    SignalHeader_t sSignalHeader;
    FRSOpMode_t eOpMode;
  } frsBSWCtrlData_t;
}

namespace FRS_FRSBSWCTRLDATA_GenAll
{
  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    FRS_frsBSWCtrlData_t_V1::AlgoInterfaceVersionNumber_t uVersionNumber;
    FRS_frsBSWCtrlData_t_V1::SignalHeader_t sSignalHeader;
    FRS_frsBSWCtrlData_t_V1::FRSOpMode_t eOpMode;
  } frsBSWCtrlData_t;
}

class CConvFRSBswCtrlData : public CSimConverterBase
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

  FRS_frsBSWCtrlData_t_V1::frsBSWCtrlData_t m_Buf_V1;
  FRS_FRSBSWCTRLDATA_GenAll::frsBSWCtrlData_t m_Buf_GenAll;

  void InitV1(FRS_frsBSWCtrlData_t_V1::frsBSWCtrlData_t & Dest);
  void InitGen(FRS_FRSBSWCTRLDATA_GenAll::frsBSWCtrlData_t & Dest, unsigned long VersionNumber);

public:

  static const char* GetConverterTypeName()
  {
    return "Init_PerfDegr";
  }

  CConvFRSBswCtrlData(void);
  virtual ~CConvFRSBswCtrlData(void);

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
    for (int nI = 0; nI < FRS_frsBSWCtrlData_t_VERSION_COUNT; nI++)
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
  static void Convert_V1_to_Gen(FRS_FRSBSWCTRLDATA_GenAll::frsBSWCtrlData_t & Dest, const FRS_frsBSWCtrlData_t_V1::frsBSWCtrlData_t & Src);
  static void Convert_Gen_to_V1(FRS_frsBSWCtrlData_t_V1::frsBSWCtrlData_t & Dest, const FRS_FRSBSWCTRLDATA_GenAll::frsBSWCtrlData_t & Src);

  static CVersionInfoImpl BASE_VERSION;
  static CVersionInfoImpl VERSION1;

  enum ePerfDegrVersions
  {
    FRS_FRSBSWCTRLDATA_GenAll,
    FRS_frsBSWCtrlData_t_V1,
    FRS_frsBSWCtrlData_t_VERSION_COUNT
  };
  static unsigned long SUPPORTED_SIZE[FRS_frsBSWCtrlData_t_VERSION_COUNT];
  static const CVersionInfoImpl * const VERSION_NUMBERS[CConvFRSBswCtrlData::FRS_frsBSWCtrlData_t_VERSION_COUNT];
};

CVersionInfoImpl  CConvFRSBswCtrlData::BASE_VERSION(0, 0, 0);
CVersionInfoImpl  CConvFRSBswCtrlData::VERSION1(0, 0, 1);

unsigned long CConvFRSBswCtrlData::SUPPORTED_SIZE[CConvFRSBswCtrlData::FRS_frsBSWCtrlData_t_VERSION_COUNT]=
{
  sizeof(FRS_FRSBSWCTRLDATA_GenAll::frsBSWCtrlData_t),
  sizeof(FRS_frsBSWCtrlData_t_V1::frsBSWCtrlData_t),
};

const CVersionInfoImpl * const CConvFRSBswCtrlData::VERSION_NUMBERS[CConvFRSBswCtrlData::FRS_frsBSWCtrlData_t_VERSION_COUNT] =
{
  &BASE_VERSION,
  &VERSION1,
};

CConvFRSBswCtrlData::CConvFRSBswCtrlData(void)
: CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT), m_Buf_GenAll(), m_Buf_V1()
{
  InitGen(m_Buf_GenAll, 0);
  InitV1(m_Buf_V1);
}

CConvFRSBswCtrlData::~CConvFRSBswCtrlData(void)
{
}

void CConvFRSBswCtrlData::InitV1(FRS_frsBSWCtrlData_t_V1::frsBSWCtrlData_t & Dest)
{
  memset(&Dest, 0, sizeof(Dest));
  Dest.uVersionNumber  = 1;
}

void CConvFRSBswCtrlData::InitGen(FRS_FRSBSWCTRLDATA_GenAll::frsBSWCtrlData_t & Dest, unsigned long VersionNumber)
{
  memset(&Dest, 0, sizeof(Dest));
  Dest.uVersionNumber  = VersionNumber;
}

void CConvFRSBswCtrlData::Convert_V1_to_Gen(FRS_FRSBSWCTRLDATA_GenAll::frsBSWCtrlData_t & Dest, const FRS_frsBSWCtrlData_t_V1::frsBSWCtrlData_t & Src)
{
  Dest.uVersionNumber    = Src.uVersionNumber;

  Dest.sSignalHeader         = Src.sSignalHeader;
}

void CConvFRSBswCtrlData::Convert_Gen_to_V1(FRS_frsBSWCtrlData_t_V1::frsBSWCtrlData_t & Dest, const FRS_FRSBSWCTRLDATA_GenAll::frsBSWCtrlData_t & Src)
{
  Dest.uVersionNumber = 7;

  Dest.sSignalHeader         = Src.sSignalHeader;
}

long CConvFRSBswCtrlData::ConvertData(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo, 
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo* pProvidePortVersionInfo, 
    void* pPPortData,
    void** pOutData, unsigned long& ulOutSize)
{
  long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  bool bGenBufferFilled = false;
  const uint32 uDataVer = ((pPPortData != NULL) && (ulPPortSize >= 4) && (ePPortType == simOPAQUE_t))?(*reinterpret_cast<uint32*>(pPPortData)):(0);
  // If ports equal, then always compatible
  if (eRPortType == ePPortType)
  {
    if (ulPPortSize == ulRPortSize)
    {
      lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
    }
    // First decide from which version we are converting and fill the generic buffer accordingly
    else if ((ulPPortSize == SUPPORTED_SIZE[FRS_frsBSWCtrlData_t_V1])
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(VERSION_NUMBERS[FRS_frsBSWCtrlData_t_V1])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && (uDataVer == 1u))
    {
      // Source Port 17
      InitGen(m_Buf_GenAll, 1);
      const FRS_frsBSWCtrlData_t_V1::frsBSWCtrlData_t & Src = *reinterpret_cast<FRS_frsBSWCtrlData_t_V1::frsBSWCtrlData_t*>(pPPortData);
      Convert_V1_to_Gen(m_Buf_GenAll, Src);
      bGenBufferFilled = true;
    }
    if (bGenBufferFilled == true)
    {
      // Second decide to which version we are converting
      // and take the generic buffer to fill the destination buffer
      if ((ulRPortSize == SUPPORTED_SIZE[FRS_frsBSWCtrlData_t_V1]) && (requestPortVersionInfo.Equals(VERSION_NUMBERS[FRS_frsBSWCtrlData_t_V1])))
      {
        // Destination port of V1
        InitV1(m_Buf_V1);
        Convert_Gen_to_V1(m_Buf_V1, m_Buf_GenAll);
        *pOutData = &m_Buf_V1;
        ulOutSize = sizeof(m_Buf_V1);
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
long CConvFRSBswCtrlData::GetDefaultValue(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo, 
    void** pDefaultData, unsigned long& ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == sizeof(FRS_frsBSWCtrlData_t_V1::frsBSWCtrlData_t)) &&
      ((requestPortVersionInfo.Equals(&VERSION1)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      InitV1(m_Buf_V1);
      *pDefaultData = &m_Buf_V1;
      ulDefaultSize = sizeof(m_Buf_V1);
      lRet = SIM_ERR_OK;
    }
    else
    {
      //No default value(s) available
    }
  }
  return lRet;
}

// used to check if an unversioned PPort is compatible with a certain version of RPort
bool CConvFRSBswCtrlData::IsVersionCompatibleWithType(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo, 
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize)
{
  bool bResult = false;
  // Equal ports are always compatible (at least assumed to be)
  if ((ulRPortSize == ulPPortSize) &&(ePPortType == eRPortType))
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
bool CConvFRSBswCtrlData::AreVersionsCompatible(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo& providePortVersionInfo)
{
  bool bResult = false;
  // Ports with same type/size/version are always compatible
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

IConverter * CreateFRSBswCtrlDataConvClass(void)
{
  return new CConvFRSBswCtrlData();
}
