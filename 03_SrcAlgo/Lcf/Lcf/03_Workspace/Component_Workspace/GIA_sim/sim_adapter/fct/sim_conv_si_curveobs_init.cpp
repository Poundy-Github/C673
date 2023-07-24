/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter_fct

  MODULNAME:            sim_conv_si_curveobs_init.cpp

  DESCRIPTION:          Conversion class for curve observer init data

  AUTHOR:               Gergely Ungvary

  CREATION DATE:        08.10.2010

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: sim_conv_si_curveobs_init.cpp  $
  CHANGES:              Revision 1.1 2017/08/10 13:15:21CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/fct/project.pj
  CHANGES:              Revision 1.6 2016/02/29 14:46:55CET Cretu, Teodora (CretuT) 
  CHANGES:              A new namespace for RPort is defined: FCT_SICurveObsInitData_V1::SICurveObsInitData_t  m_InitData_V1 and checked in the IsVersionCompatibleWithType()
  CHANGES:              Revision 1.5 2016/02/16 10:41:39CET Dagli-EXT, Goekhan (uidj7850) 
  CHANGES:              - introducing namespaces
  CHANGES:              - additional Version
  CHANGES:              Revision 1.4 2015/09/23 13:13:07CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              Minor updates (for ARS4D0 using car meas)
  CHANGES:              - Added comments -  berndtt1 [Sep 23, 2015 1:17:38 PM CEST]
  CHANGES:              Change Package : 221167:55 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.3 2013/06/19 16:54:18CEST Ungvary, Gergely (ungvaryg) 
  CHANGES:              Streamline header file (move conversion class declaration to cpp source, leaving only factory method here)
  CHANGES:              Remove dependency on fct_init.h (layout of CP/SI Init structure now local in Cpp source)
  CHANGES:              --- Added comments ---  ungvaryg [Jun 19, 2013 4:54:18 PM CEST]
  CHANGES:              Change Package : 179559:3 http://mks-psad:7002/im/viewissue?selection=179559
  CHANGES:              Revision 1.2 2011/09/08 16:12:16CEST Apel, Norman (apeln) 
  CHANGES:              - BUGFIX init of CurveObserver
  CHANGES:              --- Added comments ---  apeln [Sep 8, 2011 4:12:16 PM CEST]
  CHANGES:              Change Package : 77634:3 http://mks-psad:7002/im/viewissue?selection=77634
  CHANGES:              Revision 1.1 2010/10/08 12:40:09CEST Gergely Ungvary (ungvaryg) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/PROJECTS/ARS301/06_Algorithm/04_Engineering/03_Workspace/algo/fct_sim/fct_adapt/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */
#include "stdafx.h"
#include "sim_conv_si_curveobs_init.h"
#include "sim_converter_base.h"
#include "sim_versioninfo_impl.h"

namespace FCT_SICurveObsInitData_V1 {
  typedef struct {
    bool_t  bRangeFacAvail;
    f32_t   fRangeFac;

    bool_t  bDrivenDistAvail;
    f32_t   fDrivenDist;

    bool_t  bSumCurveAvail;
    f32_t   fSumCurve;

    bool_t  bNumberOfSamplesAvail;
    i32_t   iNumberOfSamples;

    bool_t  bMeanCurveHistAvail;
    f32_t   fMeanCurveHist[5];

    bool_t  bComplexRangeFacAvail;
    f32_t   fComplexRangeFac;
  } SICurveObsInitData_t;
}

namespace FCT_SICurveObsInitData_V2 {
  typedef struct {
    bool_t  bRangeFacAvail;
    f32_t   fRangeFac;

    bool_t  bDrivenDistAvail;
    f32_t   fDrivenDist;

    bool_t  bSumCurveAvail;
    f32_t   fSumCurve;

    bool_t  bNumberOfSamplesAvail;
    i32_t   iNumberOfSamples;

    bool_t  bMeanCurveHistAvail;
    f32_t   fMeanCurveHist[5];

    bool_t  bComplexRangeFacAvail;
    f32_t   fComplexRangeFac;

    bool_t bDistRoad2VDYAbsAvail;
    f32_t f_RoadVDYDeltaFar;
    f32_t f_RoadVDYDeltaNear;
  } SICurveObsInitData_t;
}

#define SI_CURVEOBS_NB_MEANVALUES   ((ui8_t) 5)

namespace FCT_SI_CurveObserv_RangeRed_V1 {
  typedef struct
  {
    f32_t RangeFactor;
  } SI_CurveObserv_RangeRed_t;
};

namespace FCT_SI_CurveObserv_RangeRed_V2 {
  typedef struct
  {
    f32_t DrivenDist;
    f32_t SumCurveAbs;
    i32_t NumberSamples;
    f32_t MeanCurveHist[SI_CURVEOBS_NB_MEANVALUES];

    f32_t RangeFactor;
  } SI_CurveObserv_RangeRed_t;
};

namespace FCT_SI_CurveObserv_RangeRed_V3 {
  typedef struct
  {
    f32_t RangeFactor;
    
    f32_t RoadVDYDeltaFar;
    f32_t RoadVDYDeltaNear;
  } SI_CurveObserv_RangeRed_t;
};

namespace FCT_SI_CurveObserv_RangeRed_V4 {
  typedef struct
  {
    f32_t DrivenDist;
    f32_t SumCurveAbs;
    i32_t NumberSamples;
    f32_t MeanCurveHist[SI_CURVEOBS_NB_MEANVALUES];

    f32_t RangeFactor;
    
    f32_t RoadVDYDeltaFar;
    f32_t RoadVDYDeltaNear;
  } SI_CurveObserv_RangeRed_t;
};

class CConvCurveObsInit :
  public CSimConverterBase
{
public:

  static const char* GetConverterTypeName()
  {
    return "SICurveObsInit";
  }

  CConvCurveObsInit(void);
  virtual ~CConvCurveObsInit(void);

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

  //static CVersionInfoImpl BASE_VERSION;

  FCT_SICurveObsInitData_V1::SICurveObsInitData_t  m_InitData_V1;
  FCT_SICurveObsInitData_V2::SICurveObsInitData_t  m_InitData;

  enum FCT_SI_CurveObserv_RangeRed
  {
    FCT_SI_CURVEOBSERV_RANGERED_V1,
    FCT_SI_CURVEOBSERV_RANGERED_V2,
    FCT_SI_CURVEOBSERV_RANGERED_V3,
    FCT_SI_CURVEOBSERV_RANGERED_V4,
    SICURVEOBSERVRANGERED_VERSION_COUNT
  };
  
  static const unsigned long SUPPORTED_SIZE[SICURVEOBSERVRANGERED_VERSION_COUNT];

  bool IsPortSupported(unsigned long ulPortSize) const
  {
    for (int nI = 0; nI < SICURVEOBSERVRANGERED_VERSION_COUNT; nI++)
    {
      if (ulPortSize == SUPPORTED_SIZE[nI])
      {
        return true;
      }
    };
    return false;
  };
};

const unsigned long CConvCurveObsInit::SUPPORTED_SIZE[CConvCurveObsInit::SICURVEOBSERVRANGERED_VERSION_COUNT] =
{
  sizeof(FCT_SI_CurveObserv_RangeRed_V1::SI_CurveObserv_RangeRed_t),
  sizeof(FCT_SI_CurveObserv_RangeRed_V2::SI_CurveObserv_RangeRed_t),
  sizeof(FCT_SI_CurveObserv_RangeRed_V3::SI_CurveObserv_RangeRed_t),
  sizeof(FCT_SI_CurveObserv_RangeRed_V4::SI_CurveObserv_RangeRed_t),
};

//CVersionInfoImpl CConvCurveObsInit::BASE_VERSION(0, 0, 0);

CConvCurveObsInit::CConvCurveObsInit(void)
: CSimConverterBase(NULL/*DEP_NAMES*/, 0), m_InitData()
{
  memset(&m_InitData, 0, sizeof(m_InitData));
}

CConvCurveObsInit::~CConvCurveObsInit(void)
{
}

long CConvCurveObsInit::ConvertData(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo, 
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo* pProvidePortVersionInfo, 
    void* pPPortData,
    void** pOutData, unsigned long& ulOutSize)
{
  long retval = SIM_ERR_UNDEFINED;

  // First check what type of receive port we are dealing with: it should normally be the
  // initialization structure declared in fct_init.h
  if (((ulRPortSize == sizeof(FCT_SICurveObsInitData_V1::SICurveObsInitData_t)) ||
    (ulRPortSize == sizeof(FCT_SICurveObsInitData_V2::SICurveObsInitData_t))) && (eRPortType == simOPAQUE_t))
  {
    // Provide Port Version 1
    if ((ulPPortSize == sizeof(FCT_SI_CurveObserv_RangeRed_V1::SI_CurveObserv_RangeRed_t)) && ((ePPortType == simF32_t) || (ePPortType == simOPAQUE_t)))
    {
      const FCT_SI_CurveObserv_RangeRed_V1::SI_CurveObserv_RangeRed_t *pData = reinterpret_cast<FCT_SI_CurveObserv_RangeRed_V1::SI_CurveObserv_RangeRed_t *>(pPPortData);
      memset(&m_InitData, 0, sizeof(m_InitData));
      m_InitData.bRangeFacAvail = true;
      m_InitData.fRangeFac      = pData->RangeFactor;
      retval = SIM_ERR_OK;
    }
    // Provide Port Version 2
    else if ((ulPPortSize == sizeof(FCT_SI_CurveObserv_RangeRed_V2::SI_CurveObserv_RangeRed_t)) && (ePPortType == simOPAQUE_t))
    {
      const FCT_SI_CurveObserv_RangeRed_V2::SI_CurveObserv_RangeRed_t *pData = reinterpret_cast<FCT_SI_CurveObserv_RangeRed_V2::SI_CurveObserv_RangeRed_t *>(pPPortData);
      memset(&m_InitData, 0, sizeof(m_InitData));
      m_InitData.bDrivenDistAvail       = true;
      m_InitData.fDrivenDist            = pData->DrivenDist;
      m_InitData.bSumCurveAvail         = true;
      m_InitData.fSumCurve              = pData->SumCurveAbs;
      m_InitData.bNumberOfSamplesAvail  = true;
      m_InitData.iNumberOfSamples       = pData->NumberSamples;
      m_InitData.bMeanCurveHistAvail    = true;
      for (unsigned int i=0; i<SI_CURVEOBS_NB_MEANVALUES; i++)
      {
        m_InitData.fMeanCurveHist[i]  = pData->MeanCurveHist[i];
      }
      m_InitData.bComplexRangeFacAvail  = true;
      m_InitData.fComplexRangeFac       = pData->RangeFactor;
      retval = SIM_ERR_OK;
    }
    // Provide Port Version 3
    else if ((ulPPortSize == sizeof(FCT_SI_CurveObserv_RangeRed_V3::SI_CurveObserv_RangeRed_t)) && (ePPortType == simOPAQUE_t))
    {
      const FCT_SI_CurveObserv_RangeRed_V3::SI_CurveObserv_RangeRed_t *pData = reinterpret_cast<FCT_SI_CurveObserv_RangeRed_V3::SI_CurveObserv_RangeRed_t *>(pPPortData);
      memset(&m_InitData, 0, sizeof(m_InitData));
      m_InitData.bComplexRangeFacAvail  = true;
      m_InitData.fComplexRangeFac       = pData->RangeFactor;
      m_InitData.bDistRoad2VDYAbsAvail  = true;
      m_InitData.f_RoadVDYDeltaFar      = pData->RoadVDYDeltaFar;
      m_InitData.f_RoadVDYDeltaNear     = pData->RoadVDYDeltaNear;
      retval = SIM_ERR_OK;
    }
    // Provide Port Version 4
    else if ((ulPPortSize == sizeof(FCT_SI_CurveObserv_RangeRed_V4::SI_CurveObserv_RangeRed_t)) && (ePPortType == simOPAQUE_t))
    {
      const FCT_SI_CurveObserv_RangeRed_V4::SI_CurveObserv_RangeRed_t *pData = reinterpret_cast<FCT_SI_CurveObserv_RangeRed_V4::SI_CurveObserv_RangeRed_t *>(pPPortData);
      if (ulRPortSize == sizeof(m_InitData))
      {
        memset(&m_InitData, 0, sizeof(m_InitData));
        m_InitData.bDrivenDistAvail       = true;
        m_InitData.fDrivenDist            = pData->DrivenDist;
        m_InitData.bSumCurveAvail         = true;
        m_InitData.fSumCurve              = pData->SumCurveAbs;
        m_InitData.bNumberOfSamplesAvail  = true;
        m_InitData.iNumberOfSamples       = pData->NumberSamples;
        m_InitData.bMeanCurveHistAvail    = true;
        for (unsigned int i=0; i<SI_CURVEOBS_NB_MEANVALUES; i++)
        {
          m_InitData.fMeanCurveHist[i]  = pData->MeanCurveHist[i];
        }
        m_InitData.bComplexRangeFacAvail  = true;
        m_InitData.fComplexRangeFac       = pData->RangeFactor;
        m_InitData.bDistRoad2VDYAbsAvail  = true;
        m_InitData.f_RoadVDYDeltaFar      = pData->RoadVDYDeltaFar;
        m_InitData.f_RoadVDYDeltaNear     = pData->RoadVDYDeltaNear;
      }
      else if (ulRPortSize == sizeof(m_InitData_V1))
      {
        memset(&m_InitData_V1, 0, sizeof(m_InitData_V1));
        m_InitData_V1.bDrivenDistAvail       = true;
        m_InitData_V1.fDrivenDist            = pData->DrivenDist;
        m_InitData_V1.bSumCurveAvail         = true;
        m_InitData_V1.fSumCurve              = pData->SumCurveAbs;
        m_InitData_V1.bNumberOfSamplesAvail  = true;
        m_InitData_V1.iNumberOfSamples       = pData->NumberSamples;
        m_InitData_V1.bMeanCurveHistAvail    = true;
        for (unsigned int i=0; i<SI_CURVEOBS_NB_MEANVALUES; i++)
        {
          m_InitData_V1.fMeanCurveHist[i]  = pData->MeanCurveHist[i];
        }
        m_InitData_V1.bComplexRangeFacAvail  = true;
        m_InitData_V1.fComplexRangeFac       = pData->RangeFactor;
        m_InitData_V1.bRangeFacAvail         = true;
        m_InitData_V1.fRangeFac              = pData->RangeFactor;
      }
      retval = SIM_ERR_OK;
    }
  }

  if (ulRPortSize == sizeof(m_InitData))
  {
    *pOutData = &m_InitData;
  }
  else if (ulRPortSize == sizeof(m_InitData_V1))
  {
    *pOutData = &m_InitData_V1;
  }
  if (ulRPortSize == sizeof(FCT_SICurveObsInitData_V1::SICurveObsInitData_t))
  {
    ulOutSize = sizeof(FCT_SICurveObsInitData_V1::SICurveObsInitData_t);
  }
  else if (ulRPortSize == sizeof(FCT_SICurveObsInitData_V2::SICurveObsInitData_t))
  {
    ulOutSize = sizeof(FCT_SICurveObsInitData_V2::SICurveObsInitData_t);
  }

  return retval;
}

/** returns: 
 *   SIM_ERR_OK - when this value can be used
 *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implememnted here
 *                                            and the default value from Request Port must be used
 */
long CConvCurveObsInit::GetDefaultValue(
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
bool CConvCurveObsInit::IsVersionCompatibleWithType(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo, 
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize)
{
  bool bResult = false;
  // Equal ports are always compatible (at least assumed to be)
  if ((ulRPortSize == ulPPortSize) && (eRPortType == ePPortType))
  {
    bResult = true;
  }
  else if (((ulRPortSize == sizeof(m_InitData)) || (ulRPortSize == sizeof(m_InitData_V1))) && (eRPortType == simOPAQUE_t))
  {
    if ((IsPortSupported(ulPPortSize)) & (ePPortType == simOPAQUE_t))
    {
      bResult = true;
    }
  }
  return bResult;
}

// used to check if ports are compatible between different versions
bool CConvCurveObsInit::AreVersionsCompatible(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo& providePortVersionInfo)
{
  bool bResult = false;
  // Equal ports are always compatible (at least assumed to be)
  if ((ulRPortSize == ulPPortSize) && (eRPortType == ePPortType))
  {
    bResult = true;
  }
  else if ((ulRPortSize == sizeof(m_InitData)) && (eRPortType == simOPAQUE_t))
  {
    if ((IsPortSupported(ulPPortSize)) & (ePPortType == simOPAQUE_t))
    {
      bResult = true;
    }
  }
  return bResult;
}

extern IConverter * CreateSICuveObsInitConvInstance(void)
{
  return new CConvCurveObsInit();
}
