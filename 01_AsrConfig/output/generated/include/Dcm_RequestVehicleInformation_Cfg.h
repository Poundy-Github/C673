/* --------{ EB Automotive C Source File }-------- */

#ifndef DCM_REQUESTVEHICLEINFORMATION_CFG_H
#define DCM_REQUESTVEHICLEINFORMATION_CFG_H

/*==================[includes]===================================================================*/

/*==================[macros]=====================================================================*/

#if (defined DCM_DSP_VEHINFO_NUM)
#error DCM_DSP_VEHINFO_NUM already defined
#endif /* if (defined DCM_DSP_VEHINFO_NUM) */

/** \brief Number of VehInfo configured */
#define DCM_DSP_VEHINFO_NUM             0U

#if (defined DCM_DSP_VEHINFODATA_NUM)
#error DCM_DSP_VEHINFODATA_NUM already defined
#endif /* if (defined DCM_DSP_VEHINFODATA_NUM) */

/** \brief Number of VehInfo Data configured */
#define DCM_DSP_VEHINFODATA_NUM             0U

/** \brief Size of VehInfo UsedBit Array */
#if (defined DCM_DSP_VEHINFO_USED_ARRAY_SIZE)
#error "DCM_DSP_VEHINFO_USED_ARRAY_SIZE is already defined"
#endif
#define DCM_DSP_VEHINFO_USED_ARRAY_SIZE 0U

#if (defined DCM_DSP_VEHINFO_AUTOSAR_403)
#error "DCM_DSP_VEHINFO_AUTOSAR_403 is already defined"
#endif
#define DCM_DSP_VEHINFO_AUTOSAR_403 0U

#if (defined DCM_DSP_VEHINFO_AUTOSAR_440)
#error "DCM_DSP_VEHINFO_AUTOSAR_440 is already defined"
#endif
#define DCM_DSP_VEHINFO_AUTOSAR_440 1U

#if (defined DCM_DSP_VEHINFO_AUTOSAR_VERSION)
#error DCM_DSP_VEHINFO_AUTOSAR_VERSION already defined
#endif
/** \brief ASR version compatibility for DataTransfer services */
#define DCM_DSP_VEHINFO_AUTOSAR_VERSION                   DCM_DSP_VEHINFO_AUTOSAR_403

/*==================[type definitions]===========================================================*/

/* !LINKSTO Dcm.Dsn.RequestVehicleInformation.ConfigurationDataTypes,1 */
/* !LINKSTO Dcm.dsn.Dsp.ReqVehInfo.Config.0002,1 */
 /** \brief Type definition for the DcmDspVehInfoInfoType parameter */
typedef uint8 Dcm_DspVehInfoInfoTypeType;

/* !LINKSTO Dcm.dsn.Dsp.ReqVehInfo.Config.0003,1 */
 /** \brief Type definition for the the number of DcmDspVehInfoData containers */
typedef uint8 Dcm_DspNumOfVehInfoDataType;

  /* !LINKSTO Dcm.dsn.Dsp.ReqVehInfo.Config.0004,1 */
  /** \brief Type definition for index of VehInfoData in Dcm_DspVehInfoConfigData array*/
#if (DCM_DSP_VEHINFODATA_NUM > 0xFFU)
typedef uint16 Dcm_DspStartIndexOfVehInfoDataType;
#else
typedef uint8 Dcm_DspStartIndexOfVehInfoDataType;
#endif

/* !LINKSTO Dcm.Dsn.ReqVehInfo.Type.DcmDspVehInfo,1 */
/** \brief Configuration structure of one DcmDspVehInfo container */
typedef struct
{
  /* !LINKSTO Dcm.dsn.Dsp.ReqVehInfo.Config.0004,1 */
  /** \brief The first index of a DcmDspVehInfoData container related to this VehInfo */
  Dcm_DspStartIndexOfVehInfoDataType StartIndexOfVehInfoData;

  /* !LINKSTO Dcm.dsn.Dsp.ReqVehInfo.Config.0003,1 */
  /** \brief The number of DcmDspVehInfoData containers */
  Dcm_DspNumOfVehInfoDataType NumOfVehInfoData;

  /* !LINKSTO Dcm.dsn.Dsp.ReqVehInfo.Config.0002,1 */
  /** \brief The value of the DcmDspVehInfoInfoType parameter. */
  Dcm_DspVehInfoInfoTypeType VehInfoInfoType;
#if (DCM_DSP_VEHINFO_AUTOSAR_VERSION == DCM_DSP_VEHINFO_AUTOSAR_440)
  /** \brief The value of the DcmDspVehInfoNODIProvResp parameter. */
  boolean DcmDspVehInfoNODIProvResp;
#endif
}
Dcm_DspVehInfoType;

/* !LINKSTO Dcm.dsn.Dsp.ReqVehInfo.Config.0006,1 */
/** \brief Type definition for size of the VehInfoData */
typedef uint8 Dcm_DspVehInfoDataSizeType;

/* !LINKSTO Dcm.dsn.Dsp.ReqVehInfo.Config.0007,1 */
/* !LINKSTO Dcm.Dsn.ReqVehInfo.If.InfotypeServices,1 */
/** \brief Type definition for pointer to the function called to get the VehInfoData */
#if (DCM_DSP_VEHINFO_AUTOSAR_VERSION == DCM_DSP_VEHINFO_AUTOSAR_403)
/* !LINKSTO Dcm.RequestVehicleInformation.DcmDspVehInfoASRVersion403.DcmDspVehInfoDataUsePortTrue,1 */
/* !LINKSTO Dcm.RequestVehicleInformation.DcmDspVehInfoASRVersion403.DcmDspVehInfoDataUsePortFalse,1 */
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_GetInfotypeValueDataFunctionPointerType) (
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, DCM_VAR) DataValueBuffer);
#else /* #if (DCM_DSP_VEHINFO_AUTOSAR_VERSION == DCM_DSP_VEHINFO_AUTOSAR_403) */
/* !LINKSTO Dcm.RequestVehicleInformation.DcmDspVehInfoASRVersion440.DcmDspVehInfoDataUsePortTrue,1 */
/* !LINKSTO Dcm.RequestVehicleInformation.DcmDspVehInfoASRVersion440.DcmDspVehInfoDataUsePortFalse,1 */
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_GetInfotypeValueDataFunctionPointerType) (
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, DCM_VAR) DataValueBuffer,
  P2VAR(uint8, AUTOMATIC, DCM_VAR) DataValueBufferSize);
#endif /* #if (DCM_DSP_VEHINFO_AUTOSAR_VERSION == DCM_DSP_VEHINFO_AUTOSAR_403) */
/* !LINKSTO Dcm.Dsn.ReqVehInfo.Type.DcmDspVehInfoData,1 */
/** \brief Configuration structure of one DcmDspVehInfoData container */
typedef struct
{
  /* !LINKSTO Dcm.dsn.Dsp.ReqVehInfo.Config.0007,1 */
  /** \brief Pointer to the function called to get the VehInfoData */
  Dcm_GetInfotypeValueDataFunctionPointerType GetInfotypeValueDataFunctionPointer;

  /* !LINKSTO Dcm.dsn.Dsp.ReqVehInfo.Config.0006,1 */
  /** \brief Size in bytes of the VehInfoData */
  Dcm_DspVehInfoDataSizeType VehInfoDataSize;
}
Dcm_DspVehInfoDataType;

/*==================[internal function declarations]=============================================*/

/*==================[external constants]=========================================================*/

/*==================[internal data]==============================================================*/

/*==================[external data]==============================================================*/

/*==================[external function definitions]==============================================*/

/*==================[internal function definitions]==============================================*/
#endif /* ifndef DCM_REQUESTVEHICLEINFORMATION_CFG_H */
/*==================[end of file]================================================================*/
