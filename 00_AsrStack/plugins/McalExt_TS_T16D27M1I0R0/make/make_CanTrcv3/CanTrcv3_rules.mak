#
# \file
#
# \brief AUTOSAR McalExt
#
# This file contains the implementation of the AUTOSAR
# module McalExt.
#
# \version 1.0.0
#
# \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
#
# Copyright 2005 - 2020 Elektrobit Automotive GmbH
# All rights exclusively reserved for Elektrobit Automotive GmbH,
# unless expressly agreed to otherwise.


McalExt_src_FILES += $(McalExt_CORE_PATH)\MCAL_Delivery\McIsar\Src\Mcal\Tricore\CanTrcv_Tja1043\ssc\src\CanTrcv_8_Tja1043.c
McalExt_src_FILES += $(McalExt_OUTPUT_PATH)\src\CanTrcv_8_Tja1043_Cfg.c

ifeq ($(TS_BUILD_POST_BUILD_BINARY),TRUE)
# If the post build binary shall be built do 
# not compile any files other then the postbuild files.
McalExt_src_FILES :=
endif

