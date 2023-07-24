#ifndef interface_images_h__
#define interface_images_h__
namespace ImageCtk{
#include "ctk_img_type.h"
}


#ifndef   MFC_STEREO_ROI_IMAGE_WIDTH
#define MFC_STEREO_ROI_IMAGE_WIDTH	(1024)
#endif
#ifndef   MFC_STEREO_ROI_IMAGE_HEIGHT
#define MFC_STEREO_ROI_IMAGE_HEIGHT	(460)
#endif


static const int ICF_NONE        = (0);
static const int ICF_GRAY        = (1);
static const int ICF_BAYER_RGGB  = (2);
static const int ICF_BAYER_GRBG  = (3);
static const int ICF_BAYER_BGGR  = (4);
static const int ICF_BAYER_GBRG  = (5);
static const int ICF_YCRCB_420   = (6);
static const int ICF_U           = (7);
static const int ICF_V           = (8);
static const int ICF_SATURATION  = (9);


struct ImagesV1 {

  typedef uint16 AlgoCycleCounter_t        /* Algo cycle counter @min:0.0 @max:65535.0 */	/* [Satisfies_rte sws 1188] */;
  typedef uint32 AlgoDataTimeStamp_t       /* Algo data time-stamp type (32 bit variant) @min:0.0 @max:4294967295.0 */	/* [Satisfies_rte sws 1188] */;
  typedef uint32 AlgoInterfaceVersionNumber_t /* Algo interface version nummbers @min:0.0 @max:4294967295.0 @resolution:1.0 */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 AlgoSignalState_t         /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 ImageDataFormat_t         /* Image data format enumeration @min: 0 @max:10 @values: enum { ICF_NONE=0,ICF_SATURATION=9,ICF_V=8,ICF_BAYER_GBRG=5,ICF_BAYER_GRBG=3,ICF_YCRCB_420=6,ICF_BAYER_BGGR=4,ICF_BAYER_RGGB=2,ICF_U=7,ICF_GRAY=1,ICF_2DVECTORFIELD=10,} */	/* [Satisfies_rte sws 1188] */;

  static const AlgoInterfaceVersionNumber_t   IMAGE16_INTFVER       = 1;
  static const AlgoSignalState_t              AL_SIG_STATE_INIT     = 0;
  static const AlgoSignalState_t              AL_SIG_STATE_OK       = 1;
  static const AlgoSignalState_t              AL_SIG_STATE_INVALID  = 2;


  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    AlgoDataTimeStamp_t uiTimeStamp;
    AlgoCycleCounter_t uiMeasurementCounter;
    AlgoCycleCounter_t uiCycleCounter;
    AlgoSignalState_t eSigStatus;
  } SignalHeader_t;

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    uint16 uiBitsPerChannel;
    sint16 iPixelBytes;
    sint32 iRowBytes;
    sint32 iSizeBytes;
    uint16 uiWidth;
    uint16 uiHeight;
    sint8 iScaleX;
    sint8 iScaleY;
    sint16 iOffsetX;
    sint16 iOffsetY;
    ImageDataFormat_t eDataFormat;
  } ImageHeader_t;			/* Common header for all image (aka 2D array) types */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    AlgoInterfaceVersionNumber_t uiVersionNumber;
    SignalHeader_t sSigHeader;
    ImageHeader_t sImgHeader;
    const  uint16 *   aImageData;
  } ImageU16_t;			/* General data type for image data */

};


struct ImagesV2 {

  typedef uint32 AlgoInterfaceVersionNumber_t /* Algo interface version nummbers @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */;
  typedef uint32 AlgoDataTimeStamp_t       /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */;
  typedef uint16 AlgoCycleCounter_t        /* Algo cycle counter @min:0 @max:65535 */	/* [Satisfies_rte sws 1188] */;
  typedef sint8 AlgoSignalState_t         /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef sint8 ImageDataFormat_t         /* Image data format enumeration @min: 0 @max:10 @values: enum { ICF_NONE=0,ICF_SATURATION=9,ICF_V=8,ICF_BAYER_GBRG=5,ICF_BAYER_GRBG=3,ICF_YCRCB_420=6,ICF_BAYER_BGGR=4,ICF_BAYER_RGGB=2,ICF_U=7,ICF_GRAY=1,ICF_2DVECTORFIELD=10,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint16 ParameterID_t             /* Parameter Id used to sync/match interfaces @min:0 @max:65535 */	/* [Satisfies_rte sws 1188] */;

  static const AlgoInterfaceVersionNumber_t   IMAGE16_INTFVER       = 2;
  static const AlgoSignalState_t              AL_SIG_STATE_INIT     = 0;
  static const AlgoSignalState_t              AL_SIG_STATE_OK       = 1;
  static const AlgoSignalState_t              AL_SIG_STATE_INVALID  = 2;


  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    AlgoDataTimeStamp_t uiTimeStamp;
    AlgoCycleCounter_t uiMeasurementCounter;
    AlgoCycleCounter_t uiCycleCounter;
    AlgoSignalState_t eSigStatus;
  } SignalHeader_t;			/* Common header for all structured data types */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    uint16 uiBitsPerChannel;
    sint16 iPixelBytes;
    sint32 iRowBytes;
    sint32 iSizeBytes;
    uint16 uiWidth;
    uint16 uiHeight;
    sint8 iScaleX;
    sint8 iScaleY;
    sint16 iOffsetX;
    sint16 iOffsetY;
    ImageDataFormat_t eDataFormat;
    ParameterID_t uiParameterId;
  } ImageHeader_t;			/* Common header for all image (aka 2D array) types */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    AlgoInterfaceVersionNumber_t uiVersionNumber;
    SignalHeader_t sSigHeader;
    ImageHeader_t sImgHeader;
    const  uint16 *   aImageData;
  } ImageU16_t;			/* General data type for image data */

};


struct ImagesV3 {

    typedef uint32 AlgoInterfaceVersionNumber_t /* Algo interface version nummbers @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */;
    typedef uint32 AlgoDataTimeStamp_t       /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */;
    typedef uint16 AlgoCycleCounter_t        /* Algo cycle counter @min:0 @max:65535 */	/* [Satisfies_rte sws 1188] */;
    typedef sint8 AlgoSignalState_t         /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */	/* [Satisfies_rte sws 1188] */;
    typedef sint8 ImageDataFormat_t         /* Image data format enumeration @min: 0 @max:10 @values: enum { ICF_NONE=0,ICF_SATURATION=9,ICF_V=8,ICF_BAYER_GBRG=5,ICF_BAYER_GRBG=3,ICF_YCRCB_420=6,ICF_BAYER_BGGR=4,ICF_BAYER_RGGB=2,ICF_U=7,ICF_GRAY=1,ICF_2DVECTORFIELD=10,} */	/* [Satisfies_rte sws 1188] */;
    typedef uint16 ParameterID_t             /* Parameter Id used to sync/match interfaces @min:0 @max:65535 */	/* [Satisfies_rte sws 1188] */;

    static const AlgoInterfaceVersionNumber_t   IMAGE16_INTFVER       = 3;
    static const AlgoSignalState_t              AL_SIG_STATE_INIT     = 0;
    static const AlgoSignalState_t              AL_SIG_STATE_OK       = 1;
    static const AlgoSignalState_t              AL_SIG_STATE_INVALID  = 2;


    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
        AlgoDataTimeStamp_t uiTimeStamp;
        AlgoCycleCounter_t uiMeasurementCounter;
        AlgoCycleCounter_t uiCycleCounter;
        AlgoSignalState_t eSigStatus;
    } SignalHeader_t;			/* Common header for all structured data types */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
        uint16 uiBitsPerChannel;
        sint16 iPixelBytes;
        sint32 iRowBytes;
        sint32 iSizeBytes;
        uint16 uiWidth;
        uint16 uiHeight;
        sint8 iScaleX;
        sint8 iScaleY;
        sint16 iOffsetX;
        sint16 iOffsetY;
        ImageDataFormat_t eDataFormat;
        ParameterID_t uiParameterId;
        uint32 uiFingerprint;
    } ImageHeader_t;			/* Common header for all image (aka 2D array) types */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
        AlgoInterfaceVersionNumber_t uiVersionNumber;
        SignalHeader_t sSigHeader;
        ImageHeader_t sImgHeader;
        const  uint16 *   aImageData;
    } ImageU16_t;			/* General data type for image data */

};


struct ImagesV4 {

    typedef uint32 AlgoInterfaceVersionNumber_t /* Algo interface version nummbers @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */;
    typedef uint32 AlgoDataTimeStamp_t       /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */;
    typedef uint16 AlgoCycleCounter_t        /* Algo cycle counter @min:0 @max:65535 */	/* [Satisfies_rte sws 1188] */;
    typedef sint8 AlgoSignalState_t         /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */	/* [Satisfies_rte sws 1188] */;
    typedef sint8 ImageDataFormat_t         /* Image data format enumeration @min: 0 @max:10 @values: enum { ICF_NONE=0,ICF_SATURATION=9,ICF_V=8,ICF_BAYER_GBRG=5,ICF_BAYER_GRBG=3,ICF_YCRCB_420=6,ICF_BAYER_BGGR=4,ICF_BAYER_RGGB=2,ICF_U=7,ICF_GRAY=1,ICF_2DVECTORFIELD=10,} */	/* [Satisfies_rte sws 1188] */;
    typedef sint8 eCameraType_t;
    
    static const AlgoInterfaceVersionNumber_t   IMAGE16_INTFVER       = 4;
    static const AlgoSignalState_t              AL_SIG_STATE_INIT     = 0;
    static const AlgoSignalState_t              AL_SIG_STATE_OK       = 1;
    static const AlgoSignalState_t              AL_SIG_STATE_INVALID  = 2;
    static const eCameraType_t                  CAMERA_TYPE_UNKNOWN   = 0;
    static const eCameraType_t                  CAMERA_TYPE_DISTORTED = 1;
    static const eCameraType_t                  CAMERA_TYPE_PINHOLE   = 2;  


    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
        AlgoDataTimeStamp_t uiTimeStamp;
        AlgoCycleCounter_t uiMeasurementCounter;
        AlgoCycleCounter_t uiCycleCounter;
        AlgoSignalState_t eSigStatus;
    } SignalHeader_t;			/* Common header for all structured data types */

    typedef struct
    {
        float32 fFocalX;
        float32 fFocalY;
        float32 fCenterX;
        float32 fCenterY;
        eCameraType_t eCameraType;
    } ImageHeaderIntrinsics_t;

    
    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
        uint16 uiBitsPerChannel;
        sint16 iPixelBytes;
        sint32 iRowBytes;
        sint32 iSizeBytes;
        uint16 uiWidth;
        uint16 uiHeight;
        sint8 iScaleX;
        sint8 iScaleY;
        sint16 iOffsetX;
        sint16 iOffsetY;
        ImageDataFormat_t eDataFormat;
        ImageHeaderIntrinsics_t sIntrinsics;
        uint32 uiFingerprint;
    } ImageHeader_t;			/* Common header for all image (aka 2D array) types */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
        AlgoInterfaceVersionNumber_t uiVersionNumber;
        SignalHeader_t sSigHeader;
        ImageHeader_t sImgHeader;
        const  uint16 *   aImageData;
    } ImageU16_t;			/* General data type for image data */

};

#endif // interface_images_h__
