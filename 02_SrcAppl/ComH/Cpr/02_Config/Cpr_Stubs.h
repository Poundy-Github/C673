/**
 * \file Cpr_Stubs.h
 *
 * \brief
 *
 * \version
 * --------------------------------------------------------------------------------------------
 * Version	| 		Data		|		Author			| 	Comments
 * V0.0.1		2022.03.10			Mingfen XIAO			Init version
 * V
 *
 *
 */
#ifndef CPR_STUBS_H
#define CPR_STUBS_H

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */
#include "Rte_Fcu_Type.h"
#include "Rte_Cpr_Type.h"
/*==================[macros]=================================================*/
#define CPR_CRC_RC_TIMEOUT_ENABLE   STD_ON

#define CPR_METHOD_CRC8     0U
#define CPR_METHOD_CRC16    1U 

#define CPR_Read_Msg_Staus          Cpr_RxMessageStatusInfo
/*==================[type definitions]=======================================*/
typedef enum
{
    Cpr_MsgState_Init    = E_MSG_STATUS_NONE,
    Cpr_No_Error         = E_MSG_STATUS_VALID,
    Cpr_Msg_Invalid      = E_MSG_STATUS_INVALID,
    Cpr_Msg_TimeOut      = E_MSG_STATUS_TOUT,
    Cpr_Crc_Error        = E_MSG_STATUS_CRC,
    Cpr_Rc_Error         = E_MSG_STATUS_ROLLINGCNT,
    Cpr_Crc_and_Rc_Error = E_MSG_STATUS_CRC_AND_ROLLINGCNT,
    Cpr_Out_IDRange      = E_MSG_STATUS_OUTID_RANGE
}e_Cpr_Msg_ErrorState;

typedef enum
{
    Cpr_FUNC_FCW = 0,
    Cpr_FUNC_FAB,
    Cpr_FUNC_LDW_or_LKA,
    Cpr_FUNC_LDW_Warning,
    Cpr_FUNC_ELK,
    Cpr_FUNC_AEB,
    Cpr_FUNC_Factory_Mode
}e_Cpr_HMIFuncID_t;

typedef enum // Total number: COM_RX_CALL_OUT_FUNC_PTR_ARRAY_SIZE
{
    INIT_MsgID  = E_CPR_MSG_ID_START,
    GW_50       = E_CPR_MSG_ID_GW_50,   // DLC:  8 bytes
    GW_170      = E_CPR_MSG_ID_GW_170,  // DLC:  8 bytes
    GW_17A      = E_CPR_MSG_ID_GW_17A,  // DLC: 64 bytes
    GW_17E      = E_CPR_MSG_ID_GW_17E,  // DLC:  8 bytes
    GW_180      = E_CPR_MSG_ID_GW_180,  // DLC:  8 bytes
    GW_1C2      = E_CPR_MSG_ID_GW_1C2,  // DLC: 64 bytes
    GW_20B      = E_CPR_MSG_ID_GW_20B,  // DLC: 64 bytes
    GW_24F      = E_CPR_MSG_ID_GW_24F,  // DLC:  8 bytes
    GW_278      = E_CPR_MSG_ID_GW_278,  // DLC:  8 bytes
    GW_288      = E_CPR_MSG_ID_GW_288,  // DLC:  8 bytes
    GW_28B      = E_CPR_MSG_ID_GW_28B,  // DLC:  8 bytes
    GW_2A8      = E_CPR_MSG_ID_GW_2A8,  // DLC: 64 bytes
    GW_2C2      = E_CPR_MSG_ID_GW_2C2,  // DLC: 64 bytes
    GW_2DE      = E_CPR_MSG_ID_GW_2DE,  // DLC:  8 bytes
    GW_3C2      = E_CPR_MSG_ID_GW_3C2,  // DLC: 64 bytes
    VCU_161     = E_CPR_MSG_ID_VCU_161, // DLC: 64 bytes
    VCU_38A     = E_CPR_MSG_ID_VCU_38A, // DLC:  8 bytes
    FR_111      = E_CPR_MSG_ID_FR_111,  // DLC: 64 bytes
    FR_112      = E_CPR_MSG_ID_FR_112,  // DLC: 64 bytes
    FR_113      = E_CPR_MSG_ID_FR_113,  // DLC: 64 bytes
    FR_114      = E_CPR_MSG_ID_FR_114,  // DLC: 64 bytes
    FR_115      = E_CPR_MSG_ID_FR_115,  // DLC: 64 bytes
    FR_116      = E_CPR_MSG_ID_FR_116,  // DLC: 64 bytes
    FR_117      = E_CPR_MSG_ID_FR_117,  // DLC: 64 bytes
    FR_118      = E_CPR_MSG_ID_FR_118,  // DLC: 64 bytes
    FR_119      = E_CPR_MSG_ID_FR_119,  // DLC: 64 bytes
    FR_11A      = E_CPR_MSG_ID_FR_11A,  // DLC: 64 bytes
    FR_11B      = E_CPR_MSG_ID_FR_11B,  // DLC: 64 bytes
    FR_11C      = E_CPR_MSG_ID_FR_11C,  // DLC: 64 bytes
    FR_11D      = E_CPR_MSG_ID_FR_11D,  // DLC: 64 bytes
    FR_11E      = E_CPR_MSG_ID_FR_11E,  // DLC: 64 bytes
    FR_11F      = E_CPR_MSG_ID_FR_11F,  // DLC: 64 bytes
    FR_120      = E_CPR_MSG_ID_FR_120,  // DLC: 64 bytes
    FR_136      = E_CPR_MSG_ID_FR_136,  // DLC: 64 bytes
    FR_138      = E_CPR_MSG_ID_FR_138,  // DLC: 64 bytes
    ADC_19B     = E_CPR_MSG_ID_ADC_19B, // DLC: 64 bytes
    ADC_200     = E_CPR_MSG_ID_ADC_200, // DLC: 16 bytes, UNUSUAL DBC layout, Confirmed no need to handle ADC_200 by Mingfen
    ADC_345     = E_CPR_MSG_ID_ADC_345, // DLC: 64 bytes
    ADC_346     = E_CPR_MSG_ID_ADC_346, // DLC: 64 bytes
    RxMsgEnd
}e_CPR_RxMsgID;

typedef struct
{
  e_Cpr_Msg_ErrorState  Cpr_Msg_ErrorState;
  e_CPR_RxMsgID         MsgID;
}CPR_E2ECompute_Status_t;

/*==================[external function declarations]========================*/
extern FUNC(uint8, COM_APPL_CODE) Cpr_RxMessageStatusInfo(e_CPR_RxMsgID eMsgName);


/*==================[internal function declarations]========================*/
//COM_Timeout_Callout
/* ID:VCU_161 sigain:VcuAccrMod  TimeOut:100ms*/
FUNC(boolean, COM_APPL_CODE)VCU_161_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* ID:GW17A sigain:EspVehSpd  TimeOut:100ms*/
FUNC(boolean, COM_APPL_CODE)GW_17A_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* ID:GW1C2 sigain:EspAbsActv  TimeOut:100ms*/
FUNC(boolean, COM_APPL_CODE)GW_1C2_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* ID:GW20B sigain:WhlSpdLeReDir  TimeOut:100ms*/
FUNC(boolean, COM_APPL_CODE)GW_20B_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* ID:GW2C2 sigain:IBBrkPedlModSts  TimeOut:100ms*/
FUNC(boolean, COM_APPL_CODE)GW_2C2_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* ID:GW278 sigain:ESP_LatAccelValid  TimeOut:100ms*/
FUNC(boolean, COM_APPL_CODE)GW_278_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* ID:GW170 sigain:EPS_ActualMotorTorq  TimeOut:100ms*/
FUNC(boolean, COM_APPL_CODE)GW_170_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* ID:GW180 sigain:EpsSasCalSts  TimeOut:100ms*/
FUNC(boolean, COM_APPL_CODE)GW_180_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* ID:GW17E sigain:EPS_Pinionang  TimeOut:100ms*/
FUNC(boolean, COM_APPL_CODE)GW_17E_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* ID:GW24F sigain:EPS_LDW_ShakeLevStatus  TimeOut:200ms*/
FUNC(boolean, COM_APPL_CODE)GW_24F_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* ID:GW288 sigain:BcmHiBeamSts  TimeOut:1000ms*/
FUNC(boolean, COM_APPL_CODE)GW_288_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* ID:GW2DE sigain:IP_DISFail  TimeOut:1000ms*/
FUNC(boolean, COM_APPL_CODE)GW_2DE_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* ID:GW_50 sigain:SrsCycCntr  TimeOut:1s*/
FUNC(boolean, COM_APPL_CODE)GW_50_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

//FR node
/* ID:FR_136 sigain:FR_ObjCount  TimeOut:1s*/
FUNC(boolean, COM_APPL_CODE)FR_136_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

//ADC node
/* ID:ADC_345 sigain:RLR_ElkOBJ1_Type  TimeOut:1s*/
FUNC(boolean, COM_APPL_CODE)ADC_345_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* ID:ADC_346 sigain:RLR_ElkOBJ3_Type  TimeOut:1s*/
FUNC(boolean, COM_APPL_CODE)ADC_346_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* ID:ADC_19B sigain:ADS_Fail  TimeOut:1s*/
FUNC(boolean, COM_APPL_CODE)ADC_19B_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);


//receive callouts
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDGW_50_80R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDVCU_161_353R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDGW_170_368R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDGW_17A_378R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDGW_17E_382R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDGW_180_384R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDGW_1C2_450R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDGW_20B_523R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDGW_24F_591R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDGW_278_632R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDGW_288_648R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDGW_28B_651R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDGW_2A8_680R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDGW_2C2_706R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDGW_2DE_734R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDVCU_38A_906R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDGW_3C2_962R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDFR_111_273R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDFR_112_274R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDFR_113_275R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDFR_114_276R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDFR_115_277R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDFR_116_278R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDFR_117_279R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDFR_118_280R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDFR_119_281R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDFR_11A_282R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDFR_11B_283R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDFR_11C_284R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDFR_11D_285R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDFR_11E_286R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDFR_11F_287R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDFR_120_288R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDFR_136_310R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDFR_138_312R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDADC_19B_411R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDADC_200_512R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDADC_345_837R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDADC_346_838R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

FUNC(boolean, COM_APPL_CODE) GW_507_ComIPduCallout(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

FUNC(boolean, COM_APPL_CODE) GW_3DB_ComIPduCallout(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);


#endif /* CPR_STUBS_H */
