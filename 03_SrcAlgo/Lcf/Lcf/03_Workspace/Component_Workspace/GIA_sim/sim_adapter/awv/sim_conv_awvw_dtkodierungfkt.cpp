/*! \file **********************************************************************

  COMPANY:         Continental

  PROJECT:         Simulation

  COMPONENT:       sim_adapter em

  MODULNAME:       sim_conv_awvw_dtkodierungfkt.cpp

  DESCRIPTION:

  AUTHOR:          Thomas Berndt

  CREATION DATE:   30.1.2015

  VERSION:         $Revision: 1.1 $

  ---*/ /*---
  CHANGES:         $Log: sim_conv_awvw_dtkodierungfkt.cpp  $
  CHANGES:         Revision 1.1 2017/08/10 13:14:56CEST uid34177 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/awv/project.pj
  CHANGES:         Revision 1.1 2015/01/30 08:39:26CET Berndt, Thomas01 (berndtt1) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/sim_adapter/awv/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */

#include "sim_adapter_cfg.h"
#include "sim_conv_awvw_dtkodierungfkt.h"
#include "sim_versioninfo_impl.h"

/** 
* @brief The standard AUTOSAR type boolean shall be implemented on basis of an eight bits long 
*        unsigned integer.
* @implements boolean_type
*/
typedef unsigned char boolean;
/* Boolean types */
typedef boolean Boolean                                              /* [Satisfies_rte sws 1188] */;


namespace AwvwDtKodierungFkt_V1
{
  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    Boolean Abstandswarnung;
    Boolean Ausloesedokumentation;                                   /* i_b_AWV_Codierung_Auslösedokumentation */
    Boolean Bremsruck;                                               /* i_b_AWV_Codierung_Bremsruck */
    Boolean CityAnb;                                                 /* i_b_AWV_Codierung_City_ANB */
    Boolean Hba;                                                     /* i_b_AWV_Codierung_HBA */
    Boolean Prefill;                                                 /* i_b_AWV_Codierung_Prefill */
    Boolean AtbStandard;                                             /* i_b_AWV_Codierung_TB_standard */
    Boolean AtbErweitert;                                            /* i_b_AWV_Codierung_TB_erweitert */
    Boolean Vorwarnung;                                              /* i_b_AWV_Codierung_Vorwarnung */
    Boolean VFgs;                                                    /* i_b_AWV_Codierung_vFGS */
    Boolean VFgsVorwarnung;                                          /* i_b_AWV_Codierung_vFGS_Vorwarnung */
    Boolean Zbr;                                                     /* i_b_AWV_Codierung_ZB */
    Boolean Demomodus;                                               /* i_b_AWV_Demomodus_aktivierbar */
  } DTKodierungFKT;
} // end of AwvwDtKodierungFkt_V1



namespace AwvwDtKodierungFkt_V2
{
  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    Boolean Abstandswarnung;
    Boolean Ausloesedokumentation;                                   /* i_b_AWV_Codierung_Auslösedokumentation */
    Boolean Bremsruck;                                               /* i_b_AWV_Codierung_Bremsruck */
    Boolean CityAnb;                                                 /* i_b_AWV_Codierung_City_ANB */
    Boolean Hba;                                                     /* i_b_AWV_Codierung_HBA */
    Boolean Prefill;                                                 /* i_b_AWV_Codierung_Prefill */
    Boolean AtbStandard;                                             /* i_b_AWV_Codierung_TB_standard */
    Boolean AtbErweitert;                                            /* i_b_AWV_Codierung_TB_erweitert */
    Boolean Vorwarnung;                                              /* i_b_AWV_Codierung_Vorwarnung */
    Boolean VFgs;                                                    /* i_b_AWV_Codierung_vFGS */
    Boolean VFgsVorwarnung;                                          /* i_b_AWV_Codierung_vFGS_Vorwarnung */
    Boolean Zbr;                                                     /* i_b_AWV_Codierung_ZB */
    Boolean Demomodus;                                               /* i_b_AWV_Demomodus_aktivierbar */
    Boolean EcdAnlauf;                                               /* i_b_AWV_Codierung_ECD_Anlauf */
    unsigned __int8 Getriebetyp;                                     /* i_n_UEB_Fahrzeugkonstante_Getriebetyp_Codierung */
  } DTKodierungFKT;
} // end of AwvwDtKodierungFkt_V2


class CConvAwvwDtKodierungFkt : public CSimConverterBase
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

  AwvwDtKodierungFkt_V1::DTKodierungFKT m_BufV1;
  AwvwDtKodierungFkt_V2::DTKodierungFKT m_BufV2;

  // Initialization
  template <typename T> static void InitVx (T & Dest)
  {
    ::memset(&Dest, 0, sizeof(Dest));
  }

public:

  static const char *GetConverterTypeName()
  {
    return "DTKodierungFKT";
  }

  CConvAwvwDtKodierungFkt(void);
  virtual ~CConvAwvwDtKodierungFkt(void);

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
  enum AVWV_DTKodierungFkt
  {
    AWVWDTKODIERUNGFKT_V1,
    AWVWDTKODIERUNGFKT_V2,
    AWVWDTKODIERUNGFKT_VERSION_COUNT
  };

  static CVersionInfoImpl BASE_VERSION;

  static const CVersionInfoImpl * const EM_OBJECTLIST_CAM_INPUT_VERSIONS[AWVWDTKODIERUNGFKT_VERSION_COUNT];

  static const unsigned long SUPPORTED_SIZE[AWVWDTKODIERUNGFKT_VERSION_COUNT];

  bool IsPortSupported(unsigned long ulPortSize, const IVersionInfo *pPortVersion) const
  {
    for (int nI = 0; nI < AWVWDTKODIERUNGFKT_VERSION_COUNT; nI++)
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

CVersionInfoImpl CConvAwvwDtKodierungFkt::BASE_VERSION(0, 0, 0);

const CVersionInfoImpl * const CConvAwvwDtKodierungFkt::EM_OBJECTLIST_CAM_INPUT_VERSIONS[CConvAwvwDtKodierungFkt::AWVWDTKODIERUNGFKT_VERSION_COUNT] =
{
  &BASE_VERSION,
  &BASE_VERSION
};

const unsigned long CConvAwvwDtKodierungFkt::SUPPORTED_SIZE[CConvAwvwDtKodierungFkt::AWVWDTKODIERUNGFKT_VERSION_COUNT] =
{
  sizeof(AwvwDtKodierungFkt_V1::DTKodierungFKT),
  sizeof(AwvwDtKodierungFkt_V2::DTKodierungFKT)
};

__inline void v_Convert_v1_to_v2 (AwvwDtKodierungFkt_V2::DTKodierungFKT * const pDest,
  const AwvwDtKodierungFkt_V1::DTKodierungFKT * const pSrc)
{
  memcpy(pDest, pSrc, sizeof (*pSrc));
  pDest->EcdAnlauf = 0;
  pDest->Getriebetyp = 0;
}

CConvAwvwDtKodierungFkt::CConvAwvwDtKodierungFkt(void) : CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT), m_BufV1(), m_BufV2()
{
  InitVx(m_BufV1);
  InitVx(m_BufV2);
}

CConvAwvwDtKodierungFkt::~CConvAwvwDtKodierungFkt(void)
{
}

long CConvAwvwDtKodierungFkt::ConvertData(
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
        const AwvwDtKodierungFkt_V1::DTKodierungFKT *pSrc = reinterpret_cast<AwvwDtKodierungFkt_V1::DTKodierungFKT *>(pPPortData);
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
long CConvAwvwDtKodierungFkt::GetDefaultValue(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  void **pDefaultData, unsigned long &ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == sizeof(AwvwDtKodierungFkt_V2::DTKodierungFKT)) && (BASE_VERSION.Equals(&requestPortVersionInfo)))
    {
      InitVx(m_BufV2);
      *pDefaultData = &m_BufV2;
      ulDefaultSize = sizeof(AwvwDtKodierungFkt_V2::DTKodierungFKT);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(AwvwDtKodierungFkt_V1::DTKodierungFKT)) && BASE_VERSION.Equals(&requestPortVersionInfo))
    {
      InitVx(m_BufV1);
      *pDefaultData = &m_BufV1;
      ulDefaultSize = sizeof(AwvwDtKodierungFkt_V1::DTKodierungFKT);
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
bool CConvAwvwDtKodierungFkt::IsVersionCompatibleWithType(
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
bool CConvAwvwDtKodierungFkt::AreVersionsCompatible(
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
IConverter * CreateAwvwDtKodierungFktConvClass(void)
{
  return new CConvAwvwDtKodierungFkt();
}
