//* **********************************************************************
//  COMPANY:         $CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
//  
//  PROJECT:         MFC30x_MCU
//  CPU:             MPC5675K
//  
//  PACKAGE:         $Source: ic_errcodes.h $ $Revision: 1.1 $
//  MKS Date:        $Date: 2021/12/13 17:25:50CET $
//  
//  RHAPSODY:        7.5.3
//  COMPONENT:       IC
//  CONFIGURATION:   DefaultConfig
//  MODEL ELEMENT:   ic_errcodes
//  MODULNAME:       ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_errcodes.h
//  LOGIN:           uidt3974  
//  
//  
//  
//  AUTHOR:          $Author: Wang, David (Wangd3) $
//! CREATION DATE:   Thu, 18, Oct 2012  12:22 W. Europe Daylight Time PM 
//**************************************************************************** */

#ifndef ic_errcodes_H
#define ic_errcodes_H

/*## dependency ic_cfg */
#include "ic_cfg.h"
/*## package Ic_Pkg */

/*## class TopLevel::ic_errcodes */


/*#[ ignore */

#ifdef __cplusplus
extern "C"
{
#endif

/*#]*/


/*#[ type IC_ERRDEF_LEFTIMG */
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
#define IC_ERRDEF_LEFTIMG(x) IC_ERRDEF(x) // PRQA S 3429,3453
#else
#define IC_ERRDEF_LEFTIMG(x) // PRQA S 3429,3453
#endif
/*#]*/

/*#[ type IC_ERRDEF_ATEST */
#if (IC_ANALOG_TEST_ENABLED == 1)
#define IC_ERRDEF_ATEST(x) IC_ERRDEF(x) // PRQA S 3429,3453
#else
#define IC_ERRDEF_ATEST(x) // PRQA S 3429,3453
#endif
/*#]*/

/*#[ type IC_ERRCODES */
#define IC_ERRCODES \
    IC_ERRDEF(IC_e_ERR_OK) \
    IC_ERRDEF(IC_e_ERR_EXPLICIT_DEM) \
 \
    /* Common errors */ \
    IC_ERRDEF(IC_e_ERR_WRONG_STATE) \
    IC_ERRDEF(IC_e_ERR_NULLPOINTER) \
    IC_ERRDEF(IC_e_ERR_ILLEGAL_ARGUMENT) \
    IC_ERRDEF(IC_e_ERR_NOTAVAILABLE) \
    IC_ERRDEF(IC_e_ERR_NOT_IMPLEMENTED) \
    IC_ERRDEF(IC_e_ERR_BUFFER_OVERRUN) \
    IC_ERRDEF(IC_e_ERR_FATAL_PROGRAM_ERROR) \
    IC_ERRDEF(IC_e_ERR_SOURCECODE_ERROR) \
    IC_ERRDEF(IC_e_ERR_DIVISION_BY_ZERO) \
    IC_ERRDEF(IC_e_ERR_ILLEGAL_ENUM_VALUE) \
 \
    /* Submodule initialization */ \
    IC_ERRDEF(IC_e_ERR_NOTINIT) \
    IC_ERRDEF(IC_e_ERR_INIT_SENSORDRV) \
    IC_ERRDEF(IC_e_ERR_INIT_IEDP) \
    IC_ERRDEF(IC_e_ERR_INIT_ERRMANAGER) \
    IC_ERRDEF(IC_e_ERR_INIT_ICPARAMETERS) \
 \
    /* Imager communication */ \
    IC_ERRDEF(IC_e_ERR_RXTX_BUSERR) \
    IC_ERRDEF(IC_e_ERR_RXTX_NOACK) \
    IC_ERRDEF(IC_e_ERR_RXTX_BUFFER_OVERFLOW) \
    IC_ERRDEF(IC_e_ERR_RXTX_OTHER) \
    IC_ERRDEF(IC_e_ERR_REGTX) \
    IC_ERRDEF(IC_e_ERR_REGRX) \
    IC_ERRDEF(IC_e_ERR_ILLEGAL_REGTRANSFER_ID) \
 \
    /* Register verification */ \
    IC_ERRDEF(IC_e_ERR_INITSEQ_VERIFY) \
    IC_ERRDEF(IC_e_ERR_REGCOMPARE_FAILED) \
    IC_ERRDEF(IC_e_ERR_REGTRANS_ERRORS_NOT_ZERO) \
    IC_ERRDEF(IC_e_ERR_CHECK_REGISTERS_R) \
    IC_ERRDEF(IC_e_ERR_CHECK_REGISTERS_I2C_R) \
    IC_ERRDEF(IC_e_ERR_CHECK_REGISTERS_R_FSYNCED) \
    IC_ERRDEF(IC_e_ERR_CHECK_REGISTERS_R_CONST) \
    IC_ERRDEF(IC_e_ERR_ASYNC_REGCHECK_READ_R) \
    IC_ERRDEF(IC_e_ERR_REGTX_VERIFY_FAILED_R) \
    IC_ERRDEF(IC_e_ERR_REGCHECK_I2C_NOT_FINISHED) \
 \
    IC_ERRDEF_LEFTIMG(IC_e_ERR_CHECK_REGISTERS_L) \
    IC_ERRDEF_LEFTIMG(IC_e_ERR_CHECK_REGISTERS_I2C_L) \
    IC_ERRDEF_LEFTIMG(IC_e_ERR_CHECK_REGISTERS_L_FSYNCED) \
    IC_ERRDEF_LEFTIMG(IC_e_ERR_CHECK_REGISTERS_L_CONST) \
    IC_ERRDEF_LEFTIMG(IC_e_ERR_CHECK_REGISTERS_L_LATENCY) \
    IC_ERRDEF_LEFTIMG(IC_e_ERR_ASYNC_REGCHECK_READ_L) \
    IC_ERRDEF_LEFTIMG(IC_e_ERR_REGTX_VERIFY_FAILED_L) \
    IC_ERRDEF_LEFTIMG(IC_e_ERR_REGISTER_LEFT_REQUEST_TOO_BIG) \
    IC_ERRDEF_LEFTIMG(IC_e_ERR_PROCESS_LEFTREGS_REPONSE) \
 \
    /* FuSi checks */ \
    IC_ERRDEF(IC_e_ERR_PART1_NOT_CALLED) \
    IC_ERRDEF(IC_e_ERR_PART2_NOT_CALLED) \
    IC_ERRDEF(IC_e_ERR_BIST_FAILED_RIGHT) \
    IC_ERRDEF(IC_e_ERR_DATABUSTEST_FAILED) \
    IC_ERRDEF(IC_e_ERR_DATABUSTEST_CYCLIC) \
    IC_ERRDEF(IC_e_ERR_EMBEDDED_REGS_LINE0_CORRUPTED) \
    IC_ERRDEF(IC_e_ERR_EMBEDDED_REGS_LINE1_CORRUPTED) \
    IC_ERRDEF(IC_e_ERR_EMBEDDED_STAT_CORRUPTED) \
    IC_ERRDEF(IC_e_ERR_EMBEDDED_HIST_CORRUPTED) \
    IC_ERRDEF(IC_e_ERR_HISTOGRAM_PIXELCOUNT_MISMATCH) \
    IC_ERRDEF(IC_e_ERR_BLACKLEVEL_RANGE) \
    IC_ERRDEF(IC_e_ERR_CHECK_FRAMENUM_INCR) \
    IC_ERRDEF(IC_e_ERR_CHECK_FRAMENUM_REGSTAT_MATCH) \
    IC_ERRDEF(IC_e_ERR_CHECK_FRAMEID) \
    IC_ERRDEF(IC_e_ERR_I2C_TIMING_LATE_RIGHT) \
   \
    IC_ERRDEF_LEFTIMG(IC_e_ERR_BIST_FAILED_LEFT) \
    IC_ERRDEF_LEFTIMG(IC_e_ERR_I2C_TIMING_LATE_LEFT) \
    IC_ERRDEF_LEFTIMG(IC_e_ERR_IMAGERS_SWAPPED) \
 \
    /* Analog test */ \
    IC_ERRDEF_ATEST(IC_e_ERR_ATEST_LINE) \
    IC_ERRDEF_ATEST(IC_e_ERR_ATEST_INIT) \
    IC_ERRDEF_ATEST(IC_e_ERR_ATEST_MEAN_TO_COLMEAN) \
    IC_ERRDEF_ATEST(IC_e_ERR_ATEST_MEAN_TO_REFMEAN) \
    IC_ERRDEF_ATEST(IC_e_ERR_ATEST_MEAN_REF_1X) \
    IC_ERRDEF_ATEST(IC_e_ERR_ATEST_MEAN_REF_2X) \
    IC_ERRDEF_ATEST(IC_e_ERR_ATEST_ATV1_1X) \
    IC_ERRDEF_ATEST(IC_e_ERR_ATEST_ATV1_2X) \
    IC_ERRDEF_ATEST(IC_e_ERR_ATEST_ATV3_1X) \
 \
    /* Algorithmic stuff */ \
    IC_ERRDEF(IC_e_ERR_EXTRACT_EMBEDDED_DATA) \
    IC_ERRDEF(IC_e_ERR_IC_INPUT) \
    IC_ERRDEF(IC_e_ERR_IC_RUN) \
    IC_ERRDEF(IC_e_ERR_IRCC_CALC) \
    IC_ERRDEF(IC_e_ERR_IRCC_GET) \
    IC_ERRDEF(IC_e_ERR_IRCC_SET_PPARS) \
    IC_ERRDEF(IC_e_ERR_IMGNC_INIT) \
    IC_ERRDEF(IC_e_ERR_IMGNC_LINECALLBACK) \
    IC_ERRDEF(IC_e_ERR_IMGNC_REGCALLBACK) \
    IC_ERRDEF(IC_e_ERR_IMGNC_GETRESULTS) \
 \
    /* External interface callbacks */ \
    IC_ERRDEF(IC_e_ERR_MEASFREEZE) \
    IC_ERRDEF(IC_e_ERR_DEMREPORT) \
    IC_ERRDEF(IC_e_ERR_REGISTER_ROI) \
    IC_ERRDEF(IC_e_ERR_DELETE_ROI) \
    IC_ERRDEF(IC_e_ERR_ROI_ALREADY_REGISTERED) \
    IC_ERRDEF(IC_e_ERR_REINIT_IMGCOMM) \
 \
    /* CROI / ROI */ \
    IC_ERRDEF(IC_e_ERR_ICROI_OUT_OF_RANGE) \
    IC_ERRDEF(IC_e_ERR_IC_ROI_SIZE_POSITION_MISMATCH) \
    IC_ERRDEF(IC_e_ERR_CROI_OUT_OF_RANGE) \
    IC_ERRDEF(IC_e_ERR_CROI_STARTY_MUSTBEEQUAL) \
    IC_ERRDEF(IC_e_ERR_CROI_WIDTH) \
    IC_ERRDEF(IC_e_ERR_CROI_HEIGHT) \
    IC_ERRDEF(IC_e_ERR_XSTART) \
    IC_ERRDEF(IC_e_ERR_YSTART) \
    IC_ERRDEF(IC_e_ERR_IMGDRV_SET_ICROI) \
    IC_ERRDEF(IC_e_ERR_ILLEGAL_DIMENSIONS) \
 \
    /* Imager synchronization */ \
    IC_ERRDEF_LEFTIMG(IC_e_ERR_IMGSYNC) \
    IC_ERRDEF_LEFTIMG(IC_e_ERR_IMGSYNC_OUTOFSYNC) \
    IC_ERRDEF_LEFTIMG(IC_e_ERR_IMGSYNC_RANGE_EXCEEDED) \
 \
    /* Timeout checks */ \
    IC_ERRDEF(IC_e_ERR_INPUTTIMEOUT_LDONLINECALIB) \
    IC_ERRDEF(IC_e_ERR_INPUTTIMEOUT_VDY) \
    IC_ERRDEF_LEFTIMG(IC_e_ERR_INPUTTIMEOUT_IMGSYNC_REQ) \
    IC_ERRDEF_LEFTIMG(IC_e_ERR_INPUTTIMEOUT_IMGSYNC_MEAS) \
    IC_ERRDEF_LEFTIMG(IC_e_ERR_INPUTTIMEOUT_LEFTREGRESPONSE) \
 \
    /* Other errors */ \
    IC_ERRDEF(IC_e_ERR_INVALID_CORRECTION_FACTOR) \
    IC_ERRDEF(IC_e_ERR_UNSUPPORTED_IMAGER) \
    IC_ERRDEF(IC_e_ERR_GET_REGISTER_DEFAULTS) \
    IC_ERRDEF(IC_e_ERR_REGISTERTABLE) \
    IC_ERRDEF(IC_e_ERR_SET_FRAMEHEIGHT) \
    IC_ERRDEF(IC_e_ERR_IMGDRV_GETBUFFERS) \
    IC_ERRDEF(IC_e_ERR_EXPOSURE_LINENUM) \
    IC_ERRDEF(IC_e_ERR_READ_TEMPERATURE) \
    IC_ERRDEF(IC_e_ERR_TEMPSENS_NOT_ENABLED) \
    IC_ERRDEF(IC_e_ERR_ICEXPMG_SETTODRIVER) \
    IC_ERRDEF(IC_e_ERR_GETEXPMEASFREEZE) \
    IC_ERRDEF(IC_e_ERR_ILLEGAL_REGISTER) \
    IC_ERRDEF(IC_e_ERR_ILLEGAL_SENSORNUM) \
    IC_ERRDEF(IC_e_ERR_LOCKED) \
 \
    /* End of list */ \
    IC_ERRDEF(IC_e_ERR__NUM_ENTRIES__)
/*#]*/

//  Collection of return codes used in the ImagerControl.
//  
//  !!! IMPORTANT NOTE !!!
//  When changing this enum, it's also required to change 'ICERR_S_ErrCodeNamesForMTS' !
//  This is checked and initialization of ImageControl will *FAIL* if this is inconsistent!
//  See definition of 'ICERR_S_ErrCodeNamesForMTS' below for details.
//  
//  PRQA S 0783 ERR_LIST
/*#[ type IC_E_ERROR */
#define IC_ERRDEF(x) x, // PRQA S 3410,3429,3453
typedef enum {
  IC_ERRCODES
} IC_E_ERROR; // PRQA S 0930
#undef IC_ERRDEF
// PRQA L:ERR_LIST
/*#]*/

//  This structure is used to provide meta-data to MTS via SDL/CDL file. It does not
//  contain any payload data, but tells MTS about the mapping of IC_E_ERROR to strings.
//  As this structure definition is stored in the SDL/CDL, the IC-MO and IC-Observer DLLs
//  can lookup the name for a specific error-code by looking into this structure definition.
//  The order must be the same as in 'IC_E_ERROR'. A bitfield of uint8 is used to save
//  memory, because this structure is part of the ErrorManager measfreeze data.
//  
//  All of this allows that the MTS DLLs will not have to be recompiled/updated if the list
//  of error-codes change.
//  
//  Regular expression for search+replace from top list:
//     Search:   IC_e(.*),
//     Replace:  uint8 IC_e\1 : 1;
//  
//  PRQA S 0781,0635 MTS_ERR_LIST
/*#[ type ICERR_S_ErrCodeNamesForMTS */
#define IC_ERRDEF(x) uint32 x : 1; // PRQA S 3410,3429,3412
typedef struct
{
  IC_ERRCODES
} ICERR_S_ErrCodeNamesForMTS;
#undef IC_ERRDEF
// PRQA L:MTS_ERR_LIST
/*#]*/

/*#[ type IC_E_DEM */
typedef enum {
    IC_e_DEM_PARAMETER,
    IC_e_DEM_IMAGER_BIST_R,
    IC_e_DEM_IMAGER_DATABUS_MCU_STARTUP,
    IC_e_DEM_IMAGER_ATEST_R,
    IC_e_DEM_REGTX_SYNC_VERIFY_FAILED_R,
    IC_e_DEM_FRAMECOUNTER,
    IC_e_DEM_FRAMECOUNTER_INCONSISTENT,
    IC_e_DEM_UNEXPECTED_EMBD_REG_STAT,
    IC_e_DEM_GENERAL,
    IC_e_DEM_PART1_NOTCALLED,
    IC_e_DEM_PART2_NOTCALLED,
    IC_e_DEM_IMAGER_COMM_R,
    IC_e_DEM_IMAGER_COMM,
    IC_e_DEM_IMAGER_COMM_TIMING,
    IC_e_DEM_EMBEDDED_REGS_CORRUPTED,
    IC_e_DEM_EMBEDDED_STAT_CORRUPTED,
    IC_e_DEM_REGCHECK_FAILED_R,
    IC_e_DEM_CALIBRATION,
    IC_e_DEM_INPUTS,
    IC_e_DEM_GENERAL_FATAL,
    IC_e_DEM_SOFTWARE_TIMING,
    IC_e_DEM_IMAGER_DATABUS_MCU_CYCLIC,
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    IC_e_DEM_IMAGER_COMM_L,
    IC_e_DEM_IMAGER_BIST_L,
    IC_e_DEM_REGTX_SYNC_VERIFY_FAILED_L,
    IC_e_DEM_REGCHECK_FAILED_L,
    IC_e_DEM_INPUTS_DSP2,
    IC_e_DEM_HARDWARE_TIMING,
#endif
    IC_e_DEM_COMMON_HW_DEF_ERR,
    IC_e_DEM__NUM_ENTRIES__ /* Must be last entry! */
} IC_E_DEM;
/*#]*/

/*#[ type IC_E_ERRSTATUS */
typedef enum {
    IC_e_ERRSTATUS_NOT_TESTED = 0,
    IC_e_ERRSTATUS_PASSED     = 1,
    IC_e_ERRSTATUS_FAILED     = 2
} IC_E_ERRSTATUS;
/*#]*/


/*#[ ignore */

#ifdef __cplusplus
}
#endif

/*#]*/


/*## package Ic_Pkg */

/*## class TopLevel::ic_errcodes */

#endif
/*********************************************************************
	File Path: ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_errcodes.h
*********************************************************************/
