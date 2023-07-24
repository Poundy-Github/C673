/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter_fct

  MODULNAME:            sim_conv_object_list.h

  DESCRIPTION:          

  AUTHOR:               Ovidiu Raicu

  CREATION DATE:        23.03.2010

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: sim_conv_images.h  $
  CHANGES:              Revision 1.1 2021/12/13 17:19:48CET Wang, David (Wangd3) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/adapter/conv_images/project.pj
  CHANGES:              Revision 1.2.1.2 2019/02/19 13:15:45CET Paulig, Ralf (uidt3509) 
  CHANGES:              new image version including intrinsics used in MFC5xx
  CHANGES:              Revision 1.2.1.1 2018/08/31 15:41:48CEST Paulig, Ralf (uidt3509) 
  CHANGES:              make use of extractor dll
  CHANGES:              Revision 1.2 2018/07/25 17:31:33CEST Elsayed, Abdallah (uid34177) 
  CHANGES:              updated
  CHANGES:              Revision 1.1 2018/05/28 11:07:41CEST Paulig, Ralf (uidt3509) 
  CHANGES:              MFC510 image is same as MFC4xx but with additional 140 byte footer.
  CHANGES:              Accept those images and ignore the footer for conversion.
  CHANGES:              Revision 1.0 2017/03/03 10:30:23CET Sorge, Sven (uidg3181) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/adapter/converters/conv_images/project.pj
  CHANGES:              Revision 1.9 2014/07/21 17:42:03CEST Paulig, Ralf (uidt3509) 
  CHANGES:              introduce 128 byte padding for rte images
  CHANGES:              - Added comments -  uidt3509 [Jul 21, 2014 5:42:04 PM CEST]
  CHANGES:              Change Package : 241127:1 http://mks-psad:7002/im/viewissue?selection=241127
  CHANGES:              Revision 1.8 2014/06/10 15:02:57CEST Paulig, Ralf (uidt3509) 
  CHANGES:              fixes:
  CHANGES:              - fixed memory allocation issues
  CHANGES:              features:
  CHANGES:              - save last conversions for re-use
  CHANGES:              - template functions for better code structure
  CHANGES:              --- Added comments ---  uidt3509 [Jun 10, 2014 3:02:57 PM CEST]
  CHANGES:              Change Package : 232005:4 http://mks-psad:7002/im/viewissue?selection=232005
  CHANGES:              Revision 1.7 2014/05/21 09:18:05CEST Sorge-EXT, Sven (uidg3181) 
  CHANGES:              changed versionnumber computation
  CHANGES:              --- Added comments ---  uidg3181 [May 21, 2014 9:18:05 AM CEST]
  CHANGES:              Change Package : 199693:5 http://mks-psad:7002/im/viewissue?selection=199693
  CHANGES:              Revision 1.6 2014/03/18 11:51:38CET Sorge-EXT, Sven (uidg3181) 
  CHANGES:              Added: ImagesV3 and Conversion from RawImage
  CHANGES:              --- Added comments ---  uidg3181 [Mar 18, 2014 11:51:38 AM CET]
  CHANGES:              Change Package : 217703:2 http://mks-psad:7002/im/viewissue?selection=217703
  CHANGES:              Revision 1.1 2014/03/18 11:36:07CET Sorge-EXT, Sven (uidg3181) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/adapter/converters/conv_images/conv_images_save/project.pj
  CHANGES:              Revision 1.2 2014/03/18 10:47:15CET Sorge-EXT, Sven (uidg3181) 
  CHANGES:              Added Raw Conversion
  CHANGES:              Revision 1.1 2014/02/25 17:04:46CET Schutsch-EXT, Julian (uidg2542) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/adapter/converters/conv_images/project.pj
  CHANGES:              Revision 1.4 2014/01/28 16:32:26CET Klein, Wladimir (uidu6289) 
  CHANGES:              added CTK conversion
  CHANGES:              --- Added comments ---  uidu6289 [Jan 28, 2014 4:32:27 PM CET]
  CHANGES:              Change Package : 27465:13 http://mks-psad:7002/im/viewissue?selection=27465
  CHANGES:              Revision 1.3 2014/01/21 10:29:22CET Kitt, Bernd (uidw6145) 
  CHANGES:              fixed wrong check in
  CHANGES:              --- Added comments ---  uidw6145 [Jan 21, 2014 10:29:22 AM CET]
  CHANGES:              Change Package : 210798:1 http://mks-psad:7002/im/viewissue?selection=210798
  CHANGES:              Revision 1.1 2013/11/27 18:12:43CET Schutsch-EXT, Julian (uidg2542) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CCT_CommonCameraToolbox/04_Engineering/03_Workspace/algo/cct_sim/adapter/converters/conv_images/project.pj
  CHANGES:              Revision 1.4 2013/02/28 13:25:51CET Mueller, Reik (muellerr5) 
  CHANGES:              - added function AllocImageData() to fix memory leak
  CHANGES:              --- Added comments ---  muellerr5 [Feb 28, 2013 1:25:52 PM CET]
  CHANGES:              Change Package : 173648:2 http://mks-psad:7002/im/viewissue?selection=173648
  CHANGES:              Revision 1.3 2013/02/22 13:11:57CET Pfitzer, Martin (uidu4871) 
  CHANGES:              added converter to RTE ImageU16 Version2
  CHANGES:              --- Added comments ---  uidu4871 [Feb 22, 2013 1:11:57 PM CET]
  CHANGES:              Change Package : 131461:4 http://mks-psad:7002/im/viewissue?selection=131461
  CHANGES:              Revision 1.2 2013/02/06 12:59:43CET Spruck, Jochen (spruckj) 
  CHANGES:              Add vdy offsets adapter to semo adapter, and use const vars instead of defines in interface namespaces
  CHANGES:              --- Added comments ---  spruckj [Feb 6, 2013 12:59:43 PM CET]
  CHANGES:              Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:              Revision 1.1 2013/01/17 09:34:25CET Spruck, Jochen (spruckj) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/PROJECTS/MFC400/06_Algorithm/04_Engineering/03_Workspace/algo/cct_sim/cct_adapter/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */
#pragma once
#include "sim_versioninfo_impl.h"
#include "sim_mem_ifc.h"
#include "conv_images\include\interface_images.h"
#include "extractor_ifc_wrapper.h"

class CConvImages : public CAdapterConverterBase
{
  static const int RTE_LINE_START_BOUNDARY = 128;

  ImagesV1::ImageU16_t m_ImagesV1;
  ImagesV2::ImageU16_t m_ImagesV2;
  ImagesV3::ImageU16_t m_ImagesV3;
  ImagesV4::ImageU16_t m_ImagesV4;

  uint32 GetImageInterfaceVersion(SimPortDataTypes_t /*ePortType*/, unsigned long ulPortSize, void* pPortData);
  bool PortSupported(SimPortDataTypes_t ePortType, unsigned long ulPortSize, const IVersionInfo * pPortVersionInfo = NULL) const;

  void InitDefaultV1(ImagesV1::ImageU16_t & Images);
  void InitDefaultV2(ImagesV2::ImageU16_t & Images);
  void InitDefaultV3(ImagesV3::ImageU16_t & Images);
  void InitDefaultV4(ImagesV4::ImageU16_t & Images);

  // ctk images
  template<typename Version>
  int ConvertToGeneric(const ImageCtk::CTKImageData_t & SrcImage, typename Version::ImageU16_t*& DstImage);
  int ConvertToV1(const ImageCtk::CTKImageData_t & SrcImage, ImagesV1::ImageU16_t*& DstImage);
  int ConvertToV2(const ImageCtk::CTKImageData_t & SrcImage, ImagesV2::ImageU16_t*& DstImage);
  int ConvertToV3(const ImageCtk::CTKImageData_t & SrcImage, ImagesV3::ImageU16_t*& DstImage);
  int ConvertToV4(const ImageCtk::CTKImageData_t & SrcImage, ImagesV4::ImageU16_t*& DstImage);

  // raw images
  template<typename Version>
  int ConvertRawToGenericWrapper(void* SrcImage, typename Version::ImageU16_t*& DstImage, unsigned long ulProvidePortSize);
  template<typename Version>
  int ConvertRawToGenericWithExtractor(void* SrcImage, typename Version::ImageU16_t*& DstImage, unsigned long ulProvidePortSize);
  template<typename Version>
  int ConvertRawToGeneric(void* SrcImage, typename Version::ImageU16_t*& DstImage, unsigned long ulProvidePortSize);
  int ConvertRawToV1(void* SrcImage, ImagesV1::ImageU16_t*& DstImage, unsigned long ulProvidePortSize);
  int ConvertRawToV2(void* SrcImage, ImagesV2::ImageU16_t*& DstImage, unsigned long ulProvidePortSize);
  int ConvertRawToV3(void* SrcImage, ImagesV3::ImageU16_t*& DstImage, unsigned long ulProvidePortSize);
  int ConvertRawToV4(void* SrcImage, ImagesV4::ImageU16_t*& DstImage, unsigned long ulProvidePortSize);


public:

  static CAdapterConverterBase* Create()
  {
    return new CConvImages;
  }

  static const wchar_t* GetConverterTypeName()
  {
    return L"ImageU16_t";
  }

  CConvImages(void);
  virtual ~CConvImages(void);

  const wchar_t* GetTypeName()
  {
    return GetConverterTypeName();
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
  static CVersionInfoImpl V1_IMAGES;
  static CVersionInfoImpl V2_IMAGES;
  static CVersionInfoImpl V3_IMAGES;
  static CVersionInfoImpl V4_IMAGES;

  enum eImagesVersions
  {
    IMAGES_V1,
    IMAGES_V2,
    IMAGES_V3,
    IMAGES_V4,
    IMAGES_VERSION_COUNT
  };

  CExtractorIfcWrapper m_ExtractorIfcWrapper;


  struct SImageInfoStruct
  {
    BYTE    m_bDarkStart1InfoLines;
    BYTE    m_bStart2InfoLines;
    BYTE    m_bEndInfoLines;
    UINT16  m_unHeight;
    UINT16  m_unWidth;
  };

  // pixel alignment of data coming from the MI-EMS
  // two 12bit pixels are packed into three bytes
  // Source data:
  // 1 24bit pixel A  A  A  A  A  A  A  A  B  B  B  B  B  B  B  B  C  C  C  C  C  C  C  C
  //              -----------------------------------------------------------------------
  // Dest. data    a  a  a  a  a  a  a  a  a  a  a  a  b  b  b  b  b  b  b  b  b  b  b  b
  //              07 06 05 04 03 02 01 00 11 10 09 08 03 02 01 00 11 10 09 08 07 06 05 04
  union PixelAlignment
  {
      BYTE bytes[3];
  };

  // - Registers
  // Line1: 152 regs (R0x3000 - R0x312F)
  // Line2:  93 regs (R0x3136 - R0x31BF, R0x31D0 - R0x31FF) 69 + 24
  static const USHORT sNoOfRegs = 245;
  struct SPairData
  {
    USHORT sAddress;
    USHORT sValue;
  };

  // - Statistics
  static const USHORT sNoOfHist = 244;
  static const USHORT sNoOfStats = sNoOfHist + 8;
  struct SLongPairData
  {
    USHORT sAddress;
    DWORD  sValue;
  };

  struct EmbeddedRegisters
  {
    SPairData regs[sNoOfRegs];
  };

  struct EmbeddedStatistics
  {
    SLongPairData stats[sNoOfStats];
  };

  struct MFCEmbeddedData
  {
    EmbeddedRegisters embeddedRegs;
    EmbeddedStatistics embeddedStats;      
  };

  static const struct SupportedVersion {
    unsigned long       uiSize;
    CVersionInfoImpl  * pVersion;
  } SupportedVersions[IMAGES_VERSION_COUNT];


  typedef std::map<const char*, void*> t_MemMap;
  void* m_pSrcLast;
  t_MemMap m_MemMap;
  void ClearMemMap();
  template<typename Version>
  void AllocImageData(void* pSrc, int numBytes, typename Version::ImageU16_t*& pDst, bool& bConvertedResultAvailable);


  static const BYTE  m_bDefaultDarkInfoLines  = 16;
  static const BYTE  m_bImageUnitBytes        = 3;
  static const BYTE  m_bImageUnitPixels       = 2;
    
  sint32 GetImageParameter(unsigned long &providePortSize, SImageInfoStruct &imageInfo);
  USHORT GetImageFrameCounter(void *srcImage, const unsigned long ulPPortSize, const SImageInfoStruct &imageInfo);
  int GetImageData(void *SrcImage, void* pDestImage, uint32 uiLineBytes, uint32 iSizeBytes, unsigned long ulPPortSize, const SImageInfoStruct &imageInfo);
  INT32  ExtractEmbeddedData(void *SrcImage, void* pDestImage, uint32 dwDestSize, unsigned long ulPPortSize, SImageInfoStruct &imageInfo);
  INT32  ExtractStatisticsData(void *SrcImage, void* pDestImage, uint32 dwDestSize, unsigned long ulPPortSize, SImageInfoStruct &imageInfo);

};
