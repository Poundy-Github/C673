/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS5xx

CPU:                       CPU-Independent

COMPONENT:                 CAL (Common ACC Library)

PACKAGENAME:               cal_std_ext.h

DESCRIPTION:               All standard math functions like min/max operators

AUTHOR:                    Shang, Hanyu

CREATION DATE:             27.02.2017

VERSION:                   $Revision: 1.8 $

LEGACY VERSION:            Revision: 1.9.1.1

**************************************************************************** */
#ifndef CAL_STD_INCLUDED
#define CAL_STD_INCLUDED

#include "fct_glob_ext.h"
#include "fct_types.h"

/** @defgroup fct_mat_std CAL_STD
@brief       Function used to perform the standard mathematical operations
   @ingroup fct_veh

@{ */

/* Special min/max defines previously present in fct_types.h, but only used by MAT and
modules that use MAT, thus moved here */
#define Signed_int16_min    (-32767)
#define Signed_int16_max    32766
#define Signed_int32_max    2147483647L

/* FUNKTION PROTOTYPES (KOMPONENT EXTERNAL) */
extern sint32 MAT_MIN(sint32 Val1, sint32 Val2);
extern sint32 MAT_MAX(sint32 Val1, sint32 Val2);
extern sint32 MAT_LIM(sint32 Val,  sint32 Lim1, sint32 Lim2);
extern sint32 MAT_FILT(sint32 NewVal, sint32 OldVal, sint32 FilterDepth);
extern sint32 MAT_ABS(sint32 i);
extern sint32 MAT_DIFF_DT(sint32 New, sint32 Old, times_t Cycle);
#if (0) /* Disabling unused functions */
extern sint32 MAT_INT_DT(sint32 New, sint32 Old, sint32 OldInt, times_t Cycle);
#endif /* (0) Unused functions */
extern sint32 MAT_LIM_GRAD(sint32 New, sint32 Old, sint32 max_neg_grad, sint32 max_pos_grad, times_t Cycle);
extern sint32 MAT_PT1_FILTER(const times_t cycle_time, times_t time_constant, sint32 input_value, sint32 output_value_last_cycle);
extern sint32 MAT_SQRT(sint32 Val);
extern sint8  MAT_SIGN(sint32 Val);
extern sint32 MAT_MUL(sint32 Val1, sint32 Val2, sint32 Val1Scale, sint32 Val2Scale, sint32 ReturnScale);
extern sint32 MAT_DIV(sint32 Val1, sint32 Val2, sint32 Val1Scale, sint32 Val2Scale, sint32 ReturnScale);
#if (0) /* Disabling unused functions */
extern sint16 MAT_SIN(sint32 Val);
extern sint16 MAT_COS(sint32 Val);
extern sint16 MAT_TAN(sint32 Val);
extern sint32 MAT_QUANT(sint32 Val, sint32 LastVal, sint32 MinVal, sint32 MaxVal, sint32 Res, percentage_t DutyCycle);
extern sint16 MAT_S16_SUB_S16_S16(sint16 x_value, sint16 y_value);
extern uint8 MAT_U8_SUB_U8_U8(uint8 x_value, uint8 y_value);
extern uint16 MAT_U16_SUB_U16_U16(uint16 x_value, uint16 y_value);
extern sint8 MAT_S8_SUB_S8_S8(sint8 x_value, sint8 y_value);
extern sint8 MAT_S8_LIM_S8_S8_S8(sint8 value, sint8 minimum, sint8 maximum);
extern sint16 MAT_S16_LIM_S16_S16_S16(sint16 value, sint16 minimum, sint16 maximum);
extern uint16 MAT_U16_LIM_U16_U16_U16(uint16 value, uint16 minimum, uint16 maximum);
extern sint8 MAT_S8_ADD_S8_S8(sint8 x_value, sint8 y_value);
extern uint8 MAT_U8_ADD_U8_U8(uint8 x_value, uint8 y_value);
extern uint16 MAT_U16_ADD_U16_U16(uint16 x_value, uint16 y_value);
extern sint16 MAT_S16_ADD_S16_S16_S16(sint16 x_value, sint16 y_value, sint16 z_value);
extern sint16 S16_U16(uint16 value);
extern uint8 U8_U16(uint16 value);
extern uint16 U16_S16(sint16 value);
extern sint8 S8_S16(sint16 value);
extern uint16 U16_S32(sint32 value);
extern uint8 U8_S8(sint8 value);
extern uint8 U8_S16(sint16 value);
extern sint8 S8_U8(uint8 value);
extern sint8 S8_U16(uint16 value);
extern sint8 S8_S32(sint32 value);
#endif /* (0) Unused functions */

#if (FCT_CFG_LOHP_COMPONENT)
extern sint16 MAT_S16_ADD_S16_S16(sint16 x_value, sint16 y_value);
#endif /* (FCT_CFG_LOHP_COMPONENT) */

extern sint16 S16_S32(sint32 value);
extern void MAT_HYST( times_t u16_CycleTime, float32 f_NewInput, float32 f_InputHyst_Fak, float32 f_InputHyst_Nomin, float32 f_InputHyst_Denom, float32 f_IntegralTimeErrorLimit, float32 * pf_IntegralError, float32 * pf_HystOutput );

#endif /* (CAL_STD_INCLUDED) */
/** @} end defgroup */
