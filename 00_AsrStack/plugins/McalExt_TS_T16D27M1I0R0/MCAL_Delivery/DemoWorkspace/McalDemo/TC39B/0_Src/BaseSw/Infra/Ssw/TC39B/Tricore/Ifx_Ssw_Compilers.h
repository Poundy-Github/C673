/**
 * \file Ifx_Ssw_Compilers.h
 * \brief Startup Software for compiler options
 *
 * \copyright Copyright (c) 2017 Infineon Technologies AG. All rights reserved.
 *
 * $Date: 2017-05-12 08:52:44
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 */

#ifndef IFX_SSW_COMPILERS_H_
#define IFX_SSW_COMPILERS_H_

/*Macro definition to show GNUC macros with the editor*/
#if ((!defined(__ghs__)) && (!defined(__DCC__)) && (!defined(__TASKING__)) && (!defined(__HIGHTEC__)))
#define __HIGHTEC__
#endif

/*Include files for each compiler*/
#ifdef __DCC__
#include "Ifx_Ssw_CompilersDcc.h"

#elif defined(__HIGHTEC__)
#include "Ifx_Ssw_CompilersGnuc.h"

#elif defined(__TASKING__)
#include "Ifx_Ssw_CompilersTasking.h"

#elif defined(__ghs__)
#include "Ifx_Ssw_CompilersGhs.h"
#endif

#endif /* IFX_SSW_COMPILERS_H_ */
