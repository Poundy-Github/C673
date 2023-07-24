#
_XDCBUILDCOUNT = 3
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = C:/ti/AV_BIOS_SDK/av_bios_sdk_00_07_00_00/pdk/biospsp_03_10_06_00;C:/ti/AV_BIOS_SDK/av_bios_sdk_00_07_00_00/edma3_lld_02_11_06_01;C:/ti/AV_BIOS_SDK/av_bios_sdk_00_07_00_00/xdctools_3_23_04_60;C:/ti/AV_BIOS_SDK/av_bios_sdk_00_07_00_00/bios_6_33_06_50;C:/ti/AV_BIOS_SDK/av_bios_sdk_00_07_00_00/ipc_1_24_03_32
override XDCROOT = C:/ti/AV_BIOS_SDK/av_bios_sdk_00_07_00_00/xdctools_3_23_04_60
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = C:/ti/AV_BIOS_SDK/av_bios_sdk_00_07_00_00/pdk/biospsp_03_10_06_00;C:/ti/AV_BIOS_SDK/av_bios_sdk_00_07_00_00/edma3_lld_02_11_06_01;C:/ti/AV_BIOS_SDK/av_bios_sdk_00_07_00_00/xdctools_3_23_04_60;C:/ti/AV_BIOS_SDK/av_bios_sdk_00_07_00_00/bios_6_33_06_50;C:/ti/AV_BIOS_SDK/av_bios_sdk_00_07_00_00/ipc_1_24_03_32;C:/ti/AV_BIOS_SDK/av_bios_sdk_00_07_00_00/xdctools_3_23_04_60/packages;..
HOSTOS = Windows
endif
