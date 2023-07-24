/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter

  MODULNAME:            sim_conv_FPGA_StaticPeakList

  DESCRIPTION:          Convert static peak list

  AUTHOR:               Gergely Ungvary

  CREATION DATE:        07.02.2013

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: sim_conv_FPGA_StaticPeakList.cpp  $
  CHANGES:              Revision 1.1 2017/08/10 13:15:30CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/rsp/project.pj
  CHANGES:              Revision 1.1 2013/02/07 13:56:12CET ungvaryg 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CRT_CommonRadarToolbox/04_Engineering/03_Workspace/algo/sim_adapter/rsp/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */
#include "sim_conv_FPGA_StaticPeakList.h"
#include <math.h>

#include "sim_versioninfo_impl.h"
#include "interface_peak_list_ars400.h"

class CConvFPGAStaticPeakList : public CSimConverterBase
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

  PeakListV0::FPGA_t_StaticPlFar  m_FarV0;
  PeakListV0::FPGA_t_StaticPlNear m_NearV0;
  PeakListV1::FPGA_t_StaticPlFar  m_FarV1;
  PeakListV1::FPGA_t_StaticPlNear m_NearV1;
  unsigned int                    m_nNumDynPeaks;
  PeakListV0::FPGA_t_RangeCell  * m_pDynPeaks;

  void InitPeak(PeakListV0::FPGA_t_RangeCell & Dest) const
  {
    ::memset(&Dest, 0, sizeof(Dest));
  };

  void InitPeakList(PeakListV0::FPGA_t_StaticPlFar & Dest) const
  {
    for (unsigned int i=0; i<PeakListV0::NumFarPeaks; i++)
    {
      InitPeak(Dest.a_RangeCell[i]);
    }
  };

  void InitPeakList(PeakListV0::FPGA_t_StaticPlNear & Dest) const
  {
    for (unsigned int i=0; i<PeakListV0::NumNearPeaks; i++)
    {
      InitPeak(Dest.a_RangeCell[i]);
    }
  };

  void InitPeakList(PeakListV1::FPGA_t_StaticPlFar & Dest) const
  {
    for (unsigned int i=0; i<PeakListV1::NumFarPeaks; i++)
    {
      InitPeak(Dest.a_RangeCell[i]);
    }
  };

  void InitPeakList(PeakListV1::FPGA_t_StaticPlNear & Dest) const
  {
    for (unsigned int i=0; i<PeakListV1::NumNearPeaks; i++)
    {
      InitPeak(Dest.a_RangeCell[i]);
    }
  };

public:

  CConvFPGAStaticPeakList(void): CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT),
    m_FarV0(), m_NearV0(), m_FarV1(), m_NearV1(), m_nNumDynPeaks(0), m_pDynPeaks(NULL)
  {
    InitPeakList(m_FarV0);
    InitPeakList(m_NearV0);
    InitPeakList(m_FarV1);
    InitPeakList(m_NearV1);
  };

  // Not implemented copy constructor to get linker error
  CConvFPGAStaticPeakList(const CConvFPGAStaticPeakList & init);

  virtual ~CConvFPGAStaticPeakList(void)
  {
    if (m_pDynPeaks != NULL)
    {
      delete [] m_pDynPeaks;
      m_pDynPeaks = NULL;
    }
  };

  // IConverterDestroy::Destroy implementation
  virtual void Destroy()
  {
    delete this;
  };

  // IConverter::GetTypeName implementation
  virtual const char* GetTypeName(void)
  {
    return "FPGA_StaticPeakList";
  };

  bool IsPortSupported(unsigned long ulPortSize, const IVersionInfo * pPortVersion) const
  {
    if (((pPortVersion == NULL) || (pPortVersion->Equals(&BASE_VERSION)))
    &&(
      (ulPortSize == sizeof(PeakListV1::FPGA_t_StaticPlFar)) ||
      (ulPortSize == sizeof(PeakListV1::FPGA_t_StaticPlNear)) ||
      (ulPortSize == sizeof(PeakListV0::FPGA_t_StaticPlFar)) ||
      (ulPortSize == sizeof(PeakListV0::FPGA_t_StaticPlNear))
      ) )
    {
      return true;
    }
    return false;
  };

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

  //enum eFPGAStaticPeakListVersion
  //{
  //  FPGA_STATIC_PEAK_VERSION_COUNT
  //};
  //static unsigned long SUPPORTED_SIZE[FPGA_STATIC_PEAK_VERSION_COUNT];

  //static const CVersionInfoImpl * const FPGA_STATIC_PEAK_LIST_VERSIONS[FPGA_STATIC_PEAK_VERSION_COUNT];
};

CVersionInfoImpl  CConvFPGAStaticPeakList::BASE_VERSION(0, 0, 0);
//
//unsigned long CConvFPGAStaticPeakList::SUPPORTED_SIZE[CConvFPGAStaticPeakList::FPGA_STATIC_PEAK_VERSION_COUNT]=
//{
//};
//
//const CVersionInfoImpl * const CConvFPGAStaticPeakList::FPGA_STATIC_PEAK_LIST_VERSIONS[FPGA_STATIC_PEAK_VERSION_COUNT] =
//{
//  &BASE_VERSION,
//  &RSP_CTX_VERSION_V0,
//  &RSP_CTX_VERSION_V1,
//  &RSP_CTX_VERSION_V1_1,
//  &RSP_CTX_VERSION_V2
//};


long CConvFPGAStaticPeakList::ConvertData(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo, 
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo* pProvidePortVersionInfo, 
    void* pPPortData,
    void** pOutData, unsigned long& ulOutSize)
{
  long lRet;

  // If direct one-one copy possible do that
  if ((ulRPortSize == ulPPortSize) && ((pProvidePortVersionInfo == NULL) || (requestPortVersionInfo.Equals(pProvidePortVersionInfo))))
  {
    *pOutData = pPPortData;
    ulOutSize = ulRPortSize;
    lRet = SIM_ERR_OK;
  }
  else
  {
    // First branch to decide which version we are converting to
    if ((ulRPortSize == sizeof(PeakListV1::FPGA_t_StaticPlFar)) && (requestPortVersionInfo.Equals(&BASE_VERSION)))
    {
      // Request port has layout of version 1 far, convert to that
      PeakListV1::FPGA_t_StaticPlFar * const pDest = &m_FarV1;

      if ((ulPPortSize == sizeof(PeakListV0::FPGA_t_StaticPlFar)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&BASE_VERSION))))
      {
        const PeakListV0::FPGA_t_StaticPlFar * const pSrc = reinterpret_cast<const PeakListV0::FPGA_t_StaticPlFar*>(pPPortData);
        for (unsigned int i=0; i<PeakListV0::NumFarPeaks; i++)
        {
          pDest->a_RangeCell[i] = pSrc->a_RangeCell[i];
        }
        for (unsigned int i=PeakListV0::NumFarPeaks; i<PeakListV1::NumFarPeaks; i++)
        {
          InitPeak(pDest->a_RangeCell[i]);
        }
        *pOutData = pDest;
        ulOutSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
      else
      {
        // No conversion possible
        lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
      }
    }
    else if ((ulRPortSize == sizeof(PeakListV1::FPGA_t_StaticPlNear)) && (requestPortVersionInfo.Equals(&BASE_VERSION)))
    {
      // Request port has layout of version 1 near, convert to that
      PeakListV1::FPGA_t_StaticPlNear * const pDest = &m_NearV1;

      if ((ulPPortSize == sizeof(PeakListV0::FPGA_t_StaticPlNear)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&BASE_VERSION))))
      {
        const PeakListV0::FPGA_t_StaticPlNear * const pSrc = reinterpret_cast<const PeakListV0::FPGA_t_StaticPlNear*>(pPPortData);
        for (unsigned int i=0; i<PeakListV1::NumNearPeaks; i++)
        {
          pDest->a_RangeCell[i] = pSrc->a_RangeCell[i];
        }
        *pOutData = pDest;
        ulOutSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
      else
      {
        // No conversion possible
        lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
      }
    }
    else if ((ulRPortSize == sizeof(PeakListV0::FPGA_t_StaticPlFar)) && (requestPortVersionInfo.Equals(&BASE_VERSION)))
    {
      // Request port has layout of version 0 far, convert to that
      PeakListV0::FPGA_t_StaticPlFar * const pDest = &m_FarV0;

      if ((ulPPortSize == sizeof(PeakListV1::FPGA_t_StaticPlFar)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&BASE_VERSION))))
      {
        const PeakListV1::FPGA_t_StaticPlFar * const pSrc = reinterpret_cast<const PeakListV1::FPGA_t_StaticPlFar*>(pPPortData);
        for (unsigned int i=0; i<PeakListV0::NumFarPeaks; i++)
        {
          pDest->a_RangeCell[i] = pSrc->a_RangeCell[i];
        }
        *pOutData = pDest;
        ulOutSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
      else
      {
        // No conversion possible
        lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
      }
    }
    else if ((ulRPortSize == sizeof(PeakListV0::FPGA_t_StaticPlNear)) && (requestPortVersionInfo.Equals(&BASE_VERSION)))
    {
      // Request port has layout of version 0 near, convert to that
      PeakListV0::FPGA_t_StaticPlNear * const pDest = &m_NearV0;

      if ((ulPPortSize == sizeof(PeakListV1::FPGA_t_StaticPlNear)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&BASE_VERSION))))
      {
        const PeakListV1::FPGA_t_StaticPlNear * const pSrc = reinterpret_cast<const PeakListV1::FPGA_t_StaticPlNear*>(pPPortData);
        for (unsigned int i=0; i<PeakListV1::NumNearPeaks; i++)
        {
          pDest->a_RangeCell[i] = pSrc->a_RangeCell[i];
        }
        for (unsigned int i=PeakListV1::NumNearPeaks; i<PeakListV0::NumNearPeaks; i++)
        {
          InitPeak(pDest->a_RangeCell[i]);
        }
        *pOutData = pDest;
        ulOutSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
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
  // Check if above normal conversion failed
  if (lRet == SIM_ERR_UNADAPTABLE_DATA_PORTS)
  {
    // Try last ditch dynamic conversion based on length
    const unsigned int ProNumCells = (ulPPortSize / sizeof(PeakListV0::FPGA_t_RangeCell));
    const unsigned int ReqNumCells = (ulRPortSize / sizeof(PeakListV0::FPGA_t_RangeCell));
    // The size of the provide/request port has to be a multiple of the cell we know
    if (((ProNumCells * sizeof(PeakListV0::FPGA_t_RangeCell)) == ulPPortSize) &&
      ((ReqNumCells * sizeof(PeakListV0::FPGA_t_RangeCell)) == ulRPortSize))
    {
      // Since the number of cells can be just about anything, allocate
      // a large enough buffer for destination data
      if (m_nNumDynPeaks < ReqNumCells)
      {
        if (m_pDynPeaks != NULL)
        {
          delete [] m_pDynPeaks;
        }
        m_pDynPeaks = new PeakListV0::FPGA_t_RangeCell[ReqNumCells];
        m_nNumDynPeaks = ReqNumCells;
      }
      // Verify that buffer is there
      if (m_pDynPeaks != NULL)
      {
        const PeakListV0::FPGA_t_RangeCell * const pSrc = reinterpret_cast<const PeakListV0::FPGA_t_RangeCell*>(pPPortData);
        const unsigned int NumCopyCells = min(ProNumCells, ReqNumCells);
        for (unsigned int i=0; i<NumCopyCells; i++)
        {
          m_pDynPeaks[i] = pSrc[i];
        }
        for (unsigned int i=NumCopyCells; i<ReqNumCells; i++)
        {
          InitPeak(m_pDynPeaks[i]);
        }
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
long CConvFPGAStaticPeakList::GetDefaultValue(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo, 
    void** pDefaultData, unsigned long& ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == sizeof(m_FarV1)) &&
      (BASE_VERSION.Equals(&requestPortVersionInfo)))
    {
      PeakListV1::FPGA_t_StaticPlFar & Dest = m_FarV1;
      InitPeakList(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_NearV1)) &&
      (BASE_VERSION.Equals(&requestPortVersionInfo)))
    {
      PeakListV1::FPGA_t_StaticPlNear & Dest = m_NearV1;
      InitPeakList(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_FarV0)) &&
      (BASE_VERSION.Equals(&requestPortVersionInfo)))
    {
      PeakListV0::FPGA_t_StaticPlFar & Dest = m_FarV0;
      InitPeakList(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_NearV0)) &&
      (BASE_VERSION.Equals(&requestPortVersionInfo)))
    {
      PeakListV0::FPGA_t_StaticPlNear & Dest = m_NearV0;
      InitPeakList(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
  }
  return lRet;
}

// used to check if an unversioned PPort is compatible with a certain version of RPort
bool CConvFPGAStaticPeakList::IsVersionCompatibleWithType(
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
bool CConvFPGAStaticPeakList::AreVersionsCompatible(
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
IConverter * CreateFPGAStaticPeakListConvClass(void)
{
  return new CConvFPGAStaticPeakList();
}
