#ifndef __IMAGE_FINGER_PRINT__
#define __IMAGE_FINGER_PRINT__

/// @file image_fingerprint.h Compute and check image finger print (cf Fusi Checks Requirement MFC400_L3_CIPP_162).
/// @copyright Continental AG, A.D.C. GmbH
/// $Revision: 1.1 $

// PRQA S 1026 EOF
// 2020-2-5; uic58113
// summary < Msg(3:1026) Macro may be used as a constant expression.>
// reason < RTE is in C.Interface version has to use Macro instead of constants.>
#include "algo_type.h"

/// Interface version of the class CImageFingerPrint in this file.
/// @warning If anything to the interface is changed, that number must be incremented by one!
#define CCT_IMAGE_FINGER_PRINT_INTFVER (2)

#ifdef __cplusplus
/// Namespace Image FingerPrint (ifp) that incapsulates fingerprinting methods for image-like aranged memory.
/// @todo This should be removed and the contents moved to cct, since it is a CCT file now.
namespace ifp
{
  /// Holds methods to compute image fingerprints on several image-like data structures.
  /// It fulfills the two use cases:
  /// -# Calculate an fingerprint on a given image-like memory block
  /// -# Verify the image fingerprint of a given memory block.
  class CImageFingerPrint
  {
  private:
    /// Hidden constructor since class follows
    /// singleton pattern.
    /// @todo Remove that, the class is stateless, therefore directly use the static methods.
    CImageFingerPrint() {}

  public:
    static const sint32 ALIGNMENT         = 16; ///< Byte alignment of the memory where the image data is stored
    static const sint32 SAMPLE_COL_NUMBER = 10; ///< Number of columns used as data source for the fingerprinting
    static const sint32 SAMPLE_ROW_NUMBER = 1;  ///< Number of rows used as data source for the fingerprinting

    /// @{ @name Methods for generating the fingerprint

#ifdef IMAGE16_INTFVER
    /// Compute and store the fingerprint in ImageU16_t image header.
    /// @param[in,out] image @parblock
    ///   Input image on which to compute a
    ///   finger print and where to affect it.
    ///   Fingerprint is not computed if image
    ///   is a null pointer or invalid or not init
    /// @endparblock
    static void ComputeImageFingerPrint(ImageU16_t*           const image);
#endif
#ifdef IMAGE8_INTFVER
    /// Compute and store the fingerprint in ImageU8_t image header.
    /// @copydetails ComputeImageFingerPrint(ImageU16_t* const)
    static void ComputeImageFingerPrint(ImageU8_t*            const image);
#endif
#ifdef DISPARITY_IMAGE_INTFVER
    /// Compute and store the fingerprint in DisparityImage_t image header.
    /// @copydetails ComputeImageFingerPrint(ImageU16_t* const)
    static void ComputeImageFingerPrint(DisparityImage_t*     const image);
#endif
#ifdef FLOW_IMAGE_INTFVER
    /// Compute and store the fingerprint in FlowImage_t image header.
    /// @copydetails ComputeImageFingerPrint(ImageU16_t* const)
    static void ComputeImageFingerPrint(FlowImage_t*          const image);
#endif
#ifdef PFC_SIGNATUREIMAGE_INTFVER
    /// Compute and store the fingerprint in PFC_SignatureImage_t image header.
    /// @copydetails ComputeImageFingerPrint(ImageU16_t* const)
    static void ComputeImageFingerPrint(PFC_SignatureImage_t* const image);
#endif
#ifdef GRAPPA_SEMSEG_INTFVER
    /// Compute and store the fingerprint in GrappaSemSeg_t image header.
    /// @copydetails ComputeImageFingerPrint(ImageU16_t* const)
    static void ComputeImageFingerPrint(GrappaSemSeg_t*       const image);
#endif

    /// @}

    /// @{ @name Methods for validating the fingerprint

#ifdef IMAGE16_INTFVER
    /// Compute and compare the fingerprint in ImageU16_t image header.
    /// @param[in] image Input image on which to compute a
    ///                  finger print to compare to the one
    ///                  in its image header
    /// @return @parblock
    /// - 0 if fingerprint is different from the expected one
    /// - 1 if fingerprint is the same
    /// - 2 if image is a null pointer or invalid or not init
    /// @endparblock
    static uint8 CheckImageFingerPrintValidity(const ImageU16_t*           const image);
#endif
#ifdef IMAGE8_INTFVER
    /// Compute and compare the fingerprint in ImageU8_t image header.
    /// @copydetails CheckImageFingerPrintValidity(const ImageU16_t* const)
    static uint8 CheckImageFingerPrintValidity(const ImageU8_t*            const image);
#endif
#ifdef DISPARITY_IMAGE_INTFVER
    /// Compute and compare the fingerprint in DisparityImage_t image header.
    /// @copydetails CheckImageFingerPrintValidity(const ImageU16_t* const)
    static uint8 CheckImageFingerPrintValidity(const DisparityImage_t*     const image);
#endif
#ifdef FLOW_IMAGE_INTFVER
    /// Compute and compare the fingerprint in FlowImage_t image header.
    /// @copydetails CheckImageFingerPrintValidity(const ImageU16_t* const)
    static uint8 CheckImageFingerPrintValidity(const FlowImage_t*          const image);
#endif
#ifdef PFC_SIGNATUREIMAGE_INTFVER
    /// Compute and compare the fingerprint in PFC_SignatureImage_t image header.
    /// @copydetails CheckImageFingerPrintValidity(const ImageU16_t* const)
    static uint8 CheckImageFingerPrintValidity(const PFC_SignatureImage_t* const image);
#endif
#ifdef GRAPPA_SEMSEG_INTFVER
    /// Compute and compare the fingerprint in GrappaSemSeg_t image header.
    /// @copydetails CheckImageFingerPrintValidity(const ImageU16_t* const)
    static uint8 CheckImageFingerPrintValidity(const GrappaSemSeg_t*       const image);
#endif

    /// @}

    /// @{
    /// @name Deprecated interface methods

#ifdef IMAGE16_INTFVER
    /// @copybrief ComputeImageFingerPrint(ImageU16_t* const)
    /// @deprecated Use ComputeImageFingerPrint(ImageU16_t* const)
    /// @copydetails ComputeImageFingerPrint(ImageU16_t* const)
    static void ComputeImageFingerPrint_ui16               (ImageU16_t*           const image) { ComputeImageFingerPrint(image); }
#endif
#ifdef IMAGE8_INTFVER
    /// @copybrief ComputeImageFingerPrint(ImageU8_t* const)
    /// @deprecated Use ComputeImageFingerPrint(ImageU8_t* const)
    /// @copydetails ComputeImageFingerPrint(ImageU8_t* const)
    static void ComputeImageFingerPrint_ui8                (ImageU8_t*            const image) { ComputeImageFingerPrint(image); }
#endif
#ifdef DISPARITY_IMAGE_INTFVER
    /// @copybrief ComputeImageFingerPrint(DisparityImage_t* const)
    /// @deprecated Use ComputeImageFingerPrint(DisparityImage_t* const)
    /// @copydetails ComputeImageFingerPrint(DisparityImage_t* const)
    static void ComputeImageFingerPrint_DisparityImage     (DisparityImage_t*     const image) { ComputeImageFingerPrint(image); }
#endif
#ifdef FLOW_IMAGE_INTFVER
    /// @copybrief ComputeImageFingerPrint(FlowImage_t* const)
    /// @deprecated Use ComputeImageFingerPrint(FlowImage_t* const)
    /// @copydetails ComputeImageFingerPrint(FlowImage_t* const)
    static void ComputeImageFingerPrint_FlowImage          (FlowImage_t*          const image) { ComputeImageFingerPrint(image); }
#endif
#ifdef GRAPPA_SEMSEG_INTFVER
    /// @copybrief ComputeImageFingerPrint(GrappaSemSeg_t* const)
    /// @deprecated Use ComputeImageFingerPrint(GrappaSemSeg_t* const)
    /// @copydetails ComputeImageFingerPrint(GrappaSemSeg_t* const)
    static void ComputeImageFingerPrint_FlowImage          (GrappaSemSeg_t*       const image) { ComputeImageFingerPrint(image); }
#endif

#ifdef IMAGE16_INTFVER
    /// @copybrief CheckImageFingerPrintValidity(const ImageU16_t* const)
    /// @deprecated Use CheckImageFingerPrintValidity(const ImageU16_t* const)
    /// @copydetails CheckImageFingerPrintValidity(const ImageU16_t* const)
    static uint8 CheckImageFingerPrintValidity_ui16               (const ImageU16_t*           const image) { return CheckImageFingerPrintValidity(image); }
#endif
#ifdef IMAGE8_INTFVER
    /// @copybrief CheckImageFingerPrintValidity(const ImageU8_t* const)
    /// @deprecated Use CheckImageFingerPrintValidity(const ImageU8_t* const)
    /// @copydetails CheckImageFingerPrintValidity(const ImageU8_t* const)
    static uint8 CheckImageFingerPrintValidity_ui8                (const ImageU8_t*            const image) { return CheckImageFingerPrintValidity(image); }
#endif
#ifdef DISPARITY_IMAGE_INTFVER
    /// @copybrief CheckImageFingerPrintValidity(const DisparityImage_t* const)
    /// @deprecated Use CheckImageFingerPrintValidity(const DisparityImage_t* const)
    /// @copydetails CheckImageFingerPrintValidity(const DisparityImage_t* const)
    static uint8 CheckImageFingerPrintValidity_DisparityImage     (const DisparityImage_t*     const image) { return CheckImageFingerPrintValidity(image); }
#endif
#ifdef FLOW_IMAGE_INTFVER
    /// @copybrief CheckImageFingerPrintValidity(const FlowImage_t* const)
    /// @deprecated Use CheckImageFingerPrintValidity(const FlowImage_t* const)
    /// @copydetails CheckImageFingerPrintValidity(const FlowImage_t* const)
    static uint8 CheckImageFingerPrintValidity_FlowImage          (const FlowImage_t*          const image) { return CheckImageFingerPrintValidity(image); }
#endif
#ifdef GRAPPA_SEMSEG_INTFVER
    /// @copybrief CheckImageFingerPrintValidity(const GrappaSemSeg_t* const)
    /// @deprecated Use CheckImageFingerPrintValidity(const GrappaSemSeg_t* const)
    /// @copydetails CheckImageFingerPrintValidity(const GrappaSemSeg_t* const)
    static uint8 CheckImageFingerPrintValidity_FlowImage          (const GrappaSemSeg_t*       const image) { return CheckImageFingerPrintValidity(image); }
#endif

    /// Obsolete singleton pattern instance generator.
    /// @deprecated The class is stateless, therefore directly use the static methods.
    /// @todo Remove that, the class is stateless, therefore directly use the static methods.
    /// @return the reference to the instance of the class
    static CImageFingerPrint& getInstance()
    {
      static CImageFingerPrint instance;
      return instance;
    }

    /// @}
  };
}

/* -------------- C INTERFACE WRAPPERS -------------- */
extern "C"
{
#endif // #ifdef __cplusplus

#ifdef IMAGE16_INTFVER
/// C interface to for computing the fingerprint of a ImageU16_t image.
/// @copydetails ifp::CImageFingerPrint::ComputeImageFingerPrint(ImageU16_t* const)
void ComputeImageFingerPrint_ui16               (ImageU16_t*           const image);
#endif
#ifdef IMAGE8_INTFVER
/// C interface to for computing the fingerprint of a ImageU8_t image.
/// @copydetails ifp::CImageFingerPrint::ComputeImageFingerPrint(ImageU16_t* const)
void ComputeImageFingerPrint_ui8                (ImageU8_t*            const image);
#endif
#ifdef DISPARITY_IMAGE_INTFVER
/// C interface to for computing the fingerprint of a DisparityImage_t image.
/// @copydetails ifp::CImageFingerPrint::ComputeImageFingerPrint(ImageU16_t* const)
void ComputeImageFingerPrint_DisparityImage     (DisparityImage_t*     const image);
#endif
#ifdef FLOW_IMAGE_INTFVER
/// C interface to for computing the fingerprint of a FlowImage_t image.
/// @copydetails ifp::CImageFingerPrint::ComputeImageFingerPrint(ImageU16_t* const)
void ComputeImageFingerPrint_FlowImage          (FlowImage_t*          const image);
#endif
#ifdef PFC_SIGNATUREIMAGE_INTFVER
/// C interface to for computing the fingerprint of a PFC_SignatureImage_t image.
/// @copydetails ifp::CImageFingerPrint::ComputeImageFingerPrint(ImageU16_t* const)
void ComputeImageFingerPrint_PFC_SignatureImage (PFC_SignatureImage_t* const image);
#endif
#ifdef GRAPPA_SEMSEG_INTFVER
/// C interface to for computing the fingerprint of a GrappaSemSeg_t image.
/// @copydetails ifp::CImageFingerPrint::ComputeImageFingerPrint(ImageU16_t* const)
void ComputeImageFingerPrint_GrappaSemSeg       (GrappaSemSeg_t*       const image);
#endif

#ifdef IMAGE16_INTFVER
/// C interface to for checking the fingerprint of a ImageU16_t image.
/// @copydetails ifp::CImageFingerPrint::CheckImageFingerPrintValidity(const ImageU16_t* const)
uint8 CheckImageFingerPrintValidity_ui16               (const ImageU16_t*           const image);
#endif
#ifdef IMAGE8_INTFVER
/// C interface to for checking the fingerprint of a ImageU8_t image.
/// @copydetails ifp::CImageFingerPrint::CheckImageFingerPrintValidity(const ImageU16_t* const)
uint8 CheckImageFingerPrintValidity_ui8                (const ImageU8_t*            const image);
#endif
#ifdef DISPARITY_IMAGE_INTFVER
/// C interface to for checking the fingerprint of a DisparityImage_t image.
/// @copydetails ifp::CImageFingerPrint::CheckImageFingerPrintValidity(const ImageU16_t* const)
uint8 CheckImageFingerPrintValidity_DisparityImage     (const DisparityImage_t*     const image);
#endif
#ifdef FLOW_IMAGE_INTFVER
/// C interface to for checking the fingerprint of a FlowImage_t image.
/// @copydetails ifp::CImageFingerPrint::CheckImageFingerPrintValidity(const ImageU16_t* const)
uint8 CheckImageFingerPrintValidity_FlowImage          (const FlowImage_t*          const image);
#endif
#ifdef PFC_SIGNATUREIMAGE_INTFVER
/// C interface to for checking the fingerprint of a PFC_SignatureImage_t image.
/// @copydetails ifp::CImageFingerPrint::CheckImageFingerPrintValidity(const ImageU16_t* const)
uint8 CheckImageFingerPrintValidity_PFC_SignatureImage (const PFC_SignatureImage_t* const image);
#endif
#ifdef GRAPPA_SEMSEG_INTFVER
/// C interface to for checking the fingerprint of a GrappaSemSeg_t image.
/// @copydetails ifp::CImageFingerPrint::CheckImageFingerPrintValidity(const ImageU16_t* const)
uint8 CheckImageFingerPrintValidity_GrappaSemSeg       (const GrappaSemSeg_t*       const image);
#endif

#ifdef __cplusplus
}
#endif

#endif // __IMAGE_FINGER_PRINT__
