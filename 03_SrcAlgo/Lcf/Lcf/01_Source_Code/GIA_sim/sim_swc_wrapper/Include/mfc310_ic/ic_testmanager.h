//* **********************************************************************
//  COMPANY:         $CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
//  
//  PROJECT:         MFC30x_MCU
//  CPU:             MPC5675K
//  
//  PACKAGE:         $Source: ic_testmanager.h $ $Revision: 1.1 $
//  MKS Date:        $Date: 2021/12/13 17:26:04CET $
//  
//  RHAPSODY:        7.5.3
//  COMPONENT:       IC
//  CONFIGURATION:   DefaultConfig
//  MODEL ELEMENT:   ic_testmanager
//  MODULNAME:       ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_testmanager.h
//  LOGIN:           uidt3974  
//  
//  The Imager Control Test Manager implements all 'remaining' FuSi checks, which are not
//  covered by separate modules. This includes:
//    * Imager BIST (Build-in self test)
//    * Imager Startup Databus Test (Databus Imager<->MCU)
//    * Imager Cyclic Databus Test (partly via noise/bitcombination analysis)
//  
//  Tests are controlled by the calling module (ic_controller) and implmeneted according to
//  the specification 'MFC3xx_Imager_Tests_at_Start_up_sequence_and_cyclic.docx'. See there
//  for details about thease tests.
//  
//  ==========================================================================================
//  =                  CYCLIC DATABUS TEST (noise analysis + frame counter)                  =
//  ==========================================================================================
//  The databus of the imager has to be cyclically checked, which is executed by using a
//  combination of embedded register data, embedded statistics data and image noise. All three
//  cases are needed to cover all 12 bits of the databus, so the test is split into three parts:
//  
//  1) The upper 8 bits [11:4] are checked using embedded register data. All imager registers
//     are split into two bytes, which are transported using embedded register data. All
//     important registers are cyclically checked in the register manager, so any biterror will
//     be seen there. To be sure to cover all possible damages of the bus (short circuit GND,
//     VDD, open circuit, short to neightbor line, ...), one dedicated register is used to
//     transport a special testpattern which will be changed each cycle. This is done in function
//     ICTM_e_ChangeDatabusTestpattern().
//  
//  2) The bits [3:2] are checked by using the frame counter in the statistics data, which spans
//     over pixels [9:2]. Therefore the two lower bits of the counter are visible in bits [3:2]
//     and expected to change every frame. After 4 frames, all bitcombos must have been seen in
//     the data stream. This is implemented in ICTM_v_DatabusCheckNoiseMainFunc().
//  
//  3) The lower two bits [1:0] are checked by analyzing the imager's pixeldata stream and looking
//     for all possible values (0,1,2,3) somewhere in the middle of the image. As the image is
//     always a bit grainy/noisy, even a very dark image will produce every combination within
//     a line in case the imager is not faulty. See functions ICTM_v_DatabusCheckNoise*Func() for
//     details.
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
//  Possible dereference of NULL pointer
//    PRQA S 0506 EOF
//  
//  AUTHOR:          $Author: Wang, David (Wangd3) $
//! CREATION DATE:   Mon, 12, Nov 2012  10:54 W. Europe Standard Time AM 
//**************************************************************************** */

#ifndef ic_testmanager_H
#define ic_testmanager_H

/*## dependency ic_types */
#include "ic_types.h"
/*## package Ic_Pkg */

/*## class TopLevel::ic_testmanager */
/*#[ ignore */
//  The Imager Control Test Manager implements all 'remaining' FuSi checks, which are not
//  covered by separate modules. This includes:
//    * Imager BIST (Build-in self test)
//    * Imager Startup Databus Test (Databus Imager<->MCU)
//    * Imager Cyclic Databus Test (partly via noise/bitcombination analysis)
//  
//  Tests are controlled by the calling module (ic_controller) and implmeneted according to
//  the specification 'MFC3xx_Imager_Tests_at_Start_up_sequence_and_cyclic.docx'. See there
//  for details about thease tests.
//  
//  ==========================================================================================
//  =                  CYCLIC DATABUS TEST (noise analysis + frame counter)                  =
//  ==========================================================================================
//  The databus of the imager has to be cyclically checked, which is executed by using a
//  combination of embedded register data, embedded statistics data and image noise. All three
//  cases are needed to cover all 12 bits of the databus, so the test is split into three parts:
//  
//  1) The upper 8 bits [11:4] are checked using embedded register data. All imager registers
//     are split into two bytes, which are transported using embedded register data. All
//     important registers are cyclically checked in the register manager, so any biterror will
//     be seen there. To be sure to cover all possible damages of the bus (short circuit GND,
//     VDD, open circuit, short to neightbor line, ...), one dedicated register is used to
//     transport a special testpattern which will be changed each cycle. This is done in function
//     ICTM_e_ChangeDatabusTestpattern().
//  
//  2) The bits [3:2] are checked by using the frame counter in the statistics data, which spans
//     over pixels [9:2]. Therefore the two lower bits of the counter are visible in bits [3:2]
//     and expected to change every frame. After 4 frames, all bitcombos must have been seen in
//     the data stream. This is implemented in ICTM_v_DatabusCheckNoiseMainFunc().
//  
//  3) The lower two bits [1:0] are checked by analyzing the imager's pixeldata stream and looking
//     for all possible values (0,1,2,3) somewhere in the middle of the image. As the image is
//     always a bit grainy/noisy, even a very dark image will produce every combination within
//     a line in case the imager is not faulty. See functions ICTM_v_DatabusCheckNoise*Func() for
//     details.
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
//  Possible dereference of NULL pointer
//    PRQA S 0506 EOF
/*#]*/


/*#[ ignore */

#ifdef __cplusplus
extern "C"
{
#endif

/*#]*/


/*#[ type ICTM_E_DBUS_RESULT */
typedef enum
{
    ICTM_e_DBUS_RESULT_NOT_FINISHED,
    ICTM_e_DBUS_RESULT_FINISHED_OK,
    ICTM_e_DBUS_RESULT_FINISHED_FAILED,
    ICTM_e_DBUS_RESULT_ERROR
}  ICTM_E_DBUS_RESULT;
/*#]*/

/*#[ type ICTM_E_DBTestState */
typedef enum
{
    ICTM_e_DBTESTSTATE_INIT,
    ICTM_e_DBTESTSTATE_DELAY_1_FRAME,
    ICTM_e_DBTESTSTATE_RUNNING,
    ICTM_e_DBTESTSTATE_CLEANUP,
    ICTM_e_DBTESTSTATE_DONE
}  ICTM_E_DBTestState;
/*#]*/

/*## type ICTM_S_MeasDBusCyc */
typedef struct ICTM_S_MeasDBusCyc {
    uint16 ui16_DataBusNumFrames;		/*## attribute ui16_DataBusNumFrames */
    uint16 ui16_DataBusNumFramesMax;		/*## attribute ui16_DataBusNumFramesMax */
    uint16 ui16_DataBusBitCombosSeen;		/*## attribute ui16_DataBusBitCombosSeen */
    uint32 ui32_DataBusNumPixLast;		/*## attribute ui32_DataBusNumPixLast */
    uint32 ui32_DataBusNumPixMax;		/*## attribute ui32_DataBusNumPixMax */
} ICTM_S_MeasDBusCyc;

/*## type ICTM_S_CyclicDBusTest */
typedef struct ICTM_S_CyclicDBusTest {
    //  Stores number of pixels currently used to detect all bit-combos on the lower bus lanes.
    uint32 ui32_NumPixelsUsed;		/*## attribute ui32_NumPixelsUsed */
    //  Stores number of frames currently used for cyclic databus test
    uint16 ui16_NumFramesUsed;		/*## attribute ui16_NumFramesUsed */
    //  Bit-combinations that have been seen on the lower two imager databus lanes.
    //  Bit on position 'n' set to '1' means that we have seen value DBUS[1:0]=n on the bus.
    uint16 ui16_CombosSeen_Bits01;		/*## attribute ui16_CombosSeen_Bits01 */
    //  Bit-combinations that have been seen on the lower four imager databus lanes.
    //  Bit on position 'n' set to '1' means that we have seen value DBUS[3:0]=n on the bus.
    uint16 ui16_CombosSeen_Bits0123;		/*## attribute ui16_CombosSeen_Bits0123 */
} ICTM_S_CyclicDBusTest;

/*## type ICTM_S_MeasData */
typedef struct ICTM_S_MeasData {
    ICTM_S_MeasDBusCyc s_DBusCyclic;		/*## attribute s_DBusCyclic */
    ICTM_E_DBTestState e_DatabusTestState;		/*## attribute e_DatabusTestState */
    ICTM_E_DBUS_RESULT e_DatabusTestResult;		/*## attribute e_DatabusTestResult */
    boolean b_DatabusTestFailed;		/*## attribute b_DatabusTestFailed */
} ICTM_S_MeasData;

/***    User explicit entries    ***/


/* Operations */

//*****************************************************************************
//  Functionname:  ICTM_e_ExecBIST
//  
//  Description:
//    Executes Imager Build-in Self Test according to the specification in the document:
//      * MFC3xx_Imager_Tests_at_Start_up_sequence_and_cyclic.docx (rev. 1.5)
//  
//    See activity chart for implementation details.
//  
//    NOTE: This function blocks for a significant amount of time (~120-150ms), which has to
//          be considered when choosing the calling context for executing this function.
//  
//  Preconditions:
//    * This Module must be initialized
//    * Imagers must be ready for communication (i.e. powered-on, not hold in reset, I2C ready)
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICTM_e_ExecBIST() */
IC_E_ERROR ICTM_e_ExecBIST(void);

//*****************************************************************************
//  Functionname:  ICTM_v_DatabusCheckLineFunc
//  
//  Description:
//    This function checks the correctness of the databus testpattern contained in the imager's
//    pixeldata stream. It must be called for each line of the databus test ROI during databus-test
//    execution.
//  
//    The databus-testpattern is assumed to be a 'walking-ones' pattern. As the MT9M025 has a bug
//    in it's pattern generation unit, there is a special treatment of the first pixel, which is
//    0x002 instead of 0x000.
//  
//  Outputs:  
//    * ICTM_e_DBTestResult    - Result of databus test
//    * ICTM_e_DBTestState     - State of databus test
//  
//  Preconditions:
//    * This Module must be initialized
//  
//  Parameter:     const uint16 ui16_LineNum   <In>
//  
//  
//  Parameter:     const uint16 * pui16_PixelData   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICTM_v_DatabusCheckLineFunc(const uint16,const uint16 *) */
void ICTM_v_DatabusCheckLineFunc(const uint16 ui16_LineNum, const uint16 * pui16_PixelData);

//*****************************************************************************
//  Functionname:  ICTM_v_DatabusCheckNoiseLineFunc
//  
//  Description:
//    This function is the cyclic databus test execution function, which must be called for
//    the databus test ROI defined in the variable ICCFG_cui16_DATABUSTEST_CYCLIC_LINEY. It
//    processes the pixeldata within that line and checks the bits [1:0] for all possible
//    bitcombinations. When all combinations are found, the function stops analyzing remaining
//    pixels.
//  
//    See module description for a general description how the cyclic databus test works.
//  
//  Outputs:  
//    * ICTM_s_CycDBus.ui16_CombosSeen_Bits01   - Seen bitcombinations (one bit for each combination)
//  
//  Preconditions:
//    * Call ICTM_v_DatabusCheckNoiseMainFunc(), which evaluates the results / triggers error on fail
//  
//  Parameter:     const uint16 ui16_LineNum   <In>
//  
//  
//  Parameter:     const uint16 * pui16_PixelData   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICTM_v_DatabusCheckNoiseLineFunc(const uint16,const uint16 *) */
void ICTM_v_DatabusCheckNoiseLineFunc(const uint16 ui16_LineNum, const uint16 * pui16_PixelData);

//*****************************************************************************
//  Functionname:  ICTM_e_ChangeDatabusTestpattern
//  
//  Description:
//    Switches cyclic databus testpattern to the next value in the cyclic sequence. This actually
//    writes the next value to a dedicated imager register, which is later automatically checked
//    in the register checks (ic_regmanager).
//  
//  Preconditions:
//    * This Module must be initialized
//    * Imagers must be ready for communication (i.e. powered-on, not hold in reset, I2C ready)
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICTM_e_ChangeDatabusTestpattern() */
IC_E_ERROR ICTM_e_ChangeDatabusTestpattern(void);

//*****************************************************************************
//  Functionname:  ICTM_e_DatabusCheckMainFunc
//  
//  Description:
//    This is the databus test state machine for the db-test executed during startup.
//    See state chart for details.
//  
//  Preconditions:
//    * This Module must be initialized
//    * Imagers must be ready for communication (i.e. powered-on, not hold in reset, I2C ready)
//  
//    
//  
//  return         ICTM_E_DBUS_RESULT
//**************************************************************************** */
/*## operation ICTM_e_DatabusCheckMainFunc() */
ICTM_E_DBUS_RESULT ICTM_e_DatabusCheckMainFunc(void);

//*****************************************************************************
//  Functionname:  ICTM_v_DatabusCheckNoiseMainFunc
//  
//  Description:
//    This is the main (post-) execution function of the cyclic databus test (see module description).
//    It evaluates the results produced by the line function 'ICTM_v_DatabusCheckNoiseLineFunc' (which
//    checkes databus bits [1:0]) and adds checking of the frame counter (covers databus bits [3:2]).
//    In total it generates a bitfield for all bitcombos of bits [3:0].
//  
//    If all possible bitcombinations have appeared during the last 'ICCFG_cui32_DATABUSTEST_CYCLIC_MAXFRAMES'
//    frames, the test is considered to be passed.
//  
//  Preconditions:
//    * ICTM_v_DatabusCheckNoiseLineFunc() has been executed during current frame
//  
//  Parameter:     const uint16 ui16_FrameCntStat   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICTM_v_DatabusCheckNoiseMainFunc(const uint16) */
void ICTM_v_DatabusCheckNoiseMainFunc(const uint16 ui16_FrameCntStat);

//*****************************************************************************
//  Functionname:  ICTM_v_Init
//  
//  Description:
//    Initializes the IC Testmanager. No tests are executed.
//  
//  Preconditions:
//    none
//  
//  Parameter:     ICTM_S_MeasData * const ps_MeasData   <In>
//  
//  
//  Parameter:     const IC_S_Croi * const ps_CroiMasterFrame   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICTM_v_Init(ICTM_S_MeasData * const,const IC_S_Croi * const) */
void ICTM_v_Init(ICTM_S_MeasData * const ps_MeasData, const IC_S_Croi * const ps_CroiMasterFrame);


/*#[ ignore */

#ifdef __cplusplus
}
#endif

/*#]*/


#endif
/*********************************************************************
	File Path: ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_testmanager.h
*********************************************************************/
