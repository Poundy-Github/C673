/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head_custOutput.h

DESCRIPTION:               Implementation of the head output custom interface

AUTHOR:                    $Author: Muddaveeraiah, Nalina (uidn6869) $

CREATION DATE:             $Date: 2020/06/14 02:13:37CEST $

VERSION:                   $Revision: 1.4.2.6 $

LEGACY VERSION:            1.8

**************************************************************************** */
/**
@ingroup head_custOutput
@{ **/
#ifndef HEAD_CUSTOUT_H_INCLUDED
#define HEAD_CUSTOUT_H_INCLUDED

/** @cond */
#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)
/** @endcond */
typedef struct 
{
 eEBASignalState_t HEADLatPreWarnSigState;   /* @brief LatPreWarn EBA signal state */
 eEBASignalState_t HEADLatAcuteWarnSigState; /* @brief LatAcuteWarn EBA signal state */
 eEBASignalState_t HEADPreWarnSignal;        /* @brief PreWarn EBA signal state */
 eEBASignalState_t HEADAcuteWarnSignal;      /* @brief AcuteWarn EBA signal state */
 eEBASignalState_t locHEADAcuteWarnSignal;   /*! @brief HEAD module acute warning signal state*/

}EBASignalState_t;

typedef struct 
{
 eEBAFctChan_t HEADLatPreWarnFctChannel;     /*! @brief LatPreWarn EBA FCt channel initialized */
 eEBAFctChan_t HEADLatAcuteWarnFctChannel;   /*! @brief LatAcuteWarn EBA FCt channel initialized*/
 eEBAFctChan_t HEADPreWarnFctChannel;        /*! @brief PreWarn EBA FCt channel initialized*/
 eEBAFctChan_t HEADAcuteWarnFctChannel;      /*! @brief AcuteWarn EBA FCt channel initialized*/
 eEBAFctChan_t HEADBrakeFctChannel;          /*! @brief Brake EBA FCt channel initialized*/
 eEBAFctChan_t HEADPrefillFctChannel;        /*! @brief Prefill EBA FCt channel initialized*/
 eEBAFctChan_t FctChanArbitrated;            /*! @brief HBA level :FCT Channel Arbitrated*/
 eEBAFctChan_t FctChanArbitratedLastCycle;   /*! @brief HBA level :buffer for FCT Channel in last cycle*/
}EBAFctChan_t;

typedef struct
{
 uint8 HEADAcuteWarnActiveHyp;
 uint8 HEADMaxBrkLevel;                      /*! @brief Maximum reached level brake activation during one event */
 #if (MEDIC_CFG_EBA_2ND_SENSOR_CONFIRMATION)
 boolean HEADPreBrakeCamConfirm;             /*! @brief Latched video confirmation state before ramp-out */
 #endif
}HEADCustOutputLocVar_t;
/*****************************************************************************
  INCLUDES
*****************************************************************************/
/*****************************************************************************
  FUNCTION PROTOTYPES (EXTERNAL SCOPE)
*****************************************************************************/
extern eGDBError_t HEADInitOutput(void);
extern eGDBError_t HEADOutArbitration(void);
extern void HEADCustomOutputInit(void);
extern eGDBError_t HEADCustomOutputSet(void);

/*****************************************************************************
  INLINE FUNCTION
*****************************************************************************/

#endif  /* #if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION) */
#endif /* _HEAD_CUSTOUT_H_INCLUDED */
/**@}*/ 
