#include "image_fingerprint.h"

// PRQA S 1021 EOF
// 2020-2-5; uic58113
// summary < Msg(3:1021) This macro is replaced with a literal.>
// reason < Need to use RTE defines hence macros are replaced by literals.>

#include <cassert>
#include <cstring>
#include <cstddef>
#include <limits>

namespace ifp
{
  template <uint32 M, uint32 R>
  static inline void mix(uint32& h, uint32& k)
  {
    // polyspace-begin RTE:OVFL [Justified:Low] "That is a hash function. Integer overflows do not matter here"
    k *= M;
    k ^= k >> R;
    k *= M;
    h *= M;
    h ^= k;
    // polyspace-end RTE:OVFL [Justified:Low]
  }

  /// Same algorithm as MurmurHash2, but only does aligned reads,
  /// that should be safer on certain platforms. Performance will
  /// be lower than MurmurHash2.
  ///
  /// @copyright
  /// > All code is released to the public domain.
  /// > For business purposes, Murmurhash is under the MIT license:
  /// > The MIT License (MIT)
  /// >
  /// > Permission is hereby granted, free of charge, to any person obtaining a copy
  /// > of this software and associated documentation files (the "Software"), to deal
  /// > in the Software without restriction, including without limitation the rights
  /// > to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  /// > copies of the Software, and to permit persons to whom the Software is
  /// > furnished to do so, subject to the following conditions:
  /// >
  /// > The above copyright notice and this permission notice shall be included in
  /// > all copies or substantial portions of the Software.
  /// >
  /// > THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  /// > IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  /// > FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  /// > AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  /// > LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  /// > OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  /// > THE SOFTWARE.
  ///
  /// @author         Austin Appleby
  /// @tparam    SIZE Size in bytes of @a key
  /// @param[in] key  Data array to hash.
  /// @param[in] seed Seed to use for hashing
  /// @return         Hash of key.
  template <sint32 SIZE>
  static uint32 murmurHashAligned2 (const uint8 (&key)[SIZE], const uint32 seed)
  {
    enum { R = 24 };
    static const uint32 M = 0x5bd1e995;

    sint32 idx = 0;
    sint32 len = SIZE;

    uint32 k;
    uint32 h = seed ^ len;

    // polyspace +1 RTE:ASRT [Not a defect: Low] "Asserts are called in debug mode and will not part of ECU code"
    assert(((static_cast<sint32>(reinterpret_cast<std::ptrdiff_t>(&key[0])) % 4) == 0) && "Address must be a multiple of 4");

    while (len >= 4)
    {
      {
        const uint32* uiPointer = reinterpret_cast<const uint32*>(&key[idx]);
        k = *uiPointer;
      }

      mix<M, R>(h, k);

      idx += 4;
      len -= 4;
    }

    h ^= h >> 13;
    h *= M;
    h ^= h >> 15;

    return h;
  }

  /// Generates an image finger print hash.
  /// @param[in] charImgPtr Pointer to image data casted to uint8*
  /// @param[in] sImgHeader Input image header
  /// @return               The computed fingerprint hash
  static uint32 imageFingerPrintGeneration(const uint8* const charImgPtr, const ImageHeader_t& sImgHeader)
  {
    sint32 widthRatio;
    uint16 sampleColNumberRatio;
    uint16 colShift2;
    uint16 colShift3;
    uint16 rowShift1;
    uint16 rowShift2;
    uint16 rowShift3;
    uint16 rowShift4;
    // polyspace +1 RTE:NIV [Not a defect: Low] "Varible separately  initilized using memset."
    uint8 data[4 * CImageFingerPrint::SAMPLE_COL_NUMBER * 4];    // 4 is the maximum for iPixelBytes
    uint8 i;
    uint8 j;

    // Adaptation for SRLCam different PixelBytes in FlowElement
    // polyspace +1 RTE:OVFL [Not a defect: Low] "Maximum value for iPixelBytes is 4 "
    const uint16 iPixelBytes = sImgHeader.iPixelBytes;
    const uint16 width       = sImgHeader.uiWidth;
    const uint16 height      = sImgHeader.uiHeight;
    const sint32 iRowBytes   = sImgHeader.iRowBytes;
    // polyspace +1 RTE:OVFL [Not a defect: Low] "Maximum value for iPixelBytes is 4 and SAMPLE_COL_NUMBER is 10.Assigning values are with in the range of  uin16."
    sampleColNumberRatio     = CImageFingerPrint::SAMPLE_COL_NUMBER * iPixelBytes;
    widthRatio               = iRowBytes;

    std::memset(&data[0], 0, 4 * CImageFingerPrint::SAMPLE_COL_NUMBER * 4 * sizeof(uint8));

    // polyspace +1 RTE:ASRT [Not a defect: Low] "Asserts used for detecting faults. Analyzed in SIL"
    assert( widthRatio < static_cast<sint32>( std::numeric_limits<uint16>::max() ) );
    // polyspace +1 RTE:OVFL [Not a defect: Low] "Overflow happens if iPixelBytes exceeds the limit.currently not a problem, already handled before reaching the function"
    colShift2 = ((width*iPixelBytes) - sampleColNumberRatio)/2; // Take pixels middle of row
    colShift2 -= colShift2%CImageFingerPrint::ALIGNMENT;        // Alignment to 128
    // polyspace +1 RTE:OVFL [Not a defect: Low] "Overflow happens if iPixelBytes exceeds the limit.currently not a problem, already handled before reaching the function"
    colShift3 = ((width*iPixelBytes) - sampleColNumberRatio);   // Take pixels end of row
    colShift3 -= colShift3%CImageFingerPrint::ALIGNMENT;        // Alignment to 128

    rowShift1 = 0;                                             // Take pixels begin of 2nd line
    rowShift2 = height/2;                                      // Take pixels middle of image
    rowShift3 = 3*height/4;                                    // Take pixels middle of image
    // polyspace +1 RTE:OVFL [Not a defect: Low] "Defined value for SAMPLE_ROW_NUMBER is 1 and ensures assigning values are with in the range of uin16."
    rowShift4 = height-4-CImageFingerPrint::SAMPLE_ROW_NUMBER; // Take pixels end of image

    for (i=1; i<=CImageFingerPrint::SAMPLE_ROW_NUMBER; i++)
    {
      const sint32 idx11 =  (i + rowShift1) * widthRatio;
      // polyspace-begin RTE:OVFL [Not a defect: Low] "Overflow happens for iRowBytes exceeds the limit, already handled before reaching the function."
      const sint32 idx21 = ((i + rowShift2) * widthRatio) + colShift2;
      const sint32 idx31 =  (i + rowShift3) * widthRatio;
      const sint32 idx41 = ((i + rowShift4) * widthRatio) + colShift3;
      // polyspace-end RTE:OVFL [Not a defect: Low]

      for (j=0; j<sampleColNumberRatio; j++)
      {
        // polyspace-begin RTE:IDP [Not a defect: Low] "Validity of charImgPtr is ensured from the outside. See ComputeImageFingerPrint() and CheckImageFingerPrintValidity()."
        // polyspace-begin RTE:OBAI [To fix: Low] "data[] will be written out of bounds for iPixelBytes > 4, currently not a problem."
        // polyspace-begin RTE:NIV [To fix: Low] "Variable initialization ensured before the function call."

        // PRQA S 3706 6
        // date: 2015-17-07, reviewer: Christian Exner
        // reason: We only have a dynamic data interface so that the access to the data has to be made by pointer subscript.
        data[j                           ]  = charImgPtr[idx11 + j];
        data[j +     sampleColNumberRatio]  = charImgPtr[idx21 + j];
        // polyspace-begin RTE:OVFL [Not a defect: Low] "Overflow happens for iRowBytes exceeds the limit, already handled before reaching the function."
        data[j + 2 * sampleColNumberRatio]  = charImgPtr[idx31 + j];
        data[j + 3 * sampleColNumberRatio]  = charImgPtr[idx41 + j];

        // polyspace-end RTE:OBAI [To fix: Low]
        // polyspace-end RTE:IDP [Not a defect: Low]
        // polyspace-end RTE:NIV [Not a defect: Low]
        // polyspace-end RTE:OVFL [Not a defect: Low]
      }
    }

    return murmurHashAligned2<160>(data, 464);
  }

#ifdef IMAGE8_INTFVER
  /// Converter method for ImageU8_t data pointer to a byte pointer.
  /// @param[in] img Image reference the byte pointer should be extracted from.
  /// @return        Byte pointer to image data.
  static inline const uint8* imageBytePointer(const ImageU8_t& img)
  {
    return img.aImageData;
  }
#endif

#ifdef IMAGE16_INTFVER
  /// Converter method for ImageU16_t data pointer to a byte pointer.
  /// @param[in] img Image reference the byte pointer should be extracted from.
  /// @return        Byte pointer to image data.
  static inline const uint8* imageBytePointer(const ImageU16_t& img)
  {
    return reinterpret_cast<const uint8*>(img.aImageData);
  }
#endif

#ifdef DISPARITY_IMAGE_INTFVER
  /// Converter method for DisparityImage_t data pointer to a byte pointer.
  /// @param[in] img Image reference the byte pointer should be extracted from.
  /// @return        Byte pointer to image data.
  static inline const uint8* imageBytePointer(const DisparityImage_t& img)
  {
    return reinterpret_cast<const uint8*>(img.pDisparityData);
  }
#endif

#ifdef FLOW_IMAGE_INTFVER
  /// Converter method for FlowImage_t data pointer to a byte pointer.
  /// @param[in] img Image reference the byte pointer should be extracted from.
  /// @return        Byte pointer to image data.
  static inline const uint8* imageBytePointer(const FlowImage_t& img)
  {
    return reinterpret_cast<const uint8*>(img.pFlowData);
  }
#endif

#ifdef PFC_SIGNATUREIMAGE_INTFVER
  static inline const uint8* imageBytePointer(const PFC_SignatureImage_t& img)
  {
#if PFC_SIGNATUREIMAGE_INTFVER < 2
    return reinterpret_cast<const uint8*>(img.aImageData);
#else
    return reinterpret_cast<const uint8*>(img.pSignatureData);
#endif
  }
#endif

#ifdef GRAPPA_SEMSEG_INTFVER
  /// Converter method for GrappaSemSeg_t data pointer to a byte pointer.
  /// @param[in] img Image reference the byte pointer should be extracted from.
  /// @return        Byte pointer to image data.
  static inline const uint8* imageBytePointer(const GrappaSemSeg_t& img)
  {
    return reinterpret_cast<const uint8*>(img.pSemSegData);
  }
#endif

  template <typename I>
  static inline void computeImageFingerPrint(I* const image)
  {
    if ( (image != NULL)
      && (image->sSigHeader.eSigStatus == AL_SIG_STATE_OK) )
    {
      image->sImgHeader.uiFingerprint = imageFingerPrintGeneration(imageBytePointer(*image), image->sImgHeader);
    }
  }

  template <typename I>
  static inline uint8 checkImageFingerPrintValidity(const I* const image)
  {
    uint8 returnCode;

    if ( (image == NULL)
      || (image->sSigHeader.eSigStatus != AL_SIG_STATE_OK) )
    {
      returnCode = 2;
    }
    else
    {
      const uint32 fingerprint = imageFingerPrintGeneration(imageBytePointer(*image), image->sImgHeader);

      if ( image->sImgHeader.uiFingerprint != fingerprint )
      {
        returnCode = 0;
      }
      else
      {
        returnCode = 1;
      }
    }

    return returnCode;
  }
}

#ifdef IMAGE8_INTFVER
void ifp::CImageFingerPrint::ComputeImageFingerPrint( ImageU8_t*            const image ) { ifp::computeImageFingerPrint(image); }
#endif
#ifdef IMAGE16_INTFVER
void ifp::CImageFingerPrint::ComputeImageFingerPrint( ImageU16_t*           const image ) { ifp::computeImageFingerPrint(image); }
#endif
#ifdef FLOW_IMAGE_INTFVER
void ifp::CImageFingerPrint::ComputeImageFingerPrint( FlowImage_t*          const image ) { ifp::computeImageFingerPrint(image); }
#endif
#ifdef DISPARITY_IMAGE_INTFVER
void ifp::CImageFingerPrint::ComputeImageFingerPrint( DisparityImage_t*     const image ) { ifp::computeImageFingerPrint(image); }
#endif
#ifdef PFC_SIGNATUREIMAGE_INTFVER
void ifp::CImageFingerPrint::ComputeImageFingerPrint( PFC_SignatureImage_t* const image ) { ifp::computeImageFingerPrint(image); }
#endif
#ifdef GRAPPA_SEMSEG_INTFVER
void ifp::CImageFingerPrint::ComputeImageFingerPrint( GrappaSemSeg_t*       const image ) { ifp::computeImageFingerPrint(image); }
#endif

#ifdef IMAGE8_INTFVER
uint8 ifp::CImageFingerPrint::CheckImageFingerPrintValidity( const ImageU8_t*            const image ) { return ifp::checkImageFingerPrintValidity(image); }
#endif
#ifdef IMAGE16_INTFVER
uint8 ifp::CImageFingerPrint::CheckImageFingerPrintValidity( const ImageU16_t*           const image ) { return ifp::checkImageFingerPrintValidity(image); }
#endif
#ifdef FLOW_IMAGE_INTFVER
uint8 ifp::CImageFingerPrint::CheckImageFingerPrintValidity( const FlowImage_t*          const image ) { return ifp::checkImageFingerPrintValidity(image); }
#endif
#ifdef DISPARITY_IMAGE_INTFVER
uint8 ifp::CImageFingerPrint::CheckImageFingerPrintValidity( const DisparityImage_t*     const image ) { return ifp::checkImageFingerPrintValidity(image); }
#endif
#ifdef PFC_SIGNATUREIMAGE_INTFVER
uint8 ifp::CImageFingerPrint::CheckImageFingerPrintValidity( const PFC_SignatureImage_t* const image ) { return ifp::checkImageFingerPrintValidity(image); }
#endif
#ifdef GRAPPA_SEMSEG_INTFVER
uint8 ifp::CImageFingerPrint::CheckImageFingerPrintValidity( const GrappaSemSeg_t*       const image ) { return ifp::checkImageFingerPrintValidity(image); }
#endif

/* -------------- C INTERFACE WRAPPERS -------------- */
#ifdef IMAGE16_INTFVER
void ComputeImageFingerPrint_ui16               (ImageU16_t*           const image) { ifp::computeImageFingerPrint(image); }
#endif
#ifdef IMAGE8_INTFVER
void ComputeImageFingerPrint_ui8                (ImageU8_t*            const image) { ifp::computeImageFingerPrint(image); }
#endif
#ifdef DISPARITY_IMAGE_INTFVER
void ComputeImageFingerPrint_DisparityImage     (DisparityImage_t*     const image) { ifp::computeImageFingerPrint(image); }
#endif
#ifdef FLOW_IMAGE_INTFVER
void ComputeImageFingerPrint_FlowImage          (FlowImage_t*          const image) { ifp::computeImageFingerPrint(image); }
#endif
#ifdef PFC_SIGNATUREIMAGE_INTFVER
void ComputeImageFingerPrint_PFC_SignatureImage (PFC_SignatureImage_t* const image) { ifp::computeImageFingerPrint(image); }
#endif
#ifdef GRAPPA_SEMSEG_INTFVER
void ComputeImageFingerPrint_GrappaSemSeg       (GrappaSemSeg_t*       const image) { ifp::computeImageFingerPrint(image); }
#endif

#ifdef IMAGE16_INTFVER
uint8 CheckImageFingerPrintValidity_ui16               (const ImageU16_t*           const image) { return ifp::checkImageFingerPrintValidity(image); }
#endif
#ifdef IMAGE8_INTFVER
uint8 CheckImageFingerPrintValidity_ui8                (const ImageU8_t*            const image) { return ifp::checkImageFingerPrintValidity(image); }
#endif
#ifdef DISPARITY_IMAGE_INTFVER
uint8 CheckImageFingerPrintValidity_DisparityImage     (const DisparityImage_t*     const image) { return ifp::checkImageFingerPrintValidity(image); }
#endif
#ifdef FLOW_IMAGE_INTFVER
uint8 CheckImageFingerPrintValidity_FlowImage          (const FlowImage_t*          const image) { return ifp::checkImageFingerPrintValidity(image); }
#endif
#ifdef PFC_SIGNATUREIMAGE_INTFVER
uint8 CheckImageFingerPrintValidity_PFC_SignatureImage (const PFC_SignatureImage_t* const image) { return ifp::checkImageFingerPrintValidity(image); }
#endif
#ifdef GRAPPA_SEMSEG_INTFVER
uint8 CheckImageFingerPrintValidity_GrappaSemSeg       (const GrappaSemSeg_t*       const image) { return ifp::checkImageFingerPrintValidity(image); }
#endif
