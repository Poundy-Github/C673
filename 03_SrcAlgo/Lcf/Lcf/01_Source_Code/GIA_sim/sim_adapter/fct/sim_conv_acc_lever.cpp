/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter_fct

  MODULNAME:            sim_conv_acc_lever.cpp

  DESCRIPTION:          Converter class for AccLeverInput

  AUTHOR:               Gergely Ungvary

  CREATION DATE:        27.10.2011

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: sim_conv_acc_lever.cpp  $
  CHANGES:              Revision 1.1 2021/12/13 17:20:55CET Wang, David (Wangd3) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_adapter/fct/project.pj
  CHANGES:              Revision 1.1 2017/08/10 13:15:10CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/fct/project.pj
  CHANGES:              Revision 1.4 2016/09/09 12:20:19CEST Dagli, Goekhan (uidj7850) 
  CHANGES:              Added Version 6 (Hyundai)
  CHANGES:              Revision 1.3 2013/05/21 18:04:22CEST ungvaryg 
  CHANGES:              Modify for ARS4xx 'big' adapter: remove class declarations and complex includes from individual headers (only leaving factory
  CHANGES:              function external declaration there), moving class declaration and all additional includes into cpp file. Add single factory function
  CHANGES:              per data conversion stream.
  CHANGES:              Note: otherwise no functional changes made, thus the new revisions perform the exact same conversions (ARS3xx) as previously
  CHANGES:              - Added comments -  ungvaryg [May 21, 2013 6:04:22 PM CEST]
  CHANGES:              Change Package : 172401:1 http://mks-psad:7002/im/viewissue?selection=172401
  CHANGES:              Revision 1.2 2011/11/03 14:21:14CET Ungvary, Gergely (ungvaryg) 
  CHANGES:              Add dummy AccLever conversion support (which consists of only 4 byte long version number for projects where no AccLever information present)
  CHANGES:              --- Added comments ---  ungvaryg [Nov 3, 2011 2:21:14 PM CET]
  CHANGES:              Change Package : 86065:1 http://mks-psad:7002/im/viewissue?selection=86065
  CHANGES:              Revision 1.1 2011/10/27 17:59:24CEST Ungvary Gergely (ungvaryg) (ungvaryg) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/PROJECTS/ARS301/06_Algorithm/04_Engineering/03_Workspace/algo/fct_sim/fct_adapt/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */
#include "stdafx.h"
#include "sim_conv_acc_lever.h"
#include "sim_versioninfo_impl.h"

//
// AccLeverInput structure declarations
//

namespace AccLeverV1
{
  typedef uint8 AccelSwitch_t              /* ACC lever acceleration request @min: 0 @max:2 @values: enum { ACC_LEVER_ACCEL_HIGH=2,ACC_LEVER_ACCEL_LOW=1,ACC_LEVER_NO_ACCEL=0,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;
  typedef uint8 DecelSwitch_t              /* ACC lever decceleration request @min: 0 @max:2 @values: enum { ACC_LEVER_NO_DECEL=0,ACC_LEVER_DECEL_LOW=1,ACC_LEVER_DECEL_HIGH=2,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    uint32 uiVersionNumber;         /* The interface data version @min:0.0 @max:16777215.0 */
    boolean Cancel;                 /* ACC lever cancel @min:0.0 @max:1.0 */
    boolean Resume;                 /* ACC lever resume @min:0.0 @max:1.0 */
    AccelSwitch_t AccelSwitch;      /* ACC lever acceleration request */
    DecelSwitch_t DecelSwitch;      /* ACC lever decceleration request */
    boolean MainMode;               /* ACC Main Mode Switch @min:0.0 @max:1.0 */
    boolean HeadwayInc;             /* ACC Headway increase switch @min:0.0 @max:1.0 */
    boolean HeadwayDec;             /* ACC Headway decrease switch @min:0.0 @max:1.0 */
    uint8 Headway;                  /* ACC Headway setting @min:0.0 @max:100.0 */
    boolean DM_Setting;             /* Distance monitoring setting @min:0.0 @max:1.0 */
    boolean FCA_Setting;            /* Forward collision alert setting @min:0.0 @max:1.0 */
  } AccLeverInput_t;  /* Driver ACC lever input controls @vaddr:FCT_MEAS_ID_ACC_LEVER_INPUT @cycleid:FCT_VEH @vname:AccLeverInput */

};  // End of namespace AccLeverV1


namespace AccLeverV2
{
  typedef uint8 AlgoSignalState_t          /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    uint32 uiVersionNumber;         /* The interface data version @min:0.0 @max:16777215.0 */
    AlgoSignalState_t eSignalState;
    boolean Cancel;                 /* ACC lever cancel @min:0.0 @max:1.0 */
    boolean Resume;                 /* ACC lever resume @min:0.0 @max:1.0 */
    AccLeverV1::AccelSwitch_t AccelSwitch;      /* ACC lever acceleration request */
    AccLeverV1::DecelSwitch_t DecelSwitch;      /* ACC lever decceleration request */
    boolean MainMode;               /* ACC Main Mode Switch @min:0.0 @max:1.0 */
    boolean HeadwayInc;             /* ACC Headway increase switch @min:0.0 @max:1.0 */
    boolean HeadwayDec;             /* ACC Headway decrease switch @min:0.0 @max:1.0 */
    uint8 Headway;                  /* ACC Headway setting @min:0.0 @max:100.0 */
    boolean DM_Setting;             /* Distance monitoring setting @min:0.0 @max:1.0 */
    boolean FCA_Setting;            /* Forward collision alert setting @min:0.0 @max:1.0 */
  } AccLeverInput_t;  /* Driver ACC lever input controls @vaddr:FCT_MEAS_ID_ACC_LEVER_INPUT @cycleid:FCT_VEH @vname:AccLeverInput */

};  // End of namespace AccLeverV2


namespace AccLeverV6
{
  typedef unsigned long AlgoDataTimeStamp_t;  /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */
  typedef unsigned short AlgoCycleCounter_t;  /* Algo cycle counter @min:0 @max:65535 */
  typedef unsigned char AlgoSignalState_t;    /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */

  typedef struct SignalHeader_t
  {
    AlgoDataTimeStamp_t uiTimeStamp;
    AlgoCycleCounter_t uiMeasurementCounter;
    AlgoCycleCounter_t uiCycleCounter;
    AlgoSignalState_t eSigStatus;
  } SignalHeader_t;  /* Common header for all structured data types */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    uint32 uiVersionNumber;         /* The interface data version @min:0.0 @max:16777215.0 */
    SignalHeader_t sSigHeader;
    boolean Cancel;                 /* ACC lever cancel @min:0.0 @max:1.0 */
    boolean Resume;                 /* ACC lever resume @min:0.0 @max:1.0 */
    AccLeverV1::AccelSwitch_t AccelSwitch;      /* ACC lever acceleration request */
    AccLeverV1::DecelSwitch_t DecelSwitch;      /* ACC lever decceleration request */
    boolean MainMode;               /* ACC Main Mode Switch @min:0.0 @max:1.0 */
    boolean HeadwayInc;             /* ACC Headway increase switch @min:0.0 @max:1.0 */
    boolean HeadwayDec;             /* ACC Headway decrease switch @min:0.0 @max:1.0 */
    uint8 Headway;                  /* ACC Headway setting @min:0.0 @max:100.0 */
    boolean DM_Setting;             /* Distance monitoring setting @min:0.0 @max:1.0 */
    boolean FCA_Setting;            /* Forward collision alert setting @min:0.0 @max:1.0 */
    boolean SLD_Switch;
  } AccLeverInput_t;  /* Driver ACC lever input controls @vaddr:FCT_MEAS_ID_ACC_LEVER_INPUT @cycleid:FCT_VEH @vname:AccLeverInput */

};  // End of namespace AccLeverV6

//
// Main ACC conversion class
//

class CConvAccLever : public CSimConverterBase
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

  AccLeverV1::AccLeverInput_t m_AccLeverInputV1;
  AccLeverV2::AccLeverInput_t m_AccLeverInputV2;
  AccLeverV6::AccLeverInput_t m_AccLeverInputV6;

  void InitV1(AccLeverV1::AccLeverInput_t & Dest);
  void InitV2(AccLeverV2::AccLeverInput_t & Dest);
  void InitV6(AccLeverV6::AccLeverInput_t & Dest);

public:

  static const char* GetConverterTypeName()
  {
    return "AccLeverInput";
  }

  CConvAccLever(void);
  virtual ~CConvAccLever(void);

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
  static CVersionInfoImpl ACC_LEVER_INPUT_V1_VERSION;
  static CVersionInfoImpl ACC_LEVER_INPUT_V2_VERSION;
  static CVersionInfoImpl ACC_LEVER_INPUT_V6_VERSION;

  enum eRoadVersions
  {
    ACC_LEVER_DUMMY_INPUT,
    ACC_LEVER_INPUT_V1,
    ACC_LEVER_INPUT_V2,
    ACC_LEVER_INPUT_V6,
    ACC_LEVER_INPUT_VERSION_COUNT
  };
  static unsigned long SUPPORTED_SIZE[ACC_LEVER_INPUT_VERSION_COUNT];
  static const CVersionInfoImpl * const ACC_LEVER_INPUT_VERSIONS[ACC_LEVER_INPUT_VERSION_COUNT];
};

CVersionInfoImpl  CConvAccLever::BASE_VERSION(0, 0, 0);
CVersionInfoImpl  CConvAccLever::ACC_LEVER_INPUT_V1_VERSION(0, 0, 1);
CVersionInfoImpl  CConvAccLever::ACC_LEVER_INPUT_V2_VERSION(0, 0, 2);
CVersionInfoImpl  CConvAccLever::ACC_LEVER_INPUT_V6_VERSION(0, 0, 6);

static uint32 DummyVersion = 0xFFFFFFFFu;

unsigned long CConvAccLever::SUPPORTED_SIZE[CConvAccLever::ACC_LEVER_INPUT_VERSION_COUNT]=
{
  sizeof(DummyVersion),     //!< Special dummy for 4 byte version number only (i.e.: no ACC interface of FCT component)
  sizeof(AccLeverV1::AccLeverInput_t),
  sizeof(AccLeverV2::AccLeverInput_t),
  sizeof(AccLeverV6::AccLeverInput_t)
};

const CVersionInfoImpl * const CConvAccLever::ACC_LEVER_INPUT_VERSIONS[CConvAccLever::ACC_LEVER_INPUT_VERSION_COUNT] =
{
  &BASE_VERSION,
  &ACC_LEVER_INPUT_V1_VERSION,
  &ACC_LEVER_INPUT_V2_VERSION,
  &ACC_LEVER_INPUT_V6_VERSION
};

CConvAccLever::CConvAccLever(void)
: CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT), m_AccLeverInputV1(), m_AccLeverInputV2()
{
  InitV1(m_AccLeverInputV1);
  InitV2(m_AccLeverInputV2);
  InitV6(m_AccLeverInputV6);
}

CConvAccLever::~CConvAccLever(void)
{
}

void CConvAccLever::InitV1(AccLeverV1::AccLeverInput_t & Dest)
{
  memset(&Dest, 0, sizeof(Dest));
  Dest.uiVersionNumber  = 1;
}

void CConvAccLever::InitV2(AccLeverV2::AccLeverInput_t & Dest)
{
  memset(&Dest, 0, sizeof(Dest));
  Dest.uiVersionNumber  = 2;
  Dest.eSignalState     = 0;  // ALGO_SIG_STATE_INIT
}

void CConvAccLever::InitV6(AccLeverV6::AccLeverInput_t & Dest)
{
  memset(&Dest, 0, sizeof(Dest));
  Dest.uiVersionNumber  = 6;
}

long CConvAccLever::ConvertData(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo, 
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo* pProvidePortVersionInfo, 
    void* pPPortData,
    void** pOutData, unsigned long& ulOutSize)
{
  long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  // See if conversion is needed
  if ((eRPortType == ePPortType) && (ulRPortSize == ulPPortSize) && ((pProvidePortVersionInfo == NULL) || (requestPortVersionInfo.Equals(pProvidePortVersionInfo))))
  {
    // Ports match 1-1 no conversion needed
    *pOutData = pPPortData;
    ulOutSize = ulPPortSize;
    lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
  }
  else if (ulPPortSize >= 4)
  {
    const uint32 version = *reinterpret_cast<const uint32*>(pPPortData);
    // Conversion needed: on first level see what destination we have to convert to
    if ((ulRPortSize == sizeof(AccLeverV6::AccLeverInput_t)) && ((requestPortVersionInfo.Equals(&ACC_LEVER_INPUT_V6_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      AccLeverV6::AccLeverInput_t & Dest = m_AccLeverInputV6;
      switch (version)
      {
      case 0:
      case 1:
        if (sizeof(AccLeverV1::AccLeverInput_t) == ulPPortSize)
        {
          const AccLeverV1::AccLeverInput_t & Src = *reinterpret_cast<AccLeverV1::AccLeverInput_t*>(pPPortData);
          AccLeverV2::AccLeverInput_t & Dest = m_AccLeverInputV2;
          Dest.uiVersionNumber  = 6;
          Dest.eSignalState     = 1;  // AL_SIG_STATE_OK
          Dest.Cancel           = Src.Cancel;
          Dest.Resume           = Src.Resume;
          Dest.AccelSwitch      = Src.AccelSwitch;
          Dest.DecelSwitch      = Src.DecelSwitch;
          Dest.MainMode         = Src.MainMode;
          Dest.HeadwayInc       = Src.HeadwayInc;
          Dest.HeadwayDec       = Src.HeadwayDec;
          Dest.Headway          = Src.Headway;
          Dest.DM_Setting       = Src.DM_Setting;
          Dest.FCA_Setting      = Src.FCA_Setting;
          *pOutData = &Dest;
          ulOutSize = sizeof(Dest);
          lRet = SIM_ERR_OK;
        }
        break;
      case 2:
        if (sizeof(AccLeverV2::AccLeverInput_t) == ulPPortSize)
        {
          const AccLeverV2::AccLeverInput_t & Src = *reinterpret_cast<AccLeverV2::AccLeverInput_t*>(pPPortData);
          AccLeverV2::AccLeverInput_t & Dest = m_AccLeverInputV2;
          Dest.uiVersionNumber  = 6;
          Dest.eSignalState     = 1;  // AL_SIG_STATE_OK
          Dest.Cancel           = Src.Cancel;
          Dest.Resume           = Src.Resume;
          Dest.AccelSwitch      = Src.AccelSwitch;
          Dest.DecelSwitch      = Src.DecelSwitch;
          Dest.MainMode         = Src.MainMode;
          Dest.HeadwayInc       = Src.HeadwayInc;
          Dest.HeadwayDec       = Src.HeadwayDec;
          Dest.Headway          = Src.Headway;
          Dest.DM_Setting       = Src.DM_Setting;
          Dest.FCA_Setting      = Src.FCA_Setting;
          *pOutData = &Dest;
          ulOutSize = sizeof(Dest);
          lRet = SIM_ERR_OK;
        }
        break;
      case 6:
        if (sizeof(AccLeverV6::AccLeverInput_t) == ulPPortSize)
        {
          *pOutData = pPPortData;
          ulOutSize = ulPPortSize;
          lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
        }
        break;
      default:
        break;
      }
    }
    else if ((ulRPortSize == sizeof(AccLeverV2::AccLeverInput_t)) && ((requestPortVersionInfo.Equals(&ACC_LEVER_INPUT_V2_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      AccLeverV2::AccLeverInput_t & Dest = m_AccLeverInputV2;
      switch (version)
      {
      case 0:
      case 1:
        if (sizeof(AccLeverV1::AccLeverInput_t) == ulPPortSize)
        {
          const AccLeverV1::AccLeverInput_t & Src = *reinterpret_cast<AccLeverV1::AccLeverInput_t*>(pPPortData);
          AccLeverV2::AccLeverInput_t & Dest = m_AccLeverInputV2;
          Dest.uiVersionNumber  = 2;
          Dest.eSignalState     = 1;  // AL_SIG_STATE_OK
          Dest.Cancel           = Src.Cancel;
          Dest.Resume           = Src.Resume;
          Dest.AccelSwitch      = Src.AccelSwitch;
          Dest.DecelSwitch      = Src.DecelSwitch;
          Dest.MainMode         = Src.MainMode;
          Dest.HeadwayInc       = Src.HeadwayInc;
          Dest.HeadwayDec       = Src.HeadwayDec;
          Dest.Headway          = Src.Headway;
          Dest.DM_Setting       = Src.DM_Setting;
          Dest.FCA_Setting      = Src.FCA_Setting;
          *pOutData = &Dest;
          ulOutSize = sizeof(Dest);
          lRet = SIM_ERR_OK;
        }
        break;
      case 2:
        if (sizeof(AccLeverV2::AccLeverInput_t) == ulPPortSize)
        {
          *pOutData = pPPortData;
          ulOutSize = ulPPortSize;
          lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
        }
        break;
      default:
        break;
      }
    }
    else if ((ulRPortSize == sizeof(AccLeverV1::AccLeverInput_t)) && ((requestPortVersionInfo.Equals(&ACC_LEVER_INPUT_V1_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      switch (version)
      {
      case 0:
      case 1:
        if (sizeof(AccLeverV1::AccLeverInput_t) == ulPPortSize)
        {
          *pOutData = pPPortData;
          ulOutSize = ulPPortSize;
          lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
        }
        break;
      case 2:
        if (sizeof(AccLeverV2::AccLeverInput_t) == ulPPortSize)
        {
          const AccLeverV2::AccLeverInput_t & Src = *reinterpret_cast<AccLeverV2::AccLeverInput_t*>(pPPortData);
          AccLeverV1::AccLeverInput_t & Dest = m_AccLeverInputV1;
          Dest.uiVersionNumber  = 1;
          Dest.Cancel           = Src.Cancel;
          Dest.Resume           = Src.Resume;
          Dest.AccelSwitch      = Src.AccelSwitch;
          Dest.DecelSwitch      = Src.DecelSwitch;
          Dest.MainMode         = Src.MainMode;
          Dest.HeadwayInc       = Src.HeadwayInc;
          Dest.HeadwayDec       = Src.HeadwayDec;
          Dest.Headway          = Src.Headway;
          Dest.DM_Setting       = Src.DM_Setting;
          Dest.FCA_Setting      = Src.FCA_Setting;
          *pOutData = &Dest;
          ulOutSize = sizeof(Dest);
          lRet = SIM_ERR_OK;
        }
        break;
      default:
        break;
      }
    }
    else if (ulRPortSize == 4u)
    {
      // Special 4 byte input port : FCT does not really need ACC lever information only dummy version number
      *pOutData = &DummyVersion;
      ulOutSize = sizeof(DummyVersion);
      lRet = SIM_ERR_OK;
    }
    else
    {
      // Destination (request port) format not known
      lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
    }
  }
  else
  {
    // Provide port smaller than version number?!
    lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  }
  return lRet;
}

/** returns: 
 *   SIM_ERR_OK - when this value can be used
 *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implememnted here
 *                                            and the default value from Request Port must be used
 */
long CConvAccLever::GetDefaultValue(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo, 
    void** pDefaultData, unsigned long& ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == sizeof(AccLeverV6::AccLeverInput_t)) &&
      ((requestPortVersionInfo.Equals(&ACC_LEVER_INPUT_V6_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      InitV6(m_AccLeverInputV6);
      *pDefaultData = &m_AccLeverInputV6;
      ulDefaultSize = sizeof(m_AccLeverInputV6);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(AccLeverV2::AccLeverInput_t)) &&
      ((requestPortVersionInfo.Equals(&ACC_LEVER_INPUT_V2_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      InitV2(m_AccLeverInputV2);
      *pDefaultData = &m_AccLeverInputV2;
      ulDefaultSize = sizeof(m_AccLeverInputV2);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(AccLeverV1::AccLeverInput_t)) &&
      ((requestPortVersionInfo.Equals(&ACC_LEVER_INPUT_V1_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      InitV1(m_AccLeverInputV1);
      *pDefaultData = &m_AccLeverInputV1;
      ulDefaultSize = sizeof(m_AccLeverInputV1);
      lRet = SIM_ERR_OK;
    }
    else if (ulRPortSize == sizeof(DummyVersion))
    {
      *pDefaultData = &DummyVersion;
      ulDefaultSize = sizeof(DummyVersion);
      lRet = SIM_ERR_OK;
    }
  }
  return lRet;
}

// used to check if an unversioned PPort is compatible with a certain version of RPort
bool CConvAccLever::IsVersionCompatibleWithType(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo, 
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize)
{
  bool bResult = false;

  if (ePPortType == eRPortType)
  {
    // Check if ports are of equal size & type. In this case always declare them compatible
    if (ulRPortSize == ulPPortSize)
    {
      bResult = true;
    }
    else
    {
      // Conversion necessary
      if ((ulRPortSize == sizeof(AccLeverV2::AccLeverInput_t)) && ((requestPortVersionInfo.Equals(&ACC_LEVER_INPUT_V2_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        for (unsigned int i =0; (i<CConvAccLever::ACC_LEVER_INPUT_VERSION_COUNT) && (!bResult);i++)
        {
          if (ulPPortSize == SUPPORTED_SIZE[i])
          {
            bResult = true;
          }
        }
      }
      else if ((ulRPortSize == sizeof(AccLeverV1::AccLeverInput_t)) && ((requestPortVersionInfo.Equals(&ACC_LEVER_INPUT_V1_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        for (unsigned int i =0; (i<CConvAccLever::ACC_LEVER_INPUT_VERSION_COUNT) && (!bResult);i++)
        {
          if (ulPPortSize == SUPPORTED_SIZE[i])
          {
            bResult = true;
          }
        }
      }
      else if (ulRPortSize == sizeof(DummyVersion))
      {
        bResult = true;
      }
    }
  }
  return bResult;
}

// used to check if ports are compatible between different versions
bool CConvAccLever::AreVersionsCompatible(
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
    bool bProvideOK = false, bRequestOK = false;
    for (unsigned int i =0; (i<CConvAccLever::ACC_LEVER_INPUT_VERSION_COUNT) && ((!bProvideOK) || (!bRequestOK));i++)
    {
      if ((ulPPortSize == SUPPORTED_SIZE[i]) && ((providePortVersionInfo.Equals(ACC_LEVER_INPUT_VERSIONS[i])) || (providePortVersionInfo.Equals(&BASE_VERSION))))
      {
        bProvideOK = true;
      }
      if ((ulRPortSize == SUPPORTED_SIZE[i]) && ((requestPortVersionInfo.Equals(ACC_LEVER_INPUT_VERSIONS[i])) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        bRequestOK = true;
      }
    }
    bResult = bProvideOK && bRequestOK;
  }
  return bResult;
}

//
// CreateAccLeverConvClass : single externally visible function of module
//

IConverter * CreateAccLeverConvClass(void)
{
  return new CConvAccLever();
}
