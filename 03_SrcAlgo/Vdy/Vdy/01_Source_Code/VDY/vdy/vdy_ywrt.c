/*! \file **********************************************************************

  COMPONENT:              VDY (Vehicle Dynamics Observer)

  MODULENAME:             vdy_ywrt.c

  @brief                  This module contains signal processing of yaw rate 
                          sensor providing its temperature

  VERSIONNUMBER:          $Revision: 1.7 $

*****************************************************************************/

/*****************************************************************************
  INCLUDES
*****************************************************************************/
/* PRQA S 0380 EOF */
/* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: No Risk */
#include "vdy.h"

#if (CFG_VDY_INT_GYRO)

/*****************************************************************************
  SYMBOLIC CONSTANTS
*****************************************************************************/
/* Yaw rate differentiator time constant */ 
#define VDY_YWRT_DIFF_FILT               ((fTime_t) 1.5)

/* Temperature differentiator time constant */
#define VDY_YWRT_TEMP_DIFF_FILT          ((fTime_t) 20.0)

/* Maximum yaw rate standard deviation during standstill observation */
#define VDY_YWRT_YWR_STD_DEV_MAX         DEG2RAD(0.15F)

/* Temperature table yaw rate scale factors */
#define VDY_YWRT_YWR_SCALE               (1.F/VDY_YWRT_YWR_INV_SCALE)     /* floating point  = scale * fixed point    */
#define VDY_YWRT_YWR_INV_SCALE           (1E4F)                           /* fixed point = inv_scale * floating point */

/* Temperature table confidence scale factors */
#define VDY_YWRT_CONF_SCALE              (1.F/VDY_YWRT_CONF_INV_SCALE)    /* floating point  = scale * fixed point    */
#define VDY_YWRT_CONF_INV_SCALE          (255.F)                          /* fixed point = inv_scale * floating point */

/* Minimum temperature of table node in degree celcius */
#define VDY_YWRT_TBL_MIN_TEMP            (-60L)

/* Maximum temperature of table node in degree celcius */
#define VDY_YWRT_TBL_MAX_TEMP            (+125L)

/* Temperature gap between table nodes */
#define VDY_YWRT_TBL_GAP                 (+5L)

/* First node of temperature table in degree celcius */
#define VDY_YWRT_FIRST_NODE_TEMP         ((f32_t) VDY_YWRT_TBL_MIN_TEMP)

/* Last node of temperature table in degree celcius */
#define VDY_YWRT_LAST_NODE_TEMP          ((f32_t) VDY_YWRT_TBL_MAX_TEMP)

/* Node width of temperature table in degree celcius */
#define VDY_YWRT_NODE_WIDTH              ((f32_t) VDY_YWRT_TBL_GAP)

/* Inverse node width of temperature table in 1/deg C */
#define VDY_YWRT_NODE_INV_WIDTH          (1.F/VDY_YWRT_NODE_WIDTH)

/* Maximum zero point offset of yaw rate sensor */
#define VDY_YWRT_YWR_MAX_OFFSET          (fYawRate_t) DEG2RAD(5.F)

/* Maximum yaw acceleration during standstill for calibration */
#define VDY_YWRT_YWR_GRAD_MAX            (fGradient_t) DEG2RAD(0.2F)

/* Confidence value to activate relearn */
#define VDY_YWRT_CONF_LEARN              (0.90F)

/* Confidence value to activate relearn */
#define VDY_YWRT_CONF_LEARN_ADJ          (0.58F)

/* Minimum weightning for new offset value */
#define VDY_YWRT_ALPHA_MIN               (0.2F) 

/* Maximum weighning for new offset value */
#define VDY_YWRT_ALPHA_MAX               (0.8F)

/* Maximum weighning for new offset value */
#define VDY_YWRT_ALPHA_VAL_MAX           (1.0F)

/* Delta for comparing confidences */
#define VDY_YWRT_ALPHA_DLT               (1E-5F)

/* Reduction factor for learning speed */
#define VDY_YWRT_RED_LEARN_SPEED        (6.F)
      
/* Confidence where update gain is reduced to normal gain */
#define VDY_YWRT_LEARN_SPEED_CONF_MIN   (0.01F)

/* Confidence where normal update gain is used */
#define VDY_YWRT_LEARN_SPEED_CONF_MAX   (0.20F)

/* Maximum confidence value */
#define VDY_YWRT_CONF_MAX                (1.F)

/* Maximum confidence value if current temperature is around node */
#define VDY_YWRT_CONF_MAX_NEAR           (1.F)

/* Maximum confidence value if current temperature is far from node */
#define VDY_YWRT_CONF_MAX_FAR            (0.6F)

/* Threshold deviation to activate relearning */
#define VDY_YWRT_LEARN_THRHD             ((fYawRate_t) DEG2RAD(0.15F))

/* Threshold deviation at far node to reset confidence of far node when above limit */
#define VDY_YWRT_LEARN_THRHD_FAR         ((fYawRate_t) DEG2RAD(0.5F))

/* Threshold deviation at near to reduce confidence of far node when below limit */
#define VDY_YWRT_LEARN_THRHD_NEAR        ((fYawRate_t) DEG2RAD(0.5F))

/* Maximum reasonable floating point resolution for offset confidence */
#define VDY_YWRT_CONF_DLTF               (1E-3F)

/* Maximum possible increase (innovation) of confidence per learn step */
#define VDY_YWRT_CONF_MAX_INNOV          (0.10F)

/* Number of learn cycles during vehicle standstill */
#define VDY_YWRT_MAX_LEARN_CNT           (6UL)

/* Maximum and minimal confidence values for fixed point presentation */
#define VDY_YWRT_CONF_RES_FXP             ((ui8_t) 1UL)   /* => 0.39 %  */
#define VDY_YWRT_OFFS_THRD_FXP            ((i16_t) 26L)   /* =>  0.15 deg/s */

/* Maximum confidence of table based offset type */
#define VDY_YWRT_TEMP_OFF_MAX_QUAL          (0.8F)
#define VDY_YWRT_TEMP_OFF_MAX_QUAL_COR      (1.0F / VDY_YWRT_TEMP_OFF_MAX_QUAL)

/* Factor to make internal yaw rate quality equal to external quality */
#define VDY_YWRT_TEMP_QUALITY_EQUAL_EXTERNAL   (0.75F/0.7F)


/*! Linear ramp nodes for confidency reduction of standstill offset due to temperature variation */
#define VDY_YWRT_TEMP_DRIFT_MAX            7.5F         /*!< Maximum temperature deviation in C */
#define VDY_YWRT_TEMP_DRIFT_MIN            1.5F         /*!< Minimum temperature deviation in C */
#define VDY_YWRT_MIN_RED_FAK               1.0F         /*!< Minimum confidence reduction factor  */
#define VDY_YWRT_MAX_RED_FAK               0.001F       /*!< Maximum confidence reduction factor  */

/*! Maximum change rate (with respect to cycle time) of offset during offse type change */
#define VDY_YWRT_OFFS_THRES                ((fYawRate_t) DEG2RAD(0.01F))

/*! Ensure that number of table nodes match with mininum and maximum temperature */
/* Check not possible due to VDY_YWRT_NO_NODES is no define */
/* #if ( ( ( (VDY_YWRT_TBL_MAX_TEMP-VDY_YWRT_TBL_MIN_TEMP)/VDY_YWRT_TBL_GAP)+1L) != VDY_YWRT_NO_NODES )
#error "Number of table nodes does not match with minium and maximum temperature"
#endif
*/

/*****************************************************************************
  MACROS
*****************************************************************************/

/* Helper macros to get access to data interfaces */
#define YWRT_GET_ME                   (&VDYYwrtGlobData)

#define YWRT_GET_DATA                 (&VDYYwrtGlobData.Sensor)
#define YWRT_GET_OFFS                 (&VDYYwrtGlobData.Offset) 

/* Conversion to yaw rate floating point representation */
/* <ln_offset:+1 MISRA Rule 19.7: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, this macro does simple calculations */
#define VDY_YWRT_NVM_YWR_FLP(x_)        ((f32_t)(x_) * VDY_YWRT_YWR_SCALE)
/* Conversion to yaw rate fixed point representation */
/* <ln_offset:+1 MISRA Rule 19.7: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, this macro does simple calculations */
#define VDY_YWRT_NVM_YWR_FXP(x_)        ((i16_t)(((x_) * VDY_YWRT_YWR_INV_SCALE) + 0.5F))

/* Conversion to confidence floating point representation */
/* <ln_offset:+1 MISRA Rule 19.7: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, this macro does simple calculations */
#define VDY_YWRT_NVM_CONF_FLP(x_)       ((f32_t)(x_) * VDY_YWRT_CONF_SCALE)
/* Conversion to confidence fixed point representation */
/* <ln_offset:+1 MISRA Rule 19.7: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, this macro does simple calculations */
#define VDY_YWRT_NVM_CONF_FXP(x_)       ((ui8_t)(((x_) * VDY_YWRT_CONF_INV_SCALE) + 0.5F))

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/
/* Offset overtake modes */
typedef enum {
  YWRT_OFFS_TAKE_NO      = 0UL,
  YWRT_OFFS_TAKE_LIMIT   = 1UL,
  YWRT_OFFS_TAKE_UNLIMIT = 2UL
} eYwrtTakeOvr_t;
/* <ln_offset:-1 PCLINT Error 751: reviewer name: Jochen Spruck date: 15-02-2011 reason: error only active in simulation, has no side effects*/

#if (CFG_USE_COMPACT_ENUMS)
typedef ui8_t YwrtTakeOvr_t;      /*!< using 8bit type for the real enum (32bit type) YwrtTakeOvr_t to save memory*/
#else
typedef eYwrtTakeOvr_t YwrtTakeOvr_t;
#endif

/*****************************************************************************
  VARIABLES
*****************************************************************************/


/*****************************************************************************
  LOCAL FUNCTION PROTOTYPES
*****************************************************************************/
STATIC_MTD void VDYwrtCalcOffset(const VDYYwrtSenData_t *pSen, const proVDYPrtList_t *proPorts, VDYYwrtOffsData_t *pOffs);
STATIC_MTD void VDYwrtCalcTblOffset(const VDYYwrtSenData_t *pSen, const proVDYPrtList_t *proPorts, VDYYwrtOffsTblData_t *pOffsTbl);
STATIC_MTD void VDYYwrtMergeOffset(VDYYwrtOffsData_t *pOffs, fYawRate_t offsTbl, fQuality_t confTbl);
STATIC_MTD void VDYYwrtCalcFinalOffset(const VDYYwrtSenData_t *pSen, VDYYwrtOffsData_t *pOffs);

STATIC_MTD void VDYYwrtCalcSensor(const reqVDYPrtList_t *reqPorts, VDYYwrtSenData_t *pSen);
STATIC_MTD bool_t VDYYwrtLearnValuePresent(const VDYNvYwrtLearnTable_t *pYwrTmpTbl);

STATIC_MTD void VDYYwrtGetTableNode(const VDYNvYwrtLearnTable_t *tbl, VDYYwrtLearnNode_t *ndInt);
STATIC_MTD void VDYYwrtSetTableNode(VDYNvYwrtLearnTable_t *tbl, const VDYYwrtLearnNode_t *ndInt);
STATIC_MTD void VDYYwrtCompletePendingWrites(VDYNvYwrtLearnTable_t *tbl);

STATIC_MTD void VDYYwrtInterpTable(const VDYNvYwrtLearnNode_t *node, const ui8_t *xi, i16_t *y_out, ui32_t len);

STATIC_MTD void VDYYwrtCommonInit(void);
STATIC_MTD void VDYYwrtOffsetInit( const proVDYPrtList_t *proPorts );
STATIC_MTD void VDYYwrtCalcOffsetTime(void);
STATIC_MTD void VDYYwrtCorrectTable(VDYNvYwrtLearnTable_t *pYwrTmpTbl);

STATIC_MTD void vdyYwrCalcToAutocode(VDYYwrtOffsData_t *Offs);


/*****************************************************************************
  VARIABLES
*****************************************************************************/
SET_MEMSEC_VAR(VDYYwrtGlobData)
STATIC_VAR VDYYwrtData_t  VDYYwrtGlobData;  /*!< @VADDR: 0x20017000 @VNAME: VDYYwrt @ALLOW: vdy_priv @cycleid: vdy_cycle_id*/


/* ***********************************************************************
  @fn               VDYwrtExec*/ /*!

  @brief            Determine operating sequence for vehicle dynamics observer

  @param[in]        reqPorts
  @param[in]        mif
  @param[in]        proPorts
  @return           void

  @pre              -
  @post             -
**************************************************************************** */
void VDYYwrtExec(const reqVDYPrtList_t *reqPorts, VDYModIf_t *mif, const proVDYPrtList_t *proPorts)
{
  YWRT_GET_ME->Io.mif = mif;

  /* Distinguish between different operating states */
  if (VDY_CTRL_GET_STATE(VDY_CTRL_STATE_RUNNING, reqPorts->pCtrl->CtrlMode)) {

    /*<--- Execution path for normal operating mode --->*/
    VDYYwrtSenData_t     *pSen   = YWRT_GET_DATA;  /* Yaw rate sensor related data */
    VDYYwrtOffsData_t    *pOffs  = YWRT_GET_OFFS;  /* Offset learning related data */

    /* Determine standstill flag for yaw rate offset compensation */
    /* <ln_offset:+2 MISRA Rule 10.3: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use*/
    pSen->StandstillOK = (bool_t) ((mif->LongMot.MotState.MotState == VDY_LONG_MOT_STATE_STDST) && 
                                   (mif->LongMot.MotState.Confidence > VDY_PAR_YWR_STST_CONF_MIN) ); 

    /* Start sensor signal processing */
    VDYYwrtCalcSensor(reqPorts, pSen);
    
    /* Start offset calculation */
    VDYwrtCalcOffset(pSen, proPorts, pOffs);
  }
  else {
    /*<--- Execution path for initialization mode  --->*/
    VDYYwrtCommonInit();
  }

  /* Update offset times */
  VDYYwrtCalcOffsetTime();

  /* Fill the autocode interface */
  vdyYwrCalcToAutocode(YWRT_GET_OFFS);

  return;
}


/* ***********************************************************************
  @fn               VDYYwrtInit*/ /*!

  @brief            initialize module data

  @description       
  @param[in]        proPorts
  @return           void

  @pre              -
  @post             -
**************************************************************************** */
void VDYYwrtInit( const proVDYPrtList_t *proPorts )
{

  VDYYwrtCommonInit();
  VDYYwrtOffsetInit(proPorts);

  return;
}


/* ***********************************************************************
  @fn                     vdyYwrCalcToAutocode */ /*!
  @brief                  Fill the interfact to the autocode

  @description

  @param[in]              Offs
  @param[out]             -
  @return                 void

  @pre                    -
  @post                   -

  @author                 J.Spruck
**************************************************************************** */
STATIC_MTD void vdyYwrCalcToAutocode(VDYYwrtOffsData_t *Offs)
{
    Offs->ToAutocode.OffsData.quality = Offs->Quality;
    Offs->ToAutocode.OffsData.var    = 0.000000001F;

    /* Detection of yaw rate offset changes */
#if (CFG_VDY_EX_YWR_NVM)
    if (   ( (Offs->OffsElpsdTime < (fTime_t) 1.0F) && (Offs->OffsType == (VDYYwrOffsType_t) OFFS_STANDST) )
        || ( (Offs->OffsType==(VDYYwrOffsType_t) OFFS_TEMPER_TABLE) || (Offs->OffsType==(VDYYwrOffsType_t) OFFS_DYN_APPRX)  || (Offs->OffsType==(VDYYwrOffsType_t) OFFS_STANDST_EEPROM) )
        || ( YWRT_GET_ME->Io.mif->FirstCycleDone == FALSE )  ) {
#else
    if (   ((Offs->OffsElpsdTime < (fTime_t) 1.0F) && (Offs->OffsType == (VDYYwrOffsType_t) OFFS_STANDST) )
        || ( (Offs->OffsType==(VDYYwrOffsType_t) OFFS_TEMPER_TABLE) || (Offs->OffsType==(VDYYwrOffsType_t) OFFS_DYN_APPRX) )
        || ( VDY_IS_FIRST_CYCLE_DONE() == FALSE ) ) {
#endif
      /* new offset was taken */
      /* set state */
      if (Offs->OffsType == (VDYYwrOffsType_t) OFFS_STANDST_EEPROM) {
        /* state 2 = EEPROM offset */
        Offs->ToAutocode.OffsData.state = 2U;
      }
      else {
        /* state = 1 -> set dynamic offset to stand still offset */
        Offs->ToAutocode.OffsData.state = 1U;
      }
      Offs->ToAutocode.OffsData.offset = Offs->YawRateOffset;
    }
    else {
      if (Offs->OffsType == (VDYYwrOffsType_t)OFFS_NON) {
        /* state = 3 -> yaw stand still offset never ever estimated */
        Offs->ToAutocode.OffsData.offset = 0.0F;
        Offs->ToAutocode.OffsData.state = 3U;
      }
      else {
        Offs->ToAutocode.OffsData.state = 0U;
      }
    }

    /* Check if the offset is a dynamic offset and set the dynamic flag */
    if  ((Offs->OffsType!=(VDYYwrOffsType_t) OFFS_DYN_INTER ) && (Offs->OffsType!=(VDYYwrOffsType_t) OFFS_DYN_AVG)){
      Offs->ToAutocode.IsDynamic = FALSE;
    }
    else {
      Offs->ToAutocode.IsDynamic = TRUE;
    }
}


/* ***********************************************************************
  @fn               VDYYwrInitTableOffset */ /*!
  @brief            Initialize offset data

  @description      see brief description

  @param[in]        pOffsTbl
  @param[out]       -
  @return           void

  @pre              -
  @post             -
**************************************************************************** */
STATIC_MTD void VDYYwrInitTableOffset(VDYYwrtOffsTblData_t *pOffsTbl)
{
  pOffsTbl->bWrLeft  = FALSE;
  pOffsTbl->bWrRight = FALSE;
  
  pOffsTbl->LearnCnt      = (ui16_t) 0;
  pOffsTbl->LearnAgainCnt = (ui16_t) 0;
  pOffsTbl->LastOffsTemp  = 0.F;

  pOffsTbl->Offset   = 0.F;
  pOffsTbl->Conf     = 0.F;
  pOffsTbl->Valid    = FALSE;
  pOffsTbl->Checked  = FALSE;

  pOffsTbl->Left.Conf     = 0.F;
  pOffsTbl->Left.Offset   = 0.F;
  pOffsTbl->Left.No       = (ui8_t) 0;

  pOffsTbl->Right.Conf     = 0.F;
  pOffsTbl->Right.Offset   = 0.F;
  pOffsTbl->Right.No       = (ui8_t) 0;

  vdyStatIntervalInit(&pOffsTbl->SmpYwRt);
  vdyStatIntervalInit(&pOffsTbl->SmpTemp);
  
  return;
}


/* ***********************************************************************
  @fn               VDYYwrtOffsetInit */ /*!
  @brief            Initialize offset data

  @description      see brief description

  @param[in]        -
  @param[out]       -
  @return           void

  @pre              -
  @post             -
**************************************************************************** */
STATIC_MTD void VDYYwrtOffsetInit( const proVDYPrtList_t *proPorts )
{
  VDYYwrtOffsData_t *pOffs = YWRT_GET_OFFS;
  VDYYwrtOffsTblData_t   *pOffsTbl  = &(pOffs->Tbl);     /* Offset data   */
  VDYYwrStandStillOffs_t *pOffsStSt = &(pOffs->StSt);

  if ( proPorts->pYwrtTempTable != (void *)0) {
    /* <ln_offset:+2 PCLINT Error 835: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, bit shift temp table mask */
    /* <ln_offset:+1 MISRA Rule 1.2: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, clear all the temp table states (bitmask) */
    VDY_YWRT_CLEAR_ALL(proPorts->pYwrtTempTable->statRd);
    /* <ln_offset:+2 PCLINT Error 835: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, bit shift temp table mask */
    /* <ln_offset:+1 MISRA Rule 1.2: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, clear all the temp table states (bitmask) */
    VDY_YWRT_CLEAR_ALL(proPorts->pYwrtTempTable->statWr);
    /* <ln_offset:+2 PCLINT Error 835: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, bit shift temp table mask */
    /* <ln_offset:+1 MISRA Rule 1.2: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, clear all the temp table states (bitmask) */
    VDY_YWRT_CLEAR_ALL(proPorts->pYwrtTempTable->statWrpd);
    proPorts->pYwrtTempTable->cntWr = 0x0UL;
    proPorts->pYwrtTempTable->prodOffset = VDY_YWRT_PROD_OFFSET_SNA;
  }

  pOffs->MaxQuality    = 0.F;
  pOffs->Quality       = 0.F;
  pOffs->confStSt      = 0.F;
  pOffs->confTbl       = 0.F;
  pOffs->OffsType      = (VDYYwrOffsType_t)OFFS_NON;
  pOffs->OffsElpsdTime = 0.F;
  pOffs->YawRateOffset = 0.F;
  pOffs->Temperature   = 0.F;

  /* Initialize offset table data */
  VDYYwrInitTableOffset(pOffsTbl);
  
  /* Initialize standstill offset data */
  vdyYwrInitStandStillOffset(pOffsStSt);

  return;
}


/* ***********************************************************************
  @fn               VDYYwrtCommonInit */ /*!
  @brief            Initialize non offset data

  @description      see brief description

  @param[in]        -
  @param[out]       -
  @return           void

  @pre              -
  @post             -
**************************************************************************** */
STATIC_MTD void VDYYwrtCommonInit(void)
{
  VDYYwrtSenData_t  *pSen   = YWRT_GET_DATA;

  pSen->Gradient         = 0.F;
  pSen->StandstillOK     = FALSE;
  pSen->Valid            = FALSE;
  pSen->YawRate          = 0.F;
  pSen->YawRateOld       = 0.F;
  pSen->YwFirstCycleDone = FALSE;
  pSen->Tempr            = 0.F;
  pSen->TemprOld         = 0.F;
  pSen->obsOffs          = FALSE;

  return;
}


/* ***********************************************************************
  @fn                     VDYYwrtCalcOffsetTime */ /*!
  @brief                  Calculate time since last standstill calibration

  @description            see brief description

  @param[in]              -
  @param[out]             -
  @return                 void

  @pre                    -
  @post                   -
**************************************************************************** */
STATIC_MTD void VDYYwrtCalcOffsetTime(void)
{
  fTime_t            CycleTime; 
  VDYYwrtOffsData_t  *OffsData = YWRT_GET_OFFS;

  /* Get cycle time */
  CycleTime = vdyGetCycleTime();

  /* Calculate time since last offset calibration */
  if( OffsData->OffsElpsdTime >= YWR_OFFS_ELPSD_TIME_MAX ) {
    OffsData->OffsElpsdTime = YWR_OFFS_ELPSD_TIME_MAX;
  } 
  else {
    OffsData->OffsElpsdTime += CycleTime;
  }
  return;
}


/* ***********************************************************************
  @fn               VDYYwrtCalcSensor */ /*!
  @brief            Calculate yaw rate sensor signals

  @description      see brief description

  @param[in]        -
  @param[out]       -
  @return           void

  @pre              -
  @post             -
**************************************************************************** */
STATIC_MTD void VDYYwrtCalcSensor(const reqVDYPrtList_t *reqPorts, VDYYwrtSenData_t *pSen)
{
  pSen->obsOffs = FALSE;
  
  if (  (VDY_GET_IO_STATE(VDY_SIN_POS_YWRINT, reqPorts->pVehicleInputSignals->VehSigMain.State)==VDY_IO_STATE_VALID )
     && (VDY_GET_IO_STATE(VDY_SIN_POS_YWRINT_TEMP, reqPorts->pVehicleInputSignals->VehSigMain.State)==VDY_IO_STATE_VALID ) ){
    
    /* Sample input data */
    pSen->Valid   = TRUE;
    pSen->YawRate = reqPorts->pVehicleInputSignals->VehSigMain.YawRateInt;
    pSen->Tempr   = reqPorts->pVehicleInputSignals->VehSigMain.YawRateIntTemp;
    
    /* Calculate yaw rate acceleration */
    pSen->Gradient = vdyDifferentiateCycleTime(pSen->YawRate, pSen->YawRateOld, pSen->Gradient, VDY_YWRT_DIFF_FILT);
    
    /* Calculate temperature gradient */
    pSen->TempGrad = vdyDifferentiateCycleTime(pSen->Tempr, pSen->TemprOld, pSen->TempGrad, VDY_YWRT_TEMP_DIFF_FILT);

    /* Determine observabilty of yaw rate zero point offset */
    if (pSen->StandstillOK != FALSE) {
      if (   (fABS(pSen->YawRate) < VDY_YWRT_YWR_MAX_OFFSET) 
          && ((pSen->Tempr >= VDY_YWRT_FIRST_NODE_TEMP) && (pSen->Tempr <= VDY_YWRT_LAST_NODE_TEMP)) 
          && (fABS(pSen->Gradient) < VDY_YWRT_YWR_GRAD_MAX )  )  {
        pSen->obsOffs = TRUE;
      }
    }
    /* Save values for next cycles */
    pSen->YawRateOld = pSen->YawRate;
    pSen->TemprOld   = pSen->Tempr;
    pSen->YwFirstCycleDone = TRUE;
  }
  else {
    /* Init sensor related signal data */
    pSen->Valid      = FALSE;
    pSen->YawRate    = 0.F;
    pSen->YawRateOld = 0.F;
    pSen->Tempr      = 0.F;
    pSen->TemprOld   = 0.F;
  }
  return;
}


/* ***********************************************************************
  @fn                     VDYwrtCalcOffset */ /*!
  @brief                  Calculate yaw rate offset

  @description            see brief description

  @param[in]              Yaw rate sensor, yaw rate offset
  @param[out]             yaw rate offset
  @return                 void

  @pre                    -
  @post                   -
**************************************************************************** */
STATIC_MTD void VDYwrtCalcOffset(const VDYYwrtSenData_t *pSen, const proVDYPrtList_t *proPorts, VDYYwrtOffsData_t *pOffs)
{
  pOffs->StSt.Observable   = pSen->obsOffs;
  pOffs->StSt.StandstillOK = pSen->StandstillOK;
  
  /* Run standstill offset estimation */  
  vdyYwrEstStandstillOffset(pSen->YawRate,pSen->Valid, &pOffs->StSt);
  
  /* Run standstill offset table learning */
  VDYwrtCalcTblOffset(pSen, proPorts, &pOffs->Tbl);

  /* Calculate output offset */
  VDYYwrtCalcFinalOffset(pSen, pOffs);

  return;
}


/* ***********************************************************************
  @fn                     VDYYwrtCalcFinalOffset */ /*!
  @brief                  Calculate final yaw rate offset

  @description            see brief description

  @param[in]              yaw rate sensor
  @param[out]             yaw rate offset
  @return                 void

  @pre                    -
  @post                   -
**************************************************************************** */
STATIC_MTD void VDYYwrtCalcFinalOffset(const VDYYwrtSenData_t *pSen, VDYYwrtOffsData_t *pOffs)
{
  VDYYwrtOffsTblData_t   *pOffsTbl  = &pOffs->Tbl;
  VDYYwrStandStillOffs_t *pOffsStSt = &pOffs->StSt;
  
  fTemperature_t currTemp;
  fTemperature_t absDiffTemp;
  
  fConfidence_t  tblConf;
  fYawRate_t     tblOffs;

  currTemp = pSen->Tempr;
  
  /* Limit maximum confidence of table offset */
  tblConf  = pOffsTbl->Conf * VDY_YWRT_TEMP_OFF_MAX_QUAL; 
  tblOffs  = pOffsTbl->Offset;
  
  /* If current standstill offset confidence is greater than confidence from previous 
     standstill offset, take over new offset. In case of no standstill, max quality of 
     standstill offset is equal zero */
  if (pOffsStSt->MaxQuality >= pOffs->confStSt ) {

    /* Current standstill offset is more confident than prior one. Save standstill offset
       environmental data */

    /* Save confidence reached during standstill calibration */
    pOffs->MaxQuality = pOffsStSt->MaxQuality;

    /* Save confidence derived from table reached during standstill calibration */
    pOffs->confTbl = tblConf;

    /* Save temperature during standstill calibration */
    pOffs->Temperature = currTemp;

    /* Save table offset during standstill offset take over */
    pOffs->YwRtTblOffsStSt = tblOffs;

    /* Reset offset time during last standstill offset take over */
    pOffs->OffsElpsdTime = 0.F;
  }
  
  /* Merge standstill offset and table correction offset */
  VDYYwrtMergeOffset(pOffs, tblOffs, tblConf);

  /* Temperature drift since last standstill calibration */
  absDiffTemp = fABS(currTemp - pOffs->Temperature);

  /* Reduce confidence in dependence of temperature drift */
  pOffs->confStSt = pOffs->MaxQuality * vdyLFunction( absDiffTemp, VDY_YWRT_TEMP_DRIFT_MIN, VDY_YWRT_TEMP_DRIFT_MAX,
                                                                   VDY_YWRT_MIN_RED_FAK,    VDY_YWRT_MAX_RED_FAK);
  return;
}


/* ***********************************************************************
  @fn                     VDYYwrtTakeOffset */ /*!
  @brief                  Take new offset value

  @description            see brief description

  @param[in]              take over mode, new offset value, old offset value
  @param[out]             new offset value
  @return                 void

  @pre                    -
  @post                   -
**************************************************************************** */
STATIC_MTD void VDYYwrtTakeOffset(YwrtTakeOvr_t tkOvr, fYawRate_t offsNew, fYawRate_t *offsOldOut)
{
  switch(tkOvr) {
    case YWRT_OFFS_TAKE_LIMIT: {
      *offsOldOut = MINMAX_FLOAT(*offsOldOut - VDY_YWRT_OFFS_THRES, *offsOldOut + VDY_YWRT_OFFS_THRES, offsNew);
    } break;

    case YWRT_OFFS_TAKE_UNLIMIT: {
      *offsOldOut = offsNew;
    } break;

    default: 
    case YWRT_OFFS_TAKE_NO: {
    } break;
  }
  return;
}


/* ***********************************************************************
  @fn                     VDYYwrtMergeOffset */ /*!
  @brief                  Merge standstill offset and table based yaw rate offset 

  @description            see brief description

  @param[in]              Offset data
  @param[in]              Table offset data
  @param[out]             Final yaw rate offset with confidence
  @return                 void

  @pre                    -
  @post                   -
**************************************************************************** */
STATIC_MTD void VDYYwrtMergeOffset(VDYYwrtOffsData_t *pOffs, fYawRate_t offsTbl, fQuality_t confTbl)
{
  YwrtTakeOvr_t tkOvr = (YwrtTakeOvr_t)YWRT_OFFS_TAKE_NO;

  if (  (pOffs->StSt.MaxQuality > 0.F) 
      ||(pOffs->confTbl > 0.F) ) {

    if (pOffs->StSt.StandstillOK == FALSE) {
      /* Limit gradient of offset changes during driving */
      tkOvr = (YwrtTakeOvr_t)YWRT_OFFS_TAKE_LIMIT;
    }
    else {
      /* Take over with no limitation if new standstill or table offset has more confidence */
      if (  (pOffs->StSt.MaxQuality >= pOffs->confStSt)  
          ||(pOffs->confStSt < confTbl) ) {
        tkOvr = (YwrtTakeOvr_t)YWRT_OFFS_TAKE_UNLIMIT;
      }
    }
  }
  
  /* Offset change required */
  if (tkOvr != (YwrtTakeOvr_t)YWRT_OFFS_TAKE_NO) {

    /* Selection of offset type */
    if (   (pOffs->MaxQuality >= VDY_YWR_OFF_STST_CALC_TIME_Q_MAX ) 
        && (pOffs->confTbl    >= VDY_YWRT_TEMP_OFF_MAX_QUAL) 
        && (confTbl >= VDY_YWRT_TEMP_OFF_MAX_QUAL)) {
       
      /* Standstill, table offset learned during standstill and current interpolated table offset has maximum 
         confidence */
      fYawRate_t newOffs;

      /* Update current active offset type */
      pOffs->OffsType = (VDYYwrOffsType_t)OFFS_DYN_APPRX;

      /* Set confidence to maximum value */
      pOffs->Quality = VDY_YWR_OFF_STST_CALC_TIME_Q_MAX;

      /* Use offset table to adapt last standstill offset */
      newOffs = pOffs->StSt.YawRateOffset + (offsTbl - pOffs->YwRtTblOffsStSt);

      /* Take adapted standstill offset value */
      VDYYwrtTakeOffset(tkOvr, newOffs, &pOffs->YawRateOffset);
    }
    else if (pOffs->confStSt >= confTbl) {

      /* Confidence of last calibrated standstill is better than current table offset */

      /* Update current active offset type */
      pOffs->OffsType = (VDYYwrOffsType_t)OFFS_STANDST;

      /* Use temperature adapted confidence of last standstill offset */
      pOffs->Quality = pOffs->confStSt;

      /* Take last standstill offset value */
      VDYYwrtTakeOffset(tkOvr, pOffs->StSt.YawRateOffset, &pOffs->YawRateOffset);
    }
    else {
      /* Current table offset is better than last calibrated standstill offset */

      /* Update current active offset type */
      pOffs->OffsType = (VDYYwrOffsType_t)OFFS_TEMPER_TABLE;

      /* Use confidence of table interpolated offset */
      pOffs->Quality = confTbl;

      /* Take table offset value */
      VDYYwrtTakeOffset(tkOvr, offsTbl, &pOffs->YawRateOffset);
    }
  }

  /* Modify the output quality, FR:32207 
  Increase (internal gyro) offset confidence by factor
     -> 1/0.8    (Remove lowering in caes of temp table offset) and  
     -> 0.75/0.7 (Adapt confidence value to equivalent to external gyro offset compensation) */
  pOffs->Quality = MIN_FLOAT(pOffs->Quality * VDY_YWRT_TEMP_OFF_MAX_QUAL_COR * VDY_YWRT_TEMP_QUALITY_EQUAL_EXTERNAL, 1.0F);

  return;
} 


/* ***********************************************************************
  @fn               VDYYwrtGetNodesOfInterest */ /*!
  @brief            Get working nodes according to current temperature 
                    operating point

  @description      see brief description

  @param[in]        tempr
  @param[in]        pTbl
 
  @param[out]       pOffs Offset-Data
  @return           void

  @pre              -
  @post             -
**************************************************************************** */
STATIC_MTD void VDYYwrtGetNodesOfInterest(fTemperature_t tempr, const VDYNvYwrtLearnTable_t *pTbl, VDYYwrtOffsTblData_t *pOffs)
{ 
  ui8_t Left, Right;
  
  /* Determine number of left (lower) temperature node */
  /* <ln_offset:+1 MISRA Rule 10.4: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, find index position*/
  Left = (ui8_t) ((tempr - VDY_YWRT_FIRST_NODE_TEMP) * VDY_YWRT_NODE_INV_WIDTH);

  /* Determine number of right (higher) temperature node */		
  /* <ln_offset:+1 PCLINT Error 912: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use */
  Right = (ui8_t) ((ui32_t) Left + 1UL);

  /* Update left node number */
  pOffs->Left.No = Left;

  /* Update right node number */		
  pOffs->Right.No = Right;

  /* Copy left node offset data from learning table */
  VDYYwrtGetTableNode(pTbl, &pOffs->Left);

  /* Copy right node offset data form learning table */
  VDYYwrtGetTableNode(pTbl, &pOffs->Right);

  return;
}


/* ***********************************************************************
  @fn               VDYYwrtMeasUpdateNode */ /*!
  @brief            Update offset table node with current measurement

  @description      see brief description

  @param[in]        gain, measured offset value, measurement confidence
  @param[out]       offset table node
  @return           void

  @pre              -
  @post             -
**************************************************************************** */
STATIC_MTD void VDYYwrtMeasUpdateNode(VDYYwrtLearnNode_t *node, f32_t gain, f32_t meas, f32_t conf)
{
  const f32_t redGain_c = (1.F / VDY_YWRT_RED_LEARN_SPEED);
  
  f32_t gainOffs;
  f32_t gainConf = gain * redGain_c;
  f32_t dConf = conf - node->Conf;

  /* Speed transient effect during first update values */
  if (node->Conf < VDY_YWRT_LEARN_SPEED_CONF_MIN ) {
    /* First learn value in application field, use full weight */
    gainOffs = gain;
  }
  else {
    gainOffs = gain * vdyLFunction(node->Conf, VDY_YWRT_LEARN_SPEED_CONF_MIN, VDY_YWRT_LEARN_SPEED_CONF_MAX,
                                               0.8F,                          redGain_c);
  }
  
  /* Limit minimum and maximal confidence increase per learn iteration */
  if (dConf > C_F32_DELTA) {
    
    /* Limit the maximum possible increase */
    if ( (gainConf * (conf - node->Conf)) > VDY_YWRT_CONF_MAX_INNOV ) {
      gainConf = VDY_YWRT_CONF_MAX_INNOV / dConf;
    }

    /* Limit the minimum possible increase to table resolution */
    if ( (gainConf * (conf - node->Conf)) < VDY_YWRT_CONF_SCALE ) {
      gainConf = VDY_YWRT_CONF_SCALE / dConf;
    }
  }

  /* Update node values */
  node->Offset  = ((1.0F - gainOffs) * node->Offset)  + (gainOffs * meas);
  node->Conf    = ((1.0F - gainConf) * node->Conf)    + (gainConf * conf);

  return;
}

/* ***********************************************************************
  @fn               VDYYwrtCalcOffsTblCurr */ /*!
  @brief            Calculate current yaw rate offset based on offset table

  @description      see brief description


  @return           void
  @param[in]        offset table, temperature
  @param[out]       offset

  @pre              -
  @post             -
**************************************************************************** */
STATIC_MTD void VDYYwrtCalcOffsTblCurr(const VDYNvYwrtLearnTable_t *nvTbl, fTemperature_t currTempr, VDYYwrtOffsTblData_t *pOffs)
{
  VDYYwrtLearnNode_t CurrLeft, CurrRight;
  fTemperature_t tblTempr;
  fYawRate_t ipOffs;
  fConfidence_t  ipConf;
  f32_t currAlpha;
  
  /* Limit current temperature to offset correction table range */
  tblTempr = MINMAX_FLOAT(VDY_YWRT_FIRST_NODE_TEMP, VDY_YWRT_LAST_NODE_TEMP, currTempr);

  /* Determine left node number */
  /* <ln_offset:+1 MISRA Rule 10.4: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, find index position*/
  CurrLeft.No = (ui8_t) ((tblTempr - VDY_YWRT_FIRST_NODE_TEMP) * VDY_YWRT_NODE_INV_WIDTH);

  /* Determine right node number */
  /* <ln_offset:+1 PCLINT Error 912: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use */
  CurrRight.No = (ui8_t) ((ui32_t) CurrLeft.No + 1UL);

  /* Select determined nodes */
  VDYYwrtGetTableNode(nvTbl, &CurrLeft);
  VDYYwrtGetTableNode(nvTbl, &CurrRight);

  /* Calculate normalized distance with respect to left node */
  currAlpha =  (tblTempr - (VDY_YWRT_FIRST_NODE_TEMP + ((f32_t)CurrLeft.No * VDY_YWRT_NODE_WIDTH))) * VDY_YWRT_NODE_INV_WIDTH;

  /* Interpolate offset and confidence values */
  ipOffs    = CurrLeft.Offset  + (currAlpha * (CurrRight.Offset - CurrLeft.Offset));
  ipConf    = CurrLeft.Conf    + (currAlpha * (CurrRight.Conf   - CurrLeft.Conf));
  
  /* Fill offset interface */
  pOffs->Offset = ipOffs;
  pOffs->Conf   = ipConf;
  pOffs->Valid  = VDYYwrtLearnValuePresent(nvTbl);

  return;
}

/* ***********************************************************************
  @fn               VDYYwrtInitWithFirstLearnValue */ /*!
  @brief            Initialize all nodes with first standstill offset if 
                    no learn value is saved in nvm table

  @description      see brief description

  @param[in]        offset value
  @param[in,out]    offset table
  @return           void

  @pre              -
  @post             -
**************************************************************************** */
STATIC_MTD void VDYYwrtInitWithFirstLearnValue(VDYNvYwrtLearnTable_t *pYwrTmpTbl, fYawRate_t offset)
{
  if (VDYYwrtLearnValuePresent(pYwrTmpTbl) == FALSE) {
    /* No learn value is present */
    ui32_t idx;
      
    /* Set all nodes to offset value  */
    for (idx=0UL; idx < VDY_YWRT_NO_NODES; idx++) {
      /* <ln_offset:+1 MISRA Rule 10.4: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, rounding */
      pYwrTmpTbl->Node[idx].Offset  = VDY_YWRT_NVM_YWR_FXP(offset);
      pYwrTmpTbl->Node[idx].Conf    = VDY_YWRT_CONF_RES_FXP;
    }
    /* Set write flag for all table nodes */
    /* <ln_offset:+3 PCLINT Error 912: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, clear all the temp table states (bitmask) */
    /* <ln_offset:+2 MISRA Rule 1.2: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, clear all the temp table states (bitmask) */
    /* <ln_offset:+1 MISRA Rule 10.1: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, clear all the temp table states (bitmask)  */
    VDY_YWRT_NODES_MASK_ALL(pYwrTmpTbl->statWr);

    /* Clear pending writes for all nodes */
    /* <ln_offset:+5 PCLINT Error 912: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, clear all the temp table states (bitmask) */
    /* <ln_offset:+4 PCLINT Error 845: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, clear all the temp table states (bitmask) */
    /* <ln_offset:+3 PCLINT Error 835: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, clear all the temp table states (bitmask) */
    /* <ln_offset:+2 MISRA Rule 1.2: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, clear all the temp table states (bitmask) */
    /* <ln_offset:+1 MISRA Rule 10.1: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, clear all the temp table states (bitmask) */
    VDY_YWRT_NODES_CLEAR_ALL(pYwrTmpTbl->statWrpd);
  }
  return;
}



/* ***********************************************************************
  @fn               VDYYwrtFillUnlearnedNodes */ /*!

  @brief            Fill unlearned nodes located between learned nodes by
                    interpolation
  @description      see brief description

  @param[in]        offset table
  @param[in]        temperature table
  @param[out]       offset
  @return           void

  @pre              -
  @post             -
**************************************************************************** */
STATIC_MTD void VDYYwrtFillUnlearnedNodes(const VDYYwrtOffsTblData_t *pOffsTbl, VDYNvYwrtLearnTable_t *pYwrTmpTbl)
{
  i32_t ndLowStart;
  i32_t ndHighStart;
  VDYNvYwrtLearnNode_t *node = pYwrTmpTbl->Node;
  i32_t offsIntp;
  i32_t offsDelta;

  /* Select node to start interpolation towards lower higher temperature nodes */
  if ( (pOffsTbl->bWrLeft != FALSE) && (pOffsTbl->bWrRight != FALSE) ) {
    /* Two nodes have been updated */
    ndLowStart  = (i32_t)pOffsTbl->Left.No;
    ndHighStart = (i32_t)pOffsTbl->Right.No;
  }
  else if ( (pOffsTbl->bWrLeft != FALSE) && (pOffsTbl->bWrRight == FALSE) ) {
    /* One node has been updated */
    ndLowStart  = (i32_t)pOffsTbl->Left.No;
    ndHighStart = (i32_t)pOffsTbl->Left.No;
  }
  else if ( (pOffsTbl->bWrLeft == FALSE) && (pOffsTbl->bWrRight != FALSE) ) {
    /* One node has been updated */
    ndLowStart  = (i32_t)pOffsTbl->Right.No;
    ndHighStart = (i32_t)pOffsTbl->Right.No;
  }
  else {
    /* No update has arisen */
    ndLowStart  = 0L;
    ndHighStart = (i32_t) VDY_YWRT_NO_NODES - 1L;
  }
  
  /* Update nodes towards lower temperature */
  if ( ndLowStart > 0L) {
    /* There are nodes below start node */
    
    i32_t ndLowEnd = -1L;  /* Nearest node in lower direction with enough confidence */
    i32_t idxNd;
    
    /* Step down nodes as long as node is located with enough confidence */
    for ( idxNd = ndLowStart - 1L; (idxNd >= 0L) && (ndLowEnd < 0L); idxNd--) {
      if ( node[idxNd].Conf > VDY_YWRT_CONF_RES_FXP ) {
        ndLowEnd = idxNd;
      }
    }

    /* If located node is not adjacent to updated node start filling */
    if ( ndLowEnd < (ndLowStart - 1L) ) {
      /* If no node was located with enough confidence, interpolation is not possible */
      if (ndLowEnd < 0L) {
        /* Zero delta, no interpolation */
        offsDelta = 0;
      }
      else {
        /* Calculate delta per node derived by linear interpolation between start and end nodes */
        /* <ln_offset:+1 MISRA Rule 10.3: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use*/
        offsDelta = ((i32_t)(node[ndLowEnd].Offset - node[ndLowStart].Offset) / (ndLowStart - ndLowEnd));
      }
      
      /* Initialize fill with start node */
      offsIntp = node[ndLowStart].Offset;

      /* Fill nodes between start and end node */
      for (idxNd = ndLowStart - 1L; idxNd > ndLowEnd; idxNd--) {
        i32_t diff;

        /* Update interpolation value for current node */
        offsIntp += offsDelta;

        /* Calculate difference between current table node and potential new value */
        diff =  offsIntp - (i32_t) node[idxNd].Offset;

        /* Only update node if there is a significant difference */
        /* <ln_offset:+1 PCLINT Error 912: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use */
        if ( ABS(diff) > VDY_YWRT_OFFS_THRD_FXP ) {
          /* Update node, but leave confidence untouched */
          node[idxNd].Offset = (i16_t) offsIntp;
          /* <ln_offset:+2 PCLINT Error 912: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, set temp table state */
          /* <ln_offset:+1 MISRA Rule 10.1: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, set temp table state */
          VDY_YWRT_NODE_SET_VALID(idxNd, pYwrTmpTbl->statWrpd);
        }
      }
    }
  }

  /* Update nodes towards higher temperature */
  /* <ln_offset:+1 PCLINT Error 912: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use */
  if ( ndHighStart < (i32_t)(VDY_YWRT_NO_NODES - 1UL) ) {

    i32_t ndHighEnd = (i32_t) VDY_YWRT_NO_NODES; /* Nearest node in higher direction with enough confidence */
    i32_t ii;
    
    /* Step up nodes as long as node is located with enough confidence */
    /* <ln_offset:+1 PCLINT Error 912: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use */
    for (ii = ndHighStart + 1L; (ii < (i32_t) VDY_YWRT_NO_NODES) && (ndHighEnd > (i32_t)(VDY_YWRT_NO_NODES - 1UL) ); ii++) {
      if ( node[ii].Conf > VDY_YWRT_CONF_RES_FXP ) {
        ndHighEnd = ii;
      }
    }

    /* If located node is not adjacent to updated node start filling */
    if (ndHighEnd > (ndHighStart + 1L)) {
      /* If no node was located with enough confidence, interpolation is not possible */
      /* <ln_offset:+1 PCLINT Error 912: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use */
      if (ndHighEnd > (i32_t) (VDY_YWRT_NO_NODES - 1UL)) {
        /* Zero delta, no interpolation */
        offsDelta = 0;
      }
      else {
        /* Calculate delta per node derived by linear interpolation between start and end nodes */
        /* <ln_offset:+1 MISRA Rule 10.3: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use*/
        offsDelta = ((i32_t)(node[ndHighEnd].Offset - node[ndHighStart].Offset) / (ndHighEnd - ndHighStart));
      }
      
      /* Initialize fill with start node */
      offsIntp = node[ndHighStart].Offset;

      /* Fill nodes between start and end node */
      for (ii = ndHighStart + 1L; ii < ndHighEnd; ii++) {
        i32_t diff;

        /* Update interpolation value for current node */
        offsIntp += offsDelta;

        /* Calculate difference between current table node and potential new value */
        diff =  offsIntp - (i32_t) node[ii].Offset;

        /* Only update node if there is a significant difference */
        /* <ln_offset:+1 PCLINT Error 912: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use */
        if ( ABS(diff) > VDY_YWRT_OFFS_THRD_FXP ) {
          node[ii].Offset = (i16_t) offsIntp;
          /* <ln_offset:+2 PCLINT Error 912: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, set temp table state */
          /* <ln_offset:+1 MISRA Rule 10.1: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, set temp table state */
          VDY_YWRT_NODE_SET_VALID(ii, pYwrTmpTbl->statWrpd);
        }
      }
    }
  }
  return;
}


/* ***********************************************************************
  @fn               VDYwrtCalcTblOffset */ /*!
  @brief            Calculate yaw rate sensor offset

  @description      see brief description

  @param[in]        sensor data
  @param[in]        offset table
  @param[out]       provided ports
  @return           void

  @pre              -
  @post             -
**************************************************************************** */
STATIC_MTD void VDYwrtCalcTblOffset(const VDYYwrtSenData_t *pSen, const proVDYPrtList_t *proPorts, VDYYwrtOffsTblData_t *pOffsTbl)
{
  const f32_t fir_len_min_max_c[2] = {15.F, 30.F};  /* FIR-Length nodes = Number of observed samples */
  const f32_t lrn_cnt_min_max_c[2] = { 4.F, 6.F};   /* Learn counter nodes */
  f32_t alpha;
  f32_t intp_offs;
  f32_t ywRateDiff;

  /* Init temp table with production offset */
  if (proPorts->pYwrtTempTable->prodOffset != VDY_YWRT_PROD_OFFSET_SNA) {
    VDYYwrtInitWithFirstLearnValue(proPorts->pYwrtTempTable, (f32_t) proPorts->pYwrtTempTable->prodOffset * VDY_YWRT_PROD_SCALE);
  }

  if ( pSen->obsOffs != FALSE ) {
    
    f32_t fir_len;  /* lenght of input filter */

    /* Increase filter length with rising learning iterations */
    fir_len = vdyLFunction((f32_t) pOffsTbl->LearnCnt, lrn_cnt_min_max_c[0], lrn_cnt_min_max_c[1], 
                                                       fir_len_min_max_c[0], fir_len_min_max_c[1]);

    /* Update input (moving average) filter */
    vdyStatIntervalAdd(&pOffsTbl->SmpYwRt, pSen->YawRate, 1.0F);
    vdyStatIntervalAdd(&pOffsTbl->SmpTemp, pSen->Tempr, 1.0F);

    /* Maximum number of learning iteration during current standstill reached */
    /* <ln_offset:+1 PCLINT Error 912: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use */
    if ((ui32_t) pOffsTbl->LearnCnt <= VDY_YWRT_MAX_LEARN_CNT) {

      /* Input filter hold enough samples to update standstill offset */
      if (pOffsTbl->SmpYwRt.Volume > (fir_len - C_F32_DELTA) ) {
        
        f32_t ywr_mean;
        f32_t ywr_dev;
        f32_t tmpr_mean;
    
        /* First learn value available from previous learning iteration */
        if ( pOffsTbl->LearnCnt > (ui16_t) 0) {

          /* Non-volaltile memory write request present from last learning iteraton */

          /* Bitmask enabling nvm write access in dependence of write counter */
          /* <ln_offset:+18 PCLINT Error 835: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, bit shift temp table mask */
          /* <ln_offset:+16 PCLINT Error 835: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, bit shift temp table mask */
          /* <ln_offset:+14 PCLINT Error 835: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, bit shift temp table mask */
          /* <ln_offset:+12 PCLINT Error 835: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, bit shift temp table mask */
          /* <ln_offset:+10 PCLINT Error 835: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, bit shift temp table mask */
          /* <ln_offset:+8 PCLINT Error 835: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, bit shift temp table mask */
          /* <ln_offset:+6 PCLINT Error 835: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, bit shift temp table mask */
          /* <ln_offset:+4 PCLINT Error 835: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, bit shift temp table mask */
          /* <ln_offset:+2 PCLINT Error 835: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, bit shift temp table mask */
          const ui32_t NvmWriteMask_c = (
            (0UL<<0UL) |
            (1UL<<1UL) |
            (0UL<<2UL) |
            (0UL<<3UL) |
            (0UL<<4UL) |
            (0UL<<5UL) |
            (1UL<<6UL) |
            (0UL<<7UL) |
            (0UL<<8UL) 
          );
          /* <ln_offset:-1 PCLINT Error 845: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, bit shift temp table mask */

          /* Update NVM table left node, if is required or permitted */
          if (pOffsTbl->bWrLeft != FALSE) {

            /* Update RAM table left node with new learn value */
            VDYYwrtSetTableNode(proPorts->pYwrtTempTable, &pOffsTbl->Left);

            /* Trigger pending write flag for left node */
            /* <ln_offset:+2 PCLINT Error 912: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, set temp table state */
            /* <ln_offset:+1 MISRA Rule 10.1: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, set temp table state */
            VDY_YWRT_NODE_SET_VALID(pOffsTbl->Left.No, proPorts->pYwrtTempTable->statWrpd);
          }

          /* Update NVM table right node, if is required or permitted */
          if (pOffsTbl->bWrRight != FALSE) {
            
            /* Update RAM table right node with new learn value */
            VDYYwrtSetTableNode(proPorts->pYwrtTempTable, &pOffsTbl->Right);
            
            /* Trigger pending write flag for right node */
            /* <ln_offset:+2 PCLINT Error 912: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, set temp table state */
            /* <ln_offset:+1 MISRA Rule 10.1: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, set temp table state */
            VDY_YWRT_NODE_SET_VALID(pOffsTbl->Right.No, proPorts->pYwrtTempTable->statWrpd);
          }

          /* Update unlearned nodes */
          VDYYwrtFillUnlearnedNodes(pOffsTbl, proPorts->pYwrtTempTable);

          /* Update of nvm memory required */
          /* <ln_offset:+2 PCLINT Error 912: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use */
          if (  ( (pOffsTbl->bWrLeft != FALSE) || (pOffsTbl->bWrRight != FALSE) ) 
              &&(( (1UL<<((ui32_t) pOffsTbl->LearnCnt))& NvmWriteMask_c) != 0UL ) ) {

            /* Read table write counter from nonvolatile memory */
            /* <ln_offset:+1 PCLINT Error 912: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, get temp table state */
            if (VDY_YWRT_NODE_IS_VALID(VDY_YWRT_BIT_POS_CNTR, proPorts->pYwrtTempTable->statRd)) {
              /* Number of write accesses to temp table */
              proPorts->pYwrtTempTable->cntWr++;
              /* <ln_offset:+2 PCLINT Error 912: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, set temp table state */
              /* <ln_offset:+1 MISRA Rule 10.1: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, set temp table state */
              VDY_YWRT_NODE_SET_VALID(VDY_YWRT_BIT_POS_CNTR, proPorts->pYwrtTempTable->statWr);
            }
            /* Flush pending nvm write updates */
            VDYYwrtCompletePendingWrites(proPorts->pYwrtTempTable);
          }

          /* New values transferred */
          pOffsTbl->bWrLeft  = FALSE;
          pOffsTbl->bWrRight = FALSE;
        }
    
        /* Calculate input filter output */
        vdyStatIntervalMeanDev(&pOffsTbl->SmpYwRt);
        vdyStatIntervalMeanDev(&pOffsTbl->SmpTemp);
        
        /* Save statistics before init */
        ywr_mean  = pOffsTbl->SmpYwRt.Mean; 
        ywr_dev   = pOffsTbl->SmpYwRt.Dev;
        tmpr_mean = pOffsTbl->SmpTemp.Mean; 
        
        /* Reset input filter data */
        vdyStatIntervalInitInput(&pOffsTbl->SmpYwRt);
        vdyStatIntervalInitInput(&pOffsTbl->SmpTemp);

        /* Save current offset temperature */
        pOffsTbl->LastOffsTemp = tmpr_mean;
        
        /* Standard deviaiton of observed samples must be small */
        if ( ywr_dev < VDY_YWRT_YWR_STD_DEV_MAX) {

          /* Init temp table with first standstill offset */
          VDYYwrtInitWithFirstLearnValue(proPorts->pYwrtTempTable, ywr_mean);

          /* Update working nodes according to temperature operating point */
          VDYYwrtGetNodesOfInterest(tmpr_mean, proPorts->pYwrtTempTable, pOffsTbl);
          
          /* Get normalized distance (0..1) with respect to adjacent nodes, 0-> temp = left node,  1 -> temp = right node */
          alpha =  (tmpr_mean - (VDY_YWRT_FIRST_NODE_TEMP + ((f32_t)pOffsTbl->Left.No * VDY_YWRT_NODE_WIDTH))) * VDY_YWRT_NODE_INV_WIDTH;
          
          /* Interpolate yaw rate offset value */
          intp_offs = pOffsTbl->Left.Offset + (alpha * (pOffsTbl->Right.Offset - pOffsTbl->Left.Offset));
          
          /* Calculate difference between current and interpolated yaw rate offset value*/
          ywRateDiff = fABS(ywr_mean - intp_offs);

          /* Discrimination of temperature location with respect to nodes  */
          if (alpha < VDY_YWRT_ALPHA_DLT) {

            /* Measurement point is directly located at left node */
            
            /* Make measurement update only if node is not completely learned or relearn step is necessary */
            if ( (pOffsTbl->Left.Conf < (VDY_YWRT_CONF_MAX - VDY_YWRT_CONF_DLTF) ) || (ywRateDiff > VDY_YWRT_LEARN_THRHD) ) {

              /* If there is a significant deviation between complete learned node and current measurement 
                 value lower confidence of learned node to re enable learning. The goal is not to relearn a 
                 complete new offset value, but get an average between the new and old due to hysteresis. */
              if ( (ywRateDiff > VDY_YWRT_LEARN_THRHD) && (pOffsTbl->Left.Conf > (VDY_YWRT_CONF_MAX_NEAR - VDY_YWRT_CONF_DLTF)) ) {
                pOffsTbl->Left.Conf = VDY_YWRT_CONF_LEARN;
                pOffsTbl->LearnAgainCnt++;
              }

              /* Only update left node */
              VDYYwrtMeasUpdateNode(&pOffsTbl->Left, VDY_YWRT_ALPHA_MAX, ywr_mean, VDY_YWRT_CONF_MAX_NEAR);
              pOffsTbl->bWrLeft = TRUE;
            }
          }
          else if (alpha <= VDY_YWRT_ALPHA_MIN) {

            /* Measurement point is closely located at left node */

            /* Make measurement update only if node is not completely learned or relearn step is necessary */
            if ( (pOffsTbl->Left.Conf <  (VDY_YWRT_CONF_MAX - VDY_YWRT_CONF_DLTF) ) || (ywRateDiff > VDY_YWRT_LEARN_THRHD) ) {

              /* If there is a significant deviation between complete learned node and current measurement 
                 value lower confidence of learned and adjacent node to re enable learning */
              if ( (ywRateDiff > VDY_YWRT_LEARN_THRHD) && (pOffsTbl->Left.Conf > (VDY_YWRT_CONF_MAX_NEAR - VDY_YWRT_CONF_DLTF) ) ) {

                f32_t diffNewOldRight;
                f32_t diffNewOldLeft;
                
                /* Reduce confidence of near node close */
                pOffsTbl->Left.Conf = VDY_YWRT_CONF_LEARN;

                /* If difference between new offset value and current adjacent node offset is big reset confidence. This 
                   avoids relearning due to a distorted offset value from this node. The relearn thereshold is compared 
                   against the interpolated value between left and right node */
                diffNewOldRight = ywr_mean - pOffsTbl->Right.Offset;
                diffNewOldLeft  = ywr_mean - pOffsTbl->Left.Offset;

                /* In case of big deviation reset confidence, otherwise it will only be reduced */
                if ( fABS(diffNewOldRight) > VDY_YWRT_LEARN_THRHD_FAR) {
                  pOffsTbl->Right.Conf = 0.F;
                }
                
                /* Reduce confidence of adjacent node only, if deviation at current node is small. This avoids 
                   readjusting of already relearned node */
                if (  (pOffsTbl->Right.Conf > (VDY_YWRT_CONF_MAX_FAR - VDY_YWRT_CONF_DLTF)) 
                    &&(fABS(diffNewOldLeft) < VDY_YWRT_LEARN_THRHD_NEAR) ) {
                  pOffsTbl->Right.Conf = VDY_YWRT_CONF_LEARN_ADJ;
                }

                pOffsTbl->LearnAgainCnt++;
              }

              /* Update left node */
              VDYYwrtMeasUpdateNode(&pOffsTbl->Left, VDY_YWRT_ALPHA_MAX, ywr_mean, VDY_YWRT_CONF_MAX_NEAR);
              pOffsTbl->bWrLeft = TRUE;
            }

            /* Update right node */
            if ( pOffsTbl->Right.Conf < (VDY_YWRT_CONF_MAX_FAR - VDY_YWRT_CONF_DLTF) ) {
              VDYYwrtMeasUpdateNode(&pOffsTbl->Right, VDY_YWRT_ALPHA_MIN, ywr_mean, VDY_YWRT_CONF_MAX_FAR);
              pOffsTbl->bWrRight = TRUE;
            }
          }
          else if (alpha < VDY_YWRT_ALPHA_MAX) {

            /* Measurement point is located at the middle of left and right node */

            /* Update left node */
            if ( pOffsTbl->Left.Conf <  (VDY_YWRT_CONF_MAX_FAR - VDY_YWRT_CONF_DLTF) ) {
              VDYYwrtMeasUpdateNode(&pOffsTbl->Left, (1.0F-alpha), ywr_mean, VDY_YWRT_CONF_MAX_FAR);
              pOffsTbl->bWrLeft = TRUE;
            }

            /* Update right node */
            if ( pOffsTbl->Right.Conf <  (VDY_YWRT_CONF_MAX_FAR - VDY_YWRT_CONF_DLTF) ) {
              VDYYwrtMeasUpdateNode(&pOffsTbl->Right, alpha, ywr_mean, VDY_YWRT_CONF_MAX_FAR);
              pOffsTbl->bWrRight = TRUE;
            }
          }
          else if (alpha < (VDY_YWRT_ALPHA_VAL_MAX - VDY_YWRT_ALPHA_DLT) ) {

            /* Measurement point is closely located at right node */

            /* Make measurement update only if node is not completely learned or relearn step is necessary */
            if ( (pOffsTbl->Right.Conf <  (VDY_YWRT_CONF_MAX - VDY_YWRT_CONF_DLTF))  || (ywRateDiff > VDY_YWRT_LEARN_THRHD) ) {

              /* If there is a significant deviation between complete learned node and current measurement 
                 value lower confidence of learned and adjacent node to re enable learning. */
              if ( (ywRateDiff > VDY_YWRT_LEARN_THRHD) && (pOffsTbl->Right.Conf >  (VDY_YWRT_CONF_MAX_NEAR - VDY_YWRT_CONF_DLTF) ) ) {
                
                f32_t diffNewOldLeft;
                f32_t diffNewOldRight;
                
                /* Reduce confidence of current node */
                pOffsTbl->Right.Conf = VDY_YWRT_CONF_LEARN;

                /* If difference between new offset value and current adjacent node offset is big reset confidence. This 
                avoids relearning due to a distorted offset value from this node. The relearn thereshold is compared 
                against the interpolated value between left and right node */
                diffNewOldLeft = ywr_mean  - pOffsTbl->Left.Offset;
                diffNewOldRight = ywr_mean - pOffsTbl->Right.Offset;

                /* In case of big deviation reset confidence, otherwise it will be only be reduced */
                if ( fABS(diffNewOldLeft) > VDY_YWRT_LEARN_THRHD_FAR) {
                  pOffsTbl->Left.Conf = 0.F;
                }
                
                /* Reduce confidence of adjacent node only, if deviation at current node is small. This avoids 
                   readjusting of already relearned node */
                if (  (pOffsTbl->Left.Conf > (VDY_YWRT_CONF_MAX_FAR - VDY_YWRT_CONF_DLTF))
                    &&(fABS(diffNewOldRight) < VDY_YWRT_LEARN_THRHD_NEAR) ) {
                  pOffsTbl->Left.Conf = VDY_YWRT_CONF_LEARN_ADJ;
                }

                pOffsTbl->LearnAgainCnt++;
              }

              /* Update right node */
              VDYYwrtMeasUpdateNode(&pOffsTbl->Right, VDY_YWRT_ALPHA_MAX, ywr_mean, VDY_YWRT_CONF_MAX_NEAR);
              pOffsTbl->bWrRight = TRUE;
            }
            
            /* Update left node */
            if (  pOffsTbl->Left.Conf < (VDY_YWRT_CONF_MAX_FAR - VDY_YWRT_CONF_DLTF) ) {
              VDYYwrtMeasUpdateNode(&pOffsTbl->Left, VDY_YWRT_ALPHA_MIN, ywr_mean, VDY_YWRT_CONF_MAX_FAR);
              pOffsTbl->bWrLeft = TRUE;
            }
          }
          else {

            /* Measurement point is directly located at right node */
            
            /* Make measurement update only if node is not completely learned or relearn step is necessary */
            if ( (pOffsTbl->Right.Conf < (VDY_YWRT_CONF_MAX - VDY_YWRT_CONF_DLTF))  || (ywRateDiff > VDY_YWRT_LEARN_THRHD) ) {

              /* If there is a significant deviation between complete learned node and current measurement 
              value lower confidence of learned node to re enable learning. The goal is not to relearn a 
              complete new offset value, but get an average between the new and old due to hysteresis. */
              if ( (ywRateDiff > VDY_YWRT_LEARN_THRHD) && (pOffsTbl->Right.Conf > (VDY_YWRT_CONF_MAX_NEAR - VDY_YWRT_CONF_DLTF)) ) {
                pOffsTbl->Right.Conf = VDY_YWRT_CONF_LEARN;
                pOffsTbl->LearnAgainCnt++;
              }

              /* Only update right node */
              VDYYwrtMeasUpdateNode(&pOffsTbl->Right, VDY_YWRT_ALPHA_MAX, ywr_mean, VDY_YWRT_CONF_MAX_NEAR);
              pOffsTbl->bWrRight = TRUE;
            }
          } /* End of discrimination of temperature location with respect to nodes  */ 
          
          /* Update learn counter only if table update is pending */
          if ( (pOffsTbl->bWrLeft != FALSE) || ((pOffsTbl->bWrRight != FALSE)) ) {
        
            /* Increase number of learning iteration during this standstill */
            pOffsTbl->LearnCnt++;
          }
        }
      } /* End of new input filter value */
    } /* End of learn count */
    else {
      /* Maximum number of learning reached, if during the standstill temperature 
         deviation occurs, re-enable learning */

      /* Discard pending learning values */
      pOffsTbl->bWrLeft  = FALSE;
      pOffsTbl->bWrRight = FALSE;

      /* Flush pending nvm write updates */
      VDYYwrtCompletePendingWrites(proPorts->pYwrtTempTable);

      /* Input filter hold enough samples for evalution  */
      if (pOffsTbl->SmpYwRt.Volume > (fir_len - C_F32_DELTA) ) {
        
        /* Calculate input filter output */
        vdyStatIntervalMeanDev(&pOffsTbl->SmpYwRt);
        vdyStatIntervalMeanDev(&pOffsTbl->SmpTemp);

        /* If temperature deviation to last learned offset value, re-enable learning*/
        if ( fABS(pOffsTbl->LastOffsTemp - pOffsTbl->SmpTemp.Mean) > 5.0F )  {
          pOffsTbl->LearnCnt = (ui16_t) 0;
        }

        /* Reset input filter data */
        vdyStatIntervalInit(&pOffsTbl->SmpYwRt);
        vdyStatIntervalInit(&pOffsTbl->SmpTemp);
      }
    }
  } /* End of observability */
  else {
    /* Yaw rate zero point offset is not observable */
    
    /* Discard pending learning values */
    pOffsTbl->bWrLeft  = FALSE;
    pOffsTbl->bWrRight = FALSE;

    /* At drive-off finalize learning */
    if (pSen->StandstillOK == FALSE) {
      /* reset standstill learning counter */
      pOffsTbl->LearnCnt = (ui16_t) 0;
      
      /* Flush pending nvm write updates */
      VDYYwrtCompletePendingWrites(proPorts->pYwrtTempTable);

      /* Correct missing interpolated bybass values, which could be caused by power interuption */
      /* <ln_offset:+1 PCLINT Error 912: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use */
      if ((pOffsTbl->Checked == FALSE) && !VDY_YWRT_NODES_ALL_VALID(proPorts->pYwrtTempTable->statRd)) {
        pOffsTbl->Checked = TRUE;
        VDYYwrtCorrectTable(proPorts->pYwrtTempTable);
      }
    }

    /* Reset input filter for next standstill */
    vdyStatIntervalInit(&pOffsTbl->SmpYwRt);
    vdyStatIntervalInit(&pOffsTbl->SmpTemp);
  }
  
  /* Calculate current yaw rate offset based on offset table data */
  VDYYwrtCalcOffsTblCurr(proPorts->pYwrtTempTable, pSen->Tempr, pOffsTbl);
  
  return;
}


/* ***********************************************************************
  @fn               VDYYwrtLearnValuePresent */ /*!
  @brief            Test if any learn value is present

  @description      see brief description

  @param[in]        yaw rate temperature table
  @param[out]       -
  @return           flag: TRUE: learn value present, FALSE: no learn value present

  @pre              -
  @post             -
**************************************************************************** */
STATIC_MTD bool_t VDYYwrtLearnValuePresent(const VDYNvYwrtLearnTable_t *pYwrTmpTbl)
{
  ui32_t ii;
  ui32_t Sum=0U;
  
  /* peruse all learn values */
  for (ii=0U; (ii<VDY_YWRT_NO_NODES) && (Sum == 0U); ii++) {
    Sum += (ui32_t) pYwrTmpTbl->Node[ii].Conf;
  }
  
  /* return TRUE if at least one learn value is present */
  /* <ln_offset:+1 MISRA Rule 10.3: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use*/
  return ((bool_t)(Sum>0U));
}


/* ***********************************************************************
  @fn               VDYYwrtGetTableNode */ /*!
  @brief            Read correction table node and convert to floating point

  @description      see brief description

  @param[in]        yaw rate temperature table
  @param[out]       learning node
  @return           void

  @pre              -
  @post             -
**************************************************************************** */
STATIC_MTD void VDYYwrtGetTableNode(const VDYNvYwrtLearnTable_t *tbl, VDYYwrtLearnNode_t *ndInt)
{
  ndInt->Offset  = VDY_YWRT_NVM_YWR_FLP(tbl->Node[ndInt->No].Offset);
  ndInt->Conf    = VDY_YWRT_NVM_CONF_FLP(tbl->Node[ndInt->No].Conf);

  return;
}


/* ***********************************************************************
  @fn               VDYYwrtSetTableNode */ /*!
  @brief            Convert to fixed point and write correction table node 

  @description      see brief description

  @param[in]        learning node
  @param[out]       yaw rate temperature table
  @return           void

  @pre              -
  @post             -
**************************************************************************** */
STATIC_MTD void VDYYwrtSetTableNode(VDYNvYwrtLearnTable_t *tbl, const VDYYwrtLearnNode_t *ndInt)
{
  /* <ln_offset:+1 MISRA Rule 10.4: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, rounding */
  tbl->Node[ndInt->No].Offset  = VDY_YWRT_NVM_YWR_FXP(ndInt->Offset);
  /* <ln_offset:+1 MISRA Rule 10.4: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, rounding */
  tbl->Node[ndInt->No].Conf    = VDY_YWRT_NVM_CONF_FXP(ndInt->Conf);

  return;
}


/* ***********************************************************************
  @fn               VDYYwrtCompletePendingWrites */ /*!
  @brief            Flush pending nvm memory writes

  @description      see brief description

  @param[in,out]    yaw rate learn table
  @return           void

  @pre              -
  @post             -
**************************************************************************** */
STATIC_MTD void VDYYwrtCompletePendingWrites(VDYNvYwrtLearnTable_t *tbl)
{
  /* Enable write access of pending update values */
  /* <ln_offset:+1 PCLINT Error 912: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use */
  tbl->statWr[0] |= (ui32_t)(tbl->statWrpd[0] & VDY_YWRT_NODES_MAKS_ALL_LO);
  tbl->statWr[1] |= (ui32_t)(tbl->statWrpd[1] & VDY_YWRT_NODES_MAKS_ALL_HI);
  /* <ln_offset:-1 PCLINT Error 912: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use */

  /* Clear pending writes */
  /* <ln_offset:+4 PCLINT Error 912: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, clear all the temp table states (bitmask) */
  /* <ln_offset:+3 PCLINT Error 845: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, clear all the temp table states (bitmask) */
  /* <ln_offset:+2 MISRA Rule 1.2: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, clear all the temp table states (bitmask) */
  /* <ln_offset:+1 MISRA Rule 10.1: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, clear all the temp table states (bitmask) */
  VDY_YWRT_NODES_CLEAR_ALL(tbl->statWrpd);

  return;
}


/*****************************************************************************
  @fn             VDYYwrtInterpTable
  @brief          Calculation of linear interpolated table values

  @description    see brief description

  @param[in]      xi
  @param[in]      y_out
  @param[in]      len
  @param[out]     node
  @return         void

  @pre            -
  @post           -
*****************************************************************************/
STATIC_MTD void VDYYwrtInterpTable(const VDYNvYwrtLearnNode_t *node, const ui8_t *xi, i16_t *y_out, ui32_t len)
{
  ui32_t ni = 0U;
  i16_t ii;

  /* run through all table nodes */
  for (ii=0; ii<(i16_t)VDY_YWRT_NO_NODES; ii++) {
    
    f32_t y;

    /* Look for first reference node xi above current table node */
    while ( (ni < (len - 1U)) && ((i16_t)xi[ni] < ii) ) {
      ni++;
    }

    /* test if current table node is inside reference node range */
    if (ni > 0U) {

      i16_t x2;
      i16_t x1;

      f32_t y2;
      f32_t y1;

      /* Take actual table position and previous table position for interpolation */
      x1 = (i16_t)xi[ni-1U];
      x2 = (i16_t)xi[ni];

      /* Get reference nodes values */
      y1 = (f32_t) node[x1].Offset;
      y2 = (f32_t) node[x2].Offset;

      /* reference must be distinct for interpolation */
      if (x1 < x2) {
        
        if( ii < x2 ) {
          /* table node is between reference node */
          
          y = (((f32_t)( ii - x1) * (y2 - y1)) / (f32_t)(x2 - x1)) + y1; /* MISRA Rule 10.3: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use*/
        }
        else {
          /* table node is on or beyond reference node */
          y = y2;
        } 
      }
      else {
        /* reference nodes indices are identical, interpolation not possible, use 
           first node value */
        y = y1;
      }
    }
    else {
      /* current table node outside reference node range, use first reference node as output
         value */
      y = (f32_t)(node[xi[0]].Offset);
    }
    /* save result as fixed-point value */
    /* <ln_offset:+1 MISRA Rule 10.4: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, rounding */
    y_out[ii] = (i16_t) ROUND_TO_INT(y);
    /* <ln_offset:-1 MISRA Rule 10.4: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, rounding */
  }
  return;
}


/*****************************************************************************
  @fn             VDYYwrtRepairTable
  @brief          Calculation of linear interpolated table values

  @description    see brief description


  @param[in]      pointer to table
  @param[out]     pointer to table
  @return         void

  @pre            -
  @post           -
*****************************************************************************/
STATIC_MTD void VDYYwrtCorrectTable(VDYNvYwrtLearnTable_t *pYwrTmpTbl)
{
  ui32_t idx;
  ui8_t lrn_nds[VDY_YWRT_NO_NODES];

  ui32_t len_nds = 0UL;
  VDYNvYwrtLearnNode_t *tab = pYwrTmpTbl->Node;

  /* Look for learned table nodes indices */
  for (idx=0UL; idx<VDY_YWRT_NO_NODES; idx++) {
    lrn_nds[idx] = (ui8_t) VDY_YWRT_NO_NODES;
    if (tab[idx].Conf > VDY_YWRT_CONF_RES_FXP) {
      lrn_nds[len_nds++] = (ui8_t) idx;
    }
  }

  /* If at least one learned node was found, interpolate values */
  if (len_nds > 0U) {
    i16_t offs[VDY_YWRT_NO_NODES];

    /* Interpolate and extrapolate learned values to whole table */
    VDYYwrtInterpTable(tab, lrn_nds, offs, len_nds);

    /* Run through all nodes and correct nodes if necessary */
    for (idx=0UL; idx<VDY_YWRT_NO_NODES; idx++) {

      i16_t diff = offs[idx] - tab[idx].Offset;

      /* Correct with low confidence and significant devation to interpolated value */
      /* <ln_offset:+2 PCLINT Error 912: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use */
      if (   (tab[idx].Conf <= VDY_YWRT_CONF_RES_FXP)
          && (ABS(diff) > VDY_YWRT_OFFS_THRD_FXP) ) {
        
        /* Update offset table values */
        tab[idx].Offset    = offs[idx];
        tab[idx].Conf    = VDY_YWRT_CONF_RES_FXP;
        /* <ln_offset:+2 PCLINT Error 912: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, set temp table node state */
        /* <ln_offset:+1 MISRA Rule 10.1: reviewer name: Jochen Spruck date: 15-02-2011 reason: proven in use, set temp table node state */
        VDY_YWRT_NODE_SET_VALID(idx, pYwrTmpTbl->statWrpd);
      }
    }
  }
  return;
}


/* ***********************************************************************
  @fn               VDYYwrtGetYawRateOffset */ /*!
  @brief            Hand over leanred offset and confidence value

  @description      see brief description

  @param[out]       pointer to offset table
  @param[out]       pointer to confidence table
  @return           void

  @pre              -
  @post             -
**************************************************************************** */
void VDYYwrtGetYawRateOffset(fYawRate_t *offset, fConfidence_t *conf)
{
  const VDYYwrtOffsTblData_t *pOffsTbl = &(YWRT_GET_OFFS->Tbl);

  *offset = pOffsTbl->Offset;
  *conf   = pOffsTbl->Conf;

  return;
}


/* ***********************************************************************
  @fn                     GetOffsData */ /*!
  @brief                  Access to offset data

  @description            see brief description

  @param[in]              -
  @param[out]             -
  @return                 *VDYYwrOffsData_t

  @pre                    -
  @post                   -
**************************************************************************** */
const VDYYwrtOffsData_t *VDYYwrtGetOffsData(void)
{
  return (YWRT_GET_OFFS);
}


/* ***********************************************************************
  @fn                     VDYYwrtGetPrivateData */ /*!
  @brief                  Get internal yaw rate sensor data

  @description            see brief description

  @param[in]              -
  @param[out]             -
  @return                 *VDYYwrtData_t

  @pre                    -
  @post                   -
**************************************************************************** */
VDYYwrtData_t *VDYYwrtGetPrivateData(void);
VDYYwrtData_t *VDYYwrtGetPrivateData(void)
{
  return (YWRT_GET_ME);
}
#endif

/** @} */ 
/* EOF */
