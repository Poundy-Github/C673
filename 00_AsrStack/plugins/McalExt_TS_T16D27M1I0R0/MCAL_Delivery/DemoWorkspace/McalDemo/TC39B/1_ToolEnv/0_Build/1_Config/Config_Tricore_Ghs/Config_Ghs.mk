###############################################################################
#                                                                             #
#       Copyright (C) 2020 Infineon Technologies AG. All rights reserved.     #
#                                                                             #
#                                                                             #
#                              IMPORTANT NOTICE                               #
#                                                                             #
#                                                                             #
# Infineon Technologies AG (Infineon) is supplying this file for use          #
# exclusively with Infineon’s microcontroller products. This file can be      #
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

B_GHS_TRICORE_PATH?= $(GREEN_HILLS_HOME)\comp_201815

B_GHS_TRICORE_CC_OPTIONS= -gnu99 -g -cpu=tc1v162 --xref=full -tricore_ppccompat_abi -sda=none -roxda -minlib -Ogeneral -Onoprintfuncs -Onounroll -Onotailrecursion -Onoexplodejumps --unsigned_chars -ffunctions -fsingle -no_fused_madd -Oinline_constant_math -no_float_associativity -fno_NaN_cmp_unordered -no_precise_signed_zero -half_precision_type --no_commons --no_vla --gnu_asm -dual_debug --no_short_enum --diag_error 39,549,940,1056,1780,1999 --diag_warning 193,1705,1706,1709,1710,1718,1729,1735,1777,1826,1835,2017 -srec -lnk=-no_append -nostartfiles -map -Mn -Mx -nostdlib

B_GHS_TRICORE_LD_OPTIONS= $(B_GHS_TRICORE_CC_OPTIONS)

B_GHS_TRICORE_ASM_OPTIONS= $(B_GHS_TRICORE_CC_OPTIONS)

#Include path for library directories. Add each path with following format as shown below.
#Each path prefixed with -L and separated by a space.
#B_GHS_TRICORE_LIB_INC=-L<path>[ -L<path>][..]
B_GHS_TRICORE_LIB_INC= -L"$(B_GHS_TRICORE_PATH)/lib/tri162_compat"

#Libraries to include shall be listed with option -l, with following format.
#B_GHS_TRICORE_LIBS=-l<lib name>[ -l<lib name>][..]
B_GHS_TRICORE_LIBS= -lansi -lstartup -lind_sf -larch -lsys -lmath_sf -lwc_s32
