/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head_codingSwitches.h

DESCRIPTION:               header of the head wrapper

AUTHOR:                    $Author: Muddaveeraiah, Nalina (uidn6869) $

CREATION DATE:             $Date: 2020/06/14 02:13:15CEST $

VERSION:                   $Revision: 1.3.1.5 $

LEGACY VERSION:            1.7

**************************************************************************** */
/**
@ingroup head_codingSwitches
@{ **/
#ifndef HEAD_CODINGSWITCHES_H_INCLUDED
#define HEAD_CODINGSWITCHES_H_INCLUDED

/** @cond */
#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)
/** @endcond */

/*****************************************************************************
  MACROS 
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS ENUM Switch_Function_t
*****************************************************************************/
/*! @brief Switch_Function_t
    @general Switch function types for the coding (Moving, Stationary)
    @conseq -
    @attention */
typedef enum
{
  Switch_DW   = 0,             /*!< switch function for distance warning     */
  Switch_FCW1 = 1,             /*!< switch function for first level warning  */
  Switch_FCW2 = 2,             /*!< switch function for second level warning */
  Switch_FCW3 = 3,             /*!< switch function for  third level warning */
  Switch_BRK  = 4              /*!< switch function for break warning        */
} Switch_Function_t;

/*****************************************************************
    TYPEDEF STRUCT HEADCustomCodingInfo_t
*****************************************************************/
/*! @brief Head Custom Coding Info
    @general Head Custom Coding Info
    @conseq -
    @attention - */
typedef struct 
{
  /*Coding Infos*/
  boolean CodeGenLowSpeedBitActive;         /*!< Enables reaction at vehicle low speed */
  boolean CodeGenCountryCodeAActive;        /*!< Switches between country variants     */
  boolean CodeGenCountryCodeBActive;        /*!< Switches between country variants     */
  boolean CodeGenIgnoreSelfCheckBitActive;  /*!< Name and meaning to be checked        */
  boolean CodeGenDebugMessagesBitActive;    /*!< Switches to enable debugmessages      */
  boolean CodeGenDistanceLimitBitActive;    /*!< Switches to control distance limit    */
  boolean CodeGenIgnoreActivationSwitch;    /*!< Ignore Activation Switch coded        */
  boolean paddingByte;                      /*!< Workaround to cope with some MTS-Problems on some ECUs => ensure even number of bytes in the structure*/
} HEADCustomCodingInfo_t; 

/*****************************************************************************
  GLOBAL CONSTANTS (EXTERNAL SCOPE)
*****************************************************************************/

/*****************************************************************************
  GLOBAL VARIABLES (EXTERNAL SCOPE)
*****************************************************************************/
/*! @brief Head Custom Coding Info*/
extern HEADCustomCodingInfo_t HEADCodingInfo;

/*****************************************************************************
  FUNCTION PROTOTYPES (EXTERNAL SCOPE)
*****************************************************************************/
extern eGDBError_t HEADCustomCoding(struct HEADModule_t rgModules[]);
extern const HEADCustomCodingInfo_t *HEADGetCustomCoding(void);
extern boolean HEADGetEBACoding(CPAREBACodingFctMods_t CPAR_EBA_Function, t_EBACodingParamFctModsIdx eEBACodingIdx);
extern boolean HEADGetEBASwitch(eFunctionSwitch_t FunctionBit);
extern boolean HEADGetEBASwitchHyp(Switch_Function_t eFunctionSwitch, HEADHypothesis_t const *pHyp);
extern eGDBError_t HEADCodingInhibitionCheck(HEADHypothesis_t const *pHyp, HEADBitField_t *pInhibitionMask);
#endif  /* #if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION) */

#endif /*_HEAD_CODINGSWITCHES_H_INCLUDED*/
/**@}*/
