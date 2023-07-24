// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTE - RealTimeEnvironment
/// @file  Rte_Trace_Hooks.c
/// @brief This file contains all stuff required for the RTA-Instrumentation of the RTE. Especially it contains the FrameWorkHookfunctions
///        to measure the taskRuntime of the tasks handled by the RTE. It contains also the pre- and postHookFunctions of the runables
///        called in RTE.c.
///        Note: This file is generated by the RteStandardRtaInstrGenerator. Therefore it must not be altered in the sections between the
///              startTag and the related endTag eg. ___GENERATOR_TAG___XXX___SECTION_START___, ___GENERATOR_TAG___XXX___SECTION_END___
///              as these parts are overwritten at next generatorRun. But code can be added manually outside of these sections. This applies also
///              to the generated functions: Before the startTag and after the endTag code can be added manually but not in between these two tags.

#include <Std_Types.h>
#include <Rte_Trace_Hooks.h>
#include <Os.h>
#include <rta.h>
#include <Rte.h>

/* The following GENERATOR_TAG indicates the start of the implementation related to taskConfiguration type.
 * All the lines above the GENERATOR_TAG will not be changed by the codeGenerator at all.
 * DO NOT change or remove this comment block as it is needed by codeGenerator adding the rtaInstrumentation (GenerateRteStandardRtaInstrumentation)!!!
 * ___GENERATOR_TAG___TASK_CFG_TYPE___SECTION_START___ */


/* ___GENERATOR_TAG___TASK_CFG_TYPE___SECTION_END___
 * The GENERATOR_TAG above indicates the end of the implementation related to taskConfiguration type.
 * All the lines below the GENERATOR_TAG will not be changed by the codeGenerator at all.
 * DO NOT change or remove this comment block as it is needed by codeGenerator adding the rtaInstrumentation (GenerateRteStandardRtaInstrumentation)!!!
 */





/* The following GENERATOR_TAG indicates the start of the implementation related to taskLut.
 * All the lines above the GENERATOR_TAG will not be changed by the codeGenerator at all.
 * DO NOT change or remove this comment block as it is needed by codeGenerator adding the rtaInstrumentation (GenerateRteStandardRtaInstrumentation)!!!
 * ___GENERATOR_TAG___TASK_LUT___SECTION_START___ */


/* ___GENERATOR_TAG___TASK_LUT___SECTION_END___
 * The GENERATOR_TAG above indicates the end of the implementation the implementation related to taskLut.
 * All the lines below the GENERATOR_TAG will not be changed by the codeGenerator at all.
 * DO NOT change or remove this comment block as it is needed by codeGenerator adding the rtaInstrumentation (GenerateRteStandardRtaInstrumentation)!!!
 */





/* The following GENERATOR_TAG indicates the start of the taskCycleCounter implementation.
 * All the lines above the GENERATOR_TAG will not be changed by the codeGenerator at all.
 * DO NOT change or remove this comment block as it is needed by codeGenerator adding the rtaInstrumentation (GenerateRteStandardRtaInstrumentation)!!!
 * ___GENERATOR_TAG___TASK_CYCLE_COUNTER___SECTION_START___ */


/* ___GENERATOR_TAG___TASK_CYCLE_COUNTER___SECTION_END___
 * The GENERATOR_TAG above indicates the end of the taskCycleCounter implementation.
 * All the lines below the GENERATOR_TAG will not be changed by the codeGenerator at all.
 * DO NOT change or remove this comment block as it is needed by codeGenerator adding the rtaInstrumentation (GenerateRteStandardRtaInstrumentation)!!!
 */





/* The following GENERATOR_TAG indicates the start of the frameWorkHooks implementation.
 * All the lines above the GENERATOR_TAG will not be changed by the codeGenerator at all.
 * DO NOT change or remove this comment block as it is needed by codeGenerator adding the rtaInstrumentation (GenerateRteStandardRtaInstrumentation)!!!
 * ___GENERATOR_TAG___FRAMEWORK_HOOKS___SECTION_START___ */


/* ___GENERATOR_TAG___FRAMEWORK_HOOKS___SECTION_END___
 * The GENERATOR_TAG above indicates the end of the frameWorkHooks implementation.
 * All the lines below the GENERATOR_TAG will not be changed by the codeGenerator at all.
 * DO NOT change or remove this comment block as it is needed by codeGenerator adding the rtaInstrumentation (GenerateRteStandardRtaInstrumentation)!!!
 */





/* The following GENERATOR_TAG indicates the start of the implementation of all the traceHoocFunctions.
 * All the lines above the GENERATOR_TAG will not be changed by the codeGenerator at all.
 * DO NOT change or remove this comment block as it is needed by codeGenerator adding the rtaInstrumentation (GenerateRteStandardRtaInstrumentation)!!!
 * ___GENERATOR_TAG___TRACE_HOOK_FUNCTIONS___SECTION_START___ */


/* ___GENERATOR_TAG___TRACE_HOOK_FUNCTIONS___SECTION_END___
 * The GENERATOR_TAG above indicates the end of the implementation of all the traceHoocFunctions.
 * All the lines below the GENERATOR_TAG will not be changed by the codeGenerator at all.
 * DO NOT change or remove this comment block as it is needed by codeGenerator adding the rtaInstrumentation (GenerateRteStandardRtaInstrumentation)!!!
 */
