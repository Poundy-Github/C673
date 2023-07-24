/*! \file **********************************************************************

  COMPANY:         Continental

  PROJECT:         Simulation

  COMPONENT:       sim_adapter em

  MODULNAME:       sim_conv_dtkvpar.cpp

  DESCRIPTION:

  AUTHOR:          Thomas Berndt

  CREATION DATE:   30.1.2015

  VERSION:         $Revision: 1.1 $

  ---*/ /*---
  CHANGES:         $Log: sim_conv_dtkvpar.cpp  $
  CHANGES:         Revision 1.1 2021/12/13 17:20:32CET Wang, David (Wangd3) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_adapter/awv/project.pj
  CHANGES:         Revision 1.1 2017/08/10 13:14:58CEST uid34177 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/awv/project.pj
  CHANGES:         Revision 1.1 2015/01/30 11:03:59CET Berndt, Thomas01 (berndtt1) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/sim_adapter/awv/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */

#include "sim_adapter_cfg.h"
#include "sim_conv_dtkvpar.h"
#include "sim_versioninfo_impl.h"

/**
* @brief The standard AUTOSAR type boolean shall be implemented on basis of an eight bits long
*        unsigned integer.
* @implements boolean_type
*/
typedef unsigned char boolean;
/* Boolean types */
typedef boolean Boolean                                                        /* [Satisfies_rte sws 1188] */;


namespace DTKvPar_V1
{
  typedef unsigned __int8 UInt8_A2[2];                                         /* [Satisfies_rte sws 1189] */
  typedef unsigned __int16 UInt16_A5[5];                                       /* [Satisfies_rte sws 1189] */
  typedef float Float_A2[2];                                                   /* [Satisfies_rte sws 1189] */
  typedef float Float_A3[3];                                                   /* [Satisfies_rte sws 1189] */
  typedef float Float_A4[4];                                                   /* [Satisfies_rte sws 1189] */
  typedef float Float_A5[5];                                                   /* [Satisfies_rte sws 1189] */
  typedef float Float_A6[6];                                                   /* [Satisfies_rte sws 1189] */
  typedef float Float_A7[7];                                                   /* [Satisfies_rte sws 1189] */

  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    UInt8_A2 X;
    Float_A2 Y;
  } UInt8_Float_A2;

  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    Float_A2 X;
    Float_A2 Y;
  } Float_Float_A2;

  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    Float_A3 X;
    Float_A3 Y;
  } Float_Float_A3;

  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    Float_A4 X;
    Float_A4 Y;
  } Float_Float_A4;

  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    UInt16_A5 X;
    Float_A5 Y;
  } UInt16_Float_A5;

  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    Float_A5 X;
    Float_A5 Y;
  } Float_Float_A5;

  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    Float_A6 X;
    Float_A6 Y;
  } Float_Float_A6;

  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    Float_A7 X;
    Float_A7 Y;
  } Float_Float_A7;
  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    unsigned __int16 ABSTANDSWARNUNG_ZEITLUECKE;                               /* p_t_AWV_AbstWarnung_Zeitluecke */
    unsigned __int16 ABSTANDSWARNUNG_ZEITLUECKE_DAUER_UNTERSCHRITTEN;          /* p_t_AWV_AbstWarnung_Entprellung */
    float ABSTANDSWARNUNG_VRELATIV_MAX;                                        /* p_v_AWV_LatenteWarnung_vRel */
  } DTKvLatentPar;

  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    UInt8_Float_A2 VFGS_KG_FG_VEGO_ABSTAND_KENNLINIE;                          /* p_d_vFGS_Abstand_FG */
    UInt8_Float_A2 VFGS_KG_FG_AKUT1_VOBJ_AANHALTEN_KENNLINIE;                  /* p_a_vFGS_Anhalten_FG */
    UInt8_Float_A2 VFGS_KG_FG_AKUT3_VOBJ_AANHALTEN_KENNLINIE;                  /* p_a_vFGS_Anhalten_FG_erw */
    Float_Float_A7 VFGS_KG_FG_AKUT1_VOBJ_A_KENNLINIE;                          /* p_a_vFGS_Beschleunigung_FG */
    Float_Float_A7 VFGS_KG_FG_AKUT3_VOBJ_A_KENNLINIE;                          /* p_a_vFGS_Beschleunigung_FG_erw */
    Float_Float_A4 KG_EGO_AKUT1_VEGO_ALAENGSMIN_KENNLINIE;                     /* p_a_AWV_Komfortverzoegerung_laengs_min */
    Float_Float_A5 KG_EGO_AKUT1_VEGO_ALAENGSMAX_KENNLINIE;                     /* p_a_AWV_Komfortverzoegerung_laengs_max */
    Float_Float_A6 KG_EGO_AKUT1_VEGO_AQUERMAX_KENNLINIE;                       /* p_a_AWV_Komfortverzoegerung_quer_max */
    Float_Float_A3 KG_EGO_AKUT2_VEGO_ALAENGSMIN_KENNLINIE;                     /* p_a_AWV_Komfortbereich_laengs_min */
    Float_Float_A5 KG_EGO_AKUT2_VEGO_ALAENGSMAX_KENNLINIE;                     /* p_a_AWV_Komfortbereich_laengs_max */
    Float_Float_A6 KG_EGO_AKUT2_VEGO_AQUERMAX_KENNLINIE;                       /* p_a_AWV_Komfortbereich_quer_max */
    Float_Float_A3 KG_EGO_AKUT3_VEGO_ALAENGSMIN_KENNLINIE;                     /* p_a_AWV_Komfortbereich_erweitert_laengs_min */
    Float_Float_A5 KG_EGO_AKUT3_VEGO_ALAENGSMAX_KENNLINIE;                     /* p_a_AWV_Komfortbereich_erweitert_laengs_max */
    Float_Float_A6 KG_EGO_AKUT3_VEGO_AQUERMAX_KENNLINIE;                       /* p_a_AWV_Komfortbereich_erweitert_quer_max */
    Float_Float_A2 KG_EGO_UNVERMEIDBAR_VEGO_ALAENGSMIN_KENNLINIE;              /* p_a_AWV_Grenzbereich_laengs_min */
    Float_Float_A2 KG_EGO_UNVERMEIDBAR_VEGO_ALAENGSMAX_KENNLINIE;              /* p_a_AWV_Grenzbereich_laengs_max */
    Float_Float_A2 KG_EGO_UNVERMEIDBAR_VEGO_AQUERMAX_KENNLINIE;                /* p_a_AWV_Grenzbereich_quer_max */
    float KG_EGO_DYNAMIK_FAKTOR;                                               /* p_f_AWV_Ego_Dynamik_Faktor */
    float KG_EGO_FILTER_A_DAUER;                                               /* p_t_AWV_Ego_Dynamik_Filter [s] */
    unsigned __int16 KG_EGO_PRAEDIKTION_DAUER;                                 /* p_t_AWV_Ego_Praediktion [ms] */
    unsigned __int16 KG_OBJ_FILTER_A_LAENGS_DAUER;                             /* p_t_AWV_Uebergang_a_laengs_Filter [ms] */
    unsigned __int16 KG_OBJ_FILTER_A_QUER_DAUER;                               /* p_t_AWV_Uebergang_a_quer_Filter [ms] */
    float KG_OBJ_VERZOEGERUNGSDAUER_A_SCHWELLE;                                /* p_a_AWV_ObjektverzDauer_KG_schwell [m/ss] */
    UInt16_Float_A5 KG_OBJ_VERZOEGERUNGSDAUER_FAKTOR_KENNLINIE;                /* p_f_AWV_ObjektverzDauer_KG */
    float KG_MINDESTABSTAND_MIN;                                               /* p_d_AWV_Restabstand_min [m] */
    float KG_MINDESTABSTAND_MAX;                                               /* p_d_AWV_Restabstand_max [m] */
    Float_Float_A3 KG_MINDESTABSTAND_VEGO_ABSTAND_KENNLINIE;                   /* p_d_AWV_Restabstand_vEgo [m/s][m] */
    Float_Float_A2 KG_MINDESTABSTAND_VREL_ABSTAND_KENNLINIE;                   /* p_d_AWV_Restabstand_vrel_Fzg [m/s][m] */
    DTKvLatentPar KG_LATENT;                                                   /* latente Kollisionsgefahr (Abstandswarnung) */
  } DTKvPar;
} // end of DTKvPar_V1



namespace DTKvPar_V2
{
  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    unsigned __int16 ABSTANDSWARNUNG_ZEITLUECKE;                               /* p_t_AWV_AbstWarnung_Zeitluecke */
    unsigned __int16 ABSTANDSWARNUNG_ZEITLUECKE_DAUER_UNTERSCHRITTEN;          /* p_t_AWV_AbstWarnung_Entprellung */
    float ABSTANDSWARNUNG_ZEITLUECKE_HYSTERESE_FAKTOR;                         /* p_f_AWV_AbstWarnung_Hysterese */
    float ABSTANDSWARNUNG_VRELATIV_MAX;                                        /* p_v_AWV_LatenteWarnung_vRel */
  } DTKvLatentPar;

  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    DTKvPar_V1::UInt8_Float_A2 VFGS_KG_FG_VEGO_ABSTAND_KENNLINIE;              /* p_d_vFGS_Abstand_FG */
    DTKvPar_V1::UInt8_Float_A2 VFGS_KG_FG_AKUT1_VOBJ_AANHALTEN_KENNLINIE;      /* p_a_vFGS_Anhalten_FG */
    DTKvPar_V1::UInt8_Float_A2 VFGS_KG_FG_AKUT3_VOBJ_AANHALTEN_KENNLINIE;      /* p_a_vFGS_Anhalten_FG_erw */
    DTKvPar_V1::Float_Float_A7 VFGS_KG_FG_AKUT1_VOBJ_A_KENNLINIE;              /* p_a_vFGS_Beschleunigung_FG */
    DTKvPar_V1::Float_Float_A7 VFGS_KG_FG_AKUT3_VOBJ_A_KENNLINIE;              /* p_a_vFGS_Beschleunigung_FG_erw */
    DTKvPar_V1::Float_Float_A4 KG_EGO_AKUT1_VEGO_ALAENGSMIN_KENNLINIE;         /* p_a_AWV_Komfortverzoegerung_laengs_min */
    DTKvPar_V1::Float_Float_A5 KG_EGO_AKUT1_VEGO_ALAENGSMAX_KENNLINIE;         /* p_a_AWV_Komfortverzoegerung_laengs_max */
    DTKvPar_V1::Float_Float_A6 KG_EGO_AKUT1_VEGO_AQUERMAX_KENNLINIE;           /* p_a_AWV_Komfortverzoegerung_quer_max */
    DTKvPar_V1::Float_Float_A3 KG_EGO_AKUT2_VEGO_ALAENGSMIN_KENNLINIE;         /* p_a_AWV_Komfortbereich_laengs_min */
    DTKvPar_V1::Float_Float_A5 KG_EGO_AKUT2_VEGO_ALAENGSMAX_KENNLINIE;         /* p_a_AWV_Komfortbereich_laengs_max */
    DTKvPar_V1::Float_Float_A6 KG_EGO_AKUT2_VEGO_AQUERMAX_KENNLINIE;           /* p_a_AWV_Komfortbereich_quer_max */
    DTKvPar_V1::Float_Float_A3 KG_EGO_AKUT3_VEGO_ALAENGSMIN_KENNLINIE;         /* p_a_AWV_Komfortbereich_erweitert_laengs_min */
    DTKvPar_V1::Float_Float_A5 KG_EGO_AKUT3_VEGO_ALAENGSMAX_KENNLINIE;         /* p_a_AWV_Komfortbereich_erweitert_laengs_max */
    DTKvPar_V1::Float_Float_A6 KG_EGO_AKUT3_VEGO_AQUERMAX_KENNLINIE;           /* p_a_AWV_Komfortbereich_erweitert_quer_max */
    DTKvPar_V1::Float_Float_A2 KG_EGO_UNVERMEIDBAR_VEGO_ALAENGSMIN_KENNLINIE;  /* p_a_AWV_Grenzbereich_laengs_min */
    DTKvPar_V1::Float_Float_A2 KG_EGO_UNVERMEIDBAR_VEGO_ALAENGSMAX_KENNLINIE;  /* p_a_AWV_Grenzbereich_laengs_max */
    DTKvPar_V1::Float_Float_A2 KG_EGO_UNVERMEIDBAR_VEGO_AQUERMAX_KENNLINIE;    /* p_a_AWV_Grenzbereich_quer_max */
    float KG_EGO_DYNAMIK_FAKTOR;                                               /* p_f_AWV_Ego_Dynamik_Faktor */
    float KG_EGO_FILTER_A_DAUER;                                               /* p_t_AWV_Ego_Dynamik_Filter [s] */
    unsigned __int16 KG_EGO_PRAEDIKTION_DAUER;                                 /* p_t_AWV_Ego_Praediktion [ms] */
    unsigned __int16 KG_OBJ_FILTER_A_LAENGS_DAUER;                             /* p_t_AWV_Uebergang_a_laengs_Filter [ms] */
    unsigned __int16 KG_OBJ_FILTER_A_QUER_DAUER;                               /* p_t_AWV_Uebergang_a_quer_Filter [ms] */
    float KG_OBJ_VERZOEGERUNGSDAUER_A_SCHWELLE;                                /* p_a_AWV_ObjektverzDauer_KG_schwell [m/ss] */
    DTKvPar_V1::UInt16_Float_A5 KG_OBJ_VERZOEGERUNGSDAUER_FAKTOR_KENNLINIE;    /* p_f_AWV_ObjektverzDauer_KG */
    float KG_MINDESTABSTAND_MIN;                                               /* p_d_AWV_Restabstand_min [m] */
    float KG_MINDESTABSTAND_MAX;                                               /* p_d_AWV_Restabstand_max [m] */
    DTKvPar_V1::Float_Float_A3 KG_MINDESTABSTAND_VEGO_ABSTAND_KENNLINIE;       /* p_d_AWV_Restabstand_vEgo [m/s][m] */
    DTKvPar_V1::Float_Float_A2 KG_MINDESTABSTAND_VREL_ABSTAND_KENNLINIE;       /* p_d_AWV_Restabstand_vrel_Fzg [m/s][m] */
    DTKvLatentPar KG_LATENT;                                                   /* latente Kollisionsgefahr (Abstandswarnung) */
  } DTKvPar;
} // end of DTKvPar_V2


class CConvDTKvPar : public CSimConverterBase
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

  DTKvPar_V1::DTKvPar m_BufV1;
  DTKvPar_V2::DTKvPar m_BufV2;

  // Initialization
  template <typename T> static void InitVx (T & Dest)
  {
    ::memset(&Dest, 0, sizeof(Dest));
  }

public:

  static const char *GetConverterTypeName()
  {
    return "DTKvPar";
  }

  CConvDTKvPar(void);
  virtual ~CConvDTKvPar(void);

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
  enum AVWV_DTKvPar
  {
    DTKVPAR_V1,
    DTKVPAR_V2,
    DTKVPAR_VERSION_COUNT
  };

  static CVersionInfoImpl BASE_VERSION;

  static const CVersionInfoImpl * const EM_OBJECTLIST_CAM_INPUT_VERSIONS[DTKVPAR_VERSION_COUNT];

  static const unsigned long SUPPORTED_SIZE[DTKVPAR_VERSION_COUNT];

  bool IsPortSupported(unsigned long ulPortSize, const IVersionInfo *pPortVersion) const
  {
    for (int nI = 0; nI < DTKVPAR_VERSION_COUNT; nI++)
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

CVersionInfoImpl CConvDTKvPar::BASE_VERSION(0, 0, 0);

const CVersionInfoImpl * const CConvDTKvPar::EM_OBJECTLIST_CAM_INPUT_VERSIONS[CConvDTKvPar::DTKVPAR_VERSION_COUNT] =
{
  &BASE_VERSION,
  &BASE_VERSION
};

const unsigned long CConvDTKvPar::SUPPORTED_SIZE[CConvDTKvPar::DTKVPAR_VERSION_COUNT] =
{
  sizeof(DTKvPar_V1::DTKvPar),
  sizeof(DTKvPar_V2::DTKvPar)
};

__inline void v_Convert_v1_to_v2 (DTKvPar_V2::DTKvPar * const pDest,
  const DTKvPar_V1::DTKvPar * const pSrc)
{
  memcpy(pDest, pSrc, sizeof (*pSrc));
  pDest->KG_LATENT.ABSTANDSWARNUNG_VRELATIV_MAX = pSrc->KG_LATENT.ABSTANDSWARNUNG_VRELATIV_MAX;
  pDest->KG_LATENT.ABSTANDSWARNUNG_ZEITLUECKE_HYSTERESE_FAKTOR = 0.0F;
}

CConvDTKvPar::CConvDTKvPar(void) : CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT), m_BufV1(), m_BufV2()
{
  InitVx(m_BufV1);
  InitVx(m_BufV2);
}

CConvDTKvPar::~CConvDTKvPar(void)
{
}

long CConvDTKvPar::ConvertData(
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
        const DTKvPar_V1::DTKvPar *pSrc = reinterpret_cast<DTKvPar_V1::DTKvPar *>(pPPortData);
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
long CConvDTKvPar::GetDefaultValue(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  void **pDefaultData, unsigned long &ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == sizeof(DTKvPar_V2::DTKvPar)) && (BASE_VERSION.Equals(&requestPortVersionInfo)))
    {
      InitVx(m_BufV2);
      *pDefaultData = &m_BufV2;
      ulDefaultSize = sizeof(DTKvPar_V2::DTKvPar);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(DTKvPar_V1::DTKvPar)) && BASE_VERSION.Equals(&requestPortVersionInfo))
    {
      InitVx(m_BufV1);
      *pDefaultData = &m_BufV1;
      ulDefaultSize = sizeof(DTKvPar_V1::DTKvPar);
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
bool CConvDTKvPar::IsVersionCompatibleWithType(
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
bool CConvDTKvPar::AreVersionsCompatible(
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
IConverter * CreateDTKvParConvClass(void)
{
  return new CConvDTKvPar();
}
