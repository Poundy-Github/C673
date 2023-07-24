/*! \file **********************************************************************

  COMPANY:                Continental Automotive , 

  PROJECT:                MFC300

  CPU:                    MPC567x

  COMPONENT:              ROI

  MODULNAME:              glob_type.h

  DESCRIPTION:            This file contains all global types, needed by several 
                          components. Most types are derived from platform_types.h,
                          some others (like bit types) are added here.

  AUTHOR:                 Lars Perske (b-plus GmbH)

  CREATION DATE:          21.12.2009

  VERSION:                $Revision: 1.1 $


  ---*/ /*---
    CHANGES:              $Log: glob_type.h  $
    CHANGES:              Revision 1.1 2021/12/13 17:24:43CET Wang, David (Wangd3) 
    CHANGES:              Initial revision
    CHANGES:              Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310_common/project.pj
    CHANGES:              Revision 1.0 2017/03/03 10:35:40CET Sorge, Sven (uidg3181) 
    CHANGES:              Initial revision
    CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310_common/project.pj
    CHANGES:              Revision 1.1 2014/03/13 15:11:15CET Sorge, Sven (uidg3181) 
    CHANGES:              Initial revision
    CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310_common/project.pj
    CHANGES:              Revision 1.11 2012/04/05 11:32:35CEST Wolf-EXT, Severin (uidu1890) 
    CHANGES:              added callback-type for SetAlgoInitialized
    CHANGES:              --- Added comments ---  uidu1890 [Apr 5, 2012 11:32:37 AM CEST]
    CHANGES:              Change Package : 97225:1 http://mks-psad:7002/im/viewissue?selection=97225
    CHANGES:              Revision 1.10 2012/03/08 15:12:56CET Achatz-EXT, Florian (uidt9222) 
    CHANGES:              ROI_FIFO_CORE1 buffer type added
    CHANGES:              --- Added comments ---  uidt9222 [Mar 8, 2012 3:12:56 PM CET]
    CHANGES:              Change Package : 102090:1 http://mks-psad:7002/im/viewissue?selection=102090
    CHANGES:              Revision 1.9 2012/02/24 17:46:29CET Achatz-EXT, Florian (uidt9222) 
    CHANGES:              For ROIs defined as ROI_FIFO buffer types the first line is within visible image (without dark rows)
    CHANGES:              --- Added comments ---  uidt9222 [Feb 24, 2012 5:46:30 PM CET]
    CHANGES:              Change Package : 94684:1 http://mks-psad:7002/im/viewissue?selection=94684
    CHANGES:              Revision 1.8 2011/03/17 23:16:58CET Gilch-EXT, Andreas (uidt0904) 
    CHANGES:              removed redeclaration of 64bit types; (see Plattform_Types.h)
    CHANGES:              --- Added comments ---  uidt0904 [Mar 17, 2011 11:16:58 PM CET]
    CHANGES:              Change Package : 60741:1 http://mks-psad:7002/im/viewissue?selection=60741
    CHANGES:              Revision 1.7 2011/03/15 15:43:13CET Limbrunner Matthias (x-limbrunnem) (x-limbrunnem) 
    CHANGES:              Timestamps of ROI framework adapted to 64 bit
    CHANGES:              --- Added comments ---  x-limbrunnem [Mar 15, 2011 3:43:13 PM CET]
    CHANGES:              Change Package : 61704:1 http://mks-psad:7002/im/viewissue?selection=61704
    CHANGES:              Revision 1.6 2011/02/24 10:43:04CET Matthias Limbrunner (x-limbrunnem) 
    CHANGES:              Added basic 64bit types
    CHANGES:              --- Added comments ---  x-limbrunnem [Feb 24, 2011 10:43:04 AM CET]
    CHANGES:              Change Package : 60026:1 http://mks-psad:7002/im/viewissue?selection=60026
    CHANGES:              Revision 1.5 2010/12/23 11:48:15CET Perske Lars (uidk7799) (uidk7799) 
    CHANGES:              Added pfctFuncMain2 to ROI descriptor for core1 executions
    CHANGES:              --- Added comments ---  uidk7799 [Dec 23, 2010 11:48:16 AM CET]
    CHANGES:              Change Package : 55515:1 http://mks-psad:7002/im/viewissue?selection=55515
    CHANGES:              Revision 1.4 2010/11/15 19:02:43CET Perske Lars (uidk7799) (uidk7799) 
    CHANGES:              Changed comment of ROIPipElem (no functional change)
    CHANGES:              --- Added comments ---  uidk7799 [Nov 15, 2010 7:02:43 PM CET]
    CHANGES:              Change Package : 52444:1 http://mks-psad:7002/im/viewissue?selection=52444
    CHANGES:              Revision 1.3 2010/10/18 15:12:24CEST Perske Lars (uidk7799) (uidk7799) 
    CHANGES:              Added bAborted to RoiPipElem
    CHANGES:              --- Added comments ---  uidk7799 [Oct 18, 2010 3:12:25 PM CEST]
    CHANGES:              Change Package : 52444:1 http://mks-psad:7002/im/viewissue?selection=52444
    CHANGES:              Revision 1.2 2010/10/14 15:51:59CEST Perske Lars (uidk7799) (uidk7799) 
    CHANGES:              Added usModuloWidth in t_RoiDescriptor
    CHANGES:              Revision 1.1 2010/09/30 18:58:15CEST Johann Fuehrmann (x-fuehrmannj) 
    CHANGES:              Initial revision
    CHANGES:              Member added to project /nfs/projekte1/PROJECTS/MFC300/05_Software/MCU/04_Engineering/01_Source_Code/SW/project.pj
    CHANGES:              Revision 1.4 2010/05/27 11:00:53CEST lperske 
    CHANGES:              Avoided hundreds of compiler warnings thrown due to new compiler settings
    CHANGES:              --- Added comments ---  lperske [2010/05/27 09:00:53Z]
    CHANGES:              Change Package : 44487:1 http://LISS014:6001/im/viewissue?selection=44487
    CHANGES:              Revision 1.3 2010/04/19 18:39:58CEST Lars Perske (lperske) 
    CHANGES:              New ROI stuff
    CHANGES:              --- Added comments ---  lperske [2010/04/19 16:39:58Z]
    CHANGES:              Change Package : 38903:1 http://LISS014:6001/im/viewissue?selection=38903
    CHANGES:              Revision 1.2 2010/03/26 12:12:08CET Lars Perske (lperske) 
    CHANGES:              Added ROI types, changed types to new coding guidelines
    CHANGES:              --- Added comments ---  lperske [2010/03/26 11:12:08Z]
    CHANGES:              Change Package : 38903:1 http://LISS014:6001/im/viewissue?selection=38903
    CHANGES:              Revision 1.1 2010/03/04 13:49:24CET jfuehrman 
    CHANGES:              Initial revision
    CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/BaseDevelopment_Camera_SW/02_Engineering/MPC5673L/MFC300/04_Engineering/01_Source_Code/SW/project.pj

**************************************************************************** */
#ifndef GLOB_TYPE_H
#define GLOB_TYPE_H


/* ************************************************************************* */
/*   INCLUDES                                                                */
/* ************************************************************************* */
#include "Platform_Types.h"


/** @defgroup DataDictionary Data Dictionary
  Here you will find all available data types
  @{
 */

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/

/* Basic types */
//typedef signed long long      sint64;  /* -9223372036854775808 .. 9223372036854775807  */
//typedef unsigned long long    uint64;  /*                    0 .. 18446744073709551615 */

/* basic bitfield types */
/*----------------------*/
typedef sint32          sbit32;
typedef sint16          sbit16;
typedef sint8           sbit8;
typedef uint32          ubit32;
typedef uint16          ubit16;
typedef uint8           ubit8;


/* basic pointer types */
/*---------------------*/
typedef sint8 *         psint8;
typedef uint8 *         puint8;
typedef sint16 *        psint16;
typedef uint16 *        puint16;
typedef sint32 *        psint32;
typedef uint32 *        puint32;


/* bit field structured types */
/*----------------------------*/

/*! @todo for each new project/compiler we have to check the allignment 
and packaging of bit fields in combination with structs and unions 
like in the types FourByte_t, TwoByte_t and OnByte_t 
If the allignment is o.k. we can violate MISRA Rule 110 */


/*lint -e960 Note 960: Violates MISRA Required Rule 110, bitfields inside union: untagged */
/*! Four Byte Bitfield (union)
Union to access each Bit, Byte, Word or the complete 32 Bit value.
FourByte_t t;
@sample:
t.LONG = 0xA0FF00FF;
t.WORD.H = 0xA0FF;
t.BYTE.MH =0xA0;
t.BIT.B20 = 1; 
*/  
typedef union
{
    float32     FLOAT;    /*!< Access to 4 byte float */
    uint32      LONG;     /*!< Access to Byte 1+2+3+4 */
    struct
    {
      uint16    H;        /*!< Access to Byte 3+4 */
      uint16    L;        /*!< Access to Byte 1+2 */
    }WORD;
    struct
    {
      uint8     H;        /*!< Access to Byte 4 */
      uint8     MH;       /*!< Access to Byte 3 */
      uint8     ML;       /*!< Access to Byte 2 */
      uint8     L;        /*!< Access to Byte 1 */
    }BYTE;
    struct
    {
      ubit32    B31   :1; /*!< Access to Bit 31 */
      ubit32    B30   :1; /*!< Access to Bit 30 */
      ubit32    B29   :1; /*!< Access to Bit 29 */
      ubit32    B28   :1; /*!< Access to Bit 28 */
      ubit32    B27   :1; /*!< Access to Bit 27 */
      ubit32    B26   :1;
      ubit32    B25   :1;
      ubit32    B24   :1;
      ubit32    B23   :1;
      ubit32    B22   :1;
      ubit32    B21   :1;
      ubit32    B20   :1;
      ubit32    B19   :1;
      ubit32    B18   :1;
      ubit32    B17   :1;
      ubit32    B16   :1;
      ubit32    B15   :1;
      ubit32    B14   :1;
      ubit32    B13   :1;
      ubit32    B12   :1;
      ubit32    B11   :1;
      ubit32    B10   :1;
      ubit32    B9    :1;
      ubit32    B8    :1;
      ubit32    B7    :1;
      ubit32    B6    :1;
      ubit32    B5    :1;
      ubit32    B4    :1;
      ubit32    B3    :1;
      ubit32    B2    :1;
      ubit32    B1    :1; /*!< Access to Bit 1 */
      ubit32    B0    :1; /*!< Access to Bit 0 */
    }BIT; /*!< Access to Bit 1-31 */
} t_FourByte; 


typedef union 
{
    uint16      WORD;     /*!< Access to Byte 1+2 */
    struct 
    {
      uint8     H;        /*!< Access to the high byte */
      uint8     L;        /*!< Access to the low byte */
    }BYTE;
    struct
    {
      ubit16    B15   :1; /*!< Access to Bit 15 */
      ubit16    B14   :1; /*!< Access to Bit 14 */
      ubit16    B13   :1; /*!< Access to Bit 13 */
      ubit16    B12   :1;
      ubit16    B11   :1;
      ubit16    B10   :1;
      ubit16    B9    :1;
      ubit16    B8    :1;
      ubit16    B7    :1;
      ubit16    B6    :1;
      ubit16    B5    :1;
      ubit16    B4    :1;
      ubit16    B3    :1;
      ubit16    B2    :1;
      ubit16    B1    :1; /*!< Access to Bit 1 */
      ubit16    B0    :1; /*!< Access to Bit 0 */
    }BIT; /*!< Access to Bit 0-15 */
} t_TwoByte; 


typedef union 
{
    uint8       BYTE;     /*!< Access to 8-Bits */
    struct
    {
      ubit8     B7    :1; /*!< Access to Bit 7 */
      ubit8     B6    :1; /*!< Access to Bit 6 */
      ubit8     B5    :1;
      ubit8     B4    :1;
      ubit8     B3    :1;
      ubit8     B2    :1;
      ubit8     B1    :1;
      ubit8     B0    :1; /*!< Access to Bit 0 */
    }BIT;
} t_OneByte;



/* camera specific types */
/*-----------------------*/

/*! @description: type for old imager pixel data (with 8 data lines) taken over from CSF2xx project
  @resolution: 8bit  @unit: -  @min: 0  @max: 255 */
typedef uint8           PixelData_t;

/*! @description: type for 16bit imager pixel data (with 12 data lines connected) 
  @resolution: 12bit  @unit: -  @min: 0  @max: 4095 */
typedef uint16          t_PixelData;



/* ROI specific types which are used in HLA, HLA_Adapter and ROI */
/*---------------------------------------------------------------*/
typedef enum
{
  ROI_NO_ERR=0,
  ROI_NO_USEFULL_DATA,
  ROI_XY1_GREATER_XY2,
  ROI_ROI_TO_BIG,
  ROI_DATA_OUT_OF_PICTURE,
  ROI_DATA_OUT_OF_ROIDEF,
  ROI_DATA_MEM_SIZE_OVFL,
  ROI_COUNT_MAX_OVFL,
  ROI_DATA_WIDTH_OUT_OF_PICT,
  ROI_NO_USEFUL_USER_DATA,
  ROI_MAX_NUM_ERR,
  ROI_HAL_ERROR
} t_ROIDataUseErr;

typedef enum
{
  ROI_SINGLE,                 /*!< Roi has only one local buffer. */
  ROI_TOGGLE,                 /*!< Roi has toggle buffer memory. */
  ROI_MODULO,                 /*!< Roi has toggle buffer plus ringbuffer, execution of ringbuffer callback function on highes prio., roi callback on  task prio. */
  ROI_ASYNCHRONOUS,           /*!< legacy, don't use! */
  ROI_FIFO,                   /*!< FIFO is used (MCU used with DRI) */
  ROI_NO_BUFFER,              /*!< Roi has no local buffer memory, Data source is image pointer */
  ROI_FIFO_STATIC_SUB,         /*!< Static sub ROI of ROI_FIFO which is used for icons on M32 with DRI to hold parts of the entire ROI without being overwritten */
  ROI_FIFO_RAW,
  ROI_FIFO_CORE1
} t_RoiBufferType;

typedef enum
{
  ROI_FRAME_SHORT,            /*!< short imager exposure time */
  ROI_FRAME_LONG,              /*!< long imager exposure time */
} t_RoiFrameType;

typedef struct 
{
  ubit32  ucRoiMissedRealtime               : 1;  /*!< signaling the algoritm, that last processing was too long */
  ubit32  ucRoiTimeout                      : 1;  /*!< signal to monitoring, that this Roi has hang up */
  ubit32  ucRoiNumberOfDroppedFrames        : 8;  /*!< eight bit valid if ucRoiTimeout==TRUE */
  ubit32  ucRoiExposureTimePlausiblitiyCeck : 1;  /*!< signal to monitoring, that there is a mismatch of frame number and brightness of current frame in relation to previous frame */
  ubit32  ucRoiTableNotEmpty                : 8;  /*!< eight bit in ucfRoiTableNotEmpty reserved*/
  ubit32  ucRoiError;
  ubit32  u32RoiDataUseStatus;
} t_RoiErrorFlags;

typedef struct
{
  ubit32            ucfMemType          : 1;  /*!< one bit in char for MemType reserved */
  ubit32            ucfToggleSingle     : 1;
  ubit32            ucfProcessRunning   : 1;  /*!< togglebuffer-switch although still processing? 1->wait, 0->don't wait */
  ubit32            ucfOnOff            : 1;  /*!< ROI is active: TRUE -> data is beeing extracted from frame, set by framework, can be polled in application control task */
  ubit32            ucfResolution       : 2;
  ubit32            ucfDMADone          : 1;  /*!< DMA is done, used by framework, ISR resets this flag */
  t_RoiErrorFlags   strErrFlags;
} t_RoiFlags;

typedef struct
{
  uint16            usX1;
  uint16            usX2;
  uint16            usWidth;
  uint16            usY1;
  uint16            usY2;
  uint16            usHeight;
}t_RoiBase;

/*! @description: function pointer which is used in t_RoiPipElem, one parameter */
typedef void        (*FCT_RoiCallBk)(void* param);

/*! @description: function pointer which is used for algo main call, no parameters */
typedef void        (*FCT_RoiMainCallBk)(void);

/*! @description: ROI descriptor which is also passed back to caller */
typedef struct
{
  t_RoiBase         strBaseDesc;            /*!< Rectangle */
  t_RoiFlags        strFlagsDesc;           /*!< flags */
  boolean           bSwitchedOn;            /*!< Roi will be updated or not */
  t_RoiBufferType   enumToggleSingle;       /*!< Toggle functionality mode */
  uint16            usModuloCnt;            /*!< Number of rows to collect per modulo application fuction call */
  uint16            usModuloHeight;         /*!< Number of rows which should be stored in FIFO */
  uint16            usModuloWidth;          /*!< Number of columns which should be stored in one FIFO row */
  uint16            usRingBufThreshold;     /*!< max. number of rows between read and write pointer */
  uint32            u32RoiSize;             /*!< For MEM_free */
  uint32            u32ModuloSize;          /*!<  */
  FCT_RoiCallBk     pfctFuncPreprocRoi;     /*!< pointer to final line function */
  FCT_RoiCallBk     pfctFuncPreprocToggleRoi; /*!< pointer to pre-process line function */
  FCT_RoiMainCallBk pfctFuncMain;           /*!< Pointer to main function */
  FCT_RoiMainCallBk pfctFuncMain2;          /*!< Pointer to main function */
  uint32            u32Id;                  /*!< Identifier, its free to the user to set this id to identify the window in the application */
  void            * pApp;                   /*!< Pointer to application specific Roi-information, its free to be used by the application */
  t_ROIDataUseErr   enumRoiDataUseErr;
} t_RoiDescriptor;


/*! @description: ROI user struct with descriptors */
typedef struct
{
  t_RoiDescriptor   strFromApp;
  t_RoiDescriptor   strToApp;
} t_RoiUser;

/*! @description: pointer/address type which is used as ROI Handle */
typedef t_RoiUser * t_pRoiHandle;


/*! @description: struct which is used in ROI, HLA_ADAPTER and HLA for data exchange */
typedef struct
{
  t_pRoiHandle      pRoiHandle;             /*!< Pointer to ROI informations */
  t_PixelData     * pData;                  /*!< Pointer to ROI FIFO start + line offs */
  t_PixelData     * pImageData;             /*!< Pointer to ROI FIFO start (start of complete image in fifo) */
  t_PixelData     * pCurrLine;              /*!< Pointer to start of current image line */
  uint16            usRoiRow;               /*!< Current row in roi. Set before calling modulo processing functions */
  sint32          * pi32References;         /*!< how many ROI are still owner of ImageData (source of ROI) */
  uint32            ui32frameNumber;        /*!< Frame number count (output of IA driver, synchronized to Embedded data) */
  uint64            ui64FrameTimeStamp;     /*!< Frame time stamp (1µs resolution) */
  uint64            ui64CallbackTimeStamp;  /*!< Timestamp, capturing algo callback function time (1µs resolution) */
  FCT_RoiCallBk     pfctFuncPrep;           /*!< Pointer to func */
  uint16            ui16CurrentMargin;      /*!< Current fifo margin (fill level) - if(ui16CurrentMargin < usRingBufThreshold)=>ABORT */
  boolean           bAborted;               /*!< calling of pre-proc aborted (sampling continues for algo with whole image processing) */
} t_RoiPipElem;

typedef void (GLB_fctp_AlgoInitialized_Callback)(uint8 Algo_ui8_ID, boolean Algo_b_InitState);


#endif

/** @} */
