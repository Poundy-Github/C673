/*! \file *********************************************************************

  COMPONENT:              SIMULATION

  MODULENAME:             vdy_sim_dbg.cpp

  @brief                  Supporting functions for debugging and simulation purpose

  VERSIONNUMBER:          $Revision: 1.1 $

*****************************************************************************/

#include "stdafx.h"
#include "sim_swc_dbg.h"

#include <float.h>
#include <fpieee.h>
#include <errno.h>


#pragma fenv_access (on)  // Disables optimizations that could change flag tests and mode changes

int fpieee_handler(_FPIEEE_RECORD *pieee);
eFPEErrors_t LocalErrors;
//! Transfer record for __except assessment (error log entry)
_FPIEEE_RECORD fpieee_record_g = { 0 };

BOOL SimDbgIsDebuggerAttached()
{
  DWORD dw;
  __asm {
    push eax                        // Preserve the registers
    push ecx
    mov eax, fs:[0x18]              // Get the TIB's linear address
    mov eax, dword ptr [eax + 0x30]
    mov ecx, dword ptr [eax]        // Get the whole DWORD
    mov dw, ecx                     // Save it
    pop ecx                         // Restore the registers
    pop eax
  }

  // The 3rd byte is the byte we really need to check for the
  // presence of a debugger. Check the 3rd byte
  return (BOOL)(dw & 0x00010000 ? TRUE : FALSE);
}

void SimDbgSetupFPU(unsigned int *cwOriginal)
{
  unsigned int cw;
  unsigned int stat;
  int err;

  // Set the x86 floating-point control word according to what exceptions you want to trap. 
  stat = _clearfp();      // Always call _clearfp before setting the control word
  
  // Because the second parameter in the following call is 0, it only returns the 
  // floating-point control word
  err = _controlfp_s(cwOriginal, 0, 0);

  // Set the exception masks off for exceptions that you want to trap.  When a mask bit is set, 
  // the corresponding floating-point exception is blocked from being generating.
  cw = *cwOriginal;

  // Reinitializes the floating-point math package. Clear possible invalid fpu states from 
  // previous components
  _fpreset();
  
  /* Initialize FPU without checking for pending unmasked floating-point exception.
     Sets the FPU control, status, tag, instruction pointer, and data pointer registers to
     their default states. The FPU control word is set to 037FH (round to nearest, all
     exceptions masked, 64-bit precision). The status word is cleared (no exception flags
     set, TOP is set to 0).  */
  // __asm fninit 
  
  cw   &= ~( /* EM_OVERFLOW | EM_UNDERFLOW | */ EM_ZERODIVIDE | EM_DENORMAL | EM_INVALID);
  cw   |=  ( ~_MCW_PC | _PC_24) & _MCW_PC;

  // For any bit in the second parameter (mask) that is 1, the corresponding bit in the first parameter 
  // is used to update the control word.
  err = _controlfp_s(&stat, cw,  _MCW_EM | _MCW_PC );

  LocalErrors = FPEErrors_Unknown;
  return;
}

void SimDbgRestoreFPU(unsigned int cwOriginal)
{
  unsigned int stat;
  int err;

  // Restore to default and recalculate
  err = _controlfp_s(&stat, cwOriginal ,_MCW_RC | _MCW_EM | _MCW_PC);

  return;
}
eFPEErrors_t SimGetFPUError(void)
{
  return LocalErrors;
}
int SimDbgEvaluateException(int exceptionCode, LPEXCEPTION_POINTERS pExcp)
{
  unsigned int stat;
  int ret;
  
  //May set a global variable that can be evaluated in or after _except guard code.
  stat =  _clearfp();    //Get floating-point status word. The above function also sets the
                         //busy bit to 0 to show that FPU is not busy.

  _fpieee_flt(exceptionCode,pExcp,fpieee_handler);
  if ((fpieee_record_g.Cause.ZeroDivide))
  {
    LocalErrors = FPEErrors_ZeroDivide;
    ret = EXCEPTION_EXECUTE_HANDLER;
  }
  else if ((fpieee_record_g.Cause.Inexact))
  {
    LocalErrors = FPEErrors_Inexact;
    ret = EXCEPTION_EXECUTE_HANDLER;
  }
  else if ((fpieee_record_g.Cause.InvalidOperation))
  {
    LocalErrors = FPEErrors_InvalidOperation;
    ret = EXCEPTION_EXECUTE_HANDLER;
  }
  else if ((fpieee_record_g.Cause.Overflow))
  {
    LocalErrors = FPEErrors_Overflow;
    ret = EXCEPTION_EXECUTE_HANDLER;
  }
  else if ((fpieee_record_g.Cause.Underflow))
  {
    LocalErrors = FPEErrors_Underflow;
    ret = EXCEPTION_CONTINUE_EXECUTION;
  }
  else {
    LocalErrors = FPEErrors_Unknown;
    ret = EXCEPTION_CONTINUE_EXECUTION;
  }

  return ret;
}

/* ****************************************************************************
  Functionname:    int fpieee_handler(_FPIEEE_RECORD *pieee)              */ /*!
  @brief           handles floating point exceptions, sets values to continue or
                   branches to __except for error logging

  @return          -

  @pre             stored original settings by SimDbgSetupFPU()
  @post            global variable fpieee_record_g has info about event (for error log)

  @author          Thomas Berndt
**************************************************************************** */
int fpieee_handler(_FPIEEE_RECORD *pieee)
{
  static const _FP80 FP80_HUGE = { 0x5000, 0x0467, 0xC9CD, 0xC9F2, 0x4062 };
  static const _FP80 FP80_0  = { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 };
  // user-defined ieee trap handler routine:
  // there is one handler for all IEEE exceptions

  fpieee_record_g = *pieee;

  if ((pieee->Cause.Underflow))
  {
    /* Handle only Underflow's ! All other are leading to __except case. */
    /* All "floating point" underflow operations return 0 */

    if (pieee->Result.Format == _FpFormatFp32)
    {
      pieee->Result.Value.Fp32Value = 0.0F;
    }
    else if (pieee->Result.Format == _FpFormatFp64)
    {
      pieee->Result.Value.Fp64Value = 0.0;
    }
    else if (pieee->Result.Format == _FpFormatFp80)
    {
      pieee->Result.Value.Fp80Value = FP80_0;
    }
    else
    {
      return EXCEPTION_EXECUTE_HANDLER;
    }
    return EXCEPTION_CONTINUE_EXECUTION;
  }
  else
  {
    return EXCEPTION_EXECUTE_HANDLER;
  }
}

// This next code enables the SIMD floating-point exceptions that you want to trap
void SimDbgSetupSIMD()
{
  unsigned long cntrReg;
  _asm {
    stmxcsr [cntrReg]          // Get MXCSR register
    and [cntrReg], 0FFFFFF7Fh  //bit 7 - invalid instruction mask
                               //bit 9 – divide-by-zero mask
                               //bit 10 - overflow mask
                               //bit 11 – underflow mask
    ldmxcsr [cntrReg]          // Load MXCSR register
  }
}

int SimDbgEvaluateExceptionSIMD()
{
  unsigned long cntrReg = 0;
  _asm {
    stmxcsr [cntrReg]           // Get MXCSR register
    and [cntrReg], 000000001h   // Get invalid operation
                                // flag bit 0.
                                // bit 2 – divide-by-zero flag
                                // bit 3 - overflow flag
                                // bit 4 – underflow flag
  }
  if (cntrReg > 0) {
    _asm {
      stmxcsr [cntrReg]           // Get MXCSR register
      and [cntrReg], 0FFFFFFFEh   // Clear sticky 
                                  // invalid operation flag
      ldmxcsr [cntrReg]           // Load MXCSR register
    }
    // globalVar = _SW_INVALID;
  }
  // force execution of the _except() guard code.
  return EXCEPTION_EXECUTE_HANDLER;
}
