#EB_Automotive_Makefile

#################################################################
# DEFINITIONS
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/inc/Smu_*.h)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/src/Smu_*.c)
CC_INCLUDE_PATH    += $(McalExt_CORE_PATH)/MCAL_Delivery/McIsar/Src/Mcal/Tricore/Smu/ssc/inc
