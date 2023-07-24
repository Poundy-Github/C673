/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 DIM (Driver Intention Monitoring)

PACKAGENAME:               dim20_hypothesis_mgr.h

DESCRIPTION:               Header for DIM Hypothesis Manager

AUTHOR:                    $Author: Ramachandra, Rashmi (uids9858) $

CREATION DATE:             $Date: 2020/04/01 15:46:03CEST $

VERSION:                   $Revision: 1.17 $
  
**************************************************************************** */

#ifndef DIM20_HYP_MGR_INCLUDED
#define DIM20_HYP_MGR_INCLUDED

#if (MEDIC_CFG_DRIVER_INTENTION_MONITORING)

/*****************************************************************************
  MACROS
*****************************************************************************/
/*! @brief       FeedBack buffer scale

    @general     Dim feedback buffer Scale used for AccelBuffer

    @conseq      none

    @attention   none

    @typical     none     @unit none    @min 0    @max 10   */
#define DIM_FEEDBACK_ACCEL_BUFFER_SCALE   (10.0f)

/*! @brief       FeedBack Filter time

    @general     Dim feedback use for fliter time defination

    @conseq      none

    @attention   none

    @typical     none     @unit none    @min 0    @max 0.25   */
#define DIM_FEEDBACK_DEF_GRAD_FILTER_TIME (0.25f)

/*! @brief       Mask to extract the signal applicability data from the 
                 signal to hypothesis mapping table for attention hypothesis
                 Extract data from the bit which indicates whether the signal
                 is applicable or not for attention hypothesis. */
#define DIM_SIG_ATTENTION_MASK            ((uint8)0x01)

/*! @brief       Mask to extract the signal applicability data from the 
                 signal to hypothesis mapping table for feedback hypothesis
                 Extract data from the bit which indicates whether the signal
                 is applicable or not for feedback hypothesis */
#define DIM_SIG_FEEDBACK_MASK             ((uint8)0x02)

/*! @brief       Mask to extract the signal applicability data from the 
                 signal to hypothesis mapping table for activity hypothesis
                 Extract data from the bit which indicates whether the signal
                 is applicable or not for activity hypothesis */
#define DIM_SIG_ACTIVITY_MASK             ((uint8)0x04)

/*! @brief       Mask to extract the signal applicability data from the 
                 signal to hypothesis mapping table for object-seen hypothesis
                 Extract data from the bit which indicates whether the signal
                 is applicable or not for object-seen hypothesis */
#define DIM_SIG_OBJECTSEEN_MASK           ((uint8)0x08)

/*! @brief      Threshold for driver gaze zone strongly observed
    @general    Threshold for driver gaze zone strongly observed
    @conseq     -
    @attention  -
    @typical    0.5    @unit  prob   @min 0.0   @max 1.0   */
#define DIM_DRVRLOS_PAR_AOI_STRONGLY_OBSRVD_THRES   (0.5f)

/*! @brief      Threshold for driver gaze zone observed
    @general    Threshold for driver gaze zone observed
    @conseq     -
    @attention  -
    @typical    0.4    @unit  prob   @min 0.0   @max 1.0   */
#define DIM_DRVRLOS_PAR_AOI_OBSRVD_THRES            (0.4f)

/*! @brief      Threshold for driver gaze zone weakly observed
    @general    Threshold for driver gaze zone weakly observed
    @conseq     -
    @attention  -
    @typical    0.5    @unit  prob   @min 0.0   @max 1.0   */
#define DIM_DRVRLOS_PAR_AOI_WEAKLY_OBSRVD_THRES     (0.2f)

/*! @brief       Macro to combine all the hypothesis applicability info for
                 a particular signal into one single byte.
                 For example, if sig1 is used in attention and activity, and
                 not in feedback hypothesis, then the macro would perform the following:
                 the table would look like 
                 SIGTOHYPOMAP(MEDIC_ON,MEDIC_OFF,MEDIC_ON        )
                 the evaluation would be like,
                 ((DIM_SIG_ATTENTION_MASK & (1))|(DIM_SIG_FEEDBACK_MASK & ((0)<<1))|(DIM_SIG_ACTIVITY_MASK & ((1)<<2)))
                 = 0x01 | 0x00 |0x04
                 = 0x05

                 so the signal's usage for different hypothesis is indicated using 3 LSB bits of a byte, 
                 each bit referring to a hypothesis. To access these bits, the masks are defined.

                 Many new hypothesis can be accommodated as there are many other unused bits for a signal */
#define SIGTOHYPOMAP(attn,feedbck,actvty,objseen)    ((DIM_SIG_ATTENTION_MASK & (attn))|        \
                                                      (DIM_SIG_FEEDBACK_MASK & ((feedbck)<<1))| \
                                                      (DIM_SIG_ACTIVITY_MASK & ((actvty)<<2))|  \
                                                      (DIM_SIG_OBJECTSEEN_MASK & ((objseen)<<3)))

#define DRIVER_FOV_LEFT_END                -90.0f
#define DRIVER_FOV_RIGHT_END                90.0f
#define DRIVER_LOS_STDEV_NORMDIST           2.0f

#define DIM_INPUT_NUM_OF_VEH_SIG            ((uint8)SpeedLimiter)

/*****************************************************************************
  PROTOTYPES
*****************************************************************************/
/* extern functions */
extern void DIMRunHypothesisEval( const float32 fCycleTime);
extern void DIMInitHypothesisMgr(void);

#endif /* MEDIC_CFG_DRIVER_INTENTION_MONITORING */
#endif /* DIM_HYP_MGR_INCLUDED */

