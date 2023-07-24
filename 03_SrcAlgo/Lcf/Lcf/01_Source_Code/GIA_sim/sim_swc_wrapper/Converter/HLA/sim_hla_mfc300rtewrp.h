
/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hlar_ext.h"

/*****************************************************************************
  MACROS 
*****************************************************************************/
/* time of a line (including horizontal blanking) */
#define HLA_LINE_TIME_US (36.6666667f)
/* time of a single pixel */
#define HLA_PIXEL_TIME_US (0.0222222222222f)

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/
typedef struct
{
  /********************/
  /* input parameters */
  /********************/  
  CPAR_HLA_Parameter_t*              pCPar_HlaPar;                    /* coding parameters stored in special section on ICU: common hla parameter */
  CPAR_HLAR_Parameter_t*             pCPar_HlarPar;                   /* coding parameters stored in special section on ICU: hlar parameter */ 
  NVM_HLAR_LearningValues_t*         pNvm_SigLearningValues;
  FLSPImagerCharacteristicsRight_t*  pParPPAR_ImgCharRight;           /* Production parameter (PPAR) from ICU (Only needed for HLA simulation): imager characteristic of right imager (T1_Production, Actual_T2, Actual_T3, ...) */  
  FLSPResponseCurvePeriphery_t*      pParPPAR_RespCurveRight;         /* Production parameter (PPAR) from ICU (Only needed for HLA simulation): response curve measured during production 12 values */
  FLSPProductionIntrinsic_t*         pParPPAR_ProdIntrinsicRight;

  /*****************/
  /* input signals */
  /*****************/
  IcImageCharacteristics_t*          pSig_ImgCharOdd;                 /* current imager characteristics */
  IcStatisticalResults_t*            pSig_ImgStatResOdd;              /* imager statistical results */
  MonoCalibration_t*                 pSig_MonoCalibrationLaneImager;  /* mono calibration data */ /* NEW CALI */
  RTE_HLA_Signals_t*                 pSig_HlaSig;                     /* Bus signals from ICU: Hla specific ones */
  RTE_HLA_HeadlightState_t*          pSig_HeadlightState;             /* Bus signals from ICU: feedback from head lamps (only used in simulation right now) */
} reqHlaPrtList_t;

/*****************************************************************************
  LOCAL FUNCTIONS (DECLARATION)
*****************************************************************************/

/* SetReqPorts From HLAR Functions Declarations */
void HLA_SetReqPorts_frm_HLAR( reqHlaPrtList_t *pReqPorts, HLAR_t_RequiredInputs *pHLAR_InWrite);
static void HLA_SetReqPortsHLARParam(reqHlaPrtList_t *pReqPorts, HLAR_t_RequiredInputs *pHLAR_InWrite);
static void HLA_SetReqPortsHLARSig( reqHlaPrtList_t *pReqPorts, HLAR_t_RequiredInputs *pHLAR_InWrite);
static void HLA_SetReqPortsHLARParamCamParam( reqHlaPrtList_t *pReqPorts, HLAR_t_RequiredInputs *pHLAR_InWrite);
void HLA_SetReqPortsHLARParamSensorSocket( reqHlaPrtList_t *pReqPorts, HLAR_t_RequiredInputs *pHLAR_InWrite);
void HLA_SetReqPortsHLARParamSensorAngles( reqHlaPrtList_t *pReqPorts, HLAR_t_RequiredInputs *pHLAR_InWrite);
static void HLA_SetReqPortsHLARParamRGBLuxTable( reqHlaPrtList_t *pReqPorts, HLAR_t_RequiredInputs *pHLAR_InWrite);

static void HLA_SetReqPortsHLARSigAvl( reqHlaPrtList_t *pReqPorts, HLAR_t_RequiredInputs *pHLAR_InWrite);
static void HLA_SetReqPortsHLARSigImgState( reqHlaPrtList_t *pReqPorts, HLAR_t_RequiredInputs *pHLAR_InWrite);
static void HLA_SetReqPortsHLARSigHeadlightState( reqHlaPrtList_t *pReqPorts, HLAR_t_RequiredInputs *pHLAR_InWrite);
static void HLA_SetReqPortsHLARSigCaliOnline( reqHlaPrtList_t *pReqPorts, HLAR_t_RequiredInputs *pHLAR_InWrite);
static void HLA_SetReqPortsHLARSigDefPixList( reqHlaPrtList_t *pReqPorts, HLAR_t_RequiredInputs *pHLAR_InWrite);
static void HLA_SetReqPortsHLARSigTrafStyle( reqHlaPrtList_t *pReqPorts, HLAR_t_RequiredInputs *pHLAR_InWrite);
static void HLA_SetReqPortsHLARSigImgChar( reqHlaPrtList_t *pReqPorts, HLAR_t_RequiredInputs *pHLAR_InWrite);
static void HLA_SetReqPortsHLARSigImgRespCurve( reqHlaPrtList_t *pReqPorts, HLAR_t_RequiredInputs *pHLAR_InWrite);


static void HLA_SetSigStatus(reqHlaPrtList_t *pReqPorts, HLAR_t_RequiredInputs *pHLAR_InWrite);

