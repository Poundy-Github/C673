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


#include <cstring>
#include <cassert>

namespace ifp
{
  class CImageFingerPrint
  {
  private:
    CImageFingerPrint()
    {}

  public:
    ~CImageFingerPrint(){}
    
    /// gives the one and only instance of the service types handler. singleton pattern.
    /// \return the reference to the instance of the class
    static CImageFingerPrint& getInstance()
    {
      // use non default constructor to bypass deprecated warning
      static CImageFingerPrint instance;
      return instance;
    }

    template<typename Version>
    void ComputeImageFingerPrint_ui16(typename Version::ImageU16_t * const image)
    {
      uint32 ui32_fingerprint = 0;
      if ( (image != NULL) && (image->sSigHeader.eSigStatus == Version::AL_SIG_STATE_OK) )
      {
        uint8 *charImgPtr = (uint8*) image->aImageData;
        v_ImageFingerPrintGeneration( charImgPtr,
          image->sImgHeader.uiWidth,
          image->sImgHeader.uiHeight,
          image->sImgHeader.iPixelBytes,
          image->sImgHeader.iRowBytes,
          &ui32_fingerprint);
        image->sImgHeader.uiFingerprint = ui32_fingerprint;
      }
    }

  private:
    uint32 MurmurHashAligned2 ( const uint8 * key, sint32 len, uint32 seed );
    
    void v_ImageFingerPrintGeneration(const uint8*  const charImgPtr,
                                      const uint16        width,
                                      const uint16        height,
                                      const sint16        iPixelBytes,
                                      const sint32        iRowBytes,
                                            uint32*       ui32_fingerprint);
  };
}

    
#endif // __IMAGE_FINGER_PRINT__
