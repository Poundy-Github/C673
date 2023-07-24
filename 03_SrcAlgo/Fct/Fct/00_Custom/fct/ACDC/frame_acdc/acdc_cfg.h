/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACDC (Advanced collision detection and classification)

PACKAGENAME:               acdc_cfg.h

DESCRIPTION:               configuration file for ACDC (Advanced collision detection and classification)

AUTHOR:                    $Author: Abdelkarim, Mohamed (uidp9659) $

CREATION DATE:             $Date: 2019/04/23 11:23:15CEST $

VERSION:                   $Revision: 1.29.14.2 $
**************************************************************************** */

#ifndef ACDC_CFG_H_INCLUDED
#define ACDC_CFG_H_INCLUDED

#include "acdc_ext.h"
/*!
@defgroup     frame_cfg Configuration
@ingroup      frame
@brief        Contains all configuration switches that are relevant for the ACDC Component.\n\n

@description  Contains switches for :
              - The counting of provide and require ports
              - Switching of the subcomponents
              - Switching of functionalities of ACDC
              .
              Relations between the subcomponent switches: \n
              1: Switch has to be active \n
              0: Switch has to be inactive \n
              X: Switch has no effect \n
              -: State is not possible \n
              .
              |               |Frame On |AIP On   |CD On    |EMP On   |ESPM On  |SFL On   |
              |:--------------|:--------|:--------|:--------|:--------|:--------|:--------|
              |ACDC_CFG_FRAME |    1    |    1    |    1    |    1    |    1    |    X    |
              |ACDC_CFG_CD    |    X    |    X    |    1    |    X    |    X    |    X    |
              |ACDC_CFG_EMP   |    X    |    1    |    1    |    1    |    X    |    X    |
              |ACDC_CFG_ESPM  |    X    |    X    |    X    |    X    |    1    |    X    |
              |ACDC_CFG_SFL   |    1    |    1    |    1    |    1    |    1    |    1    |

              |               |Frame Off|AIP Off  |CD Off   |EMP Off  |ESPM Off |SFL Off  |
              |:--------------|:--------|:--------|:--------|:--------|:--------|:--------|
              |ACDC_CFG_FRAME |    0    |    X    |    X    |    X    |    X    |    0    |
              |ACDC_CFG_CD    |    0    |    0    |    0    |    0    |    X    |    0    |
              |ACDC_CFG_EMP   |    0    |    X    |    X    |    0    |    X    |    0    |
              |ACDC_CFG_ESPM  |    0    |    X    |    X    |    X    |    0    |    0    |
              |ACDC_CFG_SFL   |    X    |    1    |    1    |    1    |    1    |    0    |
@{
*/

/************************************************************************/
/*                              Ports                                   */
/************************************************************************/

/*! @brief    Macro to determine the current number of require ports. Has to be aligned with the structure @ref reqACDCPrtList_t*/
#define ACDC_NOF_REQ_PORTS  (   ( (uint8)(0                                     ) )                        \
                              + ( (uint8)(1                                     ) ) /*pEgoDynRaw*/         \
                              + ( (uint8)(1                                     ) ) /*pEgoStaticData*/     \
                              + ( (uint8)(1                                     ) ) /*pEmGenObjList*/      \
                              + ( (uint8)(1                                     ) ) /*pSenCtrlData*/       \
                              + ( (uint8)(!FCT_CFG_SHORT_RANGE_FUNCTIONS        ) ) /*pEgoDynObjSync*/     \
                              + ( (uint8)(FCT_CFG_EM_FCT_CYCLEMODE              ) ) /*pEmFctCycleMode*/    \
                              + ( (uint8)(FCT_USE_EM_CUSTOM_OBJECT_LIST         ) ) /*pEmCustObjList*/     \
                              + ( (uint8)(FCT_USE_EM_ARS_TECH_OBJECT_LIST       ) ) /*pEmARSObjList*/      \
                              + ( (uint8)(FCT_USE_EM_CAM_TECH_OBJECT_LIST       ) ) /*pEmCamObjList*/      \
                              + ( (uint8)(FCT_CFG_ALIGNMENT_MONITORING_INPUT    ) ) /*pAlignmentMonInput*/ \
                              + ( (uint8)(FCT_CFG_BSW_ALGO_PARAMS               ) ) /*pBswAlgoParameters*/ \
                              + ( (uint8)(FCT_CFG_INCLUDE_FUSION_OBJECT_LIST    ) ) /*pEmFusionObjList*/   \
                              + ( (uint8)(    (FCT_CFG_COLLISION_DETECTION    )     /*pSLATE_CD_Data*/     \
                                           && (FCT_CFG_ADAPTIVE_CRUISE_CONTROL) ) ) )

/*! @brief    Macro to determine the current number of provide ports. Has to be aligned with the structure @ref provACDCPrtList_t*/
#define ACDC_NOF_PRO_PORTS  (   ( (uint8)(0                                 ) )                        \
                              + ( (uint8)(1                                 ) )   /*pErrorOut*/        \
                              + ( (uint8)(FCT_CFG_USE_ALGOCOMPSTATE         ) )   /*pSenCompState*/    \
                              + ( (uint8)(FCT_CFG_COLLISION_DETECTION       ) )   /*pHypotheses*/      \
                              + ( (uint8)(FCT_CFG_CD_CUSTOM_OUTPUT_INTERFACE) ) ) /*pCDCustomOutput*/


/************************************************************************/
/*                        Subcomponents                                 */
/************************************************************************/

/*! @brief  ACDC Frame switch */
#define ACDC_CFG_FRAME                                      FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_ACDC_COMPONENT, SWITCH_ON)

/*! @brief  Switch to enable the ACDC Input processing */
#define ACDC_CFG_AIP                                        FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_ACDC_COMPONENT, SWITCH_ON)

/*! @brief  ACDC collision detection (CD) switch */
#define ACDC_CFG_CD                                         FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_ACDC_COMPONENT, SWITCH_ON)

/*! @brief  Switch for the EBA Signal Performance Degradation (ESPM) subcomponent*/
#define ACDC_CFG_ESPM                                       FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_ACDC_COMPONENT, SWITCH_ON)

/*! @brief  Switch for the Environment Model prediction (EMP) subcomponent. */
#define ACDC_CFG_EMP                                        FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_ACDC_COMPONENT, SWITCH_ON)

/*! @brief  Switch for the Safety Functions Library (SFL)*/
#define ACDC_CFG_SFL                                        FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_ACDC_COMPONENT, SWITCH_ON)


/************************************************************************/
/*                        Functionalities                               */
/************************************************************************/

/*! @brief  ACDC turn assist switch */
#define ACDC_CFG_TURN_ASSIST                                (SWITCH_OFF)

/*! @brief  Switch to enable the circle based overlap calculation*/
#define ACDC_CFG_USE_OBJECT_CIRCLES                         (SWITCH_ON)

/*! @brief  Activates the check of the signal headers time stamp of all require ports 
            in the function @ref ACDC_b_SetupPorts*/
#define ACDC_CFG_USE_ALGO_SIGHEADER_TIMESTAMP_CHECK         (SWITCH_OFF)

/*! @brief  Activates the calculation of the Trajectory occupancy
            @attention: Very Runtime consuming! */
#define ACDC_CFG_CALC_TRAJ_OCCUPANCY                        (SWITCH_OFF)

/************************************************************************/
/*                  Object and Ego Manipulations                        */
/************************************************************************/

/*! @brief  Activates the use of object boxes for the ACDC internal object representation.*/
#define ACDC_CFG_USE_EBA_BOX_OBJECTS                        (SWITCH_ON)

/*! @brief  Activates the class based size limitation of the shape point based 
            objects. Only relevant if @ref ACDC_CFG_USE_EBA_BOX_OBJECTS or 
            @ref ACDC_CFG_USE_OBJECT_CIRCLES are active */
#define ACDC_CFG_LIMIT_SHAPE_POINT_OBJECT_SIZE              (SWITCH_ON)

/*! @brief Filter object movement with unknown dynamics */
#define ACDC_CFG_FILTER_UNKNOWN_DYNAMIC                     (SWITCH_OFF)

/*! @brief Manipulate object acceleration of VRUs */
#define ACDC_CFG_FILTER_OBJ_KINEMATIC_OF_VRUS               (SWITCH_ON)

/*! @brief Manipulate object acceleration if ego is braking */
#define ACDC_CFG_FILTER_OBJ_KINEMATIC_IF_EGO_IS_BRAKING     (SWITCH_OFF)

/*! @brief Assumed ego width */
#define ACDC_CFG_USE_REAL_EGO_DIMENSION                     (SWITCH_OFF)


/************************************************************************/
/*                      Interface Adaptations                           */
/************************************************************************/

/*! @brief        Activates the use of the hypothesis type @ref CDHypothesisType_RunupCoMoving.
    @description  In some projects the hypothesis type CDHypothesisType_RunupCoMoving is defined 
                  but not used in the configuration of the MEDIC component. Due to legacy reasons 
                  in these projects CDHypothesisType_RunUp is used instead. If this switch is inactive, 
                  all hypothesis types RunupComoving are overwritten with RunUp in the function 
                  @ref CDHypSelCopySingleIntToExtHypothesis.
                  This switch has to be inactive in interface versions that are older than 
                  (FCT_HYPOTHESIS_INTFVER = 0x00001C) */
#define ACDC_CFG_USE_HYP_TYPE_RUNUP_COMOVING                ((SWITCH_OFF) && (FCT_HYPOTHESIS_INTFVER >= 0x00001C))


/************************************************************************/
/*                      Testing & Debugging                             */
/************************************************************************/

/*! @brief Simulate additional longitudinal offset */
#define ACDC_CFG_USE_ADD_OFFSET_SIMU                         (SWITCH_OFF)
#if ACDC_CFG_USE_ADD_OFFSET_SIMU
#pragma message(__FILE__ "(" STRING_QUOTE(__LINE__)"): warning : Offset manipulation is enabled in code. Make sure this is only done for Test-Builds.")
#endif

///@}
#endif


