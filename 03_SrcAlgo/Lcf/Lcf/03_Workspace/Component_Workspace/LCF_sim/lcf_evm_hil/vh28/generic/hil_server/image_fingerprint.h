/*-------------------------------------------------------------------------
 |
 |  File Name   :  $Source: image_fingerprint.h $
 |
 | ------------------------------------------------------------------------
 |
 |  COPYRIGHT (C) Continental Automotive AG 2008
 |  ALLE RECHTE VORBEHALTEN. ALL RIGHTS RESERVED.
 |
 |   The  reproduction,  transmission or  use  of  this  document or  its
 |   contents  is  not   permitted  without  express  written  authority.
 |   Offenders will  be liable for damages. All  rights, including rights
 |   created  by patent  grant  or  registration of  a  utility model  or
 |   design, are reserved.
 |
 | ------------------------------------------------------------------------
 |
 |  Description : Compute and check image finger print 
 |                (cf Fusi Checks Requirement MFC400_L3_CIPP_162).
 |
 |  $Revision: 1.1 $
 |              
 +-------------------------------------------------------------------------*/

#ifndef __IMAGE_FINGER_PRINT__
#define __IMAGE_FINGER_PRINT__

#define IFP_ALIGNMENT             16     // in Bytes (=128 bits / 8)
#define IFP_SAMPLE_COL_NUMBER     10
#define IFP_SAMPLE_ROW_NUMBER     1  
#define IFP_MBD_RINGBUFFER_SIZE   5


#include "algo_glob.h"
#include <cstring>
#include <cassert>

namespace ifp
{
  class CImageFingerPrint
  {
  public:
    CImageFingerPrint()
    {}
     
  private:
    CImageFingerPrint(int)
    {}

  public:
    ~CImageFingerPrint(){}
    
    /// gives the one and only instance of the service types handler. singleton pattern.
    /// \return the reference to the instance of the class
    static CImageFingerPrint& getInstance()
    {
      // use non default constructor to bypass deprecated warning
      static CImageFingerPrint instance(1);
      return instance;
    }

    void    ComputeImageFingerPrint_ui16(ImageU16_t * const image);
    void    ComputeImageFingerPrint_ui8(ImageU8_t * const image);
    void    ComputeImageFingerPrint_DisparityImage(DisparityImage_t * const image);
    void    ComputeImageFingerPrint_FlowImage(FlowImage_t * const image);

    uint8   CheckImageFingerPrintValidity_ui16(const ImageU16_t * const image);
    uint8   CheckImageFingerPrintValidity_ui8(const ImageU8_t * const image);
    uint8   CheckImageFingerPrintValidity_DisparityImage(const DisparityImage_t * const image);
    uint8   CheckImageFingerPrintValidity_FlowImage(const FlowImage_t * const image);

  private:
    uint32 MurmurHashAligned2 ( const uint8 * key, sint32 len, uint32 seed );

    void v_ImageFingerPrintGeneration(const uint8 * const charImgPtr, 
                                      const ImageHeader_t &sImgHeader,
                                            uint32* ui32_fingerprint);
  };
}

    
#endif // __IMAGE_FINGER_PRINT__
