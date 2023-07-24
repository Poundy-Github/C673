/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter_fct

  MODULNAME:            sim_conv_cp_traj_state.cpp

  DESCRIPTION:          Conversion class for curve observer init data

  AUTHOR:               Gergely Ungvary

  CREATION DATE:        16.01.2012

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: sim_conv_cp_traj_state.cpp  $
  CHANGES:              Revision 1.1 2021/12/13 17:20:56CET Wang, David (Wangd3) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_adapter/fct/project.pj
  CHANGES:              Revision 1.1 2017/08/10 13:15:12CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/fct/project.pj
  CHANGES:              Revision 1.2 2013/05/21 18:04:23CEST ungvaryg 
  CHANGES:              Modify for ARS4xx 'big' adapter: remove class declarations and complex includes from individual headers (only leaving factory
  CHANGES:              function external declaration there), moving class declaration and all additional includes into cpp file. Add single factory function
  CHANGES:              per data conversion stream.
  CHANGES:              Note: otherwise no functional changes made, thus the new revisions perform the exact same conversions (ARS3xx) as previously
  CHANGES:              - Added comments -  ungvaryg [May 21, 2013 6:04:23 PM CEST]
  CHANGES:              Change Package : 172401:1 http://mks-psad:7002/im/viewissue?selection=172401
  CHANGES:              Revision 1.1 2012/01/16 09:32:16CET Apel, Norman (apeln) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/PROJECTS/ARS301/06_Algorithm/04_Engineering/03_Workspace/algo/fct_sim/fct_adapt/project.pj
  
**************************************************************************** */
/* includes ---------------------------------------------------------------- */
#include "stdafx.h"
#include "sim_conv_cp_traj_state.h"
#include "sim_versioninfo_impl.h"

class CConvCpTrajState : public CSimConverterBase
{
public:

  static const char* GetConverterTypeName()
  {
    return "SICPStateInit";
  }

  CConvCpTrajState(void);
  virtual ~CConvCpTrajState(void);

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

  ui16_t m_InitData;
};

CVersionInfoImpl   CConvCpTrajState::BASE_VERSION(0, 0, 0);

static void Swap16Bit(const ui16_t * pSrc, ui16_t * pDest)
{
  *pDest = 
    ((*pSrc & 0x8000u) >> 15) |
    ((*pSrc & 0x4000u) >> 13) |
    ((*pSrc & 0x2000u) >> 11) |
    ((*pSrc & 0x1000u) >> 9) |
    ((*pSrc & 0x0800u) >> 7) |
    ((*pSrc & 0x0400u) >> 5) |
    ((*pSrc & 0x0200u) >> 3) |
    ((*pSrc & 0x0100u) >> 1) |
    ((*pSrc & 0x0080u) << 1) |
    ((*pSrc & 0x0040u) << 3) |
    ((*pSrc & 0x0020u) << 5) |
    ((*pSrc & 0x0010u) << 7) |
    ((*pSrc & 0x0008u) << 9) |
    ((*pSrc & 0x0004u) << 11) |
    ((*pSrc & 0x0002u) << 13) |
    ((*pSrc & 0x0001u) << 15);
}

CConvCpTrajState::CConvCpTrajState(void)
: CSimConverterBase(NULL/*DEP_NAMES*/, 0), m_InitData()
{
  memset(&m_InitData, 0, sizeof(m_InitData));
}

CConvCpTrajState::~CConvCpTrajState(void)
{
}

long CConvCpTrajState::ConvertData(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo, 
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo* pProvidePortVersionInfo, 
    void* pPPortData,
    void** pOutData, unsigned long& ulOutSize)
{
  long retval = SIM_ERR_UNDEFINED;

  // First check what type of receive port we are dealing with: it should normally be the
  // initialization structure declared in fct_init.h
  if ((ulRPortSize == sizeof(m_InitData)) && (eRPortType == simOPAQUE_t))
  {
    // Check for 16 bit wide state
    if (ulPPortSize == 2u)
    {
      // Swap bitfield assuming the source is Big-Endian. This needs to be changed if source will ever be Little-Endian
      Swap16Bit(reinterpret_cast<const ui16_t*>(pPPortData), reinterpret_cast<ui16_t*>(&m_InitData));
      *pOutData = &m_InitData;
      ulOutSize = sizeof(m_InitData);
      retval = SIM_ERR_OK;
    }
  }
  *pOutData = &m_InitData;
  ulOutSize = sizeof(m_InitData);

  return retval;
}

/** returns: 
 *   SIM_ERR_OK - when this value can be used
 *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implememnted here
 *                                            and the default value from Request Port must be used
 */
long CConvCpTrajState::GetDefaultValue(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo, 
    void** pDefaultData, unsigned long& ulDefaultSize)
{
  if ((eRPortType == simOPAQUE_t)
    && (ulRPortSize == sizeof(m_InitData)))
  {
    memset(&m_InitData, 0, sizeof(m_InitData));
    *pDefaultData = &m_InitData;
    ulDefaultSize = sizeof(m_InitData);
    return SIM_ERR_OK;
  }
  return SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
}

// used to check if an unversioned PPort is compatible with a certain version of RPort
bool CConvCpTrajState::IsVersionCompatibleWithType(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo, 
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize)
{
  return true;
}

// used to check if ports are compatible between different versions
bool CConvCpTrajState::AreVersionsCompatible(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo& providePortVersionInfo)
{
  bool bResult = false;
  if ((eRPortType == simOPAQUE_t) && (ulRPortSize == sizeof(m_InitData)))
  {
    if (ulPPortSize == sizeof(ui16_t))
    {
      bResult = true;
    }
  }
  return bResult;
}

//
// Externally visible function for creating new conversion instance
//

IConverter * CreateCpTrajStateConvInstance(void)
{
  return new CConvCpTrajState();
}
