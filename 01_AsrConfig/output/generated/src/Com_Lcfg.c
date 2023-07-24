
/**
 * \file
 *
 * \brief AUTOSAR Com
 *
 * This file contains the implementation of the AUTOSAR
 * module Com.
 *
 * \version 6.3.51
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/* MISRA-C:2012 Deviation List
 *
 *
 * MISRAC2012-1) Deviated Rule: 11.5 (advisory)
 * A conversion should not be performed from pointer to
 * void into pointer to object.
 *
 * Reason:
 * The memory routines are optimized for dealing with aligned
 * memory sections.
 *
 *
 * MISRAC2012-2) Deviated Rule: 8.5 (Required)
 * An external object or function shall be declared once in one and only one file.
 *
 * Reason:
 * The callout and callback functions are declared within the file since
 * the header files which declare the functions are in general not known.
 *
 */

/*==================[inclusions]============================================*/

#include <Com_Lcfg.h>
#include <Com_Lcfg_Static.h>
#include <TSAutosar.h>

/* start data section declaration */
#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <Com_MemMap.h>

/**
 * Internal memory statically allocated upon link-time. Size depends on
 * post build configuration. Memory requirements of post build configuration
 * must be smaller than COM_RAM_SIZE_MAX in order to avoid buffer
 * overflows. Memory is aligned to the most stringent alignment requirement
 * of any simple data type available on the respective platform, e.g. uint32.
 */
STATIC TS_DefMaxAlignedByteArray(Com_DataMem, COM, VAR_CLEARED, COM_DATA_MEM_SIZE);

/* stop data section declaration */
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <Com_MemMap.h>



/* start data section declaration */
#define COM_START_SEC_CONST_UNSPECIFIED
#include <Com_MemMap.h>

/**
 * Pointer to statically allocated RAM.
 */
/* Deviation MISRAC2012-1 <+3> */
CONSTP2VAR(uint8, COM_CONST, COM_VAR_CLEARED) Com_gDataMemPtr =
  (P2VAR(uint8, COM_CONST, COM_VAR_CLEARED))
  ((P2VAR(void, COM_CONST, COM_VAR_CLEARED)) Com_DataMem);

/* stop data section declaration */
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include <Com_MemMap.h>



#define COM_START_SEC_APPL_CODE
#include <Com_MemMap.h>

/* receive callouts */
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDGW_50_80R_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDVCU_161_353R_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDGW_170_368R_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDGW_17A_378R_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDGW_17E_382R_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDGW_180_384R_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDGW_1C2_450R_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDGW_20B_523R_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDGW_24F_591R_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDGW_278_632R_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDGW_288_648R_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDGW_28B_651R_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDGW_2A8_680R_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDGW_2C2_706R_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDGW_2DE_734R_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDVCU_38A_906R_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) GW_3BD_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDGW_3C2_962R_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) GW_507_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFR_111_273R_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFR_112_274R_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFR_113_275R_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFR_114_276R_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFR_115_277R_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFR_116_278R_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFR_117_279R_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFR_118_280R_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFR_119_281R_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFR_11A_282R_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFR_11B_283R_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFR_11C_284R_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFR_11D_285R_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFR_11E_286R_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFR_11F_287R_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFR_120_288R_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFR_136_310R_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFR_138_312R_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDADC_19B_411R_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDADC_200_512R_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) ComIPduCallout_201
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) ComIPduCallout_0x1F1
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDADC_345_837R_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDADC_346_838R_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);

/* send callouts */
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFC_107_263T_ComIPduCallout
(
  PduIdType ID,
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFC_108_264T_ComIPduCallout
(
  PduIdType ID,
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFC_150_336T_ComIPduCallout
(
  PduIdType ID,
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFC_151_337T_ComIPduCallout
(
  PduIdType ID,
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFC_152_338T_ComIPduCallout
(
  PduIdType ID,
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFC_153_339T_ComIPduCallout
(
  PduIdType ID,
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFC_154_340T_ComIPduCallout
(
  PduIdType ID,
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFC_160_352T_ComIPduCallout
(
  PduIdType ID,
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFC_161_353T_ComIPduCallout
(
  PduIdType ID,
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFC_162_354T_ComIPduCallout
(
  PduIdType ID,
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFC_163_355T_ComIPduCallout
(
  PduIdType ID,
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFC_164_356T_ComIPduCallout
(
  PduIdType ID,
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFC_165_357T_ComIPduCallout
(
  PduIdType ID,
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFC_166_358T_ComIPduCallout
(
  PduIdType ID,
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFC_167_359T_ComIPduCallout
(
  PduIdType ID,
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFC_168_360T_ComIPduCallout
(
  PduIdType ID,
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFC_169_361T_ComIPduCallout
(
  PduIdType ID,
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFC_170_368T_ComIPduCallout
(
  PduIdType ID,
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFC_171_369T_ComIPduCallout
(
  PduIdType ID,
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFC_172_370T_ComIPduCallout
(
  PduIdType ID,
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFC_173_371T_ComIPduCallout
(
  PduIdType ID,
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFC_174_372T_ComIPduCallout
(
  PduIdType ID,
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFC_175_373T_ComIPduCallout
(
  PduIdType ID,
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFC_176_374T_ComIPduCallout
(
  PduIdType ID,
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFC_177_375T_ComIPduCallout
(
  PduIdType ID,
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFC_178_376T_ComIPduCallout
(
  PduIdType ID,
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFC_179_377T_ComIPduCallout
(
  PduIdType ID,
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFC_180_384T_ComIPduCallout
(
  PduIdType ID,
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFC_181_385T_ComIPduCallout
(
  PduIdType ID,
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFC_190_400T_ComIPduCallout
(
  PduIdType ID,
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFC_193_403T_ComIPduCallout
(
  PduIdType ID,
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFC_195_405T_ComIPduCallout
(
  PduIdType ID,
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFC_196_406T_ComIPduCallout
(
  PduIdType ID,
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFC_197_407T_ComIPduCallout
(
  PduIdType ID,
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFC_198_408T_ComIPduCallout
(
  PduIdType ID,
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFC_1BA_442T_ComIPduCallout
(
  PduIdType ID,
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFC_244_580T_ComIPduCallout
(
  PduIdType ID,
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFC_307_775T_ComIPduCallout
(
  PduIdType ID,
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFC_312_786T_ComIPduCallout
(
  PduIdType ID,
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr
);
/* Deviation MISRAC2012-2 */
extern FUNC(boolean, COM_APPL_CODE) PDFC_31A_794T_ComIPduCallout
(
  PduIdType ID,
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr
);

/* TX acknowledge callbacks */

/* TX timeout callbacks */
/* extern FUNC(void, COM_APPL_CODE) Com_EB_TxDMDummyCbk(void); (extern declaration already generated)*/

/* TX error callbacks */
/* extern FUNC(void, COM_APPL_CODE) Com_EB_TxDMDummyCbk(void); (extern declaration already generated)*/

/* RX timeout callbacks */
/* Deviation MISRAC2012-2 */
extern FUNC(void, COM_APPL_CODE) GW_50_SignalTimeout(void);
/* Deviation MISRAC2012-2 */
extern FUNC(void, COM_APPL_CODE) VCU_161_SignalTimeout(void);
/* Deviation MISRAC2012-2 */
extern FUNC(void, COM_APPL_CODE) GW_170_SignalTimeout(void);
/* Deviation MISRAC2012-2 */
extern FUNC(void, COM_APPL_CODE) GW_17A_SignalTimeout(void);
/* Deviation MISRAC2012-2 */
extern FUNC(void, COM_APPL_CODE) GW_17E_SignalTimeout(void);
/* Deviation MISRAC2012-2 */
extern FUNC(void, COM_APPL_CODE) GW_180_SignalTimeout(void);
/* Deviation MISRAC2012-2 */
extern FUNC(void, COM_APPL_CODE) GW_1C2_SignalTimeout(void);
/* Deviation MISRAC2012-2 */
extern FUNC(void, COM_APPL_CODE) GW_20B_SignalTimeout(void);
/* Deviation MISRAC2012-2 */
extern FUNC(void, COM_APPL_CODE) GW_24F_SignalTimeout(void);
/* Deviation MISRAC2012-2 */
extern FUNC(void, COM_APPL_CODE) GW_278_SignalTimeout(void);
/* Deviation MISRAC2012-2 */
extern FUNC(void, COM_APPL_CODE) GW_288_SignalTimeout(void);
/* Deviation MISRAC2012-2 */
extern FUNC(void, COM_APPL_CODE) GW_2C2_SignalTimeout(void);
/* Deviation MISRAC2012-2 */
extern FUNC(void, COM_APPL_CODE) GW_2DE_SignalTimeout(void);
/* Deviation MISRAC2012-2 */
extern FUNC(void, COM_APPL_CODE) FR_111_SignalTimeout(void);
/* Deviation MISRAC2012-2 */
extern FUNC(void, COM_APPL_CODE) FR_112_SignalTimeout(void);
/* Deviation MISRAC2012-2 */
extern FUNC(void, COM_APPL_CODE) FR_113_SignalTimeout(void);
/* Deviation MISRAC2012-2 */
extern FUNC(void, COM_APPL_CODE) FR_114_SignalTimeout(void);
/* Deviation MISRAC2012-2 */
extern FUNC(void, COM_APPL_CODE) FR_115_SignalTimeout(void);
/* Deviation MISRAC2012-2 */
extern FUNC(void, COM_APPL_CODE) FR_116_SignalTimeout(void);
/* Deviation MISRAC2012-2 */
extern FUNC(void, COM_APPL_CODE) FR_117_SignalTimeout(void);
/* Deviation MISRAC2012-2 */
extern FUNC(void, COM_APPL_CODE) FR_118_SignalTimeout(void);
/* Deviation MISRAC2012-2 */
extern FUNC(void, COM_APPL_CODE) FR_119_SignalTimeout(void);
/* Deviation MISRAC2012-2 */
extern FUNC(void, COM_APPL_CODE) FR_11A_SignalTimeout(void);
/* Deviation MISRAC2012-2 */
extern FUNC(void, COM_APPL_CODE) FR_11B_SignalTimeout(void);
/* Deviation MISRAC2012-2 */
extern FUNC(void, COM_APPL_CODE) FR_11C_SignalTimeout(void);
/* Deviation MISRAC2012-2 */
extern FUNC(void, COM_APPL_CODE) FR_11D_SignalTimeout(void);
/* Deviation MISRAC2012-2 */
extern FUNC(void, COM_APPL_CODE) FR_11E_SignalTimeout(void);
/* Deviation MISRAC2012-2 */
extern FUNC(void, COM_APPL_CODE) FR_11F_SignalTimeout(void);
/* Deviation MISRAC2012-2 */
extern FUNC(void, COM_APPL_CODE) FR_120_SignalTimeout(void);
/* Deviation MISRAC2012-2 */
extern FUNC(void, COM_APPL_CODE) FR_136_SignalTimeout(void);
/* Deviation MISRAC2012-2 */
extern FUNC(void, COM_APPL_CODE) ADC_19B_SignalTimeout(void);
/* Deviation MISRAC2012-2 */
extern FUNC(void, COM_APPL_CODE) ADC_345_SignalTimeout(void);
/* Deviation MISRAC2012-2 */
extern FUNC(void, COM_APPL_CODE) ADC_346_SignalTimeout(void);

/* RX acknowledge callbacks */

#define COM_STOP_SEC_APPL_CODE
#include <Com_MemMap.h>

#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <Com_MemMap.h>


#if (COM_CALL_OUT_FUNC_PTR_ARRAY_SIZE_MAX != COM_INDEX_NONE)
#if (COM_TX_CALL_OUT_FUNC_PTR_ARRAY_SIZE > 0)
/* send callouts */
CONSTP2VAR(Com_TxCalloutType, AUTOMATIC, COM_APPL_CODE) Com_TxCallouts[COM_TX_CALL_OUT_FUNC_PTR_ARRAY_SIZE] =
{
     &PDFC_107_263T_ComIPduCallout
    ,&PDFC_108_264T_ComIPduCallout
    ,&PDFC_150_336T_ComIPduCallout
    ,&PDFC_151_337T_ComIPduCallout
    ,&PDFC_152_338T_ComIPduCallout
    ,&PDFC_153_339T_ComIPduCallout
    ,&PDFC_154_340T_ComIPduCallout
    ,&PDFC_160_352T_ComIPduCallout
    ,&PDFC_161_353T_ComIPduCallout
    ,&PDFC_162_354T_ComIPduCallout
    ,&PDFC_163_355T_ComIPduCallout
    ,&PDFC_164_356T_ComIPduCallout
    ,&PDFC_165_357T_ComIPduCallout
    ,&PDFC_166_358T_ComIPduCallout
    ,&PDFC_167_359T_ComIPduCallout
    ,&PDFC_168_360T_ComIPduCallout
    ,&PDFC_169_361T_ComIPduCallout
    ,&PDFC_170_368T_ComIPduCallout
    ,&PDFC_171_369T_ComIPduCallout
    ,&PDFC_172_370T_ComIPduCallout
    ,&PDFC_173_371T_ComIPduCallout
    ,&PDFC_174_372T_ComIPduCallout
    ,&PDFC_175_373T_ComIPduCallout
    ,&PDFC_176_374T_ComIPduCallout
    ,&PDFC_177_375T_ComIPduCallout
    ,&PDFC_178_376T_ComIPduCallout
    ,&PDFC_179_377T_ComIPduCallout
    ,&PDFC_180_384T_ComIPduCallout
    ,&PDFC_181_385T_ComIPduCallout
    ,&PDFC_190_400T_ComIPduCallout
    ,&PDFC_193_403T_ComIPduCallout
    ,&PDFC_195_405T_ComIPduCallout
    ,&PDFC_196_406T_ComIPduCallout
    ,&PDFC_197_407T_ComIPduCallout
    ,&PDFC_198_408T_ComIPduCallout
    ,&PDFC_1BA_442T_ComIPduCallout
    ,&PDFC_244_580T_ComIPduCallout
    ,&PDFC_307_775T_ComIPduCallout
    ,&PDFC_312_786T_ComIPduCallout
    ,&PDFC_31A_794T_ComIPduCallout
};
#else /* (COM_CALL_OUT_FUNC_PTR_ARRAY_SIZE > 0) */
CONSTP2VAR(Com_TxCalloutType, AUTOMATIC, COM_APPL_CODE) Com_TxCallouts[1] =
{
    NULL_PTR
};
#endif /* (COM_CALL_OUT_FUNC_PTR_ARRAY_SIZE > 0) */


#if (COM_RX_CALL_OUT_FUNC_PTR_ARRAY_SIZE > 0)
/* receive callouts */
CONSTP2VAR(Com_RxCalloutType, AUTOMATIC, COM_APPL_CODE) Com_RxCallouts[COM_RX_CALL_OUT_FUNC_PTR_ARRAY_SIZE] =
{
     &PDGW_50_80R_ComIPduCallout
    ,&PDVCU_161_353R_ComIPduCallout
    ,&PDGW_170_368R_ComIPduCallout
    ,&PDGW_17A_378R_ComIPduCallout
    ,&PDGW_17E_382R_ComIPduCallout
    ,&PDGW_180_384R_ComIPduCallout
    ,&PDGW_1C2_450R_ComIPduCallout
    ,&PDGW_20B_523R_ComIPduCallout
    ,&PDGW_24F_591R_ComIPduCallout
    ,&PDGW_278_632R_ComIPduCallout
    ,&PDGW_288_648R_ComIPduCallout
    ,&PDGW_28B_651R_ComIPduCallout
    ,&PDGW_2A8_680R_ComIPduCallout
    ,&PDGW_2C2_706R_ComIPduCallout
    ,&PDGW_2DE_734R_ComIPduCallout
    ,&PDVCU_38A_906R_ComIPduCallout
    ,&GW_3BD_ComIPduCallout
    ,&PDGW_3C2_962R_ComIPduCallout
    ,&GW_507_ComIPduCallout
    ,&PDFR_111_273R_ComIPduCallout
    ,&PDFR_112_274R_ComIPduCallout
    ,&PDFR_113_275R_ComIPduCallout
    ,&PDFR_114_276R_ComIPduCallout
    ,&PDFR_115_277R_ComIPduCallout
    ,&PDFR_116_278R_ComIPduCallout
    ,&PDFR_117_279R_ComIPduCallout
    ,&PDFR_118_280R_ComIPduCallout
    ,&PDFR_119_281R_ComIPduCallout
    ,&PDFR_11A_282R_ComIPduCallout
    ,&PDFR_11B_283R_ComIPduCallout
    ,&PDFR_11C_284R_ComIPduCallout
    ,&PDFR_11D_285R_ComIPduCallout
    ,&PDFR_11E_286R_ComIPduCallout
    ,&PDFR_11F_287R_ComIPduCallout
    ,&PDFR_120_288R_ComIPduCallout
    ,&PDFR_136_310R_ComIPduCallout
    ,&PDFR_138_312R_ComIPduCallout
    ,&PDADC_19B_411R_ComIPduCallout
    ,&PDADC_200_512R_ComIPduCallout
    ,&ComIPduCallout_201
    ,&ComIPduCallout_0x1F1
    ,&PDADC_345_837R_ComIPduCallout
    ,&PDADC_346_838R_ComIPduCallout
};
#else /* (COM_RX_CALL_OUT_FUNC_PTR_ARRAY_SIZE > 0) */
CONSTP2VAR(Com_RxCalloutType, AUTOMATIC, COM_APPL_CODE) Com_RxCallouts[1] =
{
    NULL_PTR
};
#endif /* (COM_RX_CALL_OUT_FUNC_PTR_ARRAY_SIZE > 0) */
#endif /* (COM_CALL_OUT_FUNC_PTR_ARRAY_SIZE_MAX != COM_INDEX_NONE) */


#if (COM_CBK_TX_ACK_PTR_ARRAY_SIZE_MAX != COM_INDEX_NONE)
#if (COM_CBK_TX_ACK_PTR_ARRAY_SIZE > 0)
CONSTP2VAR(Com_CbkTxAck_Type, AUTOMATIC, COM_RTE_CODE) Com_CbkTxAck_Array[COM_CBK_TX_ACK_PTR_ARRAY_SIZE] =
{
};
#else /* (COM_CBK_TX_ACK_PTR_ARRAY_SIZE > 0) */
CONSTP2VAR(Com_CbkTxAck_Type, AUTOMATIC, COM_RTE_CODE) Com_CbkTxAck_Array[1] =
{
    NULL_PTR
};
#endif /* (COM_CBK_TX_ACK_PTR_ARRAY_SIZE > 0) */
#endif /* (COM_CBK_TX_ACK_PTR_ARRAY_SIZE_MAX != COM_INDEX_NONE) */


#if (COM_CBK_TX_T_OUT_ARRAY_SIZE_MAX != COM_INDEX_NONE)
#if (COM_CBK_TX_T_OUT_ARRAY_SIZE > 0)
CONSTP2VAR(Com_CbkTxTOut_Type, AUTOMATIC, COM_RTE_CODE) Com_CbkTxTOut_Array[COM_CBK_TX_T_OUT_ARRAY_SIZE] =
{
     &Com_EB_TxDMDummyCbk
};
#else /* (COM_CBK_TX_T_OUT_ARRAY_SIZE > 0) */
CONSTP2VAR(Com_CbkTxTOut_Type, AUTOMATIC, COM_RTE_CODE) Com_CbkTxTOut_Array[1] =
{
    NULL_PTR
};
#endif /* (COM_CBK_TX_T_OUT_ARRAY_SIZE > 0) */
#endif /* (COM_CBK_TX_T_OUT_ARRAY_SIZE_MAX != COM_INDEX_NONE) */


#if (COM_CBK_TX_ERR_PTR_ARRAY_SIZE_MAX != COM_INDEX_NONE)
#if (COM_CBK_TX_ERR_PTR_ARRAY_SIZE > 0)
CONSTP2VAR(Com_CbkTxErr_Type, AUTOMATIC, COM_RTE_CODE) Com_CbkTxErr_Array[COM_CBK_TX_ERR_PTR_ARRAY_SIZE] =
{
     &Com_EB_TxDMDummyCbk
};
#else /* (COM_CBK_TX_ERR_PTR_ARRAY_SIZE > 0) */
CONSTP2VAR(Com_CbkTxErr_Type, AUTOMATIC, COM_RTE_CODE) Com_CbkTxErr_Array[1] =
{
    NULL_PTR
};
#endif /* (COM_CBK_TX_ERR_PTR_ARRAY_SIZE > 0) */
#endif /* (COM_CBK_TX_ERR_PTR_ARRAY_SIZE_MAX != COM_INDEX_NONE) */


#if (COM_CBK_RX_ACK_PTR_ARRAY_SIZE_MAX != COM_INDEX_NONE)
#if (COM_CBK_RX_ACK_PTR_ARRAY_SIZE > 0)
CONSTP2VAR(Com_CbkRxAck_Type, AUTOMATIC, COM_RTE_CODE) Com_CbkRxAck_Array[COM_CBK_RX_ACK_PTR_ARRAY_SIZE] =
{
};
#else /* (COM_CBK_RX_ACK_PTR_ARRAY_SIZE > 0)) */
CONSTP2VAR(Com_CbkRxAck_Type, AUTOMATIC, COM_RTE_CODE) Com_CbkRxAck_Array[1] =
{
    NULL_PTR
};
#endif /* (COM_CBK_RX_ACK_PTR_ARRAY_SIZE > 0)) */
#endif /* (COM_CBK_RX_ACK_PTR_ARRAY_SIZE_MAX != COM_INDEX_NONE) */


#if (COM_CBK_RX_T_OUT_ARRAY_SIZE_MAX != COM_INDEX_NONE)
#if (COM_CBK_RX_T_OUT_ARRAY_SIZE > 0)
CONSTP2VAR(Com_CbkRxTOut_Type, AUTOMATIC, COM_RTE_CODE) Com_CbkRxTOut_Array[COM_CBK_RX_T_OUT_ARRAY_SIZE] =
{
     &GW_50_SignalTimeout
    ,&VCU_161_SignalTimeout
    ,&GW_170_SignalTimeout
    ,&GW_17A_SignalTimeout
    ,&GW_17E_SignalTimeout
    ,&GW_180_SignalTimeout
    ,&GW_1C2_SignalTimeout
    ,&GW_20B_SignalTimeout
    ,&GW_24F_SignalTimeout
    ,&GW_278_SignalTimeout
    ,&GW_288_SignalTimeout
    ,&GW_2C2_SignalTimeout
    ,&GW_2DE_SignalTimeout
    ,&FR_111_SignalTimeout
    ,&FR_112_SignalTimeout
    ,&FR_113_SignalTimeout
    ,&FR_114_SignalTimeout
    ,&FR_115_SignalTimeout
    ,&FR_116_SignalTimeout
    ,&FR_117_SignalTimeout
    ,&FR_118_SignalTimeout
    ,&FR_119_SignalTimeout
    ,&FR_11A_SignalTimeout
    ,&FR_11B_SignalTimeout
    ,&FR_11C_SignalTimeout
    ,&FR_11D_SignalTimeout
    ,&FR_11E_SignalTimeout
    ,&FR_11F_SignalTimeout
    ,&FR_120_SignalTimeout
    ,&FR_136_SignalTimeout
    ,&ADC_19B_SignalTimeout
    ,&ADC_345_SignalTimeout
    ,&ADC_346_SignalTimeout
};
#else /* (COM_CBK_RX_T_OUT_ARRAY_SIZE > 0) */
CONSTP2VAR(Com_CbkRxTOut_Type, AUTOMATIC, COM_RTE_CODE) Com_CbkRxTOut_Array[1] =
{
    NULL_PTR
};
#endif /* (COM_CBK_RX_T_OUT_ARRAY_SIZE > 0) */
#endif /* (COM_CBK_RX_T_OUT_ARRAY_SIZE_MAX != COM_INDEX_NONE) */


#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <Com_MemMap.h>


/* start data section declaration */
#define COM_START_SEC_CONST_32
#include <Com_MemMap.h>

/**
 * Variable holding link-time configuration
 */
CONST(uint32, COM_CONST) Com_LcfgSignature = COM_LCFG_SIGNATURE;

/* stop data section declaration */
#define COM_STOP_SEC_CONST_32
#include <Com_MemMap.h>

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
