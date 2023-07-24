/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 FCT / CD / EPF (Evasion Possibility Front)

PACKAGENAME:               cd_epf.h

DESCRIPTION:               EPF Main Header File

AUTHOR:                    $Author: uidn4751 $

CREATION DATE:             $Date: 2019/06/03 16:41:23CEST $

VERSION:                   $Revision: 1.8 $

LEGACY VERSION:            Revision: 1.5
 
**************************************************************************** */
#ifndef EPF_H_INCLUDED
#define EPF_H_INCLUDED
/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "cd_int.h"

#if (ACDC_CFG_CD)

#if (CD_USE_EPF)

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup cd_epf EPF
@brief
@description
@ingroup cd
@{
*/

/*! @brief if EPF left corridor side is undefined*/
#ifndef EPF_SIDE_LEFT
#define EPF_SIDE_LEFT 0u
#endif

/*! @brief if EPF right corridor side is undefined*/
#ifndef EPF_SIDE_RIGHT
#define EPF_SIDE_RIGHT 1u
#endif

 /************************************************************************/
 /*                           TYPEDEFS                                   */
 /************************************************************************/
/*! @brief EPF Corridor contains members like left, right and probability*/
typedef struct 
{
  float32 fYLeft;
  float32 fYRight;
  float32 fProb;
} EPFCorridor_t;

/*! @brief EPF Corridor contains members like left, right*/
typedef struct
{
  EPFCorridor_t Left;
  EPFCorridor_t Right;
} EPFCorridors_t;

/*! @brief Description of an area*/
typedef struct
{
  float32 fXNear;
  float32 fXFar;
  float32 fYLeft;
  float32 fYRight;
} EPFArea_t;

/*! @brief EPF Object which contains members like current kinematics, predicted kinematics, and width.*/
typedef struct
{
  CDMovement_t sKinNow;
  CDMovement_t sKinPred;
  float32      fWidth;
  float32      fLength;
  float32      fSafetyDist;
  float32      fANec;
} EPFObj_t;

/*! @brief EPF side description for left and right indication.*/
typedef uint8 eEPFSideInt_t;

/******************************************************************
  EPF Settings
 ******************************************************************/
/*! @brief        
    @description  This macro had been deleted. The set velocity of 2 m/s was selected 
                  randomly to make the module compilable!
                  In case the EPF is reactivated, test to validate or find more reasonable value!*/
#define CD_EPF_LATERAL_VELOCITY_THRESHOLD             (    2.0f)
/*! @brief        EPF qualifier to indicate state inactive
    @description  This parameter used for transition state inactive.\n
                  @typical 16u @unit [-] @range [0,65535]   */
#define EPF_QUALIFIER_STATE_INACTIVE                  (     16u)
/*! @brief        EPF qualifier to indicate state if function reports any error
    @description  This parameter used for transition state if error occurred.\n
                  @typical 96u @unit [-] @range [0,65535]   */
#define EPF_QUALIFIER_STATE_FUNCTION_REPORTS_ERROR    (     96u)
/*! @brief        EPF qualifier to indicate state active
    @description  This parameter used for transition state active.\n
                  @typical 144u   @unit [-] @range [0,65535]   */
#define EPF_QUALIFIER_STATE_ACTIVE                    (    144u)
/*! @brief        EPF qualifier to indicate state active from iBrake Obstacle
    @description  This parameter used for transition state active.\n
                  @typical 144u @unit [-] @range [0,65535]   */
#define EPF_QUALIFIER_STATE_ACTIVE_IBRAKE             (    145u)
/*! @brief        EPF qualifier to indicate state active from Pedestrian Obstacle
    @description  This parameter used for transition state active.\n
                  @typical 144u @unit [-] @range [0,65535]   */
#define EPF_QUALIFIER_STATE_ACTIVE_PFGS               (    146u)
/*! @brief        EPF qualifier to indicate state of fall back for a short time span
    @description  This parameter used for transition state fall back for short time.\n
                  @typical 160u @unit [-] @range [0,65535]   */
#define EPF_QUALIFIER_STATE_FALL_BACK_TEMPORARILY     (    160u)
/*! @brief        EPF qualifier to indicate state of fall back for unspecified time span
    @description  This parameter used for transition state fall back.\n
                  @typical 176u @unit [-] @range [0,65535]   */
#define EPF_QUALIFIER_STATE_FALL_BACK                 (    176u)
/*! @brief        EPF qualifier to indicate state is interface is not available
    @description  This parameter used for transition state interface unavailability.\n
                  @typical 224u @unit [-] @range [0,65535]   */
#define EPF_QUALIFIER_STATE_INTERFACE_NOT_AVAILABLE   (    224u)
/*! @brief        EPF qualifier to indicate state if signal is unfilled
    @description  This parameter used for transition state in case signal is not 
                  properly initialized or not properly filled with data.\n
                  @typical 255u @unit [-] @range [0,65535] */
#define EPF_QUALIFIER_STATE_SIGNAL_UNFILLED           (    255u)
/*! @brief       EPF Target Shape Coordinated Init Value
    @general     This parameter used for initialising X & Y Max values in computing Target Width and Length 
    @attention   [none]*/
#define EPF_SPC_MIN_VAL                               ( -999.0f)
/*! @brief       EPF Target Shape Coordinated Init Value
    @general     This parameter used for initialising X & Y Min values in computing Target Width and Length.
    @attention   [none]*/
#define EPF_SPC_MAX_VAL                               ( +999.0f)


/*****************************************************************************
  LOCAL FUNCTION DECLARATIONS
*****************************************************************************/
static boolean EPFObjIsValidObstacle(ObjNumber_t const ObjID, ObjNumber_t const TargetID);
static void    EPFLimitAbsValue(float32* fVal, float32 fMaxAbs);
static boolean EPFAreasIntersect(const EPFArea_t* psArea1, const EPFArea_t* psArea2);
static boolean EPFAreaInArea(const EPFArea_t* psAreaSmall, const EPFArea_t* psAreaBig);

static void EPFInitCorridors(const EPFObj_t* psInTarget, EPFCorridors_t* psCorridors);
static void EPFFillEPFObj(ObjNumber_t const ObjID, fTime_t const fPredTime, EPFObj_t* const pOutEPFObj );
static void EPFPredictObjectKinematic( const CDMovement_t* psKinNow, fTime_t predTime, CDMovement_t* psKinPred );

static void EPFReduceCorridorBySection(float32 fSectionYLeft, float32 fSectionYRight, eEPFSideInt_t eSideToReduceFrom, EPFCorridor_t* psCorridor);
static void EPFApplyObjToCorridors(const EPFObj_t* pInObj, const EPFObj_t* pInTarget, EPFCorridors_t* psCorridors);

static void EPFResetOutput(EPFOutput_t* pEPFOutput);
#if defined(CD_EPF_CORRIDOR_FREEZE) && (CD_EPF_CORRIDOR_FREEZE == SWITCH_ON)
static void EPFResetCorridors(void);
static void EPFFreezeCorridors(ObjNumber_t const TargetID, EPFOutput_t *const pEPFOutput);
#endif /* CD_EPF_CORRIDOR_FREEZE */
static void EPFSceneValid(ObjNumber_t const RelObjID,boolean * const pbOutSceneValid);

static void EPFCalcOutputOrientation(EPFOutput_t* const pEPFOutput);
static void EPFCalcOutputTarget(ObjNumber_t const TargetID, EPFOutput_t *const pEPFOutput);
static void EPFCalcOutputCorridors(ObjNumber_t const TargetID, EPFOutput_t * const pEPFOutput);

static void EPFLateralVelFilter(ObjNumber_t const TargetID,EPFOutput_t *const pEPFOutput);
static void EPFillTargetDimFromSPC(ObjNumber_t const ObjID, EPFObj_t * const pOutEPFObj );

///@}
#endif /* #if (CD_USE_EPF) */

#endif /* (ACDC_CFG_CD)*/
#endif /*EPF_H_INCLUDED */
