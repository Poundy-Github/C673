/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 Lcf

  MODULNAME:                 lcf_cfg_custom.h

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.5 $


  ---*/ /*--- 
  CHANGES:                   

**************************************************************************** */

#ifndef LCF_CFG_CUSTOM_H_
#define LCF_CFG_CUSTOM_H_

/*---------------------------------------------------------*
   M A C R O S
 *---------------------------------------------------------*/
#ifndef LCF_MFC5J3
#define LCF_MFC5J3
#else
#error "Project name LCF_MFC5J3 defined in different file than lcf_cfg_custom "
#endif

/*****************************************************************************
  Config:   
*****************************************************************************/

/*Defines for Optional ports*/
#define USE_IPC_PARAMS     (0u)      /* 1 if there is enough memory on IuC to send all eeprom parameters*/
#define USE_IPC_PARAMS_SIM (1u)      /*For simulation, populate pCParLdp and pCParLka if exists*/
#define HLA_RADAR_OBJECT_USED 	 (0u)
#define LCF_CAMOBJ_USED          (0u)//debug (1u)
#define LCF_IUC_USED             (0u)  /* For LaDMC*/
#define LCF_NVM_USED             (1u)  /*Enable NVM ussage - RO1444214*/
/*Defines for ErrorHandling activation*/
#define LCF_SEN_ERR_USED         (1u)
#define LCF_VEH_ERR_USED         (0u)

/*#define LCF_SIL_MANIPULATE_INPUTS*/

#define LCF_VEH_LADMC_CYCLE_TIME              (10u)           /*!< cycle time for LaDMC */
#define LCF_VEH_MAX_TASKCOUNT_VAL             (119u)          /* The maximum value of uiTaskCnt must be a common multiple of task rates (minus 1). Value 120(-1) is the least common multiple for task rates: 1,2,3,4,5,6,8,10,12 */

#if defined(LCF_VEH_LADMC_CYCLE_TIME) && (LCF_VEH_LADMC_CYCLE_TIME == 10u)
#define LCF_VEH_CYCLE_TIME                    (0.01f) /*LCF_VEH called every 10ms*/
#define LCF_VEH_DRVMN_TASK_RATE               (2u)    /*DRVMN called every second task (20ms)*/
#define LCF_VEH_TRJPLN_TASK_RATE              (2u)    /*TRJPLN called every second task (20ms)*/
#define LCF_VEH_TRJCTR_TASK_RATE              (2u)    /*TRJCTR called every second task (20ms)*/
#define LCF_VEH_v1TRJCTR_TASK_RATE            (2u)    /*v1TRJCTR called every second task (20ms)*/
#define LCF_VEH_LATDMC_TASK_RATE              (1u)    /*LATDMC called every task (10ms)*/
#define LCF_VEH_DDROC_TASK_RATE               (2u)    /*DDROC called every second task (20ms)*/
#else
#define LCF_VEH_CYCLE_TIME                    (0.02f) /*LCF_VEH called every 20ms*/
#define LCF_VEH_DRVMN_TASK_RATE               (1u)    /*DRVMN called every task (20ms)*/
#define LCF_VEH_TRJPLN_TASK_RATE              (1u)    /*TRJPLN called every task (20ms)*/
#define LCF_VEH_TRJCTR_TASK_RATE              (1u)    /*TRJCTR called every task (20ms)*/
#define LCF_VEH_v1TRJCTR_TASK_RATE            (1u)    /*v1TRJCTR called every second task (20ms)*/
#define LCF_VEH_LATDMC_TASK_RATE              (1u)    /*LATDMC called every task (20ms)*/
#define LCF_VEH_DDROC_TASK_RATE               (1u)    /*DDROC called every task (20ms)*/
#endif

/*****************************************************************************
  MACROS (CUSTOM MASKS FOR PORTS CHECKS)
*****************************************************************************/

#endif /* LCF_CFG_CUSTOM_H_ */


