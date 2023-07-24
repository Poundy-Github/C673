/*! \file **********************************************************************

  COMPANY:         Continental

  PROJECT:         Simulation

  COMPONENT:       sim_adapter em

  MODULNAME:       sim_conv_fahrpedalwert.cpp

  DESCRIPTION:

  AUTHOR:          Thomas Berndt

  CREATION DATE:   30.1.2015

  VERSION:         $Revision: 1.1 $

  ---*/ /*---
  CHANGES:         $Log: sim_conv_fahrpedalwert.cpp  $
  CHANGES:         Revision 1.1 2021/12/13 17:20:34CET Wang, David (Wangd3) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_adapter/awv/project.pj
  CHANGES:         Revision 1.1 2017/08/10 13:14:59CEST uid34177 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/awv/project.pj
  CHANGES:         Revision 1.1 2015/01/30 10:26:34CET Berndt, Thomas01 (berndtt1) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/sim_adapter/awv/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */

#include "sim_adapter_cfg.h"
#include "sim_conv_fahrpedalwert.h"
#include "sim_versioninfo_impl.h"

/** 
* @brief The standard AUTOSAR type boolean shall be implemented on basis of an eight bits long 
*        unsigned integer.
* @implements boolean_type
*/
typedef unsigned char boolean;
/* Boolean types */
typedef boolean Boolean                                              /* [Satisfies_rte sws 1188] */;


namespace Fahrpedalwert_V1
{
  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned __int8 Rohwert;                                         /* s_MO_Fahrpedalrohwert (Quelle: Motor_20.MO_Fahrpedalrohwert_01) */
    Boolean QBit;                                                    /* s_MO_QBit_Fahrpedalwerte (Quelle: Motor_20.MO_QBit_Fahrpedalwerte_01) */
  } DTFahrpedalwert;
} // end of Fahrpedalwert_V1



namespace Fahrpedalwert_V2
{
  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned __int8 Rohwert;                                         /* s_MO_Fahrpedalrohwert (Quelle: Motor_20.MO_Fahrpedalrohwert_01) */
    Boolean QBit;                                                    /* s_MO_QBit_Fahrpedalwerte (Quelle: Motor_20.MO_QBit_Fahrpedalwerte_01) */
    unsigned __int8 Skaliert;
  } DTFahrpedalwert;
} // end of Fahrpedalwert_V2


class CConvFahrpedalwert : public CSimConverterBase
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

  Fahrpedalwert_V1::DTFahrpedalwert m_BufV1;
  Fahrpedalwert_V2::DTFahrpedalwert m_BufV2;

  // Initialization
  template <typename T> static void InitVx (T & Dest)
  {
    ::memset(&Dest, 0, sizeof(Dest));
  }

public:

  static const char *GetConverterTypeName()
  {
    return "Fahrpedalwert";
  }

  CConvFahrpedalwert(void);
  virtual ~CConvFahrpedalwert(void);

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
  enum AVWV_Fahrpedalwert
  {
    FAHRPEDALWERT_V1,
    FAHRPEDALWERT_V2,
    FAHRPEDALWERT_VERSION_COUNT
  };

  static CVersionInfoImpl BASE_VERSION;

  static const CVersionInfoImpl * const EM_OBJECTLIST_CAM_INPUT_VERSIONS[FAHRPEDALWERT_VERSION_COUNT];

  static const unsigned long SUPPORTED_SIZE[FAHRPEDALWERT_VERSION_COUNT];

  bool IsPortSupported(unsigned long ulPortSize, const IVersionInfo *pPortVersion) const
  {
    for (int nI = 0; nI < FAHRPEDALWERT_VERSION_COUNT; nI++)
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

CVersionInfoImpl CConvFahrpedalwert::BASE_VERSION(0, 0, 0);

const CVersionInfoImpl * const CConvFahrpedalwert::EM_OBJECTLIST_CAM_INPUT_VERSIONS[CConvFahrpedalwert::FAHRPEDALWERT_VERSION_COUNT] =
{
  &BASE_VERSION,
  &BASE_VERSION
};

const unsigned long CConvFahrpedalwert::SUPPORTED_SIZE[CConvFahrpedalwert::FAHRPEDALWERT_VERSION_COUNT] =
{
  sizeof(Fahrpedalwert_V1::DTFahrpedalwert),
  sizeof(Fahrpedalwert_V2::DTFahrpedalwert)
};

__inline void v_Convert_v1_to_v2 (Fahrpedalwert_V2::DTFahrpedalwert * const pDest,
  const Fahrpedalwert_V1::DTFahrpedalwert * const pSrc)
{
  memcpy(pDest, pSrc, sizeof (*pSrc));
  pDest->Skaliert = 0;
}

CConvFahrpedalwert::CConvFahrpedalwert(void) : CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT), m_BufV1(), m_BufV2()
{
  InitVx(m_BufV1);
  InitVx(m_BufV2);
}

CConvFahrpedalwert::~CConvFahrpedalwert(void)
{
}

long CConvFahrpedalwert::ConvertData(
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
      if ((ulPPortSize == SUPPORTED_SIZE[0]) &&
        ((pProvidePortVersionInfo == NULL) || pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      {
        const Fahrpedalwert_V1::DTFahrpedalwert *pSrc = reinterpret_cast<Fahrpedalwert_V1::DTFahrpedalwert *>(pPPortData);
        // The decide which version we are converting to
        if ((ulRPortSize == SUPPORTED_SIZE[1]) &&
          (requestPortVersionInfo.Equals(&BASE_VERSION)))
        {
          // Destination port of V2 is m_BufV2
          v_Convert_v1_to_v2(&m_BufV2, pSrc);
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
long CConvFahrpedalwert::GetDefaultValue(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  void **pDefaultData, unsigned long &ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == sizeof(Fahrpedalwert_V2::DTFahrpedalwert)) && (BASE_VERSION.Equals(&requestPortVersionInfo)))
    {
      InitVx(m_BufV2);
      *pDefaultData = &m_BufV2;
      ulDefaultSize = sizeof(Fahrpedalwert_V2::DTFahrpedalwert);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(Fahrpedalwert_V1::DTFahrpedalwert)) && BASE_VERSION.Equals(&requestPortVersionInfo))
    {
      InitVx(m_BufV1);
      *pDefaultData = &m_BufV1;
      ulDefaultSize = sizeof(Fahrpedalwert_V1::DTFahrpedalwert);
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
bool CConvFahrpedalwert::IsVersionCompatibleWithType(
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
bool CConvFahrpedalwert::AreVersionsCompatible(
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
IConverter * CreateFahrpedalwertConvClass(void)
{
  return new CConvFahrpedalwert();
}
