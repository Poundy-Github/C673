/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter

  MODULNAME:            sim_conv_rsp1_preclusterlistheader

  DESCRIPTION:          Convert pre cluster list header

  AUTHOR:               Stephan Kaelberer, Thomas Berndt

  CREATION DATE:        29.06.2015

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: sim_conv_rsp1_preclusterlistheader.cpp  $
  CHANGES:              Revision 1.1 2021/12/13 17:21:43CET Wang, David (Wangd3) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_adapter/rsp/project.pj
  CHANGES:              Revision 1.1 2017/08/10 13:15:36CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/rsp/project.pj
  CHANGES:              Revision 1.2 2016/08/18 13:33:04CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              + ARS510: V100A and V100B and conversion between those
  CHANGES:              Revision 1.1 2015/07/06 09:11:24CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/sim_adapter/rsp/project.pj

**************************************************************************** */

/* includes ---------------------------------------------------------------- */
#include <atlbase.h>                             // ATL includes
#include "sim_adapter_cfg.h"
#include "sim_conv_rsp1_preclusterlistheader.h"
#include <math.h>

#include "sim_versioninfo_impl.h"
#include "interface_rsp1_preclusterlist_ars400.h"

#define _MINI(x,y) (x<y?x:y)

class CConvRSP1PreClusterListHeader : public CSimConverterBase
{
  // the list of dependency names used inside by the converter
  static const TCHAR *DEP_NAMES[];

  // here we define the index of each dependency for quick acces
  // the order here should match with the order from DEP_NAMES array
  enum eDepIdx
  {
    RECVERSION = 0,
    DORCSCORRECTION,
    NEARORFAR,
    // add new dependencies here
    DEP_COUNT
  };

  RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterHeader m_BufV2pren;
  RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterHeader m_BufV4pren;
  RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreClusterHeader m_BufV6pren;
  RSP1_PRECLUSTERLIST_V6_2_PR_EN::RSP_t_PreClusterHeader m_BufV62pren;
  RSP1_PRECLUSTERLIST_V100_A::RSP_t_PreClusterHeader m_BufV100_A;
  RSP1_PRECLUSTERLIST_V100_B::RSP_t_PreClusterHeader m_BufV100_B;

  // Initialization of header
  template <typename T> static void InitPreClusterHeader (T & Dest, uint32 VersionNumber)
  {
    ::memset(&(Dest), 0, sizeof(Dest));
    Dest.u_VersionNumber = VersionNumber;
  }

public:

  CConvRSP1PreClusterListHeader(void): CSimConverterBase(DEP_NAMES, DEP_COUNT),
    m_BufV2pren(), m_BufV4pren(), m_BufV6pren(), m_BufV62pren(), m_BufV100_A(), m_BufV100_B()
  {
    InitPreClusterHeader(m_BufV2pren, 2);
    InitPreClusterHeader(m_BufV4pren, 4);
    InitPreClusterHeader(m_BufV6pren, 6);
    InitPreClusterHeader(m_BufV62pren, 6);
    InitPreClusterHeader(m_BufV100_A, 0x100);
    InitPreClusterHeader(m_BufV100_B, 0x100);
  };

  // Not implemented copy constructor to get linker error
  CConvRSP1PreClusterListHeader(const CConvRSP1PreClusterListHeader & init);

  virtual ~CConvRSP1PreClusterListHeader(void)
  {
  };

  // IConverterDestroy::Destroy implementation
  virtual void Destroy()
  {
    delete this;
  };

  // IConverter::GetTypeName implementation
  virtual const char *GetTypeName(void)
  {
    return "RSP_PreClusterListHead";
  };

  bool IsPortSupported(unsigned long ulPortSize, const IVersionInfo *pPortVersion) const
  {
    for (int nI = 0; nI < RSP1_PRECLUSTERLISTHEADER_VERSION_COUNT; nI++)
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
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    void **pDefaultData, unsigned long& ulDefaultSize);

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
  // Part of the following Version Information are not used:
  static CVersionInfoImpl RSP1V1;
  static CVersionInfoImpl RSP1V2;
  static CVersionInfoImpl RSP1V3;
  static CVersionInfoImpl RSP1V4;
  static CVersionInfoImpl RSP1V5;
  static CVersionInfoImpl RSP1V6;
  static CVersionInfoImpl RSP1V100;

  enum RSP1PreClusterListHeader
  {
    RSP1_PRECLUSTERLISTHEADER_V2,
    RSP1_PRECLUSTERLISTHEADER_V4,
    RSP1_PRECLUSTERLISTHEADER_V5,
    RSP1_PRECLUSTERLISTHEADER_V6,
    RSP1_PRECLUSTERLISTHEADER_V6_2,
    RSP1_PRECLUSTERLISTHEADER_V100_A,
    RSP1_PRECLUSTERLISTHEADER_V100_B,
    RSP1_PRECLUSTERLISTHEADER_VERSION_COUNT
  };

  static const unsigned long SUPPORTED_SIZE[RSP1_PRECLUSTERLISTHEADER_VERSION_COUNT];

  static const CVersionInfoImpl * const VERSION_NUMBERS[RSP1_PRECLUSTERLISTHEADER_VERSION_COUNT];

  bool GetDeps (unsigned int &uiRecVersion, unsigned char &ucDoRCSCorrection, unsigned char &ucNearOrFar)
  {
    bool bRet = false;
    DepInfo *pValUi = GetDependencyInfo(RECVERSION);
    // retrieve dependency for being used
    if ((pValUi != NULL) && (pValUi->m_pDepData != NULL))
    {
      uiRecVersion = * (unsigned int *) pValUi->m_pDepData;
    }
    DepInfo *pValUc = GetDependencyInfo(DORCSCORRECTION);
    // retrieve dependency for being used
    if ((pValUc != NULL) && (pValUc->m_pDepData != NULL))
    {
      ucDoRCSCorrection = *((unsigned char *) pValUc->m_pDepData);
    }
    DepInfo *pValUc2 = GetDependencyInfo(NEARORFAR);
    // retrieve dependency for being used
    if ((pValUc2 != NULL) && (pValUc2->m_pDepData != NULL))
    {
      ucNearOrFar = *((unsigned char *) pValUc2->m_pDepData);
    }
    if ((pValUi != NULL) && (pValUi->m_pDepData != NULL) &&
      (pValUc != NULL) && (pValUc->m_pDepData != NULL) &&
      (pValUc2 != NULL) && (pValUc2->m_pDepData != NULL))
    {
      if ((uiRecVersion == 0x40004) ||
        (uiRecVersion == 0x40022) ||
        (uiRecVersion == 0x40100) ||
        ((uiRecVersion >= 0x40102) && (uiRecVersion <= 0x40105)))
      {
        if ((ucDoRCSCorrection == 1) &&
          ((ucNearOrFar == 1) || (ucNearOrFar == 2)))
        {
          bRet = true;
        }
      }
    }
    return bRet;
  }

};

const TCHAR *CConvRSP1PreClusterListHeader::DEP_NAMES[CConvRSP1PreClusterListHeader::DEP_COUNT] = {_T("RecVersion"), _T("DoRCSCorrection"), _T("NearOrFar")};

CVersionInfoImpl  CConvRSP1PreClusterListHeader::BASE_VERSION(0, 0, 0);
CVersionInfoImpl  CConvRSP1PreClusterListHeader::RSP1V1(0, 0, 1);
CVersionInfoImpl  CConvRSP1PreClusterListHeader::RSP1V2(0, 0, 2);
CVersionInfoImpl  CConvRSP1PreClusterListHeader::RSP1V3(0, 0, 3);
CVersionInfoImpl  CConvRSP1PreClusterListHeader::RSP1V4(0, 0, 4);
CVersionInfoImpl  CConvRSP1PreClusterListHeader::RSP1V5(0, 0, 5);
CVersionInfoImpl  CConvRSP1PreClusterListHeader::RSP1V6(0, 0, 6);
CVersionInfoImpl  CConvRSP1PreClusterListHeader::RSP1V100(0, 1, 0);

const unsigned long CConvRSP1PreClusterListHeader::SUPPORTED_SIZE[CConvRSP1PreClusterListHeader::RSP1_PRECLUSTERLISTHEADER_VERSION_COUNT]=
{
   sizeof(RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterHeader),
   sizeof(RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterHeader),
   sizeof(RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterHeader),     // Version number increased, but no header change
   sizeof(RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreClusterHeader),
   sizeof(RSP1_PRECLUSTERLIST_V6_2_PR_EN::RSP_t_PreClusterHeader),
   sizeof(RSP1_PRECLUSTERLIST_V100_A::RSP_t_PreClusterHeader),
   sizeof(RSP1_PRECLUSTERLIST_V100_B::RSP_t_PreClusterHeader)
};

const CVersionInfoImpl * const CConvRSP1PreClusterListHeader::VERSION_NUMBERS[CConvRSP1PreClusterListHeader::RSP1_PRECLUSTERLISTHEADER_VERSION_COUNT] =
{
  &RSP1V2,
  &RSP1V4,
  &RSP1V5,
  &RSP1V6,
  &RSP1V6,                                                           // Version number not increased !
  &RSP1V100,
  &RSP1V100                                                          // Version number not increased !
};

__inline void v_Convert_v100A_to_v100B(RSP1_PRECLUSTERLIST_V100_B::RSP_t_PreClusterHeader & Dest, const RSP1_PRECLUSTERLIST_V100_A::RSP_t_PreClusterHeader & Source)
{
  Dest.u_VersionNumber = 0x100u;
  Dest.sSigHeader = Source.sSigHeader;
  Dest.u_NofClusters = Source.u_NofClusters;
  Dest.ContextData = Source.ContextData;
};

__inline void v_Convert_v100B_to_v100A(RSP1_PRECLUSTERLIST_V100_A::RSP_t_PreClusterHeader & Dest, const RSP1_PRECLUSTERLIST_V100_B::RSP_t_PreClusterHeader & Source)
{
  Dest.u_VersionNumber = 0x100u;
  Dest.sSigHeader = Source.sSigHeader;
  Dest.u_TimeStamp = Source.sSigHeader.uiTimeStamp;
  Dest.u_NofClusters = Source.u_NofClusters;
  Dest.ContextData = Source.ContextData;
};

__inline void v_Convert_v6pren_to_v62pren_RCSWorkaround(RSP1_PRECLUSTERLIST_V6_2_PR_EN::RSP_t_PreClusterHeader & Dest, const RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreClusterHeader & Source,
  unsigned int uiRecVersion, unsigned char ucDoRCSCorrection, unsigned char ucNearOrFar)
{
  int nSize = _MINI(sizeof(Source), sizeof(Dest));
  memcpy(&Dest, &Source, nSize);                                     // PreClustHead is the same except the last element
  Dest.u_VersionNumber = 6u;
#if ((CFG_ARS400_PR_SWITCH == SWITCH_ON) || (CFG_ARS400_PP_SWITCH == SWITCH_ON))
  Dest.ContextData.f_PowerScalingFactor = -114.1f;
#elif (CFG_ARS400_EN_SWITCH == SWITCH_ON)
  Dest.ContextData.f_PowerScalingFactor = -119.5f;
#elif (SRR_SWITCH == SWITCH_ON)
  Dest.ContextData.f_PowerScalingFactor = -115.5f;
#endif

  // Other fields
  if (ucDoRCSCorrection == 1)
  {
    if (ucNearOrFar == 1)                                            // NEAR
    {
      if ((uiRecVersion == 0x40004) || (uiRecVersion == 0x40022) || (uiRecVersion == 0x40100))
      {
        Dest.ContextData.f_TargetNormS = Source.ContextData.f_TargetNormS + 7.4F;
      }
      else if ((uiRecVersion >= 0x40102) && (uiRecVersion <= 0x40105))
      {
        Dest.ContextData.f_TargetNormS = Source.ContextData.f_TargetNormS - 0.5F;
      }
    }
    else if (ucNearOrFar == 2)                                       // FAR
    {
      if ((uiRecVersion == 0x40004) || (uiRecVersion == 0x40022) || (uiRecVersion == 0x40100))
      {
        Dest.ContextData.f_TargetNormS = Source.ContextData.f_TargetNormS + 3.3F;
      }
      else if ((uiRecVersion >= 0x40102) && (uiRecVersion <= 0x40105))
      {
        Dest.ContextData.f_TargetNormS = Source.ContextData.f_TargetNormS - 4.2F;
      }
    }
  }
};

__inline void v_Convert_v62pren_to_v6pren_RCSWorkaround(RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreClusterHeader & Dest, const RSP1_PRECLUSTERLIST_V6_2_PR_EN::RSP_t_PreClusterHeader & Source,
  unsigned int uiRecVersion, unsigned char ucDoRCSCorrection, unsigned char ucNearOrFar)
{
  int nSize = _MINI(sizeof(Source), sizeof(Dest));
  memcpy(&Dest, &Source, nSize);                                     // PreClustHead is the same except the last element
  Dest.u_VersionNumber = 6u;

  // Other fields
  if (ucDoRCSCorrection == 1)
  {
    if (ucNearOrFar == 1)                                            // NEAR
    {
      if ((uiRecVersion == 0x40004) || (uiRecVersion == 0x40022) || (uiRecVersion == 0x40100))
      {
        Dest.ContextData.f_TargetNormS = Source.ContextData.f_TargetNormS + 7.4F;
      }
      else if ((uiRecVersion >= 0x40102) && (uiRecVersion <= 0x40105))
      {
        Dest.ContextData.f_TargetNormS = Source.ContextData.f_TargetNormS - 0.5F;
      }
    }
    else if (ucNearOrFar == 2)                                       // FAR
    {
      if ((uiRecVersion == 0x40004) || (uiRecVersion == 0x40022) || (uiRecVersion == 0x40100))
      {
        Dest.ContextData.f_TargetNormS = Source.ContextData.f_TargetNormS + 3.3F;
      }
      else if ((uiRecVersion >= 0x40102) && (uiRecVersion <= 0x40105))
      {
        Dest.ContextData.f_TargetNormS = Source.ContextData.f_TargetNormS - 4.2F;
      }
    }
  }
};

__inline void v_Convert_v5pren_to_v6pren_RCSWorkaround(RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreClusterHeader & Dest, const RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterHeader & Source,
  unsigned int uiRecVersion, unsigned char ucDoRCSCorrection, unsigned char ucNearOrFar)
{
  memcpy(&Dest, &Source, sizeof(Dest));
  Dest.u_VersionNumber = 6u;
  Dest.ContextData.u_GainReduction = 0;
  Dest.ContextData.u_CurrentRfIndex = Source.ContextData.u_CurrentRfIndex;

  // Other fields
  if (ucDoRCSCorrection == 1)
  {
    if (ucNearOrFar == 1)                                            // NEAR
    {
      if ((uiRecVersion == 0x40004) || (uiRecVersion == 0x40022) || (uiRecVersion == 0x40100))
      {
        Dest.ContextData.f_TargetNormS = Source.ContextData.f_TargetNormS + 7.4F;
      }
      else if ((uiRecVersion >= 0x40102) && (uiRecVersion <= 0x40105))
      {
        Dest.ContextData.f_TargetNormS = Source.ContextData.f_TargetNormS - 0.5F;
      }
    }
    else if (ucNearOrFar == 2)                                       // FAR
    {
      if ((uiRecVersion == 0x40004) || (uiRecVersion == 0x40022) || (uiRecVersion == 0x40100))
      {
        Dest.ContextData.f_TargetNormS = Source.ContextData.f_TargetNormS + 3.3F;
      }
      else if ((uiRecVersion >= 0x40102) && (uiRecVersion <= 0x40105))
      {
        Dest.ContextData.f_TargetNormS = Source.ContextData.f_TargetNormS - 4.2F;
      }
    }
  }
};

__inline void v_Convert_v4pren_to_v6pren_RCSWorkaround(RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreClusterHeader & Dest, const RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterHeader & Source,
  unsigned int uiRecVersion, unsigned char ucDoRCSCorrection, unsigned char ucNearOrFar)
{
  memcpy(&Dest, &Source, sizeof(Dest));
  Dest.u_VersionNumber = 6u;
  Dest.ContextData.u_GainReduction = 0;
  Dest.ContextData.u_CurrentRfIndex = Source.ContextData.u_CurrentRfIndex;

  // Other fields
  if (ucDoRCSCorrection == 1)
  {
    if (ucNearOrFar == 1)                                            // NEAR
    {
      if ((uiRecVersion == 0x40004) || (uiRecVersion == 0x40022) || (uiRecVersion == 0x40100))
      {
        Dest.ContextData.f_TargetNormS = Source.ContextData.f_TargetNormS + 7.4F;
      }
      else if ((uiRecVersion >= 0x40102) && (uiRecVersion <= 0x40105))
      {
        Dest.ContextData.f_TargetNormS = Source.ContextData.f_TargetNormS - 0.5F;
      }
    }
    else if (ucNearOrFar == 2)                                       // FAR
    {
      if ((uiRecVersion == 0x40004) || (uiRecVersion == 0x40022) || (uiRecVersion == 0x40100))
      {
        Dest.ContextData.f_TargetNormS = Source.ContextData.f_TargetNormS + 3.3F;
      }
      else if ((uiRecVersion >= 0x40102) && (uiRecVersion <= 0x40105))
      {
        Dest.ContextData.f_TargetNormS = Source.ContextData.f_TargetNormS - 4.2F;
      }
    }
  }
};

__inline void v_Convert_v2pren_to_v6pren_FAR (RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreClusterHeader & Dest,
  const RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterHeader & Src )
{
  // Header part
  Dest.u_VersionNumber = 6u;
  Dest.sSigHeader.uiTimeStamp            = Src.sSigHeader.uiTimeStamp;
  Dest.sSigHeader.uiMeasurementCounter   = Src.sSigHeader.uiMeasurementCounter;
  Dest.sSigHeader.uiCycleCounter         = Src.sSigHeader.uiCycleCounter;
  Dest.sSigHeader.eSigStatus             = Src.sSigHeader.eSigStatus;
  Dest.u_TimeStamp                       = Src.u_TimeStamp;
  Dest.u_NofClusters                     = Src.u_NofClusters;
  Dest.ContextData.f_PulseRepetitionTime = Src.ContextData.f_PulseRepetitionTime;
  Dest.ContextData.f_RangeGateLength     = Src.ContextData.f_RangeGateLength;
  Dest.ContextData.f_MidFrequency        = Src.ContextData.f_MidFrequency;
  Dest.ContextData.f_TargetNormS         = Src.ContextData.f_TargetNormS;
  Dest.ContextData.u_GainReduction       = 0u;
  Dest.ContextData.u_CurrentRfIndex      = 0u;
  memset(&(Dest.ContextData.u_Dummy), 0, sizeof(Dest.ContextData.u_Dummy));
  memcpy(Dest.ContextData.a_PathCompensation, Src.ContextData.a_PathCompensation, sizeof(Dest.ContextData.a_PathCompensation));
  memcpy(Dest.ContextData.a_AzimuthWindow, Src.ContextData.a_AzimuthWindow, sizeof(Dest.ContextData.a_AzimuthWindow));
}

__inline void v_Convert_v5pren_to_v6pren_NEAR(RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreClusterHeader & Dest, const RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterHeader & Source)
{
  /* The differences are
  - the inclusion of u_MultipleTargetProb into the array a_Pdh0_array_t_0 (in RSP_t_PreCluster), which grows from 7 to 8.
  - introduced u_GainReduction (in t_ContextData), which moves u_CurrentRfIndex by one position down */
  memcpy(&Dest, &Source, sizeof(Dest));
  Dest.u_VersionNumber = 6u;
  Dest.ContextData.u_GainReduction = 0;
  Dest.ContextData.u_CurrentRfIndex = Source.ContextData.u_CurrentRfIndex;
};

__inline void v_Convert_v5pren_to_v4pren_NEAR (RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterHeader & Dest,
  const RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterHeader & Src )
{
  // Header part
  Dest = Src;
  Dest.u_VersionNumber = 4u;
}

__inline void v_Convert_v4pren_to_v5pren_FAR (RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterHeader & Dest,
  const RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterHeader & Src )
{
  // Header part
  Dest = Src;
  Dest.u_VersionNumber = 4u;
}

__inline void v_Convert_v2pren_to_v4pren (RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterHeader & Dest,
  const RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterHeader & Src )
{
  // Header part
  Dest.u_VersionNumber = 4u;
  Dest.sSigHeader.uiTimeStamp            = Src.sSigHeader.uiTimeStamp;
  Dest.sSigHeader.uiMeasurementCounter   = Src.sSigHeader.uiMeasurementCounter;
  Dest.sSigHeader.uiCycleCounter         = Src.sSigHeader.uiCycleCounter;
  Dest.sSigHeader.eSigStatus             = Src.sSigHeader.eSigStatus;
  Dest.u_TimeStamp                       = Src.u_TimeStamp;
  Dest.u_NofClusters                     = Src.u_NofClusters;
  Dest.ContextData.f_PulseRepetitionTime = Src.ContextData.f_PulseRepetitionTime;
  Dest.ContextData.f_RangeGateLength     = Src.ContextData.f_RangeGateLength;
  Dest.ContextData.f_MidFrequency        = Src.ContextData.f_MidFrequency;
  Dest.ContextData.f_TargetNormS         = Src.ContextData.f_TargetNormS;
  Dest.ContextData.u_CurrentRfIndex      = 0u;
  memset(&(Dest.ContextData.u_Dummy), 0, sizeof(Dest.ContextData.u_Dummy));
  memcpy(Dest.ContextData.a_PathCompensation, Src.ContextData.a_PathCompensation, sizeof(Dest.ContextData.a_PathCompensation));
  memcpy(Dest.ContextData.a_AzimuthWindow, Src.ContextData.a_AzimuthWindow, sizeof(Dest.ContextData.a_AzimuthWindow));
}

__inline void v_Convert_v6_to_v6_NEAR_RCSWorkaround(RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterHeader & Dest, const RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterHeader & Source,
  unsigned int uiRecVersion, unsigned char ucDoRCSCorrection, unsigned char ucNearOrFar)
{
  memcpy(&Dest, &Source, sizeof(Dest));
  Dest.u_VersionNumber = 6u;

  // Other fields
  if (ucDoRCSCorrection == 1)
  {
    if (ucNearOrFar == 1)                                            // NEAR
    {
      if ((uiRecVersion == 0x40004) || (uiRecVersion == 0x40022) || (uiRecVersion == 0x40100))
      {
        Dest.ContextData.f_TargetNormS = Source.ContextData.f_TargetNormS + 7.4F;
      }
      else if ((uiRecVersion >= 0x40102) && (uiRecVersion <= 0x40105))
      {
        Dest.ContextData.f_TargetNormS = Source.ContextData.f_TargetNormS - 0.5F;
      }
    }
    else if (ucNearOrFar == 2)                                       // FAR
    {
      if ((uiRecVersion == 0x40004) || (uiRecVersion == 0x40022) || (uiRecVersion == 0x40100))
      {
        Dest.ContextData.f_TargetNormS = Source.ContextData.f_TargetNormS + 3.3F;
      }
      else if ((uiRecVersion >= 0x40102) && (uiRecVersion <= 0x40105))
      {
        Dest.ContextData.f_TargetNormS = Source.ContextData.f_TargetNormS - 4.2F;
      }
    }
  }
};

__inline void v_Convert_v4pren_to_v5pren_RCSWorkaround (RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterHeader & Dest, const RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterHeader & Source,
  unsigned int uiRecVersion, unsigned char ucDoRCSCorrection, unsigned char ucNearOrFar)
{
  // Header part
  Dest = Source;
  Dest.u_VersionNumber = 5u;

  // Other fields
  if (ucDoRCSCorrection == 1)
  {
    if (ucNearOrFar == 1)                                            // NEAR
    {
      if ((uiRecVersion == 0x40004) || (uiRecVersion == 0x40022) || (uiRecVersion == 0x40100))
      {
        Dest.ContextData.f_TargetNormS = Source.ContextData.f_TargetNormS + 7.4F;
      }
      else if ((uiRecVersion >= 0x40102) && (uiRecVersion <= 0x40105))
      {
        Dest.ContextData.f_TargetNormS = Source.ContextData.f_TargetNormS - 0.5F;
      }
    }
    else if (ucNearOrFar == 2)                                       // FAR
    {
      if ((uiRecVersion == 0x40004) || (uiRecVersion == 0x40022) || (uiRecVersion == 0x40100))
      {
        Dest.ContextData.f_TargetNormS = Source.ContextData.f_TargetNormS + 3.3F;
      }
      else if ((uiRecVersion >= 0x40102) && (uiRecVersion <= 0x40105))
      {
        Dest.ContextData.f_TargetNormS = Source.ContextData.f_TargetNormS - 4.2F;
      }
    }
  }
}

__inline void v_Convert_v6pren_to_v4pren_RCSWorkaround (RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterHeader & Dest, const RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreClusterHeader & Source,
  unsigned int uiRecVersion, unsigned char ucDoRCSCorrection, unsigned char ucNearOrFar)
{
  int nSize = _MINI(sizeof(Source), sizeof(Dest));
  memcpy(&Dest, &Source, nSize);                                     // PreClustHead is the same except u_GainReduction and u_CurrentRfIndex
  Dest.u_VersionNumber = 4u;
  Dest.ContextData.u_CurrentRfIndex = Source.ContextData.u_CurrentRfIndex;

  // Other fields
  if (ucDoRCSCorrection == 1)
  {
    if (ucNearOrFar == 1)                                            // NEAR
    {
      if ((uiRecVersion == 0x40004) || (uiRecVersion == 0x40022) || (uiRecVersion == 0x40100))
      {
        Dest.ContextData.f_TargetNormS = Source.ContextData.f_TargetNormS + 7.4F;
      }
      else if ((uiRecVersion >= 0x40102) && (uiRecVersion <= 0x40105))
      {
        Dest.ContextData.f_TargetNormS = Source.ContextData.f_TargetNormS - 0.5F;
      }
    }
    else if (ucNearOrFar == 2)                                       // FAR
    {
      if ((uiRecVersion == 0x40004) || (uiRecVersion == 0x40022) || (uiRecVersion == 0x40100))
      {
        Dest.ContextData.f_TargetNormS = Source.ContextData.f_TargetNormS + 3.3F;
      }
      else if ((uiRecVersion >= 0x40102) && (uiRecVersion <= 0x40105))
      {
        Dest.ContextData.f_TargetNormS = Source.ContextData.f_TargetNormS - 4.2F;
      }
    }
  }
}

__inline void v_Convert_v5pren_to_v5pren_RCSWorkaround (RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterHeader & Dest, const RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterHeader & Source,
  unsigned int uiRecVersion, unsigned char ucDoRCSCorrection, unsigned char ucNearOrFar)
{
  memcpy(&Dest, &Source, sizeof(Dest));

  // Other fields
  if (ucDoRCSCorrection == 1)
  {
    if (ucNearOrFar == 1)                                            // NEAR
    {
      if ((uiRecVersion == 0x40004) || (uiRecVersion == 0x40022) || (uiRecVersion == 0x40100))
      {
        Dest.ContextData.f_TargetNormS = Source.ContextData.f_TargetNormS + 7.4F;
      }
      else if ((uiRecVersion >= 0x40102) && (uiRecVersion <= 0x40105))
      {
        Dest.ContextData.f_TargetNormS = Source.ContextData.f_TargetNormS - 0.5F;
      }
    }
    else if (ucNearOrFar == 2)                                       // FAR
    {
      if ((uiRecVersion == 0x40004) || (uiRecVersion == 0x40022) || (uiRecVersion == 0x40100))
      {
        Dest.ContextData.f_TargetNormS = Source.ContextData.f_TargetNormS + 3.3F;
      }
      else if ((uiRecVersion >= 0x40102) && (uiRecVersion <= 0x40105))
      {
        Dest.ContextData.f_TargetNormS = Source.ContextData.f_TargetNormS - 4.2F;
      }
    }
  }
};


long CConvRSP1PreClusterListHeader::ConvertData(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo *pProvidePortVersionInfo,
    void *pPPortData,
    void **pOutData, unsigned long &ulOutSize)
{
  long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  unsigned int uiRecVersion = 0;
  unsigned char ucDoRCSCorrection = 0;
  unsigned char ucNearOrFar = 0;
  bool bWorkaroundHandling = false;

  // retrieve dependency for being used
  bWorkaroundHandling = GetDeps(uiRecVersion, ucDoRCSCorrection, ucNearOrFar);
  const unsigned __int32 uDataVer = ((pPPortData != NULL) && (ulPPortSize >= 4) && (ePPortType == simOPAQUE_t))?(*reinterpret_cast<unsigned __int32*>(pPPortData)):(0);

  // If direct one-to-one copy possible do that
  if ((ulRPortSize == ulPPortSize) && ((pProvidePortVersionInfo == NULL) || (requestPortVersionInfo.Equals(pProvidePortVersionInfo))) &&
      (!(requestPortVersionInfo.Equals(&RSP1V6) && (uDataVer == 5u))) &&
      (bWorkaroundHandling == false))
  {
    *pOutData = pPPortData;
    ulOutSize = ulRPortSize;
    lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
  }
  else
  {
    // First branch to decide which version we are converting to

    // **************************************************************************************************************************
    // * RSP_t_PreClusterHeader
    // **************************************************************************************************************************
    if (ulRPortSize == SUPPORTED_SIZE[RSP1_PRECLUSTERLISTHEADER_V100_B])
    {
      if ((ulPPortSize == SUPPORTED_SIZE[RSP1_PRECLUSTERLISTHEADER_V100_A]) &&
        ((pProvidePortVersionInfo == NULL) || (RSP1V100.Equals(pProvidePortVersionInfo))) &&
        (uDataVer == 0x100u))
      {
        const RSP1_PRECLUSTERLIST_V100_A::RSP_t_PreClusterHeader * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V100_A::RSP_t_PreClusterHeader*>(pPPortData);
        v_Convert_v100A_to_v100B(m_BufV100_B, *pSrc);
        *pOutData = &m_BufV100_B;
        ulOutSize = sizeof(m_BufV100_B);
        lRet = SIM_ERR_OK;
      }
    }
    else if (ulRPortSize == SUPPORTED_SIZE[RSP1_PRECLUSTERLISTHEADER_V100_A])
    {
      if ((ulPPortSize == SUPPORTED_SIZE[RSP1_PRECLUSTERLISTHEADER_V100_B]) &&
        ((pProvidePortVersionInfo == NULL) || (RSP1V100.Equals(pProvidePortVersionInfo))) &&
        (uDataVer == 0x100u))
      {
        const RSP1_PRECLUSTERLIST_V100_B::RSP_t_PreClusterHeader * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V100_B::RSP_t_PreClusterHeader*>(pPPortData);
        v_Convert_v100B_to_v100A(m_BufV100_A, *pSrc);
        *pOutData = &m_BufV100_A;
        ulOutSize = sizeof(m_BufV100_A);
        lRet = SIM_ERR_OK;
      }
    }
    else if (ulRPortSize == SUPPORTED_SIZE[RSP1_PRECLUSTERLISTHEADER_V6_2])
    {
      // request port version V6_2_PR_EN (RSP1V6) - provide port version V6_PR_EN - RCS Correction
      if ((ulPPortSize == SUPPORTED_SIZE[RSP1_PRECLUSTERLISTHEADER_V6]) &&
        ((pProvidePortVersionInfo == NULL) || (RSP1V6.Equals(pProvidePortVersionInfo))) &&
        (uDataVer == 6u))
      {
        const RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreClusterHeader * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreClusterHeader*>(pPPortData);
        v_Convert_v6pren_to_v62pren_RCSWorkaround(m_BufV62pren, *pSrc, uiRecVersion, ucDoRCSCorrection, ucNearOrFar);
        *pOutData = &m_BufV62pren;
        ulOutSize = sizeof(m_BufV62pren);
        lRet = SIM_ERR_OK;
      }
      // request port version V6_2_PR_EN (RSP1V6) - provide port version V5_PR_EN - RCS Correction
      else if ((ulPPortSize == SUPPORTED_SIZE[RSP1_PRECLUSTERLISTHEADER_V5]) &&
        (uDataVer == 5u))
      {
        const RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterHeader * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterHeader*>(pPPortData);
        v_Convert_v5pren_to_v6pren_RCSWorkaround(m_BufV6pren, *pSrc, uiRecVersion, 0, 0);
        v_Convert_v6pren_to_v62pren_RCSWorkaround(m_BufV62pren, m_BufV6pren, uiRecVersion, ucDoRCSCorrection, ucNearOrFar);
        *pOutData = &m_BufV62pren;
        ulOutSize = sizeof(m_BufV62pren);
        lRet = SIM_ERR_OK;
      }
      // request port version V6_2_PR_EN - provide port version V4_PR_EN
      else if ((ulPPortSize == SUPPORTED_SIZE[RSP1_PRECLUSTERLISTHEADER_V4]) &&
        (uDataVer == 4u))
      {
        const RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterHeader * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterHeader*>(pPPortData);
        v_Convert_v4pren_to_v6pren_RCSWorkaround(m_BufV6pren, *pSrc, uiRecVersion, 0, 0);
        v_Convert_v6pren_to_v62pren_RCSWorkaround(m_BufV62pren, m_BufV6pren, uiRecVersion, ucDoRCSCorrection, ucNearOrFar);
        *pOutData = &m_BufV62pren;
        ulOutSize = sizeof(m_BufV62pren);
        lRet = SIM_ERR_OK;
      }
      // request port version V6_2_PR_EN - provide port version V2_PR_EN
      else if ((ulPPortSize == SUPPORTED_SIZE[RSP1_PRECLUSTERLISTHEADER_V2]) &&
        (uDataVer == 2u))
      {
        const RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterHeader * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterHeader*>(pPPortData);
        v_Convert_v2pren_to_v4pren(m_BufV4pren,*pSrc);
        v_Convert_v4pren_to_v6pren_RCSWorkaround(m_BufV6pren,m_BufV4pren, uiRecVersion, 0, 0);
        v_Convert_v6pren_to_v62pren_RCSWorkaround(m_BufV62pren, m_BufV6pren, uiRecVersion, ucDoRCSCorrection, ucNearOrFar);
        *pOutData = &m_BufV62pren;
        ulOutSize = sizeof(m_BufV62pren);
        lRet = SIM_ERR_OK;
      }
      else
      {
        // No conversion possible
        lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
      }
    }
    else if (ulRPortSize == SUPPORTED_SIZE[RSP1_PRECLUSTERLISTHEADER_V6])          // also RSP1_PRECLUSTERLIST_V6_PR_EN
    {
      // Check Request port version, because sizes of V2_PR_EN, V4_PR_EN, V5_PR_EN and V6_PR_EN are equal.
      if (requestPortVersionInfo.Equals(&RSP1V6))
      {
        // request port version V6_PR_EN (RSP1V6) - provide port version V6_2_PR_EN - RCS Correction
        if ((ulPPortSize == SUPPORTED_SIZE[RSP1_PRECLUSTERLISTHEADER_V6_2]) &&
          (uDataVer == 6u))
        {
          const RSP1_PRECLUSTERLIST_V6_2_PR_EN::RSP_t_PreClusterHeader * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V6_2_PR_EN::RSP_t_PreClusterHeader*>(pPPortData);
          v_Convert_v62pren_to_v6pren_RCSWorkaround(m_BufV6pren, *pSrc, uiRecVersion, ucDoRCSCorrection, ucNearOrFar);
          *pOutData = &m_BufV6pren;
          ulOutSize = sizeof(m_BufV6pren);
          lRet = SIM_ERR_OK;
        }
        // request port version V6_PR_EN (RSP1V6) - provide port version V5_PR_EN - RCS Correction
        else if ((ulPPortSize == SUPPORTED_SIZE[RSP1_PRECLUSTERLISTHEADER_V5]) &&
          (uDataVer == 5u))
        {
          const RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterHeader * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterHeader*>(pPPortData);
          v_Convert_v5pren_to_v6pren_RCSWorkaround(m_BufV6pren, *pSrc, uiRecVersion, ucDoRCSCorrection, ucNearOrFar);
          *pOutData = &m_BufV6pren;
          ulOutSize = sizeof(m_BufV6pren);
          lRet = SIM_ERR_OK;
        }
        // request port version V6_PR_EN - provide port version V4_PR_EN
        else if ((ulPPortSize == SUPPORTED_SIZE[RSP1_PRECLUSTERLISTHEADER_V4]) &&
          (uDataVer == 4u))
        {
          const RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterHeader * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterHeader*>(pPPortData);
          RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterHeader * const pIntMed = &m_BufV4pren;
          v_Convert_v4pren_to_v5pren_RCSWorkaround(*pIntMed, *pSrc, uiRecVersion, ucDoRCSCorrection, ucNearOrFar);
          v_Convert_v5pren_to_v6pren_NEAR(m_BufV6pren, *pIntMed);
          *pOutData = &m_BufV6pren;
          ulOutSize = sizeof(m_BufV6pren);
          lRet = SIM_ERR_OK;
        }
        // request port version V6_PR_EN - provide port version V2_PR_EN
        else if ((ulPPortSize == SUPPORTED_SIZE[RSP1_PRECLUSTERLISTHEADER_V2]) &&
          (uDataVer == 2u))
        {
          const RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterHeader * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterHeader*>(pPPortData);
          v_Convert_v2pren_to_v4pren(m_BufV4pren,*pSrc);
          v_Convert_v4pren_to_v6pren_RCSWorkaround(m_BufV6pren, m_BufV4pren, uiRecVersion, 0, 0);
          *pOutData = &m_BufV6pren;
          ulOutSize = sizeof(m_BufV6pren);
          lRet = SIM_ERR_OK;
        }
        else
        {
          // No conversion possible
          lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
        }
      }
      if (requestPortVersionInfo.Equals(&RSP1V4) || requestPortVersionInfo.Equals(&RSP1V5))
      {
        // request port version V4_PR_EN (RSP1V4) and V5_PR_EN (RSP1V5) - provide port version V6_2_PR_EN - RCS Correction
        if ((ulPPortSize == SUPPORTED_SIZE[RSP1_PRECLUSTERLISTHEADER_V6_2]) &&
          (uDataVer == 6u))
        {
          const RSP1_PRECLUSTERLIST_V6_2_PR_EN::RSP_t_PreClusterHeader * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V6_2_PR_EN::RSP_t_PreClusterHeader*>(pPPortData);
          v_Convert_v62pren_to_v6pren_RCSWorkaround(m_BufV6pren, *pSrc, uiRecVersion, 0, 0);
          v_Convert_v6pren_to_v4pren_RCSWorkaround(m_BufV4pren, m_BufV6pren, uiRecVersion, ucDoRCSCorrection, ucNearOrFar);
          *pOutData = &m_BufV4pren;
          ulOutSize = sizeof(m_BufV4pren);
          lRet = SIM_ERR_OK;
        }
        // request port version V4_PR_EN (RSP1V4) and V5_PR_EN (RSP1V5) - provide port version V5_PR_EN - RCS Correction
        else if ((ulPPortSize == SUPPORTED_SIZE[RSP1_PRECLUSTERLISTHEADER_V6]) &&
          (uDataVer == 5u))
        {
          const RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreClusterHeader * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreClusterHeader*>(pPPortData);
          v_Convert_v6pren_to_v4pren_RCSWorkaround(m_BufV4pren, *pSrc, uiRecVersion, ucDoRCSCorrection, ucNearOrFar);
          *pOutData = &m_BufV4pren;
          ulOutSize = sizeof(m_BufV4pren);
          lRet = SIM_ERR_OK;
        }
        // request port version V4_PR_EN (RSP1V4) and V5_PR_EN (RSP1V5) - provide port version V4_PR_EN
        else if ((ulPPortSize == SUPPORTED_SIZE[RSP1_PRECLUSTERLISTHEADER_V4]) &&
          (uDataVer == 4u))
        {
          const RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreClusterHeader * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreClusterHeader*>(pPPortData);
          v_Convert_v6pren_to_v4pren_RCSWorkaround(m_BufV4pren, *pSrc, uiRecVersion, ucDoRCSCorrection, ucNearOrFar);
          *pOutData = &m_BufV4pren;
          ulOutSize = sizeof(m_BufV4pren);
          lRet = SIM_ERR_OK;
        }
        // request port version V4_PR_EN (RSP1V4) and V5_PR_EN (RSP1V5) - provide port version V2_PR_EN
        else if ((ulPPortSize == SUPPORTED_SIZE[RSP1_PRECLUSTERLISTHEADER_V2]) &&
          (uDataVer == 2u))
        {
          const RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterHeader * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterHeader*>(pPPortData);
          v_Convert_v2pren_to_v4pren(m_BufV4pren,*pSrc);
          *pOutData = &m_BufV4pren;
          ulOutSize = sizeof(m_BufV4pren);
          lRet = SIM_ERR_OK;
        }
        else
        {
          // No conversion possible
          lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
        }
      }
      if (requestPortVersionInfo.Equals(&RSP1V2))
      {
        // Not implemented, because those old request ports are not necessary

        // request port version V4_PR_EN (RSP1V4) and V5_PR_EN (RSP1V5) - provide port version V6_2_PR_EN - RCS Correction
        if ((ulPPortSize == SUPPORTED_SIZE[RSP1_PRECLUSTERLISTHEADER_V6_2]) &&
          (uDataVer == 6u))
        {
        }
        // request port version V4_PR_EN (RSP1V4) and V5_PR_EN (RSP1V5) - provide port version V5_PR_EN - RCS Correction
        else if ((ulPPortSize == SUPPORTED_SIZE[RSP1_PRECLUSTERLISTHEADER_V6]) &&
          (uDataVer == 5u))
        {
        }
        // request port version V4_PR_EN (RSP1V4) and V5_PR_EN (RSP1V5) - provide port version V4_PR_EN
        else if ((ulPPortSize == SUPPORTED_SIZE[RSP1_PRECLUSTERLISTHEADER_V4]) &&
          (uDataVer == 4u))
        {
        }
        // request port version V4_PR_EN (RSP1V4) and V5_PR_EN (RSP1V5) - provide port version V2_PR_EN
        else if ((ulPPortSize == SUPPORTED_SIZE[RSP1_PRECLUSTERLISTHEADER_V2]) &&
          (uDataVer == 2u))
        {
        }
        else
        {
          // No conversion possible
          lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
        }
      }
      else
      {
        // No conversion possible
        lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
      }
    }
    else
    {
      // Not supported conversion, since destination port not supported
      lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
    }
  }

  return lRet;
}

/** returns:
 *   SIM_ERR_OK - when this value can be used
 *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implememnted here
 *                                            and the default value from Request Port must be used
 */
long CConvRSP1PreClusterListHeader::GetDefaultValue(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  void **pDefaultData, unsigned long &ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == SUPPORTED_SIZE[RSP1_PRECLUSTERLISTHEADER_V100_B]) &&
      (VERSION_NUMBERS[RSP1_PRECLUSTERLISTHEADER_V100_B]->Equals(&requestPortVersionInfo)))
    {
      RSP1_PRECLUSTERLIST_V100_B::RSP_t_PreClusterHeader & Dest = m_BufV100_B;
      InitPreClusterHeader(Dest, 0x100);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[RSP1_PRECLUSTERLISTHEADER_V100_A]) &&
      (VERSION_NUMBERS[RSP1_PRECLUSTERLISTHEADER_V100_A]->Equals(&requestPortVersionInfo)))
    {
      RSP1_PRECLUSTERLIST_V100_A::RSP_t_PreClusterHeader & Dest = m_BufV100_A;
      InitPreClusterHeader(Dest, 0x100);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[RSP1_PRECLUSTERLISTHEADER_V6_2]) &&
      (VERSION_NUMBERS[RSP1_PRECLUSTERLISTHEADER_V6_2]->Equals(&requestPortVersionInfo)))
    {
      RSP1_PRECLUSTERLIST_V6_2_PR_EN::RSP_t_PreClusterHeader & Dest = m_BufV62pren;
      InitPreClusterHeader(Dest, 6);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[RSP1_PRECLUSTERLISTHEADER_V6]) &&
      (VERSION_NUMBERS[RSP1_PRECLUSTERLISTHEADER_V6]->Equals(&requestPortVersionInfo)))
    {
      RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreClusterHeader & Dest = m_BufV6pren;
      InitPreClusterHeader(Dest, 0);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[RSP1_PRECLUSTERLISTHEADER_V5]) &&
      (VERSION_NUMBERS[RSP1_PRECLUSTERLISTHEADER_V5]->Equals(&requestPortVersionInfo)))
    {
      RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterHeader & Dest = m_BufV4pren;
      InitPreClusterHeader(Dest, 0);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[RSP1_PRECLUSTERLISTHEADER_V4]) &&
      (VERSION_NUMBERS[RSP1_PRECLUSTERLISTHEADER_V4]->Equals(&requestPortVersionInfo)))
    {
      RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterHeader & Dest = m_BufV4pren;
      InitPreClusterHeader(Dest, 0);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[RSP1_PRECLUSTERLISTHEADER_V2]) &&
      (VERSION_NUMBERS[RSP1_PRECLUSTERLISTHEADER_V2]->Equals(&requestPortVersionInfo)))
    {
      RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterHeader & Dest = m_BufV2pren;
      InitPreClusterHeader(Dest, 0);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
  }
  return lRet;
}

// used to check if an unversioned PPort is compatible with a certain version of RPort
bool CConvRSP1PreClusterListHeader::IsVersionCompatibleWithType(
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
    if ((IsPortSupported(ulRPortSize, &requestPortVersionInfo)) && (IsPortSupported(ulPPortSize, NULL)))
    {
      bResult = true;
    }
  }
  return bResult;
}

// used to check if ports are compatible between different versions
bool CConvRSP1PreClusterListHeader::AreVersionsCompatible(
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
    if ((IsPortSupported(ulRPortSize, &requestPortVersionInfo)) && (IsPortSupported(ulPPortSize, &providePortVersionInfo)))
    {
      bResult = true;
    }
  }
  return bResult;
}

//
// The one and only externally visible factory function
//
IConverter * CreateRSP1PreClusterListHeaderConvClass(void)
{
  return new CConvRSP1PreClusterListHeader();
}