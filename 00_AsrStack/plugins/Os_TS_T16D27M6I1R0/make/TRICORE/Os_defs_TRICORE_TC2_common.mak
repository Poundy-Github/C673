#################################################################
#
# $Id: Os_defs_TRICORE_TC2_common.mak 34521 2021-07-15 08:08:43Z dypa272654 $
#
# This makefile contains derivative-specific definitions for building the OS.
#
# Copyright Elektrobit Automotive GmbH
# All rights exclusively reserved for Elektrobit Automotive GmbH,
# unless expressly agreed to otherwise.
#
#################################################################

OS_TCARCH_VARIANT=-tc161

OS_KLIB_OBJS_DERIVATE =	$(addprefix $(AutosarOS_LIB_SRC_PATH)\TRICORE\,								\
							$(OS_TRICORE_PREFIX)writeendinit$(OS_TCARCH_VARIANT).$(CC_FILE_SUFFIX)	\
						 )
