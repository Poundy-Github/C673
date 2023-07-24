/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 LCF

  MODULNAME:                 latdmc_wrp.c

  DESCRIPTION:               Wrapper for VW Passat 

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.51 $


  ---*/ /*---
  CHANGES:                   $Log: latdmc_wrp.c  $
  CHANGES:                   Revision 1.51 2020/08/18 21:43:28CEST Feick, Stefan (uidw0691) 
  CHANGES:                   #ifdef	LAT_Gi_Status_dbg
  CHANGES:                   Revision 1.50 2020/08/18 21:36:47CEST Feick, Stefan (uidw0691) 
  CHANGES:                   add dbg signal
  CHANGES:                   Revision 1.49 2020/05/11 15:21:30CEST Feick, Stefan (uidw0691) 
  CHANGES:                   add iuc trq request
  CHANGES:                   Revision 1.48 2020/05/04 18:54:33CEST Feick, Stefan (uidw0691) 
  CHANGES:                   add dbg signal
  CHANGES:                   Revision 1.47 2020/05/04 13:21:51CEST Feick, Stefan (uidw0691) 
  CHANGES:                   add road wheel angle input
  CHANGES:                   RAC/PAC torque as the input
  CHANGES:                   Revision 1.46 2020/03/02 11:14:11CET Feick, Stefan (uidw0691) 
  CHANGES:                   add dbg sig
  CHANGES:                   Revision 1.45 2020/02/27 20:40:08CET Feick, Stefan (uidw0691) 
  CHANGES:                   add dbg
  CHANGES:                   Revision 1.44 2020/01/24 17:08:38CET Feick, Stefan (uidw0691) 
  CHANGES:                   add dbg signals
  CHANGES:                   Revision 1.17.1.23.1.3 2019/08/28 15:11:31CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update files for sprint 10.07
  CHANGES:                   Revision 1.17.1.23.1.2 2019/07/30 10:04:15CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update wrappers after LCF workshop review
  CHANGES:                   Revision 1.17.1.23.1.1 2019/06/07 08:32:41CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update files for Sprint 05.10.01 on LCF variant
  CHANGES:                   Revision 1.17.1.23 2019/04/10 03:43:16CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update LCF files for auxcodegen v4.0
  CHANGES:                   Revision 1.17.1.22 2019/03/12 16:22:36CET Nastasa, Elena (uidt4846) 
  CHANGES:                   Update Source Code for Sprint5
  CHANGES:                   Revision 1.17.1.21 2019/02/13 14:03:01CET Nastasa, Elena (uidt4846) 
  CHANGES:                   Update files for Sprint3
  CHANGES:                   Revision 1.17.1.20 2019/01/31 15:34:15CET Onofrei, Marcel02 (uidk2509) 
  CHANGES:                   Update files for Sprint 02
  CHANGES:                   Revision 1.17.1.19 2019/01/15 15:01:38CET Onofrei, Marcel02 (uidk2509) 
  CHANGES:                   Update files for Sprint 1
  CHANGES:                   Revision 1.17.1.18 2018/12/18 12:08:24CET Onofrei, Marcel02 (uidk2509) 
  CHANGES:                   Checkpoint for Sprint 27 Round 3
  CHANGES:                   Revision 1.17.1.17 2018/12/12 14:02:06CET Onofrei, Marcel02 (uidk2509) 
  CHANGES:                   Check-in for sprint 27, Round1
  CHANGES:                   Revision 1.17.1.16 2018/12/05 11:42:20CET Nastasa, Elena (uidt4846) 
  CHANGES:                   Check-in for Sprint 26, round 4
  CHANGES:                   Revision 1.17.1.15 2018/11/29 15:54:42CET Nastasa, Elena (uidt4846) 
  CHANGES:                   Check-in for Sprint26 INT2
  CHANGES:                   Revision 1.17.1.14 2018/11/23 17:44:05CET Nastasa, Elena (uidt4846) 
  CHANGES:                   Check-in for Sprint26, Round 1
  CHANGES:                   Revision 1.17.1.13 2018/11/23 10:24:39CET Nastasa, Elena (uidt4846) 
  CHANGES:                   Correct Latdmc wrappers
  CHANGES:                   Revision 1.17.1.12 2018/11/12 15:19:57CET Nastasa, Elena (uidt4846) 
  CHANGES:                   Small fix in LATDMC wrapper
  CHANGES:                   Revision 1.17.1.11 2018/11/01 15:54:30CET Nastasa, Elena (uidt4846) 
  CHANGES:                   Check-in for Sprint 24, round 1
  CHANGES:                   Revision 1.17.1.10 2018/10/31 12:44:21CET Stajilov, Victor (uidn1924) 
  CHANGES:                   correct latdmc_wrp.c
  CHANGES:                   Revision 1.17.1.9 2018/10/24 15:23:58CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   Correct latdmc_wrp.c.
  CHANGES:                   Revision 1.17.1.8 2018/10/20 10:28:10CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   Prepare LO19 JT(oct) CP [1]:
  CHANGES:                   	Update common LCF sub_components;
  CHANGES:                   	Update LCF parameters for MFC431. MFC431LO19, MFC431TA19;
  CHANGES:                   	Integrate new sub-component LCOSCT for MFC431LO19;
  CHANGES:                   	Update HMOLCO module of MFC431LO19;
  CHANGES:                   	Update custom sub-components fot TA19;
  CHANGES:                   	Update algo_lib_file_list (add new LO19 Sub-Component).
  CHANGES:                   Revision 1.17.1.7 2018/08/27 16:10:35CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Check-in for Sprint19 Wk2
  CHANGES:                   Revision 1.17.1.6 2018/08/23 09:27:04CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Check-in for Sprint19
  CHANGES:                   Revision 1.17.1.5 2018/08/10 14:46:58CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Check-in for Sprint18
  CHANGES:                   Revision 1.17.1.4 2018/08/10 12:32:01CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Check-in for Sprint18
  CHANGES:                   Revision 1.17.1.3 2018/08/10 09:38:04CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Check-in for Sprint18
  CHANGES:                   Revision 1.17.1.2 2018/08/02 13:53:38CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Check-in for Sprint17
  CHANGES:                   Revision 1.17.1.1 2018/07/23 15:59:09CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Check-in for Sprint16 - Round2
  CHANGES:                   Revision 1.17 2018/06/11 16:30:38CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   check-in for sprint14
  CHANGES:                   Revision 1.16 2018/05/21 13:21:31CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Check-in for Sprint12
  CHANGES:                   Revision 1.15 2018/04/26 11:59:36CEST Grosu, George (uidl9584) 
  CHANGES:                   Update for 8.2
  CHANGES:                   Revision 1.14 2018/04/19 09:38:10CEST Grosu, George (uidl9584) 
  CHANGES:                   8.2 Initial Revision
  CHANGES:                   Revision 1.12 2018/02/09 13:09:44CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   MFC431 R8.0 bugfix3
  CHANGES:                   Revision 1.11 2018/01/26 12:26:47CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Rework of LatDMC wrapper
  CHANGES:                   Revision 1.10 2018/01/15 15:22:15CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   Initial quick merge with latest wrappers from R7.1
  CHANGES:                   Revision 1.9 2017/12/22 10:02:46CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   R8.0 update
  CHANGES:                   Revision 1.7 2017/12/08 17:20:11CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Member moved from latdmc_wrp.c in project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/lcf_veh/wrp/project.pj to latdmc_wrp.c in project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/LATDMC/project.pj.
  CHANGES:                   Revision 1.6 2017/12/07 14:58:12CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Member moved from latdmc_wrp.c in project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/lcf_veh/wrp/project.pj to latdmc_wrp.c in project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/LATDMC/project.pj.
  CHANGES:                   Revision 1.5 2017/11/20 19:03:43CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   LCF MFC431 R7.1
  CHANGES:                   Revision 1.4 2017/11/01 12:08:03CET Grosu, George (uidl9584) 
  CHANGES:                   Compilable version of maual code
  CHANGES:                   Revision 1.22.1.2 2017/09/22 16:07:59CEST Grosu, George (uidl9584) 
  CHANGES:                   Update for new RTE
  CHANGES:                   Revision 1.22.1.1 2017/08/30 10:40:01CEST Grosu, George (uidl9584) 
  CHANGES:                   Bugfix
  CHANGES:                   Revision 1.22 2017/07/14 09:38:57CEST Grosu, George (uidl9584) 
  CHANGES:                   Update for TJA RTE
  CHANGES:                   Revision 1.21 2017/07/13 17:59:45CEST Grosu, George (uidl9584) 
  CHANGES:                   Update for TJA RTE
  CHANGES:                   Revision 1.20 2017/07/06 11:43:28CEST Grosu, George (uidl9584) 
  CHANGES:                   Fix QAC errors
  CHANGES:                   Revision 1.19 2017/07/05 14:11:14CEST Grosu, George (uidl9584) 
  CHANGES:                   Update for INT-6
  CHANGES:                   Revision 1.18 2017/06/30 16:07:32CEST Grosu, George (uidl9584) 
  CHANGES:                   Update components
  CHANGES:                   Revision 1.17 2017/06/19 09:54:41CEST Grosu, George (uidl9584) 
  CHANGES:                   TJA2
  CHANGES:                   Revision 1.10 2017/05/22 07:48:57CEST Feick, Stefan (uidw0691) 
  CHANGES:                   lane status changed
  CHANGES:                   Revision 1.9 2017/05/11 19:20:32CEST Feick, Stefan (uidw0691) 
  CHANGES:                   add yaw rate offset
  CHANGES:                   Revision 1.8 2017/05/11 18:33:26CEST Feick, Stefan (uidw0691) 
  CHANGES:                   no acivation in case of TJA State = 5
  CHANGES:                   Revision 1.7 2017/05/03 19:56:28CEST Feick, Stefan (uidw0691) 
  CHANGES:                   add cam signals
  CHANGES:                   Revision 1.6 2017/05/02 10:20:11CEST Feick, Stefan (uidw0691) 
  CHANGES:                   add dbg data
  CHANGES:                   Revision 1.5 2017/05/01 22:24:59CEST Feick, Stefan (uidw0691) 
  CHANGES:                   higher resolution for heading err signal
  CHANGES:                   Revision 1.4 2017/04/28 20:32:40CEST Feick, Stefan (uidw0691) 
  CHANGES:                   update R3.0
  CHANGES:                   Revision 1.3 2017/04/28 17:22:05CEST Feick, Stefan (uidw0691) 
  CHANGES:                   R3.0
  CHANGES:                   Revision 1.7 2017/02/01 12:24:52CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   creation or R2.1 LCF functionality
  CHANGES:                   Revision 1.6 2017/01/18 08:14:38CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   Function and performance improvements during 2.0 demo in Korea
  CHANGES:                   Revision 1.5 2017/01/10 19:44:32CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   fix issue with torque output without TOI activation
  CHANGES:                   Revision 1.4 2016/11/03 11:59:04CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   Update for R2.0
  CHANGES:                   Revision 1.3 2016/09/08 08:55:37CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Update LCF for R1.0 release
  CHANGES:                   Revision 1.2 2016/08/29 11:02:28CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Wrapper bugfixes during LKA demo
  CHANGES:                   Revision 1.1 2016/08/03 20:38:58CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Wrappers updated for new LaDMC algo code
  CHANGES:                   Revision 1.0 2016/07/01 06:45:37CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/algo/00_Custom/lcfveh_wrp/project.pj

**************************************************************************** */

/*****************************************************************************
QAC AND MISRA RULES SUPPRESSION
*****************************************************************************/
//PRQA S 4395,4119 ++/ 
/*Surpress QAC Messages (entire file): A composite expression of 'essentially floating' type (float) is being cast to a different type category, 'signed'.
										Result of floating point operation cast to an integral type.
Float type is used in the calculations to reduce truncation error, the result is assign to an integer-type variable
This is intentionally with the acceptance of truncation error.*/

//PRQA S 3120,3121 ++/ 
/*Surpress QAC Messages (entire file): Hard-coded 'magic' integer constant, Hard-coded 'magic' floating constant.
Intentional use of magic numbers*/

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "latdmc_wrp.h"

/*****************************************************************************
  MODULGLOBALE KONSTANTEN
*****************************************************************************/

/*****************************************************************************
  MACROS
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS
*****************************************************************************/

/*****************************************************************************
  STRUCTURES AND TYPEDEFS
*****************************************************************************/

/*****************************************************************************
  VARIABLES
*****************************************************************************/

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
static void CopyDMCInput(void);
static void CopyDMCOutput(void);

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/

/* ****************************************************************************

  Functionname:     LATDMC_VehProcess                                            */ /*!

  @brief            Template Main processing

  @description      Calls all processing functions of latdmc and sub-components

  @param[in]        reqPorts : pointer on the required ports structure
  @param[in,out]    proPorts : pointer on the provided ports structure

  @return           -

  @pre              All states must be set
  @post             -

  @todo             review for unused code

  @author           

**************************************************************************** */
void LATDMC_VehProcess()
{
    /* Input to Lateral DMC preparation */
	CopyDMCInput(); /* ReqPorts: Environment signals */
	
	/* Lateral DMC task call */
	DMC_Soc_step();

	/* Output of Lateral DMC preparation */
    CopyDMCOutput();               /* proPorts: output storage structure */
}

/* ****************************************************************************

  Functionname:     LATDMC_VehReset                                         */ /*!

  @brief            Reset of the component

  @description      Initialization of all internal data storage.
                    Shall be called once before processing starts

  @param[in]        reqPorts : pointer on the required ports structure
  @param[in,out]    proPorts : pointer on the provided ports structure

  @return           -

  @pre              -
  @post             All internal values and all interfaces are initialized
                    to default values

  @author           Thomas Berndt, Jochen Spruck

**************************************************************************** */
void LATDMC_VehReset()
{
uint8 i;
	/*! Initialize MeasFreeze */

	/*! Reset algo data to initial values */
    DMC_Soc_initialize();
	
// Initialize the LATDMC signals with default values to cover the case when LCF_NVM in NOT activate.
	//Default values for learning kappa2angle algorithm:
#if defined(LCF_NVM_USED) && (LCF_NVM_USED == 1)
	for (i = 0; i < MIN_NO_OF_ELEM(pNvmLcfInfo->AdpCorrFactorPos_nu, DMC_ADP_CORR_FACTOR_POS_LOOP0); i++)
	{
		DMC_ADP_CORR_FACTOR_POS_LOOP0[i] =  1; 
		DMC_ADP_CORR_COUNTER_POS_LOOP0[i] = 0;   
		DMC_ADP_CORR_FACTOR_NEG_LOOP0[i] =  1; 
		DMC_ADP_CORR_COUNTER_NEG_LOOP0[i] = 0; 
	}
	DMC_ADP_CORR_FACTOR_READ_ERROR = 1;
	
	//Default values for steering angle offset learning:
	DMC_ANGLE_OFF_LOOP0 = 0;
	DMC_ANGLE_OFF_CALIB_CNT_LOOP0 = 0;
	DMC_ANGLE_OFF_READ_ERROR = 1;
#endif

	/* L3D_ALGO_26005: copy from internal data nvmLcfInfo into LADMC input signals expecting NVM data */
#if defined(LCF_NVM_USED) && (LCF_NVM_USED == 1)
	for (i = 0; i < MIN_NO_OF_ELEM(pNvmLcfInfo->AdpCorrFactorPos_nu, DMC_ADP_CORR_FACTOR_POS_LOOP0); i++)
	{
        DMC_ADP_CORR_FACTOR_POS_LOOP0[i] =  pNvmLcfInfo->AdpCorrFactorPos_nu[i]; 
        DMC_ADP_CORR_COUNTER_POS_LOOP0[i] = pNvmLcfInfo->AdpCorrCounterPos_nu[i];   
        DMC_ADP_CORR_FACTOR_NEG_LOOP0[i] =  pNvmLcfInfo->AdpCorrFactorNeg_nu[i]; 
        DMC_ADP_CORR_COUNTER_NEG_LOOP0[i] = pNvmLcfInfo->AdpCorrCounterNeg_nu[i]; 
	}
    DMC_ANGLE_OFF_LOOP0 = pNvmLcfInfo->AngleOff_nu;
    DMC_ANGLE_OFF_CALIB_CNT_LOOP0 = pNvmLcfInfo->AngleOffCalibCnt_nu;
    /* Check if there was a NVM read error */
    if (pFRAME_VehDbgData->uiNvmDataValid == 0u)
    {
        DMC_ADP_CORR_FACTOR_READ_ERROR = 1; //TODO: check name and  data type
        DMC_ANGLE_OFF_READ_ERROR = 1;
    }
    else
    {
        DMC_ADP_CORR_FACTOR_READ_ERROR = 0;
        DMC_ANGLE_OFF_READ_ERROR = 0;
    }  
#endif   
}

/* ***********************************************************************
  @fn               CopyDMCInput */ /*!

  @brief            fill LaDMC inputs with data from environment signals and TrajCtrl outputs 

  @description      

  @param[in]        void
  @return           void

  @pre              -
  @post             -
  **************************************************************************** */
static void CopyDMCInput(void)
{

	signed_int32_t tmp32;

	/* CopyDMCInput function kept because inputs if LaDMC must be filled only after TrjCtrl was executed */
	
	/* RO 720630 */
	/* Lateral DMC activation mode */
	/*Surpress QAC Messages (next line): An expression of 'essentially Boolean' type (_Bool) is being cast to signed type 'signed short'.
	Intentional explicit cast as assignment of a essentially boolean to signed short variable*/
	//PRQA S 4303 1/
	SSI_R_DMC_LAT_ACTVN_MOD	=	(signed_int16_t) S_SSI_R_DMC_LAT_ACTVN_MOD;
	if (GET_S_TPLCEN_ReplanCurValues_nu() != 0u)
	{
		/* Set bit 1 in SSI_R_DMC_LAT_ACTVN_MOD */
		/*Surpress QAC Messages (next line): A composite expression of 'essentially unsigned' type (unsigned short) is being cast to a different type category, 'signed'.
		Intentional explicit cast due to type of SSI_R_DMC_LAT_ACTVN_MOD which is signed short*/
		//PRQA S 4394 1/
		SSI_R_DMC_LAT_ACTVN_MOD = (signed_int16_t) (((uint16) SSI_R_DMC_LAT_ACTVN_MOD) | 0x0002U); 
	}
	else
	{
	}


	if( (GET_S_LCFRCV_LatCtrlModeTJA_nu() == (uint8)E_TJASTM_LATCTRLMD_LC) || (GET_S_LCFRCV_LatCtrlModeTJA_nu() == (uint8)E_TJASTM_LATCTRLMD_CMB))
	{
		SSI_R_DMC_LAT_ACTVN_MOD = (signed_int16_t) (((uint16) SSI_R_DMC_LAT_ACTVN_MOD) | 0x0100U);
	}
	else 	
	{
		if( (GET_S_LCFRCV_LatCtrlModeTJA_nu() == (uint8)E_TJASTM_LATCTRLMD_OF))
		{
			SSI_R_DMC_LAT_ACTVN_MOD = (signed_int16_t) (((uint16) SSI_R_DMC_LAT_ACTVN_MOD) | 0x0200U); 
		}
		else
		{
		}
	}
	
	
	

	
	DMC_ANGLE_FADING_REQ	=	(unsigned_char_t) S_DMC_ANGLE_FADING_REQ;

	DMC_RAMPING_DOWN_REQ	=	(unsigned_char_t) S_DMC_RAMPING_DOWN_REQ;
	
	/* end RO 720630 */
		
    /* Total curvature command (feed forward + KMC)  */
	SSI_R_DMC_CRVT_SUM_CMD	=	(signed_int16_t) S_SSI_R_DMC_CRVT_SUM_CMD;

	/* Curvature command feed forward from trajectory planner witout KMC */
	SSI_R_DMC_CRVT_FEED_FWD	=	(signed_int16_t) S_SSI_R_DMC_CRVT_FEED_FWD; /* according to LaKMC_CrvCmd_FF__1pm */
							 
	/* Curvature command rate feed forward from trajectory planner witout KMC */
	SSI_R_DMC_CRVT_CHG_RATE	=	(signed_int16_t) S_SSI_R_DMC_CRVT_CHG_RATE;

    /* Curvature command from KMC without feed forward from trajectory planner */
	SSI_R_DMC_CRVT_STEER_ACTR	=	(signed_int16_t) S_SSI_R_DMC_CRVT_STEER_ACTR;

	/* Steer angle command from KMC without feed forward from trajectory planner */
	SSI_R_DMC_STEER_AG_REQ	=	(signed_int16_t) S_SSI_R_DMC_STEER_AG_REQ;

    /* Curvature commad rate from KMC without feed forward from trajectory planner */
	SSI_R_DMC_CRVT_CMD_RATE	=	S_SSI_R_DMC_CRVT_CMD_RATE;

	/* Pure curvature command from the camera regarding the middle of the lane without modification by the trajectory planner, without preview, without latency compensation */
	/*Surpress QAC Messages (next line): Line length exceeds 200 characters.
	The lines exceeds 200 characters because of comment*/
	//PRQA S 2217 1/	
	DMC_CAM_CRVT_FEED_FWD	=	(signed_int16_t) S_DMC_CAM_CRVT_FEED_FWD;

    /* Qualifier of the pure curvature command from the camera */
	/*Surpress QAC Messages (next line): An expression of 'essentially Boolean' type (_Bool) is being cast to signed type 'signed short'.
	Intentional explicit cast as assignment of a essentially boolean to signed short variable*/
	/*Surpress QAC Messages (next line): Line length exceeds 200 characters.
	The lines exceeds 200 characters because of comment*/	
	//PRQA S 4303,2217 1/
	DMC_CAM_CRVT_FEED_FWD_QF	=	(signed_int16_t) S_DMC_CAM_CRVT_FEED_FWD_QF;

    /* Lateral error with respect to the middle of the lane as seen by the camera without modification by the trajectory planner, without preview, without latency compensation */
	DMC_CAM_LAT_ERR	=	(signed_int16_t) S_DMC_CAM_LAT_ERR;

	/* Qualifier of the lateral error with respect to the middle of the lane as seen by the camera */
	/*Surpress QAC Messages (next line): An expression of 'essentially Boolean' type (_Bool) is being cast to signed type 'signed short'.
	Intentional explicit cast as assignment of a essentially boolean to signed short variable for better execution time*/
	//PRQA S 4303 1/
	DMC_CAM_LAT_ERR_QF	=	(signed_int16_t) S_DMC_CAM_LAT_ERR_QF;

	/* Heading error with respect to the middle of the lane as seen by the camera without modification by the trajectory planner, without preview, without latency compensation */
	/*Surpress QAC Messages (next line): Line length exceeds 200 characters.
	The lines exceeds 200 characters because of comment*/
	//PRQA S 2217 1/	
	tmp32 = (signed_int32_t) S_DMC_CAM_HDNG_AG_ERR;	//using the high resolution will lead to overflows for inputs outside -1..1rad

	if (tmp32 > 32767)
	{
    		DMC_CAM_HDNG_AG_ERR = (signed_int16_t) (32767);
	}
	else if (tmp32 < -32767)
	{
    		DMC_CAM_HDNG_AG_ERR = (signed_int16_t) (-32767);
	}
	else
	{
    		DMC_CAM_HDNG_AG_ERR = (signed_int16_t) tmp32;
	}


	/* Qualifier of the heading error with respect to the middle of the lane as seen by the camera */
	/*Surpress QAC Messages (next line): An expression of 'essentially Boolean' type (_Bool) is being cast to signed type 'signed short'.
	Intentional explicit cast as assignment of a essentially boolean to signed short variable*/
	/*Surpress QAC Messages (next line): Line length exceeds 200 characters.
	The lines exceeds 200 characters because of comment*/	
	//PRQA S 4303,2217 1/
	DMC_CAM_HDNG_AG_ERR_QF	=	S_DMC_CAM_HDNG_AG_ERR_QF;

	/* Lateral error with respect to the middle of the lane as it is used by the kinematic controller */
	SSI_R_DMC_LAT_ERR	=	(signed_int16_t) S_SSI_R_DMC_LAT_ERR;

	/* Heading error with respect to the middle of the lane as it is used by the kinematic controller */
    tmp32 = (signed_int32_t) S_SSI_R_DMC_HDNG_AG_ERR;
	if (tmp32 > 32767)
	{
    		SSI_R_DMC_HDNG_AG_ERR = (signed_int16_t) (32767);
	}
	else if (tmp32 < -32767)
	{
    		SSI_R_DMC_HDNG_AG_ERR = (signed_int16_t) (-32767);
	}
	else
	{
    		SSI_R_DMC_HDNG_AG_ERR = (signed_int16_t) tmp32;
	}
	
	/* Stiffness request */
	SSI_R_DMC_STFN_REQ	=	S_SSI_R_DMC_STFN_REQ; /* signal not used anymore, only kept for compatibility reason */
	
    /* Accuracy request */
	SSI_R_DMC_OCCRCY_REQ	=	S_SSI_R_DMC_OCCRCY_REQ; /* signal not used anymore, only kept for compatibility reason */
	
	/* Steering wheel vibration  */
	SSI_R_DMC_STEER_WHL_VIBR	=	S_SSI_R_DMC_STEER_WHL_VIBR;
	
    /* Lane status information with prediction of oncoming LDP or RDP event */
	SSI_R_LANE_STATUS	=	(signed_int16_t) S_SSI_R_LANE_STATUS;

	/* Vehicle velocity */
	EST_REFERENCE_VELOCITY	=	(signed_int16_t) S_EST_REFERENCE_VELOCITY;
	
    /* Steering wheel torque */
	BUS_EPS_TOR_BAR_TORQUE	=	(signed_int16_t) S_BUS_EPS_TOR_BAR_TORQUE;

	/* Steering wheel torque (BUS_EPS_TOR_BAR_TORQUE) qualifier, 0: signal is valid, 1: signal is invalid */
	/*Surpress QAC Messages (next line): An expression of 'essentially Boolean' type (_Bool) is being cast to unsigned type 'unsigned char'.
	Intentional explicit cast as assignment of a essentially boolean to unsigned char variable*/
	//PRQA S 4304 1/
	BUS_EPS_TOR_BAR_TORQUE_QF	=	(boolean) S_BUS_EPS_TOR_BAR_TORQUE_QF;

    /* Current load at the tie road */
	BUS_EPS_ASSIST_TRQ	=	(signed_int16_t) S_BUS_EPS_ASSIST_TRQ;

	/* Finally arbitrated motor torque command */
	BUS_EPS_MOTOR_TRQ	=	(signed_int16_t) S_BUS_EPS_MOTOR_TRQ;

    /* EPS bus status, this singal is not used in DMC, just set it to 0 */
	BUS_EPS_STATUS	=	S_BUS_EPS_STATUS;

	/* IuC torque request */
	LAT_Eps_Torque_Request_nm	=	S_LAT_Eps_Torque_Request_nm;

    /* IuC DMC status */
	LAT_Dmc_Status_nu	=	(unsigned_char_t) S_LAT_Dmc_Status_nu;

	/* Torque overlay interface is faulty */
	/*Surpress QAC Messages (next line): An expression of 'essentially Boolean' type (_Bool) is being cast to unsigned type 'unsigned char'.
	Intentional explicit cast as assignment of a essentially boolean to unsigned char variable*/
	//PRQA S 4304 1/
	HALFTorqueOverlayFault	=	(boolean) S_HALFTorqueOverlayFault;
	
	/* Torque overlay interface is activated (CF_Mdps_ToiActive) */
	/*Surpress QAC Messages (next line): An expression of 'essentially Boolean' type (_Bool) is being cast to unsigned type 'unsigned char'.
	Intentional explicit cast as assignment of a essentially boolean to unsigned char variable*/
	//PRQA S 4304 1/
	HALF_TORQUE_OVERLAY_ACTIVATED	=	(boolean) S_HALF_TORQUE_OVERLAY_ACTIVATED;

	/* EPS steer angle authority */
	EpsSteerAngleAuthority	=	S_EpsSteerAngleAuthority;

	/* EPS temperature deactivation */
	EPS_TEMP_DEACTIVATION_LDW	=	S_EPS_TEMP_DEACTIVATION_LDW;

	/* ESC active  (ESC_ActiveState) */
	/*Surpress QAC Messages (next line): An expression of 'essentially Boolean' type (_Bool) is being cast to unsigned type 'unsigned char'.
	Intentional explicit cast as assignment of a essentially boolean to unsigned char variable*/
	//PRQA S 4304 1/
	AYC_IN_CYCLE	=	(boolean) S_AYC_IN_CYCLE;

	/* ESC is finally disabled (ESC_SystemState) */
	/*Surpress QAC Messages (next line): An expression of 'essentially Boolean' type (_Bool) is being cast to unsigned type 'unsigned char'.
	Intentional explicit cast as assignment of a essentially boolean to unsigned char variable*/
	//PRQA S 4304 1/
	FINAL_FUNCTION_DISABLE_AYC	=	(boolean) S_FINAL_FUNCTION_DISABLE_AYC;

    /* ESC is temporary disabled (ESC_SystemState) */
	/*Surpress QAC Messages (next line): An expression of 'essentially Boolean' type (_Bool) is being cast to unsigned type 'unsigned char'.
	Intentional explicit cast as assignment of a essentially boolean to unsigned char variable*/
	//PRQA S 4304 1/
	FUNCTION_DISABLE_AYC	=	(boolean) S_FUNCTION_DISABLE_AYC;

    /* ESC warning lamp is active */
	/*Surpress QAC Messages (next line): An expression of 'essentially Boolean' type (_Bool) is being cast to unsigned type 'unsigned char'.
	Intentional explicit cast as assignment of a essentially boolean to unsigned char variable*/
	//PRQA S 4304 1/
	AYC_WARNING_LAMP	=	(boolean) S_AYC_WARNING_LAMP;

    /* Vehicle yaw rate */ 
	DMC_FILTERED_YAW_RATE	=	(signed_int16_t) S_DMC_FILTERED_YAW_RATE;

    /* Vehicle yaw rate qualifier */ 
	/*Surpress QAC Messages (next line): An expression of 'essentially Boolean' type (_Bool) is being cast to signed type 'signed short'.
	Intentional explicit cast as assignment of a essentially boolean to signed short variable*/
	//PRQA S 4303 1/
	DMC_FILTERED_YAW_RATE_QF	=	(signed_int16_t) S_DMC_FILTERED_YAW_RATE_QF;

    /* Vehicle lateral acceleration */
	DMC_FILTERED_LATERAL_ACC_COG	=	(signed_char_t) S_DMC_FILTERED_LATERAL_ACC_COG;

    /* Vehicle lateral acceleration qualifier */
	/*Surpress QAC Messages (next line): An expression of 'essentially Boolean' type (_Bool) is being cast to signed type 'signed short'.
	Intentional explicit cast as assignment of a essentially boolean to signed short variable*/
	//PRQA S 4303 1/
	DMC_FILTERED_LATERAL_ACC_COG_QF	=	(signed_int16_t) S_DMC_FILTERED_LATERAL_ACC_COG_QF;
	
    /* EPS steering angle */
	SSI_R_EPS_STEER_AG	=	(signed_int16_t) S_SSI_R_EPS_STEER_AG;

    /* Road wheel angle */
	DMC_ROAD_WHEEL_ANGLE	=	(signed_int16_t) S_DMC_ROAD_WHEEL_ANGLE;

    /* EPS steering angle qualifier */
	/*Surpress QAC Messages (next line): An expression of 'essentially Boolean' type (_Bool) is being cast to signed type 'signed short'.
	Intentional explicit cast as assignment of a essentially boolean to signed short variable*/
	//PRQA S 4303 1/
	DMC_FILTERED_STEER_ANGLE_QF	=	(signed_int16_t) S_DMC_FILTERED_STEER_ANGLE_QF;

    /* EPS steering angle rate */
	SSI_R_EPS_STEER_AG_RATE	=	(signed_int16_t) S_SSI_R_EPS_STEER_AG_RATE;

    /* EPS steering angle rate qualifier */
	/*Surpress QAC Messages (next line): An expression of 'essentially Boolean' type (_Bool) is being cast to signed type 'signed short'.
	Intentional explicit cast as assignment of a essentially boolean to signed short variable*/
	//PRQA S 4303 1/
	DMC_FILTERED_STEER_ANGLE_RATE_QF	=	(signed_int16_t) S_DMC_FILTERED_STEER_ANGLE_RATE_QF;

	/* Steering angle offset from VDY */
	DMC_STEER_ANGLE_OFFSET	=	(signed_int16_t) S_DMC_STEER_ANGLE_OFFSET;

    /* Steering angle offset state from VDY; actual range of signal from VDY is 0..6 */
	DMC_STEER_ANGLE_OFFSET_STATE	=	(signed_int16_t) S_DMC_STEER_ANGLE_OFFSET_STATE;

    /* Yaw rate offset from VDY */
	DMC_YAW_RATE_OFFSET	=	(signed_int16_t) S_DMC_YAW_RATE_OFFSET;

    /* Yaw rate offset state from VDY */
	DMC_YAW_RATE_OFFSET_STATE	=	(signed_int16_t) S_DMC_YAW_RATE_OFFSET_STATE;
	
	/* Forced shutting off of the DMC by the mode controller */
	DMC_FORCE_SHUT_OFF_REQUEST	=	S_DMC_FORCE_SHUT_OFF_REQUEST;

	/* RO 720630 */
	/* Stiffness parameter */
	DMC_STIFFNESS_LIMIT	=	(unsigned_char_t)	S_DMC_STIFFNESS_LIMIT;	/* CTRSC signal is float32 */
	DMC_STIFFNESS_GRAD	=	(signed_int16_t)	S_DMC_STIFFNESS_GRAD;	/* CTRSC signal is float32 */

	/* Torque scale parameter */
	DMC_TORQUE_SCALE_LIMIT	=	(unsigned_char_t)	S_DMC_TORQUE_SCALE_LIMIT;	/* CTRSC signal is float32 */
	DMC_TORQUE_SCALE_GRAD	=	(signed_int16_t)	S_DMC_TORQUE_SCALE_GRAD;	/* CTRSC signal is float32 */

	/* Torque ramp gradient */
	DMC_TORQUE_RAMP_GRAD	=	(signed_int16_t) S_DMC_TORQUE_RAMP_GRAD; /* CTRSC signal is float32 */
	
	/* DMC accuracy */  
	DMC_HIGH_ACCURACY_REQUEST	=	S_DMC_HIGH_ACCURACY_REQUEST;
	/* end RO 720630 */
	
	/* DMC angle command limitation */ 
	DMC_ANGLE_REQ_MAX_LIMIT_SCALE	= S_DMC_ANGLE_REQ_MAX_LIMIT_SCALE;

	/* DMC angle gradient limitation */
	DMC_ANGLE_REQ_MAX_GRAD_SCALE	= S_DMC_ANGLE_REQ_MAX_GRAD_SCALE;

	/* Driver torque derating request */
	DMC_DERATING_LEVEL_REQ		= S_DMC_DERATING_LEVEL_REQ;

	/* Steering wheel angle sensor value */
	UNCALIBRATED_SWA_FIL 		= (signed_int16_t) S_UNCALIBRATED_SWA_FIL;
	
	/* Requested driving mode by driver */
	DMC_DRIVING_MODE = (unsigned_char_t) S_DMC_DRIVING_MODE;
	
	/* Bank angle */
	DMC_BANK_ANGLE = (signed_int16_t) S_DMC_BANK_ANGLE;

	/* Pitch angle */
	EMO_PITCH_ANGLE = (signed_int16_t) S_EMO_PITCH_ANGLE;

	/* Straight forward condition */
	DMC_GPIO = (signed_int16_t) ((unsigned_char_t)S_STRAIGHT_FORWARD); //MaOn
	DMC_GPIO2 = (signed_int16_t)(S_DMC_SIDE_OBJECT_STATUS);
	DMC_GPIO3 = (signed_int16_t)((unsigned_char_t)S_DMC_ROAD_CONDITION);
	DMC_GPIO4 = (signed_int16_t)(4);

	/* Shut off request in case of error */
	DMC_SHUT_OFF_ON_ERROR = (unsigned_char_t) S_DMC_SHUT_OFF_ON_ERROR;
}

/* ***********************************************************************
  @fn               CopyDMCOutput */ /*!

  @brief            copy LaDMC output data into the provided ports

  @description      

  @param[out]       proPorts provided ports
  @return           void

  @pre              -
  @post             -
  **************************************************************************** */
static void CopyDMCOutput(void)
{
    /* proPorts filled in CopyLcfVehOutput now */

	/* Fill debug data to be meas freezed */
	pLaDMC_DbgData->BUS_EPS_ASSIST_TRQ = BUS_EPS_ASSIST_TRQ;
	pLaDMC_DbgData->BUS_EPS_MOTOR_TRQ = BUS_EPS_MOTOR_TRQ;
	pLaDMC_DbgData->EpsSteerAngleAuthority = EpsSteerAngleAuthority;
	pLaDMC_DbgData->HALFTorqueOverlayFault = HALFTorqueOverlayFault;
	pLaDMC_DbgData->EPS_TEMP_DEACTIVATION_LDW = EPS_TEMP_DEACTIVATION_LDW;
	pLaDMC_DbgData->HALF_TORQUE_OVERLAY_ACTIVATED = HALF_TORQUE_OVERLAY_ACTIVATED;
	pLaDMC_DbgData->SSI_R_DMC_LAT_ACTVN_MOD = SSI_R_DMC_LAT_ACTVN_MOD;
	pLaDMC_DbgData->SSI_R_DMC_CRVT_SUM_CMD = SSI_R_DMC_CRVT_SUM_CMD;
	pLaDMC_DbgData->SSI_R_DMC_CRVT_FEED_FWD = SSI_R_DMC_CRVT_FEED_FWD;
	pLaDMC_DbgData->SSI_R_DMC_CRVT_CHG_RATE = SSI_R_DMC_CRVT_CHG_RATE;
	pLaDMC_DbgData->SSI_R_DMC_CRVT_STEER_ACTR = SSI_R_DMC_CRVT_STEER_ACTR;
	pLaDMC_DbgData->SSI_R_DMC_CRVT_CMD_RATE = SSI_R_DMC_CRVT_CMD_RATE;
	pLaDMC_DbgData->DMC_CAM_CRVT_FEED_FWD = DMC_CAM_CRVT_FEED_FWD;
	pLaDMC_DbgData->DMC_CAM_CRVT_FEED_FWD_QF = DMC_CAM_CRVT_FEED_FWD_QF;
	pLaDMC_DbgData->DMC_CAM_LAT_ERR = DMC_CAM_LAT_ERR;
	pLaDMC_DbgData->DMC_CAM_LAT_ERR_QF = DMC_CAM_LAT_ERR_QF;
	pLaDMC_DbgData->DMC_CAM_HDNG_AG_ERR = DMC_CAM_HDNG_AG_ERR;
	pLaDMC_DbgData->DMC_CAM_HDNG_AG_ERR_QF = DMC_CAM_HDNG_AG_ERR_QF;
	pLaDMC_DbgData->SSI_R_DMC_LAT_ERR = SSI_R_DMC_LAT_ERR;
	pLaDMC_DbgData->SSI_R_DMC_HDNG_AG_ERR = SSI_R_DMC_HDNG_AG_ERR;
	pLaDMC_DbgData->SSI_R_DMC_STFN_REQ = SSI_R_DMC_STFN_REQ;
	pLaDMC_DbgData->SSI_R_DMC_OCCRCY_REQ = SSI_R_DMC_OCCRCY_REQ;
	pLaDMC_DbgData->SSI_R_EPS_STEER_AG = SSI_R_EPS_STEER_AG;
	pLaDMC_DbgData->SSI_R_EPS_STEER_AG_RATE = SSI_R_EPS_STEER_AG_RATE;
	pLaDMC_DbgData->SSI_R_DMC_STEER_WHL_VIBR = SSI_R_DMC_STEER_WHL_VIBR;
	pLaDMC_DbgData->SSI_R_LANE_STATUS = SSI_R_LANE_STATUS;
	pLaDMC_DbgData->EST_REFERENCE_VELOCITY = EST_REFERENCE_VELOCITY;
	pLaDMC_DbgData->BUS_EPS_TOR_BAR_TORQUE = BUS_EPS_TOR_BAR_TORQUE;
	pLaDMC_DbgData->BUS_EPS_STATUS = BUS_EPS_STATUS;
	pLaDMC_DbgData->BUS_EPS_TOR_BAR_TORQUE_QF = BUS_EPS_TOR_BAR_TORQUE_QF;
	pLaDMC_DbgData->AYC_IN_CYCLE = AYC_IN_CYCLE;
	pLaDMC_DbgData->FINAL_FUNCTION_DISABLE_AYC = FINAL_FUNCTION_DISABLE_AYC;
	pLaDMC_DbgData->DMC_FORCE_SHUT_OFF_REQUEST = DMC_FORCE_SHUT_OFF_REQUEST;
	pLaDMC_DbgData->FUNCTION_DISABLE_AYC = FUNCTION_DISABLE_AYC;
	pLaDMC_DbgData->AYC_WARNING_LAMP = AYC_WARNING_LAMP;
	pLaDMC_DbgData->DMC_FILTERED_YAW_RATE = DMC_FILTERED_YAW_RATE;
	pLaDMC_DbgData->DMC_FILTERED_YAW_RATE_QF = DMC_FILTERED_YAW_RATE_QF;
	pLaDMC_DbgData->DMC_FILTERED_LATERAL_ACC_COG = DMC_FILTERED_LATERAL_ACC_COG;
	pLaDMC_DbgData->DMC_FILTERED_LATERAL_ACC_COG_QF = DMC_FILTERED_LATERAL_ACC_COG_QF;
	pLaDMC_DbgData->DMC_FILTERED_STEER_ANGLE_QF = DMC_FILTERED_STEER_ANGLE_QF;
	pLaDMC_DbgData->DMC_FILTERED_STEER_ANGLE_RATE_QF = DMC_FILTERED_STEER_ANGLE_RATE_QF;
	pLaDMC_DbgData->DMC_STEER_ANGLE_OFFSET = DMC_STEER_ANGLE_OFFSET;
	pLaDMC_DbgData->DMC_STEER_ANGLE_OFFSET_STATE = DMC_STEER_ANGLE_OFFSET_STATE;
	pLaDMC_DbgData->DMC_YAW_RATE_OFFSET = DMC_YAW_RATE_OFFSET;
	pLaDMC_DbgData->DMC_YAW_RATE_OFFSET_STATE = DMC_YAW_RATE_OFFSET_STATE;
	pLaDMC_DbgData->DMC_EPS_TRQ_REQ = DMC_EPS_TRQ_REQ;
	pLaDMC_DbgData->LaDMC_status = LaDMC_status;
	pLaDMC_DbgData->LADMC_EPS_TORQUE_REQUEST = LADMC_EPS_TORQUE_REQUEST;
	pLaDMC_DbgData->LaDMC_Eps_Request_Flag = LaDMC_Eps_Request_Flag;
	pLaDMC_DbgData->LADMC_EPS_INTERFACE_ACTIVE_REQ = LADMC_EPS_INTERFACE_ACTIVE_REQ;
	pLaDMC_DbgData->DMC_LAT_EPS_DAMP_LVL_REQ = DMC_LAT_EPS_DAMP_LVL_REQ;
	pLaDMC_DbgData->DMC_LAT_STATUS = DMC_LAT_STATUS;
	pLaDMC_DbgData->MTO_HALF_SYSTEM_STS = MTO_HALF_SYSTEM_STS;
	pLaDMC_DbgData->LADMC_STEER_ANGLE_RATE_REQ = LADMC_STEER_ANGLE_RATE_REQ;
	pLaDMC_DbgData->LADMC_STIFFNESS_LEVEL_REQUEST = LADMC_STIFFNESS_LEVEL_REQUEST;
	pLaDMC_DbgData->DMC_LONG_ENG_TRQ_REQ = DMC_LONG_ENG_TRQ_REQ;
	pLaDMC_DbgData->DMC_LONG_BRK_TRQ_REQ = DMC_LONG_BRK_TRQ_REQ;
	pLaDMC_DbgData->SaRateSig = SaRateSig;
	pLaDMC_DbgData->SaRateQ = SaRateQ;
	pLaDMC_DbgData->DYC_Steer_Angle_Feedforward = DYC_Steer_Angle_Feedforward;
	pLaDMC_DbgData->LAT_Eps_Torque_Request = LAT_Eps_Torque_Request;
	pLaDMC_DbgData->SAC_Requested_Damping_Level = SAC_Requested_Damping_Level;
	pLaDMC_DbgData->VEH_Delta_F_Dot_Est_Arb = VEH_Delta_F_Dot_Est_Arb;
	pLaDMC_DbgData->LAT_Delta_Ys = LAT_Delta_Ys;
	pLaDMC_DbgData->LKC_Delta_Ys = LKC_Delta_Ys;
	pLaDMC_DbgData->LAT_Delta_Psi = LAT_Delta_Psi;
	pLaDMC_DbgData->LKC_Delta_Psi = LKC_Delta_Psi;
	pLaDMC_DbgData->LAT_Kappa_Command = LAT_Kappa_Command;
	pLaDMC_DbgData->LAT_Kappa_Prime_Command = LAT_Kappa_Prime_Command;
	pLaDMC_DbgData->LAT_Psi = LAT_Psi;
	pLaDMC_DbgData->SAT_Saturated_Angle_Command = SAT_Saturated_Angle_Command;
	pLaDMC_DbgData->SAC_Yrc_Angle_Command = SAC_Yrc_Angle_Command;
	pLaDMC_DbgData->LAT_Eps_Torque_Request_Flag = LAT_Eps_Torque_Request_Flag;
	pLaDMC_DbgData->LAT_Delta_F_Cmd = LAT_Delta_F_Cmd;
	pLaDMC_DbgData->VEH_Delta_F = VEH_Delta_F;
	pLaDMC_DbgData->VEH_Yaw_Rate = VEH_Yaw_Rate;
	pLaDMC_DbgData->VEH_Yaw_Rate_Offset = VEH_Yaw_Rate_Offset;
	pLaDMC_DbgData->VEH_Vehicle_Velocity = VEH_Vehicle_Velocity;
	pLaDMC_DbgData->VEH_Delta_F_Dot = VEH_Delta_F_Dot;
	pLaDMC_DbgData->VEH_Steer_Torque = VEH_Steer_Torque;
	pLaDMC_DbgData->EPS_Tie_Rod_Load = EPS_Tie_Rod_Load;
	pLaDMC_DbgData->LAT_Ext_Command = LAT_Ext_Command;
	pLaDMC_DbgData->EPS_Motor_Torque = EPS_Motor_Torque;
	pLaDMC_DbgData->VEH_Brake_Force_Front_Axle = VEH_Brake_Force_Front_Axle;
	pLaDMC_DbgData->EPS_Status = EPS_Status;
	pLaDMC_DbgData->LAT_Dmc_Status = LAT_Dmc_Status;
	pLaDMC_DbgData->LaKMC_activation = LaKMC_activation;
	pLaDMC_DbgData->LaKMC_kappa_cmd = LaKMC_kappa_cmd;
	pLaDMC_DbgData->LKC_Kappa_Command_Arb = LKC_Kappa_Command_Arb; //ElNa add _arb suffix
	pLaDMC_DbgData->LaKMC_kappaP_cmd = LaKMC_kappaP_cmd;
	pLaDMC_DbgData->LaKMC_steer_kappa_ctrl_cmd = LaKMC_steer_kappa_ctrl_cmd;
	pLaDMC_DbgData->LKC_Steer_Kappa_Ctrl_Command = LKC_Steer_Kappa_Ctrl_Command;
	pLaDMC_DbgData->LaKMC_steer_angle_ctrl_cmd = LaKMC_steer_angle_ctrl_cmd;
	pLaDMC_DbgData->LaKMC_brake_kappa_ctrl_cmd = LaKMC_brake_kappa_ctrl_cmd;
	pLaDMC_DbgData->LaKMC_stiffness = LaKMC_stiffness;
	pLaDMC_DbgData->LaKMC_accuracy = LaKMC_accuracy;
	pLaDMC_DbgData->LaKMC_steering_wheel_vibration = LaKMC_steering_wheel_vibration;
	pLaDMC_DbgData->LaKMC_lateral_error = LaKMC_lateral_error;
	pLaDMC_DbgData->LaKMC_heading_error = LaKMC_heading_error;
	pLaDMC_DbgData->HEC_Psi_Control_Error = HEC_Psi_Control_Error;
	pLaDMC_DbgData->LDC_Delta_Psi_Dist = LDC_Delta_Psi_Dist;
	pLaDMC_DbgData->LDC_Psi_Command = LDC_Psi_Command;
	pLaDMC_DbgData->HEC_Delta_F_Cmd = HEC_Delta_F_Cmd;
	pLaDMC_DbgData->VEH_Lateral_Accel = VEH_Lateral_Accel;
	pLaDMC_DbgData->LAT_Tdf_Eps_Torque_Request_dbg = LAT_Tdf_Eps_Torque_Request_dbg;
	pLaDMC_DbgData->LAT_Arb_Eps_Torque_Request_dbg = LAT_Arb_Eps_Torque_Request_dbg;
	pLaDMC_DbgData->Lat_max_output_torque_dbg = Lat_max_output_torque_dbg;
	pLaDMC_DbgData->SAC_Torque_Sat_Out_dbg = SAC_Torque_Sat_Out_dbg;
	pLaDMC_DbgData->SAC_Derating_Torque_dbg = SAC_Derating_Torque_dbg;
	pLaDMC_DbgData->SAC_Torque_Out_Raw_dbg = SAC_Torque_Out_Raw_dbg;
	pLaDMC_DbgData->SAC_Load_Compensation_Torque_dbg = SAC_Load_Compensation_Torque_dbg;
	pLaDMC_DbgData->SAC_Limiter_Out_dbg = SAC_Limiter_Out_dbg;
	pLaDMC_DbgData->SAC_Kd_Part_dbg = SAC_Kd_Part_dbg;
	pLaDMC_DbgData->SAC_Active_Damping_Torque_dbg = SAC_Active_Damping_Torque_dbg;
	pLaDMC_DbgData->SAC_Ki_Part_dbg = SAC_Ki_Part_dbg;
	pLaDMC_DbgData->SAC_Kx_Part_dbg = SAC_Kx_Part_dbg;
	pLaDMC_DbgData->SAC_Latency_Compensation_Torque_dbg = SAC_Latency_Compensation_Torque_dbg;
	pLaDMC_DbgData->SAC_OScillation_Damp_Torque_dbg = SAC_OScillation_Damp_Torque_dbg;
	pLaDMC_DbgData->SAC_Eps_Trq_Load_Est_dbg = SAC_Eps_Trq_Load_Est_dbg;
	pLaDMC_DbgData->SAC_Friction_Comp_Torque_Out_dbg = SAC_Friction_Comp_Torque_Out_dbg;
	pLaDMC_DbgData->LAT_Rate_Limit_Control_Out_dbg = LAT_Rate_Limit_Control_Out_dbg;
	pLaDMC_DbgData->SAC_Delta_F_Filtered3_ = SAC_Delta_F_Filtered3_;
	pLaDMC_DbgData->SAC_Disable = SAC_Disable;
	pLaDMC_DbgData->Obs_observer_mode_sig = Obs_observer_mode_sig;
	pLaDMC_DbgData->VEH_Vehicle_Speed = VEH_Vehicle_Speed;
	pLaDMC_DbgData->LKA_Eps_Torque_Request_delayed = LKA_Eps_Torque_Request_delayed;
	pLaDMC_DbgData->SAC_Requested_Damping_Level_delayed = SAC_Requested_Damping_Level_delayed;
	pLaDMC_DbgData->TDF_Sac_Dos_Limit_Scale_delayed = TDF_Sac_Dos_Limit_Scale_delayed;
	pLaDMC_DbgData->Lat_max_output_torque_sig = Lat_max_output_torque_sig;
	pLaDMC_DbgData->SAC_Rate_Lim_Feed_Fwd_Torque = SAC_Rate_Lim_Feed_Fwd_Torque;
	pLaDMC_DbgData->SAC_Eps_Trq_Load_Est = SAC_Eps_Trq_Load_Est;
	pLaDMC_DbgData->SAC_Steer_Velocity_Source = SAC_Steer_Velocity_Source;
	pLaDMC_DbgData->SAC_Obs_Var_Delay = SAC_Obs_Var_Delay;
	pLaDMC_DbgData->LaKMC_kappa_cmd_dbg = LaKMC_kappa_cmd_dbg;
	pLaDMC_DbgData->VEH_Delta_F_dbg = VEH_Delta_F_dbg;
	pLaDMC_DbgData->VEH_Delta_F_Dot_dbg = VEH_Delta_F_Dot_dbg;
	pLaDMC_DbgData->VEH_Steer_Torque_dbg = VEH_Steer_Torque_dbg;
	pLaDMC_DbgData->EPS_Tie_Rod_Load_dbg = EPS_Tie_Rod_Load_dbg;
	pLaDMC_DbgData->EPS_Motor_Torque_dbg = EPS_Motor_Torque_dbg;
	pLaDMC_DbgData->EPS_Status_dbg = EPS_Status_dbg;
	pLaDMC_DbgData->DMC_EPS_STATUS = DMC_EPS_STATUS;
	pLaDMC_DbgData->LaDMC_Eps_Torque_Request_dbg = LaDMC_Eps_Torque_Request_dbg;
	pLaDMC_DbgData->SAT_Saturated_Angle_Command_dbg = SAT_Saturated_Angle_Command_dbg;
	pLaDMC_DbgData->LAT_Dmc_Status_dbg = LAT_Dmc_Status_dbg;
	pLaDMC_DbgData->LDC_Psi_Command_dbg = LDC_Psi_Command_dbg;
	pLaDMC_DbgData->DYC_Steer_Angle_Feedforward_dbg = DYC_Steer_Angle_Feedforward_dbg;
	pLaDMC_DbgData->LAT_Delta_Ys_dbg = LAT_Delta_Ys_dbg;
	pLaDMC_DbgData->LAT_Delta_Psi_dbg = LAT_Delta_Psi_dbg;
	pLaDMC_DbgData->LAT_Kappa_Command_dbg = LAT_Kappa_Command_dbg;
	pLaDMC_DbgData->HEC_Psi_Control_Error_dbg = HEC_Psi_Control_Error_dbg;
	pLaDMC_DbgData->HEC_Delta_F_Cmd_dbg = HEC_Delta_F_Cmd_dbg;
	pLaDMC_DbgData->LDC_Delta_Psi_Dist_dbg = LDC_Delta_Psi_Dist_dbg;
	pLaDMC_DbgData->SAC_Yrc_Angle_Command_dbg = SAC_Yrc_Angle_Command_dbg;
	pLaDMC_DbgData->DMC_LAT_DEGRADATION = DMC_LAT_DEGRADATION;
	pLaDMC_DbgData->DMC_LAT_DEGRADATION_TEMP = DMC_LAT_DEGRADATION_TEMP;
	pLaDMC_DbgData->VEH_Stability_Control_Active = VEH_Stability_Control_Active;
	pLaDMC_DbgData->VEH_Stability_Control_Active_temp = VEH_Stability_Control_Active_temp;
	pLaDMC_DbgData->LKC_Lane_Status = LKC_Lane_Status;
	pLaDMC_DbgData->LAT_Kappa_Linz_Omega_dbg = LAT_Kappa_Linz_Omega_dbg;
	pLaDMC_DbgData->LAT_Kappa_Filter_Output_dbg = LAT_Kappa_Filter_Output_dbg;
	pLaDMC_DbgData->LAT_Filtered_Delta_F_Offset_dbg = LAT_Filtered_Delta_F_Offset_dbg;
	pLaDMC_DbgData->Lat_rate_limited_offset_dbg = Lat_rate_limited_offset_dbg;
	pLaDMC_DbgData->SAC_Trq_Derating_Factor_dbg = SAC_Trq_Derating_Factor_dbg;
	pLaDMC_DbgData->TDF_Sac_Dos_Limit_Scale_dbg = TDF_Sac_Dos_Limit_Scale_dbg;	
	pLaDMC_DbgData->Cam_kappa_feedfwd = Cam_kappa_feedfwd;	
	pLaDMC_DbgData->LaKMC_kappa_sum_command = LaKMC_kappa_sum_command;	
	pLaDMC_DbgData->Cam_kappa_qf = Cam_kappa_qf;	
	pLaDMC_DbgData->LKC_Lane_Status_dbg = LKC_Lane_Status_dbg;	
	pLaDMC_DbgData->LAT_Oc_Integrator_Input_Kappa_dbg = LAT_Oc_Integrator_Input_Kappa_dbg;
	pLaDMC_DbgData->LAT_Oc_Integrator_Input_Raw_dbg = LAT_Oc_Integrator_Input_Raw_dbg;
	pLaDMC_DbgData->CAM_Kappa_Cmd_dbg = CAM_Kappa_Cmd_dbg;
	pLaDMC_DbgData->LAT_Oc_Kappa_Status_dbg = LAT_Oc_Kappa_Status_dbg;
	pLaDMC_DbgData->LAT_Oc_Dys_Status_dbg = LAT_Oc_Dys_Status_dbg;
	pLaDMC_DbgData->LAT_Gen_Purpose_dbg = LAT_Gen_Purpose_dbg;
	pLaDMC_DbgData->VEH_Delta_F_Oc_dbg = VEH_Delta_F_Oc_dbg;
	pLaDMC_DbgData->SAT_Req_Angle_Supp_Control_dbg = SAT_Req_Angle_Supp_Control_dbg;
	pLaDMC_DbgData->MOT_Modulated_Torque_dbg = MOT_Modulated_Torque_dbg;
    	pLaDMC_DbgData->TDF_Steer_Torque_Sample_dbg = TDF_Steer_Torque_Sample_dbg;
	pLaDMC_DbgData->SAC_Factor_Kp_dbg = SAC_Factor_Kp_dbg;
	pLaDMC_DbgData->SAC_Enhanced_Angle_Cmd_dbg = SAC_Enhanced_Angle_Cmd_dbg;
	pLaDMC_DbgData->SAC_Fading_Offset_dbg = SAC_Fading_Offset_dbg;
	pLaDMC_DbgData->DYC_Boost_Filter_Out_dbg = DYC_Boost_Filter_Out_dbg;
	pLaDMC_DbgData->SAC_Load_Comp_Factor_Varia_dbg = SAC_Load_Comp_Factor_Varia_dbg;
	pLaDMC_DbgData->SAC_Arb_Angle_Cmd_Raw_dbg = SAC_Arb_Angle_Cmd_Raw_dbg;
	pLaDMC_DbgData->SAC_Faded_Angle_Command_dbg = SAC_Faded_Angle_Command_dbg;
	pLaDMC_DbgData->DYC_Boost_Request_dbg = DYC_Boost_Request_dbg;
	pLaDMC_DbgData->LAT_Debug1_dbg = LAT_Debug1_dbg;
	pLaDMC_DbgData->LAT_Debug2_dbg = LAT_Debug2_dbg;
	pLaDMC_DbgData->LAT_Debug3_dbg = LAT_Debug3_dbg;
	pLaDMC_DbgData->LAT_Debug4_dbg = LAT_Debug4_dbg;
	pLaDMC_DbgData->LAT_Debug5_dbg = LAT_Debug5_dbg;
	pLaDMC_DbgData->LAT_Debug6_dbg = LAT_Debug6_dbg;
	pLaDMC_DbgData->LAT_Debug7_dbg = LAT_Debug7_dbg;
	pLaDMC_DbgData->LAT_Debug8_dbg = LAT_Debug8_dbg;
	pLaDMC_DbgData->Cam_lateral_error = Cam_lateral_error;
	pLaDMC_DbgData->Cam_heading_error = Cam_heading_error;
	pLaDMC_DbgData->VEH_Yaw_Rate_Oc_dbg = VEH_Yaw_Rate_Oc_dbg;
	pLaDMC_DbgData->SAC_Load_Comp_Factor_Straight_dbg = SAC_Load_Comp_Factor_Straight_dbg;
	pLaDMC_DbgData->OBS_Discharge_Req_Level_dbg = OBS_Discharge_Req_Level_dbg;
	pLaDMC_DbgData->OBS_Boost_Request_Level_dbg = OBS_Boost_Request_Level_dbg;
	pLaDMC_DbgData->SAC_Steering_Wheel_Angle_Cmd_dbg = SAC_Steering_Wheel_Angle_Cmd_dbg;
	pLaDMC_DbgData->SAC_Filtered_Angle_Command_dbg = SAC_Filtered_Angle_Command_dbg;
	pLaDMC_DbgData->LADMC_STEER_ANGLE_REQ = LADMC_STEER_ANGLE_REQ;
	pLaDMC_DbgData->LADMC_ACCURACY_LEVEL_REQUEST = LADMC_ACCURACY_LEVEL_REQUEST;
	pLaDMC_DbgData->SAC_Dyn_Corrected_Angle_Cmd_dbg = SAC_Dyn_Corrected_Angle_Cmd_dbg;
	pLaDMC_DbgData->TDF_Idle_Status_dbg = TDF_Idle_Status_dbg;
	pLaDMC_DbgData->SAC_Max_Torque_Scale_dbg = SAC_Max_Torque_Scale_dbg;
	pLaDMC_DbgData->SAC_Accuracy_Request_dbg = SAC_Accuracy_Request_dbg;
	pLaDMC_DbgData->DMC_STIFFNESS_LIMIT = DMC_STIFFNESS_LIMIT;
	pLaDMC_DbgData->DMC_STIFFNESS_GRAD = DMC_STIFFNESS_GRAD;
	pLaDMC_DbgData->DMC_TORQUE_SCALE_LIMIT = DMC_TORQUE_SCALE_LIMIT;
	pLaDMC_DbgData->DMC_TORQUE_SCALE_GRAD = DMC_TORQUE_SCALE_GRAD;
	pLaDMC_DbgData->DMC_TORQUE_RAMP_GRAD = DMC_TORQUE_RAMP_GRAD;
	pLaDMC_DbgData->DMC_HIGH_ACCURACY_REQUEST = DMC_HIGH_ACCURACY_REQUEST;
	pLaDMC_DbgData->DMC_ANGLE_FADING_REQ = DMC_ANGLE_FADING_REQ;
	pLaDMC_DbgData->DMC_RAMPING_DOWN_REQ = DMC_RAMPING_DOWN_REQ;
	pLaDMC_DbgData->SAC_Delta_F_Cmd_Grad_Param_dbg = SAC_Delta_F_Cmd_Grad_Param_dbg;
	pLaDMC_DbgData->SAC_Yrc_Residual_dbg = SAC_Yrc_Residual_dbg;
	pLaDMC_DbgData->DMC_ANGLE_REQ_MAX_LIMIT_SCALE = DMC_ANGLE_REQ_MAX_LIMIT_SCALE;	
	pLaDMC_DbgData->DMC_ANGLE_REQ_MAX_GRAD_SCALE = DMC_ANGLE_REQ_MAX_GRAD_SCALE;
	pLaDMC_DbgData->SAC_Angle_Command_Raw_dbg = SAC_Angle_Command_Raw_dbg;
	pLaDMC_DbgData->LAT_Activation_Request_nu = LAT_Activation_Request_nu;
	pLaDMC_DbgData->LAT_Activation_Request_Qf_nu = LAT_Activation_Request_Qf_nu;
	pLaDMC_DbgData->LAT_Force_Shut_Off_Request = LAT_Force_Shut_Off_Request;
	pLaDMC_DbgData->LAT_Steer_Angle_Command_deg = LAT_Steer_Angle_Command_deg;
	pLaDMC_DbgData->LAT_Torque_Overlay_Request_nm = LAT_Torque_Overlay_Request_nm;
	pLaDMC_DbgData->LAT_Stiffness_Request_per = LAT_Stiffness_Request_per;
	pLaDMC_DbgData->LAT_Accuracy_Request_per = LAT_Accuracy_Request_per;
	pLaDMC_DbgData->LAT_Steering_Wheel_Vibration_nu = LAT_Steering_Wheel_Vibration_nu;
	pLaDMC_DbgData->LAT_Lane_Status_nu = LAT_Lane_Status_nu;
	pLaDMC_DbgData->LAT_Derating_Level_Request_per = LAT_Derating_Level_Request_per;
	pLaDMC_DbgData->SAC_Soc_Disable = SAC_Soc_Disable;
	pLaDMC_DbgData->DMC_RAMPING_DOWN_REQ = DMC_RAMPING_DOWN_REQ;
	pLaDMC_DbgData->SAC_Load_Cmp_Fct_Curv_Chg_dbg = SAC_Load_Cmp_Fct_Curv_Chg_dbg;
	pLaDMC_DbgData->DMC_ANGLE_OFF_LOOP0 = DMC_ANGLE_OFF_LOOP0;
	pLaDMC_DbgData->DMC_ANGLE_OFF_CALIB_CNT_LOOP0 = DMC_ANGLE_OFF_CALIB_CNT_LOOP0;
	pLaDMC_DbgData->DMC_ANGLE_OFF_READ_ERROR = DMC_ANGLE_OFF_READ_ERROR;
	pLaDMC_DbgData->DMC_ANGLE_OFF = DMC_ANGLE_OFF;
	pLaDMC_DbgData->DMC_ANGLE_OFF_CALIB_CNT = DMC_ANGLE_OFF_CALIB_CNT;
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor = ADP_Dyc_Corr_Factor;
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor_Ls = ADP_Dyc_Corr_Factor_Ls;
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor_Rs = ADP_Dyc_Corr_Factor_Rs;
	pLaDMC_DbgData->Turn_And_Error_Side = Turn_And_Error_Side;
	pLaDMC_DbgData->CAM_Lateral_Error_Mean = CAM_Lateral_Error_Mean;
	pLaDMC_DbgData->CAM_Lateral_Error_Delta = CAM_Lateral_Error_Delta;
	pLaDMC_DbgData->Maximum_Waiting_Counter = Maximum_Waiting_Counter;
	pLaDMC_DbgData->Factor_Increase = Factor_Increase;
	pLaDMC_DbgData->Factor_Decrease = Factor_Decrease;
	pLaDMC_DbgData->LTLE_Waiting_Counter = LTLE_Waiting_Counter;
	pLaDMC_DbgData->LTRE_Waiting_Counter = LTRE_Waiting_Counter;
	pLaDMC_DbgData->RTLE_Waiting_Counter = RTLE_Waiting_Counter;
	pLaDMC_DbgData->RTRE_Waiting_Counter = RTRE_Waiting_Counter;
	pLaDMC_DbgData->Factor_Corr_Enable_Flag = Factor_Corr_Enable_Flag;
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor_Left_Vect[0] = ADP_Dyc_Corr_Factor_Left_Vect[0];
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor_Left_Vect[1] = ADP_Dyc_Corr_Factor_Left_Vect[1];
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor_Left_Vect[2] = ADP_Dyc_Corr_Factor_Left_Vect[2];
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor_Left_Vect[3] = ADP_Dyc_Corr_Factor_Left_Vect[3];
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor_Left_Vect[4] = ADP_Dyc_Corr_Factor_Left_Vect[4];
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor_Left_Vect[5] = ADP_Dyc_Corr_Factor_Left_Vect[5];
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor_Left_Vect[6] = ADP_Dyc_Corr_Factor_Left_Vect[6];
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor_Left_Vect[7] = ADP_Dyc_Corr_Factor_Left_Vect[7];
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor_Left_Vect[8] = ADP_Dyc_Corr_Factor_Left_Vect[8];
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor_Left_Vect[9] = ADP_Dyc_Corr_Factor_Left_Vect[9];
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor_Left_Vect[10] = ADP_Dyc_Corr_Factor_Left_Vect[10];
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor_Left_Vect[11] = ADP_Dyc_Corr_Factor_Left_Vect[11];
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor_Left_Vect[12] = ADP_Dyc_Corr_Factor_Left_Vect[12];
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor_Left_Vect[13] = ADP_Dyc_Corr_Factor_Left_Vect[13];
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor_Left_Vect[14] = ADP_Dyc_Corr_Factor_Left_Vect[14];
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor_Left_Vect[15] = ADP_Dyc_Corr_Factor_Left_Vect[15];
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor_Left_Vect[16] = ADP_Dyc_Corr_Factor_Left_Vect[16];
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor_Left_Vect[17] = ADP_Dyc_Corr_Factor_Left_Vect[17];
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor_Left_Vect[18] = ADP_Dyc_Corr_Factor_Left_Vect[18];
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor_Left_Vect[19] = ADP_Dyc_Corr_Factor_Left_Vect[19];
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor_Right_Vect[0] = ADP_Dyc_Corr_Factor_Right_Vect[0];
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor_Right_Vect[1] = ADP_Dyc_Corr_Factor_Right_Vect[1];
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor_Right_Vect[2] = ADP_Dyc_Corr_Factor_Right_Vect[2];
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor_Right_Vect[3] = ADP_Dyc_Corr_Factor_Right_Vect[3];
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor_Right_Vect[4] = ADP_Dyc_Corr_Factor_Right_Vect[4];
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor_Right_Vect[5] = ADP_Dyc_Corr_Factor_Right_Vect[5];
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor_Right_Vect[6] = ADP_Dyc_Corr_Factor_Right_Vect[6];
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor_Right_Vect[7] = ADP_Dyc_Corr_Factor_Right_Vect[7];
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor_Right_Vect[8] = ADP_Dyc_Corr_Factor_Right_Vect[8];
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor_Right_Vect[9] = ADP_Dyc_Corr_Factor_Right_Vect[9];
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor_Right_Vect[10] = ADP_Dyc_Corr_Factor_Right_Vect[10];
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor_Right_Vect[11] = ADP_Dyc_Corr_Factor_Right_Vect[11];
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor_Right_Vect[12] = ADP_Dyc_Corr_Factor_Right_Vect[12];
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor_Right_Vect[13] = ADP_Dyc_Corr_Factor_Right_Vect[13];
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor_Right_Vect[14] = ADP_Dyc_Corr_Factor_Right_Vect[14];
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor_Right_Vect[15] = ADP_Dyc_Corr_Factor_Right_Vect[15];
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor_Right_Vect[16] = ADP_Dyc_Corr_Factor_Right_Vect[16];
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor_Right_Vect[17] = ADP_Dyc_Corr_Factor_Right_Vect[17];
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor_Right_Vect[18] = ADP_Dyc_Corr_Factor_Right_Vect[18];
	pLaDMC_DbgData->ADP_Dyc_Corr_Factor_Right_Vect[19] = ADP_Dyc_Corr_Factor_Right_Vect[19];
	pLaDMC_DbgData->Mean_Kappa_Command = Mean_Kappa_Command;
	pLaDMC_DbgData->Mean_Vehicle_Velocity = Mean_Vehicle_Velocity;
	pLaDMC_DbgData->LAT_Oc_Rls_Delta_L_Offst_Lim_dbg = LAT_Oc_Rls_Delta_L_Offst_Lim_dbg;
	pLaDMC_DbgData->LAT_Oc_Rls_Status_dbg = LAT_Oc_Rls_Status_dbg;

	//TODO: make custom functions to copy debug signals specific to a particular variant in ladmc_wrp_custom.c
	pLaDMC_DbgData->SAC_Derated_Angle_Command_dbg = SAC_Derated_Angle_Command_dbg;	
#ifdef	LAT_Gi_Status_dbg
	pLaDMC_DbgData->LCFVeh_pstDbgData.LaDMC_DbgData.LAT_Gi_Status_dbg = LAT_Gi_Status_dbg;
#endif
	pLaDMC_DbgData->DMC_DERATING_LEVEL_REQ = DMC_DERATING_LEVEL_REQ;
	pLaDMC_DbgData->SAT_Angle_Rate_Residual_dbg = SAT_Angle_Rate_Residual_dbg;
	pLaDMC_DbgData->SAC_Damping_Angle_Command_dbg = SAC_Damping_Angle_Command_dbg;
	pLaDMC_DbgData->SAC_Ctrl_Err_Memshp_Low_Dyn_dbg = SAC_Ctrl_Err_Memshp_Low_Dyn_dbg;
	pLaDMC_DbgData->SAC_Control_Err_Membership_dbg = SAC_Control_Err_Membership_dbg;
	pLaDMC_DbgData->VDY_Steer_Angle_Offset = VDY_Steer_Angle_Offset;
	pLaDMC_DbgData->LAT_Kappa_Sum_Command_1pm = LAT_Kappa_Sum_Command_1pm;
	pLaDMC_DbgData->SAT_Req_Steer_Angle_Max_Ay_dbg = SAT_Req_Steer_Angle_Max_Ay_dbg;
	pLaDMC_DbgData->LAT_Ay_Control_Limit_Bias_dbg = LAT_Ay_Control_Limit_Bias_dbg;
	pLaDMC_DbgData->VEH_Delta_clm_sens_F_dbg = VEH_Delta_clm_sens_F_dbg;
	pLaDMC_DbgData->UNCALIBRATED_SWA_FIL = UNCALIBRATED_SWA_FIL;
	pLaDMC_DbgData->SAC_Delta_F_Sat_Command_dbg = SAC_Delta_F_Sat_Command_dbg;
	//pLaDMC_DbgData->SAC_Limiter_Active_dbg = SAC_Limiter_Active_dbg; //ElNa Signal not defined anywhere
	pLaDMC_DbgData->SAT_Active_Saturation_dbg = SAT_Active_Saturation_dbg;
	pLaDMC_DbgData->DMC_DRIVING_MODE = DMC_DRIVING_MODE;
	pLaDMC_DbgData->DMC_BANK_ANGLE = DMC_BANK_ANGLE;
	pLaDMC_DbgData->SAC_R_Factor = SAC_R_Factor;
	pLaDMC_DbgData->LAT_Oc_Delta_Ys_Filtered_dbg = LAT_Oc_Delta_Ys_Filtered_dbg;
	pLaDMC_DbgData->SAC_Angle_Cmd_Yawrate_Fback_dbg = SAC_Angle_Cmd_Yawrate_Fback_dbg;
	pLaDMC_DbgData->SAT_Req_Dyn_Steer_Angle_Max_dbg = SAT_Req_Dyn_Steer_Angle_Max_dbg;
	pLaDMC_DbgData->LAT_Oc_Rls_Delta_L_Offset_Raw_dbg = LAT_Oc_Rls_Delta_L_Offset_Raw_dbg;
	pLaDMC_DbgData->LAT_Oc_Rls_stiffness_dbg = LAT_Oc_Rls_stiffness_dbg;
	pLaDMC_DbgData->LAT_Oc_Rls_variance_stiffnes_dbg = LAT_Oc_Rls_variance_stiffnes_dbg;
	pLaDMC_DbgData->LAT_Oc_Rls_variance_offset_dbg = LAT_Oc_Rls_variance_offset_dbg;
	pLaDMC_DbgData->LAT_Oc_Rls_cov_stiffnes_offs_dbg = LAT_Oc_Rls_cov_stiffnes_offs_dbg;
	pLaDMC_DbgData->LAT_Ay_Dynamic_Threshold_dbg = LAT_Ay_Dynamic_Threshold_dbg;
	pLaDMC_DbgData->SAT_Req_Steer_Angle_Max_dbg = SAT_Req_Steer_Angle_Max_dbg;
	pLaDMC_DbgData->DMC_ADP_CORR_FACTOR_READ_ERROR = DMC_ADP_CORR_FACTOR_READ_ERROR;
	pLaDMC_DbgData->LCF_Operation_Mode = LCF_Operation_Mode;
	pLaDMC_DbgData->DMC_GPIO = DMC_GPIO;
	pLaDMC_DbgData->SAC_Control_Error_Eps_dbg = SAC_Control_Error_Eps_dbg; 
	pLaDMC_DbgData->LAT_Pitch_Angle_Deviation_dbg = LAT_Pitch_Angle_Deviation_dbg; 
	pLaDMC_DbgData->EMO_PITCH_ANGLE = EMO_PITCH_ANGLE;
	pLaDMC_DbgData->LAT_Oc_Rls_var1_stiff_V4_dbg = LAT_Oc_Rls_var1_stiff_V4_dbg;
	pLaDMC_DbgData->LAT_Oc_Rls_var1_off_V4_dbg = LAT_Oc_Rls_var1_off_V4_dbg;
	pLaDMC_DbgData->LAT_Oc_Rls_var_stiff_V2_dbg = LAT_Oc_Rls_var_stiff_V2_dbg;
	pLaDMC_DbgData->LAT_Oc_Rls_cov_stiff_off_V2_dbg = LAT_Oc_Rls_cov_stiff_off_V2_dbg;
	pLaDMC_DbgData->LAT_Oc_Rls_var_off_V2_dbg = LAT_Oc_Rls_var_off_V2_dbg;
	pLaDMC_DbgData->LAT_Oc_Rls_var1_stiff_V3_dbg = LAT_Oc_Rls_var1_stiff_V3_dbg;
	pLaDMC_DbgData->LAT_Oc_Rls_var1_off_V3_dbg = LAT_Oc_Rls_var1_off_V3_dbg;
	pLaDMC_DbgData->LAT_Oc_Rls_stiff_V3_dbg = LAT_Oc_Rls_stiff_V3_dbg;
	pLaDMC_DbgData->LAT_Oc_Rls_stiff_V4_dbg = LAT_Oc_Rls_stiff_V4_dbg;
	pLaDMC_DbgData->LAT_Oc_Rls_Delta_L_dead_V4_dbg = LAT_Oc_Rls_Delta_L_dead_V4_dbg;
	pLaDMC_DbgData->LAT_Oc_Rls_Delta_L_Off_V4_dbg = LAT_Oc_Rls_Delta_L_Off_V4_dbg;
	pLaDMC_DbgData->LAT_Oc_Rls_stiffness_V2_dbg = LAT_Oc_Rls_stiffness_V2_dbg;
	pLaDMC_DbgData->LAT_Oc_Rls_Delta_L_Offset_V2_dbg = LAT_Oc_Rls_Delta_L_Offset_V2_dbg;
	pLaDMC_DbgData->LAT_Oc_Rls_Delta_L_dead_V3_dbg = LAT_Oc_Rls_Delta_L_dead_V3_dbg;
	pLaDMC_DbgData->LAT_Oc_Rls_Delta_L_Off_V3_dbg = LAT_Oc_Rls_Delta_L_Off_V3_dbg;
	pLaDMC_DbgData->DYC_Angle_Per_Kappa = DYC_Angle_Per_Kappa;
	pLaDMC_DbgData->VDY_Bank_Angle = VDY_Bank_Angle;
	pLaDMC_DbgData->DMC_Steer_Angle_Oc_deg = DMC_Steer_Angle_Oc_deg;
	pLaDMC_DbgData->DMC_GPIO2 = DMC_GPIO2;
	pLaDMC_DbgData->DMC_GPIO3 = DMC_GPIO3;
	pLaDMC_DbgData->DMC_GPIO4 = DMC_GPIO4;
	pLaDMC_DbgData->DMC_Eps_Integrator_Hold_Req_nu = DMC_Eps_Integrator_Hold_Req_nu;
	pLaDMC_DbgData->DMC_SHUT_OFF_ON_ERROR = DMC_SHUT_OFF_ON_ERROR;
	pLaDMC_DbgData->SAC_Dynamic_Correction_Factor_dbg = SAC_Dynamic_Correction_Factor_dbg;
	pLaDMC_DbgData->DMC_ROAD_WHEEL_ANGLE = DMC_ROAD_WHEEL_ANGLE;
	pLaDMC_DbgData->SAC_Derated_Eps_Torque_dbg = SAC_Derated_Eps_Torque_dbg;
	pLaDMC_DbgData->TDF_Torque_Derating_Factor_dbg = TDF_Torque_Derating_Factor_dbg;
	pLaDMC_DbgData->LAT_Eps_Torque_Request_nm = LAT_Eps_Torque_Request_nm;
	pLaDMC_DbgData->LAT_Road_Wheel_Angle_Cmd_deg = LAT_Road_Wheel_Angle_Cmd_deg;
}

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */

