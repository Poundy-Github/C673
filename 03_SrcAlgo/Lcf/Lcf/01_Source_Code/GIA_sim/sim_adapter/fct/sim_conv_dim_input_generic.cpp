/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter_fct

  MODULNAME:            sim_conv_dim_input_generic.cpp

  DESCRIPTION:          

  AUTHOR:               Ovidiu Raicu

  CREATION DATE:        08.06.2010

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: sim_conv_dim_input_generic.cpp  $
  CHANGES:              Revision 1.1 2021/12/13 17:20:57CET Wang, David (Wangd3) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_adapter/fct/project.pj
  CHANGES:              Revision 1.1 2017/08/10 13:15:13CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/fct/project.pj
  CHANGES:              Revision 1.14 2016/11/15 16:34:00CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              + Version 5
  CHANGES:              Revision 1.13 2015/05/29 13:49:39CEST Diepolder, Thomas (diepoldert) 
  CHANGES:              Updated adapter to enable x-simulation D1/B0 D2/T0
  CHANGES:              --- Added comments ---  diepoldert [May 29, 2015 1:49:39 PM CEST]
  CHANGES:              Change Package : 343338:1 http://mks-psad:7002/im/viewissue?selection=343338
  CHANGES:              Revision 1.12 2014/01/24 15:35:53CET Obst, Christian02 (uidv8774) 
  CHANGES:              updated Adapter TypeNaming and
  CHANGES:              using "big Adapter" version of HeadInputCustom
  CHANGES:              --- Added comments ---  uidv8774 [Jan 24, 2014 3:35:53 PM CET]
  CHANGES:              Change Package : 215077:1 http://mks-psad:7002/im/viewissue?selection=215077
  CHANGES:              Revision 1.11 2013/09/19 17:41:24CEST Obst, Christian02 (uidv8774) 
  CHANGES:              modification towards generic adapter concept
  CHANGES:              --- Added comments ---  uidv8774 [Sep 19, 2013 5:41:25 PM CEST]
  CHANGES:              Change Package : 194538:4 http://mks-psad:7002/im/viewissue?selection=194538
  CHANGES:              Revision 1.10 2013/05/21 18:04:25CEST Ungvary, Gergely (ungvaryg) 
  CHANGES:              Modify for ARS4xx 'big' adapter: remove class declarations and complex includes from individual headers (only leaving factory
  CHANGES:              function external declaration there), moving class declaration and all additional includes into cpp file. Add single factory function
  CHANGES:              per data conversion stream.
  CHANGES:              Note: otherwise no functional changes made, thus the new revisions perform the exact same conversions (ARS3xx) as previously
  CHANGES:              --- Added comments ---  ungvaryg [May 21, 2013 6:04:25 PM CEST]
  CHANGES:              Change Package : 172401:1 http://mks-psad:7002/im/viewissue?selection=172401
  CHANGES:              Revision 1.9 2011/10/17 18:27:25CEST Diepolder, Thomas (diepoldert) 
  CHANGES:              Update simulation adapters to handle new rte interfaces
  CHANGES:              --- Added comments ---  diepoldert [Oct 17, 2011 6:27:25 PM CEST]
  CHANGES:              Change Package : 84108:1 http://mks-psad:7002/im/viewissue?selection=84108
  CHANGES:              Revision 1.8 2011/09/29 14:26:04CEST Diepolder Thomas (diepoldert) (diepoldert) 
  CHANGES:              Fix: Interpret recorded port with version number 0 as version 1, pass right return code in case of equality of requested and provided port
  CHANGES:              --- Added comments ---  diepoldert [Sep 29, 2011 2:26:04 PM CEST]
  CHANGES:              Change Package : 80006:1 http://mks-psad:7002/im/viewissue?selection=80006
  CHANGES:              Revision 1.7 2011/09/14 12:45:20CEST Ungvary Gergely (ungvaryg) (ungvaryg) 
  CHANGES:              Fix misleading names of versioning namespaces (version2 was actually version1)
  CHANGES:              Add support for real version 2
  CHANGES:              --- Added comments ---  ungvaryg [Sep 14, 2011 12:45:21 PM CEST]
  CHANGES:              Change Package : 74571:3 http://mks-psad:7002/im/viewissue?selection=74571
  CHANGES:              Revision 1.6 2011/04/13 19:11:43CEST Ungvary Gergely (ungvaryg) (ungvaryg) 
  CHANGES:              Remove direct include of algo_type.h
  CHANGES:              --- Added comments ---  ungvaryg [Apr 13, 2011 7:11:44 PM CEST]
  CHANGES:              Change Package : 63692:1 http://mks-psad:7002/im/viewissue?selection=63692
  CHANGES:              Revision 1.5 2011/03/02 16:42:34CET Thomas Diepolder (diepoldert) 
  CHANGES:              Repaired compatiblilty for old recordings (ARS301, containing 28 byte block size), currently ARS300 (same size = 28) recordings are not supported
  CHANGES:              --- Added comments ---  diepoldert [Mar 2, 2011 4:42:35 PM CET]
  CHANGES:              Change Package : 59660:2 http://mks-psad:7002/im/viewissue?selection=59660
  CHANGES:              Revision 1.4 2011/02/04 14:53:35CET Thomas Diepolder (diepoldert) 
  CHANGES:              Allow connection of DIMInputGeneric port
  CHANGES:              --- Added comments ---  diepoldert [Feb 4, 2011 2:53:35 PM CET]
  CHANGES:              Change Package : 58833:1 http://mks-psad:7002/im/viewissue?selection=58833
  CHANGES:              Revision 1.3 2010/12/06 14:03:57CET Robert Thiel (thielr) 
  CHANGES:              since the current RTE type length of DIMInputDataGeneric is 28byte == the same as the old KCM input data type, it cannot be told which is which...
  CHANGES:              Thats why the preferred version is the new RTE version - so old KCM measurements with 28 byte driver data length cannot be used anymore
  CHANGES:              --- Added comments ---  thielr [Dec 6, 2010 2:03:57 PM CET]
  CHANGES:              Change Package : 56094:1 http://mks-psad:7002/im/viewissue?selection=56094
  CHANGES:              Revision 1.2 2010/06/16 16:47:36CEST rthiel 
  CHANGES:              added 24 byte long struct type for driver inputs
  CHANGES:              --- Added comments ---  rthiel [2010/06/16 14:47:36Z]
  CHANGES:              Change Package : 19018:5 http://LISS014:6001/im/viewissue?selection=19018
  CHANGES:              Revision 1.1 2010/06/09 08:13:49CEST Ovidiu Raicu (oraicu) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FCT_Function/04_Engineering/03_Workspace/algo/fct_sim/fct_adapt/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */
#include "stdafx.h"
#include "sim_conv_dim_input_generic.h"
#include "interfacedriverinput.h"
#include "sim_versioninfo_impl.h"
#include "interfacedriverinput.h"

class CConvDimInputGeneric :
  public CSimConverterBase
//  public CDimInputGeneric
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

  DimInputV1::DIMInputGeneric_t  m_DimInputGenericV1;
  DimInputV2::DIMInputGeneric_t  m_DimInputGenericV2;
  DimInputV3::DIMInputGeneric_t  m_DimInputGenericV3;
  DimInputV4::DIMInputGeneric_t  m_DimInputGenericV4;
  DimInputV5::DIMInputGeneric_t  m_DimInputGenericV5;

  void InitGenericInputV1(DimInputV1::DIMInputGeneric_t &DestDim);
  void InitGenericInputV2(DimInputV2::DIMInputGeneric_t &DestDim);
  void InitGenericInputV3(DimInputV3::DIMInputGeneric_t &DestDim);
  void InitGenericInputV4(DimInputV4::DIMInputGeneric_t &DestDim);
  void InitGenericInputV5(DimInputV5::DIMInputGeneric_t &DestDim);

  void ConvertToV1(const DimInputNoVer2::DIMInputGeneric_t &SrcDim, DimInputV1::DIMInputGeneric_t & DestDim);
  void ConvertToV1(const DimInputNoVer3::DIMInputGeneric_t &Srcdim, DimInputV1::DIMInputGeneric_t & DestDim);
  void ConvertToV1(const DimInputV2::DIMInputGeneric_t &SrcDim, DimInputV1::DIMInputGeneric_t & DestDim);

  void ConvertToV2(const DimInputNoVer2::DIMInputGeneric_t &SrcDim, DimInputV2::DIMInputGeneric_t & DestDim);
  void ConvertToV2(const DimInputNoVer3::DIMInputGeneric_t &Srcdim, DimInputV2::DIMInputGeneric_t & DestDim);
  void ConvertToV2(const DimInputV1::DIMInputGeneric_t &SrcDim, DimInputV2::DIMInputGeneric_t & DestDim);
  void ConvertToV2(const DimInputV3::DIMInputGeneric_t &SrcDim, DimInputV2::DIMInputGeneric_t & DestDim);
  
  void ConvertToV3(const DimInputNoVer2::DIMInputGeneric_t &SrcDim, DimInputV3::DIMInputGeneric_t &DestDim);
  void ConvertToV3(const DimInputNoVer3::DIMInputGeneric_t &Srcdim, DimInputV3::DIMInputGeneric_t &DestDim);
  void ConvertToV3(const DimInputV1::DIMInputGeneric_t &SrcDim, DimInputV3::DIMInputGeneric_t &DestDim);
  void ConvertToV3(const DimInputV2::DIMInputGeneric_t &SrcDim, DimInputV3::DIMInputGeneric_t &DestDim);
  void ConvertToV3(const DimInputV4::DIMInputGeneric_t &SrcDim, DimInputV3::DIMInputGeneric_t &DestDim);

  void ConvertToV4(const DimInputV3::DIMInputGeneric_t &SrcDim, DimInputV4::DIMInputGeneric_t &DestDim);
  void ConvertToV4(const DimInputV5::DIMInputGeneric_t &SrcDim, DimInputV4::DIMInputGeneric_t &DestDim);

  void ConvertToV5(const DimInputV4::DIMInputGeneric_t &SrcDim, DimInputV5::DIMInputGeneric_t &DestDim);
public:

  static const char* GetConverterTypeName()
  {
    return "DIMInputGeneric_t";
  }

  CConvDimInputGeneric(void);
  virtual ~CConvDimInputGeneric(void);

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

  bool IsPortSupported(unsigned long ulPortSize, const IVersionInfo *pPortVersion) const
  {
    for (int nI = 0; nI < DRIVER_INPUT_VERSION_COUNT; nI++)
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

  static CVersionInfoImpl BASE_VERSION;
  static CVersionInfoImpl DIM_INPUT_VERSION_V0;
  static CVersionInfoImpl DIM_INPUT_VERSION_V1;
  static CVersionInfoImpl DIM_INPUT_VERSION_V2;
  static CVersionInfoImpl DIM_INPUT_VERSION_V3;
  static CVersionInfoImpl DIM_INPUT_VERSION_V4;
  static CVersionInfoImpl DIM_INPUT_VERSION_V5;

  enum eDriverInputVersions
  {
    DRIVER_INPUT_STRUCT_NOVER1,   /* ARS300 MeasDrvInp_t */
    DRIVER_INPUT_STRUCT_NOVER3,   /*!< ARS301 first version, but no version number */
    DRIVER_INPUT_STRUCT_V1,       /*!< ARS301 second version, but with version number = 0x1 */
    DRIVER_INPUT_STRUCT_V2,       /*!< ARS301 version 0x2 */
    DRIVER_INPUT_STRUCT_V3,       /*!< ARS301 version 0x2 */
    DRIVER_INPUT_STRUCT_V4,       /*!< MFC4xx, ARS430BW18 */
    DRIVER_INPUT_STRUCT_V5,       /*!< ARS430BW18 */
    DRIVER_INPUT_VERSION_COUNT
  };
  static unsigned long SUPPORTED_SIZE[DRIVER_INPUT_VERSION_COUNT];

  static const CVersionInfoImpl * const VERSION_NUMBERS[DRIVER_INPUT_VERSION_COUNT];
};

CVersionInfoImpl CConvDimInputGeneric::BASE_VERSION(0, 0, 0);
CVersionInfoImpl CConvDimInputGeneric::DIM_INPUT_VERSION_V0(0, 0, 0);
CVersionInfoImpl CConvDimInputGeneric::DIM_INPUT_VERSION_V1(0, 0, 1);
CVersionInfoImpl CConvDimInputGeneric::DIM_INPUT_VERSION_V2(0, 0, 2);
CVersionInfoImpl CConvDimInputGeneric::DIM_INPUT_VERSION_V3(0, 0, 3);
CVersionInfoImpl CConvDimInputGeneric::DIM_INPUT_VERSION_V4(0, 0, 4);
CVersionInfoImpl CConvDimInputGeneric::DIM_INPUT_VERSION_V5(0, 0, 5);


unsigned long CConvDimInputGeneric::SUPPORTED_SIZE[CConvDimInputGeneric::DRIVER_INPUT_VERSION_COUNT]= { 
  sizeof(DimInputNoVer1::DIMInputGeneric_t),
  sizeof(DimInputNoVer3::DIMInputGeneric_t),
  sizeof(DimInputV1::DIMInputGeneric_t),
  sizeof(DimInputV2::DIMInputGeneric_t),
  sizeof(DimInputV3::DIMInputGeneric_t),
  sizeof(DimInputV4::DIMInputGeneric_t),
  sizeof(DimInputV5::DIMInputGeneric_t)
};

const CVersionInfoImpl * const CConvDimInputGeneric::VERSION_NUMBERS[CConvDimInputGeneric::DRIVER_INPUT_VERSION_COUNT] =
{
  NULL,
  NULL,
  &DIM_INPUT_VERSION_V1,
  &DIM_INPUT_VERSION_V2,
  &DIM_INPUT_VERSION_V3,
  &DIM_INPUT_VERSION_V4,
  &DIM_INPUT_VERSION_V5
};

CConvDimInputGeneric::CConvDimInputGeneric(void)
: CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT), m_DimInputGenericV1(), m_DimInputGenericV2(), m_DimInputGenericV3(), m_DimInputGenericV4()
{
  InitGenericInputV1(m_DimInputGenericV1);
  InitGenericInputV2(m_DimInputGenericV2);
  InitGenericInputV3(m_DimInputGenericV3);
  InitGenericInputV4(m_DimInputGenericV4);
  InitGenericInputV5(m_DimInputGenericV5);
}

CConvDimInputGeneric::~CConvDimInputGeneric(void)
{
}

long CConvDimInputGeneric::ConvertData(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo, 
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo *pProvidePortVersionInfo, 
    void *pPPortData,
    void **pOutData, unsigned long &ulOutSize)
{
  long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;

  if (eRPortType == ePPortType)
  {
    const unsigned int * const pUintPportData = reinterpret_cast<unsigned int*>(pPPortData);
    const unsigned __int32 unRawDataVersion = *reinterpret_cast<const unsigned __int32 *>(pPPortData);
    CVersionInfoImpl RawVersion((unRawDataVersion >> 16) & 0xFF, (unRawDataVersion >> 8) & 0xFF, (unRawDataVersion & 0xFF));

    // For Cross-Conversion and setting of DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK; the following is deactivated
    //if ((ulRPortSize == ulPPortSize) && (((pProvidePortVersionInfo == NULL) && (requestPortVersionInfo.Equals(&RawVersion))) || (requestPortVersionInfo.Equals(pProvidePortVersionInfo))))
    //{
    //  // Ports are equal, use provide port directly
    //  *pOutData = pPPortData;
    //  ulOutSize = ulPPortSize;
    //  lRet = SIM_ERR_OK;
    //}
    //else
    {
      if ( (ulRPortSize == sizeof(DimInputV5::DIMInputGeneric_t)) && ((requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V5) || (requestPortVersionInfo.Equals(&BASE_VERSION)))))
      {
        /* Request port V5 */
        DimInputV5::DIMInputGeneric_t &DestDim = m_DimInputGenericV5;
        if ((ulPPortSize == ulRPortSize) && (unRawDataVersion == 5))
        {
          /* Provide port V5 */
          /* Only necessary if DestDim.sSigHeader.eSigStatus is not equal AL_SIG_STATE_OK */
          const DimInputV5::DIMInputGeneric_t &SrcDim = *reinterpret_cast<DimInputV5::DIMInputGeneric_t *>(pPPortData);
          DestDim = SrcDim;
          DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
          *pOutData = &DestDim;
          ulOutSize = sizeof(DestDim);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(DimInputV4::DIMInputGeneric_t)) && (unRawDataVersion == 4))
        {
          /* Provide port V4 */
          const DimInputV4::DIMInputGeneric_t &SrcDim = *reinterpret_cast<DimInputV4::DIMInputGeneric_t *>(pPPortData);
          ConvertToV5(SrcDim, DestDim);
          DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
          *pOutData = &DestDim;
          ulOutSize = sizeof(DestDim);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(DimInputV3::DIMInputGeneric_t)) && (unRawDataVersion == 3))
        {
          /* Provide port V3 */
          const DimInputV3::DIMInputGeneric_t &SrcDim = *reinterpret_cast<DimInputV3::DIMInputGeneric_t *>(pPPortData);
          ConvertToV4(SrcDim, m_DimInputGenericV4);
          ConvertToV5(m_DimInputGenericV4, DestDim);
          *pOutData = &DestDim;
          ulOutSize = sizeof(DestDim);
          lRet = SIM_ERR_OK;
        }
      }
      else if ( (ulRPortSize == sizeof(DimInputV4::DIMInputGeneric_t)) && ((requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V4) || (requestPortVersionInfo.Equals(&BASE_VERSION)))))
      {
        /* Request port V4 */
        DimInputV4::DIMInputGeneric_t &DestDim = m_DimInputGenericV4;
        if ((ulPPortSize == sizeof(DimInputV4::DIMInputGeneric_t)) && (unRawDataVersion == 4))
        {
          /* Provide port V4 */
          // lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
          /* Only necessary if DestDim.sSigHeader.eSigStatus is not equal AL_SIG_STATE_OK */
          const DimInputV4::DIMInputGeneric_t &SrcDim = *reinterpret_cast<DimInputV4::DIMInputGeneric_t *>(pPPortData);
          DestDim = SrcDim;
          DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
          *pOutData = &DestDim;
          ulOutSize = sizeof(DestDim);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(DimInputV5::DIMInputGeneric_t)) && (unRawDataVersion == 5))
        {
          /* Provide port V5 */
          const DimInputV5::DIMInputGeneric_t &SrcDim = *reinterpret_cast<DimInputV5::DIMInputGeneric_t *>(pPPortData);
          ConvertToV4(SrcDim, DestDim);
          *pOutData = &DestDim;
          ulOutSize = sizeof(DestDim);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(DimInputV3::DIMInputGeneric_t)) && (unRawDataVersion == 3))
        {
          /* Provide port V3 */
          const DimInputV3::DIMInputGeneric_t &SrcDim = *reinterpret_cast<DimInputV3::DIMInputGeneric_t *>(pPPortData);
          ConvertToV4(SrcDim, DestDim);
          *pOutData = &DestDim;
          ulOutSize = sizeof(DestDim);
          lRet = SIM_ERR_OK;
        }
      }
      else if ( (ulRPortSize == sizeof(DimInputV3::DIMInputGeneric_t)) && ((requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V3) || (requestPortVersionInfo.Equals(&BASE_VERSION)))))
      {
        // Request port is version 3
        DimInputV3::DIMInputGeneric_t &DestDim = m_DimInputGenericV3;
        if ((ulPPortSize == sizeof(DimInputV3::DIMInputGeneric_t)) && (unRawDataVersion == 3))
        {
          // Provide port also seems to be version 3
          lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
        }
        else if ((ulPPortSize == sizeof(DimInputV4::DIMInputGeneric_t)) && ((unRawDataVersion == 4) || (DIM_INPUT_VERSION_V4.Equals(pProvidePortVersionInfo))))
        {
          // Provide port is version 4
          const DimInputV4::DIMInputGeneric_t &SrcDim = *reinterpret_cast<DimInputV4::DIMInputGeneric_t *>(pPPortData);
          ConvertToV3(SrcDim, DestDim);
          *pOutData = &DestDim;
          ulOutSize = sizeof(DestDim);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(DimInputV2::DIMInputGeneric_t)) && ((unRawDataVersion == 2) || (DIM_INPUT_VERSION_V2.Equals(pProvidePortVersionInfo))))
        {
          // Provide port is version 2
          const DimInputV2::DIMInputGeneric_t &SrcDim = *reinterpret_cast<DimInputV2::DIMInputGeneric_t *>(pPPortData);
          ConvertToV3(SrcDim, DestDim);
          *pOutData = &DestDim;
          ulOutSize = sizeof(DestDim);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(DimInputV1::DIMInputGeneric_t)) && ((unRawDataVersion == 0) || (unRawDataVersion == 1) || (DIM_INPUT_VERSION_V2.Equals(pProvidePortVersionInfo))))
        {
          // Provide port is version 1
          const DimInputV1::DIMInputGeneric_t &SrcDim = *reinterpret_cast<DimInputV1::DIMInputGeneric_t *>(pPPortData);
          ConvertToV3(SrcDim, DestDim);
          *pOutData = &DestDim;
          ulOutSize = sizeof(DestDim);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(DimInputNoVer3::DIMInputGeneric_t)) && (unRawDataVersion < 0x301) && (pUintPportData[3] <= 0x5))
        {
          // Provide port is NoVer3 (note: the 0x301 constant derives from the fact that NoVer3 contains two enums followed by
          // two bytes padding. These two enums have 0x3 and 0x1 as maximums respectively, the padding has to be zero.
          // The second 0x5 constant stems from the fact that NoVer3 contains at offset 12 an enumerator with max=5 followed by
          // padding
          const DimInputNoVer3::DIMInputGeneric_t &SrcDim = *reinterpret_cast<DimInputNoVer3::DIMInputGeneric_t *>(pPPortData);
          ConvertToV3(SrcDim, DestDim);
          *pOutData = &DestDim;
          ulOutSize = sizeof(DestDim);
          lRet = SIM_ERR_OK;
        }
        else if (ulPPortSize == sizeof(DimInputNoVer2::DIMInputGeneric_t))
        {
          // Provide port is NoVer2
          const DimInputNoVer2::DIMInputGeneric_t &SrcDim = *reinterpret_cast<DimInputNoVer2::DIMInputGeneric_t *>(pPPortData);
          ConvertToV3(SrcDim, DestDim);
          *pOutData = &DestDim;
          ulOutSize = sizeof(DestDim);
          lRet = SIM_ERR_OK;
        }
        else if (ulPPortSize == sizeof(DimInputNoVer1::DIMInputGeneric_t))
        {
          // Provide port is NoVer1 (old ARS300 data)
          lRet = SIM_ERR_NO_CONVERTER_FOR_PORT; // No longer supported (was commented out in Thomas Diepolder's version too)
        }
      }
      else if ((ulRPortSize == sizeof(DimInputV2::DIMInputGeneric_t)) && ((requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V2)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        // Request port is version 2
        DimInputV2::DIMInputGeneric_t &DestDim = m_DimInputGenericV2;
        if ((ulPPortSize == sizeof(DimInputV2::DIMInputGeneric_t)) && (unRawDataVersion == 2))
        {
          // Provide port also seems to be version 2
          lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
        }
        else if ((ulPPortSize == sizeof(DimInputV3::DIMInputGeneric_t)) && ((unRawDataVersion == 3) || (DIM_INPUT_VERSION_V3.Equals(pProvidePortVersionInfo))))
        {
          // Provide port is version 3
          const DimInputV3::DIMInputGeneric_t &SrcDim = *reinterpret_cast<DimInputV3::DIMInputGeneric_t *>(pPPortData);
          ConvertToV2(SrcDim, DestDim);
          *pOutData = &DestDim;
          ulOutSize = sizeof(DestDim);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(DimInputV1::DIMInputGeneric_t)) && ((unRawDataVersion == 0) || (unRawDataVersion == 1) || (DIM_INPUT_VERSION_V1.Equals(pProvidePortVersionInfo))))
        {
          // Provide port is version 1
          const DimInputV1::DIMInputGeneric_t &SrcDim = *reinterpret_cast<DimInputV1::DIMInputGeneric_t *>(pPPortData);
          ConvertToV2(SrcDim, DestDim);
          *pOutData = &DestDim;
          ulOutSize = sizeof(DestDim);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(DimInputNoVer3::DIMInputGeneric_t)) && (unRawDataVersion < 0x301) && (pUintPportData[3] <= 0x5))
        {
          // Provide port is NoVer3 (note: the 0x301 constant derives from the fact that NoVer3 contains two enums followed by
          // two bytes padding. These two enums have 0x3 and 0x1 as maximums respectively, the padding has to be zero.
          // The second 0x5 constant stems from the fact that NoVer3 contains at offset 12 an enumerator with max=5 followed by
          // padding
          const DimInputNoVer3::DIMInputGeneric_t &SrcDim = *reinterpret_cast<DimInputNoVer3::DIMInputGeneric_t *>(pPPortData);
          ConvertToV2(SrcDim, DestDim);
          *pOutData = &DestDim;
          ulOutSize = sizeof(DestDim);
          lRet = SIM_ERR_OK;
        }
        else if (ulPPortSize == sizeof(DimInputNoVer2::DIMInputGeneric_t))
        {
          // Provide port is NoVer2
          const DimInputNoVer2::DIMInputGeneric_t &SrcDim = *reinterpret_cast<DimInputNoVer2::DIMInputGeneric_t *>(pPPortData);
          ConvertToV2(SrcDim, DestDim);
          *pOutData = &DestDim;
          ulOutSize = sizeof(DestDim);
          lRet = SIM_ERR_OK;
        }
        else if (ulPPortSize == sizeof(DimInputNoVer1::DIMInputGeneric_t))
        {
          // Provide port is NoVer1 (old ARS300 data)
          lRet = SIM_ERR_NO_CONVERTER_FOR_PORT; // No longer supported (was commented out in Thomas Diepolder's version too)
        }
      }
      else if ((ulRPortSize == sizeof(DimInputV1::DIMInputGeneric_t)) && ((requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V1)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        // Request port is version 1
        DimInputV1::DIMInputGeneric_t &DestDim = m_DimInputGenericV1;
        if ((ulPPortSize == sizeof(DimInputV2::DIMInputGeneric_t)) && ((unRawDataVersion == 2) || (DIM_INPUT_VERSION_V2.Equals(pProvidePortVersionInfo))))
        {
          // Provide port seems to be version 2
          const DimInputV2::DIMInputGeneric_t &SrcDim = *reinterpret_cast<DimInputV2::DIMInputGeneric_t *>(pPPortData);
          ConvertToV1(SrcDim, DestDim);
          *pOutData = &DestDim;
          ulOutSize = sizeof(DestDim);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(DimInputV1::DIMInputGeneric_t)) && ((unRawDataVersion == 0) || (unRawDataVersion == 1) || (DIM_INPUT_VERSION_V1.Equals(pProvidePortVersionInfo))))
        {
          // Provide port is version 1
          lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
        }
        else if ((ulPPortSize == sizeof(DimInputNoVer3::DIMInputGeneric_t)) && (unRawDataVersion < 0x301) && (pUintPportData[3] <= 0x5))
        {
          // Provide port is NoVer3 (note: the 0x301 constant derives from the fact that NoVer3 contains two enums followed by
          // two bytes padding. These two enums have 0x3 and 0x1 as maximums respectively, the padding has to be zero.
          // The second 0x5 constant stems from the fact that NoVer3 contains at offset 12 an enumerator with max=5 followed by
          // padding
          const DimInputNoVer3::DIMInputGeneric_t &SrcDim = *reinterpret_cast<DimInputNoVer3::DIMInputGeneric_t *>(pPPortData);
          ConvertToV1(SrcDim, DestDim);
          *pOutData = &DestDim;
          ulOutSize = sizeof(DestDim);
          lRet = SIM_ERR_OK;
        }
        else if (ulPPortSize == sizeof(DimInputNoVer2::DIMInputGeneric_t))
        {
          // Provide port is NoVer2
          const DimInputNoVer2::DIMInputGeneric_t &SrcDim = *reinterpret_cast<DimInputNoVer2::DIMInputGeneric_t *>(pPPortData);
          ConvertToV1(SrcDim, DestDim);
          *pOutData = &DestDim;
          ulOutSize = sizeof(DestDim);
          lRet = SIM_ERR_OK;
        }
        else if (ulPPortSize == sizeof(DimInputNoVer1::DIMInputGeneric_t))
        {
          // Provide port is NoVer1 (old ARS300 data)
          lRet = SIM_ERR_NO_CONVERTER_FOR_PORT; // No longer supported (was commented out in Thomas Diepolder's version too)
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
long CConvDimInputGeneric::GetDefaultValue(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo, 
    void **pDefaultData, unsigned long &ulDefaultSize)
{
  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == sizeof(DimInputV5::DIMInputGeneric_t))
      && ((requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V5)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      /* DIM Input Generic V5 */
      DimInputV5::DIMInputGeneric_t &DestDim = m_DimInputGenericV5;
      InitGenericInputV5(DestDim);

      *pDefaultData = &DestDim;
      ulDefaultSize = sizeof(DestDim);

      return SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(DimInputV4::DIMInputGeneric_t))
      && ((requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V4)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      /* DIM Input Generic V4 */
      DimInputV4::DIMInputGeneric_t &DestDim = m_DimInputGenericV4;
      InitGenericInputV4(DestDim);

      *pDefaultData = &DestDim;
      ulDefaultSize = sizeof(DestDim);

      return SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(DimInputV3::DIMInputGeneric_t))
      && ((requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V3)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      /* DIM Input Generic V3 */
      DimInputV3::DIMInputGeneric_t &DestDim = m_DimInputGenericV3;
      InitGenericInputV3(DestDim);

      *pDefaultData = &DestDim;
      ulDefaultSize = sizeof(DestDim);

      return SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(DimInputV2::DIMInputGeneric_t))
      && ((requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V2)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      /* DIM Input Generic V2 */
      DimInputV2::DIMInputGeneric_t &DestDim = m_DimInputGenericV2;
      InitGenericInputV2(DestDim);

      *pDefaultData = &DestDim;
      ulDefaultSize = sizeof(DestDim);

      return SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(DimInputV1::DIMInputGeneric_t))
      && ((requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V1)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      /* DIM Input Generic V1 */
      DimInputV1::DIMInputGeneric_t &DestDim = m_DimInputGenericV1;
      InitGenericInputV1(DestDim);

      *pDefaultData = &DestDim;
      ulDefaultSize = sizeof(DestDim);

      return SIM_ERR_OK;
    }
  }
  return SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
}

// used to check if an unversioned PPort is compatible with a certain version of RPort
bool CConvDimInputGeneric::IsVersionCompatibleWithType(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo, 
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize)
{
  bool bResult = false;

  if (eRPortType == ePPortType)
  {
    if (ulRPortSize == ulPPortSize)
    {
      bResult = true;
    }
    else
    {
      if ((ulRPortSize == sizeof(DimInputV5::DIMInputGeneric_t)) && (requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V5)))
      {
        /* Request Port is V5 */
        if (ulPPortSize == sizeof(DimInputV4::DIMInputGeneric_t))
        {
          // Conversion V4 -> V5
          bResult = true;
        }
        else if (ulPPortSize == sizeof(DimInputV3::DIMInputGeneric_t))
        {
          // Conversion V3 -> V5
          bResult = true;
        }
        else
        {
          bResult = false;
        }
      }
      else if ((ulRPortSize == sizeof(DimInputV4::DIMInputGeneric_t)) && (requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V4)))
      {
        /* Request Port is V4 */
        if (ulPPortSize == sizeof(DimInputV5::DIMInputGeneric_t))
        {
          // Conversion V5 -> V4
          bResult = true;
        }
        if (ulPPortSize == sizeof(DimInputV3::DIMInputGeneric_t))
        {
          // Conversion V3 -> V4
          bResult = true;
        }
        else
        {
          bResult = false;
        }
      }
      else if ((ulRPortSize == sizeof(DimInputV3::DIMInputGeneric_t)) && (requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V3)))
      {
        // Request port version == 3
        if ( (ulPPortSize == sizeof(DimInputV4::DIMInputGeneric_t))
          || (ulPPortSize == sizeof(DimInputV2::DIMInputGeneric_t))
          || (ulPPortSize == sizeof(DimInputV1::DIMInputGeneric_t))
          || (ulPPortSize == sizeof(DimInputNoVer3::DIMInputGeneric_t)) )
        {
          // Conversion OK
          bResult = true;
        }
        else
        {
          bResult = false;
        }
      }
      else if ((ulRPortSize == sizeof(DimInputV2::DIMInputGeneric_t)) && (requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V2)))
      {
        // Request port version == 2
        if (ulPPortSize == sizeof(DimInputV1::DIMInputGeneric_t))
        {
          // Conversion V1 -> V2
          bResult = true;
        }
        else if (ulPPortSize == sizeof(DimInputV3::DIMInputGeneric_t))
        {
          // Conversion no version -> V2
          bResult = true;
        }
        else if (ulPPortSize == sizeof(DimInputNoVer3::DIMInputGeneric_t))
        {
          // Conversion no version -> V2
          bResult = true;
        }
      }
      else if ((ulRPortSize == sizeof(DimInputV1::DIMInputGeneric_t)) && (requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V1)))
      {
        // Request port version == 1
        if (ulPPortSize == sizeof(DimInputV2::DIMInputGeneric_t))
        {
          // Conversion V2 -> V1
          bResult = true;
        }
        else if (ulPPortSize == sizeof(DimInputNoVer3::DIMInputGeneric_t))
        {
          // Conversion no version -> V1
          bResult = true;
        }
      }
      else if ((ulRPortSize == sizeof(DimInputNoVer3::DIMInputGeneric_t)) && (requestPortVersionInfo.Equals(&BASE_VERSION)))
      {
        // Request port unversioned ARS301 variant (NoVer3)
        if (ulPPortSize == sizeof(DimInputV1::DIMInputGeneric_t))
        {
          bResult = true;
        }
      }
      else
      {
        bResult = false;
      }
    }
  }
  return bResult;
}

// used to check if ports are compatible between different versions
bool CConvDimInputGeneric::AreVersionsCompatible(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo &providePortVersionInfo)
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


void CConvDimInputGeneric::ConvertToV1(const DimInputNoVer2::DIMInputGeneric_t &SrcDim, DimInputV1::DIMInputGeneric_t &DestDim)
{
  // Init members, which do not exists in source version
  DestDim.uiVersionNumber = 1ul;
  DestDim.bACCActive = 0;
  DestDim.eDriverSetting = eDriverSetting_Early;
  DestDim.eAccelPadelStat = DIMInputSignalState_OK;
  DestDim.eSteeringWheelAngleStat = DIMInputSignalState_OK;

  // Copy existing source members to destination 
  DestDim.fSteeringWheelAngle     = SrcDim.SteerWheelAngle;
  DestDim.fSteeringWheelAngleGrad = SrcDim.SteerWheelGrad;
  DestDim.fAccelPedalPos          = SrcDim.AccelPedalPos;
  DestDim.fAccelPedalGrad         = SrcDim.AccelPedalGrad;

  // Convert existing source members to destination members
  if (SrcDim.DriverBraking != 0u) {
    DestDim.bDriverBraking = TRUE;
  }
  else {
    DestDim.bDriverBraking = FALSE;
  }

  if (SrcDim.TurnIndicatorActive != 0u) {
    DestDim.eTurnIndicator = eTurnIndicator_Left;
  }
  else {
    DestDim.eTurnIndicator = eTurnIndicator_Off;
  }
}

void CConvDimInputGeneric::ConvertToV1(const DimInputNoVer3::DIMInputGeneric_t &SrcDim, DimInputV1::DIMInputGeneric_t &DestDim)
{
  // Init members, which do not exists in source version
  DestDim.uiVersionNumber = 1ul;

  DestDim.bACCActive              = SrcDim.bACCActive;
  DestDim.eDriverSetting          = SrcDim.eDriverSetting;
  DestDim.fSteeringWheelAngle     = SrcDim.fSteeringWheelAngle;
  DestDim.fSteeringWheelAngleGrad = SrcDim.fSteeringWheelAngleGrad;
  DestDim.eSteeringWheelAngleStat = SrcDim.eSteeringWheelAngleStat;
  DestDim.fAccelPedalPos          = SrcDim.fAccelPedalPos;
  DestDim.fAccelPedalGrad         = SrcDim.fAccelPedalGrad;
  DestDim.eAccelPadelStat         = SrcDim.eAccelPadelStat;
  DestDim.eTurnIndicator          = SrcDim.eTurnIndicator;
  DestDim.bDriverBraking          = SrcDim.bDriverBraking;
}

void CConvDimInputGeneric::ConvertToV1(const DimInputV2::DIMInputGeneric_t &SrcDim, DimInputV1::DIMInputGeneric_t & DestDim)
{
  DestDim.uiVersionNumber         = 1u;
  DestDim.bACCActive              = SrcDim.bACCActive;
  DestDim.eDriverSetting          = SrcDim.eDriverSetting;
  DestDim.fSteeringWheelAngle     = SrcDim.fSteeringWheelAngle;
  DestDim.fSteeringWheelAngleGrad = SrcDim.fSteeringWheelAngleGrad;
  DestDim.eSteeringWheelAngleStat = SrcDim.eSteeringWheelAngleStat;
  DestDim.fAccelPedalPos          = SrcDim.fAccelPedalPos;
  DestDim.fAccelPedalGrad         = SrcDim.fAccelPedalGrad;
  DestDim.eAccelPadelStat         = SrcDim.eAccelPadelStat;
  DestDim.eTurnIndicator          = SrcDim.eTurnIndicator;
  DestDim.bDriverBraking          = (SrcDim.eDriverBraking == eDriverBraking_Active);
}

void CConvDimInputGeneric::ConvertToV2(const DimInputNoVer2::DIMInputGeneric_t &SrcDim, DimInputV2::DIMInputGeneric_t & DestDim)
{
  DestDim.uiVersionNumber             = 2;
  DestDim.bACCActive                  = 0;
  DestDim.eDriverSetting              = eDriverSetting_Early;
  DestDim.fSteeringWheelAngle         = SrcDim.SteerWheelAngle;
  DestDim.fSteeringWheelAngleGrad     = SrcDim.SteerWheelGrad;
  DestDim.eSteeringWheelAngleStat     = DIMInputSignalState_OK;
  DestDim.eSteeringWheelAngleGradStat = DIMInputSignalState_OK;
  DestDim.fAccelPedalPos              = SrcDim.AccelPedalPos;
  DestDim.fAccelPedalGrad             = SrcDim.AccelPedalGrad;
  DestDim.eAccelPadelStat             = DIMInputSignalState_OK;
  DestDim.eAccelPadelGradStat         = DIMInputSignalState_OK;
  DestDim.eTurnIndicator              = (SrcDim.TurnIndicatorActive != 0u)?(eTurnIndicator_Left):(eTurnIndicator_Off);
  DestDim.eDriverBraking              = (SrcDim.DriverBraking != 0u)?(eDriverBraking_Active):(eDriverBraking_Inactive);
}

void CConvDimInputGeneric::ConvertToV2(const DimInputNoVer3::DIMInputGeneric_t &SrcDim, DimInputV2::DIMInputGeneric_t & DestDim)
{
  DestDim.uiVersionNumber             = 2;
  DestDim.bACCActive                  = SrcDim.bACCActive;
  DestDim.eDriverSetting              = SrcDim.eDriverSetting;
  DestDim.fSteeringWheelAngle         = SrcDim.fSteeringWheelAngle;
  DestDim.fSteeringWheelAngleGrad     = SrcDim.fSteeringWheelAngleGrad;
  DestDim.eSteeringWheelAngleStat     = SrcDim.eSteeringWheelAngleStat;
  DestDim.eSteeringWheelAngleGradStat = SrcDim.eSteeringWheelAngleStat;
  DestDim.fAccelPedalPos              = SrcDim.fAccelPedalPos;
  DestDim.fAccelPedalGrad             = SrcDim.fAccelPedalGrad;
  DestDim.eAccelPadelStat             = SrcDim.eAccelPadelStat;
  DestDim.eAccelPadelGradStat         = SrcDim.eAccelPadelStat;
  DestDim.eTurnIndicator              = SrcDim.eTurnIndicator;
  DestDim.eDriverBraking              = (SrcDim.bDriverBraking)?(eDriverBraking_Active):(eDriverBraking_Inactive);
}

void CConvDimInputGeneric::ConvertToV2(const DimInputV1::DIMInputGeneric_t &SrcDim, DimInputV2::DIMInputGeneric_t & DestDim)
{
  DestDim.uiVersionNumber             = 2;
  DestDim.bACCActive                  = SrcDim.bACCActive;
  DestDim.eDriverSetting              = SrcDim.eDriverSetting;
  DestDim.fSteeringWheelAngle         = SrcDim.fSteeringWheelAngle;
  DestDim.fSteeringWheelAngleGrad     = SrcDim.fSteeringWheelAngleGrad;
  DestDim.eSteeringWheelAngleStat     = SrcDim.eSteeringWheelAngleStat;
  DestDim.eSteeringWheelAngleGradStat = SrcDim.eSteeringWheelAngleStat;
  DestDim.fAccelPedalPos              = SrcDim.fAccelPedalPos;
  DestDim.fAccelPedalGrad             = SrcDim.fAccelPedalGrad;
  DestDim.eAccelPadelStat             = SrcDim.eAccelPadelStat;
  DestDim.eAccelPadelGradStat         = SrcDim.eAccelPadelStat;
  DestDim.eTurnIndicator              = SrcDim.eTurnIndicator;
  DestDim.eDriverBraking              = (SrcDim.bDriverBraking)?(eDriverBraking_Active):(eDriverBraking_Inactive);
}

void CConvDimInputGeneric::ConvertToV2(const DimInputV3::DIMInputGeneric_t &SrcDim, DimInputV2::DIMInputGeneric_t &DestDim)
{
  DestDim.uiVersionNumber             = 2;
  DestDim.bACCActive                  = SrcDim.bACCActive;
  DestDim.eDriverSetting              = SrcDim.eDriverSetting;
  DestDim.fSteeringWheelAngle         = SrcDim.fSteeringWheelAngle;
  DestDim.fSteeringWheelAngleGrad     = SrcDim.fSteeringWheelAngleGrad;
  DestDim.eSteeringWheelAngleStat     = SrcDim.eSteeringWheelAngleStat;
  DestDim.eSteeringWheelAngleGradStat = SrcDim.eSteeringWheelAngleGradStat;
  DestDim.fAccelPedalPos              = SrcDim.fAccelPedalPos;
  DestDim.fAccelPedalGrad             = SrcDim.fAccelPedalGrad;
  DestDim.eAccelPadelStat             = SrcDim.eAccelPadelStat;
  DestDim.eAccelPadelGradStat         = SrcDim.eAccelPadelGradStat;
  DestDim.eTurnIndicator              = SrcDim.eTurnIndicator;

  switch (SrcDim.eDriverBraking)
  {
  case eFCT_STATE_SIG_ACTIVE:
    DestDim.eDriverBraking = eDriverBraking_Active;
    break;
  case eFCT_STATE_SIG_INACTIVE:
    DestDim.eDriverBraking = eDriverBraking_Inactive;
    break;
  case eFCT_STATE_SIG_INVALID:
  default:
    DestDim.eDriverBraking = eDriverBraking_Invalid;
    break;
  }
}


void CConvDimInputGeneric::ConvertToV3(const DimInputNoVer2::DIMInputGeneric_t &SrcDim, DimInputV3::DIMInputGeneric_t &DestDim)
{
  DestDim.uiVersionNumber             = 3;
  DestDim.bACCActive                  = 0;
  DestDim.eDriverSetting              = eDriverSetting_Early;
  DestDim.fSteeringWheelAngle         = SrcDim.SteerWheelAngle;
  DestDim.fSteeringWheelAngleGrad     = SrcDim.SteerWheelGrad;
  DestDim.eSteeringWheelAngleStat     = DIMInputSignalState_OK;
  DestDim.eSteeringWheelAngleGradStat = DIMInputSignalState_OK;
  DestDim.fAccelPedalPos              = SrcDim.AccelPedalPos;
  DestDim.fAccelPedalGrad             = SrcDim.AccelPedalGrad;
  DestDim.eAccelPadelStat             = DIMInputSignalState_OK;
  DestDim.eAccelPadelGradStat         = DIMInputSignalState_OK;
  DestDim.eTurnIndicator              = (SrcDim.TurnIndicatorActive != 0u)?(eTurnIndicator_Left):(eTurnIndicator_Off);
  DestDim.eDriverBraking              = (SrcDim.DriverBraking != 0u)? (eFCT_STATE_SIG_ACTIVE) : (eFCT_STATE_SIG_INACTIVE);
}

void CConvDimInputGeneric::ConvertToV3(const DimInputNoVer3::DIMInputGeneric_t &SrcDim, DimInputV3::DIMInputGeneric_t &DestDim)
{
  DestDim.uiVersionNumber             = 3;
  DestDim.bACCActive                  = SrcDim.bACCActive;
  DestDim.eDriverSetting              = SrcDim.eDriverSetting;
  DestDim.fSteeringWheelAngle         = SrcDim.fSteeringWheelAngle;
  DestDim.fSteeringWheelAngleGrad     = SrcDim.fSteeringWheelAngleGrad;
  DestDim.eSteeringWheelAngleStat     = SrcDim.eSteeringWheelAngleStat;
  DestDim.eSteeringWheelAngleGradStat = SrcDim.eSteeringWheelAngleStat;
  DestDim.fAccelPedalPos              = SrcDim.fAccelPedalPos;
  DestDim.fAccelPedalGrad             = SrcDim.fAccelPedalGrad;
  DestDim.eAccelPadelStat             = SrcDim.eAccelPadelStat;
  DestDim.eAccelPadelGradStat         = SrcDim.eAccelPadelStat;
  DestDim.eTurnIndicator              = SrcDim.eTurnIndicator;
  DestDim.eDriverBraking              = (SrcDim.bDriverBraking)?(eFCT_STATE_SIG_ACTIVE):(eFCT_STATE_SIG_INACTIVE);
}

void CConvDimInputGeneric::ConvertToV3(const DimInputV1::DIMInputGeneric_t &SrcDim, DimInputV3::DIMInputGeneric_t &DestDim)
{
  DestDim.uiVersionNumber             = 3;
  DestDim.bACCActive                  = SrcDim.bACCActive;
  DestDim.eDriverSetting              = SrcDim.eDriverSetting;
  DestDim.fSteeringWheelAngle         = SrcDim.fSteeringWheelAngle;
  DestDim.fSteeringWheelAngleGrad     = SrcDim.fSteeringWheelAngleGrad;
  DestDim.eSteeringWheelAngleStat     = SrcDim.eSteeringWheelAngleStat;
  DestDim.eSteeringWheelAngleGradStat = SrcDim.eSteeringWheelAngleStat;
  DestDim.fAccelPedalPos              = SrcDim.fAccelPedalPos;
  DestDim.fAccelPedalGrad             = SrcDim.fAccelPedalGrad;
  DestDim.eAccelPadelStat             = SrcDim.eAccelPadelStat;
  DestDim.eAccelPadelGradStat         = SrcDim.eAccelPadelStat;
  DestDim.eTurnIndicator              = SrcDim.eTurnIndicator;
  DestDim.eDriverBraking              = (SrcDim.bDriverBraking)?(eFCT_STATE_SIG_ACTIVE):(eFCT_STATE_SIG_INACTIVE);
}

void CConvDimInputGeneric::ConvertToV3(const DimInputV2::DIMInputGeneric_t &SrcDim, DimInputV3::DIMInputGeneric_t &DestDim)
{
  DestDim.uiVersionNumber             = 3;
  DestDim.bACCActive                  = SrcDim.bACCActive;
  DestDim.eDriverSetting              = SrcDim.eDriverSetting;
  DestDim.fSteeringWheelAngle         = SrcDim.fSteeringWheelAngle;
  DestDim.fSteeringWheelAngleGrad     = SrcDim.fSteeringWheelAngleGrad;
  DestDim.eSteeringWheelAngleStat     = SrcDim.eSteeringWheelAngleStat;
  DestDim.eSteeringWheelAngleGradStat = SrcDim.eSteeringWheelAngleGradStat;
  DestDim.fAccelPedalPos              = SrcDim.fAccelPedalPos;
  DestDim.fAccelPedalGrad             = SrcDim.fAccelPedalGrad;
  DestDim.eAccelPadelStat             = SrcDim.eAccelPadelStat;
  DestDim.eAccelPadelGradStat         = SrcDim.eAccelPadelGradStat;
  DestDim.eTurnIndicator              = SrcDim.eTurnIndicator;

  switch (SrcDim.eDriverBraking)
  {
  case eDriverBraking_Active:
    DestDim.eDriverBraking = eFCT_STATE_SIG_ACTIVE;
    break;
  case eDriverBraking_Inactive:
    DestDim.eDriverBraking = eFCT_STATE_SIG_INACTIVE;
    break;
  case eDriverBraking_Invalid:
  default:
    DestDim.eDriverBraking = eFCT_STATE_SIG_INVALID;
    break;
  }
}

void CConvDimInputGeneric::ConvertToV3(const DimInputV4::DIMInputGeneric_t &SrcDim, DimInputV3::DIMInputGeneric_t &DestDim)
{
  DestDim.uiVersionNumber             = 3;
  DestDim.bACCActive                  = SrcDim.bACCActive;
  DestDim.eDriverSetting              = SrcDim.eDriverSetting;
  DestDim.fSteeringWheelAngle         = SrcDim.fSteeringWheelAngle;
  DestDim.fSteeringWheelAngleGrad     = SrcDim.fSteeringWheelAngleGrad;
  DestDim.eSteeringWheelAngleStat     = SrcDim.eSteeringWheelAngleStat;
  DestDim.eSteeringWheelAngleGradStat = SrcDim.eSteeringWheelAngleGradStat;
  DestDim.fAccelPedalPos              = SrcDim.fAccelPedalPos;
  DestDim.fAccelPedalGrad             = SrcDim.fAccelPedalGrad;
  DestDim.eAccelPadelStat             = SrcDim.eAccelPadelStat;
  DestDim.eAccelPadelGradStat         = SrcDim.eAccelPadelGradStat;
  DestDim.eTurnIndicator              = SrcDim.eTurnIndicator;
  DestDim.eDriverBraking              = SrcDim.eDriverBraking;
}

void CConvDimInputGeneric::ConvertToV4(const DimInputV3::DIMInputGeneric_t &SrcDim, DimInputV4::DIMInputGeneric_t &DestDim)
{
  DestDim.uiVersionNumber             = 4;
  DestDim.bACCActive                  = SrcDim.bACCActive;
  DestDim.eDriverSetting              = SrcDim.eDriverSetting;
  DestDim.fSteeringWheelAngle         = SrcDim.fSteeringWheelAngle;
  DestDim.fSteeringWheelAngleGrad     = SrcDim.fSteeringWheelAngleGrad;
  DestDim.eSteeringWheelAngleStat     = SrcDim.eSteeringWheelAngleStat;
  DestDim.eSteeringWheelAngleGradStat = SrcDim.eSteeringWheelAngleGradStat;
  DestDim.fAccelPedalPos              = SrcDim.fAccelPedalPos;
  DestDim.fAccelPedalGrad             = SrcDim.fAccelPedalGrad;
  DestDim.eAccelPadelStat             = SrcDim.eAccelPadelStat;
  DestDim.eAccelPadelGradStat         = SrcDim.eAccelPadelGradStat;
  DestDim.eTurnIndicator              = SrcDim.eTurnIndicator;
/* stuffing reasonable values */
  DestDim.sSigHeader.eSigStatus       = AL_SIG_STATE_OK;
  DestDim.sSigHeader.uiCycleCounter   = 0u;
  DestDim.sSigHeader.uiMeasurementCounter = 0u;
  DestDim.sSigHeader.uiTimeStamp      = 0u;
}

void CConvDimInputGeneric::ConvertToV4(const DimInputV5::DIMInputGeneric_t &SrcDim, DimInputV4::DIMInputGeneric_t &DestDim)
{
  DestDim.uiVersionNumber             = 4;
  DestDim.bACCActive                  = SrcDim.bACCActive;
  DestDim.eDriverSetting              = SrcDim.eDriverSetting;
  DestDim.fSteeringWheelAngle         = SrcDim.fSteeringWheelAngle;
  DestDim.fSteeringWheelAngleGrad     = SrcDim.fSteeringWheelAngleGrad;
  DestDim.eSteeringWheelAngleStat     = SrcDim.eSteeringWheelAngleStat;
  DestDim.eSteeringWheelAngleGradStat = SrcDim.eSteeringWheelAngleGradStat;
  DestDim.fAccelPedalPos              = SrcDim.fAccelPedalPos;
  DestDim.fAccelPedalGrad             = SrcDim.fAccelPedalGrad;
  DestDim.eAccelPadelStat             = SrcDim.eAccelPadelStat;
  DestDim.eAccelPadelGradStat         = SrcDim.eAccelPadelGradStat;
  DestDim.eTurnIndicator              = SrcDim.eTurnIndicator;
/* stuffing reasonable values */
  DestDim.sSigHeader                  = SrcDim.sSigHeader;
}

void CConvDimInputGeneric::ConvertToV5(const DimInputV4::DIMInputGeneric_t &SrcDim, DimInputV5::DIMInputGeneric_t &DestDim)
{
  DestDim.uiVersionNumber             = 5;
  DestDim.bACCActive                  = SrcDim.bACCActive;
  DestDim.eDriverSetting              = SrcDim.eDriverSetting;
  DestDim.fSteeringWheelAngle         = SrcDim.fSteeringWheelAngle;
  DestDim.fSteeringWheelAngleGrad     = SrcDim.fSteeringWheelAngleGrad;
  DestDim.eSteeringWheelAngleStat     = SrcDim.eSteeringWheelAngleStat;
  DestDim.eSteeringWheelAngleGradStat = SrcDim.eSteeringWheelAngleGradStat;
  DestDim.fAccelPedalPos              = SrcDim.fAccelPedalPos;
  DestDim.fAccelPedalGrad             = SrcDim.fAccelPedalGrad;
  DestDim.eAccelPadelStat             = SrcDim.eAccelPadelStat;
  DestDim.eAccelPadelGradStat         = SrcDim.eAccelPadelGradStat;
  DestDim.eTurnIndicator              = SrcDim.eTurnIndicator;
  DestDim.ePowerTrainEngaged          = 0;
/* stuffing reasonable values */
  DestDim.sSigHeader                  = SrcDim.sSigHeader;
}

void CConvDimInputGeneric::InitGenericInputV1(DimInputV1::DIMInputGeneric_t &DestDim)
{
  memset(&DestDim, 0, sizeof(DestDim));
  DestDim.uiVersionNumber = 1ul;
}

void CConvDimInputGeneric::InitGenericInputV2(DimInputV2::DIMInputGeneric_t &DestDim)
{
  memset(&DestDim, 0, sizeof(DestDim));
  DestDim.uiVersionNumber = 2ul;
}

void CConvDimInputGeneric::InitGenericInputV3(DimInputV3::DIMInputGeneric_t &DestDim)
{
  memset(&DestDim, 0, sizeof(DestDim));
  DestDim.uiVersionNumber = 3ul;
}

void CConvDimInputGeneric::InitGenericInputV4(DimInputV4::DIMInputGeneric_t &DestDim)
{
  memset(&DestDim, 0, sizeof(DestDim));
  DestDim.uiVersionNumber = 4ul;
}

void CConvDimInputGeneric::InitGenericInputV5(DimInputV5::DIMInputGeneric_t &DestDim)
{
  memset(&DestDim, 0, sizeof(DestDim));
  DestDim.uiVersionNumber = 5ul;
}

//
// Factory method
//
IConverter * CreateDimInputGenericConvInstance(void)
{
  return new CConvDimInputGeneric();
}
