###############################################################################
#                                                                             #
#       Copyright (c) 2019 Infineon Technologies AG. All rights reserved.     #
#                                                                             #
#                                                                             #
#                              IMPORTANT NOTICE                               #
#                                                                             #
#                                                                             #
# Infineon Technologies AG (Infineon) is supplying this file for use          #
# exclusively with Infineon's microcontroller products. This file can be      #
# freely distributed within development tools that are supporting such        #
# microcontroller products.                                                   #
#                                                                             #
# THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED #
# OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF          #
# MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.#
# INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,#
# OR CONSEQUENTIAL DAMAGES, FOR	ANY REASON WHATSOEVER.                        #
#                                                                             #
###############################################################################

B_TASKING_TRICORE_PATH?= $(TASKING6_3R1P2_HOME)\ctc

B_TASKING_TRICORE_CC_OPTIONS= --core=tc1.6.2 --iso=99 -O2 --eabi=BCFHNSW -AGKpvX --tradeoff=2 --fp-model=1 \
			                --switch=auto --integer-enumeration --default-near-size=0 --global-type-checking 

B_TASKING_TRICORE_LD_OPTIONS= -OcLtXY --core=mpe:vtc --global-type-checking

B_TASKING_TRICORE_ASM_OPTIONS= --core=tc1.6.2 --list-format=1 --optimize=gs

#Include path for library directories. Add each path with following format as shown below.
#Each path prefixed with -L and separated by a space.
#B_TASKING_TRICORE_LIB_INC=-L<path>[ -L<path>][..]
B_TASKING_TRICORE_LIB_INC=

#Libraries to include shall be listed with option -l, with following format.
#B_GNUC_TRICORE_LIBS=-l<lib name>[ -l<lib name>][..]
B_TASKING_TRICORE_LIBS= -lrt -lcs_fpu -lfp_fpu


