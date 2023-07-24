/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter_fct

  MODULNAME:            sim_conv_object_list.cpp

  DESCRIPTION:          

  AUTHOR:               Ovidiu Raicu

  CREATION DATE:        23.03.2010

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: sim_conv_images.cpp  $
  CHANGES:              Revision 1.1 2021/12/13 17:19:48CET Wang, David (Wangd3) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/adapter/conv_images/project.pj
  CHANGES:              Revision 1.2.1.6 2019/04/24 09:12:42CEST Paulig, Ralf (uidt3509) 
  CHANGES:              fixed reporting of errors
  CHANGES:              Revision 1.2.1.5 2019/02/27 09:29:31CET Paulig, Ralf (uidt3509) 
  CHANGES:              uiParameterId removed for image version 4
  CHANGES:              Revision 1.2.1.4 2019/02/21 13:36:04CET Paulig, Ralf (uidt3509) 
  CHANGES:              fixed bug in fingerprint calculation with new image version
  CHANGES:              Revision 1.2.1.3 2019/02/19 13:15:44CET Paulig, Ralf (uidt3509) 
  CHANGES:              new image version including intrinsics used in MFC5xx
  CHANGES:              Revision 1.2.1.2 2018/09/07 13:28:10CEST Bakkari, Olga (uidg3191) 
  CHANGES:              tiny bugfix
  CHANGES:              Revision 1.2.1.1 2018/08/31 15:41:47CEST Paulig, Ralf (uidt3509) 
  CHANGES:              make use of extractor dll
  CHANGES:              Revision 1.2 2018/07/25 17:31:33CEST Elsayed, Abdallah (uid34177) 
  CHANGES:              updated
  CHANGES:              Revision 1.1 2018/05/28 10:12:44CEST Paulig, Ralf (uidt3509) 
  CHANGES:              MFC510 image is same as MFC4xx but with additional 140 byte footer.
  CHANGES:              Accept those images and ignore the footer for conversion.
  CHANGES:              Revision 1.0 2017/03/03 10:30:23CET Sorge, Sven (uidg3181) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/adapter/converters/conv_images/project.pj
  CHANGES:              Revision 1.25 2016/09/16 07:09:02CEST Sorge, Sven (uidg3181) 
  CHANGES:              bugfix: copy the right amount of data
  CHANGES:              Revision 1.24 2014/07/23 13:19:13CEST Paulig, Ralf (uidt3509) 
  CHANGES:              fix start address of image
  CHANGES:              - Added comments -  uidt3509 [Jul 23, 2014 1:19:13 PM CEST]
  CHANGES:              Change Package : 241127:1 http://mks-psad:7002/im/viewissue?selection=241127
  CHANGES:              Revision 1.23 2014/07/21 17:42:02CEST Paulig, Ralf (uidt3509) 
  CHANGES:              introduce 128 byte padding for rte images
  CHANGES:              --- Added comments ---  uidt3509 [Jul 21, 2014 5:42:03 PM CEST]
  CHANGES:              Change Package : 241127:1 http://mks-psad:7002/im/viewissue?selection=241127
  CHANGES:              Revision 1.22 2014/07/14 16:53:20CEST Paulig, Ralf (uidt3509) 
  CHANGES:              no instance for fingerprint singleton
  CHANGES:              --- Added comments ---  uidt3509 [Jul 14, 2014 4:53:20 PM CEST]
  CHANGES:              Change Package : 241127:1 http://mks-psad:7002/im/viewissue?selection=241127
  CHANGES:              Revision 1.21 2014/07/11 17:19:44CEST Paulig, Ralf (uidt3509) 
  CHANGES:              added fingerprint calculation to image converter
  CHANGES:              --- Added comments ---  uidt3509 [Jul 11, 2014 5:19:44 PM CEST]
  CHANGES:              Change Package : 241127:1 http://mks-psad:7002/im/viewissue?selection=241127
  CHANGES:              Revision 1.20 2014/06/30 16:12:57CEST Lopez, Alejandro (uidw6142) 
  CHANGES:              Extended condition for image conversion
  CHANGES:              --- Added comments ---  uidw6142 [Jun 30, 2014 4:12:58 PM CEST]
  CHANGES:              Change Package : 241126:1 http://mks-psad:7002/im/viewissue?selection=241126
  CHANGES:              Revision 1.19 2014/06/24 17:34:17CEST Paulig, Ralf (uidt3509) 
  CHANGES:              fixed issue on extraction of embedded statistics
  CHANGES:              --- Added comments ---  uidt3509 [Jun 24, 2014 5:34:18 PM CEST]
  CHANGES:              Change Package : 232005:1 http://mks-psad:7002/im/viewissue?selection=232005
  CHANGES:              Revision 1.18 2014/06/10 15:02:56CEST Paulig, Ralf (uidt3509) 
  CHANGES:              fixes:
  CHANGES:              - fixed memory allocation issues
  CHANGES:              features:
  CHANGES:              - save last conversions for re-use
  CHANGES:              - template functions for better code structure
  CHANGES:              --- Added comments ---  uidt3509 [Jun 10, 2014 3:02:56 PM CEST]
  CHANGES:              Change Package : 232005:4 http://mks-psad:7002/im/viewissue?selection=232005
  CHANGES:              Revision 1.17 2014/05/27 11:16:05CEST Sorge-EXT, Sven (uidg3181) 
  CHANGES:              Bugfix error code handling
  CHANGES:              --- Added comments ---  uidg3181 [May 27, 2014 11:16:06 AM CEST]
  CHANGES:              Change Package : 199693:5 http://mks-psad:7002/im/viewissue?selection=199693
  CHANGES:              Revision 1.16 2014/05/21 09:40:42CEST Sorge-EXT, Sven (uidg3181) 
  CHANGES:              Error message misaligned
  CHANGES:              --- Added comments ---  uidg3181 [May 21, 2014 9:40:43 AM CEST]
  CHANGES:              Change Package : 199693:5 http://mks-psad:7002/im/viewissue?selection=199693
  CHANGES:              Revision 1.15 2014/05/21 09:18:04CEST Sorge-EXT, Sven (uidg3181) 
  CHANGES:              changed versionnumber computation
  CHANGES:              --- Added comments ---  uidg3181 [May 21, 2014 9:18:05 AM CEST]
  CHANGES:              Change Package : 199693:5 http://mks-psad:7002/im/viewissue?selection=199693
  CHANGES:              Revision 1.14 2014/05/20 09:44:57CEST Sorge-EXT, Sven (uidg3181) 
  CHANGES:              Added new Imagesize for SRLCam and added Error message for unknown Imagesizes
  CHANGES:              --- Added comments ---  uidg3181 [May 20, 2014 9:44:58 AM CEST]
  CHANGES:              Change Package : 199693:5 http://mks-psad:7002/im/viewissue?selection=199693
  CHANGES:              Revision 1.13 2014/05/13 17:16:43CEST Sorge-EXT, Sven (uidg3181) 
  CHANGES:              Added condition before conversion to Ctk Image
  CHANGES:              --- Added comments ---  uidg3181 [May 13, 2014 5:16:43 PM CEST]
  CHANGES:              Change Package : 199693:5 http://mks-psad:7002/im/viewissue?selection=199693
  CHANGES:              Revision 1.12 2014/05/13 10:21:42CEST Sorge-EXT, Sven (uidg3181) 
  CHANGES:              Removed memory allocating bug
  CHANGES:              --- Added comments ---  uidg3181 [May 13, 2014 10:21:42 AM CEST]
  CHANGES:              Change Package : 199693:5 http://mks-psad:7002/im/viewissue?selection=199693
  CHANGES:              Revision 1.11 2014/03/18 11:51:37CET Sorge-EXT, Sven (uidg3181) 
  CHANGES:              Added: ImagesV3 and Conversion from RawImage
  CHANGES:              --- Added comments ---  uidg3181 [Mar 18, 2014 11:51:38 AM CET]
  CHANGES:              Change Package : 217703:2 http://mks-psad:7002/im/viewissue?selection=217703
  CHANGES:              Revision 1.1 2014/03/18 11:36:07CET Sorge-EXT, Sven (uidg3181) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/adapter/converters/conv_images/conv_images_save/project.pj
  CHANGES:              Revision 1.2 2014/03/18 10:47:14CET Sorge-EXT, Sven (uidg3181) 
  CHANGES:              Added Raw Conversion
  CHANGES:              Revision 1.1 2014/02/25 17:04:45CET Schutsch-EXT, Julian (uidg2542) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/adapter/converters/conv_images/project.pj
  CHANGES:              Revision 1.4 2014/01/28 16:32:26CET Klein, Wladimir (uidu6289) 
  CHANGES:              added CTK conversion
  CHANGES:              --- Added comments ---  uidu6289 [Jan 28, 2014 4:32:26 PM CET]
  CHANGES:              Change Package : 27465:13 http://mks-psad:7002/im/viewissue?selection=27465
  CHANGES:              Revision 1.3 2014/01/21 10:28:46CET Kitt, Bernd (uidw6145) 
  CHANGES:              fixed wrong check in
  CHANGES:              --- Added comments ---  uidw6145 [Jan 21, 2014 10:28:46 AM CET]
  CHANGES:              Change Package : 210798:1 http://mks-psad:7002/im/viewissue?selection=210798
  CHANGES:              Revision 1.1 2013/11/27 18:12:43CET Schutsch-EXT, Julian (uidg2542) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CCT_CommonCameraToolbox/04_Engineering/03_Workspace/algo/cct_sim/adapter/converters/conv_images/project.pj
  CHANGES:              Revision 1.10 2013/10/17 14:40:25CEST Paulig, Ralf (uidt3509) 
  CHANGES:              Removed buggy version comparison.
  CHANGES:              --- Added comments ---  uidt3509 [Oct 17, 2013 2:40:25 PM CEST]
  CHANGES:              Change Package : 195872:1 http://mks-psad:7002/im/viewissue?selection=195872
  CHANGES:              Revision 1.9 2013/04/08 13:01:53CEST Ulveland, Lars (uidt7777) 
  CHANGES:              Removed an appearantly unused include which was never found.
  CHANGES:              --- Added comments ---  uidt7777 [Apr 8, 2013 1:01:53 PM CEST]
  CHANGES:              Change Package : 75818:1 http://mks-psad:7002/im/viewissue?selection=75818
  CHANGES:              Revision 1.8 2013/02/28 13:27:12CET Mueller, Reik (muellerr5) 
  CHANGES:              - added function AllocImageData() to fix memory leak
  CHANGES:              --- Added comments ---  muellerr5 [Feb 28, 2013 1:27:13 PM CET]
  CHANGES:              Change Package : 173648:2 http://mks-psad:7002/im/viewissue?selection=173648
  CHANGES:              Revision 1.7 2013/02/22 14:57:24CET Pfitzer, Martin (uidu4871) 
  CHANGES:              added some parameters in the ver2 namespace
  CHANGES:              --- Added comments ---  uidu4871 [Feb 22, 2013 2:57:24 PM CET]
  CHANGES:              Change Package : 131461:4 http://mks-psad:7002/im/viewissue?selection=131461
  CHANGES:              Revision 1.6 2013/02/22 13:08:45CET Pfitzer, Martin (uidu4871) 
  CHANGES:              added converter for the new RTE definition of ImageU16 (V2)
  CHANGES:              new ParameterID is currently set to 0 (hardcoded)
  CHANGES:              --- Added comments ---  uidu4871 [Feb 22, 2013 1:08:45 PM CET]
  CHANGES:              Change Package : 131461:4 http://mks-psad:7002/im/viewissue?selection=131461
  CHANGES:              Revision 1.5 2013/02/06 12:59:45CET Spruck, Jochen (spruckj) 
  CHANGES:              Add vdy offsets adapter to semo adapter, and use const vars instead of defines in interface namespaces
  CHANGES:              --- Added comments ---  spruckj [Feb 6, 2013 12:59:46 PM CET]
  CHANGES:              Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:              Revision 1.4 2013/01/24 11:47:42CET Friebertshaeuser, Markus (uidt0551) 
  CHANGES:              - adapt image dimensions correctly
  CHANGES:              - adapt bayer pattern corrctly
  CHANGES:              --- Added comments ---  uidt0551 [Jan 24, 2013 11:47:43 AM CET]
  CHANGES:              Change Package : 162889:10 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:              Revision 1.3 2013/01/22 10:20:08CET Westhofen, Daniel (uidt2642) 
  CHANGES:              Removed port size check (ulPPortSize)
  CHANGES:              --- Added comments ---  uidt2642 [Jan 22, 2013 10:20:08 AM CET]
  CHANGES:              Change Package : 162889:17 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:              Revision 1.2 2013/01/17 09:59:39CET Spruck, Jochen (spruckj) 
  CHANGES:              Add get RTE version
  CHANGES:              --- Added comments ---  spruckj [Jan 17, 2013 9:59:39 AM CET]
  CHANGES:              Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:              Revision 1.1 2013/01/17 09:34:24CET Spruck, Jochen (spruckj) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/PROJECTS/MFC400/06_Algorithm/04_Engineering/03_Workspace/algo/cct_sim/cct_adapter/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */
#include "stdafx.h"
#include "sim_conv_images.h"
#include "sim_adapter_ext.h"
#include <sstream>
#include <typeinfo>

#include "conv_images\cct_i400\image_fingerprint.h"


CVersionInfoImpl  CConvImages::BASE_VERSION(0, 0, 0);
CVersionInfoImpl  CConvImages::V1_IMAGES(0, 0, 1);
CVersionInfoImpl  CConvImages::V2_IMAGES(0, 0, 2);
CVersionInfoImpl  CConvImages::V3_IMAGES(0, 0, 3);
CVersionInfoImpl  CConvImages::V4_IMAGES(0, 0, 4);

uint32 CConvImages::GetImageInterfaceVersion(SimPortDataTypes_t /*ePortType*/, unsigned long ulPortSize, void* pPortData)
{
  uint32 version = 0xFFFFFFFF;
  if ((ulPortSize > 4) && (pPortData != NULL))
  {
    const ImageCtk::CTKImageData_t & CtkImageData = *reinterpret_cast<const ImageCtk::CTKImageData_t*>(pPortData);
    if (CtkImageData.HeaderSize == sizeof(ImageCtk::CTKImageData_t) && CtkImageData.bmSize == CtkImageData.bmHeight * CtkImageData.bmWidth * sizeof(uint16) && ulPortSize == CtkImageData.bmSize + sizeof(ImageCtk::CTKImageData_t))
    {
      //ctk image -> no version -> version = 0xFFFFFFFF
      return version;
    }

    SImageInfoStruct tempImageStruct;
    if(GetImageParameter(ulPortSize, tempImageStruct) == SIM_ERR_OK)
    {
      //raw image -> no version -> version = 0xFFFFFFFF
      return version;
    }

    version = *reinterpret_cast<const uint32*>(pPortData);
  }
  
  return version;
}


const CConvImages::SupportedVersion CConvImages::SupportedVersions[IMAGES_VERSION_COUNT] = 
{
  {
    sizeof(ImagesV1::ImageU16_t),
    &V1_IMAGES,
  },
  {
    sizeof(ImagesV2::ImageU16_t),
    &V2_IMAGES,
  },
  {
    sizeof(ImagesV3::ImageU16_t),
    &V3_IMAGES,
  },
  {
    sizeof(ImagesV4::ImageU16_t),
    &V4_IMAGES,
  }
};

CConvImages::CConvImages(void) : CAdapterConverterBase()
, m_pSrcLast(NULL)
{
  InitDefaultV1(m_ImagesV1);
  InitDefaultV2(m_ImagesV2);
  InitDefaultV3(m_ImagesV3);
  InitDefaultV4(m_ImagesV4);

}

CConvImages::~CConvImages(void)
{
  ClearMemMap();
}

void CConvImages::ClearMemMap()
{
  t_MemMap::iterator it = m_MemMap.begin();
  for ( ; it != m_MemMap.end(); it++)
  {
    void* pDst = it->second;
    MemLock(pDst, FALSE);
    MemFree(pDst);
  }
  m_MemMap.clear();
}

template<typename Version>
void CConvImages::AllocImageData(void* pSrc, int numBytes, typename Version::ImageU16_t*& pDst, bool& bConvertedResultAvailable)
{
  bConvertedResultAvailable = false;
  if (pSrc == m_pSrcLast)
  {
    t_MemMap::iterator it = m_MemMap.find(typeid(typename Version::ImageU16_t).name());
    if (it != m_MemMap.end())
    {
      // we already have a conversion from a previous call
      bConvertedResultAvailable = true;
      pDst = reinterpret_cast<typename Version::ImageU16_t* >(it->second);
      return;
    }
  }
  else
  {
    MemLock(m_pSrcLast, FALSE);
    ClearMemMap();
    m_pSrcLast = pSrc;
    MemLock(m_pSrcLast, TRUE);
  }

  // alloc new memory for dst and lock it
  pDst = reinterpret_cast<typename Version::ImageU16_t* >(MemAlloc(numBytes));
  MemLock(pDst, TRUE);

  m_MemMap[typeid(typename Version::ImageU16_t).name()] = pDst;
}

bool CConvImages::PortSupported(SimPortDataTypes_t ePortType, unsigned long ulPortSize, const IVersionInfo * pPortVersionInfo) const
{
  bool bResult = false;
  unsigned int i;
  // in case of reference input port the input port should be supported
  if (ePortType == simREFERENCE_t)
  {
    bResult = true;
  }

  // conversion
  for (i=0;(i<CConvImages::IMAGES_VERSION_COUNT) && (!bResult);i++)
  {
    if ((ePortType == simOPAQUE_t) && (ulPortSize == SupportedVersions[i].uiSize))
    {
      // Check if version information is compatible - with extra care for simulators that
      // do not set the version number at all...
      if ((pPortVersionInfo == NULL) || (pPortVersionInfo->Equals(CConvImages::SupportedVersions[i].pVersion)) || (pPortVersionInfo->Equals(&BASE_VERSION)))
      {
        bResult = true;
      }
    }
  }
  return bResult;
}

void CConvImages::InitDefaultV1(ImagesV1::ImageU16_t & Images)
{
  memset(&Images, 0, sizeof(Images));
  Images.uiVersionNumber = 1;
  Images.sSigHeader.eSigStatus           = ImagesV1::AL_SIG_STATE_INVALID;
}

void CConvImages::InitDefaultV2(ImagesV2::ImageU16_t & Images)
{
  memset(&Images, 0, sizeof(Images));
  Images.uiVersionNumber = 2;
  Images.sSigHeader.eSigStatus           = ImagesV2::AL_SIG_STATE_INVALID;
}

void CConvImages::InitDefaultV3(ImagesV3::ImageU16_t & Images)
{
  memset(&Images, 0, sizeof(Images));
  Images.uiVersionNumber = 3;
  Images.sSigHeader.eSigStatus           = ImagesV3::AL_SIG_STATE_INVALID;
}

void CConvImages::InitDefaultV4(ImagesV4::ImageU16_t & Images)
{
  memset(&Images, 0, sizeof(Images));
  Images.uiVersionNumber = 4;
  Images.sSigHeader.eSigStatus           = ImagesV4::AL_SIG_STATE_INVALID;
}

sint32 CConvImages::GetImageParameter(unsigned long &providePortSize, SImageInfoStruct &imageInfo)
{
  sint32 i32Result = SIM_ERR_OK;
  switch(providePortSize)
  {
  case 571392:
    imageInfo.m_bDarkStart1InfoLines = 0;
    imageInfo.m_bStart2InfoLines = 0;
    imageInfo.m_bEndInfoLines = 0;
    imageInfo.m_unHeight = 372;
    imageInfo.m_unWidth = 1024;
    break;
  case 577536:
    imageInfo.m_bDarkStart1InfoLines = 0;
    imageInfo.m_bStart2InfoLines = 2;
    imageInfo.m_bEndInfoLines = 2;
    imageInfo.m_unHeight = 372;
    imageInfo.m_unWidth = 1024;
    break;
  case 989184:
    imageInfo.m_bDarkStart1InfoLines = 0;
    imageInfo.m_bStart2InfoLines = 2;
    imageInfo.m_bEndInfoLines = 2;
    imageInfo.m_unHeight = 640;
    imageInfo.m_unWidth = 1024;
    break;
  case 1136016:
    imageInfo.m_bDarkStart1InfoLines = 0;
    imageInfo.m_bStart2InfoLines = 2;
    imageInfo.m_bEndInfoLines = 2;
    imageInfo.m_unHeight = 640;
    imageInfo.m_unWidth = 1176;
    break;
  case 1164240:                               // MFC4xx long image
    imageInfo.m_bDarkStart1InfoLines = 16;
    imageInfo.m_bStart2InfoLines = 2;
    imageInfo.m_bEndInfoLines = 2;
    imageInfo.m_unHeight = 640;
    imageInfo.m_unWidth = 1176;
    break;
  case 1164380:                               // MFC510 long image same as MFC431 but additional image footer of 140 bytes which can be ignored
    imageInfo.m_bDarkStart1InfoLines = 16;
    imageInfo.m_bStart2InfoLines = 2;
    imageInfo.m_bEndInfoLines = 2;
    imageInfo.m_unHeight = 640;
    imageInfo.m_unWidth = 1176;
    providePortSize -= 140;
    break;
  case 885528:                               // MFC4xx short image
    imageInfo.m_bDarkStart1InfoLines = 16;
    imageInfo.m_bStart2InfoLines = 2;
    imageInfo.m_bEndInfoLines = 2;
    imageInfo.m_unHeight = 482;
    imageInfo.m_unWidth = 1176;
    break;
  case 885668:                               // MFC510 short image same as MFC431 but additional image footer of 140 bytes which can be ignored
    imageInfo.m_bDarkStart1InfoLines = 16;
    imageInfo.m_bStart2InfoLines = 2;
    imageInfo.m_bEndInfoLines = 2;
    imageInfo.m_unHeight = 482;
    imageInfo.m_unWidth = 1176;
    providePortSize -= 140;
    break;
    //rectified image1
  case 615936:
    imageInfo.m_bDarkStart1InfoLines = 1;
    imageInfo.m_bStart2InfoLines = 0;
    imageInfo.m_bEndInfoLines = 0;
    imageInfo.m_unHeight = 400;
    imageInfo.m_unWidth = 1024;
    break;
    //rectified image2
  case 520704:
    imageInfo.m_bDarkStart1InfoLines = 1;
    imageInfo.m_bStart2InfoLines = 0;
    imageInfo.m_bEndInfoLines = 0;
    imageInfo.m_unHeight = 338;
    imageInfo.m_unWidth = 1024;
    break;
  case 798840 :
    // new added case for smaller imager ( for MFC 316 device )
    imageInfo.m_bDarkStart1InfoLines = 0;
    imageInfo.m_bStart2InfoLines = 2;
    imageInfo.m_bEndInfoLines = 2;
    imageInfo.m_unHeight = 630;
    imageInfo.m_unWidth = 840;
    break;
  case 612360 :
    // another new added case for smaller imager ( for MFC 316 device )
    imageInfo.m_bDarkStart1InfoLines = 0;
    imageInfo.m_bStart2InfoLines = 2;
    imageInfo.m_bEndInfoLines = 2;
    imageInfo.m_unHeight = 482;
    imageInfo.m_unWidth = 840;
    break;
  case 1728720 :
    imageInfo.m_bDarkStart1InfoLines = 16;
    imageInfo.m_bStart2InfoLines = 2;
    imageInfo.m_bEndInfoLines = 2;
    imageInfo.m_unHeight = 960;
    imageInfo.m_unWidth = 1176;
    break;
  case 321048 :
    imageInfo.m_bDarkStart1InfoLines = 16;
    imageInfo.m_bStart2InfoLines = 2;
    imageInfo.m_bEndInfoLines = 2;
    imageInfo.m_unHeight = 182;
    imageInfo.m_unWidth = 1176;
    break;
    // SRLCam
    //long - new
    //(630+2+2+16)*832*3/2
  case  811200:
    imageInfo.m_bDarkStart1InfoLines = 16;
    imageInfo.m_bStart2InfoLines = 2;
    imageInfo.m_bEndInfoLines = 2;
    imageInfo.m_unHeight = 630;
    imageInfo.m_unWidth = 832;
    break;
    //short - new
    //(482+2+2+16)*832*3/2
  case  626496:
    imageInfo.m_bDarkStart1InfoLines = 16;
    imageInfo.m_bStart2InfoLines = 2;
    imageInfo.m_bEndInfoLines = 2;
    imageInfo.m_unHeight = 482;
    imageInfo.m_unWidth = 832;
    break;
    //short - backward compatibility
    //(482+2+2+16)*840*3/2
  case 632520 :
    // fourth new added case for smaller imager ( for MFC 316 device )
    imageInfo.m_bDarkStart1InfoLines = 16;
    imageInfo.m_bStart2InfoLines = 2;
    imageInfo.m_bEndInfoLines = 2;
    imageInfo.m_unHeight = 482;
    imageInfo.m_unWidth = 840;
    break;
    //long - backward compatibility
    //(630+2+2+16)*840*3/2
  case 819000 :
    // third new added case for smaller imager ( for MFC 316 device )
    imageInfo.m_bDarkStart1InfoLines = 16;
    imageInfo.m_bStart2InfoLines = 2;
    imageInfo.m_bEndInfoLines = 2;
    imageInfo.m_unHeight = 630;
    imageInfo.m_unWidth = 840;
    break;
  default:
    i32Result = SIM_ERR_INVALID_DATA_SIZE;
    break;
  }
  return i32Result;
}

USHORT CConvImages::GetImageFrameCounter(void *srcImage, const unsigned long ulPPortSize, const SImageInfoStruct &imageInfo)
{

  USHORT us12BitsValue = 0, us12BitsValueTemp = 0;
  LPBYTE puTempBuffer = reinterpret_cast<LPBYTE>(srcImage);

  //can't get - no embedded data available
  if( 0 == imageInfo.m_bEndInfoLines )
    return 0;

  DWORD dwTempBufferSize = static_cast<DWORD>(imageInfo.m_bEndInfoLines * imageInfo.m_unWidth * m_bImageUnitBytes / m_bImageUnitPixels);
  puTempBuffer += ulPPortSize - dwTempBufferSize;

  PixelAlignment *p3Bytes = reinterpret_cast<PixelAlignment*>(puTempBuffer);

  //jump ove the first register us12BitsValue = p3Bytes->bytes[0] + ((p3Bytes->bytes[1] & 0xf0) << 4);
  p3Bytes++;
  us12BitsValueTemp = p3Bytes->bytes[0] + ((p3Bytes->bytes[1] & 0xf0) << 4);
  us12BitsValue = (us12BitsValueTemp >> 2);
  // statistics value
  // MSB 10b 

  // LSB 10b 
  us12BitsValueTemp = (p3Bytes->bytes[1] & 0x0f) + (p3Bytes->bytes[2] << 4);
  us12BitsValue = (us12BitsValue << 10)+ (us12BitsValueTemp >> 2);
  return us12BitsValue;
}

int CConvImages::GetImageData(void *SrcImage, void* pDestImage, uint32 uiLineBytes, uint32 iSizeBytes, unsigned long ulPPortSize, const SImageInfoStruct &imageInfo)
{
  LPBYTE puTempBuffer = static_cast<LPBYTE>(SrcImage);
  LPBYTE puDestBuffer = static_cast<LPBYTE>(pDestImage);
  DWORD dwTempBufferSize = ulPPortSize;
  DWORD dwTempDestSize = iSizeBytes;
  
  //Jump over Image Header
  DWORD dwSrcLineSize = imageInfo.m_unWidth * m_bImageUnitBytes / m_bImageUnitPixels;
  DWORD dwJumpOver = (imageInfo.m_bDarkStart1InfoLines + imageInfo.m_bStart2InfoLines) * dwSrcLineSize;

  puTempBuffer += dwJumpOver;

  INT32 nReturnCode = SIM_ERR_OK;
  for (unsigned int line = 0; line < imageInfo.m_unHeight; ++line)
  {
    // extract one line
    dwTempBufferSize = dwSrcLineSize;
    LPWORD puTempDestBuffer = reinterpret_cast<LPWORD>(puDestBuffer);
    while (dwTempBufferSize >= 3 && dwTempDestSize >= 4)
    {
      PixelAlignment *pSourcePixel = reinterpret_cast<PixelAlignment*>(puTempBuffer);
      USHORT usPixelValue = (pSourcePixel->bytes[0] + ( (pSourcePixel->bytes[1] & 0xf0) << 4));
      *puTempDestBuffer = usPixelValue;
      puTempDestBuffer++;
      usPixelValue = ((pSourcePixel->bytes[1] & 0x0f) + (pSourcePixel->bytes[2] << 4));
      *puTempDestBuffer = usPixelValue;
      puTempDestBuffer++;
      dwTempDestSize -= 4;

      puTempBuffer += sizeof(PixelAlignment);
      dwTempBufferSize -= sizeof(PixelAlignment);
    }
    puDestBuffer += uiLineBytes;
  }

  return nReturnCode;
}

INT32 CConvImages::ExtractEmbeddedData(void *SrcImage, void* pDestImage, uint32 dwDestSize, unsigned long ulPPortSize, SImageInfoStruct &imageInfo)
{
  LPBYTE puTempBuffer = static_cast<LPBYTE>(SrcImage);
  LPBYTE puTempDestBuffer = static_cast<LPBYTE>(pDestImage);
  DWORD dwTempBufferSize = ulPPortSize;
  DWORD dwTempDestSize = dwDestSize;

  INT32 nReturnCode = 0;
  if( imageInfo.m_bDarkStart1InfoLines + imageInfo.m_bStart2InfoLines > 16 /*m_bDefaultDarkInfoLines*/ )
    puTempBuffer += static_cast<DWORD>(m_bDefaultDarkInfoLines * imageInfo.m_unWidth * m_bImageUnitBytes / m_bImageUnitPixels);


  EmbeddedRegisters * pTmpEmbRegs;

  pTmpEmbRegs = reinterpret_cast<EmbeddedRegisters *>(puTempDestBuffer);

  USHORT usRegsCnt = 0;
  BYTE ubLineNo = 0;

  PixelAlignment *p3Bytes = reinterpret_cast<PixelAlignment*>(puTempBuffer);
  USHORT us12BitsValue = 0;
  BYTE ubEndOfLine;
  bool bIsRegAdr;

  while (ubLineNo < 2)
  {
    // - start of line
    // -- checking the EDF
    if (ubLineNo == 0)
      us12BitsValue = p3Bytes->bytes[0] + ((p3Bytes->bytes[1] & 0xf0) << 4);

    if (us12BitsValue != 0x0A0)
      return 2;

    // -- extracting the registers addresses and values
    ubEndOfLine = 0;
    bIsRegAdr = false;
    do
    {
      // tag value (AA0 - MSB of reg adr; A50 - LSB of reg adr; 05A - reg val
      us12BitsValue = (p3Bytes->bytes[1] & 0x0f) + (p3Bytes->bytes[2] << 4);
      if (us12BitsValue == 0x070)
        ubEndOfLine++;
      else
        if (us12BitsValue == 0xAA0)
          bIsRegAdr = true;
        else
          bIsRegAdr = false;

      if (ubEndOfLine >= 2)
      {
        usRegsCnt--;
        break;
      }
      else
        ubEndOfLine = 0;

      p3Bytes++;

      // MSB of reg address/value
      us12BitsValue = p3Bytes->bytes[0] + ((p3Bytes->bytes[1] & 0xf0) << 4);
      if (bIsRegAdr)
        pTmpEmbRegs->regs[usRegsCnt].sAddress = us12BitsValue;
      else
        pTmpEmbRegs->regs[usRegsCnt].sValue = us12BitsValue;

      // tag value
      us12BitsValue = (p3Bytes->bytes[1] & 0x0f) + (p3Bytes->bytes[2] << 4);
      if (us12BitsValue == 0x070)
        ubEndOfLine++;
      else
        if (us12BitsValue == 0xA50)
          bIsRegAdr = true;
        else
          bIsRegAdr = false;

      p3Bytes++;

      // LSB of reg address/value
      us12BitsValue = p3Bytes->bytes[0] + ((p3Bytes->bytes[1] & 0xf0) << 4);
      if (bIsRegAdr)
      {
        pTmpEmbRegs->regs[usRegsCnt].sAddress = (pTmpEmbRegs->regs[usRegsCnt].sAddress << 4)
          + ((us12BitsValue & 0xff0) >> 4);
      }
      else
        pTmpEmbRegs->regs[usRegsCnt].sValue = (pTmpEmbRegs->regs[usRegsCnt].sValue << 4)
        + ((us12BitsValue & 0xff0) >> 4);

      if (!bIsRegAdr)
      {
        usRegsCnt++;
        pTmpEmbRegs->regs[usRegsCnt].sAddress = pTmpEmbRegs->regs[usRegsCnt-1].sAddress + 2;
        dwTempDestSize -= sizeof(SPairData);
      }

      dwTempBufferSize -= 2*sizeof(PixelAlignment);
    }
    while ( (dwTempDestSize >= sizeof(SPairData))
      && (dwTempBufferSize >= 6));

    // skipping all 0x070 filling values at the end (only for the 1st line)
    if (ubLineNo == 0)
    {
      while (us12BitsValue == 0x070)
      {
        p3Bytes++;
        us12BitsValue = p3Bytes->bytes[0] + ((p3Bytes->bytes[1] & 0xf0) << 4);
        if (us12BitsValue != 0x070)
          break;

        us12BitsValue = (p3Bytes->bytes[1] & 0x0f) + (p3Bytes->bytes[2] << 4);
        if (us12BitsValue != 0x070)
          break;

      }
    }
    else    // resetting the extra written reg line (only for the 2nd line)
      if ((ubLineNo == 1) && (ubEndOfLine >= 2))
      {
        pTmpEmbRegs->regs[usRegsCnt].sAddress = 0;
        pTmpEmbRegs->regs[usRegsCnt].sValue = 0;
        usRegsCnt--;
      }

      ubLineNo++;
  }

  return nReturnCode;
}

INT32 CConvImages::ExtractStatisticsData(void *SrcImage, void* pDestImage, uint32 dwDestSize, unsigned long ulPPortSize, SImageInfoStruct &imageInfo)
{
  LPBYTE puTempBuffer = static_cast<LPBYTE>(SrcImage);
  LPBYTE puTempDestBuffer = static_cast<LPBYTE>(pDestImage);
  DWORD dwTempBufferSize = ulPPortSize;
  DWORD dwTempDestSize = dwDestSize;

  INT32 nReturnCode = 0;
  EmbeddedStatistics * pTmpEmbStats;

  pTmpEmbStats = reinterpret_cast<EmbeddedStatistics *>(puTempDestBuffer);

  DWORD dwStatDataSize = static_cast<DWORD>(imageInfo.m_bEndInfoLines * imageInfo.m_unWidth * m_bImageUnitBytes / m_bImageUnitPixels);
  puTempBuffer = puTempBuffer + dwTempBufferSize - dwStatDataSize;
  dwTempBufferSize = dwStatDataSize;

  PixelAlignment *p3Bytes = reinterpret_cast<PixelAlignment*>(puTempBuffer);
  USHORT us12BitsValue;
  BYTE ubEndOfLine;
  BYTE ubLineNo = 0;

  USHORT usStatsCnt = 0;

  while (ubLineNo < 2)
  {
    us12BitsValue = p3Bytes->bytes[0] + ((p3Bytes->bytes[1] & 0xf0) << 4);
    if (us12BitsValue != 0x0B0)
      return 102;

    // useless word
    us12BitsValue = (p3Bytes->bytes[1] & 0x0f) + (p3Bytes->bytes[2] << 4);
    if (ubLineNo == 0)
    {
      if ((us12BitsValue >> 2) != 0x1EC)
        return 103;
    }
    else if (ubLineNo == 1)
    {
      if ((us12BitsValue >> 2) != 0x00C)
        return 103;
    }

    do
    {
      p3Bytes++;
      ubEndOfLine = 0;

      // statistics address
      if (ubLineNo == 0)
      {
        if (usStatsCnt == 0)
          pTmpEmbStats->stats[usStatsCnt].sAddress = 0x303A;
        else
          if (usStatsCnt == 1)
            pTmpEmbStats->stats[usStatsCnt].sAddress = 0x31D2;
          else
            if (usStatsCnt == 2)
              pTmpEmbStats->stats[usStatsCnt].sAddress = 0x8000;
            else
              pTmpEmbStats->stats[usStatsCnt].sAddress = pTmpEmbStats->stats[usStatsCnt-1].sAddress + 2;
      }
      else if (ubLineNo == 1)
      {
        if (usStatsCnt == 246)
          pTmpEmbStats->stats[usStatsCnt].sAddress = 0x8200;
        else
          pTmpEmbStats->stats[usStatsCnt].sAddress = pTmpEmbStats->stats[usStatsCnt-1].sAddress + 2;
      }


      // statistics value
      // MSB 10b 
      us12BitsValue = p3Bytes->bytes[0] + ((p3Bytes->bytes[1] & 0xf0) << 4);
      pTmpEmbStats->stats[usStatsCnt].sValue = (us12BitsValue >> 2);

      if (us12BitsValue == 0x070 && usStatsCnt >= sNoOfStats - 1)
        ubEndOfLine++;

      // LSB 10b 
      us12BitsValue = (p3Bytes->bytes[1] & 0x0f) + (p3Bytes->bytes[2] << 4);

      if ((usStatsCnt == 0) || (usStatsCnt == 1))    // 303A counter and 0x31D2 - 16 bits only
        pTmpEmbStats->stats[usStatsCnt].sValue = (pTmpEmbStats->stats[usStatsCnt].sValue << 8)
        + (us12BitsValue >> 2);
      else    // everything else - 20 bits long
        pTmpEmbStats->stats[usStatsCnt].sValue = (pTmpEmbStats->stats[usStatsCnt].sValue << 10)
        + (us12BitsValue >> 2);

      if (us12BitsValue == 0x070 && usStatsCnt >= sNoOfStats - 1)
        ubEndOfLine++;

      // the statistics are not yet finished
      if (ubEndOfLine < 2)
      {
        dwTempBufferSize -= sizeof(PixelAlignment);
        dwTempDestSize -= sizeof(SLongPairData);
        usStatsCnt++;
      }
      else    // resetting the last histogram value since is not valid
      {
        pTmpEmbStats->stats[usStatsCnt].sAddress = 0;
        pTmpEmbStats->stats[usStatsCnt].sValue = 0;
      }
    }
    while ( (dwTempBufferSize >= sizeof(PixelAlignment))
      && (dwTempDestSize >= sizeof(SLongPairData))
      && (ubEndOfLine < 2));

    // skip the filling word between the lines
    if (ubLineNo == 0)
    {
      while (us12BitsValue == 0x070)
      {
        p3Bytes++;

        us12BitsValue = p3Bytes->bytes[0] + ((p3Bytes->bytes[1] & 0xf0) << 4);
        if (us12BitsValue != 0x070)
          break;

        us12BitsValue = (p3Bytes->bytes[1] & 0x0f) + (p3Bytes->bytes[2] << 4);
        if (us12BitsValue != 0x070)
          break;
        dwTempBufferSize -= sizeof(PixelAlignment);
      }
    }

    ubLineNo++;
  }

  return nReturnCode;
}

template<typename Version>
int CConvImages::ConvertToGeneric(const ImageCtk::CTKImageData_t & SrcImage, typename Version::ImageU16_t*& DstImage)
{
  // allocated required memory; introduce padding so that each line starts at a RTE_LINE_START_BOUNDARY byte boundary
  unsigned int uiUnpaddedLineBytes = (sizeof(uint16) * SrcImage.bmWidth);
  unsigned int uiPaddedLineBytes = uiUnpaddedLineBytes % RTE_LINE_START_BOUNDARY == 0 ? uiUnpaddedLineBytes : ((uiUnpaddedLineBytes / RTE_LINE_START_BOUNDARY + 1) * RTE_LINE_START_BOUNDARY);
  unsigned int uiPaddedHeaderBytes = sizeof(typename Version::ImageU16_t) + RTE_LINE_START_BOUNDARY;
  int iSizeBytes = uiPaddedHeaderBytes + uiPaddedLineBytes * SrcImage.bmHeight;
  bool bAlreadyAvailable = false;
  AllocImageData<Version>(const_cast<ImageCtk::CTKImageData_t*>(&SrcImage), iSizeBytes, DstImage, bAlreadyAvailable);
  if (bAlreadyAvailable)
  {
    return DstImage->sSigHeader.eSigStatus == Version::AL_SIG_STATE_OK ? SIM_ERR_OK : SIM_ERR_UNDEFINED;
  }

  DstImage->uiVersionNumber                 = Version::IMAGE16_INTFVER;
  DstImage->sSigHeader.eSigStatus           = Version::AL_SIG_STATE_OK;
  DstImage->sSigHeader.uiCycleCounter       = 0U;
  DstImage->sSigHeader.uiMeasurementCounter = static_cast<uint16>(0);
  DstImage->sSigHeader.uiTimeStamp          = static_cast<uint16>(0);

  DstImage->sImgHeader.uiBitsPerChannel = 12U;
  DstImage->sImgHeader.iPixelBytes      = sizeof(uint16);
  DstImage->sImgHeader.iRowBytes        = uiPaddedLineBytes;
  DstImage->sImgHeader.iSizeBytes       = uiPaddedLineBytes * SrcImage.bmHeight;

  DstImage->sImgHeader.uiWidth  = SrcImage.bmWidth;
  DstImage->sImgHeader.uiHeight = SrcImage.bmHeight;

  DstImage->sImgHeader.iOffsetX = 0;
  DstImage->sImgHeader.iOffsetY = 0;
  DstImage->sImgHeader.iScaleX  = 1;
  DstImage->sImgHeader.iScaleY  = 1;

  switch (SrcImage.BayerPattern)
  {
  case CTK_IMG_BAYERNP_NONE:
    DstImage->sImgHeader.eDataFormat = ICF_GRAY;
    break;
  case CTK_IMG_BAYERNP_RGRG_GBGB:
    DstImage->sImgHeader.eDataFormat = ICF_BAYER_RGGB;
    break;
  case CTK_IMG_BAYERNP_GRGR_BGBG:
    DstImage->sImgHeader.eDataFormat = ICF_BAYER_GRBG;
    break;
  case CTK_IMG_BAYERNP_GBGB_RGRG:
    DstImage->sImgHeader.eDataFormat = ICF_BAYER_GBRG;
    break;
  case CTK_IMG_BAYERNP_BGBG_GRGR:
    DstImage->sImgHeader.eDataFormat = ICF_BAYER_BGGR;
    break;
  default:
    DstImage->sImgHeader.eDataFormat = ICF_NONE;
    break;
  }

  // set image data pointer on RTE_LINE_START_BOUNDARY byte border behind the image header
  uint8* pDestImage = reinterpret_cast<uint8*>(DstImage + 1);
  pDestImage = pDestImage + (RTE_LINE_START_BOUNDARY - (reinterpret_cast<std::ptrdiff_t>(pDestImage) % RTE_LINE_START_BOUNDARY));
  DstImage->aImageData = reinterpret_cast<const uint16*>(pDestImage);
  const uint8* pSrcImage = reinterpret_cast<const uint8*>(&SrcImage) + sizeof(ImageCtk::CTKImageData_t);
  for (int line = 0; line < SrcImage.bmHeight; ++line)
  {
    memcpy(pDestImage, pSrcImage, SrcImage.bmBytesRow);
    pSrcImage += SrcImage.bmWidth * sizeof(uint16);
    pDestImage += uiPaddedLineBytes;
  }
  return SIM_ERR_OK;
}


template<typename Version>
int CConvImages::ConvertRawToGenericWrapper(void* SrcImage, typename Version::ImageU16_t*& DstImage, unsigned long ulProvidePortSize)
{
  int ret = SIM_ERR_UNDEFINED;
  
  ret = ConvertRawToGenericWithExtractor<Version>(SrcImage, DstImage, ulProvidePortSize);

  if (ret != SIM_ERR_OK)
  {
    ret = ConvertRawToGeneric<Version>(SrcImage, DstImage, ulProvidePortSize);
  }

  return ret;
}


template<typename Version>
int CConvImages::ConvertRawToGenericWithExtractor(void* SrcImage, typename Version::ImageU16_t*& DstImage, unsigned long ulProvidePortSize)
{
  // try first to use external extractor
  static bool bErrorReported = false;
  ::MFC5XX::IMFC5xxDataExtraction* pIExtr = m_ExtractorIfcWrapper.GetExtractorInterfaceMfc5xx();
  if (pIExtr == NULL && !bErrorReported)
  {
    std::stringstream err;
    err << "External extractor not available!! Due to following error: " << m_ExtractorIfcWrapper.GetError().c_str();
    ReportError(err_sev_error, SIM_ERR_UNDEFINED, err.str().c_str());
    bErrorReported = true;
  }
  if (pIExtr == NULL)
  {
    return SIM_ERR_UNDEFINED;
  }

  SImageInfoStruct sImageInfo;
  SDataPackageEx pkg;
  ::ZeroMemory( &pkg, sizeof(SDataPackageEx) );
  ::FillMemory( pkg.rgDataTypeIndex, sizeof(pkg.rgDataTypeIndex), 0xff );
  pkg.dwCycleID = 60;
  pkg.rgDataTypeIndex[0] = 0; // data type '0' is always all
  pkg.cbData = ulProvidePortSize;
  pkg.pData = SrcImage;
  pkg.eCycleState = SDataPackageEx::cycle_body;
  uint8 ret = pIExtr->ExtractImageParameters(pkg, MFC5XX::IMAGE_DATA, sImageInfo.m_unWidth, sImageInfo.m_unHeight);
  if (ret != MFC5XX::SUCCEEDED)
  {
    std::stringstream err;
    err << "External extractor failed to provide image parameters. For size: " << ulProvidePortSize;
    ReportError(err_sev_error, SIM_ERR_UNDEFINED, err.str().c_str());
    return SIM_ERR_UNDEFINED;
  }

  // allocated required memory; NO padding as extractor does not support it yet!!!
  unsigned int uiUnpaddedLineBytes = (sizeof(uint16) * sImageInfo.m_unWidth);
  unsigned int uiPaddedLineBytes = uiUnpaddedLineBytes;
  unsigned int uiPaddedHeaderBytes = sizeof(typename Version::ImageU16_t) + RTE_LINE_START_BOUNDARY;
  int iSizeBytes = uiPaddedHeaderBytes + sizeof(uint16) * sImageInfo.m_unWidth * sImageInfo.m_unHeight;
  bool bAlreadyAvailable = false;
  AllocImageData<Version>(SrcImage, iSizeBytes, DstImage, bAlreadyAvailable);
  if (bAlreadyAvailable)
  {
    return DstImage->sSigHeader.eSigStatus == Version::AL_SIG_STATE_OK ? SIM_ERR_OK : SIM_ERR_UNDEFINED;
  }

  uint32 frameCounter;
  ret = pIExtr->GetImageFrameCounter(pkg, frameCounter);
  if (MFC5XX::SUCCEEDED != ret)
  {
    ReportError(err_sev_error, SIM_ERR_UNDEFINED, "External extractor failed to provide frame counter.");
    return SIM_ERR_UNDEFINED;
  }
  uint64 timeStamp;
  ret = pIExtr->GetImageTimestamp(pkg, timeStamp);
  if (MFC5XX::SUCCEEDED != ret)
  {
    ReportError(err_sev_error, SIM_ERR_UNDEFINED, "External extractor failed to provide image timestamp.");
    return SIM_ERR_UNDEFINED;
  }


  DstImage->uiVersionNumber                 = Version::IMAGE16_INTFVER;
  DstImage->sSigHeader.eSigStatus           = Version::AL_SIG_STATE_INVALID;
  DstImage->sSigHeader.uiCycleCounter       = frameCounter;
  DstImage->sSigHeader.uiMeasurementCounter = DstImage->sSigHeader.uiCycleCounter;
  DstImage->sSigHeader.uiTimeStamp          = timeStamp;

  DstImage->sImgHeader.uiBitsPerChannel = 12U;
  DstImage->sImgHeader.iPixelBytes      = sizeof(uint16);
  DstImage->sImgHeader.iRowBytes        = uiPaddedLineBytes;
  DstImage->sImgHeader.iSizeBytes       = uiPaddedLineBytes * sImageInfo.m_unHeight;

  DstImage->sImgHeader.uiWidth  = sImageInfo.m_unWidth;
  DstImage->sImgHeader.uiHeight = sImageInfo.m_unHeight;

  DstImage->sImgHeader.iOffsetX = 0;
  DstImage->sImgHeader.iOffsetY = 0;
  DstImage->sImgHeader.iScaleX  = 1;
  DstImage->sImgHeader.iScaleY  = 1;

  // TODO: missing information, need additional interface to get this from the extractor
  // currently set value is only true for MFC510 but not for MFC520
  DstImage->sImgHeader.eDataFormat = ICF_BAYER_GBRG;


  // get the image data
  uint8* pDestImage = reinterpret_cast<uint8*>(DstImage + 1);
  pDestImage = pDestImage + (RTE_LINE_START_BOUNDARY - (reinterpret_cast<std::ptrdiff_t>(pDestImage) % RTE_LINE_START_BOUNDARY));
  DstImage->aImageData = reinterpret_cast<const uint16*>(pDestImage);
  uint64 uiSize = DstImage->sImgHeader.iSizeBytes;
  if (MFC5XX::SUCCEEDED != pIExtr->ExtractData(pkg, pDestImage, uiSize, MFC5XX::IMAGE_DATA, MFC5XX::OUTPUT_RAW_DATA_12_UNPACKED_16))
  {
    ReportError(err_sev_error, SIM_ERR_UNDEFINED, "External extractor failed to provide image pixel data.");
    return SIM_ERR_UNDEFINED;
  }

  ReportError(err_sev_info, SIM_ERR_UNDEFINED, "Image conversion with external extractor succeeded.");

  // everything fine so far ... set image to be valid
  DstImage->sSigHeader.eSigStatus = Version::AL_SIG_STATE_OK;
  return SIM_ERR_OK;
}


template<typename Version>
int CConvImages::ConvertRawToGeneric(void* SrcImage, typename Version::ImageU16_t*& DstImage, unsigned long ulProvidePortSize)
{
  sint32 si32Result;
  SImageInfoStruct sImageInfo;
  si32Result = GetImageParameter(ulProvidePortSize, sImageInfo);
  if(si32Result != SIM_ERR_OK)
  {
    std::stringstream err;
    err << "Image Converter: No Image Parameter available for ProvidePortSize" << ulProvidePortSize;
    ReportError(err_sev_error, SIM_ERR_UNDEFINED, err.str().c_str());
    return si32Result;
  }

  // allocated required memory; introduce padding so that each line starts at a RTE_LINE_START_BOUNDARY byte boundary
  unsigned int uiUnpaddedLineBytes = (sizeof(uint16) * sImageInfo.m_unWidth);
  unsigned int uiPaddedLineBytes = uiUnpaddedLineBytes % RTE_LINE_START_BOUNDARY == 0 ? uiUnpaddedLineBytes : ((uiUnpaddedLineBytes / RTE_LINE_START_BOUNDARY + 1) * RTE_LINE_START_BOUNDARY);
  unsigned int uiPaddedHeaderBytes = sizeof(typename Version::ImageU16_t) + RTE_LINE_START_BOUNDARY;
  int iSizeBytes = uiPaddedHeaderBytes + uiPaddedLineBytes * sImageInfo.m_unHeight;
  bool bAlreadyAvailable = false;
  AllocImageData<Version>(SrcImage, iSizeBytes, DstImage, bAlreadyAvailable);
  if (bAlreadyAvailable)
  {
    return DstImage->sSigHeader.eSigStatus == Version::AL_SIG_STATE_OK ? SIM_ERR_OK : SIM_ERR_UNDEFINED;
  }

  MFCEmbeddedData pEmbeddedData;
  DWORD dwSize = sizeof(pEmbeddedData.embeddedRegs);
  PVOID pRegs = &pEmbeddedData.embeddedRegs;
  uint32 retVal = ExtractEmbeddedData(SrcImage, pRegs, dwSize, ulProvidePortSize, sImageInfo);

  if (retVal <= 1)
  {
    unsigned __int64 qiValue0 = 0, qiValue1 = 0, qiValue2 = 0, qiValue3 = 0;
    unsigned short version = 0;
    // extract 64 bit ECU timestamp
    for (USHORT index = 0; index < sNoOfRegs; ++index)
    {
      SPairData& reg = pEmbeddedData.embeddedRegs.regs[index];
      switch (reg.sAddress)
      {
      case 0x3102:
        qiValue0 = reg.sValue;
        continue; // no need to search anymore
      case 0x3104:
        qiValue1 = reg.sValue;
        continue; // no need to search anymore
      case 0x310C:
        qiValue2 = reg.sValue;
        continue; // no need to search anymore
      case 0x310E:
        qiValue3 = reg.sValue;
        continue; // no need to search anymore
      case 0x310A:
        version = reg.sValue;
        continue; // no need to search anymore
      }
    }

    // the version number is only 8 bit long and is found in the lower 8 bits of the register
    // the old default value of the register is 0x02 the version number now starts with 0x10 from MFC release 92.04.70
    if ((version & 0x00FF ) >= 0x0010)
    {
      // combine the 4 register values
      DstImage->sSigHeader.uiTimeStamp = static_cast<uint32>((qiValue0 << 0) | (qiValue1 << 16) | (qiValue2 << 32) | (qiValue3 << 48));
    }
    else
    {
      DstImage->sSigHeader.uiTimeStamp = 0;
    }

    //get embedded statistics
    dwSize = sizeof(pEmbeddedData.embeddedStats);
    PVOID pStats = &pEmbeddedData.embeddedStats;
    retVal = ExtractStatisticsData(SrcImage, pStats, dwSize, ulProvidePortSize, sImageInfo);
    if (retVal <= 1)
    {
      // set image frame counter -> present in statistic register with address 0x303A
      for (USHORT index = 0; index < sNoOfStats; ++index)
      {
        if (pEmbeddedData.embeddedStats.stats[index].sAddress == 0x303A)
        {
          DstImage->sSigHeader.uiCycleCounter = static_cast<uint16>(pEmbeddedData.embeddedStats.stats[index].sValue);
          break;
        }
      }
    }
  }


  DstImage->uiVersionNumber  = Version::IMAGE16_INTFVER;
  DstImage->sSigHeader.eSigStatus           = Version::AL_SIG_STATE_INVALID;
  DstImage->sSigHeader.uiMeasurementCounter = DstImage->sSigHeader.uiCycleCounter;

  DstImage->sImgHeader.uiBitsPerChannel = 12U;
  DstImage->sImgHeader.iPixelBytes      = sizeof(uint16);
  DstImage->sImgHeader.iRowBytes        = uiPaddedLineBytes;
  DstImage->sImgHeader.iSizeBytes       = uiPaddedLineBytes * sImageInfo.m_unHeight;

  DstImage->sImgHeader.uiWidth  = sImageInfo.m_unWidth;
  DstImage->sImgHeader.uiHeight = sImageInfo.m_unHeight;

  DstImage->sImgHeader.iOffsetX = 0;
  DstImage->sImgHeader.iOffsetY = 0;
  DstImage->sImgHeader.iScaleX  = 1;
  DstImage->sImgHeader.iScaleY  = 1;

  DstImage->sImgHeader.eDataFormat = ICF_BAYER_GBRG;

  // set image data pointer on RTE_LINE_START_BOUNDARY byte border behind the image header
  uint8* pDestImage = reinterpret_cast<uint8*>(DstImage + 1);
  pDestImage = pDestImage + (RTE_LINE_START_BOUNDARY - (reinterpret_cast<std::ptrdiff_t>(pDestImage) % RTE_LINE_START_BOUNDARY));
  DstImage->aImageData = reinterpret_cast<const uint16*>(pDestImage);

  int iResult = GetImageData(SrcImage, pDestImage, uiPaddedLineBytes, DstImage->sImgHeader.iSizeBytes, ulProvidePortSize, sImageInfo);
  if (iResult == SIM_ERR_OK)
  {
    DstImage->sSigHeader.eSigStatus = Version::AL_SIG_STATE_OK;
  }
  return iResult;
}


int CConvImages::ConvertToV1(const ImageCtk::CTKImageData_t & SrcImage, ImagesV1::ImageU16_t*& DstImage)
{
  sint32 iResult = ConvertToGeneric<ImagesV1>(SrcImage, DstImage);

  return iResult;
}

int CConvImages::ConvertRawToV1(void* SrcImage, ImagesV1::ImageU16_t*& DstImage, unsigned long ulProvidePortSize)
{
  sint32 iResult = ConvertRawToGenericWrapper<ImagesV1>(SrcImage, DstImage, ulProvidePortSize);

  return iResult;
}


int CConvImages::ConvertToV2(const ImageCtk::CTKImageData_t & SrcImage, ImagesV2::ImageU16_t*& DstImage)
{
  sint32 iResult = ConvertToGeneric<ImagesV2>(SrcImage, DstImage);

  if (iResult == SIM_ERR_OK)
  {
    DstImage->sImgHeader.uiParameterId = 0;
  }

  return iResult;
}

int CConvImages::ConvertRawToV2(void* SrcImage, ImagesV2::ImageU16_t*& DstImage, unsigned long ulProvidePortSize)
{
  sint32 iResult = ConvertRawToGenericWrapper<ImagesV2>(SrcImage, DstImage, ulProvidePortSize);

  if (iResult == SIM_ERR_OK)
  {
    DstImage->sImgHeader.uiParameterId = 0;
  }

  return iResult;
}

int CConvImages::ConvertToV3(const ImageCtk::CTKImageData_t & SrcImage, ImagesV3::ImageU16_t*& DstImage)
{
  sint32 iResult = ConvertToGeneric<ImagesV3>(SrcImage, DstImage);

  if (iResult == SIM_ERR_OK)
  {
    DstImage->sImgHeader.uiParameterId = 0;
    ifp::CImageFingerPrint::getInstance().ComputeImageFingerPrint_ui16<ImagesV3>(DstImage);
  }

  return iResult;
}

int CConvImages::ConvertRawToV3(void* SrcImage, ImagesV3::ImageU16_t*& DstImage, unsigned long ulProvidePortSize)
{
  sint32 iResult = ConvertRawToGenericWrapper<ImagesV3>(SrcImage, DstImage, ulProvidePortSize);

  if (iResult == SIM_ERR_OK)
  {
    DstImage->sImgHeader.uiParameterId = 0;
    ifp::CImageFingerPrint::getInstance().ComputeImageFingerPrint_ui16<ImagesV3>(DstImage);
  }

  return iResult;
}

int CConvImages::ConvertToV4(const ImageCtk::CTKImageData_t & SrcImage, ImagesV4::ImageU16_t*& DstImage)
{
  sint32 iResult = ConvertToGeneric<ImagesV4>(SrcImage, DstImage);

  if (iResult == SIM_ERR_OK)
  {
    ifp::CImageFingerPrint::getInstance().ComputeImageFingerPrint_ui16<ImagesV4>(DstImage);
    DstImage->sImgHeader.sIntrinsics.fCenterX = 0.0f;
    DstImage->sImgHeader.sIntrinsics.fCenterY = 0.0f;
    DstImage->sImgHeader.sIntrinsics.fFocalX = 0.0f;
    DstImage->sImgHeader.sIntrinsics.fFocalY = 0.0f;
    DstImage->sImgHeader.sIntrinsics.eCameraType = ImagesV4::CAMERA_TYPE_UNKNOWN;
  }

  return iResult;
}

int CConvImages::ConvertRawToV4(void* SrcImage, ImagesV4::ImageU16_t*& DstImage, unsigned long ulProvidePortSize)
{
  sint32 iResult = ConvertRawToGenericWrapper<ImagesV4>(SrcImage, DstImage, ulProvidePortSize);

  if (iResult == SIM_ERR_OK)
  {
    ifp::CImageFingerPrint::getInstance().ComputeImageFingerPrint_ui16<ImagesV4>(DstImage);
    DstImage->sImgHeader.sIntrinsics.fCenterX = 0.0f;
    DstImage->sImgHeader.sIntrinsics.fCenterY = 0.0f;
    DstImage->sImgHeader.sIntrinsics.fFocalX = 0.0f;
    DstImage->sImgHeader.sIntrinsics.fFocalY = 0.0f;
    DstImage->sImgHeader.sIntrinsics.eCameraType = ImagesV4::CAMERA_TYPE_UNKNOWN;
  }

  return iResult;
}

long CConvImages::ConvertData(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo, 
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo* pProvidePortVersionInfo, 
    void* pPPortData,
    void** pOutData, unsigned long& ulOutSize)
{
  long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;

  if ( ( ((ePPortType == simOPAQUE_t) && (ulPPortSize > 4)) || (ePPortType == simREFERENCE_t) ) && (pPPortData != NULL))
  {
    const uint32 input_raw_ver = GetImageInterfaceVersion(ePPortType,ulPPortSize,pPPortData);

    const CVersionInfoImpl ProvidePortVersionInfo(CONV_I32VERSION_TO_TUPPLE(input_raw_ver));


    // First check for complete match of request/provide port. Always accept this as direct match
    // only start evaluating data if no direct copy possible
    if (((pProvidePortVersionInfo == NULL) || (requestPortVersionInfo.Equals(pProvidePortVersionInfo)) || (requestPortVersionInfo.Equals(&BASE_VERSION)) )
      && (ProvidePortVersionInfo.Equals(&requestPortVersionInfo)))
    {
      // Port types sizes and versions match, we can directly use the input data
      *pOutData = pPPortData;
      ulOutSize = ulPPortSize;
      lRet = SIM_ERR_OK;
    }
    else
    {
      // First level branches identify destination buffer version (request port)
      if (requestPortVersionInfo.Equals(CConvImages::SupportedVersions[IMAGES_V1].pVersion) || requestPortVersionInfo.Equals(&BASE_VERSION))
      {
        // first check for ctk image
        const ImageCtk::CTKImageData_t & CtkImageData = *reinterpret_cast<const ImageCtk::CTKImageData_t*>(pPPortData);
        if (CtkImageData.HeaderSize == sizeof(ImageCtk::CTKImageData_t) && CtkImageData.bmSize == CtkImageData.bmHeight * CtkImageData.bmWidth * sizeof(uint16) && ulPPortSize == CtkImageData.bmSize + sizeof(ImageCtk::CTKImageData_t))
        {
          if (ConvertToV1(CtkImageData, *reinterpret_cast<ImagesV1::ImageU16_t**>(pOutData)) == SIM_ERR_OK)
          {
            ulOutSize = sizeof(ImagesV1::ImageU16_t) + (*reinterpret_cast<ImagesV1::ImageU16_t**>(pOutData))->sImgHeader.iSizeBytes;
            lRet = SIM_ERR_OK;
          }
        }
        // check for raw data image
        else if(ConvertRawToV1(pPPortData, *reinterpret_cast<ImagesV1::ImageU16_t**>(pOutData), ulPPortSize) == SIM_ERR_OK)
        {
          ulOutSize = sizeof(ImagesV1::ImageU16_t) + (*reinterpret_cast<ImagesV1::ImageU16_t**>(pOutData))->sImgHeader.iSizeBytes;
          lRet = SIM_ERR_OK;
        }
      }
      else if (requestPortVersionInfo.Equals(CConvImages::SupportedVersions[IMAGES_V2].pVersion) || requestPortVersionInfo.Equals(&BASE_VERSION))
      {
        // first check for ctk image
        const ImageCtk::CTKImageData_t & CtkImageData = *reinterpret_cast<const ImageCtk::CTKImageData_t*>(pPPortData);
        if (CtkImageData.HeaderSize == sizeof(ImageCtk::CTKImageData_t) && CtkImageData.bmSize == CtkImageData.bmHeight * CtkImageData.bmWidth * sizeof(uint16) && ulPPortSize == CtkImageData.bmSize + sizeof(ImageCtk::CTKImageData_t))
        {
          if (ConvertToV2(CtkImageData, *reinterpret_cast<ImagesV2::ImageU16_t**>(pOutData)) == SIM_ERR_OK)
          {
            ulOutSize = sizeof(ImagesV2::ImageU16_t) + (*reinterpret_cast<ImagesV2::ImageU16_t**>(pOutData))->sImgHeader.iSizeBytes;
            lRet = SIM_ERR_OK;
          }
        }
        // check for raw data image
        else if(ConvertRawToV2(pPPortData, *reinterpret_cast<ImagesV2::ImageU16_t**>(pOutData), ulPPortSize) == SIM_ERR_OK)
        {
          ulOutSize = sizeof(ImagesV2::ImageU16_t) + (*reinterpret_cast<ImagesV2::ImageU16_t**>(pOutData))->sImgHeader.iSizeBytes;
          lRet = SIM_ERR_OK;
        }
      }
      else if (requestPortVersionInfo.Equals(CConvImages::SupportedVersions[IMAGES_V3].pVersion) || requestPortVersionInfo.Equals(&BASE_VERSION))
      {
        // first check for ctk image
        const ImageCtk::CTKImageData_t & CtkImageData = *reinterpret_cast<const ImageCtk::CTKImageData_t*>(pPPortData);
        if (CtkImageData.HeaderSize == sizeof(ImageCtk::CTKImageData_t) && CtkImageData.bmSize == CtkImageData.bmHeight * CtkImageData.bmWidth * sizeof(uint16) && ulPPortSize == CtkImageData.bmSize + sizeof(ImageCtk::CTKImageData_t))
        {
          if (ConvertToV3(CtkImageData, *reinterpret_cast<ImagesV3::ImageU16_t**>(pOutData)) == SIM_ERR_OK)
          {
            ulOutSize = sizeof(ImagesV3::ImageU16_t) + (*reinterpret_cast<ImagesV3::ImageU16_t**>(pOutData))->sImgHeader.iSizeBytes;
            lRet = SIM_ERR_OK;
          }
        }
        // check for raw data image
        else if(ConvertRawToV3(pPPortData, *reinterpret_cast<ImagesV3::ImageU16_t**>(pOutData), ulPPortSize) == SIM_ERR_OK)
        {
          ulOutSize = sizeof(ImagesV3::ImageU16_t) + (*reinterpret_cast<ImagesV3::ImageU16_t**>(pOutData))->sImgHeader.iSizeBytes;
          lRet = SIM_ERR_OK;
        }
      }
      else if (requestPortVersionInfo.Equals(CConvImages::SupportedVersions[IMAGES_V4].pVersion) || requestPortVersionInfo.Equals(&BASE_VERSION))
      {
        // first check for ctk image
        const ImageCtk::CTKImageData_t & CtkImageData = *reinterpret_cast<const ImageCtk::CTKImageData_t*>(pPPortData);
        if (CtkImageData.HeaderSize == sizeof(ImageCtk::CTKImageData_t) && CtkImageData.bmSize == CtkImageData.bmHeight * CtkImageData.bmWidth * sizeof(uint16) && ulPPortSize == CtkImageData.bmSize + sizeof(ImageCtk::CTKImageData_t))
        {
          if (ConvertToV4(CtkImageData, *reinterpret_cast<ImagesV4::ImageU16_t**>(pOutData)) == SIM_ERR_OK)
          {
            ulOutSize = sizeof(ImagesV4::ImageU16_t) + (*reinterpret_cast<ImagesV4::ImageU16_t**>(pOutData))->sImgHeader.iSizeBytes;
            lRet = SIM_ERR_OK;
          }
        }
        // check for raw data image
        else if(ConvertRawToV4(pPPortData, *reinterpret_cast<ImagesV4::ImageU16_t**>(pOutData), ulPPortSize) == SIM_ERR_OK)
        {
          ulOutSize = sizeof(ImagesV4::ImageU16_t) + (*reinterpret_cast<ImagesV4::ImageU16_t**>(pOutData))->sImgHeader.iSizeBytes;
          lRet = SIM_ERR_OK;
        }
      }
    }
  }
  else
  {
    lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  }
  return lRet;
}

/** returns: 
 *   SIM_ERR_OK - when this value can be used
 *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implememnted here
 *                                            and the default value from Request Port must be used
 */
long CConvImages::GetDefaultValue(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo, 
    void** pDefaultData, unsigned long& ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;

  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == CConvImages::SupportedVersions[IMAGES_V1].uiSize) && (requestPortVersionInfo.Equals(CConvImages::SupportedVersions[IMAGES_V1].pVersion) || requestPortVersionInfo.Equals(&BASE_VERSION)))
    {
      *pDefaultData = &m_ImagesV1;
      ulDefaultSize = sizeof(m_ImagesV1);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == CConvImages::SupportedVersions[IMAGES_V2].uiSize) && (requestPortVersionInfo.Equals(CConvImages::SupportedVersions[IMAGES_V2].pVersion)))
    {
      *pDefaultData = &m_ImagesV2;
      ulDefaultSize = sizeof(m_ImagesV2);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == CConvImages::SupportedVersions[IMAGES_V3].uiSize) && (requestPortVersionInfo.Equals(CConvImages::SupportedVersions[IMAGES_V3].pVersion)))
    {
      *pDefaultData = &m_ImagesV3;
      ulDefaultSize = sizeof(m_ImagesV3);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == CConvImages::SupportedVersions[IMAGES_V4].uiSize) && (requestPortVersionInfo.Equals(CConvImages::SupportedVersions[IMAGES_V4].pVersion)))
    {
      *pDefaultData = &m_ImagesV4;
      ulDefaultSize = sizeof(m_ImagesV4);
      lRet = SIM_ERR_OK;
    }
  }
  return lRet;
}

// used to check if an unversioned PPort is compatible with a certain version of RPort
bool CConvImages::IsVersionCompatibleWithType(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo, 
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize)
{
  bool bResult = false;
  // Always allow same type/size ports to be bound together
  if ((eRPortType == ePPortType) && (ulRPortSize == ulPPortSize))
  {
    bResult = true;
  }
  else
  {
    bResult = (PortSupported(eRPortType, ulRPortSize, &requestPortVersionInfo) && PortSupported(ePPortType, ulPPortSize));
  }
  return bResult;
}

// used to check if ports are compatible between different versions
bool CConvImages::AreVersionsCompatible(
                                        SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
                                        SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo& providePortVersionInfo)
{
  bool bResult = false;
  // Always allow same type/size ports to be bound together
  if ((eRPortType == ePPortType) && (ulRPortSize == ulPPortSize) && (providePortVersionInfo.Equals(&requestPortVersionInfo)))
  {
    bResult = true;
  }
  else
  {
    // Ports are different: conversion necessary and possible if provide & request port known
    bResult = (PortSupported(eRPortType, ulRPortSize, &requestPortVersionInfo) && PortSupported(ePPortType, ulPPortSize, &providePortVersionInfo));
  }
  return bResult;
}


