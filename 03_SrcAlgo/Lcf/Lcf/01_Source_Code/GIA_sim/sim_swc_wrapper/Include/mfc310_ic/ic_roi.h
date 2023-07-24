//* **********************************************************************
//  COMPANY:         $CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
//  
//  PROJECT:         MFC30x_MCU
//  CPU:             MPC5675K
//  
//  PACKAGE:         $Source: ic_roi.h $ $Revision: 1.1 $
//  MKS Date:        $Date: 2021/12/13 17:26:04CET $
//  
//  RHAPSODY:        7.5.3
//  COMPONENT:       IC
//  CONFIGURATION:   DefaultConfig
//  MODEL ELEMENT:   ic_roi
//  MODULNAME:       ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_roi.h
//  LOGIN:           uidt3974  
//  
//  ==========================================================================================
//  The following QAC messages are suppressed for this module:
//  
//  Error handling is emulated by using an exclusive label ERROR_EXIT, which is entered
//  via GOTO on error. Code using this type of error handling is much easier to read,
//  as no nested if() statements are required and checking of error-code/flag on each
//  block can be omitted. Suppress QAC warnings related to this functionality:
//    PRQA S 2001,2015,7003 EOF
//  
//  We intentionally have several data structures on file scope, even when they are used
//  only in one function:
//    PRQA S 3218 EOF
//  
//  A subsequent declaration of 'xxxx' means that it is being used both as a structure/union member
//  and also as a label, tag or ordinary identifier.
//    PRQA S 0781,0783 EOF
//  
//  Magic numbers with 0.0f and 1.0f are OK according to QAC documentation, however the tool
//  has a bug and gives a warning:
//  Hard-coded 'magic' floating constant '0.0f' and
//  Hard-coded 'magic' floating constant '1.0f'
//    PRQA S 3121 EOF
//  
//  Possible dereference of NULL pointer
//    PRQA S 0506 EOF
//  
//  AUTHOR:          $Author: Wang, David (Wangd3) $
//! CREATION DATE:   Wed, 7, Nov 2012  11:37 W. Europe Standard Time AM 
//**************************************************************************** */

#ifndef ic_roi_H
#define ic_roi_H

/*## dependency ic_types */
#include "ic_types.h"
/*## package Ic_Pkg */

/*## class TopLevel::ic_roi */
/*#[ ignore */
//  ==========================================================================================
//  The following QAC messages are suppressed for this module:
//  
//  Error handling is emulated by using an exclusive label ERROR_EXIT, which is entered
//  via GOTO on error. Code using this type of error handling is much easier to read,
//  as no nested if() statements are required and checking of error-code/flag on each
//  block can be omitted. Suppress QAC warnings related to this functionality:
//    PRQA S 2001,2015,7003 EOF
//  
//  We intentionally have several data structures on file scope, even when they are used
//  only in one function:
//    PRQA S 3218 EOF
//  
//  A subsequent declaration of 'xxxx' means that it is being used both as a structure/union member
//  and also as a label, tag or ordinary identifier.
//    PRQA S 0781,0783 EOF
//  
//  Magic numbers with 0.0f and 1.0f are OK according to QAC documentation, however the tool
//  has a bug and gives a warning:
//  Hard-coded 'magic' floating constant '0.0f' and
//  Hard-coded 'magic' floating constant '1.0f'
//    PRQA S 3121 EOF
//  
//  Possible dereference of NULL pointer
//    PRQA S 0506 EOF
/*#]*/


/*#[ ignore */

#ifdef __cplusplus
extern "C"
{
#endif

/*#]*/


//  Stores the ROI calibration results
/*## type ICROI_S_FilterData */
typedef struct ICROI_S_FilterData {
    float32 f32_CalibDeltaPitchFiltered;		/*## attribute f32_CalibDeltaPitchFiltered */
    float32 f32_PitchTotalFiltClamp;		/*## attribute f32_PitchTotalFiltClamp */
    float32 f32_PitchDeltaPreFilter;		/*## attribute f32_PitchDeltaPreFilter */
    float32 f32_FilterDamping;		/*## attribute f32_FilterDamping */
    boolean b_FilterFrozen;		/*## attribute b_FilterFrozen */
} ICROI_S_FilterData;

/*## type ICROI_S_MeasData */
typedef struct ICROI_S_MeasData {
    IC_S_CamParam s_CamParams;		/*## attribute s_CamParams */
    IC_S_Croi as_CroisRight[IC_cui16_NumFrameTypes];		/*## attribute as_CroisRight */
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    IC_S_Croi as_CroisLeft[IC_cui16_NumFrameTypes];
    #endif		/*## attribute as_CroisLeft */
    IC_S_Roi as_ICRois[IC_cui16_NumFrameTypes];		/*## attribute as_ICRois */
    ICROI_S_FilterData s_IcRoiCalib;		/*## attribute s_IcRoiCalib */
} ICROI_S_MeasData;

/***    User explicit entries    ***/


/* Operations */

//*****************************************************************************
//  Functionname:  ICROI_e_Init
//  
//  
//  
//  Parameter:     ICROI_S_MeasData * const ps_MeasDataIn   <In>
//  
//  
//  Parameter:     const IC_S_CamParam * const ps_CamParamIn   <In>
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICROI_e_Init(ICROI_S_MeasData * const,const IC_S_CamParam * const) */
IC_E_ERROR ICROI_e_Init(ICROI_S_MeasData * const ps_MeasDataIn, const IC_S_CamParam * const ps_CamParamIn);

//*****************************************************************************
//  Functionname:  ICROI_e_SetupICRoiLd
//  
//  
//  
//  Parameter:     IC_S_Roi * const ps_IcRoi   <In>
//  
//  
//  Parameter:     const IC_S_LdOnlineCalib * const ps_LdOnlineCalib   <In>
//  
//  
//  Parameter:     const IC_S_VehicleDyn * const ps_VehicleDyn   <In>
//  
//  
//  Parameter:     const IC_E_FRAMETYPE e_FrameType   <In>
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICROI_e_SetupICRoiLd(IC_S_Roi * const,const IC_S_LdOnlineCalib * const,const IC_S_VehicleDyn * const,const IC_E_FRAMETYPE) */
IC_E_ERROR ICROI_e_SetupICRoiLd(IC_S_Roi * const ps_IcRoi, const IC_S_LdOnlineCalib * const ps_LdOnlineCalib, const IC_S_VehicleDyn * const ps_VehicleDyn, const IC_E_FRAMETYPE e_FrameType);

//*****************************************************************************
//  Functionname:  ICROI_e_SetupICRoiHla
//  
//  
//  
//  Parameter:     IC_S_Roi * const ps_IcRoi   <In>
//  
//  
//  Parameter:     const IC_S_HlaOnlineCalib * const ps_HlaOnlineCalib   <In>
//  
//  
//  Parameter:     const IC_E_FRAMETYPE e_FrameType   <In>
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICROI_e_SetupICRoiHla(IC_S_Roi * const,const IC_S_HlaOnlineCalib * const,const IC_E_FRAMETYPE) */
IC_E_ERROR ICROI_e_SetupICRoiHla(IC_S_Roi * const ps_IcRoi, const IC_S_HlaOnlineCalib * const ps_HlaOnlineCalib, const IC_E_FRAMETYPE e_FrameType);

//*****************************************************************************
//  Functionname:  ICROI_v_GetImagerCroi
//  
//  Returns the CROI
//  
//  Parameter:     IC_S_Croi * const ps_Croi   <In>
//  
//  
//  Parameter:     const IC_E_Imager e_ImagerTypeLR   <In>
//  
//  
//  Parameter:     const IC_E_FRAMETYPE e_FrameType   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICROI_v_GetImagerCroi(IC_S_Croi * const,const IC_E_Imager,const IC_E_FRAMETYPE) */
void ICROI_v_GetImagerCroi(IC_S_Croi * const ps_Croi, const IC_E_Imager e_ImagerTypeLR, const IC_E_FRAMETYPE e_FrameType);

//*****************************************************************************
//  Functionname:  ICROI_v_SimInject
//  
//  
//  
//  Parameter:     float32 f32_CalibDeltaPitchFiltered   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICROI_v_SimInject(float32) */
#if (IC_COMPILE_FOR_MTS == 1)
void ICROI_v_SimInject(float32 f32_CalibDeltaPitchFiltered);
#endif


/*#[ ignore */

#ifdef __cplusplus
}
#endif

/*#]*/


#endif
/*********************************************************************
	File Path: ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_roi.h
*********************************************************************/
