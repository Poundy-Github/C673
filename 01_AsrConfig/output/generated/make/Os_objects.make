# This file is generated automatically. DO NOT EDIT!!
# 
# EB tresos AutoCore OS 6.1.31 TRICORE/TC38XQ
# (Build 20210823)
# 
# (c) 1998-2023 Elektrobit Automotive GmbH
# Am Wolfsmantel 46
# 91058 Erlangen
# GERMANY
# 
# Date         : 4/25/23 9:47 AM           !!!IGNORE-LINE!!!

ifndef OS_OBJECTS_MAKE_INCLUDED
OS_OBJECTS_MAKE_INCLUDED := 1

OS_GENERATED_APPL_FILES +=$(AutosarOS_OUTPUT_PATH)\src\OsApplication_C0_gen.c
OS_CORE_OsApplication_C0 = 0
OS_GENERATED_APPL_FILES +=$(AutosarOS_OUTPUT_PATH)\src\OsApplication_C1_gen.c
OS_CORE_OsApplication_C1 = 1
OS_GENERATED_APPL_FILES +=$(AutosarOS_OUTPUT_PATH)\src\OsApplication_C2_gen.c
OS_CORE_OsApplication_C2 = 2
OS_GENERATED_APPL_FILES +=$(AutosarOS_OUTPUT_PATH)\src\OsApplication_C3_gen.c
OS_CORE_OsApplication_C3 = 3
OS_GENERATED_APPL_FILES +=$(AutosarOS_OUTPUT_PATH)\src\OS_SYSTEM_0_gen.c
OS_CORE_OS_SYSTEM_0 = 0
OS_GENERATED_APPL_FILES +=$(AutosarOS_OUTPUT_PATH)\src\OS_SYSTEM_1_gen.c
OS_CORE_OS_SYSTEM_1 = 1
OS_GENERATED_APPL_FILES +=$(AutosarOS_OUTPUT_PATH)\src\OS_SYSTEM_2_gen.c
OS_CORE_OS_SYSTEM_2 = 2
OS_GENERATED_APPL_FILES +=$(AutosarOS_OUTPUT_PATH)\src\OS_SYSTEM_3_gen.c
OS_CORE_OS_SYSTEM_3 = 3
# OS_OPTIMIZED_LIB_ID tells the build process the name of the optimized library
OS_OPTIMIZED_LIB_ID = 4003ad4028

#####################################################################
# Advanced Logical Core Interface
#####################################################################

# OS_ALCI tells the build process whether to enable ALCI feature.
OS_ALCI = FALSE
#####################################################################
# Applications
#####################################################################

# The APPLICATIONS macro tells the build process the names
# of all the application objects
APPLICATIONS = OsApplication_C0 OsApplication_C1 OsApplication_C2 OsApplication_C3 OS_SYSTEM_0 OS_SYSTEM_1 OS_SYSTEM_2 OS_SYSTEM_3
# For each application XXX in the APPLICATIONS macro:
# - the macro TASKS_XXX tells the build process the names of all the tasks
#   that belong to the application XXX
# - the macro ISRS_XXX tells the build process the names of all the ISRs
#   that belong to the application XXX
TASKS_OsApplication_C0 = Core0_DefaultTask Core0_InitTask_Appl Core0_OsTask_Bsw_10ms Core0_OsTask_Appl_5ms Core0_OsTask_Bsw_20ms Core0_OsTask_OperationInovkedProxy Core0_OsTask_Appl_10ms Core0_OsTask_Appl_20ms Core0_OsTask_Appl_60ms Core0_OsTask_FunctionSafety_5ms Core0_OsTask_Bsw_5ms
ISRS_OsApplication_C0 = CAN0SR8_ISR CAN0SR9_ISR CAN0SR10_ISR CAN0SR12_ISR CAN0SR13_ISR CAN0SR14_ISR CAN1SR0_ISR CAN1SR1_ISR CAN1SR2_ISR CAN1SR3_ISR CAN1SR4_ISR CAN1SR5_ISR CAN1SR6_ISR DMACH15SR_ISR DMACH16SR_ISR GTMTIM1SR5_ISR GTMTIM2SR5_ISR QSPI3ERR_ISR QSPI3PT_ISR HSCT0_ISR HSSL0COK0_ISR HSSL0COK2_ISR DMACH0SR_ISR DMACH1SR_ISR GTMTOM2SR3_ISR GTMTIM3SR4_ISR DMAERR0SR_ISR
TASKS_OsApplication_C1 = Core1_DefaultTask Core1_InitTask_Appl Core1_OsTask_Bsw_20ms Core1_OsTask_Appl_10ms Core1_OsTask_Appl_20ms Core1_OsTask_Appl_60ms Core1_OsTask_OperationInovkedProxy
ISRS_OsApplication_C1 = 
TASKS_OsApplication_C2 = Core2_DefaultTask Core2_InitTask_Appl Core2_OsTask_Bsw_20ms Core2_OsTask_OperationInovkedProxy Core2_OsTask_Appl_5ms
ISRS_OsApplication_C2 = 
TASKS_OsApplication_C3 = Core3_DefaultTask Core3_InitTask_Appl Core3_OsTask_Bsw_20ms Core3_OsTask_Appl_10ms Core3_OsTask_Appl_50ms Core3_OsTask_Appl_60ms Core3_OsTask_OperationInovkedProxy
ISRS_OsApplication_C3 = 
TASKS_OS_SYSTEM_0 = 
ISRS_OS_SYSTEM_0 = 
TASKS_OS_SYSTEM_1 = 
ISRS_OS_SYSTEM_1 = 
TASKS_OS_SYSTEM_2 = 
ISRS_OS_SYSTEM_2 = 
TASKS_OS_SYSTEM_3 = 
ISRS_OS_SYSTEM_3 = 

#####################################################################
# Configured Modes
#####################################################################

# OS_CONFIG_EXTENDED_STATUS tells the build process which error library to use.
OS_CONFIG_EXTENDED_STATUS = TRUE
# The OS TRACER is configured as follows:
OS_TRACE = FALSE

#####################################################################
# Core Mapping
#####################################################################

# OS_INITCORE tells the build process which core the OS uses (singlecore).
OS_INITCORE = 0
#####################################################################
# Interrupts
#####################################################################

# This variable tells the build process the number of stack slots that are generated
# for the stack type kernStack
OS_NUM_KERNSTACK_SLOTS = 1,1,1,1
#####################################################################
# Kernel Type
#####################################################################

# Defines which trapping mechanism the OS shall use.
OS_KERNEL_TYPE = SYSTEM_CALL
#####################################################################
# Multicore
#####################################################################

# Defines the number of CPU cores assigned to EB tresos AutoCore OS.
OS_N_CORES := 4
# Defines the maximum number of CPU cores supported.
OS_N_CORES_MAX := 4

#####################################################################
# Optimization
#####################################################################

# Defines if library shall be optimized according to configuration
OS_BUILD_OPTIMIZED_LIB_FROM_SOURCE = FALSE
#####################################################################
# TRICORE CSAs
#####################################################################

OS_TRICORE_NCSA_LIST = 256,256,256,256
#####################################################################
# Tasks
#####################################################################

# This variable tells the build process the number of stack slots that are generated
# for the stack type taskStack
OS_NUM_TASKSTACK_SLOTS = 11,7,5,7
#####################################################################
# Threads
#####################################################################

# This variable tells the build process the number of stack slots that are generated
# for the stack type threadStack
MK_NUM_THREADSTACK_SLOTS = 11,7,5,7
endif

