/*! \file **********************************************************************

  COMPANY:         Continental

  PROJECT:         Simulation

  COMPONENT:       sim_adapter em

  MODULNAME:       sim_conv_bremsung.cpp

  DESCRIPTION:

  AUTHOR:          Thomas Berndt

  CREATION DATE:   30.1.2015

  VERSION:         $Revision: 1.1 $

  ---*/ /*---
  CHANGES:         $Log: sim_conv_bremsung.cpp  $
  CHANGES:         Revision 1.1 2017/08/10 13:14:56CEST uid34177 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/awv/project.pj
  CHANGES:         Revision 1.1 2015/05/22 11:32:30CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/sim_adapter/awv/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */

#include "sim_adapter_cfg.h"
#include "sim_conv_bremsung.h"
#include "sim_versioninfo_impl.h"

/** 
* @brief The standard AUTOSAR type boolean shall be implemented on basis of an eight bits long 
*        unsigned integer.
* @implements boolean_type
*/
typedef unsigned char boolean;
/* Boolean types */
typedef boolean Boolean                                              /* [Satisfies_rte sws 1188] */;


namespace Bremsung_V1
{
  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    Boolean ZbrFreigabe;                                             /* [[DF-AWV-69]] i_b_AWV_Zielbremsung_aktiv */
    Boolean AtbFreigabe;                                             /* [[DF-AWV-222]] i_b_AWV_Teilbremsung_aktiv */
    Boolean AtbErweitert;                                            /* [[DF-AWV-223]] i_b_AWV_Teilbremsung_erw_aktiv */
    Boolean AnbAnforderung;                                          /* [[DF-AWV-172]] s_ANB_CM_Anforderung (Ziel: ACC_10.ANB_CM_Anforderung) */
    float Verzoegerung;                                              /* [[DF-AWV-209]] s_ANB_Verzoegerungsanforderung (Ziel: ACC_10.ANB_Zielbrems_Teilbrems_Verz_Anf) */
  } DTBremsung;                                                      /* [[DF-AWV-443]] */
} // end of Bremsung_V1



namespace Bremsung_V2
{
  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    Boolean ZbrFreigabe;                                             /* [[DF-AWV-69]] i_b_AWV_Zielbremsung_aktiv */
    Boolean AtbFreigabe;                                             /* [[DF-AWV-222]] i_b_AWV_Teilbremsung_aktiv */
    Boolean AtbErweitert;                                            /* [[DF-AWV-223]] i_b_AWV_Teilbremsung_erw_aktiv */
    Boolean AtbVFgs;                                                 /* [[DF-AWV-943]] i_b_AWV_vFGS_Teilbremsung_aktiv */
    Boolean AnbAnforderung;                                          /* [[DF-AWV-172]] s_ANB_CM_Anforderung (Ziel: ACC_10.ANB_CM_Anforderung) */
    float Verzoegerung;                                              /* [[DF-AWV-209]] s_ANB_Verzoegerungsanforderung (Ziel: ACC_10.ANB_Zielbrems_Teilbrems_Verz_Anf) */
  } DTBremsung;                                                      /* [[DF-AWV-443]] */
} // end of Bremsung_V2


class CConvBremsung : public CSimConverterBase
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

  Bremsung_V1::DTBremsung m_BufV1;
  Bremsung_V2::DTBremsung m_BufV2;

  // Initialization
  template <typename T> static void InitVx (T & Dest)
  {
    ::memset(&Dest, 0, sizeof(Dest));
  }

public:

  static const char *GetConverterTypeName()
  {
    return "DTBremsung";
  }

  CConvBremsung(void);
  virtual ~CConvBremsung(void);

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
  enum AVWV_Bremsung
  {
    BREMSUNG_V1,
    BREMSUNG_V2,
    BREMSUNG_VERSION_COUNT
  };

  static CVersionInfoImpl BASE_VERSION;

  static const CVersionInfoImpl * const EM_OBJECTLIST_CAM_INPUT_VERSIONS[BREMSUNG_VERSION_COUNT];

  static const unsigned long SUPPORTED_SIZE[BREMSUNG_VERSION_COUNT];

  bool IsPortSupported(unsigned long ulPortSize, const IVersionInfo *pPortVersion) const
  {
    for (int nI = 0; nI < BREMSUNG_VERSION_COUNT; nI++)
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

CVersionInfoImpl CConvBremsung::BASE_VERSION(0, 0, 0);

const CVersionInfoImpl * const CConvBremsung::EM_OBJECTLIST_CAM_INPUT_VERSIONS[CConvBremsung::BREMSUNG_VERSION_COUNT] =
{
  &BASE_VERSION,
  &BASE_VERSION
};

const unsigned long CConvBremsung::SUPPORTED_SIZE[CConvBremsung::BREMSUNG_VERSION_COUNT] =
{
  sizeof(Bremsung_V1::DTBremsung),
  sizeof(Bremsung_V2::DTBremsung)
};

__inline void v_Convert_v1_to_v2 (Bremsung_V2::DTBremsung * const pDest,
  const Bremsung_V1::DTBremsung * const pSrc)
{
  pDest->ZbrFreigabe    = pSrc->ZbrFreigabe;
  pDest->AtbFreigabe    = pSrc->AtbFreigabe;
  pDest->AtbErweitert   = pSrc->AtbErweitert;
  pDest->AtbVFgs        = 0;
  pDest->AnbAnforderung = pSrc->AnbAnforderung;
  pDest->Verzoegerung   = pSrc->Verzoegerung;
}

__inline void v_Convert_v2_to_v1 (Bremsung_V1::DTBremsung * const pDest,
  const Bremsung_V2::DTBremsung * const pSrc)
{
  pDest->ZbrFreigabe    = pSrc->ZbrFreigabe;
  pDest->AtbFreigabe    = pSrc->AtbFreigabe;
  pDest->AtbErweitert   = pSrc->AtbErweitert;
  pDest->AnbAnforderung = pSrc->AnbAnforderung;
  pDest->Verzoegerung   = pSrc->Verzoegerung;
}

CConvBremsung::CConvBremsung(void) : CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT), m_BufV1(), m_BufV2()
{
  InitVx(m_BufV1);
  InitVx(m_BufV2);
}

CConvBremsung::~CConvBremsung(void)
{
}

long CConvBremsung::ConvertData(
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
      if ((ulPPortSize == SUPPORTED_SIZE[BREMSUNG_V1]) &&
        ((pProvidePortVersionInfo == NULL) || pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      {
        const Bremsung_V1::DTBremsung *pSrc = reinterpret_cast<Bremsung_V1::DTBremsung *>(pPPortData);
        // The decide which version we are converting to
        if ((ulRPortSize == SUPPORTED_SIZE[BREMSUNG_V2]) &&
          (requestPortVersionInfo.Equals(&BASE_VERSION)))
        {
          // Destination port of V2 is m_BufV2
          v_Convert_v1_to_v2(&m_BufV2, pSrc);
          *pOutData = &m_BufV2;
          ulOutSize = sizeof(m_BufV2);
          lRet = SIM_ERR_OK;
        }
      }
      else if ((ulPPortSize == SUPPORTED_SIZE[BREMSUNG_V2]) &&
        ((pProvidePortVersionInfo == NULL) || pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      {
        const Bremsung_V2::DTBremsung *pSrc = reinterpret_cast<Bremsung_V2::DTBremsung *>(pPPortData);
        // The decide which version we are converting to
        if ((ulRPortSize == SUPPORTED_SIZE[BREMSUNG_V1]) &&
          (requestPortVersionInfo.Equals(&BASE_VERSION)))
        {
          // Destination port of V1 is m_BufV1
          v_Convert_v2_to_v1(&m_BufV1, pSrc);
          *pOutData = &m_BufV1;
          ulOutSize = sizeof(m_BufV1);
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
long CConvBremsung::GetDefaultValue(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  void **pDefaultData, unsigned long &ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == SUPPORTED_SIZE[BREMSUNG_V2]) && (BASE_VERSION.Equals(&requestPortVersionInfo)))
    {
      InitVx(m_BufV2);
      *pDefaultData = &m_BufV2;
      ulDefaultSize = sizeof(m_BufV2);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[BREMSUNG_V1]) && BASE_VERSION.Equals(&requestPortVersionInfo))
    {
      InitVx(m_BufV1);
      *pDefaultData = &m_BufV1;
      ulDefaultSize = sizeof(m_BufV1);
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
bool CConvBremsung::IsVersionCompatibleWithType(
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
bool CConvBremsung::AreVersionsCompatible(
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
IConverter * CreateDTBremsungConvClass(void)
{
  return new CConvBremsung();
}
